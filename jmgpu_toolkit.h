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




#ifndef __AQPixelEngineReg_h__
#define __AQPixelEngineReg_h__


#define AQDepthConfigRegAddrs                                             0x0500
#define AQ_DEPTH_CONFIG_Address                                          0x01400
#define AQ_DEPTH_CONFIG_MSB                                                   15
#define AQ_DEPTH_CONFIG_LSB                                                    0
#define AQ_DEPTH_CONFIG_BLK                                                    0
#define AQ_DEPTH_CONFIG_Count                                                  1
#define AQ_DEPTH_CONFIG_FieldMask                                     0xFFFFFFFB
#define AQ_DEPTH_CONFIG_ReadMask                                      0xFFFFFFFB
#define AQ_DEPTH_CONFIG_WriteMask                                     0xFFFFFFFB
#define AQ_DEPTH_CONFIG_ResetValue                                    0x00000000


#define AQ_DEPTH_CONFIG_MASK_INTERLEAVED                                   31:31
#define AQ_DEPTH_CONFIG_MASK_INTERLEAVED_End                                  31
#define AQ_DEPTH_CONFIG_MASK_INTERLEAVED_Start                                31
#define AQ_DEPTH_CONFIG_MASK_INTERLEAVED_Type                                U01
#define   AQ_DEPTH_CONFIG_MASK_INTERLEAVED_ENABLED                           0x0
#define   AQ_DEPTH_CONFIG_MASK_INTERLEAVED_MASKED                            0x1


#define AQ_DEPTH_CONFIG_INTERLEAVED                                        30:28
#define AQ_DEPTH_CONFIG_INTERLEAVED_End                                       30
#define AQ_DEPTH_CONFIG_INTERLEAVED_Start                                     28
#define AQ_DEPTH_CONFIG_INTERLEAVED_Type                                     U03
#define   AQ_DEPTH_CONFIG_INTERLEAVED_DISABLED                               0x0
#define   AQ_DEPTH_CONFIG_INTERLEAVED_C16D16                                 0x1
#define   AQ_DEPTH_CONFIG_INTERLEAVED_C16D32                                 0x2
#define   AQ_DEPTH_CONFIG_INTERLEAVED_C32D16                                 0x3
#define   AQ_DEPTH_CONFIG_INTERLEAVED_C32D32                                 0x4


#define AQ_DEPTH_CONFIG_MASK_SUPER_TILE                                    27:27
#define AQ_DEPTH_CONFIG_MASK_SUPER_TILE_End                                   27
#define AQ_DEPTH_CONFIG_MASK_SUPER_TILE_Start                                 27
#define AQ_DEPTH_CONFIG_MASK_SUPER_TILE_Type                                 U01
#define   AQ_DEPTH_CONFIG_MASK_SUPER_TILE_ENABLED                            0x0
#define   AQ_DEPTH_CONFIG_MASK_SUPER_TILE_MASKED                             0x1

#define AQ_DEPTH_CONFIG_SUPER_TILE                                         26:26
#define AQ_DEPTH_CONFIG_SUPER_TILE_End                                        26
#define AQ_DEPTH_CONFIG_SUPER_TILE_Start                                      26
#define AQ_DEPTH_CONFIG_SUPER_TILE_Type                                      U01
#define   AQ_DEPTH_CONFIG_SUPER_TILE_DISABLED                                0x0
#define   AQ_DEPTH_CONFIG_SUPER_TILE_ENABLED                                 0x1


#define AQ_DEPTH_CONFIG_MASK_DISABLE_PE_DEPTH                              25:25
#define AQ_DEPTH_CONFIG_MASK_DISABLE_PE_DEPTH_End                             25
#define AQ_DEPTH_CONFIG_MASK_DISABLE_PE_DEPTH_Start                           25
#define AQ_DEPTH_CONFIG_MASK_DISABLE_PE_DEPTH_Type                           U01
#define   AQ_DEPTH_CONFIG_MASK_DISABLE_PE_DEPTH_ENABLED                      0x0
#define   AQ_DEPTH_CONFIG_MASK_DISABLE_PE_DEPTH_MASKED                       0x1

#define AQ_DEPTH_CONFIG_DISABLE_PE_DEPTH                                   24:24
#define AQ_DEPTH_CONFIG_DISABLE_PE_DEPTH_End                                  24
#define AQ_DEPTH_CONFIG_DISABLE_PE_DEPTH_Start                                24
#define AQ_DEPTH_CONFIG_DISABLE_PE_DEPTH_Type                                U01
#define   AQ_DEPTH_CONFIG_DISABLE_PE_DEPTH_ENABLED                           0x0
#define   AQ_DEPTH_CONFIG_DISABLE_PE_DEPTH_DISABLED                          0x1


#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT                                     23:23
#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT_End                                    23
#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT_Start                                  23
#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT_Type                                  U01
#define   AQ_DEPTH_CONFIG_MASK_D32_FLOAT_ENABLED                             0x0
#define   AQ_DEPTH_CONFIG_MASK_D32_FLOAT_MASKED                              0x1


#define AQ_DEPTH_CONFIG_D32_FLOAT                                          22:22
#define AQ_DEPTH_CONFIG_D32_FLOAT_End                                         22
#define AQ_DEPTH_CONFIG_D32_FLOAT_Start                                       22
#define AQ_DEPTH_CONFIG_D32_FLOAT_Type                                       U01
#define   AQ_DEPTH_CONFIG_D32_FLOAT_DISABLE                                  0x0
#define   AQ_DEPTH_CONFIG_D32_FLOAT_ENABLE                                   0x1


#define AQ_DEPTH_CONFIG_MASK_DEPTH_ONLY                                    21:21
#define AQ_DEPTH_CONFIG_MASK_DEPTH_ONLY_End                                   21
#define AQ_DEPTH_CONFIG_MASK_DEPTH_ONLY_Start                                 21
#define AQ_DEPTH_CONFIG_MASK_DEPTH_ONLY_Type                                 U01
#define   AQ_DEPTH_CONFIG_MASK_DEPTH_ONLY_ENABLED                            0x0
#define   AQ_DEPTH_CONFIG_MASK_DEPTH_ONLY_MASKED                             0x1

#define AQ_DEPTH_CONFIG_DEPTH_ONLY                                         20:20
#define AQ_DEPTH_CONFIG_DEPTH_ONLY_End                                        20
#define AQ_DEPTH_CONFIG_DEPTH_ONLY_Start                                      20
#define AQ_DEPTH_CONFIG_DEPTH_ONLY_Type                                      U01
#define   AQ_DEPTH_CONFIG_DEPTH_ONLY_DISABLED                                0x0
#define   AQ_DEPTH_CONFIG_DEPTH_ONLY_ENABLED                                 0x1


#define AQ_DEPTH_CONFIG_MASK_CLAMP_FAR_Z                                   19:19
#define AQ_DEPTH_CONFIG_MASK_CLAMP_FAR_Z_End                                  19
#define AQ_DEPTH_CONFIG_MASK_CLAMP_FAR_Z_Start                                19
#define AQ_DEPTH_CONFIG_MASK_CLAMP_FAR_Z_Type                                U01
#define   AQ_DEPTH_CONFIG_MASK_CLAMP_FAR_Z_ENABLED                           0x0
#define   AQ_DEPTH_CONFIG_MASK_CLAMP_FAR_Z_MASKED                            0x1


#define AQ_DEPTH_CONFIG_CLAMP_FAR_Z                                        18:18
#define AQ_DEPTH_CONFIG_CLAMP_FAR_Z_End                                       18
#define AQ_DEPTH_CONFIG_CLAMP_FAR_Z_Start                                     18
#define AQ_DEPTH_CONFIG_CLAMP_FAR_Z_Type                                     U01

#define   AQ_DEPTH_CONFIG_CLAMP_FAR_Z_CULL                                   0x0

#define   AQ_DEPTH_CONFIG_CLAMP_FAR_Z_CLAMP                                  0x1


#define AQ_DEPTH_CONFIG_MASK_EARLY                                         17:17
#define AQ_DEPTH_CONFIG_MASK_EARLY_End                                        17
#define AQ_DEPTH_CONFIG_MASK_EARLY_Start                                      17
#define AQ_DEPTH_CONFIG_MASK_EARLY_Type                                      U01
#define   AQ_DEPTH_CONFIG_MASK_EARLY_ENABLED                                 0x0
#define   AQ_DEPTH_CONFIG_MASK_EARLY_MASKED                                  0x1

#define AQ_DEPTH_CONFIG_EARLY                                              16:16
#define AQ_DEPTH_CONFIG_EARLY_End                                             16
#define AQ_DEPTH_CONFIG_EARLY_Start                                           16
#define AQ_DEPTH_CONFIG_EARLY_Type                                           U01
#define   AQ_DEPTH_CONFIG_EARLY_DISABLED                                     0x0
#define   AQ_DEPTH_CONFIG_EARLY_ENABLED                                      0x1


#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT_OPT                                 15:15
#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT_OPT_End                                15
#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT_OPT_Start                              15
#define AQ_DEPTH_CONFIG_MASK_D32_FLOAT_OPT_Type                              U01
#define   AQ_DEPTH_CONFIG_MASK_D32_FLOAT_OPT_ENABLED                         0x0
#define   AQ_DEPTH_CONFIG_MASK_D32_FLOAT_OPT_MASKED                          0x1

#define AQ_DEPTH_CONFIG_D32_FLOAT_OPT                                      14:14
#define AQ_DEPTH_CONFIG_D32_FLOAT_OPT_End                                     14
#define AQ_DEPTH_CONFIG_D32_FLOAT_OPT_Start                                   14
#define AQ_DEPTH_CONFIG_D32_FLOAT_OPT_Type                                   U01
#define   AQ_DEPTH_CONFIG_D32_FLOAT_OPT_DISABLED                             0x0
#define   AQ_DEPTH_CONFIG_D32_FLOAT_OPT_ENABLED                              0x1


#define AQ_DEPTH_CONFIG_MASK_WRITE                                         13:13
#define AQ_DEPTH_CONFIG_MASK_WRITE_End                                        13
#define AQ_DEPTH_CONFIG_MASK_WRITE_Start                                      13
#define AQ_DEPTH_CONFIG_MASK_WRITE_Type                                      U01
#define   AQ_DEPTH_CONFIG_MASK_WRITE_ENABLED                                 0x0
#define   AQ_DEPTH_CONFIG_MASK_WRITE_MASKED                                  0x1


#define AQ_DEPTH_CONFIG_WRITE                                              12:12
#define AQ_DEPTH_CONFIG_WRITE_End                                             12
#define AQ_DEPTH_CONFIG_WRITE_Start                                           12
#define AQ_DEPTH_CONFIG_WRITE_Type                                           U01
#define   AQ_DEPTH_CONFIG_WRITE_DISABLED                                     0x0
#define   AQ_DEPTH_CONFIG_WRITE_ENABLED                                      0x1


#define AQ_DEPTH_CONFIG_MASK_COMPARE                                       11:11
#define AQ_DEPTH_CONFIG_MASK_COMPARE_End                                      11
#define AQ_DEPTH_CONFIG_MASK_COMPARE_Start                                    11
#define AQ_DEPTH_CONFIG_MASK_COMPARE_Type                                    U01
#define   AQ_DEPTH_CONFIG_MASK_COMPARE_ENABLED                               0x0
#define   AQ_DEPTH_CONFIG_MASK_COMPARE_MASKED                                0x1

#define AQ_DEPTH_CONFIG_COMPARE                                             10:8
#define AQ_DEPTH_CONFIG_COMPARE_End                                           10
#define AQ_DEPTH_CONFIG_COMPARE_Start                                          8
#define AQ_DEPTH_CONFIG_COMPARE_Type                                         U03
#define   AQ_DEPTH_CONFIG_COMPARE_NEVER                                      0x0
#define   AQ_DEPTH_CONFIG_COMPARE_LESS                                       0x1
#define   AQ_DEPTH_CONFIG_COMPARE_EQUAL                                      0x2
#define   AQ_DEPTH_CONFIG_COMPARE_LESS_EQUAL                                 0x3
#define   AQ_DEPTH_CONFIG_COMPARE_GREATER                                    0x4
#define   AQ_DEPTH_CONFIG_COMPARE_NOT_EQUAL                                  0x5
#define   AQ_DEPTH_CONFIG_COMPARE_GREATER_EQUAL                              0x6
#define   AQ_DEPTH_CONFIG_COMPARE_ALWAYS                                     0x7


#define AQ_DEPTH_CONFIG_MASK_ADDR_REMAP                                      7:7
#define AQ_DEPTH_CONFIG_MASK_ADDR_REMAP_End                                    7
#define AQ_DEPTH_CONFIG_MASK_ADDR_REMAP_Start                                  7
#define AQ_DEPTH_CONFIG_MASK_ADDR_REMAP_Type                                 U01
#define   AQ_DEPTH_CONFIG_MASK_ADDR_REMAP_ENABLED                            0x0
#define   AQ_DEPTH_CONFIG_MASK_ADDR_REMAP_MASKED                             0x1


#define AQ_DEPTH_CONFIG_ADDR_REMAP                                           6:6
#define AQ_DEPTH_CONFIG_ADDR_REMAP_End                                         6
#define AQ_DEPTH_CONFIG_ADDR_REMAP_Start                                       6
#define AQ_DEPTH_CONFIG_ADDR_REMAP_Type                                      U01
#define   AQ_DEPTH_CONFIG_ADDR_REMAP_DISABLED                                0x0
#define   AQ_DEPTH_CONFIG_ADDR_REMAP_ENABLED                                 0x1


#define AQ_DEPTH_CONFIG_MASK_FORMAT                                          5:5
#define AQ_DEPTH_CONFIG_MASK_FORMAT_End                                        5
#define AQ_DEPTH_CONFIG_MASK_FORMAT_Start                                      5
#define AQ_DEPTH_CONFIG_MASK_FORMAT_Type                                     U01
#define   AQ_DEPTH_CONFIG_MASK_FORMAT_ENABLED                                0x0
#define   AQ_DEPTH_CONFIG_MASK_FORMAT_MASKED                                 0x1


#define AQ_DEPTH_CONFIG_FORMAT                                               4:4
#define AQ_DEPTH_CONFIG_FORMAT_End                                             4
#define AQ_DEPTH_CONFIG_FORMAT_Start                                           4
#define AQ_DEPTH_CONFIG_FORMAT_Type                                          U01
#define   AQ_DEPTH_CONFIG_FORMAT_Z16                                         0x0
#define   AQ_DEPTH_CONFIG_FORMAT_Z24                                         0x1


#define AQ_DEPTH_CONFIG_MASK_TYPE                                            3:3
#define AQ_DEPTH_CONFIG_MASK_TYPE_End                                          3
#define AQ_DEPTH_CONFIG_MASK_TYPE_Start                                        3
#define AQ_DEPTH_CONFIG_MASK_TYPE_Type                                       U01
#define   AQ_DEPTH_CONFIG_MASK_TYPE_ENABLED                                  0x0
#define   AQ_DEPTH_CONFIG_MASK_TYPE_MASKED                                   0x1


#define AQ_DEPTH_CONFIG_TYPE                                                 1:0
#define AQ_DEPTH_CONFIG_TYPE_End                                               1
#define AQ_DEPTH_CONFIG_TYPE_Start                                             0
#define AQ_DEPTH_CONFIG_TYPE_Type                                            U02
#define   AQ_DEPTH_CONFIG_TYPE_NONE                                          0x0
#define   AQ_DEPTH_CONFIG_TYPE_Z                                             0x1
#define   AQ_DEPTH_CONFIG_TYPE_W                                             0x2

#define AQDepthNearRegAddrs                                               0x0501
#define AQ_DEPTH_NEAR_Address                                            0x01404
#define AQ_DEPTH_NEAR_MSB                                                     15
#define AQ_DEPTH_NEAR_LSB                                                      0
#define AQ_DEPTH_NEAR_BLK                                                      0
#define AQ_DEPTH_NEAR_Count                                                    1
#define AQ_DEPTH_NEAR_FieldMask                                       0xFFFFFFFF
#define AQ_DEPTH_NEAR_ReadMask                                        0xFFFFFFFF
#define AQ_DEPTH_NEAR_WriteMask                                       0xFFFFFFFF
#define AQ_DEPTH_NEAR_ResetValue                                      0x00000000

#define AQ_DEPTH_NEAR_NEAR_FIELD                                            31:0
#define AQ_DEPTH_NEAR_NEAR_FIELD_End                                          31
#define AQ_DEPTH_NEAR_NEAR_FIELD_Start                                         0
#define AQ_DEPTH_NEAR_NEAR_FIELD_Type                                        U32

#define AQDepthFarRegAddrs                                                0x0502
#define AQ_DEPTH_FAR_Address                                             0x01408
#define AQ_DEPTH_FAR_MSB                                                      15
#define AQ_DEPTH_FAR_LSB                                                       0
#define AQ_DEPTH_FAR_BLK                                                       0
#define AQ_DEPTH_FAR_Count                                                     1
#define AQ_DEPTH_FAR_FieldMask                                        0xFFFFFFFF
#define AQ_DEPTH_FAR_ReadMask                                         0xFFFFFFFF
#define AQ_DEPTH_FAR_WriteMask                                        0xFFFFFFFF
#define AQ_DEPTH_FAR_ResetValue                                       0x00000000

#define AQ_DEPTH_FAR_FAR_FIELD                                              31:0
#define AQ_DEPTH_FAR_FAR_FIELD_End                                            31
#define AQ_DEPTH_FAR_FAR_FIELD_Start                                           0
#define AQ_DEPTH_FAR_FAR_FIELD_Type                                          U32

#define AQDepthNormalizeRegAddrs                                          0x0503
#define AQ_DEPTH_NORMALIZE_Address                                       0x0140C
#define AQ_DEPTH_NORMALIZE_MSB                                                15
#define AQ_DEPTH_NORMALIZE_LSB                                                 0
#define AQ_DEPTH_NORMALIZE_BLK                                                 0
#define AQ_DEPTH_NORMALIZE_Count                                               1
#define AQ_DEPTH_NORMALIZE_FieldMask                                  0xFFFFFFFF
#define AQ_DEPTH_NORMALIZE_ReadMask                                   0xFFFFFFFF
#define AQ_DEPTH_NORMALIZE_WriteMask                                  0xFFFFFFFF
#define AQ_DEPTH_NORMALIZE_ResetValue                                 0x00000000


#define AQ_DEPTH_NORMALIZE_NORMALIZE                                        31:0
#define AQ_DEPTH_NORMALIZE_NORMALIZE_End                                      31
#define AQ_DEPTH_NORMALIZE_NORMALIZE_Start                                     0
#define AQ_DEPTH_NORMALIZE_NORMALIZE_Type                                    U32




#define AQDepthAddressRegAddrs                                            0x0504
#define AQ_DEPTH_ADDRESS_Address                                         0x01410
#define AQ_DEPTH_ADDRESS_MSB                                                  15
#define AQ_DEPTH_ADDRESS_LSB                                                   0
#define AQ_DEPTH_ADDRESS_BLK                                                   0
#define AQ_DEPTH_ADDRESS_Count                                                 1
#define AQ_DEPTH_ADDRESS_FieldMask                                    0xFFFFFFFF
#define AQ_DEPTH_ADDRESS_ReadMask                                     0xFFFFFFFC
#define AQ_DEPTH_ADDRESS_WriteMask                                    0xFFFFFFFC
#define AQ_DEPTH_ADDRESS_ResetValue                                   0x00000000

#define AQ_DEPTH_ADDRESS_TYPE                                              31:31
#define AQ_DEPTH_ADDRESS_TYPE_End                                             31
#define AQ_DEPTH_ADDRESS_TYPE_Start                                           31
#define AQ_DEPTH_ADDRESS_TYPE_Type                                           U01
#define   AQ_DEPTH_ADDRESS_TYPE_SYSTEM                                       0x0
#define   AQ_DEPTH_ADDRESS_TYPE_VIRTUAL_SYSTEM                               0x1

#define AQ_DEPTH_ADDRESS_ADDRESS                                            30:0
#define AQ_DEPTH_ADDRESS_ADDRESS_End                                          30
#define AQ_DEPTH_ADDRESS_ADDRESS_Start                                         0
#define AQ_DEPTH_ADDRESS_ADDRESS_Type                                        U31




#define AQDepthStrideRegAddrs                                             0x0505
#define AQ_DEPTH_STRIDE_Address                                          0x01414
#define AQ_DEPTH_STRIDE_MSB                                                   15
#define AQ_DEPTH_STRIDE_LSB                                                    0
#define AQ_DEPTH_STRIDE_BLK                                                    0
#define AQ_DEPTH_STRIDE_Count                                                  1
#define AQ_DEPTH_STRIDE_FieldMask                                     0x0003FFFF
#define AQ_DEPTH_STRIDE_ReadMask                                      0x0003FFFC
#define AQ_DEPTH_STRIDE_WriteMask                                     0x0003FFFC
#define AQ_DEPTH_STRIDE_ResetValue                                    0x00000000

#define AQ_DEPTH_STRIDE_STRIDE                                              17:0
#define AQ_DEPTH_STRIDE_STRIDE_End                                            17
#define AQ_DEPTH_STRIDE_STRIDE_Start                                           0
#define AQ_DEPTH_STRIDE_STRIDE_Type                                          U18

#define AQStencilOperationRegAddrs                                        0x0506
#define AQ_STENCIL_OPERATION_Address                                     0x01418
#define AQ_STENCIL_OPERATION_MSB                                              15
#define AQ_STENCIL_OPERATION_LSB                                               0
#define AQ_STENCIL_OPERATION_BLK                                               0
#define AQ_STENCIL_OPERATION_Count                                             1
#define AQ_STENCIL_OPERATION_FieldMask                                0xFFFFFFFF
#define AQ_STENCIL_OPERATION_ReadMask                                 0xFFFFFFFF
#define AQ_STENCIL_OPERATION_WriteMask                                0xFFFFFFFF
#define AQ_STENCIL_OPERATION_ResetValue                               0x00000000


#define AQ_STENCIL_OPERATION_MASK_CCW_DEPTH_FAIL                           31:31
#define AQ_STENCIL_OPERATION_MASK_CCW_DEPTH_FAIL_End                          31
#define AQ_STENCIL_OPERATION_MASK_CCW_DEPTH_FAIL_Start                        31
#define AQ_STENCIL_OPERATION_MASK_CCW_DEPTH_FAIL_Type                        U01
#define   AQ_STENCIL_OPERATION_MASK_CCW_DEPTH_FAIL_ENABLED                   0x0
#define   AQ_STENCIL_OPERATION_MASK_CCW_DEPTH_FAIL_MASKED                    0x1


#define AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL                                30:28
#define AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_End                               30
#define AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_Start                             28
#define AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_Type                             U03
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_KEEP                           0x0
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_ZERO                           0x1
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_REPLACE                        0x2
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_INCREMENT_SAT                  0x3
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_DECREMENT_SAT                  0x4
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_INVERT                         0x5
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_INCREMENT                      0x6
#define   AQ_STENCIL_OPERATION_CCW_DEPTH_FAIL_DECREMENT                      0x7


#define AQ_STENCIL_OPERATION_MASK_CCW_FAIL                                 27:27
#define AQ_STENCIL_OPERATION_MASK_CCW_FAIL_End                                27
#define AQ_STENCIL_OPERATION_MASK_CCW_FAIL_Start                              27
#define AQ_STENCIL_OPERATION_MASK_CCW_FAIL_Type                              U01
#define   AQ_STENCIL_OPERATION_MASK_CCW_FAIL_ENABLED                         0x0
#define   AQ_STENCIL_OPERATION_MASK_CCW_FAIL_MASKED                          0x1

#define AQ_STENCIL_OPERATION_CCW_FAIL                                      26:24
#define AQ_STENCIL_OPERATION_CCW_FAIL_End                                     26
#define AQ_STENCIL_OPERATION_CCW_FAIL_Start                                   24
#define AQ_STENCIL_OPERATION_CCW_FAIL_Type                                   U03
#define   AQ_STENCIL_OPERATION_CCW_FAIL_KEEP                                 0x0
#define   AQ_STENCIL_OPERATION_CCW_FAIL_ZERO                                 0x1
#define   AQ_STENCIL_OPERATION_CCW_FAIL_REPLACE                              0x2
#define   AQ_STENCIL_OPERATION_CCW_FAIL_INCREMENT_SAT                        0x3
#define   AQ_STENCIL_OPERATION_CCW_FAIL_DECREMENT_SAT                        0x4
#define   AQ_STENCIL_OPERATION_CCW_FAIL_INVERT                               0x5
#define   AQ_STENCIL_OPERATION_CCW_FAIL_INCREMENT                            0x6
#define   AQ_STENCIL_OPERATION_CCW_FAIL_DECREMENT                            0x7


#define AQ_STENCIL_OPERATION_MASK_CCW_PASS                                 23:23
#define AQ_STENCIL_OPERATION_MASK_CCW_PASS_End                                23
#define AQ_STENCIL_OPERATION_MASK_CCW_PASS_Start                              23
#define AQ_STENCIL_OPERATION_MASK_CCW_PASS_Type                              U01
#define   AQ_STENCIL_OPERATION_MASK_CCW_PASS_ENABLED                         0x0
#define   AQ_STENCIL_OPERATION_MASK_CCW_PASS_MASKED                          0x1

#define AQ_STENCIL_OPERATION_CCW_PASS                                      22:20
#define AQ_STENCIL_OPERATION_CCW_PASS_End                                     22
#define AQ_STENCIL_OPERATION_CCW_PASS_Start                                   20
#define AQ_STENCIL_OPERATION_CCW_PASS_Type                                   U03
#define   AQ_STENCIL_OPERATION_CCW_PASS_KEEP                                 0x0
#define   AQ_STENCIL_OPERATION_CCW_PASS_ZERO                                 0x1
#define   AQ_STENCIL_OPERATION_CCW_PASS_REPLACE                              0x2
#define   AQ_STENCIL_OPERATION_CCW_PASS_INCREMENT_SAT                        0x3
#define   AQ_STENCIL_OPERATION_CCW_PASS_DECREMENT_SAT                        0x4
#define   AQ_STENCIL_OPERATION_CCW_PASS_INVERT                               0x5
#define   AQ_STENCIL_OPERATION_CCW_PASS_INCREMENT                            0x6
#define   AQ_STENCIL_OPERATION_CCW_PASS_DECREMENT                            0x7


#define AQ_STENCIL_OPERATION_MASK_CCW_COMPARE                              19:19
#define AQ_STENCIL_OPERATION_MASK_CCW_COMPARE_End                             19
#define AQ_STENCIL_OPERATION_MASK_CCW_COMPARE_Start                           19
#define AQ_STENCIL_OPERATION_MASK_CCW_COMPARE_Type                           U01
#define   AQ_STENCIL_OPERATION_MASK_CCW_COMPARE_ENABLED                      0x0
#define   AQ_STENCIL_OPERATION_MASK_CCW_COMPARE_MASKED                       0x1


#define AQ_STENCIL_OPERATION_CCW_COMPARE                                   18:16
#define AQ_STENCIL_OPERATION_CCW_COMPARE_End                                  18
#define AQ_STENCIL_OPERATION_CCW_COMPARE_Start                                16
#define AQ_STENCIL_OPERATION_CCW_COMPARE_Type                                U03
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_NEVER                             0x0
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_LESS                              0x1
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_EQUAL                             0x2
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_LESS_EQUAL                        0x3
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_GREATER                           0x4
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_NOT_EQUAL                         0x5
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_GREATER_EQUAL                     0x6
#define   AQ_STENCIL_OPERATION_CCW_COMPARE_ALWAYS                            0x7


#define AQ_STENCIL_OPERATION_MASK_DEPTH_FAIL                               15:15
#define AQ_STENCIL_OPERATION_MASK_DEPTH_FAIL_End                              15
#define AQ_STENCIL_OPERATION_MASK_DEPTH_FAIL_Start                            15
#define AQ_STENCIL_OPERATION_MASK_DEPTH_FAIL_Type                            U01
#define   AQ_STENCIL_OPERATION_MASK_DEPTH_FAIL_ENABLED                       0x0
#define   AQ_STENCIL_OPERATION_MASK_DEPTH_FAIL_MASKED                        0x1

#define AQ_STENCIL_OPERATION_DEPTH_FAIL                                    14:12
#define AQ_STENCIL_OPERATION_DEPTH_FAIL_End                                   14
#define AQ_STENCIL_OPERATION_DEPTH_FAIL_Start                                 12
#define AQ_STENCIL_OPERATION_DEPTH_FAIL_Type                                 U03
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_KEEP                               0x0
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_ZERO                               0x1
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_REPLACE                            0x2
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_INCREMENT_SAT                      0x3
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_DECREMENT_SAT                      0x4
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_INVERT                             0x5
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_INCREMENT                          0x6
#define   AQ_STENCIL_OPERATION_DEPTH_FAIL_DECREMENT                          0x7


#define AQ_STENCIL_OPERATION_MASK_FAIL                                     11:11
#define AQ_STENCIL_OPERATION_MASK_FAIL_End                                    11
#define AQ_STENCIL_OPERATION_MASK_FAIL_Start                                  11
#define AQ_STENCIL_OPERATION_MASK_FAIL_Type                                  U01
#define   AQ_STENCIL_OPERATION_MASK_FAIL_ENABLED                             0x0
#define   AQ_STENCIL_OPERATION_MASK_FAIL_MASKED                              0x1

#define AQ_STENCIL_OPERATION_FAIL                                           10:8
#define AQ_STENCIL_OPERATION_FAIL_End                                         10
#define AQ_STENCIL_OPERATION_FAIL_Start                                        8
#define AQ_STENCIL_OPERATION_FAIL_Type                                       U03
#define   AQ_STENCIL_OPERATION_FAIL_KEEP                                     0x0
#define   AQ_STENCIL_OPERATION_FAIL_ZERO                                     0x1
#define   AQ_STENCIL_OPERATION_FAIL_REPLACE                                  0x2
#define   AQ_STENCIL_OPERATION_FAIL_INCREMENT_SAT                            0x3
#define   AQ_STENCIL_OPERATION_FAIL_DECREMENT_SAT                            0x4
#define   AQ_STENCIL_OPERATION_FAIL_INVERT                                   0x5
#define   AQ_STENCIL_OPERATION_FAIL_INCREMENT                                0x6
#define   AQ_STENCIL_OPERATION_FAIL_DECREMENT                                0x7


#define AQ_STENCIL_OPERATION_MASK_PASS                                       7:7
#define AQ_STENCIL_OPERATION_MASK_PASS_End                                     7
#define AQ_STENCIL_OPERATION_MASK_PASS_Start                                   7
#define AQ_STENCIL_OPERATION_MASK_PASS_Type                                  U01
#define   AQ_STENCIL_OPERATION_MASK_PASS_ENABLED                             0x0
#define   AQ_STENCIL_OPERATION_MASK_PASS_MASKED                              0x1

#define AQ_STENCIL_OPERATION_PASS                                            6:4
#define AQ_STENCIL_OPERATION_PASS_End                                          6
#define AQ_STENCIL_OPERATION_PASS_Start                                        4
#define AQ_STENCIL_OPERATION_PASS_Type                                       U03
#define   AQ_STENCIL_OPERATION_PASS_KEEP                                     0x0
#define   AQ_STENCIL_OPERATION_PASS_ZERO                                     0x1
#define   AQ_STENCIL_OPERATION_PASS_REPLACE                                  0x2
#define   AQ_STENCIL_OPERATION_PASS_INCREMENT_SAT                            0x3
#define   AQ_STENCIL_OPERATION_PASS_DECREMENT_SAT                            0x4
#define   AQ_STENCIL_OPERATION_PASS_INVERT                                   0x5
#define   AQ_STENCIL_OPERATION_PASS_INCREMENT                                0x6
#define   AQ_STENCIL_OPERATION_PASS_DECREMENT                                0x7


#define AQ_STENCIL_OPERATION_MASK_COMPARE                                    3:3
#define AQ_STENCIL_OPERATION_MASK_COMPARE_End                                  3
#define AQ_STENCIL_OPERATION_MASK_COMPARE_Start                                3
#define AQ_STENCIL_OPERATION_MASK_COMPARE_Type                               U01
#define   AQ_STENCIL_OPERATION_MASK_COMPARE_ENABLED                          0x0
#define   AQ_STENCIL_OPERATION_MASK_COMPARE_MASKED                           0x1


#define AQ_STENCIL_OPERATION_COMPARE                                         2:0
#define AQ_STENCIL_OPERATION_COMPARE_End                                       2
#define AQ_STENCIL_OPERATION_COMPARE_Start                                     0
#define AQ_STENCIL_OPERATION_COMPARE_Type                                    U03
#define   AQ_STENCIL_OPERATION_COMPARE_NEVER                                 0x0
#define   AQ_STENCIL_OPERATION_COMPARE_LESS                                  0x1
#define   AQ_STENCIL_OPERATION_COMPARE_EQUAL                                 0x2
#define   AQ_STENCIL_OPERATION_COMPARE_LESS_EQUAL                            0x3
#define   AQ_STENCIL_OPERATION_COMPARE_GREATER                               0x4
#define   AQ_STENCIL_OPERATION_COMPARE_NOT_EQUAL                             0x5
#define   AQ_STENCIL_OPERATION_COMPARE_GREATER_EQUAL                         0x6
#define   AQ_STENCIL_OPERATION_COMPARE_ALWAYS                                0x7

#define AQStencilConfigRegAddrs                                           0x0507
#define AQ_STENCIL_CONFIG_Address                                        0x0141C
#define AQ_STENCIL_CONFIG_MSB                                                 15
#define AQ_STENCIL_CONFIG_LSB                                                  0
#define AQ_STENCIL_CONFIG_BLK                                                  0
#define AQ_STENCIL_CONFIG_Count                                                1
#define AQ_STENCIL_CONFIG_FieldMask                                   0xFFFFFFF3
#define AQ_STENCIL_CONFIG_ReadMask                                    0xFFFFFFF3
#define AQ_STENCIL_CONFIG_WriteMask                                   0xFFFFFFF3
#define AQ_STENCIL_CONFIG_ResetValue                                  0x00000000


#define AQ_STENCIL_CONFIG_MASK_WRITE_MASK                                    7:7
#define AQ_STENCIL_CONFIG_MASK_WRITE_MASK_End                                  7
#define AQ_STENCIL_CONFIG_MASK_WRITE_MASK_Start                                7
#define AQ_STENCIL_CONFIG_MASK_WRITE_MASK_Type                               U01
#define   AQ_STENCIL_CONFIG_MASK_WRITE_MASK_ENABLED                          0x0
#define   AQ_STENCIL_CONFIG_MASK_WRITE_MASK_MASKED                           0x1


#define AQ_STENCIL_CONFIG_WRITE_MASK                                       31:24
#define AQ_STENCIL_CONFIG_WRITE_MASK_End                                      31
#define AQ_STENCIL_CONFIG_WRITE_MASK_Start                                    24
#define AQ_STENCIL_CONFIG_WRITE_MASK_Type                                    U08


#define AQ_STENCIL_CONFIG_MASK_MASK                                          6:6
#define AQ_STENCIL_CONFIG_MASK_MASK_End                                        6
#define AQ_STENCIL_CONFIG_MASK_MASK_Start                                      6
#define AQ_STENCIL_CONFIG_MASK_MASK_Type                                     U01
#define   AQ_STENCIL_CONFIG_MASK_MASK_ENABLED                                0x0
#define   AQ_STENCIL_CONFIG_MASK_MASK_MASKED                                 0x1


#define AQ_STENCIL_CONFIG_MASK                                             23:16
#define AQ_STENCIL_CONFIG_MASK_End                                            23
#define AQ_STENCIL_CONFIG_MASK_Start                                          16
#define AQ_STENCIL_CONFIG_MASK_Type                                          U08


#define AQ_STENCIL_CONFIG_MASK_REFERENCE                                     5:5
#define AQ_STENCIL_CONFIG_MASK_REFERENCE_End                                   5
#define AQ_STENCIL_CONFIG_MASK_REFERENCE_Start                                 5
#define AQ_STENCIL_CONFIG_MASK_REFERENCE_Type                                U01
#define   AQ_STENCIL_CONFIG_MASK_REFERENCE_ENABLED                           0x0
#define   AQ_STENCIL_CONFIG_MASK_REFERENCE_MASKED                            0x1


#define AQ_STENCIL_CONFIG_REFERENCE                                         15:8
#define AQ_STENCIL_CONFIG_REFERENCE_End                                       15
#define AQ_STENCIL_CONFIG_REFERENCE_Start                                      8
#define AQ_STENCIL_CONFIG_REFERENCE_Type                                     U08


#define AQ_STENCIL_CONFIG_MASK_TYPE                                          4:4
#define AQ_STENCIL_CONFIG_MASK_TYPE_End                                        4
#define AQ_STENCIL_CONFIG_MASK_TYPE_Start                                      4
#define AQ_STENCIL_CONFIG_MASK_TYPE_Type                                     U01
#define   AQ_STENCIL_CONFIG_MASK_TYPE_ENABLED                                0x0
#define   AQ_STENCIL_CONFIG_MASK_TYPE_MASKED                                 0x1


#define AQ_STENCIL_CONFIG_TYPE                                               1:0
#define AQ_STENCIL_CONFIG_TYPE_End                                             1
#define AQ_STENCIL_CONFIG_TYPE_Start                                           0
#define AQ_STENCIL_CONFIG_TYPE_Type                                          U02
#define   AQ_STENCIL_CONFIG_TYPE_NONE                                        0x0
#define   AQ_STENCIL_CONFIG_TYPE_ENABLED                                     0x1
#define   AQ_STENCIL_CONFIG_TYPE_TWO_SIDED                                   0x2

#define AQAlphaTestRegAddrs                                               0x0508
#define AQ_ALPHA_TEST_Address                                            0x01420
#define AQ_ALPHA_TEST_MSB                                                     15
#define AQ_ALPHA_TEST_LSB                                                      0
#define AQ_ALPHA_TEST_BLK                                                      0
#define AQ_ALPHA_TEST_Count                                                    1
#define AQ_ALPHA_TEST_FieldMask                                       0x0001FFF3
#define AQ_ALPHA_TEST_ReadMask                                        0x0001FFF3
#define AQ_ALPHA_TEST_WriteMask                                       0x0001FFF3
#define AQ_ALPHA_TEST_ResetValue                                      0x00000000


#define AQ_ALPHA_TEST_MASK_REFERENCE                                       16:16
#define AQ_ALPHA_TEST_MASK_REFERENCE_End                                      16
#define AQ_ALPHA_TEST_MASK_REFERENCE_Start                                    16
#define AQ_ALPHA_TEST_MASK_REFERENCE_Type                                    U01
#define   AQ_ALPHA_TEST_MASK_REFERENCE_ENABLED                               0x0
#define   AQ_ALPHA_TEST_MASK_REFERENCE_MASKED                                0x1


#define AQ_ALPHA_TEST_REFERENCE                                             15:8
#define AQ_ALPHA_TEST_REFERENCE_End                                           15
#define AQ_ALPHA_TEST_REFERENCE_Start                                          8
#define AQ_ALPHA_TEST_REFERENCE_Type                                         U08


#define AQ_ALPHA_TEST_MASK_COMPARE                                           7:7
#define AQ_ALPHA_TEST_MASK_COMPARE_End                                         7
#define AQ_ALPHA_TEST_MASK_COMPARE_Start                                       7
#define AQ_ALPHA_TEST_MASK_COMPARE_Type                                      U01
#define   AQ_ALPHA_TEST_MASK_COMPARE_ENABLED                                 0x0
#define   AQ_ALPHA_TEST_MASK_COMPARE_MASKED                                  0x1


#define AQ_ALPHA_TEST_COMPARE                                                6:4
#define AQ_ALPHA_TEST_COMPARE_End                                              6
#define AQ_ALPHA_TEST_COMPARE_Start                                            4
#define AQ_ALPHA_TEST_COMPARE_Type                                           U03
#define   AQ_ALPHA_TEST_COMPARE_NEVER                                        0x0
#define   AQ_ALPHA_TEST_COMPARE_LESS                                         0x1
#define   AQ_ALPHA_TEST_COMPARE_EQUAL                                        0x2
#define   AQ_ALPHA_TEST_COMPARE_LESS_EQUAL                                   0x3
#define   AQ_ALPHA_TEST_COMPARE_GREATER                                      0x4
#define   AQ_ALPHA_TEST_COMPARE_NOT_EQUAL                                    0x5
#define   AQ_ALPHA_TEST_COMPARE_GREATER_EQUAL                                0x6
#define   AQ_ALPHA_TEST_COMPARE_ALWAYS                                       0x7


#define AQ_ALPHA_TEST_MASK_TEST                                              1:1
#define AQ_ALPHA_TEST_MASK_TEST_End                                            1
#define AQ_ALPHA_TEST_MASK_TEST_Start                                          1
#define AQ_ALPHA_TEST_MASK_TEST_Type                                         U01
#define   AQ_ALPHA_TEST_MASK_TEST_ENABLED                                    0x0
#define   AQ_ALPHA_TEST_MASK_TEST_MASKED                                     0x1

#define AQ_ALPHA_TEST_TEST                                                   0:0
#define AQ_ALPHA_TEST_TEST_End                                                 0
#define AQ_ALPHA_TEST_TEST_Start                                               0
#define AQ_ALPHA_TEST_TEST_Type                                              U01
#define   AQ_ALPHA_TEST_TEST_DISABLED                                        0x0
#define   AQ_ALPHA_TEST_TEST_ENABLED                                         0x1

#define AQAlphaBlendFactorRegAddrs                                        0x0509
#define AQ_ALPHA_BLEND_FACTOR_Address                                    0x01424
#define AQ_ALPHA_BLEND_FACTOR_MSB                                             15
#define AQ_ALPHA_BLEND_FACTOR_LSB                                              0
#define AQ_ALPHA_BLEND_FACTOR_BLK                                              0
#define AQ_ALPHA_BLEND_FACTOR_Count                                            1
#define AQ_ALPHA_BLEND_FACTOR_FieldMask                               0xFFFFFFFF
#define AQ_ALPHA_BLEND_FACTOR_ReadMask                                0xFFFFFFFF
#define AQ_ALPHA_BLEND_FACTOR_WriteMask                               0xFFFFFFFF
#define AQ_ALPHA_BLEND_FACTOR_ResetValue                              0x00000000


#define AQ_ALPHA_BLEND_FACTOR_ALPHA                                        31:24
#define AQ_ALPHA_BLEND_FACTOR_ALPHA_End                                       31
#define AQ_ALPHA_BLEND_FACTOR_ALPHA_Start                                     24
#define AQ_ALPHA_BLEND_FACTOR_ALPHA_Type                                     U08


#define AQ_ALPHA_BLEND_FACTOR_RED                                          23:16
#define AQ_ALPHA_BLEND_FACTOR_RED_End                                         23
#define AQ_ALPHA_BLEND_FACTOR_RED_Start                                       16
#define AQ_ALPHA_BLEND_FACTOR_RED_Type                                       U08


#define AQ_ALPHA_BLEND_FACTOR_GREEN                                         15:8
#define AQ_ALPHA_BLEND_FACTOR_GREEN_End                                       15
#define AQ_ALPHA_BLEND_FACTOR_GREEN_Start                                      8
#define AQ_ALPHA_BLEND_FACTOR_GREEN_Type                                     U08


#define AQ_ALPHA_BLEND_FACTOR_BLUE                                           7:0
#define AQ_ALPHA_BLEND_FACTOR_BLUE_End                                         7
#define AQ_ALPHA_BLEND_FACTOR_BLUE_Start                                       0
#define AQ_ALPHA_BLEND_FACTOR_BLUE_Type                                      U08

#define AQAlphaBlendRegAddrs                                              0x050A
#define AQ_ALPHA_BLEND_Address                                           0x01428
#define AQ_ALPHA_BLEND_MSB                                                    15
#define AQ_ALPHA_BLEND_LSB                                                     0
#define AQ_ALPHA_BLEND_BLK                                                     0
#define AQ_ALPHA_BLEND_Count                                                   1
#define AQ_ALPHA_BLEND_FieldMask                                      0xFFFFFFFF
#define AQ_ALPHA_BLEND_ReadMask                                       0xFFFFFFFF
#define AQ_ALPHA_BLEND_WriteMask                                      0xFFFFFFFF
#define AQ_ALPHA_BLEND_ResetValue                                     0x00000000


#define AQ_ALPHA_BLEND_MASK_OPERATION_ALPHA                                31:31
#define AQ_ALPHA_BLEND_MASK_OPERATION_ALPHA_End                               31
#define AQ_ALPHA_BLEND_MASK_OPERATION_ALPHA_Start                             31
#define AQ_ALPHA_BLEND_MASK_OPERATION_ALPHA_Type                             U01
#define   AQ_ALPHA_BLEND_MASK_OPERATION_ALPHA_ENABLED                        0x0
#define   AQ_ALPHA_BLEND_MASK_OPERATION_ALPHA_MASKED                         0x1


#define AQ_ALPHA_BLEND_OPERATION_ALPHA                                     30:28
#define AQ_ALPHA_BLEND_OPERATION_ALPHA_End                                    30
#define AQ_ALPHA_BLEND_OPERATION_ALPHA_Start                                  28
#define AQ_ALPHA_BLEND_OPERATION_ALPHA_Type                                  U03
#define   AQ_ALPHA_BLEND_OPERATION_ALPHA_ADD                                 0x0
#define   AQ_ALPHA_BLEND_OPERATION_ALPHA_SUBTRACT                            0x1
#define   AQ_ALPHA_BLEND_OPERATION_ALPHA_REVERSE_SUBTRACT                    0x2
#define   AQ_ALPHA_BLEND_OPERATION_ALPHA_MIN                                 0x3
#define   AQ_ALPHA_BLEND_OPERATION_ALPHA_MAX                                 0x4


#define AQ_ALPHA_BLEND_MASK_DEST_BLEND_ALPHA                               19:19
#define AQ_ALPHA_BLEND_MASK_DEST_BLEND_ALPHA_End                              19
#define AQ_ALPHA_BLEND_MASK_DEST_BLEND_ALPHA_Start                            19
#define AQ_ALPHA_BLEND_MASK_DEST_BLEND_ALPHA_Type                            U01
#define   AQ_ALPHA_BLEND_MASK_DEST_BLEND_ALPHA_ENABLED                       0x0
#define   AQ_ALPHA_BLEND_MASK_DEST_BLEND_ALPHA_MASKED                        0x1


#define AQ_ALPHA_BLEND_DEST_BLEND_ALPHA                                    27:24
#define AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_End                                   27
#define AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_Start                                 24
#define AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_Type                                 U04
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_ZERO                               0x0
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_ONE                                0x1
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_SRC_COLOR                          0x2
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_INV_SRC_COLOR                      0x3
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_SRC_ALPHA                          0x4
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_INV_SRC_ALPHA                      0x5
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_DEST_ALPHA                         0x6
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_INV_DEST_ALPHA                     0x7
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_DEST_COLOR                         0x8
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_INV_DEST_COLOR                     0x9
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_SRC_ALPHA_SAT                      0xA
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_BLEND_FACTOR_ALPHA                 0xB
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_INV_BLEND_FACTOR_ALPHA             0xC
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_BLEND_FACTOR                       0xD
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_INV_BLEND_FACTOR                   0xE
#define   AQ_ALPHA_BLEND_DEST_BLEND_ALPHA_EXTEND                             0xF


#define AQ_ALPHA_BLEND_MASK_SRC_BLEND_ALPHA                                18:18
#define AQ_ALPHA_BLEND_MASK_SRC_BLEND_ALPHA_End                               18
#define AQ_ALPHA_BLEND_MASK_SRC_BLEND_ALPHA_Start                             18
#define AQ_ALPHA_BLEND_MASK_SRC_BLEND_ALPHA_Type                             U01
#define   AQ_ALPHA_BLEND_MASK_SRC_BLEND_ALPHA_ENABLED                        0x0
#define   AQ_ALPHA_BLEND_MASK_SRC_BLEND_ALPHA_MASKED                         0x1


#define AQ_ALPHA_BLEND_SRC_BLEND_ALPHA                                     23:20
#define AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_End                                    23
#define AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_Start                                  20
#define AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_Type                                  U04
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_ZERO                                0x0
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_ONE                                 0x1
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_SRC_COLOR                           0x2
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_INV_SRC_COLOR                       0x3
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_SRC_ALPHA                           0x4
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_INV_SRC_ALPHA                       0x5
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_DEST_ALPHA                          0x6
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_INV_DEST_ALPHA                      0x7
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_DEST_COLOR                          0x8
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_INV_DEST_COLOR                      0x9
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_SRC_ALPHA_SAT                       0xA
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_BLEND_FACTOR_ALPHA                  0xB
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_INV_BLEND_FACTOR_ALPHA              0xC
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_BLEND_FACTOR                        0xD
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_INV_BLEND_FACTOR                    0xE
#define   AQ_ALPHA_BLEND_SRC_BLEND_ALPHA_EXTEND                              0xF


#define AQ_ALPHA_BLEND_MASK_ENABLE_ALPHA                                   17:17
#define AQ_ALPHA_BLEND_MASK_ENABLE_ALPHA_End                                  17
#define AQ_ALPHA_BLEND_MASK_ENABLE_ALPHA_Start                                17
#define AQ_ALPHA_BLEND_MASK_ENABLE_ALPHA_Type                                U01
#define   AQ_ALPHA_BLEND_MASK_ENABLE_ALPHA_ENABLED                           0x0
#define   AQ_ALPHA_BLEND_MASK_ENABLE_ALPHA_MASKED                            0x1

#define AQ_ALPHA_BLEND_ENABLE_ALPHA                                        16:16
#define AQ_ALPHA_BLEND_ENABLE_ALPHA_End                                       16
#define AQ_ALPHA_BLEND_ENABLE_ALPHA_Start                                     16
#define AQ_ALPHA_BLEND_ENABLE_ALPHA_Type                                     U01
#define   AQ_ALPHA_BLEND_ENABLE_ALPHA_DISABLED                               0x0
#define   AQ_ALPHA_BLEND_ENABLE_ALPHA_ENABLED                                0x1


#define AQ_ALPHA_BLEND_MASK_OPERATION                                      15:15
#define AQ_ALPHA_BLEND_MASK_OPERATION_End                                     15
#define AQ_ALPHA_BLEND_MASK_OPERATION_Start                                   15
#define AQ_ALPHA_BLEND_MASK_OPERATION_Type                                   U01
#define   AQ_ALPHA_BLEND_MASK_OPERATION_ENABLED                              0x0
#define   AQ_ALPHA_BLEND_MASK_OPERATION_MASKED                               0x1


#define AQ_ALPHA_BLEND_OPERATION                                           14:12
#define AQ_ALPHA_BLEND_OPERATION_End                                          14
#define AQ_ALPHA_BLEND_OPERATION_Start                                        12
#define AQ_ALPHA_BLEND_OPERATION_Type                                        U03
#define   AQ_ALPHA_BLEND_OPERATION_ADD                                       0x0
#define   AQ_ALPHA_BLEND_OPERATION_SUBTRACT                                  0x1
#define   AQ_ALPHA_BLEND_OPERATION_REVERSE_SUBTRACT                          0x2
#define   AQ_ALPHA_BLEND_OPERATION_MIN                                       0x3
#define   AQ_ALPHA_BLEND_OPERATION_MAX                                       0x4


#define AQ_ALPHA_BLEND_MASK_DEST_BLEND                                       3:3
#define AQ_ALPHA_BLEND_MASK_DEST_BLEND_End                                     3
#define AQ_ALPHA_BLEND_MASK_DEST_BLEND_Start                                   3
#define AQ_ALPHA_BLEND_MASK_DEST_BLEND_Type                                  U01
#define   AQ_ALPHA_BLEND_MASK_DEST_BLEND_ENABLED                             0x0
#define   AQ_ALPHA_BLEND_MASK_DEST_BLEND_MASKED                              0x1


#define AQ_ALPHA_BLEND_DEST_BLEND                                           11:8
#define AQ_ALPHA_BLEND_DEST_BLEND_End                                         11
#define AQ_ALPHA_BLEND_DEST_BLEND_Start                                        8
#define AQ_ALPHA_BLEND_DEST_BLEND_Type                                       U04
#define   AQ_ALPHA_BLEND_DEST_BLEND_ZERO                                     0x0
#define   AQ_ALPHA_BLEND_DEST_BLEND_ONE                                      0x1
#define   AQ_ALPHA_BLEND_DEST_BLEND_SRC_COLOR                                0x2
#define   AQ_ALPHA_BLEND_DEST_BLEND_INV_SRC_COLOR                            0x3
#define   AQ_ALPHA_BLEND_DEST_BLEND_SRC_ALPHA                                0x4
#define   AQ_ALPHA_BLEND_DEST_BLEND_INV_SRC_ALPHA                            0x5
#define   AQ_ALPHA_BLEND_DEST_BLEND_DEST_ALPHA                               0x6
#define   AQ_ALPHA_BLEND_DEST_BLEND_INV_DEST_ALPHA                           0x7
#define   AQ_ALPHA_BLEND_DEST_BLEND_DEST_COLOR                               0x8
#define   AQ_ALPHA_BLEND_DEST_BLEND_INV_DEST_COLOR                           0x9
#define   AQ_ALPHA_BLEND_DEST_BLEND_SRC_ALPHA_SAT                            0xA
#define   AQ_ALPHA_BLEND_DEST_BLEND_BLEND_FACTOR_ALPHA                       0xB
#define   AQ_ALPHA_BLEND_DEST_BLEND_INV_BLEND_FACTOR_ALPHA                   0xC
#define   AQ_ALPHA_BLEND_DEST_BLEND_BLEND_FACTOR                             0xD
#define   AQ_ALPHA_BLEND_DEST_BLEND_INV_BLEND_FACTOR                         0xE
#define   AQ_ALPHA_BLEND_DEST_BLEND_EXTEND                                   0xF


#define AQ_ALPHA_BLEND_MASK_SRC_BLEND                                        2:2
#define AQ_ALPHA_BLEND_MASK_SRC_BLEND_End                                      2
#define AQ_ALPHA_BLEND_MASK_SRC_BLEND_Start                                    2
#define AQ_ALPHA_BLEND_MASK_SRC_BLEND_Type                                   U01
#define   AQ_ALPHA_BLEND_MASK_SRC_BLEND_ENABLED                              0x0
#define   AQ_ALPHA_BLEND_MASK_SRC_BLEND_MASKED                               0x1


#define AQ_ALPHA_BLEND_SRC_BLEND                                             7:4
#define AQ_ALPHA_BLEND_SRC_BLEND_End                                           7
#define AQ_ALPHA_BLEND_SRC_BLEND_Start                                         4
#define AQ_ALPHA_BLEND_SRC_BLEND_Type                                        U04
#define   AQ_ALPHA_BLEND_SRC_BLEND_ZERO                                      0x0
#define   AQ_ALPHA_BLEND_SRC_BLEND_ONE                                       0x1
#define   AQ_ALPHA_BLEND_SRC_BLEND_SRC_COLOR                                 0x2
#define   AQ_ALPHA_BLEND_SRC_BLEND_INV_SRC_COLOR                             0x3
#define   AQ_ALPHA_BLEND_SRC_BLEND_SRC_ALPHA                                 0x4
#define   AQ_ALPHA_BLEND_SRC_BLEND_INV_SRC_ALPHA                             0x5
#define   AQ_ALPHA_BLEND_SRC_BLEND_DEST_ALPHA                                0x6
#define   AQ_ALPHA_BLEND_SRC_BLEND_INV_DEST_ALPHA                            0x7
#define   AQ_ALPHA_BLEND_SRC_BLEND_DEST_COLOR                                0x8
#define   AQ_ALPHA_BLEND_SRC_BLEND_INV_DEST_COLOR                            0x9
#define   AQ_ALPHA_BLEND_SRC_BLEND_SRC_ALPHA_SAT                             0xA
#define   AQ_ALPHA_BLEND_SRC_BLEND_BLEND_FACTOR_ALPHA                        0xB
#define   AQ_ALPHA_BLEND_SRC_BLEND_INV_BLEND_FACTOR_ALPHA                    0xC
#define   AQ_ALPHA_BLEND_SRC_BLEND_BLEND_FACTOR                              0xD
#define   AQ_ALPHA_BLEND_SRC_BLEND_INV_BLEND_FACTOR                          0xE
#define   AQ_ALPHA_BLEND_SRC_BLEND_EXTEND                                    0xF


#define AQ_ALPHA_BLEND_MASK_ENABLE                                           1:1
#define AQ_ALPHA_BLEND_MASK_ENABLE_End                                         1
#define AQ_ALPHA_BLEND_MASK_ENABLE_Start                                       1
#define AQ_ALPHA_BLEND_MASK_ENABLE_Type                                      U01
#define   AQ_ALPHA_BLEND_MASK_ENABLE_ENABLED                                 0x0
#define   AQ_ALPHA_BLEND_MASK_ENABLE_MASKED                                  0x1


#define AQ_ALPHA_BLEND_ENABLE                                                0:0
#define AQ_ALPHA_BLEND_ENABLE_End                                              0
#define AQ_ALPHA_BLEND_ENABLE_Start                                            0
#define AQ_ALPHA_BLEND_ENABLE_Type                                           U01
#define   AQ_ALPHA_BLEND_ENABLE_DISABLED                                     0x0
#define   AQ_ALPHA_BLEND_ENABLE_ENABLED                                      0x1

#define AQPixelConfigRegAddrs                                             0x050B
#define AQ_PIXEL_CONFIG_Address                                          0x0142C
#define AQ_PIXEL_CONFIG_MSB                                                   15
#define AQ_PIXEL_CONFIG_LSB                                                    0
#define AQ_PIXEL_CONFIG_BLK                                                    0
#define AQ_PIXEL_CONFIG_Count                                                  1
#define AQ_PIXEL_CONFIG_FieldMask                                     0xBF7FFFDF
#define AQ_PIXEL_CONFIG_ReadMask                                      0xBF7FFFDF
#define AQ_PIXEL_CONFIG_WriteMask                                     0xBF7FFFDF
#define AQ_PIXEL_CONFIG_ResetValue                                    0x00000000


#define AQ_PIXEL_CONFIG_MASK_NEW_FORMAT                                    31:31
#define AQ_PIXEL_CONFIG_MASK_NEW_FORMAT_End                                   31
#define AQ_PIXEL_CONFIG_MASK_NEW_FORMAT_Start                                 31
#define AQ_PIXEL_CONFIG_MASK_NEW_FORMAT_Type                                 U01
#define   AQ_PIXEL_CONFIG_MASK_NEW_FORMAT_ENABLED                            0x0
#define   AQ_PIXEL_CONFIG_MASK_NEW_FORMAT_MASKED                             0x1

#define AQ_PIXEL_CONFIG_NEW_FORMAT                                         29:24
#define AQ_PIXEL_CONFIG_NEW_FORMAT_End                                        29
#define AQ_PIXEL_CONFIG_NEW_FORMAT_Start                                      24
#define AQ_PIXEL_CONFIG_NEW_FORMAT_Type                                      U06
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_X4R4G4B4                               0x00
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_A4R4G4B4                               0x01
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_X1R5G5B5                               0x02
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_A1R5G5B5                               0x03
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_R5G6B5                                 0x04
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_X8R8G8B8                               0x05
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_A8R8G8B8                               0x06
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_YUY2                                   0x07
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_UYVY                                   0x08
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_INDEX8                                 0x09
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_MONOCHROME                             0x0A
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_HDR7E3                                 0x0B
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_HDR6E4                                 0x0C
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_HDR5E5                                 0x0D
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_HDR6E5                                 0x0E
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_YV12                                   0x0F
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_A8                                     0x10
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RF16                                   0x11
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RF16GF16                               0x12
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RF16GF16BF16AF16                       0x13
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RF32                                   0x14
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RF32GF32                               0x15
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_R10G10B10A2                            0x16
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI8                                    0x17
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI8GI8                                 0x18
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI8GI8BI8AI8                           0x19
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI16                                   0x1A
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI16GI16                               0x1B
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI16GI16BI16AI16                       0x1C
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI32                                   0x14
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI32GI32                               0x15
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RF11GF11BF10                           0x1D
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI10GI10BI10AI2                        0x1E
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_R8G8                                   0x1F
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_R8                                     0x23
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RF32GF32BF32AF32                       0x25
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI32GI32BI32AI32                       0x26
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_R16                                    0x27
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RUI32GUI32BUI32AUI32                   0x26
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RSI32GSI32BSI32ASI32                   0x27
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_A8B8G8R8                               0x2B
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI32_NEW                               0x2D
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_RI32GI32_NEW                           0x2E
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_R16G16                                 0x2F
#define   AQ_PIXEL_CONFIG_NEW_FORMAT_R16G16B16A16                           0x30


#define AQ_PIXEL_CONFIG_SIGN_CONTROL                                       22:22
#define AQ_PIXEL_CONFIG_SIGN_CONTROL_End                                      22
#define AQ_PIXEL_CONFIG_SIGN_CONTROL_Start                                    22
#define AQ_PIXEL_CONFIG_SIGN_CONTROL_Type                                    U01
#define   AQ_PIXEL_CONFIG_SIGN_CONTROL_UNSIGN                                0x0
#define   AQ_PIXEL_CONFIG_SIGN_CONTROL_SIGN                                  0x1


#define AQ_PIXEL_CONFIG_MASK_SUPER_TILE                                    21:21
#define AQ_PIXEL_CONFIG_MASK_SUPER_TILE_End                                   21
#define AQ_PIXEL_CONFIG_MASK_SUPER_TILE_Start                                 21
#define AQ_PIXEL_CONFIG_MASK_SUPER_TILE_Type                                 U01
#define   AQ_PIXEL_CONFIG_MASK_SUPER_TILE_ENABLED                            0x0
#define   AQ_PIXEL_CONFIG_MASK_SUPER_TILE_MASKED                             0x1

#define AQ_PIXEL_CONFIG_SUPER_TILE                                         20:20
#define AQ_PIXEL_CONFIG_SUPER_TILE_End                                        20
#define AQ_PIXEL_CONFIG_SUPER_TILE_Start                                      20
#define AQ_PIXEL_CONFIG_SUPER_TILE_Type                                      U01
#define   AQ_PIXEL_CONFIG_SUPER_TILE_DISABLED                                0x0
#define   AQ_PIXEL_CONFIG_SUPER_TILE_ENABLED                                 0x1


#define AQ_PIXEL_CONFIG_MASK_ADDR_REMAP                                    19:19
#define AQ_PIXEL_CONFIG_MASK_ADDR_REMAP_End                                   19
#define AQ_PIXEL_CONFIG_MASK_ADDR_REMAP_Start                                 19
#define AQ_PIXEL_CONFIG_MASK_ADDR_REMAP_Type                                 U01
#define   AQ_PIXEL_CONFIG_MASK_ADDR_REMAP_ENABLED                            0x0
#define   AQ_PIXEL_CONFIG_MASK_ADDR_REMAP_MASKED                             0x1


#define AQ_PIXEL_CONFIG_ADDR_REMAP                                         18:18
#define AQ_PIXEL_CONFIG_ADDR_REMAP_End                                        18
#define AQ_PIXEL_CONFIG_ADDR_REMAP_Start                                      18
#define AQ_PIXEL_CONFIG_ADDR_REMAP_Type                                      U01
#define   AQ_PIXEL_CONFIG_ADDR_REMAP_DISABLED                                0x0
#define   AQ_PIXEL_CONFIG_ADDR_REMAP_ENABLED                                 0x1


#define AQ_PIXEL_CONFIG_MASK_DESTINATION_READ                              17:17
#define AQ_PIXEL_CONFIG_MASK_DESTINATION_READ_End                             17
#define AQ_PIXEL_CONFIG_MASK_DESTINATION_READ_Start                           17
#define AQ_PIXEL_CONFIG_MASK_DESTINATION_READ_Type                           U01
#define   AQ_PIXEL_CONFIG_MASK_DESTINATION_READ_ENABLED                      0x0
#define   AQ_PIXEL_CONFIG_MASK_DESTINATION_READ_MASKED                       0x1


#define AQ_PIXEL_CONFIG_DESTINATION_READ                                   16:16
#define AQ_PIXEL_CONFIG_DESTINATION_READ_End                                  16
#define AQ_PIXEL_CONFIG_DESTINATION_READ_Start                                16
#define AQ_PIXEL_CONFIG_DESTINATION_READ_Type                                U01
#define   AQ_PIXEL_CONFIG_DESTINATION_READ_READ                              0x0
#define   AQ_PIXEL_CONFIG_DESTINATION_READ_DONT_READ                         0x1


#define AQ_PIXEL_CONFIG_MASK_TILE_MODE                                     15:15
#define AQ_PIXEL_CONFIG_MASK_TILE_MODE_End                                    15
#define AQ_PIXEL_CONFIG_MASK_TILE_MODE_Start                                  15
#define AQ_PIXEL_CONFIG_MASK_TILE_MODE_Type                                  U01
#define   AQ_PIXEL_CONFIG_MASK_TILE_MODE_ENABLED                             0x0
#define   AQ_PIXEL_CONFIG_MASK_TILE_MODE_MASKED                              0x1


#define AQ_PIXEL_CONFIG_TILE_MODE                                          14:13
#define AQ_PIXEL_CONFIG_TILE_MODE_End                                         14
#define AQ_PIXEL_CONFIG_TILE_MODE_Start                                       13
#define AQ_PIXEL_CONFIG_TILE_MODE_Type                                       U02
#define   AQ_PIXEL_CONFIG_TILE_MODE_TILED4X4                                 0x0
#define   AQ_PIXEL_CONFIG_TILE_MODE_SUPER_TILED_XMAJOR                       0x1
#define   AQ_PIXEL_CONFIG_TILE_MODE_SUPER_TILED_YMAJOR                       0x2


#define AQ_PIXEL_CONFIG_MASK_COLOR_WRITE                                   12:12
#define AQ_PIXEL_CONFIG_MASK_COLOR_WRITE_End                                  12
#define AQ_PIXEL_CONFIG_MASK_COLOR_WRITE_Start                                12
#define AQ_PIXEL_CONFIG_MASK_COLOR_WRITE_Type                                U01
#define   AQ_PIXEL_CONFIG_MASK_COLOR_WRITE_ENABLED                           0x0
#define   AQ_PIXEL_CONFIG_MASK_COLOR_WRITE_MASKED                            0x1


#define AQ_PIXEL_CONFIG_COLOR_WRITE                                         11:8
#define AQ_PIXEL_CONFIG_COLOR_WRITE_End                                       11
#define AQ_PIXEL_CONFIG_COLOR_WRITE_Start                                      8
#define AQ_PIXEL_CONFIG_COLOR_WRITE_Type                                     U04
#define   AQ_PIXEL_CONFIG_COLOR_WRITE_RED                                    0x1
#define   AQ_PIXEL_CONFIG_COLOR_WRITE_GREEN                                  0x2
#define   AQ_PIXEL_CONFIG_COLOR_WRITE_BLUE                                   0x4
#define   AQ_PIXEL_CONFIG_COLOR_WRITE_ALPHA                                  0x8


#define AQ_PIXEL_CONFIG_MASK_COLOR_PIPE                                      7:7
#define AQ_PIXEL_CONFIG_MASK_COLOR_PIPE_End                                    7
#define AQ_PIXEL_CONFIG_MASK_COLOR_PIPE_Start                                  7
#define AQ_PIXEL_CONFIG_MASK_COLOR_PIPE_Type                                 U01
#define   AQ_PIXEL_CONFIG_MASK_COLOR_PIPE_ENABLED                            0x0
#define   AQ_PIXEL_CONFIG_MASK_COLOR_PIPE_MASKED                             0x1


#define AQ_PIXEL_CONFIG_COLOR_PIPE                                           6:6
#define AQ_PIXEL_CONFIG_COLOR_PIPE_End                                         6
#define AQ_PIXEL_CONFIG_COLOR_PIPE_Start                                       6
#define AQ_PIXEL_CONFIG_COLOR_PIPE_Type                                      U01
#define   AQ_PIXEL_CONFIG_COLOR_PIPE_ENABLE                                  0x0
#define   AQ_PIXEL_CONFIG_COLOR_PIPE_DISABLE                                 0x1


#define AQ_PIXEL_CONFIG_MASK_FORMAT                                          4:4
#define AQ_PIXEL_CONFIG_MASK_FORMAT_End                                        4
#define AQ_PIXEL_CONFIG_MASK_FORMAT_Start                                      4
#define AQ_PIXEL_CONFIG_MASK_FORMAT_Type                                     U01
#define   AQ_PIXEL_CONFIG_MASK_FORMAT_ENABLED                                0x0
#define   AQ_PIXEL_CONFIG_MASK_FORMAT_MASKED                                 0x1


#define AQ_PIXEL_CONFIG_FORMAT                                               3:0
#define AQ_PIXEL_CONFIG_FORMAT_End                                             3
#define AQ_PIXEL_CONFIG_FORMAT_Start                                           0
#define AQ_PIXEL_CONFIG_FORMAT_Type                                          U04
#define   AQ_PIXEL_CONFIG_FORMAT_X4R4G4B4                                    0x0
#define   AQ_PIXEL_CONFIG_FORMAT_A4R4G4B4                                    0x1
#define   AQ_PIXEL_CONFIG_FORMAT_X1R5G5B5                                    0x2
#define   AQ_PIXEL_CONFIG_FORMAT_A1R5G5B5                                    0x3
#define   AQ_PIXEL_CONFIG_FORMAT_R5G6B5                                      0x4
#define   AQ_PIXEL_CONFIG_FORMAT_X8R8G8B8                                    0x5
#define   AQ_PIXEL_CONFIG_FORMAT_A8R8G8B8                                    0x6
#define   AQ_PIXEL_CONFIG_FORMAT_YUY2                                        0x7
#define   AQ_PIXEL_CONFIG_FORMAT_UYVY                                        0x8
#define   AQ_PIXEL_CONFIG_FORMAT_INDEX8                                      0x9
#define   AQ_PIXEL_CONFIG_FORMAT_MONOCHROME                                  0xA
#define   AQ_PIXEL_CONFIG_FORMAT_HDR7E3                                      0xB
#define   AQ_PIXEL_CONFIG_FORMAT_HDR6E4                                      0xC
#define   AQ_PIXEL_CONFIG_FORMAT_HDR5E5                                      0xD
#define   AQ_PIXEL_CONFIG_FORMAT_HDR6E5                                      0xE
#define   AQ_PIXEL_CONFIG_FORMAT_YV12                                        0xF




#define AQPixelAddressRegAddrs                                            0x050C
#define AQ_PIXEL_ADDRESS_Address                                         0x01430
#define AQ_PIXEL_ADDRESS_MSB                                                  15
#define AQ_PIXEL_ADDRESS_LSB                                                   0
#define AQ_PIXEL_ADDRESS_BLK                                                   0
#define AQ_PIXEL_ADDRESS_Count                                                 1
#define AQ_PIXEL_ADDRESS_FieldMask                                    0xFFFFFFFF
#define AQ_PIXEL_ADDRESS_ReadMask                                     0xFFFFFFFC
#define AQ_PIXEL_ADDRESS_WriteMask                                    0xFFFFFFFC
#define AQ_PIXEL_ADDRESS_ResetValue                                   0x00000000

#define AQ_PIXEL_ADDRESS_TYPE                                              31:31
#define AQ_PIXEL_ADDRESS_TYPE_End                                             31
#define AQ_PIXEL_ADDRESS_TYPE_Start                                           31
#define AQ_PIXEL_ADDRESS_TYPE_Type                                           U01
#define   AQ_PIXEL_ADDRESS_TYPE_SYSTEM                                       0x0
#define   AQ_PIXEL_ADDRESS_TYPE_VIRTUAL_SYSTEM                               0x1

#define AQ_PIXEL_ADDRESS_ADDRESS                                            30:0
#define AQ_PIXEL_ADDRESS_ADDRESS_End                                          30
#define AQ_PIXEL_ADDRESS_ADDRESS_Start                                         0
#define AQ_PIXEL_ADDRESS_ADDRESS_Type                                        U31




#define AQPixelStrideRegAddrs                                             0x050D
#define AQ_PIXEL_STRIDE_Address                                          0x01434
#define AQ_PIXEL_STRIDE_MSB                                                   15
#define AQ_PIXEL_STRIDE_LSB                                                    0
#define AQ_PIXEL_STRIDE_BLK                                                    0
#define AQ_PIXEL_STRIDE_Count                                                  1
#define AQ_PIXEL_STRIDE_FieldMask                                     0x0003FFFF
#define AQ_PIXEL_STRIDE_ReadMask                                      0x0003FFFC
#define AQ_PIXEL_STRIDE_WriteMask                                     0x0003FFFC
#define AQ_PIXEL_STRIDE_ResetValue                                    0x00000000

#define AQ_PIXEL_STRIDE_STRIDE                                              17:0
#define AQ_PIXEL_STRIDE_STRIDE_End                                            17
#define AQ_PIXEL_STRIDE_STRIDE_Start                                           0
#define AQ_PIXEL_STRIDE_STRIDE_Type                                          U18

#define AQPEBistControlRegAddrs                                           0x050E
#define AQPE_BIST_CONTROL_Address                                        0x01438
#define AQPE_BIST_CONTROL_MSB                                                 15
#define AQPE_BIST_CONTROL_LSB                                                  0
#define AQPE_BIST_CONTROL_BLK                                                  0
#define AQPE_BIST_CONTROL_Count                                                1
#define AQPE_BIST_CONTROL_FieldMask                                   0x00000003
#define AQPE_BIST_CONTROL_ReadMask                                    0x00000003
#define AQPE_BIST_CONTROL_WriteMask                                   0x00000003
#define AQPE_BIST_CONTROL_ResetValue                                  0x00000000

#define AQPE_BIST_CONTROL_RESET                                              0:0
#define AQPE_BIST_CONTROL_RESET_End                                            0
#define AQPE_BIST_CONTROL_RESET_Start                                          0
#define AQPE_BIST_CONTROL_RESET_Type                                         U01
#define   AQPE_BIST_CONTROL_RESET_NOT_RESET                                  0x0
#define   AQPE_BIST_CONTROL_RESET_RESET                                      0x1

#define AQPE_BIST_CONTROL_MODE                                               1:1
#define AQPE_BIST_CONTROL_MODE_End                                             1
#define AQPE_BIST_CONTROL_MODE_Start                                           1
#define AQPE_BIST_CONTROL_MODE_Type                                          U01
#define   AQPE_BIST_CONTROL_MODE_NOT_BIST_MODE                               0x0
#define   AQPE_BIST_CONTROL_MODE_BIST_MODE                                   0x1

#define AQPEBistStatus0RegAddrs                                           0x050F
#define AQPE_BIST_STATUS0_Address                                        0x0143C
#define AQPE_BIST_STATUS0_MSB                                                 15
#define AQPE_BIST_STATUS0_LSB                                                  0
#define AQPE_BIST_STATUS0_BLK                                                  0
#define AQPE_BIST_STATUS0_Count                                                1
#define AQPE_BIST_STATUS0_FieldMask                                   0x00000001
#define AQPE_BIST_STATUS0_ReadMask                                    0x00000001
#define AQPE_BIST_STATUS0_WriteMask                                   0x00000001
#define AQPE_BIST_STATUS0_ResetValue                                  0x00000000

#define AQPE_BIST_STATUS0_DONE                                               0:0
#define AQPE_BIST_STATUS0_DONE_End                                             0
#define AQPE_BIST_STATUS0_DONE_Start                                           0
#define AQPE_BIST_STATUS0_DONE_Type                                          U01
#define   AQPE_BIST_STATUS0_DONE_NOT_DONE                                    0x0
#define   AQPE_BIST_STATUS0_DONE_DONE                                        0x1

#define AQPEBistStatus1RegAddrs                                           0x0510
#define AQPE_BIST_STATUS1_Address                                        0x01440
#define AQPE_BIST_STATUS1_MSB                                                 15
#define AQPE_BIST_STATUS1_LSB                                                  0
#define AQPE_BIST_STATUS1_BLK                                                  0
#define AQPE_BIST_STATUS1_Count                                                1
#define AQPE_BIST_STATUS1_FieldMask                                   0x000FFFFF
#define AQPE_BIST_STATUS1_ReadMask                                    0x000FFFFF
#define AQPE_BIST_STATUS1_WriteMask                                   0x000FFFFF
#define AQPE_BIST_STATUS1_ResetValue                                  0x00000000

#define AQPE_BIST_STATUS1_BM_ERROR                                          19:0
#define AQPE_BIST_STATUS1_BM_ERROR_End                                        19
#define AQPE_BIST_STATUS1_BM_ERROR_Start                                       0
#define AQPE_BIST_STATUS1_BM_ERROR_Type                                      U20




#define AQPixelOpenVGRegAddrs                                             0x0511
#define AQ_PIXEL_OPEN_VG_Address                                         0x01444
#define AQ_PIXEL_OPEN_VG_MSB                                                  15
#define AQ_PIXEL_OPEN_VG_LSB                                                   0
#define AQ_PIXEL_OPEN_VG_BLK                                                   0
#define AQ_PIXEL_OPEN_VG_Count                                                 1
#define AQ_PIXEL_OPEN_VG_FieldMask                                    0xFFFFFFFF
#define AQ_PIXEL_OPEN_VG_ReadMask                                     0xFFFFFFFF
#define AQ_PIXEL_OPEN_VG_WriteMask                                    0xFFFFFFFF
#define AQ_PIXEL_OPEN_VG_ResetValue                                   0x00000000

#define AQ_PIXEL_OPEN_VG_RESERVED                                           31:0
#define AQ_PIXEL_OPEN_VG_RESERVED_End                                         31
#define AQ_PIXEL_OPEN_VG_RESERVED_Start                                        0
#define AQ_PIXEL_OPEN_VG_RESERVED_Type                                       U32

#define AQPixelCacheDebugRegAddrs                                         0x0512
#define AQ_PIXEL_CACHE_DEBUG_Address                                     0x01448
#define AQ_PIXEL_CACHE_DEBUG_MSB                                              15
#define AQ_PIXEL_CACHE_DEBUG_LSB                                               0
#define AQ_PIXEL_CACHE_DEBUG_BLK                                               0
#define AQ_PIXEL_CACHE_DEBUG_Count                                             1
#define AQ_PIXEL_CACHE_DEBUG_FieldMask                                0x0000000F
#define AQ_PIXEL_CACHE_DEBUG_ReadMask                                 0x0000000F
#define AQ_PIXEL_CACHE_DEBUG_WriteMask                                0x0000000F
#define AQ_PIXEL_CACHE_DEBUG_ResetValue                               0x0000000D

#define AQ_PIXEL_CACHE_DEBUG_MAX_WRITE_OUT                                   3:0
#define AQ_PIXEL_CACHE_DEBUG_MAX_WRITE_OUT_End                                 3
#define AQ_PIXEL_CACHE_DEBUG_MAX_WRITE_OUT_Start                               0
#define AQ_PIXEL_CACHE_DEBUG_MAX_WRITE_OUT_Type                              U04

#define AQPixelMcMaskCtrlRegAddrs                                         0x0513
#define AQ_PIXEL_MC_MASK_CTRL_Address                                    0x0144C
#define AQ_PIXEL_MC_MASK_CTRL_MSB                                             15
#define AQ_PIXEL_MC_MASK_CTRL_LSB                                              0
#define AQ_PIXEL_MC_MASK_CTRL_BLK                                              0
#define AQ_PIXEL_MC_MASK_CTRL_Count                                            1
#define AQ_PIXEL_MC_MASK_CTRL_FieldMask                               0x00000003
#define AQ_PIXEL_MC_MASK_CTRL_ReadMask                                0x00000003
#define AQ_PIXEL_MC_MASK_CTRL_WriteMask                               0x00000003
#define AQ_PIXEL_MC_MASK_CTRL_ResetValue                              0x00000000

#define AQ_PIXEL_MC_MASK_CTRL_MC_MASK_DISABLE                                0:0
#define AQ_PIXEL_MC_MASK_CTRL_MC_MASK_DISABLE_End                              0
#define AQ_PIXEL_MC_MASK_CTRL_MC_MASK_DISABLE_Start                            0
#define AQ_PIXEL_MC_MASK_CTRL_MC_MASK_DISABLE_Type                           U01

#define AQ_PIXEL_MC_MASK_CTRL_MC_PARTIAL_WR_DISABLE                          1:1
#define AQ_PIXEL_MC_MASK_CTRL_MC_PARTIAL_WR_DISABLE_End                        1
#define AQ_PIXEL_MC_MASK_CTRL_MC_PARTIAL_WR_DISABLE_Start                      1
#define AQ_PIXEL_MC_MASK_CTRL_MC_PARTIAL_WR_DISABLE_Type                     U01

#define AQPixelCacheMemReqLimitRegAddrs                                   0x0514
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_Address                             0x01450
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MSB                                      15
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_LSB                                       0
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_BLK                                       0
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_Count                                     1
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_FieldMask                        0x00000F3F
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_ReadMask                         0x00000F3F
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_WriteMask                        0x00000F3F
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_ResetValue                       0x0000051E

#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT                           5:0
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT_End                         5
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT_Start                       0
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT_Type                      U06

#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT_STEP                     11:8
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT_STEP_End                   11
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT_STEP_Start                  8
#define AQ_PIXEL_CACHE_MEM_REQ_LIMIT_MEM_REQ_LIMIT_STEP_Type                 U04




#define mwv207regPEHierarchicalControlRegAddrs                            0x0515
#define MWV207REG_PE_HIERARCHICAL_CONTROL_Address                        0x01454
#define MWV207REG_PE_HIERARCHICAL_CONTROL_MSB                                 15
#define MWV207REG_PE_HIERARCHICAL_CONTROL_LSB                                  0
#define MWV207REG_PE_HIERARCHICAL_CONTROL_BLK                                  0
#define MWV207REG_PE_HIERARCHICAL_CONTROL_Count                                1
#define MWV207REG_PE_HIERARCHICAL_CONTROL_FieldMask                   0x00000F0F
#define MWV207REG_PE_HIERARCHICAL_CONTROL_ReadMask                    0x00000F0F
#define MWV207REG_PE_HIERARCHICAL_CONTROL_WriteMask                   0x00000F0F
#define MWV207REG_PE_HIERARCHICAL_CONTROL_ResetValue                  0x00000000

#define MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT                             3:0
#define MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_End                           3
#define MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_Start                         0
#define MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_Type                        U04

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_OFF                       0x0

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_D16                   0x1

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_D24_LOW               0x2

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_D24_HIGH              0x3

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_D24                   0x4

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MAX_D16                   0x5

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MAX_D24_LOW               0x6

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MAX_D24_HIGH              0x7

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MAX_D24                   0x8

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_MAX_D16               0x9

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_MAX_D24_LOW           0xA

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_MAX_D24_HIGH          0xB

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_FORMAT_MIN_MAX_D24               0xC


#define MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT                         11:8
#define MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_End                       11
#define MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_Start                      8
#define MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_Type                     U04

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_OFF                    0x0

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_D16                0x1

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_D24_LOW            0x2

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_D24_HIGH           0x3

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_D24                0x4

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MAX_D16                0x5

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MAX_D24_LOW            0x6

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MAX_D24_HIGH           0x7

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MAX_D24                0x8

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_MAX_D16            0x9

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_MAX_D24_LOW        0xA

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_MAX_D24_HIGH       0xB

#define   MWV207REG_PE_HIERARCHICAL_CONTROL_RA_FORMAT_MIN_MAX_D24            0xC




#define mwv207regPEHierarchicalAddressRegAddrs                            0x0516
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_Address                        0x01458
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_MSB                                 15
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_LSB                                  0
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_BLK                                  0
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_Count                                1
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_FieldMask                   0xFFFFFFFF
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_ReadMask                    0xFFFFFFFC
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_WriteMask                   0xFFFFFFFC
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_ResetValue                  0x00000000

#define MWV207REG_PE_HIERARCHICAL_ADDRESS_TYPE                             31:31
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_TYPE_End                            31
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_TYPE_Start                          31
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_TYPE_Type                          U01
#define   MWV207REG_PE_HIERARCHICAL_ADDRESS_TYPE_SYSTEM                      0x0
#define   MWV207REG_PE_HIERARCHICAL_ADDRESS_TYPE_VIRTUAL_SYSTEM              0x1

#define MWV207REG_PE_HIERARCHICAL_ADDRESS_ADDRESS                           30:0
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_ADDRESS_End                         30
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_ADDRESS_Start                        0
#define MWV207REG_PE_HIERARCHICAL_ADDRESS_ADDRESS_Type                       U31




#define mwv207regPEVaaControlRegAddrs                                     0x0517
#define MWV207REG_PE_VAA_CONTROL_Address                                 0x0145C
#define MWV207REG_PE_VAA_CONTROL_MSB                                          15
#define MWV207REG_PE_VAA_CONTROL_LSB                                           0
#define MWV207REG_PE_VAA_CONTROL_BLK                                           0
#define MWV207REG_PE_VAA_CONTROL_Count                                         1
#define MWV207REG_PE_VAA_CONTROL_FieldMask                            0x0000FFFF
#define MWV207REG_PE_VAA_CONTROL_ReadMask                             0x0000FFFF
#define MWV207REG_PE_VAA_CONTROL_WriteMask                            0x0000FFFF
#define MWV207REG_PE_VAA_CONTROL_ResetValue                           0x00000010


#define MWV207REG_PE_VAA_CONTROL_THRESHOLD                                  15:0
#define MWV207REG_PE_VAA_CONTROL_THRESHOLD_End                                15
#define MWV207REG_PE_VAA_CONTROL_THRESHOLD_Start                               0
#define MWV207REG_PE_VAA_CONTROL_THRESHOLD_Type                              U16




#define mwv207regPEColorBaseAddressRegAddrs                               0x0518
#define MWV207REG_PE_COLOR_BASE_ADDRESS_Address                          0x01460
#define MWV207REG_PE_COLOR_BASE_ADDRESS_MSB                                   15
#define MWV207REG_PE_COLOR_BASE_ADDRESS_LSB                                    3
#define MWV207REG_PE_COLOR_BASE_ADDRESS_BLK                                    3
#define MWV207REG_PE_COLOR_BASE_ADDRESS_Count                                  8
#define MWV207REG_PE_COLOR_BASE_ADDRESS_FieldMask                     0xFFFFFFFF
#define MWV207REG_PE_COLOR_BASE_ADDRESS_ReadMask                      0xFFFFFFFC
#define MWV207REG_PE_COLOR_BASE_ADDRESS_WriteMask                     0xFFFFFFFC
#define MWV207REG_PE_COLOR_BASE_ADDRESS_ResetValue                    0x00000000

#define MWV207REG_PE_COLOR_BASE_ADDRESS_TYPE                               31:31
#define MWV207REG_PE_COLOR_BASE_ADDRESS_TYPE_End                              31
#define MWV207REG_PE_COLOR_BASE_ADDRESS_TYPE_Start                            31
#define MWV207REG_PE_COLOR_BASE_ADDRESS_TYPE_Type                            U01
#define   MWV207REG_PE_COLOR_BASE_ADDRESS_TYPE_SYSTEM                        0x0
#define   MWV207REG_PE_COLOR_BASE_ADDRESS_TYPE_VIRTUAL_SYSTEM                0x1

#define MWV207REG_PE_COLOR_BASE_ADDRESS_ADDRESS                             30:0
#define MWV207REG_PE_COLOR_BASE_ADDRESS_ADDRESS_End                           30
#define MWV207REG_PE_COLOR_BASE_ADDRESS_ADDRESS_Start                          0
#define MWV207REG_PE_COLOR_BASE_ADDRESS_ADDRESS_Type                         U31




#define mwv207regPEDepthBaseAddressRegAddrs                               0x0520
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_Address                          0x01480
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_MSB                                   15
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_LSB                                    3
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_BLK                                    3
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_Count                                  8
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_FieldMask                     0xFFFFFFFF
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_ReadMask                      0xFFFFFFFC
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_WriteMask                     0xFFFFFFFC
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_ResetValue                    0x00000000

#define MWV207REG_PE_DEPTH_BASE_ADDRESS_TYPE                               31:31
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_TYPE_End                              31
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_TYPE_Start                            31
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_TYPE_Type                            U01
#define   MWV207REG_PE_DEPTH_BASE_ADDRESS_TYPE_SYSTEM                        0x0
#define   MWV207REG_PE_DEPTH_BASE_ADDRESS_TYPE_VIRTUAL_SYSTEM                0x1

#define MWV207REG_PE_DEPTH_BASE_ADDRESS_ADDRESS                             30:0
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_ADDRESS_End                           30
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_ADDRESS_Start                          0
#define MWV207REG_PE_DEPTH_BASE_ADDRESS_ADDRESS_Type                         U31




#define mwv207regPEExtraReferenceRegAddrs                                 0x0528
#define MWV207REG_PE_EXTRA_REFERENCE_Address                             0x014A0
#define MWV207REG_PE_EXTRA_REFERENCE_MSB                                      15
#define MWV207REG_PE_EXTRA_REFERENCE_LSB                                       0
#define MWV207REG_PE_EXTRA_REFERENCE_BLK                                       0
#define MWV207REG_PE_EXTRA_REFERENCE_Count                                     1
#define MWV207REG_PE_EXTRA_REFERENCE_FieldMask                        0xFFFF03FF
#define MWV207REG_PE_EXTRA_REFERENCE_ReadMask                         0xFFFF03FF
#define MWV207REG_PE_EXTRA_REFERENCE_WriteMask                        0xFFFF03FF
#define MWV207REG_PE_EXTRA_REFERENCE_ResetValue                       0x00000000


#define MWV207REG_PE_EXTRA_REFERENCE_BACKSIDE_REFERENCE                      7:0
#define MWV207REG_PE_EXTRA_REFERENCE_BACKSIDE_REFERENCE_End                    7
#define MWV207REG_PE_EXTRA_REFERENCE_BACKSIDE_REFERENCE_Start                  0
#define MWV207REG_PE_EXTRA_REFERENCE_BACKSIDE_REFERENCE_Type                 U08


#define MWV207REG_PE_EXTRA_REFERENCE_MASK_BACKSIDE_REFERENCE                 8:8
#define MWV207REG_PE_EXTRA_REFERENCE_MASK_BACKSIDE_REFERENCE_End               8
#define MWV207REG_PE_EXTRA_REFERENCE_MASK_BACKSIDE_REFERENCE_Start             8
#define MWV207REG_PE_EXTRA_REFERENCE_MASK_BACKSIDE_REFERENCE_Type            U01
#define   MWV207REG_PE_EXTRA_REFERENCE_MASK_BACKSIDE_REFERENCE_ENABLED       0x0
#define   MWV207REG_PE_EXTRA_REFERENCE_MASK_BACKSIDE_REFERENCE_MASKED        0x1


#define MWV207REG_PE_EXTRA_REFERENCE_MASK_ALPHA_REFERENCE                    9:9
#define MWV207REG_PE_EXTRA_REFERENCE_MASK_ALPHA_REFERENCE_End                  9
#define MWV207REG_PE_EXTRA_REFERENCE_MASK_ALPHA_REFERENCE_Start                9
#define MWV207REG_PE_EXTRA_REFERENCE_MASK_ALPHA_REFERENCE_Type               U01
#define   MWV207REG_PE_EXTRA_REFERENCE_MASK_ALPHA_REFERENCE_ENABLED          0x0
#define   MWV207REG_PE_EXTRA_REFERENCE_MASK_ALPHA_REFERENCE_MASKED           0x1


#define MWV207REG_PE_EXTRA_REFERENCE_ALPHA_REFERENCE                       31:16
#define MWV207REG_PE_EXTRA_REFERENCE_ALPHA_REFERENCE_End                      31
#define MWV207REG_PE_EXTRA_REFERENCE_ALPHA_REFERENCE_Start                    16
#define MWV207REG_PE_EXTRA_REFERENCE_ALPHA_REFERENCE_Type                    U16



#define mwv207regPEDitherLowRegAddrs                                      0x052A
#define MWV207REG_PE_DITHER_LOW_Address                                  0x014A8
#define MWV207REG_PE_DITHER_LOW_MSB                                           15
#define MWV207REG_PE_DITHER_LOW_LSB                                            0
#define MWV207REG_PE_DITHER_LOW_BLK                                            0
#define MWV207REG_PE_DITHER_LOW_Count                                          1
#define MWV207REG_PE_DITHER_LOW_FieldMask                             0xFFFFFFFF
#define MWV207REG_PE_DITHER_LOW_ReadMask                              0xFFFFFFFF
#define MWV207REG_PE_DITHER_LOW_WriteMask                             0xFFFFFFFF
#define MWV207REG_PE_DITHER_LOW_ResetValue                            0xFFFFFFFF


#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y0                                  3:0
#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y0_End                                3
#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y0_Start                              0
#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y0_Type                             U04


#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y0                                  7:4
#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y0_End                                7
#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y0_Start                              4
#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y0_Type                             U04


#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y0                                 11:8
#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y0_End                               11
#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y0_Start                              8
#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y0_Type                             U04


#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y0                                15:12
#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y0_End                               15
#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y0_Start                             12
#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y0_Type                             U04


#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y1                                19:16
#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y1_End                               19
#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y1_Start                             16
#define MWV207REG_PE_DITHER_LOW_PIXEL_X0_Y1_Type                             U04


#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y1                                23:20
#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y1_End                               23
#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y1_Start                             20
#define MWV207REG_PE_DITHER_LOW_PIXEL_X1_Y1_Type                             U04


#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y1                                27:24
#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y1_End                               27
#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y1_Start                             24
#define MWV207REG_PE_DITHER_LOW_PIXEL_X2_Y1_Type                             U04


#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y1                                31:28
#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y1_End                               31
#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y1_Start                             28
#define MWV207REG_PE_DITHER_LOW_PIXEL_X3_Y1_Type                             U04

#define mwv207regPEDitherHighRegAddrs                                     0x052B
#define MWV207REG_PE_DITHER_HIGH_Address                                 0x014AC
#define MWV207REG_PE_DITHER_HIGH_MSB                                          15
#define MWV207REG_PE_DITHER_HIGH_LSB                                           0
#define MWV207REG_PE_DITHER_LOW_HIGH_BLK                                       0
#define MWV207REG_PE_DITHER_HIGH_Count                                         1
#define MWV207REG_PE_DITHER_HIGH_FieldMask                            0xFFFFFFFF
#define MWV207REG_PE_DITHER_HIGH_ReadMask                             0xFFFFFFFF
#define MWV207REG_PE_DITHER_HIGH_WriteMask                            0xFFFFFFFF
#define MWV207REG_PE_DITHER_HIGH_ResetValue                           0xFFFFFFFF


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y2                                 3:0
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y2_End                               3
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y2_Start                             0
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y2_Type                            U04


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y2                                 7:4
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y2_End                               7
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y2_Start                             4
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y2_Type                            U04


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y2                                11:8
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y2_End                              11
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y2_Start                             8
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y2_Type                            U04


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y2                               15:12
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y2_End                              15
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y2_Start                            12
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y2_Type                            U04


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y3                               19:16
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y3_End                              19
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y3_Start                            16
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X0_Y3_Type                            U04


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y3                               23:20
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y3_End                              23
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y3_Start                            20
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X1_Y3_Type                            U04


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y3                               27:24
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y3_End                              27
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y3_Start                            24
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X2_Y3_Type                            U04


#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y3                               31:28
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y3_End                              31
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y3_Start                            28
#define MWV207REG_PE_DITHER_HIGH_PIXEL_X3_Y3_Type                            U04

#define mwv207regPEBlendFactorLowRegAddrs                                 0x052C
#define MWV207REG_PE_BLEND_FACTOR_LOW_Address                            0x014B0
#define MWV207REG_PE_BLEND_FACTOR_LOW_MSB                                     15
#define MWV207REG_PE_BLEND_FACTOR_LOW_LSB                                      0
#define MWV207REG_PE_BLEND_FACTOR_LOW_BLK                                      0
#define MWV207REG_PE_BLEND_FACTOR_LOW_Count                                    1
#define MWV207REG_PE_BLEND_FACTOR_LOW_FieldMask                       0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_LOW_ReadMask                        0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_LOW_WriteMask                       0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_LOW_ResetValue                      0x00000000


#define MWV207REG_PE_BLEND_FACTOR_LOW_RED                                   15:0
#define MWV207REG_PE_BLEND_FACTOR_LOW_RED_End                                 15
#define MWV207REG_PE_BLEND_FACTOR_LOW_RED_Start                                0
#define MWV207REG_PE_BLEND_FACTOR_LOW_RED_Type                               U16


#define MWV207REG_PE_BLEND_FACTOR_LOW_GREEN                                31:16
#define MWV207REG_PE_BLEND_FACTOR_LOW_GREEN_End                               31
#define MWV207REG_PE_BLEND_FACTOR_LOW_GREEN_Start                             16
#define MWV207REG_PE_BLEND_FACTOR_LOW_GREEN_Type                             U16

#define mwv207regPEBlendFactorHighRegAddrs                                0x052D
#define MWV207REG_PE_BLEND_FACTOR_HIGH_Address                           0x014B4
#define MWV207REG_PE_BLEND_FACTOR_HIGH_MSB                                    15
#define MWV207REG_PE_BLEND_FACTOR_HIGH_LSB                                     0
#define MWV207REG_PE_BLEND_FACTOR_LOW_HIGH_BLK                                 0
#define MWV207REG_PE_BLEND_FACTOR_HIGH_Count                                   1
#define MWV207REG_PE_BLEND_FACTOR_HIGH_FieldMask                      0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_HIGH_ReadMask                       0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_HIGH_WriteMask                      0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_HIGH_ResetValue                     0x00000000


#define MWV207REG_PE_BLEND_FACTOR_HIGH_BLUE                                 15:0
#define MWV207REG_PE_BLEND_FACTOR_HIGH_BLUE_End                               15
#define MWV207REG_PE_BLEND_FACTOR_HIGH_BLUE_Start                              0
#define MWV207REG_PE_BLEND_FACTOR_HIGH_BLUE_Type                             U16


#define MWV207REG_PE_BLEND_FACTOR_HIGH_ALPHA                               31:16
#define MWV207REG_PE_BLEND_FACTOR_HIGH_ALPHA_End                              31
#define MWV207REG_PE_BLEND_FACTOR_HIGH_ALPHA_Start                            16
#define MWV207REG_PE_BLEND_FACTOR_HIGH_ALPHA_Type                            U16




#define mwv207regPEConfigRegAddrs                                         0x0529
#define MWV207REG_PE_CONFIG_Address                                      0x014A4
#define MWV207REG_PE_CONFIG_MSB                                               15
#define MWV207REG_PE_CONFIG_LSB                                                0
#define MWV207REG_PE_CONFIG_BLK                                                0
#define MWV207REG_PE_CONFIG_Count                                              1
#define MWV207REG_PE_CONFIG_FieldMask                                 0xFFBFFFFF
#define MWV207REG_PE_CONFIG_ReadMask                                  0xFFBFFFFF
#define MWV207REG_PE_CONFIG_WriteMask                                 0xFFBFFFFF
#define MWV207REG_PE_CONFIG_ResetValue                                0x000E400C


#define MWV207REG_PE_CONFIG_LOGIC_OP                                         3:0
#define MWV207REG_PE_CONFIG_LOGIC_OP_End                                       3
#define MWV207REG_PE_CONFIG_LOGIC_OP_Start                                     0
#define MWV207REG_PE_CONFIG_LOGIC_OP_Type                                    U04

#define   MWV207REG_PE_CONFIG_LOGIC_OP_CLEAR                                 0x0

#define   MWV207REG_PE_CONFIG_LOGIC_OP_NOR                                   0x1

#define   MWV207REG_PE_CONFIG_LOGIC_OP_AND_INVERTED                          0x2

#define   MWV207REG_PE_CONFIG_LOGIC_OP_COPY_INVERTED                         0x3

#define   MWV207REG_PE_CONFIG_LOGIC_OP_AND_REVERSE                           0x4

#define   MWV207REG_PE_CONFIG_LOGIC_OP_INVERT                                0x5

#define   MWV207REG_PE_CONFIG_LOGIC_OP_XOR                                   0x6

#define   MWV207REG_PE_CONFIG_LOGIC_OP_NAND                                  0x7

#define   MWV207REG_PE_CONFIG_LOGIC_OP_AND                                   0x8

#define   MWV207REG_PE_CONFIG_LOGIC_OP_EQUIV                                 0x9

#define   MWV207REG_PE_CONFIG_LOGIC_OP_NOOP                                  0xA

#define   MWV207REG_PE_CONFIG_LOGIC_OP_OR_INVERTED                           0xB

#define   MWV207REG_PE_CONFIG_LOGIC_OP_COPY                                  0xC

#define   MWV207REG_PE_CONFIG_LOGIC_OP_OR_REVERSE                            0xD

#define   MWV207REG_PE_CONFIG_LOGIC_OP_OR                                    0xE

#define   MWV207REG_PE_CONFIG_LOGIC_OP_SET                                   0xF


#define MWV207REG_PE_CONFIG_MASK_LOGIC_OP                                    4:4
#define MWV207REG_PE_CONFIG_MASK_LOGIC_OP_End                                  4
#define MWV207REG_PE_CONFIG_MASK_LOGIC_OP_Start                                4
#define MWV207REG_PE_CONFIG_MASK_LOGIC_OP_Type                               U01
#define   MWV207REG_PE_CONFIG_MASK_LOGIC_OP_ENABLED                          0x0
#define   MWV207REG_PE_CONFIG_MASK_LOGIC_OP_MASKED                           0x1


#define MWV207REG_PE_CONFIG_CONVERSION_CONTROL                               6:5
#define MWV207REG_PE_CONFIG_CONVERSION_CONTROL_End                             6
#define MWV207REG_PE_CONFIG_CONVERSION_CONTROL_Start                           5
#define MWV207REG_PE_CONFIG_CONVERSION_CONTROL_Type                          U02
#define   MWV207REG_PE_CONFIG_CONVERSION_CONTROL_EXPAND                      0x0
#define   MWV207REG_PE_CONFIG_CONVERSION_CONTROL_ADD_RGB111                  0x1
#define   MWV207REG_PE_CONFIG_CONVERSION_CONTROL_ADD_RGB212                  0x2
#define   MWV207REG_PE_CONFIG_CONVERSION_CONTROL_ADD_RGB737                  0x3


#define MWV207REG_PE_CONFIG_MASK_CONVERSION_CONTROL                        10:10
#define MWV207REG_PE_CONFIG_MASK_CONVERSION_CONTROL_End                       10
#define MWV207REG_PE_CONFIG_MASK_CONVERSION_CONTROL_Start                     10
#define MWV207REG_PE_CONFIG_MASK_CONVERSION_CONTROL_Type                     U01
#define   MWV207REG_PE_CONFIG_MASK_CONVERSION_CONTROL_ENABLED                0x0
#define   MWV207REG_PE_CONFIG_MASK_CONVERSION_CONTROL_MASKED                 0x1


#define MWV207REG_PE_CONFIG_MASK_COLOR_ADDRESS_MODE                          7:7
#define MWV207REG_PE_CONFIG_MASK_COLOR_ADDRESS_MODE_End                        7
#define MWV207REG_PE_CONFIG_MASK_COLOR_ADDRESS_MODE_Start                      7
#define MWV207REG_PE_CONFIG_MASK_COLOR_ADDRESS_MODE_Type                     U01
#define   MWV207REG_PE_CONFIG_MASK_COLOR_ADDRESS_MODE_ENABLED                0x0
#define   MWV207REG_PE_CONFIG_MASK_COLOR_ADDRESS_MODE_MASKED                 0x1


#define MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE                               9:8
#define MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE_End                             9
#define MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE_Start                           8
#define MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE_Type                          U02

#define   MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE_TILED                       0x0

#define   MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE_LINEAR                      0x1

#define   MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE_SINGLE_BUFFER4X4            0x2

#define   MWV207REG_PE_CONFIG_COLOR_ADDRESS_MODE_SINGLE_BUFFER8X4            0x3


#define MWV207REG_PE_CONFIG_MASK_SWIZZLE                                   11:11
#define MWV207REG_PE_CONFIG_MASK_SWIZZLE_End                                  11
#define MWV207REG_PE_CONFIG_MASK_SWIZZLE_Start                                11
#define MWV207REG_PE_CONFIG_MASK_SWIZZLE_Type                                U01
#define   MWV207REG_PE_CONFIG_MASK_SWIZZLE_ENABLED                           0x0
#define   MWV207REG_PE_CONFIG_MASK_SWIZZLE_MASKED                            0x1


#define MWV207REG_PE_CONFIG_SWIZZLE_R                                      13:12
#define MWV207REG_PE_CONFIG_SWIZZLE_R_End                                     13
#define MWV207REG_PE_CONFIG_SWIZZLE_R_Start                                   12
#define MWV207REG_PE_CONFIG_SWIZZLE_R_Type                                   U02
#define   MWV207REG_PE_CONFIG_SWIZZLE_R_RED                                  0x0
#define   MWV207REG_PE_CONFIG_SWIZZLE_R_GREEN                                0x1
#define   MWV207REG_PE_CONFIG_SWIZZLE_R_BLUE                                 0x2
#define   MWV207REG_PE_CONFIG_SWIZZLE_R_ALPHA                                0x3


#define MWV207REG_PE_CONFIG_SWIZZLE_G                                      15:14
#define MWV207REG_PE_CONFIG_SWIZZLE_G_End                                     15
#define MWV207REG_PE_CONFIG_SWIZZLE_G_Start                                   14
#define MWV207REG_PE_CONFIG_SWIZZLE_G_Type                                   U02
#define   MWV207REG_PE_CONFIG_SWIZZLE_G_RED                                  0x0
#define   MWV207REG_PE_CONFIG_SWIZZLE_G_GREEN                                0x1
#define   MWV207REG_PE_CONFIG_SWIZZLE_G_BLUE                                 0x2
#define   MWV207REG_PE_CONFIG_SWIZZLE_G_ALPHA                                0x3


#define MWV207REG_PE_CONFIG_SWIZZLE_B                                      17:16
#define MWV207REG_PE_CONFIG_SWIZZLE_B_End                                     17
#define MWV207REG_PE_CONFIG_SWIZZLE_B_Start                                   16
#define MWV207REG_PE_CONFIG_SWIZZLE_B_Type                                   U02
#define   MWV207REG_PE_CONFIG_SWIZZLE_B_RED                                  0x0
#define   MWV207REG_PE_CONFIG_SWIZZLE_B_GREEN                                0x1
#define   MWV207REG_PE_CONFIG_SWIZZLE_B_BLUE                                 0x2
#define   MWV207REG_PE_CONFIG_SWIZZLE_B_ALPHA                                0x3


#define MWV207REG_PE_CONFIG_SWIZZLE_A                                      19:18
#define MWV207REG_PE_CONFIG_SWIZZLE_A_End                                     19
#define MWV207REG_PE_CONFIG_SWIZZLE_A_Start                                   18
#define MWV207REG_PE_CONFIG_SWIZZLE_A_Type                                   U02
#define   MWV207REG_PE_CONFIG_SWIZZLE_A_RED                                  0x0
#define   MWV207REG_PE_CONFIG_SWIZZLE_A_GREEN                                0x1
#define   MWV207REG_PE_CONFIG_SWIZZLE_A_BLUE                                 0x2
#define   MWV207REG_PE_CONFIG_SWIZZLE_A_ALPHA                                0x3


#define MWV207REG_PE_CONFIG_STENCIL_FORMAT                                 21:20
#define MWV207REG_PE_CONFIG_STENCIL_FORMAT_End                                21
#define MWV207REG_PE_CONFIG_STENCIL_FORMAT_Start                              20
#define MWV207REG_PE_CONFIG_STENCIL_FORMAT_Type                              U02

#define   MWV207REG_PE_CONFIG_STENCIL_FORMAT_D24S8                           0x0

#define   MWV207REG_PE_CONFIG_STENCIL_FORMAT_S8                              0x1

#define   MWV207REG_PE_CONFIG_STENCIL_FORMAT_S1                              0x2

#define   MWV207REG_PE_CONFIG_STENCIL_FORMAT_D32FS8                          0x3


#define MWV207REG_PE_CONFIG_MASK_STENCIL_FORMAT                            23:23
#define MWV207REG_PE_CONFIG_MASK_STENCIL_FORMAT_End                           23
#define MWV207REG_PE_CONFIG_MASK_STENCIL_FORMAT_Start                         23
#define MWV207REG_PE_CONFIG_MASK_STENCIL_FORMAT_Type                         U01
#define   MWV207REG_PE_CONFIG_MASK_STENCIL_FORMAT_ENABLED                    0x0
#define   MWV207REG_PE_CONFIG_MASK_STENCIL_FORMAT_MASKED                     0x1


#define MWV207REG_PE_CONFIG_COLOR_CACHE_CONTROL                            24:24
#define MWV207REG_PE_CONFIG_COLOR_CACHE_CONTROL_End                           24
#define MWV207REG_PE_CONFIG_COLOR_CACHE_CONTROL_Start                         24
#define MWV207REG_PE_CONFIG_COLOR_CACHE_CONTROL_Type                         U01

#define   MWV207REG_PE_CONFIG_COLOR_CACHE_CONTROL__16X64                     0x0

#define   MWV207REG_PE_CONFIG_COLOR_CACHE_CONTROL__8X256                     0x1


#define MWV207REG_PE_CONFIG_MASK_COLOR_CACHE_CONTROL                       25:25
#define MWV207REG_PE_CONFIG_MASK_COLOR_CACHE_CONTROL_End                      25
#define MWV207REG_PE_CONFIG_MASK_COLOR_CACHE_CONTROL_Start                    25
#define MWV207REG_PE_CONFIG_MASK_COLOR_CACHE_CONTROL_Type                    U01
#define   MWV207REG_PE_CONFIG_MASK_COLOR_CACHE_CONTROL_ENABLED               0x0
#define   MWV207REG_PE_CONFIG_MASK_COLOR_CACHE_CONTROL_MASKED                0x1


#define MWV207REG_PE_CONFIG_DEPTH_CACHE_CONTROL                            26:26
#define MWV207REG_PE_CONFIG_DEPTH_CACHE_CONTROL_End                           26
#define MWV207REG_PE_CONFIG_DEPTH_CACHE_CONTROL_Start                         26
#define MWV207REG_PE_CONFIG_DEPTH_CACHE_CONTROL_Type                         U01

#define   MWV207REG_PE_CONFIG_DEPTH_CACHE_CONTROL__16X64                     0x0

#define   MWV207REG_PE_CONFIG_DEPTH_CACHE_CONTROL__8X256                     0x1


#define MWV207REG_PE_CONFIG_MASK_DEPTH_CACHE_CONTROL                       27:27
#define MWV207REG_PE_CONFIG_MASK_DEPTH_CACHE_CONTROL_End                      27
#define MWV207REG_PE_CONFIG_MASK_DEPTH_CACHE_CONTROL_Start                    27
#define MWV207REG_PE_CONFIG_MASK_DEPTH_CACHE_CONTROL_Type                    U01
#define   MWV207REG_PE_CONFIG_MASK_DEPTH_CACHE_CONTROL_ENABLED               0x0
#define   MWV207REG_PE_CONFIG_MASK_DEPTH_CACHE_CONTROL_MASKED                0x1

#define MWV207REG_PE_CONFIG_EARLY_ALPHA_KILL                               28:28
#define MWV207REG_PE_CONFIG_EARLY_ALPHA_KILL_End                              28
#define MWV207REG_PE_CONFIG_EARLY_ALPHA_KILL_Start                            28
#define MWV207REG_PE_CONFIG_EARLY_ALPHA_KILL_Type                            U01
#define   MWV207REG_PE_CONFIG_EARLY_ALPHA_KILL_DISABLE                       0x0
#define   MWV207REG_PE_CONFIG_EARLY_ALPHA_KILL_ENABLE                        0x1


#define MWV207REG_PE_CONFIG_MASK_EARLY_ALPHA_KILL                          29:29
#define MWV207REG_PE_CONFIG_MASK_EARLY_ALPHA_KILL_End                         29
#define MWV207REG_PE_CONFIG_MASK_EARLY_ALPHA_KILL_Start                       29
#define MWV207REG_PE_CONFIG_MASK_EARLY_ALPHA_KILL_Type                       U01
#define   MWV207REG_PE_CONFIG_MASK_EARLY_ALPHA_KILL_ENABLED                  0x0
#define   MWV207REG_PE_CONFIG_MASK_EARLY_ALPHA_KILL_MASKED                   0x1


#define MWV207REG_PE_CONFIG_MASK_GAMMA_CORRECTION                          30:30
#define MWV207REG_PE_CONFIG_MASK_GAMMA_CORRECTION_End                         30
#define MWV207REG_PE_CONFIG_MASK_GAMMA_CORRECTION_Start                       30
#define MWV207REG_PE_CONFIG_MASK_GAMMA_CORRECTION_Type                       U01
#define   MWV207REG_PE_CONFIG_MASK_GAMMA_CORRECTION_ENABLED                  0x0
#define   MWV207REG_PE_CONFIG_MASK_GAMMA_CORRECTION_MASKED                   0x1


#define MWV207REG_PE_CONFIG_GAMMA_CORRECTION                               31:31
#define MWV207REG_PE_CONFIG_GAMMA_CORRECTION_End                              31
#define MWV207REG_PE_CONFIG_GAMMA_CORRECTION_Start                            31
#define MWV207REG_PE_CONFIG_GAMMA_CORRECTION_Type                            U01
#define   MWV207REG_PE_CONFIG_GAMMA_CORRECTION_LINEAR                        0x0
#define   MWV207REG_PE_CONFIG_GAMMA_CORRECTION_S_RGB                         0x1




#define mwv207regPEBackfaceStencilRegAddrs                                0x052E
#define MWV207REG_PE_BACKFACE_STENCIL_Address                            0x014B8
#define MWV207REG_PE_BACKFACE_STENCIL_MSB                                     15
#define MWV207REG_PE_BACKFACE_STENCIL_LSB                                      0
#define MWV207REG_PE_BACKFACE_STENCIL_BLK                                      0
#define MWV207REG_PE_BACKFACE_STENCIL_Count                                    1
#define MWV207REG_PE_BACKFACE_STENCIL_FieldMask                       0x0000FFFF
#define MWV207REG_PE_BACKFACE_STENCIL_ReadMask                        0x0000FFFF
#define MWV207REG_PE_BACKFACE_STENCIL_WriteMask                       0x0000FFFF
#define MWV207REG_PE_BACKFACE_STENCIL_ResetValue                      0x00000000


#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_READ_MASK                     7:0
#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_READ_MASK_End                   7
#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_READ_MASK_Start                 0
#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_READ_MASK_Type                U08


#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_WRITE_MASK                   15:8
#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_WRITE_MASK_End                 15
#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_WRITE_MASK_Start                8
#define MWV207REG_PE_BACKFACE_STENCIL_BACKFACE_WRITE_MASK_Type               U08




#define mwv207regPEConfigExRegAddrs                                       0x052F
#define MWV207REG_PE_CONFIG_EX_Address                                   0x014BC
#define MWV207REG_PE_CONFIG_EX_MSB                                            15
#define MWV207REG_PE_CONFIG_EX_LSB                                             0
#define MWV207REG_PE_CONFIG_EX_BLK                                             0
#define MWV207REG_PE_CONFIG_EX_Count                                           1
#define MWV207REG_PE_CONFIG_EX_FieldMask                              0x0509FFF9
#define MWV207REG_PE_CONFIG_EX_ReadMask                               0x0509FFF9
#define MWV207REG_PE_CONFIG_EX_WriteMask                              0x0509FFF9
#define MWV207REG_PE_CONFIG_EX_ResetValue                             0x00000000


#define MWV207REG_PE_CONFIG_EX_PIPE_ENABLE                                   0:0
#define MWV207REG_PE_CONFIG_EX_PIPE_ENABLE_End                                 0
#define MWV207REG_PE_CONFIG_EX_PIPE_ENABLE_Start                               0
#define MWV207REG_PE_CONFIG_EX_PIPE_ENABLE_Type                              U01

#define   MWV207REG_PE_CONFIG_EX_PIPE_ENABLE_BOTH                            0x0

#define   MWV207REG_PE_CONFIG_EX_PIPE_ENABLE_SINGLE                          0x1

#define MWV207REG_PE_CONFIG_EX_BUG1293_FIX_DISABLE                           3:3
#define MWV207REG_PE_CONFIG_EX_BUG1293_FIX_DISABLE_End                         3
#define MWV207REG_PE_CONFIG_EX_BUG1293_FIX_DISABLE_Start                       3
#define MWV207REG_PE_CONFIG_EX_BUG1293_FIX_DISABLE_Type                      U01

#define   MWV207REG_PE_CONFIG_EX_BUG1293_FIX_DISABLE_AUTOMATIC               0x0
#define   MWV207REG_PE_CONFIG_EX_BUG1293_FIX_DISABLE_DISABLE                 0x1

#define MWV207REG_PE_CONFIG_EX_CLOCK_GATING                                  4:4
#define MWV207REG_PE_CONFIG_EX_CLOCK_GATING_End                                4
#define MWV207REG_PE_CONFIG_EX_CLOCK_GATING_Start                              4
#define MWV207REG_PE_CONFIG_EX_CLOCK_GATING_Type                             U01
#define   MWV207REG_PE_CONFIG_EX_CLOCK_GATING_AUTOMATIC                      0x0

#define   MWV207REG_PE_CONFIG_EX_CLOCK_GATING_DISABLE                        0x1


#define MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL                          6:5
#define MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL_End                        6
#define MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL_Start                      5
#define MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL_Type                     U02
#define   MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL_NO_SWAP                0x0
#define   MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL_SWAP_WORD              0x1
#define   MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL_SWAP_DWORD             0x2
#define   MWV207REG_PE_CONFIG_EX_COLOR_ENDIAN_CONTROL_SWAP_DDWORD            0x3


#define MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL                          8:7
#define MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL_End                        8
#define MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL_Start                      7
#define MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL_Type                     U02
#define   MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL_NO_SWAP                0x0
#define   MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL_SWAP_WORD              0x1
#define   MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL_SWAP_DWORD             0x2
#define   MWV207REG_PE_CONFIG_EX_DEPTH_ENDIAN_CONTROL_SWAP_DDWORD            0x3


#define MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL                         10:9
#define MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_End                       10
#define MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_Start                      9
#define MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_Type                     U02
#define   MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_NO_SWAP                0x0
#define   MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_SWAP_WORD              0x1
#define   MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_SWAP_DWORD             0x2
#define   MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_SWAP_DDWORD            0x3


#define MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL                           12:11
#define MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL_End                          12
#define MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL_Start                        11
#define MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL_Type                        U02
#define   MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL_NO_SWAP                   0x0
#define   MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL_SWAP_WORD                 0x1
#define   MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL_SWAP_DWORD                0x2
#define   MWV207REG_PE_CONFIG_EX_OQ_ENDIAN_CONTROL_SWAP_DDWORD               0x3


#define MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL                 14:13
#define MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL_End                14
#define MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL_Start              13
#define MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL_Type              U02
#define   MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL_NO_SWAP         0x0
#define   MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL_SWAP_WORD       0x1
#define   MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL_SWAP_DWORD      0x2
#define   MWV207REG_PE_CONFIG_EX_PERF_COUNTER_ENDIAN_CONTROL_SWAP_DDWORD     0x3


#define MWV207REG_PE_CONFIG_EX_COLOR_VMSAA                                 15:15
#define MWV207REG_PE_CONFIG_EX_COLOR_VMSAA_End                                15
#define MWV207REG_PE_CONFIG_EX_COLOR_VMSAA_Start                              15
#define MWV207REG_PE_CONFIG_EX_COLOR_VMSAA_Type                              U01
#define   MWV207REG_PE_CONFIG_EX_COLOR_VMSAA_DISABLED                        0x0
#define   MWV207REG_PE_CONFIG_EX_COLOR_VMSAA_ENABLED                         0x1


#define MWV207REG_PE_CONFIG_EX_DEPTH_VMSAA                                 16:16
#define MWV207REG_PE_CONFIG_EX_DEPTH_VMSAA_End                                16
#define MWV207REG_PE_CONFIG_EX_DEPTH_VMSAA_Start                              16
#define MWV207REG_PE_CONFIG_EX_DEPTH_VMSAA_Type                              U01
#define   MWV207REG_PE_CONFIG_EX_DEPTH_VMSAA_DISABLED                        0x0
#define   MWV207REG_PE_CONFIG_EX_DEPTH_VMSAA_ENABLED                         0x1


#define MWV207REG_PE_CONFIG_EX_FULL_TILE_COVERAGE_DISABLE                  19:19
#define MWV207REG_PE_CONFIG_EX_FULL_TILE_COVERAGE_DISABLE_End                 19
#define MWV207REG_PE_CONFIG_EX_FULL_TILE_COVERAGE_DISABLE_Start               19
#define MWV207REG_PE_CONFIG_EX_FULL_TILE_COVERAGE_DISABLE_Type               U01
#define   MWV207REG_PE_CONFIG_EX_FULL_TILE_COVERAGE_DISABLE_DISABLED         0x0
#define   MWV207REG_PE_CONFIG_EX_FULL_TILE_COVERAGE_DISABLE_ENABLED          0x1


#define MWV207REG_PE_CONFIG_EX_COLOR_CACHE_CONTROL                         24:24
#define MWV207REG_PE_CONFIG_EX_COLOR_CACHE_CONTROL_End                        24
#define MWV207REG_PE_CONFIG_EX_COLOR_CACHE_CONTROL_Start                      24
#define MWV207REG_PE_CONFIG_EX_COLOR_CACHE_CONTROL_Type                      U01

#define   MWV207REG_PE_CONFIG_EX_COLOR_CACHE_CONTROL__128_BCACHELINE         0x0

#define   MWV207REG_PE_CONFIG_EX_COLOR_CACHE_CONTROL__256_BCACHELINE         0x1


#define MWV207REG_PE_CONFIG_EX_DEPTH_CACHE_CONTROL                         26:26
#define MWV207REG_PE_CONFIG_EX_DEPTH_CACHE_CONTROL_End                        26
#define MWV207REG_PE_CONFIG_EX_DEPTH_CACHE_CONTROL_Start                      26
#define MWV207REG_PE_CONFIG_EX_DEPTH_CACHE_CONTROL_Type                      U01

#define   MWV207REG_PE_CONFIG_EX_DEPTH_CACHE_CONTROL__128_BCACHELINE         0x0

#define   MWV207REG_PE_CONFIG_EX_DEPTH_CACHE_CONTROL__256_BCACHELINE         0x1




#define mwv207regPEAlphaConfigRegAddrs                                    0x0530
#define MWV207REG_PE_ALPHA_CONFIG_Address                                0x014C0
#define MWV207REG_PE_ALPHA_CONFIG_MSB                                         15
#define MWV207REG_PE_ALPHA_CONFIG_LSB                                          0
#define MWV207REG_PE_ALPHA_CONFIG_BLK                                          0
#define MWV207REG_PE_ALPHA_CONFIG_Count                                        1
#define MWV207REG_PE_ALPHA_CONFIG_FieldMask                           0x1DDDFFFF
#define MWV207REG_PE_ALPHA_CONFIG_ReadMask                            0x1DDDFFFF
#define MWV207REG_PE_ALPHA_CONFIG_WriteMask                           0x1DDDFFFF
#define MWV207REG_PE_ALPHA_CONFIG_ResetValue                          0x00000000


#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE                                 3:0
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_End                               3
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_Start                             0
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_Type                            U04

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_LEGACY                        0x0

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_MULTIPLY                      0x1

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_SCREEN                        0x2

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_OVERLAY                       0x3

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_DARKEN                        0x4

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_LIGHTEN                       0x5

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_HARDLIGHT                     0x6

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_DIFFERENCE                    0x7

#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_MODE_EXCLUSION                     0x8


#define MWV207REG_PE_ALPHA_CONFIG_PRE_MULTIPLIED                             4:4
#define MWV207REG_PE_ALPHA_CONFIG_PRE_MULTIPLIED_End                           4
#define MWV207REG_PE_ALPHA_CONFIG_PRE_MULTIPLIED_Start                         4
#define MWV207REG_PE_ALPHA_CONFIG_PRE_MULTIPLIED_Type                        U01

#define   MWV207REG_PE_ALPHA_CONFIG_PRE_MULTIPLIED_NORMAL                    0x0

#define   MWV207REG_PE_ALPHA_CONFIG_PRE_MULTIPLIED_PRE_MULTIPLIED            0x1


#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_NO_READ                          5:5
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_NO_READ_End                        5
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_NO_READ_Start                      5
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_NO_READ_Type                     U01
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_NO_READ_DISABLED               0x0
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_NO_READ_ENABLED                0x1


#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_NO_READ                    6:6
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_NO_READ_End                  6
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_NO_READ_Start                6
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_NO_READ_Type               U01
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_NO_READ_DISABLED         0x0
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_NO_READ_ENABLED          0x1


#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_KILL                            7:7
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_KILL_End                          7
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_KILL_Start                        7
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_KILL_Type                       U01
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_KILL_DISABLED                 0x0
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_KILL_ENABLED                  0x1


#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_KILL                      8:8
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_KILL_End                    8
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_KILL_Start                  8
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_KILL_Type                 U01
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_KILL_DISABLED           0x0
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_KILL_ENABLED            0x1


#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_KILL                             9:9
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_KILL_End                           9
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_KILL_Start                         9
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_KILL_Type                        U01
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_KILL_DISABLED                  0x0
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ONE_KILL_ENABLED                   0x1


#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_KILL                     10:10
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_KILL_End                    10
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_KILL_Start                  10
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_KILL_Type                  U01
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_KILL_DISABLED            0x0
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ONE_KILL_ENABLED             0x1


#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_NO_READ                       11:11
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_NO_READ_End                      11
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_NO_READ_Start                    11
#define MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_NO_READ_Type                    U01
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_NO_READ_DISABLED              0x0
#define   MWV207REG_PE_ALPHA_CONFIG_ALPHA_ZERO_NO_READ_ENABLED               0x1


#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_NO_READ                 12:12
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_NO_READ_End                12
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_NO_READ_Start              12
#define MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_NO_READ_Type              U01
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_NO_READ_DISABLED        0x0
#define   MWV207REG_PE_ALPHA_CONFIG_COLOR_ALPHA_ZERO_NO_READ_ENABLED         0x1


#define MWV207REG_PE_ALPHA_CONFIG_DUAL_SOURCE_BLEND_MODE                   13:13
#define MWV207REG_PE_ALPHA_CONFIG_DUAL_SOURCE_BLEND_MODE_End                  13
#define MWV207REG_PE_ALPHA_CONFIG_DUAL_SOURCE_BLEND_MODE_Start                13
#define MWV207REG_PE_ALPHA_CONFIG_DUAL_SOURCE_BLEND_MODE_Type                U01
#define   MWV207REG_PE_ALPHA_CONFIG_DUAL_SOURCE_BLEND_MODE_DISABLED          0x0
#define   MWV207REG_PE_ALPHA_CONFIG_DUAL_SOURCE_BLEND_MODE_ENABLED           0x1


#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND                                16:14
#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_End                               16
#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_Start                             14
#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_Type                             U03
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_SRC1_COLOR                     0x0
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_INV_SRC1_COLOR                 0x1
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_SRC1_ALPHA                     0x2
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_INV_SRC1_ALPHA                 0x3


#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA                          20:18
#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA_End                         20
#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA_Start                       18
#define MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA_Type                       U03
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA_SRC1_COLOR               0x0
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA_INV_SRC1_COLOR           0x1
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA_SRC1_ALPHA               0x2
#define   MWV207REG_PE_ALPHA_CONFIG_SRC_BLEND_ALPHA_INV_SRC1_ALPHA           0x3


#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND                               24:22
#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_End                              24
#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_Start                            22
#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_Type                            U03
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_SRC1_COLOR                    0x0
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_INV_SRC1_COLOR                0x1
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_SRC1_ALPHA                    0x2
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_INV_SRC1_ALPHA                0x3


#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA                         28:26
#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA_End                        28
#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA_Start                      26
#define MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA_Type                      U03
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA_SRC1_COLOR              0x0
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA_INV_SRC1_COLOR          0x1
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA_SRC1_ALPHA              0x2
#define   MWV207REG_PE_ALPHA_CONFIG_DEST_BLEND_ALPHA_INV_SRC1_ALPHA          0x3




#define mwv207regDepthBufferEndAddressRegAddrs                            0x0531
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_Address                       0x014C4
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_MSB                                15
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_LSB                                 0
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_BLK                                 0
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_Count                               1
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_FieldMask                  0xFFFFFFFF
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_ReadMask                   0xFFFFFFFF
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_WriteMask                  0xFFFFFFFF
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_ResetValue                 0x00000000

#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_ADDRESS                          31:0
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_ADDRESS_End                        31
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_ADDRESS_Start                       0
#define MWV207REG_DEPTH_BUFFER_END_ADDRESS_ADDRESS_Type                      U32

#define mwv207regPERenderTargetFormatRegAddrs                             0x0532
#define MWV207REG_PE_RENDER_TARGET_FORMAT_Address                        0x014C8
#define MWV207REG_PE_RENDER_TARGET_FORMAT_MSB                                 15
#define MWV207REG_PE_RENDER_TARGET_FORMAT_LSB                                  0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_BLK                                  0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_Count                                1
#define MWV207REG_PE_RENDER_TARGET_FORMAT_FieldMask                   0x00EEEEDF
#define MWV207REG_PE_RENDER_TARGET_FORMAT_ReadMask                    0x00EEEEDF
#define MWV207REG_PE_RENDER_TARGET_FORMAT_WriteMask                   0x00EEEEDF
#define MWV207REG_PE_RENDER_TARGET_FORMAT_ResetValue                  0x006420C0

#define MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE                          4:0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_End                        4
#define MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_Start                      0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_Type                     U05
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED5_6_5_UNORM     0x00
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED1_5_5_5_UNORM   0x01
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED4_4_4_4_UNORM   0x02
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED2_10_10_10_UNORM 0x03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED2_10_10_10_UINT 0x04
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED2_10_10_10_HDR7E3 0x05
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED2_10_10_10_HDR6E4 0x06
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED2_10_10_10_HDR5E5 0x07
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED11_10_11_HDR6E5 0x08
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_PACKED10_11_11_HDR6E5 0x09
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_INT8                  0x0A
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_INT16                 0x0B
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_INT32                 0x0C
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_UINT8                 0x0D
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_UINT16                0x0E
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_UINT32                0x0F
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_UNORM8                0x10
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_UNORM16               0x11
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_SNORM8                0x12
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_SNORM16               0x13
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_FLOAT16               0x14
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_DATA_TYPE_FLOAT32               0x15


#define MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER                   7:6
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER_End                 7
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER_Start               6
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER_Type              U02
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER_ONE_COMPONENT   0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER_TWO_COMPONENTS  0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER_THREE_COMPONENTS 0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COMPONENT_NUMBER_FOUR_COMPONENTS 0x3


#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R                   11:9
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_End                 11
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_Start                9
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_Type               U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_LSB_COMPONENT    0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_THIRD_COMPONENT  0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_MSB_COMPONENT    0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_ZERO             0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_R_ONE              0x5


#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G                  15:13
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_End                 15
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_Start               13
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_Type               U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_LSB_COMPONENT    0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_THIRD_COMPONENT  0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_MSB_COMPONENT    0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_ZERO             0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_G_ONE              0x5


#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B                  19:17
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_End                 19
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_Start               17
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_Type               U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_LSB_COMPONENT    0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_THIRD_COMPONENT  0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_MSB_COMPONENT    0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_ZERO             0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_B_ONE              0x5


#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A                  23:21
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_End                 23
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_Start               21
#define MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_Type               U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_LSB_COMPONENT    0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_THIRD_COMPONENT  0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_MSB_COMPONENT    0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_ZERO             0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_COLOR_SWIZZLE_A_ONE              0x5




#define mwv207regStencilStrideRegAddrs                                    0x0533
#define MWV207REG_STENCIL_STRIDE_Address                                 0x014CC
#define MWV207REG_STENCIL_STRIDE_MSB                                          15
#define MWV207REG_STENCIL_STRIDE_LSB                                           0
#define MWV207REG_STENCIL_STRIDE_BLK                                           0
#define MWV207REG_STENCIL_STRIDE_Count                                         1
#define MWV207REG_STENCIL_STRIDE_FieldMask                            0x0003FFFF
#define MWV207REG_STENCIL_STRIDE_ReadMask                             0x0003FFFC
#define MWV207REG_STENCIL_STRIDE_WriteMask                            0x0003FFFC
#define MWV207REG_STENCIL_STRIDE_ResetValue                           0x00000000

#define MWV207REG_STENCIL_STRIDE_STRIDE                                     17:0
#define MWV207REG_STENCIL_STRIDE_STRIDE_End                                   17
#define MWV207REG_STENCIL_STRIDE_STRIDE_Start                                  0
#define MWV207REG_STENCIL_STRIDE_STRIDE_Type                                 U18




#define mwv207regStencilBaseAddressRegAddrs                               0x0534
#define MWV207REG_STENCIL_BASE_ADDRESS_Address                           0x014D0
#define MWV207REG_STENCIL_BASE_ADDRESS_MSB                                    15
#define MWV207REG_STENCIL_BASE_ADDRESS_LSB                                     0
#define MWV207REG_STENCIL_BASE_ADDRESS_BLK                                     0
#define MWV207REG_STENCIL_BASE_ADDRESS_Count                                   1
#define MWV207REG_STENCIL_BASE_ADDRESS_FieldMask                      0xFFFFFFFF
#define MWV207REG_STENCIL_BASE_ADDRESS_ReadMask                       0xFFFFFFFC
#define MWV207REG_STENCIL_BASE_ADDRESS_WriteMask                      0xFFFFFFFC
#define MWV207REG_STENCIL_BASE_ADDRESS_ResetValue                     0x00000000

#define MWV207REG_STENCIL_BASE_ADDRESS_TYPE                                31:31
#define MWV207REG_STENCIL_BASE_ADDRESS_TYPE_End                               31
#define MWV207REG_STENCIL_BASE_ADDRESS_TYPE_Start                             31
#define MWV207REG_STENCIL_BASE_ADDRESS_TYPE_Type                             U01
#define   MWV207REG_STENCIL_BASE_ADDRESS_TYPE_SYSTEM                         0x0
#define   MWV207REG_STENCIL_BASE_ADDRESS_TYPE_VIRTUAL_SYSTEM                 0x1

#define MWV207REG_STENCIL_BASE_ADDRESS_ADDRESS                              30:0
#define MWV207REG_STENCIL_BASE_ADDRESS_ADDRESS_End                            30
#define MWV207REG_STENCIL_BASE_ADDRESS_ADDRESS_Start                           0
#define MWV207REG_STENCIL_BASE_ADDRESS_ADDRESS_Type                          U31




#define mwv207regStencilBufferEndAddressRegAddrs                          0x0535
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_Address                     0x014D4
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_MSB                              15
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_LSB                               0
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_BLK                               0
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_Count                             1
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_FieldMask                0xFFFFFFFF
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_ReadMask                 0xFFFFFFFF
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_WriteMask                0xFFFFFFFF
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_ResetValue               0x00000000

#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_ADDRESS                        31:0
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_ADDRESS_End                      31
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_ADDRESS_Start                     0
#define MWV207REG_STENCIL_BUFFER_END_ADDRESS_ADDRESS_Type                    U32





#define mwv207regPERenderTargetAddressRegAddrs                            0x0540
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_Address                       0x01500
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_MSB                                15
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_LSB                                 5
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_BLK                                 3
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_Count                              32
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_FieldMask                  0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_ReadMask                   0xFFFFFFFC
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_WriteMask                  0xFFFFFFFC
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_ResetValue                 0x00000000

#define MWV207REG_PE_RENDER_TARGET_ADDRESS_TYPE                            31:31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_TYPE_End                           31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_TYPE_Start                         31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_TYPE_Type                         U01
#define   MWV207REG_PE_RENDER_TARGET_ADDRESS_TYPE_SYSTEM                     0x0
#define   MWV207REG_PE_RENDER_TARGET_ADDRESS_TYPE_VIRTUAL_SYSTEM             0x1

#define MWV207REG_PE_RENDER_TARGET_ADDRESS_ADDRESS                          30:0
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_ADDRESS_End                        30
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_ADDRESS_Start                       0
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_ADDRESS_Type                      U31




#define mwv207regPERenderTargetConfigRegAddrs                             0x0560
#define MWV207REG_PE_RENDER_TARGET_CONFIG_Address                        0x01580
#define MWV207REG_PE_RENDER_TARGET_CONFIG_MSB                                 15
#define MWV207REG_PE_RENDER_TARGET_CONFIG_LSB                                  2
#define MWV207REG_PE_RENDER_TARGET_CONFIG_BLK                                  0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_Count                                4
#define MWV207REG_PE_RENDER_TARGET_CONFIG_FieldMask                   0x33F3FFFF
#define MWV207REG_PE_RENDER_TARGET_CONFIG_ReadMask                    0x33F3FFE0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_WriteMask                   0x33F3FFE0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_ResetValue                  0x00000000


#define MWV207REG_PE_RENDER_TARGET_CONFIG_STRIDE                            17:0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_STRIDE_End                          17
#define MWV207REG_PE_RENDER_TARGET_CONFIG_STRIDE_Start                         0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_STRIDE_Type                        U18


#define MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT                           25:20
#define MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_End                          25
#define MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_Start                        20
#define MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_Type                        U06
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_X4R4G4B4                 0x00
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_A4R4G4B4                 0x01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_X1R5G5B5                 0x02
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_A1R5G5B5                 0x03
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_R5G6B5                   0x04
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_X8R8G8B8                 0x05
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_A8R8G8B8                 0x06
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_YUY2                     0x07
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_UYVY                     0x08
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_INDEX8                   0x09
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_MONOCHROME               0x0A
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_HDR7E3                   0x0B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_HDR6E4                   0x0C
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_HDR5E5                   0x0D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_HDR6E5                   0x0E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_YV12                     0x0F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_A8                       0x10
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RF16                     0x11
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RF16GF16                 0x12
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RF16GF16BF16AF16         0x13
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RF32                     0x14
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RF32GF32                 0x15
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_R10G10B10A2              0x16
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI8                      0x17
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI8GI8                   0x18
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI8GI8BI8AI8             0x19
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI16                     0x1A
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI16GI16                 0x1B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI16GI16BI16AI16         0x1C
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI32                     0x14
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI32GI32                 0x15
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RF11GF11BF10             0x1D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI10GI10BI10AI2          0x1E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_R8G8                     0x1F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_R8                       0x23
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RF32GF32BF32AF32         0x25
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI32GI32BI32AI32         0x26
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_R16                      0x27
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RUI32GUI32BUI32AUI32     0x26
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RSI32GSI32BSI32ASI32     0x27
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_A8B8G8R8                 0x2B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI32_NEW                 0x2D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_RI32GI32_NEW             0x2E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_R16G16                   0x2F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_FORMAT_R16G16B16A16             0x30


#define MWV207REG_PE_RENDER_TARGET_CONFIG_SUPER_TILED                      28:28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_SUPER_TILED_End                     28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_SUPER_TILED_Start                   28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_SUPER_TILED_Type                   U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_SUPER_TILED_DISABLED             0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_SUPER_TILED_ENABLED              0x1


#define MWV207REG_PE_RENDER_TARGET_CONFIG_ALPHA_BLEND_ENABLE               29:29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_ALPHA_BLEND_ENABLE_End              29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_ALPHA_BLEND_ENABLE_Start            29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_ALPHA_BLEND_ENABLE_Type            U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_ALPHA_BLEND_ENABLE_DISABLED      0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_ALPHA_BLEND_ENABLE_ENABLED       0x1




#define mwv207regPERenderTargetExtraConfigRegAddrs                        0x0564
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_Address                  0x01590
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_MSB                           15
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_LSB                            2
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_BLK                            0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_Count                          4
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_FieldMask             0x00000003
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ReadMask              0x00000003
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_WriteMask             0x00000003
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ResetValue            0x00000000


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL               1:0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL_End             1
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL_Start           0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL_Type          U02
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL_NO_SWAP     0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL_SWAP_WORD   0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL_SWAP_DWORD  0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_ENDIAN_CONTROL_SWAP_DDWORD 0x3





#define mwv207regPERenderTargetAddressExRegAddrs                          0x5200
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_Address                    0x14800
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_MSB                             15
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_LSB                              6
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_BLK                              3
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_Count                           64
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_FieldMask               0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_ReadMask                0xFFFFFFFC
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_WriteMask               0xFFFFFFFC
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_ResetValue              0x00000000

#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_TYPE                         31:31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_TYPE_End                        31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_TYPE_Start                      31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_TYPE_Type                      U01
#define   MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_TYPE_SYSTEM                  0x0
#define   MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_TYPE_VIRTUAL_SYSTEM          0x1

#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_ADDRESS                       30:0
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_ADDRESS_End                     30
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_ADDRESS_Start                    0
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX_ADDRESS_Type                   U31




#define mwv207regPERenderTargetConfigExRegAddrs                           0x5240
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_Address                     0x14900
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_MSB                              15
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_LSB                               3
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_BLK                               0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_Count                             8
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FieldMask                0xFFF3FFFF
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ReadMask                 0xFFF3FFE0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_WriteMask                0xFFF3FFE0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ResetValue               0x00000000


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_STRIDE                         17:0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_STRIDE_End                       17
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_STRIDE_Start                      0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_STRIDE_Type                     U18


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT                        25:20
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_End                       25
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_Start                     20
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_Type                     U06
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_X4R4G4B4              0x00
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_A4R4G4B4              0x01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_X1R5G5B5              0x02
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_A1R5G5B5              0x03
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_R5G6B5                0x04
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_X8R8G8B8              0x05
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_A8R8G8B8              0x06
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_YUY2                  0x07
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_UYVY                  0x08
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_INDEX8                0x09
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_MONOCHROME            0x0A
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_HDR7E3                0x0B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_HDR6E4                0x0C
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_HDR5E5                0x0D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_HDR6E5                0x0E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_YV12                  0x0F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_A8                    0x10
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RF16                  0x11
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RF16GF16              0x12
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RF16GF16BF16AF16      0x13
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RF32                  0x14
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RF32GF32              0x15
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_R10G10B10A2           0x16
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI8                   0x17
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI8GI8                0x18
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI8GI8BI8AI8          0x19
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI16                  0x1A
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI16GI16              0x1B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI16GI16BI16AI16      0x1C
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI32                  0x14
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI32GI32              0x15
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RF11GF11BF10          0x1D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI10GI10BI10AI2       0x1E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_R8G8                  0x1F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_R8                    0x23
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RF32GF32BF32AF32      0x25
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI32GI32BI32AI32      0x26
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_R16                   0x27
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RUI32GUI32BUI32AUI32  0x26
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RSI32GSI32BSI32ASI32  0x27
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_A8B8G8R8              0x2B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI32_NEW              0x2D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_RI32GI32_NEW          0x2E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_R16G16                0x2F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_FORMAT_R16G16B16A16          0x30


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_TILE_MODE                     27:26
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_TILE_MODE_End                    27
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_TILE_MODE_Start                  26
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_TILE_MODE_Type                  U02
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_TILE_MODE_TILED4X4            0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_TILE_MODE_SUPER_TILED_XMAJOR  0x1
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_TILE_MODE_SUPER_TILED_YMAJOR  0x2


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_SUPER_TILED                   28:28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_SUPER_TILED_End                  28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_SUPER_TILED_Start                28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_SUPER_TILED_Type                U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_SUPER_TILED_DISABLED          0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_SUPER_TILED_ENABLED           0x1


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ALPHA_BLEND_ENABLE            29:29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ALPHA_BLEND_ENABLE_End           29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ALPHA_BLEND_ENABLE_Start         29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ALPHA_BLEND_ENABLE_Type         U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ALPHA_BLEND_ENABLE_DISABLED   0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ALPHA_BLEND_ENABLE_ENABLED    0x1


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_GAMMA_CORRECTION              30:30
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_GAMMA_CORRECTION_End             30
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_GAMMA_CORRECTION_Start           30
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_GAMMA_CORRECTION_Type           U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_GAMMA_CORRECTION_LINEAR       0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_GAMMA_CORRECTION_S_RGB        0x1


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ADDR_REMAP                    31:31
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ADDR_REMAP_End                   31
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ADDR_REMAP_Start                 31
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ADDR_REMAP_Type                 U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ADDR_REMAP_DISABLED           0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX_ADDR_REMAP_ENABLED            0x1




#define mwv207regPERenderTargetExtraConfigExRegAddrs                      0x5248
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_Address               0x14920
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MSB                        15
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_LSB                         3
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_BLK                         0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_Count                       8
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_FieldMask          0x00003BFB
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ReadMask           0x00003BFB
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_WriteMask          0x00003BFB
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ResetValue         0x00000000


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL            1:0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL_End          1
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL_Start        0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL_Type       U02
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL_NO_SWAP  0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL_SWAP_WORD 0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL_SWAP_DWORD 0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_ENDIAN_CONTROL_SWAP_DDWORD 0x3


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_ENDIAN_CONTROL       3:3
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_ENDIAN_CONTROL_End     3
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_ENDIAN_CONTROL_Start   3
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_ENDIAN_CONTROL_Type  U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_ENDIAN_CONTROL_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_ENDIAN_CONTROL_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE               7:4
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE_End             7
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE_Start           4
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE_Type          U04
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE_RED         0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE_GREEN       0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE_BLUE        0x4
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_COLOR_WRITE_ALPHA       0x8


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_COLOR_WRITE        11:11
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_COLOR_WRITE_End       11
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_COLOR_WRITE_Start     11
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_COLOR_WRITE_Type     U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_COLOR_WRITE_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_COLOR_WRITE_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_DESTINATION_READ     9:9
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_DESTINATION_READ_End   9
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_DESTINATION_READ_Start 9
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_DESTINATION_READ_Type U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_DESTINATION_READ_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_DESTINATION_READ_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_DESTINATION_READ          8:8
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_DESTINATION_READ_End        8
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_DESTINATION_READ_Start      8
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_DESTINATION_READ_Type     U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_DESTINATION_READ_READ   0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_DESTINATION_READ_DONT_READ 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_SIGN_CONTROL       12:12
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_SIGN_CONTROL_End      12
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_SIGN_CONTROL_Start    12
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_SIGN_CONTROL_Type    U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_SIGN_CONTROL_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_MASK_SIGN_CONTROL_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_SIGN_CONTROL            13:13
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_SIGN_CONTROL_End           13
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_SIGN_CONTROL_Start         13
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_SIGN_CONTROL_Type         U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_SIGN_CONTROL_UNSIGN     0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX_SIGN_CONTROL_SIGN       0x1

#define mwv207regPERenderTargetAlphaTestRegAddrs                          0x5250
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_Address                    0x14940
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_MSB                             15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_LSB                              3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_BLK                              0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_Count                            8
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_FieldMask               0xFFFF0071
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_ReadMask                0xFFFF0071
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_WriteMask               0xFFFF0071
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_ResetValue              0x00000000

#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_TEST                           0:0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_TEST_End                         0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_TEST_Start                       0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_TEST_Type                      U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_TEST_DISABLED                0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_TEST_ENABLED                 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE                        6:4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_End                      6
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_Start                    4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_Type                   U03
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_NEVER                0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_LESS                 0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_EQUAL                0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_LESS_EQUAL           0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_GREATER              0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_NOT_EQUAL            0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_GREATER_EQUAL        0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_COMPARE_ALWAYS               0x7


#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_REFERENCE                    31:16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_REFERENCE_End                   31
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_REFERENCE_Start                 16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_REFERENCE_Type                 U16

#define mwv207regPERenderTargetAlphaControlRegAddrs                       0x5258
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_Address                 0x14960
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_MSB                          15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_LSB                           3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_BLK                           0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_Count                         8
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_FieldMask            0x7FFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ReadMask             0x7FFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_WriteMask            0x7FFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ResetValue           0x00000000


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA           30:28
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_End          30
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_Start        28
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_Type        U03
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_ADD       0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_SUBTRACT  0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_REVERSE_SUBTRACT 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_MIN       0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ALPHA_MAX       0x4


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA          27:24
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_End         27
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_Start       24
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_Type       U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_ZERO     0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_ONE      0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_SRC_COLOR 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_INV_SRC_COLOR 0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_SRC_ALPHA 0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_INV_SRC_ALPHA 0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_DEST_ALPHA 0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_INV_DEST_ALPHA 0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_DEST_COLOR 0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_INV_DEST_COLOR 0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_SRC_ALPHA_SAT 0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_BLEND_FACTOR 0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ALPHA_EXTEND   0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA           23:20
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_End          23
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_Start        20
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_Type        U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_ZERO      0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_ONE       0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_SRC_COLOR 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_INV_SRC_COLOR 0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_SRC_ALPHA 0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_INV_SRC_ALPHA 0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_DEST_ALPHA 0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_INV_DEST_ALPHA 0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_DEST_COLOR 0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_INV_DEST_COLOR 0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_SRC_ALPHA_SAT 0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_BLEND_FACTOR 0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ALPHA_EXTEND    0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_NO_READ   18:18
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_NO_READ_End  18
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_NO_READ_Start 18
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_NO_READ_Type U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_NO_READ         17:17
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_NO_READ_End        17
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_NO_READ_Start      17
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_NO_READ_Type      U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_KILL           16:16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_KILL_End          16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_KILL_Start        16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_KILL_Type        U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_KILL_DISABLED  0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_KILL_ENABLED   0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_KILL     15:15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_KILL_End    15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_KILL_Start  15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_KILL_Type  U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_KILL_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_KILL_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_KILL            19:19
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_KILL_End           19
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_KILL_Start         19
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_KILL_Type         U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_KILL_DISABLED   0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ONE_KILL_ENABLED    0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_KILL        1:1
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_KILL_End      1
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_KILL_Start    1
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_KILL_Type   U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_KILL_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ONE_KILL_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_NO_READ          2:2
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_NO_READ_End        2
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_NO_READ_Start      2
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_NO_READ_Type     U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ALPHA_ZERO_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_NO_READ    3:3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_NO_READ_End  3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_NO_READ_Start 3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_NO_READ_Type U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_COLOR_ALPHA_ZERO_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION                 14:12
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_End                14
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_Start              12
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_Type              U03
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_ADD             0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_SUBTRACT        0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_REVERSE_SUBTRACT 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_MIN             0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_OPERATION_MAX             0x4


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND                 11:8
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_End               11
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_Start              8
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_Type             U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ZERO           0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_ONE            0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_SRC_COLOR      0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_INV_SRC_COLOR  0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_SRC_ALPHA      0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_INV_SRC_ALPHA  0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_DEST_ALPHA     0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_INV_DEST_ALPHA 0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_DEST_COLOR     0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_INV_DEST_COLOR 0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_SRC_ALPHA_SAT  0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_BLEND_FACTOR   0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_DEST_BLEND_EXTEND         0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND                   7:4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_End                 7
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_Start               4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_Type              U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ZERO            0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_ONE             0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_SRC_COLOR       0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_INV_SRC_COLOR   0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_SRC_ALPHA       0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_INV_SRC_ALPHA   0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_DEST_ALPHA      0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_INV_DEST_ALPHA  0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_DEST_COLOR      0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_INV_DEST_COLOR  0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_SRC_ALPHA_SAT   0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_BLEND_FACTOR    0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_SRC_BLEND_EXTEND          0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ENABLE                      0:0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ENABLE_End                    0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ENABLE_Start                  0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ENABLE_Type                 U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ENABLE_DISABLED           0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_ENABLE_ENABLED            0x1

#define mwv207regPERenderTargetBlendColorLowRegAddrs                      0x5260
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_Address               0x14980
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_MSB                        15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_LSB                         3
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_BLK                         0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_Count                       8
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_FieldMask          0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_ReadMask           0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_WriteMask          0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_ResetValue         0x00000000


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_RED                      15:0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_RED_End                    15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_RED_Start                   0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_RED_Type                  U16


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_GREEN                   31:16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_GREEN_End                  31
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_GREEN_Start                16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_GREEN_Type                U16

#define mwv207regPERenderTargetBlendColorHighRegAddrs                     0x5268
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_Address              0x149A0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_MSB                       15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_LSB                        3
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW_HIGH_BLK                    0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_Count                      1
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_FieldMask         0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_ReadMask          0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_WriteMask         0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_ResetValue        0x00000000


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_BLUE                    15:0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_BLUE_End                  15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_BLUE_Start                 0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_BLUE_Type                U16


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_ALPHA                  31:16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_ALPHA_End                 31
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_ALPHA_Start               16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH_ALPHA_Type               U16




#define mwv207regPERenderTargetEndAddresExRegAddrs                        0x5270
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_Address                 0x149C0
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_MSB                          15
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_LSB                           3
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_BLK                           0
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_Count                         8
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_FieldMask            0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_ReadMask             0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_WriteMask            0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_ResetValue           0x00000000

#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_ADDRESS                    31:0
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_ADDRESS_End                  31
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_ADDRESS_Start                 0
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX_ADDRESS_Type                U32

#define mwv207regPERenderTargetFormatExRegAddrs                           0x5278
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_Address                     0x149E0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_MSB                              15
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_LSB                               3
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_BLK                               0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_Count                             8
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_FieldMask                0x00EEEEDF
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_ReadMask                 0x00EEEEDF
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_WriteMask                0x00EEEEDF
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_ResetValue               0x006420C0

#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE                       4:0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_End                     4
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_Start                   0
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_Type                  U05
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED5_6_5_UNORM  0x00
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED1_5_5_5_UNORM 0x01
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED4_4_4_4_UNORM 0x02
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED2_10_10_10_UNORM 0x03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED2_10_10_10_UINT 0x04
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED2_10_10_10_HDR7E3 0x05
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED2_10_10_10_HDR6E4 0x06
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED2_10_10_10_HDR5E5 0x07
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED11_10_11_HDR6E5 0x08
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_PACKED10_11_11_HDR6E5 0x09
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_INT8               0x0A
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_INT16              0x0B
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_INT32              0x0C
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_UINT8              0x0D
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_UINT16             0x0E
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_UINT32             0x0F
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_UNORM8             0x10
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_UNORM16            0x11
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_SNORM8             0x12
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_SNORM16            0x13
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_FLOAT16            0x14
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_DATA_TYPE_FLOAT32            0x15


#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER                7:6
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER_End              7
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER_Start            6
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER_Type           U02
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER_ONE_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER_TWO_COMPONENTS 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER_THREE_COMPONENTS 0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COMPONENT_NUMBER_FOUR_COMPONENTS 0x3


#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R                11:9
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_End              11
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_Start             9
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_Type            U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_ZERO          0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_R_ONE           0x5


#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G               15:13
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_End              15
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_Start            13
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_Type            U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_ZERO          0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_G_ONE           0x5


#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B               19:17
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_End              19
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_Start            17
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_Type            U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_ZERO          0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_B_ONE           0x5


#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A               23:21
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_End              23
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_Start            21
#define MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_Type            U03
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_ZERO          0x4
#define   MWV207REG_PE_RENDER_TARGET_FORMAT_EX_COLOR_SWIZZLE_A_ONE           0x5





#define mwv207regPERenderTargetAddressEx2RegAddrs                         0x5F00
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_Address                   0x17C00
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_MSB                            15
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_LSB                             4
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_BLK                             0
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_Count                          16
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_FieldMask              0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_ReadMask               0xFFFFFFFC
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_WriteMask              0xFFFFFFFC
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_ResetValue             0x00000000

#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_TYPE                        31:31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_TYPE_End                       31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_TYPE_Start                     31
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_TYPE_Type                     U01
#define   MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_TYPE_SYSTEM                 0x0
#define   MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_TYPE_VIRTUAL_SYSTEM         0x1

#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_ADDRESS                      30:0
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_ADDRESS_End                    30
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_ADDRESS_Start                   0
#define MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2_ADDRESS_Type                  U31




#define mwv207regPERenderTargetConfigEx2RegAddrs                          0x5F10
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_Address                    0x17C40
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_MSB                             15
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_LSB                              4
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_BLK                              0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_Count                           16
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FieldMask               0x7FF3FFFF
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ReadMask                0x7FF3FFE0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_WriteMask               0x7FF3FFE0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ResetValue              0x00000000


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_STRIDE                        17:0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_STRIDE_End                      17
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_STRIDE_Start                     0
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_STRIDE_Type                    U18


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT                       25:20
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_End                      25
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_Start                    20
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_Type                    U06
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_X4R4G4B4             0x00
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_A4R4G4B4             0x01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_X1R5G5B5             0x02
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_A1R5G5B5             0x03
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_R5G6B5               0x04
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_X8R8G8B8             0x05
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_A8R8G8B8             0x06
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_YUY2                 0x07
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_UYVY                 0x08
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_INDEX8               0x09
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_MONOCHROME           0x0A
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_HDR7E3               0x0B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_HDR6E4               0x0C
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_HDR5E5               0x0D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_HDR6E5               0x0E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_YV12                 0x0F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_A8                   0x10
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RF16                 0x11
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RF16GF16             0x12
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RF16GF16BF16AF16     0x13
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RF32                 0x14
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RF32GF32             0x15
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_R10G10B10A2          0x16
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI8                  0x17
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI8GI8               0x18
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI8GI8BI8AI8         0x19
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI16                 0x1A
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI16GI16             0x1B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI16GI16BI16AI16     0x1C
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI32                 0x14
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI32GI32             0x15
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RF11GF11BF10         0x1D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI10GI10BI10AI2      0x1E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_R8G8                 0x1F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_R8                   0x23
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RF32GF32BF32AF32     0x25
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI32GI32BI32AI32     0x26
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_R16                  0x27
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RUI32GUI32BUI32AUI32 0x26
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RSI32GSI32BSI32ASI32 0x27
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_A8B8G8R8             0x2B
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI32_NEW             0x2D
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_RI32GI32_NEW         0x2E
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_R16G16               0x2F
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_FORMAT_R16G16B16A16         0x30


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_TILE_MODE                    27:26
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_TILE_MODE_End                   27
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_TILE_MODE_Start                 26
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_TILE_MODE_Type                 U02
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_TILE_MODE_TILED4X4           0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_TILE_MODE_SUPER_TILED_XMAJOR 0x1
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_TILE_MODE_SUPER_TILED_YMAJOR 0x2


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_SUPER_TILED                  28:28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_SUPER_TILED_End                 28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_SUPER_TILED_Start               28
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_SUPER_TILED_Type               U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_SUPER_TILED_DISABLED         0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_SUPER_TILED_ENABLED          0x1


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ALPHA_BLEND_ENABLE           29:29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ALPHA_BLEND_ENABLE_End          29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ALPHA_BLEND_ENABLE_Start        29
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ALPHA_BLEND_ENABLE_Type        U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ALPHA_BLEND_ENABLE_DISABLED  0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_ALPHA_BLEND_ENABLE_ENABLED   0x1


#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_GAMMA_CORRECTION             30:30
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_GAMMA_CORRECTION_End            30
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_GAMMA_CORRECTION_Start          30
#define MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_GAMMA_CORRECTION_Type          U01
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_GAMMA_CORRECTION_LINEAR      0x0
#define   MWV207REG_PE_RENDER_TARGET_CONFIG_EX2_GAMMA_CORRECTION_S_RGB       0x1




#define mwv207regPERenderTargetExtraConfigEx2RegAddrs                     0x5F20
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_Address              0x17C80
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MSB                       15
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_LSB                        4
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_BLK                        0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_Count                     16
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_FieldMask         0x0777FBFB
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ReadMask          0x0777FBFB
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_WriteMask         0x0777FBFB
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ResetValue        0x03012000


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL           1:0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL_End         1
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL_Start       0
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL_Type      U02
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL_NO_SWAP 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL_SWAP_WORD 0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL_SWAP_DWORD 0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_ENDIAN_CONTROL_SWAP_DDWORD 0x3


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_ENDIAN_CONTROL      3:3
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_ENDIAN_CONTROL_End    3
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_ENDIAN_CONTROL_Start  3
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_ENDIAN_CONTROL_Type U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_ENDIAN_CONTROL_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_ENDIAN_CONTROL_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE              7:4
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE_End            7
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE_Start          4
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE_Type         U04
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE_RED        0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE_GREEN      0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE_BLUE       0x4
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_WRITE_ALPHA      0x8


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_WRITE       11:11
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_WRITE_End      11
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_WRITE_Start    11
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_WRITE_Type    U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_WRITE_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_WRITE_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_DESTINATION_READ    9:9
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_DESTINATION_READ_End  9
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_DESTINATION_READ_Start 9
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_DESTINATION_READ_Type U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_DESTINATION_READ_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_DESTINATION_READ_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_DESTINATION_READ         8:8
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_DESTINATION_READ_End       8
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_DESTINATION_READ_Start     8
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_DESTINATION_READ_Type    U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_DESTINATION_READ_READ  0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_DESTINATION_READ_DONT_READ 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_SWIZZLE     15:15
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_SWIZZLE_End    15
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_SWIZZLE_Start  15
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_SWIZZLE_Type  U01
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_SWIZZLE_ENABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_MASK_COLOR_SWIZZLE_MASKED 0x1


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R        14:12
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_End       14
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_Start     12
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_Type     U03
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_ZERO   0x4
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_R_ONE    0x5


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G        18:16
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_End       18
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_Start     16
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_Type     U03
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_ZERO   0x4
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_G_ONE    0x5


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B        22:20
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_End       22
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_Start     20
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_Type     U03
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_ZERO   0x4
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_B_ONE    0x5


#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A        26:24
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_End       26
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_Start     24
#define MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_Type     U03
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_LSB_COMPONENT 0x0
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_SECOND_COMPONENT 0x1
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_THIRD_COMPONENT 0x2
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_MSB_COMPONENT 0x3
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_ZERO   0x4
#define   MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2_COLOR_SWIZZLE_A_ONE    0x5

#define mwv207regPERenderTargetAlphaTestExRegAddrs                        0x5F30
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_Address                 0x17CC0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_MSB                          15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_LSB                           4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_BLK                           0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_Count                        16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_FieldMask            0xFFFF0071
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_ReadMask             0xFFFF0071
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_WriteMask            0xFFFF0071
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_ResetValue           0x00000000

#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_TEST                        0:0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_TEST_End                      0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_TEST_Start                    0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_TEST_Type                   U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_TEST_DISABLED             0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_TEST_ENABLED              0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE                     6:4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_End                   6
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_Start                 4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_Type                U03
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_NEVER             0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_LESS              0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_EQUAL             0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_LESS_EQUAL        0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_GREATER           0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_NOT_EQUAL         0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_GREATER_EQUAL     0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_COMPARE_ALWAYS            0x7


#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_REFERENCE                 31:16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_REFERENCE_End                31
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_REFERENCE_Start              16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_TEST_EX_REFERENCE_Type              U16

#define mwv207regPERenderTargetAlphaControlExRegAddrs                     0x5F40
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_Address              0x17D00
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_MSB                       15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_LSB                        4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_BLK                        0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_Count                     16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_FieldMask         0x7FFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ReadMask          0x7FFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_WriteMask         0x7FFFFFFF
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ResetValue        0x00000000


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA        30:28
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_End       30
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_Start     28
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_Type     U03
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_ADD    0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_SUBTRACT 0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_REVERSE_SUBTRACT 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_MIN    0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ALPHA_MAX    0x4


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA       27:24
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_End      27
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_Start    24
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_Type    U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_ZERO  0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_ONE   0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_SRC_COLOR 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_INV_SRC_COLOR 0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_SRC_ALPHA 0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_INV_SRC_ALPHA 0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_DEST_ALPHA 0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_INV_DEST_ALPHA 0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_DEST_COLOR 0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_INV_DEST_COLOR 0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_SRC_ALPHA_SAT 0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_BLEND_FACTOR 0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ALPHA_EXTEND 0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA        23:20
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_End       23
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_Start     20
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_Type     U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_ZERO   0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_ONE    0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_SRC_COLOR 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_INV_SRC_COLOR 0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_SRC_ALPHA 0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_INV_SRC_ALPHA 0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_DEST_ALPHA 0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_INV_DEST_ALPHA 0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_DEST_COLOR 0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_INV_DEST_COLOR 0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_SRC_ALPHA_SAT 0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_BLEND_FACTOR 0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ALPHA_EXTEND 0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_NO_READ 18:18
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_NO_READ_End 18
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_NO_READ_Start 18
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_NO_READ_Type U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_NO_READ      17:17
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_NO_READ_End     17
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_NO_READ_Start   17
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_NO_READ_Type   U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_KILL        16:16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_KILL_End       16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_KILL_Start     16
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_KILL_Type     U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_KILL_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_KILL_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_KILL  15:15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_KILL_End 15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_KILL_Start 15
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_KILL_Type U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_KILL_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_KILL_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_KILL         19:19
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_KILL_End        19
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_KILL_Start      19
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_KILL_Type      U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_KILL_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ONE_KILL_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_KILL     1:1
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_KILL_End   1
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_KILL_Start 1
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_KILL_Type U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_KILL_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ONE_KILL_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_NO_READ       2:2
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_NO_READ_End     2
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_NO_READ_Start   2
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_NO_READ_Type  U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ALPHA_ZERO_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_NO_READ 3:3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_NO_READ_End 3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_NO_READ_Start 3
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_NO_READ_Type U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_NO_READ_DISABLED 0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_COLOR_ALPHA_ZERO_NO_READ_ENABLED 0x1


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION              14:12
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_End             14
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_Start           12
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_Type           U03
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_ADD          0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_SUBTRACT     0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_REVERSE_SUBTRACT 0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_MIN          0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_OPERATION_MAX          0x4


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND              11:8
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_End            11
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_Start           8
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_Type          U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ZERO        0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_ONE         0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_SRC_COLOR   0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_INV_SRC_COLOR 0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_SRC_ALPHA   0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_INV_SRC_ALPHA 0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_DEST_ALPHA  0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_INV_DEST_ALPHA 0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_DEST_COLOR  0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_INV_DEST_COLOR 0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_SRC_ALPHA_SAT 0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_BLEND_FACTOR 0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_DEST_BLEND_EXTEND      0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND                7:4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_End              7
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_Start            4
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_Type           U04
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ZERO         0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_ONE          0x1
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_SRC_COLOR    0x2
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_INV_SRC_COLOR 0x3
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_SRC_ALPHA    0x4
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_INV_SRC_ALPHA 0x5
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_DEST_ALPHA   0x6
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_INV_DEST_ALPHA 0x7
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_DEST_COLOR   0x8
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_INV_DEST_COLOR 0x9
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_SRC_ALPHA_SAT 0xA
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_BLEND_FACTOR_ALPHA 0xB
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_INV_BLEND_FACTOR_ALPHA 0xC
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_BLEND_FACTOR 0xD
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_INV_BLEND_FACTOR 0xE
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_SRC_BLEND_EXTEND       0xF


#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ENABLE                   0:0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ENABLE_End                 0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ENABLE_Start               0
#define MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ENABLE_Type              U01
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ENABLE_DISABLED        0x0
#define   MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL_EX_ENABLE_ENABLED         0x1

#define mwv207regPERenderTargetBlendColorExLowRegAddrs                    0x5F60
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_Address            0x17D80
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_MSB                     15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_LSB                      4
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_BLK                      0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_Count                   16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_FieldMask       0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_ReadMask        0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_WriteMask       0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_ResetValue      0x00000000


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_RED                   15:0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_RED_End                 15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_RED_Start                0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_RED_Type               U16


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_GREEN                31:16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_GREEN_End               31
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_GREEN_Start             16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_GREEN_Type             U16

#define mwv207regPERenderTargetBlendColorExHighRegAddrs                   0x5F70
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_Address           0x17DC0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_MSB                    15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_LSB                     4
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_LOW_HIGH_BLK                 0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_Count                   1
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_FieldMask      0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_ReadMask       0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_WriteMask      0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_ResetValue     0x00000000


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_BLUE                 15:0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_BLUE_End               15
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_BLUE_Start              0
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_BLUE_Type             U16


#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_ALPHA               31:16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_ALPHA_End              31
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_ALPHA_Start            16
#define MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_EX_HIGH_ALPHA_Type            U16




#define mwv207regPERenderTargetEndAddresEx2RegAddrs                       0x5F50
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_Address                0x17D40
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_MSB                         15
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_LSB                          4
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_BLK                          0
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_Count                       16
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_FieldMask           0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_ReadMask            0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_WriteMask           0xFFFFFFFF
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_ResetValue          0x00000000

#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_ADDRESS                   31:0
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_ADDRESS_End                 31
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_ADDRESS_Start                0
#define MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX2_ADDRESS_Type               U32





#define mwv207regPEBlendFactorFp32RedRegAddrs                             0x5FD0
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_Address                       0x17F40
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_MSB                                15
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_LSB                                 3
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_BLK                                 3
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_Count                               8
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_FieldMask                  0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_ReadMask                   0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_WriteMask                  0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_ResetValue                 0x00000000


#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_FACTOR                           31:0
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_FACTOR_End                         31
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_FACTOR_Start                        0
#define MWV207REG_PE_BLEND_FACTOR_FP32_RED_FACTOR_Type                       U32




#define mwv207regPEBlendFactorFp32GreenRegAddrs                           0x5FD8
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_Address                     0x17F60
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_MSB                              15
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_LSB                               3
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_BLK                               3
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_Count                             8
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_FieldMask                0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_ReadMask                 0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_WriteMask                0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_ResetValue               0x00000000


#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_FACTOR                         31:0
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_FACTOR_End                       31
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_FACTOR_Start                      0
#define MWV207REG_PE_BLEND_FACTOR_FP32_GREEN_FACTOR_Type                     U32




#define mwv207regPEBlendFactorFp32BlueRegAddrs                            0x5FE0
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_Address                      0x17F80
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_MSB                               15
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_LSB                                3
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_BLK                                3
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_Count                              8
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_FieldMask                 0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_ReadMask                  0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_WriteMask                 0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_ResetValue                0x00000000


#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_FACTOR                          31:0
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_FACTOR_End                        31
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_FACTOR_Start                       0
#define MWV207REG_PE_BLEND_FACTOR_FP32_BLUE_FACTOR_Type                      U32




#define mwv207regPEBlendFactorFp32AlphaRegAddrs                           0x5FE8
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_Address                     0x17FA0
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_MSB                              15
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_LSB                               3
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_BLK                               3
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_Count                             8
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_FieldMask                0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_ReadMask                 0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_WriteMask                0xFFFFFFFF
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_ResetValue               0x00000000


#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_FACTOR                         31:0
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_FACTOR_End                       31
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_FACTOR_Start                      0
#define MWV207REG_PE_BLEND_FACTOR_FP32_ALPHA_FACTOR_Type                     U32


#define mwv207regDepthNearExRegAddrs                                      0x7A70
#define MWV207REG_DEPTH_NEAR_EX_Address                                  0x1E9C0
#define MWV207REG_DEPTH_NEAR_EX_MSB                                           15
#define MWV207REG_DEPTH_NEAR_EX_LSB                                            4
#define MWV207REG_DEPTH_NEAR_EX_BLK                                            4
#define MWV207REG_DEPTH_NEAR_EX_Count                                         16
#define MWV207REG_DEPTH_NEAR_EX_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEPTH_NEAR_EX_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEPTH_NEAR_EX_WriteMask                             0xFFFFFFFF
#define MWV207REG_DEPTH_NEAR_EX_ResetValue                            0x00000000

#define MWV207REG_DEPTH_NEAR_EX_NEAR                                        31:0
#define MWV207REG_DEPTH_NEAR_EX_NEAR_End                                      31
#define MWV207REG_DEPTH_NEAR_EX_NEAR_Start                                     0
#define MWV207REG_DEPTH_NEAR_EX_NEAR_Type                                    U32

#define mwv207regDepthFarExRegAddrs                                       0x7A80
#define MWV207REG_DEPTH_FAR_EX_Address                                   0x1EA00
#define MWV207REG_DEPTH_FAR_EX_MSB                                            15
#define MWV207REG_DEPTH_FAR_EX_LSB                                             4
#define MWV207REG_DEPTH_FAR_EX_BLK                                             4
#define MWV207REG_DEPTH_FAR_EX_Count                                          16
#define MWV207REG_DEPTH_FAR_EX_FieldMask                              0xFFFFFFFF
#define MWV207REG_DEPTH_FAR_EX_ReadMask                               0xFFFFFFFF
#define MWV207REG_DEPTH_FAR_EX_WriteMask                              0xFFFFFFFF
#define MWV207REG_DEPTH_FAR_EX_ResetValue                             0x00000000

#define MWV207REG_DEPTH_FAR_EX_FAR                                          31:0
#define MWV207REG_DEPTH_FAR_EX_FAR_End                                        31
#define MWV207REG_DEPTH_FAR_EX_FAR_Start                                       0
#define MWV207REG_DEPTH_FAR_EX_FAR_Type                                      U32


#endif


