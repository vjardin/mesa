// Copyright (c) 2026 Free Mobile, Vincent Jardin
// SPDX-License-Identifier: MIT

// MESA switch API stubs for the PHY-only demo build (MESA_PHY_ONLY):
// no switch chip library is linked, but a few shared demo sources still
// reference these symbols on paths that never execute in PHY-only mode.
// Every stub fails the MESA way (MESA_RC_ERROR / zero) so an unexpected
// call surfaces as a normal API error, not a crash.

#include <stdarg.h>

#include "microchip/ethernet/switch/api.h"

uint32_t mesa_capability(mesa_inst_t inst, mesa_cap_t cap)
{
    return 0;
}

uint32_t mesa_port_cnt(const mesa_inst_t inst)
{
    return 0;
}

mesa_rc mesa_port_map_get(const mesa_inst_t inst, uint32_t cnt, mesa_port_map_t *port_map)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_map_set(const mesa_inst_t inst, uint32_t cnt, const mesa_port_map_t *port_map)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_init_conf_get(const mesa_inst_t inst, mesa_init_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_init_conf_set(const mesa_inst_t inst, const mesa_init_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_inst_get(const mesa_target_type_t target, mesa_inst_create_t *const create)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_inst_create(const mesa_inst_create_t *const create, mesa_inst_t *const inst)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_inst_destroy(const mesa_inst_t inst)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_poll_1sec(const mesa_inst_t inst)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_chip_id_get(const mesa_inst_t inst, mesa_chip_id_t *const chip_id)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_sgpio_conf_get(const mesa_inst_t      inst,
                            const mesa_chip_no_t   chip_no,
                            const mesa_sgpio_group_t group,
                            mesa_sgpio_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_sgpio_conf_set(const mesa_inst_t      inst,
                            const mesa_chip_no_t   chip_no,
                            const mesa_sgpio_group_t group,
                            const mesa_sgpio_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_temp_sensor_get(const mesa_inst_t inst, int16_t *temperature)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_debug_info_get(mesa_debug_info_t *const info)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_debug_info_print(const mesa_inst_t              inst,
                              const mesa_debug_printf_t      prntf,
                              const mesa_debug_info_t *const info)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_mmd_read(const mesa_inst_t    inst,
                           const mesa_port_no_t port_no,
                           const uint8_t        mmd,
                           const uint16_t       addr,
                           uint16_t *const      value)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_mmd_write(const mesa_inst_t    inst,
                            const mesa_port_no_t port_no,
                            const uint8_t        mmd,
                            const uint16_t       addr,
                            const uint16_t       value)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_serdes_debug_set(const mesa_inst_t                        inst,
                                   const mesa_port_no_t                     port_no,
                                   const mesa_port_serdes_debug_t *const    conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_trace_conf_get(const mesa_trace_group_t group, mesa_trace_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_trace_conf_set(const mesa_trace_group_t group, const mesa_trace_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_spi_slave_init(const mesa_spi_slave_init_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_miim_read(const mesa_inst_t            inst,
                       const mesa_chip_no_t         chip_no,
                       const mesa_miim_controller_t miim_controller,
                       const uint8_t                miim_addr,
                       const uint8_t                addr,
                       uint16_t *const              value)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_miim_write(const mesa_inst_t            inst,
                        const mesa_chip_no_t         chip_no,
                        const mesa_miim_controller_t miim_controller,
                        const uint8_t                miim_addr,
                        const uint8_t                addr,
                        const uint16_t               value)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_mmd_read(const mesa_inst_t            inst,
                      const mesa_chip_no_t         chip_no,
                      const mesa_miim_controller_t miim_controller,
                      const uint8_t                miim_addr,
                      const uint8_t                mmd,
                      const uint16_t               addr,
                      uint16_t *const              value)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_mmd_write(const mesa_inst_t            inst,
                       const mesa_chip_no_t         chip_no,
                       const mesa_miim_controller_t miim_controller,
                       const uint8_t                miim_addr,
                       const uint8_t                mmd,
                       const uint16_t               addr,
                       const uint16_t               value)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_mmd_read_inc(const mesa_inst_t    inst,
                               const mesa_port_no_t port_no,
                               const uint8_t        mmd,
                               const uint16_t       addr,
                               uint16_t *const      buf,
                               uint8_t              count)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_conf_get(const mesa_inst_t       inst,
                           const mesa_port_no_t    port_no,
                           mesa_port_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_conf_set(const mesa_inst_t             inst,
                           const mesa_port_no_t          port_no,
                           const mesa_port_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_status_get(const mesa_inst_t         inst,
                             const mesa_port_no_t      port_no,
                             mesa_port_status_t *const status)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_clause_37_control_get(const mesa_inst_t                    inst,
                                        const mesa_port_no_t                 port_no,
                                        mesa_port_clause_37_control_t *const control)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_clause_37_control_set(const mesa_inst_t                          inst,
                                        const mesa_port_no_t                       port_no,
                                        const mesa_port_clause_37_control_t *const control)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_port_test_conf_set(const mesa_inst_t                  inst,
                                const mesa_port_no_t               port_no,
                                const mesa_port_test_conf_t *const conf)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_packet_rx_frame(const mesa_inst_t            inst,
                             uint8_t *const               data,
                             const uint32_t               buflen,
                             mesa_packet_rx_info_t *const rx_info)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_packet_tx_frame(const mesa_inst_t                  inst,
                             const mesa_packet_tx_info_t *const tx_info,
                             const uint8_t *const               frame,
                             const uint32_t                     length)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_packet_tx_info_init(const mesa_inst_t inst, mesa_packet_tx_info_t *const info)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_ptp_event_enable(const mesa_inst_t           inst,
                              const mesa_ptp_event_type_t ev_mask,
                              const mesa_bool_t           enable)
{
    return MESA_RC_ERROR;
}

mesa_rc mesa_ptp_event_poll(const mesa_inst_t inst, mesa_ptp_event_type_t *const ev_mask)
{
    return MESA_RC_ERROR;
}

/* Demo-module globals/functions normally provided by the switch modules
 * (port.c, ip.c, symreg.c, udmabuf.c), which are not part of the PHY-only
 * build. Same behavior as a PHY-only run of the full binary: never set,
 * never reached. */
#include "microchip/ethernet/board/api.h"
#include "main.h"
#include "symreg.h"

meba_inst_t    meba_global_inst;
mesa_port_no_t ip_port = MESA_PORT_NO_NONE;

void symreg_cli_regs_print(symreg_func_t func, char *pattern, uint32_t value)
{
}

mesa_rc udmabuf_init(void)
{
    return MESA_RC_ERROR;
}

void *udmabuf_malloc(size_t size)
{
    return NULL;
}

void udmabuf_free(void *ptr)
{
}

uintptr_t udmabuf_cpu_to_dma_addr(void *ptr)
{
    return 0;
}
