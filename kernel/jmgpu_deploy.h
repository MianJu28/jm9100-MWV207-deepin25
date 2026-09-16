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




#ifndef __jmgpuregMultiChip_h__
#define __jmgpuregMultiChip_h__





#define mwv207regMultiChipControlRegAddrs                                 0x0E80
#define MWV207REG_MULTI_CHIP_CONTROL_Address                             0x03A00
#define MWV207REG_MULTI_CHIP_CONTROL_MSB                                      15
#define MWV207REG_MULTI_CHIP_CONTROL_LSB                                       0
#define MWV207REG_MULTI_CHIP_CONTROL_BLK                                       0
#define MWV207REG_MULTI_CHIP_CONTROL_Count                                     1
#define MWV207REG_MULTI_CHIP_CONTROL_FieldMask                        0xF1FFFF77
#define MWV207REG_MULTI_CHIP_CONTROL_ReadMask                         0xF1FFFF77
#define MWV207REG_MULTI_CHIP_CONTROL_WriteMask                        0xF1FFFF77
#define MWV207REG_MULTI_CHIP_CONTROL_ResetValue                       0x00000000


#define MWV207REG_MULTI_CHIP_CONTROL_MODE                                    2:0
#define MWV207REG_MULTI_CHIP_CONTROL_MODE_End                                  2
#define MWV207REG_MULTI_CHIP_CONTROL_MODE_Start                                0
#define MWV207REG_MULTI_CHIP_CONTROL_MODE_Type                               U03

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_OFF                              0x0

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_WINDOW                           0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_INTERLEAVED16X16                 0x2

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_INTERLEAVED32X32                 0x3

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_INTERLEAVED64X64                 0x4

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_INTERLEAVED128X64                0x5

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_INTERLEAVED128X128               0x6

#define   MWV207REG_MULTI_CHIP_CONTROL_MODE_INTERLEAVED                      0x7


#define MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE                       6:4
#define MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_End                     6
#define MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_Start                   4
#define MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_Type                  U03

#define   MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_SET1                0x0

#define   MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_SET2                0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_SET3                0x2

#define   MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_SET4                0x3

#define   MWV207REG_MULTI_CHIP_CONTROL_LOAD_BALANCE_MODE_SET8                0x7

#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET0                       8:8
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET0_End                     8
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET0_Start                   8
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET0_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET0_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET0_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET1                       9:9
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET1_End                     9
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET1_Start                   9
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET1_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET1_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET1_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET2                     10:10
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET2_End                    10
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET2_Start                  10
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET2_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET2_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET2_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET3                     11:11
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET3_End                    11
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET3_Start                  11
#define MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET3_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET3_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU0_MAPPING_SET3_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET0                     12:12
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET0_End                    12
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET0_Start                  12
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET0_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET0_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET0_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET1                     13:13
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET1_End                    13
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET1_Start                  13
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET1_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET1_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET1_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET2                     14:14
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET2_End                    14
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET2_Start                  14
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET2_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET2_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET2_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET3                     15:15
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET3_End                    15
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET3_Start                  15
#define MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET3_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET3_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU1_MAPPING_SET3_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET0                     16:16
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET0_End                    16
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET0_Start                  16
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET0_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET0_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET0_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET1                     17:17
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET1_End                    17
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET1_Start                  17
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET1_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET1_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET1_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET2                     18:18
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET2_End                    18
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET2_Start                  18
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET2_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET2_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET2_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET3                     19:19
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET3_End                    19
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET3_Start                  19
#define MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET3_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET3_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU2_MAPPING_SET3_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET0                     20:20
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET0_End                    20
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET0_Start                  20
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET0_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET0_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET0_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET1                     21:21
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET1_End                    21
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET1_Start                  21
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET1_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET1_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET1_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET2                     22:22
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET2_End                    22
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET2_Start                  22
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET2_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET2_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET2_UNMAPPED            0x0

#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET3                     23:23
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET3_End                    23
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET3_Start                  23
#define MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET3_Type                  U01

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET3_MAPPED              0x1

#define   MWV207REG_MULTI_CHIP_CONTROL_GPU3_MAPPING_SET3_UNMAPPED            0x0


#define MWV207REG_MULTI_CHIP_CONTROL_SIMPLIFIED_CHECKERBOARD_MODE          24:24
#define MWV207REG_MULTI_CHIP_CONTROL_SIMPLIFIED_CHECKERBOARD_MODE_End         24
#define MWV207REG_MULTI_CHIP_CONTROL_SIMPLIFIED_CHECKERBOARD_MODE_Start       24
#define MWV207REG_MULTI_CHIP_CONTROL_SIMPLIFIED_CHECKERBOARD_MODE_Type       U01
#define   MWV207REG_MULTI_CHIP_CONTROL_SIMPLIFIED_CHECKERBOARD_MODE_DISABLED 0x0
#define   MWV207REG_MULTI_CHIP_CONTROL_SIMPLIFIED_CHECKERBOARD_MODE_ENABLED  0x1


#define MWV207REG_MULTI_CHIP_CONTROL_ENABLE_GPU_ENABLE                     31:28
#define MWV207REG_MULTI_CHIP_CONTROL_ENABLE_GPU_ENABLE_End                    31
#define MWV207REG_MULTI_CHIP_CONTROL_ENABLE_GPU_ENABLE_Start                  28
#define MWV207REG_MULTI_CHIP_CONTROL_ENABLE_GPU_ENABLE_Type                  U04




#define mwv207regMultiChipTopLeftRegAddrs                                 0x0E81
#define MWV207REG_MULTI_CHIP_TOP_LEFT_Address                            0x03A04
#define MWV207REG_MULTI_CHIP_TOP_LEFT_MSB                                     15
#define MWV207REG_MULTI_CHIP_TOP_LEFT_LSB                                      0
#define MWV207REG_MULTI_CHIP_TOP_LEFT_BLK                                      0
#define MWV207REG_MULTI_CHIP_TOP_LEFT_Count                                    1
#define MWV207REG_MULTI_CHIP_TOP_LEFT_FieldMask                       0x7FFF7FFF
#define MWV207REG_MULTI_CHIP_TOP_LEFT_ReadMask                        0x7FFF7FFF
#define MWV207REG_MULTI_CHIP_TOP_LEFT_WriteMask                       0x7FFF7FFF
#define MWV207REG_MULTI_CHIP_TOP_LEFT_ResetValue                      0x00000000

#define MWV207REG_MULTI_CHIP_TOP_LEFT_Y                                    30:16
#define MWV207REG_MULTI_CHIP_TOP_LEFT_Y_End                                   30
#define MWV207REG_MULTI_CHIP_TOP_LEFT_Y_Start                                 16
#define MWV207REG_MULTI_CHIP_TOP_LEFT_Y_Type                                 U15

#define MWV207REG_MULTI_CHIP_TOP_LEFT_X                                     14:0
#define MWV207REG_MULTI_CHIP_TOP_LEFT_X_End                                   14
#define MWV207REG_MULTI_CHIP_TOP_LEFT_X_Start                                  0
#define MWV207REG_MULTI_CHIP_TOP_LEFT_X_Type                                 U15




#define mwv207regMultiChipBottomRightRegAddrs                             0x0E82
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_Address                        0x03A08
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_MSB                                 15
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_LSB                                  0
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_BLK                                  0
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_Count                                1
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_FieldMask                   0x7FFF7FFF
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_ReadMask                    0x7FFF7FFF
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_WriteMask                   0x7FFF7FFF
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_ResetValue                  0x00000000

#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_Y                                30:16
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_Y_End                               30
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_Y_Start                             16
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_Y_Type                             U15

#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_X                                 14:0
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_X_End                               14
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_X_Start                              0
#define MWV207REG_MULTI_CHIP_BOTTOM_RIGHT_X_Type                             U15




#define mwv207regMultiChipSetMappingRegAddrs                              0x0E83
#define MWV207REG_MULTI_CHIP_SET_MAPPING_Address                         0x03A0C
#define MWV207REG_MULTI_CHIP_SET_MAPPING_MSB                                  15
#define MWV207REG_MULTI_CHIP_SET_MAPPING_LSB                                   0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_BLK                                   0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_Count                                 1
#define MWV207REG_MULTI_CHIP_SET_MAPPING_FieldMask                    0x0000FFFF
#define MWV207REG_MULTI_CHIP_SET_MAPPING_ReadMask                     0x0000FFFF
#define MWV207REG_MULTI_CHIP_SET_MAPPING_WriteMask                    0x0000FFFF
#define MWV207REG_MULTI_CHIP_SET_MAPPING_ResetValue                   0x00000000


#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU0                                3:0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU0_End                              3
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU0_Start                            0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU0_Type                           U04


#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU1                                7:4
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU1_End                              7
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU1_Start                            4
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU1_Type                           U04


#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU2                               11:8
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU2_End                             11
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU2_Start                            8
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU2_Type                           U04


#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU3                              15:12
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU3_End                             15
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU3_Start                           12
#define MWV207REG_MULTI_CHIP_SET_MAPPING_GPU3_Type                           U04




#define mwv207regMultiChipSetMappingExRegAddrs                            0x0E84
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_Address                      0x03A10
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_MSB                               15
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_LSB                                0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_BLK                                0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_Count                              1
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_FieldMask                 0xFFFFFFFF
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_ReadMask                  0xFFFFFFFF
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_WriteMask                 0xFFFFFFFF
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_ResetValue                0x00000000


#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU4                             7:0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU4_End                           7
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU4_Start                         0
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU4_Type                        U08


#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU5                            15:8
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU5_End                          15
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU5_Start                         8
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU5_Type                        U08


#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU6                           23:16
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU6_End                          23
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU6_Start                        16
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU6_Type                        U08


#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU7                           31:24
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU7_End                          31
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU7_Start                        24
#define MWV207REG_MULTI_CHIP_SET_MAPPING_EX_GPU7_Type                        U08


#endif


