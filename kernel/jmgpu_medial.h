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




#ifndef __jmgpureg3DBlt_h__
#define __jmgpureg3DBlt_h__





#define mwv207regBltSrcAddressRegAddrs                                    0x5000
#define MWV207REG_BLT_SRC_ADDRESS_Address                                0x14000
#define MWV207REG_BLT_SRC_ADDRESS_MSB                                         15
#define MWV207REG_BLT_SRC_ADDRESS_LSB                                          1
#define MWV207REG_BLT_SRC_ADDRESS_BLK                                          1
#define MWV207REG_BLT_SRC_ADDRESS_Count                                        2
#define MWV207REG_BLT_SRC_ADDRESS_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_SRC_ADDRESS_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_SRC_ADDRESS_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_SRC_ADDRESS_ResetValue                          0x00000000

#define MWV207REG_BLT_SRC_ADDRESS_ADDRESS                                   31:0
#define MWV207REG_BLT_SRC_ADDRESS_ADDRESS_End                                 31
#define MWV207REG_BLT_SRC_ADDRESS_ADDRESS_Start                                0
#define MWV207REG_BLT_SRC_ADDRESS_ADDRESS_Type                               U32




#define mwv207regBltSrcConfigRegAddrs                                     0x5002
#define MWV207REG_BLT_SRC_CONFIG_Address                                 0x14008
#define MWV207REG_BLT_SRC_CONFIG_MSB                                          15
#define MWV207REG_BLT_SRC_CONFIG_LSB                                           0
#define MWV207REG_BLT_SRC_CONFIG_BLK                                           0
#define MWV207REG_BLT_SRC_CONFIG_Count                                         1
#define MWV207REG_BLT_SRC_CONFIG_FieldMask                            0xFFFFFFFF
#define MWV207REG_BLT_SRC_CONFIG_ReadMask                             0xFFFFFFFF
#define MWV207REG_BLT_SRC_CONFIG_WriteMask                            0xFFFFFFFF
#define MWV207REG_BLT_SRC_CONFIG_ResetValue                           0x00000000


#define MWV207REG_BLT_SRC_CONFIG_STRIDE                                     20:0
#define MWV207REG_BLT_SRC_CONFIG_STRIDE_End                                   20
#define MWV207REG_BLT_SRC_CONFIG_STRIDE_Start                                  0
#define MWV207REG_BLT_SRC_CONFIG_STRIDE_Type                                 U21


#define MWV207REG_BLT_SRC_CONFIG_FORMAT                                    26:21
#define MWV207REG_BLT_SRC_CONFIG_FORMAT_End                                   26
#define MWV207REG_BLT_SRC_CONFIG_FORMAT_Start                                 21
#define MWV207REG_BLT_SRC_CONFIG_FORMAT_Type                                 U06
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_X4R4G4B4                          0x00
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_A4R4G4B4                          0x01
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_X1R5G5B5                          0x02
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_A1R5G5B5                          0x03
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_R5G6B5                            0x04
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_X8R8G8B8                          0x05
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_A8R8G8B8                          0x06
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_YUY2                              0x07
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_UYVY                              0x08
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_A8                                0x10
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RF16                              0x11
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RF16GF16                          0x12
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RF16GF16BF16AF16                  0x13
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RF32                              0x14
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RF32GF32                          0x15
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_R10G10B10A2                       0x16
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_D24S8                             0x17
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_D16                               0x18
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_D32FS8                            0x19
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_D32F                              0x1A
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_S8                                0x1B
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI8                               0x1B
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI16GI16BI16AI16                  0x1C
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RF11GF11BF10                      0x1D
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI10GI10BI10AI2                   0x1E
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI8GI8                            0x1F
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_A8L8                              0x20
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_L8                                0x21
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_R8G8B8                            0x22
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_R8                                0x23
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_G8R8                              0x24
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RF32GF32BF32AF32                  0x25
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI32GI32BI32AI32                  0x26
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_R16                               0x27
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RUI32GUI32BUI32AUI32              0x26
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RSI32GSI32BSI32ASI32              0x27
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_NV12                              0x28
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_NV16                              0x29
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_YV12                              0x2A
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI8GI8BI8AI8                      0x2B
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_P010                              0x2C
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI32_NEW                          0x2D
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI32GI32_NEW                      0x2E
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_R16G16                            0x2F
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_R16G16B16A16                      0x30
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI16                              0x31
#define   MWV207REG_BLT_SRC_CONFIG_FORMAT_RI16GI16                          0x32


#define MWV207REG_BLT_SRC_CONFIG_MSAA                                      28:27
#define MWV207REG_BLT_SRC_CONFIG_MSAA_End                                     28
#define MWV207REG_BLT_SRC_CONFIG_MSAA_Start                                   27
#define MWV207REG_BLT_SRC_CONFIG_MSAA_Type                                   U02

#define   MWV207REG_BLT_SRC_CONFIG_MSAA_NONE                                 0x0

#define   MWV207REG_BLT_SRC_CONFIG_MSAA_MSAA2X1                              0x1

#define   MWV207REG_BLT_SRC_CONFIG_MSAA_MSAA1X2                              0x2

#define   MWV207REG_BLT_SRC_CONFIG_MSAA_MSAA4                                0x3


#define MWV207REG_BLT_SRC_CONFIG_TILING                                    29:29
#define MWV207REG_BLT_SRC_CONFIG_TILING_End                                   29
#define MWV207REG_BLT_SRC_CONFIG_TILING_Start                                 29
#define MWV207REG_BLT_SRC_CONFIG_TILING_Type                                 U01
#define   MWV207REG_BLT_SRC_CONFIG_TILING_DISABLED                           0x0
#define   MWV207REG_BLT_SRC_CONFIG_TILING_ENABLE                             0x1


#define MWV207REG_BLT_SRC_CONFIG_SUPER_TILING                              30:30
#define MWV207REG_BLT_SRC_CONFIG_SUPER_TILING_End                             30
#define MWV207REG_BLT_SRC_CONFIG_SUPER_TILING_Start                           30
#define MWV207REG_BLT_SRC_CONFIG_SUPER_TILING_Type                           U01
#define   MWV207REG_BLT_SRC_CONFIG_SUPER_TILING_DISABLED                     0x0
#define   MWV207REG_BLT_SRC_CONFIG_SUPER_TILING_ENABLE                       0x1


#define MWV207REG_BLT_SRC_CONFIG_MULTI_TILING                              31:31
#define MWV207REG_BLT_SRC_CONFIG_MULTI_TILING_End                             31
#define MWV207REG_BLT_SRC_CONFIG_MULTI_TILING_Start                           31
#define MWV207REG_BLT_SRC_CONFIG_MULTI_TILING_Type                           U01
#define   MWV207REG_BLT_SRC_CONFIG_MULTI_TILING_DISABLED                     0x0
#define   MWV207REG_BLT_SRC_CONFIG_MULTI_TILING_ENABLE                       0x1




#define mwv207regBltSrcConfigExRegAddrs                                   0x5003
#define MWV207REG_BLT_SRC_CONFIG_EX_Address                              0x1400C
#define MWV207REG_BLT_SRC_CONFIG_EX_MSB                                       15
#define MWV207REG_BLT_SRC_CONFIG_EX_LSB                                        0
#define MWV207REG_BLT_SRC_CONFIG_EX_BLK                                        0
#define MWV207REG_BLT_SRC_CONFIG_EX_Count                                      1
#define MWV207REG_BLT_SRC_CONFIG_EX_FieldMask                         0x03FFFFFF
#define MWV207REG_BLT_SRC_CONFIG_EX_ReadMask                          0x03FFFFFF
#define MWV207REG_BLT_SRC_CONFIG_EX_WriteMask                         0x03FFFFFF
#define MWV207REG_BLT_SRC_CONFIG_EX_ResetValue                        0x0001C800


#define MWV207REG_BLT_SRC_CONFIG_EX_FAST_CLEAR                               0:0
#define MWV207REG_BLT_SRC_CONFIG_EX_FAST_CLEAR_End                             0
#define MWV207REG_BLT_SRC_CONFIG_EX_FAST_CLEAR_Start                           0
#define MWV207REG_BLT_SRC_CONFIG_EX_FAST_CLEAR_Type                          U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_FAST_CLEAR_DISABLED                    0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_FAST_CLEAR_ENABLE                      0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_COMPRESSION_EN_C                         1:1
#define MWV207REG_BLT_SRC_CONFIG_EX_COMPRESSION_EN_C_End                       1
#define MWV207REG_BLT_SRC_CONFIG_EX_COMPRESSION_EN_C_Start                     1
#define MWV207REG_BLT_SRC_CONFIG_EX_COMPRESSION_EN_C_Type                    U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_COMPRESSION_EN_C_DISABLE               0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_COMPRESSION_EN_C_ENABLE                0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_DEPTH_ADDR_REMAP                         2:2
#define MWV207REG_BLT_SRC_CONFIG_EX_DEPTH_ADDR_REMAP_End                       2
#define MWV207REG_BLT_SRC_CONFIG_EX_DEPTH_ADDR_REMAP_Start                     2
#define MWV207REG_BLT_SRC_CONFIG_EX_DEPTH_ADDR_REMAP_Type                    U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_DEPTH_ADDR_REMAP_DISABLED              0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_DEPTH_ADDR_REMAP_ENABLED               0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_ADDR_REMAP                               3:3
#define MWV207REG_BLT_SRC_CONFIG_EX_ADDR_REMAP_End                             3
#define MWV207REG_BLT_SRC_CONFIG_EX_ADDR_REMAP_Start                           3
#define MWV207REG_BLT_SRC_CONFIG_EX_ADDR_REMAP_Type                          U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_ADDR_REMAP_DISABLED                    0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_ADDR_REMAP_ENABLED                     0x1

#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT                             7:4
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_End                           7
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_Start                         4
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_Type                        U04
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_ARGB4                     0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_A1RGB5                    0x1
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_R5G6B5                    0x2
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_ARGB8                     0x3
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_RGB8                      0x4
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_Z24S8                     0x5
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_Z24                       0x6
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_VAA16                     0x7
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_Z16                       0x8
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_S8                        0x9
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V              0xA
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_UV_MIX                    0xB
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_YUY2                      0xC
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V_P010         0xD
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_UV_MIX_P010               0xE
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_FORMAT_A2RGB10                   0xF


#define MWV207REG_BLT_SRC_CONFIG_EX_SRGB                                     8:8
#define MWV207REG_BLT_SRC_CONFIG_EX_SRGB_End                                   8
#define MWV207REG_BLT_SRC_CONFIG_EX_SRGB_Start                                 8
#define MWV207REG_BLT_SRC_CONFIG_EX_SRGB_Type                                U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_SRGB_DISABLE                           0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_SRGB_ENABLE                            0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED                             10:9
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED_End                           10
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED_Start                          9
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED_Type                         U02
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED_RED                        0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED_GREEN                      0x1
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED_BLUE                       0x2
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_RED_ALPHA                      0x3


#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN                          12:11
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN_End                         12
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN_Start                       11
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN_Type                       U02
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN_RED                      0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN_GREEN                    0x1
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN_BLUE                     0x2
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_GREEN_ALPHA                    0x3


#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE                           14:13
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE_End                          14
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE_Start                        13
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE_Type                        U02
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE_RED                       0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE_GREEN                     0x1
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE_BLUE                      0x2
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_BLUE_ALPHA                     0x3


#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA                          16:15
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA_End                         16
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA_Start                       15
#define MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA_Type                       U02
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA_RED                      0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA_GREEN                    0x1
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA_BLUE                     0x2
#define   MWV207REG_BLT_SRC_CONFIG_EX_SWIZZLE_ALPHA_ALPHA                    0x3

#define MWV207REG_BLT_SRC_CONFIG_EX_CACHE_MODE                             17:17
#define MWV207REG_BLT_SRC_CONFIG_EX_CACHE_MODE_End                            17
#define MWV207REG_BLT_SRC_CONFIG_EX_CACHE_MODE_Start                          17
#define MWV207REG_BLT_SRC_CONFIG_EX_CACHE_MODE_Type                          U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_CACHE_MODE_DISABLED                    0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_CACHE_MODE_ENABLE                      0x1

#define MWV207REG_BLT_SRC_CONFIG_EX_UV_SWIZZLE                             18:18
#define MWV207REG_BLT_SRC_CONFIG_EX_UV_SWIZZLE_End                            18
#define MWV207REG_BLT_SRC_CONFIG_EX_UV_SWIZZLE_Start                          18
#define MWV207REG_BLT_SRC_CONFIG_EX_UV_SWIZZLE_Type                          U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_UV_SWIZZLE_DISABLED                    0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_UV_SWIZZLE_ENABLE                      0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR64                                19:19
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR64_End                               19
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR64_Start                             19
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR64_Type                             U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR64_COLOR16OR32                    0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR64_COLOR64                        0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_STATUS4_BIT                       20:20
#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_STATUS4_BIT_End                      20
#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_STATUS4_BIT_Start                    20
#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_STATUS4_BIT_Type                    U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_TILE_STATUS4_BIT_DISABLED              0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_TILE_STATUS4_BIT_ENABLED               0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE                              22:21
#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE_End                             22
#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE_Start                           21
#define MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE_Type                           U02
#define   MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE_TILED4X4                     0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE_SUPER_TILED_XMAJOR           0x1
#define   MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE_SUPER_TILED_YMAJOR           0x2
#define   MWV207REG_BLT_SRC_CONFIG_EX_TILE_MODE_TILED8X8                     0x3


#define MWV207REG_BLT_SRC_CONFIG_EX_MSAA_COMPRESSION                       23:23
#define MWV207REG_BLT_SRC_CONFIG_EX_MSAA_COMPRESSION_End                      23
#define MWV207REG_BLT_SRC_CONFIG_EX_MSAA_COMPRESSION_Start                    23
#define MWV207REG_BLT_SRC_CONFIG_EX_MSAA_COMPRESSION_Type                    U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_MSAA_COMPRESSION_DISABLE               0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_MSAA_COMPRESSION_ENABLE                0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_YMAJOR                           24:24
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_YMAJOR_End                          24
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_YMAJOR_Start                        24
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR_YMAJOR_Type                        U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_YMAJOR_DISABLE                   0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR_YMAJOR_ENABLE                    0x1


#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR128                               25:25
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR128_End                              25
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR128_Start                            25
#define MWV207REG_BLT_SRC_CONFIG_EX_COLOR128_Type                            U01
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR128_DISABLE                       0x0
#define   MWV207REG_BLT_SRC_CONFIG_EX_COLOR128_ENABLE                        0x1




#define mwv207regBltSrcTileStatusAddressRegAddrs                          0x5004
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_Address                    0x14010
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_MSB                             15
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_LSB                              0
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_BLK                              0
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_Count                            1
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_ReadMask                0xFFFFFFFF
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_WriteMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_ResetValue              0x00000000

#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_ADDRESS                       31:0
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_ADDRESS_End                     31
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_ADDRESS_Start                    0
#define MWV207REG_BLT_SRC_TILE_STATUS_ADDRESS_ADDRESS_Type                   U32




#define mwv207regBltSrcOriginRegAddrs                                     0x5005
#define MWV207REG_BLT_SRC_ORIGIN_Address                                 0x14014
#define MWV207REG_BLT_SRC_ORIGIN_MSB                                          15
#define MWV207REG_BLT_SRC_ORIGIN_LSB                                           0
#define MWV207REG_BLT_SRC_ORIGIN_BLK                                           0
#define MWV207REG_BLT_SRC_ORIGIN_Count                                         1
#define MWV207REG_BLT_SRC_ORIGIN_FieldMask                            0xFFFFFFFF
#define MWV207REG_BLT_SRC_ORIGIN_ReadMask                             0xFFFFFFFF
#define MWV207REG_BLT_SRC_ORIGIN_WriteMask                            0xFFFFFFFF
#define MWV207REG_BLT_SRC_ORIGIN_ResetValue                           0x00000000


#define MWV207REG_BLT_SRC_ORIGIN_X                                          15:0
#define MWV207REG_BLT_SRC_ORIGIN_X_End                                        15
#define MWV207REG_BLT_SRC_ORIGIN_X_Start                                       0
#define MWV207REG_BLT_SRC_ORIGIN_X_Type                                      U16


#define MWV207REG_BLT_SRC_ORIGIN_Y                                         31:16
#define MWV207REG_BLT_SRC_ORIGIN_Y_End                                        31
#define MWV207REG_BLT_SRC_ORIGIN_Y_Start                                      16
#define MWV207REG_BLT_SRC_ORIGIN_Y_Type                                      U16




#define mwv207regBltDestAddressRegAddrs                                   0x5006
#define MWV207REG_BLT_DEST_ADDRESS_Address                               0x14018
#define MWV207REG_BLT_DEST_ADDRESS_MSB                                        15
#define MWV207REG_BLT_DEST_ADDRESS_LSB                                         1
#define MWV207REG_BLT_DEST_ADDRESS_BLK                                         1
#define MWV207REG_BLT_DEST_ADDRESS_Count                                       2
#define MWV207REG_BLT_DEST_ADDRESS_FieldMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEST_ADDRESS_ReadMask                           0xFFFFFFFF
#define MWV207REG_BLT_DEST_ADDRESS_WriteMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEST_ADDRESS_ResetValue                         0x00000000

#define MWV207REG_BLT_DEST_ADDRESS_ADDRESS                                  31:0
#define MWV207REG_BLT_DEST_ADDRESS_ADDRESS_End                                31
#define MWV207REG_BLT_DEST_ADDRESS_ADDRESS_Start                               0
#define MWV207REG_BLT_DEST_ADDRESS_ADDRESS_Type                              U32




#define mwv207regBltDestTileStatusAddressRegAddrs                         0x5008
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_Address                   0x14020
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_MSB                            15
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_LSB                             0
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_BLK                             0
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_Count                           1
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_FieldMask              0xFFFFFFFF
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_ReadMask               0xFFFFFFFF
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_WriteMask              0xFFFFFFFF
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_ResetValue             0x00000000

#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_ADDRESS                      31:0
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_ADDRESS_End                    31
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_ADDRESS_Start                   0
#define MWV207REG_BLT_DEST_TILE_STATUS_ADDRESS_ADDRESS_Type                  U32




#define mwv207regBltDestConfigRegAddrs                                    0x5009
#define MWV207REG_BLT_DEST_CONFIG_Address                                0x14024
#define MWV207REG_BLT_DEST_CONFIG_MSB                                         15
#define MWV207REG_BLT_DEST_CONFIG_LSB                                          0
#define MWV207REG_BLT_DEST_CONFIG_BLK                                          0
#define MWV207REG_BLT_DEST_CONFIG_Count                                        1
#define MWV207REG_BLT_DEST_CONFIG_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_DEST_CONFIG_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_DEST_CONFIG_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_DEST_CONFIG_ResetValue                          0x00000000


#define MWV207REG_BLT_DEST_CONFIG_STRIDE                                    20:0
#define MWV207REG_BLT_DEST_CONFIG_STRIDE_End                                  20
#define MWV207REG_BLT_DEST_CONFIG_STRIDE_Start                                 0
#define MWV207REG_BLT_DEST_CONFIG_STRIDE_Type                                U21


#define MWV207REG_BLT_DEST_CONFIG_FORMAT                                   26:21
#define MWV207REG_BLT_DEST_CONFIG_FORMAT_End                                  26
#define MWV207REG_BLT_DEST_CONFIG_FORMAT_Start                                21
#define MWV207REG_BLT_DEST_CONFIG_FORMAT_Type                                U06
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_X4R4G4B4                         0x00
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_A4R4G4B4                         0x01
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_X1R5G5B5                         0x02
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_A1R5G5B5                         0x03
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_R5G6B5                           0x04
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_X8R8G8B8                         0x05
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_A8R8G8B8                         0x06
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_YUY2                             0x07
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_UYVY                             0x08
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_A8                               0x10
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RF16                             0x11
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RF16GF16                         0x12
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RF16GF16BF16AF16                 0x13
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RF32                             0x14
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RF32GF32                         0x15
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_R10G10B10A2                      0x16
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_D24S8                            0x17
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_D16                              0x18
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_D32FS8                           0x19
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_D32F                             0x1A
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_S8                               0x1B
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI8                              0x1B
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI16GI16BI16AI16                 0x1C
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RF11GF11BF10                     0x1D
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI10GI10BI10AI2                  0x1E
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI8GI8                           0x1F
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_A8L8                             0x20
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_L8                               0x21
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_R8G8B8                           0x22
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_R8                               0x23
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_G8R8                             0x24
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RF32GF32BF32AF32                 0x25
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI32GI32BI32AI32                 0x26
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_R16                              0x27
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RUI32GUI32BUI32AUI32             0x26
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RSI32GSI32BSI32ASI32             0x27
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_NV12                             0x28
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_NV16                             0x29
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_YV12                             0x2A
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI8GI8BI8AI8                     0x2B
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_P010                             0x2C
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI32_NEW                         0x2D
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI32GI32_NEW                     0x2E
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_R16G16                           0x2F
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_R16G16B16A16                     0x30
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI16                             0x31
#define   MWV207REG_BLT_DEST_CONFIG_FORMAT_RI16GI16                         0x32


#define MWV207REG_BLT_DEST_CONFIG_MSAA                                     28:27
#define MWV207REG_BLT_DEST_CONFIG_MSAA_End                                    28
#define MWV207REG_BLT_DEST_CONFIG_MSAA_Start                                  27
#define MWV207REG_BLT_DEST_CONFIG_MSAA_Type                                  U02

#define   MWV207REG_BLT_DEST_CONFIG_MSAA_NONE                                0x0

#define   MWV207REG_BLT_DEST_CONFIG_MSAA_MSAA2X1                             0x1

#define   MWV207REG_BLT_DEST_CONFIG_MSAA_MSAA1X2                             0x2

#define   MWV207REG_BLT_DEST_CONFIG_MSAA_MSAA4                               0x3


#define MWV207REG_BLT_DEST_CONFIG_TILING                                   29:29
#define MWV207REG_BLT_DEST_CONFIG_TILING_End                                  29
#define MWV207REG_BLT_DEST_CONFIG_TILING_Start                                29
#define MWV207REG_BLT_DEST_CONFIG_TILING_Type                                U01
#define   MWV207REG_BLT_DEST_CONFIG_TILING_DISABLED                          0x0
#define   MWV207REG_BLT_DEST_CONFIG_TILING_ENABLE                            0x1


#define MWV207REG_BLT_DEST_CONFIG_SUPER_TILING                             30:30
#define MWV207REG_BLT_DEST_CONFIG_SUPER_TILING_End                            30
#define MWV207REG_BLT_DEST_CONFIG_SUPER_TILING_Start                          30
#define MWV207REG_BLT_DEST_CONFIG_SUPER_TILING_Type                          U01
#define   MWV207REG_BLT_DEST_CONFIG_SUPER_TILING_DISABLED                    0x0
#define   MWV207REG_BLT_DEST_CONFIG_SUPER_TILING_ENABLE                      0x1


#define MWV207REG_BLT_DEST_CONFIG_MULTI_TILING                             31:31
#define MWV207REG_BLT_DEST_CONFIG_MULTI_TILING_End                            31
#define MWV207REG_BLT_DEST_CONFIG_MULTI_TILING_Start                          31
#define MWV207REG_BLT_DEST_CONFIG_MULTI_TILING_Type                          U01
#define   MWV207REG_BLT_DEST_CONFIG_MULTI_TILING_DISABLED                    0x0
#define   MWV207REG_BLT_DEST_CONFIG_MULTI_TILING_ENABLE                      0x1




#define mwv207regBltDestConfigExRegAddrs                                  0x500A
#define MWV207REG_BLT_DEST_CONFIG_EX_Address                             0x14028
#define MWV207REG_BLT_DEST_CONFIG_EX_MSB                                      15
#define MWV207REG_BLT_DEST_CONFIG_EX_LSB                                       0
#define MWV207REG_BLT_DEST_CONFIG_EX_BLK                                       0
#define MWV207REG_BLT_DEST_CONFIG_EX_Count                                     1
#define MWV207REG_BLT_DEST_CONFIG_EX_FieldMask                        0xFFFFFFFF
#define MWV207REG_BLT_DEST_CONFIG_EX_ReadMask                         0xFFFFFFFF
#define MWV207REG_BLT_DEST_CONFIG_EX_WriteMask                        0xFFFFFFFF
#define MWV207REG_BLT_DEST_CONFIG_EX_ResetValue                       0x0001C800


#define MWV207REG_BLT_DEST_CONFIG_EX_FAST_CLEAR                              0:0
#define MWV207REG_BLT_DEST_CONFIG_EX_FAST_CLEAR_End                            0
#define MWV207REG_BLT_DEST_CONFIG_EX_FAST_CLEAR_Start                          0
#define MWV207REG_BLT_DEST_CONFIG_EX_FAST_CLEAR_Type                         U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_FAST_CLEAR_DISABLED                   0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_FAST_CLEAR_ENABLE                     0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_COMPRESSION_EN_C                        1:1
#define MWV207REG_BLT_DEST_CONFIG_EX_COMPRESSION_EN_C_End                      1
#define MWV207REG_BLT_DEST_CONFIG_EX_COMPRESSION_EN_C_Start                    1
#define MWV207REG_BLT_DEST_CONFIG_EX_COMPRESSION_EN_C_Type                   U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_COMPRESSION_EN_C_DISABLE              0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_COMPRESSION_EN_C_ENABLE               0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR128                                2:2
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR128_End                              2
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR128_Start                            2
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR128_Type                           U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR128_DISABLE                      0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR128_ENABLE                       0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_ADDR_REMAP                              3:3
#define MWV207REG_BLT_DEST_CONFIG_EX_ADDR_REMAP_End                            3
#define MWV207REG_BLT_DEST_CONFIG_EX_ADDR_REMAP_Start                          3
#define MWV207REG_BLT_DEST_CONFIG_EX_ADDR_REMAP_Type                         U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_ADDR_REMAP_DISABLED                   0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_ADDR_REMAP_ENABLED                    0x1

#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT                            7:4
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_End                          7
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_Start                        4
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_Type                       U04
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_ARGB4                    0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_A1RGB5                   0x1
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_R5G6B5                   0x2
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_ARGB8                    0x3
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_RGB8                     0x4
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_Z24S8                    0x5
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_Z24                      0x6
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_VAA16                    0x7
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_Z16                      0x8
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_S8                       0x9
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V             0xA
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_UV_MIX                   0xB
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_YUY2                     0xC
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V_P010        0xD
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_UV_MIX_P010              0xE
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_FORMAT_A2RGB10                  0xF


#define MWV207REG_BLT_DEST_CONFIG_EX_SRGB                                    8:8
#define MWV207REG_BLT_DEST_CONFIG_EX_SRGB_End                                  8
#define MWV207REG_BLT_DEST_CONFIG_EX_SRGB_Start                                8
#define MWV207REG_BLT_DEST_CONFIG_EX_SRGB_Type                               U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_SRGB_DISABLE                          0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_SRGB_ENABLE                           0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED                            10:9
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED_End                          10
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED_Start                         9
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED_Type                        U02
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED_RED                       0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED_GREEN                     0x1
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED_BLUE                      0x2
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_RED_ALPHA                     0x3


#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN                         12:11
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN_End                        12
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN_Start                      11
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN_Type                      U02
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN_RED                     0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN_GREEN                   0x1
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN_BLUE                    0x2
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_GREEN_ALPHA                   0x3


#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE                          14:13
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE_End                         14
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE_Start                       13
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE_Type                       U02
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE_RED                      0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE_GREEN                    0x1
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE_BLUE                     0x2
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_BLUE_ALPHA                    0x3


#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA                         16:15
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA_End                        16
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA_Start                      15
#define MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA_Type                      U02
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA_RED                     0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA_GREEN                   0x1
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA_BLUE                    0x2
#define   MWV207REG_BLT_DEST_CONFIG_EX_SWIZZLE_ALPHA_ALPHA                   0x3

#define MWV207REG_BLT_DEST_CONFIG_EX_CACHE_MODE                            17:17
#define MWV207REG_BLT_DEST_CONFIG_EX_CACHE_MODE_End                           17
#define MWV207REG_BLT_DEST_CONFIG_EX_CACHE_MODE_Start                         17
#define MWV207REG_BLT_DEST_CONFIG_EX_CACHE_MODE_Type                         U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_CACHE_MODE_DISABLED                   0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_CACHE_MODE_ENABLE                     0x1

#define MWV207REG_BLT_DEST_CONFIG_EX_UV_SWIZZLE                            18:18
#define MWV207REG_BLT_DEST_CONFIG_EX_UV_SWIZZLE_End                           18
#define MWV207REG_BLT_DEST_CONFIG_EX_UV_SWIZZLE_Start                         18
#define MWV207REG_BLT_DEST_CONFIG_EX_UV_SWIZZLE_Type                         U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_UV_SWIZZLE_DISABLED                   0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_UV_SWIZZLE_ENABLE                     0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_FLIP_Y                                19:19
#define MWV207REG_BLT_DEST_CONFIG_EX_FLIP_Y_End                               19
#define MWV207REG_BLT_DEST_CONFIG_EX_FLIP_Y_Start                             19
#define MWV207REG_BLT_DEST_CONFIG_EX_FLIP_Y_Type                             U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_FLIP_Y_DISABLED                       0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_FLIP_Y_ENABLE                         0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR64                               20:20
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR64_End                              20
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR64_Start                            20
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR64_Type                            U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR64_COLOR16OR32                   0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR64_COLOR64                       0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_DISABLE_SET_SWIZZLE                   21:21
#define MWV207REG_BLT_DEST_CONFIG_EX_DISABLE_SET_SWIZZLE_End                  21
#define MWV207REG_BLT_DEST_CONFIG_EX_DISABLE_SET_SWIZZLE_Start                21
#define MWV207REG_BLT_DEST_CONFIG_EX_DISABLE_SET_SWIZZLE_Type                U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_DISABLE_SET_SWIZZLE_DISABLED          0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_DISABLE_SET_SWIZZLE_ENABLED           0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_BLOCK_SIZE_CONFIG                     22:22
#define MWV207REG_BLT_DEST_CONFIG_EX_BLOCK_SIZE_CONFIG_End                    22
#define MWV207REG_BLT_DEST_CONFIG_EX_BLOCK_SIZE_CONFIG_Start                  22
#define MWV207REG_BLT_DEST_CONFIG_EX_BLOCK_SIZE_CONFIG_Type                  U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_BLOCK_SIZE_CONFIG_DEFAULT             0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_BLOCK_SIZE_CONFIG_CUSTOMIZE           0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL                    24:23
#define MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL_End                   24
#define MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL_Start                 23
#define MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL_Type                 U02
#define   MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL_EXPAND             0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL_ADD_RGB111         0x1
#define   MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL_ADD_RGB212         0x2
#define   MWV207REG_BLT_DEST_CONFIG_EX_CONVERSION_CONTROL_ADD_RGB737         0x3


#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_STATUS4_BIT                      25:25
#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_STATUS4_BIT_End                     25
#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_STATUS4_BIT_Start                   25
#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_STATUS4_BIT_Type                   U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_TILE_STATUS4_BIT_DISABLED             0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_TILE_STATUS4_BIT_ENABLED              0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE                             27:26
#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE_End                            27
#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE_Start                          26
#define MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE_Type                          U02
#define   MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE_TILED4X4                    0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE_SUPER_TILED_XMAJOR          0x1
#define   MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE_SUPER_TILED_YMAJOR          0x2
#define   MWV207REG_BLT_DEST_CONFIG_EX_TILE_MODE_TILED8X8                    0x3


#define MWV207REG_BLT_DEST_CONFIG_EX_MSAA_COMPRESSION                      28:28
#define MWV207REG_BLT_DEST_CONFIG_EX_MSAA_COMPRESSION_End                     28
#define MWV207REG_BLT_DEST_CONFIG_EX_MSAA_COMPRESSION_Start                   28
#define MWV207REG_BLT_DEST_CONFIG_EX_MSAA_COMPRESSION_Type                   U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_MSAA_COMPRESSION_DISABLE              0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_MSAA_COMPRESSION_ENABLE               0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_YMAJOR                          29:29
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_YMAJOR_End                         29
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_YMAJOR_Start                       29
#define MWV207REG_BLT_DEST_CONFIG_EX_COLOR_YMAJOR_Type                       U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_YMAJOR_DISABLE                  0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_COLOR_YMAJOR_ENABLE                   0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_VMSAA                                 30:30
#define MWV207REG_BLT_DEST_CONFIG_EX_VMSAA_End                                30
#define MWV207REG_BLT_DEST_CONFIG_EX_VMSAA_Start                              30
#define MWV207REG_BLT_DEST_CONFIG_EX_VMSAA_Type                              U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_VMSAA_DISABLE                         0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_VMSAA_ENABLE                          0x1


#define MWV207REG_BLT_DEST_CONFIG_EX_DESTINATION_CONTROL                   31:31
#define MWV207REG_BLT_DEST_CONFIG_EX_DESTINATION_CONTROL_End                  31
#define MWV207REG_BLT_DEST_CONFIG_EX_DESTINATION_CONTROL_Start                31
#define MWV207REG_BLT_DEST_CONFIG_EX_DESTINATION_CONTROL_Type                U01
#define   MWV207REG_BLT_DEST_CONFIG_EX_DESTINATION_CONTROL_NOT_READ          0x0
#define   MWV207REG_BLT_DEST_CONFIG_EX_DESTINATION_CONTROL_READ              0x1




#define mwv207regBltDestOriginRegAddrs                                    0x500B
#define MWV207REG_BLT_DEST_ORIGIN_Address                                0x1402C
#define MWV207REG_BLT_DEST_ORIGIN_MSB                                         15
#define MWV207REG_BLT_DEST_ORIGIN_LSB                                          0
#define MWV207REG_BLT_DEST_ORIGIN_BLK                                          0
#define MWV207REG_BLT_DEST_ORIGIN_Count                                        1
#define MWV207REG_BLT_DEST_ORIGIN_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_DEST_ORIGIN_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_DEST_ORIGIN_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_DEST_ORIGIN_ResetValue                          0x00000000


#define MWV207REG_BLT_DEST_ORIGIN_X                                         15:0
#define MWV207REG_BLT_DEST_ORIGIN_X_End                                       15
#define MWV207REG_BLT_DEST_ORIGIN_X_Start                                      0
#define MWV207REG_BLT_DEST_ORIGIN_X_Type                                     U16


#define MWV207REG_BLT_DEST_ORIGIN_Y                                        31:16
#define MWV207REG_BLT_DEST_ORIGIN_Y_End                                       31
#define MWV207REG_BLT_DEST_ORIGIN_Y_Start                                     16
#define MWV207REG_BLT_DEST_ORIGIN_Y_Type                                     U16




#define mwv207regBltWindowSizeRegAddrs                                    0x500C
#define MWV207REG_BLT_WINDOW_SIZE_Address                                0x14030
#define MWV207REG_BLT_WINDOW_SIZE_MSB                                         15
#define MWV207REG_BLT_WINDOW_SIZE_LSB                                          0
#define MWV207REG_BLT_WINDOW_SIZE_BLK                                          0
#define MWV207REG_BLT_WINDOW_SIZE_Count                                        1
#define MWV207REG_BLT_WINDOW_SIZE_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_WINDOW_SIZE_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_WINDOW_SIZE_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_WINDOW_SIZE_ResetValue                          0x00000000


#define MWV207REG_BLT_WINDOW_SIZE_WIDTH                                     15:0
#define MWV207REG_BLT_WINDOW_SIZE_WIDTH_End                                   15
#define MWV207REG_BLT_WINDOW_SIZE_WIDTH_Start                                  0
#define MWV207REG_BLT_WINDOW_SIZE_WIDTH_Type                                 U16


#define MWV207REG_BLT_WINDOW_SIZE_HEIGHT                                   31:16
#define MWV207REG_BLT_WINDOW_SIZE_HEIGHT_End                                  31
#define MWV207REG_BLT_WINDOW_SIZE_HEIGHT_Start                                16
#define MWV207REG_BLT_WINDOW_SIZE_HEIGHT_Type                                U16




#define mwv207regBltSrcClearValueRegAddrs                                 0x500D
#define MWV207REG_BLT_SRC_CLEAR_VALUE_Address                            0x14034
#define MWV207REG_BLT_SRC_CLEAR_VALUE_MSB                                     15
#define MWV207REG_BLT_SRC_CLEAR_VALUE_LSB                                      0
#define MWV207REG_BLT_SRC_CLEAR_VALUE_BLK                                      0
#define MWV207REG_BLT_SRC_CLEAR_VALUE_Count                                    1
#define MWV207REG_BLT_SRC_CLEAR_VALUE_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE_ResetValue                      0x00000000


#define MWV207REG_BLT_SRC_CLEAR_VALUE_VALUE                                 31:0
#define MWV207REG_BLT_SRC_CLEAR_VALUE_VALUE_End                               31
#define MWV207REG_BLT_SRC_CLEAR_VALUE_VALUE_Start                              0
#define MWV207REG_BLT_SRC_CLEAR_VALUE_VALUE_Type                             U32




#define mwv207regBltSrcClearValue64RegAddrs                               0x500E
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_Address                          0x14038
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_MSB                                   15
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_LSB                                    0
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_BLK                                    0
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_Count                                  1
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_ReadMask                      0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_ResetValue                    0x00000000

#define MWV207REG_BLT_SRC_CLEAR_VALUE64_VALUE                               31:0
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_VALUE_End                             31
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_VALUE_Start                            0
#define MWV207REG_BLT_SRC_CLEAR_VALUE64_VALUE_Type                           U32




#define mwv207regBltDstClearValueRegAddrs                                 0x500F
#define MWV207REG_BLT_DST_CLEAR_VALUE_Address                            0x1403C
#define MWV207REG_BLT_DST_CLEAR_VALUE_MSB                                     15
#define MWV207REG_BLT_DST_CLEAR_VALUE_LSB                                      0
#define MWV207REG_BLT_DST_CLEAR_VALUE_BLK                                      0
#define MWV207REG_BLT_DST_CLEAR_VALUE_Count                                    1
#define MWV207REG_BLT_DST_CLEAR_VALUE_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE_ResetValue                      0x00000000


#define MWV207REG_BLT_DST_CLEAR_VALUE_VALUE                                 31:0
#define MWV207REG_BLT_DST_CLEAR_VALUE_VALUE_End                               31
#define MWV207REG_BLT_DST_CLEAR_VALUE_VALUE_Start                              0
#define MWV207REG_BLT_DST_CLEAR_VALUE_VALUE_Type                             U32




#define mwv207regBltDstClearValue64RegAddrs                               0x5010
#define MWV207REG_BLT_DST_CLEAR_VALUE64_Address                          0x14040
#define MWV207REG_BLT_DST_CLEAR_VALUE64_MSB                                   15
#define MWV207REG_BLT_DST_CLEAR_VALUE64_LSB                                    0
#define MWV207REG_BLT_DST_CLEAR_VALUE64_BLK                                    0
#define MWV207REG_BLT_DST_CLEAR_VALUE64_Count                                  1
#define MWV207REG_BLT_DST_CLEAR_VALUE64_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE64_ReadMask                      0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE64_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE64_ResetValue                    0x00000000

#define MWV207REG_BLT_DST_CLEAR_VALUE64_VALUE                               31:0
#define MWV207REG_BLT_DST_CLEAR_VALUE64_VALUE_End                             31
#define MWV207REG_BLT_DST_CLEAR_VALUE64_VALUE_Start                            0
#define MWV207REG_BLT_DST_CLEAR_VALUE64_VALUE_Type                           U32




#define mwv207regBltNewClearValueRegAddrs                                 0x5011
#define MWV207REG_BLT_NEW_CLEAR_VALUE_Address                            0x14044
#define MWV207REG_BLT_NEW_CLEAR_VALUE_MSB                                     15
#define MWV207REG_BLT_NEW_CLEAR_VALUE_LSB                                      0
#define MWV207REG_BLT_NEW_CLEAR_VALUE_BLK                                      0
#define MWV207REG_BLT_NEW_CLEAR_VALUE_Count                                    1
#define MWV207REG_BLT_NEW_CLEAR_VALUE_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE_ResetValue                      0x00000000


#define MWV207REG_BLT_NEW_CLEAR_VALUE_VALUE                                 31:0
#define MWV207REG_BLT_NEW_CLEAR_VALUE_VALUE_End                               31
#define MWV207REG_BLT_NEW_CLEAR_VALUE_VALUE_Start                              0
#define MWV207REG_BLT_NEW_CLEAR_VALUE_VALUE_Type                             U32




#define mwv207regBltNewClearValue64RegAddrs                               0x5012
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_Address                          0x14048
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_MSB                                   15
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_LSB                                    0
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_BLK                                    0
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_Count                                  1
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_ReadMask                      0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_ResetValue                    0x00000000

#define MWV207REG_BLT_NEW_CLEAR_VALUE64_VALUE                               31:0
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_VALUE_End                             31
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_VALUE_Start                            0
#define MWV207REG_BLT_NEW_CLEAR_VALUE64_VALUE_Type                           U32




#define mwv207regBltClearMaskRegAddrs                                     0x5013
#define MWV207REG_BLT_CLEAR_MASK_Address                                 0x1404C
#define MWV207REG_BLT_CLEAR_MASK_MSB                                          15
#define MWV207REG_BLT_CLEAR_MASK_LSB                                           0
#define MWV207REG_BLT_CLEAR_MASK_BLK                                           0
#define MWV207REG_BLT_CLEAR_MASK_Count                                         1
#define MWV207REG_BLT_CLEAR_MASK_FieldMask                            0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK_ReadMask                             0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK_WriteMask                            0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK_ResetValue                           0x00000000


#define MWV207REG_BLT_CLEAR_MASK_MASK                                       31:0
#define MWV207REG_BLT_CLEAR_MASK_MASK_End                                     31
#define MWV207REG_BLT_CLEAR_MASK_MASK_Start                                    0
#define MWV207REG_BLT_CLEAR_MASK_MASK_Type                                   U32




#define mwv207regBltClearMask64RegAddrs                                   0x5014
#define MWV207REG_BLT_CLEAR_MASK64_Address                               0x14050
#define MWV207REG_BLT_CLEAR_MASK64_MSB                                        15
#define MWV207REG_BLT_CLEAR_MASK64_LSB                                         0
#define MWV207REG_BLT_CLEAR_MASK64_BLK                                         0
#define MWV207REG_BLT_CLEAR_MASK64_Count                                       1
#define MWV207REG_BLT_CLEAR_MASK64_FieldMask                          0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK64_ReadMask                           0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK64_WriteMask                          0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK64_ResetValue                         0x00000000


#define MWV207REG_BLT_CLEAR_MASK64_MASK                                     31:0
#define MWV207REG_BLT_CLEAR_MASK64_MASK_End                                   31
#define MWV207REG_BLT_CLEAR_MASK64_MASK_Start                                  0
#define MWV207REG_BLT_CLEAR_MASK64_MASK_Type                                 U32




#define mwv207regBltDitherLowRegAddrs                                     0x5016
#define MWV207REG_BLT_DITHER_LOW_Address                                 0x14058
#define MWV207REG_BLT_DITHER_LOW_MSB                                          15
#define MWV207REG_BLT_DITHER_LOW_LSB                                           0
#define MWV207REG_BLT_DITHER_LOW_BLK                                           0
#define MWV207REG_BLT_DITHER_LOW_Count                                         1
#define MWV207REG_BLT_DITHER_LOW_FieldMask                            0xFFFFFFFF
#define MWV207REG_BLT_DITHER_LOW_ReadMask                             0xFFFFFFFF
#define MWV207REG_BLT_DITHER_LOW_WriteMask                            0xFFFFFFFF
#define MWV207REG_BLT_DITHER_LOW_ResetValue                           0x00000000


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y0                                 3:0
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y0_End                               3
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y0_Start                             0
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y0_Type                            U04


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y0                                 7:4
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y0_End                               7
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y0_Start                             4
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y0_Type                            U04


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y0                                11:8
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y0_End                              11
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y0_Start                             8
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y0_Type                            U04


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y0                               15:12
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y0_End                              15
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y0_Start                            12
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y0_Type                            U04


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y1                               19:16
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y1_End                              19
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y1_Start                            16
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X0_Y1_Type                            U04


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y1                               23:20
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y1_End                              23
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y1_Start                            20
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X1_Y1_Type                            U04


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y1                               27:24
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y1_End                              27
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y1_Start                            24
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X2_Y1_Type                            U04


#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y1                               31:28
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y1_End                              31
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y1_Start                            28
#define MWV207REG_BLT_DITHER_LOW_PIXEL_X3_Y1_Type                            U04

#define mwv207regBltDitherHighRegAddrs                                    0x5017
#define MWV207REG_BLT_DITHER_HIGH_Address                                0x1405C
#define MWV207REG_BLT_DITHER_HIGH_MSB                                         15
#define MWV207REG_BLT_DITHER_HIGH_LSB                                          0
#define MWV207REG_BLT_DITHER_LOW_HIGH_BLK                                      0
#define MWV207REG_BLT_DITHER_HIGH_Count                                        1
#define MWV207REG_BLT_DITHER_HIGH_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_DITHER_HIGH_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_DITHER_HIGH_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_DITHER_HIGH_ResetValue                          0x00000000


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y2                                3:0
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y2_End                              3
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y2_Start                            0
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y2_Type                           U04


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y2                                7:4
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y2_End                              7
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y2_Start                            4
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y2_Type                           U04


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y2                               11:8
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y2_End                             11
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y2_Start                            8
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y2_Type                           U04


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y2                              15:12
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y2_End                             15
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y2_Start                           12
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y2_Type                           U04


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y3                              19:16
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y3_End                             19
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y3_Start                           16
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X0_Y3_Type                           U04


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y3                              23:20
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y3_End                             23
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y3_Start                           20
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X1_Y3_Type                           U04


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y3                              27:24
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y3_End                             27
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y3_Start                           24
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X2_Y3_Type                           U04


#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y3                              31:28
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y3_End                             31
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y3_Start                           28
#define MWV207REG_BLT_DITHER_HIGH_PIXEL_X3_Y3_Type                           U04

#define mwv207regBltCopySizeRegAddrs                                      0x5015
#define MWV207REG_BLT_COPY_SIZE_Address                                  0x14054
#define MWV207REG_BLT_COPY_SIZE_MSB                                           15
#define MWV207REG_BLT_COPY_SIZE_LSB                                            0
#define MWV207REG_BLT_COPY_SIZE_BLK                                            0
#define MWV207REG_BLT_COPY_SIZE_Count                                          1
#define MWV207REG_BLT_COPY_SIZE_FieldMask                             0xFFFFFFFF
#define MWV207REG_BLT_COPY_SIZE_ReadMask                              0xFFFFFFFF
#define MWV207REG_BLT_COPY_SIZE_WriteMask                             0xFFFFFFFF
#define MWV207REG_BLT_COPY_SIZE_ResetValue                            0x00000000


#define MWV207REG_BLT_COPY_SIZE_SIZE                                        31:0
#define MWV207REG_BLT_COPY_SIZE_SIZE_End                                      31
#define MWV207REG_BLT_COPY_SIZE_SIZE_Start                                     0
#define MWV207REG_BLT_COPY_SIZE_SIZE_Type                                    U32




#define mwv207regBltExecuteRegAddrs                                       0x5018
#define MWV207REG_BLT_EXECUTE_Address                                    0x14060
#define MWV207REG_BLT_EXECUTE_MSB                                             15
#define MWV207REG_BLT_EXECUTE_LSB                                              0
#define MWV207REG_BLT_EXECUTE_BLK                                              0
#define MWV207REG_BLT_EXECUTE_Count                                            1
#define MWV207REG_BLT_EXECUTE_FieldMask                               0xFF11F197
#define MWV207REG_BLT_EXECUTE_ReadMask                                0xFF11F197
#define MWV207REG_BLT_EXECUTE_WriteMask                               0xFF11F197
#define MWV207REG_BLT_EXECUTE_ResetValue                              0x00000000


#define MWV207REG_BLT_EXECUTE_COMMAND                                        2:0
#define MWV207REG_BLT_EXECUTE_COMMAND_End                                      2
#define MWV207REG_BLT_EXECUTE_COMMAND_Start                                    0
#define MWV207REG_BLT_EXECUTE_COMMAND_Type                                   U03

#define   MWV207REG_BLT_EXECUTE_COMMAND_CLEAR                                0x1

#define   MWV207REG_BLT_EXECUTE_COMMAND_BLT                                  0x2

#define   MWV207REG_BLT_EXECUTE_COMMAND_COPY                                 0x3

#define   MWV207REG_BLT_EXECUTE_COMMAND_TILE_FILLER                          0x4

#define   MWV207REG_BLT_EXECUTE_COMMAND_YUV_TILER                            0x5

#define   MWV207REG_BLT_EXECUTE_COMMAND_MIPMAP                               0x6


#define MWV207REG_BLT_EXECUTE_DITHER                                         4:4
#define MWV207REG_BLT_EXECUTE_DITHER_End                                       4
#define MWV207REG_BLT_EXECUTE_DITHER_Start                                     4
#define MWV207REG_BLT_EXECUTE_DITHER_Type                                    U01

#define   MWV207REG_BLT_EXECUTE_DITHER_DISABLED                              0x0

#define   MWV207REG_BLT_EXECUTE_DITHER_ENABLED                               0x1


#define MWV207REG_BLT_EXECUTE_FENCE                                          7:7
#define MWV207REG_BLT_EXECUTE_FENCE_End                                        7
#define MWV207REG_BLT_EXECUTE_FENCE_Start                                      7
#define MWV207REG_BLT_EXECUTE_FENCE_Type                                     U01


#define MWV207REG_BLT_EXECUTE_INTERRUPT                                      8:8
#define MWV207REG_BLT_EXECUTE_INTERRUPT_End                                    8
#define MWV207REG_BLT_EXECUTE_INTERRUPT_Start                                  8
#define MWV207REG_BLT_EXECUTE_INTERRUPT_Type                                 U01


#define MWV207REG_BLT_EXECUTE_INTERRUPT_NUMBER                             16:12
#define MWV207REG_BLT_EXECUTE_INTERRUPT_NUMBER_End                            16
#define MWV207REG_BLT_EXECUTE_INTERRUPT_NUMBER_Start                          12
#define MWV207REG_BLT_EXECUTE_INTERRUPT_NUMBER_Type                          U05


#define MWV207REG_BLT_EXECUTE_SEMAPHORE                                    20:20
#define MWV207REG_BLT_EXECUTE_SEMAPHORE_End                                   20
#define MWV207REG_BLT_EXECUTE_SEMAPHORE_Start                                 20
#define MWV207REG_BLT_EXECUTE_SEMAPHORE_Type                                 U01


#define MWV207REG_BLT_EXECUTE_SEMAPHORE_NUMBER                             31:24
#define MWV207REG_BLT_EXECUTE_SEMAPHORE_NUMBER_End                            31
#define MWV207REG_BLT_EXECUTE_SEMAPHORE_NUMBER_Start                          24
#define MWV207REG_BLT_EXECUTE_SEMAPHORE_NUMBER_Type                          U08




#define mwv207regBltGammaTableRegAddrs                                    0x5040
#define MWV207REG_BLT_GAMMA_TABLE_Address                                0x14100
#define MWV207REG_BLT_GAMMA_TABLE_MSB                                         15
#define MWV207REG_BLT_GAMMA_TABLE_LSB                                          6
#define MWV207REG_BLT_GAMMA_TABLE_BLK                                          6
#define MWV207REG_BLT_GAMMA_TABLE_Count                                       64
#define MWV207REG_BLT_GAMMA_TABLE_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_GAMMA_TABLE_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_GAMMA_TABLE_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_GAMMA_TABLE_ResetValue                          0x00000000


#define MWV207REG_BLT_GAMMA_TABLE_DATA0                                      7:0
#define MWV207REG_BLT_GAMMA_TABLE_DATA0_End                                    7
#define MWV207REG_BLT_GAMMA_TABLE_DATA0_Start                                  0
#define MWV207REG_BLT_GAMMA_TABLE_DATA0_Type                                 U08


#define MWV207REG_BLT_GAMMA_TABLE_DATA1                                     15:8
#define MWV207REG_BLT_GAMMA_TABLE_DATA1_End                                   15
#define MWV207REG_BLT_GAMMA_TABLE_DATA1_Start                                  8
#define MWV207REG_BLT_GAMMA_TABLE_DATA1_Type                                 U08


#define MWV207REG_BLT_GAMMA_TABLE_DATA2                                    23:16
#define MWV207REG_BLT_GAMMA_TABLE_DATA2_End                                   23
#define MWV207REG_BLT_GAMMA_TABLE_DATA2_Start                                 16
#define MWV207REG_BLT_GAMMA_TABLE_DATA2_Type                                 U08


#define MWV207REG_BLT_GAMMA_TABLE_DATA3                                    31:24
#define MWV207REG_BLT_GAMMA_TABLE_DATA3_End                                   31
#define MWV207REG_BLT_GAMMA_TABLE_DATA3_Start                                 24
#define MWV207REG_BLT_GAMMA_TABLE_DATA3_Type                                 U08




#define mwv207regBltDegammaTableRegAddrs                                  0x5080
#define MWV207REG_BLT_DEGAMMA_TABLE_Address                              0x14200
#define MWV207REG_BLT_DEGAMMA_TABLE_MSB                                       15
#define MWV207REG_BLT_DEGAMMA_TABLE_LSB                                        6
#define MWV207REG_BLT_DEGAMMA_TABLE_BLK                                        6
#define MWV207REG_BLT_DEGAMMA_TABLE_Count                                     64
#define MWV207REG_BLT_DEGAMMA_TABLE_FieldMask                         0xFFFFFFFF
#define MWV207REG_BLT_DEGAMMA_TABLE_ReadMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEGAMMA_TABLE_WriteMask                         0xFFFFFFFF
#define MWV207REG_BLT_DEGAMMA_TABLE_ResetValue                        0x00000000


#define MWV207REG_BLT_DEGAMMA_TABLE_DATA0                                    7:0
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA0_End                                  7
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA0_Start                                0
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA0_Type                               U08


#define MWV207REG_BLT_DEGAMMA_TABLE_DATA1                                   15:8
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA1_End                                 15
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA1_Start                                8
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA1_Type                               U08


#define MWV207REG_BLT_DEGAMMA_TABLE_DATA2                                  23:16
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA2_End                                 23
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA2_Start                               16
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA2_Type                               U08


#define MWV207REG_BLT_DEGAMMA_TABLE_DATA3                                  31:24
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA3_End                                 31
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA3_Start                               24
#define MWV207REG_BLT_DEGAMMA_TABLE_DATA3_Type                               U08




#define mwv207regBltGeneralConfigRegAddrs                                 0x5019
#define MWV207REG_BLT_GENERAL_CONFIG_Address                             0x14064
#define MWV207REG_BLT_GENERAL_CONFIG_MSB                                      15
#define MWV207REG_BLT_GENERAL_CONFIG_LSB                                       0
#define MWV207REG_BLT_GENERAL_CONFIG_BLK                                       0
#define MWV207REG_BLT_GENERAL_CONFIG_Count                                     1
#define MWV207REG_BLT_GENERAL_CONFIG_FieldMask                        0x01FFFFFF
#define MWV207REG_BLT_GENERAL_CONFIG_ReadMask                         0x01FFFFFF
#define MWV207REG_BLT_GENERAL_CONFIG_WriteMask                        0x01FFFFFF
#define MWV207REG_BLT_GENERAL_CONFIG_ResetValue                       0x00000000


#define MWV207REG_BLT_GENERAL_CONFIG_YUVSTANDARD                             0:0
#define MWV207REG_BLT_GENERAL_CONFIG_YUVSTANDARD_End                           0
#define MWV207REG_BLT_GENERAL_CONFIG_YUVSTANDARD_Start                         0
#define MWV207REG_BLT_GENERAL_CONFIG_YUVSTANDARD_Type                        U01
#define   MWV207REG_BLT_GENERAL_CONFIG_YUVSTANDARD_YUV601                    0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_YUVSTANDARD_YUV709                    0x1


#define MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL                   2:1
#define MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL_End                 2
#define MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL_Start               1
#define MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL_Type              U02
#define   MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL_NO_SWAP         0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL_SWAP_WORD       0x1
#define   MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL_SWAP_DWORD      0x2
#define   MWV207REG_BLT_GENERAL_CONFIG_SOURCE_ENDIAN_CONTROL_SWAP_DDWORD     0x3


#define MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL              4:3
#define MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL_End            4
#define MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL_Start          3
#define MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL_Type         U02
#define   MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL_NO_SWAP    0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL_SWAP_WORD  0x1
#define   MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL_SWAP_DWORD 0x2
#define   MWV207REG_BLT_GENERAL_CONFIG_DESTINATION_ENDIAN_CONTROL_SWAP_DDWORD 0x3


#define MWV207REG_BLT_GENERAL_CONFIG_INTERLEAVING                            6:5
#define MWV207REG_BLT_GENERAL_CONFIG_INTERLEAVING_End                          6
#define MWV207REG_BLT_GENERAL_CONFIG_INTERLEAVING_Start                        5
#define MWV207REG_BLT_GENERAL_CONFIG_INTERLEAVING_Type                       U02
#define   MWV207REG_BLT_GENERAL_CONFIG_INTERLEAVING_OFF                      0x0

#define   MWV207REG_BLT_GENERAL_CONFIG_INTERLEAVING_PARALLAX                 0x1

#define   MWV207REG_BLT_GENERAL_CONFIG_INTERLEAVING_HONEYCOMB                0x2


#define MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP                          9:7
#define MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_End                        9
#define MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_Start                      7
#define MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_Type                     U03
#define   MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_ONE_BYTE               0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_TWO_BYTE               0x1
#define   MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_THREE_BYTE             0x2
#define   MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_FOUR_BYTE              0x3
#define   MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_SIXTH_BYTE             0x6
#define   MWV207REG_BLT_GENERAL_CONFIG_CLEAR_DEST_BPP_EIGHT_BYTE             0x7


#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_TILE_SIZE                      10:10
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_TILE_SIZE_End                     10
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_TILE_SIZE_Start                   10
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_TILE_SIZE_Type                   U01

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_TILE_SIZE_TILE64               0x0

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_TILE_SIZE_TILE256              0x1


#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_FORMAT                         11:11
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_FORMAT_End                        11
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_FORMAT_Start                      11
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_FORMAT_Type                      U01

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_FORMAT_FILLER32                0x0

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_FORMAT_FILLER64                0x1


#define MWV207REG_BLT_GENERAL_CONFIG_FILTER_TYPE                           12:12
#define MWV207REG_BLT_GENERAL_CONFIG_FILTER_TYPE_End                          12
#define MWV207REG_BLT_GENERAL_CONFIG_FILTER_TYPE_Start                        12
#define MWV207REG_BLT_GENERAL_CONFIG_FILTER_TYPE_Type                        U01

#define   MWV207REG_BLT_GENERAL_CONFIG_FILTER_TYPE_AVERAGE                   0x0

#define   MWV207REG_BLT_GENERAL_CONFIG_FILTER_TYPE_SAMPLE                    0x1


#define MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL                  14:13
#define MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL_End                 14
#define MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL_Start               13
#define MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL_Type               U02
#define   MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL_NO_SWAP          0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL_SWAP_WORD        0x1
#define   MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL_SWAP_DWORD       0x2
#define   MWV207REG_BLT_GENERAL_CONFIG_FENCE_ENDIAN_CONTROL_SWAP_DDWORD      0x3


#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP                            17:15
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_End                           17
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_Start                         15
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_Type                         U03

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_FILLER8_BPP                0x0

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_FILLER16_BPP               0x1

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_FILLER32_BPP               0x2

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_FILLER64_BPP               0x3

#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER_BPP_FILLER128_BPP              0x4


#define MWV207REG_BLT_GENERAL_CONFIG_TILE_STATUS4_BIT                      18:18
#define MWV207REG_BLT_GENERAL_CONFIG_TILE_STATUS4_BIT_End                     18
#define MWV207REG_BLT_GENERAL_CONFIG_TILE_STATUS4_BIT_Start                   18
#define MWV207REG_BLT_GENERAL_CONFIG_TILE_STATUS4_BIT_Type                   U01
#define   MWV207REG_BLT_GENERAL_CONFIG_TILE_STATUS4_BIT_DISABLED             0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_TILE_STATUS4_BIT_ENABLED              0x1


#define MWV207REG_BLT_GENERAL_CONFIG_FILLER128                             19:19
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER128_End                            19
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER128_Start                          19
#define MWV207REG_BLT_GENERAL_CONFIG_FILLER128_Type                          U01
#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER128_DISABLED                    0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_FILLER128_ENABLED                     0x1


#define MWV207REG_BLT_GENERAL_CONFIG_SRC_SIGN                              20:20
#define MWV207REG_BLT_GENERAL_CONFIG_SRC_SIGN_End                             20
#define MWV207REG_BLT_GENERAL_CONFIG_SRC_SIGN_Start                           20
#define MWV207REG_BLT_GENERAL_CONFIG_SRC_SIGN_Type                           U01
#define   MWV207REG_BLT_GENERAL_CONFIG_SRC_SIGN_UNSIGN                       0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_SRC_SIGN_SIGN                         0x1


#define MWV207REG_BLT_GENERAL_CONFIG_DEST_SIGN                             21:21
#define MWV207REG_BLT_GENERAL_CONFIG_DEST_SIGN_End                            21
#define MWV207REG_BLT_GENERAL_CONFIG_DEST_SIGN_Start                          21
#define MWV207REG_BLT_GENERAL_CONFIG_DEST_SIGN_Type                          U01
#define   MWV207REG_BLT_GENERAL_CONFIG_DEST_SIGN_UNSIGN                      0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_DEST_SIGN_SIGN                        0x1


#define MWV207REG_BLT_GENERAL_CONFIG_SRC1_SIGN                             22:22
#define MWV207REG_BLT_GENERAL_CONFIG_SRC1_SIGN_End                            22
#define MWV207REG_BLT_GENERAL_CONFIG_SRC1_SIGN_Start                          22
#define MWV207REG_BLT_GENERAL_CONFIG_SRC1_SIGN_Type                          U01
#define   MWV207REG_BLT_GENERAL_CONFIG_SRC1_SIGN_UNSIGN                      0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_SRC1_SIGN_SIGN                        0x1


#define MWV207REG_BLT_GENERAL_CONFIG_DEST1_SIGN                            23:23
#define MWV207REG_BLT_GENERAL_CONFIG_DEST1_SIGN_End                           23
#define MWV207REG_BLT_GENERAL_CONFIG_DEST1_SIGN_Start                         23
#define MWV207REG_BLT_GENERAL_CONFIG_DEST1_SIGN_Type                         U01
#define   MWV207REG_BLT_GENERAL_CONFIG_DEST1_SIGN_UNSIGN                     0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_DEST1_SIGN_SIGN                       0x1


#define MWV207REG_BLT_GENERAL_CONFIG_DEST_DEPTH_ADDR_REMAP                 24:24
#define MWV207REG_BLT_GENERAL_CONFIG_DEST_DEPTH_ADDR_REMAP_End                24
#define MWV207REG_BLT_GENERAL_CONFIG_DEST_DEPTH_ADDR_REMAP_Start              24
#define MWV207REG_BLT_GENERAL_CONFIG_DEST_DEPTH_ADDR_REMAP_Type              U01
#define   MWV207REG_BLT_GENERAL_CONFIG_DEST_DEPTH_ADDR_REMAP_DISABLED        0x0
#define   MWV207REG_BLT_GENERAL_CONFIG_DEST_DEPTH_ADDR_REMAP_ENABLED         0x1




#define mwv207regBltTileFillerCountRegAddrs                               0x501A
#define MWV207REG_BLT_TILE_FILLER_COUNT_Address                          0x14068
#define MWV207REG_BLT_TILE_FILLER_COUNT_MSB                                   15
#define MWV207REG_BLT_TILE_FILLER_COUNT_LSB                                    0
#define MWV207REG_BLT_TILE_FILLER_COUNT_BLK                                    0
#define MWV207REG_BLT_TILE_FILLER_COUNT_Count                                  1
#define MWV207REG_BLT_TILE_FILLER_COUNT_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_TILE_FILLER_COUNT_ReadMask                      0x00000000
#define MWV207REG_BLT_TILE_FILLER_COUNT_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_TILE_FILLER_COUNT_ResetValue                    0x00000000


#define MWV207REG_BLT_TILE_FILLER_COUNT_TILE_COUNT                          31:0
#define MWV207REG_BLT_TILE_FILLER_COUNT_TILE_COUNT_End                        31
#define MWV207REG_BLT_TILE_FILLER_COUNT_TILE_COUNT_Start                       0
#define MWV207REG_BLT_TILE_FILLER_COUNT_TILE_COUNT_Type                      U32




#define mwv207regBltYUVTilerConfigRegAddrs                                0x501B
#define MWV207REG_BLT_YUV_TILER_CONFIG_Address                           0x1406C
#define MWV207REG_BLT_YUV_TILER_CONFIG_MSB                                    15
#define MWV207REG_BLT_YUV_TILER_CONFIG_LSB                                     0
#define MWV207REG_BLT_YUV_TILER_CONFIG_BLK                                     0
#define MWV207REG_BLT_YUV_TILER_CONFIG_Count                                   1
#define MWV207REG_BLT_YUV_TILER_CONFIG_FieldMask                      0x0007B931
#define MWV207REG_BLT_YUV_TILER_CONFIG_ReadMask                       0x0007B931
#define MWV207REG_BLT_YUV_TILER_CONFIG_WriteMask                      0x0007B931
#define MWV207REG_BLT_YUV_TILER_CONFIG_ResetValue                     0x00000000

#define MWV207REG_BLT_YUV_TILER_CONFIG_TILER                                 0:0
#define MWV207REG_BLT_YUV_TILER_CONFIG_TILER_End                               0
#define MWV207REG_BLT_YUV_TILER_CONFIG_TILER_Start                             0
#define MWV207REG_BLT_YUV_TILER_CONFIG_TILER_Type                            U01
#define   MWV207REG_BLT_YUV_TILER_CONFIG_TILER_DISABLED                      0x0
#define   MWV207REG_BLT_YUV_TILER_CONFIG_TILER_ENABLED                       0x1

#define MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT                                5:4
#define MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT_End                              5
#define MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT_Start                            4
#define MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT_Type                           U02
#define   MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT_YV12                         0x0
#define   MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT_NV12                         0x1
#define   MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT_NV16                         0x2
#define   MWV207REG_BLT_YUV_TILER_CONFIG_FORMAT_P010                         0x3

#define MWV207REG_BLT_YUV_TILER_CONFIG_UVSWIZZLE                             8:8
#define MWV207REG_BLT_YUV_TILER_CONFIG_UVSWIZZLE_End                           8
#define MWV207REG_BLT_YUV_TILER_CONFIG_UVSWIZZLE_Start                         8
#define MWV207REG_BLT_YUV_TILER_CONFIG_UVSWIZZLE_Type                        U01
#define   MWV207REG_BLT_YUV_TILER_CONFIG_UVSWIZZLE_UV                        0x0
#define   MWV207REG_BLT_YUV_TILER_CONFIG_UVSWIZZLE_VU                        0x1

#define MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION                     13:11
#define MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_End                    13
#define MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_Start                  11
#define MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_Type                  U03
#define   MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_YUV                 0x0
#define   MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_Y                   0x1
#define   MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_U                   0x2
#define   MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_V                   0x3
#define   MWV207REG_BLT_YUV_TILER_CONFIG_PLANARSELECTION_UV                  0x4


#define MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE                           16:15
#define MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE_End                          16
#define MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE_Start                        15
#define MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE_Type                        U02
#define   MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE_TILED4X4                  0x0
#define   MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE_SUPER_TILED_XMAJOR        0x1
#define   MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE_SUPER_TILED_YMAJOR        0x2
#define   MWV207REG_BLT_YUV_TILER_CONFIG_TILE_MODE_TILED8X8                  0x3

#define MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION                            18:17
#define MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION_End                           18
#define MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION_Start                         17
#define MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION_Type                         U02
#define   MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION_DEGREE0                    0x0
#define   MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION_DEGREE90                   0x1
#define   MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION_DEGREE180                  0x2
#define   MWV207REG_BLT_YUV_TILER_CONFIG_ROTATION_DEGREE270                  0x3




#define mwv207regBltYUVTilerSizeRegAddrs                                  0x501C
#define MWV207REG_BLT_YUV_TILER_SIZE_Address                             0x14070
#define MWV207REG_BLT_YUV_TILER_SIZE_MSB                                      15
#define MWV207REG_BLT_YUV_TILER_SIZE_LSB                                       0
#define MWV207REG_BLT_YUV_TILER_SIZE_BLK                                       0
#define MWV207REG_BLT_YUV_TILER_SIZE_Count                                     1
#define MWV207REG_BLT_YUV_TILER_SIZE_FieldMask                        0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_SIZE_ReadMask                         0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_SIZE_WriteMask                        0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_SIZE_ResetValue                       0x00000000

#define MWV207REG_BLT_YUV_TILER_SIZE_WIDTH                                  15:0
#define MWV207REG_BLT_YUV_TILER_SIZE_WIDTH_End                                15
#define MWV207REG_BLT_YUV_TILER_SIZE_WIDTH_Start                               0
#define MWV207REG_BLT_YUV_TILER_SIZE_WIDTH_Type                              U16

#define MWV207REG_BLT_YUV_TILER_SIZE_HEIGHT                                31:16
#define MWV207REG_BLT_YUV_TILER_SIZE_HEIGHT_End                               31
#define MWV207REG_BLT_YUV_TILER_SIZE_HEIGHT_Start                             16
#define MWV207REG_BLT_YUV_TILER_SIZE_HEIGHT_Type                             U16




#define mwv207regBltYUVTilerYbaseRegAddrs                                 0x501D
#define MWV207REG_BLT_YUV_TILER_YBASE_Address                            0x14074
#define MWV207REG_BLT_YUV_TILER_YBASE_MSB                                     15
#define MWV207REG_BLT_YUV_TILER_YBASE_LSB                                      0
#define MWV207REG_BLT_YUV_TILER_YBASE_BLK                                      0
#define MWV207REG_BLT_YUV_TILER_YBASE_Count                                    1
#define MWV207REG_BLT_YUV_TILER_YBASE_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_YBASE_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_YBASE_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_YBASE_ResetValue                      0x00000000

#define MWV207REG_BLT_YUV_TILER_YBASE_ADDRESS                               31:0
#define MWV207REG_BLT_YUV_TILER_YBASE_ADDRESS_End                             31
#define MWV207REG_BLT_YUV_TILER_YBASE_ADDRESS_Start                            0
#define MWV207REG_BLT_YUV_TILER_YBASE_ADDRESS_Type                           U32




#define mwv207regBltYUVTilerYstrideRegAddrs                               0x501E
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_Address                          0x14078
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_MSB                                   15
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_LSB                                    0
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_BLK                                    0
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_Count                                  1
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_FieldMask                     0x0003FFFF
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_ReadMask                      0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_WriteMask                     0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_ResetValue                    0x00000000

#define MWV207REG_BLT_YUV_TILER_YSTRIDE_STRIDE                              17:0
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_STRIDE_End                            17
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_STRIDE_Start                           0
#define MWV207REG_BLT_YUV_TILER_YSTRIDE_STRIDE_Type                          U18




#define mwv207regBltYUVTilerUbaseRegAddrs                                 0x501F
#define MWV207REG_BLT_YUV_TILER_UBASE_Address                            0x1407C
#define MWV207REG_BLT_YUV_TILER_UBASE_MSB                                     15
#define MWV207REG_BLT_YUV_TILER_UBASE_LSB                                      0
#define MWV207REG_BLT_YUV_TILER_UBASE_BLK                                      0
#define MWV207REG_BLT_YUV_TILER_UBASE_Count                                    1
#define MWV207REG_BLT_YUV_TILER_UBASE_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_UBASE_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_UBASE_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_UBASE_ResetValue                      0x00000000

#define MWV207REG_BLT_YUV_TILER_UBASE_ADDRESS                               31:0
#define MWV207REG_BLT_YUV_TILER_UBASE_ADDRESS_End                             31
#define MWV207REG_BLT_YUV_TILER_UBASE_ADDRESS_Start                            0
#define MWV207REG_BLT_YUV_TILER_UBASE_ADDRESS_Type                           U32




#define mwv207regBltYUVTilerUstrideRegAddrs                               0x5020
#define MWV207REG_BLT_YUV_TILER_USTRIDE_Address                          0x14080
#define MWV207REG_BLT_YUV_TILER_USTRIDE_MSB                                   15
#define MWV207REG_BLT_YUV_TILER_USTRIDE_LSB                                    0
#define MWV207REG_BLT_YUV_TILER_USTRIDE_BLK                                    0
#define MWV207REG_BLT_YUV_TILER_USTRIDE_Count                                  1
#define MWV207REG_BLT_YUV_TILER_USTRIDE_FieldMask                     0x0003FFFF
#define MWV207REG_BLT_YUV_TILER_USTRIDE_ReadMask                      0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_USTRIDE_WriteMask                     0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_USTRIDE_ResetValue                    0x00000000

#define MWV207REG_BLT_YUV_TILER_USTRIDE_STRIDE                              17:0
#define MWV207REG_BLT_YUV_TILER_USTRIDE_STRIDE_End                            17
#define MWV207REG_BLT_YUV_TILER_USTRIDE_STRIDE_Start                           0
#define MWV207REG_BLT_YUV_TILER_USTRIDE_STRIDE_Type                          U18




#define mwv207regBltYUVTilerVbaseRegAddrs                                 0x5021
#define MWV207REG_BLT_YUV_TILER_VBASE_Address                            0x14084
#define MWV207REG_BLT_YUV_TILER_VBASE_MSB                                     15
#define MWV207REG_BLT_YUV_TILER_VBASE_LSB                                      0
#define MWV207REG_BLT_YUV_TILER_VBASE_BLK                                      0
#define MWV207REG_BLT_YUV_TILER_VBASE_Count                                    1
#define MWV207REG_BLT_YUV_TILER_VBASE_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_VBASE_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_VBASE_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_VBASE_ResetValue                      0x00000000

#define MWV207REG_BLT_YUV_TILER_VBASE_ADDRESS                               31:0
#define MWV207REG_BLT_YUV_TILER_VBASE_ADDRESS_End                             31
#define MWV207REG_BLT_YUV_TILER_VBASE_ADDRESS_Start                            0
#define MWV207REG_BLT_YUV_TILER_VBASE_ADDRESS_Type                           U32




#define mwv207regBltYUVTilerVstrideRegAddrs                               0x5022
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_Address                          0x14088
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_MSB                                   15
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_LSB                                    0
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_BLK                                    0
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_Count                                  1
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_FieldMask                     0x0003FFFF
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_ReadMask                      0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_WriteMask                     0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_ResetValue                    0x00000000

#define MWV207REG_BLT_YUV_TILER_VSTRIDE_STRIDE                              17:0
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_STRIDE_End                            17
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_STRIDE_Start                           0
#define MWV207REG_BLT_YUV_TILER_VSTRIDE_STRIDE_Type                          U18




#define mwv207regBltYUVTilerDestBaseRegAddrs                              0x5023
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_Address                        0x1408C
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_MSB                                 15
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_LSB                                  0
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_BLK                                  0
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_Count                                1
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_FieldMask                   0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_ReadMask                    0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_WriteMask                   0xFFFFFFFF
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_ResetValue                  0x00000000

#define MWV207REG_BLT_YUV_TILER_DEST_BASE_ADDRESS                           31:0
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_ADDRESS_End                         31
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_ADDRESS_Start                        0
#define MWV207REG_BLT_YUV_TILER_DEST_BASE_ADDRESS_Type                       U32




#define mwv207regBltYUVTilerDestStrideRegAddrs                            0x5024
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_Address                      0x14090
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_MSB                               15
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_LSB                                0
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_BLK                                0
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_Count                              1
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_FieldMask                 0x0003FFFF
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_ReadMask                  0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_WriteMask                 0x0003FFFC
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_ResetValue                0x00000000

#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_STRIDE                          17:0
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_STRIDE_End                        17
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_STRIDE_Start                       0
#define MWV207REG_BLT_YUV_TILER_DEST_STRIDE_STRIDE_Type                      U18




#define mwv207regBltSrcSurfaceSizeRegAddrs                                0x5025
#define MWV207REG_BLT_SRC_SURFACE_SIZE_Address                           0x14094
#define MWV207REG_BLT_SRC_SURFACE_SIZE_MSB                                    15
#define MWV207REG_BLT_SRC_SURFACE_SIZE_LSB                                     0
#define MWV207REG_BLT_SRC_SURFACE_SIZE_BLK                                     0
#define MWV207REG_BLT_SRC_SURFACE_SIZE_Count                                   1
#define MWV207REG_BLT_SRC_SURFACE_SIZE_FieldMask                      0xFFFFFFFF
#define MWV207REG_BLT_SRC_SURFACE_SIZE_ReadMask                       0xFFFFFFFF
#define MWV207REG_BLT_SRC_SURFACE_SIZE_WriteMask                      0xFFFFFFFF
#define MWV207REG_BLT_SRC_SURFACE_SIZE_ResetValue                     0x00000000


#define MWV207REG_BLT_SRC_SURFACE_SIZE_WIDTH                                15:0
#define MWV207REG_BLT_SRC_SURFACE_SIZE_WIDTH_End                              15
#define MWV207REG_BLT_SRC_SURFACE_SIZE_WIDTH_Start                             0
#define MWV207REG_BLT_SRC_SURFACE_SIZE_WIDTH_Type                            U16


#define MWV207REG_BLT_SRC_SURFACE_SIZE_HEIGHT                              31:16
#define MWV207REG_BLT_SRC_SURFACE_SIZE_HEIGHT_End                             31
#define MWV207REG_BLT_SRC_SURFACE_SIZE_HEIGHT_Start                           16
#define MWV207REG_BLT_SRC_SURFACE_SIZE_HEIGHT_Type                           U16




#define mwv207regBltSrcRotConfigRegAddrs                                  0x5026
#define MWV207REG_BLT_SRC_ROT_CONFIG_Address                             0x14098
#define MWV207REG_BLT_SRC_ROT_CONFIG_MSB                                      15
#define MWV207REG_BLT_SRC_ROT_CONFIG_LSB                                       0
#define MWV207REG_BLT_SRC_ROT_CONFIG_BLK                                       0
#define MWV207REG_BLT_SRC_ROT_CONFIG_Count                                     1
#define MWV207REG_BLT_SRC_ROT_CONFIG_FieldMask                        0x0000007F
#define MWV207REG_BLT_SRC_ROT_CONFIG_ReadMask                         0x0000007F
#define MWV207REG_BLT_SRC_ROT_CONFIG_WriteMask                        0x0000007F
#define MWV207REG_BLT_SRC_ROT_CONFIG_ResetValue                       0x00000000


#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_H                                  0:0
#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_H_End                                0
#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_H_Start                              0
#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_H_Type                             U01
#define   MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_H_DISABLED                       0x0
#define   MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_H_ENABLE                         0x1

#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_H                             1:1
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_H_End                           1
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_H_Start                         1
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_H_Type                        U01
#define   MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_H_ENABLED                   0x0
#define   MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_H_MASKED                    0x1


#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_V                                  2:2
#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_V_End                                2
#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_V_Start                              2
#define MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_V_Type                             U01
#define   MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_V_DISABLE                        0x0
#define   MWV207REG_BLT_SRC_ROT_CONFIG_FLIP_V_ENABLE                         0x1

#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_V                             3:3
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_V_End                           3
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_V_Start                         3
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_V_Type                        U01
#define   MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_V_ENABLED                   0x0
#define   MWV207REG_BLT_SRC_ROT_CONFIG_MASK_FLIP_V_MASKED                    0x1

#define MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION                                5:4
#define MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION_End                              5
#define MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION_Start                            4
#define MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION_Type                           U02
#define   MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION_DEGREE0                      0x0
#define   MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION_DEGREE90                     0x1
#define   MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION_DEGREE180                    0x2
#define   MWV207REG_BLT_SRC_ROT_CONFIG_ROTATION_DEGREE270                    0x3

#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_ROTATION                           6:6
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_ROTATION_End                         6
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_ROTATION_Start                       6
#define MWV207REG_BLT_SRC_ROT_CONFIG_MASK_ROTATION_Type                      U01
#define   MWV207REG_BLT_SRC_ROT_CONFIG_MASK_ROTATION_ENABLED                 0x0
#define   MWV207REG_BLT_SRC_ROT_CONFIG_MASK_ROTATION_MASKED                  0x1




#define mwv207regBltBlockSizeRegAddrs                                     0x5027
#define MWV207REG_BLT_BLOCK_SIZE_Address                                 0x1409C
#define MWV207REG_BLT_BLOCK_SIZE_MSB                                          15
#define MWV207REG_BLT_BLOCK_SIZE_LSB                                           0
#define MWV207REG_BLT_BLOCK_SIZE_BLK                                           0
#define MWV207REG_BLT_BLOCK_SIZE_Count                                         1
#define MWV207REG_BLT_BLOCK_SIZE_FieldMask                            0xFFFFFFFF
#define MWV207REG_BLT_BLOCK_SIZE_ReadMask                             0xFFFFFFFF
#define MWV207REG_BLT_BLOCK_SIZE_WriteMask                            0xFFFFFFFF
#define MWV207REG_BLT_BLOCK_SIZE_ResetValue                           0x00000000


#define MWV207REG_BLT_BLOCK_SIZE_WIDTH                                      15:0
#define MWV207REG_BLT_BLOCK_SIZE_WIDTH_End                                    15
#define MWV207REG_BLT_BLOCK_SIZE_WIDTH_Start                                   0
#define MWV207REG_BLT_BLOCK_SIZE_WIDTH_Type                                  U16


#define MWV207REG_BLT_BLOCK_SIZE_HEIGHT                                    31:16
#define MWV207REG_BLT_BLOCK_SIZE_HEIGHT_End                                   31
#define MWV207REG_BLT_BLOCK_SIZE_HEIGHT_Start                                 16
#define MWV207REG_BLT_BLOCK_SIZE_HEIGHT_Type                                 U16




#define mwv207regBltTileSizeRegAddrs                                      0x5028
#define MWV207REG_BLT_TILE_SIZE_Address                                  0x140A0
#define MWV207REG_BLT_TILE_SIZE_MSB                                           15
#define MWV207REG_BLT_TILE_SIZE_LSB                                            0
#define MWV207REG_BLT_TILE_SIZE_BLK                                            0
#define MWV207REG_BLT_TILE_SIZE_Count                                          1
#define MWV207REG_BLT_TILE_SIZE_FieldMask                             0xFFFFFFFF
#define MWV207REG_BLT_TILE_SIZE_ReadMask                              0xFFFFFFFF
#define MWV207REG_BLT_TILE_SIZE_WriteMask                             0xFFFFFFFF
#define MWV207REG_BLT_TILE_SIZE_ResetValue                            0x00000000


#define MWV207REG_BLT_TILE_SIZE_WIDTH                                       15:0
#define MWV207REG_BLT_TILE_SIZE_WIDTH_End                                     15
#define MWV207REG_BLT_TILE_SIZE_WIDTH_Start                                    0
#define MWV207REG_BLT_TILE_SIZE_WIDTH_Type                                   U16


#define MWV207REG_BLT_TILE_SIZE_HEIGHT                                     31:16
#define MWV207REG_BLT_TILE_SIZE_HEIGHT_End                                    31
#define MWV207REG_BLT_TILE_SIZE_HEIGHT_Start                                  16
#define MWV207REG_BLT_TILE_SIZE_HEIGHT_Type                                  U16




#define mwv207regBltFenceAddressRegAddrs                                  0x5029
#define MWV207REG_BLT_FENCE_ADDRESS_Address                              0x140A4
#define MWV207REG_BLT_FENCE_ADDRESS_MSB                                       15
#define MWV207REG_BLT_FENCE_ADDRESS_LSB                                        0
#define MWV207REG_BLT_FENCE_ADDRESS_BLK                                        0
#define MWV207REG_BLT_FENCE_ADDRESS_Count                                      1
#define MWV207REG_BLT_FENCE_ADDRESS_FieldMask                         0xFFFFFFFF
#define MWV207REG_BLT_FENCE_ADDRESS_ReadMask                          0xFFFFFFFC
#define MWV207REG_BLT_FENCE_ADDRESS_WriteMask                         0xFFFFFFFC
#define MWV207REG_BLT_FENCE_ADDRESS_ResetValue                        0x00000000

#define MWV207REG_BLT_FENCE_ADDRESS_TYPE                                   31:31
#define MWV207REG_BLT_FENCE_ADDRESS_TYPE_End                                  31
#define MWV207REG_BLT_FENCE_ADDRESS_TYPE_Start                                31
#define MWV207REG_BLT_FENCE_ADDRESS_TYPE_Type                                U01
#define   MWV207REG_BLT_FENCE_ADDRESS_TYPE_SYSTEM                            0x0
#define   MWV207REG_BLT_FENCE_ADDRESS_TYPE_VIRTUAL_SYSTEM                    0x1

#define MWV207REG_BLT_FENCE_ADDRESS_ADDRESS                                 30:0
#define MWV207REG_BLT_FENCE_ADDRESS_ADDRESS_End                               30
#define MWV207REG_BLT_FENCE_ADDRESS_ADDRESS_Start                              0
#define MWV207REG_BLT_FENCE_ADDRESS_ADDRESS_Type                             U31



#define mwv207regBltFenceDataRegAddrs                                     0x502A
#define MWV207REG_BLT_FENCE_DATA_Address                                 0x140A8
#define MWV207REG_BLT_FENCE_DATA_MSB                                          15
#define MWV207REG_BLT_FENCE_DATA_LSB                                           0
#define MWV207REG_BLT_FENCE_DATA_BLK                                           0
#define MWV207REG_BLT_FENCE_DATA_Count                                         1
#define MWV207REG_BLT_FENCE_DATA_FieldMask                            0xFFFFFFFF
#define MWV207REG_BLT_FENCE_DATA_ReadMask                             0xFFFFFFFF
#define MWV207REG_BLT_FENCE_DATA_WriteMask                            0xFFFFFFFF
#define MWV207REG_BLT_FENCE_DATA_ResetValue                           0x00000000


#define MWV207REG_BLT_FENCE_DATA_DATA                                       31:0
#define MWV207REG_BLT_FENCE_DATA_DATA_End                                     31
#define MWV207REG_BLT_FENCE_DATA_DATA_Start                                    0
#define MWV207REG_BLT_FENCE_DATA_DATA_Type                                   U32




#define mwv207regBltCacheFlushRegAddrs                                    0x502B
#define MWV207REG_BLT_CACHE_FLUSH_Address                                0x140AC
#define MWV207REG_BLT_CACHE_FLUSH_MSB                                         15
#define MWV207REG_BLT_CACHE_FLUSH_LSB                                          0
#define MWV207REG_BLT_CACHE_FLUSH_BLK                                          0
#define MWV207REG_BLT_CACHE_FLUSH_Count                                        1
#define MWV207REG_BLT_CACHE_FLUSH_FieldMask                           0x00000003
#define MWV207REG_BLT_CACHE_FLUSH_ReadMask                            0x00000003
#define MWV207REG_BLT_CACHE_FLUSH_WriteMask                           0x00000003
#define MWV207REG_BLT_CACHE_FLUSH_ResetValue                          0x00000000


#define MWV207REG_BLT_CACHE_FLUSH_TILE_CACHE                                 0:0
#define MWV207REG_BLT_CACHE_FLUSH_TILE_CACHE_End                               0
#define MWV207REG_BLT_CACHE_FLUSH_TILE_CACHE_Start                             0
#define MWV207REG_BLT_CACHE_FLUSH_TILE_CACHE_Type                            U01
#define   MWV207REG_BLT_CACHE_FLUSH_TILE_CACHE_DISABLE                       0x0
#define   MWV207REG_BLT_CACHE_FLUSH_TILE_CACHE_ENABLE                        0x1


#define MWV207REG_BLT_CACHE_FLUSH_SRC_CACHE                                  1:1
#define MWV207REG_BLT_CACHE_FLUSH_SRC_CACHE_End                                1
#define MWV207REG_BLT_CACHE_FLUSH_SRC_CACHE_Start                              1
#define MWV207REG_BLT_CACHE_FLUSH_SRC_CACHE_Type                             U01
#define   MWV207REG_BLT_CACHE_FLUSH_SRC_CACHE_DISABLE                        0x0
#define   MWV207REG_BLT_CACHE_FLUSH_SRC_CACHE_ENABLE                         0x1




#define mwv207regBltDestLODAddressRegAddrs                                0x5030
#define MWV207REG_BLT_DEST_LOD_ADDRESS_Address                           0x140C0
#define MWV207REG_BLT_DEST_LOD_ADDRESS_MSB                                    15
#define MWV207REG_BLT_DEST_LOD_ADDRESS_LSB                                     4
#define MWV207REG_BLT_DEST_LOD_ADDRESS_BLK                                     4
#define MWV207REG_BLT_DEST_LOD_ADDRESS_Count                                  13
#define MWV207REG_BLT_DEST_LOD_ADDRESS_FieldMask                      0xFFFFFFFF
#define MWV207REG_BLT_DEST_LOD_ADDRESS_ReadMask                       0xFFFFFFFF
#define MWV207REG_BLT_DEST_LOD_ADDRESS_WriteMask                      0xFFFFFFFF
#define MWV207REG_BLT_DEST_LOD_ADDRESS_ResetValue                     0x00000000

#define MWV207REG_BLT_DEST_LOD_ADDRESS_ADDRESS                              31:0
#define MWV207REG_BLT_DEST_LOD_ADDRESS_ADDRESS_End                            31
#define MWV207REG_BLT_DEST_LOD_ADDRESS_ADDRESS_Start                           0
#define MWV207REG_BLT_DEST_LOD_ADDRESS_ADDRESS_Type                          U32




#define mwv207regBltDestLODStrideRegAddrs                                 0x50C0
#define MWV207REG_BLT_DEST_LOD_STRIDE_Address                            0x14300
#define MWV207REG_BLT_DEST_LOD_STRIDE_MSB                                     15
#define MWV207REG_BLT_DEST_LOD_STRIDE_LSB                                      4
#define MWV207REG_BLT_DEST_LOD_STRIDE_BLK                                      4
#define MWV207REG_BLT_DEST_LOD_STRIDE_Count                                   13
#define MWV207REG_BLT_DEST_LOD_STRIDE_FieldMask                       0x001FFFFF
#define MWV207REG_BLT_DEST_LOD_STRIDE_ReadMask                        0x001FFFFF
#define MWV207REG_BLT_DEST_LOD_STRIDE_WriteMask                       0x001FFFFF
#define MWV207REG_BLT_DEST_LOD_STRIDE_ResetValue                      0x00000000


#define MWV207REG_BLT_DEST_LOD_STRIDE_STRIDE                                20:0
#define MWV207REG_BLT_DEST_LOD_STRIDE_STRIDE_End                              20
#define MWV207REG_BLT_DEST_LOD_STRIDE_STRIDE_Start                             0
#define MWV207REG_BLT_DEST_LOD_STRIDE_STRIDE_Type                            U21




#define mwv207regBltLODConfigRegAddrs                                     0x502C
#define MWV207REG_BLT_LOD_CONFIG_Address                                 0x140B0
#define MWV207REG_BLT_LOD_CONFIG_MSB                                          15
#define MWV207REG_BLT_LOD_CONFIG_LSB                                           0
#define MWV207REG_BLT_LOD_CONFIG_BLK                                           0
#define MWV207REG_BLT_LOD_CONFIG_Count                                         1
#define MWV207REG_BLT_LOD_CONFIG_FieldMask                            0x0000007F
#define MWV207REG_BLT_LOD_CONFIG_ReadMask                             0x0000007F
#define MWV207REG_BLT_LOD_CONFIG_WriteMask                            0x0000007F
#define MWV207REG_BLT_LOD_CONFIG_ResetValue                           0x00000000

#define MWV207REG_BLT_LOD_CONFIG_LOD_NUMBER                                  3:0
#define MWV207REG_BLT_LOD_CONFIG_LOD_NUMBER_End                                3
#define MWV207REG_BLT_LOD_CONFIG_LOD_NUMBER_Start                              0
#define MWV207REG_BLT_LOD_CONFIG_LOD_NUMBER_Type                             U04

#define MWV207REG_BLT_LOD_CONFIG_MASK_LOD_NUMBER                             4:4
#define MWV207REG_BLT_LOD_CONFIG_MASK_LOD_NUMBER_End                           4
#define MWV207REG_BLT_LOD_CONFIG_MASK_LOD_NUMBER_Start                         4
#define MWV207REG_BLT_LOD_CONFIG_MASK_LOD_NUMBER_Type                        U01
#define   MWV207REG_BLT_LOD_CONFIG_MASK_LOD_NUMBER_ENABLED                   0x0
#define   MWV207REG_BLT_LOD_CONFIG_MASK_LOD_NUMBER_MASKED                    0x1


#define MWV207REG_BLT_LOD_CONFIG_IGNORE_LOD0                                 5:5
#define MWV207REG_BLT_LOD_CONFIG_IGNORE_LOD0_End                               5
#define MWV207REG_BLT_LOD_CONFIG_IGNORE_LOD0_Start                             5
#define MWV207REG_BLT_LOD_CONFIG_IGNORE_LOD0_Type                            U01

#define MWV207REG_BLT_LOD_CONFIG_MASK_IGNORE_LOD0                            6:6
#define MWV207REG_BLT_LOD_CONFIG_MASK_IGNORE_LOD0_End                          6
#define MWV207REG_BLT_LOD_CONFIG_MASK_IGNORE_LOD0_Start                        6
#define MWV207REG_BLT_LOD_CONFIG_MASK_IGNORE_LOD0_Type                       U01
#define   MWV207REG_BLT_LOD_CONFIG_MASK_IGNORE_LOD0_ENABLED                  0x0
#define   MWV207REG_BLT_LOD_CONFIG_MASK_IGNORE_LOD0_MASKED                   0x1




#define mwv207regBltFenceDataHighRegAddrs                                 0x502D
#define MWV207REG_BLT_FENCE_DATA_HIGH_Address                            0x140B4
#define MWV207REG_BLT_FENCE_DATA_HIGH_MSB                                     15
#define MWV207REG_BLT_FENCE_DATA_HIGH_LSB                                      0
#define MWV207REG_BLT_FENCE_DATA_HIGH_BLK                                      0
#define MWV207REG_BLT_FENCE_DATA_HIGH_Count                                    1
#define MWV207REG_BLT_FENCE_DATA_HIGH_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_FENCE_DATA_HIGH_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_FENCE_DATA_HIGH_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_FENCE_DATA_HIGH_ResetValue                      0x00000000

#define MWV207REG_BLT_FENCE_DATA_HIGH_DATA                                  31:0
#define MWV207REG_BLT_FENCE_DATA_HIGH_DATA_End                                31
#define MWV207REG_BLT_FENCE_DATA_HIGH_DATA_Start                               0
#define MWV207REG_BLT_FENCE_DATA_HIGH_DATA_Type                              U32




#define mwv207regBltGeneralControlRegAddrs                                0x502E
#define MWV207REG_BLT_GENERAL_CONTROL_Address                            0x140B8
#define MWV207REG_BLT_GENERAL_CONTROL_MSB                                     15
#define MWV207REG_BLT_GENERAL_CONTROL_LSB                                      0
#define MWV207REG_BLT_GENERAL_CONTROL_BLK                                      0
#define MWV207REG_BLT_GENERAL_CONTROL_Count                                    1
#define MWV207REG_BLT_GENERAL_CONTROL_FieldMask                       0x00000001
#define MWV207REG_BLT_GENERAL_CONTROL_ReadMask                        0x00000001
#define MWV207REG_BLT_GENERAL_CONTROL_WriteMask                       0x00000001
#define MWV207REG_BLT_GENERAL_CONTROL_ResetValue                      0x00000000


#define MWV207REG_BLT_GENERAL_CONTROL_STREAM_CONTROL                         0:0
#define MWV207REG_BLT_GENERAL_CONTROL_STREAM_CONTROL_End                       0
#define MWV207REG_BLT_GENERAL_CONTROL_STREAM_CONTROL_Start                     0
#define MWV207REG_BLT_GENERAL_CONTROL_STREAM_CONTROL_Type                    U01
#define   MWV207REG_BLT_GENERAL_CONTROL_STREAM_CONTROL_LOCK                  0x1
#define   MWV207REG_BLT_GENERAL_CONTROL_STREAM_CONTROL_UNLOCK                0x0



#define mwv207regBltSwizzleExRegAddrs                                     0x502F
#define MWV207REG_BLT_SWIZZLE_EX_Address                                 0x140BC
#define MWV207REG_BLT_SWIZZLE_EX_MSB                                          15
#define MWV207REG_BLT_SWIZZLE_EX_LSB                                           0
#define MWV207REG_BLT_SWIZZLE_EX_BLK                                           0
#define MWV207REG_BLT_SWIZZLE_EX_Count                                         1
#define MWV207REG_BLT_SWIZZLE_EX_FieldMask                            0x00FFFFFF
#define MWV207REG_BLT_SWIZZLE_EX_ReadMask                             0x00FFFFFF
#define MWV207REG_BLT_SWIZZLE_EX_WriteMask                            0x00FFFFFF
#define MWV207REG_BLT_SWIZZLE_EX_ResetValue                           0x00688688


#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED                             2:0
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_End                           2
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_Start                         0
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_Type                        U03
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_RED                       0x0
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_GREEN                     0x1
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_BLUE                      0x2
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_ALPHA                     0x3
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_ZERO                      0x4
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_RED_ONE                       0x5


#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN                           5:3
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_End                         5
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_Start                       3
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_Type                      U03
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_RED                     0x0
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_GREEN                   0x1
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_BLUE                    0x2
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_ALPHA                   0x3
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_ZERO                    0x4
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_GREEN_ONE                     0x5


#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE                            8:6
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_End                          8
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_Start                        6
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_Type                       U03
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_RED                      0x0
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_GREEN                    0x1
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_BLUE                     0x2
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_ALPHA                    0x3
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_ZERO                     0x4
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_BLUE_ONE                      0x5


#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA                          11:9
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_End                        11
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_Start                       9
#define MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_Type                      U03
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_RED                     0x0
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_GREEN                   0x1
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_BLUE                    0x2
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_ALPHA                   0x3
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_ZERO                    0x4
#define   MWV207REG_BLT_SWIZZLE_EX_SRC_SWIZZLE_ALPHA_ONE                     0x5


#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED                           14:12
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_End                          14
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_Start                        12
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_Type                        U03
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_RED                       0x0
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_GREEN                     0x1
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_BLUE                      0x2
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_ALPHA                     0x3
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_ZERO                      0x4
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_RED_ONE                       0x5


#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN                         17:15
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_End                        17
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_Start                      15
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_Type                      U03
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_RED                     0x0
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_GREEN                   0x1
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_BLUE                    0x2
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_ALPHA                   0x3
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_ZERO                    0x4
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_GREEN_ONE                     0x5


#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE                          20:18
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_End                         20
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_Start                       18
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_Type                       U03
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_RED                      0x0
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_GREEN                    0x1
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_BLUE                     0x2
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_ALPHA                    0x3
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_ZERO                     0x4
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_BLUE_ONE                      0x5


#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA                         23:21
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_End                        23
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_Start                      21
#define MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_Type                      U03
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_RED                     0x0
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_GREEN                   0x1
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_BLUE                    0x2
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_ALPHA                   0x3
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_ZERO                    0x4
#define   MWV207REG_BLT_SWIZZLE_EX_DST_SWIZZLE_ALPHA_ONE                     0x5




#define mwv207regBltSrcBufferEndAddressRegAddrs                           0x503D
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_Address                     0x140F4
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_MSB                              15
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_LSB                               0
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_BLK                               0
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_Count                             1
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_FieldMask                0xFFFFFFFF
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_ReadMask                 0xFFFFFFFF
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_WriteMask                0xFFFFFFFF
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_ResetValue               0x00000000

#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_ADDRESS                        31:0
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_ADDRESS_End                      31
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_ADDRESS_Start                     0
#define MWV207REG_BLT_SRC_BUFFER_END_ADDRESS_ADDRESS_Type                    U32




#define mwv207regBltSrcUBufferEndAddressRegAddrs                          0x503E
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_Address                    0x140F8
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_MSB                             15
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_LSB                              0
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_BLK                              0
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_Count                            1
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_ReadMask                0xFFFFFFFF
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_WriteMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_ResetValue              0x00000000

#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_ADDRESS                       31:0
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_ADDRESS_End                     31
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_ADDRESS_Start                    0
#define MWV207REG_BLT_SRC_UBUFFER_END_ADDRESS_ADDRESS_Type                   U32




#define mwv207regBltSrcVBufferEndAddressRegAddrs                          0x503F
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_Address                    0x140FC
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_MSB                             15
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_LSB                              0
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_BLK                              0
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_Count                            1
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_ReadMask                0xFFFFFFFF
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_WriteMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_ResetValue              0x00000000

#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_ADDRESS                       31:0
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_ADDRESS_End                     31
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_ADDRESS_Start                    0
#define MWV207REG_BLT_SRC_VBUFFER_END_ADDRESS_ADDRESS_Type                   U32




#define mwv207regBltDstBufferEndAddressRegAddrs                           0x50CD
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_Address                     0x14334
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_MSB                              15
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_LSB                               0
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_BLK                               0
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_Count                             1
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_FieldMask                0xFFFFFFFF
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_ReadMask                 0xFFFFFFFF
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_WriteMask                0xFFFFFFFF
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_ResetValue               0x00000000

#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_ADDRESS                        31:0
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_ADDRESS_End                      31
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_ADDRESS_Start                     0
#define MWV207REG_BLT_DST_BUFFER_END_ADDRESS_ADDRESS_Type                    U32




#define mwv207regBltDestLODEndAddressRegAddrs                             0x50D0
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_Address                       0x14340
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_MSB                                15
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_LSB                                 4
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_BLK                                 4
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_Count                              13
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_FieldMask                  0xFFFFFFFF
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_ReadMask                   0xFFFFFFFF
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_WriteMask                  0xFFFFFFFF
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_ResetValue                 0x00000000

#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_ADDRESS                          31:0
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_ADDRESS_End                        31
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_ADDRESS_Start                       0
#define MWV207REG_BLT_DEST_LOD_END_ADDRESS_ADDRESS_Type                      U32




#define mwv207regBltClusterControlRegAddrs                                0x50CE
#define MWV207REG_BLT_CLUSTER_CONTROL_Address                            0x14338
#define MWV207REG_BLT_CLUSTER_CONTROL_MSB                                     15
#define MWV207REG_BLT_CLUSTER_CONTROL_LSB                                      0
#define MWV207REG_BLT_CLUSTER_CONTROL_BLK                                      0
#define MWV207REG_BLT_CLUSTER_CONTROL_Count                                    1
#define MWV207REG_BLT_CLUSTER_CONTROL_FieldMask                       0x000000FF
#define MWV207REG_BLT_CLUSTER_CONTROL_ReadMask                        0x000000FF
#define MWV207REG_BLT_CLUSTER_CONTROL_WriteMask                       0x000000FF
#define MWV207REG_BLT_CLUSTER_CONTROL_ResetValue                      0x00000000


#define MWV207REG_BLT_CLUSTER_CONTROL_CLUSTER_ENABLE                         7:0
#define MWV207REG_BLT_CLUSTER_CONTROL_CLUSTER_ENABLE_End                       7
#define MWV207REG_BLT_CLUSTER_CONTROL_CLUSTER_ENABLE_Start                     0
#define MWV207REG_BLT_CLUSTER_CONTROL_CLUSTER_ENABLE_Type                    U08




#define mwv207regBltDestFlipSizeRegAddrs                                  0x50CF
#define MWV207REG_BLT_DEST_FLIP_SIZE_Address                             0x1433C
#define MWV207REG_BLT_DEST_FLIP_SIZE_MSB                                      15
#define MWV207REG_BLT_DEST_FLIP_SIZE_LSB                                       0
#define MWV207REG_BLT_DEST_FLIP_SIZE_BLK                                       0
#define MWV207REG_BLT_DEST_FLIP_SIZE_Count                                     1
#define MWV207REG_BLT_DEST_FLIP_SIZE_FieldMask                        0xFFFFFFFF
#define MWV207REG_BLT_DEST_FLIP_SIZE_ReadMask                         0xFFFFFFFF
#define MWV207REG_BLT_DEST_FLIP_SIZE_WriteMask                        0xFFFFFFFF
#define MWV207REG_BLT_DEST_FLIP_SIZE_ResetValue                       0x00000000


#define MWV207REG_BLT_DEST_FLIP_SIZE_TOP                                    15:0
#define MWV207REG_BLT_DEST_FLIP_SIZE_TOP_End                                  15
#define MWV207REG_BLT_DEST_FLIP_SIZE_TOP_Start                                 0
#define MWV207REG_BLT_DEST_FLIP_SIZE_TOP_Type                                U16


#define MWV207REG_BLT_DEST_FLIP_SIZE_BOTTOM                                31:16
#define MWV207REG_BLT_DEST_FLIP_SIZE_BOTTOM_End                               31
#define MWV207REG_BLT_DEST_FLIP_SIZE_BOTTOM_Start                             16
#define MWV207REG_BLT_DEST_FLIP_SIZE_BOTTOM_Type                             U16




#define mwv207regBltSrcClearValue96RegAddrs                               0x50DD
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_Address                          0x14374
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_MSB                                   15
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_LSB                                    0
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_BLK                                    0
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_Count                                  1
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_ReadMask                      0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_ResetValue                    0x00000000


#define MWV207REG_BLT_SRC_CLEAR_VALUE96_VALUE                               31:0
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_VALUE_End                             31
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_VALUE_Start                            0
#define MWV207REG_BLT_SRC_CLEAR_VALUE96_VALUE_Type                           U32




#define mwv207regBltSrcClearValue128RegAddrs                              0x50DE
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_Address                         0x14378
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_MSB                                  15
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_LSB                                   0
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_BLK                                   0
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_Count                                 1
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_FieldMask                    0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_ReadMask                     0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_WriteMask                    0xFFFFFFFF
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_ResetValue                   0x00000000

#define MWV207REG_BLT_SRC_CLEAR_VALUE128_VALUE                              31:0
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_VALUE_End                            31
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_VALUE_Start                           0
#define MWV207REG_BLT_SRC_CLEAR_VALUE128_VALUE_Type                          U32




#define mwv207regBltDstClearValue96RegAddrs                               0x50DF
#define MWV207REG_BLT_DST_CLEAR_VALUE96_Address                          0x1437C
#define MWV207REG_BLT_DST_CLEAR_VALUE96_MSB                                   15
#define MWV207REG_BLT_DST_CLEAR_VALUE96_LSB                                    0
#define MWV207REG_BLT_DST_CLEAR_VALUE96_BLK                                    0
#define MWV207REG_BLT_DST_CLEAR_VALUE96_Count                                  1
#define MWV207REG_BLT_DST_CLEAR_VALUE96_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE96_ReadMask                      0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE96_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE96_ResetValue                    0x00000000


#define MWV207REG_BLT_DST_CLEAR_VALUE96_VALUE                               31:0
#define MWV207REG_BLT_DST_CLEAR_VALUE96_VALUE_End                             31
#define MWV207REG_BLT_DST_CLEAR_VALUE96_VALUE_Start                            0
#define MWV207REG_BLT_DST_CLEAR_VALUE96_VALUE_Type                           U32




#define mwv207regBltDstClearValue128RegAddrs                              0x50E0
#define MWV207REG_BLT_DST_CLEAR_VALUE128_Address                         0x14380
#define MWV207REG_BLT_DST_CLEAR_VALUE128_MSB                                  15
#define MWV207REG_BLT_DST_CLEAR_VALUE128_LSB                                   0
#define MWV207REG_BLT_DST_CLEAR_VALUE128_BLK                                   0
#define MWV207REG_BLT_DST_CLEAR_VALUE128_Count                                 1
#define MWV207REG_BLT_DST_CLEAR_VALUE128_FieldMask                    0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE128_ReadMask                     0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE128_WriteMask                    0xFFFFFFFF
#define MWV207REG_BLT_DST_CLEAR_VALUE128_ResetValue                   0x00000000

#define MWV207REG_BLT_DST_CLEAR_VALUE128_VALUE                              31:0
#define MWV207REG_BLT_DST_CLEAR_VALUE128_VALUE_End                            31
#define MWV207REG_BLT_DST_CLEAR_VALUE128_VALUE_Start                           0
#define MWV207REG_BLT_DST_CLEAR_VALUE128_VALUE_Type                          U32




#define mwv207regBltNewClearValue96RegAddrs                               0x50E1
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_Address                          0x14384
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_MSB                                   15
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_LSB                                    0
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_BLK                                    0
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_Count                                  1
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_ReadMask                      0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_ResetValue                    0x00000000


#define MWV207REG_BLT_NEW_CLEAR_VALUE96_VALUE                               31:0
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_VALUE_End                             31
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_VALUE_Start                            0
#define MWV207REG_BLT_NEW_CLEAR_VALUE96_VALUE_Type                           U32




#define mwv207regBltNewClearValue128RegAddrs                              0x50E2
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_Address                         0x14388
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_MSB                                  15
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_LSB                                   0
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_BLK                                   0
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_Count                                 1
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_FieldMask                    0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_ReadMask                     0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_WriteMask                    0xFFFFFFFF
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_ResetValue                   0x00000000

#define MWV207REG_BLT_NEW_CLEAR_VALUE128_VALUE                              31:0
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_VALUE_End                            31
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_VALUE_Start                           0
#define MWV207REG_BLT_NEW_CLEAR_VALUE128_VALUE_Type                          U32




#define mwv207regBltClearMask96RegAddrs                                   0x50E3
#define MWV207REG_BLT_CLEAR_MASK96_Address                               0x1438C
#define MWV207REG_BLT_CLEAR_MASK96_MSB                                        15
#define MWV207REG_BLT_CLEAR_MASK96_LSB                                         0
#define MWV207REG_BLT_CLEAR_MASK96_BLK                                         0
#define MWV207REG_BLT_CLEAR_MASK96_Count                                       1
#define MWV207REG_BLT_CLEAR_MASK96_FieldMask                          0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK96_ReadMask                           0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK96_WriteMask                          0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK96_ResetValue                         0x00000000


#define MWV207REG_BLT_CLEAR_MASK96_MASK                                     31:0
#define MWV207REG_BLT_CLEAR_MASK96_MASK_End                                   31
#define MWV207REG_BLT_CLEAR_MASK96_MASK_Start                                  0
#define MWV207REG_BLT_CLEAR_MASK96_MASK_Type                                 U32




#define mwv207regBltClearMask128RegAddrs                                  0x50E4
#define MWV207REG_BLT_CLEAR_MASK128_Address                              0x14390
#define MWV207REG_BLT_CLEAR_MASK128_MSB                                       15
#define MWV207REG_BLT_CLEAR_MASK128_LSB                                        0
#define MWV207REG_BLT_CLEAR_MASK128_BLK                                        0
#define MWV207REG_BLT_CLEAR_MASK128_Count                                      1
#define MWV207REG_BLT_CLEAR_MASK128_FieldMask                         0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK128_ReadMask                          0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK128_WriteMask                         0xFFFFFFFF
#define MWV207REG_BLT_CLEAR_MASK128_ResetValue                        0x00000000


#define MWV207REG_BLT_CLEAR_MASK128_MASK                                    31:0
#define MWV207REG_BLT_CLEAR_MASK128_MASK_End                                  31
#define MWV207REG_BLT_CLEAR_MASK128_MASK_Start                                 0
#define MWV207REG_BLT_CLEAR_MASK128_MASK_Type                                U32




#define mwv207regBltDestUPlaneAddressRegAddrs                             0x50E5
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_Address                        0x14394
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_MSB                                 15
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_LSB                                  0
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_BLK                                  0
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_Count                                1
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_FieldMask                   0xFFFFFFFF
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_ReadMask                    0xFFFFFFFF
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_WriteMask                   0xFFFFFFFF
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_ResetValue                  0x00000000

#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_ADDRESS                           31:0
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_ADDRESS_End                         31
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_ADDRESS_Start                        0
#define MWV207REG_BLT_DEST_UPLANE_ADDRESS_ADDRESS_Type                       U32




#define mwv207regBltDestUPlaneConfigRegAddrs                              0x50E6
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_Address                         0x14398
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_MSB                                  15
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_LSB                                   0
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_BLK                                   0
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_Count                                 1
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_FieldMask                    0x001FFFFF
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_ReadMask                     0x001FFFFF
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_WriteMask                    0x001FFFFF
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_ResetValue                   0x00000000

#define MWV207REG_BLT_DEST_UPLANE_CONFIG_STRIDE                             20:0
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_STRIDE_End                           20
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_STRIDE_Start                          0
#define MWV207REG_BLT_DEST_UPLANE_CONFIG_STRIDE_Type                         U21




#define mwv207regBltDestUPlaneEndAddressRegAddrs                          0x50E7
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_Address                    0x1439C
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_MSB                             15
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_LSB                              0
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_BLK                              0
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_Count                            1
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_ReadMask                0xFFFFFFFF
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_WriteMask               0xFFFFFFFF
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_ResetValue              0x00000000

#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_ADDRESS                       31:0
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_ADDRESS_End                     31
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_ADDRESS_Start                    0
#define MWV207REG_BLT_DEST_UPLANE_END_ADDRESS_ADDRESS_Type                   U32




#define mwv207regBltDestVPlaneAddressRegAddrs                             0x50E8
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_Address                        0x143A0
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_MSB                                 15
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_LSB                                  0
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_BLK                                  0
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_Count                                1
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_FieldMask                   0xFFFFFFFF
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_ReadMask                    0xFFFFFFFF
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_WriteMask                   0xFFFFFFFF
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_ResetValue                  0x00000000

#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_ADDRESS                           31:0
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_ADDRESS_End                         31
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_ADDRESS_Start                        0
#define MWV207REG_BLT_DEST_VPLANE_ADDRESS_ADDRESS_Type                       U32




#define mwv207regBltDestVPlaneConfigRegAddrs                              0x50E9
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_Address                         0x143A4
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_MSB                                  15
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_LSB                                   0
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_BLK                                   0
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_Count                                 1
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_FieldMask                    0x001FFFFF
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_ReadMask                     0x001FFFFF
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_WriteMask                    0x001FFFFF
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_ResetValue                   0x00000000

#define MWV207REG_BLT_DEST_VPLANE_CONFIG_STRIDE                             20:0
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_STRIDE_End                           20
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_STRIDE_Start                          0
#define MWV207REG_BLT_DEST_VPLANE_CONFIG_STRIDE_Type                         U21




#define mwv207regBltDestVPlaneEndAddressRegAddrs                          0x50EA
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_Address                    0x143A8
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_MSB                             15
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_LSB                              0
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_BLK                              0
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_Count                            1
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_ReadMask                0xFFFFFFFF
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_WriteMask               0xFFFFFFFF
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_ResetValue              0x00000000

#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_ADDRESS                       31:0
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_ADDRESS_End                     31
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_ADDRESS_Start                    0
#define MWV207REG_BLT_DEST_VPLANE_END_ADDRESS_ADDRESS_Type                   U32




#define mwv207regBltQosConfigRegAddrs                                     0x50EB
#define MWV207REG_BLT_QOS_CONFIG_Address                                 0x143AC
#define MWV207REG_BLT_QOS_CONFIG_MSB                                          15
#define MWV207REG_BLT_QOS_CONFIG_LSB                                           0
#define MWV207REG_BLT_QOS_CONFIG_BLK                                           0
#define MWV207REG_BLT_QOS_CONFIG_Count                                         1
#define MWV207REG_BLT_QOS_CONFIG_FieldMask                            0x0FFFFFF3
#define MWV207REG_BLT_QOS_CONFIG_ReadMask                             0x0FFFFFF3
#define MWV207REG_BLT_QOS_CONFIG_WriteMask                            0x0FFFFFF3
#define MWV207REG_BLT_QOS_CONFIG_ResetValue                           0x00000000

#define MWV207REG_BLT_QOS_CONFIG_SRC_QOS                                     0:0
#define MWV207REG_BLT_QOS_CONFIG_SRC_QOS_End                                   0
#define MWV207REG_BLT_QOS_CONFIG_SRC_QOS_Start                                 0
#define MWV207REG_BLT_QOS_CONFIG_SRC_QOS_Type                                U01
#define   MWV207REG_BLT_QOS_CONFIG_SRC_QOS_DISABLED                          0x0
#define   MWV207REG_BLT_QOS_CONFIG_SRC_QOS_ENABLE                            0x1

#define MWV207REG_BLT_QOS_CONFIG_DEST_QOS                                    1:1
#define MWV207REG_BLT_QOS_CONFIG_DEST_QOS_End                                  1
#define MWV207REG_BLT_QOS_CONFIG_DEST_QOS_Start                                1
#define MWV207REG_BLT_QOS_CONFIG_DEST_QOS_Type                               U01
#define   MWV207REG_BLT_QOS_CONFIG_DEST_QOS_DISABLED                         0x0
#define   MWV207REG_BLT_QOS_CONFIG_DEST_QOS_ENABLE                           0x1

#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_BAND_WIDTH_THRESHHOLD              9:4
#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_BAND_WIDTH_THRESHHOLD_End            9
#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_BAND_WIDTH_THRESHHOLD_Start          4
#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_BAND_WIDTH_THRESHHOLD_Type         U06

#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_BAND_WIDTH_THRESHHOLD           15:10
#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_BAND_WIDTH_THRESHHOLD_End          15
#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_BAND_WIDTH_THRESHHOLD_Start        10
#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_BAND_WIDTH_THRESHHOLD_Type        U06


#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_CREDIT                           21:16
#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_CREDIT_End                          21
#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_CREDIT_Start                        16
#define MWV207REG_BLT_QOS_CONFIG_READ_MAX_CREDIT_Type                        U06


#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_CREDIT                          27:22
#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_CREDIT_End                         27
#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_CREDIT_Start                       22
#define MWV207REG_BLT_QOS_CONFIG_WRITE_MAX_CREDIT_Type                       U06




#define mwv207regBltSrc1AddressRegAddrs                                   0x50EC
#define MWV207REG_BLT_SRC1_ADDRESS_Address                               0x143B0
#define MWV207REG_BLT_SRC1_ADDRESS_MSB                                        15
#define MWV207REG_BLT_SRC1_ADDRESS_LSB                                         1
#define MWV207REG_BLT_SRC1_ADDRESS_BLK                                         1
#define MWV207REG_BLT_SRC1_ADDRESS_Count                                       2
#define MWV207REG_BLT_SRC1_ADDRESS_FieldMask                          0xFFFFFFFF
#define MWV207REG_BLT_SRC1_ADDRESS_ReadMask                           0xFFFFFFFF
#define MWV207REG_BLT_SRC1_ADDRESS_WriteMask                          0xFFFFFFFF
#define MWV207REG_BLT_SRC1_ADDRESS_ResetValue                         0x00000000

#define MWV207REG_BLT_SRC1_ADDRESS_ADDRESS                                  31:0
#define MWV207REG_BLT_SRC1_ADDRESS_ADDRESS_End                                31
#define MWV207REG_BLT_SRC1_ADDRESS_ADDRESS_Start                               0
#define MWV207REG_BLT_SRC1_ADDRESS_ADDRESS_Type                              U32




#define mwv207regBltSrc1ConfigRegAddrs                                    0x50EE
#define MWV207REG_BLT_SRC1_CONFIG_Address                                0x143B8
#define MWV207REG_BLT_SRC1_CONFIG_MSB                                         15
#define MWV207REG_BLT_SRC1_CONFIG_LSB                                          0
#define MWV207REG_BLT_SRC1_CONFIG_BLK                                          0
#define MWV207REG_BLT_SRC1_CONFIG_Count                                        1
#define MWV207REG_BLT_SRC1_CONFIG_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_SRC1_CONFIG_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_SRC1_CONFIG_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_SRC1_CONFIG_ResetValue                          0x00000000


#define MWV207REG_BLT_SRC1_CONFIG_STRIDE                                    20:0
#define MWV207REG_BLT_SRC1_CONFIG_STRIDE_End                                  20
#define MWV207REG_BLT_SRC1_CONFIG_STRIDE_Start                                 0
#define MWV207REG_BLT_SRC1_CONFIG_STRIDE_Type                                U21


#define MWV207REG_BLT_SRC1_CONFIG_FORMAT                                   26:21
#define MWV207REG_BLT_SRC1_CONFIG_FORMAT_End                                  26
#define MWV207REG_BLT_SRC1_CONFIG_FORMAT_Start                                21
#define MWV207REG_BLT_SRC1_CONFIG_FORMAT_Type                                U06
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_X4R4G4B4                         0x00
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_A4R4G4B4                         0x01
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_X1R5G5B5                         0x02
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_A1R5G5B5                         0x03
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_R5G6B5                           0x04
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_X8R8G8B8                         0x05
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_A8R8G8B8                         0x06
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_YUY2                             0x07
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_UYVY                             0x08
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_A8                               0x10
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RF16                             0x11
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RF16GF16                         0x12
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RF16GF16BF16AF16                 0x13
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RF32                             0x14
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RF32GF32                         0x15
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_R10G10B10A2                      0x16
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_D24S8                            0x17
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_D16                              0x18
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_D32FS8                           0x19
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_D32F                             0x1A
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_S8                               0x1B
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI8                              0x1B
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI16GI16BI16AI16                 0x1C
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RF11GF11BF10                     0x1D
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI10GI10BI10AI2                  0x1E
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI8GI8                           0x1F
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_A8L8                             0x20
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_L8                               0x21
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_R8G8B8                           0x22
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_R8                               0x23
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_G8R8                             0x24
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RF32GF32BF32AF32                 0x25
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI32GI32BI32AI32                 0x26
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_R16                              0x27
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RUI32GUI32BUI32AUI32             0x26
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RSI32GSI32BSI32ASI32             0x27
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_NV12                             0x28
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_NV16                             0x29
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_YV12                             0x2A
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI8GI8BI8AI8                     0x2B
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_P010                             0x2C
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI32_NEW                         0x2D
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI32GI32_NEW                     0x2E
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_R16G16                           0x2F
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_R16G16B16A16                     0x30
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI16                             0x31
#define   MWV207REG_BLT_SRC1_CONFIG_FORMAT_RI16GI16                         0x32


#define MWV207REG_BLT_SRC1_CONFIG_MSAA                                     28:27
#define MWV207REG_BLT_SRC1_CONFIG_MSAA_End                                    28
#define MWV207REG_BLT_SRC1_CONFIG_MSAA_Start                                  27
#define MWV207REG_BLT_SRC1_CONFIG_MSAA_Type                                  U02

#define   MWV207REG_BLT_SRC1_CONFIG_MSAA_NONE                                0x0

#define   MWV207REG_BLT_SRC1_CONFIG_MSAA_MSAA2X1                             0x1

#define   MWV207REG_BLT_SRC1_CONFIG_MSAA_MSAA1X2                             0x2

#define   MWV207REG_BLT_SRC1_CONFIG_MSAA_MSAA4                               0x3


#define MWV207REG_BLT_SRC1_CONFIG_TILING                                   29:29
#define MWV207REG_BLT_SRC1_CONFIG_TILING_End                                  29
#define MWV207REG_BLT_SRC1_CONFIG_TILING_Start                                29
#define MWV207REG_BLT_SRC1_CONFIG_TILING_Type                                U01
#define   MWV207REG_BLT_SRC1_CONFIG_TILING_DISABLED                          0x0
#define   MWV207REG_BLT_SRC1_CONFIG_TILING_ENABLE                            0x1


#define MWV207REG_BLT_SRC1_CONFIG_SUPER_TILING                             30:30
#define MWV207REG_BLT_SRC1_CONFIG_SUPER_TILING_End                            30
#define MWV207REG_BLT_SRC1_CONFIG_SUPER_TILING_Start                          30
#define MWV207REG_BLT_SRC1_CONFIG_SUPER_TILING_Type                          U01
#define   MWV207REG_BLT_SRC1_CONFIG_SUPER_TILING_DISABLED                    0x0
#define   MWV207REG_BLT_SRC1_CONFIG_SUPER_TILING_ENABLE                      0x1


#define MWV207REG_BLT_SRC1_CONFIG_MULTI_TILING                             31:31
#define MWV207REG_BLT_SRC1_CONFIG_MULTI_TILING_End                            31
#define MWV207REG_BLT_SRC1_CONFIG_MULTI_TILING_Start                          31
#define MWV207REG_BLT_SRC1_CONFIG_MULTI_TILING_Type                          U01
#define   MWV207REG_BLT_SRC1_CONFIG_MULTI_TILING_DISABLED                    0x0
#define   MWV207REG_BLT_SRC1_CONFIG_MULTI_TILING_ENABLE                      0x1




#define mwv207regBltSrc1ConfigExRegAddrs                                  0x50EF
#define MWV207REG_BLT_SRC1_CONFIG_EX_Address                             0x143BC
#define MWV207REG_BLT_SRC1_CONFIG_EX_MSB                                      15
#define MWV207REG_BLT_SRC1_CONFIG_EX_LSB                                       0
#define MWV207REG_BLT_SRC1_CONFIG_EX_BLK                                       0
#define MWV207REG_BLT_SRC1_CONFIG_EX_Count                                     1
#define MWV207REG_BLT_SRC1_CONFIG_EX_FieldMask                        0x03FFFFFB
#define MWV207REG_BLT_SRC1_CONFIG_EX_ReadMask                         0x03FFFFFB
#define MWV207REG_BLT_SRC1_CONFIG_EX_WriteMask                        0x03FFFFFB
#define MWV207REG_BLT_SRC1_CONFIG_EX_ResetValue                       0x0001C800


#define MWV207REG_BLT_SRC1_CONFIG_EX_FAST_CLEAR                              0:0
#define MWV207REG_BLT_SRC1_CONFIG_EX_FAST_CLEAR_End                            0
#define MWV207REG_BLT_SRC1_CONFIG_EX_FAST_CLEAR_Start                          0
#define MWV207REG_BLT_SRC1_CONFIG_EX_FAST_CLEAR_Type                         U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_FAST_CLEAR_DISABLED                   0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_FAST_CLEAR_ENABLE                     0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_COMPRESSION_EN_C                        1:1
#define MWV207REG_BLT_SRC1_CONFIG_EX_COMPRESSION_EN_C_End                      1
#define MWV207REG_BLT_SRC1_CONFIG_EX_COMPRESSION_EN_C_Start                    1
#define MWV207REG_BLT_SRC1_CONFIG_EX_COMPRESSION_EN_C_Type                   U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COMPRESSION_EN_C_DISABLE              0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COMPRESSION_EN_C_ENABLE               0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT  3:3
#define MWV207REG_BLT_SRC1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_End 3
#define MWV207REG_BLT_SRC1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_Start 3
#define MWV207REG_BLT_SRC1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_Type U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_ENABLED 0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_MASKED 0x1

#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT                            7:4
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_End                          7
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_Start                        4
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_Type                       U04
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_ARGB4                    0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_A1RGB5                   0x1
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_R5G6B5                   0x2
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_ARGB8                    0x3
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_RGB8                     0x4
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_Z24S8                    0x5
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_Z24                      0x6
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_VAA16                    0x7
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_Z16                      0x8
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_S8                       0x9
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V             0xA
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_UV_MIX                   0xB
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_YUY2                     0xC
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V_P010        0xD
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_UV_MIX_P010              0xE
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_FORMAT_A2RGB10                  0xF


#define MWV207REG_BLT_SRC1_CONFIG_EX_SRGB                                    8:8
#define MWV207REG_BLT_SRC1_CONFIG_EX_SRGB_End                                  8
#define MWV207REG_BLT_SRC1_CONFIG_EX_SRGB_Start                                8
#define MWV207REG_BLT_SRC1_CONFIG_EX_SRGB_Type                               U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SRGB_DISABLE                          0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SRGB_ENABLE                           0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED                            10:9
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED_End                          10
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED_Start                         9
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED_Type                        U02
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED_RED                       0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED_GREEN                     0x1
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED_BLUE                      0x2
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_RED_ALPHA                     0x3


#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN                         12:11
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN_End                        12
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN_Start                      11
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN_Type                      U02
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN_RED                     0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN_GREEN                   0x1
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN_BLUE                    0x2
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_GREEN_ALPHA                   0x3


#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE                          14:13
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE_End                         14
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE_Start                       13
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE_Type                       U02
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE_RED                      0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE_GREEN                    0x1
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE_BLUE                     0x2
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_BLUE_ALPHA                    0x3


#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA                         16:15
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA_End                        16
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA_Start                      15
#define MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA_Type                      U02
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA_RED                     0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA_GREEN                   0x1
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA_BLUE                    0x2
#define   MWV207REG_BLT_SRC1_CONFIG_EX_SWIZZLE_ALPHA_ALPHA                   0x3

#define MWV207REG_BLT_SRC1_CONFIG_EX_CACHE_MODE                            17:17
#define MWV207REG_BLT_SRC1_CONFIG_EX_CACHE_MODE_End                           17
#define MWV207REG_BLT_SRC1_CONFIG_EX_CACHE_MODE_Start                         17
#define MWV207REG_BLT_SRC1_CONFIG_EX_CACHE_MODE_Type                         U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_CACHE_MODE_DISABLED                   0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_CACHE_MODE_ENABLE                     0x1

#define MWV207REG_BLT_SRC1_CONFIG_EX_UV_SWIZZLE                            18:18
#define MWV207REG_BLT_SRC1_CONFIG_EX_UV_SWIZZLE_End                           18
#define MWV207REG_BLT_SRC1_CONFIG_EX_UV_SWIZZLE_Start                         18
#define MWV207REG_BLT_SRC1_CONFIG_EX_UV_SWIZZLE_Type                         U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_UV_SWIZZLE_DISABLED                   0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_UV_SWIZZLE_ENABLE                     0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR64                               19:19
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR64_End                              19
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR64_Start                            19
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR64_Type                            U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR64_COLOR16OR32                   0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR64_COLOR64                       0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_STATUS4_BIT                      20:20
#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_STATUS4_BIT_End                     20
#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_STATUS4_BIT_Start                   20
#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_STATUS4_BIT_Type                   U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_TILE_STATUS4_BIT_DISABLED             0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_TILE_STATUS4_BIT_ENABLED              0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE                             22:21
#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE_End                            22
#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE_Start                          21
#define MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE_Type                          U02
#define   MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE_TILED4X4                    0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE_SUPER_TILED_XMAJOR          0x1
#define   MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE_SUPER_TILED_YMAJOR          0x2
#define   MWV207REG_BLT_SRC1_CONFIG_EX_TILE_MODE_TILED8X8                    0x3


#define MWV207REG_BLT_SRC1_CONFIG_EX_MSAA_COMPRESSION                      23:23
#define MWV207REG_BLT_SRC1_CONFIG_EX_MSAA_COMPRESSION_End                     23
#define MWV207REG_BLT_SRC1_CONFIG_EX_MSAA_COMPRESSION_Start                   23
#define MWV207REG_BLT_SRC1_CONFIG_EX_MSAA_COMPRESSION_Type                   U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_MSAA_COMPRESSION_DISABLE              0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_MSAA_COMPRESSION_ENABLE               0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_YMAJOR                          24:24
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_YMAJOR_End                         24
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_YMAJOR_Start                       24
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_YMAJOR_Type                       U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_YMAJOR_DISABLE                  0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR_YMAJOR_ENABLE                   0x1


#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR128                              25:25
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR128_End                             25
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR128_Start                           25
#define MWV207REG_BLT_SRC1_CONFIG_EX_COLOR128_Type                           U01
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR128_DISABLE                      0x0
#define   MWV207REG_BLT_SRC1_CONFIG_EX_COLOR128_ENABLE                       0x1




#define mwv207regBltSrc1TileStatusAddressRegAddrs                         0x50F0
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_Address                   0x143C0
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_MSB                            15
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_LSB                             0
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_BLK                             0
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_Count                           1
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_FieldMask              0xFFFFFFFF
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_ReadMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_WriteMask              0xFFFFFFFF
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_ResetValue             0x00000000

#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_ADDRESS                      31:0
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_ADDRESS_End                    31
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_ADDRESS_Start                   0
#define MWV207REG_BLT_SRC1_TILE_STATUS_ADDRESS_ADDRESS_Type                  U32




#define mwv207regBltSrc1OriginRegAddrs                                    0x50F1
#define MWV207REG_BLT_SRC1_ORIGIN_Address                                0x143C4
#define MWV207REG_BLT_SRC1_ORIGIN_MSB                                         15
#define MWV207REG_BLT_SRC1_ORIGIN_LSB                                          0
#define MWV207REG_BLT_SRC1_ORIGIN_BLK                                          0
#define MWV207REG_BLT_SRC1_ORIGIN_Count                                        1
#define MWV207REG_BLT_SRC1_ORIGIN_FieldMask                           0xFFFFFFFF
#define MWV207REG_BLT_SRC1_ORIGIN_ReadMask                            0xFFFFFFFF
#define MWV207REG_BLT_SRC1_ORIGIN_WriteMask                           0xFFFFFFFF
#define MWV207REG_BLT_SRC1_ORIGIN_ResetValue                          0x00000000


#define MWV207REG_BLT_SRC1_ORIGIN_X                                         15:0
#define MWV207REG_BLT_SRC1_ORIGIN_X_End                                       15
#define MWV207REG_BLT_SRC1_ORIGIN_X_Start                                      0
#define MWV207REG_BLT_SRC1_ORIGIN_X_Type                                     U16


#define MWV207REG_BLT_SRC1_ORIGIN_Y                                        31:16
#define MWV207REG_BLT_SRC1_ORIGIN_Y_End                                       31
#define MWV207REG_BLT_SRC1_ORIGIN_Y_Start                                     16
#define MWV207REG_BLT_SRC1_ORIGIN_Y_Type                                     U16




#define mwv207regBltSrc1BufferEndAddressRegAddrs                          0x50F2
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_Address                    0x143C8
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_MSB                             15
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_LSB                              0
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_BLK                              0
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_Count                            1
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_ReadMask                0xFFFFFFFF
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_WriteMask               0xFFFFFFFF
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_ResetValue              0x00000000

#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_ADDRESS                       31:0
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_ADDRESS_End                     31
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_ADDRESS_Start                    0
#define MWV207REG_BLT_SRC1_BUFFER_END_ADDRESS_ADDRESS_Type                   U32




#define mwv207regBltDest1AddressRegAddrs                                  0x50F4
#define MWV207REG_BLT_DEST1_ADDRESS_Address                              0x143D0
#define MWV207REG_BLT_DEST1_ADDRESS_MSB                                       15
#define MWV207REG_BLT_DEST1_ADDRESS_LSB                                        1
#define MWV207REG_BLT_DEST1_ADDRESS_BLK                                        1
#define MWV207REG_BLT_DEST1_ADDRESS_Count                                      2
#define MWV207REG_BLT_DEST1_ADDRESS_FieldMask                         0xFFFFFFFF
#define MWV207REG_BLT_DEST1_ADDRESS_ReadMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEST1_ADDRESS_WriteMask                         0xFFFFFFFF
#define MWV207REG_BLT_DEST1_ADDRESS_ResetValue                        0x00000000

#define MWV207REG_BLT_DEST1_ADDRESS_ADDRESS                                 31:0
#define MWV207REG_BLT_DEST1_ADDRESS_ADDRESS_End                               31
#define MWV207REG_BLT_DEST1_ADDRESS_ADDRESS_Start                              0
#define MWV207REG_BLT_DEST1_ADDRESS_ADDRESS_Type                             U32




#define mwv207regBltDest1TileStatusAddressRegAddrs                        0x50F3
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_Address                  0x143CC
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_MSB                           15
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_LSB                            0
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_BLK                            0
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_Count                          1
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_FieldMask             0xFFFFFFFF
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_ReadMask              0xFFFFFFFF
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_WriteMask             0xFFFFFFFF
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_ResetValue            0x00000000

#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_ADDRESS                     31:0
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_ADDRESS_End                   31
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_ADDRESS_Start                  0
#define MWV207REG_BLT_DEST1_TILE_STATUS_ADDRESS_ADDRESS_Type                 U32




#define mwv207regBltDest1ConfigRegAddrs                                   0x50F6
#define MWV207REG_BLT_DEST1_CONFIG_Address                               0x143D8
#define MWV207REG_BLT_DEST1_CONFIG_MSB                                        15
#define MWV207REG_BLT_DEST1_CONFIG_LSB                                         0
#define MWV207REG_BLT_DEST1_CONFIG_BLK                                         0
#define MWV207REG_BLT_DEST1_CONFIG_Count                                       1
#define MWV207REG_BLT_DEST1_CONFIG_FieldMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEST1_CONFIG_ReadMask                           0xFFFFFFFF
#define MWV207REG_BLT_DEST1_CONFIG_WriteMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEST1_CONFIG_ResetValue                         0x00000000


#define MWV207REG_BLT_DEST1_CONFIG_STRIDE                                   20:0
#define MWV207REG_BLT_DEST1_CONFIG_STRIDE_End                                 20
#define MWV207REG_BLT_DEST1_CONFIG_STRIDE_Start                                0
#define MWV207REG_BLT_DEST1_CONFIG_STRIDE_Type                               U21


#define MWV207REG_BLT_DEST1_CONFIG_FORMAT                                  26:21
#define MWV207REG_BLT_DEST1_CONFIG_FORMAT_End                                 26
#define MWV207REG_BLT_DEST1_CONFIG_FORMAT_Start                               21
#define MWV207REG_BLT_DEST1_CONFIG_FORMAT_Type                               U06
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_X4R4G4B4                        0x00
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_A4R4G4B4                        0x01
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_X1R5G5B5                        0x02
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_A1R5G5B5                        0x03
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_R5G6B5                          0x04
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_X8R8G8B8                        0x05
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_A8R8G8B8                        0x06
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_YUY2                            0x07
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_UYVY                            0x08
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_A8                              0x10
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RF16                            0x11
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RF16GF16                        0x12
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RF16GF16BF16AF16                0x13
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RF32                            0x14
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RF32GF32                        0x15
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_R10G10B10A2                     0x16
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_D24S8                           0x17
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_D16                             0x18
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_D32FS8                          0x19
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_D32F                            0x1A
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_S8                              0x1B
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI8                             0x1B
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI16GI16BI16AI16                0x1C
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RF11GF11BF10                    0x1D
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI10GI10BI10AI2                 0x1E
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI8GI8                          0x1F
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_A8L8                            0x20
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_L8                              0x21
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_R8G8B8                          0x22
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_R8                              0x23
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_G8R8                            0x24
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RF32GF32BF32AF32                0x25
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI32GI32BI32AI32                0x26
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_R16                             0x27
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RUI32GUI32BUI32AUI32            0x26
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RSI32GSI32BSI32ASI32            0x27
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_NV12                            0x28
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_NV16                            0x29
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_YV12                            0x2A
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI8GI8BI8AI8                    0x2B
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_P010                            0x2C
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI32_NEW                        0x2D
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI32GI32_NEW                    0x2E
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_R16G16                          0x2F
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_R16G16B16A16                    0x30
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI16                            0x31
#define   MWV207REG_BLT_DEST1_CONFIG_FORMAT_RI16GI16                        0x32


#define MWV207REG_BLT_DEST1_CONFIG_MSAA                                    28:27
#define MWV207REG_BLT_DEST1_CONFIG_MSAA_End                                   28
#define MWV207REG_BLT_DEST1_CONFIG_MSAA_Start                                 27
#define MWV207REG_BLT_DEST1_CONFIG_MSAA_Type                                 U02

#define   MWV207REG_BLT_DEST1_CONFIG_MSAA_NONE                               0x0

#define   MWV207REG_BLT_DEST1_CONFIG_MSAA_MSAA2X1                            0x1

#define   MWV207REG_BLT_DEST1_CONFIG_MSAA_MSAA1X2                            0x2

#define   MWV207REG_BLT_DEST1_CONFIG_MSAA_MSAA4                              0x3


#define MWV207REG_BLT_DEST1_CONFIG_TILING                                  29:29
#define MWV207REG_BLT_DEST1_CONFIG_TILING_End                                 29
#define MWV207REG_BLT_DEST1_CONFIG_TILING_Start                               29
#define MWV207REG_BLT_DEST1_CONFIG_TILING_Type                               U01
#define   MWV207REG_BLT_DEST1_CONFIG_TILING_DISABLED                         0x0
#define   MWV207REG_BLT_DEST1_CONFIG_TILING_ENABLE                           0x1


#define MWV207REG_BLT_DEST1_CONFIG_SUPER_TILING                            30:30
#define MWV207REG_BLT_DEST1_CONFIG_SUPER_TILING_End                           30
#define MWV207REG_BLT_DEST1_CONFIG_SUPER_TILING_Start                         30
#define MWV207REG_BLT_DEST1_CONFIG_SUPER_TILING_Type                         U01
#define   MWV207REG_BLT_DEST1_CONFIG_SUPER_TILING_DISABLED                   0x0
#define   MWV207REG_BLT_DEST1_CONFIG_SUPER_TILING_ENABLE                     0x1


#define MWV207REG_BLT_DEST1_CONFIG_MULTI_TILING                            31:31
#define MWV207REG_BLT_DEST1_CONFIG_MULTI_TILING_End                           31
#define MWV207REG_BLT_DEST1_CONFIG_MULTI_TILING_Start                         31
#define MWV207REG_BLT_DEST1_CONFIG_MULTI_TILING_Type                         U01
#define   MWV207REG_BLT_DEST1_CONFIG_MULTI_TILING_DISABLED                   0x0
#define   MWV207REG_BLT_DEST1_CONFIG_MULTI_TILING_ENABLE                     0x1




#define mwv207regBltDest1ConfigExRegAddrs                                 0x50F7
#define MWV207REG_BLT_DEST1_CONFIG_EX_Address                            0x143DC
#define MWV207REG_BLT_DEST1_CONFIG_EX_MSB                                     15
#define MWV207REG_BLT_DEST1_CONFIG_EX_LSB                                      0
#define MWV207REG_BLT_DEST1_CONFIG_EX_BLK                                      0
#define MWV207REG_BLT_DEST1_CONFIG_EX_Count                                    1
#define MWV207REG_BLT_DEST1_CONFIG_EX_FieldMask                       0xFFFFFFFF
#define MWV207REG_BLT_DEST1_CONFIG_EX_ReadMask                        0xFFFFFFFF
#define MWV207REG_BLT_DEST1_CONFIG_EX_WriteMask                       0xFFFFFFFF
#define MWV207REG_BLT_DEST1_CONFIG_EX_ResetValue                      0x0001C800


#define MWV207REG_BLT_DEST1_CONFIG_EX_FAST_CLEAR                             0:0
#define MWV207REG_BLT_DEST1_CONFIG_EX_FAST_CLEAR_End                           0
#define MWV207REG_BLT_DEST1_CONFIG_EX_FAST_CLEAR_Start                         0
#define MWV207REG_BLT_DEST1_CONFIG_EX_FAST_CLEAR_Type                        U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_FAST_CLEAR_DISABLED                  0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_FAST_CLEAR_ENABLE                    0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_COMPRESSION_EN_C                       1:1
#define MWV207REG_BLT_DEST1_CONFIG_EX_COMPRESSION_EN_C_End                     1
#define MWV207REG_BLT_DEST1_CONFIG_EX_COMPRESSION_EN_C_Start                   1
#define MWV207REG_BLT_DEST1_CONFIG_EX_COMPRESSION_EN_C_Type                  U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COMPRESSION_EN_C_DISABLE             0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COMPRESSION_EN_C_ENABLE              0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR128                               2:2
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR128_End                             2
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR128_Start                           2
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR128_Type                          U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR128_DISABLE                     0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR128_ENABLE                      0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT 3:3
#define MWV207REG_BLT_DEST1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_End 3
#define MWV207REG_BLT_DEST1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_Start 3
#define MWV207REG_BLT_DEST1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_Type U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_ENABLED 0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_MASK_FAST_CLEAR_COMPRESSION_EN_CFORMAT_MASKED 0x1

#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT                           7:4
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_End                         7
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_Start                       4
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_Type                      U04
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_ARGB4                   0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_A1RGB5                  0x1
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_R5G6B5                  0x2
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_ARGB8                   0x3
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_RGB8                    0x4
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_Z24S8                   0x5
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_Z24                     0x6
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_VAA16                   0x7
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_Z16                     0x8
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_S8                      0x9
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V            0xA
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_UV_MIX                  0xB
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_YUY2                    0xC
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_SINGLE_Y_U_V_P010       0xD
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_UV_MIX_P010             0xE
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_FORMAT_A2RGB10                 0xF


#define MWV207REG_BLT_DEST1_CONFIG_EX_SRGB                                   8:8
#define MWV207REG_BLT_DEST1_CONFIG_EX_SRGB_End                                 8
#define MWV207REG_BLT_DEST1_CONFIG_EX_SRGB_Start                               8
#define MWV207REG_BLT_DEST1_CONFIG_EX_SRGB_Type                              U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SRGB_DISABLE                         0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SRGB_ENABLE                          0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED                           10:9
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED_End                         10
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED_Start                        9
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED_Type                       U02
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED_RED                      0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED_GREEN                    0x1
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED_BLUE                     0x2
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_RED_ALPHA                    0x3


#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN                        12:11
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN_End                       12
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN_Start                     11
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN_Type                     U02
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN_RED                    0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN_GREEN                  0x1
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN_BLUE                   0x2
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_GREEN_ALPHA                  0x3


#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE                         14:13
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE_End                        14
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE_Start                      13
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE_Type                      U02
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE_RED                     0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE_GREEN                   0x1
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE_BLUE                    0x2
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_BLUE_ALPHA                   0x3


#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA                        16:15
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA_End                       16
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA_Start                     15
#define MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA_Type                     U02
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA_RED                    0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA_GREEN                  0x1
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA_BLUE                   0x2
#define   MWV207REG_BLT_DEST1_CONFIG_EX_SWIZZLE_ALPHA_ALPHA                  0x3

#define MWV207REG_BLT_DEST1_CONFIG_EX_CACHE_MODE                           17:17
#define MWV207REG_BLT_DEST1_CONFIG_EX_CACHE_MODE_End                          17
#define MWV207REG_BLT_DEST1_CONFIG_EX_CACHE_MODE_Start                        17
#define MWV207REG_BLT_DEST1_CONFIG_EX_CACHE_MODE_Type                        U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_CACHE_MODE_DISABLED                  0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_CACHE_MODE_ENABLE                    0x1

#define MWV207REG_BLT_DEST1_CONFIG_EX_UV_SWIZZLE                           18:18
#define MWV207REG_BLT_DEST1_CONFIG_EX_UV_SWIZZLE_End                          18
#define MWV207REG_BLT_DEST1_CONFIG_EX_UV_SWIZZLE_Start                        18
#define MWV207REG_BLT_DEST1_CONFIG_EX_UV_SWIZZLE_Type                        U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_UV_SWIZZLE_DISABLED                  0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_UV_SWIZZLE_ENABLE                    0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_FLIP_Y                               19:19
#define MWV207REG_BLT_DEST1_CONFIG_EX_FLIP_Y_End                              19
#define MWV207REG_BLT_DEST1_CONFIG_EX_FLIP_Y_Start                            19
#define MWV207REG_BLT_DEST1_CONFIG_EX_FLIP_Y_Type                            U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_FLIP_Y_DISABLED                      0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_FLIP_Y_ENABLE                        0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR64                              20:20
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR64_End                             20
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR64_Start                           20
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR64_Type                           U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR64_COLOR16OR32                  0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR64_COLOR64                      0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_DISABLE_SET_SWIZZLE                  21:21
#define MWV207REG_BLT_DEST1_CONFIG_EX_DISABLE_SET_SWIZZLE_End                 21
#define MWV207REG_BLT_DEST1_CONFIG_EX_DISABLE_SET_SWIZZLE_Start               21
#define MWV207REG_BLT_DEST1_CONFIG_EX_DISABLE_SET_SWIZZLE_Type               U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_DISABLE_SET_SWIZZLE_DISABLED         0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_DISABLE_SET_SWIZZLE_ENABLED          0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_BLOCK_SIZE_CONFIG                    22:22
#define MWV207REG_BLT_DEST1_CONFIG_EX_BLOCK_SIZE_CONFIG_End                   22
#define MWV207REG_BLT_DEST1_CONFIG_EX_BLOCK_SIZE_CONFIG_Start                 22
#define MWV207REG_BLT_DEST1_CONFIG_EX_BLOCK_SIZE_CONFIG_Type                 U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_BLOCK_SIZE_CONFIG_DEFAULT            0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_BLOCK_SIZE_CONFIG_CUSTOMIZE          0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL                   24:23
#define MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL_End                  24
#define MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL_Start                23
#define MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL_Type                U02
#define   MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL_EXPAND            0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL_ADD_RGB111        0x1
#define   MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL_ADD_RGB212        0x2
#define   MWV207REG_BLT_DEST1_CONFIG_EX_CONVERSION_CONTROL_ADD_RGB737        0x3


#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_STATUS4_BIT                     25:25
#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_STATUS4_BIT_End                    25
#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_STATUS4_BIT_Start                  25
#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_STATUS4_BIT_Type                  U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_TILE_STATUS4_BIT_DISABLED            0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_TILE_STATUS4_BIT_ENABLED             0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_MODE                            27:26
#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_MODE_End                           27
#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_MODE_Start                         26
#define MWV207REG_BLT_DEST1_CONFIG_EX_TILE_MODE_Type                         U02
#define   MWV207REG_BLT_DEST1_CONFIG_EX_TILE_MODE_TILED4X4                   0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_TILE_MODE_SUPER_TILED_XMAJOR         0x1
#define   MWV207REG_BLT_DEST1_CONFIG_EX_TILE_MODE_SUPER_TILED_YMAJOR         0x2


#define MWV207REG_BLT_DEST1_CONFIG_EX_MSAA_COMPRESSION                     28:28
#define MWV207REG_BLT_DEST1_CONFIG_EX_MSAA_COMPRESSION_End                    28
#define MWV207REG_BLT_DEST1_CONFIG_EX_MSAA_COMPRESSION_Start                  28
#define MWV207REG_BLT_DEST1_CONFIG_EX_MSAA_COMPRESSION_Type                  U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_MSAA_COMPRESSION_DISABLE             0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_MSAA_COMPRESSION_ENABLE              0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_YMAJOR                         29:29
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_YMAJOR_End                        29
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_YMAJOR_Start                      29
#define MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_YMAJOR_Type                      U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_YMAJOR_DISABLE                 0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_COLOR_YMAJOR_ENABLE                  0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_VMSAA                                30:30
#define MWV207REG_BLT_DEST1_CONFIG_EX_VMSAA_End                               30
#define MWV207REG_BLT_DEST1_CONFIG_EX_VMSAA_Start                             30
#define MWV207REG_BLT_DEST1_CONFIG_EX_VMSAA_Type                             U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_VMSAA_DISABLE                        0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_VMSAA_ENABLE                         0x1


#define MWV207REG_BLT_DEST1_CONFIG_EX_DESTINATION_CONTROL                  31:31
#define MWV207REG_BLT_DEST1_CONFIG_EX_DESTINATION_CONTROL_End                 31
#define MWV207REG_BLT_DEST1_CONFIG_EX_DESTINATION_CONTROL_Start               31
#define MWV207REG_BLT_DEST1_CONFIG_EX_DESTINATION_CONTROL_Type               U01
#define   MWV207REG_BLT_DEST1_CONFIG_EX_DESTINATION_CONTROL_NOT_READ         0x0
#define   MWV207REG_BLT_DEST1_CONFIG_EX_DESTINATION_CONTROL_READ             0x1




#define mwv207regBltDest1OriginRegAddrs                                   0x50F8
#define MWV207REG_BLT_DEST1_ORIGIN_Address                               0x143E0
#define MWV207REG_BLT_DEST1_ORIGIN_MSB                                        15
#define MWV207REG_BLT_DEST1_ORIGIN_LSB                                         0
#define MWV207REG_BLT_DEST1_ORIGIN_BLK                                         0
#define MWV207REG_BLT_DEST1_ORIGIN_Count                                       1
#define MWV207REG_BLT_DEST1_ORIGIN_FieldMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEST1_ORIGIN_ReadMask                           0xFFFFFFFF
#define MWV207REG_BLT_DEST1_ORIGIN_WriteMask                          0xFFFFFFFF
#define MWV207REG_BLT_DEST1_ORIGIN_ResetValue                         0x00000000


#define MWV207REG_BLT_DEST1_ORIGIN_X                                        15:0
#define MWV207REG_BLT_DEST1_ORIGIN_X_End                                      15
#define MWV207REG_BLT_DEST1_ORIGIN_X_Start                                     0
#define MWV207REG_BLT_DEST1_ORIGIN_X_Type                                    U16


#define MWV207REG_BLT_DEST1_ORIGIN_Y                                       31:16
#define MWV207REG_BLT_DEST1_ORIGIN_Y_End                                      31
#define MWV207REG_BLT_DEST1_ORIGIN_Y_Start                                    16
#define MWV207REG_BLT_DEST1_ORIGIN_Y_Type                                    U16




#define mwv207regBltDest1BufferEndAddressRegAddrs                         0x50F9
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_Address                   0x143E4
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_MSB                            15
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_LSB                             0
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_BLK                             0
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_Count                           1
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_FieldMask              0xFFFFFFFF
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_ReadMask               0xFFFFFFFF
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_WriteMask              0xFFFFFFFF
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_ResetValue             0x00000000

#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_ADDRESS                      31:0
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_ADDRESS_End                    31
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_ADDRESS_Start                   0
#define MWV207REG_BLT_DEST1_BUFFER_END_ADDRESS_ADDRESS_Type                  U32




#define mwv207regBltTileFillerClusterTsOffsetRegAddrs                     0x50FA
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_Address              0x143E8
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_MSB                       15
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_LSB                        0
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_BLK                        0
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_Count                      1
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_FieldMask         0xFFFFFFFF
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_ReadMask          0xFFFFFFFF
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_WriteMask         0xFFFFFFFF
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_ResetValue        0x00000000


#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_VALUE                   31:0
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_VALUE_End                 31
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_VALUE_Start                0
#define MWV207REG_BLT_TILE_FILLER_CLUSTER_TS_OFFSET_VALUE_Type               U32




#define mwv207regBltSrcHighAddressRegAddrs                                0x50FB
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_Address                           0x143EC
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_MSB                                    15
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_LSB                                     0
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_BLK                                     0
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_Count                                   1
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_FieldMask                      0xFFFFFFFF
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_ReadMask                       0xFFFFFFFF
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_WriteMask                      0xFFFFFFFF
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_ResetValue                     0x00000000

#define MWV207REG_BLT_SRC_HIGH_ADDRESS_ADDRESS                              31:0
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_ADDRESS_End                            31
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_ADDRESS_Start                           0
#define MWV207REG_BLT_SRC_HIGH_ADDRESS_ADDRESS_Type                          U32




#define mwv207regBltSrcBufferHighEndAddressRegAddrs                       0x50FC
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_Address                0x143F0
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_MSB                         15
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_LSB                          0
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_BLK                          0
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_Count                        1
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_FieldMask           0xFFFFFFFF
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_ReadMask            0xFFFFFFFF
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_WriteMask           0xFFFFFFFF
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_ResetValue          0x00000000

#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_ADDRESS                   31:0
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_ADDRESS_End                 31
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_ADDRESS_Start                0
#define MWV207REG_BLT_SRC_BUFFER_HIGH_END_ADDRESS_ADDRESS_Type               U32




#define mwv207regBltDestHighAddressRegAddrs                               0x50FD
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_Address                          0x143F4
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_MSB                                   15
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_LSB                                    0
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_BLK                                    0
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_Count                                  1
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_FieldMask                     0xFFFFFFFF
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_ReadMask                      0xFFFFFFFF
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_WriteMask                     0xFFFFFFFF
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_ResetValue                    0x00000000

#define MWV207REG_BLT_DEST_HIGH_ADDRESS_ADDRESS                             31:0
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_ADDRESS_End                           31
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_ADDRESS_Start                          0
#define MWV207REG_BLT_DEST_HIGH_ADDRESS_ADDRESS_Type                         U32




#define mwv207regBltDestBufferHighEndAddressRegAddrs                      0x50FE
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_Address               0x143F8
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_MSB                        15
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_LSB                         0
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_BLK                         0
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_Count                       1
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_FieldMask          0xFFFFFFFF
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_ReadMask           0xFFFFFFFF
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_WriteMask          0xFFFFFFFF
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_ResetValue         0x00000000

#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_ADDRESS                  31:0
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_ADDRESS_End                31
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_ADDRESS_Start               0
#define MWV207REG_BLT_DEST_BUFFER_HIGH_END_ADDRESS_ADDRESS_Type              U32

#define mwv207regBltCopyHighSizeRegAddrs                                  0x50FF
#define MWV207REG_BLT_COPY_HIGH_SIZE_Address                             0x143FC
#define MWV207REG_BLT_COPY_HIGH_SIZE_MSB                                      15
#define MWV207REG_BLT_COPY_HIGH_SIZE_LSB                                       0
#define MWV207REG_BLT_COPY_HIGH_SIZE_BLK                                       0
#define MWV207REG_BLT_COPY_HIGH_SIZE_Count                                     1
#define MWV207REG_BLT_COPY_HIGH_SIZE_FieldMask                        0x000000FF
#define MWV207REG_BLT_COPY_HIGH_SIZE_ReadMask                         0x000000FF
#define MWV207REG_BLT_COPY_HIGH_SIZE_WriteMask                        0x000000FF
#define MWV207REG_BLT_COPY_HIGH_SIZE_ResetValue                       0x00000000


#define MWV207REG_BLT_COPY_HIGH_SIZE_SIZE                                    7:0
#define MWV207REG_BLT_COPY_HIGH_SIZE_SIZE_End                                  7
#define MWV207REG_BLT_COPY_HIGH_SIZE_SIZE_Start                                0
#define MWV207REG_BLT_COPY_HIGH_SIZE_SIZE_Type                               U08


#endif


