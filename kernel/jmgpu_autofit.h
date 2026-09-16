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




#ifndef __jmgpureg3rdPartyCompression_h__
#define __jmgpureg3rdPartyCompression_h__


#define mwv207regTPCGeneralControlRegAddrs                                0x5320
#define MWV207REG_TPC_GENERAL_CONTROL_Address                            0x14C80
#define MWV207REG_TPC_GENERAL_CONTROL_MSB                                     15
#define MWV207REG_TPC_GENERAL_CONTROL_LSB                                      0
#define MWV207REG_TPC_GENERAL_CONTROL_BLK                                      0
#define MWV207REG_TPC_GENERAL_CONTROL_Count                                    1
#define MWV207REG_TPC_GENERAL_CONTROL_FieldMask                       0x00000001
#define MWV207REG_TPC_GENERAL_CONTROL_ReadMask                        0x00000001
#define MWV207REG_TPC_GENERAL_CONTROL_WriteMask                       0x00000001
#define MWV207REG_TPC_GENERAL_CONTROL_ResetValue                      0x00000000


#define MWV207REG_TPC_GENERAL_CONTROL_STREAM_CONTROL                         0:0
#define MWV207REG_TPC_GENERAL_CONTROL_STREAM_CONTROL_End                       0
#define MWV207REG_TPC_GENERAL_CONTROL_STREAM_CONTROL_Start                     0
#define MWV207REG_TPC_GENERAL_CONTROL_STREAM_CONTROL_Type                    U01
#define   MWV207REG_TPC_GENERAL_CONTROL_STREAM_CONTROL_BEGIN                 0x1
#define   MWV207REG_TPC_GENERAL_CONTROL_STREAM_CONTROL_END                   0x0

#define mwv207regTPCEncHdrAddrRegAddrs                                    0x5321
#define MWV207REG_TPC_ENC_HDR_ADDR_Address                               0x14C84
#define MWV207REG_TPC_ENC_HDR_ADDR_MSB                                        15
#define MWV207REG_TPC_ENC_HDR_ADDR_LSB                                         0
#define MWV207REG_TPC_ENC_HDR_ADDR_BLK                                         0
#define MWV207REG_TPC_ENC_HDR_ADDR_Count                                       1
#define MWV207REG_TPC_ENC_HDR_ADDR_FieldMask                          0xFFFFFFFF
#define MWV207REG_TPC_ENC_HDR_ADDR_ReadMask                           0xFFFFFFFF
#define MWV207REG_TPC_ENC_HDR_ADDR_WriteMask                          0xFFFFFFFF
#define MWV207REG_TPC_ENC_HDR_ADDR_ResetValue                         0x00000000


#define MWV207REG_TPC_ENC_HDR_ADDR_HDR_BASE                                 31:0
#define MWV207REG_TPC_ENC_HDR_ADDR_HDR_BASE_End                               31
#define MWV207REG_TPC_ENC_HDR_ADDR_HDR_BASE_Start                              0
#define MWV207REG_TPC_ENC_HDR_ADDR_HDR_BASE_Type                             U32

#define mwv207regTPCEncBodyAddrRegAddrs                                   0x5322
#define MWV207REG_TPC_ENC_BODY_ADDR_Address                              0x14C88
#define MWV207REG_TPC_ENC_BODY_ADDR_MSB                                       15
#define MWV207REG_TPC_ENC_BODY_ADDR_LSB                                        0
#define MWV207REG_TPC_ENC_BODY_ADDR_BLK                                        0
#define MWV207REG_TPC_ENC_BODY_ADDR_Count                                      1
#define MWV207REG_TPC_ENC_BODY_ADDR_FieldMask                         0xFFFFFFFF
#define MWV207REG_TPC_ENC_BODY_ADDR_ReadMask                          0xFFFFFFFF
#define MWV207REG_TPC_ENC_BODY_ADDR_WriteMask                         0xFFFFFFFF
#define MWV207REG_TPC_ENC_BODY_ADDR_ResetValue                        0x00000000


#define MWV207REG_TPC_ENC_BODY_ADDR_BODY_BASE                               31:0
#define MWV207REG_TPC_ENC_BODY_ADDR_BODY_BASE_End                             31
#define MWV207REG_TPC_ENC_BODY_ADDR_BODY_BASE_Start                            0
#define MWV207REG_TPC_ENC_BODY_ADDR_BODY_BASE_Type                           U32

#define mwv207regTPCEncFormatRegAddrs                                     0x5323
#define MWV207REG_TPC_ENC_FORMAT_Address                                 0x14C8C
#define MWV207REG_TPC_ENC_FORMAT_MSB                                          15
#define MWV207REG_TPC_ENC_FORMAT_LSB                                           0
#define MWV207REG_TPC_ENC_FORMAT_BLK                                           0
#define MWV207REG_TPC_ENC_FORMAT_Count                                         1
#define MWV207REG_TPC_ENC_FORMAT_FieldMask                            0x0000033F
#define MWV207REG_TPC_ENC_FORMAT_ReadMask                             0x0000033F
#define MWV207REG_TPC_ENC_FORMAT_WriteMask                            0x0000033F
#define MWV207REG_TPC_ENC_FORMAT_ResetValue                           0x00000015

#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_OP                                9:9
#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_OP_End                              9
#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_OP_Start                            9
#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_OP_Type                           U01


#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_DIS                               8:8
#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_DIS_End                             8
#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_DIS_Start                           8
#define MWV207REG_TPC_ENC_FORMAT_COPY_MODE_DIS_Type                          U01


#define MWV207REG_TPC_ENC_FORMAT_BLK_SHAPE                                   5:5
#define MWV207REG_TPC_ENC_FORMAT_BLK_SHAPE_End                                 5
#define MWV207REG_TPC_ENC_FORMAT_BLK_SHAPE_Start                               5
#define MWV207REG_TPC_ENC_FORMAT_BLK_SHAPE_Type                              U01

#define MWV207REG_TPC_ENC_FORMAT_YUV_TRANSFORM                               4:4
#define MWV207REG_TPC_ENC_FORMAT_YUV_TRANSFORM_End                             4
#define MWV207REG_TPC_ENC_FORMAT_YUV_TRANSFORM_Start                           4
#define MWV207REG_TPC_ENC_FORMAT_YUV_TRANSFORM_Type                          U01

#define MWV207REG_TPC_ENC_FORMAT_FMT_IDX                                     3:0
#define MWV207REG_TPC_ENC_FORMAT_FMT_IDX_End                                   3
#define MWV207REG_TPC_ENC_FORMAT_FMT_IDX_Start                                 0
#define MWV207REG_TPC_ENC_FORMAT_FMT_IDX_Type                                U04
#define   MWV207REG_TPC_ENC_FORMAT_FMT_IDX_R10G10B10A2                       0x2
#define   MWV207REG_TPC_ENC_FORMAT_FMT_IDX_YUV420_10BIT                      0x3
#define   MWV207REG_TPC_ENC_FORMAT_FMT_IDX_R8G8B8A8                          0x5
#define   MWV207REG_TPC_ENC_FORMAT_FMT_IDX_YUV420_8BIT                       0x9

#define mwv207regTPCEncSizeRegAddrs                                       0x5324
#define MWV207REG_TPC_ENC_SIZE_Address                                   0x14C90
#define MWV207REG_TPC_ENC_SIZE_MSB                                            15
#define MWV207REG_TPC_ENC_SIZE_LSB                                             0
#define MWV207REG_TPC_ENC_SIZE_BLK                                             0
#define MWV207REG_TPC_ENC_SIZE_Count                                           1
#define MWV207REG_TPC_ENC_SIZE_FieldMask                              0x0FFF1FFF
#define MWV207REG_TPC_ENC_SIZE_ReadMask                               0x0FFF1FFF
#define MWV207REG_TPC_ENC_SIZE_WriteMask                              0x0FFF1FFF
#define MWV207REG_TPC_ENC_SIZE_ResetValue                             0x00000000


#define MWV207REG_TPC_ENC_SIZE_PIC_HEIGHT                                  27:16
#define MWV207REG_TPC_ENC_SIZE_PIC_HEIGHT_End                                 27
#define MWV207REG_TPC_ENC_SIZE_PIC_HEIGHT_Start                               16
#define MWV207REG_TPC_ENC_SIZE_PIC_HEIGHT_Type                               U12


#define MWV207REG_TPC_ENC_SIZE_PIC_WIDTH                                    12:0
#define MWV207REG_TPC_ENC_SIZE_PIC_WIDTH_End                                  12
#define MWV207REG_TPC_ENC_SIZE_PIC_WIDTH_Start                                 0
#define MWV207REG_TPC_ENC_SIZE_PIC_WIDTH_Type                                U13

#define mwv207regTPCEncConfRegAddrs                                       0x5325
#define MWV207REG_TPC_ENC_CONF_Address                                   0x14C94
#define MWV207REG_TPC_ENC_CONF_MSB                                            15
#define MWV207REG_TPC_ENC_CONF_LSB                                             0
#define MWV207REG_TPC_ENC_CONF_BLK                                             0
#define MWV207REG_TPC_ENC_CONF_Count                                           1
#define MWV207REG_TPC_ENC_CONF_FieldMask                              0x00000011
#define MWV207REG_TPC_ENC_CONF_ReadMask                               0x00000011
#define MWV207REG_TPC_ENC_CONF_WriteMask                              0x00000011
#define MWV207REG_TPC_ENC_CONF_ResetValue                             0x00000000

#define MWV207REG_TPC_ENC_CONF_INT_USE_INIT                                  4:4
#define MWV207REG_TPC_ENC_CONF_INT_USE_INIT_End                                4
#define MWV207REG_TPC_ENC_CONF_INT_USE_INIT_Start                              4
#define MWV207REG_TPC_ENC_CONF_INT_USE_INIT_Type                             U01

#define MWV207REG_TPC_ENC_CONF_ENC_INIT                                      0:0
#define MWV207REG_TPC_ENC_CONF_ENC_INIT_End                                    0
#define MWV207REG_TPC_ENC_CONF_ENC_INIT_Start                                  0
#define MWV207REG_TPC_ENC_CONF_ENC_INIT_Type                                 U01

#define mwv207regTPCDecConfigRegAddrs                                     0x5326
#define MWV207REG_TPC_DEC_CONFIG_Address                                 0x14C98
#define MWV207REG_TPC_DEC_CONFIG_MSB                                          15
#define MWV207REG_TPC_DEC_CONFIG_LSB                                           0
#define MWV207REG_TPC_DEC_CONFIG_BLK                                           0
#define MWV207REG_TPC_DEC_CONFIG_Count                                         1
#define MWV207REG_TPC_DEC_CONFIG_FieldMask                            0x00000111
#define MWV207REG_TPC_DEC_CONFIG_ReadMask                             0x00000111
#define MWV207REG_TPC_DEC_CONFIG_WriteMask                            0x00000111
#define MWV207REG_TPC_DEC_CONFIG_ResetValue                           0x00000000


#define MWV207REG_TPC_DEC_CONFIG_RGBA_YBURST_MODE                            8:8
#define MWV207REG_TPC_DEC_CONFIG_RGBA_YBURST_MODE_End                          8
#define MWV207REG_TPC_DEC_CONFIG_RGBA_YBURST_MODE_Start                        8
#define MWV207REG_TPC_DEC_CONFIG_RGBA_YBURST_MODE_Type                       U01


#define MWV207REG_TPC_DEC_CONFIG_SURFACE_ID_MODE                             4:4
#define MWV207REG_TPC_DEC_CONFIG_SURFACE_ID_MODE_End                           4
#define MWV207REG_TPC_DEC_CONFIG_SURFACE_ID_MODE_Start                         4
#define MWV207REG_TPC_DEC_CONFIG_SURFACE_ID_MODE_Type                        U01

#define MWV207REG_TPC_DEC_CONFIG_HDR_PREFETCH_EN                             0:0
#define MWV207REG_TPC_DEC_CONFIG_HDR_PREFETCH_EN_End                           0
#define MWV207REG_TPC_DEC_CONFIG_HDR_PREFETCH_EN_Start                         0
#define MWV207REG_TPC_DEC_CONFIG_HDR_PREFETCH_EN_Type                        U01

#define mwv207regTPCSurfaceCfgRegAddrs                                    0x5327
#define MWV207REG_TPC_SURFACE_CFG_Address                                0x14C9C
#define MWV207REG_TPC_SURFACE_CFG_MSB                                         15
#define MWV207REG_TPC_SURFACE_CFG_LSB                                          0
#define MWV207REG_TPC_SURFACE_CFG_BLK                                          0
#define MWV207REG_TPC_SURFACE_CFG_Count                                        1
#define MWV207REG_TPC_SURFACE_CFG_FieldMask                           0x000001FF
#define MWV207REG_TPC_SURFACE_CFG_ReadMask                            0x000001FF
#define MWV207REG_TPC_SURFACE_CFG_WriteMask                           0x000001FF
#define MWV207REG_TPC_SURFACE_CFG_ResetValue                          0x00000000


#define MWV207REG_TPC_SURFACE_CFG_SURFACE8_EN                                8:8
#define MWV207REG_TPC_SURFACE_CFG_SURFACE8_EN_End                              8
#define MWV207REG_TPC_SURFACE_CFG_SURFACE8_EN_Start                            8
#define MWV207REG_TPC_SURFACE_CFG_SURFACE8_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE7_EN                                7:7
#define MWV207REG_TPC_SURFACE_CFG_SURFACE7_EN_End                              7
#define MWV207REG_TPC_SURFACE_CFG_SURFACE7_EN_Start                            7
#define MWV207REG_TPC_SURFACE_CFG_SURFACE7_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE6_EN                                6:6
#define MWV207REG_TPC_SURFACE_CFG_SURFACE6_EN_End                              6
#define MWV207REG_TPC_SURFACE_CFG_SURFACE6_EN_Start                            6
#define MWV207REG_TPC_SURFACE_CFG_SURFACE6_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE5_EN                                5:5
#define MWV207REG_TPC_SURFACE_CFG_SURFACE5_EN_End                              5
#define MWV207REG_TPC_SURFACE_CFG_SURFACE5_EN_Start                            5
#define MWV207REG_TPC_SURFACE_CFG_SURFACE5_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE4_EN                                4:4
#define MWV207REG_TPC_SURFACE_CFG_SURFACE4_EN_End                              4
#define MWV207REG_TPC_SURFACE_CFG_SURFACE4_EN_Start                            4
#define MWV207REG_TPC_SURFACE_CFG_SURFACE4_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE3_EN                                3:3
#define MWV207REG_TPC_SURFACE_CFG_SURFACE3_EN_End                              3
#define MWV207REG_TPC_SURFACE_CFG_SURFACE3_EN_Start                            3
#define MWV207REG_TPC_SURFACE_CFG_SURFACE3_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE2_EN                                2:2
#define MWV207REG_TPC_SURFACE_CFG_SURFACE2_EN_End                              2
#define MWV207REG_TPC_SURFACE_CFG_SURFACE2_EN_Start                            2
#define MWV207REG_TPC_SURFACE_CFG_SURFACE2_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE1_EN                                1:1
#define MWV207REG_TPC_SURFACE_CFG_SURFACE1_EN_End                              1
#define MWV207REG_TPC_SURFACE_CFG_SURFACE1_EN_Start                            1
#define MWV207REG_TPC_SURFACE_CFG_SURFACE1_EN_Type                           U01


#define MWV207REG_TPC_SURFACE_CFG_SURFACE0_EN                                0:0
#define MWV207REG_TPC_SURFACE_CFG_SURFACE0_EN_End                              0
#define MWV207REG_TPC_SURFACE_CFG_SURFACE0_EN_Start                            0
#define MWV207REG_TPC_SURFACE_CFG_SURFACE0_EN_Type                           U01

#define mwv207regTPCDecHostInitRegAddrs                                   0x5328
#define MWV207REG_TPC_DEC_HOST_INIT_Address                              0x14CA0
#define MWV207REG_TPC_DEC_HOST_INIT_MSB                                       15
#define MWV207REG_TPC_DEC_HOST_INIT_LSB                                        0
#define MWV207REG_TPC_DEC_HOST_INIT_BLK                                        0
#define MWV207REG_TPC_DEC_HOST_INIT_Count                                      1
#define MWV207REG_TPC_DEC_HOST_INIT_FieldMask                         0x00000001
#define MWV207REG_TPC_DEC_HOST_INIT_ReadMask                          0x00000001
#define MWV207REG_TPC_DEC_HOST_INIT_WriteMask                         0x00000001
#define MWV207REG_TPC_DEC_HOST_INIT_ResetValue                        0x00000000

#define MWV207REG_TPC_DEC_HOST_INIT_AFBC_DEC_INIT                            0:0
#define MWV207REG_TPC_DEC_HOST_INIT_AFBC_DEC_INIT_End                          0
#define MWV207REG_TPC_DEC_HOST_INIT_AFBC_DEC_INIT_Start                        0
#define MWV207REG_TPC_DEC_HOST_INIT_AFBC_DEC_INIT_Type                       U01

#define mwv207regTPCSurface0HdrAddrRegAddrs                               0x5329
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_Address                          0x14CA4
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE0_HDR_ADDR_SURFACE0_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_SURFACE0_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_SURFACE0_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE0_HDR_ADDR_SURFACE0_HDR_ADDR_Type               U32

#define mwv207regTPCSurface0FormatRegAddrs                                0x532A
#define MWV207REG_TPC_SURFACE0_FORMAT_Address                            0x14CA8
#define MWV207REG_TPC_SURFACE0_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE0_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE0_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE0_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE0_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE0_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE0_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE0_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE0_FORMAT_SURFACE0_PXL_FORMAT_R10G10B10A2      0x3

#define mwv207regTPCSurface1HdrAddrRegAddrs                               0x532B
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_Address                          0x14CAC
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE1_HDR_ADDR_SURFACE1_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_SURFACE1_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_SURFACE1_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE1_HDR_ADDR_SURFACE1_HDR_ADDR_Type               U32

#define mwv207regTPCSurface1FormatRegAddrs                                0x532C
#define MWV207REG_TPC_SURFACE1_FORMAT_Address                            0x14CB0
#define MWV207REG_TPC_SURFACE1_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE1_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE1_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE1_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE1_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE1_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE1_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE1_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE1_FORMAT_SURFACE1_PXL_FORMAT_R10G10B10A2      0x3

#define mwv207regTPCSurface2HdrAddrRegAddrs                               0x532D
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_Address                          0x14CB4
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE2_HDR_ADDR_SURFACE2_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_SURFACE2_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_SURFACE2_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE2_HDR_ADDR_SURFACE2_HDR_ADDR_Type               U32

#define mwv207regTPCSurface2FormatRegAddrs                                0x532E
#define MWV207REG_TPC_SURFACE2_FORMAT_Address                            0x14CB8
#define MWV207REG_TPC_SURFACE2_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE2_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE2_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE2_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE2_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE2_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE2_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE2_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE2_FORMAT_SURFACE2_PXL_FORMAT_Type               U02

#define mwv207regTPCSurface3HdrAddrRegAddrs                               0x532F
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_Address                          0x14CBC
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE3_HDR_ADDR_SURFACE3_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_SURFACE3_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_SURFACE3_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE3_HDR_ADDR_SURFACE3_HDR_ADDR_Type               U32

#define mwv207regTPCSurface3FormatRegAddrs                                0x5330
#define MWV207REG_TPC_SURFACE3_FORMAT_Address                            0x14CC0
#define MWV207REG_TPC_SURFACE3_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE3_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE3_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE3_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE3_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE3_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE3_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE3_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE3_FORMAT_SURFACE3_PXL_FORMAT_R10G10B10A2      0x3

#define mwv207regTPCSurface4HdrAddrRegAddrs                               0x5331
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_Address                          0x14CC4
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE4_HDR_ADDR_SURFACE4_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_SURFACE4_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_SURFACE4_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE4_HDR_ADDR_SURFACE4_HDR_ADDR_Type               U32

#define mwv207regTPCSurface4FormatRegAddrs                                0x5332
#define MWV207REG_TPC_SURFACE4_FORMAT_Address                            0x14CC8
#define MWV207REG_TPC_SURFACE4_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE4_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE4_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE4_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE4_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE4_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE4_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE4_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE4_FORMAT_SURFACE4_PXL_FORMAT_R10G10B10A2      0x3

#define mwv207regTPCSurface5HdrAddrRegAddrs                               0x5333
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_Address                          0x14CCC
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE5_HDR_ADDR_SURFACE5_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_SURFACE5_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_SURFACE5_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE5_HDR_ADDR_SURFACE5_HDR_ADDR_Type               U32

#define mwv207regTPCSurface5FormatRegAddrs                                0x5334
#define MWV207REG_TPC_SURFACE5_FORMAT_Address                            0x14CD0
#define MWV207REG_TPC_SURFACE5_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE5_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE5_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE5_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE5_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE5_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE5_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE5_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE5_FORMAT_SURFACE5_PXL_FORMAT_R10G10B10A2      0x3

#define mwv207regTPCSurface6HdrAddrRegAddrs                               0x5335
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_Address                          0x14CD4
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE6_HDR_ADDR_SURFACE6_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_SURFACE6_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_SURFACE6_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE6_HDR_ADDR_SURFACE6_HDR_ADDR_Type               U32

#define mwv207regTPCSurface6FormatRegAddrs                                0x5336
#define MWV207REG_TPC_SURFACE6_FORMAT_Address                            0x14CD8
#define MWV207REG_TPC_SURFACE6_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE6_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE6_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE6_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE6_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE6_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE6_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE6_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE6_FORMAT_SURFACE6_PXL_FORMAT_R10G10B10A2      0x3

#define mwv207regTPCSurface7HdrAddrRegAddrs                               0x5337
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_Address                          0x14CDC
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE7_HDR_ADDR_SURFACE7_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_SURFACE7_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_SURFACE7_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE7_HDR_ADDR_SURFACE7_HDR_ADDR_Type               U32

#define mwv207regTPCSurface7FormatRegAddrs                                0x5338
#define MWV207REG_TPC_SURFACE7_FORMAT_Address                            0x14CE0
#define MWV207REG_TPC_SURFACE7_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE7_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE7_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE7_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE7_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE7_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE7_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE7_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE7_FORMAT_SURFACE7_PXL_FORMAT_R10G10B10A2      0x3

#define mwv207regTPCSurface8HdrAddrRegAddrs                               0x5339
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_Address                          0x14CE4
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_MSB                                   15
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_LSB                                    0
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_BLK                                    0
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_Count                                  1
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_FieldMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_ReadMask                      0xFFFFFFFF
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_WriteMask                     0xFFFFFFFF
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_ResetValue                    0x00000000


#define MWV207REG_TPC_SURFACE8_HDR_ADDR_SURFACE8_HDR_ADDR                   31:0
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_SURFACE8_HDR_ADDR_End                 31
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_SURFACE8_HDR_ADDR_Start                0
#define MWV207REG_TPC_SURFACE8_HDR_ADDR_SURFACE8_HDR_ADDR_Type               U32

#define mwv207regTPCSurface8FormatRegAddrs                                0x533A
#define MWV207REG_TPC_SURFACE8_FORMAT_Address                            0x14CE8
#define MWV207REG_TPC_SURFACE8_FORMAT_MSB                                     15
#define MWV207REG_TPC_SURFACE8_FORMAT_LSB                                      0
#define MWV207REG_TPC_SURFACE8_FORMAT_BLK                                      0
#define MWV207REG_TPC_SURFACE8_FORMAT_Count                                    1
#define MWV207REG_TPC_SURFACE8_FORMAT_FieldMask                       0x00000303
#define MWV207REG_TPC_SURFACE8_FORMAT_ReadMask                        0x00000303
#define MWV207REG_TPC_SURFACE8_FORMAT_WriteMask                       0x00000303
#define MWV207REG_TPC_SURFACE8_FORMAT_ResetValue                      0x00000200


#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_BLK_SHAPE                     9:9
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_BLK_SHAPE_End                   9
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_BLK_SHAPE_Start                 9
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_BLK_SHAPE_Type                U01

#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_TRANSFORM_EN                  8:8
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_TRANSFORM_EN_End                8
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_TRANSFORM_EN_Start              8
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_TRANSFORM_EN_Type             U01

#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT                    1:0
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT_End                  1
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT_Start                0
#define MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT_Type               U02
#define   MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT_YUV420_8BIT      0x0
#define   MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT_R8G8B8A8         0x1
#define   MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT_YUV420_10BIT     0x2
#define   MWV207REG_TPC_SURFACE8_FORMAT_SURFACE8_PXL_FORMAT_R10G10B10A2      0x3


#endif


