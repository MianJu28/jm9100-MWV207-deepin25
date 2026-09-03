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




#ifndef __AQCommon_h__
#define __AQCommon_h__





#define AQPipeSelectRegAddrs                                              0x0E00
#define AQ_PIPE_SELECT_Address                                           0x03800
#define AQ_PIPE_SELECT_MSB                                                    15
#define AQ_PIPE_SELECT_LSB                                                     0
#define AQ_PIPE_SELECT_BLK                                                     0
#define AQ_PIPE_SELECT_Count                                                   1
#define AQ_PIPE_SELECT_FieldMask                                      0x00000001
#define AQ_PIPE_SELECT_ReadMask                                       0x00000001
#define AQ_PIPE_SELECT_WriteMask                                      0x00000001
#define AQ_PIPE_SELECT_ResetValue                                     0x00000000

#define AQ_PIPE_SELECT_PIPE                                                  0:0
#define AQ_PIPE_SELECT_PIPE_End                                                0
#define AQ_PIPE_SELECT_PIPE_Start                                              0
#define AQ_PIPE_SELECT_PIPE_Type                                             U01
#define   AQ_PIPE_SELECT_PIPE_PIPE3D                                         0x0
#define   AQ_PIPE_SELECT_PIPE_PIPE2D                                         0x1




#define AQEventRegAddrs                                                   0x0E01
#define AQ_EVENT_Address                                                 0x03804
#define AQ_EVENT_MSB                                                          15
#define AQ_EVENT_LSB                                                           0
#define AQ_EVENT_BLK                                                           0
#define AQ_EVENT_Count                                                         1
#define AQ_EVENT_FieldMask                                            0x000000FF
#define AQ_EVENT_ReadMask                                             0x000000FF
#define AQ_EVENT_WriteMask                                            0x000000FF
#define AQ_EVENT_ResetValue                                           0x00000000


#define AQ_EVENT_EVENT_ID                                                    4:0
#define AQ_EVENT_EVENT_ID_End                                                  4
#define AQ_EVENT_EVENT_ID_Start                                                0
#define AQ_EVENT_EVENT_ID_Type                                               U05


#define AQ_EVENT_FE_SRC                                                      5:5
#define AQ_EVENT_FE_SRC_End                                                    5
#define AQ_EVENT_FE_SRC_Start                                                  5
#define AQ_EVENT_FE_SRC_Type                                                 U01
#define   AQ_EVENT_FE_SRC_DISABLE                                            0x0
#define   AQ_EVENT_FE_SRC_ENABLE                                             0x1


#define AQ_EVENT_PE_SRC                                                      6:6
#define AQ_EVENT_PE_SRC_End                                                    6
#define AQ_EVENT_PE_SRC_Start                                                  6
#define AQ_EVENT_PE_SRC_Type                                                 U01
#define   AQ_EVENT_PE_SRC_DISABLE                                            0x0
#define   AQ_EVENT_PE_SRC_ENABLE                                             0x1


#define AQ_EVENT_BLT_SRC                                                     7:7
#define AQ_EVENT_BLT_SRC_End                                                   7
#define AQ_EVENT_BLT_SRC_Start                                                 7
#define AQ_EVENT_BLT_SRC_Type                                                U01
#define   AQ_EVENT_BLT_SRC_DISABLE                                           0x0
#define   AQ_EVENT_BLT_SRC_ENABLE                                            0x1



#define AQSemaphoreRegAddrs                                               0x0E02
#define AQ_SEMAPHORE_Address                                             0x03808
#define AQ_SEMAPHORE_MSB                                                      15
#define AQ_SEMAPHORE_LSB                                                       0
#define AQ_SEMAPHORE_BLK                                                       0
#define AQ_SEMAPHORE_Count                                                     1
#define AQ_SEMAPHORE_FieldMask                                        0x3FFF1F1F
#define AQ_SEMAPHORE_ReadMask                                         0x3FFF1F1F
#define AQ_SEMAPHORE_WriteMask                                        0x3FFF1F1F
#define AQ_SEMAPHORE_ResetValue                                       0x00000000

#define AQ_SEMAPHORE_SOURCE                                                  4:0
#define AQ_SEMAPHORE_SOURCE_End                                                4
#define AQ_SEMAPHORE_SOURCE_Start                                              0
#define AQ_SEMAPHORE_SOURCE_Type                                             U05
#define   AQ_SEMAPHORE_SOURCE_FRONT_END                                     0x01
#define   AQ_SEMAPHORE_SOURCE_VERTEX_SHADER                                 0x02
#define   AQ_SEMAPHORE_SOURCE_PRIMITIVE_ASSEMBLY                            0x03
#define   AQ_SEMAPHORE_SOURCE_SETUP                                         0x04
#define   AQ_SEMAPHORE_SOURCE_RASTERIZER                                    0x05
#define   AQ_SEMAPHORE_SOURCE_PIXEL_SHADER                                  0x06
#define   AQ_SEMAPHORE_SOURCE_PIXEL_ENGINE                                  0x07
#define   AQ_SEMAPHORE_SOURCE_MEMORY_CONTROLLER                             0x08
#define   AQ_SEMAPHORE_SOURCE_DISPLAY_CONTROLLER0                           0x09
#define   AQ_SEMAPHORE_SOURCE_DISPLAY_CONTROLLER1                           0x0A
#define   AQ_SEMAPHORE_SOURCE_DRAWING_ENGINE                                0x0B
#define   AQ_SEMAPHORE_SOURCE_EVENT                                         0x0C
#define   AQ_SEMAPHORE_SOURCE_RESOLVE                                       0x0D
#define   AQ_SEMAPHORE_SOURCE_CHIP_ID                                       0x0F
#define   AQ_SEMAPHORE_SOURCE_BLT_ENGINE                                    0x10

#define AQ_SEMAPHORE_DESTINATION                                            12:8
#define AQ_SEMAPHORE_DESTINATION_End                                          12
#define AQ_SEMAPHORE_DESTINATION_Start                                         8
#define AQ_SEMAPHORE_DESTINATION_Type                                        U05
#define   AQ_SEMAPHORE_DESTINATION_FRONT_END                                0x01
#define   AQ_SEMAPHORE_DESTINATION_VERTEX_SHADER                            0x02
#define   AQ_SEMAPHORE_DESTINATION_PRIMITIVE_ASSEMBLY                       0x03
#define   AQ_SEMAPHORE_DESTINATION_SETUP                                    0x04
#define   AQ_SEMAPHORE_DESTINATION_RASTERIZER                               0x05
#define   AQ_SEMAPHORE_DESTINATION_PIXEL_SHADER                             0x06
#define   AQ_SEMAPHORE_DESTINATION_PIXEL_ENGINE                             0x07
#define   AQ_SEMAPHORE_DESTINATION_MEMORY_CONTROLLER                        0x08
#define   AQ_SEMAPHORE_DESTINATION_DISPLAY_CONTROLLER0                      0x09
#define   AQ_SEMAPHORE_DESTINATION_DISPLAY_CONTROLLER1                      0x0A
#define   AQ_SEMAPHORE_DESTINATION_DRAWING_ENGINE                           0x0B
#define   AQ_SEMAPHORE_DESTINATION_EVENT                                    0x0C
#define   AQ_SEMAPHORE_DESTINATION_RESOLVE                                  0x0D
#define   AQ_SEMAPHORE_DESTINATION_CHIP_ID                                  0x0F
#define   AQ_SEMAPHORE_DESTINATION_BLT_ENGINE                               0x10

#define AQ_SEMAPHORE_SOURCE_ID                                             23:20
#define AQ_SEMAPHORE_SOURCE_ID_End                                            23
#define AQ_SEMAPHORE_SOURCE_ID_Start                                          20
#define AQ_SEMAPHORE_SOURCE_ID_Type                                          U04

#define AQ_SEMAPHORE_DESTINATION_ID                                        27:24
#define AQ_SEMAPHORE_DESTINATION_ID_End                                       27
#define AQ_SEMAPHORE_DESTINATION_ID_Start                                     24
#define AQ_SEMAPHORE_DESTINATION_ID_Type                                     U04

#define AQ_SEMAPHORE_ID                                                    19:16
#define AQ_SEMAPHORE_ID_End                                                   19
#define AQ_SEMAPHORE_ID_Start                                                 16
#define AQ_SEMAPHORE_ID_Type                                                 U04

#define AQ_SEMAPHORE_FRONT_END                                             29:28
#define AQ_SEMAPHORE_FRONT_END_End                                            29
#define AQ_SEMAPHORE_FRONT_END_Start                                          28
#define AQ_SEMAPHORE_FRONT_END_Type                                          U02
#define   AQ_SEMAPHORE_FRONT_END_COMMAND                                     0x0
#define   AQ_SEMAPHORE_FRONT_END_INDEX                                       0x1
#define   AQ_SEMAPHORE_FRONT_END_VERTEX                                      0x2
#define   AQ_SEMAPHORE_FRONT_END_PREFETCH                                    0x3




#define AQFlushRegAddrs                                                   0x0E03
#define AQ_FLUSH_Address                                                 0x0380C
#define AQ_FLUSH_MSB                                                          15
#define AQ_FLUSH_LSB                                                           0
#define AQ_FLUSH_BLK                                                           0
#define AQ_FLUSH_Count                                                         1
#define AQ_FLUSH_FieldMask                                            0x0000FF7F
#define AQ_FLUSH_ReadMask                                             0x0000FF7F
#define AQ_FLUSH_WriteMask                                            0x0000FF7F
#define AQ_FLUSH_ResetValue                                           0x00000000


#define AQ_FLUSH_ZCACHE                                                      0:0
#define AQ_FLUSH_ZCACHE_End                                                    0
#define AQ_FLUSH_ZCACHE_Start                                                  0
#define AQ_FLUSH_ZCACHE_Type                                                 U01
#define   AQ_FLUSH_ZCACHE_DISABLE                                            0x0
#define   AQ_FLUSH_ZCACHE_ENABLE                                             0x1


#define AQ_FLUSH_CCACHE                                                      1:1
#define AQ_FLUSH_CCACHE_End                                                    1
#define AQ_FLUSH_CCACHE_Start                                                  1
#define AQ_FLUSH_CCACHE_Type                                                 U01
#define   AQ_FLUSH_CCACHE_DISABLE                                            0x0
#define   AQ_FLUSH_CCACHE_ENABLE                                             0x1

#define AQ_FLUSH_TCACHE                                                      2:2
#define AQ_FLUSH_TCACHE_End                                                    2
#define AQ_FLUSH_TCACHE_Start                                                  2
#define AQ_FLUSH_TCACHE_Type                                                 U01
#define   AQ_FLUSH_TCACHE_DISABLE                                            0x0
#define   AQ_FLUSH_TCACHE_ENABLE                                             0x1


#define AQ_FLUSH_PE2D_CACHE                                                  3:3
#define AQ_FLUSH_PE2D_CACHE_End                                                3
#define AQ_FLUSH_PE2D_CACHE_Start                                              3
#define AQ_FLUSH_PE2D_CACHE_Type                                             U01
#define   AQ_FLUSH_PE2D_CACHE_DISABLE                                        0x0
#define   AQ_FLUSH_PE2D_CACHE_ENABLE                                         0x1

#define AQ_FLUSH_VST_CACHE                                                   4:4
#define AQ_FLUSH_VST_CACHE_End                                                 4
#define AQ_FLUSH_VST_CACHE_Start                                               4
#define AQ_FLUSH_VST_CACHE_Type                                              U01
#define   AQ_FLUSH_VST_CACHE_DISABLE                                         0x0
#define   AQ_FLUSH_VST_CACHE_ENABLE                                          0x1


#define AQ_FLUSH_SHL1_CACHE                                                  5:5
#define AQ_FLUSH_SHL1_CACHE_End                                                5
#define AQ_FLUSH_SHL1_CACHE_Start                                              5
#define AQ_FLUSH_SHL1_CACHE_Type                                             U01
#define   AQ_FLUSH_SHL1_CACHE_DISABLE                                        0x0
#define   AQ_FLUSH_SHL1_CACHE_ENABLE                                         0x1


#define AQ_FLUSH_L2_CACHE                                                    6:6
#define AQ_FLUSH_L2_CACHE_End                                                  6
#define AQ_FLUSH_L2_CACHE_Start                                                6
#define AQ_FLUSH_L2_CACHE_Type                                               U01
#define   AQ_FLUSH_L2_CACHE_DISABLE                                          0x0
#define   AQ_FLUSH_L2_CACHE_ENABLE                                           0x1


#define AQ_FLUSH_ZCACHE_INVALIDATE                                           8:8
#define AQ_FLUSH_ZCACHE_INVALIDATE_End                                         8
#define AQ_FLUSH_ZCACHE_INVALIDATE_Start                                       8
#define AQ_FLUSH_ZCACHE_INVALIDATE_Type                                      U01


#define AQ_FLUSH_BLT3_DCACHE                                                 9:9
#define AQ_FLUSH_BLT3_DCACHE_End                                               9
#define AQ_FLUSH_BLT3_DCACHE_Start                                             9
#define AQ_FLUSH_BLT3_DCACHE_Type                                            U01
#define   AQ_FLUSH_BLT3_DCACHE_DISABLE                                       0x0
#define   AQ_FLUSH_BLT3_DCACHE_ENABLE                                        0x1


#define AQ_FLUSH_VSSHL1_CACHE                                              10:10
#define AQ_FLUSH_VSSHL1_CACHE_End                                             10
#define AQ_FLUSH_VSSHL1_CACHE_Start                                           10
#define AQ_FLUSH_VSSHL1_CACHE_Type                                           U01
#define   AQ_FLUSH_VSSHL1_CACHE_DISABLE                                      0x0
#define   AQ_FLUSH_VSSHL1_CACHE_ENABLE                                       0x1


#define AQ_FLUSH_PSSHL1_CACHE                                              11:11
#define AQ_FLUSH_PSSHL1_CACHE_End                                             11
#define AQ_FLUSH_PSSHL1_CACHE_Start                                           11
#define AQ_FLUSH_PSSHL1_CACHE_Type                                           U01
#define   AQ_FLUSH_PSSHL1_CACHE_DISABLE                                      0x0
#define   AQ_FLUSH_PSSHL1_CACHE_ENABLE                                       0x1


#define AQ_FLUSH_TL1_CACHE                                                 12:12
#define AQ_FLUSH_TL1_CACHE_End                                                12
#define AQ_FLUSH_TL1_CACHE_Start                                              12
#define AQ_FLUSH_TL1_CACHE_Type                                              U01
#define   AQ_FLUSH_TL1_CACHE_DISABLE                                         0x0
#define   AQ_FLUSH_TL1_CACHE_ENABLE                                          0x1


#define AQ_FLUSH_GPIPE_TL1_CACHE                                           13:13
#define AQ_FLUSH_GPIPE_TL1_CACHE_End                                          13
#define AQ_FLUSH_GPIPE_TL1_CACHE_Start                                        13
#define AQ_FLUSH_GPIPE_TL1_CACHE_Type                                        U01
#define   AQ_FLUSH_GPIPE_TL1_CACHE_DISABLE                                   0x0
#define   AQ_FLUSH_GPIPE_TL1_CACHE_ENABLE                                    0x1


#define AQ_FLUSH_VERTEX_DATA_CACHE                                         14:14
#define AQ_FLUSH_VERTEX_DATA_CACHE_End                                        14
#define AQ_FLUSH_VERTEX_DATA_CACHE_Start                                      14
#define AQ_FLUSH_VERTEX_DATA_CACHE_Type                                      U01
#define   AQ_FLUSH_VERTEX_DATA_CACHE_DISABLE                                 0x0
#define   AQ_FLUSH_VERTEX_DATA_CACHE_ENABLE                                  0x1


#define AQ_FLUSH_MCTS_HEADER_CACHE                                         15:15
#define AQ_FLUSH_MCTS_HEADER_CACHE_End                                        15
#define AQ_FLUSH_MCTS_HEADER_CACHE_Start                                      15
#define AQ_FLUSH_MCTS_HEADER_CACHE_Type                                      U01
#define   AQ_FLUSH_MCTS_HEADER_CACHE_DISABLE                                 0x0
#define   AQ_FLUSH_MCTS_HEADER_CACHE_ENABLE                                  0x1




#define AQMMUFlushRegAddrs                                                0x0E04
#define AQMMU_FLUSH_Address                                              0x03810
#define AQMMU_FLUSH_MSB                                                       15
#define AQMMU_FLUSH_LSB                                                        0
#define AQMMU_FLUSH_BLK                                                        0
#define AQMMU_FLUSH_Count                                                      1
#define AQMMU_FLUSH_FieldMask                                         0x0000007F
#define AQMMU_FLUSH_ReadMask                                          0x0000007F
#define AQMMU_FLUSH_WriteMask                                         0x0000007F
#define AQMMU_FLUSH_ResetValue                                        0x00000000


#define AQMMU_FLUSH_FEMMU                                                    0:0
#define AQMMU_FLUSH_FEMMU_End                                                  0
#define AQMMU_FLUSH_FEMMU_Start                                                0
#define AQMMU_FLUSH_FEMMU_Type                                               U01
#define   AQMMU_FLUSH_FEMMU_DISABLE                                          0x0
#define   AQMMU_FLUSH_FEMMU_ENABLE                                           0x1


#define AQMMU_FLUSH_RAMMU                                                    1:1
#define AQMMU_FLUSH_RAMMU_End                                                  1
#define AQMMU_FLUSH_RAMMU_Start                                                1
#define AQMMU_FLUSH_RAMMU_Type                                               U01
#define   AQMMU_FLUSH_RAMMU_DISABLE                                          0x0
#define   AQMMU_FLUSH_RAMMU_ENABLE                                           0x1


#define AQMMU_FLUSH_TXMMU                                                    2:2
#define AQMMU_FLUSH_TXMMU_End                                                  2
#define AQMMU_FLUSH_TXMMU_Start                                                2
#define AQMMU_FLUSH_TXMMU_Type                                               U01
#define   AQMMU_FLUSH_TXMMU_DISABLE                                          0x0
#define   AQMMU_FLUSH_TXMMU_ENABLE                                           0x1


#define AQMMU_FLUSH_PEMMU                                                    3:3
#define AQMMU_FLUSH_PEMMU_End                                                  3
#define AQMMU_FLUSH_PEMMU_Start                                                3
#define AQMMU_FLUSH_PEMMU_Type                                               U01
#define   AQMMU_FLUSH_PEMMU_DISABLE                                          0x0
#define   AQMMU_FLUSH_PEMMU_ENABLE                                           0x1


#define AQMMU_FLUSH_PEZMMU                                                   4:4
#define AQMMU_FLUSH_PEZMMU_End                                                 4
#define AQMMU_FLUSH_PEZMMU_Start                                               4
#define AQMMU_FLUSH_PEZMMU_Type                                              U01
#define   AQMMU_FLUSH_PEZMMU_DISABLE                                         0x0
#define   AQMMU_FLUSH_PEZMMU_ENABLE                                          0x1


#define AQMMU_FLUSH_IMMMU                                                    5:5
#define AQMMU_FLUSH_IMMMU_End                                                  5
#define AQMMU_FLUSH_IMMMU_Start                                                5
#define AQMMU_FLUSH_IMMMU_Type                                               U01
#define   AQMMU_FLUSH_IMMMU_DISABLE                                          0x0
#define   AQMMU_FLUSH_IMMMU_ENABLE                                           0x1


#define AQMMU_FLUSH_VGMMU                                                    6:6
#define AQMMU_FLUSH_VGMMU_End                                                  6
#define AQMMU_FLUSH_VGMMU_Start                                                6
#define AQMMU_FLUSH_VGMMU_Type                                               U01
#define   AQMMU_FLUSH_VGMMU_DISABLE                                          0x0
#define   AQMMU_FLUSH_VGMMU_ENABLE                                           0x1




#define AQVertexElementConfigRegAddrs                                     0x0E05
#define AQ_VERTEX_ELEMENT_CONFIG_Address                                 0x03814
#define AQ_VERTEX_ELEMENT_CONFIG_MSB                                          15
#define AQ_VERTEX_ELEMENT_CONFIG_LSB                                           0
#define AQ_VERTEX_ELEMENT_CONFIG_BLK                                           0
#define AQ_VERTEX_ELEMENT_CONFIG_Count                                         1
#define AQ_VERTEX_ELEMENT_CONFIG_FieldMask                            0x00011113
#define AQ_VERTEX_ELEMENT_CONFIG_ReadMask                             0x00011113
#define AQ_VERTEX_ELEMENT_CONFIG_WriteMask                            0x00011113
#define AQ_VERTEX_ELEMENT_CONFIG_ResetValue                           0x00000001


#define AQ_VERTEX_ELEMENT_CONFIG_VS_OUTPUT_BUFFER                            1:0
#define AQ_VERTEX_ELEMENT_CONFIG_VS_OUTPUT_BUFFER_End                          1
#define AQ_VERTEX_ELEMENT_CONFIG_VS_OUTPUT_BUFFER_Start                        0
#define AQ_VERTEX_ELEMENT_CONFIG_VS_OUTPUT_BUFFER_Type                       U02
#define   AQ_VERTEX_ELEMENT_CONFIG_VS_OUTPUT_BUFFER_SIZE4                    0x0
#define   AQ_VERTEX_ELEMENT_CONFIG_VS_OUTPUT_BUFFER_SIZE8                    0x1
#define   AQ_VERTEX_ELEMENT_CONFIG_VS_OUTPUT_BUFFER_SIZE16                   0x2


#define AQ_VERTEX_ELEMENT_CONFIG_CACHE_DISABLE                               4:4
#define AQ_VERTEX_ELEMENT_CONFIG_CACHE_DISABLE_End                             4
#define AQ_VERTEX_ELEMENT_CONFIG_CACHE_DISABLE_Start                           4
#define AQ_VERTEX_ELEMENT_CONFIG_CACHE_DISABLE_Type                          U01
#define   AQ_VERTEX_ELEMENT_CONFIG_CACHE_DISABLE_ENABLED                     0x0
#define   AQ_VERTEX_ELEMENT_CONFIG_CACHE_DISABLE_DISABLED                    0x1


#define AQ_VERTEX_ELEMENT_CONFIG_GEOMETRY_CACHE                              8:8
#define AQ_VERTEX_ELEMENT_CONFIG_GEOMETRY_CACHE_End                            8
#define AQ_VERTEX_ELEMENT_CONFIG_GEOMETRY_CACHE_Start                          8
#define AQ_VERTEX_ELEMENT_CONFIG_GEOMETRY_CACHE_Type                         U01

#define   AQ_VERTEX_ELEMENT_CONFIG_GEOMETRY_CACHE_DISABLE                    0x0
#define   AQ_VERTEX_ELEMENT_CONFIG_GEOMETRY_CACHE_ENABLE                     0x1


#define AQ_VERTEX_ELEMENT_CONFIG_TRIPPLE_LOOKUP                            12:12
#define AQ_VERTEX_ELEMENT_CONFIG_TRIPPLE_LOOKUP_End                           12
#define AQ_VERTEX_ELEMENT_CONFIG_TRIPPLE_LOOKUP_Start                         12
#define AQ_VERTEX_ELEMENT_CONFIG_TRIPPLE_LOOKUP_Type                         U01

#define   AQ_VERTEX_ELEMENT_CONFIG_TRIPPLE_LOOKUP_AUTOMATIC                  0x0

#define   AQ_VERTEX_ELEMENT_CONFIG_TRIPPLE_LOOKUP_DISABLE                    0x1


#define AQ_VERTEX_ELEMENT_CONFIG_FAST_VERTEX_LOOKUP                        16:16
#define AQ_VERTEX_ELEMENT_CONFIG_FAST_VERTEX_LOOKUP_End                       16
#define AQ_VERTEX_ELEMENT_CONFIG_FAST_VERTEX_LOOKUP_Start                     16
#define AQ_VERTEX_ELEMENT_CONFIG_FAST_VERTEX_LOOKUP_Type                     U01

#define   AQ_VERTEX_ELEMENT_CONFIG_FAST_VERTEX_LOOKUP_DISABLE                0x0

#define   AQ_VERTEX_ELEMENT_CONFIG_FAST_VERTEX_LOOKUP_PACKED                 0x1




#define mwv207regMultiSampleConfigRegAddrs                                0x0E06
#define MWV207REG_MULTI_SAMPLE_CONFIG_Address                            0x03818
#define MWV207REG_MULTI_SAMPLE_CONFIG_MSB                                     15
#define MWV207REG_MULTI_SAMPLE_CONFIG_LSB                                      0
#define MWV207REG_MULTI_SAMPLE_CONFIG_BLK                                      0
#define MWV207REG_MULTI_SAMPLE_CONFIG_Count                                    1
#define MWV207REG_MULTI_SAMPLE_CONFIG_FieldMask                       0x99FBF1FB
#define MWV207REG_MULTI_SAMPLE_CONFIG_ReadMask                        0x99FBF1FB
#define MWV207REG_MULTI_SAMPLE_CONFIG_WriteMask                       0x99FBF1FB
#define MWV207REG_MULTI_SAMPLE_CONFIG_ResetValue                      0x00000000


#define MWV207REG_MULTI_SAMPLE_CONFIG_MODE                                   1:0
#define MWV207REG_MULTI_SAMPLE_CONFIG_MODE_End                                 1
#define MWV207REG_MULTI_SAMPLE_CONFIG_MODE_Start                               0
#define MWV207REG_MULTI_SAMPLE_CONFIG_MODE_Type                              U02
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MODE_OFF                             0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MODE_MSAA2                           0x1
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MODE_MSAA4                           0x2
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MODE_MSAA8                           0x3


#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_MODE                              3:3
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_MODE_End                            3
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_MODE_Start                          3
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_MODE_Type                         U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_MODE_ENABLED                    0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_MODE_MASKED                     0x1

#define MWV207REG_MULTI_SAMPLE_CONFIG_ENABLE                                 7:4
#define MWV207REG_MULTI_SAMPLE_CONFIG_ENABLE_End                               7
#define MWV207REG_MULTI_SAMPLE_CONFIG_ENABLE_Start                             4
#define MWV207REG_MULTI_SAMPLE_CONFIG_ENABLE_Type                            U04


#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_ENABLE                            8:8
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_ENABLE_End                          8
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_ENABLE_Start                        8
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_ENABLE_Type                       U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_ENABLE_ENABLED                  0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_ENABLE_MASKED                   0x1


#define MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH                                14:12
#define MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_End                               14
#define MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_Start                             12
#define MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_Type                             U03
#define   MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_DISABLED                       0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_MATRIX0                        0x1
#define   MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_MATRIX1                        0x2
#define   MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_MATRIX2                        0x3
#define   MWV207REG_MULTI_SAMPLE_CONFIG_DEPTH_MATRIX3                        0x4


#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_DEPTH                           15:15
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_DEPTH_End                          15
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_DEPTH_Start                        15
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_DEPTH_Type                        U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_DEPTH_ENABLED                   0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_DEPTH_MASKED                    0x1


#define MWV207REG_MULTI_SAMPLE_CONFIG_VAA                                  17:16
#define MWV207REG_MULTI_SAMPLE_CONFIG_VAA_End                                 17
#define MWV207REG_MULTI_SAMPLE_CONFIG_VAA_Start                               16
#define MWV207REG_MULTI_SAMPLE_CONFIG_VAA_Type                               U02

#define   MWV207REG_MULTI_SAMPLE_CONFIG_VAA_OFF                              0x0

#define   MWV207REG_MULTI_SAMPLE_CONFIG_VAA_TWO_COLOR                        0x1

#define   MWV207REG_MULTI_SAMPLE_CONFIG_VAA_TWO_COLOR8                       0x2

#define   MWV207REG_MULTI_SAMPLE_CONFIG_VAA_FOUR_COLOR                       0x3


#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_VAA                             19:19
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_VAA_End                            19
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_VAA_Start                          19
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_VAA_Type                          U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_VAA_ENABLED                     0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_VAA_MASKED                      0x1

#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_COUNT                         22:20
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_COUNT_End                        22
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_COUNT_Start                      20
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_COUNT_Type                      U03


#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_COUNT                    23:23
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_COUNT_End                   23
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_COUNT_Start                 23
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_COUNT_Type                 U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_COUNT_ENABLED            0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_COUNT_MASKED             0x1


#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_SHADING_ENABLE                24:24
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_SHADING_ENABLE_End               24
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_SHADING_ENABLE_Start             24
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_SHADING_ENABLE_Type             U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_SHADING_ENABLE_DISABLED       0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_SHADING_ENABLE_ENABLED        0x1


#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_SHADING_ENABLE           27:27
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_SHADING_ENABLE_End          27
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_SHADING_ENABLE_Start        27
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_SHADING_ENABLE_Type        U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_SHADING_ENABLE_ENABLED   0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_SHADING_ENABLE_MASKED    0x1

#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_CENTER                        28:28
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_CENTER_End                       28
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_CENTER_Start                     28
#define MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_CENTER_Type                     U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_CENTER_DISABLED               0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_SAMPLE_CENTER_ENABLED                0x1


#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_CENTER                   31:31
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_CENTER_End                  31
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_CENTER_Start                31
#define MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_CENTER_Type                U01
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_CENTER_ENABLED           0x0
#define   MWV207REG_MULTI_SAMPLE_CONFIG_MASK_SAMPLE_CENTER_MASKED            0x1




#define mwv207regVaryingsRegAddrs                                         0x0E07
#define MWV207REG_VARYINGS_Address                                       0x0381C
#define MWV207REG_VARYINGS_MSB                                                15
#define MWV207REG_VARYINGS_LSB                                                 0
#define MWV207REG_VARYINGS_BLK                                                 0
#define MWV207REG_VARYINGS_Count                                               1
#define MWV207REG_VARYINGS_FieldMask                                  0x0000007F
#define MWV207REG_VARYINGS_ReadMask                                   0x0000007E
#define MWV207REG_VARYINGS_WriteMask                                  0x0000007E
#define MWV207REG_VARYINGS_ResetValue                                 0x00000000

#define MWV207REG_VARYINGS_COMPONENT_COUNT                                   6:0
#define MWV207REG_VARYINGS_COMPONENT_COUNT_End                                 6
#define MWV207REG_VARYINGS_COMPONENT_COUNT_Start                               0
#define MWV207REG_VARYINGS_COMPONENT_COUNT_Type                              U07




#define mwv207regVaryingPackingRegAddrs                                   0x0E08
#define MWV207REG_VARYING_PACKING_Address                                0x03820
#define MWV207REG_VARYING_PACKING_MSB                                         15
#define MWV207REG_VARYING_PACKING_LSB                                          0
#define MWV207REG_VARYING_PACKING_BLK                                          0
#define MWV207REG_VARYING_PACKING_Count                                        1
#define MWV207REG_VARYING_PACKING_FieldMask                           0x77777777
#define MWV207REG_VARYING_PACKING_ReadMask                            0x77777777
#define MWV207REG_VARYING_PACKING_WriteMask                           0x77777777
#define MWV207REG_VARYING_PACKING_ResetValue                          0x00000000


#define MWV207REG_VARYING_PACKING_VARYING0                                   2:0
#define MWV207REG_VARYING_PACKING_VARYING0_End                                 2
#define MWV207REG_VARYING_PACKING_VARYING0_Start                               0
#define MWV207REG_VARYING_PACKING_VARYING0_Type                              U03


#define MWV207REG_VARYING_PACKING_VARYING1                                   6:4
#define MWV207REG_VARYING_PACKING_VARYING1_End                                 6
#define MWV207REG_VARYING_PACKING_VARYING1_Start                               4
#define MWV207REG_VARYING_PACKING_VARYING1_Type                              U03


#define MWV207REG_VARYING_PACKING_VARYING2                                  10:8
#define MWV207REG_VARYING_PACKING_VARYING2_End                                10
#define MWV207REG_VARYING_PACKING_VARYING2_Start                               8
#define MWV207REG_VARYING_PACKING_VARYING2_Type                              U03


#define MWV207REG_VARYING_PACKING_VARYING3                                 14:12
#define MWV207REG_VARYING_PACKING_VARYING3_End                                14
#define MWV207REG_VARYING_PACKING_VARYING3_Start                              12
#define MWV207REG_VARYING_PACKING_VARYING3_Type                              U03


#define MWV207REG_VARYING_PACKING_VARYING4                                 18:16
#define MWV207REG_VARYING_PACKING_VARYING4_End                                18
#define MWV207REG_VARYING_PACKING_VARYING4_Start                              16
#define MWV207REG_VARYING_PACKING_VARYING4_Type                              U03


#define MWV207REG_VARYING_PACKING_VARYING5                                 22:20
#define MWV207REG_VARYING_PACKING_VARYING5_End                                22
#define MWV207REG_VARYING_PACKING_VARYING5_Start                              20
#define MWV207REG_VARYING_PACKING_VARYING5_Type                              U03


#define MWV207REG_VARYING_PACKING_VARYING6                                 26:24
#define MWV207REG_VARYING_PACKING_VARYING6_End                                26
#define MWV207REG_VARYING_PACKING_VARYING6_Start                              24
#define MWV207REG_VARYING_PACKING_VARYING6_Type                              U03


#define MWV207REG_VARYING_PACKING_VARYING7                                 30:28
#define MWV207REG_VARYING_PACKING_VARYING7_End                                30
#define MWV207REG_VARYING_PACKING_VARYING7_Start                              28
#define MWV207REG_VARYING_PACKING_VARYING7_Type                              U03




#define mwv207regComponentTypeLowRegAddrs                                 0x0E0A
#define MWV207REG_COMPONENT_TYPE_LOW_Address                             0x03828
#define MWV207REG_COMPONENT_TYPE_LOW_MSB                                      15
#define MWV207REG_COMPONENT_TYPE_LOW_LSB                                       0
#define MWV207REG_COMPONENT_TYPE_LOW_BLK                                       0
#define MWV207REG_COMPONENT_TYPE_LOW_Count                                     1
#define MWV207REG_COMPONENT_TYPE_LOW_FieldMask                        0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_LOW_ReadMask                         0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_LOW_WriteMask                        0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_LOW_ResetValue                       0x00000000

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X                             1:0
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X_End                           1
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X_Start                         0
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0X_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y                             3:2
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y_End                           3
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y_Start                         2
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Y_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z                             5:4
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z_End                           5
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z_Start                         4
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0Z_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W                             7:6
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W_End                           7
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W_Start                         6
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT0W_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X                             9:8
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X_End                           9
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X_Start                         8
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1X_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y                           11:10
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y_End                          11
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y_Start                        10
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Y_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z                           13:12
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z_End                          13
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z_Start                        12
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1Z_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W                           15:14
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W_End                          15
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W_Start                        14
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT1W_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X                           17:16
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X_End                          17
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X_Start                        16
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2X_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y                           19:18
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y_End                          19
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y_Start                        18
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Y_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z                           21:20
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z_End                          21
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z_Start                        20
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2Z_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W                           23:22
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W_End                          23
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W_Start                        22
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT2W_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X                           25:24
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X_End                          25
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X_Start                        24
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3X_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y                           27:26
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y_End                          27
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y_Start                        26
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Y_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z                           29:28
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z_End                          29
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z_Start                        28
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3Z_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W                           31:30
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W_End                          31
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W_Start                        30
#define MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_LOW_COMPONENT3W_TEXTURE_V                 0x3

#define mwv207regComponentTypeHighRegAddrs                                0x0E0B
#define MWV207REG_COMPONENT_TYPE_HIGH_Address                            0x0382C
#define MWV207REG_COMPONENT_TYPE_HIGH_MSB                                     15
#define MWV207REG_COMPONENT_TYPE_HIGH_LSB                                      0
#define MWV207REG_COMPONENT_TYPE_LOW_HIGH_BLK                                  0
#define MWV207REG_COMPONENT_TYPE_HIGH_Count                                    1
#define MWV207REG_COMPONENT_TYPE_HIGH_FieldMask                       0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_HIGH_ReadMask                        0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_HIGH_WriteMask                       0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_HIGH_ResetValue                      0x00000000

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X                            1:0
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X_End                          1
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X_Start                        0
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y                            3:2
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y_End                          3
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y_Start                        2
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z                            5:4
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z_End                          5
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z_Start                        4
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W                            7:6
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W_End                          7
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W_Start                        6
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT4W_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X                            9:8
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X_End                          9
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X_Start                        8
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y                          11:10
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y_End                         11
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y_Start                       10
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z                          13:12
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z_End                         13
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z_Start                       12
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W                          15:14
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W_End                         15
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W_Start                       14
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT5W_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X                          17:16
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X_End                         17
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X_Start                       16
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y                          19:18
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y_End                         19
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y_Start                       18
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z                          21:20
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z_End                         21
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z_Start                       20
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W                          23:22
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W_End                         23
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W_Start                       22
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT6W_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X                          25:24
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X_End                         25
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X_Start                       24
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y                          27:26
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y_End                         27
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y_Start                       26
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z                          29:28
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z_End                         29
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z_Start                       28
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W                          31:30
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W_End                         31
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W_Start                       30
#define MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_HIGH_COMPONENT7W_TEXTURE_V                0x3



#define mwv207regOcclusionAddressRegAddrs                                 0x0E09
#define MWV207REG_OCCLUSION_ADDRESS_Address                              0x03824
#define MWV207REG_OCCLUSION_ADDRESS_MSB                                       15
#define MWV207REG_OCCLUSION_ADDRESS_LSB                                        0
#define MWV207REG_OCCLUSION_ADDRESS_BLK                                        0
#define MWV207REG_OCCLUSION_ADDRESS_Count                                      1
#define MWV207REG_OCCLUSION_ADDRESS_FieldMask                         0xFFFFFFFF
#define MWV207REG_OCCLUSION_ADDRESS_ReadMask                          0xFFFFFFFC
#define MWV207REG_OCCLUSION_ADDRESS_WriteMask                         0xFFFFFFFC
#define MWV207REG_OCCLUSION_ADDRESS_ResetValue                        0x00000000

#define MWV207REG_OCCLUSION_ADDRESS_TYPE                                   31:31
#define MWV207REG_OCCLUSION_ADDRESS_TYPE_End                                  31
#define MWV207REG_OCCLUSION_ADDRESS_TYPE_Start                                31
#define MWV207REG_OCCLUSION_ADDRESS_TYPE_Type                                U01
#define   MWV207REG_OCCLUSION_ADDRESS_TYPE_SYSTEM                            0x0
#define   MWV207REG_OCCLUSION_ADDRESS_TYPE_VIRTUAL_SYSTEM                    0x1

#define MWV207REG_OCCLUSION_ADDRESS_ADDRESS                                 30:0
#define MWV207REG_OCCLUSION_ADDRESS_ADDRESS_End                               30
#define MWV207REG_OCCLUSION_ADDRESS_ADDRESS_Start                              0
#define MWV207REG_OCCLUSION_ADDRESS_ADDRESS_Type                             U31



#define mwv207regOcclusionDataRegAddrs                                    0x0E0C
#define MWV207REG_OCCLUSION_DATA_Address                                 0x03830
#define MWV207REG_OCCLUSION_DATA_MSB                                          15
#define MWV207REG_OCCLUSION_DATA_LSB                                           0
#define MWV207REG_OCCLUSION_DATA_BLK                                           0
#define MWV207REG_OCCLUSION_DATA_Count                                         1
#define MWV207REG_OCCLUSION_DATA_FieldMask                            0xFFFFFFFF
#define MWV207REG_OCCLUSION_DATA_ReadMask                             0xFFFFFFFF
#define MWV207REG_OCCLUSION_DATA_WriteMask                            0xFFFFFFFF
#define MWV207REG_OCCLUSION_DATA_ResetValue                           0x00000000

#define MWV207REG_OCCLUSION_DATA_COUNTER                                    31:0
#define MWV207REG_OCCLUSION_DATA_COUNTER_End                                  31
#define MWV207REG_OCCLUSION_DATA_COUNTER_Start                                 0
#define MWV207REG_OCCLUSION_DATA_COUNTER_Type                                U32




#define mwv207regVaryingPackingExRegAddrs                                 0x0E0D
#define MWV207REG_VARYING_PACKING_EX_Address                             0x03834
#define MWV207REG_VARYING_PACKING_EX_MSB                                      15
#define MWV207REG_VARYING_PACKING_EX_LSB                                       0
#define MWV207REG_VARYING_PACKING_EX_BLK                                       0
#define MWV207REG_VARYING_PACKING_EX_Count                                     1
#define MWV207REG_VARYING_PACKING_EX_FieldMask                        0x77777777
#define MWV207REG_VARYING_PACKING_EX_ReadMask                         0x77777777
#define MWV207REG_VARYING_PACKING_EX_WriteMask                        0x77777777
#define MWV207REG_VARYING_PACKING_EX_ResetValue                       0x00000000


#define MWV207REG_VARYING_PACKING_EX_VARYING8                                2:0
#define MWV207REG_VARYING_PACKING_EX_VARYING8_End                              2
#define MWV207REG_VARYING_PACKING_EX_VARYING8_Start                            0
#define MWV207REG_VARYING_PACKING_EX_VARYING8_Type                           U03


#define MWV207REG_VARYING_PACKING_EX_VARYING9                                6:4
#define MWV207REG_VARYING_PACKING_EX_VARYING9_End                              6
#define MWV207REG_VARYING_PACKING_EX_VARYING9_Start                            4
#define MWV207REG_VARYING_PACKING_EX_VARYING9_Type                           U03


#define MWV207REG_VARYING_PACKING_EX_VARYING10                              10:8
#define MWV207REG_VARYING_PACKING_EX_VARYING10_End                            10
#define MWV207REG_VARYING_PACKING_EX_VARYING10_Start                           8
#define MWV207REG_VARYING_PACKING_EX_VARYING10_Type                          U03


#define MWV207REG_VARYING_PACKING_EX_VARYING11                             14:12
#define MWV207REG_VARYING_PACKING_EX_VARYING11_End                            14
#define MWV207REG_VARYING_PACKING_EX_VARYING11_Start                          12
#define MWV207REG_VARYING_PACKING_EX_VARYING11_Type                          U03


#define MWV207REG_VARYING_PACKING_EX_VARYING12                             18:16
#define MWV207REG_VARYING_PACKING_EX_VARYING12_End                            18
#define MWV207REG_VARYING_PACKING_EX_VARYING12_Start                          16
#define MWV207REG_VARYING_PACKING_EX_VARYING12_Type                          U03


#define MWV207REG_VARYING_PACKING_EX_VARYING13                             22:20
#define MWV207REG_VARYING_PACKING_EX_VARYING13_End                            22
#define MWV207REG_VARYING_PACKING_EX_VARYING13_Start                          20
#define MWV207REG_VARYING_PACKING_EX_VARYING13_Type                          U03


#define MWV207REG_VARYING_PACKING_EX_VARYING14                             26:24
#define MWV207REG_VARYING_PACKING_EX_VARYING14_End                            26
#define MWV207REG_VARYING_PACKING_EX_VARYING14_Start                          24
#define MWV207REG_VARYING_PACKING_EX_VARYING14_Type                          U03


#define MWV207REG_VARYING_PACKING_EX_VARYING15                             30:28
#define MWV207REG_VARYING_PACKING_EX_VARYING15_End                            30
#define MWV207REG_VARYING_PACKING_EX_VARYING15_Start                          28
#define MWV207REG_VARYING_PACKING_EX_VARYING15_Type                          U03




#define mwv207regComponentTypeExRegAddrs                                  0x0E0E
#define MWV207REG_COMPONENT_TYPE_EX_Address                              0x03838
#define MWV207REG_COMPONENT_TYPE_EX_MSB                                       15
#define MWV207REG_COMPONENT_TYPE_EX_LSB                                        0
#define MWV207REG_COMPONENT_TYPE_EX_BLK                                        0
#define MWV207REG_COMPONENT_TYPE_EX_Count                                      1
#define MWV207REG_COMPONENT_TYPE_EX_FieldMask                         0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_EX_ReadMask                          0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_EX_WriteMask                         0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_EX_ResetValue                        0x00000000

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X                              1:0
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X_End                            1
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X_Start                          0
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8X_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y                              3:2
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y_End                            3
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y_Start                          2
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Y_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z                              5:4
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z_End                            5
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z_Start                          4
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8Z_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W                              7:6
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W_End                            7
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W_Start                          6
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT8W_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X                              9:8
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X_End                            9
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X_Start                          8
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9X_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y                            11:10
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y_End                           11
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y_Start                         10
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Y_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z                            13:12
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z_End                           13
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z_Start                         12
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9Z_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W                            15:14
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W_End                           15
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W_Start                         14
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W_Type                         U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W_OTHER                      0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W_COLOR                      0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W_TEXTURE_U                  0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT9W_TEXTURE_V                  0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X                           17:16
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X_End                          17
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X_Start                        16
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10X_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y                           19:18
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y_End                          19
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y_Start                        18
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Y_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z                           21:20
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z_End                          21
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z_Start                        20
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10Z_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W                           23:22
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W_End                          23
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W_Start                        22
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT10W_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X                           25:24
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X_End                          25
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X_Start                        24
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11X_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y                           27:26
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y_End                          27
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y_Start                        26
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Y_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z                           29:28
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z_End                          29
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z_Start                        28
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11Z_TEXTURE_V                 0x3

#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W                           31:30
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W_End                          31
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W_Start                        30
#define MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W_Type                        U02
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W_OTHER                     0x0
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W_COLOR                     0x1
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W_TEXTURE_U                 0x2
#define   MWV207REG_COMPONENT_TYPE_EX_COMPONENT11W_TEXTURE_V                 0x3




#define mwv207regWindowControlRegAddrs                                    0x0E0F
#define MWV207REG_WINDOW_CONTROL_Address                                 0x0383C
#define MWV207REG_WINDOW_CONTROL_MSB                                          15
#define MWV207REG_WINDOW_CONTROL_LSB                                           0
#define MWV207REG_WINDOW_CONTROL_BLK                                           0
#define MWV207REG_WINDOW_CONTROL_Count                                         1
#define MWV207REG_WINDOW_CONTROL_FieldMask                            0x00000333
#define MWV207REG_WINDOW_CONTROL_ReadMask                             0x00000333
#define MWV207REG_WINDOW_CONTROL_WriteMask                            0x00000333
#define MWV207REG_WINDOW_CONTROL_ResetValue                           0x00000000

#define MWV207REG_WINDOW_CONTROL_COLOR                                       1:0
#define MWV207REG_WINDOW_CONTROL_COLOR_End                                     1
#define MWV207REG_WINDOW_CONTROL_COLOR_Start                                   0
#define MWV207REG_WINDOW_CONTROL_COLOR_Type                                  U02
#define   MWV207REG_WINDOW_CONTROL_COLOR_DISABLE                             0x0
#define   MWV207REG_WINDOW_CONTROL_COLOR_INTERNAL                            0x1
#define   MWV207REG_WINDOW_CONTROL_COLOR_EXTERNAL                            0x2

#define MWV207REG_WINDOW_CONTROL_DEPTH                                       5:4
#define MWV207REG_WINDOW_CONTROL_DEPTH_End                                     5
#define MWV207REG_WINDOW_CONTROL_DEPTH_Start                                   4
#define MWV207REG_WINDOW_CONTROL_DEPTH_Type                                  U02
#define   MWV207REG_WINDOW_CONTROL_DEPTH_DISABLE                             0x0
#define   MWV207REG_WINDOW_CONTROL_DEPTH_INTERNAL                            0x1
#define   MWV207REG_WINDOW_CONTROL_DEPTH_EXTERNAL                            0x2

#define MWV207REG_WINDOW_CONTROL_STREAMS                                     9:8
#define MWV207REG_WINDOW_CONTROL_STREAMS_End                                   9
#define MWV207REG_WINDOW_CONTROL_STREAMS_Start                                 8
#define MWV207REG_WINDOW_CONTROL_STREAMS_Type                                U02
#define   MWV207REG_WINDOW_CONTROL_STREAMS_DISABLE                           0x0
#define   MWV207REG_WINDOW_CONTROL_STREAMS_ENABLE                            0x1
#define   MWV207REG_WINDOW_CONTROL_STREAMS_INVALIDATE                        0x2




#define mwv207regWindowOriginRegAddrs                                     0x0E10
#define MWV207REG_WINDOW_ORIGIN_Address                                  0x03840
#define MWV207REG_WINDOW_ORIGIN_MSB                                           15
#define MWV207REG_WINDOW_ORIGIN_LSB                                            0
#define MWV207REG_WINDOW_ORIGIN_BLK                                            0
#define MWV207REG_WINDOW_ORIGIN_Count                                          1
#define MWV207REG_WINDOW_ORIGIN_FieldMask                             0x1FFF1FFF
#define MWV207REG_WINDOW_ORIGIN_ReadMask                              0x1FFF1FFF
#define MWV207REG_WINDOW_ORIGIN_WriteMask                             0x1FFF1FFF
#define MWV207REG_WINDOW_ORIGIN_ResetValue                            0x00000000


#define MWV207REG_WINDOW_ORIGIN_X                                           12:0
#define MWV207REG_WINDOW_ORIGIN_X_End                                         12
#define MWV207REG_WINDOW_ORIGIN_X_Start                                        0
#define MWV207REG_WINDOW_ORIGIN_X_Type                                       U13


#define MWV207REG_WINDOW_ORIGIN_Y                                          28:16
#define MWV207REG_WINDOW_ORIGIN_Y_End                                         28
#define MWV207REG_WINDOW_ORIGIN_Y_Start                                       16
#define MWV207REG_WINDOW_ORIGIN_Y_Type                                       U13




#define mwv207regWindowSizeRegAddrs                                       0x0E11
#define MWV207REG_WINDOW_SIZE_Address                                    0x03844
#define MWV207REG_WINDOW_SIZE_MSB                                             15
#define MWV207REG_WINDOW_SIZE_LSB                                              0
#define MWV207REG_WINDOW_SIZE_BLK                                              0
#define MWV207REG_WINDOW_SIZE_Count                                            1
#define MWV207REG_WINDOW_SIZE_FieldMask                               0x3FFF3FFF
#define MWV207REG_WINDOW_SIZE_ReadMask                                0x3FFF3FFF
#define MWV207REG_WINDOW_SIZE_WriteMask                               0x3FFF3FFF
#define MWV207REG_WINDOW_SIZE_ResetValue                              0x00000000


#define MWV207REG_WINDOW_SIZE_WIDTH                                         13:0
#define MWV207REG_WINDOW_SIZE_WIDTH_End                                       13
#define MWV207REG_WINDOW_SIZE_WIDTH_Start                                      0
#define MWV207REG_WINDOW_SIZE_WIDTH_Type                                     U14


#define MWV207REG_WINDOW_SIZE_HEIGHT                                       29:16
#define MWV207REG_WINDOW_SIZE_HEIGHT_End                                      29
#define MWV207REG_WINDOW_SIZE_HEIGHT_Start                                    16
#define MWV207REG_WINDOW_SIZE_HEIGHT_Type                                    U14



#define mwv207regStoreCounterRegAddrs                                     0x0E12
#define MWV207REG_STORE_COUNTER_Address                                  0x03848
#define MWV207REG_STORE_COUNTER_MSB                                           15
#define MWV207REG_STORE_COUNTER_LSB                                            0
#define MWV207REG_STORE_COUNTER_BLK                                            0
#define MWV207REG_STORE_COUNTER_Count                                          1
#define MWV207REG_STORE_COUNTER_FieldMask                             0xFFFFFFFF
#define MWV207REG_STORE_COUNTER_ReadMask                              0xFFFFFFFF
#define MWV207REG_STORE_COUNTER_WriteMask                             0xFFFFFFFF
#define MWV207REG_STORE_COUNTER_ResetValue                            0x00000000


#define MWV207REG_STORE_COUNTER_COUNTER_SELECT                              15:0
#define MWV207REG_STORE_COUNTER_COUNTER_SELECT_End                            15
#define MWV207REG_STORE_COUNTER_COUNTER_SELECT_Start                           0
#define MWV207REG_STORE_COUNTER_COUNTER_SELECT_Type                          U16

#define MWV207REG_STORE_COUNTER_SOURCE_SH                                  16:16
#define MWV207REG_STORE_COUNTER_SOURCE_SH_End                                 16
#define MWV207REG_STORE_COUNTER_SOURCE_SH_Start                               16
#define MWV207REG_STORE_COUNTER_SOURCE_SH_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_RA                                  17:17
#define MWV207REG_STORE_COUNTER_SOURCE_RA_End                                 17
#define MWV207REG_STORE_COUNTER_SOURCE_RA_Start                               17
#define MWV207REG_STORE_COUNTER_SOURCE_RA_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_SE                                  18:18
#define MWV207REG_STORE_COUNTER_SOURCE_SE_End                                 18
#define MWV207REG_STORE_COUNTER_SOURCE_SE_Start                               18
#define MWV207REG_STORE_COUNTER_SOURCE_SE_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_PA                                  19:19
#define MWV207REG_STORE_COUNTER_SOURCE_PA_End                                 19
#define MWV207REG_STORE_COUNTER_SOURCE_PA_Start                               19
#define MWV207REG_STORE_COUNTER_SOURCE_PA_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_FE                                  20:20
#define MWV207REG_STORE_COUNTER_SOURCE_FE_End                                 20
#define MWV207REG_STORE_COUNTER_SOURCE_FE_Start                               20
#define MWV207REG_STORE_COUNTER_SOURCE_FE_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_PE                                  21:21
#define MWV207REG_STORE_COUNTER_SOURCE_PE_End                                 21
#define MWV207REG_STORE_COUNTER_SOURCE_PE_Start                               21
#define MWV207REG_STORE_COUNTER_SOURCE_PE_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_TX                                  22:22
#define MWV207REG_STORE_COUNTER_SOURCE_TX_End                                 22
#define MWV207REG_STORE_COUNTER_SOURCE_TX_Start                               22
#define MWV207REG_STORE_COUNTER_SOURCE_TX_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_MC                                  23:23
#define MWV207REG_STORE_COUNTER_SOURCE_MC_End                                 23
#define MWV207REG_STORE_COUNTER_SOURCE_MC_Start                               23
#define MWV207REG_STORE_COUNTER_SOURCE_MC_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_HI                                  24:24
#define MWV207REG_STORE_COUNTER_SOURCE_HI_End                                 24
#define MWV207REG_STORE_COUNTER_SOURCE_HI_Start                               24
#define MWV207REG_STORE_COUNTER_SOURCE_HI_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_GPUL2                               25:25
#define MWV207REG_STORE_COUNTER_SOURCE_GPUL2_End                              25
#define MWV207REG_STORE_COUNTER_SOURCE_GPUL2_Start                            25
#define MWV207REG_STORE_COUNTER_SOURCE_GPUL2_Type                            U01

#define MWV207REG_STORE_COUNTER_SOURCE_WD                                  26:26
#define MWV207REG_STORE_COUNTER_SOURCE_WD_End                                 26
#define MWV207REG_STORE_COUNTER_SOURCE_WD_Start                               26
#define MWV207REG_STORE_COUNTER_SOURCE_WD_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_NN                                  27:27
#define MWV207REG_STORE_COUNTER_SOURCE_NN_End                                 27
#define MWV207REG_STORE_COUNTER_SOURCE_NN_Start                               27
#define MWV207REG_STORE_COUNTER_SOURCE_NN_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_TP                                  28:28
#define MWV207REG_STORE_COUNTER_SOURCE_TP_End                                 28
#define MWV207REG_STORE_COUNTER_SOURCE_TP_Start                               28
#define MWV207REG_STORE_COUNTER_SOURCE_TP_Type                               U01

#define MWV207REG_STORE_COUNTER_SOURCE_TFB                                 29:29
#define MWV207REG_STORE_COUNTER_SOURCE_TFB_End                                29
#define MWV207REG_STORE_COUNTER_SOURCE_TFB_Start                              29
#define MWV207REG_STORE_COUNTER_SOURCE_TFB_Type                              U01

#define MWV207REG_STORE_COUNTER_SOURCE_USC                                 30:30
#define MWV207REG_STORE_COUNTER_SOURCE_USC_End                                30
#define MWV207REG_STORE_COUNTER_SOURCE_USC_Start                              30
#define MWV207REG_STORE_COUNTER_SOURCE_USC_Type                              U01

#define MWV207REG_STORE_COUNTER_SOURCE_DIR                                 31:31
#define MWV207REG_STORE_COUNTER_SOURCE_DIR_End                                31
#define MWV207REG_STORE_COUNTER_SOURCE_DIR_Start                              31
#define MWV207REG_STORE_COUNTER_SOURCE_DIR_Type                              U01




#define AQModeRegAddrs                                                    0x0E13
#define AQ_MODE_Address                                                  0x0384C
#define AQ_MODE_MSB                                                           15
#define AQ_MODE_LSB                                                            0
#define AQ_MODE_BLK                                                            0
#define AQ_MODE_Count                                                          1
#define AQ_MODE_FieldMask                                             0x00000003
#define AQ_MODE_ReadMask                                              0x00000003
#define AQ_MODE_WriteMask                                             0x00000003
#define AQ_MODE_ResetValue                                            0x00000000


#define AQ_MODE_API_MODE                                                     1:0
#define AQ_MODE_API_MODE_End                                                   1
#define AQ_MODE_API_MODE_Start                                                 0
#define AQ_MODE_API_MODE_Type                                                U02
#define   AQ_MODE_API_MODE_OpenGL                                            0x0
#define   AQ_MODE_API_MODE_OpenVG                                            0x1
#define   AQ_MODE_API_MODE_OpenCL                                            0x2
#define   AQ_MODE_API_MODE_D3d                                               0x3




#define mwv207regContextRegAddrs                                          0x0E14
#define MWV207REG_CONTEXT_Address                                        0x03850
#define MWV207REG_CONTEXT_MSB                                                 15
#define MWV207REG_CONTEXT_LSB                                                  0
#define MWV207REG_CONTEXT_BLK                                                  0
#define MWV207REG_CONTEXT_Count                                                1
#define MWV207REG_CONTEXT_FieldMask                                   0xFFFFFFFF
#define MWV207REG_CONTEXT_ReadMask                                    0xFFFFFFFF
#define MWV207REG_CONTEXT_WriteMask                                   0xFFFFFFFF
#define MWV207REG_CONTEXT_ResetValue                                  0x00000000

#define MWV207REG_CONTEXT_ID                                                31:0
#define MWV207REG_CONTEXT_ID_End                                              31
#define MWV207REG_CONTEXT_ID_Start                                             0
#define MWV207REG_CONTEXT_ID_Type                                            U32




#define mwv207regComponentTypeEx2RegAddrs                                 0x0E15
#define MWV207REG_COMPONENT_TYPE_EX2_Address                             0x03854
#define MWV207REG_COMPONENT_TYPE_EX2_MSB                                      15
#define MWV207REG_COMPONENT_TYPE_EX2_LSB                                       0
#define MWV207REG_COMPONENT_TYPE_EX2_BLK                                       0
#define MWV207REG_COMPONENT_TYPE_EX2_Count                                     1
#define MWV207REG_COMPONENT_TYPE_EX2_FieldMask                        0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_EX2_ReadMask                         0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_EX2_WriteMask                        0xFFFFFFFF
#define MWV207REG_COMPONENT_TYPE_EX2_ResetValue                       0x00000000

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X                            1:0
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X_End                          1
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X_Start                        0
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y                            3:2
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y_End                          3
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y_Start                        2
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z                            5:4
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z_End                          5
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z_Start                        4
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W                            7:6
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W_End                          7
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W_Start                        6
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT12W_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X                            9:8
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X_End                          9
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X_Start                        8
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y                          11:10
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y_End                         11
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y_Start                       10
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z                          13:12
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z_End                         13
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z_Start                       12
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W                          15:14
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W_End                         15
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W_Start                       14
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT13W_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X                          17:16
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X_End                         17
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X_Start                       16
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y                          19:18
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y_End                         19
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y_Start                       18
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z                          21:20
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z_End                         21
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z_Start                       20
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W                          23:22
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W_End                         23
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W_Start                       22
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT14W_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X                          25:24
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X_End                         25
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X_Start                       24
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15X_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y                          27:26
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y_End                         27
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y_Start                       26
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Y_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z                          29:28
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z_End                         29
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z_Start                       28
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15Z_TEXTURE_V                0x3

#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W                          31:30
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W_End                         31
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W_Start                       30
#define MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W_Type                       U02
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W_OTHER                    0x0
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W_COLOR                    0x1
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W_TEXTURE_U                0x2
#define   MWV207REG_COMPONENT_TYPE_EX2_COMPONENT15W_TEXTURE_V                0x3



#define mwv207regPCAddressRegAddrs                                        0x0E16
#define MWV207REG_PC_ADDRESS_Address                                     0x03858
#define MWV207REG_PC_ADDRESS_MSB                                              15
#define MWV207REG_PC_ADDRESS_LSB                                               0
#define MWV207REG_PC_ADDRESS_BLK                                               0
#define MWV207REG_PC_ADDRESS_Count                                             1
#define MWV207REG_PC_ADDRESS_FieldMask                                0xFFFFFFFF
#define MWV207REG_PC_ADDRESS_ReadMask                                 0xFFFFFFFF
#define MWV207REG_PC_ADDRESS_WriteMask                                0xFFFFFFFF
#define MWV207REG_PC_ADDRESS_ResetValue                               0x00000000

#define MWV207REG_PC_ADDRESS_ADDRESS                                        31:0
#define MWV207REG_PC_ADDRESS_ADDRESS_End                                      31
#define MWV207REG_PC_ADDRESS_ADDRESS_Start                                     0
#define MWV207REG_PC_ADDRESS_ADDRESS_Type                                    U32




#define mwv207regTXCacheRegAddrs                                          0x0E17
#define MWV207REG_TX_CACHE_Address                                       0x0385C
#define MWV207REG_TX_CACHE_MSB                                                15
#define MWV207REG_TX_CACHE_LSB                                                 0
#define MWV207REG_TX_CACHE_BLK                                                 0
#define MWV207REG_TX_CACHE_Count                                               1
#define MWV207REG_TX_CACHE_FieldMask                                  0x00000001
#define MWV207REG_TX_CACHE_ReadMask                                   0x00000001
#define MWV207REG_TX_CACHE_WriteMask                                  0x00000001
#define MWV207REG_TX_CACHE_ResetValue                                 0x00000000

#define MWV207REG_TX_CACHE_DISABLE_L2                                        0:0
#define MWV207REG_TX_CACHE_DISABLE_L2_End                                      0
#define MWV207REG_TX_CACHE_DISABLE_L2_Start                                    0
#define MWV207REG_TX_CACHE_DISABLE_L2_Type                                   U01
#define   MWV207REG_TX_CACHE_DISABLE_L2_ENABLE                               0x0
#define   MWV207REG_TX_CACHE_DISABLE_L2_DISABLE                              0x1




#define mwv207regOcclusionControlRegAddrs                                 0x0E18
#define MWV207REG_OCCLUSION_CONTROL_Address                              0x03860
#define MWV207REG_OCCLUSION_CONTROL_MSB                                       15
#define MWV207REG_OCCLUSION_CONTROL_LSB                                        0
#define MWV207REG_OCCLUSION_CONTROL_BLK                                        0
#define MWV207REG_OCCLUSION_CONTROL_Count                                      1
#define MWV207REG_OCCLUSION_CONTROL_FieldMask                         0x00000007
#define MWV207REG_OCCLUSION_CONTROL_ReadMask                          0x00000007
#define MWV207REG_OCCLUSION_CONTROL_WriteMask                         0x00000007
#define MWV207REG_OCCLUSION_CONTROL_ResetValue                        0x00000000


#define MWV207REG_OCCLUSION_CONTROL_MODE                                     2:0
#define MWV207REG_OCCLUSION_CONTROL_MODE_End                                   2
#define MWV207REG_OCCLUSION_CONTROL_MODE_Start                                 0
#define MWV207REG_OCCLUSION_CONTROL_MODE_Type                                U03

#define   MWV207REG_OCCLUSION_CONTROL_MODE_COUNT                             0x0
#define   MWV207REG_OCCLUSION_CONTROL_MODE_BOOLEAN                           0x1
#define   MWV207REG_OCCLUSION_CONTROL_MODE_BOOLEAN_CONDITIONAL               0x2

#define   MWV207REG_OCCLUSION_CONTROL_MODE_COUNT_EARLY                       0x3
#define   MWV207REG_OCCLUSION_CONTROL_MODE_BOOLEAN_EARLY                     0x4
#define   MWV207REG_OCCLUSION_CONTROL_MODE_BOOLEAN_CONDITIONAL_EARLY         0x5

#define   MWV207REG_OCCLUSION_CONTROL_MODE_RENDER                            0x6
#define   MWV207REG_OCCLUSION_CONTROL_MODE_RENDER_IN_RA                      0x7




#define mwv207regClockControlRegAddrs                                     0x0E19
#define MWV207REG_CLOCK_CONTROL_Address                                  0x03864
#define MWV207REG_CLOCK_CONTROL_MSB                                           15
#define MWV207REG_CLOCK_CONTROL_LSB                                            0
#define MWV207REG_CLOCK_CONTROL_BLK                                            0
#define MWV207REG_CLOCK_CONTROL_Count                                          1
#define MWV207REG_CLOCK_CONTROL_FieldMask                             0x007F7F7F
#define MWV207REG_CLOCK_CONTROL_ReadMask                              0x007F7F7F
#define MWV207REG_CLOCK_CONTROL_WriteMask                             0x007F7F7F
#define MWV207REG_CLOCK_CONTROL_ResetValue                            0x00404040

#define MWV207REG_CLOCK_CONTROL_CORE                                         6:0
#define MWV207REG_CLOCK_CONTROL_CORE_End                                       6
#define MWV207REG_CLOCK_CONTROL_CORE_Start                                     0
#define MWV207REG_CLOCK_CONTROL_CORE_Type                                    U07

#define MWV207REG_CLOCK_CONTROL_SHADER                                      14:8
#define MWV207REG_CLOCK_CONTROL_SHADER_End                                    14
#define MWV207REG_CLOCK_CONTROL_SHADER_Start                                   8
#define MWV207REG_CLOCK_CONTROL_SHADER_Type                                  U07

#define MWV207REG_CLOCK_CONTROL_TEXTURE                                    22:16
#define MWV207REG_CLOCK_CONTROL_TEXTURE_End                                   22
#define MWV207REG_CLOCK_CONTROL_TEXTURE_Start                                 16
#define MWV207REG_CLOCK_CONTROL_TEXTURE_Type                                 U07




#define mwv207regFenceAddressRegAddrs                                     0x0E1A
#define MWV207REG_FENCE_ADDRESS_Address                                  0x03868
#define MWV207REG_FENCE_ADDRESS_MSB                                           15
#define MWV207REG_FENCE_ADDRESS_LSB                                            0
#define MWV207REG_FENCE_ADDRESS_BLK                                            0
#define MWV207REG_FENCE_ADDRESS_Count                                          1
#define MWV207REG_FENCE_ADDRESS_FieldMask                             0xFFFFFFFF
#define MWV207REG_FENCE_ADDRESS_ReadMask                              0xFFFFFFFC
#define MWV207REG_FENCE_ADDRESS_WriteMask                             0xFFFFFFFC
#define MWV207REG_FENCE_ADDRESS_ResetValue                            0x00000000

#define MWV207REG_FENCE_ADDRESS_TYPE                                       31:31
#define MWV207REG_FENCE_ADDRESS_TYPE_End                                      31
#define MWV207REG_FENCE_ADDRESS_TYPE_Start                                    31
#define MWV207REG_FENCE_ADDRESS_TYPE_Type                                    U01
#define   MWV207REG_FENCE_ADDRESS_TYPE_SYSTEM                                0x0
#define   MWV207REG_FENCE_ADDRESS_TYPE_VIRTUAL_SYSTEM                        0x1

#define MWV207REG_FENCE_ADDRESS_ADDRESS                                     30:0
#define MWV207REG_FENCE_ADDRESS_ADDRESS_End                                   30
#define MWV207REG_FENCE_ADDRESS_ADDRESS_Start                                  0
#define MWV207REG_FENCE_ADDRESS_ADDRESS_Type                                 U31




#define mwv207regFenceDataRegAddrs                                        0x0E1B
#define MWV207REG_FENCE_DATA_Address                                     0x0386C
#define MWV207REG_FENCE_DATA_MSB                                              15
#define MWV207REG_FENCE_DATA_LSB                                               0
#define MWV207REG_FENCE_DATA_BLK                                               0
#define MWV207REG_FENCE_DATA_Count                                             1
#define MWV207REG_FENCE_DATA_FieldMask                                0xFFFFFFFF
#define MWV207REG_FENCE_DATA_ReadMask                                 0xFFFFFFFF
#define MWV207REG_FENCE_DATA_WriteMask                                0xFFFFFFFF
#define MWV207REG_FENCE_DATA_ResetValue                               0x00000000

#define MWV207REG_FENCE_DATA_DATA                                           31:0
#define MWV207REG_FENCE_DATA_DATA_End                                         31
#define MWV207REG_FENCE_DATA_DATA_Start                                        0
#define MWV207REG_FENCE_DATA_DATA_Type                                       U32




#define mwv207regProbeAddressRegAddrs                                     0x0E1C
#define MWV207REG_PROBE_ADDRESS_Address                                  0x03870
#define MWV207REG_PROBE_ADDRESS_MSB                                           15
#define MWV207REG_PROBE_ADDRESS_LSB                                            0
#define MWV207REG_PROBE_ADDRESS_BLK                                            0
#define MWV207REG_PROBE_ADDRESS_Count                                          1
#define MWV207REG_PROBE_ADDRESS_FieldMask                             0xFFFFFFFF
#define MWV207REG_PROBE_ADDRESS_ReadMask                              0xFFFFFFFC
#define MWV207REG_PROBE_ADDRESS_WriteMask                             0xFFFFFFFC
#define MWV207REG_PROBE_ADDRESS_ResetValue                            0x00000000

#define MWV207REG_PROBE_ADDRESS_TYPE                                       31:31
#define MWV207REG_PROBE_ADDRESS_TYPE_End                                      31
#define MWV207REG_PROBE_ADDRESS_TYPE_Start                                    31
#define MWV207REG_PROBE_ADDRESS_TYPE_Type                                    U01
#define   MWV207REG_PROBE_ADDRESS_TYPE_SYSTEM                                0x0
#define   MWV207REG_PROBE_ADDRESS_TYPE_VIRTUAL_SYSTEM                        0x1

#define MWV207REG_PROBE_ADDRESS_ADDRESS                                     30:0
#define MWV207REG_PROBE_ADDRESS_ADDRESS_End                                   30
#define MWV207REG_PROBE_ADDRESS_ADDRESS_Start                                  0
#define MWV207REG_PROBE_ADDRESS_ADDRESS_Type                                 U31




#define mwv207regProbeDataRegAddrs                                        0x0E1D
#define MWV207REG_PROBE_DATA_Address                                     0x03874
#define MWV207REG_PROBE_DATA_MSB                                              15
#define MWV207REG_PROBE_DATA_LSB                                               0
#define MWV207REG_PROBE_DATA_BLK                                               0
#define MWV207REG_PROBE_DATA_Count                                             1
#define MWV207REG_PROBE_DATA_FieldMask                                0xFFFFFFFF
#define MWV207REG_PROBE_DATA_ReadMask                                 0xFFFFFFFF
#define MWV207REG_PROBE_DATA_WriteMask                                0xFFFFFFFF
#define MWV207REG_PROBE_DATA_ResetValue                               0x00000000

#define MWV207REG_PROBE_DATA_DATA                                           31:0
#define MWV207REG_PROBE_DATA_DATA_End                                         31
#define MWV207REG_PROBE_DATA_DATA_Start                                        0
#define MWV207REG_PROBE_DATA_DATA_Type                                       U32




#define mwv207regProbeSelectRegAddrs                                      0x0E1E
#define MWV207REG_PROBE_SELECT_Address                                   0x03878
#define MWV207REG_PROBE_SELECT_MSB                                            15
#define MWV207REG_PROBE_SELECT_LSB                                             0
#define MWV207REG_PROBE_SELECT_BLK                                             0
#define MWV207REG_PROBE_SELECT_Count                                           1
#define MWV207REG_PROBE_SELECT_FieldMask                              0x031FFFFF
#define MWV207REG_PROBE_SELECT_ReadMask                               0x031FFFFF
#define MWV207REG_PROBE_SELECT_WriteMask                              0x031FFFFF
#define MWV207REG_PROBE_SELECT_ResetValue                             0x00000000


#define MWV207REG_PROBE_SELECT_COUNTER                                      15:0
#define MWV207REG_PROBE_SELECT_COUNTER_End                                    15
#define MWV207REG_PROBE_SELECT_COUNTER_Start                                   0
#define MWV207REG_PROBE_SELECT_COUNTER_Type                                  U16

#define MWV207REG_PROBE_SELECT_MODULE                                      20:16
#define MWV207REG_PROBE_SELECT_MODULE_End                                     20
#define MWV207REG_PROBE_SELECT_MODULE_Start                                   16
#define MWV207REG_PROBE_SELECT_MODULE_Type                                   U05
#define   MWV207REG_PROBE_SELECT_MODULE_FRONT_END                           0x00
#define   MWV207REG_PROBE_SELECT_MODULE_VERTEX_SHADER                       0x01
#define   MWV207REG_PROBE_SELECT_MODULE_PRIMITIVE_ASSEMBLY                  0x02
#define   MWV207REG_PROBE_SELECT_MODULE_SETUP                               0x03
#define   MWV207REG_PROBE_SELECT_MODULE_RASTERIZER                          0x04
#define   MWV207REG_PROBE_SELECT_MODULE_PIXEL_SHADER                        0x05
#define   MWV207REG_PROBE_SELECT_MODULE_TEXTURE                             0x06
#define   MWV207REG_PROBE_SELECT_MODULE_PIXEL_ENGINE                        0x07
#define   MWV207REG_PROBE_SELECT_MODULE_MEMORY_CONTROLLER_COLOR             0x08
#define   MWV207REG_PROBE_SELECT_MODULE_MEMORY_CONTROLLER_DEPTH             0x09
#define   MWV207REG_PROBE_SELECT_MODULE_HOST_INTERFACE0                     0x0A
#define   MWV207REG_PROBE_SELECT_MODULE_HOST_INTERFACE1                     0x0B
#define   MWV207REG_PROBE_SELECT_MODULE_GPUL2_CACHE                         0x0C
#define   MWV207REG_PROBE_SELECT_MODULE_WORK_DISTRIBUTOR                    0x0D
#define   MWV207REG_PROBE_SELECT_MODULE_POSITION_PA                         0x0E
#define   MWV207REG_PROBE_SELECT_MODULE_FINAL_PA                            0x0F
#define   MWV207REG_PROBE_SELECT_MODULE_TESS_CTRL_SHADER                    0x10
#define   MWV207REG_PROBE_SELECT_MODULE_TESS_EVAL_SHADER                    0x11
#define   MWV207REG_PROBE_SELECT_MODULE_GEOMETRY_SHADER                     0x12
#define   MWV207REG_PROBE_SELECT_MODULE_TRANSFORM_FEEDBACK                  0x13
#define   MWV207REG_PROBE_SELECT_MODULE_UNIVERSAL_STORAGE                   0x14
#define   MWV207REG_PROBE_SELECT_MODULE_DIRECTORY                           0x15
#define   MWV207REG_PROBE_SELECT_MODULE_BLIT                                0x16


#define MWV207REG_PROBE_SELECT_OP_CODE                                     25:24
#define MWV207REG_PROBE_SELECT_OP_CODE_End                                    25
#define MWV207REG_PROBE_SELECT_OP_CODE_Start                                  24
#define MWV207REG_PROBE_SELECT_OP_CODE_Type                                  U02
#define   MWV207REG_PROBE_SELECT_OP_CODE_PROBE_AND_PASS                      0x0
#define   MWV207REG_PROBE_SELECT_OP_CODE_RESET                               0x1
#define   MWV207REG_PROBE_SELECT_OP_CODE_PAUSE                               0x2
#define   MWV207REG_PROBE_SELECT_OP_CODE_RESUME                              0x3

#define mwv207regToggleSwitchRegAddrs                                     0x0E1F
#define MWV207REG_TOGGLE_SWITCH_Address                                  0x0387C
#define MWV207REG_TOGGLE_SWITCH_MSB                                           15
#define MWV207REG_TOGGLE_SWITCH_LSB                                            0
#define MWV207REG_TOGGLE_SWITCH_BLK                                            0
#define MWV207REG_TOGGLE_SWITCH_Count                                          1
#define MWV207REG_TOGGLE_SWITCH_FieldMask                             0x0000000F
#define MWV207REG_TOGGLE_SWITCH_ReadMask                              0x0000000F
#define MWV207REG_TOGGLE_SWITCH_WriteMask                             0x0000000F
#define MWV207REG_TOGGLE_SWITCH_ResetValue                            0x0000000F


#define MWV207REG_TOGGLE_SWITCH_PA_POS_CLAMP                                 0:0
#define MWV207REG_TOGGLE_SWITCH_PA_POS_CLAMP_End                               0
#define MWV207REG_TOGGLE_SWITCH_PA_POS_CLAMP_Start                             0
#define MWV207REG_TOGGLE_SWITCH_PA_POS_CLAMP_Type                            U01
#define   MWV207REG_TOGGLE_SWITCH_PA_POS_CLAMP_ENABLE                        0x0
#define   MWV207REG_TOGGLE_SWITCH_PA_POS_CLAMP_DISABLE                       0x1


#define MWV207REG_TOGGLE_SWITCH_PA_ATTR_CLAMP                                1:1
#define MWV207REG_TOGGLE_SWITCH_PA_ATTR_CLAMP_End                              1
#define MWV207REG_TOGGLE_SWITCH_PA_ATTR_CLAMP_Start                            1
#define MWV207REG_TOGGLE_SWITCH_PA_ATTR_CLAMP_Type                           U01
#define   MWV207REG_TOGGLE_SWITCH_PA_ATTR_CLAMP_ENABLE                       0x0
#define   MWV207REG_TOGGLE_SWITCH_PA_ATTR_CLAMP_DISABLE                      0x1


#define MWV207REG_TOGGLE_SWITCH_PS_COORD_CLAMP                               2:2
#define MWV207REG_TOGGLE_SWITCH_PS_COORD_CLAMP_End                             2
#define MWV207REG_TOGGLE_SWITCH_PS_COORD_CLAMP_Start                           2
#define MWV207REG_TOGGLE_SWITCH_PS_COORD_CLAMP_Type                          U01
#define   MWV207REG_TOGGLE_SWITCH_PS_COORD_CLAMP_ENABLE                      0x0
#define   MWV207REG_TOGGLE_SWITCH_PS_COORD_CLAMP_DISABLE                     0x1


#define MWV207REG_TOGGLE_SWITCH_SH_COORD_CLAMP                               3:3
#define MWV207REG_TOGGLE_SWITCH_SH_COORD_CLAMP_End                             3
#define MWV207REG_TOGGLE_SWITCH_SH_COORD_CLAMP_Start                           3
#define MWV207REG_TOGGLE_SWITCH_SH_COORD_CLAMP_Type                          U01
#define   MWV207REG_TOGGLE_SWITCH_SH_COORD_CLAMP_ENABLE                      0x0
#define   MWV207REG_TOGGLE_SWITCH_SH_COORD_CLAMP_DISABLE                     0x1

#define mwv207regPerformanceRegAddrs                                      0x0E20
#define MWV207REG_PERFORMANCE_Address                                    0x03880
#define MWV207REG_PERFORMANCE_MSB                                             15
#define MWV207REG_PERFORMANCE_LSB                                              0
#define MWV207REG_PERFORMANCE_BLK                                              0
#define MWV207REG_PERFORMANCE_Count                                            1
#define MWV207REG_PERFORMANCE_FieldMask                               0x000001FB
#define MWV207REG_PERFORMANCE_ReadMask                                0x000001FB
#define MWV207REG_PERFORMANCE_WriteMask                               0x000001FB
#define MWV207REG_PERFORMANCE_ResetValue                              0x00000000


#define MWV207REG_PERFORMANCE_POSITION_ONLY                                  1:0
#define MWV207REG_PERFORMANCE_POSITION_ONLY_End                                1
#define MWV207REG_PERFORMANCE_POSITION_ONLY_Start                              0
#define MWV207REG_PERFORMANCE_POSITION_ONLY_Type                             U02

#define   MWV207REG_PERFORMANCE_POSITION_ONLY_DISABLE                        0x0
#define   MWV207REG_PERFORMANCE_POSITION_ONLY_ENABLE                         0x1
#define   MWV207REG_PERFORMANCE_POSITION_ONLY_ENABLE_IDS                     0x2


#define MWV207REG_PERFORMANCE_MASK_POSITION_ONLY                             3:3
#define MWV207REG_PERFORMANCE_MASK_POSITION_ONLY_End                           3
#define MWV207REG_PERFORMANCE_MASK_POSITION_ONLY_Start                         3
#define MWV207REG_PERFORMANCE_MASK_POSITION_ONLY_Type                        U01
#define   MWV207REG_PERFORMANCE_MASK_POSITION_ONLY_ENABLED                   0x0
#define   MWV207REG_PERFORMANCE_MASK_POSITION_ONLY_MASKED                    0x1


#define MWV207REG_PERFORMANCE_CLUSTER_SIZE                                   7:4
#define MWV207REG_PERFORMANCE_CLUSTER_SIZE_End                                 7
#define MWV207REG_PERFORMANCE_CLUSTER_SIZE_Start                               4
#define MWV207REG_PERFORMANCE_CLUSTER_SIZE_Type                              U04
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT8X8                        0x0
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT16X8                       0x1
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT16X16                      0x2
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT32X16                      0x3
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT32X32                      0x4
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT64X32                      0x5
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT64X64                      0x6
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT128X64                     0x7
#define   MWV207REG_PERFORMANCE_CLUSTER_SIZE_SPLIT128X128                    0x8


#define MWV207REG_PERFORMANCE_MASK_CLUSTER_SIZE                              8:8
#define MWV207REG_PERFORMANCE_MASK_CLUSTER_SIZE_End                            8
#define MWV207REG_PERFORMANCE_MASK_CLUSTER_SIZE_Start                          8
#define MWV207REG_PERFORMANCE_MASK_CLUSTER_SIZE_Type                         U01
#define   MWV207REG_PERFORMANCE_MASK_CLUSTER_SIZE_ENABLED                    0x0
#define   MWV207REG_PERFORMANCE_MASK_CLUSTER_SIZE_MASKED                     0x1



#define mwv207regUSCControlRegAddrs                                       0x0E21
#define MWV207REG_USC_CONTROL_Address                                    0x03884
#define MWV207REG_USC_CONTROL_MSB                                             15
#define MWV207REG_USC_CONTROL_LSB                                              0
#define MWV207REG_USC_CONTROL_BLK                                              0
#define MWV207REG_USC_CONTROL_Count                                            1
#define MWV207REG_USC_CONTROL_FieldMask                               0x007F0F77
#define MWV207REG_USC_CONTROL_ReadMask                                0x007F0F77
#define MWV207REG_USC_CONTROL_WriteMask                               0x007F0F77
#define MWV207REG_USC_CONTROL_ResetValue                              0x00000001

#define MWV207REG_USC_CONTROL_CACHE_PAGES                                    2:0
#define MWV207REG_USC_CONTROL_CACHE_PAGES_End                                  2
#define MWV207REG_USC_CONTROL_CACHE_PAGES_Start                                0
#define MWV207REG_USC_CONTROL_CACHE_PAGES_Type                               U03

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_FULL                             0x0

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_HALF                             0x1

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_QUARTER                          0x2

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_EIGHTH                           0x3

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_SIXTEENTH                        0x4

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_THIRTYSECOND                     0x5

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_THREE_QUARTER                    0x6

#define   MWV207REG_USC_CONTROL_CACHE_PAGES_NONE                             0x7


#define MWV207REG_USC_CONTROL_ORDER_MODE                                     6:4
#define MWV207REG_USC_CONTROL_ORDER_MODE_End                                   6
#define MWV207REG_USC_CONTROL_ORDER_MODE_Start                                 4
#define MWV207REG_USC_CONTROL_ORDER_MODE_Type                                U03

#define   MWV207REG_USC_CONTROL_ORDER_MODE_NORMAL                            0x0
#define   MWV207REG_USC_CONTROL_ORDER_MODE_IN_ORDER_WITH_ATOMIC              0x1

#define   MWV207REG_USC_CONTROL_ORDER_MODE_IN_ORDER_ALWAYS                   0x2
#define   MWV207REG_USC_CONTROL_ORDER_MODE_SINGLE_GROUP_WITH_ATOMIC          0x3

#define   MWV207REG_USC_CONTROL_ORDER_MODE_SINGLE_GROUP_ALWAYS               0x4

#define MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES                            11:8
#define MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_End                          11
#define MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_Start                         8
#define MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_Type                        U04

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_FULL                      0x0

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_HALF                      0x1

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_QUARTER                   0x2

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_EIGHTH                    0x3

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_SIXTEENTH                 0x4

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_THIRTYSECOND              0x5

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_THREE_QUARTER             0x6

#define   MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_NONE                      0x7

#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT                     20:16
#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT_End                    20
#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT_Start                  16
#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT_Type                  U05


#define MWV207REG_USC_CONTROL_ASYNC_COPY256_BYTES_BURST_REQ                21:21
#define MWV207REG_USC_CONTROL_ASYNC_COPY256_BYTES_BURST_REQ_End               21
#define MWV207REG_USC_CONTROL_ASYNC_COPY256_BYTES_BURST_REQ_Start             21
#define MWV207REG_USC_CONTROL_ASYNC_COPY256_BYTES_BURST_REQ_Type             U01
#define   MWV207REG_USC_CONTROL_ASYNC_COPY256_BYTES_BURST_REQ_ENABLE         0x0
#define   MWV207REG_USC_CONTROL_ASYNC_COPY256_BYTES_BURST_REQ_DISABLE        0x1

#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT_BIT5                22:22
#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT_BIT5_End               22
#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT_BIT5_Start             22
#define MWV207REG_USC_CONTROL_MEMORY_CONTROLLER_SELECT_BIT5_Type             U01



#define mwv207regSemanticsRegAddrs                                        0x0E30
#define MWV207REG_SEMANTICS_Address                                      0x038C0
#define MWV207REG_SEMANTICS_MSB                                               15
#define MWV207REG_SEMANTICS_LSB                                                4
#define MWV207REG_SEMANTICS_BLK                                                4
#define MWV207REG_SEMANTICS_Count                                             16
#define MWV207REG_SEMANTICS_FieldMask                                 0xFFFFFFFF
#define MWV207REG_SEMANTICS_ReadMask                                  0xFFFFFFFF
#define MWV207REG_SEMANTICS_WriteMask                                 0xFFFFFFFF
#define MWV207REG_SEMANTICS_ResetValue                                0x00000000


#define MWV207REG_SEMANTICS_INTERPOLATION0_X                                 1:0
#define MWV207REG_SEMANTICS_INTERPOLATION0_X_End                               1
#define MWV207REG_SEMANTICS_INTERPOLATION0_X_Start                             0
#define MWV207REG_SEMANTICS_INTERPOLATION0_X_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION0_X_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION0_X_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION0_X_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION0_X_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION0_X                                      3:2
#define MWV207REG_SEMANTICS_LOCATION0_X_End                                    3
#define MWV207REG_SEMANTICS_LOCATION0_X_Start                                  2
#define MWV207REG_SEMANTICS_LOCATION0_X_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION0_X_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION0_X_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION0_X_SAMPLE                             0x2


#define MWV207REG_SEMANTICS_INTERPOLATION0_Y                                 5:4
#define MWV207REG_SEMANTICS_INTERPOLATION0_Y_End                               5
#define MWV207REG_SEMANTICS_INTERPOLATION0_Y_Start                             4
#define MWV207REG_SEMANTICS_INTERPOLATION0_Y_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Y_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Y_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Y_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Y_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION0_Y                                      7:6
#define MWV207REG_SEMANTICS_LOCATION0_Y_End                                    7
#define MWV207REG_SEMANTICS_LOCATION0_Y_Start                                  6
#define MWV207REG_SEMANTICS_LOCATION0_Y_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION0_Y_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION0_Y_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION0_Y_SAMPLE                             0x2


#define MWV207REG_SEMANTICS_INTERPOLATION0_Z                                 9:8
#define MWV207REG_SEMANTICS_INTERPOLATION0_Z_End                               9
#define MWV207REG_SEMANTICS_INTERPOLATION0_Z_Start                             8
#define MWV207REG_SEMANTICS_INTERPOLATION0_Z_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Z_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Z_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Z_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION0_Z_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION0_Z                                    11:10
#define MWV207REG_SEMANTICS_LOCATION0_Z_End                                   11
#define MWV207REG_SEMANTICS_LOCATION0_Z_Start                                 10
#define MWV207REG_SEMANTICS_LOCATION0_Z_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION0_Z_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION0_Z_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION0_Z_SAMPLE                             0x2


#define MWV207REG_SEMANTICS_INTERPOLATION0_W                               13:12
#define MWV207REG_SEMANTICS_INTERPOLATION0_W_End                              13
#define MWV207REG_SEMANTICS_INTERPOLATION0_W_Start                            12
#define MWV207REG_SEMANTICS_INTERPOLATION0_W_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION0_W_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION0_W_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION0_W_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION0_W_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION0_W                                    15:14
#define MWV207REG_SEMANTICS_LOCATION0_W_End                                   15
#define MWV207REG_SEMANTICS_LOCATION0_W_Start                                 14
#define MWV207REG_SEMANTICS_LOCATION0_W_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION0_W_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION0_W_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION0_W_SAMPLE                             0x2


#define MWV207REG_SEMANTICS_INTERPOLATION1_X                               17:16
#define MWV207REG_SEMANTICS_INTERPOLATION1_X_End                              17
#define MWV207REG_SEMANTICS_INTERPOLATION1_X_Start                            16
#define MWV207REG_SEMANTICS_INTERPOLATION1_X_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION1_X_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION1_X_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION1_X_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION1_X_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION1_X                                    19:18
#define MWV207REG_SEMANTICS_LOCATION1_X_End                                   19
#define MWV207REG_SEMANTICS_LOCATION1_X_Start                                 18
#define MWV207REG_SEMANTICS_LOCATION1_X_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION1_X_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION1_X_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION1_X_SAMPLE                             0x2


#define MWV207REG_SEMANTICS_INTERPOLATION1_Y                               21:20
#define MWV207REG_SEMANTICS_INTERPOLATION1_Y_End                              21
#define MWV207REG_SEMANTICS_INTERPOLATION1_Y_Start                            20
#define MWV207REG_SEMANTICS_INTERPOLATION1_Y_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Y_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Y_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Y_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Y_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION1_Y                                    23:22
#define MWV207REG_SEMANTICS_LOCATION1_Y_End                                   23
#define MWV207REG_SEMANTICS_LOCATION1_Y_Start                                 22
#define MWV207REG_SEMANTICS_LOCATION1_Y_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION1_Y_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION1_Y_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION1_Y_SAMPLE                             0x2


#define MWV207REG_SEMANTICS_INTERPOLATION1_Z                               25:24
#define MWV207REG_SEMANTICS_INTERPOLATION1_Z_End                              25
#define MWV207REG_SEMANTICS_INTERPOLATION1_Z_Start                            24
#define MWV207REG_SEMANTICS_INTERPOLATION1_Z_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Z_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Z_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Z_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION1_Z_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION1_Z                                    27:26
#define MWV207REG_SEMANTICS_LOCATION1_Z_End                                   27
#define MWV207REG_SEMANTICS_LOCATION1_Z_Start                                 26
#define MWV207REG_SEMANTICS_LOCATION1_Z_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION1_Z_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION1_Z_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION1_Z_SAMPLE                             0x2


#define MWV207REG_SEMANTICS_INTERPOLATION1_W                               29:28
#define MWV207REG_SEMANTICS_INTERPOLATION1_W_End                              29
#define MWV207REG_SEMANTICS_INTERPOLATION1_W_Start                            28
#define MWV207REG_SEMANTICS_INTERPOLATION1_W_Type                            U02
#define   MWV207REG_SEMANTICS_INTERPOLATION1_W_SMOOTH                        0x0
#define   MWV207REG_SEMANTICS_INTERPOLATION1_W_NO_PERSPECTIVE                0x1
#define   MWV207REG_SEMANTICS_INTERPOLATION1_W_FLAT                          0x2
#define   MWV207REG_SEMANTICS_INTERPOLATION1_W_INTEGER                       0x3


#define MWV207REG_SEMANTICS_LOCATION1_W                                    31:30
#define MWV207REG_SEMANTICS_LOCATION1_W_End                                   31
#define MWV207REG_SEMANTICS_LOCATION1_W_Start                                 30
#define MWV207REG_SEMANTICS_LOCATION1_W_Type                                 U02
#define   MWV207REG_SEMANTICS_LOCATION1_W_CENTER                             0x0
#define   MWV207REG_SEMANTICS_LOCATION1_W_CENTROID                           0x1
#define   MWV207REG_SEMANTICS_LOCATION1_W_SAMPLE                             0x2




#define mwv207regSemanticLocationRegAddrs                                 0x0E22
#define MWV207REG_SEMANTIC_LOCATION_Address                              0x03888
#define MWV207REG_SEMANTIC_LOCATION_MSB                                       15
#define MWV207REG_SEMANTIC_LOCATION_LSB                                        0
#define MWV207REG_SEMANTIC_LOCATION_BLK                                        0
#define MWV207REG_SEMANTIC_LOCATION_Count                                      1
#define MWV207REG_SEMANTIC_LOCATION_FieldMask                         0x7F7F7F7F
#define MWV207REG_SEMANTIC_LOCATION_ReadMask                          0x7F7F7F7F
#define MWV207REG_SEMANTIC_LOCATION_WriteMask                         0x7F7F7F7F
#define MWV207REG_SEMANTIC_LOCATION_ResetValue                        0x00000000


#define MWV207REG_SEMANTIC_LOCATION_POINT_SIZE                               6:0
#define MWV207REG_SEMANTIC_LOCATION_POINT_SIZE_End                             6
#define MWV207REG_SEMANTIC_LOCATION_POINT_SIZE_Start                           0
#define MWV207REG_SEMANTIC_LOCATION_POINT_SIZE_Type                          U07

#define MWV207REG_SEMANTIC_LOCATION_POINT_COORD                             14:8
#define MWV207REG_SEMANTIC_LOCATION_POINT_COORD_End                           14
#define MWV207REG_SEMANTIC_LOCATION_POINT_COORD_Start                          8
#define MWV207REG_SEMANTIC_LOCATION_POINT_COORD_Type                         U07

#define MWV207REG_SEMANTIC_LOCATION_RENDER_ARRAY                           22:16
#define MWV207REG_SEMANTIC_LOCATION_RENDER_ARRAY_End                          22
#define MWV207REG_SEMANTIC_LOCATION_RENDER_ARRAY_Start                        16
#define MWV207REG_SEMANTIC_LOCATION_RENDER_ARRAY_Type                        U07

#define MWV207REG_SEMANTIC_LOCATION_PRIMITIVE_ID                           30:24
#define MWV207REG_SEMANTIC_LOCATION_PRIMITIVE_ID_End                          30
#define MWV207REG_SEMANTIC_LOCATION_PRIMITIVE_ID_Start                        24
#define MWV207REG_SEMANTIC_LOCATION_PRIMITIVE_ID_Type                        U07




#define mwv207regColorSliceRegAddrs                                       0x0E28
#define MWV207REG_COLOR_SLICE_Address                                    0x038A0
#define MWV207REG_COLOR_SLICE_MSB                                             15
#define MWV207REG_COLOR_SLICE_LSB                                              3
#define MWV207REG_COLOR_SLICE_BLK                                              3
#define MWV207REG_COLOR_SLICE_Count                                            8
#define MWV207REG_COLOR_SLICE_FieldMask                               0x3FFFFFFF
#define MWV207REG_COLOR_SLICE_ReadMask                                0x3FFFFFFF
#define MWV207REG_COLOR_SLICE_WriteMask                               0x3FFFFFFF
#define MWV207REG_COLOR_SLICE_ResetValue                              0x00000000


#define MWV207REG_COLOR_SLICE_SLICE                                         29:0
#define MWV207REG_COLOR_SLICE_SLICE_End                                       29
#define MWV207REG_COLOR_SLICE_SLICE_Start                                      0
#define MWV207REG_COLOR_SLICE_SLICE_Type                                     U30




#define mwv207regDepthSliceRegAddrs                                       0x0E23
#define MWV207REG_DEPTH_SLICE_Address                                    0x0388C
#define MWV207REG_DEPTH_SLICE_MSB                                             15
#define MWV207REG_DEPTH_SLICE_LSB                                              0
#define MWV207REG_DEPTH_SLICE_BLK                                              0
#define MWV207REG_DEPTH_SLICE_Count                                            1
#define MWV207REG_DEPTH_SLICE_FieldMask                               0x1FFFFFFF
#define MWV207REG_DEPTH_SLICE_ReadMask                                0x1FFFFFFF
#define MWV207REG_DEPTH_SLICE_WriteMask                               0x1FFFFFFF
#define MWV207REG_DEPTH_SLICE_ResetValue                              0x00000000


#define MWV207REG_DEPTH_SLICE_SLICE                                         28:0
#define MWV207REG_DEPTH_SLICE_SLICE_End                                       28
#define MWV207REG_DEPTH_SLICE_SLICE_Start                                      0
#define MWV207REG_DEPTH_SLICE_SLICE_Type                                     U29




#define mwv207regShaderL1cFlushOnlyRegAddrs                               0x0E24
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_Address                          0x03890
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_MSB                                   15
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_LSB                                    0
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_BLK                                    0
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_Count                                  1
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_FieldMask                     0x0000001F
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_ReadMask                      0x0000001F
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_WriteMask                     0x0000001F
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_ResetValue                    0x00000000

#define MWV207REG_SHADER_L1C_FLUSH_ONLY_VS                                   0:0
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_VS_End                                 0
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_VS_Start                               0
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_VS_Type                              U01

#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TCS                                  1:1
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TCS_End                                1
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TCS_Start                              1
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TCS_Type                             U01

#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TES                                  2:2
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TES_End                                2
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TES_Start                              2
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_TES_Type                             U01

#define MWV207REG_SHADER_L1C_FLUSH_ONLY_GS                                   3:3
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_GS_End                                 3
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_GS_Start                               3
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_GS_Type                              U01

#define MWV207REG_SHADER_L1C_FLUSH_ONLY_PS                                   4:4
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_PS_End                                 4
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_PS_Start                               4
#define MWV207REG_SHADER_L1C_FLUSH_ONLY_PS_Type                              U01




#define mwv207regShaderL1cFlushWaitRegAddrs                               0x0E25
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_Address                          0x03894
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_MSB                                   15
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_LSB                                    0
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_BLK                                    0
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_Count                                  1
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_FieldMask                     0x0000001F
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_ReadMask                      0x0000001F
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_WriteMask                     0x0000001F
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_ResetValue                    0x00000000

#define MWV207REG_SHADER_L1C_FLUSH_WAIT_VS                                   0:0
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_VS_End                                 0
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_VS_Start                               0
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_VS_Type                              U01

#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TCS                                  1:1
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TCS_End                                1
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TCS_Start                              1
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TCS_Type                             U01

#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TES                                  2:2
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TES_End                                2
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TES_Start                              2
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_TES_Type                             U01

#define MWV207REG_SHADER_L1C_FLUSH_WAIT_GS                                   3:3
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_GS_End                                 3
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_GS_Start                               3
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_GS_Type                              U01

#define MWV207REG_SHADER_L1C_FLUSH_WAIT_PS                                   4:4
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_PS_End                                 4
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_PS_Start                               4
#define MWV207REG_SHADER_L1C_FLUSH_WAIT_PS_Type                              U01




#define mwv207regFenceDataHighRegAddrs                                    0x0E26
#define MWV207REG_FENCE_DATA_HIGH_Address                                0x03898
#define MWV207REG_FENCE_DATA_HIGH_MSB                                         15
#define MWV207REG_FENCE_DATA_HIGH_LSB                                          0
#define MWV207REG_FENCE_DATA_HIGH_BLK                                          0
#define MWV207REG_FENCE_DATA_HIGH_Count                                        1
#define MWV207REG_FENCE_DATA_HIGH_FieldMask                           0xFFFFFFFF
#define MWV207REG_FENCE_DATA_HIGH_ReadMask                            0xFFFFFFFF
#define MWV207REG_FENCE_DATA_HIGH_WriteMask                           0xFFFFFFFF
#define MWV207REG_FENCE_DATA_HIGH_ResetValue                          0x00000000

#define MWV207REG_FENCE_DATA_HIGH_DATA                                      31:0
#define MWV207REG_FENCE_DATA_HIGH_DATA_End                                    31
#define MWV207REG_FENCE_DATA_HIGH_DATA_Start                                   0
#define MWV207REG_FENCE_DATA_HIGH_DATA_Type                                  U32




#define mwv207regDrawIDRegAddrs                                           0x0E27
#define MWV207REG_DRAW_ID_Address                                        0x0389C
#define MWV207REG_DRAW_ID_MSB                                                 15
#define MWV207REG_DRAW_ID_LSB                                                  0
#define MWV207REG_DRAW_ID_BLK                                                  0
#define MWV207REG_DRAW_ID_Count                                                1
#define MWV207REG_DRAW_ID_FieldMask                                   0xFFFFFFFF
#define MWV207REG_DRAW_ID_ReadMask                                    0xFFFFFFFF
#define MWV207REG_DRAW_ID_WriteMask                                   0xFFFFFFFF
#define MWV207REG_DRAW_ID_ResetValue                                  0x00000000

#define MWV207REG_DRAW_ID_DATA                                              31:0
#define MWV207REG_DRAW_ID_DATA_End                                            31
#define MWV207REG_DRAW_ID_DATA_Start                                           0
#define MWV207REG_DRAW_ID_DATA_Type                                          U32




#define mwv207regAPPContextIDLowRegAddrs                                  0x0E40
#define MWV207REG_APP_CONTEXT_ID_LOW_Address                             0x03900
#define MWV207REG_APP_CONTEXT_ID_LOW_MSB                                      15
#define MWV207REG_APP_CONTEXT_ID_LOW_LSB                                       0
#define MWV207REG_APP_CONTEXT_ID_LOW_BLK                                       0
#define MWV207REG_APP_CONTEXT_ID_LOW_Count                                     1
#define MWV207REG_APP_CONTEXT_ID_LOW_FieldMask                        0xFFFFFFFF
#define MWV207REG_APP_CONTEXT_ID_LOW_ReadMask                         0xFFFFFFFF
#define MWV207REG_APP_CONTEXT_ID_LOW_WriteMask                        0xFFFFFFFF
#define MWV207REG_APP_CONTEXT_ID_LOW_ResetValue                       0x00000000

#define MWV207REG_APP_CONTEXT_ID_LOW_ID                                     31:0
#define MWV207REG_APP_CONTEXT_ID_LOW_ID_End                                   31
#define MWV207REG_APP_CONTEXT_ID_LOW_ID_Start                                  0
#define MWV207REG_APP_CONTEXT_ID_LOW_ID_Type                                 U32




#define mwv207regAPPContextIDHighRegAddrs                                 0x0E41
#define MWV207REG_APP_CONTEXT_ID_HIGH_Address                            0x03904
#define MWV207REG_APP_CONTEXT_ID_HIGH_MSB                                     15
#define MWV207REG_APP_CONTEXT_ID_HIGH_LSB                                      0
#define MWV207REG_APP_CONTEXT_ID_HIGH_BLK                                      0
#define MWV207REG_APP_CONTEXT_ID_HIGH_Count                                    1
#define MWV207REG_APP_CONTEXT_ID_HIGH_FieldMask                       0xFFFFFFFF
#define MWV207REG_APP_CONTEXT_ID_HIGH_ReadMask                        0xFFFFFFFF
#define MWV207REG_APP_CONTEXT_ID_HIGH_WriteMask                       0xFFFFFFFF
#define MWV207REG_APP_CONTEXT_ID_HIGH_ResetValue                      0x00000000

#define MWV207REG_APP_CONTEXT_ID_HIGH_ID                                    31:0
#define MWV207REG_APP_CONTEXT_ID_HIGH_ID_End                                  31
#define MWV207REG_APP_CONTEXT_ID_HIGH_ID_Start                                 0
#define MWV207REG_APP_CONTEXT_ID_HIGH_ID_Type                                U32




#define mwv207regClusterControlRegAddrs                                   0x0E44
#define MWV207REG_CLUSTER_CONTROL_Address                                0x03910
#define MWV207REG_CLUSTER_CONTROL_MSB                                         15
#define MWV207REG_CLUSTER_CONTROL_LSB                                          2
#define MWV207REG_CLUSTER_CONTROL_BLK                                          2
#define MWV207REG_CLUSTER_CONTROL_Count                                        4
#define MWV207REG_CLUSTER_CONTROL_FieldMask                           0x000000FF
#define MWV207REG_CLUSTER_CONTROL_ReadMask                            0x000000FF
#define MWV207REG_CLUSTER_CONTROL_WriteMask                           0x000000FF
#define MWV207REG_CLUSTER_CONTROL_ResetValue                          0x000000FF


#define MWV207REG_CLUSTER_CONTROL_CLUSTER_ALIVE_ENABLE                       7:0
#define MWV207REG_CLUSTER_CONTROL_CLUSTER_ALIVE_ENABLE_End                     7
#define MWV207REG_CLUSTER_CONTROL_CLUSTER_ALIVE_ENABLE_Start                   0
#define MWV207REG_CLUSTER_CONTROL_CLUSTER_ALIVE_ENABLE_Type                  U08




#define mwv207regClusterCheckerBoardRegAddrs                              0x0E42
#define MWV207REG_CLUSTER_CHECKER_BOARD_Address                          0x03908
#define MWV207REG_CLUSTER_CHECKER_BOARD_MSB                                   15
#define MWV207REG_CLUSTER_CHECKER_BOARD_LSB                                    0
#define MWV207REG_CLUSTER_CHECKER_BOARD_BLK                                    0
#define MWV207REG_CLUSTER_CHECKER_BOARD_Count                                  1
#define MWV207REG_CLUSTER_CHECKER_BOARD_FieldMask                     0x00000007
#define MWV207REG_CLUSTER_CHECKER_BOARD_ReadMask                      0x00000007
#define MWV207REG_CLUSTER_CHECKER_BOARD_WriteMask                     0x00000007
#define MWV207REG_CLUSTER_CHECKER_BOARD_ResetValue                    0x00000000


#define MWV207REG_CLUSTER_CHECKER_BOARD_SIZE                                 2:0
#define MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_End                               2
#define MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_Start                             0
#define MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_Type                            U03
#define   MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_BLOCK16X16                    0x0
#define   MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_BLOCK16X32                    0x1
#define   MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_BLOCK32X32                    0x2
#define   MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_BLOCK32X64                    0x3
#define   MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_BLOCK64X64                    0x4
#define   MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_BLOCK64X128                   0x5
#define   MWV207REG_CLUSTER_CHECKER_BOARD_SIZE_BLOCK128X128                  0x6




#define mwv207regPowerClusterControlRegAddrs                              0x0E48
#define MWV207REG_POWER_CLUSTER_CONTROL_Address                          0x03920
#define MWV207REG_POWER_CLUSTER_CONTROL_MSB                                   15
#define MWV207REG_POWER_CLUSTER_CONTROL_LSB                                    2
#define MWV207REG_POWER_CLUSTER_CONTROL_BLK                                    2
#define MWV207REG_POWER_CLUSTER_CONTROL_Count                                  4
#define MWV207REG_POWER_CLUSTER_CONTROL_FieldMask                     0x000000FF
#define MWV207REG_POWER_CLUSTER_CONTROL_ReadMask                      0x000000FF
#define MWV207REG_POWER_CLUSTER_CONTROL_WriteMask                     0x000000FF
#define MWV207REG_POWER_CLUSTER_CONTROL_ResetValue                    0x000000FF

#define MWV207REG_POWER_CLUSTER_CONTROL_POWER_CLUSTER_ALIVE                  7:0
#define MWV207REG_POWER_CLUSTER_CONTROL_POWER_CLUSTER_ALIVE_End                7
#define MWV207REG_POWER_CLUSTER_CONTROL_POWER_CLUSTER_ALIVE_Start              0
#define MWV207REG_POWER_CLUSTER_CONTROL_POWER_CLUSTER_ALIVE_Type             U08




#define mwv207regTriggerNNRegAddrs                                        0x0E43
#define MWV207REG_TRIGGER_NN_Address                                     0x0390C
#define MWV207REG_TRIGGER_NN_MSB                                              15
#define MWV207REG_TRIGGER_NN_LSB                                               0
#define MWV207REG_TRIGGER_NN_BLK                                               0
#define MWV207REG_TRIGGER_NN_Count                                             1
#define MWV207REG_TRIGGER_NN_FieldMask                                0x03FFFFFF
#define MWV207REG_TRIGGER_NN_ReadMask                                 0x03FFFFFF
#define MWV207REG_TRIGGER_NN_WriteMask                                0x03FFFFFF
#define MWV207REG_TRIGGER_NN_ResetValue                               0x00000000

#define MWV207REG_TRIGGER_NN_COMMAND_BUFFER_ADDR                            25:0
#define MWV207REG_TRIGGER_NN_COMMAND_BUFFER_ADDR_End                          25
#define MWV207REG_TRIGGER_NN_COMMAND_BUFFER_ADDR_Start                         0
#define MWV207REG_TRIGGER_NN_COMMAND_BUFFER_ADDR_Type                        U26




#define mwv207regConfigNNRegAddrs                                         0x0E4C
#define MWV207REG_CONFIG_NN_Address                                      0x03930
#define MWV207REG_CONFIG_NN_MSB                                               15
#define MWV207REG_CONFIG_NN_LSB                                                0
#define MWV207REG_CONFIG_NN_BLK                                                0
#define MWV207REG_CONFIG_NN_Count                                              1
#define MWV207REG_CONFIG_NN_FieldMask                                 0x1FFFFFFC
#define MWV207REG_CONFIG_NN_ReadMask                                  0x1FFFFFFC
#define MWV207REG_CONFIG_NN_WriteMask                                 0x1FFFFFFC
#define MWV207REG_CONFIG_NN_ResetValue                                0x00800000


#define MWV207REG_CONFIG_NN_ZDPN                                             2:2
#define MWV207REG_CONFIG_NN_ZDPN_End                                           2
#define MWV207REG_CONFIG_NN_ZDPN_Start                                         2
#define MWV207REG_CONFIG_NN_ZDPN_Type                                        U01
#define   MWV207REG_CONFIG_NN_ZDPN_ENABLE                                    0x0
#define   MWV207REG_CONFIG_NN_ZDPN_FORCE_DISABLE                             0x1


#define MWV207REG_CONFIG_NN_SW_TILING                                        3:3
#define MWV207REG_CONFIG_NN_SW_TILING_End                                      3
#define MWV207REG_CONFIG_NN_SW_TILING_Start                                    3
#define MWV207REG_CONFIG_NN_SW_TILING_Type                                   U01
#define   MWV207REG_CONFIG_NN_SW_TILING_ENABLE                               0x0
#define   MWV207REG_CONFIG_NN_SW_TILING_FORCE_DISABLE                        0x1


#define MWV207REG_CONFIG_NN_SMALL_BATCH                                      4:4
#define MWV207REG_CONFIG_NN_SMALL_BATCH_End                                    4
#define MWV207REG_CONFIG_NN_SMALL_BATCH_Start                                  4
#define MWV207REG_CONFIG_NN_SMALL_BATCH_Type                                 U01
#define   MWV207REG_CONFIG_NN_SMALL_BATCH_ENABLE                             0x0
#define   MWV207REG_CONFIG_NN_SMALL_BATCH_DISABLE                            0x1

#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE                                   6:5
#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE_End                                 6
#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE_Start                               5
#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE_Type                              U02
#define   MWV207REG_CONFIG_NN_DDR_BURST_SIZE_SIZE64_B                        0x0
#define   MWV207REG_CONFIG_NN_DDR_BURST_SIZE_SIZE128_B                       0x1
#define   MWV207REG_CONFIG_NN_DDR_BURST_SIZE_SIZE256_B                       0x2
#define   MWV207REG_CONFIG_NN_DDR_BURST_SIZE_SIZE512_B                       0x3


#define MWV207REG_CONFIG_NN_XYDPN                                            7:7
#define MWV207REG_CONFIG_NN_XYDPN_End                                          7
#define MWV207REG_CONFIG_NN_XYDPN_Start                                        7
#define MWV207REG_CONFIG_NN_XYDPN_Type                                       U01
#define   MWV207REG_CONFIG_NN_XYDPN_ENABLE                                   0x0
#define   MWV207REG_CONFIG_NN_XYDPN_FORCE_DISABLE                            0x1

#define MWV207REG_CONFIG_NN_POWER_CONTROL                                   11:8
#define MWV207REG_CONFIG_NN_POWER_CONTROL_End                                 11
#define MWV207REG_CONFIG_NN_POWER_CONTROL_Start                                8
#define MWV207REG_CONFIG_NN_POWER_CONTROL_Type                               U04
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_ALL_ON                           0x0
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_ALL_OFF                          0x1
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_NN_OFF                           0x2
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_ONE_CL_ON                        0x3
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_TWO_CL_ON                        0x4
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_THREE_CL_ON                      0x5
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_FOUR_CL_ON                       0x6
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_FIVE_CL_ON                       0x7
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_SIX_CL_ON                        0x8
#define   MWV207REG_CONFIG_NN_POWER_CONTROL_SEVEN_CL_ON                      0x9


#define MWV207REG_CONFIG_NN_COMMAND_SIZE                                   12:12
#define MWV207REG_CONFIG_NN_COMMAND_SIZE_End                                  12
#define MWV207REG_CONFIG_NN_COMMAND_SIZE_Start                                12
#define MWV207REG_CONFIG_NN_COMMAND_SIZE_Type                                U01
#define   MWV207REG_CONFIG_NN_COMMAND_SIZE_SIZE128_B                         0x0
#define   MWV207REG_CONFIG_NN_COMMAND_SIZE_SIZE192_B                         0x1

#define MWV207REG_CONFIG_NN_AXI_FULL_BANDWIDTH_HIDING                      16:13
#define MWV207REG_CONFIG_NN_AXI_FULL_BANDWIDTH_HIDING_End                     16
#define MWV207REG_CONFIG_NN_AXI_FULL_BANDWIDTH_HIDING_Start                   13
#define MWV207REG_CONFIG_NN_AXI_FULL_BANDWIDTH_HIDING_Type                   U04

#define MWV207REG_CONFIG_NN_KERNEL_STREAM_MAX_COEF_SIZE                    17:17
#define MWV207REG_CONFIG_NN_KERNEL_STREAM_MAX_COEF_SIZE_End                   17
#define MWV207REG_CONFIG_NN_KERNEL_STREAM_MAX_COEF_SIZE_Start                 17
#define MWV207REG_CONFIG_NN_KERNEL_STREAM_MAX_COEF_SIZE_Type                 U01
#define   MWV207REG_CONFIG_NN_KERNEL_STREAM_MAX_COEF_SIZE_ONE_BYTE           0x0
#define   MWV207REG_CONFIG_NN_KERNEL_STREAM_MAX_COEF_SIZE_TWO_BYTES          0x1

#define MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH                20:18
#define MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_End               20
#define MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_Start             18
#define MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_Type             U03
#define   MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_CH1            0x0
#define   MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_CH2            0x1
#define   MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_CH4            0x2
#define   MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_CH8            0x3
#define   MWV207REG_CONFIG_NN_INIMAGE_STREAM_MAX_TRANSPOSE_CH_CH16           0x4

#define MWV207REG_CONFIG_NN_RESERVE_SEC_INIMAGE_STREAM_SPACE               21:21
#define MWV207REG_CONFIG_NN_RESERVE_SEC_INIMAGE_STREAM_SPACE_End              21
#define MWV207REG_CONFIG_NN_RESERVE_SEC_INIMAGE_STREAM_SPACE_Start            21
#define MWV207REG_CONFIG_NN_RESERVE_SEC_INIMAGE_STREAM_SPACE_Type            U01
#define   MWV207REG_CONFIG_NN_RESERVE_SEC_INIMAGE_STREAM_SPACE_DISABLE       0x0
#define   MWV207REG_CONFIG_NN_RESERVE_SEC_INIMAGE_STREAM_SPACE_ENABLE        0x1

#define MWV207REG_CONFIG_NN_KERNEL_SYMBOLE_DECODER_PER_CYCLE               23:22
#define MWV207REG_CONFIG_NN_KERNEL_SYMBOLE_DECODER_PER_CYCLE_End              23
#define MWV207REG_CONFIG_NN_KERNEL_SYMBOLE_DECODER_PER_CYCLE_Start            22
#define MWV207REG_CONFIG_NN_KERNEL_SYMBOLE_DECODER_PER_CYCLE_Type            U02

#define MWV207REG_CONFIG_NN_MIN_AXI_BURST                                  26:24
#define MWV207REG_CONFIG_NN_MIN_AXI_BURST_End                                 26
#define MWV207REG_CONFIG_NN_MIN_AXI_BURST_Start                               24
#define MWV207REG_CONFIG_NN_MIN_AXI_BURST_Type                               U03
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_SIZE16                           0x0
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_SIZE32                           0x1
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_SIZE64                           0x2
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_SIZE128                          0x3
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_SIZE256                          0x4
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_SIZE512                          0x5
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_SIZE1024                         0x6
#define   MWV207REG_CONFIG_NN_MIN_AXI_BURST_AXI_BUS_WIDTH                    0x7

#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE_BIT2                            27:27
#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE_BIT2_End                           27
#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE_BIT2_Start                         27
#define MWV207REG_CONFIG_NN_DDR_BURST_SIZE_BIT2_Type                         U01


#define MWV207REG_CONFIG_NN_COMMAND_SIZE_BIT1                              28:28
#define MWV207REG_CONFIG_NN_COMMAND_SIZE_BIT1_End                             28
#define MWV207REG_CONFIG_NN_COMMAND_SIZE_BIT1_Start                           28
#define MWV207REG_CONFIG_NN_COMMAND_SIZE_BIT1_Type                           U01




#define mwv207regTriggerTPRegAddrs                                        0x0E4D
#define MWV207REG_TRIGGER_TP_Address                                     0x03934
#define MWV207REG_TRIGGER_TP_MSB                                              15
#define MWV207REG_TRIGGER_TP_LSB                                               0
#define MWV207REG_TRIGGER_TP_BLK                                               0
#define MWV207REG_TRIGGER_TP_Count                                             1
#define MWV207REG_TRIGGER_TP_FieldMask                                0x03FFFFFF
#define MWV207REG_TRIGGER_TP_ReadMask                                 0x03FFFFFF
#define MWV207REG_TRIGGER_TP_WriteMask                                0x03FFFFFF
#define MWV207REG_TRIGGER_TP_ResetValue                               0x00000000

#define MWV207REG_TRIGGER_TP_COMMAND_BUFFER_ADDR                            25:0
#define MWV207REG_TRIGGER_TP_COMMAND_BUFFER_ADDR_End                          25
#define MWV207REG_TRIGGER_TP_COMMAND_BUFFER_ADDR_Start                         0
#define MWV207REG_TRIGGER_TP_COMMAND_BUFFER_ADDR_Type                        U26




#define mwv207regSramRemapStartAddressRegAddrs                            0x0E4E
#define MWV207REG_SRAM_REMAP_START_ADDRESS_Address                       0x03938
#define MWV207REG_SRAM_REMAP_START_ADDRESS_MSB                                15
#define MWV207REG_SRAM_REMAP_START_ADDRESS_LSB                                 0
#define MWV207REG_SRAM_REMAP_START_ADDRESS_BLK                                 0
#define MWV207REG_SRAM_REMAP_START_ADDRESS_Count                               1
#define MWV207REG_SRAM_REMAP_START_ADDRESS_FieldMask                  0xFFFFFFFF
#define MWV207REG_SRAM_REMAP_START_ADDRESS_ReadMask                   0xFFFFFFFF
#define MWV207REG_SRAM_REMAP_START_ADDRESS_WriteMask                  0xFFFFFFFF
#define MWV207REG_SRAM_REMAP_START_ADDRESS_ResetValue                 0x00000000

#define MWV207REG_SRAM_REMAP_START_ADDRESS_ADDRESS_VALUE                    31:0
#define MWV207REG_SRAM_REMAP_START_ADDRESS_ADDRESS_VALUE_End                  31
#define MWV207REG_SRAM_REMAP_START_ADDRESS_ADDRESS_VALUE_Start                 0
#define MWV207REG_SRAM_REMAP_START_ADDRESS_ADDRESS_VALUE_Type                U32



#define mwv207regOnChipBufferRemapStartAddressRegAddrs                    0x0E4F
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_Address             0x0393C
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_MSB                      15
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_LSB                       0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_BLK                       0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_Count                     1
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_FieldMask        0xFFFFFFFF
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_ReadMask         0xFFFFFFFF
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_WriteMask        0xFFFFFFFF
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_ResetValue       0x08000000

#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_ADDRESS_VALUE          31:0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_ADDRESS_VALUE_End        31
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_ADDRESS_VALUE_Start       0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_START_ADDRESS_ADDRESS_VALUE_Type      U32



#define mwv207regOnChipBufferRemapEndAddressRegAddrs                      0x0E50
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_Address               0x03940
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_MSB                        15
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_LSB                         0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_BLK                         0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_Count                       1
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_FieldMask          0xFFFFFFFF
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_ReadMask           0xFFFFFFFF
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_WriteMask          0xFFFFFFFF
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_ResetValue         0x08480000

#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_ADDRESS_VALUE            31:0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_ADDRESS_VALUE_End          31
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_ADDRESS_VALUE_Start         0
#define MWV207REG_ON_CHIP_BUFFER_REMAP_END_ADDRESS_ADDRESS_VALUE_Type        U32




#define mwv207regSramImageStreamingBaseAddressRegAddrs                    0x0E51
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_Address              0x03944
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_MSB                       15
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_LSB                        0
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_BLK                        0
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_Count                      1
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_FieldMask         0xFFFFFFFF
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_ReadMask          0xFFFFFFFF
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_WriteMask         0xFFFFFFFF
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_ResetValue        0x00000000

#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_ADDRESS_VALUE           31:0
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_ADDRESS_VALUE_End         31
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_ADDRESS_VALUE_Start        0
#define MWV207REG_SRAM_IMAGE_STREAMING_BASE_ADDRESS_ADDRESS_VALUE_Type       U32




#define mwv207regSramImageStreamingBufferSizeRegAddrs                     0x0E52
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_Address               0x03948
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_MSB                        15
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_LSB                         0
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_BLK                         0
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_Count                       1
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_FieldMask          0xFFFFFFFF
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_ReadMask           0xFFFFFFFF
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_WriteMask          0xFFFFFFFF
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_ResetValue         0x00000000

#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_BUFFER_SIZE              31:0
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_BUFFER_SIZE_End            31
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_BUFFER_SIZE_Start           0
#define MWV207REG_SRAM_IMAGE_STREAMING_BUFFER_SIZE_BUFFER_SIZE_Type          U32




#define mwv207regConfigTPRegAddrs                                         0x0E53
#define MWV207REG_CONFIG_TP_Address                                      0x0394C
#define MWV207REG_CONFIG_TP_MSB                                               15
#define MWV207REG_CONFIG_TP_LSB                                                0
#define MWV207REG_CONFIG_TP_BLK                                                0
#define MWV207REG_CONFIG_TP_Count                                              1
#define MWV207REG_CONFIG_TP_FieldMask                                 0x0000001F
#define MWV207REG_CONFIG_TP_ReadMask                                  0x0000001F
#define MWV207REG_CONFIG_TP_WriteMask                                 0x0000001F
#define MWV207REG_CONFIG_TP_ResetValue                                0x00000000


#define MWV207REG_CONFIG_TP_SMALL_BATCH                                      0:0
#define MWV207REG_CONFIG_TP_SMALL_BATCH_End                                    0
#define MWV207REG_CONFIG_TP_SMALL_BATCH_Start                                  0
#define MWV207REG_CONFIG_TP_SMALL_BATCH_Type                                 U01
#define   MWV207REG_CONFIG_TP_SMALL_BATCH_ENABLE                             0x0
#define   MWV207REG_CONFIG_TP_SMALL_BATCH_DISABLE                            0x1


#define MWV207REG_CONFIG_TP_FULL_OR_FC_ONLY_TP                               1:1
#define MWV207REG_CONFIG_TP_FULL_OR_FC_ONLY_TP_End                             1
#define MWV207REG_CONFIG_TP_FULL_OR_FC_ONLY_TP_Start                           1
#define MWV207REG_CONFIG_TP_FULL_OR_FC_ONLY_TP_Type                          U01

#define   MWV207REG_CONFIG_TP_FULL_OR_FC_ONLY_TP_FULL_TP                     0x0

#define   MWV207REG_CONFIG_TP_FULL_OR_FC_ONLY_TP_FC_ONLY_TP                  0x1


#define MWV207REG_CONFIG_TP_DDR_BURST_SIZE                                   3:2
#define MWV207REG_CONFIG_TP_DDR_BURST_SIZE_End                                 3
#define MWV207REG_CONFIG_TP_DDR_BURST_SIZE_Start                               2
#define MWV207REG_CONFIG_TP_DDR_BURST_SIZE_Type                              U02
#define   MWV207REG_CONFIG_TP_DDR_BURST_SIZE_SIZE64_B                        0x0
#define   MWV207REG_CONFIG_TP_DDR_BURST_SIZE_SIZE128_B                       0x1
#define   MWV207REG_CONFIG_TP_DDR_BURST_SIZE_SIZE256_B                       0x2


#define MWV207REG_CONFIG_TP_COMMAND_SIZE                                     4:4
#define MWV207REG_CONFIG_TP_COMMAND_SIZE_End                                   4
#define MWV207REG_CONFIG_TP_COMMAND_SIZE_Start                                 4
#define MWV207REG_CONFIG_TP_COMMAND_SIZE_Type                                U01
#define   MWV207REG_CONFIG_TP_COMMAND_SIZE_SIZE128_B                         0x0
#define   MWV207REG_CONFIG_TP_COMMAND_SIZE_SIZE192_B                         0x1




#define mwv207regVipFlushRegAddrs                                         0x0E54
#define MWV207REG_VIP_FLUSH_Address                                      0x03950
#define MWV207REG_VIP_FLUSH_MSB                                               15
#define MWV207REG_VIP_FLUSH_LSB                                                0
#define MWV207REG_VIP_FLUSH_BLK                                                0
#define MWV207REG_VIP_FLUSH_Count                                              1
#define MWV207REG_VIP_FLUSH_FieldMask                                 0x0000000F
#define MWV207REG_VIP_FLUSH_ReadMask                                  0x0000000F
#define MWV207REG_VIP_FLUSH_WriteMask                                 0x0000000F
#define MWV207REG_VIP_FLUSH_ResetValue                                0x00000000


#define MWV207REG_VIP_FLUSH_NN_FLUSH_CLIENT_ID                               0:0
#define MWV207REG_VIP_FLUSH_NN_FLUSH_CLIENT_ID_End                             0
#define MWV207REG_VIP_FLUSH_NN_FLUSH_CLIENT_ID_Start                           0
#define MWV207REG_VIP_FLUSH_NN_FLUSH_CLIENT_ID_Type                          U01


#define MWV207REG_VIP_FLUSH_NN_NO_FLUSH                                      1:1
#define MWV207REG_VIP_FLUSH_NN_NO_FLUSH_End                                    1
#define MWV207REG_VIP_FLUSH_NN_NO_FLUSH_Start                                  1
#define MWV207REG_VIP_FLUSH_NN_NO_FLUSH_Type                                 U01


#define MWV207REG_VIP_FLUSH_TP_FLUSH_CLIENT_ID                               2:2
#define MWV207REG_VIP_FLUSH_TP_FLUSH_CLIENT_ID_End                             2
#define MWV207REG_VIP_FLUSH_TP_FLUSH_CLIENT_ID_Start                           2
#define MWV207REG_VIP_FLUSH_TP_FLUSH_CLIENT_ID_Type                          U01


#define MWV207REG_VIP_FLUSH_TP_NO_FLUSH                                      3:3
#define MWV207REG_VIP_FLUSH_TP_NO_FLUSH_End                                    3
#define MWV207REG_VIP_FLUSH_TP_NO_FLUSH_Start                                  3
#define MWV207REG_VIP_FLUSH_TP_NO_FLUSH_Type                                 U01




#define mwv207regProbeSelectExtendRegAddrs                                0x0E55
#define MWV207REG_PROBE_SELECT_EXTEND_Address                            0x03954
#define MWV207REG_PROBE_SELECT_EXTEND_MSB                                     15
#define MWV207REG_PROBE_SELECT_EXTEND_LSB                                      0
#define MWV207REG_PROBE_SELECT_EXTEND_BLK                                      0
#define MWV207REG_PROBE_SELECT_EXTEND_Count                                    1
#define MWV207REG_PROBE_SELECT_EXTEND_FieldMask                       0x030FFFFF
#define MWV207REG_PROBE_SELECT_EXTEND_ReadMask                        0x030FFFFF
#define MWV207REG_PROBE_SELECT_EXTEND_WriteMask                       0x030FFFFF
#define MWV207REG_PROBE_SELECT_EXTEND_ResetValue                      0x00000000


#define MWV207REG_PROBE_SELECT_EXTEND_COUNTER                               15:0
#define MWV207REG_PROBE_SELECT_EXTEND_COUNTER_End                             15
#define MWV207REG_PROBE_SELECT_EXTEND_COUNTER_Start                            0
#define MWV207REG_PROBE_SELECT_EXTEND_COUNTER_Type                           U16

#define MWV207REG_PROBE_SELECT_EXTEND_MODULE                               19:16
#define MWV207REG_PROBE_SELECT_EXTEND_MODULE_End                              19
#define MWV207REG_PROBE_SELECT_EXTEND_MODULE_Start                            16
#define MWV207REG_PROBE_SELECT_EXTEND_MODULE_Type                            U04
#define   MWV207REG_PROBE_SELECT_EXTEND_MODULE_NEURAL_NET                    0x0
#define   MWV207REG_PROBE_SELECT_EXTEND_MODULE_TENSOR_PROCESSOR              0x1


#define MWV207REG_PROBE_SELECT_EXTEND_OP_CODE                              25:24
#define MWV207REG_PROBE_SELECT_EXTEND_OP_CODE_End                             25
#define MWV207REG_PROBE_SELECT_EXTEND_OP_CODE_Start                           24
#define MWV207REG_PROBE_SELECT_EXTEND_OP_CODE_Type                           U02
#define   MWV207REG_PROBE_SELECT_EXTEND_OP_CODE_PROBE_AND_PASS               0x0
#define   MWV207REG_PROBE_SELECT_EXTEND_OP_CODE_RESET                        0x1
#define   MWV207REG_PROBE_SELECT_EXTEND_OP_CODE_PAUSE                        0x2
#define   MWV207REG_PROBE_SELECT_EXTEND_OP_CODE_RESUME                       0x3




#define mwv207regAXISramRemapVirtualStartAddressRegAddrs                  0x0E56
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_Address           0x03958
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_MSB                    15
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_LSB                     0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_BLK                     0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_Count                   1
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_FieldMask      0xFFFFFFFF
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_ReadMask       0xFFFFFFFF
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_WriteMask      0xFFFFFFFF
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_ResetValue     0x00000000

#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_ADDRESS_VALUE        31:0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_ADDRESS_VALUE_End      31
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_ADDRESS_VALUE_Start     0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_START_ADDRESS_ADDRESS_VALUE_Type    U32




#define mwv207regAXISramRemapVirtualEndAddressRegAddrs                    0x0E57
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_Address             0x0395C
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_MSB                      15
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_LSB                       0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_BLK                       0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_Count                     1
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_FieldMask        0xFFFFFFFF
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_ReadMask         0xFFFFFFFF
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_WriteMask        0xFFFFFFFF
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_ResetValue       0x00000000

#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_ADDRESS_VALUE          31:0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_ADDRESS_VALUE_End        31
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_ADDRESS_VALUE_Start       0
#define MWV207REG_AXI_SRAM_REMAP_VIRTUAL_END_ADDRESS_ADDRESS_VALUE_Type      U32




#define mwv207regStencilSliceRegAddrs                                     0x0E58
#define MWV207REG_STENCIL_SLICE_Address                                  0x03960
#define MWV207REG_STENCIL_SLICE_MSB                                           15
#define MWV207REG_STENCIL_SLICE_LSB                                            0
#define MWV207REG_STENCIL_SLICE_BLK                                            0
#define MWV207REG_STENCIL_SLICE_Count                                          1
#define MWV207REG_STENCIL_SLICE_FieldMask                             0x1FFFFFFF
#define MWV207REG_STENCIL_SLICE_ReadMask                              0x1FFFFFFF
#define MWV207REG_STENCIL_SLICE_WriteMask                             0x1FFFFFFF
#define MWV207REG_STENCIL_SLICE_ResetValue                            0x00000000


#define MWV207REG_STENCIL_SLICE_SLICE                                       28:0
#define MWV207REG_STENCIL_SLICE_SLICE_End                                     28
#define MWV207REG_STENCIL_SLICE_SLICE_Start                                    0
#define MWV207REG_STENCIL_SLICE_SLICE_Type                                   U29

#define mwv207regVIP40BitsVaRegAddrs                                      0x0E59
#define MWV207REG_VIP40_BITS_VA_Address                                  0x03964
#define MWV207REG_VIP40_BITS_VA_MSB                                           15
#define MWV207REG_VIP40_BITS_VA_LSB                                            0
#define MWV207REG_VIP40_BITS_VA_BLK                                            0
#define MWV207REG_VIP40_BITS_VA_Count                                          1
#define MWV207REG_VIP40_BITS_VA_FieldMask                             0xFFFFFFFF
#define MWV207REG_VIP40_BITS_VA_ReadMask                              0xFFFFFFFF
#define MWV207REG_VIP40_BITS_VA_WriteMask                             0xFFFFFFFF
#define MWV207REG_VIP40_BITS_VA_ResetValue                            0x00000000

#define MWV207REG_VIP40_BITS_VA_SRAM_REMAP_START_BIT39_TO32                  7:0
#define MWV207REG_VIP40_BITS_VA_SRAM_REMAP_START_BIT39_TO32_End                7
#define MWV207REG_VIP40_BITS_VA_SRAM_REMAP_START_BIT39_TO32_Start              0
#define MWV207REG_VIP40_BITS_VA_SRAM_REMAP_START_BIT39_TO32_Type             U08

#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_START_ADDR_BIT39_TO32             15:8
#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_START_ADDR_BIT39_TO32_End           15
#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_START_ADDR_BIT39_TO32_Start          8
#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_START_ADDR_BIT39_TO32_Type         U08

#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_END_ADDR_BIT39_TO32              23:16
#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_END_ADDR_BIT39_TO32_End             23
#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_END_ADDR_BIT39_TO32_Start           16
#define MWV207REG_VIP40_BITS_VA_OCB_REMAP_END_ADDR_BIT39_TO32_Type           U08


#define MWV207REG_VIP40_BITS_VA_PROBE_ADDRESS_BIT39_TO32                   31:24
#define MWV207REG_VIP40_BITS_VA_PROBE_ADDRESS_BIT39_TO32_End                  31
#define MWV207REG_VIP40_BITS_VA_PROBE_ADDRESS_BIT39_TO32_Start                24
#define MWV207REG_VIP40_BITS_VA_PROBE_ADDRESS_BIT39_TO32_Type                U08



#define mwv207regVIPMiscRegAddrs                                          0x0E5A
#define MWV207REG_VIP_MISC_Address                                       0x03968
#define MWV207REG_VIP_MISC_MSB                                                15
#define MWV207REG_VIP_MISC_LSB                                                 0
#define MWV207REG_VIP_MISC_BLK                                                 0
#define MWV207REG_VIP_MISC_Count                                               1
#define MWV207REG_VIP_MISC_FieldMask                                  0x00FFFFFF
#define MWV207REG_VIP_MISC_ReadMask                                   0x00FFFFFF
#define MWV207REG_VIP_MISC_WriteMask                                  0x00FFFFFF
#define MWV207REG_VIP_MISC_ResetValue                                 0x00000000


#define MWV207REG_VIP_MISC_NN_QUICK_RESET                                    0:0
#define MWV207REG_VIP_MISC_NN_QUICK_RESET_End                                  0
#define MWV207REG_VIP_MISC_NN_QUICK_RESET_Start                                0
#define MWV207REG_VIP_MISC_NN_QUICK_RESET_Type                               U01
#define   MWV207REG_VIP_MISC_NN_QUICK_RESET_DISABLED                         0x0
#define   MWV207REG_VIP_MISC_NN_QUICK_RESET_ENABLED                          0x1

#define MWV207REG_VIP_MISC_NN_BW_PATTERN_CONTROL_NUM                         4:1
#define MWV207REG_VIP_MISC_NN_BW_PATTERN_CONTROL_NUM_End                       4
#define MWV207REG_VIP_MISC_NN_BW_PATTERN_CONTROL_NUM_Start                     1
#define MWV207REG_VIP_MISC_NN_BW_PATTERN_CONTROL_NUM_Type                    U04


#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1                            7:5
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_End                          7
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_Start                        5
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_Type                       U03
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_SIZE64_B                 0x0
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_SIZE128_B                0x1
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_SIZE256_B                0x2
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_SIZE512_B                0x3
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_SIZE1024_B               0x4
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID1_AXI_BUS_WIDTH            0x7


#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1                                10:8
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_End                              10
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_Start                             8
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_Type                            U03
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_SIZE16_B                      0x0
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_SIZE32_B                      0x1
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_SIZE64_B                      0x2
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_SIZE128_B                     0x3
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_SIZE256_B                     0x4
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_SIZE512_B                     0x5
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_SIZE1024_B                    0x6
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID1_AXI_BUS_WIDTH                 0x7


#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2                          13:11
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_End                         13
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_Start                       11
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_Type                       U03
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_SIZE64_B                 0x0
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_SIZE128_B                0x1
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_SIZE256_B                0x2
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_SIZE512_B                0x3
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_SIZE1024_B               0x4
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID2_AXI_BUS_WIDTH            0x7


#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2                               16:14
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_End                              16
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_Start                            14
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_Type                            U03
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_SIZE16_B                      0x0
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_SIZE32_B                      0x1
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_SIZE64_B                      0x2
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_SIZE128_B                     0x3
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_SIZE256_B                     0x4
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_SIZE512_B                     0x5
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_SIZE1024_B                    0x6
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID2_AXI_BUS_WIDTH                 0x7


#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3                          19:17
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_End                         19
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_Start                       17
#define MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_Type                       U03
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_SIZE64_B                 0x0
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_SIZE128_B                0x1
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_SIZE256_B                0x2
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_SIZE512_B                0x3
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_SIZE1024_B               0x4
#define   MWV207REG_VIP_MISC_DDR_BURST_SIZE_AXI_ID3_AXI_BUS_WIDTH            0x7


#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3                               23:20
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_End                              23
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_Start                            20
#define MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_Type                            U04
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_SIZE16_B                      0x0
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_SIZE32_B                      0x1
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_SIZE64_B                      0x2
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_SIZE128_B                     0x3
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_SIZE256_B                     0x4
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_SIZE512_B                     0x5
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_SIZE1024_B                    0x6
#define   MWV207REG_VIP_MISC_MIN_AXI_BURST_ID3_AXI_BUS_WIDTH                 0x7



#define mwv207regSPInstrMemAddrRegAddrs                                   0x0E5B
#define MWV207REG_SP_INSTR_MEM_ADDR_Address                              0x0396C
#define MWV207REG_SP_INSTR_MEM_ADDR_MSB                                       15
#define MWV207REG_SP_INSTR_MEM_ADDR_LSB                                        0
#define MWV207REG_SP_INSTR_MEM_ADDR_BLK                                        0
#define MWV207REG_SP_INSTR_MEM_ADDR_Count                                      1
#define MWV207REG_SP_INSTR_MEM_ADDR_FieldMask                         0x000000FF
#define MWV207REG_SP_INSTR_MEM_ADDR_ReadMask                          0x000000FF
#define MWV207REG_SP_INSTR_MEM_ADDR_WriteMask                         0x000000FF
#define MWV207REG_SP_INSTR_MEM_ADDR_ResetValue                        0x00000000


#define MWV207REG_SP_INSTR_MEM_ADDR_ADDR                                     7:0
#define MWV207REG_SP_INSTR_MEM_ADDR_ADDR_End                                   7
#define MWV207REG_SP_INSTR_MEM_ADDR_ADDR_Start                                 0
#define MWV207REG_SP_INSTR_MEM_ADDR_ADDR_Type                                U08




#define mwv207regSPInstrMemDataLowRegAddrs                                0x0E5C
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_Address                          0x03970
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_MSB                                   15
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_LSB                                    0
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_BLK                                    0
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_Count                                  1
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_FieldMask                     0xFFFFFFFF
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_ReadMask                      0xFFFFFFFF
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_WriteMask                     0xFFFFFFFF
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_ResetValue                    0x00000000

#define MWV207REG_SP_INSTR_MEM_DATA_LOW_DATA                                31:0
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_DATA_End                              31
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_DATA_Start                             0
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_DATA_Type                            U32

#define mwv207regSPInstrMemDataHighRegAddrs                               0x0E5D
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_Address                         0x03974
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_MSB                                  15
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_LSB                                   0
#define MWV207REG_SP_INSTR_MEM_DATA_LOW_HIGH_BLK                               0
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_Count                                 1
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_FieldMask                    0xFFFFFFFF
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_ReadMask                     0xFFFFFFFF
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_WriteMask                    0xFFFFFFFF
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_ResetValue                   0x00000000

#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_DATA                               31:0
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_DATA_End                             31
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_DATA_Start                            0
#define MWV207REG_SP_INSTR_MEM_DATA_HIGH_DATA_Type                           U32




#define mwv207regClusterControl1RegAddrs                                  0x0E60
#define MWV207REG_CLUSTER_CONTROL1_Address                               0x03980
#define MWV207REG_CLUSTER_CONTROL1_MSB                                        15
#define MWV207REG_CLUSTER_CONTROL1_LSB                                         2
#define MWV207REG_CLUSTER_CONTROL1_BLK                                         2
#define MWV207REG_CLUSTER_CONTROL1_Count                                       4
#define MWV207REG_CLUSTER_CONTROL1_FieldMask                          0x000000FF
#define MWV207REG_CLUSTER_CONTROL1_ReadMask                           0x000000FF
#define MWV207REG_CLUSTER_CONTROL1_WriteMask                          0x000000FF
#define MWV207REG_CLUSTER_CONTROL1_ResetValue                         0x000000FF


#define MWV207REG_CLUSTER_CONTROL1_CLUSTER_ALIVE_ENABLE                      7:0
#define MWV207REG_CLUSTER_CONTROL1_CLUSTER_ALIVE_ENABLE_End                    7
#define MWV207REG_CLUSTER_CONTROL1_CLUSTER_ALIVE_ENABLE_Start                  0
#define MWV207REG_CLUSTER_CONTROL1_CLUSTER_ALIVE_ENABLE_Type                 U08




#define mwv207regPowerClusterControl1RegAddrs                             0x0E64
#define MWV207REG_POWER_CLUSTER_CONTROL1_Address                         0x03990
#define MWV207REG_POWER_CLUSTER_CONTROL1_MSB                                  15
#define MWV207REG_POWER_CLUSTER_CONTROL1_LSB                                   2
#define MWV207REG_POWER_CLUSTER_CONTROL1_BLK                                   2
#define MWV207REG_POWER_CLUSTER_CONTROL1_Count                                 4
#define MWV207REG_POWER_CLUSTER_CONTROL1_FieldMask                    0x000000FF
#define MWV207REG_POWER_CLUSTER_CONTROL1_ReadMask                     0x000000FF
#define MWV207REG_POWER_CLUSTER_CONTROL1_WriteMask                    0x000000FF
#define MWV207REG_POWER_CLUSTER_CONTROL1_ResetValue                   0x000000FF

#define MWV207REG_POWER_CLUSTER_CONTROL1_POWER_CLUSTER_ALIVE                 7:0
#define MWV207REG_POWER_CLUSTER_CONTROL1_POWER_CLUSTER_ALIVE_End               7
#define MWV207REG_POWER_CLUSTER_CONTROL1_POWER_CLUSTER_ALIVE_Start             0
#define MWV207REG_POWER_CLUSTER_CONTROL1_POWER_CLUSTER_ALIVE_Type            U08



#define mwv207regCmdLoopNnCmdIterationRegAddrs                            0x0E5E
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_Address                      0x03978
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_MSB                               15
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_LSB                                0
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_BLK                                0
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_Count                              1
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_FieldMask                 0x0000FFFF
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_ReadMask                  0x0000FFFF
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_WriteMask                 0x0000FFFF
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_ResetValue                0x00000000

#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_VALUE                           15:0
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_VALUE_End                         15
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_VALUE_Start                        0
#define MWV207REG_CMD_LOOP_NN_CMD_ITERATION_VALUE_Type                       U16



#define mwv207regCmdLoopNnRegionBaseAddr0RegAddrs                         0x0E5F
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_Address                  0x0397C
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_MSB                           15
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_LSB                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_BLK                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_Count                          1
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_FieldMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_ReadMask              0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_WriteMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_ResetValue            0x00000000

#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_VALUE                       31:0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_VALUE_End                     31
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_VALUE_Start                    0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR0_VALUE_Type                   U32



#define mwv207regCmdLoopNnRegionBaseAddr1RegAddrs                         0x0E68
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_Address                  0x039A0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_MSB                           15
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_LSB                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_BLK                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_Count                          1
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_FieldMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_ReadMask              0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_WriteMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_ResetValue            0x00000000

#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_VALUE                       31:0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_VALUE_End                     31
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_VALUE_Start                    0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR1_VALUE_Type                   U32



#define mwv207regCmdLoopNnRegionBaseAddr2RegAddrs                         0x0E69
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_Address                  0x039A4
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_MSB                           15
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_LSB                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_BLK                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_Count                          1
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_FieldMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_ReadMask              0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_WriteMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_ResetValue            0x00000000

#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_VALUE                       31:0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_VALUE_End                     31
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_VALUE_Start                    0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR2_VALUE_Type                   U32



#define mwv207regCmdLoopNnRegionBaseAddr3RegAddrs                         0x0E6A
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_Address                  0x039A8
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_MSB                           15
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_LSB                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_BLK                            0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_Count                          1
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_FieldMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_ReadMask              0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_WriteMask             0xFFFFFFFF
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_ResetValue            0x00000000

#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_VALUE                       31:0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_VALUE_End                     31
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_VALUE_Start                    0
#define MWV207REG_CMD_LOOP_NN_REGION_BASE_ADDR3_VALUE_Type                   U32



#define mwv207regVIPClockGateRegAddrs                                     0x0E6B
#define MWV207REG_VIP_CLOCK_GATE_Address                                 0x039AC
#define MWV207REG_VIP_CLOCK_GATE_MSB                                          15
#define MWV207REG_VIP_CLOCK_GATE_LSB                                           0
#define MWV207REG_VIP_CLOCK_GATE_BLK                                           0
#define MWV207REG_VIP_CLOCK_GATE_Count                                         1
#define MWV207REG_VIP_CLOCK_GATE_FieldMask                            0xF8FFFFFE
#define MWV207REG_VIP_CLOCK_GATE_ReadMask                             0xF8FFFFFE
#define MWV207REG_VIP_CLOCK_GATE_WriteMask                            0xF8FFFFFE
#define MWV207REG_VIP_CLOCK_GATE_ResetValue                           0x00000000


#define MWV207REG_VIP_CLOCK_GATE_TOP_CMD_PARSER                              1:1
#define MWV207REG_VIP_CLOCK_GATE_TOP_CMD_PARSER_End                            1
#define MWV207REG_VIP_CLOCK_GATE_TOP_CMD_PARSER_Start                          1
#define MWV207REG_VIP_CLOCK_GATE_TOP_CMD_PARSER_Type                         U01


#define MWV207REG_VIP_CLOCK_GATE_KRNL_REQ                                    2:2
#define MWV207REG_VIP_CLOCK_GATE_KRNL_REQ_End                                  2
#define MWV207REG_VIP_CLOCK_GATE_KRNL_REQ_Start                                2
#define MWV207REG_VIP_CLOCK_GATE_KRNL_REQ_Type                               U01


#define MWV207REG_VIP_CLOCK_GATE_IMG_REQ_HANDLE                              3:3
#define MWV207REG_VIP_CLOCK_GATE_IMG_REQ_HANDLE_End                            3
#define MWV207REG_VIP_CLOCK_GATE_IMG_REQ_HANDLE_Start                          3
#define MWV207REG_VIP_CLOCK_GATE_IMG_REQ_HANDLE_Type                         U01


#define MWV207REG_VIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL                    4:4
#define MWV207REG_VIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL_End                  4
#define MWV207REG_VIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL_Start                4
#define MWV207REG_VIP_CLOCK_GATE_DATA_SHFT_VL_MT_BUF_CTRL_Type               U01


#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_WR                             5:5
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_WR_End                           5
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_WR_Start                         5
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_WR_Type                        U01


#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP                         6:6
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP_End                       6
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP_Start                     6
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_TOP_Type                    U01


#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD                     7:7
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD_End                   7
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD_Start                 7
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_RD_KNRL_RD_Type                U01


#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD                    8:8
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD_End                  8
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD_Start                8
#define MWV207REG_VIP_CLOCK_GATE_PE_SRAM_INTF_IMG_IMG2_RD_Type               U01


#define MWV207REG_VIP_CLOCK_GATE_PP_TOP_PIPE_TOP                             9:9
#define MWV207REG_VIP_CLOCK_GATE_PP_TOP_PIPE_TOP_End                           9
#define MWV207REG_VIP_CLOCK_GATE_PP_TOP_PIPE_TOP_Start                         9
#define MWV207REG_VIP_CLOCK_GATE_PP_TOP_PIPE_TOP_Type                        U01


#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP1                                  10:10
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP1_End                                 10
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP1_Start                               10
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP1_Type                               U01


#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2                                  11:11
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2_End                                 11
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2_Start                               11
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2_Type                               U01


#define MWV207REG_VIP_CLOCK_GATE_PP_BST_COL                                12:12
#define MWV207REG_VIP_CLOCK_GATE_PP_BST_COL_End                               12
#define MWV207REG_VIP_CLOCK_GATE_PP_BST_COL_Start                             12
#define MWV207REG_VIP_CLOCK_GATE_PP_BST_COL_Type                             U01


#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2_DMA                              13:13
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2_DMA_End                             13
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2_DMA_Start                           13
#define MWV207REG_VIP_CLOCK_GATE_PP_TRSP2_DMA_Type                           U01

#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT     14:14
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT_End    14
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT_Start  14
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_POST_STRM_DIS_POST_ADD_I16_FMT_Type  U01

#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP           15:15
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP_End          15
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP_Start        15
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_WSF2_FP32_POOL_POOL_FLOP_Type        U01

#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD       16:16
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD_End      16
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD_Start    16
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_INT2_FP_POST_MULT_TENSOR_ADD_Type    U01


#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT              17:17
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT_End             17
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT_Start           17
#define MWV207REG_VIP_CLOCK_GATE_PP_PIP_NN_ALU_CONVER_PIP_OUT_Type           U01


#define MWV207REG_VIP_CLOCK_GATE_CP_TOP_CONV_CORE                          18:18
#define MWV207REG_VIP_CLOCK_GATE_CP_TOP_CONV_CORE_End                         18
#define MWV207REG_VIP_CLOCK_GATE_CP_TOP_CONV_CORE_Start                       18
#define MWV207REG_VIP_CLOCK_GATE_CP_TOP_CONV_CORE_Type                       U01


#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_WR_RD                          19:19
#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_WR_RD_End                         19
#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_WR_RD_Start                       19
#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_WR_RD_Type                       U01


#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_OUT                            20:20
#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_OUT_End                           20
#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_OUT_Start                         20
#define MWV207REG_VIP_CLOCK_GATE_CP_IMG_BUF_OUT_Type                         U01


#define MWV207REG_VIP_CLOCK_GATE_CC_DECOMP                                 21:21
#define MWV207REG_VIP_CLOCK_GATE_CC_DECOMP_End                                21
#define MWV207REG_VIP_CLOCK_GATE_CC_DECOMP_Start                              21
#define MWV207REG_VIP_CLOCK_GATE_CC_DECOMP_Type                              U01

#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG 22:22
#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG_End 22
#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG_Start 22
#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_MULT_OUT_REG_ADD_OUT_REG_ACCUM_RD_REG_Type U01


#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO                        23:23
#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO_End                       23
#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO_Start                     23
#define MWV207REG_VIP_CLOCK_GATE_CC_SEQ_OUTPUT_INFO_Type                     U01


#define MWV207REG_VIP_CLOCK_GATE_VIP_GATING                                27:27
#define MWV207REG_VIP_CLOCK_GATE_VIP_GATING_End                               27
#define MWV207REG_VIP_CLOCK_GATE_VIP_GATING_Start                             27
#define MWV207REG_VIP_CLOCK_GATE_VIP_GATING_Type                             U01


#define MWV207REG_VIP_CLOCK_GATE_DEEP_SLEEP                                28:28
#define MWV207REG_VIP_CLOCK_GATE_DEEP_SLEEP_End                               28
#define MWV207REG_VIP_CLOCK_GATE_DEEP_SLEEP_Start                             28
#define MWV207REG_VIP_CLOCK_GATE_DEEP_SLEEP_Type                             U01


#define MWV207REG_VIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING                  29:29
#define MWV207REG_VIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING_End                 29
#define MWV207REG_VIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING_Start               29
#define MWV207REG_VIP_CLOCK_GATE_OCM_RELATED_FLOPS_GATING_Type               U01


#define MWV207REG_VIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS                     30:30
#define MWV207REG_VIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS_End                    30
#define MWV207REG_VIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS_Start                  30
#define MWV207REG_VIP_CLOCK_GATE_DMA5_VIP_AND4_SUB_SYS_Type                  U01


#define MWV207REG_VIP_CLOCK_GATE_SH_USC_RELATED                            31:31
#define MWV207REG_VIP_CLOCK_GATE_SH_USC_RELATED_End                           31
#define MWV207REG_VIP_CLOCK_GATE_SH_USC_RELATED_Start                         31
#define MWV207REG_VIP_CLOCK_GATE_SH_USC_RELATED_Type                         U01




#define mwv207regCullDistanceLocation0RegAddrs                            0x0E6C
#define MWV207REG_CULL_DISTANCE_LOCATION0_Address                        0x039B0
#define MWV207REG_CULL_DISTANCE_LOCATION0_MSB                                 15
#define MWV207REG_CULL_DISTANCE_LOCATION0_LSB                                  0
#define MWV207REG_CULL_DISTANCE_LOCATION0_BLK                                  0
#define MWV207REG_CULL_DISTANCE_LOCATION0_Count                                1
#define MWV207REG_CULL_DISTANCE_LOCATION0_FieldMask                   0x7F7F7F7F
#define MWV207REG_CULL_DISTANCE_LOCATION0_ReadMask                    0x7F7F7F7F
#define MWV207REG_CULL_DISTANCE_LOCATION0_WriteMask                   0x7F7F7F7F
#define MWV207REG_CULL_DISTANCE_LOCATION0_ResetValue                  0x00000000


#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_X                        6:0
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_X_End                      6
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_X_Start                    0
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_X_Type                   U07


#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Y                       14:8
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Y_End                     14
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Y_Start                    8
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Y_Type                   U07


#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Z                      22:16
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Z_End                     22
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Z_Start                   16
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_Z_Type                   U07


#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_W                      30:24
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_W_End                     30
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_W_Start                   24
#define MWV207REG_CULL_DISTANCE_LOCATION0_LOCATION0_W_Type                   U07




#define mwv207regCullDistanceLocation1RegAddrs                            0x0E6D
#define MWV207REG_CULL_DISTANCE_LOCATION1_Address                        0x039B4
#define MWV207REG_CULL_DISTANCE_LOCATION1_MSB                                 15
#define MWV207REG_CULL_DISTANCE_LOCATION1_LSB                                  0
#define MWV207REG_CULL_DISTANCE_LOCATION1_BLK                                  0
#define MWV207REG_CULL_DISTANCE_LOCATION1_Count                                1
#define MWV207REG_CULL_DISTANCE_LOCATION1_FieldMask                   0x7F7F7F7F
#define MWV207REG_CULL_DISTANCE_LOCATION1_ReadMask                    0x7F7F7F7F
#define MWV207REG_CULL_DISTANCE_LOCATION1_WriteMask                   0x7F7F7F7F
#define MWV207REG_CULL_DISTANCE_LOCATION1_ResetValue                  0x00000000


#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_X                        6:0
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_X_End                      6
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_X_Start                    0
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_X_Type                   U07


#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Y                       14:8
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Y_End                     14
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Y_Start                    8
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Y_Type                   U07


#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Z                      22:16
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Z_End                     22
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Z_Start                   16
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_Z_Type                   U07


#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_W                      30:24
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_W_End                     30
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_W_Start                   24
#define MWV207REG_CULL_DISTANCE_LOCATION1_LOCATION1_W_Type                   U07




#define mwv207regClipDistanceLocation0RegAddrs                            0x0E6E
#define MWV207REG_CLIP_DISTANCE_LOCATION0_Address                        0x039B8
#define MWV207REG_CLIP_DISTANCE_LOCATION0_MSB                                 15
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LSB                                  0
#define MWV207REG_CLIP_DISTANCE_LOCATION0_BLK                                  0
#define MWV207REG_CLIP_DISTANCE_LOCATION0_Count                                1
#define MWV207REG_CLIP_DISTANCE_LOCATION0_FieldMask                   0x7F7F7F7F
#define MWV207REG_CLIP_DISTANCE_LOCATION0_ReadMask                    0x7F7F7F7F
#define MWV207REG_CLIP_DISTANCE_LOCATION0_WriteMask                   0x7F7F7F7F
#define MWV207REG_CLIP_DISTANCE_LOCATION0_ResetValue                  0x00000000


#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_X                        6:0
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_X_End                      6
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_X_Start                    0
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_X_Type                   U07


#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Y                       14:8
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Y_End                     14
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Y_Start                    8
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Y_Type                   U07


#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Z                      22:16
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Z_End                     22
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Z_Start                   16
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_Z_Type                   U07


#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_W                      30:24
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_W_End                     30
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_W_Start                   24
#define MWV207REG_CLIP_DISTANCE_LOCATION0_LOCATION0_W_Type                   U07




#define mwv207regClipDistanceLocation1RegAddrs                            0x0E6F
#define MWV207REG_CLIP_DISTANCE_LOCATION1_Address                        0x039BC
#define MWV207REG_CLIP_DISTANCE_LOCATION1_MSB                                 15
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LSB                                  0
#define MWV207REG_CLIP_DISTANCE_LOCATION1_BLK                                  0
#define MWV207REG_CLIP_DISTANCE_LOCATION1_Count                                1
#define MWV207REG_CLIP_DISTANCE_LOCATION1_FieldMask                   0x7F7F7F7F
#define MWV207REG_CLIP_DISTANCE_LOCATION1_ReadMask                    0x7F7F7F7F
#define MWV207REG_CLIP_DISTANCE_LOCATION1_WriteMask                   0x7F7F7F7F
#define MWV207REG_CLIP_DISTANCE_LOCATION1_ResetValue                  0x00000000


#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_X                        6:0
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_X_End                      6
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_X_Start                    0
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_X_Type                   U07


#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Y                       14:8
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Y_End                     14
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Y_Start                    8
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Y_Type                   U07


#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Z                      22:16
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Z_End                     22
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Z_Start                   16
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_Z_Type                   U07


#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_W                      30:24
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_W_End                     30
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_W_Start                   24
#define MWV207REG_CLIP_DISTANCE_LOCATION1_LOCATION1_W_Type                   U07




#define mwv207regViewportArrayIndexLocationRegAddrs                       0x0E70
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_Address                  0x039C0
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_MSB                           15
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_LSB                            0
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_BLK                            0
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_Count                          1
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_FieldMask             0x0000007F
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_ReadMask              0x0000007F
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_WriteMask             0x0000007F
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_ResetValue            0x00000000


#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_LOCATION0_X                  6:0
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_LOCATION0_X_End                6
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_LOCATION0_X_Start              0
#define MWV207REG_VIEWPORT_ARRAY_INDEX_LOCATION_LOCATION0_X_Type             U07




#define mwv207regMultiSampleEnableExRegAddrs                              0x0E71
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_Address                         0x039C4
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_MSB                                  15
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_LSB                                   0
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_BLK                                   0
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_Count                                 1
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_FieldMask                    0x00000FFF
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_ReadMask                     0x00000FFF
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_WriteMask                    0x00000FFF
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_ResetValue                   0x00000000

#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_ENABLE                             11:0
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_ENABLE_End                           11
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_ENABLE_Start                          0
#define MWV207REG_MULTI_SAMPLE_ENABLE_EX_ENABLE_Type                         U12




#define mwv207regConfigNN2RegAddrs                                        0x0E72
#define MWV207REG_CONFIG_NN2_Address                                     0x039C8
#define MWV207REG_CONFIG_NN2_MSB                                              15
#define MWV207REG_CONFIG_NN2_LSB                                               0
#define MWV207REG_CONFIG_NN2_BLK                                               0
#define MWV207REG_CONFIG_NN2_Count                                             1
#define MWV207REG_CONFIG_NN2_FieldMask                                0x0000003F
#define MWV207REG_CONFIG_NN2_ReadMask                                 0x0000003F
#define MWV207REG_CONFIG_NN2_WriteMask                                0x0000003F
#define MWV207REG_CONFIG_NN2_ResetValue                               0x00000000

#define MWV207REG_CONFIG_NN2_NUM_CONV_CORE_USED_MINUS_ONE                    5:0
#define MWV207REG_CONFIG_NN2_NUM_CONV_CORE_USED_MINUS_ONE_End                  5
#define MWV207REG_CONFIG_NN2_NUM_CONV_CORE_USED_MINUS_ONE_Start                0
#define MWV207REG_CONFIG_NN2_NUM_CONV_CORE_USED_MINUS_ONE_Type               U06




#define AQSelectNSAIDRegAddrs                                             0x0E73
#define AQ_SELECT_NSAID_Address                                          0x039CC
#define AQ_SELECT_NSAID_MSB                                                   15
#define AQ_SELECT_NSAID_LSB                                                    0
#define AQ_SELECT_NSAID_BLK                                                    0
#define AQ_SELECT_NSAID_Count                                                  1
#define AQ_SELECT_NSAID_FieldMask                                     0x00000003
#define AQ_SELECT_NSAID_ReadMask                                      0x00000003
#define AQ_SELECT_NSAID_WriteMask                                     0x00000003
#define AQ_SELECT_NSAID_ResetValue                                    0x00000000


#define AQ_SELECT_NSAID_NSAID1                                               0:0
#define AQ_SELECT_NSAID_NSAID1_End                                             0
#define AQ_SELECT_NSAID_NSAID1_Start                                           0
#define AQ_SELECT_NSAID_NSAID1_Type                                          U01


#define AQ_SELECT_NSAID_NSAID2                                               1:1
#define AQ_SELECT_NSAID_NSAID2_End                                             1
#define AQ_SELECT_NSAID_NSAID2_Start                                           1
#define AQ_SELECT_NSAID_NSAID2_Type                                          U01




#define AQFESelectNSAIDRegAddrs                                           0x0E74
#define AQFE_SELECT_NSAID_Address                                        0x039D0
#define AQFE_SELECT_NSAID_MSB                                                 15
#define AQFE_SELECT_NSAID_LSB                                                  0
#define AQFE_SELECT_NSAID_BLK                                                  0
#define AQFE_SELECT_NSAID_Count                                                1
#define AQFE_SELECT_NSAID_FieldMask                                   0x00000001
#define AQFE_SELECT_NSAID_ReadMask                                    0x00000001
#define AQFE_SELECT_NSAID_WriteMask                                   0x00000001
#define AQFE_SELECT_NSAID_ResetValue                                  0x00000000


#define AQFE_SELECT_NSAID_NSAID0                                             0:0
#define AQFE_SELECT_NSAID_NSAID0_End                                           0
#define AQFE_SELECT_NSAID_NSAID0_Start                                         0
#define AQFE_SELECT_NSAID_NSAID0_Type                                        U01



#define JMDEF_TOKEN_OPCODE                                                   3:0
#define JMDEF_TOKEN_OPCODE_End                                                 3
#define JMDEF_TOKEN_OPCODE_Start                                               0
#define JMDEF_TOKEN_OPCODE_Type                                              U04

#define   JMDEF_TOKEN_OPCODE_RESET_PRIMITIVE_ID                              0x0

#define   JMDEF_TOKEN_OPCODE_END_OF_PATCH                                    0x1

#define   JMDEF_TOKEN_OPCODE_END_OF_DRAW                                     0x2
#define   JMDEF_TOKEN_OPCODE_CLOSE_GROUP                                     0x3

#define   JMDEF_TOKEN_OPCODE_CHANGE_STATE_SET                                0x4

#define   JMDEF_TOKEN_OPCODE_STATE_OUT_BOTTOM                                0x5

#define   JMDEF_TOKEN_OPCODE_SNAP_TO_PAGE                                    0x6

#define   JMDEF_TOKEN_OPCODE_INCREASE_PRIMITIVE_ID                           0x7

#define   JMDEF_TOKEN_OPCODE_START_DATA                                      0x8

#define   JMDEF_TOKEN_OPCODE_RESET_INSTANCE_ID                               0x9

#define   JMDEF_TOKEN_OPCODE_RESET_STATE_SET                                 0xA

#define   JMDEF_TOKEN_OPCODE_SET_PRIMITIVE_ID                                0xB

#define   JMDEF_TOKEN_OPCODE_FLUSH_WD_VTX_COMPLETIONS                        0xC

#define   JMDEF_TOKEN_OPCODE_INVALIDATE_PPA2_LINE_CACHE                      0xD


#define JMDEF_TOKEN_CLIENT                                                   8:4
#define JMDEF_TOKEN_CLIENT_End                                                 8
#define JMDEF_TOKEN_CLIENT_Start                                               4
#define JMDEF_TOKEN_CLIENT_Type                                              U05

#define   JMDEF_TOKEN_CLIENT_NONE                                           0x00

#define   JMDEF_TOKEN_CLIENT_VS                                             0x01

#define   JMDEF_TOKEN_CLIENT_TCS                                            0x02

#define   JMDEF_TOKEN_CLIENT_TES                                            0x04

#define   JMDEF_TOKEN_CLIENT_GS                                             0x08

#define   JMDEF_TOKEN_CLIENT_PS                                             0x10


#endif


