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




#ifndef __jmgpuregTexture_h__
#define __jmgpuregTexture_h__


#define mwv207regTXConfigRegAddrs                                         0x4000
#define MWV207REG_TX_CONFIG_Address                                      0x10000
#define MWV207REG_TX_CONFIG_MSB                                               15
#define MWV207REG_TX_CONFIG_LSB                                                5
#define MWV207REG_TX_CONFIG_BLK                                                0
#define MWV207REG_TX_CONFIG_Count                                             32
#define MWV207REG_TX_CONFIG_FieldMask                                 0xFFFFFFFF
#define MWV207REG_TX_CONFIG_ReadMask                                  0xFFFFFFFF
#define MWV207REG_TX_CONFIG_WriteMask                                 0xFFFFFFFF
#define MWV207REG_TX_CONFIG_ResetValue                                0x00000000


#define MWV207REG_TX_CONFIG_TYPE                                             2:0
#define MWV207REG_TX_CONFIG_TYPE_End                                           2
#define MWV207REG_TX_CONFIG_TYPE_Start                                         0
#define MWV207REG_TX_CONFIG_TYPE_Type                                        U03
#define   MWV207REG_TX_CONFIG_TYPE_NONE                                      0x0
#define   MWV207REG_TX_CONFIG_TYPE_1D                                        0x1
#define   MWV207REG_TX_CONFIG_TYPE_2D                                        0x2
#define   MWV207REG_TX_CONFIG_TYPE_3D                                        0x3
#define   MWV207REG_TX_CONFIG_TYPE_PROJECTED                                 0x4
#define   MWV207REG_TX_CONFIG_TYPE_CUBIC_MAP                                 0x5


#define MWV207REG_TX_CONFIG_ADDR_UMODE                                       4:3
#define MWV207REG_TX_CONFIG_ADDR_UMODE_End                                     4
#define MWV207REG_TX_CONFIG_ADDR_UMODE_Start                                   3
#define MWV207REG_TX_CONFIG_ADDR_UMODE_Type                                  U02
#define   MWV207REG_TX_CONFIG_ADDR_UMODE_WRAP                                0x0
#define   MWV207REG_TX_CONFIG_ADDR_UMODE_MIRROR                              0x1
#define   MWV207REG_TX_CONFIG_ADDR_UMODE_CLAMP                               0x2
#define   MWV207REG_TX_CONFIG_ADDR_UMODE_BORDER                              0x3


#define MWV207REG_TX_CONFIG_ADDR_VMODE                                       6:5
#define MWV207REG_TX_CONFIG_ADDR_VMODE_End                                     6
#define MWV207REG_TX_CONFIG_ADDR_VMODE_Start                                   5
#define MWV207REG_TX_CONFIG_ADDR_VMODE_Type                                  U02
#define   MWV207REG_TX_CONFIG_ADDR_VMODE_WRAP                                0x0
#define   MWV207REG_TX_CONFIG_ADDR_VMODE_MIRROR                              0x1
#define   MWV207REG_TX_CONFIG_ADDR_VMODE_CLAMP                               0x2
#define   MWV207REG_TX_CONFIG_ADDR_VMODE_BORDER                              0x3


#define MWV207REG_TX_CONFIG_MIN_FILTER                                       8:7
#define MWV207REG_TX_CONFIG_MIN_FILTER_End                                     8
#define MWV207REG_TX_CONFIG_MIN_FILTER_Start                                   7
#define MWV207REG_TX_CONFIG_MIN_FILTER_Type                                  U02
#define   MWV207REG_TX_CONFIG_MIN_FILTER_NONE                                0x0
#define   MWV207REG_TX_CONFIG_MIN_FILTER_POINT                               0x1
#define   MWV207REG_TX_CONFIG_MIN_FILTER_LINEAR                              0x2
#define   MWV207REG_TX_CONFIG_MIN_FILTER_ANISOTROPIC                         0x3


#define MWV207REG_TX_CONFIG_MIP_FILTER                                      10:9
#define MWV207REG_TX_CONFIG_MIP_FILTER_End                                    10
#define MWV207REG_TX_CONFIG_MIP_FILTER_Start                                   9
#define MWV207REG_TX_CONFIG_MIP_FILTER_Type                                  U02
#define   MWV207REG_TX_CONFIG_MIP_FILTER_NONE                                0x0
#define   MWV207REG_TX_CONFIG_MIP_FILTER_POINT                               0x1
#define   MWV207REG_TX_CONFIG_MIP_FILTER_LINEAR                              0x2
#define   MWV207REG_TX_CONFIG_MIP_FILTER_ANISOTROPIC                         0x3


#define MWV207REG_TX_CONFIG_MAG_FILTER                                     12:11
#define MWV207REG_TX_CONFIG_MAG_FILTER_End                                    12
#define MWV207REG_TX_CONFIG_MAG_FILTER_Start                                  11
#define MWV207REG_TX_CONFIG_MAG_FILTER_Type                                  U02
#define   MWV207REG_TX_CONFIG_MAG_FILTER_NONE                                0x0
#define   MWV207REG_TX_CONFIG_MAG_FILTER_POINT                               0x1
#define   MWV207REG_TX_CONFIG_MAG_FILTER_LINEAR                              0x2
#define   MWV207REG_TX_CONFIG_MAG_FILTER_ANISOTROPIC                         0x3


#define MWV207REG_TX_CONFIG_FORMAT                                         17:13
#define MWV207REG_TX_CONFIG_FORMAT_End                                        17
#define MWV207REG_TX_CONFIG_FORMAT_Start                                      13
#define MWV207REG_TX_CONFIG_FORMAT_Type                                      U05
#define   MWV207REG_TX_CONFIG_FORMAT_A8                                     0x01
#define   MWV207REG_TX_CONFIG_FORMAT_L8                                     0x02
#define   MWV207REG_TX_CONFIG_FORMAT_I8                                     0x03
#define   MWV207REG_TX_CONFIG_FORMAT_A8L8                                   0x04
#define   MWV207REG_TX_CONFIG_FORMAT_ARGB4                                  0x05
#define   MWV207REG_TX_CONFIG_FORMAT_XRGB4                                  0x06
#define   MWV207REG_TX_CONFIG_FORMAT_ARGB8                                  0x07
#define   MWV207REG_TX_CONFIG_FORMAT_XRGB8                                  0x08
#define   MWV207REG_TX_CONFIG_FORMAT_ABGR8                                  0x09
#define   MWV207REG_TX_CONFIG_FORMAT_XBGR8                                  0x0A
#define   MWV207REG_TX_CONFIG_FORMAT_R5G6B5                                 0x0B
#define   MWV207REG_TX_CONFIG_FORMAT_A1RGB5                                 0x0C
#define   MWV207REG_TX_CONFIG_FORMAT_X1RGB5                                 0x0D
#define   MWV207REG_TX_CONFIG_FORMAT_YUY2                                   0x0E
#define   MWV207REG_TX_CONFIG_FORMAT_UYVY                                   0x0F
#define   MWV207REG_TX_CONFIG_FORMAT_D16                                    0x10
#define   MWV207REG_TX_CONFIG_FORMAT_D24X8                                  0x11
#define   MWV207REG_TX_CONFIG_FORMAT_A8_OES                                 0x12
#define   MWV207REG_TX_CONFIG_FORMAT_DXT1                                   0x13
#define   MWV207REG_TX_CONFIG_FORMAT_DXT2                                   0x14
#define   MWV207REG_TX_CONFIG_FORMAT_DXT3                                   0x14
#define   MWV207REG_TX_CONFIG_FORMAT_DXT4                                   0x15
#define   MWV207REG_TX_CONFIG_FORMAT_DXT5                                   0x15
#define   MWV207REG_TX_CONFIG_FORMAT_HDR7E3                                 0x16
#define   MWV207REG_TX_CONFIG_FORMAT_HDR6E4                                 0x17
#define   MWV207REG_TX_CONFIG_FORMAT_HDR5E5                                 0x18
#define   MWV207REG_TX_CONFIG_FORMAT_HDR6E5                                 0x19
#define   MWV207REG_TX_CONFIG_FORMAT_RGBE8                                  0x1A
#define   MWV207REG_TX_CONFIG_FORMAT_RGBE8F                                 0x1B
#define   MWV207REG_TX_CONFIG_FORMAT_RGB9E5                                 0x1C
#define   MWV207REG_TX_CONFIG_FORMAT_RGB9E5F                                0x1D
#define   MWV207REG_TX_CONFIG_FORMAT_ETC1                                   0x1E


#define MWV207REG_TX_CONFIG_FILTER_CONSTANT                                18:18
#define MWV207REG_TX_CONFIG_FILTER_CONSTANT_End                               18
#define MWV207REG_TX_CONFIG_FILTER_CONSTANT_Start                             18
#define MWV207REG_TX_CONFIG_FILTER_CONSTANT_Type                             U01
#define   MWV207REG_TX_CONFIG_FILTER_CONSTANT_DISABLE                        0x0
#define   MWV207REG_TX_CONFIG_FILTER_CONSTANT_ENABLE                         0x1


#define MWV207REG_TX_CONFIG_ROUND_UV                                       19:19
#define MWV207REG_TX_CONFIG_ROUND_UV_End                                      19
#define MWV207REG_TX_CONFIG_ROUND_UV_Start                                    19
#define MWV207REG_TX_CONFIG_ROUND_UV_Type                                    U01
#define   MWV207REG_TX_CONFIG_ROUND_UV_DISABLE                               0x0
#define   MWV207REG_TX_CONFIG_ROUND_UV_ENABLE                                0x1


#define MWV207REG_TX_CONFIG_ADDRESSING                                     21:20
#define MWV207REG_TX_CONFIG_ADDRESSING_End                                    21
#define MWV207REG_TX_CONFIG_ADDRESSING_Start                                  20
#define MWV207REG_TX_CONFIG_ADDRESSING_Type                                  U02

#define   MWV207REG_TX_CONFIG_ADDRESSING_NO_STRIDE                           0x0

#define   MWV207REG_TX_CONFIG_ADDRESSING_NO_STRIDE_LINEAR                    0x1

#define   MWV207REG_TX_CONFIG_ADDRESSING_TILED                               0x2

#define   MWV207REG_TX_CONFIG_ADDRESSING_LINEAR                              0x3


#define MWV207REG_TX_CONFIG_ENDIAN_CONTROL                                 23:22
#define MWV207REG_TX_CONFIG_ENDIAN_CONTROL_End                                23
#define MWV207REG_TX_CONFIG_ENDIAN_CONTROL_Start                              22
#define MWV207REG_TX_CONFIG_ENDIAN_CONTROL_Type                              U02
#define   MWV207REG_TX_CONFIG_ENDIAN_CONTROL_NO_SWAP                         0x0
#define   MWV207REG_TX_CONFIG_ENDIAN_CONTROL_SWAP_WORD                       0x1
#define   MWV207REG_TX_CONFIG_ENDIAN_CONTROL_SWAP_DWORD                      0x2
#define   MWV207REG_TX_CONFIG_ENDIAN_CONTROL_SWAP_DDWORD                     0x3


#define MWV207REG_TX_CONFIG_ANISO_MAX_LOG                                  31:24
#define MWV207REG_TX_CONFIG_ANISO_MAX_LOG_End                                 31
#define MWV207REG_TX_CONFIG_ANISO_MAX_LOG_Start                               24
#define MWV207REG_TX_CONFIG_ANISO_MAX_LOG_Type                               U08

#define mwv207regTXSizeRegAddrs                                           0x4020
#define MWV207REG_TX_SIZE_Address                                        0x10080
#define MWV207REG_TX_SIZE_MSB                                                 15
#define MWV207REG_TX_SIZE_LSB                                                  5
#define MWV207REG_TX_SIZE_BLK                                                  0
#define MWV207REG_TX_SIZE_Count                                               32
#define MWV207REG_TX_SIZE_FieldMask                                   0x7FFF7FFF
#define MWV207REG_TX_SIZE_ReadMask                                    0x7FFF7FFF
#define MWV207REG_TX_SIZE_WriteMask                                   0x7FFF7FFF
#define MWV207REG_TX_SIZE_ResetValue                                  0x00000000


#define MWV207REG_TX_SIZE_INT_WIDTH                                         14:0
#define MWV207REG_TX_SIZE_INT_WIDTH_End                                       14
#define MWV207REG_TX_SIZE_INT_WIDTH_Start                                      0
#define MWV207REG_TX_SIZE_INT_WIDTH_Type                                     U15


#define MWV207REG_TX_SIZE_INT_HEIGHT                                       30:16
#define MWV207REG_TX_SIZE_INT_HEIGHT_End                                      30
#define MWV207REG_TX_SIZE_INT_HEIGHT_Start                                    16
#define MWV207REG_TX_SIZE_INT_HEIGHT_Type                                    U15

#define mwv207regTXLogSizeRegAddrs                                        0x4040
#define MWV207REG_TX_LOG_SIZE_Address                                    0x10100
#define MWV207REG_TX_LOG_SIZE_MSB                                             15
#define MWV207REG_TX_LOG_SIZE_LSB                                              5
#define MWV207REG_TX_LOG_SIZE_BLK                                              0
#define MWV207REG_TX_LOG_SIZE_Count                                           32
#define MWV207REG_TX_LOG_SIZE_FieldMask                               0xF80FFFFF
#define MWV207REG_TX_LOG_SIZE_ReadMask                                0xF80FFFFF
#define MWV207REG_TX_LOG_SIZE_WriteMask                               0xF80FFFFF
#define MWV207REG_TX_LOG_SIZE_ResetValue                              0x00000000


#define MWV207REG_TX_LOG_SIZE_LOG_WIDTH                                      9:0
#define MWV207REG_TX_LOG_SIZE_LOG_WIDTH_End                                    9
#define MWV207REG_TX_LOG_SIZE_LOG_WIDTH_Start                                  0
#define MWV207REG_TX_LOG_SIZE_LOG_WIDTH_Type                                 U10


#define MWV207REG_TX_LOG_SIZE_LOG_HEIGHT                                   19:10
#define MWV207REG_TX_LOG_SIZE_LOG_HEIGHT_End                                  19
#define MWV207REG_TX_LOG_SIZE_LOG_HEIGHT_Start                                10
#define MWV207REG_TX_LOG_SIZE_LOG_HEIGHT_Type                                U10


#define MWV207REG_TX_LOG_SIZE_TX2_SH_NORMALIZE                             28:27
#define MWV207REG_TX_LOG_SIZE_TX2_SH_NORMALIZE_End                            28
#define MWV207REG_TX_LOG_SIZE_TX2_SH_NORMALIZE_Start                          27
#define MWV207REG_TX_LOG_SIZE_TX2_SH_NORMALIZE_Type                          U02

#define   MWV207REG_TX_LOG_SIZE_TX2_SH_NORMALIZE_AUTO                        0x0

#define   MWV207REG_TX_LOG_SIZE_TX2_SH_NORMALIZE_ENABLED                     0x1

#define   MWV207REG_TX_LOG_SIZE_TX2_SH_NORMALIZE_DISABLED                    0x2


#define MWV207REG_TX_LOG_SIZE_INTEGER_FILTER_CONTROL                       29:29
#define MWV207REG_TX_LOG_SIZE_INTEGER_FILTER_CONTROL_End                      29
#define MWV207REG_TX_LOG_SIZE_INTEGER_FILTER_CONTROL_Start                    29
#define MWV207REG_TX_LOG_SIZE_INTEGER_FILTER_CONTROL_Type                    U01

#define   MWV207REG_TX_LOG_SIZE_INTEGER_FILTER_CONTROL_NATIVE                0x0

#define   MWV207REG_TX_LOG_SIZE_INTEGER_FILTER_CONTROL_INTEGER               0x1


#define MWV207REG_TX_LOG_SIZE_NON_POWER_OF_TWO_CONTROL                     30:30
#define MWV207REG_TX_LOG_SIZE_NON_POWER_OF_TWO_CONTROL_End                    30
#define MWV207REG_TX_LOG_SIZE_NON_POWER_OF_TWO_CONTROL_Start                  30
#define MWV207REG_TX_LOG_SIZE_NON_POWER_OF_TWO_CONTROL_Type                  U01

#define   MWV207REG_TX_LOG_SIZE_NON_POWER_OF_TWO_CONTROL_NON_POWER_OF_TWO    0x0

#define   MWV207REG_TX_LOG_SIZE_NON_POWER_OF_TWO_CONTROL_POWER_OF_TWO        0x1


#define MWV207REG_TX_LOG_SIZE_SRGB                                         31:31
#define MWV207REG_TX_LOG_SIZE_SRGB_End                                        31
#define MWV207REG_TX_LOG_SIZE_SRGB_Start                                      31
#define MWV207REG_TX_LOG_SIZE_SRGB_Type                                      U01
#define   MWV207REG_TX_LOG_SIZE_SRGB_DISABLE                                 0x0
#define   MWV207REG_TX_LOG_SIZE_SRGB_ENABLE                                  0x1

#define mwv207regTXLodRegAddrs                                            0x4060
#define MWV207REG_TX_LOD_Address                                         0x10180
#define MWV207REG_TX_LOD_MSB                                                  15
#define MWV207REG_TX_LOD_LSB                                                   5
#define MWV207REG_TX_LOD_BLK                                                   0
#define MWV207REG_TX_LOD_Count                                                32
#define MWV207REG_TX_LOD_FieldMask                                    0x7FFFFFFF
#define MWV207REG_TX_LOD_ReadMask                                     0x7FFFFFFF
#define MWV207REG_TX_LOD_WriteMask                                    0x7FFFFFFF
#define MWV207REG_TX_LOD_ResetValue                                   0x00000000


#define MWV207REG_TX_LOD_EN_LOD_BIAS                                         0:0
#define MWV207REG_TX_LOD_EN_LOD_BIAS_End                                       0
#define MWV207REG_TX_LOD_EN_LOD_BIAS_Start                                     0
#define MWV207REG_TX_LOD_EN_LOD_BIAS_Type                                    U01
#define   MWV207REG_TX_LOD_EN_LOD_BIAS_DISABLE                               0x0
#define   MWV207REG_TX_LOD_EN_LOD_BIAS_ENABLE                                0x1


#define MWV207REG_TX_LOD_MAX_LOD_FIX5DOT5                                   10:1
#define MWV207REG_TX_LOD_MAX_LOD_FIX5DOT5_End                                 10
#define MWV207REG_TX_LOD_MAX_LOD_FIX5DOT5_Start                                1
#define MWV207REG_TX_LOD_MAX_LOD_FIX5DOT5_Type                               U10


#define MWV207REG_TX_LOD_MIN_LOD_FIX5DOT5                                  20:11
#define MWV207REG_TX_LOD_MIN_LOD_FIX5DOT5_End                                 20
#define MWV207REG_TX_LOD_MIN_LOD_FIX5DOT5_Start                               11
#define MWV207REG_TX_LOD_MIN_LOD_FIX5DOT5_Type                               U10


#define MWV207REG_TX_LOD_BIAS_LOD_FIX5DOT5                                 30:21
#define MWV207REG_TX_LOD_BIAS_LOD_FIX5DOT5_End                                30
#define MWV207REG_TX_LOD_BIAS_LOD_FIX5DOT5_Start                              21
#define MWV207REG_TX_LOD_BIAS_LOD_FIX5DOT5_Type                              U10

#define mwv207regTXBorderColorRegAddrs                                    0x4080
#define MWV207REG_TX_BORDER_COLOR_Address                                0x10200
#define MWV207REG_TX_BORDER_COLOR_MSB                                         15
#define MWV207REG_TX_BORDER_COLOR_LSB                                          5
#define MWV207REG_TX_BORDER_COLOR_BLK                                          0
#define MWV207REG_TX_BORDER_COLOR_Count                                       32
#define MWV207REG_TX_BORDER_COLOR_FieldMask                           0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_ReadMask                            0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_WriteMask                           0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_ResetValue                          0x00000000

#define MWV207REG_TX_BORDER_COLOR_ALPHA                                    31:24
#define MWV207REG_TX_BORDER_COLOR_ALPHA_End                                   31
#define MWV207REG_TX_BORDER_COLOR_ALPHA_Start                                 24
#define MWV207REG_TX_BORDER_COLOR_ALPHA_Type                                 U08

#define MWV207REG_TX_BORDER_COLOR_RED                                      23:16
#define MWV207REG_TX_BORDER_COLOR_RED_End                                     23
#define MWV207REG_TX_BORDER_COLOR_RED_Start                                   16
#define MWV207REG_TX_BORDER_COLOR_RED_Type                                   U08

#define MWV207REG_TX_BORDER_COLOR_GREEN                                     15:8
#define MWV207REG_TX_BORDER_COLOR_GREEN_End                                   15
#define MWV207REG_TX_BORDER_COLOR_GREEN_Start                                  8
#define MWV207REG_TX_BORDER_COLOR_GREEN_Type                                 U08

#define MWV207REG_TX_BORDER_COLOR_BLUE                                       7:0
#define MWV207REG_TX_BORDER_COLOR_BLUE_End                                     7
#define MWV207REG_TX_BORDER_COLOR_BLUE_Start                                   0
#define MWV207REG_TX_BORDER_COLOR_BLUE_Type                                  U08




#define mwv207regTXLinearStrideRegAddrs                                   0x40A0
#define MWV207REG_TX_LINEAR_STRIDE_Address                               0x10280
#define MWV207REG_TX_LINEAR_STRIDE_MSB                                        15
#define MWV207REG_TX_LINEAR_STRIDE_LSB                                         5
#define MWV207REG_TX_LINEAR_STRIDE_BLK                                         0
#define MWV207REG_TX_LINEAR_STRIDE_Count                                      32
#define MWV207REG_TX_LINEAR_STRIDE_FieldMask                          0x0003FFFF
#define MWV207REG_TX_LINEAR_STRIDE_ReadMask                           0x0003FFFF
#define MWV207REG_TX_LINEAR_STRIDE_WriteMask                          0x0003FFFF
#define MWV207REG_TX_LINEAR_STRIDE_ResetValue                         0x00000000


#define MWV207REG_TX_LINEAR_STRIDE_STRIDE                                   17:0
#define MWV207REG_TX_LINEAR_STRIDE_STRIDE_End                                 17
#define MWV207REG_TX_LINEAR_STRIDE_STRIDE_Start                                0
#define MWV207REG_TX_LINEAR_STRIDE_STRIDE_Type                               U18




#define mwv207regTX3DRegAddrs                                             0x40C0
#define MWV207REG_TX3_D_Address                                          0x10300
#define MWV207REG_TX3_D_MSB                                                   15
#define MWV207REG_TX3_D_LSB                                                    5
#define MWV207REG_TX3_D_BLK                                                    0
#define MWV207REG_TX3_D_Count                                                 32
#define MWV207REG_TX3_D_FieldMask                                     0x33FF3FFF
#define MWV207REG_TX3_D_ReadMask                                      0x33FF3FFF
#define MWV207REG_TX3_D_WriteMask                                     0x33FF3FFF
#define MWV207REG_TX3_D_ResetValue                                    0x00000000


#define MWV207REG_TX3_D_DEPTH                                               13:0
#define MWV207REG_TX3_D_DEPTH_End                                             13
#define MWV207REG_TX3_D_DEPTH_Start                                            0
#define MWV207REG_TX3_D_DEPTH_Type                                           U14


#define MWV207REG_TX3_D_LOG_DEPTH                                          25:16
#define MWV207REG_TX3_D_LOG_DEPTH_End                                         25
#define MWV207REG_TX3_D_LOG_DEPTH_Start                                       16
#define MWV207REG_TX3_D_LOG_DEPTH_Type                                       U10


#define MWV207REG_TX3_D_MODE                                               29:28
#define MWV207REG_TX3_D_MODE_End                                              29
#define MWV207REG_TX3_D_MODE_Start                                            28
#define MWV207REG_TX3_D_MODE_Type                                            U02
#define   MWV207REG_TX3_D_MODE_WRAP                                          0x0
#define   MWV207REG_TX3_D_MODE_MIRROR                                        0x1
#define   MWV207REG_TX3_D_MODE_CLAMP                                         0x2
#define   MWV207REG_TX3_D_MODE_BORDER                                        0x3




#define mwv207regTXExtConfigRegAddrs                                      0x40E0
#define MWV207REG_TX_EXT_CONFIG_Address                                  0x10380
#define MWV207REG_TX_EXT_CONFIG_MSB                                           15
#define MWV207REG_TX_EXT_CONFIG_LSB                                            5
#define MWV207REG_TX_EXT_CONFIG_BLK                                            0
#define MWV207REG_TX_EXT_CONFIG_Count                                         32
#define MWV207REG_TX_EXT_CONFIG_FieldMask                             0xFFFFFFBF
#define MWV207REG_TX_EXT_CONFIG_ReadMask                              0xFFFFFFBF
#define MWV207REG_TX_EXT_CONFIG_WriteMask                             0xFFFFFFBF
#define MWV207REG_TX_EXT_CONFIG_ResetValue                            0x00321000

#define MWV207REG_TX_EXT_CONFIG_FORMAT                                       5:0
#define MWV207REG_TX_EXT_CONFIG_FORMAT_End                                     5
#define MWV207REG_TX_EXT_CONFIG_FORMAT_Start                                   0
#define MWV207REG_TX_EXT_CONFIG_FORMAT_Type                                  U06
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_ETC2_RGB8                          0x00
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_ETC2_RGB8A1                        0x01
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_ETC2_RGB8A8                        0x02
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_EAC__R11_UNSIGNED                  0x03
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_EAC__RG11_UNSIGNED                 0x04
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_EAC__RG11_SIGNED                   0x05
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_R8G8                               0x06
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RF16                               0x07
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RF16GF16                           0x08
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RF16GF16BGF16AF16                  0x09
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RF32                               0x0A
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RF32GF32                           0x0B
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_R10G10B10A2                        0x0C
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_EAC__R11_SIGNED                    0x0D
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_R8__SNORM                          0x0E
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RG8__SNORM                         0x0F
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RGBX8__SNORM                       0x10
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RGBA8__SNORM                       0x11
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RGB8                               0x12
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_YUV_ASSEMBLY                       0x13
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_ASTC                               0x14
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI8                                0x15
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI8GI8                             0x16
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI8GI8BI8AI8                       0x17
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI16                               0x18
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI16GI16                           0x19
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI16GI16BI16AI16                   0x1A
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI32                               0x0A
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI32GI32                           0x0B
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RF11GF11BF10                       0x1B
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI10GI10BI10AI2                    0x1C
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_R8G8B8G8                           0x1D
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_G8R8G8B8                           0x1E
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI8GI8BI8GI8                       0x1F
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_GI8RI8GI8BI8                       0x20
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_R8                                 0x21
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_D24S8                              0x22
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI32_NEW                           0x23
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI32GI32_NEW                       0x24
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_AYUV                               0x25
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RF32GF32BF32AF32                   0x26
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RI32GI32BI32AI32                   0x27
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RUI32GUI32BUI32AUI32               0x27
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RSI32GSI32BSI32ASI32               0x28
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_D32F                               0x29
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_D32FS8                             0x2A
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_BC4_UNORM                          0x2B
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_BC4_SNORM                          0x2C
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_BC5_UNORM                          0x2D
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_BC5_SNORM                          0x2E
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_BC6_UF16                           0x2F
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_BC6_SF16                           0x30
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_BC7_UNORM                          0x31
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RGBA16_UNORM                       0x32
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RGBA16_SNORM                       0x33
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RG16_UNORM                         0x34
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_RG16_SNORM                         0x35
#define   MWV207REG_TX_EXT_CONFIG_FORMAT_R16_SNORM                          0x36


#define MWV207REG_TX_EXT_CONFIG_COLOR_SWIZZLE                                7:7
#define MWV207REG_TX_EXT_CONFIG_COLOR_SWIZZLE_End                              7
#define MWV207REG_TX_EXT_CONFIG_COLOR_SWIZZLE_Start                            7
#define MWV207REG_TX_EXT_CONFIG_COLOR_SWIZZLE_Type                           U01
#define   MWV207REG_TX_EXT_CONFIG_COLOR_SWIZZLE_DISABLE                      0x0
#define   MWV207REG_TX_EXT_CONFIG_COLOR_SWIZZLE_ENABLE                       0x1


#define MWV207REG_TX_EXT_CONFIG_SWAP_Y                                     11:11
#define MWV207REG_TX_EXT_CONFIG_SWAP_Y_End                                    11
#define MWV207REG_TX_EXT_CONFIG_SWAP_Y_Start                                  11
#define MWV207REG_TX_EXT_CONFIG_SWAP_Y_Type                                  U01


#define MWV207REG_TX_EXT_CONFIG_SWAP_UV                                    15:15
#define MWV207REG_TX_EXT_CONFIG_SWAP_UV_End                                   15
#define MWV207REG_TX_EXT_CONFIG_SWAP_UV_Start                                 15
#define MWV207REG_TX_EXT_CONFIG_SWAP_UV_Type                                 U01


#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED                                 10:8
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_End                               10
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_Start                              8
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_Type                             U03
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_RED                            0x0
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_GREEN                          0x1
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_BLUE                           0x2
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_ALPHA                          0x3
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_ZERO                           0x4
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_RED_ONE                            0x5


#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN                              14:12
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_End                             14
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_Start                           12
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_Type                           U03
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_RED                          0x0
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_GREEN                        0x1
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_BLUE                         0x2
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_ALPHA                        0x3
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_ZERO                         0x4
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_GREEN_ONE                          0x5


#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE                               18:16
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_End                              18
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_Start                            16
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_Type                            U03
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_RED                           0x0
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_GREEN                         0x1
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_BLUE                          0x2
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_ALPHA                         0x3
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_ZERO                          0x4
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_BLUE_ONE                           0x5


#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA                              22:20
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_End                             22
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_Start                           20
#define MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_Type                           U03
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_RED                          0x0
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_GREEN                        0x1
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_BLUE                         0x2
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_ALPHA                        0x3
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_ZERO                         0x4
#define   MWV207REG_TX_EXT_CONFIG_SWIZZLE_ALPHA_ONE                          0x5

#define MWV207REG_TX_EXT_CONFIG_FLIP_Y                                     19:19
#define MWV207REG_TX_EXT_CONFIG_FLIP_Y_End                                    19
#define MWV207REG_TX_EXT_CONFIG_FLIP_Y_Start                                  19
#define MWV207REG_TX_EXT_CONFIG_FLIP_Y_Type                                  U01
#define   MWV207REG_TX_EXT_CONFIG_FLIP_Y_NORMAL                              0x0
#define   MWV207REG_TX_EXT_CONFIG_FLIP_Y_UPSIDE_DOWN                         0x1


#define MWV207REG_TX_EXT_CONFIG_TX256_BYTE_REQUEST                         23:23
#define MWV207REG_TX_EXT_CONFIG_TX256_BYTE_REQUEST_End                        23
#define MWV207REG_TX_EXT_CONFIG_TX256_BYTE_REQUEST_Start                      23
#define MWV207REG_TX_EXT_CONFIG_TX256_BYTE_REQUEST_Type                      U01
#define   MWV207REG_TX_EXT_CONFIG_TX256_BYTE_REQUEST_DISABLE                 0x0
#define   MWV207REG_TX_EXT_CONFIG_TX256_BYTE_REQUEST_ENABLE                  0x1


#define MWV207REG_TX_EXT_CONFIG_TEXTURE_ARRAY                              24:24
#define MWV207REG_TX_EXT_CONFIG_TEXTURE_ARRAY_End                             24
#define MWV207REG_TX_EXT_CONFIG_TEXTURE_ARRAY_Start                           24
#define MWV207REG_TX_EXT_CONFIG_TEXTURE_ARRAY_Type                           U01
#define   MWV207REG_TX_EXT_CONFIG_TEXTURE_ARRAY_DISABLE                      0x0
#define   MWV207REG_TX_EXT_CONFIG_TEXTURE_ARRAY_ENABLE                       0x1


#define MWV207REG_TX_EXT_CONFIG_EN_SEAMLESS_CUBE_MAP                       25:25
#define MWV207REG_TX_EXT_CONFIG_EN_SEAMLESS_CUBE_MAP_End                      25
#define MWV207REG_TX_EXT_CONFIG_EN_SEAMLESS_CUBE_MAP_Start                    25
#define MWV207REG_TX_EXT_CONFIG_EN_SEAMLESS_CUBE_MAP_Type                    U01
#define   MWV207REG_TX_EXT_CONFIG_EN_SEAMLESS_CUBE_MAP_DISABLE               0x0
#define   MWV207REG_TX_EXT_CONFIG_EN_SEAMLESS_CUBE_MAP_ENABLE                0x1


#define MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN                            28:26
#define MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_End                           28
#define MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_Start                         26
#define MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_Type                         U03

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_FOUR                       0x0

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_SIXTEEN                    0x1

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_SUPER_TILED                0x2

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_SPLIT_TILED                0x3

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_SPLIT_SUPER_TILED          0x4

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_SPLIT_TILED_BIG            0x5

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_SPLIT_SUPER_TILED_BIG      0x6

#define   MWV207REG_TX_EXT_CONFIG_HORIZONAL_ALIGN_SUPER_TILED_YMAJOR         0x7


#define MWV207REG_TX_EXT_CONFIG_YUV_STANDARD                               29:29
#define MWV207REG_TX_EXT_CONFIG_YUV_STANDARD_End                              29
#define MWV207REG_TX_EXT_CONFIG_YUV_STANDARD_Start                            29
#define MWV207REG_TX_EXT_CONFIG_YUV_STANDARD_Type                            U01

#define   MWV207REG_TX_EXT_CONFIG_YUV_STANDARD_YUV601                        0x0

#define   MWV207REG_TX_EXT_CONFIG_YUV_STANDARD_YUV709                        0x1

#define MWV207REG_TX_EXT_CONFIG_TILE_STATUS                                30:30
#define MWV207REG_TX_EXT_CONFIG_TILE_STATUS_End                               30
#define MWV207REG_TX_EXT_CONFIG_TILE_STATUS_Start                             30
#define MWV207REG_TX_EXT_CONFIG_TILE_STATUS_Type                             U01

#define   MWV207REG_TX_EXT_CONFIG_TILE_STATUS_NO                             0x0

#define   MWV207REG_TX_EXT_CONFIG_TILE_STATUS_YES                            0x1


#define MWV207REG_TX_EXT_CONFIG_IMAGE_FILTER                               31:31
#define MWV207REG_TX_EXT_CONFIG_IMAGE_FILTER_End                              31
#define MWV207REG_TX_EXT_CONFIG_IMAGE_FILTER_Start                            31
#define MWV207REG_TX_EXT_CONFIG_IMAGE_FILTER_Type                            U01

#define   MWV207REG_TX_EXT_CONFIG_IMAGE_FILTER_NORMAL                        0x0

#define   MWV207REG_TX_EXT_CONFIG_IMAGE_FILTER_FILTER_KERNEL                 0x1




#define mwv207regTXAddressRegAddrs                                        0x4200
#define MWV207REG_TX_ADDRESS_Address                                     0x10800
#define MWV207REG_TX_ADDRESS_MSB                                              15
#define MWV207REG_TX_ADDRESS_LSB                                               9
#define MWV207REG_TX_ADDRESS_BLK                                               4
#define MWV207REG_TX_ADDRESS_Count                                           512
#define MWV207REG_TX_ADDRESS_FieldMask                                0xFFFFFFFF
#define MWV207REG_TX_ADDRESS_ReadMask                                 0xFFFFFFFC
#define MWV207REG_TX_ADDRESS_WriteMask                                0xFFFFFFFC
#define MWV207REG_TX_ADDRESS_ResetValue                               0x00000000

#define MWV207REG_TX_ADDRESS_TYPE                                          31:31
#define MWV207REG_TX_ADDRESS_TYPE_End                                         31
#define MWV207REG_TX_ADDRESS_TYPE_Start                                       31
#define MWV207REG_TX_ADDRESS_TYPE_Type                                       U01
#define   MWV207REG_TX_ADDRESS_TYPE_SYSTEM                                   0x0
#define   MWV207REG_TX_ADDRESS_TYPE_VIRTUAL_SYSTEM                           0x1

#define MWV207REG_TX_ADDRESS_ADDRESS                                        30:0
#define MWV207REG_TX_ADDRESS_ADDRESS_End                                      30
#define MWV207REG_TX_ADDRESS_ADDRESS_Start                                     0
#define MWV207REG_TX_ADDRESS_ADDRESS_Type                                    U31




#define mwv207regTXControlYUVExRegAddrs                                   0x4100
#define MWV207REG_TX_CONTROL_YUV_EX_Address                              0x10400
#define MWV207REG_TX_CONTROL_YUV_EX_MSB                                       15
#define MWV207REG_TX_CONTROL_YUV_EX_LSB                                        5
#define MWV207REG_TX_CONTROL_YUV_EX_BLK                                        0
#define MWV207REG_TX_CONTROL_YUV_EX_Count                                     32
#define MWV207REG_TX_CONTROL_YUV_EX_FieldMask                         0xFFFF7F73
#define MWV207REG_TX_CONTROL_YUV_EX_ReadMask                          0xFFFF7F73
#define MWV207REG_TX_CONTROL_YUV_EX_WriteMask                         0xFFFF7F73
#define MWV207REG_TX_CONTROL_YUV_EX_ResetValue                        0x00000000


#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X                                 1:0
#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X_End                               1
#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X_Start                             0
#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X_Type                            U02

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X_NONE                          0x0

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X_ONE                           0x1

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X_TWO                           0x2

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_X_FOUR                          0x3


#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y                                 5:4
#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y_End                               5
#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y_Start                             4
#define MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y_Type                            U02

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y_NONE                          0x0

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y_ONE                           0x1

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y_TWO                           0x2

#define   MWV207REG_TX_CONTROL_YUV_EX_FORMAT_Y_FOUR                          0x3


#define MWV207REG_TX_CONTROL_YUV_EX_CHANNEL_BITS                             6:6
#define MWV207REG_TX_CONTROL_YUV_EX_CHANNEL_BITS_End                           6
#define MWV207REG_TX_CONTROL_YUV_EX_CHANNEL_BITS_Start                         6
#define MWV207REG_TX_CONTROL_YUV_EX_CHANNEL_BITS_Type                        U01

#define   MWV207REG_TX_CONTROL_YUV_EX_CHANNEL_BITS_BITS8                     0x0

#define   MWV207REG_TX_CONTROL_YUV_EX_CHANNEL_BITS_BITS10                    0x1


#define MWV207REG_TX_CONTROL_YUV_EX_YOFFSET                                 10:8
#define MWV207REG_TX_CONTROL_YUV_EX_YOFFSET_End                               10
#define MWV207REG_TX_CONTROL_YUV_EX_YOFFSET_Start                              8
#define MWV207REG_TX_CONTROL_YUV_EX_YOFFSET_Type                             U03


#define MWV207REG_TX_CONTROL_YUV_EX_TILE_EX                                11:11
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_EX_End                               11
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_EX_Start                             11
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_EX_Type                             U01

#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_EX_NO_EXTERNED                    0x0

#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_EX_CUSTOMER0                      0x1


#define MWV207REG_TX_CONTROL_YUV_EX_UOFFSET                                14:12
#define MWV207REG_TX_CONTROL_YUV_EX_UOFFSET_End                               14
#define MWV207REG_TX_CONTROL_YUV_EX_UOFFSET_Start                             12
#define MWV207REG_TX_CONTROL_YUV_EX_UOFFSET_Type                             U03


#define MWV207REG_TX_CONTROL_YUV_EX_VOFFSET                                18:16
#define MWV207REG_TX_CONTROL_YUV_EX_VOFFSET_End                               18
#define MWV207REG_TX_CONTROL_YUV_EX_VOFFSET_Start                             16
#define MWV207REG_TX_CONTROL_YUV_EX_VOFFSET_Type                             U03


#define MWV207REG_TX_CONTROL_YUV_EX_IS_P010                                19:19
#define MWV207REG_TX_CONTROL_YUV_EX_IS_P010_End                               19
#define MWV207REG_TX_CONTROL_YUV_EX_IS_P010_Start                             19
#define MWV207REG_TX_CONTROL_YUV_EX_IS_P010_Type                             U01

#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVED                            20:20
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVED_End                           20
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVED_Start                         20
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVED_Type                         U01
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVED_PLANAR                     0x0
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVED_INTERLEAVED                0x1


#define MWV207REG_TX_CONTROL_YUV_EX_INTERLACED                             21:21
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLACED_End                            21
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLACED_Start                          21
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLACED_Type                          U01
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLACED_PROGRESSIVE                 0x0

#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLACED_INTERLACED                  0x1


#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_Y                   23:22
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_Y_End                  23
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_Y_Start                22
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_Y_Type                U02
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_Y_PLANE_Y           0x0
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_Y_PLANE_U           0x1
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_Y_PLANE_V           0x2


#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_U                   25:24
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_U_End                  25
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_U_Start                24
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_U_Type                U02
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_U_PLANE_Y           0x0
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_U_PLANE_U           0x1
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_U_PLANE_V           0x2


#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_V                   27:26
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_V_End                  27
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_V_Start                26
#define MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_V_Type                U02
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_V_PLANE_Y           0x0
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_V_PLANE_U           0x1
#define   MWV207REG_TX_CONTROL_YUV_EX_INTERLEAVE_SWIZZLE_V_PLANE_V           0x2


#define MWV207REG_TX_CONTROL_YUV_EX_TILE_Y                                 29:28
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_Y_End                                29
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_Y_Start                              28
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_Y_Type                              U02
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_Y_LINEAR                          0x0
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_Y_TILE4X4                         0x1
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_Y_TILE8X8                         0x2
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_Y_TILE16X16                       0x3


#define MWV207REG_TX_CONTROL_YUV_EX_TILE_UV                                31:30
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_UV_End                               31
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_UV_Start                             30
#define MWV207REG_TX_CONTROL_YUV_EX_TILE_UV_Type                             U02
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_UV_LINEAR                         0x0
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_UV_TILE4X4                        0x1
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_UV_TILE8X8                        0x2
#define   MWV207REG_TX_CONTROL_YUV_EX_TILE_UV_TILE16X16                      0x3




#define mwv207regTXStrideYUVExRegAddrs                                    0x4120
#define MWV207REG_TX_STRIDE_YUV_EX_Address                               0x10480
#define MWV207REG_TX_STRIDE_YUV_EX_MSB                                        15
#define MWV207REG_TX_STRIDE_YUV_EX_LSB                                         5
#define MWV207REG_TX_STRIDE_YUV_EX_BLK                                         0
#define MWV207REG_TX_STRIDE_YUV_EX_Count                                      32
#define MWV207REG_TX_STRIDE_YUV_EX_FieldMask                          0xFFFFFFFF
#define MWV207REG_TX_STRIDE_YUV_EX_ReadMask                           0xFFFFFFFF
#define MWV207REG_TX_STRIDE_YUV_EX_WriteMask                          0xFFFFFFFF
#define MWV207REG_TX_STRIDE_YUV_EX_ResetValue                         0x00000000


#define MWV207REG_TX_STRIDE_YUV_EX_USTRIDE                                  15:0
#define MWV207REG_TX_STRIDE_YUV_EX_USTRIDE_End                                15
#define MWV207REG_TX_STRIDE_YUV_EX_USTRIDE_Start                               0
#define MWV207REG_TX_STRIDE_YUV_EX_USTRIDE_Type                              U16


#define MWV207REG_TX_STRIDE_YUV_EX_VSTRIDE                                 31:16
#define MWV207REG_TX_STRIDE_YUV_EX_VSTRIDE_End                                31
#define MWV207REG_TX_STRIDE_YUV_EX_VSTRIDE_Start                              16
#define MWV207REG_TX_STRIDE_YUV_EX_VSTRIDE_Type                              U16




#define mwv207regTxASTC0ExRegAddrs                                        0x4140
#define MWV207REG_TX_ASTC0_EX_Address                                    0x10500
#define MWV207REG_TX_ASTC0_EX_MSB                                             15
#define MWV207REG_TX_ASTC0_EX_LSB                                              5
#define MWV207REG_TX_ASTC0_EX_BLK                                              0
#define MWV207REG_TX_ASTC0_EX_Count                                           32
#define MWV207REG_TX_ASTC0_EX_FieldMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC0_EX_ReadMask                                0x1F1F1F1F
#define MWV207REG_TX_ASTC0_EX_WriteMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC0_EX_ResetValue                              0x00000000


#define MWV207REG_TX_ASTC0_EX_SIZE_LOD0                                      3:0
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD0_End                                    3
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD0_Start                                  0
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD0_Type                                 U04
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_4x4                                0x0
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_5x4                                0x1
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_5x5                                0x2
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_6x5                                0x3
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_6x6                                0x4
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_8x5                                0x5
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_8x6                                0x6
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_8x8                                0x7
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_10x5                               0x8
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_10x6                               0x9
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_10x8                               0xA
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_10x10                              0xB
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_12x10                              0xC
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD0_12x12                              0xD


#define MWV207REG_TX_ASTC0_EX_SRGB_LOD0                                      4:4
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD0_End                                    4
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD0_Start                                  4
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD0_Type                                 U01
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD0_DISABLE                            0x0
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD0_ENABLE                             0x1


#define MWV207REG_TX_ASTC0_EX_SIZE_LOD1                                     11:8
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD1_End                                   11
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD1_Start                                  8
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD1_Type                                 U04
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_4x4                                0x0
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_5x4                                0x1
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_5x5                                0x2
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_6x5                                0x3
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_6x6                                0x4
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_8x5                                0x5
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_8x6                                0x6
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_8x8                                0x7
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_10x5                               0x8
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_10x6                               0x9
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_10x8                               0xA
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_10x10                              0xB
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_12x10                              0xC
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD1_12x12                              0xD


#define MWV207REG_TX_ASTC0_EX_SRGB_LOD1                                    12:12
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD1_End                                   12
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD1_Start                                 12
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD1_Type                                 U01
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD1_DISABLE                            0x0
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD1_ENABLE                             0x1


#define MWV207REG_TX_ASTC0_EX_SIZE_LOD2                                    19:16
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD2_End                                   19
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD2_Start                                 16
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD2_Type                                 U04
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_4x4                                0x0
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_5x4                                0x1
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_5x5                                0x2
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_6x5                                0x3
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_6x6                                0x4
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_8x5                                0x5
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_8x6                                0x6
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_8x8                                0x7
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_10x5                               0x8
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_10x6                               0x9
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_10x8                               0xA
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_10x10                              0xB
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_12x10                              0xC
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD2_12x12                              0xD


#define MWV207REG_TX_ASTC0_EX_SRGB_LOD2                                    20:20
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD2_End                                   20
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD2_Start                                 20
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD2_Type                                 U01
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD2_DISABLE                            0x0
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD2_ENABLE                             0x1


#define MWV207REG_TX_ASTC0_EX_SIZE_LOD3                                    27:24
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD3_End                                   27
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD3_Start                                 24
#define MWV207REG_TX_ASTC0_EX_SIZE_LOD3_Type                                 U04
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_4x4                                0x0
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_5x4                                0x1
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_5x5                                0x2
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_6x5                                0x3
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_6x6                                0x4
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_8x5                                0x5
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_8x6                                0x6
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_8x8                                0x7
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_10x5                               0x8
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_10x6                               0x9
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_10x8                               0xA
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_10x10                              0xB
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_12x10                              0xC
#define   MWV207REG_TX_ASTC0_EX_SIZE_LOD3_12x12                              0xD


#define MWV207REG_TX_ASTC0_EX_SRGB_LOD3                                    28:28
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD3_End                                   28
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD3_Start                                 28
#define MWV207REG_TX_ASTC0_EX_SRGB_LOD3_Type                                 U01
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD3_DISABLE                            0x0
#define   MWV207REG_TX_ASTC0_EX_SRGB_LOD3_ENABLE                             0x1




#define mwv207regTxASTC1ExRegAddrs                                        0x4160
#define MWV207REG_TX_ASTC1_EX_Address                                    0x10580
#define MWV207REG_TX_ASTC1_EX_MSB                                             15
#define MWV207REG_TX_ASTC1_EX_LSB                                              5
#define MWV207REG_TX_ASTC1_EX_BLK                                              0
#define MWV207REG_TX_ASTC1_EX_Count                                           32
#define MWV207REG_TX_ASTC1_EX_FieldMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC1_EX_ReadMask                                0x1F1F1F1F
#define MWV207REG_TX_ASTC1_EX_WriteMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC1_EX_ResetValue                              0x00000000


#define MWV207REG_TX_ASTC1_EX_SIZE_LOD4                                      3:0
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD4_End                                    3
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD4_Start                                  0
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD4_Type                                 U04
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_4x4                                0x0
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_5x4                                0x1
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_5x5                                0x2
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_6x5                                0x3
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_6x6                                0x4
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_8x5                                0x5
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_8x6                                0x6
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_8x8                                0x7
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_10x5                               0x8
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_10x6                               0x9
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_10x8                               0xA
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_10x10                              0xB
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_12x10                              0xC
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD4_12x12                              0xD


#define MWV207REG_TX_ASTC1_EX_SRGB_LOD4                                      4:4
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD4_End                                    4
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD4_Start                                  4
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD4_Type                                 U01
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD4_DISABLE                            0x0
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD4_ENABLE                             0x1


#define MWV207REG_TX_ASTC1_EX_SIZE_LOD5                                     11:8
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD5_End                                   11
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD5_Start                                  8
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD5_Type                                 U04
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_4x4                                0x0
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_5x4                                0x1
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_5x5                                0x2
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_6x5                                0x3
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_6x6                                0x4
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_8x5                                0x5
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_8x6                                0x6
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_8x8                                0x7
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_10x5                               0x8
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_10x6                               0x9
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_10x8                               0xA
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_10x10                              0xB
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_12x10                              0xC
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD5_12x12                              0xD


#define MWV207REG_TX_ASTC1_EX_SRGB_LOD5                                    12:12
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD5_End                                   12
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD5_Start                                 12
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD5_Type                                 U01
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD5_DISABLE                            0x0
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD5_ENABLE                             0x1


#define MWV207REG_TX_ASTC1_EX_SIZE_LOD6                                    19:16
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD6_End                                   19
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD6_Start                                 16
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD6_Type                                 U04
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_4x4                                0x0
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_5x4                                0x1
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_5x5                                0x2
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_6x5                                0x3
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_6x6                                0x4
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_8x5                                0x5
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_8x6                                0x6
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_8x8                                0x7
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_10x5                               0x8
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_10x6                               0x9
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_10x8                               0xA
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_10x10                              0xB
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_12x10                              0xC
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD6_12x12                              0xD


#define MWV207REG_TX_ASTC1_EX_SRGB_LOD6                                    20:20
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD6_End                                   20
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD6_Start                                 20
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD6_Type                                 U01
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD6_DISABLE                            0x0
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD6_ENABLE                             0x1


#define MWV207REG_TX_ASTC1_EX_SIZE_LOD7                                    27:24
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD7_End                                   27
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD7_Start                                 24
#define MWV207REG_TX_ASTC1_EX_SIZE_LOD7_Type                                 U04
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_4x4                                0x0
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_5x4                                0x1
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_5x5                                0x2
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_6x5                                0x3
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_6x6                                0x4
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_8x5                                0x5
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_8x6                                0x6
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_8x8                                0x7
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_10x5                               0x8
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_10x6                               0x9
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_10x8                               0xA
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_10x10                              0xB
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_12x10                              0xC
#define   MWV207REG_TX_ASTC1_EX_SIZE_LOD7_12x12                              0xD


#define MWV207REG_TX_ASTC1_EX_SRGB_LOD7                                    28:28
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD7_End                                   28
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD7_Start                                 28
#define MWV207REG_TX_ASTC1_EX_SRGB_LOD7_Type                                 U01
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD7_DISABLE                            0x0
#define   MWV207REG_TX_ASTC1_EX_SRGB_LOD7_ENABLE                             0x1




#define mwv207regTxASTC2ExRegAddrs                                        0x4180
#define MWV207REG_TX_ASTC2_EX_Address                                    0x10600
#define MWV207REG_TX_ASTC2_EX_MSB                                             15
#define MWV207REG_TX_ASTC2_EX_LSB                                              5
#define MWV207REG_TX_ASTC2_EX_BLK                                              0
#define MWV207REG_TX_ASTC2_EX_Count                                           32
#define MWV207REG_TX_ASTC2_EX_FieldMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC2_EX_ReadMask                                0x1F1F1F1F
#define MWV207REG_TX_ASTC2_EX_WriteMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC2_EX_ResetValue                              0x00000000


#define MWV207REG_TX_ASTC2_EX_SIZE_LOD8                                      3:0
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD8_End                                    3
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD8_Start                                  0
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD8_Type                                 U04
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_4x4                                0x0
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_5x4                                0x1
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_5x5                                0x2
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_6x5                                0x3
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_6x6                                0x4
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_8x5                                0x5
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_8x6                                0x6
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_8x8                                0x7
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_10x5                               0x8
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_10x6                               0x9
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_10x8                               0xA
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_10x10                              0xB
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_12x10                              0xC
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD8_12x12                              0xD


#define MWV207REG_TX_ASTC2_EX_SRGB_LOD8                                      4:4
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD8_End                                    4
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD8_Start                                  4
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD8_Type                                 U01
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD8_DISABLE                            0x0
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD8_ENABLE                             0x1


#define MWV207REG_TX_ASTC2_EX_SIZE_LOD9                                     11:8
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD9_End                                   11
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD9_Start                                  8
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD9_Type                                 U04
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_4x4                                0x0
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_5x4                                0x1
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_5x5                                0x2
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_6x5                                0x3
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_6x6                                0x4
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_8x5                                0x5
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_8x6                                0x6
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_8x8                                0x7
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_10x5                               0x8
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_10x6                               0x9
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_10x8                               0xA
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_10x10                              0xB
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_12x10                              0xC
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD9_12x12                              0xD


#define MWV207REG_TX_ASTC2_EX_SRGB_LOD9                                    12:12
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD9_End                                   12
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD9_Start                                 12
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD9_Type                                 U01
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD9_DISABLE                            0x0
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD9_ENABLE                             0x1


#define MWV207REG_TX_ASTC2_EX_SIZE_LOD10                                   19:16
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD10_End                                  19
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD10_Start                                16
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD10_Type                                U04
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_4x4                               0x0
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_5x4                               0x1
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_5x5                               0x2
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_6x5                               0x3
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_6x6                               0x4
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_8x5                               0x5
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_8x6                               0x6
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_8x8                               0x7
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_10x5                              0x8
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_10x6                              0x9
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_10x8                              0xA
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_10x10                             0xB
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_12x10                             0xC
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD10_12x12                             0xD


#define MWV207REG_TX_ASTC2_EX_SRGB_LOD10                                   20:20
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD10_End                                  20
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD10_Start                                20
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD10_Type                                U01
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD10_DISABLE                           0x0
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD10_ENABLE                            0x1


#define MWV207REG_TX_ASTC2_EX_SIZE_LOD11                                   27:24
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD11_End                                  27
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD11_Start                                24
#define MWV207REG_TX_ASTC2_EX_SIZE_LOD11_Type                                U04
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_4x4                               0x0
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_5x4                               0x1
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_5x5                               0x2
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_6x5                               0x3
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_6x6                               0x4
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_8x5                               0x5
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_8x6                               0x6
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_8x8                               0x7
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_10x5                              0x8
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_10x6                              0x9
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_10x8                              0xA
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_10x10                             0xB
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_12x10                             0xC
#define   MWV207REG_TX_ASTC2_EX_SIZE_LOD11_12x12                             0xD


#define MWV207REG_TX_ASTC2_EX_SRGB_LOD11                                   28:28
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD11_End                                  28
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD11_Start                                28
#define MWV207REG_TX_ASTC2_EX_SRGB_LOD11_Type                                U01
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD11_DISABLE                           0x0
#define   MWV207REG_TX_ASTC2_EX_SRGB_LOD11_ENABLE                            0x1




#define mwv207regTxASTC3ExRegAddrs                                        0x41A0
#define MWV207REG_TX_ASTC3_EX_Address                                    0x10680
#define MWV207REG_TX_ASTC3_EX_MSB                                             15
#define MWV207REG_TX_ASTC3_EX_LSB                                              5
#define MWV207REG_TX_ASTC3_EX_BLK                                              0
#define MWV207REG_TX_ASTC3_EX_Count                                           32
#define MWV207REG_TX_ASTC3_EX_FieldMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC3_EX_ReadMask                                0x1F1F1F1F
#define MWV207REG_TX_ASTC3_EX_WriteMask                               0x1F1F1F1F
#define MWV207REG_TX_ASTC3_EX_ResetValue                              0x00000000


#define MWV207REG_TX_ASTC3_EX_SIZE_LOD12                                     3:0
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD12_End                                   3
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD12_Start                                 0
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD12_Type                                U04
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_4x4                               0x0
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_5x4                               0x1
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_5x5                               0x2
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_6x5                               0x3
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_6x6                               0x4
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_8x5                               0x5
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_8x6                               0x6
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_8x8                               0x7
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_10x5                              0x8
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_10x6                              0x9
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_10x8                              0xA
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_10x10                             0xB
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_12x10                             0xC
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD12_12x12                             0xD


#define MWV207REG_TX_ASTC3_EX_SRGB_LOD12                                     4:4
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD12_End                                   4
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD12_Start                                 4
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD12_Type                                U01
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD12_DISABLE                           0x0
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD12_ENABLE                            0x1


#define MWV207REG_TX_ASTC3_EX_SIZE_LOD13                                    11:8
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD13_End                                  11
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD13_Start                                 8
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD13_Type                                U04
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_4x4                               0x0
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_5x4                               0x1
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_5x5                               0x2
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_6x5                               0x3
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_6x6                               0x4
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_8x5                               0x5
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_8x6                               0x6
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_8x8                               0x7
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_10x5                              0x8
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_10x6                              0x9
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_10x8                              0xA
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_10x10                             0xB
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_12x10                             0xC
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD13_12x12                             0xD


#define MWV207REG_TX_ASTC3_EX_SRGB_LOD13                                   12:12
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD13_End                                  12
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD13_Start                                12
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD13_Type                                U01
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD13_DISABLE                           0x0
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD13_ENABLE                            0x1


#define MWV207REG_TX_ASTC3_EX_SIZE_LOD14                                   19:16
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD14_End                                  19
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD14_Start                                16
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD14_Type                                U04
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_4x4                               0x0
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_5x4                               0x1
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_5x5                               0x2
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_6x5                               0x3
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_6x6                               0x4
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_8x5                               0x5
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_8x6                               0x6
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_8x8                               0x7
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_10x5                              0x8
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_10x6                              0x9
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_10x8                              0xA
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_10x10                             0xB
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_12x10                             0xC
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD14_12x12                             0xD


#define MWV207REG_TX_ASTC3_EX_SRGB_LOD14                                   20:20
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD14_End                                  20
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD14_Start                                20
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD14_Type                                U01
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD14_DISABLE                           0x0
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD14_ENABLE                            0x1


#define MWV207REG_TX_ASTC3_EX_SIZE_LOD15                                   27:24
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD15_End                                  27
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD15_Start                                24
#define MWV207REG_TX_ASTC3_EX_SIZE_LOD15_Type                                U04
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_4x4                               0x0
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_5x4                               0x1
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_5x5                               0x2
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_6x5                               0x3
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_6x6                               0x4
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_8x5                               0x5
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_8x6                               0x6
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_8x8                               0x7
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_10x5                              0x8
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_10x6                              0x9
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_10x8                              0xA
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_10x10                             0xB
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_12x10                             0xC
#define   MWV207REG_TX_ASTC3_EX_SIZE_LOD15_12x12                             0xD


#define MWV207REG_TX_ASTC3_EX_SRGB_LOD15                                   28:28
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD15_End                                  28
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD15_Start                                28
#define MWV207REG_TX_ASTC3_EX_SRGB_LOD15_Type                                U01
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD15_DISABLE                           0x0
#define   MWV207REG_TX_ASTC3_EX_SRGB_LOD15_ENABLE                            0x1




#define mwv207regTXBaseLODRegAddrs                                        0x41C0
#define MWV207REG_TX_BASE_LOD_Address                                    0x10700
#define MWV207REG_TX_BASE_LOD_MSB                                             15
#define MWV207REG_TX_BASE_LOD_LSB                                              5
#define MWV207REG_TX_BASE_LOD_BLK                                              0
#define MWV207REG_TX_BASE_LOD_Count                                           32
#define MWV207REG_TX_BASE_LOD_FieldMask                               0x01F10F0F
#define MWV207REG_TX_BASE_LOD_ReadMask                                0x01F10F0F
#define MWV207REG_TX_BASE_LOD_WriteMask                               0x01F10F0F
#define MWV207REG_TX_BASE_LOD_ResetValue                              0x00000F00


#define MWV207REG_TX_BASE_LOD_BASE_LEVEL                                     3:0
#define MWV207REG_TX_BASE_LOD_BASE_LEVEL_End                                   3
#define MWV207REG_TX_BASE_LOD_BASE_LEVEL_Start                                 0
#define MWV207REG_TX_BASE_LOD_BASE_LEVEL_Type                                U04


#define MWV207REG_TX_BASE_LOD_MAX_LEVEL                                     11:8
#define MWV207REG_TX_BASE_LOD_MAX_LEVEL_End                                   11
#define MWV207REG_TX_BASE_LOD_MAX_LEVEL_Start                                  8
#define MWV207REG_TX_BASE_LOD_MAX_LEVEL_Type                                 U04


#define MWV207REG_TX_BASE_LOD_COMPARE_MODE                                 16:16
#define MWV207REG_TX_BASE_LOD_COMPARE_MODE_End                                16
#define MWV207REG_TX_BASE_LOD_COMPARE_MODE_Start                              16
#define MWV207REG_TX_BASE_LOD_COMPARE_MODE_Type                              U01

#define   MWV207REG_TX_BASE_LOD_COMPARE_MODE_NONE                            0x0

#define   MWV207REG_TX_BASE_LOD_COMPARE_MODE_REFERENCE                       0x1


#define MWV207REG_TX_BASE_LOD_COMPARE_FUNC                                 22:20
#define MWV207REG_TX_BASE_LOD_COMPARE_FUNC_End                                22
#define MWV207REG_TX_BASE_LOD_COMPARE_FUNC_Start                              20
#define MWV207REG_TX_BASE_LOD_COMPARE_FUNC_Type                              U03
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_LEQUAL                          0x0
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_GEQUAL                          0x1
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_LESS                            0x2
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_GREATER                         0x3
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_EQUAL                           0x4
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_NOT_EQUAL                       0x5
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_ALWAYS                          0x6
#define   MWV207REG_TX_BASE_LOD_COMPARE_FUNC_NEVER                           0x7


#define MWV207REG_TX_BASE_LOD_CALCULATION_MODE                             24:23
#define MWV207REG_TX_BASE_LOD_CALCULATION_MODE_End                            24
#define MWV207REG_TX_BASE_LOD_CALCULATION_MODE_Start                          23
#define MWV207REG_TX_BASE_LOD_CALCULATION_MODE_Type                          U02
#define   MWV207REG_TX_BASE_LOD_CALCULATION_MODE_D3D_ES20                    0x0
#define   MWV207REG_TX_BASE_LOD_CALCULATION_MODE_ES30                        0x1

#define mwv207regTXConfig2RegAddrs                                        0x41E0
#define MWV207REG_TX_CONFIG2_Address                                     0x10780
#define MWV207REG_TX_CONFIG2_MSB                                              15
#define MWV207REG_TX_CONFIG2_LSB                                               5
#define MWV207REG_TX_CONFIG2_BLK                                               0
#define MWV207REG_TX_CONFIG2_Count                                            32
#define MWV207REG_TX_CONFIG2_FieldMask                                0xF39F3333
#define MWV207REG_TX_CONFIG2_ReadMask                                 0xF39F3333
#define MWV207REG_TX_CONFIG2_WriteMask                                0xF39F3333
#define MWV207REG_TX_CONFIG2_ResetValue                               0x00030000


#define MWV207REG_TX_CONFIG2_NORM_RED                                        1:0
#define MWV207REG_TX_CONFIG2_NORM_RED_End                                      1
#define MWV207REG_TX_CONFIG2_NORM_RED_Start                                    0
#define MWV207REG_TX_CONFIG2_NORM_RED_Type                                   U02
#define   MWV207REG_TX_CONFIG2_NORM_RED_DISABLE                              0x0
#define   MWV207REG_TX_CONFIG2_NORM_RED_UNSIGNED                             0x1
#define   MWV207REG_TX_CONFIG2_NORM_RED_SIGNED                               0x2


#define MWV207REG_TX_CONFIG2_NORM_GREEN                                      5:4
#define MWV207REG_TX_CONFIG2_NORM_GREEN_End                                    5
#define MWV207REG_TX_CONFIG2_NORM_GREEN_Start                                  4
#define MWV207REG_TX_CONFIG2_NORM_GREEN_Type                                 U02
#define   MWV207REG_TX_CONFIG2_NORM_GREEN_DISABLE                            0x0
#define   MWV207REG_TX_CONFIG2_NORM_GREEN_UNSIGNED                           0x1
#define   MWV207REG_TX_CONFIG2_NORM_GREEN_SIGNED                             0x2


#define MWV207REG_TX_CONFIG2_NORM_BLUE                                       9:8
#define MWV207REG_TX_CONFIG2_NORM_BLUE_End                                     9
#define MWV207REG_TX_CONFIG2_NORM_BLUE_Start                                   8
#define MWV207REG_TX_CONFIG2_NORM_BLUE_Type                                  U02
#define   MWV207REG_TX_CONFIG2_NORM_BLUE_DISABLE                             0x0
#define   MWV207REG_TX_CONFIG2_NORM_BLUE_UNSIGNED                            0x1
#define   MWV207REG_TX_CONFIG2_NORM_BLUE_SIGNED                              0x2


#define MWV207REG_TX_CONFIG2_NORM_ALPHA                                    13:12
#define MWV207REG_TX_CONFIG2_NORM_ALPHA_End                                   13
#define MWV207REG_TX_CONFIG2_NORM_ALPHA_Start                                 12
#define MWV207REG_TX_CONFIG2_NORM_ALPHA_Type                                 U02
#define   MWV207REG_TX_CONFIG2_NORM_ALPHA_DISABLE                            0x0
#define   MWV207REG_TX_CONFIG2_NORM_ALPHA_UNSIGNED                           0x1
#define   MWV207REG_TX_CONFIG2_NORM_ALPHA_SIGNED                             0x2


#define MWV207REG_TX_CONFIG2_TX_FILTER_CLAMP                               16:16
#define MWV207REG_TX_CONFIG2_TX_FILTER_CLAMP_End                              16
#define MWV207REG_TX_CONFIG2_TX_FILTER_CLAMP_Start                            16
#define MWV207REG_TX_CONFIG2_TX_FILTER_CLAMP_Type                            U01
#define   MWV207REG_TX_CONFIG2_TX_FILTER_CLAMP_ENABLE                        0x0
#define   MWV207REG_TX_CONFIG2_TX_FILTER_CLAMP_DISABLE                       0x1


#define MWV207REG_TX_CONFIG2_TX_COLOR_CLAMP                                17:17
#define MWV207REG_TX_CONFIG2_TX_COLOR_CLAMP_End                               17
#define MWV207REG_TX_CONFIG2_TX_COLOR_CLAMP_Start                             17
#define MWV207REG_TX_CONFIG2_TX_COLOR_CLAMP_Type                             U01
#define   MWV207REG_TX_CONFIG2_TX_COLOR_CLAMP_ENABLE                         0x0
#define   MWV207REG_TX_CONFIG2_TX_COLOR_CLAMP_DISABLE                        0x1


#define MWV207REG_TX_CONFIG2_INTEGER_SIGN_EXTENSION                        19:18
#define MWV207REG_TX_CONFIG2_INTEGER_SIGN_EXTENSION_End                       19
#define MWV207REG_TX_CONFIG2_INTEGER_SIGN_EXTENSION_Start                     18
#define MWV207REG_TX_CONFIG2_INTEGER_SIGN_EXTENSION_Type                     U02

#define   MWV207REG_TX_CONFIG2_INTEGER_SIGN_EXTENSION_NONE                   0x0

#define   MWV207REG_TX_CONFIG2_INTEGER_SIGN_EXTENSION_SIGNED8                0x1

#define   MWV207REG_TX_CONFIG2_INTEGER_SIGN_EXTENSION_SIGNED16               0x2


#define MWV207REG_TX_CONFIG2_GUARDBAND_ENABLE                              20:20
#define MWV207REG_TX_CONFIG2_GUARDBAND_ENABLE_End                             20
#define MWV207REG_TX_CONFIG2_GUARDBAND_ENABLE_Start                           20
#define MWV207REG_TX_CONFIG2_GUARDBAND_ENABLE_Type                           U01
#define   MWV207REG_TX_CONFIG2_GUARDBAND_ENABLE_DISABLE                      0x0
#define   MWV207REG_TX_CONFIG2_GUARDBAND_ENABLE_ENABLE                       0x1


#define MWV207REG_TX_CONFIG2_TX128_BYTE_REQUEST                            23:23
#define MWV207REG_TX_CONFIG2_TX128_BYTE_REQUEST_End                           23
#define MWV207REG_TX_CONFIG2_TX128_BYTE_REQUEST_Start                         23
#define MWV207REG_TX_CONFIG2_TX128_BYTE_REQUEST_Type                         U01
#define   MWV207REG_TX_CONFIG2_TX128_BYTE_REQUEST_DISABLE                    0x0
#define   MWV207REG_TX_CONFIG2_TX128_BYTE_REQUEST_ENABLE                     0x1


#define MWV207REG_TX_CONFIG2_GUARDBAND_INDEX                               25:24
#define MWV207REG_TX_CONFIG2_GUARDBAND_INDEX_End                              25
#define MWV207REG_TX_CONFIG2_GUARDBAND_INDEX_Start                            24
#define MWV207REG_TX_CONFIG2_GUARDBAND_INDEX_Type                            U02


#define MWV207REG_TX_CONFIG2_TILE_STATUS_CLIENT                            30:28
#define MWV207REG_TX_CONFIG2_TILE_STATUS_CLIENT_End                           30
#define MWV207REG_TX_CONFIG2_TILE_STATUS_CLIENT_Start                         28
#define MWV207REG_TX_CONFIG2_TILE_STATUS_CLIENT_Type                         U03


#define MWV207REG_TX_CONFIG2_COMPRESSION_DEC                               31:31
#define MWV207REG_TX_CONFIG2_COMPRESSION_DEC_End                              31
#define MWV207REG_TX_CONFIG2_COMPRESSION_DEC_Start                            31
#define MWV207REG_TX_CONFIG2_COMPRESSION_DEC_Type                            U01
#define   MWV207REG_TX_CONFIG2_COMPRESSION_DEC_DISABLE                       0x0
#define   MWV207REG_TX_CONFIG2_COMPRESSION_DEC_ENABLE                        0x1

#define mwv207regTXSizeExtRegAddrs                                        0x4400
#define MWV207REG_TX_SIZE_EXT_Address                                    0x11000
#define MWV207REG_TX_SIZE_EXT_MSB                                             15
#define MWV207REG_TX_SIZE_EXT_LSB                                              5
#define MWV207REG_TX_SIZE_EXT_BLK                                              0
#define MWV207REG_TX_SIZE_EXT_Count                                           32
#define MWV207REG_TX_SIZE_EXT_FieldMask                               0xFFFFFFFF
#define MWV207REG_TX_SIZE_EXT_ReadMask                                0xFFFFFFFF
#define MWV207REG_TX_SIZE_EXT_WriteMask                               0xFFFFFFFF
#define MWV207REG_TX_SIZE_EXT_ResetValue                              0x00000000


#define MWV207REG_TX_SIZE_EXT_LOG_WIDTH                                     15:0
#define MWV207REG_TX_SIZE_EXT_LOG_WIDTH_End                                   15
#define MWV207REG_TX_SIZE_EXT_LOG_WIDTH_Start                                  0
#define MWV207REG_TX_SIZE_EXT_LOG_WIDTH_Type                                 U16


#define MWV207REG_TX_SIZE_EXT_LOG_HEIGHT                                   31:16
#define MWV207REG_TX_SIZE_EXT_LOG_HEIGHT_End                                  31
#define MWV207REG_TX_SIZE_EXT_LOG_HEIGHT_Start                                16
#define MWV207REG_TX_SIZE_EXT_LOG_HEIGHT_Type                                U16

#define mwv207regTXVolumeExtRegAddrs                                      0x4420
#define MWV207REG_TX_VOLUME_EXT_Address                                  0x11080
#define MWV207REG_TX_VOLUME_EXT_MSB                                           15
#define MWV207REG_TX_VOLUME_EXT_LSB                                            5
#define MWV207REG_TX_VOLUME_EXT_BLK                                            0
#define MWV207REG_TX_VOLUME_EXT_Count                                         32
#define MWV207REG_TX_VOLUME_EXT_FieldMask                             0x0000FFFF
#define MWV207REG_TX_VOLUME_EXT_ReadMask                              0x0000FFFF
#define MWV207REG_TX_VOLUME_EXT_WriteMask                             0x0000FFFF
#define MWV207REG_TX_VOLUME_EXT_ResetValue                            0x00000000


#define MWV207REG_TX_VOLUME_EXT_LOG_DEPTH                                   15:0
#define MWV207REG_TX_VOLUME_EXT_LOG_DEPTH_End                                 15
#define MWV207REG_TX_VOLUME_EXT_LOG_DEPTH_Start                                0
#define MWV207REG_TX_VOLUME_EXT_LOG_DEPTH_Type                               U16

#define mwv207regTXLodExtRegAddrs                                         0x4440
#define MWV207REG_TX_LOD_EXT_Address                                     0x11100
#define MWV207REG_TX_LOD_EXT_MSB                                              15
#define MWV207REG_TX_LOD_EXT_LSB                                               5
#define MWV207REG_TX_LOD_EXT_BLK                                               0
#define MWV207REG_TX_LOD_EXT_Count                                            32
#define MWV207REG_TX_LOD_EXT_FieldMask                                0x1FFF1FFF
#define MWV207REG_TX_LOD_EXT_ReadMask                                 0x1FFF1FFF
#define MWV207REG_TX_LOD_EXT_WriteMask                                0x1FFF1FFF
#define MWV207REG_TX_LOD_EXT_ResetValue                               0x00000000


#define MWV207REG_TX_LOD_EXT_MAX_LOD                                        12:0
#define MWV207REG_TX_LOD_EXT_MAX_LOD_End                                      12
#define MWV207REG_TX_LOD_EXT_MAX_LOD_Start                                     0
#define MWV207REG_TX_LOD_EXT_MAX_LOD_Type                                    U13


#define MWV207REG_TX_LOD_EXT_MIN_LOD                                       28:16
#define MWV207REG_TX_LOD_EXT_MIN_LOD_End                                      28
#define MWV207REG_TX_LOD_EXT_MIN_LOD_Start                                    16
#define MWV207REG_TX_LOD_EXT_MIN_LOD_Type                                    U13

#define mwv207regTXLodBiasExtRegAddrs                                     0x4460
#define MWV207REG_TX_LOD_BIAS_EXT_Address                                0x11180
#define MWV207REG_TX_LOD_BIAS_EXT_MSB                                         15
#define MWV207REG_TX_LOD_BIAS_EXT_LSB                                          5
#define MWV207REG_TX_LOD_BIAS_EXT_BLK                                          0
#define MWV207REG_TX_LOD_BIAS_EXT_Count                                       32
#define MWV207REG_TX_LOD_BIAS_EXT_FieldMask                           0x0001FFFF
#define MWV207REG_TX_LOD_BIAS_EXT_ReadMask                            0x0001FFFF
#define MWV207REG_TX_LOD_BIAS_EXT_WriteMask                           0x0001FFFF
#define MWV207REG_TX_LOD_BIAS_EXT_ResetValue                          0x00000000


#define MWV207REG_TX_LOD_BIAS_EXT_BIAS_LOD                                  15:0
#define MWV207REG_TX_LOD_BIAS_EXT_BIAS_LOD_End                                15
#define MWV207REG_TX_LOD_BIAS_EXT_BIAS_LOD_Start                               0
#define MWV207REG_TX_LOD_BIAS_EXT_BIAS_LOD_Type                              U16


#define MWV207REG_TX_LOD_BIAS_EXT_ENABLE_BIAS_LOD                          16:16
#define MWV207REG_TX_LOD_BIAS_EXT_ENABLE_BIAS_LOD_End                         16
#define MWV207REG_TX_LOD_BIAS_EXT_ENABLE_BIAS_LOD_Start                       16
#define MWV207REG_TX_LOD_BIAS_EXT_ENABLE_BIAS_LOD_Type                       U01




#define mwv207regTXSliceRegAddrs                                          0x4480
#define MWV207REG_TX_SLICE_Address                                       0x11200
#define MWV207REG_TX_SLICE_MSB                                                15
#define MWV207REG_TX_SLICE_LSB                                                 5
#define MWV207REG_TX_SLICE_BLK                                                 0
#define MWV207REG_TX_SLICE_Count                                              32
#define MWV207REG_TX_SLICE_FieldMask                                  0xFFFFFFFF
#define MWV207REG_TX_SLICE_ReadMask                                   0xFFFFFFFF
#define MWV207REG_TX_SLICE_WriteMask                                  0xFFFFFFFF
#define MWV207REG_TX_SLICE_ResetValue                                 0x00000000


#define MWV207REG_TX_SLICE_SLICE_SIZE                                       31:0
#define MWV207REG_TX_SLICE_SLICE_SIZE_End                                     31
#define MWV207REG_TX_SLICE_SLICE_SIZE_Start                                    0
#define MWV207REG_TX_SLICE_SLICE_SIZE_Type                                   U32

#define mwv207regTXConfig3RegAddrs                                        0x44A0
#define MWV207REG_TX_CONFIG3_Address                                     0x11280
#define MWV207REG_TX_CONFIG3_MSB                                              15
#define MWV207REG_TX_CONFIG3_LSB                                               5
#define MWV207REG_TX_CONFIG3_BLK                                               0
#define MWV207REG_TX_CONFIG3_Count                                            32
#define MWV207REG_TX_CONFIG3_FieldMask                                0x00077719
#define MWV207REG_TX_CONFIG3_ReadMask                                 0x00077719
#define MWV207REG_TX_CONFIG3_WriteMask                                0x00077719
#define MWV207REG_TX_CONFIG3_ResetValue                               0x00000000

#define MWV207REG_TX_CONFIG3_DEPTH_STENCIL_TEXTURE_MODE                      0:0
#define MWV207REG_TX_CONFIG3_DEPTH_STENCIL_TEXTURE_MODE_End                    0
#define MWV207REG_TX_CONFIG3_DEPTH_STENCIL_TEXTURE_MODE_Start                  0
#define MWV207REG_TX_CONFIG3_DEPTH_STENCIL_TEXTURE_MODE_Type                 U01
#define   MWV207REG_TX_CONFIG3_DEPTH_STENCIL_TEXTURE_MODE_DEPTH_COMPONENT    0x0
#define   MWV207REG_TX_CONFIG3_DEPTH_STENCIL_TEXTURE_MODE_STENCIL_INDEX      0x1

#define MWV207REG_TX_CONFIG3_USE_STRIDE                                      3:3
#define MWV207REG_TX_CONFIG3_USE_STRIDE_End                                    3
#define MWV207REG_TX_CONFIG3_USE_STRIDE_Start                                  3
#define MWV207REG_TX_CONFIG3_USE_STRIDE_Type                                 U01
#define   MWV207REG_TX_CONFIG3_USE_STRIDE_DISABLE                            0x0
#define   MWV207REG_TX_CONFIG3_USE_STRIDE_ENABLE                             0x1


#define MWV207REG_TX_CONFIG3_ENABLE_NEW_MODE                                 4:4
#define MWV207REG_TX_CONFIG3_ENABLE_NEW_MODE_End                               4
#define MWV207REG_TX_CONFIG3_ENABLE_NEW_MODE_Start                             4
#define MWV207REG_TX_CONFIG3_ENABLE_NEW_MODE_Type                            U01

#define   MWV207REG_TX_CONFIG3_ENABLE_NEW_MODE_DISABLE                       0x0

#define   MWV207REG_TX_CONFIG3_ENABLE_NEW_MODE_ENABLE                        0x1


#define MWV207REG_TX_CONFIG3_UMODE                                          10:8
#define MWV207REG_TX_CONFIG3_UMODE_End                                        10
#define MWV207REG_TX_CONFIG3_UMODE_Start                                       8
#define MWV207REG_TX_CONFIG3_UMODE_Type                                      U03
#define   MWV207REG_TX_CONFIG3_UMODE_WRAP                                    0x0
#define   MWV207REG_TX_CONFIG3_UMODE_MIRROR                                  0x1
#define   MWV207REG_TX_CONFIG3_UMODE_CLAMP                                   0x2
#define   MWV207REG_TX_CONFIG3_UMODE_BORDER                                  0x3
#define   MWV207REG_TX_CONFIG3_UMODE_MIRROR_ONCE                             0x4
#define   MWV207REG_TX_CONFIG3_UMODE_MIRROR_CLAMP2_EDGE                      0x5


#define MWV207REG_TX_CONFIG3_VMODE                                         14:12
#define MWV207REG_TX_CONFIG3_VMODE_End                                        14
#define MWV207REG_TX_CONFIG3_VMODE_Start                                      12
#define MWV207REG_TX_CONFIG3_VMODE_Type                                      U03
#define   MWV207REG_TX_CONFIG3_VMODE_WRAP                                    0x0
#define   MWV207REG_TX_CONFIG3_VMODE_MIRROR                                  0x1
#define   MWV207REG_TX_CONFIG3_VMODE_CLAMP                                   0x2
#define   MWV207REG_TX_CONFIG3_VMODE_BORDER                                  0x3
#define   MWV207REG_TX_CONFIG3_VMODE_MIRROR_ONCE                             0x4
#define   MWV207REG_TX_CONFIG3_VMODE_MIRROR_CLAMP2_EDGE                      0x5


#define MWV207REG_TX_CONFIG3_WMODE                                         18:16
#define MWV207REG_TX_CONFIG3_WMODE_End                                        18
#define MWV207REG_TX_CONFIG3_WMODE_Start                                      16
#define MWV207REG_TX_CONFIG3_WMODE_Type                                      U03
#define   MWV207REG_TX_CONFIG3_WMODE_WRAP                                    0x0
#define   MWV207REG_TX_CONFIG3_WMODE_MIRROR                                  0x1
#define   MWV207REG_TX_CONFIG3_WMODE_CLAMP                                   0x2
#define   MWV207REG_TX_CONFIG3_WMODE_BORDER                                  0x3
#define   MWV207REG_TX_CONFIG3_WMODE_MIRROR_ONCE                             0x4
#define   MWV207REG_TX_CONFIG3_WMODE_MIRROR_CLAMP2_EDGE                      0x5

#define mwv207regTXAnisoCtrlRegAddrs                                      0x44C0
#define MWV207REG_TX_ANISO_CTRL_Address                                  0x11300
#define MWV207REG_TX_ANISO_CTRL_MSB                                           15
#define MWV207REG_TX_ANISO_CTRL_LSB                                            5
#define MWV207REG_TX_ANISO_CTRL_BLK                                            0
#define MWV207REG_TX_ANISO_CTRL_Count                                         32
#define MWV207REG_TX_ANISO_CTRL_FieldMask                             0x000007FF
#define MWV207REG_TX_ANISO_CTRL_ReadMask                              0x000007FF
#define MWV207REG_TX_ANISO_CTRL_WriteMask                             0x000007FF
#define MWV207REG_TX_ANISO_CTRL_ResetValue                            0x00000000


#define MWV207REG_TX_ANISO_CTRL_ANISO_MAX_LOG                               10:0
#define MWV207REG_TX_ANISO_CTRL_ANISO_MAX_LOG_End                             10
#define MWV207REG_TX_ANISO_CTRL_ANISO_MAX_LOG_Start                            0
#define MWV207REG_TX_ANISO_CTRL_ANISO_MAX_LOG_Type                           U11




#define mwv207regTXBorderColorRed32RegAddrs                               0x44E0
#define MWV207REG_TX_BORDER_COLOR_RED32_Address                          0x11380
#define MWV207REG_TX_BORDER_COLOR_RED32_MSB                                   15
#define MWV207REG_TX_BORDER_COLOR_RED32_LSB                                    5
#define MWV207REG_TX_BORDER_COLOR_RED32_BLK                                    0
#define MWV207REG_TX_BORDER_COLOR_RED32_Count                                 32
#define MWV207REG_TX_BORDER_COLOR_RED32_FieldMask                     0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_RED32_ReadMask                      0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_RED32_WriteMask                     0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_RED32_ResetValue                    0x00000000


#define MWV207REG_TX_BORDER_COLOR_RED32_RED                                 31:0
#define MWV207REG_TX_BORDER_COLOR_RED32_RED_End                               31
#define MWV207REG_TX_BORDER_COLOR_RED32_RED_Start                              0
#define MWV207REG_TX_BORDER_COLOR_RED32_RED_Type                             U32




#define mwv207regTXBorderColorGreen32RegAddrs                             0x4500
#define MWV207REG_TX_BORDER_COLOR_GREEN32_Address                        0x11400
#define MWV207REG_TX_BORDER_COLOR_GREEN32_MSB                                 15
#define MWV207REG_TX_BORDER_COLOR_GREEN32_LSB                                  5
#define MWV207REG_TX_BORDER_COLOR_GREEN32_BLK                                  0
#define MWV207REG_TX_BORDER_COLOR_GREEN32_Count                               32
#define MWV207REG_TX_BORDER_COLOR_GREEN32_FieldMask                   0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_GREEN32_ReadMask                    0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_GREEN32_WriteMask                   0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_GREEN32_ResetValue                  0x00000000


#define MWV207REG_TX_BORDER_COLOR_GREEN32_GREEN                             31:0
#define MWV207REG_TX_BORDER_COLOR_GREEN32_GREEN_End                           31
#define MWV207REG_TX_BORDER_COLOR_GREEN32_GREEN_Start                          0
#define MWV207REG_TX_BORDER_COLOR_GREEN32_GREEN_Type                         U32




#define mwv207regTXBorderColorBlue32RegAddrs                              0x4520
#define MWV207REG_TX_BORDER_COLOR_BLUE32_Address                         0x11480
#define MWV207REG_TX_BORDER_COLOR_BLUE32_MSB                                  15
#define MWV207REG_TX_BORDER_COLOR_BLUE32_LSB                                   5
#define MWV207REG_TX_BORDER_COLOR_BLUE32_BLK                                   0
#define MWV207REG_TX_BORDER_COLOR_BLUE32_Count                                32
#define MWV207REG_TX_BORDER_COLOR_BLUE32_FieldMask                    0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_BLUE32_ReadMask                     0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_BLUE32_WriteMask                    0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_BLUE32_ResetValue                   0x00000000


#define MWV207REG_TX_BORDER_COLOR_BLUE32_BLUE                               31:0
#define MWV207REG_TX_BORDER_COLOR_BLUE32_BLUE_End                             31
#define MWV207REG_TX_BORDER_COLOR_BLUE32_BLUE_Start                            0
#define MWV207REG_TX_BORDER_COLOR_BLUE32_BLUE_Type                           U32




#define mwv207regTXBorderColorAlpha32RegAddrs                             0x4540
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_Address                        0x11500
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_MSB                                 15
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_LSB                                  5
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_BLK                                  0
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_Count                               32
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_FieldMask                   0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_ReadMask                    0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_WriteMask                   0xFFFFFFFF
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_ResetValue                  0x00000000


#define MWV207REG_TX_BORDER_COLOR_ALPHA32_ALPHA                             31:0
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_ALPHA_End                           31
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_ALPHA_Start                          0
#define MWV207REG_TX_BORDER_COLOR_ALPHA32_ALPHA_Type                         U32





#define mwv207regTXHorizontalKernelRegAddrs                               0x4800
#define MWV207REG_TX_HORIZONTAL_KERNEL_Address                           0x12000
#define MWV207REG_TX_HORIZONTAL_KERNEL_MSB                                    15
#define MWV207REG_TX_HORIZONTAL_KERNEL_LSB                                     8
#define MWV207REG_TX_HORIZONTAL_KERNEL_BLK                                     8
#define MWV207REG_TX_HORIZONTAL_KERNEL_Count                                 256
#define MWV207REG_TX_HORIZONTAL_KERNEL_FieldMask                      0xFFFFFFFF
#define MWV207REG_TX_HORIZONTAL_KERNEL_ReadMask                       0xFFFFFFFF
#define MWV207REG_TX_HORIZONTAL_KERNEL_WriteMask                      0xFFFFFFFF
#define MWV207REG_TX_HORIZONTAL_KERNEL_ResetValue                     0x00000000


#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE0                                 7:0
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE0_End                               7
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE0_Start                             0
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE0_Type                            U08


#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE1                                15:8
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE1_End                              15
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE1_Start                             8
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE1_Type                            U08


#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE2                               23:16
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE2_End                              23
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE2_Start                            16
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE2_Type                            U08


#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE3                               31:24
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE3_End                              31
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE3_Start                            24
#define MWV207REG_TX_HORIZONTAL_KERNEL_BYTE3_Type                            U08




#define mwv207regTXVerticalKernelRegAddrs                                 0x4900
#define MWV207REG_TX_VERTICAL_KERNEL_Address                             0x12400
#define MWV207REG_TX_VERTICAL_KERNEL_MSB                                      15
#define MWV207REG_TX_VERTICAL_KERNEL_LSB                                       8
#define MWV207REG_TX_VERTICAL_KERNEL_BLK                                       8
#define MWV207REG_TX_VERTICAL_KERNEL_Count                                   256
#define MWV207REG_TX_VERTICAL_KERNEL_FieldMask                        0xFFFFFFFF
#define MWV207REG_TX_VERTICAL_KERNEL_ReadMask                         0xFFFFFFFF
#define MWV207REG_TX_VERTICAL_KERNEL_WriteMask                        0xFFFFFFFF
#define MWV207REG_TX_VERTICAL_KERNEL_ResetValue                       0x00000000


#define MWV207REG_TX_VERTICAL_KERNEL_BYTE0                                   7:0
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE0_End                                 7
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE0_Start                               0
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE0_Type                              U08


#define MWV207REG_TX_VERTICAL_KERNEL_BYTE1                                  15:8
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE1_End                                15
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE1_Start                               8
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE1_Type                              U08


#define MWV207REG_TX_VERTICAL_KERNEL_BYTE2                                 23:16
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE2_End                                23
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE2_Start                              16
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE2_Type                              U08


#define MWV207REG_TX_VERTICAL_KERNEL_BYTE3                                 31:24
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE3_End                                31
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE3_Start                              24
#define MWV207REG_TX_VERTICAL_KERNEL_BYTE3_Type                              U08





#define mwv207regTXGuardbandRegAddrs                                      0x5300
#define MWV207REG_TX_GUARDBAND_Address                                   0x14C00
#define MWV207REG_TX_GUARDBAND_MSB                                            15
#define MWV207REG_TX_GUARDBAND_LSB                                             4
#define MWV207REG_TX_GUARDBAND_BLK                                             4
#define MWV207REG_TX_GUARDBAND_Count                                          16
#define MWV207REG_TX_GUARDBAND_FieldMask                              0x1F1F1F1F
#define MWV207REG_TX_GUARDBAND_ReadMask                               0x1F1F1F1F
#define MWV207REG_TX_GUARDBAND_WriteMask                              0x1F1F1F1F
#define MWV207REG_TX_GUARDBAND_ResetValue                             0x00000000

#define MWV207REG_TX_GUARDBAND_GUARDBAND0                                    4:0
#define MWV207REG_TX_GUARDBAND_GUARDBAND0_End                                  4
#define MWV207REG_TX_GUARDBAND_GUARDBAND0_Start                                0
#define MWV207REG_TX_GUARDBAND_GUARDBAND0_Type                               U05

#define MWV207REG_TX_GUARDBAND_GUARDBAND1                                   12:8
#define MWV207REG_TX_GUARDBAND_GUARDBAND1_End                                 12
#define MWV207REG_TX_GUARDBAND_GUARDBAND1_Start                                8
#define MWV207REG_TX_GUARDBAND_GUARDBAND1_Type                               U05

#define MWV207REG_TX_GUARDBAND_GUARDBAND2                                  20:16
#define MWV207REG_TX_GUARDBAND_GUARDBAND2_End                                 20
#define MWV207REG_TX_GUARDBAND_GUARDBAND2_Start                               16
#define MWV207REG_TX_GUARDBAND_GUARDBAND2_Type                               U05

#define MWV207REG_TX_GUARDBAND_GUARDBAND3                                  28:24
#define MWV207REG_TX_GUARDBAND_GUARDBAND3_End                                 28
#define MWV207REG_TX_GUARDBAND_GUARDBAND3_Start                               24
#define MWV207REG_TX_GUARDBAND_GUARDBAND3_Type                               U05





#define mwv207regTXGlobalConfigRegAddrs                                   0x5310
#define MWV207REG_TX_GLOBAL_CONFIG_Address                               0x14C40
#define MWV207REG_TX_GLOBAL_CONFIG_MSB                                        15
#define MWV207REG_TX_GLOBAL_CONFIG_LSB                                         0
#define MWV207REG_TX_GLOBAL_CONFIG_BLK                                         0
#define MWV207REG_TX_GLOBAL_CONFIG_Count                                       1
#define MWV207REG_TX_GLOBAL_CONFIG_FieldMask                          0x00000001
#define MWV207REG_TX_GLOBAL_CONFIG_ReadMask                           0x00000001
#define MWV207REG_TX_GLOBAL_CONFIG_WriteMask                          0x00000001
#define MWV207REG_TX_GLOBAL_CONFIG_ResetValue                         0x00000000


#define MWV207REG_TX_GLOBAL_CONFIG_TEXTURE_DESCRIPTOR                        0:0
#define MWV207REG_TX_GLOBAL_CONFIG_TEXTURE_DESCRIPTOR_End                      0
#define MWV207REG_TX_GLOBAL_CONFIG_TEXTURE_DESCRIPTOR_Start                    0
#define MWV207REG_TX_GLOBAL_CONFIG_TEXTURE_DESCRIPTOR_Type                   U01
#define   MWV207REG_TX_GLOBAL_CONFIG_TEXTURE_DESCRIPTOR_DISABLE              0x0
#define   MWV207REG_TX_GLOBAL_CONFIG_TEXTURE_DESCRIPTOR_ENABLE               0x1




#define mwv207regTXGpipeCommandRegAddrs                                   0x5311
#define MWV207REG_TX_GPIPE_COMMAND_Address                               0x14C44
#define MWV207REG_TX_GPIPE_COMMAND_MSB                                        15
#define MWV207REG_TX_GPIPE_COMMAND_LSB                                         0
#define MWV207REG_TX_GPIPE_COMMAND_BLK                                         0
#define MWV207REG_TX_GPIPE_COMMAND_Count                                       1
#define MWV207REG_TX_GPIPE_COMMAND_FieldMask                          0xF3FF03FF
#define MWV207REG_TX_GPIPE_COMMAND_ReadMask                           0xF3FF03FF
#define MWV207REG_TX_GPIPE_COMMAND_WriteMask                          0xF3FF03FF
#define MWV207REG_TX_GPIPE_COMMAND_ResetValue                         0x00000000


#define MWV207REG_TX_GPIPE_COMMAND_DATA                                      9:0
#define MWV207REG_TX_GPIPE_COMMAND_DATA_End                                    9
#define MWV207REG_TX_GPIPE_COMMAND_DATA_Start                                  0
#define MWV207REG_TX_GPIPE_COMMAND_DATA_Type                                 U10


#define MWV207REG_TX_GPIPE_COMMAND_NUM                                     25:16
#define MWV207REG_TX_GPIPE_COMMAND_NUM_End                                    25
#define MWV207REG_TX_GPIPE_COMMAND_NUM_Start                                  16
#define MWV207REG_TX_GPIPE_COMMAND_NUM_Type                                  U10


#define MWV207REG_TX_GPIPE_COMMAND_COMMAND                                 31:28
#define MWV207REG_TX_GPIPE_COMMAND_COMMAND_End                                31
#define MWV207REG_TX_GPIPE_COMMAND_COMMAND_Start                              28
#define MWV207REG_TX_GPIPE_COMMAND_COMMAND_Type                              U04
#define   MWV207REG_TX_GPIPE_COMMAND_COMMAND_INVALIDATE_ALL                  0x0
#define   MWV207REG_TX_GPIPE_COMMAND_COMMAND_INVALIDATE_ONE                  0x1
#define   MWV207REG_TX_GPIPE_COMMAND_COMMAND_PREFETCH                        0x2




#define mwv207regTXPixelCommandRegAddrs                                   0x5312
#define MWV207REG_TX_PIXEL_COMMAND_Address                               0x14C48
#define MWV207REG_TX_PIXEL_COMMAND_MSB                                        15
#define MWV207REG_TX_PIXEL_COMMAND_LSB                                         0
#define MWV207REG_TX_PIXEL_COMMAND_BLK                                         0
#define MWV207REG_TX_PIXEL_COMMAND_Count                                       1
#define MWV207REG_TX_PIXEL_COMMAND_FieldMask                          0xF3FF03FF
#define MWV207REG_TX_PIXEL_COMMAND_ReadMask                           0xF3FF03FF
#define MWV207REG_TX_PIXEL_COMMAND_WriteMask                          0xF3FF03FF
#define MWV207REG_TX_PIXEL_COMMAND_ResetValue                         0x00000000


#define MWV207REG_TX_PIXEL_COMMAND_DATA                                      9:0
#define MWV207REG_TX_PIXEL_COMMAND_DATA_End                                    9
#define MWV207REG_TX_PIXEL_COMMAND_DATA_Start                                  0
#define MWV207REG_TX_PIXEL_COMMAND_DATA_Type                                 U10


#define MWV207REG_TX_PIXEL_COMMAND_NUM                                     25:16
#define MWV207REG_TX_PIXEL_COMMAND_NUM_End                                    25
#define MWV207REG_TX_PIXEL_COMMAND_NUM_Start                                  16
#define MWV207REG_TX_PIXEL_COMMAND_NUM_Type                                  U10


#define MWV207REG_TX_PIXEL_COMMAND_COMMAND                                 31:28
#define MWV207REG_TX_PIXEL_COMMAND_COMMAND_End                                31
#define MWV207REG_TX_PIXEL_COMMAND_COMMAND_Start                              28
#define MWV207REG_TX_PIXEL_COMMAND_COMMAND_Type                              U04
#define   MWV207REG_TX_PIXEL_COMMAND_COMMAND_INVALIDATE_ALL                  0x0
#define   MWV207REG_TX_PIXEL_COMMAND_COMMAND_INVALIDATE_ONE                  0x1
#define   MWV207REG_TX_PIXEL_COMMAND_COMMAND_PREFETCH                        0x2




#define mwv207regTXGpipeInvalidateTextureDescriptorRegAddrs               0x5313
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_Address         0x14C4C
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_MSB                  15
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_LSB                   0
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_BLK                   0
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_Count                 1
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_FieldMask    0xFFFFFFFF
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_ReadMask     0xFFFFFFC0
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_WriteMask    0xFFFFFFC0
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_ResetValue   0x00000000


#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS            31:0
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS_End          31
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS_Start         0
#define MWV207REG_TX_GPIPE_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS_Type        U32




#define mwv207regTXPixelInvalidateTextureDescriptorRegAddrs               0x5314
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_Address         0x14C50
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_MSB                  15
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_LSB                   0
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_BLK                   0
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_Count                 1
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_FieldMask    0xFFFFFFFF
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_ReadMask     0xFFFFFFC0
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_WriteMask    0xFFFFFFC0
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_ResetValue   0x00000000


#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS            31:0
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS_End          31
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS_Start         0
#define MWV207REG_TX_PIXEL_INVALIDATE_TEXTURE_DESCRIPTOR_ADDRESS_Type        U32




#define mwv207regTextureDescriptorAddrTableAddrRegAddrs                   0x5315
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_Address             0x14C54
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_MSB                      15
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_LSB                       0
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_BLK                       0
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_Count                     1
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_FieldMask        0xFFFFFFFF
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_ReadMask         0xFFFFFFFF
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_WriteMask        0xFFFFFFFF
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_ResetValue       0x00000000


#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_ADDRESS                31:0
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_ADDRESS_End              31
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_ADDRESS_Start             0
#define MWV207REG_TEXTURE_DESCRIPTOR_ADDR_TABLE_ADDR_ADDRESS_Type            U32




#define mwv207regSamplerAddrTableAddrRegAddrs                             0x5316
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_Address                        0x14C58
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_MSB                                 15
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_LSB                                  0
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_BLK                                  0
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_Count                                1
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_FieldMask                   0xFFFFFFFF
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_ReadMask                    0xFFFFFFFF
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_WriteMask                   0xFFFFFFFF
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_ResetValue                  0x00000000


#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_ADDRESS                           31:0
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_ADDRESS_End                         31
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_ADDRESS_Start                        0
#define MWV207REG_SAMPLER_ADDR_TABLE_ADDR_ADDRESS_Type                       U32




#define mwv207regSamplerCommandRegAddrs                                   0x5317
#define MWV207REG_SAMPLER_COMMAND_Address                                0x14C5C
#define MWV207REG_SAMPLER_COMMAND_MSB                                         15
#define MWV207REG_SAMPLER_COMMAND_LSB                                          0
#define MWV207REG_SAMPLER_COMMAND_BLK                                          0
#define MWV207REG_SAMPLER_COMMAND_Count                                        1
#define MWV207REG_SAMPLER_COMMAND_FieldMask                           0xF07F007F
#define MWV207REG_SAMPLER_COMMAND_ReadMask                            0xF07F007F
#define MWV207REG_SAMPLER_COMMAND_WriteMask                           0xF07F007F
#define MWV207REG_SAMPLER_COMMAND_ResetValue                          0x00000000


#define MWV207REG_SAMPLER_COMMAND_INDEX                                      6:0
#define MWV207REG_SAMPLER_COMMAND_INDEX_End                                    6
#define MWV207REG_SAMPLER_COMMAND_INDEX_Start                                  0
#define MWV207REG_SAMPLER_COMMAND_INDEX_Type                                 U07


#define MWV207REG_SAMPLER_COMMAND_NUM                                      22:16
#define MWV207REG_SAMPLER_COMMAND_NUM_End                                     22
#define MWV207REG_SAMPLER_COMMAND_NUM_Start                                   16
#define MWV207REG_SAMPLER_COMMAND_NUM_Type                                   U07


#define MWV207REG_SAMPLER_COMMAND_COMMAND                                  31:28
#define MWV207REG_SAMPLER_COMMAND_COMMAND_End                                 31
#define MWV207REG_SAMPLER_COMMAND_COMMAND_Start                               28
#define MWV207REG_SAMPLER_COMMAND_COMMAND_Type                               U04
#define   MWV207REG_SAMPLER_COMMAND_COMMAND_INVALIDATE_ALL                   0x0
#define   MWV207REG_SAMPLER_COMMAND_COMMAND_INVALIDATE                       0x1
#define   MWV207REG_SAMPLER_COMMAND_COMMAND_PREFETCH                         0x2




#define mwv207regSamplerInvalidateRegAddrs                                0x5318
#define MWV207REG_SAMPLER_INVALIDATE_Address                             0x14C60
#define MWV207REG_SAMPLER_INVALIDATE_MSB                                      15
#define MWV207REG_SAMPLER_INVALIDATE_LSB                                       0
#define MWV207REG_SAMPLER_INVALIDATE_BLK                                       0
#define MWV207REG_SAMPLER_INVALIDATE_Count                                     1
#define MWV207REG_SAMPLER_INVALIDATE_FieldMask                        0xFFFFFFFF
#define MWV207REG_SAMPLER_INVALIDATE_ReadMask                         0xFFFFFFC0
#define MWV207REG_SAMPLER_INVALIDATE_WriteMask                        0xFFFFFFC0
#define MWV207REG_SAMPLER_INVALIDATE_ResetValue                       0x00000000


#define MWV207REG_SAMPLER_INVALIDATE_ADDRESS                                31:0
#define MWV207REG_SAMPLER_INVALIDATE_ADDRESS_End                              31
#define MWV207REG_SAMPLER_INVALIDATE_ADDRESS_Start                             0
#define MWV207REG_SAMPLER_INVALIDATE_ADDRESS_Type                            U32





#define mwv207regTXGpipeTextureDescriptorAddrRegAddrs                     0x5600
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_Address               0x15800
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_MSB                        15
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_LSB                         7
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_BLK                         0
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_Count                     128
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_FieldMask          0xFFFFFFFF
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_ReadMask           0xFFFFFFC0
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_WriteMask          0xFFFFFFC0
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_ResetValue         0x00000000


#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_ADDRESS                  31:0
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_ADDRESS_End                31
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_ADDRESS_Start               0
#define MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR_ADDRESS_Type              U32




#define mwv207regTXGpipeTextureCtrlRegAddrs                               0x5680
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_Address                          0x15A00
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_MSB                                   15
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_LSB                                    7
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_BLK                                    0
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_Count                                128
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_FieldMask                     0x0000007F
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_ReadMask                      0x0000007F
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_WriteMask                     0x0000007F
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_ResetValue                    0x00000000


#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX256_BYTE_REQUEST                   0:0
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX256_BYTE_REQUEST_End                 0
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX256_BYTE_REQUEST_Start               0
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX256_BYTE_REQUEST_Type              U01
#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX256_BYTE_REQUEST_DISABLE         0x0
#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX256_BYTE_REQUEST_ENABLE          0x1

#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILE_STATUS                          1:1
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILE_STATUS_End                        1
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILE_STATUS_Start                      1
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILE_STATUS_Type                     U01

#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILE_STATUS_NO                     0x0

#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILE_STATUS_YES                    0x1


#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILESTATUS_CLIENT                    4:2
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILESTATUS_CLIENT_End                  4
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILESTATUS_CLIENT_Start                2
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TILESTATUS_CLIENT_Type               U03


#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_COMPRESSION_DEC                      5:5
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_COMPRESSION_DEC_End                    5
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_COMPRESSION_DEC_Start                  5
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_COMPRESSION_DEC_Type                 U01
#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_COMPRESSION_DEC_DISABLE            0x0
#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_COMPRESSION_DEC_ENABLE             0x1


#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX128_BYTE_REQUEST                   6:6
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX128_BYTE_REQUEST_End                 6
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX128_BYTE_REQUEST_Start               6
#define MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX128_BYTE_REQUEST_Type              U01
#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX128_BYTE_REQUEST_DISABLE         0x0
#define   MWV207REG_TX_GPIPE_TEXTURE_CTRL_TX128_BYTE_REQUEST_ENABLE          0x1





#define mwv207regTXPixelTextureDescriptorAddrRegAddrs                     0x5700
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_Address               0x15C00
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_MSB                        15
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_LSB                         7
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_BLK                         0
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_Count                     128
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_FieldMask          0xFFFFFFFF
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_ReadMask           0xFFFFFFC0
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_WriteMask          0xFFFFFFC0
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_ResetValue         0x00000000


#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_ADDRESS                  31:0
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_ADDRESS_End                31
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_ADDRESS_Start               0
#define MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR_ADDRESS_Type              U32




#define mwv207regTXPixelTextureCtrlRegAddrs                               0x5780
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_Address                          0x15E00
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_MSB                                   15
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_LSB                                    7
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_BLK                                    0
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_Count                                128
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_FieldMask                     0x0000007F
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_ReadMask                      0x0000007F
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_WriteMask                     0x0000007F
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_ResetValue                    0x00000000


#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX256_BYTE_REQUEST                   0:0
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX256_BYTE_REQUEST_End                 0
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX256_BYTE_REQUEST_Start               0
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX256_BYTE_REQUEST_Type              U01
#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX256_BYTE_REQUEST_DISABLE         0x0
#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX256_BYTE_REQUEST_ENABLE          0x1

#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILE_STATUS                          1:1
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILE_STATUS_End                        1
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILE_STATUS_Start                      1
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILE_STATUS_Type                     U01

#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILE_STATUS_NO                     0x0

#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILE_STATUS_YES                    0x1


#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILESTATUS_CLIENT                    4:2
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILESTATUS_CLIENT_End                  4
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILESTATUS_CLIENT_Start                2
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TILESTATUS_CLIENT_Type               U03


#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_COMPRESSION_DEC                      5:5
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_COMPRESSION_DEC_End                    5
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_COMPRESSION_DEC_Start                  5
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_COMPRESSION_DEC_Type                 U01
#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_COMPRESSION_DEC_DISABLE            0x0
#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_COMPRESSION_DEC_ENABLE             0x1


#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX128_BYTE_REQUEST                   6:6
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX128_BYTE_REQUEST_End                 6
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX128_BYTE_REQUEST_Start               6
#define MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX128_BYTE_REQUEST_Type              U01
#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX128_BYTE_REQUEST_DISABLE         0x0
#define   MWV207REG_TX_PIXEL_TEXTURE_CTRL_TX128_BYTE_REQUEST_ENABLE          0x1





#define mwv207regTXGpipeSamplerCtrl0RegAddrs                              0x5800
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_Address                         0x16000
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MSB                                  15
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_LSB                                   7
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_BLK                                   0
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_Count                               128
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_FieldMask                    0xFFFFFFFF
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ReadMask                     0xFFFFFFFF
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_WriteMask                    0xFFFFFFFF
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ResetValue                   0x00000000


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE                          2:0
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_End                        2
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_Start                      0
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_Type                     U03
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_WRAP                   0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_MIRROR                 0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_CLAMP                  0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_BORDER                 0x3
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_MIRROR_ONCE            0x4
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_UMODE_MIRROR_CLAMP2_EDGE     0x5


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE                          5:3
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_End                        5
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_Start                      3
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_Type                     U03
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_WRAP                   0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_MIRROR                 0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_CLAMP                  0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_BORDER                 0x3
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_MIRROR_ONCE            0x4
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_VMODE_MIRROR_CLAMP2_EDGE     0x5


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE                          8:6
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_End                        8
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_Start                      6
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_Type                     U03
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_WRAP                   0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_MIRROR                 0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_CLAMP                  0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_BORDER                 0x3
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_MIRROR_ONCE            0x4
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ADDR_WMODE_MIRROR_CLAMP2_EDGE     0x5


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER                         10:9
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER_End                       10
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER_Start                      9
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER_Type                     U02
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER_NONE                   0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER_POINT                  0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER_LINEAR                 0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIN_FILTER_ANISOTROPIC            0x3


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER                        12:11
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER_End                       12
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER_Start                     11
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER_Type                     U02
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER_NONE                   0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER_POINT                  0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER_LINEAR                 0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MIP_FILTER_ANISOTROPIC            0x3


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER                        14:13
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER_End                       14
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER_Start                     13
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER_Type                     U02
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER_NONE                   0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER_POINT                  0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER_LINEAR                 0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_MAG_FILTER_ANISOTROPIC            0x3


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ROUND_UVW                         15:15
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ROUND_UVW_End                        15
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ROUND_UVW_Start                      15
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ROUND_UVW_Type                      U01
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ROUND_UVW_DISABLE                 0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ROUND_UVW_ENABLE                  0x1

#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_DEPTH_STENCIL_MODE                16:16
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_End               16
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_Start             16
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_Type             U01
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_DEPTH_COMPONENT 0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_STENCIL_INDEX  0x1


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_MODE                      17:17
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_MODE_End                     17
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_MODE_Start                   17
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_MODE_Type                   U01

#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_MODE_NONE                 0x0

#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_MODE_REFERENCE            0x1


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC                      20:18
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_End                     20
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_Start                   18
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_Type                   U03
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_LEQUAL               0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_GEQUAL               0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_LESS                 0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_GREATER              0x3
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_EQUAL                0x4
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_NOT_EQUAL            0x5
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_ALWAYS               0x6
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_COMPARE_FUNC_NEVER                0x7


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_LOD_CALCULATION_MODE              22:21
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_LOD_CALCULATION_MODE_End             22
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_LOD_CALCULATION_MODE_Start           21
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_LOD_CALCULATION_MODE_Type           U02
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_LOD_CALCULATION_MODE_D3D_ES20     0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_LOD_CALCULATION_MODE_ES30         0x1


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL            23:23
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_End           23
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_Start         23
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_Type         U01

#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_NATIVE     0x0

#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_INTEGER    0x1


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ANISO_MAX_LOG                     31:24
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ANISO_MAX_LOG_End                    31
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ANISO_MAX_LOG_Start                  24
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL0_ANISO_MAX_LOG_Type                  U08




#define mwv207regTXGpipeSamplerCtrl1RegAddrs                              0x5880
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_Address                         0x16200
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_MSB                                  15
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_LSB                                   7
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BLK                                   0
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_Count                               128
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_FieldMask                    0x0000007F
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_ReadMask                     0x0000007F
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_WriteMask                    0x0000007F
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_ResetValue                   0x00000000

#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT                 1:0
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT_End               1
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT_Start             0
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT_Type            U02
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN0000    0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN0001    0x1
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN_BORDER_FROM_TEXTURE_DESCRIPTOR 0x2
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN1111    0x3


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_SRGB                                2:2
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_SRGB_End                              2
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_SRGB_Start                            2
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_SRGB_Type                           U01
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_SRGB_DISABLE                      0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_SRGB_ENABLE                       0x1


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_ENABLE                    3:3
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_ENABLE_End                  3
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_ENABLE_Start                3
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_ENABLE_Type               U01
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_ENABLE_DISABLE          0x0
#define   MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_ENABLE_ENABLE           0x1


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_INDEX                     5:4
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_INDEX_End                   5
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_INDEX_Start                 4
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_GUARDBAND_INDEX_Type                U02


#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_UNNORMALIZED                        6:6
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_UNNORMALIZED_End                      6
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_UNNORMALIZED_Start                    6
#define MWV207REG_TX_GPIPE_SAMPLER_CTRL1_UNNORMALIZED_Type                   U01

#define mwv207regTXGpipeSamplerLodMaxMinRegAddrs                          0x5900
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_Address                   0x16400
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MSB                            15
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_LSB                             7
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_BLK                             0
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_Count                         128
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_FieldMask              0x1FFF1FFF
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_ReadMask               0x1FFF1FFF
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_WriteMask              0x1FFF1FFF
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_ResetValue             0x00000000


#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MAX_LOD                      12:0
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MAX_LOD_End                    12
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MAX_LOD_Start                   0
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MAX_LOD_Type                  U13


#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MIN_LOD                     28:16
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MIN_LOD_End                    28
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MIN_LOD_Start                  16
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN_MIN_LOD_Type                  U13

#define mwv207regTXGpipeSamplerLodBiasRegAddrs                            0x5980
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_Address                      0x16600
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_MSB                               15
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_LSB                                7
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_BLK                                0
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_Count                            128
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_FieldMask                 0x0001FFFF
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_ReadMask                  0x0001FFFF
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_WriteMask                 0x0001FFFF
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_ResetValue                0x00000000


#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_BIAS_LOD                        15:0
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_BIAS_LOD_End                      15
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_BIAS_LOD_Start                     0
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_BIAS_LOD_Type                    U16


#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD                16:16
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD_End               16
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD_Start             16
#define MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD_Type             U01

#define mwv207regTXGpipeSamplerAnisoCtrlRegAddrs                          0x5A00
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_Address                    0x16800
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_MSB                             15
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_LSB                              7
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_BLK                              0
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_Count                          128
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_FieldMask               0x000007FF
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_ReadMask                0x000007FF
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_WriteMask               0x000007FF
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_ResetValue              0x00000000


#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG                 10:0
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG_End               10
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG_Start              0
#define MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG_Type             U11





#define mwv207regTXPixelSamplerCtrl0RegAddrs                              0x5B00
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_Address                         0x16C00
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MSB                                  15
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_LSB                                   7
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_BLK                                   0
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_Count                               128
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_FieldMask                    0xFFFFFFFF
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ReadMask                     0xFFFFFFFF
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_WriteMask                    0xFFFFFFFF
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ResetValue                   0x00000000


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE                          2:0
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_End                        2
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_Start                      0
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_Type                     U03
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_WRAP                   0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_MIRROR                 0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_CLAMP                  0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_BORDER                 0x3
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_MIRROR_ONCE            0x4
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_UMODE_MIRROR_CLAMP2_EDGE     0x5


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE                          5:3
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_End                        5
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_Start                      3
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_Type                     U03
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_WRAP                   0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_MIRROR                 0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_CLAMP                  0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_BORDER                 0x3
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_MIRROR_ONCE            0x4
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_VMODE_MIRROR_CLAMP2_EDGE     0x5


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE                          8:6
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_End                        8
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_Start                      6
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_Type                     U03
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_WRAP                   0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_MIRROR                 0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_CLAMP                  0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_BORDER                 0x3
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_MIRROR_ONCE            0x4
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ADDR_WMODE_MIRROR_CLAMP2_EDGE     0x5


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER                         10:9
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER_End                       10
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER_Start                      9
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER_Type                     U02
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER_NONE                   0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER_POINT                  0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER_LINEAR                 0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIN_FILTER_ANISOTROPIC            0x3


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER                        12:11
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER_End                       12
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER_Start                     11
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER_Type                     U02
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER_NONE                   0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER_POINT                  0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER_LINEAR                 0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MIP_FILTER_ANISOTROPIC            0x3


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER                        14:13
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER_End                       14
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER_Start                     13
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER_Type                     U02
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER_NONE                   0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER_POINT                  0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER_LINEAR                 0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_MAG_FILTER_ANISOTROPIC            0x3


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ROUND_UVW                         15:15
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ROUND_UVW_End                        15
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ROUND_UVW_Start                      15
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ROUND_UVW_Type                      U01
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ROUND_UVW_DISABLE                 0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ROUND_UVW_ENABLE                  0x1

#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_DEPTH_STENCIL_MODE                16:16
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_End               16
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_Start             16
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_Type             U01
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_DEPTH_COMPONENT 0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_DEPTH_STENCIL_MODE_STENCIL_INDEX  0x1


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_MODE                      17:17
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_MODE_End                     17
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_MODE_Start                   17
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_MODE_Type                   U01

#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_MODE_NONE                 0x0

#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_MODE_REFERENCE            0x1


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC                      20:18
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_End                     20
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_Start                   18
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_Type                   U03
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_LEQUAL               0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_GEQUAL               0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_LESS                 0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_GREATER              0x3
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_EQUAL                0x4
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_NOT_EQUAL            0x5
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_ALWAYS               0x6
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_COMPARE_FUNC_NEVER                0x7


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_LOD_CALCULATION_MODE              22:21
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_LOD_CALCULATION_MODE_End             22
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_LOD_CALCULATION_MODE_Start           21
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_LOD_CALCULATION_MODE_Type           U02
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_LOD_CALCULATION_MODE_D3D_ES20     0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_LOD_CALCULATION_MODE_ES30         0x1


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL            23:23
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_End           23
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_Start         23
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_Type         U01

#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_NATIVE     0x0

#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL0_INTEGER_FILTER_CONTROL_INTEGER    0x1


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ANISO_MAX_LOG                     31:24
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ANISO_MAX_LOG_End                    31
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ANISO_MAX_LOG_Start                  24
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL0_ANISO_MAX_LOG_Type                  U08




#define mwv207regTXPixelSamplerCtrl1RegAddrs                              0x5B80
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_Address                         0x16E00
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_MSB                                  15
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_LSB                                   7
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BLK                                   0
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_Count                               128
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_FieldMask                    0x0000007F
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_ReadMask                     0x0000007F
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_WriteMask                    0x0000007F
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_ResetValue                   0x00000000

#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT                 1:0
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT_End               1
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT_Start             0
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT_Type            U02
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN0000    0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN0001    0x1
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN_BORDER_FROM_TEXTURE_DESCRIPTOR 0x2
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_BORDER_COLOR_SELECT_RETURN1111    0x3


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_SRGB                                2:2
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_SRGB_End                              2
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_SRGB_Start                            2
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_SRGB_Type                           U01
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_SRGB_DISABLE                      0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_SRGB_ENABLE                       0x1


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_ENABLE                    3:3
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_ENABLE_End                  3
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_ENABLE_Start                3
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_ENABLE_Type               U01
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_ENABLE_DISABLE          0x0
#define   MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_ENABLE_ENABLE           0x1


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_INDEX                     5:4
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_INDEX_End                   5
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_INDEX_Start                 4
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_GUARDBAND_INDEX_Type                U02


#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_UNNORMALIZED                        6:6
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_UNNORMALIZED_End                      6
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_UNNORMALIZED_Start                    6
#define MWV207REG_TX_PIXEL_SAMPLER_CTRL1_UNNORMALIZED_Type                   U01

#define mwv207regTXPixelSamplerLodMaxMinRegAddrs                          0x5C00
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_Address                   0x17000
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MSB                            15
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_LSB                             7
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_BLK                             0
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_Count                         128
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_FieldMask              0x1FFF1FFF
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_ReadMask               0x1FFF1FFF
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_WriteMask              0x1FFF1FFF
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_ResetValue             0x00000000


#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MAX_LOD                      12:0
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MAX_LOD_End                    12
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MAX_LOD_Start                   0
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MAX_LOD_Type                  U13


#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MIN_LOD                     28:16
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MIN_LOD_End                    28
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MIN_LOD_Start                  16
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN_MIN_LOD_Type                  U13

#define mwv207regTXPixelSamplerLodBiasRegAddrs                            0x5C80
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_Address                      0x17200
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_MSB                               15
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_LSB                                7
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_BLK                                0
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_Count                            128
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_FieldMask                 0x0001FFFF
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_ReadMask                  0x0001FFFF
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_WriteMask                 0x0001FFFF
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_ResetValue                0x00000000


#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_BIAS_LOD                        15:0
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_BIAS_LOD_End                      15
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_BIAS_LOD_Start                     0
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_BIAS_LOD_Type                    U16


#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD                16:16
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD_End               16
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD_Start             16
#define MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS_ENABLE_BIAS_LOD_Type             U01

#define mwv207regTXPixelSamplerAnisoCtrlRegAddrs                          0x5D00
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_Address                    0x17400
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_MSB                             15
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_LSB                              7
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_BLK                              0
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_Count                          128
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_FieldMask               0x000007FF
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_ReadMask                0x000007FF
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_WriteMask               0x000007FF
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_ResetValue              0x00000000


#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG                 10:0
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG_End               10
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG_Start              0
#define MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL_ANISO_MAX_LOG_Type             U11



#define MWV207REG_SAMPLER_STATE_MIP_FILTER                                   1:0
#define MWV207REG_SAMPLER_STATE_MIP_FILTER_End                                 1
#define MWV207REG_SAMPLER_STATE_MIP_FILTER_Start                               0
#define MWV207REG_SAMPLER_STATE_MIP_FILTER_Type                              U02
#define   MWV207REG_SAMPLER_STATE_MIP_FILTER_NONE                            0x0
#define   MWV207REG_SAMPLER_STATE_MIP_FILTER_POINT                           0x1
#define   MWV207REG_SAMPLER_STATE_MIP_FILTER_LINEAR                          0x2

#define MWV207REG_SAMPLER_STATE_MAG_FILTER                                   3:2
#define MWV207REG_SAMPLER_STATE_MAG_FILTER_End                                 3
#define MWV207REG_SAMPLER_STATE_MAG_FILTER_Start                               2
#define MWV207REG_SAMPLER_STATE_MAG_FILTER_Type                              U02
#define   MWV207REG_SAMPLER_STATE_MAG_FILTER_NONE                            0x0
#define   MWV207REG_SAMPLER_STATE_MAG_FILTER_POINT                           0x1
#define   MWV207REG_SAMPLER_STATE_MAG_FILTER_LINEAR                          0x2

#define MWV207REG_SAMPLER_STATE_MIN_FILTER                                   5:4
#define MWV207REG_SAMPLER_STATE_MIN_FILTER_End                                 5
#define MWV207REG_SAMPLER_STATE_MIN_FILTER_Start                               4
#define MWV207REG_SAMPLER_STATE_MIN_FILTER_Type                              U02
#define   MWV207REG_SAMPLER_STATE_MIN_FILTER_NONE                            0x0
#define   MWV207REG_SAMPLER_STATE_MIN_FILTER_POINT                           0x1
#define   MWV207REG_SAMPLER_STATE_MIN_FILTER_LINEAR                          0x2

#define MWV207REG_SAMPLER_STATE_ANISO                                        6:6
#define MWV207REG_SAMPLER_STATE_ANISO_End                                      6
#define MWV207REG_SAMPLER_STATE_ANISO_Start                                    6
#define MWV207REG_SAMPLER_STATE_ANISO_Type                                   U01
#define   MWV207REG_SAMPLER_STATE_ANISO_DISABLE                              0x0
#define   MWV207REG_SAMPLER_STATE_ANISO_ENABLE                               0x1

#define MWV207REG_SAMPLER_STATE_REDUCTION_TYPE                               8:7
#define MWV207REG_SAMPLER_STATE_REDUCTION_TYPE_End                             8
#define MWV207REG_SAMPLER_STATE_REDUCTION_TYPE_Start                           7
#define MWV207REG_SAMPLER_STATE_REDUCTION_TYPE_Type                          U02
#define   MWV207REG_SAMPLER_STATE_REDUCTION_TYPE_NORMAL                      0x0
#define   MWV207REG_SAMPLER_STATE_REDUCTION_TYPE_COMPARISON                  0x1
#define   MWV207REG_SAMPLER_STATE_REDUCTION_TYPE_MIN                         0x2
#define   MWV207REG_SAMPLER_STATE_REDUCTION_TYPE_MAX                         0x3

#define MWV207REG_SAMPLER_STATE_ADDRESS_U                                   11:9
#define MWV207REG_SAMPLER_STATE_ADDRESS_U_End                                 11
#define MWV207REG_SAMPLER_STATE_ADDRESS_U_Start                                9
#define MWV207REG_SAMPLER_STATE_ADDRESS_U_Type                               U03
#define   MWV207REG_SAMPLER_STATE_ADDRESS_U_WRAP                             0x0
#define   MWV207REG_SAMPLER_STATE_ADDRESS_U_MIRROR                           0x1
#define   MWV207REG_SAMPLER_STATE_ADDRESS_U_CLAMP                            0x2
#define   MWV207REG_SAMPLER_STATE_ADDRESS_U_BORDER                           0x3
#define   MWV207REG_SAMPLER_STATE_ADDRESS_U_MIRROR_ONCE                      0x4

#define MWV207REG_SAMPLER_STATE_ADDRESS_V                                  14:12
#define MWV207REG_SAMPLER_STATE_ADDRESS_V_End                                 14
#define MWV207REG_SAMPLER_STATE_ADDRESS_V_Start                               12
#define MWV207REG_SAMPLER_STATE_ADDRESS_V_Type                               U03
#define   MWV207REG_SAMPLER_STATE_ADDRESS_V_WRAP                             0x0
#define   MWV207REG_SAMPLER_STATE_ADDRESS_V_MIRROR                           0x1
#define   MWV207REG_SAMPLER_STATE_ADDRESS_V_CLAMP                            0x2
#define   MWV207REG_SAMPLER_STATE_ADDRESS_V_BORDER                           0x3
#define   MWV207REG_SAMPLER_STATE_ADDRESS_V_MIRROR_ONCE                      0x4

#define MWV207REG_SAMPLER_STATE_ADDRESS_W                                  17:15
#define MWV207REG_SAMPLER_STATE_ADDRESS_W_End                                 17
#define MWV207REG_SAMPLER_STATE_ADDRESS_W_Start                               15
#define MWV207REG_SAMPLER_STATE_ADDRESS_W_Type                               U03
#define   MWV207REG_SAMPLER_STATE_ADDRESS_W_WRAP                             0x0
#define   MWV207REG_SAMPLER_STATE_ADDRESS_W_MIRROR                           0x1
#define   MWV207REG_SAMPLER_STATE_ADDRESS_W_CLAMP                            0x2
#define   MWV207REG_SAMPLER_STATE_ADDRESS_W_BORDER                           0x3
#define   MWV207REG_SAMPLER_STATE_ADDRESS_W_MIRROR_ONCE                      0x4


#define MWV207REG_SAMPLER_STATE_COMPARE_FUNC                               20:18
#define MWV207REG_SAMPLER_STATE_COMPARE_FUNC_End                              20
#define MWV207REG_SAMPLER_STATE_COMPARE_FUNC_Start                            18
#define MWV207REG_SAMPLER_STATE_COMPARE_FUNC_Type                            U03
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_LEQUAL                        0x0
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_GEQUAL                        0x1
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_LESS                          0x2
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_GREATER                       0x3
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_EQUAL                         0x4
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_NOT_EQUAL                     0x5
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_ALWAYS                        0x6
#define   MWV207REG_SAMPLER_STATE_COMPARE_FUNC_NEVER                         0x7


#define MWV207REG_SAMPLER_STATE_ROUND_UVW                                  21:21
#define MWV207REG_SAMPLER_STATE_ROUND_UVW_End                                 21
#define MWV207REG_SAMPLER_STATE_ROUND_UVW_Start                               21
#define MWV207REG_SAMPLER_STATE_ROUND_UVW_Type                               U01
#define   MWV207REG_SAMPLER_STATE_ROUND_UVW_DISABLE                          0x0
#define   MWV207REG_SAMPLER_STATE_ROUND_UVW_ENABLE                           0x1


#define MWV207REG_SAMPLER_STATE_DEPTH_STENCIL_MODE                         22:22
#define MWV207REG_SAMPLER_STATE_DEPTH_STENCIL_MODE_End                        22
#define MWV207REG_SAMPLER_STATE_DEPTH_STENCIL_MODE_Start                      22
#define MWV207REG_SAMPLER_STATE_DEPTH_STENCIL_MODE_Type                      U01
#define   MWV207REG_SAMPLER_STATE_DEPTH_STENCIL_MODE_DEPTH                   0x0
#define   MWV207REG_SAMPLER_STATE_DEPTH_STENCIL_MODE_STENCIL                 0x1


#define MWV207REG_SAMPLER_STATE_LOD_CALC_MODE                              23:23
#define MWV207REG_SAMPLER_STATE_LOD_CALC_MODE_End                             23
#define MWV207REG_SAMPLER_STATE_LOD_CALC_MODE_Start                           23
#define MWV207REG_SAMPLER_STATE_LOD_CALC_MODE_Type                           U01
#define   MWV207REG_SAMPLER_STATE_LOD_CALC_MODE_ES20                         0x0
#define   MWV207REG_SAMPLER_STATE_LOD_CALC_MODE_ES30                         0x1


#define MWV207REG_SAMPLER_STATE_INTEGER_FILTER                             24:24
#define MWV207REG_SAMPLER_STATE_INTEGER_FILTER_End                            24
#define MWV207REG_SAMPLER_STATE_INTEGER_FILTER_Start                          24
#define MWV207REG_SAMPLER_STATE_INTEGER_FILTER_Type                          U01
#define   MWV207REG_SAMPLER_STATE_INTEGER_FILTER_NATIVE                      0x0
#define   MWV207REG_SAMPLER_STATE_INTEGER_FILTER_INTEGER                     0x1


#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT                        26:25
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT_End                       26
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT_Start                     25
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT_Type                     U02
#define   MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT_RGBA0000               0x0
#define   MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT_RGBA0001               0x1
#define   MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT_USE_BORDER             0x2
#define   MWV207REG_SAMPLER_STATE_BORDER_COLOR_SELECT_RGBA1111               0x3


#define MWV207REG_SAMPLER_STATE_FLOAT_TX_COORD                             27:27
#define MWV207REG_SAMPLER_STATE_FLOAT_TX_COORD_End                            27
#define MWV207REG_SAMPLER_STATE_FLOAT_TX_COORD_Start                          27
#define MWV207REG_SAMPLER_STATE_FLOAT_TX_COORD_Type                          U01
#define   MWV207REG_SAMPLER_STATE_FLOAT_TX_COORD_NORMALIZED                  0x0
#define   MWV207REG_SAMPLER_STATE_FLOAT_TX_COORD_UNNORMALIZED                0x1


#define MWV207REG_SAMPLER_STATE_GUARDBAND                                  28:28
#define MWV207REG_SAMPLER_STATE_GUARDBAND_End                                 28
#define MWV207REG_SAMPLER_STATE_GUARDBAND_Start                               28
#define MWV207REG_SAMPLER_STATE_GUARDBAND_Type                               U01
#define   MWV207REG_SAMPLER_STATE_GUARDBAND_DISABLE                          0x0
#define   MWV207REG_SAMPLER_STATE_GUARDBAND_ENABLE                           0x1


#define MWV207REG_SAMPLER_STATE_GUARDBAND_INDEX                            30:29
#define MWV207REG_SAMPLER_STATE_GUARDBAND_INDEX_End                           30
#define MWV207REG_SAMPLER_STATE_GUARDBAND_INDEX_Start                         29
#define MWV207REG_SAMPLER_STATE_GUARDBAND_INDEX_Type                         U02



#define MWV207REG_SAMPLER_STATE_MIN_LOD                                     15:0
#define MWV207REG_SAMPLER_STATE_MIN_LOD_End                                   15
#define MWV207REG_SAMPLER_STATE_MIN_LOD_Start                                  0
#define MWV207REG_SAMPLER_STATE_MIN_LOD_Type                                 U16


#define MWV207REG_SAMPLER_STATE_MAX_LOD                                    31:16
#define MWV207REG_SAMPLER_STATE_MAX_LOD_End                                   31
#define MWV207REG_SAMPLER_STATE_MAX_LOD_Start                                 16
#define MWV207REG_SAMPLER_STATE_MAX_LOD_Type                                 U16



#define MWV207REG_SAMPLER_STATE_BIAS_LOD                                    15:0
#define MWV207REG_SAMPLER_STATE_BIAS_LOD_End                                  15
#define MWV207REG_SAMPLER_STATE_BIAS_LOD_Start                                 0
#define MWV207REG_SAMPLER_STATE_BIAS_LOD_Type                                U16

#define MWV207REG_SAMPLER_STATE_ENABLE_LOD_BIAS                            16:16
#define MWV207REG_SAMPLER_STATE_ENABLE_LOD_BIAS_End                           16
#define MWV207REG_SAMPLER_STATE_ENABLE_LOD_BIAS_Start                         16
#define MWV207REG_SAMPLER_STATE_ENABLE_LOD_BIAS_Type                         U01
#define   MWV207REG_SAMPLER_STATE_ENABLE_LOD_BIAS_DISABLE                    0x0

#define   MWV207REG_SAMPLER_STATE_ENABLE_LOD_BIAS_ENABLE                     0x1


#define MWV207REG_SAMPLER_STATE_MAX_ANISO                                  21:17
#define MWV207REG_SAMPLER_STATE_MAX_ANISO_End                                 21
#define MWV207REG_SAMPLER_STATE_MAX_ANISO_Start                               17
#define MWV207REG_SAMPLER_STATE_MAX_ANISO_Type                               U05



#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_B                              31:0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_B_End                            31
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_B_Start                           0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_B_Type                          U32



#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_G                              31:0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_G_End                            31
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_G_Start                           0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_G_Type                          U32



#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_R                              31:0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_R_End                            31
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_R_Start                           0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_R_Type                          U32



#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_A                              31:0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_A_End                            31
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_A_Start                           0
#define MWV207REG_SAMPLER_STATE_BORDER_COLOR_A_Type                          U32




#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD0                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD0_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD0_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD0_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD1                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD1_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD1_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD1_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD2                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD2_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD2_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD2_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD3                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD3_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD3_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD3_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD4                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD4_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD4_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD4_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD5                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD5_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD5_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD5_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD6                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD6_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD6_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD6_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD7                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD7_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD7_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD7_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD8                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD8_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD8_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD8_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD9                                31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD9_End                              31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD9_Start                             0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD9_Type                            U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD10                               31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD10_End                             31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD10_Start                            0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD10_Type                           U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD11                               31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD11_End                             31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD11_Start                            0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD11_Type                           U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD12                               31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD12_End                             31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD12_Start                            0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD12_Type                           U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD13                               31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD13_End                             31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD13_Start                            0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD13_Type                           U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD14                               31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD14_End                             31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD14_Start                            0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD14_Type                           U32



#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD15                               31:0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD15_End                             31
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD15_Start                            0
#define MWV207REG_TEXTURE_STATE_ADDRESS_LOD15_Type                           U32


#define MWV207REG_TEXTURE_STATE_TEXTURE_TYPE                                 2:0
#define MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_End                               2
#define MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_Start                             0
#define MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_Type                            U03
#define   MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_NONE                          0x0
#define   MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_1D                            0x1
#define   MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_2D                            0x2
#define   MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_3D                            0x3
#define   MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_PROJECTED                     0x4
#define   MWV207REG_TEXTURE_STATE_TEXTURE_TYPE_CUBIC                         0x5

#define MWV207REG_TEXTURE_STATE_TEXTURE_ARRAY                                3:3
#define MWV207REG_TEXTURE_STATE_TEXTURE_ARRAY_End                              3
#define MWV207REG_TEXTURE_STATE_TEXTURE_ARRAY_Start                            3
#define MWV207REG_TEXTURE_STATE_TEXTURE_ARRAY_Type                           U01
#define   MWV207REG_TEXTURE_STATE_TEXTURE_ARRAY_DISABLE                      0x0
#define   MWV207REG_TEXTURE_STATE_TEXTURE_ARRAY_ENABLE                       0x1

#define MWV207REG_TEXTURE_STATE_FORMATS                                     14:4
#define MWV207REG_TEXTURE_STATE_FORMATS_End                                   14
#define MWV207REG_TEXTURE_STATE_FORMATS_Start                                  4
#define MWV207REG_TEXTURE_STATE_FORMATS_Type                                 U11
#define   MWV207REG_TEXTURE_STATE_FORMATS_A8                               0x001
#define   MWV207REG_TEXTURE_STATE_FORMATS_L8                               0x002
#define   MWV207REG_TEXTURE_STATE_FORMATS_I8                               0x003
#define   MWV207REG_TEXTURE_STATE_FORMATS_A8L8                             0x004
#define   MWV207REG_TEXTURE_STATE_FORMATS_ARGB4                            0x005
#define   MWV207REG_TEXTURE_STATE_FORMATS_XRGB4                            0x006
#define   MWV207REG_TEXTURE_STATE_FORMATS_ARGB8                            0x007
#define   MWV207REG_TEXTURE_STATE_FORMATS_XRGB8                            0x008
#define   MWV207REG_TEXTURE_STATE_FORMATS_ABGR8                            0x009
#define   MWV207REG_TEXTURE_STATE_FORMATS_XBGR8                            0x00A
#define   MWV207REG_TEXTURE_STATE_FORMATS_R5G6B5                           0x00B
#define   MWV207REG_TEXTURE_STATE_FORMATS_A1RGB5                           0x00C
#define   MWV207REG_TEXTURE_STATE_FORMATS_X1RGB5                           0x00D
#define   MWV207REG_TEXTURE_STATE_FORMATS_YUY2                             0x00E
#define   MWV207REG_TEXTURE_STATE_FORMATS_UYVY                             0x00F
#define   MWV207REG_TEXTURE_STATE_FORMATS_D16                              0x010
#define   MWV207REG_TEXTURE_STATE_FORMATS_D24X8                            0x011
#define   MWV207REG_TEXTURE_STATE_FORMATS_A8_OES                           0x012
#define   MWV207REG_TEXTURE_STATE_FORMATS_DXT1                             0x013
#define   MWV207REG_TEXTURE_STATE_FORMATS_DXT2                             0x014
#define   MWV207REG_TEXTURE_STATE_FORMATS_DXT3                             0x014
#define   MWV207REG_TEXTURE_STATE_FORMATS_DXT4                             0x015
#define   MWV207REG_TEXTURE_STATE_FORMATS_DXT5                             0x015
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC1_UNORM8                       0x013
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC2_UNORM8                       0x014
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC3_UNORM8                       0x015
#define   MWV207REG_TEXTURE_STATE_FORMATS_HDR7E3                           0x016
#define   MWV207REG_TEXTURE_STATE_FORMATS_HDR6E4                           0x017
#define   MWV207REG_TEXTURE_STATE_FORMATS_HDR5E5                           0x018
#define   MWV207REG_TEXTURE_STATE_FORMATS_HDR6E5                           0x019
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGBE8                            0x01A
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGBE8F                           0x01B
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGB9E5                           0x01C
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGB9E5F                          0x01D
#define   MWV207REG_TEXTURE_STATE_FORMATS_ETC1                             0x01E
#define   MWV207REG_TEXTURE_STATE_FORMATS_ETC2_RGB8                        0x040
#define   MWV207REG_TEXTURE_STATE_FORMATS_ETC2_RGB8A1                      0x041
#define   MWV207REG_TEXTURE_STATE_FORMATS_ETC2_RGB8A8                      0x042
#define   MWV207REG_TEXTURE_STATE_FORMATS_EAC_R11_UNSIGNED                 0x043
#define   MWV207REG_TEXTURE_STATE_FORMATS_EAC_RG11_UNSIGNED                0x044
#define   MWV207REG_TEXTURE_STATE_FORMATS_EAC_RG11_SIGNED                  0x045
#define   MWV207REG_TEXTURE_STATE_FORMATS_R8G8                             0x046
#define   MWV207REG_TEXTURE_STATE_FORMATS_RF16                             0x047
#define   MWV207REG_TEXTURE_STATE_FORMATS_RF16GF16                         0x048
#define   MWV207REG_TEXTURE_STATE_FORMATS_RF16GF16BF16AF16                 0x049
#define   MWV207REG_TEXTURE_STATE_FORMATS_RF32                             0x04A
#define   MWV207REG_TEXTURE_STATE_FORMATS_RF32GF32                         0x04B
#define   MWV207REG_TEXTURE_STATE_FORMATS_R10G10B10A2                      0x04C
#define   MWV207REG_TEXTURE_STATE_FORMATS_EAC_R11_SIGNED                   0x04D
#define   MWV207REG_TEXTURE_STATE_FORMATS_R8_SNORM                         0x04E
#define   MWV207REG_TEXTURE_STATE_FORMATS_RG8_SNORM                        0x04F
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGBX8_SNORM                      0x050
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGBA8_SNORM                      0x051
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGB8                             0x052
#define   MWV207REG_TEXTURE_STATE_FORMATS_YUV_ASSEMBLY                     0x053
#define   MWV207REG_TEXTURE_STATE_FORMATS_ASTC                             0x054
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI8                              0x055
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI8GI8                           0x056
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI8GI8BI8AI8                     0x057
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI16                             0x058
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI16GI16                         0x059
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI16GI16BI16AI16                 0x05A
#define   MWV207REG_TEXTURE_STATE_FORMATS_RF11GF11BF10                     0x05B
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI10GI10BI10AI2                  0x05C
#define   MWV207REG_TEXTURE_STATE_FORMATS_R8G8B8G8                         0x05D
#define   MWV207REG_TEXTURE_STATE_FORMATS_G8R8G8B8                         0x05E
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI8GI8BI8GI8                     0x05F
#define   MWV207REG_TEXTURE_STATE_FORMATS_GI8RI8GI8BI8                     0x060
#define   MWV207REG_TEXTURE_STATE_FORMATS_R8                               0x061
#define   MWV207REG_TEXTURE_STATE_FORMATS_D24S8                            0x062
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI32                             0x063
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI32GI32                         0x064
#define   MWV207REG_TEXTURE_STATE_FORMATS_AYUV                             0x065
#define   MWV207REG_TEXTURE_STATE_FORMATS_RF32GF32BF32AF32                 0x066
#define   MWV207REG_TEXTURE_STATE_FORMATS_RI32GI32BI32AI32                 0x067
#define   MWV207REG_TEXTURE_STATE_FORMATS_D32F                             0x069
#define   MWV207REG_TEXTURE_STATE_FORMATS_D32FS8                           0x06A
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC4_UNORM16                      0x06B
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC4_SNORM16                      0x06C
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC5_UNORM16                      0x06D
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC5_SNORM16                      0x06E
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC6_UF16                         0x06F
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC6_SF16                         0x070
#define   MWV207REG_TEXTURE_STATE_FORMATS_BC7_UNORM8                       0x071
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGBA16_UNORM                     0x072
#define   MWV207REG_TEXTURE_STATE_FORMATS_RGBA16_SNORM                     0x073
#define   MWV207REG_TEXTURE_STATE_FORMATS_RG16_UNORM                       0x074
#define   MWV207REG_TEXTURE_STATE_FORMATS_RG16_SNORM                       0x075
#define   MWV207REG_TEXTURE_STATE_FORMATS_R16_SNORM                        0x076

#define MWV207REG_TEXTURE_STATE_GAMMA_MODE                                 15:15
#define MWV207REG_TEXTURE_STATE_GAMMA_MODE_End                                15
#define MWV207REG_TEXTURE_STATE_GAMMA_MODE_Start                              15
#define MWV207REG_TEXTURE_STATE_GAMMA_MODE_Type                              U01
#define   MWV207REG_TEXTURE_STATE_GAMMA_MODE_DISABLE                         0x0
#define   MWV207REG_TEXTURE_STATE_GAMMA_MODE_ENABLE                          0x1

#define MWV207REG_TEXTURE_STATE_ADDRESSING                                 17:16
#define MWV207REG_TEXTURE_STATE_ADDRESSING_End                                17
#define MWV207REG_TEXTURE_STATE_ADDRESSING_Start                              16
#define MWV207REG_TEXTURE_STATE_ADDRESSING_Type                              U02
#define   MWV207REG_TEXTURE_STATE_ADDRESSING_TILED_NO_STRIDE                 0x0
#define   MWV207REG_TEXTURE_STATE_ADDRESSING_LINEAR_NO_STRIDE                0x1
#define   MWV207REG_TEXTURE_STATE_ADDRESSING_TILED                           0x2
#define   MWV207REG_TEXTURE_STATE_ADDRESSING_LINEAR                          0x3

#define MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL                             19:18
#define MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL_End                            19
#define MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL_Start                          18
#define MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL_Type                          U02
#define   MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL_NO_SWAP                     0x0
#define   MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL_SWAP_WORD                   0x1
#define   MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL_SWAP_DWORD                  0x2
#define   MWV207REG_TEXTURE_STATE_ENDIAN_CONTROL_SWAP_DDWORD                 0x3

#define MWV207REG_TEXTURE_STATE_SEAMLESS_CUBE_MAP                          20:20
#define MWV207REG_TEXTURE_STATE_SEAMLESS_CUBE_MAP_End                         20
#define MWV207REG_TEXTURE_STATE_SEAMLESS_CUBE_MAP_Start                       20
#define MWV207REG_TEXTURE_STATE_SEAMLESS_CUBE_MAP_Type                       U01
#define   MWV207REG_TEXTURE_STATE_SEAMLESS_CUBE_MAP_DISABLE                  0x0
#define   MWV207REG_TEXTURE_STATE_SEAMLESS_CUBE_MAP_ENABLE                   0x1

#define MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN                           23:21
#define MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_End                          23
#define MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_Start                        21
#define MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_Type                        U03
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_FOUR                      0x0
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_SIXTEEN                   0x1
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_SUPER_TILED               0x2
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_SPLIT_TILED               0x3
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_SPLIT_SUPER_TILED         0x4
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_SPLIT_TILED_BIG           0x5
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_SPLIT_SUPER_TILED_BIG     0x6
#define   MWV207REG_TEXTURE_STATE_HORIZONTAL_ALIGN_SUPER_TILED_YMAJOR        0x7

#define MWV207REG_TEXTURE_STATE_YUV_STANDARD                               24:24
#define MWV207REG_TEXTURE_STATE_YUV_STANDARD_End                              24
#define MWV207REG_TEXTURE_STATE_YUV_STANDARD_Start                            24
#define MWV207REG_TEXTURE_STATE_YUV_STANDARD_Type                            U01
#define   MWV207REG_TEXTURE_STATE_YUV_STANDARD_YUV601                        0x0
#define   MWV207REG_TEXTURE_STATE_YUV_STANDARD_YUV709                        0x1

#define MWV207REG_TEXTURE_STATE_IMAGE_FILTER                               25:25
#define MWV207REG_TEXTURE_STATE_IMAGE_FILTER_End                              25
#define MWV207REG_TEXTURE_STATE_IMAGE_FILTER_Start                            25
#define MWV207REG_TEXTURE_STATE_IMAGE_FILTER_Type                            U01
#define   MWV207REG_TEXTURE_STATE_IMAGE_FILTER_NORMAL                        0x0
#define   MWV207REG_TEXTURE_STATE_IMAGE_FILTER_KERNAL                        0x1

#define MWV207REG_TEXTURE_STATE_USE_STRIDE                                 26:26
#define MWV207REG_TEXTURE_STATE_USE_STRIDE_End                                26
#define MWV207REG_TEXTURE_STATE_USE_STRIDE_Start                              26
#define MWV207REG_TEXTURE_STATE_USE_STRIDE_Type                              U01
#define   MWV207REG_TEXTURE_STATE_USE_STRIDE_DISABLE                         0x0
#define   MWV207REG_TEXTURE_STATE_USE_STRIDE_ENABLE                          0x1

#define MWV207REG_TEXTURE_STATE_FILTER_CONSTANT                            27:27
#define MWV207REG_TEXTURE_STATE_FILTER_CONSTANT_End                           27
#define MWV207REG_TEXTURE_STATE_FILTER_CONSTANT_Start                         27
#define MWV207REG_TEXTURE_STATE_FILTER_CONSTANT_Type                         U01
#define   MWV207REG_TEXTURE_STATE_FILTER_CONSTANT_DISABLE                    0x0
#define   MWV207REG_TEXTURE_STATE_FILTER_CONSTANT_ENABLE                     0x1

#define MWV207REG_TEXTURE_STATE_MSAA                                       29:28
#define MWV207REG_TEXTURE_STATE_MSAA_End                                      29
#define MWV207REG_TEXTURE_STATE_MSAA_Start                                    28
#define MWV207REG_TEXTURE_STATE_MSAA_Type                                    U02
#define   MWV207REG_TEXTURE_STATE_MSAA_NON                                   0x0
#define   MWV207REG_TEXTURE_STATE_MSAA_X4                                    0x1
#define   MWV207REG_TEXTURE_STATE_MSAA_X8                                    0x2



#define MWV207REG_TEXTURE_STATE_NORM_RED                                     1:0
#define MWV207REG_TEXTURE_STATE_NORM_RED_End                                   1
#define MWV207REG_TEXTURE_STATE_NORM_RED_Start                                 0
#define MWV207REG_TEXTURE_STATE_NORM_RED_Type                                U02
#define   MWV207REG_TEXTURE_STATE_NORM_RED_DISABLE                           0x0
#define   MWV207REG_TEXTURE_STATE_NORM_RED_UNSIGNED                          0x1
#define   MWV207REG_TEXTURE_STATE_NORM_RED_SIGNED                            0x2


#define MWV207REG_TEXTURE_STATE_NORM_GREEN                                   3:2
#define MWV207REG_TEXTURE_STATE_NORM_GREEN_End                                 3
#define MWV207REG_TEXTURE_STATE_NORM_GREEN_Start                               2
#define MWV207REG_TEXTURE_STATE_NORM_GREEN_Type                              U02
#define   MWV207REG_TEXTURE_STATE_NORM_GREEN_DISABLE                         0x0
#define   MWV207REG_TEXTURE_STATE_NORM_GREEN_UNSIGNED                        0x1
#define   MWV207REG_TEXTURE_STATE_NORM_GREEN_SIGNED                          0x2


#define MWV207REG_TEXTURE_STATE_NORM_BLUE                                    5:4
#define MWV207REG_TEXTURE_STATE_NORM_BLUE_End                                  5
#define MWV207REG_TEXTURE_STATE_NORM_BLUE_Start                                4
#define MWV207REG_TEXTURE_STATE_NORM_BLUE_Type                               U02
#define   MWV207REG_TEXTURE_STATE_NORM_BLUE_DISABLE                          0x0
#define   MWV207REG_TEXTURE_STATE_NORM_BLUE_UNSIGNED                         0x1
#define   MWV207REG_TEXTURE_STATE_NORM_BLUE_SIGNED                           0x2


#define MWV207REG_TEXTURE_STATE_NORM_ALPHA                                   7:6
#define MWV207REG_TEXTURE_STATE_NORM_ALPHA_End                                 7
#define MWV207REG_TEXTURE_STATE_NORM_ALPHA_Start                               6
#define MWV207REG_TEXTURE_STATE_NORM_ALPHA_Type                              U02
#define   MWV207REG_TEXTURE_STATE_NORM_ALPHA_DISABLE                         0x0
#define   MWV207REG_TEXTURE_STATE_NORM_ALPHA_UNSIGNED                        0x1
#define   MWV207REG_TEXTURE_STATE_NORM_ALPHA_SIGNED                          0x2


#define MWV207REG_TEXTURE_STATE_CLAMP_FILTER                                 8:8
#define MWV207REG_TEXTURE_STATE_CLAMP_FILTER_End                               8
#define MWV207REG_TEXTURE_STATE_CLAMP_FILTER_Start                             8
#define MWV207REG_TEXTURE_STATE_CLAMP_FILTER_Type                            U01
#define   MWV207REG_TEXTURE_STATE_CLAMP_FILTER_DISABLE                       0x0
#define   MWV207REG_TEXTURE_STATE_CLAMP_FILTER_ENABLE                        0x1


#define MWV207REG_TEXTURE_STATE_CLAMP_COLOR                                  9:9
#define MWV207REG_TEXTURE_STATE_CLAMP_COLOR_End                                9
#define MWV207REG_TEXTURE_STATE_CLAMP_COLOR_Start                              9
#define MWV207REG_TEXTURE_STATE_CLAMP_COLOR_Type                             U01
#define   MWV207REG_TEXTURE_STATE_CLAMP_COLOR_DISABLE                        0x0
#define   MWV207REG_TEXTURE_STATE_CLAMP_COLOR_ENABLE                         0x1


#define MWV207REG_TEXTURE_STATE_INTEGER_SIGN_EXTENSION                     11:10
#define MWV207REG_TEXTURE_STATE_INTEGER_SIGN_EXTENSION_End                    11
#define MWV207REG_TEXTURE_STATE_INTEGER_SIGN_EXTENSION_Start                  10
#define MWV207REG_TEXTURE_STATE_INTEGER_SIGN_EXTENSION_Type                  U02

#define   MWV207REG_TEXTURE_STATE_INTEGER_SIGN_EXTENSION_NONE                0x0

#define   MWV207REG_TEXTURE_STATE_INTEGER_SIGN_EXTENSION_SIGNED8             0x1

#define   MWV207REG_TEXTURE_STATE_INTEGER_SIGN_EXTENSION_SIGNED16            0x2


#define MWV207REG_TEXTURE_STATE_NORM_OUTPUT                                13:12
#define MWV207REG_TEXTURE_STATE_NORM_OUTPUT_End                               13
#define MWV207REG_TEXTURE_STATE_NORM_OUTPUT_Start                             12
#define MWV207REG_TEXTURE_STATE_NORM_OUTPUT_Type                             U02

#define   MWV207REG_TEXTURE_STATE_NORM_OUTPUT_AUTO                           0x0

#define   MWV207REG_TEXTURE_STATE_NORM_OUTPUT_ENABLED                        0x1

#define   MWV207REG_TEXTURE_STATE_NORM_OUTPUT_DISABLED                       0x2

#define MWV207REG_TEXTURE_STATE_COLOR_SWIZZLE                              16:16
#define MWV207REG_TEXTURE_STATE_COLOR_SWIZZLE_End                             16
#define MWV207REG_TEXTURE_STATE_COLOR_SWIZZLE_Start                           16
#define MWV207REG_TEXTURE_STATE_COLOR_SWIZZLE_Type                           U01
#define   MWV207REG_TEXTURE_STATE_COLOR_SWIZZLE_DISABLE                      0x0
#define   MWV207REG_TEXTURE_STATE_COLOR_SWIZZLE_ENABLE                       0x1

#define MWV207REG_TEXTURE_STATE_SWIZZLE_RED                                19:17
#define MWV207REG_TEXTURE_STATE_SWIZZLE_RED_End                               19
#define MWV207REG_TEXTURE_STATE_SWIZZLE_RED_Start                             17
#define MWV207REG_TEXTURE_STATE_SWIZZLE_RED_Type                             U03
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_RED_RED                            0x0
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_RED_GREEN                          0x1
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_RED_BLUE                           0x2
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_RED_ALPHA                          0x3
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_RED_ZERO                           0x4
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_RED_ONE                            0x5

#define MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN                              22:20
#define MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_End                             22
#define MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_Start                           20
#define MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_Type                           U03
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_RED                          0x0
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_GREEN                        0x1
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_BLUE                         0x2
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_ALPHA                        0x3
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_ZERO                         0x4
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_GREEN_ONE                          0x5

#define MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE                               25:23
#define MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_End                              25
#define MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_Start                            23
#define MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_Type                            U03
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_RED                           0x0
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_GREEN                         0x1
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_BLUE                          0x2
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_ALPHA                         0x3
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_ZERO                          0x4
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_BLUE_ONE                           0x5

#define MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA                              28:26
#define MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_End                             28
#define MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_Start                           26
#define MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_Type                           U03
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_RED                          0x0
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_GREEN                        0x1
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_BLUE                         0x2
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_ALPHA                        0x3
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_ZERO                         0x4
#define   MWV207REG_TEXTURE_STATE_SWIZZLE_ALPHA_ONE                          0x5


#define MWV207REG_TEXTURE_STATE_SWAP_Y                                     29:29
#define MWV207REG_TEXTURE_STATE_SWAP_Y_End                                    29
#define MWV207REG_TEXTURE_STATE_SWAP_Y_Start                                  29
#define MWV207REG_TEXTURE_STATE_SWAP_Y_Type                                  U01
#define   MWV207REG_TEXTURE_STATE_SWAP_Y_DISABLE                             0x0
#define   MWV207REG_TEXTURE_STATE_SWAP_Y_ENABLE                              0x1


#define MWV207REG_TEXTURE_STATE_SWAP_UV                                    30:30
#define MWV207REG_TEXTURE_STATE_SWAP_UV_End                                   30
#define MWV207REG_TEXTURE_STATE_SWAP_UV_Start                                 30
#define MWV207REG_TEXTURE_STATE_SWAP_UV_Type                                 U01
#define   MWV207REG_TEXTURE_STATE_SWAP_UV_DISABLE                            0x0
#define   MWV207REG_TEXTURE_STATE_SWAP_UV_ENABLE                             0x1

#define MWV207REG_TEXTURE_STATE_FLIP_Y                                     31:31
#define MWV207REG_TEXTURE_STATE_FLIP_Y_End                                    31
#define MWV207REG_TEXTURE_STATE_FLIP_Y_Start                                  31
#define MWV207REG_TEXTURE_STATE_FLIP_Y_Type                                  U01
#define   MWV207REG_TEXTURE_STATE_FLIP_Y_DISABLE                             0x0
#define   MWV207REG_TEXTURE_STATE_FLIP_Y_ENABLE                              0x1



#define MWV207REG_TEXTURE_STATE_TEXTURE_WIDTH                               15:0
#define MWV207REG_TEXTURE_STATE_TEXTURE_WIDTH_End                             15
#define MWV207REG_TEXTURE_STATE_TEXTURE_WIDTH_Start                            0
#define MWV207REG_TEXTURE_STATE_TEXTURE_WIDTH_Type                           U16


#define MWV207REG_TEXTURE_STATE_TILE_STATUS_CLIENT                         22:20
#define MWV207REG_TEXTURE_STATE_TILE_STATUS_CLIENT_End                        22
#define MWV207REG_TEXTURE_STATE_TILE_STATUS_CLIENT_Start                      20
#define MWV207REG_TEXTURE_STATE_TILE_STATUS_CLIENT_Type                      U03


#define MWV207REG_TEXTURE_STATE_TILE_STATUS_ENABLE                         23:23
#define MWV207REG_TEXTURE_STATE_TILE_STATUS_ENABLE_End                        23
#define MWV207REG_TEXTURE_STATE_TILE_STATUS_ENABLE_Start                      23
#define MWV207REG_TEXTURE_STATE_TILE_STATUS_ENABLE_Type                      U01
#define   MWV207REG_TEXTURE_STATE_TILE_STATUS_ENABLE_DISABLE                 0x0
#define   MWV207REG_TEXTURE_STATE_TILE_STATUS_ENABLE_ENABLE                  0x1


#define MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE                       25:24
#define MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE_End                      25
#define MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE_Start                    24
#define MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE_Type                    U02

#define   MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE_BYTES64               0x0

#define   MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE_BYTES128              0x1

#define   MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE_BYTES160              0x2

#define   MWV207REG_TEXTURE_STATE_TEXTURE_REQUEST_SIZE_BYTES256              0x3



#define MWV207REG_TEXTURE_STATE_TEXTURE_HEIGHT                              15:0
#define MWV207REG_TEXTURE_STATE_TEXTURE_HEIGHT_End                            15
#define MWV207REG_TEXTURE_STATE_TEXTURE_HEIGHT_Start                           0
#define MWV207REG_TEXTURE_STATE_TEXTURE_HEIGHT_Type                          U16


#define MWV207REG_TEXTURE_STATE_TEXTURE_DEPTH                              31:16
#define MWV207REG_TEXTURE_STATE_TEXTURE_DEPTH_End                             31
#define MWV207REG_TEXTURE_STATE_TEXTURE_DEPTH_Start                           16
#define MWV207REG_TEXTURE_STATE_TEXTURE_DEPTH_Type                           U16


#define MWV207REG_TEXTURE_STATE_STRIDE                                      17:0
#define MWV207REG_TEXTURE_STATE_STRIDE_End                                    17
#define MWV207REG_TEXTURE_STATE_STRIDE_Start                                   0
#define MWV207REG_TEXTURE_STATE_STRIDE_Type                                  U18

#define MWV207REG_TEXTURE_STATE_BASE_LEVEL                                 23:20
#define MWV207REG_TEXTURE_STATE_BASE_LEVEL_End                                23
#define MWV207REG_TEXTURE_STATE_BASE_LEVEL_Start                              20
#define MWV207REG_TEXTURE_STATE_BASE_LEVEL_Type                              U04

#define MWV207REG_TEXTURE_STATE_MAX_LEVEL                                  27:24
#define MWV207REG_TEXTURE_STATE_MAX_LEVEL_End                                 27
#define MWV207REG_TEXTURE_STATE_MAX_LEVEL_Start                               24
#define MWV207REG_TEXTURE_STATE_MAX_LEVEL_Type                               U04



#define MWV207REG_TEXTURE_STATE_SLICE_SIZE                                  31:0
#define MWV207REG_TEXTURE_STATE_SLICE_SIZE_End                                31
#define MWV207REG_TEXTURE_STATE_SLICE_SIZE_Start                               0
#define MWV207REG_TEXTURE_STATE_SLICE_SIZE_Type                              U32



#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_X                                 1:0
#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_X_End                               1
#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_X_Start                             0
#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_X_Type                            U02

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_X_NONE                          0x0

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_X_ONE                           0x1

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_X_TWO                           0x2

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_X_FOUR                          0x3


#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y                                 5:4
#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y_End                               5
#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y_Start                             4
#define MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y_Type                            U02

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y_NONE                          0x0

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y_ONE                           0x1

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y_TWO                           0x2

#define   MWV207REG_TEXTURE_STATE_YUV_FORMAT_Y_FOUR                          0x3


#define MWV207REG_TEXTURE_STATE_YUV_CHANNEL_BITS                             6:6
#define MWV207REG_TEXTURE_STATE_YUV_CHANNEL_BITS_End                           6
#define MWV207REG_TEXTURE_STATE_YUV_CHANNEL_BITS_Start                         6
#define MWV207REG_TEXTURE_STATE_YUV_CHANNEL_BITS_Type                        U01

#define   MWV207REG_TEXTURE_STATE_YUV_CHANNEL_BITS_BITS8                     0x0

#define   MWV207REG_TEXTURE_STATE_YUV_CHANNEL_BITS_BITS10                    0x1


#define MWV207REG_TEXTURE_STATE_YUV_YOFFSET                                 10:8
#define MWV207REG_TEXTURE_STATE_YUV_YOFFSET_End                               10
#define MWV207REG_TEXTURE_STATE_YUV_YOFFSET_Start                              8
#define MWV207REG_TEXTURE_STATE_YUV_YOFFSET_Type                             U03


#define MWV207REG_TEXTURE_STATE_YUV_TILE_EX                                11:11
#define MWV207REG_TEXTURE_STATE_YUV_TILE_EX_End                               11
#define MWV207REG_TEXTURE_STATE_YUV_TILE_EX_Start                             11
#define MWV207REG_TEXTURE_STATE_YUV_TILE_EX_Type                             U01

#define   MWV207REG_TEXTURE_STATE_YUV_TILE_EX_NO_EXTERNED                    0x0

#define   MWV207REG_TEXTURE_STATE_YUV_TILE_EX_CUSTOMER0                      0x1


#define MWV207REG_TEXTURE_STATE_YUV_UOFFSET                                14:12
#define MWV207REG_TEXTURE_STATE_YUV_UOFFSET_End                               14
#define MWV207REG_TEXTURE_STATE_YUV_UOFFSET_Start                             12
#define MWV207REG_TEXTURE_STATE_YUV_UOFFSET_Type                             U03


#define MWV207REG_TEXTURE_STATE_YUV_VOFFSET                                18:16
#define MWV207REG_TEXTURE_STATE_YUV_VOFFSET_End                               18
#define MWV207REG_TEXTURE_STATE_YUV_VOFFSET_Start                             16
#define MWV207REG_TEXTURE_STATE_YUV_VOFFSET_Type                             U03


#define MWV207REG_TEXTURE_STATE_YUV_IS_P010                                19:19
#define MWV207REG_TEXTURE_STATE_YUV_IS_P010_End                               19
#define MWV207REG_TEXTURE_STATE_YUV_IS_P010_Start                             19
#define MWV207REG_TEXTURE_STATE_YUV_IS_P010_Type                             U01

#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVED                            20:20
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVED_End                           20
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVED_Start                         20
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVED_Type                         U01
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVED_PLANAR                     0x0
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVED_INTERLEAVED                0x1


#define MWV207REG_TEXTURE_STATE_YUV_INTERLACED                             21:21
#define MWV207REG_TEXTURE_STATE_YUV_INTERLACED_End                            21
#define MWV207REG_TEXTURE_STATE_YUV_INTERLACED_Start                          21
#define MWV207REG_TEXTURE_STATE_YUV_INTERLACED_Type                          U01
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLACED_PROGRESSIVE                 0x0

#define   MWV207REG_TEXTURE_STATE_YUV_INTERLACED_INTERLACED                  0x1


#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_Y                   23:22
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_Y_End                  23
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_Y_Start                22
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_Y_Type                U02
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_Y_PLANE_Y           0x0
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_Y_PLANE_U           0x1
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_Y_PLANE_V           0x2


#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_U                   25:24
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_U_End                  25
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_U_Start                24
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_U_Type                U02
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_U_PLANE_Y           0x0
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_U_PLANE_U           0x1
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_U_PLANE_V           0x2


#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_V                   27:26
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_V_End                  27
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_V_Start                26
#define MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_V_Type                U02
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_V_PLANE_Y           0x0
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_V_PLANE_U           0x1
#define   MWV207REG_TEXTURE_STATE_YUV_INTERLEAVE_SWIZZLE_V_PLANE_V           0x2


#define MWV207REG_TEXTURE_STATE_YUV_TILE_Y                                 29:28
#define MWV207REG_TEXTURE_STATE_YUV_TILE_Y_End                                29
#define MWV207REG_TEXTURE_STATE_YUV_TILE_Y_Start                              28
#define MWV207REG_TEXTURE_STATE_YUV_TILE_Y_Type                              U02
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_Y_LINEAR                          0x0
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_Y_TILE4X4                         0x1
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_Y_TILE8X8                         0x2
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_Y_TILE16X16                       0x3


#define MWV207REG_TEXTURE_STATE_YUV_TILE_UV                                31:30
#define MWV207REG_TEXTURE_STATE_YUV_TILE_UV_End                               31
#define MWV207REG_TEXTURE_STATE_YUV_TILE_UV_Start                             30
#define MWV207REG_TEXTURE_STATE_YUV_TILE_UV_Type                             U02
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_UV_LINEAR                         0x0
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_UV_TILE4X4                        0x1
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_UV_TILE8X8                        0x2
#define   MWV207REG_TEXTURE_STATE_YUV_TILE_UV_TILE16X16                      0x3


#define MWV207REG_TEXTURE_STATE_YUV_USTRIDE                                 15:0
#define MWV207REG_TEXTURE_STATE_YUV_USTRIDE_End                               15
#define MWV207REG_TEXTURE_STATE_YUV_USTRIDE_Start                              0
#define MWV207REG_TEXTURE_STATE_YUV_USTRIDE_Type                             U16

#define MWV207REG_TEXTURE_STATE_YUV_VSTRIDE                                31:16
#define MWV207REG_TEXTURE_STATE_YUV_VSTRIDE_End                               31
#define MWV207REG_TEXTURE_STATE_YUV_VSTRIDE_Start                             16
#define MWV207REG_TEXTURE_STATE_YUV_VSTRIDE_Type                             U16



#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0                               3:0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_End                             3
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_Start                           0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD0_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD0                               4:4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD0_End                             4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD0_Start                           4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD0_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD0_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD0_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1                              11:8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_End                            11
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_Start                           8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD1_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD1                             12:12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD1_End                            12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD1_Start                          12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD1_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD1_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD1_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2                             19:16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_End                            19
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_Start                          16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD2_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD2                             20:20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD2_End                            20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD2_Start                          20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD2_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD2_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD2_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3                             27:24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_End                            27
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_Start                          24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD3_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD3                             28:28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD3_End                            28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD3_Start                          28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD3_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD3_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD3_ENABLE                      0x1



#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4                               3:0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_End                             3
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_Start                           0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD4_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD4                               4:4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD4_End                             4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD4_Start                           4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD4_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD4_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD4_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5                              11:8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_End                            11
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_Start                           8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD5_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD5                             12:12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD5_End                            12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD5_Start                          12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD5_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD5_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD5_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6                             19:16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_End                            19
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_Start                          16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD6_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD6                             20:20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD6_End                            20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD6_Start                          20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD6_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD6_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD6_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7                             27:24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_End                            27
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_Start                          24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD7_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD7                             28:28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD7_End                            28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD7_Start                          28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD7_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD7_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD7_ENABLE                      0x1



#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8                               3:0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_End                             3
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_Start                           0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD8_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD8                               4:4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD8_End                             4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD8_Start                           4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD8_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD8_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD8_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9                              11:8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_End                            11
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_Start                           8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_Type                          U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_4x4                         0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_5x4                         0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_5x5                         0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_6x5                         0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_6x6                         0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_8x5                         0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_8x6                         0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_8x8                         0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_10x5                        0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_10x6                        0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_10x8                        0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_10x10                       0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_12x10                       0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD9_12x12                       0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD9                             12:12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD9_End                            12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD9_Start                          12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD9_Type                          U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD9_DISABLE                     0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD9_ENABLE                      0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10                            19:16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_End                           19
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_Start                         16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_Type                         U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_4x4                        0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_5x4                        0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_5x5                        0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_6x5                        0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_6x6                        0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_8x5                        0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_8x6                        0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_8x8                        0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_10x5                       0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_10x6                       0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_10x8                       0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_10x10                      0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_12x10                      0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD10_12x12                      0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD10                            20:20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD10_End                           20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD10_Start                         20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD10_Type                         U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD10_DISABLE                    0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD10_ENABLE                     0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11                            27:24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_End                           27
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_Start                         24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_Type                         U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_4x4                        0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_5x4                        0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_5x5                        0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_6x5                        0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_6x6                        0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_8x5                        0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_8x6                        0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_8x8                        0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_10x5                       0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_10x6                       0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_10x8                       0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_10x10                      0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_12x10                      0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD11_12x12                      0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD11                            28:28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD11_End                           28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD11_Start                         28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD11_Type                         U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD11_DISABLE                    0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD11_ENABLE                     0x1



#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12                              3:0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_End                            3
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_Start                          0
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_Type                         U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_4x4                        0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_5x4                        0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_5x5                        0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_6x5                        0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_6x6                        0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_8x5                        0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_8x6                        0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_8x8                        0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_10x5                       0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_10x6                       0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_10x8                       0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_10x10                      0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_12x10                      0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD12_12x12                      0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD12                              4:4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD12_End                            4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD12_Start                          4
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD12_Type                         U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD12_DISABLE                    0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD12_ENABLE                     0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13                             11:8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_End                           11
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_Start                          8
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_Type                         U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_4x4                        0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_5x4                        0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_5x5                        0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_6x5                        0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_6x6                        0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_8x5                        0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_8x6                        0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_8x8                        0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_10x5                       0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_10x6                       0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_10x8                       0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_10x10                      0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_12x10                      0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD13_12x12                      0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD13                            12:12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD13_End                           12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD13_Start                         12
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD13_Type                         U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD13_DISABLE                    0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD13_ENABLE                     0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14                            19:16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_End                           19
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_Start                         16
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_Type                         U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_4x4                        0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_5x4                        0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_5x5                        0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_6x5                        0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_6x6                        0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_8x5                        0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_8x6                        0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_8x8                        0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_10x5                       0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_10x6                       0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_10x8                       0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_10x10                      0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_12x10                      0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD14_12x12                      0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD14                            20:20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD14_End                           20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD14_Start                         20
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD14_Type                         U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD14_DISABLE                    0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD14_ENABLE                     0x1


#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15                            27:24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_End                           27
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_Start                         24
#define MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_Type                         U04
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_4x4                        0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_5x4                        0x1
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_5x5                        0x2
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_6x5                        0x3
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_6x6                        0x4
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_8x5                        0x5
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_8x6                        0x6
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_8x8                        0x7
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_10x5                       0x8
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_10x6                       0x9
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_10x8                       0xA
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_10x10                      0xB
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_12x10                      0xC
#define   MWV207REG_TEXTURE_STATE_ASTC_SIZE_LOD15_12x12                      0xD


#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD15                            28:28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD15_End                           28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD15_Start                         28
#define MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD15_Type                         U01
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD15_DISABLE                    0x0
#define   MWV207REG_TEXTURE_STATE_ASTC_SRGB_LOD15_ENABLE                     0x1


#endif


