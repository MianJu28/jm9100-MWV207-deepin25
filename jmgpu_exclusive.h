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




#ifndef __AQDma_h__
#define __AQDma_h__


#define AQVertexElementCtrlRegAddrs                                       0x0180
#define AQ_VERTEX_ELEMENT_CTRL_Address                                   0x00600
#define AQ_VERTEX_ELEMENT_CTRL_MSB                                            15
#define AQ_VERTEX_ELEMENT_CTRL_LSB                                             4
#define AQ_VERTEX_ELEMENT_CTRL_BLK                                             4
#define AQ_VERTEX_ELEMENT_CTRL_Count                                          16
#define AQ_VERTEX_ELEMENT_CTRL_FieldMask                              0xFFFFFFFF
#define AQ_VERTEX_ELEMENT_CTRL_ReadMask                               0xFFFFFFFF
#define AQ_VERTEX_ELEMENT_CTRL_WriteMask                              0xFFFFFFFF
#define AQ_VERTEX_ELEMENT_CTRL_ResetValue                             0x00000000

#define AQ_VERTEX_ELEMENT_CTRL_FORMAT                                        3:0
#define AQ_VERTEX_ELEMENT_CTRL_FORMAT_End                                      3
#define AQ_VERTEX_ELEMENT_CTRL_FORMAT_Start                                    0
#define AQ_VERTEX_ELEMENT_CTRL_FORMAT_Type                                   U04
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_BYTE                                 0x0
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_UBYTE                                0x1
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_SHORT                                0x2
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_USHORT                               0x3
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_INT                                  0x4
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_UINT                                 0x5
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_DEC                                  0x6
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_UDEC                                 0x7
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_FLOAT                                0x8
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_FLOAT16                              0x9
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_D3DCOLOR                             0xA
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_FIXED16DOT16                         0xB
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_GL_INT_10_10_10_2                    0xC
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_GL_UINT_10_10_10_2                   0xD
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_INT8                                 0xE
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_INT16                                0xF
#define   AQ_VERTEX_ELEMENT_CTRL_FORMAT_INT32                                0x8

#define AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL                                5:4
#define AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL_End                              5
#define AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL_Start                            4
#define AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL_Type                           U02
#define   AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL_NO_SWAP                      0x0
#define   AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL_SWAP_WORD                    0x1
#define   AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL_SWAP_DWORD                   0x2
#define   AQ_VERTEX_ELEMENT_CTRL_ENDIAN_CONTROL_SWAP_DDWORD                  0x3

#define AQ_VERTEX_ELEMENT_CTRL_GENERIC                                       6:6
#define AQ_VERTEX_ELEMENT_CTRL_GENERIC_End                                     6
#define AQ_VERTEX_ELEMENT_CTRL_GENERIC_Start                                   6
#define AQ_VERTEX_ELEMENT_CTRL_GENERIC_Type                                  U01
#define   AQ_VERTEX_ELEMENT_CTRL_GENERIC_DISABLE                             0x0
#define   AQ_VERTEX_ELEMENT_CTRL_GENERIC_ENABLE                              0x1

#define AQ_VERTEX_ELEMENT_CTRL_FETCH_BREAK                                   7:7
#define AQ_VERTEX_ELEMENT_CTRL_FETCH_BREAK_End                                 7
#define AQ_VERTEX_ELEMENT_CTRL_FETCH_BREAK_Start                               7
#define AQ_VERTEX_ELEMENT_CTRL_FETCH_BREAK_Type                              U01
#define   AQ_VERTEX_ELEMENT_CTRL_FETCH_BREAK_DISABLE                         0x0
#define   AQ_VERTEX_ELEMENT_CTRL_FETCH_BREAK_ENABLE                          0x1

#define AQ_VERTEX_ELEMENT_CTRL_STREAM_ID                                    11:8
#define AQ_VERTEX_ELEMENT_CTRL_STREAM_ID_End                                  11
#define AQ_VERTEX_ELEMENT_CTRL_STREAM_ID_Start                                 8
#define AQ_VERTEX_ELEMENT_CTRL_STREAM_ID_Type                                U04

#define AQ_VERTEX_ELEMENT_CTRL_SIZE                                        13:12
#define AQ_VERTEX_ELEMENT_CTRL_SIZE_End                                       13
#define AQ_VERTEX_ELEMENT_CTRL_SIZE_Start                                     12
#define AQ_VERTEX_ELEMENT_CTRL_SIZE_Type                                     U02
#define   AQ_VERTEX_ELEMENT_CTRL_SIZE_FOUR_ELEMENTS                          0x0
#define   AQ_VERTEX_ELEMENT_CTRL_SIZE_ONE_ELEMENT                            0x1
#define   AQ_VERTEX_ELEMENT_CTRL_SIZE_TWO_ELEMEMETS                          0x2
#define   AQ_VERTEX_ELEMENT_CTRL_SIZE_THREE_ELEMENTS                         0x3

#define AQ_VERTEX_ELEMENT_CTRL_NORMALIZE                                   15:14
#define AQ_VERTEX_ELEMENT_CTRL_NORMALIZE_End                                  15
#define AQ_VERTEX_ELEMENT_CTRL_NORMALIZE_Start                                14
#define AQ_VERTEX_ELEMENT_CTRL_NORMALIZE_Type                                U02
#define   AQ_VERTEX_ELEMENT_CTRL_NORMALIZE_DISABLE                           0x0
#define   AQ_VERTEX_ELEMENT_CTRL_NORMALIZE_D3D                               0x1
#define   AQ_VERTEX_ELEMENT_CTRL_NORMALIZE_OES                               0x2

#define AQ_VERTEX_ELEMENT_CTRL_OFFSET                                      23:16
#define AQ_VERTEX_ELEMENT_CTRL_OFFSET_End                                     23
#define AQ_VERTEX_ELEMENT_CTRL_OFFSET_Start                                   16
#define AQ_VERTEX_ELEMENT_CTRL_OFFSET_Type                                   U08

#define AQ_VERTEX_ELEMENT_CTRL_FETCH_SIZE                                  31:24
#define AQ_VERTEX_ELEMENT_CTRL_FETCH_SIZE_End                                 31
#define AQ_VERTEX_ELEMENT_CTRL_FETCH_SIZE_Start                               24
#define AQ_VERTEX_ELEMENT_CTRL_FETCH_SIZE_Type                               U08




#define AQCmdStreamBaseAddrRegAddrs                                       0x0190
#define AQ_CMD_STREAM_BASE_ADDR_Address                                  0x00640
#define AQ_CMD_STREAM_BASE_ADDR_MSB                                           15
#define AQ_CMD_STREAM_BASE_ADDR_LSB                                            0
#define AQ_CMD_STREAM_BASE_ADDR_BLK                                            0
#define AQ_CMD_STREAM_BASE_ADDR_Count                                          1
#define AQ_CMD_STREAM_BASE_ADDR_FieldMask                             0xFFFFFFFF
#define AQ_CMD_STREAM_BASE_ADDR_ReadMask                              0xFFFFFFFC
#define AQ_CMD_STREAM_BASE_ADDR_WriteMask                             0xFFFFFFFC
#define AQ_CMD_STREAM_BASE_ADDR_ResetValue                            0x00000000

#define AQ_CMD_STREAM_BASE_ADDR_TYPE                                       31:31
#define AQ_CMD_STREAM_BASE_ADDR_TYPE_End                                      31
#define AQ_CMD_STREAM_BASE_ADDR_TYPE_Start                                    31
#define AQ_CMD_STREAM_BASE_ADDR_TYPE_Type                                    U01
#define   AQ_CMD_STREAM_BASE_ADDR_TYPE_SYSTEM                                0x0
#define   AQ_CMD_STREAM_BASE_ADDR_TYPE_VIRTUAL_SYSTEM                        0x1

#define AQ_CMD_STREAM_BASE_ADDR_ADDRESS                                     30:0
#define AQ_CMD_STREAM_BASE_ADDR_ADDRESS_End                                   30
#define AQ_CMD_STREAM_BASE_ADDR_ADDRESS_Start                                  0
#define AQ_CMD_STREAM_BASE_ADDR_ADDRESS_Type                                 U31




#define AQIndexStreamBaseAddrRegAddrs                                     0x0191
#define AQ_INDEX_STREAM_BASE_ADDR_Address                                0x00644
#define AQ_INDEX_STREAM_BASE_ADDR_MSB                                         15
#define AQ_INDEX_STREAM_BASE_ADDR_LSB                                          0
#define AQ_INDEX_STREAM_BASE_ADDR_BLK                                          0
#define AQ_INDEX_STREAM_BASE_ADDR_Count                                        1
#define AQ_INDEX_STREAM_BASE_ADDR_FieldMask                           0xFFFFFFFF
#define AQ_INDEX_STREAM_BASE_ADDR_ReadMask                            0xFFFFFFFC
#define AQ_INDEX_STREAM_BASE_ADDR_WriteMask                           0xFFFFFFFC
#define AQ_INDEX_STREAM_BASE_ADDR_ResetValue                          0x00000000

#define AQ_INDEX_STREAM_BASE_ADDR_TYPE                                     31:31
#define AQ_INDEX_STREAM_BASE_ADDR_TYPE_End                                    31
#define AQ_INDEX_STREAM_BASE_ADDR_TYPE_Start                                  31
#define AQ_INDEX_STREAM_BASE_ADDR_TYPE_Type                                  U01
#define   AQ_INDEX_STREAM_BASE_ADDR_TYPE_SYSTEM                              0x0
#define   AQ_INDEX_STREAM_BASE_ADDR_TYPE_VIRTUAL_SYSTEM                      0x1

#define AQ_INDEX_STREAM_BASE_ADDR_ADDRESS                                   30:0
#define AQ_INDEX_STREAM_BASE_ADDR_ADDRESS_End                                 30
#define AQ_INDEX_STREAM_BASE_ADDR_ADDRESS_Start                                0
#define AQ_INDEX_STREAM_BASE_ADDR_ADDRESS_Type                               U31

#define AQIndexStreamCtrlRegAddrs                                         0x0192
#define AQ_INDEX_STREAM_CTRL_Address                                     0x00648
#define AQ_INDEX_STREAM_CTRL_MSB                                              15
#define AQ_INDEX_STREAM_CTRL_LSB                                               0
#define AQ_INDEX_STREAM_CTRL_BLK                                               0
#define AQ_INDEX_STREAM_CTRL_Count                                             1
#define AQ_INDEX_STREAM_CTRL_FieldMask                                0x00000133
#define AQ_INDEX_STREAM_CTRL_ReadMask                                 0x00000133
#define AQ_INDEX_STREAM_CTRL_WriteMask                                0x00000133
#define AQ_INDEX_STREAM_CTRL_ResetValue                               0x00000000


#define AQ_INDEX_STREAM_CTRL_STRIDE                                          1:0
#define AQ_INDEX_STREAM_CTRL_STRIDE_End                                        1
#define AQ_INDEX_STREAM_CTRL_STRIDE_Start                                      0
#define AQ_INDEX_STREAM_CTRL_STRIDE_Type                                     U02

#define   AQ_INDEX_STREAM_CTRL_STRIDE_INDEX8                                 0x0

#define   AQ_INDEX_STREAM_CTRL_STRIDE_INDEX16                                0x1

#define   AQ_INDEX_STREAM_CTRL_STRIDE_INDEX32                                0x2


#define AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL                                  5:4
#define AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL_End                                5
#define AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL_Start                              4
#define AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL_Type                             U02
#define   AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL_NO_SWAP                        0x0
#define   AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL_SWAP_WORD                      0x1
#define   AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL_SWAP_DWORD                     0x2
#define   AQ_INDEX_STREAM_CTRL_ENDIAN_CONTROL_SWAP_DDWORD                    0x3


#define AQ_INDEX_STREAM_CTRL_RESTART                                         8:8
#define AQ_INDEX_STREAM_CTRL_RESTART_End                                       8
#define AQ_INDEX_STREAM_CTRL_RESTART_Start                                     8
#define AQ_INDEX_STREAM_CTRL_RESTART_Type                                    U01
#define   AQ_INDEX_STREAM_CTRL_RESTART_DISABLE                               0x0
#define   AQ_INDEX_STREAM_CTRL_RESTART_ENABLE                                0x1




#define AQVertexStreamBaseAddrRegAddrs                                    0x0193
#define AQ_VERTEX_STREAM_BASE_ADDR_Address                               0x0064C
#define AQ_VERTEX_STREAM_BASE_ADDR_MSB                                        15
#define AQ_VERTEX_STREAM_BASE_ADDR_LSB                                         0
#define AQ_VERTEX_STREAM_BASE_ADDR_BLK                                         0
#define AQ_VERTEX_STREAM_BASE_ADDR_Count                                       1
#define AQ_VERTEX_STREAM_BASE_ADDR_FieldMask                          0xFFFFFFFF
#define AQ_VERTEX_STREAM_BASE_ADDR_ReadMask                           0xFFFFFFFC
#define AQ_VERTEX_STREAM_BASE_ADDR_WriteMask                          0xFFFFFFFC
#define AQ_VERTEX_STREAM_BASE_ADDR_ResetValue                         0x00000000

#define AQ_VERTEX_STREAM_BASE_ADDR_TYPE                                    31:31
#define AQ_VERTEX_STREAM_BASE_ADDR_TYPE_End                                   31
#define AQ_VERTEX_STREAM_BASE_ADDR_TYPE_Start                                 31
#define AQ_VERTEX_STREAM_BASE_ADDR_TYPE_Type                                 U01
#define   AQ_VERTEX_STREAM_BASE_ADDR_TYPE_SYSTEM                             0x0
#define   AQ_VERTEX_STREAM_BASE_ADDR_TYPE_VIRTUAL_SYSTEM                     0x1

#define AQ_VERTEX_STREAM_BASE_ADDR_ADDRESS                                  30:0
#define AQ_VERTEX_STREAM_BASE_ADDR_ADDRESS_End                                30
#define AQ_VERTEX_STREAM_BASE_ADDR_ADDRESS_Start                               0
#define AQ_VERTEX_STREAM_BASE_ADDR_ADDRESS_Type                              U31

#define AQVertexStreamCtrlRegAddrs                                        0x0194
#define AQ_VERTEX_STREAM_CTRL_Address                                    0x00650
#define AQ_VERTEX_STREAM_CTRL_MSB                                             15
#define AQ_VERTEX_STREAM_CTRL_LSB                                              0
#define AQ_VERTEX_STREAM_CTRL_BLK                                              0
#define AQ_VERTEX_STREAM_CTRL_Count                                            1
#define AQ_VERTEX_STREAM_CTRL_FieldMask                               0x000001FF
#define AQ_VERTEX_STREAM_CTRL_ReadMask                                0x000001FF
#define AQ_VERTEX_STREAM_CTRL_WriteMask                               0x000001FF
#define AQ_VERTEX_STREAM_CTRL_ResetValue                              0x00000000


#define AQ_VERTEX_STREAM_CTRL_STRIDE                                         8:0
#define AQ_VERTEX_STREAM_CTRL_STRIDE_End                                       8
#define AQ_VERTEX_STREAM_CTRL_STRIDE_Start                                     0
#define AQ_VERTEX_STREAM_CTRL_STRIDE_Type                                    U09



#define AQCmdBufferAddrRegAddrs                                           0x0195
#define AQ_CMD_BUFFER_ADDR_Address                                       0x00654
#define AQ_CMD_BUFFER_ADDR_MSB                                                15
#define AQ_CMD_BUFFER_ADDR_LSB                                                 0
#define AQ_CMD_BUFFER_ADDR_BLK                                                 0
#define AQ_CMD_BUFFER_ADDR_Count                                               1
#define AQ_CMD_BUFFER_ADDR_FieldMask                                  0xFFFFFFFF
#define AQ_CMD_BUFFER_ADDR_ReadMask                                   0x00000000
#define AQ_CMD_BUFFER_ADDR_WriteMask                                  0xFFFFFFFC
#define AQ_CMD_BUFFER_ADDR_ResetValue                                 0x00000000


#define AQ_CMD_BUFFER_ADDR_ADDRESS                                          30:0
#define AQ_CMD_BUFFER_ADDR_ADDRESS_End                                        30
#define AQ_CMD_BUFFER_ADDR_ADDRESS_Start                                       0
#define AQ_CMD_BUFFER_ADDR_ADDRESS_Type                                      U31


#define AQ_CMD_BUFFER_ADDR_TYPE                                            31:31
#define AQ_CMD_BUFFER_ADDR_TYPE_End                                           31
#define AQ_CMD_BUFFER_ADDR_TYPE_Start                                         31
#define AQ_CMD_BUFFER_ADDR_TYPE_Type                                         U01
#define   AQ_CMD_BUFFER_ADDR_TYPE_SYSTEM                                     0x0
#define   AQ_CMD_BUFFER_ADDR_TYPE_VIRTUAL_SYSTEM                             0x1



#define AQCmdBufferCtrlRegAddrs                                           0x0196
#define AQ_CMD_BUFFER_CTRL_Address                                       0x00658
#define AQ_CMD_BUFFER_CTRL_MSB                                                15
#define AQ_CMD_BUFFER_CTRL_LSB                                                 0
#define AQ_CMD_BUFFER_CTRL_BLK                                                 0
#define AQ_CMD_BUFFER_CTRL_Count                                               1
#define AQ_CMD_BUFFER_CTRL_FieldMask                                  0x0031FFFF
#define AQ_CMD_BUFFER_CTRL_ReadMask                                   0x00000000
#define AQ_CMD_BUFFER_CTRL_WriteMask                                  0x0031FFFF
#define AQ_CMD_BUFFER_CTRL_ResetValue                                 0x00000000

#define AQ_CMD_BUFFER_CTRL_PREFETCH                                         15:0
#define AQ_CMD_BUFFER_CTRL_PREFETCH_End                                       15
#define AQ_CMD_BUFFER_CTRL_PREFETCH_Start                                      0
#define AQ_CMD_BUFFER_CTRL_PREFETCH_Type                                     U16


#define AQ_CMD_BUFFER_CTRL_ENABLE                                          16:16
#define AQ_CMD_BUFFER_CTRL_ENABLE_End                                         16
#define AQ_CMD_BUFFER_CTRL_ENABLE_Start                                       16
#define AQ_CMD_BUFFER_CTRL_ENABLE_Type                                       U01
#define   AQ_CMD_BUFFER_CTRL_ENABLE_DISABLE                                  0x0
#define   AQ_CMD_BUFFER_CTRL_ENABLE_ENABLE                                   0x1


#define AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL                                  21:20
#define AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL_End                                 21
#define AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL_Start                               20
#define AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL_Type                               U02
#define   AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL_NO_SWAP                          0x0
#define   AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL_SWAP_WORD                        0x1
#define   AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL_SWAP_DWORD                       0x2
#define   AQ_CMD_BUFFER_CTRL_ENDIAN_CONTROL_SWAP_DDWORD                      0x3



#define AQFEStatusRegAddrs                                                0x0197
#define AQFE_STATUS_Address                                              0x0065C
#define AQFE_STATUS_MSB                                                       15
#define AQFE_STATUS_LSB                                                        0
#define AQFE_STATUS_BLK                                                        0
#define AQFE_STATUS_Count                                                      1
#define AQFE_STATUS_FieldMask                                         0x00000311
#define AQFE_STATUS_ReadMask                                          0x00000311
#define AQFE_STATUS_WriteMask                                         0x00000000
#define AQFE_STATUS_ResetValue                                        0x00000000


#define AQFE_STATUS_COMMAND_DATA                                             0:0
#define AQFE_STATUS_COMMAND_DATA_End                                           0
#define AQFE_STATUS_COMMAND_DATA_Start                                         0
#define AQFE_STATUS_COMMAND_DATA_Type                                        U01
#define   AQFE_STATUS_COMMAND_DATA_IDLE                                      0x0
#define   AQFE_STATUS_COMMAND_DATA_BUSY                                      0x1


#define AQFE_STATUS_ASYNC                                                    4:4
#define AQFE_STATUS_ASYNC_End                                                  4
#define AQFE_STATUS_ASYNC_Start                                                4
#define AQFE_STATUS_ASYNC_Type                                               U01

#define   AQFE_STATUS_ASYNC_IDLE                                             0x0

#define   AQFE_STATUS_ASYNC_BUSY                                             0x1


#define AQFE_STATUS_BLT                                                      9:8
#define AQFE_STATUS_BLT_End                                                    9
#define AQFE_STATUS_BLT_Start                                                  8
#define AQFE_STATUS_BLT_Type                                                 U02

#define   AQFE_STATUS_BLT_IDLE                                               0x0

#define   AQFE_STATUS_BLT_STATES_LOADING                                     0x1

#define   AQFE_STATUS_BLT_EXECUTING                                          0x2




#define AQFEDebugStateRegAddrs                                            0x0198
#define AQFE_DEBUG_STATE_Address                                         0x00660
#define AQFE_DEBUG_STATE_MSB                                                  15
#define AQFE_DEBUG_STATE_LSB                                                   0
#define AQFE_DEBUG_STATE_BLK                                                   0
#define AQFE_DEBUG_STATE_Count                                                 1
#define AQFE_DEBUG_STATE_FieldMask                                    0x0003FF1F
#define AQFE_DEBUG_STATE_ReadMask                                     0x0003FF1F
#define AQFE_DEBUG_STATE_WriteMask                                    0x00000000
#define AQFE_DEBUG_STATE_ResetValue                                   0x00000000

#define AQFE_DEBUG_STATE_CMD_STATE                                           4:0
#define AQFE_DEBUG_STATE_CMD_STATE_End                                         4
#define AQFE_DEBUG_STATE_CMD_STATE_Start                                       0
#define AQFE_DEBUG_STATE_CMD_STATE_Type                                      U05

#define AQFE_DEBUG_STATE_CMD_DMA_STATE                                       9:8
#define AQFE_DEBUG_STATE_CMD_DMA_STATE_End                                     9
#define AQFE_DEBUG_STATE_CMD_DMA_STATE_Start                                   8
#define AQFE_DEBUG_STATE_CMD_DMA_STATE_Type                                  U02

#define AQFE_DEBUG_STATE_CMD_FETCH_STATE                                   11:10
#define AQFE_DEBUG_STATE_CMD_FETCH_STATE_End                                  11
#define AQFE_DEBUG_STATE_CMD_FETCH_STATE_Start                                10
#define AQFE_DEBUG_STATE_CMD_FETCH_STATE_Type                                U02

#define AQFE_DEBUG_STATE_REQ_DMA_STATE                                     13:12
#define AQFE_DEBUG_STATE_REQ_DMA_STATE_End                                    13
#define AQFE_DEBUG_STATE_REQ_DMA_STATE_Start                                  12
#define AQFE_DEBUG_STATE_REQ_DMA_STATE_Type                                  U02

#define AQFE_DEBUG_STATE_CAL_STATE                                         15:14
#define AQFE_DEBUG_STATE_CAL_STATE_End                                        15
#define AQFE_DEBUG_STATE_CAL_STATE_Start                                      14
#define AQFE_DEBUG_STATE_CAL_STATE_Type                                      U02

#define AQFE_DEBUG_STATE_VE_REQ_STATE                                      17:16
#define AQFE_DEBUG_STATE_VE_REQ_STATE_End                                     17
#define AQFE_DEBUG_STATE_VE_REQ_STATE_Start                                   16
#define AQFE_DEBUG_STATE_VE_REQ_STATE_Type                                   U02



#define AQFEDebugCurCmdAdrRegAddrs                                        0x0199
#define AQFE_DEBUG_CUR_CMD_ADR_Address                                   0x00664
#define AQFE_DEBUG_CUR_CMD_ADR_MSB                                            15
#define AQFE_DEBUG_CUR_CMD_ADR_LSB                                             0
#define AQFE_DEBUG_CUR_CMD_ADR_BLK                                             0
#define AQFE_DEBUG_CUR_CMD_ADR_Count                                           1
#define AQFE_DEBUG_CUR_CMD_ADR_FieldMask                              0xFFFFFFF8
#define AQFE_DEBUG_CUR_CMD_ADR_ReadMask                               0xFFFFFFF8
#define AQFE_DEBUG_CUR_CMD_ADR_WriteMask                              0x00000000
#define AQFE_DEBUG_CUR_CMD_ADR_ResetValue                             0x00000000

#define AQFE_DEBUG_CUR_CMD_ADR_CUR_CMD_ADR                                  31:3
#define AQFE_DEBUG_CUR_CMD_ADR_CUR_CMD_ADR_End                                31
#define AQFE_DEBUG_CUR_CMD_ADR_CUR_CMD_ADR_Start                               3
#define AQFE_DEBUG_CUR_CMD_ADR_CUR_CMD_ADR_Type                              U29




#define AQFEDebugCmdLowRegRegAddrs                                        0x019A
#define AQFE_DEBUG_CMD_LOW_REG_Address                                   0x00668
#define AQFE_DEBUG_CMD_LOW_REG_MSB                                            15
#define AQFE_DEBUG_CMD_LOW_REG_LSB                                             0
#define AQFE_DEBUG_CMD_LOW_REG_BLK                                             0
#define AQFE_DEBUG_CMD_LOW_REG_Count                                           1
#define AQFE_DEBUG_CMD_LOW_REG_FieldMask                              0xFFFFFFFF
#define AQFE_DEBUG_CMD_LOW_REG_ReadMask                               0xFFFFFFFF
#define AQFE_DEBUG_CMD_LOW_REG_WriteMask                              0x00000000
#define AQFE_DEBUG_CMD_LOW_REG_ResetValue                             0x00000000


#define AQFE_DEBUG_CMD_LOW_REG_CMD_LOW_REG                                  31:0
#define AQFE_DEBUG_CMD_LOW_REG_CMD_LOW_REG_End                                31
#define AQFE_DEBUG_CMD_LOW_REG_CMD_LOW_REG_Start                               0
#define AQFE_DEBUG_CMD_LOW_REG_CMD_LOW_REG_Type                              U32




#define AQFEDebugCmdHiRegRegAddrs                                         0x019B
#define AQFE_DEBUG_CMD_HI_REG_Address                                    0x0066C
#define AQFE_DEBUG_CMD_HI_REG_MSB                                             15
#define AQFE_DEBUG_CMD_HI_REG_LSB                                              0
#define AQFE_DEBUG_CMD_HI_REG_BLK                                              0
#define AQFE_DEBUG_CMD_HI_REG_Count                                            1
#define AQFE_DEBUG_CMD_HI_REG_FieldMask                               0xFFFFFFFF
#define AQFE_DEBUG_CMD_HI_REG_ReadMask                                0xFFFFFFFF
#define AQFE_DEBUG_CMD_HI_REG_WriteMask                               0x00000000
#define AQFE_DEBUG_CMD_HI_REG_ResetValue                              0x00000000


#define AQFE_DEBUG_CMD_HI_REG_CMD_HI_REG                                    31:0
#define AQFE_DEBUG_CMD_HI_REG_CMD_HI_REG_End                                  31
#define AQFE_DEBUG_CMD_HI_REG_CMD_HI_REG_Start                                 0
#define AQFE_DEBUG_CMD_HI_REG_CMD_HI_REG_Type                                U32




#define mwv207regFEVertexAddressRegAddrs                                  0x01A0
#define MWV207REG_FE_VERTEX_ADDRESS_Address                              0x00680
#define MWV207REG_FE_VERTEX_ADDRESS_MSB                                       15
#define MWV207REG_FE_VERTEX_ADDRESS_LSB                                        3
#define MWV207REG_FE_VERTEX_ADDRESS_BLK                                        3
#define MWV207REG_FE_VERTEX_ADDRESS_Count                                      8
#define MWV207REG_FE_VERTEX_ADDRESS_FieldMask                         0xFFFFFFFF
#define MWV207REG_FE_VERTEX_ADDRESS_ReadMask                          0xFFFFFFFC
#define MWV207REG_FE_VERTEX_ADDRESS_WriteMask                         0xFFFFFFFC
#define MWV207REG_FE_VERTEX_ADDRESS_ResetValue                        0x00000000

#define MWV207REG_FE_VERTEX_ADDRESS_TYPE                                   31:31
#define MWV207REG_FE_VERTEX_ADDRESS_TYPE_End                                  31
#define MWV207REG_FE_VERTEX_ADDRESS_TYPE_Start                                31
#define MWV207REG_FE_VERTEX_ADDRESS_TYPE_Type                                U01
#define   MWV207REG_FE_VERTEX_ADDRESS_TYPE_SYSTEM                            0x0
#define   MWV207REG_FE_VERTEX_ADDRESS_TYPE_VIRTUAL_SYSTEM                    0x1

#define MWV207REG_FE_VERTEX_ADDRESS_ADDRESS                                 30:0
#define MWV207REG_FE_VERTEX_ADDRESS_ADDRESS_End                               30
#define MWV207REG_FE_VERTEX_ADDRESS_ADDRESS_Start                              0
#define MWV207REG_FE_VERTEX_ADDRESS_ADDRESS_Type                             U31

#define mwv207regFEVertexStrideRegAddrs                                   0x01A8
#define MWV207REG_FE_VERTEX_STRIDE_Address                               0x006A0
#define MWV207REG_FE_VERTEX_STRIDE_MSB                                        15
#define MWV207REG_FE_VERTEX_STRIDE_LSB                                         3
#define MWV207REG_FE_VERTEX_STRIDE_BLK                                         3
#define MWV207REG_FE_VERTEX_STRIDE_Count                                       8
#define MWV207REG_FE_VERTEX_STRIDE_FieldMask                          0xFFFF81FF
#define MWV207REG_FE_VERTEX_STRIDE_ReadMask                           0xFFFF81FF
#define MWV207REG_FE_VERTEX_STRIDE_WriteMask                          0xFFFF81FF
#define MWV207REG_FE_VERTEX_STRIDE_ResetValue                         0x00000000


#define MWV207REG_FE_VERTEX_STRIDE_STRIDE                                    8:0
#define MWV207REG_FE_VERTEX_STRIDE_STRIDE_End                                  8
#define MWV207REG_FE_VERTEX_STRIDE_STRIDE_Start                                0
#define MWV207REG_FE_VERTEX_STRIDE_STRIDE_Type                               U09


#define MWV207REG_FE_VERTEX_STRIDE_INSTANCE_MODE                           15:15
#define MWV207REG_FE_VERTEX_STRIDE_INSTANCE_MODE_End                          15
#define MWV207REG_FE_VERTEX_STRIDE_INSTANCE_MODE_Start                        15
#define MWV207REG_FE_VERTEX_STRIDE_INSTANCE_MODE_Type                        U01
#define   MWV207REG_FE_VERTEX_STRIDE_INSTANCE_MODE_PER_INSTANCE              0x0
#define   MWV207REG_FE_VERTEX_STRIDE_INSTANCE_MODE_PER_VERTEX                0x1


#define MWV207REG_FE_VERTEX_STRIDE_DIVISOR                                 31:16
#define MWV207REG_FE_VERTEX_STRIDE_DIVISOR_End                                31
#define MWV207REG_FE_VERTEX_STRIDE_DIVISOR_Start                              16
#define MWV207REG_FE_VERTEX_STRIDE_DIVISOR_Type                              U16



#define mwv207regFEDETimeoutRegAddrs                                      0x019C
#define MWV207REG_FEDE_TIMEOUT_Address                                   0x00670
#define MWV207REG_FEDE_TIMEOUT_MSB                                            15
#define MWV207REG_FEDE_TIMEOUT_LSB                                             0
#define MWV207REG_FEDE_TIMEOUT_BLK                                             0
#define MWV207REG_FEDE_TIMEOUT_Count                                           1
#define MWV207REG_FEDE_TIMEOUT_FieldMask                              0xFFFFFFFF
#define MWV207REG_FEDE_TIMEOUT_ReadMask                               0xFFFFFFFF
#define MWV207REG_FEDE_TIMEOUT_WriteMask                              0xFFFFFFFF
#define MWV207REG_FEDE_TIMEOUT_ResetValue                             0x00000000


#define MWV207REG_FEDE_TIMEOUT_COUNTER                                      31:0
#define MWV207REG_FEDE_TIMEOUT_COUNTER_End                                    31
#define MWV207REG_FEDE_TIMEOUT_COUNTER_Start                                   0
#define MWV207REG_FEDE_TIMEOUT_COUNTER_Type                                  U32

#define mwv207regFEPrimitiveRestartRegAddrs                               0x019D
#define MWV207REG_FE_PRIMITIVE_RESTART_Address                           0x00674
#define MWV207REG_FE_PRIMITIVE_RESTART_MSB                                    15
#define MWV207REG_FE_PRIMITIVE_RESTART_LSB                                     0
#define MWV207REG_FE_PRIMITIVE_RESTART_BLK                                     0
#define MWV207REG_FE_PRIMITIVE_RESTART_Count                                   1
#define MWV207REG_FE_PRIMITIVE_RESTART_FieldMask                      0xFFFFFFFF
#define MWV207REG_FE_PRIMITIVE_RESTART_ReadMask                       0xFFFFFFFF
#define MWV207REG_FE_PRIMITIVE_RESTART_WriteMask                      0xFFFFFFFF
#define MWV207REG_FE_PRIMITIVE_RESTART_ResetValue                     0x00000000

#define MWV207REG_FE_PRIMITIVE_RESTART_INDEX                                31:0
#define MWV207REG_FE_PRIMITIVE_RESTART_INDEX_End                              31
#define MWV207REG_FE_PRIMITIVE_RESTART_INDEX_Start                             0
#define MWV207REG_FE_PRIMITIVE_RESTART_INDEX_Type                            U32




#define mwv207regFEIndexMinRegAddrs                                       0x019E
#define MWV207REG_FE_INDEX_MIN_Address                                   0x00678
#define MWV207REG_FE_INDEX_MIN_MSB                                            15
#define MWV207REG_FE_INDEX_MIN_LSB                                             0
#define MWV207REG_FE_INDEX_MIN_BLK                                             0
#define MWV207REG_FE_INDEX_MIN_Count                                           1
#define MWV207REG_FE_INDEX_MIN_FieldMask                              0xFFFFFFFF
#define MWV207REG_FE_INDEX_MIN_ReadMask                               0xFFFFFFFF
#define MWV207REG_FE_INDEX_MIN_WriteMask                              0xFFFFFFFF
#define MWV207REG_FE_INDEX_MIN_ResetValue                             0x00000000

#define MWV207REG_FE_INDEX_MIN_INDEX                                        31:0
#define MWV207REG_FE_INDEX_MIN_INDEX_End                                      31
#define MWV207REG_FE_INDEX_MIN_INDEX_Start                                     0
#define MWV207REG_FE_INDEX_MIN_INDEX_Type                                    U32




#define mwv207regFEIndexMaxRegAddrs                                       0x019F
#define MWV207REG_FE_INDEX_MAX_Address                                   0x0067C
#define MWV207REG_FE_INDEX_MAX_MSB                                            15
#define MWV207REG_FE_INDEX_MAX_LSB                                             0
#define MWV207REG_FE_INDEX_MAX_BLK                                             0
#define MWV207REG_FE_INDEX_MAX_Count                                           1
#define MWV207REG_FE_INDEX_MAX_FieldMask                              0xFFFFFFFF
#define MWV207REG_FE_INDEX_MAX_ReadMask                               0xFFFFFFFF
#define MWV207REG_FE_INDEX_MAX_WriteMask                              0xFFFFFFFF
#define MWV207REG_FE_INDEX_MAX_ResetValue                             0xFFFFFFFF

#define MWV207REG_FE_INDEX_MAX_INDEX                                        31:0
#define MWV207REG_FE_INDEX_MAX_INDEX_End                                      31
#define MWV207REG_FE_INDEX_MAX_INDEX_Start                                     0
#define MWV207REG_FE_INDEX_MAX_INDEX_Type                                    U32



#define mwv207regFEGenericsXRegAddrs                                      0x01B0
#define MWV207REG_FE_GENERICS_X_Address                                  0x006C0
#define MWV207REG_FE_GENERICS_X_MSB                                           15
#define MWV207REG_FE_GENERICS_X_LSB                                            4
#define MWV207REG_FE_GENERICS_X_BLK                                            4
#define MWV207REG_FE_GENERICS_X_Count                                         16
#define MWV207REG_FE_GENERICS_X_FieldMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_X_ReadMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERICS_X_WriteMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_X_ResetValue                            0x00000000


#define MWV207REG_FE_GENERICS_X_FL32                                        31:0
#define MWV207REG_FE_GENERICS_X_FL32_End                                      31
#define MWV207REG_FE_GENERICS_X_FL32_Start                                     0
#define MWV207REG_FE_GENERICS_X_FL32_Type                                    U32



#define mwv207regFEGenericsYRegAddrs                                      0x01C0
#define MWV207REG_FE_GENERICS_Y_Address                                  0x00700
#define MWV207REG_FE_GENERICS_Y_MSB                                           15
#define MWV207REG_FE_GENERICS_Y_LSB                                            4
#define MWV207REG_FE_GENERICS_Y_BLK                                            4
#define MWV207REG_FE_GENERICS_Y_Count                                         16
#define MWV207REG_FE_GENERICS_Y_FieldMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_Y_ReadMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERICS_Y_WriteMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_Y_ResetValue                            0x00000000


#define MWV207REG_FE_GENERICS_Y_FL32                                        31:0
#define MWV207REG_FE_GENERICS_Y_FL32_End                                      31
#define MWV207REG_FE_GENERICS_Y_FL32_Start                                     0
#define MWV207REG_FE_GENERICS_Y_FL32_Type                                    U32



#define mwv207regFEGenericsZRegAddrs                                      0x01D0
#define MWV207REG_FE_GENERICS_Z_Address                                  0x00740
#define MWV207REG_FE_GENERICS_Z_MSB                                           15
#define MWV207REG_FE_GENERICS_Z_LSB                                            4
#define MWV207REG_FE_GENERICS_Z_BLK                                            4
#define MWV207REG_FE_GENERICS_Z_Count                                         16
#define MWV207REG_FE_GENERICS_Z_FieldMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_Z_ReadMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERICS_Z_WriteMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_Z_ResetValue                            0x00000000


#define MWV207REG_FE_GENERICS_Z_FL32                                        31:0
#define MWV207REG_FE_GENERICS_Z_FL32_End                                      31
#define MWV207REG_FE_GENERICS_Z_FL32_Start                                     0
#define MWV207REG_FE_GENERICS_Z_FL32_Type                                    U32



#define mwv207regFEGenericsWRegAddrs                                      0x01E0
#define MWV207REG_FE_GENERICS_W_Address                                  0x00780
#define MWV207REG_FE_GENERICS_W_MSB                                           15
#define MWV207REG_FE_GENERICS_W_LSB                                            4
#define MWV207REG_FE_GENERICS_W_BLK                                            4
#define MWV207REG_FE_GENERICS_W_Count                                         16
#define MWV207REG_FE_GENERICS_W_FieldMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_W_ReadMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERICS_W_WriteMask                             0xFFFFFFFF
#define MWV207REG_FE_GENERICS_W_ResetValue                            0x3F800000


#define MWV207REG_FE_GENERICS_W_FL32                                        31:0
#define MWV207REG_FE_GENERICS_W_FL32_End                                      31
#define MWV207REG_FE_GENERICS_W_FL32_Start                                     0
#define MWV207REG_FE_GENERICS_W_FL32_Type                                    U32




#define mwv207regFEPatchControlRegAddrs                                   0x01F0
#define MWV207REG_FE_PATCH_CONTROL_Address                               0x007C0
#define MWV207REG_FE_PATCH_CONTROL_MSB                                        15
#define MWV207REG_FE_PATCH_CONTROL_LSB                                         0
#define MWV207REG_FE_PATCH_CONTROL_BLK                                         0
#define MWV207REG_FE_PATCH_CONTROL_Count                                       1
#define MWV207REG_FE_PATCH_CONTROL_FieldMask                          0x0000003F
#define MWV207REG_FE_PATCH_CONTROL_ReadMask                           0x0000003F
#define MWV207REG_FE_PATCH_CONTROL_WriteMask                          0x0000003F
#define MWV207REG_FE_PATCH_CONTROL_ResetValue                         0x00000003


#define MWV207REG_FE_PATCH_CONTROL_VERTEX_COUNT                              5:0
#define MWV207REG_FE_PATCH_CONTROL_VERTEX_COUNT_End                            5
#define MWV207REG_FE_PATCH_CONTROL_VERTEX_COUNT_Start                          0
#define MWV207REG_FE_PATCH_CONTROL_VERTEX_COUNT_Type                         U06




#define mwv207regFEIdRegAddrs                                             0x01F1
#define MWV207REG_FE_ID_Address                                          0x007C4
#define MWV207REG_FE_ID_MSB                                                   15
#define MWV207REG_FE_ID_LSB                                                    0
#define MWV207REG_FE_ID_BLK                                                    0
#define MWV207REG_FE_ID_Count                                                  1
#define MWV207REG_FE_ID_FieldMask                                     0x007F7F13
#define MWV207REG_FE_ID_ReadMask                                      0x007F7F13
#define MWV207REG_FE_ID_WriteMask                                     0x007F7F13
#define MWV207REG_FE_ID_ResetValue                                    0x00000000


#define MWV207REG_FE_ID_ID_SELECT                                            1:0
#define MWV207REG_FE_ID_ID_SELECT_End                                          1
#define MWV207REG_FE_ID_ID_SELECT_Start                                        0
#define MWV207REG_FE_ID_ID_SELECT_Type                                       U02

#define   MWV207REG_FE_ID_ID_SELECT_DISABLE                                  0x0

#define   MWV207REG_FE_ID_ID_SELECT_VERTEX_ID                                0x1

#define   MWV207REG_FE_ID_ID_SELECT_INSTANCE_ID                              0x2

#define   MWV207REG_FE_ID_ID_SELECT_BOTH                                     0x3


#define MWV207REG_FE_ID_PRIMITIVE_ID_RESET                                   4:4
#define MWV207REG_FE_ID_PRIMITIVE_ID_RESET_End                                 4
#define MWV207REG_FE_ID_PRIMITIVE_ID_RESET_Start                               4
#define MWV207REG_FE_ID_PRIMITIVE_ID_RESET_Type                              U01

#define   MWV207REG_FE_ID_PRIMITIVE_ID_RESET_PER_INSTANCE                    0x0

#define   MWV207REG_FE_ID_PRIMITIVE_ID_RESET_PER_DRAW                        0x1


#define MWV207REG_FE_ID_VERTEX_ID_LOCATION                                  14:8
#define MWV207REG_FE_ID_VERTEX_ID_LOCATION_End                                14
#define MWV207REG_FE_ID_VERTEX_ID_LOCATION_Start                               8
#define MWV207REG_FE_ID_VERTEX_ID_LOCATION_Type                              U07


#define MWV207REG_FE_ID_INSTANCE_ID_LOCATION                               22:16
#define MWV207REG_FE_ID_INSTANCE_ID_LOCATION_End                              22
#define MWV207REG_FE_ID_INSTANCE_ID_LOCATION_Start                            16
#define MWV207REG_FE_ID_INSTANCE_ID_LOCATION_Type                            U07




#define mwv207regFEResetAttributesRegAddrs                                0x01F2
#define MWV207REG_FE_RESET_ATTRIBUTES_Address                            0x007C8
#define MWV207REG_FE_RESET_ATTRIBUTES_MSB                                     15
#define MWV207REG_FE_RESET_ATTRIBUTES_LSB                                      0
#define MWV207REG_FE_RESET_ATTRIBUTES_BLK                                      0
#define MWV207REG_FE_RESET_ATTRIBUTES_Count                                    1
#define MWV207REG_FE_RESET_ATTRIBUTES_FieldMask                       0x00000001
#define MWV207REG_FE_RESET_ATTRIBUTES_ReadMask                        0x00000001
#define MWV207REG_FE_RESET_ATTRIBUTES_WriteMask                       0x00000001
#define MWV207REG_FE_RESET_ATTRIBUTES_ResetValue                      0x00000000


#define MWV207REG_FE_RESET_ATTRIBUTES_RESET                                  0:0
#define MWV207REG_FE_RESET_ATTRIBUTES_RESET_End                                0
#define MWV207REG_FE_RESET_ATTRIBUTES_RESET_Start                              0
#define MWV207REG_FE_RESET_ATTRIBUTES_RESET_Type                             U01




#define mwv207regFEComputeIndirectRegAddrs                                0x01F3
#define MWV207REG_FE_COMPUTE_INDIRECT_Address                            0x007CC
#define MWV207REG_FE_COMPUTE_INDIRECT_MSB                                     15
#define MWV207REG_FE_COMPUTE_INDIRECT_LSB                                      0
#define MWV207REG_FE_COMPUTE_INDIRECT_BLK                                      0
#define MWV207REG_FE_COMPUTE_INDIRECT_Count                                    1
#define MWV207REG_FE_COMPUTE_INDIRECT_FieldMask                       0x000003FF
#define MWV207REG_FE_COMPUTE_INDIRECT_ReadMask                        0x000003FF
#define MWV207REG_FE_COMPUTE_INDIRECT_WriteMask                       0x000003FF
#define MWV207REG_FE_COMPUTE_INDIRECT_ResetValue                      0x00000000


#define MWV207REG_FE_COMPUTE_INDIRECT_UNIFORM                                8:0
#define MWV207REG_FE_COMPUTE_INDIRECT_UNIFORM_End                              8
#define MWV207REG_FE_COMPUTE_INDIRECT_UNIFORM_Start                            0
#define MWV207REG_FE_COMPUTE_INDIRECT_UNIFORM_Type                           U09


#define MWV207REG_FE_COMPUTE_INDIRECT_DISABLE_PASSING_UNIFORM                9:9
#define MWV207REG_FE_COMPUTE_INDIRECT_DISABLE_PASSING_UNIFORM_End              9
#define MWV207REG_FE_COMPUTE_INDIRECT_DISABLE_PASSING_UNIFORM_Start            9
#define MWV207REG_FE_COMPUTE_INDIRECT_DISABLE_PASSING_UNIFORM_Type           U01
#define   MWV207REG_FE_COMPUTE_INDIRECT_DISABLE_PASSING_UNIFORM_DISABLE      0x0
#define   MWV207REG_FE_COMPUTE_INDIRECT_DISABLE_PASSING_UNIFORM_ENABLE       0x1



#define mwv207regFEPackingRegAddrs                                        0x01F4
#define MWV207REG_FE_PACKING_Address                                     0x007D0
#define MWV207REG_FE_PACKING_MSB                                              15
#define MWV207REG_FE_PACKING_LSB                                               1
#define MWV207REG_FE_PACKING_BLK                                               1
#define MWV207REG_FE_PACKING_Count                                             2
#define MWV207REG_FE_PACKING_FieldMask                                0xFFFFFFFF
#define MWV207REG_FE_PACKING_ReadMask                                 0xFFFFFFFF
#define MWV207REG_FE_PACKING_WriteMask                                0xFFFFFFFF
#define MWV207REG_FE_PACKING_ResetValue                               0x00000000


#define MWV207REG_FE_PACKING_ATTRIBUTE0                                      1:0
#define MWV207REG_FE_PACKING_ATTRIBUTE0_End                                    1
#define MWV207REG_FE_PACKING_ATTRIBUTE0_Start                                  0
#define MWV207REG_FE_PACKING_ATTRIBUTE0_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE1                                      3:2
#define MWV207REG_FE_PACKING_ATTRIBUTE1_End                                    3
#define MWV207REG_FE_PACKING_ATTRIBUTE1_Start                                  2
#define MWV207REG_FE_PACKING_ATTRIBUTE1_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE2                                      5:4
#define MWV207REG_FE_PACKING_ATTRIBUTE2_End                                    5
#define MWV207REG_FE_PACKING_ATTRIBUTE2_Start                                  4
#define MWV207REG_FE_PACKING_ATTRIBUTE2_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE3                                      7:6
#define MWV207REG_FE_PACKING_ATTRIBUTE3_End                                    7
#define MWV207REG_FE_PACKING_ATTRIBUTE3_Start                                  6
#define MWV207REG_FE_PACKING_ATTRIBUTE3_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE4                                      9:8
#define MWV207REG_FE_PACKING_ATTRIBUTE4_End                                    9
#define MWV207REG_FE_PACKING_ATTRIBUTE4_Start                                  8
#define MWV207REG_FE_PACKING_ATTRIBUTE4_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE5                                    11:10
#define MWV207REG_FE_PACKING_ATTRIBUTE5_End                                   11
#define MWV207REG_FE_PACKING_ATTRIBUTE5_Start                                 10
#define MWV207REG_FE_PACKING_ATTRIBUTE5_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE6                                    13:12
#define MWV207REG_FE_PACKING_ATTRIBUTE6_End                                   13
#define MWV207REG_FE_PACKING_ATTRIBUTE6_Start                                 12
#define MWV207REG_FE_PACKING_ATTRIBUTE6_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE7                                    15:14
#define MWV207REG_FE_PACKING_ATTRIBUTE7_End                                   15
#define MWV207REG_FE_PACKING_ATTRIBUTE7_Start                                 14
#define MWV207REG_FE_PACKING_ATTRIBUTE7_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE8                                    17:16
#define MWV207REG_FE_PACKING_ATTRIBUTE8_End                                   17
#define MWV207REG_FE_PACKING_ATTRIBUTE8_Start                                 16
#define MWV207REG_FE_PACKING_ATTRIBUTE8_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE9                                    19:18
#define MWV207REG_FE_PACKING_ATTRIBUTE9_End                                   19
#define MWV207REG_FE_PACKING_ATTRIBUTE9_Start                                 18
#define MWV207REG_FE_PACKING_ATTRIBUTE9_Type                                 U02


#define MWV207REG_FE_PACKING_ATTRIBUTE10                                   21:20
#define MWV207REG_FE_PACKING_ATTRIBUTE10_End                                  21
#define MWV207REG_FE_PACKING_ATTRIBUTE10_Start                                20
#define MWV207REG_FE_PACKING_ATTRIBUTE10_Type                                U02


#define MWV207REG_FE_PACKING_ATTRIBUTE11                                   23:22
#define MWV207REG_FE_PACKING_ATTRIBUTE11_End                                  23
#define MWV207REG_FE_PACKING_ATTRIBUTE11_Start                                22
#define MWV207REG_FE_PACKING_ATTRIBUTE11_Type                                U02


#define MWV207REG_FE_PACKING_ATTRIBUTE12                                   25:24
#define MWV207REG_FE_PACKING_ATTRIBUTE12_End                                  25
#define MWV207REG_FE_PACKING_ATTRIBUTE12_Start                                24
#define MWV207REG_FE_PACKING_ATTRIBUTE12_Type                                U02


#define MWV207REG_FE_PACKING_ATTRIBUTE13                                   27:26
#define MWV207REG_FE_PACKING_ATTRIBUTE13_End                                  27
#define MWV207REG_FE_PACKING_ATTRIBUTE13_Start                                26
#define MWV207REG_FE_PACKING_ATTRIBUTE13_Type                                U02


#define MWV207REG_FE_PACKING_ATTRIBUTE14                                   29:28
#define MWV207REG_FE_PACKING_ATTRIBUTE14_End                                  29
#define MWV207REG_FE_PACKING_ATTRIBUTE14_Start                                28
#define MWV207REG_FE_PACKING_ATTRIBUTE14_Type                                U02


#define MWV207REG_FE_PACKING_ATTRIBUTE15                                   31:30
#define MWV207REG_FE_PACKING_ATTRIBUTE15_End                                  31
#define MWV207REG_FE_PACKING_ATTRIBUTE15_Start                                30
#define MWV207REG_FE_PACKING_ATTRIBUTE15_Type                                U02




#define mwv207regFEControlRegAddrs                                        0x01F6
#define MWV207REG_FE_CONTROL_Address                                     0x007D8
#define MWV207REG_FE_CONTROL_MSB                                              15
#define MWV207REG_FE_CONTROL_LSB                                               0
#define MWV207REG_FE_CONTROL_BLK                                               0
#define MWV207REG_FE_CONTROL_Count                                             1
#define MWV207REG_FE_CONTROL_FieldMask                                0x00000003
#define MWV207REG_FE_CONTROL_ReadMask                                 0x00000003
#define MWV207REG_FE_CONTROL_WriteMask                                0x00000003
#define MWV207REG_FE_CONTROL_ResetValue                               0x00000000

#define MWV207REG_FE_CONTROL_RETAIN_MODE                                     0:0
#define MWV207REG_FE_CONTROL_RETAIN_MODE_End                                   0
#define MWV207REG_FE_CONTROL_RETAIN_MODE_Start                                 0
#define MWV207REG_FE_CONTROL_RETAIN_MODE_Type                                U01

#define   MWV207REG_FE_CONTROL_RETAIN_MODE_DEFAULT                           0x0

#define   MWV207REG_FE_CONTROL_RETAIN_MODE_RETAIN                            0x1


#define MWV207REG_FE_CONTROL_FETCH_BREAK_MODE                                1:1
#define MWV207REG_FE_CONTROL_FETCH_BREAK_MODE_End                              1
#define MWV207REG_FE_CONTROL_FETCH_BREAK_MODE_Start                            1
#define MWV207REG_FE_CONTROL_FETCH_BREAK_MODE_Type                           U01
#define   MWV207REG_FE_CONTROL_FETCH_BREAK_MODE_DISABLE                      0x0

#define   MWV207REG_FE_CONTROL_FETCH_BREAK_MODE_ENABLE                       0x1



#define mwv207regFEDescriptorStartAddressRegAddrs                         0x01F7
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_Address                    0x007DC
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_MSB                             15
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_LSB                              0
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_BLK                              0
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_Count                            1
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_FieldMask               0xFFFFFFFF
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_ReadMask                0xFFFFFFFC
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_WriteMask               0xFFFFFFFC
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_ResetValue              0x00000000


#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_ADDRESS                       31:0
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_ADDRESS_End                     31
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_ADDRESS_Start                    0
#define MWV207REG_FE_DESCRIPTOR_START_ADDRESS_ADDRESS_Type                   U32



#define mwv207regFEDescriptorEndAddressRegAddrs                           0x01F8
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_Address                      0x007E0
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_MSB                               15
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_LSB                                0
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_BLK                                0
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_Count                              1
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_FieldMask                 0xFFFFFFFF
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_ReadMask                  0xFFFFFFFC
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_WriteMask                 0xFFFFFFFC
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_ResetValue                0x00000000


#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_ADDRESS                         31:0
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_ADDRESS_End                       31
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_ADDRESS_Start                      0
#define MWV207REG_FE_DESCRIPTOR_END_ADDRESS_ADDRESS_Type                     U32



#define mwv207regFEAsyncStatusRegAddrs                                    0x01F9
#define MWV207REG_FE_ASYNC_STATUS_Address                                0x007E4
#define MWV207REG_FE_ASYNC_STATUS_MSB                                         15
#define MWV207REG_FE_ASYNC_STATUS_LSB                                          0
#define MWV207REG_FE_ASYNC_STATUS_BLK                                          0
#define MWV207REG_FE_ASYNC_STATUS_Count                                        1
#define MWV207REG_FE_ASYNC_STATUS_FieldMask                           0x0000007F
#define MWV207REG_FE_ASYNC_STATUS_ReadMask                            0x0000007F
#define MWV207REG_FE_ASYNC_STATUS_WriteMask                           0x00000000
#define MWV207REG_FE_ASYNC_STATUS_ResetValue                          0x00000000

#define MWV207REG_FE_ASYNC_STATUS_FREE_DESCRIPTOR                            6:0
#define MWV207REG_FE_ASYNC_STATUS_FREE_DESCRIPTOR_End                          6
#define MWV207REG_FE_ASYNC_STATUS_FREE_DESCRIPTOR_Start                        0
#define MWV207REG_FE_ASYNC_STATUS_FREE_DESCRIPTOR_Type                       U07




#define mwv207regFEFenceDataRegAddrs                                      0x01FA
#define MWV207REG_FE_FENCE_DATA_Address                                  0x007E8
#define MWV207REG_FE_FENCE_DATA_MSB                                           15
#define MWV207REG_FE_FENCE_DATA_LSB                                            0
#define MWV207REG_FE_FENCE_DATA_BLK                                            0
#define MWV207REG_FE_FENCE_DATA_Count                                          1
#define MWV207REG_FE_FENCE_DATA_FieldMask                             0xFFFFFFFF
#define MWV207REG_FE_FENCE_DATA_ReadMask                              0xFFFFFFFF
#define MWV207REG_FE_FENCE_DATA_WriteMask                             0xFFFFFFFF
#define MWV207REG_FE_FENCE_DATA_ResetValue                            0x00000000


#define MWV207REG_FE_FENCE_DATA_DATA                                        31:0
#define MWV207REG_FE_FENCE_DATA_DATA_End                                      31
#define MWV207REG_FE_FENCE_DATA_DATA_Start                                     0
#define MWV207REG_FE_FENCE_DATA_DATA_Type                                    U32




#define mwv207regFEBaseInstanceRegAddrs                                   0x01FB
#define MWV207REG_FE_BASE_INSTANCE_Address                               0x007EC
#define MWV207REG_FE_BASE_INSTANCE_MSB                                        15
#define MWV207REG_FE_BASE_INSTANCE_LSB                                         0
#define MWV207REG_FE_BASE_INSTANCE_BLK                                         0
#define MWV207REG_FE_BASE_INSTANCE_Count                                       1
#define MWV207REG_FE_BASE_INSTANCE_FieldMask                          0xFFFFFFFF
#define MWV207REG_FE_BASE_INSTANCE_ReadMask                           0xFFFFFFFF
#define MWV207REG_FE_BASE_INSTANCE_WriteMask                          0xFFFFFFFF
#define MWV207REG_FE_BASE_INSTANCE_ResetValue                         0x00000000


#define MWV207REG_FE_BASE_INSTANCE_BASE_INSTANCE                            31:0
#define MWV207REG_FE_BASE_INSTANCE_BASE_INSTANCE_End                          31
#define MWV207REG_FE_BASE_INSTANCE_BASE_INSTANCE_Start                         0
#define MWV207REG_FE_BASE_INSTANCE_BASE_INSTANCE_Type                        U32

#define mwv207regFEAsyncConfigRegAddrs                                    0x01FC
#define MWV207REG_FE_ASYNC_CONFIG_Address                                0x007F0
#define MWV207REG_FE_ASYNC_CONFIG_MSB                                         15
#define MWV207REG_FE_ASYNC_CONFIG_LSB                                          0
#define MWV207REG_FE_ASYNC_CONFIG_BLK                                          0
#define MWV207REG_FE_ASYNC_CONFIG_Count                                        1
#define MWV207REG_FE_ASYNC_CONFIG_FieldMask                           0x0000003F
#define MWV207REG_FE_ASYNC_CONFIG_ReadMask                            0x0000003F
#define MWV207REG_FE_ASYNC_CONFIG_WriteMask                           0x0000003F
#define MWV207REG_FE_ASYNC_CONFIG_ResetValue                          0x00000000


#define MWV207REG_FE_ASYNC_CONFIG_FETCH_COUNT                                5:0
#define MWV207REG_FE_ASYNC_CONFIG_FETCH_COUNT_End                              5
#define MWV207REG_FE_ASYNC_CONFIG_FETCH_COUNT_Start                            0
#define MWV207REG_FE_ASYNC_CONFIG_FETCH_COUNT_Type                           U06




#define mwv207regFEFenceDataHighRegAddrs                                  0x01FD
#define MWV207REG_FE_FENCE_DATA_HIGH_Address                             0x007F4
#define MWV207REG_FE_FENCE_DATA_HIGH_MSB                                      15
#define MWV207REG_FE_FENCE_DATA_HIGH_LSB                                       0
#define MWV207REG_FE_FENCE_DATA_HIGH_BLK                                       0
#define MWV207REG_FE_FENCE_DATA_HIGH_Count                                     1
#define MWV207REG_FE_FENCE_DATA_HIGH_FieldMask                        0xFFFFFFFF
#define MWV207REG_FE_FENCE_DATA_HIGH_ReadMask                         0xFFFFFFFF
#define MWV207REG_FE_FENCE_DATA_HIGH_WriteMask                        0xFFFFFFFF
#define MWV207REG_FE_FENCE_DATA_HIGH_ResetValue                       0x00000000


#define MWV207REG_FE_FENCE_DATA_HIGH_DATA                                   31:0
#define MWV207REG_FE_FENCE_DATA_HIGH_DATA_End                                 31
#define MWV207REG_FE_FENCE_DATA_HIGH_DATA_Start                                0
#define MWV207REG_FE_FENCE_DATA_HIGH_DATA_Type                               U32




#define mwv207regFEIndexEndAddressRegAddrs                                0x01FE
#define MWV207REG_FE_INDEX_END_ADDRESS_Address                           0x007F8
#define MWV207REG_FE_INDEX_END_ADDRESS_MSB                                    15
#define MWV207REG_FE_INDEX_END_ADDRESS_LSB                                     0
#define MWV207REG_FE_INDEX_END_ADDRESS_BLK                                     0
#define MWV207REG_FE_INDEX_END_ADDRESS_Count                                   1
#define MWV207REG_FE_INDEX_END_ADDRESS_FieldMask                      0xFFFFFFFF
#define MWV207REG_FE_INDEX_END_ADDRESS_ReadMask                       0xFFFFFFFF
#define MWV207REG_FE_INDEX_END_ADDRESS_WriteMask                      0xFFFFFFFF
#define MWV207REG_FE_INDEX_END_ADDRESS_ResetValue                     0x00000000

#define MWV207REG_FE_INDEX_END_ADDRESS_ADDRESS                              31:0
#define MWV207REG_FE_INDEX_END_ADDRESS_ADDRESS_End                            31
#define MWV207REG_FE_INDEX_END_ADDRESS_ADDRESS_Start                           0
#define MWV207REG_FE_INDEX_END_ADDRESS_ADDRESS_Type                          U32

#define mwv207regFAControlRegAddrs                                        0x01FF
#define MWV207REG_FA_CONTROL_Address                                     0x007FC
#define MWV207REG_FA_CONTROL_MSB                                              15
#define MWV207REG_FA_CONTROL_LSB                                               0
#define MWV207REG_FA_CONTROL_BLK                                               0
#define MWV207REG_FA_CONTROL_Count                                             1
#define MWV207REG_FA_CONTROL_FieldMask                                0x00000003
#define MWV207REG_FA_CONTROL_ReadMask                                 0x00000003
#define MWV207REG_FA_CONTROL_WriteMask                                0x00000003
#define MWV207REG_FA_CONTROL_ResetValue                               0x00000000


#define MWV207REG_FA_CONTROL_VERTEX_FETCH                                    1:0
#define MWV207REG_FA_CONTROL_VERTEX_FETCH_End                                  1
#define MWV207REG_FA_CONTROL_VERTEX_FETCH_Start                                0
#define MWV207REG_FA_CONTROL_VERTEX_FETCH_Type                               U02
#define   MWV207REG_FA_CONTROL_VERTEX_FETCH_DISABLE                          0x0
#define   MWV207REG_FA_CONTROL_VERTEX_FETCH_ENABLE_WITH_LOCK                 0x1
#define   MWV207REG_FA_CONTROL_VERTEX_FETCH_ENABLE_WITHOUT_LOCK              0x2





#define mwv207regFEStreamAddressRegAddrs                                  0x5180
#define MWV207REG_FE_STREAM_ADDRESS_Address                              0x14600
#define MWV207REG_FE_STREAM_ADDRESS_MSB                                       15
#define MWV207REG_FE_STREAM_ADDRESS_LSB                                        4
#define MWV207REG_FE_STREAM_ADDRESS_BLK                                        4
#define MWV207REG_FE_STREAM_ADDRESS_Count                                     16
#define MWV207REG_FE_STREAM_ADDRESS_FieldMask                         0xFFFFFFFF
#define MWV207REG_FE_STREAM_ADDRESS_ReadMask                          0xFFFFFFFC
#define MWV207REG_FE_STREAM_ADDRESS_WriteMask                         0xFFFFFFFC
#define MWV207REG_FE_STREAM_ADDRESS_ResetValue                        0x00000000

#define MWV207REG_FE_STREAM_ADDRESS_TYPE                                   31:31
#define MWV207REG_FE_STREAM_ADDRESS_TYPE_End                                  31
#define MWV207REG_FE_STREAM_ADDRESS_TYPE_Start                                31
#define MWV207REG_FE_STREAM_ADDRESS_TYPE_Type                                U01
#define   MWV207REG_FE_STREAM_ADDRESS_TYPE_SYSTEM                            0x0
#define   MWV207REG_FE_STREAM_ADDRESS_TYPE_VIRTUAL_SYSTEM                    0x1

#define MWV207REG_FE_STREAM_ADDRESS_ADDRESS                                 30:0
#define MWV207REG_FE_STREAM_ADDRESS_ADDRESS_End                               30
#define MWV207REG_FE_STREAM_ADDRESS_ADDRESS_Start                              0
#define MWV207REG_FE_STREAM_ADDRESS_ADDRESS_Type                             U31




#define mwv207regFEStreamStrideRegAddrs                                   0x5190
#define MWV207REG_FE_STREAM_STRIDE_Address                               0x14640
#define MWV207REG_FE_STREAM_STRIDE_MSB                                        15
#define MWV207REG_FE_STREAM_STRIDE_LSB                                         4
#define MWV207REG_FE_STREAM_STRIDE_BLK                                         4
#define MWV207REG_FE_STREAM_STRIDE_Count                                      16
#define MWV207REG_FE_STREAM_STRIDE_FieldMask                          0x00008FFF
#define MWV207REG_FE_STREAM_STRIDE_ReadMask                           0x00008FFF
#define MWV207REG_FE_STREAM_STRIDE_WriteMask                          0x00008FFF
#define MWV207REG_FE_STREAM_STRIDE_ResetValue                         0x00000000


#define MWV207REG_FE_STREAM_STRIDE_STRIDE                                   11:0
#define MWV207REG_FE_STREAM_STRIDE_STRIDE_End                                 11
#define MWV207REG_FE_STREAM_STRIDE_STRIDE_Start                                0
#define MWV207REG_FE_STREAM_STRIDE_STRIDE_Type                               U12


#define MWV207REG_FE_STREAM_STRIDE_INSTANCE_MODE                           15:15
#define MWV207REG_FE_STREAM_STRIDE_INSTANCE_MODE_End                          15
#define MWV207REG_FE_STREAM_STRIDE_INSTANCE_MODE_Start                        15
#define MWV207REG_FE_STREAM_STRIDE_INSTANCE_MODE_Type                        U01
#define   MWV207REG_FE_STREAM_STRIDE_INSTANCE_MODE_PER_INSTANCE              0x0
#define   MWV207REG_FE_STREAM_STRIDE_INSTANCE_MODE_PER_VERTEX                0x1




#define mwv207regFEStreamDivisorRegAddrs                                  0x51A0
#define MWV207REG_FE_STREAM_DIVISOR_Address                              0x14680
#define MWV207REG_FE_STREAM_DIVISOR_MSB                                       15
#define MWV207REG_FE_STREAM_DIVISOR_LSB                                        4
#define MWV207REG_FE_STREAM_DIVISOR_BLK                                        4
#define MWV207REG_FE_STREAM_DIVISOR_Count                                     16
#define MWV207REG_FE_STREAM_DIVISOR_FieldMask                         0xFFFFFFFF
#define MWV207REG_FE_STREAM_DIVISOR_ReadMask                          0xFFFFFFFF
#define MWV207REG_FE_STREAM_DIVISOR_WriteMask                         0xFFFFFFFF
#define MWV207REG_FE_STREAM_DIVISOR_ResetValue                        0x00000000

#define MWV207REG_FE_STREAM_DIVISOR_DIVISOR                                 31:0
#define MWV207REG_FE_STREAM_DIVISOR_DIVISOR_End                               31
#define MWV207REG_FE_STREAM_DIVISOR_DIVISOR_Start                              0
#define MWV207REG_FE_STREAM_DIVISOR_DIVISOR_Type                             U32




#define mwv207regFEStreamEndAddressRegAddrs                               0x51B0
#define MWV207REG_FE_STREAM_END_ADDRESS_Address                          0x146C0
#define MWV207REG_FE_STREAM_END_ADDRESS_MSB                                   15
#define MWV207REG_FE_STREAM_END_ADDRESS_LSB                                    4
#define MWV207REG_FE_STREAM_END_ADDRESS_BLK                                    4
#define MWV207REG_FE_STREAM_END_ADDRESS_Count                                 16
#define MWV207REG_FE_STREAM_END_ADDRESS_FieldMask                     0xFFFFFFFF
#define MWV207REG_FE_STREAM_END_ADDRESS_ReadMask                      0xFFFFFFFF
#define MWV207REG_FE_STREAM_END_ADDRESS_WriteMask                     0xFFFFFFFF
#define MWV207REG_FE_STREAM_END_ADDRESS_ResetValue                    0x00000000

#define MWV207REG_FE_STREAM_END_ADDRESS_ADDRESS                             31:0
#define MWV207REG_FE_STREAM_END_ADDRESS_ADDRESS_End                           31
#define MWV207REG_FE_STREAM_END_ADDRESS_ADDRESS_Start                          0
#define MWV207REG_FE_STREAM_END_ADDRESS_ADDRESS_Type                         U32





#define mwv207regFEAttributeRegAddrs                                      0x5E00
#define MWV207REG_FE_ATTRIBUTE_Address                                   0x17800
#define MWV207REG_FE_ATTRIBUTE_MSB                                            15
#define MWV207REG_FE_ATTRIBUTE_LSB                                             5
#define MWV207REG_FE_ATTRIBUTE_BLK                                             0
#define MWV207REG_FE_ATTRIBUTE_Count                                          32
#define MWV207REG_FE_ATTRIBUTE_FieldMask                              0xFFFFFFFF
#define MWV207REG_FE_ATTRIBUTE_ReadMask                               0xFFFFFFFF
#define MWV207REG_FE_ATTRIBUTE_WriteMask                              0xFFFFFFFF
#define MWV207REG_FE_ATTRIBUTE_ResetValue                             0x00000000


#define MWV207REG_FE_ATTRIBUTE_FORMAT                                        3:0
#define MWV207REG_FE_ATTRIBUTE_FORMAT_End                                      3
#define MWV207REG_FE_ATTRIBUTE_FORMAT_Start                                    0
#define MWV207REG_FE_ATTRIBUTE_FORMAT_Type                                   U04

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_BYTE                                 0x0

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_UBYTE                                0x1

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_SHORT                                0x2

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_USHORT                               0x3

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_INT                                  0x4

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_UINT                                 0x5

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_DEC                                  0x6

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_UDEC                                 0x7

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_FLOAT                                0x8

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_FLOAT16                              0x9
#define   MWV207REG_FE_ATTRIBUTE_FORMAT_COLOR                                0xA

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_FIXED16_DOT16                        0xB

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_GL_INT_10_10_10_2                    0xC

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_GL_UINT_10_10_10_2                   0xD

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_INT8                                 0xE

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_INT16                                0xF

#define   MWV207REG_FE_ATTRIBUTE_FORMAT_INT32                                0x8


#define MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL                                5:4
#define MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL_End                              5
#define MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL_Start                            4
#define MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL_Type                           U02

#define   MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL_NO_SWAP                      0x0

#define   MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL_SWAP_WORD                    0x1

#define   MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL_SWAP_DWORD                   0x2

#define   MWV207REG_FE_ATTRIBUTE_ENDIAN_CONTROL_SWAP_DDWORD                  0x3

#define MWV207REG_FE_ATTRIBUTE_GENERIC                                       6:6
#define MWV207REG_FE_ATTRIBUTE_GENERIC_End                                     6
#define MWV207REG_FE_ATTRIBUTE_GENERIC_Start                                   6
#define MWV207REG_FE_ATTRIBUTE_GENERIC_Type                                  U01
#define   MWV207REG_FE_ATTRIBUTE_GENERIC_DISABLE                             0x0
#define   MWV207REG_FE_ATTRIBUTE_GENERIC_ENABLE                              0x1


#define MWV207REG_FE_ATTRIBUTE_FORMAT_BIT4                                   7:7
#define MWV207REG_FE_ATTRIBUTE_FORMAT_BIT4_End                                 7
#define MWV207REG_FE_ATTRIBUTE_FORMAT_BIT4_Start                               7
#define MWV207REG_FE_ATTRIBUTE_FORMAT_BIT4_Type                              U01


#define MWV207REG_FE_ATTRIBUTE_STREAM_ID                                    11:8
#define MWV207REG_FE_ATTRIBUTE_STREAM_ID_End                                  11
#define MWV207REG_FE_ATTRIBUTE_STREAM_ID_Start                                 8
#define MWV207REG_FE_ATTRIBUTE_STREAM_ID_Type                                U04

#define MWV207REG_FE_ATTRIBUTE_SIZE                                        13:12
#define MWV207REG_FE_ATTRIBUTE_SIZE_End                                       13
#define MWV207REG_FE_ATTRIBUTE_SIZE_Start                                     12
#define MWV207REG_FE_ATTRIBUTE_SIZE_Type                                     U02

#define   MWV207REG_FE_ATTRIBUTE_SIZE_ONE                                    0x1

#define   MWV207REG_FE_ATTRIBUTE_SIZE_TWO                                    0x2

#define   MWV207REG_FE_ATTRIBUTE_SIZE_THREE                                  0x3

#define   MWV207REG_FE_ATTRIBUTE_SIZE_FOUR                                   0x0

#define MWV207REG_FE_ATTRIBUTE_NORMALIZE                                   15:14
#define MWV207REG_FE_ATTRIBUTE_NORMALIZE_End                                  15
#define MWV207REG_FE_ATTRIBUTE_NORMALIZE_Start                                14
#define MWV207REG_FE_ATTRIBUTE_NORMALIZE_Type                                U02

#define   MWV207REG_FE_ATTRIBUTE_NORMALIZE_DISABLE                           0x0

#define   MWV207REG_FE_ATTRIBUTE_NORMALIZE_D3D                               0x1

#define   MWV207REG_FE_ATTRIBUTE_NORMALIZE_OPEN_GL                           0x2


#define MWV207REG_FE_ATTRIBUTE_OFFSET                                      31:16
#define MWV207REG_FE_ATTRIBUTE_OFFSET_End                                     31
#define MWV207REG_FE_ATTRIBUTE_OFFSET_Start                                   16
#define MWV207REG_FE_ATTRIBUTE_OFFSET_Type                                   U16



#define mwv207regFEGenericXRegAddrs                                       0x5E20
#define MWV207REG_FE_GENERIC_X_Address                                   0x17880
#define MWV207REG_FE_GENERIC_X_MSB                                            15
#define MWV207REG_FE_GENERIC_X_LSB                                             5
#define MWV207REG_FE_GENERIC_X_BLK                                             0
#define MWV207REG_FE_GENERIC_X_Count                                          32
#define MWV207REG_FE_GENERIC_X_FieldMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_X_ReadMask                               0xFFFFFFFF
#define MWV207REG_FE_GENERIC_X_WriteMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_X_ResetValue                             0x00000000


#define MWV207REG_FE_GENERIC_X_VALUE                                        31:0
#define MWV207REG_FE_GENERIC_X_VALUE_End                                      31
#define MWV207REG_FE_GENERIC_X_VALUE_Start                                     0
#define MWV207REG_FE_GENERIC_X_VALUE_Type                                    U32



#define mwv207regFEGenericYRegAddrs                                       0x5E40
#define MWV207REG_FE_GENERIC_Y_Address                                   0x17900
#define MWV207REG_FE_GENERIC_Y_MSB                                            15
#define MWV207REG_FE_GENERIC_Y_LSB                                             5
#define MWV207REG_FE_GENERIC_Y_BLK                                             0
#define MWV207REG_FE_GENERIC_Y_Count                                          32
#define MWV207REG_FE_GENERIC_Y_FieldMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_Y_ReadMask                               0xFFFFFFFF
#define MWV207REG_FE_GENERIC_Y_WriteMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_Y_ResetValue                             0x00000000


#define MWV207REG_FE_GENERIC_Y_VALUE                                        31:0
#define MWV207REG_FE_GENERIC_Y_VALUE_End                                      31
#define MWV207REG_FE_GENERIC_Y_VALUE_Start                                     0
#define MWV207REG_FE_GENERIC_Y_VALUE_Type                                    U32



#define mwv207regFEGenericZRegAddrs                                       0x5E60
#define MWV207REG_FE_GENERIC_Z_Address                                   0x17980
#define MWV207REG_FE_GENERIC_Z_MSB                                            15
#define MWV207REG_FE_GENERIC_Z_LSB                                             5
#define MWV207REG_FE_GENERIC_Z_BLK                                             0
#define MWV207REG_FE_GENERIC_Z_Count                                          32
#define MWV207REG_FE_GENERIC_Z_FieldMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_Z_ReadMask                               0xFFFFFFFF
#define MWV207REG_FE_GENERIC_Z_WriteMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_Z_ResetValue                             0x00000000


#define MWV207REG_FE_GENERIC_Z_VALUE                                        31:0
#define MWV207REG_FE_GENERIC_Z_VALUE_End                                      31
#define MWV207REG_FE_GENERIC_Z_VALUE_Start                                     0
#define MWV207REG_FE_GENERIC_Z_VALUE_Type                                    U32



#define mwv207regFEGenericWRegAddrs                                       0x5E80
#define MWV207REG_FE_GENERIC_W_Address                                   0x17A00
#define MWV207REG_FE_GENERIC_W_MSB                                            15
#define MWV207REG_FE_GENERIC_W_LSB                                             5
#define MWV207REG_FE_GENERIC_W_BLK                                             0
#define MWV207REG_FE_GENERIC_W_Count                                          32
#define MWV207REG_FE_GENERIC_W_FieldMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_W_ReadMask                               0xFFFFFFFF
#define MWV207REG_FE_GENERIC_W_WriteMask                              0xFFFFFFFF
#define MWV207REG_FE_GENERIC_W_ResetValue                             0x3F800000


#define MWV207REG_FE_GENERIC_W_VALUE                                        31:0
#define MWV207REG_FE_GENERIC_W_VALUE_End                                      31
#define MWV207REG_FE_GENERIC_W_VALUE_Start                                     0
#define MWV207REG_FE_GENERIC_W_VALUE_Type                                    U32



#define mwv207regFEFetchRegAddrs                                          0x5EA0
#define MWV207REG_FE_FETCH_Address                                       0x17A80
#define MWV207REG_FE_FETCH_MSB                                                15
#define MWV207REG_FE_FETCH_LSB                                                 5
#define MWV207REG_FE_FETCH_BLK                                                 0
#define MWV207REG_FE_FETCH_Count                                              32
#define MWV207REG_FE_FETCH_FieldMask                                  0x000009FF
#define MWV207REG_FE_FETCH_ReadMask                                   0x000009FF
#define MWV207REG_FE_FETCH_WriteMask                                  0x000009FF
#define MWV207REG_FE_FETCH_ResetValue                                 0x00000000

#define MWV207REG_FE_FETCH_FETCH_SIZE                                        8:0
#define MWV207REG_FE_FETCH_FETCH_SIZE_End                                      8
#define MWV207REG_FE_FETCH_FETCH_SIZE_Start                                    0
#define MWV207REG_FE_FETCH_FETCH_SIZE_Type                                   U09

#define MWV207REG_FE_FETCH_FETCH_BREAK                                     11:11
#define MWV207REG_FE_FETCH_FETCH_BREAK_End                                    11
#define MWV207REG_FE_FETCH_FETCH_BREAK_Start                                  11
#define MWV207REG_FE_FETCH_FETCH_BREAK_Type                                  U01
#define   MWV207REG_FE_FETCH_FETCH_BREAK_DISABLE                             0x0
#define   MWV207REG_FE_FETCH_FETCH_BREAK_ENABLE                              0x1





#define mwv207regFEPosOnlyAttributesRegAddrs                              0x5400
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_Address                         0x15000
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_MSB                                  15
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_LSB                                   4
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_BLK                                   0
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_Count                                16
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FieldMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_ReadMask                     0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_WriteMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_ResetValue                   0x00000000

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT                              3:0
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_End                            3
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_Start                          0
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_Type                         U04
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_BYTE                       0x0
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_UBYTE                      0x1
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_SHORT                      0x2
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_USHORT                     0x3
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_INT                        0x4
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_UINT                       0x5
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_DEC                        0x6
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_UDEC                       0x7
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_FLOAT                      0x8
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_FLOAT16                    0x9
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_D3DCOLOR                   0xA
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_FIXED16DOT16               0xB
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_GL_INT_10_10_10_2          0xC
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_GL_UINT_10_10_10_2         0xD
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_INT8                       0xE
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_INT16                      0xF
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FORMAT_INT32                      0x8

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL                      5:4
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL_End                    5
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL_Start                  4
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL_Type                 U02
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL_NO_SWAP            0x0
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL_SWAP_WORD          0x1
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL_SWAP_DWORD         0x2
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_ENDIAN_CONTROL_SWAP_DDWORD        0x3

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_GENERIC                             6:6
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_GENERIC_End                           6
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_GENERIC_Start                         6
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_GENERIC_Type                        U01
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_GENERIC_DISABLE                   0x0
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_GENERIC_ENABLE                    0x1

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_BREAK                         7:7
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_BREAK_End                       7
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_BREAK_Start                     7
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_BREAK_Type                    U01
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_BREAK_DISABLE               0x0
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_BREAK_ENABLE                0x1

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_STREAM_ID                          11:8
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_STREAM_ID_End                        11
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_STREAM_ID_Start                       8
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_STREAM_ID_Type                      U04

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE                              13:12
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE_End                             13
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE_Start                           12
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE_Type                           U02
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE_FOUR_ELEMENTS                0x0
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE_ONE_ELEMENT                  0x1
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE_TWO_ELEMEMETS                0x2
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_SIZE_THREE_ELEMENTS               0x3

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_NORMALIZE                         15:14
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_NORMALIZE_End                        15
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_NORMALIZE_Start                      14
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_NORMALIZE_Type                      U02
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_NORMALIZE_DISABLE                 0x0
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_NORMALIZE_D3D                     0x1
#define   MWV207REG_FE_POS_ONLY_ATTRIBUTES_NORMALIZE_OES                     0x2

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_OFFSET                            23:16
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_OFFSET_End                           23
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_OFFSET_Start                         16
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_OFFSET_Type                         U08

#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_SIZE                        31:24
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_SIZE_End                       31
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_SIZE_Start                     24
#define MWV207REG_FE_POS_ONLY_ATTRIBUTES_FETCH_SIZE_Type                     U08




#define mwv207regFEPosOnlyStreamAddressRegAddrs                           0x5410
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_Address                     0x15040
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_MSB                              15
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_LSB                               4
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_BLK                               0
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_Count                            16
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_FieldMask                0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_ReadMask                 0xFFFFFFFC
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_WriteMask                0xFFFFFFFC
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_ResetValue               0x00000000

#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_TYPE                          31:31
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_TYPE_End                         31
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_TYPE_Start                       31
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_TYPE_Type                       U01
#define   MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_TYPE_SYSTEM                   0x0
#define   MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_TYPE_VIRTUAL_SYSTEM           0x1

#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_ADDRESS                        30:0
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_ADDRESS_End                      30
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_ADDRESS_Start                     0
#define MWV207REG_FE_POS_ONLY_STREAM_ADDRESS_ADDRESS_Type                    U31




#define mwv207regFEPosOnlyStreamStrideRegAddrs                            0x5420
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_Address                      0x15080
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_MSB                               15
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_LSB                                4
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_BLK                                0
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_Count                             16
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_FieldMask                 0x000081FF
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_ReadMask                  0x000081FF
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_WriteMask                 0x000081FF
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_ResetValue                0x00000000


#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_STRIDE                           8:0
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_STRIDE_End                         8
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_STRIDE_Start                       0
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_STRIDE_Type                      U09


#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_INSTANCE_MODE                  15:15
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_INSTANCE_MODE_End                 15
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_INSTANCE_MODE_Start               15
#define MWV207REG_FE_POS_ONLY_STREAM_STRIDE_INSTANCE_MODE_Type               U01
#define   MWV207REG_FE_POS_ONLY_STREAM_STRIDE_INSTANCE_MODE_PER_INSTANCE     0x0
#define   MWV207REG_FE_POS_ONLY_STREAM_STRIDE_INSTANCE_MODE_PER_VERTEX       0x1




#define mwv207regFEPosOnlyStreamDivisorRegAddrs                           0x5430
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_Address                     0x150C0
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_MSB                              15
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_LSB                               4
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_BLK                               0
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_Count                            16
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_FieldMask                0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_ReadMask                 0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_WriteMask                0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_ResetValue               0x00000000

#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_DIVISOR                        31:0
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_DIVISOR_End                      31
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_DIVISOR_Start                     0
#define MWV207REG_FE_POS_ONLY_STREAM_DIVISOR_DIVISOR_Type                    U32




#define mwv207regFEPosOnlyGenericsXRegAddrs                               0x5440
#define MWV207REG_FE_POS_ONLY_GENERICS_X_Address                         0x15100
#define MWV207REG_FE_POS_ONLY_GENERICS_X_MSB                                  15
#define MWV207REG_FE_POS_ONLY_GENERICS_X_LSB                                   4
#define MWV207REG_FE_POS_ONLY_GENERICS_X_BLK                                   0
#define MWV207REG_FE_POS_ONLY_GENERICS_X_Count                                16
#define MWV207REG_FE_POS_ONLY_GENERICS_X_FieldMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_X_ReadMask                     0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_X_WriteMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_X_ResetValue                   0x00000000


#define MWV207REG_FE_POS_ONLY_GENERICS_X_VALUE                              31:0
#define MWV207REG_FE_POS_ONLY_GENERICS_X_VALUE_End                            31
#define MWV207REG_FE_POS_ONLY_GENERICS_X_VALUE_Start                           0
#define MWV207REG_FE_POS_ONLY_GENERICS_X_VALUE_Type                          U32




#define mwv207regFEPosOnlyGenericsYRegAddrs                               0x5450
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_Address                         0x15140
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_MSB                                  15
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_LSB                                   4
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_BLK                                   0
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_Count                                16
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_FieldMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_ReadMask                     0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_WriteMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_ResetValue                   0x00000000


#define MWV207REG_FE_POS_ONLY_GENERICS_Y_VALUE                              31:0
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_VALUE_End                            31
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_VALUE_Start                           0
#define MWV207REG_FE_POS_ONLY_GENERICS_Y_VALUE_Type                          U32




#define mwv207regFEPosOnlyGenericsZRegAddrs                               0x5460
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_Address                         0x15180
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_MSB                                  15
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_LSB                                   4
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_BLK                                   0
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_Count                                16
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_FieldMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_ReadMask                     0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_WriteMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_ResetValue                   0x00000000


#define MWV207REG_FE_POS_ONLY_GENERICS_Z_VALUE                              31:0
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_VALUE_End                            31
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_VALUE_Start                           0
#define MWV207REG_FE_POS_ONLY_GENERICS_Z_VALUE_Type                          U32




#define mwv207regFEPosOnlyGenericsWRegAddrs                               0x5470
#define MWV207REG_FE_POS_ONLY_GENERICS_W_Address                         0x151C0
#define MWV207REG_FE_POS_ONLY_GENERICS_W_MSB                                  15
#define MWV207REG_FE_POS_ONLY_GENERICS_W_LSB                                   4
#define MWV207REG_FE_POS_ONLY_GENERICS_W_BLK                                   0
#define MWV207REG_FE_POS_ONLY_GENERICS_W_Count                                16
#define MWV207REG_FE_POS_ONLY_GENERICS_W_FieldMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_W_ReadMask                     0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_W_WriteMask                    0xFFFFFFFF
#define MWV207REG_FE_POS_ONLY_GENERICS_W_ResetValue                   0x3F800000


#define MWV207REG_FE_POS_ONLY_GENERICS_W_VALUE                              31:0
#define MWV207REG_FE_POS_ONLY_GENERICS_W_VALUE_End                            31
#define MWV207REG_FE_POS_ONLY_GENERICS_W_VALUE_Start                           0
#define MWV207REG_FE_POS_ONLY_GENERICS_W_VALUE_Type                          U32




#define mwv207regFEPosOnlyPackingRegAddrs                                 0x5480
#define MWV207REG_FE_POS_ONLY_PACKING_Address                            0x15200
#define MWV207REG_FE_POS_ONLY_PACKING_MSB                                     15
#define MWV207REG_FE_POS_ONLY_PACKING_LSB                                      4
#define MWV207REG_FE_POS_ONLY_PACKING_BLK                                      0
#define MWV207REG_FE_POS_ONLY_PACKING_Count                                   16
#define MWV207REG_FE_POS_ONLY_PACKING_FieldMask                       0x00000003
#define MWV207REG_FE_POS_ONLY_PACKING_ReadMask                        0x00000003
#define MWV207REG_FE_POS_ONLY_PACKING_WriteMask                       0x00000003
#define MWV207REG_FE_POS_ONLY_PACKING_ResetValue                      0x00000000


#define MWV207REG_FE_POS_ONLY_PACKING_COMPONENTS                             1:0
#define MWV207REG_FE_POS_ONLY_PACKING_COMPONENTS_End                           1
#define MWV207REG_FE_POS_ONLY_PACKING_COMPONENTS_Start                         0
#define MWV207REG_FE_POS_ONLY_PACKING_COMPONENTS_Type                        U02




#define ATTRI_FORMAT_ATTRI_FORMAT                                            4:0
#define ATTRI_FORMAT_ATTRI_FORMAT_End                                          4
#define ATTRI_FORMAT_ATTRI_FORMAT_Start                                        0
#define ATTRI_FORMAT_ATTRI_FORMAT_Type                                       U05

#define   ATTRI_FORMAT_ATTRI_FORMAT_BYTE                                    0x00

#define   ATTRI_FORMAT_ATTRI_FORMAT_UBYTE                                   0x01

#define   ATTRI_FORMAT_ATTRI_FORMAT_SHORT                                   0x02

#define   ATTRI_FORMAT_ATTRI_FORMAT_USHORT                                  0x03

#define   ATTRI_FORMAT_ATTRI_FORMAT_INT                                     0x04

#define   ATTRI_FORMAT_ATTRI_FORMAT_UINT                                    0x05

#define   ATTRI_FORMAT_ATTRI_FORMAT_DEC                                     0x06

#define   ATTRI_FORMAT_ATTRI_FORMAT_UDEC                                    0x07

#define   ATTRI_FORMAT_ATTRI_FORMAT_FLOAT                                   0x08

#define   ATTRI_FORMAT_ATTRI_FORMAT_FLOAT16                                 0x09
#define   ATTRI_FORMAT_ATTRI_FORMAT_COLOR                                   0x0A

#define   ATTRI_FORMAT_ATTRI_FORMAT_FIXED16_DOT16                           0x0B

#define   ATTRI_FORMAT_ATTRI_FORMAT_GL_INT_10_10_10_2                       0x0C

#define   ATTRI_FORMAT_ATTRI_FORMAT_GL_UINT_10_10_10_2                      0x0D

#define   ATTRI_FORMAT_ATTRI_FORMAT_INT8                                    0x0E

#define   ATTRI_FORMAT_ATTRI_FORMAT_INT16                                   0x0F

#define   ATTRI_FORMAT_ATTRI_FORMAT_INT32                                   0x08

#define   ATTRI_FORMAT_ATTRI_FORMAT_TRUE_INT32                              0x10


#endif


