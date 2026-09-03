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




#ifndef __AQSetupReg_h__
#define __AQSetupReg_h__





#define AQSetupClipLeftRegAddrs                                           0x0300
#define AQ_SETUP_CLIP_LEFT_Address                                       0x00C00
#define AQ_SETUP_CLIP_LEFT_MSB                                                15
#define AQ_SETUP_CLIP_LEFT_LSB                                                 0
#define AQ_SETUP_CLIP_LEFT_BLK                                                 0
#define AQ_SETUP_CLIP_LEFT_Count                                               1
#define AQ_SETUP_CLIP_LEFT_FieldMask                                  0xFFFFFFFF
#define AQ_SETUP_CLIP_LEFT_ReadMask                                   0xFFFFFFFF
#define AQ_SETUP_CLIP_LEFT_WriteMask                                  0xFFFFFFFF
#define AQ_SETUP_CLIP_LEFT_ResetValue                                 0x00000000


#define AQ_SETUP_CLIP_LEFT_CLIP                                             31:0
#define AQ_SETUP_CLIP_LEFT_CLIP_End                                           31
#define AQ_SETUP_CLIP_LEFT_CLIP_Start                                          0
#define AQ_SETUP_CLIP_LEFT_CLIP_Type                                         U32




#define AQSetupClipTopRegAddrs                                            0x0301
#define AQ_SETUP_CLIP_TOP_Address                                        0x00C04
#define AQ_SETUP_CLIP_TOP_MSB                                                 15
#define AQ_SETUP_CLIP_TOP_LSB                                                  0
#define AQ_SETUP_CLIP_TOP_BLK                                                  0
#define AQ_SETUP_CLIP_TOP_Count                                                1
#define AQ_SETUP_CLIP_TOP_FieldMask                                   0xFFFFFFFF
#define AQ_SETUP_CLIP_TOP_ReadMask                                    0xFFFFFFFF
#define AQ_SETUP_CLIP_TOP_WriteMask                                   0xFFFFFFFF
#define AQ_SETUP_CLIP_TOP_ResetValue                                  0x00000000


#define AQ_SETUP_CLIP_TOP_CLIP                                              31:0
#define AQ_SETUP_CLIP_TOP_CLIP_End                                            31
#define AQ_SETUP_CLIP_TOP_CLIP_Start                                           0
#define AQ_SETUP_CLIP_TOP_CLIP_Type                                          U32




#define AQSetupClipRightRegAddrs                                          0x0302
#define AQ_SETUP_CLIP_RIGHT_Address                                      0x00C08
#define AQ_SETUP_CLIP_RIGHT_MSB                                               15
#define AQ_SETUP_CLIP_RIGHT_LSB                                                0
#define AQ_SETUP_CLIP_RIGHT_BLK                                                0
#define AQ_SETUP_CLIP_RIGHT_Count                                              1
#define AQ_SETUP_CLIP_RIGHT_FieldMask                                 0xFFFFFFFF
#define AQ_SETUP_CLIP_RIGHT_ReadMask                                  0xFFFFFFFF
#define AQ_SETUP_CLIP_RIGHT_WriteMask                                 0xFFFFFFFF
#define AQ_SETUP_CLIP_RIGHT_ResetValue                                0x45000000

#define AQ_SETUP_CLIP_RIGHT_CLIP                                            31:0
#define AQ_SETUP_CLIP_RIGHT_CLIP_End                                          31
#define AQ_SETUP_CLIP_RIGHT_CLIP_Start                                         0
#define AQ_SETUP_CLIP_RIGHT_CLIP_Type                                        U32




#define AQSetupClipBottomRegAddrs                                         0x0303
#define AQ_SETUP_CLIP_BOTTOM_Address                                     0x00C0C
#define AQ_SETUP_CLIP_BOTTOM_MSB                                              15
#define AQ_SETUP_CLIP_BOTTOM_LSB                                               0
#define AQ_SETUP_CLIP_BOTTOM_BLK                                               0
#define AQ_SETUP_CLIP_BOTTOM_Count                                             1
#define AQ_SETUP_CLIP_BOTTOM_FieldMask                                0xFFFFFFFF
#define AQ_SETUP_CLIP_BOTTOM_ReadMask                                 0xFFFFFFFF
#define AQ_SETUP_CLIP_BOTTOM_WriteMask                                0xFFFFFFFF
#define AQ_SETUP_CLIP_BOTTOM_ResetValue                               0x45000000

#define AQ_SETUP_CLIP_BOTTOM_CLIP                                           31:0
#define AQ_SETUP_CLIP_BOTTOM_CLIP_End                                         31
#define AQ_SETUP_CLIP_BOTTOM_CLIP_Start                                        0
#define AQ_SETUP_CLIP_BOTTOM_CLIP_Type                                       U32




#define AQSetupSlopeScaledDepthBiasRegAddrs                               0x0304
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_Address                         0x00C10
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_MSB                                  15
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_LSB                                   0
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_BLK                                   0
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_Count                                 1
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_FieldMask                    0xFFFFFFFF
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_ReadMask                     0xFFFFFFFF
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_WriteMask                    0xFFFFFFFF
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_ResetValue                   0x00000000

#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_BIAS                               31:0
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_BIAS_End                             31
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_BIAS_Start                            0
#define AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS_BIAS_Type                           U32




#define AQSetupDepthBiasRegAddrs                                          0x0305
#define AQ_SETUP_DEPTH_BIAS_Address                                      0x00C14
#define AQ_SETUP_DEPTH_BIAS_MSB                                               15
#define AQ_SETUP_DEPTH_BIAS_LSB                                                0
#define AQ_SETUP_DEPTH_BIAS_BLK                                                0
#define AQ_SETUP_DEPTH_BIAS_Count                                              1
#define AQ_SETUP_DEPTH_BIAS_FieldMask                                 0xFFFFFFFF
#define AQ_SETUP_DEPTH_BIAS_ReadMask                                  0xFFFFFFFF
#define AQ_SETUP_DEPTH_BIAS_WriteMask                                 0xFFFFFFFF
#define AQ_SETUP_DEPTH_BIAS_ResetValue                                0x00000000

#define AQ_SETUP_DEPTH_BIAS_BIAS                                            31:0
#define AQ_SETUP_DEPTH_BIAS_BIAS_End                                          31
#define AQ_SETUP_DEPTH_BIAS_BIAS_Start                                         0
#define AQ_SETUP_DEPTH_BIAS_BIAS_Type                                        U32




#define AQSetupConfigRegAddrs                                             0x0306
#define AQ_SETUP_CONFIG_Address                                          0x00C18
#define AQ_SETUP_CONFIG_MSB                                                   15
#define AQ_SETUP_CONFIG_LSB                                                    0
#define AQ_SETUP_CONFIG_BLK                                                    0
#define AQ_SETUP_CONFIG_Count                                                  1
#define AQ_SETUP_CONFIG_FieldMask                                     0x00000031
#define AQ_SETUP_CONFIG_ReadMask                                      0x00000031
#define AQ_SETUP_CONFIG_WriteMask                                     0x00000031
#define AQ_SETUP_CONFIG_ResetValue                                    0x00000000


#define AQ_SETUP_CONFIG_LAST_PIXEL                                           0:0
#define AQ_SETUP_CONFIG_LAST_PIXEL_End                                         0
#define AQ_SETUP_CONFIG_LAST_PIXEL_Start                                       0
#define AQ_SETUP_CONFIG_LAST_PIXEL_Type                                      U01
#define   AQ_SETUP_CONFIG_LAST_PIXEL_DISABLE                                 0x0
#define   AQ_SETUP_CONFIG_LAST_PIXEL_ENABLE                                  0x1


#define AQ_SETUP_CONFIG_BUGFIX15_DISABLE                                     4:4
#define AQ_SETUP_CONFIG_BUGFIX15_DISABLE_End                                   4
#define AQ_SETUP_CONFIG_BUGFIX15_DISABLE_Start                                 4
#define AQ_SETUP_CONFIG_BUGFIX15_DISABLE_Type                                U01
#define   AQ_SETUP_CONFIG_BUGFIX15_DISABLE_ENABLE                            0x0
#define   AQ_SETUP_CONFIG_BUGFIX15_DISABLE_DISABLE                           0x1


#define AQ_SETUP_CONFIG_LINE_FOUR_EDGE                                       5:5
#define AQ_SETUP_CONFIG_LINE_FOUR_EDGE_End                                     5
#define AQ_SETUP_CONFIG_LINE_FOUR_EDGE_Start                                   5
#define AQ_SETUP_CONFIG_LINE_FOUR_EDGE_Type                                  U01
#define   AQ_SETUP_CONFIG_LINE_FOUR_EDGE_ENABLE                              0x0
#define   AQ_SETUP_CONFIG_LINE_FOUR_EDGE_DISABLE                             0x1



#define mwv207regSEAreaThresholdRegAddrs                                  0x0307
#define MWV207REG_SE_AREA_THRESHOLD_Address                              0x00C1C
#define MWV207REG_SE_AREA_THRESHOLD_MSB                                       15
#define MWV207REG_SE_AREA_THRESHOLD_LSB                                        0
#define MWV207REG_SE_AREA_THRESHOLD_BLK                                        0
#define MWV207REG_SE_AREA_THRESHOLD_Count                                      1
#define MWV207REG_SE_AREA_THRESHOLD_FieldMask                         0xFFFFFFFF
#define MWV207REG_SE_AREA_THRESHOLD_ReadMask                          0xFFFFFFFF
#define MWV207REG_SE_AREA_THRESHOLD_WriteMask                         0xFFFFFFFF
#define MWV207REG_SE_AREA_THRESHOLD_ResetValue                        0x42000000


#define MWV207REG_SE_AREA_THRESHOLD_THRESHOLD                               31:0
#define MWV207REG_SE_AREA_THRESHOLD_THRESHOLD_End                             31
#define MWV207REG_SE_AREA_THRESHOLD_THRESHOLD_Start                            0
#define MWV207REG_SE_AREA_THRESHOLD_THRESHOLD_Type                           U32



#define mwv207regSEClipCompareRightRegAddrs                               0x0308
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_Address                          0x00C20
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_MSB                                   15
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_LSB                                    0
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_BLK                                    0
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_Count                                  1
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_FieldMask                     0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_ReadMask                      0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_WriteMask                     0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_ResetValue                    0x00000000


#define MWV207REG_SE_CLIP_COMPARE_RIGHT_FL32                                31:0
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_FL32_End                              31
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_FL32_Start                             0
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_FL32_Type                            U32




#define mwv207regSEClipCompareBottomRegAddrs                              0x0309
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_Address                         0x00C24
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_MSB                                  15
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_LSB                                   0
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_BLK                                   0
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_Count                                 1
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_FieldMask                    0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_ReadMask                     0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_WriteMask                    0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_ResetValue                   0x00000000


#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_FL32                               31:0
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_FL32_End                             31
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_FL32_Start                            0
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_FL32_Type                           U32




#define mwv207regSEDepthBiasClampRegAddrs                                 0x030A
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_Address                            0x00C28
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_MSB                                     15
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_LSB                                      0
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_BLK                                      0
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_Count                                    1
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_FieldMask                       0xFFFFFFFF
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_ReadMask                        0xFFFFFFFF
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_WriteMask                       0xFFFFFFFF
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_ResetValue                      0x00000000


#define MWV207REG_SE_DEPTH_BIAS_CLAMP_CLAMP                                 31:0
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_CLAMP_End                               31
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_CLAMP_Start                              0
#define MWV207REG_SE_DEPTH_BIAS_CLAMP_CLAMP_Type                             U32





#define mwv207regSEClipLeftExRegAddrs                                     0x0310
#define MWV207REG_SE_CLIP_LEFT_EX_Address                                0x00C40
#define MWV207REG_SE_CLIP_LEFT_EX_MSB                                         15
#define MWV207REG_SE_CLIP_LEFT_EX_LSB                                          4
#define MWV207REG_SE_CLIP_LEFT_EX_BLK                                          4
#define MWV207REG_SE_CLIP_LEFT_EX_Count                                       16
#define MWV207REG_SE_CLIP_LEFT_EX_FieldMask                           0xFFFFFFFF
#define MWV207REG_SE_CLIP_LEFT_EX_ReadMask                            0xFFFFFFFF
#define MWV207REG_SE_CLIP_LEFT_EX_WriteMask                           0xFFFFFFFF
#define MWV207REG_SE_CLIP_LEFT_EX_ResetValue                          0x00000000


#define MWV207REG_SE_CLIP_LEFT_EX_CLIP                                      31:0
#define MWV207REG_SE_CLIP_LEFT_EX_CLIP_End                                    31
#define MWV207REG_SE_CLIP_LEFT_EX_CLIP_Start                                   0
#define MWV207REG_SE_CLIP_LEFT_EX_CLIP_Type                                  U32




#define mwv207regSEClipTopExRegAddrs                                      0x0320
#define MWV207REG_SE_CLIP_TOP_EX_Address                                 0x00C80
#define MWV207REG_SE_CLIP_TOP_EX_MSB                                          15
#define MWV207REG_SE_CLIP_TOP_EX_LSB                                           4
#define MWV207REG_SE_CLIP_TOP_EX_BLK                                           4
#define MWV207REG_SE_CLIP_TOP_EX_Count                                        16
#define MWV207REG_SE_CLIP_TOP_EX_FieldMask                            0xFFFFFFFF
#define MWV207REG_SE_CLIP_TOP_EX_ReadMask                             0xFFFFFFFF
#define MWV207REG_SE_CLIP_TOP_EX_WriteMask                            0xFFFFFFFF
#define MWV207REG_SE_CLIP_TOP_EX_ResetValue                           0x00000000


#define MWV207REG_SE_CLIP_TOP_EX_CLIP                                       31:0
#define MWV207REG_SE_CLIP_TOP_EX_CLIP_End                                     31
#define MWV207REG_SE_CLIP_TOP_EX_CLIP_Start                                    0
#define MWV207REG_SE_CLIP_TOP_EX_CLIP_Type                                   U32




#define mwv207regSEClipRightExRegAddrs                                    0x0330
#define MWV207REG_SE_CLIP_RIGHT_EX_Address                               0x00CC0
#define MWV207REG_SE_CLIP_RIGHT_EX_MSB                                        15
#define MWV207REG_SE_CLIP_RIGHT_EX_LSB                                         4
#define MWV207REG_SE_CLIP_RIGHT_EX_BLK                                         4
#define MWV207REG_SE_CLIP_RIGHT_EX_Count                                      16
#define MWV207REG_SE_CLIP_RIGHT_EX_FieldMask                          0xFFFFFFFF
#define MWV207REG_SE_CLIP_RIGHT_EX_ReadMask                           0xFFFFFFFF
#define MWV207REG_SE_CLIP_RIGHT_EX_WriteMask                          0xFFFFFFFF
#define MWV207REG_SE_CLIP_RIGHT_EX_ResetValue                         0x45000000

#define MWV207REG_SE_CLIP_RIGHT_EX_CLIP                                     31:0
#define MWV207REG_SE_CLIP_RIGHT_EX_CLIP_End                                   31
#define MWV207REG_SE_CLIP_RIGHT_EX_CLIP_Start                                  0
#define MWV207REG_SE_CLIP_RIGHT_EX_CLIP_Type                                 U32




#define mwv207regSEClipBottomExRegAddrs                                   0x0340
#define MWV207REG_SE_CLIP_BOTTOM_EX_Address                              0x00D00
#define MWV207REG_SE_CLIP_BOTTOM_EX_MSB                                       15
#define MWV207REG_SE_CLIP_BOTTOM_EX_LSB                                        4
#define MWV207REG_SE_CLIP_BOTTOM_EX_BLK                                        4
#define MWV207REG_SE_CLIP_BOTTOM_EX_Count                                     16
#define MWV207REG_SE_CLIP_BOTTOM_EX_FieldMask                         0xFFFFFFFF
#define MWV207REG_SE_CLIP_BOTTOM_EX_ReadMask                          0xFFFFFFFF
#define MWV207REG_SE_CLIP_BOTTOM_EX_WriteMask                         0xFFFFFFFF
#define MWV207REG_SE_CLIP_BOTTOM_EX_ResetValue                        0x45000000

#define MWV207REG_SE_CLIP_BOTTOM_EX_CLIP                                    31:0
#define MWV207REG_SE_CLIP_BOTTOM_EX_CLIP_End                                  31
#define MWV207REG_SE_CLIP_BOTTOM_EX_CLIP_Start                                 0
#define MWV207REG_SE_CLIP_BOTTOM_EX_CLIP_Type                                U32



#define mwv207regSEClipCompareRightExRegAddrs                             0x0350
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_Address                       0x00D40
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_MSB                                15
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_LSB                                 4
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_BLK                                 4
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_Count                              16
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_FieldMask                  0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_ReadMask                   0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_WriteMask                  0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_ResetValue                 0x00000000


#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_FL32                             31:0
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_FL32_End                           31
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_FL32_Start                          0
#define MWV207REG_SE_CLIP_COMPARE_RIGHT_EX_FL32_Type                         U32




#define mwv207regSEClipCompareBottomExRegAddrs                            0x0360
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_Address                      0x00D80
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_MSB                               15
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_LSB                                4
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_BLK                                4
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_Count                             16
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_FieldMask                 0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_ReadMask                  0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_WriteMask                 0xFFFFFFFF
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_ResetValue                0x00000000


#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_FL32                            31:0
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_FL32_End                          31
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_FL32_Start                         0
#define MWV207REG_SE_CLIP_COMPARE_BOTTOM_EX_FL32_Type                        U32


#endif


