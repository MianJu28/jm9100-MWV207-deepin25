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




#ifndef __jmgpuregDEC400_h__
#define __jmgpuregDEC400_h__





#define mwv207regDEC400ControlRegAddrs                                    0x6200
#define MWV207REG_DEC400_CONTROL_Address                                 0x18800
#define MWV207REG_DEC400_CONTROL_MSB                                          15
#define MWV207REG_DEC400_CONTROL_LSB                                           0
#define MWV207REG_DEC400_CONTROL_BLK                                           0
#define MWV207REG_DEC400_CONTROL_Count                                         1
#define MWV207REG_DEC400_CONTROL_FieldMask                            0xFFFFFFFF
#define MWV207REG_DEC400_CONTROL_ReadMask                             0xFFFFFFFF
#define MWV207REG_DEC400_CONTROL_WriteMask                            0x4AFF01DF
#define MWV207REG_DEC400_CONTROL_ResetValue                           0x0201018A


#define MWV207REG_DEC400_CONTROL_FLUSH                                       0:0
#define MWV207REG_DEC400_CONTROL_FLUSH_End                                     0
#define MWV207REG_DEC400_CONTROL_FLUSH_Start                                   0
#define MWV207REG_DEC400_CONTROL_FLUSH_Type                                  U01
#define   MWV207REG_DEC400_CONTROL_FLUSH_DISABLE                             0x0
#define   MWV207REG_DEC400_CONTROL_FLUSH_ENABLE                              0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_COMPRESSION                         1:1
#define MWV207REG_DEC400_CONTROL_DISABLE_COMPRESSION_End                       1
#define MWV207REG_DEC400_CONTROL_DISABLE_COMPRESSION_Start                     1
#define MWV207REG_DEC400_CONTROL_DISABLE_COMPRESSION_Type                    U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_COMPRESSION_ENABLE                0x0

#define   MWV207REG_DEC400_CONTROL_DISABLE_COMPRESSION_DISABLE               0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_CLOCK_GATING                    2:2
#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_CLOCK_GATING_End                  2
#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_CLOCK_GATING_Start                2
#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_CLOCK_GATING_Type               U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_RAM_CLOCK_GATING_DISABLE          0x0
#define   MWV207REG_DEC400_CONTROL_DISABLE_RAM_CLOCK_GATING_ENABLE           0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_DEBUG_REGISTERS                     3:3
#define MWV207REG_DEC400_CONTROL_DISABLE_DEBUG_REGISTERS_End                   3
#define MWV207REG_DEC400_CONTROL_DISABLE_DEBUG_REGISTERS_Start                 3
#define MWV207REG_DEC400_CONTROL_DISABLE_DEBUG_REGISTERS_Type                U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_DEBUG_REGISTERS_DISABLE           0x1
#define   MWV207REG_DEC400_CONTROL_DISABLE_DEBUG_REGISTERS_ENABLE            0x0


#define MWV207REG_DEC400_CONTROL_SOFT_RESET                                  4:4
#define MWV207REG_DEC400_CONTROL_SOFT_RESET_End                                4
#define MWV207REG_DEC400_CONTROL_SOFT_RESET_Start                              4
#define MWV207REG_DEC400_CONTROL_SOFT_RESET_Type                             U01
#define   MWV207REG_DEC400_CONTROL_SOFT_RESET_DISABLE                        0x0
#define   MWV207REG_DEC400_CONTROL_SOFT_RESET_ENABLE                         0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION              5:5
#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_End            5
#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Start          5
#define MWV207REG_DEC400_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Type         U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_DISABLE    0x0
#define   MWV207REG_DEC400_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_ENABLE     0x1


#define MWV207REG_DEC400_CONTROL_FLUSH_DCACHE                                6:6
#define MWV207REG_DEC400_CONTROL_FLUSH_DCACHE_End                              6
#define MWV207REG_DEC400_CONTROL_FLUSH_DCACHE_Start                            6
#define MWV207REG_DEC400_CONTROL_FLUSH_DCACHE_Type                           U01
#define   MWV207REG_DEC400_CONTROL_FLUSH_DCACHE_DISABLE                      0x0
#define   MWV207REG_DEC400_CONTROL_FLUSH_DCACHE_ENABLE                       0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_DCACHE                              7:7
#define MWV207REG_DEC400_CONTROL_DISABLE_DCACHE_End                            7
#define MWV207REG_DEC400_CONTROL_DISABLE_DCACHE_Start                          7
#define MWV207REG_DEC400_CONTROL_DISABLE_DCACHE_Type                         U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_DCACHE_DISABLE                    0x0
#define   MWV207REG_DEC400_CONTROL_DISABLE_DCACHE_ENABLE                     0x1

#define MWV207REG_DEC400_CONTROL_WRITE_REQ_ALIGN_MODE                        8:8
#define MWV207REG_DEC400_CONTROL_WRITE_REQ_ALIGN_MODE_End                      8
#define MWV207REG_DEC400_CONTROL_WRITE_REQ_ALIGN_MODE_Start                    8
#define MWV207REG_DEC400_CONTROL_WRITE_REQ_ALIGN_MODE_Type                   U01
#define   MWV207REG_DEC400_CONTROL_WRITE_REQ_ALIGN_MODE_DISABLE              0x0
#define   MWV207REG_DEC400_CONTROL_WRITE_REQ_ALIGN_MODE_ENABLE               0x1


#define MWV207REG_DEC400_CONTROL_RESERVE0                                   15:9
#define MWV207REG_DEC400_CONTROL_RESERVE0_End                                 15
#define MWV207REG_DEC400_CONTROL_RESERVE0_Start                                9
#define MWV207REG_DEC400_CONTROL_RESERVE0_Type                               U07


#define MWV207REG_DEC400_CONTROL_DISABLE_HW_FLUSH                          16:16
#define MWV207REG_DEC400_CONTROL_DISABLE_HW_FLUSH_End                         16
#define MWV207REG_DEC400_CONTROL_DISABLE_HW_FLUSH_Start                       16
#define MWV207REG_DEC400_CONTROL_DISABLE_HW_FLUSH_Type                       U01

#define   MWV207REG_DEC400_CONTROL_DISABLE_HW_FLUSH_ENABLE                   0x0
#define   MWV207REG_DEC400_CONTROL_DISABLE_HW_FLUSH_DISABLE                  0x1


#define MWV207REG_DEC400_CONTROL_CLK_DIS                                   17:17
#define MWV207REG_DEC400_CONTROL_CLK_DIS_End                                  17
#define MWV207REG_DEC400_CONTROL_CLK_DIS_Start                                17
#define MWV207REG_DEC400_CONTROL_CLK_DIS_Type                                U01
#define   MWV207REG_DEC400_CONTROL_CLK_DIS_DISABLE                           0x1
#define   MWV207REG_DEC400_CONTROL_CLK_DIS_ENABLE                            0x0

#define MWV207REG_DEC400_CONTROL_SW_FLUSH_ID                               23:18
#define MWV207REG_DEC400_CONTROL_SW_FLUSH_ID_End                              23
#define MWV207REG_DEC400_CONTROL_SW_FLUSH_ID_Start                            18
#define MWV207REG_DEC400_CONTROL_SW_FLUSH_ID_Type                            U06

#define MWV207REG_DEC400_CONTROL_TILE_CACHE_MODE                           24:24
#define MWV207REG_DEC400_CONTROL_TILE_CACHE_MODE_End                          24
#define MWV207REG_DEC400_CONTROL_TILE_CACHE_MODE_Start                        24
#define MWV207REG_DEC400_CONTROL_TILE_CACHE_MODE_Type                        U01
#define   MWV207REG_DEC400_CONTROL_TILE_CACHE_MODE_MODE16X64                 0x0
#define   MWV207REG_DEC400_CONTROL_TILE_CACHE_MODE_MODE64X16                 0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_CACHE_PREFETCH                    25:25
#define MWV207REG_DEC400_CONTROL_DISABLE_CACHE_PREFETCH_End                   25
#define MWV207REG_DEC400_CONTROL_DISABLE_CACHE_PREFETCH_Start                 25
#define MWV207REG_DEC400_CONTROL_DISABLE_CACHE_PREFETCH_Type                 U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_CACHE_PREFETCH_DISABLED           0x1
#define   MWV207REG_DEC400_CONTROL_DISABLE_CACHE_PREFETCH_ENABLED            0x0


#define MWV207REG_DEC400_CONTROL_CONFIGURE_MODE                            26:26
#define MWV207REG_DEC400_CONTROL_CONFIGURE_MODE_End                           26
#define MWV207REG_DEC400_CONTROL_CONFIGURE_MODE_Start                         26
#define MWV207REG_DEC400_CONTROL_CONFIGURE_MODE_Type                         U01
#define   MWV207REG_DEC400_CONTROL_CONFIGURE_MODE_AHB                        0x0
#define   MWV207REG_DEC400_CONTROL_CONFIGURE_MODE_LOAD_STATE                 0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_PREFETCH                          27:27
#define MWV207REG_DEC400_CONTROL_DISABLE_PREFETCH_End                         27
#define MWV207REG_DEC400_CONTROL_DISABLE_PREFETCH_Start                       27
#define MWV207REG_DEC400_CONTROL_DISABLE_PREFETCH_Type                       U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_PREFETCH_DISABLED                 0x0
#define   MWV207REG_DEC400_CONTROL_DISABLE_PREFETCH_ENABLED                  0x1

#define MWV207REG_DEC400_CONTROL_HW_UPDATE_SHADOW_REG_MODE                 28:28
#define MWV207REG_DEC400_CONTROL_HW_UPDATE_SHADOW_REG_MODE_End                28
#define MWV207REG_DEC400_CONTROL_HW_UPDATE_SHADOW_REG_MODE_Start              28
#define MWV207REG_DEC400_CONTROL_HW_UPDATE_SHADOW_REG_MODE_Type              U01
#define   MWV207REG_DEC400_CONTROL_HW_UPDATE_SHADOW_REG_MODE_TRIGGER         0x0
#define   MWV207REG_DEC400_CONTROL_HW_UPDATE_SHADOW_REG_MODE_FRAME_END       0x1


#define MWV207REG_DEC400_CONTROL_SOFT_UPDATE_SHADOW_REG                    29:29
#define MWV207REG_DEC400_CONTROL_SOFT_UPDATE_SHADOW_REG_End                   29
#define MWV207REG_DEC400_CONTROL_SOFT_UPDATE_SHADOW_REG_Start                 29
#define MWV207REG_DEC400_CONTROL_SOFT_UPDATE_SHADOW_REG_Type                 U01
#define   MWV207REG_DEC400_CONTROL_SOFT_UPDATE_SHADOW_REG_DISABLED           0x0
#define   MWV207REG_DEC400_CONTROL_SOFT_UPDATE_SHADOW_REG_ENABLED            0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_MODULE_CLOCK_GATING               30:30
#define MWV207REG_DEC400_CONTROL_DISABLE_MODULE_CLOCK_GATING_End              30
#define MWV207REG_DEC400_CONTROL_DISABLE_MODULE_CLOCK_GATING_Start            30
#define MWV207REG_DEC400_CONTROL_DISABLE_MODULE_CLOCK_GATING_Type            U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_MODULE_CLOCK_GATING_DISABLE       0x0
#define   MWV207REG_DEC400_CONTROL_DISABLE_MODULE_CLOCK_GATING_ENABLE        0x1


#define MWV207REG_DEC400_CONTROL_DISABLE_GLOBAL_CLOCK_GATING               31:31
#define MWV207REG_DEC400_CONTROL_DISABLE_GLOBAL_CLOCK_GATING_End              31
#define MWV207REG_DEC400_CONTROL_DISABLE_GLOBAL_CLOCK_GATING_Start            31
#define MWV207REG_DEC400_CONTROL_DISABLE_GLOBAL_CLOCK_GATING_Type            U01
#define   MWV207REG_DEC400_CONTROL_DISABLE_GLOBAL_CLOCK_GATING_DISABLE       0x0
#define   MWV207REG_DEC400_CONTROL_DISABLE_GLOBAL_CLOCK_GATING_ENABLE        0x1



#define mwv207regDEC400ControlExRegAddrs                                  0x6201
#define MWV207REG_DEC400_CONTROL_EX_Address                              0x18804
#define MWV207REG_DEC400_CONTROL_EX_MSB                                       15
#define MWV207REG_DEC400_CONTROL_EX_LSB                                        0
#define MWV207REG_DEC400_CONTROL_EX_BLK                                        0
#define MWV207REG_DEC400_CONTROL_EX_Count                                      1
#define MWV207REG_DEC400_CONTROL_EX_FieldMask                         0xFFFFFFFF
#define MWV207REG_DEC400_CONTROL_EX_ReadMask                          0xFFFFFFFF
#define MWV207REG_DEC400_CONTROL_EX_WriteMask                         0x200EFFFF
#define MWV207REG_DEC400_CONTROL_EX_ResetValue                        0x00080000


#define MWV207REG_DEC400_CONTROL_EX_AXUSER                                  11:0
#define MWV207REG_DEC400_CONTROL_EX_AXUSER_End                                11
#define MWV207REG_DEC400_CONTROL_EX_AXUSER_Start                               0
#define MWV207REG_DEC400_CONTROL_EX_AXUSER_Type                              U12


#define MWV207REG_DEC400_CONTROL_EX_AXQOS                                  15:12
#define MWV207REG_DEC400_CONTROL_EX_AXQOS_End                                 15
#define MWV207REG_DEC400_CONTROL_EX_AXQOS_Start                               12
#define MWV207REG_DEC400_CONTROL_EX_AXQOS_Type                               U04


#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT                     16:16
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_End                    16
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_Start                  16
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_Type                  U01


#define MWV207REG_DEC400_CONTROL_EX_ENABLE_END_ADDRESS_RANGE_CHECK         17:17
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_END_ADDRESS_RANGE_CHECK_End        17
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_END_ADDRESS_RANGE_CHECK_Start      17
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_END_ADDRESS_RANGE_CHECK_Type      U01


#define MWV207REG_DEC400_CONTROL_EX_FAST_CLEAR_WIDTH_SEL                   18:18
#define MWV207REG_DEC400_CONTROL_EX_FAST_CLEAR_WIDTH_SEL_End                  18
#define MWV207REG_DEC400_CONTROL_EX_FAST_CLEAR_WIDTH_SEL_Start                18
#define MWV207REG_DEC400_CONTROL_EX_FAST_CLEAR_WIDTH_SEL_Type                U01

#define MWV207REG_DEC400_CONTROL_EX_WRITE_MISS_POLICY                      19:19
#define MWV207REG_DEC400_CONTROL_EX_WRITE_MISS_POLICY_End                     19
#define MWV207REG_DEC400_CONTROL_EX_WRITE_MISS_POLICY_Start                   19
#define MWV207REG_DEC400_CONTROL_EX_WRITE_MISS_POLICY_Type                   U01

#define   MWV207REG_DEC400_CONTROL_EX_WRITE_MISS_POLICY_POLICY0              0x0

#define   MWV207REG_DEC400_CONTROL_EX_WRITE_MISS_POLICY_POLICY1              0x1


#define MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE                       21:20
#define MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE_End                      21
#define MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE_Start                    20
#define MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE_Type                    U02

#define   MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE_MODE0                 0x0

#define   MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE_MODE1                 0x1

#define   MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE_MODE2                 0x2
#define   MWV207REG_DEC400_CONTROL_EX_COMPRESSION_MODE_RESERVED              0x3

#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX                  23:22
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX_End                 23
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX_Start               22
#define MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX_Type               U02
#define   MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX_BYTES64          0x0
#define   MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX_BYTES128         0x1
#define   MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX_BYTES256         0x2
#define   MWV207REG_DEC400_CONTROL_EX_ENABLE_BURST_SPLIT_EX_RESERVED         0x3


#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TFC                      24:24
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TFC_End                     24
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TFC_Start                   24
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TFC_Type                   U01
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TFC_DISABLE              0x0
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TFC_ENABLE               0x1


#define MWV207REG_DEC400_CONTROL_EX_DISABLE_ADDRESS_HASH                   25:25
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_ADDRESS_HASH_End                  25
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_ADDRESS_HASH_Start                25
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_ADDRESS_HASH_Type                U01
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_ADDRESS_HASH_DISABLE           0x0
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_ADDRESS_HASH_ENABLE            0x1

#define MWV207REG_DEC400_CONTROL_EX_TGL_DISABLE_COMPRESSION                26:26
#define MWV207REG_DEC400_CONTROL_EX_TGL_DISABLE_COMPRESSION_End               26
#define MWV207REG_DEC400_CONTROL_EX_TGL_DISABLE_COMPRESSION_Start             26
#define MWV207REG_DEC400_CONTROL_EX_TGL_DISABLE_COMPRESSION_Type             U01
#define   MWV207REG_DEC400_CONTROL_EX_TGL_DISABLE_COMPRESSION_DISABLE        0x0
#define   MWV207REG_DEC400_CONTROL_EX_TGL_DISABLE_COMPRESSION_ENABLE         0x1


#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TSC                      27:27
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TSC_End                     27
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TSC_Start                   27
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TSC_Type                   U01
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TSC_DISABLE              0x0
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_CACHE_TSC_ENABLE               0x1


#define MWV207REG_DEC400_CONTROL_EX_DISABLE_DCACHE                         28:28
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_DCACHE_End                        28
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_DCACHE_Start                      28
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_DCACHE_Type                      U01
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_DCACHE_DISABLE                 0x0
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_DCACHE_ENABLE                  0x1

#define MWV207REG_DEC400_CONTROL_EX_READ_MISS_POLICY                       29:29
#define MWV207REG_DEC400_CONTROL_EX_READ_MISS_POLICY_End                      29
#define MWV207REG_DEC400_CONTROL_EX_READ_MISS_POLICY_Start                    29
#define MWV207REG_DEC400_CONTROL_EX_READ_MISS_POLICY_Type                    U01

#define   MWV207REG_DEC400_CONTROL_EX_READ_MISS_POLICY_POLICY0               0x0
#define   MWV207REG_DEC400_CONTROL_EX_READ_MISS_POLICY_POLICY1               0x1


#define MWV207REG_DEC400_CONTROL_EX_TILE_YF                                30:30
#define MWV207REG_DEC400_CONTROL_EX_TILE_YF_End                               30
#define MWV207REG_DEC400_CONTROL_EX_TILE_YF_Start                             30
#define MWV207REG_DEC400_CONTROL_EX_TILE_YF_Type                             U01
#define   MWV207REG_DEC400_CONTROL_EX_TILE_YF_DISABLE                        0x0
#define   MWV207REG_DEC400_CONTROL_EX_TILE_YF_ENABLE                         0x1


#define MWV207REG_DEC400_CONTROL_EX_DISABLE_TSC_AUTO_EVICT                 31:31
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_TSC_AUTO_EVICT_End                31
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_TSC_AUTO_EVICT_Start              31
#define MWV207REG_DEC400_CONTROL_EX_DISABLE_TSC_AUTO_EVICT_Type              U01
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_TSC_AUTO_EVICT_DISABLE         0x0
#define   MWV207REG_DEC400_CONTROL_EX_DISABLE_TSC_AUTO_EVICT_ENABLE          0x1



#define mwv207regDEC400ControlEx2RegAddrs                                 0x6202
#define MWV207REG_DEC400_CONTROL_EX2_Address                             0x18808
#define MWV207REG_DEC400_CONTROL_EX2_MSB                                      15
#define MWV207REG_DEC400_CONTROL_EX2_LSB                                       0
#define MWV207REG_DEC400_CONTROL_EX2_BLK                                       0
#define MWV207REG_DEC400_CONTROL_EX2_Count                                     1
#define MWV207REG_DEC400_CONTROL_EX2_FieldMask                        0xFFFFFFFF
#define MWV207REG_DEC400_CONTROL_EX2_ReadMask                         0xFFFFFFFF
#define MWV207REG_DEC400_CONTROL_EX2_WriteMask                        0x033FFFFF
#define MWV207REG_DEC400_CONTROL_EX2_ResetValue                       0x003FC810


#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_READ_ID                     6:0
#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_READ_ID_End                   6
#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_READ_ID_Start                 0
#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_READ_ID_Type                U07


#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_WRITE_ID                   13:7
#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_WRITE_ID_End                 13
#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_WRITE_ID_Start                7
#define MWV207REG_DEC400_CONTROL_EX2_TILE_STATUS_WRITE_ID_Type               U07


#define MWV207REG_DEC400_CONTROL_EX2_WR_OT_CNT                             21:14
#define MWV207REG_DEC400_CONTROL_EX2_WR_OT_CNT_End                            21
#define MWV207REG_DEC400_CONTROL_EX2_WR_OT_CNT_Start                          14
#define MWV207REG_DEC400_CONTROL_EX2_WR_OT_CNT_Type                          U08
#define   MWV207REG_DEC400_CONTROL_EX2_WR_OT_CNT_RESET                      0xFF


#define MWV207REG_DEC400_CONTROL_EX2_RESERVE0                              23:22
#define MWV207REG_DEC400_CONTROL_EX2_RESERVE0_End                             23
#define MWV207REG_DEC400_CONTROL_EX2_RESERVE0_Start                           22
#define MWV207REG_DEC400_CONTROL_EX2_RESERVE0_Type                           U02


#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_TSC_HIT_MISS_SEPARATE_REQUEST  24:24
#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_TSC_HIT_MISS_SEPARATE_REQUEST_End 24
#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_TSC_HIT_MISS_SEPARATE_REQUEST_Start 24
#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_TSC_HIT_MISS_SEPARATE_REQUEST_Type U01
#define   MWV207REG_DEC400_CONTROL_EX2_ENABLE_TSC_HIT_MISS_SEPARATE_REQUEST_DISABLE 0x0
#define   MWV207REG_DEC400_CONTROL_EX2_ENABLE_TSC_HIT_MISS_SEPARATE_REQUEST_ENABLE 0x1


#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_GLOBAL_CR_STATISTICS           25:25
#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_GLOBAL_CR_STATISTICS_End          25
#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_GLOBAL_CR_STATISTICS_Start        25
#define MWV207REG_DEC400_CONTROL_EX2_ENABLE_GLOBAL_CR_STATISTICS_Type        U01
#define   MWV207REG_DEC400_CONTROL_EX2_ENABLE_GLOBAL_CR_STATISTICS_DISABLE   0x0
#define   MWV207REG_DEC400_CONTROL_EX2_ENABLE_GLOBAL_CR_STATISTICS_ENABLE    0x1

#define MWV207REG_DEC400_CONTROL_EX2_PROBE_STREAM_ID                       30:26
#define MWV207REG_DEC400_CONTROL_EX2_PROBE_STREAM_ID_End                      30
#define MWV207REG_DEC400_CONTROL_EX2_PROBE_STREAM_ID_Start                    26
#define MWV207REG_DEC400_CONTROL_EX2_PROBE_STREAM_ID_Type                    U05

#define MWV207REG_DEC400_CONTROL_EX2_TS_CACHE_MAP_MODE                     31:31
#define MWV207REG_DEC400_CONTROL_EX2_TS_CACHE_MAP_MODE_End                    31
#define MWV207REG_DEC400_CONTROL_EX2_TS_CACHE_MAP_MODE_Start                  31
#define MWV207REG_DEC400_CONTROL_EX2_TS_CACHE_MAP_MODE_Type                  U01
#define   MWV207REG_DEC400_CONTROL_EX2_TS_CACHE_MAP_MODE_MODE0               0x0
#define   MWV207REG_DEC400_CONTROL_EX2_TS_CACHE_MAP_MODE_MODE1               0x1




#define mwv207regDEC400IntrEnblRegAddrs                                   0x6203
#define MWV207REG_DEC400_INTR_ENBL_Address                               0x1880C
#define MWV207REG_DEC400_INTR_ENBL_MSB                                        15
#define MWV207REG_DEC400_INTR_ENBL_LSB                                         0
#define MWV207REG_DEC400_INTR_ENBL_BLK                                         0
#define MWV207REG_DEC400_INTR_ENBL_Count                                       1
#define MWV207REG_DEC400_INTR_ENBL_FieldMask                          0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_ReadMask                           0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_WriteMask                          0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_ResetValue                         0x00000000


#define MWV207REG_DEC400_INTR_ENBL_INTR_ENBL_VEC                            31:0
#define MWV207REG_DEC400_INTR_ENBL_INTR_ENBL_VEC_End                          31
#define MWV207REG_DEC400_INTR_ENBL_INTR_ENBL_VEC_Start                         0
#define MWV207REG_DEC400_INTR_ENBL_INTR_ENBL_VEC_Type                        U32



#define mwv207regDEC400IntrEnblExRegAddrs                                 0x6204
#define MWV207REG_DEC400_INTR_ENBL_EX_Address                            0x18810
#define MWV207REG_DEC400_INTR_ENBL_EX_MSB                                     15
#define MWV207REG_DEC400_INTR_ENBL_EX_LSB                                      0
#define MWV207REG_DEC400_INTR_ENBL_EX_BLK                                      0
#define MWV207REG_DEC400_INTR_ENBL_EX_Count                                    1
#define MWV207REG_DEC400_INTR_ENBL_EX_FieldMask                       0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_EX_ReadMask                        0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_EX_WriteMask                       0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_EX_ResetValue                      0x00000000


#define MWV207REG_DEC400_INTR_ENBL_EX_INTR_ENBL_VEC                         31:0
#define MWV207REG_DEC400_INTR_ENBL_EX_INTR_ENBL_VEC_End                       31
#define MWV207REG_DEC400_INTR_ENBL_EX_INTR_ENBL_VEC_Start                      0
#define MWV207REG_DEC400_INTR_ENBL_EX_INTR_ENBL_VEC_Type                     U32



#define mwv207regDEC400IntrEnblEx2RegAddrs                                0x6205
#define MWV207REG_DEC400_INTR_ENBL_EX2_Address                           0x18814
#define MWV207REG_DEC400_INTR_ENBL_EX2_MSB                                    15
#define MWV207REG_DEC400_INTR_ENBL_EX2_LSB                                     0
#define MWV207REG_DEC400_INTR_ENBL_EX2_BLK                                     0
#define MWV207REG_DEC400_INTR_ENBL_EX2_Count                                   1
#define MWV207REG_DEC400_INTR_ENBL_EX2_FieldMask                      0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_EX2_ReadMask                       0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_EX2_WriteMask                      0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ENBL_EX2_ResetValue                     0x00000000


#define MWV207REG_DEC400_INTR_ENBL_EX2_INTR_ENBL_VEC                        31:0
#define MWV207REG_DEC400_INTR_ENBL_EX2_INTR_ENBL_VEC_End                      31
#define MWV207REG_DEC400_INTR_ENBL_EX2_INTR_ENBL_VEC_Start                     0
#define MWV207REG_DEC400_INTR_ENBL_EX2_INTR_ENBL_VEC_Type                    U32



#define mwv207regDEC400IntrAcknowledgeRegAddrs                            0x6206
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_Address                        0x18818
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_MSB                                 15
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_LSB                                  0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_BLK                                  0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_Count                                1
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_FieldMask                   0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_ReadMask                    0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_WriteMask                   0x00000000
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_ResetValue                  0x00000000

#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_INTR_VEC                          31:0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_INTR_VEC_End                        31
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_INTR_VEC_Start                       0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_INTR_VEC_Type                      U32



#define mwv207regDEC400IntrAcknowledgeExRegAddrs                          0x6207
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_Address                     0x1881C
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_MSB                              15
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_LSB                               0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_BLK                               0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_Count                             1
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_WriteMask                0x00000000
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_ResetValue               0x00000000

#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_INTR_VEC                       31:0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_INTR_VEC_End                     31
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_INTR_VEC_Start                    0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX_INTR_VEC_Type                   U32



#define mwv207regDEC400IntrAcknowledgeEx2RegAddrs                         0x6208
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_Address                    0x18820
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_MSB                             15
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_LSB                              0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_BLK                              0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_Count                            1
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_FieldMask               0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_ReadMask                0xFFFFFFFF
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_WriteMask               0x00000000
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_ResetValue              0x00000000

#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_INTR_VEC                      31:0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_INTR_VEC_End                    31
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_INTR_VEC_Start                   0
#define MWV207REG_DEC400_INTR_ACKNOWLEDGE_EX2_INTR_VEC_Type                  U32




#define mwv207regDEC400TileStatusDebugRegAddrs                            0x6209
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_Address                       0x18824
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_MSB                                15
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_LSB                                 0
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_BLK                                 0
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_Count                               1
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_FieldMask                  0xFFFFFFFF
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_ReadMask                   0xFFFFFFFF
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_WriteMask                  0x00000000
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_ResetValue                 0x20008A00


#define MWV207REG_DEC400_TILE_STATUS_DEBUG_DEBUG                            31:0
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_DEBUG_End                          31
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_DEBUG_Start                         0
#define MWV207REG_DEC400_TILE_STATUS_DEBUG_DEBUG_Type                        U32




#define mwv207regDEC400EncoderDebugRegAddrs                               0x620A
#define MWV207REG_DEC400_ENCODER_DEBUG_Address                           0x18828
#define MWV207REG_DEC400_ENCODER_DEBUG_MSB                                    15
#define MWV207REG_DEC400_ENCODER_DEBUG_LSB                                     0
#define MWV207REG_DEC400_ENCODER_DEBUG_BLK                                     0
#define MWV207REG_DEC400_ENCODER_DEBUG_Count                                   1
#define MWV207REG_DEC400_ENCODER_DEBUG_FieldMask                      0xFFFFFFFF
#define MWV207REG_DEC400_ENCODER_DEBUG_ReadMask                       0xFFFFFFFF
#define MWV207REG_DEC400_ENCODER_DEBUG_WriteMask                      0x00000000
#define MWV207REG_DEC400_ENCODER_DEBUG_ResetValue                     0x02000000


#define MWV207REG_DEC400_ENCODER_DEBUG_DEBUG                                31:0
#define MWV207REG_DEC400_ENCODER_DEBUG_DEBUG_End                              31
#define MWV207REG_DEC400_ENCODER_DEBUG_DEBUG_Start                             0
#define MWV207REG_DEC400_ENCODER_DEBUG_DEBUG_Type                            U32




#define mwv207regDEC400DecoderDebugRegAddrs                               0x620B
#define MWV207REG_DEC400_DECODER_DEBUG_Address                           0x1882C
#define MWV207REG_DEC400_DECODER_DEBUG_MSB                                    15
#define MWV207REG_DEC400_DECODER_DEBUG_LSB                                     0
#define MWV207REG_DEC400_DECODER_DEBUG_BLK                                     0
#define MWV207REG_DEC400_DECODER_DEBUG_Count                                   1
#define MWV207REG_DEC400_DECODER_DEBUG_FieldMask                      0xFFFFFFFF
#define MWV207REG_DEC400_DECODER_DEBUG_ReadMask                       0xFFFFFFFF
#define MWV207REG_DEC400_DECODER_DEBUG_WriteMask                      0x00000000
#define MWV207REG_DEC400_DECODER_DEBUG_ResetValue                     0x00000000


#define MWV207REG_DEC400_DECODER_DEBUG_DEBUG                                31:0
#define MWV207REG_DEC400_DECODER_DEBUG_DEBUG_End                              31
#define MWV207REG_DEC400_DECODER_DEBUG_DEBUG_Start                             0
#define MWV207REG_DEC400_DECODER_DEBUG_DEBUG_Type                            U32



#define mwv207regDEC400TotalReadsInRegAddrs                               0x620C
#define MWV207REG_DEC400_TOTAL_READS_IN_Address                          0x18830
#define MWV207REG_DEC400_TOTAL_READS_IN_MSB                                   15
#define MWV207REG_DEC400_TOTAL_READS_IN_LSB                                    0
#define MWV207REG_DEC400_TOTAL_READS_IN_BLK                                    0
#define MWV207REG_DEC400_TOTAL_READS_IN_Count                                  1
#define MWV207REG_DEC400_TOTAL_READS_IN_FieldMask                     0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_IN_ReadMask                      0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_IN_WriteMask                     0x00000000
#define MWV207REG_DEC400_TOTAL_READS_IN_ResetValue                    0x00000000


#define MWV207REG_DEC400_TOTAL_READS_IN_COUNT                               31:0
#define MWV207REG_DEC400_TOTAL_READS_IN_COUNT_End                             31
#define MWV207REG_DEC400_TOTAL_READS_IN_COUNT_Start                            0
#define MWV207REG_DEC400_TOTAL_READS_IN_COUNT_Type                           U32




#define mwv207regDEC400TotalWritesInRegAddrs                              0x620D
#define MWV207REG_DEC400_TOTAL_WRITES_IN_Address                         0x18834
#define MWV207REG_DEC400_TOTAL_WRITES_IN_MSB                                  15
#define MWV207REG_DEC400_TOTAL_WRITES_IN_LSB                                   0
#define MWV207REG_DEC400_TOTAL_WRITES_IN_BLK                                   0
#define MWV207REG_DEC400_TOTAL_WRITES_IN_Count                                 1
#define MWV207REG_DEC400_TOTAL_WRITES_IN_FieldMask                    0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_IN_ReadMask                     0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_IN_WriteMask                    0x00000000
#define MWV207REG_DEC400_TOTAL_WRITES_IN_ResetValue                   0x00000000


#define MWV207REG_DEC400_TOTAL_WRITES_IN_COUNT                              31:0
#define MWV207REG_DEC400_TOTAL_WRITES_IN_COUNT_End                            31
#define MWV207REG_DEC400_TOTAL_WRITES_IN_COUNT_Start                           0
#define MWV207REG_DEC400_TOTAL_WRITES_IN_COUNT_Type                          U32




#define mwv207regDEC400TotalReadBurstsInRegAddrs                          0x620E
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_Address                    0x18838
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_MSB                             15
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_LSB                              0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_BLK                              0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_Count                            1
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_FieldMask               0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_ReadMask                0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_WriteMask               0x00000000
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_ResetValue              0x00000000


#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_COUNT                         31:0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_COUNT_End                       31
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_COUNT_Start                      0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_IN_COUNT_Type                     U32




#define mwv207regDEC400TotalWriteBurstsInRegAddrs                         0x620F
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_Address                   0x1883C
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_MSB                            15
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_LSB                             0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_BLK                             0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_Count                           1
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_FieldMask              0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_ReadMask               0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_WriteMask              0x00000000
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_ResetValue             0x00000000


#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_COUNT                        31:0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_COUNT_End                      31
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_COUNT_Start                     0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_IN_COUNT_Type                    U32




#define mwv207regDEC400TotalReadsReqInRegAddrs                            0x6210
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_Address                      0x18840
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_MSB                               15
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_LSB                                0
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_BLK                                0
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_Count                              1
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_FieldMask                 0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_ReadMask                  0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_WriteMask                 0x00000000
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_ResetValue                0x00000000


#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_COUNT                           31:0
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_COUNT_End                         31
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_COUNT_Start                        0
#define MWV207REG_DEC400_TOTAL_READS_REQ_IN_COUNT_Type                       U32




#define mwv207regDEC400TotalWritesReqInRegAddrs                           0x6211
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_Address                     0x18844
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_MSB                              15
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_LSB                               0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_BLK                               0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_Count                             1
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_WriteMask                0x00000000
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_ResetValue               0x00000000


#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_COUNT                          31:0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_COUNT_End                        31
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_COUNT_Start                       0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_IN_COUNT_Type                      U32




#define mwv207regDEC400TotalReadLastsInRegAddrs                           0x6212
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_Address                     0x18848
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_MSB                              15
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_LSB                               0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_BLK                               0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_Count                             1
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_WriteMask                0x00000000
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_ResetValue               0x00000000


#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_COUNT                          31:0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_COUNT_End                        31
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_COUNT_Start                       0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_IN_COUNT_Type                      U32




#define mwv207regDEC400TotalWriteLastsInRegAddrs                          0x6213
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_Address                    0x1884C
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_MSB                             15
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_LSB                              0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_BLK                              0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_Count                            1
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_FieldMask               0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_ReadMask                0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_WriteMask               0x00000000
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_ResetValue              0x00000000


#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_COUNT                         31:0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_COUNT_End                       31
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_COUNT_Start                      0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_IN_COUNT_Type                     U32




#define mwv207regDEC400TotalWriteResponseInRegAddrs                       0x6214
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_Address                 0x18850
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_MSB                          15
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_LSB                           0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_BLK                           0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_Count                         1
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_FieldMask            0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_ReadMask             0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_WriteMask            0x00000000
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_ResetValue           0x00000000


#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_COUNT                      31:0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_COUNT_End                    31
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_COUNT_Start                   0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_IN_COUNT_Type                  U32




#define mwv207regDEC400TotalReadsOUTRegAddrs                              0x6215
#define MWV207REG_DEC400_TOTAL_READS_OUT_Address                         0x18854
#define MWV207REG_DEC400_TOTAL_READS_OUT_MSB                                  15
#define MWV207REG_DEC400_TOTAL_READS_OUT_LSB                                   0
#define MWV207REG_DEC400_TOTAL_READS_OUT_BLK                                   0
#define MWV207REG_DEC400_TOTAL_READS_OUT_Count                                 1
#define MWV207REG_DEC400_TOTAL_READS_OUT_FieldMask                    0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_OUT_ReadMask                     0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_OUT_WriteMask                    0x00000000
#define MWV207REG_DEC400_TOTAL_READS_OUT_ResetValue                   0x00000000


#define MWV207REG_DEC400_TOTAL_READS_OUT_COUNT                              31:0
#define MWV207REG_DEC400_TOTAL_READS_OUT_COUNT_End                            31
#define MWV207REG_DEC400_TOTAL_READS_OUT_COUNT_Start                           0
#define MWV207REG_DEC400_TOTAL_READS_OUT_COUNT_Type                          U32




#define mwv207regDEC400TotalWritesOUTRegAddrs                             0x6216
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_Address                        0x18858
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_MSB                                 15
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_LSB                                  0
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_BLK                                  0
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_Count                                1
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_FieldMask                   0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_ReadMask                    0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_WriteMask                   0x00000000
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_ResetValue                  0x00000000


#define MWV207REG_DEC400_TOTAL_WRITES_OUT_COUNT                             31:0
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_COUNT_End                           31
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_COUNT_Start                          0
#define MWV207REG_DEC400_TOTAL_WRITES_OUT_COUNT_Type                         U32




#define mwv207regDEC400TotalReadBurstsOUTRegAddrs                         0x6217
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_Address                   0x1885C
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_MSB                            15
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_LSB                             0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_BLK                             0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_Count                           1
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_FieldMask              0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_ReadMask               0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_WriteMask              0x00000000
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_ResetValue             0x00000000


#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_COUNT                        31:0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_COUNT_End                      31
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_COUNT_Start                     0
#define MWV207REG_DEC400_TOTAL_READ_BURSTS_OUT_COUNT_Type                    U32




#define mwv207regDEC400TotalWriteBurstsOUTRegAddrs                        0x6218
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_Address                  0x18860
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_MSB                           15
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_LSB                            0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_BLK                            0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_Count                          1
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_WriteMask             0x00000000
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_ResetValue            0x00000000


#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_COUNT                       31:0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_COUNT_End                     31
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_COUNT_Start                    0
#define MWV207REG_DEC400_TOTAL_WRITE_BURSTS_OUT_COUNT_Type                   U32




#define mwv207regDEC400TotalReadsReqOUTRegAddrs                           0x6219
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_Address                     0x18864
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_MSB                              15
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_LSB                               0
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_BLK                               0
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_Count                             1
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_WriteMask                0x00000000
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_ResetValue               0x00000000


#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_COUNT                          31:0
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_COUNT_End                        31
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_COUNT_Start                       0
#define MWV207REG_DEC400_TOTAL_READS_REQ_OUT_COUNT_Type                      U32




#define mwv207regDEC400TotalWritesReqOUTRegAddrs                          0x621A
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_Address                    0x18868
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_MSB                             15
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_LSB                              0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_BLK                              0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_Count                            1
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_FieldMask               0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_ReadMask                0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_WriteMask               0x00000000
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_ResetValue              0x00000000


#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_COUNT                         31:0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_COUNT_End                       31
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_COUNT_Start                      0
#define MWV207REG_DEC400_TOTAL_WRITES_REQ_OUT_COUNT_Type                     U32




#define mwv207regDEC400TotalReadLastsOUTRegAddrs                          0x621B
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_Address                    0x1886C
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_MSB                             15
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_LSB                              0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_BLK                              0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_Count                            1
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_FieldMask               0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_ReadMask                0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_WriteMask               0x00000000
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_ResetValue              0x00000000


#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_COUNT                         31:0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_COUNT_End                       31
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_COUNT_Start                      0
#define MWV207REG_DEC400_TOTAL_READ_LASTS_OUT_COUNT_Type                     U32




#define mwv207regDEC400TotalWriteLastsOUTRegAddrs                         0x621C
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_Address                   0x18870
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_MSB                            15
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_LSB                             0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_BLK                             0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_Count                           1
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_FieldMask              0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_ReadMask               0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_WriteMask              0x00000000
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_ResetValue             0x00000000


#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_COUNT                        31:0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_COUNT_End                      31
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_COUNT_Start                     0
#define MWV207REG_DEC400_TOTAL_WRITE_LASTS_OUT_COUNT_Type                    U32




#define mwv207regDEC400TotalWriteResponseOUTRegAddrs                      0x621D
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_Address                0x18874
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_MSB                         15
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_LSB                          0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_BLK                          0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_Count                        1
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_FieldMask           0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_ReadMask            0xFFFFFFFF
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_WriteMask           0x00000000
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_ResetValue          0x00000000


#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_COUNT                     31:0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_COUNT_End                   31
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_COUNT_Start                  0
#define MWV207REG_DEC400_TOTAL_WRITE_RESPONSE_OUT_COUNT_Type                 U32




#define mwv207regDEC400StatusRegAddrs                                     0x621E
#define MWV207REG_DEC400_STATUS_Address                                  0x18878
#define MWV207REG_DEC400_STATUS_MSB                                           15
#define MWV207REG_DEC400_STATUS_LSB                                            0
#define MWV207REG_DEC400_STATUS_BLK                                            0
#define MWV207REG_DEC400_STATUS_Count                                          1
#define MWV207REG_DEC400_STATUS_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_STATUS_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_STATUS_WriteMask                             0x00000000
#define MWV207REG_DEC400_STATUS_ResetValue                            0x00000FFD


#define MWV207REG_DEC400_STATUS_IDLE                                         0:0
#define MWV207REG_DEC400_STATUS_IDLE_End                                       0
#define MWV207REG_DEC400_STATUS_IDLE_Start                                     0
#define MWV207REG_DEC400_STATUS_IDLE_Type                                    U01

#define MWV207REG_DEC400_STATUS_BUTT_JOINT                                   1:1
#define MWV207REG_DEC400_STATUS_BUTT_JOINT_End                                 1
#define MWV207REG_DEC400_STATUS_BUTT_JOINT_Start                               1
#define MWV207REG_DEC400_STATUS_BUTT_JOINT_Type                              U01


#define MWV207REG_DEC400_STATUS_IDLE_VEC                                    31:2
#define MWV207REG_DEC400_STATUS_IDLE_VEC_End                                  31
#define MWV207REG_DEC400_STATUS_IDLE_VEC_Start                                 2
#define MWV207REG_DEC400_STATUS_IDLE_VEC_Type                                U30



#define mwv207regDEC400DebugInfoSelectRegAddrs                            0x621F
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_Address                       0x1887C
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_MSB                                15
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_LSB                                 0
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_BLK                                 0
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_Count                               1
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_FieldMask                  0x8000007F
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_ReadMask                   0x8000007F
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_WriteMask                  0x8000007F
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_ResetValue                 0x00000000


#define MWV207REG_DEC400_DEBUG_INFO_SELECT_VALUE                             6:0
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_VALUE_End                           6
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_VALUE_Start                         0
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_VALUE_Type                        U07


#define MWV207REG_DEC400_DEBUG_INFO_SELECT_ENABLE                          31:31
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_ENABLE_End                         31
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_ENABLE_Start                       31
#define MWV207REG_DEC400_DEBUG_INFO_SELECT_ENABLE_Type                       U01



#define mwv207regDEC400ReadConfigRegAddrs                                 0x6220
#define MWV207REG_DEC400_READ_CONFIG_Address                             0x18880
#define MWV207REG_DEC400_READ_CONFIG_MSB                                      15
#define MWV207REG_DEC400_READ_CONFIG_LSB                                       5
#define MWV207REG_DEC400_READ_CONFIG_BLK                                       5
#define MWV207REG_DEC400_READ_CONFIG_Count                                    32
#define MWV207REG_DEC400_READ_CONFIG_FieldMask                        0x7FFFFFFF
#define MWV207REG_DEC400_READ_CONFIG_ReadMask                         0x7FFFFFFF
#define MWV207REG_DEC400_READ_CONFIG_WriteMask                        0x7E0300FF
#define MWV207REG_DEC400_READ_CONFIG_ResetValue                       0x00020000


#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ENABLE                      0:0
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ENABLE_End                    0
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ENABLE_Start                  0
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ENABLE_Type                 U01
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ENABLE_DISABLE            0x0
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ENABLE_ENABLE             0x1


#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE                        2:1
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE_End                      2
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE_Start                    1
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE_Type                   U02
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE_SIZE64_BYTE          0x0
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE_SIZE128_BYTE         0x1
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE_SIZE256_BYTE         0x2
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_SIZE_SIZE512_BYTE         0x3

#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT                      7:3
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_End                    7
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_Start                  3
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_Type                 U05
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_ARGB8             0x00
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_XRGB8             0x01

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_AYUV              0x02
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_UYVY              0x03
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_YUY2              0x04
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_YUV_ONLY          0x05
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_UV_MIX            0x06
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_ARGB4             0x07
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_XRGB4             0x08
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_A1RGB5            0x09
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_X1RGB5            0x0A
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_R5G6B5            0x0B
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_A2R10G10B10       0x0F

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_BAYER             0x10

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_COEFFICIENT       0x12

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_ARGB16            0x13

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_FORMAT_X2RGB10           0x15


#define MWV207REG_DEC400_READ_CONFIG_RESERVE1                               15:8
#define MWV207REG_DEC400_READ_CONFIG_RESERVE1_End                             15
#define MWV207REG_DEC400_READ_CONFIG_RESERVE1_Start                            8
#define MWV207REG_DEC400_READ_CONFIG_RESERVE1_Type                           U08


#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE                17:16
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE_End               17
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE_Start             16
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE_Type             U02

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN1_BYTE    0x0

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN16_BYTE   0x1
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN32_BYTE   0x2

#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN64_BYTE   0x3


#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE1               20:18
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE1_End              20
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE1_Start            18
#define MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE1_Type            U03
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE1_ALIGN256_BYTE 0x4
#define   MWV207REG_DEC400_READ_CONFIG_COMPRESSION_ALIGN_MODE1_ALIGN512_BYTE 0x5


#define MWV207REG_DEC400_READ_CONFIG_RESERVE2                              21:21
#define MWV207REG_DEC400_READ_CONFIG_RESERVE2_End                             21
#define MWV207REG_DEC400_READ_CONFIG_RESERVE2_Start                           21
#define MWV207REG_DEC400_READ_CONFIG_RESERVE2_Type                           U01

#define MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE                       24:22
#define MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE_End                      24
#define MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE_Start                    22
#define MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE_Type                    U03
#define   MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE_TILE1_ALIGN           0x0
#define   MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE_TILE2_ALIGN           0x1
#define   MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE_TILE4_ALIGN           0x2
#define   MWV207REG_DEC400_READ_CONFIG_TILE_ALIGN_MODE_CBSR_ALIGN            0x3

#define MWV207REG_DEC400_READ_CONFIG_TILE_MODE                             30:25
#define MWV207REG_DEC400_READ_CONFIG_TILE_MODE_End                            30
#define MWV207REG_DEC400_READ_CONFIG_TILE_MODE_Start                          25
#define MWV207REG_DEC400_READ_CONFIG_TILE_MODE_Type                          U06
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE8X8_XMAJOR             0x00
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE8X8_YMAJOR             0x01
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE16X4                   0x02
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE8X4                    0x03
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE4X8                    0x04
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER16X4                 0x06
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE64X4                   0x07

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE32X4                   0x08
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER256X1                0x09
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER128X1                0x0A
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER64X4                 0x0B

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER256X2                0x0C

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER128X2                0x0D

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER128X4                0x0E
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER64X1                 0x0F
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE16X8                   0x10

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE8X16                   0x11

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER512X1                0x12
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER32X4                 0x13

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER64X2                 0x14

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER32X2                 0x15
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER32X1                 0x16
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_RASTER16X1                 0x17

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE128X4                  0x18

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE256X4                  0x19

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE512X4                  0x1A

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE16X16                  0x1B

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE32X16                  0x1C

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE64X16                  0x1D

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE128X8                  0x1E
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE8X4_S                  0x1F
#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE16X4_S                 0x20

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE32X4_S                 0x21

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE16X4_LSB               0x22

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE32X4_LSB               0x23

#define   MWV207REG_DEC400_READ_CONFIG_TILE_MODE_TILE32X8                   0x24



#define mwv207regDEC400ReadExConfigRegAddrs                               0x6240
#define MWV207REG_DEC400_READ_EX_CONFIG_Address                          0x18900
#define MWV207REG_DEC400_READ_EX_CONFIG_MSB                                   15
#define MWV207REG_DEC400_READ_EX_CONFIG_LSB                                    5
#define MWV207REG_DEC400_READ_EX_CONFIG_BLK                                    5
#define MWV207REG_DEC400_READ_EX_CONFIG_Count                                 32
#define MWV207REG_DEC400_READ_EX_CONFIG_FieldMask                     0x3DFFFFFF
#define MWV207REG_DEC400_READ_EX_CONFIG_ReadMask                      0x3DFFFFFF
#define MWV207REG_DEC400_READ_EX_CONFIG_WriteMask                     0x00070001
#define MWV207REG_DEC400_READ_EX_CONFIG_ResetValue                    0x00000000

#define MWV207REG_DEC400_READ_EX_CONFIG_TPC                                  0:0
#define MWV207REG_DEC400_READ_EX_CONFIG_TPC_End                                0
#define MWV207REG_DEC400_READ_EX_CONFIG_TPC_Start                              0
#define MWV207REG_DEC400_READ_EX_CONFIG_TPC_Type                             U01
#define   MWV207REG_DEC400_READ_EX_CONFIG_TPC_DISABLE                        0x0
#define   MWV207REG_DEC400_READ_EX_CONFIG_TPC_ENABLE                         0x1


#define MWV207REG_DEC400_READ_EX_CONFIG_RESERVE0                             2:1
#define MWV207REG_DEC400_READ_EX_CONFIG_RESERVE0_End                           2
#define MWV207REG_DEC400_READ_EX_CONFIG_RESERVE0_Start                         1
#define MWV207REG_DEC400_READ_EX_CONFIG_RESERVE0_Type                        U02

#define MWV207REG_DEC400_READ_EX_CONFIG_CBSR_WIDTH                          15:3
#define MWV207REG_DEC400_READ_EX_CONFIG_CBSR_WIDTH_End                        15
#define MWV207REG_DEC400_READ_EX_CONFIG_CBSR_WIDTH_Start                       3
#define MWV207REG_DEC400_READ_EX_CONFIG_CBSR_WIDTH_Type                      U13

#define MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH                          18:16
#define MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_End                         18
#define MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_Start                       16
#define MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_Type                       U03
#define   MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_BIT8                     0x0
#define   MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_BIT10                    0x1
#define   MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_BIT12                    0x2
#define   MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_BIT14                    0x3
#define   MWV207REG_DEC400_READ_EX_CONFIG_BIT_DEPTH_BIT16                    0x4


#define MWV207REG_DEC400_READ_EX_CONFIG_TILE_Y                             19:19
#define MWV207REG_DEC400_READ_EX_CONFIG_TILE_Y_End                            19
#define MWV207REG_DEC400_READ_EX_CONFIG_TILE_Y_Start                          19
#define MWV207REG_DEC400_READ_EX_CONFIG_TILE_Y_Type                          U01
#define   MWV207REG_DEC400_READ_EX_CONFIG_TILE_Y_DISABLE                     0x0
#define   MWV207REG_DEC400_READ_EX_CONFIG_TILE_Y_ENABLE                      0x1

#define MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE                        24:20
#define MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_End                       24
#define MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_Start                     20
#define MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_Type                     U05
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_DEFAULT               0x00
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM0           0x01
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM1           0x02
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM2           0x03
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM3           0x04
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_TNR_STREAM_Y          0x05
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_TNR_STREAM_UV         0x06
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_GDC_STREAM_Y          0x07
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_GDC_STREAM_U          0x08
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_GDC_STREAM_V          0x09
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_VPU_SRC_Y             0x0A
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_VPU_SRC_UV            0x0B
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_VPU_REF_Y             0x0C
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_VPU_REF_UV            0x0D
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_AY         0x0E
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_AU         0x0F
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_AV         0x10
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BY         0x11
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BU         0x12
#define   MWV207REG_DEC400_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BV         0x13

#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_READ_MODE                 26:26
#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_READ_MODE_End                26
#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_READ_MODE_Start              26
#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_READ_MODE_Type              U01
#define   MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_READ_MODE_DISABLE         0x0
#define   MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_READ_MODE_ENABLE          0x1

#define MWV207REG_DEC400_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT            27:27
#define MWV207REG_DEC400_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_End           27
#define MWV207REG_DEC400_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Start         27
#define MWV207REG_DEC400_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Type         U01
#define   MWV207REG_DEC400_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_LRU        0x0
#define   MWV207REG_DEC400_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_FIFO       0x1


#define MWV207REG_DEC400_READ_EX_CONFIG_INTEL_P010                         28:28
#define MWV207REG_DEC400_READ_EX_CONFIG_INTEL_P010_End                        28
#define MWV207REG_DEC400_READ_EX_CONFIG_INTEL_P010_Start                      28
#define MWV207REG_DEC400_READ_EX_CONFIG_INTEL_P010_Type                      U01
#define   MWV207REG_DEC400_READ_EX_CONFIG_INTEL_P010_DISABLE                 0x0
#define   MWV207REG_DEC400_READ_EX_CONFIG_INTEL_P010_ENABLE                  0x1

#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_REPLACEMENT               29:29
#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_REPLACEMENT_End              29
#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_REPLACEMENT_Start            29
#define MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_REPLACEMENT_Type            U01
#define   MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_REPLACEMENT_LRU           0x0
#define   MWV207REG_DEC400_READ_EX_CONFIG_TS_CACHE_REPLACEMENT_FIFO          0x1



#define mwv207regDEC400WriteConfigRegAddrs                                0x6260
#define MWV207REG_DEC400_WRITE_CONFIG_Address                            0x18980
#define MWV207REG_DEC400_WRITE_CONFIG_MSB                                     15
#define MWV207REG_DEC400_WRITE_CONFIG_LSB                                      5
#define MWV207REG_DEC400_WRITE_CONFIG_BLK                                      5
#define MWV207REG_DEC400_WRITE_CONFIG_Count                                   32
#define MWV207REG_DEC400_WRITE_CONFIG_FieldMask                       0x7FFFFFFF
#define MWV207REG_DEC400_WRITE_CONFIG_ReadMask                        0x7FFFFFFF
#define MWV207REG_DEC400_WRITE_CONFIG_WriteMask                       0x7E0300FF
#define MWV207REG_DEC400_WRITE_CONFIG_ResetValue                      0x00020000


#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ENABLE                     0:0
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ENABLE_End                   0
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ENABLE_Start                 0
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ENABLE_Type                U01
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ENABLE_DISABLE           0x0
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ENABLE_ENABLE            0x1


#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE                       2:1
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE_End                     2
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE_Start                   1
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE_Type                  U02
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE_SIZE64_BYTE         0x0
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE_SIZE128_BYTE        0x1
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE_SIZE256_BYTE        0x2
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_SIZE_SIZE512_BYTE        0x3

#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT                     7:3
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_End                   7
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_Start                 3
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_Type                U05
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_ARGB8            0x00
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_XRGB8            0x01
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_AYUV             0x02
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_UYVY             0x03
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_YUY2             0x04
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_YUV_ONLY         0x05
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_UV_MIX           0x06
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_ARGB4            0x07
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_XRGB4            0x08

#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_A1RGB5           0x09

#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_X1RGB5           0x0A

#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_R5G6B5           0x0B
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_A2R10G10B10      0x0F
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_BAYER            0x10

#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_COEFFICIENT      0x12
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_ARGB16           0x13
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_FORMAT_X2RGB10          0x15


#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE1                              15:8
#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE1_End                            15
#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE1_Start                           8
#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE1_Type                          U08


#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE               17:16
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_End              17
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_Start            16
#define MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_Type            U02
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN1_BYTE   0x0
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN16_BYTE  0x1
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN32_BYTE  0x2
#define   MWV207REG_DEC400_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN64_BYTE  0x3


#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE2                             21:18
#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE2_End                            21
#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE2_Start                          18
#define MWV207REG_DEC400_WRITE_CONFIG_RESERVE2_Type                          U04

#define MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE                      24:22
#define MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE_End                     24
#define MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE_Start                   22
#define MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE_Type                   U03
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE_TILE1_ALIGN          0x0
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE_TILE2_ALIGN          0x1
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE_TILE4_ALIGN          0x2
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_ALIGN_MODE_CBSR_ALIGN           0x3

#define MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE                            30:25
#define MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_End                           30
#define MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_Start                         25
#define MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_Type                         U06
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE8X8_XMAJOR            0x00
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE8X8_YMAJOR            0x01
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE16X4                  0x02
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE8X4                   0x03
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE4X8                   0x04
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER16X4                0x06
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE64X4                  0x07

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE32X4                  0x08
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER256X1               0x09
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER128X1               0x0A
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER64X4                0x0B

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER256X2               0x0C

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER128X2               0x0D

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER128X4               0x0E
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER64X1                0x0F
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE16X8                  0x10

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE8X16                  0x11

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER512X1               0x12
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER32X4                0x13

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER64X2                0x14

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER32X2                0x15
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER32X1                0x16
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_RASTER16X1                0x17

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE128X4                 0x18

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE256X4                 0x19

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE512X4                 0x1A

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE16X16                 0x1B

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE32X16                 0x1C

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE64X16                 0x1D

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE128X8                 0x1E
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE8X4_S                 0x1F
#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE16X4_S                0x20

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE32X4_S                0x21

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE16X4_LSB              0x22

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE32X4_LSB              0x23

#define   MWV207REG_DEC400_WRITE_CONFIG_TILE_MODE_TILE32X8                  0x24



#define mwv207regDEC400WriteExConfigRegAddrs                              0x6280
#define MWV207REG_DEC400_WRITE_EX_CONFIG_Address                         0x18A00
#define MWV207REG_DEC400_WRITE_EX_CONFIG_MSB                                  15
#define MWV207REG_DEC400_WRITE_EX_CONFIG_LSB                                   5
#define MWV207REG_DEC400_WRITE_EX_CONFIG_BLK                                   5
#define MWV207REG_DEC400_WRITE_EX_CONFIG_Count                                32
#define MWV207REG_DEC400_WRITE_EX_CONFIG_FieldMask                    0x3DFFFFFF
#define MWV207REG_DEC400_WRITE_EX_CONFIG_ReadMask                     0x3DFFFFFF
#define MWV207REG_DEC400_WRITE_EX_CONFIG_WriteMask                    0x00070001
#define MWV207REG_DEC400_WRITE_EX_CONFIG_ResetValue                   0x00000000


#define MWV207REG_DEC400_WRITE_EX_CONFIG_TPC                                 0:0
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TPC_End                               0
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TPC_Start                             0
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TPC_Type                            U01
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TPC_DISABLE                       0x0
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TPC_ENABLE                        0x1


#define MWV207REG_DEC400_WRITE_EX_CONFIG_RESERVE0                            2:1
#define MWV207REG_DEC400_WRITE_EX_CONFIG_RESERVE0_End                          2
#define MWV207REG_DEC400_WRITE_EX_CONFIG_RESERVE0_Start                        1
#define MWV207REG_DEC400_WRITE_EX_CONFIG_RESERVE0_Type                       U02

#define MWV207REG_DEC400_WRITE_EX_CONFIG_CBSR_WIDTH                         15:3
#define MWV207REG_DEC400_WRITE_EX_CONFIG_CBSR_WIDTH_End                       15
#define MWV207REG_DEC400_WRITE_EX_CONFIG_CBSR_WIDTH_Start                      3
#define MWV207REG_DEC400_WRITE_EX_CONFIG_CBSR_WIDTH_Type                     U13

#define MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH                         18:16
#define MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_End                        18
#define MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_Start                      16
#define MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_Type                      U03
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_BIT8                    0x0
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_BIT10                   0x1
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_BIT12                   0x2
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_BIT14                   0x3
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_BIT_DEPTH_BIT16                   0x4


#define MWV207REG_DEC400_WRITE_EX_CONFIG_TILE_Y                            19:19
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TILE_Y_End                           19
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TILE_Y_Start                         19
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TILE_Y_Type                         U01
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TILE_Y_DISABLE                    0x0
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TILE_Y_ENABLE                     0x1

#define MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE                       24:20
#define MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_End                      24
#define MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_Start                    20
#define MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_Type                    U05
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_RESERVED             0x00
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM0         0x01
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM1         0x02
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM2         0x03
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM3         0x04
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM0_Y        0x05
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM0_U        0x06
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM0_V        0x07
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM1_Y        0x08
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM1_U        0x09
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM1_V        0x0A
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM2_Y        0x0B
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM2_U        0x0C
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM2_V        0x0D
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_PSA_STREAM_Y         0x0E
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_PSA_STREAM_U         0x0F
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_PSA_STREAM_V         0x10
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_TNR_STREAM_Y         0x11
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_TNR_STREAM_UV        0x12
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_VPU_STREAM_Y         0x13
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_VPU_STREAM_UV        0x14
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BY        0x15
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BU        0x16
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BV        0x17

#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_READ_MODE                26:26
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_End               26
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_Start             26
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_Type             U01
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_DISABLE        0x0
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_ENABLE         0x1

#define MWV207REG_DEC400_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT           27:27
#define MWV207REG_DEC400_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_End          27
#define MWV207REG_DEC400_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Start        27
#define MWV207REG_DEC400_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Type        U01
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_LRU       0x0
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_FIFO      0x1


#define MWV207REG_DEC400_WRITE_EX_CONFIG_INTEL_P010                        28:28
#define MWV207REG_DEC400_WRITE_EX_CONFIG_INTEL_P010_End                       28
#define MWV207REG_DEC400_WRITE_EX_CONFIG_INTEL_P010_Start                     28
#define MWV207REG_DEC400_WRITE_EX_CONFIG_INTEL_P010_Type                     U01
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_INTEL_P010_DISABLE                0x0
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_INTEL_P010_ENABLE                 0x1

#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_REPLACEMENT              29:29
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_REPLACEMENT_End             29
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_REPLACEMENT_Start           29
#define MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_REPLACEMENT_Type           U01
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_REPLACEMENT_LRU          0x0
#define   MWV207REG_DEC400_WRITE_EX_CONFIG_TS_CACHE_REPLACEMENT_FIFO         0x1




#define mwv207regDEC400ReadBufferBaseRegAddrs                             0x62A0
#define MWV207REG_DEC400_READ_BUFFER_BASE_Address                        0x18A80
#define MWV207REG_DEC400_READ_BUFFER_BASE_MSB                                 15
#define MWV207REG_DEC400_READ_BUFFER_BASE_LSB                                  5
#define MWV207REG_DEC400_READ_BUFFER_BASE_BLK                                  5
#define MWV207REG_DEC400_READ_BUFFER_BASE_Count                               32
#define MWV207REG_DEC400_READ_BUFFER_BASE_FieldMask                   0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_BASE_ReadMask                    0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_BASE_WriteMask                   0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_BASE_ResetValue                  0xFFFFFFFF


#define MWV207REG_DEC400_READ_BUFFER_BASE_ADDRESS                           31:0
#define MWV207REG_DEC400_READ_BUFFER_BASE_ADDRESS_End                         31
#define MWV207REG_DEC400_READ_BUFFER_BASE_ADDRESS_Start                        0
#define MWV207REG_DEC400_READ_BUFFER_BASE_ADDRESS_Type                       U32




#define mwv207regDEC400ReadBufferBaseExRegAddrs                           0x62C0
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_Address                     0x18B00
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_MSB                              15
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_LSB                               5
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_BLK                               5
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_Count                            32
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_WriteMask                0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_ResetValue               0xFFFFFFFF


#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_ADDRESS                        31:0
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_ADDRESS_End                      31
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_ADDRESS_Start                     0
#define MWV207REG_DEC400_READ_BUFFER_BASE_EX_ADDRESS_Type                    U32



#define mwv207regDEC400ReadBufferEndRegAddrs                              0x62E0
#define MWV207REG_DEC400_READ_BUFFER_END_Address                         0x18B80
#define MWV207REG_DEC400_READ_BUFFER_END_MSB                                  15
#define MWV207REG_DEC400_READ_BUFFER_END_LSB                                   5
#define MWV207REG_DEC400_READ_BUFFER_END_BLK                                   5
#define MWV207REG_DEC400_READ_BUFFER_END_Count                                32
#define MWV207REG_DEC400_READ_BUFFER_END_FieldMask                    0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_END_ReadMask                     0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_END_WriteMask                    0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_END_ResetValue                   0xFFFFFFFF


#define MWV207REG_DEC400_READ_BUFFER_END_ADDRESS                            31:0
#define MWV207REG_DEC400_READ_BUFFER_END_ADDRESS_End                          31
#define MWV207REG_DEC400_READ_BUFFER_END_ADDRESS_Start                         0
#define MWV207REG_DEC400_READ_BUFFER_END_ADDRESS_Type                        U32



#define mwv207regDEC400ReadBufferEndExRegAddrs                            0x6300
#define MWV207REG_DEC400_READ_BUFFER_END_EX_Address                      0x18C00
#define MWV207REG_DEC400_READ_BUFFER_END_EX_MSB                               15
#define MWV207REG_DEC400_READ_BUFFER_END_EX_LSB                                5
#define MWV207REG_DEC400_READ_BUFFER_END_EX_BLK                                5
#define MWV207REG_DEC400_READ_BUFFER_END_EX_Count                             32
#define MWV207REG_DEC400_READ_BUFFER_END_EX_FieldMask                 0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_END_EX_ReadMask                  0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_END_EX_WriteMask                 0xFFFFFFFF
#define MWV207REG_DEC400_READ_BUFFER_END_EX_ResetValue                0xFFFFFFFF


#define MWV207REG_DEC400_READ_BUFFER_END_EX_ADDRESS                         31:0
#define MWV207REG_DEC400_READ_BUFFER_END_EX_ADDRESS_End                       31
#define MWV207REG_DEC400_READ_BUFFER_END_EX_ADDRESS_Start                      0
#define MWV207REG_DEC400_READ_BUFFER_END_EX_ADDRESS_Type                     U32




#define mwv207regDEC400ReadFlushCacheRegAddrs                             0x6320
#define MWV207REG_DEC400_READ_FLUSH_CACHE_Address                        0x18C80
#define MWV207REG_DEC400_READ_FLUSH_CACHE_MSB                                 15
#define MWV207REG_DEC400_READ_FLUSH_CACHE_LSB                                  5
#define MWV207REG_DEC400_READ_FLUSH_CACHE_BLK                                  5
#define MWV207REG_DEC400_READ_FLUSH_CACHE_Count                               32
#define MWV207REG_DEC400_READ_FLUSH_CACHE_FieldMask                   0xFFFFFFFF
#define MWV207REG_DEC400_READ_FLUSH_CACHE_ReadMask                    0xFFFFFFFF
#define MWV207REG_DEC400_READ_FLUSH_CACHE_WriteMask                   0x00000000
#define MWV207REG_DEC400_READ_FLUSH_CACHE_ResetValue                  0xFFFFFFFF


#define MWV207REG_DEC400_READ_FLUSH_CACHE_ADDRESS                           31:0
#define MWV207REG_DEC400_READ_FLUSH_CACHE_ADDRESS_End                         31
#define MWV207REG_DEC400_READ_FLUSH_CACHE_ADDRESS_Start                        0
#define MWV207REG_DEC400_READ_FLUSH_CACHE_ADDRESS_Type                       U32



#define mwv207regDEC400ReadFlushCacheExRegAddrs                           0x6340
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_Address                     0x18D00
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_MSB                              15
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_LSB                               5
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_BLK                               5
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_Count                            32
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_WriteMask                0xFFFFFFFF
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_ResetValue               0xFFFFFFFF


#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_ADDRESS                        31:0
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_ADDRESS_End                      31
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_ADDRESS_Start                     0
#define MWV207REG_DEC400_READ_FLUSH_CACHE_EX_ADDRESS_Type                    U32



#define mwv207regDEC400WriteBufferBaseRegAddrs                            0x6360
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_Address                       0x18D80
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_MSB                                15
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_LSB                                 5
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_BLK                                 5
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_Count                              32
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_FieldMask                  0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_ReadMask                   0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_WriteMask                  0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_ResetValue                 0xFFFFFFFF


#define MWV207REG_DEC400_WRITE_BUFFER_BASE_ADDRESS                          31:0
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_ADDRESS_End                        31
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_ADDRESS_Start                       0
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_ADDRESS_Type                      U32



#define mwv207regDEC400WriteBufferBaseExRegAddrs                          0x6380
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_Address                    0x18E00
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_MSB                             15
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_LSB                              5
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_BLK                              5
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_Count                           32
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_FieldMask               0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_ReadMask                0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_WriteMask               0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_ResetValue              0xFFFFFFFF


#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_ADDRESS                       31:0
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_ADDRESS_End                     31
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_ADDRESS_Start                    0
#define MWV207REG_DEC400_WRITE_BUFFER_BASE_EX_ADDRESS_Type                   U32



#define mwv207regDEC400WriteBufferEndRegAddrs                             0x63A0
#define MWV207REG_DEC400_WRITE_BUFFER_END_Address                        0x18E80
#define MWV207REG_DEC400_WRITE_BUFFER_END_MSB                                 15
#define MWV207REG_DEC400_WRITE_BUFFER_END_LSB                                  5
#define MWV207REG_DEC400_WRITE_BUFFER_END_BLK                                  5
#define MWV207REG_DEC400_WRITE_BUFFER_END_Count                               32
#define MWV207REG_DEC400_WRITE_BUFFER_END_FieldMask                   0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_END_ReadMask                    0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_END_WriteMask                   0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_END_ResetValue                  0xFFFFFFFF


#define MWV207REG_DEC400_WRITE_BUFFER_END_ADDRESS                           31:0
#define MWV207REG_DEC400_WRITE_BUFFER_END_ADDRESS_End                         31
#define MWV207REG_DEC400_WRITE_BUFFER_END_ADDRESS_Start                        0
#define MWV207REG_DEC400_WRITE_BUFFER_END_ADDRESS_Type                       U32



#define mwv207regDEC400WriteBufferEndExRegAddrs                           0x63C0
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_Address                     0x18F00
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_MSB                              15
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_LSB                               5
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_BLK                               5
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_Count                            32
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_WriteMask                0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_ResetValue               0xFFFFFFFF


#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_ADDRESS                        31:0
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_ADDRESS_End                      31
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_ADDRESS_Start                     0
#define MWV207REG_DEC400_WRITE_BUFFER_END_EX_ADDRESS_Type                    U32



#define mwv207regDEC400WriteFlushCacheRegAddrs                            0x63E0
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_Address                       0x18F80
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_MSB                                15
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_LSB                                 5
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_BLK                                 5
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_Count                              32
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_FieldMask                  0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_ReadMask                   0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_WriteMask                  0x00000000
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_ResetValue                 0xFFFFFFFF


#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_ADDRESS                          31:0
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_ADDRESS_End                        31
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_ADDRESS_Start                       0
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_ADDRESS_Type                      U32



#define mwv207regDEC400WriteFlushCacheExRegAddrs                          0x6400
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_Address                    0x19000
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_MSB                             15
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_LSB                              5
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_BLK                              5
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_Count                           32
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_FieldMask               0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_ReadMask                0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_WriteMask               0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_ResetValue              0xFFFFFFFF


#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_ADDRESS                       31:0
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_ADDRESS_End                     31
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_ADDRESS_Start                    0
#define MWV207REG_DEC400_WRITE_FLUSH_CACHE_EX_ADDRESS_Type                   U32



#define mwv207regDEC400ReadCacheBaseRegAddrs                              0x6420
#define MWV207REG_DEC400_READ_CACHE_BASE_Address                         0x19080
#define MWV207REG_DEC400_READ_CACHE_BASE_MSB                                  15
#define MWV207REG_DEC400_READ_CACHE_BASE_LSB                                   5
#define MWV207REG_DEC400_READ_CACHE_BASE_BLK                                   5
#define MWV207REG_DEC400_READ_CACHE_BASE_Count                                32
#define MWV207REG_DEC400_READ_CACHE_BASE_FieldMask                    0xFFFFFFFF
#define MWV207REG_DEC400_READ_CACHE_BASE_ReadMask                     0xFFFFFFFF
#define MWV207REG_DEC400_READ_CACHE_BASE_WriteMask                    0xFFFFFFFF
#define MWV207REG_DEC400_READ_CACHE_BASE_ResetValue                   0x00000000


#define MWV207REG_DEC400_READ_CACHE_BASE_ADDRESS                            31:0
#define MWV207REG_DEC400_READ_CACHE_BASE_ADDRESS_End                          31
#define MWV207REG_DEC400_READ_CACHE_BASE_ADDRESS_Start                         0
#define MWV207REG_DEC400_READ_CACHE_BASE_ADDRESS_Type                        U32



#define mwv207regDEC400ReadCacheBaseExRegAddrs                            0x6440
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_Address                      0x19100
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_MSB                               15
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_LSB                                5
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_BLK                                5
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_Count                             32
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_FieldMask                 0xFFFFFFFF
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_ReadMask                  0xFFFFFFFF
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_WriteMask                 0xFFFFFFFF
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_ResetValue                0x00000000


#define MWV207REG_DEC400_READ_CACHE_BASE_EX_ADDRESS                         31:0
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_ADDRESS_End                       31
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_ADDRESS_Start                      0
#define MWV207REG_DEC400_READ_CACHE_BASE_EX_ADDRESS_Type                     U32



#define mwv207regDEC400WriteCacheBaseRegAddrs                             0x6460
#define MWV207REG_DEC400_WRITE_CACHE_BASE_Address                        0x19180
#define MWV207REG_DEC400_WRITE_CACHE_BASE_MSB                                 15
#define MWV207REG_DEC400_WRITE_CACHE_BASE_LSB                                  5
#define MWV207REG_DEC400_WRITE_CACHE_BASE_BLK                                  5
#define MWV207REG_DEC400_WRITE_CACHE_BASE_Count                               32
#define MWV207REG_DEC400_WRITE_CACHE_BASE_FieldMask                   0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_CACHE_BASE_ReadMask                    0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_CACHE_BASE_WriteMask                   0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_CACHE_BASE_ResetValue                  0x00000000


#define MWV207REG_DEC400_WRITE_CACHE_BASE_ADDRESS                           31:0
#define MWV207REG_DEC400_WRITE_CACHE_BASE_ADDRESS_End                         31
#define MWV207REG_DEC400_WRITE_CACHE_BASE_ADDRESS_Start                        0
#define MWV207REG_DEC400_WRITE_CACHE_BASE_ADDRESS_Type                       U32



#define mwv207regDEC400WriteCacheBaseExRegAddrs                           0x6480
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_Address                     0x19200
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_MSB                              15
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_LSB                               5
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_BLK                               5
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_Count                            32
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_WriteMask                0xFFFFFFFF
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_ResetValue               0x00000000


#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_ADDRESS                        31:0
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_ADDRESS_End                      31
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_ADDRESS_Start                     0
#define MWV207REG_DEC400_WRITE_CACHE_BASE_EX_ADDRESS_Type                    U32




#define mwv207regDEC400DebugInfoOutRegAddrs                               0x64A0
#define MWV207REG_DEC400_DEBUG_INFO_OUT_Address                          0x19280
#define MWV207REG_DEC400_DEBUG_INFO_OUT_MSB                                   15
#define MWV207REG_DEC400_DEBUG_INFO_OUT_LSB                                    0
#define MWV207REG_DEC400_DEBUG_INFO_OUT_BLK                                    0
#define MWV207REG_DEC400_DEBUG_INFO_OUT_Count                                  1
#define MWV207REG_DEC400_DEBUG_INFO_OUT_FieldMask                     0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_INFO_OUT_ReadMask                      0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_INFO_OUT_WriteMask                     0x00000000
#define MWV207REG_DEC400_DEBUG_INFO_OUT_ResetValue                    0x000003FF


#define MWV207REG_DEC400_DEBUG_INFO_OUT_VALUE                               31:0
#define MWV207REG_DEC400_DEBUG_INFO_OUT_VALUE_End                             31
#define MWV207REG_DEC400_DEBUG_INFO_OUT_VALUE_Start                            0
#define MWV207REG_DEC400_DEBUG_INFO_OUT_VALUE_Type                           U32




#define mwv207regDEC400Debug0RegAddrs                                     0x64A1
#define MWV207REG_DEC400_DEBUG0_Address                                  0x19284
#define MWV207REG_DEC400_DEBUG0_MSB                                           15
#define MWV207REG_DEC400_DEBUG0_LSB                                            0
#define MWV207REG_DEC400_DEBUG0_BLK                                            0
#define MWV207REG_DEC400_DEBUG0_Count                                          1
#define MWV207REG_DEC400_DEBUG0_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG0_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG0_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG0_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG0_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG0_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG0_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG0_DEBUG_Type                                   U32




#define mwv207regDEC400Debug1RegAddrs                                     0x64A2
#define MWV207REG_DEC400_DEBUG1_Address                                  0x19288
#define MWV207REG_DEC400_DEBUG1_MSB                                           15
#define MWV207REG_DEC400_DEBUG1_LSB                                            0
#define MWV207REG_DEC400_DEBUG1_BLK                                            0
#define MWV207REG_DEC400_DEBUG1_Count                                          1
#define MWV207REG_DEC400_DEBUG1_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG1_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG1_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG1_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG1_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG1_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG1_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG1_DEBUG_Type                                   U32




#define mwv207regDEC400Debug2RegAddrs                                     0x64A3
#define MWV207REG_DEC400_DEBUG2_Address                                  0x1928C
#define MWV207REG_DEC400_DEBUG2_MSB                                           15
#define MWV207REG_DEC400_DEBUG2_LSB                                            0
#define MWV207REG_DEC400_DEBUG2_BLK                                            0
#define MWV207REG_DEC400_DEBUG2_Count                                          1
#define MWV207REG_DEC400_DEBUG2_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG2_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG2_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG2_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG2_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG2_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG2_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG2_DEBUG_Type                                   U32




#define mwv207regDEC400Debug3RegAddrs                                     0x64A4
#define MWV207REG_DEC400_DEBUG3_Address                                  0x19290
#define MWV207REG_DEC400_DEBUG3_MSB                                           15
#define MWV207REG_DEC400_DEBUG3_LSB                                            0
#define MWV207REG_DEC400_DEBUG3_BLK                                            0
#define MWV207REG_DEC400_DEBUG3_Count                                          1
#define MWV207REG_DEC400_DEBUG3_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG3_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG3_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG3_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG3_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG3_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG3_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG3_DEBUG_Type                                   U32




#define mwv207regDEC400Debug4RegAddrs                                     0x64A5
#define MWV207REG_DEC400_DEBUG4_Address                                  0x19294
#define MWV207REG_DEC400_DEBUG4_MSB                                           15
#define MWV207REG_DEC400_DEBUG4_LSB                                            0
#define MWV207REG_DEC400_DEBUG4_BLK                                            0
#define MWV207REG_DEC400_DEBUG4_Count                                          1
#define MWV207REG_DEC400_DEBUG4_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG4_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG4_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG4_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG4_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG4_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG4_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG4_DEBUG_Type                                   U32




#define mwv207regDEC400Debug5RegAddrs                                     0x64A6
#define MWV207REG_DEC400_DEBUG5_Address                                  0x19298
#define MWV207REG_DEC400_DEBUG5_MSB                                           15
#define MWV207REG_DEC400_DEBUG5_LSB                                            0
#define MWV207REG_DEC400_DEBUG5_BLK                                            0
#define MWV207REG_DEC400_DEBUG5_Count                                          1
#define MWV207REG_DEC400_DEBUG5_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG5_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG5_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG5_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG5_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG5_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG5_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG5_DEBUG_Type                                   U32



#define mwv207regDEC400StateCommitRegAddrs                                0x64A7
#define MWV207REG_DEC400_STATE_COMMIT_Address                            0x1929C
#define MWV207REG_DEC400_STATE_COMMIT_MSB                                     15
#define MWV207REG_DEC400_STATE_COMMIT_LSB                                      0
#define MWV207REG_DEC400_STATE_COMMIT_BLK                                      0
#define MWV207REG_DEC400_STATE_COMMIT_Count                                    1
#define MWV207REG_DEC400_STATE_COMMIT_FieldMask                       0xFFFFFFFF
#define MWV207REG_DEC400_STATE_COMMIT_ReadMask                        0xFFFFFFFF
#define MWV207REG_DEC400_STATE_COMMIT_WriteMask                       0x00000000
#define MWV207REG_DEC400_STATE_COMMIT_ResetValue                      0x00000000


#define MWV207REG_DEC400_STATE_COMMIT_COMMIT                                31:0
#define MWV207REG_DEC400_STATE_COMMIT_COMMIT_End                              31
#define MWV207REG_DEC400_STATE_COMMIT_COMMIT_Start                             0
#define MWV207REG_DEC400_STATE_COMMIT_COMMIT_Type                            U32




#define mwv207regDEC400Debug6RegAddrs                                     0x64A8
#define MWV207REG_DEC400_DEBUG6_Address                                  0x192A0
#define MWV207REG_DEC400_DEBUG6_MSB                                           15
#define MWV207REG_DEC400_DEBUG6_LSB                                            0
#define MWV207REG_DEC400_DEBUG6_BLK                                            0
#define MWV207REG_DEC400_DEBUG6_Count                                          1
#define MWV207REG_DEC400_DEBUG6_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG6_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG6_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG6_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG6_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG6_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG6_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG6_DEBUG_Type                                   U32




#define mwv207regDEC400Debug7RegAddrs                                     0x64A9
#define MWV207REG_DEC400_DEBUG7_Address                                  0x192A4
#define MWV207REG_DEC400_DEBUG7_MSB                                           15
#define MWV207REG_DEC400_DEBUG7_LSB                                            0
#define MWV207REG_DEC400_DEBUG7_BLK                                            0
#define MWV207REG_DEC400_DEBUG7_Count                                          1
#define MWV207REG_DEC400_DEBUG7_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG7_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG7_WriteMask                             0x00000000
#define MWV207REG_DEC400_DEBUG7_ResetValue                            0x00000000


#define MWV207REG_DEC400_DEBUG7_DEBUG                                       31:0
#define MWV207REG_DEC400_DEBUG7_DEBUG_End                                     31
#define MWV207REG_DEC400_DEBUG7_DEBUG_Start                                    0
#define MWV207REG_DEC400_DEBUG7_DEBUG_Type                                   U32



#define mwv207regDEC400CrDebugTile128Type0RegAddrs                        0x64AA
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_Address                  0x192A8
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_COMPRESSED_BYTES128         31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_COMPRESSED_BYTES128_End       31
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_COMPRESSED_BYTES128_Start      0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE0_COMPRESSED_BYTES128_Type     U32



#define mwv207regDEC400CrDebugTile128Type1RegAddrs                        0x64AB
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_Address                  0x192AC
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_COMPRESSED_BYTES32          31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_COMPRESSED_BYTES32_End        31
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_COMPRESSED_BYTES32_Start       0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE1_COMPRESSED_BYTES32_Type      U32



#define mwv207regDEC400CrDebugTile128Type2RegAddrs                        0x64AC
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_Address                  0x192B0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_COMPRESSED_BYTES64          31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_COMPRESSED_BYTES64_End        31
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_COMPRESSED_BYTES64_Start       0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE2_COMPRESSED_BYTES64_Type      U32



#define mwv207regDEC400CrDebugTile128Type3RegAddrs                        0x64AD
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_Address                  0x192B4
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_COMPRESSED_BYTES96          31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_COMPRESSED_BYTES96_End        31
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_COMPRESSED_BYTES96_Start       0
#define MWV207REG_DEC400_CR_DEBUG_TILE128_TYPE3_COMPRESSED_BYTES96_Type      U32



#define mwv207regDEC400CrDebugTile256Type0RegAddrs                        0x64AE
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_Address                  0x192B8
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_COMPRESSED_BYTES256         31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_COMPRESSED_BYTES256_End       31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_COMPRESSED_BYTES256_Start      0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE0_COMPRESSED_BYTES256_Type     U32



#define mwv207regDEC400CrDebugTile256Type1RegAddrs                        0x64AF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_Address                  0x192BC
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_COMPRESSED_BYTES32          31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_COMPRESSED_BYTES32_End        31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_COMPRESSED_BYTES32_Start       0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE1_COMPRESSED_BYTES32_Type      U32



#define mwv207regDEC400CrDebugTile256Type2RegAddrs                        0x64B0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_Address                  0x192C0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_COMPRESSED_BYTES64          31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_COMPRESSED_BYTES64_End        31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_COMPRESSED_BYTES64_Start       0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE2_COMPRESSED_BYTES64_Type      U32



#define mwv207regDEC400CrDebugTile256Type3RegAddrs                        0x64B1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_Address                  0x192C4
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_WriteMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_COMPRESSED_BYTES96          31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_COMPRESSED_BYTES96_End        31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_COMPRESSED_BYTES96_Start       0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE3_COMPRESSED_BYTES96_Type      U32



#define mwv207regDEC400CrDebugTile256Type4RegAddrs                        0x64B2
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_Address                  0x192C8
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_COMPRESSED_BYTES128         31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_COMPRESSED_BYTES128_End       31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_COMPRESSED_BYTES128_Start      0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE4_COMPRESSED_BYTES128_Type     U32



#define mwv207regDEC400CrDebugTile256Type5RegAddrs                        0x64B3
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_Address                  0x192CC
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_COMPRESSED_BYTES160         31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_COMPRESSED_BYTES160_End       31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_COMPRESSED_BYTES160_Start      0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE5_COMPRESSED_BYTES160_Type     U32



#define mwv207regDEC400CrDebugTile256Type6RegAddrs                        0x64B4
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_Address                  0x192D0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_COMPRESSED_BYTES192         31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_COMPRESSED_BYTES192_End       31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_COMPRESSED_BYTES192_Start      0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE6_COMPRESSED_BYTES192_Type     U32



#define mwv207regDEC400CrDebugTile256Type7RegAddrs                        0x64B5
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_Address                  0x192D4
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_MSB                           15
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_LSB                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_BLK                            0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_Count                          1
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_FieldMask             0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_ReadMask              0xFFFFFFFF
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_WriteMask             0x00000000
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_ResetValue            0x00000000


#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_COMPRESSED_BYTES224         31:0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_COMPRESSED_BYTES224_End       31
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_COMPRESSED_BYTES224_Start      0
#define MWV207REG_DEC400_CR_DEBUG_TILE256_TYPE7_COMPRESSED_BYTES224_Type     U32



#define mwv207regDEC400DebugReadGateDomainClkCounterRegAddrs              0x64B6
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_Address      0x192D8
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_MSB               15
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_LSB                0
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_BLK                0
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_Count              1
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_FieldMask 0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_ReadMask  0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_WriteMask 0x00000000
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_ResetValue 0x00000000


#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_VALUE           31:0
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_VALUE_End         31
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_VALUE_Start        0
#define MWV207REG_DEC400_DEBUG_READ_GATE_DOMAIN_CLK_COUNTER_VALUE_Type       U32



#define mwv207regDEC400DebugWriteGateDomainClkCounterRegAddrs             0x64B7
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_Address     0x192DC
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_MSB              15
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_LSB               0
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_BLK               0
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_Count             1
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_FieldMask 0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_ReadMask 0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_WriteMask 0x00000000
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_ResetValue 0x00000000


#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_VALUE          31:0
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_VALUE_End        31
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_VALUE_Start       0
#define MWV207REG_DEC400_DEBUG_WRITE_GATE_DOMAIN_CLK_COUNTER_VALUE_Type      U32



#define mwv207regDEC400DebugOtherGateDomainClkCounterRegAddrs             0x64B8
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_Address     0x192E0
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_MSB              15
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_LSB               0
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_BLK               0
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_Count             1
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_FieldMask 0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_ReadMask 0xFFFFFFFF
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_WriteMask 0x00000000
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_ResetValue 0x00000000


#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_VALUE          31:0
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_VALUE_End        31
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_VALUE_Start       0
#define MWV207REG_DEC400_DEBUG_OTHER_GATE_DOMAIN_CLK_COUNTER_VALUE_Type      U32



#define mwv207regDEC400FastClearValueRegAddrs                             0x64C0
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_Address                        0x19300
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_MSB                                 15
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_LSB                                  5
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_BLK                                  5
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_Count                               32
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_FieldMask                   0xFFFFFFFF
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_ReadMask                    0xFFFFFFFF
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_WriteMask                   0xFFFFFFFF
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_ResetValue                  0x00000000


#define MWV207REG_DEC400_FAST_CLEAR_VALUE_FAST_CLEAR_VALUE                  31:0
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_FAST_CLEAR_VALUE_End                31
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_FAST_CLEAR_VALUE_Start               0
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_FAST_CLEAR_VALUE_Type              U32



#define mwv207regDEC400FastClearValueExRegAddrs                           0x64E0
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_Address                     0x19380
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_MSB                              15
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_LSB                               5
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_BLK                               5
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_Count                            32
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_FieldMask                0xFFFFFFFF
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_ReadMask                 0xFFFFFFFF
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_WriteMask                0xFFFFFFFF
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_ResetValue               0x00000000


#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_FAST_CLEAR_VALUE_EX            31:0
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_FAST_CLEAR_VALUE_EX_End          31
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_FAST_CLEAR_VALUE_EX_Start         0
#define MWV207REG_DEC400_FAST_CLEAR_VALUE_EX_FAST_CLEAR_VALUE_EX_Type        U32




#define mwv207regDEC400ImageSizeRegAddrs                                  0x6500
#define MWV207REG_DEC400_IMAGE_SIZE_Address                              0x19400
#define MWV207REG_DEC400_IMAGE_SIZE_MSB                                       15
#define MWV207REG_DEC400_IMAGE_SIZE_LSB                                        5
#define MWV207REG_DEC400_IMAGE_SIZE_BLK                                        5
#define MWV207REG_DEC400_IMAGE_SIZE_Count                                     32
#define MWV207REG_DEC400_IMAGE_SIZE_FieldMask                         0xFFFFFFFF
#define MWV207REG_DEC400_IMAGE_SIZE_ReadMask                          0xFFFFFFFF
#define MWV207REG_DEC400_IMAGE_SIZE_WriteMask                         0xFFFFFFFF
#define MWV207REG_DEC400_IMAGE_SIZE_ResetValue                        0x00000000


#define MWV207REG_DEC400_IMAGE_SIZE_STRIDE                                  15:0
#define MWV207REG_DEC400_IMAGE_SIZE_STRIDE_End                                15
#define MWV207REG_DEC400_IMAGE_SIZE_STRIDE_Start                               0
#define MWV207REG_DEC400_IMAGE_SIZE_STRIDE_Type                              U16


#define MWV207REG_DEC400_IMAGE_SIZE_WIDTH                                  31:16
#define MWV207REG_DEC400_IMAGE_SIZE_WIDTH_End                                 31
#define MWV207REG_DEC400_IMAGE_SIZE_WIDTH_Start                               16
#define MWV207REG_DEC400_IMAGE_SIZE_WIDTH_Type                               U16


#endif


