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




#ifndef __AQCommand_h__
#define __AQCommand_h__





#define AQStallRegAddrs                                                   0x0F00
#define AQ_STALL_Address                                                 0x03C00
#define AQ_STALL_MSB                                                          15
#define AQ_STALL_LSB                                                           0
#define AQ_STALL_BLK                                                           0
#define AQ_STALL_Count                                                         1
#define AQ_STALL_FieldMask                                            0xFFFF1F1F
#define AQ_STALL_ReadMask                                             0xFFFF1F1F
#define AQ_STALL_WriteMask                                            0xFFFF1F1F
#define AQ_STALL_ResetValue                                           0x00000000

#define AQ_STALL_FLIP0                                                     30:30
#define AQ_STALL_FLIP0_End                                                    30
#define AQ_STALL_FLIP0_Start                                                  30
#define AQ_STALL_FLIP0_Type                                                  U01

#define AQ_STALL_FLIP1                                                     31:31
#define AQ_STALL_FLIP1_End                                                    31
#define AQ_STALL_FLIP1_Start                                                  31
#define AQ_STALL_FLIP1_Type                                                  U01

#define AQ_STALL_SOURCE                                                      4:0
#define AQ_STALL_SOURCE_End                                                    4
#define AQ_STALL_SOURCE_Start                                                  0
#define AQ_STALL_SOURCE_Type                                                 U05
#define   AQ_STALL_SOURCE_FRONT_END                                         0x01
#define   AQ_STALL_SOURCE_VERTEX_SHADER                                     0x02
#define   AQ_STALL_SOURCE_PRIMITIVE_ASSEMBLY                                0x03
#define   AQ_STALL_SOURCE_SETUP                                             0x04
#define   AQ_STALL_SOURCE_RASTERIZER                                        0x05
#define   AQ_STALL_SOURCE_PIXEL_SHADER                                      0x06
#define   AQ_STALL_SOURCE_PIXEL_ENGINE                                      0x07
#define   AQ_STALL_SOURCE_MEMORY_CONTROLLER                                 0x08
#define   AQ_STALL_SOURCE_DISPLAY_CONTROLLER0                               0x09
#define   AQ_STALL_SOURCE_DISPLAY_CONTROLLER1                               0x0A
#define   AQ_STALL_SOURCE_DRAWING_ENGINE                                    0x0B
#define   AQ_STALL_SOURCE_EVENT                                             0x0C
#define   AQ_STALL_SOURCE_RESOLVE                                           0x0D
#define   AQ_STALL_SOURCE_CHIP_ID                                           0x0F
#define   AQ_STALL_SOURCE_BLT_ENGINE                                        0x10

#define AQ_STALL_DESTINATION                                                12:8
#define AQ_STALL_DESTINATION_End                                              12
#define AQ_STALL_DESTINATION_Start                                             8
#define AQ_STALL_DESTINATION_Type                                            U05
#define   AQ_STALL_DESTINATION_FRONT_END                                    0x01
#define   AQ_STALL_DESTINATION_VERTEX_SHADER                                0x02
#define   AQ_STALL_DESTINATION_PRIMITIVE_ASSEMBLY                           0x03
#define   AQ_STALL_DESTINATION_SETUP                                        0x04
#define   AQ_STALL_DESTINATION_RASTERIZER                                   0x05
#define   AQ_STALL_DESTINATION_PIXEL_SHADER                                 0x06
#define   AQ_STALL_DESTINATION_PIXEL_ENGINE                                 0x07
#define   AQ_STALL_DESTINATION_MEMORY_CONTROLLER                            0x08
#define   AQ_STALL_DESTINATION_DISPLAY_CONTROLLER0                          0x09
#define   AQ_STALL_DESTINATION_DISPLAY_CONTROLLER1                          0x0A
#define   AQ_STALL_DESTINATION_DRAWING_ENGINE                               0x0B
#define   AQ_STALL_DESTINATION_EVENT                                        0x0C
#define   AQ_STALL_DESTINATION_RESOLVE                                      0x0D
#define   AQ_STALL_DESTINATION_CHIP_ID                                      0x0F
#define   AQ_STALL_DESTINATION_BLT_ENGINE                                   0x10

#define AQ_STALL_SOURCE_ID                                                 23:20
#define AQ_STALL_SOURCE_ID_End                                                23
#define AQ_STALL_SOURCE_ID_Start                                              20
#define AQ_STALL_SOURCE_ID_Type                                              U04

#define AQ_STALL_DESTINATION_ID                                            27:24
#define AQ_STALL_DESTINATION_ID_End                                           27
#define AQ_STALL_DESTINATION_ID_Start                                         24
#define AQ_STALL_DESTINATION_ID_Type                                         U04

#define AQ_STALL_ID                                                        19:16
#define AQ_STALL_ID_End                                                       19
#define AQ_STALL_ID_Start                                                     16
#define AQ_STALL_ID_Type                                                     U04

#define AQ_STALL_FRONT_END                                                 29:28
#define AQ_STALL_FRONT_END_End                                                29
#define AQ_STALL_FRONT_END_Start                                              28
#define AQ_STALL_FRONT_END_Type                                              U02
#define   AQ_STALL_FRONT_END_COMMAND                                         0x0
#define   AQ_STALL_FRONT_END_INDEX                                           0x1
#define   AQ_STALL_FRONT_END_VERTEX                                          0x2
#define   AQ_STALL_FRONT_END_PREFETCH                                        0x3




#define AQClearRegAddrs                                                   0x0F01
#define AQ_CLEAR_Address                                                 0x03C04
#define AQ_CLEAR_MSB                                                          15
#define AQ_CLEAR_LSB                                                           0
#define AQ_CLEAR_BLK                                                           0
#define AQ_CLEAR_Count                                                         1
#define AQ_CLEAR_FieldMask                                            0x00000001
#define AQ_CLEAR_ReadMask                                             0x00000001
#define AQ_CLEAR_WriteMask                                            0x00000001
#define AQ_CLEAR_ResetValue                                           0x00000000

#define AQ_CLEAR_FAST_CLEAR                                                  0:0
#define AQ_CLEAR_FAST_CLEAR_End                                                0
#define AQ_CLEAR_FAST_CLEAR_Start                                              0
#define AQ_CLEAR_FAST_CLEAR_Type                                             U01
#define   AQ_CLEAR_FAST_CLEAR_START                                          0x1




#define AQTriggerRegAddrs                                                 0x0F02
#define AQ_TRIGGER_Address                                               0x03C08
#define AQ_TRIGGER_MSB                                                        15
#define AQ_TRIGGER_LSB                                                         0
#define AQ_TRIGGER_BLK                                                         0
#define AQ_TRIGGER_Count                                                       1
#define AQ_TRIGGER_FieldMask                                          0x3FFF1F1F
#define AQ_TRIGGER_ReadMask                                           0x3FFF1F1F
#define AQ_TRIGGER_WriteMask                                          0x3FFF1F1F
#define AQ_TRIGGER_ResetValue                                         0x00000000

#define AQ_TRIGGER_SOURCE                                                    4:0
#define AQ_TRIGGER_SOURCE_End                                                  4
#define AQ_TRIGGER_SOURCE_Start                                                0
#define AQ_TRIGGER_SOURCE_Type                                               U05
#define   AQ_TRIGGER_SOURCE_FRONT_END                                       0x01
#define   AQ_TRIGGER_SOURCE_VERTEX_SHADER                                   0x02
#define   AQ_TRIGGER_SOURCE_PRIMITIVE_ASSEMBLY                              0x03
#define   AQ_TRIGGER_SOURCE_SETUP                                           0x04
#define   AQ_TRIGGER_SOURCE_RASTERIZER                                      0x05
#define   AQ_TRIGGER_SOURCE_PIXEL_SHADER                                    0x06
#define   AQ_TRIGGER_SOURCE_PIXEL_ENGINE                                    0x07
#define   AQ_TRIGGER_SOURCE_MEMORY_CONTROLLER                               0x08
#define   AQ_TRIGGER_SOURCE_DISPLAY_CONTROLLER0                             0x09
#define   AQ_TRIGGER_SOURCE_DISPLAY_CONTROLLER1                             0x0A
#define   AQ_TRIGGER_SOURCE_DRAWING_ENGINE                                  0x0B
#define   AQ_TRIGGER_SOURCE_EVENT                                           0x0C
#define   AQ_TRIGGER_SOURCE_RESOLVE                                         0x0D
#define   AQ_TRIGGER_SOURCE_CHIP_ID                                         0x0F
#define   AQ_TRIGGER_SOURCE_BLT_ENGINE                                      0x10

#define AQ_TRIGGER_DESTINATION                                              12:8
#define AQ_TRIGGER_DESTINATION_End                                            12
#define AQ_TRIGGER_DESTINATION_Start                                           8
#define AQ_TRIGGER_DESTINATION_Type                                          U05
#define   AQ_TRIGGER_DESTINATION_FRONT_END                                  0x01
#define   AQ_TRIGGER_DESTINATION_VERTEX_SHADER                              0x02
#define   AQ_TRIGGER_DESTINATION_PRIMITIVE_ASSEMBLY                         0x03
#define   AQ_TRIGGER_DESTINATION_SETUP                                      0x04
#define   AQ_TRIGGER_DESTINATION_RASTERIZER                                 0x05
#define   AQ_TRIGGER_DESTINATION_PIXEL_SHADER                               0x06
#define   AQ_TRIGGER_DESTINATION_PIXEL_ENGINE                               0x07
#define   AQ_TRIGGER_DESTINATION_MEMORY_CONTROLLER                          0x08
#define   AQ_TRIGGER_DESTINATION_DISPLAY_CONTROLLER0                        0x09
#define   AQ_TRIGGER_DESTINATION_DISPLAY_CONTROLLER1                        0x0A
#define   AQ_TRIGGER_DESTINATION_DRAWING_ENGINE                             0x0B
#define   AQ_TRIGGER_DESTINATION_EVENT                                      0x0C
#define   AQ_TRIGGER_DESTINATION_RESOLVE                                    0x0D
#define   AQ_TRIGGER_DESTINATION_CHIP_ID                                    0x0F
#define   AQ_TRIGGER_DESTINATION_BLT_ENGINE                                 0x10

#define AQ_TRIGGER_SOURCE_ID                                               23:20
#define AQ_TRIGGER_SOURCE_ID_End                                              23
#define AQ_TRIGGER_SOURCE_ID_Start                                            20
#define AQ_TRIGGER_SOURCE_ID_Type                                            U04

#define AQ_TRIGGER_DESTINATION_ID                                          27:24
#define AQ_TRIGGER_DESTINATION_ID_End                                         27
#define AQ_TRIGGER_DESTINATION_ID_Start                                       24
#define AQ_TRIGGER_DESTINATION_ID_Type                                       U04

#define AQ_TRIGGER_ID                                                      19:16
#define AQ_TRIGGER_ID_End                                                     19
#define AQ_TRIGGER_ID_Start                                                   16
#define AQ_TRIGGER_ID_Type                                                   U04

#define AQ_TRIGGER_FRONT_END                                               29:28
#define AQ_TRIGGER_FRONT_END_End                                              29
#define AQ_TRIGGER_FRONT_END_Start                                            28
#define AQ_TRIGGER_FRONT_END_Type                                            U02
#define   AQ_TRIGGER_FRONT_END_COMMAND                                       0x0
#define   AQ_TRIGGER_FRONT_END_INDEX                                         0x1
#define   AQ_TRIGGER_FRONT_END_VERTEX                                        0x2
#define   AQ_TRIGGER_FRONT_END_PREFETCH                                      0x3


#define AQCommandLoadStateCmdAddrs                                        0x0F03
#define AQ_COMMAND_LOAD_STATE_Address                                    0x03C0C
#define AQ_COMMAND_LOAD_STATE_Count                                            1

#define AQ_COMMAND_LOAD_STATE_COMMAND_Index                                    0
#define AQ_COMMAND_LOAD_STATE_COMMAND_CmdAddrs                            0x0F03


#define AQ_COMMAND_LOAD_STATE_COMMAND_FLOAT                                26:26
#define AQ_COMMAND_LOAD_STATE_COMMAND_FLOAT_End                               26
#define AQ_COMMAND_LOAD_STATE_COMMAND_FLOAT_Start                             26
#define AQ_COMMAND_LOAD_STATE_COMMAND_FLOAT_Type                             U01
#define   AQ_COMMAND_LOAD_STATE_COMMAND_FLOAT_NORMAL                         0x0
#define   AQ_COMMAND_LOAD_STATE_COMMAND_FLOAT_FIXED16_DOT16                  0x1


#define AQ_COMMAND_LOAD_STATE_COMMAND_COUNT                                25:16
#define AQ_COMMAND_LOAD_STATE_COMMAND_COUNT_End                               25
#define AQ_COMMAND_LOAD_STATE_COMMAND_COUNT_Start                             16
#define AQ_COMMAND_LOAD_STATE_COMMAND_COUNT_Type                             U10


#define AQ_COMMAND_LOAD_STATE_COMMAND_ADDRESS                               15:0
#define AQ_COMMAND_LOAD_STATE_COMMAND_ADDRESS_End                             15
#define AQ_COMMAND_LOAD_STATE_COMMAND_ADDRESS_Start                            0
#define AQ_COMMAND_LOAD_STATE_COMMAND_ADDRESS_Type                           U16

#define AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE                               31:27
#define AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_End                              31
#define AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_Start                            27
#define AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_Type                            U05
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_LOAD_STATE                   0x01
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_END                          0x02
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_NOP                          0x03
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_START_DE                     0x04
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE           0x05
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE     0x06
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_WAIT                         0x07
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_LINK                         0x08
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_STALL                        0x09
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_CALL                         0x0A
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_RETURN                       0x0B
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_DRAW_INSTANCED               0x0C
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_CHIP_ENABLE                  0x0D
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_POP_OCCLUSION_QUERY          0x0E
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_FENCE                        0x0F
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_DRAW_INDIRECT                0x10
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_COMPUTE_INDIRECT             0x11
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_SNAP_TO_PAGE                 0x13
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT          0x14
#define   AQ_COMMAND_LOAD_STATE_COMMAND_OPCODE_DRAW_DIRECT                  0x15


#define AQCommandEndCmdAddrs                                              0x0F04
#define AQ_COMMAND_END_Address                                           0x03C10
#define AQ_COMMAND_END_Count                                                   1

#define AQ_COMMAND_END_COMMAND_Index                                           0
#define AQ_COMMAND_END_COMMAND_CmdAddrs                                   0x0F04


#define AQ_COMMAND_END_COMMAND_EVENT_ENABLE                                  8:8
#define AQ_COMMAND_END_COMMAND_EVENT_ENABLE_End                                8
#define AQ_COMMAND_END_COMMAND_EVENT_ENABLE_Start                              8
#define AQ_COMMAND_END_COMMAND_EVENT_ENABLE_Type                             U01


#define AQ_COMMAND_END_COMMAND_EVENT_ID                                      4:0
#define AQ_COMMAND_END_COMMAND_EVENT_ID_End                                    4
#define AQ_COMMAND_END_COMMAND_EVENT_ID_Start                                  0
#define AQ_COMMAND_END_COMMAND_EVENT_ID_Type                                 U05

#define AQ_COMMAND_END_COMMAND_OPCODE                                      31:27
#define AQ_COMMAND_END_COMMAND_OPCODE_End                                     31
#define AQ_COMMAND_END_COMMAND_OPCODE_Start                                   27
#define AQ_COMMAND_END_COMMAND_OPCODE_Type                                   U05
#define   AQ_COMMAND_END_COMMAND_OPCODE_LOAD_STATE                          0x01
#define   AQ_COMMAND_END_COMMAND_OPCODE_END                                 0x02
#define   AQ_COMMAND_END_COMMAND_OPCODE_NOP                                 0x03
#define   AQ_COMMAND_END_COMMAND_OPCODE_START_DE                            0x04
#define   AQ_COMMAND_END_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                  0x05
#define   AQ_COMMAND_END_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE            0x06
#define   AQ_COMMAND_END_COMMAND_OPCODE_WAIT                                0x07
#define   AQ_COMMAND_END_COMMAND_OPCODE_LINK                                0x08
#define   AQ_COMMAND_END_COMMAND_OPCODE_STALL                               0x09
#define   AQ_COMMAND_END_COMMAND_OPCODE_CALL                                0x0A
#define   AQ_COMMAND_END_COMMAND_OPCODE_RETURN                              0x0B
#define   AQ_COMMAND_END_COMMAND_OPCODE_DRAW_INSTANCED                      0x0C
#define   AQ_COMMAND_END_COMMAND_OPCODE_CHIP_ENABLE                         0x0D
#define   AQ_COMMAND_END_COMMAND_OPCODE_POP_OCCLUSION_QUERY                 0x0E
#define   AQ_COMMAND_END_COMMAND_OPCODE_FENCE                               0x0F
#define   AQ_COMMAND_END_COMMAND_OPCODE_DRAW_INDIRECT                       0x10
#define   AQ_COMMAND_END_COMMAND_OPCODE_COMPUTE_INDIRECT                    0x11
#define   AQ_COMMAND_END_COMMAND_OPCODE_SNAP_TO_PAGE                        0x13
#define   AQ_COMMAND_END_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                 0x14
#define   AQ_COMMAND_END_COMMAND_OPCODE_DRAW_DIRECT                         0x15


#define AQCommandNopCmdAddrs                                              0x0F05
#define AQ_COMMAND_NOP_Address                                           0x03C14
#define AQ_COMMAND_NOP_Count                                                   1

#define AQ_COMMAND_NOP_COMMAND_Index                                           0
#define AQ_COMMAND_NOP_COMMAND_CmdAddrs                                   0x0F05

#define AQ_COMMAND_NOP_COMMAND_OPCODE                                      31:27
#define AQ_COMMAND_NOP_COMMAND_OPCODE_End                                     31
#define AQ_COMMAND_NOP_COMMAND_OPCODE_Start                                   27
#define AQ_COMMAND_NOP_COMMAND_OPCODE_Type                                   U05
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_LOAD_STATE                          0x01
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_END                                 0x02
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_NOP                                 0x03
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_START_DE                            0x04
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                  0x05
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE            0x06
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_WAIT                                0x07
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_LINK                                0x08
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_STALL                               0x09
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_CALL                                0x0A
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_RETURN                              0x0B
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_DRAW_INSTANCED                      0x0C
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_CHIP_ENABLE                         0x0D
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_POP_OCCLUSION_QUERY                 0x0E
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_FENCE                               0x0F
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_DRAW_INDIRECT                       0x10
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_COMPUTE_INDIRECT                    0x11
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_SNAP_TO_PAGE                        0x13
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                 0x14
#define   AQ_COMMAND_NOP_COMMAND_OPCODE_DRAW_DIRECT                         0x15


#define AQCommandStartDECmdAddrs                                          0x0F06
#define AQ_COMMAND_START_DE_Address                                      0x03C18
#define AQ_COMMAND_START_DE_Count                                              1

#define AQ_COMMAND_START_DE_COMMAND_Index                                      0
#define AQ_COMMAND_START_DE_COMMAND_CmdAddrs                              0x0F06

#define AQ_COMMAND_START_DE_COMMAND_DATA_COUNT                             26:16
#define AQ_COMMAND_START_DE_COMMAND_DATA_COUNT_End                            26
#define AQ_COMMAND_START_DE_COMMAND_DATA_COUNT_Start                          16
#define AQ_COMMAND_START_DE_COMMAND_DATA_COUNT_Type                          U11

#define AQ_COMMAND_START_DE_COMMAND_COUNT                                   15:8
#define AQ_COMMAND_START_DE_COMMAND_COUNT_End                                 15
#define AQ_COMMAND_START_DE_COMMAND_COUNT_Start                                8
#define AQ_COMMAND_START_DE_COMMAND_COUNT_Type                               U08

#define AQ_COMMAND_START_DE_COMMAND_OPCODE                                 31:27
#define AQ_COMMAND_START_DE_COMMAND_OPCODE_End                                31
#define AQ_COMMAND_START_DE_COMMAND_OPCODE_Start                              27
#define AQ_COMMAND_START_DE_COMMAND_OPCODE_Type                              U05
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_LOAD_STATE                     0x01
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_END                            0x02
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_NOP                            0x03
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_START_DE                       0x04
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE             0x05
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE       0x06
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_WAIT                           0x07
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_LINK                           0x08
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_STALL                          0x09
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_CALL                           0x0A
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_RETURN                         0x0B
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_DRAW_INSTANCED                 0x0C
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_CHIP_ENABLE                    0x0D
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_POP_OCCLUSION_QUERY            0x0E
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_FENCE                          0x0F
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_DRAW_INDIRECT                  0x10
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_COMPUTE_INDIRECT               0x11
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_SNAP_TO_PAGE                   0x13
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT            0x14
#define   AQ_COMMAND_START_DE_COMMAND_OPCODE_DRAW_DIRECT                    0x15


#define AQCommandDX8DrawPrimitiveCmdAddrs                                 0x0F08
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_Address                            0x03C20
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_Count                                    4

#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_Index                            0
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_CmdAddrs                    0x0F08

#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE                       31:27
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_End                      31
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_Start                    27
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_Type                    U05
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_LOAD_STATE           0x01
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_END                  0x02
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_NOP                  0x03
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_START_DE             0x04
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE   0x05
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE 0x06
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_WAIT                 0x07
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_LINK                 0x08
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_STALL                0x09
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_CALL                 0x0A
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_RETURN               0x0B
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_DRAW_INSTANCED       0x0C
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_CHIP_ENABLE          0x0D
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_POP_OCCLUSION_QUERY  0x0E
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_FENCE                0x0F
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_DRAW_INDIRECT        0x10
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_COMPUTE_INDIRECT     0x11
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_SNAP_TO_PAGE         0x13
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT  0x14
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND_OPCODE_DRAW_DIRECT          0x15

#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_Index                           1
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_CmdAddrs                   0x0F09

#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE                          3:0
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_End                        3
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_Start                      0
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_Type                     U04
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_POINT_LIST             0x1
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_LINE_LIST              0x2
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_LINE_STRIP             0x3
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_LIST          0x4
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_STRIP         0x5
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_FAN           0x6
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_LINE_LOOP              0x7
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_RECTANGLE              0x8
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_LINES_ADJACENCY        0x9
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_LINE_STRIP_ADJACENCY   0xA
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLES_ADJACENCY    0xB
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_STRIP_ADJACENCY 0xC
#define   AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_TYPE_PATCH_LIST             0xD


#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_INSTANCE                    31:16
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_INSTANCE_End                   31
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_INSTANCE_Start                 16
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMTYPE_INSTANCE_Type                 U16

#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_VERTEXSTART_Index                        2
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_VERTEXSTART_CmdAddrs                0x0F0A


#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_VERTEXSTART_INDEX                     23:0
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_VERTEXSTART_INDEX_End                   23
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_VERTEXSTART_INDEX_Start                  0
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_VERTEXSTART_INDEX_Type                 U24

#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMCOUNT_Index                          3
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMCOUNT_CmdAddrs                  0x0F0B


#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMCOUNT_COUNT                       23:0
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMCOUNT_COUNT_End                     23
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMCOUNT_COUNT_Start                    0
#define AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMCOUNT_COUNT_Type                   U24


#define AQCommandDX8DrawIndexPrimitiveCmdAddrs                            0x0F10
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_Address                      0x03C40
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_Count                              5

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_Index                      0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_CmdAddrs              0x0F10

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE                 31:27
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_End                31
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_Start              27
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_Type              U05
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_LOAD_STATE     0x01
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_END            0x02
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_NOP            0x03
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_START_DE       0x04
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE 0x05
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE 0x06
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_WAIT           0x07
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_LINK           0x08
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_STALL          0x09
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_CALL           0x0A
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_RETURN         0x0B
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_DRAW_INSTANCED 0x0C
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_CHIP_ENABLE    0x0D
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_POP_OCCLUSION_QUERY 0x0E
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_FENCE          0x0F
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_DRAW_INDIRECT  0x10
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_COMPUTE_INDIRECT 0x11
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_SNAP_TO_PAGE   0x13
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT 0x14
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_COMMAND_OPCODE_DRAW_DIRECT    0x15

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_Index                     1
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_CmdAddrs             0x0F11

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE                    3:0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_End                  3
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_Start                0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_Type               U04
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_POINT_LIST       0x1
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_LINE_LIST        0x2
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_LINE_STRIP       0x3
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_LIST    0x4
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_STRIP   0x5
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_FAN     0x6
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_LINE_LOOP        0x7
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_RECTANGLE        0x8
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_LINES_ADJACENCY  0x9
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_LINE_STRIP_ADJACENCY 0xA
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLES_ADJACENCY 0xB
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_TRIANGLE_STRIP_ADJACENCY 0xC
#define   AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_TYPE_PATCH_LIST       0xD


#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_INSTANCE              31:16
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_INSTANCE_End             31
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_INSTANCE_Start           16
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMTYPE_INSTANCE_Type           U16

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_START_Index                        2
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_START_CmdAddrs                0x0F12


#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_START_INDEX                     23:0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_START_INDEX_End                   23
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_START_INDEX_Start                  0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_START_INDEX_Type                 U24

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMCOUNT_Index                    3
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMCOUNT_CmdAddrs            0x0F13


#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMCOUNT_COUNT                 23:0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMCOUNT_COUNT_End               23
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMCOUNT_COUNT_Start              0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_PRIMCOUNT_COUNT_Type             U24

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_BASEVERTEX_Index                   4
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_BASEVERTEX_CmdAddrs           0x0F14

#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_BASEVERTEX_INDEX                31:0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_BASEVERTEX_INDEX_End              31
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_BASEVERTEX_INDEX_Start             0
#define AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_BASEVERTEX_INDEX_Type            U32


#define AQCommandWaitCmdAddrs                                             0x0F07
#define AQ_COMMAND_WAIT_Address                                          0x03C1C
#define AQ_COMMAND_WAIT_Count                                                  1

#define AQ_COMMAND_WAIT_COMMAND_Index                                          0
#define AQ_COMMAND_WAIT_COMMAND_CmdAddrs                                  0x0F07


#define AQ_COMMAND_WAIT_COMMAND_DELAY                                       15:0
#define AQ_COMMAND_WAIT_COMMAND_DELAY_End                                     15
#define AQ_COMMAND_WAIT_COMMAND_DELAY_Start                                    0
#define AQ_COMMAND_WAIT_COMMAND_DELAY_Type                                   U16

#define AQ_COMMAND_WAIT_COMMAND_OPCODE                                     31:27
#define AQ_COMMAND_WAIT_COMMAND_OPCODE_End                                    31
#define AQ_COMMAND_WAIT_COMMAND_OPCODE_Start                                  27
#define AQ_COMMAND_WAIT_COMMAND_OPCODE_Type                                  U05
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_LOAD_STATE                         0x01
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_END                                0x02
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_NOP                                0x03
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_START_DE                           0x04
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                 0x05
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE           0x06
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_WAIT                               0x07
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_LINK                               0x08
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_STALL                              0x09
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_CALL                               0x0A
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_RETURN                             0x0B
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_DRAW_INSTANCED                     0x0C
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_CHIP_ENABLE                        0x0D
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_POP_OCCLUSION_QUERY                0x0E
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_FENCE                              0x0F
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_DRAW_INDIRECT                      0x10
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_COMPUTE_INDIRECT                   0x11
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_SNAP_TO_PAGE                       0x13
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                0x14
#define   AQ_COMMAND_WAIT_COMMAND_OPCODE_DRAW_DIRECT                        0x15


#define AQCommandLinkCmdAddrs                                             0x0F0C
#define AQ_COMMAND_LINK_Address                                          0x03C30
#define AQ_COMMAND_LINK_Count                                                  2

#define AQ_COMMAND_LINK_COMMAND_Index                                          0
#define AQ_COMMAND_LINK_COMMAND_CmdAddrs                                  0x0F0C


#define AQ_COMMAND_LINK_COMMAND_CONDITIONAL                                26:24
#define AQ_COMMAND_LINK_COMMAND_CONDITIONAL_End                               26
#define AQ_COMMAND_LINK_COMMAND_CONDITIONAL_Start                             24
#define AQ_COMMAND_LINK_COMMAND_CONDITIONAL_Type                             U03

#define   AQ_COMMAND_LINK_COMMAND_CONDITIONAL_ALWAYS                         0x0

#define   AQ_COMMAND_LINK_COMMAND_CONDITIONAL_OCCLUSION_ONE                  0x1

#define   AQ_COMMAND_LINK_COMMAND_CONDITIONAL_OCCLUSION_NONE                 0x2
#define   AQ_COMMAND_LINK_COMMAND_CONDITIONAL_OCCLUSION_ONE_POP              0x3
#define   AQ_COMMAND_LINK_COMMAND_CONDITIONAL_OCCLUSION_NONE_POP             0x4

#define AQ_COMMAND_LINK_COMMAND_PREFETCH                                    15:0
#define AQ_COMMAND_LINK_COMMAND_PREFETCH_End                                  15
#define AQ_COMMAND_LINK_COMMAND_PREFETCH_Start                                 0
#define AQ_COMMAND_LINK_COMMAND_PREFETCH_Type                                U16

#define AQ_COMMAND_LINK_COMMAND_OPCODE                                     31:27
#define AQ_COMMAND_LINK_COMMAND_OPCODE_End                                    31
#define AQ_COMMAND_LINK_COMMAND_OPCODE_Start                                  27
#define AQ_COMMAND_LINK_COMMAND_OPCODE_Type                                  U05
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_LOAD_STATE                         0x01
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_END                                0x02
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_NOP                                0x03
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_START_DE                           0x04
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                 0x05
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE           0x06
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_WAIT                               0x07
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_LINK                               0x08
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_STALL                              0x09
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_CALL                               0x0A
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_RETURN                             0x0B
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_DRAW_INSTANCED                     0x0C
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_CHIP_ENABLE                        0x0D
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_POP_OCCLUSION_QUERY                0x0E
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_FENCE                              0x0F
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_DRAW_INDIRECT                      0x10
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_COMPUTE_INDIRECT                   0x11
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_SNAP_TO_PAGE                       0x13
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                0x14
#define   AQ_COMMAND_LINK_COMMAND_OPCODE_DRAW_DIRECT                        0x15

#define AQ_COMMAND_LINK_ADDRESS_Index                                          1
#define AQ_COMMAND_LINK_ADDRESS_CmdAddrs                                  0x0F0D

#define AQ_COMMAND_LINK_ADDRESS_TYPE                                       31:31
#define AQ_COMMAND_LINK_ADDRESS_TYPE_End                                      31
#define AQ_COMMAND_LINK_ADDRESS_TYPE_Start                                    31
#define AQ_COMMAND_LINK_ADDRESS_TYPE_Type                                    U01
#define   AQ_COMMAND_LINK_ADDRESS_TYPE_SYSTEM                                0x0
#define   AQ_COMMAND_LINK_ADDRESS_TYPE_VIRTUAL_SYSTEM                        0x1

#define AQ_COMMAND_LINK_ADDRESS_ADDRESS                                     30:0
#define AQ_COMMAND_LINK_ADDRESS_ADDRESS_End                                   30
#define AQ_COMMAND_LINK_ADDRESS_ADDRESS_Start                                  0
#define AQ_COMMAND_LINK_ADDRESS_ADDRESS_Type                                 U31


#define jmcmdCallCmdAddrs                                                 0x0F18
#define JMCMD_CALL_Address                                               0x03C60
#define JMCMD_CALL_Count                                                       4

#define JMCMD_CALL_COMMAND_Index                                               0
#define JMCMD_CALL_COMMAND_CmdAddrs                                       0x0F18


#define JMCMD_CALL_COMMAND_CONDITIONAL                                     26:24
#define JMCMD_CALL_COMMAND_CONDITIONAL_End                                    26
#define JMCMD_CALL_COMMAND_CONDITIONAL_Start                                  24
#define JMCMD_CALL_COMMAND_CONDITIONAL_Type                                  U03

#define   JMCMD_CALL_COMMAND_CONDITIONAL_ALWAYS                              0x0

#define   JMCMD_CALL_COMMAND_CONDITIONAL_OCCLUSION_ONE                       0x1

#define   JMCMD_CALL_COMMAND_CONDITIONAL_OCCLUSION_NONE                      0x2
#define   JMCMD_CALL_COMMAND_CONDITIONAL_OCCLUSION_ONE_POP                   0x3
#define   JMCMD_CALL_COMMAND_CONDITIONAL_OCCLUSION_NONE_POP                  0x4

#define JMCMD_CALL_COMMAND_PREFETCH                                         15:0
#define JMCMD_CALL_COMMAND_PREFETCH_End                                       15
#define JMCMD_CALL_COMMAND_PREFETCH_Start                                      0
#define JMCMD_CALL_COMMAND_PREFETCH_Type                                     U16

#define JMCMD_CALL_COMMAND_OPCODE                                          31:27
#define JMCMD_CALL_COMMAND_OPCODE_End                                         31
#define JMCMD_CALL_COMMAND_OPCODE_Start                                       27
#define JMCMD_CALL_COMMAND_OPCODE_Type                                       U05
#define   JMCMD_CALL_COMMAND_OPCODE_LOAD_STATE                              0x01
#define   JMCMD_CALL_COMMAND_OPCODE_END                                     0x02
#define   JMCMD_CALL_COMMAND_OPCODE_NOP                                     0x03
#define   JMCMD_CALL_COMMAND_OPCODE_START_DE                                0x04
#define   JMCMD_CALL_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                      0x05
#define   JMCMD_CALL_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE                0x06
#define   JMCMD_CALL_COMMAND_OPCODE_WAIT                                    0x07
#define   JMCMD_CALL_COMMAND_OPCODE_LINK                                    0x08
#define   JMCMD_CALL_COMMAND_OPCODE_STALL                                   0x09
#define   JMCMD_CALL_COMMAND_OPCODE_CALL                                    0x0A
#define   JMCMD_CALL_COMMAND_OPCODE_RETURN                                  0x0B
#define   JMCMD_CALL_COMMAND_OPCODE_DRAW_INSTANCED                          0x0C
#define   JMCMD_CALL_COMMAND_OPCODE_CHIP_ENABLE                             0x0D
#define   JMCMD_CALL_COMMAND_OPCODE_POP_OCCLUSION_QUERY                     0x0E
#define   JMCMD_CALL_COMMAND_OPCODE_FENCE                                   0x0F
#define   JMCMD_CALL_COMMAND_OPCODE_DRAW_INDIRECT                           0x10
#define   JMCMD_CALL_COMMAND_OPCODE_COMPUTE_INDIRECT                        0x11
#define   JMCMD_CALL_COMMAND_OPCODE_SNAP_TO_PAGE                            0x13
#define   JMCMD_CALL_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                     0x14
#define   JMCMD_CALL_COMMAND_OPCODE_DRAW_DIRECT                             0x15

#define JMCMD_CALL_ADDRESS_Index                                               1
#define JMCMD_CALL_ADDRESS_CmdAddrs                                       0x0F19

#define JMCMD_CALL_ADDRESS_TYPE                                            31:31
#define JMCMD_CALL_ADDRESS_TYPE_End                                           31
#define JMCMD_CALL_ADDRESS_TYPE_Start                                         31
#define JMCMD_CALL_ADDRESS_TYPE_Type                                         U01
#define   JMCMD_CALL_ADDRESS_TYPE_SYSTEM                                     0x0
#define   JMCMD_CALL_ADDRESS_TYPE_VIRTUAL_SYSTEM                             0x1

#define JMCMD_CALL_ADDRESS_ADDRESS                                          30:0
#define JMCMD_CALL_ADDRESS_ADDRESS_End                                        30
#define JMCMD_CALL_ADDRESS_ADDRESS_Start                                       0
#define JMCMD_CALL_ADDRESS_ADDRESS_Type                                      U31

#define JMCMD_CALL_RETURN_PREFETCH_Index                                       2
#define JMCMD_CALL_RETURN_PREFETCH_CmdAddrs                               0x0F1A

#define JMCMD_CALL_RETURN_PREFETCH_PREFETCH                                 15:0
#define JMCMD_CALL_RETURN_PREFETCH_PREFETCH_End                               15
#define JMCMD_CALL_RETURN_PREFETCH_PREFETCH_Start                              0
#define JMCMD_CALL_RETURN_PREFETCH_PREFETCH_Type                             U16

#define JMCMD_CALL_RETURN_ADDRESS_Index                                        3
#define JMCMD_CALL_RETURN_ADDRESS_CmdAddrs                                0x0F1B

#define JMCMD_CALL_RETURN_ADDRESS_TYPE                                     31:31
#define JMCMD_CALL_RETURN_ADDRESS_TYPE_End                                    31
#define JMCMD_CALL_RETURN_ADDRESS_TYPE_Start                                  31
#define JMCMD_CALL_RETURN_ADDRESS_TYPE_Type                                  U01
#define   JMCMD_CALL_RETURN_ADDRESS_TYPE_SYSTEM                              0x0
#define   JMCMD_CALL_RETURN_ADDRESS_TYPE_VIRTUAL_SYSTEM                      0x1

#define JMCMD_CALL_RETURN_ADDRESS_ADDRESS                                   30:0
#define JMCMD_CALL_RETURN_ADDRESS_ADDRESS_End                                 30
#define JMCMD_CALL_RETURN_ADDRESS_ADDRESS_Start                                0
#define JMCMD_CALL_RETURN_ADDRESS_ADDRESS_Type                               U31


#define jmcmdReturnCmdAddrs                                               0x0F0E
#define JMCMD_RETURN_Address                                             0x03C38
#define JMCMD_RETURN_Count                                                     1

#define JMCMD_RETURN_COMMAND_Index                                             0
#define JMCMD_RETURN_COMMAND_CmdAddrs                                     0x0F0E

#define JMCMD_RETURN_COMMAND_OPCODE                                        31:27
#define JMCMD_RETURN_COMMAND_OPCODE_End                                       31
#define JMCMD_RETURN_COMMAND_OPCODE_Start                                     27
#define JMCMD_RETURN_COMMAND_OPCODE_Type                                     U05
#define   JMCMD_RETURN_COMMAND_OPCODE_LOAD_STATE                            0x01
#define   JMCMD_RETURN_COMMAND_OPCODE_END                                   0x02
#define   JMCMD_RETURN_COMMAND_OPCODE_NOP                                   0x03
#define   JMCMD_RETURN_COMMAND_OPCODE_START_DE                              0x04
#define   JMCMD_RETURN_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                    0x05
#define   JMCMD_RETURN_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE              0x06
#define   JMCMD_RETURN_COMMAND_OPCODE_WAIT                                  0x07
#define   JMCMD_RETURN_COMMAND_OPCODE_LINK                                  0x08
#define   JMCMD_RETURN_COMMAND_OPCODE_STALL                                 0x09
#define   JMCMD_RETURN_COMMAND_OPCODE_CALL                                  0x0A
#define   JMCMD_RETURN_COMMAND_OPCODE_RETURN                                0x0B
#define   JMCMD_RETURN_COMMAND_OPCODE_DRAW_INSTANCED                        0x0C
#define   JMCMD_RETURN_COMMAND_OPCODE_CHIP_ENABLE                           0x0D
#define   JMCMD_RETURN_COMMAND_OPCODE_POP_OCCLUSION_QUERY                   0x0E
#define   JMCMD_RETURN_COMMAND_OPCODE_FENCE                                 0x0F
#define   JMCMD_RETURN_COMMAND_OPCODE_DRAW_INDIRECT                         0x10
#define   JMCMD_RETURN_COMMAND_OPCODE_COMPUTE_INDIRECT                      0x11
#define   JMCMD_RETURN_COMMAND_OPCODE_SNAP_TO_PAGE                          0x13
#define   JMCMD_RETURN_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                   0x14
#define   JMCMD_RETURN_COMMAND_OPCODE_DRAW_DIRECT                           0x15



#define AQ_COMMAND_PIPE_PIPE                                                 1:0
#define AQ_COMMAND_PIPE_PIPE_End                                               1
#define AQ_COMMAND_PIPE_PIPE_Start                                             0
#define AQ_COMMAND_PIPE_PIPE_Type                                            U02
#define   AQ_COMMAND_PIPE_PIPE_3D                                            0x0
#define   AQ_COMMAND_PIPE_PIPE_2D                                            0x1
#define   AQ_COMMAND_PIPE_PIPE_VIDEO                                         0x2


#define AQ_COMMAND_OPCODE_OPCODE                                           31:27
#define AQ_COMMAND_OPCODE_OPCODE_End                                          31
#define AQ_COMMAND_OPCODE_OPCODE_Start                                        27
#define AQ_COMMAND_OPCODE_OPCODE_Type                                        U05
#define   AQ_COMMAND_OPCODE_OPCODE_LOAD_STATE                               0x01
#define   AQ_COMMAND_OPCODE_OPCODE_END                                      0x02
#define   AQ_COMMAND_OPCODE_OPCODE_NOP                                      0x03
#define   AQ_COMMAND_OPCODE_OPCODE_START_DE                                 0x04
#define   AQ_COMMAND_OPCODE_OPCODE_DX8_DRAW_PRIMITIVE                       0x05
#define   AQ_COMMAND_OPCODE_OPCODE_DX8_DRAW_INDEX_PRIMITIVE                 0x06
#define   AQ_COMMAND_OPCODE_OPCODE_WAIT                                     0x07
#define   AQ_COMMAND_OPCODE_OPCODE_LINK                                     0x08
#define   AQ_COMMAND_OPCODE_OPCODE_STALL                                    0x09
#define   AQ_COMMAND_OPCODE_OPCODE_CALL                                     0x0A
#define   AQ_COMMAND_OPCODE_OPCODE_RETURN                                   0x0B
#define   AQ_COMMAND_OPCODE_OPCODE_DRAW_INSTANCED                           0x0C
#define   AQ_COMMAND_OPCODE_OPCODE_CHIP_ENABLE                              0x0D
#define   AQ_COMMAND_OPCODE_OPCODE_POP_OCCLUSION_QUERY                      0x0E
#define   AQ_COMMAND_OPCODE_OPCODE_FENCE                                    0x0F
#define   AQ_COMMAND_OPCODE_OPCODE_DRAW_INDIRECT                            0x10
#define   AQ_COMMAND_OPCODE_OPCODE_COMPUTE_INDIRECT                         0x11
#define   AQ_COMMAND_OPCODE_OPCODE_SNAP_TO_PAGE                             0x13
#define   AQ_COMMAND_OPCODE_OPCODE_MULTI_DRAW_INDIRECT                      0x14
#define   AQ_COMMAND_OPCODE_OPCODE_DRAW_DIRECT                              0x15


#define AQ_COMMAND_COLOR_ALPHA                                             31:24
#define AQ_COMMAND_COLOR_ALPHA_End                                            31
#define AQ_COMMAND_COLOR_ALPHA_Start                                          24
#define AQ_COMMAND_COLOR_ALPHA_Type                                          U08

#define AQ_COMMAND_COLOR_RED                                               23:16
#define AQ_COMMAND_COLOR_RED_End                                              23
#define AQ_COMMAND_COLOR_RED_Start                                            16
#define AQ_COMMAND_COLOR_RED_Type                                            U08

#define AQ_COMMAND_COLOR_GREEN                                              15:8
#define AQ_COMMAND_COLOR_GREEN_End                                            15
#define AQ_COMMAND_COLOR_GREEN_Start                                           8
#define AQ_COMMAND_COLOR_GREEN_Type                                          U08

#define AQ_COMMAND_COLOR_BLUE                                                7:0
#define AQ_COMMAND_COLOR_BLUE_End                                              7
#define AQ_COMMAND_COLOR_BLUE_Start                                            0
#define AQ_COMMAND_COLOR_BLUE_Type                                           U08


#define AQ_COMMAND_TOP_LEFT_Y                                              31:16
#define AQ_COMMAND_TOP_LEFT_Y_End                                             31
#define AQ_COMMAND_TOP_LEFT_Y_Start                                           16
#define AQ_COMMAND_TOP_LEFT_Y_Type                                           U16

#define AQ_COMMAND_TOP_LEFT_X                                               15:0
#define AQ_COMMAND_TOP_LEFT_X_End                                             15
#define AQ_COMMAND_TOP_LEFT_X_Start                                            0
#define AQ_COMMAND_TOP_LEFT_X_Type                                           U16


#define AQ_COMMAND_BOTTOM_RIGHT_Y                                          31:16
#define AQ_COMMAND_BOTTOM_RIGHT_Y_End                                         31
#define AQ_COMMAND_BOTTOM_RIGHT_Y_Start                                       16
#define AQ_COMMAND_BOTTOM_RIGHT_Y_Type                                       U16

#define AQ_COMMAND_BOTTOM_RIGHT_X                                           15:0
#define AQ_COMMAND_BOTTOM_RIGHT_X_End                                         15
#define AQ_COMMAND_BOTTOM_RIGHT_X_Start                                        0
#define AQ_COMMAND_BOTTOM_RIGHT_X_Type                                       U16


#define AQ_COMMAND_PRIM_TYPE                                                31:0
#define AQ_COMMAND_PRIM_TYPE_End                                              31
#define AQ_COMMAND_PRIM_TYPE_Start                                             0
#define AQ_COMMAND_PRIM_TYPE_Type                                            U32
#define   AQ_COMMAND_PRIM_TYPE_POINT_LIST                             0x00000001
#define   AQ_COMMAND_PRIM_TYPE_LINE_LIST                              0x00000002
#define   AQ_COMMAND_PRIM_TYPE_LINE_STRIP                             0x00000003
#define   AQ_COMMAND_PRIM_TYPE_TRIANGLE_LIST                          0x00000004
#define   AQ_COMMAND_PRIM_TYPE_TRIANGLE_STRIP                         0x00000005
#define   AQ_COMMAND_PRIM_TYPE_TRIANGLE_FAN                           0x00000006
#define   AQ_COMMAND_PRIM_TYPE_LINE_LOOP                              0x00000007
#define   AQ_COMMAND_PRIM_TYPE_RECTANGLE                              0x00000008
#define   AQ_COMMAND_PRIM_TYPE_LINES_ADJACENCY                        0x00000009
#define   AQ_COMMAND_PRIM_TYPE_LINE_STRIP_ADJACENCY                   0x0000000A
#define   AQ_COMMAND_PRIM_TYPE_TRIANGLES_ADJACENCY                    0x0000000B
#define   AQ_COMMAND_PRIM_TYPE_TRIANGLE_STRIP_ADJACENCY               0x0000000C
#define   AQ_COMMAND_PRIM_TYPE_PATCH_LIST                             0x0000000D


#define AQ_COMMAND_BYTE4_B0                                                  7:0
#define AQ_COMMAND_BYTE4_B0_End                                                7
#define AQ_COMMAND_BYTE4_B0_Start                                              0
#define AQ_COMMAND_BYTE4_B0_Type                                             U08

#define AQ_COMMAND_BYTE4_B1                                                 15:8
#define AQ_COMMAND_BYTE4_B1_End                                               15
#define AQ_COMMAND_BYTE4_B1_Start                                              8
#define AQ_COMMAND_BYTE4_B1_Type                                             U08

#define AQ_COMMAND_BYTE4_B2                                                23:16
#define AQ_COMMAND_BYTE4_B2_End                                               23
#define AQ_COMMAND_BYTE4_B2_Start                                             16
#define AQ_COMMAND_BYTE4_B2_Type                                             U08

#define AQ_COMMAND_BYTE4_B3                                                31:24
#define AQ_COMMAND_BYTE4_B3_End                                               31
#define AQ_COMMAND_BYTE4_B3_Start                                             24
#define AQ_COMMAND_BYTE4_B3_Type                                             U08


#define AQ_COMMAND_SHORT2_S0                                                15:0
#define AQ_COMMAND_SHORT2_S0_End                                              15
#define AQ_COMMAND_SHORT2_S0_Start                                             0
#define AQ_COMMAND_SHORT2_S0_Type                                            U16

#define AQ_COMMAND_SHORT2_S1                                               31:16
#define AQ_COMMAND_SHORT2_S1_End                                              31
#define AQ_COMMAND_SHORT2_S1_Start                                            16
#define AQ_COMMAND_SHORT2_S1_Type                                            U16


#define AQ_COMMAND_DEC3_D0                                                   9:0
#define AQ_COMMAND_DEC3_D0_End                                                 9
#define AQ_COMMAND_DEC3_D0_Start                                               0
#define AQ_COMMAND_DEC3_D0_Type                                              U10

#define AQ_COMMAND_DEC3_D1                                                 19:10
#define AQ_COMMAND_DEC3_D1_End                                                19
#define AQ_COMMAND_DEC3_D1_Start                                              10
#define AQ_COMMAND_DEC3_D1_Type                                              U10

#define AQ_COMMAND_DEC3_D2                                                 29:20
#define AQ_COMMAND_DEC3_D2_End                                                29
#define AQ_COMMAND_DEC3_D2_Start                                              20
#define AQ_COMMAND_DEC3_D2_Type                                              U10


#define AQ_COMMAND_FLOAT16_F0                                               15:0
#define AQ_COMMAND_FLOAT16_F0_End                                             15
#define AQ_COMMAND_FLOAT16_F0_Start                                            0
#define AQ_COMMAND_FLOAT16_F0_Type                                           U16

#define AQ_COMMAND_FLOAT16_F1                                              31:16
#define AQ_COMMAND_FLOAT16_F1_End                                             31
#define AQ_COMMAND_FLOAT16_F1_Start                                           16
#define AQ_COMMAND_FLOAT16_F1_Type                                           U16


#define StallCmdAddrs                                                     0x0F16
#define STALL_Address                                                    0x03C58
#define STALL_Count                                                            2

#define STALL_COMMAND_Index                                                    0
#define STALL_COMMAND_CmdAddrs                                            0x0F16

#define STALL_COMMAND_OPCODE                                               31:27
#define STALL_COMMAND_OPCODE_End                                              31
#define STALL_COMMAND_OPCODE_Start                                            27
#define STALL_COMMAND_OPCODE_Type                                            U05
#define   STALL_COMMAND_OPCODE_LOAD_STATE                                   0x01
#define   STALL_COMMAND_OPCODE_END                                          0x02
#define   STALL_COMMAND_OPCODE_NOP                                          0x03
#define   STALL_COMMAND_OPCODE_START_DE                                     0x04
#define   STALL_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                           0x05
#define   STALL_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE                     0x06
#define   STALL_COMMAND_OPCODE_WAIT                                         0x07
#define   STALL_COMMAND_OPCODE_LINK                                         0x08
#define   STALL_COMMAND_OPCODE_STALL                                        0x09
#define   STALL_COMMAND_OPCODE_CALL                                         0x0A
#define   STALL_COMMAND_OPCODE_RETURN                                       0x0B
#define   STALL_COMMAND_OPCODE_DRAW_INSTANCED                               0x0C
#define   STALL_COMMAND_OPCODE_CHIP_ENABLE                                  0x0D
#define   STALL_COMMAND_OPCODE_POP_OCCLUSION_QUERY                          0x0E
#define   STALL_COMMAND_OPCODE_FENCE                                        0x0F
#define   STALL_COMMAND_OPCODE_DRAW_INDIRECT                                0x10
#define   STALL_COMMAND_OPCODE_COMPUTE_INDIRECT                             0x11
#define   STALL_COMMAND_OPCODE_SNAP_TO_PAGE                                 0x13
#define   STALL_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                          0x14
#define   STALL_COMMAND_OPCODE_DRAW_DIRECT                                  0x15

#define STALL_STALL_Index                                                      1
#define STALL_STALL_CmdAddrs                                              0x0F17

#define STALL_STALL_SOURCE                                                   4:0
#define STALL_STALL_SOURCE_End                                                 4
#define STALL_STALL_SOURCE_Start                                               0
#define STALL_STALL_SOURCE_Type                                              U05
#define   STALL_STALL_SOURCE_FRONT_END                                      0x01
#define   STALL_STALL_SOURCE_VERTEX_SHADER                                  0x02
#define   STALL_STALL_SOURCE_PRIMITIVE_ASSEMBLY                             0x03
#define   STALL_STALL_SOURCE_SETUP                                          0x04
#define   STALL_STALL_SOURCE_RASTERIZER                                     0x05
#define   STALL_STALL_SOURCE_PIXEL_SHADER                                   0x06
#define   STALL_STALL_SOURCE_PIXEL_ENGINE                                   0x07
#define   STALL_STALL_SOURCE_MEMORY_CONTROLLER                              0x08
#define   STALL_STALL_SOURCE_DISPLAY_CONTROLLER0                            0x09
#define   STALL_STALL_SOURCE_DISPLAY_CONTROLLER1                            0x0A
#define   STALL_STALL_SOURCE_DRAWING_ENGINE                                 0x0B
#define   STALL_STALL_SOURCE_EVENT                                          0x0C
#define   STALL_STALL_SOURCE_RESOLVE                                        0x0D
#define   STALL_STALL_SOURCE_CHIP_ID                                        0x0F
#define   STALL_STALL_SOURCE_BLT_ENGINE                                     0x10

#define STALL_STALL_DESTINATION                                             12:8
#define STALL_STALL_DESTINATION_End                                           12
#define STALL_STALL_DESTINATION_Start                                          8
#define STALL_STALL_DESTINATION_Type                                         U05
#define   STALL_STALL_DESTINATION_FRONT_END                                 0x01
#define   STALL_STALL_DESTINATION_VERTEX_SHADER                             0x02
#define   STALL_STALL_DESTINATION_PRIMITIVE_ASSEMBLY                        0x03
#define   STALL_STALL_DESTINATION_SETUP                                     0x04
#define   STALL_STALL_DESTINATION_RASTERIZER                                0x05
#define   STALL_STALL_DESTINATION_PIXEL_SHADER                              0x06
#define   STALL_STALL_DESTINATION_PIXEL_ENGINE                              0x07
#define   STALL_STALL_DESTINATION_MEMORY_CONTROLLER                         0x08
#define   STALL_STALL_DESTINATION_DISPLAY_CONTROLLER0                       0x09
#define   STALL_STALL_DESTINATION_DISPLAY_CONTROLLER1                       0x0A
#define   STALL_STALL_DESTINATION_DRAWING_ENGINE                            0x0B
#define   STALL_STALL_DESTINATION_EVENT                                     0x0C
#define   STALL_STALL_DESTINATION_RESOLVE                                   0x0D
#define   STALL_STALL_DESTINATION_CHIP_ID                                   0x0F
#define   STALL_STALL_DESTINATION_BLT_ENGINE                                0x10

#define STALL_STALL_SOURCE_ID                                              23:20
#define STALL_STALL_SOURCE_ID_End                                             23
#define STALL_STALL_SOURCE_ID_Start                                           20
#define STALL_STALL_SOURCE_ID_Type                                           U04

#define STALL_STALL_DESTINATION_ID                                         27:24
#define STALL_STALL_DESTINATION_ID_End                                        27
#define STALL_STALL_DESTINATION_ID_Start                                      24
#define STALL_STALL_DESTINATION_ID_Type                                      U04

#define STALL_STALL_ID                                                     19:16
#define STALL_STALL_ID_End                                                    19
#define STALL_STALL_ID_Start                                                  16
#define STALL_STALL_ID_Type                                                  U04

#define STALL_STALL_FRONT_END                                              29:28
#define STALL_STALL_FRONT_END_End                                             29
#define STALL_STALL_FRONT_END_Start                                           28
#define STALL_STALL_FRONT_END_Type                                           U02
#define   STALL_STALL_FRONT_END_COMMAND                                      0x0
#define   STALL_STALL_FRONT_END_INDEX                                        0x1
#define   STALL_STALL_FRONT_END_VERTEX                                       0x2
#define   STALL_STALL_FRONT_END_PREFETCH                                     0x3


#define jmcmdDrawInstancedCmdAddrs                                        0x0F1C
#define JMCMD_DRAW_INSTANCED_Address                                     0x03C70
#define JMCMD_DRAW_INSTANCED_Count                                             3

#define JMCMD_DRAW_INSTANCED_COMMAND_Index                                     0
#define JMCMD_DRAW_INSTANCED_COMMAND_CmdAddrs                             0x0F1C


#define JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL                           26:24
#define JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_End                          26
#define JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_Start                        24
#define JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_Type                        U03

#define   JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_ALWAYS                    0x0

#define   JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_OCCLUSION_ONE             0x1

#define   JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_OCCLUSION_NONE            0x2
#define   JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_OCCLUSION_ONE_POP         0x3
#define   JMCMD_DRAW_INSTANCED_COMMAND_CONDITIONAL_OCCLUSION_NONE_POP        0x4

#define JMCMD_DRAW_INSTANCED_COMMAND_VERTEX_CACHE                          23:23
#define JMCMD_DRAW_INSTANCED_COMMAND_VERTEX_CACHE_End                         23
#define JMCMD_DRAW_INSTANCED_COMMAND_VERTEX_CACHE_Start                       23
#define JMCMD_DRAW_INSTANCED_COMMAND_VERTEX_CACHE_Type                       U01

#define   JMCMD_DRAW_INSTANCED_COMMAND_VERTEX_CACHE_FLUSH                    0x0

#define   JMCMD_DRAW_INSTANCED_COMMAND_VERTEX_CACHE_KEEP                     0x1


#define JMCMD_DRAW_INSTANCED_COMMAND_MODE                                  22:20
#define JMCMD_DRAW_INSTANCED_COMMAND_MODE_End                                 22
#define JMCMD_DRAW_INSTANCED_COMMAND_MODE_Start                               20
#define JMCMD_DRAW_INSTANCED_COMMAND_MODE_Type                               U03

#define   JMCMD_DRAW_INSTANCED_COMMAND_MODE_ARRAYS                           0x0

#define   JMCMD_DRAW_INSTANCED_COMMAND_MODE_ELEMENTS                         0x1

#define   JMCMD_DRAW_INSTANCED_COMMAND_MODE_STREAM                           0x2

#define   JMCMD_DRAW_INSTANCED_COMMAND_MODE_STREAM_OUT                       0x3

#define   JMCMD_DRAW_INSTANCED_COMMAND_MODE_STREAM_OUT_OCCLUDED              0x4


#define JMCMD_DRAW_INSTANCED_COMMAND_TYPE                                  19:16
#define JMCMD_DRAW_INSTANCED_COMMAND_TYPE_End                                 19
#define JMCMD_DRAW_INSTANCED_COMMAND_TYPE_Start                               16
#define JMCMD_DRAW_INSTANCED_COMMAND_TYPE_Type                               U04
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_POINT_LIST                       0x1
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_LINE_LIST                        0x2
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_LINE_STRIP                       0x3
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_TRIANGLE_LIST                    0x4
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_TRIANGLE_STRIP                   0x5
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_TRIANGLE_FAN                     0x6
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_LINE_LOOP                        0x7
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_RECTANGLE                        0x8
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_LINES_ADJACENCY                  0x9
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_LINE_STRIP_ADJACENCY             0xA
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_TRIANGLES_ADJACENCY              0xB
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_TRIANGLE_STRIP_ADJACENCY         0xC
#define   JMCMD_DRAW_INSTANCED_COMMAND_TYPE_PATCH_LIST                       0xD


#define JMCMD_DRAW_INSTANCED_COMMAND_INSTANCE_COUNT                         15:0
#define JMCMD_DRAW_INSTANCED_COMMAND_INSTANCE_COUNT_End                       15
#define JMCMD_DRAW_INSTANCED_COMMAND_INSTANCE_COUNT_Start                      0
#define JMCMD_DRAW_INSTANCED_COMMAND_INSTANCE_COUNT_Type                     U16

#define JMCMD_DRAW_INSTANCED_COMMAND_OPCODE                                31:27
#define JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_End                               31
#define JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_Start                             27
#define JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_Type                             U05
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_LOAD_STATE                    0x01
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_END                           0x02
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_NOP                           0x03
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_START_DE                      0x04
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE            0x05
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE      0x06
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_WAIT                          0x07
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_LINK                          0x08
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_STALL                         0x09
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_CALL                          0x0A
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_RETURN                        0x0B
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_DRAW_INSTANCED                0x0C
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_CHIP_ENABLE                   0x0D
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_POP_OCCLUSION_QUERY           0x0E
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_FENCE                         0x0F
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_DRAW_INDIRECT                 0x10
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_COMPUTE_INDIRECT              0x11
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_SNAP_TO_PAGE                  0x13
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_MULTI_DRAW_INDIRECT           0x14
#define   JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_DRAW_DIRECT                   0x15

#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_Index                                1
#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_CmdAddrs                        0x0F1D


#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_COUNT                             23:0
#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_COUNT_End                           23
#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_COUNT_Start                          0
#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_COUNT_Type                         U24


#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_INSTANCE_COUNT_HIGH              31:24
#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_INSTANCE_COUNT_HIGH_End             31
#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_INSTANCE_COUNT_HIGH_Start           24
#define JMCMD_DRAW_INSTANCED_VERTEX_COUNT_INSTANCE_COUNT_HIGH_Type           U08

#define JMCMD_DRAW_INSTANCED_VERTEX_START_Index                                2
#define JMCMD_DRAW_INSTANCED_VERTEX_START_CmdAddrs                        0x0F1E


#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX                             23:0
#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX_End                           23
#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX_Start                          0
#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX_Type                         U24

#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX_EXTENDED                   31:24
#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX_EXTENDED_End                  31
#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX_EXTENDED_Start                24
#define JMCMD_DRAW_INSTANCED_VERTEX_START_INDEX_EXTENDED_Type                U08


#define jmcmdChipEnableCmdAddrs                                           0x0F0F
#define JMCMD_CHIP_ENABLE_Address                                        0x03C3C
#define JMCMD_CHIP_ENABLE_Count                                                1

#define JMCMD_CHIP_ENABLE_COMMAND_Index                                        0
#define JMCMD_CHIP_ENABLE_COMMAND_CmdAddrs                                0x0F0F

#define JMCMD_CHIP_ENABLE_COMMAND_ENABLE                                    15:0
#define JMCMD_CHIP_ENABLE_COMMAND_ENABLE_End                                  15
#define JMCMD_CHIP_ENABLE_COMMAND_ENABLE_Start                                 0
#define JMCMD_CHIP_ENABLE_COMMAND_ENABLE_Type                                U16

#define JMCMD_CHIP_ENABLE_COMMAND_OPCODE                                   31:27
#define JMCMD_CHIP_ENABLE_COMMAND_OPCODE_End                                  31
#define JMCMD_CHIP_ENABLE_COMMAND_OPCODE_Start                                27
#define JMCMD_CHIP_ENABLE_COMMAND_OPCODE_Type                                U05
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_LOAD_STATE                       0x01
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_END                              0x02
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_NOP                              0x03
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_START_DE                         0x04
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE               0x05
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE         0x06
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_WAIT                             0x07
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_LINK                             0x08
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_STALL                            0x09
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_CALL                             0x0A
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_RETURN                           0x0B
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_DRAW_INSTANCED                   0x0C
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_CHIP_ENABLE                      0x0D
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_POP_OCCLUSION_QUERY              0x0E
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_FENCE                            0x0F
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_DRAW_INDIRECT                    0x10
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_COMPUTE_INDIRECT                 0x11
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_SNAP_TO_PAGE                     0x13
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT              0x14
#define   JMCMD_CHIP_ENABLE_COMMAND_OPCODE_DRAW_DIRECT                      0x15


#define jmcmdPopOcclusionQueryCmdAddrs                                    0x0F15
#define JMCMD_POP_OCCLUSION_QUERY_Address                                0x03C54
#define JMCMD_POP_OCCLUSION_QUERY_Count                                        1

#define JMCMD_POP_OCCLUSION_QUERY_COMMAND_Index                                0
#define JMCMD_POP_OCCLUSION_QUERY_COMMAND_CmdAddrs                        0x0F15

#define JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE                           31:27
#define JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_End                          31
#define JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_Start                        27
#define JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_Type                        U05
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_LOAD_STATE               0x01
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_END                      0x02
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_NOP                      0x03
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_START_DE                 0x04
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE       0x05
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE 0x06
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_WAIT                     0x07
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_LINK                     0x08
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_STALL                    0x09
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_CALL                     0x0A
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_RETURN                   0x0B
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_DRAW_INSTANCED           0x0C
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_CHIP_ENABLE              0x0D
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_POP_OCCLUSION_QUERY      0x0E
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_FENCE                    0x0F
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_DRAW_INDIRECT            0x10
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_COMPUTE_INDIRECT         0x11
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_SNAP_TO_PAGE             0x13
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_MULTI_DRAW_INDIRECT      0x14
#define   JMCMD_POP_OCCLUSION_QUERY_COMMAND_OPCODE_DRAW_DIRECT              0x15


#define jmcmdFenceCmdAddrs                                                0x0F20
#define JMCMD_FENCE_Address                                              0x03C80
#define JMCMD_FENCE_Count                                                      2

#define JMCMD_FENCE_COMMAND_Index                                              0
#define JMCMD_FENCE_COMMAND_CmdAddrs                                      0x0F20


#define JMCMD_FENCE_COMMAND_MODE                                           17:16
#define JMCMD_FENCE_COMMAND_MODE_End                                          17
#define JMCMD_FENCE_COMMAND_MODE_Start                                        16
#define JMCMD_FENCE_COMMAND_MODE_Type                                        U02

#define   JMCMD_FENCE_COMMAND_MODE_NON_ZERO                                  0x0

#define   JMCMD_FENCE_COMMAND_MODE_EQUALS                                    0x1

#define   JMCMD_FENCE_COMMAND_MODE_GREATER_EQUAL                             0x2


#define JMCMD_FENCE_COMMAND_DELAY                                           15:0
#define JMCMD_FENCE_COMMAND_DELAY_End                                         15
#define JMCMD_FENCE_COMMAND_DELAY_Start                                        0
#define JMCMD_FENCE_COMMAND_DELAY_Type                                       U16

#define JMCMD_FENCE_COMMAND_OPCODE                                         31:27
#define JMCMD_FENCE_COMMAND_OPCODE_End                                        31
#define JMCMD_FENCE_COMMAND_OPCODE_Start                                      27
#define JMCMD_FENCE_COMMAND_OPCODE_Type                                      U05
#define   JMCMD_FENCE_COMMAND_OPCODE_LOAD_STATE                             0x01
#define   JMCMD_FENCE_COMMAND_OPCODE_END                                    0x02
#define   JMCMD_FENCE_COMMAND_OPCODE_NOP                                    0x03
#define   JMCMD_FENCE_COMMAND_OPCODE_START_DE                               0x04
#define   JMCMD_FENCE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE                     0x05
#define   JMCMD_FENCE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE               0x06
#define   JMCMD_FENCE_COMMAND_OPCODE_WAIT                                   0x07
#define   JMCMD_FENCE_COMMAND_OPCODE_LINK                                   0x08
#define   JMCMD_FENCE_COMMAND_OPCODE_STALL                                  0x09
#define   JMCMD_FENCE_COMMAND_OPCODE_CALL                                   0x0A
#define   JMCMD_FENCE_COMMAND_OPCODE_RETURN                                 0x0B
#define   JMCMD_FENCE_COMMAND_OPCODE_DRAW_INSTANCED                         0x0C
#define   JMCMD_FENCE_COMMAND_OPCODE_CHIP_ENABLE                            0x0D
#define   JMCMD_FENCE_COMMAND_OPCODE_POP_OCCLUSION_QUERY                    0x0E
#define   JMCMD_FENCE_COMMAND_OPCODE_FENCE                                  0x0F
#define   JMCMD_FENCE_COMMAND_OPCODE_DRAW_INDIRECT                          0x10
#define   JMCMD_FENCE_COMMAND_OPCODE_COMPUTE_INDIRECT                       0x11
#define   JMCMD_FENCE_COMMAND_OPCODE_SNAP_TO_PAGE                           0x13
#define   JMCMD_FENCE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT                    0x14
#define   JMCMD_FENCE_COMMAND_OPCODE_DRAW_DIRECT                            0x15

#define JMCMD_FENCE_ADDRESS_Index                                              1
#define JMCMD_FENCE_ADDRESS_CmdAddrs                                      0x0F21

#define JMCMD_FENCE_ADDRESS_TYPE                                           31:31
#define JMCMD_FENCE_ADDRESS_TYPE_End                                          31
#define JMCMD_FENCE_ADDRESS_TYPE_Start                                        31
#define JMCMD_FENCE_ADDRESS_TYPE_Type                                        U01
#define   JMCMD_FENCE_ADDRESS_TYPE_SYSTEM                                    0x0
#define   JMCMD_FENCE_ADDRESS_TYPE_VIRTUAL_SYSTEM                            0x1

#define JMCMD_FENCE_ADDRESS_ADDRESS                                         30:0
#define JMCMD_FENCE_ADDRESS_ADDRESS_End                                       30
#define JMCMD_FENCE_ADDRESS_ADDRESS_Start                                      0
#define JMCMD_FENCE_ADDRESS_ADDRESS_Type                                     U31


#define jmcmdDrawIndirectCmdAddrs                                         0x0F22
#define JMCMD_DRAW_INDIRECT_Address                                      0x03C88
#define JMCMD_DRAW_INDIRECT_Count                                              2

#define JMCMD_DRAW_INDIRECT_COMMAND_Index                                      0
#define JMCMD_DRAW_INDIRECT_COMMAND_CmdAddrs                              0x0F22


#define JMCMD_DRAW_INDIRECT_COMMAND_TFB_STREAM_INDEX                       19:18
#define JMCMD_DRAW_INDIRECT_COMMAND_TFB_STREAM_INDEX_End                      19
#define JMCMD_DRAW_INDIRECT_COMMAND_TFB_STREAM_INDEX_Start                    18
#define JMCMD_DRAW_INDIRECT_COMMAND_TFB_STREAM_INDEX_Type                    U02


#define JMCMD_DRAW_INDIRECT_COMMAND_HEADER                                 16:16
#define JMCMD_DRAW_INDIRECT_COMMAND_HEADER_End                                16
#define JMCMD_DRAW_INDIRECT_COMMAND_HEADER_Start                              16
#define JMCMD_DRAW_INDIRECT_COMMAND_HEADER_Type                              U01

#define   JMCMD_DRAW_INDIRECT_COMMAND_HEADER_DRAW_INDIRECT                   0x0

#define   JMCMD_DRAW_INDIRECT_COMMAND_HEADER_TRANSFORM_FEEDBACK              0x1

#define JMCMD_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE                      14:14
#define JMCMD_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_End                     14
#define JMCMD_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_Start                   14
#define JMCMD_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_Type                   U01

#define   JMCMD_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_DISABLE              0x0

#define   JMCMD_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_ENABLE               0x1

#define JMCMD_DRAW_INDIRECT_COMMAND_VERTEX_CACHE                           12:12
#define JMCMD_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_End                          12
#define JMCMD_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_Start                        12
#define JMCMD_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_Type                        U01

#define   JMCMD_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_FLUSH                     0x0

#define   JMCMD_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_KEEP                      0x1


#define JMCMD_DRAW_INDIRECT_COMMAND_MODE                                     8:8
#define JMCMD_DRAW_INDIRECT_COMMAND_MODE_End                                   8
#define JMCMD_DRAW_INDIRECT_COMMAND_MODE_Start                                 8
#define JMCMD_DRAW_INDIRECT_COMMAND_MODE_Type                                U01

#define   JMCMD_DRAW_INDIRECT_COMMAND_MODE_ARRAYS                            0x0

#define   JMCMD_DRAW_INDIRECT_COMMAND_MODE_ELEMENTS                          0x1


#define JMCMD_DRAW_INDIRECT_COMMAND_TYPE                                     3:0
#define JMCMD_DRAW_INDIRECT_COMMAND_TYPE_End                                   3
#define JMCMD_DRAW_INDIRECT_COMMAND_TYPE_Start                                 0
#define JMCMD_DRAW_INDIRECT_COMMAND_TYPE_Type                                U04
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_POINT_LIST                        0x1
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_LINE_LIST                         0x2
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_LINE_STRIP                        0x3
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_LIST                     0x4
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_STRIP                    0x5
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_FAN                      0x6
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_LINE_LOOP                         0x7
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_RECTANGLE                         0x8
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_LINES_ADJACENCY                   0x9
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_LINE_STRIP_ADJACENCY              0xA
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLES_ADJACENCY               0xB
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_STRIP_ADJACENCY          0xC
#define   JMCMD_DRAW_INDIRECT_COMMAND_TYPE_PATCH_LIST                        0xD

#define JMCMD_DRAW_INDIRECT_COMMAND_OPCODE                                 31:27
#define JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_End                                31
#define JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_Start                              27
#define JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_Type                              U05
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_LOAD_STATE                     0x01
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_END                            0x02
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_NOP                            0x03
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_START_DE                       0x04
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE             0x05
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE       0x06
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_WAIT                           0x07
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_LINK                           0x08
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_STALL                          0x09
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_CALL                           0x0A
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_RETURN                         0x0B
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_DRAW_INSTANCED                 0x0C
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_CHIP_ENABLE                    0x0D
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_POP_OCCLUSION_QUERY            0x0E
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_FENCE                          0x0F
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_DRAW_INDIRECT                  0x10
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_COMPUTE_INDIRECT               0x11
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_SNAP_TO_PAGE                   0x13
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_MULTI_DRAW_INDIRECT            0x14
#define   JMCMD_DRAW_INDIRECT_COMMAND_OPCODE_DRAW_DIRECT                    0x15

#define JMCMD_DRAW_INDIRECT_ADDRESS_Index                                      1
#define JMCMD_DRAW_INDIRECT_ADDRESS_CmdAddrs                              0x0F23


#define JMCMD_DRAW_INDIRECT_ADDRESS_ADDRESS                                 31:0
#define JMCMD_DRAW_INDIRECT_ADDRESS_ADDRESS_End                               31
#define JMCMD_DRAW_INDIRECT_ADDRESS_ADDRESS_Start                              0
#define JMCMD_DRAW_INDIRECT_ADDRESS_ADDRESS_Type                             U32


#define jmcmdComputeIndirectCmdAddrs                                      0x0F24
#define JMCMD_COMPUTE_INDIRECT_Address                                   0x03C90
#define JMCMD_COMPUTE_INDIRECT_Count                                           2

#define JMCMD_COMPUTE_INDIRECT_COMMAND_Index                                   0
#define JMCMD_COMPUTE_INDIRECT_COMMAND_CmdAddrs                           0x0F24

#define JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE                              31:27
#define JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_End                             31
#define JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_Start                           27
#define JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_Type                           U05
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_LOAD_STATE                  0x01
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_END                         0x02
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_NOP                         0x03
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_START_DE                    0x04
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE          0x05
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE    0x06
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_WAIT                        0x07
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_LINK                        0x08
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_STALL                       0x09
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_CALL                        0x0A
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_RETURN                      0x0B
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_DRAW_INSTANCED              0x0C
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_CHIP_ENABLE                 0x0D
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_POP_OCCLUSION_QUERY         0x0E
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_FENCE                       0x0F
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_DRAW_INDIRECT               0x10
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_COMPUTE_INDIRECT            0x11
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_SNAP_TO_PAGE                0x13
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_MULTI_DRAW_INDIRECT         0x14
#define   JMCMD_COMPUTE_INDIRECT_COMMAND_OPCODE_DRAW_DIRECT                 0x15

#define JMCMD_COMPUTE_INDIRECT_ADDRESS_Index                                   1
#define JMCMD_COMPUTE_INDIRECT_ADDRESS_CmdAddrs                           0x0F25


#define JMCMD_COMPUTE_INDIRECT_ADDRESS_ADDRESS                              31:0
#define JMCMD_COMPUTE_INDIRECT_ADDRESS_ADDRESS_End                            31
#define JMCMD_COMPUTE_INDIRECT_ADDRESS_ADDRESS_Start                           0
#define JMCMD_COMPUTE_INDIRECT_ADDRESS_ADDRESS_Type                          U32


#define jmcmdStall3DBltSemaphoreCmdAddrs                                  0x0F1F
#define JMCMD_STALL3_DBLT_SEMAPHORE_Address                              0x03C7C
#define JMCMD_STALL3_DBLT_SEMAPHORE_Count                                      1

#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_Index                              0
#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_CmdAddrs                      0x0F1F


#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_SEMAPHORE                        7:0
#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_SEMAPHORE_End                      7
#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_SEMAPHORE_Start                    0
#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_SEMAPHORE_Type                   U08

#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE                         31:27
#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_End                        31
#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_Start                      27
#define JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_Type                      U05
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_LOAD_STATE             0x01
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_END                    0x02
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_NOP                    0x03
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_START_DE               0x04
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE     0x05
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE 0x06
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_WAIT                   0x07
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_LINK                   0x08
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_STALL                  0x09
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_CALL                   0x0A
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_RETURN                 0x0B
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_DRAW_INSTANCED         0x0C
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_CHIP_ENABLE            0x0D
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_POP_OCCLUSION_QUERY    0x0E
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_FENCE                  0x0F
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_DRAW_INDIRECT          0x10
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_COMPUTE_INDIRECT       0x11
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_SNAP_TO_PAGE           0x13
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT    0x14
#define   JMCMD_STALL3_DBLT_SEMAPHORE_COMMAND_OPCODE_DRAW_DIRECT            0x15


#define jmcmdSnapToPageCmdAddrs                                           0x0F26
#define JMCMD_SNAP_TO_PAGE_Address                                       0x03C98
#define JMCMD_SNAP_TO_PAGE_Count                                               1

#define JMCMD_SNAP_TO_PAGE_COMMAND_Index                                       0
#define JMCMD_SNAP_TO_PAGE_COMMAND_CmdAddrs                               0x0F26


#define JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT                                    4:0
#define JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_End                                  4
#define JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_Start                                0
#define JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_Type                               U05

#define   JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_NONE                            0x00

#define   JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_VS                              0x01

#define   JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_TCS                             0x02

#define   JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_TES                             0x04

#define   JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_GS                              0x08

#define   JMCMD_SNAP_TO_PAGE_COMMAND_CLIENT_PS                              0x10

#define JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE                                  31:27
#define JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_End                                 31
#define JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_Start                               27
#define JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_Type                               U05
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_LOAD_STATE                      0x01
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_END                             0x02
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_NOP                             0x03
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_START_DE                        0x04
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE              0x05
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE        0x06
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_WAIT                            0x07
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_LINK                            0x08
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_STALL                           0x09
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_CALL                            0x0A
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_RETURN                          0x0B
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_DRAW_INSTANCED                  0x0C
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_CHIP_ENABLE                     0x0D
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_POP_OCCLUSION_QUERY             0x0E
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_FENCE                           0x0F
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_DRAW_INDIRECT                   0x10
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_COMPUTE_INDIRECT                0x11
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_SNAP_TO_PAGE                    0x13
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_MULTI_DRAW_INDIRECT             0x14
#define   JMCMD_SNAP_TO_PAGE_COMMAND_OPCODE_DRAW_DIRECT                     0x15


#define jmcmdMultiDrawIndirectCmdAddrs                                    0x0F28
#define JMCMD_MULTI_DRAW_INDIRECT_Address                                0x03CA0
#define JMCMD_MULTI_DRAW_INDIRECT_Count                                        3

#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_Index                                0
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_CmdAddrs                        0x0F28


#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_HEADER                           16:16
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_HEADER_End                          16
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_HEADER_Start                        16
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_HEADER_Type                        U01

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_HEADER_DRAW_INDIRECT             0x0

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_HEADER_TRANSFORM_FEEDBACK        0x1

#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE                14:14
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_End               14
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_Start             14
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_Type             U01

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_DISABLE        0x0

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_USE_BASE_INSTANCE_ENABLE         0x1

#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_VERTEX_CACHE                     12:12
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_End                    12
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_Start                  12
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_Type                  U01

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_FLUSH               0x0

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_VERTEX_CACHE_KEEP                0x1


#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_MODE                               8:8
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_MODE_End                             8
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_MODE_Start                           8
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_MODE_Type                          U01

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_MODE_ARRAYS                      0x0

#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_MODE_ELEMENTS                    0x1


#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE                               3:0
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_End                             3
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_Start                           0
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_Type                          U04
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_POINT_LIST                  0x1
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_LINE_LIST                   0x2
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_LINE_STRIP                  0x3
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_LIST               0x4
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_STRIP              0x5
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_FAN                0x6
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_LINE_LOOP                   0x7
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_RECTANGLE                   0x8
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_LINES_ADJACENCY             0x9
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_LINE_STRIP_ADJACENCY        0xA
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLES_ADJACENCY         0xB
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_TRIANGLE_STRIP_ADJACENCY    0xC
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_TYPE_PATCH_LIST                  0xD

#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE                           31:27
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_End                          31
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_Start                        27
#define JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_Type                        U05
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_LOAD_STATE               0x01
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_END                      0x02
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_NOP                      0x03
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_START_DE                 0x04
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE       0x05
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE 0x06
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_WAIT                     0x07
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_LINK                     0x08
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_STALL                    0x09
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_CALL                     0x0A
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_RETURN                   0x0B
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_DRAW_INSTANCED           0x0C
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_CHIP_ENABLE              0x0D
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_POP_OCCLUSION_QUERY      0x0E
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_FENCE                    0x0F
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_DRAW_INDIRECT            0x10
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_COMPUTE_INDIRECT         0x11
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_SNAP_TO_PAGE             0x13
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_MULTI_DRAW_INDIRECT      0x14
#define   JMCMD_MULTI_DRAW_INDIRECT_COMMAND_OPCODE_DRAW_DIRECT              0x15

#define JMCMD_MULTI_DRAW_INDIRECT_ADDRESS_Index                                1
#define JMCMD_MULTI_DRAW_INDIRECT_ADDRESS_CmdAddrs                        0x0F29


#define JMCMD_MULTI_DRAW_INDIRECT_ADDRESS_ADDRESS                           31:0
#define JMCMD_MULTI_DRAW_INDIRECT_ADDRESS_ADDRESS_End                         31
#define JMCMD_MULTI_DRAW_INDIRECT_ADDRESS_ADDRESS_Start                        0
#define JMCMD_MULTI_DRAW_INDIRECT_ADDRESS_ADDRESS_Type                       U32

#define JMCMD_MULTI_DRAW_INDIRECT_DATA_Index                                   2
#define JMCMD_MULTI_DRAW_INDIRECT_DATA_CmdAddrs                           0x0F2A


#define JMCMD_MULTI_DRAW_INDIRECT_DATA_DRAW_COUNT                           17:0
#define JMCMD_MULTI_DRAW_INDIRECT_DATA_DRAW_COUNT_End                         17
#define JMCMD_MULTI_DRAW_INDIRECT_DATA_DRAW_COUNT_Start                        0
#define JMCMD_MULTI_DRAW_INDIRECT_DATA_DRAW_COUNT_Type                       U18

#define JMCMD_MULTI_DRAW_INDIRECT_DATA_STRIDE                              31:18
#define JMCMD_MULTI_DRAW_INDIRECT_DATA_STRIDE_End                             31
#define JMCMD_MULTI_DRAW_INDIRECT_DATA_STRIDE_Start                           18
#define JMCMD_MULTI_DRAW_INDIRECT_DATA_STRIDE_Type                           U14


#define jmcmdDrawDirectCmdAddrs                                           0x0F30
#define JMCMD_DRAW_DIRECT_Address                                        0x03CC0
#define JMCMD_DRAW_DIRECT_Count                                                5

#define JMCMD_DRAW_DIRECT_COMMAND_Index                                        0
#define JMCMD_DRAW_DIRECT_COMMAND_CmdAddrs                                0x0F30


#define JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL                              26:24
#define JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_End                             26
#define JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_Start                           24
#define JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_Type                           U03

#define   JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_ALWAYS                       0x0

#define   JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_OCCLUSION_ONE                0x1

#define   JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_OCCLUSION_NONE               0x2
#define   JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_OCCLUSION_ONE_POP            0x3
#define   JMCMD_DRAW_DIRECT_COMMAND_CONDITIONAL_OCCLUSION_NONE_POP           0x4

#define JMCMD_DRAW_DIRECT_COMMAND_VERTEX_CACHE                             23:23
#define JMCMD_DRAW_DIRECT_COMMAND_VERTEX_CACHE_End                            23
#define JMCMD_DRAW_DIRECT_COMMAND_VERTEX_CACHE_Start                          23
#define JMCMD_DRAW_DIRECT_COMMAND_VERTEX_CACHE_Type                          U01

#define   JMCMD_DRAW_DIRECT_COMMAND_VERTEX_CACHE_FLUSH                       0x0

#define   JMCMD_DRAW_DIRECT_COMMAND_VERTEX_CACHE_KEEP                        0x1


#define JMCMD_DRAW_DIRECT_COMMAND_MODE                                     22:20
#define JMCMD_DRAW_DIRECT_COMMAND_MODE_End                                    22
#define JMCMD_DRAW_DIRECT_COMMAND_MODE_Start                                  20
#define JMCMD_DRAW_DIRECT_COMMAND_MODE_Type                                  U03

#define   JMCMD_DRAW_DIRECT_COMMAND_MODE_ARRAYS                              0x0

#define   JMCMD_DRAW_DIRECT_COMMAND_MODE_ELEMENTS                            0x1


#define JMCMD_DRAW_DIRECT_COMMAND_TYPE                                     19:16
#define JMCMD_DRAW_DIRECT_COMMAND_TYPE_End                                    19
#define JMCMD_DRAW_DIRECT_COMMAND_TYPE_Start                                  16
#define JMCMD_DRAW_DIRECT_COMMAND_TYPE_Type                                  U04
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_POINT_LIST                          0x1
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_LINE_LIST                           0x2
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_LINE_STRIP                          0x3
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_TRIANGLE_LIST                       0x4
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_TRIANGLE_STRIP                      0x5
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_TRIANGLE_FAN                        0x6
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_LINE_LOOP                           0x7
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_RECTANGLE                           0x8
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_LINES_ADJACENCY                     0x9
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_LINE_STRIP_ADJACENCY                0xA
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_TRIANGLES_ADJACENCY                 0xB
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_TRIANGLE_STRIP_ADJACENCY            0xC
#define   JMCMD_DRAW_DIRECT_COMMAND_TYPE_PATCH_LIST                          0xD


#define JMCMD_DRAW_DIRECT_COMMAND_INSTANCE_COUNT                            15:0
#define JMCMD_DRAW_DIRECT_COMMAND_INSTANCE_COUNT_End                          15
#define JMCMD_DRAW_DIRECT_COMMAND_INSTANCE_COUNT_Start                         0
#define JMCMD_DRAW_DIRECT_COMMAND_INSTANCE_COUNT_Type                        U16

#define JMCMD_DRAW_DIRECT_COMMAND_OPCODE                                   31:27
#define JMCMD_DRAW_DIRECT_COMMAND_OPCODE_End                                  31
#define JMCMD_DRAW_DIRECT_COMMAND_OPCODE_Start                                27
#define JMCMD_DRAW_DIRECT_COMMAND_OPCODE_Type                                U05
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_LOAD_STATE                       0x01
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_END                              0x02
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_NOP                              0x03
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_START_DE                         0x04
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_DX8_DRAW_PRIMITIVE               0x05
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_DX8_DRAW_INDEX_PRIMITIVE         0x06
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_WAIT                             0x07
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_LINK                             0x08
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_STALL                            0x09
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_CALL                             0x0A
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_RETURN                           0x0B
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_DRAW_INSTANCED                   0x0C
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_CHIP_ENABLE                      0x0D
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_POP_OCCLUSION_QUERY              0x0E
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_FENCE                            0x0F
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_DRAW_INDIRECT                    0x10
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_COMPUTE_INDIRECT                 0x11
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_SNAP_TO_PAGE                     0x13
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_MULTI_DRAW_INDIRECT              0x14
#define   JMCMD_DRAW_DIRECT_COMMAND_OPCODE_DRAW_DIRECT                      0x15

#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_Index                                   1
#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_CmdAddrs                           0x0F31


#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_COUNT                                23:0
#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_COUNT_End                              23
#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_COUNT_Start                             0
#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_COUNT_Type                            U24


#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_INSTANCE_COUNT_HIGH                 31:24
#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_INSTANCE_COUNT_HIGH_End                31
#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_INSTANCE_COUNT_HIGH_Start              24
#define JMCMD_DRAW_DIRECT_VERTEX_COUNT_INSTANCE_COUNT_HIGH_Type              U08

#define JMCMD_DRAW_DIRECT_VERTEX_START_Index                                   2
#define JMCMD_DRAW_DIRECT_VERTEX_START_CmdAddrs                           0x0F32


#define JMCMD_DRAW_DIRECT_VERTEX_START_VERTEX_START                         23:0
#define JMCMD_DRAW_DIRECT_VERTEX_START_VERTEX_START_End                       23
#define JMCMD_DRAW_DIRECT_VERTEX_START_VERTEX_START_Start                      0
#define JMCMD_DRAW_DIRECT_VERTEX_START_VERTEX_START_Type                     U24

#define JMCMD_DRAW_DIRECT_VERTEX_START_INDEX_EXTENDED                      31:24
#define JMCMD_DRAW_DIRECT_VERTEX_START_INDEX_EXTENDED_End                     31
#define JMCMD_DRAW_DIRECT_VERTEX_START_INDEX_EXTENDED_Start                   24
#define JMCMD_DRAW_DIRECT_VERTEX_START_INDEX_EXTENDED_Type                   U08

#define JMCMD_DRAW_DIRECT_INSTANCE_START_Index                                 3
#define JMCMD_DRAW_DIRECT_INSTANCE_START_CmdAddrs                         0x0F33


#define JMCMD_DRAW_DIRECT_INSTANCE_START_INSTANCE_START                     31:0
#define JMCMD_DRAW_DIRECT_INSTANCE_START_INSTANCE_START_End                   31
#define JMCMD_DRAW_DIRECT_INSTANCE_START_INSTANCE_START_Start                  0
#define JMCMD_DRAW_DIRECT_INSTANCE_START_INSTANCE_START_Type                 U32

#define JMCMD_DRAW_DIRECT_INDEX_START_Index                                    4
#define JMCMD_DRAW_DIRECT_INDEX_START_CmdAddrs                            0x0F34


#define JMCMD_DRAW_DIRECT_INDEX_START_INDEX_START                           31:0
#define JMCMD_DRAW_DIRECT_INDEX_START_INDEX_START_End                         31
#define JMCMD_DRAW_DIRECT_INDEX_START_INDEX_START_Start                        0
#define JMCMD_DRAW_DIRECT_INDEX_START_INDEX_START_Type                       U32


#endif


