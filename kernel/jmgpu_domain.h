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




#ifndef __jmgpuregTessellation_h__
#define __jmgpuregTessellation_h__





#define mwv207regTCSStartRegAddrs                                         0x5280
#define MWV207REG_TCS_START_Address                                      0x14A00
#define MWV207REG_TCS_START_MSB                                               15
#define MWV207REG_TCS_START_LSB                                                0
#define MWV207REG_TCS_START_BLK                                                0
#define MWV207REG_TCS_START_Count                                              1
#define MWV207REG_TCS_START_FieldMask                                 0x000FFFFF
#define MWV207REG_TCS_START_ReadMask                                  0x000FFFFF
#define MWV207REG_TCS_START_WriteMask                                 0x000FFFFF
#define MWV207REG_TCS_START_ResetValue                                0x00000000


#define MWV207REG_TCS_START_PC                                              19:0
#define MWV207REG_TCS_START_PC_End                                            19
#define MWV207REG_TCS_START_PC_Start                                           0
#define MWV207REG_TCS_START_PC_Type                                          U20




#define mwv207regTCSRelativeEndRegAddrs                                   0x5281
#define MWV207REG_TCS_RELATIVE_END_Address                               0x14A04
#define MWV207REG_TCS_RELATIVE_END_MSB                                        15
#define MWV207REG_TCS_RELATIVE_END_LSB                                         0
#define MWV207REG_TCS_RELATIVE_END_BLK                                         0
#define MWV207REG_TCS_RELATIVE_END_Count                                       1
#define MWV207REG_TCS_RELATIVE_END_FieldMask                          0x001FFFFF
#define MWV207REG_TCS_RELATIVE_END_ReadMask                           0x001FFFFF
#define MWV207REG_TCS_RELATIVE_END_WriteMask                          0x001FFFFF
#define MWV207REG_TCS_RELATIVE_END_ResetValue                         0x00000000

#define MWV207REG_TCS_RELATIVE_END_PC                                       20:0
#define MWV207REG_TCS_RELATIVE_END_PC_End                                     20
#define MWV207REG_TCS_RELATIVE_END_PC_Start                                    0
#define MWV207REG_TCS_RELATIVE_END_PC_Type                                   U21



#define mwv207regTCSInstructionRegAddrs                                   0x5282
#define MWV207REG_TCS_INSTRUCTION_Address                                0x14A08
#define MWV207REG_TCS_INSTRUCTION_MSB                                         15
#define MWV207REG_TCS_INSTRUCTION_LSB                                          0
#define MWV207REG_TCS_INSTRUCTION_BLK                                          0
#define MWV207REG_TCS_INSTRUCTION_Count                                        1
#define MWV207REG_TCS_INSTRUCTION_FieldMask                           0xFFFFFFFF
#define MWV207REG_TCS_INSTRUCTION_ReadMask                            0xFFFFFF00
#define MWV207REG_TCS_INSTRUCTION_WriteMask                           0xFFFFFF00
#define MWV207REG_TCS_INSTRUCTION_ResetValue                          0x00000000


#define MWV207REG_TCS_INSTRUCTION_ADDRESS                                   31:0
#define MWV207REG_TCS_INSTRUCTION_ADDRESS_End                                 31
#define MWV207REG_TCS_INSTRUCTION_ADDRESS_Start                                0
#define MWV207REG_TCS_INSTRUCTION_ADDRESS_Type                               U32




#define mwv207regTCSInstructionPrefetchRegAddrs                           0x5283
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_Address                       0x14A0C
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_MSB                                15
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_LSB                                 0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_BLK                                 0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_Count                               1
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_FieldMask                  0x000FFFFF
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_ReadMask                   0x000FFFFF
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_WriteMask                  0x000FFFFF
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_ResetValue                 0x00000000

#define MWV207REG_TCS_INSTRUCTION_PREFETCH_PC                               19:0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_PC_End                             19
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_PC_Start                            0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_PC_Type                           U20



#define mwv207regTCSInstructionPrefetchRelativeEndRegAddrs                0x5284
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_Address          0x14A10
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_MSB                   15
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_LSB                    0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_BLK                    0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_Count                  1
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_FieldMask     0x000FFFFF
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_ReadMask      0x000FFFFF
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_WriteMask     0x000FFFFF
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_ResetValue    0x00000000

#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_PC                  19:0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_End                19
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Start               0
#define MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Type              U20




#define mwv207regTCSControlRegAddrs                                       0x5285
#define MWV207REG_TCS_CONTROL_Address                                    0x14A14
#define MWV207REG_TCS_CONTROL_MSB                                             15
#define MWV207REG_TCS_CONTROL_LSB                                              0
#define MWV207REG_TCS_CONTROL_BLK                                              0
#define MWV207REG_TCS_CONTROL_Count                                            1
#define MWV207REG_TCS_CONTROL_FieldMask                               0x03F7F33F
#define MWV207REG_TCS_CONTROL_ReadMask                                0x03F7F33F
#define MWV207REG_TCS_CONTROL_WriteMask                               0x03F7F33F
#define MWV207REG_TCS_CONTROL_ResetValue                              0x00000000

#define MWV207REG_TCS_CONTROL_OUTPUT_COUNT                                   5:0
#define MWV207REG_TCS_CONTROL_OUTPUT_COUNT_End                                 5
#define MWV207REG_TCS_CONTROL_OUTPUT_COUNT_Start                               0
#define MWV207REG_TCS_CONTROL_OUTPUT_COUNT_Type                              U06


#define MWV207REG_TCS_CONTROL_REMAP                                          9:8
#define MWV207REG_TCS_CONTROL_REMAP_End                                        9
#define MWV207REG_TCS_CONTROL_REMAP_Start                                      8
#define MWV207REG_TCS_CONTROL_REMAP_Type                                     U02
#define   MWV207REG_TCS_CONTROL_REMAP_INPUT                                  0x0
#define   MWV207REG_TCS_CONTROL_REMAP_INPUT_OUTPUT                           0x1
#define   MWV207REG_TCS_CONTROL_REMAP_PACKED                                 0x2


#define MWV207REG_TCS_CONTROL_TEMP_COUNT                                   18:12
#define MWV207REG_TCS_CONTROL_TEMP_COUNT_End                                  18
#define MWV207REG_TCS_CONTROL_TEMP_COUNT_Start                                12
#define MWV207REG_TCS_CONTROL_TEMP_COUNT_Type                                U07

#define MWV207REG_TCS_CONTROL_OUTPUT_ATTRIBUTES                            25:20
#define MWV207REG_TCS_CONTROL_OUTPUT_ATTRIBUTES_End                           25
#define MWV207REG_TCS_CONTROL_OUTPUT_ATTRIBUTES_Start                         20
#define MWV207REG_TCS_CONTROL_OUTPUT_ATTRIBUTES_Type                         U06




#define mwv207regTCSOutputRegAddrs                                        0x5288
#define MWV207REG_TCS_OUTPUT_Address                                     0x14A20
#define MWV207REG_TCS_OUTPUT_MSB                                              15
#define MWV207REG_TCS_OUTPUT_LSB                                               3
#define MWV207REG_TCS_OUTPUT_BLK                                               3
#define MWV207REG_TCS_OUTPUT_Count                                             8
#define MWV207REG_TCS_OUTPUT_FieldMask                                0x3F3F3F3F
#define MWV207REG_TCS_OUTPUT_ReadMask                                 0x3F3F3F3F
#define MWV207REG_TCS_OUTPUT_WriteMask                                0x3F3F3F3F
#define MWV207REG_TCS_OUTPUT_ResetValue                               0x00000000

#define MWV207REG_TCS_OUTPUT_OUTPUT0                                         5:0
#define MWV207REG_TCS_OUTPUT_OUTPUT0_End                                       5
#define MWV207REG_TCS_OUTPUT_OUTPUT0_Start                                     0
#define MWV207REG_TCS_OUTPUT_OUTPUT0_Type                                    U06

#define MWV207REG_TCS_OUTPUT_OUTPUT1                                        13:8
#define MWV207REG_TCS_OUTPUT_OUTPUT1_End                                      13
#define MWV207REG_TCS_OUTPUT_OUTPUT1_Start                                     8
#define MWV207REG_TCS_OUTPUT_OUTPUT1_Type                                    U06

#define MWV207REG_TCS_OUTPUT_OUTPUT2                                       21:16
#define MWV207REG_TCS_OUTPUT_OUTPUT2_End                                      21
#define MWV207REG_TCS_OUTPUT_OUTPUT2_Start                                    16
#define MWV207REG_TCS_OUTPUT_OUTPUT2_Type                                    U06

#define MWV207REG_TCS_OUTPUT_OUTPUT3                                       29:24
#define MWV207REG_TCS_OUTPUT_OUTPUT3_End                                      29
#define MWV207REG_TCS_OUTPUT_OUTPUT3_Start                                    24
#define MWV207REG_TCS_OUTPUT_OUTPUT3_Type                                    U06




#define mwv207regTCSThrottleRegAddrs                                      0x5286
#define MWV207REG_TCS_THROTTLE_Address                                   0x14A18
#define MWV207REG_TCS_THROTTLE_MSB                                            15
#define MWV207REG_TCS_THROTTLE_LSB                                             0
#define MWV207REG_TCS_THROTTLE_BLK                                             0
#define MWV207REG_TCS_THROTTLE_Count                                           1
#define MWV207REG_TCS_THROTTLE_FieldMask                              0x03FFF03F
#define MWV207REG_TCS_THROTTLE_ReadMask                               0x03FFF03F
#define MWV207REG_TCS_THROTTLE_WriteMask                              0x03FFF03F
#define MWV207REG_TCS_THROTTLE_ResetValue                             0x00000000

#define MWV207REG_TCS_THROTTLE_MAX_PAGES                                     5:0
#define MWV207REG_TCS_THROTTLE_MAX_PAGES_End                                   5
#define MWV207REG_TCS_THROTTLE_MAX_PAGES_Start                                 0
#define MWV207REG_TCS_THROTTLE_MAX_PAGES_Type                                U06


#define MWV207REG_TCS_THROTTLE_MAX_PATCHES                                 19:12
#define MWV207REG_TCS_THROTTLE_MAX_PATCHES_End                                19
#define MWV207REG_TCS_THROTTLE_MAX_PATCHES_Start                              12
#define MWV207REG_TCS_THROTTLE_MAX_PATCHES_Type                              U08

#define MWV207REG_TCS_THROTTLE_MIN_PAGES                                   25:20
#define MWV207REG_TCS_THROTTLE_MIN_PAGES_End                                  25
#define MWV207REG_TCS_THROTTLE_MIN_PAGES_Start                                20
#define MWV207REG_TCS_THROTTLE_MIN_PAGES_Type                                U06



#define mwv207regTCSAttributeRegAddrs                                     0x5287
#define MWV207REG_TCS_ATTRIBUTE_Address                                  0x14A1C
#define MWV207REG_TCS_ATTRIBUTE_MSB                                           15
#define MWV207REG_TCS_ATTRIBUTE_LSB                                            0
#define MWV207REG_TCS_ATTRIBUTE_BLK                                            0
#define MWV207REG_TCS_ATTRIBUTE_Count                                          1
#define MWV207REG_TCS_ATTRIBUTE_FieldMask                             0xFFF7FF3F
#define MWV207REG_TCS_ATTRIBUTE_ReadMask                              0xFFF7FF3F
#define MWV207REG_TCS_ATTRIBUTE_WriteMask                             0xFFF7FF3F
#define MWV207REG_TCS_ATTRIBUTE_ResetValue                            0x00000000

#define MWV207REG_TCS_ATTRIBUTE_CONTROL_POINT_SIZE                           5:0
#define MWV207REG_TCS_ATTRIBUTE_CONTROL_POINT_SIZE_End                         5
#define MWV207REG_TCS_ATTRIBUTE_CONTROL_POINT_SIZE_Start                       0
#define MWV207REG_TCS_ATTRIBUTE_CONTROL_POINT_SIZE_Type                      U06

#define MWV207REG_TCS_ATTRIBUTE_PER_PATCH_OFFSET                            18:8
#define MWV207REG_TCS_ATTRIBUTE_PER_PATCH_OFFSET_End                          18
#define MWV207REG_TCS_ATTRIBUTE_PER_PATCH_OFFSET_Start                         8
#define MWV207REG_TCS_ATTRIBUTE_PER_PATCH_OFFSET_Type                        U11

#define MWV207REG_TCS_ATTRIBUTE_PATCH_SIZE                                 30:20
#define MWV207REG_TCS_ATTRIBUTE_PATCH_SIZE_End                                30
#define MWV207REG_TCS_ATTRIBUTE_PATCH_SIZE_Start                              20
#define MWV207REG_TCS_ATTRIBUTE_PATCH_SIZE_Type                              U11


#define MWV207REG_TCS_ATTRIBUTE_LAYOUT                                     31:31
#define MWV207REG_TCS_ATTRIBUTE_LAYOUT_End                                    31
#define MWV207REG_TCS_ATTRIBUTE_LAYOUT_Start                                  31
#define MWV207REG_TCS_ATTRIBUTE_LAYOUT_Type                                  U01

#define   MWV207REG_TCS_ATTRIBUTE_LAYOUT_INTERLEAVED                         0x0

#define   MWV207REG_TCS_ATTRIBUTE_LAYOUT_LINEAR                              0x1




#define mwv207regTCSAttributeExRegAddrs                                   0x5290
#define MWV207REG_TCS_ATTRIBUTE_EX_Address                               0x14A40
#define MWV207REG_TCS_ATTRIBUTE_EX_MSB                                        15
#define MWV207REG_TCS_ATTRIBUTE_EX_LSB                                         0
#define MWV207REG_TCS_ATTRIBUTE_EX_BLK                                         0
#define MWV207REG_TCS_ATTRIBUTE_EX_Count                                       1
#define MWV207REG_TCS_ATTRIBUTE_EX_FieldMask                          0x000007FF
#define MWV207REG_TCS_ATTRIBUTE_EX_ReadMask                           0x000007FF
#define MWV207REG_TCS_ATTRIBUTE_EX_WriteMask                          0x000007FF
#define MWV207REG_TCS_ATTRIBUTE_EX_ResetValue                         0x00000000

#define MWV207REG_TCS_ATTRIBUTE_EX_GROUP_SIZE                               10:0
#define MWV207REG_TCS_ATTRIBUTE_EX_GROUP_SIZE_End                             10
#define MWV207REG_TCS_ATTRIBUTE_EX_GROUP_SIZE_Start                            0
#define MWV207REG_TCS_ATTRIBUTE_EX_GROUP_SIZE_Type                           U11




#define mwv207regTCSUniformBaseRegAddrs                                   0x5291
#define MWV207REG_TCS_UNIFORM_BASE_Address                               0x14A44
#define MWV207REG_TCS_UNIFORM_BASE_MSB                                        15
#define MWV207REG_TCS_UNIFORM_BASE_LSB                                         0
#define MWV207REG_TCS_UNIFORM_BASE_BLK                                         0
#define MWV207REG_TCS_UNIFORM_BASE_Count                                       1
#define MWV207REG_TCS_UNIFORM_BASE_FieldMask                          0x000003FF
#define MWV207REG_TCS_UNIFORM_BASE_ReadMask                           0x000003FF
#define MWV207REG_TCS_UNIFORM_BASE_WriteMask                          0x000003FF
#define MWV207REG_TCS_UNIFORM_BASE_ResetValue                         0x00000000


#define MWV207REG_TCS_UNIFORM_BASE_OFFSET                                    9:0
#define MWV207REG_TCS_UNIFORM_BASE_OFFSET_End                                  9
#define MWV207REG_TCS_UNIFORM_BASE_OFFSET_Start                                0
#define MWV207REG_TCS_UNIFORM_BASE_OFFSET_Type                               U10



#define mwv207regTCSUniformLockRegAddrs                                   0x5292
#define MWV207REG_TCS_UNIFORM_LOCK_Address                               0x14A48
#define MWV207REG_TCS_UNIFORM_LOCK_MSB                                        15
#define MWV207REG_TCS_UNIFORM_LOCK_LSB                                         0
#define MWV207REG_TCS_UNIFORM_LOCK_BLK                                         0
#define MWV207REG_TCS_UNIFORM_LOCK_Count                                       1
#define MWV207REG_TCS_UNIFORM_LOCK_FieldMask                          0x000003FF
#define MWV207REG_TCS_UNIFORM_LOCK_ReadMask                           0x000003FF
#define MWV207REG_TCS_UNIFORM_LOCK_WriteMask                          0x000003FF
#define MWV207REG_TCS_UNIFORM_LOCK_ResetValue                         0x00000000


#define MWV207REG_TCS_UNIFORM_LOCK_OFFSET                                    9:0
#define MWV207REG_TCS_UNIFORM_LOCK_OFFSET_End                                  9
#define MWV207REG_TCS_UNIFORM_LOCK_OFFSET_Start                                0
#define MWV207REG_TCS_UNIFORM_LOCK_OFFSET_Type                               U10




#define mwv207regTCSSamplerBaseRegAddrs                                   0x5293
#define MWV207REG_TCS_SAMPLER_BASE_Address                               0x14A4C
#define MWV207REG_TCS_SAMPLER_BASE_MSB                                        15
#define MWV207REG_TCS_SAMPLER_BASE_LSB                                         0
#define MWV207REG_TCS_SAMPLER_BASE_BLK                                         0
#define MWV207REG_TCS_SAMPLER_BASE_Count                                       1
#define MWV207REG_TCS_SAMPLER_BASE_FieldMask                          0x03FF007F
#define MWV207REG_TCS_SAMPLER_BASE_ReadMask                           0x03FF007F
#define MWV207REG_TCS_SAMPLER_BASE_WriteMask                          0x03FF007F
#define MWV207REG_TCS_SAMPLER_BASE_ResetValue                         0x00000000


#define MWV207REG_TCS_SAMPLER_BASE_OFFSET                                    6:0
#define MWV207REG_TCS_SAMPLER_BASE_OFFSET_End                                  6
#define MWV207REG_TCS_SAMPLER_BASE_OFFSET_Start                                0
#define MWV207REG_TCS_SAMPLER_BASE_OFFSET_Type                               U07


#define MWV207REG_TCS_SAMPLER_BASE_TXD_OFFSET                              25:16
#define MWV207REG_TCS_SAMPLER_BASE_TXD_OFFSET_End                             25
#define MWV207REG_TCS_SAMPLER_BASE_TXD_OFFSET_Start                           16
#define MWV207REG_TCS_SAMPLER_BASE_TXD_OFFSET_Type                           U10



#define mwv207regTCSSamplerLockRegAddrs                                   0x5294
#define MWV207REG_TCS_SAMPLER_LOCK_Address                               0x14A50
#define MWV207REG_TCS_SAMPLER_LOCK_MSB                                        15
#define MWV207REG_TCS_SAMPLER_LOCK_LSB                                         0
#define MWV207REG_TCS_SAMPLER_LOCK_BLK                                         0
#define MWV207REG_TCS_SAMPLER_LOCK_Count                                       1
#define MWV207REG_TCS_SAMPLER_LOCK_FieldMask                          0x03FF007F
#define MWV207REG_TCS_SAMPLER_LOCK_ReadMask                           0x03FF007F
#define MWV207REG_TCS_SAMPLER_LOCK_WriteMask                          0x03FF007F
#define MWV207REG_TCS_SAMPLER_LOCK_ResetValue                         0x00000000


#define MWV207REG_TCS_SAMPLER_LOCK_OFFSET                                    6:0
#define MWV207REG_TCS_SAMPLER_LOCK_OFFSET_End                                  6
#define MWV207REG_TCS_SAMPLER_LOCK_OFFSET_Start                                0
#define MWV207REG_TCS_SAMPLER_LOCK_OFFSET_Type                               U07


#define MWV207REG_TCS_SAMPLER_LOCK_TXD_OFFSET                              25:16
#define MWV207REG_TCS_SAMPLER_LOCK_TXD_OFFSET_End                             25
#define MWV207REG_TCS_SAMPLER_LOCK_TXD_OFFSET_Start                           16
#define MWV207REG_TCS_SAMPLER_LOCK_TXD_OFFSET_Type                           U10




#define mwv207regTCSAttributeGlobalControlRegAddrs                        0x5295
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_Address                   0x14A54
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MSB                            15
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_LSB                             0
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_BLK                             0
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_Count                           1
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_FieldMask              0xFFFFF0F1
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ReadMask               0xFFFFF0F1
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_WriteMask              0xFFFFF0F1
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ResetValue             0x00000000


#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM              0:0
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_End            0
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Start          0
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Type         U01
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_DISABLED   0x0
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_ENABLED    0x1


#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER          7:4
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_End        7
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Start      4
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Type     U04
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS1K   0x0
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS2K   0x1
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS4K   0x2
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS8K   0x3
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS16K  0x4
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS32K  0x5
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS64K  0x6
#define   MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS128K 0x7


#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR                   31:12
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_End                  31
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Start                12
#define MWV207REG_TCS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Type                U20





#define mwv207regTPGControlRegAddrs                                       0x52C0
#define MWV207REG_TPG_CONTROL_Address                                    0x14B00
#define MWV207REG_TPG_CONTROL_MSB                                             15
#define MWV207REG_TPG_CONTROL_LSB                                              0
#define MWV207REG_TPG_CONTROL_BLK                                              0
#define MWV207REG_TPG_CONTROL_Count                                            1
#define MWV207REG_TPG_CONTROL_FieldMask                               0x17F7F333
#define MWV207REG_TPG_CONTROL_ReadMask                                0x17F7F333
#define MWV207REG_TPG_CONTROL_WriteMask                               0x17F7F333
#define MWV207REG_TPG_CONTROL_ResetValue                              0x00040000


#define MWV207REG_TPG_CONTROL_MODE                                           1:0
#define MWV207REG_TPG_CONTROL_MODE_End                                         1
#define MWV207REG_TPG_CONTROL_MODE_Start                                       0
#define MWV207REG_TPG_CONTROL_MODE_Type                                      U02

#define   MWV207REG_TPG_CONTROL_MODE_TRIANGLE                                0x0

#define   MWV207REG_TPG_CONTROL_MODE_QUAD                                    0x1

#define   MWV207REG_TPG_CONTROL_MODE_ISO_LINE                                0x2

#define MWV207REG_TPG_CONTROL_SPACING                                        5:4
#define MWV207REG_TPG_CONTROL_SPACING_End                                      5
#define MWV207REG_TPG_CONTROL_SPACING_Start                                    4
#define MWV207REG_TPG_CONTROL_SPACING_Type                                   U02

#define   MWV207REG_TPG_CONTROL_SPACING_EQUAL                                0x0

#define   MWV207REG_TPG_CONTROL_SPACING_POWER_OF_TWO                         0x1

#define   MWV207REG_TPG_CONTROL_SPACING_FRACTIONAL_ODD                       0x2

#define   MWV207REG_TPG_CONTROL_SPACING_FRACTIONAL_EVEN                      0x3


#define MWV207REG_TPG_CONTROL_TOPOLOGY                                       9:8
#define MWV207REG_TPG_CONTROL_TOPOLOGY_End                                     9
#define MWV207REG_TPG_CONTROL_TOPOLOGY_Start                                   8
#define MWV207REG_TPG_CONTROL_TOPOLOGY_Type                                  U02

#define   MWV207REG_TPG_CONTROL_TOPOLOGY_POINT                               0x0

#define   MWV207REG_TPG_CONTROL_TOPOLOGY_LINE                                0x1

#define   MWV207REG_TPG_CONTROL_TOPOLOGY_TRIANGLE_CW                         0x2

#define   MWV207REG_TPG_CONTROL_TOPOLOGY_TRIANGLE_CCW                        0x3


#define MWV207REG_TPG_CONTROL_MAX_FACTOR                                   18:12
#define MWV207REG_TPG_CONTROL_MAX_FACTOR_End                                  18
#define MWV207REG_TPG_CONTROL_MAX_FACTOR_Start                                12
#define MWV207REG_TPG_CONTROL_MAX_FACTOR_Type                                U07

#define MWV207REG_TPG_CONTROL_THRESHOLD                                    26:20
#define MWV207REG_TPG_CONTROL_THRESHOLD_End                                   26
#define MWV207REG_TPG_CONTROL_THRESHOLD_Start                                 20
#define MWV207REG_TPG_CONTROL_THRESHOLD_Type                                 U07


#define MWV207REG_TPG_CONTROL_FORCE_TRIVIAL_TESSELLATION                   28:28
#define MWV207REG_TPG_CONTROL_FORCE_TRIVIAL_TESSELLATION_End                  28
#define MWV207REG_TPG_CONTROL_FORCE_TRIVIAL_TESSELLATION_Start                28
#define MWV207REG_TPG_CONTROL_FORCE_TRIVIAL_TESSELLATION_Type                U01
#define   MWV207REG_TPG_CONTROL_FORCE_TRIVIAL_TESSELLATION_DISABLED          0x0
#define   MWV207REG_TPG_CONTROL_FORCE_TRIVIAL_TESSELLATION_ENABLED           0x1




#define mwv207regTESStartRegAddrs                                         0x52C1
#define MWV207REG_TES_START_Address                                      0x14B04
#define MWV207REG_TES_START_MSB                                               15
#define MWV207REG_TES_START_LSB                                                0
#define MWV207REG_TES_START_BLK                                                0
#define MWV207REG_TES_START_Count                                              1
#define MWV207REG_TES_START_FieldMask                                 0x000FFFFF
#define MWV207REG_TES_START_ReadMask                                  0x000FFFFF
#define MWV207REG_TES_START_WriteMask                                 0x000FFFFF
#define MWV207REG_TES_START_ResetValue                                0x00000000


#define MWV207REG_TES_START_PC                                              19:0
#define MWV207REG_TES_START_PC_End                                            19
#define MWV207REG_TES_START_PC_Start                                           0
#define MWV207REG_TES_START_PC_Type                                          U20




#define mwv207regTESRelativeEndRegAddrs                                   0x52C2
#define MWV207REG_TES_RELATIVE_END_Address                               0x14B08
#define MWV207REG_TES_RELATIVE_END_MSB                                        15
#define MWV207REG_TES_RELATIVE_END_LSB                                         0
#define MWV207REG_TES_RELATIVE_END_BLK                                         0
#define MWV207REG_TES_RELATIVE_END_Count                                       1
#define MWV207REG_TES_RELATIVE_END_FieldMask                          0x001FFFFF
#define MWV207REG_TES_RELATIVE_END_ReadMask                           0x001FFFFF
#define MWV207REG_TES_RELATIVE_END_WriteMask                          0x001FFFFF
#define MWV207REG_TES_RELATIVE_END_ResetValue                         0x00000000

#define MWV207REG_TES_RELATIVE_END_PC                                       20:0
#define MWV207REG_TES_RELATIVE_END_PC_End                                     20
#define MWV207REG_TES_RELATIVE_END_PC_Start                                    0
#define MWV207REG_TES_RELATIVE_END_PC_Type                                   U21



#define mwv207regTESInstructionRegAddrs                                   0x52C3
#define MWV207REG_TES_INSTRUCTION_Address                                0x14B0C
#define MWV207REG_TES_INSTRUCTION_MSB                                         15
#define MWV207REG_TES_INSTRUCTION_LSB                                          0
#define MWV207REG_TES_INSTRUCTION_BLK                                          0
#define MWV207REG_TES_INSTRUCTION_Count                                        1
#define MWV207REG_TES_INSTRUCTION_FieldMask                           0xFFFFFFFF
#define MWV207REG_TES_INSTRUCTION_ReadMask                            0xFFFFFF00
#define MWV207REG_TES_INSTRUCTION_WriteMask                           0xFFFFFF00
#define MWV207REG_TES_INSTRUCTION_ResetValue                          0x00000000


#define MWV207REG_TES_INSTRUCTION_ADDRESS                                   31:0
#define MWV207REG_TES_INSTRUCTION_ADDRESS_End                                 31
#define MWV207REG_TES_INSTRUCTION_ADDRESS_Start                                0
#define MWV207REG_TES_INSTRUCTION_ADDRESS_Type                               U32




#define mwv207regTESInstructionPrefetchRegAddrs                           0x52C4
#define MWV207REG_TES_INSTRUCTION_PREFETCH_Address                       0x14B10
#define MWV207REG_TES_INSTRUCTION_PREFETCH_MSB                                15
#define MWV207REG_TES_INSTRUCTION_PREFETCH_LSB                                 0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_BLK                                 0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_Count                               1
#define MWV207REG_TES_INSTRUCTION_PREFETCH_FieldMask                  0x000FFFFF
#define MWV207REG_TES_INSTRUCTION_PREFETCH_ReadMask                   0x000FFFFF
#define MWV207REG_TES_INSTRUCTION_PREFETCH_WriteMask                  0x000FFFFF
#define MWV207REG_TES_INSTRUCTION_PREFETCH_ResetValue                 0x00000000

#define MWV207REG_TES_INSTRUCTION_PREFETCH_PC                               19:0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_PC_End                             19
#define MWV207REG_TES_INSTRUCTION_PREFETCH_PC_Start                            0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_PC_Type                           U20



#define mwv207regTESInstructionPrefetchRelativeEndRegAddrs                0x52C5
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_Address          0x14B14
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_MSB                   15
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_LSB                    0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_BLK                    0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_Count                  1
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_FieldMask     0x000FFFFF
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_ReadMask      0x000FFFFF
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_WriteMask     0x000FFFFF
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_ResetValue    0x00000000

#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_PC                  19:0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_PC_End                19
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Start               0
#define MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Type              U20




#define mwv207regTESControlRegAddrs                                       0x52C6
#define MWV207REG_TES_CONTROL_Address                                    0x14B18
#define MWV207REG_TES_CONTROL_MSB                                             15
#define MWV207REG_TES_CONTROL_LSB                                              0
#define MWV207REG_TES_CONTROL_BLK                                              0
#define MWV207REG_TES_CONTROL_Count                                            1
#define MWV207REG_TES_CONTROL_FieldMask                               0x0007F3F1
#define MWV207REG_TES_CONTROL_ReadMask                                0x0007F3F1
#define MWV207REG_TES_CONTROL_WriteMask                               0x0007F3F1
#define MWV207REG_TES_CONTROL_ResetValue                              0x00000000


#define MWV207REG_TES_CONTROL_EXECUTION                                      0:0
#define MWV207REG_TES_CONTROL_EXECUTION_End                                    0
#define MWV207REG_TES_CONTROL_EXECUTION_Start                                  0
#define MWV207REG_TES_CONTROL_EXECUTION_Type                                 U01

#define   MWV207REG_TES_CONTROL_EXECUTION_SKIPPED                            0x0

#define   MWV207REG_TES_CONTROL_EXECUTION_EXECUTE                            0x1


#define MWV207REG_TES_CONTROL_OUTPUT_ATTRIBUTES                              9:4
#define MWV207REG_TES_CONTROL_OUTPUT_ATTRIBUTES_End                            9
#define MWV207REG_TES_CONTROL_OUTPUT_ATTRIBUTES_Start                          4
#define MWV207REG_TES_CONTROL_OUTPUT_ATTRIBUTES_Type                         U06


#define MWV207REG_TES_CONTROL_TEMP_COUNT                                   18:12
#define MWV207REG_TES_CONTROL_TEMP_COUNT_End                                  18
#define MWV207REG_TES_CONTROL_TEMP_COUNT_Start                                12
#define MWV207REG_TES_CONTROL_TEMP_COUNT_Type                                U07




#define mwv207regTESThrottleRegAddrs                                      0x52C7
#define MWV207REG_TES_THROTTLE_Address                                   0x14B1C
#define MWV207REG_TES_THROTTLE_MSB                                            15
#define MWV207REG_TES_THROTTLE_LSB                                             0
#define MWV207REG_TES_THROTTLE_BLK                                             0
#define MWV207REG_TES_THROTTLE_Count                                           1
#define MWV207REG_TES_THROTTLE_FieldMask                              0x1FFFF03F
#define MWV207REG_TES_THROTTLE_ReadMask                               0x1FFFF03F
#define MWV207REG_TES_THROTTLE_WriteMask                              0x1FFFF03F
#define MWV207REG_TES_THROTTLE_ResetValue                             0x00000000

#define MWV207REG_TES_THROTTLE_MAX_PAGES                                     5:0
#define MWV207REG_TES_THROTTLE_MAX_PAGES_End                                   5
#define MWV207REG_TES_THROTTLE_MAX_PAGES_Start                                 0
#define MWV207REG_TES_THROTTLE_MAX_PAGES_Type                                U06


#define MWV207REG_TES_THROTTLE_MAX_THREADS                                 19:12
#define MWV207REG_TES_THROTTLE_MAX_THREADS_End                                19
#define MWV207REG_TES_THROTTLE_MAX_THREADS_Start                              12
#define MWV207REG_TES_THROTTLE_MAX_THREADS_Type                              U08

#define MWV207REG_TES_THROTTLE_RESULT_WINDOW_SIZE                          28:20
#define MWV207REG_TES_THROTTLE_RESULT_WINDOW_SIZE_End                         28
#define MWV207REG_TES_THROTTLE_RESULT_WINDOW_SIZE_Start                       20
#define MWV207REG_TES_THROTTLE_RESULT_WINDOW_SIZE_Type                       U09



#define mwv207regTESAttributeRegAddrs                                     0x52C8
#define MWV207REG_TES_ATTRIBUTE_Address                                  0x14B20
#define MWV207REG_TES_ATTRIBUTE_MSB                                           15
#define MWV207REG_TES_ATTRIBUTE_LSB                                            0
#define MWV207REG_TES_ATTRIBUTE_BLK                                            0
#define MWV207REG_TES_ATTRIBUTE_Count                                          1
#define MWV207REG_TES_ATTRIBUTE_FieldMask                             0x0007FF3F
#define MWV207REG_TES_ATTRIBUTE_ReadMask                              0x0007FF3F
#define MWV207REG_TES_ATTRIBUTE_WriteMask                             0x0007FF3F
#define MWV207REG_TES_ATTRIBUTE_ResetValue                            0x00000000

#define MWV207REG_TES_ATTRIBUTE_VERTEX_SIZE                                  5:0
#define MWV207REG_TES_ATTRIBUTE_VERTEX_SIZE_End                                5
#define MWV207REG_TES_ATTRIBUTE_VERTEX_SIZE_Start                              0
#define MWV207REG_TES_ATTRIBUTE_VERTEX_SIZE_Type                             U06

#define MWV207REG_TES_ATTRIBUTE_GROUP_SIZE                                  18:8
#define MWV207REG_TES_ATTRIBUTE_GROUP_SIZE_End                                18
#define MWV207REG_TES_ATTRIBUTE_GROUP_SIZE_Start                               8
#define MWV207REG_TES_ATTRIBUTE_GROUP_SIZE_Type                              U11




#define mwv207regTESOutputRegAddrs                                        0x52D0
#define MWV207REG_TES_OUTPUT_Address                                     0x14B40
#define MWV207REG_TES_OUTPUT_MSB                                              15
#define MWV207REG_TES_OUTPUT_LSB                                               3
#define MWV207REG_TES_OUTPUT_BLK                                               3
#define MWV207REG_TES_OUTPUT_Count                                             8
#define MWV207REG_TES_OUTPUT_FieldMask                                0x3F3F3F3F
#define MWV207REG_TES_OUTPUT_ReadMask                                 0x3F3F3F3F
#define MWV207REG_TES_OUTPUT_WriteMask                                0x3F3F3F3F
#define MWV207REG_TES_OUTPUT_ResetValue                               0x00000000


#define MWV207REG_TES_OUTPUT_OUTPUT0                                         5:0
#define MWV207REG_TES_OUTPUT_OUTPUT0_End                                       5
#define MWV207REG_TES_OUTPUT_OUTPUT0_Start                                     0
#define MWV207REG_TES_OUTPUT_OUTPUT0_Type                                    U06


#define MWV207REG_TES_OUTPUT_OUTPUT1                                        13:8
#define MWV207REG_TES_OUTPUT_OUTPUT1_End                                      13
#define MWV207REG_TES_OUTPUT_OUTPUT1_Start                                     8
#define MWV207REG_TES_OUTPUT_OUTPUT1_Type                                    U06


#define MWV207REG_TES_OUTPUT_OUTPUT2                                       21:16
#define MWV207REG_TES_OUTPUT_OUTPUT2_End                                      21
#define MWV207REG_TES_OUTPUT_OUTPUT2_Start                                    16
#define MWV207REG_TES_OUTPUT_OUTPUT2_Type                                    U06


#define MWV207REG_TES_OUTPUT_OUTPUT3                                       29:24
#define MWV207REG_TES_OUTPUT_OUTPUT3_End                                      29
#define MWV207REG_TES_OUTPUT_OUTPUT3_Start                                    24
#define MWV207REG_TES_OUTPUT_OUTPUT3_Type                                    U06




#define mwv207regTESUniformBaseRegAddrs                                   0x52C9
#define MWV207REG_TES_UNIFORM_BASE_Address                               0x14B24
#define MWV207REG_TES_UNIFORM_BASE_MSB                                        15
#define MWV207REG_TES_UNIFORM_BASE_LSB                                         0
#define MWV207REG_TES_UNIFORM_BASE_BLK                                         0
#define MWV207REG_TES_UNIFORM_BASE_Count                                       1
#define MWV207REG_TES_UNIFORM_BASE_FieldMask                          0x000003FF
#define MWV207REG_TES_UNIFORM_BASE_ReadMask                           0x000003FF
#define MWV207REG_TES_UNIFORM_BASE_WriteMask                          0x000003FF
#define MWV207REG_TES_UNIFORM_BASE_ResetValue                         0x00000000


#define MWV207REG_TES_UNIFORM_BASE_OFFSET                                    9:0
#define MWV207REG_TES_UNIFORM_BASE_OFFSET_End                                  9
#define MWV207REG_TES_UNIFORM_BASE_OFFSET_Start                                0
#define MWV207REG_TES_UNIFORM_BASE_OFFSET_Type                               U10



#define mwv207regTESUniformLockRegAddrs                                   0x52CA
#define MWV207REG_TES_UNIFORM_LOCK_Address                               0x14B28
#define MWV207REG_TES_UNIFORM_LOCK_MSB                                        15
#define MWV207REG_TES_UNIFORM_LOCK_LSB                                         0
#define MWV207REG_TES_UNIFORM_LOCK_BLK                                         0
#define MWV207REG_TES_UNIFORM_LOCK_Count                                       1
#define MWV207REG_TES_UNIFORM_LOCK_FieldMask                          0x000003FF
#define MWV207REG_TES_UNIFORM_LOCK_ReadMask                           0x000003FF
#define MWV207REG_TES_UNIFORM_LOCK_WriteMask                          0x000003FF
#define MWV207REG_TES_UNIFORM_LOCK_ResetValue                         0x00000000


#define MWV207REG_TES_UNIFORM_LOCK_OFFSET                                    9:0
#define MWV207REG_TES_UNIFORM_LOCK_OFFSET_End                                  9
#define MWV207REG_TES_UNIFORM_LOCK_OFFSET_Start                                0
#define MWV207REG_TES_UNIFORM_LOCK_OFFSET_Type                               U10




#define mwv207regTESSamplerBaseRegAddrs                                   0x52CB
#define MWV207REG_TES_SAMPLER_BASE_Address                               0x14B2C
#define MWV207REG_TES_SAMPLER_BASE_MSB                                        15
#define MWV207REG_TES_SAMPLER_BASE_LSB                                         0
#define MWV207REG_TES_SAMPLER_BASE_BLK                                         0
#define MWV207REG_TES_SAMPLER_BASE_Count                                       1
#define MWV207REG_TES_SAMPLER_BASE_FieldMask                          0x03FF007F
#define MWV207REG_TES_SAMPLER_BASE_ReadMask                           0x03FF007F
#define MWV207REG_TES_SAMPLER_BASE_WriteMask                          0x03FF007F
#define MWV207REG_TES_SAMPLER_BASE_ResetValue                         0x00000000


#define MWV207REG_TES_SAMPLER_BASE_OFFSET                                    6:0
#define MWV207REG_TES_SAMPLER_BASE_OFFSET_End                                  6
#define MWV207REG_TES_SAMPLER_BASE_OFFSET_Start                                0
#define MWV207REG_TES_SAMPLER_BASE_OFFSET_Type                               U07


#define MWV207REG_TES_SAMPLER_BASE_TXD_OFFSET                              25:16
#define MWV207REG_TES_SAMPLER_BASE_TXD_OFFSET_End                             25
#define MWV207REG_TES_SAMPLER_BASE_TXD_OFFSET_Start                           16
#define MWV207REG_TES_SAMPLER_BASE_TXD_OFFSET_Type                           U10



#define mwv207regTESSamplerLockRegAddrs                                   0x52CC
#define MWV207REG_TES_SAMPLER_LOCK_Address                               0x14B30
#define MWV207REG_TES_SAMPLER_LOCK_MSB                                        15
#define MWV207REG_TES_SAMPLER_LOCK_LSB                                         0
#define MWV207REG_TES_SAMPLER_LOCK_BLK                                         0
#define MWV207REG_TES_SAMPLER_LOCK_Count                                       1
#define MWV207REG_TES_SAMPLER_LOCK_FieldMask                          0x03FF007F
#define MWV207REG_TES_SAMPLER_LOCK_ReadMask                           0x03FF007F
#define MWV207REG_TES_SAMPLER_LOCK_WriteMask                          0x03FF007F
#define MWV207REG_TES_SAMPLER_LOCK_ResetValue                         0x00000000


#define MWV207REG_TES_SAMPLER_LOCK_OFFSET                                    6:0
#define MWV207REG_TES_SAMPLER_LOCK_OFFSET_End                                  6
#define MWV207REG_TES_SAMPLER_LOCK_OFFSET_Start                                0
#define MWV207REG_TES_SAMPLER_LOCK_OFFSET_Type                               U07


#define MWV207REG_TES_SAMPLER_LOCK_TXD_OFFSET                              25:16
#define MWV207REG_TES_SAMPLER_LOCK_TXD_OFFSET_End                             25
#define MWV207REG_TES_SAMPLER_LOCK_TXD_OFFSET_Start                           16
#define MWV207REG_TES_SAMPLER_LOCK_TXD_OFFSET_Type                           U10




#define mwv207regTESThrottleExRegAddrs                                    0x52CD
#define MWV207REG_TES_THROTTLE_EX_Address                                0x14B34
#define MWV207REG_TES_THROTTLE_EX_MSB                                         15
#define MWV207REG_TES_THROTTLE_EX_LSB                                          0
#define MWV207REG_TES_THROTTLE_EX_BLK                                          0
#define MWV207REG_TES_THROTTLE_EX_Count                                        1
#define MWV207REG_TES_THROTTLE_EX_FieldMask                           0x00003FFF
#define MWV207REG_TES_THROTTLE_EX_ReadMask                            0x00003FFF
#define MWV207REG_TES_THROTTLE_EX_WriteMask                           0x00003FFF
#define MWV207REG_TES_THROTTLE_EX_ResetValue                          0x00000000


#define MWV207REG_TES_THROTTLE_EX_MAX_PATCHES                                7:0
#define MWV207REG_TES_THROTTLE_EX_MAX_PATCHES_End                              7
#define MWV207REG_TES_THROTTLE_EX_MAX_PATCHES_Start                            0
#define MWV207REG_TES_THROTTLE_EX_MAX_PATCHES_Type                           U08

#define MWV207REG_TES_THROTTLE_EX_MIN_PAGES                                 13:8
#define MWV207REG_TES_THROTTLE_EX_MIN_PAGES_End                               13
#define MWV207REG_TES_THROTTLE_EX_MIN_PAGES_Start                              8
#define MWV207REG_TES_THROTTLE_EX_MIN_PAGES_Type                             U06




#define mwv207regTESAttributeGlobalControlRegAddrs                        0x52CE
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_Address                   0x14B38
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MSB                            15
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_LSB                             0
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_BLK                             0
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_Count                           1
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_FieldMask              0xFFFFF0F1
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ReadMask               0xFFFFF0F1
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_WriteMask              0xFFFFF0F1
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ResetValue             0x00000000


#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM              0:0
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_End            0
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Start          0
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Type         U01
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_DISABLED   0x0
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_ENABLED    0x1


#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER          7:4
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_End        7
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Start      4
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Type     U04
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS1K   0x0
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS2K   0x1
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS4K   0x2
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS8K   0x3
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS16K  0x4
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS32K  0x5
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS64K  0x6
#define   MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS128K 0x7


#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR                   31:12
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_End                  31
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Start                12
#define MWV207REG_TES_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Type                U20


#endif


