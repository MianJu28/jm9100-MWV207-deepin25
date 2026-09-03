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




#ifndef __AQRasterReg_h__
#define __AQRasterReg_h__


#define AQRasterControlRegAddrs                                           0x0380
#define AQ_RASTER_CONTROL_Address                                        0x00E00
#define AQ_RASTER_CONTROL_MSB                                                 15
#define AQ_RASTER_CONTROL_LSB                                                  0
#define AQ_RASTER_CONTROL_BLK                                                  0
#define AQ_RASTER_CONTROL_Count                                                1
#define AQ_RASTER_CONTROL_FieldMask                                   0x000003FF
#define AQ_RASTER_CONTROL_ReadMask                                    0x000003FF
#define AQ_RASTER_CONTROL_WriteMask                                   0x000003FF
#define AQ_RASTER_CONTROL_ResetValue                                  0x000000F1


#define AQ_RASTER_CONTROL_ENABLE_OPTIMIZATIONS                               0:0
#define AQ_RASTER_CONTROL_ENABLE_OPTIMIZATIONS_End                             0
#define AQ_RASTER_CONTROL_ENABLE_OPTIMIZATIONS_Start                           0
#define AQ_RASTER_CONTROL_ENABLE_OPTIMIZATIONS_Type                          U01
#define   AQ_RASTER_CONTROL_ENABLE_OPTIMIZATIONS_DISABLED                    0x0
#define   AQ_RASTER_CONTROL_ENABLE_OPTIMIZATIONS_ENABLED                     0x1

#define AQ_RASTER_CONTROL_HALF_ATTRIBUTE                                     1:1
#define AQ_RASTER_CONTROL_HALF_ATTRIBUTE_End                                   1
#define AQ_RASTER_CONTROL_HALF_ATTRIBUTE_Start                                 1
#define AQ_RASTER_CONTROL_HALF_ATTRIBUTE_Type                                U01
#define   AQ_RASTER_CONTROL_HALF_ATTRIBUTE_DISABLED                          0x0
#define   AQ_RASTER_CONTROL_HALF_ATTRIBUTE_ENABLED                           0x1


#define AQ_RASTER_CONTROL_PIXEL_PREFETCH                                     2:2
#define AQ_RASTER_CONTROL_PIXEL_PREFETCH_End                                   2
#define AQ_RASTER_CONTROL_PIXEL_PREFETCH_Start                                 2
#define AQ_RASTER_CONTROL_PIXEL_PREFETCH_Type                                U01
#define   AQ_RASTER_CONTROL_PIXEL_PREFETCH_DISABLED                          0x0
#define   AQ_RASTER_CONTROL_PIXEL_PREFETCH_ENABLED                           0x1

#define AQ_RASTER_CONTROL_WAIT_FOR_ALL_IDLE_BEFORE_COMPOSITION               3:3
#define AQ_RASTER_CONTROL_WAIT_FOR_ALL_IDLE_BEFORE_COMPOSITION_End             3
#define AQ_RASTER_CONTROL_WAIT_FOR_ALL_IDLE_BEFORE_COMPOSITION_Start           3
#define AQ_RASTER_CONTROL_WAIT_FOR_ALL_IDLE_BEFORE_COMPOSITION_Type          U01
#define   AQ_RASTER_CONTROL_WAIT_FOR_ALL_IDLE_BEFORE_COMPOSITION_DISABLED    0x0
#define   AQ_RASTER_CONTROL_WAIT_FOR_ALL_IDLE_BEFORE_COMPOSITION_ENABLED     0x1

#define AQ_RASTER_CONTROL_MAX_TRIANGLE_FOR_PS_PACK                           9:4
#define AQ_RASTER_CONTROL_MAX_TRIANGLE_FOR_PS_PACK_End                         9
#define AQ_RASTER_CONTROL_MAX_TRIANGLE_FOR_PS_PACK_Start                       4
#define AQ_RASTER_CONTROL_MAX_TRIANGLE_FOR_PS_PACK_Type                      U06



#define mwv207regMultiSampleCoordsRegAddrs                                0x0384
#define MWV207REG_MULTI_SAMPLE_COORDS_Address                            0x00E10
#define MWV207REG_MULTI_SAMPLE_COORDS_MSB                                     15
#define MWV207REG_MULTI_SAMPLE_COORDS_LSB                                      2
#define MWV207REG_MULTI_SAMPLE_COORDS_BLK                                      2
#define MWV207REG_MULTI_SAMPLE_COORDS_Count                                    4
#define MWV207REG_MULTI_SAMPLE_COORDS_FieldMask                       0xFFFFFFFF
#define MWV207REG_MULTI_SAMPLE_COORDS_ReadMask                        0xFFFFFFFF
#define MWV207REG_MULTI_SAMPLE_COORDS_WriteMask                       0xFFFFFFFF
#define MWV207REG_MULTI_SAMPLE_COORDS_ResetValue                      0x00000000


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_X                              3:0
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_X_End                            3
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_X_Start                          0
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_X_Type                         U04


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_Y                              7:4
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_Y_End                            7
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_Y_Start                          4
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE0_Y_Type                         U04


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_X                             11:8
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_X_End                           11
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_X_Start                          8
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_X_Type                         U04


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_Y                            15:12
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_Y_End                           15
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_Y_Start                         12
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE1_Y_Type                         U04


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_X                            19:16
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_X_End                           19
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_X_Start                         16
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_X_Type                         U04


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_Y                            23:20
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_Y_End                           23
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_Y_Start                         20
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE2_Y_Type                         U04


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_X                            27:24
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_X_End                           27
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_X_Start                         24
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_X_Type                         U04


#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_Y                            31:28
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_Y_End                           31
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_Y_Start                         28
#define MWV207REG_MULTI_SAMPLE_COORDS_SAMPLE3_Y_Type                         U04



#define mwv207regMultiSampleJitterRegAddrs                                0x0381
#define MWV207REG_MULTI_SAMPLE_JITTER_Address                            0x00E04
#define MWV207REG_MULTI_SAMPLE_JITTER_MSB                                     15
#define MWV207REG_MULTI_SAMPLE_JITTER_LSB                                      0
#define MWV207REG_MULTI_SAMPLE_JITTER_BLK                                      0
#define MWV207REG_MULTI_SAMPLE_JITTER_Count                                    1
#define MWV207REG_MULTI_SAMPLE_JITTER_FieldMask                       0xFFFFFFFF
#define MWV207REG_MULTI_SAMPLE_JITTER_ReadMask                        0xFFFFFFFF
#define MWV207REG_MULTI_SAMPLE_JITTER_WriteMask                       0xFFFFFFFF
#define MWV207REG_MULTI_SAMPLE_JITTER_ResetValue                      0x00000000


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X0                           1:0
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X0_End                         1
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X0_Start                       0
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X0_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X1                           3:2
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X1_End                         3
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X1_Start                       2
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X1_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X2                           5:4
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X2_End                         5
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X2_Start                       4
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X2_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X3                           7:6
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X3_End                         7
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X3_Start                       6
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y0_X3_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X0                           9:8
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X0_End                         9
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X0_Start                       8
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X0_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X1                         11:10
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X1_End                        11
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X1_Start                      10
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X1_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X2                         13:12
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X2_End                        13
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X2_Start                      12
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X2_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X3                         15:14
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X3_End                        15
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X3_Start                      14
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y1_X3_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X0                         17:16
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X0_End                        17
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X0_Start                      16
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X0_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X1                         19:18
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X1_End                        19
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X1_Start                      18
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X1_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X2                         21:20
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X2_End                        21
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X2_Start                      20
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X2_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X3                         23:22
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X3_End                        23
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X3_Start                      22
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y2_X3_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X0                         25:24
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X0_End                        25
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X0_Start                      24
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X0_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X1                         27:26
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X1_End                        27
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X1_Start                      26
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X1_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X2                         29:28
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X2_End                        29
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X2_Start                      28
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X2_Type                      U02


#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X3                         31:30
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X3_End                        31
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X3_Start                      30
#define MWV207REG_MULTI_SAMPLE_JITTER_JITTER_Y3_X3_Type                      U02



#define mwv207regCentroidsRegAddrs                                        0x0390
#define MWV207REG_CENTROIDS_Address                                      0x00E40
#define MWV207REG_CENTROIDS_MSB                                               15
#define MWV207REG_CENTROIDS_LSB                                                4
#define MWV207REG_CENTROIDS_BLK                                                4
#define MWV207REG_CENTROIDS_Count                                             16
#define MWV207REG_CENTROIDS_FieldMask                                 0xFFFFFFFF
#define MWV207REG_CENTROIDS_ReadMask                                  0xFFFFFFFF
#define MWV207REG_CENTROIDS_WriteMask                                 0xFFFFFFFF
#define MWV207REG_CENTROIDS_ResetValue                                0x00000000


#define MWV207REG_CENTROIDS_CENTROID_X_0_4_8_12                              3:0
#define MWV207REG_CENTROIDS_CENTROID_X_0_4_8_12_End                            3
#define MWV207REG_CENTROIDS_CENTROID_X_0_4_8_12_Start                          0
#define MWV207REG_CENTROIDS_CENTROID_X_0_4_8_12_Type                         U04


#define MWV207REG_CENTROIDS_CENTROID_Y_0_4_8_12                              7:4
#define MWV207REG_CENTROIDS_CENTROID_Y_0_4_8_12_End                            7
#define MWV207REG_CENTROIDS_CENTROID_Y_0_4_8_12_Start                          4
#define MWV207REG_CENTROIDS_CENTROID_Y_0_4_8_12_Type                         U04


#define MWV207REG_CENTROIDS_CENTROID_X_1_5_9_13                             11:8
#define MWV207REG_CENTROIDS_CENTROID_X_1_5_9_13_End                           11
#define MWV207REG_CENTROIDS_CENTROID_X_1_5_9_13_Start                          8
#define MWV207REG_CENTROIDS_CENTROID_X_1_5_9_13_Type                         U04


#define MWV207REG_CENTROIDS_CENTROID_Y_1_5_9_13                            15:12
#define MWV207REG_CENTROIDS_CENTROID_Y_1_5_9_13_End                           15
#define MWV207REG_CENTROIDS_CENTROID_Y_1_5_9_13_Start                         12
#define MWV207REG_CENTROIDS_CENTROID_Y_1_5_9_13_Type                         U04


#define MWV207REG_CENTROIDS_CENTROID_X_2_6_10_14                           19:16
#define MWV207REG_CENTROIDS_CENTROID_X_2_6_10_14_End                          19
#define MWV207REG_CENTROIDS_CENTROID_X_2_6_10_14_Start                        16
#define MWV207REG_CENTROIDS_CENTROID_X_2_6_10_14_Type                        U04


#define MWV207REG_CENTROIDS_CENTROID_Y_2_6_10_14                           23:20
#define MWV207REG_CENTROIDS_CENTROID_Y_2_6_10_14_End                          23
#define MWV207REG_CENTROIDS_CENTROID_Y_2_6_10_14_Start                        20
#define MWV207REG_CENTROIDS_CENTROID_Y_2_6_10_14_Type                        U04


#define MWV207REG_CENTROIDS_CENTROID_X_3_7_11_15                           27:24
#define MWV207REG_CENTROIDS_CENTROID_X_3_7_11_15_End                          27
#define MWV207REG_CENTROIDS_CENTROID_X_3_7_11_15_Start                        24
#define MWV207REG_CENTROIDS_CENTROID_X_3_7_11_15_Type                        U04


#define MWV207REG_CENTROIDS_CENTROID_Y_3_7_11_15                           31:28
#define MWV207REG_CENTROIDS_CENTROID_Y_3_7_11_15_End                          31
#define MWV207REG_CENTROIDS_CENTROID_Y_3_7_11_15_Start                        28
#define MWV207REG_CENTROIDS_CENTROID_Y_3_7_11_15_Type                        U04




#define mwv207regRAControlRegAddrs                                        0x0382
#define MWV207REG_RA_CONTROL_Address                                     0x00E08
#define MWV207REG_RA_CONTROL_MSB                                              15
#define MWV207REG_RA_CONTROL_LSB                                               0
#define MWV207REG_RA_CONTROL_BLK                                               0
#define MWV207REG_RA_CONTROL_Count                                             1
#define MWV207REG_RA_CONTROL_FieldMask                                0xFF1113F5
#define MWV207REG_RA_CONTROL_ReadMask                                 0xFF1113F5
#define MWV207REG_RA_CONTROL_WriteMask                                0xFF1113F5
#define MWV207REG_RA_CONTROL_ResetValue                               0x17000031


#define MWV207REG_RA_CONTROL_EARLY_EARLY_Z                                   0:0
#define MWV207REG_RA_CONTROL_EARLY_EARLY_Z_End                                 0
#define MWV207REG_RA_CONTROL_EARLY_EARLY_Z_Start                               0
#define MWV207REG_RA_CONTROL_EARLY_EARLY_Z_Type                              U01
#define   MWV207REG_RA_CONTROL_EARLY_EARLY_Z_DISABLED                        0x0
#define   MWV207REG_RA_CONTROL_EARLY_EARLY_Z_ENABLED                         0x1

#define MWV207REG_RA_CONTROL_SMALL_BATCH                                     2:2
#define MWV207REG_RA_CONTROL_SMALL_BATCH_End                                   2
#define MWV207REG_RA_CONTROL_SMALL_BATCH_Start                                 2
#define MWV207REG_RA_CONTROL_SMALL_BATCH_Type                                U01
#define   MWV207REG_RA_CONTROL_SMALL_BATCH_ENABLED                           0x0
#define   MWV207REG_RA_CONTROL_SMALL_BATCH_DISABLED                          0x1


#define MWV207REG_RA_CONTROL_DEPTH_RELAXATION                                7:4
#define MWV207REG_RA_CONTROL_DEPTH_RELAXATION_End                              7
#define MWV207REG_RA_CONTROL_DEPTH_RELAXATION_Start                            4
#define MWV207REG_RA_CONTROL_DEPTH_RELAXATION_Type                           U04
#define   MWV207REG_RA_CONTROL_DEPTH_RELAXATION_DEFAULT                      0x3


#define MWV207REG_RA_CONTROL_WALKER                                          9:8
#define MWV207REG_RA_CONTROL_WALKER_End                                        9
#define MWV207REG_RA_CONTROL_WALKER_Start                                      8
#define MWV207REG_RA_CONTROL_WALKER_Type                                     U02

#define   MWV207REG_RA_CONTROL_WALKER_AUTOMATIC                              0x0

#define   MWV207REG_RA_CONTROL_WALKER_HORIZONTAL                             0x1

#define   MWV207REG_RA_CONTROL_WALKER_VERTICAL                               0x2

#define   MWV207REG_RA_CONTROL_WALKER_HIERARCHICAL                           0x3


#define MWV207REG_RA_CONTROL_DISABLE_ZCONTROL                              12:12
#define MWV207REG_RA_CONTROL_DISABLE_ZCONTROL_End                             12
#define MWV207REG_RA_CONTROL_DISABLE_ZCONTROL_Start                           12
#define MWV207REG_RA_CONTROL_DISABLE_ZCONTROL_Type                           U01

#define   MWV207REG_RA_CONTROL_DISABLE_ZCONTROL_ENABLED                      0x0

#define   MWV207REG_RA_CONTROL_DISABLE_ZCONTROL_DISABLED                     0x1


#define MWV207REG_RA_CONTROL_ZMODE                                         16:16
#define MWV207REG_RA_CONTROL_ZMODE_End                                        16
#define MWV207REG_RA_CONTROL_ZMODE_Start                                      16
#define MWV207REG_RA_CONTROL_ZMODE_Type                                      U01
#define   MWV207REG_RA_CONTROL_ZMODE_AUTOMATIC                               0x0

#define   MWV207REG_RA_CONTROL_ZMODE_FLOAT                                   0x1

#define MWV207REG_RA_CONTROL_CENTROID_Z                                    20:20
#define MWV207REG_RA_CONTROL_CENTROID_Z_End                                   20
#define MWV207REG_RA_CONTROL_CENTROID_Z_Start                                 20
#define MWV207REG_RA_CONTROL_CENTROID_Z_Type                                 U01
#define   MWV207REG_RA_CONTROL_CENTROID_Z_AVERAGE                            0x0

#define   MWV207REG_RA_CONTROL_CENTROID_Z_CENTROID                           0x1


#define MWV207REG_RA_CONTROL_SHADER_Z                                      24:24
#define MWV207REG_RA_CONTROL_SHADER_Z_End                                     24
#define MWV207REG_RA_CONTROL_SHADER_Z_Start                                   24
#define MWV207REG_RA_CONTROL_SHADER_Z_Type                                   U01

#define   MWV207REG_RA_CONTROL_SHADER_Z_DISABLED                             0x0

#define   MWV207REG_RA_CONTROL_SHADER_Z_ENABLED                              0x1


#define MWV207REG_RA_CONTROL_SHADER_SUB_SAMPLES                            25:25
#define MWV207REG_RA_CONTROL_SHADER_SUB_SAMPLES_End                           25
#define MWV207REG_RA_CONTROL_SHADER_SUB_SAMPLES_Start                         25
#define MWV207REG_RA_CONTROL_SHADER_SUB_SAMPLES_Type                         U01

#define   MWV207REG_RA_CONTROL_SHADER_SUB_SAMPLES_DISABLED                   0x0

#define   MWV207REG_RA_CONTROL_SHADER_SUB_SAMPLES_ENABLED                    0x1


#define MWV207REG_RA_CONTROL_SHADER_W                                      26:26
#define MWV207REG_RA_CONTROL_SHADER_W_End                                     26
#define MWV207REG_RA_CONTROL_SHADER_W_Start                                   26
#define MWV207REG_RA_CONTROL_SHADER_W_Type                                   U01

#define   MWV207REG_RA_CONTROL_SHADER_W_DISABLED                             0x0

#define   MWV207REG_RA_CONTROL_SHADER_W_ENABLED                              0x1


#define MWV207REG_RA_CONTROL_QUAD_DIRECTION                                27:27
#define MWV207REG_RA_CONTROL_QUAD_DIRECTION_End                               27
#define MWV207REG_RA_CONTROL_QUAD_DIRECTION_Start                             27
#define MWV207REG_RA_CONTROL_QUAD_DIRECTION_Type                             U01
#define   MWV207REG_RA_CONTROL_QUAD_DIRECTION_ZIG_ZAG                        0x0
#define   MWV207REG_RA_CONTROL_QUAD_DIRECTION_CYCLE                          0x1


#define MWV207REG_RA_CONTROL_ZSELECT                                       29:28
#define MWV207REG_RA_CONTROL_ZSELECT_End                                      29
#define MWV207REG_RA_CONTROL_ZSELECT_Start                                    28
#define MWV207REG_RA_CONTROL_ZSELECT_Type                                    U02

#define   MWV207REG_RA_CONTROL_ZSELECT_READ_WRITE                            0x0

#define   MWV207REG_RA_CONTROL_ZSELECT_READ                                  0x1

#define   MWV207REG_RA_CONTROL_ZSELECT_DISABLED                              0x2


#define MWV207REG_RA_CONTROL_SUB_SAMPLE_MASK_LOCATION                      31:30
#define MWV207REG_RA_CONTROL_SUB_SAMPLE_MASK_LOCATION_End                     31
#define MWV207REG_RA_CONTROL_SUB_SAMPLE_MASK_LOCATION_Start                   30
#define MWV207REG_RA_CONTROL_SUB_SAMPLE_MASK_LOCATION_Type                   U02

#define   MWV207REG_RA_CONTROL_SUB_SAMPLE_MASK_LOCATION_SUB_Z                0x0

#define   MWV207REG_RA_CONTROL_SUB_SAMPLE_MASK_LOCATION_Z                    0x1

#define   MWV207REG_RA_CONTROL_SUB_SAMPLE_MASK_LOCATION_W                    0x2




#define mwv207regRAMediumpMaskRegAddrs                                    0x0383
#define MWV207REG_RA_MEDIUMP_MASK_Address                                0x00E0C
#define MWV207REG_RA_MEDIUMP_MASK_MSB                                         15
#define MWV207REG_RA_MEDIUMP_MASK_LSB                                          0
#define MWV207REG_RA_MEDIUMP_MASK_BLK                                          0
#define MWV207REG_RA_MEDIUMP_MASK_Count                                        1
#define MWV207REG_RA_MEDIUMP_MASK_FieldMask                           0xFFFFFFFF
#define MWV207REG_RA_MEDIUMP_MASK_ReadMask                            0xFFFFFFFF
#define MWV207REG_RA_MEDIUMP_MASK_WriteMask                           0xFFFFFFFF
#define MWV207REG_RA_MEDIUMP_MASK_ResetValue                          0x00000000


#define MWV207REG_RA_MEDIUMP_MASK_ATTRIBUTE_MASK                            15:0
#define MWV207REG_RA_MEDIUMP_MASK_ATTRIBUTE_MASK_End                          15
#define MWV207REG_RA_MEDIUMP_MASK_ATTRIBUTE_MASK_Start                         0
#define MWV207REG_RA_MEDIUMP_MASK_ATTRIBUTE_MASK_Type                        U16


#define MWV207REG_RA_MEDIUMP_MASK_WMASK                                    31:16
#define MWV207REG_RA_MEDIUMP_MASK_WMASK_End                                   31
#define MWV207REG_RA_MEDIUMP_MASK_WMASK_Start                                 16
#define MWV207REG_RA_MEDIUMP_MASK_WMASK_Type                                 U16

#define mwv207regRAControlHZRegAddrs                                      0x0388
#define MWV207REG_RA_CONTROL_HZ_Address                                  0x00E20
#define MWV207REG_RA_CONTROL_HZ_MSB                                           15
#define MWV207REG_RA_CONTROL_HZ_LSB                                            0
#define MWV207REG_RA_CONTROL_HZ_BLK                                            0
#define MWV207REG_RA_CONTROL_HZ_Count                                          1
#define MWV207REG_RA_CONTROL_HZ_FieldMask                             0x00117131
#define MWV207REG_RA_CONTROL_HZ_ReadMask                              0x00117131
#define MWV207REG_RA_CONTROL_HZ_WriteMask                             0x00117131
#define MWV207REG_RA_CONTROL_HZ_ResetValue                            0x00000000


#define MWV207REG_RA_CONTROL_HZ_FORMAT                                       0:0
#define MWV207REG_RA_CONTROL_HZ_FORMAT_End                                     0
#define MWV207REG_RA_CONTROL_HZ_FORMAT_Start                                   0
#define MWV207REG_RA_CONTROL_HZ_FORMAT_Type                                  U01

#define   MWV207REG_RA_CONTROL_HZ_FORMAT_HZ16_MIN_MAX                        0x0

#define   MWV207REG_RA_CONTROL_HZ_FORMAT_HZ24_MIN_MAX                        0x1


#define MWV207REG_RA_CONTROL_HZ_MODE1                                        5:4
#define MWV207REG_RA_CONTROL_HZ_MODE1_End                                      5
#define MWV207REG_RA_CONTROL_HZ_MODE1_Start                                    4
#define MWV207REG_RA_CONTROL_HZ_MODE1_Type                                   U02

#define   MWV207REG_RA_CONTROL_HZ_MODE1_DISABLED                             0x0

#define   MWV207REG_RA_CONTROL_HZ_MODE1_READ_ONLY                            0x1

#define   MWV207REG_RA_CONTROL_HZ_MODE1_ENABLED                              0x2


#define MWV207REG_RA_CONTROL_HZ_LEVEL1                                       8:8
#define MWV207REG_RA_CONTROL_HZ_LEVEL1_End                                     8
#define MWV207REG_RA_CONTROL_HZ_LEVEL1_Start                                   8
#define MWV207REG_RA_CONTROL_HZ_LEVEL1_Type                                  U01

#define   MWV207REG_RA_CONTROL_HZ_LEVEL1_TILE2X2                             0x0

#define   MWV207REG_RA_CONTROL_HZ_LEVEL1_TILE4X4                             0x1


#define MWV207REG_RA_CONTROL_HZ_COMPARE                                    14:12
#define MWV207REG_RA_CONTROL_HZ_COMPARE_End                                   14
#define MWV207REG_RA_CONTROL_HZ_COMPARE_Start                                 12
#define MWV207REG_RA_CONTROL_HZ_COMPARE_Type                                 U03

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_NEVER                              0x0

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_LESS                               0x1

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_EQUAL                              0x2

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_LESS_EQUAL                         0x3

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_GREATER                            0x4

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_NOT_EQUAL                          0x5

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_GREATER_EQUAL                      0x6

#define   MWV207REG_RA_CONTROL_HZ_COMPARE_ALWAYS                             0x7


#define MWV207REG_RA_CONTROL_HZ_KILL                                       16:16
#define MWV207REG_RA_CONTROL_HZ_KILL_End                                      16
#define MWV207REG_RA_CONTROL_HZ_KILL_Start                                    16
#define MWV207REG_RA_CONTROL_HZ_KILL_Type                                    U01

#define   MWV207REG_RA_CONTROL_HZ_KILL_NONE                                  0x0
#define   MWV207REG_RA_CONTROL_HZ_KILL_HZ_PRE_PASS                           0x1


#define MWV207REG_RA_CONTROL_HZ_MSAA                                       20:20
#define MWV207REG_RA_CONTROL_HZ_MSAA_End                                      20
#define MWV207REG_RA_CONTROL_HZ_MSAA_Start                                    20
#define MWV207REG_RA_CONTROL_HZ_MSAA_Type                                    U01

#define   MWV207REG_RA_CONTROL_HZ_MSAA_NORMAL                                0x0

#define   MWV207REG_RA_CONTROL_HZ_MSAA_PRE_PASS                              0x1




#define mwv207regHZBaseAddress1RegAddrs                                   0x0389
#define MWV207REG_HZ_BASE_ADDRESS1_Address                               0x00E24
#define MWV207REG_HZ_BASE_ADDRESS1_MSB                                        15
#define MWV207REG_HZ_BASE_ADDRESS1_LSB                                         0
#define MWV207REG_HZ_BASE_ADDRESS1_BLK                                         0
#define MWV207REG_HZ_BASE_ADDRESS1_Count                                       1
#define MWV207REG_HZ_BASE_ADDRESS1_FieldMask                          0xFFFFFFFF
#define MWV207REG_HZ_BASE_ADDRESS1_ReadMask                           0xFFFFFFFF
#define MWV207REG_HZ_BASE_ADDRESS1_WriteMask                          0xFFFFFFFF
#define MWV207REG_HZ_BASE_ADDRESS1_ResetValue                         0x00000000

#define MWV207REG_HZ_BASE_ADDRESS1_ADDRESS                                  31:0
#define MWV207REG_HZ_BASE_ADDRESS1_ADDRESS_End                                31
#define MWV207REG_HZ_BASE_ADDRESS1_ADDRESS_Start                               0
#define MWV207REG_HZ_BASE_ADDRESS1_ADDRESS_Type                              U32




#define mwv207regHZTileStatus1RegAddrs                                    0x038A
#define MWV207REG_HZ_TILE_STATUS1_Address                                0x00E28
#define MWV207REG_HZ_TILE_STATUS1_MSB                                         15
#define MWV207REG_HZ_TILE_STATUS1_LSB                                          0
#define MWV207REG_HZ_TILE_STATUS1_BLK                                          0
#define MWV207REG_HZ_TILE_STATUS1_Count                                        1
#define MWV207REG_HZ_TILE_STATUS1_FieldMask                           0xFFFFFFFF
#define MWV207REG_HZ_TILE_STATUS1_ReadMask                            0xFFFFFFFF
#define MWV207REG_HZ_TILE_STATUS1_WriteMask                           0xFFFFFFFF
#define MWV207REG_HZ_TILE_STATUS1_ResetValue                          0x00000000

#define MWV207REG_HZ_TILE_STATUS1_ADDRESS                                   31:0
#define MWV207REG_HZ_TILE_STATUS1_ADDRESS_End                                 31
#define MWV207REG_HZ_TILE_STATUS1_ADDRESS_Start                                0
#define MWV207REG_HZ_TILE_STATUS1_ADDRESS_Type                               U32




#define mwv207regRADebugRegAddrs                                          0x038B
#define MWV207REG_RA_DEBUG_Address                                       0x00E2C
#define MWV207REG_RA_DEBUG_MSB                                                15
#define MWV207REG_RA_DEBUG_LSB                                                 0
#define MWV207REG_RA_DEBUG_BLK                                                 0
#define MWV207REG_RA_DEBUG_Count                                               1
#define MWV207REG_RA_DEBUG_FieldMask                                  0x00000111
#define MWV207REG_RA_DEBUG_ReadMask                                   0x00000111
#define MWV207REG_RA_DEBUG_WriteMask                                  0x00000111
#define MWV207REG_RA_DEBUG_ResetValue                                 0x00000000


#define MWV207REG_RA_DEBUG_ZFLUSH_TO_HZ                                      0:0
#define MWV207REG_RA_DEBUG_ZFLUSH_TO_HZ_End                                    0
#define MWV207REG_RA_DEBUG_ZFLUSH_TO_HZ_Start                                  0
#define MWV207REG_RA_DEBUG_ZFLUSH_TO_HZ_Type                                 U01
#define   MWV207REG_RA_DEBUG_ZFLUSH_TO_HZ_ENABLED                            0x0
#define   MWV207REG_RA_DEBUG_ZFLUSH_TO_HZ_DISABLED                           0x1


#define MWV207REG_RA_DEBUG_HZ_MERGE                                          4:4
#define MWV207REG_RA_DEBUG_HZ_MERGE_End                                        4
#define MWV207REG_RA_DEBUG_HZ_MERGE_Start                                      4
#define MWV207REG_RA_DEBUG_HZ_MERGE_Type                                     U01
#define   MWV207REG_RA_DEBUG_HZ_MERGE_ENABLED                                0x0
#define   MWV207REG_RA_DEBUG_HZ_MERGE_DISABLED                               0x1


#define MWV207REG_RA_DEBUG_ACCEPT                                            8:8
#define MWV207REG_RA_DEBUG_ACCEPT_End                                          8
#define MWV207REG_RA_DEBUG_ACCEPT_Start                                        8
#define MWV207REG_RA_DEBUG_ACCEPT_Type                                       U01
#define   MWV207REG_RA_DEBUG_ACCEPT_ENABLED                                  0x0
#define   MWV207REG_RA_DEBUG_ACCEPT_DISABLED                                 0x1




#define mwv207regRATimeOutRegAddrs                                        0x038C
#define MWV207REG_RA_TIME_OUT_Address                                    0x00E30
#define MWV207REG_RA_TIME_OUT_MSB                                             15
#define MWV207REG_RA_TIME_OUT_LSB                                              0
#define MWV207REG_RA_TIME_OUT_BLK                                              0
#define MWV207REG_RA_TIME_OUT_Count                                            1
#define MWV207REG_RA_TIME_OUT_FieldMask                               0x0000FFFF
#define MWV207REG_RA_TIME_OUT_ReadMask                                0x0000FFFF
#define MWV207REG_RA_TIME_OUT_WriteMask                               0x0000FFFF
#define MWV207REG_RA_TIME_OUT_ResetValue                              0x00000080

#define MWV207REG_RA_TIME_OUT_TIME_OUT_VALUE                                15:0
#define MWV207REG_RA_TIME_OUT_TIME_OUT_VALUE_End                              15
#define MWV207REG_RA_TIME_OUT_TIME_OUT_VALUE_Start                             0
#define MWV207REG_RA_TIME_OUT_TIME_OUT_VALUE_Type                            U16




#define mwv207regRAControlExRegAddrs                                      0x038D
#define MWV207REG_RA_CONTROL_EX_Address                                  0x00E34
#define MWV207REG_RA_CONTROL_EX_MSB                                           15
#define MWV207REG_RA_CONTROL_EX_LSB                                            0
#define MWV207REG_RA_CONTROL_EX_BLK                                            0
#define MWV207REG_RA_CONTROL_EX_Count                                          1
#define MWV207REG_RA_CONTROL_EX_FieldMask                             0x000003F3
#define MWV207REG_RA_CONTROL_EX_ReadMask                              0x000003F3
#define MWV207REG_RA_CONTROL_EX_WriteMask                             0x000003F3
#define MWV207REG_RA_CONTROL_EX_ResetValue                            0x00000000


#define MWV207REG_RA_CONTROL_EX_POSITION                                     1:0
#define MWV207REG_RA_CONTROL_EX_POSITION_End                                   1
#define MWV207REG_RA_CONTROL_EX_POSITION_Start                                 0
#define MWV207REG_RA_CONTROL_EX_POSITION_Type                                U02
#define   MWV207REG_RA_CONTROL_EX_POSITION_CENTER                            0x0
#define   MWV207REG_RA_CONTROL_EX_POSITION_CENTROID                          0x1
#define   MWV207REG_RA_CONTROL_EX_POSITION_SAMPLE                            0x2


#define MWV207REG_RA_CONTROL_EX_RENDER_ARRAY                                 4:4
#define MWV207REG_RA_CONTROL_EX_RENDER_ARRAY_End                               4
#define MWV207REG_RA_CONTROL_EX_RENDER_ARRAY_Start                             4
#define MWV207REG_RA_CONTROL_EX_RENDER_ARRAY_Type                            U01

#define   MWV207REG_RA_CONTROL_EX_RENDER_ARRAY_DISABLED                      0x0
#define   MWV207REG_RA_CONTROL_EX_RENDER_ARRAY_ENABLED                       0x1


#define MWV207REG_RA_CONTROL_EX_EARLY_DEPTH_IN_APP                           5:5
#define MWV207REG_RA_CONTROL_EX_EARLY_DEPTH_IN_APP_End                         5
#define MWV207REG_RA_CONTROL_EX_EARLY_DEPTH_IN_APP_Start                       5
#define MWV207REG_RA_CONTROL_EX_EARLY_DEPTH_IN_APP_Type                      U01
#define   MWV207REG_RA_CONTROL_EX_EARLY_DEPTH_IN_APP_DISABLED                0x0
#define   MWV207REG_RA_CONTROL_EX_EARLY_DEPTH_IN_APP_ENABLED                 0x1

#define MWV207REG_RA_CONTROL_EX_FORCE_HZ_EZ_CLOCK_ON                         6:6
#define MWV207REG_RA_CONTROL_EX_FORCE_HZ_EZ_CLOCK_ON_End                       6
#define MWV207REG_RA_CONTROL_EX_FORCE_HZ_EZ_CLOCK_ON_Start                     6
#define MWV207REG_RA_CONTROL_EX_FORCE_HZ_EZ_CLOCK_ON_Type                    U01
#define   MWV207REG_RA_CONTROL_EX_FORCE_HZ_EZ_CLOCK_ON_DISABLED              0x0
#define   MWV207REG_RA_CONTROL_EX_FORCE_HZ_EZ_CLOCK_ON_ENABLED               0x1


#define MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT                          9:7
#define MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_End                        9
#define MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_Start                      7
#define MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_Type                     U03
#define   MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_DISABLED               0x0
#define   MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_SAMPLE1                0x1
#define   MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_SAMPLE2                0x2
#define   MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_SAMPLE4                0x3
#define   MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_SAMPLE8                0x4
#define   MWV207REG_RA_CONTROL_EX_FORCED_SAMPLE_COUNT_SAMPLE16               0x5


#endif


