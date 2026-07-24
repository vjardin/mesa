// Copyright (c) 2026 Free Mobile
// SPDX-License-Identifier: MIT

#ifndef PHY_DEVICE_GET_H_
#define PHY_DEVICE_GET_H_

#include "microchip/ethernet/board/api.h"

// Bounds-checked accessor for a MEBA instance's phy_devices[] array.
//
// The CLI parser accepts uport=0 as a valid input (its comment says
// "Port 0 == PORT_NONE") and cli_parm_port_no then calls uport2iport(0)
// which returns MESA_PORT_NO_NONE (0xFFFFFFFF). Callers that blindly
// index inst->phy_devices[req->port_no] therefore dereference through
// an out-of-bounds offset and crash mesa-demo-void with SIGSEGV.
//
// Every mepa_apps/*.c cli_cmd_* handler should route its phy_devices
// access through this helper: NULL means either port_no is out of
// range or the port has no PHY attached; treat both as user error.
static inline mepa_device_t *
phy_device_get(meba_inst_t inst, mesa_port_no_t port_no)
{
	if (inst == NULL) {
		return NULL;
	}
	if (port_no >= (mesa_port_no_t)inst->phy_device_cnt) {
		return NULL;
	}
	return inst->phy_devices[port_no];
}

/* Convenience guard for cli_cmd_* handlers.  Rejects invalid port_no or
 * missing PHY device with a user-facing message and returns from the
 * enclosing function.  Use at the top of every cli_cmd_* body that later
 * indexes <inst>->phy_devices[req->port_no]. */
#define PHY_DEVICE_GUARD(inst)                                        \
	do {                                                              \
		if (phy_device_get((inst), req->port_no) == NULL) {           \
			cli_printf(" Dev is Not Created for the port : %d\n",     \
			           req->port_no + 1);                             \
			return;                                                   \
		}                                                             \
	} while (0)

#endif /* PHY_DEVICE_GET_H_ */
