/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#ifndef __MEDIA_IRIS_PLATFORM_HAWI_H__
#define __MEDIA_IRIS_PLATFORM_HAWI_H__

static const char * const hawi_clk_reset_table[] = {
	"bus0",
	"core",
};

static const struct platform_clk_data hawi_clk_table[] = {
	{IRIS_AXI_CLK, "iface" },
	{IRIS_AXIC_CLK, "ifacec" },
	{IRIS_CTRL_CLK, "core" },
	{IRIS_HW_FREERUN_CLK, "core_freerun" },
	{IRIS_CTRL_FREERUN_CLK, "core_ctl_freerun" },
	{IRIS_CTRL_DEBUG_CLK, "core_debug" },
	{IRIS_CX_AXI_CLK, "cx_iface" },
	{IRIS_HW_CLK, "vcodec0_core" },
	{IRIS_VPP0_HW_CLK, "vcodec_vpp0" },
	{IRIS_VPP1_HW_CLK, "vcodec_vpp1" },
	{IRIS_VPP_GATING_CLK, "vcodec_vpp0_vpp1_gating" },
	{IRIS_APV_HW_CLK, "vcodec_apv" },
	{IRIS_BSE_HW_CLK, "vcodec_bse" },
};

static const char *const hawi_opp_clk_table[] = {
	"vcodec0_core",
	"vcodec_apv",
	"vcodec_bse",
	"core",
	NULL,
};

static const char * const hawi_pmdomain_table[] = {
	"venus",
	"vcodec0",
	"vpp0",
	"vpp1",
	"apv",
	"mm-int",
	"cx-int",
};

#endif
