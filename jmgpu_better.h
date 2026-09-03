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




#ifndef __jmgpuregVipScaler_h__
#define __jmgpuregVipScaler_h__




#define mwv207regRoiBaseYRegAddrs                                         0x5F90
#define MWV207REG_ROI_BASE_Y_Address                                     0x17E40
#define MWV207REG_ROI_BASE_Y_MSB                                              15
#define MWV207REG_ROI_BASE_Y_LSB                                               0
#define MWV207REG_ROI_BASE_Y_BLK                                               0
#define MWV207REG_ROI_BASE_Y_Count                                             1
#define MWV207REG_ROI_BASE_Y_FieldMask                                0xFFFFFFFF
#define MWV207REG_ROI_BASE_Y_ReadMask                                 0xFFFFFFFF
#define MWV207REG_ROI_BASE_Y_WriteMask                                0xFFFFFFFF
#define MWV207REG_ROI_BASE_Y_ResetValue                               0x00000000


#define MWV207REG_ROI_BASE_Y_ADDRESS                                        31:0
#define MWV207REG_ROI_BASE_Y_ADDRESS_End                                      31
#define MWV207REG_ROI_BASE_Y_ADDRESS_Start                                     0
#define MWV207REG_ROI_BASE_Y_ADDRESS_Type                                    U32



#define mwv207regRoiBaseURegAddrs                                         0x5F91
#define MWV207REG_ROI_BASE_U_Address                                     0x17E44
#define MWV207REG_ROI_BASE_U_MSB                                              15
#define MWV207REG_ROI_BASE_U_LSB                                               0
#define MWV207REG_ROI_BASE_U_BLK                                               0
#define MWV207REG_ROI_BASE_U_Count                                             1
#define MWV207REG_ROI_BASE_U_FieldMask                                0xFFFFFFFF
#define MWV207REG_ROI_BASE_U_ReadMask                                 0xFFFFFFFF
#define MWV207REG_ROI_BASE_U_WriteMask                                0xFFFFFFFF
#define MWV207REG_ROI_BASE_U_ResetValue                               0x00000000

#define MWV207REG_ROI_BASE_U_ADDRESS                                        31:0
#define MWV207REG_ROI_BASE_U_ADDRESS_End                                      31
#define MWV207REG_ROI_BASE_U_ADDRESS_Start                                     0
#define MWV207REG_ROI_BASE_U_ADDRESS_Type                                    U32



#define mwv207regRoiBaseVRegAddrs                                         0x5F92
#define MWV207REG_ROI_BASE_V_Address                                     0x17E48
#define MWV207REG_ROI_BASE_V_MSB                                              15
#define MWV207REG_ROI_BASE_V_LSB                                               0
#define MWV207REG_ROI_BASE_V_BLK                                               0
#define MWV207REG_ROI_BASE_V_Count                                             1
#define MWV207REG_ROI_BASE_V_FieldMask                                0xFFFFFFFF
#define MWV207REG_ROI_BASE_V_ReadMask                                 0xFFFFFFFF
#define MWV207REG_ROI_BASE_V_WriteMask                                0xFFFFFFFF
#define MWV207REG_ROI_BASE_V_ResetValue                               0x00000000

#define MWV207REG_ROI_BASE_V_ADDRESS                                        31:0
#define MWV207REG_ROI_BASE_V_ADDRESS_End                                      31
#define MWV207REG_ROI_BASE_V_ADDRESS_Start                                     0
#define MWV207REG_ROI_BASE_V_ADDRESS_Type                                    U32



#define mwv207regRoiRegAddrs                                              0x5F93
#define MWV207REG_ROI_Address                                            0x17E4C
#define MWV207REG_ROI_MSB                                                     15
#define MWV207REG_ROI_LSB                                                      0
#define MWV207REG_ROI_BLK                                                      0
#define MWV207REG_ROI_Count                                                    1
#define MWV207REG_ROI_FieldMask                                       0xFFFFFFFF
#define MWV207REG_ROI_ReadMask                                        0xFFFFFFFF
#define MWV207REG_ROI_WriteMask                                       0xFFFFFFFF
#define MWV207REG_ROI_ResetValue                                      0x00000000

#define MWV207REG_ROI_WIDTH                                                 15:0
#define MWV207REG_ROI_WIDTH_End                                               15
#define MWV207REG_ROI_WIDTH_Start                                              0
#define MWV207REG_ROI_WIDTH_Type                                             U16

#define MWV207REG_ROI_HEIGHT                                               31:16
#define MWV207REG_ROI_HEIGHT_End                                              31
#define MWV207REG_ROI_HEIGHT_Start                                            16
#define MWV207REG_ROI_HEIGHT_Type                                            U16



#define mwv207regOutImageBaseRRegAddrs                                    0x5F94
#define MWV207REG_OUT_IMAGE_BASE_R_Address                               0x17E50
#define MWV207REG_OUT_IMAGE_BASE_R_MSB                                        15
#define MWV207REG_OUT_IMAGE_BASE_R_LSB                                         0
#define MWV207REG_OUT_IMAGE_BASE_R_BLK                                         0
#define MWV207REG_OUT_IMAGE_BASE_R_Count                                       1
#define MWV207REG_OUT_IMAGE_BASE_R_FieldMask                          0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_R_ReadMask                           0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_R_WriteMask                          0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_R_ResetValue                         0x00000000

#define MWV207REG_OUT_IMAGE_BASE_R_ADDRESS                                  31:0
#define MWV207REG_OUT_IMAGE_BASE_R_ADDRESS_End                                31
#define MWV207REG_OUT_IMAGE_BASE_R_ADDRESS_Start                               0
#define MWV207REG_OUT_IMAGE_BASE_R_ADDRESS_Type                              U32

#define mwv207regOutImageBaseGRegAddrs                                    0x5F95
#define MWV207REG_OUT_IMAGE_BASE_G_Address                               0x17E54
#define MWV207REG_OUT_IMAGE_BASE_G_MSB                                        15
#define MWV207REG_OUT_IMAGE_BASE_G_LSB                                         0
#define MWV207REG_OUT_IMAGE_BASE_G_BLK                                         0
#define MWV207REG_OUT_IMAGE_BASE_G_Count                                       1
#define MWV207REG_OUT_IMAGE_BASE_G_FieldMask                          0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_G_ReadMask                           0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_G_WriteMask                          0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_G_ResetValue                         0x00000000

#define MWV207REG_OUT_IMAGE_BASE_G_ADDRESS                                  31:0
#define MWV207REG_OUT_IMAGE_BASE_G_ADDRESS_End                                31
#define MWV207REG_OUT_IMAGE_BASE_G_ADDRESS_Start                               0
#define MWV207REG_OUT_IMAGE_BASE_G_ADDRESS_Type                              U32

#define mwv207regOutImageBaseBRegAddrs                                    0x5F96
#define MWV207REG_OUT_IMAGE_BASE_B_Address                               0x17E58
#define MWV207REG_OUT_IMAGE_BASE_B_MSB                                        15
#define MWV207REG_OUT_IMAGE_BASE_B_LSB                                         0
#define MWV207REG_OUT_IMAGE_BASE_B_BLK                                         0
#define MWV207REG_OUT_IMAGE_BASE_B_Count                                       1
#define MWV207REG_OUT_IMAGE_BASE_B_FieldMask                          0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_B_ReadMask                           0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_B_WriteMask                          0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_BASE_B_ResetValue                         0x00000000

#define MWV207REG_OUT_IMAGE_BASE_B_ADDRESS                                  31:0
#define MWV207REG_OUT_IMAGE_BASE_B_ADDRESS_End                                31
#define MWV207REG_OUT_IMAGE_BASE_B_ADDRESS_Start                               0
#define MWV207REG_OUT_IMAGE_BASE_B_ADDRESS_Type                              U32

#define mwv207regOutImageRegAddrs                                         0x5F97
#define MWV207REG_OUT_IMAGE_Address                                      0x17E5C
#define MWV207REG_OUT_IMAGE_MSB                                               15
#define MWV207REG_OUT_IMAGE_LSB                                                0
#define MWV207REG_OUT_IMAGE_BLK                                                0
#define MWV207REG_OUT_IMAGE_Count                                              1
#define MWV207REG_OUT_IMAGE_FieldMask                                 0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_ReadMask                                  0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_WriteMask                                 0xFFFFFFFF
#define MWV207REG_OUT_IMAGE_ResetValue                                0x00000000

#define MWV207REG_OUT_IMAGE_WIDTH                                           15:0
#define MWV207REG_OUT_IMAGE_WIDTH_End                                         15
#define MWV207REG_OUT_IMAGE_WIDTH_Start                                        0
#define MWV207REG_OUT_IMAGE_WIDTH_Type                                       U16

#define MWV207REG_OUT_IMAGE_HEIGHT                                         31:16
#define MWV207REG_OUT_IMAGE_HEIGHT_End                                        31
#define MWV207REG_OUT_IMAGE_HEIGHT_Start                                      16
#define MWV207REG_OUT_IMAGE_HEIGHT_Type                                      U16

#define mwv207regScaleXRegAddrs                                           0x5F98
#define MWV207REG_SCALE_X_Address                                        0x17E60
#define MWV207REG_SCALE_X_MSB                                                 15
#define MWV207REG_SCALE_X_LSB                                                  0
#define MWV207REG_SCALE_X_BLK                                                  0
#define MWV207REG_SCALE_X_Count                                                1
#define MWV207REG_SCALE_X_FieldMask                                   0xFFFFFFFF
#define MWV207REG_SCALE_X_ReadMask                                    0xFFFFFFFF
#define MWV207REG_SCALE_X_WriteMask                                   0xFFFFFFFF
#define MWV207REG_SCALE_X_ResetValue                                  0x00000000


#define MWV207REG_SCALE_X_FACTOR                                            31:0
#define MWV207REG_SCALE_X_FACTOR_End                                          31
#define MWV207REG_SCALE_X_FACTOR_Start                                         0
#define MWV207REG_SCALE_X_FACTOR_Type                                        U32

#define mwv207regScaleYRegAddrs                                           0x5F99
#define MWV207REG_SCALE_Y_Address                                        0x17E64
#define MWV207REG_SCALE_Y_MSB                                                 15
#define MWV207REG_SCALE_Y_LSB                                                  0
#define MWV207REG_SCALE_Y_BLK                                                  0
#define MWV207REG_SCALE_Y_Count                                                1
#define MWV207REG_SCALE_Y_FieldMask                                   0xFFFFFFFF
#define MWV207REG_SCALE_Y_ReadMask                                    0xFFFFFFFF
#define MWV207REG_SCALE_Y_WriteMask                                   0xFFFFFFFF
#define MWV207REG_SCALE_Y_ResetValue                                  0x00000000


#define MWV207REG_SCALE_Y_FACTOR                                            31:0
#define MWV207REG_SCALE_Y_FACTOR_End                                          31
#define MWV207REG_SCALE_Y_FACTOR_Start                                         0
#define MWV207REG_SCALE_Y_FACTOR_Type                                        U32



#define mwv207regInImageInitErrorRegAddrs                                 0x5F9A
#define MWV207REG_IN_IMAGE_INIT_ERROR_Address                            0x17E68
#define MWV207REG_IN_IMAGE_INIT_ERROR_MSB                                     15
#define MWV207REG_IN_IMAGE_INIT_ERROR_LSB                                      0
#define MWV207REG_IN_IMAGE_INIT_ERROR_BLK                                      0
#define MWV207REG_IN_IMAGE_INIT_ERROR_Count                                    1
#define MWV207REG_IN_IMAGE_INIT_ERROR_FieldMask                       0x3FFFFFFF
#define MWV207REG_IN_IMAGE_INIT_ERROR_ReadMask                        0x3FFFFFFF
#define MWV207REG_IN_IMAGE_INIT_ERROR_WriteMask                       0x3FFFFFFF
#define MWV207REG_IN_IMAGE_INIT_ERROR_ResetValue                      0x00000000

#define MWV207REG_IN_IMAGE_INIT_ERROR_X                                     14:0
#define MWV207REG_IN_IMAGE_INIT_ERROR_X_End                                   14
#define MWV207REG_IN_IMAGE_INIT_ERROR_X_Start                                  0
#define MWV207REG_IN_IMAGE_INIT_ERROR_X_Type                                 U15

#define MWV207REG_IN_IMAGE_INIT_ERROR_Y                                    29:15
#define MWV207REG_IN_IMAGE_INIT_ERROR_Y_End                                   29
#define MWV207REG_IN_IMAGE_INIT_ERROR_Y_Start                                 15
#define MWV207REG_IN_IMAGE_INIT_ERROR_Y_Type                                 U15

#define mwv207regTriggerScalerRegAddrs                                    0x5F9B
#define MWV207REG_TRIGGER_SCALER_Address                                 0x17E6C
#define MWV207REG_TRIGGER_SCALER_MSB                                          15
#define MWV207REG_TRIGGER_SCALER_LSB                                           0
#define MWV207REG_TRIGGER_SCALER_BLK                                           0
#define MWV207REG_TRIGGER_SCALER_Count                                         1
#define MWV207REG_TRIGGER_SCALER_FieldMask                            0x00000FFF
#define MWV207REG_TRIGGER_SCALER_ReadMask                             0x00000FFF
#define MWV207REG_TRIGGER_SCALER_WriteMask                            0x00000FFF
#define MWV207REG_TRIGGER_SCALER_ResetValue                           0x00000000


#define MWV207REG_TRIGGER_SCALER_START                                       0:0
#define MWV207REG_TRIGGER_SCALER_START_End                                     0
#define MWV207REG_TRIGGER_SCALER_START_Start                                   0
#define MWV207REG_TRIGGER_SCALER_START_Type                                  U01
#define   MWV207REG_TRIGGER_SCALER_START_FALSE                               0x0
#define   MWV207REG_TRIGGER_SCALER_START_TRUE                                0x1

#define MWV207REG_TRIGGER_SCALER_YONLY_MODE                                  1:1
#define MWV207REG_TRIGGER_SCALER_YONLY_MODE_End                                1
#define MWV207REG_TRIGGER_SCALER_YONLY_MODE_Start                              1
#define MWV207REG_TRIGGER_SCALER_YONLY_MODE_Type                             U01
#define   MWV207REG_TRIGGER_SCALER_YONLY_MODE_FALSE                          0x0
#define   MWV207REG_TRIGGER_SCALER_YONLY_MODE_TRUE                           0x1


#define MWV207REG_TRIGGER_SCALER_OUT_BITS_SIZE                               2:2
#define MWV207REG_TRIGGER_SCALER_OUT_BITS_SIZE_End                             2
#define MWV207REG_TRIGGER_SCALER_OUT_BITS_SIZE_Start                           2
#define MWV207REG_TRIGGER_SCALER_OUT_BITS_SIZE_Type                          U01
#define   MWV207REG_TRIGGER_SCALER_OUT_BITS_SIZE_EIGHT                       0x0
#define   MWV207REG_TRIGGER_SCALER_OUT_BITS_SIZE_SIXTEEN                     0x1


#define MWV207REG_TRIGGER_SCALER_OUTPUT_SIGN_UNSIGN                          3:3
#define MWV207REG_TRIGGER_SCALER_OUTPUT_SIGN_UNSIGN_End                        3
#define MWV207REG_TRIGGER_SCALER_OUTPUT_SIGN_UNSIGN_Start                      3
#define MWV207REG_TRIGGER_SCALER_OUTPUT_SIGN_UNSIGN_Type                     U01
#define   MWV207REG_TRIGGER_SCALER_OUTPUT_SIGN_UNSIGN_UNSIGN                 0x0
#define   MWV207REG_TRIGGER_SCALER_OUTPUT_SIGN_UNSIGN_SIGN                   0x1


#define MWV207REG_TRIGGER_SCALER_POST_SHIFT                                  7:4
#define MWV207REG_TRIGGER_SCALER_POST_SHIFT_End                                7
#define MWV207REG_TRIGGER_SCALER_POST_SHIFT_Start                              4
#define MWV207REG_TRIGGER_SCALER_POST_SHIFT_Type                             U04


#define MWV207REG_TRIGGER_SCALER_EIGHT_BIT_TO_SIXTEEN_BIT_SHIFT             11:8
#define MWV207REG_TRIGGER_SCALER_EIGHT_BIT_TO_SIXTEEN_BIT_SHIFT_End           11
#define MWV207REG_TRIGGER_SCALER_EIGHT_BIT_TO_SIXTEEN_BIT_SHIFT_Start          8
#define MWV207REG_TRIGGER_SCALER_EIGHT_BIT_TO_SIXTEEN_BIT_SHIFT_Type         U04




#define mwv207regOutStandingRequstRegAddrs                                0x5F9C
#define MWV207REG_OUT_STANDING_REQUST_Address                            0x17E70
#define MWV207REG_OUT_STANDING_REQUST_MSB                                     15
#define MWV207REG_OUT_STANDING_REQUST_LSB                                      0
#define MWV207REG_OUT_STANDING_REQUST_BLK                                      0
#define MWV207REG_OUT_STANDING_REQUST_Count                                    1
#define MWV207REG_OUT_STANDING_REQUST_FieldMask                       0xFFFFFFFF
#define MWV207REG_OUT_STANDING_REQUST_ReadMask                        0xFFFFFFFF
#define MWV207REG_OUT_STANDING_REQUST_WriteMask                       0xFFFFFFFF
#define MWV207REG_OUT_STANDING_REQUST_ResetValue                      0x00000000

#define MWV207REG_OUT_STANDING_REQUST_COUNTER                               31:0
#define MWV207REG_OUT_STANDING_REQUST_COUNTER_End                             31
#define MWV207REG_OUT_STANDING_REQUST_COUNTER_Start                            0
#define MWV207REG_OUT_STANDING_REQUST_COUNTER_Type                           U32

#define mwv207regYUV2RGBCoef0RegAddrs                                     0x5F9D
#define MWV207REG_YUV2_RGB_COEF0_Address                                 0x17E74
#define MWV207REG_YUV2_RGB_COEF0_MSB                                          15
#define MWV207REG_YUV2_RGB_COEF0_LSB                                           0
#define MWV207REG_YUV2_RGB_COEF0_BLK                                           0
#define MWV207REG_YUV2_RGB_COEF0_Count                                         1
#define MWV207REG_YUV2_RGB_COEF0_FieldMask                            0x3FFFFFFF
#define MWV207REG_YUV2_RGB_COEF0_ReadMask                             0x3FFFFFFF
#define MWV207REG_YUV2_RGB_COEF0_WriteMask                            0x3FFFFFFF
#define MWV207REG_YUV2_RGB_COEF0_ResetValue                           0x00000000

#define MWV207REG_YUV2_RGB_COEF0_C0                                          9:0
#define MWV207REG_YUV2_RGB_COEF0_C0_End                                        9
#define MWV207REG_YUV2_RGB_COEF0_C0_Start                                      0
#define MWV207REG_YUV2_RGB_COEF0_C0_Type                                     U10

#define MWV207REG_YUV2_RGB_COEF0_C1                                        19:10
#define MWV207REG_YUV2_RGB_COEF0_C1_End                                       19
#define MWV207REG_YUV2_RGB_COEF0_C1_Start                                     10
#define MWV207REG_YUV2_RGB_COEF0_C1_Type                                     U10

#define MWV207REG_YUV2_RGB_COEF0_C2                                        29:20
#define MWV207REG_YUV2_RGB_COEF0_C2_End                                       29
#define MWV207REG_YUV2_RGB_COEF0_C2_Start                                     20
#define MWV207REG_YUV2_RGB_COEF0_C2_Type                                     U10

#define mwv207regYUV2RGBCoef1RegAddrs                                     0x5F9E
#define MWV207REG_YUV2_RGB_COEF1_Address                                 0x17E78
#define MWV207REG_YUV2_RGB_COEF1_MSB                                          15
#define MWV207REG_YUV2_RGB_COEF1_LSB                                           0
#define MWV207REG_YUV2_RGB_COEF1_BLK                                           0
#define MWV207REG_YUV2_RGB_COEF1_Count                                         1
#define MWV207REG_YUV2_RGB_COEF1_FieldMask                            0x000FFFFF
#define MWV207REG_YUV2_RGB_COEF1_ReadMask                             0x000FFFFF
#define MWV207REG_YUV2_RGB_COEF1_WriteMask                            0x000FFFFF
#define MWV207REG_YUV2_RGB_COEF1_ResetValue                           0x00000000

#define MWV207REG_YUV2_RGB_COEF1_C3                                          9:0
#define MWV207REG_YUV2_RGB_COEF1_C3_End                                        9
#define MWV207REG_YUV2_RGB_COEF1_C3_Start                                      0
#define MWV207REG_YUV2_RGB_COEF1_C3_Type                                     U10

#define MWV207REG_YUV2_RGB_COEF1_C4                                        19:10
#define MWV207REG_YUV2_RGB_COEF1_C4_End                                       19
#define MWV207REG_YUV2_RGB_COEF1_C4_Start                                     10
#define MWV207REG_YUV2_RGB_COEF1_C4_Type                                     U10




#define mwv207regYUV2RGBCoef2RegAddrs                                     0x5F9F
#define MWV207REG_YUV2_RGB_COEF2_Address                                 0x17E7C
#define MWV207REG_YUV2_RGB_COEF2_MSB                                          15
#define MWV207REG_YUV2_RGB_COEF2_LSB                                           0
#define MWV207REG_YUV2_RGB_COEF2_BLK                                           0
#define MWV207REG_YUV2_RGB_COEF2_Count                                         1
#define MWV207REG_YUV2_RGB_COEF2_FieldMask                            0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF2_ReadMask                             0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF2_WriteMask                            0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF2_ResetValue                           0x00000000

#define MWV207REG_YUV2_RGB_COEF2_C5                                         18:0
#define MWV207REG_YUV2_RGB_COEF2_C5_End                                       18
#define MWV207REG_YUV2_RGB_COEF2_C5_Start                                      0
#define MWV207REG_YUV2_RGB_COEF2_C5_Type                                     U19




#define mwv207regYUV2RGBCoef3RegAddrs                                     0x5FA0
#define MWV207REG_YUV2_RGB_COEF3_Address                                 0x17E80
#define MWV207REG_YUV2_RGB_COEF3_MSB                                          15
#define MWV207REG_YUV2_RGB_COEF3_LSB                                           0
#define MWV207REG_YUV2_RGB_COEF3_BLK                                           0
#define MWV207REG_YUV2_RGB_COEF3_Count                                         1
#define MWV207REG_YUV2_RGB_COEF3_FieldMask                            0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF3_ReadMask                             0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF3_WriteMask                            0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF3_ResetValue                           0x00000000

#define MWV207REG_YUV2_RGB_COEF3_C6                                         18:0
#define MWV207REG_YUV2_RGB_COEF3_C6_End                                       18
#define MWV207REG_YUV2_RGB_COEF3_C6_Start                                      0
#define MWV207REG_YUV2_RGB_COEF3_C6_Type                                     U19

#define mwv207regYUV2RGBCoef4RegAddrs                                     0x5FA1
#define MWV207REG_YUV2_RGB_COEF4_Address                                 0x17E84
#define MWV207REG_YUV2_RGB_COEF4_MSB                                          15
#define MWV207REG_YUV2_RGB_COEF4_LSB                                           0
#define MWV207REG_YUV2_RGB_COEF4_BLK                                           0
#define MWV207REG_YUV2_RGB_COEF4_Count                                         1
#define MWV207REG_YUV2_RGB_COEF4_FieldMask                            0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF4_ReadMask                             0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF4_WriteMask                            0x0007FFFF
#define MWV207REG_YUV2_RGB_COEF4_ResetValue                           0x00000000

#define MWV207REG_YUV2_RGB_COEF4_C7                                         18:0
#define MWV207REG_YUV2_RGB_COEF4_C7_End                                       18
#define MWV207REG_YUV2_RGB_COEF4_C7_Start                                      0
#define MWV207REG_YUV2_RGB_COEF4_C7_Type                                     U19




#define mwv207regStrideRegAddrs                                           0x5FA2
#define MWV207REG_STRIDE_Address                                         0x17E88
#define MWV207REG_STRIDE_MSB                                                  15
#define MWV207REG_STRIDE_LSB                                                   0
#define MWV207REG_STRIDE_BLK                                                   0
#define MWV207REG_STRIDE_Count                                                 1
#define MWV207REG_STRIDE_FieldMask                                    0xFFFFFFFF
#define MWV207REG_STRIDE_ReadMask                                     0xFFFFFFFF
#define MWV207REG_STRIDE_WriteMask                                    0xFFFFFFFF
#define MWV207REG_STRIDE_ResetValue                                   0x00000000

#define MWV207REG_STRIDE_IN_IMAGE_Y                                         15:0
#define MWV207REG_STRIDE_IN_IMAGE_Y_End                                       15
#define MWV207REG_STRIDE_IN_IMAGE_Y_Start                                      0
#define MWV207REG_STRIDE_IN_IMAGE_Y_Type                                     U16

#define MWV207REG_STRIDE_OUT_IMAGE_RGB                                     31:16
#define MWV207REG_STRIDE_OUT_IMAGE_RGB_End                                    31
#define MWV207REG_STRIDE_OUT_IMAGE_RGB_Start                                  16
#define MWV207REG_STRIDE_OUT_IMAGE_RGB_Type                                  U16



#define mwv207regInImageRegAddrs                                          0x5FA3
#define MWV207REG_IN_IMAGE_Address                                       0x17E8C
#define MWV207REG_IN_IMAGE_MSB                                                15
#define MWV207REG_IN_IMAGE_LSB                                                 0
#define MWV207REG_IN_IMAGE_BLK                                                 0
#define MWV207REG_IN_IMAGE_Count                                               1
#define MWV207REG_IN_IMAGE_FieldMask                                  0xFFFFFFFF
#define MWV207REG_IN_IMAGE_ReadMask                                   0xFFFFFFFF
#define MWV207REG_IN_IMAGE_WriteMask                                  0xFFFFFFFF
#define MWV207REG_IN_IMAGE_ResetValue                                 0x00000000

#define MWV207REG_IN_IMAGE_WIDTH                                            15:0
#define MWV207REG_IN_IMAGE_WIDTH_End                                          15
#define MWV207REG_IN_IMAGE_WIDTH_Start                                         0
#define MWV207REG_IN_IMAGE_WIDTH_Type                                        U16

#define MWV207REG_IN_IMAGE_HEIGHT                                          31:16
#define MWV207REG_IN_IMAGE_HEIGHT_End                                         31
#define MWV207REG_IN_IMAGE_HEIGHT_Start                                       16
#define MWV207REG_IN_IMAGE_HEIGHT_Type                                       U16




#define mwv207regRoiTLCoorRegAddrs                                        0x5FA4
#define MWV207REG_ROI_TL_COOR_Address                                    0x17E90
#define MWV207REG_ROI_TL_COOR_MSB                                             15
#define MWV207REG_ROI_TL_COOR_LSB                                              0
#define MWV207REG_ROI_TL_COOR_BLK                                              0
#define MWV207REG_ROI_TL_COOR_Count                                            1
#define MWV207REG_ROI_TL_COOR_FieldMask                               0xFFFFFFFF
#define MWV207REG_ROI_TL_COOR_ReadMask                                0xFFFFFFFF
#define MWV207REG_ROI_TL_COOR_WriteMask                               0xFFFFFFFF
#define MWV207REG_ROI_TL_COOR_ResetValue                              0x00000000

#define MWV207REG_ROI_TL_COOR_X                                             15:0
#define MWV207REG_ROI_TL_COOR_X_End                                           15
#define MWV207REG_ROI_TL_COOR_X_Start                                          0
#define MWV207REG_ROI_TL_COOR_X_Type                                         U16

#define MWV207REG_ROI_TL_COOR_Y                                            31:16
#define MWV207REG_ROI_TL_COOR_Y_End                                           31
#define MWV207REG_ROI_TL_COOR_Y_Start                                         16
#define MWV207REG_ROI_TL_COOR_Y_Type                                         U16




#define mwv207regInImageInitErrorIntRegAddrs                              0x5FA5
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_Address                        0x17E94
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_MSB                                 15
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_LSB                                  0
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_BLK                                  0
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_Count                                1
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_FieldMask                   0x0000FFFF
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_ReadMask                    0x0000FFFF
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_WriteMask                   0x0000FFFF
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_ResetValue                  0x00000000

#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_X                                  7:0
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_X_End                                7
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_X_Start                              0
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_X_Type                             U08


#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_Y                                 15:8
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_Y_End                               15
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_Y_Start                              8
#define MWV207REG_IN_IMAGE_INIT_ERROR_INT_Y_Type                             U08




#define mwv207regClampRRegAddrs                                           0x5FA6
#define MWV207REG_CLAMP_R_Address                                        0x17E98
#define MWV207REG_CLAMP_R_MSB                                                 15
#define MWV207REG_CLAMP_R_LSB                                                  0
#define MWV207REG_CLAMP_R_BLK                                                  0
#define MWV207REG_CLAMP_R_Count                                                1
#define MWV207REG_CLAMP_R_FieldMask                                   0xFFFFFFFF
#define MWV207REG_CLAMP_R_ReadMask                                    0xFFFFFFFF
#define MWV207REG_CLAMP_R_WriteMask                                   0xFFFFFFFF
#define MWV207REG_CLAMP_R_ResetValue                                  0x00000000

#define MWV207REG_CLAMP_R_MIN                                               15:0
#define MWV207REG_CLAMP_R_MIN_End                                             15
#define MWV207REG_CLAMP_R_MIN_Start                                            0
#define MWV207REG_CLAMP_R_MIN_Type                                           U16

#define MWV207REG_CLAMP_R_MAX                                              31:16
#define MWV207REG_CLAMP_R_MAX_End                                             31
#define MWV207REG_CLAMP_R_MAX_Start                                           16
#define MWV207REG_CLAMP_R_MAX_Type                                           U16




#define mwv207regClampGRegAddrs                                           0x5FA7
#define MWV207REG_CLAMP_G_Address                                        0x17E9C
#define MWV207REG_CLAMP_G_MSB                                                 15
#define MWV207REG_CLAMP_G_LSB                                                  0
#define MWV207REG_CLAMP_G_BLK                                                  0
#define MWV207REG_CLAMP_G_Count                                                1
#define MWV207REG_CLAMP_G_FieldMask                                   0xFFFFFFFF
#define MWV207REG_CLAMP_G_ReadMask                                    0xFFFFFFFF
#define MWV207REG_CLAMP_G_WriteMask                                   0xFFFFFFFF
#define MWV207REG_CLAMP_G_ResetValue                                  0x00000000

#define MWV207REG_CLAMP_G_MIN                                               15:0
#define MWV207REG_CLAMP_G_MIN_End                                             15
#define MWV207REG_CLAMP_G_MIN_Start                                            0
#define MWV207REG_CLAMP_G_MIN_Type                                           U16

#define MWV207REG_CLAMP_G_MAX                                              31:16
#define MWV207REG_CLAMP_G_MAX_End                                             31
#define MWV207REG_CLAMP_G_MAX_Start                                           16
#define MWV207REG_CLAMP_G_MAX_Type                                           U16




#define mwv207regClampBRegAddrs                                           0x5FA8
#define MWV207REG_CLAMP_B_Address                                        0x17EA0
#define MWV207REG_CLAMP_B_MSB                                                 15
#define MWV207REG_CLAMP_B_LSB                                                  0
#define MWV207REG_CLAMP_B_BLK                                                  0
#define MWV207REG_CLAMP_B_Count                                                1
#define MWV207REG_CLAMP_B_FieldMask                                   0xFFFFFFFF
#define MWV207REG_CLAMP_B_ReadMask                                    0xFFFFFFFF
#define MWV207REG_CLAMP_B_WriteMask                                   0xFFFFFFFF
#define MWV207REG_CLAMP_B_ResetValue                                  0x00000000

#define MWV207REG_CLAMP_B_MIN                                               15:0
#define MWV207REG_CLAMP_B_MIN_End                                             15
#define MWV207REG_CLAMP_B_MIN_Start                                            0
#define MWV207REG_CLAMP_B_MIN_Type                                           U16

#define MWV207REG_CLAMP_B_MAX                                              31:16
#define MWV207REG_CLAMP_B_MAX_End                                             31
#define MWV207REG_CLAMP_B_MAX_Start                                           16
#define MWV207REG_CLAMP_B_MAX_Type                                           U16


#endif


