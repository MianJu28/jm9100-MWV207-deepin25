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




#ifndef __jmgpuregStreamOut_h__
#define __jmgpuregStreamOut_h__





#define mwv207regSOControlRegAddrs                                        0x5100
#define MWV207REG_SO_CONTROL_Address                                     0x14400
#define MWV207REG_SO_CONTROL_MSB                                              15
#define MWV207REG_SO_CONTROL_LSB                                               0
#define MWV207REG_SO_CONTROL_BLK                                               0
#define MWV207REG_SO_CONTROL_Count                                             1
#define MWV207REG_SO_CONTROL_FieldMask                                0x007F3F17
#define MWV207REG_SO_CONTROL_ReadMask                                 0x007F3F17
#define MWV207REG_SO_CONTROL_WriteMask                                0x007F3F17
#define MWV207REG_SO_CONTROL_ResetValue                               0x00000000


#define MWV207REG_SO_CONTROL_MODE                                            2:0
#define MWV207REG_SO_CONTROL_MODE_End                                          2
#define MWV207REG_SO_CONTROL_MODE_Start                                        0
#define MWV207REG_SO_CONTROL_MODE_Type                                       U03

#define   MWV207REG_SO_CONTROL_MODE_DISABLED                                 0x0

#define   MWV207REG_SO_CONTROL_MODE_INDEX_STREAM_OUT                         0x1

#define   MWV207REG_SO_CONTROL_MODE_MULTI_GPU_STREAM_OUT                     0x2

#define   MWV207REG_SO_CONTROL_MODE_BIN_OUT                                  0x3

#define   MWV207REG_SO_CONTROL_MODE_TRANSFORM_FEEDBACK                       0x4


#define MWV207REG_SO_CONTROL_WRITE_THROUGH                                   4:4
#define MWV207REG_SO_CONTROL_WRITE_THROUGH_End                                 4
#define MWV207REG_SO_CONTROL_WRITE_THROUGH_Start                               4
#define MWV207REG_SO_CONTROL_WRITE_THROUGH_Type                              U01

#define   MWV207REG_SO_CONTROL_WRITE_THROUGH_DISABLED                        0x0
#define   MWV207REG_SO_CONTROL_WRITE_THROUGH_ENABLED                         0x1

#define MWV207REG_SO_CONTROL_COUNT                                          11:8
#define MWV207REG_SO_CONTROL_COUNT_End                                        11
#define MWV207REG_SO_CONTROL_COUNT_Start                                       8
#define MWV207REG_SO_CONTROL_COUNT_Type                                      U04


#define MWV207REG_SO_CONTROL_FORMAT                                        13:12
#define MWV207REG_SO_CONTROL_FORMAT_End                                       13
#define MWV207REG_SO_CONTROL_FORMAT_Start                                     12
#define MWV207REG_SO_CONTROL_FORMAT_Type                                     U02

#define   MWV207REG_SO_CONTROL_FORMAT_INDEX8                                 0x0

#define   MWV207REG_SO_CONTROL_FORMAT_INDEX16                                0x1

#define   MWV207REG_SO_CONTROL_FORMAT_INDEX32                                0x2


#define MWV207REG_SO_CONTROL_MULTI_GPU_MODE                                18:16
#define MWV207REG_SO_CONTROL_MULTI_GPU_MODE_End                               18
#define MWV207REG_SO_CONTROL_MULTI_GPU_MODE_Start                             16
#define MWV207REG_SO_CONTROL_MULTI_GPU_MODE_Type                             U03

#define   MWV207REG_SO_CONTROL_MULTI_GPU_MODE_WINDOWED                       0x0

#define   MWV207REG_SO_CONTROL_MULTI_GPU_MODE_INTERLEAVED64X64               0x1

#define   MWV207REG_SO_CONTROL_MULTI_GPU_MODE_INTERLEAVED128X64              0x2

#define   MWV207REG_SO_CONTROL_MULTI_GPU_MODE_INTERLEAVED128X128             0x3

#define   MWV207REG_SO_CONTROL_MULTI_GPU_MODE_INTERLEAVED16X16               0x4

#define   MWV207REG_SO_CONTROL_MULTI_GPU_MODE_INTERLEAVED32X32               0x5


#define MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL                           20:19
#define MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL_End                          20
#define MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL_Start                        19
#define MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL_Type                        U02
#define   MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL_NO_SWAP                   0x0
#define   MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL_SWAP_WORD                 0x1
#define   MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL_SWAP_DWORD                0x2
#define   MWV207REG_SO_CONTROL_BODY_ENDIAN_CONTROL_SWAP_DDWORD               0x3


#define MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL                         22:21
#define MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL_End                        22
#define MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL_Start                      21
#define MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL_Type                      U02
#define   MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL_NO_SWAP                 0x0
#define   MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL_SWAP_WORD               0x1
#define   MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL_SWAP_DWORD              0x2
#define   MWV207REG_SO_CONTROL_HEADER_ENDIAN_CONTROL_SWAP_DDWORD             0x3




#define mwv207regSOCollectRegAddrs                                        0x5101
#define MWV207REG_SO_COLLECT_Address                                     0x14404
#define MWV207REG_SO_COLLECT_MSB                                              15
#define MWV207REG_SO_COLLECT_LSB                                               0
#define MWV207REG_SO_COLLECT_BLK                                               0
#define MWV207REG_SO_COLLECT_Count                                             1
#define MWV207REG_SO_COLLECT_FieldMask                                0x000001F7
#define MWV207REG_SO_COLLECT_ReadMask                                 0x000001F7
#define MWV207REG_SO_COLLECT_WriteMask                                0x000001F7
#define MWV207REG_SO_COLLECT_ResetValue                               0x00000000


#define MWV207REG_SO_COLLECT_COLLECT_MODE                                    2:0
#define MWV207REG_SO_COLLECT_COLLECT_MODE_End                                  2
#define MWV207REG_SO_COLLECT_COLLECT_MODE_Start                                0
#define MWV207REG_SO_COLLECT_COLLECT_MODE_Type                               U03

#define   MWV207REG_SO_COLLECT_COLLECT_MODE_INITIALIZE                       0x0

#define   MWV207REG_SO_COLLECT_COLLECT_MODE_PAUSE                            0x1

#define   MWV207REG_SO_COLLECT_COLLECT_MODE_RESUME                           0x2

#define   MWV207REG_SO_COLLECT_COLLECT_MODE_STOP                             0x3
#define   MWV207REG_SO_COLLECT_COLLECT_MODE_STOP_SIGNAL                      0x4


#define MWV207REG_SO_COLLECT_SIGNAL                                          8:4
#define MWV207REG_SO_COLLECT_SIGNAL_End                                        8
#define MWV207REG_SO_COLLECT_SIGNAL_Start                                      4
#define MWV207REG_SO_COLLECT_SIGNAL_Type                                     U05




#define mwv207regSOAddressRegAddrs                                        0x5110
#define MWV207REG_SO_ADDRESS_Address                                     0x14440
#define MWV207REG_SO_ADDRESS_MSB                                              15
#define MWV207REG_SO_ADDRESS_LSB                                               4
#define MWV207REG_SO_ADDRESS_BLK                                               4
#define MWV207REG_SO_ADDRESS_Count                                            16
#define MWV207REG_SO_ADDRESS_FieldMask                                0xFFFFFFFF
#define MWV207REG_SO_ADDRESS_ReadMask                                 0xFFFFFFC0
#define MWV207REG_SO_ADDRESS_WriteMask                                0xFFFFFFC0
#define MWV207REG_SO_ADDRESS_ResetValue                               0x00000000


#define MWV207REG_SO_ADDRESS_ADDRESS                                        31:0
#define MWV207REG_SO_ADDRESS_ADDRESS_End                                      31
#define MWV207REG_SO_ADDRESS_ADDRESS_Start                                     0
#define MWV207REG_SO_ADDRESS_ADDRESS_Type                                    U32




#define mwv207regSOBinOriginRegAddrs                                      0x5102
#define MWV207REG_SO_BIN_ORIGIN_Address                                  0x14408
#define MWV207REG_SO_BIN_ORIGIN_MSB                                           15
#define MWV207REG_SO_BIN_ORIGIN_LSB                                            0
#define MWV207REG_SO_BIN_ORIGIN_BLK                                            0
#define MWV207REG_SO_BIN_ORIGIN_Count                                          1
#define MWV207REG_SO_BIN_ORIGIN_FieldMask                             0x1FFF1FFF
#define MWV207REG_SO_BIN_ORIGIN_ReadMask                              0x1FFF1FFF
#define MWV207REG_SO_BIN_ORIGIN_WriteMask                             0x1FFF1FFF
#define MWV207REG_SO_BIN_ORIGIN_ResetValue                            0x00000000


#define MWV207REG_SO_BIN_ORIGIN_X                                           12:0
#define MWV207REG_SO_BIN_ORIGIN_X_End                                         12
#define MWV207REG_SO_BIN_ORIGIN_X_Start                                        0
#define MWV207REG_SO_BIN_ORIGIN_X_Type                                       U13


#define MWV207REG_SO_BIN_ORIGIN_Y                                          28:16
#define MWV207REG_SO_BIN_ORIGIN_Y_End                                         28
#define MWV207REG_SO_BIN_ORIGIN_Y_Start                                       16
#define MWV207REG_SO_BIN_ORIGIN_Y_Type                                       U13




#define mwv207regSOBinSizeRegAddrs                                        0x5103
#define MWV207REG_SO_BIN_SIZE_Address                                    0x1440C
#define MWV207REG_SO_BIN_SIZE_MSB                                             15
#define MWV207REG_SO_BIN_SIZE_LSB                                              0
#define MWV207REG_SO_BIN_SIZE_BLK                                              0
#define MWV207REG_SO_BIN_SIZE_Count                                            1
#define MWV207REG_SO_BIN_SIZE_FieldMask                               0x1F1F0F0F
#define MWV207REG_SO_BIN_SIZE_ReadMask                                0x1F1F0F0F
#define MWV207REG_SO_BIN_SIZE_WriteMask                               0x1F1F0F0F
#define MWV207REG_SO_BIN_SIZE_ResetValue                              0x00000000

#define MWV207REG_SO_BIN_SIZE_WIDTH                                          3:0
#define MWV207REG_SO_BIN_SIZE_WIDTH_End                                        3
#define MWV207REG_SO_BIN_SIZE_WIDTH_Start                                      0
#define MWV207REG_SO_BIN_SIZE_WIDTH_Type                                     U04

#define MWV207REG_SO_BIN_SIZE_HEIGHT                                        11:8
#define MWV207REG_SO_BIN_SIZE_HEIGHT_End                                      11
#define MWV207REG_SO_BIN_SIZE_HEIGHT_Start                                     8
#define MWV207REG_SO_BIN_SIZE_HEIGHT_Type                                    U04


#define MWV207REG_SO_BIN_SIZE_COUNT_X                                      20:16
#define MWV207REG_SO_BIN_SIZE_COUNT_X_End                                     20
#define MWV207REG_SO_BIN_SIZE_COUNT_X_Start                                   16
#define MWV207REG_SO_BIN_SIZE_COUNT_X_Type                                   U05


#define MWV207REG_SO_BIN_SIZE_COUNT_Y                                      28:24
#define MWV207REG_SO_BIN_SIZE_COUNT_Y_End                                     28
#define MWV207REG_SO_BIN_SIZE_COUNT_Y_Start                                   24
#define MWV207REG_SO_BIN_SIZE_COUNT_Y_Type                                   U05



#define mwv207regSOWindowOriginRegAddrs                                   0x5120
#define MWV207REG_SO_WINDOW_ORIGIN_Address                               0x14480
#define MWV207REG_SO_WINDOW_ORIGIN_MSB                                        15
#define MWV207REG_SO_WINDOW_ORIGIN_LSB                                         4
#define MWV207REG_SO_WINDOW_ORIGIN_BLK                                         4
#define MWV207REG_SO_WINDOW_ORIGIN_Count                                      16
#define MWV207REG_SO_WINDOW_ORIGIN_FieldMask                          0x1FFF1FFF
#define MWV207REG_SO_WINDOW_ORIGIN_ReadMask                           0x1FFF1FFF
#define MWV207REG_SO_WINDOW_ORIGIN_WriteMask                          0x1FFF1FFF
#define MWV207REG_SO_WINDOW_ORIGIN_ResetValue                         0x00000000


#define MWV207REG_SO_WINDOW_ORIGIN_X                                        12:0
#define MWV207REG_SO_WINDOW_ORIGIN_X_End                                      12
#define MWV207REG_SO_WINDOW_ORIGIN_X_Start                                     0
#define MWV207REG_SO_WINDOW_ORIGIN_X_Type                                    U13


#define MWV207REG_SO_WINDOW_ORIGIN_Y                                       28:16
#define MWV207REG_SO_WINDOW_ORIGIN_Y_End                                      28
#define MWV207REG_SO_WINDOW_ORIGIN_Y_Start                                    16
#define MWV207REG_SO_WINDOW_ORIGIN_Y_Type                                    U13



#define mwv207regSOWindowSizeRegAddrs                                     0x5130
#define MWV207REG_SO_WINDOW_SIZE_Address                                 0x144C0
#define MWV207REG_SO_WINDOW_SIZE_MSB                                          15
#define MWV207REG_SO_WINDOW_SIZE_LSB                                           4
#define MWV207REG_SO_WINDOW_SIZE_BLK                                           4
#define MWV207REG_SO_WINDOW_SIZE_Count                                        16
#define MWV207REG_SO_WINDOW_SIZE_FieldMask                            0x3FFF3FFF
#define MWV207REG_SO_WINDOW_SIZE_ReadMask                             0x3FFF3FFF
#define MWV207REG_SO_WINDOW_SIZE_WriteMask                            0x3FFF3FFF
#define MWV207REG_SO_WINDOW_SIZE_ResetValue                           0x00000000


#define MWV207REG_SO_WINDOW_SIZE_WIDTH                                      13:0
#define MWV207REG_SO_WINDOW_SIZE_WIDTH_End                                    13
#define MWV207REG_SO_WINDOW_SIZE_WIDTH_Start                                   0
#define MWV207REG_SO_WINDOW_SIZE_WIDTH_Type                                  U14


#define MWV207REG_SO_WINDOW_SIZE_HEIGHT                                    29:16
#define MWV207REG_SO_WINDOW_SIZE_HEIGHT_End                                   29
#define MWV207REG_SO_WINDOW_SIZE_HEIGHT_Start                                 16
#define MWV207REG_SO_WINDOW_SIZE_HEIGHT_Type                                 U14




#define mwv207regSOStreamSizeRegAddrs                                     0x5104
#define MWV207REG_SO_STREAM_SIZE_Address                                 0x14410
#define MWV207REG_SO_STREAM_SIZE_MSB                                          15
#define MWV207REG_SO_STREAM_SIZE_LSB                                           2
#define MWV207REG_SO_STREAM_SIZE_BLK                                           2
#define MWV207REG_SO_STREAM_SIZE_Count                                         4
#define MWV207REG_SO_STREAM_SIZE_FieldMask                            0x3F3F3F3F
#define MWV207REG_SO_STREAM_SIZE_ReadMask                             0x3F3F3F3F
#define MWV207REG_SO_STREAM_SIZE_WriteMask                            0x3F3F3F3F
#define MWV207REG_SO_STREAM_SIZE_ResetValue                           0x00000000


#define MWV207REG_SO_STREAM_SIZE_STREAM0_4_8_12                              5:0
#define MWV207REG_SO_STREAM_SIZE_STREAM0_4_8_12_End                            5
#define MWV207REG_SO_STREAM_SIZE_STREAM0_4_8_12_Start                          0
#define MWV207REG_SO_STREAM_SIZE_STREAM0_4_8_12_Type                         U06


#define MWV207REG_SO_STREAM_SIZE_STREAM1_5_9_13                             13:8
#define MWV207REG_SO_STREAM_SIZE_STREAM1_5_9_13_End                           13
#define MWV207REG_SO_STREAM_SIZE_STREAM1_5_9_13_Start                          8
#define MWV207REG_SO_STREAM_SIZE_STREAM1_5_9_13_Type                         U06


#define MWV207REG_SO_STREAM_SIZE_STREAM2_6_10_14                           21:16
#define MWV207REG_SO_STREAM_SIZE_STREAM2_6_10_14_End                          21
#define MWV207REG_SO_STREAM_SIZE_STREAM2_6_10_14_Start                        16
#define MWV207REG_SO_STREAM_SIZE_STREAM2_6_10_14_Type                        U06


#define MWV207REG_SO_STREAM_SIZE_STREAM3_7_11_15                           29:24
#define MWV207REG_SO_STREAM_SIZE_STREAM3_7_11_15_End                          29
#define MWV207REG_SO_STREAM_SIZE_STREAM3_7_11_15_Start                        24
#define MWV207REG_SO_STREAM_SIZE_STREAM3_7_11_15_Type                        U06





#define mwv207regTFBControlRegAddrs                                       0x7000
#define MWV207REG_TFB_CONTROL_Address                                    0x1C000
#define MWV207REG_TFB_CONTROL_MSB                                             15
#define MWV207REG_TFB_CONTROL_LSB                                              0
#define MWV207REG_TFB_CONTROL_BLK                                              0
#define MWV207REG_TFB_CONTROL_Count                                            1
#define MWV207REG_TFB_CONTROL_FieldMask                               0x00000031
#define MWV207REG_TFB_CONTROL_ReadMask                                0x00000031
#define MWV207REG_TFB_CONTROL_WriteMask                               0x00000031
#define MWV207REG_TFB_CONTROL_ResetValue                              0x00000000

#define MWV207REG_TFB_CONTROL_IGNORE_ALL_STREAMS                             0:0
#define MWV207REG_TFB_CONTROL_IGNORE_ALL_STREAMS_End                           0
#define MWV207REG_TFB_CONTROL_IGNORE_ALL_STREAMS_Start                         0
#define MWV207REG_TFB_CONTROL_IGNORE_ALL_STREAMS_Type                        U01

#define   MWV207REG_TFB_CONTROL_IGNORE_ALL_STREAMS_PROCESS                   0x0

#define   MWV207REG_TFB_CONTROL_IGNORE_ALL_STREAMS_IGNORE                    0x1


#define MWV207REG_TFB_CONTROL_STREAM_INDEX                                   5:4
#define MWV207REG_TFB_CONTROL_STREAM_INDEX_End                                 5
#define MWV207REG_TFB_CONTROL_STREAM_INDEX_Start                               4
#define MWV207REG_TFB_CONTROL_STREAM_INDEX_Type                              U02




#define mwv207regTFBCommandRegAddrs                                       0x7001
#define MWV207REG_TFB_COMMAND_Address                                    0x1C004
#define MWV207REG_TFB_COMMAND_MSB                                             15
#define MWV207REG_TFB_COMMAND_LSB                                              0
#define MWV207REG_TFB_COMMAND_BLK                                              0
#define MWV207REG_TFB_COMMAND_Count                                            1
#define MWV207REG_TFB_COMMAND_FieldMask                               0x00000007
#define MWV207REG_TFB_COMMAND_ReadMask                                0x00000007
#define MWV207REG_TFB_COMMAND_WriteMask                               0x00000007
#define MWV207REG_TFB_COMMAND_ResetValue                              0x00000000


#define MWV207REG_TFB_COMMAND_COMMAND                                        2:0
#define MWV207REG_TFB_COMMAND_COMMAND_End                                      2
#define MWV207REG_TFB_COMMAND_COMMAND_Start                                    0
#define MWV207REG_TFB_COMMAND_COMMAND_Type                                   U03

#define   MWV207REG_TFB_COMMAND_COMMAND_IDLE                                 0x0

#define   MWV207REG_TFB_COMMAND_COMMAND_ACTIVE                               0x1
#define   MWV207REG_TFB_COMMAND_COMMAND_PAUSE                                0x2

#define   MWV207REG_TFB_COMMAND_COMMAND_RESUME                               0x3

#define   MWV207REG_TFB_COMMAND_COMMAND_RESUME_WITH_READ                     0x4



#define mwv207regTFBHeaderRegAddrs                                        0x7002
#define MWV207REG_TFB_HEADER_Address                                     0x1C008
#define MWV207REG_TFB_HEADER_MSB                                              15
#define MWV207REG_TFB_HEADER_LSB                                               0
#define MWV207REG_TFB_HEADER_BLK                                               0
#define MWV207REG_TFB_HEADER_Count                                             1
#define MWV207REG_TFB_HEADER_FieldMask                                0xFFFFFFFF
#define MWV207REG_TFB_HEADER_ReadMask                                 0xFFFFFFFF
#define MWV207REG_TFB_HEADER_WriteMask                                0xFFFFFFFF
#define MWV207REG_TFB_HEADER_ResetValue                               0x00000000

#define MWV207REG_TFB_HEADER_ADDRESS                                        31:0
#define MWV207REG_TFB_HEADER_ADDRESS_End                                      31
#define MWV207REG_TFB_HEADER_ADDRESS_Start                                     0
#define MWV207REG_TFB_HEADER_ADDRESS_Type                                    U32



#define mwv207regTFBBufferAddressRegAddrs                                 0x7010
#define MWV207REG_TFB_BUFFER_ADDRESS_Address                             0x1C040
#define MWV207REG_TFB_BUFFER_ADDRESS_MSB                                      15
#define MWV207REG_TFB_BUFFER_ADDRESS_LSB                                       4
#define MWV207REG_TFB_BUFFER_ADDRESS_BLK                                       4
#define MWV207REG_TFB_BUFFER_ADDRESS_Count                                    16
#define MWV207REG_TFB_BUFFER_ADDRESS_FieldMask                        0xFFFFFFFF
#define MWV207REG_TFB_BUFFER_ADDRESS_ReadMask                         0xFFFFFFFF
#define MWV207REG_TFB_BUFFER_ADDRESS_WriteMask                        0xFFFFFFFF
#define MWV207REG_TFB_BUFFER_ADDRESS_ResetValue                       0x00000000

#define MWV207REG_TFB_BUFFER_ADDRESS_ADDRESS                                31:0
#define MWV207REG_TFB_BUFFER_ADDRESS_ADDRESS_End                              31
#define MWV207REG_TFB_BUFFER_ADDRESS_ADDRESS_Start                             0
#define MWV207REG_TFB_BUFFER_ADDRESS_ADDRESS_Type                            U32



#define mwv207regTFBBufferSizeRegAddrs                                    0x7020
#define MWV207REG_TFB_BUFFER_SIZE_Address                                0x1C080
#define MWV207REG_TFB_BUFFER_SIZE_MSB                                         15
#define MWV207REG_TFB_BUFFER_SIZE_LSB                                          4
#define MWV207REG_TFB_BUFFER_SIZE_BLK                                          4
#define MWV207REG_TFB_BUFFER_SIZE_Count                                       16
#define MWV207REG_TFB_BUFFER_SIZE_FieldMask                           0xFFFFFFFF
#define MWV207REG_TFB_BUFFER_SIZE_ReadMask                            0xFFFFFFFF
#define MWV207REG_TFB_BUFFER_SIZE_WriteMask                           0xFFFFFFFF
#define MWV207REG_TFB_BUFFER_SIZE_ResetValue                          0x00000000


#define MWV207REG_TFB_BUFFER_SIZE_SIZE                                      31:0
#define MWV207REG_TFB_BUFFER_SIZE_SIZE_End                                    31
#define MWV207REG_TFB_BUFFER_SIZE_SIZE_Start                                   0
#define MWV207REG_TFB_BUFFER_SIZE_SIZE_Type                                  U32



#define mwv207regTFBBufferStrideRegAddrs                                  0x7030
#define MWV207REG_TFB_BUFFER_STRIDE_Address                              0x1C0C0
#define MWV207REG_TFB_BUFFER_STRIDE_MSB                                       15
#define MWV207REG_TFB_BUFFER_STRIDE_LSB                                        4
#define MWV207REG_TFB_BUFFER_STRIDE_BLK                                        4
#define MWV207REG_TFB_BUFFER_STRIDE_Count                                     16
#define MWV207REG_TFB_BUFFER_STRIDE_FieldMask                         0x00000FFF
#define MWV207REG_TFB_BUFFER_STRIDE_ReadMask                          0x00000FFF
#define MWV207REG_TFB_BUFFER_STRIDE_WriteMask                         0x00000FFF
#define MWV207REG_TFB_BUFFER_STRIDE_ResetValue                        0x00000000


#define MWV207REG_TFB_BUFFER_STRIDE_STRIDE                                  11:0
#define MWV207REG_TFB_BUFFER_STRIDE_STRIDE_End                                11
#define MWV207REG_TFB_BUFFER_STRIDE_STRIDE_Start                               0
#define MWV207REG_TFB_BUFFER_STRIDE_STRIDE_Type                              U12



#define mwv207regTFBDescriptorCountRegAddrs                               0x7040
#define MWV207REG_TFB_DESCRIPTOR_COUNT_Address                           0x1C100
#define MWV207REG_TFB_DESCRIPTOR_COUNT_MSB                                    15
#define MWV207REG_TFB_DESCRIPTOR_COUNT_LSB                                     4
#define MWV207REG_TFB_DESCRIPTOR_COUNT_BLK                                     4
#define MWV207REG_TFB_DESCRIPTOR_COUNT_Count                                  16
#define MWV207REG_TFB_DESCRIPTOR_COUNT_FieldMask                      0x000000FF
#define MWV207REG_TFB_DESCRIPTOR_COUNT_ReadMask                       0x000000FF
#define MWV207REG_TFB_DESCRIPTOR_COUNT_WriteMask                      0x000000FF
#define MWV207REG_TFB_DESCRIPTOR_COUNT_ResetValue                     0x00000000

#define MWV207REG_TFB_DESCRIPTOR_COUNT_COUNT                                 7:0
#define MWV207REG_TFB_DESCRIPTOR_COUNT_COUNT_End                               7
#define MWV207REG_TFB_DESCRIPTOR_COUNT_COUNT_Start                             0
#define MWV207REG_TFB_DESCRIPTOR_COUNT_COUNT_Type                            U08




#define mwv207regTFBDescriptorRegAddrs                                    0x7200
#define MWV207REG_TFB_DESCRIPTOR_Address                                 0x1C800
#define MWV207REG_TFB_DESCRIPTOR_MSB                                          15
#define MWV207REG_TFB_DESCRIPTOR_LSB                                           9
#define MWV207REG_TFB_DESCRIPTOR_BLK                                           9
#define MWV207REG_TFB_DESCRIPTOR_Count                                       512
#define MWV207REG_TFB_DESCRIPTOR_FieldMask                            0x00331F13
#define MWV207REG_TFB_DESCRIPTOR_ReadMask                             0x00331F13
#define MWV207REG_TFB_DESCRIPTOR_WriteMask                            0x00331F13
#define MWV207REG_TFB_DESCRIPTOR_ResetValue                           0x00000000


#define MWV207REG_TFB_DESCRIPTOR_BUFFER_INDEX                                1:0
#define MWV207REG_TFB_DESCRIPTOR_BUFFER_INDEX_End                              1
#define MWV207REG_TFB_DESCRIPTOR_BUFFER_INDEX_Start                            0
#define MWV207REG_TFB_DESCRIPTOR_BUFFER_INDEX_Type                           U02

#define MWV207REG_TFB_DESCRIPTOR_SKIP                                        4:4
#define MWV207REG_TFB_DESCRIPTOR_SKIP_End                                      4
#define MWV207REG_TFB_DESCRIPTOR_SKIP_Start                                    4
#define MWV207REG_TFB_DESCRIPTOR_SKIP_Type                                   U01


#define MWV207REG_TFB_DESCRIPTOR_ATTRIBUTE_INDEX                            12:8
#define MWV207REG_TFB_DESCRIPTOR_ATTRIBUTE_INDEX_End                          12
#define MWV207REG_TFB_DESCRIPTOR_ATTRIBUTE_INDEX_Start                         8
#define MWV207REG_TFB_DESCRIPTOR_ATTRIBUTE_INDEX_Type                        U05


#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_START                           17:16
#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_START_End                          17
#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_START_Start                        16
#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_START_Type                        U02
#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_START_X                         0x0
#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_START_Y                         0x1
#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_START_Z                         0x2
#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_START_W                         0x3


#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT                           21:20
#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT_End                          21
#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT_Start                        20
#define MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT_Type                        U02

#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT_ONE                       0x1

#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT_TWO                       0x2

#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT_THREE                     0x3

#define   MWV207REG_TFB_DESCRIPTOR_COMPONENT_COUNT_FOUR                      0x0




#define mwv207regTFBInvalidateRegAddrs                                    0x7003
#define MWV207REG_TFB_INVALIDATE_Address                                 0x1C00C
#define MWV207REG_TFB_INVALIDATE_MSB                                          15
#define MWV207REG_TFB_INVALIDATE_LSB                                           0
#define MWV207REG_TFB_INVALIDATE_BLK                                           0
#define MWV207REG_TFB_INVALIDATE_Count                                         1
#define MWV207REG_TFB_INVALIDATE_FieldMask                            0x00000001
#define MWV207REG_TFB_INVALIDATE_ReadMask                             0x00000001
#define MWV207REG_TFB_INVALIDATE_WriteMask                            0x00000001
#define MWV207REG_TFB_INVALIDATE_ResetValue                           0x00000000


#define MWV207REG_TFB_INVALIDATE_INVALIDATE                                  0:0
#define MWV207REG_TFB_INVALIDATE_INVALIDATE_End                                0
#define MWV207REG_TFB_INVALIDATE_INVALIDATE_Start                              0
#define MWV207REG_TFB_INVALIDATE_INVALIDATE_Type                             U01
#define   MWV207REG_TFB_INVALIDATE_INVALIDATE_TRUE                           0x1




#define mwv207regTFBQueryCommandRegAddrs                                  0x7004
#define MWV207REG_TFB_QUERY_COMMAND_Address                              0x1C010
#define MWV207REG_TFB_QUERY_COMMAND_MSB                                       15
#define MWV207REG_TFB_QUERY_COMMAND_LSB                                        0
#define MWV207REG_TFB_QUERY_COMMAND_BLK                                        0
#define MWV207REG_TFB_QUERY_COMMAND_Count                                      1
#define MWV207REG_TFB_QUERY_COMMAND_FieldMask                         0x00000FF7
#define MWV207REG_TFB_QUERY_COMMAND_ReadMask                          0x00000FF7
#define MWV207REG_TFB_QUERY_COMMAND_WriteMask                         0x00000FF7
#define MWV207REG_TFB_QUERY_COMMAND_ResetValue                        0x00000000


#define MWV207REG_TFB_QUERY_COMMAND_COMMAND                                  2:0
#define MWV207REG_TFB_QUERY_COMMAND_COMMAND_End                                2
#define MWV207REG_TFB_QUERY_COMMAND_COMMAND_Start                              0
#define MWV207REG_TFB_QUERY_COMMAND_COMMAND_Type                             U03

#define   MWV207REG_TFB_QUERY_COMMAND_COMMAND_IDLE                           0x0

#define   MWV207REG_TFB_QUERY_COMMAND_COMMAND_ACTIVE                         0x1

#define   MWV207REG_TFB_QUERY_COMMAND_COMMAND_PAUSE                          0x2

#define   MWV207REG_TFB_QUERY_COMMAND_COMMAND_RESUME                         0x3
#define   MWV207REG_TFB_QUERY_COMMAND_COMMAND_RESUME_WITH_READ               0x4


#define MWV207REG_TFB_QUERY_COMMAND_STREAM                                   7:4
#define MWV207REG_TFB_QUERY_COMMAND_STREAM_End                                 7
#define MWV207REG_TFB_QUERY_COMMAND_STREAM_Start                               4
#define MWV207REG_TFB_QUERY_COMMAND_STREAM_Type                              U04


#define MWV207REG_TFB_QUERY_COMMAND_QUERY                                   11:8
#define MWV207REG_TFB_QUERY_COMMAND_QUERY_End                                 11
#define MWV207REG_TFB_QUERY_COMMAND_QUERY_Start                                8
#define MWV207REG_TFB_QUERY_COMMAND_QUERY_Type                               U04

#define   MWV207REG_TFB_QUERY_COMMAND_QUERY_PRIMITIVES_WRITTEN               0x0

#define   MWV207REG_TFB_QUERY_COMMAND_QUERY_PRIMITIVES_GENERATED             0x1



#define mwv207regTFBQueryHeaderRegAddrs                                   0x7005
#define MWV207REG_TFB_QUERY_HEADER_Address                               0x1C014
#define MWV207REG_TFB_QUERY_HEADER_MSB                                        15
#define MWV207REG_TFB_QUERY_HEADER_LSB                                         0
#define MWV207REG_TFB_QUERY_HEADER_BLK                                         0
#define MWV207REG_TFB_QUERY_HEADER_Count                                       1
#define MWV207REG_TFB_QUERY_HEADER_FieldMask                          0xFFFFFFFF
#define MWV207REG_TFB_QUERY_HEADER_ReadMask                           0xFFFFFFFF
#define MWV207REG_TFB_QUERY_HEADER_WriteMask                          0xFFFFFFFF
#define MWV207REG_TFB_QUERY_HEADER_ResetValue                         0x00000000

#define MWV207REG_TFB_QUERY_HEADER_ADDRESS                                  31:0
#define MWV207REG_TFB_QUERY_HEADER_ADDRESS_End                                31
#define MWV207REG_TFB_QUERY_HEADER_ADDRESS_Start                               0
#define MWV207REG_TFB_QUERY_HEADER_ADDRESS_Type                              U32


#define   JMDEF_SO_PRIMITIVE_TYPE_NOT_READY                                  0x0
#define   JMDEF_SO_PRIMITIVE_TYPE_POINT                                      0x1
#define   JMDEF_SO_PRIMITIVE_TYPE_LINE                                       0x2
#define   JMDEF_SO_PRIMITIVE_TYPE_TRIANGLE                                   0x3


#endif


