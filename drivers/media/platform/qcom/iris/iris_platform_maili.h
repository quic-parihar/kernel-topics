/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#ifndef __IRIS_PLATFORM_MAILI_H__
#define __IRIS_PLATFORM_MAILI_H__

static const char *const maili_pmdomain_table[] = {
	"venus",
	"vcodec0",
	"vpp0",
};

static const struct platform_clk_data maili_clk_table[] = {
	{ IRIS_AXI_CLK,          "iface"                },
	{ IRIS_AXI1_CLK,         "iface1"               },
	{ IRIS_CTRL_CLK,         "core"                 },
	{ IRIS_CTRL_FREERUN_CLK, "core_freerun"         },
	{ IRIS_HW_CLK,           "vcodec0_core"         },
	{ IRIS_HW_FREERUN_CLK,   "vcodec0_core_freerun" },
	{ IRIS_BSE_HW_CLK,       "vcodec_bse"           },
	{ IRIS_VPP0_HW_CLK,      "vcodec_vpp0"          },
};

static const char *const maili_opp_clk_table[] = {
	"vcodec0_core",
	"vcodec_bse",
	"core",
	NULL,
};

static const char *const vpu4x_clk_reset_table[] = {
	"bus0",
	"bus1",
	"core",
	"vcodec0_core",
};

#endif
