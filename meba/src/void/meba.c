// Copyright (c) 2026 Free Mobile, Vincent Jardin
// SPDX-License-Identifier: MIT

// MEBA "void" board: no switch, no fixed PHY population: for only MEPA PHYs
// managed by the application (PHY-only setups: evaluation boards, PTP
// daemons, debug tooling, SPI-attached 10G/25G PHYs such as the LAN80xx).
//
// The board exposes "port_cnt" MEPA port slots (conf tag, default 4). It
// deliberately does NOT probe or pre-create PHY devices at
// MEBA_PHY_INITIALIZE: the application creates each device explicitly (ex:
// mesa-demo "PHY Dev Create"), which is also the only path running the
// PRE/DEFAULT/POST reset sequence. PHY register access is forwarded to the
// application-provided board_info accessors: MIIM/MMD through the standard
// meba_generic callouts, SPI through meba_phy_spi_read/write below.

#include <stdlib.h>
#include <string.h>

#include "microchip/ethernet/board/api.h"
#include "meba_aux.h"
#include "meba_generic.h"

#define VOID_PORTS_MAX 16

typedef struct meba_board_state {
    uint32_t          port_cnt;
    meba_port_entry_t entry[VOID_PORTS_MAX];
    mepa_device_t    *phy_devices[VOID_PORTS_MAX];
} meba_board_state_t;

#define INST2BOARD(inst) ((meba_board_state_t *)(inst)->private_data)

static uint32_t void_capability(meba_inst_t inst, int cap)
{
    meba_board_state_t *board = INST2BOARD(inst);

    switch (cap) {
    case MEBA_CAP_BOARD_PORT_COUNT:
    case MEBA_CAP_BOARD_PORT_MAP_COUNT: return board->port_cnt;
    default:                            return 0;
    }
}

static mesa_rc void_port_entry_get(meba_inst_t inst, mesa_port_no_t port_no, meba_port_entry_t *entry)
{
    meba_board_state_t *board = INST2BOARD(inst);

    if (port_no >= board->port_cnt) {
        return MESA_RC_ERROR;
    }
    *entry = board->entry[port_no];
    return MESA_RC_OK;
}

static mesa_rc void_reset(meba_inst_t inst, meba_reset_point_t reset)
{
    meba_board_state_t *board = INST2BOARD(inst);

    switch (reset) {
    case MEBA_PHY_INITIALIZE:
        // Expose the (empty) device table and wire the MEPA callouts, but do
        // NOT probe: with no fixed population there is nothing to detect, and
        // pre-created devices would skip the application's create/reset path.
        inst->phy_devices = (mepa_device_t **)&board->phy_devices;
        inst->phy_device_cnt = board->port_cnt;
        meba_phy_callout_init(inst);
        break;
    default: break;
    }
    return MESA_RC_OK;
}

/* PHY SPI register access: let's forward to the application-provided board_info
 * accessors (iface.spi_read/spi_write). The application decides the transport
 * (/dev/spidev, an SPI proxy daemon, ...) and keeps the slot demux; the cs
 * argument is unused on this board.
 */
static mesa_rc void_phy_spi_read(meba_inst_t     inst,
                                 mesa_port_no_t  port_no,
                                 uint8_t         dev,
                                 uint16_t        reg_num,
                                 uint32_t *const data)
{
    if (inst->iface.spi_read == NULL) {
        return MESA_RC_NOT_IMPLEMENTED;
    }
    return inst->iface.spi_read(port_no, dev, 0, reg_num, data);
}

static mesa_rc void_phy_spi_write(meba_inst_t     inst,
                                  mesa_port_no_t  port_no,
                                  uint8_t         dev,
                                  uint16_t        reg_num,
                                  uint32_t *const data)
{
    if (inst->iface.spi_write == NULL) {
        return MESA_RC_NOT_IMPLEMENTED;
    }
    return inst->iface.spi_write(port_no, dev, 0, reg_num, data);
}

meba_inst_t meba_initialize(size_t callouts_size, const meba_board_interface_t *callouts)
{
    meba_inst_t         inst;
    meba_board_state_t *board;
    uint32_t            port_cnt = 4;
    mesa_port_no_t      port_no;

    if (callouts_size < sizeof(*callouts)) {
        fprintf(stderr, "Callouts size problem, expected %zd, got %zd\n", sizeof(*callouts),
                callouts_size);
        return NULL;
    }

    if ((inst = meba_state_alloc(callouts, "void", 0, sizeof(*board))) == NULL) {
        return NULL;
    }

    MEBA_ASSERT(inst->private_data != NULL);
    board = INST2BOARD(inst);

    // Number of MEPA port slots, application-defined
    (void)meba_conf_get_u32(inst, "port_cnt", &port_cnt);
    if (port_cnt < 1 || port_cnt > VOID_PORTS_MAX) {
        port_cnt = 4;
    }
    board->port_cnt = port_cnt;

    for (port_no = 0; port_no < port_cnt; port_no++) {
        meba_port_entry_t *entry = &board->entry[port_no];
        entry->map.chip_port = port_no;
        entry->map.miim_controller = MESA_MIIM_CONTROLLER_NONE;
        entry->mac_if = MESA_PORT_INTERFACE_NO_CONNECTION;
        entry->cap = MEBA_PORT_CAP_NONE;
        // Single-package assumption: port 0 anchors multi-channel PHY
        // packages (mepa_link_base_port); refine via conf tags if a
        // multi-package setup ever needs it.
        entry->phy_base_port = 0;
    }

    T_I(inst, "Board: %s, %d MEPA port slots (no switch)", inst->props.name, board->port_cnt);

    inst->api.meba_capability = void_capability;
    inst->api.meba_port_entry_get = void_port_entry_get;
    inst->api.meba_reset = void_reset;
    inst->api.meba_deinitialize = meba_deinitialize;
    inst->api.meba_phy_spi_read = void_phy_spi_read;
    inst->api.meba_phy_spi_write = void_phy_spi_write;

    return inst;
}
