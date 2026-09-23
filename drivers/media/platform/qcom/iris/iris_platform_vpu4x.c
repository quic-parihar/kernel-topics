// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#include "iris_core.h"
#include "iris_ctrls.h"
#include "iris_hfi_gen2.h"
#include "iris_hfi_gen2_defines.h"
#include "iris_platform_common.h"
#include "iris_vpu_buffer.h"
#include "iris_vpu_common.h"

#include "iris_platform_sm8550.h"
#include "iris_platform_maili.h"

static const struct iris_firmware_desc iris_vpu40_p1_s8_gen2_desc = {
	.firmware_data = &iris_hfi_gen2_data,
	.get_vpu_buffer_size = iris_vpu4x_buf_size,
	.fwname = "qcom/vpu/vpu40_p1_s8.mbn",
};

static const u32 iris_fmts_vpu4x_dec[] = {
	[IRIS_FMT_H264] = V4L2_PIX_FMT_H264,
	[IRIS_FMT_HEVC] = V4L2_PIX_FMT_HEVC,
	[IRIS_FMT_VP9] = V4L2_PIX_FMT_VP9,
	[IRIS_FMT_AV1] = V4L2_PIX_FMT_AV1,
};

static const struct icc_info iris_icc_info_vpu4x[] = {
	{ "cpu-cfg",    1000, 1000     },
	{ "video-mem",  1000, 15000000 },
};

static const struct bw_info iris_bw_table_dec_vpu4x[] = {
	{ ((4096 * 2160) / 256) * 60, 1608000 },
	{ ((4096 * 2160) / 256) * 30,  826000 },
	{ ((1920 * 1080) / 256) * 60,  567000 },
	{ ((1920 * 1080) / 256) * 30,  294000 },
};

static const char * const iris_opp_pd_table_vpu4x[] = { "mxc", "mmcx" };

static const struct tz_cp_config tz_cp_config_vpu4x[] = {
	{
		.cp_start = VIDEO_REGION_VM0_SECURE_NP_ID,
		.cp_size = 0,
		.cp_nonpixel_start = 0x01000000,
		.cp_nonpixel_size = 0x24800000,
	},
	{
		.cp_start = VIDEO_REGION_VM0_NONSECURE_NP_ID,
		.cp_size = 0,
		.cp_nonpixel_start = 0x25800000,
		.cp_nonpixel_size = 0xda400000,
	},
};

const struct iris_platform_data maili_data = {
	.firmware_desc_gen2 = &iris_vpu40_p1_s8_gen2_desc,
	.vpu_ops = &iris_vpu4x_ops,
	.icc_tbl = iris_icc_info_vpu4x,
	.icc_tbl_size = ARRAY_SIZE(iris_icc_info_vpu4x),
	.clk_rst_tbl = vpu4x_clk_reset_table,
	.clk_rst_tbl_size = ARRAY_SIZE(vpu4x_clk_reset_table),
	.bw_tbl_dec = iris_bw_table_dec_vpu4x,
	.bw_tbl_dec_size = ARRAY_SIZE(iris_bw_table_dec_vpu4x),
	.pmdomain_tbl = maili_pmdomain_table,
	.pmdomain_tbl_size = ARRAY_SIZE(maili_pmdomain_table),
	.opp_pd_tbl = iris_opp_pd_table_vpu4x,
	.opp_pd_tbl_size = ARRAY_SIZE(iris_opp_pd_table_vpu4x),
	.clk_tbl = maili_clk_table,
	.clk_tbl_size = ARRAY_SIZE(maili_clk_table),
	.opp_clk_tbl = maili_opp_clk_table,
	/* Upper bound of DMA address range */
	.dma_mask = 0xffc00000 - 1,
	.inst_iris_fmts = iris_fmts_vpu4x_dec,
	.inst_iris_fmts_size = ARRAY_SIZE(iris_fmts_vpu4x_dec),
	.inst_caps = &platform_inst_cap_sm8550,
	.tz_cp_config_data = tz_cp_config_vpu4x,
	.tz_cp_config_data_size = ARRAY_SIZE(tz_cp_config_vpu4x),
	.num_vpp_pipe = 1,
	.max_session_count = 16,
	.max_core_mbpf = NUM_MBS_8K,
	.max_core_mbps = NUM_MBS_8K * 30,
};
