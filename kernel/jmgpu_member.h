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




#ifndef __AQMemoryReg_h__
#define __AQMemoryReg_h__





#define AQMemoryFePageTableRegAddrs                                       0x0100
#define AQ_MEMORY_FE_PAGE_TABLE_Address                                  0x00400
#define AQ_MEMORY_FE_PAGE_TABLE_MSB                                           15
#define AQ_MEMORY_FE_PAGE_TABLE_LSB                                            0
#define AQ_MEMORY_FE_PAGE_TABLE_BLK                                            0
#define AQ_MEMORY_FE_PAGE_TABLE_Count                                          1
#define AQ_MEMORY_FE_PAGE_TABLE_FieldMask                             0xFFFFF000
#define AQ_MEMORY_FE_PAGE_TABLE_ReadMask                              0xFFFFF000
#define AQ_MEMORY_FE_PAGE_TABLE_WriteMask                             0xFFFFF000
#define AQ_MEMORY_FE_PAGE_TABLE_ResetValue                            0x00000000


#define AQ_MEMORY_FE_PAGE_TABLE_BASE_ADDRESS                               31:12
#define AQ_MEMORY_FE_PAGE_TABLE_BASE_ADDRESS_End                              31
#define AQ_MEMORY_FE_PAGE_TABLE_BASE_ADDRESS_Start                            12
#define AQ_MEMORY_FE_PAGE_TABLE_BASE_ADDRESS_Type                            U20




#define AQMemoryTxPageTableRegAddrs                                       0x0101
#define AQ_MEMORY_TX_PAGE_TABLE_Address                                  0x00404
#define AQ_MEMORY_TX_PAGE_TABLE_MSB                                           15
#define AQ_MEMORY_TX_PAGE_TABLE_LSB                                            0
#define AQ_MEMORY_TX_PAGE_TABLE_BLK                                            0
#define AQ_MEMORY_TX_PAGE_TABLE_Count                                          1
#define AQ_MEMORY_TX_PAGE_TABLE_FieldMask                             0xFFFFF000
#define AQ_MEMORY_TX_PAGE_TABLE_ReadMask                              0xFFFFF000
#define AQ_MEMORY_TX_PAGE_TABLE_WriteMask                             0xFFFFF000
#define AQ_MEMORY_TX_PAGE_TABLE_ResetValue                            0x00000000


#define AQ_MEMORY_TX_PAGE_TABLE_BASE_ADDRESS                               31:12
#define AQ_MEMORY_TX_PAGE_TABLE_BASE_ADDRESS_End                              31
#define AQ_MEMORY_TX_PAGE_TABLE_BASE_ADDRESS_Start                            12
#define AQ_MEMORY_TX_PAGE_TABLE_BASE_ADDRESS_Type                            U20

#define AQMemoryPePageTableRegAddrs                                       0x0102
#define AQ_MEMORY_PE_PAGE_TABLE_Address                                  0x00408
#define AQ_MEMORY_PE_PAGE_TABLE_MSB                                           15
#define AQ_MEMORY_PE_PAGE_TABLE_LSB                                            0
#define AQ_MEMORY_PE_PAGE_TABLE_BLK                                            0
#define AQ_MEMORY_PE_PAGE_TABLE_Count                                          1
#define AQ_MEMORY_PE_PAGE_TABLE_FieldMask                             0xFFFFF000
#define AQ_MEMORY_PE_PAGE_TABLE_ReadMask                              0xFFFFF000
#define AQ_MEMORY_PE_PAGE_TABLE_WriteMask                             0xFFFFF000
#define AQ_MEMORY_PE_PAGE_TABLE_ResetValue                            0x00000000


#define AQ_MEMORY_PE_PAGE_TABLE_BASE_ADDRESS                               31:12
#define AQ_MEMORY_PE_PAGE_TABLE_BASE_ADDRESS_End                              31
#define AQ_MEMORY_PE_PAGE_TABLE_BASE_ADDRESS_Start                            12
#define AQ_MEMORY_PE_PAGE_TABLE_BASE_ADDRESS_Type                            U20

#define AQMemoryPezPageTableRegAddrs                                      0x0103
#define AQ_MEMORY_PEZ_PAGE_TABLE_Address                                 0x0040C
#define AQ_MEMORY_PEZ_PAGE_TABLE_MSB                                          15
#define AQ_MEMORY_PEZ_PAGE_TABLE_LSB                                           0
#define AQ_MEMORY_PEZ_PAGE_TABLE_BLK                                           0
#define AQ_MEMORY_PEZ_PAGE_TABLE_Count                                         1
#define AQ_MEMORY_PEZ_PAGE_TABLE_FieldMask                            0xFFFFF000
#define AQ_MEMORY_PEZ_PAGE_TABLE_ReadMask                             0xFFFFF000
#define AQ_MEMORY_PEZ_PAGE_TABLE_WriteMask                            0xFFFFF000
#define AQ_MEMORY_PEZ_PAGE_TABLE_ResetValue                           0x00000000


#define AQ_MEMORY_PEZ_PAGE_TABLE_BASE_ADDRESS                              31:12
#define AQ_MEMORY_PEZ_PAGE_TABLE_BASE_ADDRESS_End                             31
#define AQ_MEMORY_PEZ_PAGE_TABLE_BASE_ADDRESS_Start                           12
#define AQ_MEMORY_PEZ_PAGE_TABLE_BASE_ADDRESS_Type                           U20

#define AQMemoryRaPageTableRegAddrs                                       0x0104
#define AQ_MEMORY_RA_PAGE_TABLE_Address                                  0x00410
#define AQ_MEMORY_RA_PAGE_TABLE_MSB                                           15
#define AQ_MEMORY_RA_PAGE_TABLE_LSB                                            0
#define AQ_MEMORY_RA_PAGE_TABLE_BLK                                            0
#define AQ_MEMORY_RA_PAGE_TABLE_Count                                          1
#define AQ_MEMORY_RA_PAGE_TABLE_FieldMask                             0xFFFFF000
#define AQ_MEMORY_RA_PAGE_TABLE_ReadMask                              0xFFFFF000
#define AQ_MEMORY_RA_PAGE_TABLE_WriteMask                             0xFFFFF000
#define AQ_MEMORY_RA_PAGE_TABLE_ResetValue                            0x00000000


#define AQ_MEMORY_RA_PAGE_TABLE_BASE_ADDRESS                               31:12
#define AQ_MEMORY_RA_PAGE_TABLE_BASE_ADDRESS_End                              31
#define AQ_MEMORY_RA_PAGE_TABLE_BASE_ADDRESS_Start                            12
#define AQ_MEMORY_RA_PAGE_TABLE_BASE_ADDRESS_Type                            U20




#define AQMemoryDebugRegAddrs                                             0x0105
#define AQ_MEMORY_DEBUG_Address                                          0x00414
#define AQ_MEMORY_DEBUG_MSB                                                   15
#define AQ_MEMORY_DEBUG_LSB                                                    0
#define AQ_MEMORY_DEBUG_BLK                                                    0
#define AQ_MEMORY_DEBUG_Count                                                  1
#define AQ_MEMORY_DEBUG_FieldMask                                     0xFFFFF8FF
#define AQ_MEMORY_DEBUG_ReadMask                                      0xFFFFF8FF
#define AQ_MEMORY_DEBUG_WriteMask                                     0xFFFFF8FF
#define AQ_MEMORY_DEBUG_ResetValue                                    0x3C000000


#define AQ_MEMORY_DEBUG_MAX_OUTSTANDING_READS                                7:0
#define AQ_MEMORY_DEBUG_MAX_OUTSTANDING_READS_End                              7
#define AQ_MEMORY_DEBUG_MAX_OUTSTANDING_READS_Start                            0
#define AQ_MEMORY_DEBUG_MAX_OUTSTANDING_READS_Type                           U08

#define AQ_MEMORY_DEBUG_DISABLE_HZ_FLUSH                                   11:11
#define AQ_MEMORY_DEBUG_DISABLE_HZ_FLUSH_End                                  11
#define AQ_MEMORY_DEBUG_DISABLE_HZ_FLUSH_Start                                11
#define AQ_MEMORY_DEBUG_DISABLE_HZ_FLUSH_Type                                U01

#define AQ_MEMORY_DEBUG_DISABLE_HZ_L2                                      12:12
#define AQ_MEMORY_DEBUG_DISABLE_HZ_L2_End                                     12
#define AQ_MEMORY_DEBUG_DISABLE_HZ_L2_Start                                   12
#define AQ_MEMORY_DEBUG_DISABLE_HZ_L2_Type                                   U01

#define AQ_MEMORY_DEBUG_DISABLE_BUBBLE_OPTIMIZATION_IN_DECODER             13:13
#define AQ_MEMORY_DEBUG_DISABLE_BUBBLE_OPTIMIZATION_IN_DECODER_End            13
#define AQ_MEMORY_DEBUG_DISABLE_BUBBLE_OPTIMIZATION_IN_DECODER_Start          13
#define AQ_MEMORY_DEBUG_DISABLE_BUBBLE_OPTIMIZATION_IN_DECODER_Type          U01

#define AQ_MEMORY_DEBUG_DISABLE_MINI_MMU_CACHE                             14:14
#define AQ_MEMORY_DEBUG_DISABLE_MINI_MMU_CACHE_End                            14
#define AQ_MEMORY_DEBUG_DISABLE_MINI_MMU_CACHE_Start                          14
#define AQ_MEMORY_DEBUG_DISABLE_MINI_MMU_CACHE_Type                          U01

#define AQ_MEMORY_DEBUG_DISABLE_MULTI_VERTEX                               15:15
#define AQ_MEMORY_DEBUG_DISABLE_MULTI_VERTEX_End                              15
#define AQ_MEMORY_DEBUG_DISABLE_MULTI_VERTEX_Start                            15
#define AQ_MEMORY_DEBUG_DISABLE_MULTI_VERTEX_Type                            U01

#define AQ_MEMORY_DEBUG_DISABLE_AUTO_RESTART                               16:16
#define AQ_MEMORY_DEBUG_DISABLE_AUTO_RESTART_End                              16
#define AQ_MEMORY_DEBUG_DISABLE_AUTO_RESTART_Start                            16
#define AQ_MEMORY_DEBUG_DISABLE_AUTO_RESTART_Type                            U01

#define AQ_MEMORY_DEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE                 17:17
#define AQ_MEMORY_DEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE_End                17
#define AQ_MEMORY_DEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE_Start              17
#define AQ_MEMORY_DEBUG_INTERLEAVE_BUFFER_LOW_LATENCY_MODE_Type              U01

#define AQ_MEMORY_DEBUG_BYPASS_COMPRESSION_INTERLEAVE_BUFFER               18:18
#define AQ_MEMORY_DEBUG_BYPASS_COMPRESSION_INTERLEAVE_BUFFER_End              18
#define AQ_MEMORY_DEBUG_BYPASS_COMPRESSION_INTERLEAVE_BUFFER_Start            18
#define AQ_MEMORY_DEBUG_BYPASS_COMPRESSION_INTERLEAVE_BUFFER_Type            U01

#define AQ_MEMORY_DEBUG_LIMIT_CONTROL                                      19:19
#define AQ_MEMORY_DEBUG_LIMIT_CONTROL_End                                     19
#define AQ_MEMORY_DEBUG_LIMIT_CONTROL_Start                                   19
#define AQ_MEMORY_DEBUG_LIMIT_CONTROL_Type                                   U01
#define   AQ_MEMORY_DEBUG_LIMIT_CONTROL_REQUESTS                             0x0
#define   AQ_MEMORY_DEBUG_LIMIT_CONTROL_DATA                                 0x1


#define AQ_MEMORY_DEBUG_DISABLE_FAST_CLEAR                                 20:20
#define AQ_MEMORY_DEBUG_DISABLE_FAST_CLEAR_End                                20
#define AQ_MEMORY_DEBUG_DISABLE_FAST_CLEAR_Start                              20
#define AQ_MEMORY_DEBUG_DISABLE_FAST_CLEAR_Type                              U01


#define AQ_MEMORY_DEBUG_DISABLE_ZCOMPRESSION                               21:21
#define AQ_MEMORY_DEBUG_DISABLE_ZCOMPRESSION_End                              21
#define AQ_MEMORY_DEBUG_DISABLE_ZCOMPRESSION_Start                            21
#define AQ_MEMORY_DEBUG_DISABLE_ZCOMPRESSION_Type                            U01

#define AQ_MEMORY_DEBUG_DISABLE_STALL_READS                                22:22
#define AQ_MEMORY_DEBUG_DISABLE_STALL_READS_End                               22
#define AQ_MEMORY_DEBUG_DISABLE_STALL_READS_Start                             22
#define AQ_MEMORY_DEBUG_DISABLE_STALL_READS_Type                             U01

#define AQ_MEMORY_DEBUG_DISABLE_WRITE_DATA_SPEEDUP                         23:23
#define AQ_MEMORY_DEBUG_DISABLE_WRITE_DATA_SPEEDUP_End                        23
#define AQ_MEMORY_DEBUG_DISABLE_WRITE_DATA_SPEEDUP_Start                      23
#define AQ_MEMORY_DEBUG_DISABLE_WRITE_DATA_SPEEDUP_Type                      U01


#define AQ_MEMORY_DEBUG_ZCOMP_LIMIT                                        29:24
#define AQ_MEMORY_DEBUG_ZCOMP_LIMIT_End                                       29
#define AQ_MEMORY_DEBUG_ZCOMP_LIMIT_Start                                     24
#define AQ_MEMORY_DEBUG_ZCOMP_LIMIT_Type                                     U06

#define AQ_MEMORY_DEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS                  30:30
#define AQ_MEMORY_DEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS_End                 30
#define AQ_MEMORY_DEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS_Start               30
#define AQ_MEMORY_DEBUG_DONT_STALL_WRITES_TO_SAME_ADDRESS_Type               U01

#define AQ_MEMORY_DEBUG_DISABLE_LATENCY_OPTIMIZATION_IN_FC                 31:31
#define AQ_MEMORY_DEBUG_DISABLE_LATENCY_OPTIMIZATION_IN_FC_End                31
#define AQ_MEMORY_DEBUG_DISABLE_LATENCY_OPTIMIZATION_IN_FC_Start              31
#define AQ_MEMORY_DEBUG_DISABLE_LATENCY_OPTIMIZATION_IN_FC_Type              U01

#define AQMemoryRaRegAddrs                                                0x0106
#define AQ_MEMORY_RA_Address                                             0x00418
#define AQ_MEMORY_RA_MSB                                                      15
#define AQ_MEMORY_RA_LSB                                                       0
#define AQ_MEMORY_RA_BLK                                                       0
#define AQ_MEMORY_RA_Count                                                     1
#define AQ_MEMORY_RA_FieldMask                                        0xFFFFFFFF
#define AQ_MEMORY_RA_ReadMask                                         0xFFFFFFFF
#define AQ_MEMORY_RA_WriteMask                                        0xFFFFFFFF
#define AQ_MEMORY_RA_ResetValue                                       0x00000000

#define AQ_MEMORY_RA_BASE_ADDRESS                                           31:0
#define AQ_MEMORY_RA_BASE_ADDRESS_End                                         31
#define AQ_MEMORY_RA_BASE_ADDRESS_Start                                        0
#define AQ_MEMORY_RA_BASE_ADDRESS_Type                                       U32

#define AQMemoryFeRegAddrs                                                0x0107
#define AQ_MEMORY_FE_Address                                             0x0041C
#define AQ_MEMORY_FE_MSB                                                      15
#define AQ_MEMORY_FE_LSB                                                       0
#define AQ_MEMORY_FE_BLK                                                       0
#define AQ_MEMORY_FE_Count                                                     1
#define AQ_MEMORY_FE_FieldMask                                        0xFFFFFFFF
#define AQ_MEMORY_FE_ReadMask                                         0xFFFFFFFF
#define AQ_MEMORY_FE_WriteMask                                        0xFFFFFFFF
#define AQ_MEMORY_FE_ResetValue                                       0x00000000

#define AQ_MEMORY_FE_BASE_ADDRESS                                           31:0
#define AQ_MEMORY_FE_BASE_ADDRESS_End                                         31
#define AQ_MEMORY_FE_BASE_ADDRESS_Start                                        0
#define AQ_MEMORY_FE_BASE_ADDRESS_Type                                       U32

#define AQMemoryTxRegAddrs                                                0x0108
#define AQ_MEMORY_TX_Address                                             0x00420
#define AQ_MEMORY_TX_MSB                                                      15
#define AQ_MEMORY_TX_LSB                                                       0
#define AQ_MEMORY_TX_BLK                                                       0
#define AQ_MEMORY_TX_Count                                                     1
#define AQ_MEMORY_TX_FieldMask                                        0xFFFFFFFF
#define AQ_MEMORY_TX_ReadMask                                         0xFFFFFFFF
#define AQ_MEMORY_TX_WriteMask                                        0xFFFFFFFF
#define AQ_MEMORY_TX_ResetValue                                       0x00000000

#define AQ_MEMORY_TX_BASE_ADDRESS                                           31:0
#define AQ_MEMORY_TX_BASE_ADDRESS_End                                         31
#define AQ_MEMORY_TX_BASE_ADDRESS_Start                                        0
#define AQ_MEMORY_TX_BASE_ADDRESS_Type                                       U32

#define AQMemoryPezRegAddrs                                               0x0109
#define AQ_MEMORY_PEZ_Address                                            0x00424
#define AQ_MEMORY_PEZ_MSB                                                     15
#define AQ_MEMORY_PEZ_LSB                                                      0
#define AQ_MEMORY_PEZ_BLK                                                      0
#define AQ_MEMORY_PEZ_Count                                                    1
#define AQ_MEMORY_PEZ_FieldMask                                       0xFFFFFFFF
#define AQ_MEMORY_PEZ_ReadMask                                        0xFFFFFFFF
#define AQ_MEMORY_PEZ_WriteMask                                       0xFFFFFFFF
#define AQ_MEMORY_PEZ_ResetValue                                      0x00000000

#define AQ_MEMORY_PEZ_BASE_ADDRESS                                          31:0
#define AQ_MEMORY_PEZ_BASE_ADDRESS_End                                        31
#define AQ_MEMORY_PEZ_BASE_ADDRESS_Start                                       0
#define AQ_MEMORY_PEZ_BASE_ADDRESS_Type                                      U32

#define AQMemoryPecRegAddrs                                               0x010A
#define AQ_MEMORY_PEC_Address                                            0x00428
#define AQ_MEMORY_PEC_MSB                                                     15
#define AQ_MEMORY_PEC_LSB                                                      0
#define AQ_MEMORY_PEC_BLK                                                      0
#define AQ_MEMORY_PEC_Count                                                    1
#define AQ_MEMORY_PEC_FieldMask                                       0xFFFFFFFF
#define AQ_MEMORY_PEC_ReadMask                                        0xFFFFFFFF
#define AQ_MEMORY_PEC_WriteMask                                       0xFFFFFFFF
#define AQ_MEMORY_PEC_ResetValue                                      0x00000000

#define AQ_MEMORY_PEC_BASE_ADDRESS                                          31:0
#define AQ_MEMORY_PEC_BASE_ADDRESS_End                                        31
#define AQ_MEMORY_PEC_BASE_ADDRESS_Start                                       0
#define AQ_MEMORY_PEC_BASE_ADDRESS_Type                                      U32



#define AQRegisterTimingControlRegAddrs                                   0x010B
#define AQ_REGISTER_TIMING_CONTROL_Address                               0x0042C
#define AQ_REGISTER_TIMING_CONTROL_MSB                                        15
#define AQ_REGISTER_TIMING_CONTROL_LSB                                         0
#define AQ_REGISTER_TIMING_CONTROL_BLK                                         0
#define AQ_REGISTER_TIMING_CONTROL_Count                                       1
#define AQ_REGISTER_TIMING_CONTROL_FieldMask                          0xFFFFFFFF
#define AQ_REGISTER_TIMING_CONTROL_ReadMask                           0xFFFFFFFF
#define AQ_REGISTER_TIMING_CONTROL_WriteMask                          0xFFFFFFFF
#define AQ_REGISTER_TIMING_CONTROL_ResetValue                         0x00030000


#define AQ_REGISTER_TIMING_CONTROL_FOR_RF1P                                  7:0
#define AQ_REGISTER_TIMING_CONTROL_FOR_RF1P_End                                7
#define AQ_REGISTER_TIMING_CONTROL_FOR_RF1P_Start                              0
#define AQ_REGISTER_TIMING_CONTROL_FOR_RF1P_Type                             U08


#define AQ_REGISTER_TIMING_CONTROL_FOR_RF2P                                 15:8
#define AQ_REGISTER_TIMING_CONTROL_FOR_RF2P_End                               15
#define AQ_REGISTER_TIMING_CONTROL_FOR_RF2P_Start                              8
#define AQ_REGISTER_TIMING_CONTROL_FOR_RF2P_Type                             U08


#define AQ_REGISTER_TIMING_CONTROL_FAST_RTC                                17:16
#define AQ_REGISTER_TIMING_CONTROL_FAST_RTC_End                               17
#define AQ_REGISTER_TIMING_CONTROL_FAST_RTC_Start                             16
#define AQ_REGISTER_TIMING_CONTROL_FAST_RTC_Type                             U02


#define AQ_REGISTER_TIMING_CONTROL_FAST_WTC                                19:18
#define AQ_REGISTER_TIMING_CONTROL_FAST_WTC_End                               19
#define AQ_REGISTER_TIMING_CONTROL_FAST_WTC_Start                             18
#define AQ_REGISTER_TIMING_CONTROL_FAST_WTC_Type                             U02


#define AQ_REGISTER_TIMING_CONTROL_POWER_DOWN                              20:20
#define AQ_REGISTER_TIMING_CONTROL_POWER_DOWN_End                             20
#define AQ_REGISTER_TIMING_CONTROL_POWER_DOWN_Start                           20
#define AQ_REGISTER_TIMING_CONTROL_POWER_DOWN_Type                           U01


#define AQ_REGISTER_TIMING_CONTROL_DEEP_SLEEP                              21:21
#define AQ_REGISTER_TIMING_CONTROL_DEEP_SLEEP_End                             21
#define AQ_REGISTER_TIMING_CONTROL_DEEP_SLEEP_Start                           21
#define AQ_REGISTER_TIMING_CONTROL_DEEP_SLEEP_Type                           U01


#define AQ_REGISTER_TIMING_CONTROL_LIGHT_SLEEP                             22:22
#define AQ_REGISTER_TIMING_CONTROL_LIGHT_SLEEP_End                            22
#define AQ_REGISTER_TIMING_CONTROL_LIGHT_SLEEP_Start                          22
#define AQ_REGISTER_TIMING_CONTROL_LIGHT_SLEEP_Type                          U01

#define AQ_REGISTER_TIMING_CONTROL_RESERVED                                31:23
#define AQ_REGISTER_TIMING_CONTROL_RESERVED_End                               31
#define AQ_REGISTER_TIMING_CONTROL_RESERVED_Start                             23
#define AQ_REGISTER_TIMING_CONTROL_RESERVED_Type                             U09




#define jmMemoryReservedRegAddrs                                          0x010C
#define JM_MEMORY_RESERVED_Address                                       0x00430
#define JM_MEMORY_RESERVED_MSB                                                15
#define JM_MEMORY_RESERVED_LSB                                                 0
#define JM_MEMORY_RESERVED_BLK                                                 0
#define JM_MEMORY_RESERVED_Count                                               1
#define JM_MEMORY_RESERVED_FieldMask                                  0xFFFFFFFF
#define JM_MEMORY_RESERVED_ReadMask                                   0xFFFFFFFF
#define JM_MEMORY_RESERVED_WriteMask                                  0x00000000
#define JM_MEMORY_RESERVED_ResetValue                                 0x00000000


#define JM_MEMORY_RESERVED_RESERVED                                         31:0
#define JM_MEMORY_RESERVED_RESERVED_End                                       31
#define JM_MEMORY_RESERVED_RESERVED_Start                                      0
#define JM_MEMORY_RESERVED_RESERVED_Type                                     U32



#define jmDisplayPriorityRegAddrs                                         0x010D
#define JM_DISPLAY_PRIORITY_Address                                      0x00434
#define JM_DISPLAY_PRIORITY_MSB                                               15
#define JM_DISPLAY_PRIORITY_LSB                                                0
#define JM_DISPLAY_PRIORITY_BLK                                                0
#define JM_DISPLAY_PRIORITY_Count                                              1
#define JM_DISPLAY_PRIORITY_FieldMask                                 0x0000FFFF
#define JM_DISPLAY_PRIORITY_ReadMask                                  0x0000FFFF
#define JM_DISPLAY_PRIORITY_WriteMask                                 0x0000FFFF
#define JM_DISPLAY_PRIORITY_ResetValue                                0x00000102

#define JM_DISPLAY_PRIORITY_PERIOD                                           7:0
#define JM_DISPLAY_PRIORITY_PERIOD_End                                         7
#define JM_DISPLAY_PRIORITY_PERIOD_Start                                       0
#define JM_DISPLAY_PRIORITY_PERIOD_Type                                      U08

#define JM_DISPLAY_PRIORITY_HIGH                                            15:8
#define JM_DISPLAY_PRIORITY_HIGH_End                                          15
#define JM_DISPLAY_PRIORITY_HIGH_Start                                         8
#define JM_DISPLAY_PRIORITY_HIGH_Type                                        U08




#define jmDbgCycleCounterRegAddrs                                         0x010E
#define JM_DBG_CYCLE_COUNTER_Address                                     0x00438
#define JM_DBG_CYCLE_COUNTER_MSB                                              15
#define JM_DBG_CYCLE_COUNTER_LSB                                               0
#define JM_DBG_CYCLE_COUNTER_BLK                                               0
#define JM_DBG_CYCLE_COUNTER_Count                                             1
#define JM_DBG_CYCLE_COUNTER_FieldMask                                0xFFFFFFFF
#define JM_DBG_CYCLE_COUNTER_ReadMask                                 0xFFFFFFFF
#define JM_DBG_CYCLE_COUNTER_WriteMask                                0xFFFFFFFF
#define JM_DBG_CYCLE_COUNTER_ResetValue                               0x00000000


#define JM_DBG_CYCLE_COUNTER_COUNT                                          31:0
#define JM_DBG_CYCLE_COUNTER_COUNT_End                                        31
#define JM_DBG_CYCLE_COUNTER_COUNT_Start                                       0
#define JM_DBG_CYCLE_COUNTER_COUNT_Type                                      U32




#define jmOutstandingReads0RegAddrs                                       0x010F
#define JM_OUTSTANDING_READS0_Address                                    0x0043C
#define JM_OUTSTANDING_READS0_MSB                                             15
#define JM_OUTSTANDING_READS0_LSB                                              0
#define JM_OUTSTANDING_READS0_BLK                                              0
#define JM_OUTSTANDING_READS0_Count                                            1
#define JM_OUTSTANDING_READS0_FieldMask                               0xFFFFFFFF
#define JM_OUTSTANDING_READS0_ReadMask                                0xFFFFFFFF
#define JM_OUTSTANDING_READS0_WriteMask                               0x00000000
#define JM_OUTSTANDING_READS0_ResetValue                              0x00000000


#define JM_OUTSTANDING_READS0_PEC                                            7:0
#define JM_OUTSTANDING_READS0_PEC_End                                          7
#define JM_OUTSTANDING_READS0_PEC_Start                                        0
#define JM_OUTSTANDING_READS0_PEC_Type                                       U08


#define JM_OUTSTANDING_READS0_PEZ                                           15:8
#define JM_OUTSTANDING_READS0_PEZ_End                                         15
#define JM_OUTSTANDING_READS0_PEZ_Start                                        8
#define JM_OUTSTANDING_READS0_PEZ_Type                                       U08


#define JM_OUTSTANDING_READS0_FE                                           23:16
#define JM_OUTSTANDING_READS0_FE_End                                          23
#define JM_OUTSTANDING_READS0_FE_Start                                        16
#define JM_OUTSTANDING_READS0_FE_Type                                        U08


#define JM_OUTSTANDING_READS0_MMU                                          31:24
#define JM_OUTSTANDING_READS0_MMU_End                                         31
#define JM_OUTSTANDING_READS0_MMU_Start                                       24
#define JM_OUTSTANDING_READS0_MMU_Type                                       U08




#define jmOutstandingReads1RegAddrs                                       0x0110
#define JM_OUTSTANDING_READS1_Address                                    0x00440
#define JM_OUTSTANDING_READS1_MSB                                             15
#define JM_OUTSTANDING_READS1_LSB                                              0
#define JM_OUTSTANDING_READS1_BLK                                              0
#define JM_OUTSTANDING_READS1_Count                                            1
#define JM_OUTSTANDING_READS1_FieldMask                               0xFFFFFFFF
#define JM_OUTSTANDING_READS1_ReadMask                                0xFFFFFFFF
#define JM_OUTSTANDING_READS1_WriteMask                               0x00000000
#define JM_OUTSTANDING_READS1_ResetValue                              0x00000000


#define JM_OUTSTANDING_READS1_RA                                             7:0
#define JM_OUTSTANDING_READS1_RA_End                                           7
#define JM_OUTSTANDING_READS1_RA_Start                                         0
#define JM_OUTSTANDING_READS1_RA_Type                                        U08


#define JM_OUTSTANDING_READS1_TX                                            15:8
#define JM_OUTSTANDING_READS1_TX_End                                          15
#define JM_OUTSTANDING_READS1_TX_Start                                         8
#define JM_OUTSTANDING_READS1_TX_Type                                        U08


#define JM_OUTSTANDING_READS1_FC                                           23:16
#define JM_OUTSTANDING_READS1_FC_End                                          23
#define JM_OUTSTANDING_READS1_FC_Start                                        16
#define JM_OUTSTANDING_READS1_FC_Type                                        U08

#define JM_OUTSTANDING_READS1_TOTAL                                        31:24
#define JM_OUTSTANDING_READS1_TOTAL_End                                       31
#define JM_OUTSTANDING_READS1_TOTAL_Start                                     24
#define JM_OUTSTANDING_READS1_TOTAL_Type                                     U08




#define jmOutstandingWritesRegAddrs                                       0x0111
#define JM_OUTSTANDING_WRITES_Address                                    0x00444
#define JM_OUTSTANDING_WRITES_MSB                                             15
#define JM_OUTSTANDING_WRITES_LSB                                              0
#define JM_OUTSTANDING_WRITES_BLK                                              0
#define JM_OUTSTANDING_WRITES_Count                                            1
#define JM_OUTSTANDING_WRITES_FieldMask                               0xFFFFFFFF
#define JM_OUTSTANDING_WRITES_ReadMask                                0xFFFFFFFF
#define JM_OUTSTANDING_WRITES_WriteMask                               0x00000000
#define JM_OUTSTANDING_WRITES_ResetValue                              0x00000000


#define JM_OUTSTANDING_WRITES_PEC                                            7:0
#define JM_OUTSTANDING_WRITES_PEC_End                                          7
#define JM_OUTSTANDING_WRITES_PEC_Start                                        0
#define JM_OUTSTANDING_WRITES_PEC_Type                                       U08


#define JM_OUTSTANDING_WRITES_PEZ                                           15:8
#define JM_OUTSTANDING_WRITES_PEZ_End                                         15
#define JM_OUTSTANDING_WRITES_PEZ_Start                                        8
#define JM_OUTSTANDING_WRITES_PEZ_Type                                       U08


#define JM_OUTSTANDING_WRITES_FC                                           23:16
#define JM_OUTSTANDING_WRITES_FC_End                                          23
#define JM_OUTSTANDING_WRITES_FC_Start                                        16
#define JM_OUTSTANDING_WRITES_FC_Type                                        U08

#define JM_OUTSTANDING_WRITES_TOTAL                                        31:24
#define JM_OUTSTANDING_WRITES_TOTAL_End                                       31
#define JM_OUTSTANDING_WRITES_TOTAL_Start                                     24
#define JM_OUTSTANDING_WRITES_TOTAL_Type                                     U08




#define jmDebugSignalsRaRegAddrs                                          0x0112
#define JM_DEBUG_SIGNALS_RA_Address                                      0x00448
#define JM_DEBUG_SIGNALS_RA_MSB                                               15
#define JM_DEBUG_SIGNALS_RA_LSB                                                0
#define JM_DEBUG_SIGNALS_RA_BLK                                                0
#define JM_DEBUG_SIGNALS_RA_Count                                              1
#define JM_DEBUG_SIGNALS_RA_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_RA_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_RA_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_RA_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_RA_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_RA_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_RA_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_RA_SIGNAL_Type                                      U32




#define jmDebugSignalsTxRegAddrs                                          0x0113
#define JM_DEBUG_SIGNALS_TX_Address                                      0x0044C
#define JM_DEBUG_SIGNALS_TX_MSB                                               15
#define JM_DEBUG_SIGNALS_TX_LSB                                                0
#define JM_DEBUG_SIGNALS_TX_BLK                                                0
#define JM_DEBUG_SIGNALS_TX_Count                                              1
#define JM_DEBUG_SIGNALS_TX_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_TX_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_TX_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_TX_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_TX_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_TX_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_TX_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_TX_SIGNAL_Type                                      U32




#define jmDebugSignalsFeRegAddrs                                          0x0114
#define JM_DEBUG_SIGNALS_FE_Address                                      0x00450
#define JM_DEBUG_SIGNALS_FE_MSB                                               15
#define JM_DEBUG_SIGNALS_FE_LSB                                                0
#define JM_DEBUG_SIGNALS_FE_BLK                                                0
#define JM_DEBUG_SIGNALS_FE_Count                                              1
#define JM_DEBUG_SIGNALS_FE_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_FE_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_FE_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_FE_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_FE_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_FE_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_FE_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_FE_SIGNAL_Type                                      U32




#define jmDebugSignalsPeRegAddrs                                          0x0115
#define JM_DEBUG_SIGNALS_PE_Address                                      0x00454
#define JM_DEBUG_SIGNALS_PE_MSB                                               15
#define JM_DEBUG_SIGNALS_PE_LSB                                                0
#define JM_DEBUG_SIGNALS_PE_BLK                                                0
#define JM_DEBUG_SIGNALS_PE_Count                                              1
#define JM_DEBUG_SIGNALS_PE_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_PE_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_PE_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_PE_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_PE_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_PE_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_PE_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_PE_SIGNAL_Type                                      U32




#define jmDebugSignalsDeRegAddrs                                          0x0116
#define JM_DEBUG_SIGNALS_DE_Address                                      0x00458
#define JM_DEBUG_SIGNALS_DE_MSB                                               15
#define JM_DEBUG_SIGNALS_DE_LSB                                                0
#define JM_DEBUG_SIGNALS_DE_BLK                                                0
#define JM_DEBUG_SIGNALS_DE_Count                                              1
#define JM_DEBUG_SIGNALS_DE_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_DE_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_DE_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_DE_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_DE_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_DE_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_DE_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_DE_SIGNAL_Type                                      U32




#define jmDebugSignalsShRegAddrs                                          0x0117
#define JM_DEBUG_SIGNALS_SH_Address                                      0x0045C
#define JM_DEBUG_SIGNALS_SH_MSB                                               15
#define JM_DEBUG_SIGNALS_SH_LSB                                                0
#define JM_DEBUG_SIGNALS_SH_BLK                                                0
#define JM_DEBUG_SIGNALS_SH_Count                                              1
#define JM_DEBUG_SIGNALS_SH_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_SH_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_SH_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_SH_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_SH_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_SH_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_SH_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_SH_SIGNAL_Type                                      U32




#define jmDebugSignalsPaRegAddrs                                          0x0118
#define JM_DEBUG_SIGNALS_PA_Address                                      0x00460
#define JM_DEBUG_SIGNALS_PA_MSB                                               15
#define JM_DEBUG_SIGNALS_PA_LSB                                                0
#define JM_DEBUG_SIGNALS_PA_BLK                                                0
#define JM_DEBUG_SIGNALS_PA_Count                                              1
#define JM_DEBUG_SIGNALS_PA_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_PA_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_PA_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_PA_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_PA_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_PA_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_PA_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_PA_SIGNAL_Type                                      U32




#define jmDebugSignalsSeRegAddrs                                          0x0119
#define JM_DEBUG_SIGNALS_SE_Address                                      0x00464
#define JM_DEBUG_SIGNALS_SE_MSB                                               15
#define JM_DEBUG_SIGNALS_SE_LSB                                                0
#define JM_DEBUG_SIGNALS_SE_BLK                                                0
#define JM_DEBUG_SIGNALS_SE_Count                                              1
#define JM_DEBUG_SIGNALS_SE_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_SE_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_SE_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_SE_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_SE_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_SE_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_SE_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_SE_SIGNAL_Type                                      U32




#define jmDebugSignalsMcRegAddrs                                          0x011A
#define JM_DEBUG_SIGNALS_MC_Address                                      0x00468
#define JM_DEBUG_SIGNALS_MC_MSB                                               15
#define JM_DEBUG_SIGNALS_MC_LSB                                                0
#define JM_DEBUG_SIGNALS_MC_BLK                                                0
#define JM_DEBUG_SIGNALS_MC_Count                                              1
#define JM_DEBUG_SIGNALS_MC_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_MC_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_MC_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_MC_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_MC_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_MC_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_MC_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_MC_SIGNAL_Type                                      U32




#define jmDebugSignalsHiRegAddrs                                          0x011B
#define JM_DEBUG_SIGNALS_HI_Address                                      0x0046C
#define JM_DEBUG_SIGNALS_HI_MSB                                               15
#define JM_DEBUG_SIGNALS_HI_LSB                                                0
#define JM_DEBUG_SIGNALS_HI_BLK                                                0
#define JM_DEBUG_SIGNALS_HI_Count                                              1
#define JM_DEBUG_SIGNALS_HI_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_HI_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_HI_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_HI_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_HI_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_HI_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_HI_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_HI_SIGNAL_Type                                      U32

#define jmDebugControl0RegAddrs                                           0x011C
#define JM_DEBUG_CONTROL0_Address                                        0x00470
#define JM_DEBUG_CONTROL0_MSB                                                 15
#define JM_DEBUG_CONTROL0_LSB                                                  0
#define JM_DEBUG_CONTROL0_BLK                                                  0
#define JM_DEBUG_CONTROL0_Count                                                1
#define JM_DEBUG_CONTROL0_FieldMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL0_ReadMask                                    0xFFFFFFFF
#define JM_DEBUG_CONTROL0_WriteMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL0_ResetValue                                  0x00000000

#define JM_DEBUG_CONTROL0_FE                                                 7:0
#define JM_DEBUG_CONTROL0_FE_End                                               7
#define JM_DEBUG_CONTROL0_FE_Start                                             0
#define JM_DEBUG_CONTROL0_FE_Type                                            U08

#define JM_DEBUG_CONTROL0_DE                                                15:8
#define JM_DEBUG_CONTROL0_DE_End                                              15
#define JM_DEBUG_CONTROL0_DE_Start                                             8
#define JM_DEBUG_CONTROL0_DE_Type                                            U08

#define JM_DEBUG_CONTROL0_PE                                               23:16
#define JM_DEBUG_CONTROL0_PE_End                                              23
#define JM_DEBUG_CONTROL0_PE_Start                                            16
#define JM_DEBUG_CONTROL0_PE_Type                                            U08

#define JM_DEBUG_CONTROL0_SH                                               31:24
#define JM_DEBUG_CONTROL0_SH_End                                              31
#define JM_DEBUG_CONTROL0_SH_Start                                            24
#define JM_DEBUG_CONTROL0_SH_Type                                            U08

#define jmDebugControl1RegAddrs                                           0x011D
#define JM_DEBUG_CONTROL1_Address                                        0x00474
#define JM_DEBUG_CONTROL1_MSB                                                 15
#define JM_DEBUG_CONTROL1_LSB                                                  0
#define JM_DEBUG_CONTROL1_BLK                                                  0
#define JM_DEBUG_CONTROL1_Count                                                1
#define JM_DEBUG_CONTROL1_FieldMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL1_ReadMask                                    0xFFFFFFFF
#define JM_DEBUG_CONTROL1_WriteMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL1_ResetValue                                  0x00000000

#define JM_DEBUG_CONTROL1_PA                                                 7:0
#define JM_DEBUG_CONTROL1_PA_End                                               7
#define JM_DEBUG_CONTROL1_PA_Start                                             0
#define JM_DEBUG_CONTROL1_PA_Type                                            U08

#define JM_DEBUG_CONTROL1_SE                                                15:8
#define JM_DEBUG_CONTROL1_SE_End                                              15
#define JM_DEBUG_CONTROL1_SE_Start                                             8
#define JM_DEBUG_CONTROL1_SE_Type                                            U08

#define JM_DEBUG_CONTROL1_RA                                               23:16
#define JM_DEBUG_CONTROL1_RA_End                                              23
#define JM_DEBUG_CONTROL1_RA_Start                                            16
#define JM_DEBUG_CONTROL1_RA_Type                                            U08

#define JM_DEBUG_CONTROL1_TX                                               31:24
#define JM_DEBUG_CONTROL1_TX_End                                              31
#define JM_DEBUG_CONTROL1_TX_Start                                            24
#define JM_DEBUG_CONTROL1_TX_Type                                            U08

#define jmDebugControl2RegAddrs                                           0x011E
#define JM_DEBUG_CONTROL2_Address                                        0x00478
#define JM_DEBUG_CONTROL2_MSB                                                 15
#define JM_DEBUG_CONTROL2_LSB                                                  0
#define JM_DEBUG_CONTROL2_BLK                                                  0
#define JM_DEBUG_CONTROL2_Count                                                1
#define JM_DEBUG_CONTROL2_FieldMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL2_ReadMask                                    0xFFFFFFFF
#define JM_DEBUG_CONTROL2_WriteMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL2_ResetValue                                  0x00000000

#define JM_DEBUG_CONTROL2_MC                                                 7:0
#define JM_DEBUG_CONTROL2_MC_End                                               7
#define JM_DEBUG_CONTROL2_MC_Start                                             0
#define JM_DEBUG_CONTROL2_MC_Type                                            U08

#define JM_DEBUG_CONTROL2_HI                                                15:8
#define JM_DEBUG_CONTROL2_HI_End                                              15
#define JM_DEBUG_CONTROL2_HI_Start                                             8
#define JM_DEBUG_CONTROL2_HI_Type                                            U08

#define JM_DEBUG_CONTROL2_L2                                               23:16
#define JM_DEBUG_CONTROL2_L2_End                                              23
#define JM_DEBUG_CONTROL2_L2_Start                                            16
#define JM_DEBUG_CONTROL2_L2_Type                                            U08

#define JM_DEBUG_CONTROL2_BLT                                              31:24
#define JM_DEBUG_CONTROL2_BLT_End                                             31
#define JM_DEBUG_CONTROL2_BLT_Start                                           24
#define JM_DEBUG_CONTROL2_BLT_Type                                           U08

#define jmDebugControl3RegAddrs                                           0x011F
#define JM_DEBUG_CONTROL3_Address                                        0x0047C
#define JM_DEBUG_CONTROL3_MSB                                                 15
#define JM_DEBUG_CONTROL3_LSB                                                  0
#define JM_DEBUG_CONTROL3_BLK                                                  0
#define JM_DEBUG_CONTROL3_Count                                                1
#define JM_DEBUG_CONTROL3_FieldMask                                   0x00000F0F
#define JM_DEBUG_CONTROL3_ReadMask                                    0x00000F0F
#define JM_DEBUG_CONTROL3_WriteMask                                   0x00000F0F
#define JM_DEBUG_CONTROL3_ResetValue                                  0x00000000

#define JM_DEBUG_CONTROL3_PROBE0                                             3:0
#define JM_DEBUG_CONTROL3_PROBE0_End                                           3
#define JM_DEBUG_CONTROL3_PROBE0_Start                                         0
#define JM_DEBUG_CONTROL3_PROBE0_Type                                        U04
#define   JM_DEBUG_CONTROL3_PROBE0_FE                                        0x0
#define   JM_DEBUG_CONTROL3_PROBE0_DE                                        0x1
#define   JM_DEBUG_CONTROL3_PROBE0_PE                                        0x2
#define   JM_DEBUG_CONTROL3_PROBE0_SH                                        0x3
#define   JM_DEBUG_CONTROL3_PROBE0_PA                                        0x4
#define   JM_DEBUG_CONTROL3_PROBE0_SE                                        0x5
#define   JM_DEBUG_CONTROL3_PROBE0_RA                                        0x6
#define   JM_DEBUG_CONTROL3_PROBE0_TX                                        0x7
#define   JM_DEBUG_CONTROL3_PROBE0_MC                                        0x8
#define   JM_DEBUG_CONTROL3_PROBE0_PPA                                       0x9

#define JM_DEBUG_CONTROL3_PROBE1                                            11:8
#define JM_DEBUG_CONTROL3_PROBE1_End                                          11
#define JM_DEBUG_CONTROL3_PROBE1_Start                                         8
#define JM_DEBUG_CONTROL3_PROBE1_Type                                        U04
#define   JM_DEBUG_CONTROL3_PROBE1_FE                                        0x0
#define   JM_DEBUG_CONTROL3_PROBE1_DE                                        0x1
#define   JM_DEBUG_CONTROL3_PROBE1_PE                                        0x2
#define   JM_DEBUG_CONTROL3_PROBE1_SH                                        0x3
#define   JM_DEBUG_CONTROL3_PROBE1_PA                                        0x4
#define   JM_DEBUG_CONTROL3_PROBE1_SE                                        0x5
#define   JM_DEBUG_CONTROL3_PROBE1_RA                                        0x6
#define   JM_DEBUG_CONTROL3_PROBE1_TX                                        0x7
#define   JM_DEBUG_CONTROL3_PROBE1_MC                                        0x8
#define   JM_DEBUG_CONTROL3_PROBE1_PPA                                       0x9

#define jmBusControlRegAddrs                                              0x0120
#define JM_BUS_CONTROL_Address                                           0x00480
#define JM_BUS_CONTROL_MSB                                                    15
#define JM_BUS_CONTROL_LSB                                                     0
#define JM_BUS_CONTROL_BLK                                                     0
#define JM_BUS_CONTROL_Count                                                   1
#define JM_BUS_CONTROL_FieldMask                                      0x000003FF
#define JM_BUS_CONTROL_ReadMask                                       0x000003FF
#define JM_BUS_CONTROL_WriteMask                                      0x000003EF
#define JM_BUS_CONTROL_ResetValue                                     0x00000288


#define JM_BUS_CONTROL_PEC                                                   0:0
#define JM_BUS_CONTROL_PEC_End                                                 0
#define JM_BUS_CONTROL_PEC_Start                                               0
#define JM_BUS_CONTROL_PEC_Type                                              U01


#define JM_BUS_CONTROL_PEZ                                                   1:1
#define JM_BUS_CONTROL_PEZ_End                                                 1
#define JM_BUS_CONTROL_PEZ_Start                                               1
#define JM_BUS_CONTROL_PEZ_Type                                              U01


#define JM_BUS_CONTROL_DC                                                    2:2
#define JM_BUS_CONTROL_DC_End                                                  2
#define JM_BUS_CONTROL_DC_Start                                                2
#define JM_BUS_CONTROL_DC_Type                                               U01


#define JM_BUS_CONTROL_FE                                                    3:3
#define JM_BUS_CONTROL_FE_End                                                  3
#define JM_BUS_CONTROL_FE_Start                                                3
#define JM_BUS_CONTROL_FE_Type                                               U01


#define JM_BUS_CONTROL_UNUSED                                                4:4
#define JM_BUS_CONTROL_UNUSED_End                                              4
#define JM_BUS_CONTROL_UNUSED_Start                                            4
#define JM_BUS_CONTROL_UNUSED_Type                                           U01


#define JM_BUS_CONTROL_MMU                                                   5:5
#define JM_BUS_CONTROL_MMU_End                                                 5
#define JM_BUS_CONTROL_MMU_Start                                               5
#define JM_BUS_CONTROL_MMU_Type                                              U01


#define JM_BUS_CONTROL_FC                                                    6:6
#define JM_BUS_CONTROL_FC_End                                                  6
#define JM_BUS_CONTROL_FC_Start                                                6
#define JM_BUS_CONTROL_FC_Type                                               U01


#define JM_BUS_CONTROL_TX                                                    7:7
#define JM_BUS_CONTROL_TX_End                                                  7
#define JM_BUS_CONTROL_TX_Start                                                7
#define JM_BUS_CONTROL_TX_Type                                               U01


#define JM_BUS_CONTROL_FCC                                                   8:8
#define JM_BUS_CONTROL_FCC_End                                                 8
#define JM_BUS_CONTROL_FCC_Start                                               8
#define JM_BUS_CONTROL_FCC_Type                                              U01


#define JM_BUS_CONTROL_SH                                                    9:9
#define JM_BUS_CONTROL_SH_End                                                  9
#define JM_BUS_CONTROL_SH_Start                                                9
#define JM_BUS_CONTROL_SH_Type                                               U01

#define mwv207regEndianness0RegAddrs                                      0x0121
#define MWV207REG_ENDIANNESS0_Address                                    0x00484
#define MWV207REG_ENDIANNESS0_MSB                                             15
#define MWV207REG_ENDIANNESS0_LSB                                              0
#define MWV207REG_ENDIANNESS0_BLK                                              0
#define MWV207REG_ENDIANNESS0_Count                                            1
#define MWV207REG_ENDIANNESS0_FieldMask                               0xFFFFFFFF
#define MWV207REG_ENDIANNESS0_ReadMask                                0xFFFFFFFF
#define MWV207REG_ENDIANNESS0_WriteMask                               0xFFFFFFFF
#define MWV207REG_ENDIANNESS0_ResetValue                              0x00000000


#define MWV207REG_ENDIANNESS0_WORD_SWAP                                     31:0
#define MWV207REG_ENDIANNESS0_WORD_SWAP_End                                   31
#define MWV207REG_ENDIANNESS0_WORD_SWAP_Start                                  0
#define MWV207REG_ENDIANNESS0_WORD_SWAP_Type                                 U32

#define mwv207regEndianness1RegAddrs                                      0x0122
#define MWV207REG_ENDIANNESS1_Address                                    0x00488
#define MWV207REG_ENDIANNESS1_MSB                                             15
#define MWV207REG_ENDIANNESS1_LSB                                              0
#define MWV207REG_ENDIANNESS1_BLK                                              0
#define MWV207REG_ENDIANNESS1_Count                                            1
#define MWV207REG_ENDIANNESS1_FieldMask                               0xFFFFFFFF
#define MWV207REG_ENDIANNESS1_ReadMask                                0xFFFFFFFF
#define MWV207REG_ENDIANNESS1_WriteMask                               0xFFFFFFFF
#define MWV207REG_ENDIANNESS1_ResetValue                              0x00000000


#define MWV207REG_ENDIANNESS1_BYTE_SWAP                                     31:0
#define MWV207REG_ENDIANNESS1_BYTE_SWAP_End                                   31
#define MWV207REG_ENDIANNESS1_BYTE_SWAP_Start                                  0
#define MWV207REG_ENDIANNESS1_BYTE_SWAP_Type                                 U32

#define mwv207regEndianness2RegAddrs                                      0x0123
#define MWV207REG_ENDIANNESS2_Address                                    0x0048C
#define MWV207REG_ENDIANNESS2_MSB                                             15
#define MWV207REG_ENDIANNESS2_LSB                                              0
#define MWV207REG_ENDIANNESS2_BLK                                              0
#define MWV207REG_ENDIANNESS2_Count                                            1
#define MWV207REG_ENDIANNESS2_FieldMask                               0xFFFFFFFF
#define MWV207REG_ENDIANNESS2_ReadMask                                0xFFFFFFFF
#define MWV207REG_ENDIANNESS2_WriteMask                               0xFFFFFFFF
#define MWV207REG_ENDIANNESS2_ResetValue                              0x00000000


#define MWV207REG_ENDIANNESS2_BIT_SWAP                                      31:0
#define MWV207REG_ENDIANNESS2_BIT_SWAP_End                                    31
#define MWV207REG_ENDIANNESS2_BIT_SWAP_Start                                   0
#define MWV207REG_ENDIANNESS2_BIT_SWAP_Type                                  U32

#define mwv207regDrawPrimitiveStartTimeStampRegAddrs                      0x0124
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_Address                0x00490
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_MSB                         15
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_LSB                          0
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_BLK                          0
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_Count                        1
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_FieldMask           0xFFFFFFFF
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_ReadMask            0xFFFFFFFF
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_WriteMask           0x00000000
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_ResetValue          0x00000000


#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_START_TIME                31:0
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_START_TIME_End              31
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_START_TIME_Start             0
#define MWV207REG_DRAW_PRIMITIVE_START_TIME_STAMP_START_TIME_Type            U32

#define mwv207regDrawPrimitiveEndTimeStampRegAddrs                        0x0125
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_Address                  0x00494
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_MSB                           15
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_LSB                            0
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_BLK                            0
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_Count                          1
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_FieldMask             0xFFFFFFFF
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_ReadMask              0xFFFFFFFF
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_WriteMask             0x00000000
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_ResetValue            0x00000000


#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_END_TIME                    31:0
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_END_TIME_End                  31
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_END_TIME_Start                 0
#define MWV207REG_DRAW_PRIMITIVE_END_TIME_STAMP_END_TIME_Type                U32

#define mwv207regReqBankAddrMaskRegAddrs                                  0x0126
#define MWV207REG_REQ_BANK_ADDR_MASK_Address                             0x00498
#define MWV207REG_REQ_BANK_ADDR_MASK_MSB                                      15
#define MWV207REG_REQ_BANK_ADDR_MASK_LSB                                       0
#define MWV207REG_REQ_BANK_ADDR_MASK_BLK                                       0
#define MWV207REG_REQ_BANK_ADDR_MASK_Count                                     1
#define MWV207REG_REQ_BANK_ADDR_MASK_FieldMask                        0xFFFFFFFF
#define MWV207REG_REQ_BANK_ADDR_MASK_ReadMask                         0xFFFFFFFF
#define MWV207REG_REQ_BANK_ADDR_MASK_WriteMask                        0xFFFFFFFF
#define MWV207REG_REQ_BANK_ADDR_MASK_ResetValue                       0x00000000


#define MWV207REG_REQ_BANK_ADDR_MASK_REQ_BANK_ADDR_MASK                     31:0
#define MWV207REG_REQ_BANK_ADDR_MASK_REQ_BANK_ADDR_MASK_End                   31
#define MWV207REG_REQ_BANK_ADDR_MASK_REQ_BANK_ADDR_MASK_Start                  0
#define MWV207REG_REQ_BANK_ADDR_MASK_REQ_BANK_ADDR_MASK_Type                 U32

#define mwv207regReqRowAddrMaskRegAddrs                                   0x0127
#define MWV207REG_REQ_ROW_ADDR_MASK_Address                              0x0049C
#define MWV207REG_REQ_ROW_ADDR_MASK_MSB                                       15
#define MWV207REG_REQ_ROW_ADDR_MASK_LSB                                        0
#define MWV207REG_REQ_ROW_ADDR_MASK_BLK                                        0
#define MWV207REG_REQ_ROW_ADDR_MASK_Count                                      1
#define MWV207REG_REQ_ROW_ADDR_MASK_FieldMask                         0xFFFFFFFF
#define MWV207REG_REQ_ROW_ADDR_MASK_ReadMask                          0xFFFFFFFF
#define MWV207REG_REQ_ROW_ADDR_MASK_WriteMask                         0xFFFFFFFF
#define MWV207REG_REQ_ROW_ADDR_MASK_ResetValue                        0x00000000


#define MWV207REG_REQ_ROW_ADDR_MASK_REQ_ROW_ADDR_MASK                       31:0
#define MWV207REG_REQ_ROW_ADDR_MASK_REQ_ROW_ADDR_MASK_End                     31
#define MWV207REG_REQ_ROW_ADDR_MASK_REQ_ROW_ADDR_MASK_Start                    0
#define MWV207REG_REQ_ROW_ADDR_MASK_REQ_ROW_ADDR_MASK_Type                   U32

#define mwv207regReqWeightRegAddrs                                        0x0128
#define MWV207REG_REQ_WEIGHT_Address                                     0x004A0
#define MWV207REG_REQ_WEIGHT_MSB                                              15
#define MWV207REG_REQ_WEIGHT_LSB                                               3
#define MWV207REG_REQ_WEIGHT_BLK                                               3
#define MWV207REG_REQ_WEIGHT_Count                                             8
#define MWV207REG_REQ_WEIGHT_FieldMask                                0xFFFFFFFF
#define MWV207REG_REQ_WEIGHT_ReadMask                                 0xFFFFFFFF
#define MWV207REG_REQ_WEIGHT_WriteMask                                0xFFFFFFFF
#define MWV207REG_REQ_WEIGHT_ResetValue                               0x00000000

#define MWV207REG_REQ_WEIGHT_REQ_WEIGHT                                     31:0
#define MWV207REG_REQ_WEIGHT_REQ_WEIGHT_End                                   31
#define MWV207REG_REQ_WEIGHT_REQ_WEIGHT_Start                                  0
#define MWV207REG_REQ_WEIGHT_REQ_WEIGHT_Type                                 U32

#define mwv207regRdReqAgingThreshRegAddrs                                 0x0130
#define MWV207REG_RD_REQ_AGING_THRESH_Address                            0x004C0
#define MWV207REG_RD_REQ_AGING_THRESH_MSB                                     15
#define MWV207REG_RD_REQ_AGING_THRESH_LSB                                      4
#define MWV207REG_RD_REQ_AGING_THRESH_BLK                                      4
#define MWV207REG_RD_REQ_AGING_THRESH_Count                                   16
#define MWV207REG_RD_REQ_AGING_THRESH_FieldMask                       0x0000FFFF
#define MWV207REG_RD_REQ_AGING_THRESH_ReadMask                        0x0000FFFF
#define MWV207REG_RD_REQ_AGING_THRESH_WriteMask                       0x0000FFFF
#define MWV207REG_RD_REQ_AGING_THRESH_ResetValue                      0x00000000

#define MWV207REG_RD_REQ_AGING_THRESH_RD_REQ_AGING_THRESH                   15:0
#define MWV207REG_RD_REQ_AGING_THRESH_RD_REQ_AGING_THRESH_End                 15
#define MWV207REG_RD_REQ_AGING_THRESH_RD_REQ_AGING_THRESH_Start                0
#define MWV207REG_RD_REQ_AGING_THRESH_RD_REQ_AGING_THRESH_Type               U16

#define mwv207regWrReqAgingThreshRegAddrs                                 0x0140
#define MWV207REG_WR_REQ_AGING_THRESH_Address                            0x00500
#define MWV207REG_WR_REQ_AGING_THRESH_MSB                                     15
#define MWV207REG_WR_REQ_AGING_THRESH_LSB                                      4
#define MWV207REG_WR_REQ_AGING_THRESH_BLK                                      4
#define MWV207REG_WR_REQ_AGING_THRESH_Count                                   16
#define MWV207REG_WR_REQ_AGING_THRESH_FieldMask                       0x0000FFFF
#define MWV207REG_WR_REQ_AGING_THRESH_ReadMask                        0x0000FFFF
#define MWV207REG_WR_REQ_AGING_THRESH_WriteMask                       0x0000FFFF
#define MWV207REG_WR_REQ_AGING_THRESH_ResetValue                      0x00000000

#define MWV207REG_WR_REQ_AGING_THRESH_WR_REQ_AGING_THRESH                   15:0
#define MWV207REG_WR_REQ_AGING_THRESH_WR_REQ_AGING_THRESH_End                 15
#define MWV207REG_WR_REQ_AGING_THRESH_WR_REQ_AGING_THRESH_Start                0
#define MWV207REG_WR_REQ_AGING_THRESH_WR_REQ_AGING_THRESH_Type               U16

#define mwv207regControlRegAddrs                                          0x0150
#define MWV207REG_CONTROL_Address                                        0x00540
#define MWV207REG_CONTROL_MSB                                                 15
#define MWV207REG_CONTROL_LSB                                                  0
#define MWV207REG_CONTROL_BLK                                                  0
#define MWV207REG_CONTROL_Count                                                1
#define MWV207REG_CONTROL_FieldMask                                   0x00000301
#define MWV207REG_CONTROL_ReadMask                                    0x00000301
#define MWV207REG_CONTROL_WriteMask                                   0x00000301
#define MWV207REG_CONTROL_ResetValue                                  0x00000001

#define MWV207REG_CONTROL_L2_ENABLE                                          0:0
#define MWV207REG_CONTROL_L2_ENABLE_End                                        0
#define MWV207REG_CONTROL_L2_ENABLE_Start                                      0
#define MWV207REG_CONTROL_L2_ENABLE_Type                                     U01

#define MWV207REG_CONTROL_DDR_CONFIG                                         8:8
#define MWV207REG_CONTROL_DDR_CONFIG_End                                       8
#define MWV207REG_CONTROL_DDR_CONFIG_Start                                     8
#define MWV207REG_CONTROL_DDR_CONFIG_Type                                    U01
#define   MWV207REG_CONTROL_DDR_CONFIG_DDR64_BIT                             0x0
#define   MWV207REG_CONTROL_DDR_CONFIG_DDR32_BIT                             0x1

#define MWV207REG_CONTROL_TIME_COUNTER                                       9:9
#define MWV207REG_CONTROL_TIME_COUNTER_End                                     9
#define MWV207REG_CONTROL_TIME_COUNTER_Start                                   9
#define MWV207REG_CONTROL_TIME_COUNTER_Type                                  U01
#define   MWV207REG_CONTROL_TIME_COUNTER_DISABLE                             0x0
#define   MWV207REG_CONTROL_TIME_COUNTER_ENABLE                              0x1

#define mwv207regCounter0RegAddrs                                         0x0151
#define MWV207REG_COUNTER0_Address                                       0x00544
#define MWV207REG_COUNTER0_MSB                                                15
#define MWV207REG_COUNTER0_LSB                                                 0
#define MWV207REG_COUNTER0_BLK                                                 0
#define MWV207REG_COUNTER0_Count                                               1
#define MWV207REG_COUNTER0_FieldMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER0_ReadMask                                   0xFFFFFFFF
#define MWV207REG_COUNTER0_WriteMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER0_ResetValue                                 0x00000000

#define MWV207REG_COUNTER0_COUNTER                                          31:0
#define MWV207REG_COUNTER0_COUNTER_End                                        31
#define MWV207REG_COUNTER0_COUNTER_Start                                       0
#define MWV207REG_COUNTER0_COUNTER_Type                                      U32

#define mwv207regCounter1RegAddrs                                         0x0152
#define MWV207REG_COUNTER1_Address                                       0x00548
#define MWV207REG_COUNTER1_MSB                                                15
#define MWV207REG_COUNTER1_LSB                                                 0
#define MWV207REG_COUNTER1_BLK                                                 0
#define MWV207REG_COUNTER1_Count                                               1
#define MWV207REG_COUNTER1_FieldMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER1_ReadMask                                   0xFFFFFFFF
#define MWV207REG_COUNTER1_WriteMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER1_ResetValue                                 0x00000000

#define MWV207REG_COUNTER1_COUNTER                                          31:0
#define MWV207REG_COUNTER1_COUNTER_End                                        31
#define MWV207REG_COUNTER1_COUNTER_Start                                       0
#define MWV207REG_COUNTER1_COUNTER_Type                                      U32

#define mwv207regCounter2RegAddrs                                         0x0153
#define MWV207REG_COUNTER2_Address                                       0x0054C
#define MWV207REG_COUNTER2_MSB                                                15
#define MWV207REG_COUNTER2_LSB                                                 0
#define MWV207REG_COUNTER2_BLK                                                 0
#define MWV207REG_COUNTER2_Count                                               1
#define MWV207REG_COUNTER2_FieldMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER2_ReadMask                                   0xFFFFFFFF
#define MWV207REG_COUNTER2_WriteMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER2_ResetValue                                 0x00000000

#define MWV207REG_COUNTER2_COUNTER                                          31:0
#define MWV207REG_COUNTER2_COUNTER_End                                        31
#define MWV207REG_COUNTER2_COUNTER_Start                                       0
#define MWV207REG_COUNTER2_COUNTER_Type                                      U32

#define mwv207regCounter3RegAddrs                                         0x0154
#define MWV207REG_COUNTER3_Address                                       0x00550
#define MWV207REG_COUNTER3_MSB                                                15
#define MWV207REG_COUNTER3_LSB                                                 0
#define MWV207REG_COUNTER3_BLK                                                 0
#define MWV207REG_COUNTER3_Count                                               1
#define MWV207REG_COUNTER3_FieldMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER3_ReadMask                                   0xFFFFFFFF
#define MWV207REG_COUNTER3_WriteMask                                  0xFFFFFFFF
#define MWV207REG_COUNTER3_ResetValue                                 0x00000000

#define MWV207REG_COUNTER3_COUNTER                                          31:0
#define MWV207REG_COUNTER3_COUNTER_End                                        31
#define MWV207REG_COUNTER3_COUNTER_Start                                       0
#define MWV207REG_COUNTER3_COUNTER_Type                                      U32




#define mwv207regCETriggerAsyncRegAddrs                                   0x0155
#define MWV207REG_CE_TRIGGER_ASYNC_Address                               0x00554
#define MWV207REG_CE_TRIGGER_ASYNC_MSB                                        15
#define MWV207REG_CE_TRIGGER_ASYNC_LSB                                         0
#define MWV207REG_CE_TRIGGER_ASYNC_BLK                                         0
#define MWV207REG_CE_TRIGGER_ASYNC_Count                                       1
#define MWV207REG_CE_TRIGGER_ASYNC_FieldMask                          0x00000003
#define MWV207REG_CE_TRIGGER_ASYNC_ReadMask                           0x00000003
#define MWV207REG_CE_TRIGGER_ASYNC_WriteMask                          0x00000003
#define MWV207REG_CE_TRIGGER_ASYNC_ResetValue                         0x00000000

#define MWV207REG_CE_TRIGGER_ASYNC_EXECUTE                                   1:0
#define MWV207REG_CE_TRIGGER_ASYNC_EXECUTE_End                                 1
#define MWV207REG_CE_TRIGGER_ASYNC_EXECUTE_Start                               0
#define MWV207REG_CE_TRIGGER_ASYNC_EXECUTE_Type                              U02

#define   MWV207REG_CE_TRIGGER_ASYNC_EXECUTE_IDLE                            0x0

#define   MWV207REG_CE_TRIGGER_ASYNC_EXECUTE_TRIGGER                         0x1
#define   MWV207REG_CE_TRIGGER_ASYNC_EXECUTE_LOAD                            0x3




#define mwv207regControl0RegAddrs                                         0x0156
#define MWV207REG_CONTROL0_Address                                       0x00558
#define MWV207REG_CONTROL0_MSB                                                15
#define MWV207REG_CONTROL0_LSB                                                 0
#define MWV207REG_CONTROL0_BLK                                                 0
#define MWV207REG_CONTROL0_Count                                               1
#define MWV207REG_CONTROL0_FieldMask                                  0x0FFF00FF
#define MWV207REG_CONTROL0_ReadMask                                   0x0FFF00FF
#define MWV207REG_CONTROL0_WriteMask                                  0x0FFF00FF
#define MWV207REG_CONTROL0_ResetValue                                 0x00800005

#define MWV207REG_CONTROL0_ENABLE_READ_MERGE                                 0:0
#define MWV207REG_CONTROL0_ENABLE_READ_MERGE_End                               0
#define MWV207REG_CONTROL0_ENABLE_READ_MERGE_Start                             0
#define MWV207REG_CONTROL0_ENABLE_READ_MERGE_Type                            U01

#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_MERGE                            1:1
#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_MERGE_End                          1
#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_MERGE_Start                        1
#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_MERGE_Type                       U01

#define MWV207REG_CONTROL0_ENABLE_WRITE_MERGE                                2:2
#define MWV207REG_CONTROL0_ENABLE_WRITE_MERGE_End                              2
#define MWV207REG_CONTROL0_ENABLE_WRITE_MERGE_Start                            2
#define MWV207REG_CONTROL0_ENABLE_WRITE_MERGE_Type                           U01

#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE                      3:3
#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_End                    3
#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_Start                  3
#define MWV207REG_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_Type                 U01

#define MWV207REG_CONTROL0_DISABLE_AXI_REORDER                               4:4
#define MWV207REG_CONTROL0_DISABLE_AXI_REORDER_End                             4
#define MWV207REG_CONTROL0_DISABLE_AXI_REORDER_Start                           4
#define MWV207REG_CONTROL0_DISABLE_AXI_REORDER_Type                          U01

#define MWV207REG_CONTROL0_DISABLE_AXI_WRITE_REORDER                         5:5
#define MWV207REG_CONTROL0_DISABLE_AXI_WRITE_REORDER_End                       5
#define MWV207REG_CONTROL0_DISABLE_AXI_WRITE_REORDER_Start                     5
#define MWV207REG_CONTROL0_DISABLE_AXI_WRITE_REORDER_Type                    U01

#define MWV207REG_CONTROL0_FORCE_ON_AXI0                                     6:6
#define MWV207REG_CONTROL0_FORCE_ON_AXI0_End                                   6
#define MWV207REG_CONTROL0_FORCE_ON_AXI0_Start                                 6
#define MWV207REG_CONTROL0_FORCE_ON_AXI0_Type                                U01

#define MWV207REG_CONTROL0_FORCE_ON_AXI1                                     7:7
#define MWV207REG_CONTROL0_FORCE_ON_AXI1_End                                   7
#define MWV207REG_CONTROL0_FORCE_ON_AXI1_Start                                 7
#define MWV207REG_CONTROL0_FORCE_ON_AXI1_Type                                U01

#define MWV207REG_CONTROL0_OUTSTANDING_READS_PER_CHANNEL                   25:16
#define MWV207REG_CONTROL0_OUTSTANDING_READS_PER_CHANNEL_End                  25
#define MWV207REG_CONTROL0_OUTSTANDING_READS_PER_CHANNEL_Start                16
#define MWV207REG_CONTROL0_OUTSTANDING_READS_PER_CHANNEL_Type                U10


#define MWV207REG_CONTROL0_BY_PASS_TPC                                     26:26
#define MWV207REG_CONTROL0_BY_PASS_TPC_End                                    26
#define MWV207REG_CONTROL0_BY_PASS_TPC_Start                                  26
#define MWV207REG_CONTROL0_BY_PASS_TPC_Type                                  U01
#define   MWV207REG_CONTROL0_BY_PASS_TPC_DISABLED                            0x0
#define   MWV207REG_CONTROL0_BY_PASS_TPC_ENABLED                             0x1


#define MWV207REG_CONTROL0_DEBUG_TPC                                       27:27
#define MWV207REG_CONTROL0_DEBUG_TPC_End                                      27
#define MWV207REG_CONTROL0_DEBUG_TPC_Start                                    27
#define MWV207REG_CONTROL0_DEBUG_TPC_Type                                    U01
#define   MWV207REG_CONTROL0_DEBUG_TPC_DISABLED                              0x0
#define   MWV207REG_CONTROL0_DEBUG_TPC_ENABLED                               0x1




#define mwv207regControl1RegAddrs                                         0x0157
#define MWV207REG_CONTROL1_Address                                       0x0055C
#define MWV207REG_CONTROL1_MSB                                                15
#define MWV207REG_CONTROL1_LSB                                                 0
#define MWV207REG_CONTROL1_BLK                                                 0
#define MWV207REG_CONTROL1_Count                                               1
#define MWV207REG_CONTROL1_FieldMask                                  0xFFFFFFFF
#define MWV207REG_CONTROL1_ReadMask                                   0xFFFFFFFF
#define MWV207REG_CONTROL1_WriteMask                                  0xFFFFFFFF
#define MWV207REG_CONTROL1_ResetValue                                 0x00FF0A05

#define MWV207REG_CONTROL1_ID0                                               7:0
#define MWV207REG_CONTROL1_ID0_End                                             7
#define MWV207REG_CONTROL1_ID0_Start                                           0
#define MWV207REG_CONTROL1_ID0_Type                                          U08

#define MWV207REG_CONTROL1_ID1                                              15:8
#define MWV207REG_CONTROL1_ID1_End                                            15
#define MWV207REG_CONTROL1_ID1_Start                                           8
#define MWV207REG_CONTROL1_ID1_Type                                          U08

#define MWV207REG_CONTROL1_ID2                                             23:16
#define MWV207REG_CONTROL1_ID2_End                                            23
#define MWV207REG_CONTROL1_ID2_Start                                          16
#define MWV207REG_CONTROL1_ID2_Type                                          U08

#define MWV207REG_CONTROL1_FLUSH                                           24:24
#define MWV207REG_CONTROL1_FLUSH_End                                          24
#define MWV207REG_CONTROL1_FLUSH_Start                                        24
#define MWV207REG_CONTROL1_FLUSH_Type                                        U01

#define MWV207REG_CONTROL1_MISC                                            26:25
#define MWV207REG_CONTROL1_MISC_End                                           26
#define MWV207REG_CONTROL1_MISC_Start                                         25
#define MWV207REG_CONTROL1_MISC_Type                                         U02

#define MWV207REG_CONTROL1_DISABLE_L2                                      27:27
#define MWV207REG_CONTROL1_DISABLE_L2_End                                     27
#define MWV207REG_CONTROL1_DISABLE_L2_Start                                   27
#define MWV207REG_CONTROL1_DISABLE_L2_Type                                   U01

#define MWV207REG_CONTROL1_ISOLATE_GPU                                     31:28
#define MWV207REG_CONTROL1_ISOLATE_GPU_End                                    31
#define MWV207REG_CONTROL1_ISOLATE_GPU_Start                                  28
#define MWV207REG_CONTROL1_ISOLATE_GPU_Type                                  U04




#define mwv207regStatus0RegAddrs                                          0x0158
#define MWV207REG_STATUS0_Address                                        0x00560
#define MWV207REG_STATUS0_MSB                                                 15
#define MWV207REG_STATUS0_LSB                                                  0
#define MWV207REG_STATUS0_BLK                                                  0
#define MWV207REG_STATUS0_Count                                                1
#define MWV207REG_STATUS0_FieldMask                                   0x00000001
#define MWV207REG_STATUS0_ReadMask                                    0x00000001
#define MWV207REG_STATUS0_WriteMask                                   0x00000000
#define MWV207REG_STATUS0_ResetValue                                  0x00000000

#define MWV207REG_STATUS0_IDLE_L2                                            0:0
#define MWV207REG_STATUS0_IDLE_L2_End                                          0
#define MWV207REG_STATUS0_IDLE_L2_Start                                        0
#define MWV207REG_STATUS0_IDLE_L2_Type                                       U01




#define jmDebugSignalsL2RegAddrs                                          0x0159
#define JM_DEBUG_SIGNALS_L2_Address                                      0x00564
#define JM_DEBUG_SIGNALS_L2_MSB                                               15
#define JM_DEBUG_SIGNALS_L2_LSB                                                0
#define JM_DEBUG_SIGNALS_L2_BLK                                                0
#define JM_DEBUG_SIGNALS_L2_Count                                              1
#define JM_DEBUG_SIGNALS_L2_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_L2_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_L2_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_L2_ResetValue                                0x00000000

#define JM_DEBUG_SIGNALS_L2_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_L2_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_L2_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_L2_SIGNAL_Type                                      U32




#define jmDebugLatencyMonitorControlRegAddrs                              0x015A
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_Address                         0x00568
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_MSB                                  15
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_LSB                                   0
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_BLK                                   0
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_Count                                 1
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_FieldMask                    0x0000011F
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_ReadMask                     0x0000011F
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_WriteMask                    0x0000011F
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_ResetValue                   0x00000000


#define JM_DEBUG_LATENCY_MONITOR_CONTROL_ID                                  4:0
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_ID_End                                4
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_ID_Start                              0
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_ID_Type                             U05


#define JM_DEBUG_LATENCY_MONITOR_CONTROL_CLEAR                               8:8
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_CLEAR_End                             8
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_CLEAR_Start                           8
#define JM_DEBUG_LATENCY_MONITOR_CONTROL_CLEAR_Type                          U01

#define jmDebugLatencyMonitor0RegAddrs                                    0x015B
#define JM_DEBUG_LATENCY_MONITOR0_Address                                0x0056C
#define JM_DEBUG_LATENCY_MONITOR0_MSB                                         15
#define JM_DEBUG_LATENCY_MONITOR0_LSB                                          0
#define JM_DEBUG_LATENCY_MONITOR0_BLK                                          0
#define JM_DEBUG_LATENCY_MONITOR0_Count                                        1
#define JM_DEBUG_LATENCY_MONITOR0_FieldMask                           0x0FFF0FFF
#define JM_DEBUG_LATENCY_MONITOR0_ReadMask                            0x0FFF0FFF
#define JM_DEBUG_LATENCY_MONITOR0_WriteMask                           0x00000000
#define JM_DEBUG_LATENCY_MONITOR0_ResetValue                          0x00000000

#define JM_DEBUG_LATENCY_MONITOR0_MAX_LATENCY                               11:0
#define JM_DEBUG_LATENCY_MONITOR0_MAX_LATENCY_End                             11
#define JM_DEBUG_LATENCY_MONITOR0_MAX_LATENCY_Start                            0
#define JM_DEBUG_LATENCY_MONITOR0_MAX_LATENCY_Type                           U12

#define JM_DEBUG_LATENCY_MONITOR0_MIN_LATENCY                              27:16
#define JM_DEBUG_LATENCY_MONITOR0_MIN_LATENCY_End                             27
#define JM_DEBUG_LATENCY_MONITOR0_MIN_LATENCY_Start                           16
#define JM_DEBUG_LATENCY_MONITOR0_MIN_LATENCY_Type                           U12

#define jmDebugLatencyMonitor1RegAddrs                                    0x015C
#define JM_DEBUG_LATENCY_MONITOR1_Address                                0x00570
#define JM_DEBUG_LATENCY_MONITOR1_MSB                                         15
#define JM_DEBUG_LATENCY_MONITOR1_LSB                                          0
#define JM_DEBUG_LATENCY_MONITOR1_BLK                                          0
#define JM_DEBUG_LATENCY_MONITOR1_Count                                        1
#define JM_DEBUG_LATENCY_MONITOR1_FieldMask                           0xFFFFFFFF
#define JM_DEBUG_LATENCY_MONITOR1_ReadMask                            0xFFFFFFFF
#define JM_DEBUG_LATENCY_MONITOR1_WriteMask                           0x00000000
#define JM_DEBUG_LATENCY_MONITOR1_ResetValue                          0x00000000

#define JM_DEBUG_LATENCY_MONITOR1_TOTAL_LATENCY                             31:0
#define JM_DEBUG_LATENCY_MONITOR1_TOTAL_LATENCY_End                           31
#define JM_DEBUG_LATENCY_MONITOR1_TOTAL_LATENCY_Start                          0
#define JM_DEBUG_LATENCY_MONITOR1_TOTAL_LATENCY_Type                         U32

#define jmDebugLatencyMonitor2RegAddrs                                    0x015D
#define JM_DEBUG_LATENCY_MONITOR2_Address                                0x00574
#define JM_DEBUG_LATENCY_MONITOR2_MSB                                         15
#define JM_DEBUG_LATENCY_MONITOR2_LSB                                          0
#define JM_DEBUG_LATENCY_MONITOR2_BLK                                          0
#define JM_DEBUG_LATENCY_MONITOR2_Count                                        1
#define JM_DEBUG_LATENCY_MONITOR2_FieldMask                           0x0000FFFF
#define JM_DEBUG_LATENCY_MONITOR2_ReadMask                            0x0000FFFF
#define JM_DEBUG_LATENCY_MONITOR2_WriteMask                           0x00000000
#define JM_DEBUG_LATENCY_MONITOR2_ResetValue                          0x00000000

#define JM_DEBUG_LATENCY_MONITOR2_TOTAL_SAMPLE_COUNT                        15:0
#define JM_DEBUG_LATENCY_MONITOR2_TOTAL_SAMPLE_COUNT_End                      15
#define JM_DEBUG_LATENCY_MONITOR2_TOTAL_SAMPLE_COUNT_Start                     0
#define JM_DEBUG_LATENCY_MONITOR2_TOTAL_SAMPLE_COUNT_Type                    U16

#define mwv207regControl3RegAddrs                                         0x015E
#define MWV207REG_CONTROL3_Address                                       0x00578
#define MWV207REG_CONTROL3_MSB                                                15
#define MWV207REG_CONTROL3_LSB                                                 0
#define MWV207REG_CONTROL3_BLK                                                 0
#define MWV207REG_CONTROL3_Count                                               1
#define MWV207REG_CONTROL3_FieldMask                                  0x01FFFFFF
#define MWV207REG_CONTROL3_ReadMask                                   0x01FFFFFF
#define MWV207REG_CONTROL3_WriteMask                                  0x01FFFFFF
#define MWV207REG_CONTROL3_ResetValue                                 0x00011112

#define MWV207REG_CONTROL3_DOMAIN_SELECT_SHARED                              1:0
#define MWV207REG_CONTROL3_DOMAIN_SELECT_SHARED_End                            1
#define MWV207REG_CONTROL3_DOMAIN_SELECT_SHARED_Start                          0
#define MWV207REG_CONTROL3_DOMAIN_SELECT_SHARED_Type                         U02

#define MWV207REG_CONTROL3_DOMAIN_SELECT_NON_SHARED                          3:2
#define MWV207REG_CONTROL3_DOMAIN_SELECT_NON_SHARED_End                        3
#define MWV207REG_CONTROL3_DOMAIN_SELECT_NON_SHARED_Start                      2
#define MWV207REG_CONTROL3_DOMAIN_SELECT_NON_SHARED_Type                     U02

#define MWV207REG_CONTROL3_QOS0                                              7:4
#define MWV207REG_CONTROL3_QOS0_End                                            7
#define MWV207REG_CONTROL3_QOS0_Start                                          4
#define MWV207REG_CONTROL3_QOS0_Type                                         U04

#define MWV207REG_CONTROL3_QOS1                                             11:8
#define MWV207REG_CONTROL3_QOS1_End                                           11
#define MWV207REG_CONTROL3_QOS1_Start                                          8
#define MWV207REG_CONTROL3_QOS1_Type                                         U04

#define MWV207REG_CONTROL3_QOS2                                            15:12
#define MWV207REG_CONTROL3_QOS2_End                                           15
#define MWV207REG_CONTROL3_QOS2_Start                                         12
#define MWV207REG_CONTROL3_QOS2_Type                                         U04

#define MWV207REG_CONTROL3_QOS3                                            19:16
#define MWV207REG_CONTROL3_QOS3_End                                           19
#define MWV207REG_CONTROL3_QOS3_Start                                         16
#define MWV207REG_CONTROL3_QOS3_Type                                         U04

#define MWV207REG_CONTROL3_GPU_BYPASS_L2                                   23:20
#define MWV207REG_CONTROL3_GPU_BYPASS_L2_End                                  23
#define MWV207REG_CONTROL3_GPU_BYPASS_L2_Start                                20
#define MWV207REG_CONTROL3_GPU_BYPASS_L2_Type                                U04

#define MWV207REG_CONTROL3_DISABLE_L2_FLUSH_ALL                            24:24
#define MWV207REG_CONTROL3_DISABLE_L2_FLUSH_ALL_End                           24
#define MWV207REG_CONTROL3_DISABLE_L2_FLUSH_ALL_Start                         24
#define MWV207REG_CONTROL3_DISABLE_L2_FLUSH_ALL_Type                         U01

#define AQMemoryDebug1RegAddrs                                            0x015F
#define AQ_MEMORY_DEBUG1_Address                                         0x0057C
#define AQ_MEMORY_DEBUG1_MSB                                                  15
#define AQ_MEMORY_DEBUG1_LSB                                                   0
#define AQ_MEMORY_DEBUG1_BLK                                                   0
#define AQ_MEMORY_DEBUG1_Count                                                 1
#define AQ_MEMORY_DEBUG1_FieldMask                                    0x000003FF
#define AQ_MEMORY_DEBUG1_ReadMask                                     0x000003FF
#define AQ_MEMORY_DEBUG1_WriteMask                                    0x000003FF
#define AQ_MEMORY_DEBUG1_ResetValue                                   0x00000000


#define AQ_MEMORY_DEBUG1_HZ_WRITE_LIMIT                                      7:0
#define AQ_MEMORY_DEBUG1_HZ_WRITE_LIMIT_End                                    7
#define AQ_MEMORY_DEBUG1_HZ_WRITE_LIMIT_Start                                  0
#define AQ_MEMORY_DEBUG1_HZ_WRITE_LIMIT_Type                                 U08
#define   AQ_MEMORY_DEBUG1_HZ_WRITE_LIMIT_RESET_LOW                         0x12
#define   AQ_MEMORY_DEBUG1_HZ_WRITE_LIMIT_RESET_HIGH                        0x22
#define   AQ_MEMORY_DEBUG1_HZ_WRITE_LIMIT_RESET_VERY_HIGH                   0x30

#define AQ_MEMORY_DEBUG1_BYPASS_V2_HANG_PROTECTION                           8:8
#define AQ_MEMORY_DEBUG1_BYPASS_V2_HANG_PROTECTION_End                         8
#define AQ_MEMORY_DEBUG1_BYPASS_V2_HANG_PROTECTION_Start                       8
#define AQ_MEMORY_DEBUG1_BYPASS_V2_HANG_PROTECTION_Type                      U01

#define AQ_MEMORY_DEBUG1_DISABLE_PER_GPU_LINK                                9:9
#define AQ_MEMORY_DEBUG1_DISABLE_PER_GPU_LINK_End                              9
#define AQ_MEMORY_DEBUG1_DISABLE_PER_GPU_LINK_Start                            9
#define AQ_MEMORY_DEBUG1_DISABLE_PER_GPU_LINK_Type                           U01




#define jmCoreCycleCounterRegAddrs                                        0x0160
#define JM_CORE_CYCLE_COUNTER_Address                                    0x00580
#define JM_CORE_CYCLE_COUNTER_MSB                                             15
#define JM_CORE_CYCLE_COUNTER_LSB                                              0
#define JM_CORE_CYCLE_COUNTER_BLK                                              0
#define JM_CORE_CYCLE_COUNTER_Count                                            1
#define JM_CORE_CYCLE_COUNTER_FieldMask                               0xFFFFFFFF
#define JM_CORE_CYCLE_COUNTER_ReadMask                                0xFFFFFFFF
#define JM_CORE_CYCLE_COUNTER_WriteMask                               0xC0000000
#define JM_CORE_CYCLE_COUNTER_ResetValue                              0x00000000

#define JM_CORE_CYCLE_COUNTER_COUNT                                         29:0
#define JM_CORE_CYCLE_COUNTER_COUNT_End                                       29
#define JM_CORE_CYCLE_COUNTER_COUNT_Start                                      0
#define JM_CORE_CYCLE_COUNTER_COUNT_Type                                     U30

#define JM_CORE_CYCLE_COUNTER_ENABLE                                       30:30
#define JM_CORE_CYCLE_COUNTER_ENABLE_End                                      30
#define JM_CORE_CYCLE_COUNTER_ENABLE_Start                                    30
#define JM_CORE_CYCLE_COUNTER_ENABLE_Type                                    U01

#define JM_CORE_CYCLE_COUNTER_CLEAR                                        31:31
#define JM_CORE_CYCLE_COUNTER_CLEAR_End                                       31
#define JM_CORE_CYCLE_COUNTER_CLEAR_Start                                     31
#define JM_CORE_CYCLE_COUNTER_CLEAR_Type                                     U01




#define jmShCycleCounterRegAddrs                                          0x0161
#define JM_SH_CYCLE_COUNTER_Address                                      0x00584
#define JM_SH_CYCLE_COUNTER_MSB                                               15
#define JM_SH_CYCLE_COUNTER_LSB                                                0
#define JM_SH_CYCLE_COUNTER_BLK                                                0
#define JM_SH_CYCLE_COUNTER_Count                                              1
#define JM_SH_CYCLE_COUNTER_FieldMask                                 0xFFFFFFFF
#define JM_SH_CYCLE_COUNTER_ReadMask                                  0xFFFFFFFF
#define JM_SH_CYCLE_COUNTER_WriteMask                                 0xC0000000
#define JM_SH_CYCLE_COUNTER_ResetValue                                0x00000000

#define JM_SH_CYCLE_COUNTER_COUNT                                           29:0
#define JM_SH_CYCLE_COUNTER_COUNT_End                                         29
#define JM_SH_CYCLE_COUNTER_COUNT_Start                                        0
#define JM_SH_CYCLE_COUNTER_COUNT_Type                                       U30

#define JM_SH_CYCLE_COUNTER_ENABLE                                         30:30
#define JM_SH_CYCLE_COUNTER_ENABLE_End                                        30
#define JM_SH_CYCLE_COUNTER_ENABLE_Start                                      30
#define JM_SH_CYCLE_COUNTER_ENABLE_Type                                      U01

#define JM_SH_CYCLE_COUNTER_CLEAR                                          31:31
#define JM_SH_CYCLE_COUNTER_CLEAR_End                                         31
#define JM_SH_CYCLE_COUNTER_CLEAR_Start                                       31
#define JM_SH_CYCLE_COUNTER_CLEAR_Type                                       U01




#define jmAxiCycleCounterRegAddrs                                         0x0162
#define JM_AXI_CYCLE_COUNTER_Address                                     0x00588
#define JM_AXI_CYCLE_COUNTER_MSB                                              15
#define JM_AXI_CYCLE_COUNTER_LSB                                               0
#define JM_AXI_CYCLE_COUNTER_BLK                                               0
#define JM_AXI_CYCLE_COUNTER_Count                                             1
#define JM_AXI_CYCLE_COUNTER_FieldMask                                0xFFFFFFFF
#define JM_AXI_CYCLE_COUNTER_ReadMask                                 0xFFFFFFFF
#define JM_AXI_CYCLE_COUNTER_WriteMask                                0xC0000000
#define JM_AXI_CYCLE_COUNTER_ResetValue                               0x00000000

#define JM_AXI_CYCLE_COUNTER_COUNT                                          29:0
#define JM_AXI_CYCLE_COUNTER_COUNT_End                                        29
#define JM_AXI_CYCLE_COUNTER_COUNT_Start                                       0
#define JM_AXI_CYCLE_COUNTER_COUNT_Type                                      U30

#define JM_AXI_CYCLE_COUNTER_ENABLE                                        30:30
#define JM_AXI_CYCLE_COUNTER_ENABLE_End                                       30
#define JM_AXI_CYCLE_COUNTER_ENABLE_Start                                     30
#define JM_AXI_CYCLE_COUNTER_ENABLE_Type                                     U01

#define JM_AXI_CYCLE_COUNTER_CLEAR                                         31:31
#define JM_AXI_CYCLE_COUNTER_CLEAR_End                                        31
#define JM_AXI_CYCLE_COUNTER_CLEAR_Start                                      31
#define JM_AXI_CYCLE_COUNTER_CLEAR_Type                                      U01




#define mwv207regMemoryDiagnoseRegAddrs                                   0x0163
#define MWV207REG_MEMORY_DIAGNOSE_Address                                0x0058C
#define MWV207REG_MEMORY_DIAGNOSE_MSB                                         15
#define MWV207REG_MEMORY_DIAGNOSE_LSB                                          0
#define MWV207REG_MEMORY_DIAGNOSE_BLK                                          0
#define MWV207REG_MEMORY_DIAGNOSE_Count                                        1
#define MWV207REG_MEMORY_DIAGNOSE_FieldMask                           0x00000011
#define MWV207REG_MEMORY_DIAGNOSE_ReadMask                            0x00000011
#define MWV207REG_MEMORY_DIAGNOSE_WriteMask                           0x00000011
#define MWV207REG_MEMORY_DIAGNOSE_ResetValue                          0x00000000

#define MWV207REG_MEMORY_DIAGNOSE_REPORT_MODE                                0:0
#define MWV207REG_MEMORY_DIAGNOSE_REPORT_MODE_End                              0
#define MWV207REG_MEMORY_DIAGNOSE_REPORT_MODE_Start                            0
#define MWV207REG_MEMORY_DIAGNOSE_REPORT_MODE_Type                           U01
#define   MWV207REG_MEMORY_DIAGNOSE_REPORT_MODE_NORMAL_DEBUG_MODE            0x0
#define   MWV207REG_MEMORY_DIAGNOSE_REPORT_MODE_REPORT_ASSERTION_EXCEPTION   0x1

#define MWV207REG_MEMORY_DIAGNOSE_EXCEPTION                                  4:4
#define MWV207REG_MEMORY_DIAGNOSE_EXCEPTION_End                                4
#define MWV207REG_MEMORY_DIAGNOSE_EXCEPTION_Start                              4
#define MWV207REG_MEMORY_DIAGNOSE_EXCEPTION_Type                             U01
#define   MWV207REG_MEMORY_DIAGNOSE_EXCEPTION_REPORT_FIFO_FULL_COVERAGE      0x0
#define   MWV207REG_MEMORY_DIAGNOSE_EXCEPTION_REPORT_FIFO_EXCEPTION_ASSERTION 0x1




#define mwv207regTimeStampAddressRegAddrs                                 0x0164
#define MWV207REG_TIME_STAMP_ADDRESS_Address                             0x00590
#define MWV207REG_TIME_STAMP_ADDRESS_MSB                                      15
#define MWV207REG_TIME_STAMP_ADDRESS_LSB                                       0
#define MWV207REG_TIME_STAMP_ADDRESS_BLK                                       0
#define MWV207REG_TIME_STAMP_ADDRESS_Count                                     1
#define MWV207REG_TIME_STAMP_ADDRESS_FieldMask                        0xFFFFFFFF
#define MWV207REG_TIME_STAMP_ADDRESS_ReadMask                         0xFFFFFFFC
#define MWV207REG_TIME_STAMP_ADDRESS_WriteMask                        0xFFFFFFFC
#define MWV207REG_TIME_STAMP_ADDRESS_ResetValue                       0x00000000

#define MWV207REG_TIME_STAMP_ADDRESS_TYPE                                  31:31
#define MWV207REG_TIME_STAMP_ADDRESS_TYPE_End                                 31
#define MWV207REG_TIME_STAMP_ADDRESS_TYPE_Start                               31
#define MWV207REG_TIME_STAMP_ADDRESS_TYPE_Type                               U01
#define   MWV207REG_TIME_STAMP_ADDRESS_TYPE_SYSTEM                           0x0
#define   MWV207REG_TIME_STAMP_ADDRESS_TYPE_VIRTUAL_SYSTEM                   0x1

#define MWV207REG_TIME_STAMP_ADDRESS_ADDRESS                                30:0
#define MWV207REG_TIME_STAMP_ADDRESS_ADDRESS_End                              30
#define MWV207REG_TIME_STAMP_ADDRESS_ADDRESS_Start                             0
#define MWV207REG_TIME_STAMP_ADDRESS_ADDRESS_Type                            U31




#define mwv207regTimeStampTriggerRegAddrs                                 0x0165
#define MWV207REG_TIME_STAMP_TRIGGER_Address                             0x00594
#define MWV207REG_TIME_STAMP_TRIGGER_MSB                                      15
#define MWV207REG_TIME_STAMP_TRIGGER_LSB                                       0
#define MWV207REG_TIME_STAMP_TRIGGER_BLK                                       0
#define MWV207REG_TIME_STAMP_TRIGGER_Count                                     1
#define MWV207REG_TIME_STAMP_TRIGGER_FieldMask                        0x0000FFDF
#define MWV207REG_TIME_STAMP_TRIGGER_ReadMask                         0x0000FFDF
#define MWV207REG_TIME_STAMP_TRIGGER_WriteMask                        0x0000FFDF
#define MWV207REG_TIME_STAMP_TRIGGER_ResetValue                       0x00000000


#define MWV207REG_TIME_STAMP_TRIGGER_MODULE                                  4:0
#define MWV207REG_TIME_STAMP_TRIGGER_MODULE_End                                4
#define MWV207REG_TIME_STAMP_TRIGGER_MODULE_Start                              0
#define MWV207REG_TIME_STAMP_TRIGGER_MODULE_Type                             U05
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_FRONT_END                     0x00
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_VERTEX_SHADER                 0x01
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_TESSELATION_CONTORL_SHADER    0x02
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_TESSELATION_EVALUATION_SHADER 0x03
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_GEOMETRY_SHADER               0x04
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_PRIMITIVE_ASSEMBLY            0x05
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_SETUP                         0x06
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_RASTERIZER                    0x07
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_PIXEL_SHADER                  0x08
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_TEXTURE                       0x09
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_PIXEL_ENGINE                  0x0A
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_BLT_ENGINE                    0x0B
#define   MWV207REG_TIME_STAMP_TRIGGER_MODULE_WORK_DISTRIBUTOR              0x0C


#define MWV207REG_TIME_STAMP_TRIGGER_COMMAND                                 7:6
#define MWV207REG_TIME_STAMP_TRIGGER_COMMAND_End                               7
#define MWV207REG_TIME_STAMP_TRIGGER_COMMAND_Start                             6
#define MWV207REG_TIME_STAMP_TRIGGER_COMMAND_Type                            U02
#define   MWV207REG_TIME_STAMP_TRIGGER_COMMAND_NONE                          0x0
#define   MWV207REG_TIME_STAMP_TRIGGER_COMMAND_CLEAR                         0x1
#define   MWV207REG_TIME_STAMP_TRIGGER_COMMAND_SET                           0x2
#define   MWV207REG_TIME_STAMP_TRIGGER_COMMAND_TIME_STAMP                    0x3


#define MWV207REG_TIME_STAMP_TRIGGER_INDEX                                  15:8
#define MWV207REG_TIME_STAMP_TRIGGER_INDEX_End                                15
#define MWV207REG_TIME_STAMP_TRIGGER_INDEX_Start                               8
#define MWV207REG_TIME_STAMP_TRIGGER_INDEX_Type                              U08




#define jmDebugSignalsPPaRegAddrs                                         0x0166
#define JM_DEBUG_SIGNALS_PPA_Address                                     0x00598
#define JM_DEBUG_SIGNALS_PPA_MSB                                              15
#define JM_DEBUG_SIGNALS_PPA_LSB                                               0
#define JM_DEBUG_SIGNALS_PPA_BLK                                               0
#define JM_DEBUG_SIGNALS_PPA_Count                                             1
#define JM_DEBUG_SIGNALS_PPA_FieldMask                                0xFFFFFFFF
#define JM_DEBUG_SIGNALS_PPA_ReadMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_PPA_WriteMask                                0x00000000
#define JM_DEBUG_SIGNALS_PPA_ResetValue                               0x00000000

#define JM_DEBUG_SIGNALS_PPA_SIGNAL                                         31:0
#define JM_DEBUG_SIGNALS_PPA_SIGNAL_End                                       31
#define JM_DEBUG_SIGNALS_PPA_SIGNAL_Start                                      0
#define JM_DEBUG_SIGNALS_PPA_SIGNAL_Type                                     U32




#define jmDebugSignalsQChannelRegAddrs                                    0x0167
#define JM_DEBUG_SIGNALS_QCHANNEL_Address                                0x0059C
#define JM_DEBUG_SIGNALS_QCHANNEL_MSB                                         15
#define JM_DEBUG_SIGNALS_QCHANNEL_LSB                                          0
#define JM_DEBUG_SIGNALS_QCHANNEL_BLK                                          0
#define JM_DEBUG_SIGNALS_QCHANNEL_Count                                        1
#define JM_DEBUG_SIGNALS_QCHANNEL_FieldMask                           0xFFFFFFFF
#define JM_DEBUG_SIGNALS_QCHANNEL_ReadMask                            0xFFFFFFFF
#define JM_DEBUG_SIGNALS_QCHANNEL_WriteMask                           0x00000000
#define JM_DEBUG_SIGNALS_QCHANNEL_ResetValue                          0x00000000


#define JM_DEBUG_SIGNALS_QCHANNEL_SIGNAL                                    31:0
#define JM_DEBUG_SIGNALS_QCHANNEL_SIGNAL_End                                  31
#define JM_DEBUG_SIGNALS_QCHANNEL_SIGNAL_Start                                 0
#define JM_DEBUG_SIGNALS_QCHANNEL_SIGNAL_Type                                U32




#define jmChipConfigRegAddrs                                              0x0168
#define JM_CHIP_CONFIG_Address                                           0x005A0
#define JM_CHIP_CONFIG_MSB                                                    15
#define JM_CHIP_CONFIG_LSB                                                     0
#define JM_CHIP_CONFIG_BLK                                                     0
#define JM_CHIP_CONFIG_Count                                                   1
#define JM_CHIP_CONFIG_FieldMask                                      0x000000FF
#define JM_CHIP_CONFIG_ReadMask                                       0x000000FF
#define JM_CHIP_CONFIG_WriteMask                                      0x000000FF
#define JM_CHIP_CONFIG_ResetValue                                     0x00000000


#define JM_CHIP_CONFIG_CLUSTER_COUNT                                         7:0
#define JM_CHIP_CONFIG_CLUSTER_COUNT_End                                       7
#define JM_CHIP_CONFIG_CLUSTER_COUNT_Start                                     0
#define JM_CHIP_CONFIG_CLUSTER_COUNT_Type                                    U08




#define mwv207regDramControlRegAddrs                                      0x0169
#define MWV207REG_DRAM_CONTROL_Address                                   0x005A4
#define MWV207REG_DRAM_CONTROL_MSB                                            15
#define MWV207REG_DRAM_CONTROL_LSB                                             0
#define MWV207REG_DRAM_CONTROL_BLK                                             0
#define MWV207REG_DRAM_CONTROL_Count                                           1
#define MWV207REG_DRAM_CONTROL_FieldMask                              0x30003F3F
#define MWV207REG_DRAM_CONTROL_ReadMask                               0x30003F3F
#define MWV207REG_DRAM_CONTROL_WriteMask                              0x30003F3F
#define MWV207REG_DRAM_CONTROL_ResetValue                             0x00000000

#define MWV207REG_DRAM_CONTROL_DRAM_CS_MLSB                                  5:0
#define MWV207REG_DRAM_CONTROL_DRAM_CS_MLSB_End                                5
#define MWV207REG_DRAM_CONTROL_DRAM_CS_MLSB_Start                              0
#define MWV207REG_DRAM_CONTROL_DRAM_CS_MLSB_Type                             U06

#define MWV207REG_DRAM_CONTROL_DRAM_BANK_LSB                                13:8
#define MWV207REG_DRAM_CONTROL_DRAM_BANK_LSB_End                              13
#define MWV207REG_DRAM_CONTROL_DRAM_BANK_LSB_Start                             8
#define MWV207REG_DRAM_CONTROL_DRAM_BANK_LSB_Type                            U06

#define MWV207REG_DRAM_CONTROL_COMPRESSION_GRANULARITY                     29:28
#define MWV207REG_DRAM_CONTROL_COMPRESSION_GRANULARITY_End                    29
#define MWV207REG_DRAM_CONTROL_COMPRESSION_GRANULARITY_Start                  28
#define MWV207REG_DRAM_CONTROL_COMPRESSION_GRANULARITY_Type                  U02
#define   MWV207REG_DRAM_CONTROL_COMPRESSION_GRANULARITY_16B                 0x0
#define   MWV207REG_DRAM_CONTROL_COMPRESSION_GRANULARITY_32B                 0x1
#define   MWV207REG_DRAM_CONTROL_COMPRESSION_GRANULARITY_64B                 0x2



#define AQ_MEMORY_ADDRESS_TYPE                                             31:31
#define AQ_MEMORY_ADDRESS_TYPE_End                                            31
#define AQ_MEMORY_ADDRESS_TYPE_Start                                          31
#define AQ_MEMORY_ADDRESS_TYPE_Type                                          U01
#define   AQ_MEMORY_ADDRESS_TYPE_SYSTEM                                      0x0
#define   AQ_MEMORY_ADDRESS_TYPE_VIRTUAL_SYSTEM                              0x1

#define AQ_MEMORY_ADDRESS_ADDRESS                                           30:0
#define AQ_MEMORY_ADDRESS_ADDRESS_End                                         30
#define AQ_MEMORY_ADDRESS_ADDRESS_Start                                        0
#define AQ_MEMORY_ADDRESS_ADDRESS_Type                                       U31


#define AQ_MEMORY_PAGE_TABLE_ENTRY_ADDRESS                                 31:10
#define AQ_MEMORY_PAGE_TABLE_ENTRY_ADDRESS_End                                31
#define AQ_MEMORY_PAGE_TABLE_ENTRY_ADDRESS_Start                              10
#define AQ_MEMORY_PAGE_TABLE_ENTRY_ADDRESS_Type                              U22

#define AQ_MEMORY_PAGE_TABLE_ENTRY_LINKED                                    8:8
#define AQ_MEMORY_PAGE_TABLE_ENTRY_LINKED_End                                  8
#define AQ_MEMORY_PAGE_TABLE_ENTRY_LINKED_Start                                8
#define AQ_MEMORY_PAGE_TABLE_ENTRY_LINKED_Type                               U01

#define AQ_MEMORY_PAGE_TABLE_ENTRY_REFERENCE_COUNT                           7:0
#define AQ_MEMORY_PAGE_TABLE_ENTRY_REFERENCE_COUNT_End                         7
#define AQ_MEMORY_PAGE_TABLE_ENTRY_REFERENCE_COUNT_Start                       0
#define AQ_MEMORY_PAGE_TABLE_ENTRY_REFERENCE_COUNT_Type                      U08

#define   AQ_MEMORY_TILE_STATUS_REQUEST64                                    0x0
#define   AQ_MEMORY_TILE_STATUS_FAST_CLEAR                                   0x1
#define   AQ_MEMORY_TILE_STATUS_REQUEST32                                    0x2
#define   AQ_MEMORY_TILE_STATUS_REQUEST16                                    0x3
#define   AQ_MEMORY_TILE_STATUS_REQUEST8                                     0x4
#define   AQ_MEMORY_TILE_STATUS_NOCOMPRESS                                   0x0
#define   AQ_MEMORY_TILE_STATUS_FASTCLEAR                                    0x1
#define   AQ_MEMORY_TILE_STATUS_COMPRESS32B                                  0x2
#define   AQ_MEMORY_TILE_STATUS_COMPRESS32BP1X                               0x3
#define   AQ_MEMORY_TILE_STATUS_COMPRESS64B                                  0x4
#define   AQ_MEMORY_TILE_STATUS_NOCOMPRESSP1X                                0x5
#define   AQ_MEMORY_TILE_STATUS_COMPRESS96B                                  0x6
#define   AQ_MEMORY_TILE_STATUS_COMPRESS128B                                 0x8
#define   AQ_MEMORY_TILE_STATUS_COMPRESS160B                                 0xA
#define   AQ_MEMORY_TILE_STATUS_COMPRESS192B                                 0xC
#define   AQ_MEMORY_TILE_STATUS_COMPRESS224B                                 0xE
#define   AQ_MEMORY_TILE_STATUS_FASTCLEARP1X                                 0xF
#define   AQ_MEMORY_TILE_STATUS_FAIL                                         0x0
#define   AQ_MEMORY_TILE_STATUS_CLEAR                                        0x1
#define   AQ_MEMORY_TILE_STATUS_IS32B                                        0x2
#define   AQ_MEMORY_TILE_STATUS_IS64B                                        0x3
#define   AQ_MEMORY_TILE_STATUS_IS96B                                        0x4
#define   AQ_MEMORY_TILE_STATUS_IS128B                                       0x5
#define   AQ_MEMORY_TILE_STATUS_IS160B                                       0x6
#define   AQ_MEMORY_TILE_STATUS_IS192B                                       0x7
#define   AQ_MEMORY_TILE_STATUS_IS224B                                       0x8
#define   AQ_MEMORY_TILE_STATUS_IS32BP1X                                     0xB
#define   AQ_MEMORY_TILE_STATUS_FAILP1X                                      0xE
#define   AQ_MEMORY_TILE_STATUS_CLEARP1X                                     0xF


#endif


