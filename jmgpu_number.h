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




#ifndef __AQPowerManagementReg_h__
#define __AQPowerManagementReg_h__




#define jmModulePowerControlsRegAddrs                                     0x0040
#define JM_MODULE_POWER_CONTROLS_Address                                 0x00100
#define JM_MODULE_POWER_CONTROLS_MSB                                          15
#define JM_MODULE_POWER_CONTROLS_LSB                                           0
#define JM_MODULE_POWER_CONTROLS_BLK                                           0
#define JM_MODULE_POWER_CONTROLS_Count                                         1
#define JM_MODULE_POWER_CONTROLS_FieldMask                            0xFFFF00F7
#define JM_MODULE_POWER_CONTROLS_ReadMask                             0xFFFF00F7
#define JM_MODULE_POWER_CONTROLS_WriteMask                            0xFFFF00F7
#define JM_MODULE_POWER_CONTROLS_ResetValue                           0x00140020


#define JM_MODULE_POWER_CONTROLS_ENABLE_MODULE_CLOCK_GATING                  0:0
#define JM_MODULE_POWER_CONTROLS_ENABLE_MODULE_CLOCK_GATING_End                0
#define JM_MODULE_POWER_CONTROLS_ENABLE_MODULE_CLOCK_GATING_Start              0
#define JM_MODULE_POWER_CONTROLS_ENABLE_MODULE_CLOCK_GATING_Type             U01


#define JM_MODULE_POWER_CONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING           1:1
#define JM_MODULE_POWER_CONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_End         1
#define JM_MODULE_POWER_CONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_Start       1
#define JM_MODULE_POWER_CONTROLS_DISABLE_STALL_MODULE_CLOCK_GATING_Type      U01


#define JM_MODULE_POWER_CONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING          2:2
#define JM_MODULE_POWER_CONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_End        2
#define JM_MODULE_POWER_CONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_Start      2
#define JM_MODULE_POWER_CONTROLS_DISABLE_STARVE_MODULE_CLOCK_GATING_Type     U01


#define JM_MODULE_POWER_CONTROLS_TURN_ON_COUNTER                             7:4
#define JM_MODULE_POWER_CONTROLS_TURN_ON_COUNTER_End                           7
#define JM_MODULE_POWER_CONTROLS_TURN_ON_COUNTER_Start                         4
#define JM_MODULE_POWER_CONTROLS_TURN_ON_COUNTER_Type                        U04

#define JM_MODULE_POWER_CONTROLS_TURN_OFF_COUNTER                          31:16
#define JM_MODULE_POWER_CONTROLS_TURN_OFF_COUNTER_End                         31
#define JM_MODULE_POWER_CONTROLS_TURN_OFF_COUNTER_Start                       16
#define JM_MODULE_POWER_CONTROLS_TURN_OFF_COUNTER_Type                       U16



#define jmModulePowerModuleControlRegAddrs                                0x0041
#define JM_MODULE_POWER_MODULE_CONTROL_Address                           0x00104
#define JM_MODULE_POWER_MODULE_CONTROL_MSB                                    15
#define JM_MODULE_POWER_MODULE_CONTROL_LSB                                     0
#define JM_MODULE_POWER_MODULE_CONTROL_BLK                                     0
#define JM_MODULE_POWER_MODULE_CONTROL_Count                                   1
#define JM_MODULE_POWER_MODULE_CONTROL_FieldMask                      0x00FFFFFF
#define JM_MODULE_POWER_MODULE_CONTROL_ReadMask                       0x00FFFFFF
#define JM_MODULE_POWER_MODULE_CONTROL_WriteMask                      0x00FFFFFF
#define JM_MODULE_POWER_MODULE_CONTROL_ResetValue                     0x00000000


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_FE        0:0
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_FE_End      0
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_FE_Start    0
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_FE_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_DE        1:1
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_DE_End      1
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_DE_Start    1
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_DE_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PE        2:2
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PE_End      2
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PE_Start    2
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PE_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH        3:3
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_End      3
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_Start    3
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PA        4:4
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PA_End      4
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PA_Start    4
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PA_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SE        5:5
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SE_End      5
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SE_Start    5
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SE_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA        6:6
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_End      6
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_Start    6
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TX        7:7
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TX_End      7
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TX_Start    7
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TX_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VG        8:8
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VG_End      8
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VG_Start    8
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VG_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_IM        9:9
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_IM_End      9
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_IM_Start    9
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_IM_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_EU   10:10
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_EU_End  10
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_EU_Start 10
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_EU_Type U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TS      11:11
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TS_End     11
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TS_Start   11
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TS_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_L1_LS   12:12
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_L1_LS_End  12
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_L1_LS_Start 12
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_L1_LS_Type U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RS      13:13
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RS_End     13
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RS_Start   13
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RS_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_MC      14:14
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_MC_End     14
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_MC_Start   14
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_MC_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_IO   15:15
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_IO_End  15
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_IO_Start 15
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_SH_IO_Type U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_EZ   16:16
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_EZ_End  16
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_EZ_Start 16
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_EZ_Type U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_HZ   17:17
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_HZ_End  17
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_HZ_Start 17
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_RA_HZ_Type U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TPG     18:18
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TPG_End    18
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TPG_Start  18
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TPG_Type  U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TFB     19:19
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TFB_End    19
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TFB_Start  19
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_TFB_Type  U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_BLT     20:20
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_BLT_End    20
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_BLT_Start  20
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_BLT_Type  U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VX      21:21
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VX_End     21
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VX_Start   21
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_VX_Type   U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_GPIPE   22:22
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_GPIPE_End  22
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_GPIPE_Start 22
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_GPIPE_Type U01


#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PPA     23:23
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PPA_End    23
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PPA_Start  23
#define JM_MODULE_POWER_MODULE_CONTROL_DISABLE_MODULE_CLOCK_GATING_PPA_Type  U01



#define jmModulePowerModuleStatusRegAddrs                                 0x0042
#define JM_MODULE_POWER_MODULE_STATUS_Address                            0x00108
#define JM_MODULE_POWER_MODULE_STATUS_MSB                                     15
#define JM_MODULE_POWER_MODULE_STATUS_LSB                                      0
#define JM_MODULE_POWER_MODULE_STATUS_BLK                                      0
#define JM_MODULE_POWER_MODULE_STATUS_Count                                    1
#define JM_MODULE_POWER_MODULE_STATUS_FieldMask                       0x00F01BFF
#define JM_MODULE_POWER_MODULE_STATUS_ReadMask                        0x00F01BFF
#define JM_MODULE_POWER_MODULE_STATUS_WriteMask                       0x00000000
#define JM_MODULE_POWER_MODULE_STATUS_ResetValue                      0x00000000


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_FE                  0:0
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_FE_End                0
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_FE_Start              0
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_FE_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_DE                  1:1
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_DE_End                1
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_DE_Start              1
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_DE_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PE                  2:2
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PE_End                2
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PE_Start              2
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PE_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SH                  3:3
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SH_End                3
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SH_Start              3
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SH_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PA                  4:4
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PA_End                4
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PA_Start              4
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PA_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SE                  5:5
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SE_End                5
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SE_Start              5
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_SE_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_RA                  6:6
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_RA_End                6
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_RA_Start              6
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_RA_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TX                  7:7
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TX_End                7
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TX_Start              7
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TX_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VG                  8:8
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VG_End                8
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VG_Start              8
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VG_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_IM                  9:9
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_IM_End                9
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_IM_Start              9
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_IM_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TS                11:11
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TS_End               11
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TS_Start             11
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_TS_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_L1_LS             12:12
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_L1_LS_End            12
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_L1_LS_Start          12
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_L1_LS_Type          U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_BLT               20:20
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_BLT_End              20
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_BLT_Start            20
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_BLT_Type            U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VX                21:21
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VX_End               21
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VX_Start             21
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_VX_Type             U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_GPIPE             22:22
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_GPIPE_End            22
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_GPIPE_Start          22
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_GPIPE_Type          U01


#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PPA               23:23
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PPA_End              23
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PPA_Start            23
#define JM_MODULE_POWER_MODULE_STATUS_MODULE_CLOCK_GATED_PPA_Type            U01




#define jmPulseEaterRegAddrs                                              0x0043
#define JM_PULSE_EATER_Address                                           0x0010C
#define JM_PULSE_EATER_MSB                                                    15
#define JM_PULSE_EATER_LSB                                                     0
#define JM_PULSE_EATER_BLK                                                     0
#define JM_PULSE_EATER_Count                                                   1
#define JM_PULSE_EATER_FieldMask                                      0xFFFFFFFF
#define JM_PULSE_EATER_ReadMask                                       0xFFFFFFFF
#define JM_PULSE_EATER_WriteMask                                      0xFFFFFFFF
#define JM_PULSE_EATER_ResetValue                                     0x015B0880


#define JM_PULSE_EATER_FSCALE_CMD_LOAD_SH                                    0:0
#define JM_PULSE_EATER_FSCALE_CMD_LOAD_SH_End                                  0
#define JM_PULSE_EATER_FSCALE_CMD_LOAD_SH_Start                                0
#define JM_PULSE_EATER_FSCALE_CMD_LOAD_SH_Type                               U01

#define JM_PULSE_EATER_FSCALE_VAL_SH                                         7:1
#define JM_PULSE_EATER_FSCALE_VAL_SH_End                                       7
#define JM_PULSE_EATER_FSCALE_VAL_SH_Start                                     1
#define JM_PULSE_EATER_FSCALE_VAL_SH_Type                                    U07


#define JM_PULSE_EATER_PERIOD                                               15:8
#define JM_PULSE_EATER_PERIOD_End                                             15
#define JM_PULSE_EATER_PERIOD_Start                                            8
#define JM_PULSE_EATER_PERIOD_Type                                           U08

#define JM_PULSE_EATER_ENABLE_AUTO_PULSE_SH                                16:16
#define JM_PULSE_EATER_ENABLE_AUTO_PULSE_SH_End                               16
#define JM_PULSE_EATER_ENABLE_AUTO_PULSE_SH_Start                             16
#define JM_PULSE_EATER_ENABLE_AUTO_PULSE_SH_Type                             U01


#define JM_PULSE_EATER_DISABLE_AUTO_PULSE                                  17:17
#define JM_PULSE_EATER_DISABLE_AUTO_PULSE_End                                 17
#define JM_PULSE_EATER_DISABLE_AUTO_PULSE_Start                               17
#define JM_PULSE_EATER_DISABLE_AUTO_PULSE_Type                               U01

#define JM_PULSE_EATER_EXTERNAL_CONTROL                                    18:18
#define JM_PULSE_EATER_EXTERNAL_CONTROL_End                                   18
#define JM_PULSE_EATER_EXTERNAL_CONTROL_Start                                 18
#define JM_PULSE_EATER_EXTERNAL_CONTROL_Type                                 U01


#define JM_PULSE_EATER_MASK_PE_STALL                                       19:19
#define JM_PULSE_EATER_MASK_PE_STALL_End                                      19
#define JM_PULSE_EATER_MASK_PE_STALL_Start                                    19
#define JM_PULSE_EATER_MASK_PE_STALL_Type                                    U01


#define JM_PULSE_EATER_UPPER_BOUND_ENABLE                                  20:20
#define JM_PULSE_EATER_UPPER_BOUND_ENABLE_End                                 20
#define JM_PULSE_EATER_UPPER_BOUND_ENABLE_Start                               20
#define JM_PULSE_EATER_UPPER_BOUND_ENABLE_Type                               U01


#define JM_PULSE_EATER_ADD_OFFSET                                          21:21
#define JM_PULSE_EATER_ADD_OFFSET_End                                         21
#define JM_PULSE_EATER_ADD_OFFSET_Start                                       21
#define JM_PULSE_EATER_ADD_OFFSET_Type                                       U01


#define JM_PULSE_EATER_ENABLE_FAST_START                                   22:22
#define JM_PULSE_EATER_ENABLE_FAST_START_End                                  22
#define JM_PULSE_EATER_ENABLE_FAST_START_Start                                22
#define JM_PULSE_EATER_ENABLE_FAST_START_Type                                U01


#define JM_PULSE_EATER_ONLY_IDLE                                           23:23
#define JM_PULSE_EATER_ONLY_IDLE_End                                          23
#define JM_PULSE_EATER_ONLY_IDLE_Start                                        23
#define JM_PULSE_EATER_ONLY_IDLE_Type                                        U01


#define JM_PULSE_EATER_MIN_PULSE_COUNT                                     30:24
#define JM_PULSE_EATER_MIN_PULSE_COUNT_End                                    30
#define JM_PULSE_EATER_MIN_PULSE_COUNT_Start                                  24
#define JM_PULSE_EATER_MIN_PULSE_COUNT_Type                                  U07

#define JM_PULSE_EATER_MASK_MC_IDLE                                        31:31
#define JM_PULSE_EATER_MASK_MC_IDLE_End                                       31
#define JM_PULSE_EATER_MASK_MC_IDLE_Start                                     31
#define JM_PULSE_EATER_MASK_MC_IDLE_Type                                     U01




#define jmPulseEaterDebug0RegAddrs                                        0x0044
#define JM_PULSE_EATER_DEBUG0_Address                                    0x00110
#define JM_PULSE_EATER_DEBUG0_MSB                                             15
#define JM_PULSE_EATER_DEBUG0_LSB                                              0
#define JM_PULSE_EATER_DEBUG0_BLK                                              0
#define JM_PULSE_EATER_DEBUG0_Count                                            1
#define JM_PULSE_EATER_DEBUG0_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG0_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG0_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG0_ResetValue                              0x00000000


#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT                               7:0
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_End                             7
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_Start                           0
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_Type                          U08


#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P1                           15:8
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P1_End                         15
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P1_Start                        8
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P1_Type                       U08


#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P2                          23:16
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P2_End                         23
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P2_Start                       16
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P2_Type                       U08


#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P3                          31:24
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P3_End                         31
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P3_Start                       24
#define JM_PULSE_EATER_DEBUG0_CORE_PULSE_COUNT_P3_Type                       U08




#define jmPulseEaterDebug1RegAddrs                                        0x0045
#define JM_PULSE_EATER_DEBUG1_Address                                    0x00114
#define JM_PULSE_EATER_DEBUG1_MSB                                             15
#define JM_PULSE_EATER_DEBUG1_LSB                                              0
#define JM_PULSE_EATER_DEBUG1_BLK                                              0
#define JM_PULSE_EATER_DEBUG1_Count                                            1
#define JM_PULSE_EATER_DEBUG1_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG1_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG1_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG1_ResetValue                              0x00000000


#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT                                 7:0
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_End                               7
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_Start                             0
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_Type                            U08


#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P1                             15:8
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P1_End                           15
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P1_Start                          8
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P1_Type                         U08


#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P2                            23:16
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P2_End                           23
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P2_Start                         16
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P2_Type                         U08


#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P3                            31:24
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P3_End                           31
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P3_Start                         24
#define JM_PULSE_EATER_DEBUG1_SH_PULSE_COUNT_P3_Type                         U08

#define jmPulseEaterDebug2RegAddrs                                        0x0046
#define JM_PULSE_EATER_DEBUG2_Address                                    0x00118
#define JM_PULSE_EATER_DEBUG2_MSB                                             15
#define JM_PULSE_EATER_DEBUG2_LSB                                              0
#define JM_PULSE_EATER_DEBUG2_BLK                                              0
#define JM_PULSE_EATER_DEBUG2_Count                                            1
#define JM_PULSE_EATER_DEBUG2_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG2_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG2_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG2_ResetValue                              0x00000000

#define JM_PULSE_EATER_DEBUG2_IDLE_COUNT_CURRENT                            15:0
#define JM_PULSE_EATER_DEBUG2_IDLE_COUNT_CURRENT_End                          15
#define JM_PULSE_EATER_DEBUG2_IDLE_COUNT_CURRENT_Start                         0
#define JM_PULSE_EATER_DEBUG2_IDLE_COUNT_CURRENT_Type                        U16

#define JM_PULSE_EATER_DEBUG2_PE_STALL_COUNT_CURRENT                       31:16
#define JM_PULSE_EATER_DEBUG2_PE_STALL_COUNT_CURRENT_End                      31
#define JM_PULSE_EATER_DEBUG2_PE_STALL_COUNT_CURRENT_Start                    16
#define JM_PULSE_EATER_DEBUG2_PE_STALL_COUNT_CURRENT_Type                    U16

#define jmPulseEaterDebug3RegAddrs                                        0x0047
#define JM_PULSE_EATER_DEBUG3_Address                                    0x0011C
#define JM_PULSE_EATER_DEBUG3_MSB                                             15
#define JM_PULSE_EATER_DEBUG3_LSB                                              0
#define JM_PULSE_EATER_DEBUG3_BLK                                              0
#define JM_PULSE_EATER_DEBUG3_Count                                            1
#define JM_PULSE_EATER_DEBUG3_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG3_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG3_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG3_ResetValue                              0x00000000

#define JM_PULSE_EATER_DEBUG3_IDLE_COUNT_P1                                 15:0
#define JM_PULSE_EATER_DEBUG3_IDLE_COUNT_P1_End                               15
#define JM_PULSE_EATER_DEBUG3_IDLE_COUNT_P1_Start                              0
#define JM_PULSE_EATER_DEBUG3_IDLE_COUNT_P1_Type                             U16

#define JM_PULSE_EATER_DEBUG3_PE_STALL_COUNT_P1                            31:16
#define JM_PULSE_EATER_DEBUG3_PE_STALL_COUNT_P1_End                           31
#define JM_PULSE_EATER_DEBUG3_PE_STALL_COUNT_P1_Start                         16
#define JM_PULSE_EATER_DEBUG3_PE_STALL_COUNT_P1_Type                         U16

#define jmPulseEaterDebug4RegAddrs                                        0x0048
#define JM_PULSE_EATER_DEBUG4_Address                                    0x00120
#define JM_PULSE_EATER_DEBUG4_MSB                                             15
#define JM_PULSE_EATER_DEBUG4_LSB                                              0
#define JM_PULSE_EATER_DEBUG4_BLK                                              0
#define JM_PULSE_EATER_DEBUG4_Count                                            1
#define JM_PULSE_EATER_DEBUG4_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG4_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG4_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG4_ResetValue                              0x00000000

#define JM_PULSE_EATER_DEBUG4_IDLE_COUNT_P2                                 15:0
#define JM_PULSE_EATER_DEBUG4_IDLE_COUNT_P2_End                               15
#define JM_PULSE_EATER_DEBUG4_IDLE_COUNT_P2_Start                              0
#define JM_PULSE_EATER_DEBUG4_IDLE_COUNT_P2_Type                             U16

#define JM_PULSE_EATER_DEBUG4_PE_STALL_COUNT_P2                            31:16
#define JM_PULSE_EATER_DEBUG4_PE_STALL_COUNT_P2_End                           31
#define JM_PULSE_EATER_DEBUG4_PE_STALL_COUNT_P2_Start                         16
#define JM_PULSE_EATER_DEBUG4_PE_STALL_COUNT_P2_Type                         U16

#define jmPulseEaterDebug5RegAddrs                                        0x0049
#define JM_PULSE_EATER_DEBUG5_Address                                    0x00124
#define JM_PULSE_EATER_DEBUG5_MSB                                             15
#define JM_PULSE_EATER_DEBUG5_LSB                                              0
#define JM_PULSE_EATER_DEBUG5_BLK                                              0
#define JM_PULSE_EATER_DEBUG5_Count                                            1
#define JM_PULSE_EATER_DEBUG5_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG5_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG5_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG5_ResetValue                              0x00000000

#define JM_PULSE_EATER_DEBUG5_SH_ACTIVE_COUNT_CURRENT                       15:0
#define JM_PULSE_EATER_DEBUG5_SH_ACTIVE_COUNT_CURRENT_End                     15
#define JM_PULSE_EATER_DEBUG5_SH_ACTIVE_COUNT_CURRENT_Start                    0
#define JM_PULSE_EATER_DEBUG5_SH_ACTIVE_COUNT_CURRENT_Type                   U16

#define JM_PULSE_EATER_DEBUG5_VS_STALL_COUNT_CURRENT                       31:16
#define JM_PULSE_EATER_DEBUG5_VS_STALL_COUNT_CURRENT_End                      31
#define JM_PULSE_EATER_DEBUG5_VS_STALL_COUNT_CURRENT_Start                    16
#define JM_PULSE_EATER_DEBUG5_VS_STALL_COUNT_CURRENT_Type                    U16

#define jmPulseEaterDebug6RegAddrs                                        0x004A
#define JM_PULSE_EATER_DEBUG6_Address                                    0x00128
#define JM_PULSE_EATER_DEBUG6_MSB                                             15
#define JM_PULSE_EATER_DEBUG6_LSB                                              0
#define JM_PULSE_EATER_DEBUG6_BLK                                              0
#define JM_PULSE_EATER_DEBUG6_Count                                            1
#define JM_PULSE_EATER_DEBUG6_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG6_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG6_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG6_ResetValue                              0x00000000

#define JM_PULSE_EATER_DEBUG6_SH_ACTIVE_COUNT_P1                            15:0
#define JM_PULSE_EATER_DEBUG6_SH_ACTIVE_COUNT_P1_End                          15
#define JM_PULSE_EATER_DEBUG6_SH_ACTIVE_COUNT_P1_Start                         0
#define JM_PULSE_EATER_DEBUG6_SH_ACTIVE_COUNT_P1_Type                        U16

#define JM_PULSE_EATER_DEBUG6_VS_STALL_COUNT_P1                            31:16
#define JM_PULSE_EATER_DEBUG6_VS_STALL_COUNT_P1_End                           31
#define JM_PULSE_EATER_DEBUG6_VS_STALL_COUNT_P1_Start                         16
#define JM_PULSE_EATER_DEBUG6_VS_STALL_COUNT_P1_Type                         U16

#define jmPulseEaterDebug7RegAddrs                                        0x004B
#define JM_PULSE_EATER_DEBUG7_Address                                    0x0012C
#define JM_PULSE_EATER_DEBUG7_MSB                                             15
#define JM_PULSE_EATER_DEBUG7_LSB                                              0
#define JM_PULSE_EATER_DEBUG7_BLK                                              0
#define JM_PULSE_EATER_DEBUG7_Count                                            1
#define JM_PULSE_EATER_DEBUG7_FieldMask                               0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG7_ReadMask                                0xFFFFFFFF
#define JM_PULSE_EATER_DEBUG7_WriteMask                               0x00000000
#define JM_PULSE_EATER_DEBUG7_ResetValue                              0x00000000

#define JM_PULSE_EATER_DEBUG7_SH_ACTIVE_COUNT_P2                            15:0
#define JM_PULSE_EATER_DEBUG7_SH_ACTIVE_COUNT_P2_End                          15
#define JM_PULSE_EATER_DEBUG7_SH_ACTIVE_COUNT_P2_Start                         0
#define JM_PULSE_EATER_DEBUG7_SH_ACTIVE_COUNT_P2_Type                        U16

#define JM_PULSE_EATER_DEBUG7_VS_STALL_COUNT_P2                            31:16
#define JM_PULSE_EATER_DEBUG7_VS_STALL_COUNT_P2_End                           31
#define JM_PULSE_EATER_DEBUG7_VS_STALL_COUNT_P2_Start                         16
#define JM_PULSE_EATER_DEBUG7_VS_STALL_COUNT_P2_Type                         U16




#define jmPulseEater1RegAddrs                                             0x004C
#define JM_PULSE_EATER1_Address                                          0x00130
#define JM_PULSE_EATER1_MSB                                                   15
#define JM_PULSE_EATER1_LSB                                                    0
#define JM_PULSE_EATER1_BLK                                                    0
#define JM_PULSE_EATER1_Count                                                  1
#define JM_PULSE_EATER1_FieldMask                                     0xFFFFC003
#define JM_PULSE_EATER1_ReadMask                                      0xFFFFC003
#define JM_PULSE_EATER1_WriteMask                                     0xFFFFC003
#define JM_PULSE_EATER1_ResetValue                                    0x00800000


#define JM_PULSE_EATER1_FAST_START_DURATION                                  0:0
#define JM_PULSE_EATER1_FAST_START_DURATION_End                                0
#define JM_PULSE_EATER1_FAST_START_DURATION_Start                              0
#define JM_PULSE_EATER1_FAST_START_DURATION_Type                             U01
#define   JM_PULSE_EATER1_FAST_START_DURATION_COUNT128                       0x0
#define   JM_PULSE_EATER1_FAST_START_DURATION_COUNT1024                      0x1


#define JM_PULSE_EATER1_SH_RESOURCE_CHECK_CONTROL                            1:1
#define JM_PULSE_EATER1_SH_RESOURCE_CHECK_CONTROL_End                          1
#define JM_PULSE_EATER1_SH_RESOURCE_CHECK_CONTROL_Start                        1
#define JM_PULSE_EATER1_SH_RESOURCE_CHECK_CONTROL_Type                       U01
#define   JM_PULSE_EATER1_SH_RESOURCE_CHECK_CONTROL_AUTO                     0x0
#define   JM_PULSE_EATER1_SH_RESOURCE_CHECK_CONTROL_FORCE_RESOURCE_CHECK     0x1


#define JM_PULSE_EATER1_DISABLE_AUTO_PULSE_PER_FRAME                       14:14
#define JM_PULSE_EATER1_DISABLE_AUTO_PULSE_PER_FRAME_End                      14
#define JM_PULSE_EATER1_DISABLE_AUTO_PULSE_PER_FRAME_Start                    14
#define JM_PULSE_EATER1_DISABLE_AUTO_PULSE_PER_FRAME_Type                    U01


#define JM_PULSE_EATER1_DISABLE_AVERAGE_HISTORY                            15:15
#define JM_PULSE_EATER1_DISABLE_AVERAGE_HISTORY_End                           15
#define JM_PULSE_EATER1_DISABLE_AVERAGE_HISTORY_Start                         15
#define JM_PULSE_EATER1_DISABLE_AVERAGE_HISTORY_Type                         U01


#define JM_PULSE_EATER1_PERIOD_PER_FRAME                                   31:16
#define JM_PULSE_EATER1_PERIOD_PER_FRAME_End                                  31
#define JM_PULSE_EATER1_PERIOD_PER_FRAME_Start                                16
#define JM_PULSE_EATER1_PERIOD_PER_FRAME_Type                                U16

#define jmPulseEater1Debug0RegAddrs                                       0x004D
#define JM_PULSE_EATER1_DEBUG0_Address                                   0x00134
#define JM_PULSE_EATER1_DEBUG0_MSB                                            15
#define JM_PULSE_EATER1_DEBUG0_LSB                                             0
#define JM_PULSE_EATER1_DEBUG0_BLK                                             0
#define JM_PULSE_EATER1_DEBUG0_Count                                           1
#define JM_PULSE_EATER1_DEBUG0_FieldMask                              0xFFFFFFFF
#define JM_PULSE_EATER1_DEBUG0_ReadMask                               0xFFFFFFFF
#define JM_PULSE_EATER1_DEBUG0_WriteMask                              0x00000000
#define JM_PULSE_EATER1_DEBUG0_ResetValue                             0x00000000


#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT                              7:0
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_End                            7
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_Start                          0
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_Type                         U08


#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P1                          15:8
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P1_End                        15
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P1_Start                       8
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P1_Type                      U08


#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P2                         23:16
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P2_End                        23
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P2_Start                      16
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P2_Type                      U08


#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P3                         31:24
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P3_End                        31
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P3_Start                      24
#define JM_PULSE_EATER1_DEBUG0_CORE_PULSE_COUNT_P3_Type                      U08

#define jmPulseEater1Debug1RegAddrs                                       0x004E
#define JM_PULSE_EATER1_DEBUG1_Address                                   0x00138
#define JM_PULSE_EATER1_DEBUG1_MSB                                            15
#define JM_PULSE_EATER1_DEBUG1_LSB                                             0
#define JM_PULSE_EATER1_DEBUG1_BLK                                             0
#define JM_PULSE_EATER1_DEBUG1_Count                                           1
#define JM_PULSE_EATER1_DEBUG1_FieldMask                              0xFFFFFFFF
#define JM_PULSE_EATER1_DEBUG1_ReadMask                               0xFFFFFFFF
#define JM_PULSE_EATER1_DEBUG1_WriteMask                              0x00000000
#define JM_PULSE_EATER1_DEBUG1_ResetValue                             0x00000000


#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P4                           7:0
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P4_End                         7
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P4_Start                       0
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P4_Type                      U08


#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P5                          15:8
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P5_End                        15
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P5_Start                       8
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P5_Type                      U08


#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P6                         23:16
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P6_End                        23
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P6_Start                      16
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P6_Type                      U08


#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P7                         31:24
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P7_End                        31
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P7_Start                      24
#define JM_PULSE_EATER1_DEBUG1_CORE_PULSE_COUNT_P7_Type                      U08

#define jmPeakPowerMultipliers0RegAddrs                                   0x004F
#define JM_PEAK_POWER_MULTIPLIERS0_Address                               0x0013C
#define JM_PEAK_POWER_MULTIPLIERS0_MSB                                        15
#define JM_PEAK_POWER_MULTIPLIERS0_LSB                                         0
#define JM_PEAK_POWER_MULTIPLIERS0_BLK                                         0
#define JM_PEAK_POWER_MULTIPLIERS0_Count                                       1
#define JM_PEAK_POWER_MULTIPLIERS0_FieldMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS0_ReadMask                           0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS0_WriteMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS0_ResetValue                         0x00001010

#define JM_PEAK_POWER_MULTIPLIERS0_PE0                                       7:0
#define JM_PEAK_POWER_MULTIPLIERS0_PE0_End                                     7
#define JM_PEAK_POWER_MULTIPLIERS0_PE0_Start                                   0
#define JM_PEAK_POWER_MULTIPLIERS0_PE0_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS0_PE1                                      15:8
#define JM_PEAK_POWER_MULTIPLIERS0_PE1_End                                    15
#define JM_PEAK_POWER_MULTIPLIERS0_PE1_Start                                   8
#define JM_PEAK_POWER_MULTIPLIERS0_PE1_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS0_PE2                                     23:16
#define JM_PEAK_POWER_MULTIPLIERS0_PE2_End                                    23
#define JM_PEAK_POWER_MULTIPLIERS0_PE2_Start                                  16
#define JM_PEAK_POWER_MULTIPLIERS0_PE2_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS0_PE3                                     31:24
#define JM_PEAK_POWER_MULTIPLIERS0_PE3_End                                    31
#define JM_PEAK_POWER_MULTIPLIERS0_PE3_Start                                  24
#define JM_PEAK_POWER_MULTIPLIERS0_PE3_Type                                  U08

#define jmPeakPowerMultipliers1RegAddrs                                   0x0050
#define JM_PEAK_POWER_MULTIPLIERS1_Address                               0x00140
#define JM_PEAK_POWER_MULTIPLIERS1_MSB                                        15
#define JM_PEAK_POWER_MULTIPLIERS1_LSB                                         0
#define JM_PEAK_POWER_MULTIPLIERS1_BLK                                         0
#define JM_PEAK_POWER_MULTIPLIERS1_Count                                       1
#define JM_PEAK_POWER_MULTIPLIERS1_FieldMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS1_ReadMask                           0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS1_WriteMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS1_ResetValue                         0x20082020

#define JM_PEAK_POWER_MULTIPLIERS1_TX0                                       7:0
#define JM_PEAK_POWER_MULTIPLIERS1_TX0_End                                     7
#define JM_PEAK_POWER_MULTIPLIERS1_TX0_Start                                   0
#define JM_PEAK_POWER_MULTIPLIERS1_TX0_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS1_TX1                                      15:8
#define JM_PEAK_POWER_MULTIPLIERS1_TX1_End                                    15
#define JM_PEAK_POWER_MULTIPLIERS1_TX1_Start                                   8
#define JM_PEAK_POWER_MULTIPLIERS1_TX1_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS1_TX2                                     23:16
#define JM_PEAK_POWER_MULTIPLIERS1_TX2_End                                    23
#define JM_PEAK_POWER_MULTIPLIERS1_TX2_Start                                  16
#define JM_PEAK_POWER_MULTIPLIERS1_TX2_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS1_TX3                                     31:24
#define JM_PEAK_POWER_MULTIPLIERS1_TX3_End                                    31
#define JM_PEAK_POWER_MULTIPLIERS1_TX3_Start                                  24
#define JM_PEAK_POWER_MULTIPLIERS1_TX3_Type                                  U08

#define jmPeakPowerMultipliers2RegAddrs                                   0x0051
#define JM_PEAK_POWER_MULTIPLIERS2_Address                               0x00144
#define JM_PEAK_POWER_MULTIPLIERS2_MSB                                        15
#define JM_PEAK_POWER_MULTIPLIERS2_LSB                                         0
#define JM_PEAK_POWER_MULTIPLIERS2_BLK                                         0
#define JM_PEAK_POWER_MULTIPLIERS2_Count                                       1
#define JM_PEAK_POWER_MULTIPLIERS2_FieldMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS2_ReadMask                           0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS2_WriteMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS2_ResetValue                         0x00000420

#define JM_PEAK_POWER_MULTIPLIERS2_RA0                                       7:0
#define JM_PEAK_POWER_MULTIPLIERS2_RA0_End                                     7
#define JM_PEAK_POWER_MULTIPLIERS2_RA0_Start                                   0
#define JM_PEAK_POWER_MULTIPLIERS2_RA0_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS2_RA1                                      15:8
#define JM_PEAK_POWER_MULTIPLIERS2_RA1_End                                    15
#define JM_PEAK_POWER_MULTIPLIERS2_RA1_Start                                   8
#define JM_PEAK_POWER_MULTIPLIERS2_RA1_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS2_RA2                                     23:16
#define JM_PEAK_POWER_MULTIPLIERS2_RA2_End                                    23
#define JM_PEAK_POWER_MULTIPLIERS2_RA2_Start                                  16
#define JM_PEAK_POWER_MULTIPLIERS2_RA2_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS2_RA3                                     31:24
#define JM_PEAK_POWER_MULTIPLIERS2_RA3_End                                    31
#define JM_PEAK_POWER_MULTIPLIERS2_RA3_Start                                  24
#define JM_PEAK_POWER_MULTIPLIERS2_RA3_Type                                  U08

#define jmPeakPowerMultipliers3RegAddrs                                   0x0052
#define JM_PEAK_POWER_MULTIPLIERS3_Address                               0x00148
#define JM_PEAK_POWER_MULTIPLIERS3_MSB                                        15
#define JM_PEAK_POWER_MULTIPLIERS3_LSB                                         0
#define JM_PEAK_POWER_MULTIPLIERS3_BLK                                         0
#define JM_PEAK_POWER_MULTIPLIERS3_Count                                       1
#define JM_PEAK_POWER_MULTIPLIERS3_FieldMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS3_ReadMask                           0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS3_WriteMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS3_ResetValue                         0x20101060

#define JM_PEAK_POWER_MULTIPLIERS3_SH0                                       7:0
#define JM_PEAK_POWER_MULTIPLIERS3_SH0_End                                     7
#define JM_PEAK_POWER_MULTIPLIERS3_SH0_Start                                   0
#define JM_PEAK_POWER_MULTIPLIERS3_SH0_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS3_SH1                                      15:8
#define JM_PEAK_POWER_MULTIPLIERS3_SH1_End                                    15
#define JM_PEAK_POWER_MULTIPLIERS3_SH1_Start                                   8
#define JM_PEAK_POWER_MULTIPLIERS3_SH1_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS3_SH2                                     23:16
#define JM_PEAK_POWER_MULTIPLIERS3_SH2_End                                    23
#define JM_PEAK_POWER_MULTIPLIERS3_SH2_Start                                  16
#define JM_PEAK_POWER_MULTIPLIERS3_SH2_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS3_SH3                                     31:24
#define JM_PEAK_POWER_MULTIPLIERS3_SH3_End                                    31
#define JM_PEAK_POWER_MULTIPLIERS3_SH3_Start                                  24
#define JM_PEAK_POWER_MULTIPLIERS3_SH3_Type                                  U08

#define jmPeakPowerMultipliers4RegAddrs                                   0x0053
#define JM_PEAK_POWER_MULTIPLIERS4_Address                               0x0014C
#define JM_PEAK_POWER_MULTIPLIERS4_MSB                                        15
#define JM_PEAK_POWER_MULTIPLIERS4_LSB                                         0
#define JM_PEAK_POWER_MULTIPLIERS4_BLK                                         0
#define JM_PEAK_POWER_MULTIPLIERS4_Count                                       1
#define JM_PEAK_POWER_MULTIPLIERS4_FieldMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS4_ReadMask                           0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS4_WriteMask                          0xFFFFFFFF
#define JM_PEAK_POWER_MULTIPLIERS4_ResetValue                         0x00000020

#define JM_PEAK_POWER_MULTIPLIERS4_SH4                                       7:0
#define JM_PEAK_POWER_MULTIPLIERS4_SH4_End                                     7
#define JM_PEAK_POWER_MULTIPLIERS4_SH4_Start                                   0
#define JM_PEAK_POWER_MULTIPLIERS4_SH4_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS4_SH5                                      15:8
#define JM_PEAK_POWER_MULTIPLIERS4_SH5_End                                    15
#define JM_PEAK_POWER_MULTIPLIERS4_SH5_Start                                   8
#define JM_PEAK_POWER_MULTIPLIERS4_SH5_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS4_SH6                                     23:16
#define JM_PEAK_POWER_MULTIPLIERS4_SH6_End                                    23
#define JM_PEAK_POWER_MULTIPLIERS4_SH6_Start                                  16
#define JM_PEAK_POWER_MULTIPLIERS4_SH6_Type                                  U08

#define JM_PEAK_POWER_MULTIPLIERS4_SH7                                     31:24
#define JM_PEAK_POWER_MULTIPLIERS4_SH7_End                                    31
#define JM_PEAK_POWER_MULTIPLIERS4_SH7_Start                                  24
#define JM_PEAK_POWER_MULTIPLIERS4_SH7_Type                                  U08

#define jmPeakPowerControlRegAddrs                                        0x0054
#define JM_PEAK_POWER_CONTROL_Address                                    0x00150
#define JM_PEAK_POWER_CONTROL_MSB                                             15
#define JM_PEAK_POWER_CONTROL_LSB                                              0
#define JM_PEAK_POWER_CONTROL_BLK                                              0
#define JM_PEAK_POWER_CONTROL_Count                                            1
#define JM_PEAK_POWER_CONTROL_FieldMask                               0x0FFF07FF
#define JM_PEAK_POWER_CONTROL_ReadMask                                0x0FFF07FF
#define JM_PEAK_POWER_CONTROL_WriteMask                               0x0FFF07FF
#define JM_PEAK_POWER_CONTROL_ResetValue                              0x02580280

#define JM_PEAK_POWER_CONTROL_PERIOD                                         3:0
#define JM_PEAK_POWER_CONTROL_PERIOD_End                                       3
#define JM_PEAK_POWER_CONTROL_PERIOD_Start                                     0
#define JM_PEAK_POWER_CONTROL_PERIOD_Type                                    U04


#define JM_PEAK_POWER_CONTROL_PEAK_PULSE_COUNT                              10:4
#define JM_PEAK_POWER_CONTROL_PEAK_PULSE_COUNT_End                            10
#define JM_PEAK_POWER_CONTROL_PEAK_PULSE_COUNT_Start                           4
#define JM_PEAK_POWER_CONTROL_PEAK_PULSE_COUNT_Type                          U07

#define JM_PEAK_POWER_CONTROL_PEAK_VALUE                                   27:16
#define JM_PEAK_POWER_CONTROL_PEAK_VALUE_End                                  27
#define JM_PEAK_POWER_CONTROL_PEAK_VALUE_Start                                16
#define JM_PEAK_POWER_CONTROL_PEAK_VALUE_Type                                U12

#define mwv207regAHBPowerControl0RegAddrs                                 0x0055
#define MWV207REG_AHB_POWER_CONTROL0_Address                             0x00154
#define MWV207REG_AHB_POWER_CONTROL0_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL0_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL0_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL0_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL0_FieldMask                        0x0FFF1FFF
#define MWV207REG_AHB_POWER_CONTROL0_ReadMask                         0x0FFF1FFF
#define MWV207REG_AHB_POWER_CONTROL0_WriteMask                        0x0FFF1FFF
#define MWV207REG_AHB_POWER_CONTROL0_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSI       3:0
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSI_End     3
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSI_Start   0
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSI_Type  U04


#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSO       9:4
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSO_End     9
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSO_Start   4
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHPSO_Type  U06


#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHTXIO    12:10
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHTXIO_End   12
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHTXIO_Start 10
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHTXIO_Type U03


#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHGPIPEIO 27:16
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHGPIPEIO_End 27
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHGPIPEIO_Start 16
#define MWV207REG_AHB_POWER_CONTROL0_DISABLE_MODULE_CLOCK_GATING_SHGPIPEIO_Type U12

#define mwv207regAHBPowerControl1RegAddrs                                 0x0056
#define MWV207REG_AHB_POWER_CONTROL1_Address                             0x00158
#define MWV207REG_AHB_POWER_CONTROL1_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL1_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL1_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL1_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL1_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL1_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL1_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL1_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHVPF       0:0
#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHVPF_End     0
#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHVPF_Start   0
#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHVPF_Type  U01


#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHATTR      1:1
#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHATTR_End    1
#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHATTR_Start  1
#define MWV207REG_AHB_POWER_CONTROL1_DISABLE_MODULE_CLOCK_GATING_SHATTR_Type U01


#define MWV207REG_AHB_POWER_CONTROL1_PERIOD                                 31:2
#define MWV207REG_AHB_POWER_CONTROL1_PERIOD_End                               31
#define MWV207REG_AHB_POWER_CONTROL1_PERIOD_Start                              2
#define MWV207REG_AHB_POWER_CONTROL1_PERIOD_Type                             U30

#define mwv207regAHBPowerControl2RegAddrs                                 0x0057
#define MWV207REG_AHB_POWER_CONTROL2_Address                             0x0015C
#define MWV207REG_AHB_POWER_CONTROL2_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL2_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL2_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL2_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL2_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL2_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL2_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL2_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL2_PERIOD                                 31:0
#define MWV207REG_AHB_POWER_CONTROL2_PERIOD_End                               31
#define MWV207REG_AHB_POWER_CONTROL2_PERIOD_Start                              0
#define MWV207REG_AHB_POWER_CONTROL2_PERIOD_Type                             U32

#define mwv207regAHBPowerControl3RegAddrs                                 0x0058
#define MWV207REG_AHB_POWER_CONTROL3_Address                             0x00160
#define MWV207REG_AHB_POWER_CONTROL3_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL3_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL3_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL3_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL3_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL3_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL3_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL3_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL3_PERIOD                                 31:0
#define MWV207REG_AHB_POWER_CONTROL3_PERIOD_End                               31
#define MWV207REG_AHB_POWER_CONTROL3_PERIOD_Start                              0
#define MWV207REG_AHB_POWER_CONTROL3_PERIOD_Type                             U32

#define mwv207regAHBPowerControl4RegAddrs                                 0x0059
#define MWV207REG_AHB_POWER_CONTROL4_Address                             0x00164
#define MWV207REG_AHB_POWER_CONTROL4_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL4_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL4_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL4_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL4_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL4_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL4_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL4_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL4_PERIOD0                                23:0
#define MWV207REG_AHB_POWER_CONTROL4_PERIOD0_End                              23
#define MWV207REG_AHB_POWER_CONTROL4_PERIOD0_Start                             0
#define MWV207REG_AHB_POWER_CONTROL4_PERIOD0_Type                            U24


#define MWV207REG_AHB_POWER_CONTROL4_PERIOD1                               31:24
#define MWV207REG_AHB_POWER_CONTROL4_PERIOD1_End                              31
#define MWV207REG_AHB_POWER_CONTROL4_PERIOD1_Start                            24
#define MWV207REG_AHB_POWER_CONTROL4_PERIOD1_Type                            U08

#define mwv207regAHBPowerControl5RegAddrs                                 0x005A
#define MWV207REG_AHB_POWER_CONTROL5_Address                             0x00168
#define MWV207REG_AHB_POWER_CONTROL5_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL5_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL5_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL5_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL5_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL5_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL5_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL5_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL5_PERIOD0                                15:0
#define MWV207REG_AHB_POWER_CONTROL5_PERIOD0_End                              15
#define MWV207REG_AHB_POWER_CONTROL5_PERIOD0_Start                             0
#define MWV207REG_AHB_POWER_CONTROL5_PERIOD0_Type                            U16


#define MWV207REG_AHB_POWER_CONTROL5_PERIOD1                               31:16
#define MWV207REG_AHB_POWER_CONTROL5_PERIOD1_End                              31
#define MWV207REG_AHB_POWER_CONTROL5_PERIOD1_Start                            16
#define MWV207REG_AHB_POWER_CONTROL5_PERIOD1_Type                            U16

#define mwv207regAHBPowerControl6RegAddrs                                 0x005B
#define MWV207REG_AHB_POWER_CONTROL6_Address                             0x0016C
#define MWV207REG_AHB_POWER_CONTROL6_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL6_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL6_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL6_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL6_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL6_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL6_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL6_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL6_PERIOD0                                 7:0
#define MWV207REG_AHB_POWER_CONTROL6_PERIOD0_End                               7
#define MWV207REG_AHB_POWER_CONTROL6_PERIOD0_Start                             0
#define MWV207REG_AHB_POWER_CONTROL6_PERIOD0_Type                            U08


#define MWV207REG_AHB_POWER_CONTROL6_PERIOD1                                31:8
#define MWV207REG_AHB_POWER_CONTROL6_PERIOD1_End                              31
#define MWV207REG_AHB_POWER_CONTROL6_PERIOD1_Start                             8
#define MWV207REG_AHB_POWER_CONTROL6_PERIOD1_Type                            U24

#define mwv207regAHBPowerControl7RegAddrs                                 0x005C
#define MWV207REG_AHB_POWER_CONTROL7_Address                             0x00170
#define MWV207REG_AHB_POWER_CONTROL7_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL7_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL7_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL7_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL7_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL7_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL7_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL7_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL7_PERIOD0                                15:0
#define MWV207REG_AHB_POWER_CONTROL7_PERIOD0_End                              15
#define MWV207REG_AHB_POWER_CONTROL7_PERIOD0_Start                             0
#define MWV207REG_AHB_POWER_CONTROL7_PERIOD0_Type                            U16


#define MWV207REG_AHB_POWER_CONTROL7_PERIOD1                               23:16
#define MWV207REG_AHB_POWER_CONTROL7_PERIOD1_End                              23
#define MWV207REG_AHB_POWER_CONTROL7_PERIOD1_Start                            16
#define MWV207REG_AHB_POWER_CONTROL7_PERIOD1_Type                            U08


#define MWV207REG_AHB_POWER_CONTROL7_DISABLE_MODULE_CLOCK_GATING_SHFU      31:24
#define MWV207REG_AHB_POWER_CONTROL7_DISABLE_MODULE_CLOCK_GATING_SHFU_End     31
#define MWV207REG_AHB_POWER_CONTROL7_DISABLE_MODULE_CLOCK_GATING_SHFU_Start   24
#define MWV207REG_AHB_POWER_CONTROL7_DISABLE_MODULE_CLOCK_GATING_SHFU_Type   U08

#define mwv207regAHBPowerControl8RegAddrs                                 0x005D
#define MWV207REG_AHB_POWER_CONTROL8_Address                             0x00174
#define MWV207REG_AHB_POWER_CONTROL8_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL8_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL8_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL8_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL8_FieldMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL8_ReadMask                         0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL8_WriteMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL8_ResetValue                       0x00000000


#define MWV207REG_AHB_POWER_CONTROL8_PERIOD                                 31:0
#define MWV207REG_AHB_POWER_CONTROL8_PERIOD_End                               31
#define MWV207REG_AHB_POWER_CONTROL8_PERIOD_Start                              0
#define MWV207REG_AHB_POWER_CONTROL8_PERIOD_Type                             U32

#define mwv207regAHBPowerControl9RegAddrs                                 0x005E
#define MWV207REG_AHB_POWER_CONTROL9_Address                             0x00178
#define MWV207REG_AHB_POWER_CONTROL9_MSB                                      15
#define MWV207REG_AHB_POWER_CONTROL9_LSB                                       0
#define MWV207REG_AHB_POWER_CONTROL9_BLK                                       0
#define MWV207REG_AHB_POWER_CONTROL9_Count                                     1
#define MWV207REG_AHB_POWER_CONTROL9_FieldMask                        0x0000FFFF
#define MWV207REG_AHB_POWER_CONTROL9_ReadMask                         0x0000FFFF
#define MWV207REG_AHB_POWER_CONTROL9_WriteMask                        0x0000FFFF
#define MWV207REG_AHB_POWER_CONTROL9_ResetValue                       0x00000000

#define MWV207REG_AHB_POWER_CONTROL9_DISABLE_CLOCK_GATING_CNN               15:0
#define MWV207REG_AHB_POWER_CONTROL9_DISABLE_CLOCK_GATING_CNN_End             15
#define MWV207REG_AHB_POWER_CONTROL9_DISABLE_CLOCK_GATING_CNN_Start            0
#define MWV207REG_AHB_POWER_CONTROL9_DISABLE_CLOCK_GATING_CNN_Type           U16

#define mwv207regAHBPowerControl10RegAddrs                                0x005F
#define MWV207REG_AHB_POWER_CONTROL10_Address                            0x0017C
#define MWV207REG_AHB_POWER_CONTROL10_MSB                                     15
#define MWV207REG_AHB_POWER_CONTROL10_LSB                                      0
#define MWV207REG_AHB_POWER_CONTROL10_BLK                                      0
#define MWV207REG_AHB_POWER_CONTROL10_Count                                    1
#define MWV207REG_AHB_POWER_CONTROL10_FieldMask                       0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL10_ReadMask                        0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL10_WriteMask                       0xFFFFFFFF
#define MWV207REG_AHB_POWER_CONTROL10_ResetValue                      0x00000000


#define MWV207REG_AHB_POWER_CONTROL10_PERIOD                                31:0
#define MWV207REG_AHB_POWER_CONTROL10_PERIOD_End                              31
#define MWV207REG_AHB_POWER_CONTROL10_PERIOD_Start                             0
#define MWV207REG_AHB_POWER_CONTROL10_PERIOD_Type                            U32


#endif


