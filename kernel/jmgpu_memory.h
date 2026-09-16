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




#ifndef __jmgpuregComposition_h__
#define __jmgpuregComposition_h__





#define mwv207regCEOriginRegAddrs                                         0x0C00
#define MWV207REG_CE_ORIGIN_Address                                      0x03000
#define MWV207REG_CE_ORIGIN_MSB                                               15
#define MWV207REG_CE_ORIGIN_LSB                                                0
#define MWV207REG_CE_ORIGIN_BLK                                                0
#define MWV207REG_CE_ORIGIN_Count                                              1
#define MWV207REG_CE_ORIGIN_FieldMask                                 0x3FFF3FFF
#define MWV207REG_CE_ORIGIN_ReadMask                                  0x3FFF3FFF
#define MWV207REG_CE_ORIGIN_WriteMask                                 0x3FFF3FFF
#define MWV207REG_CE_ORIGIN_ResetValue                                0x00000000


#define MWV207REG_CE_ORIGIN_X                                               13:0
#define MWV207REG_CE_ORIGIN_X_End                                             13
#define MWV207REG_CE_ORIGIN_X_Start                                            0
#define MWV207REG_CE_ORIGIN_X_Type                                           U14


#define MWV207REG_CE_ORIGIN_Y                                              29:16
#define MWV207REG_CE_ORIGIN_Y_End                                             29
#define MWV207REG_CE_ORIGIN_Y_Start                                           16
#define MWV207REG_CE_ORIGIN_Y_Type                                           U14




#define mwv207regCESizeRegAddrs                                           0x0C01
#define MWV207REG_CE_SIZE_Address                                        0x03004
#define MWV207REG_CE_SIZE_MSB                                                 15
#define MWV207REG_CE_SIZE_LSB                                                  0
#define MWV207REG_CE_SIZE_BLK                                                  0
#define MWV207REG_CE_SIZE_Count                                                1
#define MWV207REG_CE_SIZE_FieldMask                                   0x7FFF7FFF
#define MWV207REG_CE_SIZE_ReadMask                                    0x7FFF7FFF
#define MWV207REG_CE_SIZE_WriteMask                                   0x7FFF7FFF
#define MWV207REG_CE_SIZE_ResetValue                                  0x00000000


#define MWV207REG_CE_SIZE_WIDTH                                             14:0
#define MWV207REG_CE_SIZE_WIDTH_End                                           14
#define MWV207REG_CE_SIZE_WIDTH_Start                                          0
#define MWV207REG_CE_SIZE_WIDTH_Type                                         U15


#define MWV207REG_CE_SIZE_HEIGHT                                           30:16
#define MWV207REG_CE_SIZE_HEIGHT_End                                          30
#define MWV207REG_CE_SIZE_HEIGHT_Start                                        16
#define MWV207REG_CE_SIZE_HEIGHT_Type                                        U15




#define mwv207regCEStateMemoryRegAddrs                                    0x0C02
#define MWV207REG_CE_STATE_MEMORY_Address                                0x03008
#define MWV207REG_CE_STATE_MEMORY_MSB                                         15
#define MWV207REG_CE_STATE_MEMORY_LSB                                          0
#define MWV207REG_CE_STATE_MEMORY_BLK                                          0
#define MWV207REG_CE_STATE_MEMORY_Count                                        1
#define MWV207REG_CE_STATE_MEMORY_FieldMask                           0xFFFFFFFF
#define MWV207REG_CE_STATE_MEMORY_ReadMask                            0xFFFFFFFF
#define MWV207REG_CE_STATE_MEMORY_WriteMask                           0xFFFFFFFF
#define MWV207REG_CE_STATE_MEMORY_ResetValue                          0x00000000

#define MWV207REG_CE_STATE_MEMORY_ADDRESS                                   31:0
#define MWV207REG_CE_STATE_MEMORY_ADDRESS_End                                 31
#define MWV207REG_CE_STATE_MEMORY_ADDRESS_Start                                0
#define MWV207REG_CE_STATE_MEMORY_ADDRESS_Type                               U32




#define mwv207regCEExecuteRegAddrs                                        0x0C03
#define MWV207REG_CE_EXECUTE_Address                                     0x0300C
#define MWV207REG_CE_EXECUTE_MSB                                              15
#define MWV207REG_CE_EXECUTE_LSB                                               0
#define MWV207REG_CE_EXECUTE_BLK                                               0
#define MWV207REG_CE_EXECUTE_Count                                             1
#define MWV207REG_CE_EXECUTE_FieldMask                                0x011F1133
#define MWV207REG_CE_EXECUTE_ReadMask                                 0x011F1133
#define MWV207REG_CE_EXECUTE_WriteMask                                0x011F1133
#define MWV207REG_CE_EXECUTE_ResetValue                               0x00000000

#define MWV207REG_CE_EXECUTE_EXECUTE                                         1:0
#define MWV207REG_CE_EXECUTE_EXECUTE_End                                       1
#define MWV207REG_CE_EXECUTE_EXECUTE_Start                                     0
#define MWV207REG_CE_EXECUTE_EXECUTE_Type                                    U02

#define   MWV207REG_CE_EXECUTE_EXECUTE_IDLE                                  0x0

#define   MWV207REG_CE_EXECUTE_EXECUTE_TRIGGER                               0x1
#define   MWV207REG_CE_EXECUTE_EXECUTE_LOAD                                  0x3

#define MWV207REG_CE_EXECUTE_DO_SEMAPHORE                                    5:4
#define MWV207REG_CE_EXECUTE_DO_SEMAPHORE_End                                  5
#define MWV207REG_CE_EXECUTE_DO_SEMAPHORE_Start                                4
#define MWV207REG_CE_EXECUTE_DO_SEMAPHORE_Type                               U02

#define   MWV207REG_CE_EXECUTE_DO_SEMAPHORE_NONE                             0x0

#define   MWV207REG_CE_EXECUTE_DO_SEMAPHORE_BEFORE                           0x1

#define   MWV207REG_CE_EXECUTE_DO_SEMAPHORE_AFTER                            0x2

#define   MWV207REG_CE_EXECUTE_DO_SEMAPHORE_BEFORE_AFTER                     0x3


#define MWV207REG_CE_EXECUTE_DO_FLUSH                                        8:8
#define MWV207REG_CE_EXECUTE_DO_FLUSH_End                                      8
#define MWV207REG_CE_EXECUTE_DO_FLUSH_Start                                    8
#define MWV207REG_CE_EXECUTE_DO_FLUSH_Type                                   U01


#define MWV207REG_CE_EXECUTE_DO_EVENT                                      12:12
#define MWV207REG_CE_EXECUTE_DO_EVENT_End                                     12
#define MWV207REG_CE_EXECUTE_DO_EVENT_Start                                   12
#define MWV207REG_CE_EXECUTE_DO_EVENT_Type                                   U01


#define MWV207REG_CE_EXECUTE_EVENT_ID                                      20:16
#define MWV207REG_CE_EXECUTE_EVENT_ID_End                                     20
#define MWV207REG_CE_EXECUTE_EVENT_ID_Start                                   16
#define MWV207REG_CE_EXECUTE_EVENT_ID_Type                                   U05

#define MWV207REG_CE_EXECUTE_PRE_FLUSH                                     24:24
#define MWV207REG_CE_EXECUTE_PRE_FLUSH_End                                    24
#define MWV207REG_CE_EXECUTE_PRE_FLUSH_Start                                  24
#define MWV207REG_CE_EXECUTE_PRE_FLUSH_Type                                  U01




#define mwv207regCEProgramRegAddrs                                        0x0C04
#define MWV207REG_CE_PROGRAM_Address                                     0x03010
#define MWV207REG_CE_PROGRAM_MSB                                              15
#define MWV207REG_CE_PROGRAM_LSB                                               0
#define MWV207REG_CE_PROGRAM_BLK                                               0
#define MWV207REG_CE_PROGRAM_Count                                             1
#define MWV207REG_CE_PROGRAM_FieldMask                                0xFFFFFFFF
#define MWV207REG_CE_PROGRAM_ReadMask                                 0xFFFFFFFF
#define MWV207REG_CE_PROGRAM_WriteMask                                0xFFFFFFFF
#define MWV207REG_CE_PROGRAM_ResetValue                               0x00000000


#define MWV207REG_CE_PROGRAM_START                                          15:0
#define MWV207REG_CE_PROGRAM_START_End                                        15
#define MWV207REG_CE_PROGRAM_START_Start                                       0
#define MWV207REG_CE_PROGRAM_START_Type                                      U16


#define MWV207REG_CE_PROGRAM_END                                           31:16
#define MWV207REG_CE_PROGRAM_END_End                                          31
#define MWV207REG_CE_PROGRAM_END_Start                                        16
#define MWV207REG_CE_PROGRAM_END_Type                                        U16




#define mwv207regCEConfigRegAddrs                                         0x0C05
#define MWV207REG_CE_CONFIG_Address                                      0x03014
#define MWV207REG_CE_CONFIG_MSB                                               15
#define MWV207REG_CE_CONFIG_LSB                                                0
#define MWV207REG_CE_CONFIG_BLK                                                0
#define MWV207REG_CE_CONFIG_Count                                              1
#define MWV207REG_CE_CONFIG_FieldMask                                 0xFFF1FFFF
#define MWV207REG_CE_CONFIG_ReadMask                                  0xFFF1FFFF
#define MWV207REG_CE_CONFIG_WriteMask                                 0xFFF1FFFF
#define MWV207REG_CE_CONFIG_ResetValue                                0x00000000


#define MWV207REG_CE_CONFIG_STRIDE                                          16:0
#define MWV207REG_CE_CONFIG_STRIDE_End                                        16
#define MWV207REG_CE_CONFIG_STRIDE_Start                                       0
#define MWV207REG_CE_CONFIG_STRIDE_Type                                      U17


#define MWV207REG_CE_CONFIG_TILING                                         21:20
#define MWV207REG_CE_CONFIG_TILING_End                                        21
#define MWV207REG_CE_CONFIG_TILING_Start                                      20
#define MWV207REG_CE_CONFIG_TILING_Type                                      U02

#define   MWV207REG_CE_CONFIG_TILING_TILED                                   0x0

#define   MWV207REG_CE_CONFIG_TILING_SUPER_TILED                             0x1

#define   MWV207REG_CE_CONFIG_TILING_LINEAR                                  0x2


#define MWV207REG_CE_CONFIG_FORMAT                                         29:24
#define MWV207REG_CE_CONFIG_FORMAT_End                                        29
#define MWV207REG_CE_CONFIG_FORMAT_Start                                      24
#define MWV207REG_CE_CONFIG_FORMAT_Type                                      U06
#define   MWV207REG_CE_CONFIG_FORMAT_X4R4G4B4                               0x00
#define   MWV207REG_CE_CONFIG_FORMAT_A4R4G4B4                               0x01
#define   MWV207REG_CE_CONFIG_FORMAT_X1R5G5B5                               0x02
#define   MWV207REG_CE_CONFIG_FORMAT_A1R5G5B5                               0x03
#define   MWV207REG_CE_CONFIG_FORMAT_R5G6B5                                 0x04
#define   MWV207REG_CE_CONFIG_FORMAT_X8R8G8B8                               0x05
#define   MWV207REG_CE_CONFIG_FORMAT_A8R8G8B8                               0x06
#define   MWV207REG_CE_CONFIG_FORMAT_YUY2                                   0x07
#define   MWV207REG_CE_CONFIG_FORMAT_UYVY                                   0x08
#define   MWV207REG_CE_CONFIG_FORMAT_INDEX8                                 0x09
#define   MWV207REG_CE_CONFIG_FORMAT_MONOCHROME                             0x0A
#define   MWV207REG_CE_CONFIG_FORMAT_HDR7E3                                 0x0B
#define   MWV207REG_CE_CONFIG_FORMAT_HDR6E4                                 0x0C
#define   MWV207REG_CE_CONFIG_FORMAT_HDR5E5                                 0x0D
#define   MWV207REG_CE_CONFIG_FORMAT_HDR6E5                                 0x0E
#define   MWV207REG_CE_CONFIG_FORMAT_YV12                                   0x0F
#define   MWV207REG_CE_CONFIG_FORMAT_A8                                     0x10
#define   MWV207REG_CE_CONFIG_FORMAT_RF16                                   0x11
#define   MWV207REG_CE_CONFIG_FORMAT_RF16GF16                               0x12
#define   MWV207REG_CE_CONFIG_FORMAT_RF16GF16BF16AF16                       0x13
#define   MWV207REG_CE_CONFIG_FORMAT_RF32                                   0x14
#define   MWV207REG_CE_CONFIG_FORMAT_RF32GF32                               0x15
#define   MWV207REG_CE_CONFIG_FORMAT_R10G10B10A2                            0x16
#define   MWV207REG_CE_CONFIG_FORMAT_RI8                                    0x17
#define   MWV207REG_CE_CONFIG_FORMAT_RI8GI8                                 0x18
#define   MWV207REG_CE_CONFIG_FORMAT_RI8GI8BI8AI8                           0x19
#define   MWV207REG_CE_CONFIG_FORMAT_RI16                                   0x1A
#define   MWV207REG_CE_CONFIG_FORMAT_RI16GI16                               0x1B
#define   MWV207REG_CE_CONFIG_FORMAT_RI16GI16BI16AI16                       0x1C
#define   MWV207REG_CE_CONFIG_FORMAT_RI32                                   0x14
#define   MWV207REG_CE_CONFIG_FORMAT_RI32GI32                               0x15
#define   MWV207REG_CE_CONFIG_FORMAT_RF11GF11BF10                           0x1D
#define   MWV207REG_CE_CONFIG_FORMAT_RI10GI10BI10AI2                        0x1E
#define   MWV207REG_CE_CONFIG_FORMAT_R8G8                                   0x1F
#define   MWV207REG_CE_CONFIG_FORMAT_R8                                     0x23
#define   MWV207REG_CE_CONFIG_FORMAT_RF32GF32BF32AF32                       0x25
#define   MWV207REG_CE_CONFIG_FORMAT_RI32GI32BI32AI32                       0x26
#define   MWV207REG_CE_CONFIG_FORMAT_R16                                    0x27
#define   MWV207REG_CE_CONFIG_FORMAT_RUI32GUI32BUI32AUI32                   0x26
#define   MWV207REG_CE_CONFIG_FORMAT_RSI32GSI32BSI32ASI32                   0x27
#define   MWV207REG_CE_CONFIG_FORMAT_A8B8G8R8                               0x2B
#define   MWV207REG_CE_CONFIG_FORMAT_RI32_NEW                               0x2D
#define   MWV207REG_CE_CONFIG_FORMAT_RI32GI32_NEW                           0x2E
#define   MWV207REG_CE_CONFIG_FORMAT_R16G16                                 0x2F
#define   MWV207REG_CE_CONFIG_FORMAT_R16G16B16A16                           0x30


#define MWV207REG_CE_CONFIG_MULTI_SAMPLE                                   31:30
#define MWV207REG_CE_CONFIG_MULTI_SAMPLE_End                                  31
#define MWV207REG_CE_CONFIG_MULTI_SAMPLE_Start                                30
#define MWV207REG_CE_CONFIG_MULTI_SAMPLE_Type                                U02

#define   MWV207REG_CE_CONFIG_MULTI_SAMPLE_OFF                               0x0

#define   MWV207REG_CE_CONFIG_MULTI_SAMPLE_MSAA2                             0x1

#define   MWV207REG_CE_CONFIG_MULTI_SAMPLE_MSAA4                             0x2


#define MWV207REG_CE_CONFIG_WALKER                                         23:22
#define MWV207REG_CE_CONFIG_WALKER_End                                        23
#define MWV207REG_CE_CONFIG_WALKER_Start                                      22
#define MWV207REG_CE_CONFIG_WALKER_Type                                      U02

#define   MWV207REG_CE_CONFIG_WALKER_AUTOMATIC                               0x0

#define   MWV207REG_CE_CONFIG_WALKER_HORIZONTAL                              0x1

#define   MWV207REG_CE_CONFIG_WALKER_VERTICAL                                0x2

#define   MWV207REG_CE_CONFIG_WALKER_HIERARCHICAL                            0x3




#define mwv207regCEAddressRegAddrs                                        0x0C08
#define MWV207REG_CE_ADDRESS_Address                                     0x03020
#define MWV207REG_CE_ADDRESS_MSB                                              15
#define MWV207REG_CE_ADDRESS_LSB                                               3
#define MWV207REG_CE_ADDRESS_BLK                                               3
#define MWV207REG_CE_ADDRESS_Count                                             8
#define MWV207REG_CE_ADDRESS_FieldMask                                0xFFFFFFFF
#define MWV207REG_CE_ADDRESS_ReadMask                                 0xFFFFFFFF
#define MWV207REG_CE_ADDRESS_WriteMask                                0xFFFFFFFF
#define MWV207REG_CE_ADDRESS_ResetValue                               0x00000000


#define MWV207REG_CE_ADDRESS_ADDRESS                                        31:0
#define MWV207REG_CE_ADDRESS_ADDRESS_End                                      31
#define MWV207REG_CE_ADDRESS_ADDRESS_Start                                     0
#define MWV207REG_CE_ADDRESS_ADDRESS_Type                                    U32




#define mwv207regCECountRegAddrs                                          0x0C06
#define MWV207REG_CE_COUNT_Address                                       0x03018
#define MWV207REG_CE_COUNT_MSB                                                15
#define MWV207REG_CE_COUNT_LSB                                                 0
#define MWV207REG_CE_COUNT_BLK                                                 0
#define MWV207REG_CE_COUNT_Count                                               1
#define MWV207REG_CE_COUNT_FieldMask                                  0x0F3F3F0F
#define MWV207REG_CE_COUNT_ReadMask                                   0x0F3F3F0F
#define MWV207REG_CE_COUNT_WriteMask                                  0x0F3F3F0F
#define MWV207REG_CE_COUNT_ResetValue                                 0x00000000

#define MWV207REG_CE_COUNT_ATTRIBUTE_COUNT                                   3:0
#define MWV207REG_CE_COUNT_ATTRIBUTE_COUNT_End                                 3
#define MWV207REG_CE_COUNT_ATTRIBUTE_COUNT_Start                               0
#define MWV207REG_CE_COUNT_ATTRIBUTE_COUNT_Type                              U04


#define MWV207REG_CE_COUNT_OUT_REGISTER                                     13:8
#define MWV207REG_CE_COUNT_OUT_REGISTER_End                                   13
#define MWV207REG_CE_COUNT_OUT_REGISTER_Start                                  8
#define MWV207REG_CE_COUNT_OUT_REGISTER_Type                                 U06


#define MWV207REG_CE_COUNT_TEMP_COUNT                                      21:16
#define MWV207REG_CE_COUNT_TEMP_COUNT_End                                     21
#define MWV207REG_CE_COUNT_TEMP_COUNT_Start                                   16
#define MWV207REG_CE_COUNT_TEMP_COUNT_Type                                   U06


#define MWV207REG_CE_COUNT_INPUT_COUNT                                     27:24
#define MWV207REG_CE_COUNT_INPUT_COUNT_End                                    27
#define MWV207REG_CE_COUNT_INPUT_COUNT_Start                                  24
#define MWV207REG_CE_COUNT_INPUT_COUNT_Type                                  U04



#define mwv207regCEDitherLowRegAddrs                                      0x0C10
#define MWV207REG_CE_DITHER_LOW_Address                                  0x03040
#define MWV207REG_CE_DITHER_LOW_MSB                                           15
#define MWV207REG_CE_DITHER_LOW_LSB                                            0
#define MWV207REG_CE_DITHER_LOW_BLK                                            0
#define MWV207REG_CE_DITHER_LOW_Count                                          1
#define MWV207REG_CE_DITHER_LOW_FieldMask                             0xFFFFFFFF
#define MWV207REG_CE_DITHER_LOW_ReadMask                              0xFFFFFFFF
#define MWV207REG_CE_DITHER_LOW_WriteMask                             0xFFFFFFFF
#define MWV207REG_CE_DITHER_LOW_ResetValue                            0xFFFFFFFF


#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y0                                  3:0
#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y0_End                                3
#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y0_Start                              0
#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y0_Type                             U04


#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y0                                  7:4
#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y0_End                                7
#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y0_Start                              4
#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y0_Type                             U04


#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y0                                 11:8
#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y0_End                               11
#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y0_Start                              8
#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y0_Type                             U04


#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y0                                15:12
#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y0_End                               15
#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y0_Start                             12
#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y0_Type                             U04


#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y1                                19:16
#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y1_End                               19
#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y1_Start                             16
#define MWV207REG_CE_DITHER_LOW_PIXEL_X0_Y1_Type                             U04


#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y1                                23:20
#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y1_End                               23
#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y1_Start                             20
#define MWV207REG_CE_DITHER_LOW_PIXEL_X1_Y1_Type                             U04


#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y1                                27:24
#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y1_End                               27
#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y1_Start                             24
#define MWV207REG_CE_DITHER_LOW_PIXEL_X2_Y1_Type                             U04


#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y1                                31:28
#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y1_End                               31
#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y1_Start                             28
#define MWV207REG_CE_DITHER_LOW_PIXEL_X3_Y1_Type                             U04

#define mwv207regCEDitherHighRegAddrs                                     0x0C11
#define MWV207REG_CE_DITHER_HIGH_Address                                 0x03044
#define MWV207REG_CE_DITHER_HIGH_MSB                                          15
#define MWV207REG_CE_DITHER_HIGH_LSB                                           0
#define MWV207REG_CE_DITHER_LOW_HIGH_BLK                                       0
#define MWV207REG_CE_DITHER_HIGH_Count                                         1
#define MWV207REG_CE_DITHER_HIGH_FieldMask                            0xFFFFFFFF
#define MWV207REG_CE_DITHER_HIGH_ReadMask                             0xFFFFFFFF
#define MWV207REG_CE_DITHER_HIGH_WriteMask                            0xFFFFFFFF
#define MWV207REG_CE_DITHER_HIGH_ResetValue                           0xFFFFFFFF


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y2                                 3:0
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y2_End                               3
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y2_Start                             0
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y2_Type                            U04


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y2                                 7:4
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y2_End                               7
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y2_Start                             4
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y2_Type                            U04


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y2                                11:8
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y2_End                              11
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y2_Start                             8
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y2_Type                            U04


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y2                               15:12
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y2_End                              15
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y2_Start                            12
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y2_Type                            U04


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y3                               19:16
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y3_End                              19
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y3_Start                            16
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X0_Y3_Type                            U04


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y3                               23:20
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y3_End                              23
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y3_Start                            20
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X1_Y3_Type                            U04


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y3                               27:24
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y3_End                              27
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y3_Start                            24
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X2_Y3_Type                            U04


#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y3                               31:28
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y3_End                              31
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y3_Start                            28
#define MWV207REG_CE_DITHER_HIGH_PIXEL_X3_Y3_Type                            U04




#define mwv207regCESwizzleRegAddrs                                        0x0C07
#define MWV207REG_CE_SWIZZLE_Address                                     0x0301C
#define MWV207REG_CE_SWIZZLE_MSB                                              15
#define MWV207REG_CE_SWIZZLE_LSB                                               0
#define MWV207REG_CE_SWIZZLE_BLK                                               0
#define MWV207REG_CE_SWIZZLE_Count                                             1
#define MWV207REG_CE_SWIZZLE_FieldMask                                0x000001FF
#define MWV207REG_CE_SWIZZLE_ReadMask                                 0x000001FF
#define MWV207REG_CE_SWIZZLE_WriteMask                                0x000001FF
#define MWV207REG_CE_SWIZZLE_ResetValue                               0x000000E4


#define MWV207REG_CE_SWIZZLE_SWIZZLE_R                                       1:0
#define MWV207REG_CE_SWIZZLE_SWIZZLE_R_End                                     1
#define MWV207REG_CE_SWIZZLE_SWIZZLE_R_Start                                   0
#define MWV207REG_CE_SWIZZLE_SWIZZLE_R_Type                                  U02
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_R_RED                                 0x0
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_R_GREEN                               0x1
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_R_BLUE                                0x2
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_R_ALPHA                               0x3


#define MWV207REG_CE_SWIZZLE_SWIZZLE_G                                       3:2
#define MWV207REG_CE_SWIZZLE_SWIZZLE_G_End                                     3
#define MWV207REG_CE_SWIZZLE_SWIZZLE_G_Start                                   2
#define MWV207REG_CE_SWIZZLE_SWIZZLE_G_Type                                  U02
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_G_RED                                 0x0
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_G_GREEN                               0x1
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_G_BLUE                                0x2
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_G_ALPHA                               0x3


#define MWV207REG_CE_SWIZZLE_SWIZZLE_B                                       5:4
#define MWV207REG_CE_SWIZZLE_SWIZZLE_B_End                                     5
#define MWV207REG_CE_SWIZZLE_SWIZZLE_B_Start                                   4
#define MWV207REG_CE_SWIZZLE_SWIZZLE_B_Type                                  U02
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_B_RED                                 0x0
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_B_GREEN                               0x1
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_B_BLUE                                0x2
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_B_ALPHA                               0x3


#define MWV207REG_CE_SWIZZLE_SWIZZLE_A                                       7:6
#define MWV207REG_CE_SWIZZLE_SWIZZLE_A_End                                     7
#define MWV207REG_CE_SWIZZLE_SWIZZLE_A_Start                                   6
#define MWV207REG_CE_SWIZZLE_SWIZZLE_A_Type                                  U02
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_A_RED                                 0x0
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_A_GREEN                               0x1
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_A_BLUE                                0x2
#define   MWV207REG_CE_SWIZZLE_SWIZZLE_A_ALPHA                               0x3


#define MWV207REG_CE_SWIZZLE_CACHE_CONFIGURATION                             8:8
#define MWV207REG_CE_SWIZZLE_CACHE_CONFIGURATION_End                           8
#define MWV207REG_CE_SWIZZLE_CACHE_CONFIGURATION_Start                         8
#define MWV207REG_CE_SWIZZLE_CACHE_CONFIGURATION_Type                        U01

#define   MWV207REG_CE_SWIZZLE_CACHE_CONFIGURATION__16X64                    0x0

#define   MWV207REG_CE_SWIZZLE_CACHE_CONFIGURATION__8X256                    0x1




#define mwv207regCEConstRegAddrs                                          0x0C12
#define MWV207REG_CE_CONST_Address                                       0x03048
#define MWV207REG_CE_CONST_MSB                                                15
#define MWV207REG_CE_CONST_LSB                                                 0
#define MWV207REG_CE_CONST_BLK                                                 0
#define MWV207REG_CE_CONST_Count                                               1
#define MWV207REG_CE_CONST_FieldMask                                  0x000003FF
#define MWV207REG_CE_CONST_ReadMask                                   0x000003FF
#define MWV207REG_CE_CONST_WriteMask                                  0x000003FF
#define MWV207REG_CE_CONST_ResetValue                                 0x00000000


#define MWV207REG_CE_CONST_BASE_OFFSET                                       9:0
#define MWV207REG_CE_CONST_BASE_OFFSET_End                                     9
#define MWV207REG_CE_CONST_BASE_OFFSET_Start                                   0
#define MWV207REG_CE_CONST_BASE_OFFSET_Type                                  U10



#define mwv207regCEInstructionRegAddrs                                    0x0C13
#define MWV207REG_CE_INSTRUCTION_Address                                 0x0304C
#define MWV207REG_CE_INSTRUCTION_MSB                                          15
#define MWV207REG_CE_INSTRUCTION_LSB                                           0
#define MWV207REG_CE_INSTRUCTION_BLK                                           0
#define MWV207REG_CE_INSTRUCTION_Count                                         1
#define MWV207REG_CE_INSTRUCTION_FieldMask                            0xFFFFFFFF
#define MWV207REG_CE_INSTRUCTION_ReadMask                             0xFFFFFF00
#define MWV207REG_CE_INSTRUCTION_WriteMask                            0xFFFFFF00
#define MWV207REG_CE_INSTRUCTION_ResetValue                           0x00000000


#define MWV207REG_CE_INSTRUCTION_ADDRESS                                    31:0
#define MWV207REG_CE_INSTRUCTION_ADDRESS_End                                  31
#define MWV207REG_CE_INSTRUCTION_ADDRESS_Start                                 0
#define MWV207REG_CE_INSTRUCTION_ADDRESS_Type                                U32





#define mwv207regCEAttributeXRegAddrs                                     0x0C18
#define MWV207REG_CE_ATTRIBUTE_X_Address                                 0x03060
#define MWV207REG_CE_ATTRIBUTE_X_MSB                                          15
#define MWV207REG_CE_ATTRIBUTE_X_LSB                                           3
#define MWV207REG_CE_ATTRIBUTE_X_BLK                                           0
#define MWV207REG_CE_ATTRIBUTE_X_Count                                         8
#define MWV207REG_CE_ATTRIBUTE_X_FieldMask                            0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_X_ReadMask                             0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_X_WriteMask                            0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_X_ResetValue                           0x00000000


#define MWV207REG_CE_ATTRIBUTE_X_X                                          31:0
#define MWV207REG_CE_ATTRIBUTE_X_X_End                                        31
#define MWV207REG_CE_ATTRIBUTE_X_X_Start                                       0
#define MWV207REG_CE_ATTRIBUTE_X_X_Type                                      U32



#define mwv207regCEAttributeXdxRegAddrs                                   0x0C20
#define MWV207REG_CE_ATTRIBUTE_XDX_Address                               0x03080
#define MWV207REG_CE_ATTRIBUTE_XDX_MSB                                        15
#define MWV207REG_CE_ATTRIBUTE_XDX_LSB                                         3
#define MWV207REG_CE_ATTRIBUTE_XDX_BLK                                         0
#define MWV207REG_CE_ATTRIBUTE_XDX_Count                                       8
#define MWV207REG_CE_ATTRIBUTE_XDX_FieldMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_XDX_ReadMask                           0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_XDX_WriteMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_XDX_ResetValue                         0x00000000


#define MWV207REG_CE_ATTRIBUTE_XDX_DX                                       31:0
#define MWV207REG_CE_ATTRIBUTE_XDX_DX_End                                     31
#define MWV207REG_CE_ATTRIBUTE_XDX_DX_Start                                    0
#define MWV207REG_CE_ATTRIBUTE_XDX_DX_Type                                   U32



#define mwv207regCEAttributeXdyRegAddrs                                   0x0C28
#define MWV207REG_CE_ATTRIBUTE_XDY_Address                               0x030A0
#define MWV207REG_CE_ATTRIBUTE_XDY_MSB                                        15
#define MWV207REG_CE_ATTRIBUTE_XDY_LSB                                         3
#define MWV207REG_CE_ATTRIBUTE_XDY_BLK                                         0
#define MWV207REG_CE_ATTRIBUTE_XDY_Count                                       8
#define MWV207REG_CE_ATTRIBUTE_XDY_FieldMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_XDY_ReadMask                           0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_XDY_WriteMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_XDY_ResetValue                         0x00000000


#define MWV207REG_CE_ATTRIBUTE_XDY_DY                                       31:0
#define MWV207REG_CE_ATTRIBUTE_XDY_DY_End                                     31
#define MWV207REG_CE_ATTRIBUTE_XDY_DY_Start                                    0
#define MWV207REG_CE_ATTRIBUTE_XDY_DY_Type                                   U32




#define mwv207regCEAttributeYRegAddrs                                     0x0C30
#define MWV207REG_CE_ATTRIBUTE_Y_Address                                 0x030C0
#define MWV207REG_CE_ATTRIBUTE_Y_MSB                                          15
#define MWV207REG_CE_ATTRIBUTE_Y_LSB                                           3
#define MWV207REG_CE_ATTRIBUTE_Y_BLK                                           0
#define MWV207REG_CE_ATTRIBUTE_Y_Count                                         8
#define MWV207REG_CE_ATTRIBUTE_Y_FieldMask                            0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_Y_ReadMask                             0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_Y_WriteMask                            0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_Y_ResetValue                           0x00000000


#define MWV207REG_CE_ATTRIBUTE_Y_Y                                          31:0
#define MWV207REG_CE_ATTRIBUTE_Y_Y_End                                        31
#define MWV207REG_CE_ATTRIBUTE_Y_Y_Start                                       0
#define MWV207REG_CE_ATTRIBUTE_Y_Y_Type                                      U32



#define mwv207regCEAttributeYdxRegAddrs                                   0x0C38
#define MWV207REG_CE_ATTRIBUTE_YDX_Address                               0x030E0
#define MWV207REG_CE_ATTRIBUTE_YDX_MSB                                        15
#define MWV207REG_CE_ATTRIBUTE_YDX_LSB                                         3
#define MWV207REG_CE_ATTRIBUTE_YDX_BLK                                         0
#define MWV207REG_CE_ATTRIBUTE_YDX_Count                                       8
#define MWV207REG_CE_ATTRIBUTE_YDX_FieldMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_YDX_ReadMask                           0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_YDX_WriteMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_YDX_ResetValue                         0x00000000


#define MWV207REG_CE_ATTRIBUTE_YDX_DX                                       31:0
#define MWV207REG_CE_ATTRIBUTE_YDX_DX_End                                     31
#define MWV207REG_CE_ATTRIBUTE_YDX_DX_Start                                    0
#define MWV207REG_CE_ATTRIBUTE_YDX_DX_Type                                   U32



#define mwv207regCEAttributeYdyRegAddrs                                   0x0C40
#define MWV207REG_CE_ATTRIBUTE_YDY_Address                               0x03100
#define MWV207REG_CE_ATTRIBUTE_YDY_MSB                                        15
#define MWV207REG_CE_ATTRIBUTE_YDY_LSB                                         3
#define MWV207REG_CE_ATTRIBUTE_YDY_BLK                                         0
#define MWV207REG_CE_ATTRIBUTE_YDY_Count                                       8
#define MWV207REG_CE_ATTRIBUTE_YDY_FieldMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_YDY_ReadMask                           0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_YDY_WriteMask                          0xFFFFFFFF
#define MWV207REG_CE_ATTRIBUTE_YDY_ResetValue                         0x00000000


#define MWV207REG_CE_ATTRIBUTE_YDY_DY                                       31:0
#define MWV207REG_CE_ATTRIBUTE_YDY_DY_End                                     31
#define MWV207REG_CE_ATTRIBUTE_YDY_DY_Start                                    0
#define MWV207REG_CE_ATTRIBUTE_YDY_DY_Type                                   U32




#define mwv207regCESamplerConfigRegAddrs                                  0x0C48
#define MWV207REG_CE_SAMPLER_CONFIG_Address                              0x03120
#define MWV207REG_CE_SAMPLER_CONFIG_MSB                                       15
#define MWV207REG_CE_SAMPLER_CONFIG_LSB                                        3
#define MWV207REG_CE_SAMPLER_CONFIG_BLK                                        0
#define MWV207REG_CE_SAMPLER_CONFIG_Count                                      8
#define MWV207REG_CE_SAMPLER_CONFIG_FieldMask                         0xFFFFFFFF
#define MWV207REG_CE_SAMPLER_CONFIG_ReadMask                          0xFFFFFFFF
#define MWV207REG_CE_SAMPLER_CONFIG_WriteMask                         0xFFFFFFFF
#define MWV207REG_CE_SAMPLER_CONFIG_ResetValue                        0x00000000


#define MWV207REG_CE_SAMPLER_CONFIG_FORMAT                                   4:0
#define MWV207REG_CE_SAMPLER_CONFIG_FORMAT_End                                 4
#define MWV207REG_CE_SAMPLER_CONFIG_FORMAT_Start                               0
#define MWV207REG_CE_SAMPLER_CONFIG_FORMAT_Type                              U05
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_A8                             0x01
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_L8                             0x02
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_I8                             0x03
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_A8L8                           0x04
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_ARGB4                          0x05
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_XRGB4                          0x06
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_ARGB8                          0x07
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_XRGB8                          0x08
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_ABGR8                          0x09
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_XBGR8                          0x0A
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_R5G6B5                         0x0B
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_A1RGB5                         0x0C
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_X1RGB5                         0x0D
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_YUY2                           0x0E
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_UYVY                           0x0F
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_D16                            0x10
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_D24X8                          0x11
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_A8_OES                         0x12
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_DXT1                           0x13
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_DXT2                           0x14
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_DXT3                           0x14
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_DXT4                           0x15
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_DXT5                           0x15
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_HDR7E3                         0x16
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_HDR6E4                         0x17
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_HDR5E5                         0x18
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_HDR6E5                         0x19
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_RGBE8                          0x1A
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_RGBE8F                         0x1B
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_RGB9E5                         0x1C
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_RGB9E5F                        0x1D
#define   MWV207REG_CE_SAMPLER_CONFIG_FORMAT_ETC1                           0x1E


#define MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT                                7:5
#define MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_End                              7
#define MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_Start                            5
#define MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_Type                           U03

#define   MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_FOUR                         0x0

#define   MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_SIXTEEN                      0x1

#define   MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_SUPER_TILED                  0x2

#define   MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_SPLIT_TILED                  0x3

#define   MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_SPLIT_SUPER_TILED            0x4

#define   MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_SPLIT_TILED_BIG              0x5

#define   MWV207REG_CE_SAMPLER_CONFIG_ALIGNMENT_SPLIT_SUPER_TILED_BUG        0x6

#define MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT                         12:8
#define MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_End                       12
#define MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_Start                      8
#define MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_Type                     U05
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_ETC2_RGB8             0x00
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_ETC2_RGB8A1           0x01
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_ETC2_RGB8A8           0x02
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_EAC__R11_UNSIGNED     0x03
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_EAC__RG11_UNSIGNED    0x04
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_EAC__RG11_SIGNED      0x05
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_R8G8                  0x06
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RF16                  0x07
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RF16GF16              0x08
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RF16GF16BGF16AF16     0x09
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RF32                  0x0A
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RF32GF32              0x0B
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_R10G10B10A2           0x0C
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_EAC__R11_SIGNED       0x0D
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_R8__SNORM             0x0E
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RG8__SNORM            0x0F
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RGBX8__SNORM          0x10
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RGBA8__SNORM          0x11
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_RGB8                  0x12
#define   MWV207REG_CE_SAMPLER_CONFIG_EXTENDED_FORMAT_YUV_ASSEMBLY          0x13


#define MWV207REG_CE_SAMPLER_CONFIG_FILTER                                 13:13
#define MWV207REG_CE_SAMPLER_CONFIG_FILTER_End                                13
#define MWV207REG_CE_SAMPLER_CONFIG_FILTER_Start                              13
#define MWV207REG_CE_SAMPLER_CONFIG_FILTER_Type                              U01

#define   MWV207REG_CE_SAMPLER_CONFIG_FILTER_POINT                           0x0

#define   MWV207REG_CE_SAMPLER_CONFIG_FILTER_LINEAR                          0x1


#define MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING                             15:14
#define MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING_End                            15
#define MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING_Start                          14
#define MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING_Type                          U02

#define   MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING_NO_STRIDE                   0x0

#define   MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING_NO_STRIDE_LINEAR            0x1

#define   MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING_TILED                       0x2

#define   MWV207REG_CE_SAMPLER_CONFIG_ADDRESSING_LINEAR                      0x3


#define MWV207REG_CE_SAMPLER_CONFIG_STRIDE                                 31:16
#define MWV207REG_CE_SAMPLER_CONFIG_STRIDE_End                                31
#define MWV207REG_CE_SAMPLER_CONFIG_STRIDE_Start                              16
#define MWV207REG_CE_SAMPLER_CONFIG_STRIDE_Type                              U16




#define mwv207regCESamplerSizeRegAddrs                                    0x0C50
#define MWV207REG_CE_SAMPLER_SIZE_Address                                0x03140
#define MWV207REG_CE_SAMPLER_SIZE_MSB                                         15
#define MWV207REG_CE_SAMPLER_SIZE_LSB                                          3
#define MWV207REG_CE_SAMPLER_SIZE_BLK                                          0
#define MWV207REG_CE_SAMPLER_SIZE_Count                                        8
#define MWV207REG_CE_SAMPLER_SIZE_FieldMask                           0xBFFFBFFF
#define MWV207REG_CE_SAMPLER_SIZE_ReadMask                            0xBFFFBFFF
#define MWV207REG_CE_SAMPLER_SIZE_WriteMask                           0xBFFFBFFF
#define MWV207REG_CE_SAMPLER_SIZE_ResetValue                          0x00000000


#define MWV207REG_CE_SAMPLER_SIZE_WIDTH                                     13:0
#define MWV207REG_CE_SAMPLER_SIZE_WIDTH_End                                   13
#define MWV207REG_CE_SAMPLER_SIZE_WIDTH_Start                                  0
#define MWV207REG_CE_SAMPLER_SIZE_WIDTH_Type                                 U14


#define MWV207REG_CE_SAMPLER_SIZE_YUV_STANDARD                             15:15
#define MWV207REG_CE_SAMPLER_SIZE_YUV_STANDARD_End                            15
#define MWV207REG_CE_SAMPLER_SIZE_YUV_STANDARD_Start                          15
#define MWV207REG_CE_SAMPLER_SIZE_YUV_STANDARD_Type                          U01

#define   MWV207REG_CE_SAMPLER_SIZE_YUV_STANDARD_YUV601                      0x0

#define   MWV207REG_CE_SAMPLER_SIZE_YUV_STANDARD_YUV709                      0x1


#define MWV207REG_CE_SAMPLER_SIZE_HEIGHT                                   29:16
#define MWV207REG_CE_SAMPLER_SIZE_HEIGHT_End                                  29
#define MWV207REG_CE_SAMPLER_SIZE_HEIGHT_Start                                16
#define MWV207REG_CE_SAMPLER_SIZE_HEIGHT_Type                                U14


#define MWV207REG_CE_SAMPLER_SIZE_EXPANSION_CONTROL                        31:31
#define MWV207REG_CE_SAMPLER_SIZE_EXPANSION_CONTROL_End                       31
#define MWV207REG_CE_SAMPLER_SIZE_EXPANSION_CONTROL_Start                     31
#define MWV207REG_CE_SAMPLER_SIZE_EXPANSION_CONTROL_Type                     U01

#define   MWV207REG_CE_SAMPLER_SIZE_EXPANSION_CONTROL_REPLICATE              0x0

#define   MWV207REG_CE_SAMPLER_SIZE_EXPANSION_CONTROL_ZERO                   0x1




#define mwv207regCESamplerAddressRegAddrs                                 0x0C80
#define MWV207REG_CE_SAMPLER_ADDRESS_Address                             0x03200
#define MWV207REG_CE_SAMPLER_ADDRESS_MSB                                      15
#define MWV207REG_CE_SAMPLER_ADDRESS_LSB                                       6
#define MWV207REG_CE_SAMPLER_ADDRESS_BLK                                       3
#define MWV207REG_CE_SAMPLER_ADDRESS_Count                                    64
#define MWV207REG_CE_SAMPLER_ADDRESS_FieldMask                        0xFFFFFFFF
#define MWV207REG_CE_SAMPLER_ADDRESS_ReadMask                         0xFFFFFFFF
#define MWV207REG_CE_SAMPLER_ADDRESS_WriteMask                        0xFFFFFFFF
#define MWV207REG_CE_SAMPLER_ADDRESS_ResetValue                       0x00000000

#define MWV207REG_CE_SAMPLER_ADDRESS_ADDRESS                                31:0
#define MWV207REG_CE_SAMPLER_ADDRESS_ADDRESS_End                              31
#define MWV207REG_CE_SAMPLER_ADDRESS_ADDRESS_Start                             0
#define MWV207REG_CE_SAMPLER_ADDRESS_ADDRESS_Type                            U32




#define mwv207regCEBorderXRegAddrs                                        0x0C58
#define MWV207REG_CE_BORDER_X_Address                                    0x03160
#define MWV207REG_CE_BORDER_X_MSB                                             15
#define MWV207REG_CE_BORDER_X_LSB                                              3
#define MWV207REG_CE_BORDER_X_BLK                                              0
#define MWV207REG_CE_BORDER_X_Count                                            8
#define MWV207REG_CE_BORDER_X_FieldMask                               0xBFFF3FFF
#define MWV207REG_CE_BORDER_X_ReadMask                                0xBFFF3FFF
#define MWV207REG_CE_BORDER_X_WriteMask                               0xBFFF3FFF
#define MWV207REG_CE_BORDER_X_ResetValue                              0x00000000


#define MWV207REG_CE_BORDER_X_MIN_X                                         13:0
#define MWV207REG_CE_BORDER_X_MIN_X_End                                       13
#define MWV207REG_CE_BORDER_X_MIN_X_Start                                      0
#define MWV207REG_CE_BORDER_X_MIN_X_Type                                     U14


#define MWV207REG_CE_BORDER_X_MAX_X                                        29:16
#define MWV207REG_CE_BORDER_X_MAX_X_End                                       29
#define MWV207REG_CE_BORDER_X_MAX_X_Start                                     16
#define MWV207REG_CE_BORDER_X_MAX_X_Type                                     U14

#define MWV207REG_CE_BORDER_X_TILE_STATUS                                  31:31
#define MWV207REG_CE_BORDER_X_TILE_STATUS_End                                 31
#define MWV207REG_CE_BORDER_X_TILE_STATUS_Start                               31
#define MWV207REG_CE_BORDER_X_TILE_STATUS_Type                               U01

#define   MWV207REG_CE_BORDER_X_TILE_STATUS_NO                               0x0

#define   MWV207REG_CE_BORDER_X_TILE_STATUS_YES                              0x1




#define mwv207regCEBorderYRegAddrs                                        0x0C60
#define MWV207REG_CE_BORDER_Y_Address                                    0x03180
#define MWV207REG_CE_BORDER_Y_MSB                                             15
#define MWV207REG_CE_BORDER_Y_LSB                                              3
#define MWV207REG_CE_BORDER_Y_BLK                                              0
#define MWV207REG_CE_BORDER_Y_Count                                            8
#define MWV207REG_CE_BORDER_Y_FieldMask                               0x3FFF3FFF
#define MWV207REG_CE_BORDER_Y_ReadMask                                0x3FFF3FFF
#define MWV207REG_CE_BORDER_Y_WriteMask                               0x3FFF3FFF
#define MWV207REG_CE_BORDER_Y_ResetValue                              0x00000000


#define MWV207REG_CE_BORDER_Y_MIN_Y                                         13:0
#define MWV207REG_CE_BORDER_Y_MIN_Y_End                                       13
#define MWV207REG_CE_BORDER_Y_MIN_Y_Start                                      0
#define MWV207REG_CE_BORDER_Y_MIN_Y_Type                                     U14


#define MWV207REG_CE_BORDER_Y_MAX_Y                                        29:16
#define MWV207REG_CE_BORDER_Y_MAX_Y_End                                       29
#define MWV207REG_CE_BORDER_Y_MAX_Y_Start                                     16
#define MWV207REG_CE_BORDER_Y_MAX_Y_Type                                     U14




#define mwv207regCETileStatusControlRegAddrs                              0x0C68
#define MWV207REG_CE_TILE_STATUS_CONTROL_Address                         0x031A0
#define MWV207REG_CE_TILE_STATUS_CONTROL_MSB                                  15
#define MWV207REG_CE_TILE_STATUS_CONTROL_LSB                                   3
#define MWV207REG_CE_TILE_STATUS_CONTROL_BLK                                   0
#define MWV207REG_CE_TILE_STATUS_CONTROL_Count                                 8
#define MWV207REG_CE_TILE_STATUS_CONTROL_FieldMask                    0x000000F3
#define MWV207REG_CE_TILE_STATUS_CONTROL_ReadMask                     0x000000F3
#define MWV207REG_CE_TILE_STATUS_CONTROL_WriteMask                    0x000000F3
#define MWV207REG_CE_TILE_STATUS_CONTROL_ResetValue                   0x00000000


#define MWV207REG_CE_TILE_STATUS_CONTROL_CONTROL                             1:0
#define MWV207REG_CE_TILE_STATUS_CONTROL_CONTROL_End                           1
#define MWV207REG_CE_TILE_STATUS_CONTROL_CONTROL_Start                         0
#define MWV207REG_CE_TILE_STATUS_CONTROL_CONTROL_Type                        U02

#define   MWV207REG_CE_TILE_STATUS_CONTROL_CONTROL_DISABLE                   0x0

#define   MWV207REG_CE_TILE_STATUS_CONTROL_CONTROL_ENABLE                    0x1

#define   MWV207REG_CE_TILE_STATUS_CONTROL_CONTROL_COMPRESSED                0x3


#define MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT                              7:4
#define MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_End                            7
#define MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_Start                          4
#define MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_Type                         U04
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_ARGB4                      0x0
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_A1RGB5                     0x1
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_R5G6B5                     0x2
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_ARGB8                      0x3
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_RGB8                       0x4
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_Z24S8                      0x5
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_Z24                        0x6
#define   MWV207REG_CE_TILE_STATUS_CONTROL_FORMAT_VAA16                      0x7




#define mwv207regCETileStatusBufferRegAddrs                               0x0C70
#define MWV207REG_CE_TILE_STATUS_BUFFER_Address                          0x031C0
#define MWV207REG_CE_TILE_STATUS_BUFFER_MSB                                   15
#define MWV207REG_CE_TILE_STATUS_BUFFER_LSB                                    3
#define MWV207REG_CE_TILE_STATUS_BUFFER_BLK                                    0
#define MWV207REG_CE_TILE_STATUS_BUFFER_Count                                  8
#define MWV207REG_CE_TILE_STATUS_BUFFER_FieldMask                     0xFFFFFFFF
#define MWV207REG_CE_TILE_STATUS_BUFFER_ReadMask                      0xFFFFFFFF
#define MWV207REG_CE_TILE_STATUS_BUFFER_WriteMask                     0xFFFFFFFF
#define MWV207REG_CE_TILE_STATUS_BUFFER_ResetValue                    0x00000000

#define MWV207REG_CE_TILE_STATUS_BUFFER_ADDRESS                             31:0
#define MWV207REG_CE_TILE_STATUS_BUFFER_ADDRESS_End                           31
#define MWV207REG_CE_TILE_STATUS_BUFFER_ADDRESS_Start                          0
#define MWV207REG_CE_TILE_STATUS_BUFFER_ADDRESS_Type                         U32




#define mwv207regCETileStatusClearRegAddrs                                0x0C78
#define MWV207REG_CE_TILE_STATUS_CLEAR_Address                           0x031E0
#define MWV207REG_CE_TILE_STATUS_CLEAR_MSB                                    15
#define MWV207REG_CE_TILE_STATUS_CLEAR_LSB                                     3
#define MWV207REG_CE_TILE_STATUS_CLEAR_BLK                                     0
#define MWV207REG_CE_TILE_STATUS_CLEAR_Count                                   8
#define MWV207REG_CE_TILE_STATUS_CLEAR_FieldMask                      0xFFFFFFFF
#define MWV207REG_CE_TILE_STATUS_CLEAR_ReadMask                       0xFFFFFFFF
#define MWV207REG_CE_TILE_STATUS_CLEAR_WriteMask                      0xFFFFFFFF
#define MWV207REG_CE_TILE_STATUS_CLEAR_ResetValue                     0x00000000

#define MWV207REG_CE_TILE_STATUS_CLEAR_VALUE                                31:0
#define MWV207REG_CE_TILE_STATUS_CLEAR_VALUE_End                              31
#define MWV207REG_CE_TILE_STATUS_CLEAR_VALUE_Start                             0
#define MWV207REG_CE_TILE_STATUS_CLEAR_VALUE_Type                            U32


#endif


