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




#ifndef __jmgpuregNeuralNet_h__
#define __jmgpuregNeuralNet_h__


#define mwv207regVipSramImageStreamBaseAddressRegAddrs                    0x6180
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_Address             0x18600
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_MSB                      15
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_LSB                       0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_BLK                       0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_Count                     1
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_FieldMask        0xFFFFFFFF
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_ReadMask         0xFFFFFFFF
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_WriteMask        0xFFFFFFFF
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_ResetValue       0x00000000

#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_ADDRESS                31:0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_ADDRESS_End              31
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_ADDRESS_Start             0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BASE_ADDRESS_ADDRESS_Type            U32

#define mwv207regVipSramImageStreamBufferSizeRegAddrs                     0x6181
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_Address              0x18604
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_MSB                       15
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_LSB                        0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_BLK                        0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_Count                      1
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_FieldMask         0xFFFFFFFF
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_ReadMask          0xFFFFFFFF
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_WriteMask         0xFFFFFFFF
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_ResetValue        0x00000000

#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_SIZE                    31:0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_SIZE_End                  31
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_SIZE_Start                 0
#define MWV207REG_VIP_SRAM_IMAGE_STREAM_BUFFER_SIZE_SIZE_Type                U32

#define mwv207regVipRemapStartAddressRegAddrs                             0x6182
#define MWV207REG_VIP_REMAP_START_ADDRESS_Address                        0x18608
#define MWV207REG_VIP_REMAP_START_ADDRESS_MSB                                 15
#define MWV207REG_VIP_REMAP_START_ADDRESS_LSB                                  0
#define MWV207REG_VIP_REMAP_START_ADDRESS_BLK                                  0
#define MWV207REG_VIP_REMAP_START_ADDRESS_Count                                1
#define MWV207REG_VIP_REMAP_START_ADDRESS_FieldMask                   0xFFFFFFFF
#define MWV207REG_VIP_REMAP_START_ADDRESS_ReadMask                    0xFFFFFFFF
#define MWV207REG_VIP_REMAP_START_ADDRESS_WriteMask                   0xFFFFFFFF
#define MWV207REG_VIP_REMAP_START_ADDRESS_ResetValue                  0x00000000

#define MWV207REG_VIP_REMAP_START_ADDRESS_ADDRESS                           31:0
#define MWV207REG_VIP_REMAP_START_ADDRESS_ADDRESS_End                         31
#define MWV207REG_VIP_REMAP_START_ADDRESS_ADDRESS_Start                        0
#define MWV207REG_VIP_REMAP_START_ADDRESS_ADDRESS_Type                       U32



#define MWV207REG_NN_DATA_TYPE                                               3:0
#define MWV207REG_NN_DATA_TYPE_End                                             3
#define MWV207REG_NN_DATA_TYPE_Start                                           0
#define MWV207REG_NN_DATA_TYPE_Type                                          U04
#define   MWV207REG_NN_DATA_TYPE_UINT8                                       0x0
#define   MWV207REG_NN_DATA_TYPE_FP16                                        0x1
#define   MWV207REG_NN_DATA_TYPE_INT8                                        0x2
#define   MWV207REG_NN_DATA_TYPE_UINT16                                      0x3
#define   MWV207REG_NN_DATA_TYPE_INT16                                       0x4
#define   MWV207REG_NN_DATA_TYPE_UINT4                                       0x5
#define   MWV207REG_NN_DATA_TYPE_INT4                                        0x6
#define   MWV207REG_NN_DATA_TYPE_BFP16                                       0x7
#define   MWV207REG_NN_DATA_TYPE_FP32                                        0x8
#define   MWV207REG_NN_DATA_TYPE_INT32                                       0x9


#define MWV207REG_NN_ACTIVATION_TYPE                                         1:0
#define MWV207REG_NN_ACTIVATION_TYPE_End                                       1
#define MWV207REG_NN_ACTIVATION_TYPE_Start                                     0
#define MWV207REG_NN_ACTIVATION_TYPE_Type                                    U02
#define   MWV207REG_NN_ACTIVATION_TYPE_NONE                                  0x0
#define   MWV207REG_NN_ACTIVATION_TYPE_RELU                                  0x1
#define   MWV207REG_NN_ACTIVATION_TYPE_LEAKY_RELU                            0x2


#define MWV207REG_NN_ALU_FUNCTION_TYPE                                       3:0
#define MWV207REG_NN_ALU_FUNCTION_TYPE_End                                     3
#define MWV207REG_NN_ALU_FUNCTION_TYPE_Start                                   0
#define MWV207REG_NN_ALU_FUNCTION_TYPE_Type                                  U04
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_POST_MULTIPLY                       0x0
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_TENSOR_ADD                          0x1
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_LEAKY_RELU_OR_PRELU                 0x2
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_LUT_ACTIVATION                      0x3
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_TENSOR_MULTIPLY                     0x4
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_LEAKY_RELU_FOLLOWD_BY_TA            0x5
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_SP_IN_PROGRAM0                      0x6
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_SP_IN_PROGRAM1                      0x7
#define   MWV207REG_NN_ALU_FUNCTION_TYPE_SP_IN_PROGRAM2                      0x8


#define MWV207REG_NN_ROUNDING_MODE_TYPE                                      3:0
#define MWV207REG_NN_ROUNDING_MODE_TYPE_End                                    3
#define MWV207REG_NN_ROUNDING_MODE_TYPE_Start                                  0
#define MWV207REG_NN_ROUNDING_MODE_TYPE_Type                                 U04
#define   MWV207REG_NN_ROUNDING_MODE_TYPE_SIMPLE_ROUNDING                    0x0
#define   MWV207REG_NN_ROUNDING_MODE_TYPE_RTNE                               0x1
#define   MWV207REG_NN_ROUNDING_MODE_TYPE_RTZ                                0x2
#define   MWV207REG_NN_ROUNDING_MODE_TYPE_RTNI                               0x3
#define   MWV207REG_NN_ROUNDING_MODE_TYPE_RTNA                               0x4



#define MWV207REG_NN_INST_WORD0_LAYER_TYPE                                   0:0
#define MWV207REG_NN_INST_WORD0_LAYER_TYPE_End                                 0
#define MWV207REG_NN_INST_WORD0_LAYER_TYPE_Start                               0
#define MWV207REG_NN_INST_WORD0_LAYER_TYPE_Type                              U01
#define   MWV207REG_NN_INST_WORD0_LAYER_TYPE_CONVOLUTION_LAYER               0x0
#define   MWV207REG_NN_INST_WORD0_LAYER_TYPE_FC_LAYER                        0x1

#define MWV207REG_NN_INST_WORD0_NO_ZLOCATION_OFFSET                          1:1
#define MWV207REG_NN_INST_WORD0_NO_ZLOCATION_OFFSET_End                        1
#define MWV207REG_NN_INST_WORD0_NO_ZLOCATION_OFFSET_Start                      1
#define MWV207REG_NN_INST_WORD0_NO_ZLOCATION_OFFSET_Type                     U01

#define MWV207REG_NN_INST_WORD0_KERNEL_XYSIZE                                5:2
#define MWV207REG_NN_INST_WORD0_KERNEL_XYSIZE_End                              5
#define MWV207REG_NN_INST_WORD0_KERNEL_XYSIZE_Start                            2
#define MWV207REG_NN_INST_WORD0_KERNEL_XYSIZE_Type                           U04

#define MWV207REG_NN_INST_WORD0_KERNEL_ZSIZE                                19:6
#define MWV207REG_NN_INST_WORD0_KERNEL_ZSIZE_End                              19
#define MWV207REG_NN_INST_WORD0_KERNEL_ZSIZE_Start                             6
#define MWV207REG_NN_INST_WORD0_KERNEL_ZSIZE_Type                            U14

#define MWV207REG_NN_INST_WORD0_KERNELS_PER_CORE                           26:20
#define MWV207REG_NN_INST_WORD0_KERNELS_PER_CORE_End                          26
#define MWV207REG_NN_INST_WORD0_KERNELS_PER_CORE_Start                        20
#define MWV207REG_NN_INST_WORD0_KERNELS_PER_CORE_Type                        U07

#define MWV207REG_NN_INST_WORD0_POOLING                                    28:27
#define MWV207REG_NN_INST_WORD0_POOLING_End                                   28
#define MWV207REG_NN_INST_WORD0_POOLING_Start                                 27
#define MWV207REG_NN_INST_WORD0_POOLING_Type                                 U02
#define   MWV207REG_NN_INST_WORD0_POOLING_NO_POOLING                         0x0
#define   MWV207REG_NN_INST_WORD0_POOLING_MAX_POOLING                        0x1
#define   MWV207REG_NN_INST_WORD0_POOLING_AVERAGE_POOLING                    0x2
#define   MWV207REG_NN_INST_WORD0_POOLING_FIRST_PIXEL_POOLING                0x3


#define MWV207REG_NN_INST_WORD0_POOLING_XYSIZE                             29:29
#define MWV207REG_NN_INST_WORD0_POOLING_XYSIZE_End                            29
#define MWV207REG_NN_INST_WORD0_POOLING_XYSIZE_Start                          29
#define MWV207REG_NN_INST_WORD0_POOLING_XYSIZE_Type                          U01
#define   MWV207REG_NN_INST_WORD0_POOLING_XYSIZE_TWO                         0x0
#define   MWV207REG_NN_INST_WORD0_POOLING_XYSIZE_THREE                       0x1

#define MWV207REG_NN_INST_WORD0_PRELU                                      30:30
#define MWV207REG_NN_INST_WORD0_PRELU_End                                     30
#define MWV207REG_NN_INST_WORD0_PRELU_Start                                   30
#define MWV207REG_NN_INST_WORD0_PRELU_Type                                   U01

#define MWV207REG_NN_INST_WORD0_LAST_LAYER                                 31:31
#define MWV207REG_NN_INST_WORD0_LAST_LAYER_End                                31
#define MWV207REG_NN_INST_WORD0_LAST_LAYER_Start                              31
#define MWV207REG_NN_INST_WORD0_LAST_LAYER_Type                              U01


#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_SIZE_MINUS1                      0:0
#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_SIZE_MINUS1_End                    0
#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_SIZE_MINUS1_Start                  0
#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_SIZE_MINUS1_Type                 U01


#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_TYPE                             1:1
#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_TYPE_End                           1
#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_TYPE_Start                         1
#define MWV207REG_NN_INST_WORD1_KERNEL_DATA_TYPE_Type                        U01

#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_SIZE_MINUS1                     2:2
#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_SIZE_MINUS1_End                   2
#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_SIZE_MINUS1_Start                 2
#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_SIZE_MINUS1_Type                U01


#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_TYPE                            3:3
#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_TYPE_End                          3
#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_TYPE_Start                        3
#define MWV207REG_NN_INST_WORD1_INIMAGE_DATA_TYPE_Type                       U01

#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_SIZE_MINUS1                    4:4
#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_SIZE_MINUS1_End                  4
#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_SIZE_MINUS1_Start                4
#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_SIZE_MINUS1_Type               U01


#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_TYPE                           5:5
#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_TYPE_End                         5
#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_TYPE_Start                       5
#define MWV207REG_NN_INST_WORD1_OUTIMAGE_DATA_TYPE_Type                      U01

#define MWV207REG_NN_INST_WORD1_INIMAGE_XSIZE                               18:6
#define MWV207REG_NN_INST_WORD1_INIMAGE_XSIZE_End                             18
#define MWV207REG_NN_INST_WORD1_INIMAGE_XSIZE_Start                            6
#define MWV207REG_NN_INST_WORD1_INIMAGE_XSIZE_Type                           U13

#define MWV207REG_NN_INST_WORD1_INIMAGE_YSIZE                              31:19
#define MWV207REG_NN_INST_WORD1_INIMAGE_YSIZE_End                             31
#define MWV207REG_NN_INST_WORD1_INIMAGE_YSIZE_Start                           19
#define MWV207REG_NN_INST_WORD1_INIMAGE_YSIZE_Type                           U13



#define MWV207REG_NN_INST_WORD2_INIMAGE_XOFFSET                              2:0
#define MWV207REG_NN_INST_WORD2_INIMAGE_XOFFSET_End                            2
#define MWV207REG_NN_INST_WORD2_INIMAGE_XOFFSET_Start                          0
#define MWV207REG_NN_INST_WORD2_INIMAGE_XOFFSET_Type                         U03


#define MWV207REG_NN_INST_WORD2_INIMAGE_YOFFSET                              5:3
#define MWV207REG_NN_INST_WORD2_INIMAGE_YOFFSET_End                            5
#define MWV207REG_NN_INST_WORD2_INIMAGE_YOFFSET_Start                          3
#define MWV207REG_NN_INST_WORD2_INIMAGE_YOFFSET_Type                         U03

#define MWV207REG_NN_INST_WORD2_INIMAGE_SIGNED                               6:6
#define MWV207REG_NN_INST_WORD2_INIMAGE_SIGNED_End                             6
#define MWV207REG_NN_INST_WORD2_INIMAGE_SIGNED_Start                           6
#define MWV207REG_NN_INST_WORD2_INIMAGE_SIGNED_Type                          U01


#define MWV207REG_NN_INST_WORD2_BRICK_MODE                                   7:7
#define MWV207REG_NN_INST_WORD2_BRICK_MODE_End                                 7
#define MWV207REG_NN_INST_WORD2_BRICK_MODE_Start                               7
#define MWV207REG_NN_INST_WORD2_BRICK_MODE_Type                              U01

#define MWV207REG_NN_INST_WORD2_BRICK_DISTANCE                              23:8
#define MWV207REG_NN_INST_WORD2_BRICK_DISTANCE_End                            23
#define MWV207REG_NN_INST_WORD2_BRICK_DISTANCE_Start                           8
#define MWV207REG_NN_INST_WORD2_BRICK_DISTANCE_Type                          U16

#define MWV207REG_NN_INST_WORD2_RELU                                       24:24
#define MWV207REG_NN_INST_WORD2_RELU_End                                      24
#define MWV207REG_NN_INST_WORD2_RELU_Start                                    24
#define MWV207REG_NN_INST_WORD2_RELU_Type                                    U01

#define MWV207REG_NN_INST_WORD2_ACTIVATION_FUNCTION                        25:25
#define MWV207REG_NN_INST_WORD2_ACTIVATION_FUNCTION_End                       25
#define MWV207REG_NN_INST_WORD2_ACTIVATION_FUNCTION_Start                     25
#define MWV207REG_NN_INST_WORD2_ACTIVATION_FUNCTION_Type                     U01

#define MWV207REG_NN_INST_WORD2_POST_MULTIPLIER                            26:26
#define MWV207REG_NN_INST_WORD2_POST_MULTIPLIER_End                           26
#define MWV207REG_NN_INST_WORD2_POST_MULTIPLIER_Start                         26
#define MWV207REG_NN_INST_WORD2_POST_MULTIPLIER_Type                         U01
#define   MWV207REG_NN_INST_WORD2_POST_MULTIPLIER_ONE                        0x0
#define   MWV207REG_NN_INST_WORD2_POST_MULTIPLIER_THREE                      0x1


#define MWV207REG_NN_INST_WORD2_POST_SHIFT                                 31:27
#define MWV207REG_NN_INST_WORD2_POST_SHIFT_End                                31
#define MWV207REG_NN_INST_WORD2_POST_SHIFT_Start                              27
#define MWV207REG_NN_INST_WORD2_POST_SHIFT_Type                              U05


#define MWV207REG_NN_INST_WORD3_ONE_TILE                                     0:0
#define MWV207REG_NN_INST_WORD3_ONE_TILE_End                                   0
#define MWV207REG_NN_INST_WORD3_ONE_TILE_Start                                 0
#define MWV207REG_NN_INST_WORD3_ONE_TILE_Type                                U01

#define MWV207REG_NN_INST_WORD3_NO_OUTPUT                                    1:1
#define MWV207REG_NN_INST_WORD3_NO_OUTPUT_End                                  1
#define MWV207REG_NN_INST_WORD3_NO_OUTPUT_Start                                1
#define MWV207REG_NN_INST_WORD3_NO_OUTPUT_Type                               U01

#define MWV207REG_NN_INST_WORD3_NO_BIAS                                      2:2
#define MWV207REG_NN_INST_WORD3_NO_BIAS_End                                    2
#define MWV207REG_NN_INST_WORD3_NO_BIAS_Start                                  2
#define MWV207REG_NN_INST_WORD3_NO_BIAS_Type                                 U01

#define MWV207REG_NN_INST_WORD3_NO_FLUSH                                     3:3
#define MWV207REG_NN_INST_WORD3_NO_FLUSH_End                                   3
#define MWV207REG_NN_INST_WORD3_NO_FLUSH_Start                                 3
#define MWV207REG_NN_INST_WORD3_NO_FLUSH_Type                                U01

#define MWV207REG_NN_INST_WORD3_INIMAGE_GLOBAL_MEM                           4:4
#define MWV207REG_NN_INST_WORD3_INIMAGE_GLOBAL_MEM_End                         4
#define MWV207REG_NN_INST_WORD3_INIMAGE_GLOBAL_MEM_Start                       4
#define MWV207REG_NN_INST_WORD3_INIMAGE_GLOBAL_MEM_Type                      U01

#define MWV207REG_NN_INST_WORD3_OUTIMAGE_GLOBAL_MEM                          5:5
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_GLOBAL_MEM_End                        5
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_GLOBAL_MEM_Start                      5
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_GLOBAL_MEM_Type                     U01


#define MWV207REG_NN_INST_WORD3_OUTIMAGE_XSIZE                              18:6
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_XSIZE_End                            18
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_XSIZE_Start                           6
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_XSIZE_Type                          U13


#define MWV207REG_NN_INST_WORD3_OUTIMAGE_YSIZE                             31:19
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_YSIZE_End                            31
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_YSIZE_Start                          19
#define MWV207REG_NN_INST_WORD3_OUTIMAGE_YSIZE_Type                          U13



#define MWV207REG_NN_INST_WORD4_OUTIMAGE_ZSIZE                              13:0
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_ZSIZE_End                            13
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_ZSIZE_Start                           0
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_ZSIZE_Type                          U14

#define MWV207REG_NN_INST_WORD4_ROUNDING_MODE                              15:14
#define MWV207REG_NN_INST_WORD4_ROUNDING_MODE_End                             15
#define MWV207REG_NN_INST_WORD4_ROUNDING_MODE_Start                           14
#define MWV207REG_NN_INST_WORD4_ROUNDING_MODE_Type                           U02
#define   MWV207REG_NN_INST_WORD4_ROUNDING_MODE_SIMPLE_ROUNDING              0x0
#define   MWV207REG_NN_INST_WORD4_ROUNDING_MODE_RTNE                         0x1
#define   MWV207REG_NN_INST_WORD4_ROUNDING_MODE_RTZ                          0x2
#define   MWV207REG_NN_INST_WORD4_ROUNDING_MODE_RTNI                         0x3


#define MWV207REG_NN_INST_WORD4_INIMAGE_XOFFSET_BIT3                       16:16
#define MWV207REG_NN_INST_WORD4_INIMAGE_XOFFSET_BIT3_End                      16
#define MWV207REG_NN_INST_WORD4_INIMAGE_XOFFSET_BIT3_Start                    16
#define MWV207REG_NN_INST_WORD4_INIMAGE_XOFFSET_BIT3_Type                    U01


#define MWV207REG_NN_INST_WORD4_INIMAGE_YOFFSET_BIT3                       17:17
#define MWV207REG_NN_INST_WORD4_INIMAGE_YOFFSET_BIT3_End                      17
#define MWV207REG_NN_INST_WORD4_INIMAGE_YOFFSET_BIT3_Start                    17
#define MWV207REG_NN_INST_WORD4_INIMAGE_YOFFSET_BIT3_Type                    U01


#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_XSIZE                        24:18
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_XSIZE_End                       24
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_XSIZE_Start                     18
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_XSIZE_Type                     U07


#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_YSIZE                        31:25
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_YSIZE_End                       31
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_YSIZE_Start                     25
#define MWV207REG_NN_INST_WORD4_OUTIMAGE_TILE_YSIZE_Type                     U07



#define MWV207REG_NN_INST_WORD5_KERNEL_BASE_ADDRESS                         25:0
#define MWV207REG_NN_INST_WORD5_KERNEL_BASE_ADDRESS_End                       25
#define MWV207REG_NN_INST_WORD5_KERNEL_BASE_ADDRESS_Start                      0
#define MWV207REG_NN_INST_WORD5_KERNEL_BASE_ADDRESS_Type                     U26

#define MWV207REG_NN_INST_WORD5_KERNEL_ZSIZE1                              31:26
#define MWV207REG_NN_INST_WORD5_KERNEL_ZSIZE1_End                             31
#define MWV207REG_NN_INST_WORD5_KERNEL_ZSIZE1_Start                           26
#define MWV207REG_NN_INST_WORD5_KERNEL_ZSIZE1_Type                           U06


#define MWV207REG_NN_INST_WORD6_INPUT_BASE_ADDRESS                          31:0
#define MWV207REG_NN_INST_WORD6_INPUT_BASE_ADDRESS_End                        31
#define MWV207REG_NN_INST_WORD6_INPUT_BASE_ADDRESS_Start                       0
#define MWV207REG_NN_INST_WORD6_INPUT_BASE_ADDRESS_Type                      U32


#define MWV207REG_NN_INST_WORD7_OUTPUT_BASE_ADDRESS                         31:0
#define MWV207REG_NN_INST_WORD7_OUTPUT_BASE_ADDRESS_End                       31
#define MWV207REG_NN_INST_WORD7_OUTPUT_BASE_ADDRESS_Start                      0
#define MWV207REG_NN_INST_WORD7_OUTPUT_BASE_ADDRESS_Type                     U32


#define MWV207REG_NN_INST_WORD8_IMAGE_CACHING_MODE                           1:0
#define MWV207REG_NN_INST_WORD8_IMAGE_CACHING_MODE_End                         1
#define MWV207REG_NN_INST_WORD8_IMAGE_CACHING_MODE_Start                       0
#define MWV207REG_NN_INST_WORD8_IMAGE_CACHING_MODE_Type                      U02
#define   MWV207REG_NN_INST_WORD8_IMAGE_CACHING_MODE_IMAGE_STREAM            0x0
#define   MWV207REG_NN_INST_WORD8_IMAGE_CACHING_MODE_IMAGE_FULL_CACHE        0x1

#define MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE                          3:2
#define MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE_End                        3
#define MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE_Start                      2
#define MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE_Type                     U02
#define   MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE_KERNEL_STREAM          0x0
#define   MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE_KERNEL_FULL_CACHE      0x1
#define   MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE_KERNEL_PARTIAL_CACHE   0x2
#define   MWV207REG_NN_INST_WORD8_KERNEL_CACHING_MODE_KERNEL_FULL_CACHE_AXI_SRAM 0x3

#define MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT                      5:4
#define MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT_End                    5
#define MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT_Start                  4
#define MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT_Type                 U02
#define   MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT_SIXTY_FOUR_BYTES   0x0
#define   MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT_ONE_TWENTY_EIGHT_BYTES 0x1
#define   MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT_TWO_FIFTY_SIX_BYTES 0x2
#define   MWV207REG_NN_INST_WORD8_PARTIAL_CACHE_DATA_UNIT_FIVE_TWELVE_BYTES  0x3

#define MWV207REG_NN_INST_WORD8_KERNEL_PATTERN_MSB                          11:6
#define MWV207REG_NN_INST_WORD8_KERNEL_PATTERN_MSB_End                        11
#define MWV207REG_NN_INST_WORD8_KERNEL_PATTERN_MSB_Start                       6
#define MWV207REG_NN_INST_WORD8_KERNEL_PATTERN_MSB_Type                      U06

#define MWV207REG_NN_INST_WORD8_KERNEL_YSIZE                               15:12
#define MWV207REG_NN_INST_WORD8_KERNEL_YSIZE_End                              15
#define MWV207REG_NN_INST_WORD8_KERNEL_YSIZE_Start                            12
#define MWV207REG_NN_INST_WORD8_KERNEL_YSIZE_Type                            U04

#define MWV207REG_NN_INST_WORD8_OUT_IMAGE_YSTRIDE                          31:16
#define MWV207REG_NN_INST_WORD8_OUT_IMAGE_YSTRIDE_End                         31
#define MWV207REG_NN_INST_WORD8_OUT_IMAGE_YSTRIDE_Start                       16
#define MWV207REG_NN_INST_WORD8_OUT_IMAGE_YSTRIDE_Type                       U16


#define MWV207REG_NN_INST_WORD9_KERNEL_PATTERN_LOW32_BITS                   31:0
#define MWV207REG_NN_INST_WORD9_KERNEL_PATTERN_LOW32_BITS_End                 31
#define MWV207REG_NN_INST_WORD9_KERNEL_PATTERN_LOW32_BITS_Start                0
#define MWV207REG_NN_INST_WORD9_KERNEL_PATTERN_LOW32_BITS_Type               U32


#define MWV207REG_NN_INST_WORD10_KERNEL_PATTERN_HIGH32_BITS                 31:0
#define MWV207REG_NN_INST_WORD10_KERNEL_PATTERN_HIGH32_BITS_End               31
#define MWV207REG_NN_INST_WORD10_KERNEL_PATTERN_HIGH32_BITS_Start              0
#define MWV207REG_NN_INST_WORD10_KERNEL_PATTERN_HIGH32_BITS_Type             U32


#define MWV207REG_NN_INST_WORD11_KERNEL_CACHE_START_ADDRESS                 31:0
#define MWV207REG_NN_INST_WORD11_KERNEL_CACHE_START_ADDRESS_End               31
#define MWV207REG_NN_INST_WORD11_KERNEL_CACHE_START_ADDRESS_Start              0
#define MWV207REG_NN_INST_WORD11_KERNEL_CACHE_START_ADDRESS_Type             U32


#define MWV207REG_NN_INST_WORD12_KERNEL_CACHE_END_ADDRESS                   31:0
#define MWV207REG_NN_INST_WORD12_KERNEL_CACHE_END_ADDRESS_End                 31
#define MWV207REG_NN_INST_WORD12_KERNEL_CACHE_END_ADDRESS_Start                0
#define MWV207REG_NN_INST_WORD12_KERNEL_CACHE_END_ADDRESS_Type               U32


#define MWV207REG_NN_INST_WORD13_IMAGE_START_ADDRESS                        31:0
#define MWV207REG_NN_INST_WORD13_IMAGE_START_ADDRESS_End                      31
#define MWV207REG_NN_INST_WORD13_IMAGE_START_ADDRESS_Start                     0
#define MWV207REG_NN_INST_WORD13_IMAGE_START_ADDRESS_Type                    U32


#define MWV207REG_NN_INST_WORD14_IMAGE_END_ADDRESS                          31:0
#define MWV207REG_NN_INST_WORD14_IMAGE_END_ADDRESS_End                        31
#define MWV207REG_NN_INST_WORD14_IMAGE_END_ADDRESS_Start                       0
#define MWV207REG_NN_INST_WORD14_IMAGE_END_ADDRESS_Type                      U32


#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE                        1:0
#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE_End                      1
#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE_Start                    0
#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE_Type                   U02
#define   MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE_CONSTANT             0x0
#define   MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE_CLAMP                0x1
#define   MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE_MIRROR_SYMMETRIC     0x2
#define   MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_MODE_MIRROR_REFLECT       0x3


#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_CONSTANT                   17:2
#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_CONSTANT_End                 17
#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_CONSTANT_Start                2
#define MWV207REG_NN_INST_WORD15_IN_IMAGE_BORDER_CONSTANT_Type               U16

#define MWV207REG_NN_INST_WORD15_OUT_IMAGE_CACHE_EVICT_POLICY              18:18
#define MWV207REG_NN_INST_WORD15_OUT_IMAGE_CACHE_EVICT_POLICY_End             18
#define MWV207REG_NN_INST_WORD15_OUT_IMAGE_CACHE_EVICT_POLICY_Start           18
#define MWV207REG_NN_INST_WORD15_OUT_IMAGE_CACHE_EVICT_POLICY_Type           U01
#define   MWV207REG_NN_INST_WORD15_OUT_IMAGE_CACHE_EVICT_POLICY_STAY_LEAST_RECENTLY_USED 0x0
#define   MWV207REG_NN_INST_WORD15_OUT_IMAGE_CACHE_EVICT_POLICY_SWITCH_TO_MOST_RECENTLY_USED 0x1


#define MWV207REG_NN_INST_WORD15_KERNEL_DATA_TYPE_MSB                      19:19
#define MWV207REG_NN_INST_WORD15_KERNEL_DATA_TYPE_MSB_End                     19
#define MWV207REG_NN_INST_WORD15_KERNEL_DATA_TYPE_MSB_Start                   19
#define MWV207REG_NN_INST_WORD15_KERNEL_DATA_TYPE_MSB_Type                   U01


#define MWV207REG_NN_INST_WORD15_INIMAGE_DATA_TYPE_MSB                     20:20
#define MWV207REG_NN_INST_WORD15_INIMAGE_DATA_TYPE_MSB_End                    20
#define MWV207REG_NN_INST_WORD15_INIMAGE_DATA_TYPE_MSB_Start                  20
#define MWV207REG_NN_INST_WORD15_INIMAGE_DATA_TYPE_MSB_Type                  U01


#define MWV207REG_NN_INST_WORD15_OUTIMAGE_DATA_TYPE_MSB                    21:21
#define MWV207REG_NN_INST_WORD15_OUTIMAGE_DATA_TYPE_MSB_End                   21
#define MWV207REG_NN_INST_WORD15_OUTIMAGE_DATA_TYPE_MSB_Start                 21
#define MWV207REG_NN_INST_WORD15_OUTIMAGE_DATA_TYPE_MSB_Type                 U01

#define MWV207REG_NN_INST_WORD15_POST_MULTIPLIER_BIT6TO1                   27:22
#define MWV207REG_NN_INST_WORD15_POST_MULTIPLIER_BIT6TO1_End                  27
#define MWV207REG_NN_INST_WORD15_POST_MULTIPLIER_BIT6TO1_Start                22
#define MWV207REG_NN_INST_WORD15_POST_MULTIPLIER_BIT6TO1_Type                U06


#define MWV207REG_NN_INST_WORD15_POST_SHIFT_BIT6TO5                        29:28
#define MWV207REG_NN_INST_WORD15_POST_SHIFT_BIT6TO5_End                       29
#define MWV207REG_NN_INST_WORD15_POST_SHIFT_BIT6TO5_Start                     28
#define MWV207REG_NN_INST_WORD15_POST_SHIFT_BIT6TO5_Type                     U02


#define MWV207REG_NN_INST_WORD15_DISABLE_ZDPN                              30:30
#define MWV207REG_NN_INST_WORD15_DISABLE_ZDPN_End                             30
#define MWV207REG_NN_INST_WORD15_DISABLE_ZDPN_Start                           30
#define MWV207REG_NN_INST_WORD15_DISABLE_ZDPN_Type                           U01
#define   MWV207REG_NN_INST_WORD15_DISABLE_ZDPN_DEFAULT                      0x0
#define   MWV207REG_NN_INST_WORD15_DISABLE_ZDPN_FORCE_DISABLE                0x1


#define MWV207REG_NN_INST_WORD15_NN_SMALL_BATCH_FLUSH_ID                   31:31
#define MWV207REG_NN_INST_WORD15_NN_SMALL_BATCH_FLUSH_ID_End                  31
#define MWV207REG_NN_INST_WORD15_NN_SMALL_BATCH_FLUSH_ID_Start                31
#define MWV207REG_NN_INST_WORD15_NN_SMALL_BATCH_FLUSH_ID_Type                U01


#define MWV207REG_NN_INST_WORD16_IN_IMAGE_XSTRIDE                           15:0
#define MWV207REG_NN_INST_WORD16_IN_IMAGE_XSTRIDE_End                         15
#define MWV207REG_NN_INST_WORD16_IN_IMAGE_XSTRIDE_Start                        0
#define MWV207REG_NN_INST_WORD16_IN_IMAGE_XSTRIDE_Type                       U16

#define MWV207REG_NN_INST_WORD16_IN_IMAGE_YSTRIDE                          31:16
#define MWV207REG_NN_INST_WORD16_IN_IMAGE_YSTRIDE_End                         31
#define MWV207REG_NN_INST_WORD16_IN_IMAGE_YSTRIDE_Start                       16
#define MWV207REG_NN_INST_WORD16_IN_IMAGE_YSTRIDE_Type                       U16


#define MWV207REG_NN_INST_WORD17_OUT_IMAGE_XSTRIDE                          15:0
#define MWV207REG_NN_INST_WORD17_OUT_IMAGE_XSTRIDE_End                        15
#define MWV207REG_NN_INST_WORD17_OUT_IMAGE_XSTRIDE_Start                       0
#define MWV207REG_NN_INST_WORD17_OUT_IMAGE_XSTRIDE_Type                      U16


#define MWV207REG_NN_INST_WORD17_BRICK_DISTANCE_BIT23TO16                  23:16
#define MWV207REG_NN_INST_WORD17_BRICK_DISTANCE_BIT23TO16_End                 23
#define MWV207REG_NN_INST_WORD17_BRICK_DISTANCE_BIT23TO16_Start               16
#define MWV207REG_NN_INST_WORD17_BRICK_DISTANCE_BIT23TO16_Type               U08

#define MWV207REG_NN_INST_WORD17_POST_MULTIPLIER_BIT14TO7                  31:24
#define MWV207REG_NN_INST_WORD17_POST_MULTIPLIER_BIT14TO7_End                 31
#define MWV207REG_NN_INST_WORD17_POST_MULTIPLIER_BIT14TO7_Start               24
#define MWV207REG_NN_INST_WORD17_POST_MULTIPLIER_BIT14TO7_Type               U08


#define MWV207REG_NN_INST_WORD18_OUT_IMAGE_CIRCULAR_BUF_SIZE                25:0
#define MWV207REG_NN_INST_WORD18_OUT_IMAGE_CIRCULAR_BUF_SIZE_End              25
#define MWV207REG_NN_INST_WORD18_OUT_IMAGE_CIRCULAR_BUF_SIZE_Start             0
#define MWV207REG_NN_INST_WORD18_OUT_IMAGE_CIRCULAR_BUF_SIZE_Type            U26


#define MWV207REG_NN_INST_WORD18_PER_CH_POST_MULT                          26:26
#define MWV207REG_NN_INST_WORD18_PER_CH_POST_MULT_End                         26
#define MWV207REG_NN_INST_WORD18_PER_CH_POST_MULT_Start                       26
#define MWV207REG_NN_INST_WORD18_PER_CH_POST_MULT_Type                       U01
#define   MWV207REG_NN_INST_WORD18_PER_CH_POST_MULT_DISABLE                  0x0
#define   MWV207REG_NN_INST_WORD18_PER_CH_POST_MULT_ENABLE                   0x1

#define MWV207REG_NN_INST_WORD18_SMALL_ACCUM                               27:27
#define MWV207REG_NN_INST_WORD18_SMALL_ACCUM_End                              27
#define MWV207REG_NN_INST_WORD18_SMALL_ACCUM_Start                            27
#define MWV207REG_NN_INST_WORD18_SMALL_ACCUM_Type                            U01
#define   MWV207REG_NN_INST_WORD18_SMALL_ACCUM_DISABLE                       0x0
#define   MWV207REG_NN_INST_WORD18_SMALL_ACCUM_ENABLE                        0x1

#define MWV207REG_NN_INST_WORD18_SLOW_OUTPUT                               28:28
#define MWV207REG_NN_INST_WORD18_SLOW_OUTPUT_End                              28
#define MWV207REG_NN_INST_WORD18_SLOW_OUTPUT_Start                            28
#define MWV207REG_NN_INST_WORD18_SLOW_OUTPUT_Type                            U01
#define   MWV207REG_NN_INST_WORD18_SLOW_OUTPUT_DISABLE                       0x0
#define   MWV207REG_NN_INST_WORD18_SLOW_OUTPUT_ENABLE                        0x1

#define MWV207REG_NN_INST_WORD18_IN_IMAGE_XOFFSET_BIT4                     29:29
#define MWV207REG_NN_INST_WORD18_IN_IMAGE_XOFFSET_BIT4_End                    29
#define MWV207REG_NN_INST_WORD18_IN_IMAGE_XOFFSET_BIT4_Start                  29
#define MWV207REG_NN_INST_WORD18_IN_IMAGE_XOFFSET_BIT4_Type                  U01

#define MWV207REG_NN_INST_WORD18_IN_IMAGE_YOFFSET_BIT4                     30:30
#define MWV207REG_NN_INST_WORD18_IN_IMAGE_YOFFSET_BIT4_End                    30
#define MWV207REG_NN_INST_WORD18_IN_IMAGE_YOFFSET_BIT4_Start                  30
#define MWV207REG_NN_INST_WORD18_IN_IMAGE_YOFFSET_BIT4_Type                  U01

#define MWV207REG_NN_INST_WORD18_KERNEL_DATA_TYPE_BIT3                     31:31
#define MWV207REG_NN_INST_WORD18_KERNEL_DATA_TYPE_BIT3_End                    31
#define MWV207REG_NN_INST_WORD18_KERNEL_DATA_TYPE_BIT3_Start                  31
#define MWV207REG_NN_INST_WORD18_KERNEL_DATA_TYPE_BIT3_Type                  U01


#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1      25:0
#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_End    25
#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Start   0
#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Type  U26

#define MWV207REG_NN_INST_WORD19_IN_IMAGE_PAD_SLICE                        26:26
#define MWV207REG_NN_INST_WORD19_IN_IMAGE_PAD_SLICE_End                       26
#define MWV207REG_NN_INST_WORD19_IN_IMAGE_PAD_SLICE_Start                     26
#define MWV207REG_NN_INST_WORD19_IN_IMAGE_PAD_SLICE_Type                     U01

#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_PAD_SLICE                       27:27
#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_PAD_SLICE_End                      27
#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_PAD_SLICE_Start                    27
#define MWV207REG_NN_INST_WORD19_OUT_IMAGE_PAD_SLICE_Type                    U01

#define MWV207REG_NN_INST_WORD19_DW_OUT_IMAGE_ZERO_POINT_BIT1TO0           29:28
#define MWV207REG_NN_INST_WORD19_DW_OUT_IMAGE_ZERO_POINT_BIT1TO0_End          29
#define MWV207REG_NN_INST_WORD19_DW_OUT_IMAGE_ZERO_POINT_BIT1TO0_Start        28
#define MWV207REG_NN_INST_WORD19_DW_OUT_IMAGE_ZERO_POINT_BIT1TO0_Type        U02

#define MWV207REG_NN_INST_WORD19_B_FLOAT16_MODE                            30:30
#define MWV207REG_NN_INST_WORD19_B_FLOAT16_MODE_End                           30
#define MWV207REG_NN_INST_WORD19_B_FLOAT16_MODE_Start                         30
#define MWV207REG_NN_INST_WORD19_B_FLOAT16_MODE_Type                         U01

#define MWV207REG_NN_INST_WORD19_IN_IMAGE_DATA_TYPE_BIT3                   31:31
#define MWV207REG_NN_INST_WORD19_IN_IMAGE_DATA_TYPE_BIT3_End                  31
#define MWV207REG_NN_INST_WORD19_IN_IMAGE_DATA_TYPE_BIT3_Start                31
#define MWV207REG_NN_INST_WORD19_IN_IMAGE_DATA_TYPE_BIT3_Type                U01


#define MWV207REG_NN_INST_WORD20_IN_IMAGE_CIRCULAR_BUF_SIZE                 25:0
#define MWV207REG_NN_INST_WORD20_IN_IMAGE_CIRCULAR_BUF_SIZE_End               25
#define MWV207REG_NN_INST_WORD20_IN_IMAGE_CIRCULAR_BUF_SIZE_Start              0
#define MWV207REG_NN_INST_WORD20_IN_IMAGE_CIRCULAR_BUF_SIZE_Type             U26

#define MWV207REG_NN_INST_WORD20_OUT_IMAGE_DATA_TYPE_BIT3                  26:26
#define MWV207REG_NN_INST_WORD20_OUT_IMAGE_DATA_TYPE_BIT3_End                 26
#define MWV207REG_NN_INST_WORD20_OUT_IMAGE_DATA_TYPE_BIT3_Start               26
#define MWV207REG_NN_INST_WORD20_OUT_IMAGE_DATA_TYPE_BIT3_Type               U01


#define MWV207REG_NN_INST_WORD20_ALU_FUNCTION                              29:27
#define MWV207REG_NN_INST_WORD20_ALU_FUNCTION_End                             29
#define MWV207REG_NN_INST_WORD20_ALU_FUNCTION_Start                           27
#define MWV207REG_NN_INST_WORD20_ALU_FUNCTION_Type                           U03

#define MWV207REG_NN_INST_WORD20_CONVOLUTION_STRIDE                        30:30
#define MWV207REG_NN_INST_WORD20_CONVOLUTION_STRIDE_End                       30
#define MWV207REG_NN_INST_WORD20_CONVOLUTION_STRIDE_Start                     30
#define MWV207REG_NN_INST_WORD20_CONVOLUTION_STRIDE_Type                     U01
#define   MWV207REG_NN_INST_WORD20_CONVOLUTION_STRIDE_ONE                    0x0
#define   MWV207REG_NN_INST_WORD20_CONVOLUTION_STRIDE_TWO                    0x1


#define MWV207REG_NN_INST_WORD20_ROUND_MODE_BIT2                           31:31
#define MWV207REG_NN_INST_WORD20_ROUND_MODE_BIT2_End                          31
#define MWV207REG_NN_INST_WORD20_ROUND_MODE_BIT2_Start                        31
#define MWV207REG_NN_INST_WORD20_ROUND_MODE_BIT2_Type                        U01


#define MWV207REG_NN_INST_WORD21_IN_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1       25:0
#define MWV207REG_NN_INST_WORD21_IN_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_End     25
#define MWV207REG_NN_INST_WORD21_IN_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Start    0
#define MWV207REG_NN_INST_WORD21_IN_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Type   U26

#define MWV207REG_NN_INST_WORD21_DW_COEF_ZERO_POINT_BIT5TO0                31:26
#define MWV207REG_NN_INST_WORD21_DW_COEF_ZERO_POINT_BIT5TO0_End               31
#define MWV207REG_NN_INST_WORD21_DW_COEF_ZERO_POINT_BIT5TO0_Start             26
#define MWV207REG_NN_INST_WORD21_DW_COEF_ZERO_POINT_BIT5TO0_Type             U06


#define MWV207REG_NN_INST_WORD22_COEF_ZERO_POINT                             7:0
#define MWV207REG_NN_INST_WORD22_COEF_ZERO_POINT_End                           7
#define MWV207REG_NN_INST_WORD22_COEF_ZERO_POINT_Start                         0
#define MWV207REG_NN_INST_WORD22_COEF_ZERO_POINT_Type                        U08

#define MWV207REG_NN_INST_WORD22_OUT_IMAGE_ZERO_POINT                       15:8
#define MWV207REG_NN_INST_WORD22_OUT_IMAGE_ZERO_POINT_End                     15
#define MWV207REG_NN_INST_WORD22_OUT_IMAGE_ZERO_POINT_Start                    8
#define MWV207REG_NN_INST_WORD22_OUT_IMAGE_ZERO_POINT_Type                   U08

#define MWV207REG_NN_INST_WORD22_KERNEL_DIRECT_STREAM_FROM_VIP_SRAM        16:16
#define MWV207REG_NN_INST_WORD22_KERNEL_DIRECT_STREAM_FROM_VIP_SRAM_End       16
#define MWV207REG_NN_INST_WORD22_KERNEL_DIRECT_STREAM_FROM_VIP_SRAM_Start     16
#define MWV207REG_NN_INST_WORD22_KERNEL_DIRECT_STREAM_FROM_VIP_SRAM_Type     U01

#define MWV207REG_NN_INST_WORD22_DEPTH_WISE                                17:17
#define MWV207REG_NN_INST_WORD22_DEPTH_WISE_End                               17
#define MWV207REG_NN_INST_WORD22_DEPTH_WISE_Start                             17
#define MWV207REG_NN_INST_WORD22_DEPTH_WISE_Type                             U01

#define MWV207REG_NN_INST_WORD22_POST_MULTIPLIER_BIT22TO15                 25:18
#define MWV207REG_NN_INST_WORD22_POST_MULTIPLIER_BIT22TO15_End                25
#define MWV207REG_NN_INST_WORD22_POST_MULTIPLIER_BIT22TO15_Start              18
#define MWV207REG_NN_INST_WORD22_POST_MULTIPLIER_BIT22TO15_Type              U08


#define MWV207REG_NN_INST_WORD22_DW_OUT_IMAGE_ZERO_POINT_BIT7TO2           31:26
#define MWV207REG_NN_INST_WORD22_DW_OUT_IMAGE_ZERO_POINT_BIT7TO2_End          31
#define MWV207REG_NN_INST_WORD22_DW_OUT_IMAGE_ZERO_POINT_BIT7TO2_Start        26
#define MWV207REG_NN_INST_WORD22_DW_OUT_IMAGE_ZERO_POINT_BIT7TO2_Type        U06


#define MWV207REG_NN_INST_WORD23_NN_AXI_READ_CYCLE_RATIO_BIT5                0:0
#define MWV207REG_NN_INST_WORD23_NN_AXI_READ_CYCLE_RATIO_BIT5_End              0
#define MWV207REG_NN_INST_WORD23_NN_AXI_READ_CYCLE_RATIO_BIT5_Start            0
#define MWV207REG_NN_INST_WORD23_NN_AXI_READ_CYCLE_RATIO_BIT5_Type           U01

#define MWV207REG_NN_INST_WORD23_LUT_LOAD                                    1:1
#define MWV207REG_NN_INST_WORD23_LUT_LOAD_End                                  1
#define MWV207REG_NN_INST_WORD23_LUT_LOAD_Start                                1
#define MWV207REG_NN_INST_WORD23_LUT_LOAD_Type                               U01

#define MWV207REG_NN_INST_WORD23_NEG_POST_MULTIPLIER                        24:2
#define MWV207REG_NN_INST_WORD23_NEG_POST_MULTIPLIER_End                      24
#define MWV207REG_NN_INST_WORD23_NEG_POST_MULTIPLIER_Start                     2
#define MWV207REG_NN_INST_WORD23_NEG_POST_MULTIPLIER_Type                    U23

#define MWV207REG_NN_INST_WORD23_NEG_POST_SHIFT                            31:25
#define MWV207REG_NN_INST_WORD23_NEG_POST_SHIFT_End                           31
#define MWV207REG_NN_INST_WORD23_NEG_POST_SHIFT_Start                         25
#define MWV207REG_NN_INST_WORD23_NEG_POST_SHIFT_Type                         U07


#define MWV207REG_NN_INST_WORD24_IN_IMAGE_TRANSPOSE_CH_MINUS_ONE             3:0
#define MWV207REG_NN_INST_WORD24_IN_IMAGE_TRANSPOSE_CH_MINUS_ONE_End           3
#define MWV207REG_NN_INST_WORD24_IN_IMAGE_TRANSPOSE_CH_MINUS_ONE_Start         0
#define MWV207REG_NN_INST_WORD24_IN_IMAGE_TRANSPOSE_CH_MINUS_ONE_Type        U04

#define MWV207REG_NN_INST_WORD24_OUT_IMAGE_TRANSPOSE_BUF_START_ADDR         31:4
#define MWV207REG_NN_INST_WORD24_OUT_IMAGE_TRANSPOSE_BUF_START_ADDR_End       31
#define MWV207REG_NN_INST_WORD24_OUT_IMAGE_TRANSPOSE_BUF_START_ADDR_Start      4
#define MWV207REG_NN_INST_WORD24_OUT_IMAGE_TRANSPOSE_BUF_START_ADDR_Type     U28


#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_CH_MINUS_ONE            3:0
#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_CH_MINUS_ONE_End          3
#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_CH_MINUS_ONE_Start        0
#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_CH_MINUS_ONE_Type       U04

#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_BUF_END_ADDR_PLUS_ONE  31:4
#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_BUF_END_ADDR_PLUS_ONE_End 31
#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_BUF_END_ADDR_PLUS_ONE_Start 4
#define MWV207REG_NN_INST_WORD25_OUT_IMAGE_TRANSPOSE_BUF_END_ADDR_PLUS_ONE_Type U28



#define MWV207REG_NN_INST_WORD26_IN_IMAGE_SLICE_BIT31_TO16                  15:0
#define MWV207REG_NN_INST_WORD26_IN_IMAGE_SLICE_BIT31_TO16_End                15
#define MWV207REG_NN_INST_WORD26_IN_IMAGE_SLICE_BIT31_TO16_Start               0
#define MWV207REG_NN_INST_WORD26_IN_IMAGE_SLICE_BIT31_TO16_Type              U16


#define MWV207REG_NN_INST_WORD26_OUT_IMAGE_SLICE_BIT31_TO16                31:16
#define MWV207REG_NN_INST_WORD26_OUT_IMAGE_SLICE_BIT31_TO16_End               31
#define MWV207REG_NN_INST_WORD26_OUT_IMAGE_SLICE_BIT31_TO16_Start             16
#define MWV207REG_NN_INST_WORD26_OUT_IMAGE_SLICE_BIT31_TO16_Type             U16


#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_X                        0:0
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_X_End                      0
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_X_Start                    0
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_X_Type                   U01

#define   MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_X_REMOVE_XDIM          0x1

#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Y                        1:1
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Y_End                      1
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Y_Start                    1
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Y_Type                   U01

#define   MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Y_REMOVE_YDIM          0x1

#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Z                        2:2
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Z_End                      2
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Z_Start                    2
#define MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Z_Type                   U01

#define   MWV207REG_NN_INST_WORD27_SP_OUTPUT_COLLAPSE_Z_REMOVE_ZDIM          0x1

#define MWV207REG_NN_INST_WORD27_SP_NO_OUTPUT                                3:3
#define MWV207REG_NN_INST_WORD27_SP_NO_OUTPUT_End                              3
#define MWV207REG_NN_INST_WORD27_SP_NO_OUTPUT_Start                            3
#define MWV207REG_NN_INST_WORD27_SP_NO_OUTPUT_Type                           U01
#define   MWV207REG_NN_INST_WORD27_SP_NO_OUTPUT_TRUE                         0x1

#define MWV207REG_NN_INST_WORD27_SP_PROGRAM_ADDRESS                         11:4
#define MWV207REG_NN_INST_WORD27_SP_PROGRAM_ADDRESS_End                       11
#define MWV207REG_NN_INST_WORD27_SP_PROGRAM_ADDRESS_Start                      4
#define MWV207REG_NN_INST_WORD27_SP_PROGRAM_ADDRESS_Type                     U08


#define MWV207REG_NN_INST_WORD27_NN_IN_IMAGE_AXI_ID_OFFSET                 13:12
#define MWV207REG_NN_INST_WORD27_NN_IN_IMAGE_AXI_ID_OFFSET_End                13
#define MWV207REG_NN_INST_WORD27_NN_IN_IMAGE_AXI_ID_OFFSET_Start              12
#define MWV207REG_NN_INST_WORD27_NN_IN_IMAGE_AXI_ID_OFFSET_Type              U02


#define MWV207REG_NN_INST_WORD27_NN_OUT_IMAGE_AXI_ID_OFFSET                15:14
#define MWV207REG_NN_INST_WORD27_NN_OUT_IMAGE_AXI_ID_OFFSET_End               15
#define MWV207REG_NN_INST_WORD27_NN_OUT_IMAGE_AXI_ID_OFFSET_Start             14
#define MWV207REG_NN_INST_WORD27_NN_OUT_IMAGE_AXI_ID_OFFSET_Type             U02


#define MWV207REG_NN_INST_WORD27_NN_KERNEL_AXI_ID_OFFSET                   17:16
#define MWV207REG_NN_INST_WORD27_NN_KERNEL_AXI_ID_OFFSET_End                  17
#define MWV207REG_NN_INST_WORD27_NN_KERNEL_AXI_ID_OFFSET_Start                16
#define MWV207REG_NN_INST_WORD27_NN_KERNEL_AXI_ID_OFFSET_Type                U02


#define MWV207REG_NN_INST_WORD27_NN_MATRIX_MUL                             20:18
#define MWV207REG_NN_INST_WORD27_NN_MATRIX_MUL_End                            20
#define MWV207REG_NN_INST_WORD27_NN_MATRIX_MUL_Start                          18
#define MWV207REG_NN_INST_WORD27_NN_MATRIX_MUL_Type                          U03
#define   MWV207REG_NN_INST_WORD27_NN_MATRIX_MUL_CONV                        0x0
#define   MWV207REG_NN_INST_WORD27_NN_MATRIX_MUL_AT_MULT_B                   0x1
#define   MWV207REG_NN_INST_WORD27_NN_MATRIX_MUL_A_MULT_B                    0x2


#define MWV207REG_NN_INST_WORD27_ENABLE_FAST_XDP3                          21:21
#define MWV207REG_NN_INST_WORD27_ENABLE_FAST_XDP3_End                         21
#define MWV207REG_NN_INST_WORD27_ENABLE_FAST_XDP3_Start                       21
#define MWV207REG_NN_INST_WORD27_ENABLE_FAST_XDP3_Type                       U01


#define MWV207REG_NN_INST_WORD27_CLEAR_INPUT_EVENT                         22:22
#define MWV207REG_NN_INST_WORD27_CLEAR_INPUT_EVENT_End                        22
#define MWV207REG_NN_INST_WORD27_CLEAR_INPUT_EVENT_Start                      22
#define MWV207REG_NN_INST_WORD27_CLEAR_INPUT_EVENT_Type                      U01


#define MWV207REG_NN_INST_WORD27_INPUT_EVENT_ID                            25:23
#define MWV207REG_NN_INST_WORD27_INPUT_EVENT_ID_End                           25
#define MWV207REG_NN_INST_WORD27_INPUT_EVENT_ID_Start                         23
#define MWV207REG_NN_INST_WORD27_INPUT_EVENT_ID_Type                         U03

#define MWV207REG_NN_INST_WORD27_DW_COEF_ZERO_POINT_BIT7TO6                27:26
#define MWV207REG_NN_INST_WORD27_DW_COEF_ZERO_POINT_BIT7TO6_End               27
#define MWV207REG_NN_INST_WORD27_DW_COEF_ZERO_POINT_BIT7TO6_Start             26
#define MWV207REG_NN_INST_WORD27_DW_COEF_ZERO_POINT_BIT7TO6_Type             U02

#define MWV207REG_NN_INST_WORD27_POST_MUL_SIGN                             28:28
#define MWV207REG_NN_INST_WORD27_POST_MUL_SIGN_End                            28
#define MWV207REG_NN_INST_WORD27_POST_MUL_SIGN_Start                          28
#define MWV207REG_NN_INST_WORD27_POST_MUL_SIGN_Type                          U01

#define MWV207REG_NN_INST_WORD27_NEG_POST_MUL_SIGN                         29:29
#define MWV207REG_NN_INST_WORD27_NEG_POST_MUL_SIGN_End                        29
#define MWV207REG_NN_INST_WORD27_NEG_POST_MUL_SIGN_Start                      29
#define MWV207REG_NN_INST_WORD27_NEG_POST_MUL_SIGN_Type                      U01

#define MWV207REG_NN_INST_WORD27_POST_SHIFT_BIT7                           30:30
#define MWV207REG_NN_INST_WORD27_POST_SHIFT_BIT7_End                          30
#define MWV207REG_NN_INST_WORD27_POST_SHIFT_BIT7_Start                        30
#define MWV207REG_NN_INST_WORD27_POST_SHIFT_BIT7_Type                        U01


#define MWV207REG_NN_INST_WORD27_NEG_POST_SHIFT_BIT7                       31:31
#define MWV207REG_NN_INST_WORD27_NEG_POST_SHIFT_BIT7_End                      31
#define MWV207REG_NN_INST_WORD27_NEG_POST_SHIFT_BIT7_Start                    31
#define MWV207REG_NN_INST_WORD27_NEG_POST_SHIFT_BIT7_Type                    U01



#define MWV207REG_NN_INST_WORD28_WAIT_FOR_OUTPUT_EVENT                       0:0
#define MWV207REG_NN_INST_WORD28_WAIT_FOR_OUTPUT_EVENT_End                     0
#define MWV207REG_NN_INST_WORD28_WAIT_FOR_OUTPUT_EVENT_Start                   0
#define MWV207REG_NN_INST_WORD28_WAIT_FOR_OUTPUT_EVENT_Type                  U01


#define MWV207REG_NN_INST_WORD28_CLEAR_OUTPUT_EVENT                          1:1
#define MWV207REG_NN_INST_WORD28_CLEAR_OUTPUT_EVENT_End                        1
#define MWV207REG_NN_INST_WORD28_CLEAR_OUTPUT_EVENT_Start                      1
#define MWV207REG_NN_INST_WORD28_CLEAR_OUTPUT_EVENT_Type                     U01


#define MWV207REG_NN_INST_WORD28_OUTPUT_EVENT_ID                             4:2
#define MWV207REG_NN_INST_WORD28_OUTPUT_EVENT_ID_End                           4
#define MWV207REG_NN_INST_WORD28_OUTPUT_EVENT_ID_Start                         2
#define MWV207REG_NN_INST_WORD28_OUTPUT_EVENT_ID_Type                        U03


#define MWV207REG_NN_INST_WORD28_NN_FRAME_START                              5:5
#define MWV207REG_NN_INST_WORD28_NN_FRAME_START_End                            5
#define MWV207REG_NN_INST_WORD28_NN_FRAME_START_Start                          5
#define MWV207REG_NN_INST_WORD28_NN_FRAME_START_Type                         U01

#define MWV207REG_NN_INST_WORD28_IN_IMAGE_NHWC                               6:6
#define MWV207REG_NN_INST_WORD28_IN_IMAGE_NHWC_End                             6
#define MWV207REG_NN_INST_WORD28_IN_IMAGE_NHWC_Start                           6
#define MWV207REG_NN_INST_WORD28_IN_IMAGE_NHWC_Type                          U01


#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_NHWC                              7:7
#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_NHWC_End                            7
#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_NHWC_Start                          7
#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_NHWC_Type                         U01


#define MWV207REG_NN_INST_WORD28_NN_COEF_DECOMPRESS_BYPASS                 26:26
#define MWV207REG_NN_INST_WORD28_NN_COEF_DECOMPRESS_BYPASS_End                26
#define MWV207REG_NN_INST_WORD28_NN_COEF_DECOMPRESS_BYPASS_Start              26
#define MWV207REG_NN_INST_WORD28_NN_COEF_DECOMPRESS_BYPASS_Type              U01


#define MWV207REG_NN_INST_WORD28_ALU_FUNCTION_BIT3                         27:27
#define MWV207REG_NN_INST_WORD28_ALU_FUNCTION_BIT3_End                        27
#define MWV207REG_NN_INST_WORD28_ALU_FUNCTION_BIT3_Start                      27
#define MWV207REG_NN_INST_WORD28_ALU_FUNCTION_BIT3_Type                      U01

#define MWV207REG_NN_INST_WORD28_SP_IN_TILE_MAPPING                        28:28
#define MWV207REG_NN_INST_WORD28_SP_IN_TILE_MAPPING_End                       28
#define MWV207REG_NN_INST_WORD28_SP_IN_TILE_MAPPING_Start                     28
#define MWV207REG_NN_INST_WORD28_SP_IN_TILE_MAPPING_Type                     U01
#define   MWV207REG_NN_INST_WORD28_SP_IN_TILE_MAPPING_XY_MERGED              0x0
#define   MWV207REG_NN_INST_WORD28_SP_IN_TILE_MAPPING_YZ_MERGED              0x1

#define MWV207REG_NN_INST_WORD28_DEPTH_TO_SPACE                            29:29
#define MWV207REG_NN_INST_WORD28_DEPTH_TO_SPACE_End                           29
#define MWV207REG_NN_INST_WORD28_DEPTH_TO_SPACE_Start                         29
#define MWV207REG_NN_INST_WORD28_DEPTH_TO_SPACE_Type                         U01

#define MWV207REG_NN_INST_WORD28_WAIT_FOR_INPUT_EVENT                      30:30
#define MWV207REG_NN_INST_WORD28_WAIT_FOR_INPUT_EVENT_End                     30
#define MWV207REG_NN_INST_WORD28_WAIT_FOR_INPUT_EVENT_Start                   30
#define MWV207REG_NN_INST_WORD28_WAIT_FOR_INPUT_EVENT_Type                   U01


#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_TILE_XSIZE_BIT7                 31:31
#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_TILE_XSIZE_BIT7_End                31
#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_TILE_XSIZE_BIT7_Start              31
#define MWV207REG_NN_INST_WORD28_OUT_IMAGE_TILE_XSIZE_BIT7_Type              U01



#define MWV207REG_NN_INST_WORD29_NN_CLAMP_MAX                               31:0
#define MWV207REG_NN_INST_WORD29_NN_CLAMP_MAX_End                             31
#define MWV207REG_NN_INST_WORD29_NN_CLAMP_MAX_Start                            0
#define MWV207REG_NN_INST_WORD29_NN_CLAMP_MAX_Type                           U32



#define MWV207REG_NN_INST_WORD30_NN_CLAMP_MIN                               31:0
#define MWV207REG_NN_INST_WORD30_NN_CLAMP_MIN_End                             31
#define MWV207REG_NN_INST_WORD30_NN_CLAMP_MIN_Start                            0
#define MWV207REG_NN_INST_WORD30_NN_CLAMP_MIN_Type                           U32



#define MWV207REG_NN_INST_WORD31_NN_CONV_ONED_MODE                           0:0
#define MWV207REG_NN_INST_WORD31_NN_CONV_ONED_MODE_End                         0
#define MWV207REG_NN_INST_WORD31_NN_CONV_ONED_MODE_Start                       0
#define MWV207REG_NN_INST_WORD31_NN_CONV_ONED_MODE_Type                      U01


#define MWV207REG_NN_INST_WORD31_NN_TRANSPOSE_PHASE2_ENABLE                  1:1
#define MWV207REG_NN_INST_WORD31_NN_TRANSPOSE_PHASE2_ENABLE_End                1
#define MWV207REG_NN_INST_WORD31_NN_TRANSPOSE_PHASE2_ENABLE_Start              1
#define MWV207REG_NN_INST_WORD31_NN_TRANSPOSE_PHASE2_ENABLE_Type             U01

#define MWV207REG_NN_INST_WORD31_NN_POOLING_STRIDE                           2:2
#define MWV207REG_NN_INST_WORD31_NN_POOLING_STRIDE_End                         2
#define MWV207REG_NN_INST_WORD31_NN_POOLING_STRIDE_Start                       2
#define MWV207REG_NN_INST_WORD31_NN_POOLING_STRIDE_Type                      U01
#define   MWV207REG_NN_INST_WORD31_NN_POOLING_STRIDE_ONE                     0x0

#define   MWV207REG_NN_INST_WORD31_NN_POOLING_STRIDE_TWO                     0x1

#define MWV207REG_NN_INST_WORD31_NN_LEFT_POOLING_PADDING                     4:3
#define MWV207REG_NN_INST_WORD31_NN_LEFT_POOLING_PADDING_End                   4
#define MWV207REG_NN_INST_WORD31_NN_LEFT_POOLING_PADDING_Start                 3
#define MWV207REG_NN_INST_WORD31_NN_LEFT_POOLING_PADDING_Type                U02

#define MWV207REG_NN_INST_WORD31_NN_TOP_POOLING_PADDING                      6:5
#define MWV207REG_NN_INST_WORD31_NN_TOP_POOLING_PADDING_End                    6
#define MWV207REG_NN_INST_WORD31_NN_TOP_POOLING_PADDING_Start                  5
#define MWV207REG_NN_INST_WORD31_NN_TOP_POOLING_PADDING_Type                 U02

#define MWV207REG_NN_INST_WORD31_NN_RIGHT_POOLING_PADDING                    8:7
#define MWV207REG_NN_INST_WORD31_NN_RIGHT_POOLING_PADDING_End                  8
#define MWV207REG_NN_INST_WORD31_NN_RIGHT_POOLING_PADDING_Start                7
#define MWV207REG_NN_INST_WORD31_NN_RIGHT_POOLING_PADDING_Type               U02

#define MWV207REG_NN_INST_WORD31_NN_BOTTOM_POOLING_PADDING                  10:9
#define MWV207REG_NN_INST_WORD31_NN_BOTTOM_POOLING_PADDING_End                10
#define MWV207REG_NN_INST_WORD31_NN_BOTTOM_POOLING_PADDING_Start               9
#define MWV207REG_NN_INST_WORD31_NN_BOTTOM_POOLING_PADDING_Type              U02


#define MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL                       12:11
#define MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL_End                      12
#define MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL_Start                    11
#define MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL_Type                    U02
#define   MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL_NO_BLOCKING           0x0
#define   MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL_BF_PRE_WR_COMPLETE    0x1
#define   MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL_PRE_WR_TILE_COMPLETE  0x2
#define   MWV207REG_NN_INST_WORD31_NN_IMG_FTCH_BLK_CTL_PRE_WR_COMPLETE       0x3


#define MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL                  14:13
#define MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL_End                 14
#define MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL_Start               13
#define MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL_Type               U02
#define   MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL_NO_BLOCKING      0x0
#define   MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL_BF_PRE_WR_COMPLETE 0x1
#define   MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL_PRE_WR_TILE_COMPLETE 0x2
#define   MWV207REG_NN_INST_WORD31_NN_SEC_IMG_FTCH_BLK_CTRL_PRE_WR_COMPLETE  0x3


#define MWV207REG_NN_INST_WORD31_NN_CONV_CORE_BYPASS                       15:15
#define MWV207REG_NN_INST_WORD31_NN_CONV_CORE_BYPASS_End                      15
#define MWV207REG_NN_INST_WORD31_NN_CONV_CORE_BYPASS_Start                    15
#define MWV207REG_NN_INST_WORD31_NN_CONV_CORE_BYPASS_Type                    U01

#define MWV207REG_NN_INST_WORD31_NN_TENSOR_ADD_RELU                        16:16
#define MWV207REG_NN_INST_WORD31_NN_TENSOR_ADD_RELU_End                       16
#define MWV207REG_NN_INST_WORD31_NN_TENSOR_ADD_RELU_Start                     16
#define MWV207REG_NN_INST_WORD31_NN_TENSOR_ADD_RELU_Type                     U01

#define MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM                     19:17
#define MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_End                    19
#define MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_Start                  17
#define MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_Type                  U03
#define   MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_ONE_VIP             0x0
#define   MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_TWO                 0x1
#define   MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_FOUR_VIP            0x2
#define   MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_EIGHT               0x3
#define   MWV207REG_NN_INST_WORD31_NN_VIP_JOIN_FORCE_NUM_SIXTEEN             0x4


#define MWV207REG_NN_INST_WORD31_NN_BATCH_SIZE_MINUS_ONE                   24:20
#define MWV207REG_NN_INST_WORD31_NN_BATCH_SIZE_MINUS_ONE_End                  24
#define MWV207REG_NN_INST_WORD31_NN_BATCH_SIZE_MINUS_ONE_Start                20
#define MWV207REG_NN_INST_WORD31_NN_BATCH_SIZE_MINUS_ONE_Type                U05

#define MWV207REG_NN_INST_WORD31_NN_BATCH_INIMAGE_RANK                     25:25
#define MWV207REG_NN_INST_WORD31_NN_BATCH_INIMAGE_RANK_End                    25
#define MWV207REG_NN_INST_WORD31_NN_BATCH_INIMAGE_RANK_Start                  25
#define MWV207REG_NN_INST_WORD31_NN_BATCH_INIMAGE_RANK_Type                  U01
#define   MWV207REG_NN_INST_WORD31_NN_BATCH_INIMAGE_RANK_NCHW                0x0
#define   MWV207REG_NN_INST_WORD31_NN_BATCH_INIMAGE_RANK_CNHW                0x1

#define MWV207REG_NN_INST_WORD31_NN_BATCH_OUTIMAGE_RANK                    26:26
#define MWV207REG_NN_INST_WORD31_NN_BATCH_OUTIMAGE_RANK_End                   26
#define MWV207REG_NN_INST_WORD31_NN_BATCH_OUTIMAGE_RANK_Start                 26
#define MWV207REG_NN_INST_WORD31_NN_BATCH_OUTIMAGE_RANK_Type                 U01
#define   MWV207REG_NN_INST_WORD31_NN_BATCH_OUTIMAGE_RANK_NCHW               0x0
#define   MWV207REG_NN_INST_WORD31_NN_BATCH_OUTIMAGE_RANK_CNHW               0x1


#define MWV207REG_NN_INST_WORD31_NN_AXI_READ_CYCLE_RATIO_BIT0_TO4          31:27
#define MWV207REG_NN_INST_WORD31_NN_AXI_READ_CYCLE_RATIO_BIT0_TO4_End         31
#define MWV207REG_NN_INST_WORD31_NN_AXI_READ_CYCLE_RATIO_BIT0_TO4_Start       27
#define MWV207REG_NN_INST_WORD31_NN_AXI_READ_CYCLE_RATIO_BIT0_TO4_Type       U05




#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_XSTRIDE                  15:0
#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_XSTRIDE_End                15
#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_XSTRIDE_Start               0
#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_XSTRIDE_Type              U16


#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_YSTRIDE                 31:16
#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_YSTRIDE_End                31
#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_YSTRIDE_Start              16
#define MWV207REG_NN_INST_WORD32_SECOND_BIT_STREAM_YSTRIDE_Type              U16


#define MWV207REG_NN_INST_WORD33_SECOND_IN_IMAGE_PAD_TO_SLICE                0:0
#define MWV207REG_NN_INST_WORD33_SECOND_IN_IMAGE_PAD_TO_SLICE_End              0
#define MWV207REG_NN_INST_WORD33_SECOND_IN_IMAGE_PAD_TO_SLICE_Start            0
#define MWV207REG_NN_INST_WORD33_SECOND_IN_IMAGE_PAD_TO_SLICE_Type           U01
#define   MWV207REG_NN_INST_WORD33_SECOND_IN_IMAGE_PAD_TO_SLICE_DISABLE      0x0

#define   MWV207REG_NN_INST_WORD33_SECOND_IN_IMAGE_PAD_TO_SLICE_ENABLE       0x1


#define MWV207REG_NN_INST_WORD33_NN_SECOND_INIMAGE_CIRCULAR_BUFFER_SIZE     26:1
#define MWV207REG_NN_INST_WORD33_NN_SECOND_INIMAGE_CIRCULAR_BUFFER_SIZE_End   26
#define MWV207REG_NN_INST_WORD33_NN_SECOND_INIMAGE_CIRCULAR_BUFFER_SIZE_Start  1
#define MWV207REG_NN_INST_WORD33_NN_SECOND_INIMAGE_CIRCULAR_BUFFER_SIZE_Type U26

#define MWV207REG_NN_INST_WORD33_SECOND_INIMAGE_TRANSPOSE_CH_MINUS_ONE     30:27
#define MWV207REG_NN_INST_WORD33_SECOND_INIMAGE_TRANSPOSE_CH_MINUS_ONE_End    30
#define MWV207REG_NN_INST_WORD33_SECOND_INIMAGE_TRANSPOSE_CH_MINUS_ONE_Start  27
#define MWV207REG_NN_INST_WORD33_SECOND_INIMAGE_TRANSPOSE_CH_MINUS_ONE_Type  U04


#define MWV207REG_NN_INST_WORD33_PP_LOW_POWER_MODE                         31:31
#define MWV207REG_NN_INST_WORD33_PP_LOW_POWER_MODE_End                        31
#define MWV207REG_NN_INST_WORD33_PP_LOW_POWER_MODE_Start                      31
#define MWV207REG_NN_INST_WORD33_PP_LOW_POWER_MODE_Type                      U01
#define   MWV207REG_NN_INST_WORD33_PP_LOW_POWER_MODE_DISABLE                 0x0
#define   MWV207REG_NN_INST_WORD33_PP_LOW_POWER_MODE_ENABLE                  0x1



#define MWV207REG_NN_INST_WORD34_NN_SECOND_INPUT_BASE_ADDRESS               31:0
#define MWV207REG_NN_INST_WORD34_NN_SECOND_INPUT_BASE_ADDRESS_End             31
#define MWV207REG_NN_INST_WORD34_NN_SECOND_INPUT_BASE_ADDRESS_Start            0
#define MWV207REG_NN_INST_WORD34_NN_SECOND_INPUT_BASE_ADDRESS_Type           U32



#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_CIRC_BUF_END_ADDR_PLUS1        25:0
#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_CIRC_BUF_END_ADDR_PLUS1_End      25
#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_CIRC_BUF_END_ADDR_PLUS1_Start     0
#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_CIRC_BUF_END_ADDR_PLUS1_Type    U26

#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_AXI_ID_OFFSET                 27:26
#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_AXI_ID_OFFSET_End                27
#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_AXI_ID_OFFSET_Start              26
#define MWV207REG_NN_INST_WORD35_NN2ND_IMAGE_AXI_ID_OFFSET_Type              U02


#define MWV207REG_NN_INST_WORD35_NN2ND_INPUT_IMAGE_DATA_TYPE               31:28
#define MWV207REG_NN_INST_WORD35_NN2ND_INPUT_IMAGE_DATA_TYPE_End              31
#define MWV207REG_NN_INST_WORD35_NN2ND_INPUT_IMAGE_DATA_TYPE_Start            28
#define MWV207REG_NN_INST_WORD35_NN2ND_INPUT_IMAGE_DATA_TYPE_Type            U04



#define MWV207REG_NN_INST_WORD36_TENSOR_ADD_CONSTANT                        13:0
#define MWV207REG_NN_INST_WORD36_TENSOR_ADD_CONSTANT_End                      13
#define MWV207REG_NN_INST_WORD36_TENSOR_ADD_CONSTANT_Start                     0
#define MWV207REG_NN_INST_WORD36_TENSOR_ADD_CONSTANT_Type                    U14


#define MWV207REG_NN_INST_WORD36__PAD                                      15:14
#define MWV207REG_NN_INST_WORD36__PAD_End                                     15
#define MWV207REG_NN_INST_WORD36__PAD_Start                                   14
#define MWV207REG_NN_INST_WORD36__PAD_Type                                   U02

#define MWV207REG_NN_INST_WORD36_SECOND_BIT_STREAM_SLICE_BIT31TO16         31:16
#define MWV207REG_NN_INST_WORD36_SECOND_BIT_STREAM_SLICE_BIT31TO16_End        31
#define MWV207REG_NN_INST_WORD36_SECOND_BIT_STREAM_SLICE_BIT31TO16_Start      16
#define MWV207REG_NN_INST_WORD36_SECOND_BIT_STREAM_SLICE_BIT31TO16_Type      U16



#define MWV207REG_NN_INST_WORD37_KERNEL_BASE_ADDR_BIT39_TO32                 7:0
#define MWV207REG_NN_INST_WORD37_KERNEL_BASE_ADDR_BIT39_TO32_End               7
#define MWV207REG_NN_INST_WORD37_KERNEL_BASE_ADDR_BIT39_TO32_Start             0
#define MWV207REG_NN_INST_WORD37_KERNEL_BASE_ADDR_BIT39_TO32_Type            U08


#define MWV207REG_NN_INST_WORD37_INPUT_BASE_ADDR_BIT39_TO32                 15:8
#define MWV207REG_NN_INST_WORD37_INPUT_BASE_ADDR_BIT39_TO32_End               15
#define MWV207REG_NN_INST_WORD37_INPUT_BASE_ADDR_BIT39_TO32_Start              8
#define MWV207REG_NN_INST_WORD37_INPUT_BASE_ADDR_BIT39_TO32_Type             U08


#define MWV207REG_NN_INST_WORD37_OUTPUT_BASE_ADDR_BIT39_TO32               23:16
#define MWV207REG_NN_INST_WORD37_OUTPUT_BASE_ADDR_BIT39_TO32_End              23
#define MWV207REG_NN_INST_WORD37_OUTPUT_BASE_ADDR_BIT39_TO32_Start            16
#define MWV207REG_NN_INST_WORD37_OUTPUT_BASE_ADDR_BIT39_TO32_Type            U08

#define MWV207REG_NN_INST_WORD37_IN_IMAGE_CB_SIZE_BIT39_TO32               31:24
#define MWV207REG_NN_INST_WORD37_IN_IMAGE_CB_SIZE_BIT39_TO32_End              31
#define MWV207REG_NN_INST_WORD37_IN_IMAGE_CB_SIZE_BIT39_TO32_Start            24
#define MWV207REG_NN_INST_WORD37_IN_IMAGE_CB_SIZE_BIT39_TO32_Type            U08


#define MWV207REG_NN_INST_WORD38_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32       7:0
#define MWV207REG_NN_INST_WORD38_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_End     7
#define MWV207REG_NN_INST_WORD38_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Start   0
#define MWV207REG_NN_INST_WORD38_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Type  U08

#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_SIZE_BIT39TO32                15:8
#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_SIZE_BIT39TO32_End              15
#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_SIZE_BIT39TO32_Start             8
#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_SIZE_BIT39TO32_Type            U08

#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32    23:16
#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_End   23
#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Start 16
#define MWV207REG_NN_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Type U08

#define MWV207REG_NN_INST_WORD38_SECOND_INPUT_BASE_ADDR39_TO32             31:24
#define MWV207REG_NN_INST_WORD38_SECOND_INPUT_BASE_ADDR39_TO32_End            31
#define MWV207REG_NN_INST_WORD38_SECOND_INPUT_BASE_ADDR39_TO32_Start          24
#define MWV207REG_NN_INST_WORD38_SECOND_INPUT_BASE_ADDR39_TO32_Type          U08


#define MWV207REG_NN_INST_WORD39_SECOND_IN_IMAGE_CB_SIZE_BIT39_TO32          7:0
#define MWV207REG_NN_INST_WORD39_SECOND_IN_IMAGE_CB_SIZE_BIT39_TO32_End        7
#define MWV207REG_NN_INST_WORD39_SECOND_IN_IMAGE_CB_SIZE_BIT39_TO32_Start      0
#define MWV207REG_NN_INST_WORD39_SECOND_IN_IMAGE_CB_SIZE_BIT39_TO32_Type     U08

#define MWV207REG_NN_INST_WORD39_SECOND_INIMAGE_CB_END_ADDR_PLUS1_BIT39TO32 15:8
#define MWV207REG_NN_INST_WORD39_SECOND_INIMAGE_CB_END_ADDR_PLUS1_BIT39TO32_End 15
#define MWV207REG_NN_INST_WORD39_SECOND_INIMAGE_CB_END_ADDR_PLUS1_BIT39TO32_Start 8
#define MWV207REG_NN_INST_WORD39_SECOND_INIMAGE_CB_END_ADDR_PLUS1_BIT39TO32_Type U08

#define MWV207REG_NN_INST_WORD39_IN_IMAGE_SLICE_BIT39_TO32                 23:16
#define MWV207REG_NN_INST_WORD39_IN_IMAGE_SLICE_BIT39_TO32_End                23
#define MWV207REG_NN_INST_WORD39_IN_IMAGE_SLICE_BIT39_TO32_Start              16
#define MWV207REG_NN_INST_WORD39_IN_IMAGE_SLICE_BIT39_TO32_Type              U08

#define MWV207REG_NN_INST_WORD39_OUT_IMAGE_SLICE_BIT39_TO32                31:24
#define MWV207REG_NN_INST_WORD39_OUT_IMAGE_SLICE_BIT39_TO32_End               31
#define MWV207REG_NN_INST_WORD39_OUT_IMAGE_SLICE_BIT39_TO32_Start             24
#define MWV207REG_NN_INST_WORD39_OUT_IMAGE_SLICE_BIT39_TO32_Type             U08



#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_XSIZE_BIT31_TO13                 18:0
#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_XSIZE_BIT31_TO13_End               18
#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_XSIZE_BIT31_TO13_Start              0
#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_XSIZE_BIT31_TO13_Type             U19

#define MWV207REG_NN_INST_WORD40_SECOND_BIT_STREAM_SLICE_BIT39TO32         26:19
#define MWV207REG_NN_INST_WORD40_SECOND_BIT_STREAM_SLICE_BIT39TO32_End        26
#define MWV207REG_NN_INST_WORD40_SECOND_BIT_STREAM_SLICE_BIT39TO32_Start      19
#define MWV207REG_NN_INST_WORD40_SECOND_BIT_STREAM_SLICE_BIT39TO32_Type      U08


#define MWV207REG_NN_INST_WORD40_KERNEL_ADDR_OFFSET_ID                     28:27
#define MWV207REG_NN_INST_WORD40_KERNEL_ADDR_OFFSET_ID_End                    28
#define MWV207REG_NN_INST_WORD40_KERNEL_ADDR_OFFSET_ID_Start                  27
#define MWV207REG_NN_INST_WORD40_KERNEL_ADDR_OFFSET_ID_Type                  U02


#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_ADDR_OFFSET_ID                  30:29
#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_ADDR_OFFSET_ID_End                 30
#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_ADDR_OFFSET_ID_Start               29
#define MWV207REG_NN_INST_WORD40_OUT_IMAGE_ADDR_OFFSET_ID_Type               U02



#define MWV207REG_NN_INST_WORD41_OUT_IMAGE_YSIZE_BIT31_TO13                 18:0
#define MWV207REG_NN_INST_WORD41_OUT_IMAGE_YSIZE_BIT31_TO13_End               18
#define MWV207REG_NN_INST_WORD41_OUT_IMAGE_YSIZE_BIT31_TO13_Start              0
#define MWV207REG_NN_INST_WORD41_OUT_IMAGE_YSIZE_BIT31_TO13_Type             U19

#define MWV207REG_NN_INST_WORD41_IN_IMAGE_BASE_ADDR_INC_BIT12_TO0          31:19
#define MWV207REG_NN_INST_WORD41_IN_IMAGE_BASE_ADDR_INC_BIT12_TO0_End         31
#define MWV207REG_NN_INST_WORD41_IN_IMAGE_BASE_ADDR_INC_BIT12_TO0_Start       19
#define MWV207REG_NN_INST_WORD41_IN_IMAGE_BASE_ADDR_INC_BIT12_TO0_Type       U13



#define MWV207REG_NN_INST_WORD42_OUT_IMAGE_ZSIZE_BIT31_TO14                 17:0
#define MWV207REG_NN_INST_WORD42_OUT_IMAGE_ZSIZE_BIT31_TO14_End               17
#define MWV207REG_NN_INST_WORD42_OUT_IMAGE_ZSIZE_BIT31_TO14_Start              0
#define MWV207REG_NN_INST_WORD42_OUT_IMAGE_ZSIZE_BIT31_TO14_Type             U18

#define MWV207REG_NN_INST_WORD42_KERNEL_ZSIZE_BIT31_TO20                   29:18
#define MWV207REG_NN_INST_WORD42_KERNEL_ZSIZE_BIT31_TO20_End                  29
#define MWV207REG_NN_INST_WORD42_KERNEL_ZSIZE_BIT31_TO20_Start                18
#define MWV207REG_NN_INST_WORD42_KERNEL_ZSIZE_BIT31_TO20_Type                U12


#define MWV207REG_NN_INST_WORD42_SECOND_IN_IMAGE_ADDR_OFFSET_ID            31:30
#define MWV207REG_NN_INST_WORD42_SECOND_IN_IMAGE_ADDR_OFFSET_ID_End           31
#define MWV207REG_NN_INST_WORD42_SECOND_IN_IMAGE_ADDR_OFFSET_ID_Start         30
#define MWV207REG_NN_INST_WORD42_SECOND_IN_IMAGE_ADDR_OFFSET_ID_Type         U02



#define MWV207REG_NN_INST_WORD43_INIMAGE_XSIZE_BIT31_TO13                   18:0
#define MWV207REG_NN_INST_WORD43_INIMAGE_XSIZE_BIT31_TO13_End                 18
#define MWV207REG_NN_INST_WORD43_INIMAGE_XSIZE_BIT31_TO13_Start                0
#define MWV207REG_NN_INST_WORD43_INIMAGE_XSIZE_BIT31_TO13_Type               U19

#define MWV207REG_NN_INST_WORD43_IN_IMAGE_BASE_ADDR_INC_BIT23_TO13         29:19
#define MWV207REG_NN_INST_WORD43_IN_IMAGE_BASE_ADDR_INC_BIT23_TO13_End        29
#define MWV207REG_NN_INST_WORD43_IN_IMAGE_BASE_ADDR_INC_BIT23_TO13_Start      19
#define MWV207REG_NN_INST_WORD43_IN_IMAGE_BASE_ADDR_INC_BIT23_TO13_Type      U11



#define MWV207REG_NN_INST_WORD44_INIMAGE_YSIZE_BIT31_TO13                   18:0
#define MWV207REG_NN_INST_WORD44_INIMAGE_YSIZE_BIT31_TO13_End                 18
#define MWV207REG_NN_INST_WORD44_INIMAGE_YSIZE_BIT31_TO13_Start                0
#define MWV207REG_NN_INST_WORD44_INIMAGE_YSIZE_BIT31_TO13_Type               U19


#define MWV207REG_NN_INST_WORD44_IN_IMAGE_ADDR_OFFSET_ID                   20:19
#define MWV207REG_NN_INST_WORD44_IN_IMAGE_ADDR_OFFSET_ID_End                  20
#define MWV207REG_NN_INST_WORD44_IN_IMAGE_ADDR_OFFSET_ID_Start                19
#define MWV207REG_NN_INST_WORD44_IN_IMAGE_ADDR_OFFSET_ID_Type                U02



#define MWV207REG_NN_INST_WORD45_INIMAGE_XSTRIDE_BIT31_TO16                 15:0
#define MWV207REG_NN_INST_WORD45_INIMAGE_XSTRIDE_BIT31_TO16_End               15
#define MWV207REG_NN_INST_WORD45_INIMAGE_XSTRIDE_BIT31_TO16_Start              0
#define MWV207REG_NN_INST_WORD45_INIMAGE_XSTRIDE_BIT31_TO16_Type             U16

#define MWV207REG_NN_INST_WORD45_OUTIMAGE_XSTRIDE_BIT31_TO16               31:16
#define MWV207REG_NN_INST_WORD45_OUTIMAGE_XSTRIDE_BIT31_TO16_End              31
#define MWV207REG_NN_INST_WORD45_OUTIMAGE_XSTRIDE_BIT31_TO16_Start            16
#define MWV207REG_NN_INST_WORD45_OUTIMAGE_XSTRIDE_BIT31_TO16_Type            U16


#define MWV207REG_NN_INST_WORD46_SECOND_BSX_STRIDE_BIT31_TO16               15:0
#define MWV207REG_NN_INST_WORD46_SECOND_BSX_STRIDE_BIT31_TO16_End             15
#define MWV207REG_NN_INST_WORD46_SECOND_BSX_STRIDE_BIT31_TO16_Start            0
#define MWV207REG_NN_INST_WORD46_SECOND_BSX_STRIDE_BIT31_TO16_Type           U16

#define MWV207REG_NN_INST_WORD46_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT15_TO0   31:16
#define MWV207REG_NN_INST_WORD46_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT15_TO0_End  31
#define MWV207REG_NN_INST_WORD46_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT15_TO0_Start 16
#define MWV207REG_NN_INST_WORD46_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT15_TO0_Type U16


#define MWV207REG_NN_INST_WORD47_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT23_TO16    7:0
#define MWV207REG_NN_INST_WORD47_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT23_TO16_End  7
#define MWV207REG_NN_INST_WORD47_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT23_TO16_Start 0
#define MWV207REG_NN_INST_WORD47_SECOND_IN_IMAGE_BASE_ADDR_INC_BIT23_TO16_Type U08


#define MWV207REG_NN_INST_WORD47_OUT_IMAGE_BASE_ADDR_INC                    31:8
#define MWV207REG_NN_INST_WORD47_OUT_IMAGE_BASE_ADDR_INC_End                  31
#define MWV207REG_NN_INST_WORD47_OUT_IMAGE_BASE_ADDR_INC_Start                 8
#define MWV207REG_NN_INST_WORD47_OUT_IMAGE_BASE_ADDR_INC_Type                U24



#define MWV207REG_TP_INST_WORD0_INIMAGE_XSIZE                               15:0
#define MWV207REG_TP_INST_WORD0_INIMAGE_XSIZE_End                             15
#define MWV207REG_TP_INST_WORD0_INIMAGE_XSIZE_Start                            0
#define MWV207REG_TP_INST_WORD0_INIMAGE_XSIZE_Type                           U16

#define MWV207REG_TP_INST_WORD0_TP_SOFTMAX_BETA                            31:16
#define MWV207REG_TP_INST_WORD0_TP_SOFTMAX_BETA_End                           31
#define MWV207REG_TP_INST_WORD0_TP_SOFTMAX_BETA_Start                         16
#define MWV207REG_TP_INST_WORD0_TP_SOFTMAX_BETA_Type                         U16


#define MWV207REG_TP_INST_WORD1_INIMAGE_YSIZE                               15:0
#define MWV207REG_TP_INST_WORD1_INIMAGE_YSIZE_End                             15
#define MWV207REG_TP_INST_WORD1_INIMAGE_YSIZE_Start                            0
#define MWV207REG_TP_INST_WORD1_INIMAGE_YSIZE_Type                           U16

#define MWV207REG_TP_INST_WORD1_INIMAGE_ZSIZE                              31:16
#define MWV207REG_TP_INST_WORD1_INIMAGE_ZSIZE_End                             31
#define MWV207REG_TP_INST_WORD1_INIMAGE_ZSIZE_Start                           16
#define MWV207REG_TP_INST_WORD1_INIMAGE_ZSIZE_Type                           U16


#define MWV207REG_TP_INST_WORD2_INIMAGE_STRIDE                              15:0
#define MWV207REG_TP_INST_WORD2_INIMAGE_STRIDE_End                            15
#define MWV207REG_TP_INST_WORD2_INIMAGE_STRIDE_Start                           0
#define MWV207REG_TP_INST_WORD2_INIMAGE_STRIDE_Type                          U16


#define MWV207REG_TP_INST_WORD3_INIMAGE_SLICE                               31:0
#define MWV207REG_TP_INST_WORD3_INIMAGE_SLICE_End                             31
#define MWV207REG_TP_INST_WORD3_INIMAGE_SLICE_Start                            0
#define MWV207REG_TP_INST_WORD3_INIMAGE_SLICE_Type                           U32


#define MWV207REG_TP_INST_WORD4_INWINDOW_XSTART                             15:0
#define MWV207REG_TP_INST_WORD4_INWINDOW_XSTART_End                           15
#define MWV207REG_TP_INST_WORD4_INWINDOW_XSTART_Start                          0
#define MWV207REG_TP_INST_WORD4_INWINDOW_XSTART_Type                         U16

#define MWV207REG_TP_INST_WORD4_INWINDOW_YSTART                            31:16
#define MWV207REG_TP_INST_WORD4_INWINDOW_YSTART_End                           31
#define MWV207REG_TP_INST_WORD4_INWINDOW_YSTART_Start                         16
#define MWV207REG_TP_INST_WORD4_INWINDOW_YSTART_Type                         U16


#define MWV207REG_TP_INST_WORD5_INWINDOW_XEND                               15:0
#define MWV207REG_TP_INST_WORD5_INWINDOW_XEND_End                             15
#define MWV207REG_TP_INST_WORD5_INWINDOW_XEND_Start                            0
#define MWV207REG_TP_INST_WORD5_INWINDOW_XEND_Type                           U16

#define MWV207REG_TP_INST_WORD5_INWINDOW_YEND                              31:16
#define MWV207REG_TP_INST_WORD5_INWINDOW_YEND_End                             31
#define MWV207REG_TP_INST_WORD5_INWINDOW_YEND_Start                           16
#define MWV207REG_TP_INST_WORD5_INWINDOW_YEND_Type                           U16


#define MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE                              1:0
#define MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE_End                            1
#define MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE_Start                          0
#define MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE_Type                         U02
#define   MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE_TWO_D_TILE_SLIDING_MODE    0x0
#define   MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE_THREE_D_TILE_SLIDING_MODE  0x1
#define   MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE_ROI_COMMAND_LIST_MODE      0x2
#define   MWV207REG_TP_INST_WORD6_INTILE_SEQUENCE_FC__LAYER_PROCESS          0x3

#define MWV207REG_TP_INST_WORD6_INTILE_LIST_GLOBAL_MEM                       2:2
#define MWV207REG_TP_INST_WORD6_INTILE_LIST_GLOBAL_MEM_End                     2
#define MWV207REG_TP_INST_WORD6_INTILE_LIST_GLOBAL_MEM_Start                   2
#define MWV207REG_TP_INST_WORD6_INTILE_LIST_GLOBAL_MEM_Type                  U01

#define MWV207REG_TP_INST_WORD6_INIMAGE_GLOBAL_MEM                           3:3
#define MWV207REG_TP_INST_WORD6_INIMAGE_GLOBAL_MEM_End                         3
#define MWV207REG_TP_INST_WORD6_INIMAGE_GLOBAL_MEM_Start                       3
#define MWV207REG_TP_INST_WORD6_INIMAGE_GLOBAL_MEM_Type                      U01


#define MWV207REG_TP_INST_WORD6_ALU_I2F_ENABLE                               4:4
#define MWV207REG_TP_INST_WORD6_ALU_I2F_ENABLE_End                             4
#define MWV207REG_TP_INST_WORD6_ALU_I2F_ENABLE_Start                           4
#define MWV207REG_TP_INST_WORD6_ALU_I2F_ENABLE_Type                          U01

#define MWV207REG_TP_INST_WORD6_ALU_SQUARE_ENABLE                            5:5
#define MWV207REG_TP_INST_WORD6_ALU_SQUARE_ENABLE_End                          5
#define MWV207REG_TP_INST_WORD6_ALU_SQUARE_ENABLE_Start                        5
#define MWV207REG_TP_INST_WORD6_ALU_SQUARE_ENABLE_Type                       U01


#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING                          7:6
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_End                        7
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_Start                      6
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_Type                     U02
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_SUM_FILTER             0x0
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_MAX_FILTER             0x1
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_SEGMENTED_MAX_INTEGRAL 0x2
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_MAX_POOLING            0x3

#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_BIT2                     8:8
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_BIT2_End                   8
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_BIT2_Start                 8
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROCESSING_BIT2_Type                U01

#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_COUNT                         14:9
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_COUNT_End                       14
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_COUNT_Start                      9
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_COUNT_Type                     U06

#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE                       15:15
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE_End                      15
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE_Start                    15
#define MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE_Type                    U01
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE_NO_OUTPUT_SKIPPING    0x0
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE_SKIP_EVERY_OTHER_OUTPUT 0x1
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE_HSIZE                 0x0
#define   MWV207REG_TP_INST_WORD6_ALU_HORZ_PROC_STRIDE_HSIZE_MINUS_ONE       0x1

#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING                        17:16
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING_End                       17
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING_Start                     16
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING_Type                     U02
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING_VERT_SUM_FILTER        0x0
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING_VERT_MAX_FILTER        0x1
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING_EXTENDED_HORZ_FILTER   0x2
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROCESSING_VERT_MAX_POOLING       0x3

#define MWV207REG_TP_INST_WORD6_TP_SOFTMAX_SKIP_MAX                        18:18
#define MWV207REG_TP_INST_WORD6_TP_SOFTMAX_SKIP_MAX_End                       18
#define MWV207REG_TP_INST_WORD6_TP_SOFTMAX_SKIP_MAX_Start                     18
#define MWV207REG_TP_INST_WORD6_TP_SOFTMAX_SKIP_MAX_Type                     U01

#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_COUNT                        24:19
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_COUNT_End                       24
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_COUNT_Start                     19
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_COUNT_Type                     U06

#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE                       25:25
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE_End                      25
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE_Start                    25
#define MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE_Type                    U01
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE_NO_OUTPUT_SKIPPING    0x0
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE_SKIP_EVERY_OTHER_OUTPUT 0x1
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE_VSIZE                 0x0
#define   MWV207REG_TP_INST_WORD6_ALU_VERT_PROC_STRIDE_VSIZE_MINUS_ONE       0x1

#define MWV207REG_TP_INST_WORD6_ALU_NMS_ENABLE                             26:26
#define MWV207REG_TP_INST_WORD6_ALU_NMS_ENABLE_End                            26
#define MWV207REG_TP_INST_WORD6_ALU_NMS_ENABLE_Start                          26
#define MWV207REG_TP_INST_WORD6_ALU_NMS_ENABLE_Type                          U01

#define MWV207REG_TP_INST_WORD6_ALU_PWL_ENABLE                             27:27
#define MWV207REG_TP_INST_WORD6_ALU_PWL_ENABLE_End                            27
#define MWV207REG_TP_INST_WORD6_ALU_PWL_ENABLE_Start                          27
#define MWV207REG_TP_INST_WORD6_ALU_PWL_ENABLE_Type                          U01

#define MWV207REG_TP_INST_WORD6_ALU_MULT_ENABLE                            28:28
#define MWV207REG_TP_INST_WORD6_ALU_MULT_ENABLE_End                           28
#define MWV207REG_TP_INST_WORD6_ALU_MULT_ENABLE_Start                         28
#define MWV207REG_TP_INST_WORD6_ALU_MULT_ENABLE_Type                         U01


#define MWV207REG_TP_INST_WORD6_ALU_F2I_ENABLE                             29:29
#define MWV207REG_TP_INST_WORD6_ALU_F2I_ENABLE_End                            29
#define MWV207REG_TP_INST_WORD6_ALU_F2I_ENABLE_Start                          29
#define MWV207REG_TP_INST_WORD6_ALU_F2I_ENABLE_Type                          U01

#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT                           30:30
#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT_End                          30
#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT_Start                        30
#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT_Type                        U01

#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT_GLOBAL_MEM                31:31
#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT_GLOBAL_MEM_End               31
#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT_GLOBAL_MEM_Start             31
#define MWV207REG_TP_INST_WORD6_ALU_LOAD_PWL_LUT_GLOBAL_MEM_Type             U01


#define MWV207REG_TP_INST_WORD7_INTILE_LIST_ADDRESS                         31:0
#define MWV207REG_TP_INST_WORD7_INTILE_LIST_ADDRESS_End                       31
#define MWV207REG_TP_INST_WORD7_INTILE_LIST_ADDRESS_Start                      0
#define MWV207REG_TP_INST_WORD7_INTILE_LIST_ADDRESS_Type                     U32


#define MWV207REG_TP_INST_WORD8_INTILE_XSIZE                                15:0
#define MWV207REG_TP_INST_WORD8_INTILE_XSIZE_End                              15
#define MWV207REG_TP_INST_WORD8_INTILE_XSIZE_Start                             0
#define MWV207REG_TP_INST_WORD8_INTILE_XSIZE_Type                            U16

#define MWV207REG_TP_INST_WORD8_INTILE_YSIZE                               31:16
#define MWV207REG_TP_INST_WORD8_INTILE_YSIZE_End                              31
#define MWV207REG_TP_INST_WORD8_INTILE_YSIZE_Start                            16
#define MWV207REG_TP_INST_WORD8_INTILE_YSIZE_Type                            U16


#define MWV207REG_TP_INST_WORD9_INTILE_XINC                                 15:0
#define MWV207REG_TP_INST_WORD9_INTILE_XINC_End                               15
#define MWV207REG_TP_INST_WORD9_INTILE_XINC_Start                              0
#define MWV207REG_TP_INST_WORD9_INTILE_XINC_Type                             U16

#define MWV207REG_TP_INST_WORD9_INTILE_YINC                                31:16
#define MWV207REG_TP_INST_WORD9_INTILE_YINC_End                               31
#define MWV207REG_TP_INST_WORD9_INTILE_YINC_Start                             16
#define MWV207REG_TP_INST_WORD9_INTILE_YINC_Type                             U16


#define MWV207REG_TP_INST_WORD10_INIMAGE_BASE_ADDRESS                       31:0
#define MWV207REG_TP_INST_WORD10_INIMAGE_BASE_ADDRESS_End                     31
#define MWV207REG_TP_INST_WORD10_INIMAGE_BASE_ADDRESS_Start                    0
#define MWV207REG_TP_INST_WORD10_INIMAGE_BASE_ADDRESS_Type                   U32


#define MWV207REG_TP_INST_WORD11_ALU_LOAD_PWL_ADDRESS                       31:0
#define MWV207REG_TP_INST_WORD11_ALU_LOAD_PWL_ADDRESS_End                     31
#define MWV207REG_TP_INST_WORD11_ALU_LOAD_PWL_ADDRESS_Start                    0
#define MWV207REG_TP_INST_WORD11_ALU_LOAD_PWL_ADDRESS_Type                   U32


#define MWV207REG_TP_INST_WORD12_OUTTILE_SKIP_ATBORDER                       0:0
#define MWV207REG_TP_INST_WORD12_OUTTILE_SKIP_ATBORDER_End                     0
#define MWV207REG_TP_INST_WORD12_OUTTILE_SKIP_ATBORDER_Start                   0
#define MWV207REG_TP_INST_WORD12_OUTTILE_SKIP_ATBORDER_Type                  U01
#define   MWV207REG_TP_INST_WORD12_OUTTILE_SKIP_ATBORDER_OUTPUT_ZERO_FOR_BORDER_PIXEL 0x0
#define   MWV207REG_TP_INST_WORD12_OUTTILE_SKIP_ATBORDER_DROP_OUTPUT_FOR_BORDER_PIXEL 0x1

#define MWV207REG_TP_INST_WORD12_OUT_GLOBAL_MEM                              1:1
#define MWV207REG_TP_INST_WORD12_OUT_GLOBAL_MEM_End                            1
#define MWV207REG_TP_INST_WORD12_OUT_GLOBAL_MEM_Start                          1
#define MWV207REG_TP_INST_WORD12_OUT_GLOBAL_MEM_Type                         U01

#define MWV207REG_TP_INST_WORD12_OUT_LOOP1_RESET                             2:2
#define MWV207REG_TP_INST_WORD12_OUT_LOOP1_RESET_End                           2
#define MWV207REG_TP_INST_WORD12_OUT_LOOP1_RESET_Start                         2
#define MWV207REG_TP_INST_WORD12_OUT_LOOP1_RESET_Type                        U01
#define   MWV207REG_TP_INST_WORD12_OUT_LOOP1_RESET_LOOP_COUNT_MET            0x0
#define   MWV207REG_TP_INST_WORD12_OUT_LOOP1_RESET_LAST_PIXEL_OF_ROW_IN_TILE 0x1

#define MWV207REG_TP_INST_WORD12_OUT_LOOP2_RESET                             3:3
#define MWV207REG_TP_INST_WORD12_OUT_LOOP2_RESET_End                           3
#define MWV207REG_TP_INST_WORD12_OUT_LOOP2_RESET_Start                         3
#define MWV207REG_TP_INST_WORD12_OUT_LOOP2_RESET_Type                        U01
#define   MWV207REG_TP_INST_WORD12_OUT_LOOP2_RESET_LOOP_COUNT_MET            0x0
#define   MWV207REG_TP_INST_WORD12_OUT_LOOP2_RESET_LAST_PIXEL_OF_2D_TILE     0x1

#define MWV207REG_TP_INST_WORD12_OUT_LOOP3_RESET                             4:4
#define MWV207REG_TP_INST_WORD12_OUT_LOOP3_RESET_End                           4
#define MWV207REG_TP_INST_WORD12_OUT_LOOP3_RESET_Start                         4
#define MWV207REG_TP_INST_WORD12_OUT_LOOP3_RESET_Type                        U01
#define   MWV207REG_TP_INST_WORD12_OUT_LOOP3_RESET_LOOP_COUNT_MET            0x0
#define   MWV207REG_TP_INST_WORD12_OUT_LOOP3_RESET_LAST_PIXEL_OF_2D_TILE     0x1

#define MWV207REG_TP_INST_WORD12_OUT_BRICK_MODE                              5:5
#define MWV207REG_TP_INST_WORD12_OUT_BRICK_MODE_End                            5
#define MWV207REG_TP_INST_WORD12_OUT_BRICK_MODE_Start                          5
#define MWV207REG_TP_INST_WORD12_OUT_BRICK_MODE_Type                         U01

#define MWV207REG_TP_INST_WORD12_ALU_Z_FILTER_MODE                           6:6
#define MWV207REG_TP_INST_WORD12_ALU_Z_FILTER_MODE_End                         6
#define MWV207REG_TP_INST_WORD12_ALU_Z_FILTER_MODE_Start                       6
#define MWV207REG_TP_INST_WORD12_ALU_Z_FILTER_MODE_Type                      U01

#define MWV207REG_TP_INST_WORD12_FLUSH_CLIENT_ID                             7:7
#define MWV207REG_TP_INST_WORD12_FLUSH_CLIENT_ID_End                           7
#define MWV207REG_TP_INST_WORD12_FLUSH_CLIENT_ID_Start                         7
#define MWV207REG_TP_INST_WORD12_FLUSH_CLIENT_ID_Type                        U01

#define MWV207REG_TP_INST_WORD12_INWINDOW_ZSTART_OVERFETCH                   9:8
#define MWV207REG_TP_INST_WORD12_INWINDOW_ZSTART_OVERFETCH_End                 9
#define MWV207REG_TP_INST_WORD12_INWINDOW_ZSTART_OVERFETCH_Start               8
#define MWV207REG_TP_INST_WORD12_INWINDOW_ZSTART_OVERFETCH_Type              U02

#define MWV207REG_TP_INST_WORD12_TP_SOFTMAX_ENABLE                         10:10
#define MWV207REG_TP_INST_WORD12_TP_SOFTMAX_ENABLE_End                        10
#define MWV207REG_TP_INST_WORD12_TP_SOFTMAX_ENABLE_Start                      10
#define MWV207REG_TP_INST_WORD12_TP_SOFTMAX_ENABLE_Type                      U01

#define MWV207REG_TP_INST_WORD12_INWINDOW_ZEND_OVERFETCH                   12:11
#define MWV207REG_TP_INST_WORD12_INWINDOW_ZEND_OVERFETCH_End                  12
#define MWV207REG_TP_INST_WORD12_INWINDOW_ZEND_OVERFETCH_Start                11
#define MWV207REG_TP_INST_WORD12_INWINDOW_ZEND_OVERFETCH_Type                U02

#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_MODE                         13:13
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_MODE_End                        13
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_MODE_Start                      13
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_MODE_Type                      U01

#define MWV207REG_TP_INST_WORD12_ALU_SQUARE_PRESHIFT                       17:14
#define MWV207REG_TP_INST_WORD12_ALU_SQUARE_PRESHIFT_End                      17
#define MWV207REG_TP_INST_WORD12_ALU_SQUARE_PRESHIFT_Start                    14
#define MWV207REG_TP_INST_WORD12_ALU_SQUARE_PRESHIFT_Type                    U04

#define MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE                         20:18
#define MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_End                        20
#define MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_Start                      18
#define MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_Type                      U03
#define   MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_UINT8                   0x0
#define   MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_FP16                    0x1
#define   MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_INT8                    0x2
#define   MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_UINT16                  0x3
#define   MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_INT16                   0x4
#define   MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_FP32                    0x5
#define   MWV207REG_TP_INST_WORD12_INIMAGE_DATA_TYPE_BFP16                   0x6

#define MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE                       23:21
#define MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_End                      23
#define MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_Start                    21
#define MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_Type                    U03
#define   MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_UINT8                 0x0
#define   MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_FP16                  0x1
#define   MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_INT8                  0x2
#define   MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_UINT16                0x3
#define   MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_INT16                 0x4
#define   MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_FP32                  0x5
#define   MWV207REG_TP_INST_WORD12_OUTIMPAGE_DATA_TYPE_BFP16                 0x6

#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_OP_TYPE                      25:24
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_OP_TYPE_End                     25
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_OP_TYPE_Start                   24
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_OP_TYPE_Type                   U02
#define   MWV207REG_TP_INST_WORD12_ELEMENT_WISE_OP_TYPE_ADD                  0x0
#define   MWV207REG_TP_INST_WORD12_ELEMENT_WISE_OP_TYPE_SUB                  0x1
#define   MWV207REG_TP_INST_WORD12_ELEMENT_WISE_OP_TYPE_MULTIPLY             0x2

#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_XSIZE                26:26
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_XSIZE_End               26
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_XSIZE_Start             26
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_XSIZE_Type             U01

#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_YSIZE                27:27
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_YSIZE_End               27
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_YSIZE_Start             27
#define MWV207REG_TP_INST_WORD12_ELEMENT_WISE_TENSORA_YSIZE_Type             U01

#define MWV207REG_TP_INST_WORD12_ALU_PWL_SIGN_SUPPORT                      28:28
#define MWV207REG_TP_INST_WORD12_ALU_PWL_SIGN_SUPPORT_End                     28
#define MWV207REG_TP_INST_WORD12_ALU_PWL_SIGN_SUPPORT_Start                   28
#define MWV207REG_TP_INST_WORD12_ALU_PWL_SIGN_SUPPORT_Type                   U01

#define MWV207REG_TP_INST_WORD12_ALU_RELU_ENABLE                           29:29
#define MWV207REG_TP_INST_WORD12_ALU_RELU_ENABLE_End                          29
#define MWV207REG_TP_INST_WORD12_ALU_RELU_ENABLE_Start                        29
#define MWV207REG_TP_INST_WORD12_ALU_RELU_ENABLE_Type                        U01

#define MWV207REG_TP_INST_WORD12_NO_FLUSH                                  30:30
#define MWV207REG_TP_INST_WORD12_NO_FLUSH_End                                 30
#define MWV207REG_TP_INST_WORD12_NO_FLUSH_Start                               30
#define MWV207REG_TP_INST_WORD12_NO_FLUSH_Type                               U01

#define MWV207REG_TP_INST_WORD12_LAST                                      31:31
#define MWV207REG_TP_INST_WORD12_LAST_End                                     31
#define MWV207REG_TP_INST_WORD12_LAST_Start                                   31
#define MWV207REG_TP_INST_WORD12_LAST_Type                                   U01


#define MWV207REG_TP_INST_WORD13_OUT_BASE_ADDRESS                           31:0
#define MWV207REG_TP_INST_WORD13_OUT_BASE_ADDRESS_End                         31
#define MWV207REG_TP_INST_WORD13_OUT_BASE_ADDRESS_Start                        0
#define MWV207REG_TP_INST_WORD13_OUT_BASE_ADDRESS_Type                       U32


#define MWV207REG_TP_INST_WORD14_OUT_LOOP0_ADDR_INC                         31:0
#define MWV207REG_TP_INST_WORD14_OUT_LOOP0_ADDR_INC_End                       31
#define MWV207REG_TP_INST_WORD14_OUT_LOOP0_ADDR_INC_Start                      0
#define MWV207REG_TP_INST_WORD14_OUT_LOOP0_ADDR_INC_Type                     U32


#define MWV207REG_TP_INST_WORD15_OUT_LOOP1_ADDR_INC                         31:0
#define MWV207REG_TP_INST_WORD15_OUT_LOOP1_ADDR_INC_End                       31
#define MWV207REG_TP_INST_WORD15_OUT_LOOP1_ADDR_INC_Start                      0
#define MWV207REG_TP_INST_WORD15_OUT_LOOP1_ADDR_INC_Type                     U32


#define MWV207REG_TP_INST_WORD16_OUT_LOOP0_COUNT                            15:0
#define MWV207REG_TP_INST_WORD16_OUT_LOOP0_COUNT_End                          15
#define MWV207REG_TP_INST_WORD16_OUT_LOOP0_COUNT_Start                         0
#define MWV207REG_TP_INST_WORD16_OUT_LOOP0_COUNT_Type                        U16

#define MWV207REG_TP_INST_WORD16_OUT_LOOP1_COUNT                           31:16
#define MWV207REG_TP_INST_WORD16_OUT_LOOP1_COUNT_End                          31
#define MWV207REG_TP_INST_WORD16_OUT_LOOP1_COUNT_Start                        16
#define MWV207REG_TP_INST_WORD16_OUT_LOOP1_COUNT_Type                        U16


#define MWV207REG_TP_INST_WORD17_OUT_LOOP2_ADDR_INC                         31:0
#define MWV207REG_TP_INST_WORD17_OUT_LOOP2_ADDR_INC_End                       31
#define MWV207REG_TP_INST_WORD17_OUT_LOOP2_ADDR_INC_Start                      0
#define MWV207REG_TP_INST_WORD17_OUT_LOOP2_ADDR_INC_Type                     U32


#define MWV207REG_TP_INST_WORD18_OUT_LOOP3_ADDR_INC                         31:0
#define MWV207REG_TP_INST_WORD18_OUT_LOOP3_ADDR_INC_End                       31
#define MWV207REG_TP_INST_WORD18_OUT_LOOP3_ADDR_INC_Start                      0
#define MWV207REG_TP_INST_WORD18_OUT_LOOP3_ADDR_INC_Type                     U32


#define MWV207REG_TP_INST_WORD19_OUT_LOOP2_COUNT                            15:0
#define MWV207REG_TP_INST_WORD19_OUT_LOOP2_COUNT_End                          15
#define MWV207REG_TP_INST_WORD19_OUT_LOOP2_COUNT_Start                         0
#define MWV207REG_TP_INST_WORD19_OUT_LOOP2_COUNT_Type                        U16

#define MWV207REG_TP_INST_WORD19_OUT_LOOP3_COUNT                           31:16
#define MWV207REG_TP_INST_WORD19_OUT_LOOP3_COUNT_End                          31
#define MWV207REG_TP_INST_WORD19_OUT_LOOP3_COUNT_Start                        16
#define MWV207REG_TP_INST_WORD19_OUT_LOOP3_COUNT_Type                        U16


#define MWV207REG_TP_INST_WORD20_OUT_LOOP4_ADDR_INC                         31:0
#define MWV207REG_TP_INST_WORD20_OUT_LOOP4_ADDR_INC_End                       31
#define MWV207REG_TP_INST_WORD20_OUT_LOOP4_ADDR_INC_Start                      0
#define MWV207REG_TP_INST_WORD20_OUT_LOOP4_ADDR_INC_Type                     U32


#define MWV207REG_TP_INST_WORD21_OUT_LOOP5_ADDR_INC                         31:0
#define MWV207REG_TP_INST_WORD21_OUT_LOOP5_ADDR_INC_End                       31
#define MWV207REG_TP_INST_WORD21_OUT_LOOP5_ADDR_INC_Start                      0
#define MWV207REG_TP_INST_WORD21_OUT_LOOP5_ADDR_INC_Type                     U32


#define MWV207REG_TP_INST_WORD22_OUT_LOOP4_COUNT                            15:0
#define MWV207REG_TP_INST_WORD22_OUT_LOOP4_COUNT_End                          15
#define MWV207REG_TP_INST_WORD22_OUT_LOOP4_COUNT_Start                         0
#define MWV207REG_TP_INST_WORD22_OUT_LOOP4_COUNT_Type                        U16

#define MWV207REG_TP_INST_WORD22_OUT_LOOP5_COUNT                           31:16
#define MWV207REG_TP_INST_WORD22_OUT_LOOP5_COUNT_End                          31
#define MWV207REG_TP_INST_WORD22_OUT_LOOP5_COUNT_Start                        16
#define MWV207REG_TP_INST_WORD22_OUT_LOOP5_COUNT_Type                        U16


#define MWV207REG_TP_INST_WORD23_OUT_LOOP6_ADDR_INC                         31:0
#define MWV207REG_TP_INST_WORD23_OUT_LOOP6_ADDR_INC_End                       31
#define MWV207REG_TP_INST_WORD23_OUT_LOOP6_ADDR_INC_Start                      0
#define MWV207REG_TP_INST_WORD23_OUT_LOOP6_ADDR_INC_Type                     U32


#define MWV207REG_TP_INST_WORD24_ALU_FILTER_PWL_SWAP                         0:0
#define MWV207REG_TP_INST_WORD24_ALU_FILTER_PWL_SWAP_End                       0
#define MWV207REG_TP_INST_WORD24_ALU_FILTER_PWL_SWAP_Start                     0
#define MWV207REG_TP_INST_WORD24_ALU_FILTER_PWL_SWAP_Type                    U01
#define   MWV207REG_TP_INST_WORD24_ALU_FILTER_PWL_SWAP_REGULAR_TP_DATA_FLOW  0x0
#define   MWV207REG_TP_INST_WORD24_ALU_FILTER_PWL_SWAP_SWAP_FILTER_AND_PWL_FUNCTIONS 0x1

#define MWV207REG_TP_INST_WORD24_FLOAT_ROUNDING_MODE                         2:1
#define MWV207REG_TP_INST_WORD24_FLOAT_ROUNDING_MODE_End                       2
#define MWV207REG_TP_INST_WORD24_FLOAT_ROUNDING_MODE_Start                     1
#define MWV207REG_TP_INST_WORD24_FLOAT_ROUNDING_MODE_Type                    U02
#define   MWV207REG_TP_INST_WORD24_FLOAT_ROUNDING_MODE_NOT_USED              0x0
#define   MWV207REG_TP_INST_WORD24_FLOAT_ROUNDING_MODE_RTNE                  0x1
#define   MWV207REG_TP_INST_WORD24_FLOAT_ROUNDING_MODE_RTZ                   0x2

#define MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE                       4:3
#define MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE_End                     4
#define MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE_Start                   3
#define MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE_Type                  U02
#define   MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE_SIMPLE_ROUNDING     0x0
#define   MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE_RTNE                0x1
#define   MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE_RTZ                 0x2
#define   MWV207REG_TP_INST_WORD24_INTEGER_ROUNDING_MODE_RTNI                0x3

#define MWV207REG_TP_INST_WORD24_ALU_INPUT_PRESHIFT                          9:5
#define MWV207REG_TP_INST_WORD24_ALU_INPUT_PRESHIFT_End                        9
#define MWV207REG_TP_INST_WORD24_ALU_INPUT_PRESHIFT_Start                      5
#define MWV207REG_TP_INST_WORD24_ALU_INPUT_PRESHIFT_Type                     U05

#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT                      14:10
#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT_End                     14
#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT_Start                   10
#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT_Type                   U05

#define MWV207REG_TP_INST_WORD24_ALU_REORDER_BITS_USED                     18:15
#define MWV207REG_TP_INST_WORD24_ALU_REORDER_BITS_USED_End                    18
#define MWV207REG_TP_INST_WORD24_ALU_REORDER_BITS_USED_Start                  15
#define MWV207REG_TP_INST_WORD24_ALU_REORDER_BITS_USED_Type                  U04

#define MWV207REG_TP_INST_WORD24_ALU_REORDER_LOOP2_MODE                    19:19
#define MWV207REG_TP_INST_WORD24_ALU_REORDER_LOOP2_MODE_End                   19
#define MWV207REG_TP_INST_WORD24_ALU_REORDER_LOOP2_MODE_Start                 19
#define MWV207REG_TP_INST_WORD24_ALU_REORDER_LOOP2_MODE_Type                 U01

#define MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY               21:20
#define MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY_End              21
#define MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY_Start            20
#define MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY_Type            U02
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY_STAY_LEAST_RECENTLY_USED 0x0
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY_SWITCH_TO_MOST_RECENTLY_USED 0x1
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY_HORIZONTAL_TILE_SLIDING 0x2
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_CACHE_EVICT_POLICY_VERTICAL_TILE_SLIDING 0x3

#define MWV207REG_TP_INST_WORD24_OUT_IMAGE_CACHE_EVICT_POLICY              23:22
#define MWV207REG_TP_INST_WORD24_OUT_IMAGE_CACHE_EVICT_POLICY_End             23
#define MWV207REG_TP_INST_WORD24_OUT_IMAGE_CACHE_EVICT_POLICY_Start           22
#define MWV207REG_TP_INST_WORD24_OUT_IMAGE_CACHE_EVICT_POLICY_Type           U02
#define   MWV207REG_TP_INST_WORD24_OUT_IMAGE_CACHE_EVICT_POLICY_STAY_LEAST_RECENTLY_USED 0x0
#define   MWV207REG_TP_INST_WORD24_OUT_IMAGE_CACHE_EVICT_POLICY_SWITCH_TO_MOST_RECENTLY_USED 0x1
#define   MWV207REG_TP_INST_WORD24_OUT_IMAGE_CACHE_EVICT_POLICY_HORIZONTAL_TILE_SLIDING 0x2

#define MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE                      25:24
#define MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE_End                     25
#define MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE_Start                   24
#define MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE_Type                   U02
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE_CONSTANT             0x0
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE_CLAMP                0x1
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE_MIRROR_SYMMETRIC     0x2
#define   MWV207REG_TP_INST_WORD24_IN_IMAGE_BORDER_MODE_MIRROR_REFLECT       0x3


#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT_BIT6TO5              27:26
#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT_BIT6TO5_End             27
#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT_BIT6TO5_Start           26
#define MWV207REG_TP_INST_WORD24_ALU_OUTPUT_POSTSHIFT_BIT6TO5_Type           U02

#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORA_ZSIZE                28:28
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORA_ZSIZE_End               28
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORA_ZSIZE_Start             28
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORA_ZSIZE_Type             U01

#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_XSIZE                29:29
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_XSIZE_End               29
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_XSIZE_Start             29
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_XSIZE_Type             U01

#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_YSIZE                30:30
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_YSIZE_End               30
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_YSIZE_Start             30
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_YSIZE_Type             U01

#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_ZSIZE                31:31
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_ZSIZE_End               31
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_ZSIZE_Start             31
#define MWV207REG_TP_INST_WORD24_ELEMENT_WISE_TENSORB_ZSIZE_Type             U01


#define MWV207REG_TP_INST_WORD25_INIMAGE_CIRCULAR_BUF_SIZE                  25:0
#define MWV207REG_TP_INST_WORD25_INIMAGE_CIRCULAR_BUF_SIZE_End                25
#define MWV207REG_TP_INST_WORD25_INIMAGE_CIRCULAR_BUF_SIZE_Start               0
#define MWV207REG_TP_INST_WORD25_INIMAGE_CIRCULAR_BUF_SIZE_Type              U26


#define MWV207REG_TP_INST_WORD26_INIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1        25:0
#define MWV207REG_TP_INST_WORD26_INIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_End      25
#define MWV207REG_TP_INST_WORD26_INIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Start     0
#define MWV207REG_TP_INST_WORD26_INIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Type    U26


#define MWV207REG_TP_INST_WORD27_OUTIMAGE_CIRCULAR_BUF_SIZE                 25:0
#define MWV207REG_TP_INST_WORD27_OUTIMAGE_CIRCULAR_BUF_SIZE_End               25
#define MWV207REG_TP_INST_WORD27_OUTIMAGE_CIRCULAR_BUF_SIZE_Start              0
#define MWV207REG_TP_INST_WORD27_OUTIMAGE_CIRCULAR_BUF_SIZE_Type             U26


#define MWV207REG_TP_INST_WORD28_OUTIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1       25:0
#define MWV207REG_TP_INST_WORD28_OUTIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_End     25
#define MWV207REG_TP_INST_WORD28_OUTIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Start    0
#define MWV207REG_TP_INST_WORD28_OUTIMAGE_CIRCULAR_BUF_END_ADDR_PLUS1_Type   U26



#define MWV207REG_TP_INST_WORD29_IN_IMAGE_BORDER_CONSTANT                   15:0
#define MWV207REG_TP_INST_WORD29_IN_IMAGE_BORDER_CONSTANT_End                 15
#define MWV207REG_TP_INST_WORD29_IN_IMAGE_BORDER_CONSTANT_Start                0
#define MWV207REG_TP_INST_WORD29_IN_IMAGE_BORDER_CONSTANT_Type               U16

#define MWV207REG_TP_INST_WORD29_COEF_ZERO_POINT                           23:16
#define MWV207REG_TP_INST_WORD29_COEF_ZERO_POINT_End                          23
#define MWV207REG_TP_INST_WORD29_COEF_ZERO_POINT_Start                        16
#define MWV207REG_TP_INST_WORD29_COEF_ZERO_POINT_Type                        U08

#define MWV207REG_TP_INST_WORD29_IN_IMAGE_ZERO_POINT                       31:24
#define MWV207REG_TP_INST_WORD29_IN_IMAGE_ZERO_POINT_End                      31
#define MWV207REG_TP_INST_WORD29_IN_IMAGE_ZERO_POINT_Start                    24
#define MWV207REG_TP_INST_WORD29_IN_IMAGE_ZERO_POINT_Type                    U08


#define MWV207REG_TP_INST_WORD30_OUT_IMAGE_ZERO_POINT                        7:0
#define MWV207REG_TP_INST_WORD30_OUT_IMAGE_ZERO_POINT_End                      7
#define MWV207REG_TP_INST_WORD30_OUT_IMAGE_ZERO_POINT_Start                    0
#define MWV207REG_TP_INST_WORD30_OUT_IMAGE_ZERO_POINT_Type                   U08


#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER                 22:8
#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER_End               22
#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER_Start              8
#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER_Type             U15


#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER_BIT22_TO15     30:23
#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER_BIT22_TO15_End    30
#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER_BIT22_TO15_Start  23
#define MWV207REG_TP_INST_WORD30_ALU_OUTPUT_POST_MULTIPLIER_BIT22_TO15_Type  U08




#define MWV207REG_TP_INST_WORD32_INIMAGE_BASE_ADDR_BIT39_TO32                7:0
#define MWV207REG_TP_INST_WORD32_INIMAGE_BASE_ADDR_BIT39_TO32_End              7
#define MWV207REG_TP_INST_WORD32_INIMAGE_BASE_ADDR_BIT39_TO32_Start            0
#define MWV207REG_TP_INST_WORD32_INIMAGE_BASE_ADDR_BIT39_TO32_Type           U08


#define MWV207REG_TP_INST_WORD32_ALU_LOAD_PWL_ADDR_BIT39_TO32               15:8
#define MWV207REG_TP_INST_WORD32_ALU_LOAD_PWL_ADDR_BIT39_TO32_End             15
#define MWV207REG_TP_INST_WORD32_ALU_LOAD_PWL_ADDR_BIT39_TO32_Start            8
#define MWV207REG_TP_INST_WORD32_ALU_LOAD_PWL_ADDR_BIT39_TO32_Type           U08


#define MWV207REG_TP_INST_WORD32_OUT_BASE_ADDR_BIT39_TO32                  23:16
#define MWV207REG_TP_INST_WORD32_OUT_BASE_ADDR_BIT39_TO32_End                 23
#define MWV207REG_TP_INST_WORD32_OUT_BASE_ADDR_BIT39_TO32_Start               16
#define MWV207REG_TP_INST_WORD32_OUT_BASE_ADDR_BIT39_TO32_Type               U08


#define MWV207REG_TP_INST_WORD32_OUT_LOOP0_INC_BIT39_TO32                  31:24
#define MWV207REG_TP_INST_WORD32_OUT_LOOP0_INC_BIT39_TO32_End                 31
#define MWV207REG_TP_INST_WORD32_OUT_LOOP0_INC_BIT39_TO32_Start               24
#define MWV207REG_TP_INST_WORD32_OUT_LOOP0_INC_BIT39_TO32_Type               U08



#define MWV207REG_TP_INST_WORD33_OUT_LOOP1_INC_BIT39_TO32                    7:0
#define MWV207REG_TP_INST_WORD33_OUT_LOOP1_INC_BIT39_TO32_End                  7
#define MWV207REG_TP_INST_WORD33_OUT_LOOP1_INC_BIT39_TO32_Start                0
#define MWV207REG_TP_INST_WORD33_OUT_LOOP1_INC_BIT39_TO32_Type               U08


#define MWV207REG_TP_INST_WORD33_OUT_LOOP2_INC_BIT39_TO32                   15:8
#define MWV207REG_TP_INST_WORD33_OUT_LOOP2_INC_BIT39_TO32_End                 15
#define MWV207REG_TP_INST_WORD33_OUT_LOOP2_INC_BIT39_TO32_Start                8
#define MWV207REG_TP_INST_WORD33_OUT_LOOP2_INC_BIT39_TO32_Type               U08


#define MWV207REG_TP_INST_WORD33_OUT_LOOP3_INC_BIT39_TO32                  23:16
#define MWV207REG_TP_INST_WORD33_OUT_LOOP3_INC_BIT39_TO32_End                 23
#define MWV207REG_TP_INST_WORD33_OUT_LOOP3_INC_BIT39_TO32_Start               16
#define MWV207REG_TP_INST_WORD33_OUT_LOOP3_INC_BIT39_TO32_Type               U08


#define MWV207REG_TP_INST_WORD33_OUT_LOOP4_INC_BIT39_TO32                  31:24
#define MWV207REG_TP_INST_WORD33_OUT_LOOP4_INC_BIT39_TO32_End                 31
#define MWV207REG_TP_INST_WORD33_OUT_LOOP4_INC_BIT39_TO32_Start               24
#define MWV207REG_TP_INST_WORD33_OUT_LOOP4_INC_BIT39_TO32_Type               U08



#define MWV207REG_TP_INST_WORD34_OUT_LOOP5_INC_BIT39_TO32                    7:0
#define MWV207REG_TP_INST_WORD34_OUT_LOOP5_INC_BIT39_TO32_End                  7
#define MWV207REG_TP_INST_WORD34_OUT_LOOP5_INC_BIT39_TO32_Start                0
#define MWV207REG_TP_INST_WORD34_OUT_LOOP5_INC_BIT39_TO32_Type               U08


#define MWV207REG_TP_INST_WORD34_OUT_LOOP6_INC_BIT39_TO32                   15:8
#define MWV207REG_TP_INST_WORD34_OUT_LOOP6_INC_BIT39_TO32_End                 15
#define MWV207REG_TP_INST_WORD34_OUT_LOOP6_INC_BIT39_TO32_Start                8
#define MWV207REG_TP_INST_WORD34_OUT_LOOP6_INC_BIT39_TO32_Type               U08


#define MWV207REG_TP_INST_WORD34_OUT_LOOP0_COUNT_BIT31_TO16                31:16
#define MWV207REG_TP_INST_WORD34_OUT_LOOP0_COUNT_BIT31_TO16_End               31
#define MWV207REG_TP_INST_WORD34_OUT_LOOP0_COUNT_BIT31_TO16_Start             16
#define MWV207REG_TP_INST_WORD34_OUT_LOOP0_COUNT_BIT31_TO16_Type             U16



#define MWV207REG_TP_INST_WORD35_OUT_LOOP1_COUNT_BIT31_TO16                 15:0
#define MWV207REG_TP_INST_WORD35_OUT_LOOP1_COUNT_BIT31_TO16_End               15
#define MWV207REG_TP_INST_WORD35_OUT_LOOP1_COUNT_BIT31_TO16_Start              0
#define MWV207REG_TP_INST_WORD35_OUT_LOOP1_COUNT_BIT31_TO16_Type             U16


#define MWV207REG_TP_INST_WORD35_OUT_LOOP2_COUNT_BIT31_TO16                31:16
#define MWV207REG_TP_INST_WORD35_OUT_LOOP2_COUNT_BIT31_TO16_End               31
#define MWV207REG_TP_INST_WORD35_OUT_LOOP2_COUNT_BIT31_TO16_Start             16
#define MWV207REG_TP_INST_WORD35_OUT_LOOP2_COUNT_BIT31_TO16_Type             U16



#define MWV207REG_TP_INST_WORD36_OUT_LOOP3_COUNT_BIT31_TO16                 15:0
#define MWV207REG_TP_INST_WORD36_OUT_LOOP3_COUNT_BIT31_TO16_End               15
#define MWV207REG_TP_INST_WORD36_OUT_LOOP3_COUNT_BIT31_TO16_Start              0
#define MWV207REG_TP_INST_WORD36_OUT_LOOP3_COUNT_BIT31_TO16_Type             U16


#define MWV207REG_TP_INST_WORD36_OUT_LOOP4_COUNT_BIT31_TO16                31:16
#define MWV207REG_TP_INST_WORD36_OUT_LOOP4_COUNT_BIT31_TO16_End               31
#define MWV207REG_TP_INST_WORD36_OUT_LOOP4_COUNT_BIT31_TO16_Start             16
#define MWV207REG_TP_INST_WORD36_OUT_LOOP4_COUNT_BIT31_TO16_Type             U16



#define MWV207REG_TP_INST_WORD37_OUT_LOOP5_COUNT_BIT31_TO16                 15:0
#define MWV207REG_TP_INST_WORD37_OUT_LOOP5_COUNT_BIT31_TO16_End               15
#define MWV207REG_TP_INST_WORD37_OUT_LOOP5_COUNT_BIT31_TO16_Start              0
#define MWV207REG_TP_INST_WORD37_OUT_LOOP5_COUNT_BIT31_TO16_Type             U16


#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CBUF_SIZE_BIT39_TO32             23:16
#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CBUF_SIZE_BIT39_TO32_End            23
#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CBUF_SIZE_BIT39_TO32_Start          16
#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CBUF_SIZE_BIT39_TO32_Type          U08

#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32     31:24
#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_End    31
#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Start  24
#define MWV207REG_TP_INST_WORD37_IN_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Type  U08


#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_BUF_SIZE_BIT39_TO32            7:0
#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_BUF_SIZE_BIT39_TO32_End          7
#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_BUF_SIZE_BIT39_TO32_Start        0
#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_BUF_SIZE_BIT39_TO32_Type       U08

#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32     15:8
#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_End   15
#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Start  8
#define MWV207REG_TP_INST_WORD38_OUT_IMAGE_CB_END_ADDR_PLUS1_BIT39_TO32_Type U08


#define MWV207REG_TP_INST_WORD38_IN_TILE_LIST_ADDR_BIT39_TO32              23:16
#define MWV207REG_TP_INST_WORD38_IN_TILE_LIST_ADDR_BIT39_TO32_End             23
#define MWV207REG_TP_INST_WORD38_IN_TILE_LIST_ADDR_BIT39_TO32_Start           16
#define MWV207REG_TP_INST_WORD38_IN_TILE_LIST_ADDR_BIT39_TO32_Type           U08



#define MWV207REG_TP_INST_WORD39_IN_IMAGE_XSIZE_BIT31_TO16                  15:0
#define MWV207REG_TP_INST_WORD39_IN_IMAGE_XSIZE_BIT31_TO16_End                15
#define MWV207REG_TP_INST_WORD39_IN_IMAGE_XSIZE_BIT31_TO16_Start               0
#define MWV207REG_TP_INST_WORD39_IN_IMAGE_XSIZE_BIT31_TO16_Type              U16


#define MWV207REG_TP_INST_WORD39_IN_IMAGE_YSIZE_BIT31_TO16                 31:16
#define MWV207REG_TP_INST_WORD39_IN_IMAGE_YSIZE_BIT31_TO16_End                31
#define MWV207REG_TP_INST_WORD39_IN_IMAGE_YSIZE_BIT31_TO16_Start              16
#define MWV207REG_TP_INST_WORD39_IN_IMAGE_YSIZE_BIT31_TO16_Type              U16



#define MWV207REG_TP_INST_WORD40_IN_IMAGE_ZSIZE_BIT31_TO16                  15:0
#define MWV207REG_TP_INST_WORD40_IN_IMAGE_ZSIZE_BIT31_TO16_End                15
#define MWV207REG_TP_INST_WORD40_IN_IMAGE_ZSIZE_BIT31_TO16_Start               0
#define MWV207REG_TP_INST_WORD40_IN_IMAGE_ZSIZE_BIT31_TO16_Type              U16


#define MWV207REG_TP_INST_WORD40_IN_IMAGE_STRIDE_BIT31_TO16                31:16
#define MWV207REG_TP_INST_WORD40_IN_IMAGE_STRIDE_BIT31_TO16_End               31
#define MWV207REG_TP_INST_WORD40_IN_IMAGE_STRIDE_BIT31_TO16_Start             16
#define MWV207REG_TP_INST_WORD40_IN_IMAGE_STRIDE_BIT31_TO16_Type             U16



#define MWV207REG_TP_INST_WORD41_IN_WINDOW_XSTART_BIT31_TO16                15:0
#define MWV207REG_TP_INST_WORD41_IN_WINDOW_XSTART_BIT31_TO16_End              15
#define MWV207REG_TP_INST_WORD41_IN_WINDOW_XSTART_BIT31_TO16_Start             0
#define MWV207REG_TP_INST_WORD41_IN_WINDOW_XSTART_BIT31_TO16_Type            U16


#define MWV207REG_TP_INST_WORD41_IN_WINDOW_YSTART_BIT31_TO16               31:16
#define MWV207REG_TP_INST_WORD41_IN_WINDOW_YSTART_BIT31_TO16_End              31
#define MWV207REG_TP_INST_WORD41_IN_WINDOW_YSTART_BIT31_TO16_Start            16
#define MWV207REG_TP_INST_WORD41_IN_WINDOW_YSTART_BIT31_TO16_Type            U16



#define MWV207REG_TP_INST_WORD42_IN_WINDOW_XEND_BIT31_TO16                  15:0
#define MWV207REG_TP_INST_WORD42_IN_WINDOW_XEND_BIT31_TO16_End                15
#define MWV207REG_TP_INST_WORD42_IN_WINDOW_XEND_BIT31_TO16_Start               0
#define MWV207REG_TP_INST_WORD42_IN_WINDOW_XEND_BIT31_TO16_Type              U16


#define MWV207REG_TP_INST_WORD42_IN_WINDOW_YEND_BIT31_TO16                 31:16
#define MWV207REG_TP_INST_WORD42_IN_WINDOW_YEND_BIT31_TO16_End                31
#define MWV207REG_TP_INST_WORD42_IN_WINDOW_YEND_BIT31_TO16_Start              16
#define MWV207REG_TP_INST_WORD42_IN_WINDOW_YEND_BIT31_TO16_Type              U16



#define MWV207REG_TP_INST_WORD43_IN_TILE_XSIZE_BIT31_TO16                   15:0
#define MWV207REG_TP_INST_WORD43_IN_TILE_XSIZE_BIT31_TO16_End                 15
#define MWV207REG_TP_INST_WORD43_IN_TILE_XSIZE_BIT31_TO16_Start                0
#define MWV207REG_TP_INST_WORD43_IN_TILE_XSIZE_BIT31_TO16_Type               U16


#define MWV207REG_TP_INST_WORD43_IN_TILE_YSIZE_BIT31_TO16                  31:16
#define MWV207REG_TP_INST_WORD43_IN_TILE_YSIZE_BIT31_TO16_End                 31
#define MWV207REG_TP_INST_WORD43_IN_TILE_YSIZE_BIT31_TO16_Start               16
#define MWV207REG_TP_INST_WORD43_IN_TILE_YSIZE_BIT31_TO16_Type               U16



#define MWV207REG_TP_INST_WORD44_IN_TILE_XINC_BIT31_TO16                    15:0
#define MWV207REG_TP_INST_WORD44_IN_TILE_XINC_BIT31_TO16_End                  15
#define MWV207REG_TP_INST_WORD44_IN_TILE_XINC_BIT31_TO16_Start                 0
#define MWV207REG_TP_INST_WORD44_IN_TILE_XINC_BIT31_TO16_Type                U16


#define MWV207REG_TP_INST_WORD44_IN_TILE_YINC_BIT31_TO16                   31:16
#define MWV207REG_TP_INST_WORD44_IN_TILE_YINC_BIT31_TO16_End                  31
#define MWV207REG_TP_INST_WORD44_IN_TILE_YINC_BIT31_TO16_Start                16
#define MWV207REG_TP_INST_WORD44_IN_TILE_YINC_BIT31_TO16_Type                U16



#define MWV207REG_TP_INST_WORD45_IN_IMAGE_SLICE_BIT39_TO32                   7:0
#define MWV207REG_TP_INST_WORD45_IN_IMAGE_SLICE_BIT39_TO32_End                 7
#define MWV207REG_TP_INST_WORD45_IN_IMAGE_SLICE_BIT39_TO32_Start               0
#define MWV207REG_TP_INST_WORD45_IN_IMAGE_SLICE_BIT39_TO32_Type              U08



#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_HSIZE                        5:0
#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_HSIZE_End                      5
#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_HSIZE_Start                    0
#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_HSIZE_Type                   U06

#define MWV207REG_TPROI_POOL_INST_WORD0_HSTRIDE                              6:6
#define MWV207REG_TPROI_POOL_INST_WORD0_HSTRIDE_End                            6
#define MWV207REG_TPROI_POOL_INST_WORD0_HSTRIDE_Start                          6
#define MWV207REG_TPROI_POOL_INST_WORD0_HSTRIDE_Type                         U01
#define   MWV207REG_TPROI_POOL_INST_WORD0_HSTRIDE_HSIZE                      0x0
#define   MWV207REG_TPROI_POOL_INST_WORD0_HSTRIDE_HSIZE_MINUS_ONE            0x1

#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_VSIZE                       12:7
#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_VSIZE_End                     12
#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_VSIZE_Start                    7
#define MWV207REG_TPROI_POOL_INST_WORD0_POOLING_VSIZE_Type                   U06

#define MWV207REG_TPROI_POOL_INST_WORD0_VSTRIDE                            13:13
#define MWV207REG_TPROI_POOL_INST_WORD0_VSTRIDE_End                           13
#define MWV207REG_TPROI_POOL_INST_WORD0_VSTRIDE_Start                         13
#define MWV207REG_TPROI_POOL_INST_WORD0_VSTRIDE_Type                         U01
#define   MWV207REG_TPROI_POOL_INST_WORD0_VSTRIDE_VSIZE                      0x0
#define   MWV207REG_TPROI_POOL_INST_WORD0_VSTRIDE_VSIZE_MINUS_ONE            0x1

#define MWV207REG_TPROI_POOL_INST_WORD0_LAST                               15:15
#define MWV207REG_TPROI_POOL_INST_WORD0_LAST_End                              15
#define MWV207REG_TPROI_POOL_INST_WORD0_LAST_Start                            15
#define MWV207REG_TPROI_POOL_INST_WORD0_LAST_Type                            U01

#define MWV207REG_TPROI_POOL_INST_WORD0_XCOORD                             23:16
#define MWV207REG_TPROI_POOL_INST_WORD0_XCOORD_End                            23
#define MWV207REG_TPROI_POOL_INST_WORD0_XCOORD_Start                          16
#define MWV207REG_TPROI_POOL_INST_WORD0_XCOORD_Type                          U08

#define MWV207REG_TPROI_POOL_INST_WORD0_YCOORD                             31:24
#define MWV207REG_TPROI_POOL_INST_WORD0_YCOORD_End                            31
#define MWV207REG_TPROI_POOL_INST_WORD0_YCOORD_Start                          24
#define MWV207REG_TPROI_POOL_INST_WORD0_YCOORD_Type                          U08



#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_XCOORD                          7:0
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_XCOORD_End                        7
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_XCOORD_Start                      0
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_XCOORD_Type                     U08

#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_YCOORD                         15:8
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_YCOORD_End                       15
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_YCOORD_Start                      8
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_YCOORD_Type                     U08

#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_LAST                          16:16
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_LAST_End                         16
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_LAST_Start                       16
#define MWV207REG_TPROI_POOL_LIST_INST_WORD0_LAST_Type                       U01


#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_HINC                   15:0
#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_HINC_End                 15
#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_HINC_Start                0
#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_HINC_Type               U16

#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_VINC                  31:16
#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_VINC_End                 31
#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_VINC_Start               16
#define MWV207REG_TPROI_POOL_LIST_INST_WORD1_POOLING_VINC_Type               U16




#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_INIT_NUM_OF_INST              15:0
#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_INIT_NUM_OF_INST_End            15
#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_INIT_NUM_OF_INST_Start           0
#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_INIT_NUM_OF_INST_Type          U16


#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_LOOP_NUM_OF_INST             31:16
#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_LOOP_NUM_OF_INST_End            31
#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_LOOP_NUM_OF_INST_Start          16
#define MWV207REG_SP_INST_HDR_DWORD0_LOW_PROG_LOOP_NUM_OF_INST_Type          U16


#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_COMP_NUM_OF_INSTR            15:0
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_COMP_NUM_OF_INSTR_End          15
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_COMP_NUM_OF_INSTR_Start         0
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_COMP_NUM_OF_INSTR_Type        U16

#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_ROUNDING_MODE               16:16
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_ROUNDING_MODE_End              16
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_ROUNDING_MODE_Start            16
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_ROUNDING_MODE_Type            U01
#define   MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_ROUNDING_MODE_SP_RTNE       0x0
#define   MWV207REG_SP_INST_HDR_DWORD0_HIGH_PROG_ROUNDING_MODE_SP__STICKY    0x1

#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP                      18:17
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP_End                     18
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP_Start                   17
#define MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP_Type                   U02
#define   MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP_SINGLE_INPUT         0x0
#define   MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP_INTERLEAVE_TWO_INPUT 0x1
#define   MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP_V11                  0x2
#define   MWV207REG_SP_INST_HDR_DWORD0_HIGH_INPUT_SETUP_V12                  0x3



#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_OUTPUTS               7:0
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_OUTPUTS_End             7
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_OUTPUTS_Start           0
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_OUTPUTS_Type          U08

#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_FLUSH_CYCLES                15:8
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_FLUSH_CYCLES_End              15
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_FLUSH_CYCLES_Start             8
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_FLUSH_CYCLES_Type            U08


#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V11_WR              23:16
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V11_WR_End             23
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V11_WR_Start           16
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V11_WR_Type           U08


#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V12_WR              31:24
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V12_WR_End             31
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V12_WR_Start           24
#define MWV207REG_SP_INST_HDR_DWORD1_LOW_NUM_OF_IGN_LD_V12_WR_Type           U08



#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V11_RD               7:0
#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V11_RD_End             7
#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V11_RD_Start           0
#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V11_RD_Type          U08


#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V12_RD              15:8
#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V12_RD_End            15
#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V12_RD_Start           8
#define MWV207REG_SP_INST_HDR_DWORD1_HIGH_NUM_OF_IGN_LD_V12_RD_Type          U08


#define MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR                       1:0
#define MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR_End                     1
#define MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR_Start                   0
#define MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR_Type                  U02
#define   MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR_DIST_DISABLE        0x0
#define   MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR_SCALAR_GATHER       0x1
#define   MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR_VECTOR_GATHER       0x2
#define   MWV207REG_SP_INST_HDR_DWORD2_CH0_POST_RE_DISTR_VECTOR_SCATTER      0x3

#define MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR                       3:2
#define MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR_End                     3
#define MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR_Start                   2
#define MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR_Type                  U02
#define   MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR_DIST_DISABLE        0x0
#define   MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR_SCALAR_GATHER       0x1
#define   MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR_VECTOR_GATHER       0x2
#define   MWV207REG_SP_INST_HDR_DWORD2_CH1_POST_RE_DISTR_VECTOR_SCATTER      0x3

#define MWV207REG_SP_INST_HDR_DWORD2_V11_RESET_AT_START                      4:4
#define MWV207REG_SP_INST_HDR_DWORD2_V11_RESET_AT_START_End                    4
#define MWV207REG_SP_INST_HDR_DWORD2_V11_RESET_AT_START_Start                  4
#define MWV207REG_SP_INST_HDR_DWORD2_V11_RESET_AT_START_Type                 U01
#define   MWV207REG_SP_INST_HDR_DWORD2_V11_RESET_AT_START_ENABLE             0x1

#define MWV207REG_SP_INST_HDR_DWORD2_V12_RESET_AT_START                      5:5
#define MWV207REG_SP_INST_HDR_DWORD2_V12_RESET_AT_START_End                    5
#define MWV207REG_SP_INST_HDR_DWORD2_V12_RESET_AT_START_Start                  5
#define MWV207REG_SP_INST_HDR_DWORD2_V12_RESET_AT_START_Type                 U01
#define   MWV207REG_SP_INST_HDR_DWORD2_V12_RESET_AT_START_ENABLE             0x1

#define MWV207REG_SP_INST_HDR_DWORD2_V11_PUSH_POP_CFG                        6:6
#define MWV207REG_SP_INST_HDR_DWORD2_V11_PUSH_POP_CFG_End                      6
#define MWV207REG_SP_INST_HDR_DWORD2_V11_PUSH_POP_CFG_Start                    6
#define MWV207REG_SP_INST_HDR_DWORD2_V11_PUSH_POP_CFG_Type                   U01
#define   MWV207REG_SP_INST_HDR_DWORD2_V11_PUSH_POP_CFG_EVERY_WRRD           0x0
#define   MWV207REG_SP_INST_HDR_DWORD2_V11_PUSH_POP_CFG_USE_ELE_MARKER       0x1

#define MWV207REG_SP_INST_HDR_DWORD2_V12_PUSH_POP_CFG                        7:7
#define MWV207REG_SP_INST_HDR_DWORD2_V12_PUSH_POP_CFG_End                      7
#define MWV207REG_SP_INST_HDR_DWORD2_V12_PUSH_POP_CFG_Start                    7
#define MWV207REG_SP_INST_HDR_DWORD2_V12_PUSH_POP_CFG_Type                   U01
#define   MWV207REG_SP_INST_HDR_DWORD2_V12_PUSH_POP_CFG_EVERY_WRRD           0x0
#define   MWV207REG_SP_INST_HDR_DWORD2_V12_PUSH_POP_CFG_USE_ELE_MARKER       0x1


#define MWV207REG_SP_INST_HDR_DWORD2_ACC_IN_SEL                            10:10
#define MWV207REG_SP_INST_HDR_DWORD2_ACC_IN_SEL_End                           10
#define MWV207REG_SP_INST_HDR_DWORD2_ACC_IN_SEL_Start                         10
#define MWV207REG_SP_INST_HDR_DWORD2_ACC_IN_SEL_Type                         U01
#define   MWV207REG_SP_INST_HDR_DWORD2_ACC_IN_SEL_FROM_OUTPUT                0x0
#define   MWV207REG_SP_INST_HDR_DWORD2_ACC_IN_SEL_FROM_ACCEL                 0x1

#define MWV207REG_SP_INST_HDR_DWORD2_NUM_OF_IGN_LD_ACC_OUT                 23:16
#define MWV207REG_SP_INST_HDR_DWORD2_NUM_OF_IGN_LD_ACC_OUT_End                23
#define MWV207REG_SP_INST_HDR_DWORD2_NUM_OF_IGN_LD_ACC_OUT_Start              16
#define MWV207REG_SP_INST_HDR_DWORD2_NUM_OF_IGN_LD_ACC_OUT_Type              U08


#define MWV207REG_SP_INST_HDR_DWORD2_SE_RESET                              24:24
#define MWV207REG_SP_INST_HDR_DWORD2_SE_RESET_End                             24
#define MWV207REG_SP_INST_HDR_DWORD2_SE_RESET_Start                           24
#define MWV207REG_SP_INST_HDR_DWORD2_SE_RESET_Type                           U01
#define   MWV207REG_SP_INST_HDR_DWORD2_SE_RESET_ENABLE                       0x1

#define MWV207REG_SP_INST_HDR_DWORD2_SE_CONTROL                            26:25
#define MWV207REG_SP_INST_HDR_DWORD2_SE_CONTROL_End                           26
#define MWV207REG_SP_INST_HDR_DWORD2_SE_CONTROL_Start                         25
#define MWV207REG_SP_INST_HDR_DWORD2_SE_CONTROL_Type                         U02
#define   MWV207REG_SP_INST_HDR_DWORD2_SE_CONTROL_ACCUM_INTERNAL             0x0
#define   MWV207REG_SP_INST_HDR_DWORD2_SE_CONTROL_ACCUM_1D                   0x1
#define   MWV207REG_SP_INST_HDR_DWORD2_SE_CONTROL_ACCUM_2D                   0x2


#define MWV207REG_SP_INST_HDR_DWORD2_SE_NUM_CH_MINUS1                      27:27
#define MWV207REG_SP_INST_HDR_DWORD2_SE_NUM_CH_MINUS1_End                     27
#define MWV207REG_SP_INST_HDR_DWORD2_SE_NUM_CH_MINUS1_Start                   27
#define MWV207REG_SP_INST_HDR_DWORD2_SE_NUM_CH_MINUS1_Type                   U01

#define   MWV207REG_SP_INST_HDR_DWORD2_SE_NUM_CH_MINUS1_ONE_CH               0x0
#define   MWV207REG_SP_INST_HDR_DWORD2_SE_NUM_CH_MINUS1_TWO_CH               0x1


#define MWV207REG_SP_INST_HDR_DWORD2_SE2_DACC_STORAGE                      28:28
#define MWV207REG_SP_INST_HDR_DWORD2_SE2_DACC_STORAGE_End                     28
#define MWV207REG_SP_INST_HDR_DWORD2_SE2_DACC_STORAGE_Start                   28
#define MWV207REG_SP_INST_HDR_DWORD2_SE2_DACC_STORAGE_Type                   U01



#define MWV207REG_SP_INSTR_LOW_FA_SRC0                                       3:0
#define MWV207REG_SP_INSTR_LOW_FA_SRC0_End                                     3
#define MWV207REG_SP_INSTR_LOW_FA_SRC0_Start                                   0
#define MWV207REG_SP_INSTR_LOW_FA_SRC0_Type                                  U04
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SPINOUT                             0x0
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR1                                 0x1
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR2                                 0x2
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR3                                 0x3
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR4                                 0x4
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR5                                 0x5
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR6                                 0x6
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR7                                 0x7
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR8                                 0x8
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR9                                 0x9
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_SR10                                0xA
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_VR11                                0xB
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_VR12                                0xC
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_VR13                                0xD
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_VR14                                0xE
#define   MWV207REG_SP_INSTR_LOW_FA_SRC0_PWLSETUP_ACC                        0xF


#define MWV207REG_SP_INSTR_LOW_FA_SRC1                                       7:4
#define MWV207REG_SP_INSTR_LOW_FA_SRC1_End                                     7
#define MWV207REG_SP_INSTR_LOW_FA_SRC1_Start                                   4
#define MWV207REG_SP_INSTR_LOW_FA_SRC1_Type                                  U04
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SPINOUT                             0x0
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR1                                 0x1
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR2                                 0x2
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR3                                 0x3
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR4                                 0x4
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR5                                 0x5
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR6                                 0x6
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR7                                 0x7
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR8                                 0x8
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR9                                 0x9
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_SR10                                0xA
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_VR11                                0xB
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_VR12                                0xC
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_VR13                                0xD
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_VR14                                0xE
#define   MWV207REG_SP_INSTR_LOW_FA_SRC1_PWLSETUP_ACC                        0xF


#define MWV207REG_SP_INSTR_LOW_FA_DST                                       11:8
#define MWV207REG_SP_INSTR_LOW_FA_DST_End                                     11
#define MWV207REG_SP_INSTR_LOW_FA_DST_Start                                    8
#define MWV207REG_SP_INSTR_LOW_FA_DST_Type                                   U04
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SPINOUT                              0x0
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR1                                  0x1
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR2                                  0x2
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR3                                  0x3
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR4                                  0x4
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR5                                  0x5
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR6                                  0x6
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR7                                  0x7
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR8                                  0x8
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR9                                  0x9
#define   MWV207REG_SP_INSTR_LOW_FA_DST_SR10                                 0xA
#define   MWV207REG_SP_INSTR_LOW_FA_DST_VR11                                 0xB
#define   MWV207REG_SP_INSTR_LOW_FA_DST_VR12                                 0xC
#define   MWV207REG_SP_INSTR_LOW_FA_DST_VR13                                 0xD
#define   MWV207REG_SP_INSTR_LOW_FA_DST_VR14                                 0xE
#define   MWV207REG_SP_INSTR_LOW_FA_DST_PWLSETUP_ACC                         0xF


#define MWV207REG_SP_INSTR_LOW_FA_OP                                       15:12
#define MWV207REG_SP_INSTR_LOW_FA_OP_End                                      15
#define MWV207REG_SP_INSTR_LOW_FA_OP_Start                                    12
#define MWV207REG_SP_INSTR_LOW_FA_OP_Type                                    U04
#define   MWV207REG_SP_INSTR_LOW_FA_OP_FA_IDLE                               0x0
#define   MWV207REG_SP_INSTR_LOW_FA_OP_FA_ADD                                0x1
#define   MWV207REG_SP_INSTR_LOW_FA_OP_FA_SUB                                0x2


#define MWV207REG_SP_INSTR_LOW_FM_SRC0                                     19:16
#define MWV207REG_SP_INSTR_LOW_FM_SRC0_End                                    19
#define MWV207REG_SP_INSTR_LOW_FM_SRC0_Start                                  16
#define MWV207REG_SP_INSTR_LOW_FM_SRC0_Type                                  U04
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SPINOUT                             0x0
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR1                                 0x1
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR2                                 0x2
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR3                                 0x3
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR4                                 0x4
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR5                                 0x5
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR6                                 0x6
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR7                                 0x7
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR8                                 0x8
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR9                                 0x9
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_SR10                                0xA
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_VR11                                0xB
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_VR12                                0xC
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_VR13                                0xD
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_VR14                                0xE
#define   MWV207REG_SP_INSTR_LOW_FM_SRC0_PWLSETUP_ACC                        0xF


#define MWV207REG_SP_INSTR_LOW_FM_SRC1                                     23:20
#define MWV207REG_SP_INSTR_LOW_FM_SRC1_End                                    23
#define MWV207REG_SP_INSTR_LOW_FM_SRC1_Start                                  20
#define MWV207REG_SP_INSTR_LOW_FM_SRC1_Type                                  U04
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SPINOUT                             0x0
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR1                                 0x1
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR2                                 0x2
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR3                                 0x3
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR4                                 0x4
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR5                                 0x5
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR6                                 0x6
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR7                                 0x7
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR8                                 0x8
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR9                                 0x9
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_SR10                                0xA
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_VR11                                0xB
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_VR12                                0xC
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_VR13                                0xD
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_VR14                                0xE
#define   MWV207REG_SP_INSTR_LOW_FM_SRC1_PWLSETUP_ACC                        0xF


#define MWV207REG_SP_INSTR_LOW_FM_DST                                      27:24
#define MWV207REG_SP_INSTR_LOW_FM_DST_End                                     27
#define MWV207REG_SP_INSTR_LOW_FM_DST_Start                                   24
#define MWV207REG_SP_INSTR_LOW_FM_DST_Type                                   U04
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SPINOUT                              0x0
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR1                                  0x1
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR2                                  0x2
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR3                                  0x3
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR4                                  0x4
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR5                                  0x5
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR6                                  0x6
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR7                                  0x7
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR8                                  0x8
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR9                                  0x9
#define   MWV207REG_SP_INSTR_LOW_FM_DST_SR10                                 0xA
#define   MWV207REG_SP_INSTR_LOW_FM_DST_VR11                                 0xB
#define   MWV207REG_SP_INSTR_LOW_FM_DST_VR12                                 0xC
#define   MWV207REG_SP_INSTR_LOW_FM_DST_VR13                                 0xD
#define   MWV207REG_SP_INSTR_LOW_FM_DST_VR14                                 0xE
#define   MWV207REG_SP_INSTR_LOW_FM_DST_PWLSETUP_ACC                         0xF


#define MWV207REG_SP_INSTR_LOW_FM_OP                                       31:28
#define MWV207REG_SP_INSTR_LOW_FM_OP_End                                      31
#define MWV207REG_SP_INSTR_LOW_FM_OP_Start                                    28
#define MWV207REG_SP_INSTR_LOW_FM_OP_Type                                    U04
#define   MWV207REG_SP_INSTR_LOW_FM_OP_FM_IDLE                               0x0
#define   MWV207REG_SP_INSTR_LOW_FM_OP_FM_MUL                                0x1
#define   MWV207REG_SP_INSTR_LOW_FM_OP_FM_MUL_CLAMP                          0x2



#define MWV207REG_SP_INSTR_HIGH_MV_SRC0                                      3:0
#define MWV207REG_SP_INSTR_HIGH_MV_SRC0_End                                    3
#define MWV207REG_SP_INSTR_HIGH_MV_SRC0_Start                                  0
#define MWV207REG_SP_INSTR_HIGH_MV_SRC0_Type                                 U04
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SPINOUT                            0x0
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR1                                0x1
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR2                                0x2
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR3                                0x3
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR4                                0x4
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR5                                0x5
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR6                                0x6
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR7                                0x7
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR8                                0x8
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR9                                0x9
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_SR10                               0xA
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_VR11                               0xB
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_VR12                               0xC
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_VR13                               0xD
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_VR14                               0xE
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC0_PWLSETUP_ACC                       0xF


#define MWV207REG_SP_INSTR_HIGH_MV_SRC1                                      7:4
#define MWV207REG_SP_INSTR_HIGH_MV_SRC1_End                                    7
#define MWV207REG_SP_INSTR_HIGH_MV_SRC1_Start                                  4
#define MWV207REG_SP_INSTR_HIGH_MV_SRC1_Type                                 U04
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SPINOUT                            0x0
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR1                                0x1
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR2                                0x2
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR3                                0x3
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR4                                0x4
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR5                                0x5
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR6                                0x6
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR7                                0x7
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR8                                0x8
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR9                                0x9
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_SR10                               0xA
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_VR11                               0xB
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_VR12                               0xC
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_VR13                               0xD
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_VR14                               0xE
#define   MWV207REG_SP_INSTR_HIGH_MV_SRC1_PWLSETUP_ACC                       0xF


#define MWV207REG_SP_INSTR_HIGH_MV_DST                                      11:8
#define MWV207REG_SP_INSTR_HIGH_MV_DST_End                                    11
#define MWV207REG_SP_INSTR_HIGH_MV_DST_Start                                   8
#define MWV207REG_SP_INSTR_HIGH_MV_DST_Type                                  U04
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SPINOUT                             0x0
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR1                                 0x1
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR2                                 0x2
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR3                                 0x3
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR4                                 0x4
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR5                                 0x5
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR6                                 0x6
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR7                                 0x7
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR8                                 0x8
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR9                                 0x9
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_SR10                                0xA
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_VR11                                0xB
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_VR12                                0xC
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_VR13                                0xD
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_VR14                                0xE
#define   MWV207REG_SP_INSTR_HIGH_MV_DST_PWLSETUP_ACC                        0xF


#define MWV207REG_SP_INSTR_HIGH_MV_OP                                      15:12
#define MWV207REG_SP_INSTR_HIGH_MV_OP_End                                     15
#define MWV207REG_SP_INSTR_HIGH_MV_OP_Start                                   12
#define MWV207REG_SP_INSTR_HIGH_MV_OP_Type                                   U04
#define   MWV207REG_SP_INSTR_HIGH_MV_OP_MV_IDLE                              0x0
#define   MWV207REG_SP_INSTR_HIGH_MV_OP_MV                                   0x1
#define   MWV207REG_SP_INSTR_HIGH_MV_OP_MV_SEL0                              0x2
#define   MWV207REG_SP_INSTR_HIGH_MV_OP_MV_SEL1                              0x3
#define   MWV207REG_SP_INSTR_HIGH_MV_OP_MV_IMMD                              0x4
#define   MWV207REG_SP_INSTR_HIGH_MV_OP_MV_ABS                               0x5


#define MWV207REG_SP_INSTR_HIGH_PW_OP                                      18:16
#define MWV207REG_SP_INSTR_HIGH_PW_OP_End                                     18
#define MWV207REG_SP_INSTR_HIGH_PW_OP_Start                                   16
#define MWV207REG_SP_INSTR_HIGH_PW_OP_Type                                   U03
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_PWI_IDLE                             0x0
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_SETUP0                               0x1
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_SETUP1                               0x2
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_SETUP2                               0x3
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_SETUP3                               0x4
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_SETUP4                               0x5
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_SETUP5                               0x6
#define   MWV207REG_SP_INSTR_HIGH_PW_OP_SETUP6                               0x7



#define MWV207REG_SP_INST_MVIM_LOW_CONST0TO11                               11:0
#define MWV207REG_SP_INST_MVIM_LOW_CONST0TO11_End                             11
#define MWV207REG_SP_INST_MVIM_LOW_CONST0TO11_Start                            0
#define MWV207REG_SP_INST_MVIM_LOW_CONST0TO11_Type                           U12


#define MWV207REG_SP_INST_MVIM_LOW_FA_OP                                   15:12
#define MWV207REG_SP_INST_MVIM_LOW_FA_OP_End                                  15
#define MWV207REG_SP_INST_MVIM_LOW_FA_OP_Start                                12
#define MWV207REG_SP_INST_MVIM_LOW_FA_OP_Type                                U04
#define   MWV207REG_SP_INST_MVIM_LOW_FA_OP_FA_IDLE                           0x0
#define   MWV207REG_SP_INST_MVIM_LOW_FA_OP_FA_ADD                            0x1
#define   MWV207REG_SP_INST_MVIM_LOW_FA_OP_FA_SUB                            0x2


#define MWV207REG_SP_INST_MVIM_LOW_CONST12TO23                             27:16
#define MWV207REG_SP_INST_MVIM_LOW_CONST12TO23_End                            27
#define MWV207REG_SP_INST_MVIM_LOW_CONST12TO23_Start                          16
#define MWV207REG_SP_INST_MVIM_LOW_CONST12TO23_Type                          U12


#define MWV207REG_SP_INST_MVIM_LOW_FM_OP                                   31:28
#define MWV207REG_SP_INST_MVIM_LOW_FM_OP_End                                  31
#define MWV207REG_SP_INST_MVIM_LOW_FM_OP_Start                                28
#define MWV207REG_SP_INST_MVIM_LOW_FM_OP_Type                                U04



#define MWV207REG_SP_INST_MVIM_HIGH_CONST24TO31                              7:0
#define MWV207REG_SP_INST_MVIM_HIGH_CONST24TO31_End                            7
#define MWV207REG_SP_INST_MVIM_HIGH_CONST24TO31_Start                          0
#define MWV207REG_SP_INST_MVIM_HIGH_CONST24TO31_Type                         U08


#define MWV207REG_SP_INST_MVIM_HIGH_MV_DST                                  11:8
#define MWV207REG_SP_INST_MVIM_HIGH_MV_DST_End                                11
#define MWV207REG_SP_INST_MVIM_HIGH_MV_DST_Start                               8
#define MWV207REG_SP_INST_MVIM_HIGH_MV_DST_Type                              U04
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SPINOUT                         0x0
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR1                             0x1
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR2                             0x2
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR3                             0x3
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR4                             0x4
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR5                             0x5
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR6                             0x6
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR7                             0x7
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR8                             0x8
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR9                             0x9
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_SR10                            0xA
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_VR11                            0xB
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_VR12                            0xC
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_VR13                            0xD
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_VR14                            0xE
#define   MWV207REG_SP_INST_MVIM_HIGH_MV_DST_PWLSETUP_ACC                    0xF


#define MWV207REG_SP_INST_MVIM_HIGH_MV_OP                                  15:12
#define MWV207REG_SP_INST_MVIM_HIGH_MV_OP_End                                 15
#define MWV207REG_SP_INST_MVIM_HIGH_MV_OP_Start                               12
#define MWV207REG_SP_INST_MVIM_HIGH_MV_OP_Type                               U04

#define MWV207REG_SP_INST_MVIM_HIGH_PW_OP                                  18:16
#define MWV207REG_SP_INST_MVIM_HIGH_PW_OP_End                                 18
#define MWV207REG_SP_INST_MVIM_HIGH_PW_OP_Start                               16
#define MWV207REG_SP_INST_MVIM_HIGH_PW_OP_Type                               U03
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_PWI_IDLE                         0x0
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_SETUP0                           0x1
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_SETUP1                           0x2
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_SETUP2                           0x3
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_SETUP3                           0x4
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_SETUP4                           0x5
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_SETUP5                           0x6
#define   MWV207REG_SP_INST_MVIM_HIGH_PW_OP_SETUP6                           0x7


#endif


