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




#ifndef __jmgpuregDEC_h__
#define __jmgpuregDEC_h__





#define mwv207regDECReadConfigRegAddrs                                    0x6000
#define MWV207REG_DEC_READ_CONFIG_Address                                0x18000
#define MWV207REG_DEC_READ_CONFIG_MSB                                         15
#define MWV207REG_DEC_READ_CONFIG_LSB                                          4
#define MWV207REG_DEC_READ_CONFIG_BLK                                          4
#define MWV207REG_DEC_READ_CONFIG_Count                                       16
#define MWV207REG_DEC_READ_CONFIG_FieldMask                           0x3FF3F7FF
#define MWV207REG_DEC_READ_CONFIG_ReadMask                            0x3FF3F7FF
#define MWV207REG_DEC_READ_CONFIG_WriteMask                           0x3FF3F7FF
#define MWV207REG_DEC_READ_CONFIG_ResetValue                          0x00000000


#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ENABLE                         0:0
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ENABLE_End                       0
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ENABLE_Start                     0
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ENABLE_Type                    U01
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_ENABLE_DISABLE               0x0
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_ENABLE_ENABLE                0x1


#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_SIZE                           2:1
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_SIZE_End                         2
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_SIZE_Start                       1
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_SIZE_Type                      U02
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_SIZE_SIZE64_BYTE             0x0
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_SIZE_SIZE128_BYTE            0x1
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_SIZE_SIZE256_BYTE            0x2

#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT                         7:3
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_End                       7
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_Start                     3
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_Type                    U05
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_ARGB8                0x00
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_XRGB8                0x01
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_AYUV                 0x02
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_UYVY                 0x03
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_YUY2                 0x04
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_YUV_ONLY             0x05
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_UV_MIX               0x06
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_ARGB4                0x07
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_XRGB4                0x08
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_A1RGB5               0x09
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_X1RGB5               0x0A
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_R5G6B5               0x0B
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_Z24S8                0x0C
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_Z24                  0x0D
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_Z16                  0x0E
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_A2R10G10B10          0x0F
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_BAYER                0x10
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_FORMAT_SIGNED_BAYER         0x11


#define MWV207REG_DEC_READ_CONFIG_CONTROL                                    9:8
#define MWV207REG_DEC_READ_CONFIG_CONTROL_End                                  9
#define MWV207REG_DEC_READ_CONFIG_CONTROL_Start                                8
#define MWV207REG_DEC_READ_CONFIG_CONTROL_Type                               U02

#define   MWV207REG_DEC_READ_CONFIG_CONTROL_DISABLE                          0x0

#define   MWV207REG_DEC_READ_CONFIG_CONTROL_ENABLE                           0x1

#define   MWV207REG_DEC_READ_CONFIG_CONTROL_COMPRESSED                       0x3

#define MWV207REG_DEC_READ_CONFIG_DOWN_SAMPLER                             10:10
#define MWV207REG_DEC_READ_CONFIG_DOWN_SAMPLER_End                            10
#define MWV207REG_DEC_READ_CONFIG_DOWN_SAMPLER_Start                          10
#define MWV207REG_DEC_READ_CONFIG_DOWN_SAMPLER_Type                          U01
#define   MWV207REG_DEC_READ_CONFIG_DOWN_SAMPLER_DISABLED                    0x0
#define   MWV207REG_DEC_READ_CONFIG_DOWN_SAMPLER_ENABLED                     0x1


#define MWV207REG_DEC_READ_CONFIG_FORMAT                                   15:12
#define MWV207REG_DEC_READ_CONFIG_FORMAT_End                                  15
#define MWV207REG_DEC_READ_CONFIG_FORMAT_Start                                12
#define MWV207REG_DEC_READ_CONFIG_FORMAT_Type                                U04
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_ARGB4                             0x0
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_A1RGB5                            0x1
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_R5G6B5                            0x2
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_ARGB8                             0x3
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_RGB8                              0x4
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_Z24S8                             0x5
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_Z24                               0x6
#define   MWV207REG_DEC_READ_CONFIG_FORMAT_VAA16                             0x7


#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE                   17:16
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE_End                  17
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE_Start                16
#define MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE_Type                U02
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN1_BYTE       0x0
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN16_BYTE      0x1
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN32_BYTE      0x2
#define   MWV207REG_DEC_READ_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN64_BYTE      0x3


#define MWV207REG_DEC_READ_CONFIG_SWIZZLE                                  21:20
#define MWV207REG_DEC_READ_CONFIG_SWIZZLE_End                                 21
#define MWV207REG_DEC_READ_CONFIG_SWIZZLE_Start                               20
#define MWV207REG_DEC_READ_CONFIG_SWIZZLE_Type                               U02
#define   MWV207REG_DEC_READ_CONFIG_SWIZZLE_ARGB                             0x0
#define   MWV207REG_DEC_READ_CONFIG_SWIZZLE_RGBA                             0x1
#define   MWV207REG_DEC_READ_CONFIG_SWIZZLE_ABGR                             0x2
#define   MWV207REG_DEC_READ_CONFIG_SWIZZLE_BGRA                             0x3


#define MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE                          24:22
#define MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE_End                         24
#define MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE_Start                       22
#define MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE_Type                       U03
#define   MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE_TILE1_ALIGN              0x0
#define   MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE_TILE2_ALIGN              0x1
#define   MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE_TILE4_ALIGN              0x2
#define   MWV207REG_DEC_READ_CONFIG_TILE_ALIGN_MODE_CBSR_ALIGN               0x3


#define MWV207REG_DEC_READ_CONFIG_TILE_MODE                                29:25
#define MWV207REG_DEC_READ_CONFIG_TILE_MODE_End                               29
#define MWV207REG_DEC_READ_CONFIG_TILE_MODE_Start                             25
#define MWV207REG_DEC_READ_CONFIG_TILE_MODE_Type                             U05
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE8X8_XMAJOR                0x00
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE8X8_YMAJOR                0x01
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE16X4                      0x02
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE8X4                       0x03
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE4X8                       0x04
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE4X4                       0x05
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER16X4                    0x06
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE64X4                      0x07
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_TILE32X4                      0x08
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER256X1                   0x09
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER128X1                   0x0A
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER64X4                    0x0B
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER256X2                   0x0C
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER128X2                   0x0D
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER128X4                   0x0E
#define   MWV207REG_DEC_READ_CONFIG_TILE_MODE_RASTER64X1                    0x0F




#define mwv207regDECWriteConfigRegAddrs                                   0x6010
#define MWV207REG_DEC_WRITE_CONFIG_Address                               0x18040
#define MWV207REG_DEC_WRITE_CONFIG_MSB                                        15
#define MWV207REG_DEC_WRITE_CONFIG_LSB                                         4
#define MWV207REG_DEC_WRITE_CONFIG_BLK                                         4
#define MWV207REG_DEC_WRITE_CONFIG_Count                                      16
#define MWV207REG_DEC_WRITE_CONFIG_FieldMask                          0x3FF300FF
#define MWV207REG_DEC_WRITE_CONFIG_ReadMask                           0x3FF300FF
#define MWV207REG_DEC_WRITE_CONFIG_WriteMask                          0x3FF300FF
#define MWV207REG_DEC_WRITE_CONFIG_ResetValue                         0x00000000


#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ENABLE                        0:0
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ENABLE_End                      0
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ENABLE_Start                    0
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ENABLE_Type                   U01
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ENABLE_DISABLE              0x0
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ENABLE_ENABLE               0x1


#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_SIZE                          2:1
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_SIZE_End                        2
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_SIZE_Start                      1
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_SIZE_Type                     U02
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_SIZE_SIZE64_BYTE            0x0
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_SIZE_SIZE128_BYTE           0x1
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_SIZE_SIZE256_BYTE           0x2

#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT                        7:3
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_End                      7
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_Start                    3
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_Type                   U05
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_ARGB8               0x00
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_XRGB8               0x01
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_AYUV                0x02
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_UYVY                0x03
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_YUY2                0x04
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_YUV_ONLY            0x05
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_UV_MIX              0x06
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_ARGB4               0x07
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_XRGB4               0x08
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_A1RGB5              0x09
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_X1RGB5              0x0A
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_R5G6B5              0x0B
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_Z24S8               0x0C
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_Z24                 0x0D
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_Z16                 0x0E
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_A2R10G10B10         0x0F
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_BAYER               0x10
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_FORMAT_SIGNED_BAYER        0x11


#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE                  17:16
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_End                 17
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_Start               16
#define MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_Type               U02
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN1_BYTE      0x0
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN16_BYTE     0x1
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN32_BYTE     0x2
#define   MWV207REG_DEC_WRITE_CONFIG_COMPRESSION_ALIGN_MODE_ALIGN64_BYTE     0x3


#define MWV207REG_DEC_WRITE_CONFIG_SWIZZLE                                 21:20
#define MWV207REG_DEC_WRITE_CONFIG_SWIZZLE_End                                21
#define MWV207REG_DEC_WRITE_CONFIG_SWIZZLE_Start                              20
#define MWV207REG_DEC_WRITE_CONFIG_SWIZZLE_Type                              U02
#define   MWV207REG_DEC_WRITE_CONFIG_SWIZZLE_ARGB                            0x0
#define   MWV207REG_DEC_WRITE_CONFIG_SWIZZLE_RGBA                            0x1
#define   MWV207REG_DEC_WRITE_CONFIG_SWIZZLE_ABGR                            0x2
#define   MWV207REG_DEC_WRITE_CONFIG_SWIZZLE_BGRA                            0x3


#define MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE                         24:22
#define MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE_End                        24
#define MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE_Start                      22
#define MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE_Type                      U03
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE_TILE1_ALIGN             0x0
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE_TILE2_ALIGN             0x1
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE_TILE4_ALIGN             0x2
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_ALIGN_MODE_CBSR_ALIGN              0x3


#define MWV207REG_DEC_WRITE_CONFIG_TILE_MODE                               29:25
#define MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_End                              29
#define MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_Start                            25
#define MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_Type                            U05
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE8X8_XMAJOR               0x00
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE8X8_YMAJOR               0x01
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE16X4                     0x02
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE8X4                      0x03
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE4X8                      0x04
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE4X4                      0x05
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER16X4                   0x06
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE64X4                     0x07
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_TILE32X4                     0x08
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER256X1                  0x09
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER128X1                  0x0A
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER64X4                   0x0B
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER256X2                  0x0C
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER128X2                  0x0D
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER128X4                  0x0E
#define   MWV207REG_DEC_WRITE_CONFIG_TILE_MODE_RASTER64X1                   0x0F




#define mwv207regDECReadBufferBaseRegAddrs                                0x6020
#define MWV207REG_DEC_READ_BUFFER_BASE_Address                           0x18080
#define MWV207REG_DEC_READ_BUFFER_BASE_MSB                                    15
#define MWV207REG_DEC_READ_BUFFER_BASE_LSB                                     4
#define MWV207REG_DEC_READ_BUFFER_BASE_BLK                                     4
#define MWV207REG_DEC_READ_BUFFER_BASE_Count                                  16
#define MWV207REG_DEC_READ_BUFFER_BASE_FieldMask                      0xFFFFFFFF
#define MWV207REG_DEC_READ_BUFFER_BASE_ReadMask                       0xFFFFFFFF
#define MWV207REG_DEC_READ_BUFFER_BASE_WriteMask                      0xFFFFFFFF
#define MWV207REG_DEC_READ_BUFFER_BASE_ResetValue                     0x00000000

#define MWV207REG_DEC_READ_BUFFER_BASE_ADDRESS                              31:0
#define MWV207REG_DEC_READ_BUFFER_BASE_ADDRESS_End                            31
#define MWV207REG_DEC_READ_BUFFER_BASE_ADDRESS_Start                           0
#define MWV207REG_DEC_READ_BUFFER_BASE_ADDRESS_Type                          U32




#define mwv207regDECReadCacheBaseRegAddrs                                 0x6030
#define MWV207REG_DEC_READ_CACHE_BASE_Address                            0x180C0
#define MWV207REG_DEC_READ_CACHE_BASE_MSB                                     15
#define MWV207REG_DEC_READ_CACHE_BASE_LSB                                      4
#define MWV207REG_DEC_READ_CACHE_BASE_BLK                                      4
#define MWV207REG_DEC_READ_CACHE_BASE_Count                                   16
#define MWV207REG_DEC_READ_CACHE_BASE_FieldMask                       0xFFFFFFFF
#define MWV207REG_DEC_READ_CACHE_BASE_ReadMask                        0xFFFFFFFF
#define MWV207REG_DEC_READ_CACHE_BASE_WriteMask                       0xFFFFFFFF
#define MWV207REG_DEC_READ_CACHE_BASE_ResetValue                      0x00000000

#define MWV207REG_DEC_READ_CACHE_BASE_ADDRESS                               31:0
#define MWV207REG_DEC_READ_CACHE_BASE_ADDRESS_End                             31
#define MWV207REG_DEC_READ_CACHE_BASE_ADDRESS_Start                            0
#define MWV207REG_DEC_READ_CACHE_BASE_ADDRESS_Type                           U32




#define mwv207regDECWriteBufferBaseRegAddrs                               0x6040
#define MWV207REG_DEC_WRITE_BUFFER_BASE_Address                          0x18100
#define MWV207REG_DEC_WRITE_BUFFER_BASE_MSB                                   15
#define MWV207REG_DEC_WRITE_BUFFER_BASE_LSB                                    4
#define MWV207REG_DEC_WRITE_BUFFER_BASE_BLK                                    4
#define MWV207REG_DEC_WRITE_BUFFER_BASE_Count                                 16
#define MWV207REG_DEC_WRITE_BUFFER_BASE_FieldMask                     0xFFFFFFFF
#define MWV207REG_DEC_WRITE_BUFFER_BASE_ReadMask                      0xFFFFFFFF
#define MWV207REG_DEC_WRITE_BUFFER_BASE_WriteMask                     0xFFFFFFFF
#define MWV207REG_DEC_WRITE_BUFFER_BASE_ResetValue                    0x00000000

#define MWV207REG_DEC_WRITE_BUFFER_BASE_ADDRESS                             31:0
#define MWV207REG_DEC_WRITE_BUFFER_BASE_ADDRESS_End                           31
#define MWV207REG_DEC_WRITE_BUFFER_BASE_ADDRESS_Start                          0
#define MWV207REG_DEC_WRITE_BUFFER_BASE_ADDRESS_Type                         U32




#define mwv207regDECWriteCacheBaseRegAddrs                                0x6050
#define MWV207REG_DEC_WRITE_CACHE_BASE_Address                           0x18140
#define MWV207REG_DEC_WRITE_CACHE_BASE_MSB                                    15
#define MWV207REG_DEC_WRITE_CACHE_BASE_LSB                                     4
#define MWV207REG_DEC_WRITE_CACHE_BASE_BLK                                     4
#define MWV207REG_DEC_WRITE_CACHE_BASE_Count                                  16
#define MWV207REG_DEC_WRITE_CACHE_BASE_FieldMask                      0xFFFFFFFF
#define MWV207REG_DEC_WRITE_CACHE_BASE_ReadMask                       0xFFFFFFFF
#define MWV207REG_DEC_WRITE_CACHE_BASE_WriteMask                      0xFFFFFFFF
#define MWV207REG_DEC_WRITE_CACHE_BASE_ResetValue                     0x00000000

#define MWV207REG_DEC_WRITE_CACHE_BASE_ADDRESS                              31:0
#define MWV207REG_DEC_WRITE_CACHE_BASE_ADDRESS_End                            31
#define MWV207REG_DEC_WRITE_CACHE_BASE_ADDRESS_Start                           0
#define MWV207REG_DEC_WRITE_CACHE_BASE_ADDRESS_Type                          U32




#define mwv207regDECControlRegAddrs                                       0x6060
#define MWV207REG_DEC_CONTROL_Address                                    0x18180
#define MWV207REG_DEC_CONTROL_MSB                                             15
#define MWV207REG_DEC_CONTROL_LSB                                              0
#define MWV207REG_DEC_CONTROL_BLK                                              0
#define MWV207REG_DEC_CONTROL_Count                                            1
#define MWV207REG_DEC_CONTROL_FieldMask                               0x03FFFFFF
#define MWV207REG_DEC_CONTROL_ReadMask                                0x03FFFFFF
#define MWV207REG_DEC_CONTROL_WriteMask                               0x03FFFFFF
#define MWV207REG_DEC_CONTROL_ResetValue                              0x0000EE0A


#define MWV207REG_DEC_CONTROL_FLUSH                                          0:0
#define MWV207REG_DEC_CONTROL_FLUSH_End                                        0
#define MWV207REG_DEC_CONTROL_FLUSH_Start                                      0
#define MWV207REG_DEC_CONTROL_FLUSH_Type                                     U01
#define   MWV207REG_DEC_CONTROL_FLUSH_DISABLE                                0x0
#define   MWV207REG_DEC_CONTROL_FLUSH_ENABLE                                 0x1


#define MWV207REG_DEC_CONTROL_DISABLE_COMPRESSION                            1:1
#define MWV207REG_DEC_CONTROL_DISABLE_COMPRESSION_End                          1
#define MWV207REG_DEC_CONTROL_DISABLE_COMPRESSION_Start                        1
#define MWV207REG_DEC_CONTROL_DISABLE_COMPRESSION_Type                       U01
#define   MWV207REG_DEC_CONTROL_DISABLE_COMPRESSION_DISABLE                  0x0
#define   MWV207REG_DEC_CONTROL_DISABLE_COMPRESSION_ENABLE                   0x1


#define MWV207REG_DEC_CONTROL_DISABLE_RAM_CLOCK_GATING                       2:2
#define MWV207REG_DEC_CONTROL_DISABLE_RAM_CLOCK_GATING_End                     2
#define MWV207REG_DEC_CONTROL_DISABLE_RAM_CLOCK_GATING_Start                   2
#define MWV207REG_DEC_CONTROL_DISABLE_RAM_CLOCK_GATING_Type                  U01
#define   MWV207REG_DEC_CONTROL_DISABLE_RAM_CLOCK_GATING_DISABLE             0x0
#define   MWV207REG_DEC_CONTROL_DISABLE_RAM_CLOCK_GATING_ENABLE              0x1

#define MWV207REG_DEC_CONTROL_DISABLE_DEBUG_REGISTERS                        3:3
#define MWV207REG_DEC_CONTROL_DISABLE_DEBUG_REGISTERS_End                      3
#define MWV207REG_DEC_CONTROL_DISABLE_DEBUG_REGISTERS_Start                    3
#define MWV207REG_DEC_CONTROL_DISABLE_DEBUG_REGISTERS_Type                   U01
#define   MWV207REG_DEC_CONTROL_DISABLE_DEBUG_REGISTERS_DISABLE              0x0
#define   MWV207REG_DEC_CONTROL_DISABLE_DEBUG_REGISTERS_ENABLE               0x1


#define MWV207REG_DEC_CONTROL_SOFT_RESET                                     4:4
#define MWV207REG_DEC_CONTROL_SOFT_RESET_End                                   4
#define MWV207REG_DEC_CONTROL_SOFT_RESET_Start                                 4
#define MWV207REG_DEC_CONTROL_SOFT_RESET_Type                                U01
#define   MWV207REG_DEC_CONTROL_SOFT_RESET_DISABLE                           0x0
#define   MWV207REG_DEC_CONTROL_SOFT_RESET_ENABLE                            0x1


#define MWV207REG_DEC_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION                 5:5
#define MWV207REG_DEC_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_End               5
#define MWV207REG_DEC_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Start             5
#define MWV207REG_DEC_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Type            U01
#define   MWV207REG_DEC_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_DISABLE       0x0
#define   MWV207REG_DEC_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_ENABLE        0x1


#define MWV207REG_DEC_CONTROL_ENABLE_WRITE_SYNC                              6:6
#define MWV207REG_DEC_CONTROL_ENABLE_WRITE_SYNC_End                            6
#define MWV207REG_DEC_CONTROL_ENABLE_WRITE_SYNC_Start                          6
#define MWV207REG_DEC_CONTROL_ENABLE_WRITE_SYNC_Type                         U01
#define   MWV207REG_DEC_CONTROL_ENABLE_WRITE_SYNC_DISABLE                    0x0
#define   MWV207REG_DEC_CONTROL_ENABLE_WRITE_SYNC_ENABLE                     0x1

#define MWV207REG_DEC_CONTROL_ENABLE96_BYTE_YUV_COMP                         7:7
#define MWV207REG_DEC_CONTROL_ENABLE96_BYTE_YUV_COMP_End                       7
#define MWV207REG_DEC_CONTROL_ENABLE96_BYTE_YUV_COMP_Start                     7
#define MWV207REG_DEC_CONTROL_ENABLE96_BYTE_YUV_COMP_Type                    U01
#define   MWV207REG_DEC_CONTROL_ENABLE96_BYTE_YUV_COMP_DISABLE               0x0
#define   MWV207REG_DEC_CONTROL_ENABLE96_BYTE_YUV_COMP_ENABLE                0x1


#define MWV207REG_DEC_CONTROL_TILE_STATUS_READ_ID                           11:8
#define MWV207REG_DEC_CONTROL_TILE_STATUS_READ_ID_End                         11
#define MWV207REG_DEC_CONTROL_TILE_STATUS_READ_ID_Start                        8
#define MWV207REG_DEC_CONTROL_TILE_STATUS_READ_ID_Type                       U04


#define MWV207REG_DEC_CONTROL_TILE_STATUS_WRITE_ID                         15:12
#define MWV207REG_DEC_CONTROL_TILE_STATUS_WRITE_ID_End                        15
#define MWV207REG_DEC_CONTROL_TILE_STATUS_WRITE_ID_Start                      12
#define MWV207REG_DEC_CONTROL_TILE_STATUS_WRITE_ID_Type                      U04


#define MWV207REG_DEC_CONTROL_DISABLE_HW_FLUSH                             16:16
#define MWV207REG_DEC_CONTROL_DISABLE_HW_FLUSH_End                            16
#define MWV207REG_DEC_CONTROL_DISABLE_HW_FLUSH_Start                          16
#define MWV207REG_DEC_CONTROL_DISABLE_HW_FLUSH_Type                          U01
#define   MWV207REG_DEC_CONTROL_DISABLE_HW_FLUSH_DISABLE                     0x0
#define   MWV207REG_DEC_CONTROL_DISABLE_HW_FLUSH_ENABLE                      0x1


#define MWV207REG_DEC_CONTROL_CLK_DIS                                      17:17
#define MWV207REG_DEC_CONTROL_CLK_DIS_End                                     17
#define MWV207REG_DEC_CONTROL_CLK_DIS_Start                                   17
#define MWV207REG_DEC_CONTROL_CLK_DIS_Type                                   U01
#define   MWV207REG_DEC_CONTROL_CLK_DIS_DISABLE                              0x0
#define   MWV207REG_DEC_CONTROL_CLK_DIS_ENABLE                               0x1


#define MWV207REG_DEC_CONTROL_SW_FLUSH_ID                                  21:18
#define MWV207REG_DEC_CONTROL_SW_FLUSH_ID_End                                 21
#define MWV207REG_DEC_CONTROL_SW_FLUSH_ID_Start                               18
#define MWV207REG_DEC_CONTROL_SW_FLUSH_ID_Type                               U04


#define MWV207REG_DEC_CONTROL_CONFIGURE_MODE                               22:22
#define MWV207REG_DEC_CONTROL_CONFIGURE_MODE_End                              22
#define MWV207REG_DEC_CONTROL_CONFIGURE_MODE_Start                            22
#define MWV207REG_DEC_CONTROL_CONFIGURE_MODE_Type                            U01
#define   MWV207REG_DEC_CONTROL_CONFIGURE_MODE_AHB                           0x0
#define   MWV207REG_DEC_CONTROL_CONFIGURE_MODE_LOAD_STATE                    0x1


#define MWV207REG_DEC_CONTROL_DISABLE_PREFETCH                             23:23
#define MWV207REG_DEC_CONTROL_DISABLE_PREFETCH_End                            23
#define MWV207REG_DEC_CONTROL_DISABLE_PREFETCH_Start                          23
#define MWV207REG_DEC_CONTROL_DISABLE_PREFETCH_Type                          U01
#define   MWV207REG_DEC_CONTROL_DISABLE_PREFETCH_DISABLED                    0x0
#define   MWV207REG_DEC_CONTROL_DISABLE_PREFETCH_ENABLED                     0x1

#define MWV207REG_DEC_CONTROL_TILE_CACHE_MODE                              24:24
#define MWV207REG_DEC_CONTROL_TILE_CACHE_MODE_End                             24
#define MWV207REG_DEC_CONTROL_TILE_CACHE_MODE_Start                           24
#define MWV207REG_DEC_CONTROL_TILE_CACHE_MODE_Type                           U01
#define   MWV207REG_DEC_CONTROL_TILE_CACHE_MODE_MODE16X64                    0x0
#define   MWV207REG_DEC_CONTROL_TILE_CACHE_MODE_MODE64X16                    0x1


#define MWV207REG_DEC_CONTROL_DISABLE_CACHE_PREFETCH                       25:25
#define MWV207REG_DEC_CONTROL_DISABLE_CACHE_PREFETCH_End                      25
#define MWV207REG_DEC_CONTROL_DISABLE_CACHE_PREFETCH_Start                    25
#define MWV207REG_DEC_CONTROL_DISABLE_CACHE_PREFETCH_Type                    U01
#define   MWV207REG_DEC_CONTROL_DISABLE_CACHE_PREFETCH_DISABLED              0x0
#define   MWV207REG_DEC_CONTROL_DISABLE_CACHE_PREFETCH_ENABLED               0x1



#define mwv207regDECIntrAcknowledgeRegAddrs                               0x6061
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_Address                           0x18184
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_MSB                                    15
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_LSB                                     0
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_BLK                                     0
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_Count                                   1
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_FieldMask                      0xFFFFFFFF
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_ReadMask                       0xFFFFFFFF
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_WriteMask                      0x00000000
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_ResetValue                     0x00000000

#define MWV207REG_DEC_INTR_ACKNOWLEDGE_INTR_VEC                             31:0
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_INTR_VEC_End                           31
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_INTR_VEC_Start                          0
#define MWV207REG_DEC_INTR_ACKNOWLEDGE_INTR_VEC_Type                         U32



#define mwv207regDECIntrEnblRegAddrs                                      0x6062
#define MWV207REG_DEC_INTR_ENBL_Address                                  0x18188
#define MWV207REG_DEC_INTR_ENBL_MSB                                           15
#define MWV207REG_DEC_INTR_ENBL_LSB                                            0
#define MWV207REG_DEC_INTR_ENBL_BLK                                            0
#define MWV207REG_DEC_INTR_ENBL_Count                                          1
#define MWV207REG_DEC_INTR_ENBL_FieldMask                             0xFFFFFFFF
#define MWV207REG_DEC_INTR_ENBL_ReadMask                              0xFFFFFFFF
#define MWV207REG_DEC_INTR_ENBL_WriteMask                             0xFFFFFFFF
#define MWV207REG_DEC_INTR_ENBL_ResetValue                            0x00000000

#define MWV207REG_DEC_INTR_ENBL_INTR_ENBL_VEC                               31:0
#define MWV207REG_DEC_INTR_ENBL_INTR_ENBL_VEC_End                             31
#define MWV207REG_DEC_INTR_ENBL_INTR_ENBL_VEC_Start                            0
#define MWV207REG_DEC_INTR_ENBL_INTR_ENBL_VEC_Type                           U32




#define mwv207regDECTileStatusDebugRegAddrs                               0x6063
#define MWV207REG_DEC_TILE_STATUS_DEBUG_Address                          0x1818C
#define MWV207REG_DEC_TILE_STATUS_DEBUG_MSB                                   15
#define MWV207REG_DEC_TILE_STATUS_DEBUG_LSB                                    0
#define MWV207REG_DEC_TILE_STATUS_DEBUG_BLK                                    0
#define MWV207REG_DEC_TILE_STATUS_DEBUG_Count                                  1
#define MWV207REG_DEC_TILE_STATUS_DEBUG_FieldMask                     0xFFFFFFFF
#define MWV207REG_DEC_TILE_STATUS_DEBUG_ReadMask                      0xFFFFFFFF
#define MWV207REG_DEC_TILE_STATUS_DEBUG_WriteMask                     0x00000000
#define MWV207REG_DEC_TILE_STATUS_DEBUG_ResetValue                    0x00000000

#define MWV207REG_DEC_TILE_STATUS_DEBUG_DEBUG                               31:0
#define MWV207REG_DEC_TILE_STATUS_DEBUG_DEBUG_End                             31
#define MWV207REG_DEC_TILE_STATUS_DEBUG_DEBUG_Start                            0
#define MWV207REG_DEC_TILE_STATUS_DEBUG_DEBUG_Type                           U32




#define mwv207regDECEncoderDebugRegAddrs                                  0x6064
#define MWV207REG_DEC_ENCODER_DEBUG_Address                              0x18190
#define MWV207REG_DEC_ENCODER_DEBUG_MSB                                       15
#define MWV207REG_DEC_ENCODER_DEBUG_LSB                                        0
#define MWV207REG_DEC_ENCODER_DEBUG_BLK                                        0
#define MWV207REG_DEC_ENCODER_DEBUG_Count                                      1
#define MWV207REG_DEC_ENCODER_DEBUG_FieldMask                         0xFFFFFFFF
#define MWV207REG_DEC_ENCODER_DEBUG_ReadMask                          0xFFFFFFFF
#define MWV207REG_DEC_ENCODER_DEBUG_WriteMask                         0x00000000
#define MWV207REG_DEC_ENCODER_DEBUG_ResetValue                        0x00000000

#define MWV207REG_DEC_ENCODER_DEBUG_DEBUG                                   31:0
#define MWV207REG_DEC_ENCODER_DEBUG_DEBUG_End                                 31
#define MWV207REG_DEC_ENCODER_DEBUG_DEBUG_Start                                0
#define MWV207REG_DEC_ENCODER_DEBUG_DEBUG_Type                               U32




#define mwv207regDECDecoderDebugRegAddrs                                  0x6065
#define MWV207REG_DEC_DECODER_DEBUG_Address                              0x18194
#define MWV207REG_DEC_DECODER_DEBUG_MSB                                       15
#define MWV207REG_DEC_DECODER_DEBUG_LSB                                        0
#define MWV207REG_DEC_DECODER_DEBUG_BLK                                        0
#define MWV207REG_DEC_DECODER_DEBUG_Count                                      1
#define MWV207REG_DEC_DECODER_DEBUG_FieldMask                         0xFFFFFFFF
#define MWV207REG_DEC_DECODER_DEBUG_ReadMask                          0xFFFFFFFF
#define MWV207REG_DEC_DECODER_DEBUG_WriteMask                         0x00000000
#define MWV207REG_DEC_DECODER_DEBUG_ResetValue                        0x00000000

#define MWV207REG_DEC_DECODER_DEBUG_DEBUG                                   31:0
#define MWV207REG_DEC_DECODER_DEBUG_DEBUG_End                                 31
#define MWV207REG_DEC_DECODER_DEBUG_DEBUG_Start                                0
#define MWV207REG_DEC_DECODER_DEBUG_DEBUG_Type                               U32



#define jmDECTotalReadsInRegAddrs                                         0x6066
#define JM_DEC_TOTAL_READS_IN_Address                                    0x18198
#define JM_DEC_TOTAL_READS_IN_MSB                                             15
#define JM_DEC_TOTAL_READS_IN_LSB                                              0
#define JM_DEC_TOTAL_READS_IN_BLK                                              0
#define JM_DEC_TOTAL_READS_IN_Count                                            1
#define JM_DEC_TOTAL_READS_IN_FieldMask                               0xFFFFFFFF
#define JM_DEC_TOTAL_READS_IN_ReadMask                                0xFFFFFFFF
#define JM_DEC_TOTAL_READS_IN_WriteMask                               0x00000000
#define JM_DEC_TOTAL_READS_IN_ResetValue                              0x00000000

#define JM_DEC_TOTAL_READS_IN_COUNT                                         31:0
#define JM_DEC_TOTAL_READS_IN_COUNT_End                                       31
#define JM_DEC_TOTAL_READS_IN_COUNT_Start                                      0
#define JM_DEC_TOTAL_READS_IN_COUNT_Type                                     U32



#define jmDECTotalWritesInRegAddrs                                        0x6067
#define JM_DEC_TOTAL_WRITES_IN_Address                                   0x1819C
#define JM_DEC_TOTAL_WRITES_IN_MSB                                            15
#define JM_DEC_TOTAL_WRITES_IN_LSB                                             0
#define JM_DEC_TOTAL_WRITES_IN_BLK                                             0
#define JM_DEC_TOTAL_WRITES_IN_Count                                           1
#define JM_DEC_TOTAL_WRITES_IN_FieldMask                              0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_IN_ReadMask                               0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_IN_WriteMask                              0x00000000
#define JM_DEC_TOTAL_WRITES_IN_ResetValue                             0x00000000

#define JM_DEC_TOTAL_WRITES_IN_COUNT                                        31:0
#define JM_DEC_TOTAL_WRITES_IN_COUNT_End                                      31
#define JM_DEC_TOTAL_WRITES_IN_COUNT_Start                                     0
#define JM_DEC_TOTAL_WRITES_IN_COUNT_Type                                    U32



#define jmDECTotalReadBurstsInRegAddrs                                    0x6068
#define JM_DEC_TOTAL_READ_BURSTS_IN_Address                              0x181A0
#define JM_DEC_TOTAL_READ_BURSTS_IN_MSB                                       15
#define JM_DEC_TOTAL_READ_BURSTS_IN_LSB                                        0
#define JM_DEC_TOTAL_READ_BURSTS_IN_BLK                                        0
#define JM_DEC_TOTAL_READ_BURSTS_IN_Count                                      1
#define JM_DEC_TOTAL_READ_BURSTS_IN_FieldMask                         0xFFFFFFFF
#define JM_DEC_TOTAL_READ_BURSTS_IN_ReadMask                          0xFFFFFFFF
#define JM_DEC_TOTAL_READ_BURSTS_IN_WriteMask                         0x00000000
#define JM_DEC_TOTAL_READ_BURSTS_IN_ResetValue                        0x00000000

#define JM_DEC_TOTAL_READ_BURSTS_IN_COUNT                                   31:0
#define JM_DEC_TOTAL_READ_BURSTS_IN_COUNT_End                                 31
#define JM_DEC_TOTAL_READ_BURSTS_IN_COUNT_Start                                0
#define JM_DEC_TOTAL_READ_BURSTS_IN_COUNT_Type                               U32



#define jmDECTotalWriteBurstsInRegAddrs                                   0x6069
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_Address                             0x181A4
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_MSB                                      15
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_LSB                                       0
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_BLK                                       0
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_Count                                     1
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_FieldMask                        0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_ReadMask                         0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_WriteMask                        0x00000000
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_ResetValue                       0x00000000

#define JM_DEC_TOTAL_WRITE_BURSTS_IN_COUNT                                  31:0
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_COUNT_End                                31
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_COUNT_Start                               0
#define JM_DEC_TOTAL_WRITE_BURSTS_IN_COUNT_Type                              U32




#define jmDECTotalReadsReqInRegAddrs                                      0x606A
#define JM_DEC_TOTAL_READS_REQ_IN_Address                                0x181A8
#define JM_DEC_TOTAL_READS_REQ_IN_MSB                                         15
#define JM_DEC_TOTAL_READS_REQ_IN_LSB                                          0
#define JM_DEC_TOTAL_READS_REQ_IN_BLK                                          0
#define JM_DEC_TOTAL_READS_REQ_IN_Count                                        1
#define JM_DEC_TOTAL_READS_REQ_IN_FieldMask                           0xFFFFFFFF
#define JM_DEC_TOTAL_READS_REQ_IN_ReadMask                            0xFFFFFFFF
#define JM_DEC_TOTAL_READS_REQ_IN_WriteMask                           0x00000000
#define JM_DEC_TOTAL_READS_REQ_IN_ResetValue                          0x00000000

#define JM_DEC_TOTAL_READS_REQ_IN_COUNT                                     31:0
#define JM_DEC_TOTAL_READS_REQ_IN_COUNT_End                                   31
#define JM_DEC_TOTAL_READS_REQ_IN_COUNT_Start                                  0
#define JM_DEC_TOTAL_READS_REQ_IN_COUNT_Type                                 U32




#define jmDECTotalWritesReqInRegAddrs                                     0x606B
#define JM_DEC_TOTAL_WRITES_REQ_IN_Address                               0x181AC
#define JM_DEC_TOTAL_WRITES_REQ_IN_MSB                                        15
#define JM_DEC_TOTAL_WRITES_REQ_IN_LSB                                         0
#define JM_DEC_TOTAL_WRITES_REQ_IN_BLK                                         0
#define JM_DEC_TOTAL_WRITES_REQ_IN_Count                                       1
#define JM_DEC_TOTAL_WRITES_REQ_IN_FieldMask                          0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_REQ_IN_ReadMask                           0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_REQ_IN_WriteMask                          0x00000000
#define JM_DEC_TOTAL_WRITES_REQ_IN_ResetValue                         0x00000000

#define JM_DEC_TOTAL_WRITES_REQ_IN_COUNT                                    31:0
#define JM_DEC_TOTAL_WRITES_REQ_IN_COUNT_End                                  31
#define JM_DEC_TOTAL_WRITES_REQ_IN_COUNT_Start                                 0
#define JM_DEC_TOTAL_WRITES_REQ_IN_COUNT_Type                                U32




#define jmDECTotalReadLastsInRegAddrs                                     0x606C
#define JM_DEC_TOTAL_READ_LASTS_IN_Address                               0x181B0
#define JM_DEC_TOTAL_READ_LASTS_IN_MSB                                        15
#define JM_DEC_TOTAL_READ_LASTS_IN_LSB                                         0
#define JM_DEC_TOTAL_READ_LASTS_IN_BLK                                         0
#define JM_DEC_TOTAL_READ_LASTS_IN_Count                                       1
#define JM_DEC_TOTAL_READ_LASTS_IN_FieldMask                          0xFFFFFFFF
#define JM_DEC_TOTAL_READ_LASTS_IN_ReadMask                           0xFFFFFFFF
#define JM_DEC_TOTAL_READ_LASTS_IN_WriteMask                          0x00000000
#define JM_DEC_TOTAL_READ_LASTS_IN_ResetValue                         0x00000000

#define JM_DEC_TOTAL_READ_LASTS_IN_COUNT                                    31:0
#define JM_DEC_TOTAL_READ_LASTS_IN_COUNT_End                                  31
#define JM_DEC_TOTAL_READ_LASTS_IN_COUNT_Start                                 0
#define JM_DEC_TOTAL_READ_LASTS_IN_COUNT_Type                                U32




#define jmDECTotalWriteLastsInRegAddrs                                    0x606D
#define JM_DEC_TOTAL_WRITE_LASTS_IN_Address                              0x181B4
#define JM_DEC_TOTAL_WRITE_LASTS_IN_MSB                                       15
#define JM_DEC_TOTAL_WRITE_LASTS_IN_LSB                                        0
#define JM_DEC_TOTAL_WRITE_LASTS_IN_BLK                                        0
#define JM_DEC_TOTAL_WRITE_LASTS_IN_Count                                      1
#define JM_DEC_TOTAL_WRITE_LASTS_IN_FieldMask                         0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_LASTS_IN_ReadMask                          0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_LASTS_IN_WriteMask                         0x00000000
#define JM_DEC_TOTAL_WRITE_LASTS_IN_ResetValue                        0x00000000

#define JM_DEC_TOTAL_WRITE_LASTS_IN_COUNT                                   31:0
#define JM_DEC_TOTAL_WRITE_LASTS_IN_COUNT_End                                 31
#define JM_DEC_TOTAL_WRITE_LASTS_IN_COUNT_Start                                0
#define JM_DEC_TOTAL_WRITE_LASTS_IN_COUNT_Type                               U32




#define jmDECTotalReadsOUTRegAddrs                                        0x606E
#define JM_DEC_TOTAL_READS_OUT_Address                                   0x181B8
#define JM_DEC_TOTAL_READS_OUT_MSB                                            15
#define JM_DEC_TOTAL_READS_OUT_LSB                                             0
#define JM_DEC_TOTAL_READS_OUT_BLK                                             0
#define JM_DEC_TOTAL_READS_OUT_Count                                           1
#define JM_DEC_TOTAL_READS_OUT_FieldMask                              0xFFFFFFFF
#define JM_DEC_TOTAL_READS_OUT_ReadMask                               0xFFFFFFFF
#define JM_DEC_TOTAL_READS_OUT_WriteMask                              0x00000000
#define JM_DEC_TOTAL_READS_OUT_ResetValue                             0x00000000

#define JM_DEC_TOTAL_READS_OUT_COUNT                                        31:0
#define JM_DEC_TOTAL_READS_OUT_COUNT_End                                      31
#define JM_DEC_TOTAL_READS_OUT_COUNT_Start                                     0
#define JM_DEC_TOTAL_READS_OUT_COUNT_Type                                    U32




#define jmDECTotalWritesOUTRegAddrs                                       0x606F
#define JM_DEC_TOTAL_WRITES_OUT_Address                                  0x181BC
#define JM_DEC_TOTAL_WRITES_OUT_MSB                                           15
#define JM_DEC_TOTAL_WRITES_OUT_LSB                                            0
#define JM_DEC_TOTAL_WRITES_OUT_BLK                                            0
#define JM_DEC_TOTAL_WRITES_OUT_Count                                          1
#define JM_DEC_TOTAL_WRITES_OUT_FieldMask                             0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_OUT_ReadMask                              0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_OUT_WriteMask                             0x00000000
#define JM_DEC_TOTAL_WRITES_OUT_ResetValue                            0x00000000

#define JM_DEC_TOTAL_WRITES_OUT_COUNT                                       31:0
#define JM_DEC_TOTAL_WRITES_OUT_COUNT_End                                     31
#define JM_DEC_TOTAL_WRITES_OUT_COUNT_Start                                    0
#define JM_DEC_TOTAL_WRITES_OUT_COUNT_Type                                   U32




#define jmDECTotalReadBurstsOUTRegAddrs                                   0x6070
#define JM_DEC_TOTAL_READ_BURSTS_OUT_Address                             0x181C0
#define JM_DEC_TOTAL_READ_BURSTS_OUT_MSB                                      15
#define JM_DEC_TOTAL_READ_BURSTS_OUT_LSB                                       0
#define JM_DEC_TOTAL_READ_BURSTS_OUT_BLK                                       0
#define JM_DEC_TOTAL_READ_BURSTS_OUT_Count                                     1
#define JM_DEC_TOTAL_READ_BURSTS_OUT_FieldMask                        0xFFFFFFFF
#define JM_DEC_TOTAL_READ_BURSTS_OUT_ReadMask                         0xFFFFFFFF
#define JM_DEC_TOTAL_READ_BURSTS_OUT_WriteMask                        0x00000000
#define JM_DEC_TOTAL_READ_BURSTS_OUT_ResetValue                       0x00000000

#define JM_DEC_TOTAL_READ_BURSTS_OUT_COUNT                                  31:0
#define JM_DEC_TOTAL_READ_BURSTS_OUT_COUNT_End                                31
#define JM_DEC_TOTAL_READ_BURSTS_OUT_COUNT_Start                               0
#define JM_DEC_TOTAL_READ_BURSTS_OUT_COUNT_Type                              U32




#define jmDECTotalWriteBurstsOUTRegAddrs                                  0x6071
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_Address                            0x181C4
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_MSB                                     15
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_LSB                                      0
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_BLK                                      0
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_Count                                    1
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_FieldMask                       0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_ReadMask                        0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_WriteMask                       0x00000000
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_ResetValue                      0x00000000

#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_COUNT                                 31:0
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_COUNT_End                               31
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_COUNT_Start                              0
#define JM_DEC_TOTAL_WRITE_BURSTS_OUT_COUNT_Type                             U32




#define jmDECTotalReadsReqOUTRegAddrs                                     0x6072
#define JM_DEC_TOTAL_READS_REQ_OUT_Address                               0x181C8
#define JM_DEC_TOTAL_READS_REQ_OUT_MSB                                        15
#define JM_DEC_TOTAL_READS_REQ_OUT_LSB                                         0
#define JM_DEC_TOTAL_READS_REQ_OUT_BLK                                         0
#define JM_DEC_TOTAL_READS_REQ_OUT_Count                                       1
#define JM_DEC_TOTAL_READS_REQ_OUT_FieldMask                          0xFFFFFFFF
#define JM_DEC_TOTAL_READS_REQ_OUT_ReadMask                           0xFFFFFFFF
#define JM_DEC_TOTAL_READS_REQ_OUT_WriteMask                          0x00000000
#define JM_DEC_TOTAL_READS_REQ_OUT_ResetValue                         0x00000000

#define JM_DEC_TOTAL_READS_REQ_OUT_COUNT                                    31:0
#define JM_DEC_TOTAL_READS_REQ_OUT_COUNT_End                                  31
#define JM_DEC_TOTAL_READS_REQ_OUT_COUNT_Start                                 0
#define JM_DEC_TOTAL_READS_REQ_OUT_COUNT_Type                                U32




#define jmDECTotalWritesReqOUTRegAddrs                                    0x6073
#define JM_DEC_TOTAL_WRITES_REQ_OUT_Address                              0x181CC
#define JM_DEC_TOTAL_WRITES_REQ_OUT_MSB                                       15
#define JM_DEC_TOTAL_WRITES_REQ_OUT_LSB                                        0
#define JM_DEC_TOTAL_WRITES_REQ_OUT_BLK                                        0
#define JM_DEC_TOTAL_WRITES_REQ_OUT_Count                                      1
#define JM_DEC_TOTAL_WRITES_REQ_OUT_FieldMask                         0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_REQ_OUT_ReadMask                          0xFFFFFFFF
#define JM_DEC_TOTAL_WRITES_REQ_OUT_WriteMask                         0x00000000
#define JM_DEC_TOTAL_WRITES_REQ_OUT_ResetValue                        0x00000000

#define JM_DEC_TOTAL_WRITES_REQ_OUT_COUNT                                   31:0
#define JM_DEC_TOTAL_WRITES_REQ_OUT_COUNT_End                                 31
#define JM_DEC_TOTAL_WRITES_REQ_OUT_COUNT_Start                                0
#define JM_DEC_TOTAL_WRITES_REQ_OUT_COUNT_Type                               U32




#define jmDECTotalReadLastsOUTRegAddrs                                    0x6074
#define JM_DEC_TOTAL_READ_LASTS_OUT_Address                              0x181D0
#define JM_DEC_TOTAL_READ_LASTS_OUT_MSB                                       15
#define JM_DEC_TOTAL_READ_LASTS_OUT_LSB                                        0
#define JM_DEC_TOTAL_READ_LASTS_OUT_BLK                                        0
#define JM_DEC_TOTAL_READ_LASTS_OUT_Count                                      1
#define JM_DEC_TOTAL_READ_LASTS_OUT_FieldMask                         0xFFFFFFFF
#define JM_DEC_TOTAL_READ_LASTS_OUT_ReadMask                          0xFFFFFFFF
#define JM_DEC_TOTAL_READ_LASTS_OUT_WriteMask                         0x00000000
#define JM_DEC_TOTAL_READ_LASTS_OUT_ResetValue                        0x00000000

#define JM_DEC_TOTAL_READ_LASTS_OUT_COUNT                                   31:0
#define JM_DEC_TOTAL_READ_LASTS_OUT_COUNT_End                                 31
#define JM_DEC_TOTAL_READ_LASTS_OUT_COUNT_Start                                0
#define JM_DEC_TOTAL_READ_LASTS_OUT_COUNT_Type                               U32




#define jmDECTotalWriteLastsOUTRegAddrs                                   0x6075
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_Address                             0x181D4
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_MSB                                      15
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_LSB                                       0
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_BLK                                       0
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_Count                                     1
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_FieldMask                        0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_ReadMask                         0xFFFFFFFF
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_WriteMask                        0x00000000
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_ResetValue                       0x00000000

#define JM_DEC_TOTAL_WRITE_LASTS_OUT_COUNT                                  31:0
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_COUNT_End                                31
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_COUNT_Start                               0
#define JM_DEC_TOTAL_WRITE_LASTS_OUT_COUNT_Type                              U32




#define mwv207regDECDebug0RegAddrs                                        0x6076
#define MWV207REG_DEC_DEBUG0_Address                                     0x181D8
#define MWV207REG_DEC_DEBUG0_MSB                                              15
#define MWV207REG_DEC_DEBUG0_LSB                                               0
#define MWV207REG_DEC_DEBUG0_BLK                                               0
#define MWV207REG_DEC_DEBUG0_Count                                             1
#define MWV207REG_DEC_DEBUG0_FieldMask                                0xFFFFFFFF
#define MWV207REG_DEC_DEBUG0_ReadMask                                 0xFFFFFFFF
#define MWV207REG_DEC_DEBUG0_WriteMask                                0x00000000
#define MWV207REG_DEC_DEBUG0_ResetValue                               0x00000000

#define MWV207REG_DEC_DEBUG0_DEBUG                                          31:0
#define MWV207REG_DEC_DEBUG0_DEBUG_End                                        31
#define MWV207REG_DEC_DEBUG0_DEBUG_Start                                       0
#define MWV207REG_DEC_DEBUG0_DEBUG_Type                                      U32




#define mwv207regDECDebug1RegAddrs                                        0x6077
#define MWV207REG_DEC_DEBUG1_Address                                     0x181DC
#define MWV207REG_DEC_DEBUG1_MSB                                              15
#define MWV207REG_DEC_DEBUG1_LSB                                               0
#define MWV207REG_DEC_DEBUG1_BLK                                               0
#define MWV207REG_DEC_DEBUG1_Count                                             1
#define MWV207REG_DEC_DEBUG1_FieldMask                                0xFFFFFFFF
#define MWV207REG_DEC_DEBUG1_ReadMask                                 0xFFFFFFFF
#define MWV207REG_DEC_DEBUG1_WriteMask                                0x00000000
#define MWV207REG_DEC_DEBUG1_ResetValue                               0x00000000

#define MWV207REG_DEC_DEBUG1_DEBUG                                          31:0
#define MWV207REG_DEC_DEBUG1_DEBUG_End                                        31
#define MWV207REG_DEC_DEBUG1_DEBUG_Start                                       0
#define MWV207REG_DEC_DEBUG1_DEBUG_Type                                      U32




#define mwv207regDECDebug2RegAddrs                                        0x6078
#define MWV207REG_DEC_DEBUG2_Address                                     0x181E0
#define MWV207REG_DEC_DEBUG2_MSB                                              15
#define MWV207REG_DEC_DEBUG2_LSB                                               0
#define MWV207REG_DEC_DEBUG2_BLK                                               0
#define MWV207REG_DEC_DEBUG2_Count                                             1
#define MWV207REG_DEC_DEBUG2_FieldMask                                0xFFFFFFFF
#define MWV207REG_DEC_DEBUG2_ReadMask                                 0xFFFFFFFF
#define MWV207REG_DEC_DEBUG2_WriteMask                                0x00000000
#define MWV207REG_DEC_DEBUG2_ResetValue                               0x00000000

#define MWV207REG_DEC_DEBUG2_DEBUG                                          31:0
#define MWV207REG_DEC_DEBUG2_DEBUG_End                                        31
#define MWV207REG_DEC_DEBUG2_DEBUG_Start                                       0
#define MWV207REG_DEC_DEBUG2_DEBUG_Type                                      U32




#define mwv207regDECDebug3RegAddrs                                        0x6079
#define MWV207REG_DEC_DEBUG3_Address                                     0x181E4
#define MWV207REG_DEC_DEBUG3_MSB                                              15
#define MWV207REG_DEC_DEBUG3_LSB                                               0
#define MWV207REG_DEC_DEBUG3_BLK                                               0
#define MWV207REG_DEC_DEBUG3_Count                                             1
#define MWV207REG_DEC_DEBUG3_FieldMask                                0xFFFFFFFF
#define MWV207REG_DEC_DEBUG3_ReadMask                                 0xFFFFFFFF
#define MWV207REG_DEC_DEBUG3_WriteMask                                0x00000000
#define MWV207REG_DEC_DEBUG3_ResetValue                               0x00000000

#define MWV207REG_DEC_DEBUG3_DEBUG                                          31:0
#define MWV207REG_DEC_DEBUG3_DEBUG_End                                        31
#define MWV207REG_DEC_DEBUG3_DEBUG_Start                                       0
#define MWV207REG_DEC_DEBUG3_DEBUG_Type                                      U32




#define mwv207regDECClearRegAddrs                                         0x6080
#define MWV207REG_DEC_CLEAR_Address                                      0x18200
#define MWV207REG_DEC_CLEAR_MSB                                               15
#define MWV207REG_DEC_CLEAR_LSB                                                4
#define MWV207REG_DEC_CLEAR_BLK                                                4
#define MWV207REG_DEC_CLEAR_Count                                             16
#define MWV207REG_DEC_CLEAR_FieldMask                                 0xFFFFFFFF
#define MWV207REG_DEC_CLEAR_ReadMask                                  0xFFFFFFFF
#define MWV207REG_DEC_CLEAR_WriteMask                                 0xFFFFFFFF
#define MWV207REG_DEC_CLEAR_ResetValue                                0x00000000

#define MWV207REG_DEC_CLEAR_CLEAR                                           31:0
#define MWV207REG_DEC_CLEAR_CLEAR_End                                         31
#define MWV207REG_DEC_CLEAR_CLEAR_Start                                        0
#define MWV207REG_DEC_CLEAR_CLEAR_Type                                       U32




#define mwv207regDECReadExConfigRegAddrs                                  0x6090
#define MWV207REG_DEC_READ_EX_CONFIG_Address                             0x18240
#define MWV207REG_DEC_READ_EX_CONFIG_MSB                                      15
#define MWV207REG_DEC_READ_EX_CONFIG_LSB                                       4
#define MWV207REG_DEC_READ_EX_CONFIG_BLK                                       4
#define MWV207REG_DEC_READ_EX_CONFIG_Count                                    16
#define MWV207REG_DEC_READ_EX_CONFIG_FieldMask                        0x1DFFFFFF
#define MWV207REG_DEC_READ_EX_CONFIG_ReadMask                         0x1DFFFFFF
#define MWV207REG_DEC_READ_EX_CONFIG_WriteMask                        0x1DFFFFFF
#define MWV207REG_DEC_READ_EX_CONFIG_ResetValue                       0x00000000

#define MWV207REG_DEC_READ_EX_CONFIG_TPC                                     0:0
#define MWV207REG_DEC_READ_EX_CONFIG_TPC_End                                   0
#define MWV207REG_DEC_READ_EX_CONFIG_TPC_Start                                 0
#define MWV207REG_DEC_READ_EX_CONFIG_TPC_Type                                U01
#define   MWV207REG_DEC_READ_EX_CONFIG_TPC_DISABLE                           0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_TPC_ENABLE                            0x1


#define MWV207REG_DEC_READ_EX_CONFIG_BIT10                                   1:1
#define MWV207REG_DEC_READ_EX_CONFIG_BIT10_End                                 1
#define MWV207REG_DEC_READ_EX_CONFIG_BIT10_Start                               1
#define MWV207REG_DEC_READ_EX_CONFIG_BIT10_Type                              U01
#define   MWV207REG_DEC_READ_EX_CONFIG_BIT10_DISABLE                         0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_BIT10_ENABLE                          0x1


#define MWV207REG_DEC_READ_EX_CONFIG_YUV                                     2:2
#define MWV207REG_DEC_READ_EX_CONFIG_YUV_End                                   2
#define MWV207REG_DEC_READ_EX_CONFIG_YUV_Start                                 2
#define MWV207REG_DEC_READ_EX_CONFIG_YUV_Type                                U01
#define   MWV207REG_DEC_READ_EX_CONFIG_YUV_Y                                 0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_YUV_UV                                0x1

#define MWV207REG_DEC_READ_EX_CONFIG_CBSR_WIDTH                             15:3
#define MWV207REG_DEC_READ_EX_CONFIG_CBSR_WIDTH_End                           15
#define MWV207REG_DEC_READ_EX_CONFIG_CBSR_WIDTH_Start                          3
#define MWV207REG_DEC_READ_EX_CONFIG_CBSR_WIDTH_Type                         U13


#define MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH                             18:16
#define MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH_End                            18
#define MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH_Start                          16
#define MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH_Type                          U03
#define   MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH_BIT8                        0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH_BIT10                       0x1
#define   MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH_BIT12                       0x2
#define   MWV207REG_DEC_READ_EX_CONFIG_BIT_DEPTH_BIT16                       0x3


#define MWV207REG_DEC_READ_EX_CONFIG_TILE_Y                                19:19
#define MWV207REG_DEC_READ_EX_CONFIG_TILE_Y_End                               19
#define MWV207REG_DEC_READ_EX_CONFIG_TILE_Y_Start                             19
#define MWV207REG_DEC_READ_EX_CONFIG_TILE_Y_Type                             U01
#define   MWV207REG_DEC_READ_EX_CONFIG_TILE_Y_DISABLE                        0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_TILE_Y_ENABLE                         0x1

#define MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE                           24:20
#define MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_End                          24
#define MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_Start                        20
#define MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_Type                        U05
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_DEFAULT                  0x00
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM0              0x01
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM1              0x02
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM2              0x03
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_ISA_STREAM3              0x04
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_TNR_STREAM_Y             0x05
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_TNR_STREAM_UV            0x06
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_GDC_STREAM_Y             0x07
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_GDC_STREAM_U             0x08
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_GDC_STREAM_V             0x09
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_VPU_SRC_Y                0x0A
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_VPU_SRC_UV               0x0B
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_VPU_REF_Y                0x0C
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_VPU_REF_UV               0x0D
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_AY            0x0E
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_AU            0x0F
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_AV            0x10
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BY            0x11
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BU            0x12
#define   MWV207REG_DEC_READ_EX_CONFIG_STREAM_MODE_XYZ_STREAM_BV            0x13

#define MWV207REG_DEC_READ_EX_CONFIG_TS_CACHE_READ_MODE                    26:26
#define MWV207REG_DEC_READ_EX_CONFIG_TS_CACHE_READ_MODE_End                   26
#define MWV207REG_DEC_READ_EX_CONFIG_TS_CACHE_READ_MODE_Start                 26
#define MWV207REG_DEC_READ_EX_CONFIG_TS_CACHE_READ_MODE_Type                 U01
#define   MWV207REG_DEC_READ_EX_CONFIG_TS_CACHE_READ_MODE_DISABLE            0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_TS_CACHE_READ_MODE_ENABLE             0x1


#define MWV207REG_DEC_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT               27:27
#define MWV207REG_DEC_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_End              27
#define MWV207REG_DEC_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Start            27
#define MWV207REG_DEC_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Type            U01
#define   MWV207REG_DEC_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_LRU           0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_FIFO          0x1


#define MWV207REG_DEC_READ_EX_CONFIG_INTEL_P010                            28:28
#define MWV207REG_DEC_READ_EX_CONFIG_INTEL_P010_End                           28
#define MWV207REG_DEC_READ_EX_CONFIG_INTEL_P010_Start                         28
#define MWV207REG_DEC_READ_EX_CONFIG_INTEL_P010_Type                         U01
#define   MWV207REG_DEC_READ_EX_CONFIG_INTEL_P010_DISABLE                    0x0
#define   MWV207REG_DEC_READ_EX_CONFIG_INTEL_P010_ENABLE                     0x1




#define mwv207regDECReadStrideRegAddrs                                    0x60A0
#define MWV207REG_DEC_READ_STRIDE_Address                                0x18280
#define MWV207REG_DEC_READ_STRIDE_MSB                                         15
#define MWV207REG_DEC_READ_STRIDE_LSB                                          4
#define MWV207REG_DEC_READ_STRIDE_BLK                                          4
#define MWV207REG_DEC_READ_STRIDE_Count                                       16
#define MWV207REG_DEC_READ_STRIDE_FieldMask                           0x0003FFFF
#define MWV207REG_DEC_READ_STRIDE_ReadMask                            0x0003FFFC
#define MWV207REG_DEC_READ_STRIDE_WriteMask                           0x0003FFFC
#define MWV207REG_DEC_READ_STRIDE_ResetValue                          0x00000000

#define MWV207REG_DEC_READ_STRIDE_STRIDE                                    17:0
#define MWV207REG_DEC_READ_STRIDE_STRIDE_End                                  17
#define MWV207REG_DEC_READ_STRIDE_STRIDE_Start                                 0
#define MWV207REG_DEC_READ_STRIDE_STRIDE_Type                                U18




#define mwv207regDECWriteExConfigRegAddrs                                 0x60B0
#define MWV207REG_DEC_WRITE_EX_CONFIG_Address                            0x182C0
#define MWV207REG_DEC_WRITE_EX_CONFIG_MSB                                     15
#define MWV207REG_DEC_WRITE_EX_CONFIG_LSB                                      4
#define MWV207REG_DEC_WRITE_EX_CONFIG_BLK                                      4
#define MWV207REG_DEC_WRITE_EX_CONFIG_Count                                   16
#define MWV207REG_DEC_WRITE_EX_CONFIG_FieldMask                       0x1DFFFFFF
#define MWV207REG_DEC_WRITE_EX_CONFIG_ReadMask                        0x1DFFFFFF
#define MWV207REG_DEC_WRITE_EX_CONFIG_WriteMask                       0x1DFFFFFF
#define MWV207REG_DEC_WRITE_EX_CONFIG_ResetValue                      0x00000000


#define MWV207REG_DEC_WRITE_EX_CONFIG_TPC                                    0:0
#define MWV207REG_DEC_WRITE_EX_CONFIG_TPC_End                                  0
#define MWV207REG_DEC_WRITE_EX_CONFIG_TPC_Start                                0
#define MWV207REG_DEC_WRITE_EX_CONFIG_TPC_Type                               U01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_TPC_DISABLE                          0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_TPC_ENABLE                           0x1


#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT10                                  1:1
#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT10_End                                1
#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT10_Start                              1
#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT10_Type                             U01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_BIT10_DISABLE                        0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_BIT10_ENABLE                         0x1


#define MWV207REG_DEC_WRITE_EX_CONFIG_YUV                                    2:2
#define MWV207REG_DEC_WRITE_EX_CONFIG_YUV_End                                  2
#define MWV207REG_DEC_WRITE_EX_CONFIG_YUV_Start                                2
#define MWV207REG_DEC_WRITE_EX_CONFIG_YUV_Type                               U01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_YUV_Y                                0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_YUV_UV                               0x1

#define MWV207REG_DEC_WRITE_EX_CONFIG_CBSR_WIDTH                            15:3
#define MWV207REG_DEC_WRITE_EX_CONFIG_CBSR_WIDTH_End                          15
#define MWV207REG_DEC_WRITE_EX_CONFIG_CBSR_WIDTH_Start                         3
#define MWV207REG_DEC_WRITE_EX_CONFIG_CBSR_WIDTH_Type                        U13


#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH                            18:16
#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH_End                           18
#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH_Start                         16
#define MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH_Type                         U03
#define   MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH_BIT8                       0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH_BIT10                      0x1
#define   MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH_BIT12                      0x2
#define   MWV207REG_DEC_WRITE_EX_CONFIG_BIT_DEPTH_BIT16                      0x3


#define MWV207REG_DEC_WRITE_EX_CONFIG_TILE_Y                               19:19
#define MWV207REG_DEC_WRITE_EX_CONFIG_TILE_Y_End                              19
#define MWV207REG_DEC_WRITE_EX_CONFIG_TILE_Y_Start                            19
#define MWV207REG_DEC_WRITE_EX_CONFIG_TILE_Y_Type                            U01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_TILE_Y_DISABLE                       0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_TILE_Y_ENABLE                        0x1

#define MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE                          24:20
#define MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_End                         24
#define MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_Start                       20
#define MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_Type                       U05
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_RESERVED                0x00
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM0            0x01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM1            0x02
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM2            0x03
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_MIPI_STREAM3            0x04
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM0_Y           0x05
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM0_U           0x06
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM0_V           0x07
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM1_Y           0x08
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM1_U           0x09
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM1_V           0x0A
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM2_Y           0x0B
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM2_U           0x0C
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_OSF_STREAM2_V           0x0D
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_PSA_STREAM_Y            0x0E
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_PSA_STREAM_U            0x0F
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_PSA_STREAM_V            0x10
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_TNR_STREAM_Y            0x11
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_TNR_STREAM_UV           0x12
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_VPU_STREAM_Y            0x13
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_VPU_STREAM_UV           0x14
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_XYZ_STREAM_Y            0x15
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_XYZ_STREAM_U            0x16
#define   MWV207REG_DEC_WRITE_EX_CONFIG_STREAM_MODE_XYZ_STREAM_V            0x17

#define MWV207REG_DEC_WRITE_EX_CONFIG_TS_CACHE_READ_MODE                   26:26
#define MWV207REG_DEC_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_End                  26
#define MWV207REG_DEC_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_Start                26
#define MWV207REG_DEC_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_Type                U01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_DISABLE           0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_TS_CACHE_READ_MODE_ENABLE            0x1

#define MWV207REG_DEC_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT              27:27
#define MWV207REG_DEC_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_End             27
#define MWV207REG_DEC_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Start           27
#define MWV207REG_DEC_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_Type           U01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_LRU          0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_PIXEL_CACHE_REPLACEMENT_FIFO         0x1


#define MWV207REG_DEC_WRITE_EX_CONFIG_INTEL_P010                           28:28
#define MWV207REG_DEC_WRITE_EX_CONFIG_INTEL_P010_End                          28
#define MWV207REG_DEC_WRITE_EX_CONFIG_INTEL_P010_Start                        28
#define MWV207REG_DEC_WRITE_EX_CONFIG_INTEL_P010_Type                        U01
#define   MWV207REG_DEC_WRITE_EX_CONFIG_INTEL_P010_DISABLE                   0x0
#define   MWV207REG_DEC_WRITE_EX_CONFIG_INTEL_P010_ENABLE                    0x1




#define mwv207regDECWriteStrideRegAddrs                                   0x60C0
#define MWV207REG_DEC_WRITE_STRIDE_Address                               0x18300
#define MWV207REG_DEC_WRITE_STRIDE_MSB                                        15
#define MWV207REG_DEC_WRITE_STRIDE_LSB                                         4
#define MWV207REG_DEC_WRITE_STRIDE_BLK                                         4
#define MWV207REG_DEC_WRITE_STRIDE_Count                                      16
#define MWV207REG_DEC_WRITE_STRIDE_FieldMask                          0x0003FFFF
#define MWV207REG_DEC_WRITE_STRIDE_ReadMask                           0x0003FFFC
#define MWV207REG_DEC_WRITE_STRIDE_WriteMask                          0x0003FFFC
#define MWV207REG_DEC_WRITE_STRIDE_ResetValue                         0x00000000

#define MWV207REG_DEC_WRITE_STRIDE_STRIDE                                   17:0
#define MWV207REG_DEC_WRITE_STRIDE_STRIDE_End                                 17
#define MWV207REG_DEC_WRITE_STRIDE_STRIDE_Start                                0
#define MWV207REG_DEC_WRITE_STRIDE_STRIDE_Type                               U18




#define mwv207regDECControlExRegAddrs                                     0x607A
#define MWV207REG_DEC_CONTROL_EX_Address                                 0x181E8
#define MWV207REG_DEC_CONTROL_EX_MSB                                          15
#define MWV207REG_DEC_CONTROL_EX_LSB                                           0
#define MWV207REG_DEC_CONTROL_EX_BLK                                           0
#define MWV207REG_DEC_CONTROL_EX_Count                                         1
#define MWV207REG_DEC_CONTROL_EX_FieldMask                            0x00000FFF
#define MWV207REG_DEC_CONTROL_EX_ReadMask                             0x00000FFF
#define MWV207REG_DEC_CONTROL_EX_WriteMask                            0x00000FFF
#define MWV207REG_DEC_CONTROL_EX_ResetValue                           0x00000000


#define MWV207REG_DEC_CONTROL_EX_AXUSER                                     11:0
#define MWV207REG_DEC_CONTROL_EX_AXUSER_End                                   11
#define MWV207REG_DEC_CONTROL_EX_AXUSER_Start                                  0
#define MWV207REG_DEC_CONTROL_EX_AXUSER_Type                                 U12




#define mwv207regDECReadBufferEndRegAddrs                                 0x60D0
#define MWV207REG_DEC_READ_BUFFER_END_Address                            0x18340
#define MWV207REG_DEC_READ_BUFFER_END_MSB                                     15
#define MWV207REG_DEC_READ_BUFFER_END_LSB                                      4
#define MWV207REG_DEC_READ_BUFFER_END_BLK                                      4
#define MWV207REG_DEC_READ_BUFFER_END_Count                                   16
#define MWV207REG_DEC_READ_BUFFER_END_FieldMask                       0xFFFFFFFF
#define MWV207REG_DEC_READ_BUFFER_END_ReadMask                        0xFFFFFFFF
#define MWV207REG_DEC_READ_BUFFER_END_WriteMask                       0xFFFFFFFF
#define MWV207REG_DEC_READ_BUFFER_END_ResetValue                      0x00000000

#define MWV207REG_DEC_READ_BUFFER_END_ADDRESS                               31:0
#define MWV207REG_DEC_READ_BUFFER_END_ADDRESS_End                             31
#define MWV207REG_DEC_READ_BUFFER_END_ADDRESS_Start                            0
#define MWV207REG_DEC_READ_BUFFER_END_ADDRESS_Type                           U32




#define mwv207regDECWriteBufferEndRegAddrs                                0x60E0
#define MWV207REG_DEC_WRITE_BUFFER_END_Address                           0x18380
#define MWV207REG_DEC_WRITE_BUFFER_END_MSB                                    15
#define MWV207REG_DEC_WRITE_BUFFER_END_LSB                                     4
#define MWV207REG_DEC_WRITE_BUFFER_END_BLK                                     4
#define MWV207REG_DEC_WRITE_BUFFER_END_Count                                  16
#define MWV207REG_DEC_WRITE_BUFFER_END_FieldMask                      0xFFFFFFFF
#define MWV207REG_DEC_WRITE_BUFFER_END_ReadMask                       0xFFFFFFFF
#define MWV207REG_DEC_WRITE_BUFFER_END_WriteMask                      0xFFFFFFFF
#define MWV207REG_DEC_WRITE_BUFFER_END_ResetValue                     0x00000000

#define MWV207REG_DEC_WRITE_BUFFER_END_ADDRESS                              31:0
#define MWV207REG_DEC_WRITE_BUFFER_END_ADDRESS_End                            31
#define MWV207REG_DEC_WRITE_BUFFER_END_ADDRESS_Start                           0
#define MWV207REG_DEC_WRITE_BUFFER_END_ADDRESS_Type                          U32


#endif


