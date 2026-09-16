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




#ifndef __jmgpuregDisplay_h__
#define __jmgpuregDisplay_h__





#define mwv207regFrameBufferConfigRegAddrs                                0x0124
#define MWV207REG_FRAME_BUFFER_CONFIG_Address                            0x00490
#define MWV207REG_FRAME_BUFFER_CONFIG_MSB                                     15
#define MWV207REG_FRAME_BUFFER_CONFIG_LSB                                      1
#define MWV207REG_FRAME_BUFFER_CONFIG_BLK                                      1
#define MWV207REG_FRAME_BUFFER_CONFIG_Count                                    2
#define MWV207REG_FRAME_BUFFER_CONFIG_FieldMask                       0x31111317
#define MWV207REG_FRAME_BUFFER_CONFIG_ReadMask                        0x11011317
#define MWV207REG_FRAME_BUFFER_CONFIG_WriteMask                       0x20111317
#define MWV207REG_FRAME_BUFFER_CONFIG_ResetValue                      0x00000000

#define MWV207REG_FRAME_BUFFER_CONFIG_BACK_PRESSURE_DISABLE                29:29
#define MWV207REG_FRAME_BUFFER_CONFIG_BACK_PRESSURE_DISABLE_End               29
#define MWV207REG_FRAME_BUFFER_CONFIG_BACK_PRESSURE_DISABLE_Start             29
#define MWV207REG_FRAME_BUFFER_CONFIG_BACK_PRESSURE_DISABLE_Type             U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_BACK_PRESSURE_DISABLE_NO             0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_BACK_PRESSURE_DISABLE_YES            0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_FLIP_IN_PROGRESS                     28:28
#define MWV207REG_FRAME_BUFFER_CONFIG_FLIP_IN_PROGRESS_End                    28
#define MWV207REG_FRAME_BUFFER_CONFIG_FLIP_IN_PROGRESS_Start                  28
#define MWV207REG_FRAME_BUFFER_CONFIG_FLIP_IN_PROGRESS_Type                  U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_FLIP_IN_PROGRESS_NO                  0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_FLIP_IN_PROGRESS_YES                 0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_UNDERFLOW                            24:24
#define MWV207REG_FRAME_BUFFER_CONFIG_UNDERFLOW_End                           24
#define MWV207REG_FRAME_BUFFER_CONFIG_UNDERFLOW_Start                         24
#define MWV207REG_FRAME_BUFFER_CONFIG_UNDERFLOW_Type                         U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_UNDERFLOW_NO                         0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_UNDERFLOW_YES                        0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_RESET                                20:20
#define MWV207REG_FRAME_BUFFER_CONFIG_RESET_End                               20
#define MWV207REG_FRAME_BUFFER_CONFIG_RESET_Start                             20
#define MWV207REG_FRAME_BUFFER_CONFIG_RESET_Type                             U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_RESET_RESET                          0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_VALID                                16:16
#define MWV207REG_FRAME_BUFFER_CONFIG_VALID_End                               16
#define MWV207REG_FRAME_BUFFER_CONFIG_VALID_Start                             16
#define MWV207REG_FRAME_BUFFER_CONFIG_VALID_Type                             U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_VALID_WORKING                        0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_VALID_PENDING                        0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_GAMMA                                12:12
#define MWV207REG_FRAME_BUFFER_CONFIG_GAMMA_End                               12
#define MWV207REG_FRAME_BUFFER_CONFIG_GAMMA_Start                             12
#define MWV207REG_FRAME_BUFFER_CONFIG_GAMMA_Type                             U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_GAMMA_DISABLED                       0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_GAMMA_ENABLED                        0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_SWITCHPANEL                            9:9
#define MWV207REG_FRAME_BUFFER_CONFIG_SWITCHPANEL_End                          9
#define MWV207REG_FRAME_BUFFER_CONFIG_SWITCHPANEL_Start                        9
#define MWV207REG_FRAME_BUFFER_CONFIG_SWITCHPANEL_Type                       U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_SWITCHPANEL_DISABLED                 0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_SWITCHPANEL_ENABLED                  0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_OUTPUT                                 8:8
#define MWV207REG_FRAME_BUFFER_CONFIG_OUTPUT_End                               8
#define MWV207REG_FRAME_BUFFER_CONFIG_OUTPUT_Start                             8
#define MWV207REG_FRAME_BUFFER_CONFIG_OUTPUT_Type                            U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_OUTPUT_DISABLED                      0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_OUTPUT_ENABLED                       0x1


#define MWV207REG_FRAME_BUFFER_CONFIG_MODE                                   4:4
#define MWV207REG_FRAME_BUFFER_CONFIG_MODE_End                                 4
#define MWV207REG_FRAME_BUFFER_CONFIG_MODE_Start                               4
#define MWV207REG_FRAME_BUFFER_CONFIG_MODE_Type                              U01
#define   MWV207REG_FRAME_BUFFER_CONFIG_MODE_LINEAR                          0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_MODE_TILE4X4                         0x1

#define MWV207REG_FRAME_BUFFER_CONFIG_FORMAT                                 2:0
#define MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_End                               2
#define MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_Start                             0
#define MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_Type                            U03
#define   MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_NONE                          0x0
#define   MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_R4G4B4                        0x1
#define   MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_R5G5B5                        0x2
#define   MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_R5G6B5                        0x3
#define   MWV207REG_FRAME_BUFFER_CONFIG_FORMAT_R8G8B8                        0x4



#define mwv207regFrameBufferAddressRegAddrs                               0x0126
#define MWV207REG_FRAME_BUFFER_ADDRESS_Address                           0x00498
#define MWV207REG_FRAME_BUFFER_ADDRESS_MSB                                    15
#define MWV207REG_FRAME_BUFFER_ADDRESS_LSB                                     1
#define MWV207REG_FRAME_BUFFER_ADDRESS_BLK                                     1
#define MWV207REG_FRAME_BUFFER_ADDRESS_Count                                   2
#define MWV207REG_FRAME_BUFFER_ADDRESS_FieldMask                      0xFFFFFFFF
#define MWV207REG_FRAME_BUFFER_ADDRESS_ReadMask                       0xFFFFFFFF
#define MWV207REG_FRAME_BUFFER_ADDRESS_WriteMask                      0xFFFFFFFF
#define MWV207REG_FRAME_BUFFER_ADDRESS_ResetValue                     0x00000000

#define MWV207REG_FRAME_BUFFER_ADDRESS_ADDRESS                              31:0
#define MWV207REG_FRAME_BUFFER_ADDRESS_ADDRESS_End                            31
#define MWV207REG_FRAME_BUFFER_ADDRESS_ADDRESS_Start                           0
#define MWV207REG_FRAME_BUFFER_ADDRESS_ADDRESS_Type                          U32



#define mwv207regFrameBufferStrideRegAddrs                                0x0128
#define MWV207REG_FRAME_BUFFER_STRIDE_Address                            0x004A0
#define MWV207REG_FRAME_BUFFER_STRIDE_MSB                                     15
#define MWV207REG_FRAME_BUFFER_STRIDE_LSB                                      1
#define MWV207REG_FRAME_BUFFER_STRIDE_BLK                                      1
#define MWV207REG_FRAME_BUFFER_STRIDE_Count                                    2
#define MWV207REG_FRAME_BUFFER_STRIDE_FieldMask                       0x0001FFFF
#define MWV207REG_FRAME_BUFFER_STRIDE_ReadMask                        0x0001FFFF
#define MWV207REG_FRAME_BUFFER_STRIDE_WriteMask                       0x0001FFFF
#define MWV207REG_FRAME_BUFFER_STRIDE_ResetValue                      0x00000000


#define MWV207REG_FRAME_BUFFER_STRIDE_STRIDE                                16:0
#define MWV207REG_FRAME_BUFFER_STRIDE_STRIDE_End                              16
#define MWV207REG_FRAME_BUFFER_STRIDE_STRIDE_Start                             0
#define MWV207REG_FRAME_BUFFER_STRIDE_STRIDE_Type                            U17



#define mwv207regFrameBufferOriginRegAddrs                                0x012A
#define MWV207REG_FRAME_BUFFER_ORIGIN_Address                            0x004A8
#define MWV207REG_FRAME_BUFFER_ORIGIN_MSB                                     15
#define MWV207REG_FRAME_BUFFER_ORIGIN_LSB                                      1
#define MWV207REG_FRAME_BUFFER_ORIGIN_BLK                                      1
#define MWV207REG_FRAME_BUFFER_ORIGIN_Count                                    2
#define MWV207REG_FRAME_BUFFER_ORIGIN_FieldMask                       0x07FF07FF
#define MWV207REG_FRAME_BUFFER_ORIGIN_ReadMask                        0x07FF07FF
#define MWV207REG_FRAME_BUFFER_ORIGIN_WriteMask                       0x07FF07FF
#define MWV207REG_FRAME_BUFFER_ORIGIN_ResetValue                      0x00000000


#define MWV207REG_FRAME_BUFFER_ORIGIN_X                                     10:0
#define MWV207REG_FRAME_BUFFER_ORIGIN_X_End                                   10
#define MWV207REG_FRAME_BUFFER_ORIGIN_X_Start                                  0
#define MWV207REG_FRAME_BUFFER_ORIGIN_X_Type                                 U11


#define MWV207REG_FRAME_BUFFER_ORIGIN_Y                                    26:16
#define MWV207REG_FRAME_BUFFER_ORIGIN_Y_End                                   26
#define MWV207REG_FRAME_BUFFER_ORIGIN_Y_Start                                 16
#define MWV207REG_FRAME_BUFFER_ORIGIN_Y_Type                                 U11




#define mwv207regOverlayConfigRegAddrs                                    0x012C
#define MWV207REG_OVERLAY_CONFIG_Address                                 0x004B0
#define MWV207REG_OVERLAY_CONFIG_MSB                                          15
#define MWV207REG_OVERLAY_CONFIG_LSB                                           1
#define MWV207REG_OVERLAY_CONFIG_BLK                                           1
#define MWV207REG_OVERLAY_CONFIG_Count                                         2
#define MWV207REG_OVERLAY_CONFIG_FieldMask                            0x0111FF17
#define MWV207REG_OVERLAY_CONFIG_ReadMask                             0x0111FF17
#define MWV207REG_OVERLAY_CONFIG_WriteMask                            0x0001FF17
#define MWV207REG_OVERLAY_CONFIG_ResetValue                           0x00000000

#define MWV207REG_OVERLAY_CONFIG_FLIP_IN_PROGRESS                          24:24
#define MWV207REG_OVERLAY_CONFIG_FLIP_IN_PROGRESS_End                         24
#define MWV207REG_OVERLAY_CONFIG_FLIP_IN_PROGRESS_Start                       24
#define MWV207REG_OVERLAY_CONFIG_FLIP_IN_PROGRESS_Type                       U01
#define   MWV207REG_OVERLAY_CONFIG_FLIP_IN_PROGRESS_NO                       0x0
#define   MWV207REG_OVERLAY_CONFIG_FLIP_IN_PROGRESS_YES                      0x1

#define MWV207REG_OVERLAY_CONFIG_UNDERFLOW                                 20:20
#define MWV207REG_OVERLAY_CONFIG_UNDERFLOW_End                                20
#define MWV207REG_OVERLAY_CONFIG_UNDERFLOW_Start                              20
#define MWV207REG_OVERLAY_CONFIG_UNDERFLOW_Type                              U01
#define   MWV207REG_OVERLAY_CONFIG_UNDERFLOW_NO                              0x0
#define   MWV207REG_OVERLAY_CONFIG_UNDERFLOW_YES                             0x1


#define MWV207REG_OVERLAY_CONFIG_MODE                                      16:16
#define MWV207REG_OVERLAY_CONFIG_MODE_End                                     16
#define MWV207REG_OVERLAY_CONFIG_MODE_Start                                   16
#define MWV207REG_OVERLAY_CONFIG_MODE_Type                                   U01
#define   MWV207REG_OVERLAY_CONFIG_MODE_LINEAR                               0x0
#define   MWV207REG_OVERLAY_CONFIG_MODE_TILE4X4                              0x1

#define MWV207REG_OVERLAY_CONFIG_ALPHA_VALUE                                15:8
#define MWV207REG_OVERLAY_CONFIG_ALPHA_VALUE_End                              15
#define MWV207REG_OVERLAY_CONFIG_ALPHA_VALUE_Start                             8
#define MWV207REG_OVERLAY_CONFIG_ALPHA_VALUE_Type                            U08

#define MWV207REG_OVERLAY_CONFIG_ALPHA_MODE                                  4:4
#define MWV207REG_OVERLAY_CONFIG_ALPHA_MODE_End                                4
#define MWV207REG_OVERLAY_CONFIG_ALPHA_MODE_Start                              4
#define MWV207REG_OVERLAY_CONFIG_ALPHA_MODE_Type                             U01
#define   MWV207REG_OVERLAY_CONFIG_ALPHA_MODE_PER_PIXEL                      0x0
#define   MWV207REG_OVERLAY_CONFIG_ALPHA_MODE_PLANAR                         0x1

#define MWV207REG_OVERLAY_CONFIG_FORMAT                                      2:0
#define MWV207REG_OVERLAY_CONFIG_FORMAT_End                                    2
#define MWV207REG_OVERLAY_CONFIG_FORMAT_Start                                  0
#define MWV207REG_OVERLAY_CONFIG_FORMAT_Type                                 U03
#define   MWV207REG_OVERLAY_CONFIG_FORMAT_NONE                               0x0
#define   MWV207REG_OVERLAY_CONFIG_FORMAT_A4R4G4B4                           0x1
#define   MWV207REG_OVERLAY_CONFIG_FORMAT_A1R5G5B5                           0x2
#define   MWV207REG_OVERLAY_CONFIG_FORMAT_R5G6B5                             0x3
#define   MWV207REG_OVERLAY_CONFIG_FORMAT_A8R8G8B8                           0x4




#define mwv207regOverlayAddressRegAddrs                                   0x012E
#define MWV207REG_OVERLAY_ADDRESS_Address                                0x004B8
#define MWV207REG_OVERLAY_ADDRESS_MSB                                         15
#define MWV207REG_OVERLAY_ADDRESS_LSB                                          1
#define MWV207REG_OVERLAY_ADDRESS_BLK                                          1
#define MWV207REG_OVERLAY_ADDRESS_Count                                        2
#define MWV207REG_OVERLAY_ADDRESS_FieldMask                           0xFFFFFFFF
#define MWV207REG_OVERLAY_ADDRESS_ReadMask                            0xFFFFFFFF
#define MWV207REG_OVERLAY_ADDRESS_WriteMask                           0xFFFFFFFF
#define MWV207REG_OVERLAY_ADDRESS_ResetValue                          0x00000000

#define MWV207REG_OVERLAY_ADDRESS_ADDRESS                                   31:0
#define MWV207REG_OVERLAY_ADDRESS_ADDRESS_End                                 31
#define MWV207REG_OVERLAY_ADDRESS_ADDRESS_Start                                0
#define MWV207REG_OVERLAY_ADDRESS_ADDRESS_Type                               U32




#define mwv207regOverlayStrideRegAddrs                                    0x0130
#define MWV207REG_OVERLAY_STRIDE_Address                                 0x004C0
#define MWV207REG_OVERLAY_STRIDE_MSB                                          15
#define MWV207REG_OVERLAY_STRIDE_LSB                                           1
#define MWV207REG_OVERLAY_STRIDE_BLK                                           1
#define MWV207REG_OVERLAY_STRIDE_Count                                         2
#define MWV207REG_OVERLAY_STRIDE_FieldMask                            0x00003FFF
#define MWV207REG_OVERLAY_STRIDE_ReadMask                             0x00003FFC
#define MWV207REG_OVERLAY_STRIDE_WriteMask                            0x00003FFC
#define MWV207REG_OVERLAY_STRIDE_ResetValue                           0x00000000


#define MWV207REG_OVERLAY_STRIDE_STRIDE                                     13:0
#define MWV207REG_OVERLAY_STRIDE_STRIDE_End                                   13
#define MWV207REG_OVERLAY_STRIDE_STRIDE_Start                                  0
#define MWV207REG_OVERLAY_STRIDE_STRIDE_Type                                 U14



#define mwv207regOverlayTLRegAddrs                                        0x0132
#define MWV207REG_OVERLAY_TL_Address                                     0x004C8
#define MWV207REG_OVERLAY_TL_MSB                                              15
#define MWV207REG_OVERLAY_TL_LSB                                               1
#define MWV207REG_OVERLAY_TL_BLK                                               1
#define MWV207REG_OVERLAY_TL_Count                                             2
#define MWV207REG_OVERLAY_TL_FieldMask                                0x007F07FF
#define MWV207REG_OVERLAY_TL_ReadMask                                 0x007F07FF
#define MWV207REG_OVERLAY_TL_WriteMask                                0x007F07FF
#define MWV207REG_OVERLAY_TL_ResetValue                               0x00000000


#define MWV207REG_OVERLAY_TL_X                                              10:0
#define MWV207REG_OVERLAY_TL_X_End                                            10
#define MWV207REG_OVERLAY_TL_X_Start                                           0
#define MWV207REG_OVERLAY_TL_X_Type                                          U11


#define MWV207REG_OVERLAY_TL_Y                                             22:16
#define MWV207REG_OVERLAY_TL_Y_End                                            22
#define MWV207REG_OVERLAY_TL_Y_Start                                          16
#define MWV207REG_OVERLAY_TL_Y_Type                                          U07



#define mwv207regOverlayBRRegAddrs                                        0x0134
#define MWV207REG_OVERLAY_BR_Address                                     0x004D0
#define MWV207REG_OVERLAY_BR_MSB                                              15
#define MWV207REG_OVERLAY_BR_LSB                                               1
#define MWV207REG_OVERLAY_BR_BLK                                               1
#define MWV207REG_OVERLAY_BR_Count                                             2
#define MWV207REG_OVERLAY_BR_FieldMask                                0x07FF07FF
#define MWV207REG_OVERLAY_BR_ReadMask                                 0x07FF07FF
#define MWV207REG_OVERLAY_BR_WriteMask                                0x07FF07FF
#define MWV207REG_OVERLAY_BR_ResetValue                               0x00000000


#define MWV207REG_OVERLAY_BR_X                                              10:0
#define MWV207REG_OVERLAY_BR_X_End                                            10
#define MWV207REG_OVERLAY_BR_X_Start                                           0
#define MWV207REG_OVERLAY_BR_X_Type                                          U11


#define MWV207REG_OVERLAY_BR_Y                                             26:16
#define MWV207REG_OVERLAY_BR_Y_End                                            26
#define MWV207REG_OVERLAY_BR_Y_Start                                          16
#define MWV207REG_OVERLAY_BR_Y_Type                                          U11




#define mwv207regDisplayDitherConfigRegAddrs                              0x0136
#define MWV207REG_DISPLAY_DITHER_CONFIG_Address                          0x004D8
#define MWV207REG_DISPLAY_DITHER_CONFIG_MSB                                   15
#define MWV207REG_DISPLAY_DITHER_CONFIG_LSB                                    1
#define MWV207REG_DISPLAY_DITHER_CONFIG_BLK                                    1
#define MWV207REG_DISPLAY_DITHER_CONFIG_Count                                  2
#define MWV207REG_DISPLAY_DITHER_CONFIG_FieldMask                     0x800F0F0F
#define MWV207REG_DISPLAY_DITHER_CONFIG_ReadMask                      0x800F0F0F
#define MWV207REG_DISPLAY_DITHER_CONFIG_WriteMask                     0x800F0F0F
#define MWV207REG_DISPLAY_DITHER_CONFIG_ResetValue                    0x00000000

#define MWV207REG_DISPLAY_DITHER_CONFIG_ENABLE                             31:31
#define MWV207REG_DISPLAY_DITHER_CONFIG_ENABLE_End                            31
#define MWV207REG_DISPLAY_DITHER_CONFIG_ENABLE_Start                          31
#define MWV207REG_DISPLAY_DITHER_CONFIG_ENABLE_Type                          U01
#define   MWV207REG_DISPLAY_DITHER_CONFIG_ENABLE_DISABLED                    0x0
#define   MWV207REG_DISPLAY_DITHER_CONFIG_ENABLE_ENABLED                     0x1

#define MWV207REG_DISPLAY_DITHER_CONFIG_RED_SIZE                           19:16
#define MWV207REG_DISPLAY_DITHER_CONFIG_RED_SIZE_End                          19
#define MWV207REG_DISPLAY_DITHER_CONFIG_RED_SIZE_Start                        16
#define MWV207REG_DISPLAY_DITHER_CONFIG_RED_SIZE_Type                        U04

#define MWV207REG_DISPLAY_DITHER_CONFIG_GREEN_SIZE                          11:8
#define MWV207REG_DISPLAY_DITHER_CONFIG_GREEN_SIZE_End                        11
#define MWV207REG_DISPLAY_DITHER_CONFIG_GREEN_SIZE_Start                       8
#define MWV207REG_DISPLAY_DITHER_CONFIG_GREEN_SIZE_Type                      U04

#define MWV207REG_DISPLAY_DITHER_CONFIG_BLUE_SIZE                            3:0
#define MWV207REG_DISPLAY_DITHER_CONFIG_BLUE_SIZE_End                          3
#define MWV207REG_DISPLAY_DITHER_CONFIG_BLUE_SIZE_Start                        0
#define MWV207REG_DISPLAY_DITHER_CONFIG_BLUE_SIZE_Type                       U04




#define mwv207regDisplayDitherTableLowRegAddrs                            0x0138
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Address                       0x004E0
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_MSB                                15
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_LSB                                 1
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_BLK                                 1
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Count                               2
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_FieldMask                  0xFFFFFFFF
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_ReadMask                   0xFFFFFFFF
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_WriteMask                  0xFFFFFFFF
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_ResetValue                 0x00000000


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X0                             3:0
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X0_End                           3
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X0_Start                         0
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X0_Type                        U04


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X1                             7:4
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X1_End                           7
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X1_Start                         4
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X1_Type                        U04


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X2                            11:8
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X2_End                          11
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X2_Start                         8
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X2_Type                        U04


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X3                           15:12
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X3_End                          15
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X3_Start                        12
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y0_X3_Type                        U04


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X0                           19:16
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X0_End                          19
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X0_Start                        16
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X0_Type                        U04


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X1                           23:20
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X1_End                          23
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X1_Start                        20
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X1_Type                        U04


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X2                           27:24
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X2_End                          27
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X2_Start                        24
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X2_Type                        U04


#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X3                           31:28
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X3_End                          31
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X3_Start                        28
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_Y1_X3_Type                        U04

#define mwv207regDisplayDitherTableHighRegAddrs                           0x013A
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Address                      0x004E8
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_MSB                               15
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_LSB                                1
#define MWV207REG_DISPLAY_DITHER_TABLE_LOW_HIGH_BLK                            1
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Count                              2
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_FieldMask                 0xFFFFFFFF
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_ReadMask                  0xFFFFFFFF
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_WriteMask                 0xFFFFFFFF
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_ResetValue                0x00000000


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0                            3:0
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0_End                          3
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0_Start                        0
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X0_Type                       U04


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1                            7:4
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1_End                          7
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1_Start                        4
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X1_Type                       U04


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2                           11:8
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2_End                         11
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2_Start                        8
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X2_Type                       U04


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3                          15:12
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3_End                         15
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3_Start                       12
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y2_X3_Type                       U04


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0                          19:16
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0_End                         19
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0_Start                       16
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X0_Type                       U04


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1                          23:20
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1_End                         23
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1_Start                       20
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X1_Type                       U04


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2                          27:24
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2_End                         27
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2_Start                       24
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X2_Type                       U04


#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3                          31:28
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3_End                         31
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3_Start                       28
#define MWV207REG_DISPLAY_DITHER_TABLE_HIGH_Y3_X3_Type                       U04



#define mwv207regPanelConfigRegAddrs                                      0x013C
#define MWV207REG_PANEL_CONFIG_Address                                   0x004F0
#define MWV207REG_PANEL_CONFIG_MSB                                            15
#define MWV207REG_PANEL_CONFIG_LSB                                             1
#define MWV207REG_PANEL_CONFIG_BLK                                             1
#define MWV207REG_PANEL_CONFIG_Count                                           2
#define MWV207REG_PANEL_CONFIG_FieldMask                              0x80033333
#define MWV207REG_PANEL_CONFIG_ReadMask                               0x80033333
#define MWV207REG_PANEL_CONFIG_WriteMask                              0x80033333
#define MWV207REG_PANEL_CONFIG_ResetValue                             0x00000000


#define MWV207REG_PANEL_CONFIG_SEQUENCING                                  31:31
#define MWV207REG_PANEL_CONFIG_SEQUENCING_End                                 31
#define MWV207REG_PANEL_CONFIG_SEQUENCING_Start                               31
#define MWV207REG_PANEL_CONFIG_SEQUENCING_Type                               U01
#define   MWV207REG_PANEL_CONFIG_SEQUENCING_HARDWARE                         0x0
#define   MWV207REG_PANEL_CONFIG_SEQUENCING_SOFTWARE                         0x1


#define MWV207REG_PANEL_CONFIG_BACKLIGHT_POLARITY                          17:17
#define MWV207REG_PANEL_CONFIG_BACKLIGHT_POLARITY_End                         17
#define MWV207REG_PANEL_CONFIG_BACKLIGHT_POLARITY_Start                       17
#define MWV207REG_PANEL_CONFIG_BACKLIGHT_POLARITY_Type                       U01
#define   MWV207REG_PANEL_CONFIG_BACKLIGHT_POLARITY_POSITIVE                 0x0
#define   MWV207REG_PANEL_CONFIG_BACKLIGHT_POLARITY_NEGATIVE                 0x1


#define MWV207REG_PANEL_CONFIG_BACKLIGHT                                   16:16
#define MWV207REG_PANEL_CONFIG_BACKLIGHT_End                                  16
#define MWV207REG_PANEL_CONFIG_BACKLIGHT_Start                                16
#define MWV207REG_PANEL_CONFIG_BACKLIGHT_Type                                U01
#define   MWV207REG_PANEL_CONFIG_BACKLIGHT_DISABLED                          0x0
#define   MWV207REG_PANEL_CONFIG_BACKLIGHT_ENABLED                           0x1


#define MWV207REG_PANEL_CONFIG_POWER_POLARITY                              13:13
#define MWV207REG_PANEL_CONFIG_POWER_POLARITY_End                             13
#define MWV207REG_PANEL_CONFIG_POWER_POLARITY_Start                           13
#define MWV207REG_PANEL_CONFIG_POWER_POLARITY_Type                           U01
#define   MWV207REG_PANEL_CONFIG_POWER_POLARITY_POSITIVE                     0x0
#define   MWV207REG_PANEL_CONFIG_POWER_POLARITY_NEGATIVE                     0x1


#define MWV207REG_PANEL_CONFIG_POWER                                       12:12
#define MWV207REG_PANEL_CONFIG_POWER_End                                      12
#define MWV207REG_PANEL_CONFIG_POWER_Start                                    12
#define MWV207REG_PANEL_CONFIG_POWER_Type                                    U01
#define   MWV207REG_PANEL_CONFIG_POWER_DISABLED                              0x0
#define   MWV207REG_PANEL_CONFIG_POWER_ENABLED                               0x1


#define MWV207REG_PANEL_CONFIG_CLOCK_POLARITY                                9:9
#define MWV207REG_PANEL_CONFIG_CLOCK_POLARITY_End                              9
#define MWV207REG_PANEL_CONFIG_CLOCK_POLARITY_Start                            9
#define MWV207REG_PANEL_CONFIG_CLOCK_POLARITY_Type                           U01
#define   MWV207REG_PANEL_CONFIG_CLOCK_POLARITY_POSITIVE                     0x0
#define   MWV207REG_PANEL_CONFIG_CLOCK_POLARITY_NEGATIVE                     0x1


#define MWV207REG_PANEL_CONFIG_CLOCK                                         8:8
#define MWV207REG_PANEL_CONFIG_CLOCK_End                                       8
#define MWV207REG_PANEL_CONFIG_CLOCK_Start                                     8
#define MWV207REG_PANEL_CONFIG_CLOCK_Type                                    U01
#define   MWV207REG_PANEL_CONFIG_CLOCK_DISABLED                              0x0
#define   MWV207REG_PANEL_CONFIG_CLOCK_ENABLED                               0x1


#define MWV207REG_PANEL_CONFIG_DATA_POLARITY                                 5:5
#define MWV207REG_PANEL_CONFIG_DATA_POLARITY_End                               5
#define MWV207REG_PANEL_CONFIG_DATA_POLARITY_Start                             5
#define MWV207REG_PANEL_CONFIG_DATA_POLARITY_Type                            U01
#define   MWV207REG_PANEL_CONFIG_DATA_POLARITY_POSITIVE                      0x0
#define   MWV207REG_PANEL_CONFIG_DATA_POLARITY_NEGATIVE                      0x1


#define MWV207REG_PANEL_CONFIG_DATA_ENABLE                                   4:4
#define MWV207REG_PANEL_CONFIG_DATA_ENABLE_End                                 4
#define MWV207REG_PANEL_CONFIG_DATA_ENABLE_Start                               4
#define MWV207REG_PANEL_CONFIG_DATA_ENABLE_Type                              U01
#define   MWV207REG_PANEL_CONFIG_DATA_ENABLE_DISABLED                        0x0
#define   MWV207REG_PANEL_CONFIG_DATA_ENABLE_ENABLED                         0x1


#define MWV207REG_PANEL_CONFIG_DE_POLARITY                                   1:1
#define MWV207REG_PANEL_CONFIG_DE_POLARITY_End                                 1
#define MWV207REG_PANEL_CONFIG_DE_POLARITY_Start                               1
#define MWV207REG_PANEL_CONFIG_DE_POLARITY_Type                              U01
#define   MWV207REG_PANEL_CONFIG_DE_POLARITY_POSITIVE                        0x0
#define   MWV207REG_PANEL_CONFIG_DE_POLARITY_NEGATIVE                        0x1


#define MWV207REG_PANEL_CONFIG_DE                                            0:0
#define MWV207REG_PANEL_CONFIG_DE_End                                          0
#define MWV207REG_PANEL_CONFIG_DE_Start                                        0
#define MWV207REG_PANEL_CONFIG_DE_Type                                       U01
#define   MWV207REG_PANEL_CONFIG_DE_DISABLED                                 0x0
#define   MWV207REG_PANEL_CONFIG_DE_ENABLED                                  0x1



#define mwv207regPanelTimingRegAddrs                                      0x013E
#define MWV207REG_PANEL_TIMING_Address                                   0x004F8
#define MWV207REG_PANEL_TIMING_MSB                                            15
#define MWV207REG_PANEL_TIMING_LSB                                             1
#define MWV207REG_PANEL_TIMING_BLK                                             1
#define MWV207REG_PANEL_TIMING_Count                                           2
#define MWV207REG_PANEL_TIMING_FieldMask                              0xFFFFFFFF
#define MWV207REG_PANEL_TIMING_ReadMask                               0xFFFFFFFF
#define MWV207REG_PANEL_TIMING_WriteMask                              0xFFFFFFFF
#define MWV207REG_PANEL_TIMING_ResetValue                             0x00000000


#define MWV207REG_PANEL_TIMING_POWER_DISABLE                               31:28
#define MWV207REG_PANEL_TIMING_POWER_DISABLE_End                              31
#define MWV207REG_PANEL_TIMING_POWER_DISABLE_Start                            28
#define MWV207REG_PANEL_TIMING_POWER_DISABLE_Type                            U04


#define MWV207REG_PANEL_TIMING_BACKLIGHT_DISABLE                           27:24
#define MWV207REG_PANEL_TIMING_BACKLIGHT_DISABLE_End                          27
#define MWV207REG_PANEL_TIMING_BACKLIGHT_DISABLE_Start                        24
#define MWV207REG_PANEL_TIMING_BACKLIGHT_DISABLE_Type                        U04


#define MWV207REG_PANEL_TIMING_CLOCK_DISABLE                               23:20
#define MWV207REG_PANEL_TIMING_CLOCK_DISABLE_End                              23
#define MWV207REG_PANEL_TIMING_CLOCK_DISABLE_Start                            20
#define MWV207REG_PANEL_TIMING_CLOCK_DISABLE_Type                            U04


#define MWV207REG_PANEL_TIMING_DATA_DISABLE                                19:16
#define MWV207REG_PANEL_TIMING_DATA_DISABLE_End                               19
#define MWV207REG_PANEL_TIMING_DATA_DISABLE_Start                             16
#define MWV207REG_PANEL_TIMING_DATA_DISABLE_Type                             U04


#define MWV207REG_PANEL_TIMING_DATA_ENABLE                                 15:12
#define MWV207REG_PANEL_TIMING_DATA_ENABLE_End                                15
#define MWV207REG_PANEL_TIMING_DATA_ENABLE_Start                              12
#define MWV207REG_PANEL_TIMING_DATA_ENABLE_Type                              U04


#define MWV207REG_PANEL_TIMING_CLOCK_ENABLE                                 11:8
#define MWV207REG_PANEL_TIMING_CLOCK_ENABLE_End                               11
#define MWV207REG_PANEL_TIMING_CLOCK_ENABLE_Start                              8
#define MWV207REG_PANEL_TIMING_CLOCK_ENABLE_Type                             U04


#define MWV207REG_PANEL_TIMING_BACKLIGHT_ENABLE                              7:4
#define MWV207REG_PANEL_TIMING_BACKLIGHT_ENABLE_End                            7
#define MWV207REG_PANEL_TIMING_BACKLIGHT_ENABLE_Start                          4
#define MWV207REG_PANEL_TIMING_BACKLIGHT_ENABLE_Type                         U04


#define MWV207REG_PANEL_TIMING_POWER_ENABLE                                  3:0
#define MWV207REG_PANEL_TIMING_POWER_ENABLE_End                                3
#define MWV207REG_PANEL_TIMING_POWER_ENABLE_Start                              0
#define MWV207REG_PANEL_TIMING_POWER_ENABLE_Type                             U04



#define mwv207regHDisplayRegAddrs                                         0x0140
#define MWV207REG_HDISPLAY_Address                                       0x00500
#define MWV207REG_HDISPLAY_MSB                                                15
#define MWV207REG_HDISPLAY_LSB                                                 1
#define MWV207REG_HDISPLAY_BLK                                                 1
#define MWV207REG_HDISPLAY_Count                                               2
#define MWV207REG_HDISPLAY_FieldMask                                  0x7FFF7FFF
#define MWV207REG_HDISPLAY_ReadMask                                   0x7FFF7FFF
#define MWV207REG_HDISPLAY_WriteMask                                  0x7FFF7FFF
#define MWV207REG_HDISPLAY_ResetValue                                 0x00000000


#define MWV207REG_HDISPLAY_TOTAL                                           30:16
#define MWV207REG_HDISPLAY_TOTAL_End                                          30
#define MWV207REG_HDISPLAY_TOTAL_Start                                        16
#define MWV207REG_HDISPLAY_TOTAL_Type                                        U15


#define MWV207REG_HDISPLAY_DISPLAY_END                                      14:0
#define MWV207REG_HDISPLAY_DISPLAY_END_End                                    14
#define MWV207REG_HDISPLAY_DISPLAY_END_Start                                   0
#define MWV207REG_HDISPLAY_DISPLAY_END_Type                                  U15



#define mwv207regHSyncRegAddrs                                            0x0142
#define MWV207REG_HSYNC_Address                                          0x00508
#define MWV207REG_HSYNC_MSB                                                   15
#define MWV207REG_HSYNC_LSB                                                    1
#define MWV207REG_HSYNC_BLK                                                    1
#define MWV207REG_HSYNC_Count                                                  2
#define MWV207REG_HSYNC_FieldMask                                     0xFFFFFFFF
#define MWV207REG_HSYNC_ReadMask                                      0xFFFFFFFF
#define MWV207REG_HSYNC_WriteMask                                     0xFFFFFFFF
#define MWV207REG_HSYNC_ResetValue                                    0x00000000


#define MWV207REG_HSYNC_POLARITY                                           31:31
#define MWV207REG_HSYNC_POLARITY_End                                          31
#define MWV207REG_HSYNC_POLARITY_Start                                        31
#define MWV207REG_HSYNC_POLARITY_Type                                        U01
#define   MWV207REG_HSYNC_POLARITY_POSITIVE                                  0x0
#define   MWV207REG_HSYNC_POLARITY_NEGATIVE                                  0x1


#define MWV207REG_HSYNC_PULSE                                              30:30
#define MWV207REG_HSYNC_PULSE_End                                             30
#define MWV207REG_HSYNC_PULSE_Start                                           30
#define MWV207REG_HSYNC_PULSE_Type                                           U01
#define   MWV207REG_HSYNC_PULSE_DISABLED                                     0x0
#define   MWV207REG_HSYNC_PULSE_ENABLED                                      0x1


#define MWV207REG_HSYNC_END                                                29:15
#define MWV207REG_HSYNC_END_End                                               29
#define MWV207REG_HSYNC_END_Start                                             15
#define MWV207REG_HSYNC_END_Type                                             U15


#define MWV207REG_HSYNC_START                                               14:0
#define MWV207REG_HSYNC_START_End                                             14
#define MWV207REG_HSYNC_START_Start                                            0
#define MWV207REG_HSYNC_START_Type                                           U15



#define mwv207regHCounter1RegAddrs                                        0x0144
#define MWV207REG_HCOUNTER1_Address                                      0x00510
#define MWV207REG_HCOUNTER1_MSB                                               15
#define MWV207REG_HCOUNTER1_LSB                                                1
#define MWV207REG_HCOUNTER1_BLK                                                1
#define MWV207REG_HCOUNTER1_Count                                              2
#define MWV207REG_HCOUNTER1_FieldMask                                 0xCFFF0FFF
#define MWV207REG_HCOUNTER1_ReadMask                                  0xCFFF0FFF
#define MWV207REG_HCOUNTER1_WriteMask                                 0xCFFF0FFF
#define MWV207REG_HCOUNTER1_ResetValue                                0x00000000


#define MWV207REG_HCOUNTER1_POLARITY                                       31:31
#define MWV207REG_HCOUNTER1_POLARITY_End                                      31
#define MWV207REG_HCOUNTER1_POLARITY_Start                                    31
#define MWV207REG_HCOUNTER1_POLARITY_Type                                    U01
#define   MWV207REG_HCOUNTER1_POLARITY_POSITIVE                              0x0
#define   MWV207REG_HCOUNTER1_POLARITY_NEGATIVE                              0x1


#define MWV207REG_HCOUNTER1_PULSE                                          30:30
#define MWV207REG_HCOUNTER1_PULSE_End                                         30
#define MWV207REG_HCOUNTER1_PULSE_Start                                       30
#define MWV207REG_HCOUNTER1_PULSE_Type                                       U01
#define   MWV207REG_HCOUNTER1_PULSE_DISABLED                                 0x0
#define   MWV207REG_HCOUNTER1_PULSE_ENABLED                                  0x1


#define MWV207REG_HCOUNTER1_END                                            27:16
#define MWV207REG_HCOUNTER1_END_End                                           27
#define MWV207REG_HCOUNTER1_END_Start                                         16
#define MWV207REG_HCOUNTER1_END_Type                                         U12


#define MWV207REG_HCOUNTER1_START                                           11:0
#define MWV207REG_HCOUNTER1_START_End                                         11
#define MWV207REG_HCOUNTER1_START_Start                                        0
#define MWV207REG_HCOUNTER1_START_Type                                       U12



#define mwv207regHCounter2RegAddrs                                        0x0146
#define MWV207REG_HCOUNTER2_Address                                      0x00518
#define MWV207REG_HCOUNTER2_MSB                                               15
#define MWV207REG_HCOUNTER2_LSB                                                1
#define MWV207REG_HCOUNTER2_BLK                                                1
#define MWV207REG_HCOUNTER2_Count                                              2
#define MWV207REG_HCOUNTER2_FieldMask                                 0xCFFF0FFF
#define MWV207REG_HCOUNTER2_ReadMask                                  0xCFFF0FFF
#define MWV207REG_HCOUNTER2_WriteMask                                 0xCFFF0FFF
#define MWV207REG_HCOUNTER2_ResetValue                                0x00000000


#define MWV207REG_HCOUNTER2_POLARITY                                       31:31
#define MWV207REG_HCOUNTER2_POLARITY_End                                      31
#define MWV207REG_HCOUNTER2_POLARITY_Start                                    31
#define MWV207REG_HCOUNTER2_POLARITY_Type                                    U01
#define   MWV207REG_HCOUNTER2_POLARITY_POSITIVE                              0x0
#define   MWV207REG_HCOUNTER2_POLARITY_NEGATIVE                              0x1


#define MWV207REG_HCOUNTER2_PULSE                                          30:30
#define MWV207REG_HCOUNTER2_PULSE_End                                         30
#define MWV207REG_HCOUNTER2_PULSE_Start                                       30
#define MWV207REG_HCOUNTER2_PULSE_Type                                       U01
#define   MWV207REG_HCOUNTER2_PULSE_DISABLED                                 0x0
#define   MWV207REG_HCOUNTER2_PULSE_ENABLED                                  0x1


#define MWV207REG_HCOUNTER2_END                                            27:16
#define MWV207REG_HCOUNTER2_END_End                                           27
#define MWV207REG_HCOUNTER2_END_Start                                         16
#define MWV207REG_HCOUNTER2_END_Type                                         U12


#define MWV207REG_HCOUNTER2_START                                           11:0
#define MWV207REG_HCOUNTER2_START_End                                         11
#define MWV207REG_HCOUNTER2_START_Start                                        0
#define MWV207REG_HCOUNTER2_START_Type                                       U12



#define mwv207regVDisplayRegAddrs                                         0x0148
#define MWV207REG_VDISPLAY_Address                                       0x00520
#define MWV207REG_VDISPLAY_MSB                                                15
#define MWV207REG_VDISPLAY_LSB                                                 1
#define MWV207REG_VDISPLAY_BLK                                                 1
#define MWV207REG_VDISPLAY_Count                                               2
#define MWV207REG_VDISPLAY_FieldMask                                  0x7FFF7FFF
#define MWV207REG_VDISPLAY_ReadMask                                   0x7FFF7FFF
#define MWV207REG_VDISPLAY_WriteMask                                  0x7FFF7FFF
#define MWV207REG_VDISPLAY_ResetValue                                 0x00000000


#define MWV207REG_VDISPLAY_TOTAL                                           30:16
#define MWV207REG_VDISPLAY_TOTAL_End                                          30
#define MWV207REG_VDISPLAY_TOTAL_Start                                        16
#define MWV207REG_VDISPLAY_TOTAL_Type                                        U15


#define MWV207REG_VDISPLAY_DISPLAY_END                                      14:0
#define MWV207REG_VDISPLAY_DISPLAY_END_End                                    14
#define MWV207REG_VDISPLAY_DISPLAY_END_Start                                   0
#define MWV207REG_VDISPLAY_DISPLAY_END_Type                                  U15



#define mwv207regVSyncRegAddrs                                            0x014A
#define MWV207REG_VSYNC_Address                                          0x00528
#define MWV207REG_VSYNC_MSB                                                   15
#define MWV207REG_VSYNC_LSB                                                    1
#define MWV207REG_VSYNC_BLK                                                    1
#define MWV207REG_VSYNC_Count                                                  2
#define MWV207REG_VSYNC_FieldMask                                     0xFFFFFFFF
#define MWV207REG_VSYNC_ReadMask                                      0xFFFFFFFF
#define MWV207REG_VSYNC_WriteMask                                     0xFFFFFFFF
#define MWV207REG_VSYNC_ResetValue                                    0x00000000


#define MWV207REG_VSYNC_POLARITY                                           31:31
#define MWV207REG_VSYNC_POLARITY_End                                          31
#define MWV207REG_VSYNC_POLARITY_Start                                        31
#define MWV207REG_VSYNC_POLARITY_Type                                        U01
#define   MWV207REG_VSYNC_POLARITY_POSITIVE                                  0x0
#define   MWV207REG_VSYNC_POLARITY_NEGATIVE                                  0x1


#define MWV207REG_VSYNC_PULSE                                              30:30
#define MWV207REG_VSYNC_PULSE_End                                             30
#define MWV207REG_VSYNC_PULSE_Start                                           30
#define MWV207REG_VSYNC_PULSE_Type                                           U01
#define   MWV207REG_VSYNC_PULSE_DISABLED                                     0x0
#define   MWV207REG_VSYNC_PULSE_ENABLED                                      0x1


#define MWV207REG_VSYNC_END                                                29:15
#define MWV207REG_VSYNC_END_End                                               29
#define MWV207REG_VSYNC_END_Start                                             15
#define MWV207REG_VSYNC_END_Type                                             U15


#define MWV207REG_VSYNC_START                                               14:0
#define MWV207REG_VSYNC_START_End                                             14
#define MWV207REG_VSYNC_START_Start                                            0
#define MWV207REG_VSYNC_START_Type                                           U15



#define mwv207regDisplayCurrentLocationRegAddrs                           0x014C
#define MWV207REG_DISPLAY_CURRENT_LOCATION_Address                       0x00530
#define MWV207REG_DISPLAY_CURRENT_LOCATION_MSB                                15
#define MWV207REG_DISPLAY_CURRENT_LOCATION_LSB                                 1
#define MWV207REG_DISPLAY_CURRENT_LOCATION_BLK                                 1
#define MWV207REG_DISPLAY_CURRENT_LOCATION_Count                               2
#define MWV207REG_DISPLAY_CURRENT_LOCATION_FieldMask                  0xFFFFFFFF
#define MWV207REG_DISPLAY_CURRENT_LOCATION_ReadMask                   0xFFFFFFFF
#define MWV207REG_DISPLAY_CURRENT_LOCATION_WriteMask                  0x00000000
#define MWV207REG_DISPLAY_CURRENT_LOCATION_ResetValue                 0x00000000


#define MWV207REG_DISPLAY_CURRENT_LOCATION_X                                15:0
#define MWV207REG_DISPLAY_CURRENT_LOCATION_X_End                              15
#define MWV207REG_DISPLAY_CURRENT_LOCATION_X_Start                             0
#define MWV207REG_DISPLAY_CURRENT_LOCATION_X_Type                            U16


#define MWV207REG_DISPLAY_CURRENT_LOCATION_Y                               31:16
#define MWV207REG_DISPLAY_CURRENT_LOCATION_Y_End                              31
#define MWV207REG_DISPLAY_CURRENT_LOCATION_Y_Start                            16
#define MWV207REG_DISPLAY_CURRENT_LOCATION_Y_Type                            U16



#define mwv207regGammaIndexRegAddrs                                       0x014E
#define MWV207REG_GAMMA_INDEX_Address                                    0x00538
#define MWV207REG_GAMMA_INDEX_MSB                                             15
#define MWV207REG_GAMMA_INDEX_LSB                                              1
#define MWV207REG_GAMMA_INDEX_BLK                                              1
#define MWV207REG_GAMMA_INDEX_Count                                            2
#define MWV207REG_GAMMA_INDEX_FieldMask                               0x000000FF
#define MWV207REG_GAMMA_INDEX_ReadMask                                0x000000FF
#define MWV207REG_GAMMA_INDEX_WriteMask                               0x000000FF
#define MWV207REG_GAMMA_INDEX_ResetValue                              0x00000000


#define MWV207REG_GAMMA_INDEX_INDEX                                          7:0
#define MWV207REG_GAMMA_INDEX_INDEX_End                                        7
#define MWV207REG_GAMMA_INDEX_INDEX_Start                                      0
#define MWV207REG_GAMMA_INDEX_INDEX_Type                                     U08



#define mwv207regGammaDataRegAddrs                                        0x0150
#define MWV207REG_GAMMA_DATA_Address                                     0x00540
#define MWV207REG_GAMMA_DATA_MSB                                              15
#define MWV207REG_GAMMA_DATA_LSB                                               1
#define MWV207REG_GAMMA_DATA_BLK                                               1
#define MWV207REG_GAMMA_DATA_Count                                             2
#define MWV207REG_GAMMA_DATA_FieldMask                                0x00FFFFFF
#define MWV207REG_GAMMA_DATA_ReadMask                                 0x00FFFFFF
#define MWV207REG_GAMMA_DATA_WriteMask                                0x00FFFFFF
#define MWV207REG_GAMMA_DATA_ResetValue                               0x00000000


#define MWV207REG_GAMMA_DATA_RED                                           23:16
#define MWV207REG_GAMMA_DATA_RED_End                                          23
#define MWV207REG_GAMMA_DATA_RED_Start                                        16
#define MWV207REG_GAMMA_DATA_RED_Type                                        U08


#define MWV207REG_GAMMA_DATA_GREEN                                          15:8
#define MWV207REG_GAMMA_DATA_GREEN_End                                        15
#define MWV207REG_GAMMA_DATA_GREEN_Start                                       8
#define MWV207REG_GAMMA_DATA_GREEN_Type                                      U08


#define MWV207REG_GAMMA_DATA_BLUE                                            7:0
#define MWV207REG_GAMMA_DATA_BLUE_End                                          7
#define MWV207REG_GAMMA_DATA_BLUE_Start                                        0
#define MWV207REG_GAMMA_DATA_BLUE_Type                                       U08



#define mwv207regCursorConfigRegAddrs                                     0x0152
#define MWV207REG_CURSOR_CONFIG_Address                                  0x00548
#define MWV207REG_CURSOR_CONFIG_MSB                                           15
#define MWV207REG_CURSOR_CONFIG_LSB                                            0
#define MWV207REG_CURSOR_CONFIG_BLK                                            0
#define MWV207REG_CURSOR_CONFIG_Count                                          1
#define MWV207REG_CURSOR_CONFIG_FieldMask                             0x801F1F13
#define MWV207REG_CURSOR_CONFIG_ReadMask                              0x801F1F13
#define MWV207REG_CURSOR_CONFIG_WriteMask                             0x001F1F13
#define MWV207REG_CURSOR_CONFIG_ResetValue                            0x00000000

#define MWV207REG_CURSOR_CONFIG_FLIP_IN_PROGRESS                           31:31
#define MWV207REG_CURSOR_CONFIG_FLIP_IN_PROGRESS_End                          31
#define MWV207REG_CURSOR_CONFIG_FLIP_IN_PROGRESS_Start                        31
#define MWV207REG_CURSOR_CONFIG_FLIP_IN_PROGRESS_Type                        U01
#define   MWV207REG_CURSOR_CONFIG_FLIP_IN_PROGRESS_NO                        0x0
#define   MWV207REG_CURSOR_CONFIG_FLIP_IN_PROGRESS_YES                       0x1

#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_X                                 20:16
#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_X_End                                20
#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_X_Start                              16
#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_X_Type                              U05

#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_Y                                  12:8
#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_Y_End                                12
#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_Y_Start                               8
#define MWV207REG_CURSOR_CONFIG_HOT_SPOT_Y_Type                              U05


#define MWV207REG_CURSOR_CONFIG_DISPLAY                                      4:4
#define MWV207REG_CURSOR_CONFIG_DISPLAY_End                                    4
#define MWV207REG_CURSOR_CONFIG_DISPLAY_Start                                  4
#define MWV207REG_CURSOR_CONFIG_DISPLAY_Type                                 U01
#define   MWV207REG_CURSOR_CONFIG_DISPLAY_DISPLAY0                           0x0
#define   MWV207REG_CURSOR_CONFIG_DISPLAY_DISPLAY1                           0x1

#define MWV207REG_CURSOR_CONFIG_FORMAT                                       1:0
#define MWV207REG_CURSOR_CONFIG_FORMAT_End                                     1
#define MWV207REG_CURSOR_CONFIG_FORMAT_Start                                   0
#define MWV207REG_CURSOR_CONFIG_FORMAT_Type                                  U02
#define   MWV207REG_CURSOR_CONFIG_FORMAT_DISABLED                            0x0
#define   MWV207REG_CURSOR_CONFIG_FORMAT_MASKED                              0x1
#define   MWV207REG_CURSOR_CONFIG_FORMAT_A8R8G8B8                            0x2



#define mwv207regCursorAddressRegAddrs                                    0x0153
#define MWV207REG_CURSOR_ADDRESS_Address                                 0x0054C
#define MWV207REG_CURSOR_ADDRESS_MSB                                          15
#define MWV207REG_CURSOR_ADDRESS_LSB                                           0
#define MWV207REG_CURSOR_ADDRESS_BLK                                           0
#define MWV207REG_CURSOR_ADDRESS_Count                                         1
#define MWV207REG_CURSOR_ADDRESS_FieldMask                            0xFFFFFFFF
#define MWV207REG_CURSOR_ADDRESS_ReadMask                             0xFFFFFFFF
#define MWV207REG_CURSOR_ADDRESS_WriteMask                            0xFFFFFFFF
#define MWV207REG_CURSOR_ADDRESS_ResetValue                           0x00000000

#define MWV207REG_CURSOR_ADDRESS_ADDRESS                                    31:0
#define MWV207REG_CURSOR_ADDRESS_ADDRESS_End                                  31
#define MWV207REG_CURSOR_ADDRESS_ADDRESS_Start                                 0
#define MWV207REG_CURSOR_ADDRESS_ADDRESS_Type                                U32



#define mwv207regCursorLocationRegAddrs                                   0x0154
#define MWV207REG_CURSOR_LOCATION_Address                                0x00550
#define MWV207REG_CURSOR_LOCATION_MSB                                         15
#define MWV207REG_CURSOR_LOCATION_LSB                                          0
#define MWV207REG_CURSOR_LOCATION_BLK                                          0
#define MWV207REG_CURSOR_LOCATION_Count                                        1
#define MWV207REG_CURSOR_LOCATION_FieldMask                           0x7FFF7FFF
#define MWV207REG_CURSOR_LOCATION_ReadMask                            0x7FFF7FFF
#define MWV207REG_CURSOR_LOCATION_WriteMask                           0x7FFF7FFF
#define MWV207REG_CURSOR_LOCATION_ResetValue                          0x00000000


#define MWV207REG_CURSOR_LOCATION_X                                         14:0
#define MWV207REG_CURSOR_LOCATION_X_End                                       14
#define MWV207REG_CURSOR_LOCATION_X_Start                                      0
#define MWV207REG_CURSOR_LOCATION_X_Type                                     U15


#define MWV207REG_CURSOR_LOCATION_Y                                        30:16
#define MWV207REG_CURSOR_LOCATION_Y_End                                       30
#define MWV207REG_CURSOR_LOCATION_Y_Start                                     16
#define MWV207REG_CURSOR_LOCATION_Y_Type                                     U15



#define mwv207regCursorBackgroundRegAddrs                                 0x0155
#define MWV207REG_CURSOR_BACKGROUND_Address                              0x00554
#define MWV207REG_CURSOR_BACKGROUND_MSB                                       15
#define MWV207REG_CURSOR_BACKGROUND_LSB                                        0
#define MWV207REG_CURSOR_BACKGROUND_BLK                                        0
#define MWV207REG_CURSOR_BACKGROUND_Count                                      1
#define MWV207REG_CURSOR_BACKGROUND_FieldMask                         0x00FFFFFF
#define MWV207REG_CURSOR_BACKGROUND_ReadMask                          0x00FFFFFF
#define MWV207REG_CURSOR_BACKGROUND_WriteMask                         0x00FFFFFF
#define MWV207REG_CURSOR_BACKGROUND_ResetValue                        0x00000000


#define MWV207REG_CURSOR_BACKGROUND_RED                                    23:16
#define MWV207REG_CURSOR_BACKGROUND_RED_End                                   23
#define MWV207REG_CURSOR_BACKGROUND_RED_Start                                 16
#define MWV207REG_CURSOR_BACKGROUND_RED_Type                                 U08


#define MWV207REG_CURSOR_BACKGROUND_GREEN                                   15:8
#define MWV207REG_CURSOR_BACKGROUND_GREEN_End                                 15
#define MWV207REG_CURSOR_BACKGROUND_GREEN_Start                                8
#define MWV207REG_CURSOR_BACKGROUND_GREEN_Type                               U08


#define MWV207REG_CURSOR_BACKGROUND_BLUE                                     7:0
#define MWV207REG_CURSOR_BACKGROUND_BLUE_End                                   7
#define MWV207REG_CURSOR_BACKGROUND_BLUE_Start                                 0
#define MWV207REG_CURSOR_BACKGROUND_BLUE_Type                                U08



#define mwv207regCursorForegroundRegAddrs                                 0x0156
#define MWV207REG_CURSOR_FOREGROUND_Address                              0x00558
#define MWV207REG_CURSOR_FOREGROUND_MSB                                       15
#define MWV207REG_CURSOR_FOREGROUND_LSB                                        0
#define MWV207REG_CURSOR_FOREGROUND_BLK                                        0
#define MWV207REG_CURSOR_FOREGROUND_Count                                      1
#define MWV207REG_CURSOR_FOREGROUND_FieldMask                         0x00FFFFFF
#define MWV207REG_CURSOR_FOREGROUND_ReadMask                          0x00FFFFFF
#define MWV207REG_CURSOR_FOREGROUND_WriteMask                         0x00FFFFFF
#define MWV207REG_CURSOR_FOREGROUND_ResetValue                        0x00000000


#define MWV207REG_CURSOR_FOREGROUND_RED                                    23:16
#define MWV207REG_CURSOR_FOREGROUND_RED_End                                   23
#define MWV207REG_CURSOR_FOREGROUND_RED_Start                                 16
#define MWV207REG_CURSOR_FOREGROUND_RED_Type                                 U08


#define MWV207REG_CURSOR_FOREGROUND_GREEN                                   15:8
#define MWV207REG_CURSOR_FOREGROUND_GREEN_End                                 15
#define MWV207REG_CURSOR_FOREGROUND_GREEN_Start                                8
#define MWV207REG_CURSOR_FOREGROUND_GREEN_Type                               U08


#define MWV207REG_CURSOR_FOREGROUND_BLUE                                     7:0
#define MWV207REG_CURSOR_FOREGROUND_BLUE_End                                   7
#define MWV207REG_CURSOR_FOREGROUND_BLUE_Start                                 0
#define MWV207REG_CURSOR_FOREGROUND_BLUE_Type                                U08




#define mwv207regReservedRegAddrs                                         0x0157
#define MWV207REG_RESERVED_Address                                       0x0055C
#define MWV207REG_RESERVED_MSB                                                15
#define MWV207REG_RESERVED_LSB                                                 0
#define MWV207REG_RESERVED_BLK                                                 0
#define MWV207REG_RESERVED_Count                                               1
#define MWV207REG_RESERVED_FieldMask                                  0xFFFFFFFF
#define MWV207REG_RESERVED_ReadMask                                   0xFFFFFFFF
#define MWV207REG_RESERVED_WriteMask                                  0xFFFFFFFF
#define MWV207REG_RESERVED_ResetValue                                 0x00000000

#define MWV207REG_RESERVED_RESERVED                                         31:0
#define MWV207REG_RESERVED_RESERVED_End                                       31
#define MWV207REG_RESERVED_RESERVED_Start                                      0
#define MWV207REG_RESERVED_RESERVED_Type                                     U32




#define mwv207regReservedGroupRegAddrs                                    0x0158
#define MWV207REG_RESERVED_GROUP_Address                                 0x00560
#define MWV207REG_RESERVED_GROUP_MSB                                          15
#define MWV207REG_RESERVED_GROUP_LSB                                           3
#define MWV207REG_RESERVED_GROUP_BLK                                           3
#define MWV207REG_RESERVED_GROUP_Count                                         8
#define MWV207REG_RESERVED_GROUP_FieldMask                            0xFFFFFFFF
#define MWV207REG_RESERVED_GROUP_ReadMask                             0xFFFFFFFF
#define MWV207REG_RESERVED_GROUP_WriteMask                            0xFFFFFFFF
#define MWV207REG_RESERVED_GROUP_ResetValue                           0x00000000

#define MWV207REG_RESERVED_GROUP_RESERVED                                   31:0
#define MWV207REG_RESERVED_GROUP_RESERVED_End                                 31
#define MWV207REG_RESERVED_GROUP_RESERVED_Start                                0
#define MWV207REG_RESERVED_GROUP_RESERVED_Type                               U32

#define mwv207regDisplayIntrRegAddrs                                      0x0160
#define MWV207REG_DISPLAY_INTR_Address                                   0x00580
#define MWV207REG_DISPLAY_INTR_MSB                                            15
#define MWV207REG_DISPLAY_INTR_LSB                                             0
#define MWV207REG_DISPLAY_INTR_BLK                                             0
#define MWV207REG_DISPLAY_INTR_Count                                           1
#define MWV207REG_DISPLAY_INTR_FieldMask                              0x00003111
#define MWV207REG_DISPLAY_INTR_ReadMask                               0x00003111
#define MWV207REG_DISPLAY_INTR_WriteMask                              0x00003111
#define MWV207REG_DISPLAY_INTR_ResetValue                             0x00000000


#define MWV207REG_DISPLAY_INTR_DISP0                                         0:0
#define MWV207REG_DISPLAY_INTR_DISP0_End                                       0
#define MWV207REG_DISPLAY_INTR_DISP0_Start                                     0
#define MWV207REG_DISPLAY_INTR_DISP0_Type                                    U01


#define MWV207REG_DISPLAY_INTR_DISP1                                         4:4
#define MWV207REG_DISPLAY_INTR_DISP1_End                                       4
#define MWV207REG_DISPLAY_INTR_DISP1_Start                                     4
#define MWV207REG_DISPLAY_INTR_DISP1_Type                                    U01


#define MWV207REG_DISPLAY_INTR_CURSOR                                        8:8
#define MWV207REG_DISPLAY_INTR_CURSOR_End                                      8
#define MWV207REG_DISPLAY_INTR_CURSOR_Start                                    8
#define MWV207REG_DISPLAY_INTR_CURSOR_Type                                   U01


#define MWV207REG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR                         12:12
#define MWV207REG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR_End                        12
#define MWV207REG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR_Start                      12
#define MWV207REG_DISPLAY_INTR_DISP0_DBI_CFG_ERROR_Type                      U01


#define MWV207REG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR                         13:13
#define MWV207REG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR_End                        13
#define MWV207REG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR_Start                      13
#define MWV207REG_DISPLAY_INTR_DISP1_DBI_CFG_ERROR_Type                      U01



#define mwv207regDisplayIntrEnableRegAddrs                                0x0161
#define MWV207REG_DISPLAY_INTR_ENABLE_Address                            0x00584
#define MWV207REG_DISPLAY_INTR_ENABLE_MSB                                     15
#define MWV207REG_DISPLAY_INTR_ENABLE_LSB                                      0
#define MWV207REG_DISPLAY_INTR_ENABLE_BLK                                      0
#define MWV207REG_DISPLAY_INTR_ENABLE_Count                                    1
#define MWV207REG_DISPLAY_INTR_ENABLE_FieldMask                       0x00000011
#define MWV207REG_DISPLAY_INTR_ENABLE_ReadMask                        0x00000011
#define MWV207REG_DISPLAY_INTR_ENABLE_WriteMask                       0x00000011
#define MWV207REG_DISPLAY_INTR_ENABLE_ResetValue                      0x00000000


#define MWV207REG_DISPLAY_INTR_ENABLE_DISP0                                  0:0
#define MWV207REG_DISPLAY_INTR_ENABLE_DISP0_End                                0
#define MWV207REG_DISPLAY_INTR_ENABLE_DISP0_Start                              0
#define MWV207REG_DISPLAY_INTR_ENABLE_DISP0_Type                             U01


#define MWV207REG_DISPLAY_INTR_ENABLE_DISP1                                  4:4
#define MWV207REG_DISPLAY_INTR_ENABLE_DISP1_End                                4
#define MWV207REG_DISPLAY_INTR_ENABLE_DISP1_Start                              4
#define MWV207REG_DISPLAY_INTR_ENABLE_DISP1_Type                             U01




#define mwv207regDbiConfigRegAddrs                                        0x0162
#define MWV207REG_DBI_CONFIG_Address                                     0x00588
#define MWV207REG_DBI_CONFIG_MSB                                              15
#define MWV207REG_DBI_CONFIG_LSB                                               1
#define MWV207REG_DBI_CONFIG_BLK                                               1
#define MWV207REG_DBI_CONFIG_Count                                             2
#define MWV207REG_DBI_CONFIG_FieldMask                                0x00003FFF
#define MWV207REG_DBI_CONFIG_ReadMask                                 0x00003FFF
#define MWV207REG_DBI_CONFIG_WriteMask                                0x00003FFF
#define MWV207REG_DBI_CONFIG_ResetValue                               0x00000000


#define MWV207REG_DBI_CONFIG_DBI_TYPEC_OPT                                 13:12
#define MWV207REG_DBI_CONFIG_DBI_TYPEC_OPT_End                                13
#define MWV207REG_DBI_CONFIG_DBI_TYPEC_OPT_Start                              12
#define MWV207REG_DBI_CONFIG_DBI_TYPEC_OPT_Type                              U02


#define MWV207REG_DBI_CONFIG_DBI_AC_TIME_UNIT                               11:8
#define MWV207REG_DBI_CONFIG_DBI_AC_TIME_UNIT_End                             11
#define MWV207REG_DBI_CONFIG_DBI_AC_TIME_UNIT_Start                            8
#define MWV207REG_DBI_CONFIG_DBI_AC_TIME_UNIT_Type                           U04


#define MWV207REG_DBI_CONFIG_DBIX_POLARITY                                   7:7
#define MWV207REG_DBI_CONFIG_DBIX_POLARITY_End                                 7
#define MWV207REG_DBI_CONFIG_DBIX_POLARITY_Start                               7
#define MWV207REG_DBI_CONFIG_DBIX_POLARITY_Type                              U01
#define   MWV207REG_DBI_CONFIG_DBIX_POLARITY_DEFAULT                         0x0
#define   MWV207REG_DBI_CONFIG_DBIX_POLARITY_REVERSE                         0x1


#define MWV207REG_DBI_CONFIG_BUS_OUTPUT_SEL                                  6:6
#define MWV207REG_DBI_CONFIG_BUS_OUTPUT_SEL_End                                6
#define MWV207REG_DBI_CONFIG_BUS_OUTPUT_SEL_Start                              6
#define MWV207REG_DBI_CONFIG_BUS_OUTPUT_SEL_Type                             U01
#define   MWV207REG_DBI_CONFIG_BUS_OUTPUT_SEL_DPI                            0x0
#define   MWV207REG_DBI_CONFIG_BUS_OUTPUT_SEL_DBI                            0x1

#define MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT                                 5:2
#define MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_End                               5
#define MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_Start                             2
#define MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_Type                            U04
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D8R3G3B2                      0x0
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D8R4G4B4                      0x1
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D8R5G6B5                      0x2
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D8R6G6B6                      0x3
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D8R8G8B8                      0x4
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D9R6G6B6                      0x5
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D16R3G3B2                     0x6
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D16R4G4B4                     0x7
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D16R5G6B5                     0x8
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R6_G6_B6_OP1              0x9
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R6_G6_B6_OP2              0xA
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R8_G8_B8_OP1              0xB
#define   MWV207REG_DBI_CONFIG_DBI_DATA_FORMAT_D16_R8_G8_B8_OP2              0xC


#define MWV207REG_DBI_CONFIG_DBI_TYPE                                        1:0
#define MWV207REG_DBI_CONFIG_DBI_TYPE_End                                      1
#define MWV207REG_DBI_CONFIG_DBI_TYPE_Start                                    0
#define MWV207REG_DBI_CONFIG_DBI_TYPE_Type                                   U02
#define   MWV207REG_DBI_CONFIG_DBI_TYPE_TYPE_AFIXED_E                        0x0
#define   MWV207REG_DBI_CONFIG_DBI_TYPE_TYPE_ACLOCK_E                        0x1
#define   MWV207REG_DBI_CONFIG_DBI_TYPE_TYPE_B                               0x2
#define   MWV207REG_DBI_CONFIG_DBI_TYPE_TYPE_C                               0x3




#define mwv207regDbiIfResetRegAddrs                                       0x0164
#define MWV207REG_DBI_IF_RESET_Address                                   0x00590
#define MWV207REG_DBI_IF_RESET_MSB                                            15
#define MWV207REG_DBI_IF_RESET_LSB                                             1
#define MWV207REG_DBI_IF_RESET_BLK                                             1
#define MWV207REG_DBI_IF_RESET_Count                                           2
#define MWV207REG_DBI_IF_RESET_FieldMask                              0x00000001
#define MWV207REG_DBI_IF_RESET_ReadMask                               0x00000000
#define MWV207REG_DBI_IF_RESET_WriteMask                              0x00000001
#define MWV207REG_DBI_IF_RESET_ResetValue                             0x00000000

#define MWV207REG_DBI_IF_RESET_DBI_IF_LEVEL_RESET                            0:0
#define MWV207REG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_End                          0
#define MWV207REG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_Start                        0
#define MWV207REG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_Type                       U01
#define   MWV207REG_DBI_IF_RESET_DBI_IF_LEVEL_RESET_RESET                    0x1




#define mwv207regDbiWrChar1RegAddrs                                       0x0166
#define MWV207REG_DBI_WR_CHAR1_Address                                   0x00598
#define MWV207REG_DBI_WR_CHAR1_MSB                                            15
#define MWV207REG_DBI_WR_CHAR1_LSB                                             1
#define MWV207REG_DBI_WR_CHAR1_BLK                                             1
#define MWV207REG_DBI_WR_CHAR1_Count                                           2
#define MWV207REG_DBI_WR_CHAR1_FieldMask                              0x0000FFFF
#define MWV207REG_DBI_WR_CHAR1_ReadMask                               0x0000FFFF
#define MWV207REG_DBI_WR_CHAR1_WriteMask                              0x0000FFFF
#define MWV207REG_DBI_WR_CHAR1_ResetValue                             0x00000000

#define MWV207REG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT                            15:12
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT_End                           15
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT_Start                         12
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_CS_ASSERT_Type                         U04

#define MWV207REG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT                         11:8
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT_End                       11
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT_Start                      8
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_EOR_WR_ASSERT_Type                     U04

#define MWV207REG_DBI_WR_CHAR1_DBI_WR_PERIOD                                 7:0
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_PERIOD_End                               7
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_PERIOD_Start                             0
#define MWV207REG_DBI_WR_CHAR1_DBI_WR_PERIOD_Type                            U08




#define mwv207regDbiWrChar2RegAddrs                                       0x0168
#define MWV207REG_DBI_WR_CHAR2_Address                                   0x005A0
#define MWV207REG_DBI_WR_CHAR2_MSB                                            15
#define MWV207REG_DBI_WR_CHAR2_LSB                                             1
#define MWV207REG_DBI_WR_CHAR2_BLK                                             1
#define MWV207REG_DBI_WR_CHAR2_Count                                           2
#define MWV207REG_DBI_WR_CHAR2_FieldMask                              0x0000FFFF
#define MWV207REG_DBI_WR_CHAR2_ReadMask                               0x0000FFFF
#define MWV207REG_DBI_WR_CHAR2_WriteMask                              0x0000FFFF
#define MWV207REG_DBI_WR_CHAR2_ResetValue                             0x00000000

#define MWV207REG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT                            15:8
#define MWV207REG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT_End                          15
#define MWV207REG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT_Start                         8
#define MWV207REG_DBI_WR_CHAR2_DBI_WR_CS_DE_ASRT_Type                        U08

#define MWV207REG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT                         7:0
#define MWV207REG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT_End                       7
#define MWV207REG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT_Start                     0
#define MWV207REG_DBI_WR_CHAR2_DBI_WR_EOR_WR_DE_ASRT_Type                    U08




#define mwv207regDbiCmdRegAddrs                                           0x016A
#define MWV207REG_DBI_CMD_Address                                        0x005A8
#define MWV207REG_DBI_CMD_MSB                                                 15
#define MWV207REG_DBI_CMD_LSB                                                  1
#define MWV207REG_DBI_CMD_BLK                                                  1
#define MWV207REG_DBI_CMD_Count                                                2
#define MWV207REG_DBI_CMD_FieldMask                                   0xC000FFFF
#define MWV207REG_DBI_CMD_ReadMask                                    0x00000000
#define MWV207REG_DBI_CMD_WriteMask                                   0xC000FFFF
#define MWV207REG_DBI_CMD_ResetValue                                  0x00000000


#define MWV207REG_DBI_CMD_DBI_COMMANDFLAG                                  31:30
#define MWV207REG_DBI_CMD_DBI_COMMANDFLAG_End                                 31
#define MWV207REG_DBI_CMD_DBI_COMMANDFLAG_Start                               30
#define MWV207REG_DBI_CMD_DBI_COMMANDFLAG_Type                               U02
#define   MWV207REG_DBI_CMD_DBI_COMMANDFLAG_ADDRESS                          0x0
#define   MWV207REG_DBI_CMD_DBI_COMMANDFLAG_WRITE_MEM_START                  0x1
#define   MWV207REG_DBI_CMD_DBI_COMMANDFLAG_PARAMETER_OR_DATA                0x2
#define   MWV207REG_DBI_CMD_DBI_COMMANDFLAG_READ                             0x3


#define MWV207REG_DBI_CMD_DBI_COMMAND_WORD                                  15:0
#define MWV207REG_DBI_CMD_DBI_COMMAND_WORD_End                                15
#define MWV207REG_DBI_CMD_DBI_COMMAND_WORD_Start                               0
#define MWV207REG_DBI_CMD_DBI_COMMAND_WORD_Type                              U16




#define mwv207regDpiConfigRegAddrs                                        0x016C
#define MWV207REG_DPI_CONFIG_Address                                     0x005B0
#define MWV207REG_DPI_CONFIG_MSB                                              15
#define MWV207REG_DPI_CONFIG_LSB                                               1
#define MWV207REG_DPI_CONFIG_BLK                                               1
#define MWV207REG_DPI_CONFIG_Count                                             2
#define MWV207REG_DPI_CONFIG_FieldMask                                0x00000007
#define MWV207REG_DPI_CONFIG_ReadMask                                 0x00000007
#define MWV207REG_DPI_CONFIG_WriteMask                                0x00000007
#define MWV207REG_DPI_CONFIG_ResetValue                               0x00000000

#define MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT                                 2:0
#define MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_End                               2
#define MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_Start                             0
#define MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_Type                            U03
#define   MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_D16CFG1                       0x0
#define   MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_D16CFG2                       0x1
#define   MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_D16CFG3                       0x2
#define   MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_D18CFG1                       0x3
#define   MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_D18CFG2                       0x4
#define   MWV207REG_DPI_CONFIG_DPI_DATA_FORMAT_D24                           0x5



#define mwv207regDcChipIdRegAddrs                                         0x016E
#define MWV207REG_DC_CHIP_ID_Address                                     0x005B8
#define MWV207REG_DC_CHIP_ID_MSB                                              15
#define MWV207REG_DC_CHIP_ID_LSB                                               0
#define MWV207REG_DC_CHIP_ID_BLK                                               0
#define MWV207REG_DC_CHIP_ID_Count                                             1
#define MWV207REG_DC_CHIP_ID_FieldMask                                0xFFFFFFFF
#define MWV207REG_DC_CHIP_ID_ReadMask                                 0xFFFFFFFF
#define MWV207REG_DC_CHIP_ID_WriteMask                                0x00000000
#define MWV207REG_DC_CHIP_ID_ResetValue                               0x00000000


#define MWV207REG_DC_CHIP_ID_ID                                             31:0
#define MWV207REG_DC_CHIP_ID_ID_End                                           31
#define MWV207REG_DC_CHIP_ID_ID_Start                                          0
#define MWV207REG_DC_CHIP_ID_ID_Type                                         U32



#define mwv207regDcChipRevRegAddrs                                        0x016F
#define MWV207REG_DC_CHIP_REV_Address                                    0x005BC
#define MWV207REG_DC_CHIP_REV_MSB                                             15
#define MWV207REG_DC_CHIP_REV_LSB                                              0
#define MWV207REG_DC_CHIP_REV_BLK                                              0
#define MWV207REG_DC_CHIP_REV_Count                                            1
#define MWV207REG_DC_CHIP_REV_FieldMask                               0xFFFFFFFF
#define MWV207REG_DC_CHIP_REV_ReadMask                                0xFFFFFFFF
#define MWV207REG_DC_CHIP_REV_WriteMask                               0x00000000
#define MWV207REG_DC_CHIP_REV_ResetValue                              0x00000000


#define MWV207REG_DC_CHIP_REV_REV                                           31:0
#define MWV207REG_DC_CHIP_REV_REV_End                                         31
#define MWV207REG_DC_CHIP_REV_REV_Start                                        0
#define MWV207REG_DC_CHIP_REV_REV_Type                                       U32



#define mwv207regDcChipDateRegAddrs                                       0x0170
#define MWV207REG_DC_CHIP_DATE_Address                                   0x005C0
#define MWV207REG_DC_CHIP_DATE_MSB                                            15
#define MWV207REG_DC_CHIP_DATE_LSB                                             0
#define MWV207REG_DC_CHIP_DATE_BLK                                             0
#define MWV207REG_DC_CHIP_DATE_Count                                           1
#define MWV207REG_DC_CHIP_DATE_FieldMask                              0xFFFFFFFF
#define MWV207REG_DC_CHIP_DATE_ReadMask                               0xFFFFFFFF
#define MWV207REG_DC_CHIP_DATE_WriteMask                              0x00000000
#define MWV207REG_DC_CHIP_DATE_ResetValue                             0x00000000


#define MWV207REG_DC_CHIP_DATE_DATE                                         31:0
#define MWV207REG_DC_CHIP_DATE_DATE_End                                       31
#define MWV207REG_DC_CHIP_DATE_DATE_Start                                      0
#define MWV207REG_DC_CHIP_DATE_DATE_Type                                     U32



#define mwv207regDcChipTimeRegAddrs                                       0x0171
#define MWV207REG_DC_CHIP_TIME_Address                                   0x005C4
#define MWV207REG_DC_CHIP_TIME_MSB                                            15
#define MWV207REG_DC_CHIP_TIME_LSB                                             0
#define MWV207REG_DC_CHIP_TIME_BLK                                             0
#define MWV207REG_DC_CHIP_TIME_Count                                           1
#define MWV207REG_DC_CHIP_TIME_FieldMask                              0xFFFFFFFF
#define MWV207REG_DC_CHIP_TIME_ReadMask                               0xFFFFFFFF
#define MWV207REG_DC_CHIP_TIME_WriteMask                              0x00000000
#define MWV207REG_DC_CHIP_TIME_ResetValue                             0x00000000


#define MWV207REG_DC_CHIP_TIME_TIME                                         31:0
#define MWV207REG_DC_CHIP_TIME_TIME_End                                       31
#define MWV207REG_DC_CHIP_TIME_TIME_Start                                      0
#define MWV207REG_DC_CHIP_TIME_TIME_Type                                     U32




#define mwv207regDcChipPatchRevRegAddrs                                   0x0172
#define MWV207REG_DC_CHIP_PATCH_REV_Address                              0x005C8
#define MWV207REG_DC_CHIP_PATCH_REV_MSB                                       15
#define MWV207REG_DC_CHIP_PATCH_REV_LSB                                        0
#define MWV207REG_DC_CHIP_PATCH_REV_BLK                                        0
#define MWV207REG_DC_CHIP_PATCH_REV_Count                                      1
#define MWV207REG_DC_CHIP_PATCH_REV_FieldMask                         0xFFFFFFFF
#define MWV207REG_DC_CHIP_PATCH_REV_ReadMask                          0xFFFFFFFF
#define MWV207REG_DC_CHIP_PATCH_REV_WriteMask                         0x00000000
#define MWV207REG_DC_CHIP_PATCH_REV_ResetValue                        0x00000000


#define MWV207REG_DC_CHIP_PATCH_REV_PATCH_REV                               31:0
#define MWV207REG_DC_CHIP_PATCH_REV_PATCH_REV_End                             31
#define MWV207REG_DC_CHIP_PATCH_REV_PATCH_REV_Start                            0
#define MWV207REG_DC_CHIP_PATCH_REV_PATCH_REV_Type                           U32




#define mwv207regReserved1RegAddrs                                        0x0173
#define MWV207REG_RESERVED1_Address                                      0x005CC
#define MWV207REG_RESERVED1_MSB                                               15
#define MWV207REG_RESERVED1_LSB                                                0
#define MWV207REG_RESERVED1_BLK                                                0
#define MWV207REG_RESERVED1_Count                                              1
#define MWV207REG_RESERVED1_FieldMask                                 0xFFFFFFFF
#define MWV207REG_RESERVED1_ReadMask                                  0xFFFFFFFF
#define MWV207REG_RESERVED1_WriteMask                                 0xFFFFFFFF
#define MWV207REG_RESERVED1_ResetValue                                0x00000000

#define MWV207REG_RESERVED1_RESERVED                                        31:0
#define MWV207REG_RESERVED1_RESERVED_End                                      31
#define MWV207REG_RESERVED1_RESERVED_Start                                     0
#define MWV207REG_RESERVED1_RESERVED_Type                                    U32




#define mwv207regDcTileInCfgRegAddrs                                      0x0174
#define MWV207REG_DC_TILE_IN_CFG_Address                                 0x005D0
#define MWV207REG_DC_TILE_IN_CFG_MSB                                          15
#define MWV207REG_DC_TILE_IN_CFG_LSB                                           1
#define MWV207REG_DC_TILE_IN_CFG_BLK                                           1
#define MWV207REG_DC_TILE_IN_CFG_Count                                         2
#define MWV207REG_DC_TILE_IN_CFG_FieldMask                            0x0000003F
#define MWV207REG_DC_TILE_IN_CFG_ReadMask                             0x0000003F
#define MWV207REG_DC_TILE_IN_CFG_WriteMask                            0x0000003F
#define MWV207REG_DC_TILE_IN_CFG_ResetValue                           0x00000000


#define MWV207REG_DC_TILE_IN_CFG_CFG_MODE_EN                                 5:5
#define MWV207REG_DC_TILE_IN_CFG_CFG_MODE_EN_End                               5
#define MWV207REG_DC_TILE_IN_CFG_CFG_MODE_EN_Start                             5
#define MWV207REG_DC_TILE_IN_CFG_CFG_MODE_EN_Type                            U01
#define   MWV207REG_DC_TILE_IN_CFG_CFG_MODE_EN_DISABLE                       0x0
#define   MWV207REG_DC_TILE_IN_CFG_CFG_MODE_EN_ENABLE                        0x1


#define MWV207REG_DC_TILE_IN_CFG_YUV2_RGB_EN                                 4:4
#define MWV207REG_DC_TILE_IN_CFG_YUV2_RGB_EN_End                               4
#define MWV207REG_DC_TILE_IN_CFG_YUV2_RGB_EN_Start                             4
#define MWV207REG_DC_TILE_IN_CFG_YUV2_RGB_EN_Type                            U01
#define   MWV207REG_DC_TILE_IN_CFG_YUV2_RGB_EN_DISABLE                       0x0
#define   MWV207REG_DC_TILE_IN_CFG_YUV2_RGB_EN_ENABLE                        0x1


#define MWV207REG_DC_TILE_IN_CFG_YUV_STANDARD                                3:2
#define MWV207REG_DC_TILE_IN_CFG_YUV_STANDARD_End                              3
#define MWV207REG_DC_TILE_IN_CFG_YUV_STANDARD_Start                            2
#define MWV207REG_DC_TILE_IN_CFG_YUV_STANDARD_Type                           U02
#define   MWV207REG_DC_TILE_IN_CFG_YUV_STANDARD_BT601                        0x0
#define   MWV207REG_DC_TILE_IN_CFG_YUV_STANDARD_BT709                        0x1

#define MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT                                 1:0
#define MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT_End                               1
#define MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT_Start                             0
#define MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT_Type                            U02
#define   MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT_NONE                          0x0
#define   MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT_ARGB8888                      0x1
#define   MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT_YUY2                          0x2
#define   MWV207REG_DC_TILE_IN_CFG_TILE_FORMAT_NV12                          0x3



#define mwv207regDcTileUvFrameBufferAdrRegAddrs                           0x0176
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_Address                    0x005D8
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_MSB                             15
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_LSB                              1
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_BLK                              1
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_Count                            2
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_FieldMask               0xFFFFFFFF
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_ReadMask                0xFFFFFFFF
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_WriteMask               0xFFFFFFFF
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_ResetValue              0x00000000


#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS                       31:0
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS_End                     31
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS_Start                    0
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_ADR_ADDRESS_Type                   U32



#define mwv207regDcTileUvFrameBufferStrRegAddrs                           0x0178
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_Address                    0x005E0
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_MSB                             15
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_LSB                              1
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_BLK                              1
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_Count                            2
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_FieldMask               0x0000FFFF
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_ReadMask                0x0000FFFF
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_WriteMask               0x0000FFFF
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_ResetValue              0x00000000


#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE                        15:0
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE_End                      15
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE_Start                     0
#define MWV207REG_DC_TILE_UV_FRAME_BUFFER_STR_STRIDE_Type                    U16




#define mwv207regDcChipInfoRegAddrs                                       0x017A
#define MWV207REG_DC_CHIP_INFO_Address                                   0x005E8
#define MWV207REG_DC_CHIP_INFO_MSB                                            15
#define MWV207REG_DC_CHIP_INFO_LSB                                             0
#define MWV207REG_DC_CHIP_INFO_BLK                                             0
#define MWV207REG_DC_CHIP_INFO_Count                                           1
#define MWV207REG_DC_CHIP_INFO_FieldMask                              0xFFFFFFFF
#define MWV207REG_DC_CHIP_INFO_ReadMask                               0xFFFFFFFF
#define MWV207REG_DC_CHIP_INFO_WriteMask                              0x00000000
#define MWV207REG_DC_CHIP_INFO_ResetValue                             0x00000000


#define MWV207REG_DC_CHIP_INFO_CHIP_INFO                                    31:0
#define MWV207REG_DC_CHIP_INFO_CHIP_INFO_End                                  31
#define MWV207REG_DC_CHIP_INFO_CHIP_INFO_Start                                 0
#define MWV207REG_DC_CHIP_INFO_CHIP_INFO_Type                                U32




#define mwv207regDcProductIdRegAddrs                                      0x017B
#define MWV207REG_DC_PRODUCT_ID_Address                                  0x005EC
#define MWV207REG_DC_PRODUCT_ID_MSB                                           15
#define MWV207REG_DC_PRODUCT_ID_LSB                                            0
#define MWV207REG_DC_PRODUCT_ID_BLK                                            0
#define MWV207REG_DC_PRODUCT_ID_Count                                          1
#define MWV207REG_DC_PRODUCT_ID_FieldMask                             0xFFFFFFFF
#define MWV207REG_DC_PRODUCT_ID_ReadMask                              0xFFFFFFFF
#define MWV207REG_DC_PRODUCT_ID_WriteMask                             0x00000000
#define MWV207REG_DC_PRODUCT_ID_ResetValue                            0x00000000


#define MWV207REG_DC_PRODUCT_ID_PRODUCT_ID                                  31:0
#define MWV207REG_DC_PRODUCT_ID_PRODUCT_ID_End                                31
#define MWV207REG_DC_PRODUCT_ID_PRODUCT_ID_Start                               0
#define MWV207REG_DC_PRODUCT_ID_PRODUCT_ID_Type                              U32




#define mwv207regDcEcoIdRegAddrs                                          0x017C
#define MWV207REG_DC_ECO_ID_Address                                      0x005F0
#define MWV207REG_DC_ECO_ID_MSB                                               15
#define MWV207REG_DC_ECO_ID_LSB                                                0
#define MWV207REG_DC_ECO_ID_BLK                                                0
#define MWV207REG_DC_ECO_ID_Count                                              1
#define MWV207REG_DC_ECO_ID_FieldMask                                 0xFFFFFFFF
#define MWV207REG_DC_ECO_ID_ReadMask                                  0xFFFFFFFF
#define MWV207REG_DC_ECO_ID_WriteMask                                 0x00000000
#define MWV207REG_DC_ECO_ID_ResetValue                                0x00000000


#define MWV207REG_DC_ECO_ID_ID                                              31:0
#define MWV207REG_DC_ECO_ID_ID_End                                            31
#define MWV207REG_DC_ECO_ID_ID_Start                                           0
#define MWV207REG_DC_ECO_ID_ID_Type                                          U32




#define mwv207regDbiTypecCfgRegAddrs                                      0x017E
#define MWV207REG_DBI_TYPEC_CFG_Address                                  0x005F8
#define MWV207REG_DBI_TYPEC_CFG_MSB                                           15
#define MWV207REG_DBI_TYPEC_CFG_LSB                                            1
#define MWV207REG_DBI_TYPEC_CFG_BLK                                            1
#define MWV207REG_DBI_TYPEC_CFG_Count                                          2
#define MWV207REG_DBI_TYPEC_CFG_FieldMask                             0x001FFFFF
#define MWV207REG_DBI_TYPEC_CFG_ReadMask                              0x001FFFFF
#define MWV207REG_DBI_TYPEC_CFG_WriteMask                             0x001FFFFF
#define MWV207REG_DBI_TYPEC_CFG_ResetValue                            0x00000000

#define MWV207REG_DBI_TYPEC_CFG_SCL_SEL                                    20:20
#define MWV207REG_DBI_TYPEC_CFG_SCL_SEL_End                                   20
#define MWV207REG_DBI_TYPEC_CFG_SCL_SEL_Start                                 20
#define MWV207REG_DBI_TYPEC_CFG_SCL_SEL_Type                                 U01
#define   MWV207REG_DBI_TYPEC_CFG_SCL_SEL_DIVIDED_SDA_CLK                    0x0
#define   MWV207REG_DBI_TYPEC_CFG_SCL_SEL_SDA_CLK                            0x1

#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRH                                   19:12
#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRH_End                                  19
#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRH_Start                                12
#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRH_Type                                U08

#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRL                                    11:4
#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRL_End                                  11
#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRL_Start                                 4
#define MWV207REG_DBI_TYPEC_CFG_SCL_TWRL_Type                                U08

#define MWV207REG_DBI_TYPEC_CFG_TAS                                          3:0
#define MWV207REG_DBI_TYPEC_CFG_TAS_End                                        3
#define MWV207REG_DBI_TYPEC_CFG_TAS_Start                                      0
#define MWV207REG_DBI_TYPEC_CFG_TAS_Type                                     U04

#define mwv207regDCStatusRegAddrs                                         0x0180
#define MWV207REG_DC_STATUS_Address                                      0x00600
#define MWV207REG_DC_STATUS_MSB                                               15
#define MWV207REG_DC_STATUS_LSB                                                1
#define MWV207REG_DC_STATUS_BLK                                                1
#define MWV207REG_DC_STATUS_Count                                              2
#define MWV207REG_DC_STATUS_FieldMask                                 0x00000001
#define MWV207REG_DC_STATUS_ReadMask                                  0x00000001
#define MWV207REG_DC_STATUS_WriteMask                                 0x00000001
#define MWV207REG_DC_STATUS_ResetValue                                0x00000000


#define MWV207REG_DC_STATUS_DBI_TYPEC_FIFO_FULL                              0:0
#define MWV207REG_DC_STATUS_DBI_TYPEC_FIFO_FULL_End                            0
#define MWV207REG_DC_STATUS_DBI_TYPEC_FIFO_FULL_Start                          0
#define MWV207REG_DC_STATUS_DBI_TYPEC_FIFO_FULL_Type                         U01

#define mwv207regDebugCounterSelectRegAddrs                               0x0182
#define MWV207REG_DEBUG_COUNTER_SELECT_Address                           0x00608
#define MWV207REG_DEBUG_COUNTER_SELECT_MSB                                    15
#define MWV207REG_DEBUG_COUNTER_SELECT_LSB                                     1
#define MWV207REG_DEBUG_COUNTER_SELECT_BLK                                     1
#define MWV207REG_DEBUG_COUNTER_SELECT_Count                                   2
#define MWV207REG_DEBUG_COUNTER_SELECT_FieldMask                      0x000000FF
#define MWV207REG_DEBUG_COUNTER_SELECT_ReadMask                       0x000000FF
#define MWV207REG_DEBUG_COUNTER_SELECT_WriteMask                      0x000000FF
#define MWV207REG_DEBUG_COUNTER_SELECT_ResetValue                     0x00000000

#define MWV207REG_DEBUG_COUNTER_SELECT_SELECT                                7:0
#define MWV207REG_DEBUG_COUNTER_SELECT_SELECT_End                              7
#define MWV207REG_DEBUG_COUNTER_SELECT_SELECT_Start                            0
#define MWV207REG_DEBUG_COUNTER_SELECT_SELECT_Type                           U08
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_RD_REQ_CNT        0x00
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_RD_LAST_CNT       0x01
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_REQ_BURST_CNT     0x02
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_AXI_RD_BURST_CUNT     0x03
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_PIXEL_CNT             0x04
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_FRAME_CNT             0x05
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_INPUT_DBI_CMD_CNT     0x06
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_TOTAL_OUTPUT_DBI_CMD_CNT    0x07
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_DEBUG_SIGNALS0              0x08
#define   MWV207REG_DEBUG_COUNTER_SELECT_SELECT_RESET_ALL_DEBUG_COUNTERS    0xFF

#define mwv207regDebugCounterValueRegAddrs                                0x0184
#define MWV207REG_DEBUG_COUNTER_VALUE_Address                            0x00610
#define MWV207REG_DEBUG_COUNTER_VALUE_MSB                                     15
#define MWV207REG_DEBUG_COUNTER_VALUE_LSB                                      1
#define MWV207REG_DEBUG_COUNTER_VALUE_BLK                                      1
#define MWV207REG_DEBUG_COUNTER_VALUE_Count                                    2
#define MWV207REG_DEBUG_COUNTER_VALUE_FieldMask                       0xFFFFFFFF
#define MWV207REG_DEBUG_COUNTER_VALUE_ReadMask                        0xFFFFFFFF
#define MWV207REG_DEBUG_COUNTER_VALUE_WriteMask                       0xFFFFFFFF
#define MWV207REG_DEBUG_COUNTER_VALUE_ResetValue                      0x00000000


#define MWV207REG_DEBUG_COUNTER_VALUE_VALUE                                 31:0
#define MWV207REG_DEBUG_COUNTER_VALUE_VALUE_End                               31
#define MWV207REG_DEBUG_COUNTER_VALUE_VALUE_Start                              0
#define MWV207REG_DEBUG_COUNTER_VALUE_VALUE_Type                             U32


#endif


