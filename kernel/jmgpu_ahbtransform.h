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




#ifndef __jmgpuregAHBTensorTransfDMA_h__
#define __jmgpuregAHBTensorTransfDMA_h__




#define mwv207regAHBTTSyncRegAddrs                                        0x0B00
#define MWV207REG_AHBTT_SYNC_Address                                     0x02C00
#define MWV207REG_AHBTT_SYNC_MSB                                              15
#define MWV207REG_AHBTT_SYNC_LSB                                               0
#define MWV207REG_AHBTT_SYNC_BLK                                               0
#define MWV207REG_AHBTT_SYNC_Count                                             1
#define MWV207REG_AHBTT_SYNC_FieldMask                                0x0000FFFF
#define MWV207REG_AHBTT_SYNC_ReadMask                                 0x0000FFFF
#define MWV207REG_AHBTT_SYNC_WriteMask                                0x00000000
#define MWV207REG_AHBTT_SYNC_ResetValue                               0x00000000

#define MWV207REG_AHBTT_SYNC_VIP_TENSOR_IO_BUSY                             15:0
#define MWV207REG_AHBTT_SYNC_VIP_TENSOR_IO_BUSY_End                           15
#define MWV207REG_AHBTT_SYNC_VIP_TENSOR_IO_BUSY_Start                          0
#define MWV207REG_AHBTT_SYNC_VIP_TENSOR_IO_BUSY_Type                         U16




#define mwv207regAHBTTDMiscRegAddrs                                       0x0B01
#define MWV207REG_AHBTTD_MISC_Address                                    0x02C04
#define MWV207REG_AHBTTD_MISC_MSB                                             15
#define MWV207REG_AHBTTD_MISC_LSB                                              0
#define MWV207REG_AHBTTD_MISC_BLK                                              0
#define MWV207REG_AHBTTD_MISC_Count                                            1
#define MWV207REG_AHBTTD_MISC_FieldMask                               0x0000007F
#define MWV207REG_AHBTTD_MISC_ReadMask                                0x00000000
#define MWV207REG_AHBTTD_MISC_WriteMask                               0x0000007F
#define MWV207REG_AHBTTD_MISC_ResetValue                              0x00000000

#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED                        0:0
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_End                      0
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_Start                    0
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_Type                   U01

#define MWV207REG_AHBTTD_MISC_VIP_SOFTWARE_FRAME_START                       1:1
#define MWV207REG_AHBTTD_MISC_VIP_SOFTWARE_FRAME_START_End                     1
#define MWV207REG_AHBTTD_MISC_VIP_SOFTWARE_FRAME_START_Start                   1
#define MWV207REG_AHBTTD_MISC_VIP_SOFTWARE_FRAME_START_Type                  U01

#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0                   2:2
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0_End                 2
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0_Start               2
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0_Type              U01

#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1                   3:3
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1_End                 3
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1_Start               3
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1_Type              U01

#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2                   4:4
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2_End                 4
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2_Start               4
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2_Type              U01

#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3                   5:5
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3_End                 5
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3_Start               5
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3_Type              U01

#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4                   6:6
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4_End                 6
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4_Start               6
#define MWV207REG_AHBTTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4_Type              U01



#define mwv207regAHBVIPTensorIoRegAddrs                                   0x0B02
#define MWV207REG_AHBVIP_TENSOR_IO_Address                               0x02C08
#define MWV207REG_AHBVIP_TENSOR_IO_MSB                                        15
#define MWV207REG_AHBVIP_TENSOR_IO_LSB                                         0
#define MWV207REG_AHBVIP_TENSOR_IO_BLK                                         0
#define MWV207REG_AHBVIP_TENSOR_IO_Count                                       1
#define MWV207REG_AHBVIP_TENSOR_IO_FieldMask                          0x0000FFFF
#define MWV207REG_AHBVIP_TENSOR_IO_ReadMask                           0x0000FFFF
#define MWV207REG_AHBVIP_TENSOR_IO_WriteMask                          0x0000FFFF
#define MWV207REG_AHBVIP_TENSOR_IO_ResetValue                         0x00000000

#define MWV207REG_AHBVIP_TENSOR_IO_ADDRESS                                  15:0
#define MWV207REG_AHBVIP_TENSOR_IO_ADDRESS_End                                15
#define MWV207REG_AHBVIP_TENSOR_IO_ADDRESS_Start                               0
#define MWV207REG_AHBVIP_TENSOR_IO_ADDRESS_Type                              U16



#define mwv207regAHBVIPTensorIoWrRegAddrs                                 0x0B03
#define MWV207REG_AHBVIP_TENSOR_IO_WR_Address                            0x02C0C
#define MWV207REG_AHBVIP_TENSOR_IO_WR_MSB                                     15
#define MWV207REG_AHBVIP_TENSOR_IO_WR_LSB                                      0
#define MWV207REG_AHBVIP_TENSOR_IO_WR_BLK                                      0
#define MWV207REG_AHBVIP_TENSOR_IO_WR_Count                                    1
#define MWV207REG_AHBVIP_TENSOR_IO_WR_FieldMask                       0xFFFFFFFF
#define MWV207REG_AHBVIP_TENSOR_IO_WR_ReadMask                        0xFFFFFFFF
#define MWV207REG_AHBVIP_TENSOR_IO_WR_WriteMask                       0xFFFFFFFF
#define MWV207REG_AHBVIP_TENSOR_IO_WR_ResetValue                      0x00000000

#define MWV207REG_AHBVIP_TENSOR_IO_WR_DATA                                  31:0
#define MWV207REG_AHBVIP_TENSOR_IO_WR_DATA_End                                31
#define MWV207REG_AHBVIP_TENSOR_IO_WR_DATA_Start                               0
#define MWV207REG_AHBVIP_TENSOR_IO_WR_DATA_Type                              U32




#define mwv207regAHBVIPDMARawStatusRegAddrs                               0x0B04
#define MWV207REG_AHBVIPDMA_RAW_STATUS_Address                           0x02C10
#define MWV207REG_AHBVIPDMA_RAW_STATUS_MSB                                    15
#define MWV207REG_AHBVIPDMA_RAW_STATUS_LSB                                     0
#define MWV207REG_AHBVIPDMA_RAW_STATUS_BLK                                     0
#define MWV207REG_AHBVIPDMA_RAW_STATUS_Count                                   1
#define MWV207REG_AHBVIPDMA_RAW_STATUS_FieldMask                      0x0003FFFF
#define MWV207REG_AHBVIPDMA_RAW_STATUS_ReadMask                       0x0003FFFF
#define MWV207REG_AHBVIPDMA_RAW_STATUS_WriteMask                      0x0003FFFF
#define MWV207REG_AHBVIPDMA_RAW_STATUS_ResetValue                     0x00000000

#define MWV207REG_AHBVIPDMA_RAW_STATUS_TENSOR_IO_FRAME_COMPL                15:0
#define MWV207REG_AHBVIPDMA_RAW_STATUS_TENSOR_IO_FRAME_COMPL_End              15
#define MWV207REG_AHBVIPDMA_RAW_STATUS_TENSOR_IO_FRAME_COMPL_Start             0
#define MWV207REG_AHBVIPDMA_RAW_STATUS_TENSOR_IO_FRAME_COMPL_Type            U16

#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_JOB_CANCEL_COMPL                16:16
#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_JOB_CANCEL_COMPL_End               16
#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_JOB_CANCEL_COMPL_Start             16
#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_JOB_CANCEL_COMPL_Type             U01

#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_SYNC_ERROR                      17:17
#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_SYNC_ERROR_End                     17
#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_SYNC_ERROR_Start                   17
#define MWV207REG_AHBVIPDMA_RAW_STATUS_VIP_SYNC_ERROR_Type                   U01



#define mwv207regAHBVIPDMAIntrEnRegAddrs                                  0x0B05
#define MWV207REG_AHBVIPDMA_INTR_EN_Address                              0x02C14
#define MWV207REG_AHBVIPDMA_INTR_EN_MSB                                       15
#define MWV207REG_AHBVIPDMA_INTR_EN_LSB                                        0
#define MWV207REG_AHBVIPDMA_INTR_EN_BLK                                        0
#define MWV207REG_AHBVIPDMA_INTR_EN_Count                                      1
#define MWV207REG_AHBVIPDMA_INTR_EN_FieldMask                         0x0003FFFF
#define MWV207REG_AHBVIPDMA_INTR_EN_ReadMask                          0x0003FFFF
#define MWV207REG_AHBVIPDMA_INTR_EN_WriteMask                         0x0003FFFF
#define MWV207REG_AHBVIPDMA_INTR_EN_ResetValue                        0x00000000

#define MWV207REG_AHBVIPDMA_INTR_EN_TENSOR_IO_FRAME_COMPL                   15:0
#define MWV207REG_AHBVIPDMA_INTR_EN_TENSOR_IO_FRAME_COMPL_End                 15
#define MWV207REG_AHBVIPDMA_INTR_EN_TENSOR_IO_FRAME_COMPL_Start                0
#define MWV207REG_AHBVIPDMA_INTR_EN_TENSOR_IO_FRAME_COMPL_Type               U16

#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_JOB_CANCEL_COMPL                   16:16
#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_JOB_CANCEL_COMPL_End                  16
#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_JOB_CANCEL_COMPL_Start                16
#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_JOB_CANCEL_COMPL_Type                U01

#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_SYNC_ERROR                         17:17
#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_SYNC_ERROR_End                        17
#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_SYNC_ERROR_Start                      17
#define MWV207REG_AHBVIPDMA_INTR_EN_VIP_SYNC_ERROR_Type                      U01



#define mwv207regAHBVIPDMAIntrStatusRegAddrs                              0x0B06
#define MWV207REG_AHBVIPDMA_INTR_STATUS_Address                          0x02C18
#define MWV207REG_AHBVIPDMA_INTR_STATUS_MSB                                   15
#define MWV207REG_AHBVIPDMA_INTR_STATUS_LSB                                    0
#define MWV207REG_AHBVIPDMA_INTR_STATUS_BLK                                    0
#define MWV207REG_AHBVIPDMA_INTR_STATUS_Count                                  1
#define MWV207REG_AHBVIPDMA_INTR_STATUS_FieldMask                     0x0003FFFF
#define MWV207REG_AHBVIPDMA_INTR_STATUS_ReadMask                      0x0003FFFF
#define MWV207REG_AHBVIPDMA_INTR_STATUS_WriteMask                     0x00000000
#define MWV207REG_AHBVIPDMA_INTR_STATUS_ResetValue                    0x00000000

#define MWV207REG_AHBVIPDMA_INTR_STATUS_TENSOR_IO_FRAME_COMPL               15:0
#define MWV207REG_AHBVIPDMA_INTR_STATUS_TENSOR_IO_FRAME_COMPL_End             15
#define MWV207REG_AHBVIPDMA_INTR_STATUS_TENSOR_IO_FRAME_COMPL_Start            0
#define MWV207REG_AHBVIPDMA_INTR_STATUS_TENSOR_IO_FRAME_COMPL_Type           U16

#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_JOB_CANCEL_COMPL               16:16
#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_JOB_CANCEL_COMPL_End              16
#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_JOB_CANCEL_COMPL_Start            16
#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_JOB_CANCEL_COMPL_Type            U01

#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_SYNC_ERROR                     17:17
#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_SYNC_ERROR_End                    17
#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_SYNC_ERROR_Start                  17
#define MWV207REG_AHBVIPDMA_INTR_STATUS_VIP_SYNC_ERROR_Type                  U01



#define mwv207regAHBVIPClockGateRegAddrs                                  0x0B07
#define MWV207REG_AHBVIP_CLOCK_GATE_Address                              0x02C1C
#define MWV207REG_AHBVIP_CLOCK_GATE_MSB                                       15
#define MWV207REG_AHBVIP_CLOCK_GATE_LSB                                        0
#define MWV207REG_AHBVIP_CLOCK_GATE_BLK                                        0
#define MWV207REG_AHBVIP_CLOCK_GATE_Count                                      1
#define MWV207REG_AHBVIP_CLOCK_GATE_FieldMask                         0xF8FFFFFE
#define MWV207REG_AHBVIP_CLOCK_GATE_ReadMask                          0xF8FFFFFE
#define MWV207REG_AHBVIP_CLOCK_GATE_WriteMask                         0xF8FFFFFE
#define MWV207REG_AHBVIP_CLOCK_GATE_ResetValue                        0x00000000


#define MWV207REG_AHBVIP_CLOCK_GATE_TOP_CMD_PARSER                           1:1
#define MWV207REG_AHBVIP_CLOCK_GATE_TOP_CMD_PARSER_End                         1
#define MWV207REG_AHBVIP_CLOCK_GATE_TOP_CMD_PARSER_Start                       1
#define MWV207REG_AHBVIP_CLOCK_GATE_TOP_CMD_PARSER_Type                      U01


#define MWV207REG_AHBVIP_CLOCK_GATE_KRNL_REQ                                 2:2
#define MWV207REG_AHBVIP_CLOCK_GATE_KRNL_REQ_End                               2
#define MWV207REG_AHBVIP_CLOCK_GATE_KRNL_REQ_Start                             2
#define MWV207REG_AHBVIP_CLOCK_GATE_KRNL_REQ_Type                            U01


#define MWV207REG_AHBVIP_CLOCK_GATE_IMG_REQ_HANDLE                           3:3
#define MWV207REG_AHBVIP_CLOCK_GATE_IMG_REQ_HANDLE_End                         3
#define MWV207REG_AHBVIP_CLOCK_GATE_IMG_REQ_HANDLE_Start                       3
#define MWV207REG_AHBVIP_CLOCK_GATE_IMG_REQ_HANDLE_Type                      U01


#define MWV207REG_AHBVIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL                 4:4
#define MWV207REG_AHBVIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL_End               4
#define MWV207REG_AHBVIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL_Start             4
#define MWV207REG_AHBVIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL_Type            U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_WR                          5:5
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_WR_End                        5
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_WR_Start                      5
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_WR_Type                     U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP                      6:6
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP_End                    6
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP_Start                  6
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP_Type                 U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD                  7:7
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD_End                7
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD_Start              7
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD_Type             U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD                 8:8
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD_End               8
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD_Start             8
#define MWV207REG_AHBVIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD_Type            U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TOP_PIPE_TOP                          9:9
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TOP_PIPE_TOP_End                        9
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TOP_PIPE_TOP_Start                      9
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TOP_PIPE_TOP_Type                     U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP1                               10:10
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP1_End                              10
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP1_Start                            10
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP1_Type                            U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2                               11:11
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2_End                              11
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2_Start                            11
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2_Type                            U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PP_BST_COL                             12:12
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_BST_COL_End                            12
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_BST_COL_Start                          12
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_BST_COL_Type                          U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2_DMA                           13:13
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2_DMA_End                          13
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2_DMA_Start                        13
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_TRSP2_DMA_Type                        U01

#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT  14:14
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT_End 14
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT_Start 14
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT_Type U01

#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP        15:15
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP_End       15
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP_Start     15
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP_Type     U01

#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD    16:16
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD_End   16
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD_Start 16
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD_Type U01


#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT           17:17
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT_End          17
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT_Start        17
#define MWV207REG_AHBVIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT_Type        U01


#define MWV207REG_AHBVIP_CLOCK_GATE_CP_TOP_CONV_CORE                       18:18
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_TOP_CONV_CORE_End                      18
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_TOP_CONV_CORE_Start                    18
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_TOP_CONV_CORE_Type                    U01


#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_WR_RD                       19:19
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_WR_RD_End                      19
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_WR_RD_Start                    19
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_WR_RD_Type                    U01


#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_OUT                         20:20
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_OUT_End                        20
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_OUT_Start                      20
#define MWV207REG_AHBVIP_CLOCK_GATE_CP_IMG_BUF_OUT_Type                      U01


#define MWV207REG_AHBVIP_CLOCK_GATE_CC_DECOMP                              21:21
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_DECOMP_End                             21
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_DECOMP_Start                           21
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_DECOMP_Type                           U01

#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG 22:22
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG_End 22
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG_Start 22
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG_Type U01


#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO                     23:23
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO_End                    23
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO_Start                  23
#define MWV207REG_AHBVIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO_Type                  U01


#define MWV207REG_AHBVIP_CLOCK_GATE_VIP_GATING                             27:27
#define MWV207REG_AHBVIP_CLOCK_GATE_VIP_GATING_End                            27
#define MWV207REG_AHBVIP_CLOCK_GATE_VIP_GATING_Start                          27
#define MWV207REG_AHBVIP_CLOCK_GATE_VIP_GATING_Type                          U01


#define MWV207REG_AHBVIP_CLOCK_GATE_DEEP_SLEEP                             28:28
#define MWV207REG_AHBVIP_CLOCK_GATE_DEEP_SLEEP_End                            28
#define MWV207REG_AHBVIP_CLOCK_GATE_DEEP_SLEEP_Start                          28
#define MWV207REG_AHBVIP_CLOCK_GATE_DEEP_SLEEP_Type                          U01


#define MWV207REG_AHBVIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING               29:29
#define MWV207REG_AHBVIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING_End              29
#define MWV207REG_AHBVIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING_Start            29
#define MWV207REG_AHBVIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING_Type            U01


#define MWV207REG_AHBVIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS                  30:30
#define MWV207REG_AHBVIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS_End                 30
#define MWV207REG_AHBVIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS_Start               30
#define MWV207REG_AHBVIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS_Type               U01


#define MWV207REG_AHBVIP_CLOCK_GATE_SH_USC_RELATED                         31:31
#define MWV207REG_AHBVIP_CLOCK_GATE_SH_USC_RELATED_End                        31
#define MWV207REG_AHBVIP_CLOCK_GATE_SH_USC_RELATED_Start                      31
#define MWV207REG_AHBVIP_CLOCK_GATE_SH_USC_RELATED_Type                      U01




#define mwv207regAHBVIPDebugRegAddrs                                      0x0B08
#define MWV207REG_AHBVIP_DEBUG_Address                                   0x02C20
#define MWV207REG_AHBVIP_DEBUG_MSB                                            15
#define MWV207REG_AHBVIP_DEBUG_LSB                                             0
#define MWV207REG_AHBVIP_DEBUG_BLK                                             0
#define MWV207REG_AHBVIP_DEBUG_Count                                           1
#define MWV207REG_AHBVIP_DEBUG_FieldMask                              0xFFFFFFFF
#define MWV207REG_AHBVIP_DEBUG_ReadMask                               0xFFFFFFFF
#define MWV207REG_AHBVIP_DEBUG_WriteMask                              0xFFFFFFFF
#define MWV207REG_AHBVIP_DEBUG_ResetValue                             0x00000000

#define MWV207REG_AHBVIP_DEBUG_OCLA                                         31:0
#define MWV207REG_AHBVIP_DEBUG_OCLA_End                                       31
#define MWV207REG_AHBVIP_DEBUG_OCLA_Start                                      0
#define MWV207REG_AHBVIP_DEBUG_OCLA_Type                                     U32





#define mwv207regAHBXTTDMiscRegAddrs                                      0x0B10
#define MWV207REG_AHBXTTD_MISC_Address                                   0x02C40
#define MWV207REG_AHBXTTD_MISC_MSB                                            15
#define MWV207REG_AHBXTTD_MISC_LSB                                             0
#define MWV207REG_AHBXTTD_MISC_BLK                                             0
#define MWV207REG_AHBXTTD_MISC_Count                                           1
#define MWV207REG_AHBXTTD_MISC_FieldMask                              0xFFFFFFFF
#define MWV207REG_AHBXTTD_MISC_ReadMask                               0xFF9FFFFC
#define MWV207REG_AHBXTTD_MISC_WriteMask                              0xFFFE01FF
#define MWV207REG_AHBXTTD_MISC_ResetValue                             0xFF000040

#define MWV207REG_AHBXTTD_MISC_XSHADOW_REG_PREPARED                          0:0
#define MWV207REG_AHBXTTD_MISC_XSHADOW_REG_PREPARED_End                        0
#define MWV207REG_AHBXTTD_MISC_XSHADOW_REG_PREPARED_Start                      0
#define MWV207REG_AHBXTTD_MISC_XSHADOW_REG_PREPARED_Type                     U01

#define MWV207REG_AHBXTTD_MISC_XSOFTWARE_FRAME_START                         1:1
#define MWV207REG_AHBXTTD_MISC_XSOFTWARE_FRAME_START_End                       1
#define MWV207REG_AHBXTTD_MISC_XSOFTWARE_FRAME_START_Start                     1
#define MWV207REG_AHBXTTD_MISC_XSOFTWARE_FRAME_START_Type                    U01

#define MWV207REG_AHBXTTD_MISC_VIP_CLUSTER_CLOCK_GATE                        5:2
#define MWV207REG_AHBXTTD_MISC_VIP_CLUSTER_CLOCK_GATE_End                      5
#define MWV207REG_AHBXTTD_MISC_VIP_CLUSTER_CLOCK_GATE_Start                    2
#define MWV207REG_AHBXTTD_MISC_VIP_CLUSTER_CLOCK_GATE_Type                   U04

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET                                    6:6
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_End                                  6
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_Start                                6
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_Type                               U01


#define MWV207REG_AHBXTTD_MISC_DENOISE_POST_PROCESS_BYPASS                   7:7
#define MWV207REG_AHBXTTD_MISC_DENOISE_POST_PROCESS_BYPASS_End                 7
#define MWV207REG_AHBXTTD_MISC_DENOISE_POST_PROCESS_BYPASS_Start               7
#define MWV207REG_AHBXTTD_MISC_DENOISE_POST_PROCESS_BYPASS_Type              U01

#define MWV207REG_AHBXTTD_MISC_OCM_BYPASS                                    8:8
#define MWV207REG_AHBXTTD_MISC_OCM_BYPASS_End                                  8
#define MWV207REG_AHBXTTD_MISC_OCM_BYPASS_Start                                8
#define MWV207REG_AHBXTTD_MISC_OCM_BYPASS_Type                               U01

#define MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY                              16:9
#define MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_End                            16
#define MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_Start                           9
#define MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_Type                          U08
#define   MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_DMA5                       0x01
#define   MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_DMA6                       0x02
#define   MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_DMA7                       0x04
#define   MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_DMA8                       0x08
#define   MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_DMA9                       0x10
#define   MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_DMA10                      0x20
#define   MWV207REG_AHBXTTD_MISC_XTENSOR_IO_BUSY_MATRIX                     0x40

#define MWV207REG_AHBXTTD_MISC_DEFAULT_QOS                                 20:17
#define MWV207REG_AHBXTTD_MISC_DEFAULT_QOS_End                                20
#define MWV207REG_AHBXTTD_MISC_DEFAULT_QOS_Start                              17
#define MWV207REG_AHBXTTD_MISC_DEFAULT_QOS_Type                              U04

#define MWV207REG_AHBXTTD_MISC_XISP_SHADOW_REG_PREPARED                    21:21
#define MWV207REG_AHBXTTD_MISC_XISP_SHADOW_REG_PREPARED_End                   21
#define MWV207REG_AHBXTTD_MISC_XISP_SHADOW_REG_PREPARED_Start                 21
#define MWV207REG_AHBXTTD_MISC_XISP_SHADOW_REG_PREPARED_Type                 U01


#define MWV207REG_AHBXTTD_MISC_XISP_SOFT_WARE_FRAME_START                  22:22
#define MWV207REG_AHBXTTD_MISC_XISP_SOFT_WARE_FRAME_START_End                 22
#define MWV207REG_AHBXTTD_MISC_XISP_SOFT_WARE_FRAME_START_Start               22
#define MWV207REG_AHBXTTD_MISC_XISP_SOFT_WARE_FRAME_START_Type               U01

#define MWV207REG_AHBXTTD_MISC_XJOB_CANCEL                                 23:23
#define MWV207REG_AHBXTTD_MISC_XJOB_CANCEL_End                                23
#define MWV207REG_AHBXTTD_MISC_XJOB_CANCEL_Start                              23
#define MWV207REG_AHBXTTD_MISC_XJOB_CANCEL_Type                              U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP0                             24:24
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP0_End                            24
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP0_Start                          24
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP0_Type                          U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP1                             25:25
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP1_End                            25
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP1_Start                          25
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP1_Type                          U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP2                             26:26
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP2_End                            26
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP2_Start                          26
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP2_Type                          U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP3                             27:27
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP3_End                            27
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP3_Start                          27
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_VIP3_Type                          U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP0                         28:28
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP0_End                        28
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP0_Start                      28
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP0_Type                      U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP1                         29:29
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP1_End                        29
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP1_Start                      29
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP1_Type                      U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP2                         30:30
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP2_End                        30
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP2_Start                      30
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP2_Type                      U01

#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP3                         31:31
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP3_End                        31
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP3_Start                      31
#define MWV207REG_AHBXTTD_MISC_SOFT_RESET_ACLKVIP3_Type                      U01



#define mwv207regAHBXTensorIoRegAddrs                                     0x0B11
#define MWV207REG_AHBX_TENSOR_IO_Address                                 0x02C44
#define MWV207REG_AHBX_TENSOR_IO_MSB                                          15
#define MWV207REG_AHBX_TENSOR_IO_LSB                                           0
#define MWV207REG_AHBX_TENSOR_IO_BLK                                           0
#define MWV207REG_AHBX_TENSOR_IO_Count                                         1
#define MWV207REG_AHBX_TENSOR_IO_FieldMask                            0x0000FFFF
#define MWV207REG_AHBX_TENSOR_IO_ReadMask                             0x0000FFFF
#define MWV207REG_AHBX_TENSOR_IO_WriteMask                            0x0000FFFF
#define MWV207REG_AHBX_TENSOR_IO_ResetValue                           0x00000000

#define MWV207REG_AHBX_TENSOR_IO_ADDRESS                                    15:0
#define MWV207REG_AHBX_TENSOR_IO_ADDRESS_End                                  15
#define MWV207REG_AHBX_TENSOR_IO_ADDRESS_Start                                 0
#define MWV207REG_AHBX_TENSOR_IO_ADDRESS_Type                                U16



#define mwv207regAHBXTensorIoWrRegAddrs                                   0x0B12
#define MWV207REG_AHBX_TENSOR_IO_WR_Address                              0x02C48
#define MWV207REG_AHBX_TENSOR_IO_WR_MSB                                       15
#define MWV207REG_AHBX_TENSOR_IO_WR_LSB                                        0
#define MWV207REG_AHBX_TENSOR_IO_WR_BLK                                        0
#define MWV207REG_AHBX_TENSOR_IO_WR_Count                                      1
#define MWV207REG_AHBX_TENSOR_IO_WR_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TENSOR_IO_WR_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_TENSOR_IO_WR_WriteMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TENSOR_IO_WR_ResetValue                        0x00000000

#define MWV207REG_AHBX_TENSOR_IO_WR_DATA                                    31:0
#define MWV207REG_AHBX_TENSOR_IO_WR_DATA_End                                  31
#define MWV207REG_AHBX_TENSOR_IO_WR_DATA_Start                                 0
#define MWV207REG_AHBX_TENSOR_IO_WR_DATA_Type                                U32



#define mwv207regAHBSbiInPureqToPureqMaxCycleRegAddrs                     0x0B13
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_Address            0x02C4C
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_MSB                     15
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_LSB                      0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_BLK                      0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_Count                    1
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_FieldMask       0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_ReadMask        0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_WriteMask       0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_ResetValue      0x00000000

#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_COUNT                 31:0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_COUNT_End               31
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_COUNT_Start              0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_MAX_CYCLE_COUNT_Type             U32



#define mwv207regAHBSbiInPureqToPureqTimeoutRegAddrs                      0x0B14
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_Address              0x02C50
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_MSB                       15
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_LSB                        0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_BLK                        0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_Count                      1
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_FieldMask         0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_ReadMask          0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_WriteMask         0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_ResetValue        0x00000000

#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_THRESHOLD               31:0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_THRESHOLD_End             31
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_THRESHOLD_Start            0
#define MWV207REG_AHB_SBI_IN_PUREQ_TO_PUREQ_TIMEOUT_THRESHOLD_Type           U32



#define mwv207regAHBSbiOutCureqToCureqMaxCycleRegAddrs                    0x0B15
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_Address           0x02C54
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_MSB                    15
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_LSB                     0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_BLK                     0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_Count                   1
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_FieldMask      0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_ReadMask       0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_WriteMask      0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_ResetValue     0x00000000

#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_COUNT                31:0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_COUNT_End              31
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_COUNT_Start             0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_MAX_CYCLE_COUNT_Type            U32



#define mwv207regAHBSbiOutCureqToCureqTimeoutRegAddrs                     0x0B16
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_Address             0x02C58
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_MSB                      15
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_LSB                       0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_BLK                       0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_Count                     1
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_FieldMask        0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_ReadMask         0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_WriteMask        0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_ResetValue       0x00000000

#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_THRESOLD               31:0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_THRESOLD_End             31
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_THRESOLD_Start            0
#define MWV207REG_AHB_SBI_OUT_CUREQ_TO_CUREQ_TIMEOUT_THRESOLD_Type           U32



#define mwv207regAHBSbiInPrreqToPrackMaxCycleRegAddrs                     0x0B17
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_Address            0x02C5C
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_MSB                     15
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_LSB                      0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_BLK                      0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_Count                    1
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_FieldMask       0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_ReadMask        0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_WriteMask       0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_ResetValue      0x00000000

#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_COUNT                 31:0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_COUNT_End               31
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_COUNT_Start              0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_MAX_CYCLE_COUNT_Type             U32



#define mwv207regAHBSbiInPrreqToPrackTimeoutRegAddrs                      0x0B18
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_Address              0x02C60
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_MSB                       15
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_LSB                        0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_BLK                        0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_Count                      1
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_FieldMask         0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_ReadMask          0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_WriteMask         0xFFFFFFFF
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_ResetValue        0x00000000

#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_THRESHOLD               31:0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_THRESHOLD_End             31
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_THRESHOLD_Start            0
#define MWV207REG_AHB_SBI_IN_PRREQ_TO_PRACK_TIMEOUT_THRESHOLD_Type           U32



#define mwv207regAHBSbiOutCrreqToCrackMaxCycleRegAddrs                    0x0B19
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_Address           0x02C64
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_MSB                    15
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_LSB                     0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_BLK                     0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_Count                   1
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_FieldMask      0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_ReadMask       0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_WriteMask      0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_ResetValue     0x00000000

#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_COUNT                31:0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_COUNT_End              31
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_COUNT_Start             0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_MAX_CYCLE_COUNT_Type            U32



#define mwv207regAHBSbiOutCrreqToCrackTimeoutRegAddrs                     0x0B1A
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_Address             0x02C68
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_MSB                      15
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_LSB                       0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_BLK                       0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_Count                     1
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_FieldMask        0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_ReadMask         0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_WriteMask        0xFFFFFFFF
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_ResetValue       0x00000000

#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_THRESHOLD              31:0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_THRESHOLD_End            31
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_THRESHOLD_Start           0
#define MWV207REG_AHB_SBI_OUT_CRREQ_TO_CRACK_TIMEOUT_THRESHOLD_Type          U32



#define mwv207regAHBOcmRemapStartAddressRegAddrs                          0x0B1B
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_Address                    0x02C6C
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_MSB                             15
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_LSB                              0
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_BLK                              0
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_Count                            1
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_ReadMask                0xFFFFFFFF
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_WriteMask               0xFFFFFFFF
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_ResetValue              0x08000000

#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_ADDR_VALUE                    31:0
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_ADDR_VALUE_End                  31
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_ADDR_VALUE_Start                 0
#define MWV207REG_AHB_OCM_REMAP_START_ADDRESS_ADDR_VALUE_Type                U32



#define mwv207regAHBOcmRemapEndAddressRegAddrs                            0x0B1C
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_Address                      0x02C70
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_MSB                               15
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_LSB                                0
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_BLK                                0
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_Count                              1
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_FieldMask                 0xFFFFFFFF
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_ReadMask                  0xFFFFFFFF
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_WriteMask                 0xFFFFFFFF
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_ResetValue                0x08480000

#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_ADDR_VALUE                      31:0
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_ADDR_VALUE_End                    31
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_ADDR_VALUE_Start                   0
#define MWV207REG_AHB_OCM_REMAP_END_ADDRESS_ADDR_VALUE_Type                  U32




#define mwv207regAHBSWControlVXSBI0RegAddrs                               0x0B1D
#define MWV207REG_AHBSW_CONTROL_VXSBI0_Address                           0x02C74
#define MWV207REG_AHBSW_CONTROL_VXSBI0_MSB                                    15
#define MWV207REG_AHBSW_CONTROL_VXSBI0_LSB                                     0
#define MWV207REG_AHBSW_CONTROL_VXSBI0_BLK                                     0
#define MWV207REG_AHBSW_CONTROL_VXSBI0_Count                                   1
#define MWV207REG_AHBSW_CONTROL_VXSBI0_FieldMask                      0x0000003F
#define MWV207REG_AHBSW_CONTROL_VXSBI0_ReadMask                       0x0000003F
#define MWV207REG_AHBSW_CONTROL_VXSBI0_WriteMask                      0x0000003F
#define MWV207REG_AHBSW_CONTROL_VXSBI0_ResetValue                     0x00000000

#define MWV207REG_AHBSW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT                   1:0
#define MWV207REG_AHBSW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_End                 1
#define MWV207REG_AHBSW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_Start               0
#define MWV207REG_AHBSW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_Type              U02
#define   MWV207REG_AHBSW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_ISP             0x0
#define   MWV207REG_AHBSW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_SOFT_CONTROL    0x1
#define   MWV207REG_AHBSW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_PATTERN_GEN     0x2


#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_WR_FRAME_START                    2:2
#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_WR_FRAME_START_End                  2
#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_WR_FRAME_START_Start                2
#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_WR_FRAME_START_Type               U01

#define MWV207REG_AHBSW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT                   4:3
#define MWV207REG_AHBSW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_End                 4
#define MWV207REG_AHBSW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_Start               3
#define MWV207REG_AHBSW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_Type              U02
#define   MWV207REG_AHBSW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_ISP             0x0
#define   MWV207REG_AHBSW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_SOFT_CONTROL    0x1
#define   MWV207REG_AHBSW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_CHECK_SUM_GEN   0x2


#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_RD_FRAME_START                    5:5
#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_RD_FRAME_START_End                  5
#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_RD_FRAME_START_Start                5
#define MWV207REG_AHBSW_CONTROL_VXSBI0_SBI_RD_FRAME_START_Type               U01




#define mwv207regAHBSWControlVXSBI1RegAddrs                               0x0B1E
#define MWV207REG_AHBSW_CONTROL_VXSBI1_Address                           0x02C78
#define MWV207REG_AHBSW_CONTROL_VXSBI1_MSB                                    15
#define MWV207REG_AHBSW_CONTROL_VXSBI1_LSB                                     0
#define MWV207REG_AHBSW_CONTROL_VXSBI1_BLK                                     0
#define MWV207REG_AHBSW_CONTROL_VXSBI1_Count                                   1
#define MWV207REG_AHBSW_CONTROL_VXSBI1_FieldMask                      0x0000000F
#define MWV207REG_AHBSW_CONTROL_VXSBI1_ReadMask                       0x0000000F
#define MWV207REG_AHBSW_CONTROL_VXSBI1_WriteMask                      0x0000000F
#define MWV207REG_AHBSW_CONTROL_VXSBI1_ResetValue                     0x00000000


#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PR_REQ                             0:0
#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PR_REQ_End                           0
#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PR_REQ_Start                         0
#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PR_REQ_Type                        U01


#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PU_REQ                             1:1
#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PU_REQ_End                           1
#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PU_REQ_Start                         1
#define MWV207REG_AHBSW_CONTROL_VXSBI1_WR_PU_REQ_Type                        U01


#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CR_REQ                             2:2
#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CR_REQ_End                           2
#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CR_REQ_Start                         2
#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CR_REQ_Type                        U01


#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CU_REQ                             3:3
#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CU_REQ_End                           3
#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CU_REQ_Start                         3
#define MWV207REG_AHBSW_CONTROL_VXSBI1_RD_CU_REQ_Type                        U01




#define mwv207regAHBSWControlVXSBI2RegAddrs                               0x0B1F
#define MWV207REG_AHBSW_CONTROL_VXSBI2_Address                           0x02C7C
#define MWV207REG_AHBSW_CONTROL_VXSBI2_MSB                                    15
#define MWV207REG_AHBSW_CONTROL_VXSBI2_LSB                                     0
#define MWV207REG_AHBSW_CONTROL_VXSBI2_BLK                                     0
#define MWV207REG_AHBSW_CONTROL_VXSBI2_Count                                   1
#define MWV207REG_AHBSW_CONTROL_VXSBI2_FieldMask                      0x0000000F
#define MWV207REG_AHBSW_CONTROL_VXSBI2_ReadMask                       0x0000000F
#define MWV207REG_AHBSW_CONTROL_VXSBI2_WriteMask                      0x0000000F
#define MWV207REG_AHBSW_CONTROL_VXSBI2_ResetValue                     0x00000000


#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PR_ACK                             0:0
#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PR_ACK_End                           0
#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PR_ACK_Start                         0
#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PR_ACK_Type                        U01


#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PU_ACK                             1:1
#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PU_ACK_End                           1
#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PU_ACK_Start                         1
#define MWV207REG_AHBSW_CONTROL_VXSBI2_WR_PU_ACK_Type                        U01


#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CR_ACK                             2:2
#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CR_ACK_End                           2
#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CR_ACK_Start                         2
#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CR_ACK_Type                        U01


#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CU_ACK                             3:3
#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CU_ACK_End                           3
#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CU_ACK_Start                         3
#define MWV207REG_AHBSW_CONTROL_VXSBI2_RD_CU_ACK_Type                        U01




#define mwv207regAHBPtnGenBayerImageRegAddrs                              0x0B20
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_Address                        0x02C80
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_MSB                                 15
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_LSB                                  0
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_BLK                                  0
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_Count                                1
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_FieldMask                   0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_ReadMask                    0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_WriteMask                   0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_ResetValue                  0x0C001100


#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_WIDTH                             15:0
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_WIDTH_End                           15
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_WIDTH_Start                          0
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_WIDTH_Type                         U16


#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_HEIGHT                           31:16
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_HEIGHT_End                          31
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_HEIGHT_Start                        16
#define MWV207REG_AHB_PTN_GEN_BAYER_IMAGE_HEIGHT_Type                        U16

#define mwv207regAHBPtnGenRedRegAddrs                                     0x0B21
#define MWV207REG_AHB_PTN_GEN_RED_Address                                0x02C84
#define MWV207REG_AHB_PTN_GEN_RED_MSB                                         15
#define MWV207REG_AHB_PTN_GEN_RED_LSB                                          0
#define MWV207REG_AHB_PTN_GEN_RED_BLK                                          0
#define MWV207REG_AHB_PTN_GEN_RED_Count                                        1
#define MWV207REG_AHB_PTN_GEN_RED_FieldMask                           0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_RED_ReadMask                            0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_RED_WriteMask                           0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_RED_ResetValue                          0x00000000


#define MWV207REG_AHB_PTN_GEN_RED_INIT                                      15:0
#define MWV207REG_AHB_PTN_GEN_RED_INIT_End                                    15
#define MWV207REG_AHB_PTN_GEN_RED_INIT_Start                                   0
#define MWV207REG_AHB_PTN_GEN_RED_INIT_Type                                  U16


#define MWV207REG_AHB_PTN_GEN_RED_INC_X                                    31:16
#define MWV207REG_AHB_PTN_GEN_RED_INC_X_End                                   31
#define MWV207REG_AHB_PTN_GEN_RED_INC_X_Start                                 16
#define MWV207REG_AHB_PTN_GEN_RED_INC_X_Type                                 U16

#define mwv207regAHBPtnGenGreensRegAddrs                                  0x0B22
#define MWV207REG_AHB_PTN_GEN_GREENS_Address                             0x02C88
#define MWV207REG_AHB_PTN_GEN_GREENS_MSB                                      15
#define MWV207REG_AHB_PTN_GEN_GREENS_LSB                                       0
#define MWV207REG_AHB_PTN_GEN_GREENS_BLK                                       0
#define MWV207REG_AHB_PTN_GEN_GREENS_Count                                     1
#define MWV207REG_AHB_PTN_GEN_GREENS_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_GREENS_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_GREENS_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_GREENS_ResetValue                       0x00000000


#define MWV207REG_AHB_PTN_GEN_GREENS_INIT                                   15:0
#define MWV207REG_AHB_PTN_GEN_GREENS_INIT_End                                 15
#define MWV207REG_AHB_PTN_GEN_GREENS_INIT_Start                                0
#define MWV207REG_AHB_PTN_GEN_GREENS_INIT_Type                               U16


#define MWV207REG_AHB_PTN_GEN_GREENS_INC_X                                 31:16
#define MWV207REG_AHB_PTN_GEN_GREENS_INC_X_End                                31
#define MWV207REG_AHB_PTN_GEN_GREENS_INC_X_Start                              16
#define MWV207REG_AHB_PTN_GEN_GREENS_INC_X_Type                              U16

#define mwv207regAHBPtnGenBlueRegAddrs                                    0x0B23
#define MWV207REG_AHB_PTN_GEN_BLUE_Address                               0x02C8C
#define MWV207REG_AHB_PTN_GEN_BLUE_MSB                                        15
#define MWV207REG_AHB_PTN_GEN_BLUE_LSB                                         0
#define MWV207REG_AHB_PTN_GEN_BLUE_BLK                                         0
#define MWV207REG_AHB_PTN_GEN_BLUE_Count                                       1
#define MWV207REG_AHB_PTN_GEN_BLUE_FieldMask                          0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_BLUE_ReadMask                           0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_BLUE_WriteMask                          0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_BLUE_ResetValue                         0x00000000


#define MWV207REG_AHB_PTN_GEN_BLUE_INIT                                     15:0
#define MWV207REG_AHB_PTN_GEN_BLUE_INIT_End                                   15
#define MWV207REG_AHB_PTN_GEN_BLUE_INIT_Start                                  0
#define MWV207REG_AHB_PTN_GEN_BLUE_INIT_Type                                 U16


#define MWV207REG_AHB_PTN_GEN_BLUE_INC_X                                   31:16
#define MWV207REG_AHB_PTN_GEN_BLUE_INC_X_End                                  31
#define MWV207REG_AHB_PTN_GEN_BLUE_INC_X_Start                                16
#define MWV207REG_AHB_PTN_GEN_BLUE_INC_X_Type                                U16




#define mwv207regAHBPtnGenIncY0RegAddrs                                   0x0B24
#define MWV207REG_AHB_PTN_GEN_INC_Y0_Address                             0x02C90
#define MWV207REG_AHB_PTN_GEN_INC_Y0_MSB                                      15
#define MWV207REG_AHB_PTN_GEN_INC_Y0_LSB                                       0
#define MWV207REG_AHB_PTN_GEN_INC_Y0_BLK                                       0
#define MWV207REG_AHB_PTN_GEN_INC_Y0_Count                                     1
#define MWV207REG_AHB_PTN_GEN_INC_Y0_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_INC_Y0_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_INC_Y0_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_PTN_GEN_INC_Y0_ResetValue                       0x00000000

#define MWV207REG_AHB_PTN_GEN_INC_Y0_RED                                    15:0
#define MWV207REG_AHB_PTN_GEN_INC_Y0_RED_End                                  15
#define MWV207REG_AHB_PTN_GEN_INC_Y0_RED_Start                                 0
#define MWV207REG_AHB_PTN_GEN_INC_Y0_RED_Type                                U16


#define MWV207REG_AHB_PTN_GEN_INC_Y0_GREENS                                31:16
#define MWV207REG_AHB_PTN_GEN_INC_Y0_GREENS_End                               31
#define MWV207REG_AHB_PTN_GEN_INC_Y0_GREENS_Start                             16
#define MWV207REG_AHB_PTN_GEN_INC_Y0_GREENS_Type                             U16

#define mwv207regAHBPtnGenIncY1RegAddrs                                   0x0B25
#define MWV207REG_AHB_PTN_GEN_INC_Y1_Address                             0x02C94
#define MWV207REG_AHB_PTN_GEN_INC_Y1_MSB                                      15
#define MWV207REG_AHB_PTN_GEN_INC_Y1_LSB                                       0
#define MWV207REG_AHB_PTN_GEN_INC_Y1_BLK                                       0
#define MWV207REG_AHB_PTN_GEN_INC_Y1_Count                                     1
#define MWV207REG_AHB_PTN_GEN_INC_Y1_FieldMask                        0x0000FFFF
#define MWV207REG_AHB_PTN_GEN_INC_Y1_ReadMask                         0x0000FFFF
#define MWV207REG_AHB_PTN_GEN_INC_Y1_WriteMask                        0x0000FFFF
#define MWV207REG_AHB_PTN_GEN_INC_Y1_ResetValue                       0x00000000


#define MWV207REG_AHB_PTN_GEN_INC_Y1_BLUE                                   15:0
#define MWV207REG_AHB_PTN_GEN_INC_Y1_BLUE_End                                 15
#define MWV207REG_AHB_PTN_GEN_INC_Y1_BLUE_Start                                0
#define MWV207REG_AHB_PTN_GEN_INC_Y1_BLUE_Type                               U16




#define mwv207regAHBChecksumActualChecksumRedRegAddrs                     0x0B26
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_Address               0x02C98
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_MSB                        15
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_LSB                         0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_BLK                         0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_Count                       1
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_FieldMask          0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_ReadMask           0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_WriteMask          0x00000000
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_ResetValue         0x00000000

#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_VALUE                    31:0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_VALUE_End                  31
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_VALUE_Start                 0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_RED_VALUE_Type                U32




#define mwv207regAHBChecksumActualChecksumGreenRegAddrs                   0x0B27
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_Address             0x02C9C
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_MSB                      15
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_LSB                       0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_BLK                       0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_Count                     1
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_FieldMask        0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_ReadMask         0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_WriteMask        0x00000000
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_ResetValue       0x00000000

#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_VALUE                  31:0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_VALUE_End                31
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_VALUE_Start               0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_GREEN_VALUE_Type              U32




#define mwv207regAHBChecksumActualChecksumBlueRegAddrs                    0x0B28
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_Address              0x02CA0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_MSB                       15
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_LSB                        0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_BLK                        0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_Count                      1
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_FieldMask         0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_ReadMask          0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_WriteMask         0x00000000
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_ResetValue        0x00000000

#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_VALUE                   31:0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_VALUE_End                 31
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_VALUE_Start                0
#define MWV207REG_AHB_CHECKSUM_ACTUAL_CHECKSUM_BLUE_VALUE_Type               U32




#define mwv207regAHBChecksumExpectedChecksumRedRegAddrs                   0x0B29
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_Address             0x02CA4
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_MSB                      15
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_LSB                       0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_BLK                       0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_Count                     1
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_FieldMask        0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_ReadMask         0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_WriteMask        0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_ResetValue       0x00000000

#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE                  31:0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE_End                31
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE_Start               0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE_Type              U32




#define mwv207regAHBChecksumExpectedChecksumGreenRegAddrs                 0x0B2A
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_Address           0x02CA8
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_MSB                    15
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_LSB                     0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_BLK                     0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_Count                   1
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_FieldMask      0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_ReadMask       0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_WriteMask      0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_ResetValue     0x00000000

#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE                31:0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE_End              31
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE_Start             0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE_Type            U32




#define mwv207regAHBChecksumExpectedChecksumBlueRegAddrs                  0x0B2B
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_Address            0x02CAC
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_MSB                     15
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_LSB                      0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_BLK                      0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_Count                    1
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_FieldMask       0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_ReadMask        0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_WriteMask       0xFFFFFFFF
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_ResetValue      0x00000000

#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE                 31:0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE_End               31
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE_Start              0
#define MWV207REG_AHB_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE_Type             U32




#define mwv207regAHBPatternsRegAddrs                                      0x0B2C
#define MWV207REG_AHB_PATTERNS_Address                                   0x02CB0
#define MWV207REG_AHB_PATTERNS_MSB                                            15
#define MWV207REG_AHB_PATTERNS_LSB                                             0
#define MWV207REG_AHB_PATTERNS_BLK                                             0
#define MWV207REG_AHB_PATTERNS_Count                                           1
#define MWV207REG_AHB_PATTERNS_FieldMask                              0x0000003F
#define MWV207REG_AHB_PATTERNS_ReadMask                               0x0000003F
#define MWV207REG_AHB_PATTERNS_WriteMask                              0x0000003F
#define MWV207REG_AHB_PATTERNS_ResetValue                             0x00000000

#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_RED                          0:0
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_RED_End                        0
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_RED_Start                      0
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_RED_Type                     U01
#define   MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_RED_DISABLE                0x0
#define   MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_RED_ENABLE                 0x1

#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_GREEN                        1:1
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_GREEN_End                      1
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_GREEN_Start                    1
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_GREEN_Type                   U01
#define   MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_GREEN_DISABLE              0x0
#define   MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_GREEN_ENABLE               0x1

#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_BLUE                         2:2
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_BLUE_End                       2
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_BLUE_Start                     2
#define MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_BLUE_Type                    U01
#define   MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_BLUE_DISABLE               0x0
#define   MWV207REG_AHB_PATTERNS_COMPARE_CHECKSUM_BLUE_ENABLE                0x1


#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_RED                         3:3
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_RED_End                       3
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_RED_Start                     3
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_RED_Type                    U01


#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_GREEN                       4:4
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_GREEN_End                     4
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_GREEN_Start                   4
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_GREEN_Type                  U01


#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_BLUE                        5:5
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_BLUE_End                      5
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_BLUE_Start                    5
#define MWV207REG_AHB_PATTERNS_MISMATCH_CHECKSUM_BLUE_Type                   U01




#define Region0StartRegAddrs                                              0x0B2D
#define REGION0_START_Address                                            0x02CB4
#define REGION0_START_MSB                                                     15
#define REGION0_START_LSB                                                      0
#define REGION0_START_BLK                                                      0
#define REGION0_START_Count                                                    1
#define REGION0_START_FieldMask                                       0xFFFFFFFF
#define REGION0_START_ReadMask                                        0xFFFFFFFF
#define REGION0_START_WriteMask                                       0xFFFFFFFF
#define REGION0_START_ResetValue                                      0x00000000

#define REGION0_START_ADDR                                                  31:0
#define REGION0_START_ADDR_End                                                31
#define REGION0_START_ADDR_Start                                               0
#define REGION0_START_ADDR_Type                                              U32




#define Region0EndRegAddrs                                                0x0B2E
#define REGION0_END_Address                                              0x02CB8
#define REGION0_END_MSB                                                       15
#define REGION0_END_LSB                                                        0
#define REGION0_END_BLK                                                        0
#define REGION0_END_Count                                                      1
#define REGION0_END_FieldMask                                         0xFFFFFFFF
#define REGION0_END_ReadMask                                          0xFFFFFFFF
#define REGION0_END_WriteMask                                         0xFFFFFFFF
#define REGION0_END_ResetValue                                        0x00000000

#define REGION0_END_ADDR                                                    31:0
#define REGION0_END_ADDR_End                                                  31
#define REGION0_END_ADDR_Start                                                 0
#define REGION0_END_ADDR_Type                                                U32



#define Region01stAccViolRegAddrs                                         0x0B2F
#define REGION01ST_ACC_VIOL_Address                                      0x02CBC
#define REGION01ST_ACC_VIOL_MSB                                               15
#define REGION01ST_ACC_VIOL_LSB                                                0
#define REGION01ST_ACC_VIOL_BLK                                                0
#define REGION01ST_ACC_VIOL_Count                                              1
#define REGION01ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION01ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION01ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION01ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION01ST_ACC_VIOL_ADDR                                            31:0
#define REGION01ST_ACC_VIOL_ADDR_End                                          31
#define REGION01ST_ACC_VIOL_ADDR_Start                                         0
#define REGION01ST_ACC_VIOL_ADDR_Type                                        U32

#define Region0MiscRegAddrs                                               0x0B30
#define REGION0_MISC_Address                                             0x02CC0
#define REGION0_MISC_MSB                                                      15
#define REGION0_MISC_LSB                                                       0
#define REGION0_MISC_BLK                                                       0
#define REGION0_MISC_Count                                                     1
#define REGION0_MISC_FieldMask                                        0x000000FF
#define REGION0_MISC_ReadMask                                         0x000000FF
#define REGION0_MISC_WriteMask                                        0x000000FF
#define REGION0_MISC_ResetValue                                       0x00000000


#define REGION0_MISC_XDMA_RD_ACC                                             0:0
#define REGION0_MISC_XDMA_RD_ACC_End                                           0
#define REGION0_MISC_XDMA_RD_ACC_Start                                         0
#define REGION0_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION0_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION0_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION0_MISC_XDMA_WR_ACC                                             1:1
#define REGION0_MISC_XDMA_WR_ACC_End                                           1
#define REGION0_MISC_XDMA_WR_ACC_Start                                         1
#define REGION0_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION0_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION0_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION0_MISC_VIP_RD_ACC                                              2:2
#define REGION0_MISC_VIP_RD_ACC_End                                            2
#define REGION0_MISC_VIP_RD_ACC_Start                                          2
#define REGION0_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION0_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION0_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION0_MISC_VIP_WR_ACC                                              3:3
#define REGION0_MISC_VIP_WR_ACC_End                                            3
#define REGION0_MISC_VIP_WR_ACC_Start                                          3
#define REGION0_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION0_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION0_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION0_MISC_ISP_RD_ACC                                              4:4
#define REGION0_MISC_ISP_RD_ACC_End                                            4
#define REGION0_MISC_ISP_RD_ACC_Start                                          4
#define REGION0_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION0_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION0_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION0_MISC_ISP_WR_ACC                                              5:5
#define REGION0_MISC_ISP_WR_ACC_End                                            5
#define REGION0_MISC_ISP_WR_ACC_Start                                          5
#define REGION0_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION0_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION0_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION0_MISC_CPU_RD_ACC                                              6:6
#define REGION0_MISC_CPU_RD_ACC_End                                            6
#define REGION0_MISC_CPU_RD_ACC_Start                                          6
#define REGION0_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION0_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION0_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION0_MISC_CPU_WR_ACC                                              7:7
#define REGION0_MISC_CPU_WR_ACC_End                                            7
#define REGION0_MISC_CPU_WR_ACC_Start                                          7
#define REGION0_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION0_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION0_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region1StartRegAddrs                                              0x0B31
#define REGION1_START_Address                                            0x02CC4
#define REGION1_START_MSB                                                     15
#define REGION1_START_LSB                                                      0
#define REGION1_START_BLK                                                      0
#define REGION1_START_Count                                                    1
#define REGION1_START_FieldMask                                       0xFFFFFFFF
#define REGION1_START_ReadMask                                        0xFFFFFFFF
#define REGION1_START_WriteMask                                       0xFFFFFFFF
#define REGION1_START_ResetValue                                      0x00000000

#define REGION1_START_ADDR                                                  31:0
#define REGION1_START_ADDR_End                                                31
#define REGION1_START_ADDR_Start                                               0
#define REGION1_START_ADDR_Type                                              U32




#define Region1EndRegAddrs                                                0x0B32
#define REGION1_END_Address                                              0x02CC8
#define REGION1_END_MSB                                                       15
#define REGION1_END_LSB                                                        0
#define REGION1_END_BLK                                                        0
#define REGION1_END_Count                                                      1
#define REGION1_END_FieldMask                                         0xFFFFFFFF
#define REGION1_END_ReadMask                                          0xFFFFFFFF
#define REGION1_END_WriteMask                                         0xFFFFFFFF
#define REGION1_END_ResetValue                                        0x00000000

#define REGION1_END_ADDR                                                    31:0
#define REGION1_END_ADDR_End                                                  31
#define REGION1_END_ADDR_Start                                                 0
#define REGION1_END_ADDR_Type                                                U32



#define Region11stAccViolRegAddrs                                         0x0B33
#define REGION11ST_ACC_VIOL_Address                                      0x02CCC
#define REGION11ST_ACC_VIOL_MSB                                               15
#define REGION11ST_ACC_VIOL_LSB                                                0
#define REGION11ST_ACC_VIOL_BLK                                                0
#define REGION11ST_ACC_VIOL_Count                                              1
#define REGION11ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION11ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION11ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION11ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION11ST_ACC_VIOL_ADDR                                            31:0
#define REGION11ST_ACC_VIOL_ADDR_End                                          31
#define REGION11ST_ACC_VIOL_ADDR_Start                                         0
#define REGION11ST_ACC_VIOL_ADDR_Type                                        U32

#define Region1MiscRegAddrs                                               0x0B34
#define REGION1_MISC_Address                                             0x02CD0
#define REGION1_MISC_MSB                                                      15
#define REGION1_MISC_LSB                                                       0
#define REGION1_MISC_BLK                                                       0
#define REGION1_MISC_Count                                                     1
#define REGION1_MISC_FieldMask                                        0x000000FF
#define REGION1_MISC_ReadMask                                         0x000000FF
#define REGION1_MISC_WriteMask                                        0x000000FF
#define REGION1_MISC_ResetValue                                       0x00000000


#define REGION1_MISC_XDMA_RD_ACC                                             0:0
#define REGION1_MISC_XDMA_RD_ACC_End                                           0
#define REGION1_MISC_XDMA_RD_ACC_Start                                         0
#define REGION1_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION1_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION1_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION1_MISC_XDMA_WR_ACC                                             1:1
#define REGION1_MISC_XDMA_WR_ACC_End                                           1
#define REGION1_MISC_XDMA_WR_ACC_Start                                         1
#define REGION1_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION1_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION1_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION1_MISC_VIP_RD_ACC                                              2:2
#define REGION1_MISC_VIP_RD_ACC_End                                            2
#define REGION1_MISC_VIP_RD_ACC_Start                                          2
#define REGION1_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION1_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION1_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION1_MISC_VIP_WR_ACC                                              3:3
#define REGION1_MISC_VIP_WR_ACC_End                                            3
#define REGION1_MISC_VIP_WR_ACC_Start                                          3
#define REGION1_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION1_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION1_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION1_MISC_ISP_RD_ACC                                              4:4
#define REGION1_MISC_ISP_RD_ACC_End                                            4
#define REGION1_MISC_ISP_RD_ACC_Start                                          4
#define REGION1_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION1_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION1_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION1_MISC_ISP_WR_ACC                                              5:5
#define REGION1_MISC_ISP_WR_ACC_End                                            5
#define REGION1_MISC_ISP_WR_ACC_Start                                          5
#define REGION1_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION1_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION1_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION1_MISC_CPU_RD_ACC                                              6:6
#define REGION1_MISC_CPU_RD_ACC_End                                            6
#define REGION1_MISC_CPU_RD_ACC_Start                                          6
#define REGION1_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION1_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION1_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION1_MISC_CPU_WR_ACC                                              7:7
#define REGION1_MISC_CPU_WR_ACC_End                                            7
#define REGION1_MISC_CPU_WR_ACC_Start                                          7
#define REGION1_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION1_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION1_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region2StartRegAddrs                                              0x0B35
#define REGION2_START_Address                                            0x02CD4
#define REGION2_START_MSB                                                     15
#define REGION2_START_LSB                                                      0
#define REGION2_START_BLK                                                      0
#define REGION2_START_Count                                                    1
#define REGION2_START_FieldMask                                       0xFFFFFFFF
#define REGION2_START_ReadMask                                        0xFFFFFFFF
#define REGION2_START_WriteMask                                       0xFFFFFFFF
#define REGION2_START_ResetValue                                      0x00000000

#define REGION2_START_ADDR                                                  31:0
#define REGION2_START_ADDR_End                                                31
#define REGION2_START_ADDR_Start                                               0
#define REGION2_START_ADDR_Type                                              U32




#define Region2EndRegAddrs                                                0x0B36
#define REGION2_END_Address                                              0x02CD8
#define REGION2_END_MSB                                                       15
#define REGION2_END_LSB                                                        0
#define REGION2_END_BLK                                                        0
#define REGION2_END_Count                                                      1
#define REGION2_END_FieldMask                                         0xFFFFFFFF
#define REGION2_END_ReadMask                                          0xFFFFFFFF
#define REGION2_END_WriteMask                                         0xFFFFFFFF
#define REGION2_END_ResetValue                                        0x00000000

#define REGION2_END_ADDR                                                    31:0
#define REGION2_END_ADDR_End                                                  31
#define REGION2_END_ADDR_Start                                                 0
#define REGION2_END_ADDR_Type                                                U32



#define Region21stAccViolRegAddrs                                         0x0B37
#define REGION21ST_ACC_VIOL_Address                                      0x02CDC
#define REGION21ST_ACC_VIOL_MSB                                               15
#define REGION21ST_ACC_VIOL_LSB                                                0
#define REGION21ST_ACC_VIOL_BLK                                                0
#define REGION21ST_ACC_VIOL_Count                                              1
#define REGION21ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION21ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION21ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION21ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION21ST_ACC_VIOL_ADDR                                            31:0
#define REGION21ST_ACC_VIOL_ADDR_End                                          31
#define REGION21ST_ACC_VIOL_ADDR_Start                                         0
#define REGION21ST_ACC_VIOL_ADDR_Type                                        U32

#define Region2MiscRegAddrs                                               0x0B38
#define REGION2_MISC_Address                                             0x02CE0
#define REGION2_MISC_MSB                                                      15
#define REGION2_MISC_LSB                                                       0
#define REGION2_MISC_BLK                                                       0
#define REGION2_MISC_Count                                                     1
#define REGION2_MISC_FieldMask                                        0x000000FF
#define REGION2_MISC_ReadMask                                         0x000000FF
#define REGION2_MISC_WriteMask                                        0x000000FF
#define REGION2_MISC_ResetValue                                       0x00000000


#define REGION2_MISC_XDMA_RD_ACC                                             0:0
#define REGION2_MISC_XDMA_RD_ACC_End                                           0
#define REGION2_MISC_XDMA_RD_ACC_Start                                         0
#define REGION2_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION2_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION2_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION2_MISC_XDMA_WR_ACC                                             1:1
#define REGION2_MISC_XDMA_WR_ACC_End                                           1
#define REGION2_MISC_XDMA_WR_ACC_Start                                         1
#define REGION2_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION2_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION2_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION2_MISC_VIP_RD_ACC                                              2:2
#define REGION2_MISC_VIP_RD_ACC_End                                            2
#define REGION2_MISC_VIP_RD_ACC_Start                                          2
#define REGION2_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION2_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION2_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION2_MISC_VIP_WR_ACC                                              3:3
#define REGION2_MISC_VIP_WR_ACC_End                                            3
#define REGION2_MISC_VIP_WR_ACC_Start                                          3
#define REGION2_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION2_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION2_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION2_MISC_ISP_RD_ACC                                              4:4
#define REGION2_MISC_ISP_RD_ACC_End                                            4
#define REGION2_MISC_ISP_RD_ACC_Start                                          4
#define REGION2_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION2_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION2_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION2_MISC_ISP_WR_ACC                                              5:5
#define REGION2_MISC_ISP_WR_ACC_End                                            5
#define REGION2_MISC_ISP_WR_ACC_Start                                          5
#define REGION2_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION2_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION2_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION2_MISC_CPU_RD_ACC                                              6:6
#define REGION2_MISC_CPU_RD_ACC_End                                            6
#define REGION2_MISC_CPU_RD_ACC_Start                                          6
#define REGION2_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION2_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION2_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION2_MISC_CPU_WR_ACC                                              7:7
#define REGION2_MISC_CPU_WR_ACC_End                                            7
#define REGION2_MISC_CPU_WR_ACC_Start                                          7
#define REGION2_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION2_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION2_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region3StartRegAddrs                                              0x0B39
#define REGION3_START_Address                                            0x02CE4
#define REGION3_START_MSB                                                     15
#define REGION3_START_LSB                                                      0
#define REGION3_START_BLK                                                      0
#define REGION3_START_Count                                                    1
#define REGION3_START_FieldMask                                       0xFFFFFFFF
#define REGION3_START_ReadMask                                        0xFFFFFFFF
#define REGION3_START_WriteMask                                       0xFFFFFFFF
#define REGION3_START_ResetValue                                      0x00000000

#define REGION3_START_ADDR                                                  31:0
#define REGION3_START_ADDR_End                                                31
#define REGION3_START_ADDR_Start                                               0
#define REGION3_START_ADDR_Type                                              U32




#define Region3EndRegAddrs                                                0x0B3A
#define REGION3_END_Address                                              0x02CE8
#define REGION3_END_MSB                                                       15
#define REGION3_END_LSB                                                        0
#define REGION3_END_BLK                                                        0
#define REGION3_END_Count                                                      1
#define REGION3_END_FieldMask                                         0xFFFFFFFF
#define REGION3_END_ReadMask                                          0xFFFFFFFF
#define REGION3_END_WriteMask                                         0xFFFFFFFF
#define REGION3_END_ResetValue                                        0x00000000

#define REGION3_END_ADDR                                                    31:0
#define REGION3_END_ADDR_End                                                  31
#define REGION3_END_ADDR_Start                                                 0
#define REGION3_END_ADDR_Type                                                U32



#define Region31stAccViolRegAddrs                                         0x0B3B
#define REGION31ST_ACC_VIOL_Address                                      0x02CEC
#define REGION31ST_ACC_VIOL_MSB                                               15
#define REGION31ST_ACC_VIOL_LSB                                                0
#define REGION31ST_ACC_VIOL_BLK                                                0
#define REGION31ST_ACC_VIOL_Count                                              1
#define REGION31ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION31ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION31ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION31ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION31ST_ACC_VIOL_ADDR                                            31:0
#define REGION31ST_ACC_VIOL_ADDR_End                                          31
#define REGION31ST_ACC_VIOL_ADDR_Start                                         0
#define REGION31ST_ACC_VIOL_ADDR_Type                                        U32

#define Region3MiscRegAddrs                                               0x0B3C
#define REGION3_MISC_Address                                             0x02CF0
#define REGION3_MISC_MSB                                                      15
#define REGION3_MISC_LSB                                                       0
#define REGION3_MISC_BLK                                                       0
#define REGION3_MISC_Count                                                     1
#define REGION3_MISC_FieldMask                                        0x000000FF
#define REGION3_MISC_ReadMask                                         0x000000FF
#define REGION3_MISC_WriteMask                                        0x000000FF
#define REGION3_MISC_ResetValue                                       0x00000000


#define REGION3_MISC_XDMA_RD_ACC                                             0:0
#define REGION3_MISC_XDMA_RD_ACC_End                                           0
#define REGION3_MISC_XDMA_RD_ACC_Start                                         0
#define REGION3_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION3_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION3_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION3_MISC_XDMA_WR_ACC                                             1:1
#define REGION3_MISC_XDMA_WR_ACC_End                                           1
#define REGION3_MISC_XDMA_WR_ACC_Start                                         1
#define REGION3_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION3_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION3_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION3_MISC_VIP_RD_ACC                                              2:2
#define REGION3_MISC_VIP_RD_ACC_End                                            2
#define REGION3_MISC_VIP_RD_ACC_Start                                          2
#define REGION3_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION3_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION3_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION3_MISC_VIP_WR_ACC                                              3:3
#define REGION3_MISC_VIP_WR_ACC_End                                            3
#define REGION3_MISC_VIP_WR_ACC_Start                                          3
#define REGION3_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION3_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION3_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION3_MISC_ISP_RD_ACC                                              4:4
#define REGION3_MISC_ISP_RD_ACC_End                                            4
#define REGION3_MISC_ISP_RD_ACC_Start                                          4
#define REGION3_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION3_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION3_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION3_MISC_ISP_WR_ACC                                              5:5
#define REGION3_MISC_ISP_WR_ACC_End                                            5
#define REGION3_MISC_ISP_WR_ACC_Start                                          5
#define REGION3_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION3_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION3_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION3_MISC_CPU_RD_ACC                                              6:6
#define REGION3_MISC_CPU_RD_ACC_End                                            6
#define REGION3_MISC_CPU_RD_ACC_Start                                          6
#define REGION3_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION3_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION3_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION3_MISC_CPU_WR_ACC                                              7:7
#define REGION3_MISC_CPU_WR_ACC_End                                            7
#define REGION3_MISC_CPU_WR_ACC_Start                                          7
#define REGION3_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION3_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION3_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region4StartRegAddrs                                              0x0B3D
#define REGION4_START_Address                                            0x02CF4
#define REGION4_START_MSB                                                     15
#define REGION4_START_LSB                                                      0
#define REGION4_START_BLK                                                      0
#define REGION4_START_Count                                                    1
#define REGION4_START_FieldMask                                       0xFFFFFFFF
#define REGION4_START_ReadMask                                        0xFFFFFFFF
#define REGION4_START_WriteMask                                       0xFFFFFFFF
#define REGION4_START_ResetValue                                      0x00000000

#define REGION4_START_ADDR                                                  31:0
#define REGION4_START_ADDR_End                                                31
#define REGION4_START_ADDR_Start                                               0
#define REGION4_START_ADDR_Type                                              U32




#define Region4EndRegAddrs                                                0x0B3E
#define REGION4_END_Address                                              0x02CF8
#define REGION4_END_MSB                                                       15
#define REGION4_END_LSB                                                        0
#define REGION4_END_BLK                                                        0
#define REGION4_END_Count                                                      1
#define REGION4_END_FieldMask                                         0xFFFFFFFF
#define REGION4_END_ReadMask                                          0xFFFFFFFF
#define REGION4_END_WriteMask                                         0xFFFFFFFF
#define REGION4_END_ResetValue                                        0x00000000

#define REGION4_END_ADDR                                                    31:0
#define REGION4_END_ADDR_End                                                  31
#define REGION4_END_ADDR_Start                                                 0
#define REGION4_END_ADDR_Type                                                U32



#define Region41stAccViolRegAddrs                                         0x0B3F
#define REGION41ST_ACC_VIOL_Address                                      0x02CFC
#define REGION41ST_ACC_VIOL_MSB                                               15
#define REGION41ST_ACC_VIOL_LSB                                                0
#define REGION41ST_ACC_VIOL_BLK                                                0
#define REGION41ST_ACC_VIOL_Count                                              1
#define REGION41ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION41ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION41ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION41ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION41ST_ACC_VIOL_ADDR                                            31:0
#define REGION41ST_ACC_VIOL_ADDR_End                                          31
#define REGION41ST_ACC_VIOL_ADDR_Start                                         0
#define REGION41ST_ACC_VIOL_ADDR_Type                                        U32

#define Region4MiscRegAddrs                                               0x0B40
#define REGION4_MISC_Address                                             0x02D00
#define REGION4_MISC_MSB                                                      15
#define REGION4_MISC_LSB                                                       0
#define REGION4_MISC_BLK                                                       0
#define REGION4_MISC_Count                                                     1
#define REGION4_MISC_FieldMask                                        0x000000FF
#define REGION4_MISC_ReadMask                                         0x000000FF
#define REGION4_MISC_WriteMask                                        0x000000FF
#define REGION4_MISC_ResetValue                                       0x00000000


#define REGION4_MISC_XDMA_RD_ACC                                             0:0
#define REGION4_MISC_XDMA_RD_ACC_End                                           0
#define REGION4_MISC_XDMA_RD_ACC_Start                                         0
#define REGION4_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION4_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION4_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION4_MISC_XDMA_WR_ACC                                             1:1
#define REGION4_MISC_XDMA_WR_ACC_End                                           1
#define REGION4_MISC_XDMA_WR_ACC_Start                                         1
#define REGION4_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION4_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION4_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION4_MISC_VIP_RD_ACC                                              2:2
#define REGION4_MISC_VIP_RD_ACC_End                                            2
#define REGION4_MISC_VIP_RD_ACC_Start                                          2
#define REGION4_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION4_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION4_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION4_MISC_VIP_WR_ACC                                              3:3
#define REGION4_MISC_VIP_WR_ACC_End                                            3
#define REGION4_MISC_VIP_WR_ACC_Start                                          3
#define REGION4_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION4_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION4_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION4_MISC_ISP_RD_ACC                                              4:4
#define REGION4_MISC_ISP_RD_ACC_End                                            4
#define REGION4_MISC_ISP_RD_ACC_Start                                          4
#define REGION4_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION4_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION4_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION4_MISC_ISP_WR_ACC                                              5:5
#define REGION4_MISC_ISP_WR_ACC_End                                            5
#define REGION4_MISC_ISP_WR_ACC_Start                                          5
#define REGION4_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION4_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION4_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION4_MISC_CPU_RD_ACC                                              6:6
#define REGION4_MISC_CPU_RD_ACC_End                                            6
#define REGION4_MISC_CPU_RD_ACC_Start                                          6
#define REGION4_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION4_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION4_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION4_MISC_CPU_WR_ACC                                              7:7
#define REGION4_MISC_CPU_WR_ACC_End                                            7
#define REGION4_MISC_CPU_WR_ACC_Start                                          7
#define REGION4_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION4_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION4_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region5StartRegAddrs                                              0x0B41
#define REGION5_START_Address                                            0x02D04
#define REGION5_START_MSB                                                     15
#define REGION5_START_LSB                                                      0
#define REGION5_START_BLK                                                      0
#define REGION5_START_Count                                                    1
#define REGION5_START_FieldMask                                       0xFFFFFFFF
#define REGION5_START_ReadMask                                        0xFFFFFFFF
#define REGION5_START_WriteMask                                       0xFFFFFFFF
#define REGION5_START_ResetValue                                      0x00000000

#define REGION5_START_ADDR                                                  31:0
#define REGION5_START_ADDR_End                                                31
#define REGION5_START_ADDR_Start                                               0
#define REGION5_START_ADDR_Type                                              U32




#define Region5EndRegAddrs                                                0x0B42
#define REGION5_END_Address                                              0x02D08
#define REGION5_END_MSB                                                       15
#define REGION5_END_LSB                                                        0
#define REGION5_END_BLK                                                        0
#define REGION5_END_Count                                                      1
#define REGION5_END_FieldMask                                         0xFFFFFFFF
#define REGION5_END_ReadMask                                          0xFFFFFFFF
#define REGION5_END_WriteMask                                         0xFFFFFFFF
#define REGION5_END_ResetValue                                        0x00000000

#define REGION5_END_ADDR                                                    31:0
#define REGION5_END_ADDR_End                                                  31
#define REGION5_END_ADDR_Start                                                 0
#define REGION5_END_ADDR_Type                                                U32



#define Region51stAccViolRegAddrs                                         0x0B43
#define REGION51ST_ACC_VIOL_Address                                      0x02D0C
#define REGION51ST_ACC_VIOL_MSB                                               15
#define REGION51ST_ACC_VIOL_LSB                                                0
#define REGION51ST_ACC_VIOL_BLK                                                0
#define REGION51ST_ACC_VIOL_Count                                              1
#define REGION51ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION51ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION51ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION51ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION51ST_ACC_VIOL_ADDR                                            31:0
#define REGION51ST_ACC_VIOL_ADDR_End                                          31
#define REGION51ST_ACC_VIOL_ADDR_Start                                         0
#define REGION51ST_ACC_VIOL_ADDR_Type                                        U32

#define Region5MiscRegAddrs                                               0x0B44
#define REGION5_MISC_Address                                             0x02D10
#define REGION5_MISC_MSB                                                      15
#define REGION5_MISC_LSB                                                       0
#define REGION5_MISC_BLK                                                       0
#define REGION5_MISC_Count                                                     1
#define REGION5_MISC_FieldMask                                        0x000000FF
#define REGION5_MISC_ReadMask                                         0x000000FF
#define REGION5_MISC_WriteMask                                        0x000000FF
#define REGION5_MISC_ResetValue                                       0x00000000


#define REGION5_MISC_XDMA_RD_ACC                                             0:0
#define REGION5_MISC_XDMA_RD_ACC_End                                           0
#define REGION5_MISC_XDMA_RD_ACC_Start                                         0
#define REGION5_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION5_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION5_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION5_MISC_XDMA_WR_ACC                                             1:1
#define REGION5_MISC_XDMA_WR_ACC_End                                           1
#define REGION5_MISC_XDMA_WR_ACC_Start                                         1
#define REGION5_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION5_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION5_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION5_MISC_VIP_RD_ACC                                              2:2
#define REGION5_MISC_VIP_RD_ACC_End                                            2
#define REGION5_MISC_VIP_RD_ACC_Start                                          2
#define REGION5_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION5_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION5_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION5_MISC_VIP_WR_ACC                                              3:3
#define REGION5_MISC_VIP_WR_ACC_End                                            3
#define REGION5_MISC_VIP_WR_ACC_Start                                          3
#define REGION5_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION5_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION5_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION5_MISC_ISP_RD_ACC                                              4:4
#define REGION5_MISC_ISP_RD_ACC_End                                            4
#define REGION5_MISC_ISP_RD_ACC_Start                                          4
#define REGION5_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION5_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION5_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION5_MISC_ISP_WR_ACC                                              5:5
#define REGION5_MISC_ISP_WR_ACC_End                                            5
#define REGION5_MISC_ISP_WR_ACC_Start                                          5
#define REGION5_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION5_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION5_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION5_MISC_CPU_RD_ACC                                              6:6
#define REGION5_MISC_CPU_RD_ACC_End                                            6
#define REGION5_MISC_CPU_RD_ACC_Start                                          6
#define REGION5_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION5_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION5_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION5_MISC_CPU_WR_ACC                                              7:7
#define REGION5_MISC_CPU_WR_ACC_End                                            7
#define REGION5_MISC_CPU_WR_ACC_Start                                          7
#define REGION5_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION5_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION5_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region6StartRegAddrs                                              0x0B45
#define REGION6_START_Address                                            0x02D14
#define REGION6_START_MSB                                                     15
#define REGION6_START_LSB                                                      0
#define REGION6_START_BLK                                                      0
#define REGION6_START_Count                                                    1
#define REGION6_START_FieldMask                                       0xFFFFFFFF
#define REGION6_START_ReadMask                                        0xFFFFFFFF
#define REGION6_START_WriteMask                                       0xFFFFFFFF
#define REGION6_START_ResetValue                                      0x00000000

#define REGION6_START_ADDR                                                  31:0
#define REGION6_START_ADDR_End                                                31
#define REGION6_START_ADDR_Start                                               0
#define REGION6_START_ADDR_Type                                              U32




#define Region6EndRegAddrs                                                0x0B46
#define REGION6_END_Address                                              0x02D18
#define REGION6_END_MSB                                                       15
#define REGION6_END_LSB                                                        0
#define REGION6_END_BLK                                                        0
#define REGION6_END_Count                                                      1
#define REGION6_END_FieldMask                                         0xFFFFFFFF
#define REGION6_END_ReadMask                                          0xFFFFFFFF
#define REGION6_END_WriteMask                                         0xFFFFFFFF
#define REGION6_END_ResetValue                                        0x00000000

#define REGION6_END_ADDR                                                    31:0
#define REGION6_END_ADDR_End                                                  31
#define REGION6_END_ADDR_Start                                                 0
#define REGION6_END_ADDR_Type                                                U32



#define Region61stAccViolRegAddrs                                         0x0B47
#define REGION61ST_ACC_VIOL_Address                                      0x02D1C
#define REGION61ST_ACC_VIOL_MSB                                               15
#define REGION61ST_ACC_VIOL_LSB                                                0
#define REGION61ST_ACC_VIOL_BLK                                                0
#define REGION61ST_ACC_VIOL_Count                                              1
#define REGION61ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION61ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION61ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION61ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION61ST_ACC_VIOL_ADDR                                            31:0
#define REGION61ST_ACC_VIOL_ADDR_End                                          31
#define REGION61ST_ACC_VIOL_ADDR_Start                                         0
#define REGION61ST_ACC_VIOL_ADDR_Type                                        U32

#define Region6MiscRegAddrs                                               0x0B48
#define REGION6_MISC_Address                                             0x02D20
#define REGION6_MISC_MSB                                                      15
#define REGION6_MISC_LSB                                                       0
#define REGION6_MISC_BLK                                                       0
#define REGION6_MISC_Count                                                     1
#define REGION6_MISC_FieldMask                                        0x000000FF
#define REGION6_MISC_ReadMask                                         0x000000FF
#define REGION6_MISC_WriteMask                                        0x000000FF
#define REGION6_MISC_ResetValue                                       0x00000000


#define REGION6_MISC_XDMA_RD_ACC                                             0:0
#define REGION6_MISC_XDMA_RD_ACC_End                                           0
#define REGION6_MISC_XDMA_RD_ACC_Start                                         0
#define REGION6_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION6_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION6_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION6_MISC_XDMA_WR_ACC                                             1:1
#define REGION6_MISC_XDMA_WR_ACC_End                                           1
#define REGION6_MISC_XDMA_WR_ACC_Start                                         1
#define REGION6_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION6_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION6_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION6_MISC_VIP_RD_ACC                                              2:2
#define REGION6_MISC_VIP_RD_ACC_End                                            2
#define REGION6_MISC_VIP_RD_ACC_Start                                          2
#define REGION6_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION6_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION6_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION6_MISC_VIP_WR_ACC                                              3:3
#define REGION6_MISC_VIP_WR_ACC_End                                            3
#define REGION6_MISC_VIP_WR_ACC_Start                                          3
#define REGION6_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION6_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION6_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION6_MISC_ISP_RD_ACC                                              4:4
#define REGION6_MISC_ISP_RD_ACC_End                                            4
#define REGION6_MISC_ISP_RD_ACC_Start                                          4
#define REGION6_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION6_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION6_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION6_MISC_ISP_WR_ACC                                              5:5
#define REGION6_MISC_ISP_WR_ACC_End                                            5
#define REGION6_MISC_ISP_WR_ACC_Start                                          5
#define REGION6_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION6_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION6_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION6_MISC_CPU_RD_ACC                                              6:6
#define REGION6_MISC_CPU_RD_ACC_End                                            6
#define REGION6_MISC_CPU_RD_ACC_Start                                          6
#define REGION6_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION6_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION6_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION6_MISC_CPU_WR_ACC                                              7:7
#define REGION6_MISC_CPU_WR_ACC_End                                            7
#define REGION6_MISC_CPU_WR_ACC_Start                                          7
#define REGION6_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION6_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION6_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region7StartRegAddrs                                              0x0B49
#define REGION7_START_Address                                            0x02D24
#define REGION7_START_MSB                                                     15
#define REGION7_START_LSB                                                      0
#define REGION7_START_BLK                                                      0
#define REGION7_START_Count                                                    1
#define REGION7_START_FieldMask                                       0xFFFFFFFF
#define REGION7_START_ReadMask                                        0xFFFFFFFF
#define REGION7_START_WriteMask                                       0xFFFFFFFF
#define REGION7_START_ResetValue                                      0x00000000

#define REGION7_START_ADDR                                                  31:0
#define REGION7_START_ADDR_End                                                31
#define REGION7_START_ADDR_Start                                               0
#define REGION7_START_ADDR_Type                                              U32




#define Region7EndRegAddrs                                                0x0B4A
#define REGION7_END_Address                                              0x02D28
#define REGION7_END_MSB                                                       15
#define REGION7_END_LSB                                                        0
#define REGION7_END_BLK                                                        0
#define REGION7_END_Count                                                      1
#define REGION7_END_FieldMask                                         0xFFFFFFFF
#define REGION7_END_ReadMask                                          0xFFFFFFFF
#define REGION7_END_WriteMask                                         0xFFFFFFFF
#define REGION7_END_ResetValue                                        0x00000000

#define REGION7_END_ADDR                                                    31:0
#define REGION7_END_ADDR_End                                                  31
#define REGION7_END_ADDR_Start                                                 0
#define REGION7_END_ADDR_Type                                                U32



#define Region71stAccViolRegAddrs                                         0x0B4B
#define REGION71ST_ACC_VIOL_Address                                      0x02D2C
#define REGION71ST_ACC_VIOL_MSB                                               15
#define REGION71ST_ACC_VIOL_LSB                                                0
#define REGION71ST_ACC_VIOL_BLK                                                0
#define REGION71ST_ACC_VIOL_Count                                              1
#define REGION71ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION71ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION71ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION71ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION71ST_ACC_VIOL_ADDR                                            31:0
#define REGION71ST_ACC_VIOL_ADDR_End                                          31
#define REGION71ST_ACC_VIOL_ADDR_Start                                         0
#define REGION71ST_ACC_VIOL_ADDR_Type                                        U32

#define Region7MiscRegAddrs                                               0x0B4C
#define REGION7_MISC_Address                                             0x02D30
#define REGION7_MISC_MSB                                                      15
#define REGION7_MISC_LSB                                                       0
#define REGION7_MISC_BLK                                                       0
#define REGION7_MISC_Count                                                     1
#define REGION7_MISC_FieldMask                                        0x000000FF
#define REGION7_MISC_ReadMask                                         0x000000FF
#define REGION7_MISC_WriteMask                                        0x000000FF
#define REGION7_MISC_ResetValue                                       0x00000000


#define REGION7_MISC_XDMA_RD_ACC                                             0:0
#define REGION7_MISC_XDMA_RD_ACC_End                                           0
#define REGION7_MISC_XDMA_RD_ACC_Start                                         0
#define REGION7_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION7_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION7_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION7_MISC_XDMA_WR_ACC                                             1:1
#define REGION7_MISC_XDMA_WR_ACC_End                                           1
#define REGION7_MISC_XDMA_WR_ACC_Start                                         1
#define REGION7_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION7_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION7_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION7_MISC_VIP_RD_ACC                                              2:2
#define REGION7_MISC_VIP_RD_ACC_End                                            2
#define REGION7_MISC_VIP_RD_ACC_Start                                          2
#define REGION7_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION7_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION7_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION7_MISC_VIP_WR_ACC                                              3:3
#define REGION7_MISC_VIP_WR_ACC_End                                            3
#define REGION7_MISC_VIP_WR_ACC_Start                                          3
#define REGION7_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION7_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION7_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION7_MISC_ISP_RD_ACC                                              4:4
#define REGION7_MISC_ISP_RD_ACC_End                                            4
#define REGION7_MISC_ISP_RD_ACC_Start                                          4
#define REGION7_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION7_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION7_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION7_MISC_ISP_WR_ACC                                              5:5
#define REGION7_MISC_ISP_WR_ACC_End                                            5
#define REGION7_MISC_ISP_WR_ACC_Start                                          5
#define REGION7_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION7_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION7_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION7_MISC_CPU_RD_ACC                                              6:6
#define REGION7_MISC_CPU_RD_ACC_End                                            6
#define REGION7_MISC_CPU_RD_ACC_Start                                          6
#define REGION7_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION7_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION7_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION7_MISC_CPU_WR_ACC                                              7:7
#define REGION7_MISC_CPU_WR_ACC_End                                            7
#define REGION7_MISC_CPU_WR_ACC_Start                                          7
#define REGION7_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION7_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION7_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define Region8StartRegAddrs                                              0x0B4D
#define REGION8_START_Address                                            0x02D34
#define REGION8_START_MSB                                                     15
#define REGION8_START_LSB                                                      0
#define REGION8_START_BLK                                                      0
#define REGION8_START_Count                                                    1
#define REGION8_START_FieldMask                                       0xFFFFFFFF
#define REGION8_START_ReadMask                                        0xFFFFFFFF
#define REGION8_START_WriteMask                                       0xFFFFFFFF
#define REGION8_START_ResetValue                                      0x00000000

#define REGION8_START_ADDR                                                  31:0
#define REGION8_START_ADDR_End                                                31
#define REGION8_START_ADDR_Start                                               0
#define REGION8_START_ADDR_Type                                              U32




#define Region8EndRegAddrs                                                0x0B4E
#define REGION8_END_Address                                              0x02D38
#define REGION8_END_MSB                                                       15
#define REGION8_END_LSB                                                        0
#define REGION8_END_BLK                                                        0
#define REGION8_END_Count                                                      1
#define REGION8_END_FieldMask                                         0xFFFFFFFF
#define REGION8_END_ReadMask                                          0xFFFFFFFF
#define REGION8_END_WriteMask                                         0xFFFFFFFF
#define REGION8_END_ResetValue                                        0x00000000

#define REGION8_END_ADDR                                                    31:0
#define REGION8_END_ADDR_End                                                  31
#define REGION8_END_ADDR_Start                                                 0
#define REGION8_END_ADDR_Type                                                U32



#define Region81stAccViolRegAddrs                                         0x0B4F
#define REGION81ST_ACC_VIOL_Address                                      0x02D3C
#define REGION81ST_ACC_VIOL_MSB                                               15
#define REGION81ST_ACC_VIOL_LSB                                                0
#define REGION81ST_ACC_VIOL_BLK                                                0
#define REGION81ST_ACC_VIOL_Count                                              1
#define REGION81ST_ACC_VIOL_FieldMask                                 0xFFFFFFFF
#define REGION81ST_ACC_VIOL_ReadMask                                  0xFFFFFFFF
#define REGION81ST_ACC_VIOL_WriteMask                                 0xFFFFFFFF
#define REGION81ST_ACC_VIOL_ResetValue                                0xFFFFFFFF

#define REGION81ST_ACC_VIOL_ADDR                                            31:0
#define REGION81ST_ACC_VIOL_ADDR_End                                          31
#define REGION81ST_ACC_VIOL_ADDR_Start                                         0
#define REGION81ST_ACC_VIOL_ADDR_Type                                        U32

#define Region8MiscRegAddrs                                               0x0B50
#define REGION8_MISC_Address                                             0x02D40
#define REGION8_MISC_MSB                                                      15
#define REGION8_MISC_LSB                                                       0
#define REGION8_MISC_BLK                                                       0
#define REGION8_MISC_Count                                                     1
#define REGION8_MISC_FieldMask                                        0x000000FF
#define REGION8_MISC_ReadMask                                         0x000000FF
#define REGION8_MISC_WriteMask                                        0x000000FF
#define REGION8_MISC_ResetValue                                       0x00000000


#define REGION8_MISC_XDMA_RD_ACC                                             0:0
#define REGION8_MISC_XDMA_RD_ACC_End                                           0
#define REGION8_MISC_XDMA_RD_ACC_Start                                         0
#define REGION8_MISC_XDMA_RD_ACC_Type                                        U01
#define   REGION8_MISC_XDMA_RD_ACC_NOT_ALLOWED                               0x0
#define   REGION8_MISC_XDMA_RD_ACC_ALLOWED                                   0x1


#define REGION8_MISC_XDMA_WR_ACC                                             1:1
#define REGION8_MISC_XDMA_WR_ACC_End                                           1
#define REGION8_MISC_XDMA_WR_ACC_Start                                         1
#define REGION8_MISC_XDMA_WR_ACC_Type                                        U01
#define   REGION8_MISC_XDMA_WR_ACC_NOT_ALLOWED                               0x0
#define   REGION8_MISC_XDMA_WR_ACC_ALLOWED                                   0x1


#define REGION8_MISC_VIP_RD_ACC                                              2:2
#define REGION8_MISC_VIP_RD_ACC_End                                            2
#define REGION8_MISC_VIP_RD_ACC_Start                                          2
#define REGION8_MISC_VIP_RD_ACC_Type                                         U01
#define   REGION8_MISC_VIP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION8_MISC_VIP_RD_ACC_ALLOWED                                    0x1


#define REGION8_MISC_VIP_WR_ACC                                              3:3
#define REGION8_MISC_VIP_WR_ACC_End                                            3
#define REGION8_MISC_VIP_WR_ACC_Start                                          3
#define REGION8_MISC_VIP_WR_ACC_Type                                         U01
#define   REGION8_MISC_VIP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION8_MISC_VIP_WR_ACC_ALLOWED                                    0x1


#define REGION8_MISC_ISP_RD_ACC                                              4:4
#define REGION8_MISC_ISP_RD_ACC_End                                            4
#define REGION8_MISC_ISP_RD_ACC_Start                                          4
#define REGION8_MISC_ISP_RD_ACC_Type                                         U01
#define   REGION8_MISC_ISP_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION8_MISC_ISP_RD_ACC_ALLOWED                                    0x1


#define REGION8_MISC_ISP_WR_ACC                                              5:5
#define REGION8_MISC_ISP_WR_ACC_End                                            5
#define REGION8_MISC_ISP_WR_ACC_Start                                          5
#define REGION8_MISC_ISP_WR_ACC_Type                                         U01
#define   REGION8_MISC_ISP_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION8_MISC_ISP_WR_ACC_ALLOWED                                    0x1


#define REGION8_MISC_CPU_RD_ACC                                              6:6
#define REGION8_MISC_CPU_RD_ACC_End                                            6
#define REGION8_MISC_CPU_RD_ACC_Start                                          6
#define REGION8_MISC_CPU_RD_ACC_Type                                         U01
#define   REGION8_MISC_CPU_RD_ACC_NOT_ALLOWED                                0x0
#define   REGION8_MISC_CPU_RD_ACC_ALLOWED                                    0x1


#define REGION8_MISC_CPU_WR_ACC                                              7:7
#define REGION8_MISC_CPU_WR_ACC_End                                            7
#define REGION8_MISC_CPU_WR_ACC_Start                                          7
#define REGION8_MISC_CPU_WR_ACC_Type                                         U01
#define   REGION8_MISC_CPU_WR_ACC_NOT_ALLOWED                                0x0
#define   REGION8_MISC_CPU_WR_ACC_ALLOWED                                    0x1




#define mwv207regAHBXDMARawStatusRegAddrs                                 0x0B51
#define MWV207REG_AHBXDMA_RAW_STATUS_Address                             0x02D44
#define MWV207REG_AHBXDMA_RAW_STATUS_MSB                                      15
#define MWV207REG_AHBXDMA_RAW_STATUS_LSB                                       0
#define MWV207REG_AHBXDMA_RAW_STATUS_BLK                                       0
#define MWV207REG_AHBXDMA_RAW_STATUS_Count                                     1
#define MWV207REG_AHBXDMA_RAW_STATUS_FieldMask                        0x07FFFFFF
#define MWV207REG_AHBXDMA_RAW_STATUS_ReadMask                         0x07FFFFFF
#define MWV207REG_AHBXDMA_RAW_STATUS_WriteMask                        0x07FFFFFF
#define MWV207REG_AHBXDMA_RAW_STATUS_ResetValue                       0x00000000

#define MWV207REG_AHBXDMA_RAW_STATUS_COMP_FRAME_COMPL                        0:0
#define MWV207REG_AHBXDMA_RAW_STATUS_COMP_FRAME_COMPL_End                      0
#define MWV207REG_AHBXDMA_RAW_STATUS_COMP_FRAME_COMPL_Start                    0
#define MWV207REG_AHBXDMA_RAW_STATUS_COMP_FRAME_COMPL_Type                   U01

#define MWV207REG_AHBXDMA_RAW_STATUS_DE_COMP_FRAME_COMPL                     1:1
#define MWV207REG_AHBXDMA_RAW_STATUS_DE_COMP_FRAME_COMPL_End                   1
#define MWV207REG_AHBXDMA_RAW_STATUS_DE_COMP_FRAME_COMPL_Start                 1
#define MWV207REG_AHBXDMA_RAW_STATUS_DE_COMP_FRAME_COMPL_Type                U01

#define MWV207REG_AHBXDMA_RAW_STATUS_XIO_SYNC_ERROR_INTR                     2:2
#define MWV207REG_AHBXDMA_RAW_STATUS_XIO_SYNC_ERROR_INTR_End                   2
#define MWV207REG_AHBXDMA_RAW_STATUS_XIO_SYNC_ERROR_INTR_Start                 2
#define MWV207REG_AHBXDMA_RAW_STATUS_XIO_SYNC_ERROR_INTR_Type                U01


#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT            3:3
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_End          3
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_Start        3
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_Type       U01

#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT           4:4
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_End         4
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_Start       4
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_Type      U01

#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT            5:5
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT_End          5
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT_Start        5
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT_Type       U01

#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT           6:6
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_End         6
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_Start       6
#define MWV207REG_AHBXDMA_RAW_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_Type      U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_XDMA_ACC_VIOL                   7:7
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_XDMA_ACC_VIOL_End                 7
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_XDMA_ACC_VIOL_Start               7
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_XDMA_ACC_VIOL                   8:8
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_XDMA_ACC_VIOL_End                 8
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_XDMA_ACC_VIOL_Start               8
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_XDMA_ACC_VIOL                   9:9
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_XDMA_ACC_VIOL_End                 9
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_XDMA_ACC_VIOL_Start               9
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_XDMA_ACC_VIOL                 10:10
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_XDMA_ACC_VIOL_End                10
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_XDMA_ACC_VIOL_Start              10
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_XDMA_ACC_VIOL                 11:11
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_XDMA_ACC_VIOL_End                11
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_XDMA_ACC_VIOL_Start              11
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_XDMA_ACC_VIOL                 12:12
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_XDMA_ACC_VIOL_End                12
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_XDMA_ACC_VIOL_Start              12
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_XDMA_ACC_VIOL                 13:13
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_XDMA_ACC_VIOL_End                13
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_XDMA_ACC_VIOL_Start              13
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_XDMA_ACC_VIOL                 14:14
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_XDMA_ACC_VIOL_End                14
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_XDMA_ACC_VIOL_Start              14
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_XDMA_ACC_VIOL                 15:15
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_XDMA_ACC_VIOL_End                15
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_XDMA_ACC_VIOL_Start              15
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_XDMA_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_AXI_ACC_VIOL                  16:16
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_AXI_ACC_VIOL_End                 16
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_AXI_ACC_VIOL_Start               16
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION0_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_AXI_ACC_VIOL                  17:17
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_AXI_ACC_VIOL_End                 17
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_AXI_ACC_VIOL_Start               17
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION1_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_AXI_ACC_VIOL                  18:18
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_AXI_ACC_VIOL_End                 18
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_AXI_ACC_VIOL_Start               18
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION2_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_AXI_ACC_VIOL                  19:19
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_AXI_ACC_VIOL_End                 19
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_AXI_ACC_VIOL_Start               19
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION3_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_AXI_ACC_VIOL                  20:20
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_AXI_ACC_VIOL_End                 20
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_AXI_ACC_VIOL_Start               20
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION4_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_AXI_ACC_VIOL                  21:21
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_AXI_ACC_VIOL_End                 21
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_AXI_ACC_VIOL_Start               21
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION5_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_AXI_ACC_VIOL                  22:22
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_AXI_ACC_VIOL_End                 22
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_AXI_ACC_VIOL_Start               22
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION6_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_AXI_ACC_VIOL                  23:23
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_AXI_ACC_VIOL_End                 23
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_AXI_ACC_VIOL_Start               23
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION7_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_AXI_ACC_VIOL                  24:24
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_AXI_ACC_VIOL_End                 24
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_AXI_ACC_VIOL_Start               24
#define MWV207REG_AHBXDMA_RAW_STATUS_REGION8_AXI_ACC_VIOL_Type               U01

#define MWV207REG_AHBXDMA_RAW_STATUS_PSITOSBI_FRM_COMPL                    25:25
#define MWV207REG_AHBXDMA_RAW_STATUS_PSITOSBI_FRM_COMPL_End                   25
#define MWV207REG_AHBXDMA_RAW_STATUS_PSITOSBI_FRM_COMPL_Start                 25
#define MWV207REG_AHBXDMA_RAW_STATUS_PSITOSBI_FRM_COMPL_Type                 U01

#define MWV207REG_AHBXDMA_RAW_STATUS_SBITOPSI_FRM_COMPL                    26:26
#define MWV207REG_AHBXDMA_RAW_STATUS_SBITOPSI_FRM_COMPL_End                   26
#define MWV207REG_AHBXDMA_RAW_STATUS_SBITOPSI_FRM_COMPL_Start                 26
#define MWV207REG_AHBXDMA_RAW_STATUS_SBITOPSI_FRM_COMPL_Type                 U01

#define mwv207regAHBXDMARawStatus2RegAddrs                                0x0B52
#define MWV207REG_AHBXDMA_RAW_STATUS2_Address                            0x02D48
#define MWV207REG_AHBXDMA_RAW_STATUS2_MSB                                     15
#define MWV207REG_AHBXDMA_RAW_STATUS2_LSB                                      0
#define MWV207REG_AHBXDMA_RAW_STATUS2_BLK                                      0
#define MWV207REG_AHBXDMA_RAW_STATUS2_Count                                    1
#define MWV207REG_AHBXDMA_RAW_STATUS2_FieldMask                       0x0003FFFF
#define MWV207REG_AHBXDMA_RAW_STATUS2_ReadMask                        0x0003FFFF
#define MWV207REG_AHBXDMA_RAW_STATUS2_WriteMask                       0x0003FFFF
#define MWV207REG_AHBXDMA_RAW_STATUS2_ResetValue                      0x00000000

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_ISP_ACC_VIOL                   0:0
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_ISP_ACC_VIOL_End                 0
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_ISP_ACC_VIOL_Start               0
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_ISP_ACC_VIOL                   1:1
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_ISP_ACC_VIOL_End                 1
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_ISP_ACC_VIOL_Start               1
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_ISP_ACC_VIOL                   2:2
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_ISP_ACC_VIOL_End                 2
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_ISP_ACC_VIOL_Start               2
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_ISP_ACC_VIOL                   3:3
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_ISP_ACC_VIOL_End                 3
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_ISP_ACC_VIOL_Start               3
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_ISP_ACC_VIOL                   4:4
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_ISP_ACC_VIOL_End                 4
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_ISP_ACC_VIOL_Start               4
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_ISP_ACC_VIOL                   5:5
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_ISP_ACC_VIOL_End                 5
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_ISP_ACC_VIOL_Start               5
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_ISP_ACC_VIOL                   6:6
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_ISP_ACC_VIOL_End                 6
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_ISP_ACC_VIOL_Start               6
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_ISP_ACC_VIOL                   7:7
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_ISP_ACC_VIOL_End                 7
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_ISP_ACC_VIOL_Start               7
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_ISP_ACC_VIOL                   8:8
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_ISP_ACC_VIOL_End                 8
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_ISP_ACC_VIOL_Start               8
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_ISP_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_CPU_ACC_VIOL                   9:9
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_CPU_ACC_VIOL_End                 9
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_CPU_ACC_VIOL_Start               9
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION0_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_CPU_ACC_VIOL                 10:10
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_CPU_ACC_VIOL_End                10
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_CPU_ACC_VIOL_Start              10
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION1_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_CPU_ACC_VIOL                 11:11
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_CPU_ACC_VIOL_End                11
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_CPU_ACC_VIOL_Start              11
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION2_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_CPU_ACC_VIOL                 12:12
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_CPU_ACC_VIOL_End                12
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_CPU_ACC_VIOL_Start              12
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION3_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_CPU_ACC_VIOL                 13:13
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_CPU_ACC_VIOL_End                13
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_CPU_ACC_VIOL_Start              13
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION4_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_CPU_ACC_VIOL                 14:14
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_CPU_ACC_VIOL_End                14
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_CPU_ACC_VIOL_Start              14
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION5_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_CPU_ACC_VIOL                 15:15
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_CPU_ACC_VIOL_End                15
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_CPU_ACC_VIOL_Start              15
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION6_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_CPU_ACC_VIOL                 16:16
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_CPU_ACC_VIOL_End                16
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_CPU_ACC_VIOL_Start              16
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION7_CPU_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_CPU_ACC_VIOL                 17:17
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_CPU_ACC_VIOL_End                17
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_CPU_ACC_VIOL_Start              17
#define MWV207REG_AHBXDMA_RAW_STATUS2_REGION8_CPU_ACC_VIOL_Type              U01



#define mwv207regAHBXDMAIntrEnRegAddrs                                    0x0B53
#define MWV207REG_AHBXDMA_INTR_EN_Address                                0x02D4C
#define MWV207REG_AHBXDMA_INTR_EN_MSB                                         15
#define MWV207REG_AHBXDMA_INTR_EN_LSB                                          0
#define MWV207REG_AHBXDMA_INTR_EN_BLK                                          0
#define MWV207REG_AHBXDMA_INTR_EN_Count                                        1
#define MWV207REG_AHBXDMA_INTR_EN_FieldMask                           0x07FFFFFF
#define MWV207REG_AHBXDMA_INTR_EN_ReadMask                            0x07FFFFFF
#define MWV207REG_AHBXDMA_INTR_EN_WriteMask                           0x07FFFFFF
#define MWV207REG_AHBXDMA_INTR_EN_ResetValue                          0x00000000

#define MWV207REG_AHBXDMA_INTR_EN_COMP_FRAME_COMPL                           0:0
#define MWV207REG_AHBXDMA_INTR_EN_COMP_FRAME_COMPL_End                         0
#define MWV207REG_AHBXDMA_INTR_EN_COMP_FRAME_COMPL_Start                       0
#define MWV207REG_AHBXDMA_INTR_EN_COMP_FRAME_COMPL_Type                      U01

#define MWV207REG_AHBXDMA_INTR_EN_DE_COMP_FRAME_COMPL                        1:1
#define MWV207REG_AHBXDMA_INTR_EN_DE_COMP_FRAME_COMPL_End                      1
#define MWV207REG_AHBXDMA_INTR_EN_DE_COMP_FRAME_COMPL_Start                    1
#define MWV207REG_AHBXDMA_INTR_EN_DE_COMP_FRAME_COMPL_Type                   U01

#define MWV207REG_AHBXDMA_INTR_EN_SYNC_ERROR                                 2:2
#define MWV207REG_AHBXDMA_INTR_EN_SYNC_ERROR_End                               2
#define MWV207REG_AHBXDMA_INTR_EN_SYNC_ERROR_Start                             2
#define MWV207REG_AHBXDMA_INTR_EN_SYNC_ERROR_Type                            U01

#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PUREQ_TO_PUREQ_TIMEOUT               3:3
#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_End             3
#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_Start           3
#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_Type          U01

#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT              4:4
#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_End            4
#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_Start          4
#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_Type         U01

#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PRREQ_TO_PRACK_TIMEOUT               5:5
#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PRREQ_TO_PRACK_TIMEOUT_End             5
#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PRREQ_TO_PRACK_TIMEOUT_Start           5
#define MWV207REG_AHBXDMA_INTR_EN_SBIIN_PRREQ_TO_PRACK_TIMEOUT_Type          U01

#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CRREQ_TO_CRACK_TIMEOUT              6:6
#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_End            6
#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_Start          6
#define MWV207REG_AHBXDMA_INTR_EN_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_Type         U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION0_XDMA_ACC_VIOL                      7:7
#define MWV207REG_AHBXDMA_INTR_EN_REGION0_XDMA_ACC_VIOL_End                    7
#define MWV207REG_AHBXDMA_INTR_EN_REGION0_XDMA_ACC_VIOL_Start                  7
#define MWV207REG_AHBXDMA_INTR_EN_REGION0_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION1_XDMA_ACC_VIOL                      8:8
#define MWV207REG_AHBXDMA_INTR_EN_REGION1_XDMA_ACC_VIOL_End                    8
#define MWV207REG_AHBXDMA_INTR_EN_REGION1_XDMA_ACC_VIOL_Start                  8
#define MWV207REG_AHBXDMA_INTR_EN_REGION1_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION2_XDMA_ACC_VIOL                      9:9
#define MWV207REG_AHBXDMA_INTR_EN_REGION2_XDMA_ACC_VIOL_End                    9
#define MWV207REG_AHBXDMA_INTR_EN_REGION2_XDMA_ACC_VIOL_Start                  9
#define MWV207REG_AHBXDMA_INTR_EN_REGION2_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION3_XDMA_ACC_VIOL                    10:10
#define MWV207REG_AHBXDMA_INTR_EN_REGION3_XDMA_ACC_VIOL_End                   10
#define MWV207REG_AHBXDMA_INTR_EN_REGION3_XDMA_ACC_VIOL_Start                 10
#define MWV207REG_AHBXDMA_INTR_EN_REGION3_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION4_XDMA_ACC_VIOL                    11:11
#define MWV207REG_AHBXDMA_INTR_EN_REGION4_XDMA_ACC_VIOL_End                   11
#define MWV207REG_AHBXDMA_INTR_EN_REGION4_XDMA_ACC_VIOL_Start                 11
#define MWV207REG_AHBXDMA_INTR_EN_REGION4_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION5_XDMA_ACC_VIOL                    12:12
#define MWV207REG_AHBXDMA_INTR_EN_REGION5_XDMA_ACC_VIOL_End                   12
#define MWV207REG_AHBXDMA_INTR_EN_REGION5_XDMA_ACC_VIOL_Start                 12
#define MWV207REG_AHBXDMA_INTR_EN_REGION5_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION6_XDMA_ACC_VIOL                    13:13
#define MWV207REG_AHBXDMA_INTR_EN_REGION6_XDMA_ACC_VIOL_End                   13
#define MWV207REG_AHBXDMA_INTR_EN_REGION6_XDMA_ACC_VIOL_Start                 13
#define MWV207REG_AHBXDMA_INTR_EN_REGION6_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION7_XDMA_ACC_VIOL                    14:14
#define MWV207REG_AHBXDMA_INTR_EN_REGION7_XDMA_ACC_VIOL_End                   14
#define MWV207REG_AHBXDMA_INTR_EN_REGION7_XDMA_ACC_VIOL_Start                 14
#define MWV207REG_AHBXDMA_INTR_EN_REGION7_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION8_XDMA_ACC_VIOL                    15:15
#define MWV207REG_AHBXDMA_INTR_EN_REGION8_XDMA_ACC_VIOL_End                   15
#define MWV207REG_AHBXDMA_INTR_EN_REGION8_XDMA_ACC_VIOL_Start                 15
#define MWV207REG_AHBXDMA_INTR_EN_REGION8_XDMA_ACC_VIOL_Type                 U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION0_AXI_ACC_VIOL                     16:16
#define MWV207REG_AHBXDMA_INTR_EN_REGION0_AXI_ACC_VIOL_End                    16
#define MWV207REG_AHBXDMA_INTR_EN_REGION0_AXI_ACC_VIOL_Start                  16
#define MWV207REG_AHBXDMA_INTR_EN_REGION0_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION1_AXI_ACC_VIOL                     17:17
#define MWV207REG_AHBXDMA_INTR_EN_REGION1_AXI_ACC_VIOL_End                    17
#define MWV207REG_AHBXDMA_INTR_EN_REGION1_AXI_ACC_VIOL_Start                  17
#define MWV207REG_AHBXDMA_INTR_EN_REGION1_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION2_AXI_ACC_VIOL                     18:18
#define MWV207REG_AHBXDMA_INTR_EN_REGION2_AXI_ACC_VIOL_End                    18
#define MWV207REG_AHBXDMA_INTR_EN_REGION2_AXI_ACC_VIOL_Start                  18
#define MWV207REG_AHBXDMA_INTR_EN_REGION2_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION3_AXI_ACC_VIOL                     19:19
#define MWV207REG_AHBXDMA_INTR_EN_REGION3_AXI_ACC_VIOL_End                    19
#define MWV207REG_AHBXDMA_INTR_EN_REGION3_AXI_ACC_VIOL_Start                  19
#define MWV207REG_AHBXDMA_INTR_EN_REGION3_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION4_AXI_ACC_VIOL                     20:20
#define MWV207REG_AHBXDMA_INTR_EN_REGION4_AXI_ACC_VIOL_End                    20
#define MWV207REG_AHBXDMA_INTR_EN_REGION4_AXI_ACC_VIOL_Start                  20
#define MWV207REG_AHBXDMA_INTR_EN_REGION4_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION5_AXI_ACC_VIOL                     21:21
#define MWV207REG_AHBXDMA_INTR_EN_REGION5_AXI_ACC_VIOL_End                    21
#define MWV207REG_AHBXDMA_INTR_EN_REGION5_AXI_ACC_VIOL_Start                  21
#define MWV207REG_AHBXDMA_INTR_EN_REGION5_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION6_AXI_ACC_VIOL                     22:22
#define MWV207REG_AHBXDMA_INTR_EN_REGION6_AXI_ACC_VIOL_End                    22
#define MWV207REG_AHBXDMA_INTR_EN_REGION6_AXI_ACC_VIOL_Start                  22
#define MWV207REG_AHBXDMA_INTR_EN_REGION6_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION7_AXI_ACC_VIOL                     23:23
#define MWV207REG_AHBXDMA_INTR_EN_REGION7_AXI_ACC_VIOL_End                    23
#define MWV207REG_AHBXDMA_INTR_EN_REGION7_AXI_ACC_VIOL_Start                  23
#define MWV207REG_AHBXDMA_INTR_EN_REGION7_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_REGION8_AXI_ACC_VIOL                     24:24
#define MWV207REG_AHBXDMA_INTR_EN_REGION8_AXI_ACC_VIOL_End                    24
#define MWV207REG_AHBXDMA_INTR_EN_REGION8_AXI_ACC_VIOL_Start                  24
#define MWV207REG_AHBXDMA_INTR_EN_REGION8_AXI_ACC_VIOL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_EN_PSITOSBI_FRM_COMPL                       25:25
#define MWV207REG_AHBXDMA_INTR_EN_PSITOSBI_FRM_COMPL_End                      25
#define MWV207REG_AHBXDMA_INTR_EN_PSITOSBI_FRM_COMPL_Start                    25
#define MWV207REG_AHBXDMA_INTR_EN_PSITOSBI_FRM_COMPL_Type                    U01

#define MWV207REG_AHBXDMA_INTR_EN_SBITOPSI_FRM_COMPL                       26:26
#define MWV207REG_AHBXDMA_INTR_EN_SBITOPSI_FRM_COMPL_End                      26
#define MWV207REG_AHBXDMA_INTR_EN_SBITOPSI_FRM_COMPL_Start                    26
#define MWV207REG_AHBXDMA_INTR_EN_SBITOPSI_FRM_COMPL_Type                    U01

#define mwv207regAHBXDMAIntrEn2RegAddrs                                   0x0B54
#define MWV207REG_AHBXDMA_INTR_EN2_Address                               0x02D50
#define MWV207REG_AHBXDMA_INTR_EN2_MSB                                        15
#define MWV207REG_AHBXDMA_INTR_EN2_LSB                                         0
#define MWV207REG_AHBXDMA_INTR_EN2_BLK                                         0
#define MWV207REG_AHBXDMA_INTR_EN2_Count                                       1
#define MWV207REG_AHBXDMA_INTR_EN2_FieldMask                          0x0003FFFF
#define MWV207REG_AHBXDMA_INTR_EN2_ReadMask                           0x0003FFFF
#define MWV207REG_AHBXDMA_INTR_EN2_WriteMask                          0x0003FFFF
#define MWV207REG_AHBXDMA_INTR_EN2_ResetValue                         0x00000000


#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_ISP_ACC_VIOL                      0:0
#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_ISP_ACC_VIOL_End                    0
#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_ISP_ACC_VIOL_Start                  0
#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_ISP_ACC_VIOL                      1:1
#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_ISP_ACC_VIOL_End                    1
#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_ISP_ACC_VIOL_Start                  1
#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_ISP_ACC_VIOL                      2:2
#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_ISP_ACC_VIOL_End                    2
#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_ISP_ACC_VIOL_Start                  2
#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_ISP_ACC_VIOL                      3:3
#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_ISP_ACC_VIOL_End                    3
#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_ISP_ACC_VIOL_Start                  3
#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_ISP_ACC_VIOL                      4:4
#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_ISP_ACC_VIOL_End                    4
#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_ISP_ACC_VIOL_Start                  4
#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_ISP_ACC_VIOL                      5:5
#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_ISP_ACC_VIOL_End                    5
#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_ISP_ACC_VIOL_Start                  5
#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_ISP_ACC_VIOL                      6:6
#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_ISP_ACC_VIOL_End                    6
#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_ISP_ACC_VIOL_Start                  6
#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_ISP_ACC_VIOL                      7:7
#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_ISP_ACC_VIOL_End                    7
#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_ISP_ACC_VIOL_Start                  7
#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_ISP_ACC_VIOL                      8:8
#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_ISP_ACC_VIOL_End                    8
#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_ISP_ACC_VIOL_Start                  8
#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_ISP_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_CPU_ACC_VIOL                      9:9
#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_CPU_ACC_VIOL_End                    9
#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_CPU_ACC_VIOL_Start                  9
#define MWV207REG_AHBXDMA_INTR_EN2_REGION0_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_CPU_ACC_VIOL                    10:10
#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_CPU_ACC_VIOL_End                   10
#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_CPU_ACC_VIOL_Start                 10
#define MWV207REG_AHBXDMA_INTR_EN2_REGION1_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_CPU_ACC_VIOL                    11:11
#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_CPU_ACC_VIOL_End                   11
#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_CPU_ACC_VIOL_Start                 11
#define MWV207REG_AHBXDMA_INTR_EN2_REGION2_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_CPU_ACC_VIOL                    12:12
#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_CPU_ACC_VIOL_End                   12
#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_CPU_ACC_VIOL_Start                 12
#define MWV207REG_AHBXDMA_INTR_EN2_REGION3_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_CPU_ACC_VIOL                    13:13
#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_CPU_ACC_VIOL_End                   13
#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_CPU_ACC_VIOL_Start                 13
#define MWV207REG_AHBXDMA_INTR_EN2_REGION4_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_CPU_ACC_VIOL                    14:14
#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_CPU_ACC_VIOL_End                   14
#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_CPU_ACC_VIOL_Start                 14
#define MWV207REG_AHBXDMA_INTR_EN2_REGION5_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_CPU_ACC_VIOL                    15:15
#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_CPU_ACC_VIOL_End                   15
#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_CPU_ACC_VIOL_Start                 15
#define MWV207REG_AHBXDMA_INTR_EN2_REGION6_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_CPU_ACC_VIOL                    16:16
#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_CPU_ACC_VIOL_End                   16
#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_CPU_ACC_VIOL_Start                 16
#define MWV207REG_AHBXDMA_INTR_EN2_REGION7_CPU_ACC_VIOL_Type                 U01


#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_CPU_ACC_VIOL                    17:17
#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_CPU_ACC_VIOL_End                   17
#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_CPU_ACC_VIOL_Start                 17
#define MWV207REG_AHBXDMA_INTR_EN2_REGION8_CPU_ACC_VIOL_Type                 U01



#define mwv207regAHBXDMAIntrStatusRegAddrs                                0x0B55
#define MWV207REG_AHBXDMA_INTR_STATUS_Address                            0x02D54
#define MWV207REG_AHBXDMA_INTR_STATUS_MSB                                     15
#define MWV207REG_AHBXDMA_INTR_STATUS_LSB                                      0
#define MWV207REG_AHBXDMA_INTR_STATUS_BLK                                      0
#define MWV207REG_AHBXDMA_INTR_STATUS_Count                                    1
#define MWV207REG_AHBXDMA_INTR_STATUS_FieldMask                       0x07FFFFFF
#define MWV207REG_AHBXDMA_INTR_STATUS_ReadMask                        0x07FFFFFF
#define MWV207REG_AHBXDMA_INTR_STATUS_WriteMask                       0x00000000
#define MWV207REG_AHBXDMA_INTR_STATUS_ResetValue                      0x00000000

#define MWV207REG_AHBXDMA_INTR_STATUS_COMP_FRAME_COMPL                       0:0
#define MWV207REG_AHBXDMA_INTR_STATUS_COMP_FRAME_COMPL_End                     0
#define MWV207REG_AHBXDMA_INTR_STATUS_COMP_FRAME_COMPL_Start                   0
#define MWV207REG_AHBXDMA_INTR_STATUS_COMP_FRAME_COMPL_Type                  U01

#define MWV207REG_AHBXDMA_INTR_STATUS_DE_COMP_FRAME_COMPL                    1:1
#define MWV207REG_AHBXDMA_INTR_STATUS_DE_COMP_FRAME_COMPL_End                  1
#define MWV207REG_AHBXDMA_INTR_STATUS_DE_COMP_FRAME_COMPL_Start                1
#define MWV207REG_AHBXDMA_INTR_STATUS_DE_COMP_FRAME_COMPL_Type               U01

#define MWV207REG_AHBXDMA_INTR_STATUS_XIO_SYNC_ERROR                         2:2
#define MWV207REG_AHBXDMA_INTR_STATUS_XIO_SYNC_ERROR_End                       2
#define MWV207REG_AHBXDMA_INTR_STATUS_XIO_SYNC_ERROR_Start                     2
#define MWV207REG_AHBXDMA_INTR_STATUS_XIO_SYNC_ERROR_Type                    U01


#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT           3:3
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_End         3
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_Start       3
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PUREQ_TO_PUREQ_TIMEOUT_Type      U01

#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT          4:4
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_End        4
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_Start      4
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CUREQ_TO_CUREQ_TIMEOUT_Type     U01

#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT           5:5
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT_End         5
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT_Start       5
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIIN_PRREQ_TO_PRACK_TIMEOUT_Type      U01

#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT          6:6
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_End        6
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_Start      6
#define MWV207REG_AHBXDMA_INTR_STATUS_SBIOUT_CRREQ_TO_CRACK_TIMEOUT_Type     U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_XIODMA_ACC_VIOL                7:7
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_XIODMA_ACC_VIOL_End              7
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_XIODMA_ACC_VIOL_Start            7
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_XIODMA_ACC_VIOL                8:8
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_XIODMA_ACC_VIOL_End              8
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_XIODMA_ACC_VIOL_Start            8
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_XIODMA_ACC_VIOL                9:9
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_XIODMA_ACC_VIOL_End              9
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_XIODMA_ACC_VIOL_Start            9
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_XIODMA_ACC_VIOL              10:10
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_XIODMA_ACC_VIOL_End             10
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_XIODMA_ACC_VIOL_Start           10
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_XIODMA_ACC_VIOL              11:11
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_XIODMA_ACC_VIOL_End             11
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_XIODMA_ACC_VIOL_Start           11
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_XIODMA_ACC_VIOL              12:12
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_XIODMA_ACC_VIOL_End             12
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_XIODMA_ACC_VIOL_Start           12
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_XIODMA_ACC_VIOL              13:13
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_XIODMA_ACC_VIOL_End             13
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_XIODMA_ACC_VIOL_Start           13
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_XIODMA_ACC_VIOL              14:14
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_XIODMA_ACC_VIOL_End             14
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_XIODMA_ACC_VIOL_Start           14
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_XIODMA_ACC_VIOL              15:15
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_XIODMA_ACC_VIOL_End             15
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_XIODMA_ACC_VIOL_Start           15
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_XIODMA_ACC_VIOL_Type           U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_AXI_ACC_VIOL                 16:16
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_AXI_ACC_VIOL_End                16
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_AXI_ACC_VIOL_Start              16
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION0_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_AXI_ACC_VIOL                 17:17
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_AXI_ACC_VIOL_End                17
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_AXI_ACC_VIOL_Start              17
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION1_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_AXI_ACC_VIOL                 18:18
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_AXI_ACC_VIOL_End                18
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_AXI_ACC_VIOL_Start              18
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION2_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_AXI_ACC_VIOL                 19:19
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_AXI_ACC_VIOL_End                19
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_AXI_ACC_VIOL_Start              19
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION3_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_AXI_ACC_VIOL                 20:20
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_AXI_ACC_VIOL_End                20
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_AXI_ACC_VIOL_Start              20
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION4_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_AXI_ACC_VIOL                 21:21
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_AXI_ACC_VIOL_End                21
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_AXI_ACC_VIOL_Start              21
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION5_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_AXI_ACC_VIOL                 22:22
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_AXI_ACC_VIOL_End                22
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_AXI_ACC_VIOL_Start              22
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION6_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_AXI_ACC_VIOL                 23:23
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_AXI_ACC_VIOL_End                23
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_AXI_ACC_VIOL_Start              23
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION7_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_AXI_ACC_VIOL                 24:24
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_AXI_ACC_VIOL_End                24
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_AXI_ACC_VIOL_Start              24
#define MWV207REG_AHBXDMA_INTR_STATUS_REGION8_AXI_ACC_VIOL_Type              U01

#define MWV207REG_AHBXDMA_INTR_STATUS_PSITOSBI_FRM_COMPL                   25:25
#define MWV207REG_AHBXDMA_INTR_STATUS_PSITOSBI_FRM_COMPL_End                  25
#define MWV207REG_AHBXDMA_INTR_STATUS_PSITOSBI_FRM_COMPL_Start                25
#define MWV207REG_AHBXDMA_INTR_STATUS_PSITOSBI_FRM_COMPL_Type                U01

#define MWV207REG_AHBXDMA_INTR_STATUS_SBITOPSI_FRM_COMPL                   26:26
#define MWV207REG_AHBXDMA_INTR_STATUS_SBITOPSI_FRM_COMPL_End                  26
#define MWV207REG_AHBXDMA_INTR_STATUS_SBITOPSI_FRM_COMPL_Start                26
#define MWV207REG_AHBXDMA_INTR_STATUS_SBITOPSI_FRM_COMPL_Type                U01




#define mwv207regAHBXDMAIntrStatus2RegAddrs                               0x0B56
#define MWV207REG_AHBXDMA_INTR_STATUS2_Address                           0x02D58
#define MWV207REG_AHBXDMA_INTR_STATUS2_MSB                                    15
#define MWV207REG_AHBXDMA_INTR_STATUS2_LSB                                     0
#define MWV207REG_AHBXDMA_INTR_STATUS2_BLK                                     0
#define MWV207REG_AHBXDMA_INTR_STATUS2_Count                                   1
#define MWV207REG_AHBXDMA_INTR_STATUS2_FieldMask                      0x0003FFFF
#define MWV207REG_AHBXDMA_INTR_STATUS2_ReadMask                       0x0003FFFF
#define MWV207REG_AHBXDMA_INTR_STATUS2_WriteMask                      0x00000000
#define MWV207REG_AHBXDMA_INTR_STATUS2_ResetValue                     0x00000000


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_ISP_ACC_VIOL                  0:0
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_ISP_ACC_VIOL_End                0
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_ISP_ACC_VIOL_Start              0
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_ISP_ACC_VIOL                  1:1
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_ISP_ACC_VIOL_End                1
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_ISP_ACC_VIOL_Start              1
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_ISP_ACC_VIOL                  2:2
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_ISP_ACC_VIOL_End                2
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_ISP_ACC_VIOL_Start              2
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_ISP_ACC_VIOL                  3:3
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_ISP_ACC_VIOL_End                3
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_ISP_ACC_VIOL_Start              3
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_ISP_ACC_VIOL                  4:4
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_ISP_ACC_VIOL_End                4
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_ISP_ACC_VIOL_Start              4
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_ISP_ACC_VIOL                  5:5
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_ISP_ACC_VIOL_End                5
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_ISP_ACC_VIOL_Start              5
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_ISP_ACC_VIOL                  6:6
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_ISP_ACC_VIOL_End                6
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_ISP_ACC_VIOL_Start              6
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_ISP_ACC_VIOL                  7:7
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_ISP_ACC_VIOL_End                7
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_ISP_ACC_VIOL_Start              7
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_ISP_ACC_VIOL                  8:8
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_ISP_ACC_VIOL_End                8
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_ISP_ACC_VIOL_Start              8
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_ISP_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_CPU_ACC_VIOL                  9:9
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_CPU_ACC_VIOL_End                9
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_CPU_ACC_VIOL_Start              9
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION0_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_CPU_ACC_VIOL                10:10
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_CPU_ACC_VIOL_End               10
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_CPU_ACC_VIOL_Start             10
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION1_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_CPU_ACC_VIOL                11:11
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_CPU_ACC_VIOL_End               11
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_CPU_ACC_VIOL_Start             11
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION2_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_CPU_ACC_VIOL                12:12
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_CPU_ACC_VIOL_End               12
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_CPU_ACC_VIOL_Start             12
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION3_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_CPU_ACC_VIOL                13:13
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_CPU_ACC_VIOL_End               13
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_CPU_ACC_VIOL_Start             13
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION4_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_CPU_ACC_VIOL                14:14
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_CPU_ACC_VIOL_End               14
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_CPU_ACC_VIOL_Start             14
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION5_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_CPU_ACC_VIOL                15:15
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_CPU_ACC_VIOL_End               15
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_CPU_ACC_VIOL_Start             15
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION6_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_CPU_ACC_VIOL                16:16
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_CPU_ACC_VIOL_End               16
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_CPU_ACC_VIOL_Start             16
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION7_CPU_ACC_VIOL_Type             U01


#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_CPU_ACC_VIOL                17:17
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_CPU_ACC_VIOL_End               17
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_CPU_ACC_VIOL_Start             17
#define MWV207REG_AHBXDMA_INTR_STATUS2_REGION8_CPU_ACC_VIOL_Type             U01




#define mwv207regAHBCompressorRegAddrs                                    0x0B57
#define MWV207REG_AHB_COMPRESSOR_Address                                 0x02D5C
#define MWV207REG_AHB_COMPRESSOR_MSB                                          15
#define MWV207REG_AHB_COMPRESSOR_LSB                                           0
#define MWV207REG_AHB_COMPRESSOR_BLK                                           0
#define MWV207REG_AHB_COMPRESSOR_Count                                         1
#define MWV207REG_AHB_COMPRESSOR_FieldMask                            0x0FFFFFFF
#define MWV207REG_AHB_COMPRESSOR_ReadMask                             0x0FFFFFFF
#define MWV207REG_AHB_COMPRESSOR_WriteMask                            0x0FFFFFFF
#define MWV207REG_AHB_COMPRESSOR_ResetValue                           0x04000000


#define MWV207REG_AHB_COMPRESSOR_UNCOMPRESSED_MODE                           0:0
#define MWV207REG_AHB_COMPRESSOR_UNCOMPRESSED_MODE_End                         0
#define MWV207REG_AHB_COMPRESSOR_UNCOMPRESSED_MODE_Start                       0
#define MWV207REG_AHB_COMPRESSOR_UNCOMPRESSED_MODE_Type                      U01
#define   MWV207REG_AHB_COMPRESSOR_UNCOMPRESSED_MODE_COMPRESSED              0x0
#define   MWV207REG_AHB_COMPRESSOR_UNCOMPRESSED_MODE_UNCOMPRESSED            0x1


#define MWV207REG_AHB_COMPRESSOR_SOFT_CLEAR                                  1:1
#define MWV207REG_AHB_COMPRESSOR_SOFT_CLEAR_End                                1
#define MWV207REG_AHB_COMPRESSOR_SOFT_CLEAR_Start                              1
#define MWV207REG_AHB_COMPRESSOR_SOFT_CLEAR_Type                             U01

#define MWV207REG_AHB_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS                      9:2
#define MWV207REG_AHB_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS_End                    9
#define MWV207REG_AHB_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Start                  2
#define MWV207REG_AHB_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Type                 U08


#define MWV207REG_AHB_COMPRESSOR_FRAME_HEIGHT                              23:10
#define MWV207REG_AHB_COMPRESSOR_FRAME_HEIGHT_End                             23
#define MWV207REG_AHB_COMPRESSOR_FRAME_HEIGHT_Start                           10
#define MWV207REG_AHB_COMPRESSOR_FRAME_HEIGHT_Type                           U14


#define MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE                            25:24
#define MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE_End                           25
#define MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE_Start                         24
#define MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE_Type                         U02
#define   MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE_RGGB                       0x0
#define   MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE_GRBG                       0x1
#define   MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE_GBRG                       0x2
#define   MWV207REG_AHB_COMPRESSOR_CFG_BAYER_MODE_BGGR                       0x3


#define MWV207REG_AHB_COMPRESSOR_CFG_RATIO                                 27:26
#define MWV207REG_AHB_COMPRESSOR_CFG_RATIO_End                                27
#define MWV207REG_AHB_COMPRESSOR_CFG_RATIO_Start                              26
#define MWV207REG_AHB_COMPRESSOR_CFG_RATIO_Type                              U02
#define   MWV207REG_AHB_COMPRESSOR_CFG_RATIO_SIXTEEN_DIV_EIGHT               0x0
#define   MWV207REG_AHB_COMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TEN                 0x1
#define   MWV207REG_AHB_COMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TWELVE              0x2




#define mwv207regAHBDecompressorRegAddrs                                  0x0B58
#define MWV207REG_AHB_DECOMPRESSOR_Address                               0x02D60
#define MWV207REG_AHB_DECOMPRESSOR_MSB                                        15
#define MWV207REG_AHB_DECOMPRESSOR_LSB                                         0
#define MWV207REG_AHB_DECOMPRESSOR_BLK                                         0
#define MWV207REG_AHB_DECOMPRESSOR_Count                                       1
#define MWV207REG_AHB_DECOMPRESSOR_FieldMask                          0x0FFFFFFF
#define MWV207REG_AHB_DECOMPRESSOR_ReadMask                           0x0FFFFFFF
#define MWV207REG_AHB_DECOMPRESSOR_WriteMask                          0x0FFFFFFF
#define MWV207REG_AHB_DECOMPRESSOR_ResetValue                         0x04000000


#define MWV207REG_AHB_DECOMPRESSOR_UNCOMPRESSED_MODE                         0:0
#define MWV207REG_AHB_DECOMPRESSOR_UNCOMPRESSED_MODE_End                       0
#define MWV207REG_AHB_DECOMPRESSOR_UNCOMPRESSED_MODE_Start                     0
#define MWV207REG_AHB_DECOMPRESSOR_UNCOMPRESSED_MODE_Type                    U01
#define   MWV207REG_AHB_DECOMPRESSOR_UNCOMPRESSED_MODE_COMPRESSED            0x0
#define   MWV207REG_AHB_DECOMPRESSOR_UNCOMPRESSED_MODE_UNCOMPRESSED          0x1


#define MWV207REG_AHB_DECOMPRESSOR_SOFT_CLEAR                                1:1
#define MWV207REG_AHB_DECOMPRESSOR_SOFT_CLEAR_End                              1
#define MWV207REG_AHB_DECOMPRESSOR_SOFT_CLEAR_Start                            1
#define MWV207REG_AHB_DECOMPRESSOR_SOFT_CLEAR_Type                           U01

#define MWV207REG_AHB_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS                    9:2
#define MWV207REG_AHB_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS_End                  9
#define MWV207REG_AHB_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Start                2
#define MWV207REG_AHB_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Type               U08


#define MWV207REG_AHB_DECOMPRESSOR_FRAME_HEIGHT                            23:10
#define MWV207REG_AHB_DECOMPRESSOR_FRAME_HEIGHT_End                           23
#define MWV207REG_AHB_DECOMPRESSOR_FRAME_HEIGHT_Start                         10
#define MWV207REG_AHB_DECOMPRESSOR_FRAME_HEIGHT_Type                         U14


#define MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE                          25:24
#define MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE_End                         25
#define MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE_Start                       24
#define MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE_Type                       U02
#define   MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE_RGGB                     0x0
#define   MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE_GRBG                     0x1
#define   MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE_GBRG                     0x2
#define   MWV207REG_AHB_DECOMPRESSOR_CFG_BAYER_MODE_BGGR                     0x3


#define MWV207REG_AHB_DECOMPRESSOR_CFG_RATIO                               27:26
#define MWV207REG_AHB_DECOMPRESSOR_CFG_RATIO_End                              27
#define MWV207REG_AHB_DECOMPRESSOR_CFG_RATIO_Start                            26
#define MWV207REG_AHB_DECOMPRESSOR_CFG_RATIO_Type                            U02
#define   MWV207REG_AHB_DECOMPRESSOR_CFG_RATIO_SIXTEEN_DIV_EIGHT             0x0
#define   MWV207REG_AHB_DECOMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TEN               0x1
#define   MWV207REG_AHB_DECOMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TWELVE            0x2




#define mwv207regAHBDenoisePostProcessC0RegAddrs                          0x0B59
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_Address                    0x02D64
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_MSB                             15
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_LSB                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_BLK                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_Count                            1
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_FieldMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_ReadMask                0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_WriteMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_ResetValue              0x00000000

#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_VALUE                         31:0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_VALUE_End                       31
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_VALUE_Start                      0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C0_VALUE_Type                     U32




#define mwv207regAHBDenoisePostProcessC1RegAddrs                          0x0B5A
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_Address                    0x02D68
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_MSB                             15
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_LSB                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_BLK                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_Count                            1
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_FieldMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_ReadMask                0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_WriteMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_ResetValue              0x00000000

#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_VALUE                         31:0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_VALUE_End                       31
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_VALUE_Start                      0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C1_VALUE_Type                     U32




#define mwv207regAHBDenoisePostProcessC2RegAddrs                          0x0B5B
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_Address                    0x02D6C
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_MSB                             15
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_LSB                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_BLK                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_Count                            1
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_FieldMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_ReadMask                0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_WriteMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_ResetValue              0x00000000

#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_VALUE                         31:0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_VALUE_End                       31
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_VALUE_Start                      0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C2_VALUE_Type                     U32




#define mwv207regAHBDenoisePostProcessC3RegAddrs                          0x0B5C
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_Address                    0x02D70
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_MSB                             15
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_LSB                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_BLK                              0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_Count                            1
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_FieldMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_ReadMask                0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_WriteMask               0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_ResetValue              0x00000000

#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_VALUE                         31:0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_VALUE_End                       31
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_VALUE_Start                      0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_C3_VALUE_Type                     U32



#define mwv207regAHBDenoisePostProcessNnOutScaleRegAddrs                  0x0B5D
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_Address          0x02D74
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_MSB                   15
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_LSB                    0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_BLK                    0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_Count                  1
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_FieldMask     0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_ReadMask      0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_WriteMask     0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_ResetValue    0x00000000

#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE               31:0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE_End             31
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE_Start            0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE_Type           U32



#define mwv207regAHBDenoisePostProcessClampMinMaxRegAddrs                 0x0B5E
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_Address         0x02D78
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_MSB                  15
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_LSB                   0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_BLK                   0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_Count                 1
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_FieldMask    0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_ReadMask     0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_WriteMask    0xFFFFFFFF
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_ResetValue   0x00000000

#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX          15:0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX_End        15
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX_Start       0
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX_Type      U16

#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN         31:16
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN_End        31
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN_Start      16
#define MWV207REG_AHB_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN_Type      U16



#define mwv207regAHBXAxiQos0RegAddrs                                      0x0B5F
#define MWV207REG_AHBX_AXI_QOS0_Address                                  0x02D7C
#define MWV207REG_AHBX_AXI_QOS0_MSB                                           15
#define MWV207REG_AHBX_AXI_QOS0_LSB                                            0
#define MWV207REG_AHBX_AXI_QOS0_BLK                                            0
#define MWV207REG_AHBX_AXI_QOS0_Count                                          1
#define MWV207REG_AHBX_AXI_QOS0_FieldMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS0_ReadMask                              0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS0_WriteMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS0_ResetValue                            0x00000000

#define MWV207REG_AHBX_AXI_QOS0_SW_QOS                                       1:0
#define MWV207REG_AHBX_AXI_QOS0_SW_QOS_End                                     1
#define MWV207REG_AHBX_AXI_QOS0_SW_QOS_Start                                   0
#define MWV207REG_AHBX_AXI_QOS0_SW_QOS_Type                                  U02

#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE0                                 3:2
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE0_End                               3
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE0_Start                             2
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE0_Type                            U02

#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE1                                 5:4
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE1_End                               5
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE1_Start                             4
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE1_Type                            U02

#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE2                                 7:6
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE2_End                               7
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE2_Start                             6
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE2_Type                            U02

#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE3                                 9:8
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE3_End                               9
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE3_Start                             8
#define MWV207REG_AHBX_AXI_QOS0_HW_QOS_CODE3_Type                            U02

#define MWV207REG_AHBX_AXI_QOS0_TH1                                        14:10
#define MWV207REG_AHBX_AXI_QOS0_TH1_End                                       14
#define MWV207REG_AHBX_AXI_QOS0_TH1_Start                                     10
#define MWV207REG_AHBX_AXI_QOS0_TH1_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS0_TH2                                        19:15
#define MWV207REG_AHBX_AXI_QOS0_TH2_End                                       19
#define MWV207REG_AHBX_AXI_QOS0_TH2_Start                                     15
#define MWV207REG_AHBX_AXI_QOS0_TH2_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS0_TH3                                        24:20
#define MWV207REG_AHBX_AXI_QOS0_TH3_End                                       24
#define MWV207REG_AHBX_AXI_QOS0_TH3_Start                                     20
#define MWV207REG_AHBX_AXI_QOS0_TH3_Type                                     U05



#define mwv207regAHBXAxiQos1RegAddrs                                      0x0B60
#define MWV207REG_AHBX_AXI_QOS1_Address                                  0x02D80
#define MWV207REG_AHBX_AXI_QOS1_MSB                                           15
#define MWV207REG_AHBX_AXI_QOS1_LSB                                            0
#define MWV207REG_AHBX_AXI_QOS1_BLK                                            0
#define MWV207REG_AHBX_AXI_QOS1_Count                                          1
#define MWV207REG_AHBX_AXI_QOS1_FieldMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS1_ReadMask                              0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS1_WriteMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS1_ResetValue                            0x00000000

#define MWV207REG_AHBX_AXI_QOS1_SW_QOS                                       1:0
#define MWV207REG_AHBX_AXI_QOS1_SW_QOS_End                                     1
#define MWV207REG_AHBX_AXI_QOS1_SW_QOS_Start                                   0
#define MWV207REG_AHBX_AXI_QOS1_SW_QOS_Type                                  U02

#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE0                                 3:2
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE0_End                               3
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE0_Start                             2
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE0_Type                            U02

#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE1                                 5:4
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE1_End                               5
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE1_Start                             4
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE1_Type                            U02

#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE2                                 7:6
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE2_End                               7
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE2_Start                             6
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE2_Type                            U02

#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE3                                 9:8
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE3_End                               9
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE3_Start                             8
#define MWV207REG_AHBX_AXI_QOS1_HW_QOS_CODE3_Type                            U02

#define MWV207REG_AHBX_AXI_QOS1_TH1                                        14:10
#define MWV207REG_AHBX_AXI_QOS1_TH1_End                                       14
#define MWV207REG_AHBX_AXI_QOS1_TH1_Start                                     10
#define MWV207REG_AHBX_AXI_QOS1_TH1_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS1_TH2                                        19:15
#define MWV207REG_AHBX_AXI_QOS1_TH2_End                                       19
#define MWV207REG_AHBX_AXI_QOS1_TH2_Start                                     15
#define MWV207REG_AHBX_AXI_QOS1_TH2_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS1_TH3                                        24:20
#define MWV207REG_AHBX_AXI_QOS1_TH3_End                                       24
#define MWV207REG_AHBX_AXI_QOS1_TH3_Start                                     20
#define MWV207REG_AHBX_AXI_QOS1_TH3_Type                                     U05



#define mwv207regAHBXAxiQos2RegAddrs                                      0x0B61
#define MWV207REG_AHBX_AXI_QOS2_Address                                  0x02D84
#define MWV207REG_AHBX_AXI_QOS2_MSB                                           15
#define MWV207REG_AHBX_AXI_QOS2_LSB                                            0
#define MWV207REG_AHBX_AXI_QOS2_BLK                                            0
#define MWV207REG_AHBX_AXI_QOS2_Count                                          1
#define MWV207REG_AHBX_AXI_QOS2_FieldMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS2_ReadMask                              0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS2_WriteMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS2_ResetValue                            0x00000000

#define MWV207REG_AHBX_AXI_QOS2_SW_QOS                                       1:0
#define MWV207REG_AHBX_AXI_QOS2_SW_QOS_End                                     1
#define MWV207REG_AHBX_AXI_QOS2_SW_QOS_Start                                   0
#define MWV207REG_AHBX_AXI_QOS2_SW_QOS_Type                                  U02

#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE0                                 3:2
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE0_End                               3
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE0_Start                             2
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE0_Type                            U02

#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE1                                 5:4
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE1_End                               5
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE1_Start                             4
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE1_Type                            U02

#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE2                                 7:6
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE2_End                               7
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE2_Start                             6
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE2_Type                            U02

#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE3                                 9:8
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE3_End                               9
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE3_Start                             8
#define MWV207REG_AHBX_AXI_QOS2_HW_QOS_CODE3_Type                            U02

#define MWV207REG_AHBX_AXI_QOS2_TH1                                        14:10
#define MWV207REG_AHBX_AXI_QOS2_TH1_End                                       14
#define MWV207REG_AHBX_AXI_QOS2_TH1_Start                                     10
#define MWV207REG_AHBX_AXI_QOS2_TH1_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS2_TH2                                        19:15
#define MWV207REG_AHBX_AXI_QOS2_TH2_End                                       19
#define MWV207REG_AHBX_AXI_QOS2_TH2_Start                                     15
#define MWV207REG_AHBX_AXI_QOS2_TH2_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS2_TH3                                        24:20
#define MWV207REG_AHBX_AXI_QOS2_TH3_End                                       24
#define MWV207REG_AHBX_AXI_QOS2_TH3_Start                                     20
#define MWV207REG_AHBX_AXI_QOS2_TH3_Type                                     U05



#define mwv207regAHBXAxiQos3RegAddrs                                      0x0B62
#define MWV207REG_AHBX_AXI_QOS3_Address                                  0x02D88
#define MWV207REG_AHBX_AXI_QOS3_MSB                                           15
#define MWV207REG_AHBX_AXI_QOS3_LSB                                            0
#define MWV207REG_AHBX_AXI_QOS3_BLK                                            0
#define MWV207REG_AHBX_AXI_QOS3_Count                                          1
#define MWV207REG_AHBX_AXI_QOS3_FieldMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS3_ReadMask                              0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS3_WriteMask                             0x01FFFFFF
#define MWV207REG_AHBX_AXI_QOS3_ResetValue                            0x00000000

#define MWV207REG_AHBX_AXI_QOS3_SW_QOS                                       1:0
#define MWV207REG_AHBX_AXI_QOS3_SW_QOS_End                                     1
#define MWV207REG_AHBX_AXI_QOS3_SW_QOS_Start                                   0
#define MWV207REG_AHBX_AXI_QOS3_SW_QOS_Type                                  U02

#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE0                                 3:2
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE0_End                               3
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE0_Start                             2
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE0_Type                            U02

#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE1                                 5:4
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE1_End                               5
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE1_Start                             4
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE1_Type                            U02

#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE2                                 7:6
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE2_End                               7
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE2_Start                             6
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE2_Type                            U02

#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE3                                 9:8
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE3_End                               9
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE3_Start                             8
#define MWV207REG_AHBX_AXI_QOS3_HW_QOS_CODE3_Type                            U02

#define MWV207REG_AHBX_AXI_QOS3_TH1                                        14:10
#define MWV207REG_AHBX_AXI_QOS3_TH1_End                                       14
#define MWV207REG_AHBX_AXI_QOS3_TH1_Start                                     10
#define MWV207REG_AHBX_AXI_QOS3_TH1_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS3_TH2                                        19:15
#define MWV207REG_AHBX_AXI_QOS3_TH2_End                                       19
#define MWV207REG_AHBX_AXI_QOS3_TH2_Start                                     15
#define MWV207REG_AHBX_AXI_QOS3_TH2_Type                                     U05

#define MWV207REG_AHBX_AXI_QOS3_TH3                                        24:20
#define MWV207REG_AHBX_AXI_QOS3_TH3_End                                       24
#define MWV207REG_AHBX_AXI_QOS3_TH3_Start                                     20
#define MWV207REG_AHBX_AXI_QOS3_TH3_Type                                     U05

#define mwv207regAHBXDeepSleep0RegAddrs                                   0x0B63
#define MWV207REG_AHBX_DEEP_SLEEP0_Address                               0x02D8C
#define MWV207REG_AHBX_DEEP_SLEEP0_MSB                                        15
#define MWV207REG_AHBX_DEEP_SLEEP0_LSB                                         0
#define MWV207REG_AHBX_DEEP_SLEEP0_BLK                                         0
#define MWV207REG_AHBX_DEEP_SLEEP0_Count                                       1
#define MWV207REG_AHBX_DEEP_SLEEP0_FieldMask                          0x01FFFFFF
#define MWV207REG_AHBX_DEEP_SLEEP0_ReadMask                           0x01FFFFFF
#define MWV207REG_AHBX_DEEP_SLEEP0_WriteMask                          0x01FE01FF
#define MWV207REG_AHBX_DEEP_SLEEP0_ResetValue                         0x00000000


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP0                                   1:0
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP0_End                                 1
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP0_Start                               0
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP0_Type                              U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP0_NOSLEEP                         0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP0_IMMEDIATE                       0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP0_VBLANK                          0x2


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP1                                   3:2
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP1_End                                 3
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP1_Start                               2
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP1_Type                              U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP1_NOSLEEP                         0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP1_IMMEDIATE                       0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP1_VBLANK                          0x2


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP2                                   5:4
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP2_End                                 5
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP2_Start                               4
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP2_Type                              U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP2_NOSLEEP                         0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP2_IMMEDIATE                       0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP2_VBLANK                          0x2


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP3                                   7:6
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP3_End                                 7
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP3_Start                               6
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP3_Type                              U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP3_NOSLEEP                         0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP3_IMMEDIATE                       0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_VIP3_VBLANK                          0x2

#define MWV207REG_AHBX_DEEP_SLEEP0_WAKEUP_METHOD                             8:8
#define MWV207REG_AHBX_DEEP_SLEEP0_WAKEUP_METHOD_End                           8
#define MWV207REG_AHBX_DEEP_SLEEP0_WAKEUP_METHOD_Start                         8
#define MWV207REG_AHBX_DEEP_SLEEP0_WAKEUP_METHOD_Type                        U01
#define   MWV207REG_AHBX_DEEP_SLEEP0_WAKEUP_METHOD_HW_AUTO_DETECK            0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_WAKEUP_METHOD_SOFT_TIMER                0x1


#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0                              10:9
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0_End                            10
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0_Start                           9
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0_Type                          U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0_NONE_SLEEP                  0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0_ENTERRING                   0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0_IN_SLEEP                    0x2
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP0_WAKING_UP                   0x3


#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1                             12:11
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1_End                            12
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1_Start                          11
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1_Type                          U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1_NONE_SLEEP                  0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1_ENTERRING                   0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1_IN_SLEEP                    0x2
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP1_WAKING_UP                   0x3


#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2                             14:13
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2_End                            14
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2_Start                          13
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2_Type                          U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2_NONE_SLEEP                  0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2_ENTERRING                   0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2_IN_SLEEP                    0x2
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP2_WAKING_UP                   0x3


#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3                             16:15
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3_End                            16
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3_Start                          15
#define MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3_Type                          U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3_NONE_SLEEP                  0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3_ENTERRING                   0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3_IN_SLEEP                    0x2
#define   MWV207REG_AHBX_DEEP_SLEEP0_STATUS_VIP3_WAKING_UP                   0x3


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART0                     18:17
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART0_End                    18
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART0_Start                  17
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART0_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART0_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART0_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART0_VBLANK              0x2


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART1                     20:19
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART1_End                    20
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART1_Start                  19
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART1_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART1_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART1_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART1_VBLANK              0x2


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART2                     22:21
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART2_End                    22
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART2_Start                  21
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART2_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART2_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART2_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART2_VBLANK              0x2


#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART3                     24:23
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART3_End                    24
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART3_Start                  23
#define MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART3_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART3_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART3_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP0_EN_SHARED_OCM_PART3_VBLANK              0x2

#define mwv207regAHBXDeepSleep1RegAddrs                                   0x0B64
#define MWV207REG_AHBX_DEEP_SLEEP1_Address                               0x02D90
#define MWV207REG_AHBX_DEEP_SLEEP1_MSB                                        15
#define MWV207REG_AHBX_DEEP_SLEEP1_LSB                                         0
#define MWV207REG_AHBX_DEEP_SLEEP1_BLK                                         0
#define MWV207REG_AHBX_DEEP_SLEEP1_Count                                       1
#define MWV207REG_AHBX_DEEP_SLEEP1_FieldMask                          0x00FFFFFF
#define MWV207REG_AHBX_DEEP_SLEEP1_ReadMask                           0x00FFFFFF
#define MWV207REG_AHBX_DEEP_SLEEP1_WriteMask                          0x000000FF
#define MWV207REG_AHBX_DEEP_SLEEP1_ResetValue                         0x00000000


#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART4                       1:0
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART4_End                     1
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART4_Start                   0
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART4_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART4_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART4_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART4_VBLANK              0x2


#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART5                       3:2
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART5_End                     3
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART5_Start                   2
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART5_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART5_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART5_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART5_VBLANK              0x2


#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART6                       5:4
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART6_End                     5
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART6_Start                   4
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART6_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART6_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART6_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART6_VBLANK              0x2


#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART7                       7:6
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART7_End                     7
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART7_Start                   6
#define MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART7_Type                  U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART7_NOSLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART7_IMMEDIATE           0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_EN_SHARED_OCM_PART7_VBLANK              0x2


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0                          9:8
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0_End                        9
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0_Start                      8
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART0_WAKING_UP              0x3


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1                        11:10
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1_End                       11
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1_Start                     10
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART1_WAKING_UP              0x3


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2                        13:12
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2_End                       13
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2_Start                     12
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART2_WAKING_UP              0x3


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3                        15:14
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3_End                       15
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3_Start                     14
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART3_WAKING_UP              0x3


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4                        17:16
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4_End                       17
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4_Start                     16
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART4_WAKING_UP              0x3


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5                        19:18
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5_End                       19
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5_Start                     18
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART5_WAKING_UP              0x3


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6                        21:20
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6_End                       21
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6_Start                     20
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART6_WAKING_UP              0x3


#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7                        23:22
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7_End                       23
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7_Start                     22
#define MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7_Type                     U02
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7_NONE_SLEEP             0x0
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7_ENTERRING              0x1
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7_IN_SLEEP               0x2
#define   MWV207REG_AHBX_DEEP_SLEEP1_STATUS_OCM_PART7_WAKING_UP              0x3

#define mwv207regAHBXDeepSleep2RegAddrs                                   0x0B65
#define MWV207REG_AHBX_DEEP_SLEEP2_Address                               0x02D94
#define MWV207REG_AHBX_DEEP_SLEEP2_MSB                                        15
#define MWV207REG_AHBX_DEEP_SLEEP2_LSB                                         0
#define MWV207REG_AHBX_DEEP_SLEEP2_BLK                                         0
#define MWV207REG_AHBX_DEEP_SLEEP2_Count                                       1
#define MWV207REG_AHBX_DEEP_SLEEP2_FieldMask                          0xFFFFFFFF
#define MWV207REG_AHBX_DEEP_SLEEP2_ReadMask                           0xFFFFFFFF
#define MWV207REG_AHBX_DEEP_SLEEP2_WriteMask                          0x003FFFFF
#define MWV207REG_AHBX_DEEP_SLEEP2_ResetValue                         0xFFDF0000


#define MWV207REG_AHBX_DEEP_SLEEP2_WAKE_UP_COUNT                            15:0
#define MWV207REG_AHBX_DEEP_SLEEP2_WAKE_UP_COUNT_End                          15
#define MWV207REG_AHBX_DEEP_SLEEP2_WAKE_UP_COUNT_Start                         0
#define MWV207REG_AHBX_DEEP_SLEEP2_WAKE_UP_COUNT_Type                        U16


#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD                              19:16
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD_End                             19
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD_Start                           16
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD_Type                           U04


#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD                              20:20
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD_End                             20
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD_Start                           20
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD_Type                           U01


#define MWV207REG_AHBX_DEEP_SLEEP2_RAM_DSLPLV                              21:21
#define MWV207REG_AHBX_DEEP_SLEEP2_RAM_DSLPLV_End                             21
#define MWV207REG_AHBX_DEEP_SLEEP2_RAM_DSLPLV_Start                           21
#define MWV207REG_AHBX_DEEP_SLEEP2_RAM_DSLPLV_Type                           U01


#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD_OUT                          25:22
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD_OUT_End                         25
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD_OUT_Start                       22
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_SD_OUT_Type                       U04


#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD_OUT                          26:26
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD_OUT_End                         26
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD_OUT_Start                       26
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_SD_OUT_Type                       U01


#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_DSLP_OUT                        30:27
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_DSLP_OUT_End                       30
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_DSLP_OUT_Start                     27
#define MWV207REG_AHBX_DEEP_SLEEP2_VIP_RAM_DSLP_OUT_Type                     U04


#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_DSLP_OUT                        31:31
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_DSLP_OUT_End                       31
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_DSLP_OUT_Start                     31
#define MWV207REG_AHBX_DEEP_SLEEP2_OCM_RAM_DSLP_OUT_Type                     U01

#define mwv207regAHBXCacheRegAddrs                                        0x0B66
#define MWV207REG_AHBX_CACHE_Address                                     0x02D98
#define MWV207REG_AHBX_CACHE_MSB                                              15
#define MWV207REG_AHBX_CACHE_LSB                                               0
#define MWV207REG_AHBX_CACHE_BLK                                               0
#define MWV207REG_AHBX_CACHE_Count                                             1
#define MWV207REG_AHBX_CACHE_FieldMask                                0x000000FF
#define MWV207REG_AHBX_CACHE_ReadMask                                 0x000000FF
#define MWV207REG_AHBX_CACHE_WriteMask                                0x000000FF
#define MWV207REG_AHBX_CACHE_ResetValue                               0x00000022


#define MWV207REG_AHBX_CACHE_AR_VALUE                                        3:0
#define MWV207REG_AHBX_CACHE_AR_VALUE_End                                      3
#define MWV207REG_AHBX_CACHE_AR_VALUE_Start                                    0
#define MWV207REG_AHBX_CACHE_AR_VALUE_Type                                   U04


#define MWV207REG_AHBX_CACHE_AW_VALUE                                        7:4
#define MWV207REG_AHBX_CACHE_AW_VALUE_End                                      7
#define MWV207REG_AHBX_CACHE_AW_VALUE_Start                                    4
#define MWV207REG_AHBX_CACHE_AW_VALUE_Type                                   U04




#define mwv207regAHBXVIPDebugRegAddrs                                     0x0B67
#define MWV207REG_AHBXVIP_DEBUG_Address                                  0x02D9C
#define MWV207REG_AHBXVIP_DEBUG_MSB                                           15
#define MWV207REG_AHBXVIP_DEBUG_LSB                                            0
#define MWV207REG_AHBXVIP_DEBUG_BLK                                            0
#define MWV207REG_AHBXVIP_DEBUG_Count                                          1
#define MWV207REG_AHBXVIP_DEBUG_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXVIP_DEBUG_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXVIP_DEBUG_WriteMask                             0xFFFFFFFF
#define MWV207REG_AHBXVIP_DEBUG_ResetValue                            0x00000000

#define MWV207REG_AHBXVIP_DEBUG_OCLA                                        31:0
#define MWV207REG_AHBXVIP_DEBUG_OCLA_End                                      31
#define MWV207REG_AHBXVIP_DEBUG_OCLA_Start                                     0
#define MWV207REG_AHBXVIP_DEBUG_OCLA_Type                                    U32



#define mwv207regAHBXTTDMisc2RegAddrs                                     0x0B68
#define MWV207REG_AHBXTTD_MISC2_Address                                  0x02DA0
#define MWV207REG_AHBXTTD_MISC2_MSB                                           15
#define MWV207REG_AHBXTTD_MISC2_LSB                                            0
#define MWV207REG_AHBXTTD_MISC2_BLK                                            0
#define MWV207REG_AHBXTTD_MISC2_Count                                          1
#define MWV207REG_AHBXTTD_MISC2_FieldMask                             0x0000003F
#define MWV207REG_AHBXTTD_MISC2_ReadMask                              0x00000000
#define MWV207REG_AHBXTTD_MISC2_WriteMask                             0x0000003F
#define MWV207REG_AHBXTTD_MISC2_ResetValue                            0x00000000

#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA5                    0:0
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA5_End                  0
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA5_Start                0
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA5_Type               U01

#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA6                    1:1
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA6_End                  1
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA6_Start                1
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA6_Type               U01

#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA7                    2:2
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA7_End                  2
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA7_Start                2
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA7_Type               U01

#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA8                    3:3
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA8_End                  3
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA8_Start                3
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA8_Type               U01

#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA9                    4:4
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA9_End                  4
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA9_Start                4
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA9_Type               U01

#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA10                   5:5
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA10_End                 5
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA10_Start               5
#define MWV207REG_AHBXTTD_MISC2_XSHADOW_REG_PREPARED_DMA10_Type              U01




#define mwv207regAHBCompDecompRegAddrs                                    0x0B69
#define MWV207REG_AHB_COMP_DECOMP_Address                                0x02DA4
#define MWV207REG_AHB_COMP_DECOMP_MSB                                         15
#define MWV207REG_AHB_COMP_DECOMP_LSB                                          0
#define MWV207REG_AHB_COMP_DECOMP_BLK                                          0
#define MWV207REG_AHB_COMP_DECOMP_Count                                        1
#define MWV207REG_AHB_COMP_DECOMP_FieldMask                           0x00000FFF
#define MWV207REG_AHB_COMP_DECOMP_ReadMask                            0x00000FFF
#define MWV207REG_AHB_COMP_DECOMP_WriteMask                           0x00000FFF
#define MWV207REG_AHB_COMP_DECOMP_ResetValue                          0x00000000

#define MWV207REG_AHB_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS                 5:0
#define MWV207REG_AHB_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS_End               5
#define MWV207REG_AHB_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS_Start             0
#define MWV207REG_AHB_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS_Type            U06

#define MWV207REG_AHB_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS             11:6
#define MWV207REG_AHB_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS_End           11
#define MWV207REG_AHB_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS_Start          6
#define MWV207REG_AHB_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS_Type         U06





#define mwv207regAHBXTotalRdCPURegAddrs                                   0x0C80
#define MWV207REG_AHBX_TOTAL_RD_CPU_Address                              0x03200
#define MWV207REG_AHBX_TOTAL_RD_CPU_MSB                                       15
#define MWV207REG_AHBX_TOTAL_RD_CPU_LSB                                        0
#define MWV207REG_AHBX_TOTAL_RD_CPU_BLK                                        0
#define MWV207REG_AHBX_TOTAL_RD_CPU_Count                                      1
#define MWV207REG_AHBX_TOTAL_RD_CPU_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_CPU_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_CPU_WriteMask                         0x00000000
#define MWV207REG_AHBX_TOTAL_RD_CPU_ResetValue                        0x00000000

#define MWV207REG_AHBX_TOTAL_RD_CPU_COUNT                                   31:0
#define MWV207REG_AHBX_TOTAL_RD_CPU_COUNT_End                                 31
#define MWV207REG_AHBX_TOTAL_RD_CPU_COUNT_Start                                0
#define MWV207REG_AHBX_TOTAL_RD_CPU_COUNT_Type                               U32




#define mwv207regAHBXTotalWrCPURegAddrs                                   0x0C81
#define MWV207REG_AHBX_TOTAL_WR_CPU_Address                              0x03204
#define MWV207REG_AHBX_TOTAL_WR_CPU_MSB                                       15
#define MWV207REG_AHBX_TOTAL_WR_CPU_LSB                                        0
#define MWV207REG_AHBX_TOTAL_WR_CPU_BLK                                        0
#define MWV207REG_AHBX_TOTAL_WR_CPU_Count                                      1
#define MWV207REG_AHBX_TOTAL_WR_CPU_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_CPU_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_CPU_WriteMask                         0x00000000
#define MWV207REG_AHBX_TOTAL_WR_CPU_ResetValue                        0x00000000

#define MWV207REG_AHBX_TOTAL_WR_CPU_COUNT                                   31:0
#define MWV207REG_AHBX_TOTAL_WR_CPU_COUNT_End                                 31
#define MWV207REG_AHBX_TOTAL_WR_CPU_COUNT_Start                                0
#define MWV207REG_AHBX_TOTAL_WR_CPU_COUNT_Type                               U32




#define mwv207regAHBXTotalWrBurstCPURegAddrs                              0x0C82
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_Address                        0x03208
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_MSB                                 15
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_LSB                                  0
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_BLK                                  0
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_Count                                1
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_FieldMask                   0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_ReadMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_WriteMask                   0x00000000
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_ResetValue                  0x00000000

#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_COUNT                             31:0
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_COUNT_End                           31
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_COUNT_Start                          0
#define MWV207REG_AHBX_TOTAL_WR_BURST_CPU_COUNT_Type                         U32




#define mwv207regAHBXTotalWrReqCPURegAddrs                                0x0C83
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_Address                          0x0320C
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_MSB                                   15
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_LSB                                    0
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_BLK                                    0
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_Count                                  1
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_WriteMask                     0x00000000
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_ResetValue                    0x00000000

#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_COUNT                               31:0
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_COUNT_End                             31
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_COUNT_Start                            0
#define MWV207REG_AHBX_TOTAL_WR_REQ_CPU_COUNT_Type                           U32




#define mwv207regAHBXTotalWrLastCPURegAddrs                               0x0C84
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_Address                         0x03210
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_MSB                                  15
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_LSB                                   0
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_BLK                                   0
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_Count                                 1
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_FieldMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_ReadMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_WriteMask                    0x00000000
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_ResetValue                   0x00000000

#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_COUNT                              31:0
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_COUNT_End                            31
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_COUNT_Start                           0
#define MWV207REG_AHBX_TOTAL_WR_LAST_CPU_COUNT_Type                          U32




#define mwv207regAHBXTotalRdBurstCPURegAddrs                              0x0C85
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_Address                        0x03214
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_MSB                                 15
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_LSB                                  0
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_BLK                                  0
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_Count                                1
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_FieldMask                   0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_ReadMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_WriteMask                   0x00000000
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_ResetValue                  0x00000000

#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_COUNT                             31:0
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_COUNT_End                           31
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_COUNT_Start                          0
#define MWV207REG_AHBX_TOTAL_RD_BURST_CPU_COUNT_Type                         U32




#define mwv207regAHBXTotalRdReqCPURegAddrs                                0x0C86
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_Address                          0x03218
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_MSB                                   15
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_LSB                                    0
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_BLK                                    0
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_Count                                  1
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_WriteMask                     0x00000000
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_ResetValue                    0x00000000

#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_COUNT                               31:0
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_COUNT_End                             31
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_COUNT_Start                            0
#define MWV207REG_AHBX_TOTAL_RD_REQ_CPU_COUNT_Type                           U32




#define mwv207regAHBXTotalRdLastCPURegAddrs                               0x0C87
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_Address                         0x0321C
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_MSB                                  15
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_LSB                                   0
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_BLK                                   0
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_Count                                 1
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_FieldMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_ReadMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_WriteMask                    0x00000000
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_ResetValue                   0x00000000

#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_COUNT                              31:0
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_COUNT_End                            31
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_COUNT_Start                           0
#define MWV207REG_AHBX_TOTAL_RD_LAST_CPU_COUNT_Type                          U32




#define mwv207regAHBXTotalRdISPRegAddrs                                   0x0C88
#define MWV207REG_AHBX_TOTAL_RD_ISP_Address                              0x03220
#define MWV207REG_AHBX_TOTAL_RD_ISP_MSB                                       15
#define MWV207REG_AHBX_TOTAL_RD_ISP_LSB                                        0
#define MWV207REG_AHBX_TOTAL_RD_ISP_BLK                                        0
#define MWV207REG_AHBX_TOTAL_RD_ISP_Count                                      1
#define MWV207REG_AHBX_TOTAL_RD_ISP_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_ISP_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_ISP_WriteMask                         0x00000000
#define MWV207REG_AHBX_TOTAL_RD_ISP_ResetValue                        0x00000000

#define MWV207REG_AHBX_TOTAL_RD_ISP_COUNT                                   31:0
#define MWV207REG_AHBX_TOTAL_RD_ISP_COUNT_End                                 31
#define MWV207REG_AHBX_TOTAL_RD_ISP_COUNT_Start                                0
#define MWV207REG_AHBX_TOTAL_RD_ISP_COUNT_Type                               U32




#define mwv207regAHBXTotalWrISPRegAddrs                                   0x0C89
#define MWV207REG_AHBX_TOTAL_WR_ISP_Address                              0x03224
#define MWV207REG_AHBX_TOTAL_WR_ISP_MSB                                       15
#define MWV207REG_AHBX_TOTAL_WR_ISP_LSB                                        0
#define MWV207REG_AHBX_TOTAL_WR_ISP_BLK                                        0
#define MWV207REG_AHBX_TOTAL_WR_ISP_Count                                      1
#define MWV207REG_AHBX_TOTAL_WR_ISP_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_ISP_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_ISP_WriteMask                         0x00000000
#define MWV207REG_AHBX_TOTAL_WR_ISP_ResetValue                        0x00000000

#define MWV207REG_AHBX_TOTAL_WR_ISP_COUNT                                   31:0
#define MWV207REG_AHBX_TOTAL_WR_ISP_COUNT_End                                 31
#define MWV207REG_AHBX_TOTAL_WR_ISP_COUNT_Start                                0
#define MWV207REG_AHBX_TOTAL_WR_ISP_COUNT_Type                               U32




#define mwv207regAHBXTotalWrBurstISPRegAddrs                              0x0C8A
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_Address                        0x03228
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_MSB                                 15
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_LSB                                  0
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_BLK                                  0
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_Count                                1
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_FieldMask                   0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_ReadMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_WriteMask                   0x00000000
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_ResetValue                  0x00000000

#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_COUNT                             31:0
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_COUNT_End                           31
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_COUNT_Start                          0
#define MWV207REG_AHBX_TOTAL_WR_BURST_ISP_COUNT_Type                         U32




#define mwv207regAHBXTotalWrReqISPRegAddrs                                0x0C8B
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_Address                          0x0322C
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_MSB                                   15
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_LSB                                    0
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_BLK                                    0
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_Count                                  1
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_WriteMask                     0x00000000
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_ResetValue                    0x00000000

#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_COUNT                               31:0
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_COUNT_End                             31
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_COUNT_Start                            0
#define MWV207REG_AHBX_TOTAL_WR_REQ_ISP_COUNT_Type                           U32




#define mwv207regAHBXTotalWrLastISPRegAddrs                               0x0C8C
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_Address                         0x03230
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_MSB                                  15
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_LSB                                   0
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_BLK                                   0
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_Count                                 1
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_FieldMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_ReadMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_WriteMask                    0x00000000
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_ResetValue                   0x00000000

#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_COUNT                              31:0
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_COUNT_End                            31
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_COUNT_Start                           0
#define MWV207REG_AHBX_TOTAL_WR_LAST_ISP_COUNT_Type                          U32




#define mwv207regAHBXTotalRdBurstISPRegAddrs                              0x0C8D
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_Address                        0x03234
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_MSB                                 15
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_LSB                                  0
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_BLK                                  0
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_Count                                1
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_FieldMask                   0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_ReadMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_WriteMask                   0x00000000
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_ResetValue                  0x00000000

#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_COUNT                             31:0
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_COUNT_End                           31
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_COUNT_Start                          0
#define MWV207REG_AHBX_TOTAL_RD_BURST_ISP_COUNT_Type                         U32




#define mwv207regAHBXTotalRdReqISPRegAddrs                                0x0C8E
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_Address                          0x03238
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_MSB                                   15
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_LSB                                    0
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_BLK                                    0
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_Count                                  1
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_WriteMask                     0x00000000
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_ResetValue                    0x00000000

#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_COUNT                               31:0
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_COUNT_End                             31
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_COUNT_Start                            0
#define MWV207REG_AHBX_TOTAL_RD_REQ_ISP_COUNT_Type                           U32




#define mwv207regAHBXTotalRdLastISPRegAddrs                               0x0C8F
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_Address                         0x0323C
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_MSB                                  15
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_LSB                                   0
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_BLK                                   0
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_Count                                 1
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_FieldMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_ReadMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_WriteMask                    0x00000000
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_ResetValue                   0x00000000

#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_COUNT                              31:0
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_COUNT_End                            31
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_COUNT_Start                           0
#define MWV207REG_AHBX_TOTAL_RD_LAST_ISP_COUNT_Type                          U32




#define mwv207regAHBXTotalRdDDRRegAddrs                                   0x0C90
#define MWV207REG_AHBX_TOTAL_RD_DDR_Address                              0x03240
#define MWV207REG_AHBX_TOTAL_RD_DDR_MSB                                       15
#define MWV207REG_AHBX_TOTAL_RD_DDR_LSB                                        0
#define MWV207REG_AHBX_TOTAL_RD_DDR_BLK                                        0
#define MWV207REG_AHBX_TOTAL_RD_DDR_Count                                      1
#define MWV207REG_AHBX_TOTAL_RD_DDR_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_DDR_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_DDR_WriteMask                         0x00000000
#define MWV207REG_AHBX_TOTAL_RD_DDR_ResetValue                        0x00000000

#define MWV207REG_AHBX_TOTAL_RD_DDR_COUNT                                   31:0
#define MWV207REG_AHBX_TOTAL_RD_DDR_COUNT_End                                 31
#define MWV207REG_AHBX_TOTAL_RD_DDR_COUNT_Start                                0
#define MWV207REG_AHBX_TOTAL_RD_DDR_COUNT_Type                               U32




#define mwv207regAHBXTotalWrDDRRegAddrs                                   0x0C91
#define MWV207REG_AHBX_TOTAL_WR_DDR_Address                              0x03244
#define MWV207REG_AHBX_TOTAL_WR_DDR_MSB                                       15
#define MWV207REG_AHBX_TOTAL_WR_DDR_LSB                                        0
#define MWV207REG_AHBX_TOTAL_WR_DDR_BLK                                        0
#define MWV207REG_AHBX_TOTAL_WR_DDR_Count                                      1
#define MWV207REG_AHBX_TOTAL_WR_DDR_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_DDR_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_DDR_WriteMask                         0x00000000
#define MWV207REG_AHBX_TOTAL_WR_DDR_ResetValue                        0x00000000

#define MWV207REG_AHBX_TOTAL_WR_DDR_COUNT                                   31:0
#define MWV207REG_AHBX_TOTAL_WR_DDR_COUNT_End                                 31
#define MWV207REG_AHBX_TOTAL_WR_DDR_COUNT_Start                                0
#define MWV207REG_AHBX_TOTAL_WR_DDR_COUNT_Type                               U32




#define mwv207regAHBXTotalWrBurstDDRRegAddrs                              0x0C92
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_Address                        0x03248
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_MSB                                 15
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_LSB                                  0
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_BLK                                  0
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_Count                                1
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_FieldMask                   0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_ReadMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_WriteMask                   0x00000000
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_ResetValue                  0x00000000

#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_COUNT                             31:0
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_COUNT_End                           31
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_COUNT_Start                          0
#define MWV207REG_AHBX_TOTAL_WR_BURST_DDR_COUNT_Type                         U32




#define mwv207regAHBXTotalWrReqDDRRegAddrs                                0x0C93
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_Address                          0x0324C
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_MSB                                   15
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_LSB                                    0
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_BLK                                    0
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_Count                                  1
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_WriteMask                     0x00000000
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_ResetValue                    0x00000000

#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_COUNT                               31:0
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_COUNT_End                             31
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_COUNT_Start                            0
#define MWV207REG_AHBX_TOTAL_WR_REQ_DDR_COUNT_Type                           U32




#define mwv207regAHBXTotalWrLastDDRRegAddrs                               0x0C94
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_Address                         0x03250
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_MSB                                  15
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_LSB                                   0
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_BLK                                   0
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_Count                                 1
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_FieldMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_ReadMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_WriteMask                    0x00000000
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_ResetValue                   0x00000000

#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_COUNT                              31:0
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_COUNT_End                            31
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_COUNT_Start                           0
#define MWV207REG_AHBX_TOTAL_WR_LAST_DDR_COUNT_Type                          U32




#define mwv207regAHBXTotalRdBurstDDRRegAddrs                              0x0C95
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_Address                        0x03254
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_MSB                                 15
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_LSB                                  0
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_BLK                                  0
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_Count                                1
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_FieldMask                   0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_ReadMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_WriteMask                   0x00000000
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_ResetValue                  0x00000000

#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_COUNT                             31:0
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_COUNT_End                           31
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_COUNT_Start                          0
#define MWV207REG_AHBX_TOTAL_RD_BURST_DDR_COUNT_Type                         U32




#define mwv207regAHBXTotalRdReqDDRRegAddrs                                0x0C96
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_Address                          0x03258
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_MSB                                   15
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_LSB                                    0
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_BLK                                    0
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_Count                                  1
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_WriteMask                     0x00000000
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_ResetValue                    0x00000000

#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_COUNT                               31:0
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_COUNT_End                             31
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_COUNT_Start                            0
#define MWV207REG_AHBX_TOTAL_RD_REQ_DDR_COUNT_Type                           U32




#define mwv207regAHBXTotalRdLastDDRRegAddrs                               0x0C97
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_Address                         0x0325C
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_MSB                                  15
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_LSB                                   0
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_BLK                                   0
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_Count                                 1
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_FieldMask                    0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_ReadMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_WriteMask                    0x00000000
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_ResetValue                   0x00000000

#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_COUNT                              31:0
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_COUNT_End                            31
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_COUNT_Start                           0
#define MWV207REG_AHBX_TOTAL_RD_LAST_DDR_COUNT_Type                          U32

#define mwv207regAHBXMemCountRegAddrs                                     0x0C98
#define MWV207REG_AHBX_MEM_COUNT_Address                                 0x03260
#define MWV207REG_AHBX_MEM_COUNT_MSB                                          15
#define MWV207REG_AHBX_MEM_COUNT_LSB                                           0
#define MWV207REG_AHBX_MEM_COUNT_BLK                                           0
#define MWV207REG_AHBX_MEM_COUNT_Count                                         1
#define MWV207REG_AHBX_MEM_COUNT_FieldMask                            0x00000001
#define MWV207REG_AHBX_MEM_COUNT_ReadMask                             0x00000001
#define MWV207REG_AHBX_MEM_COUNT_WriteMask                            0x00000001
#define MWV207REG_AHBX_MEM_COUNT_ResetValue                           0x00000000

#define MWV207REG_AHBX_MEM_COUNT_RESET                                       0:0
#define MWV207REG_AHBX_MEM_COUNT_RESET_End                                     0
#define MWV207REG_AHBX_MEM_COUNT_RESET_Start                                   0
#define MWV207REG_AHBX_MEM_COUNT_RESET_Type                                  U01

#define mwv207regAHBXDDRRdCkTotalRegAddrs                                 0x0C99
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_Address                            0x03264
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_MSB                                     15
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_LSB                                      0
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_BLK                                      0
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_Count                                    1
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_FieldMask                       0xFFFFFFFF
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_ReadMask                        0xFFFFFFFF
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_WriteMask                       0x00000000
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_ResetValue                      0x00000000

#define MWV207REG_AHBXDDR_RD_CK_TOTAL_DATA_CNT                              31:0
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_DATA_CNT_End                            31
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_DATA_CNT_Start                           0
#define MWV207REG_AHBXDDR_RD_CK_TOTAL_DATA_CNT_Type                          U32

#define mwv207regAHBXDDRWrCkTotalRegAddrs                                 0x0C9A
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_Address                            0x03268
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_MSB                                     15
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_LSB                                      0
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_BLK                                      0
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_Count                                    1
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_FieldMask                       0xFFFFFFFF
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_ReadMask                        0xFFFFFFFF
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_WriteMask                       0x00000000
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_ResetValue                      0x00000000

#define MWV207REG_AHBXDDR_WR_CK_TOTAL_DATA_CNT                              31:0
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_DATA_CNT_End                            31
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_DATA_CNT_Start                           0
#define MWV207REG_AHBXDDR_WR_CK_TOTAL_DATA_CNT_Type                          U32

#define mwv207regAHBXPrAckRegAddrs                                        0x0C9B
#define MWV207REG_AHBX_PR_ACK_Address                                    0x0326C
#define MWV207REG_AHBX_PR_ACK_MSB                                             15
#define MWV207REG_AHBX_PR_ACK_LSB                                              0
#define MWV207REG_AHBX_PR_ACK_BLK                                              0
#define MWV207REG_AHBX_PR_ACK_Count                                            1
#define MWV207REG_AHBX_PR_ACK_FieldMask                               0xFFFFFFFF
#define MWV207REG_AHBX_PR_ACK_ReadMask                                0xFFFFFFFF
#define MWV207REG_AHBX_PR_ACK_WriteMask                               0x00000000
#define MWV207REG_AHBX_PR_ACK_ResetValue                              0x00000000

#define MWV207REG_AHBX_PR_ACK_CNT                                           31:0
#define MWV207REG_AHBX_PR_ACK_CNT_End                                         31
#define MWV207REG_AHBX_PR_ACK_CNT_Start                                        0
#define MWV207REG_AHBX_PR_ACK_CNT_Type                                       U32

#define mwv207regAHBXPuAckRegAddrs                                        0x0C9C
#define MWV207REG_AHBX_PU_ACK_Address                                    0x03270
#define MWV207REG_AHBX_PU_ACK_MSB                                             15
#define MWV207REG_AHBX_PU_ACK_LSB                                              0
#define MWV207REG_AHBX_PU_ACK_BLK                                              0
#define MWV207REG_AHBX_PU_ACK_Count                                            1
#define MWV207REG_AHBX_PU_ACK_FieldMask                               0xFFFFFFFF
#define MWV207REG_AHBX_PU_ACK_ReadMask                                0xFFFFFFFF
#define MWV207REG_AHBX_PU_ACK_WriteMask                               0x00000000
#define MWV207REG_AHBX_PU_ACK_ResetValue                              0x00000000

#define MWV207REG_AHBX_PU_ACK_CNT                                           31:0
#define MWV207REG_AHBX_PU_ACK_CNT_End                                         31
#define MWV207REG_AHBX_PU_ACK_CNT_Start                                        0
#define MWV207REG_AHBX_PU_ACK_CNT_Type                                       U32

#define mwv207regAHBXCrAckRegAddrs                                        0x0C9D
#define MWV207REG_AHBX_CR_ACK_Address                                    0x03274
#define MWV207REG_AHBX_CR_ACK_MSB                                             15
#define MWV207REG_AHBX_CR_ACK_LSB                                              0
#define MWV207REG_AHBX_CR_ACK_BLK                                              0
#define MWV207REG_AHBX_CR_ACK_Count                                            1
#define MWV207REG_AHBX_CR_ACK_FieldMask                               0xFFFFFFFF
#define MWV207REG_AHBX_CR_ACK_ReadMask                                0xFFFFFFFF
#define MWV207REG_AHBX_CR_ACK_WriteMask                               0x00000000
#define MWV207REG_AHBX_CR_ACK_ResetValue                              0x00000000

#define MWV207REG_AHBX_CR_ACK_CNT                                           31:0
#define MWV207REG_AHBX_CR_ACK_CNT_End                                         31
#define MWV207REG_AHBX_CR_ACK_CNT_Start                                        0
#define MWV207REG_AHBX_CR_ACK_CNT_Type                                       U32

#define mwv207regAHBXCuAckRegAddrs                                        0x0C9E
#define MWV207REG_AHBX_CU_ACK_Address                                    0x03278
#define MWV207REG_AHBX_CU_ACK_MSB                                             15
#define MWV207REG_AHBX_CU_ACK_LSB                                              0
#define MWV207REG_AHBX_CU_ACK_BLK                                              0
#define MWV207REG_AHBX_CU_ACK_Count                                            1
#define MWV207REG_AHBX_CU_ACK_FieldMask                               0xFFFFFFFF
#define MWV207REG_AHBX_CU_ACK_ReadMask                                0xFFFFFFFF
#define MWV207REG_AHBX_CU_ACK_WriteMask                               0x00000000
#define MWV207REG_AHBX_CU_ACK_ResetValue                              0x00000000

#define MWV207REG_AHBX_CU_ACK_CNT                                           31:0
#define MWV207REG_AHBX_CU_ACK_CNT_End                                         31
#define MWV207REG_AHBX_CU_ACK_CNT_Start                                        0
#define MWV207REG_AHBX_CU_ACK_CNT_Type                                       U32

#define mwv207regAHBXInFrmStartRegAddrs                                   0x0C9F
#define MWV207REG_AHBX_IN_FRM_START_Address                              0x0327C
#define MWV207REG_AHBX_IN_FRM_START_MSB                                       15
#define MWV207REG_AHBX_IN_FRM_START_LSB                                        0
#define MWV207REG_AHBX_IN_FRM_START_BLK                                        0
#define MWV207REG_AHBX_IN_FRM_START_Count                                      1
#define MWV207REG_AHBX_IN_FRM_START_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBX_IN_FRM_START_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBX_IN_FRM_START_WriteMask                         0x00000000
#define MWV207REG_AHBX_IN_FRM_START_ResetValue                        0x00000000

#define MWV207REG_AHBX_IN_FRM_START_CNT                                     31:0
#define MWV207REG_AHBX_IN_FRM_START_CNT_End                                   31
#define MWV207REG_AHBX_IN_FRM_START_CNT_Start                                  0
#define MWV207REG_AHBX_IN_FRM_START_CNT_Type                                 U32

#define mwv207regAHBXOutFrmStartRegAddrs                                  0x0CA0
#define MWV207REG_AHBX_OUT_FRM_START_Address                             0x03280
#define MWV207REG_AHBX_OUT_FRM_START_MSB                                      15
#define MWV207REG_AHBX_OUT_FRM_START_LSB                                       0
#define MWV207REG_AHBX_OUT_FRM_START_BLK                                       0
#define MWV207REG_AHBX_OUT_FRM_START_Count                                     1
#define MWV207REG_AHBX_OUT_FRM_START_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHBX_OUT_FRM_START_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHBX_OUT_FRM_START_WriteMask                        0x00000000
#define MWV207REG_AHBX_OUT_FRM_START_ResetValue                       0x00000000

#define MWV207REG_AHBX_OUT_FRM_START_CNT                                    31:0
#define MWV207REG_AHBX_OUT_FRM_START_CNT_End                                  31
#define MWV207REG_AHBX_OUT_FRM_START_CNT_Start                                 0
#define MWV207REG_AHBX_OUT_FRM_START_CNT_Type                                U32

#define mwv207regAHBXFlexaPSI0RegAddrs                                    0x0CA1
#define MWV207REG_AHBX_FLEXA_PSI0_Address                                0x03284
#define MWV207REG_AHBX_FLEXA_PSI0_MSB                                         15
#define MWV207REG_AHBX_FLEXA_PSI0_LSB                                          0
#define MWV207REG_AHBX_FLEXA_PSI0_BLK                                          0
#define MWV207REG_AHBX_FLEXA_PSI0_Count                                        1
#define MWV207REG_AHBX_FLEXA_PSI0_FieldMask                           0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI0_ReadMask                            0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI0_WriteMask                           0x00000000
#define MWV207REG_AHBX_FLEXA_PSI0_ResetValue                          0x00000000

#define MWV207REG_AHBX_FLEXA_PSI0_CNT                                       31:0
#define MWV207REG_AHBX_FLEXA_PSI0_CNT_End                                     31
#define MWV207REG_AHBX_FLEXA_PSI0_CNT_Start                                    0
#define MWV207REG_AHBX_FLEXA_PSI0_CNT_Type                                   U32

#define mwv207regAHBXFlexaPSI1RegAddrs                                    0x0CA2
#define MWV207REG_AHBX_FLEXA_PSI1_Address                                0x03288
#define MWV207REG_AHBX_FLEXA_PSI1_MSB                                         15
#define MWV207REG_AHBX_FLEXA_PSI1_LSB                                          0
#define MWV207REG_AHBX_FLEXA_PSI1_BLK                                          0
#define MWV207REG_AHBX_FLEXA_PSI1_Count                                        1
#define MWV207REG_AHBX_FLEXA_PSI1_FieldMask                           0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI1_ReadMask                            0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI1_WriteMask                           0x00000000
#define MWV207REG_AHBX_FLEXA_PSI1_ResetValue                          0x00000000

#define MWV207REG_AHBX_FLEXA_PSI1_CNT                                       31:0
#define MWV207REG_AHBX_FLEXA_PSI1_CNT_End                                     31
#define MWV207REG_AHBX_FLEXA_PSI1_CNT_Start                                    0
#define MWV207REG_AHBX_FLEXA_PSI1_CNT_Type                                   U32

#define mwv207regAHBXFlexaPSI2RegAddrs                                    0x0CA3
#define MWV207REG_AHBX_FLEXA_PSI2_Address                                0x0328C
#define MWV207REG_AHBX_FLEXA_PSI2_MSB                                         15
#define MWV207REG_AHBX_FLEXA_PSI2_LSB                                          0
#define MWV207REG_AHBX_FLEXA_PSI2_BLK                                          0
#define MWV207REG_AHBX_FLEXA_PSI2_Count                                        1
#define MWV207REG_AHBX_FLEXA_PSI2_FieldMask                           0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI2_ReadMask                            0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI2_WriteMask                           0x00000000
#define MWV207REG_AHBX_FLEXA_PSI2_ResetValue                          0x00000000

#define MWV207REG_AHBX_FLEXA_PSI2_CNT                                       31:0
#define MWV207REG_AHBX_FLEXA_PSI2_CNT_End                                     31
#define MWV207REG_AHBX_FLEXA_PSI2_CNT_Start                                    0
#define MWV207REG_AHBX_FLEXA_PSI2_CNT_Type                                   U32

#define mwv207regAHBXFlexaPSI3RegAddrs                                    0x0CA4
#define MWV207REG_AHBX_FLEXA_PSI3_Address                                0x03290
#define MWV207REG_AHBX_FLEXA_PSI3_MSB                                         15
#define MWV207REG_AHBX_FLEXA_PSI3_LSB                                          0
#define MWV207REG_AHBX_FLEXA_PSI3_BLK                                          0
#define MWV207REG_AHBX_FLEXA_PSI3_Count                                        1
#define MWV207REG_AHBX_FLEXA_PSI3_FieldMask                           0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI3_ReadMask                            0xFFFFFFFF
#define MWV207REG_AHBX_FLEXA_PSI3_WriteMask                           0x00000000
#define MWV207REG_AHBX_FLEXA_PSI3_ResetValue                          0x00000000

#define MWV207REG_AHBX_FLEXA_PSI3_CNT                                       31:0
#define MWV207REG_AHBX_FLEXA_PSI3_CNT_End                                     31
#define MWV207REG_AHBX_FLEXA_PSI3_CNT_Start                                    0
#define MWV207REG_AHBX_FLEXA_PSI3_CNT_Type                                   U32

#define mwv207regAHBXVIPSramDeepSleepRegAddrs                             0x0CA5
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_Address                        0x03294
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_MSB                                 15
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_LSB                                  0
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_BLK                                  0
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_Count                                1
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_FieldMask                   0x00000FFF
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_ReadMask                    0x00000FFF
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_WriteMask                   0x00000000
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_ResetValue                  0x00000000

#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_STATUS                            11:0
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_STATUS_End                          11
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_STATUS_Start                         0
#define MWV207REG_AHBXVIP_SRAM_DEEP_SLEEP_STATUS_Type                        U12

#define mwv207regAHBXOcmDeepSleepRegAddrs                                 0x0CA6
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_Address                            0x03298
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_MSB                                     15
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_LSB                                      0
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_BLK                                      0
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_Count                                    1
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_FieldMask                       0x00FFFFFF
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_ReadMask                        0x00FFFFFF
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_WriteMask                       0x00000000
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_ResetValue                      0x00000000

#define MWV207REG_AHBX_OCM_DEEP_SLEEP_STATUS                                23:0
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_STATUS_End                              23
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_STATUS_Start                             0
#define MWV207REG_AHBX_OCM_DEEP_SLEEP_STATUS_Type                            U24

#define mwv207regAHBXVIPWorkDoneRegAddrs                                  0x0CA7
#define MWV207REG_AHBXVIP_WORK_DONE_Address                              0x0329C
#define MWV207REG_AHBXVIP_WORK_DONE_MSB                                       15
#define MWV207REG_AHBXVIP_WORK_DONE_LSB                                        0
#define MWV207REG_AHBXVIP_WORK_DONE_BLK                                        0
#define MWV207REG_AHBXVIP_WORK_DONE_Count                                      1
#define MWV207REG_AHBXVIP_WORK_DONE_FieldMask                         0xFFFFFFFF
#define MWV207REG_AHBXVIP_WORK_DONE_ReadMask                          0xFFFFFFFF
#define MWV207REG_AHBXVIP_WORK_DONE_WriteMask                         0x00000000
#define MWV207REG_AHBXVIP_WORK_DONE_ResetValue                        0x00000000

#define MWV207REG_AHBXVIP_WORK_DONE_CNT                                     31:0
#define MWV207REG_AHBXVIP_WORK_DONE_CNT_End                                   31
#define MWV207REG_AHBXVIP_WORK_DONE_CNT_Start                                  0
#define MWV207REG_AHBXVIP_WORK_DONE_CNT_Type                                 U32

#define mwv207regAHBXVIP0TotalWrReqRegAddrs                               0x0CA8
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_Address                          0x032A0
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_MSB                                   15
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_LSB                                    0
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_BLK                                    0
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_Count                                  1
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP0_TOTAL_WR_REQ_CNT_Type                             U32

#define mwv207regAHBXVIP0TotalRdReqRegAddrs                               0x0CA9
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_Address                          0x032A4
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_MSB                                   15
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_LSB                                    0
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_BLK                                    0
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_Count                                  1
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP0_TOTAL_RD_REQ_CNT_Type                             U32

#define mwv207regAHBXVIP1TotalWrReqRegAddrs                               0x0CAA
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_Address                          0x032A8
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_MSB                                   15
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_LSB                                    0
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_BLK                                    0
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_Count                                  1
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP1_TOTAL_WR_REQ_CNT_Type                             U32

#define mwv207regAHBXVIP1TotalRdReqRegAddrs                               0x0CAB
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_Address                          0x032AC
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_MSB                                   15
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_LSB                                    0
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_BLK                                    0
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_Count                                  1
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP1_TOTAL_RD_REQ_CNT_Type                             U32

#define mwv207regAHBXVIP2TotalWrReqRegAddrs                               0x0CAC
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_Address                          0x032B0
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_MSB                                   15
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_LSB                                    0
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_BLK                                    0
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_Count                                  1
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP2_TOTAL_WR_REQ_CNT_Type                             U32

#define mwv207regAHBXVIP2TotalRdReqRegAddrs                               0x0CAD
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_Address                          0x032B4
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_MSB                                   15
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_LSB                                    0
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_BLK                                    0
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_Count                                  1
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP2_TOTAL_RD_REQ_CNT_Type                             U32

#define mwv207regAHBXVIP3TotalWrReqRegAddrs                               0x0CAE
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_Address                          0x032B8
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_MSB                                   15
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_LSB                                    0
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_BLK                                    0
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_Count                                  1
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP3_TOTAL_WR_REQ_CNT_Type                             U32

#define mwv207regAHBXVIP3TotalRdReqRegAddrs                               0x0CAF
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_Address                          0x032BC
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_MSB                                   15
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_LSB                                    0
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_BLK                                    0
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_Count                                  1
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_CNT                                 31:0
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_CNT_End                               31
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_CNT_Start                              0
#define MWV207REG_AHBXVIP3_TOTAL_RD_REQ_CNT_Type                             U32

#define mwv207regAHBXDMA0TotalWrReqRegAddrs                               0x0CB0
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_Address                          0x032C0
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_MSB                                   15
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_LSB                                    0
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_BLK                                    0
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_Count                                  1
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_CNT                                 31:0
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_CNT_End                               31
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_CNT_Start                              0
#define MWV207REG_AHBXDMA0_TOTAL_WR_REQ_CNT_Type                             U32

#define mwv207regAHBXDMA0TotalRdReqRegAddrs                               0x0CB1
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_Address                          0x032C4
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_MSB                                   15
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_LSB                                    0
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_BLK                                    0
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_Count                                  1
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_CNT                                 31:0
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_CNT_End                               31
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_CNT_Start                              0
#define MWV207REG_AHBXDMA0_TOTAL_RD_REQ_CNT_Type                             U32

#define mwv207regAHBXDMA2TotalWrReqRegAddrs                               0x0CB2
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_Address                          0x032C8
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_MSB                                   15
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_LSB                                    0
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_BLK                                    0
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_Count                                  1
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_CNT                                 31:0
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_CNT_End                               31
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_CNT_Start                              0
#define MWV207REG_AHBXDMA2_TOTAL_WR_REQ_CNT_Type                             U32

#define mwv207regAHBXDMA2TotalRdReqRegAddrs                               0x0CB3
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_Address                          0x032CC
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_MSB                                   15
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_LSB                                    0
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_BLK                                    0
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_Count                                  1
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_CNT                                 31:0
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_CNT_End                               31
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_CNT_Start                              0
#define MWV207REG_AHBXDMA2_TOTAL_RD_REQ_CNT_Type                             U32

#define mwv207regAHBXOcmTotalWrReqRegAddrs                                0x0CB4
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_Address                          0x032D0
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_MSB                                   15
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_LSB                                    0
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_BLK                                    0
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_Count                                  1
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_CNT                                 31:0
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_CNT_End                               31
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_CNT_Start                              0
#define MWV207REG_AHBX_OCM_TOTAL_WR_REQ_CNT_Type                             U32

#define mwv207regAHBXOcmTotalRdReqRegAddrs                                0x0CB5
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_Address                          0x032D4
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_MSB                                   15
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_LSB                                    0
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_BLK                                    0
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_Count                                  1
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_WriteMask                     0x00000000
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_ResetValue                    0x00000000

#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_CNT                                 31:0
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_CNT_End                               31
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_CNT_Start                              0
#define MWV207REG_AHBX_OCM_TOTAL_RD_REQ_CNT_Type                             U32

#define mwv207regAHBXSbiToPsiDbg0RegAddrs                                 0x0CB6
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_Address                           0x032D8
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_MSB                                    15
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_LSB                                     0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_BLK                                     0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_Count                                   1
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_FieldMask                      0xFFFFFFFF
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_ReadMask                       0xFFFFFFFF
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_WriteMask                      0x00000000
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_ResetValue                     0x00000000

#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_CNT                                  31:0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_CNT_End                                31
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_CNT_Start                               0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG0_CNT_Type                              U32

#define mwv207regAHBXSbiToPsiDbg1RegAddrs                                 0x0CB7
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_Address                           0x032DC
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_MSB                                    15
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_LSB                                     0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_BLK                                     0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_Count                                   1
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_FieldMask                      0xFFFFFFFF
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_ReadMask                       0xFFFFFFFF
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_WriteMask                      0x00000000
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_ResetValue                     0x00000000

#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_CNT                                  31:0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_CNT_End                                31
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_CNT_Start                               0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG1_CNT_Type                              U32

#define mwv207regAHBXSbiToPsiDbg2RegAddrs                                 0x0CB8
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_Address                           0x032E0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_MSB                                    15
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_LSB                                     0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_BLK                                     0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_Count                                   1
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_FieldMask                      0xFFFFFFFF
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_ReadMask                       0xFFFFFFFF
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_WriteMask                      0x00000000
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_ResetValue                     0x00000000

#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_CNT                                  31:0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_CNT_End                                31
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_CNT_Start                               0
#define MWV207REG_AHBX_SBI_TO_PSI_DBG2_CNT_Type                              U32

#define mwv207regAHBXPsiToSbiDbg0RegAddrs                                 0x0CB9
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_Address                           0x032E4
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_MSB                                    15
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_LSB                                     0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_BLK                                     0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_Count                                   1
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_FieldMask                      0xFFFFFFFF
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_ReadMask                       0xFFFFFFFF
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_WriteMask                      0x00000000
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_ResetValue                     0x00000000

#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_CNT                                  31:0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_CNT_End                                31
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_CNT_Start                               0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG0_CNT_Type                              U32

#define mwv207regAHBXPsiToSbiDbg1RegAddrs                                 0x0CBA
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_Address                           0x032E8
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_MSB                                    15
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_LSB                                     0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_BLK                                     0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_Count                                   1
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_FieldMask                      0xFFFFFFFF
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_ReadMask                       0xFFFFFFFF
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_WriteMask                      0x00000000
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_ResetValue                     0x00000000

#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_CNT                                  31:0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_CNT_End                                31
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_CNT_Start                               0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG1_CNT_Type                              U32

#define mwv207regAHBXPsiToSbiDbg2RegAddrs                                 0x0CBB
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_Address                           0x032EC
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_MSB                                    15
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_LSB                                     0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_BLK                                     0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_Count                                   1
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_FieldMask                      0xFFFFFFFF
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_ReadMask                       0xFFFFFFFF
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_WriteMask                      0x00000000
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_ResetValue                     0x00000000

#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_CNT                                  31:0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_CNT_End                                31
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_CNT_Start                               0
#define MWV207REG_AHBX_PSI_TO_SBI_DBG2_CNT_Type                              U32

#define mwv207regAHBXTransmitterDbg0RegAddrs                              0x0CBC
#define MWV207REG_AHBX_TRANSMITTER_DBG0_Address                          0x032F0
#define MWV207REG_AHBX_TRANSMITTER_DBG0_MSB                                   15
#define MWV207REG_AHBX_TRANSMITTER_DBG0_LSB                                    0
#define MWV207REG_AHBX_TRANSMITTER_DBG0_BLK                                    0
#define MWV207REG_AHBX_TRANSMITTER_DBG0_Count                                  1
#define MWV207REG_AHBX_TRANSMITTER_DBG0_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TRANSMITTER_DBG0_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TRANSMITTER_DBG0_WriteMask                     0x00000000
#define MWV207REG_AHBX_TRANSMITTER_DBG0_ResetValue                    0x00000000

#define MWV207REG_AHBX_TRANSMITTER_DBG0_CNT                                 31:0
#define MWV207REG_AHBX_TRANSMITTER_DBG0_CNT_End                               31
#define MWV207REG_AHBX_TRANSMITTER_DBG0_CNT_Start                              0
#define MWV207REG_AHBX_TRANSMITTER_DBG0_CNT_Type                             U32

#define mwv207regAHBXTransmitterDbg1RegAddrs                              0x0CBD
#define MWV207REG_AHBX_TRANSMITTER_DBG1_Address                          0x032F4
#define MWV207REG_AHBX_TRANSMITTER_DBG1_MSB                                   15
#define MWV207REG_AHBX_TRANSMITTER_DBG1_LSB                                    0
#define MWV207REG_AHBX_TRANSMITTER_DBG1_BLK                                    0
#define MWV207REG_AHBX_TRANSMITTER_DBG1_Count                                  1
#define MWV207REG_AHBX_TRANSMITTER_DBG1_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TRANSMITTER_DBG1_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TRANSMITTER_DBG1_WriteMask                     0x00000000
#define MWV207REG_AHBX_TRANSMITTER_DBG1_ResetValue                    0x00000000

#define MWV207REG_AHBX_TRANSMITTER_DBG1_CNT                                 31:0
#define MWV207REG_AHBX_TRANSMITTER_DBG1_CNT_End                               31
#define MWV207REG_AHBX_TRANSMITTER_DBG1_CNT_Start                              0
#define MWV207REG_AHBX_TRANSMITTER_DBG1_CNT_Type                             U32

#define mwv207regAHBXTransmitterDbg2RegAddrs                              0x0CBE
#define MWV207REG_AHBX_TRANSMITTER_DBG2_Address                          0x032F8
#define MWV207REG_AHBX_TRANSMITTER_DBG2_MSB                                   15
#define MWV207REG_AHBX_TRANSMITTER_DBG2_LSB                                    0
#define MWV207REG_AHBX_TRANSMITTER_DBG2_BLK                                    0
#define MWV207REG_AHBX_TRANSMITTER_DBG2_Count                                  1
#define MWV207REG_AHBX_TRANSMITTER_DBG2_FieldMask                     0xFFFFFFFF
#define MWV207REG_AHBX_TRANSMITTER_DBG2_ReadMask                      0xFFFFFFFF
#define MWV207REG_AHBX_TRANSMITTER_DBG2_WriteMask                     0x00000000
#define MWV207REG_AHBX_TRANSMITTER_DBG2_ResetValue                    0x00000000

#define MWV207REG_AHBX_TRANSMITTER_DBG2_CNT                                 31:0
#define MWV207REG_AHBX_TRANSMITTER_DBG2_CNT_End                               31
#define MWV207REG_AHBX_TRANSMITTER_DBG2_CNT_Start                              0
#define MWV207REG_AHBX_TRANSMITTER_DBG2_CNT_Type                             U32

#define mwv207regAHBXReceiverDbg0RegAddrs                                 0x0CBF
#define MWV207REG_AHBX_RECEIVER_DBG0_Address                             0x032FC
#define MWV207REG_AHBX_RECEIVER_DBG0_MSB                                      15
#define MWV207REG_AHBX_RECEIVER_DBG0_LSB                                       0
#define MWV207REG_AHBX_RECEIVER_DBG0_BLK                                       0
#define MWV207REG_AHBX_RECEIVER_DBG0_Count                                     1
#define MWV207REG_AHBX_RECEIVER_DBG0_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHBX_RECEIVER_DBG0_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHBX_RECEIVER_DBG0_WriteMask                        0x00000000
#define MWV207REG_AHBX_RECEIVER_DBG0_ResetValue                       0x00000000

#define MWV207REG_AHBX_RECEIVER_DBG0_CNT                                    31:0
#define MWV207REG_AHBX_RECEIVER_DBG0_CNT_End                                  31
#define MWV207REG_AHBX_RECEIVER_DBG0_CNT_Start                                 0
#define MWV207REG_AHBX_RECEIVER_DBG0_CNT_Type                                U32

#define mwv207regAHBXReceiverDbg1RegAddrs                                 0x0CC0
#define MWV207REG_AHBX_RECEIVER_DBG1_Address                             0x03300
#define MWV207REG_AHBX_RECEIVER_DBG1_MSB                                      15
#define MWV207REG_AHBX_RECEIVER_DBG1_LSB                                       0
#define MWV207REG_AHBX_RECEIVER_DBG1_BLK                                       0
#define MWV207REG_AHBX_RECEIVER_DBG1_Count                                     1
#define MWV207REG_AHBX_RECEIVER_DBG1_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHBX_RECEIVER_DBG1_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHBX_RECEIVER_DBG1_WriteMask                        0x00000000
#define MWV207REG_AHBX_RECEIVER_DBG1_ResetValue                       0x00000000

#define MWV207REG_AHBX_RECEIVER_DBG1_CNT                                    31:0
#define MWV207REG_AHBX_RECEIVER_DBG1_CNT_End                                  31
#define MWV207REG_AHBX_RECEIVER_DBG1_CNT_Start                                 0
#define MWV207REG_AHBX_RECEIVER_DBG1_CNT_Type                                U32

#define mwv207regAHBXReceiverDbg2RegAddrs                                 0x0CC1
#define MWV207REG_AHBX_RECEIVER_DBG2_Address                             0x03304
#define MWV207REG_AHBX_RECEIVER_DBG2_MSB                                      15
#define MWV207REG_AHBX_RECEIVER_DBG2_LSB                                       0
#define MWV207REG_AHBX_RECEIVER_DBG2_BLK                                       0
#define MWV207REG_AHBX_RECEIVER_DBG2_Count                                     1
#define MWV207REG_AHBX_RECEIVER_DBG2_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHBX_RECEIVER_DBG2_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHBX_RECEIVER_DBG2_WriteMask                        0x00000000
#define MWV207REG_AHBX_RECEIVER_DBG2_ResetValue                       0x00000000

#define MWV207REG_AHBX_RECEIVER_DBG2_CNT                                    31:0
#define MWV207REG_AHBX_RECEIVER_DBG2_CNT_End                                  31
#define MWV207REG_AHBX_RECEIVER_DBG2_CNT_Start                                 0
#define MWV207REG_AHBX_RECEIVER_DBG2_CNT_Type                                U32

#define mwv207regAHBXDMA0Dbg0RegAddrs                                     0x0CC2
#define MWV207REG_AHBXDMA0_DBG0_Address                                  0x03308
#define MWV207REG_AHBXDMA0_DBG0_MSB                                           15
#define MWV207REG_AHBXDMA0_DBG0_LSB                                            0
#define MWV207REG_AHBXDMA0_DBG0_BLK                                            0
#define MWV207REG_AHBXDMA0_DBG0_Count                                          1
#define MWV207REG_AHBXDMA0_DBG0_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA0_DBG0_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA0_DBG0_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA0_DBG0_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA0_DBG0_CNT                                         31:0
#define MWV207REG_AHBXDMA0_DBG0_CNT_End                                       31
#define MWV207REG_AHBXDMA0_DBG0_CNT_Start                                      0
#define MWV207REG_AHBXDMA0_DBG0_CNT_Type                                     U32

#define mwv207regAHBXDMA0Dbg1RegAddrs                                     0x0CC3
#define MWV207REG_AHBXDMA0_DBG1_Address                                  0x0330C
#define MWV207REG_AHBXDMA0_DBG1_MSB                                           15
#define MWV207REG_AHBXDMA0_DBG1_LSB                                            0
#define MWV207REG_AHBXDMA0_DBG1_BLK                                            0
#define MWV207REG_AHBXDMA0_DBG1_Count                                          1
#define MWV207REG_AHBXDMA0_DBG1_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA0_DBG1_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA0_DBG1_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA0_DBG1_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA0_DBG1_CNT                                         31:0
#define MWV207REG_AHBXDMA0_DBG1_CNT_End                                       31
#define MWV207REG_AHBXDMA0_DBG1_CNT_Start                                      0
#define MWV207REG_AHBXDMA0_DBG1_CNT_Type                                     U32

#define mwv207regAHBXDMA0Dbg2RegAddrs                                     0x0CC4
#define MWV207REG_AHBXDMA0_DBG2_Address                                  0x03310
#define MWV207REG_AHBXDMA0_DBG2_MSB                                           15
#define MWV207REG_AHBXDMA0_DBG2_LSB                                            0
#define MWV207REG_AHBXDMA0_DBG2_BLK                                            0
#define MWV207REG_AHBXDMA0_DBG2_Count                                          1
#define MWV207REG_AHBXDMA0_DBG2_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA0_DBG2_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA0_DBG2_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA0_DBG2_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA0_DBG2_CNT                                         31:0
#define MWV207REG_AHBXDMA0_DBG2_CNT_End                                       31
#define MWV207REG_AHBXDMA0_DBG2_CNT_Start                                      0
#define MWV207REG_AHBXDMA0_DBG2_CNT_Type                                     U32

#define mwv207regAHBXDMA1Dbg0RegAddrs                                     0x0CC5
#define MWV207REG_AHBXDMA1_DBG0_Address                                  0x03314
#define MWV207REG_AHBXDMA1_DBG0_MSB                                           15
#define MWV207REG_AHBXDMA1_DBG0_LSB                                            0
#define MWV207REG_AHBXDMA1_DBG0_BLK                                            0
#define MWV207REG_AHBXDMA1_DBG0_Count                                          1
#define MWV207REG_AHBXDMA1_DBG0_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA1_DBG0_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA1_DBG0_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA1_DBG0_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA1_DBG0_CNT                                         31:0
#define MWV207REG_AHBXDMA1_DBG0_CNT_End                                       31
#define MWV207REG_AHBXDMA1_DBG0_CNT_Start                                      0
#define MWV207REG_AHBXDMA1_DBG0_CNT_Type                                     U32

#define mwv207regAHBXDMA1Dbg1RegAddrs                                     0x0CC6
#define MWV207REG_AHBXDMA1_DBG1_Address                                  0x03318
#define MWV207REG_AHBXDMA1_DBG1_MSB                                           15
#define MWV207REG_AHBXDMA1_DBG1_LSB                                            0
#define MWV207REG_AHBXDMA1_DBG1_BLK                                            0
#define MWV207REG_AHBXDMA1_DBG1_Count                                          1
#define MWV207REG_AHBXDMA1_DBG1_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA1_DBG1_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA1_DBG1_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA1_DBG1_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA1_DBG1_CNT                                         31:0
#define MWV207REG_AHBXDMA1_DBG1_CNT_End                                       31
#define MWV207REG_AHBXDMA1_DBG1_CNT_Start                                      0
#define MWV207REG_AHBXDMA1_DBG1_CNT_Type                                     U32

#define mwv207regAHBXDMA1Dbg2RegAddrs                                     0x0CC7
#define MWV207REG_AHBXDMA1_DBG2_Address                                  0x0331C
#define MWV207REG_AHBXDMA1_DBG2_MSB                                           15
#define MWV207REG_AHBXDMA1_DBG2_LSB                                            0
#define MWV207REG_AHBXDMA1_DBG2_BLK                                            0
#define MWV207REG_AHBXDMA1_DBG2_Count                                          1
#define MWV207REG_AHBXDMA1_DBG2_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA1_DBG2_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA1_DBG2_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA1_DBG2_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA1_DBG2_CNT                                         31:0
#define MWV207REG_AHBXDMA1_DBG2_CNT_End                                       31
#define MWV207REG_AHBXDMA1_DBG2_CNT_Start                                      0
#define MWV207REG_AHBXDMA1_DBG2_CNT_Type                                     U32

#define mwv207regAHBXDMA2Dbg0RegAddrs                                     0x0CC8
#define MWV207REG_AHBXDMA2_DBG0_Address                                  0x03320
#define MWV207REG_AHBXDMA2_DBG0_MSB                                           15
#define MWV207REG_AHBXDMA2_DBG0_LSB                                            0
#define MWV207REG_AHBXDMA2_DBG0_BLK                                            0
#define MWV207REG_AHBXDMA2_DBG0_Count                                          1
#define MWV207REG_AHBXDMA2_DBG0_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA2_DBG0_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA2_DBG0_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA2_DBG0_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA2_DBG0_CNT                                         31:0
#define MWV207REG_AHBXDMA2_DBG0_CNT_End                                       31
#define MWV207REG_AHBXDMA2_DBG0_CNT_Start                                      0
#define MWV207REG_AHBXDMA2_DBG0_CNT_Type                                     U32

#define mwv207regAHBXDMA2Dbg1RegAddrs                                     0x0CC9
#define MWV207REG_AHBXDMA2_DBG1_Address                                  0x03324
#define MWV207REG_AHBXDMA2_DBG1_MSB                                           15
#define MWV207REG_AHBXDMA2_DBG1_LSB                                            0
#define MWV207REG_AHBXDMA2_DBG1_BLK                                            0
#define MWV207REG_AHBXDMA2_DBG1_Count                                          1
#define MWV207REG_AHBXDMA2_DBG1_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA2_DBG1_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA2_DBG1_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA2_DBG1_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA2_DBG1_CNT                                         31:0
#define MWV207REG_AHBXDMA2_DBG1_CNT_End                                       31
#define MWV207REG_AHBXDMA2_DBG1_CNT_Start                                      0
#define MWV207REG_AHBXDMA2_DBG1_CNT_Type                                     U32

#define mwv207regAHBXDMA2Dbg2RegAddrs                                     0x0CCA
#define MWV207REG_AHBXDMA2_DBG2_Address                                  0x03328
#define MWV207REG_AHBXDMA2_DBG2_MSB                                           15
#define MWV207REG_AHBXDMA2_DBG2_LSB                                            0
#define MWV207REG_AHBXDMA2_DBG2_BLK                                            0
#define MWV207REG_AHBXDMA2_DBG2_Count                                          1
#define MWV207REG_AHBXDMA2_DBG2_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA2_DBG2_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA2_DBG2_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA2_DBG2_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA2_DBG2_CNT                                         31:0
#define MWV207REG_AHBXDMA2_DBG2_CNT_End                                       31
#define MWV207REG_AHBXDMA2_DBG2_CNT_Start                                      0
#define MWV207REG_AHBXDMA2_DBG2_CNT_Type                                     U32

#define mwv207regAHBXDMA3Dbg0RegAddrs                                     0x0CCB
#define MWV207REG_AHBXDMA3_DBG0_Address                                  0x0332C
#define MWV207REG_AHBXDMA3_DBG0_MSB                                           15
#define MWV207REG_AHBXDMA3_DBG0_LSB                                            0
#define MWV207REG_AHBXDMA3_DBG0_BLK                                            0
#define MWV207REG_AHBXDMA3_DBG0_Count                                          1
#define MWV207REG_AHBXDMA3_DBG0_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA3_DBG0_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA3_DBG0_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA3_DBG0_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA3_DBG0_CNT                                         31:0
#define MWV207REG_AHBXDMA3_DBG0_CNT_End                                       31
#define MWV207REG_AHBXDMA3_DBG0_CNT_Start                                      0
#define MWV207REG_AHBXDMA3_DBG0_CNT_Type                                     U32

#define mwv207regAHBXDMA3Dbg1RegAddrs                                     0x0CCC
#define MWV207REG_AHBXDMA3_DBG1_Address                                  0x03330
#define MWV207REG_AHBXDMA3_DBG1_MSB                                           15
#define MWV207REG_AHBXDMA3_DBG1_LSB                                            0
#define MWV207REG_AHBXDMA3_DBG1_BLK                                            0
#define MWV207REG_AHBXDMA3_DBG1_Count                                          1
#define MWV207REG_AHBXDMA3_DBG1_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA3_DBG1_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA3_DBG1_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA3_DBG1_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA3_DBG1_CNT                                         31:0
#define MWV207REG_AHBXDMA3_DBG1_CNT_End                                       31
#define MWV207REG_AHBXDMA3_DBG1_CNT_Start                                      0
#define MWV207REG_AHBXDMA3_DBG1_CNT_Type                                     U32

#define mwv207regAHBXDMA3Dbg2RegAddrs                                     0x0CCD
#define MWV207REG_AHBXDMA3_DBG2_Address                                  0x03334
#define MWV207REG_AHBXDMA3_DBG2_MSB                                           15
#define MWV207REG_AHBXDMA3_DBG2_LSB                                            0
#define MWV207REG_AHBXDMA3_DBG2_BLK                                            0
#define MWV207REG_AHBXDMA3_DBG2_Count                                          1
#define MWV207REG_AHBXDMA3_DBG2_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA3_DBG2_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA3_DBG2_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA3_DBG2_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA3_DBG2_CNT                                         31:0
#define MWV207REG_AHBXDMA3_DBG2_CNT_End                                       31
#define MWV207REG_AHBXDMA3_DBG2_CNT_Start                                      0
#define MWV207REG_AHBXDMA3_DBG2_CNT_Type                                     U32

#define mwv207regAHBXDMA4Dbg0RegAddrs                                     0x0CCE
#define MWV207REG_AHBXDMA4_DBG0_Address                                  0x03338
#define MWV207REG_AHBXDMA4_DBG0_MSB                                           15
#define MWV207REG_AHBXDMA4_DBG0_LSB                                            0
#define MWV207REG_AHBXDMA4_DBG0_BLK                                            0
#define MWV207REG_AHBXDMA4_DBG0_Count                                          1
#define MWV207REG_AHBXDMA4_DBG0_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA4_DBG0_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA4_DBG0_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA4_DBG0_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA4_DBG0_CNT                                         31:0
#define MWV207REG_AHBXDMA4_DBG0_CNT_End                                       31
#define MWV207REG_AHBXDMA4_DBG0_CNT_Start                                      0
#define MWV207REG_AHBXDMA4_DBG0_CNT_Type                                     U32

#define mwv207regAHBXDMA4Dbg1RegAddrs                                     0x0CCF
#define MWV207REG_AHBXDMA4_DBG1_Address                                  0x0333C
#define MWV207REG_AHBXDMA4_DBG1_MSB                                           15
#define MWV207REG_AHBXDMA4_DBG1_LSB                                            0
#define MWV207REG_AHBXDMA4_DBG1_BLK                                            0
#define MWV207REG_AHBXDMA4_DBG1_Count                                          1
#define MWV207REG_AHBXDMA4_DBG1_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA4_DBG1_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA4_DBG1_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA4_DBG1_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA4_DBG1_CNT                                         31:0
#define MWV207REG_AHBXDMA4_DBG1_CNT_End                                       31
#define MWV207REG_AHBXDMA4_DBG1_CNT_Start                                      0
#define MWV207REG_AHBXDMA4_DBG1_CNT_Type                                     U32

#define mwv207regAHBXDMA4Dbg2RegAddrs                                     0x0CD0
#define MWV207REG_AHBXDMA4_DBG2_Address                                  0x03340
#define MWV207REG_AHBXDMA4_DBG2_MSB                                           15
#define MWV207REG_AHBXDMA4_DBG2_LSB                                            0
#define MWV207REG_AHBXDMA4_DBG2_BLK                                            0
#define MWV207REG_AHBXDMA4_DBG2_Count                                          1
#define MWV207REG_AHBXDMA4_DBG2_FieldMask                             0xFFFFFFFF
#define MWV207REG_AHBXDMA4_DBG2_ReadMask                              0xFFFFFFFF
#define MWV207REG_AHBXDMA4_DBG2_WriteMask                             0x00000000
#define MWV207REG_AHBXDMA4_DBG2_ResetValue                            0x00000000

#define MWV207REG_AHBXDMA4_DBG2_CNT                                         31:0
#define MWV207REG_AHBXDMA4_DBG2_CNT_End                                       31
#define MWV207REG_AHBXDMA4_DBG2_CNT_Start                                      0
#define MWV207REG_AHBXDMA4_DBG2_CNT_Type                                     U32



#define MWV207REG_TTDMA_DEFINE                                               4:0
#define MWV207REG_TTDMA_DEFINE_End                                             4
#define MWV207REG_TTDMA_DEFINE_Start                                           0
#define MWV207REG_TTDMA_DEFINE_Type                                          U05
#define   MWV207REG_TTDMA_DEFINE_PSIIN0_DMA0                                0x00
#define   MWV207REG_TTDMA_DEFINE_PSIIN1_DMA1                                0x01
#define   MWV207REG_TTDMA_DEFINE_PSIOUT0_DMA2                               0x02
#define   MWV207REG_TTDMA_DEFINE_PSIOUT1_DMA3                               0x03
#define   MWV207REG_TTDMA_DEFINE_PSIOUT2_DMA4                               0x04
#define   MWV207REG_TTDMA_DEFINE_SBI2PSI_DMA5                               0x05
#define   MWV207REG_TTDMA_DEFINE_REFIN_DMA6                                 0x06
#define   MWV207REG_TTDMA_DEFINE_PSI2SBI_DMA7                               0x07
#define   MWV207REG_TTDMA_DEFINE_REFOUT_DMA8                                0x08
#define   MWV207REG_TTDMA_DEFINE_PSI2SBI_DMA9                               0x09
#define   MWV207REG_TTDMA_DEFINE_SBI2PSI_DMA10                              0x0A



#define MWV207REG_TTDMA_WORD0_MEM_TENSOR_XSIZE                              31:0
#define MWV207REG_TTDMA_WORD0_MEM_TENSOR_XSIZE_End                            31
#define MWV207REG_TTDMA_WORD0_MEM_TENSOR_XSIZE_Start                           0
#define MWV207REG_TTDMA_WORD0_MEM_TENSOR_XSIZE_Type                          U32



#define MWV207REG_TTDMA_WORD1_MEM_TENSOR_YSIZE                              31:0
#define MWV207REG_TTDMA_WORD1_MEM_TENSOR_YSIZE_End                            31
#define MWV207REG_TTDMA_WORD1_MEM_TENSOR_YSIZE_Start                           0
#define MWV207REG_TTDMA_WORD1_MEM_TENSOR_YSIZE_Type                          U32



#define MWV207REG_TTDMA_WORD2_MEM_TENSOR_ZSIZE                              31:0
#define MWV207REG_TTDMA_WORD2_MEM_TENSOR_ZSIZE_End                            31
#define MWV207REG_TTDMA_WORD2_MEM_TENSOR_ZSIZE_Start                           0
#define MWV207REG_TTDMA_WORD2_MEM_TENSOR_ZSIZE_Type                          U32



#define MWV207REG_TTDMA_WORD3_MEM_TENSOR_XSTRIDE                            31:0
#define MWV207REG_TTDMA_WORD3_MEM_TENSOR_XSTRIDE_End                          31
#define MWV207REG_TTDMA_WORD3_MEM_TENSOR_XSTRIDE_Start                         0
#define MWV207REG_TTDMA_WORD3_MEM_TENSOR_XSTRIDE_Type                        U32



#define MWV207REG_TTDMA_WORD4_MEM_TENSOR_SLICE                              31:0
#define MWV207REG_TTDMA_WORD4_MEM_TENSOR_SLICE_End                            31
#define MWV207REG_TTDMA_WORD4_MEM_TENSOR_SLICE_Start                           0
#define MWV207REG_TTDMA_WORD4_MEM_TENSOR_SLICE_Type                          U32



#define MWV207REG_TTDMA_WORD5_MEM_TENSOR_YSTRIDE                            31:0
#define MWV207REG_TTDMA_WORD5_MEM_TENSOR_YSTRIDE_End                          31
#define MWV207REG_TTDMA_WORD5_MEM_TENSOR_YSTRIDE_Start                         0
#define MWV207REG_TTDMA_WORD5_MEM_TENSOR_YSTRIDE_Type                        U32


#define MWV207REG_TTDMA_WORD6_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT31_TO0  31:0
#define MWV207REG_TTDMA_WORD6_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT31_TO0_End 31
#define MWV207REG_TTDMA_WORD6_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT31_TO0_Start 0
#define MWV207REG_TTDMA_WORD6_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT31_TO0_Type U32



#define MWV207REG_TTDMA_WORD7_MEM_TENSOR_CIRCULAR_BUF_SIZE                  31:0
#define MWV207REG_TTDMA_WORD7_MEM_TENSOR_CIRCULAR_BUF_SIZE_End                31
#define MWV207REG_TTDMA_WORD7_MEM_TENSOR_CIRCULAR_BUF_SIZE_Start               0
#define MWV207REG_TTDMA_WORD7_MEM_TENSOR_CIRCULAR_BUF_SIZE_Type              U32



#define MWV207REG_TTDMA_WORD8_WR_SUBTENSOR_XSIZE                            31:0
#define MWV207REG_TTDMA_WORD8_WR_SUBTENSOR_XSIZE_End                          31
#define MWV207REG_TTDMA_WORD8_WR_SUBTENSOR_XSIZE_Start                         0
#define MWV207REG_TTDMA_WORD8_WR_SUBTENSOR_XSIZE_Type                        U32



#define MWV207REG_TTDMA_WORD9_WR_SUBTENSOR_YSIZE                            31:0
#define MWV207REG_TTDMA_WORD9_WR_SUBTENSOR_YSIZE_End                          31
#define MWV207REG_TTDMA_WORD9_WR_SUBTENSOR_YSIZE_Start                         0
#define MWV207REG_TTDMA_WORD9_WR_SUBTENSOR_YSIZE_Type                        U32



#define MWV207REG_TTDMA_WORD10_WR_SUBTENSOR_ZSIZE                           31:0
#define MWV207REG_TTDMA_WORD10_WR_SUBTENSOR_ZSIZE_End                         31
#define MWV207REG_TTDMA_WORD10_WR_SUBTENSOR_ZSIZE_Start                        0
#define MWV207REG_TTDMA_WORD10_WR_SUBTENSOR_ZSIZE_Type                       U32



#define MWV207REG_TTDMA_WORD11_WR_SUBTENSOR_INIT_XSIZE                      31:0
#define MWV207REG_TTDMA_WORD11_WR_SUBTENSOR_INIT_XSIZE_End                    31
#define MWV207REG_TTDMA_WORD11_WR_SUBTENSOR_INIT_XSIZE_Start                   0
#define MWV207REG_TTDMA_WORD11_WR_SUBTENSOR_INIT_XSIZE_Type                  U32



#define MWV207REG_TTDMA_WORD12_WR_SUBTENSOR_INIT_YSIZE                      31:0
#define MWV207REG_TTDMA_WORD12_WR_SUBTENSOR_INIT_YSIZE_End                    31
#define MWV207REG_TTDMA_WORD12_WR_SUBTENSOR_INIT_YSIZE_Start                   0
#define MWV207REG_TTDMA_WORD12_WR_SUBTENSOR_INIT_YSIZE_Type                  U32



#define MWV207REG_TTDMA_WORD13_WR_SUBTENSOR_INIT_ZSIZE                      31:0
#define MWV207REG_TTDMA_WORD13_WR_SUBTENSOR_INIT_ZSIZE_End                    31
#define MWV207REG_TTDMA_WORD13_WR_SUBTENSOR_INIT_ZSIZE_Start                   0
#define MWV207REG_TTDMA_WORD13_WR_SUBTENSOR_INIT_ZSIZE_Type                  U32



#define MWV207REG_TTDMA_WORD14_RD_SUBTENSOR_XSIZE                           31:0
#define MWV207REG_TTDMA_WORD14_RD_SUBTENSOR_XSIZE_End                         31
#define MWV207REG_TTDMA_WORD14_RD_SUBTENSOR_XSIZE_Start                        0
#define MWV207REG_TTDMA_WORD14_RD_SUBTENSOR_XSIZE_Type                       U32



#define MWV207REG_TTDMA_WORD15_RD_SUBTENSOR_YSIZE                           31:0
#define MWV207REG_TTDMA_WORD15_RD_SUBTENSOR_YSIZE_End                         31
#define MWV207REG_TTDMA_WORD15_RD_SUBTENSOR_YSIZE_Start                        0
#define MWV207REG_TTDMA_WORD15_RD_SUBTENSOR_YSIZE_Type                       U32



#define MWV207REG_TTDMA_WORD16_RD_SUBTENSOR_ZSIZE                           31:0
#define MWV207REG_TTDMA_WORD16_RD_SUBTENSOR_ZSIZE_End                         31
#define MWV207REG_TTDMA_WORD16_RD_SUBTENSOR_ZSIZE_Start                        0
#define MWV207REG_TTDMA_WORD16_RD_SUBTENSOR_ZSIZE_Type                       U32



#define MWV207REG_TTDMA_WORD17_RD_SUBTENSOR_INIT_XSIZE                      31:0
#define MWV207REG_TTDMA_WORD17_RD_SUBTENSOR_INIT_XSIZE_End                    31
#define MWV207REG_TTDMA_WORD17_RD_SUBTENSOR_INIT_XSIZE_Start                   0
#define MWV207REG_TTDMA_WORD17_RD_SUBTENSOR_INIT_XSIZE_Type                  U32



#define MWV207REG_TTDMA_WORD18_RD_SUBTENSOR_INIT_YSIZE                      31:0
#define MWV207REG_TTDMA_WORD18_RD_SUBTENSOR_INIT_YSIZE_End                    31
#define MWV207REG_TTDMA_WORD18_RD_SUBTENSOR_INIT_YSIZE_Start                   0
#define MWV207REG_TTDMA_WORD18_RD_SUBTENSOR_INIT_YSIZE_Type                  U32



#define MWV207REG_TTDMA_WORD19_RD_SUBTENSOR_INIT_ZSIZE                      31:0
#define MWV207REG_TTDMA_WORD19_RD_SUBTENSOR_INIT_ZSIZE_End                    31
#define MWV207REG_TTDMA_WORD19_RD_SUBTENSOR_INIT_ZSIZE_Start                   0
#define MWV207REG_TTDMA_WORD19_RD_SUBTENSOR_INIT_ZSIZE_Type                  U32



#define MWV207REG_TTDMA_WORD20_RD_SUBTENSOR_YINC                            31:0
#define MWV207REG_TTDMA_WORD20_RD_SUBTENSOR_YINC_End                          31
#define MWV207REG_TTDMA_WORD20_RD_SUBTENSOR_YINC_Start                         0
#define MWV207REG_TTDMA_WORD20_RD_SUBTENSOR_YINC_Type                        U32



#define MWV207REG_TTDMA_WORD21_WORD_SIZE_MINUS_ONE                           2:0
#define MWV207REG_TTDMA_WORD21_WORD_SIZE_MINUS_ONE_End                         2
#define MWV207REG_TTDMA_WORD21_WORD_SIZE_MINUS_ONE_Start                       0
#define MWV207REG_TTDMA_WORD21_WORD_SIZE_MINUS_ONE_Type                      U03


#define MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER                               5:3
#define MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_End                             5
#define MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_Start                           3
#define MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_Type                          U03
#define   MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_XYZ                         0x0
#define   MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_XZY                         0x1
#define   MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_YXZ                         0x2
#define   MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_YZX                         0x3
#define   MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_ZXY                         0x4
#define   MWV207REG_TTDMA_WORD21_SUBTENSOR_ORDER_ZYX                         0x5


#define MWV207REG_TTDMA_WORD21_WR_SUBTENSOR_ODD_FRAME                        6:6
#define MWV207REG_TTDMA_WORD21_WR_SUBTENSOR_ODD_FRAME_End                      6
#define MWV207REG_TTDMA_WORD21_WR_SUBTENSOR_ODD_FRAME_Start                    6
#define MWV207REG_TTDMA_WORD21_WR_SUBTENSOR_ODD_FRAME_Type                   U01
#define   MWV207REG_TTDMA_WORD21_WR_SUBTENSOR_ODD_FRAME_START_FROM_EVEN      0x0
#define   MWV207REG_TTDMA_WORD21_WR_SUBTENSOR_ODD_FRAME_START_FROM_ODD       0x1


#define MWV207REG_TTDMA_WORD21_RD_SUBTENSOR_ODD_FRAME                        7:7
#define MWV207REG_TTDMA_WORD21_RD_SUBTENSOR_ODD_FRAME_End                      7
#define MWV207REG_TTDMA_WORD21_RD_SUBTENSOR_ODD_FRAME_Start                    7
#define MWV207REG_TTDMA_WORD21_RD_SUBTENSOR_ODD_FRAME_Type                   U01
#define   MWV207REG_TTDMA_WORD21_RD_SUBTENSOR_ODD_FRAME_START_FROM_EVEN      0x0
#define   MWV207REG_TTDMA_WORD21_RD_SUBTENSOR_ODD_FRAME_START_FROM_ODD       0x1

#define MWV207REG_TTDMA_WORD21_GENERATE_SYNC_ERROR                           8:8
#define MWV207REG_TTDMA_WORD21_GENERATE_SYNC_ERROR_End                         8
#define MWV207REG_TTDMA_WORD21_GENERATE_SYNC_ERROR_Start                       8
#define MWV207REG_TTDMA_WORD21_GENERATE_SYNC_ERROR_Type                      U01
#define   MWV207REG_TTDMA_WORD21_GENERATE_SYNC_ERROR_IGNORE                  0x0
#define   MWV207REG_TTDMA_WORD21_GENERATE_SYNC_ERROR_GENERATE                0x1


#define MWV207REG_TTDMA_WORD21_MEMORY_ACCESS                                10:9
#define MWV207REG_TTDMA_WORD21_MEMORY_ACCESS_End                              10
#define MWV207REG_TTDMA_WORD21_MEMORY_ACCESS_Start                             9
#define MWV207REG_TTDMA_WORD21_MEMORY_ACCESS_Type                            U02
#define   MWV207REG_TTDMA_WORD21_MEMORY_ACCESS_ENABLE                        0x0

#define   MWV207REG_TTDMA_WORD21_MEMORY_ACCESS_DISABLE_AND_SYNC              0x1
#define   MWV207REG_TTDMA_WORD21_MEMORY_ACCESS_DISABLE_AND_ZERO              0x2


#define MWV207REG_TTDMA_WORD21_WALKING_START_CONTROL                       12:11
#define MWV207REG_TTDMA_WORD21_WALKING_START_CONTROL_End                      12
#define MWV207REG_TTDMA_WORD21_WALKING_START_CONTROL_Start                    11
#define MWV207REG_TTDMA_WORD21_WALKING_START_CONTROL_Type                    U02
#define   MWV207REG_TTDMA_WORD21_WALKING_START_CONTROL_NO_START              0x0
#define   MWV207REG_TTDMA_WORD21_WALKING_START_CONTROL_START_ONE_FRAME       0x1
#define   MWV207REG_TTDMA_WORD21_WALKING_START_CONTROL_CONTINUOUS_START      0x2

#define MWV207REG_TTDMA_WORD21_FRAME_START_SELECT                          13:13
#define MWV207REG_TTDMA_WORD21_FRAME_START_SELECT_End                         13
#define MWV207REG_TTDMA_WORD21_FRAME_START_SELECT_Start                       13
#define MWV207REG_TTDMA_WORD21_FRAME_START_SELECT_Type                       U01
#define   MWV207REG_TTDMA_WORD21_FRAME_START_SELECT_HARDWARE                 0x0
#define   MWV207REG_TTDMA_WORD21_FRAME_START_SELECT_SOFT_WARE                0x1

#define MWV207REG_TTDMA_WORD21_IMPROPER_FRAME_START                        14:14
#define MWV207REG_TTDMA_WORD21_IMPROPER_FRAME_START_End                       14
#define MWV207REG_TTDMA_WORD21_IMPROPER_FRAME_START_Start                     14
#define MWV207REG_TTDMA_WORD21_IMPROPER_FRAME_START_Type                     U01


#define MWV207REG_TTDMA_WORD21_NON_THROTTLING_MODE                         15:15
#define MWV207REG_TTDMA_WORD21_NON_THROTTLING_MODE_End                        15
#define MWV207REG_TTDMA_WORD21_NON_THROTTLING_MODE_Start                      15
#define MWV207REG_TTDMA_WORD21_NON_THROTTLING_MODE_Type                      U01
#define   MWV207REG_TTDMA_WORD21_NON_THROTTLING_MODE_THROTTLING_MODE         0x0
#define   MWV207REG_TTDMA_WORD21_NON_THROTTLING_MODE_NON_THROTTLING_MODE     0x1

#define MWV207REG_TTDMA_WORD21_FREE_RUN_CONTROL                            16:16
#define MWV207REG_TTDMA_WORD21_FREE_RUN_CONTROL_End                           16
#define MWV207REG_TTDMA_WORD21_FREE_RUN_CONTROL_Start                         16
#define MWV207REG_TTDMA_WORD21_FREE_RUN_CONTROL_Type                         U01

#define MWV207REG_TTDMA_WORD21_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT33_TO32 18:17
#define MWV207REG_TTDMA_WORD21_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT33_TO32_End 18
#define MWV207REG_TTDMA_WORD21_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT33_TO32_Start 17
#define MWV207REG_TTDMA_WORD21_MWV207REG_MEM_TENSOR_CIRC_BUF_ADDR_BIT33_TO32_Type U02

#define MWV207REG_TTDMA_WORD21_MEM_TENSOR_BASE_ADDR_BIT28_TO16             31:19
#define MWV207REG_TTDMA_WORD21_MEM_TENSOR_BASE_ADDR_BIT28_TO16_End            31
#define MWV207REG_TTDMA_WORD21_MEM_TENSOR_BASE_ADDR_BIT28_TO16_Start          19
#define MWV207REG_TTDMA_WORD21_MEM_TENSOR_BASE_ADDR_BIT28_TO16_Type          U13


#define MWV207REG_TTDMA_WORD22_MEMORY_ACCESS_RATE_CONTROL                   15:0
#define MWV207REG_TTDMA_WORD22_MEMORY_ACCESS_RATE_CONTROL_End                 15
#define MWV207REG_TTDMA_WORD22_MEMORY_ACCESS_RATE_CONTROL_Start                0
#define MWV207REG_TTDMA_WORD22_MEMORY_ACCESS_RATE_CONTROL_Type               U16

#define MWV207REG_TTDMA_WORD22_MEM_TENSOR_BASE_ADDR_BIT15_TO0              31:16
#define MWV207REG_TTDMA_WORD22_MEM_TENSOR_BASE_ADDR_BIT15_TO0_End             31
#define MWV207REG_TTDMA_WORD22_MEM_TENSOR_BASE_ADDR_BIT15_TO0_Start           16
#define MWV207REG_TTDMA_WORD22_MEM_TENSOR_BASE_ADDR_BIT15_TO0_Type           U16



#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_LENGTH                      15:0
#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_LENGTH_End                    15
#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_LENGTH_Start                   0
#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_LENGTH_Type                  U16

#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_START                      31:16
#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_START_End                     31
#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_START_Start                   16
#define MWV207REG_TTDMA_WORD23_PSI_IN_EXTRACTOR_START_Type                   U16



#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_END                         15:0
#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_END_End                       15
#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_END_Start                      0
#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_END_Type                     U16

#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_BORDER_CONSTANT            31:16
#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_BORDER_CONSTANT_End           31
#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_BORDER_CONSTANT_Start         16
#define MWV207REG_TTDMA_WORD24_PSI_IN_EXTRACTOR_BORDER_CONSTANT_Type         U16


#define MWV207REG_TTDMA_WORD25_PSI_IN_DATA_TYPE                              0:0
#define MWV207REG_TTDMA_WORD25_PSI_IN_DATA_TYPE_End                            0
#define MWV207REG_TTDMA_WORD25_PSI_IN_DATA_TYPE_Start                          0
#define MWV207REG_TTDMA_WORD25_PSI_IN_DATA_TYPE_Type                         U01
#define   MWV207REG_TTDMA_WORD25_PSI_IN_DATA_TYPE_EIGHT_BITS                 0x0
#define   MWV207REG_TTDMA_WORD25_PSI_IN_DATA_TYPE_SIXTEEN_BITS               0x1

#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_LEFT_PAD                     6:1
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_LEFT_PAD_End                   6
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_LEFT_PAD_Start                 1
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_LEFT_PAD_Type                U06

#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_RIGHT_PAD                   12:7
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_RIGHT_PAD_End                 12
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_RIGHT_PAD_Start                7
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_RIGHT_PAD_Type               U06


#define MWV207REG_TTDMA_WORD25_PSI_IN_TRANSPOSE_CH_MINUS_ONE               15:13
#define MWV207REG_TTDMA_WORD25_PSI_IN_TRANSPOSE_CH_MINUS_ONE_End              15
#define MWV207REG_TTDMA_WORD25_PSI_IN_TRANSPOSE_CH_MINUS_ONE_Start            13
#define MWV207REG_TTDMA_WORD25_PSI_IN_TRANSPOSE_CH_MINUS_ONE_Type            U03

#define MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID                     18:16
#define MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_End                    18
#define MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_Start                  16
#define MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_Type                  U03
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_NN                  0x0
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_PSI_OUT0            0x1
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_PSI_OUT1            0x2
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_PSI_OUT2            0x3
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_PSI_OUT3            0x4
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_PSI_OUT4            0x5
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_PSI_OUT5            0x6
#define   MWV207REG_TTDMA_WORD25_PSI_IN_RD_COMMIT_OUT_ID_PSI_OUT6            0x7


#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_BORDER_STYLE               19:19
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_BORDER_STYLE_End              19
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_BORDER_STYLE_Start            19
#define MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_BORDER_STYLE_Type            U01
#define   MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_BORDER_STYLE_BORDER_CONST  0x0
#define   MWV207REG_TTDMA_WORD25_PSI_IN_EXTRACTOR_BORDER_STYLE_NEAREST_EDGE  0x1

#define MWV207REG_TTDMA_WORD25_RD_SUBTENSOR_COUNT_BIT11_TO0                31:20
#define MWV207REG_TTDMA_WORD25_RD_SUBTENSOR_COUNT_BIT11_TO0_End               31
#define MWV207REG_TTDMA_WORD25_RD_SUBTENSOR_COUNT_BIT11_TO0_Start             20
#define MWV207REG_TTDMA_WORD25_RD_SUBTENSOR_COUNT_BIT11_TO0_Type             U12



#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_LENGTH                        15:0
#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_LENGTH_End                      15
#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_LENGTH_Start                     0
#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_LENGTH_Type                    U16


#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_START                        31:16
#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_START_End                       31
#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_START_Start                     16
#define MWV207REG_TTDMA_WORD26_PSI_OUT_FILLER_START_Type                     U16



#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_END                           15:0
#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_END_End                         15
#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_END_Start                        0
#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_END_Type                       U16

#define MWV207REG_TTDMA_WORD27_PSI_OUT_DATA_TYPE                           16:16
#define MWV207REG_TTDMA_WORD27_PSI_OUT_DATA_TYPE_End                          16
#define MWV207REG_TTDMA_WORD27_PSI_OUT_DATA_TYPE_Start                        16
#define MWV207REG_TTDMA_WORD27_PSI_OUT_DATA_TYPE_Type                        U01
#define   MWV207REG_TTDMA_WORD27_PSI_OUT_DATA_TYPE_EIGHT_BITS                0x0
#define   MWV207REG_TTDMA_WORD27_PSI_OUT_DATA_TYPE_SIXTEEN_BITS              0x1


#define MWV207REG_TTDMA_WORD27_PSI_OUT_TRANSPOSE_CH_MINUS_ONE              19:17
#define MWV207REG_TTDMA_WORD27_PSI_OUT_TRANSPOSE_CH_MINUS_ONE_End             19
#define MWV207REG_TTDMA_WORD27_PSI_OUT_TRANSPOSE_CH_MINUS_ONE_Start           17
#define MWV207REG_TTDMA_WORD27_PSI_OUT_TRANSPOSE_CH_MINUS_ONE_Type           U03


#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_IGN_INPUT                    20:20
#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_IGN_INPUT_End                   20
#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_IGN_INPUT_Start                 20
#define MWV207REG_TTDMA_WORD27_PSI_OUT_FILLER_IGN_INPUT_Type                 U01

#define MWV207REG_TTDMA_WORD27_MEM_TENSOR_BASE_ADDR_BIT31_TO29             23:21
#define MWV207REG_TTDMA_WORD27_MEM_TENSOR_BASE_ADDR_BIT31_TO29_End            23
#define MWV207REG_TTDMA_WORD27_MEM_TENSOR_BASE_ADDR_BIT31_TO29_Start          21
#define MWV207REG_TTDMA_WORD27_MEM_TENSOR_BASE_ADDR_BIT31_TO29_Type          U03

#define MWV207REG_TTDMA_WORD27_RD_SUBTENSOR_COUNT_BIT15_TO12               27:24
#define MWV207REG_TTDMA_WORD27_RD_SUBTENSOR_COUNT_BIT15_TO12_End              27
#define MWV207REG_TTDMA_WORD27_RD_SUBTENSOR_COUNT_BIT15_TO12_Start            24
#define MWV207REG_TTDMA_WORD27_RD_SUBTENSOR_COUNT_BIT15_TO12_Type            U04

#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_LEFT_PAD_BIT6TO7           29:28
#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_LEFT_PAD_BIT6TO7_End          29
#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_LEFT_PAD_BIT6TO7_Start        28
#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_LEFT_PAD_BIT6TO7_Type        U02

#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_RIGHT_PAD_BIT6TO7          31:30
#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_RIGHT_PAD_BIT6TO7_End         31
#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_RIGHT_PAD_BIT6TO7_Start       30
#define MWV207REG_TTDMA_WORD27_PSI_IN_EXTRACTOR_RIGHT_PAD_BIT6TO7_Type       U02


#endif


