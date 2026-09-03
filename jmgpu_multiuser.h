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




#ifndef __AQResolveReg_h__
#define __AQResolveReg_h__


#define AQRsTriggerRegAddrs                                               0x0580
#define AQ_RS_TRIGGER_Address                                            0x01600
#define AQ_RS_TRIGGER_MSB                                                     15
#define AQ_RS_TRIGGER_LSB                                                      0
#define AQ_RS_TRIGGER_BLK                                                      0
#define AQ_RS_TRIGGER_Count                                                    1
#define AQ_RS_TRIGGER_FieldMask                                       0x00000001
#define AQ_RS_TRIGGER_ReadMask                                        0x00000001
#define AQ_RS_TRIGGER_WriteMask                                       0x00000001
#define AQ_RS_TRIGGER_ResetValue                                      0x00000000


#define AQ_RS_TRIGGER_TRIG                                                   0:0
#define AQ_RS_TRIGGER_TRIG_End                                                 0
#define AQ_RS_TRIGGER_TRIG_Start                                               0
#define AQ_RS_TRIGGER_TRIG_Type                                              U01

#define AQRsConfigRegAddrs                                                0x0581
#define AQ_RS_CONFIG_Address                                             0x01604
#define AQ_RS_CONFIG_MSB                                                      15
#define AQ_RS_CONFIG_LSB                                                       0
#define AQ_RS_CONFIG_BLK                                                       0
#define AQ_RS_CONFIG_Count                                                     1
#define AQ_RS_CONFIG_FieldMask                                        0x7777FFFF
#define AQ_RS_CONFIG_ReadMask                                         0x7777FFFF
#define AQ_RS_CONFIG_WriteMask                                        0x7777FFFF
#define AQ_RS_CONFIG_ResetValue                                       0x00000000


#define AQ_RS_CONFIG_RS_SRC_FORMAT                                           4:0
#define AQ_RS_CONFIG_RS_SRC_FORMAT_End                                         4
#define AQ_RS_CONFIG_RS_SRC_FORMAT_Start                                       0
#define AQ_RS_CONFIG_RS_SRC_FORMAT_Type                                      U05
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_X4R4G4B4                               0x00
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_A4R4G4B4                               0x01
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_X1R5G5B5                               0x02
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_A1R5G5B5                               0x03
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_R5G6B5                                 0x04
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_X8R8G8B8                               0x05
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_A8R8G8B8                               0x06
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_YUY2                                   0x07
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_UYVY                                   0x08
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_INDEX8                                 0x09
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_MONOCHROME                             0x0A
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_HDR7E3                                 0x0B
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_HDR6E4                                 0x0C
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_HDR5E5                                 0x0D
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_HDR6E5                                 0x0E
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_YV12                                   0x0F
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_A8                                     0x10
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RF16                                   0x11
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RF16GF16                               0x12
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RF16GF16BF16AF16                       0x13
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RF32                                   0x14
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RF32GF32                               0x15
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_R10G10B10A2                            0x16
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_D24S8                                  0x17
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_D16                                    0x18
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RI8GI8BI8AI8                           0x19
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RI16                                   0x1A
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RI16GI16                               0x1B
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RI16GI16BI16AI16                       0x1C
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RI32                                   0x14
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RI32GI32                               0x15
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RF11GF11BF10                           0x1D
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_RI10GI10BI10AI2                        0x1E
#define   AQ_RS_CONFIG_RS_SRC_FORMAT_R8G8                                   0x1F

#define AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE                                     6:5
#define AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE_End                                   6
#define AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE_Start                                 5
#define AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE_Type                                U02
#define   AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE_DISABLE                           0x0
#define   AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE_ENABLE2X1                         0x1
#define   AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE_ENABLE1X2                         0x2

#define   AQ_RS_CONFIG_RS_SRC_SUPER_SAMPLE_ENABLE2X2                         0x3

#define AQ_RS_CONFIG_RS_SRC_TILE_ENABLE                                      7:7
#define AQ_RS_CONFIG_RS_SRC_TILE_ENABLE_End                                    7
#define AQ_RS_CONFIG_RS_SRC_TILE_ENABLE_Start                                  7
#define AQ_RS_CONFIG_RS_SRC_TILE_ENABLE_Type                                 U01
#define   AQ_RS_CONFIG_RS_SRC_TILE_ENABLE_DISABLE                            0x0

#define   AQ_RS_CONFIG_RS_SRC_TILE_ENABLE_ENABLE                             0x1


#define AQ_RS_CONFIG_RS_DEST_FORMAT                                         12:8
#define AQ_RS_CONFIG_RS_DEST_FORMAT_End                                       12
#define AQ_RS_CONFIG_RS_DEST_FORMAT_Start                                      8
#define AQ_RS_CONFIG_RS_DEST_FORMAT_Type                                     U05
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_X4R4G4B4                              0x00
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_A4R4G4B4                              0x01
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_X1R5G5B5                              0x02
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_A1R5G5B5                              0x03
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_R5G6B5                                0x04
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_X8R8G8B8                              0x05
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_A8R8G8B8                              0x06
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_YUY2                                  0x07
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_UYVY                                  0x08
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_INDEX8                                0x09
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_MONOCHROME                            0x0A
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_HDR7E3                                0x0B
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_HDR6E4                                0x0C
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_HDR5E5                                0x0D
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_HDR6E5                                0x0E
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_YV12                                  0x0F
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_A8                                    0x10
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RF16                                  0x11
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RF16GF16                              0x12
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RF16GF16BF16AF16                      0x13
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RF32                                  0x14
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RF32GF32                              0x15
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_R10G10B10A2                           0x16
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_D24S8                                 0x17
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_D16                                   0x18
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RI8GI8BI8AI8                          0x19
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RI16                                  0x1A
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RI16GI16                              0x1B
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RI16GI16BI16AI16                      0x1C
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RI32                                  0x14
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RI32GI32                              0x15
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RF11GF11BF10                          0x1D
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_RI10GI10BI10AI2                       0x1E
#define   AQ_RS_CONFIG_RS_DEST_FORMAT_R8G8                                  0x1F

#define AQ_RS_CONFIG_RS_DEST_SRGB                                          13:13
#define AQ_RS_CONFIG_RS_DEST_SRGB_End                                         13
#define AQ_RS_CONFIG_RS_DEST_SRGB_Start                                       13
#define AQ_RS_CONFIG_RS_DEST_SRGB_Type                                       U01
#define   AQ_RS_CONFIG_RS_DEST_SRGB_DISABLE                                  0x0

#define   AQ_RS_CONFIG_RS_DEST_SRGB_ENABLE                                   0x1

#define AQ_RS_CONFIG_RS_DEST_TILE_ENABLE                                   14:14
#define AQ_RS_CONFIG_RS_DEST_TILE_ENABLE_End                                  14
#define AQ_RS_CONFIG_RS_DEST_TILE_ENABLE_Start                                14
#define AQ_RS_CONFIG_RS_DEST_TILE_ENABLE_Type                                U01
#define   AQ_RS_CONFIG_RS_DEST_TILE_ENABLE_DISABLE                           0x0

#define   AQ_RS_CONFIG_RS_DEST_TILE_ENABLE_ENABLE                            0x1


#define AQ_RS_CONFIG_YUV_STANDARD                                          15:15
#define AQ_RS_CONFIG_YUV_STANDARD_End                                         15
#define AQ_RS_CONFIG_YUV_STANDARD_Start                                       15
#define AQ_RS_CONFIG_YUV_STANDARD_Type                                       U01

#define   AQ_RS_CONFIG_YUV_STANDARD_YUV601                                   0x0

#define   AQ_RS_CONFIG_YUV_STANDARD_YUV709                                   0x1

#define AQ_RS_CONFIG_RS_EDGE_DETECT_ENABLE                                 16:16
#define AQ_RS_CONFIG_RS_EDGE_DETECT_ENABLE_End                                16
#define AQ_RS_CONFIG_RS_EDGE_DETECT_ENABLE_Start                              16
#define AQ_RS_CONFIG_RS_EDGE_DETECT_ENABLE_Type                              U01
#define   AQ_RS_CONFIG_RS_EDGE_DETECT_ENABLE_DISABLE                         0x0

#define   AQ_RS_CONFIG_RS_EDGE_DETECT_ENABLE_ENABLE                          0x1

#define AQ_RS_CONFIG_RS_EDGE_DETECT_ZMETHOD                                17:17
#define AQ_RS_CONFIG_RS_EDGE_DETECT_ZMETHOD_End                               17
#define AQ_RS_CONFIG_RS_EDGE_DETECT_ZMETHOD_Start                             17
#define AQ_RS_CONFIG_RS_EDGE_DETECT_ZMETHOD_Type                             U01
#define   AQ_RS_CONFIG_RS_EDGE_DETECT_ZMETHOD_NONE                           0x0

#define   AQ_RS_CONFIG_RS_EDGE_DETECT_ZMETHOD_DIFF2                          0x1

#define AQ_RS_CONFIG_RS_EDGE_DETECT_LINE_CHECK                             18:18
#define AQ_RS_CONFIG_RS_EDGE_DETECT_LINE_CHECK_End                            18
#define AQ_RS_CONFIG_RS_EDGE_DETECT_LINE_CHECK_Start                          18
#define AQ_RS_CONFIG_RS_EDGE_DETECT_LINE_CHECK_Type                          U01
#define   AQ_RS_CONFIG_RS_EDGE_DETECT_LINE_CHECK_DISABLE                     0x0
#define   AQ_RS_CONFIG_RS_EDGE_DETECT_LINE_CHECK_ENABLE                      0x1

#define AQ_RS_CONFIG_RS_EDGE_DETECT_SMETHOD                                20:20
#define AQ_RS_CONFIG_RS_EDGE_DETECT_SMETHOD_End                               20
#define AQ_RS_CONFIG_RS_EDGE_DETECT_SMETHOD_Start                             20
#define AQ_RS_CONFIG_RS_EDGE_DETECT_SMETHOD_Type                             U01
#define   AQ_RS_CONFIG_RS_EDGE_DETECT_SMETHOD_DISABLE                        0x0

#define   AQ_RS_CONFIG_RS_EDGE_DETECT_SMETHOD_ENABLE                         0x1

#define AQ_RS_CONFIG_RS_EDGE_DETECT_CMETHOD                                21:21
#define AQ_RS_CONFIG_RS_EDGE_DETECT_CMETHOD_End                               21
#define AQ_RS_CONFIG_RS_EDGE_DETECT_CMETHOD_Start                             21
#define AQ_RS_CONFIG_RS_EDGE_DETECT_CMETHOD_Type                             U01
#define   AQ_RS_CONFIG_RS_EDGE_DETECT_CMETHOD_DISABLE                        0x0

#define   AQ_RS_CONFIG_RS_EDGE_DETECT_CMETHOD_ENABLE                         0x1


#define AQ_RS_CONFIG_DEPTH_FORMAT                                          22:22
#define AQ_RS_CONFIG_DEPTH_FORMAT_End                                         22
#define AQ_RS_CONFIG_DEPTH_FORMAT_Start                                       22
#define AQ_RS_CONFIG_DEPTH_FORMAT_Type                                       U01
#define   AQ_RS_CONFIG_DEPTH_FORMAT_Z16                                      0x0
#define   AQ_RS_CONFIG_DEPTH_FORMAT_Z24                                      0x1


#define AQ_RS_CONFIG_INTERLEAVED                                           26:24
#define AQ_RS_CONFIG_INTERLEAVED_End                                          26
#define AQ_RS_CONFIG_INTERLEAVED_Start                                        24
#define AQ_RS_CONFIG_INTERLEAVED_Type                                        U03
#define   AQ_RS_CONFIG_INTERLEAVED_DISABLED                                  0x0
#define   AQ_RS_CONFIG_INTERLEAVED_C16D16                                    0x1
#define   AQ_RS_CONFIG_INTERLEAVED_C16D32                                    0x2
#define   AQ_RS_CONFIG_INTERLEAVED_C32D16                                    0x3
#define   AQ_RS_CONFIG_INTERLEAVED_C32D32                                    0x4

#define AQ_RS_CONFIG_RS_SRC_DEPTH_TILE_ENABLE                              28:28
#define AQ_RS_CONFIG_RS_SRC_DEPTH_TILE_ENABLE_End                             28
#define AQ_RS_CONFIG_RS_SRC_DEPTH_TILE_ENABLE_Start                           28
#define AQ_RS_CONFIG_RS_SRC_DEPTH_TILE_ENABLE_Type                           U01
#define   AQ_RS_CONFIG_RS_SRC_DEPTH_TILE_ENABLE_DISABLE                      0x0

#define   AQ_RS_CONFIG_RS_SRC_DEPTH_TILE_ENABLE_ENABLE                       0x1

#define AQ_RS_CONFIG_FLIP_RB                                               29:29
#define AQ_RS_CONFIG_FLIP_RB_End                                              29
#define AQ_RS_CONFIG_FLIP_RB_Start                                            29
#define AQ_RS_CONFIG_FLIP_RB_Type                                            U01
#define   AQ_RS_CONFIG_FLIP_RB_DISABLE                                       0x0
#define   AQ_RS_CONFIG_FLIP_RB_ENABLE                                        0x1

#define AQ_RS_CONFIG_FLIP_Y                                                30:30
#define AQ_RS_CONFIG_FLIP_Y_End                                               30
#define AQ_RS_CONFIG_FLIP_Y_Start                                             30
#define AQ_RS_CONFIG_FLIP_Y_Type                                             U01
#define   AQ_RS_CONFIG_FLIP_Y_DISABLE                                        0x0

#define   AQ_RS_CONFIG_FLIP_Y_ENABLE                                         0x1




#define AQRsSrcAddressRegAddrs                                            0x0582
#define AQ_RS_SRC_ADDRESS_Address                                        0x01608
#define AQ_RS_SRC_ADDRESS_MSB                                                 15
#define AQ_RS_SRC_ADDRESS_LSB                                                  0
#define AQ_RS_SRC_ADDRESS_BLK                                                  0
#define AQ_RS_SRC_ADDRESS_Count                                                1
#define AQ_RS_SRC_ADDRESS_FieldMask                                   0xFFFFFFFF
#define AQ_RS_SRC_ADDRESS_ReadMask                                    0xFFFFFFFC
#define AQ_RS_SRC_ADDRESS_WriteMask                                   0xFFFFFFFC
#define AQ_RS_SRC_ADDRESS_ResetValue                                  0x00000000

#define AQ_RS_SRC_ADDRESS_TYPE                                             31:31
#define AQ_RS_SRC_ADDRESS_TYPE_End                                            31
#define AQ_RS_SRC_ADDRESS_TYPE_Start                                          31
#define AQ_RS_SRC_ADDRESS_TYPE_Type                                          U01
#define   AQ_RS_SRC_ADDRESS_TYPE_SYSTEM                                      0x0
#define   AQ_RS_SRC_ADDRESS_TYPE_VIRTUAL_SYSTEM                              0x1

#define AQ_RS_SRC_ADDRESS_ADDRESS                                           30:0
#define AQ_RS_SRC_ADDRESS_ADDRESS_End                                         30
#define AQ_RS_SRC_ADDRESS_ADDRESS_Start                                        0
#define AQ_RS_SRC_ADDRESS_ADDRESS_Type                                       U31

#define AQRsSrcStrideRegAddrs                                             0x0583
#define AQ_RS_SRC_STRIDE_Address                                         0x0160C
#define AQ_RS_SRC_STRIDE_MSB                                                  15
#define AQ_RS_SRC_STRIDE_LSB                                                   0
#define AQ_RS_SRC_STRIDE_BLK                                                   0
#define AQ_RS_SRC_STRIDE_Count                                                 1
#define AQ_RS_SRC_STRIDE_FieldMask                                    0xF80FFFFF
#define AQ_RS_SRC_STRIDE_ReadMask                                     0xF80FFFFF
#define AQ_RS_SRC_STRIDE_WriteMask                                    0xF80FFFFF
#define AQ_RS_SRC_STRIDE_ResetValue                                   0x00000000


#define AQ_RS_SRC_STRIDE_STRIDE                                             19:0
#define AQ_RS_SRC_STRIDE_STRIDE_End                                           19
#define AQ_RS_SRC_STRIDE_STRIDE_Start                                          0
#define AQ_RS_SRC_STRIDE_STRIDE_Type                                         U20

#define AQ_RS_SRC_STRIDE_SUPER_TILE                                        31:31
#define AQ_RS_SRC_STRIDE_SUPER_TILE_End                                       31
#define AQ_RS_SRC_STRIDE_SUPER_TILE_Start                                     31
#define AQ_RS_SRC_STRIDE_SUPER_TILE_Type                                     U01
#define   AQ_RS_SRC_STRIDE_SUPER_TILE_DISABLED                               0x0
#define   AQ_RS_SRC_STRIDE_SUPER_TILE_ENABLED                                0x1

#define AQ_RS_SRC_STRIDE_MULTI_TILE                                        30:30
#define AQ_RS_SRC_STRIDE_MULTI_TILE_End                                       30
#define AQ_RS_SRC_STRIDE_MULTI_TILE_Start                                     30
#define AQ_RS_SRC_STRIDE_MULTI_TILE_Type                                     U01
#define   AQ_RS_SRC_STRIDE_MULTI_TILE_DISABLED                               0x0
#define   AQ_RS_SRC_STRIDE_MULTI_TILE_ENABLED                                0x1


#define AQ_RS_SRC_STRIDE_CACHE256                                          29:29
#define AQ_RS_SRC_STRIDE_CACHE256_End                                         29
#define AQ_RS_SRC_STRIDE_CACHE256_Start                                       29
#define AQ_RS_SRC_STRIDE_CACHE256_Type                                       U01
#define   AQ_RS_SRC_STRIDE_CACHE256_DISABLED                                 0x0
#define   AQ_RS_SRC_STRIDE_CACHE256_ENABLED                                  0x1


#define AQ_RS_SRC_STRIDE_TILE_MODE                                         28:27
#define AQ_RS_SRC_STRIDE_TILE_MODE_End                                        28
#define AQ_RS_SRC_STRIDE_TILE_MODE_Start                                      27
#define AQ_RS_SRC_STRIDE_TILE_MODE_Type                                      U02
#define   AQ_RS_SRC_STRIDE_TILE_MODE_TILED4X4                                0x0
#define   AQ_RS_SRC_STRIDE_TILE_MODE_SUPER_TILED_XMAJOR                      0x1
#define   AQ_RS_SRC_STRIDE_TILE_MODE_SUPER_TILED_YMAJOR                      0x2




#define AQRsDestAddressRegAddrs                                           0x0584
#define AQ_RS_DEST_ADDRESS_Address                                       0x01610
#define AQ_RS_DEST_ADDRESS_MSB                                                15
#define AQ_RS_DEST_ADDRESS_LSB                                                 0
#define AQ_RS_DEST_ADDRESS_BLK                                                 0
#define AQ_RS_DEST_ADDRESS_Count                                               1
#define AQ_RS_DEST_ADDRESS_FieldMask                                  0xFFFFFFFF
#define AQ_RS_DEST_ADDRESS_ReadMask                                   0xFFFFFFFC
#define AQ_RS_DEST_ADDRESS_WriteMask                                  0xFFFFFFFC
#define AQ_RS_DEST_ADDRESS_ResetValue                                 0x00000000

#define AQ_RS_DEST_ADDRESS_TYPE                                            31:31
#define AQ_RS_DEST_ADDRESS_TYPE_End                                           31
#define AQ_RS_DEST_ADDRESS_TYPE_Start                                         31
#define AQ_RS_DEST_ADDRESS_TYPE_Type                                         U01
#define   AQ_RS_DEST_ADDRESS_TYPE_SYSTEM                                     0x0
#define   AQ_RS_DEST_ADDRESS_TYPE_VIRTUAL_SYSTEM                             0x1

#define AQ_RS_DEST_ADDRESS_ADDRESS                                          30:0
#define AQ_RS_DEST_ADDRESS_ADDRESS_End                                        30
#define AQ_RS_DEST_ADDRESS_ADDRESS_Start                                       0
#define AQ_RS_DEST_ADDRESS_ADDRESS_Type                                      U31

#define AQRsDestStrideRegAddrs                                            0x0585
#define AQ_RS_DEST_STRIDE_Address                                        0x01614
#define AQ_RS_DEST_STRIDE_MSB                                                 15
#define AQ_RS_DEST_STRIDE_LSB                                                  0
#define AQ_RS_DEST_STRIDE_BLK                                                  0
#define AQ_RS_DEST_STRIDE_Count                                                1
#define AQ_RS_DEST_STRIDE_FieldMask                                   0xF80FFFFF
#define AQ_RS_DEST_STRIDE_ReadMask                                    0xF80FFFFF
#define AQ_RS_DEST_STRIDE_WriteMask                                   0xF80FFFFF
#define AQ_RS_DEST_STRIDE_ResetValue                                  0x00000000


#define AQ_RS_DEST_STRIDE_STRIDE                                            19:0
#define AQ_RS_DEST_STRIDE_STRIDE_End                                          19
#define AQ_RS_DEST_STRIDE_STRIDE_Start                                         0
#define AQ_RS_DEST_STRIDE_STRIDE_Type                                        U20

#define AQ_RS_DEST_STRIDE_SUPER_TILE                                       31:31
#define AQ_RS_DEST_STRIDE_SUPER_TILE_End                                      31
#define AQ_RS_DEST_STRIDE_SUPER_TILE_Start                                    31
#define AQ_RS_DEST_STRIDE_SUPER_TILE_Type                                    U01
#define   AQ_RS_DEST_STRIDE_SUPER_TILE_DISABLED                              0x0
#define   AQ_RS_DEST_STRIDE_SUPER_TILE_ENABLED                               0x1

#define AQ_RS_DEST_STRIDE_MULTI_TILE                                       30:30
#define AQ_RS_DEST_STRIDE_MULTI_TILE_End                                      30
#define AQ_RS_DEST_STRIDE_MULTI_TILE_Start                                    30
#define AQ_RS_DEST_STRIDE_MULTI_TILE_Type                                    U01
#define   AQ_RS_DEST_STRIDE_MULTI_TILE_DISABLED                              0x0
#define   AQ_RS_DEST_STRIDE_MULTI_TILE_ENABLED                               0x1


#define AQ_RS_DEST_STRIDE_CACHE256                                         29:29
#define AQ_RS_DEST_STRIDE_CACHE256_End                                        29
#define AQ_RS_DEST_STRIDE_CACHE256_Start                                      29
#define AQ_RS_DEST_STRIDE_CACHE256_Type                                      U01
#define   AQ_RS_DEST_STRIDE_CACHE256_DISABLED                                0x0
#define   AQ_RS_DEST_STRIDE_CACHE256_ENABLED                                 0x1


#define AQ_RS_DEST_STRIDE_TILE_MODE                                        28:27
#define AQ_RS_DEST_STRIDE_TILE_MODE_End                                       28
#define AQ_RS_DEST_STRIDE_TILE_MODE_Start                                     27
#define AQ_RS_DEST_STRIDE_TILE_MODE_Type                                     U02
#define   AQ_RS_DEST_STRIDE_TILE_MODE_TILED4X4                               0x0
#define   AQ_RS_DEST_STRIDE_TILE_MODE_SUPER_TILED_XMAJOR                     0x1
#define   AQ_RS_DEST_STRIDE_TILE_MODE_SUPER_TILED_YMAJOR                     0x2




#define AQRsDepSrcAddressRegAddrs                                         0x0586
#define AQ_RS_DEP_SRC_ADDRESS_Address                                    0x01618
#define AQ_RS_DEP_SRC_ADDRESS_MSB                                             15
#define AQ_RS_DEP_SRC_ADDRESS_LSB                                              0
#define AQ_RS_DEP_SRC_ADDRESS_BLK                                              0
#define AQ_RS_DEP_SRC_ADDRESS_Count                                            1
#define AQ_RS_DEP_SRC_ADDRESS_FieldMask                               0xFFFFFFFF
#define AQ_RS_DEP_SRC_ADDRESS_ReadMask                                0xFFFFFFFC
#define AQ_RS_DEP_SRC_ADDRESS_WriteMask                               0xFFFFFFFC
#define AQ_RS_DEP_SRC_ADDRESS_ResetValue                              0x00000000

#define AQ_RS_DEP_SRC_ADDRESS_TYPE                                         31:31
#define AQ_RS_DEP_SRC_ADDRESS_TYPE_End                                        31
#define AQ_RS_DEP_SRC_ADDRESS_TYPE_Start                                      31
#define AQ_RS_DEP_SRC_ADDRESS_TYPE_Type                                      U01
#define   AQ_RS_DEP_SRC_ADDRESS_TYPE_SYSTEM                                  0x0
#define   AQ_RS_DEP_SRC_ADDRESS_TYPE_VIRTUAL_SYSTEM                          0x1

#define AQ_RS_DEP_SRC_ADDRESS_ADDRESS                                       30:0
#define AQ_RS_DEP_SRC_ADDRESS_ADDRESS_End                                     30
#define AQ_RS_DEP_SRC_ADDRESS_ADDRESS_Start                                    0
#define AQ_RS_DEP_SRC_ADDRESS_ADDRESS_Type                                   U31




#define AQRsDepSrcStrideRegAddrs                                          0x0587
#define AQ_RS_DEP_SRC_STRIDE_Address                                     0x0161C
#define AQ_RS_DEP_SRC_STRIDE_MSB                                              15
#define AQ_RS_DEP_SRC_STRIDE_LSB                                               0
#define AQ_RS_DEP_SRC_STRIDE_BLK                                               0
#define AQ_RS_DEP_SRC_STRIDE_Count                                             1
#define AQ_RS_DEP_SRC_STRIDE_FieldMask                                0x0003FFFF
#define AQ_RS_DEP_SRC_STRIDE_ReadMask                                 0x0003FFFC
#define AQ_RS_DEP_SRC_STRIDE_WriteMask                                0x0003FFFC
#define AQ_RS_DEP_SRC_STRIDE_ResetValue                               0x00000000

#define AQ_RS_DEP_SRC_STRIDE_STRIDE                                         17:0
#define AQ_RS_DEP_SRC_STRIDE_STRIDE_End                                       17
#define AQ_RS_DEP_SRC_STRIDE_STRIDE_Start                                      0
#define AQ_RS_DEP_SRC_STRIDE_STRIDE_Type                                     U18




#define AQRsWindowSizeRegAddrs                                            0x0588
#define AQ_RS_WINDOW_SIZE_Address                                        0x01620
#define AQ_RS_WINDOW_SIZE_MSB                                                 15
#define AQ_RS_WINDOW_SIZE_LSB                                                  0
#define AQ_RS_WINDOW_SIZE_BLK                                                  0
#define AQ_RS_WINDOW_SIZE_Count                                                1
#define AQ_RS_WINDOW_SIZE_FieldMask                                   0xFFFFFFFF
#define AQ_RS_WINDOW_SIZE_ReadMask                                    0xFFFFFFFF
#define AQ_RS_WINDOW_SIZE_WriteMask                                   0xFFFFFFFF
#define AQ_RS_WINDOW_SIZE_ResetValue                                  0x00000000


#define AQ_RS_WINDOW_SIZE_WIDTH                                             15:0
#define AQ_RS_WINDOW_SIZE_WIDTH_End                                           15
#define AQ_RS_WINDOW_SIZE_WIDTH_Start                                          0
#define AQ_RS_WINDOW_SIZE_WIDTH_Type                                         U16


#define AQ_RS_WINDOW_SIZE_HEIGHT                                           31:16
#define AQ_RS_WINDOW_SIZE_HEIGHT_End                                          31
#define AQ_RS_WINDOW_SIZE_HEIGHT_Start                                        16
#define AQ_RS_WINDOW_SIZE_HEIGHT_Type                                        U16

#define AQRsEdgeDetectThreshRegAddrs                                      0x0589
#define AQ_RS_EDGE_DETECT_THRESH_Address                                 0x01624
#define AQ_RS_EDGE_DETECT_THRESH_MSB                                          15
#define AQ_RS_EDGE_DETECT_THRESH_LSB                                           0
#define AQ_RS_EDGE_DETECT_THRESH_BLK                                           0
#define AQ_RS_EDGE_DETECT_THRESH_Count                                         1
#define AQ_RS_EDGE_DETECT_THRESH_FieldMask                            0x00FFFFFF
#define AQ_RS_EDGE_DETECT_THRESH_ReadMask                             0x00FFFFFF
#define AQ_RS_EDGE_DETECT_THRESH_WriteMask                            0x00FFFFFF
#define AQ_RS_EDGE_DETECT_THRESH_ResetValue                           0x00000000


#define AQ_RS_EDGE_DETECT_THRESH_VALUE                                      23:0
#define AQ_RS_EDGE_DETECT_THRESH_VALUE_End                                    23
#define AQ_RS_EDGE_DETECT_THRESH_VALUE_Start                                   0
#define AQ_RS_EDGE_DETECT_THRESH_VALUE_Type                                  U24




#define AQRsEdgeFilterCoefRegAddrs                                        0x058A
#define AQ_RS_EDGE_FILTER_COEF_Address                                   0x01628
#define AQ_RS_EDGE_FILTER_COEF_MSB                                            15
#define AQ_RS_EDGE_FILTER_COEF_LSB                                             0
#define AQ_RS_EDGE_FILTER_COEF_BLK                                             0
#define AQ_RS_EDGE_FILTER_COEF_Count                                           1
#define AQ_RS_EDGE_FILTER_COEF_FieldMask                              0x0003FFFF
#define AQ_RS_EDGE_FILTER_COEF_ReadMask                               0x0003FFFF
#define AQ_RS_EDGE_FILTER_COEF_WriteMask                              0x0003FFFF
#define AQ_RS_EDGE_FILTER_COEF_ResetValue                             0x00000000

#define AQ_RS_EDGE_FILTER_COEF_CORNERS                                       5:0
#define AQ_RS_EDGE_FILTER_COEF_CORNERS_End                                     5
#define AQ_RS_EDGE_FILTER_COEF_CORNERS_Start                                   0
#define AQ_RS_EDGE_FILTER_COEF_CORNERS_Type                                  U06

#define AQ_RS_EDGE_FILTER_COEF_SIDES                                        11:6
#define AQ_RS_EDGE_FILTER_COEF_SIDES_End                                      11
#define AQ_RS_EDGE_FILTER_COEF_SIDES_Start                                     6
#define AQ_RS_EDGE_FILTER_COEF_SIDES_Type                                    U06

#define AQ_RS_EDGE_FILTER_COEF_CENTER                                      17:12
#define AQ_RS_EDGE_FILTER_COEF_CENTER_End                                     17
#define AQ_RS_EDGE_FILTER_COEF_CENTER_Start                                   12
#define AQ_RS_EDGE_FILTER_COEF_CENTER_Type                                   U06




#define AQRsDitherTableRegAddrs                                           0x058C
#define AQ_RS_DITHER_TABLE_Address                                       0x01630
#define AQ_RS_DITHER_TABLE_MSB                                                15
#define AQ_RS_DITHER_TABLE_LSB                                                 1
#define AQ_RS_DITHER_TABLE_BLK                                                 1
#define AQ_RS_DITHER_TABLE_Count                                               2
#define AQ_RS_DITHER_TABLE_FieldMask                                  0xFFFFFFFF
#define AQ_RS_DITHER_TABLE_ReadMask                                   0xFFFFFFFF
#define AQ_RS_DITHER_TABLE_WriteMask                                  0xFFFFFFFF
#define AQ_RS_DITHER_TABLE_ResetValue                                 0x00000000

#define AQ_RS_DITHER_TABLE_B0                                                7:0
#define AQ_RS_DITHER_TABLE_B0_End                                              7
#define AQ_RS_DITHER_TABLE_B0_Start                                            0
#define AQ_RS_DITHER_TABLE_B0_Type                                           U08

#define AQ_RS_DITHER_TABLE_B1                                               15:8
#define AQ_RS_DITHER_TABLE_B1_End                                             15
#define AQ_RS_DITHER_TABLE_B1_Start                                            8
#define AQ_RS_DITHER_TABLE_B1_Type                                           U08

#define AQ_RS_DITHER_TABLE_B2                                              23:16
#define AQ_RS_DITHER_TABLE_B2_End                                             23
#define AQ_RS_DITHER_TABLE_B2_Start                                           16
#define AQ_RS_DITHER_TABLE_B2_Type                                           U08

#define AQ_RS_DITHER_TABLE_B3                                              31:24
#define AQ_RS_DITHER_TABLE_B3_End                                             31
#define AQ_RS_DITHER_TABLE_B3_Start                                           24
#define AQ_RS_DITHER_TABLE_B3_Type                                           U08

#define AQRsNonFilterFrontZRegAddrs                                       0x058B
#define AQ_RS_NON_FILTER_FRONT_Z_Address                                 0x0162C
#define AQ_RS_NON_FILTER_FRONT_Z_MSB                                          15
#define AQ_RS_NON_FILTER_FRONT_Z_LSB                                           0
#define AQ_RS_NON_FILTER_FRONT_Z_BLK                                           0
#define AQ_RS_NON_FILTER_FRONT_Z_Count                                         1
#define AQ_RS_NON_FILTER_FRONT_Z_FieldMask                            0xFFFFFFFF
#define AQ_RS_NON_FILTER_FRONT_Z_ReadMask                             0xFFFFFFFF
#define AQ_RS_NON_FILTER_FRONT_Z_WriteMask                            0xFFFFFFFF
#define AQ_RS_NON_FILTER_FRONT_Z_ResetValue                           0x00000000


#define AQ_RS_NON_FILTER_FRONT_Z_RS_NON_FILTER_FRONT_Z                      31:0
#define AQ_RS_NON_FILTER_FRONT_Z_RS_NON_FILTER_FRONT_Z_End                    31
#define AQ_RS_NON_FILTER_FRONT_Z_RS_NON_FILTER_FRONT_Z_Start                   0
#define AQ_RS_NON_FILTER_FRONT_Z_RS_NON_FILTER_FRONT_Z_Type                  U32

#define AQRsDebugRegAddrs                                                 0x058E
#define AQ_RS_DEBUG_Address                                              0x01638
#define AQ_RS_DEBUG_MSB                                                       15
#define AQ_RS_DEBUG_LSB                                                        0
#define AQ_RS_DEBUG_BLK                                                        0
#define AQ_RS_DEBUG_Count                                                      1
#define AQ_RS_DEBUG_FieldMask                                         0x0000033F
#define AQ_RS_DEBUG_ReadMask                                          0x0000033F
#define AQ_RS_DEBUG_WriteMask                                         0x0000033F
#define AQ_RS_DEBUG_ResetValue                                        0x00000000


#define AQ_RS_DEBUG_DISABLE_LATENCY_OPTIMIZATION                             8:8
#define AQ_RS_DEBUG_DISABLE_LATENCY_OPTIMIZATION_End                           8
#define AQ_RS_DEBUG_DISABLE_LATENCY_OPTIMIZATION_Start                         8
#define AQ_RS_DEBUG_DISABLE_LATENCY_OPTIMIZATION_Type                        U01
#define   AQ_RS_DEBUG_DISABLE_LATENCY_OPTIMIZATION_ENABLE                    0x0
#define   AQ_RS_DEBUG_DISABLE_LATENCY_OPTIMIZATION_DISABLE                   0x1


#define AQ_RS_DEBUG_FILTER_TILE_COUNT                                        5:0
#define AQ_RS_DEBUG_FILTER_TILE_COUNT_End                                      5
#define AQ_RS_DEBUG_FILTER_TILE_COUNT_Start                                    0
#define AQ_RS_DEBUG_FILTER_TILE_COUNT_Type                                   U06
#define   AQ_RS_DEBUG_FILTER_TILE_COUNT_RESET_LOW                           0x0B
#define   AQ_RS_DEBUG_FILTER_TILE_COUNT_RESET_HIGH                          0x1A
#define   AQ_RS_DEBUG_FILTER_TILE_COUNT_RESET_VERY_HIGH                     0x38


#define AQ_RS_DEBUG_FORCE_WRITES_TO_PEC                                      9:9
#define AQ_RS_DEBUG_FORCE_WRITES_TO_PEC_End                                    9
#define AQ_RS_DEBUG_FORCE_WRITES_TO_PEC_Start                                  9
#define AQ_RS_DEBUG_FORCE_WRITES_TO_PEC_Type                                 U01

#define AQRsClearValueRegAddrs                                            0x0590
#define AQ_RS_CLEAR_VALUE_Address                                        0x01640
#define AQ_RS_CLEAR_VALUE_MSB                                                 15
#define AQ_RS_CLEAR_VALUE_LSB                                                  2
#define AQ_RS_CLEAR_VALUE_BLK                                                  2
#define AQ_RS_CLEAR_VALUE_Count                                                4
#define AQ_RS_CLEAR_VALUE_FieldMask                                   0xFFFFFFFF
#define AQ_RS_CLEAR_VALUE_ReadMask                                    0xFFFFFFFF
#define AQ_RS_CLEAR_VALUE_WriteMask                                   0xFFFFFFFF
#define AQ_RS_CLEAR_VALUE_ResetValue                                  0x00000000


#define AQ_RS_CLEAR_VALUE_VALUE                                             31:0
#define AQ_RS_CLEAR_VALUE_VALUE_End                                           31
#define AQ_RS_CLEAR_VALUE_VALUE_Start                                          0
#define AQ_RS_CLEAR_VALUE_VALUE_Type                                         U32

#define AQRsClearControlRegAddrs                                          0x058F
#define AQ_RS_CLEAR_CONTROL_Address                                      0x0163C
#define AQ_RS_CLEAR_CONTROL_MSB                                               15
#define AQ_RS_CLEAR_CONTROL_LSB                                                0
#define AQ_RS_CLEAR_CONTROL_BLK                                                0
#define AQ_RS_CLEAR_CONTROL_Count                                              1
#define AQ_RS_CLEAR_CONTROL_FieldMask                                 0x0003FFFF
#define AQ_RS_CLEAR_CONTROL_ReadMask                                  0x0003FFFF
#define AQ_RS_CLEAR_CONTROL_WriteMask                                 0x0003FFFF
#define AQ_RS_CLEAR_CONTROL_ResetValue                                0x00000000


#define AQ_RS_CLEAR_CONTROL_ENABLE                                         17:16
#define AQ_RS_CLEAR_CONTROL_ENABLE_End                                        17
#define AQ_RS_CLEAR_CONTROL_ENABLE_Start                                      16
#define AQ_RS_CLEAR_CONTROL_ENABLE_Type                                      U02
#define   AQ_RS_CLEAR_CONTROL_ENABLE_DISABLED                                0x0
#define   AQ_RS_CLEAR_CONTROL_ENABLE_CLEAR_ONE                               0x1
#define   AQ_RS_CLEAR_CONTROL_ENABLE_CLEAR_FOUR                              0x2
#define   AQ_RS_CLEAR_CONTROL_ENABLE_CLEAR64                                 0x3


#define AQ_RS_CLEAR_CONTROL_MASK                                            15:0
#define AQ_RS_CLEAR_CONTROL_MASK_End                                          15
#define AQ_RS_CLEAR_CONTROL_MASK_Start                                         0
#define AQ_RS_CLEAR_CONTROL_MASK_Type                                        U16




#define jmTileCacheFlushRegAddrs                                          0x0594
#define JM_TILE_CACHE_FLUSH_Address                                      0x01650
#define JM_TILE_CACHE_FLUSH_MSB                                               15
#define JM_TILE_CACHE_FLUSH_LSB                                                0
#define JM_TILE_CACHE_FLUSH_BLK                                                0
#define JM_TILE_CACHE_FLUSH_Count                                              1
#define JM_TILE_CACHE_FLUSH_FieldMask                                 0x000000F1
#define JM_TILE_CACHE_FLUSH_ReadMask                                  0x000000F1
#define JM_TILE_CACHE_FLUSH_WriteMask                                 0x000000F1
#define JM_TILE_CACHE_FLUSH_ResetValue                                0x00000000


#define JM_TILE_CACHE_FLUSH_FLUSH                                            0:0
#define JM_TILE_CACHE_FLUSH_FLUSH_End                                          0
#define JM_TILE_CACHE_FLUSH_FLUSH_Start                                        0
#define JM_TILE_CACHE_FLUSH_FLUSH_Type                                       U01
#define   JM_TILE_CACHE_FLUSH_FLUSH_DISABLE                                  0x0
#define   JM_TILE_CACHE_FLUSH_FLUSH_ENABLE                                   0x1


#define JM_TILE_CACHE_FLUSH_RESET_ZCOUNTER                                   4:4
#define JM_TILE_CACHE_FLUSH_RESET_ZCOUNTER_End                                 4
#define JM_TILE_CACHE_FLUSH_RESET_ZCOUNTER_Start                               4
#define JM_TILE_CACHE_FLUSH_RESET_ZCOUNTER_Type                              U01
#define   JM_TILE_CACHE_FLUSH_RESET_ZCOUNTER_DISABLE                         0x0
#define   JM_TILE_CACHE_FLUSH_RESET_ZCOUNTER_ENABLE                          0x1


#define JM_TILE_CACHE_FLUSH_RESET_CCOUNTER                                   5:5
#define JM_TILE_CACHE_FLUSH_RESET_CCOUNTER_End                                 5
#define JM_TILE_CACHE_FLUSH_RESET_CCOUNTER_Start                               5
#define JM_TILE_CACHE_FLUSH_RESET_CCOUNTER_Type                              U01
#define   JM_TILE_CACHE_FLUSH_RESET_CCOUNTER_DISABLE                         0x0
#define   JM_TILE_CACHE_FLUSH_RESET_CCOUNTER_ENABLE                          0x1


#define JM_TILE_CACHE_FLUSH_FLUSH_L2                                         6:6
#define JM_TILE_CACHE_FLUSH_FLUSH_L2_End                                       6
#define JM_TILE_CACHE_FLUSH_FLUSH_L2_Start                                     6
#define JM_TILE_CACHE_FLUSH_FLUSH_L2_Type                                    U01
#define   JM_TILE_CACHE_FLUSH_FLUSH_L2_DISABLE                               0x0
#define   JM_TILE_CACHE_FLUSH_FLUSH_L2_ENABLE                                0x1


#define JM_TILE_CACHE_FLUSH_RESET_COUNTER_HZ                                 7:7
#define JM_TILE_CACHE_FLUSH_RESET_COUNTER_HZ_End                               7
#define JM_TILE_CACHE_FLUSH_RESET_COUNTER_HZ_Start                             7
#define JM_TILE_CACHE_FLUSH_RESET_COUNTER_HZ_Type                            U01
#define   JM_TILE_CACHE_FLUSH_RESET_COUNTER_HZ_RESET                         0x1



#define jmMemoryConfigRegAddrs                                            0x0595
#define JM_MEMORY_CONFIG_Address                                         0x01654
#define JM_MEMORY_CONFIG_MSB                                                  15
#define JM_MEMORY_CONFIG_LSB                                                   0
#define JM_MEMORY_CONFIG_BLK                                                   0
#define JM_MEMORY_CONFIG_Count                                                 1
#define JM_MEMORY_CONFIG_FieldMask                                    0xFFFFFFFF
#define JM_MEMORY_CONFIG_ReadMask                                     0xFFFFFFFF
#define JM_MEMORY_CONFIG_WriteMask                                    0xFFFFFFFF
#define JM_MEMORY_CONFIG_ResetValue                                   0x00200000


#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_Z                                     0:0
#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_Z_End                                   0
#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_Z_Start                                 0
#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_Z_Type                                U01
#define   JM_MEMORY_CONFIG_FAST_CLEAR_EN_Z_DISABLE                           0x0
#define   JM_MEMORY_CONFIG_FAST_CLEAR_EN_Z_ENABLE                            0x1


#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_C                                     1:1
#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_C_End                                   1
#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_C_Start                                 1
#define JM_MEMORY_CONFIG_FAST_CLEAR_EN_C_Type                                U01
#define   JM_MEMORY_CONFIG_FAST_CLEAR_EN_C_DISABLE                           0x0
#define   JM_MEMORY_CONFIG_FAST_CLEAR_EN_C_ENABLE                            0x1


#define JM_MEMORY_CONFIG_COLOR16_BIT                                         2:2
#define JM_MEMORY_CONFIG_COLOR16_BIT_End                                       2
#define JM_MEMORY_CONFIG_COLOR16_BIT_Start                                     2
#define JM_MEMORY_CONFIG_COLOR16_BIT_Type                                    U01
#define   JM_MEMORY_CONFIG_COLOR16_BIT_DISABLE                               0x0
#define   JM_MEMORY_CONFIG_COLOR16_BIT_ENABLE                                0x1


#define JM_MEMORY_CONFIG_DEPTH16_BIT                                         3:3
#define JM_MEMORY_CONFIG_DEPTH16_BIT_End                                       3
#define JM_MEMORY_CONFIG_DEPTH16_BIT_Start                                     3
#define JM_MEMORY_CONFIG_DEPTH16_BIT_Type                                    U01
#define   JM_MEMORY_CONFIG_DEPTH16_BIT_DISABLE                               0x0
#define   JM_MEMORY_CONFIG_DEPTH16_BIT_ENABLE                                0x1


#define JM_MEMORY_CONFIG_AUTO_DISABLE_Z                                      4:4
#define JM_MEMORY_CONFIG_AUTO_DISABLE_Z_End                                    4
#define JM_MEMORY_CONFIG_AUTO_DISABLE_Z_Start                                  4
#define JM_MEMORY_CONFIG_AUTO_DISABLE_Z_Type                                 U01
#define   JM_MEMORY_CONFIG_AUTO_DISABLE_Z_DISABLE                            0x0
#define   JM_MEMORY_CONFIG_AUTO_DISABLE_Z_ENABLE                             0x1


#define JM_MEMORY_CONFIG_AUTO_DISABLE_C                                      5:5
#define JM_MEMORY_CONFIG_AUTO_DISABLE_C_End                                    5
#define JM_MEMORY_CONFIG_AUTO_DISABLE_C_Start                                  5
#define JM_MEMORY_CONFIG_AUTO_DISABLE_C_Type                                 U01
#define   JM_MEMORY_CONFIG_AUTO_DISABLE_C_DISABLE                            0x0
#define   JM_MEMORY_CONFIG_AUTO_DISABLE_C_ENABLE                             0x1


#define JM_MEMORY_CONFIG_COMPRESSION_EN_Z                                    6:6
#define JM_MEMORY_CONFIG_COMPRESSION_EN_Z_End                                  6
#define JM_MEMORY_CONFIG_COMPRESSION_EN_Z_Start                                6
#define JM_MEMORY_CONFIG_COMPRESSION_EN_Z_Type                               U01
#define   JM_MEMORY_CONFIG_COMPRESSION_EN_Z_DISABLE                          0x0
#define   JM_MEMORY_CONFIG_COMPRESSION_EN_Z_ENABLE                           0x1


#define JM_MEMORY_CONFIG_COMPRESSION_EN_C                                    7:7
#define JM_MEMORY_CONFIG_COMPRESSION_EN_C_End                                  7
#define JM_MEMORY_CONFIG_COMPRESSION_EN_C_Start                                7
#define JM_MEMORY_CONFIG_COMPRESSION_EN_C_Type                               U01
#define   JM_MEMORY_CONFIG_COMPRESSION_EN_C_DISABLE                          0x0
#define   JM_MEMORY_CONFIG_COMPRESSION_EN_C_ENABLE                           0x1

#define JM_MEMORY_CONFIG_COLOR_FORMAT                                       11:8
#define JM_MEMORY_CONFIG_COLOR_FORMAT_End                                     11
#define JM_MEMORY_CONFIG_COLOR_FORMAT_Start                                    8
#define JM_MEMORY_CONFIG_COLOR_FORMAT_Type                                   U04
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_ARGB4                                0x0
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_A1RGB5                               0x1
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_R5G6B5                               0x2
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_ARGB8                                0x3
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_RGB8                                 0x4
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_Z24S8                                0x5
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_Z24                                  0x6
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_VAA16                                0x7
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_Z16                                  0x8
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_S8                                   0x9
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_SINGLE_Y_U_V                         0xA
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_UV_MIX                               0xB
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_YUY2                                 0xC
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_SINGLE_Y_U_V_P010                    0xD
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_UV_MIX_P010                          0xE
#define   JM_MEMORY_CONFIG_COLOR_FORMAT_A2RGB10                              0xF


#define JM_MEMORY_CONFIG_ENABLE_HZ_FAST_CLEAR                              12:12
#define JM_MEMORY_CONFIG_ENABLE_HZ_FAST_CLEAR_End                             12
#define JM_MEMORY_CONFIG_ENABLE_HZ_FAST_CLEAR_Start                           12
#define JM_MEMORY_CONFIG_ENABLE_HZ_FAST_CLEAR_Type                           U01
#define   JM_MEMORY_CONFIG_ENABLE_HZ_FAST_CLEAR_DISABLE                      0x0
#define   JM_MEMORY_CONFIG_ENABLE_HZ_FAST_CLEAR_ENABLE                       0x1


#define JM_MEMORY_CONFIG_AUTO_DISABLE_HZ_FAST_CLEAR                        13:13
#define JM_MEMORY_CONFIG_AUTO_DISABLE_HZ_FAST_CLEAR_End                       13
#define JM_MEMORY_CONFIG_AUTO_DISABLE_HZ_FAST_CLEAR_Start                     13
#define JM_MEMORY_CONFIG_AUTO_DISABLE_HZ_FAST_CLEAR_Type                     U01
#define   JM_MEMORY_CONFIG_AUTO_DISABLE_HZ_FAST_CLEAR_DISABLE                0x0
#define   JM_MEMORY_CONFIG_AUTO_DISABLE_HZ_FAST_CLEAR_ENABLE                 0x1


#define JM_MEMORY_CONFIG_STENCIL_CTRL                                      14:14
#define JM_MEMORY_CONFIG_STENCIL_CTRL_End                                     14
#define JM_MEMORY_CONFIG_STENCIL_CTRL_Start                                   14
#define JM_MEMORY_CONFIG_STENCIL_CTRL_Type                                   U01
#define   JM_MEMORY_CONFIG_STENCIL_CTRL_DISABLE                              0x0
#define   JM_MEMORY_CONFIG_STENCIL_CTRL_ENABLE                               0x1


#define JM_MEMORY_CONFIG_COLOR_TILE_STATUS4_BIT                            15:15
#define JM_MEMORY_CONFIG_COLOR_TILE_STATUS4_BIT_End                           15
#define JM_MEMORY_CONFIG_COLOR_TILE_STATUS4_BIT_Start                         15
#define JM_MEMORY_CONFIG_COLOR_TILE_STATUS4_BIT_Type                         U01
#define   JM_MEMORY_CONFIG_COLOR_TILE_STATUS4_BIT_DISABLED                   0x0
#define   JM_MEMORY_CONFIG_COLOR_TILE_STATUS4_BIT_ENABLED                    0x1


#define JM_MEMORY_CONFIG_MAX_PREFETCH_COUNT                                25:16
#define JM_MEMORY_CONFIG_MAX_PREFETCH_COUNT_End                               25
#define JM_MEMORY_CONFIG_MAX_PREFETCH_COUNT_Start                             16
#define JM_MEMORY_CONFIG_MAX_PREFETCH_COUNT_Type                             U10


#define JM_MEMORY_CONFIG_MSAA_COMPRESSION                                  26:26
#define JM_MEMORY_CONFIG_MSAA_COMPRESSION_End                                 26
#define JM_MEMORY_CONFIG_MSAA_COMPRESSION_Start                               26
#define JM_MEMORY_CONFIG_MSAA_COMPRESSION_Type                               U01
#define   JM_MEMORY_CONFIG_MSAA_COMPRESSION_DISABLE                          0x0
#define   JM_MEMORY_CONFIG_MSAA_COMPRESSION_ENABLE                           0x1


#define JM_MEMORY_CONFIG_COLOR_YMAJOR                                      27:27
#define JM_MEMORY_CONFIG_COLOR_YMAJOR_End                                     27
#define JM_MEMORY_CONFIG_COLOR_YMAJOR_Start                                   27
#define JM_MEMORY_CONFIG_COLOR_YMAJOR_Type                                   U01
#define   JM_MEMORY_CONFIG_COLOR_YMAJOR_DISABLE                              0x0
#define   JM_MEMORY_CONFIG_COLOR_YMAJOR_ENABLE                               0x1


#define JM_MEMORY_CONFIG_DISABLE_L2                                        28:28
#define JM_MEMORY_CONFIG_DISABLE_L2_End                                       28
#define JM_MEMORY_CONFIG_DISABLE_L2_Start                                     28
#define JM_MEMORY_CONFIG_DISABLE_L2_Type                                     U01

#define JM_MEMORY_CONFIG_FIX_RAW_HAZARDS                                   29:29
#define JM_MEMORY_CONFIG_FIX_RAW_HAZARDS_End                                  29
#define JM_MEMORY_CONFIG_FIX_RAW_HAZARDS_Start                                29
#define JM_MEMORY_CONFIG_FIX_RAW_HAZARDS_Type                                U01


#define JM_MEMORY_CONFIG_COLOR64                                           30:30
#define JM_MEMORY_CONFIG_COLOR64_End                                          30
#define JM_MEMORY_CONFIG_COLOR64_Start                                        30
#define JM_MEMORY_CONFIG_COLOR64_Type                                        U01
#define   JM_MEMORY_CONFIG_COLOR64_COLOR16OR32                               0x0
#define   JM_MEMORY_CONFIG_COLOR64_COLOR64                                   0x1


#define JM_MEMORY_CONFIG_DISABLE_ZC16_FIX                                  31:31
#define JM_MEMORY_CONFIG_DISABLE_ZC16_FIX_End                                 31
#define JM_MEMORY_CONFIG_DISABLE_ZC16_FIX_Start                               31
#define JM_MEMORY_CONFIG_DISABLE_ZC16_FIX_Type                               U01
#define   JM_MEMORY_CONFIG_DISABLE_ZC16_FIX_DISABLED                         0x0
#define   JM_MEMORY_CONFIG_DISABLE_ZC16_FIX_ENABLED                          0x1




#define jmColorCacheRegAddrs                                              0x0596
#define JM_COLOR_CACHE_Address                                           0x01658
#define JM_COLOR_CACHE_MSB                                                    15
#define JM_COLOR_CACHE_LSB                                                     0
#define JM_COLOR_CACHE_BLK                                                     0
#define JM_COLOR_CACHE_Count                                                   1
#define JM_COLOR_CACHE_FieldMask                                      0xFFFFFFFF
#define JM_COLOR_CACHE_ReadMask                                       0xFFFFFFFC
#define JM_COLOR_CACHE_WriteMask                                      0xFFFFFFFC
#define JM_COLOR_CACHE_ResetValue                                     0x00000000

#define JM_COLOR_CACHE_TYPE                                                31:31
#define JM_COLOR_CACHE_TYPE_End                                               31
#define JM_COLOR_CACHE_TYPE_Start                                             31
#define JM_COLOR_CACHE_TYPE_Type                                             U01
#define   JM_COLOR_CACHE_TYPE_SYSTEM                                         0x0
#define   JM_COLOR_CACHE_TYPE_VIRTUAL_SYSTEM                                 0x1

#define JM_COLOR_CACHE_ADDRESS                                              30:0
#define JM_COLOR_CACHE_ADDRESS_End                                            30
#define JM_COLOR_CACHE_ADDRESS_Start                                           0
#define JM_COLOR_CACHE_ADDRESS_Type                                          U31




#define jmColorBaseRegAddrs                                               0x0597
#define JM_COLOR_BASE_Address                                            0x0165C
#define JM_COLOR_BASE_MSB                                                     15
#define JM_COLOR_BASE_LSB                                                      0
#define JM_COLOR_BASE_BLK                                                      0
#define JM_COLOR_BASE_Count                                                    1
#define JM_COLOR_BASE_FieldMask                                       0xFFFFFFFF
#define JM_COLOR_BASE_ReadMask                                        0xFFFFFFFC
#define JM_COLOR_BASE_WriteMask                                       0xFFFFFFFC
#define JM_COLOR_BASE_ResetValue                                      0x00000000

#define JM_COLOR_BASE_TYPE                                                 31:31
#define JM_COLOR_BASE_TYPE_End                                                31
#define JM_COLOR_BASE_TYPE_Start                                              31
#define JM_COLOR_BASE_TYPE_Type                                              U01
#define   JM_COLOR_BASE_TYPE_SYSTEM                                          0x0
#define   JM_COLOR_BASE_TYPE_VIRTUAL_SYSTEM                                  0x1

#define JM_COLOR_BASE_ADDRESS                                               30:0
#define JM_COLOR_BASE_ADDRESS_End                                             30
#define JM_COLOR_BASE_ADDRESS_Start                                            0
#define JM_COLOR_BASE_ADDRESS_Type                                           U31




#define jmColorClearValueRegAddrs                                         0x0598
#define JM_COLOR_CLEAR_VALUE_Address                                     0x01660
#define JM_COLOR_CLEAR_VALUE_MSB                                              15
#define JM_COLOR_CLEAR_VALUE_LSB                                               0
#define JM_COLOR_CLEAR_VALUE_BLK                                               0
#define JM_COLOR_CLEAR_VALUE_Count                                             1
#define JM_COLOR_CLEAR_VALUE_FieldMask                                0xFFFFFFFF
#define JM_COLOR_CLEAR_VALUE_ReadMask                                 0xFFFFFFFF
#define JM_COLOR_CLEAR_VALUE_WriteMask                                0xFFFFFFFF
#define JM_COLOR_CLEAR_VALUE_ResetValue                               0x00000000

#define JM_COLOR_CLEAR_VALUE_VALUE                                          31:0
#define JM_COLOR_CLEAR_VALUE_VALUE_End                                        31
#define JM_COLOR_CLEAR_VALUE_VALUE_Start                                       0
#define JM_COLOR_CLEAR_VALUE_VALUE_Type                                      U32




#define jmDepthCacheRegAddrs                                              0x0599
#define JM_DEPTH_CACHE_Address                                           0x01664
#define JM_DEPTH_CACHE_MSB                                                    15
#define JM_DEPTH_CACHE_LSB                                                     0
#define JM_DEPTH_CACHE_BLK                                                     0
#define JM_DEPTH_CACHE_Count                                                   1
#define JM_DEPTH_CACHE_FieldMask                                      0xFFFFFFFF
#define JM_DEPTH_CACHE_ReadMask                                       0xFFFFFFFC
#define JM_DEPTH_CACHE_WriteMask                                      0xFFFFFFFC
#define JM_DEPTH_CACHE_ResetValue                                     0x00000000

#define JM_DEPTH_CACHE_TYPE                                                31:31
#define JM_DEPTH_CACHE_TYPE_End                                               31
#define JM_DEPTH_CACHE_TYPE_Start                                             31
#define JM_DEPTH_CACHE_TYPE_Type                                             U01
#define   JM_DEPTH_CACHE_TYPE_SYSTEM                                         0x0
#define   JM_DEPTH_CACHE_TYPE_VIRTUAL_SYSTEM                                 0x1

#define JM_DEPTH_CACHE_ADDRESS                                              30:0
#define JM_DEPTH_CACHE_ADDRESS_End                                            30
#define JM_DEPTH_CACHE_ADDRESS_Start                                           0
#define JM_DEPTH_CACHE_ADDRESS_Type                                          U31




#define jmDepthBaseRegAddrs                                               0x059A
#define JM_DEPTH_BASE_Address                                            0x01668
#define JM_DEPTH_BASE_MSB                                                     15
#define JM_DEPTH_BASE_LSB                                                      0
#define JM_DEPTH_BASE_BLK                                                      0
#define JM_DEPTH_BASE_Count                                                    1
#define JM_DEPTH_BASE_FieldMask                                       0xFFFFFFFF
#define JM_DEPTH_BASE_ReadMask                                        0xFFFFFFFC
#define JM_DEPTH_BASE_WriteMask                                       0xFFFFFFFC
#define JM_DEPTH_BASE_ResetValue                                      0x00000000

#define JM_DEPTH_BASE_TYPE                                                 31:31
#define JM_DEPTH_BASE_TYPE_End                                                31
#define JM_DEPTH_BASE_TYPE_Start                                              31
#define JM_DEPTH_BASE_TYPE_Type                                              U01
#define   JM_DEPTH_BASE_TYPE_SYSTEM                                          0x0
#define   JM_DEPTH_BASE_TYPE_VIRTUAL_SYSTEM                                  0x1

#define JM_DEPTH_BASE_ADDRESS                                               30:0
#define JM_DEPTH_BASE_ADDRESS_End                                             30
#define JM_DEPTH_BASE_ADDRESS_Start                                            0
#define JM_DEPTH_BASE_ADDRESS_Type                                           U31




#define jmDepthClearValueRegAddrs                                         0x059B
#define JM_DEPTH_CLEAR_VALUE_Address                                     0x0166C
#define JM_DEPTH_CLEAR_VALUE_MSB                                              15
#define JM_DEPTH_CLEAR_VALUE_LSB                                               0
#define JM_DEPTH_CLEAR_VALUE_BLK                                               0
#define JM_DEPTH_CLEAR_VALUE_Count                                             1
#define JM_DEPTH_CLEAR_VALUE_FieldMask                                0xFFFFFFFF
#define JM_DEPTH_CLEAR_VALUE_ReadMask                                 0xFFFFFFFF
#define JM_DEPTH_CLEAR_VALUE_WriteMask                                0xFFFFFFFF
#define JM_DEPTH_CLEAR_VALUE_ResetValue                               0x00000000

#define JM_DEPTH_CLEAR_VALUE_VALUE                                          31:0
#define JM_DEPTH_CLEAR_VALUE_VALUE_End                                        31
#define JM_DEPTH_CLEAR_VALUE_VALUE_Start                                       0
#define JM_DEPTH_CLEAR_VALUE_VALUE_Type                                      U32



#define jmTileStatusCounterZRegAddrs                                      0x059C
#define JM_TILE_STATUS_COUNTER_Z_Address                                 0x01670
#define JM_TILE_STATUS_COUNTER_Z_MSB                                          15
#define JM_TILE_STATUS_COUNTER_Z_LSB                                           0
#define JM_TILE_STATUS_COUNTER_Z_BLK                                           0
#define JM_TILE_STATUS_COUNTER_Z_Count                                         1
#define JM_TILE_STATUS_COUNTER_Z_FieldMask                            0xFFFFFFFF
#define JM_TILE_STATUS_COUNTER_Z_ReadMask                             0xFFFFFFFF
#define JM_TILE_STATUS_COUNTER_Z_WriteMask                            0xFFFFFFFF
#define JM_TILE_STATUS_COUNTER_Z_ResetValue                           0x00000000

#define JM_TILE_STATUS_COUNTER_Z_COUNTER                                    31:0
#define JM_TILE_STATUS_COUNTER_Z_COUNTER_End                                  31
#define JM_TILE_STATUS_COUNTER_Z_COUNTER_Start                                 0
#define JM_TILE_STATUS_COUNTER_Z_COUNTER_Type                                U32



#define jmTileStatusCounterCRegAddrs                                      0x059D
#define JM_TILE_STATUS_COUNTER_C_Address                                 0x01674
#define JM_TILE_STATUS_COUNTER_C_MSB                                          15
#define JM_TILE_STATUS_COUNTER_C_LSB                                           0
#define JM_TILE_STATUS_COUNTER_C_BLK                                           0
#define JM_TILE_STATUS_COUNTER_C_Count                                         1
#define JM_TILE_STATUS_COUNTER_C_FieldMask                            0xFFFFFFFF
#define JM_TILE_STATUS_COUNTER_C_ReadMask                             0xFFFFFFFF
#define JM_TILE_STATUS_COUNTER_C_WriteMask                            0xFFFFFFFF
#define JM_TILE_STATUS_COUNTER_C_ResetValue                           0x00000000

#define JM_TILE_STATUS_COUNTER_C_COUNTER                                    31:0
#define JM_TILE_STATUS_COUNTER_C_COUNTER_End                                  31
#define JM_TILE_STATUS_COUNTER_C_COUNTER_Start                                 0
#define JM_TILE_STATUS_COUNTER_C_COUNTER_Type                                U32




#define jmYUVTilerConfigRegAddrs                                          0x059E
#define JM_YUV_TILER_CONFIG_Address                                      0x01678
#define JM_YUV_TILER_CONFIG_MSB                                               15
#define JM_YUV_TILER_CONFIG_LSB                                                0
#define JM_YUV_TILER_CONFIG_BLK                                                0
#define JM_YUV_TILER_CONFIG_Count                                              1
#define JM_YUV_TILER_CONFIG_FieldMask                                 0x00000131
#define JM_YUV_TILER_CONFIG_ReadMask                                  0x00000131
#define JM_YUV_TILER_CONFIG_WriteMask                                 0x00000131
#define JM_YUV_TILER_CONFIG_ResetValue                                0x00000000

#define JM_YUV_TILER_CONFIG_TILER                                            0:0
#define JM_YUV_TILER_CONFIG_TILER_End                                          0
#define JM_YUV_TILER_CONFIG_TILER_Start                                        0
#define JM_YUV_TILER_CONFIG_TILER_Type                                       U01
#define   JM_YUV_TILER_CONFIG_TILER_DISABLED                                 0x0
#define   JM_YUV_TILER_CONFIG_TILER_ENABLED                                  0x1

#define JM_YUV_TILER_CONFIG_FORMAT                                           5:4
#define JM_YUV_TILER_CONFIG_FORMAT_End                                         5
#define JM_YUV_TILER_CONFIG_FORMAT_Start                                       4
#define JM_YUV_TILER_CONFIG_FORMAT_Type                                      U02
#define   JM_YUV_TILER_CONFIG_FORMAT_YV12                                    0x0
#define   JM_YUV_TILER_CONFIG_FORMAT_NV12                                    0x1
#define   JM_YUV_TILER_CONFIG_FORMAT_NV16                                    0x2

#define JM_YUV_TILER_CONFIG_UVSWIZZLE                                        8:8
#define JM_YUV_TILER_CONFIG_UVSWIZZLE_End                                      8
#define JM_YUV_TILER_CONFIG_UVSWIZZLE_Start                                    8
#define JM_YUV_TILER_CONFIG_UVSWIZZLE_Type                                   U01
#define   JM_YUV_TILER_CONFIG_UVSWIZZLE_UV                                   0x0
#define   JM_YUV_TILER_CONFIG_UVSWIZZLE_VU                                   0x1




#define jmYUVTilerSizeRegAddrs                                            0x059F
#define JM_YUV_TILER_SIZE_Address                                        0x0167C
#define JM_YUV_TILER_SIZE_MSB                                                 15
#define JM_YUV_TILER_SIZE_LSB                                                  0
#define JM_YUV_TILER_SIZE_BLK                                                  0
#define JM_YUV_TILER_SIZE_Count                                                1
#define JM_YUV_TILER_SIZE_FieldMask                                   0xFFFFFFFF
#define JM_YUV_TILER_SIZE_ReadMask                                    0xFFFFFFFF
#define JM_YUV_TILER_SIZE_WriteMask                                   0xFFFFFFFF
#define JM_YUV_TILER_SIZE_ResetValue                                  0x00000000

#define JM_YUV_TILER_SIZE_WIDTH                                             15:0
#define JM_YUV_TILER_SIZE_WIDTH_End                                           15
#define JM_YUV_TILER_SIZE_WIDTH_Start                                          0
#define JM_YUV_TILER_SIZE_WIDTH_Type                                         U16

#define JM_YUV_TILER_SIZE_HEIGHT                                           31:16
#define JM_YUV_TILER_SIZE_HEIGHT_End                                          31
#define JM_YUV_TILER_SIZE_HEIGHT_Start                                        16
#define JM_YUV_TILER_SIZE_HEIGHT_Type                                        U16




#define jmYUVTilerYbaseRegAddrs                                           0x05A0
#define JM_YUV_TILER_YBASE_Address                                       0x01680
#define JM_YUV_TILER_YBASE_MSB                                                15
#define JM_YUV_TILER_YBASE_LSB                                                 0
#define JM_YUV_TILER_YBASE_BLK                                                 0
#define JM_YUV_TILER_YBASE_Count                                               1
#define JM_YUV_TILER_YBASE_FieldMask                                  0xFFFFFFFF
#define JM_YUV_TILER_YBASE_ReadMask                                   0xFFFFFFFC
#define JM_YUV_TILER_YBASE_WriteMask                                  0xFFFFFFFC
#define JM_YUV_TILER_YBASE_ResetValue                                 0x00000000

#define JM_YUV_TILER_YBASE_TYPE                                            31:31
#define JM_YUV_TILER_YBASE_TYPE_End                                           31
#define JM_YUV_TILER_YBASE_TYPE_Start                                         31
#define JM_YUV_TILER_YBASE_TYPE_Type                                         U01
#define   JM_YUV_TILER_YBASE_TYPE_SYSTEM                                     0x0
#define   JM_YUV_TILER_YBASE_TYPE_VIRTUAL_SYSTEM                             0x1

#define JM_YUV_TILER_YBASE_ADDRESS                                          30:0
#define JM_YUV_TILER_YBASE_ADDRESS_End                                        30
#define JM_YUV_TILER_YBASE_ADDRESS_Start                                       0
#define JM_YUV_TILER_YBASE_ADDRESS_Type                                      U31




#define jmYUVTilerYstrideRegAddrs                                         0x05A1
#define JM_YUV_TILER_YSTRIDE_Address                                     0x01684
#define JM_YUV_TILER_YSTRIDE_MSB                                              15
#define JM_YUV_TILER_YSTRIDE_LSB                                               0
#define JM_YUV_TILER_YSTRIDE_BLK                                               0
#define JM_YUV_TILER_YSTRIDE_Count                                             1
#define JM_YUV_TILER_YSTRIDE_FieldMask                                0x0003FFFF
#define JM_YUV_TILER_YSTRIDE_ReadMask                                 0x0003FFFC
#define JM_YUV_TILER_YSTRIDE_WriteMask                                0x0003FFFC
#define JM_YUV_TILER_YSTRIDE_ResetValue                               0x00000000

#define JM_YUV_TILER_YSTRIDE_STRIDE                                         17:0
#define JM_YUV_TILER_YSTRIDE_STRIDE_End                                       17
#define JM_YUV_TILER_YSTRIDE_STRIDE_Start                                      0
#define JM_YUV_TILER_YSTRIDE_STRIDE_Type                                     U18




#define jmYUVTilerUbaseRegAddrs                                           0x05A2
#define JM_YUV_TILER_UBASE_Address                                       0x01688
#define JM_YUV_TILER_UBASE_MSB                                                15
#define JM_YUV_TILER_UBASE_LSB                                                 0
#define JM_YUV_TILER_UBASE_BLK                                                 0
#define JM_YUV_TILER_UBASE_Count                                               1
#define JM_YUV_TILER_UBASE_FieldMask                                  0xFFFFFFFF
#define JM_YUV_TILER_UBASE_ReadMask                                   0xFFFFFFFC
#define JM_YUV_TILER_UBASE_WriteMask                                  0xFFFFFFFC
#define JM_YUV_TILER_UBASE_ResetValue                                 0x00000000

#define JM_YUV_TILER_UBASE_TYPE                                            31:31
#define JM_YUV_TILER_UBASE_TYPE_End                                           31
#define JM_YUV_TILER_UBASE_TYPE_Start                                         31
#define JM_YUV_TILER_UBASE_TYPE_Type                                         U01
#define   JM_YUV_TILER_UBASE_TYPE_SYSTEM                                     0x0
#define   JM_YUV_TILER_UBASE_TYPE_VIRTUAL_SYSTEM                             0x1

#define JM_YUV_TILER_UBASE_ADDRESS                                          30:0
#define JM_YUV_TILER_UBASE_ADDRESS_End                                        30
#define JM_YUV_TILER_UBASE_ADDRESS_Start                                       0
#define JM_YUV_TILER_UBASE_ADDRESS_Type                                      U31




#define jmYUVTilerUstrideRegAddrs                                         0x05A3
#define JM_YUV_TILER_USTRIDE_Address                                     0x0168C
#define JM_YUV_TILER_USTRIDE_MSB                                              15
#define JM_YUV_TILER_USTRIDE_LSB                                               0
#define JM_YUV_TILER_USTRIDE_BLK                                               0
#define JM_YUV_TILER_USTRIDE_Count                                             1
#define JM_YUV_TILER_USTRIDE_FieldMask                                0x0003FFFF
#define JM_YUV_TILER_USTRIDE_ReadMask                                 0x0003FFFC
#define JM_YUV_TILER_USTRIDE_WriteMask                                0x0003FFFC
#define JM_YUV_TILER_USTRIDE_ResetValue                               0x00000000

#define JM_YUV_TILER_USTRIDE_STRIDE                                         17:0
#define JM_YUV_TILER_USTRIDE_STRIDE_End                                       17
#define JM_YUV_TILER_USTRIDE_STRIDE_Start                                      0
#define JM_YUV_TILER_USTRIDE_STRIDE_Type                                     U18




#define jmYUVTilerVbaseRegAddrs                                           0x05A4
#define JM_YUV_TILER_VBASE_Address                                       0x01690
#define JM_YUV_TILER_VBASE_MSB                                                15
#define JM_YUV_TILER_VBASE_LSB                                                 0
#define JM_YUV_TILER_VBASE_BLK                                                 0
#define JM_YUV_TILER_VBASE_Count                                               1
#define JM_YUV_TILER_VBASE_FieldMask                                  0xFFFFFFFF
#define JM_YUV_TILER_VBASE_ReadMask                                   0xFFFFFFFC
#define JM_YUV_TILER_VBASE_WriteMask                                  0xFFFFFFFC
#define JM_YUV_TILER_VBASE_ResetValue                                 0x00000000

#define JM_YUV_TILER_VBASE_TYPE                                            31:31
#define JM_YUV_TILER_VBASE_TYPE_End                                           31
#define JM_YUV_TILER_VBASE_TYPE_Start                                         31
#define JM_YUV_TILER_VBASE_TYPE_Type                                         U01
#define   JM_YUV_TILER_VBASE_TYPE_SYSTEM                                     0x0
#define   JM_YUV_TILER_VBASE_TYPE_VIRTUAL_SYSTEM                             0x1

#define JM_YUV_TILER_VBASE_ADDRESS                                          30:0
#define JM_YUV_TILER_VBASE_ADDRESS_End                                        30
#define JM_YUV_TILER_VBASE_ADDRESS_Start                                       0
#define JM_YUV_TILER_VBASE_ADDRESS_Type                                      U31




#define jmYUVTilerVstrideRegAddrs                                         0x05A5
#define JM_YUV_TILER_VSTRIDE_Address                                     0x01694
#define JM_YUV_TILER_VSTRIDE_MSB                                              15
#define JM_YUV_TILER_VSTRIDE_LSB                                               0
#define JM_YUV_TILER_VSTRIDE_BLK                                               0
#define JM_YUV_TILER_VSTRIDE_Count                                             1
#define JM_YUV_TILER_VSTRIDE_FieldMask                                0x0003FFFF
#define JM_YUV_TILER_VSTRIDE_ReadMask                                 0x0003FFFC
#define JM_YUV_TILER_VSTRIDE_WriteMask                                0x0003FFFC
#define JM_YUV_TILER_VSTRIDE_ResetValue                               0x00000000

#define JM_YUV_TILER_VSTRIDE_STRIDE                                         17:0
#define JM_YUV_TILER_VSTRIDE_STRIDE_End                                       17
#define JM_YUV_TILER_VSTRIDE_STRIDE_Start                                      0
#define JM_YUV_TILER_VSTRIDE_STRIDE_Type                                     U18




#define jmYUVTilerDestBaseRegAddrs                                        0x05A6
#define JM_YUV_TILER_DEST_BASE_Address                                   0x01698
#define JM_YUV_TILER_DEST_BASE_MSB                                            15
#define JM_YUV_TILER_DEST_BASE_LSB                                             0
#define JM_YUV_TILER_DEST_BASE_BLK                                             0
#define JM_YUV_TILER_DEST_BASE_Count                                           1
#define JM_YUV_TILER_DEST_BASE_FieldMask                              0xFFFFFFFF
#define JM_YUV_TILER_DEST_BASE_ReadMask                               0xFFFFFFFC
#define JM_YUV_TILER_DEST_BASE_WriteMask                              0xFFFFFFFC
#define JM_YUV_TILER_DEST_BASE_ResetValue                             0x00000000

#define JM_YUV_TILER_DEST_BASE_TYPE                                        31:31
#define JM_YUV_TILER_DEST_BASE_TYPE_End                                       31
#define JM_YUV_TILER_DEST_BASE_TYPE_Start                                     31
#define JM_YUV_TILER_DEST_BASE_TYPE_Type                                     U01
#define   JM_YUV_TILER_DEST_BASE_TYPE_SYSTEM                                 0x0
#define   JM_YUV_TILER_DEST_BASE_TYPE_VIRTUAL_SYSTEM                         0x1

#define JM_YUV_TILER_DEST_BASE_ADDRESS                                      30:0
#define JM_YUV_TILER_DEST_BASE_ADDRESS_End                                    30
#define JM_YUV_TILER_DEST_BASE_ADDRESS_Start                                   0
#define JM_YUV_TILER_DEST_BASE_ADDRESS_Type                                  U31




#define jmYUVTilerDestStrideRegAddrs                                      0x05A7
#define JM_YUV_TILER_DEST_STRIDE_Address                                 0x0169C
#define JM_YUV_TILER_DEST_STRIDE_MSB                                          15
#define JM_YUV_TILER_DEST_STRIDE_LSB                                           0
#define JM_YUV_TILER_DEST_STRIDE_BLK                                           0
#define JM_YUV_TILER_DEST_STRIDE_Count                                         1
#define JM_YUV_TILER_DEST_STRIDE_FieldMask                            0x0003FFFF
#define JM_YUV_TILER_DEST_STRIDE_ReadMask                             0x0003FFFC
#define JM_YUV_TILER_DEST_STRIDE_WriteMask                            0x0003FFFC
#define JM_YUV_TILER_DEST_STRIDE_ResetValue                           0x00000000

#define JM_YUV_TILER_DEST_STRIDE_STRIDE                                     17:0
#define JM_YUV_TILER_DEST_STRIDE_STRIDE_End                                   17
#define JM_YUV_TILER_DEST_STRIDE_STRIDE_Start                                  0
#define JM_YUV_TILER_DEST_STRIDE_STRIDE_Type                                 U18




#define mwv207regRSConfigRegAddrs                                         0x05A8
#define MWV207REG_RS_CONFIG_Address                                      0x016A0
#define MWV207REG_RS_CONFIG_MSB                                               15
#define MWV207REG_RS_CONFIG_LSB                                                0
#define MWV207REG_RS_CONFIG_BLK                                                0
#define MWV207REG_RS_CONFIG_Count                                              1
#define MWV207REG_RS_CONFIG_FieldMask                                 0xFF3937F3
#define MWV207REG_RS_CONFIG_ReadMask                                  0xFF3937F3
#define MWV207REG_RS_CONFIG_WriteMask                                 0xFF3937F3
#define MWV207REG_RS_CONFIG_ResetValue                                0x00000000


#define MWV207REG_RS_CONFIG_VAA                                              1:0
#define MWV207REG_RS_CONFIG_VAA_End                                            1
#define MWV207REG_RS_CONFIG_VAA_Start                                          0
#define MWV207REG_RS_CONFIG_VAA_Type                                         U02
#define   MWV207REG_RS_CONFIG_VAA_OFF                                        0x0

#define   MWV207REG_RS_CONFIG_VAA_TWO_COLOR                                  0x1

#define   MWV207REG_RS_CONFIG_VAA_TWO_COLOR8                                 0x2


#define MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL                            5:4
#define MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL_End                          5
#define MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL_Start                        4
#define MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL_Type                       U02
#define   MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL_NO_SWAP                  0x0
#define   MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL_SWAP_WORD                0x1
#define   MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL_SWAP_DWORD               0x2
#define   MWV207REG_RS_CONFIG_SOURCE_ENDIAN_CONTROL_SWAP_DDWORD              0x3


#define MWV207REG_RS_CONFIG_CONVERSION_CONTROL                               7:6
#define MWV207REG_RS_CONFIG_CONVERSION_CONTROL_End                             7
#define MWV207REG_RS_CONFIG_CONVERSION_CONTROL_Start                           6
#define MWV207REG_RS_CONFIG_CONVERSION_CONTROL_Type                          U02
#define   MWV207REG_RS_CONFIG_CONVERSION_CONTROL_EXPAND                      0x0
#define   MWV207REG_RS_CONFIG_CONVERSION_CONTROL_ADD_RGB111                  0x1
#define   MWV207REG_RS_CONFIG_CONVERSION_CONTROL_ADD_RGB212                  0x2
#define   MWV207REG_RS_CONFIG_CONVERSION_CONTROL_ADD_RGB737                  0x3


#define MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL                       9:8
#define MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL_End                     9
#define MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL_Start                   8
#define MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL_Type                  U02
#define   MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL_NO_SWAP             0x0
#define   MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL_SWAP_WORD           0x1
#define   MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL_SWAP_DWORD          0x2
#define   MWV207REG_RS_CONFIG_DESTINATION_ENDIAN_CONTROL_SWAP_DDWORD         0x3


#define MWV207REG_RS_CONFIG_FC_DEPTH                                       10:10
#define MWV207REG_RS_CONFIG_FC_DEPTH_End                                      10
#define MWV207REG_RS_CONFIG_FC_DEPTH_Start                                    10
#define MWV207REG_RS_CONFIG_FC_DEPTH_Type                                    U01
#define   MWV207REG_RS_CONFIG_FC_DEPTH_DISABLE                               0x0
#define   MWV207REG_RS_CONFIG_FC_DEPTH_ENABLE                                0x1


#define MWV207REG_RS_CONFIG_INTERLEAVING                                   13:12
#define MWV207REG_RS_CONFIG_INTERLEAVING_End                                  13
#define MWV207REG_RS_CONFIG_INTERLEAVING_Start                                12
#define MWV207REG_RS_CONFIG_INTERLEAVING_Type                                U02
#define   MWV207REG_RS_CONFIG_INTERLEAVING_OFF                               0x0

#define   MWV207REG_RS_CONFIG_INTERLEAVING_PARALLAX                          0x1

#define   MWV207REG_RS_CONFIG_INTERLEAVING_HONEYCOMB                         0x2


#define MWV207REG_RS_CONFIG_INTERLEAVE_FORMAT                              16:16
#define MWV207REG_RS_CONFIG_INTERLEAVE_FORMAT_End                             16
#define MWV207REG_RS_CONFIG_INTERLEAVE_FORMAT_Start                           16
#define MWV207REG_RS_CONFIG_INTERLEAVE_FORMAT_Type                           U01

#define   MWV207REG_RS_CONFIG_INTERLEAVE_FORMAT_BPP16                        0x0

#define   MWV207REG_RS_CONFIG_INTERLEAVE_FORMAT_BPP32                        0x1


#define MWV207REG_RS_CONFIG_FULL_HEIGHT                                    20:20
#define MWV207REG_RS_CONFIG_FULL_HEIGHT_End                                   20
#define MWV207REG_RS_CONFIG_FULL_HEIGHT_Start                                 20
#define MWV207REG_RS_CONFIG_FULL_HEIGHT_Type                                 U01
#define   MWV207REG_RS_CONFIG_FULL_HEIGHT_DISABLE                            0x0
#define   MWV207REG_RS_CONFIG_FULL_HEIGHT_ENABLE                             0x1


#define MWV207REG_RS_CONFIG_TILE_STATUS4_BIT                               21:21
#define MWV207REG_RS_CONFIG_TILE_STATUS4_BIT_End                              21
#define MWV207REG_RS_CONFIG_TILE_STATUS4_BIT_Start                            21
#define MWV207REG_RS_CONFIG_TILE_STATUS4_BIT_Type                            U01
#define   MWV207REG_RS_CONFIG_TILE_STATUS4_BIT_DISABLED                      0x0
#define   MWV207REG_RS_CONFIG_TILE_STATUS4_BIT_ENABLED                       0x1


#define MWV207REG_RS_CONFIG_FILLER_TILE_SIZE                               24:24
#define MWV207REG_RS_CONFIG_FILLER_TILE_SIZE_End                              24
#define MWV207REG_RS_CONFIG_FILLER_TILE_SIZE_Start                            24
#define MWV207REG_RS_CONFIG_FILLER_TILE_SIZE_Type                            U01

#define   MWV207REG_RS_CONFIG_FILLER_TILE_SIZE_TILE64                        0x0

#define   MWV207REG_RS_CONFIG_FILLER_TILE_SIZE_TILE256                       0x1


#define MWV207REG_RS_CONFIG_FILLER_FORMAT                                  28:28
#define MWV207REG_RS_CONFIG_FILLER_FORMAT_End                                 28
#define MWV207REG_RS_CONFIG_FILLER_FORMAT_Start                               28
#define MWV207REG_RS_CONFIG_FILLER_FORMAT_Type                               U01

#define   MWV207REG_RS_CONFIG_FILLER_FORMAT_FILLER32                         0x0

#define   MWV207REG_RS_CONFIG_FILLER_FORMAT_FILLER64                         0x1


#define MWV207REG_RS_CONFIG_FILLER_BPP                                     27:25
#define MWV207REG_RS_CONFIG_FILLER_BPP_End                                    27
#define MWV207REG_RS_CONFIG_FILLER_BPP_Start                                  25
#define MWV207REG_RS_CONFIG_FILLER_BPP_Type                                  U03

#define   MWV207REG_RS_CONFIG_FILLER_BPP_FILLER8_BPP                         0x0

#define   MWV207REG_RS_CONFIG_FILLER_BPP_FILLER16_BPP                        0x1

#define   MWV207REG_RS_CONFIG_FILLER_BPP_FILLER32_BPP                        0x2

#define   MWV207REG_RS_CONFIG_FILLER_BPP_FILLER64_BPP                        0x3

#define   MWV207REG_RS_CONFIG_FILLER_BPP_FILLER128_BPP                       0x4


#define MWV207REG_RS_CONFIG_FC_CLIENT                                      31:29
#define MWV207REG_RS_CONFIG_FC_CLIENT_End                                     31
#define MWV207REG_RS_CONFIG_FC_CLIENT_Start                                   29
#define MWV207REG_RS_CONFIG_FC_CLIENT_Type                                   U03


#define MWV207REG_RS_CONFIG_FILLER128                                      19:19
#define MWV207REG_RS_CONFIG_FILLER128_End                                     19
#define MWV207REG_RS_CONFIG_FILLER128_Start                                   19
#define MWV207REG_RS_CONFIG_FILLER128_Type                                   U01
#define   MWV207REG_RS_CONFIG_FILLER128_DISABLED                             0x0
#define   MWV207REG_RS_CONFIG_FILLER128_ENABLED                              0x1




#define mwv207regMCCacheHZRegAddrs                                        0x05A9
#define MWV207REG_MC_CACHE_HZ_Address                                    0x016A4
#define MWV207REG_MC_CACHE_HZ_MSB                                             15
#define MWV207REG_MC_CACHE_HZ_LSB                                              0
#define MWV207REG_MC_CACHE_HZ_BLK                                              0
#define MWV207REG_MC_CACHE_HZ_Count                                            1
#define MWV207REG_MC_CACHE_HZ_FieldMask                               0xFFFFFFFF
#define MWV207REG_MC_CACHE_HZ_ReadMask                                0xFFFFFFFC
#define MWV207REG_MC_CACHE_HZ_WriteMask                               0xFFFFFFFC
#define MWV207REG_MC_CACHE_HZ_ResetValue                              0x00000000

#define MWV207REG_MC_CACHE_HZ_TYPE                                         31:31
#define MWV207REG_MC_CACHE_HZ_TYPE_End                                        31
#define MWV207REG_MC_CACHE_HZ_TYPE_Start                                      31
#define MWV207REG_MC_CACHE_HZ_TYPE_Type                                      U01
#define   MWV207REG_MC_CACHE_HZ_TYPE_SYSTEM                                  0x0
#define   MWV207REG_MC_CACHE_HZ_TYPE_VIRTUAL_SYSTEM                          0x1

#define MWV207REG_MC_CACHE_HZ_ADDRESS                                       30:0
#define MWV207REG_MC_CACHE_HZ_ADDRESS_End                                     30
#define MWV207REG_MC_CACHE_HZ_ADDRESS_Start                                    0
#define MWV207REG_MC_CACHE_HZ_ADDRESS_Type                                   U31




#define mwv207regMCClearValueHZRegAddrs                                   0x05AA
#define MWV207REG_MC_CLEAR_VALUE_HZ_Address                              0x016A8
#define MWV207REG_MC_CLEAR_VALUE_HZ_MSB                                       15
#define MWV207REG_MC_CLEAR_VALUE_HZ_LSB                                        0
#define MWV207REG_MC_CLEAR_VALUE_HZ_BLK                                        0
#define MWV207REG_MC_CLEAR_VALUE_HZ_Count                                      1
#define MWV207REG_MC_CLEAR_VALUE_HZ_FieldMask                         0xFFFFFFFF
#define MWV207REG_MC_CLEAR_VALUE_HZ_ReadMask                          0xFFFFFFFF
#define MWV207REG_MC_CLEAR_VALUE_HZ_WriteMask                         0xFFFFFFFF
#define MWV207REG_MC_CLEAR_VALUE_HZ_ResetValue                        0x00000000

#define MWV207REG_MC_CLEAR_VALUE_HZ_VALUE                                   31:0
#define MWV207REG_MC_CLEAR_VALUE_HZ_VALUE_End                                 31
#define MWV207REG_MC_CLEAR_VALUE_HZ_VALUE_Start                                0
#define MWV207REG_MC_CLEAR_VALUE_HZ_VALUE_Type                               U32



#define mwv207regMCCounterHZRegAddrs                                      0x05AB
#define MWV207REG_MC_COUNTER_HZ_Address                                  0x016AC
#define MWV207REG_MC_COUNTER_HZ_MSB                                           15
#define MWV207REG_MC_COUNTER_HZ_LSB                                            0
#define MWV207REG_MC_COUNTER_HZ_BLK                                            0
#define MWV207REG_MC_COUNTER_HZ_Count                                          1
#define MWV207REG_MC_COUNTER_HZ_FieldMask                             0xFFFFFFFF
#define MWV207REG_MC_COUNTER_HZ_ReadMask                              0xFFFFFFFF
#define MWV207REG_MC_COUNTER_HZ_WriteMask                             0xFFFFFFFF
#define MWV207REG_MC_COUNTER_HZ_ResetValue                            0x00000000

#define MWV207REG_MC_COUNTER_HZ_COUNTER                                     31:0
#define MWV207REG_MC_COUNTER_HZ_COUNTER_End                                   31
#define MWV207REG_MC_COUNTER_HZ_COUNTER_Start                                  0
#define MWV207REG_MC_COUNTER_HZ_COUNTER_Type                                 U32



#define mwv207regRSSourceAddressRegAddrs                                  0x05B0
#define MWV207REG_RS_SOURCE_ADDRESS_Address                              0x016C0
#define MWV207REG_RS_SOURCE_ADDRESS_MSB                                       15
#define MWV207REG_RS_SOURCE_ADDRESS_LSB                                        3
#define MWV207REG_RS_SOURCE_ADDRESS_BLK                                        3
#define MWV207REG_RS_SOURCE_ADDRESS_Count                                      8
#define MWV207REG_RS_SOURCE_ADDRESS_FieldMask                         0xFFFFFFFF
#define MWV207REG_RS_SOURCE_ADDRESS_ReadMask                          0xFFFFFFFC
#define MWV207REG_RS_SOURCE_ADDRESS_WriteMask                         0xFFFFFFFC
#define MWV207REG_RS_SOURCE_ADDRESS_ResetValue                        0x00000000

#define MWV207REG_RS_SOURCE_ADDRESS_TYPE                                   31:31
#define MWV207REG_RS_SOURCE_ADDRESS_TYPE_End                                  31
#define MWV207REG_RS_SOURCE_ADDRESS_TYPE_Start                                31
#define MWV207REG_RS_SOURCE_ADDRESS_TYPE_Type                                U01
#define   MWV207REG_RS_SOURCE_ADDRESS_TYPE_SYSTEM                            0x0
#define   MWV207REG_RS_SOURCE_ADDRESS_TYPE_VIRTUAL_SYSTEM                    0x1

#define MWV207REG_RS_SOURCE_ADDRESS_ADDRESS                                 30:0
#define MWV207REG_RS_SOURCE_ADDRESS_ADDRESS_End                               30
#define MWV207REG_RS_SOURCE_ADDRESS_ADDRESS_Start                              0
#define MWV207REG_RS_SOURCE_ADDRESS_ADDRESS_Type                             U31



#define mwv207regRSTargetAddressRegAddrs                                  0x05B8
#define MWV207REG_RS_TARGET_ADDRESS_Address                              0x016E0
#define MWV207REG_RS_TARGET_ADDRESS_MSB                                       15
#define MWV207REG_RS_TARGET_ADDRESS_LSB                                        3
#define MWV207REG_RS_TARGET_ADDRESS_BLK                                        3
#define MWV207REG_RS_TARGET_ADDRESS_Count                                      8
#define MWV207REG_RS_TARGET_ADDRESS_FieldMask                         0xFFFFFFFF
#define MWV207REG_RS_TARGET_ADDRESS_ReadMask                          0xFFFFFFFC
#define MWV207REG_RS_TARGET_ADDRESS_WriteMask                         0xFFFFFFFC
#define MWV207REG_RS_TARGET_ADDRESS_ResetValue                        0x00000000

#define MWV207REG_RS_TARGET_ADDRESS_TYPE                                   31:31
#define MWV207REG_RS_TARGET_ADDRESS_TYPE_End                                  31
#define MWV207REG_RS_TARGET_ADDRESS_TYPE_Start                                31
#define MWV207REG_RS_TARGET_ADDRESS_TYPE_Type                                U01
#define   MWV207REG_RS_TARGET_ADDRESS_TYPE_SYSTEM                            0x0
#define   MWV207REG_RS_TARGET_ADDRESS_TYPE_VIRTUAL_SYSTEM                    0x1

#define MWV207REG_RS_TARGET_ADDRESS_ADDRESS                                 30:0
#define MWV207REG_RS_TARGET_ADDRESS_ADDRESS_End                               30
#define MWV207REG_RS_TARGET_ADDRESS_ADDRESS_Start                              0
#define MWV207REG_RS_TARGET_ADDRESS_ADDRESS_Type                             U31




#define mwv207regRSOffsetRegAddrs                                         0x05C0
#define MWV207REG_RS_OFFSET_Address                                      0x01700
#define MWV207REG_RS_OFFSET_MSB                                               15
#define MWV207REG_RS_OFFSET_LSB                                                3
#define MWV207REG_RS_OFFSET_BLK                                                3
#define MWV207REG_RS_OFFSET_Count                                              8
#define MWV207REG_RS_OFFSET_FieldMask                                 0x1FFF1FFF
#define MWV207REG_RS_OFFSET_ReadMask                                  0x1FFF1FFF
#define MWV207REG_RS_OFFSET_WriteMask                                 0x1FFF1FFF
#define MWV207REG_RS_OFFSET_ResetValue                                0x00000000


#define MWV207REG_RS_OFFSET_X                                               12:0
#define MWV207REG_RS_OFFSET_X_End                                             12
#define MWV207REG_RS_OFFSET_X_Start                                            0
#define MWV207REG_RS_OFFSET_X_Type                                           U13


#define MWV207REG_RS_OFFSET_Y                                              28:16
#define MWV207REG_RS_OFFSET_Y_End                                             28
#define MWV207REG_RS_OFFSET_Y_Start                                           16
#define MWV207REG_RS_OFFSET_Y_Type                                           U13




#define mwv207regMCTextureConfigRegAddrs                                  0x05C8
#define MWV207REG_MC_TEXTURE_CONFIG_Address                              0x01720
#define MWV207REG_MC_TEXTURE_CONFIG_MSB                                       15
#define MWV207REG_MC_TEXTURE_CONFIG_LSB                                        3
#define MWV207REG_MC_TEXTURE_CONFIG_BLK                                        3
#define MWV207REG_MC_TEXTURE_CONFIG_Count                                      8
#define MWV207REG_MC_TEXTURE_CONFIG_FieldMask                         0x037FFFF3
#define MWV207REG_MC_TEXTURE_CONFIG_ReadMask                          0x037FFFF3
#define MWV207REG_MC_TEXTURE_CONFIG_WriteMask                         0x037FFFF3
#define MWV207REG_MC_TEXTURE_CONFIG_ResetValue                        0x00000000


#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL                                  1:0
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL_End                                1
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL_Start                              0
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL_Type                             U02

#define   MWV207REG_MC_TEXTURE_CONFIG_CONTROL_DISABLE                        0x0

#define   MWV207REG_MC_TEXTURE_CONFIG_CONTROL_ENABLE                         0x1

#define   MWV207REG_MC_TEXTURE_CONFIG_CONTROL_COMPRESSED                     0x3


#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT                                   7:4
#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT_End                                 7
#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT_Start                               4
#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT_Type                              U04
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_ARGB4                           0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_A1RGB5                          0x1
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_R5G6B5                          0x2
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_ARGB8                           0x3
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_RGB8                            0x4
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_Z24S8                           0x5
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_Z24                             0x6
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_VAA16                           0x7
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_Z16                             0x8
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_S8                              0x9
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_SINGLE_Y_U_V                    0xA
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_UV_MIX                          0xB
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_YUY2                            0xC
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_SINGLE_Y_U_V_P010               0xD
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_UV_MIX_P010                     0xE
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_A2RGB10                         0xF

#define MWV207REG_MC_TEXTURE_CONFIG_DOWN_SAMPLER                             8:8
#define MWV207REG_MC_TEXTURE_CONFIG_DOWN_SAMPLER_End                           8
#define MWV207REG_MC_TEXTURE_CONFIG_DOWN_SAMPLER_Start                         8
#define MWV207REG_MC_TEXTURE_CONFIG_DOWN_SAMPLER_Type                        U01
#define   MWV207REG_MC_TEXTURE_CONFIG_DOWN_SAMPLER_DISABLED                  0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_DOWN_SAMPLER_ENABLED                   0x1


#define MWV207REG_MC_TEXTURE_CONFIG_COLOR64                                  9:9
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR64_End                                9
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR64_Start                              9
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR64_Type                             U01
#define   MWV207REG_MC_TEXTURE_CONFIG_COLOR64_COLOR16OR32                    0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_COLOR64_COLOR64                        0x1


#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL_DEC                            10:10
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL_DEC_End                           10
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL_DEC_Start                         10
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL_DEC_Type                         U01
#define   MWV207REG_MC_TEXTURE_CONFIG_CONTROL_DEC_DISABLE                    0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_CONTROL_DEC_ENABLE                     0x1


#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC                             13:11
#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_End                            13
#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_Start                          11
#define MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_Type                          U03
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_A8R8G8B8                    0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_X8R8G8B8                    0x1
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_AYUV                        0x2
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_UYVY                        0x3
#define   MWV207REG_MC_TEXTURE_CONFIG_FORMAT_DEC_YUY2                        0x4


#define MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC                            15:14
#define MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC_End                           15
#define MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC_Start                         14
#define MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC_Type                         U02
#define   MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC_ARGB                       0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC_RGBA                       0x1
#define   MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC_ABGR                       0x2
#define   MWV207REG_MC_TEXTURE_CONFIG_SWIZZLE_DEC_BGRA                       0x3


#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL256                             16:16
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL256_End                            16
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL256_Start                          16
#define MWV207REG_MC_TEXTURE_CONFIG_CONTROL256_Type                          U01
#define   MWV207REG_MC_TEXTURE_CONFIG_CONTROL256_DISABLE                     0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_CONTROL256_ENABLE                      0x1


#define MWV207REG_MC_TEXTURE_CONFIG_TILE_STATUS4_BIT                       17:17
#define MWV207REG_MC_TEXTURE_CONFIG_TILE_STATUS4_BIT_End                      17
#define MWV207REG_MC_TEXTURE_CONFIG_TILE_STATUS4_BIT_Start                    17
#define MWV207REG_MC_TEXTURE_CONFIG_TILE_STATUS4_BIT_Type                    U01
#define   MWV207REG_MC_TEXTURE_CONFIG_TILE_STATUS4_BIT_DISABLED              0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_TILE_STATUS4_BIT_ENABLED               0x1


#define MWV207REG_MC_TEXTURE_CONFIG_COLOR_YMAJOR                           19:19
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR_YMAJOR_End                          19
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR_YMAJOR_Start                        19
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR_YMAJOR_Type                        U01
#define   MWV207REG_MC_TEXTURE_CONFIG_COLOR_YMAJOR_DISABLE                   0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_COLOR_YMAJOR_ENABLE                    0x1


#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_COMPRESSION                       18:18
#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_COMPRESSION_End                      18
#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_COMPRESSION_Start                    18
#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_COMPRESSION_Type                    U01
#define   MWV207REG_MC_TEXTURE_CONFIG_MSAA_COMPRESSION_DISABLE               0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_MSAA_COMPRESSION_ENABLE                0x1


#define MWV207REG_MC_TEXTURE_CONFIG_COLOR128                               20:20
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR128_End                              20
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR128_Start                            20
#define MWV207REG_MC_TEXTURE_CONFIG_COLOR128_Type                            U01
#define   MWV207REG_MC_TEXTURE_CONFIG_COLOR128_DISABLE                       0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_COLOR128_ENABLE                        0x1


#define MWV207REG_MC_TEXTURE_CONFIG_ADDR_REMAP                             21:21
#define MWV207REG_MC_TEXTURE_CONFIG_ADDR_REMAP_End                            21
#define MWV207REG_MC_TEXTURE_CONFIG_ADDR_REMAP_Start                          21
#define MWV207REG_MC_TEXTURE_CONFIG_ADDR_REMAP_Type                          U01
#define   MWV207REG_MC_TEXTURE_CONFIG_ADDR_REMAP_DISABLED                    0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_ADDR_REMAP_ENABLED                     0x1


#define MWV207REG_MC_TEXTURE_CONFIG_DEPTH_ADDR_REMAP                       22:22
#define MWV207REG_MC_TEXTURE_CONFIG_DEPTH_ADDR_REMAP_End                      22
#define MWV207REG_MC_TEXTURE_CONFIG_DEPTH_ADDR_REMAP_Start                    22
#define MWV207REG_MC_TEXTURE_CONFIG_DEPTH_ADDR_REMAP_Type                    U01
#define   MWV207REG_MC_TEXTURE_CONFIG_DEPTH_ADDR_REMAP_DISABLED              0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_DEPTH_ADDR_REMAP_ENABLED               0x1


#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE                              25:24
#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE_End                             25
#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE_Start                           24
#define MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE_Type                           U02
#define   MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE_OFF                          0x0
#define   MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE_MSAA2                        0x1
#define   MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE_MSAA4                        0x2
#define   MWV207REG_MC_TEXTURE_CONFIG_MSAA_MODE_MSAA8                        0x3




#define mwv207regMCTextureBufferRegAddrs                                  0x05D0
#define MWV207REG_MC_TEXTURE_BUFFER_Address                              0x01740
#define MWV207REG_MC_TEXTURE_BUFFER_MSB                                       15
#define MWV207REG_MC_TEXTURE_BUFFER_LSB                                        3
#define MWV207REG_MC_TEXTURE_BUFFER_BLK                                        3
#define MWV207REG_MC_TEXTURE_BUFFER_Count                                      8
#define MWV207REG_MC_TEXTURE_BUFFER_FieldMask                         0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_BUFFER_ReadMask                          0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_BUFFER_WriteMask                         0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_BUFFER_ResetValue                        0x00000000


#define MWV207REG_MC_TEXTURE_BUFFER_ADDRESS                                 31:0
#define MWV207REG_MC_TEXTURE_BUFFER_ADDRESS_End                               31
#define MWV207REG_MC_TEXTURE_BUFFER_ADDRESS_Start                              0
#define MWV207REG_MC_TEXTURE_BUFFER_ADDRESS_Type                             U32




#define mwv207regMCTextureClearRegAddrs                                   0x05D8
#define MWV207REG_MC_TEXTURE_CLEAR_Address                               0x01760
#define MWV207REG_MC_TEXTURE_CLEAR_MSB                                        15
#define MWV207REG_MC_TEXTURE_CLEAR_LSB                                         3
#define MWV207REG_MC_TEXTURE_CLEAR_BLK                                         3
#define MWV207REG_MC_TEXTURE_CLEAR_Count                                       8
#define MWV207REG_MC_TEXTURE_CLEAR_FieldMask                          0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR_ReadMask                           0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR_WriteMask                          0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR_ResetValue                         0x00000000


#define MWV207REG_MC_TEXTURE_CLEAR_VALUE                                    31:0
#define MWV207REG_MC_TEXTURE_CLEAR_VALUE_End                                  31
#define MWV207REG_MC_TEXTURE_CLEAR_VALUE_Start                                 0
#define MWV207REG_MC_TEXTURE_CLEAR_VALUE_Type                                U32



#define mwv207regRSTileFillerTriggerRegAddrs                              0x05AC
#define MWV207REG_RS_TILE_FILLER_TRIGGER_Address                         0x016B0
#define MWV207REG_RS_TILE_FILLER_TRIGGER_MSB                                  15
#define MWV207REG_RS_TILE_FILLER_TRIGGER_LSB                                   0
#define MWV207REG_RS_TILE_FILLER_TRIGGER_BLK                                   0
#define MWV207REG_RS_TILE_FILLER_TRIGGER_Count                                 1
#define MWV207REG_RS_TILE_FILLER_TRIGGER_FieldMask                    0xFFFFFFFF
#define MWV207REG_RS_TILE_FILLER_TRIGGER_ReadMask                     0x00000000
#define MWV207REG_RS_TILE_FILLER_TRIGGER_WriteMask                    0xFFFFFFFF
#define MWV207REG_RS_TILE_FILLER_TRIGGER_ResetValue                   0x00000000


#define MWV207REG_RS_TILE_FILLER_TRIGGER_TILE_COUNT                         31:0
#define MWV207REG_RS_TILE_FILLER_TRIGGER_TILE_COUNT_End                       31
#define MWV207REG_RS_TILE_FILLER_TRIGGER_TILE_COUNT_Start                      0
#define MWV207REG_RS_TILE_FILLER_TRIGGER_TILE_COUNT_Type                     U32




#define mwv207regRSInterleaveAddressRegAddrs                              0x05AD
#define MWV207REG_RS_INTERLEAVE_ADDRESS_Address                          0x016B4
#define MWV207REG_RS_INTERLEAVE_ADDRESS_MSB                                   15
#define MWV207REG_RS_INTERLEAVE_ADDRESS_LSB                                    0
#define MWV207REG_RS_INTERLEAVE_ADDRESS_BLK                                    0
#define MWV207REG_RS_INTERLEAVE_ADDRESS_Count                                  1
#define MWV207REG_RS_INTERLEAVE_ADDRESS_FieldMask                     0xFFFFFFFF
#define MWV207REG_RS_INTERLEAVE_ADDRESS_ReadMask                      0xFFFFFFFF
#define MWV207REG_RS_INTERLEAVE_ADDRESS_WriteMask                     0xFFFFFFFF
#define MWV207REG_RS_INTERLEAVE_ADDRESS_ResetValue                    0x00000000

#define MWV207REG_RS_INTERLEAVE_ADDRESS_ADDRESS                             31:0
#define MWV207REG_RS_INTERLEAVE_ADDRESS_ADDRESS_End                           31
#define MWV207REG_RS_INTERLEAVE_ADDRESS_ADDRESS_Start                          0
#define MWV207REG_RS_INTERLEAVE_ADDRESS_ADDRESS_Type                         U32




#define mwv207regRSControlRegAddrs                                        0x05AE
#define MWV207REG_RS_CONTROL_Address                                     0x016B8
#define MWV207REG_RS_CONTROL_MSB                                              15
#define MWV207REG_RS_CONTROL_LSB                                               0
#define MWV207REG_RS_CONTROL_BLK                                               0
#define MWV207REG_RS_CONTROL_Count                                             1
#define MWV207REG_RS_CONTROL_FieldMask                                0x00000003
#define MWV207REG_RS_CONTROL_ReadMask                                 0x00000003
#define MWV207REG_RS_CONTROL_WriteMask                                0x00000003
#define MWV207REG_RS_CONTROL_ResetValue                               0x00000000


#define MWV207REG_RS_CONTROL_PIPE_ENABLE                                     0:0
#define MWV207REG_RS_CONTROL_PIPE_ENABLE_End                                   0
#define MWV207REG_RS_CONTROL_PIPE_ENABLE_Start                                 0
#define MWV207REG_RS_CONTROL_PIPE_ENABLE_Type                                U01

#define   MWV207REG_RS_CONTROL_PIPE_ENABLE_BOTH                              0x0

#define   MWV207REG_RS_CONTROL_PIPE_ENABLE_SINGLE                            0x1


#define MWV207REG_RS_CONTROL_FILTER_TYPE                                     1:1
#define MWV207REG_RS_CONTROL_FILTER_TYPE_End                                   1
#define MWV207REG_RS_CONTROL_FILTER_TYPE_Start                                 1
#define MWV207REG_RS_CONTROL_FILTER_TYPE_Type                                U01

#define   MWV207REG_RS_CONTROL_FILTER_TYPE_AVERAGE                           0x0

#define   MWV207REG_RS_CONTROL_FILTER_TYPE_SAMPLE                            0x1




#define mwv207regMCColorClear64RegAddrs                                   0x05AF
#define MWV207REG_MC_COLOR_CLEAR64_Address                               0x016BC
#define MWV207REG_MC_COLOR_CLEAR64_MSB                                        15
#define MWV207REG_MC_COLOR_CLEAR64_LSB                                         0
#define MWV207REG_MC_COLOR_CLEAR64_BLK                                         0
#define MWV207REG_MC_COLOR_CLEAR64_Count                                       1
#define MWV207REG_MC_COLOR_CLEAR64_FieldMask                          0xFFFFFFFF
#define MWV207REG_MC_COLOR_CLEAR64_ReadMask                           0xFFFFFFFF
#define MWV207REG_MC_COLOR_CLEAR64_WriteMask                          0xFFFFFFFF
#define MWV207REG_MC_COLOR_CLEAR64_ResetValue                         0x00000000

#define MWV207REG_MC_COLOR_CLEAR64_VALUE                                    31:0
#define MWV207REG_MC_COLOR_CLEAR64_VALUE_End                                  31
#define MWV207REG_MC_COLOR_CLEAR64_VALUE_Start                                 0
#define MWV207REG_MC_COLOR_CLEAR64_VALUE_Type                                U32




#define mwv207regMCTextureClear64RegAddrs                                 0x05E0
#define MWV207REG_MC_TEXTURE_CLEAR64_Address                             0x01780
#define MWV207REG_MC_TEXTURE_CLEAR64_MSB                                      15
#define MWV207REG_MC_TEXTURE_CLEAR64_LSB                                       3
#define MWV207REG_MC_TEXTURE_CLEAR64_BLK                                       3
#define MWV207REG_MC_TEXTURE_CLEAR64_Count                                     8
#define MWV207REG_MC_TEXTURE_CLEAR64_FieldMask                        0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR64_ReadMask                         0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR64_WriteMask                        0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR64_ResetValue                       0x00000000


#define MWV207REG_MC_TEXTURE_CLEAR64_VALUE                                  31:0
#define MWV207REG_MC_TEXTURE_CLEAR64_VALUE_End                                31
#define MWV207REG_MC_TEXTURE_CLEAR64_VALUE_Start                               0
#define MWV207REG_MC_TEXTURE_CLEAR64_VALUE_Type                              U32



#define mwv207regMRTMemoryConfigRegAddrs                                  0x05E8
#define MWV207REG_MRT_MEMORY_CONFIG_Address                              0x017A0
#define MWV207REG_MRT_MEMORY_CONFIG_MSB                                       15
#define MWV207REG_MRT_MEMORY_CONFIG_LSB                                        3
#define MWV207REG_MRT_MEMORY_CONFIG_BLK                                        3
#define MWV207REG_MRT_MEMORY_CONFIG_Count                                      8
#define MWV207REG_MRT_MEMORY_CONFIG_FieldMask                         0x00000FFF
#define MWV207REG_MRT_MEMORY_CONFIG_ReadMask                          0x00000FFF
#define MWV207REG_MRT_MEMORY_CONFIG_WriteMask                         0x00000FFF
#define MWV207REG_MRT_MEMORY_CONFIG_ResetValue                        0x00000000


#define MWV207REG_MRT_MEMORY_CONFIG_FAST_CLEAR_EN_C                          0:0
#define MWV207REG_MRT_MEMORY_CONFIG_FAST_CLEAR_EN_C_End                        0
#define MWV207REG_MRT_MEMORY_CONFIG_FAST_CLEAR_EN_C_Start                      0
#define MWV207REG_MRT_MEMORY_CONFIG_FAST_CLEAR_EN_C_Type                     U01
#define   MWV207REG_MRT_MEMORY_CONFIG_FAST_CLEAR_EN_C_DISABLE                0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_FAST_CLEAR_EN_C_ENABLE                 0x1


#define MWV207REG_MRT_MEMORY_CONFIG_AUTO_DISABLE_C                           1:1
#define MWV207REG_MRT_MEMORY_CONFIG_AUTO_DISABLE_C_End                         1
#define MWV207REG_MRT_MEMORY_CONFIG_AUTO_DISABLE_C_Start                       1
#define MWV207REG_MRT_MEMORY_CONFIG_AUTO_DISABLE_C_Type                      U01
#define   MWV207REG_MRT_MEMORY_CONFIG_AUTO_DISABLE_C_DISABLE                 0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_AUTO_DISABLE_C_ENABLE                  0x1


#define MWV207REG_MRT_MEMORY_CONFIG_COMPRESSION_EN_C                         2:2
#define MWV207REG_MRT_MEMORY_CONFIG_COMPRESSION_EN_C_End                       2
#define MWV207REG_MRT_MEMORY_CONFIG_COMPRESSION_EN_C_Start                     2
#define MWV207REG_MRT_MEMORY_CONFIG_COMPRESSION_EN_C_Type                    U01
#define   MWV207REG_MRT_MEMORY_CONFIG_COMPRESSION_EN_C_DISABLE               0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_COMPRESSION_EN_C_ENABLE                0x1

#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT                             6:3
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_End                           6
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_Start                         3
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_Type                        U04
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_ARGB4                     0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_A1RGB5                    0x1
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_R5G6B5                    0x2
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_ARGB8                     0x3
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_RGB8                      0x4
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_Z24S8                     0x5
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_Z24                       0x6
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_VAA16                     0x7
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_Z16                       0x8
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_S8                        0x9
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_SINGLE_Y_U_V              0xA
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_UV_MIX                    0xB
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_YUY2                      0xC
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_SINGLE_Y_U_V_P010         0xD
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_UV_MIX_P010               0xE
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_FORMAT_A2RGB10                   0xF


#define MWV207REG_MRT_MEMORY_CONFIG_COLOR64                                  7:7
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR64_End                                7
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR64_Start                              7
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR64_Type                             U01
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR64_COLOR16OR32                    0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR64_COLOR64                        0x1


#define MWV207REG_MRT_MEMORY_CONFIG_TILE_STATUS4_BIT                         8:8
#define MWV207REG_MRT_MEMORY_CONFIG_TILE_STATUS4_BIT_End                       8
#define MWV207REG_MRT_MEMORY_CONFIG_TILE_STATUS4_BIT_Start                     8
#define MWV207REG_MRT_MEMORY_CONFIG_TILE_STATUS4_BIT_Type                    U01
#define   MWV207REG_MRT_MEMORY_CONFIG_TILE_STATUS4_BIT_DISABLED              0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_TILE_STATUS4_BIT_ENABLED               0x1


#define MWV207REG_MRT_MEMORY_CONFIG_MSAA_COMPRESSION                         9:9
#define MWV207REG_MRT_MEMORY_CONFIG_MSAA_COMPRESSION_End                       9
#define MWV207REG_MRT_MEMORY_CONFIG_MSAA_COMPRESSION_Start                     9
#define MWV207REG_MRT_MEMORY_CONFIG_MSAA_COMPRESSION_Type                    U01
#define   MWV207REG_MRT_MEMORY_CONFIG_MSAA_COMPRESSION_DISABLE               0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_MSAA_COMPRESSION_ENABLE                0x1


#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_YMAJOR                           10:10
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_YMAJOR_End                          10
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_YMAJOR_Start                        10
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR_YMAJOR_Type                        U01
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_YMAJOR_DISABLE                   0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR_YMAJOR_ENABLE                    0x1


#define MWV207REG_MRT_MEMORY_CONFIG_COLOR128                               11:11
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR128_End                              11
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR128_Start                            11
#define MWV207REG_MRT_MEMORY_CONFIG_COLOR128_Type                            U01
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR128_DISABLE                       0x0
#define   MWV207REG_MRT_MEMORY_CONFIG_COLOR128_ENABLE                        0x1




#define mwv207regMRTColorCacheRegAddrs                                    0x05F0
#define MWV207REG_MRT_COLOR_CACHE_Address                                0x017C0
#define MWV207REG_MRT_COLOR_CACHE_MSB                                         15
#define MWV207REG_MRT_COLOR_CACHE_LSB                                          3
#define MWV207REG_MRT_COLOR_CACHE_BLK                                          3
#define MWV207REG_MRT_COLOR_CACHE_Count                                        8
#define MWV207REG_MRT_COLOR_CACHE_FieldMask                           0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CACHE_ReadMask                            0xFFFFFFFC
#define MWV207REG_MRT_COLOR_CACHE_WriteMask                           0xFFFFFFFC
#define MWV207REG_MRT_COLOR_CACHE_ResetValue                          0x00000000

#define MWV207REG_MRT_COLOR_CACHE_TYPE                                     31:31
#define MWV207REG_MRT_COLOR_CACHE_TYPE_End                                    31
#define MWV207REG_MRT_COLOR_CACHE_TYPE_Start                                  31
#define MWV207REG_MRT_COLOR_CACHE_TYPE_Type                                  U01
#define   MWV207REG_MRT_COLOR_CACHE_TYPE_SYSTEM                              0x0
#define   MWV207REG_MRT_COLOR_CACHE_TYPE_VIRTUAL_SYSTEM                      0x1

#define MWV207REG_MRT_COLOR_CACHE_ADDRESS                                   30:0
#define MWV207REG_MRT_COLOR_CACHE_ADDRESS_End                                 30
#define MWV207REG_MRT_COLOR_CACHE_ADDRESS_Start                                0
#define MWV207REG_MRT_COLOR_CACHE_ADDRESS_Type                               U31




#define mwv207regMRTColorBaseRegAddrs                                     0x05F8
#define MWV207REG_MRT_COLOR_BASE_Address                                 0x017E0
#define MWV207REG_MRT_COLOR_BASE_MSB                                          15
#define MWV207REG_MRT_COLOR_BASE_LSB                                           3
#define MWV207REG_MRT_COLOR_BASE_BLK                                           3
#define MWV207REG_MRT_COLOR_BASE_Count                                         8
#define MWV207REG_MRT_COLOR_BASE_FieldMask                            0xFFFFFFFF
#define MWV207REG_MRT_COLOR_BASE_ReadMask                             0xFFFFFFFC
#define MWV207REG_MRT_COLOR_BASE_WriteMask                            0xFFFFFFFC
#define MWV207REG_MRT_COLOR_BASE_ResetValue                           0x00000000

#define MWV207REG_MRT_COLOR_BASE_TYPE                                      31:31
#define MWV207REG_MRT_COLOR_BASE_TYPE_End                                     31
#define MWV207REG_MRT_COLOR_BASE_TYPE_Start                                   31
#define MWV207REG_MRT_COLOR_BASE_TYPE_Type                                   U01
#define   MWV207REG_MRT_COLOR_BASE_TYPE_SYSTEM                               0x0
#define   MWV207REG_MRT_COLOR_BASE_TYPE_VIRTUAL_SYSTEM                       0x1

#define MWV207REG_MRT_COLOR_BASE_ADDRESS                                    30:0
#define MWV207REG_MRT_COLOR_BASE_ADDRESS_End                                  30
#define MWV207REG_MRT_COLOR_BASE_ADDRESS_Start                                 0
#define MWV207REG_MRT_COLOR_BASE_ADDRESS_Type                                U31





#define mwv207regMRTColorClearValueRegAddrs                               0x0680
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_Address                          0x01A00
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_MSB                                   15
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_LSB                                    3
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_BLK                                    3
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_Count                                  8
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_FieldMask                     0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_ReadMask                      0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_WriteMask                     0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_ResetValue                    0x00000000

#define MWV207REG_MRT_COLOR_CLEAR_VALUE_VALUE                               31:0
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_VALUE_End                             31
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_VALUE_Start                            0
#define MWV207REG_MRT_COLOR_CLEAR_VALUE_VALUE_Type                           U32




#define mwv207regMRTMCColorClear64RegAddrs                                0x0688
#define MWV207REG_MRTMC_COLOR_CLEAR64_Address                            0x01A20
#define MWV207REG_MRTMC_COLOR_CLEAR64_MSB                                     15
#define MWV207REG_MRTMC_COLOR_CLEAR64_LSB                                      3
#define MWV207REG_MRTMC_COLOR_CLEAR64_BLK                                      3
#define MWV207REG_MRTMC_COLOR_CLEAR64_Count                                    8
#define MWV207REG_MRTMC_COLOR_CLEAR64_FieldMask                       0xFFFFFFFF
#define MWV207REG_MRTMC_COLOR_CLEAR64_ReadMask                        0xFFFFFFFF
#define MWV207REG_MRTMC_COLOR_CLEAR64_WriteMask                       0xFFFFFFFF
#define MWV207REG_MRTMC_COLOR_CLEAR64_ResetValue                      0x00000000

#define MWV207REG_MRTMC_COLOR_CLEAR64_VALUE                                 31:0
#define MWV207REG_MRTMC_COLOR_CLEAR64_VALUE_End                               31
#define MWV207REG_MRTMC_COLOR_CLEAR64_VALUE_Start                              0
#define MWV207REG_MRTMC_COLOR_CLEAR64_VALUE_Type                             U32



#define mwv207regMRTTileStatusCounterCRegAddrs                            0x0690
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_Address                      0x01A40
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_MSB                               15
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_LSB                                3
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_BLK                                3
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_Count                              8
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_FieldMask                 0xFFFFFFFF
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_ReadMask                  0xFFFFFFFF
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_WriteMask                 0xFFFFFFFF
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_ResetValue                0x00000000

#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_COUNTER                         31:0
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_COUNTER_End                       31
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_COUNTER_Start                      0
#define MWV207REG_MRT_TILE_STATUS_COUNTER_C_COUNTER_Type                     U32




#define mwv207regRSSrcSurfaceSizeRegAddrs                                 0x0698
#define MWV207REG_RS_SRC_SURFACE_SIZE_Address                            0x01A60
#define MWV207REG_RS_SRC_SURFACE_SIZE_MSB                                     15
#define MWV207REG_RS_SRC_SURFACE_SIZE_LSB                                      0
#define MWV207REG_RS_SRC_SURFACE_SIZE_BLK                                      0
#define MWV207REG_RS_SRC_SURFACE_SIZE_Count                                    1
#define MWV207REG_RS_SRC_SURFACE_SIZE_FieldMask                       0xFFFFFFFF
#define MWV207REG_RS_SRC_SURFACE_SIZE_ReadMask                        0xFFFFFFFF
#define MWV207REG_RS_SRC_SURFACE_SIZE_WriteMask                       0xFFFFFFFF
#define MWV207REG_RS_SRC_SURFACE_SIZE_ResetValue                      0x00000000


#define MWV207REG_RS_SRC_SURFACE_SIZE_WIDTH                                 15:0
#define MWV207REG_RS_SRC_SURFACE_SIZE_WIDTH_End                               15
#define MWV207REG_RS_SRC_SURFACE_SIZE_WIDTH_Start                              0
#define MWV207REG_RS_SRC_SURFACE_SIZE_WIDTH_Type                             U16


#define MWV207REG_RS_SRC_SURFACE_SIZE_HEIGHT                               31:16
#define MWV207REG_RS_SRC_SURFACE_SIZE_HEIGHT_End                              31
#define MWV207REG_RS_SRC_SURFACE_SIZE_HEIGHT_Start                            16
#define MWV207REG_RS_SRC_SURFACE_SIZE_HEIGHT_Type                            U16




#define mwv207regRSSrcRotationConfigRegAddrs                              0x0699
#define MWV207REG_RS_SRC_ROTATION_CONFIG_Address                         0x01A64
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MSB                                  15
#define MWV207REG_RS_SRC_ROTATION_CONFIG_LSB                                   0
#define MWV207REG_RS_SRC_ROTATION_CONFIG_BLK                                   0
#define MWV207REG_RS_SRC_ROTATION_CONFIG_Count                                 1
#define MWV207REG_RS_SRC_ROTATION_CONFIG_FieldMask                    0x0000007F
#define MWV207REG_RS_SRC_ROTATION_CONFIG_ReadMask                     0x0000007F
#define MWV207REG_RS_SRC_ROTATION_CONFIG_WriteMask                    0x0000007F
#define MWV207REG_RS_SRC_ROTATION_CONFIG_ResetValue                   0x00000000


#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_H                              0:0
#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_H_End                            0
#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_H_Start                          0
#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_H_Type                         U01
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_H_DISABLED                   0x0
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_H_ENABLE                     0x1

#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_H                         1:1
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_H_End                       1
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_H_Start                     1
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_H_Type                    U01
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_H_ENABLED               0x0
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_H_MASKED                0x1


#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_V                              2:2
#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_V_End                            2
#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_V_Start                          2
#define MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_V_Type                         U01
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_V_DISABLE                    0x0
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_FLIP_V_ENABLE                     0x1

#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_V                         3:3
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_V_End                       3
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_V_Start                     3
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_V_Type                    U01
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_V_ENABLED               0x0
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_FLIP_V_MASKED                0x1

#define MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION                            5:4
#define MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION_End                          5
#define MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION_Start                        4
#define MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION_Type                       U02
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION_DEGREE0                  0x0
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION_DEGREE90                 0x1
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION_DEGREE180                0x2
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_ROTATION_DEGREE270                0x3

#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_ROTATION                       6:6
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_ROTATION_End                     6
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_ROTATION_Start                   6
#define MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_ROTATION_Type                  U01
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_ROTATION_ENABLED             0x0
#define   MWV207REG_RS_SRC_ROTATION_CONFIG_MASK_ROTATION_MASKED              0x1




#define mwv207regMCTextureBaseBufferRegAddrs                              0x06A0
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_Address                         0x01A80
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_MSB                                  15
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_LSB                                   3
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_BLK                                   3
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_Count                                 8
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_FieldMask                    0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_ReadMask                     0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_WriteMask                    0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_ResetValue                   0x00000000


#define MWV207REG_MC_TEXTURE_BASE_BUFFER_ADDRESS                            31:0
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_ADDRESS_End                          31
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_ADDRESS_Start                         0
#define MWV207REG_MC_TEXTURE_BASE_BUFFER_ADDRESS_Type                        U32




#define mwv207regMCShaderConfigRegAddrs                                   0x069C
#define MWV207REG_MC_SHADER_CONFIG_Address                               0x01A70
#define MWV207REG_MC_SHADER_CONFIG_MSB                                        15
#define MWV207REG_MC_SHADER_CONFIG_LSB                                         2
#define MWV207REG_MC_SHADER_CONFIG_BLK                                         2
#define MWV207REG_MC_SHADER_CONFIG_Count                                       4
#define MWV207REG_MC_SHADER_CONFIG_FieldMask                          0x001C06F3
#define MWV207REG_MC_SHADER_CONFIG_ReadMask                           0x001C06F3
#define MWV207REG_MC_SHADER_CONFIG_WriteMask                          0x001C06F3
#define MWV207REG_MC_SHADER_CONFIG_ResetValue                         0x00000000


#define MWV207REG_MC_SHADER_CONFIG_CONTROL                                   1:0
#define MWV207REG_MC_SHADER_CONFIG_CONTROL_End                                 1
#define MWV207REG_MC_SHADER_CONFIG_CONTROL_Start                               0
#define MWV207REG_MC_SHADER_CONFIG_CONTROL_Type                              U02

#define   MWV207REG_MC_SHADER_CONFIG_CONTROL_DISABLE                         0x0

#define   MWV207REG_MC_SHADER_CONFIG_CONTROL_ENABLE                          0x1

#define   MWV207REG_MC_SHADER_CONFIG_CONTROL_COMPRESSED                      0x3


#define MWV207REG_MC_SHADER_CONFIG_FORMAT                                    7:4
#define MWV207REG_MC_SHADER_CONFIG_FORMAT_End                                  7
#define MWV207REG_MC_SHADER_CONFIG_FORMAT_Start                                4
#define MWV207REG_MC_SHADER_CONFIG_FORMAT_Type                               U04
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_ARGB4                            0x0
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_A1RGB5                           0x1
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_R5G6B5                           0x2
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_ARGB8                            0x3
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_RGB8                             0x4
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_Z24S8                            0x5
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_Z24                              0x6
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_VAA16                            0x7
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_Z16                              0x8
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_S8                               0x9
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_SINGLE_Y_U_V                     0xA
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_UV_MIX                           0xB
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_YUY2                             0xC
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_SINGLE_Y_U_V_P010                0xD
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_UV_MIX_P010                      0xE
#define   MWV207REG_MC_SHADER_CONFIG_FORMAT_A2RGB10                          0xF


#define MWV207REG_MC_SHADER_CONFIG_COLOR64                                   9:9
#define MWV207REG_MC_SHADER_CONFIG_COLOR64_End                                 9
#define MWV207REG_MC_SHADER_CONFIG_COLOR64_Start                               9
#define MWV207REG_MC_SHADER_CONFIG_COLOR64_Type                              U01
#define   MWV207REG_MC_SHADER_CONFIG_COLOR64_COLOR16OR32                     0x0
#define   MWV207REG_MC_SHADER_CONFIG_COLOR64_COLOR64                         0x1


#define MWV207REG_MC_SHADER_CONFIG_REQUEST_SIZE                            10:10
#define MWV207REG_MC_SHADER_CONFIG_REQUEST_SIZE_End                           10
#define MWV207REG_MC_SHADER_CONFIG_REQUEST_SIZE_Start                         10
#define MWV207REG_MC_SHADER_CONFIG_REQUEST_SIZE_Type                         U01
#define   MWV207REG_MC_SHADER_CONFIG_REQUEST_SIZE_SIZE128_B                  0x0
#define   MWV207REG_MC_SHADER_CONFIG_REQUEST_SIZE_SIZE256_B                  0x1


#define MWV207REG_MC_SHADER_CONFIG_COLOR_YMAJOR                            19:19
#define MWV207REG_MC_SHADER_CONFIG_COLOR_YMAJOR_End                           19
#define MWV207REG_MC_SHADER_CONFIG_COLOR_YMAJOR_Start                         19
#define MWV207REG_MC_SHADER_CONFIG_COLOR_YMAJOR_Type                         U01
#define   MWV207REG_MC_SHADER_CONFIG_COLOR_YMAJOR_DISABLE                    0x0
#define   MWV207REG_MC_SHADER_CONFIG_COLOR_YMAJOR_ENABLE                     0x1


#define MWV207REG_MC_SHADER_CONFIG_MSAA_COMPRESSION                        18:18
#define MWV207REG_MC_SHADER_CONFIG_MSAA_COMPRESSION_End                       18
#define MWV207REG_MC_SHADER_CONFIG_MSAA_COMPRESSION_Start                     18
#define MWV207REG_MC_SHADER_CONFIG_MSAA_COMPRESSION_Type                     U01
#define   MWV207REG_MC_SHADER_CONFIG_MSAA_COMPRESSION_DISABLE                0x0
#define   MWV207REG_MC_SHADER_CONFIG_MSAA_COMPRESSION_ENABLE                 0x1


#define MWV207REG_MC_SHADER_CONFIG_COLOR128                                20:20
#define MWV207REG_MC_SHADER_CONFIG_COLOR128_End                               20
#define MWV207REG_MC_SHADER_CONFIG_COLOR128_Start                             20
#define MWV207REG_MC_SHADER_CONFIG_COLOR128_Type                             U01
#define   MWV207REG_MC_SHADER_CONFIG_COLOR128_DISABLE                        0x0
#define   MWV207REG_MC_SHADER_CONFIG_COLOR128_ENABLE                         0x1




#define mwv207regMCShaderBufferRegAddrs                                   0x06A8
#define MWV207REG_MC_SHADER_BUFFER_Address                               0x01AA0
#define MWV207REG_MC_SHADER_BUFFER_MSB                                        15
#define MWV207REG_MC_SHADER_BUFFER_LSB                                         2
#define MWV207REG_MC_SHADER_BUFFER_BLK                                         2
#define MWV207REG_MC_SHADER_BUFFER_Count                                       4
#define MWV207REG_MC_SHADER_BUFFER_FieldMask                          0xFFFFFFFF
#define MWV207REG_MC_SHADER_BUFFER_ReadMask                           0xFFFFFFFF
#define MWV207REG_MC_SHADER_BUFFER_WriteMask                          0xFFFFFFFF
#define MWV207REG_MC_SHADER_BUFFER_ResetValue                         0x00000000


#define MWV207REG_MC_SHADER_BUFFER_ADDRESS                                  31:0
#define MWV207REG_MC_SHADER_BUFFER_ADDRESS_End                                31
#define MWV207REG_MC_SHADER_BUFFER_ADDRESS_Start                               0
#define MWV207REG_MC_SHADER_BUFFER_ADDRESS_Type                              U32




#define mwv207regMCShaderClearRegAddrs                                    0x06AC
#define MWV207REG_MC_SHADER_CLEAR_Address                                0x01AB0
#define MWV207REG_MC_SHADER_CLEAR_MSB                                         15
#define MWV207REG_MC_SHADER_CLEAR_LSB                                          2
#define MWV207REG_MC_SHADER_CLEAR_BLK                                          2
#define MWV207REG_MC_SHADER_CLEAR_Count                                        4
#define MWV207REG_MC_SHADER_CLEAR_FieldMask                           0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR_ReadMask                            0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR_WriteMask                           0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR_ResetValue                          0x00000000


#define MWV207REG_MC_SHADER_CLEAR_VALUE                                     31:0
#define MWV207REG_MC_SHADER_CLEAR_VALUE_End                                   31
#define MWV207REG_MC_SHADER_CLEAR_VALUE_Start                                  0
#define MWV207REG_MC_SHADER_CLEAR_VALUE_Type                                 U32




#define mwv207regMCShaderClear64RegAddrs                                  0x06B0
#define MWV207REG_MC_SHADER_CLEAR64_Address                              0x01AC0
#define MWV207REG_MC_SHADER_CLEAR64_MSB                                       15
#define MWV207REG_MC_SHADER_CLEAR64_LSB                                        2
#define MWV207REG_MC_SHADER_CLEAR64_BLK                                        2
#define MWV207REG_MC_SHADER_CLEAR64_Count                                      4
#define MWV207REG_MC_SHADER_CLEAR64_FieldMask                         0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR64_ReadMask                          0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR64_WriteMask                         0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR64_ResetValue                        0x00000000


#define MWV207REG_MC_SHADER_CLEAR64_VALUE                                   31:0
#define MWV207REG_MC_SHADER_CLEAR64_VALUE_End                                 31
#define MWV207REG_MC_SHADER_CLEAR64_VALUE_Start                                0
#define MWV207REG_MC_SHADER_CLEAR64_VALUE_Type                               U32




#define mwv207regMCShaderBaseBufferRegAddrs                               0x06B4
#define MWV207REG_MC_SHADER_BASE_BUFFER_Address                          0x01AD0
#define MWV207REG_MC_SHADER_BASE_BUFFER_MSB                                   15
#define MWV207REG_MC_SHADER_BASE_BUFFER_LSB                                    2
#define MWV207REG_MC_SHADER_BASE_BUFFER_BLK                                    2
#define MWV207REG_MC_SHADER_BASE_BUFFER_Count                                  4
#define MWV207REG_MC_SHADER_BASE_BUFFER_FieldMask                     0xFFFFFFFF
#define MWV207REG_MC_SHADER_BASE_BUFFER_ReadMask                      0xFFFFFFFF
#define MWV207REG_MC_SHADER_BASE_BUFFER_WriteMask                     0xFFFFFFFF
#define MWV207REG_MC_SHADER_BASE_BUFFER_ResetValue                    0x00000000


#define MWV207REG_MC_SHADER_BASE_BUFFER_ADDRESS                             31:0
#define MWV207REG_MC_SHADER_BASE_BUFFER_ADDRESS_End                           31
#define MWV207REG_MC_SHADER_BASE_BUFFER_ADDRESS_Start                          0
#define MWV207REG_MC_SHADER_BASE_BUFFER_ADDRESS_Type                         U32




#define mwv207regRSSrcBufferEndAddressRegAddrs                            0x069A
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_Address                      0x01A68
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_MSB                               15
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_LSB                                0
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_BLK                                0
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_Count                              1
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_FieldMask                 0xFFFFFFFF
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_ReadMask                  0xFFFFFFFF
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_WriteMask                 0xFFFFFFFF
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_ResetValue                0x00000000

#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_ADDRESS                         31:0
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_ADDRESS_End                       31
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_ADDRESS_Start                      0
#define MWV207REG_RS_SRC_BUFFER_END_ADDRESS_ADDRESS_Type                     U32




#define mwv207regRSSrcUBufferEndAddressRegAddrs                           0x069B
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_Address                     0x01A6C
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_MSB                              15
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_LSB                               0
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_BLK                               0
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_Count                             1
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_FieldMask                0xFFFFFFFF
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_ReadMask                 0xFFFFFFFF
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_WriteMask                0xFFFFFFFF
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_ResetValue               0x00000000

#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_ADDRESS                        31:0
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_ADDRESS_End                      31
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_ADDRESS_Start                     0
#define MWV207REG_RS_SRC_UBUFFER_END_ADDRESS_ADDRESS_Type                    U32




#define mwv207regRSSrcVBufferEndAddressRegAddrs                           0x06B8
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_Address                     0x01AE0
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_MSB                              15
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_LSB                               0
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_BLK                               0
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_Count                             1
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_FieldMask                0xFFFFFFFF
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_ReadMask                 0xFFFFFFFF
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_WriteMask                0xFFFFFFFF
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_ResetValue               0x00000000

#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_ADDRESS                        31:0
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_ADDRESS_End                      31
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_ADDRESS_Start                     0
#define MWV207REG_RS_SRC_VBUFFER_END_ADDRESS_ADDRESS_Type                    U32




#define mwv207regRSDstBufferEndAddressRegAddrs                            0x06B9
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_Address                      0x01AE4
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_MSB                               15
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_LSB                                0
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_BLK                                0
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_Count                              1
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_FieldMask                 0xFFFFFFFF
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_ReadMask                  0xFFFFFFFF
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_WriteMask                 0xFFFFFFFF
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_ResetValue                0x00000000

#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_ADDRESS                         31:0
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_ADDRESS_End                       31
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_ADDRESS_Start                      0
#define MWV207REG_RS_DST_BUFFER_END_ADDRESS_ADDRESS_Type                     U32

#define mwv207regRSDstConfigExRegAddrs                                    0x06BA
#define MWV207REG_RS_DST_CONFIG_EX_Address                               0x01AE8
#define MWV207REG_RS_DST_CONFIG_EX_MSB                                        15
#define MWV207REG_RS_DST_CONFIG_EX_LSB                                         0
#define MWV207REG_RS_DST_CONFIG_EX_BLK                                         0
#define MWV207REG_RS_DST_CONFIG_EX_Count                                       1
#define MWV207REG_RS_DST_CONFIG_EX_FieldMask                          0x00000107
#define MWV207REG_RS_DST_CONFIG_EX_ReadMask                           0x00000107
#define MWV207REG_RS_DST_CONFIG_EX_WriteMask                          0x00000107
#define MWV207REG_RS_DST_CONFIG_EX_ResetValue                         0x00000000


#define MWV207REG_RS_DST_CONFIG_EX_FORMAT                                    2:0
#define MWV207REG_RS_DST_CONFIG_EX_FORMAT_End                                  2
#define MWV207REG_RS_DST_CONFIG_EX_FORMAT_Start                                0
#define MWV207REG_RS_DST_CONFIG_EX_FORMAT_Type                               U03
#define   MWV207REG_RS_DST_CONFIG_EX_FORMAT_INVALID                          0x0
#define   MWV207REG_RS_DST_CONFIG_EX_FORMAT_UYVY                             0x1
#define   MWV207REG_RS_DST_CONFIG_EX_FORMAT_NV12                             0x2
#define   MWV207REG_RS_DST_CONFIG_EX_FORMAT_NV16                             0x3
#define   MWV207REG_RS_DST_CONFIG_EX_FORMAT_YV12                             0x4

#define MWV207REG_RS_DST_CONFIG_EX_UVSWIZZLE                                 8:8
#define MWV207REG_RS_DST_CONFIG_EX_UVSWIZZLE_End                               8
#define MWV207REG_RS_DST_CONFIG_EX_UVSWIZZLE_Start                             8
#define MWV207REG_RS_DST_CONFIG_EX_UVSWIZZLE_Type                            U01
#define   MWV207REG_RS_DST_CONFIG_EX_UVSWIZZLE_UV                            0x0
#define   MWV207REG_RS_DST_CONFIG_EX_UVSWIZZLE_VU                            0x1




#define mwv207regRSDstAddress1RegAddrs                                    0x06BB
#define MWV207REG_RS_DST_ADDRESS1_Address                                0x01AEC
#define MWV207REG_RS_DST_ADDRESS1_MSB                                         15
#define MWV207REG_RS_DST_ADDRESS1_LSB                                          0
#define MWV207REG_RS_DST_ADDRESS1_BLK                                          0
#define MWV207REG_RS_DST_ADDRESS1_Count                                        1
#define MWV207REG_RS_DST_ADDRESS1_FieldMask                           0xFFFFFFFF
#define MWV207REG_RS_DST_ADDRESS1_ReadMask                            0xFFFFFFFC
#define MWV207REG_RS_DST_ADDRESS1_WriteMask                           0xFFFFFFFC
#define MWV207REG_RS_DST_ADDRESS1_ResetValue                          0x00000000

#define MWV207REG_RS_DST_ADDRESS1_TYPE                                     31:31
#define MWV207REG_RS_DST_ADDRESS1_TYPE_End                                    31
#define MWV207REG_RS_DST_ADDRESS1_TYPE_Start                                  31
#define MWV207REG_RS_DST_ADDRESS1_TYPE_Type                                  U01
#define   MWV207REG_RS_DST_ADDRESS1_TYPE_SYSTEM                              0x0
#define   MWV207REG_RS_DST_ADDRESS1_TYPE_VIRTUAL_SYSTEM                      0x1

#define MWV207REG_RS_DST_ADDRESS1_ADDRESS                                   30:0
#define MWV207REG_RS_DST_ADDRESS1_ADDRESS_End                                 30
#define MWV207REG_RS_DST_ADDRESS1_ADDRESS_Start                                0
#define MWV207REG_RS_DST_ADDRESS1_ADDRESS_Type                               U31

#define mwv207regRSDstStride1RegAddrs                                     0x06BC
#define MWV207REG_RS_DST_STRIDE1_Address                                 0x01AF0
#define MWV207REG_RS_DST_STRIDE1_MSB                                          15
#define MWV207REG_RS_DST_STRIDE1_LSB                                           0
#define MWV207REG_RS_DST_STRIDE1_BLK                                           0
#define MWV207REG_RS_DST_STRIDE1_Count                                         1
#define MWV207REG_RS_DST_STRIDE1_FieldMask                            0x000FFFFF
#define MWV207REG_RS_DST_STRIDE1_ReadMask                             0x000FFFFF
#define MWV207REG_RS_DST_STRIDE1_WriteMask                            0x000FFFFF
#define MWV207REG_RS_DST_STRIDE1_ResetValue                           0x00000000


#define MWV207REG_RS_DST_STRIDE1_STRIDE                                     19:0
#define MWV207REG_RS_DST_STRIDE1_STRIDE_End                                   19
#define MWV207REG_RS_DST_STRIDE1_STRIDE_Start                                  0
#define MWV207REG_RS_DST_STRIDE1_STRIDE_Type                                 U20




#define mwv207regRSDstAddress2RegAddrs                                    0x06BD
#define MWV207REG_RS_DST_ADDRESS2_Address                                0x01AF4
#define MWV207REG_RS_DST_ADDRESS2_MSB                                         15
#define MWV207REG_RS_DST_ADDRESS2_LSB                                          0
#define MWV207REG_RS_DST_ADDRESS2_BLK                                          0
#define MWV207REG_RS_DST_ADDRESS2_Count                                        1
#define MWV207REG_RS_DST_ADDRESS2_FieldMask                           0xFFFFFFFF
#define MWV207REG_RS_DST_ADDRESS2_ReadMask                            0xFFFFFFFC
#define MWV207REG_RS_DST_ADDRESS2_WriteMask                           0xFFFFFFFC
#define MWV207REG_RS_DST_ADDRESS2_ResetValue                          0x00000000

#define MWV207REG_RS_DST_ADDRESS2_TYPE                                     31:31
#define MWV207REG_RS_DST_ADDRESS2_TYPE_End                                    31
#define MWV207REG_RS_DST_ADDRESS2_TYPE_Start                                  31
#define MWV207REG_RS_DST_ADDRESS2_TYPE_Type                                  U01
#define   MWV207REG_RS_DST_ADDRESS2_TYPE_SYSTEM                              0x0
#define   MWV207REG_RS_DST_ADDRESS2_TYPE_VIRTUAL_SYSTEM                      0x1

#define MWV207REG_RS_DST_ADDRESS2_ADDRESS                                   30:0
#define MWV207REG_RS_DST_ADDRESS2_ADDRESS_End                                 30
#define MWV207REG_RS_DST_ADDRESS2_ADDRESS_Start                                0
#define MWV207REG_RS_DST_ADDRESS2_ADDRESS_Type                               U31

#define mwv207regRSDstStride2RegAddrs                                     0x06BE
#define MWV207REG_RS_DST_STRIDE2_Address                                 0x01AF8
#define MWV207REG_RS_DST_STRIDE2_MSB                                          15
#define MWV207REG_RS_DST_STRIDE2_LSB                                           0
#define MWV207REG_RS_DST_STRIDE2_BLK                                           0
#define MWV207REG_RS_DST_STRIDE2_Count                                         1
#define MWV207REG_RS_DST_STRIDE2_FieldMask                            0x000FFFFF
#define MWV207REG_RS_DST_STRIDE2_ReadMask                             0x000FFFFF
#define MWV207REG_RS_DST_STRIDE2_WriteMask                            0x000FFFFF
#define MWV207REG_RS_DST_STRIDE2_ResetValue                           0x00000000


#define MWV207REG_RS_DST_STRIDE2_STRIDE                                     19:0
#define MWV207REG_RS_DST_STRIDE2_STRIDE_End                                   19
#define MWV207REG_RS_DST_STRIDE2_STRIDE_Start                                  0
#define MWV207REG_RS_DST_STRIDE2_STRIDE_Type                                 U20



#define jmMemoryConfigExRegAddrs                                          0x06BF
#define JM_MEMORY_CONFIG_EX_Address                                      0x01AFC
#define JM_MEMORY_CONFIG_EX_MSB                                               15
#define JM_MEMORY_CONFIG_EX_LSB                                                0
#define JM_MEMORY_CONFIG_EX_BLK                                                0
#define JM_MEMORY_CONFIG_EX_Count                                              1
#define JM_MEMORY_CONFIG_EX_FieldMask                                 0x00000003
#define JM_MEMORY_CONFIG_EX_ReadMask                                  0x00000003
#define JM_MEMORY_CONFIG_EX_WriteMask                                 0x00000003
#define JM_MEMORY_CONFIG_EX_ResetValue                                0x00000000


#define JM_MEMORY_CONFIG_EX_COLOR128                                         0:0
#define JM_MEMORY_CONFIG_EX_COLOR128_End                                       0
#define JM_MEMORY_CONFIG_EX_COLOR128_Start                                     0
#define JM_MEMORY_CONFIG_EX_COLOR128_Type                                    U01
#define   JM_MEMORY_CONFIG_EX_COLOR128_DISABLE                               0x0
#define   JM_MEMORY_CONFIG_EX_COLOR128_ENABLE                                0x1


#define JM_MEMORY_CONFIG_EX_DEPTH64                                          1:1
#define JM_MEMORY_CONFIG_EX_DEPTH64_End                                        1
#define JM_MEMORY_CONFIG_EX_DEPTH64_Start                                      1
#define JM_MEMORY_CONFIG_EX_DEPTH64_Type                                     U01
#define   JM_MEMORY_CONFIG_EX_DEPTH64_DISABLE                                0x0
#define   JM_MEMORY_CONFIG_EX_DEPTH64_ENABLE                                 0x1




#define mwv207regMRTColorClearValue96RegAddrs                             0x06C0
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_Address                        0x01B00
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_MSB                                 15
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_LSB                                  3
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_BLK                                  3
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_Count                                8
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_FieldMask                   0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_ReadMask                    0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_WriteMask                   0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_ResetValue                  0x00000000

#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_VALUE                             31:0
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_VALUE_End                           31
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_VALUE_Start                          0
#define MWV207REG_MRT_COLOR_CLEAR_VALUE96_VALUE_Type                         U32




#define mwv207regMRTColorClearValue128RegAddrs                            0x06C8
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_Address                       0x01B20
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_MSB                                15
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_LSB                                 3
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_BLK                                 3
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_Count                               8
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_FieldMask                  0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_ReadMask                   0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_WriteMask                  0xFFFFFFFF
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_ResetValue                 0x00000000

#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_VALUE                            31:0
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_VALUE_End                          31
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_VALUE_Start                         0
#define MWV207REG_MRT_COLOR_CLEAR_VALUE128_VALUE_Type                        U32




#define jmDepthClearValue64RegAddrs                                       0x06D0
#define JM_DEPTH_CLEAR_VALUE64_Address                                   0x01B40
#define JM_DEPTH_CLEAR_VALUE64_MSB                                            15
#define JM_DEPTH_CLEAR_VALUE64_LSB                                             0
#define JM_DEPTH_CLEAR_VALUE64_BLK                                             0
#define JM_DEPTH_CLEAR_VALUE64_Count                                           1
#define JM_DEPTH_CLEAR_VALUE64_FieldMask                              0xFFFFFFFF
#define JM_DEPTH_CLEAR_VALUE64_ReadMask                               0xFFFFFFFF
#define JM_DEPTH_CLEAR_VALUE64_WriteMask                              0xFFFFFFFF
#define JM_DEPTH_CLEAR_VALUE64_ResetValue                             0x00000000

#define JM_DEPTH_CLEAR_VALUE64_VALUE                                        31:0
#define JM_DEPTH_CLEAR_VALUE64_VALUE_End                                      31
#define JM_DEPTH_CLEAR_VALUE64_VALUE_Start                                     0
#define JM_DEPTH_CLEAR_VALUE64_VALUE_Type                                    U32




#define mwv207regMCShaderClear96RegAddrs                                  0x06D4
#define MWV207REG_MC_SHADER_CLEAR96_Address                              0x01B50
#define MWV207REG_MC_SHADER_CLEAR96_MSB                                       15
#define MWV207REG_MC_SHADER_CLEAR96_LSB                                        2
#define MWV207REG_MC_SHADER_CLEAR96_BLK                                        2
#define MWV207REG_MC_SHADER_CLEAR96_Count                                      4
#define MWV207REG_MC_SHADER_CLEAR96_FieldMask                         0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR96_ReadMask                          0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR96_WriteMask                         0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR96_ResetValue                        0x00000000


#define MWV207REG_MC_SHADER_CLEAR96_VALUE                                   31:0
#define MWV207REG_MC_SHADER_CLEAR96_VALUE_End                                 31
#define MWV207REG_MC_SHADER_CLEAR96_VALUE_Start                                0
#define MWV207REG_MC_SHADER_CLEAR96_VALUE_Type                               U32




#define mwv207regMCShaderClear128RegAddrs                                 0x06D8
#define MWV207REG_MC_SHADER_CLEAR128_Address                             0x01B60
#define MWV207REG_MC_SHADER_CLEAR128_MSB                                      15
#define MWV207REG_MC_SHADER_CLEAR128_LSB                                       2
#define MWV207REG_MC_SHADER_CLEAR128_BLK                                       2
#define MWV207REG_MC_SHADER_CLEAR128_Count                                     4
#define MWV207REG_MC_SHADER_CLEAR128_FieldMask                        0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR128_ReadMask                         0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR128_WriteMask                        0xFFFFFFFF
#define MWV207REG_MC_SHADER_CLEAR128_ResetValue                       0x00000000


#define MWV207REG_MC_SHADER_CLEAR128_VALUE                                  31:0
#define MWV207REG_MC_SHADER_CLEAR128_VALUE_End                                31
#define MWV207REG_MC_SHADER_CLEAR128_VALUE_Start                               0
#define MWV207REG_MC_SHADER_CLEAR128_VALUE_Type                              U32




#define mwv207regMCTextureClear96RegAddrs                                 0x06DC
#define MWV207REG_MC_TEXTURE_CLEAR96_Address                             0x01B70
#define MWV207REG_MC_TEXTURE_CLEAR96_MSB                                      15
#define MWV207REG_MC_TEXTURE_CLEAR96_LSB                                       2
#define MWV207REG_MC_TEXTURE_CLEAR96_BLK                                       2
#define MWV207REG_MC_TEXTURE_CLEAR96_Count                                     4
#define MWV207REG_MC_TEXTURE_CLEAR96_FieldMask                        0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR96_ReadMask                         0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR96_WriteMask                        0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR96_ResetValue                       0x00000000


#define MWV207REG_MC_TEXTURE_CLEAR96_VALUE                                  31:0
#define MWV207REG_MC_TEXTURE_CLEAR96_VALUE_End                                31
#define MWV207REG_MC_TEXTURE_CLEAR96_VALUE_Start                               0
#define MWV207REG_MC_TEXTURE_CLEAR96_VALUE_Type                              U32




#define mwv207regMCTextureClear128RegAddrs                                0x06E0
#define MWV207REG_MC_TEXTURE_CLEAR128_Address                            0x01B80
#define MWV207REG_MC_TEXTURE_CLEAR128_MSB                                     15
#define MWV207REG_MC_TEXTURE_CLEAR128_LSB                                      2
#define MWV207REG_MC_TEXTURE_CLEAR128_BLK                                      2
#define MWV207REG_MC_TEXTURE_CLEAR128_Count                                    4
#define MWV207REG_MC_TEXTURE_CLEAR128_FieldMask                       0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR128_ReadMask                        0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR128_WriteMask                       0xFFFFFFFF
#define MWV207REG_MC_TEXTURE_CLEAR128_ResetValue                      0x00000000


#define MWV207REG_MC_TEXTURE_CLEAR128_VALUE                                 31:0
#define MWV207REG_MC_TEXTURE_CLEAR128_VALUE_End                               31
#define MWV207REG_MC_TEXTURE_CLEAR128_VALUE_Start                              0
#define MWV207REG_MC_TEXTURE_CLEAR128_VALUE_Type                             U32


#endif


