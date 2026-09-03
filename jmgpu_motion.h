/*
 * JMGPU driver
 *
 * Copyright (c) 2020 ChangSha JingJiaMicro Electronics Co., Ltd.
 * All rights reserved.
 *
 * Author:
 *      wj <jjwgpu@jingjiamicro.com>
 *
 * The software and information contained herein is proprietary and
 * confidential to JingJiaMicro Electronics. This software can only be
 * used by JingJiaMicro Electronics Corporation. Any use, reproduction,
 * or disclosure without the written permission of JingJiaMicro
 * Electronics Corporation is strictly prohibited.
 *
 */





#ifndef __jmgpu_hal_profiler_shared_h_
#define __jmgpu_hal_profiler_shared_h_

#ifdef __cplusplus
extern "C" {
#endif

#define J9_HANDLE_J9MA_REAPPROVAL   1
#define J9_MUSKS                    1
#define J9_COXING                   0
#define J9_HANDLE_J_UNICYCLIST      0


typedef struct tag_jms_PROFILER_COUNTERS_PART1 {
    jmtUINT32       gpuTotalRead64BytesPerFrame;
    jmtUINT32       gpuTotalWrite64BytesPerFrame;


    jmtUINT32       fe_draw_count;
    jmtUINT32       fe_out_vertex_count;
    jmtUINT32       fe_cache_miss_count;
    jmtUINT32       fe_cache_lk_count;
    jmtUINT32       fe_stall_count;
    jmtUINT32       fe_starve_count;
    jmtUINT32       fe_process_count;


    jmtUINT32       pe0_pixel_count_killed_by_color_pipe;
    jmtUINT32       pe0_pixel_count_killed_by_depth_pipe;
    jmtUINT32       pe0_pixel_count_drawn_by_color_pipe;
    jmtUINT32       pe0_pixel_count_drawn_by_depth_pipe;
    jmtUINT32       pe1_pixel_count_killed_by_color_pipe;
    jmtUINT32       pe1_pixel_count_killed_by_depth_pipe;
    jmtUINT32       pe1_pixel_count_drawn_by_color_pipe;
    jmtUINT32       pe1_pixel_count_drawn_by_depth_pipe;


    jmtUINT32       shader_cycle_count;
    jmtUINT32       vs_shader_cycle_count;
    jmtUINT32       ps_shader_cycle_count;
    jmtUINT32       ps_inst_counter;
    jmtUINT32       ps_rendered_pixel_counter;
    jmtUINT32       vs_inst_counter;
    jmtUINT32       vs_rendered_vertice_counter;
    jmtUINT32       vs_branch_inst_counter;
    jmtUINT32       vs_texld_inst_counter;
    jmtUINT32       ps_branch_inst_counter;
    jmtUINT32       ps_texld_inst_counter;
    jmtUINT32       vs_non_idle_starve_count;
    jmtUINT32       vs_starve_count;
    jmtUINT32       vs_stall_count;
    jmtUINT32       vs_process_count;
    jmtUINT32       ps_non_idle_starve_count;
    jmtUINT32       ps_starve_count;
    jmtUINT32       ps_stall_count;
    jmtUINT32       ps_process_count;


    jmtUINT32       pa_input_vtx_counter;
    jmtUINT32       pa_input_prim_counter;
    jmtUINT32       pa_output_prim_counter;
    jmtUINT32       pa_depth_clipped_counter;
    jmtUINT32       pa_trivial_rejected_counter;
    jmtUINT32       pa_culled_prim_counter;
    jmtUINT32       pa_droped_prim_counter;
    jmtUINT32       pa_frustum_clipped_prim_counter;
    jmtUINT32       pa_frustum_clipdroped_prim_counter;
    jmtUINT32       pa_non_idle_starve_count;
    jmtUINT32       pa_starve_count;
    jmtUINT32       pa_stall_count;
    jmtUINT32       pa_process_count;


    jmtUINT32       se_culled_triangle_count;
    jmtUINT32       se_culled_lines_count;
    jmtUINT32       se_clipped_triangle_count;
    jmtUINT32       se_clipped_line_count;
    jmtUINT32       se_starve_count;
    jmtUINT32       se_stall_count;
    jmtUINT32       se_receive_triangle_count;
    jmtUINT32       se_send_triangle_count;
    jmtUINT32       se_receive_lines_count;
    jmtUINT32       se_send_lines_count;
    jmtUINT32       se_process_count;
    jmtUINT32       se_trivial_rejected_line_count;
    jmtUINT32       se_non_idle_starve_count;


    jmtUINT32       ra_input_prim_count;
    jmtUINT32       ra_total_quad_count;
    jmtUINT32       ra_valid_quad_count_after_early_z;
    jmtUINT32       ra_valid_pixel_count_to_render;
    jmtUINT32       ra_output_valid_quad_count;
    jmtUINT32       ra_output_valid_pixel_count;
    jmtUINT32       ra_pipe_cache_miss_counter;
    jmtUINT32       ra_pipe_hz_cache_miss_counter;
    jmtUINT32       ra_prefetch_cache_miss_counter;
    jmtUINT32       ra_prefetch_hz_cache_miss_counter;
    jmtUINT32       ra_eez_culled_counter;
    jmtUINT32       ra_non_idle_starve_count;
    jmtUINT32       ra_starve_count;
    jmtUINT32       ra_stall_count;
    jmtUINT32       ra_process_count;


    jmtUINT32       tx_total_bilinear_requests;
    jmtUINT32       tx_total_trilinear_requests;
    jmtUINT32       tx_total_discarded_texture_requests;
    jmtUINT32       tx_total_texture_requests;
    jmtUINT32       tx_mc0_miss_count;
    jmtUINT32       tx_mc0_request_byte_count;
    jmtUINT32       tx_mc1_miss_count;
    jmtUINT32       tx_mc1_request_byte_count;
    jmtUINT32       tx_non_idle_starve_count;
    jmtUINT32       tx_starve_count;
    jmtUINT32       tx_stall_count;
    jmtUINT32       tx_process_count;
} j9_handle_j9menu_promissive;

typedef struct tag_jms_PROFILER_COUNTERS_PART2 {

    jmtUINT32       mcc_total_read_req_8B_from_colorpipe;
    jmtUINT32       mcc_total_read_req_8B_sentout_from_colorpipe;
    jmtUINT32       mcc_total_write_req_8B_from_colorpipe;
    jmtUINT32       mcc_total_read_req_sentout_from_colorpipe;
    jmtUINT32       mcc_total_write_req_from_colorpipe;
    jmtUINT32       mcc_total_read_req_8B_from_depthpipe;
    jmtUINT32       mcc_total_read_req_8B_sentout_from_depthpipe;
    jmtUINT32       mcc_total_write_req_8B_from_depthpipe;
    jmtUINT32       mcc_total_read_req_sentout_from_depthpipe;
    jmtUINT32       mcc_total_write_req_from_depthpipe;
    jmtUINT32       mcc_total_read_req_8B_from_others;
    jmtUINT32       mcc_total_write_req_8B_from_others;
    jmtUINT32       mcc_total_read_req_from_others;
    jmtUINT32       mcc_total_write_req_from_others;
    jmtUINT32       mcc_axi_total_latency;
    jmtUINT32       mcc_axi_sample_count;
    jmtUINT32       mcc_axi_max_latency;
    jmtUINT32       mcc_axi_min_latency;
    jmtUINT32       mc_fe_read_bandwidth;
    jmtUINT32       mc_mmu_read_bandwidth;
    jmtUINT32       mc_blt_read_bandwidth;
    jmtUINT32       mc_sh0_read_bandwidth;
    jmtUINT32       mc_sh1_read_bandwidth;
    jmtUINT32       mc_pe_write_bandwidth;
    jmtUINT32       mc_blt_write_bandwidth;
    jmtUINT32       mc_sh0_write_bandwidth;
    jmtUINT32       mc_sh1_write_bandwidth;


    jmtUINT32       mcz_total_read_req_8B_from_colorpipe;
    jmtUINT32       mcz_total_read_req_8B_sentout_from_colorpipe;
    jmtUINT32       mcz_total_write_req_8B_from_colorpipe;
    jmtUINT32       mcz_total_read_req_sentout_from_colorpipe;
    jmtUINT32       mcz_total_write_req_from_colorpipe;
    jmtUINT32       mcz_total_read_req_8B_from_depthpipe;
    jmtUINT32       mcz_total_read_req_8B_sentout_from_depthpipe;
    jmtUINT32       mcz_total_write_req_8B_from_depthpipe;
    jmtUINT32       mcz_total_read_req_sentout_from_depthpipe;
    jmtUINT32       mcz_total_write_req_from_depthpipe;
    jmtUINT32       mcz_total_read_req_8B_from_others;
    jmtUINT32       mcz_total_write_req_8B_from_others;
    jmtUINT32       mcz_total_read_req_from_others;
    jmtUINT32       mcz_total_write_req_from_others;
    jmtUINT32       mcz_axi_total_latency;
    jmtUINT32       mcz_axi_sample_count;
    jmtUINT32       mcz_axi_max_latency;
    jmtUINT32       mcz_axi_min_latency;


    jmtUINT32       hi0_total_read_8B_count;
    jmtUINT32       hi0_total_write_8B_count;
    jmtUINT32       hi0_total_read_request_count;
    jmtUINT32       hi0_total_write_request_count;
    jmtUINT32       hi0_axi_cycles_read_request_stalled;
    jmtUINT32       hi0_axi_cycles_write_request_stalled;
    jmtUINT32       hi0_axi_cycles_write_data_stalled;
    jmtUINT32       hi1_total_read_8B_count;
    jmtUINT32       hi1_total_write_8B_count;
    jmtUINT32       hi1_total_read_request_count;
    jmtUINT32       hi1_total_write_request_count;
    jmtUINT32       hi1_axi_cycles_read_request_stalled;
    jmtUINT32       hi1_axi_cycles_write_request_stalled;
    jmtUINT32       hi1_axi_cycles_write_data_stalled;
    jmtUINT32       hi_total_cycle_count;
    jmtUINT32       hi_total_idle_cycle_count;
    jmtUINT32       hi_total_read_8B_count;
    jmtUINT32       hi_total_write_8B_count;
    jmtUINT32       hi_total_readOCB_16B_count;
    jmtUINT32       hi_total_writeOCB_16B_count;


    jmtUINT32       l2_total_axi0_read_request_count;
    jmtUINT32       l2_total_axi1_read_request_count;
    jmtUINT32       l2_total_axi0_write_request_count;
    jmtUINT32       l2_total_axi1_write_request_count;
    jmtUINT32       l2_total_read_transactions_request_by_axi0;
    jmtUINT32       l2_total_read_transactions_request_by_axi1;
    jmtUINT32       l2_total_write_transactions_request_by_axi0;
    jmtUINT32       l2_total_write_transactions_request_by_axi1;
    jmtUINT32       l2_axi0_minmax_latency;
    jmtUINT32       l2_axi0_min_latency;
    jmtUINT32       l2_axi0_max_latency;
    jmtUINT32       l2_axi0_total_latency;
    jmtUINT32       l2_axi0_total_request_count;
    jmtUINT32       l2_axi1_minmax_latency;
    jmtUINT32       l2_axi1_min_latency;
    jmtUINT32       l2_axi1_max_latency;
    jmtUINT32       l2_axi1_total_latency;
    jmtUINT32       l2_axi1_total_request_count;
} j9_handle_j9menu_jointuress;

typedef struct tag_jms_PROFILER_COUNTERS {
    j9_handle_j9menu_promissive counters_part1;
    j9_handle_j9menu_jointuress counters_part2;
} j9_handle__spancelled;

typedef enum tag_jme_VIP_PROBE_COUNTER {
    J9_HANDLE_J_ATTRIBUTE_BANDCUTTER,
    J9_HANDLE_J9MATHS_ATTRIBUTE_CELIBATIST,
    J9_HANDLE_J9MENU_RECLIMBING
} j9_handle__denegation;


typedef enum tag_jme_TPCOUNTER_OVERFLOW {
    J9_HANDLE__ATTRIBUTE_TANGERINES                  = (1 << 0),
    J9_HANDLE_J9MIRROR_ATTRIBUTE_QUINOPYRIN          = (1 << 1),
    J9_HANDLE_ATTRIBUTE_BEHAVIOUR_CROSSBENCH         = (1 << 2),
    J9_HANDLE__ATTRIBUTE_BEHAVIOUR_PHLEBOLOGY        = (1 << 3),
    J9_HANDLE__ATTRIBUTE_BEHAVIOUR_PALEOSTYLY        = (1 << 4),
    J9_HANDLE_J_ATTRIBUTE_BEHAVIOUR_THEOGONIST       = (1 << 5),
    J9_HANDLE_ATTRIBUTE_BEHAVIOUR_BALLBUSTER         = (1 << 6),
    J9_HANDLE__ATTRIBUTE_BEHAVIOUR_CALCIFUGAL        = (1 << 7),
    J9_HANDLE_J9_ATTRIBUTE_ILLUCIDATE                = (1 << 8),
    J9_HANDLE_J9MA_ATTRIBUTE_ILLUCIDATE              = (1 << 9),
    J9_HANDLE_J9M_ATTRIBUTE_PEDIMENTED               = (1 << 10),
    J9_HANDLE_J9MIRROR_ATTRIBUTE_QUINTUPLET          = (1 << 11),
    J9_HANDLE_J9MA_ATTRIBUTE_BEHAVIOUR_TIMBERLIKE    = (1 << 0),
    J9_HANDLE_J9MA_ATTRIBUTE_BEHAVIOUR_PICHICIAGO    = (1 << 1),
    J9_HANDLE_J9MA_ATTRIBUTE_BEHAVIOUR_PALEOSTYLY    = (1 << 2),
    J9_HANDLE_J9MA_ATTRIBUTE_BEHAVIOUR_PHLEBOLOGY    = (1 << 3),
} tag_jme_TPCOUNTER_OVERFLOW;


typedef enum tag_jme_NNCOUNTER_OVERFLOW {
    J9_HANDLE_J9MIRROR_ATTRIBUTE_GROUNDWAVE          = (1 << 0),
    J9_HANDLE_J9_ATTRIBUTE_BEHAVIOUR_PALEOSTYLY      = (1 << 2),
    J9_HANDLE_ATTRIBUTE_BEHAVIOUR_MORBIDNESS         = (1 << 3),
    J9_HANDLE_J9M_ATTRIBUTE_BEHAVIOUR_TIMBERLIKE     = (1 << 4),
    J9_HANDLE__ATTRIBUTE_BEHAVIOUR_TIMBERLIKE        = (1 << 5),
    J9_HANDLE_J9M_ATTRIBUTE_BEHAVIOUR_PATHOMANIA     = (1 << 6),
    J9_HANDLE_J9MA_ATTRIBUTE_BEHAVIOUR_LEPROLOGIC    = (1 << 7),
    J9_HANDLE_J9MATHS_ATTRIBUTE_COFFEETIME           = (1 << 8),
    J9_HANDLE_J9MATHS_ATTRIBUTE_QUINOPYRIN           = (1 << 9),
    J9_HANDLE_J9_ATTRIBUTE_BEHAVIOUR_PHLEBOLOGY      = (1 << 10),
    J9_HANDLE_J_ATTRIBUTE_BEHAVIOUR_INUREMENTS       = (1 << 11),
} tag_jme_NNCOUNTER_OVERFLOW;

#define   J9_HANDLE_ATTRIBUTE_AUTOGENIES            0x9
typedef struct tag_jms_PROFILER_VIP_PROBE_COUNTERS {

    jmtUINT32       nn_layer_id;
    jmtUINT32       nn_layer_id_overflow;
    jmtUINT32       nn_instr_info;
    jmtUINT32       nn_total_busy_cycle;
    jmtUINT32       nn_total_busy_cycle_overflow;
    jmtUINT32       nn_total_read_cycle_ddr;
    jmtUINT32       nn_total_read_cycle_ddr_overflow;
    jmtUINT32       nn_total_read_valid_bandwidth_ddr;
    jmtUINT32       nn_total_read_valid_bandwidth_ddr_overflow;
    jmtUINT32       nn_total_write_cycle_ddr;
    jmtUINT32       nn_total_write_cycle_ddr_overflow;
    jmtUINT32       nn_total_write_valid_bandwidth_ddr;
    jmtUINT32       nn_total_write_valid_bandwidth_ddr_overflow;
    jmtUINT32       nn_total_read_cycle_sram;
    jmtUINT32       nn_total_read_cycle_sram_overflow;
    jmtUINT32       nn_total_write_cycle_sram;
    jmtUINT32       nn_total_write_cycle_sram_overflow;
    jmtUINT32       nn_total_mac_cycle;
    jmtUINT32       nn_total_mac_cycle_overflow;
    jmtUINT32       nn_total_mac_count;
    jmtUINT32       nn_total_mac_count_overflow;
    jmtUINT32       nn_zero_coef_skip_count;
    jmtUINT32       nn_zero_coef_skip_count_overflow;
    jmtUINT32       nn_non_zero_coef_count;
    jmtUINT32       nn_non_zero_coef_count_overflow;

    jmtUINT32       nn_reserved_counter[4 * J9_HANDLE_ATTRIBUTE_AUTOGENIES];
    jmtUINT32       nn_total_idle_cycle_core_overflow[4];
    jmtUINT32       nn_total_idle_cycle_core[32];


    jmtUINT32       tp_layer_id;
    jmtUINT32       tp_layer_id_overflow;
    jmtUINT32       tp_total_busy_cycle;
    jmtUINT32       tp_total_busy_cycle_overflow;

    jmtUINT32       tp_total_read_bandwidth_cache;
    jmtUINT32       tp_total_read_bandwidth_cache_overflow;
    jmtUINT32       tp_total_write_bandwidth_cache;
    jmtUINT32       tp_total_write_bandwidth_cache_overflow;

    jmtUINT32       tp_total_read_bandwidth_sram;
    jmtUINT32       tp_total_read_bandwidth_sram_overflow;
    jmtUINT32       tp_total_write_bandwidth_sram;
    jmtUINT32       tp_total_write_bandwidth_sram_overflow;

    jmtUINT32       tp_total_read_bandwidth_ocb;
    jmtUINT32       tp_total_read_bandwidth_ocb_overflow;
    jmtUINT32       tp_total_write_bandwidth_ocb;
    jmtUINT32       tp_total_write_bandwidth_ocb_overflow;

    jmtUINT32       tp_fc_pix_count;
    jmtUINT32       tp_fc_zero_skip_count;
    jmtUINT32       tp_fc_pix_count_overflow;
    jmtUINT32       tp_fc_zero_skip_count_overflow;

    jmtUINT32       tp_fc_coef_count;
    jmtUINT32       tp_fc_coef_zero_count;
    jmtUINT32       tp_fc_coef_count_overflow;
    jmtUINT32       tp_fc_coef_zero_count_overflow;

    jmtUINT32       tp_total_idle_cycle_core[16];
    jmtUINT32       tp_total_idle_cycle_core_overflows[16];
} j9_handle__attribute_chronicled;

#ifdef __cplusplus
}
#endif

#endif



