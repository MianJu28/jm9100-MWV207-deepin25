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




#ifndef __AQShader_h__
#define __AQShader_h__


#define AQVertexShaderEndPCRegAddrs                                       0x0200
#define AQ_VERTEX_SHADER_END_PC_Address                                  0x00800
#define AQ_VERTEX_SHADER_END_PC_MSB                                           15
#define AQ_VERTEX_SHADER_END_PC_LSB                                            0
#define AQ_VERTEX_SHADER_END_PC_BLK                                            0
#define AQ_VERTEX_SHADER_END_PC_Count                                          1
#define AQ_VERTEX_SHADER_END_PC_FieldMask                             0x00000FFF
#define AQ_VERTEX_SHADER_END_PC_ReadMask                              0x00000FFF
#define AQ_VERTEX_SHADER_END_PC_WriteMask                             0x00000FFF
#define AQ_VERTEX_SHADER_END_PC_ResetValue                            0x00000000

#define AQ_VERTEX_SHADER_END_PC_ADDRESS                                     11:0
#define AQ_VERTEX_SHADER_END_PC_ADDRESS_End                                   11
#define AQ_VERTEX_SHADER_END_PC_ADDRESS_Start                                  0
#define AQ_VERTEX_SHADER_END_PC_ADDRESS_Type                                 U12



#define AQVertexShaderInstRegAddrs                                        0x1000
#define AQ_VERTEX_SHADER_INST_Address                                    0x04000
#define AQ_VERTEX_SHADER_INST_MSB                                             15
#define AQ_VERTEX_SHADER_INST_LSB                                             10
#define AQ_VERTEX_SHADER_INST_BLK                                             10
#define AQ_VERTEX_SHADER_INST_Count                                         1024
#define AQ_VERTEX_SHADER_INST_FieldMask                               0xFFFFFFFF
#define AQ_VERTEX_SHADER_INST_ReadMask                                0xFFFFFFFF
#define AQ_VERTEX_SHADER_INST_WriteMask                               0xFFFFFFFF
#define AQ_VERTEX_SHADER_INST_ResetValue                              0x00000000

#define AQ_VERTEX_SHADER_INST_INSTRUCTION                                   31:0
#define AQ_VERTEX_SHADER_INST_INSTRUCTION_End                                 31
#define AQ_VERTEX_SHADER_INST_INSTRUCTION_Start                                0
#define AQ_VERTEX_SHADER_INST_INSTRUCTION_Type                               U32

#define AQVertexShaderOutputControlRegAddrs                               0x0201
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_Address                          0x00804
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_MSB                                   15
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_LSB                                    0
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_BLK                                    0
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_Count                                  1
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_FieldMask                     0xBF3F3F3F
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ReadMask                      0xBF3F3F3F
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_WriteMask                     0xBF3F3F3F
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ResetValue                    0x00000000

#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_COUNT                                5:0
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_COUNT_End                              5
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_COUNT_Start                            0
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_COUNT_Type                           U06

#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS16                           13:8
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS16_End                         13
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS16_Start                        8
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS16_Type                       U06

#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS17                          21:16
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS17_End                         21
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS17_Start                       16
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS17_Type                       U06

#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS18                          29:24
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS18_End                         29
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS18_Start                       24
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_ADDRESS18_Type                       U06

#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_OUTPUT_PACKER                      31:31
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_OUTPUT_PACKER_End                     31
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_OUTPUT_PACKER_Start                   31
#define AQ_VERTEX_SHADER_OUTPUT_CONTROL_OUTPUT_PACKER_Type                   U01
#define   AQ_VERTEX_SHADER_OUTPUT_CONTROL_OUTPUT_PACKER_ENABLE               0x0
#define   AQ_VERTEX_SHADER_OUTPUT_CONTROL_OUTPUT_PACKER_DISABLE              0x1



#define AQVertexShaderOutputRegAddrs                                      0x0204
#define AQ_VERTEX_SHADER_OUTPUT_Address                                  0x00810
#define AQ_VERTEX_SHADER_OUTPUT_MSB                                           15
#define AQ_VERTEX_SHADER_OUTPUT_LSB                                            2
#define AQ_VERTEX_SHADER_OUTPUT_BLK                                            2
#define AQ_VERTEX_SHADER_OUTPUT_Count                                          4
#define AQ_VERTEX_SHADER_OUTPUT_FieldMask                             0x3F3F3F3F
#define AQ_VERTEX_SHADER_OUTPUT_ReadMask                              0x3F3F3F3F
#define AQ_VERTEX_SHADER_OUTPUT_WriteMask                             0x3F3F3F3F
#define AQ_VERTEX_SHADER_OUTPUT_ResetValue                            0x00000000

#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS0                                     5:0
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS0_End                                   5
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS0_Start                                 0
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS0_Type                                U06

#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS1                                    13:8
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS1_End                                  13
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS1_Start                                 8
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS1_Type                                U06

#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS2                                   21:16
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS2_End                                  21
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS2_Start                                16
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS2_Type                                U06

#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS3                                   29:24
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS3_End                                  29
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS3_Start                                24
#define AQ_VERTEX_SHADER_OUTPUT_ADDRESS3_Type                                U06

#define AQVertexShaderInputControlRegAddrs                                0x0202
#define AQ_VERTEX_SHADER_INPUT_CONTROL_Address                           0x00808
#define AQ_VERTEX_SHADER_INPUT_CONTROL_MSB                                    15
#define AQ_VERTEX_SHADER_INPUT_CONTROL_LSB                                     0
#define AQ_VERTEX_SHADER_INPUT_CONTROL_BLK                                     0
#define AQ_VERTEX_SHADER_INPUT_CONTROL_Count                                   1
#define AQ_VERTEX_SHADER_INPUT_CONTROL_FieldMask                      0xC03F1F3F
#define AQ_VERTEX_SHADER_INPUT_CONTROL_ReadMask                       0xC03F1F3F
#define AQ_VERTEX_SHADER_INPUT_CONTROL_WriteMask                      0xC03F1F3F
#define AQ_VERTEX_SHADER_INPUT_CONTROL_ResetValue                     0x00000000

#define AQ_VERTEX_SHADER_INPUT_CONTROL_COUNT                                 5:0
#define AQ_VERTEX_SHADER_INPUT_CONTROL_COUNT_End                               5
#define AQ_VERTEX_SHADER_INPUT_CONTROL_COUNT_Start                             0
#define AQ_VERTEX_SHADER_INPUT_CONTROL_COUNT_Type                            U06

#define AQ_VERTEX_SHADER_INPUT_CONTROL_TIMEOUT                              12:8
#define AQ_VERTEX_SHADER_INPUT_CONTROL_TIMEOUT_End                            12
#define AQ_VERTEX_SHADER_INPUT_CONTROL_TIMEOUT_Start                           8
#define AQ_VERTEX_SHADER_INPUT_CONTROL_TIMEOUT_Type                          U05

#define AQ_VERTEX_SHADER_INPUT_CONTROL_ADDRESS16                           21:16
#define AQ_VERTEX_SHADER_INPUT_CONTROL_ADDRESS16_End                          21
#define AQ_VERTEX_SHADER_INPUT_CONTROL_ADDRESS16_Start                        16
#define AQ_VERTEX_SHADER_INPUT_CONTROL_ADDRESS16_Type                        U06

#define AQ_VERTEX_SHADER_INPUT_CONTROL_PERF_BUG_FIX                        30:30
#define AQ_VERTEX_SHADER_INPUT_CONTROL_PERF_BUG_FIX_End                       30
#define AQ_VERTEX_SHADER_INPUT_CONTROL_PERF_BUG_FIX_Start                     30
#define AQ_VERTEX_SHADER_INPUT_CONTROL_PERF_BUG_FIX_Type                     U01
#define   AQ_VERTEX_SHADER_INPUT_CONTROL_PERF_BUG_FIX_ENABLE                 0x0
#define   AQ_VERTEX_SHADER_INPUT_CONTROL_PERF_BUG_FIX_DISABLE                0x1

#define AQ_VERTEX_SHADER_INPUT_CONTROL_VERTEX_INST_ID                      31:31
#define AQ_VERTEX_SHADER_INPUT_CONTROL_VERTEX_INST_ID_End                     31
#define AQ_VERTEX_SHADER_INPUT_CONTROL_VERTEX_INST_ID_Start                   31
#define AQ_VERTEX_SHADER_INPUT_CONTROL_VERTEX_INST_ID_Type                   U01
#define   AQ_VERTEX_SHADER_INPUT_CONTROL_VERTEX_INST_ID_DISABLE              0x0
#define   AQ_VERTEX_SHADER_INPUT_CONTROL_VERTEX_INST_ID_ENABLE               0x1



#define AQVertexShaderInputRegAddrs                                       0x0208
#define AQ_VERTEX_SHADER_INPUT_Address                                   0x00820
#define AQ_VERTEX_SHADER_INPUT_MSB                                            15
#define AQ_VERTEX_SHADER_INPUT_LSB                                             2
#define AQ_VERTEX_SHADER_INPUT_BLK                                             2
#define AQ_VERTEX_SHADER_INPUT_Count                                           4
#define AQ_VERTEX_SHADER_INPUT_FieldMask                              0x3F3F3F3F
#define AQ_VERTEX_SHADER_INPUT_ReadMask                               0x3F3F3F3F
#define AQ_VERTEX_SHADER_INPUT_WriteMask                              0x3F3F3F3F
#define AQ_VERTEX_SHADER_INPUT_ResetValue                             0x00000000

#define AQ_VERTEX_SHADER_INPUT_ADDRESS0                                      5:0
#define AQ_VERTEX_SHADER_INPUT_ADDRESS0_End                                    5
#define AQ_VERTEX_SHADER_INPUT_ADDRESS0_Start                                  0
#define AQ_VERTEX_SHADER_INPUT_ADDRESS0_Type                                 U06

#define AQ_VERTEX_SHADER_INPUT_ADDRESS1                                     13:8
#define AQ_VERTEX_SHADER_INPUT_ADDRESS1_End                                   13
#define AQ_VERTEX_SHADER_INPUT_ADDRESS1_Start                                  8
#define AQ_VERTEX_SHADER_INPUT_ADDRESS1_Type                                 U06

#define AQ_VERTEX_SHADER_INPUT_ADDRESS2                                    21:16
#define AQ_VERTEX_SHADER_INPUT_ADDRESS2_End                                   21
#define AQ_VERTEX_SHADER_INPUT_ADDRESS2_Start                                 16
#define AQ_VERTEX_SHADER_INPUT_ADDRESS2_Type                                 U06

#define AQ_VERTEX_SHADER_INPUT_ADDRESS3                                    29:24
#define AQ_VERTEX_SHADER_INPUT_ADDRESS3_End                                   29
#define AQ_VERTEX_SHADER_INPUT_ADDRESS3_Start                                 24
#define AQ_VERTEX_SHADER_INPUT_ADDRESS3_Type                                 U06

#define AQVertexShaderTemporaryRegisterControlRegAddrs                    0x0203
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_Address              0x0080C
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_MSB                       15
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_LSB                        0
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_BLK                        0
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_Count                      1
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_FieldMask         0x0000007F
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_ReadMask          0x0000007F
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_WriteMask         0x0000007F
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_ResetValue        0x00000000

#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT                    6:0
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT_End                  6
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT_Start                0
#define AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT_Type               U07

#define AQVertexShaderLoadBalancingRegAddrs                               0x020C
#define AQ_VERTEX_SHADER_LOAD_BALANCING_Address                          0x00830
#define AQ_VERTEX_SHADER_LOAD_BALANCING_MSB                                   15
#define AQ_VERTEX_SHADER_LOAD_BALANCING_LSB                                    0
#define AQ_VERTEX_SHADER_LOAD_BALANCING_BLK                                    0
#define AQ_VERTEX_SHADER_LOAD_BALANCING_Count                                  1
#define AQ_VERTEX_SHADER_LOAD_BALANCING_FieldMask                     0x0F3FFFFF
#define AQ_VERTEX_SHADER_LOAD_BALANCING_ReadMask                      0x0F3FFFFF
#define AQ_VERTEX_SHADER_LOAD_BALANCING_WriteMask                     0x0F3FFFFF
#define AQ_VERTEX_SHADER_LOAD_BALANCING_ResetValue                    0x00000000

#define AQ_VERTEX_SHADER_LOAD_BALANCING_SCALE                                7:0
#define AQ_VERTEX_SHADER_LOAD_BALANCING_SCALE_End                              7
#define AQ_VERTEX_SHADER_LOAD_BALANCING_SCALE_Start                            0
#define AQ_VERTEX_SHADER_LOAD_BALANCING_SCALE_Type                           U08

#define AQ_VERTEX_SHADER_LOAD_BALANCING_MIN                                 15:8
#define AQ_VERTEX_SHADER_LOAD_BALANCING_MIN_End                               15
#define AQ_VERTEX_SHADER_LOAD_BALANCING_MIN_Start                              8
#define AQ_VERTEX_SHADER_LOAD_BALANCING_MIN_Type                             U08

#define AQ_VERTEX_SHADER_LOAD_BALANCING_MAX                                21:16
#define AQ_VERTEX_SHADER_LOAD_BALANCING_MAX_End                               21
#define AQ_VERTEX_SHADER_LOAD_BALANCING_MAX_Start                             16
#define AQ_VERTEX_SHADER_LOAD_BALANCING_MAX_Type                             U06

#define AQ_VERTEX_SHADER_LOAD_BALANCING_FAVOR_PS                           27:24
#define AQ_VERTEX_SHADER_LOAD_BALANCING_FAVOR_PS_End                          27
#define AQ_VERTEX_SHADER_LOAD_BALANCING_FAVOR_PS_Start                        24
#define AQ_VERTEX_SHADER_LOAD_BALANCING_FAVOR_PS_Type                        U04

#define AQVertexShaderPerformanceCounterRegAddrs                          0x020D
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_Address                     0x00834
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_MSB                              15
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_LSB                               0
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_BLK                               0
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_Count                             1
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_FieldMask                0xFFFFFFFF
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_ReadMask                 0xFFFFFFFF
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_WriteMask                0xFFFFFFFF
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_ResetValue               0x00000000


#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL0                            7:0
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL0_End                          7
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL0_Start                        0
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL0_Type                       U08


#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL1                           15:8
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL1_End                         15
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL1_Start                        8
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL1_Type                       U08


#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL2                          23:16
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL2_End                         23
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL2_Start                       16
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL2_Type                       U08


#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL3                          31:24
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL3_End                         31
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL3_Start                       24
#define AQ_VERTEX_SHADER_PERFORMANCE_COUNTER_SEL3_Type                       U08



#define AQVertexShaderConstRegAddrs                                       0x1400
#define AQ_VERTEX_SHADER_CONST_Address                                   0x05000
#define AQ_VERTEX_SHADER_CONST_MSB                                            15
#define AQ_VERTEX_SHADER_CONST_LSB                                            10
#define AQ_VERTEX_SHADER_CONST_BLK                                            10
#define AQ_VERTEX_SHADER_CONST_Count                                        1024
#define AQ_VERTEX_SHADER_CONST_FieldMask                              0xFFFFFFFF
#define AQ_VERTEX_SHADER_CONST_ReadMask                               0xFFFFFFFF
#define AQ_VERTEX_SHADER_CONST_WriteMask                              0xFFFFFFFF
#define AQ_VERTEX_SHADER_CONST_ResetValue                             0x00000000

#define AQ_VERTEX_SHADER_CONST_VALUE                                        31:0
#define AQ_VERTEX_SHADER_CONST_VALUE_End                                      31
#define AQ_VERTEX_SHADER_CONST_VALUE_Start                                     0
#define AQ_VERTEX_SHADER_CONST_VALUE_Type                                    U32

#define AQVertexShaderStartPCRegAddrs                                     0x020E
#define AQ_VERTEX_SHADER_START_PC_Address                                0x00838
#define AQ_VERTEX_SHADER_START_PC_MSB                                         15
#define AQ_VERTEX_SHADER_START_PC_LSB                                          0
#define AQ_VERTEX_SHADER_START_PC_BLK                                          0
#define AQ_VERTEX_SHADER_START_PC_Count                                        1
#define AQ_VERTEX_SHADER_START_PC_FieldMask                           0x03FF0FFF
#define AQ_VERTEX_SHADER_START_PC_ReadMask                            0x03FF0FFF
#define AQ_VERTEX_SHADER_START_PC_WriteMask                           0x03FF0FFF
#define AQ_VERTEX_SHADER_START_PC_ResetValue                          0x00000000

#define AQ_VERTEX_SHADER_START_PC_PC_OFFSET                                 11:0
#define AQ_VERTEX_SHADER_START_PC_PC_OFFSET_End                               11
#define AQ_VERTEX_SHADER_START_PC_PC_OFFSET_Start                              0
#define AQ_VERTEX_SHADER_START_PC_PC_OFFSET_Type                             U12

#define AQ_VERTEX_SHADER_START_PC_CONST_OFFSET                             25:16
#define AQ_VERTEX_SHADER_START_PC_CONST_OFFSET_End                            25
#define AQ_VERTEX_SHADER_START_PC_CONST_OFFSET_Start                          16
#define AQ_VERTEX_SHADER_START_PC_CONST_OFFSET_Type                          U10




#define AQShBistControlRegAddrs                                           0x020F
#define AQ_SH_BIST_CONTROL_Address                                       0x0083C
#define AQ_SH_BIST_CONTROL_MSB                                                15
#define AQ_SH_BIST_CONTROL_LSB                                                 0
#define AQ_SH_BIST_CONTROL_BLK                                                 0
#define AQ_SH_BIST_CONTROL_Count                                               1
#define AQ_SH_BIST_CONTROL_FieldMask                                  0x00000003
#define AQ_SH_BIST_CONTROL_ReadMask                                   0x00000003
#define AQ_SH_BIST_CONTROL_WriteMask                                  0x00000003
#define AQ_SH_BIST_CONTROL_ResetValue                                 0x00000000

#define AQ_SH_BIST_CONTROL_RESET                                             0:0
#define AQ_SH_BIST_CONTROL_RESET_End                                           0
#define AQ_SH_BIST_CONTROL_RESET_Start                                         0
#define AQ_SH_BIST_CONTROL_RESET_Type                                        U01
#define   AQ_SH_BIST_CONTROL_RESET_NOT_RESET                                 0x0
#define   AQ_SH_BIST_CONTROL_RESET_RESET                                     0x1

#define AQ_SH_BIST_CONTROL_MODE                                              1:1
#define AQ_SH_BIST_CONTROL_MODE_End                                            1
#define AQ_SH_BIST_CONTROL_MODE_Start                                          1
#define AQ_SH_BIST_CONTROL_MODE_Type                                         U01
#define   AQ_SH_BIST_CONTROL_MODE_NOT_BIST_MODE                              0x0
#define   AQ_SH_BIST_CONTROL_MODE_BIST_MODE                                  0x1




#define AQShBistStatus0RegAddrs                                           0x0210
#define AQ_SH_BIST_STATUS0_Address                                       0x00840
#define AQ_SH_BIST_STATUS0_MSB                                                15
#define AQ_SH_BIST_STATUS0_LSB                                                 0
#define AQ_SH_BIST_STATUS0_BLK                                                 0
#define AQ_SH_BIST_STATUS0_Count                                               1
#define AQ_SH_BIST_STATUS0_FieldMask                                  0x00000001
#define AQ_SH_BIST_STATUS0_ReadMask                                   0x00000001
#define AQ_SH_BIST_STATUS0_WriteMask                                  0x00000001
#define AQ_SH_BIST_STATUS0_ResetValue                                 0x00000000

#define AQ_SH_BIST_STATUS0_DONE                                              0:0
#define AQ_SH_BIST_STATUS0_DONE_End                                            0
#define AQ_SH_BIST_STATUS0_DONE_Start                                          0
#define AQ_SH_BIST_STATUS0_DONE_Type                                         U01
#define   AQ_SH_BIST_STATUS0_DONE_NOT_DONE                                   0x0
#define   AQ_SH_BIST_STATUS0_DONE_DONE                                       0x1




#define AQShBistStatus1RegAddrs                                           0x0211
#define AQ_SH_BIST_STATUS1_Address                                       0x00844
#define AQ_SH_BIST_STATUS1_MSB                                                15
#define AQ_SH_BIST_STATUS1_LSB                                                 0
#define AQ_SH_BIST_STATUS1_BLK                                                 0
#define AQ_SH_BIST_STATUS1_Count                                               1
#define AQ_SH_BIST_STATUS1_FieldMask                                  0xFFFFFFFF
#define AQ_SH_BIST_STATUS1_ReadMask                                   0xFFFFFFFF
#define AQ_SH_BIST_STATUS1_WriteMask                                  0xFFFFFFFF
#define AQ_SH_BIST_STATUS1_ResetValue                                 0x00000000

#define AQ_SH_BIST_STATUS1_BM_ERROR                                         31:0
#define AQ_SH_BIST_STATUS1_BM_ERROR_End                                       31
#define AQ_SH_BIST_STATUS1_BM_ERROR_Start                                      0
#define AQ_SH_BIST_STATUS1_BM_ERROR_Type                                     U32




#define AQShBistStatus2RegAddrs                                           0x0212
#define AQ_SH_BIST_STATUS2_Address                                       0x00848
#define AQ_SH_BIST_STATUS2_MSB                                                15
#define AQ_SH_BIST_STATUS2_LSB                                                 0
#define AQ_SH_BIST_STATUS2_BLK                                                 0
#define AQ_SH_BIST_STATUS2_Count                                               1
#define AQ_SH_BIST_STATUS2_FieldMask                                  0xFFFFFFFF
#define AQ_SH_BIST_STATUS2_ReadMask                                   0xFFFFFFFF
#define AQ_SH_BIST_STATUS2_WriteMask                                  0xFFFFFFFF
#define AQ_SH_BIST_STATUS2_ResetValue                                 0x00000000

#define AQ_SH_BIST_STATUS2_BM_ERROR                                         31:0
#define AQ_SH_BIST_STATUS2_BM_ERROR_End                                       31
#define AQ_SH_BIST_STATUS2_BM_ERROR_Start                                      0
#define AQ_SH_BIST_STATUS2_BM_ERROR_Type                                     U32




#define AQShStatusRegAddrs                                                0x0213
#define AQ_SH_STATUS_Address                                             0x0084C
#define AQ_SH_STATUS_MSB                                                      15
#define AQ_SH_STATUS_LSB                                                       0
#define AQ_SH_STATUS_BLK                                                       0
#define AQ_SH_STATUS_Count                                                     1
#define AQ_SH_STATUS_FieldMask                                        0x007FFFFF
#define AQ_SH_STATUS_ReadMask                                         0x007FFFFF
#define AQ_SH_STATUS_WriteMask                                        0x007FFFFF
#define AQ_SH_STATUS_ResetValue                                       0x00000000

#define AQ_SH_STATUS_VERTEX_INPUT_INTERFACE_IDLE                             0:0
#define AQ_SH_STATUS_VERTEX_INPUT_INTERFACE_IDLE_End                           0
#define AQ_SH_STATUS_VERTEX_INPUT_INTERFACE_IDLE_Start                         0
#define AQ_SH_STATUS_VERTEX_INPUT_INTERFACE_IDLE_Type                        U01

#define AQ_SH_STATUS_VERTEX_INPUT_BUFFER_IDLE                                1:1
#define AQ_SH_STATUS_VERTEX_INPUT_BUFFER_IDLE_End                              1
#define AQ_SH_STATUS_VERTEX_INPUT_BUFFER_IDLE_Start                            1
#define AQ_SH_STATUS_VERTEX_INPUT_BUFFER_IDLE_Type                           U01

#define AQ_SH_STATUS_VERTEX_GROUP_ALLOCATION_EMPTY                           2:2
#define AQ_SH_STATUS_VERTEX_GROUP_ALLOCATION_EMPTY_End                         2
#define AQ_SH_STATUS_VERTEX_GROUP_ALLOCATION_EMPTY_Start                       2
#define AQ_SH_STATUS_VERTEX_GROUP_ALLOCATION_EMPTY_Type                      U01

#define AQ_SH_STATUS_VERTEX_OUTPUT_BUFFER_EMPTY                              3:3
#define AQ_SH_STATUS_VERTEX_OUTPUT_BUFFER_EMPTY_End                            3
#define AQ_SH_STATUS_VERTEX_OUTPUT_BUFFER_EMPTY_Start                          3
#define AQ_SH_STATUS_VERTEX_OUTPUT_BUFFER_EMPTY_Type                         U01

#define AQ_SH_STATUS_VERTEX_OUTPUT_INTERFACE_IDLE                            4:4
#define AQ_SH_STATUS_VERTEX_OUTPUT_INTERFACE_IDLE_End                          4
#define AQ_SH_STATUS_VERTEX_OUTPUT_INTERFACE_IDLE_Start                        4
#define AQ_SH_STATUS_VERTEX_OUTPUT_INTERFACE_IDLE_Type                       U01

#define AQ_SH_STATUS_PIXEL_INPUT_INTERFACE_IDLE                              5:5
#define AQ_SH_STATUS_PIXEL_INPUT_INTERFACE_IDLE_End                            5
#define AQ_SH_STATUS_PIXEL_INPUT_INTERFACE_IDLE_Start                          5
#define AQ_SH_STATUS_PIXEL_INPUT_INTERFACE_IDLE_Type                         U01

#define AQ_SH_STATUS_PIXEL_INPUT_BUFFER_IDLE                                 6:6
#define AQ_SH_STATUS_PIXEL_INPUT_BUFFER_IDLE_End                               6
#define AQ_SH_STATUS_PIXEL_INPUT_BUFFER_IDLE_Start                             6
#define AQ_SH_STATUS_PIXEL_INPUT_BUFFER_IDLE_Type                            U01

#define AQ_SH_STATUS_PIXEL_GROUP_ALLOCATION_EMPTY                            7:7
#define AQ_SH_STATUS_PIXEL_GROUP_ALLOCATION_EMPTY_End                          7
#define AQ_SH_STATUS_PIXEL_GROUP_ALLOCATION_EMPTY_Start                        7
#define AQ_SH_STATUS_PIXEL_GROUP_ALLOCATION_EMPTY_Type                       U01

#define AQ_SH_STATUS_PIXEL_OUTPUT_BUFFER_EMPTY                               8:8
#define AQ_SH_STATUS_PIXEL_OUTPUT_BUFFER_EMPTY_End                             8
#define AQ_SH_STATUS_PIXEL_OUTPUT_BUFFER_EMPTY_Start                           8
#define AQ_SH_STATUS_PIXEL_OUTPUT_BUFFER_EMPTY_Type                          U01

#define AQ_SH_STATUS_PIXEL_OUTPUT_INTERFACE_IDLE                             9:9
#define AQ_SH_STATUS_PIXEL_OUTPUT_INTERFACE_IDLE_End                           9
#define AQ_SH_STATUS_PIXEL_OUTPUT_INTERFACE_IDLE_Start                         9
#define AQ_SH_STATUS_PIXEL_OUTPUT_INTERFACE_IDLE_Type                        U01

#define AQ_SH_STATUS_SH2TX_VALID_                                          10:10
#define AQ_SH_STATUS_SH2TX_VALID__End                                         10
#define AQ_SH_STATUS_SH2TX_VALID__Start                                       10
#define AQ_SH_STATUS_SH2TX_VALID__Type                                       U01

#define AQ_SH_STATUS_SH2TX_READY                                           11:11
#define AQ_SH_STATUS_SH2TX_READY_End                                          11
#define AQ_SH_STATUS_SH2TX_READY_Start                                        11
#define AQ_SH_STATUS_SH2TX_READY_Type                                        U01

#define AQ_SH_STATUS_SH2PE_VALID_                                          12:12
#define AQ_SH_STATUS_SH2PE_VALID__End                                         12
#define AQ_SH_STATUS_SH2PE_VALID__Start                                       12
#define AQ_SH_STATUS_SH2PE_VALID__Type                                       U01

#define AQ_SH_STATUS_SH2PE_READY                                           13:13
#define AQ_SH_STATUS_SH2PE_READY_End                                          13
#define AQ_SH_STATUS_SH2PE_READY_Start                                        13
#define AQ_SH_STATUS_SH2PE_READY_Type                                        U01

#define AQ_SH_STATUS_SH2PA_VALID_                                          14:14
#define AQ_SH_STATUS_SH2PA_VALID__End                                         14
#define AQ_SH_STATUS_SH2PA_VALID__Start                                       14
#define AQ_SH_STATUS_SH2PA_VALID__Type                                       U01

#define AQ_SH_STATUS_SH2PA_READY                                           15:15
#define AQ_SH_STATUS_SH2PA_READY_End                                          15
#define AQ_SH_STATUS_SH2PA_READY_Start                                        15
#define AQ_SH_STATUS_SH2PA_READY_Type                                        U01

#define AQ_SH_STATUS_FE2SH_VALID_                                          16:16
#define AQ_SH_STATUS_FE2SH_VALID__End                                         16
#define AQ_SH_STATUS_FE2SH_VALID__Start                                       16
#define AQ_SH_STATUS_FE2SH_VALID__Type                                       U01

#define AQ_SH_STATUS_FE2SH_READY                                           17:17
#define AQ_SH_STATUS_FE2SH_READY_End                                          17
#define AQ_SH_STATUS_FE2SH_READY_Start                                        17
#define AQ_SH_STATUS_FE2SH_READY_Type                                        U01

#define AQ_SH_STATUS_TX2SH_VALID_                                          18:18
#define AQ_SH_STATUS_TX2SH_VALID__End                                         18
#define AQ_SH_STATUS_TX2SH_VALID__Start                                       18
#define AQ_SH_STATUS_TX2SH_VALID__Type                                       U01

#define AQ_SH_STATUS_TX2SH_READY                                           19:19
#define AQ_SH_STATUS_TX2SH_READY_End                                          19
#define AQ_SH_STATUS_TX2SH_READY_Start                                        19
#define AQ_SH_STATUS_TX2SH_READY_Type                                        U01

#define AQ_SH_STATUS_RA2SH_VALID_                                          20:20
#define AQ_SH_STATUS_RA2SH_VALID__End                                         20
#define AQ_SH_STATUS_RA2SH_VALID__Start                                       20
#define AQ_SH_STATUS_RA2SH_VALID__Type                                       U01

#define AQ_SH_STATUS_RA2SH_READY                                           21:21
#define AQ_SH_STATUS_RA2SH_READY_End                                          21
#define AQ_SH_STATUS_RA2SH_READY_Start                                        21
#define AQ_SH_STATUS_RA2SH_READY_Type                                        U01

#define AQ_SH_STATUS_TEXTURE_SIDEBAND_FIFO_EMPTY                           22:22
#define AQ_SH_STATUS_TEXTURE_SIDEBAND_FIFO_EMPTY_End                          22
#define AQ_SH_STATUS_TEXTURE_SIDEBAND_FIFO_EMPTY_Start                        22
#define AQ_SH_STATUS_TEXTURE_SIDEBAND_FIFO_EMPTY_Type                        U01



#define mwv207regVSBalanceIntervalRegAddrs                                0x0214
#define MWV207REG_VS_BALANCE_INTERVAL_Address                            0x00850
#define MWV207REG_VS_BALANCE_INTERVAL_MSB                                     15
#define MWV207REG_VS_BALANCE_INTERVAL_LSB                                      0
#define MWV207REG_VS_BALANCE_INTERVAL_BLK                                      0
#define MWV207REG_VS_BALANCE_INTERVAL_Count                                    1
#define MWV207REG_VS_BALANCE_INTERVAL_FieldMask                       0xFFFFFFFF
#define MWV207REG_VS_BALANCE_INTERVAL_ReadMask                        0xFFFFFFFF
#define MWV207REG_VS_BALANCE_INTERVAL_WriteMask                       0xFFFFFFFF
#define MWV207REG_VS_BALANCE_INTERVAL_ResetValue                      0x000003E8

#define MWV207REG_VS_BALANCE_INTERVAL_INTERVAL                              31:0
#define MWV207REG_VS_BALANCE_INTERVAL_INTERVAL_End                            31
#define MWV207REG_VS_BALANCE_INTERVAL_INTERVAL_Start                           0
#define MWV207REG_VS_BALANCE_INTERVAL_INTERVAL_Type                          U32



#define mwv207regVSBalanceThresholdRegAddrs                               0x0215
#define MWV207REG_VS_BALANCE_THRESHOLD_Address                           0x00854
#define MWV207REG_VS_BALANCE_THRESHOLD_MSB                                    15
#define MWV207REG_VS_BALANCE_THRESHOLD_LSB                                     0
#define MWV207REG_VS_BALANCE_THRESHOLD_BLK                                     0
#define MWV207REG_VS_BALANCE_THRESHOLD_Count                                   1
#define MWV207REG_VS_BALANCE_THRESHOLD_FieldMask                      0xFFFFFFFF
#define MWV207REG_VS_BALANCE_THRESHOLD_ReadMask                       0xFFFFFFFF
#define MWV207REG_VS_BALANCE_THRESHOLD_WriteMask                      0xFFFFFFFF
#define MWV207REG_VS_BALANCE_THRESHOLD_ResetValue                     0x00000100

#define MWV207REG_VS_BALANCE_THRESHOLD_THRESHOLD                            31:0
#define MWV207REG_VS_BALANCE_THRESHOLD_THRESHOLD_End                          31
#define MWV207REG_VS_BALANCE_THRESHOLD_THRESHOLD_Start                         0
#define MWV207REG_VS_BALANCE_THRESHOLD_THRESHOLD_Type                        U32

#define mwv207regVSBalanceShiftRegAddrs                                   0x0216
#define MWV207REG_VS_BALANCE_SHIFT_Address                               0x00858
#define MWV207REG_VS_BALANCE_SHIFT_MSB                                        15
#define MWV207REG_VS_BALANCE_SHIFT_LSB                                         0
#define MWV207REG_VS_BALANCE_SHIFT_BLK                                         0
#define MWV207REG_VS_BALANCE_SHIFT_Count                                       1
#define MWV207REG_VS_BALANCE_SHIFT_FieldMask                          0xFF3FFBFF
#define MWV207REG_VS_BALANCE_SHIFT_ReadMask                           0xFF3FFBFF
#define MWV207REG_VS_BALANCE_SHIFT_WriteMask                          0xFF3FFBFF
#define MWV207REG_VS_BALANCE_SHIFT_ResetValue                         0x00001005


#define MWV207REG_VS_BALANCE_SHIFT_COARSE                                    9:0
#define MWV207REG_VS_BALANCE_SHIFT_COARSE_End                                  9
#define MWV207REG_VS_BALANCE_SHIFT_COARSE_Start                                0
#define MWV207REG_VS_BALANCE_SHIFT_COARSE_Type                               U10


#define MWV207REG_VS_BALANCE_SHIFT_ENABLE                                  11:11
#define MWV207REG_VS_BALANCE_SHIFT_ENABLE_End                                 11
#define MWV207REG_VS_BALANCE_SHIFT_ENABLE_Start                               11
#define MWV207REG_VS_BALANCE_SHIFT_ENABLE_Type                               U01
#define   MWV207REG_VS_BALANCE_SHIFT_ENABLE_DISABLE                          0x0
#define   MWV207REG_VS_BALANCE_SHIFT_ENABLE_ENABLE                           0x1


#define MWV207REG_VS_BALANCE_SHIFT_FINE                                    21:12
#define MWV207REG_VS_BALANCE_SHIFT_FINE_End                                   21
#define MWV207REG_VS_BALANCE_SHIFT_FINE_Start                                 12
#define MWV207REG_VS_BALANCE_SHIFT_FINE_Type                                 U10


#define MWV207REG_VS_BALANCE_SHIFT_MAX                                     31:24
#define MWV207REG_VS_BALANCE_SHIFT_MAX_End                                    31
#define MWV207REG_VS_BALANCE_SHIFT_MAX_Start                                  24
#define MWV207REG_VS_BALANCE_SHIFT_MAX_Type                                  U08




#define mwv207regVSShaderCodeRegAddrs                                     0x3000
#define MWV207REG_VS_SHADER_CODE_Address                                 0x0C000
#define MWV207REG_VS_SHADER_CODE_MSB                                          15
#define MWV207REG_VS_SHADER_CODE_LSB                                          12
#define MWV207REG_VS_SHADER_CODE_BLK                                          12
#define MWV207REG_VS_SHADER_CODE_Count                                      4096
#define MWV207REG_VS_SHADER_CODE_FieldMask                            0xFFFFFFFF
#define MWV207REG_VS_SHADER_CODE_ReadMask                             0xFFFFFFFF
#define MWV207REG_VS_SHADER_CODE_WriteMask                            0xFFFFFFFF
#define MWV207REG_VS_SHADER_CODE_ResetValue                           0x00000000

#define MWV207REG_VS_SHADER_CODE_INSTRUCTION                                31:0
#define MWV207REG_VS_SHADER_CODE_INSTRUCTION_End                              31
#define MWV207REG_VS_SHADER_CODE_INSTRUCTION_Start                             0
#define MWV207REG_VS_SHADER_CODE_INSTRUCTION_Type                            U32



#define mwv207regVSProgramRegAddrs                                        0x0217
#define MWV207REG_VS_PROGRAM_Address                                     0x0085C
#define MWV207REG_VS_PROGRAM_MSB                                              15
#define MWV207REG_VS_PROGRAM_LSB                                               0
#define MWV207REG_VS_PROGRAM_BLK                                               0
#define MWV207REG_VS_PROGRAM_Count                                             1
#define MWV207REG_VS_PROGRAM_FieldMask                                0xFFFFFFFF
#define MWV207REG_VS_PROGRAM_ReadMask                                 0xFFFFFFFF
#define MWV207REG_VS_PROGRAM_WriteMask                                0xFFFFFFFF
#define MWV207REG_VS_PROGRAM_ResetValue                               0x00000000


#define MWV207REG_VS_PROGRAM_START                                          15:0
#define MWV207REG_VS_PROGRAM_START_End                                        15
#define MWV207REG_VS_PROGRAM_START_Start                                       0
#define MWV207REG_VS_PROGRAM_START_Type                                      U16


#define MWV207REG_VS_PROGRAM_END                                           31:16
#define MWV207REG_VS_PROGRAM_END_End                                          31
#define MWV207REG_VS_PROGRAM_END_Start                                        16
#define MWV207REG_VS_PROGRAM_END_Type                                        U16




#define mwv207regShaderConfigRegAddrs                                     0x0218
#define MWV207REG_SHADER_CONFIG_Address                                  0x00860
#define MWV207REG_SHADER_CONFIG_MSB                                           15
#define MWV207REG_SHADER_CONFIG_LSB                                            0
#define MWV207REG_SHADER_CONFIG_BLK                                            0
#define MWV207REG_SHADER_CONFIG_Count                                          1
#define MWV207REG_SHADER_CONFIG_FieldMask                             0xF3FFD511
#define MWV207REG_SHADER_CONFIG_ReadMask                              0xF3FFD511
#define MWV207REG_SHADER_CONFIG_WriteMask                             0xF3FFD511
#define MWV207REG_SHADER_CONFIG_ResetValue                            0x00000000


#define MWV207REG_SHADER_CONFIG_INST_DECODE_SELECT                           0:0
#define MWV207REG_SHADER_CONFIG_INST_DECODE_SELECT_End                         0
#define MWV207REG_SHADER_CONFIG_INST_DECODE_SELECT_Start                       0
#define MWV207REG_SHADER_CONFIG_INST_DECODE_SELECT_Type                      U01
#define   MWV207REG_SHADER_CONFIG_INST_DECODE_SELECT_VS                      0x0
#define   MWV207REG_SHADER_CONFIG_INST_DECODE_SELECT_PS                      0x1


#define MWV207REG_SHADER_CONFIG_UNIFORM_DECODE_SELECT                        4:4
#define MWV207REG_SHADER_CONFIG_UNIFORM_DECODE_SELECT_End                      4
#define MWV207REG_SHADER_CONFIG_UNIFORM_DECODE_SELECT_Start                    4
#define MWV207REG_SHADER_CONFIG_UNIFORM_DECODE_SELECT_Type                   U01
#define   MWV207REG_SHADER_CONFIG_UNIFORM_DECODE_SELECT_VS                   0x0
#define   MWV207REG_SHADER_CONFIG_UNIFORM_DECODE_SELECT_PS                   0x1

#define MWV207REG_SHADER_CONFIG_OUT_COLOR_ROUNDING                           8:8
#define MWV207REG_SHADER_CONFIG_OUT_COLOR_ROUNDING_End                         8
#define MWV207REG_SHADER_CONFIG_OUT_COLOR_ROUNDING_Start                       8
#define MWV207REG_SHADER_CONFIG_OUT_COLOR_ROUNDING_Type                      U01
#define   MWV207REG_SHADER_CONFIG_OUT_COLOR_ROUNDING_DISABLE                 0x0
#define   MWV207REG_SHADER_CONFIG_OUT_COLOR_ROUNDING_ENABLE                  0x1

#define MWV207REG_SHADER_CONFIG_LOAD_STORE_USE_PACK_MODE                   10:10
#define MWV207REG_SHADER_CONFIG_LOAD_STORE_USE_PACK_MODE_End                  10
#define MWV207REG_SHADER_CONFIG_LOAD_STORE_USE_PACK_MODE_Start                10
#define MWV207REG_SHADER_CONFIG_LOAD_STORE_USE_PACK_MODE_Type                U01
#define   MWV207REG_SHADER_CONFIG_LOAD_STORE_USE_PACK_MODE_DISABLE           0x0
#define   MWV207REG_SHADER_CONFIG_LOAD_STORE_USE_PACK_MODE_ENABLE            0x1


#define MWV207REG_SHADER_CONFIG_RTNE_ROUNDING                              12:12
#define MWV207REG_SHADER_CONFIG_RTNE_ROUNDING_End                             12
#define MWV207REG_SHADER_CONFIG_RTNE_ROUNDING_Start                           12
#define MWV207REG_SHADER_CONFIG_RTNE_ROUNDING_Type                           U01
#define   MWV207REG_SHADER_CONFIG_RTNE_ROUNDING_DISABLE                      0x0
#define   MWV207REG_SHADER_CONFIG_RTNE_ROUNDING_ENABLE                       0x1


#define MWV207REG_SHADER_CONFIG_ENDIAN_CONTROL                             14:14
#define MWV207REG_SHADER_CONFIG_ENDIAN_CONTROL_End                            14
#define MWV207REG_SHADER_CONFIG_ENDIAN_CONTROL_Start                          14
#define MWV207REG_SHADER_CONFIG_ENDIAN_CONTROL_Type                          U01
#define   MWV207REG_SHADER_CONFIG_ENDIAN_CONTROL_LITTLE                      0x0
#define   MWV207REG_SHADER_CONFIG_ENDIAN_CONTROL_BIG                         0x1


#define MWV207REG_SHADER_CONFIG_HALF_REGISTER_DEPENDENCY                   15:15
#define MWV207REG_SHADER_CONFIG_HALF_REGISTER_DEPENDENCY_End                  15
#define MWV207REG_SHADER_CONFIG_HALF_REGISTER_DEPENDENCY_Start                15
#define MWV207REG_SHADER_CONFIG_HALF_REGISTER_DEPENDENCY_Type                U01
#define   MWV207REG_SHADER_CONFIG_HALF_REGISTER_DEPENDENCY_ENABLE            0x0
#define   MWV207REG_SHADER_CONFIG_HALF_REGISTER_DEPENDENCY_DISABLE           0x1

#define MWV207REG_SHADER_CONFIG_SAMPLER_DECODE_SELECT                      16:16
#define MWV207REG_SHADER_CONFIG_SAMPLER_DECODE_SELECT_End                     16
#define MWV207REG_SHADER_CONFIG_SAMPLER_DECODE_SELECT_Start                   16
#define MWV207REG_SHADER_CONFIG_SAMPLER_DECODE_SELECT_Type                   U01
#define   MWV207REG_SHADER_CONFIG_SAMPLER_DECODE_SELECT_PS                   0x0
#define   MWV207REG_SHADER_CONFIG_SAMPLER_DECODE_SELECT_VS                   0x1


#define MWV207REG_SHADER_CONFIG_PRESWIZZLE_POWER_OPTIMIZATION              17:17
#define MWV207REG_SHADER_CONFIG_PRESWIZZLE_POWER_OPTIMIZATION_End             17
#define MWV207REG_SHADER_CONFIG_PRESWIZZLE_POWER_OPTIMIZATION_Start           17
#define MWV207REG_SHADER_CONFIG_PRESWIZZLE_POWER_OPTIMIZATION_Type           U01
#define   MWV207REG_SHADER_CONFIG_PRESWIZZLE_POWER_OPTIMIZATION_ENABLE       0x0
#define   MWV207REG_SHADER_CONFIG_PRESWIZZLE_POWER_OPTIMIZATION_DISABLE      0x1


#define MWV207REG_SHADER_CONFIG_PIXEL_XY_FRAC_POWER_OPTIMIZATION           18:18
#define MWV207REG_SHADER_CONFIG_PIXEL_XY_FRAC_POWER_OPTIMIZATION_End          18
#define MWV207REG_SHADER_CONFIG_PIXEL_XY_FRAC_POWER_OPTIMIZATION_Start        18
#define MWV207REG_SHADER_CONFIG_PIXEL_XY_FRAC_POWER_OPTIMIZATION_Type        U01
#define   MWV207REG_SHADER_CONFIG_PIXEL_XY_FRAC_POWER_OPTIMIZATION_ENABLE    0x0
#define   MWV207REG_SHADER_CONFIG_PIXEL_XY_FRAC_POWER_OPTIMIZATION_DISABLE   0x1


#define MWV207REG_SHADER_CONFIG_A0_POWER_OPTIMIZATION                      19:19
#define MWV207REG_SHADER_CONFIG_A0_POWER_OPTIMIZATION_End                     19
#define MWV207REG_SHADER_CONFIG_A0_POWER_OPTIMIZATION_Start                   19
#define MWV207REG_SHADER_CONFIG_A0_POWER_OPTIMIZATION_Type                   U01
#define   MWV207REG_SHADER_CONFIG_A0_POWER_OPTIMIZATION_ENABLE               0x0
#define   MWV207REG_SHADER_CONFIG_A0_POWER_OPTIMIZATION_DISABLE              0x1

#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_OFFSET_SHIFT                   23:20
#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_OFFSET_SHIFT_End                  23
#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_OFFSET_SHIFT_Start                20
#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_OFFSET_SHIFT_Type                U04

#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_INDEX_STRIDE                   25:24
#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_INDEX_STRIDE_End                  25
#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_INDEX_STRIDE_Start                24
#define MWV207REG_SHADER_CONFIG_LS_RELATIVE_INDEX_STRIDE_Type                U02

#define   MWV207REG_SHADER_CONFIG_LS_RELATIVE_INDEX_STRIDE_COMPATIBLE        0x0

#define   MWV207REG_SHADER_CONFIG_LS_RELATIVE_INDEX_STRIDE_ADAPTIVE          0x1

#define   MWV207REG_SHADER_CONFIG_LS_RELATIVE_INDEX_STRIDE_BYTE              0x2


#define MWV207REG_SHADER_CONFIG_VS_PRECISION                               28:28
#define MWV207REG_SHADER_CONFIG_VS_PRECISION_End                              28
#define MWV207REG_SHADER_CONFIG_VS_PRECISION_Start                            28
#define MWV207REG_SHADER_CONFIG_VS_PRECISION_Type                            U01

#define   MWV207REG_SHADER_CONFIG_VS_PRECISION_HIGH                          0x0

#define   MWV207REG_SHADER_CONFIG_VS_PRECISION_MEDIUM                        0x1


#define MWV207REG_SHADER_CONFIG_PS_PRECISION                               29:29
#define MWV207REG_SHADER_CONFIG_PS_PRECISION_End                              29
#define MWV207REG_SHADER_CONFIG_PS_PRECISION_Start                            29
#define MWV207REG_SHADER_CONFIG_PS_PRECISION_Type                            U01

#define   MWV207REG_SHADER_CONFIG_PS_PRECISION_HIGH                          0x0

#define   MWV207REG_SHADER_CONFIG_PS_PRECISION_MEDIUM                        0x1


#define MWV207REG_SHADER_CONFIG_CONVERT_NAN                                30:30
#define MWV207REG_SHADER_CONFIG_CONVERT_NAN_End                               30
#define MWV207REG_SHADER_CONFIG_CONVERT_NAN_Start                             30
#define MWV207REG_SHADER_CONFIG_CONVERT_NAN_Type                             U01

#define   MWV207REG_SHADER_CONFIG_CONVERT_NAN_ZERO                           0x0
#define   MWV207REG_SHADER_CONFIG_CONVERT_NAN_INFINITY                       0x1


#define MWV207REG_SHADER_CONFIG_ATOMIC_ROBUSTNESS                          31:31
#define MWV207REG_SHADER_CONFIG_ATOMIC_ROBUSTNESS_End                         31
#define MWV207REG_SHADER_CONFIG_ATOMIC_ROBUSTNESS_Start                       31
#define MWV207REG_SHADER_CONFIG_ATOMIC_ROBUSTNESS_Type                       U01

#define   MWV207REG_SHADER_CONFIG_ATOMIC_ROBUSTNESS_DISABLED                 0x0

#define   MWV207REG_SHADER_CONFIG_ATOMIC_ROBUSTNESS_ENABLED                  0x1

#define mwv207regVertexShaderConstRegAddrs                                0x0219
#define MWV207REG_VERTEX_SHADER_CONST_Address                            0x00864
#define MWV207REG_VERTEX_SHADER_CONST_MSB                                     15
#define MWV207REG_VERTEX_SHADER_CONST_LSB                                      0
#define MWV207REG_VERTEX_SHADER_CONST_BLK                                      0
#define MWV207REG_VERTEX_SHADER_CONST_Count                                    1
#define MWV207REG_VERTEX_SHADER_CONST_FieldMask                       0x000003FF
#define MWV207REG_VERTEX_SHADER_CONST_ReadMask                        0x000003FF
#define MWV207REG_VERTEX_SHADER_CONST_WriteMask                       0x000003FF
#define MWV207REG_VERTEX_SHADER_CONST_ResetValue                      0x00000000

#define MWV207REG_VERTEX_SHADER_CONST_BASE_OFFSET                            9:0
#define MWV207REG_VERTEX_SHADER_CONST_BASE_OFFSET_End                          9
#define MWV207REG_VERTEX_SHADER_CONST_BASE_OFFSET_Start                        0
#define MWV207REG_VERTEX_SHADER_CONST_BASE_OFFSET_Type                       U10




#define mwv207regSHCacheControlRegAddrs                                   0x021A
#define MWV207REG_SH_CACHE_CONTROL_Address                               0x00868
#define MWV207REG_SH_CACHE_CONTROL_MSB                                        15
#define MWV207REG_SH_CACHE_CONTROL_LSB                                         0
#define MWV207REG_SH_CACHE_CONTROL_BLK                                         0
#define MWV207REG_SH_CACHE_CONTROL_Count                                       1
#define MWV207REG_SH_CACHE_CONTROL_FieldMask                          0x000003F1
#define MWV207REG_SH_CACHE_CONTROL_ReadMask                           0x000003F1
#define MWV207REG_SH_CACHE_CONTROL_WriteMask                          0x000003F1
#define MWV207REG_SH_CACHE_CONTROL_ResetValue                         0x00000000

#define MWV207REG_SH_CACHE_CONTROL_MODE                                      0:0
#define MWV207REG_SH_CACHE_CONTROL_MODE_End                                    0
#define MWV207REG_SH_CACHE_CONTROL_MODE_Start                                  0
#define MWV207REG_SH_CACHE_CONTROL_MODE_Type                                 U01

#define   MWV207REG_SH_CACHE_CONTROL_MODE_STATES                             0x0

#define   MWV207REG_SH_CACHE_CONTROL_MODE_MEMORY                             0x1


#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_VS                             4:4
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_VS_End                           4
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_VS_Start                         4
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_VS_Type                        U01


#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_PS                             5:5
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_PS_End                           5
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_PS_Start                         5
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_PS_Type                        U01


#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_CE                             6:6
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_CE_End                           6
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_CE_Start                         6
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_CE_Type                        U01


#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TCS                            7:7
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TCS_End                          7
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TCS_Start                        7
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TCS_Type                       U01


#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TES                            8:8
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TES_End                          8
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TES_Start                        8
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_TES_Type                       U01


#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_GS                             9:9
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_GS_End                           9
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_GS_Start                         9
#define MWV207REG_SH_CACHE_CONTROL_INVALIDATE_GS_Type                        U01



#define mwv207regVSInstructionRegAddrs                                    0x021B
#define MWV207REG_VS_INSTRUCTION_Address                                 0x0086C
#define MWV207REG_VS_INSTRUCTION_MSB                                          15
#define MWV207REG_VS_INSTRUCTION_LSB                                           0
#define MWV207REG_VS_INSTRUCTION_BLK                                           0
#define MWV207REG_VS_INSTRUCTION_Count                                         1
#define MWV207REG_VS_INSTRUCTION_FieldMask                            0xFFFFFFFF
#define MWV207REG_VS_INSTRUCTION_ReadMask                             0xFFFFFF00
#define MWV207REG_VS_INSTRUCTION_WriteMask                            0xFFFFFF00
#define MWV207REG_VS_INSTRUCTION_ResetValue                           0x00000000


#define MWV207REG_VS_INSTRUCTION_ADDRESS                                    31:0
#define MWV207REG_VS_INSTRUCTION_ADDRESS_End                                  31
#define MWV207REG_VS_INSTRUCTION_ADDRESS_Start                                 0
#define MWV207REG_VS_INSTRUCTION_ADDRESS_Type                                U32



#define mwv207regVSAttributeRegAddrs                                      0x021C
#define MWV207REG_VS_ATTRIBUTE_Address                                   0x00870
#define MWV207REG_VS_ATTRIBUTE_MSB                                            15
#define MWV207REG_VS_ATTRIBUTE_LSB                                             0
#define MWV207REG_VS_ATTRIBUTE_BLK                                             0
#define MWV207REG_VS_ATTRIBUTE_Count                                           1
#define MWV207REG_VS_ATTRIBUTE_FieldMask                              0x0007FF3F
#define MWV207REG_VS_ATTRIBUTE_ReadMask                               0x0007FF3F
#define MWV207REG_VS_ATTRIBUTE_WriteMask                              0x0007FF3F
#define MWV207REG_VS_ATTRIBUTE_ResetValue                             0x00000000

#define MWV207REG_VS_ATTRIBUTE_VERTEX_SIZE                                   5:0
#define MWV207REG_VS_ATTRIBUTE_VERTEX_SIZE_End                                 5
#define MWV207REG_VS_ATTRIBUTE_VERTEX_SIZE_Start                               0
#define MWV207REG_VS_ATTRIBUTE_VERTEX_SIZE_Type                              U06

#define MWV207REG_VS_ATTRIBUTE_GROUP_SIZE                                   18:8
#define MWV207REG_VS_ATTRIBUTE_GROUP_SIZE_End                                 18
#define MWV207REG_VS_ATTRIBUTE_GROUP_SIZE_Start                                8
#define MWV207REG_VS_ATTRIBUTE_GROUP_SIZE_Type                               U11




#define mwv207regVSStartPCRegAddrs                                        0x021D
#define MWV207REG_VS_START_PC_Address                                    0x00874
#define MWV207REG_VS_START_PC_MSB                                             15
#define MWV207REG_VS_START_PC_LSB                                              0
#define MWV207REG_VS_START_PC_BLK                                              0
#define MWV207REG_VS_START_PC_Count                                            1
#define MWV207REG_VS_START_PC_FieldMask                               0x000FFFFF
#define MWV207REG_VS_START_PC_ReadMask                                0x000FFFFF
#define MWV207REG_VS_START_PC_WriteMask                               0x000FFFFF
#define MWV207REG_VS_START_PC_ResetValue                              0x00000000


#define MWV207REG_VS_START_PC_START                                         19:0
#define MWV207REG_VS_START_PC_START_End                                       19
#define MWV207REG_VS_START_PC_START_Start                                      0
#define MWV207REG_VS_START_PC_START_Type                                     U20




#define mwv207regVSEndPCRegAddrs                                          0x021E
#define MWV207REG_VS_END_PC_Address                                      0x00878
#define MWV207REG_VS_END_PC_MSB                                               15
#define MWV207REG_VS_END_PC_LSB                                                0
#define MWV207REG_VS_END_PC_BLK                                                0
#define MWV207REG_VS_END_PC_Count                                              1
#define MWV207REG_VS_END_PC_FieldMask                                 0x000FFFFF
#define MWV207REG_VS_END_PC_ReadMask                                  0x000FFFFF
#define MWV207REG_VS_END_PC_WriteMask                                 0x000FFFFF
#define MWV207REG_VS_END_PC_ResetValue                                0x00000000


#define MWV207REG_VS_END_PC_END                                             19:0
#define MWV207REG_VS_END_PC_END_End                                           19
#define MWV207REG_VS_END_PC_END_Start                                          0
#define MWV207REG_VS_END_PC_END_Type                                         U20




#define mwv207regPSStartPCRegAddrs                                        0x021F
#define MWV207REG_PS_START_PC_Address                                    0x0087C
#define MWV207REG_PS_START_PC_MSB                                             15
#define MWV207REG_PS_START_PC_LSB                                              0
#define MWV207REG_PS_START_PC_BLK                                              0
#define MWV207REG_PS_START_PC_Count                                            1
#define MWV207REG_PS_START_PC_FieldMask                               0x000FFFFF
#define MWV207REG_PS_START_PC_ReadMask                                0x000FFFFF
#define MWV207REG_PS_START_PC_WriteMask                               0x000FFFFF
#define MWV207REG_PS_START_PC_ResetValue                              0x00000000


#define MWV207REG_PS_START_PC_START                                         19:0
#define MWV207REG_PS_START_PC_START_End                                       19
#define MWV207REG_PS_START_PC_START_Start                                      0
#define MWV207REG_PS_START_PC_START_Type                                     U20




#define mwv207regPSEndPCRegAddrs                                          0x0220
#define MWV207REG_PS_END_PC_Address                                      0x00880
#define MWV207REG_PS_END_PC_MSB                                               15
#define MWV207REG_PS_END_PC_LSB                                                0
#define MWV207REG_PS_END_PC_BLK                                                0
#define MWV207REG_PS_END_PC_Count                                              1
#define MWV207REG_PS_END_PC_FieldMask                                 0x000FFFFF
#define MWV207REG_PS_END_PC_ReadMask                                  0x000FFFFF
#define MWV207REG_PS_END_PC_WriteMask                                 0x000FFFFF
#define MWV207REG_PS_END_PC_ResetValue                                0x00000000


#define MWV207REG_PS_END_PC_END                                             19:0
#define MWV207REG_PS_END_PC_END_End                                           19
#define MWV207REG_PS_END_PC_END_Start                                          0
#define MWV207REG_PS_END_PC_END_Type                                         U20



#define mwv207regSHSamplerArbitrationRegAddrs                             0x0221
#define MWV207REG_SH_SAMPLER_ARBITRATION_Address                         0x00884
#define MWV207REG_SH_SAMPLER_ARBITRATION_MSB                                  15
#define MWV207REG_SH_SAMPLER_ARBITRATION_LSB                                   0
#define MWV207REG_SH_SAMPLER_ARBITRATION_BLK                                   0
#define MWV207REG_SH_SAMPLER_ARBITRATION_Count                                 1
#define MWV207REG_SH_SAMPLER_ARBITRATION_FieldMask                    0x00003F3F
#define MWV207REG_SH_SAMPLER_ARBITRATION_ReadMask                     0x00003F3F
#define MWV207REG_SH_SAMPLER_ARBITRATION_WriteMask                    0x00003F3F
#define MWV207REG_SH_SAMPLER_ARBITRATION_ResetValue                   0x00000000

#define MWV207REG_SH_SAMPLER_ARBITRATION_PS_GROUP_LIMIT                      5:0
#define MWV207REG_SH_SAMPLER_ARBITRATION_PS_GROUP_LIMIT_End                    5
#define MWV207REG_SH_SAMPLER_ARBITRATION_PS_GROUP_LIMIT_Start                  0
#define MWV207REG_SH_SAMPLER_ARBITRATION_PS_GROUP_LIMIT_Type                 U06

#define   MWV207REG_SH_SAMPLER_ARBITRATION_PS_GROUP_LIMIT_IN_ORDER          0x00

#define   MWV207REG_SH_SAMPLER_ARBITRATION_PS_GROUP_LIMIT_UNLIMITED         0x3F

#define MWV207REG_SH_SAMPLER_ARBITRATION_VS_GROUP_LIMIT                     13:8
#define MWV207REG_SH_SAMPLER_ARBITRATION_VS_GROUP_LIMIT_End                   13
#define MWV207REG_SH_SAMPLER_ARBITRATION_VS_GROUP_LIMIT_Start                  8
#define MWV207REG_SH_SAMPLER_ARBITRATION_VS_GROUP_LIMIT_Type                 U06

#define   MWV207REG_SH_SAMPLER_ARBITRATION_VS_GROUP_LIMIT_IN_ORDER          0x00

#define   MWV207REG_SH_SAMPLER_ARBITRATION_VS_GROUP_LIMIT_UNLIMITED         0x3F



#define mwv207regSHPowerManagementRegAddrs                                0x0222
#define MWV207REG_SH_POWER_MANAGEMENT_Address                            0x00888
#define MWV207REG_SH_POWER_MANAGEMENT_MSB                                     15
#define MWV207REG_SH_POWER_MANAGEMENT_LSB                                      0
#define MWV207REG_SH_POWER_MANAGEMENT_BLK                                      0
#define MWV207REG_SH_POWER_MANAGEMENT_Count                                    1
#define MWV207REG_SH_POWER_MANAGEMENT_FieldMask                       0x00000077
#define MWV207REG_SH_POWER_MANAGEMENT_ReadMask                        0x00000077
#define MWV207REG_SH_POWER_MANAGEMENT_WriteMask                       0x00000077
#define MWV207REG_SH_POWER_MANAGEMENT_ResetValue                      0x00000077

#define MWV207REG_SH_POWER_MANAGEMENT_PS_ACTIVE_CORES                        2:0
#define MWV207REG_SH_POWER_MANAGEMENT_PS_ACTIVE_CORES_End                      2
#define MWV207REG_SH_POWER_MANAGEMENT_PS_ACTIVE_CORES_Start                    0
#define MWV207REG_SH_POWER_MANAGEMENT_PS_ACTIVE_CORES_Type                   U03
#define   MWV207REG_SH_POWER_MANAGEMENT_PS_ACTIVE_CORES_ALL                  0x7

#define MWV207REG_SH_POWER_MANAGEMENT_VS_ACTIVE_CORES                        6:4
#define MWV207REG_SH_POWER_MANAGEMENT_VS_ACTIVE_CORES_End                      6
#define MWV207REG_SH_POWER_MANAGEMENT_VS_ACTIVE_CORES_Start                    4
#define MWV207REG_SH_POWER_MANAGEMENT_VS_ACTIVE_CORES_Type                   U03
#define   MWV207REG_SH_POWER_MANAGEMENT_VS_ACTIVE_CORES_ALL                  0x7




#define mwv207regVSInstructionPrefetchRegAddrs                            0x0223
#define MWV207REG_VS_INSTRUCTION_PREFETCH_Address                        0x0088C
#define MWV207REG_VS_INSTRUCTION_PREFETCH_MSB                                 15
#define MWV207REG_VS_INSTRUCTION_PREFETCH_LSB                                  0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_BLK                                  0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_Count                                1
#define MWV207REG_VS_INSTRUCTION_PREFETCH_FieldMask                   0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_ReadMask                    0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_WriteMask                   0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_ResetValue                  0x00000000


#define MWV207REG_VS_INSTRUCTION_PREFETCH_PC                                19:0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_PC_End                              19
#define MWV207REG_VS_INSTRUCTION_PREFETCH_PC_Start                             0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_PC_Type                            U20



#define mwv207regVSInstructionPrefetchEndRegAddrs                         0x0224
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_Address                    0x00890
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_MSB                             15
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_LSB                              0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_BLK                              0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_Count                            1
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_FieldMask               0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_ReadMask                0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_WriteMask               0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_ResetValue              0x00000000

#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_PC                            19:0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_PC_End                          19
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_PC_Start                         0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_END_PC_Type                        U20




#define mwv207regShaderConfig2RegAddrs                                    0x0225
#define MWV207REG_SHADER_CONFIG2_Address                                 0x00894
#define MWV207REG_SHADER_CONFIG2_MSB                                          15
#define MWV207REG_SHADER_CONFIG2_LSB                                           0
#define MWV207REG_SHADER_CONFIG2_BLK                                           0
#define MWV207REG_SHADER_CONFIG2_Count                                         1
#define MWV207REG_SHADER_CONFIG2_FieldMask                            0x00000001
#define MWV207REG_SHADER_CONFIG2_ReadMask                             0x00000001
#define MWV207REG_SHADER_CONFIG2_WriteMask                            0x00000001
#define MWV207REG_SHADER_CONFIG2_ResetValue                           0x00000000

#define MWV207REG_SHADER_CONFIG2_VARYING_PACKING_POWER_OPTIMIZATION          0:0
#define MWV207REG_SHADER_CONFIG2_VARYING_PACKING_POWER_OPTIMIZATION_End        0
#define MWV207REG_SHADER_CONFIG2_VARYING_PACKING_POWER_OPTIMIZATION_Start      0
#define MWV207REG_SHADER_CONFIG2_VARYING_PACKING_POWER_OPTIMIZATION_Type     U01
#define   MWV207REG_SHADER_CONFIG2_VARYING_PACKING_POWER_OPTIMIZATION_ENABLE 0x0
#define   MWV207REG_SHADER_CONFIG2_VARYING_PACKING_POWER_OPTIMIZATION_DISABLE 0x1



#define mwv207regVSUnpackRegAddrs                                         0x0226
#define MWV207REG_VS_UNPACK_Address                                      0x00898
#define MWV207REG_VS_UNPACK_MSB                                               15
#define MWV207REG_VS_UNPACK_LSB                                                1
#define MWV207REG_VS_UNPACK_BLK                                                1
#define MWV207REG_VS_UNPACK_Count                                              2
#define MWV207REG_VS_UNPACK_FieldMask                                 0xFFFFFFFF
#define MWV207REG_VS_UNPACK_ReadMask                                  0xFFFFFFFF
#define MWV207REG_VS_UNPACK_WriteMask                                 0xFFFFFFFF
#define MWV207REG_VS_UNPACK_ResetValue                                0x00000000


#define MWV207REG_VS_UNPACK_ATTRIBUTE0                                       1:0
#define MWV207REG_VS_UNPACK_ATTRIBUTE0_End                                     1
#define MWV207REG_VS_UNPACK_ATTRIBUTE0_Start                                   0
#define MWV207REG_VS_UNPACK_ATTRIBUTE0_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE1                                       3:2
#define MWV207REG_VS_UNPACK_ATTRIBUTE1_End                                     3
#define MWV207REG_VS_UNPACK_ATTRIBUTE1_Start                                   2
#define MWV207REG_VS_UNPACK_ATTRIBUTE1_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE2                                       5:4
#define MWV207REG_VS_UNPACK_ATTRIBUTE2_End                                     5
#define MWV207REG_VS_UNPACK_ATTRIBUTE2_Start                                   4
#define MWV207REG_VS_UNPACK_ATTRIBUTE2_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE3                                       7:6
#define MWV207REG_VS_UNPACK_ATTRIBUTE3_End                                     7
#define MWV207REG_VS_UNPACK_ATTRIBUTE3_Start                                   6
#define MWV207REG_VS_UNPACK_ATTRIBUTE3_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE4                                       9:8
#define MWV207REG_VS_UNPACK_ATTRIBUTE4_End                                     9
#define MWV207REG_VS_UNPACK_ATTRIBUTE4_Start                                   8
#define MWV207REG_VS_UNPACK_ATTRIBUTE4_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE5                                     11:10
#define MWV207REG_VS_UNPACK_ATTRIBUTE5_End                                    11
#define MWV207REG_VS_UNPACK_ATTRIBUTE5_Start                                  10
#define MWV207REG_VS_UNPACK_ATTRIBUTE5_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE6                                     13:12
#define MWV207REG_VS_UNPACK_ATTRIBUTE6_End                                    13
#define MWV207REG_VS_UNPACK_ATTRIBUTE6_Start                                  12
#define MWV207REG_VS_UNPACK_ATTRIBUTE6_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE7                                     15:14
#define MWV207REG_VS_UNPACK_ATTRIBUTE7_End                                    15
#define MWV207REG_VS_UNPACK_ATTRIBUTE7_Start                                  14
#define MWV207REG_VS_UNPACK_ATTRIBUTE7_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE8                                     17:16
#define MWV207REG_VS_UNPACK_ATTRIBUTE8_End                                    17
#define MWV207REG_VS_UNPACK_ATTRIBUTE8_Start                                  16
#define MWV207REG_VS_UNPACK_ATTRIBUTE8_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE9                                     19:18
#define MWV207REG_VS_UNPACK_ATTRIBUTE9_End                                    19
#define MWV207REG_VS_UNPACK_ATTRIBUTE9_Start                                  18
#define MWV207REG_VS_UNPACK_ATTRIBUTE9_Type                                  U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE10                                    21:20
#define MWV207REG_VS_UNPACK_ATTRIBUTE10_End                                   21
#define MWV207REG_VS_UNPACK_ATTRIBUTE10_Start                                 20
#define MWV207REG_VS_UNPACK_ATTRIBUTE10_Type                                 U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE11                                    23:22
#define MWV207REG_VS_UNPACK_ATTRIBUTE11_End                                   23
#define MWV207REG_VS_UNPACK_ATTRIBUTE11_Start                                 22
#define MWV207REG_VS_UNPACK_ATTRIBUTE11_Type                                 U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE12                                    25:24
#define MWV207REG_VS_UNPACK_ATTRIBUTE12_End                                   25
#define MWV207REG_VS_UNPACK_ATTRIBUTE12_Start                                 24
#define MWV207REG_VS_UNPACK_ATTRIBUTE12_Type                                 U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE13                                    27:26
#define MWV207REG_VS_UNPACK_ATTRIBUTE13_End                                   27
#define MWV207REG_VS_UNPACK_ATTRIBUTE13_Start                                 26
#define MWV207REG_VS_UNPACK_ATTRIBUTE13_Type                                 U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE14                                    29:28
#define MWV207REG_VS_UNPACK_ATTRIBUTE14_End                                   29
#define MWV207REG_VS_UNPACK_ATTRIBUTE14_Start                                 28
#define MWV207REG_VS_UNPACK_ATTRIBUTE14_Type                                 U02


#define MWV207REG_VS_UNPACK_ATTRIBUTE15                                    31:30
#define MWV207REG_VS_UNPACK_ATTRIBUTE15_End                                   31
#define MWV207REG_VS_UNPACK_ATTRIBUTE15_Start                                 30
#define MWV207REG_VS_UNPACK_ATTRIBUTE15_Type                                 U02




#define mwv207regVSThrottleRegAddrs                                       0x0228
#define MWV207REG_VS_THROTTLE_Address                                    0x008A0
#define MWV207REG_VS_THROTTLE_MSB                                             15
#define MWV207REG_VS_THROTTLE_LSB                                              0
#define MWV207REG_VS_THROTTLE_BLK                                              0
#define MWV207REG_VS_THROTTLE_Count                                            1
#define MWV207REG_VS_THROTTLE_FieldMask                               0x1FFFF03F
#define MWV207REG_VS_THROTTLE_ReadMask                                0x1FFFF03F
#define MWV207REG_VS_THROTTLE_WriteMask                               0x1FFFF03F
#define MWV207REG_VS_THROTTLE_ResetValue                              0x00000000

#define MWV207REG_VS_THROTTLE_MAX_PAGES                                      5:0
#define MWV207REG_VS_THROTTLE_MAX_PAGES_End                                    5
#define MWV207REG_VS_THROTTLE_MAX_PAGES_Start                                  0
#define MWV207REG_VS_THROTTLE_MAX_PAGES_Type                                 U06


#define MWV207REG_VS_THROTTLE_MAX_THREADS                                  19:12
#define MWV207REG_VS_THROTTLE_MAX_THREADS_End                                 19
#define MWV207REG_VS_THROTTLE_MAX_THREADS_Start                               12
#define MWV207REG_VS_THROTTLE_MAX_THREADS_Type                               U08

#define MWV207REG_VS_THROTTLE_RESULT_WINDOW_SIZE                           28:20
#define MWV207REG_VS_THROTTLE_RESULT_WINDOW_SIZE_End                          28
#define MWV207REG_VS_THROTTLE_RESULT_WINDOW_SIZE_Start                        20
#define MWV207REG_VS_THROTTLE_RESULT_WINDOW_SIZE_Type                        U09




#define mwv207regVSInputRegAddrs                                          0x0230
#define MWV207REG_VS_INPUT_Address                                       0x008C0
#define MWV207REG_VS_INPUT_MSB                                                15
#define MWV207REG_VS_INPUT_LSB                                                 3
#define MWV207REG_VS_INPUT_BLK                                                 3
#define MWV207REG_VS_INPUT_Count                                               8
#define MWV207REG_VS_INPUT_FieldMask                                  0x3F3F3F3F
#define MWV207REG_VS_INPUT_ReadMask                                   0x3F3F3F3F
#define MWV207REG_VS_INPUT_WriteMask                                  0x3F3F3F3F
#define MWV207REG_VS_INPUT_ResetValue                                 0x00000000


#define MWV207REG_VS_INPUT_ATTRIBUTE0                                        5:0
#define MWV207REG_VS_INPUT_ATTRIBUTE0_End                                      5
#define MWV207REG_VS_INPUT_ATTRIBUTE0_Start                                    0
#define MWV207REG_VS_INPUT_ATTRIBUTE0_Type                                   U06


#define MWV207REG_VS_INPUT_ATTRIBUTE1                                       13:8
#define MWV207REG_VS_INPUT_ATTRIBUTE1_End                                     13
#define MWV207REG_VS_INPUT_ATTRIBUTE1_Start                                    8
#define MWV207REG_VS_INPUT_ATTRIBUTE1_Type                                   U06


#define MWV207REG_VS_INPUT_ATTRIBUTE2                                      21:16
#define MWV207REG_VS_INPUT_ATTRIBUTE2_End                                     21
#define MWV207REG_VS_INPUT_ATTRIBUTE2_Start                                   16
#define MWV207REG_VS_INPUT_ATTRIBUTE2_Type                                   U06


#define MWV207REG_VS_INPUT_ATTRIBUTE3                                      29:24
#define MWV207REG_VS_INPUT_ATTRIBUTE3_End                                     29
#define MWV207REG_VS_INPUT_ATTRIBUTE3_Start                                   24
#define MWV207REG_VS_INPUT_ATTRIBUTE3_Type                                   U06




#define mwv207regVSOutputRegAddrs                                         0x0238
#define MWV207REG_VS_OUTPUT_Address                                      0x008E0
#define MWV207REG_VS_OUTPUT_MSB                                               15
#define MWV207REG_VS_OUTPUT_LSB                                                3
#define MWV207REG_VS_OUTPUT_BLK                                                3
#define MWV207REG_VS_OUTPUT_Count                                              8
#define MWV207REG_VS_OUTPUT_FieldMask                                 0x3F3F3F3F
#define MWV207REG_VS_OUTPUT_ReadMask                                  0x3F3F3F3F
#define MWV207REG_VS_OUTPUT_WriteMask                                 0x3F3F3F3F
#define MWV207REG_VS_OUTPUT_ResetValue                                0x00000000


#define MWV207REG_VS_OUTPUT_OUTPUT0                                          5:0
#define MWV207REG_VS_OUTPUT_OUTPUT0_End                                        5
#define MWV207REG_VS_OUTPUT_OUTPUT0_Start                                      0
#define MWV207REG_VS_OUTPUT_OUTPUT0_Type                                     U06


#define MWV207REG_VS_OUTPUT_OUTPUT1                                         13:8
#define MWV207REG_VS_OUTPUT_OUTPUT1_End                                       13
#define MWV207REG_VS_OUTPUT_OUTPUT1_Start                                      8
#define MWV207REG_VS_OUTPUT_OUTPUT1_Type                                     U06


#define MWV207REG_VS_OUTPUT_OUTPUT2                                        21:16
#define MWV207REG_VS_OUTPUT_OUTPUT2_End                                       21
#define MWV207REG_VS_OUTPUT_OUTPUT2_Start                                     16
#define MWV207REG_VS_OUTPUT_OUTPUT2_Type                                     U06


#define MWV207REG_VS_OUTPUT_OUTPUT3                                        29:24
#define MWV207REG_VS_OUTPUT_OUTPUT3_End                                       29
#define MWV207REG_VS_OUTPUT_OUTPUT3_Start                                     24
#define MWV207REG_VS_OUTPUT_OUTPUT3_Type                                     U06



#define mwv207regVSUniformLockRegAddrs                                    0x0229
#define MWV207REG_VS_UNIFORM_LOCK_Address                                0x008A4
#define MWV207REG_VS_UNIFORM_LOCK_MSB                                         15
#define MWV207REG_VS_UNIFORM_LOCK_LSB                                          0
#define MWV207REG_VS_UNIFORM_LOCK_BLK                                          0
#define MWV207REG_VS_UNIFORM_LOCK_Count                                        1
#define MWV207REG_VS_UNIFORM_LOCK_FieldMask                           0x000003FF
#define MWV207REG_VS_UNIFORM_LOCK_ReadMask                            0x000003FF
#define MWV207REG_VS_UNIFORM_LOCK_WriteMask                           0x000003FF
#define MWV207REG_VS_UNIFORM_LOCK_ResetValue                          0x00000000


#define MWV207REG_VS_UNIFORM_LOCK_OFFSET                                     9:0
#define MWV207REG_VS_UNIFORM_LOCK_OFFSET_End                                   9
#define MWV207REG_VS_UNIFORM_LOCK_OFFSET_Start                                 0
#define MWV207REG_VS_UNIFORM_LOCK_OFFSET_Type                                U10




#define mwv207regVSSamplerBaseRegAddrs                                    0x022A
#define MWV207REG_VS_SAMPLER_BASE_Address                                0x008A8
#define MWV207REG_VS_SAMPLER_BASE_MSB                                         15
#define MWV207REG_VS_SAMPLER_BASE_LSB                                          0
#define MWV207REG_VS_SAMPLER_BASE_BLK                                          0
#define MWV207REG_VS_SAMPLER_BASE_Count                                        1
#define MWV207REG_VS_SAMPLER_BASE_FieldMask                           0x03FF007F
#define MWV207REG_VS_SAMPLER_BASE_ReadMask                            0x03FF007F
#define MWV207REG_VS_SAMPLER_BASE_WriteMask                           0x03FF007F
#define MWV207REG_VS_SAMPLER_BASE_ResetValue                          0x00000000


#define MWV207REG_VS_SAMPLER_BASE_OFFSET                                     6:0
#define MWV207REG_VS_SAMPLER_BASE_OFFSET_End                                   6
#define MWV207REG_VS_SAMPLER_BASE_OFFSET_Start                                 0
#define MWV207REG_VS_SAMPLER_BASE_OFFSET_Type                                U07


#define MWV207REG_VS_SAMPLER_BASE_TXD_OFFSET                               25:16
#define MWV207REG_VS_SAMPLER_BASE_TXD_OFFSET_End                              25
#define MWV207REG_VS_SAMPLER_BASE_TXD_OFFSET_Start                            16
#define MWV207REG_VS_SAMPLER_BASE_TXD_OFFSET_Type                            U10



#define mwv207regVSSamplerLockRegAddrs                                    0x022B
#define MWV207REG_VS_SAMPLER_LOCK_Address                                0x008AC
#define MWV207REG_VS_SAMPLER_LOCK_MSB                                         15
#define MWV207REG_VS_SAMPLER_LOCK_LSB                                          0
#define MWV207REG_VS_SAMPLER_LOCK_BLK                                          0
#define MWV207REG_VS_SAMPLER_LOCK_Count                                        1
#define MWV207REG_VS_SAMPLER_LOCK_FieldMask                           0x03FF007F
#define MWV207REG_VS_SAMPLER_LOCK_ReadMask                            0x03FF007F
#define MWV207REG_VS_SAMPLER_LOCK_WriteMask                           0x03FF007F
#define MWV207REG_VS_SAMPLER_LOCK_ResetValue                          0x00000000


#define MWV207REG_VS_SAMPLER_LOCK_OFFSET                                     6:0
#define MWV207REG_VS_SAMPLER_LOCK_OFFSET_End                                   6
#define MWV207REG_VS_SAMPLER_LOCK_OFFSET_Start                                 0
#define MWV207REG_VS_SAMPLER_LOCK_OFFSET_Type                                U07


#define MWV207REG_VS_SAMPLER_LOCK_TXD_OFFSET                               25:16
#define MWV207REG_VS_SAMPLER_LOCK_TXD_OFFSET_End                              25
#define MWV207REG_VS_SAMPLER_LOCK_TXD_OFFSET_Start                            16
#define MWV207REG_VS_SAMPLER_LOCK_TXD_OFFSET_Type                            U10




#define mwv207regSHIcacheInvalidateRegAddrs                               0x022C
#define MWV207REG_SH_ICACHE_INVALIDATE_Address                           0x008B0
#define MWV207REG_SH_ICACHE_INVALIDATE_MSB                                    15
#define MWV207REG_SH_ICACHE_INVALIDATE_LSB                                     0
#define MWV207REG_SH_ICACHE_INVALIDATE_BLK                                     0
#define MWV207REG_SH_ICACHE_INVALIDATE_Count                                   1
#define MWV207REG_SH_ICACHE_INVALIDATE_FieldMask                      0x0000001F
#define MWV207REG_SH_ICACHE_INVALIDATE_ReadMask                       0x0000001F
#define MWV207REG_SH_ICACHE_INVALIDATE_WriteMask                      0x0000001F
#define MWV207REG_SH_ICACHE_INVALIDATE_ResetValue                     0x00000000


#define MWV207REG_SH_ICACHE_INVALIDATE_VS                                    0:0
#define MWV207REG_SH_ICACHE_INVALIDATE_VS_End                                  0
#define MWV207REG_SH_ICACHE_INVALIDATE_VS_Start                                0
#define MWV207REG_SH_ICACHE_INVALIDATE_VS_Type                               U01


#define MWV207REG_SH_ICACHE_INVALIDATE_TCS                                   1:1
#define MWV207REG_SH_ICACHE_INVALIDATE_TCS_End                                 1
#define MWV207REG_SH_ICACHE_INVALIDATE_TCS_Start                               1
#define MWV207REG_SH_ICACHE_INVALIDATE_TCS_Type                              U01


#define MWV207REG_SH_ICACHE_INVALIDATE_TES                                   2:2
#define MWV207REG_SH_ICACHE_INVALIDATE_TES_End                                 2
#define MWV207REG_SH_ICACHE_INVALIDATE_TES_Start                               2
#define MWV207REG_SH_ICACHE_INVALIDATE_TES_Type                              U01


#define MWV207REG_SH_ICACHE_INVALIDATE_GS                                    3:3
#define MWV207REG_SH_ICACHE_INVALIDATE_GS_End                                  3
#define MWV207REG_SH_ICACHE_INVALIDATE_GS_Start                                3
#define MWV207REG_SH_ICACHE_INVALIDATE_GS_Type                               U01


#define MWV207REG_SH_ICACHE_INVALIDATE_PS                                    4:4
#define MWV207REG_SH_ICACHE_INVALIDATE_PS_End                                  4
#define MWV207REG_SH_ICACHE_INVALIDATE_PS_Start                                4
#define MWV207REG_SH_ICACHE_INVALIDATE_PS_Type                               U01



#define mwv207regShaderSteeringRegAddrs                                   0x022D
#define MWV207REG_SHADER_STEERING_Address                                0x008B4
#define MWV207REG_SHADER_STEERING_MSB                                         15
#define MWV207REG_SHADER_STEERING_LSB                                          0
#define MWV207REG_SHADER_STEERING_BLK                                          0
#define MWV207REG_SHADER_STEERING_Count                                        1
#define MWV207REG_SHADER_STEERING_FieldMask                           0x00000001
#define MWV207REG_SHADER_STEERING_ReadMask                            0x00000001
#define MWV207REG_SHADER_STEERING_WriteMask                           0x00000001
#define MWV207REG_SHADER_STEERING_ResetValue                          0x00000000


#define MWV207REG_SHADER_STEERING_SAMPLER_DECODE_SELECT                      0:0
#define MWV207REG_SHADER_STEERING_SAMPLER_DECODE_SELECT_End                    0
#define MWV207REG_SHADER_STEERING_SAMPLER_DECODE_SELECT_Start                  0
#define MWV207REG_SHADER_STEERING_SAMPLER_DECODE_SELECT_Type                 U01
#define   MWV207REG_SHADER_STEERING_SAMPLER_DECODE_SELECT_PIXEL              0x0
#define   MWV207REG_SHADER_STEERING_SAMPLER_DECODE_SELECT_GPIPE              0x1



#define mwv207regShaderStaticRegAddrs                                     0x022E
#define MWV207REG_SHADER_STATIC_Address                                  0x008B8
#define MWV207REG_SHADER_STATIC_MSB                                           15
#define MWV207REG_SHADER_STATIC_LSB                                            0
#define MWV207REG_SHADER_STATIC_BLK                                            0
#define MWV207REG_SHADER_STATIC_Count                                          1
#define MWV207REG_SHADER_STATIC_FieldMask                             0x100007FF
#define MWV207REG_SHADER_STATIC_ReadMask                              0x100007FF
#define MWV207REG_SHADER_STATIC_WriteMask                             0x100007FF
#define MWV207REG_SHADER_STATIC_ResetValue                            0x00000000


#define MWV207REG_SHADER_STATIC_PRESWIZZLE_POWER_OPTIMIZATION                0:0
#define MWV207REG_SHADER_STATIC_PRESWIZZLE_POWER_OPTIMIZATION_End              0
#define MWV207REG_SHADER_STATIC_PRESWIZZLE_POWER_OPTIMIZATION_Start            0
#define MWV207REG_SHADER_STATIC_PRESWIZZLE_POWER_OPTIMIZATION_Type           U01
#define   MWV207REG_SHADER_STATIC_PRESWIZZLE_POWER_OPTIMIZATION_ENABLE       0x0
#define   MWV207REG_SHADER_STATIC_PRESWIZZLE_POWER_OPTIMIZATION_DISABLE      0x1


#define MWV207REG_SHADER_STATIC_A0_POWER_OPTIMIZATION                        1:1
#define MWV207REG_SHADER_STATIC_A0_POWER_OPTIMIZATION_End                      1
#define MWV207REG_SHADER_STATIC_A0_POWER_OPTIMIZATION_Start                    1
#define MWV207REG_SHADER_STATIC_A0_POWER_OPTIMIZATION_Type                   U01
#define   MWV207REG_SHADER_STATIC_A0_POWER_OPTIMIZATION_ENABLE               0x0
#define   MWV207REG_SHADER_STATIC_A0_POWER_OPTIMIZATION_DISABLE              0x1


#define MWV207REG_SHADER_STATIC_HALF_REGISTER_DEPENDENCY                     2:2
#define MWV207REG_SHADER_STATIC_HALF_REGISTER_DEPENDENCY_End                   2
#define MWV207REG_SHADER_STATIC_HALF_REGISTER_DEPENDENCY_Start                 2
#define MWV207REG_SHADER_STATIC_HALF_REGISTER_DEPENDENCY_Type                U01
#define   MWV207REG_SHADER_STATIC_HALF_REGISTER_DEPENDENCY_ENABLE            0x0
#define   MWV207REG_SHADER_STATIC_HALF_REGISTER_DEPENDENCY_DISABLE           0x1

#define MWV207REG_SHADER_STATIC_VARYING_PACKING_POWER_OPTIMIZATION           3:3
#define MWV207REG_SHADER_STATIC_VARYING_PACKING_POWER_OPTIMIZATION_End         3
#define MWV207REG_SHADER_STATIC_VARYING_PACKING_POWER_OPTIMIZATION_Start       3
#define MWV207REG_SHADER_STATIC_VARYING_PACKING_POWER_OPTIMIZATION_Type      U01
#define   MWV207REG_SHADER_STATIC_VARYING_PACKING_POWER_OPTIMIZATION_ENABLE  0x0
#define   MWV207REG_SHADER_STATIC_VARYING_PACKING_POWER_OPTIMIZATION_DISABLE 0x1


#define MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH                            4:4
#define MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH_End                          4
#define MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH_Start                        4
#define MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH_Type                       U01
#define   MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH_ENABLE                   0x0
#define   MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH_DISABLE                  0x1


#define MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH                            5:5
#define MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH_End                          5
#define MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH_Start                        5
#define MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH_Type                       U01
#define   MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH_ENABLE                   0x0
#define   MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH_DISABLE                  0x1


#define MWV207REG_SHADER_STATIC_SNAP_DISABLED_STAGES                         6:6
#define MWV207REG_SHADER_STATIC_SNAP_DISABLED_STAGES_End                       6
#define MWV207REG_SHADER_STATIC_SNAP_DISABLED_STAGES_Start                     6
#define MWV207REG_SHADER_STATIC_SNAP_DISABLED_STAGES_Type                    U01
#define   MWV207REG_SHADER_STATIC_SNAP_DISABLED_STAGES_ENABLE                0x0
#define   MWV207REG_SHADER_STATIC_SNAP_DISABLED_STAGES_DISABLE               0x1

#define MWV207REG_SHADER_STATIC_MULTI_WORK_GROUP_PACK_OPTIMIZATION           7:7
#define MWV207REG_SHADER_STATIC_MULTI_WORK_GROUP_PACK_OPTIMIZATION_End         7
#define MWV207REG_SHADER_STATIC_MULTI_WORK_GROUP_PACK_OPTIMIZATION_Start       7
#define MWV207REG_SHADER_STATIC_MULTI_WORK_GROUP_PACK_OPTIMIZATION_Type      U01
#define   MWV207REG_SHADER_STATIC_MULTI_WORK_GROUP_PACK_OPTIMIZATION_ENABLE  0x0
#define   MWV207REG_SHADER_STATIC_MULTI_WORK_GROUP_PACK_OPTIMIZATION_DISABLE 0x1


#define MWV207REG_SHADER_STATIC_DUAL_ISSUE                                   8:8
#define MWV207REG_SHADER_STATIC_DUAL_ISSUE_End                                 8
#define MWV207REG_SHADER_STATIC_DUAL_ISSUE_Start                               8
#define MWV207REG_SHADER_STATIC_DUAL_ISSUE_Type                              U01
#define   MWV207REG_SHADER_STATIC_DUAL_ISSUE_DISABLE                         0x0
#define   MWV207REG_SHADER_STATIC_DUAL_ISSUE_ENABLE                          0x1


#define MWV207REG_SHADER_STATIC_TWO_GROUP_FAST_REISSUE                       9:9
#define MWV207REG_SHADER_STATIC_TWO_GROUP_FAST_REISSUE_End                     9
#define MWV207REG_SHADER_STATIC_TWO_GROUP_FAST_REISSUE_Start                   9
#define MWV207REG_SHADER_STATIC_TWO_GROUP_FAST_REISSUE_Type                  U01
#define   MWV207REG_SHADER_STATIC_TWO_GROUP_FAST_REISSUE_DISABLE             0x0
#define   MWV207REG_SHADER_STATIC_TWO_GROUP_FAST_REISSUE_ENABLE              0x1


#define MWV207REG_SHADER_STATIC_BANK_SWAP                                  10:10
#define MWV207REG_SHADER_STATIC_BANK_SWAP_End                                 10
#define MWV207REG_SHADER_STATIC_BANK_SWAP_Start                               10
#define MWV207REG_SHADER_STATIC_BANK_SWAP_Type                               U01
#define   MWV207REG_SHADER_STATIC_BANK_SWAP_ENABLE                           0x0
#define   MWV207REG_SHADER_STATIC_BANK_SWAP_DISABLE                          0x1


#define MWV207REG_SHADER_STATIC_ENDIAN_CONTROL                             28:28
#define MWV207REG_SHADER_STATIC_ENDIAN_CONTROL_End                            28
#define MWV207REG_SHADER_STATIC_ENDIAN_CONTROL_Start                          28
#define MWV207REG_SHADER_STATIC_ENDIAN_CONTROL_Type                          U01
#define   MWV207REG_SHADER_STATIC_ENDIAN_CONTROL_LITTLE                      0x0
#define   MWV207REG_SHADER_STATIC_ENDIAN_CONTROL_BIG                         0x1




#define mwv207regVSRelativeEndRegAddrs                                    0x022F
#define MWV207REG_VS_RELATIVE_END_Address                                0x008BC
#define MWV207REG_VS_RELATIVE_END_MSB                                         15
#define MWV207REG_VS_RELATIVE_END_LSB                                          0
#define MWV207REG_VS_RELATIVE_END_BLK                                          0
#define MWV207REG_VS_RELATIVE_END_Count                                        1
#define MWV207REG_VS_RELATIVE_END_FieldMask                           0x001FFFFF
#define MWV207REG_VS_RELATIVE_END_ReadMask                            0x001FFFFF
#define MWV207REG_VS_RELATIVE_END_WriteMask                           0x001FFFFF
#define MWV207REG_VS_RELATIVE_END_ResetValue                          0x00000000

#define MWV207REG_VS_RELATIVE_END_PC                                        20:0
#define MWV207REG_VS_RELATIVE_END_PC_End                                      20
#define MWV207REG_VS_RELATIVE_END_PC_Start                                     0
#define MWV207REG_VS_RELATIVE_END_PC_Type                                    U21


#define mwv207regTWConfigRegAddrs                                         0x0240
#define MWV207REG_TW_CONFIG_Address                                      0x00900
#define MWV207REG_TW_CONFIG_MSB                                               15
#define MWV207REG_TW_CONFIG_LSB                                                0
#define MWV207REG_TW_CONFIG_BLK                                                0
#define MWV207REG_TW_CONFIG_Count                                              1
#define MWV207REG_TW_CONFIG_FieldMask                                 0xB7FFF773
#define MWV207REG_TW_CONFIG_ReadMask                                  0xB7FFF773
#define MWV207REG_TW_CONFIG_WriteMask                                 0xB7FFF773
#define MWV207REG_TW_CONFIG_ResetValue                                0x00000000


#define MWV207REG_TW_CONFIG_WORK_DIM                                         1:0
#define MWV207REG_TW_CONFIG_WORK_DIM_End                                       1
#define MWV207REG_TW_CONFIG_WORK_DIM_Start                                     0
#define MWV207REG_TW_CONFIG_WORK_DIM_Type                                    U02
#define   MWV207REG_TW_CONFIG_WORK_DIM_DEFAULT                               0x0
#define   MWV207REG_TW_CONFIG_WORK_DIM_ONE                                   0x1
#define   MWV207REG_TW_CONFIG_WORK_DIM_TWO                                   0x2
#define   MWV207REG_TW_CONFIG_WORK_DIM_THREE                                 0x3

#define MWV207REG_TW_CONFIG_TRAVERSE_ORDER                                   6:4
#define MWV207REG_TW_CONFIG_TRAVERSE_ORDER_End                                 6
#define MWV207REG_TW_CONFIG_TRAVERSE_ORDER_Start                               4
#define MWV207REG_TW_CONFIG_TRAVERSE_ORDER_Type                              U03
#define   MWV207REG_TW_CONFIG_TRAVERSE_ORDER_XYZ                             0x0
#define   MWV207REG_TW_CONFIG_TRAVERSE_ORDER_XZY                             0x1
#define   MWV207REG_TW_CONFIG_TRAVERSE_ORDER_YXZ                             0x2
#define   MWV207REG_TW_CONFIG_TRAVERSE_ORDER_ZXY                             0x3
#define   MWV207REG_TW_CONFIG_TRAVERSE_ORDER_YZX                             0x4
#define   MWV207REG_TW_CONFIG_TRAVERSE_ORDER_ZYX                             0x5


#define MWV207REG_TW_CONFIG_SWATH_ENABLE_X                                   8:8
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_X_End                                 8
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_X_Start                               8
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_X_Type                              U01
#define   MWV207REG_TW_CONFIG_SWATH_ENABLE_X_DISABLE                         0x0
#define   MWV207REG_TW_CONFIG_SWATH_ENABLE_X_ENABLE                          0x1


#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Y                                   9:9
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Y_End                                 9
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Y_Start                               9
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Y_Type                              U01
#define   MWV207REG_TW_CONFIG_SWATH_ENABLE_Y_DISABLE                         0x0
#define   MWV207REG_TW_CONFIG_SWATH_ENABLE_Y_ENABLE                          0x1


#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Z                                 10:10
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Z_End                                10
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Z_Start                              10
#define MWV207REG_TW_CONFIG_SWATH_ENABLE_Z_Type                              U01
#define   MWV207REG_TW_CONFIG_SWATH_ENABLE_Z_DISABLE                         0x0
#define   MWV207REG_TW_CONFIG_SWATH_ENABLE_Z_ENABLE                          0x1

#define MWV207REG_TW_CONFIG_SWATH_SIZE_X                                   15:12
#define MWV207REG_TW_CONFIG_SWATH_SIZE_X_End                                  15
#define MWV207REG_TW_CONFIG_SWATH_SIZE_X_Start                                12
#define MWV207REG_TW_CONFIG_SWATH_SIZE_X_Type                                U04

#define MWV207REG_TW_CONFIG_SWATH_SIZE_Y                                   19:16
#define MWV207REG_TW_CONFIG_SWATH_SIZE_Y_End                                  19
#define MWV207REG_TW_CONFIG_SWATH_SIZE_Y_Start                                16
#define MWV207REG_TW_CONFIG_SWATH_SIZE_Y_Type                                U04

#define MWV207REG_TW_CONFIG_SWATH_SIZE_Z                                   23:20
#define MWV207REG_TW_CONFIG_SWATH_SIZE_Z_End                                  23
#define MWV207REG_TW_CONFIG_SWATH_SIZE_Z_Start                                20
#define MWV207REG_TW_CONFIG_SWATH_SIZE_Z_Type                                U04

#define MWV207REG_TW_CONFIG_VALUE_ORDER                                    26:24
#define MWV207REG_TW_CONFIG_VALUE_ORDER_End                                   26
#define MWV207REG_TW_CONFIG_VALUE_ORDER_Start                                 24
#define MWV207REG_TW_CONFIG_VALUE_ORDER_Type                                 U03
#define   MWV207REG_TW_CONFIG_VALUE_ORDER_GLW                                0x0
#define   MWV207REG_TW_CONFIG_VALUE_ORDER_GWL                                0x1
#define   MWV207REG_TW_CONFIG_VALUE_ORDER_LGW                                0x2
#define   MWV207REG_TW_CONFIG_VALUE_ORDER_WGL                                0x3
#define   MWV207REG_TW_CONFIG_VALUE_ORDER_LWG                                0x4
#define   MWV207REG_TW_CONFIG_VALUE_ORDER_WLG                                0x5

#define MWV207REG_TW_CONFIG_SELECT_HIGH_COUNT                              29:28
#define MWV207REG_TW_CONFIG_SELECT_HIGH_COUNT_End                             29
#define MWV207REG_TW_CONFIG_SELECT_HIGH_COUNT_Start                           28
#define MWV207REG_TW_CONFIG_SELECT_HIGH_COUNT_Type                           U02

#define   MWV207REG_TW_CONFIG_SELECT_HIGH_COUNT_X                            0x0

#define   MWV207REG_TW_CONFIG_SELECT_HIGH_COUNT_Y                            0x1

#define   MWV207REG_TW_CONFIG_SELECT_HIGH_COUNT_Z                            0x2

#define MWV207REG_TW_CONFIG_TRIGGER_MODE                                   31:31
#define MWV207REG_TW_CONFIG_TRIGGER_MODE_End                                  31
#define MWV207REG_TW_CONFIG_TRIGGER_MODE_Start                                31
#define MWV207REG_TW_CONFIG_TRIGGER_MODE_Type                                U01
#define   MWV207REG_TW_CONFIG_TRIGGER_MODE_SYNC                              0x0
#define   MWV207REG_TW_CONFIG_TRIGGER_MODE_ASYNC                             0x1

#define mwv207regTWInfoXRegAddrs                                          0x0241
#define MWV207REG_TW_INFO_X_Address                                      0x00904
#define MWV207REG_TW_INFO_X_MSB                                               15
#define MWV207REG_TW_INFO_X_LSB                                                0
#define MWV207REG_TW_INFO_X_BLK                                                0
#define MWV207REG_TW_INFO_X_Count                                              1
#define MWV207REG_TW_INFO_X_FieldMask                                 0xFFFFFFFF
#define MWV207REG_TW_INFO_X_ReadMask                                  0xFFFFFFFF
#define MWV207REG_TW_INFO_X_WriteMask                                 0xFFFFFFFF
#define MWV207REG_TW_INFO_X_ResetValue                                0x00000000


#define MWV207REG_TW_INFO_X_GLOBAL_SIZE                                     15:0
#define MWV207REG_TW_INFO_X_GLOBAL_SIZE_End                                   15
#define MWV207REG_TW_INFO_X_GLOBAL_SIZE_Start                                  0
#define MWV207REG_TW_INFO_X_GLOBAL_SIZE_Type                                 U16


#define MWV207REG_TW_INFO_X_GLOBAL_OFFSET                                  31:16
#define MWV207REG_TW_INFO_X_GLOBAL_OFFSET_End                                 31
#define MWV207REG_TW_INFO_X_GLOBAL_OFFSET_Start                               16
#define MWV207REG_TW_INFO_X_GLOBAL_OFFSET_Type                               U16

#define mwv207regTWInfoYRegAddrs                                          0x0242
#define MWV207REG_TW_INFO_Y_Address                                      0x00908
#define MWV207REG_TW_INFO_Y_MSB                                               15
#define MWV207REG_TW_INFO_Y_LSB                                                0
#define MWV207REG_TW_INFO_Y_BLK                                                0
#define MWV207REG_TW_INFO_Y_Count                                              1
#define MWV207REG_TW_INFO_Y_FieldMask                                 0xFFFFFFFF
#define MWV207REG_TW_INFO_Y_ReadMask                                  0xFFFFFFFF
#define MWV207REG_TW_INFO_Y_WriteMask                                 0xFFFFFFFF
#define MWV207REG_TW_INFO_Y_ResetValue                                0x00000000


#define MWV207REG_TW_INFO_Y_GLOBAL_SIZE                                     15:0
#define MWV207REG_TW_INFO_Y_GLOBAL_SIZE_End                                   15
#define MWV207REG_TW_INFO_Y_GLOBAL_SIZE_Start                                  0
#define MWV207REG_TW_INFO_Y_GLOBAL_SIZE_Type                                 U16


#define MWV207REG_TW_INFO_Y_GLOBAL_OFFSET                                  31:16
#define MWV207REG_TW_INFO_Y_GLOBAL_OFFSET_End                                 31
#define MWV207REG_TW_INFO_Y_GLOBAL_OFFSET_Start                               16
#define MWV207REG_TW_INFO_Y_GLOBAL_OFFSET_Type                               U16

#define mwv207regTWInfoZRegAddrs                                          0x0243
#define MWV207REG_TW_INFO_Z_Address                                      0x0090C
#define MWV207REG_TW_INFO_Z_MSB                                               15
#define MWV207REG_TW_INFO_Z_LSB                                                0
#define MWV207REG_TW_INFO_Z_BLK                                                0
#define MWV207REG_TW_INFO_Z_Count                                              1
#define MWV207REG_TW_INFO_Z_FieldMask                                 0xFFFFFFFF
#define MWV207REG_TW_INFO_Z_ReadMask                                  0xFFFFFFFF
#define MWV207REG_TW_INFO_Z_WriteMask                                 0xFFFFFFFF
#define MWV207REG_TW_INFO_Z_ResetValue                                0x00000000


#define MWV207REG_TW_INFO_Z_GLOBAL_SIZE                                     15:0
#define MWV207REG_TW_INFO_Z_GLOBAL_SIZE_End                                   15
#define MWV207REG_TW_INFO_Z_GLOBAL_SIZE_Start                                  0
#define MWV207REG_TW_INFO_Z_GLOBAL_SIZE_Type                                 U16


#define MWV207REG_TW_INFO_Z_GLOBAL_OFFSET                                  31:16
#define MWV207REG_TW_INFO_Z_GLOBAL_OFFSET_End                                 31
#define MWV207REG_TW_INFO_Z_GLOBAL_OFFSET_Start                               16
#define MWV207REG_TW_INFO_Z_GLOBAL_OFFSET_Type                               U16



#define mwv207regTWWorkGroupXRegAddrs                                     0x0244
#define MWV207REG_TW_WORK_GROUP_X_Address                                0x00910
#define MWV207REG_TW_WORK_GROUP_X_MSB                                         15
#define MWV207REG_TW_WORK_GROUP_X_LSB                                          0
#define MWV207REG_TW_WORK_GROUP_X_BLK                                          0
#define MWV207REG_TW_WORK_GROUP_X_Count                                        1
#define MWV207REG_TW_WORK_GROUP_X_FieldMask                           0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_X_ReadMask                            0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_X_WriteMask                           0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_X_ResetValue                          0x00000000


#define MWV207REG_TW_WORK_GROUP_X_SIZE                                       9:0
#define MWV207REG_TW_WORK_GROUP_X_SIZE_End                                     9
#define MWV207REG_TW_WORK_GROUP_X_SIZE_Start                                   0
#define MWV207REG_TW_WORK_GROUP_X_SIZE_Type                                  U10


#define MWV207REG_TW_WORK_GROUP_X_COUNT                                    31:16
#define MWV207REG_TW_WORK_GROUP_X_COUNT_End                                   31
#define MWV207REG_TW_WORK_GROUP_X_COUNT_Start                                 16
#define MWV207REG_TW_WORK_GROUP_X_COUNT_Type                                 U16



#define mwv207regTWWorkGroupYRegAddrs                                     0x0245
#define MWV207REG_TW_WORK_GROUP_Y_Address                                0x00914
#define MWV207REG_TW_WORK_GROUP_Y_MSB                                         15
#define MWV207REG_TW_WORK_GROUP_Y_LSB                                          0
#define MWV207REG_TW_WORK_GROUP_Y_BLK                                          0
#define MWV207REG_TW_WORK_GROUP_Y_Count                                        1
#define MWV207REG_TW_WORK_GROUP_Y_FieldMask                           0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_Y_ReadMask                            0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_Y_WriteMask                           0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_Y_ResetValue                          0x00000000


#define MWV207REG_TW_WORK_GROUP_Y_SIZE                                       9:0
#define MWV207REG_TW_WORK_GROUP_Y_SIZE_End                                     9
#define MWV207REG_TW_WORK_GROUP_Y_SIZE_Start                                   0
#define MWV207REG_TW_WORK_GROUP_Y_SIZE_Type                                  U10


#define MWV207REG_TW_WORK_GROUP_Y_COUNT                                    31:16
#define MWV207REG_TW_WORK_GROUP_Y_COUNT_End                                   31
#define MWV207REG_TW_WORK_GROUP_Y_COUNT_Start                                 16
#define MWV207REG_TW_WORK_GROUP_Y_COUNT_Type                                 U16



#define mwv207regTWWorkGroupZRegAddrs                                     0x0246
#define MWV207REG_TW_WORK_GROUP_Z_Address                                0x00918
#define MWV207REG_TW_WORK_GROUP_Z_MSB                                         15
#define MWV207REG_TW_WORK_GROUP_Z_LSB                                          0
#define MWV207REG_TW_WORK_GROUP_Z_BLK                                          0
#define MWV207REG_TW_WORK_GROUP_Z_Count                                        1
#define MWV207REG_TW_WORK_GROUP_Z_FieldMask                           0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_Z_ReadMask                            0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_Z_WriteMask                           0xFFFF03FF
#define MWV207REG_TW_WORK_GROUP_Z_ResetValue                          0x00000000


#define MWV207REG_TW_WORK_GROUP_Z_SIZE                                       9:0
#define MWV207REG_TW_WORK_GROUP_Z_SIZE_End                                     9
#define MWV207REG_TW_WORK_GROUP_Z_SIZE_Start                                   0
#define MWV207REG_TW_WORK_GROUP_Z_SIZE_Type                                  U10


#define MWV207REG_TW_WORK_GROUP_Z_COUNT                                    31:16
#define MWV207REG_TW_WORK_GROUP_Z_COUNT_End                                   31
#define MWV207REG_TW_WORK_GROUP_Z_COUNT_Start                                 16
#define MWV207REG_TW_WORK_GROUP_Z_COUNT_Type                                 U16

#define mwv207regTWShaderInfoRegAddrs                                     0x0247
#define MWV207REG_TW_SHADER_INFO_Address                                 0x0091C
#define MWV207REG_TW_SHADER_INFO_MSB                                          15
#define MWV207REG_TW_SHADER_INFO_LSB                                           0
#define MWV207REG_TW_SHADER_INFO_BLK                                           0
#define MWV207REG_TW_SHADER_INFO_Count                                         1
#define MWV207REG_TW_SHADER_INFO_FieldMask                            0xFFFFFFFF
#define MWV207REG_TW_SHADER_INFO_ReadMask                             0xFFFFFFFF
#define MWV207REG_TW_SHADER_INFO_WriteMask                            0xFFFFFFFF
#define MWV207REG_TW_SHADER_INFO_ResetValue                           0x00000000

#define MWV207REG_TW_SHADER_INFO_THREAD_ALLOCATION                          31:0
#define MWV207REG_TW_SHADER_INFO_THREAD_ALLOCATION_End                        31
#define MWV207REG_TW_SHADER_INFO_THREAD_ALLOCATION_Start                       0
#define MWV207REG_TW_SHADER_INFO_THREAD_ALLOCATION_Type                      U32

#define mwv207regTWTriggerRegAddrs                                        0x0248
#define MWV207REG_TW_TRIGGER_Address                                     0x00920
#define MWV207REG_TW_TRIGGER_MSB                                              15
#define MWV207REG_TW_TRIGGER_LSB                                               0
#define MWV207REG_TW_TRIGGER_BLK                                               0
#define MWV207REG_TW_TRIGGER_Count                                             1
#define MWV207REG_TW_TRIGGER_FieldMask                                0xFFFFFFFF
#define MWV207REG_TW_TRIGGER_ReadMask                                 0xFFFFFFFF
#define MWV207REG_TW_TRIGGER_WriteMask                                0xFFFFFFFF
#define MWV207REG_TW_TRIGGER_ResetValue                               0x00000000


#define MWV207REG_TW_TRIGGER_TRIGGER                                        31:0
#define MWV207REG_TW_TRIGGER_TRIGGER_End                                      31
#define MWV207REG_TW_TRIGGER_TRIGGER_Start                                     0
#define MWV207REG_TW_TRIGGER_TRIGGER_Type                                    U32

#define mwv207regTWShaderInfo2RegAddrs                                    0x0249
#define MWV207REG_TW_SHADER_INFO2_Address                                0x00924
#define MWV207REG_TW_SHADER_INFO2_MSB                                         15
#define MWV207REG_TW_SHADER_INFO2_LSB                                          0
#define MWV207REG_TW_SHADER_INFO2_BLK                                          0
#define MWV207REG_TW_SHADER_INFO2_Count                                        1
#define MWV207REG_TW_SHADER_INFO2_FieldMask                           0x33F1FFFF
#define MWV207REG_TW_SHADER_INFO2_ReadMask                            0x33F1FFFF
#define MWV207REG_TW_SHADER_INFO2_WriteMask                           0x33F1FFFF
#define MWV207REG_TW_SHADER_INFO2_ResetValue                          0x00000000


#define MWV207REG_TW_SHADER_INFO2_LOCAL_COUNT                               15:0
#define MWV207REG_TW_SHADER_INFO2_LOCAL_COUNT_End                             15
#define MWV207REG_TW_SHADER_INFO2_LOCAL_COUNT_Start                            0
#define MWV207REG_TW_SHADER_INFO2_LOCAL_COUNT_Type                           U16


#define MWV207REG_TW_SHADER_INFO2_BARRIER                                  16:16
#define MWV207REG_TW_SHADER_INFO2_BARRIER_End                                 16
#define MWV207REG_TW_SHADER_INFO2_BARRIER_Start                               16
#define MWV207REG_TW_SHADER_INFO2_BARRIER_Type                               U01
#define   MWV207REG_TW_SHADER_INFO2_BARRIER_NOT_PRESENT                      0x1
#define   MWV207REG_TW_SHADER_INFO2_BARRIER_PRESENT                          0x0

#define MWV207REG_TW_SHADER_INFO2_WORK_GROUP_IN_CLUSTER                    25:20
#define MWV207REG_TW_SHADER_INFO2_WORK_GROUP_IN_CLUSTER_End                   25
#define MWV207REG_TW_SHADER_INFO2_WORK_GROUP_IN_CLUSTER_Start                 20
#define MWV207REG_TW_SHADER_INFO2_WORK_GROUP_IN_CLUSTER_Type                 U06

#define MWV207REG_TW_SHADER_INFO2_LOCAL_ID_W                               29:28
#define MWV207REG_TW_SHADER_INFO2_LOCAL_ID_W_End                              29
#define MWV207REG_TW_SHADER_INFO2_LOCAL_ID_W_Start                            28
#define MWV207REG_TW_SHADER_INFO2_LOCAL_ID_W_Type                            U02
#define   MWV207REG_TW_SHADER_INFO2_LOCAL_ID_W_DISABLED                      0x0
#define   MWV207REG_TW_SHADER_INFO2_LOCAL_ID_W_LOCAL_STORAGE_BASE            0x1
#define   MWV207REG_TW_SHADER_INFO2_LOCAL_ID_W_RUNNING_WORK_GROUP_ID         0x2

#define mwv207regTWInfoGlobalSizeXRegAddrs                                0x024A
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_Address                          0x00928
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_MSB                                   15
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_LSB                                    0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_BLK                                    0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_Count                                  1
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_FieldMask                     0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_ReadMask                      0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_WriteMask                     0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_ResetValue                    0x00000000


#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_GLOBAL_SIZE                         31:0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_GLOBAL_SIZE_End                       31
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_GLOBAL_SIZE_Start                      0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_X_GLOBAL_SIZE_Type                     U32

#define mwv207regTWInfoGlobalOffsetXRegAddrs                              0x024B
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_Address                        0x0092C
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_MSB                                 15
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_LSB                                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_BLK                                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_Count                                1
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_FieldMask                   0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_ReadMask                    0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_WriteMask                   0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_ResetValue                  0x00000000


#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_GLOBAL_OFFSET                     31:0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_GLOBAL_OFFSET_End                   31
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_GLOBAL_OFFSET_Start                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_X_GLOBAL_OFFSET_Type                 U32

#define mwv207regTWInfoGlobalSizeYRegAddrs                                0x024C
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_Address                          0x00930
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_MSB                                   15
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_LSB                                    0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_BLK                                    0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_Count                                  1
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_FieldMask                     0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_ReadMask                      0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_WriteMask                     0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_ResetValue                    0x00000000


#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_GLOBAL_SIZE                         31:0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_GLOBAL_SIZE_End                       31
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_GLOBAL_SIZE_Start                      0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Y_GLOBAL_SIZE_Type                     U32

#define mwv207regTWInfoGlobalOffsetYRegAddrs                              0x024D
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_Address                        0x00934
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_MSB                                 15
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_LSB                                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_BLK                                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_Count                                1
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_FieldMask                   0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_ReadMask                    0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_WriteMask                   0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_ResetValue                  0x00000000


#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_GLOBAL_OFFSET                     31:0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_GLOBAL_OFFSET_End                   31
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_GLOBAL_OFFSET_Start                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Y_GLOBAL_OFFSET_Type                 U32

#define mwv207regTWInfoGlobalSizeZRegAddrs                                0x024E
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_Address                          0x00938
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_MSB                                   15
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_LSB                                    0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_BLK                                    0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_Count                                  1
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_FieldMask                     0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_ReadMask                      0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_WriteMask                     0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_ResetValue                    0x00000000


#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_GLOBAL_SIZE                         31:0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_GLOBAL_SIZE_End                       31
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_GLOBAL_SIZE_Start                      0
#define MWV207REG_TW_INFO_GLOBAL_SIZE_Z_GLOBAL_SIZE_Type                     U32

#define mwv207regTWInfoGlobalOffsetZRegAddrs                              0x024F
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_Address                        0x0093C
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_MSB                                 15
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_LSB                                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_BLK                                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_Count                                1
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_FieldMask                   0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_ReadMask                    0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_WriteMask                   0xFFFFFFFF
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_ResetValue                  0x00000000


#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_GLOBAL_OFFSET                     31:0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_GLOBAL_OFFSET_End                   31
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_GLOBAL_OFFSET_Start                  0
#define MWV207REG_TW_INFO_GLOBAL_OFFSET_Z_GLOBAL_OFFSET_Type                 U32

#define mwv207regTWWorkGroupCountXRegAddrs                                0x0250
#define MWV207REG_TW_WORK_GROUP_COUNT_X_Address                          0x00940
#define MWV207REG_TW_WORK_GROUP_COUNT_X_MSB                                   15
#define MWV207REG_TW_WORK_GROUP_COUNT_X_LSB                                    0
#define MWV207REG_TW_WORK_GROUP_COUNT_X_BLK                                    0
#define MWV207REG_TW_WORK_GROUP_COUNT_X_Count                                  1
#define MWV207REG_TW_WORK_GROUP_COUNT_X_FieldMask                     0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_X_ReadMask                      0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_X_WriteMask                     0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_X_ResetValue                    0x00000000

#define MWV207REG_TW_WORK_GROUP_COUNT_X_COUNT                               31:0
#define MWV207REG_TW_WORK_GROUP_COUNT_X_COUNT_End                             31
#define MWV207REG_TW_WORK_GROUP_COUNT_X_COUNT_Start                            0
#define MWV207REG_TW_WORK_GROUP_COUNT_X_COUNT_Type                           U32

#define mwv207regTWWorkGroupCountYRegAddrs                                0x0251
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_Address                          0x00944
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_MSB                                   15
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_LSB                                    0
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_BLK                                    0
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_Count                                  1
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_FieldMask                     0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_ReadMask                      0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_WriteMask                     0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_ResetValue                    0x00000000

#define MWV207REG_TW_WORK_GROUP_COUNT_Y_COUNT                               31:0
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_COUNT_End                             31
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_COUNT_Start                            0
#define MWV207REG_TW_WORK_GROUP_COUNT_Y_COUNT_Type                           U32

#define mwv207regTWWorkGroupCountZRegAddrs                                0x0252
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_Address                          0x00948
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_MSB                                   15
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_LSB                                    0
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_BLK                                    0
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_Count                                  1
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_FieldMask                     0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_ReadMask                      0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_WriteMask                     0xFFFFFFFF
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_ResetValue                    0x00000000

#define MWV207REG_TW_WORK_GROUP_COUNT_Z_COUNT                               31:0
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_COUNT_End                             31
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_COUNT_Start                            0
#define MWV207REG_TW_WORK_GROUP_COUNT_Z_COUNT_Type                           U32

#define mwv207regTWWorkgroupSizeXRegAddrs                                 0x0253
#define MWV207REG_TW_WORKGROUP_SIZE_X_Address                            0x0094C
#define MWV207REG_TW_WORKGROUP_SIZE_X_MSB                                     15
#define MWV207REG_TW_WORKGROUP_SIZE_X_LSB                                      0
#define MWV207REG_TW_WORKGROUP_SIZE_X_BLK                                      0
#define MWV207REG_TW_WORKGROUP_SIZE_X_Count                                    1
#define MWV207REG_TW_WORKGROUP_SIZE_X_FieldMask                       0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_X_ReadMask                        0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_X_WriteMask                       0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_X_ResetValue                      0x00000000


#define MWV207REG_TW_WORKGROUP_SIZE_X_SIZE                                   9:0
#define MWV207REG_TW_WORKGROUP_SIZE_X_SIZE_End                                 9
#define MWV207REG_TW_WORKGROUP_SIZE_X_SIZE_Start                               0
#define MWV207REG_TW_WORKGROUP_SIZE_X_SIZE_Type                              U10

#define mwv207regTWWorkgroupSizeYRegAddrs                                 0x0254
#define MWV207REG_TW_WORKGROUP_SIZE_Y_Address                            0x00950
#define MWV207REG_TW_WORKGROUP_SIZE_Y_MSB                                     15
#define MWV207REG_TW_WORKGROUP_SIZE_Y_LSB                                      0
#define MWV207REG_TW_WORKGROUP_SIZE_Y_BLK                                      0
#define MWV207REG_TW_WORKGROUP_SIZE_Y_Count                                    1
#define MWV207REG_TW_WORKGROUP_SIZE_Y_FieldMask                       0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_Y_ReadMask                        0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_Y_WriteMask                       0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_Y_ResetValue                      0x00000000


#define MWV207REG_TW_WORKGROUP_SIZE_Y_SIZE                                   9:0
#define MWV207REG_TW_WORKGROUP_SIZE_Y_SIZE_End                                 9
#define MWV207REG_TW_WORKGROUP_SIZE_Y_SIZE_Start                               0
#define MWV207REG_TW_WORKGROUP_SIZE_Y_SIZE_Type                              U10

#define mwv207regTWWorkgroupSizeZRegAddrs                                 0x0255
#define MWV207REG_TW_WORKGROUP_SIZE_Z_Address                            0x00954
#define MWV207REG_TW_WORKGROUP_SIZE_Z_MSB                                     15
#define MWV207REG_TW_WORKGROUP_SIZE_Z_LSB                                      0
#define MWV207REG_TW_WORKGROUP_SIZE_Z_BLK                                      0
#define MWV207REG_TW_WORKGROUP_SIZE_Z_Count                                    1
#define MWV207REG_TW_WORKGROUP_SIZE_Z_FieldMask                       0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_Z_ReadMask                        0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_Z_WriteMask                       0x000003FF
#define MWV207REG_TW_WORKGROUP_SIZE_Z_ResetValue                      0x00000000


#define MWV207REG_TW_WORKGROUP_SIZE_Z_SIZE                                   9:0
#define MWV207REG_TW_WORKGROUP_SIZE_Z_SIZE_End                                 9
#define MWV207REG_TW_WORKGROUP_SIZE_Z_SIZE_Start                               0
#define MWV207REG_TW_WORKGROUP_SIZE_Z_SIZE_Type                              U10

#define mwv207regTWInfoGlobalScaleXRegAddrs                               0x0256
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_Address                         0x00958
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_MSB                                  15
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_LSB                                   0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_BLK                                   0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_Count                                 1
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_FieldMask                    0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_ReadMask                     0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_WriteMask                    0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_ResetValue                   0x00000000


#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_SCALE                               7:0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_SCALE_End                             7
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_SCALE_Start                           0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_X_SCALE_Type                          U08

#define mwv207regTWInfoGlobalScaleYRegAddrs                               0x0257
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_Address                         0x0095C
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_MSB                                  15
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_LSB                                   0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_BLK                                   0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_Count                                 1
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_FieldMask                    0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_ReadMask                     0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_WriteMask                    0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_ResetValue                   0x00000000


#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_SCALE                               7:0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_SCALE_End                             7
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_SCALE_Start                           0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Y_SCALE_Type                          U08

#define mwv207regTWInfoGlobalScaleZRegAddrs                               0x0258
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_Address                         0x00960
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_MSB                                  15
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_LSB                                   0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_BLK                                   0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_Count                                 1
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_FieldMask                    0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_ReadMask                     0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_WriteMask                    0x000000FF
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_ResetValue                   0x00000000


#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_SCALE                               7:0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_SCALE_End                             7
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_SCALE_Start                           0
#define MWV207REG_TW_INFO_GLOBAL_SCALE_Z_SCALE_Type                          U08





#define mwv207regGSControlRegAddrs                                        0x0440
#define MWV207REG_GS_CONTROL_Address                                     0x01100
#define MWV207REG_GS_CONTROL_MSB                                              15
#define MWV207REG_GS_CONTROL_LSB                                               0
#define MWV207REG_GS_CONTROL_BLK                                               0
#define MWV207REG_GS_CONTROL_Count                                             1
#define MWV207REG_GS_CONTROL_FieldMask                                0x3F37F3F1
#define MWV207REG_GS_CONTROL_ReadMask                                 0x3F37F3F1
#define MWV207REG_GS_CONTROL_WriteMask                                0x3F37F3F1
#define MWV207REG_GS_CONTROL_ResetValue                               0x00000000


#define MWV207REG_GS_CONTROL_MODE                                            0:0
#define MWV207REG_GS_CONTROL_MODE_End                                          0
#define MWV207REG_GS_CONTROL_MODE_Start                                        0
#define MWV207REG_GS_CONTROL_MODE_Type                                       U01

#define   MWV207REG_GS_CONTROL_MODE_BYPASS                                   0x0

#define   MWV207REG_GS_CONTROL_MODE_ENABLE                                   0x1


#define MWV207REG_GS_CONTROL_OUTPUT_COUNT                                    9:4
#define MWV207REG_GS_CONTROL_OUTPUT_COUNT_End                                  9
#define MWV207REG_GS_CONTROL_OUTPUT_COUNT_Start                                4
#define MWV207REG_GS_CONTROL_OUTPUT_COUNT_Type                               U06


#define MWV207REG_GS_CONTROL_TEMP_COUNT                                    18:12
#define MWV207REG_GS_CONTROL_TEMP_COUNT_End                                   18
#define MWV207REG_GS_CONTROL_TEMP_COUNT_Start                                 12
#define MWV207REG_GS_CONTROL_TEMP_COUNT_Type                                 U07


#define MWV207REG_GS_CONTROL_INPUT_START                                   21:20
#define MWV207REG_GS_CONTROL_INPUT_START_End                                  21
#define MWV207REG_GS_CONTROL_INPUT_START_Start                                20
#define MWV207REG_GS_CONTROL_INPUT_START_Type                                U02
#define   MWV207REG_GS_CONTROL_INPUT_START_R0Z                               0x0

#define   MWV207REG_GS_CONTROL_INPUT_START_R1X                               0x1
#define   MWV207REG_GS_CONTROL_INPUT_START_R1Z                               0x2

#define   MWV207REG_GS_CONTROL_INPUT_START_R2X                               0x3

#define MWV207REG_GS_CONTROL_HAS_RESTART                                   24:24
#define MWV207REG_GS_CONTROL_HAS_RESTART_End                                  24
#define MWV207REG_GS_CONTROL_HAS_RESTART_Start                                24
#define MWV207REG_GS_CONTROL_HAS_RESTART_Type                                U01

#define MWV207REG_GS_CONTROL_HAS_STREAM_OUT                                25:25
#define MWV207REG_GS_CONTROL_HAS_STREAM_OUT_End                               25
#define MWV207REG_GS_CONTROL_HAS_STREAM_OUT_Start                             25
#define MWV207REG_GS_CONTROL_HAS_STREAM_OUT_Type                             U01

#define MWV207REG_GS_CONTROL_HAS_PRIMITIVE_ID                              26:26
#define MWV207REG_GS_CONTROL_HAS_PRIMITIVE_ID_End                             26
#define MWV207REG_GS_CONTROL_HAS_PRIMITIVE_ID_Start                           26
#define MWV207REG_GS_CONTROL_HAS_PRIMITIVE_ID_Type                           U01

#define   MWV207REG_GS_CONTROL_HAS_PRIMITIVE_ID_NO                           0x0
#define   MWV207REG_GS_CONTROL_HAS_PRIMITIVE_ID_YES                          0x1

#define MWV207REG_GS_CONTROL_HAS_INSTANCE_ID                               27:27
#define MWV207REG_GS_CONTROL_HAS_INSTANCE_ID_End                              27
#define MWV207REG_GS_CONTROL_HAS_INSTANCE_ID_Start                            27
#define MWV207REG_GS_CONTROL_HAS_INSTANCE_ID_Type                            U01

#define   MWV207REG_GS_CONTROL_HAS_INSTANCE_ID_NO                            0x0
#define   MWV207REG_GS_CONTROL_HAS_INSTANCE_ID_YES                           0x1


#define MWV207REG_GS_CONTROL_LAST_ATTRIBUTE                                29:28
#define MWV207REG_GS_CONTROL_LAST_ATTRIBUTE_End                               29
#define MWV207REG_GS_CONTROL_LAST_ATTRIBUTE_Start                             28
#define MWV207REG_GS_CONTROL_LAST_ATTRIBUTE_Type                             U02

#define   MWV207REG_GS_CONTROL_LAST_ATTRIBUTE_FOUR                           0x0

#define   MWV207REG_GS_CONTROL_LAST_ATTRIBUTE_ONE                            0x1

#define   MWV207REG_GS_CONTROL_LAST_ATTRIBUTE_TWO                            0x2

#define   MWV207REG_GS_CONTROL_LAST_ATTRIBUTE_THREE                          0x3

#define mwv207regGSTypeRegAddrs                                           0x0441
#define MWV207REG_GS_TYPE_Address                                        0x01104
#define MWV207REG_GS_TYPE_MSB                                                 15
#define MWV207REG_GS_TYPE_LSB                                                  0
#define MWV207REG_GS_TYPE_BLK                                                  0
#define MWV207REG_GS_TYPE_Count                                                1
#define MWV207REG_GS_TYPE_FieldMask                                   0x0000000F
#define MWV207REG_GS_TYPE_ReadMask                                    0x0000000F
#define MWV207REG_GS_TYPE_WriteMask                                   0x0000000F
#define MWV207REG_GS_TYPE_ResetValue                                  0x00000001


#define MWV207REG_GS_TYPE_OUTPUT_TYPE                                        3:0
#define MWV207REG_GS_TYPE_OUTPUT_TYPE_End                                      3
#define MWV207REG_GS_TYPE_OUTPUT_TYPE_Start                                    0
#define MWV207REG_GS_TYPE_OUTPUT_TYPE_Type                                   U04
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_POINT_LIST                           0x1
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_LINE_LIST                            0x2
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_LINE_STRIP                           0x3
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_TRIANGLE_LIST                        0x4
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_TRIANGLE_STRIP                       0x5
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_TRIANGLE_FAN                         0x6
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_LINE_LOOP                            0x7
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_RECTANGLE                            0x8
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_LINES_ADJACENCY                      0x9
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_LINE_STRIP_ADJACENCY                 0xA
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_TRIANGLES_ADJACENCY                  0xB
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_TRIANGLE_STRIP_ADJACENCY             0xC
#define   MWV207REG_GS_TYPE_OUTPUT_TYPE_PATCH_LIST                           0xD

#define mwv207regGSCountersRegAddrs                                       0x0442
#define MWV207REG_GS_COUNTERS_Address                                    0x01108
#define MWV207REG_GS_COUNTERS_MSB                                             15
#define MWV207REG_GS_COUNTERS_LSB                                              0
#define MWV207REG_GS_COUNTERS_BLK                                              0
#define MWV207REG_GS_COUNTERS_Count                                            1
#define MWV207REG_GS_COUNTERS_FieldMask                               0x01FF007F
#define MWV207REG_GS_COUNTERS_ReadMask                                0x01FF007F
#define MWV207REG_GS_COUNTERS_WriteMask                               0x01FF007F
#define MWV207REG_GS_COUNTERS_ResetValue                              0x01000001


#define MWV207REG_GS_COUNTERS_INSTANCE_COUNT                                 6:0
#define MWV207REG_GS_COUNTERS_INSTANCE_COUNT_End                               6
#define MWV207REG_GS_COUNTERS_INSTANCE_COUNT_Start                             0
#define MWV207REG_GS_COUNTERS_INSTANCE_COUNT_Type                            U07


#define MWV207REG_GS_COUNTERS_VERTEX_COUNT                                 24:16
#define MWV207REG_GS_COUNTERS_VERTEX_COUNT_End                                24
#define MWV207REG_GS_COUNTERS_VERTEX_COUNT_Start                              16
#define MWV207REG_GS_COUNTERS_VERTEX_COUNT_Type                              U09




#define mwv207regGSOutputRegAddrs                                         0x0448
#define MWV207REG_GS_OUTPUT_Address                                      0x01120
#define MWV207REG_GS_OUTPUT_MSB                                               15
#define MWV207REG_GS_OUTPUT_LSB                                                3
#define MWV207REG_GS_OUTPUT_BLK                                                3
#define MWV207REG_GS_OUTPUT_Count                                              8
#define MWV207REG_GS_OUTPUT_FieldMask                                 0x3F3F3F3F
#define MWV207REG_GS_OUTPUT_ReadMask                                  0x3F3F3F3F
#define MWV207REG_GS_OUTPUT_WriteMask                                 0x3F3F3F3F
#define MWV207REG_GS_OUTPUT_ResetValue                                0x00000000

#define MWV207REG_GS_OUTPUT_OUTPUT0                                          5:0
#define MWV207REG_GS_OUTPUT_OUTPUT0_End                                        5
#define MWV207REG_GS_OUTPUT_OUTPUT0_Start                                      0
#define MWV207REG_GS_OUTPUT_OUTPUT0_Type                                     U06

#define MWV207REG_GS_OUTPUT_OUTPUT1                                         13:8
#define MWV207REG_GS_OUTPUT_OUTPUT1_End                                       13
#define MWV207REG_GS_OUTPUT_OUTPUT1_Start                                      8
#define MWV207REG_GS_OUTPUT_OUTPUT1_Type                                     U06

#define MWV207REG_GS_OUTPUT_OUTPUT2                                        21:16
#define MWV207REG_GS_OUTPUT_OUTPUT2_End                                       21
#define MWV207REG_GS_OUTPUT_OUTPUT2_Start                                     16
#define MWV207REG_GS_OUTPUT_OUTPUT2_Type                                     U06

#define MWV207REG_GS_OUTPUT_OUTPUT3                                        29:24
#define MWV207REG_GS_OUTPUT_OUTPUT3_End                                       29
#define MWV207REG_GS_OUTPUT_OUTPUT3_Start                                     24
#define MWV207REG_GS_OUTPUT_OUTPUT3_Type                                     U06




#define mwv207regGSStartRegAddrs                                          0x0443
#define MWV207REG_GS_START_Address                                       0x0110C
#define MWV207REG_GS_START_MSB                                                15
#define MWV207REG_GS_START_LSB                                                 0
#define MWV207REG_GS_START_BLK                                                 0
#define MWV207REG_GS_START_Count                                               1
#define MWV207REG_GS_START_FieldMask                                  0x000FFFFF
#define MWV207REG_GS_START_ReadMask                                   0x000FFFFF
#define MWV207REG_GS_START_WriteMask                                  0x000FFFFF
#define MWV207REG_GS_START_ResetValue                                 0x00000000


#define MWV207REG_GS_START_PC                                               19:0
#define MWV207REG_GS_START_PC_End                                             19
#define MWV207REG_GS_START_PC_Start                                            0
#define MWV207REG_GS_START_PC_Type                                           U20




#define mwv207regGSRelativeEndRegAddrs                                    0x0444
#define MWV207REG_GS_RELATIVE_END_Address                                0x01110
#define MWV207REG_GS_RELATIVE_END_MSB                                         15
#define MWV207REG_GS_RELATIVE_END_LSB                                          0
#define MWV207REG_GS_RELATIVE_END_BLK                                          0
#define MWV207REG_GS_RELATIVE_END_Count                                        1
#define MWV207REG_GS_RELATIVE_END_FieldMask                           0x001FFFFF
#define MWV207REG_GS_RELATIVE_END_ReadMask                            0x001FFFFF
#define MWV207REG_GS_RELATIVE_END_WriteMask                           0x001FFFFF
#define MWV207REG_GS_RELATIVE_END_ResetValue                          0x00000000

#define MWV207REG_GS_RELATIVE_END_PC                                        20:0
#define MWV207REG_GS_RELATIVE_END_PC_End                                      20
#define MWV207REG_GS_RELATIVE_END_PC_Start                                     0
#define MWV207REG_GS_RELATIVE_END_PC_Type                                    U21



#define mwv207regGSInstructionRegAddrs                                    0x0445
#define MWV207REG_GS_INSTRUCTION_Address                                 0x01114
#define MWV207REG_GS_INSTRUCTION_MSB                                          15
#define MWV207REG_GS_INSTRUCTION_LSB                                           0
#define MWV207REG_GS_INSTRUCTION_BLK                                           0
#define MWV207REG_GS_INSTRUCTION_Count                                         1
#define MWV207REG_GS_INSTRUCTION_FieldMask                            0xFFFFFFFF
#define MWV207REG_GS_INSTRUCTION_ReadMask                             0xFFFFFF00
#define MWV207REG_GS_INSTRUCTION_WriteMask                            0xFFFFFF00
#define MWV207REG_GS_INSTRUCTION_ResetValue                           0x00000000


#define MWV207REG_GS_INSTRUCTION_ADDRESS                                    31:0
#define MWV207REG_GS_INSTRUCTION_ADDRESS_End                                  31
#define MWV207REG_GS_INSTRUCTION_ADDRESS_Start                                 0
#define MWV207REG_GS_INSTRUCTION_ADDRESS_Type                                U32




#define mwv207regGSInstructionPrefetchRegAddrs                            0x0446
#define MWV207REG_GS_INSTRUCTION_PREFETCH_Address                        0x01118
#define MWV207REG_GS_INSTRUCTION_PREFETCH_MSB                                 15
#define MWV207REG_GS_INSTRUCTION_PREFETCH_LSB                                  0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_BLK                                  0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_Count                                1
#define MWV207REG_GS_INSTRUCTION_PREFETCH_FieldMask                   0x000FFFFF
#define MWV207REG_GS_INSTRUCTION_PREFETCH_ReadMask                    0x000FFFFF
#define MWV207REG_GS_INSTRUCTION_PREFETCH_WriteMask                   0x000FFFFF
#define MWV207REG_GS_INSTRUCTION_PREFETCH_ResetValue                  0x00000000


#define MWV207REG_GS_INSTRUCTION_PREFETCH_PC                                19:0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_PC_End                              19
#define MWV207REG_GS_INSTRUCTION_PREFETCH_PC_Start                             0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_PC_Type                            U20



#define mwv207regGSInstructionPrefetchRelativeEndRegAddrs                 0x0447
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_Address           0x0111C
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_MSB                    15
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_LSB                     0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_BLK                     0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_Count                   1
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_FieldMask      0x000FFFFF
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_ReadMask       0x000FFFFF
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_WriteMask      0x000FFFFF
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_ResetValue     0x00000000

#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_PC                   19:0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_End                 19
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Start                0
#define MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Type               U20




#define mwv207regGSThrottleRegAddrs                                       0x0450
#define MWV207REG_GS_THROTTLE_Address                                    0x01140
#define MWV207REG_GS_THROTTLE_MSB                                             15
#define MWV207REG_GS_THROTTLE_LSB                                              0
#define MWV207REG_GS_THROTTLE_BLK                                              0
#define MWV207REG_GS_THROTTLE_Count                                            1
#define MWV207REG_GS_THROTTLE_FieldMask                               0x07E0FF3F
#define MWV207REG_GS_THROTTLE_ReadMask                                0x07E0FF3F
#define MWV207REG_GS_THROTTLE_WriteMask                               0x07E0FF3F
#define MWV207REG_GS_THROTTLE_ResetValue                              0x00000000

#define MWV207REG_GS_THROTTLE_MAX_PAGES                                      5:0
#define MWV207REG_GS_THROTTLE_MAX_PAGES_End                                    5
#define MWV207REG_GS_THROTTLE_MAX_PAGES_Start                                  0
#define MWV207REG_GS_THROTTLE_MAX_PAGES_Type                                 U06


#define MWV207REG_GS_THROTTLE_MAX_THREADS                                   15:8
#define MWV207REG_GS_THROTTLE_MAX_THREADS_End                                 15
#define MWV207REG_GS_THROTTLE_MAX_THREADS_Start                                8
#define MWV207REG_GS_THROTTLE_MAX_THREADS_Type                               U08

#define MWV207REG_GS_THROTTLE_MIN_PAGES                                    26:21
#define MWV207REG_GS_THROTTLE_MIN_PAGES_End                                   26
#define MWV207REG_GS_THROTTLE_MIN_PAGES_Start                                 21
#define MWV207REG_GS_THROTTLE_MIN_PAGES_Type                                 U06



#define mwv207regGSAttributeRegAddrs                                      0x0451
#define MWV207REG_GS_ATTRIBUTE_Address                                   0x01144
#define MWV207REG_GS_ATTRIBUTE_MSB                                            15
#define MWV207REG_GS_ATTRIBUTE_LSB                                             0
#define MWV207REG_GS_ATTRIBUTE_BLK                                             0
#define MWV207REG_GS_ATTRIBUTE_Count                                           1
#define MWV207REG_GS_ATTRIBUTE_FieldMask                              0xFFF1FFFF
#define MWV207REG_GS_ATTRIBUTE_ReadMask                               0xFFF1FFFF
#define MWV207REG_GS_ATTRIBUTE_WriteMask                              0xFFF1FFFF
#define MWV207REG_GS_ATTRIBUTE_ResetValue                             0x00000000

#define MWV207REG_GS_ATTRIBUTE_VERTEX_SIZE                                   7:0
#define MWV207REG_GS_ATTRIBUTE_VERTEX_SIZE_End                                 7
#define MWV207REG_GS_ATTRIBUTE_VERTEX_SIZE_Start                               0
#define MWV207REG_GS_ATTRIBUTE_VERTEX_SIZE_Type                              U08

#define MWV207REG_GS_ATTRIBUTE_THREAD_SIZE                                  16:8
#define MWV207REG_GS_ATTRIBUTE_THREAD_SIZE_End                                16
#define MWV207REG_GS_ATTRIBUTE_THREAD_SIZE_Start                               8
#define MWV207REG_GS_ATTRIBUTE_THREAD_SIZE_Type                              U09

#define MWV207REG_GS_ATTRIBUTE_META_DATA_OFFSET                            31:20
#define MWV207REG_GS_ATTRIBUTE_META_DATA_OFFSET_End                           31
#define MWV207REG_GS_ATTRIBUTE_META_DATA_OFFSET_Start                         20
#define MWV207REG_GS_ATTRIBUTE_META_DATA_OFFSET_Type                         U12




#define mwv207regGSAttributeExRegAddrs                                    0x0452
#define MWV207REG_GS_ATTRIBUTE_EX_Address                                0x01148
#define MWV207REG_GS_ATTRIBUTE_EX_MSB                                         15
#define MWV207REG_GS_ATTRIBUTE_EX_LSB                                          0
#define MWV207REG_GS_ATTRIBUTE_EX_BLK                                          0
#define MWV207REG_GS_ATTRIBUTE_EX_Count                                        1
#define MWV207REG_GS_ATTRIBUTE_EX_FieldMask                           0x00000FFF
#define MWV207REG_GS_ATTRIBUTE_EX_ReadMask                            0x00000FFF
#define MWV207REG_GS_ATTRIBUTE_EX_WriteMask                           0x00000FFF
#define MWV207REG_GS_ATTRIBUTE_EX_ResetValue                          0x00000000

#define MWV207REG_GS_ATTRIBUTE_EX_GROUP_SIZE                                11:0
#define MWV207REG_GS_ATTRIBUTE_EX_GROUP_SIZE_End                              11
#define MWV207REG_GS_ATTRIBUTE_EX_GROUP_SIZE_Start                             0
#define MWV207REG_GS_ATTRIBUTE_EX_GROUP_SIZE_Type                            U12




#define mwv207regGSUniformBaseRegAddrs                                    0x0453
#define MWV207REG_GS_UNIFORM_BASE_Address                                0x0114C
#define MWV207REG_GS_UNIFORM_BASE_MSB                                         15
#define MWV207REG_GS_UNIFORM_BASE_LSB                                          0
#define MWV207REG_GS_UNIFORM_BASE_BLK                                          0
#define MWV207REG_GS_UNIFORM_BASE_Count                                        1
#define MWV207REG_GS_UNIFORM_BASE_FieldMask                           0x000003FF
#define MWV207REG_GS_UNIFORM_BASE_ReadMask                            0x000003FF
#define MWV207REG_GS_UNIFORM_BASE_WriteMask                           0x000003FF
#define MWV207REG_GS_UNIFORM_BASE_ResetValue                          0x00000000


#define MWV207REG_GS_UNIFORM_BASE_OFFSET                                     9:0
#define MWV207REG_GS_UNIFORM_BASE_OFFSET_End                                   9
#define MWV207REG_GS_UNIFORM_BASE_OFFSET_Start                                 0
#define MWV207REG_GS_UNIFORM_BASE_OFFSET_Type                                U10



#define mwv207regGSUniformLockRegAddrs                                    0x0454
#define MWV207REG_GS_UNIFORM_LOCK_Address                                0x01150
#define MWV207REG_GS_UNIFORM_LOCK_MSB                                         15
#define MWV207REG_GS_UNIFORM_LOCK_LSB                                          0
#define MWV207REG_GS_UNIFORM_LOCK_BLK                                          0
#define MWV207REG_GS_UNIFORM_LOCK_Count                                        1
#define MWV207REG_GS_UNIFORM_LOCK_FieldMask                           0x000003FF
#define MWV207REG_GS_UNIFORM_LOCK_ReadMask                            0x000003FF
#define MWV207REG_GS_UNIFORM_LOCK_WriteMask                           0x000003FF
#define MWV207REG_GS_UNIFORM_LOCK_ResetValue                          0x00000000


#define MWV207REG_GS_UNIFORM_LOCK_OFFSET                                     9:0
#define MWV207REG_GS_UNIFORM_LOCK_OFFSET_End                                   9
#define MWV207REG_GS_UNIFORM_LOCK_OFFSET_Start                                 0
#define MWV207REG_GS_UNIFORM_LOCK_OFFSET_Type                                U10




#define mwv207regGSSamplerBaseRegAddrs                                    0x0455
#define MWV207REG_GS_SAMPLER_BASE_Address                                0x01154
#define MWV207REG_GS_SAMPLER_BASE_MSB                                         15
#define MWV207REG_GS_SAMPLER_BASE_LSB                                          0
#define MWV207REG_GS_SAMPLER_BASE_BLK                                          0
#define MWV207REG_GS_SAMPLER_BASE_Count                                        1
#define MWV207REG_GS_SAMPLER_BASE_FieldMask                           0x03FF007F
#define MWV207REG_GS_SAMPLER_BASE_ReadMask                            0x03FF007F
#define MWV207REG_GS_SAMPLER_BASE_WriteMask                           0x03FF007F
#define MWV207REG_GS_SAMPLER_BASE_ResetValue                          0x00000000


#define MWV207REG_GS_SAMPLER_BASE_OFFSET                                     6:0
#define MWV207REG_GS_SAMPLER_BASE_OFFSET_End                                   6
#define MWV207REG_GS_SAMPLER_BASE_OFFSET_Start                                 0
#define MWV207REG_GS_SAMPLER_BASE_OFFSET_Type                                U07


#define MWV207REG_GS_SAMPLER_BASE_TXD_OFFSET                               25:16
#define MWV207REG_GS_SAMPLER_BASE_TXD_OFFSET_End                              25
#define MWV207REG_GS_SAMPLER_BASE_TXD_OFFSET_Start                            16
#define MWV207REG_GS_SAMPLER_BASE_TXD_OFFSET_Type                            U10



#define mwv207regGSSamplerLockRegAddrs                                    0x0456
#define MWV207REG_GS_SAMPLER_LOCK_Address                                0x01158
#define MWV207REG_GS_SAMPLER_LOCK_MSB                                         15
#define MWV207REG_GS_SAMPLER_LOCK_LSB                                          0
#define MWV207REG_GS_SAMPLER_LOCK_BLK                                          0
#define MWV207REG_GS_SAMPLER_LOCK_Count                                        1
#define MWV207REG_GS_SAMPLER_LOCK_FieldMask                           0x03FF007F
#define MWV207REG_GS_SAMPLER_LOCK_ReadMask                            0x03FF007F
#define MWV207REG_GS_SAMPLER_LOCK_WriteMask                           0x03FF007F
#define MWV207REG_GS_SAMPLER_LOCK_ResetValue                          0x00000000


#define MWV207REG_GS_SAMPLER_LOCK_OFFSET                                     6:0
#define MWV207REG_GS_SAMPLER_LOCK_OFFSET_End                                   6
#define MWV207REG_GS_SAMPLER_LOCK_OFFSET_Start                                 0
#define MWV207REG_GS_SAMPLER_LOCK_OFFSET_Type                                U07


#define MWV207REG_GS_SAMPLER_LOCK_TXD_OFFSET                               25:16
#define MWV207REG_GS_SAMPLER_LOCK_TXD_OFFSET_End                              25
#define MWV207REG_GS_SAMPLER_LOCK_TXD_OFFSET_Start                            16
#define MWV207REG_GS_SAMPLER_LOCK_TXD_OFFSET_Type                            U10




#define mwv207regGSThrottleExRegAddrs                                     0x0457
#define MWV207REG_GS_THROTTLE_EX_Address                                 0x0115C
#define MWV207REG_GS_THROTTLE_EX_MSB                                          15
#define MWV207REG_GS_THROTTLE_EX_LSB                                           0
#define MWV207REG_GS_THROTTLE_EX_BLK                                           0
#define MWV207REG_GS_THROTTLE_EX_Count                                         1
#define MWV207REG_GS_THROTTLE_EX_FieldMask                            0x000000FF
#define MWV207REG_GS_THROTTLE_EX_ReadMask                             0x000000FF
#define MWV207REG_GS_THROTTLE_EX_WriteMask                            0x000000FF
#define MWV207REG_GS_THROTTLE_EX_ResetValue                           0x000000FF

#define MWV207REG_GS_THROTTLE_EX_MAX_RMISSES                                 7:0
#define MWV207REG_GS_THROTTLE_EX_MAX_RMISSES_End                               7
#define MWV207REG_GS_THROTTLE_EX_MAX_RMISSES_Start                             0
#define MWV207REG_GS_THROTTLE_EX_MAX_RMISSES_Type                            U08




#define mwv207regGSAttributeGlobalControlRegAddrs                         0x0458
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_Address                    0x01160
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MSB                             15
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_LSB                              0
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_BLK                              0
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_Count                            1
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_FieldMask               0xFFFFF0F1
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ReadMask                0xFFFFF0F1
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_WriteMask               0xFFFFF0F1
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ResetValue              0x00000000


#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM               0:0
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_End             0
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Start           0
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Type          U01
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_DISABLED    0x0
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_ENABLED     0x1


#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER           7:4
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_End         7
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Start       4
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Type      U04
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS1K    0x0
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS2K    0x1
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS4K    0x2
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS8K    0x3
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS16K   0x4
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS32K   0x5
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS64K   0x6
#define   MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS128K  0x7


#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR                    31:12
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_End                   31
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Start                 12
#define MWV207REG_GS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Type                 U20


#define AQPixelShaderEndPCRegAddrs                                        0x0400
#define AQ_PIXEL_SHADER_END_PC_Address                                   0x01000
#define AQ_PIXEL_SHADER_END_PC_MSB                                            15
#define AQ_PIXEL_SHADER_END_PC_LSB                                             0
#define AQ_PIXEL_SHADER_END_PC_BLK                                             0
#define AQ_PIXEL_SHADER_END_PC_Count                                           1
#define AQ_PIXEL_SHADER_END_PC_FieldMask                              0x00000FFF
#define AQ_PIXEL_SHADER_END_PC_ReadMask                               0x00000FFF
#define AQ_PIXEL_SHADER_END_PC_WriteMask                              0x00000FFF
#define AQ_PIXEL_SHADER_END_PC_ResetValue                             0x00000000

#define AQ_PIXEL_SHADER_END_PC_ADDRESS                                      11:0
#define AQ_PIXEL_SHADER_END_PC_ADDRESS_End                                    11
#define AQ_PIXEL_SHADER_END_PC_ADDRESS_Start                                   0
#define AQ_PIXEL_SHADER_END_PC_ADDRESS_Type                                  U12

#define AQPixelShaderInstRegAddrs                                         0x1800
#define AQ_PIXEL_SHADER_INST_Address                                     0x06000
#define AQ_PIXEL_SHADER_INST_MSB                                              15
#define AQ_PIXEL_SHADER_INST_LSB                                              10
#define AQ_PIXEL_SHADER_INST_BLK                                              10
#define AQ_PIXEL_SHADER_INST_Count                                          1024
#define AQ_PIXEL_SHADER_INST_FieldMask                                0xFFFFFFFF
#define AQ_PIXEL_SHADER_INST_ReadMask                                 0xFFFFFFFF
#define AQ_PIXEL_SHADER_INST_WriteMask                                0xFFFFFFFF
#define AQ_PIXEL_SHADER_INST_ResetValue                               0x00000000

#define AQ_PIXEL_SHADER_INST_INSTRUCTION                                    31:0
#define AQ_PIXEL_SHADER_INST_INSTRUCTION_End                                  31
#define AQ_PIXEL_SHADER_INST_INSTRUCTION_Start                                 0
#define AQ_PIXEL_SHADER_INST_INSTRUCTION_Type                                U32




#define AQPixelShaderColorOutRegAddrs                                     0x0401
#define AQ_PIXEL_SHADER_COLOR_OUT_Address                                0x01004
#define AQ_PIXEL_SHADER_COLOR_OUT_MSB                                         15
#define AQ_PIXEL_SHADER_COLOR_OUT_LSB                                          0
#define AQ_PIXEL_SHADER_COLOR_OUT_BLK                                          0
#define AQ_PIXEL_SHADER_COLOR_OUT_Count                                        1
#define AQ_PIXEL_SHADER_COLOR_OUT_FieldMask                           0x3F3F3F3F
#define AQ_PIXEL_SHADER_COLOR_OUT_ReadMask                            0x3F3F3F3F
#define AQ_PIXEL_SHADER_COLOR_OUT_WriteMask                           0x3F3F3F3F
#define AQ_PIXEL_SHADER_COLOR_OUT_ResetValue                          0x00000000

#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS                                    5:0
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS_End                                  5
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS_Start                                0
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS_Type                               U06

#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS1                                  13:8
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS1_End                                13
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS1_Start                               8
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS1_Type                              U06

#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS2                                 21:16
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS2_End                                21
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS2_Start                              16
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS2_Type                              U06

#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS3                                 29:24
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS3_End                                29
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS3_Start                              24
#define AQ_PIXEL_SHADER_COLOR_OUT_ADDRESS3_Type                              U06

#define AQPixelShaderInputControlRegAddrs                                 0x0402
#define AQ_PIXEL_SHADER_INPUT_CONTROL_Address                            0x01008
#define AQ_PIXEL_SHADER_INPUT_CONTROL_MSB                                     15
#define AQ_PIXEL_SHADER_INPUT_CONTROL_LSB                                      0
#define AQ_PIXEL_SHADER_INPUT_CONTROL_BLK                                      0
#define AQ_PIXEL_SHADER_INPUT_CONTROL_Count                                    1
#define AQ_PIXEL_SHADER_INPUT_CONTROL_FieldMask                       0xFF9F1F3F
#define AQ_PIXEL_SHADER_INPUT_CONTROL_ReadMask                        0xFF9F1F3F
#define AQ_PIXEL_SHADER_INPUT_CONTROL_WriteMask                       0xFF9F1F3F
#define AQ_PIXEL_SHADER_INPUT_CONTROL_ResetValue                      0x00000000

#define AQ_PIXEL_SHADER_INPUT_CONTROL_COUNT                                  5:0
#define AQ_PIXEL_SHADER_INPUT_CONTROL_COUNT_End                                5
#define AQ_PIXEL_SHADER_INPUT_CONTROL_COUNT_Start                              0
#define AQ_PIXEL_SHADER_INPUT_CONTROL_COUNT_Type                             U06

#define AQ_PIXEL_SHADER_INPUT_CONTROL_TIMEOUT                               12:8
#define AQ_PIXEL_SHADER_INPUT_CONTROL_TIMEOUT_End                             12
#define AQ_PIXEL_SHADER_INPUT_CONTROL_TIMEOUT_Start                            8
#define AQ_PIXEL_SHADER_INPUT_CONTROL_TIMEOUT_Type                           U05

#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_VARYINGS_COUNT                 20:16
#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_VARYINGS_COUNT_End                20
#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_VARYINGS_COUNT_Start              16
#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_VARYINGS_COUNT_Type              U05

#define AQ_PIXEL_SHADER_INPUT_CONTROL_POS_HPVECFMT                         23:23
#define AQ_PIXEL_SHADER_INPUT_CONTROL_POS_HPVECFMT_End                        23
#define AQ_PIXEL_SHADER_INPUT_CONTROL_POS_HPVECFMT_Start                      23
#define AQ_PIXEL_SHADER_INPUT_CONTROL_POS_HPVECFMT_Type                      U01
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_POS_HPVECFMT_HPV4                    0x0
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_POS_HPVECFMT_HPV2                    0x1

#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_POSITION                       24:24
#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_POSITION_End                      24
#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_POSITION_Start                    24
#define AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_POSITION_Type                    U01
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_POSITION_ENABLE                0x1
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_HIGHP_POSITION_DISABLE               0x0


#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL                    25:25
#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_End                   25
#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_Start                 25
#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_Type                 U01
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_ENABLE             0x1
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_DISABLE            0x0

#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_COUNT              30:26
#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_COUNT_End             30
#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_COUNT_Start           26
#define AQ_PIXEL_SHADER_INPUT_CONTROL_PIXEL_INPUT_STALL_COUNT_Type           U05

#define AQ_PIXEL_SHADER_INPUT_CONTROL_SUBSAMPLE_HPVECFMT                   31:31
#define AQ_PIXEL_SHADER_INPUT_CONTROL_SUBSAMPLE_HPVECFMT_End                  31
#define AQ_PIXEL_SHADER_INPUT_CONTROL_SUBSAMPLE_HPVECFMT_Start                31
#define AQ_PIXEL_SHADER_INPUT_CONTROL_SUBSAMPLE_HPVECFMT_Type                U01
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_SUBSAMPLE_HPVECFMT_HPV4              0x0
#define   AQ_PIXEL_SHADER_INPUT_CONTROL_SUBSAMPLE_HPVECFMT_HPV2              0x1

#define AQPixelShaderTemporaryRegisterControlRegAddrs                     0x0403
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_Address               0x0100C
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_MSB                        15
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_LSB                         0
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_BLK                         0
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_Count                       1
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_FieldMask          0x0000007F
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_ReadMask           0x0000007F
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_WriteMask          0x0000007F
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_ResetValue         0x00000000

#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT                     6:0
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT_End                   6
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT_Start                 0
#define AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL_COUNT_Type                U07

#define AQPixelShaderControlRegAddrs                                      0x0404
#define AQ_PIXEL_SHADER_CONTROL_Address                                  0x01010
#define AQ_PIXEL_SHADER_CONTROL_MSB                                           15
#define AQ_PIXEL_SHADER_CONTROL_LSB                                            0
#define AQ_PIXEL_SHADER_CONTROL_BLK                                            0
#define AQ_PIXEL_SHADER_CONTROL_Count                                          1
#define AQ_PIXEL_SHADER_CONTROL_FieldMask                             0x003F1F1F
#define AQ_PIXEL_SHADER_CONTROL_ReadMask                              0x003F1F1F
#define AQ_PIXEL_SHADER_CONTROL_WriteMask                             0x003F1F1F
#define AQ_PIXEL_SHADER_CONTROL_ResetValue                            0x00000000

#define AQ_PIXEL_SHADER_CONTROL_BYPASS_SHADING                               0:0
#define AQ_PIXEL_SHADER_CONTROL_BYPASS_SHADING_End                             0
#define AQ_PIXEL_SHADER_CONTROL_BYPASS_SHADING_Start                           0
#define AQ_PIXEL_SHADER_CONTROL_BYPASS_SHADING_Type                          U01
#define   AQ_PIXEL_SHADER_CONTROL_BYPASS_SHADING_DISABLE                     0x0
#define   AQ_PIXEL_SHADER_CONTROL_BYPASS_SHADING_ENABLE                      0x1

#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE                           1:1
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE_End                         1
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE_Start                       1
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE_Type                      U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE_DISABLE                 0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE_ENABLE                  0x1

#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE1                          2:2
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE1_End                        2
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE1_Start                      2
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE1_Type                     U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE1_DISABLE                0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE1_ENABLE                 0x1

#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE2                          3:3
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE2_End                        3
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE2_Start                      3
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE2_Type                     U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE2_DISABLE                0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE2_ENABLE                 0x1

#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE3                          4:4
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE3_End                        4
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE3_Start                      4
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE3_Type                     U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE3_DISABLE                0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_SATURATE3_ENABLE                 0x1

#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_COUNT                             11:8
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_COUNT_End                           11
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_COUNT_Start                          8
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_COUNT_Type                         U04


#define AQ_PIXEL_SHADER_CONTROL_MSAA_SIDEBAND                              12:12
#define AQ_PIXEL_SHADER_CONTROL_MSAA_SIDEBAND_End                             12
#define AQ_PIXEL_SHADER_CONTROL_MSAA_SIDEBAND_Start                           12
#define AQ_PIXEL_SHADER_CONTROL_MSAA_SIDEBAND_Type                           U01
#define   AQ_PIXEL_SHADER_CONTROL_MSAA_SIDEBAND_REGISTERS                    0x0
#define   AQ_PIXEL_SHADER_CONTROL_MSAA_SIDEBAND_SIDEBAND                     0x1


#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA0                           16:16
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA0_End                          16
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA0_Start                        16
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA0_Type                        U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA0_USER                      0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA0_ONE                       0x1


#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA1                           17:17
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA1_End                          17
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA1_Start                        17
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA1_Type                        U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA1_USER                      0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA1_ONE                       0x1


#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA2                           18:18
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA2_End                          18
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA2_Start                        18
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA2_Type                        U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA2_USER                      0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA2_ONE                       0x1


#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA3                           19:19
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA3_End                          19
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA3_Start                        19
#define AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA3_Type                        U01
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA3_USER                      0x0
#define   AQ_PIXEL_SHADER_CONTROL_COLOR_OUT_ALPHA3_ONE                       0x1

#define AQ_PIXEL_SHADER_CONTROL_GL_SAMPLE_MASK_ENABLE                      20:20
#define AQ_PIXEL_SHADER_CONTROL_GL_SAMPLE_MASK_ENABLE_End                     20
#define AQ_PIXEL_SHADER_CONTROL_GL_SAMPLE_MASK_ENABLE_Start                   20
#define AQ_PIXEL_SHADER_CONTROL_GL_SAMPLE_MASK_ENABLE_Type                   U01
#define   AQ_PIXEL_SHADER_CONTROL_GL_SAMPLE_MASK_ENABLE_DISABLED             0x0
#define   AQ_PIXEL_SHADER_CONTROL_GL_SAMPLE_MASK_ENABLE_ENABLED              0x1

#define AQ_PIXEL_SHADER_CONTROL_PS_GROUP_END_CONTROL                       21:21
#define AQ_PIXEL_SHADER_CONTROL_PS_GROUP_END_CONTROL_End                      21
#define AQ_PIXEL_SHADER_CONTROL_PS_GROUP_END_CONTROL_Start                    21
#define AQ_PIXEL_SHADER_CONTROL_PS_GROUP_END_CONTROL_Type                    U01
#define   AQ_PIXEL_SHADER_CONTROL_PS_GROUP_END_CONTROL_WAIT_IDLE             0x0
#define   AQ_PIXEL_SHADER_CONTROL_PS_GROUP_END_CONTROL_RASTER_LAST           0x1

#define AQPixelShaderPerformanceCounterRegAddrs                           0x0405
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_Address                      0x01014
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_MSB                               15
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_LSB                                0
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_BLK                                0
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_Count                              1
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_FieldMask                 0xFFFFFFFF
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_ReadMask                  0xFFFFFFFF
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_WriteMask                 0xFFFFFFFF
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_ResetValue                0x00000000


#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL0                             7:0
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL0_End                           7
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL0_Start                         0
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL0_Type                        U08


#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL1                            15:8
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL1_End                          15
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL1_Start                         8
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL1_Type                        U08


#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL2                           23:16
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL2_End                          23
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL2_Start                        16
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL2_Type                        U08


#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL3                           31:24
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL3_End                          31
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL3_Start                        24
#define AQ_PIXEL_SHADER_PERFORMANCE_COUNTER_SEL3_Type                        U08



#define AQPixelShaderConstRegAddrs                                        0x1C00
#define AQ_PIXEL_SHADER_CONST_Address                                    0x07000
#define AQ_PIXEL_SHADER_CONST_MSB                                             15
#define AQ_PIXEL_SHADER_CONST_LSB                                             10
#define AQ_PIXEL_SHADER_CONST_BLK                                             10
#define AQ_PIXEL_SHADER_CONST_Count                                         1024
#define AQ_PIXEL_SHADER_CONST_FieldMask                               0xFFFFFFFF
#define AQ_PIXEL_SHADER_CONST_ReadMask                                0xFFFFFFFF
#define AQ_PIXEL_SHADER_CONST_WriteMask                               0xFFFFFFFF
#define AQ_PIXEL_SHADER_CONST_ResetValue                              0x00000000

#define AQ_PIXEL_SHADER_CONST_VALUE                                         31:0
#define AQ_PIXEL_SHADER_CONST_VALUE_End                                       31
#define AQ_PIXEL_SHADER_CONST_VALUE_Start                                      0
#define AQ_PIXEL_SHADER_CONST_VALUE_Type                                     U32

#define AQPixelShaderStartPCRegAddrs                                      0x0406
#define AQ_PIXEL_SHADER_START_PC_Address                                 0x01018
#define AQ_PIXEL_SHADER_START_PC_MSB                                          15
#define AQ_PIXEL_SHADER_START_PC_LSB                                           0
#define AQ_PIXEL_SHADER_START_PC_BLK                                           0
#define AQ_PIXEL_SHADER_START_PC_Count                                         1
#define AQ_PIXEL_SHADER_START_PC_FieldMask                            0x03FF0FFF
#define AQ_PIXEL_SHADER_START_PC_ReadMask                             0x03FF0FFF
#define AQ_PIXEL_SHADER_START_PC_WriteMask                            0x03FF0FFF
#define AQ_PIXEL_SHADER_START_PC_ResetValue                           0x01000000

#define AQ_PIXEL_SHADER_START_PC_PC_OFFSET                                  11:0
#define AQ_PIXEL_SHADER_START_PC_PC_OFFSET_End                                11
#define AQ_PIXEL_SHADER_START_PC_PC_OFFSET_Start                               0
#define AQ_PIXEL_SHADER_START_PC_PC_OFFSET_Type                              U12

#define AQ_PIXEL_SHADER_START_PC_CONST_OFFSET                              25:16
#define AQ_PIXEL_SHADER_START_PC_CONST_OFFSET_End                             25
#define AQ_PIXEL_SHADER_START_PC_CONST_OFFSET_Start                           16
#define AQ_PIXEL_SHADER_START_PC_CONST_OFFSET_Type                           U10




#define mwv207regPSShaderCodeRegAddrs                                     0x2000
#define MWV207REG_PS_SHADER_CODE_Address                                 0x08000
#define MWV207REG_PS_SHADER_CODE_MSB                                          15
#define MWV207REG_PS_SHADER_CODE_LSB                                          12
#define MWV207REG_PS_SHADER_CODE_BLK                                          12
#define MWV207REG_PS_SHADER_CODE_Count                                      4096
#define MWV207REG_PS_SHADER_CODE_FieldMask                            0xFFFFFFFF
#define MWV207REG_PS_SHADER_CODE_ReadMask                             0xFFFFFFFF
#define MWV207REG_PS_SHADER_CODE_WriteMask                            0xFFFFFFFF
#define MWV207REG_PS_SHADER_CODE_ResetValue                           0x00000000

#define MWV207REG_PS_SHADER_CODE_INSTRUCTION                                31:0
#define MWV207REG_PS_SHADER_CODE_INSTRUCTION_End                              31
#define MWV207REG_PS_SHADER_CODE_INSTRUCTION_Start                             0
#define MWV207REG_PS_SHADER_CODE_INSTRUCTION_Type                            U32



#define mwv207regPSProgramRegAddrs                                        0x0407
#define MWV207REG_PS_PROGRAM_Address                                     0x0101C
#define MWV207REG_PS_PROGRAM_MSB                                              15
#define MWV207REG_PS_PROGRAM_LSB                                               0
#define MWV207REG_PS_PROGRAM_BLK                                               0
#define MWV207REG_PS_PROGRAM_Count                                             1
#define MWV207REG_PS_PROGRAM_FieldMask                                0xFFFFFFFF
#define MWV207REG_PS_PROGRAM_ReadMask                                 0xFFFFFFFF
#define MWV207REG_PS_PROGRAM_WriteMask                                0xFFFFFFFF
#define MWV207REG_PS_PROGRAM_ResetValue                               0x00000100


#define MWV207REG_PS_PROGRAM_START                                          15:0
#define MWV207REG_PS_PROGRAM_START_End                                        15
#define MWV207REG_PS_PROGRAM_START_Start                                       0
#define MWV207REG_PS_PROGRAM_START_Type                                      U16


#define MWV207REG_PS_PROGRAM_END                                           31:16
#define MWV207REG_PS_PROGRAM_END_End                                          31
#define MWV207REG_PS_PROGRAM_END_Start                                        16
#define MWV207REG_PS_PROGRAM_END_Type                                        U16




#define mwv207regSHUniformsRegAddrs                                       0xC000
#define MWV207REG_SH_UNIFORMS_Address                                    0x30000
#define MWV207REG_SH_UNIFORMS_MSB                                             15
#define MWV207REG_SH_UNIFORMS_LSB                                             12
#define MWV207REG_SH_UNIFORMS_BLK                                             12
#define MWV207REG_SH_UNIFORMS_Count                                         2304
#define MWV207REG_SH_UNIFORMS_FieldMask                               0xFFFFFFFF
#define MWV207REG_SH_UNIFORMS_ReadMask                                0xFFFFFFFF
#define MWV207REG_SH_UNIFORMS_WriteMask                               0xFFFFFFFF
#define MWV207REG_SH_UNIFORMS_ResetValue                              0x00000000

#define MWV207REG_SH_UNIFORMS_VALUE                                         31:0
#define MWV207REG_SH_UNIFORMS_VALUE_End                                       31
#define MWV207REG_SH_UNIFORMS_VALUE_Start                                      0
#define MWV207REG_SH_UNIFORMS_VALUE_Type                                     U32




#define mwv207regGpipeUniformsRegAddrs                                    0xD000
#define MWV207REG_GPIPE_UNIFORMS_Address                                 0x34000
#define MWV207REG_GPIPE_UNIFORMS_MSB                                          15
#define MWV207REG_GPIPE_UNIFORMS_LSB                                          11
#define MWV207REG_GPIPE_UNIFORMS_BLK                                          11
#define MWV207REG_GPIPE_UNIFORMS_Count                                      2048
#define MWV207REG_GPIPE_UNIFORMS_FieldMask                            0xFFFFFFFF
#define MWV207REG_GPIPE_UNIFORMS_ReadMask                             0xFFFFFFFF
#define MWV207REG_GPIPE_UNIFORMS_WriteMask                            0xFFFFFFFF
#define MWV207REG_GPIPE_UNIFORMS_ResetValue                           0x00000000

#define MWV207REG_GPIPE_UNIFORMS_VALUE                                      31:0
#define MWV207REG_GPIPE_UNIFORMS_VALUE_End                                    31
#define MWV207REG_GPIPE_UNIFORMS_VALUE_Start                                   0
#define MWV207REG_GPIPE_UNIFORMS_VALUE_Type                                  U32




#define mwv207regPixelUniformsRegAddrs                                    0xD800
#define MWV207REG_PIXEL_UNIFORMS_Address                                 0x36000
#define MWV207REG_PIXEL_UNIFORMS_MSB                                          15
#define MWV207REG_PIXEL_UNIFORMS_LSB                                          11
#define MWV207REG_PIXEL_UNIFORMS_BLK                                          11
#define MWV207REG_PIXEL_UNIFORMS_Count                                      2048
#define MWV207REG_PIXEL_UNIFORMS_FieldMask                            0xFFFFFFFF
#define MWV207REG_PIXEL_UNIFORMS_ReadMask                             0xFFFFFFFF
#define MWV207REG_PIXEL_UNIFORMS_WriteMask                            0xFFFFFFFF
#define MWV207REG_PIXEL_UNIFORMS_ResetValue                           0x00000000

#define MWV207REG_PIXEL_UNIFORMS_VALUE                                      31:0
#define MWV207REG_PIXEL_UNIFORMS_VALUE_End                                    31
#define MWV207REG_PIXEL_UNIFORMS_VALUE_Start                                   0
#define MWV207REG_PIXEL_UNIFORMS_VALUE_Type                                  U32




#define mwv207regSHInstructionsRegAddrs                                   0x8000
#define MWV207REG_SH_INSTRUCTIONS_Address                                0x20000
#define MWV207REG_SH_INSTRUCTIONS_MSB                                         15
#define MWV207REG_SH_INSTRUCTIONS_LSB                                         13
#define MWV207REG_SH_INSTRUCTIONS_BLK                                         13
#define MWV207REG_SH_INSTRUCTIONS_Count                                     8192
#define MWV207REG_SH_INSTRUCTIONS_FieldMask                           0xFFFFFFFF
#define MWV207REG_SH_INSTRUCTIONS_ReadMask                            0xFFFFFFFF
#define MWV207REG_SH_INSTRUCTIONS_WriteMask                           0xFFFFFFFF
#define MWV207REG_SH_INSTRUCTIONS_ResetValue                          0x00000000

#define MWV207REG_SH_INSTRUCTIONS_INSTRUCTION                               31:0
#define MWV207REG_SH_INSTRUCTIONS_INSTRUCTION_End                             31
#define MWV207REG_SH_INSTRUCTIONS_INSTRUCTION_Start                            0
#define MWV207REG_SH_INSTRUCTIONS_INSTRUCTION_Type                           U32

#define mwv207regOCLFeatureControlRegAddrs                                0x0408
#define MWV207REG_OCL_FEATURE_CONTROL_Address                            0x01020
#define MWV207REG_OCL_FEATURE_CONTROL_MSB                                     15
#define MWV207REG_OCL_FEATURE_CONTROL_LSB                                      0
#define MWV207REG_OCL_FEATURE_CONTROL_BLK                                      0
#define MWV207REG_OCL_FEATURE_CONTROL_Count                                    1
#define MWV207REG_OCL_FEATURE_CONTROL_FieldMask                       0x00000001
#define MWV207REG_OCL_FEATURE_CONTROL_ReadMask                        0x00000001
#define MWV207REG_OCL_FEATURE_CONTROL_WriteMask                       0x00000001
#define MWV207REG_OCL_FEATURE_CONTROL_ResetValue                      0x00000001


#define MWV207REG_OCL_FEATURE_CONTROL_ENABLE_LS_BROADCAST                    0:0
#define MWV207REG_OCL_FEATURE_CONTROL_ENABLE_LS_BROADCAST_End                  0
#define MWV207REG_OCL_FEATURE_CONTROL_ENABLE_LS_BROADCAST_Start                0
#define MWV207REG_OCL_FEATURE_CONTROL_ENABLE_LS_BROADCAST_Type               U01
#define   MWV207REG_OCL_FEATURE_CONTROL_ENABLE_LS_BROADCAST_DISABLE          0x0
#define   MWV207REG_OCL_FEATURE_CONTROL_ENABLE_LS_BROADCAST_ENABLE           0x1

#define mwv207regPixelShaderConstRegAddrs                                 0x0409
#define MWV207REG_PIXEL_SHADER_CONST_Address                             0x01024
#define MWV207REG_PIXEL_SHADER_CONST_MSB                                      15
#define MWV207REG_PIXEL_SHADER_CONST_LSB                                       0
#define MWV207REG_PIXEL_SHADER_CONST_BLK                                       0
#define MWV207REG_PIXEL_SHADER_CONST_Count                                     1
#define MWV207REG_PIXEL_SHADER_CONST_FieldMask                        0x000003FF
#define MWV207REG_PIXEL_SHADER_CONST_ReadMask                         0x000003FF
#define MWV207REG_PIXEL_SHADER_CONST_WriteMask                        0x000003FF
#define MWV207REG_PIXEL_SHADER_CONST_ResetValue                       0x00000100

#define MWV207REG_PIXEL_SHADER_CONST_BASE_OFFSET                             9:0
#define MWV207REG_PIXEL_SHADER_CONST_BASE_OFFSET_End                           9
#define MWV207REG_PIXEL_SHADER_CONST_BASE_OFFSET_Start                         0
#define MWV207REG_PIXEL_SHADER_CONST_BASE_OFFSET_Type                        U10



#define mwv207regPSInstructionRegAddrs                                    0x040A
#define MWV207REG_PS_INSTRUCTION_Address                                 0x01028
#define MWV207REG_PS_INSTRUCTION_MSB                                          15
#define MWV207REG_PS_INSTRUCTION_LSB                                           0
#define MWV207REG_PS_INSTRUCTION_BLK                                           0
#define MWV207REG_PS_INSTRUCTION_Count                                         1
#define MWV207REG_PS_INSTRUCTION_FieldMask                            0xFFFFFFFF
#define MWV207REG_PS_INSTRUCTION_ReadMask                             0xFFFFFF00
#define MWV207REG_PS_INSTRUCTION_WriteMask                            0xFFFFFF00
#define MWV207REG_PS_INSTRUCTION_ResetValue                           0x00000000


#define MWV207REG_PS_INSTRUCTION_ADDRESS                                    31:0
#define MWV207REG_PS_INSTRUCTION_ADDRESS_End                                  31
#define MWV207REG_PS_INSTRUCTION_ADDRESS_Start                                 0
#define MWV207REG_PS_INSTRUCTION_ADDRESS_Type                                U32




#define mwv207regPSOutputControlRegAddrs                                  0x040B
#define MWV207REG_PS_OUTPUT_CONTROL_Address                              0x0102C
#define MWV207REG_PS_OUTPUT_CONTROL_MSB                                       15
#define MWV207REG_PS_OUTPUT_CONTROL_LSB                                        0
#define MWV207REG_PS_OUTPUT_CONTROL_BLK                                        0
#define MWV207REG_PS_OUTPUT_CONTROL_Count                                      1
#define MWV207REG_PS_OUTPUT_CONTROL_FieldMask                         0xFFFFFFFF
#define MWV207REG_PS_OUTPUT_CONTROL_ReadMask                          0xFFFFFFFF
#define MWV207REG_PS_OUTPUT_CONTROL_WriteMask                         0xFFFFFFFF
#define MWV207REG_PS_OUTPUT_CONTROL_ResetValue                        0x00000000

#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT4                                  5:0
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT4_End                                5
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT4_Start                              0
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT4_Type                             U06


#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA4                                   6:6
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA4_End                                 6
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA4_Start                               6
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA4_Type                              U01
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA4_USER                            0x0
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA4_ONE                             0x1


#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE4                                7:7
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE4_End                              7
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE4_Start                            7
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE4_Type                           U01

#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT5                                 13:8
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT5_End                               13
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT5_Start                              8
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT5_Type                             U06


#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA5                                 14:14
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA5_End                                14
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA5_Start                              14
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA5_Type                              U01
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA5_USER                            0x0
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA5_ONE                             0x1


#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE5                              15:15
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE5_End                             15
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE5_Start                           15
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE5_Type                           U01

#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT6                                21:16
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT6_End                               21
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT6_Start                             16
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT6_Type                             U06


#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA6                                 22:22
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA6_End                                22
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA6_Start                              22
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA6_Type                              U01
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA6_USER                            0x0
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA6_ONE                             0x1


#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE6                              23:23
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE6_End                             23
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE6_Start                           23
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE6_Type                           U01

#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT7                                29:24
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT7_End                               29
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT7_Start                             24
#define MWV207REG_PS_OUTPUT_CONTROL_OUTPUT7_Type                             U06


#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA7                                 30:30
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA7_End                                30
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA7_Start                              30
#define MWV207REG_PS_OUTPUT_CONTROL_ALPHA7_Type                              U01
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA7_USER                            0x0
#define   MWV207REG_PS_OUTPUT_CONTROL_ALPHA7_ONE                             0x1


#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE7                              31:31
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE7_End                             31
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE7_Start                           31
#define MWV207REG_PS_OUTPUT_CONTROL_SATURATE7_Type                           U01




#define mwv207regPSOutputModeRegAddrs                                     0x040C
#define MWV207REG_PS_OUTPUT_MODE_Address                                 0x01030
#define MWV207REG_PS_OUTPUT_MODE_MSB                                          15
#define MWV207REG_PS_OUTPUT_MODE_LSB                                           0
#define MWV207REG_PS_OUTPUT_MODE_BLK                                           0
#define MWV207REG_PS_OUTPUT_MODE_Count                                         1
#define MWV207REG_PS_OUTPUT_MODE_FieldMask                            0xFFFFFFFF
#define MWV207REG_PS_OUTPUT_MODE_ReadMask                             0xFFFFFFFF
#define MWV207REG_PS_OUTPUT_MODE_WriteMask                            0xFFFFFFFF
#define MWV207REG_PS_OUTPUT_MODE_ResetValue                           0x00000000


#define MWV207REG_PS_OUTPUT_MODE_CONTROL0                                    3:0
#define MWV207REG_PS_OUTPUT_MODE_CONTROL0_End                                  3
#define MWV207REG_PS_OUTPUT_MODE_CONTROL0_Start                                0
#define MWV207REG_PS_OUTPUT_MODE_CONTROL0_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL0_SIGNED32                         0x9


#define MWV207REG_PS_OUTPUT_MODE_CONTROL1                                    7:4
#define MWV207REG_PS_OUTPUT_MODE_CONTROL1_End                                  7
#define MWV207REG_PS_OUTPUT_MODE_CONTROL1_Start                                4
#define MWV207REG_PS_OUTPUT_MODE_CONTROL1_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL1_SIGNED32                         0x9


#define MWV207REG_PS_OUTPUT_MODE_CONTROL2                                   11:8
#define MWV207REG_PS_OUTPUT_MODE_CONTROL2_End                                 11
#define MWV207REG_PS_OUTPUT_MODE_CONTROL2_Start                                8
#define MWV207REG_PS_OUTPUT_MODE_CONTROL2_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL2_SIGNED32                         0x9


#define MWV207REG_PS_OUTPUT_MODE_CONTROL3                                  15:12
#define MWV207REG_PS_OUTPUT_MODE_CONTROL3_End                                 15
#define MWV207REG_PS_OUTPUT_MODE_CONTROL3_Start                               12
#define MWV207REG_PS_OUTPUT_MODE_CONTROL3_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL3_SIGNED32                         0x9


#define MWV207REG_PS_OUTPUT_MODE_CONTROL4                                  19:16
#define MWV207REG_PS_OUTPUT_MODE_CONTROL4_End                                 19
#define MWV207REG_PS_OUTPUT_MODE_CONTROL4_Start                               16
#define MWV207REG_PS_OUTPUT_MODE_CONTROL4_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL4_SIGNED32                         0x9


#define MWV207REG_PS_OUTPUT_MODE_CONTROL5                                  23:20
#define MWV207REG_PS_OUTPUT_MODE_CONTROL5_End                                 23
#define MWV207REG_PS_OUTPUT_MODE_CONTROL5_Start                               20
#define MWV207REG_PS_OUTPUT_MODE_CONTROL5_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL5_SIGNED32                         0x9


#define MWV207REG_PS_OUTPUT_MODE_CONTROL6                                  27:24
#define MWV207REG_PS_OUTPUT_MODE_CONTROL6_End                                 27
#define MWV207REG_PS_OUTPUT_MODE_CONTROL6_Start                               24
#define MWV207REG_PS_OUTPUT_MODE_CONTROL6_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL6_SIGNED32                         0x9


#define MWV207REG_PS_OUTPUT_MODE_CONTROL7                                  31:28
#define MWV207REG_PS_OUTPUT_MODE_CONTROL7_End                                 31
#define MWV207REG_PS_OUTPUT_MODE_CONTROL7_Start                               28
#define MWV207REG_PS_OUTPUT_MODE_CONTROL7_Type                               U04
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_FLOAT                            0x0
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_INTEGER16                        0x1
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_INTEGER32                        0x2
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_UNSIGNED8                        0x3
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_UNSIGNED16                       0x4
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_SIGNED8                          0x5
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_SIGNED16                         0x6
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_FLOAT32                          0x7
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_UNSIGNED32                       0x8
#define   MWV207REG_PS_OUTPUT_MODE_CONTROL7_SIGNED32                         0x9



#define mwv207regPSOutputPrecisionRegAddrs                                0x040D
#define MWV207REG_PS_OUTPUT_PRECISION_Address                            0x01034
#define MWV207REG_PS_OUTPUT_PRECISION_MSB                                     15
#define MWV207REG_PS_OUTPUT_PRECISION_LSB                                      0
#define MWV207REG_PS_OUTPUT_PRECISION_BLK                                      0
#define MWV207REG_PS_OUTPUT_PRECISION_Count                                    1
#define MWV207REG_PS_OUTPUT_PRECISION_FieldMask                       0x7F7F7F7F
#define MWV207REG_PS_OUTPUT_PRECISION_ReadMask                        0x7F7F7F7F
#define MWV207REG_PS_OUTPUT_PRECISION_WriteMask                       0x7F7F7F7F
#define MWV207REG_PS_OUTPUT_PRECISION_ResetValue                      0x00000000

#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT0                       5:0
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT0_End                     5
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT0_Start                   0
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT0_Type                  U06


#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP0                                 6:6
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP0_End                               6
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP0_Start                             6
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP0_Type                            U01
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP0_DISABLE                       0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP0_ENABLE                        0x1

#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT1                      13:8
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT1_End                    13
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT1_Start                   8
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT1_Type                  U06


#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP1                               14:14
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP1_End                              14
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP1_Start                            14
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP1_Type                            U01
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP1_DISABLE                       0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP1_ENABLE                        0x1

#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT2                     21:16
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT2_End                    21
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT2_Start                  16
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT2_Type                  U06


#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP2                               22:22
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP2_End                              22
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP2_Start                            22
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP2_Type                            U01
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP2_DISABLE                       0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP2_ENABLE                        0x1

#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT3                     29:24
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT3_End                    29
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT3_Start                  24
#define MWV207REG_PS_OUTPUT_PRECISION_T1_HIGHP_OUTPUT3_Type                  U06


#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP3                               30:30
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP3_End                              30
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP3_Start                            30
#define MWV207REG_PS_OUTPUT_PRECISION_HIGHP3_Type                            U01
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP3_DISABLE                       0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_HIGHP3_ENABLE                        0x1



#define mwv207regPSOutputPrecisionExRegAddrs                              0x040E
#define MWV207REG_PS_OUTPUT_PRECISION_EX_Address                         0x01038
#define MWV207REG_PS_OUTPUT_PRECISION_EX_MSB                                  15
#define MWV207REG_PS_OUTPUT_PRECISION_EX_LSB                                   0
#define MWV207REG_PS_OUTPUT_PRECISION_EX_BLK                                   0
#define MWV207REG_PS_OUTPUT_PRECISION_EX_Count                                 1
#define MWV207REG_PS_OUTPUT_PRECISION_EX_FieldMask                    0x7F7F7F7F
#define MWV207REG_PS_OUTPUT_PRECISION_EX_ReadMask                     0x7F7F7F7F
#define MWV207REG_PS_OUTPUT_PRECISION_EX_WriteMask                    0x7F7F7F7F
#define MWV207REG_PS_OUTPUT_PRECISION_EX_ResetValue                   0x00000000

#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT4                    5:0
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT4_End                  5
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT4_Start                0
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT4_Type               U06


#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP4                              6:6
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP4_End                            6
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP4_Start                          6
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP4_Type                         U01
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP4_DISABLE                    0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP4_ENABLE                     0x1

#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT5                   13:8
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT5_End                 13
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT5_Start                8
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT5_Type               U06


#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP5                            14:14
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP5_End                           14
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP5_Start                         14
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP5_Type                         U01
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP5_DISABLE                    0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP5_ENABLE                     0x1

#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT6                  21:16
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT6_End                 21
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT6_Start               16
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT6_Type               U06


#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP6                            22:22
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP6_End                           22
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP6_Start                         22
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP6_Type                         U01
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP6_DISABLE                    0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP6_ENABLE                     0x1

#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT7                  29:24
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT7_End                 29
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT7_Start               24
#define MWV207REG_PS_OUTPUT_PRECISION_EX_T1_HIGHP_OUTPUT7_Type               U06


#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP7                            30:30
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP7_End                           30
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP7_Start                         30
#define MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP7_Type                         U01
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP7_DISABLE                    0x0
#define   MWV207REG_PS_OUTPUT_PRECISION_EX_HIGHP7_ENABLE                     0x1



#define mwv207regPSInputTypeRegAddrs                                      0x0410
#define MWV207REG_PS_INPUT_TYPE_Address                                  0x01040
#define MWV207REG_PS_INPUT_TYPE_MSB                                           15
#define MWV207REG_PS_INPUT_TYPE_LSB                                            1
#define MWV207REG_PS_INPUT_TYPE_BLK                                            1
#define MWV207REG_PS_INPUT_TYPE_Count                                          2
#define MWV207REG_PS_INPUT_TYPE_FieldMask                             0xFFFFFFFF
#define MWV207REG_PS_INPUT_TYPE_ReadMask                              0xFFFFFFFF
#define MWV207REG_PS_INPUT_TYPE_WriteMask                             0xFFFFFFFF
#define MWV207REG_PS_INPUT_TYPE_ResetValue                            0x00000000


#define MWV207REG_PS_INPUT_TYPE_VARYING0X                                    0:0
#define MWV207REG_PS_INPUT_TYPE_VARYING0X_End                                  0
#define MWV207REG_PS_INPUT_TYPE_VARYING0X_Start                                0
#define MWV207REG_PS_INPUT_TYPE_VARYING0X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING0X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING0X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING0Y                                    1:1
#define MWV207REG_PS_INPUT_TYPE_VARYING0Y_End                                  1
#define MWV207REG_PS_INPUT_TYPE_VARYING0Y_Start                                1
#define MWV207REG_PS_INPUT_TYPE_VARYING0Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING0Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING0Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING0Z                                    2:2
#define MWV207REG_PS_INPUT_TYPE_VARYING0Z_End                                  2
#define MWV207REG_PS_INPUT_TYPE_VARYING0Z_Start                                2
#define MWV207REG_PS_INPUT_TYPE_VARYING0Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING0Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING0Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING0W                                    3:3
#define MWV207REG_PS_INPUT_TYPE_VARYING0W_End                                  3
#define MWV207REG_PS_INPUT_TYPE_VARYING0W_Start                                3
#define MWV207REG_PS_INPUT_TYPE_VARYING0W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING0W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING0W_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING1X                                    4:4
#define MWV207REG_PS_INPUT_TYPE_VARYING1X_End                                  4
#define MWV207REG_PS_INPUT_TYPE_VARYING1X_Start                                4
#define MWV207REG_PS_INPUT_TYPE_VARYING1X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING1X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING1X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING1Y                                    5:5
#define MWV207REG_PS_INPUT_TYPE_VARYING1Y_End                                  5
#define MWV207REG_PS_INPUT_TYPE_VARYING1Y_Start                                5
#define MWV207REG_PS_INPUT_TYPE_VARYING1Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING1Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING1Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING1Z                                    6:6
#define MWV207REG_PS_INPUT_TYPE_VARYING1Z_End                                  6
#define MWV207REG_PS_INPUT_TYPE_VARYING1Z_Start                                6
#define MWV207REG_PS_INPUT_TYPE_VARYING1Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING1Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING1Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING1W                                    7:7
#define MWV207REG_PS_INPUT_TYPE_VARYING1W_End                                  7
#define MWV207REG_PS_INPUT_TYPE_VARYING1W_Start                                7
#define MWV207REG_PS_INPUT_TYPE_VARYING1W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING1W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING1W_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING2X                                    8:8
#define MWV207REG_PS_INPUT_TYPE_VARYING2X_End                                  8
#define MWV207REG_PS_INPUT_TYPE_VARYING2X_Start                                8
#define MWV207REG_PS_INPUT_TYPE_VARYING2X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING2X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING2X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING2Y                                    9:9
#define MWV207REG_PS_INPUT_TYPE_VARYING2Y_End                                  9
#define MWV207REG_PS_INPUT_TYPE_VARYING2Y_Start                                9
#define MWV207REG_PS_INPUT_TYPE_VARYING2Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING2Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING2Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING2Z                                  10:10
#define MWV207REG_PS_INPUT_TYPE_VARYING2Z_End                                 10
#define MWV207REG_PS_INPUT_TYPE_VARYING2Z_Start                               10
#define MWV207REG_PS_INPUT_TYPE_VARYING2Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING2Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING2Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING2W                                  11:11
#define MWV207REG_PS_INPUT_TYPE_VARYING2W_End                                 11
#define MWV207REG_PS_INPUT_TYPE_VARYING2W_Start                               11
#define MWV207REG_PS_INPUT_TYPE_VARYING2W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING2W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING2W_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING3X                                  12:12
#define MWV207REG_PS_INPUT_TYPE_VARYING3X_End                                 12
#define MWV207REG_PS_INPUT_TYPE_VARYING3X_Start                               12
#define MWV207REG_PS_INPUT_TYPE_VARYING3X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING3X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING3X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING3Y                                  13:13
#define MWV207REG_PS_INPUT_TYPE_VARYING3Y_End                                 13
#define MWV207REG_PS_INPUT_TYPE_VARYING3Y_Start                               13
#define MWV207REG_PS_INPUT_TYPE_VARYING3Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING3Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING3Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING3Z                                  14:14
#define MWV207REG_PS_INPUT_TYPE_VARYING3Z_End                                 14
#define MWV207REG_PS_INPUT_TYPE_VARYING3Z_Start                               14
#define MWV207REG_PS_INPUT_TYPE_VARYING3Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING3Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING3Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING3W                                  15:15
#define MWV207REG_PS_INPUT_TYPE_VARYING3W_End                                 15
#define MWV207REG_PS_INPUT_TYPE_VARYING3W_Start                               15
#define MWV207REG_PS_INPUT_TYPE_VARYING3W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING3W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING3W_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING4X                                  16:16
#define MWV207REG_PS_INPUT_TYPE_VARYING4X_End                                 16
#define MWV207REG_PS_INPUT_TYPE_VARYING4X_Start                               16
#define MWV207REG_PS_INPUT_TYPE_VARYING4X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING4X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING4X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING4Y                                  17:17
#define MWV207REG_PS_INPUT_TYPE_VARYING4Y_End                                 17
#define MWV207REG_PS_INPUT_TYPE_VARYING4Y_Start                               17
#define MWV207REG_PS_INPUT_TYPE_VARYING4Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING4Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING4Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING4Z                                  18:18
#define MWV207REG_PS_INPUT_TYPE_VARYING4Z_End                                 18
#define MWV207REG_PS_INPUT_TYPE_VARYING4Z_Start                               18
#define MWV207REG_PS_INPUT_TYPE_VARYING4Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING4Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING4Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING4W                                  19:19
#define MWV207REG_PS_INPUT_TYPE_VARYING4W_End                                 19
#define MWV207REG_PS_INPUT_TYPE_VARYING4W_Start                               19
#define MWV207REG_PS_INPUT_TYPE_VARYING4W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING4W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING4W_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING5X                                  20:20
#define MWV207REG_PS_INPUT_TYPE_VARYING5X_End                                 20
#define MWV207REG_PS_INPUT_TYPE_VARYING5X_Start                               20
#define MWV207REG_PS_INPUT_TYPE_VARYING5X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING5X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING5X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING5Y                                  21:21
#define MWV207REG_PS_INPUT_TYPE_VARYING5Y_End                                 21
#define MWV207REG_PS_INPUT_TYPE_VARYING5Y_Start                               21
#define MWV207REG_PS_INPUT_TYPE_VARYING5Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING5Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING5Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING5Z                                  22:22
#define MWV207REG_PS_INPUT_TYPE_VARYING5Z_End                                 22
#define MWV207REG_PS_INPUT_TYPE_VARYING5Z_Start                               22
#define MWV207REG_PS_INPUT_TYPE_VARYING5Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING5Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING5Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING5W                                  23:23
#define MWV207REG_PS_INPUT_TYPE_VARYING5W_End                                 23
#define MWV207REG_PS_INPUT_TYPE_VARYING5W_Start                               23
#define MWV207REG_PS_INPUT_TYPE_VARYING5W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING5W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING5W_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING6X                                  24:24
#define MWV207REG_PS_INPUT_TYPE_VARYING6X_End                                 24
#define MWV207REG_PS_INPUT_TYPE_VARYING6X_Start                               24
#define MWV207REG_PS_INPUT_TYPE_VARYING6X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING6X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING6X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING6Y                                  25:25
#define MWV207REG_PS_INPUT_TYPE_VARYING6Y_End                                 25
#define MWV207REG_PS_INPUT_TYPE_VARYING6Y_Start                               25
#define MWV207REG_PS_INPUT_TYPE_VARYING6Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING6Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING6Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING6Z                                  26:26
#define MWV207REG_PS_INPUT_TYPE_VARYING6Z_End                                 26
#define MWV207REG_PS_INPUT_TYPE_VARYING6Z_Start                               26
#define MWV207REG_PS_INPUT_TYPE_VARYING6Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING6Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING6Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING6W                                  27:27
#define MWV207REG_PS_INPUT_TYPE_VARYING6W_End                                 27
#define MWV207REG_PS_INPUT_TYPE_VARYING6W_Start                               27
#define MWV207REG_PS_INPUT_TYPE_VARYING6W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING6W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING6W_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING7X                                  28:28
#define MWV207REG_PS_INPUT_TYPE_VARYING7X_End                                 28
#define MWV207REG_PS_INPUT_TYPE_VARYING7X_Start                               28
#define MWV207REG_PS_INPUT_TYPE_VARYING7X_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING7X_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING7X_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING7Y                                  29:29
#define MWV207REG_PS_INPUT_TYPE_VARYING7Y_End                                 29
#define MWV207REG_PS_INPUT_TYPE_VARYING7Y_Start                               29
#define MWV207REG_PS_INPUT_TYPE_VARYING7Y_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING7Y_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING7Y_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING7Z                                  30:30
#define MWV207REG_PS_INPUT_TYPE_VARYING7Z_End                                 30
#define MWV207REG_PS_INPUT_TYPE_VARYING7Z_Start                               30
#define MWV207REG_PS_INPUT_TYPE_VARYING7Z_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING7Z_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING7Z_INTEGER16                        0x1


#define MWV207REG_PS_INPUT_TYPE_VARYING7W                                  31:31
#define MWV207REG_PS_INPUT_TYPE_VARYING7W_End                                 31
#define MWV207REG_PS_INPUT_TYPE_VARYING7W_Start                               31
#define MWV207REG_PS_INPUT_TYPE_VARYING7W_Type                               U01
#define   MWV207REG_PS_INPUT_TYPE_VARYING7W_FLOAT16                          0x0
#define   MWV207REG_PS_INPUT_TYPE_VARYING7W_INTEGER16                        0x1




#define mwv207regPSOutputMapRegAddrs                                      0x040F
#define MWV207REG_PS_OUTPUT_MAP_Address                                  0x0103C
#define MWV207REG_PS_OUTPUT_MAP_MSB                                           15
#define MWV207REG_PS_OUTPUT_MAP_LSB                                            0
#define MWV207REG_PS_OUTPUT_MAP_BLK                                            0
#define MWV207REG_PS_OUTPUT_MAP_Count                                          1
#define MWV207REG_PS_OUTPUT_MAP_FieldMask                             0x77777777
#define MWV207REG_PS_OUTPUT_MAP_ReadMask                              0x77777777
#define MWV207REG_PS_OUTPUT_MAP_WriteMask                             0x77777777
#define MWV207REG_PS_OUTPUT_MAP_ResetValue                            0x76543210


#define MWV207REG_PS_OUTPUT_MAP_TARGET0                                      2:0
#define MWV207REG_PS_OUTPUT_MAP_TARGET0_End                                    2
#define MWV207REG_PS_OUTPUT_MAP_TARGET0_Start                                  0
#define MWV207REG_PS_OUTPUT_MAP_TARGET0_Type                                 U03


#define MWV207REG_PS_OUTPUT_MAP_TARGET1                                      6:4
#define MWV207REG_PS_OUTPUT_MAP_TARGET1_End                                    6
#define MWV207REG_PS_OUTPUT_MAP_TARGET1_Start                                  4
#define MWV207REG_PS_OUTPUT_MAP_TARGET1_Type                                 U03


#define MWV207REG_PS_OUTPUT_MAP_TARGET2                                     10:8
#define MWV207REG_PS_OUTPUT_MAP_TARGET2_End                                   10
#define MWV207REG_PS_OUTPUT_MAP_TARGET2_Start                                  8
#define MWV207REG_PS_OUTPUT_MAP_TARGET2_Type                                 U03


#define MWV207REG_PS_OUTPUT_MAP_TARGET3                                    14:12
#define MWV207REG_PS_OUTPUT_MAP_TARGET3_End                                   14
#define MWV207REG_PS_OUTPUT_MAP_TARGET3_Start                                 12
#define MWV207REG_PS_OUTPUT_MAP_TARGET3_Type                                 U03


#define MWV207REG_PS_OUTPUT_MAP_TARGET4                                    18:16
#define MWV207REG_PS_OUTPUT_MAP_TARGET4_End                                   18
#define MWV207REG_PS_OUTPUT_MAP_TARGET4_Start                                 16
#define MWV207REG_PS_OUTPUT_MAP_TARGET4_Type                                 U03


#define MWV207REG_PS_OUTPUT_MAP_TARGET5                                    22:20
#define MWV207REG_PS_OUTPUT_MAP_TARGET5_End                                   22
#define MWV207REG_PS_OUTPUT_MAP_TARGET5_Start                                 20
#define MWV207REG_PS_OUTPUT_MAP_TARGET5_Type                                 U03


#define MWV207REG_PS_OUTPUT_MAP_TARGET6                                    26:24
#define MWV207REG_PS_OUTPUT_MAP_TARGET6_End                                   26
#define MWV207REG_PS_OUTPUT_MAP_TARGET6_Start                                 24
#define MWV207REG_PS_OUTPUT_MAP_TARGET6_Type                                 U03


#define MWV207REG_PS_OUTPUT_MAP_TARGET7                                    30:28
#define MWV207REG_PS_OUTPUT_MAP_TARGET7_End                                   30
#define MWV207REG_PS_OUTPUT_MAP_TARGET7_Start                                 28
#define MWV207REG_PS_OUTPUT_MAP_TARGET7_Type                                 U03




#define mwv207regPSInstructionPrefetchRegAddrs                            0x0412
#define MWV207REG_PS_INSTRUCTION_PREFETCH_Address                        0x01048
#define MWV207REG_PS_INSTRUCTION_PREFETCH_MSB                                 15
#define MWV207REG_PS_INSTRUCTION_PREFETCH_LSB                                  0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_BLK                                  0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_Count                                1
#define MWV207REG_PS_INSTRUCTION_PREFETCH_FieldMask                   0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_ReadMask                    0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_WriteMask                   0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_ResetValue                  0x00000000


#define MWV207REG_PS_INSTRUCTION_PREFETCH_PC                                19:0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_PC_End                              19
#define MWV207REG_PS_INSTRUCTION_PREFETCH_PC_Start                             0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_PC_Type                            U20



#define mwv207regPSInstructionPrefetchEndRegAddrs                         0x0413
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_Address                    0x0104C
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_MSB                             15
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_LSB                              0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_BLK                              0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_Count                            1
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_FieldMask               0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_ReadMask                0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_WriteMask               0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_ResetValue              0x00000000

#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_PC                            19:0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_PC_End                          19
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_PC_Start                         0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_END_PC_Type                        U20



#define mwv207regPSUniformLockRegAddrs                                    0x0414
#define MWV207REG_PS_UNIFORM_LOCK_Address                                0x01050
#define MWV207REG_PS_UNIFORM_LOCK_MSB                                         15
#define MWV207REG_PS_UNIFORM_LOCK_LSB                                          0
#define MWV207REG_PS_UNIFORM_LOCK_BLK                                          0
#define MWV207REG_PS_UNIFORM_LOCK_Count                                        1
#define MWV207REG_PS_UNIFORM_LOCK_FieldMask                           0x000003FF
#define MWV207REG_PS_UNIFORM_LOCK_ReadMask                            0x000003FF
#define MWV207REG_PS_UNIFORM_LOCK_WriteMask                           0x000003FF
#define MWV207REG_PS_UNIFORM_LOCK_ResetValue                          0x00000000


#define MWV207REG_PS_UNIFORM_LOCK_OFFSET                                     9:0
#define MWV207REG_PS_UNIFORM_LOCK_OFFSET_End                                   9
#define MWV207REG_PS_UNIFORM_LOCK_OFFSET_Start                                 0
#define MWV207REG_PS_UNIFORM_LOCK_OFFSET_Type                                U10

#define mwv207regPSSampleCoverageCtrlRegAddrs                             0x0415
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_Address                        0x01054
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MSB                                 15
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_LSB                                  0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_BLK                                  0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_Count                                1
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_FieldMask                   0x99F9998F
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ReadMask                    0x99F9998F
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_WriteMask                   0x99F9998F
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ResetValue                  0x00000000


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_VALUE                3:0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_VALUE_End              3
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_VALUE_Start            0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_VALUE_Type           U04
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_VALUE_ENABLE       0x1
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_VALUE_DISABLE      0x0


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_VALUE           7:7
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_VALUE_End         7
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_VALUE_Start       7
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_VALUE_Type      U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_VALUE_ENABLED 0x0
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_VALUE_MASKED  0x1


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE                      8:8
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_End                    8
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_Start                  8
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_Type                 U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_ENABLE             0x1
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_COVERAGE_DISABLE            0x0


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE               11:11
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_End              11
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_Start            11
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_Type            U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_ENABLED       0x0
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_MASK_COVERAGE_MASKED        0x1


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ALPHA_TO_COVERAGE                12:12
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ALPHA_TO_COVERAGE_End               12
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ALPHA_TO_COVERAGE_Start             12
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ALPHA_TO_COVERAGE_Type             U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ALPHA_TO_COVERAGE_ENABLE         0x1
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_ALPHA_TO_COVERAGE_DISABLE        0x0


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_ALPHA_TO_COVERAGE           15:15
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_ALPHA_TO_COVERAGE_End          15
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_ALPHA_TO_COVERAGE_Start        15
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_ALPHA_TO_COVERAGE_Type        U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_ALPHA_TO_COVERAGE_ENABLED   0x0
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_ALPHA_TO_COVERAGE_MASKED    0x1


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_INVERT           16:16
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_INVERT_End          16
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_INVERT_Start        16
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_INVERT_Type        U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_INVERT_ENABLE    0x1
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_INVERT_DISABLE   0x0


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_INVERT      19:19
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_INVERT_End     19
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_INVERT_Start   19
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_INVERT_Type   U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_INVERT_ENABLED 0x0
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_INVERT_MASKED 0x1


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_VALUE            24:20
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_VALUE_End           24
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_VALUE_Start         20
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_VALUE_Type         U05
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_VALUE_ENABLE    0x01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_VALUE_DISABLE   0x00


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_VALUE       27:27
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_VALUE_End      27
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_VALUE_Start    27
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_VALUE_Type    U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_VALUE_ENABLED 0x0
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_VALUE_MASKED 0x1


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE                  28:28
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_End                 28
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_Start               28
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_Type               U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_ENABLE           0x1
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_GLOBAL_COVERAGE_DISABLE          0x0


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE             31:31
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_End            31
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_Start          31
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_Type          U01
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_ENABLED     0x0
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_MASK_GLOBAL_COVERAGE_MASKED      0x1




#define mwv207regPSSampleDitherTableRegAddrs                              0x0418
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_Address                         0x01060
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_MSB                                  15
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_LSB                                   3
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_BLK                                   3
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_Count                                 8
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_FieldMask                    0xFFFFFFFF
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_ReadMask                     0xFFFFFFFF
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_WriteMask                    0xFFFFFFFF
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_ResetValue                   0x00000000


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X0                                  3:0
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X0_End                                3
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X0_Start                              0
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X0_Type                             U04


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X1                                  7:4
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X1_End                                7
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X1_Start                              4
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X1_Type                             U04


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X2                                 11:8
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X2_End                               11
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X2_Start                              8
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X2_Type                             U04


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X3                                15:12
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X3_End                               15
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X3_Start                             12
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X3_Type                             U04


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X4                                19:16
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X4_End                               19
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X4_Start                             16
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X4_Type                             U04


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X5                                23:20
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X5_End                               23
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X5_Start                             20
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X5_Type                             U04


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X6                                27:24
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X6_End                               27
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X6_Start                             24
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X6_Type                             U04


#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X7                                31:28
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X7_End                               31
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X7_Start                             28
#define MWV207REG_PS_SAMPLE_DITHER_TABLE_X7_Type                             U04




#define mwv207regPSUnpackRegAddrs                                         0x0420
#define MWV207REG_PS_UNPACK_Address                                      0x01080
#define MWV207REG_PS_UNPACK_MSB                                               15
#define MWV207REG_PS_UNPACK_LSB                                                2
#define MWV207REG_PS_UNPACK_BLK                                                2
#define MWV207REG_PS_UNPACK_Count                                              4
#define MWV207REG_PS_UNPACK_FieldMask                                 0x77777777
#define MWV207REG_PS_UNPACK_ReadMask                                  0x77777777
#define MWV207REG_PS_UNPACK_WriteMask                                 0x77777777
#define MWV207REG_PS_UNPACK_ResetValue                                0x00000000

#define MWV207REG_PS_UNPACK_VARYING0                                         2:0
#define MWV207REG_PS_UNPACK_VARYING0_End                                       2
#define MWV207REG_PS_UNPACK_VARYING0_Start                                     0
#define MWV207REG_PS_UNPACK_VARYING0_Type                                    U03

#define MWV207REG_PS_UNPACK_VARYING1                                         6:4
#define MWV207REG_PS_UNPACK_VARYING1_End                                       6
#define MWV207REG_PS_UNPACK_VARYING1_Start                                     4
#define MWV207REG_PS_UNPACK_VARYING1_Type                                    U03

#define MWV207REG_PS_UNPACK_VARYING2                                        10:8
#define MWV207REG_PS_UNPACK_VARYING2_End                                      10
#define MWV207REG_PS_UNPACK_VARYING2_Start                                     8
#define MWV207REG_PS_UNPACK_VARYING2_Type                                    U03

#define MWV207REG_PS_UNPACK_VARYING3                                       14:12
#define MWV207REG_PS_UNPACK_VARYING3_End                                      14
#define MWV207REG_PS_UNPACK_VARYING3_Start                                    12
#define MWV207REG_PS_UNPACK_VARYING3_Type                                    U03

#define MWV207REG_PS_UNPACK_VARYING4                                       18:16
#define MWV207REG_PS_UNPACK_VARYING4_End                                      18
#define MWV207REG_PS_UNPACK_VARYING4_Start                                    16
#define MWV207REG_PS_UNPACK_VARYING4_Type                                    U03

#define MWV207REG_PS_UNPACK_VARYING5                                       22:20
#define MWV207REG_PS_UNPACK_VARYING5_End                                      22
#define MWV207REG_PS_UNPACK_VARYING5_Start                                    20
#define MWV207REG_PS_UNPACK_VARYING5_Type                                    U03

#define MWV207REG_PS_UNPACK_VARYING6                                       26:24
#define MWV207REG_PS_UNPACK_VARYING6_End                                      26
#define MWV207REG_PS_UNPACK_VARYING6_Start                                    24
#define MWV207REG_PS_UNPACK_VARYING6_Type                                    U03

#define MWV207REG_PS_UNPACK_VARYING7                                       30:28
#define MWV207REG_PS_UNPACK_VARYING7_End                                      30
#define MWV207REG_PS_UNPACK_VARYING7_Start                                    28
#define MWV207REG_PS_UNPACK_VARYING7_Type                                    U03




#define mwv207regPSSamplerBaseRegAddrs                                    0x0416
#define MWV207REG_PS_SAMPLER_BASE_Address                                0x01058
#define MWV207REG_PS_SAMPLER_BASE_MSB                                         15
#define MWV207REG_PS_SAMPLER_BASE_LSB                                          0
#define MWV207REG_PS_SAMPLER_BASE_BLK                                          0
#define MWV207REG_PS_SAMPLER_BASE_Count                                        1
#define MWV207REG_PS_SAMPLER_BASE_FieldMask                           0x03FF007F
#define MWV207REG_PS_SAMPLER_BASE_ReadMask                            0x03FF007F
#define MWV207REG_PS_SAMPLER_BASE_WriteMask                           0x03FF007F
#define MWV207REG_PS_SAMPLER_BASE_ResetValue                          0x00000000


#define MWV207REG_PS_SAMPLER_BASE_OFFSET                                     6:0
#define MWV207REG_PS_SAMPLER_BASE_OFFSET_End                                   6
#define MWV207REG_PS_SAMPLER_BASE_OFFSET_Start                                 0
#define MWV207REG_PS_SAMPLER_BASE_OFFSET_Type                                U07


#define MWV207REG_PS_SAMPLER_BASE_TXD_OFFSET                               25:16
#define MWV207REG_PS_SAMPLER_BASE_TXD_OFFSET_End                              25
#define MWV207REG_PS_SAMPLER_BASE_TXD_OFFSET_Start                            16
#define MWV207REG_PS_SAMPLER_BASE_TXD_OFFSET_Type                            U10



#define mwv207regPSSamplerLockRegAddrs                                    0x0417
#define MWV207REG_PS_SAMPLER_LOCK_Address                                0x0105C
#define MWV207REG_PS_SAMPLER_LOCK_MSB                                         15
#define MWV207REG_PS_SAMPLER_LOCK_LSB                                          0
#define MWV207REG_PS_SAMPLER_LOCK_BLK                                          0
#define MWV207REG_PS_SAMPLER_LOCK_Count                                        1
#define MWV207REG_PS_SAMPLER_LOCK_FieldMask                           0x03FF007F
#define MWV207REG_PS_SAMPLER_LOCK_ReadMask                            0x03FF007F
#define MWV207REG_PS_SAMPLER_LOCK_WriteMask                           0x03FF007F
#define MWV207REG_PS_SAMPLER_LOCK_ResetValue                          0x00000000


#define MWV207REG_PS_SAMPLER_LOCK_OFFSET                                     6:0
#define MWV207REG_PS_SAMPLER_LOCK_OFFSET_End                                   6
#define MWV207REG_PS_SAMPLER_LOCK_OFFSET_Start                                 0
#define MWV207REG_PS_SAMPLER_LOCK_OFFSET_Type                                U07


#define MWV207REG_PS_SAMPLER_LOCK_TXD_OFFSET                               25:16
#define MWV207REG_PS_SAMPLER_LOCK_TXD_OFFSET_End                              25
#define MWV207REG_PS_SAMPLER_LOCK_TXD_OFFSET_Start                            16
#define MWV207REG_PS_SAMPLER_LOCK_TXD_OFFSET_Type                            U10




#define mwv207regPSRelativeEndRegAddrs                                    0x0424
#define MWV207REG_PS_RELATIVE_END_Address                                0x01090
#define MWV207REG_PS_RELATIVE_END_MSB                                         15
#define MWV207REG_PS_RELATIVE_END_LSB                                          0
#define MWV207REG_PS_RELATIVE_END_BLK                                          0
#define MWV207REG_PS_RELATIVE_END_Count                                        1
#define MWV207REG_PS_RELATIVE_END_FieldMask                           0x001FFFFF
#define MWV207REG_PS_RELATIVE_END_ReadMask                            0x001FFFFF
#define MWV207REG_PS_RELATIVE_END_WriteMask                           0x001FFFFF
#define MWV207REG_PS_RELATIVE_END_ResetValue                          0x00000000

#define MWV207REG_PS_RELATIVE_END_PC                                        20:0
#define MWV207REG_PS_RELATIVE_END_PC_End                                      20
#define MWV207REG_PS_RELATIVE_END_PC_Start                                     0
#define MWV207REG_PS_RELATIVE_END_PC_Type                                    U21



#define mwv207regPSInstructionPrefetchRelativeEndRegAddrs                 0x0425
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_Address           0x01094
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_MSB                    15
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_LSB                     0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_BLK                     0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_Count                   1
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_FieldMask      0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_ReadMask       0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_WriteMask      0x000FFFFF
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_ResetValue     0x00000000

#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_PC                   19:0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_End                 19
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Start                0
#define MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Type               U20




#define mwv207regPSMaxRegAddrs                                            0x0426
#define MWV207REG_PS_MAX_Address                                         0x01098
#define MWV207REG_PS_MAX_MSB                                                  15
#define MWV207REG_PS_MAX_LSB                                                   0
#define MWV207REG_PS_MAX_BLK                                                   0
#define MWV207REG_PS_MAX_Count                                                 1
#define MWV207REG_PS_MAX_FieldMask                                    0x000F07FF
#define MWV207REG_PS_MAX_ReadMask                                     0x000F07FF
#define MWV207REG_PS_MAX_WriteMask                                    0x000F07FF
#define MWV207REG_PS_MAX_ResetValue                                   0x00000000

#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX                                  7:0
#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX_End                                7
#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX_Start                              0
#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX_Type                             U08

#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX_BIT8_10                         10:8
#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX_BIT8_10_End                       10
#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX_BIT8_10_Start                      8
#define MWV207REG_PS_MAX_RENDER_ARRAY_INDEX_BIT8_10_Type                     U03

#define MWV207REG_PS_MAX_VIEWPORT_ARRAY_INDEX                              19:16
#define MWV207REG_PS_MAX_VIEWPORT_ARRAY_INDEX_End                             19
#define MWV207REG_PS_MAX_VIEWPORT_ARRAY_INDEX_Start                           16
#define MWV207REG_PS_MAX_VIEWPORT_ARRAY_INDEX_Type                           U04




#define mwv207regPSCSThrottleRegAddrs                                     0x0427
#define MWV207REG_PSCS_THROTTLE_Address                                  0x0109C
#define MWV207REG_PSCS_THROTTLE_MSB                                           15
#define MWV207REG_PSCS_THROTTLE_LSB                                            0
#define MWV207REG_PSCS_THROTTLE_BLK                                            0
#define MWV207REG_PSCS_THROTTLE_Count                                          1
#define MWV207REG_PSCS_THROTTLE_FieldMask                             0x0FFFFF7F
#define MWV207REG_PSCS_THROTTLE_ReadMask                              0x0FFFFF7F
#define MWV207REG_PSCS_THROTTLE_WriteMask                             0x0FFFFF7F
#define MWV207REG_PSCS_THROTTLE_ResetValue                            0x00000000

#define MWV207REG_PSCS_THROTTLE_ATTRIB_MAX_PAGES                             6:0
#define MWV207REG_PSCS_THROTTLE_ATTRIB_MAX_PAGES_End                           6
#define MWV207REG_PSCS_THROTTLE_ATTRIB_MAX_PAGES_Start                         0
#define MWV207REG_PSCS_THROTTLE_ATTRIB_MAX_PAGES_Type                        U07


#define MWV207REG_PSCS_THROTTLE_WORK_GROUP_COUNT_IN_SHADER_GROUP            15:8
#define MWV207REG_PSCS_THROTTLE_WORK_GROUP_COUNT_IN_SHADER_GROUP_End          15
#define MWV207REG_PSCS_THROTTLE_WORK_GROUP_COUNT_IN_SHADER_GROUP_Start         8
#define MWV207REG_PSCS_THROTTLE_WORK_GROUP_COUNT_IN_SHADER_GROUP_Type        U08

#define MWV207REG_PSCS_THROTTLE_MAX_RUNNING_WORK_GROUPS_MINUS_ONE          27:16
#define MWV207REG_PSCS_THROTTLE_MAX_RUNNING_WORK_GROUPS_MINUS_ONE_End         27
#define MWV207REG_PSCS_THROTTLE_MAX_RUNNING_WORK_GROUPS_MINUS_ONE_Start       16
#define MWV207REG_PSCS_THROTTLE_MAX_RUNNING_WORK_GROUPS_MINUS_ONE_Type       U12



#define mwv207regPSTriggerNNRegAddrs                                      0x0428
#define MWV207REG_PS_TRIGGER_NN_Address                                  0x010A0
#define MWV207REG_PS_TRIGGER_NN_MSB                                           15
#define MWV207REG_PS_TRIGGER_NN_LSB                                            0
#define MWV207REG_PS_TRIGGER_NN_BLK                                            0
#define MWV207REG_PS_TRIGGER_NN_Count                                          1
#define MWV207REG_PS_TRIGGER_NN_FieldMask                             0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_NN_ReadMask                              0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_NN_WriteMask                             0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_NN_ResetValue                            0x00000000


#define MWV207REG_PS_TRIGGER_NN_COMMAND_EVENT_ID                             4:0
#define MWV207REG_PS_TRIGGER_NN_COMMAND_EVENT_ID_End                           4
#define MWV207REG_PS_TRIGGER_NN_COMMAND_EVENT_ID_Start                         0
#define MWV207REG_PS_TRIGGER_NN_COMMAND_EVENT_ID_Type                        U05

#define MWV207REG_PS_TRIGGER_NN_COMMAND_BUFFER_ADDR                         31:6
#define MWV207REG_PS_TRIGGER_NN_COMMAND_BUFFER_ADDR_End                       31
#define MWV207REG_PS_TRIGGER_NN_COMMAND_BUFFER_ADDR_Start                      6
#define MWV207REG_PS_TRIGGER_NN_COMMAND_BUFFER_ADDR_Type                     U26




#define mwv207regPSWaitForEventRegAddrs                                   0x0429
#define MWV207REG_PS_WAIT_FOR_EVENT_Address                              0x010A4
#define MWV207REG_PS_WAIT_FOR_EVENT_MSB                                       15
#define MWV207REG_PS_WAIT_FOR_EVENT_LSB                                        0
#define MWV207REG_PS_WAIT_FOR_EVENT_BLK                                        0
#define MWV207REG_PS_WAIT_FOR_EVENT_Count                                      1
#define MWV207REG_PS_WAIT_FOR_EVENT_FieldMask                         0x0000001F
#define MWV207REG_PS_WAIT_FOR_EVENT_ReadMask                          0x0000001F
#define MWV207REG_PS_WAIT_FOR_EVENT_WriteMask                         0x0000001F
#define MWV207REG_PS_WAIT_FOR_EVENT_ResetValue                        0x00000000

#define MWV207REG_PS_WAIT_FOR_EVENT_EVENT_ID                                 4:0
#define MWV207REG_PS_WAIT_FOR_EVENT_EVENT_ID_End                               4
#define MWV207REG_PS_WAIT_FOR_EVENT_EVENT_ID_Start                             0
#define MWV207REG_PS_WAIT_FOR_EVENT_EVENT_ID_Type                            U05




#define mwv207regGpipeLoadBalancingRegAddrs                               0x042A
#define MWV207REG_GPIPE_LOAD_BALANCING_Address                           0x010A8
#define MWV207REG_GPIPE_LOAD_BALANCING_MSB                                    15
#define MWV207REG_GPIPE_LOAD_BALANCING_LSB                                     0
#define MWV207REG_GPIPE_LOAD_BALANCING_BLK                                     0
#define MWV207REG_GPIPE_LOAD_BALANCING_Count                                   1
#define MWV207REG_GPIPE_LOAD_BALANCING_FieldMask                      0x00000FF1
#define MWV207REG_GPIPE_LOAD_BALANCING_ReadMask                       0x00000FF1
#define MWV207REG_GPIPE_LOAD_BALANCING_WriteMask                      0x00000FF1
#define MWV207REG_GPIPE_LOAD_BALANCING_ResetValue                     0x00000000

#define MWV207REG_GPIPE_LOAD_BALANCING_HIGH_WM_SIZE                          0:0
#define MWV207REG_GPIPE_LOAD_BALANCING_HIGH_WM_SIZE_End                        0
#define MWV207REG_GPIPE_LOAD_BALANCING_HIGH_WM_SIZE_Start                      0
#define MWV207REG_GPIPE_LOAD_BALANCING_HIGH_WM_SIZE_Type                     U01
#define   MWV207REG_GPIPE_LOAD_BALANCING_HIGH_WM_SIZE_QUARTER                0x1
#define   MWV207REG_GPIPE_LOAD_BALANCING_HIGH_WM_SIZE_HALF                   0x0

#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_BELOW_WM              7:4
#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_BELOW_WM_End            7
#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_BELOW_WM_Start          4
#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_BELOW_WM_Type         U04

#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_ABOVE_WM             11:8
#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_ABOVE_WM_End           11
#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_ABOVE_WM_Start          8
#define MWV207REG_GPIPE_LOAD_BALANCING_GPIPE_TIMESLICE_ABOVE_WM_Type         U04




#define mwv207regSHAllocUniformsRegAddrs                                  0x042B
#define MWV207REG_SH_ALLOC_UNIFORMS_Address                              0x010AC
#define MWV207REG_SH_ALLOC_UNIFORMS_MSB                                       15
#define MWV207REG_SH_ALLOC_UNIFORMS_LSB                                        0
#define MWV207REG_SH_ALLOC_UNIFORMS_BLK                                        0
#define MWV207REG_SH_ALLOC_UNIFORMS_Count                                      1
#define MWV207REG_SH_ALLOC_UNIFORMS_FieldMask                         0x81FF01FF
#define MWV207REG_SH_ALLOC_UNIFORMS_ReadMask                          0x81FF01FF
#define MWV207REG_SH_ALLOC_UNIFORMS_WriteMask                         0x81FF01FF
#define MWV207REG_SH_ALLOC_UNIFORMS_ResetValue                        0x00000000


#define MWV207REG_SH_ALLOC_UNIFORMS_SIZE                                     8:0
#define MWV207REG_SH_ALLOC_UNIFORMS_SIZE_End                                   8
#define MWV207REG_SH_ALLOC_UNIFORMS_SIZE_Start                                 0
#define MWV207REG_SH_ALLOC_UNIFORMS_SIZE_Type                                U09


#define MWV207REG_SH_ALLOC_UNIFORMS_BASE                                   24:16
#define MWV207REG_SH_ALLOC_UNIFORMS_BASE_End                                  24
#define MWV207REG_SH_ALLOC_UNIFORMS_BASE_Start                                16
#define MWV207REG_SH_ALLOC_UNIFORMS_BASE_Type                                U09


#define MWV207REG_SH_ALLOC_UNIFORMS_COPY                                   31:31
#define MWV207REG_SH_ALLOC_UNIFORMS_COPY_End                                  31
#define MWV207REG_SH_ALLOC_UNIFORMS_COPY_Start                                31
#define MWV207REG_SH_ALLOC_UNIFORMS_COPY_Type                                U01
#define   MWV207REG_SH_ALLOC_UNIFORMS_COPY_DISABLE                           0x0
#define   MWV207REG_SH_ALLOC_UNIFORMS_COPY_ENABLE                            0x1




#define mwv207regSHAllocSamplersRegAddrs                                  0x042C
#define MWV207REG_SH_ALLOC_SAMPLERS_Address                              0x010B0
#define MWV207REG_SH_ALLOC_SAMPLERS_MSB                                       15
#define MWV207REG_SH_ALLOC_SAMPLERS_LSB                                        0
#define MWV207REG_SH_ALLOC_SAMPLERS_BLK                                        0
#define MWV207REG_SH_ALLOC_SAMPLERS_Count                                      1
#define MWV207REG_SH_ALLOC_SAMPLERS_FieldMask                         0x807F007F
#define MWV207REG_SH_ALLOC_SAMPLERS_ReadMask                          0x807F007F
#define MWV207REG_SH_ALLOC_SAMPLERS_WriteMask                         0x807F007F
#define MWV207REG_SH_ALLOC_SAMPLERS_ResetValue                        0x00000000


#define MWV207REG_SH_ALLOC_SAMPLERS_SIZE                                     6:0
#define MWV207REG_SH_ALLOC_SAMPLERS_SIZE_End                                   6
#define MWV207REG_SH_ALLOC_SAMPLERS_SIZE_Start                                 0
#define MWV207REG_SH_ALLOC_SAMPLERS_SIZE_Type                                U07


#define MWV207REG_SH_ALLOC_SAMPLERS_BASE                                   22:16
#define MWV207REG_SH_ALLOC_SAMPLERS_BASE_End                                  22
#define MWV207REG_SH_ALLOC_SAMPLERS_BASE_Start                                16
#define MWV207REG_SH_ALLOC_SAMPLERS_BASE_Type                                U07


#define MWV207REG_SH_ALLOC_SAMPLERS_COPY                                   31:31
#define MWV207REG_SH_ALLOC_SAMPLERS_COPY_End                                  31
#define MWV207REG_SH_ALLOC_SAMPLERS_COPY_Start                                31
#define MWV207REG_SH_ALLOC_SAMPLERS_COPY_Type                                U01
#define   MWV207REG_SH_ALLOC_SAMPLERS_COPY_DISABLE                           0x0
#define   MWV207REG_SH_ALLOC_SAMPLERS_COPY_ENABLE                            0x1




#define mwv207regSHAllocTexturesRegAddrs                                  0x042D
#define MWV207REG_SH_ALLOC_TEXTURES_Address                              0x010B4
#define MWV207REG_SH_ALLOC_TEXTURES_MSB                                       15
#define MWV207REG_SH_ALLOC_TEXTURES_LSB                                        0
#define MWV207REG_SH_ALLOC_TEXTURES_BLK                                        0
#define MWV207REG_SH_ALLOC_TEXTURES_Count                                      1
#define MWV207REG_SH_ALLOC_TEXTURES_FieldMask                         0x807F007F
#define MWV207REG_SH_ALLOC_TEXTURES_ReadMask                          0x807F007F
#define MWV207REG_SH_ALLOC_TEXTURES_WriteMask                         0x807F007F
#define MWV207REG_SH_ALLOC_TEXTURES_ResetValue                        0x00000000


#define MWV207REG_SH_ALLOC_TEXTURES_SIZE                                     6:0
#define MWV207REG_SH_ALLOC_TEXTURES_SIZE_End                                   6
#define MWV207REG_SH_ALLOC_TEXTURES_SIZE_Start                                 0
#define MWV207REG_SH_ALLOC_TEXTURES_SIZE_Type                                U07


#define MWV207REG_SH_ALLOC_TEXTURES_BASE                                   22:16
#define MWV207REG_SH_ALLOC_TEXTURES_BASE_End                                  22
#define MWV207REG_SH_ALLOC_TEXTURES_BASE_Start                                16
#define MWV207REG_SH_ALLOC_TEXTURES_BASE_Type                                U07


#define MWV207REG_SH_ALLOC_TEXTURES_COPY                                   31:31
#define MWV207REG_SH_ALLOC_TEXTURES_COPY_End                                  31
#define MWV207REG_SH_ALLOC_TEXTURES_COPY_Start                                31
#define MWV207REG_SH_ALLOC_TEXTURES_COPY_Type                                U01
#define   MWV207REG_SH_ALLOC_TEXTURES_COPY_DISABLE                           0x0
#define   MWV207REG_SH_ALLOC_TEXTURES_COPY_ENABLE                            0x1




#define mwv207regPSTriggerTPRegAddrs                                      0x042E
#define MWV207REG_PS_TRIGGER_TP_Address                                  0x010B8
#define MWV207REG_PS_TRIGGER_TP_MSB                                           15
#define MWV207REG_PS_TRIGGER_TP_LSB                                            0
#define MWV207REG_PS_TRIGGER_TP_BLK                                            0
#define MWV207REG_PS_TRIGGER_TP_Count                                          1
#define MWV207REG_PS_TRIGGER_TP_FieldMask                             0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_TP_ReadMask                              0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_TP_WriteMask                             0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_TP_ResetValue                            0x00000000


#define MWV207REG_PS_TRIGGER_TP_COMMAND_EVENT_ID                             4:0
#define MWV207REG_PS_TRIGGER_TP_COMMAND_EVENT_ID_End                           4
#define MWV207REG_PS_TRIGGER_TP_COMMAND_EVENT_ID_Start                         0
#define MWV207REG_PS_TRIGGER_TP_COMMAND_EVENT_ID_Type                        U05

#define MWV207REG_PS_TRIGGER_TP_COMMAND_BUFFER_ADDR                         31:6
#define MWV207REG_PS_TRIGGER_TP_COMMAND_BUFFER_ADDR_End                       31
#define MWV207REG_PS_TRIGGER_TP_COMMAND_BUFFER_ADDR_Start                      6
#define MWV207REG_PS_TRIGGER_TP_COMMAND_BUFFER_ADDR_Type                     U26




#define mwv207regPSTriggerCustomerSuperInstructionRegAddrs                0x042F
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_Address          0x010BC
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_MSB                   15
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_LSB                    0
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_BLK                    0
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_Count                  1
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_FieldMask     0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_ReadMask      0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_WriteMask     0xFFFFFFDF
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_ResetValue    0x00000000


#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_EVENT_ID     4:0
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_EVENT_ID_End   4
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_EVENT_ID_Start 0
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_EVENT_ID_Type U05

#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_BUFFER_ADDR 31:6
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_BUFFER_ADDR_End 31
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_BUFFER_ADDR_Start 6
#define MWV207REG_PS_TRIGGER_CUSTOMER_SUPER_INSTRUCTION_COMMAND_BUFFER_ADDR_Type U26




#define mwv207regSHStateControlRegAddrs                                   0x0430
#define MWV207REG_SH_STATE_CONTROL_Address                               0x010C0
#define MWV207REG_SH_STATE_CONTROL_MSB                                        15
#define MWV207REG_SH_STATE_CONTROL_LSB                                         0
#define MWV207REG_SH_STATE_CONTROL_BLK                                         0
#define MWV207REG_SH_STATE_CONTROL_Count                                       1
#define MWV207REG_SH_STATE_CONTROL_FieldMask                          0x00000011
#define MWV207REG_SH_STATE_CONTROL_ReadMask                           0x00000011
#define MWV207REG_SH_STATE_CONTROL_WriteMask                          0x00000011
#define MWV207REG_SH_STATE_CONTROL_ResetValue                         0x00000000


#define MWV207REG_SH_STATE_CONTROL_GPIPE_STATE_BARRIER                       0:0
#define MWV207REG_SH_STATE_CONTROL_GPIPE_STATE_BARRIER_End                     0
#define MWV207REG_SH_STATE_CONTROL_GPIPE_STATE_BARRIER_Start                   0
#define MWV207REG_SH_STATE_CONTROL_GPIPE_STATE_BARRIER_Type                  U01
#define   MWV207REG_SH_STATE_CONTROL_GPIPE_STATE_BARRIER_DISABLED            0x0
#define   MWV207REG_SH_STATE_CONTROL_GPIPE_STATE_BARRIER_ENABLED             0x1


#define MWV207REG_SH_STATE_CONTROL_PPIPE_STATE_BARRIER                       4:4
#define MWV207REG_SH_STATE_CONTROL_PPIPE_STATE_BARRIER_End                     4
#define MWV207REG_SH_STATE_CONTROL_PPIPE_STATE_BARRIER_Start                   4
#define MWV207REG_SH_STATE_CONTROL_PPIPE_STATE_BARRIER_Type                  U01
#define   MWV207REG_SH_STATE_CONTROL_PPIPE_STATE_BARRIER_DISABLED            0x0
#define   MWV207REG_SH_STATE_CONTROL_PPIPE_STATE_BARRIER_ENABLED             0x1




#define mwv207regSHL1LSControlRegAddrs                                    0x0431
#define MWV207REG_SHL1_LS_CONTROL_Address                                0x010C4
#define MWV207REG_SHL1_LS_CONTROL_MSB                                         15
#define MWV207REG_SHL1_LS_CONTROL_LSB                                          0
#define MWV207REG_SHL1_LS_CONTROL_BLK                                          0
#define MWV207REG_SHL1_LS_CONTROL_Count                                        1
#define MWV207REG_SHL1_LS_CONTROL_FieldMask                           0x0000000F
#define MWV207REG_SHL1_LS_CONTROL_ReadMask                            0x0000000F
#define MWV207REG_SHL1_LS_CONTROL_WriteMask                           0x0000000F
#define MWV207REG_SHL1_LS_CONTROL_ResetValue                          0x00000000


#define MWV207REG_SHL1_LS_CONTROL_HASH_TABLE                                 0:0
#define MWV207REG_SHL1_LS_CONTROL_HASH_TABLE_End                               0
#define MWV207REG_SHL1_LS_CONTROL_HASH_TABLE_Start                             0
#define MWV207REG_SHL1_LS_CONTROL_HASH_TABLE_Type                            U01
#define   MWV207REG_SHL1_LS_CONTROL_HASH_TABLE_DISABLED                      0x0
#define   MWV207REG_SHL1_LS_CONTROL_HASH_TABLE_ENABLED                       0x1


#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_LINE                               1:1
#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_LINE_End                             1
#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_LINE_Start                           1
#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_LINE_Type                          U01
#define   MWV207REG_SHL1_LS_CONTROL_L1_HASH_LINE_DISABLED                    0x0
#define   MWV207REG_SHL1_LS_CONTROL_L1_HASH_LINE_ENABLED                     0x1


#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_BANK                               2:2
#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_BANK_End                             2
#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_BANK_Start                           2
#define MWV207REG_SHL1_LS_CONTROL_L1_HASH_BANK_Type                          U01
#define   MWV207REG_SHL1_LS_CONTROL_L1_HASH_BANK_DISABLED                    0x0
#define   MWV207REG_SHL1_LS_CONTROL_L1_HASH_BANK_ENABLED                     0x1


#define MWV207REG_SHL1_LS_CONTROL_LS_HASH_BANK                               3:3
#define MWV207REG_SHL1_LS_CONTROL_LS_HASH_BANK_End                             3
#define MWV207REG_SHL1_LS_CONTROL_LS_HASH_BANK_Start                           3
#define MWV207REG_SHL1_LS_CONTROL_LS_HASH_BANK_Type                          U01
#define   MWV207REG_SHL1_LS_CONTROL_LS_HASH_BANK_DISABLED                    0x0
#define   MWV207REG_SHL1_LS_CONTROL_LS_HASH_BANK_ENABLED                     0x1

#define mwv207regPSOutputControl1RegAddrs                                 0x0432
#define MWV207REG_PS_OUTPUT_CONTROL1_Address                             0x010C8
#define MWV207REG_PS_OUTPUT_CONTROL1_MSB                                      15
#define MWV207REG_PS_OUTPUT_CONTROL1_LSB                                       0
#define MWV207REG_PS_OUTPUT_CONTROL1_BLK                                       0
#define MWV207REG_PS_OUTPUT_CONTROL1_Count                                     1
#define MWV207REG_PS_OUTPUT_CONTROL1_FieldMask                        0xBFBFBFBF
#define MWV207REG_PS_OUTPUT_CONTROL1_ReadMask                         0xBFBFBFBF
#define MWV207REG_PS_OUTPUT_CONTROL1_WriteMask                        0xBFBFBFBF
#define MWV207REG_PS_OUTPUT_CONTROL1_ResetValue                       0x00000000

#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT8                                 5:0
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT8_End                               5
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT8_Start                             0
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT8_Type                            U06

#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE8                     7:7
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE8_End                   7
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE8_Start                 7
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE8_Type                U01
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE8_DISABLE           0x0
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE8_ENABLE            0x1

#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT9                                13:8
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT9_End                              13
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT9_Start                             8
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT9_Type                            U06

#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE9                   15:15
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE9_End                  15
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE9_Start                15
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE9_Type                U01
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE9_DISABLE           0x0
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE9_ENABLE            0x1

#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT10                              21:16
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT10_End                             21
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT10_Start                           16
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT10_Type                           U06

#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE10                  23:23
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE10_End                 23
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE10_Start               23
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE10_Type               U01
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE10_DISABLE          0x0
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE10_ENABLE           0x1

#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT11                              29:24
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT11_End                             29
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT11_Start                           24
#define MWV207REG_PS_OUTPUT_CONTROL1_OUTPUT11_Type                           U06

#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE11                  31:31
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE11_End                 31
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE11_Start               31
#define MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE11_Type               U01
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE11_DISABLE          0x0
#define   MWV207REG_PS_OUTPUT_CONTROL1_COLOR_OUT_SATURATE11_ENABLE           0x1

#define mwv207regPSOutputControl2RegAddrs                                 0x0433
#define MWV207REG_PS_OUTPUT_CONTROL2_Address                             0x010CC
#define MWV207REG_PS_OUTPUT_CONTROL2_MSB                                      15
#define MWV207REG_PS_OUTPUT_CONTROL2_LSB                                       0
#define MWV207REG_PS_OUTPUT_CONTROL2_BLK                                       0
#define MWV207REG_PS_OUTPUT_CONTROL2_Count                                     1
#define MWV207REG_PS_OUTPUT_CONTROL2_FieldMask                        0xBFBFBFBF
#define MWV207REG_PS_OUTPUT_CONTROL2_ReadMask                         0xBFBFBFBF
#define MWV207REG_PS_OUTPUT_CONTROL2_WriteMask                        0xBFBFBFBF
#define MWV207REG_PS_OUTPUT_CONTROL2_ResetValue                       0x00000000

#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT12                                5:0
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT12_End                              5
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT12_Start                            0
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT12_Type                           U06

#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE12                    7:7
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE12_End                  7
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE12_Start                7
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE12_Type               U01
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE12_DISABLE          0x0
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE12_ENABLE           0x1

#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT13                               13:8
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT13_End                             13
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT13_Start                            8
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT13_Type                           U06

#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE13                  15:15
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE13_End                 15
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE13_Start               15
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE13_Type               U01
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE13_DISABLE          0x0
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE13_ENABLE           0x1

#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT14                              21:16
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT14_End                             21
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT14_Start                           16
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT14_Type                           U06

#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE14                  23:23
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE14_End                 23
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE14_Start               23
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE14_Type               U01
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE14_DISABLE          0x0
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE14_ENABLE           0x1

#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT15                              29:24
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT15_End                             29
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT15_Start                           24
#define MWV207REG_PS_OUTPUT_CONTROL2_OUTPUT15_Type                           U06

#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE15                  31:31
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE15_End                 31
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE15_Start               31
#define MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE15_Type               U01
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE15_DISABLE          0x0
#define   MWV207REG_PS_OUTPUT_CONTROL2_COLOR_OUT_SATURATE15_ENABLE           0x1




#define mwv207regSHInternalControlRegAddrs                                0x0434
#define MWV207REG_SH_INTERNAL_CONTROL_Address                            0x010D0
#define MWV207REG_SH_INTERNAL_CONTROL_MSB                                     15
#define MWV207REG_SH_INTERNAL_CONTROL_LSB                                      0
#define MWV207REG_SH_INTERNAL_CONTROL_BLK                                      0
#define MWV207REG_SH_INTERNAL_CONTROL_Count                                    1
#define MWV207REG_SH_INTERNAL_CONTROL_FieldMask                       0xFFFFFFFF
#define MWV207REG_SH_INTERNAL_CONTROL_ReadMask                        0xFFFFFFFF
#define MWV207REG_SH_INTERNAL_CONTROL_WriteMask                       0xFFFFFFFF
#define MWV207REG_SH_INTERNAL_CONTROL_ResetValue                      0x00000000

#define MWV207REG_SH_INTERNAL_CONTROL_RTL                                   31:0
#define MWV207REG_SH_INTERNAL_CONTROL_RTL_End                                 31
#define MWV207REG_SH_INTERNAL_CONTROL_RTL_Start                                0
#define MWV207REG_SH_INTERNAL_CONTROL_RTL_Type                               U32




#define mwv207regPSInputHpvecfmtRegAddrs                                  0x0435
#define MWV207REG_PS_INPUT_HPVECFMT_Address                              0x010D4
#define MWV207REG_PS_INPUT_HPVECFMT_MSB                                       15
#define MWV207REG_PS_INPUT_HPVECFMT_LSB                                        0
#define MWV207REG_PS_INPUT_HPVECFMT_BLK                                        0
#define MWV207REG_PS_INPUT_HPVECFMT_Count                                      1
#define MWV207REG_PS_INPUT_HPVECFMT_FieldMask                         0xFFFFFFFF
#define MWV207REG_PS_INPUT_HPVECFMT_ReadMask                          0xFFFFFFFF
#define MWV207REG_PS_INPUT_HPVECFMT_WriteMask                         0xFFFFFFFF
#define MWV207REG_PS_INPUT_HPVECFMT_ResetValue                        0x00000000

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING0                                 0:0
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING0_End                               0
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING0_Start                             0
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING0_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING0_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING0_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING1                                 1:1
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING1_End                               1
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING1_Start                             1
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING1_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING1_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING1_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING2                                 2:2
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING2_End                               2
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING2_Start                             2
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING2_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING2_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING2_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING3                                 3:3
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING3_End                               3
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING3_Start                             3
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING3_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING3_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING3_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING4                                 4:4
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING4_End                               4
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING4_Start                             4
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING4_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING4_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING4_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING5                                 5:5
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING5_End                               5
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING5_Start                             5
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING5_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING5_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING5_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING6                                 6:6
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING6_End                               6
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING6_Start                             6
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING6_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING6_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING6_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING7                                 7:7
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING7_End                               7
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING7_Start                             7
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING7_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING7_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING7_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING8                                 8:8
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING8_End                               8
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING8_Start                             8
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING8_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING8_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING8_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING9                                 9:9
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING9_End                               9
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING9_Start                             9
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING9_Type                            U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING9_HPV4                          0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING9_HPV2                          0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING10                              10:10
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING10_End                             10
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING10_Start                           10
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING10_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING10_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING10_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING11                              11:11
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING11_End                             11
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING11_Start                           11
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING11_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING11_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING11_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING12                              12:12
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING12_End                             12
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING12_Start                           12
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING12_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING12_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING12_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING13                              13:13
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING13_End                             13
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING13_Start                           13
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING13_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING13_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING13_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING14                              14:14
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING14_End                             14
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING14_Start                           14
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING14_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING14_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING14_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING15                              15:15
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING15_End                             15
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING15_Start                           15
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING15_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING15_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING15_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING16                              16:16
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING16_End                             16
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING16_Start                           16
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING16_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING16_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING16_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING17                              17:17
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING17_End                             17
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING17_Start                           17
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING17_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING17_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING17_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING18                              18:18
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING18_End                             18
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING18_Start                           18
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING18_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING18_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING18_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING19                              19:19
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING19_End                             19
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING19_Start                           19
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING19_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING19_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING19_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING20                              20:20
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING20_End                             20
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING20_Start                           20
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING20_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING20_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING20_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING21                              21:21
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING21_End                             21
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING21_Start                           21
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING21_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING21_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING21_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING22                              22:22
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING22_End                             22
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING22_Start                           22
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING22_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING22_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING22_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING23                              23:23
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING23_End                             23
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING23_Start                           23
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING23_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING23_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING23_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING24                              24:24
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING24_End                             24
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING24_Start                           24
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING24_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING24_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING24_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING25                              25:25
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING25_End                             25
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING25_Start                           25
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING25_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING25_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING25_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING26                              26:26
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING26_End                             26
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING26_Start                           26
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING26_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING26_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING26_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING27                              27:27
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING27_End                             27
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING27_Start                           27
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING27_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING27_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING27_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING28                              28:28
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING28_End                             28
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING28_Start                           28
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING28_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING28_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING28_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING29                              29:29
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING29_End                             29
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING29_Start                           29
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING29_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING29_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING29_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING30                              30:30
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING30_End                             30
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING30_Start                           30
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING30_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING30_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING30_HPV2                         0x1

#define MWV207REG_PS_INPUT_HPVECFMT_VARYING31                              31:31
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING31_End                             31
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING31_Start                           31
#define MWV207REG_PS_INPUT_HPVECFMT_VARYING31_Type                           U01
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING31_HPV4                         0x0
#define   MWV207REG_PS_INPUT_HPVECFMT_VARYING31_HPV2                         0x1




#define mwv207regPSOutputPrecvecfmtRegAddrs                               0x0436
#define MWV207REG_PS_OUTPUT_PRECVECFMT_Address                           0x010D8
#define MWV207REG_PS_OUTPUT_PRECVECFMT_MSB                                    15
#define MWV207REG_PS_OUTPUT_PRECVECFMT_LSB                                     0
#define MWV207REG_PS_OUTPUT_PRECVECFMT_BLK                                     0
#define MWV207REG_PS_OUTPUT_PRECVECFMT_Count                                   1
#define MWV207REG_PS_OUTPUT_PRECVECFMT_FieldMask                      0x0000FFFF
#define MWV207REG_PS_OUTPUT_PRECVECFMT_ReadMask                       0x0000FFFF
#define MWV207REG_PS_OUTPUT_PRECVECFMT_WriteMask                      0x0000FFFF
#define MWV207REG_PS_OUTPUT_PRECVECFMT_ResetValue                     0x00000000

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT0                                   1:0
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT0_End                                 1
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT0_Start                               0
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT0_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT0_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT0_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT0_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT0_MPV4                            0x3

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT1                                   3:2
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT1_End                                 3
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT1_Start                               2
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT1_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT1_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT1_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT1_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT1_MPV4                            0x3

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT2                                   5:4
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT2_End                                 5
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT2_Start                               4
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT2_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT2_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT2_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT2_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT2_MPV4                            0x3

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT3                                   7:6
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT3_End                                 7
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT3_Start                               6
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT3_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT3_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT3_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT3_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT3_MPV4                            0x3

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT4                                   9:8
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT4_End                                 9
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT4_Start                               8
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT4_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT4_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT4_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT4_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT4_MPV4                            0x3

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT5                                 11:10
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT5_End                                11
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT5_Start                              10
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT5_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT5_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT5_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT5_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT5_MPV4                            0x3

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT6                                 13:12
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT6_End                                13
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT6_Start                              12
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT6_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT6_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT6_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT6_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT6_MPV4                            0x3

#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT7                                 15:14
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT7_End                                15
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT7_Start                              14
#define MWV207REG_PS_OUTPUT_PRECVECFMT_RT7_Type                              U02
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT7_HPV4                            0x0
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT7_HPV2_V2                         0x1
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT7_HPV2_V4                         0x2
#define   MWV207REG_PS_OUTPUT_PRECVECFMT_RT7_MPV4                            0x3




#define mwv207regSHInternalControl1RegAddrs                               0x0437
#define MWV207REG_SH_INTERNAL_CONTROL1_Address                           0x010DC
#define MWV207REG_SH_INTERNAL_CONTROL1_MSB                                    15
#define MWV207REG_SH_INTERNAL_CONTROL1_LSB                                     0
#define MWV207REG_SH_INTERNAL_CONTROL1_BLK                                     0
#define MWV207REG_SH_INTERNAL_CONTROL1_Count                                   1
#define MWV207REG_SH_INTERNAL_CONTROL1_FieldMask                      0x000000BF
#define MWV207REG_SH_INTERNAL_CONTROL1_ReadMask                       0x000000BF
#define MWV207REG_SH_INTERNAL_CONTROL1_WriteMask                      0x000000BF
#define MWV207REG_SH_INTERNAL_CONTROL1_ResetValue                     0x00000020

#define MWV207REG_SH_INTERNAL_CONTROL1_SPECULATIVE_WINDOW_SIZE               5:0
#define MWV207REG_SH_INTERNAL_CONTROL1_SPECULATIVE_WINDOW_SIZE_End             5
#define MWV207REG_SH_INTERNAL_CONTROL1_SPECULATIVE_WINDOW_SIZE_Start           0
#define MWV207REG_SH_INTERNAL_CONTROL1_SPECULATIVE_WINDOW_SIZE_Type          U06

#define MWV207REG_SH_INTERNAL_CONTROL1_DISABLE_CONTEXT_TABLE_RENAME          7:7
#define MWV207REG_SH_INTERNAL_CONTROL1_DISABLE_CONTEXT_TABLE_RENAME_End        7
#define MWV207REG_SH_INTERNAL_CONTROL1_DISABLE_CONTEXT_TABLE_RENAME_Start      7
#define MWV207REG_SH_INTERNAL_CONTROL1_DISABLE_CONTEXT_TABLE_RENAME_Type     U01




#define mwv207regHWInternalControlRegAddrs                                0x0438
#define MWV207REG_HW_INTERNAL_CONTROL_Address                            0x010E0
#define MWV207REG_HW_INTERNAL_CONTROL_MSB                                     15
#define MWV207REG_HW_INTERNAL_CONTROL_LSB                                      0
#define MWV207REG_HW_INTERNAL_CONTROL_BLK                                      0
#define MWV207REG_HW_INTERNAL_CONTROL_Count                                    1
#define MWV207REG_HW_INTERNAL_CONTROL_FieldMask                       0x00000001
#define MWV207REG_HW_INTERNAL_CONTROL_ReadMask                        0x00000001
#define MWV207REG_HW_INTERNAL_CONTROL_WriteMask                       0x00000001
#define MWV207REG_HW_INTERNAL_CONTROL_ResetValue                      0x00000000


#define MWV207REG_HW_INTERNAL_CONTROL_END_OF_DRAW                            0:0
#define MWV207REG_HW_INTERNAL_CONTROL_END_OF_DRAW_End                          0
#define MWV207REG_HW_INTERNAL_CONTROL_END_OF_DRAW_Start                        0
#define MWV207REG_HW_INTERNAL_CONTROL_END_OF_DRAW_Type                       U01
#define   MWV207REG_HW_INTERNAL_CONTROL_END_OF_DRAW_DISABLE                  0x0
#define   MWV207REG_HW_INTERNAL_CONTROL_END_OF_DRAW_ENABLE                   0x1

#define mwv207regPSSampleCoverageCtrlExRegAddrs                           0x0439
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_Address                     0x010E4
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_MSB                              15
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_LSB                               0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_BLK                               0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_Count                             1
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_FieldMask                0x00000FFF
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_ReadMask                 0x00000FFF
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_WriteMask                0x00000FFF
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_ResetValue               0x00000000


#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_MASK_COVERAGE_VALUE            11:0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_MASK_COVERAGE_VALUE_End          11
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_MASK_COVERAGE_VALUE_Start         0
#define MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_MASK_COVERAGE_VALUE_Type        U12
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_MASK_COVERAGE_VALUE_ENABLE  0x001
#define   MWV207REG_PS_SAMPLE_COVERAGE_CTRL_EX_MASK_COVERAGE_VALUE_DISABLE 0x000





#define mwv207regVSPosOnlyStartPCRegAddrs                                 0x5500
#define MWV207REG_VS_POS_ONLY_START_PC_Address                           0x15400
#define MWV207REG_VS_POS_ONLY_START_PC_MSB                                    15
#define MWV207REG_VS_POS_ONLY_START_PC_LSB                                     0
#define MWV207REG_VS_POS_ONLY_START_PC_BLK                                     0
#define MWV207REG_VS_POS_ONLY_START_PC_Count                                   1
#define MWV207REG_VS_POS_ONLY_START_PC_FieldMask                      0x000FFFFF
#define MWV207REG_VS_POS_ONLY_START_PC_ReadMask                       0x000FFFFF
#define MWV207REG_VS_POS_ONLY_START_PC_WriteMask                      0x000FFFFF
#define MWV207REG_VS_POS_ONLY_START_PC_ResetValue                     0x00000000


#define MWV207REG_VS_POS_ONLY_START_PC_PC                                   19:0
#define MWV207REG_VS_POS_ONLY_START_PC_PC_End                                 19
#define MWV207REG_VS_POS_ONLY_START_PC_PC_Start                                0
#define MWV207REG_VS_POS_ONLY_START_PC_PC_Type                               U20



#define mwv207regVSPosOnlyEndPCRegAddrs                                   0x5501
#define MWV207REG_VS_POS_ONLY_END_PC_Address                             0x15404
#define MWV207REG_VS_POS_ONLY_END_PC_MSB                                      15
#define MWV207REG_VS_POS_ONLY_END_PC_LSB                                       0
#define MWV207REG_VS_POS_ONLY_END_PC_BLK                                       0
#define MWV207REG_VS_POS_ONLY_END_PC_Count                                     1
#define MWV207REG_VS_POS_ONLY_END_PC_FieldMask                        0x000FFFFF
#define MWV207REG_VS_POS_ONLY_END_PC_ReadMask                         0x000FFFFF
#define MWV207REG_VS_POS_ONLY_END_PC_WriteMask                        0x000FFFFF
#define MWV207REG_VS_POS_ONLY_END_PC_ResetValue                       0x00000000


#define MWV207REG_VS_POS_ONLY_END_PC_PC                                     19:0
#define MWV207REG_VS_POS_ONLY_END_PC_PC_End                                   19
#define MWV207REG_VS_POS_ONLY_END_PC_PC_Start                                  0
#define MWV207REG_VS_POS_ONLY_END_PC_PC_Type                                 U20




#define mwv207regVSPosOnlyInstructionRegAddrs                             0x5502
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_Address                        0x15408
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_MSB                                 15
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_LSB                                  0
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_BLK                                  0
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_Count                                1
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_FieldMask                   0xFFFFFFFF
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_ReadMask                    0xFFFFFF00
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_WriteMask                   0xFFFFFF00
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_ResetValue                  0x00000000


#define MWV207REG_VS_POS_ONLY_INSTRUCTION_ADDRESS                           31:0
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_ADDRESS_End                         31
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_ADDRESS_Start                        0
#define MWV207REG_VS_POS_ONLY_INSTRUCTION_ADDRESS_Type                       U32



#define mwv207regVSPosOnlyPrefetchRegAddrs                                0x5503
#define MWV207REG_VS_POS_ONLY_PREFETCH_Address                           0x1540C
#define MWV207REG_VS_POS_ONLY_PREFETCH_MSB                                    15
#define MWV207REG_VS_POS_ONLY_PREFETCH_LSB                                     0
#define MWV207REG_VS_POS_ONLY_PREFETCH_BLK                                     0
#define MWV207REG_VS_POS_ONLY_PREFETCH_Count                                   1
#define MWV207REG_VS_POS_ONLY_PREFETCH_FieldMask                      0x000FFFFF
#define MWV207REG_VS_POS_ONLY_PREFETCH_ReadMask                       0x000FFFFF
#define MWV207REG_VS_POS_ONLY_PREFETCH_WriteMask                      0x000FFFFF
#define MWV207REG_VS_POS_ONLY_PREFETCH_ResetValue                     0x00000000


#define MWV207REG_VS_POS_ONLY_PREFETCH_PC                                   19:0
#define MWV207REG_VS_POS_ONLY_PREFETCH_PC_End                                 19
#define MWV207REG_VS_POS_ONLY_PREFETCH_PC_Start                                0
#define MWV207REG_VS_POS_ONLY_PREFETCH_PC_Type                               U20



#define mwv207regVSPosOnlyPrefetchEndRegAddrs                             0x5504
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_Address                       0x15410
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_MSB                                15
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_LSB                                 0
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_BLK                                 0
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_Count                               1
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_FieldMask                  0x000FFFFF
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_ReadMask                   0x000FFFFF
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_WriteMask                  0x000FFFFF
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_ResetValue                 0x00000000


#define MWV207REG_VS_POS_ONLY_PREFETCH_END_PC                               19:0
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_PC_End                             19
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_PC_Start                            0
#define MWV207REG_VS_POS_ONLY_PREFETCH_END_PC_Type                           U20




#define mwv207regVSPosOnlyControlRegAddrs                                 0x5505
#define MWV207REG_VS_POS_ONLY_CONTROL_Address                            0x15414
#define MWV207REG_VS_POS_ONLY_CONTROL_MSB                                     15
#define MWV207REG_VS_POS_ONLY_CONTROL_LSB                                      0
#define MWV207REG_VS_POS_ONLY_CONTROL_BLK                                      0
#define MWV207REG_VS_POS_ONLY_CONTROL_Count                                    1
#define MWV207REG_VS_POS_ONLY_CONTROL_FieldMask                       0x3F3F17F1
#define MWV207REG_VS_POS_ONLY_CONTROL_ReadMask                        0x3F3F17F1
#define MWV207REG_VS_POS_ONLY_CONTROL_WriteMask                       0x3F3F17F1
#define MWV207REG_VS_POS_ONLY_CONTROL_ResetValue                      0x00000000


#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE                                 0:0
#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_End                               0
#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_Start                             0
#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_Type                            U01

#define   MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_BYPASS                        0x0

#define   MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_ENABLE                        0x1

#define MWV207REG_VS_POS_ONLY_CONTROL_TEMP_COUNT                            10:4
#define MWV207REG_VS_POS_ONLY_CONTROL_TEMP_COUNT_End                          10
#define MWV207REG_VS_POS_ONLY_CONTROL_TEMP_COUNT_Start                         4
#define MWV207REG_VS_POS_ONLY_CONTROL_TEMP_COUNT_Type                        U07


#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_ID                            12:12
#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_ID_End                           12
#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_ID_Start                         12
#define MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_ID_Type                         U01

#define   MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_ID_DISABLE                    0x0

#define   MWV207REG_VS_POS_ONLY_CONTROL_ENABLE_ID_ENABLE                     0x1


#define MWV207REG_VS_POS_ONLY_CONTROL_POSITION                             21:16
#define MWV207REG_VS_POS_ONLY_CONTROL_POSITION_End                            21
#define MWV207REG_VS_POS_ONLY_CONTROL_POSITION_Start                          16
#define MWV207REG_VS_POS_ONLY_CONTROL_POSITION_Type                          U06


#define MWV207REG_VS_POS_ONLY_CONTROL_ID                                   29:24
#define MWV207REG_VS_POS_ONLY_CONTROL_ID_End                                  29
#define MWV207REG_VS_POS_ONLY_CONTROL_ID_Start                                24
#define MWV207REG_VS_POS_ONLY_CONTROL_ID_Type                                U06




#define mwv207regVSPosOnlyInputControlRegAddrs                            0x5506
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_Address                      0x15418
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_MSB                               15
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_LSB                                0
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_BLK                                0
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_Count                              1
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_FieldMask                 0x00001F1F
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_ReadMask                  0x00001F1F
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_WriteMask                 0x00001F1F
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_ResetValue                0x00000000


#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_COUNT                            4:0
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_COUNT_End                          4
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_COUNT_Start                        0
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_COUNT_Type                       U05

#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_TIMEOUT                         12:8
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_TIMEOUT_End                       12
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_TIMEOUT_Start                      8
#define MWV207REG_VS_POS_ONLY_INPUT_CONTROL_TIMEOUT_Type                     U05



#define mwv207regVSPosOnlyInputRegAddrs                                   0x5508
#define MWV207REG_VS_POS_ONLY_INPUT_Address                              0x15420
#define MWV207REG_VS_POS_ONLY_INPUT_MSB                                       15
#define MWV207REG_VS_POS_ONLY_INPUT_LSB                                        3
#define MWV207REG_VS_POS_ONLY_INPUT_BLK                                        3
#define MWV207REG_VS_POS_ONLY_INPUT_Count                                      5
#define MWV207REG_VS_POS_ONLY_INPUT_FieldMask                         0x3F3F3F3F
#define MWV207REG_VS_POS_ONLY_INPUT_ReadMask                          0x3F3F3F3F
#define MWV207REG_VS_POS_ONLY_INPUT_WriteMask                         0x3F3F3F3F
#define MWV207REG_VS_POS_ONLY_INPUT_ResetValue                        0x00000000


#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS0                                 5:0
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS0_End                               5
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS0_Start                             0
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS0_Type                            U06


#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS1                                13:8
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS1_End                              13
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS1_Start                             8
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS1_Type                            U06


#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS2                               21:16
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS2_End                              21
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS2_Start                            16
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS2_Type                            U06


#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS3                               29:24
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS3_End                              29
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS3_Start                            24
#define MWV207REG_VS_POS_ONLY_INPUT_ADDRESS3_Type                            U06



#define mwv207regVSPosOnlyUnpackRegAddrs                                  0x5507
#define MWV207REG_VS_POS_ONLY_UNPACK_Address                             0x1541C
#define MWV207REG_VS_POS_ONLY_UNPACK_MSB                                      15
#define MWV207REG_VS_POS_ONLY_UNPACK_LSB                                       0
#define MWV207REG_VS_POS_ONLY_UNPACK_BLK                                       0
#define MWV207REG_VS_POS_ONLY_UNPACK_Count                                     1
#define MWV207REG_VS_POS_ONLY_UNPACK_FieldMask                        0xFFFFFFFF
#define MWV207REG_VS_POS_ONLY_UNPACK_ReadMask                         0xFFFFFFFF
#define MWV207REG_VS_POS_ONLY_UNPACK_WriteMask                        0xFFFFFFFF
#define MWV207REG_VS_POS_ONLY_UNPACK_ResetValue                       0x00000000


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE0                              1:0
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE0_End                            1
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE0_Start                          0
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE0_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE1                              3:2
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE1_End                            3
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE1_Start                          2
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE1_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE2                              5:4
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE2_End                            5
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE2_Start                          4
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE2_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE3                              7:6
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE3_End                            7
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE3_Start                          6
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE3_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE4                              9:8
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE4_End                            9
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE4_Start                          8
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE4_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE5                            11:10
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE5_End                           11
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE5_Start                         10
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE5_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE6                            13:12
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE6_End                           13
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE6_Start                         12
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE6_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE7                            15:14
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE7_End                           15
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE7_Start                         14
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE7_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE8                            17:16
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE8_End                           17
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE8_Start                         16
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE8_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE9                            19:18
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE9_End                           19
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE9_Start                         18
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE9_Type                         U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE10                           21:20
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE10_End                          21
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE10_Start                        20
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE10_Type                        U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE11                           23:22
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE11_End                          23
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE11_Start                        22
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE11_Type                        U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE12                           25:24
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE12_End                          25
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE12_Start                        24
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE12_Type                        U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE13                           27:26
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE13_End                          27
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE13_Start                        26
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE13_Type                        U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE14                           29:28
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE14_End                          29
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE14_Start                        28
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE14_Type                        U02


#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE15                           31:30
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE15_End                          31
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE15_Start                        30
#define MWV207REG_VS_POS_ONLY_UNPACK_ATTRIBUTE15_Type                        U02



#define mwv207regVSPosOnlyAttributeBaseRegAddrs                           0x550D
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_Address                     0x15434
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_MSB                              15
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_LSB                               0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_BLK                               0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_Count                             1
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_FieldMask                0xFFFFFFFF
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_ReadMask                 0xFFFFFFC0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_WriteMask                0xFFFFFFC0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_ResetValue               0x00000000

#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_ADDRESS                        31:0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_ADDRESS_End                      31
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_ADDRESS_Start                     0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_BASE_ADDRESS_Type                    U32



#define mwv207regVSPosOnlyAttributeSizeRegAddrs                           0x550E
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_Address                     0x15438
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_MSB                              15
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_LSB                               0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_BLK                               0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_Count                             1
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_FieldMask                0x000FFFFF
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_ReadMask                 0x000FFFFF
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_WriteMask                0x000FFFFF
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_ResetValue               0x00000000

#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SIZE                           15:0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SIZE_End                         15
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SIZE_Start                        0
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SIZE_Type                       U16

#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SLICE                         19:16
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SLICE_End                        19
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SLICE_Start                      16
#define MWV207REG_VS_POS_ONLY_ATTRIBUTE_SIZE_SLICE_Type                      U04

#define mwv207regVSPosOnlyThrottleRegAddrs                                0x550F
#define MWV207REG_VS_POS_ONLY_THROTTLE_Address                           0x1543C
#define MWV207REG_VS_POS_ONLY_THROTTLE_MSB                                    15
#define MWV207REG_VS_POS_ONLY_THROTTLE_LSB                                     0
#define MWV207REG_VS_POS_ONLY_THROTTLE_BLK                                     0
#define MWV207REG_VS_POS_ONLY_THROTTLE_Count                                   1
#define MWV207REG_VS_POS_ONLY_THROTTLE_FieldMask                      0xFFF7F1FF
#define MWV207REG_VS_POS_ONLY_THROTTLE_ReadMask                       0xFFF7F1FF
#define MWV207REG_VS_POS_ONLY_THROTTLE_WriteMask                      0xFFF7F1FF
#define MWV207REG_VS_POS_ONLY_THROTTLE_ResetValue                     0x00000000


#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_VERTICES                          8:0
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_VERTICES_End                        8
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_VERTICES_Start                      0
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_VERTICES_Type                     U09


#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_THREADS                         18:12
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_THREADS_End                        18
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_THREADS_Start                      12
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_THREADS_Type                      U07

#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_LINES                           31:20
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_LINES_End                          31
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_LINES_Start                        20
#define MWV207REG_VS_POS_ONLY_THROTTLE_MAX_LINES_Type                        U12





#define mwv207regShaderMiscConfigRegAddrs                                 0x5580
#define MWV207REG_SHADER_MISC_CONFIG_Address                             0x15600
#define MWV207REG_SHADER_MISC_CONFIG_MSB                                      15
#define MWV207REG_SHADER_MISC_CONFIG_LSB                                       0
#define MWV207REG_SHADER_MISC_CONFIG_BLK                                       0
#define MWV207REG_SHADER_MISC_CONFIG_Count                                     1
#define MWV207REG_SHADER_MISC_CONFIG_FieldMask                        0x000007FF
#define MWV207REG_SHADER_MISC_CONFIG_ReadMask                         0x000007FF
#define MWV207REG_SHADER_MISC_CONFIG_WriteMask                        0x000007FF
#define MWV207REG_SHADER_MISC_CONFIG_ResetValue                       0x00000000

#define MWV207REG_SHADER_MISC_CONFIG_OUT_COLOR_ROUNDING                      0:0
#define MWV207REG_SHADER_MISC_CONFIG_OUT_COLOR_ROUNDING_End                    0
#define MWV207REG_SHADER_MISC_CONFIG_OUT_COLOR_ROUNDING_Start                  0
#define MWV207REG_SHADER_MISC_CONFIG_OUT_COLOR_ROUNDING_Type                 U01
#define   MWV207REG_SHADER_MISC_CONFIG_OUT_COLOR_ROUNDING_DISABLE            0x0
#define   MWV207REG_SHADER_MISC_CONFIG_OUT_COLOR_ROUNDING_ENABLE             0x1


#define MWV207REG_SHADER_MISC_CONFIG_RTNE_ROUNDING                           1:1
#define MWV207REG_SHADER_MISC_CONFIG_RTNE_ROUNDING_End                         1
#define MWV207REG_SHADER_MISC_CONFIG_RTNE_ROUNDING_Start                       1
#define MWV207REG_SHADER_MISC_CONFIG_RTNE_ROUNDING_Type                      U01
#define   MWV207REG_SHADER_MISC_CONFIG_RTNE_ROUNDING_DISABLE                 0x0
#define   MWV207REG_SHADER_MISC_CONFIG_RTNE_ROUNDING_ENABLE                  0x1


#define MWV207REG_SHADER_MISC_CONFIG_PS_PRECISION                            2:2
#define MWV207REG_SHADER_MISC_CONFIG_PS_PRECISION_End                          2
#define MWV207REG_SHADER_MISC_CONFIG_PS_PRECISION_Start                        2
#define MWV207REG_SHADER_MISC_CONFIG_PS_PRECISION_Type                       U01

#define   MWV207REG_SHADER_MISC_CONFIG_PS_PRECISION_HIGH                     0x0

#define   MWV207REG_SHADER_MISC_CONFIG_PS_PRECISION_MEDIUM                   0x1


#define MWV207REG_SHADER_MISC_CONFIG_CONVERT_NAN                             3:3
#define MWV207REG_SHADER_MISC_CONFIG_CONVERT_NAN_End                           3
#define MWV207REG_SHADER_MISC_CONFIG_CONVERT_NAN_Start                         3
#define MWV207REG_SHADER_MISC_CONFIG_CONVERT_NAN_Type                        U01

#define   MWV207REG_SHADER_MISC_CONFIG_CONVERT_NAN_ZERO                      0x0
#define   MWV207REG_SHADER_MISC_CONFIG_CONVERT_NAN_INFINITY                  0x1

#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_OFFSET_SHIFT                7:4
#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_OFFSET_SHIFT_End              7
#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_OFFSET_SHIFT_Start            4
#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_OFFSET_SHIFT_Type           U04

#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_INDEX_STRIDE                9:8
#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_INDEX_STRIDE_End              9
#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_INDEX_STRIDE_Start            8
#define MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_INDEX_STRIDE_Type           U02

#define   MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_INDEX_STRIDE_COMPATIBLE   0x0

#define   MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_INDEX_STRIDE_ADAPTIVE     0x1

#define   MWV207REG_SHADER_MISC_CONFIG_LS_RELATIVE_INDEX_STRIDE_BYTE         0x2


#define MWV207REG_SHADER_MISC_CONFIG_PIXEL_OVERLAP_INTERLOCK               10:10
#define MWV207REG_SHADER_MISC_CONFIG_PIXEL_OVERLAP_INTERLOCK_End              10
#define MWV207REG_SHADER_MISC_CONFIG_PIXEL_OVERLAP_INTERLOCK_Start            10
#define MWV207REG_SHADER_MISC_CONFIG_PIXEL_OVERLAP_INTERLOCK_Type            U01
#define   MWV207REG_SHADER_MISC_CONFIG_PIXEL_OVERLAP_INTERLOCK_ENABLE        0x1
#define   MWV207REG_SHADER_MISC_CONFIG_PIXEL_OVERLAP_INTERLOCK_DISABLE       0x0



#define mwv207regVSInstructionPrefetchRelativeEndRegAddrs                 0x5581
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_Address           0x15604
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_MSB                    15
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_LSB                     0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_BLK                     0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_Count                   1
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_FieldMask      0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_ReadMask       0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_WriteMask      0x000FFFFF
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_ResetValue     0x00000000

#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_PC                   19:0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_End                 19
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Start                0
#define MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END_PC_Type               U20




#define mwv207regVSThrottleExRegAddrs                                     0x5582
#define MWV207REG_VS_THROTTLE_EX_Address                                 0x15608
#define MWV207REG_VS_THROTTLE_EX_MSB                                          15
#define MWV207REG_VS_THROTTLE_EX_LSB                                           0
#define MWV207REG_VS_THROTTLE_EX_BLK                                           0
#define MWV207REG_VS_THROTTLE_EX_Count                                         1
#define MWV207REG_VS_THROTTLE_EX_FieldMask                            0x0000003F
#define MWV207REG_VS_THROTTLE_EX_ReadMask                             0x0000003F
#define MWV207REG_VS_THROTTLE_EX_WriteMask                            0x0000003F
#define MWV207REG_VS_THROTTLE_EX_ResetValue                           0x00000000

#define MWV207REG_VS_THROTTLE_EX_MIN_PAGES                                   5:0
#define MWV207REG_VS_THROTTLE_EX_MIN_PAGES_End                                 5
#define MWV207REG_VS_THROTTLE_EX_MIN_PAGES_Start                               0
#define MWV207REG_VS_THROTTLE_EX_MIN_PAGES_Type                              U06




#define mwv207regVSBuddyRegAddrs                                          0x5583
#define MWV207REG_VS_BUDDY_Address                                       0x1560C
#define MWV207REG_VS_BUDDY_MSB                                                15
#define MWV207REG_VS_BUDDY_LSB                                                 0
#define MWV207REG_VS_BUDDY_BLK                                                 0
#define MWV207REG_VS_BUDDY_Count                                               1
#define MWV207REG_VS_BUDDY_FieldMask                                  0x0000003F
#define MWV207REG_VS_BUDDY_ReadMask                                   0x0000003F
#define MWV207REG_VS_BUDDY_WriteMask                                  0x0000003F
#define MWV207REG_VS_BUDDY_ResetValue                                 0x00000000


#define MWV207REG_VS_BUDDY_GRPSIZE_M1                                        5:0
#define MWV207REG_VS_BUDDY_GRPSIZE_M1_End                                      5
#define MWV207REG_VS_BUDDY_GRPSIZE_M1_Start                                    0
#define MWV207REG_VS_BUDDY_GRPSIZE_M1_Type                                   U06




#define mwv207regTCSBuddyRegAddrs                                         0x5584
#define MWV207REG_TCS_BUDDY_Address                                      0x15610
#define MWV207REG_TCS_BUDDY_MSB                                               15
#define MWV207REG_TCS_BUDDY_LSB                                                0
#define MWV207REG_TCS_BUDDY_BLK                                                0
#define MWV207REG_TCS_BUDDY_Count                                              1
#define MWV207REG_TCS_BUDDY_FieldMask                                 0x0000003F
#define MWV207REG_TCS_BUDDY_ReadMask                                  0x0000003F
#define MWV207REG_TCS_BUDDY_WriteMask                                 0x0000003F
#define MWV207REG_TCS_BUDDY_ResetValue                                0x00000000


#define MWV207REG_TCS_BUDDY_GRPSIZE_M1                                       5:0
#define MWV207REG_TCS_BUDDY_GRPSIZE_M1_End                                     5
#define MWV207REG_TCS_BUDDY_GRPSIZE_M1_Start                                   0
#define MWV207REG_TCS_BUDDY_GRPSIZE_M1_Type                                  U06




#define mwv207regTESBuddyRegAddrs                                         0x5585
#define MWV207REG_TES_BUDDY_Address                                      0x15614
#define MWV207REG_TES_BUDDY_MSB                                               15
#define MWV207REG_TES_BUDDY_LSB                                                0
#define MWV207REG_TES_BUDDY_BLK                                                0
#define MWV207REG_TES_BUDDY_Count                                              1
#define MWV207REG_TES_BUDDY_FieldMask                                 0x0000003F
#define MWV207REG_TES_BUDDY_ReadMask                                  0x0000003F
#define MWV207REG_TES_BUDDY_WriteMask                                 0x0000003F
#define MWV207REG_TES_BUDDY_ResetValue                                0x00000000


#define MWV207REG_TES_BUDDY_GRPSIZE_M1                                       5:0
#define MWV207REG_TES_BUDDY_GRPSIZE_M1_End                                     5
#define MWV207REG_TES_BUDDY_GRPSIZE_M1_Start                                   0
#define MWV207REG_TES_BUDDY_GRPSIZE_M1_Type                                  U06




#define mwv207regGSBuddyRegAddrs                                          0x5586
#define MWV207REG_GS_BUDDY_Address                                       0x15618
#define MWV207REG_GS_BUDDY_MSB                                                15
#define MWV207REG_GS_BUDDY_LSB                                                 0
#define MWV207REG_GS_BUDDY_BLK                                                 0
#define MWV207REG_GS_BUDDY_Count                                               1
#define MWV207REG_GS_BUDDY_FieldMask                                  0x0000003F
#define MWV207REG_GS_BUDDY_ReadMask                                   0x0000003F
#define MWV207REG_GS_BUDDY_WriteMask                                  0x0000003F
#define MWV207REG_GS_BUDDY_ResetValue                                 0x00000000


#define MWV207REG_GS_BUDDY_GRPSIZE_M1                                        5:0
#define MWV207REG_GS_BUDDY_GRPSIZE_M1_End                                      5
#define MWV207REG_GS_BUDDY_GRPSIZE_M1_Start                                    0
#define MWV207REG_GS_BUDDY_GRPSIZE_M1_Type                                   U06




#define mwv207regPSBuddyRegAddrs                                          0x5587
#define MWV207REG_PS_BUDDY_Address                                       0x1561C
#define MWV207REG_PS_BUDDY_MSB                                                15
#define MWV207REG_PS_BUDDY_LSB                                                 0
#define MWV207REG_PS_BUDDY_BLK                                                 0
#define MWV207REG_PS_BUDDY_Count                                               1
#define MWV207REG_PS_BUDDY_FieldMask                                  0x0000003F
#define MWV207REG_PS_BUDDY_ReadMask                                   0x0000003F
#define MWV207REG_PS_BUDDY_WriteMask                                  0x0000003F
#define MWV207REG_PS_BUDDY_ResetValue                                 0x00000000


#define MWV207REG_PS_BUDDY_GRPSIZE_M1                                        5:0
#define MWV207REG_PS_BUDDY_GRPSIZE_M1_End                                      5
#define MWV207REG_PS_BUDDY_GRPSIZE_M1_Start                                    0
#define MWV207REG_PS_BUDDY_GRPSIZE_M1_Type                                   U06




#define mwv207regVSLsAllocRegAddrs                                        0x5588
#define MWV207REG_VS_LS_ALLOC_Address                                    0x15620
#define MWV207REG_VS_LS_ALLOC_MSB                                             15
#define MWV207REG_VS_LS_ALLOC_LSB                                              0
#define MWV207REG_VS_LS_ALLOC_BLK                                              0
#define MWV207REG_VS_LS_ALLOC_Count                                            1
#define MWV207REG_VS_LS_ALLOC_FieldMask                               0x0000FFFF
#define MWV207REG_VS_LS_ALLOC_ReadMask                                0x0000FFFF
#define MWV207REG_VS_LS_ALLOC_WriteMask                               0x0000FFFF
#define MWV207REG_VS_LS_ALLOC_ResetValue                              0x00000000

#define MWV207REG_VS_LS_ALLOC_COUNT                                         15:0
#define MWV207REG_VS_LS_ALLOC_COUNT_End                                       15
#define MWV207REG_VS_LS_ALLOC_COUNT_Start                                      0
#define MWV207REG_VS_LS_ALLOC_COUNT_Type                                     U16




#define mwv207regTCSLsAllocRegAddrs                                       0x5589
#define MWV207REG_TCS_LS_ALLOC_Address                                   0x15624
#define MWV207REG_TCS_LS_ALLOC_MSB                                            15
#define MWV207REG_TCS_LS_ALLOC_LSB                                             0
#define MWV207REG_TCS_LS_ALLOC_BLK                                             0
#define MWV207REG_TCS_LS_ALLOC_Count                                           1
#define MWV207REG_TCS_LS_ALLOC_FieldMask                              0x0000FFFF
#define MWV207REG_TCS_LS_ALLOC_ReadMask                               0x0000FFFF
#define MWV207REG_TCS_LS_ALLOC_WriteMask                              0x0000FFFF
#define MWV207REG_TCS_LS_ALLOC_ResetValue                             0x00000000

#define MWV207REG_TCS_LS_ALLOC_COUNT                                        15:0
#define MWV207REG_TCS_LS_ALLOC_COUNT_End                                      15
#define MWV207REG_TCS_LS_ALLOC_COUNT_Start                                     0
#define MWV207REG_TCS_LS_ALLOC_COUNT_Type                                    U16




#define mwv207regTESLsAllocRegAddrs                                       0x558A
#define MWV207REG_TES_LS_ALLOC_Address                                   0x15628
#define MWV207REG_TES_LS_ALLOC_MSB                                            15
#define MWV207REG_TES_LS_ALLOC_LSB                                             0
#define MWV207REG_TES_LS_ALLOC_BLK                                             0
#define MWV207REG_TES_LS_ALLOC_Count                                           1
#define MWV207REG_TES_LS_ALLOC_FieldMask                              0x0000FFFF
#define MWV207REG_TES_LS_ALLOC_ReadMask                               0x0000FFFF
#define MWV207REG_TES_LS_ALLOC_WriteMask                              0x0000FFFF
#define MWV207REG_TES_LS_ALLOC_ResetValue                             0x00000000

#define MWV207REG_TES_LS_ALLOC_COUNT                                        15:0
#define MWV207REG_TES_LS_ALLOC_COUNT_End                                      15
#define MWV207REG_TES_LS_ALLOC_COUNT_Start                                     0
#define MWV207REG_TES_LS_ALLOC_COUNT_Type                                    U16




#define mwv207regGSLsAllocRegAddrs                                        0x558B
#define MWV207REG_GS_LS_ALLOC_Address                                    0x1562C
#define MWV207REG_GS_LS_ALLOC_MSB                                             15
#define MWV207REG_GS_LS_ALLOC_LSB                                              0
#define MWV207REG_GS_LS_ALLOC_BLK                                              0
#define MWV207REG_GS_LS_ALLOC_Count                                            1
#define MWV207REG_GS_LS_ALLOC_FieldMask                               0x0000FFFF
#define MWV207REG_GS_LS_ALLOC_ReadMask                                0x0000FFFF
#define MWV207REG_GS_LS_ALLOC_WriteMask                               0x0000FFFF
#define MWV207REG_GS_LS_ALLOC_ResetValue                              0x00000000

#define MWV207REG_GS_LS_ALLOC_COUNT                                         15:0
#define MWV207REG_GS_LS_ALLOC_COUNT_End                                       15
#define MWV207REG_GS_LS_ALLOC_COUNT_Start                                      0
#define MWV207REG_GS_LS_ALLOC_COUNT_Type                                     U16




#define mwv207regPSLsAllocRegAddrs                                        0x558C
#define MWV207REG_PS_LS_ALLOC_Address                                    0x15630
#define MWV207REG_PS_LS_ALLOC_MSB                                             15
#define MWV207REG_PS_LS_ALLOC_LSB                                              0
#define MWV207REG_PS_LS_ALLOC_BLK                                              0
#define MWV207REG_PS_LS_ALLOC_Count                                            1
#define MWV207REG_PS_LS_ALLOC_FieldMask                               0x0000FFFF
#define MWV207REG_PS_LS_ALLOC_ReadMask                                0x0000FFFF
#define MWV207REG_PS_LS_ALLOC_WriteMask                               0x0000FFFF
#define MWV207REG_PS_LS_ALLOC_ResetValue                              0x00000000

#define MWV207REG_PS_LS_ALLOC_COUNT                                         15:0
#define MWV207REG_PS_LS_ALLOC_COUNT_End                                       15
#define MWV207REG_PS_LS_ALLOC_COUNT_Start                                      0
#define MWV207REG_PS_LS_ALLOC_COUNT_Type                                     U16




#define mwv207regVSAttributeGlobalControlRegAddrs                         0x558D
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_Address                    0x15634
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MSB                             15
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_LSB                              0
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_BLK                              0
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_Count                            1
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_FieldMask               0xFFFFF0F1
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ReadMask                0xFFFFF0F1
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_WriteMask               0xFFFFF0F1
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ResetValue              0x00000000


#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM               0:0
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_End             0
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Start           0
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_Type          U01
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_DISABLED    0x0
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_ATTRIBUTE_IN_MEM_ENABLED     0x1


#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER           7:4
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_End         7
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Start       4
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_Type      U04
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS1K    0x0
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS2K    0x1
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS4K    0x2
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS8K    0x3
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS16K   0x4
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS32K   0x5
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS64K   0x6
#define   MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_MEM_SIZE_PER_CLUSTER_IS128K  0x7


#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR                    31:12
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_End                   31
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Start                 12
#define MWV207REG_VS_ATTRIBUTE_GLOBAL_CONTROL_BASE_ADDR_Type                 U20


#define mwv207regPSTransferDescriptor0RegAddrs                            0x7800
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_Address                        0x1E000
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_FieldMask                   0x0000FFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_ReadMask                    0x0000FFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_WriteMask                   0x0000FFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_START                 4:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_START_End               4
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_START_Start             0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_START_Type            U05


#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_END                   9:5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_END_End                 9
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_END_Start               5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_SHADER_GROUP_END_Type              U05


#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_LAST_ACTIVE_SHADER_GROUP         14:10
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_LAST_ACTIVE_SHADER_GROUP_End        14
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_LAST_ACTIVE_SHADER_GROUP_Start      10
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_LAST_ACTIVE_SHADER_GROUP_Type      U05

#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_TILE_MODE                        15:15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_TILE_MODE_End                       15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_TILE_MODE_Start                     15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR0_TILE_MODE_Type                     U01
#define   MWV207REG_PS_TRANSFER_DESCRIPTOR0_TILE_MODE_ROW_MODE               0x0
#define   MWV207REG_PS_TRANSFER_DESCRIPTOR0_TILE_MODE_TILE_MODE              0x1

#define mwv207regPSTransferDescriptor1RegAddrs                            0x7820
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_Address                        0x1E080
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_FieldMask                   0x3FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ReadMask                    0x3FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_WriteMask                   0x3FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_DATA_SIZE_MINUS_ONE                1:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_DATA_SIZE_MINUS_ONE_End              1
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_DATA_SIZE_MINUS_ONE_Start            0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_DATA_SIZE_MINUS_ONE_Type           U02


#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_XSIZE_BYTES_MINUS_ONE       5:2
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_XSIZE_BYTES_MINUS_ONE_End     5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_XSIZE_BYTES_MINUS_ONE_Start   2
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_XSIZE_BYTES_MINUS_ONE_Type  U04


#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_YSIZE_ROWS_MINUS_ONE        9:6
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_YSIZE_ROWS_MINUS_ONE_End      9
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_YSIZE_ROWS_MINUS_ONE_Start    6
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_ACCESS_YSIZE_ROWS_MINUS_ONE_Type   U04


#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_XDISTANCE_BYTES           13:10
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_XDISTANCE_BYTES_End          13
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_XDISTANCE_BYTES_Start        10
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_XDISTANCE_BYTES_Type        U04


#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_YDISTANCE_ROWS            29:14
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_YDISTANCE_ROWS_End           29
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_YDISTANCE_ROWS_Start         14
#define MWV207REG_PS_TRANSFER_DESCRIPTOR1_THREAD_YDISTANCE_ROWS_Type         U16

#define mwv207regPSTransferDescriptor2RegAddrs                            0x7840
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_Address                        0x1E100
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_FieldMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_ReadMask                    0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_WriteMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_XSIZE_THREADS                9:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_XSIZE_THREADS_End              9
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_XSIZE_THREADS_Start            0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_XSIZE_THREADS_Type           U10


#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_YSIZE_ROWS_MINUS_ONE       19:10
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_YSIZE_ROWS_MINUS_ONE_End      19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_YSIZE_ROWS_MINUS_ONE_Start    10
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_GROUP_YSIZE_ROWS_MINUS_ONE_Type    U10


#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_RECIPROCAL_GROUP_XSIZE_THREADS   31:20
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_RECIPROCAL_GROUP_XSIZE_THREADS_End  31
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_RECIPROCAL_GROUP_XSIZE_THREADS_Start 20
#define MWV207REG_PS_TRANSFER_DESCRIPTOR2_RECIPROCAL_GROUP_XSIZE_THREADS_Type U12

#define mwv207regPSTransferDescriptor3RegAddrs                            0x7860
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_Address                        0x1E180
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_FieldMask                   0x0FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_ReadMask                    0x0FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_WriteMask                   0x0FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_STEP_BYTES         19:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_STEP_BYTES_End       19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_STEP_BYTES_Start      0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_STEP_BYTES_Type     U20


#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_MAXCOUNT_STEPS    27:20
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_MAXCOUNT_STEPS_End   27
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_MAXCOUNT_STEPS_Start 20
#define MWV207REG_PS_TRANSFER_DESCRIPTOR3_SEQUENCE_XJUMP_MAXCOUNT_STEPS_Type U08

#define mwv207regPSTransferDescriptor4RegAddrs                            0x7880
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_Address                        0x1E200
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_FieldMask                   0x1FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_ReadMask                    0x1FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_WriteMask                   0x1FFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_STEP_ROWS           4:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_STEP_ROWS_End         4
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_STEP_ROWS_Start       0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_STEP_ROWS_Type      U05


#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_MAXCOUNT_ROWS      12:5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_MAXCOUNT_ROWS_End    12
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_MAXCOUNT_ROWS_Start   5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_SEQUENCE_YJUMP_MAXCOUNT_ROWS_Type  U08


#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_IMAGE_YSIZE_ROWS                 28:13
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_IMAGE_YSIZE_ROWS_End                28
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_IMAGE_YSIZE_ROWS_Start              13
#define MWV207REG_PS_TRANSFER_DESCRIPTOR4_IMAGE_YSIZE_ROWS_Type              U16

#define mwv207regPSTransferDescriptor5RegAddrs                            0x78A0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_Address                        0x1E280
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_FieldMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_ReadMask                    0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WriteMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_STEP_BYTES          19:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_STEP_BYTES_End        19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_STEP_BYTES_Start       0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_STEP_BYTES_Type      U20


#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_MAXCOUNT_STEPS     27:20
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_MAXCOUNT_STEPS_End    27
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_MAXCOUNT_STEPS_Start  20
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_XSLIDE_MAXCOUNT_STEPS_Type  U08


#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_YSLIDE_STEP_ROWS          31:28
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_YSLIDE_STEP_ROWS_End         31
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_YSLIDE_STEP_ROWS_Start       28
#define MWV207REG_PS_TRANSFER_DESCRIPTOR5_WINDOW_YSLIDE_STEP_ROWS_Type       U04

#define mwv207regPSTransferDescriptor6RegAddrs                            0x78C0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_Address                        0x1E300
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_FieldMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_ReadMask                    0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WriteMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSLIDE_MAXCOUNT_ROWS       15:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSLIDE_MAXCOUNT_ROWS_End     15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSLIDE_MAXCOUNT_ROWS_Start    0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSLIDE_MAXCOUNT_ROWS_Type   U16


#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSIZE_ROWS                31:16
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSIZE_ROWS_End               31
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSIZE_ROWS_Start             16
#define MWV207REG_PS_TRANSFER_DESCRIPTOR6_WINDOW_YSIZE_ROWS_Type             U16

#define mwv207regPSTransferDescriptor7RegAddrs                            0x78E0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_Address                        0x1E380
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_FieldMask                   0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_ReadMask                    0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_WriteMask                   0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_IMAGE_XSIZE_BYTES                 19:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_IMAGE_XSIZE_BYTES_End               19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_IMAGE_XSIZE_BYTES_Start              0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR7_IMAGE_XSIZE_BYTES_Type             U20

#define mwv207regPSTransferDescriptor8RegAddrs                            0x7900
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_Address                        0x1E400
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_FieldMask                   0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_ReadMask                    0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_WriteMask                   0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_BUFFER_STRIDE                     19:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_BUFFER_STRIDE_End                   19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_BUFFER_STRIDE_Start                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR8_BUFFER_STRIDE_Type                 U20

#define mwv207regPSTransferDescriptor9RegAddrs                            0x7920
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_Address                        0x1E480
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_MSB                                 15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_LSB                                  5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_BLK                                  0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_Count                               32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_FieldMask                   0x001FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_ReadMask                    0x001FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_WriteMask                   0x001FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_ResetValue                  0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_IMAGE_XOFFSET_BYTES               20:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_IMAGE_XOFFSET_BYTES_End             20
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_IMAGE_XOFFSET_BYTES_Start            0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR9_IMAGE_XOFFSET_BYTES_Type           U21

#define mwv207regPSTransferDescriptor10RegAddrs                           0x7940
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_Address                       0x1E500
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_MSB                                15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_LSB                                 5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_BLK                                 0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_Count                              32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_FieldMask                  0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_ReadMask                   0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_WriteMask                  0x000FFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_ResetValue                 0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_YOFFSET_ROWS               16:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_YOFFSET_ROWS_End             16
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_YOFFSET_ROWS_Start            0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_YOFFSET_ROWS_Type           U17


#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_BORDER_MODE               18:17
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_BORDER_MODE_End              18
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_BORDER_MODE_Start            17
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_BORDER_MODE_Type            U02
#define   MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_BORDER_MODE_NEAREST       0x0
#define   MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_BORDER_MODE_CONSTANT      0x1
#define   MWV207REG_PS_TRANSFER_DESCRIPTOR10_IMAGE_BORDER_MODE_MIRROR        0x2

#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_BUFFER_IS_LOCAL_STORAGE         19:19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_BUFFER_IS_LOCAL_STORAGE_End        19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_BUFFER_IS_LOCAL_STORAGE_Start      19
#define MWV207REG_PS_TRANSFER_DESCRIPTOR10_BUFFER_IS_LOCAL_STORAGE_Type      U01

#define mwv207regPSTransferDescriptor11RegAddrs                           0x7960
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_Address                       0x1E580
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_MSB                                15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_LSB                                 5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_BLK                                 0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_Count                              32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_FieldMask                  0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_ReadMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_WriteMask                  0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_ResetValue                 0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_BORDER_CONSTANT                  31:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_BORDER_CONSTANT_End                31
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_BORDER_CONSTANT_Start               0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR11_BORDER_CONSTANT_Type              U32

#define mwv207regPSTransferDescriptor12RegAddrs                           0x7980
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_Address                       0x1E600
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_MSB                                15
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_LSB                                 5
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_BLK                                 0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_Count                              32
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_FieldMask                  0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_ReadMask                   0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_WriteMask                  0xFFFFFFFF
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_ResetValue                 0x00000000


#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_BUFFER_BASE_ADDRESS              31:0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_BUFFER_BASE_ADDRESS_End            31
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_BUFFER_BASE_ADDRESS_Start           0
#define MWV207REG_PS_TRANSFER_DESCRIPTOR12_BUFFER_BASE_ADDRESS_Type          U32



#define AQ_VERTEX_SHADER_PERFORMANCE_SEL                                     7:0
#define AQ_VERTEX_SHADER_PERFORMANCE_SEL_End                                   7
#define AQ_VERTEX_SHADER_PERFORMANCE_SEL_Start                                 0
#define AQ_VERTEX_SHADER_PERFORMANCE_SEL_Type                                U08
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_NONE                             0x00
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2TX_VALID__AND_READY_          0x01
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2TX_VALID__AND_READY           0x02
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2TX_VALID_AND_READY_           0x03
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2TX_VALID_AND_READY            0x04
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TX2SH_VALID__AND_READY_          0x05
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TX2SH_VALID__AND_READY           0x06
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TX2SH_VALID_AND_READY_           0x07
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TX2SH_VALID_AND_READY            0x08
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2PA_VALID__AND_READY_          0x09
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2PA_VALID__AND_READY           0x0A
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2PA_VALID_AND_READY_           0x0B
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_SH2PA_VALID_AND_READY            0x0C
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_FE2SH_VALID__AND_READY_          0x0D
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_FE2SH_VALID__AND_READY           0x0E
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_FE2SH_VALID_AND_READY_           0x0F
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_FE2SH_VALID_AND_READY            0x10
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TEXTURE_REQUEST_FIFO_ALMOST_FULL 0x11
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TEXTURE_SIDEBAND_FIFO_FULL       0x12
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TEXTURE_RETURN_CHECK_FIFO_FULL   0x13
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_STATE_LOAD_TO_DATA_WAIT_FOR_IDLE 0x14
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_DATA_TO_STATE_LOAD_WAIT_FOR_IDLE 0x15
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_STATE_LOAD_TO_DATA_TRANSITIONS   0x16
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_STATE_LOADS                      0x17
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_VERTEX_CACHE_HITS                0x18
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_VERTEX_CACHE_MISSES              0x19
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_INPUT_ATTRIBUTES                 0x1A
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_INPUT_TIMEOUTS                   0x1B
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_WRITE_GENERATE_ATTRIBUTES        0x1C
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_ALL_UNFINISHED_GROUPS_WAITING_FOR_TEXTURE 0x1D
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_PENDING_TEXTURES_WITHOUT_INSTRUCTION_EXECUTION 0x1E
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_INSTRUCTIONS_EXECUTED            0x1F
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_GROUP_INSTRUCTIONS_EXECUTED      0x20
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_OUTPUT_BUFFER_BANK_COLLISIONS    0x21
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TEXTURE_REQUEST_FIFO_LIMITED     0x22
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_GROUPS                           0x23
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_VERTICES                         0x24
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_HALF_GROUPS_OR_PAGES_IN_USE      0x25

#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_BUSY                             0x26

#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_TEXTURE_LOADS                    0x27
#define   AQ_VERTEX_SHADER_PERFORMANCE_SEL_DISCARDED_TEXTURE_LOADS          0x28



#define AQ_PIXEL_SHADER_PERFORMANCE_SEL                                      7:0
#define AQ_PIXEL_SHADER_PERFORMANCE_SEL_End                                    7
#define AQ_PIXEL_SHADER_PERFORMANCE_SEL_Start                                  0
#define AQ_PIXEL_SHADER_PERFORMANCE_SEL_Type                                 U08
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_NONE                              0x00
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_SH2PE_VALID__AND_READY_           0x01
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_SH2PE_VALID__AND_READY            0x02
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_SH2PE_VALID_AND_READY_            0x03
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_SH2PE_VALID_AND_READY             0x04
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_RA2SH_VALID__AND_READY_           0x05
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_RA2SH_VALID__AND_READY            0x06
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_RA2SH_VALID_AND_READY_            0x07
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_RA2SH_VALID_AND_READY             0x08
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_STATE_LOAD_TO_DATA_WAIT_FOR_IDLE  0x09
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_DATA_TO_STATE_LOAD_WAIT_FOR_IDLE  0x0A
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_STATE_LOAD_TO_DATA_TRANSITIONS    0x0B
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_STATE_LOADS                       0x0C
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_INPUT_ATTRIBUTES                  0x0D
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_INPUT_TIMEOUTS                    0x0E
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_WRITE_GENERATE_ATTRIBUTES         0x0F
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_INSTRUCTIONS_EXECUTED             0x10
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_GROUP_INSTRUCTIONS_EXECUTED       0x11
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_TEXTURE_REQUEST_FIFO_LIMITED      0x12
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_SHADED_PIXELS                     0x13

#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_SHADED_COVERED_PIXELS             0x14
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_TEXKILLED_PIXELS                  0x15

#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_OUTPUT_SHADED_PIXELS              0x16
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_GROUPS                            0x17

#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_DISCARDED_QUADS                   0x18
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_DISCARDED_ATTRIBUTES              0x19

#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_IDLE_DISCARDED_QUADS              0x1A

#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_IDLE_DISCARDED_ATTRIBUTES         0x1B
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_BYPASS_ATTRIBUTES                 0x1C
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_BYPASS_MODE_CYCLES                0x1D

#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_TEXTURE_LOADS                     0x1E
#define   AQ_PIXEL_SHADER_PERFORMANCE_SEL_DISCARDED_TEXTURE_LOADS           0x1F



#define AQ_CTRLFLOWBIT                                                     31:31
#define AQ_CTRLFLOWBIT_End                                                    31
#define AQ_CTRLFLOWBIT_Start                                                  31
#define AQ_CTRLFLOWBIT_Type                                                  U01
#define   AQ_CTRLFLOWBIT_DISABLE                                             0x0
#define   AQ_CTRLFLOWBIT_ENABLE                                              0x1

#define AQ_OPCODE                                                          30:26
#define AQ_OPCODE_End                                                         30
#define AQ_OPCODE_Start                                                       26
#define AQ_OPCODE_Type                                                       U05
#define   AQ_OPCODE_NOP                                                     0x00
#define   AQ_OPCODE_MOV                                                     0x01
#define   AQ_OPCODE_MOVA                                                    0x02
#define   AQ_OPCODE_CMP                                                     0x03
#define   AQ_OPCODE_ADD                                                     0x04
#define   AQ_OPCODE_MAD                                                     0x05
#define   AQ_OPCODE_MUL                                                     0x06
#define   AQ_OPCODE_RCP                                                     0x07
#define   AQ_OPCODE_RSQ                                                     0x08
#define   AQ_OPCODE_DST                                                     0x09
#define   AQ_OPCODE_LITP                                                    0x0A
#define   AQ_OPCODE_DP3                                                     0x0B
#define   AQ_OPCODE_DP4                                                     0x0C
#define   AQ_OPCODE_MIN                                                     0x0D
#define   AQ_OPCODE_MAX                                                     0x0E
#define   AQ_OPCODE_SLT                                                     0x0F
#define   AQ_OPCODE_SGE                                                     0x10
#define   AQ_OPCODE_EXP                                                     0x11
#define   AQ_OPCODE_LOG                                                     0x12
#define   AQ_OPCODE_FRC                                                     0x13
#define   AQ_OPCODE_MAXXYZ                                                  0x14
#define   AQ_OPCODE_TEXLDL                                                  0x14
#define   AQ_OPCODE_TEXKILL                                                 0x15
#define   AQ_OPCODE_TEXLD                                                   0x16
#define   AQ_OPCODE_TEXLDB                                                  0x17
#define   AQ_OPCODE_TEXLDP                                                  0x18
#define   AQ_OPCODE_TEXLDD                                                  0x19
#define   AQ_OPCODE_DSX                                                     0x1A
#define   AQ_OPCODE_DSY                                                     0x1B
#define   AQ_OPCODE_CALL                                                    0x1C
#define   AQ_OPCODE_CALLNZ                                                  0x1D
#define   AQ_OPCODE_RET                                                     0x1E
#define   AQ_OPCODE_LOOP                                                    0x03
#define   AQ_OPCODE_ENDLOOP                                                 0x04
#define   AQ_OPCODE_REP                                                     0x05
#define   AQ_OPCODE_ENDREP                                                  0x06
#define   AQ_OPCODE_IF                                                      0x07
#define   AQ_OPCODE_ELSE                                                    0x08
#define   AQ_OPCODE_ENDIF                                                   0x09
#define   AQ_OPCODE_IFC                                                     0x0A
#define   AQ_OPCODE_BREAK                                                   0x0B
#define   AQ_OPCODE_BREAKP                                                  0x0C
#define   AQ_OPCODE_BREAKC                                                  0x0D
#define   AQ_OPCODE_SETP                                                    0x0E

#define AQ_A0_ROUND                                                        24:24
#define AQ_A0_ROUND_End                                                       24
#define AQ_A0_ROUND_Start                                                     24
#define AQ_A0_ROUND_Type                                                     U01
#define   AQ_A0_ROUND_DOWN                                                   0x0
#define   AQ_A0_ROUND_UP                                                     0x1

#define AQ_DEST_ADDR_MODE                                                  23:23
#define AQ_DEST_ADDR_MODE_End                                                 23
#define AQ_DEST_ADDR_MODE_Start                                               23
#define AQ_DEST_ADDR_MODE_Type                                               U01

#define AQ_DEST_PRED_ENABLE                                                22:22
#define AQ_DEST_PRED_ENABLE_End                                               22
#define AQ_DEST_PRED_ENABLE_Start                                             22
#define AQ_DEST_PRED_ENABLE_Type                                             U01

#define AQ_DESTREG_ADR_LABEL                                               21:13
#define AQ_DESTREG_ADR_LABEL_End                                              21
#define AQ_DESTREG_ADR_LABEL_Start                                            13
#define AQ_DESTREG_ADR_LABEL_Type                                            U09

#define AQ_DESTMASK                                                         12:9
#define AQ_DESTMASK_End                                                       12
#define AQ_DESTMASK_Start                                                      9
#define AQ_DESTMASK_Type                                                     U04

#define AQ_DESTREGTYPE                                                       8:5
#define AQ_DESTREGTYPE_End                                                     8
#define AQ_DESTREGTYPE_Start                                                   5
#define AQ_DESTREGTYPE_Type                                                  U04

#define AQ_DEST_MODIFIER_BIT                                                 4:4
#define AQ_DEST_MODIFIER_BIT_End                                               4
#define AQ_DEST_MODIFIER_BIT_Start                                             4
#define AQ_DEST_MODIFIER_BIT_Type                                            U01
#define   AQ_DEST_MODIFIER_BIT_NONE                                          0x0
#define   AQ_DEST_MODIFIER_BIT_SAT                                           0x1

#define AQ_DEST_PRED_METHOD                                                  3:3
#define AQ_DEST_PRED_METHOD_End                                                3
#define AQ_DEST_PRED_METHOD_Start                                              3
#define AQ_DEST_PRED_METHOD_Type                                             U01

#define AQ_BOOL_METHOD_BIT                                                   2:2
#define AQ_BOOL_METHOD_BIT_End                                                 2
#define AQ_BOOL_METHOD_BIT_Start                                               2
#define AQ_BOOL_METHOD_BIT_Type                                              U01

#define AQ_DEST_PRED_SWIZZLE                                                 1:0
#define AQ_DEST_PRED_SWIZZLE_End                                               1
#define AQ_DEST_PRED_SWIZZLE_Start                                             0
#define AQ_DEST_PRED_SWIZZLE_Type                                            U02



#define AQ_SRC_ADRMODEBIT                                                  31:31
#define AQ_SRC_ADRMODEBIT_End                                                 31
#define AQ_SRC_ADRMODEBIT_Start                                               31
#define AQ_SRC_ADRMODEBIT_Type                                               U01
#define   AQ_SRC_ADRMODEBIT_ABSOLUTE                                         0x0
#define   AQ_SRC_ADRMODEBIT_RELATIVE                                         0x1

#define AQ_SRC_TEXLDD_SAMP_NO_LOW                                          30:28
#define AQ_SRC_TEXLDD_SAMP_NO_LOW_End                                         30
#define AQ_SRC_TEXLDD_SAMP_NO_LOW_Start                                       28
#define AQ_SRC_TEXLDD_SAMP_NO_LOW_Type                                       U03

#define AQ_SRC_REGADR                                                      27:20
#define AQ_SRC_REGADR_End                                                     27
#define AQ_SRC_REGADR_Start                                                   20
#define AQ_SRC_REGADR_Type                                                   U08

#define AQ_SRC_REGTYPE                                                     19:16
#define AQ_SRC_REGTYPE_End                                                    19
#define AQ_SRC_REGTYPE_Start                                                  16
#define AQ_SRC_REGTYPE_Type                                                  U04

#define AQ_SRC_WSWIZZLE                                                    15:14
#define AQ_SRC_WSWIZZLE_End                                                   15
#define AQ_SRC_WSWIZZLE_Start                                                 14
#define AQ_SRC_WSWIZZLE_Type                                                 U02

#define AQ_SRC_ZSWIZZLE                                                    13:12
#define AQ_SRC_ZSWIZZLE_End                                                   13
#define AQ_SRC_ZSWIZZLE_Start                                                 12
#define AQ_SRC_ZSWIZZLE_Type                                                 U02

#define AQ_SRC_YSWIZZLE                                                    11:10
#define AQ_SRC_YSWIZZLE_End                                                   11
#define AQ_SRC_YSWIZZLE_Start                                                 10
#define AQ_SRC_YSWIZZLE_Type                                                 U02

#define AQ_SRC_XSWIZZLE                                                      9:8
#define AQ_SRC_XSWIZZLE_End                                                    9
#define AQ_SRC_XSWIZZLE_Start                                                  8
#define AQ_SRC_XSWIZZLE_Type                                                 U02

#define AQ_SRC_MODIFIER                                                      5:4
#define AQ_SRC_MODIFIER_End                                                    5
#define AQ_SRC_MODIFIER_Start                                                  4
#define AQ_SRC_MODIFIER_Type                                                 U02
#define   AQ_SRC_MODIFIER_NONE                                               0x0
#define   AQ_SRC_MODIFIER_NEG                                                0x1

#define   AQ_SRC_MODIFIER_ABS                                                0x2

#define AQ_SRC_AL_BIT                                                        3:3
#define AQ_SRC_AL_BIT_End                                                      3
#define AQ_SRC_AL_BIT_Start                                                    3
#define AQ_SRC_AL_BIT_Type                                                   U01
#define   AQ_SRC_AL_BIT_A0                                                   0x0
#define   AQ_SRC_AL_BIT_AL                                                   0x1

#define AQ_SRC_A0_SWIZZLE                                                    2:1
#define AQ_SRC_A0_SWIZZLE_End                                                  2
#define AQ_SRC_A0_SWIZZLE_Start                                                1
#define AQ_SRC_A0_SWIZZLE_Type                                               U02

#define AQ_SRC_TEXLDD_SAMP_NO_HIGH                                           0:0
#define AQ_SRC_TEXLDD_SAMP_NO_HIGH_End                                         0
#define AQ_SRC_TEXLDD_SAMP_NO_HIGH_Start                                       0
#define AQ_SRC_TEXLDD_SAMP_NO_HIGH_Type                                      U01



#define SHADER_SRC_SWIZZLE                                                   1:0
#define SHADER_SRC_SWIZZLE_End                                                 1
#define SHADER_SRC_SWIZZLE_Start                                               0
#define SHADER_SRC_SWIZZLE_Type                                              U02
#define   SHADER_SRC_SWIZZLE_X                                               0x0
#define   SHADER_SRC_SWIZZLE_Y                                               0x1
#define   SHADER_SRC_SWIZZLE_Z                                               0x2
#define   SHADER_SRC_SWIZZLE_W                                               0x3



#define SRC_DEST_REG                                                         3:0
#define SRC_DEST_REG_End                                                       3
#define SRC_DEST_REG_Start                                                     0
#define SRC_DEST_REG_Type                                                    U04
#define   SRC_DEST_REG_COLOROUT                                              0x0
#define   SRC_DEST_REG_DEPTHOUT                                              0x1
#define   SRC_DEST_REG_TEMP                                                  0x2
#define   SRC_DEST_REG_INPUT                                                 0x3
#define   SRC_DEST_REG_INTEGER                                               0x4
#define   SRC_DEST_REG_CONST                                                 0x5
#define   SRC_DEST_REG_TEXTURE                                               0x6
#define   SRC_DEST_REG_ADDR                                                  0x6
#define   SRC_DEST_REG_RASTOUT                                               0x7
#define   SRC_DEST_REG_POSITION                                              0x7
#define   SRC_DEST_REG_ATTROUT                                               0x8
#define   SRC_DEST_REG_FACE                                                  0x8
#define   SRC_DEST_REG_TEXCRDOUT                                             0x9
#define   SRC_DEST_REG_PRED                                                  0x9
#define   SRC_DEST_REG_SAMPLER                                               0xA
#define   SRC_DEST_REG_BOOL                                                  0xB
#define   SRC_DEST_REG_VS_OUTPUT                                             0xC




#define AQ_INST_OP_CODE                                                      5:0
#define AQ_INST_OP_CODE_End                                                    5
#define AQ_INST_OP_CODE_Start                                                  0
#define AQ_INST_OP_CODE_Type                                                 U06

#define AQ_INST_CONDITION_CODE                                              10:6
#define AQ_INST_CONDITION_CODE_End                                            10
#define AQ_INST_CONDITION_CODE_Start                                           6
#define AQ_INST_CONDITION_CODE_Type                                          U05
#define   AQ_INST_CONDITION_CODE_TRUE                                       0x00
#define   AQ_INST_CONDITION_CODE_GT                                         0x01
#define   AQ_INST_CONDITION_CODE_LT                                         0x02
#define   AQ_INST_CONDITION_CODE_GE                                         0x03
#define   AQ_INST_CONDITION_CODE_LE                                         0x04
#define   AQ_INST_CONDITION_CODE_EQ                                         0x05
#define   AQ_INST_CONDITION_CODE_NE                                         0x06
#define   AQ_INST_CONDITION_CODE_AND                                        0x07
#define   AQ_INST_CONDITION_CODE_OR                                         0x08
#define   AQ_INST_CONDITION_CODE_XOR                                        0x09
#define   AQ_INST_CONDITION_CODE_NOT                                        0x0A
#define   AQ_INST_CONDITION_CODE_NZ                                         0x0B
#define   AQ_INST_CONDITION_CODE_GEZ                                        0x0C
#define   AQ_INST_CONDITION_CODE_GZ                                         0x0D
#define   AQ_INST_CONDITION_CODE_LEZ                                        0x0E
#define   AQ_INST_CONDITION_CODE_LZ                                         0x0F
#define   AQ_INST_CONDITION_CODE_FINITE                                     0x10
#define   AQ_INST_CONDITION_CODE_INFINITE                                   0x11
#define   AQ_INST_CONDITION_CODE_NAN                                        0x12
#define   AQ_INST_CONDITION_CODE_NORMAL                                     0x13
#define   AQ_INST_CONDITION_CODE_ANYMSB                                     0x14
#define   AQ_INST_CONDITION_CODE_ALLMSB                                     0x15
#define   AQ_INST_CONDITION_CODE_SELMSB                                     0x16
#define   AQ_INST_CONDITION_CODE_UCARRY                                     0x17
#define   AQ_INST_CONDITION_CODE_HELPER                                     0x18
#define   AQ_INST_CONDITION_CODE_NOTHELPER                                  0x19

#define AQ_INST_SATURATE                                                   11:11
#define AQ_INST_SATURATE_End                                                  11
#define AQ_INST_SATURATE_Start                                                11
#define AQ_INST_SATURATE_Type                                                U01
#define   AQ_INST_SATURATE_NONE                                              0x0
#define   AQ_INST_SATURATE_ZERO_TO_ONE                                       0x1

#define AQ_INST_DEST_VALID                                                 12:12
#define AQ_INST_DEST_VALID_End                                                12
#define AQ_INST_DEST_VALID_Start                                              12
#define AQ_INST_DEST_VALID_Type                                              U01

#define AQ_INST_DEST_REL_ADR                                               15:13
#define AQ_INST_DEST_REL_ADR_End                                              15
#define AQ_INST_DEST_REL_ADR_Start                                            13
#define AQ_INST_DEST_REL_ADR_Type                                            U03

#define AQ_INST_DEST_ADR                                                   22:16
#define AQ_INST_DEST_ADR_End                                                  22
#define AQ_INST_DEST_ADR_Start                                                16
#define AQ_INST_DEST_ADR_Type                                                U07

#define AQ_INST_DEST_WRITE_ENABLE                                          26:23
#define AQ_INST_DEST_WRITE_ENABLE_End                                         26
#define AQ_INST_DEST_WRITE_ENABLE_Start                                       23
#define AQ_INST_DEST_WRITE_ENABLE_Type                                       U04


#define AQ_INST_SAMPLER_NUM                                                31:27
#define AQ_INST_SAMPLER_NUM_End                                               31
#define AQ_INST_SAMPLER_NUM_Start                                             27
#define AQ_INST_SAMPLER_NUM_Type                                             U05



#define AQ_INST_SAMPLER_REL_ADR                                              2:0
#define AQ_INST_SAMPLER_REL_ADR_End                                            2
#define AQ_INST_SAMPLER_REL_ADR_Start                                          0
#define AQ_INST_SAMPLER_REL_ADR_Type                                         U03

#define AQ_INST_SAMPLER_SWIZZLE                                             10:3
#define AQ_INST_SAMPLER_SWIZZLE_End                                           10
#define AQ_INST_SAMPLER_SWIZZLE_Start                                          3
#define AQ_INST_SAMPLER_SWIZZLE_Type                                         U08

#define AQ_INST_SRC0_VALID                                                 11:11
#define AQ_INST_SRC0_VALID_End                                                11
#define AQ_INST_SRC0_VALID_Start                                              11
#define AQ_INST_SRC0_VALID_Type                                              U01

#define AQ_INST_SRC0_ADR                                                   20:12
#define AQ_INST_SRC0_ADR_End                                                  20
#define AQ_INST_SRC0_ADR_Start                                                12
#define AQ_INST_SRC0_ADR_Type                                                U09


#define AQ_INST_INST_TYPE_0                                                21:21
#define AQ_INST_INST_TYPE_0_End                                               21
#define AQ_INST_INST_TYPE_0_Start                                             21
#define AQ_INST_INST_TYPE_0_Type                                             U01

#define AQ_INST_SRC0_SWIZZLE                                               29:22
#define AQ_INST_SRC0_SWIZZLE_End                                              29
#define AQ_INST_SRC0_SWIZZLE_Start                                            22
#define AQ_INST_SRC0_SWIZZLE_Type                                            U08

#define AQ_INST_SRC0_MODIFIER_NEG                                          30:30
#define AQ_INST_SRC0_MODIFIER_NEG_End                                         30
#define AQ_INST_SRC0_MODIFIER_NEG_Start                                       30
#define AQ_INST_SRC0_MODIFIER_NEG_Type                                       U01

#define AQ_INST_SRC0_MODIFIER_ABS                                          31:31
#define AQ_INST_SRC0_MODIFIER_ABS_End                                         31
#define AQ_INST_SRC0_MODIFIER_ABS_Start                                       31
#define AQ_INST_SRC0_MODIFIER_ABS_Type                                       U01



#define AQ_INST_SRC0_REL_ADR                                                 2:0
#define AQ_INST_SRC0_REL_ADR_End                                               2
#define AQ_INST_SRC0_REL_ADR_Start                                             0
#define AQ_INST_SRC0_REL_ADR_Type                                            U03

#define AQ_INST_SRC0_TYPE                                                    5:3
#define AQ_INST_SRC0_TYPE_End                                                  5
#define AQ_INST_SRC0_TYPE_Start                                                3
#define AQ_INST_SRC0_TYPE_Type                                               U03

#define AQ_INST_SRC1_VALID                                                   6:6
#define AQ_INST_SRC1_VALID_End                                                 6
#define AQ_INST_SRC1_VALID_Start                                               6
#define AQ_INST_SRC1_VALID_Type                                              U01

#define AQ_INST_SRC1_ADR                                                    15:7
#define AQ_INST_SRC1_ADR_End                                                  15
#define AQ_INST_SRC1_ADR_Start                                                 7
#define AQ_INST_SRC1_ADR_Type                                                U09

#define AQ_INST_OP_CODE_MSB6                                               16:16
#define AQ_INST_OP_CODE_MSB6_End                                              16
#define AQ_INST_OP_CODE_MSB6_Start                                            16
#define AQ_INST_OP_CODE_MSB6_Type                                            U01

#define AQ_INST_SRC1_SWIZZLE                                               24:17
#define AQ_INST_SRC1_SWIZZLE_End                                              24
#define AQ_INST_SRC1_SWIZZLE_Start                                            17
#define AQ_INST_SRC1_SWIZZLE_Type                                            U08

#define AQ_INST_SRC1_MODIFIER_NEG                                          25:25
#define AQ_INST_SRC1_MODIFIER_NEG_End                                         25
#define AQ_INST_SRC1_MODIFIER_NEG_Start                                       25
#define AQ_INST_SRC1_MODIFIER_NEG_Type                                       U01

#define AQ_INST_SRC1_MODIFIER_ABS                                          26:26
#define AQ_INST_SRC1_MODIFIER_ABS_End                                         26
#define AQ_INST_SRC1_MODIFIER_ABS_Start                                       26
#define AQ_INST_SRC1_MODIFIER_ABS_Type                                       U01

#define AQ_INST_SRC1_REL_ADR                                               29:27
#define AQ_INST_SRC1_REL_ADR_End                                              29
#define AQ_INST_SRC1_REL_ADR_Start                                            27
#define AQ_INST_SRC1_REL_ADR_Type                                            U03


#define AQ_INST_INST_TYPE_1                                                31:30
#define AQ_INST_INST_TYPE_1_End                                               31
#define AQ_INST_INST_TYPE_1_Start                                             30
#define AQ_INST_INST_TYPE_1_Type                                             U02



#define AQ_INST_SRC1_TYPE                                                    2:0
#define AQ_INST_SRC1_TYPE_End                                                  2
#define AQ_INST_SRC1_TYPE_Start                                                0
#define AQ_INST_SRC1_TYPE_Type                                               U03

#define AQ_INST_SRC2_VALID                                                   3:3
#define AQ_INST_SRC2_VALID_End                                                 3
#define AQ_INST_SRC2_VALID_Start                                               3
#define AQ_INST_SRC2_VALID_Type                                              U01

#define AQ_INST_SRC2_ADR                                                    12:4
#define AQ_INST_SRC2_ADR_End                                                  12
#define AQ_INST_SRC2_ADR_Start                                                 4
#define AQ_INST_SRC2_ADR_Type                                                U09


#define AQ_INST_DEST_ADR_MSB7                                              13:13
#define AQ_INST_DEST_ADR_MSB7_End                                             13
#define AQ_INST_DEST_ADR_MSB7_Start                                           13
#define AQ_INST_DEST_ADR_MSB7_Type                                           U01

#define AQ_INST_SRC2_SWIZZLE                                               21:14
#define AQ_INST_SRC2_SWIZZLE_End                                              21
#define AQ_INST_SRC2_SWIZZLE_Start                                            14
#define AQ_INST_SRC2_SWIZZLE_Type                                            U08

#define AQ_INST_SRC2_MODIFIER_NEG                                          22:22
#define AQ_INST_SRC2_MODIFIER_NEG_End                                         22
#define AQ_INST_SRC2_MODIFIER_NEG_Start                                       22
#define AQ_INST_SRC2_MODIFIER_NEG_Type                                       U01

#define AQ_INST_SRC2_MODIFIER_ABS                                          23:23
#define AQ_INST_SRC2_MODIFIER_ABS_End                                         23
#define AQ_INST_SRC2_MODIFIER_ABS_Start                                       23
#define AQ_INST_SRC2_MODIFIER_ABS_Type                                       U01


#define AQ_INST_DEST_ADR_MSB8                                              24:24
#define AQ_INST_DEST_ADR_MSB8_End                                             24
#define AQ_INST_DEST_ADR_MSB8_Start                                           24
#define AQ_INST_DEST_ADR_MSB8_Type                                           U01

#define AQ_INST_SRC2_REL_ADR                                               27:25
#define AQ_INST_SRC2_REL_ADR_End                                              27
#define AQ_INST_SRC2_REL_ADR_Start                                            25
#define AQ_INST_SRC2_REL_ADR_Type                                            U03

#define AQ_INST_SRC2_TYPE                                                  30:28
#define AQ_INST_SRC2_TYPE_End                                                 30
#define AQ_INST_SRC2_TYPE_Start                                               28
#define AQ_INST_SRC2_TYPE_Type                                               U03

#define AQ_INST_DEST_SOURCE                                                31:31
#define AQ_INST_DEST_SOURCE_End                                               31
#define AQ_INST_DEST_SOURCE_Start                                             31
#define AQ_INST_DEST_SOURCE_Type                                             U01

#define   AQ_INST_DEST_SOURCE_DEFAULT                                        0x0

#define   AQ_INST_DEST_SOURCE_LOCAL                                          0x1

#define   AQ_INST_DEST_SOURCE_MEDIUMP_TEMP                                   0x0

#define   AQ_INST_DEST_SOURCE_HIGHP_TEMP                                     0x1



#define AQ_INST_SRC1_TYPE                                                    2:0
#define AQ_INST_SRC1_TYPE_End                                                  2
#define AQ_INST_SRC1_TYPE_Start                                                0
#define AQ_INST_SRC1_TYPE_Type                                               U03

#define AQ_INST_SRC2_VALID                                                   3:3
#define AQ_INST_SRC2_VALID_End                                                 3
#define AQ_INST_SRC2_VALID_Start                                               3
#define AQ_INST_SRC2_VALID_Type                                              U01

#define AQ_INST_LOOP_OP                                                      4:4
#define AQ_INST_LOOP_OP_End                                                    4
#define AQ_INST_LOOP_OP_Start                                                  4
#define AQ_INST_LOOP_OP_Type                                                 U01
#define   AQ_INST_LOOP_OP_NONE                                               0x0
#define   AQ_INST_LOOP_OP_DEALLOCATE_ON_FALSE                                0x1

#define AQ_INST_TARGET                                                      26:7
#define AQ_INST_TARGET_End                                                    26
#define AQ_INST_TARGET_Start                                                   7
#define AQ_INST_TARGET_Type                                                  U20




#define AQ_INST_TD_INDEX0                                                  31:27
#define AQ_INST_TD_INDEX0_End                                                 31
#define AQ_INST_TD_INDEX0_Start                                               27
#define AQ_INST_TD_INDEX0_Type                                               U05




#define AQ_INST_TD_OPCODE0                                                   2:0
#define AQ_INST_TD_OPCODE0_End                                                 2
#define AQ_INST_TD_OPCODE0_Start                                               0
#define AQ_INST_TD_OPCODE0_Type                                              U03
#define   AQ_INST_TD_OPCODE0_TD_NOP                                          0x0
#define   AQ_INST_TD_OPCODE0_TD_LOAD                                         0x1
#define   AQ_INST_TD_OPCODE0_TD_STORE                                        0x2
#define   AQ_INST_TD_OPCODE0_TD_BRANCH                                       0x3
#define   AQ_INST_TD_OPCODE0_TD_COPY_TO_LOCAL                                0x4
#define   AQ_INST_TD_OPCODE0_TD_COPY_TO_UNIFORM                              0x5


#define AQ_INST_TD_OPCODE1                                                   5:3
#define AQ_INST_TD_OPCODE1_End                                                 5
#define AQ_INST_TD_OPCODE1_Start                                               3
#define AQ_INST_TD_OPCODE1_Type                                              U03
#define   AQ_INST_TD_OPCODE1_TD_NOP                                          0x0
#define   AQ_INST_TD_OPCODE1_TD_LOAD                                         0x1
#define   AQ_INST_TD_OPCODE1_TD_STORE                                        0x2
#define   AQ_INST_TD_OPCODE1_TD_BRANCH                                       0x3
#define   AQ_INST_TD_OPCODE1_TD_COPY_TO_LOCAL                                0x4
#define   AQ_INST_TD_OPCODE1_TD_COPY_TO_UNIFORM                              0x5


#define AQ_INST_TD_INDEX1                                                   10:6
#define AQ_INST_TD_INDEX1_End                                                 10
#define AQ_INST_TD_INDEX1_Start                                                6
#define AQ_INST_TD_INDEX1_Type                                               U05




#define AQ_INST                                                              6:0
#define AQ_INST_End                                                            6
#define AQ_INST_Start                                                          0
#define AQ_INST_Type                                                         U07
#define   AQ_INST_OP_CODE_NOP                                               0x00
#define   AQ_INST_OP_CODE_ADD                                               0x01
#define   AQ_INST_OP_CODE_MAD                                               0x02
#define   AQ_INST_OP_CODE_MUL                                               0x03
#define   AQ_INST_OP_CODE_DST                                               0x04
#define   AQ_INST_OP_CODE_DP3                                               0x05
#define   AQ_INST_OP_CODE_DP4                                               0x06
#define   AQ_INST_OP_CODE_DSX                                               0x07
#define   AQ_INST_OP_CODE_DSY                                               0x08
#define   AQ_INST_OP_CODE_MOV                                               0x09
#define   AQ_INST_OP_CODE_MOVAR                                             0x0A
#define   AQ_INST_OP_CODE_MOVAF                                             0x0B
#define   AQ_INST_OP_CODE_RCP                                               0x0C
#define   AQ_INST_OP_CODE_RSQ                                               0x0D
#define   AQ_INST_OP_CODE_LITP                                              0x0E
#define   AQ_INST_OP_CODE_SELECT                                            0x0F
#define   AQ_INST_OP_CODE_SET                                               0x10
#define   AQ_INST_OP_CODE_EXP                                               0x11
#define   AQ_INST_OP_CODE_LOG                                               0x12
#define   AQ_INST_OP_CODE_FRC                                               0x13
#define   AQ_INST_OP_CODE_CALL                                              0x14
#define   AQ_INST_OP_CODE_RET                                               0x15
#define   AQ_INST_OP_CODE_BRANCH                                            0x16
#define   AQ_INST_OP_CODE_TEXKILL                                           0x17
#define   AQ_INST_OP_CODE_TEXLD                                             0x18
#define   AQ_INST_OP_CODE_TEXLD_B_PCF                                       0x18
#define   AQ_INST_OP_CODE_TEXLDB                                            0x19
#define   AQ_INST_OP_CODE_TEXLDD                                            0x1A
#define   AQ_INST_OP_CODE_TEXLD_G                                           0x1A
#define   AQ_INST_OP_CODE_TEXLDL                                            0x1B
#define   AQ_INST_OP_CODE_TEXLDP                                            0x1C
#define   AQ_INST_OP_CODE_TEXLDPCF                                          0x1C
#define   AQ_INST_OP_CODE_REP                                               0x1D
#define   AQ_INST_OP_CODE_ENDREP                                            0x1E
#define   AQ_INST_OP_CODE_LOOP                                              0x1F
#define   AQ_INST_OP_CODE_ENDLOOP                                           0x20
#define   AQ_INST_OP_CODE_SQRT                                              0x21
#define   AQ_INST_OP_CODE_SINXHPI                                           0x22
#define   AQ_INST_OP_CODE_COSXHPI                                           0x23
#define   AQ_INST_OP_CODE_BRANCH_ANY                                        0x24
#define   AQ_INST_OP_CODE_FLOOR                                             0x25
#define   AQ_INST_OP_CODE_CEIL                                              0x26
#define   AQ_INST_OP_CODE_SIGN                                              0x27
#define   AQ_INST_OP_CODE_ADDLO                                             0x28
#define   AQ_INST_OP_CODE_MULLO                                             0x29
#define   AQ_INST_OP_CODE_BARRIER                                           0x2A
#define   AQ_INST_OP_CODE_SWIZZLE                                           0x2B
#define   AQ_INST_OP_CODE_I2I                                               0x2C
#define   AQ_INST_OP_CODE_I2F                                               0x2D
#define   AQ_INST_OP_CODE_F2I                                               0x2E
#define   AQ_INST_OP_CODE_F2IRND                                            0x2F
#define   AQ_INST_OP_CODE_FMA                                               0x30
#define   AQ_INST_OP_CODE_CMP                                               0x31
#define   AQ_INST_OP_CODE_LOAD                                              0x32
#define   AQ_INST_OP_CODE_STORE                                             0x33
#define   AQ_INST_OP_CODE_IMG_LOAD_3D                                       0x34
#define   AQ_INST_OP_CODE_IMG_STORE_3D                                      0x35
#define   AQ_INST_OP_CODE_CLAMP0_MAX                                        0x36
#define   AQ_INST_OP_CODE_IMG_ADDR                                          0x37
#define   AQ_INST_OP_CODE_IMG_ADDR_3D                                       0x38
#define   AQ_INST_OP_CODE_LOADP                                             0x39
#define   AQ_INST_OP_CODE_STOREP                                            0x3A
#define   AQ_INST_OP_CODE_IADDSAT                                           0x3B
#define   AQ_INST_OP_CODE_IMULLO0                                           0x3C
#define   AQ_INST_OP_CODE_IMULLO1                                           0x3D
#define   AQ_INST_OP_CODE_IMULLOSAT0                                        0x3E
#define   AQ_INST_OP_CODE_IMULLOSAT1                                        0x3F
#define   AQ_INST_OP_CODE_IMULHI0                                           0x40
#define   AQ_INST_OP_CODE_IMULHI1                                           0x41
#define   AQ_INST_OP_CODE_STORE_ATTR                                        0x42
#define   AQ_INST_OP_CODE_SELECT_MAP                                        0x43
#define   AQ_INST_OP_CODE_IDIV0                                             0x44
#define   AQ_INST_OP_CODE_EVIS                                              0x45
#define   AQ_INST_OP_CODE_IMG_ATOM                                          0x46
#define   AQ_INST_OP_CODE_IMG_SLICE                                         0x46
#define   AQ_INST_OP_CODE_NEURAL_NET                                        0x47
#define   AQ_INST_OP_CODE_IMOD0                                             0x48
#define   AQ_INST_OP_CODE_TEXLD_U_S_L                                       0x49
#define   AQ_INST_OP_CODE_TEXLD_U_U_L                                       0x4A
#define   AQ_INST_OP_CODE_TEXLD_U_F_L                                       0x4B
#define   AQ_INST_OP_CODE_IMADLO0                                           0x4C
#define   AQ_INST_OP_CODE_IMADLO1                                           0x4D
#define   AQ_INST_OP_CODE_IMADLOSAT0                                        0x4E
#define   AQ_INST_OP_CODE_IMADLOSAT1                                        0x4F
#define   AQ_INST_OP_CODE_IMADHI0                                           0x50
#define   AQ_INST_OP_CODE_IMADHI1                                           0x51
#define   AQ_INST_OP_CODE_IMADHISAT0                                        0x52
#define   AQ_INST_OP_CODE_IMADHISAT1                                        0x53
#define   AQ_INST_OP_CODE_BIT_INSERT1                                       0x54
#define   AQ_INST_OP_CODE_BIT_INSERT2                                       0x55
#define   AQ_INST_OP_CODE_MOVAI                                             0x56
#define   AQ_INST_OP_CODE_IABS                                              0x57
#define   AQ_INST_OP_CODE_LEADZERO                                          0x58
#define   AQ_INST_OP_CODE_LSHIFT                                            0x59
#define   AQ_INST_OP_CODE_RSHIFT                                            0x5A
#define   AQ_INST_OP_CODE_ROTATE                                            0x5B
#define   AQ_INST_OP_CODE_OR                                                0x5C
#define   AQ_INST_OP_CODE_AND                                               0x5D
#define   AQ_INST_OP_CODE_XOR                                               0x5E
#define   AQ_INST_OP_CODE_NOT                                               0x5F
#define   AQ_INST_OP_CODE_BIT_EXTRACT                                       0x60
#define   AQ_INST_OP_CODE_POPCOUNT                                          0x61
#define   AQ_INST_OP_CODE_CMPLX                                             0x62
#define   AQ_INST_OP_CODE_ARCTRIG                                           0x63
#define   AQ_INST_OP_CODE_DIV                                               0x64
#define   AQ_INST_OP_CODE_ATOM_ADD                                          0x65
#define   AQ_INST_OP_CODE_ATOM_XCHG                                         0x66
#define   AQ_INST_OP_CODE_ATOM_CMP_XCHG                                     0x67
#define   AQ_INST_OP_CODE_ATOM_MIN                                          0x68
#define   AQ_INST_OP_CODE_ATOM_MAX                                          0x69
#define   AQ_INST_OP_CODE_ATOM_OR                                           0x6A
#define   AQ_INST_OP_CODE_ATOM_AND                                          0x6B
#define   AQ_INST_OP_CODE_ATOM_XOR                                          0x6C
#define   AQ_INST_OP_CODE_BIT_REVERSAL                                      0x6D
#define   AQ_INST_OP_CODE_BYTE_REVERSAL                                     0x6E
#define   AQ_INST_OP_CODE_TEXLD_L_PCF                                       0x6F
#define   AQ_INST_OP_CODE_TEXLD_G_PCF                                       0x70
#define   AQ_INST_OP_CODE_PACK                                              0x71
#define   AQ_INST_OP_CODE_CONV                                              0x72
#define   AQ_INST_OP_CODE_DP2                                               0x73
#define   AQ_INST_OP_CODE_NORM_DP2                                          0x74
#define   AQ_INST_OP_CODE_NORM_DP3                                          0x75
#define   AQ_INST_OP_CODE_NORM_DP4                                          0x76
#define   AQ_INST_OP_CODE_NORM_MUL                                          0x77
#define   AQ_INST_OP_CODE_LOAD_ATTR                                         0x78
#define   AQ_INST_OP_CODE_IMG_LOAD                                          0x79
#define   AQ_INST_OP_CODE_IMG_STORE                                         0x7A
#define   AQ_INST_OP_CODE_TEXLD_U                                           0x7B
#define   AQ_INST_OP_CODE_TEXLD_U_F_B                                       0x7B
#define   AQ_INST_OP_CODE_LODQ_G                                            0x7C
#define   AQ_INST_OP_CODE_TEXLD_GATHER                                      0x7D
#define   AQ_INST_OP_CODE_ASYNC_COPY                                        0x7E
#define   AQ_INST_OP_CODE_EXTENDED                                          0x7F



#define MWV207REG_SH_EXTENDED_OPCODE                                         7:0
#define MWV207REG_SH_EXTENDED_OPCODE_End                                       7
#define MWV207REG_SH_EXTENDED_OPCODE_Start                                     0
#define MWV207REG_SH_EXTENDED_OPCODE_Type                                    U08
#define   MWV207REG_SH_EXTENDED_OPCODE_EMIT                                 0x01
#define   MWV207REG_SH_EXTENDED_OPCODE_RESTART                              0x02
#define   MWV207REG_SH_EXTENDED_OPCODE_FLUSH                                0x03
#define   MWV207REG_SH_EXTENDED_OPCODE_LODQ                                 0x04
#define   MWV207REG_SH_EXTENDED_OPCODE_BIT_FINDLSB                          0x0B
#define   MWV207REG_SH_EXTENDED_OPCODE_BIT_FINDMSB                          0x0C
#define   MWV207REG_SH_EXTENDED_OPCODE_TEXLD_FETCH_MS                       0x0D
#define   MWV207REG_SH_EXTENDED_OPCODE_TEXLD_FETCH_MS_S                     0x0D
#define   MWV207REG_SH_EXTENDED_OPCODE_TEXLD_FETCH_MS_U                     0x0E
#define   MWV207REG_SH_EXTENDED_OPCODE_HALFMIX                              0x0F
#define   MWV207REG_SH_EXTENDED_OPCODE_LDEXP                                0x10
#define   MWV207REG_SH_EXTENDED_OPCODE_WAIT_GROUP_EVENT                     0x11
#define   MWV207REG_SH_EXTENDED_OPCODE_TD_OP                                0x12
#define   MWV207REG_SH_EXTENDED_OPCODE_MOVBIX                               0x13
#define   MWV207REG_SH_EXTENDED_OPCODE_TEX_INVALIDATE                       0x14
#define   MWV207REG_SH_EXTENDED_OPCODE_PRE_NORM                             0x15



#define MWV207REG_SH_IMG_ATOM_OPCODE                                         2:0
#define MWV207REG_SH_IMG_ATOM_OPCODE_End                                       2
#define MWV207REG_SH_IMG_ATOM_OPCODE_Start                                     0
#define MWV207REG_SH_IMG_ATOM_OPCODE_Type                                    U03
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_ADD                  0x0
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_XCHG                 0x1
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_CMP_XCHG             0x2
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_MIN                  0x3
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_MAX                  0x4
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_OR                   0x5
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_AND                  0x6
#define   MWV207REG_SH_IMG_ATOM_OPCODE_IMG_OP_CODE_ATOM_XOR                  0x7


#define MWV207REG_SH_IMG_ATOM_OPCODE3_D                                      3:3
#define MWV207REG_SH_IMG_ATOM_OPCODE3_D_End                                    3
#define MWV207REG_SH_IMG_ATOM_OPCODE3_D_Start                                  3
#define MWV207REG_SH_IMG_ATOM_OPCODE3_D_Type                                 U01
#define   MWV207REG_SH_IMG_ATOM_OPCODE3_D_DISABLED                           0x0
#define   MWV207REG_SH_IMG_ATOM_OPCODE3_D_ENABLED                            0x1



#define AQ_SHADER_SRC_REG_TYPE                                               2:0
#define AQ_SHADER_SRC_REG_TYPE_End                                             2
#define AQ_SHADER_SRC_REG_TYPE_Start                                           0
#define AQ_SHADER_SRC_REG_TYPE_Type                                          U03
#define   AQ_SHADER_SRC_REG_TYPE_TEMP                                        0x0

#define   AQ_SHADER_SRC_REG_TYPE_MEDIUMP_TEMP                                0x0
#define   AQ_SHADER_SRC_REG_TYPE_FACE                                        0x1

#define   AQ_SHADER_SRC_REG_TYPE_TEMP256                                     0x1
#define   AQ_SHADER_SRC_REG_TYPE_UNBOUNDED_CONST                             0x2
#define   AQ_SHADER_SRC_REG_TYPE_BOUNDED_CONST                               0x3
#define   AQ_SHADER_SRC_REG_TYPE_VERTEX_ID                                   0x4

#define   AQ_SHADER_SRC_REG_TYPE_HIGHP_TEMP                                  0x4

#define   AQ_SHADER_SRC_REG_TYPE_UNIFORM512                                  0x4
#define   AQ_SHADER_SRC_REG_TYPE_EXTENDED                                    0x5
#define   AQ_SHADER_SRC_REG_TYPE_INSTANCE_ID                                 0x5
#define   AQ_SHADER_SRC_REG_TYPE_LOCAL                                       0x6
#define   AQ_SHADER_SRC_REG_TYPE_IMMEDIATE                                   0x7



#define MWV207REG_SH_INSTRUCTION_TYPE                                        2:0
#define MWV207REG_SH_INSTRUCTION_TYPE_End                                      2
#define MWV207REG_SH_INSTRUCTION_TYPE_Start                                    0
#define MWV207REG_SH_INSTRUCTION_TYPE_Type                                   U03
#define   MWV207REG_SH_INSTRUCTION_TYPE_FLOAT32                              0x0
#define   MWV207REG_SH_INSTRUCTION_TYPE_FLOAT16                              0x1
#define   MWV207REG_SH_INSTRUCTION_TYPE_SIGNED32                             0x2
#define   MWV207REG_SH_INSTRUCTION_TYPE_SIGNED16                             0x3
#define   MWV207REG_SH_INSTRUCTION_TYPE_SIGNED8                              0x4
#define   MWV207REG_SH_INSTRUCTION_TYPE_UNSIGNED32                           0x5
#define   MWV207REG_SH_INSTRUCTION_TYPE_UNSIGNED16                           0x6
#define   MWV207REG_SH_INSTRUCTION_TYPE_UNSIGNED8                            0x7


#define MWV207REG_SH_INSTRUCTION_INDEX                                       9:4
#define MWV207REG_SH_INSTRUCTION_INDEX_End                                     9
#define MWV207REG_SH_INSTRUCTION_INDEX_Start                                   4
#define MWV207REG_SH_INSTRUCTION_INDEX_Type                                  U06

#define   MWV207REG_SH_INSTRUCTION_INDEX_INSTANCE_ID                        0x00

#define   MWV207REG_SH_INSTRUCTION_INDEX_INPUT_PRIMITIVE_ID                 0x01

#define   MWV207REG_SH_INSTRUCTION_INDEX_OUTPUT_PRIMITIVE_ID                0x02

#define   MWV207REG_SH_INSTRUCTION_INDEX_IMMEDIATE_U                        0x03

#define   MWV207REG_SH_INSTRUCTION_INDEX_IMMEDIATE_S                        0x04

#define   MWV207REG_SH_INSTRUCTION_INDEX_CACHE_ID                           0x05

#define   MWV207REG_SH_INSTRUCTION_INDEX_REMAP                              0x06

#define   MWV207REG_SH_INSTRUCTION_INDEX_REMAP0                             0x08

#define   MWV207REG_SH_INSTRUCTION_INDEX_REMAP1                             0x09

#define   MWV207REG_SH_INSTRUCTION_INDEX_REMAP2                             0x0A

#define   MWV207REG_SH_INSTRUCTION_INDEX_REMAP3                             0x0B

#define   MWV207REG_SH_INSTRUCTION_INDEX_REMAP4                             0x0C

#define   MWV207REG_SH_INSTRUCTION_INDEX_REMAP5                             0x0D

#define   MWV207REG_SH_INSTRUCTION_INDEX_PC_PLUS_ONE                        0x0E

#define   MWV207REG_SH_INSTRUCTION_INDEX_VERTEX_ID                          0x0F

#define   MWV207REG_SH_INSTRUCTION_INDEX_SAMPLE_ID                          0x10

#define   MWV207REG_SH_INSTRUCTION_INDEX_SAMPLE_POSITION                    0x11

#define   MWV207REG_SH_INSTRUCTION_INDEX_SAMPLE_MASK_IN                     0x12

#define   MWV207REG_SH_INSTRUCTION_INDEX_CLUSTER_ID                         0x13

#define   MWV207REG_SH_INSTRUCTION_INDEX_THREAD_ID                          0x14


#define MWV207REG_SH_INSTRUCTION_XTYPE                                     15:12
#define MWV207REG_SH_INSTRUCTION_XTYPE_End                                    15
#define MWV207REG_SH_INSTRUCTION_XTYPE_Start                                  12
#define MWV207REG_SH_INSTRUCTION_XTYPE_Type                                  U04
#define   MWV207REG_SH_INSTRUCTION_XTYPE_FLOAT32                             0x0
#define   MWV207REG_SH_INSTRUCTION_XTYPE_FLOAT16                             0x1
#define   MWV207REG_SH_INSTRUCTION_XTYPE_SIGNED32                            0x2
#define   MWV207REG_SH_INSTRUCTION_XTYPE_SIGNED16                            0x3
#define   MWV207REG_SH_INSTRUCTION_XTYPE_SIGNED8                             0x4
#define   MWV207REG_SH_INSTRUCTION_XTYPE_UNSIGNED32                          0x5
#define   MWV207REG_SH_INSTRUCTION_XTYPE_UNSIGNED16                          0x6
#define   MWV207REG_SH_INSTRUCTION_XTYPE_UNSIGNED8                           0x7
#define   MWV207REG_SH_INSTRUCTION_XTYPE_SIGNED64                            0xA
#define   MWV207REG_SH_INSTRUCTION_XTYPE_SNORM16                             0xB
#define   MWV207REG_SH_INSTRUCTION_XTYPE_SNORM8                              0xC
#define   MWV207REG_SH_INSTRUCTION_XTYPE_UNSIGNED64                          0xD
#define   MWV207REG_SH_INSTRUCTION_XTYPE_UNORM16                             0xE
#define   MWV207REG_SH_INSTRUCTION_XTYPE_UNORM8                              0xF



#define MWV207REG_SH_IMMEDIATE_VALUE                                        19:0
#define MWV207REG_SH_IMMEDIATE_VALUE_End                                      19
#define MWV207REG_SH_IMMEDIATE_VALUE_Start                                     0
#define MWV207REG_SH_IMMEDIATE_VALUE_Type                                    U20


#define MWV207REG_SH_IMMEDIATE_TYPE                                        21:20
#define MWV207REG_SH_IMMEDIATE_TYPE_End                                       21
#define MWV207REG_SH_IMMEDIATE_TYPE_Start                                     20
#define MWV207REG_SH_IMMEDIATE_TYPE_Type                                     U02

#define   MWV207REG_SH_IMMEDIATE_TYPE_FP20                                   0x0

#define   MWV207REG_SH_IMMEDIATE_TYPE_S20                                    0x1

#define   MWV207REG_SH_IMMEDIATE_TYPE_U20                                    0x2

#define   MWV207REG_SH_IMMEDIATE_TYPE_PACKED                                 0x3


#define MWV207REG_OPEN_CL_QUERY                                              2:0
#define MWV207REG_OPEN_CL_QUERY_End                                            2
#define MWV207REG_OPEN_CL_QUERY_Start                                          0
#define MWV207REG_OPEN_CL_QUERY_Type                                         U03
#define   MWV207REG_OPEN_CL_QUERY_ID                                         0x0
#define   MWV207REG_OPEN_CL_QUERY_WORK_DIM                                   0x1
#define   MWV207REG_OPEN_CL_QUERY_GLOBAL_SIZE                                0x2
#define   MWV207REG_OPEN_CL_QUERY_LOCAL_SIZE                                 0x3
#define   MWV207REG_OPEN_CL_QUERY_NUM_GROUPS                                 0x4
#define   MWV207REG_OPEN_CL_QUERY_GLOBAL_OFFSET                              0x5



#define MWV207REG_SH_IMAGE_SHIFT                                             2:0
#define MWV207REG_SH_IMAGE_SHIFT_End                                           2
#define MWV207REG_SH_IMAGE_SHIFT_Start                                         0
#define MWV207REG_SH_IMAGE_SHIFT_Type                                        U03


#define MWV207REG_SH_IMAGE_MULTIPLY                                          3:3
#define MWV207REG_SH_IMAGE_MULTIPLY_End                                        3
#define MWV207REG_SH_IMAGE_MULTIPLY_Start                                      3
#define MWV207REG_SH_IMAGE_MULTIPLY_Type                                     U01
#define   MWV207REG_SH_IMAGE_MULTIPLY_ONE                                    0x0
#define   MWV207REG_SH_IMAGE_MULTIPLY_THREE                                  0x1


#define MWV207REG_SH_IMAGE_ADDRESSING                                        5:4
#define MWV207REG_SH_IMAGE_ADDRESSING_End                                      5
#define MWV207REG_SH_IMAGE_ADDRESSING_Start                                    4
#define MWV207REG_SH_IMAGE_ADDRESSING_Type                                   U02
#define   MWV207REG_SH_IMAGE_ADDRESSING_NONE                                 0x0
#define   MWV207REG_SH_IMAGE_ADDRESSING_BORDER0                              0x1
#define   MWV207REG_SH_IMAGE_ADDRESSING_BORDER1                              0x2
#define   MWV207REG_SH_IMAGE_ADDRESSING_CLAMP                                0x3


#define MWV207REG_SH_IMAGE_CONVERSION                                        9:6
#define MWV207REG_SH_IMAGE_CONVERSION_End                                      9
#define MWV207REG_SH_IMAGE_CONVERSION_Start                                    6
#define MWV207REG_SH_IMAGE_CONVERSION_Type                                   U04
#define   MWV207REG_SH_IMAGE_CONVERSION_FP32                                 0x0
#define   MWV207REG_SH_IMAGE_CONVERSION_FP16                                 0x1
#define   MWV207REG_SH_IMAGE_CONVERSION_S32                                  0x2
#define   MWV207REG_SH_IMAGE_CONVERSION_S16                                  0x3
#define   MWV207REG_SH_IMAGE_CONVERSION_S8                                   0x4
#define   MWV207REG_SH_IMAGE_CONVERSION_U32                                  0x5
#define   MWV207REG_SH_IMAGE_CONVERSION_U16                                  0x6
#define   MWV207REG_SH_IMAGE_CONVERSION_U8                                   0x7
#define   MWV207REG_SH_IMAGE_CONVERSION_PACKED555                            0x8
#define   MWV207REG_SH_IMAGE_CONVERSION_PACKED565                            0x9
#define   MWV207REG_SH_IMAGE_CONVERSION_PACKED101010                         0xA
#define   MWV207REG_SH_IMAGE_CONVERSION_SNORM16                              0xB
#define   MWV207REG_SH_IMAGE_CONVERSION_SNORM8                               0xC
#define   MWV207REG_SH_IMAGE_CONVERSION_UNORM16                              0xE
#define   MWV207REG_SH_IMAGE_CONVERSION_UNORM8                               0xF


#define MWV207REG_SH_IMAGE_TILING                                          11:10
#define MWV207REG_SH_IMAGE_TILING_End                                         11
#define MWV207REG_SH_IMAGE_TILING_Start                                       10
#define MWV207REG_SH_IMAGE_TILING_Type                                       U02
#define   MWV207REG_SH_IMAGE_TILING_LINEAR                                   0x0
#define   MWV207REG_SH_IMAGE_TILING_TILED                                    0x1
#define   MWV207REG_SH_IMAGE_TILING_SUPER_TILED                              0x2
#define   MWV207REG_SH_IMAGE_TILING_SUPER_TILED_YMAJOR                       0x3


#define MWV207REG_SH_IMAGE_TYPE                                            12:12
#define MWV207REG_SH_IMAGE_TYPE_End                                           12
#define MWV207REG_SH_IMAGE_TYPE_Start                                         12
#define MWV207REG_SH_IMAGE_TYPE_Type                                         U01
#define   MWV207REG_SH_IMAGE_TYPE_1D                                         0x0
#define   MWV207REG_SH_IMAGE_TYPE_2D                                         0x1


#define MWV207REG_SH_IMAGE_IMAGE_ID0                                       13:13
#define MWV207REG_SH_IMAGE_IMAGE_ID0_End                                      13
#define MWV207REG_SH_IMAGE_IMAGE_ID0_Start                                    13
#define MWV207REG_SH_IMAGE_IMAGE_ID0_Type                                    U01


#define MWV207REG_SH_IMAGE_COMPONENT_COUNT                                 15:14
#define MWV207REG_SH_IMAGE_COMPONENT_COUNT_End                                15
#define MWV207REG_SH_IMAGE_COMPONENT_COUNT_Start                              14
#define MWV207REG_SH_IMAGE_COMPONENT_COUNT_Type                              U02
#define   MWV207REG_SH_IMAGE_COMPONENT_COUNT_FOUR_COMPONENTS                 0x0
#define   MWV207REG_SH_IMAGE_COMPONENT_COUNT_ONE_COMPONENT                   0x1
#define   MWV207REG_SH_IMAGE_COMPONENT_COUNT_TWO_COMPONENTS                  0x2
#define   MWV207REG_SH_IMAGE_COMPONENT_COUNT_THREE_COMPONENTS                0x3


#define MWV207REG_SH_IMAGE_SWIZZLE_R                                       18:16
#define MWV207REG_SH_IMAGE_SWIZZLE_R_End                                      18
#define MWV207REG_SH_IMAGE_SWIZZLE_R_Start                                    16
#define MWV207REG_SH_IMAGE_SWIZZLE_R_Type                                    U03
#define   MWV207REG_SH_IMAGE_SWIZZLE_R_X                                     0x0
#define   MWV207REG_SH_IMAGE_SWIZZLE_R_Y                                     0x1
#define   MWV207REG_SH_IMAGE_SWIZZLE_R_Z                                     0x2
#define   MWV207REG_SH_IMAGE_SWIZZLE_R_W                                     0x3
#define   MWV207REG_SH_IMAGE_SWIZZLE_R_ZERO                                  0x4
#define   MWV207REG_SH_IMAGE_SWIZZLE_R_ONE                                   0x5


#define MWV207REG_SH_IMAGE_IMAGE_ID1                                       19:19
#define MWV207REG_SH_IMAGE_IMAGE_ID1_End                                      19
#define MWV207REG_SH_IMAGE_IMAGE_ID1_Start                                    19
#define MWV207REG_SH_IMAGE_IMAGE_ID1_Type                                    U01


#define MWV207REG_SH_IMAGE_SWIZZLE_G                                       22:20
#define MWV207REG_SH_IMAGE_SWIZZLE_G_End                                      22
#define MWV207REG_SH_IMAGE_SWIZZLE_G_Start                                    20
#define MWV207REG_SH_IMAGE_SWIZZLE_G_Type                                    U03
#define   MWV207REG_SH_IMAGE_SWIZZLE_G_X                                     0x0
#define   MWV207REG_SH_IMAGE_SWIZZLE_G_Y                                     0x1
#define   MWV207REG_SH_IMAGE_SWIZZLE_G_Z                                     0x2
#define   MWV207REG_SH_IMAGE_SWIZZLE_G_W                                     0x3
#define   MWV207REG_SH_IMAGE_SWIZZLE_G_ZERO                                  0x4
#define   MWV207REG_SH_IMAGE_SWIZZLE_G_ONE                                   0x5


#define MWV207REG_SH_IMAGE_IMAGE_ID2                                       23:23
#define MWV207REG_SH_IMAGE_IMAGE_ID2_End                                      23
#define MWV207REG_SH_IMAGE_IMAGE_ID2_Start                                    23
#define MWV207REG_SH_IMAGE_IMAGE_ID2_Type                                    U01


#define MWV207REG_SH_IMAGE_SWIZZLE_B                                       26:24
#define MWV207REG_SH_IMAGE_SWIZZLE_B_End                                      26
#define MWV207REG_SH_IMAGE_SWIZZLE_B_Start                                    24
#define MWV207REG_SH_IMAGE_SWIZZLE_B_Type                                    U03
#define   MWV207REG_SH_IMAGE_SWIZZLE_B_X                                     0x0
#define   MWV207REG_SH_IMAGE_SWIZZLE_B_Y                                     0x1
#define   MWV207REG_SH_IMAGE_SWIZZLE_B_Z                                     0x2
#define   MWV207REG_SH_IMAGE_SWIZZLE_B_W                                     0x3
#define   MWV207REG_SH_IMAGE_SWIZZLE_B_ZERO                                  0x4
#define   MWV207REG_SH_IMAGE_SWIZZLE_B_ONE                                   0x5


#define MWV207REG_SH_IMAGE_TYPE3_D                                         27:27
#define MWV207REG_SH_IMAGE_TYPE3_D_End                                        27
#define MWV207REG_SH_IMAGE_TYPE3_D_Start                                      27
#define MWV207REG_SH_IMAGE_TYPE3_D_Type                                      U01
#define   MWV207REG_SH_IMAGE_TYPE3_D_NOT3_D                                  0x0
#define   MWV207REG_SH_IMAGE_TYPE3_D_3D                                      0x1


#define MWV207REG_SH_IMAGE_SWIZZLE_A                                       30:28
#define MWV207REG_SH_IMAGE_SWIZZLE_A_End                                      30
#define MWV207REG_SH_IMAGE_SWIZZLE_A_Start                                    28
#define MWV207REG_SH_IMAGE_SWIZZLE_A_Type                                    U03
#define   MWV207REG_SH_IMAGE_SWIZZLE_A_X                                     0x0
#define   MWV207REG_SH_IMAGE_SWIZZLE_A_Y                                     0x1
#define   MWV207REG_SH_IMAGE_SWIZZLE_A_Z                                     0x2
#define   MWV207REG_SH_IMAGE_SWIZZLE_A_W                                     0x3
#define   MWV207REG_SH_IMAGE_SWIZZLE_A_ZERO                                  0x4
#define   MWV207REG_SH_IMAGE_SWIZZLE_A_ONE                                   0x5


#define MWV207REG_SH_IMAGE_TYPE_ARRAY                                      31:31
#define MWV207REG_SH_IMAGE_TYPE_ARRAY_End                                     31
#define MWV207REG_SH_IMAGE_TYPE_ARRAY_Start                                   31
#define MWV207REG_SH_IMAGE_TYPE_ARRAY_Type                                   U01
#define   MWV207REG_SH_IMAGE_TYPE_ARRAY_NOT_ARRAY                            0x0
#define   MWV207REG_SH_IMAGE_TYPE_ARRAY_ARRAY                                0x1



#define MWV207REG_SH_IMAGE_PROPERTY_TYPE                                     2:0
#define MWV207REG_SH_IMAGE_PROPERTY_TYPE_End                                   2
#define MWV207REG_SH_IMAGE_PROPERTY_TYPE_Start                                 0
#define MWV207REG_SH_IMAGE_PROPERTY_TYPE_Type                                U03
#define   MWV207REG_SH_IMAGE_PROPERTY_TYPE_1D                                0x0
#define   MWV207REG_SH_IMAGE_PROPERTY_TYPE_2D                                0x1
#define   MWV207REG_SH_IMAGE_PROPERTY_TYPE_3D                                0x3
#define   MWV207REG_SH_IMAGE_PROPERTY_TYPE_1D_ARRAY                          0x4
#define   MWV207REG_SH_IMAGE_PROPERTY_TYPE_2D_ARRAY                          0x5



#define MWV207REG_SH_FLUSH_TEXTURE                                           0:0
#define MWV207REG_SH_FLUSH_TEXTURE_End                                         0
#define MWV207REG_SH_FLUSH_TEXTURE_Start                                       0
#define MWV207REG_SH_FLUSH_TEXTURE_Type                                      U01


#define MWV207REG_SH_FLUSH_L1_FLUSH                                          1:1
#define MWV207REG_SH_FLUSH_L1_FLUSH_End                                        1
#define MWV207REG_SH_FLUSH_L1_FLUSH_Start                                      1
#define MWV207REG_SH_FLUSH_L1_FLUSH_Type                                     U01

#define MWV207REG_SH_FLUSH_L1_FLUSH_INTERLOCK                                2:2
#define MWV207REG_SH_FLUSH_L1_FLUSH_INTERLOCK_End                              2
#define MWV207REG_SH_FLUSH_L1_FLUSH_INTERLOCK_Start                            2
#define MWV207REG_SH_FLUSH_L1_FLUSH_INTERLOCK_Type                           U01


#define MWV207REG_SH_FLUSH_L1_INVALIDATE                                     3:3
#define MWV207REG_SH_FLUSH_L1_INVALIDATE_End                                   3
#define MWV207REG_SH_FLUSH_L1_INVALIDATE_Start                                 3
#define MWV207REG_SH_FLUSH_L1_INVALIDATE_Type                                U01



#define MWV207REG_SH_TEXLD_U_COORDINATES                                     1:0
#define MWV207REG_SH_TEXLD_U_COORDINATES_End                                   1
#define MWV207REG_SH_TEXLD_U_COORDINATES_Start                                 0
#define MWV207REG_SH_TEXLD_U_COORDINATES_Type                                U02
#define   MWV207REG_SH_TEXLD_U_COORDINATES_INTEGER                           0x0
#define   MWV207REG_SH_TEXLD_U_COORDINATES_FLOAT                             0x1

#define   MWV207REG_SH_TEXLD_U_COORDINATES_NORMALIZED                        0x2


#define MWV207REG_SH_TEXLD_U_MAG_FILTER                                      4:4
#define MWV207REG_SH_TEXLD_U_MAG_FILTER_End                                    4
#define MWV207REG_SH_TEXLD_U_MAG_FILTER_Start                                  4
#define MWV207REG_SH_TEXLD_U_MAG_FILTER_Type                                 U01
#define   MWV207REG_SH_TEXLD_U_MAG_FILTER_NEAREST                            0x0
#define   MWV207REG_SH_TEXLD_U_MAG_FILTER_LINEAR                             0x1


#define MWV207REG_SH_TEXLD_U_MIN_FILTER                                      5:5
#define MWV207REG_SH_TEXLD_U_MIN_FILTER_End                                    5
#define MWV207REG_SH_TEXLD_U_MIN_FILTER_Start                                  5
#define MWV207REG_SH_TEXLD_U_MIN_FILTER_Type                                 U01
#define   MWV207REG_SH_TEXLD_U_MIN_FILTER_NEAREST                            0x0
#define   MWV207REG_SH_TEXLD_U_MIN_FILTER_LINEAR                             0x1


#define MWV207REG_SH_TEXLD_U_MIP_FILTER                                      6:6
#define MWV207REG_SH_TEXLD_U_MIP_FILTER_End                                    6
#define MWV207REG_SH_TEXLD_U_MIP_FILTER_Start                                  6
#define MWV207REG_SH_TEXLD_U_MIP_FILTER_Type                                 U01
#define   MWV207REG_SH_TEXLD_U_MIP_FILTER_NEAREST                            0x0
#define   MWV207REG_SH_TEXLD_U_MIP_FILTER_LINEAR                             0x1


#define MWV207REG_SH_TEXLD_U_ADDRESSING                                      9:8
#define MWV207REG_SH_TEXLD_U_ADDRESSING_End                                    9
#define MWV207REG_SH_TEXLD_U_ADDRESSING_Start                                  8
#define MWV207REG_SH_TEXLD_U_ADDRESSING_Type                                 U02
#define   MWV207REG_SH_TEXLD_U_ADDRESSING_CLAMP                              0x0
#define   MWV207REG_SH_TEXLD_U_ADDRESSING_BORDER                             0x1
#define   MWV207REG_SH_TEXLD_U_ADDRESSING_REPEAT                             0x2
#define   MWV207REG_SH_TEXLD_U_ADDRESSING_MIRRORED_REPEAT                    0x3


#define MWV207REG_SH_TEXLD_U_MODE                                          13:12
#define MWV207REG_SH_TEXLD_U_MODE_End                                         13
#define MWV207REG_SH_TEXLD_U_MODE_Start                                       12
#define MWV207REG_SH_TEXLD_U_MODE_Type                                       U02
#define   MWV207REG_SH_TEXLD_U_MODE_PLAIN                                    0x0
#define   MWV207REG_SH_TEXLD_U_MODE_LOD                                      0x1
#define   MWV207REG_SH_TEXLD_U_MODE_BIAS                                     0x2



#define MWV207REG_SH_LOAD_STORE_SHIFT                                        2:0
#define MWV207REG_SH_LOAD_STORE_SHIFT_End                                      2
#define MWV207REG_SH_LOAD_STORE_SHIFT_Start                                    0
#define MWV207REG_SH_LOAD_STORE_SHIFT_Type                                   U03


#define MWV207REG_SH_LOAD_STORE_MULTIPLY                                     3:3
#define MWV207REG_SH_LOAD_STORE_MULTIPLY_End                                   3
#define MWV207REG_SH_LOAD_STORE_MULTIPLY_Start                                 3
#define MWV207REG_SH_LOAD_STORE_MULTIPLY_Type                                U01
#define   MWV207REG_SH_LOAD_STORE_MULTIPLY_ONE                               0x0
#define   MWV207REG_SH_LOAD_STORE_MULTIPLY_THREE                             0x1


#define MWV207REG_SH_LOAD_STORE_SKIP_FOR_HELPERS                             4:4
#define MWV207REG_SH_LOAD_STORE_SKIP_FOR_HELPERS_End                           4
#define MWV207REG_SH_LOAD_STORE_SKIP_FOR_HELPERS_Start                         4
#define MWV207REG_SH_LOAD_STORE_SKIP_FOR_HELPERS_Type                        U01

#define MWV207REG_SH_LOAD_STORE_ACCESS_LOCAL_STORAGE                         5:5
#define MWV207REG_SH_LOAD_STORE_ACCESS_LOCAL_STORAGE_End                       5
#define MWV207REG_SH_LOAD_STORE_ACCESS_LOCAL_STORAGE_Start                     5
#define MWV207REG_SH_LOAD_STORE_ACCESS_LOCAL_STORAGE_Type                    U01



#define MWV207REG_SH_ATTRIBUTE_ADDRESS                                      11:0
#define MWV207REG_SH_ATTRIBUTE_ADDRESS_End                                    11
#define MWV207REG_SH_ATTRIBUTE_ADDRESS_Start                                   0
#define MWV207REG_SH_ATTRIBUTE_ADDRESS_Type                                  U12


#define MWV207REG_SH_ATTRIBUTE_LAYOUT                                      12:12
#define MWV207REG_SH_ATTRIBUTE_LAYOUT_End                                     12
#define MWV207REG_SH_ATTRIBUTE_LAYOUT_Start                                   12
#define MWV207REG_SH_ATTRIBUTE_LAYOUT_Type                                   U01

#define   MWV207REG_SH_ATTRIBUTE_LAYOUT_INTERLEAVED                          0x0

#define   MWV207REG_SH_ATTRIBUTE_LAYOUT_LINEAR                               0x1


#define MWV207REG_SH_ATTRIBUTE_CLIENT                                      15:14
#define MWV207REG_SH_ATTRIBUTE_CLIENT_End                                     15
#define MWV207REG_SH_ATTRIBUTE_CLIENT_Start                                   14
#define MWV207REG_SH_ATTRIBUTE_CLIENT_Type                                   U02

#define   MWV207REG_SH_ATTRIBUTE_CLIENT_VS                                   0x0

#define   MWV207REG_SH_ATTRIBUTE_CLIENT_TCS                                  0x1

#define   MWV207REG_SH_ATTRIBUTE_CLIENT_TES                                  0x2

#define   MWV207REG_SH_ATTRIBUTE_CLIENT_GS                                   0x3



#define MWV207REG_SH_LOCAL_STORAGE_ENABLE                                    1:1
#define MWV207REG_SH_LOCAL_STORAGE_ENABLE_End                                  1
#define MWV207REG_SH_LOCAL_STORAGE_ENABLE_Start                                1
#define MWV207REG_SH_LOCAL_STORAGE_ENABLE_Type                               U01
#define   MWV207REG_SH_LOCAL_STORAGE_ENABLE_REGISTER                         0x0
#define   MWV207REG_SH_LOCAL_STORAGE_ENABLE_LOCAL_STORAGE                    0x1



#define MWV207REG_SH_SAMPLER_NUM_SYNC_FLAG                                   3:3
#define MWV207REG_SH_SAMPLER_NUM_SYNC_FLAG_End                                 3
#define MWV207REG_SH_SAMPLER_NUM_SYNC_FLAG_Start                               3
#define MWV207REG_SH_SAMPLER_NUM_SYNC_FLAG_Type                              U01


#define MWV207REG_SH_INST_ENDIAN_CONTROL                                     0:0
#define MWV207REG_SH_INST_ENDIAN_CONTROL_End                                   0
#define MWV207REG_SH_INST_ENDIAN_CONTROL_Start                                 0
#define MWV207REG_SH_INST_ENDIAN_CONTROL_Type                                U01
#define   MWV207REG_SH_INST_ENDIAN_CONTROL_DISABLE                           0x0
#define   MWV207REG_SH_INST_ENDIAN_CONTROL_ENABLE                            0x1


#define MWV207REG_SH_USC_CONTROL_ALLOCATE                                    1:1
#define MWV207REG_SH_USC_CONTROL_ALLOCATE_End                                  1
#define MWV207REG_SH_USC_CONTROL_ALLOCATE_Start                                1
#define MWV207REG_SH_USC_CONTROL_ALLOCATE_Type                               U01
#define   MWV207REG_SH_USC_CONTROL_ALLOCATE_YES                              0x0
#define   MWV207REG_SH_USC_CONTROL_ALLOCATE_NO                               0x1


#define MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER                            2:2
#define MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_End                          2
#define MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_Start                        2
#define MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_Type                       U01
#define   MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_NO                       0x0
#define   MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_YES                      0x1

#define MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER                               3:3
#define MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER_End                             3
#define MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER_Start                           3
#define MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER_Type                          U01
#define   MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER_NO                          0x0
#define   MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER_YES                         0x1



#define MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT                                  1:0
#define MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT_End                                1
#define MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT_Start                              0
#define MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT_Type                             U02

#define   MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT_VS                             0x0

#define   MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT_TCS                            0x1

#define   MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT_TES                            0x2

#define   MWV207REG_SH_SAMPLER_SWIZZLE_CLIENT_GS                             0x3


#define MWV207REG_SH_SAMPLER_SWIZZLE_LAYOUT                                  3:3
#define MWV207REG_SH_SAMPLER_SWIZZLE_LAYOUT_End                                3
#define MWV207REG_SH_SAMPLER_SWIZZLE_LAYOUT_Start                              3
#define MWV207REG_SH_SAMPLER_SWIZZLE_LAYOUT_Type                             U01

#define   MWV207REG_SH_SAMPLER_SWIZZLE_LAYOUT_INTERLEAVED                    0x0

#define   MWV207REG_SH_SAMPLER_SWIZZLE_LAYOUT_LINEAR                         0x1



#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_RESTART                        0:0
#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_RESTART_End                      0
#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_RESTART_Start                    0
#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_RESTART_Type                   U01
#define   MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_RESTART_DISABLE              0x0
#define   MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_RESTART_ENABLE               0x1


#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_JUMP_TO_END                    1:1
#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_JUMP_TO_END_End                  1
#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_JUMP_TO_END_Start                1
#define MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_JUMP_TO_END_Type               U01
#define   MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_JUMP_TO_END_ENABLE           0x0
#define   MWV207REG_SH_SAMPLER_SWIZZLE_FOR_EMIT_JUMP_TO_END_DISABLE          0x1



#define MWV207REG_SH_ATTRIBUTE_EX_ADDRESS                                   10:0
#define MWV207REG_SH_ATTRIBUTE_EX_ADDRESS_End                                 10
#define MWV207REG_SH_ATTRIBUTE_EX_ADDRESS_Start                                0
#define MWV207REG_SH_ATTRIBUTE_EX_ADDRESS_Type                               U11

#define MWV207REG_SH_ATTRIBUTE_EX_CLUSTER_ID                               13:11
#define MWV207REG_SH_ATTRIBUTE_EX_CLUSTER_ID_End                              13
#define MWV207REG_SH_ATTRIBUTE_EX_CLUSTER_ID_Start                            11
#define MWV207REG_SH_ATTRIBUTE_EX_CLUSTER_ID_Type                            U03


#define MWV207REG_SH_ATTRIBUTE_EX_VALIDITY                                 15:15
#define MWV207REG_SH_ATTRIBUTE_EX_VALIDITY_End                                15
#define MWV207REG_SH_ATTRIBUTE_EX_VALIDITY_Start                              15
#define MWV207REG_SH_ATTRIBUTE_EX_VALIDITY_Type                              U01

#define   MWV207REG_SH_ATTRIBUTE_EX_VALIDITY_VALID                           0x0

#define   MWV207REG_SH_ATTRIBUTE_EX_VALIDITY_INVALID                         0x1



#define MWV207REG_SH_ATTRIBUTE_GS_EX_ADDRESS                                13:0
#define MWV207REG_SH_ATTRIBUTE_GS_EX_ADDRESS_End                              13
#define MWV207REG_SH_ATTRIBUTE_GS_EX_ADDRESS_Start                             0
#define MWV207REG_SH_ATTRIBUTE_GS_EX_ADDRESS_Type                            U14

#define MWV207REG_SH_ATTRIBUTE_GS_EX_CLUSTER_ID                            15:14
#define MWV207REG_SH_ATTRIBUTE_GS_EX_CLUSTER_ID_End                           15
#define MWV207REG_SH_ATTRIBUTE_GS_EX_CLUSTER_ID_Start                         14
#define MWV207REG_SH_ATTRIBUTE_GS_EX_CLUSTER_ID_Type                         U02



#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_ADDRESS                             12:0
#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_ADDRESS_End                           12
#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_ADDRESS_Start                          0
#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_ADDRESS_Type                         U13

#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_CLUSTER_ID                         15:13
#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_CLUSTER_ID_End                        15
#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_CLUSTER_ID_Start                      13
#define MWV207REG_SH_ATTRIBUTE_GS_EX_EX_CLUSTER_ID_Type                      U03




#define MWV207REG_SH_VISION_OPCODE                                           5:0
#define MWV207REG_SH_VISION_OPCODE_End                                         5
#define MWV207REG_SH_VISION_OPCODE_Start                                       0
#define MWV207REG_SH_VISION_OPCODE_Type                                      U06
#define   MWV207REG_SH_VISION_OPCODE_ABS_DIFF                               0x01
#define   MWV207REG_SH_VISION_OPCODE_IADD                                   0x02
#define   MWV207REG_SH_VISION_OPCODE_IACC_SQ                                0x03
#define   MWV207REG_SH_VISION_OPCODE_LERP                                   0x04
#define   MWV207REG_SH_VISION_OPCODE_FILTER                                 0x05
#define   MWV207REG_SH_VISION_OPCODE_MAG_PHASE                              0x06
#define   MWV207REG_SH_VISION_OPCODE_MUL_SHIFT                              0x07
#define   MWV207REG_SH_VISION_OPCODE_DP16X1                                 0x08
#define   MWV207REG_SH_VISION_OPCODE_DP8X2                                  0x09
#define   MWV207REG_SH_VISION_OPCODE_DP4X4                                  0x0A
#define   MWV207REG_SH_VISION_OPCODE_DP2X8                                  0x0B
#define   MWV207REG_SH_VISION_OPCODE_CLAMP                                  0x0C
#define   MWV207REG_SH_VISION_OPCODE_BI_LINEAR                              0x0D
#define   MWV207REG_SH_VISION_OPCODE_SELECT_ADD                             0x0E
#define   MWV207REG_SH_VISION_OPCODE_ATOMIC_ADD                             0x0F
#define   MWV207REG_SH_VISION_OPCODE_BIT_EXTRACT                            0x10
#define   MWV207REG_SH_VISION_OPCODE_BIT_REPLACE                            0x11
#define   MWV207REG_SH_VISION_OPCODE_DP32X1                                 0x12
#define   MWV207REG_SH_VISION_OPCODE_DP16X2                                 0x13
#define   MWV207REG_SH_VISION_OPCODE_DP8X4                                  0x14
#define   MWV207REG_SH_VISION_OPCODE_DP4X8                                  0x15
#define   MWV207REG_SH_VISION_OPCODE_DP2X16                                 0x16
#define   MWV207REG_SH_VISION_OPCODE_INDEX_ADD                              0x17
#define   MWV207REG_SH_VISION_OPCODE_VERT_MIN3                              0x18
#define   MWV207REG_SH_VISION_OPCODE_VERT_MAX3                              0x19
#define   MWV207REG_SH_VISION_OPCODE_VERT_MED3                              0x1A
#define   MWV207REG_SH_VISION_OPCODE_HORZ_MIN3                              0x1B
#define   MWV207REG_SH_VISION_OPCODE_HORZ_MAX3                              0x1C
#define   MWV207REG_SH_VISION_OPCODE_HORZ_MED3                              0x1D
#define   MWV207REG_SH_VISION_OPCODE_GATHER                                 0x1E
#define   MWV207REG_SH_VISION_OPCODE_SCATTER                                0x1F
#define   MWV207REG_SH_VISION_OPCODE_ATOMIC_S                               0x20


#define MWV207REG_SH_VISION_FILTER                                          11:8
#define MWV207REG_SH_VISION_FILTER_End                                        11
#define MWV207REG_SH_VISION_FILTER_Start                                       8
#define MWV207REG_SH_VISION_FILTER_Type                                      U04

#define   MWV207REG_SH_VISION_FILTER_BOX                                     0x0
#define   MWV207REG_SH_VISION_FILTER_GAUSSIAN                                0x1
#define   MWV207REG_SH_VISION_FILTER_SOBEL_X                                 0x2
#define   MWV207REG_SH_VISION_FILTER_SOBEL_Y                                 0x3
#define   MWV207REG_SH_VISION_FILTER_SCHARR_X                                0x4
#define   MWV207REG_SH_VISION_FILTER_SCHARR_Y                                0x5

#define   MWV207REG_SH_VISION_FILTER_MAX                                     0x8

#define   MWV207REG_SH_VISION_FILTER_MIN                                     0x9

#define   MWV207REG_SH_VISION_FILTER_MEDIAN                                  0xA


#define MWV207REG_SH_VISION_ROUNDING                                       13:12
#define MWV207REG_SH_VISION_ROUNDING_End                                      13
#define MWV207REG_SH_VISION_ROUNDING_Start                                    12
#define MWV207REG_SH_VISION_ROUNDING_Type                                    U02

#define   MWV207REG_SH_VISION_ROUNDING_TRUNCATE                              0x0

#define   MWV207REG_SH_VISION_ROUNDING_TOWARD_ZERO                           0x0

#define   MWV207REG_SH_VISION_ROUNDING_SIMPLE_ROUNDING                       0x1

#define   MWV207REG_SH_VISION_ROUNDING_HALF_UP                               0x1

#define   MWV207REG_SH_VISION_ROUNDING_HALF_NEAREST_EVEN                     0x2


#define MWV207REG_SH_SCATTERED_OFFSET_TYPE                                   2:0
#define MWV207REG_SH_SCATTERED_OFFSET_TYPE_End                                 2
#define MWV207REG_SH_SCATTERED_OFFSET_TYPE_Start                               0
#define MWV207REG_SH_SCATTERED_OFFSET_TYPE_Type                              U03
#define   MWV207REG_SH_SCATTERED_OFFSET_TYPE_UNSIGNED32                      0x0
#define   MWV207REG_SH_SCATTERED_OFFSET_TYPE_SIGNED32                        0x1
#define   MWV207REG_SH_SCATTERED_OFFSET_TYPE_UNSIGNED16                      0x2
#define   MWV207REG_SH_SCATTERED_OFFSET_TYPE_SIGNED16                        0x3
#define   MWV207REG_SH_SCATTERED_OFFSET_TYPE_UNSIGNED8                       0x4
#define   MWV207REG_SH_SCATTERED_OFFSET_TYPE_SIGNED8                         0x5

#define MWV207REG_SH_SCATTERED_ATOM_OP                                       5:3
#define MWV207REG_SH_SCATTERED_ATOM_OP_End                                     5
#define MWV207REG_SH_SCATTERED_ATOM_OP_Start                                   3
#define MWV207REG_SH_SCATTERED_ATOM_OP_Type                                  U03
#define   MWV207REG_SH_SCATTERED_ATOM_OP_ADD                                 0x0
#define   MWV207REG_SH_SCATTERED_ATOM_OP_MIN                                 0x1
#define   MWV207REG_SH_SCATTERED_ATOM_OP_MAX                                 0x2
#define   MWV207REG_SH_SCATTERED_ATOM_OP_OR                                  0x3
#define   MWV207REG_SH_SCATTERED_ATOM_OP_AND                                 0x4
#define   MWV207REG_SH_SCATTERED_ATOM_OP_XOR                                 0x5
#define   MWV207REG_SH_SCATTERED_ATOM_OP_XCHG                                0x6



#define MWV207REG_SH_CMPLX_OPCODE                                            3:0
#define MWV207REG_SH_CMPLX_OPCODE_End                                          3
#define MWV207REG_SH_CMPLX_OPCODE_Start                                        0
#define MWV207REG_SH_CMPLX_OPCODE_Type                                       U04
#define   MWV207REG_SH_CMPLX_OPCODE_MUL                                      0x0
#define   MWV207REG_SH_CMPLX_OPCODE_MAD                                      0x1
#define   MWV207REG_SH_CMPLX_OPCODE_ADD                                      0x2



#define AQ_SHADER_SRC_XSWIZZLE                                               1:0
#define AQ_SHADER_SRC_XSWIZZLE_End                                             1
#define AQ_SHADER_SRC_XSWIZZLE_Start                                           0
#define AQ_SHADER_SRC_XSWIZZLE_Type                                          U02

#define AQ_SHADER_SRC_YSWIZZLE                                               3:2
#define AQ_SHADER_SRC_YSWIZZLE_End                                             3
#define AQ_SHADER_SRC_YSWIZZLE_Start                                           2
#define AQ_SHADER_SRC_YSWIZZLE_Type                                          U02

#define AQ_SHADER_SRC_ZSWIZZLE                                               5:4
#define AQ_SHADER_SRC_ZSWIZZLE_End                                             5
#define AQ_SHADER_SRC_ZSWIZZLE_Start                                           4
#define AQ_SHADER_SRC_ZSWIZZLE_Type                                          U02

#define AQ_SHADER_SRC_WSWIZZLE                                               7:6
#define AQ_SHADER_SRC_WSWIZZLE_End                                             7
#define AQ_SHADER_SRC_WSWIZZLE_Start                                           6
#define AQ_SHADER_SRC_WSWIZZLE_Type                                          U02



#define AQ_SHADER_REL_ADR                                                    2:0
#define AQ_SHADER_REL_ADR_End                                                  2
#define AQ_SHADER_REL_ADR_Start                                                0
#define AQ_SHADER_REL_ADR_Type                                               U03
#define   AQ_SHADER_REL_ADR_NONE                                             0x0
#define   AQ_SHADER_REL_ADR_A0_X                                             0x1
#define   AQ_SHADER_REL_ADR_A0_Y                                             0x2
#define   AQ_SHADER_REL_ADR_A0_Z                                             0x3
#define   AQ_SHADER_REL_ADR_A0_W                                             0x4
#define   AQ_SHADER_REL_ADR_AL                                               0x5
#define   AQ_SHADER_REL_ADR_INSTANCE_ID                                      0x6
#define   AQ_SHADER_REL_ADR_B0                                               0x7



#define AQ_SHADER_LOOP_COUNT                                                 8:0
#define AQ_SHADER_LOOP_COUNT_End                                               8
#define AQ_SHADER_LOOP_COUNT_Start                                             0
#define AQ_SHADER_LOOP_COUNT_Type                                            U09

#define AQ_SHADER_LOOP_INITIAL                                             18:10
#define AQ_SHADER_LOOP_INITIAL_End                                            18
#define AQ_SHADER_LOOP_INITIAL_Start                                          10
#define AQ_SHADER_LOOP_INITIAL_Type                                          U09

#define AQ_SHADER_LOOP_STEP                                                29:21
#define AQ_SHADER_LOOP_STEP_End                                               29
#define AQ_SHADER_LOOP_STEP_Start                                             21
#define AQ_SHADER_LOOP_STEP_Type                                             U09



#define AQ_SHADER_YUV_FORMAT_FORMAT                                          1:0
#define AQ_SHADER_YUV_FORMAT_FORMAT_End                                        1
#define AQ_SHADER_YUV_FORMAT_FORMAT_Start                                      0
#define AQ_SHADER_YUV_FORMAT_FORMAT_Type                                     U02
#define   AQ_SHADER_YUV_FORMAT_FORMAT_YUV444                                 0x0
#define   AQ_SHADER_YUV_FORMAT_FORMAT_YUV422                                 0x1
#define   AQ_SHADER_YUV_FORMAT_FORMAT_YUV420                                 0x2



#define AQ_SHADER_YUV_STANDARD_STANDARD                                      0:0
#define AQ_SHADER_YUV_STANDARD_STANDARD_End                                    0
#define AQ_SHADER_YUV_STANDARD_STANDARD_Start                                  0
#define AQ_SHADER_YUV_STANDARD_STANDARD_Type                                 U01
#define   AQ_SHADER_YUV_STANDARD_STANDARD_BT709                              0x0
#define   AQ_SHADER_YUV_STANDARD_STANDARD_BT601                              0x1



#define AQ_SHADER_ROUNDING_MODE_MODE                                         1:0
#define AQ_SHADER_ROUNDING_MODE_MODE_End                                       1
#define AQ_SHADER_ROUNDING_MODE_MODE_Start                                     0
#define AQ_SHADER_ROUNDING_MODE_MODE_Type                                    U02
#define   AQ_SHADER_ROUNDING_MODE_MODE_DEFAULT                               0x0
#define   AQ_SHADER_ROUNDING_MODE_MODE_RTZ                                   0x1
#define   AQ_SHADER_ROUNDING_MODE_MODE_RTNE                                  0x2


#define AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE                         1:0
#define AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE_End                       1
#define AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE_Start                     0
#define AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE_Type                    U02
#define   AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE_RTNI                  0x0
#define   AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE_RTZ                   0x1
#define   AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE_RTNE                  0x2
#define   AQ_SHADER_CONV_LOAD_STORE_ROUNDING_MODE_MODE_RTPI                  0x3



#define AQ_SHADER_PACK_MODE_MODE                                             0:0
#define AQ_SHADER_PACK_MODE_MODE_End                                           0
#define AQ_SHADER_PACK_MODE_MODE_Start                                         0
#define AQ_SHADER_PACK_MODE_MODE_Type                                        U01
#define   AQ_SHADER_PACK_MODE_MODE_PACK                                      0x0
#define   AQ_SHADER_PACK_MODE_MODE_UNPACK                                    0x1


#define AQ_SHADER_IMG_LOAD_STORE_PACK_MODE_MODE                              0:0
#define AQ_SHADER_IMG_LOAD_STORE_PACK_MODE_MODE_End                            0
#define AQ_SHADER_IMG_LOAD_STORE_PACK_MODE_MODE_Start                          0
#define AQ_SHADER_IMG_LOAD_STORE_PACK_MODE_MODE_Type                         U01
#define   AQ_SHADER_IMG_LOAD_STORE_PACK_MODE_MODE_UNPACK                     0x0
#define   AQ_SHADER_IMG_LOAD_STORE_PACK_MODE_MODE_PACK                       0x1



#define AQ_SHADER_VECTOR_SIZE                                                1:0
#define AQ_SHADER_VECTOR_SIZE_End                                              1
#define AQ_SHADER_VECTOR_SIZE_Start                                            0
#define AQ_SHADER_VECTOR_SIZE_Type                                           U02
#define   AQ_SHADER_VECTOR_SIZE_VEC4                                         0x0
#define   AQ_SHADER_VECTOR_SIZE_VEC1                                         0x1
#define   AQ_SHADER_VECTOR_SIZE_VEC2                                         0x2
#define   AQ_SHADER_VECTOR_SIZE_VEC3                                         0x3


#define AQ_SHADER_IMG_LOAD_STORE_VECTOR_SIZE                                 0:0
#define AQ_SHADER_IMG_LOAD_STORE_VECTOR_SIZE_End                               0
#define AQ_SHADER_IMG_LOAD_STORE_VECTOR_SIZE_Start                             0
#define AQ_SHADER_IMG_LOAD_STORE_VECTOR_SIZE_Type                            U01
#define   AQ_SHADER_IMG_LOAD_STORE_VECTOR_SIZE_VEC1                          0x0
#define   AQ_SHADER_IMG_LOAD_STORE_VECTOR_SIZE_VEC4                          0x1


#define AQ_SHADER_CONV_VECTOR_SIZE                                           1:0
#define AQ_SHADER_CONV_VECTOR_SIZE_End                                         1
#define AQ_SHADER_CONV_VECTOR_SIZE_Start                                       0
#define AQ_SHADER_CONV_VECTOR_SIZE_Type                                      U02
#define   AQ_SHADER_CONV_VECTOR_SIZE_VEC1                                    0x0
#define   AQ_SHADER_CONV_VECTOR_SIZE_VEC4                                    0x1
#define   AQ_SHADER_CONV_VECTOR_SIZE_VEC2                                    0x2
#define   AQ_SHADER_CONV_VECTOR_SIZE_VEC3                                    0x3



#define AQ_SHADER_DENORMAL_MODE_MODE                                         7:0
#define AQ_SHADER_DENORMAL_MODE_MODE_End                                       7
#define AQ_SHADER_DENORMAL_MODE_MODE_Start                                     0
#define AQ_SHADER_DENORMAL_MODE_MODE_Type                                    U08
#define   AQ_SHADER_DENORMAL_MODE_MODE_OFF                                  0x00
#define   AQ_SHADER_DENORMAL_MODE_MODE_ON                                   0x80



#define AQ_SHADER_EMIT_RESTART_MODE                                          7:0
#define AQ_SHADER_EMIT_RESTART_MODE_End                                        7
#define AQ_SHADER_EMIT_RESTART_MODE_Start                                      0
#define AQ_SHADER_EMIT_RESTART_MODE_Type                                     U08
#define   AQ_SHADER_EMIT_RESTART_MODE_DISABLED                              0x00
#define   AQ_SHADER_EMIT_RESTART_MODE_ENABLED                               0x01



#define AQ_SHADER_THREAD_TYPE_MODE                                           1:0
#define AQ_SHADER_THREAD_TYPE_MODE_End                                         1
#define AQ_SHADER_THREAD_TYPE_MODE_Start                                       0
#define AQ_SHADER_THREAD_TYPE_MODE_Type                                      U02
#define   AQ_SHADER_THREAD_TYPE_MODE_T0T1                                    0x0
#define   AQ_SHADER_THREAD_TYPE_MODE_T0                                      0x1
#define   AQ_SHADER_THREAD_TYPE_MODE_T1                                      0x2
#define   AQ_SHADER_THREAD_TYPE_MODE_T0T1_HIGHPVEC2                          0x3



#define AQ_SHADER_DEST_SWIZZLE_MODE                                          1:0
#define AQ_SHADER_DEST_SWIZZLE_MODE_End                                        1
#define AQ_SHADER_DEST_SWIZZLE_MODE_Start                                      0
#define AQ_SHADER_DEST_SWIZZLE_MODE_Type                                     U02
#define   AQ_SHADER_DEST_SWIZZLE_MODE_SRC0                                   0x0
#define   AQ_SHADER_DEST_SWIZZLE_MODE_SRC1                                   0x1
#define   AQ_SHADER_DEST_SWIZZLE_MODE_SRC2                                   0x2



#define AQ_SHADER_ARCTRIG_MODE_MODE                                          7:0
#define AQ_SHADER_ARCTRIG_MODE_MODE_End                                        7
#define AQ_SHADER_ARCTRIG_MODE_MODE_Start                                      0
#define AQ_SHADER_ARCTRIG_MODE_MODE_Type                                     U08
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCCOS                                0x00
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCSIN                                0x01
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTAN                                0x02
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTAN2                               0x03
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTAN2_PREPROC                       0x83
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTRIG                               0x10
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTRIG_PREPROC1                      0x11
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTRIG_PREPROC2                      0x12
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTRIG_PREPROC3                      0x13
#define   AQ_SHADER_ARCTRIG_MODE_MODE_ARCTRIG_POSTADDPI                     0x14



#define MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX                                3:0
#define MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_End                              3
#define MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_Start                            0
#define MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_Type                           U04
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_TERM_CONFIG                  0x0
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_TERM_ASELECT                 0x1
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_TERM_ABIN                    0x2
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_TERM_BSELECT                 0x4
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_TERM_BBIN                    0x5
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_MISC_CONFIG                  0x7
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_CONSTANT0                    0x8
#define   MWV207REG_SH_DOT_PRODUCT_LAYOUT_INDEX_CONSTANT1                    0xC


#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0                           1:0
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0_End                         1
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0_Start                       0
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM0_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1                           3:2
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1_End                         3
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1_Start                       2
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM1_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2                           5:4
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2_End                         5
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2_Start                       4
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM2_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3                           7:6
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3_End                         7
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3_Start                       6
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM3_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4                           9:8
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4_End                         9
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4_Start                       8
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM4_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5                         11:10
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5_End                        11
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5_Start                      10
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM5_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6                         13:12
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6_End                        13
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6_Start                      12
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM6_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7                         15:14
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7_End                        15
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7_Start                      14
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM7_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8                         17:16
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8_End                        17
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8_Start                      16
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM8_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9                         19:18
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9_End                        19
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9_Start                      18
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9_Type                      U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9_DISABLED                0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9_ADD                     0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9_SUBTRACT                0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM9_ACCUMULATOR             0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10                        21:20
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10_End                       21
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10_Start                     20
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10_Type                     U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10_DISABLED               0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10_ADD                    0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10_SUBTRACT               0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM10_ACCUMULATOR            0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11                        23:22
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11_End                       23
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11_Start                     22
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11_Type                     U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11_DISABLED               0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11_ADD                    0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11_SUBTRACT               0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM11_ACCUMULATOR            0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12                        25:24
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12_End                       25
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12_Start                     24
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12_Type                     U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12_DISABLED               0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12_ADD                    0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12_SUBTRACT               0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM12_ACCUMULATOR            0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13                        27:26
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13_End                       27
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13_Start                     26
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13_Type                     U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13_DISABLED               0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13_ADD                    0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13_SUBTRACT               0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM13_ACCUMULATOR            0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14                        29:28
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14_End                       29
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14_Start                     28
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14_Type                     U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14_DISABLED               0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14_ADD                    0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14_SUBTRACT               0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM14_ACCUMULATOR            0x3

#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15                        31:30
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15_End                       31
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15_Start                     30
#define MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15_Type                     U02
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15_DISABLED               0x0
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15_ADD                    0x1
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15_SUBTRACT               0x2
#define   MWV207REG_SH_DOT_PRODUCT_TERM_CONFIG_TERM15_ACCUMULATOR            0x3


#define MWV207REG_SH_DOT_PRODUCT_A_SELECT0                                   1:0
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT0_End                                 1
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT0_Start                               0
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT0_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT0_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT0_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT0_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT1                                   3:2
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT1_End                                 3
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT1_Start                               2
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT1_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT1_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT1_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT1_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT2                                   5:4
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT2_End                                 5
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT2_Start                               4
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT2_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT2_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT2_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT2_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT3                                   7:6
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT3_End                                 7
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT3_Start                               6
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT3_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT3_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT3_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT3_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT4                                   9:8
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT4_End                                 9
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT4_Start                               8
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT4_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT4_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT4_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT4_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT5                                 11:10
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT5_End                                11
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT5_Start                              10
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT5_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT5_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT5_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT5_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT6                                 13:12
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT6_End                                13
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT6_Start                              12
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT6_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT6_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT6_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT6_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT7                                 15:14
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT7_End                                15
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT7_Start                              14
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT7_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT7_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT7_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT7_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT8                                 17:16
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT8_End                                17
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT8_Start                              16
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT8_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT8_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT8_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT8_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT9                                 19:18
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT9_End                                19
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT9_Start                              18
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT9_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT9_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT9_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT9_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT10                                21:20
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT10_End                               21
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT10_Start                             20
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT10_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT10_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT10_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT10_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT11                                23:22
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT11_End                               23
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT11_Start                             22
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT11_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT11_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT11_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT11_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT12                                25:24
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT12_End                               25
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT12_Start                             24
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT12_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT12_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT12_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT12_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT13                                27:26
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT13_End                               27
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT13_Start                             26
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT13_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT13_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT13_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT13_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT14                                29:28
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT14_End                               29
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT14_Start                             28
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT14_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT14_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT14_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT14_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_A_SELECT15                                31:30
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT15_End                               31
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT15_Start                             30
#define MWV207REG_SH_DOT_PRODUCT_A_SELECT15_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT15_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT15_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_A_SELECT15_CONSTANTS                      0x2


#define MWV207REG_SH_DOT_PRODUCT_A_BIN0                                      3:0
#define MWV207REG_SH_DOT_PRODUCT_A_BIN0_End                                    3
#define MWV207REG_SH_DOT_PRODUCT_A_BIN0_Start                                  0
#define MWV207REG_SH_DOT_PRODUCT_A_BIN0_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN1                                      7:4
#define MWV207REG_SH_DOT_PRODUCT_A_BIN1_End                                    7
#define MWV207REG_SH_DOT_PRODUCT_A_BIN1_Start                                  4
#define MWV207REG_SH_DOT_PRODUCT_A_BIN1_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN2                                     11:8
#define MWV207REG_SH_DOT_PRODUCT_A_BIN2_End                                   11
#define MWV207REG_SH_DOT_PRODUCT_A_BIN2_Start                                  8
#define MWV207REG_SH_DOT_PRODUCT_A_BIN2_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN3                                    15:12
#define MWV207REG_SH_DOT_PRODUCT_A_BIN3_End                                   15
#define MWV207REG_SH_DOT_PRODUCT_A_BIN3_Start                                 12
#define MWV207REG_SH_DOT_PRODUCT_A_BIN3_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN4                                    19:16
#define MWV207REG_SH_DOT_PRODUCT_A_BIN4_End                                   19
#define MWV207REG_SH_DOT_PRODUCT_A_BIN4_Start                                 16
#define MWV207REG_SH_DOT_PRODUCT_A_BIN4_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN5                                    23:20
#define MWV207REG_SH_DOT_PRODUCT_A_BIN5_End                                   23
#define MWV207REG_SH_DOT_PRODUCT_A_BIN5_Start                                 20
#define MWV207REG_SH_DOT_PRODUCT_A_BIN5_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN6                                    27:24
#define MWV207REG_SH_DOT_PRODUCT_A_BIN6_End                                   27
#define MWV207REG_SH_DOT_PRODUCT_A_BIN6_Start                                 24
#define MWV207REG_SH_DOT_PRODUCT_A_BIN6_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN7                                    31:28
#define MWV207REG_SH_DOT_PRODUCT_A_BIN7_End                                   31
#define MWV207REG_SH_DOT_PRODUCT_A_BIN7_Start                                 28
#define MWV207REG_SH_DOT_PRODUCT_A_BIN7_Type                                 U04


#define MWV207REG_SH_DOT_PRODUCT_A_BIN8                                      3:0
#define MWV207REG_SH_DOT_PRODUCT_A_BIN8_End                                    3
#define MWV207REG_SH_DOT_PRODUCT_A_BIN8_Start                                  0
#define MWV207REG_SH_DOT_PRODUCT_A_BIN8_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN9                                      7:4
#define MWV207REG_SH_DOT_PRODUCT_A_BIN9_End                                    7
#define MWV207REG_SH_DOT_PRODUCT_A_BIN9_Start                                  4
#define MWV207REG_SH_DOT_PRODUCT_A_BIN9_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN10                                    11:8
#define MWV207REG_SH_DOT_PRODUCT_A_BIN10_End                                  11
#define MWV207REG_SH_DOT_PRODUCT_A_BIN10_Start                                 8
#define MWV207REG_SH_DOT_PRODUCT_A_BIN10_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN11                                   15:12
#define MWV207REG_SH_DOT_PRODUCT_A_BIN11_End                                  15
#define MWV207REG_SH_DOT_PRODUCT_A_BIN11_Start                                12
#define MWV207REG_SH_DOT_PRODUCT_A_BIN11_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN12                                   19:16
#define MWV207REG_SH_DOT_PRODUCT_A_BIN12_End                                  19
#define MWV207REG_SH_DOT_PRODUCT_A_BIN12_Start                                16
#define MWV207REG_SH_DOT_PRODUCT_A_BIN12_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN13                                   23:20
#define MWV207REG_SH_DOT_PRODUCT_A_BIN13_End                                  23
#define MWV207REG_SH_DOT_PRODUCT_A_BIN13_Start                                20
#define MWV207REG_SH_DOT_PRODUCT_A_BIN13_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN14                                   27:24
#define MWV207REG_SH_DOT_PRODUCT_A_BIN14_End                                  27
#define MWV207REG_SH_DOT_PRODUCT_A_BIN14_Start                                24
#define MWV207REG_SH_DOT_PRODUCT_A_BIN14_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_A_BIN15                                   31:28
#define MWV207REG_SH_DOT_PRODUCT_A_BIN15_End                                  31
#define MWV207REG_SH_DOT_PRODUCT_A_BIN15_Start                                28
#define MWV207REG_SH_DOT_PRODUCT_A_BIN15_Type                                U04


#define MWV207REG_SH_DOT_PRODUCT_B_SELECT0                                   1:0
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT0_End                                 1
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT0_Start                               0
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT0_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT0_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT0_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT0_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT1                                   3:2
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT1_End                                 3
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT1_Start                               2
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT1_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT1_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT1_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT1_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT2                                   5:4
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT2_End                                 5
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT2_Start                               4
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT2_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT2_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT2_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT2_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT3                                   7:6
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT3_End                                 7
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT3_Start                               6
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT3_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT3_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT3_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT3_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT4                                   9:8
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT4_End                                 9
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT4_Start                               8
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT4_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT4_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT4_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT4_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT5                                 11:10
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT5_End                                11
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT5_Start                              10
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT5_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT5_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT5_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT5_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT6                                 13:12
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT6_End                                13
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT6_Start                              12
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT6_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT6_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT6_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT6_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT7                                 15:14
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT7_End                                15
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT7_Start                              14
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT7_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT7_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT7_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT7_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT8                                 17:16
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT8_End                                17
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT8_Start                              16
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT8_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT8_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT8_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT8_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT9                                 19:18
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT9_End                                19
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT9_Start                              18
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT9_Type                              U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT9_SRC0                            0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT9_SRC1                            0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT9_CONSTANTS                       0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT10                                21:20
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT10_End                               21
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT10_Start                             20
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT10_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT10_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT10_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT10_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT11                                23:22
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT11_End                               23
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT11_Start                             22
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT11_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT11_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT11_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT11_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT12                                25:24
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT12_End                               25
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT12_Start                             24
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT12_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT12_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT12_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT12_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT13                                27:26
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT13_End                               27
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT13_Start                             26
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT13_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT13_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT13_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT13_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT14                                29:28
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT14_End                               29
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT14_Start                             28
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT14_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT14_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT14_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT14_CONSTANTS                      0x2

#define MWV207REG_SH_DOT_PRODUCT_B_SELECT15                                31:30
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT15_End                               31
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT15_Start                             30
#define MWV207REG_SH_DOT_PRODUCT_B_SELECT15_Type                             U02
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT15_SRC0                           0x0
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT15_SRC1                           0x1
#define   MWV207REG_SH_DOT_PRODUCT_B_SELECT15_CONSTANTS                      0x2


#define MWV207REG_SH_DOT_PRODUCT_B_BIN0                                      3:0
#define MWV207REG_SH_DOT_PRODUCT_B_BIN0_End                                    3
#define MWV207REG_SH_DOT_PRODUCT_B_BIN0_Start                                  0
#define MWV207REG_SH_DOT_PRODUCT_B_BIN0_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN1                                      7:4
#define MWV207REG_SH_DOT_PRODUCT_B_BIN1_End                                    7
#define MWV207REG_SH_DOT_PRODUCT_B_BIN1_Start                                  4
#define MWV207REG_SH_DOT_PRODUCT_B_BIN1_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN2                                     11:8
#define MWV207REG_SH_DOT_PRODUCT_B_BIN2_End                                   11
#define MWV207REG_SH_DOT_PRODUCT_B_BIN2_Start                                  8
#define MWV207REG_SH_DOT_PRODUCT_B_BIN2_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN3                                    15:12
#define MWV207REG_SH_DOT_PRODUCT_B_BIN3_End                                   15
#define MWV207REG_SH_DOT_PRODUCT_B_BIN3_Start                                 12
#define MWV207REG_SH_DOT_PRODUCT_B_BIN3_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN4                                    19:16
#define MWV207REG_SH_DOT_PRODUCT_B_BIN4_End                                   19
#define MWV207REG_SH_DOT_PRODUCT_B_BIN4_Start                                 16
#define MWV207REG_SH_DOT_PRODUCT_B_BIN4_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN5                                    23:20
#define MWV207REG_SH_DOT_PRODUCT_B_BIN5_End                                   23
#define MWV207REG_SH_DOT_PRODUCT_B_BIN5_Start                                 20
#define MWV207REG_SH_DOT_PRODUCT_B_BIN5_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN6                                    27:24
#define MWV207REG_SH_DOT_PRODUCT_B_BIN6_End                                   27
#define MWV207REG_SH_DOT_PRODUCT_B_BIN6_Start                                 24
#define MWV207REG_SH_DOT_PRODUCT_B_BIN6_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN7                                    31:28
#define MWV207REG_SH_DOT_PRODUCT_B_BIN7_End                                   31
#define MWV207REG_SH_DOT_PRODUCT_B_BIN7_Start                                 28
#define MWV207REG_SH_DOT_PRODUCT_B_BIN7_Type                                 U04


#define MWV207REG_SH_DOT_PRODUCT_B_BIN8                                      3:0
#define MWV207REG_SH_DOT_PRODUCT_B_BIN8_End                                    3
#define MWV207REG_SH_DOT_PRODUCT_B_BIN8_Start                                  0
#define MWV207REG_SH_DOT_PRODUCT_B_BIN8_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN9                                      7:4
#define MWV207REG_SH_DOT_PRODUCT_B_BIN9_End                                    7
#define MWV207REG_SH_DOT_PRODUCT_B_BIN9_Start                                  4
#define MWV207REG_SH_DOT_PRODUCT_B_BIN9_Type                                 U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN10                                    11:8
#define MWV207REG_SH_DOT_PRODUCT_B_BIN10_End                                  11
#define MWV207REG_SH_DOT_PRODUCT_B_BIN10_Start                                 8
#define MWV207REG_SH_DOT_PRODUCT_B_BIN10_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN11                                   15:12
#define MWV207REG_SH_DOT_PRODUCT_B_BIN11_End                                  15
#define MWV207REG_SH_DOT_PRODUCT_B_BIN11_Start                                12
#define MWV207REG_SH_DOT_PRODUCT_B_BIN11_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN12                                   19:16
#define MWV207REG_SH_DOT_PRODUCT_B_BIN12_End                                  19
#define MWV207REG_SH_DOT_PRODUCT_B_BIN12_Start                                16
#define MWV207REG_SH_DOT_PRODUCT_B_BIN12_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN13                                   23:20
#define MWV207REG_SH_DOT_PRODUCT_B_BIN13_End                                  23
#define MWV207REG_SH_DOT_PRODUCT_B_BIN13_Start                                20
#define MWV207REG_SH_DOT_PRODUCT_B_BIN13_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN14                                   27:24
#define MWV207REG_SH_DOT_PRODUCT_B_BIN14_End                                  27
#define MWV207REG_SH_DOT_PRODUCT_B_BIN14_Start                                24
#define MWV207REG_SH_DOT_PRODUCT_B_BIN14_Type                                U04

#define MWV207REG_SH_DOT_PRODUCT_B_BIN15                                   31:28
#define MWV207REG_SH_DOT_PRODUCT_B_BIN15_End                                  31
#define MWV207REG_SH_DOT_PRODUCT_B_BIN15_Start                                28
#define MWV207REG_SH_DOT_PRODUCT_B_BIN15_Type                                U04



#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_POST_SHIFT                      4:0
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_POST_SHIFT_End                    4
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_POST_SHIFT_Start                  0
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_POST_SHIFT_Type                 U05


#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE                  10:8
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_End                10
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_Start               8
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_Type              U03
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_FLOAT32         0x0
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_FLOAT16         0x1
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_SIGNED32        0x2
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_SIGNED16        0x3
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_SIGNED8         0x4
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_UNSIGNED32      0x5
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_UNSIGNED16      0x6
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_CONSTANT_TYPE_UNSIGNED8       0x7


#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE              14:12
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_End             14
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_Start           12
#define MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_Type           U03
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_FLOAT32      0x0
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_FLOAT16      0x1
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED32     0x2
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED16     0x3
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED8      0x4
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED32   0x5
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED16   0x6
#define   MWV207REG_SH_DOT_PRODUCT_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED8    0x7


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_X                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_X_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_X_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_X_Type                            U32


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Y                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Y_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Y_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Y_Type                            U32


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Z                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Z_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Z_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_Z_Type                            U32


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_W                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_W_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_W_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT0_W_Type                            U32


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_X                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_X_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_X_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_X_Type                            U32


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Y                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Y_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Y_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Y_Type                            U32


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Z                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Z_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Z_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_Z_Type                            U32


#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_W                                31:0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_W_End                              31
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_W_Start                             0
#define MWV207REG_SH_DOT_PRODUCT_CONSTANT1_W_Type                            U32



#define MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX                              3:0
#define MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX_End                            3
#define MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX_Start                          0
#define MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX_Type                         U04
#define   MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX_TERM_CONFIG                0x0
#define   MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX_BIN_SELECT                 0x2
#define   MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX_MISC_CONFIG                0x7
#define   MWV207REG_SH_DOT_PRODUCT32_LAYOUT_INDEX_CONSTANTS                  0x8


#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0                         1:0
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0_End                       1
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0_Start                     0
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM0_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1                         3:2
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1_End                       3
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1_Start                     2
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM1_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2                         5:4
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2_End                       5
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2_Start                     4
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM2_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3                         7:6
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3_End                       7
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3_Start                     6
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM3_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4                         9:8
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4_End                       9
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4_Start                     8
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM4_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5                       11:10
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5_End                      11
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5_Start                    10
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM5_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6                       13:12
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6_End                      13
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6_Start                    12
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM6_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7                       15:14
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7_End                      15
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7_Start                    14
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM7_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8                       17:16
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8_End                      17
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8_Start                    16
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM8_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9                       19:18
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9_End                      19
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9_Start                    18
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9_Type                    U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9_DISABLED              0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9_ADD                   0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9_SUBTRACT              0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM9_ACCUMULATOR           0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10                      21:20
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10_End                     21
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10_Start                   20
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM10_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11                      23:22
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11_End                     23
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11_Start                   22
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM11_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12                      25:24
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12_End                     25
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12_Start                   24
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM12_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13                      27:26
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13_End                     27
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13_Start                   26
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM13_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14                      29:28
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14_End                     29
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14_Start                   28
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM14_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15                      31:30
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15_End                     31
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15_Start                   30
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM15_ACCUMULATOR          0x3


#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16                        1:0
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16_End                      1
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16_Start                    0
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM16_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17                        3:2
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17_End                      3
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17_Start                    2
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM17_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18                        5:4
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18_End                      5
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18_Start                    4
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM18_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19                        7:6
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19_End                      7
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19_Start                    6
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM19_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20                        9:8
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20_End                      9
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20_Start                    8
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM20_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21                      11:10
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21_End                     11
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21_Start                   10
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM21_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22                      13:12
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22_End                     13
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22_Start                   12
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM22_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23                      15:14
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23_End                     15
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23_Start                   14
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM23_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24                      17:16
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24_End                     17
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24_Start                   16
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM24_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25                      19:18
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25_End                     19
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25_Start                   18
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM25_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26                      21:20
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26_End                     21
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26_Start                   20
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM26_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27                      23:22
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27_End                     23
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27_Start                   22
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM27_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28                      25:24
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28_End                     25
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28_Start                   24
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM28_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29                      27:26
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29_End                     27
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29_Start                   26
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM29_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30                      29:28
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30_End                     29
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30_Start                   28
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM30_ACCUMULATOR          0x3

#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31                      31:30
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31_End                     31
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31_Start                   30
#define MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31_Type                   U02
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31_DISABLED             0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31_ADD                  0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31_SUBTRACT             0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TERM_CONFIG_TERM31_ACCUMULATOR          0x3


#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN0                           4:0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN0_End                         4
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN0_Start                       0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN0_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN1                           9:5
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN1_End                         9
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN1_Start                       5
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN1_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN2                         14:10
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN2_End                        14
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN2_Start                      10
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN2_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN3                         19:15
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN3_End                        19
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN3_Start                      15
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN3_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN4                         24:20
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN4_End                        24
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN4_Start                      20
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN4_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN5                         29:25
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN5_End                        29
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN5_Start                      25
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN5_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_A                       31:30
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_A_End                      31
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_A_Start                    30
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_A_Type                    U02


#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_B                         2:0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_B_End                       2
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_B_Start                     0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN6_B_Type                    U03

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN7                           7:3
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN7_End                         7
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN7_Start                       3
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN7_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN8                          12:8
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN8_End                        12
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN8_Start                       8
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN8_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN9                         17:13
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN9_End                        17
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN9_Start                      13
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN9_Type                      U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN10                        22:18
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN10_End                       22
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN10_Start                     18
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN10_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN11                        27:23
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN11_End                       27
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN11_Start                     23
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN11_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_A                      31:28
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_A_End                     31
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_A_Start                   28
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_A_Type                   U04


#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_B                        0:0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_B_End                      0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_B_Start                    0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN12_B_Type                   U01

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN13                          5:1
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN13_End                        5
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN13_Start                      1
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN13_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN14                         10:6
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN14_End                       10
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN14_Start                      6
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN14_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN15                        15:11
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN15_End                       15
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN15_Start                     11
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN15_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN16                        20:16
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN16_End                       20
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN16_Start                     16
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN16_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN17                        25:21
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN17_End                       25
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN17_Start                     21
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN17_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN18                        30:26
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN18_End                       30
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN18_Start                     26
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN18_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_A                      31:31
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_A_End                     31
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_A_Start                   31
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_A_Type                   U01


#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_B                        3:0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_B_End                      3
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_B_Start                    0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN19_B_Type                   U04

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN20                          8:4
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN20_End                        8
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN20_Start                      4
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN20_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN21                         13:9
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN21_End                       13
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN21_Start                      9
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN21_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN22                        18:14
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN22_End                       18
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN22_Start                     14
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN22_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN23                        23:19
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN23_End                       23
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN23_Start                     19
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN23_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN24                        28:24
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN24_End                       28
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN24_Start                     24
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN24_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_A                      31:29
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_A_End                     31
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_A_Start                   29
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_A_Type                   U03


#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_B                        1:0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_B_End                      1
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_B_Start                    0
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN25_B_Type                   U02

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN26                          6:2
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN26_End                        6
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN26_Start                      2
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN26_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN27                         11:7
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN27_End                       11
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN27_Start                      7
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN27_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN28                        16:12
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN28_End                       16
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN28_Start                     12
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN28_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN29                        21:17
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN29_End                       21
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN29_Start                     17
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN29_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN30                        26:22
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN30_End                       26
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN30_Start                     22
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN30_Type                     U05

#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN31                        31:27
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN31_End                       31
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN31_Start                     27
#define MWV207REG_SH_DOT_PRODUCT32_BIN_SELECT_BIN31_Type                     U05



#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_POST_SHIFT                    4:0
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_POST_SHIFT_End                  4
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_POST_SHIFT_Start                0
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_POST_SHIFT_Type               U05


#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE                10:8
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_End              10
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_Start             8
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_Type            U03
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_FLOAT32       0x0
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_FLOAT16       0x1
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_SIGNED32      0x2
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_SIGNED16      0x3
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_SIGNED8       0x4
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_UNSIGNED32    0x5
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_UNSIGNED16    0x6
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_CONSTANT_TYPE_UNSIGNED8     0x7


#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE            14:12
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_End           14
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_Start         12
#define MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_Type         U03
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_FLOAT32    0x0
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_FLOAT16    0x1
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED32   0x2
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED16   0x3
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED8    0x4
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED32 0x5
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED16 0x6
#define   MWV207REG_SH_DOT_PRODUCT32_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED8  0x7


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN0                            7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN0_End                          7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN0_Start                        0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN0_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN1                           15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN1_End                         15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN1_Start                        8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN1_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN2                          23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN2_End                         23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN2_Start                       16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN2_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN3                          31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN3_End                         31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN3_Start                       24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN3_Type                       U08


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN4                            7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN4_End                          7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN4_Start                        0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN4_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN5                           15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN5_End                         15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN5_Start                        8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN5_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN6                          23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN6_End                         23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN6_Start                       16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN6_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN7                          31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN7_End                         31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN7_Start                       24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN7_Type                       U08


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN8                            7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN8_End                          7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN8_Start                        0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN8_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN9                           15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN9_End                         15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN9_Start                        8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN9_Type                       U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN10                         23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN10_End                        23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN10_Start                      16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN10_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN11                         31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN11_End                        31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN11_Start                      24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN11_Type                      U08


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN12                           7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN12_End                         7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN12_Start                       0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN12_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN13                          15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN13_End                        15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN13_Start                       8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN13_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN14                         23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN14_End                        23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN14_Start                      16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN14_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN15                         31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN15_End                        31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN15_Start                      24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN15_Type                      U08


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN16                           7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN16_End                         7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN16_Start                       0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN16_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN17                          15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN17_End                        15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN17_Start                       8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN17_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN18                         23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN18_End                        23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN18_Start                      16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN18_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN19                         31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN19_End                        31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN19_Start                      24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN19_Type                      U08


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN20                           7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN20_End                         7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN20_Start                       0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN20_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN21                          15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN21_End                        15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN21_Start                       8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN21_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN22                         23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN22_End                        23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN22_Start                      16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN22_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN23                         31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN23_End                        31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN23_Start                      24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN23_Type                      U08


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN24                           7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN24_End                         7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN24_Start                       0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN24_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN25                          15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN25_End                        15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN25_Start                       8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN25_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN26                         23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN26_End                        23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN26_Start                      16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN26_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN27                         31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN27_End                        31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN27_Start                      24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN27_Type                      U08


#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN28                           7:0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN28_End                         7
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN28_Start                       0
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN28_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN29                          15:8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN29_End                        15
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN29_Start                       8
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN29_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN30                         23:16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN30_End                        23
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN30_Start                      16
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN30_Type                      U08

#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN31                         31:24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN31_End                        31
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN31_Start                      24
#define MWV207REG_SH_DOT_PRODUCT32_CONSTANTS_BIN31_Type                      U08



#define MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX                         3:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX_End                       3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX_Start                     0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX_Type                    U04
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX_TERM_CONFIG           0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX_BIN0_SELECT           0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX_MISC_CONFIG           0x7
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_LAYOUT_INDEX_BIN1_SELECT           0x8


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0                    1:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0_End                  1
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0_Start                0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM0_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1                    3:2
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1_End                  3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1_Start                2
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM1_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2                    5:4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2_End                  5
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2_Start                4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM2_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3                    7:6
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3_End                  7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3_Start                6
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM3_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4                    9:8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4_End                  9
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4_Start                8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM4_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5                  11:10
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5_End                 11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5_Start               10
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM5_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6                  13:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6_End                 13
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6_Start               12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM6_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7                  15:14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7_End                 15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7_Start               14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM7_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8                  17:16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8_End                 17
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8_Start               16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM8_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9                  19:18
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9_End                 19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9_Start               18
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9_Type               U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9_DISABLED         0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9_ADD              0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9_SUBTRACT         0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM9_ACCUMULATOR      0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10                 21:20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10_End                21
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10_Start              20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM10_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11                 23:22
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11_End                23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11_Start              22
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM11_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12                 25:24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12_End                25
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12_Start              24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM12_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13                 27:26
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13_End                27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13_Start              26
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM13_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14                 29:28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14_End                29
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14_Start              28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM14_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15                 31:30
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15_End                31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15_Start              30
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM15_ACCUMULATOR     0x3


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16                   1:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16_End                 1
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16_Start               0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM16_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17                   3:2
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17_End                 3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17_Start               2
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM17_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18                   5:4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18_End                 5
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18_Start               4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM18_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19                   7:6
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19_End                 7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19_Start               6
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM19_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20                   9:8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20_End                 9
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20_Start               8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM20_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21                 11:10
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21_End                11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21_Start              10
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM21_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22                 13:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22_End                13
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22_Start              12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM22_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23                 15:14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23_End                15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23_Start              14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM23_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24                 17:16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24_End                17
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24_Start              16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM24_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25                 19:18
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25_End                19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25_Start              18
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM25_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26                 21:20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26_End                21
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26_Start              20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM26_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27                 23:22
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27_End                23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27_Start              22
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM27_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28                 25:24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28_End                25
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28_Start              24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM28_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29                 27:26
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29_End                27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29_Start              26
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM29_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30                 29:28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30_End                29
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30_Start              28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM30_ACCUMULATOR     0x3

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31                 31:30
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31_End                31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31_Start              30
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31_Type              U02
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31_DISABLED        0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31_ADD             0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31_SUBTRACT        0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_TERM_CONFIG_TERM31_ACCUMULATOR     0x3


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN0                     4:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN0_End                   4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN0_Start                 0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN0_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN1                     9:5
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN1_End                   9
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN1_Start                 5
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN1_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN2                   14:10
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN2_End                  14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN2_Start                10
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN2_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN3                   19:15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN3_End                  19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN3_Start                15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN3_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN4                   24:20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN4_End                  24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN4_Start                20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN4_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN5                   29:25
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN5_End                  29
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN5_Start                25
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN5_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_A                 31:30
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_A_End                31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_A_Start              30
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_A_Type              U02


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_B                   2:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_B_End                 2
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_B_Start               0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN6_B_Type              U03

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN7                     7:3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN7_End                   7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN7_Start                 3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN7_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN8                    12:8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN8_End                  12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN8_Start                 8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN8_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN9                   17:13
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN9_End                  17
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN9_Start                13
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN9_Type                U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN10                  22:18
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN10_End                 22
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN10_Start               18
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN10_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN11                  27:23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN11_End                 27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN11_Start               23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN11_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_A                31:28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_A_End               31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_A_Start             28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_A_Type             U04


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_B                  0:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_B_End                0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_B_Start              0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN12_B_Type             U01

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN13                    5:1
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN13_End                  5
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN13_Start                1
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN13_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN14                   10:6
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN14_End                 10
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN14_Start                6
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN14_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN15                  15:11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN15_End                 15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN15_Start               11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN15_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN16                  20:16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN16_End                 20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN16_Start               16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN16_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN17                  25:21
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN17_End                 25
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN17_Start               21
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN17_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN18                  30:26
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN18_End                 30
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN18_Start               26
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN18_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_A                31:31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_A_End               31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_A_Start             31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_A_Type             U01


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_B                  3:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_B_End                3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_B_Start              0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN19_B_Type             U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN20                    8:4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN20_End                  8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN20_Start                4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN20_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN21                   13:9
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN21_End                 13
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN21_Start                9
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN21_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN22                  18:14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN22_End                 18
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN22_Start               14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN22_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN23                  23:19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN23_End                 23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN23_Start               19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN23_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN24                  28:24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN24_End                 28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN24_Start               24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN24_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_A                31:29
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_A_End               31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_A_Start             29
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_A_Type             U03


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_B                  1:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_B_End                1
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_B_Start              0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN25_B_Type             U02

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN26                    6:2
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN26_End                  6
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN26_Start                2
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN26_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN27                   11:7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN27_End                 11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN27_Start                7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN27_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN28                  16:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN28_End                 16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN28_Start               12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN28_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN29                  21:17
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN29_End                 21
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN29_Start               17
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN29_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN30                  26:22
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN30_End                 26
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN30_Start               22
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN30_Type               U05

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN31                  31:27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN31_End                 31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN31_Start               27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN0_SELECT_BIN31_Type               U05



#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_POST_SHIFT               4:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_POST_SHIFT_End             4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_POST_SHIFT_Start           0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_POST_SHIFT_Type          U05


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE       14:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_End      14
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_Start    12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_Type    U03
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_FLOAT32 0x0
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_FLOAT16 0x1
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED32 0x2
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED16 0x3
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_SIGNED8 0x4
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED32 0x5
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED16 0x6
#define   MWV207REG_SH_DOT_PRODUCT32_TEMP_MISC_CONFIG_ACCUMULATOR_TYPE_UNSIGNED8 0x7


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN0                     3:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN0_End                   3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN0_Start                 0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN0_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN1                     7:4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN1_End                   7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN1_Start                 4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN1_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN2                    11:8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN2_End                  11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN2_Start                 8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN2_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN3                   15:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN3_End                  15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN3_Start                12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN3_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN4                   19:16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN4_End                  19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN4_Start                16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN4_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN5                   23:20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN5_End                  23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN5_Start                20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN5_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN6                   27:24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN6_End                  27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN6_Start                24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN6_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN7                   31:28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN7_End                  31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN7_Start                28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN7_Type                U04


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN8                     3:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN8_End                   3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN8_Start                 0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN8_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN9                     7:4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN9_End                   7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN9_Start                 4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN9_Type                U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN10                   11:8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN10_End                 11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN10_Start                8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN10_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN11                  15:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN11_End                 15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN11_Start               12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN11_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN12                  19:16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN12_End                 19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN12_Start               16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN12_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN13                  23:20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN13_End                 23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN13_Start               20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN13_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN14                  27:24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN14_End                 27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN14_Start               24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN14_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN15                  31:28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN15_End                 31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN15_Start               28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN15_Type               U04


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN16                    3:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN16_End                  3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN16_Start                0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN16_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN17                    7:4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN17_End                  7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN17_Start                4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN17_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN18                   11:8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN18_End                 11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN18_Start                8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN18_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN19                  15:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN19_End                 15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN19_Start               12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN19_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN20                  19:16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN20_End                 19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN20_Start               16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN20_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN21                  23:20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN21_End                 23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN21_Start               20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN21_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN22                  27:24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN22_End                 27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN22_Start               24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN22_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN23                  31:28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN23_End                 31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN23_Start               28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN23_Type               U04


#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN24                    3:0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN24_End                  3
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN24_Start                0
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN24_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN25                    7:4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN25_End                  7
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN25_Start                4
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN25_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN26                   11:8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN26_End                 11
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN26_Start                8
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN26_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN27                  15:12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN27_End                 15
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN27_Start               12
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN27_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN28                  19:16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN28_End                 19
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN28_Start               16
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN28_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN29                  23:20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN29_End                 23
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN29_Start               20
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN29_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN30                  27:24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN30_End                 27
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN30_Start               24
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN30_Type               U04

#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN31                  31:28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN31_End                 31
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN31_Start               28
#define MWV207REG_SH_DOT_PRODUCT32_TEMP_BIN1_SELECT_BIN31_Type               U04


#endif


