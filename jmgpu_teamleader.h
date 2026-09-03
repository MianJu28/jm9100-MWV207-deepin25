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




#ifndef __jmgpuregMMU_h__
#define __jmgpuregMMU_h__




#define mwv207regMMUSafeAddressRegAddrs                                   0x0060
#define MWV207REG_MMU_SAFE_ADDRESS_Address                               0x00180
#define MWV207REG_MMU_SAFE_ADDRESS_MSB                                        15
#define MWV207REG_MMU_SAFE_ADDRESS_LSB                                         0
#define MWV207REG_MMU_SAFE_ADDRESS_BLK                                         0
#define MWV207REG_MMU_SAFE_ADDRESS_Count                                       1
#define MWV207REG_MMU_SAFE_ADDRESS_FieldMask                          0xFFFFFFFF
#define MWV207REG_MMU_SAFE_ADDRESS_ReadMask                           0xFFFFFFC0
#define MWV207REG_MMU_SAFE_ADDRESS_WriteMask                          0xFFFFFFC0
#define MWV207REG_MMU_SAFE_ADDRESS_ResetValue                         0x00000000


#define MWV207REG_MMU_SAFE_ADDRESS_ADDRESS                                  31:0
#define MWV207REG_MMU_SAFE_ADDRESS_ADDRESS_End                                31
#define MWV207REG_MMU_SAFE_ADDRESS_ADDRESS_Start                               0
#define MWV207REG_MMU_SAFE_ADDRESS_ADDRESS_Type                              U32



#define mwv207regMMUExceptionRegAddrs                                     0x0064
#define MWV207REG_MMU_EXCEPTION_Address                                  0x00190
#define MWV207REG_MMU_EXCEPTION_MSB                                           15
#define MWV207REG_MMU_EXCEPTION_LSB                                            2
#define MWV207REG_MMU_EXCEPTION_BLK                                            2
#define MWV207REG_MMU_EXCEPTION_Count                                          4
#define MWV207REG_MMU_EXCEPTION_FieldMask                             0xFFFFFFFF
#define MWV207REG_MMU_EXCEPTION_ReadMask                              0xFFFFFFFF
#define MWV207REG_MMU_EXCEPTION_WriteMask                             0xFFFFFFFF
#define MWV207REG_MMU_EXCEPTION_ResetValue                            0x00000000


#define MWV207REG_MMU_EXCEPTION_ADDRESS                                     31:0
#define MWV207REG_MMU_EXCEPTION_ADDRESS_End                                   31
#define MWV207REG_MMU_EXCEPTION_ADDRESS_Start                                  0
#define MWV207REG_MMU_EXCEPTION_ADDRESS_Type                                 U32



#define mwv207regMMUConfigurationRegAddrs                                 0x0061
#define MWV207REG_MMU_CONFIGURATION_Address                              0x00184
#define MWV207REG_MMU_CONFIGURATION_MSB                                       15
#define MWV207REG_MMU_CONFIGURATION_LSB                                        0
#define MWV207REG_MMU_CONFIGURATION_BLK                                        0
#define MWV207REG_MMU_CONFIGURATION_Count                                      1
#define MWV207REG_MMU_CONFIGURATION_FieldMask                         0xFFFFFD99
#define MWV207REG_MMU_CONFIGURATION_ReadMask                          0xFFFFFD99
#define MWV207REG_MMU_CONFIGURATION_WriteMask                         0xFFFFFD99
#define MWV207REG_MMU_CONFIGURATION_ResetValue                        0x00000000


#define MWV207REG_MMU_CONFIGURATION_MODE                                     0:0
#define MWV207REG_MMU_CONFIGURATION_MODE_End                                   0
#define MWV207REG_MMU_CONFIGURATION_MODE_Start                                 0
#define MWV207REG_MMU_CONFIGURATION_MODE_Type                                U01
#define   MWV207REG_MMU_CONFIGURATION_MODE_MODE4_K                           0x0
#define   MWV207REG_MMU_CONFIGURATION_MODE_MODE1_K                           0x1


#define MWV207REG_MMU_CONFIGURATION_MASK_MODE                                3:3
#define MWV207REG_MMU_CONFIGURATION_MASK_MODE_End                              3
#define MWV207REG_MMU_CONFIGURATION_MASK_MODE_Start                            3
#define MWV207REG_MMU_CONFIGURATION_MASK_MODE_Type                           U01
#define   MWV207REG_MMU_CONFIGURATION_MASK_MODE_ENABLED                      0x0
#define   MWV207REG_MMU_CONFIGURATION_MASK_MODE_MASKED                       0x1


#define MWV207REG_MMU_CONFIGURATION_FLUSH                                    4:4
#define MWV207REG_MMU_CONFIGURATION_FLUSH_End                                  4
#define MWV207REG_MMU_CONFIGURATION_FLUSH_Start                                4
#define MWV207REG_MMU_CONFIGURATION_FLUSH_Type                               U01
#define   MWV207REG_MMU_CONFIGURATION_FLUSH_FLUSH                            0x1


#define MWV207REG_MMU_CONFIGURATION_MASK_FLUSH                               7:7
#define MWV207REG_MMU_CONFIGURATION_MASK_FLUSH_End                             7
#define MWV207REG_MMU_CONFIGURATION_MASK_FLUSH_Start                           7
#define MWV207REG_MMU_CONFIGURATION_MASK_FLUSH_Type                          U01
#define   MWV207REG_MMU_CONFIGURATION_MASK_FLUSH_ENABLED                     0x0
#define   MWV207REG_MMU_CONFIGURATION_MASK_FLUSH_MASKED                      0x1


#define MWV207REG_MMU_CONFIGURATION_MASK_ADDRESS                             8:8
#define MWV207REG_MMU_CONFIGURATION_MASK_ADDRESS_End                           8
#define MWV207REG_MMU_CONFIGURATION_MASK_ADDRESS_Start                         8
#define MWV207REG_MMU_CONFIGURATION_MASK_ADDRESS_Type                        U01
#define   MWV207REG_MMU_CONFIGURATION_MASK_ADDRESS_ENABLED                   0x0
#define   MWV207REG_MMU_CONFIGURATION_MASK_ADDRESS_MASKED                    0x1

#define MWV207REG_MMU_CONFIGURATION_ADDRESS                                31:10
#define MWV207REG_MMU_CONFIGURATION_ADDRESS_End                               31
#define MWV207REG_MMU_CONFIGURATION_ADDRESS_Start                             10
#define MWV207REG_MMU_CONFIGURATION_ADDRESS_Type                             U22



#define mwv207regMMUStatusRegAddrs                                        0x0062
#define MWV207REG_MMU_STATUS_Address                                     0x00188
#define MWV207REG_MMU_STATUS_MSB                                              15
#define MWV207REG_MMU_STATUS_LSB                                               0
#define MWV207REG_MMU_STATUS_BLK                                               0
#define MWV207REG_MMU_STATUS_Count                                             1
#define MWV207REG_MMU_STATUS_FieldMask                                0x00007777
#define MWV207REG_MMU_STATUS_ReadMask                                 0x00007777
#define MWV207REG_MMU_STATUS_WriteMask                                0x00000000
#define MWV207REG_MMU_STATUS_ResetValue                               0x00000000

#define MWV207REG_MMU_STATUS_EXCEPTION0                                      2:0
#define MWV207REG_MMU_STATUS_EXCEPTION0_End                                    2
#define MWV207REG_MMU_STATUS_EXCEPTION0_Start                                  0
#define MWV207REG_MMU_STATUS_EXCEPTION0_Type                                 U03
#define   MWV207REG_MMU_STATUS_EXCEPTION0_SLAVE_NOT_PRESENT                  0x1
#define   MWV207REG_MMU_STATUS_EXCEPTION0_PAGE_NOT_PRESENT                   0x2
#define   MWV207REG_MMU_STATUS_EXCEPTION0_WRITE_VIOLATION                    0x3
#define   MWV207REG_MMU_STATUS_EXCEPTION0_OUT_OF_BOUND                       0x4
#define   MWV207REG_MMU_STATUS_EXCEPTION0_READ_SECURITY_VIOLATION            0x5
#define   MWV207REG_MMU_STATUS_EXCEPTION0_WRITE_SECURITY_VIOLATION           0x6

#define MWV207REG_MMU_STATUS_EXCEPTION1                                      6:4
#define MWV207REG_MMU_STATUS_EXCEPTION1_End                                    6
#define MWV207REG_MMU_STATUS_EXCEPTION1_Start                                  4
#define MWV207REG_MMU_STATUS_EXCEPTION1_Type                                 U03
#define   MWV207REG_MMU_STATUS_EXCEPTION1_SLAVE_NOT_PRESENT                  0x1
#define   MWV207REG_MMU_STATUS_EXCEPTION1_PAGE_NOT_PRESENT                   0x2
#define   MWV207REG_MMU_STATUS_EXCEPTION1_WRITE_VIOLATION                    0x3
#define   MWV207REG_MMU_STATUS_EXCEPTION1_OUT_OF_BOUND                       0x4
#define   MWV207REG_MMU_STATUS_EXCEPTION1_READ_SECURITY_VIOLATION            0x5
#define   MWV207REG_MMU_STATUS_EXCEPTION1_WRITE_SECURITY_VIOLATION           0x6

#define MWV207REG_MMU_STATUS_EXCEPTION2                                     10:8
#define MWV207REG_MMU_STATUS_EXCEPTION2_End                                   10
#define MWV207REG_MMU_STATUS_EXCEPTION2_Start                                  8
#define MWV207REG_MMU_STATUS_EXCEPTION2_Type                                 U03
#define   MWV207REG_MMU_STATUS_EXCEPTION2_SLAVE_NOT_PRESENT                  0x1
#define   MWV207REG_MMU_STATUS_EXCEPTION2_PAGE_NOT_PRESENT                   0x2
#define   MWV207REG_MMU_STATUS_EXCEPTION2_WRITE_VIOLATION                    0x3
#define   MWV207REG_MMU_STATUS_EXCEPTION2_OUT_OF_BOUND                       0x4
#define   MWV207REG_MMU_STATUS_EXCEPTION2_READ_SECURITY_VIOLATION            0x5
#define   MWV207REG_MMU_STATUS_EXCEPTION2_WRITE_SECURITY_VIOLATION           0x6

#define MWV207REG_MMU_STATUS_EXCEPTION3                                    14:12
#define MWV207REG_MMU_STATUS_EXCEPTION3_End                                   14
#define MWV207REG_MMU_STATUS_EXCEPTION3_Start                                 12
#define MWV207REG_MMU_STATUS_EXCEPTION3_Type                                 U03
#define   MWV207REG_MMU_STATUS_EXCEPTION3_SLAVE_NOT_PRESENT                  0x1
#define   MWV207REG_MMU_STATUS_EXCEPTION3_PAGE_NOT_PRESENT                   0x2
#define   MWV207REG_MMU_STATUS_EXCEPTION3_WRITE_VIOLATION                    0x3
#define   MWV207REG_MMU_STATUS_EXCEPTION3_OUT_OF_BOUND                       0x4
#define   MWV207REG_MMU_STATUS_EXCEPTION3_READ_SECURITY_VIOLATION            0x5
#define   MWV207REG_MMU_STATUS_EXCEPTION3_WRITE_SECURITY_VIOLATION           0x6



#define mwv207regMMUControlRegAddrs                                       0x0063
#define MWV207REG_MMU_CONTROL_Address                                    0x0018C
#define MWV207REG_MMU_CONTROL_MSB                                             15
#define MWV207REG_MMU_CONTROL_LSB                                              0
#define MWV207REG_MMU_CONTROL_BLK                                              0
#define MWV207REG_MMU_CONTROL_Count                                            1
#define MWV207REG_MMU_CONTROL_FieldMask                               0x000003FF
#define MWV207REG_MMU_CONTROL_ReadMask                                0x000003F0
#define MWV207REG_MMU_CONTROL_WriteMask                               0x000003FF
#define MWV207REG_MMU_CONTROL_ResetValue                              0x000001F0

#define MWV207REG_MMU_CONTROL_ENABLE                                         0:0
#define MWV207REG_MMU_CONTROL_ENABLE_End                                       0
#define MWV207REG_MMU_CONTROL_ENABLE_Start                                     0
#define MWV207REG_MMU_CONTROL_ENABLE_Type                                    U01
#define   MWV207REG_MMU_CONTROL_ENABLE_ENABLE                                0x1


#define MWV207REG_MMU_CONTROL_STRICT_MODE                                    1:1
#define MWV207REG_MMU_CONTROL_STRICT_MODE_End                                  1
#define MWV207REG_MMU_CONTROL_STRICT_MODE_Start                                1
#define MWV207REG_MMU_CONTROL_STRICT_MODE_Type                               U01
#define   MWV207REG_MMU_CONTROL_STRICT_MODE_ENABLE                           0x1


#define MWV207REG_MMU_CONTROL_OUT_OF_BOUND_EXCEPTION                         2:2
#define MWV207REG_MMU_CONTROL_OUT_OF_BOUND_EXCEPTION_End                       2
#define MWV207REG_MMU_CONTROL_OUT_OF_BOUND_EXCEPTION_Start                     2
#define MWV207REG_MMU_CONTROL_OUT_OF_BOUND_EXCEPTION_Type                    U01
#define   MWV207REG_MMU_CONTROL_OUT_OF_BOUND_EXCEPTION_ENABLE                0x1


#define MWV207REG_MMU_CONTROL_SECURITY_VIOL_EXCEPTION                        3:3
#define MWV207REG_MMU_CONTROL_SECURITY_VIOL_EXCEPTION_End                      3
#define MWV207REG_MMU_CONTROL_SECURITY_VIOL_EXCEPTION_Start                    3
#define MWV207REG_MMU_CONTROL_SECURITY_VIOL_EXCEPTION_Type                   U01
#define   MWV207REG_MMU_CONTROL_SECURITY_VIOL_EXCEPTION_ENABLE               0x1


#define MWV207REG_MMU_CONTROL_MMU_ID                                         9:4
#define MWV207REG_MMU_CONTROL_MMU_ID_End                                       9
#define MWV207REG_MMU_CONTROL_MMU_ID_Start                                     4
#define MWV207REG_MMU_CONTROL_MMU_ID_Type                                    U06



#define mwv207regMMUConfigurationExtRegAddrs                              0x0068
#define MWV207REG_MMU_CONFIGURATION_EXT_Address                          0x001A0
#define MWV207REG_MMU_CONFIGURATION_EXT_MSB                                   15
#define MWV207REG_MMU_CONFIGURATION_EXT_LSB                                    0
#define MWV207REG_MMU_CONFIGURATION_EXT_BLK                                    0
#define MWV207REG_MMU_CONFIGURATION_EXT_Count                                  1
#define MWV207REG_MMU_CONFIGURATION_EXT_FieldMask                     0xE0FFE0FF
#define MWV207REG_MMU_CONFIGURATION_EXT_ReadMask                      0xE0FFE0FF
#define MWV207REG_MMU_CONFIGURATION_EXT_WriteMask                     0xE0FFE0FF
#define MWV207REG_MMU_CONFIGURATION_EXT_ResetValue                    0x00000000

#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS                         7:0
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_End                       7
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_Start                     0
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_Type                    U08

#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SECURE                13:13
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SECURE_End               13
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SECURE_Start             13
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SECURE_Type             U01


#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SHAREABLE             14:14
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SHAREABLE_End            14
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SHAREABLE_Start          14
#define MWV207REG_MMU_CONFIGURATION_EXT_SAFE_ADDRESS_SHAREABLE_Type          U01


#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_SAFE_ADDRESS                  15:15
#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_SAFE_ADDRESS_End                 15
#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_SAFE_ADDRESS_Start               15
#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_SAFE_ADDRESS_Type               U01
#define   MWV207REG_MMU_CONFIGURATION_EXT_MASK_SAFE_ADDRESS_ENABLED          0x0
#define   MWV207REG_MMU_CONFIGURATION_EXT_MASK_SAFE_ADDRESS_MASKED           0x1


#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB                         23:16
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_End                        23
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_Start                      16
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_Type                      U08


#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SECURE                  29:29
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SECURE_End                 29
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SECURE_Start               29
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SECURE_Type               U01


#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SHAREABLE               30:30
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SHAREABLE_End              30
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SHAREABLE_Start            30
#define MWV207REG_MMU_CONFIGURATION_EXT_MASTER_TLB_SHAREABLE_Type            U01


#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_MASTER_TLB                    31:31
#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_MASTER_TLB_End                   31
#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_MASTER_TLB_Start                 31
#define MWV207REG_MMU_CONFIGURATION_EXT_MASK_MASTER_TLB_Type                 U01
#define   MWV207REG_MMU_CONFIGURATION_EXT_MASK_MASTER_TLB_ENABLED            0x0
#define   MWV207REG_MMU_CONFIGURATION_EXT_MASK_MASTER_TLB_MASKED             0x1



#define jmDebugSignalsBltRegAddrs                                         0x0069
#define JM_DEBUG_SIGNALS_BLT_Address                                     0x001A4
#define JM_DEBUG_SIGNALS_BLT_MSB                                              15
#define JM_DEBUG_SIGNALS_BLT_LSB                                               0
#define JM_DEBUG_SIGNALS_BLT_BLK                                               0
#define JM_DEBUG_SIGNALS_BLT_Count                                             1
#define JM_DEBUG_SIGNALS_BLT_FieldMask                                0xFFFFFFFF
#define JM_DEBUG_SIGNALS_BLT_ReadMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_BLT_WriteMask                                0x00000000
#define JM_DEBUG_SIGNALS_BLT_ResetValue                               0x00000000

#define JM_DEBUG_SIGNALS_BLT_SIGNAL                                         31:0
#define JM_DEBUG_SIGNALS_BLT_SIGNAL_End                                       31
#define JM_DEBUG_SIGNALS_BLT_SIGNAL_Start                                      0
#define JM_DEBUG_SIGNALS_BLT_SIGNAL_Type                                     U32




#define mwv207regMMUBarrierRegAddrs                                       0x006A
#define MWV207REG_MMU_BARRIER_Address                                    0x001A8
#define MWV207REG_MMU_BARRIER_MSB                                             15
#define MWV207REG_MMU_BARRIER_LSB                                              0
#define MWV207REG_MMU_BARRIER_BLK                                              0
#define MWV207REG_MMU_BARRIER_Count                                            1
#define MWV207REG_MMU_BARRIER_FieldMask                               0xFFFFFFFF
#define MWV207REG_MMU_BARRIER_ReadMask                                0xFFFFFFFF
#define MWV207REG_MMU_BARRIER_WriteMask                               0xFFFFFFFF
#define MWV207REG_MMU_BARRIER_ResetValue                              0x00000000


#define MWV207REG_MMU_BARRIER_TYPE                                           1:0
#define MWV207REG_MMU_BARRIER_TYPE_End                                         1
#define MWV207REG_MMU_BARRIER_TYPE_Start                                       0
#define MWV207REG_MMU_BARRIER_TYPE_Type                                      U02
#define   MWV207REG_MMU_BARRIER_TYPE_NORMAL_ACCESS_RESPECTING_BARRIER        0x0
#define   MWV207REG_MMU_BARRIER_TYPE_MEMORY_BARRIER                          0x1
#define   MWV207REG_MMU_BARRIER_TYPE_NORMAL_ACCESS_IGNORING_BARRIER          0x2
#define   MWV207REG_MMU_BARRIER_TYPE_SYNCHRONIZATION_BARRIER                 0x3


#define MWV207REG_MMU_BARRIER_CLIENT                                         5:2
#define MWV207REG_MMU_BARRIER_CLIENT_End                                       5
#define MWV207REG_MMU_BARRIER_CLIENT_Start                                     2
#define MWV207REG_MMU_BARRIER_CLIENT_Type                                    U04
#define   MWV207REG_MMU_BARRIER_CLIENT_PIXEL_ENGINE_COLOR                    0x0
#define   MWV207REG_MMU_BARRIER_CLIENT_PIXEL_ENGINE_DEPTH                    0x2
#define   MWV207REG_MMU_BARRIER_CLIENT_SHADER                                0x4
#define   MWV207REG_MMU_BARRIER_CLIENT_FRONT_END                             0x5
#define   MWV207REG_MMU_BARRIER_CLIENT_RASTERIZER                            0x6
#define   MWV207REG_MMU_BARRIER_CLIENT_TEXTURE                               0xA


#define MWV207REG_MMU_BARRIER_ADDR                                          31:6
#define MWV207REG_MMU_BARRIER_ADDR_End                                        31
#define MWV207REG_MMU_BARRIER_ADDR_Start                                       6
#define MWV207REG_MMU_BARRIER_ADDR_Type                                      U26




#define mwv207regMMUConfigRegAddrs                                        0x006B
#define MWV207REG_MMU_CONFIG_Address                                     0x001AC
#define MWV207REG_MMU_CONFIG_MSB                                              15
#define MWV207REG_MMU_CONFIG_LSB                                               0
#define MWV207REG_MMU_CONFIG_BLK                                               0
#define MWV207REG_MMU_CONFIG_Count                                             1
#define MWV207REG_MMU_CONFIG_FieldMask                                0xFC01FFFF
#define MWV207REG_MMU_CONFIG_ReadMask                                 0xFC01FFFF
#define MWV207REG_MMU_CONFIG_WriteMask                                0xFC01FFFF
#define MWV207REG_MMU_CONFIG_ResetValue                               0x00000000


#define MWV207REG_MMU_CONFIG_PAGE_TABLE_ID                                  15:0
#define MWV207REG_MMU_CONFIG_PAGE_TABLE_ID_End                                15
#define MWV207REG_MMU_CONFIG_PAGE_TABLE_ID_Start                               0
#define MWV207REG_MMU_CONFIG_PAGE_TABLE_ID_Type                              U16


#define MWV207REG_MMU_CONFIG_MASK_PAGE_TABLE_ID                            16:16
#define MWV207REG_MMU_CONFIG_MASK_PAGE_TABLE_ID_End                           16
#define MWV207REG_MMU_CONFIG_MASK_PAGE_TABLE_ID_Start                         16
#define MWV207REG_MMU_CONFIG_MASK_PAGE_TABLE_ID_Type                         U01
#define   MWV207REG_MMU_CONFIG_MASK_PAGE_TABLE_ID_ENABLED                    0x0
#define   MWV207REG_MMU_CONFIG_MASK_PAGE_TABLE_ID_MASKED                     0x1


#define MWV207REG_MMU_CONFIG_VIRTUAL_ADDRESS_40_BITS                       26:26
#define MWV207REG_MMU_CONFIG_VIRTUAL_ADDRESS_40_BITS_End                      26
#define MWV207REG_MMU_CONFIG_VIRTUAL_ADDRESS_40_BITS_Start                    26
#define MWV207REG_MMU_CONFIG_VIRTUAL_ADDRESS_40_BITS_Type                    U01
#define   MWV207REG_MMU_CONFIG_VIRTUAL_ADDRESS_40_BITS_ENABLED               0x0
#define   MWV207REG_MMU_CONFIG_VIRTUAL_ADDRESS_40_BITS_DISABLED              0x1


#define MWV207REG_MMU_CONFIG_MASK_VIRTUAL_ADDRESS_40_BITS                  27:27
#define MWV207REG_MMU_CONFIG_MASK_VIRTUAL_ADDRESS_40_BITS_End                 27
#define MWV207REG_MMU_CONFIG_MASK_VIRTUAL_ADDRESS_40_BITS_Start               27
#define MWV207REG_MMU_CONFIG_MASK_VIRTUAL_ADDRESS_40_BITS_Type               U01
#define   MWV207REG_MMU_CONFIG_MASK_VIRTUAL_ADDRESS_40_BITS_ENABLED          0x0
#define   MWV207REG_MMU_CONFIG_MASK_VIRTUAL_ADDRESS_40_BITS_MASKED           0x1


#define MWV207REG_MMU_CONFIG_OUT_OF_BOUND                                  28:28
#define MWV207REG_MMU_CONFIG_OUT_OF_BOUND_End                                 28
#define MWV207REG_MMU_CONFIG_OUT_OF_BOUND_Start                               28
#define MWV207REG_MMU_CONFIG_OUT_OF_BOUND_Type                               U01
#define   MWV207REG_MMU_CONFIG_OUT_OF_BOUND_DISABLED                         0x0
#define   MWV207REG_MMU_CONFIG_OUT_OF_BOUND_ENABLED                          0x1


#define MWV207REG_MMU_CONFIG_MASK_OUT_OF_BOUND                             29:29
#define MWV207REG_MMU_CONFIG_MASK_OUT_OF_BOUND_End                            29
#define MWV207REG_MMU_CONFIG_MASK_OUT_OF_BOUND_Start                          29
#define MWV207REG_MMU_CONFIG_MASK_OUT_OF_BOUND_Type                          U01
#define   MWV207REG_MMU_CONFIG_MASK_OUT_OF_BOUND_ENABLED                     0x0
#define   MWV207REG_MMU_CONFIG_MASK_OUT_OF_BOUND_MASKED                      0x1


#define MWV207REG_MMU_CONFIG_SECURITY                                      30:30
#define MWV207REG_MMU_CONFIG_SECURITY_End                                     30
#define MWV207REG_MMU_CONFIG_SECURITY_Start                                   30
#define MWV207REG_MMU_CONFIG_SECURITY_Type                                   U01
#define   MWV207REG_MMU_CONFIG_SECURITY_NON_SECURE_MODE                      0x0
#define   MWV207REG_MMU_CONFIG_SECURITY_SECURE_MODE                          0x1


#define MWV207REG_MMU_CONFIG_MASK_SECURITY                                 31:31
#define MWV207REG_MMU_CONFIG_MASK_SECURITY_End                                31
#define MWV207REG_MMU_CONFIG_MASK_SECURITY_Start                              31
#define MWV207REG_MMU_CONFIG_MASK_SECURITY_Type                              U01
#define   MWV207REG_MMU_CONFIG_MASK_SECURITY_ENABLED                         0x0
#define   MWV207REG_MMU_CONFIG_MASK_SECURITY_MASKED                          0x1




#define mwv207regMMUDcControlRegAddrs                                     0x006C
#define MWV207REG_MMU_DC_CONTROL_Address                                 0x001B0
#define MWV207REG_MMU_DC_CONTROL_MSB                                          15
#define MWV207REG_MMU_DC_CONTROL_LSB                                           0
#define MWV207REG_MMU_DC_CONTROL_BLK                                           0
#define MWV207REG_MMU_DC_CONTROL_Count                                         1
#define MWV207REG_MMU_DC_CONTROL_FieldMask                            0x0000000F
#define MWV207REG_MMU_DC_CONTROL_ReadMask                             0x00000003
#define MWV207REG_MMU_DC_CONTROL_WriteMask                            0x0000000F
#define MWV207REG_MMU_DC_CONTROL_ResetValue                           0x00000001

#define MWV207REG_MMU_DC_CONTROL_DC_SECURITY                                 0:0
#define MWV207REG_MMU_DC_CONTROL_DC_SECURITY_End                               0
#define MWV207REG_MMU_DC_CONTROL_DC_SECURITY_Start                             0
#define MWV207REG_MMU_DC_CONTROL_DC_SECURITY_Type                            U01

#define MWV207REG_MMU_DC_CONTROL_PANEL_SECURITY                              1:1
#define MWV207REG_MMU_DC_CONTROL_PANEL_SECURITY_End                            1
#define MWV207REG_MMU_DC_CONTROL_PANEL_SECURITY_Start                          1
#define MWV207REG_MMU_DC_CONTROL_PANEL_SECURITY_Type                         U01


#define MWV207REG_MMU_DC_CONTROL_STRICT_MODE                                 2:2
#define MWV207REG_MMU_DC_CONTROL_STRICT_MODE_End                               2
#define MWV207REG_MMU_DC_CONTROL_STRICT_MODE_Start                             2
#define MWV207REG_MMU_DC_CONTROL_STRICT_MODE_Type                            U01
#define   MWV207REG_MMU_DC_CONTROL_STRICT_MODE_DISABLE                       0x0
#define   MWV207REG_MMU_DC_CONTROL_STRICT_MODE_ENABLE                        0x1


#define MWV207REG_MMU_DC_CONTROL_SECURITY_VIOL_EXCEPTION                     3:3
#define MWV207REG_MMU_DC_CONTROL_SECURITY_VIOL_EXCEPTION_End                   3
#define MWV207REG_MMU_DC_CONTROL_SECURITY_VIOL_EXCEPTION_Start                 3
#define MWV207REG_MMU_DC_CONTROL_SECURITY_VIOL_EXCEPTION_Type                U01
#define   MWV207REG_MMU_DC_CONTROL_SECURITY_VIOL_EXCEPTION_DISABLE           0x0
#define   MWV207REG_MMU_DC_CONTROL_SECURITY_VIOL_EXCEPTION_ENABLE            0x1




#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_MODE                             0:0
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_MODE_End                           0
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_MODE_Start                         0
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_MODE_Type                        U01
#define   MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_MODE_MODE4_K                   0x0
#define   MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_MODE_MODE1_K                   0x1


#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_ADDRESS                        31:10
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_ADDRESS_End                       31
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_ADDRESS_Start                     10
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_LOW_ADDRESS_Type                     U22



#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB                      7:0
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_End                    7
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_Start                  0
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_Type                 U08


#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SECURE               8:8
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SECURE_End             8
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SECURE_Start           8
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SECURE_Type          U01


#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SHAREABLE            9:9
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SHAREABLE_End          9
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SHAREABLE_Start        9
#define MWV207REG_MMU_TABLE_ARRAY_ENTRY_HIGH_MASTER_TLB_SHAREABLE_Type       U01


#endif


