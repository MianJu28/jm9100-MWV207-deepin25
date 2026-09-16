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




#ifndef __jmgpuPerformance_h__
#define __jmgpuPerformance_h__





#define mwv207regPCTimeStampRegAddrs                                      0x4C00
#define MWV207REG_PC_TIME_STAMP_Address                                  0x13000
#define MWV207REG_PC_TIME_STAMP_MSB                                           15
#define MWV207REG_PC_TIME_STAMP_LSB                                            0
#define MWV207REG_PC_TIME_STAMP_BLK                                            0
#define MWV207REG_PC_TIME_STAMP_Count                                          1
#define MWV207REG_PC_TIME_STAMP_FieldMask                             0xFFFFFFFF
#define MWV207REG_PC_TIME_STAMP_ReadMask                              0xFFFFFFFF
#define MWV207REG_PC_TIME_STAMP_WriteMask                             0xFFFFFFFF
#define MWV207REG_PC_TIME_STAMP_ResetValue                            0x00000000

#define MWV207REG_PC_TIME_STAMP_COUNTER                                     31:0
#define MWV207REG_PC_TIME_STAMP_COUNTER_End                                   31
#define MWV207REG_PC_TIME_STAMP_COUNTER_Start                                  0
#define MWV207REG_PC_TIME_STAMP_COUNTER_Type                                 U32




#define mwv207regPCComamdBytesFetchedRegAddrs                             0x4C01
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_Address                        0x13004
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_MSB                                 15
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_LSB                                  0
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_BLK                                  0
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_Count                                1
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_FieldMask                   0xFFFFFFFF
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_ReadMask                    0xFFFFFFFF
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_WriteMask                   0xFFFFFFFF
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_ResetValue                  0x00000000

#define MWV207REG_PC_COMAMD_BYTES_FETCHED_COUNTER                           31:0
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_COUNTER_End                         31
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_COUNTER_Start                        0
#define MWV207REG_PC_COMAMD_BYTES_FETCHED_COUNTER_Type                       U32




#define mwv207regPCDrawCommandsRegAddrs                                   0x4C02
#define MWV207REG_PC_DRAW_COMMANDS_Address                               0x13008
#define MWV207REG_PC_DRAW_COMMANDS_MSB                                        15
#define MWV207REG_PC_DRAW_COMMANDS_LSB                                         0
#define MWV207REG_PC_DRAW_COMMANDS_BLK                                         0
#define MWV207REG_PC_DRAW_COMMANDS_Count                                       1
#define MWV207REG_PC_DRAW_COMMANDS_FieldMask                          0xFFFFFFFF
#define MWV207REG_PC_DRAW_COMMANDS_ReadMask                           0xFFFFFFFF
#define MWV207REG_PC_DRAW_COMMANDS_WriteMask                          0xFFFFFFFF
#define MWV207REG_PC_DRAW_COMMANDS_ResetValue                         0x00000000

#define MWV207REG_PC_DRAW_COMMANDS_COUNTER                                  31:0
#define MWV207REG_PC_DRAW_COMMANDS_COUNTER_End                                31
#define MWV207REG_PC_DRAW_COMMANDS_COUNTER_Start                               0
#define MWV207REG_PC_DRAW_COMMANDS_COUNTER_Type                              U32




#define mwv207regPCIndexBytesFetchedRegAddrs                              0x4C03
#define MWV207REG_PC_INDEX_BYTES_FETCHED_Address                         0x1300C
#define MWV207REG_PC_INDEX_BYTES_FETCHED_MSB                                  15
#define MWV207REG_PC_INDEX_BYTES_FETCHED_LSB                                   0
#define MWV207REG_PC_INDEX_BYTES_FETCHED_BLK                                   0
#define MWV207REG_PC_INDEX_BYTES_FETCHED_Count                                 1
#define MWV207REG_PC_INDEX_BYTES_FETCHED_FieldMask                    0xFFFFFFFF
#define MWV207REG_PC_INDEX_BYTES_FETCHED_ReadMask                     0xFFFFFFFF
#define MWV207REG_PC_INDEX_BYTES_FETCHED_WriteMask                    0xFFFFFFFF
#define MWV207REG_PC_INDEX_BYTES_FETCHED_ResetValue                   0x00000000

#define MWV207REG_PC_INDEX_BYTES_FETCHED_COUNTER                            31:0
#define MWV207REG_PC_INDEX_BYTES_FETCHED_COUNTER_End                          31
#define MWV207REG_PC_INDEX_BYTES_FETCHED_COUNTER_Start                         0
#define MWV207REG_PC_INDEX_BYTES_FETCHED_COUNTER_Type                        U32




#define mwv207regPCIndexCacheHitRegAddrs                                  0x4C04
#define MWV207REG_PC_INDEX_CACHE_HIT_Address                             0x13010
#define MWV207REG_PC_INDEX_CACHE_HIT_MSB                                      15
#define MWV207REG_PC_INDEX_CACHE_HIT_LSB                                       0
#define MWV207REG_PC_INDEX_CACHE_HIT_BLK                                       0
#define MWV207REG_PC_INDEX_CACHE_HIT_Count                                     1
#define MWV207REG_PC_INDEX_CACHE_HIT_FieldMask                        0xFFFFFFFF
#define MWV207REG_PC_INDEX_CACHE_HIT_ReadMask                         0xFFFFFFFF
#define MWV207REG_PC_INDEX_CACHE_HIT_WriteMask                        0xFFFFFFFF
#define MWV207REG_PC_INDEX_CACHE_HIT_ResetValue                       0x00000000

#define MWV207REG_PC_INDEX_CACHE_HIT_COUNTER                                31:0
#define MWV207REG_PC_INDEX_CACHE_HIT_COUNTER_End                              31
#define MWV207REG_PC_INDEX_CACHE_HIT_COUNTER_Start                             0
#define MWV207REG_PC_INDEX_CACHE_HIT_COUNTER_Type                            U32




#define mwv207regPCVertexCountRegAddrs                                    0x4C05
#define MWV207REG_PC_VERTEX_COUNT_Address                                0x13014
#define MWV207REG_PC_VERTEX_COUNT_MSB                                         15
#define MWV207REG_PC_VERTEX_COUNT_LSB                                          0
#define MWV207REG_PC_VERTEX_COUNT_BLK                                          0
#define MWV207REG_PC_VERTEX_COUNT_Count                                        1
#define MWV207REG_PC_VERTEX_COUNT_FieldMask                           0xFFFFFFFF
#define MWV207REG_PC_VERTEX_COUNT_ReadMask                            0xFFFFFFFF
#define MWV207REG_PC_VERTEX_COUNT_WriteMask                           0xFFFFFFFF
#define MWV207REG_PC_VERTEX_COUNT_ResetValue                          0x00000000

#define MWV207REG_PC_VERTEX_COUNT_COUNTER                                   31:0
#define MWV207REG_PC_VERTEX_COUNT_COUNTER_End                                 31
#define MWV207REG_PC_VERTEX_COUNT_COUNTER_Start                                0
#define MWV207REG_PC_VERTEX_COUNT_COUNTER_Type                               U32




#define mwv207regPCVertexBytesFetchedRegAddrs                             0x4C06
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_Address                        0x13018
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_MSB                                 15
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_LSB                                  0
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_BLK                                  0
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_Count                                1
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_FieldMask                   0xFFFFFFFF
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_ReadMask                    0xFFFFFFFF
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_WriteMask                   0xFFFFFFFF
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_ResetValue                  0x00000000

#define MWV207REG_PC_VERTEX_BYTES_FETCHED_COUNTER                           31:0
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_COUNTER_End                         31
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_COUNTER_Start                        0
#define MWV207REG_PC_VERTEX_BYTES_FETCHED_COUNTER_Type                       U32




#define mwv207regPCTotalVertexRegAddrs                                    0x4C07
#define MWV207REG_PC_TOTAL_VERTEX_Address                                0x1301C
#define MWV207REG_PC_TOTAL_VERTEX_MSB                                         15
#define MWV207REG_PC_TOTAL_VERTEX_LSB                                          0
#define MWV207REG_PC_TOTAL_VERTEX_BLK                                          0
#define MWV207REG_PC_TOTAL_VERTEX_Count                                        1
#define MWV207REG_PC_TOTAL_VERTEX_FieldMask                           0xFFFFFFFF
#define MWV207REG_PC_TOTAL_VERTEX_ReadMask                            0xFFFFFFFF
#define MWV207REG_PC_TOTAL_VERTEX_WriteMask                           0xFFFFFFFF
#define MWV207REG_PC_TOTAL_VERTEX_ResetValue                          0x00000000

#define MWV207REG_PC_TOTAL_VERTEX_COUNTER                                   31:0
#define MWV207REG_PC_TOTAL_VERTEX_COUNTER_End                                 31
#define MWV207REG_PC_TOTAL_VERTEX_COUNTER_Start                                0
#define MWV207REG_PC_TOTAL_VERTEX_COUNTER_Type                               U32




#define mwv207regPCTotalPrimitiveRegAddrs                                 0x4C08
#define MWV207REG_PC_TOTAL_PRIMITIVE_Address                             0x13020
#define MWV207REG_PC_TOTAL_PRIMITIVE_MSB                                      15
#define MWV207REG_PC_TOTAL_PRIMITIVE_LSB                                       0
#define MWV207REG_PC_TOTAL_PRIMITIVE_BLK                                       0
#define MWV207REG_PC_TOTAL_PRIMITIVE_Count                                     1
#define MWV207REG_PC_TOTAL_PRIMITIVE_FieldMask                        0xFFFFFFFF
#define MWV207REG_PC_TOTAL_PRIMITIVE_ReadMask                         0xFFFFFFFF
#define MWV207REG_PC_TOTAL_PRIMITIVE_WriteMask                        0xFFFFFFFF
#define MWV207REG_PC_TOTAL_PRIMITIVE_ResetValue                       0x00000000

#define MWV207REG_PC_TOTAL_PRIMITIVE_COUNTER                                31:0
#define MWV207REG_PC_TOTAL_PRIMITIVE_COUNTER_End                              31
#define MWV207REG_PC_TOTAL_PRIMITIVE_COUNTER_Start                             0
#define MWV207REG_PC_TOTAL_PRIMITIVE_COUNTER_Type                            U32




#define mwv207regPCTrivialRejectPrimitiveRegAddrs                         0x4C09
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_Address                    0x13024
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_MSB                             15
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_LSB                              0
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_BLK                              0
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_Count                            1
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_FieldMask               0xFFFFFFFF
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_ReadMask                0xFFFFFFFF
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_WriteMask               0xFFFFFFFF
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_ResetValue              0x00000000

#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_COUNTER                       31:0
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_COUNTER_End                     31
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_COUNTER_Start                    0
#define MWV207REG_PC_TRIVIAL_REJECT_PRIMITIVE_COUNTER_Type                   U32




#define mwv207regPCCulledPrimitiveRegAddrs                                0x4C0A
#define MWV207REG_PC_CULLED_PRIMITIVE_Address                            0x13028
#define MWV207REG_PC_CULLED_PRIMITIVE_MSB                                     15
#define MWV207REG_PC_CULLED_PRIMITIVE_LSB                                      0
#define MWV207REG_PC_CULLED_PRIMITIVE_BLK                                      0
#define MWV207REG_PC_CULLED_PRIMITIVE_Count                                    1
#define MWV207REG_PC_CULLED_PRIMITIVE_FieldMask                       0xFFFFFFFF
#define MWV207REG_PC_CULLED_PRIMITIVE_ReadMask                        0xFFFFFFFF
#define MWV207REG_PC_CULLED_PRIMITIVE_WriteMask                       0xFFFFFFFF
#define MWV207REG_PC_CULLED_PRIMITIVE_ResetValue                      0x00000000

#define MWV207REG_PC_CULLED_PRIMITIVE_COUNTER                               31:0
#define MWV207REG_PC_CULLED_PRIMITIVE_COUNTER_End                             31
#define MWV207REG_PC_CULLED_PRIMITIVE_COUNTER_Start                            0
#define MWV207REG_PC_CULLED_PRIMITIVE_COUNTER_Type                           U32




#define mwv207regPCDepthClippedPrimitiveRegAddrs                          0x4C0B
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_Address                     0x1302C
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_MSB                              15
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_LSB                               0
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_BLK                               0
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_Count                             1
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_FieldMask                0xFFFFFFFF
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_ReadMask                 0xFFFFFFFF
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_WriteMask                0xFFFFFFFF
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_ResetValue               0x00000000

#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_COUNTER                        31:0
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_COUNTER_End                      31
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_COUNTER_Start                     0
#define MWV207REG_PC_DEPTH_CLIPPED_PRIMITIVE_COUNTER_Type                    U32




#define mwv207regPCFrustumClippedPrimitiveRegAddrs                        0x4C0C
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_Address                   0x13030
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_MSB                            15
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_LSB                             0
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_BLK                             0
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_Count                           1
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_FieldMask              0xFFFFFFFF
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_ReadMask               0xFFFFFFFF
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_WriteMask              0xFFFFFFFF
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_ResetValue             0x00000000

#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_COUNTER                      31:0
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_COUNTER_End                    31
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_COUNTER_Start                   0
#define MWV207REG_PC_FRUSTUM_CLIPPED_PRIMITIVE_COUNTER_Type                  U32




#define mwv207regPCOutputPrimitiveRegAddrs                                0x4C0D
#define MWV207REG_PC_OUTPUT_PRIMITIVE_Address                            0x13034
#define MWV207REG_PC_OUTPUT_PRIMITIVE_MSB                                     15
#define MWV207REG_PC_OUTPUT_PRIMITIVE_LSB                                      0
#define MWV207REG_PC_OUTPUT_PRIMITIVE_BLK                                      0
#define MWV207REG_PC_OUTPUT_PRIMITIVE_Count                                    1
#define MWV207REG_PC_OUTPUT_PRIMITIVE_FieldMask                       0xFFFFFFFF
#define MWV207REG_PC_OUTPUT_PRIMITIVE_ReadMask                        0xFFFFFFFF
#define MWV207REG_PC_OUTPUT_PRIMITIVE_WriteMask                       0xFFFFFFFF
#define MWV207REG_PC_OUTPUT_PRIMITIVE_ResetValue                      0x00000000

#define MWV207REG_PC_OUTPUT_PRIMITIVE_COUNTER                               31:0
#define MWV207REG_PC_OUTPUT_PRIMITIVE_COUNTER_End                             31
#define MWV207REG_PC_OUTPUT_PRIMITIVE_COUNTER_Start                            0
#define MWV207REG_PC_OUTPUT_PRIMITIVE_COUNTER_Type                           U32




#define mwv207regPCCulledTrianglesRegAddrs                                0x4C0E
#define MWV207REG_PC_CULLED_TRIANGLES_Address                            0x13038
#define MWV207REG_PC_CULLED_TRIANGLES_MSB                                     15
#define MWV207REG_PC_CULLED_TRIANGLES_LSB                                      0
#define MWV207REG_PC_CULLED_TRIANGLES_BLK                                      0
#define MWV207REG_PC_CULLED_TRIANGLES_Count                                    1
#define MWV207REG_PC_CULLED_TRIANGLES_FieldMask                       0xFFFFFFFF
#define MWV207REG_PC_CULLED_TRIANGLES_ReadMask                        0xFFFFFFFF
#define MWV207REG_PC_CULLED_TRIANGLES_WriteMask                       0xFFFFFFFF
#define MWV207REG_PC_CULLED_TRIANGLES_ResetValue                      0x00000000

#define MWV207REG_PC_CULLED_TRIANGLES_COUNTER                               31:0
#define MWV207REG_PC_CULLED_TRIANGLES_COUNTER_End                             31
#define MWV207REG_PC_CULLED_TRIANGLES_COUNTER_Start                            0
#define MWV207REG_PC_CULLED_TRIANGLES_COUNTER_Type                           U32




#define mwv207regPCCulledLinesRegAddrs                                    0x4C0F
#define MWV207REG_PC_CULLED_LINES_Address                                0x1303C
#define MWV207REG_PC_CULLED_LINES_MSB                                         15
#define MWV207REG_PC_CULLED_LINES_LSB                                          0
#define MWV207REG_PC_CULLED_LINES_BLK                                          0
#define MWV207REG_PC_CULLED_LINES_Count                                        1
#define MWV207REG_PC_CULLED_LINES_FieldMask                           0xFFFFFFFF
#define MWV207REG_PC_CULLED_LINES_ReadMask                            0xFFFFFFFF
#define MWV207REG_PC_CULLED_LINES_WriteMask                           0xFFFFFFFF
#define MWV207REG_PC_CULLED_LINES_ResetValue                          0x00000000

#define MWV207REG_PC_CULLED_LINES_COUNTER                                   31:0
#define MWV207REG_PC_CULLED_LINES_COUNTER_End                                 31
#define MWV207REG_PC_CULLED_LINES_COUNTER_Start                                0
#define MWV207REG_PC_CULLED_LINES_COUNTER_Type                               U32




#define mwv207regPCCulledRectanglesRegAddrs                               0x4C10
#define MWV207REG_PC_CULLED_RECTANGLES_Address                           0x13040
#define MWV207REG_PC_CULLED_RECTANGLES_MSB                                    15
#define MWV207REG_PC_CULLED_RECTANGLES_LSB                                     0
#define MWV207REG_PC_CULLED_RECTANGLES_BLK                                     0
#define MWV207REG_PC_CULLED_RECTANGLES_Count                                   1
#define MWV207REG_PC_CULLED_RECTANGLES_FieldMask                      0xFFFFFFFF
#define MWV207REG_PC_CULLED_RECTANGLES_ReadMask                       0xFFFFFFFF
#define MWV207REG_PC_CULLED_RECTANGLES_WriteMask                      0xFFFFFFFF
#define MWV207REG_PC_CULLED_RECTANGLES_ResetValue                     0x00000000

#define MWV207REG_PC_CULLED_RECTANGLES_COUNTER                              31:0
#define MWV207REG_PC_CULLED_RECTANGLES_COUNTER_End                            31
#define MWV207REG_PC_CULLED_RECTANGLES_COUNTER_Start                           0
#define MWV207REG_PC_CULLED_RECTANGLES_COUNTER_Type                          U32




#define mwv207regPCClippedTrianglesRegAddrs                               0x4C11
#define MWV207REG_PC_CLIPPED_TRIANGLES_Address                           0x13044
#define MWV207REG_PC_CLIPPED_TRIANGLES_MSB                                    15
#define MWV207REG_PC_CLIPPED_TRIANGLES_LSB                                     0
#define MWV207REG_PC_CLIPPED_TRIANGLES_BLK                                     0
#define MWV207REG_PC_CLIPPED_TRIANGLES_Count                                   1
#define MWV207REG_PC_CLIPPED_TRIANGLES_FieldMask                      0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_TRIANGLES_ReadMask                       0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_TRIANGLES_WriteMask                      0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_TRIANGLES_ResetValue                     0x00000000

#define MWV207REG_PC_CLIPPED_TRIANGLES_COUNTER                              31:0
#define MWV207REG_PC_CLIPPED_TRIANGLES_COUNTER_End                            31
#define MWV207REG_PC_CLIPPED_TRIANGLES_COUNTER_Start                           0
#define MWV207REG_PC_CLIPPED_TRIANGLES_COUNTER_Type                          U32




#define mwv207regPCClippedLinesRegAddrs                                   0x4C12
#define MWV207REG_PC_CLIPPED_LINES_Address                               0x13048
#define MWV207REG_PC_CLIPPED_LINES_MSB                                        15
#define MWV207REG_PC_CLIPPED_LINES_LSB                                         0
#define MWV207REG_PC_CLIPPED_LINES_BLK                                         0
#define MWV207REG_PC_CLIPPED_LINES_Count                                       1
#define MWV207REG_PC_CLIPPED_LINES_FieldMask                          0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_LINES_ReadMask                           0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_LINES_WriteMask                          0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_LINES_ResetValue                         0x00000000

#define MWV207REG_PC_CLIPPED_LINES_COUNTER                                  31:0
#define MWV207REG_PC_CLIPPED_LINES_COUNTER_End                                31
#define MWV207REG_PC_CLIPPED_LINES_COUNTER_Start                               0
#define MWV207REG_PC_CLIPPED_LINES_COUNTER_Type                              U32




#define mwv207regPCClippedRectanglesRegAddrs                              0x4C13
#define MWV207REG_PC_CLIPPED_RECTANGLES_Address                          0x1304C
#define MWV207REG_PC_CLIPPED_RECTANGLES_MSB                                   15
#define MWV207REG_PC_CLIPPED_RECTANGLES_LSB                                    0
#define MWV207REG_PC_CLIPPED_RECTANGLES_BLK                                    0
#define MWV207REG_PC_CLIPPED_RECTANGLES_Count                                  1
#define MWV207REG_PC_CLIPPED_RECTANGLES_FieldMask                     0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_RECTANGLES_ReadMask                      0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_RECTANGLES_WriteMask                     0xFFFFFFFF
#define MWV207REG_PC_CLIPPED_RECTANGLES_ResetValue                    0x00000000

#define MWV207REG_PC_CLIPPED_RECTANGLES_COUNTER                             31:0
#define MWV207REG_PC_CLIPPED_RECTANGLES_COUNTER_End                           31
#define MWV207REG_PC_CLIPPED_RECTANGLES_COUNTER_Start                          0
#define MWV207REG_PC_CLIPPED_RECTANGLES_COUNTER_Type                         U32




#define mwv207regPCRasterizedPrimitivesRegAddrs                           0x4C14
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_Address                       0x13050
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_MSB                                15
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_LSB                                 0
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_BLK                                 0
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_Count                               1
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_FieldMask                  0xFFFFFFFF
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_ReadMask                   0xFFFFFFFF
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_WriteMask                  0xFFFFFFFF
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_ResetValue                 0x00000000

#define MWV207REG_PC_RASTERIZED_PRIMITIVES_COUNTER                          31:0
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_COUNTER_End                        31
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_COUNTER_Start                       0
#define MWV207REG_PC_RASTERIZED_PRIMITIVES_COUNTER_Type                      U32




#define mwv207regPCTotalQuadsRegAddrs                                     0x4C15
#define MWV207REG_PC_TOTAL_QUADS_Address                                 0x13054
#define MWV207REG_PC_TOTAL_QUADS_MSB                                          15
#define MWV207REG_PC_TOTAL_QUADS_LSB                                           0
#define MWV207REG_PC_TOTAL_QUADS_BLK                                           0
#define MWV207REG_PC_TOTAL_QUADS_Count                                         1
#define MWV207REG_PC_TOTAL_QUADS_FieldMask                            0xFFFFFFFF
#define MWV207REG_PC_TOTAL_QUADS_ReadMask                             0xFFFFFFFF
#define MWV207REG_PC_TOTAL_QUADS_WriteMask                            0xFFFFFFFF
#define MWV207REG_PC_TOTAL_QUADS_ResetValue                           0x00000000

#define MWV207REG_PC_TOTAL_QUADS_COUNTER                                    31:0
#define MWV207REG_PC_TOTAL_QUADS_COUNTER_End                                  31
#define MWV207REG_PC_TOTAL_QUADS_COUNTER_Start                                 0
#define MWV207REG_PC_TOTAL_QUADS_COUNTER_Type                                U32




#define mwv207regPCCulledHZRegAddrs                                       0x4C16
#define MWV207REG_PC_CULLED_HZ_Address                                   0x13058
#define MWV207REG_PC_CULLED_HZ_MSB                                            15
#define MWV207REG_PC_CULLED_HZ_LSB                                             0
#define MWV207REG_PC_CULLED_HZ_BLK                                             0
#define MWV207REG_PC_CULLED_HZ_Count                                           1
#define MWV207REG_PC_CULLED_HZ_FieldMask                              0xFFFFFFFF
#define MWV207REG_PC_CULLED_HZ_ReadMask                               0xFFFFFFFF
#define MWV207REG_PC_CULLED_HZ_WriteMask                              0xFFFFFFFF
#define MWV207REG_PC_CULLED_HZ_ResetValue                             0x00000000

#define MWV207REG_PC_CULLED_HZ_COUNTER                                      31:0
#define MWV207REG_PC_CULLED_HZ_COUNTER_End                                    31
#define MWV207REG_PC_CULLED_HZ_COUNTER_Start                                   0
#define MWV207REG_PC_CULLED_HZ_COUNTER_Type                                  U32




#define mwv207regPCCulledEEZRegAddrs                                      0x4C17
#define MWV207REG_PC_CULLED_EEZ_Address                                  0x1305C
#define MWV207REG_PC_CULLED_EEZ_MSB                                           15
#define MWV207REG_PC_CULLED_EEZ_LSB                                            0
#define MWV207REG_PC_CULLED_EEZ_BLK                                            0
#define MWV207REG_PC_CULLED_EEZ_Count                                          1
#define MWV207REG_PC_CULLED_EEZ_FieldMask                             0xFFFFFFFF
#define MWV207REG_PC_CULLED_EEZ_ReadMask                              0xFFFFFFFF
#define MWV207REG_PC_CULLED_EEZ_WriteMask                             0xFFFFFFFF
#define MWV207REG_PC_CULLED_EEZ_ResetValue                            0x00000000

#define MWV207REG_PC_CULLED_EEZ_COUNTER                                     31:0
#define MWV207REG_PC_CULLED_EEZ_COUNTER_End                                   31
#define MWV207REG_PC_CULLED_EEZ_COUNTER_Start                                  0
#define MWV207REG_PC_CULLED_EEZ_COUNTER_Type                                 U32




#define mwv207regPCValidQuadsRegAddrs                                     0x4C18
#define MWV207REG_PC_VALID_QUADS_Address                                 0x13060
#define MWV207REG_PC_VALID_QUADS_MSB                                          15
#define MWV207REG_PC_VALID_QUADS_LSB                                           0
#define MWV207REG_PC_VALID_QUADS_BLK                                           0
#define MWV207REG_PC_VALID_QUADS_Count                                         1
#define MWV207REG_PC_VALID_QUADS_FieldMask                            0xFFFFFFFF
#define MWV207REG_PC_VALID_QUADS_ReadMask                             0xFFFFFFFF
#define MWV207REG_PC_VALID_QUADS_WriteMask                            0xFFFFFFFF
#define MWV207REG_PC_VALID_QUADS_ResetValue                           0x00000000

#define MWV207REG_PC_VALID_QUADS_COUNTER                                    31:0
#define MWV207REG_PC_VALID_QUADS_COUNTER_End                                  31
#define MWV207REG_PC_VALID_QUADS_COUNTER_Start                                 0
#define MWV207REG_PC_VALID_QUADS_COUNTER_Type                                U32




#define mwv207regPCValidPixelsRegAddrs                                    0x4C19
#define MWV207REG_PC_VALID_PIXELS_Address                                0x13064
#define MWV207REG_PC_VALID_PIXELS_MSB                                         15
#define MWV207REG_PC_VALID_PIXELS_LSB                                          0
#define MWV207REG_PC_VALID_PIXELS_BLK                                          0
#define MWV207REG_PC_VALID_PIXELS_Count                                        1
#define MWV207REG_PC_VALID_PIXELS_FieldMask                           0xFFFFFFFF
#define MWV207REG_PC_VALID_PIXELS_ReadMask                            0xFFFFFFFF
#define MWV207REG_PC_VALID_PIXELS_WriteMask                           0xFFFFFFFF
#define MWV207REG_PC_VALID_PIXELS_ResetValue                          0x00000000

#define MWV207REG_PC_VALID_PIXELS_COUNTER                                   31:0
#define MWV207REG_PC_VALID_PIXELS_COUNTER_End                                 31
#define MWV207REG_PC_VALID_PIXELS_COUNTER_Start                                0
#define MWV207REG_PC_VALID_PIXELS_COUNTER_Type                               U32




#define mwv207regPCHZCacheRequestsRegAddrs                                0x4C1A
#define MWV207REG_PCHZ_CACHE_REQUESTS_Address                            0x13068
#define MWV207REG_PCHZ_CACHE_REQUESTS_MSB                                     15
#define MWV207REG_PCHZ_CACHE_REQUESTS_LSB                                      0
#define MWV207REG_PCHZ_CACHE_REQUESTS_BLK                                      0
#define MWV207REG_PCHZ_CACHE_REQUESTS_Count                                    1
#define MWV207REG_PCHZ_CACHE_REQUESTS_FieldMask                       0xFFFFFFFF
#define MWV207REG_PCHZ_CACHE_REQUESTS_ReadMask                        0xFFFFFFFF
#define MWV207REG_PCHZ_CACHE_REQUESTS_WriteMask                       0xFFFFFFFF
#define MWV207REG_PCHZ_CACHE_REQUESTS_ResetValue                      0x00000000

#define MWV207REG_PCHZ_CACHE_REQUESTS_COUNTER                               31:0
#define MWV207REG_PCHZ_CACHE_REQUESTS_COUNTER_End                             31
#define MWV207REG_PCHZ_CACHE_REQUESTS_COUNTER_Start                            0
#define MWV207REG_PCHZ_CACHE_REQUESTS_COUNTER_Type                           U32




#define mwv207regPCHZCacheMissesRegAddrs                                  0x4C1B
#define MWV207REG_PCHZ_CACHE_MISSES_Address                              0x1306C
#define MWV207REG_PCHZ_CACHE_MISSES_MSB                                       15
#define MWV207REG_PCHZ_CACHE_MISSES_LSB                                        0
#define MWV207REG_PCHZ_CACHE_MISSES_BLK                                        0
#define MWV207REG_PCHZ_CACHE_MISSES_Count                                      1
#define MWV207REG_PCHZ_CACHE_MISSES_FieldMask                         0xFFFFFFFF
#define MWV207REG_PCHZ_CACHE_MISSES_ReadMask                          0xFFFFFFFF
#define MWV207REG_PCHZ_CACHE_MISSES_WriteMask                         0xFFFFFFFF
#define MWV207REG_PCHZ_CACHE_MISSES_ResetValue                        0x00000000

#define MWV207REG_PCHZ_CACHE_MISSES_COUNTER                                 31:0
#define MWV207REG_PCHZ_CACHE_MISSES_COUNTER_End                               31
#define MWV207REG_PCHZ_CACHE_MISSES_COUNTER_Start                              0
#define MWV207REG_PCHZ_CACHE_MISSES_COUNTER_Type                             U32




#define mwv207regPCHZBytesFetchedRegAddrs                                 0x4C1C
#define MWV207REG_PCHZ_BYTES_FETCHED_Address                             0x13070
#define MWV207REG_PCHZ_BYTES_FETCHED_MSB                                      15
#define MWV207REG_PCHZ_BYTES_FETCHED_LSB                                       0
#define MWV207REG_PCHZ_BYTES_FETCHED_BLK                                       0
#define MWV207REG_PCHZ_BYTES_FETCHED_Count                                     1
#define MWV207REG_PCHZ_BYTES_FETCHED_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCHZ_BYTES_FETCHED_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCHZ_BYTES_FETCHED_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCHZ_BYTES_FETCHED_ResetValue                       0x00000000

#define MWV207REG_PCHZ_BYTES_FETCHED_COUNTER                                31:0
#define MWV207REG_PCHZ_BYTES_FETCHED_COUNTER_End                              31
#define MWV207REG_PCHZ_BYTES_FETCHED_COUNTER_Start                             0
#define MWV207REG_PCHZ_BYTES_FETCHED_COUNTER_Type                            U32




#define mwv207regPCEZCacheRequestsRegAddrs                                0x4C1D
#define MWV207REG_PCEZ_CACHE_REQUESTS_Address                            0x13074
#define MWV207REG_PCEZ_CACHE_REQUESTS_MSB                                     15
#define MWV207REG_PCEZ_CACHE_REQUESTS_LSB                                      0
#define MWV207REG_PCEZ_CACHE_REQUESTS_BLK                                      0
#define MWV207REG_PCEZ_CACHE_REQUESTS_Count                                    1
#define MWV207REG_PCEZ_CACHE_REQUESTS_FieldMask                       0xFFFFFFFF
#define MWV207REG_PCEZ_CACHE_REQUESTS_ReadMask                        0xFFFFFFFF
#define MWV207REG_PCEZ_CACHE_REQUESTS_WriteMask                       0xFFFFFFFF
#define MWV207REG_PCEZ_CACHE_REQUESTS_ResetValue                      0x00000000

#define MWV207REG_PCEZ_CACHE_REQUESTS_COUNTER                               31:0
#define MWV207REG_PCEZ_CACHE_REQUESTS_COUNTER_End                             31
#define MWV207REG_PCEZ_CACHE_REQUESTS_COUNTER_Start                            0
#define MWV207REG_PCEZ_CACHE_REQUESTS_COUNTER_Type                           U32




#define mwv207regPCEZCacheMissesRegAddrs                                  0x4C1E
#define MWV207REG_PCEZ_CACHE_MISSES_Address                              0x13078
#define MWV207REG_PCEZ_CACHE_MISSES_MSB                                       15
#define MWV207REG_PCEZ_CACHE_MISSES_LSB                                        0
#define MWV207REG_PCEZ_CACHE_MISSES_BLK                                        0
#define MWV207REG_PCEZ_CACHE_MISSES_Count                                      1
#define MWV207REG_PCEZ_CACHE_MISSES_FieldMask                         0xFFFFFFFF
#define MWV207REG_PCEZ_CACHE_MISSES_ReadMask                          0xFFFFFFFF
#define MWV207REG_PCEZ_CACHE_MISSES_WriteMask                         0xFFFFFFFF
#define MWV207REG_PCEZ_CACHE_MISSES_ResetValue                        0x00000000

#define MWV207REG_PCEZ_CACHE_MISSES_COUNTER                                 31:0
#define MWV207REG_PCEZ_CACHE_MISSES_COUNTER_End                               31
#define MWV207REG_PCEZ_CACHE_MISSES_COUNTER_Start                              0
#define MWV207REG_PCEZ_CACHE_MISSES_COUNTER_Type                             U32




#define mwv207regPCEZBytesFetchedRegAddrs                                 0x4C1F
#define MWV207REG_PCEZ_BYTES_FETCHED_Address                             0x1307C
#define MWV207REG_PCEZ_BYTES_FETCHED_MSB                                      15
#define MWV207REG_PCEZ_BYTES_FETCHED_LSB                                       0
#define MWV207REG_PCEZ_BYTES_FETCHED_BLK                                       0
#define MWV207REG_PCEZ_BYTES_FETCHED_Count                                     1
#define MWV207REG_PCEZ_BYTES_FETCHED_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCEZ_BYTES_FETCHED_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCEZ_BYTES_FETCHED_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCEZ_BYTES_FETCHED_ResetValue                       0x00000000

#define MWV207REG_PCEZ_BYTES_FETCHED_COUNTER                                31:0
#define MWV207REG_PCEZ_BYTES_FETCHED_COUNTER_End                              31
#define MWV207REG_PCEZ_BYTES_FETCHED_COUNTER_Start                             0
#define MWV207REG_PCEZ_BYTES_FETCHED_COUNTER_Type                            U32




#define mwv207regPCColorKilledPixelsRegAddrs                              0x4C20
#define MWV207REG_PC_COLOR_KILLED_PIXELS_Address                         0x13080
#define MWV207REG_PC_COLOR_KILLED_PIXELS_MSB                                  15
#define MWV207REG_PC_COLOR_KILLED_PIXELS_LSB                                   3
#define MWV207REG_PC_COLOR_KILLED_PIXELS_BLK                                   3
#define MWV207REG_PC_COLOR_KILLED_PIXELS_Count                                 8
#define MWV207REG_PC_COLOR_KILLED_PIXELS_FieldMask                    0xFFFFFFFF
#define MWV207REG_PC_COLOR_KILLED_PIXELS_ReadMask                     0xFFFFFFFF
#define MWV207REG_PC_COLOR_KILLED_PIXELS_WriteMask                    0xFFFFFFFF
#define MWV207REG_PC_COLOR_KILLED_PIXELS_ResetValue                   0x00000000

#define MWV207REG_PC_COLOR_KILLED_PIXELS_COUNTER                            31:0
#define MWV207REG_PC_COLOR_KILLED_PIXELS_COUNTER_End                          31
#define MWV207REG_PC_COLOR_KILLED_PIXELS_COUNTER_Start                         0
#define MWV207REG_PC_COLOR_KILLED_PIXELS_COUNTER_Type                        U32




#define mwv207regPCDepthKilledPixelsRegAddrs                              0x4C28
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_Address                         0x130A0
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_MSB                                  15
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_LSB                                   3
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_BLK                                   3
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_Count                                 8
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_FieldMask                    0xFFFFFFFF
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_ReadMask                     0xFFFFFFFF
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_WriteMask                    0xFFFFFFFF
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_ResetValue                   0x00000000

#define MWV207REG_PC_DEPTH_KILLED_PIXELS_COUNTER                            31:0
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_COUNTER_End                          31
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_COUNTER_Start                         0
#define MWV207REG_PC_DEPTH_KILLED_PIXELS_COUNTER_Type                        U32




#define mwv207regPCStencilKilledPixelsRegAddrs                            0x4C30
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_Address                       0x130C0
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_MSB                                15
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_LSB                                 3
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_BLK                                 3
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_Count                               8
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_FieldMask                  0xFFFFFFFF
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_ReadMask                   0xFFFFFFFF
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_WriteMask                  0xFFFFFFFF
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_ResetValue                 0x00000000

#define MWV207REG_PC_STENCIL_KILLED_PIXELS_COUNTER                          31:0
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_COUNTER_End                        31
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_COUNTER_Start                       0
#define MWV207REG_PC_STENCIL_KILLED_PIXELS_COUNTER_Type                      U32




#define mwv207regPCColorRenderedPixelsRegAddrs                            0x4C38
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_Address                       0x130E0
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_MSB                                15
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_LSB                                 3
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_BLK                                 3
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_Count                               8
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_FieldMask                  0xFFFFFFFF
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_ReadMask                   0xFFFFFFFF
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_WriteMask                  0xFFFFFFFF
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_ResetValue                 0x00000000

#define MWV207REG_PC_COLOR_RENDERED_PIXELS_COUNTER                          31:0
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_COUNTER_End                        31
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_COUNTER_Start                       0
#define MWV207REG_PC_COLOR_RENDERED_PIXELS_COUNTER_Type                      U32




#define mwv207regPCDepthRenderedPixelsRegAddrs                            0x4C40
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_Address                       0x13100
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_MSB                                15
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_LSB                                 3
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_BLK                                 3
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_Count                               8
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_FieldMask                  0xFFFFFFFF
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_ReadMask                   0xFFFFFFFF
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_WriteMask                  0xFFFFFFFF
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_ResetValue                 0x00000000

#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_COUNTER                          31:0
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_COUNTER_End                        31
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_COUNTER_Start                       0
#define MWV207REG_PC_DEPTH_RENDERED_PIXELS_COUNTER_Type                      U32




#define mwv207regPCCCacheRequestsRegAddrs                                 0x4C48
#define MWV207REG_PCC_CACHE_REQUESTS_Address                             0x13120
#define MWV207REG_PCC_CACHE_REQUESTS_MSB                                      15
#define MWV207REG_PCC_CACHE_REQUESTS_LSB                                       3
#define MWV207REG_PCC_CACHE_REQUESTS_BLK                                       3
#define MWV207REG_PCC_CACHE_REQUESTS_Count                                     8
#define MWV207REG_PCC_CACHE_REQUESTS_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCC_CACHE_REQUESTS_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCC_CACHE_REQUESTS_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCC_CACHE_REQUESTS_ResetValue                       0x00000000

#define MWV207REG_PCC_CACHE_REQUESTS_COUNTER                                31:0
#define MWV207REG_PCC_CACHE_REQUESTS_COUNTER_End                              31
#define MWV207REG_PCC_CACHE_REQUESTS_COUNTER_Start                             0
#define MWV207REG_PCC_CACHE_REQUESTS_COUNTER_Type                            U32




#define mwv207regPCCCacheMissesRegAddrs                                   0x4C50
#define MWV207REG_PCC_CACHE_MISSES_Address                               0x13140
#define MWV207REG_PCC_CACHE_MISSES_MSB                                        15
#define MWV207REG_PCC_CACHE_MISSES_LSB                                         3
#define MWV207REG_PCC_CACHE_MISSES_BLK                                         3
#define MWV207REG_PCC_CACHE_MISSES_Count                                       8
#define MWV207REG_PCC_CACHE_MISSES_FieldMask                          0xFFFFFFFF
#define MWV207REG_PCC_CACHE_MISSES_ReadMask                           0xFFFFFFFF
#define MWV207REG_PCC_CACHE_MISSES_WriteMask                          0xFFFFFFFF
#define MWV207REG_PCC_CACHE_MISSES_ResetValue                         0x00000000

#define MWV207REG_PCC_CACHE_MISSES_COUNTER                                  31:0
#define MWV207REG_PCC_CACHE_MISSES_COUNTER_End                                31
#define MWV207REG_PCC_CACHE_MISSES_COUNTER_Start                               0
#define MWV207REG_PCC_CACHE_MISSES_COUNTER_Type                              U32




#define mwv207regPCCCacheBytesFetchedRegAddrs                             0x4C58
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_Address                        0x13160
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_MSB                                 15
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_LSB                                  3
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_BLK                                  3
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_Count                                8
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_FieldMask                   0xFFFFFFFF
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_ReadMask                    0xFFFFFFFF
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_WriteMask                   0xFFFFFFFF
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_ResetValue                  0x00000000

#define MWV207REG_PCC_CACHE_BYTES_FETCHED_COUNTER                           31:0
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_COUNTER_End                         31
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_COUNTER_Start                        0
#define MWV207REG_PCC_CACHE_BYTES_FETCHED_COUNTER_Type                       U32




#define mwv207regPCCCacheBytesWrittenRegAddrs                             0x4C60
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_Address                        0x13180
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_MSB                                 15
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_LSB                                  3
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_BLK                                  3
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_Count                                8
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_FieldMask                   0xFFFFFFFF
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_ReadMask                    0xFFFFFFFF
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_WriteMask                   0xFFFFFFFF
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_ResetValue                  0x00000000

#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_COUNTER                           31:0
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_COUNTER_End                         31
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_COUNTER_Start                        0
#define MWV207REG_PCC_CACHE_BYTES_WRITTEN_COUNTER_Type                       U32




#define mwv207regPCZCacheRequestsRegAddrs                                 0x4C68
#define MWV207REG_PCZ_CACHE_REQUESTS_Address                             0x131A0
#define MWV207REG_PCZ_CACHE_REQUESTS_MSB                                      15
#define MWV207REG_PCZ_CACHE_REQUESTS_LSB                                       3
#define MWV207REG_PCZ_CACHE_REQUESTS_BLK                                       3
#define MWV207REG_PCZ_CACHE_REQUESTS_Count                                     8
#define MWV207REG_PCZ_CACHE_REQUESTS_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_REQUESTS_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_REQUESTS_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_REQUESTS_ResetValue                       0x00000000

#define MWV207REG_PCZ_CACHE_REQUESTS_COUNTER                                31:0
#define MWV207REG_PCZ_CACHE_REQUESTS_COUNTER_End                              31
#define MWV207REG_PCZ_CACHE_REQUESTS_COUNTER_Start                             0
#define MWV207REG_PCZ_CACHE_REQUESTS_COUNTER_Type                            U32




#define mwv207regPCZCacheMissesRegAddrs                                   0x4C70
#define MWV207REG_PCZ_CACHE_MISSES_Address                               0x131C0
#define MWV207REG_PCZ_CACHE_MISSES_MSB                                        15
#define MWV207REG_PCZ_CACHE_MISSES_LSB                                         3
#define MWV207REG_PCZ_CACHE_MISSES_BLK                                         3
#define MWV207REG_PCZ_CACHE_MISSES_Count                                       8
#define MWV207REG_PCZ_CACHE_MISSES_FieldMask                          0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_MISSES_ReadMask                           0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_MISSES_WriteMask                          0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_MISSES_ResetValue                         0x00000000

#define MWV207REG_PCZ_CACHE_MISSES_COUNTER                                  31:0
#define MWV207REG_PCZ_CACHE_MISSES_COUNTER_End                                31
#define MWV207REG_PCZ_CACHE_MISSES_COUNTER_Start                               0
#define MWV207REG_PCZ_CACHE_MISSES_COUNTER_Type                              U32




#define mwv207regPCZCacheBytesFetchedRegAddrs                             0x4C78
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_Address                        0x131E0
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_MSB                                 15
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_LSB                                  3
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_BLK                                  3
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_Count                                8
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_FieldMask                   0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_ReadMask                    0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_WriteMask                   0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_ResetValue                  0x00000000

#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_COUNTER                           31:0
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_COUNTER_End                         31
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_COUNTER_Start                        0
#define MWV207REG_PCZ_CACHE_BYTES_FETCHED_COUNTER_Type                       U32




#define mwv207regPCZCacheBytesWrittenRegAddrs                             0x4C80
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_Address                        0x13200
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_MSB                                 15
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_LSB                                  3
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_BLK                                  3
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_Count                                8
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_FieldMask                   0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_ReadMask                    0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_WriteMask                   0xFFFFFFFF
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_ResetValue                  0x00000000

#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_COUNTER                           31:0
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_COUNTER_End                         31
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_COUNTER_Start                        0
#define MWV207REG_PCZ_CACHE_BYTES_WRITTEN_COUNTER_Type                       U32




#define mwv207regPCHZBytesWrittenRegAddrs                                 0x4C88
#define MWV207REG_PCHZ_BYTES_WRITTEN_Address                             0x13220
#define MWV207REG_PCHZ_BYTES_WRITTEN_MSB                                      15
#define MWV207REG_PCHZ_BYTES_WRITTEN_LSB                                       3
#define MWV207REG_PCHZ_BYTES_WRITTEN_BLK                                       3
#define MWV207REG_PCHZ_BYTES_WRITTEN_Count                                     8
#define MWV207REG_PCHZ_BYTES_WRITTEN_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCHZ_BYTES_WRITTEN_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCHZ_BYTES_WRITTEN_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCHZ_BYTES_WRITTEN_ResetValue                       0x00000000

#define MWV207REG_PCHZ_BYTES_WRITTEN_COUNTER                                31:0
#define MWV207REG_PCHZ_BYTES_WRITTEN_COUNTER_End                              31
#define MWV207REG_PCHZ_BYTES_WRITTEN_COUNTER_Start                             0
#define MWV207REG_PCHZ_BYTES_WRITTEN_COUNTER_Type                            U32




#define mwv207regPCTexelRequestsRegAddrs                                  0x4C90
#define MWV207REG_PC_TEXEL_REQUESTS_Address                              0x13240
#define MWV207REG_PC_TEXEL_REQUESTS_MSB                                       15
#define MWV207REG_PC_TEXEL_REQUESTS_LSB                                        0
#define MWV207REG_PC_TEXEL_REQUESTS_BLK                                        0
#define MWV207REG_PC_TEXEL_REQUESTS_Count                                      1
#define MWV207REG_PC_TEXEL_REQUESTS_FieldMask                         0xFFFFFFFF
#define MWV207REG_PC_TEXEL_REQUESTS_ReadMask                          0xFFFFFFFF
#define MWV207REG_PC_TEXEL_REQUESTS_WriteMask                         0xFFFFFFFF
#define MWV207REG_PC_TEXEL_REQUESTS_ResetValue                        0x00000000

#define MWV207REG_PC_TEXEL_REQUESTS_COUNTER                                 31:0
#define MWV207REG_PC_TEXEL_REQUESTS_COUNTER_End                               31
#define MWV207REG_PC_TEXEL_REQUESTS_COUNTER_Start                              0
#define MWV207REG_PC_TEXEL_REQUESTS_COUNTER_Type                             U32




#define mwv207regPCBilinearRequestsRegAddrs                               0x4C91
#define MWV207REG_PC_BILINEAR_REQUESTS_Address                           0x13244
#define MWV207REG_PC_BILINEAR_REQUESTS_MSB                                    15
#define MWV207REG_PC_BILINEAR_REQUESTS_LSB                                     0
#define MWV207REG_PC_BILINEAR_REQUESTS_BLK                                     0
#define MWV207REG_PC_BILINEAR_REQUESTS_Count                                   1
#define MWV207REG_PC_BILINEAR_REQUESTS_FieldMask                      0xFFFFFFFF
#define MWV207REG_PC_BILINEAR_REQUESTS_ReadMask                       0xFFFFFFFF
#define MWV207REG_PC_BILINEAR_REQUESTS_WriteMask                      0xFFFFFFFF
#define MWV207REG_PC_BILINEAR_REQUESTS_ResetValue                     0x00000000

#define MWV207REG_PC_BILINEAR_REQUESTS_COUNTER                              31:0
#define MWV207REG_PC_BILINEAR_REQUESTS_COUNTER_End                            31
#define MWV207REG_PC_BILINEAR_REQUESTS_COUNTER_Start                           0
#define MWV207REG_PC_BILINEAR_REQUESTS_COUNTER_Type                          U32




#define mwv207regPCTrilinearRequestsRegAddrs                              0x4C92
#define MWV207REG_PC_TRILINEAR_REQUESTS_Address                          0x13248
#define MWV207REG_PC_TRILINEAR_REQUESTS_MSB                                   15
#define MWV207REG_PC_TRILINEAR_REQUESTS_LSB                                    0
#define MWV207REG_PC_TRILINEAR_REQUESTS_BLK                                    0
#define MWV207REG_PC_TRILINEAR_REQUESTS_Count                                  1
#define MWV207REG_PC_TRILINEAR_REQUESTS_FieldMask                     0xFFFFFFFF
#define MWV207REG_PC_TRILINEAR_REQUESTS_ReadMask                      0xFFFFFFFF
#define MWV207REG_PC_TRILINEAR_REQUESTS_WriteMask                     0xFFFFFFFF
#define MWV207REG_PC_TRILINEAR_REQUESTS_ResetValue                    0x00000000

#define MWV207REG_PC_TRILINEAR_REQUESTS_COUNTER                             31:0
#define MWV207REG_PC_TRILINEAR_REQUESTS_COUNTER_End                           31
#define MWV207REG_PC_TRILINEAR_REQUESTS_COUNTER_Start                          0
#define MWV207REG_PC_TRILINEAR_REQUESTS_COUNTER_Type                         U32




#define mwv207regPCDiscardedRequestsRegAddrs                              0x4C93
#define MWV207REG_PC_DISCARDED_REQUESTS_Address                          0x1324C
#define MWV207REG_PC_DISCARDED_REQUESTS_MSB                                   15
#define MWV207REG_PC_DISCARDED_REQUESTS_LSB                                    0
#define MWV207REG_PC_DISCARDED_REQUESTS_BLK                                    0
#define MWV207REG_PC_DISCARDED_REQUESTS_Count                                  1
#define MWV207REG_PC_DISCARDED_REQUESTS_FieldMask                     0xFFFFFFFF
#define MWV207REG_PC_DISCARDED_REQUESTS_ReadMask                      0xFFFFFFFF
#define MWV207REG_PC_DISCARDED_REQUESTS_WriteMask                     0xFFFFFFFF
#define MWV207REG_PC_DISCARDED_REQUESTS_ResetValue                    0x00000000

#define MWV207REG_PC_DISCARDED_REQUESTS_COUNTER                             31:0
#define MWV207REG_PC_DISCARDED_REQUESTS_COUNTER_End                           31
#define MWV207REG_PC_DISCARDED_REQUESTS_COUNTER_Start                          0
#define MWV207REG_PC_DISCARDED_REQUESTS_COUNTER_Type                         U32




#define mwv207regPCTXCacheRequestsRegAddrs                                0x4C98
#define MWV207REG_PCTX_CACHE_REQUESTS_Address                            0x13260
#define MWV207REG_PCTX_CACHE_REQUESTS_MSB                                     15
#define MWV207REG_PCTX_CACHE_REQUESTS_LSB                                      3
#define MWV207REG_PCTX_CACHE_REQUESTS_BLK                                      3
#define MWV207REG_PCTX_CACHE_REQUESTS_Count                                    8
#define MWV207REG_PCTX_CACHE_REQUESTS_FieldMask                       0xFFFFFFFF
#define MWV207REG_PCTX_CACHE_REQUESTS_ReadMask                        0xFFFFFFFF
#define MWV207REG_PCTX_CACHE_REQUESTS_WriteMask                       0xFFFFFFFF
#define MWV207REG_PCTX_CACHE_REQUESTS_ResetValue                      0x00000000

#define MWV207REG_PCTX_CACHE_REQUESTS_COUNTER                               31:0
#define MWV207REG_PCTX_CACHE_REQUESTS_COUNTER_End                             31
#define MWV207REG_PCTX_CACHE_REQUESTS_COUNTER_Start                            0
#define MWV207REG_PCTX_CACHE_REQUESTS_COUNTER_Type                           U32




#define mwv207regPCTXCacheMissesRegAddrs                                  0x4CA0
#define MWV207REG_PCTX_CACHE_MISSES_Address                              0x13280
#define MWV207REG_PCTX_CACHE_MISSES_MSB                                       15
#define MWV207REG_PCTX_CACHE_MISSES_LSB                                        3
#define MWV207REG_PCTX_CACHE_MISSES_BLK                                        3
#define MWV207REG_PCTX_CACHE_MISSES_Count                                      8
#define MWV207REG_PCTX_CACHE_MISSES_FieldMask                         0xFFFFFFFF
#define MWV207REG_PCTX_CACHE_MISSES_ReadMask                          0xFFFFFFFF
#define MWV207REG_PCTX_CACHE_MISSES_WriteMask                         0xFFFFFFFF
#define MWV207REG_PCTX_CACHE_MISSES_ResetValue                        0x00000000

#define MWV207REG_PCTX_CACHE_MISSES_COUNTER                                 31:0
#define MWV207REG_PCTX_CACHE_MISSES_COUNTER_End                               31
#define MWV207REG_PCTX_CACHE_MISSES_COUNTER_Start                              0
#define MWV207REG_PCTX_CACHE_MISSES_COUNTER_Type                             U32




#define mwv207regPCTXBytesFetchedRegAddrs                                 0x4CA8
#define MWV207REG_PCTX_BYTES_FETCHED_Address                             0x132A0
#define MWV207REG_PCTX_BYTES_FETCHED_MSB                                      15
#define MWV207REG_PCTX_BYTES_FETCHED_LSB                                       3
#define MWV207REG_PCTX_BYTES_FETCHED_BLK                                       3
#define MWV207REG_PCTX_BYTES_FETCHED_Count                                     8
#define MWV207REG_PCTX_BYTES_FETCHED_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCTX_BYTES_FETCHED_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCTX_BYTES_FETCHED_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCTX_BYTES_FETCHED_ResetValue                       0x00000000

#define MWV207REG_PCTX_BYTES_FETCHED_COUNTER                                31:0
#define MWV207REG_PCTX_BYTES_FETCHED_COUNTER_End                              31
#define MWV207REG_PCTX_BYTES_FETCHED_COUNTER_Start                             0
#define MWV207REG_PCTX_BYTES_FETCHED_COUNTER_Type                            U32




#define mwv207regPCVertexInstructionsRegAddrs                             0x4C94
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_Address                         0x13250
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_MSB                                  15
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_LSB                                   0
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_BLK                                   0
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_Count                                 1
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_FieldMask                    0xFFFFFFFF
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_ReadMask                     0xFFFFFFFF
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_WriteMask                    0xFFFFFFFF
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_ResetValue                   0x00000000

#define MWV207REG_PC_VERTEX_INSTRUCTIONS_COUNTER                            31:0
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_COUNTER_End                          31
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_COUNTER_Start                         0
#define MWV207REG_PC_VERTEX_INSTRUCTIONS_COUNTER_Type                        U32




#define mwv207regPCVertexBranchesRegAddrs                                 0x4C95
#define MWV207REG_PC_VERTEX_BRANCHES_Address                             0x13254
#define MWV207REG_PC_VERTEX_BRANCHES_MSB                                      15
#define MWV207REG_PC_VERTEX_BRANCHES_LSB                                       0
#define MWV207REG_PC_VERTEX_BRANCHES_BLK                                       0
#define MWV207REG_PC_VERTEX_BRANCHES_Count                                     1
#define MWV207REG_PC_VERTEX_BRANCHES_FieldMask                        0xFFFFFFFF
#define MWV207REG_PC_VERTEX_BRANCHES_ReadMask                         0xFFFFFFFF
#define MWV207REG_PC_VERTEX_BRANCHES_WriteMask                        0xFFFFFFFF
#define MWV207REG_PC_VERTEX_BRANCHES_ResetValue                       0x00000000

#define MWV207REG_PC_VERTEX_BRANCHES_COUNTER                                31:0
#define MWV207REG_PC_VERTEX_BRANCHES_COUNTER_End                              31
#define MWV207REG_PC_VERTEX_BRANCHES_COUNTER_Start                             0
#define MWV207REG_PC_VERTEX_BRANCHES_COUNTER_Type                            U32




#define mwv207regPCVertexTexturesRegAddrs                                 0x4C96
#define MWV207REG_PC_VERTEX_TEXTURES_Address                             0x13258
#define MWV207REG_PC_VERTEX_TEXTURES_MSB                                      15
#define MWV207REG_PC_VERTEX_TEXTURES_LSB                                       0
#define MWV207REG_PC_VERTEX_TEXTURES_BLK                                       0
#define MWV207REG_PC_VERTEX_TEXTURES_Count                                     1
#define MWV207REG_PC_VERTEX_TEXTURES_FieldMask                        0xFFFFFFFF
#define MWV207REG_PC_VERTEX_TEXTURES_ReadMask                         0xFFFFFFFF
#define MWV207REG_PC_VERTEX_TEXTURES_WriteMask                        0xFFFFFFFF
#define MWV207REG_PC_VERTEX_TEXTURES_ResetValue                       0x00000000

#define MWV207REG_PC_VERTEX_TEXTURES_COUNTER                                31:0
#define MWV207REG_PC_VERTEX_TEXTURES_COUNTER_End                              31
#define MWV207REG_PC_VERTEX_TEXTURES_COUNTER_Start                             0
#define MWV207REG_PC_VERTEX_TEXTURES_COUNTER_Type                            U32




#define mwv207regPCVerticesRenderedRegAddrs                               0x4C97
#define MWV207REG_PC_VERTICES_RENDERED_Address                           0x1325C
#define MWV207REG_PC_VERTICES_RENDERED_MSB                                    15
#define MWV207REG_PC_VERTICES_RENDERED_LSB                                     0
#define MWV207REG_PC_VERTICES_RENDERED_BLK                                     0
#define MWV207REG_PC_VERTICES_RENDERED_Count                                   1
#define MWV207REG_PC_VERTICES_RENDERED_FieldMask                      0xFFFFFFFF
#define MWV207REG_PC_VERTICES_RENDERED_ReadMask                       0xFFFFFFFF
#define MWV207REG_PC_VERTICES_RENDERED_WriteMask                      0xFFFFFFFF
#define MWV207REG_PC_VERTICES_RENDERED_ResetValue                     0x00000000

#define MWV207REG_PC_VERTICES_RENDERED_COUNTER                              31:0
#define MWV207REG_PC_VERTICES_RENDERED_COUNTER_End                            31
#define MWV207REG_PC_VERTICES_RENDERED_COUNTER_Start                           0
#define MWV207REG_PC_VERTICES_RENDERED_COUNTER_Type                          U32




#define mwv207regPCPixelInstructionsRegAddrs                              0x4CB0
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_Address                          0x132C0
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_MSB                                   15
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_LSB                                    0
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_BLK                                    0
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_Count                                  1
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_FieldMask                     0xFFFFFFFF
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_ReadMask                      0xFFFFFFFF
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_WriteMask                     0xFFFFFFFF
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_ResetValue                    0x00000000

#define MWV207REG_PC_PIXEL_INSTRUCTIONS_COUNTER                             31:0
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_COUNTER_End                           31
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_COUNTER_Start                          0
#define MWV207REG_PC_PIXEL_INSTRUCTIONS_COUNTER_Type                         U32




#define mwv207regPCPixelBranchesRegAddrs                                  0x4CB1
#define MWV207REG_PC_PIXEL_BRANCHES_Address                              0x132C4
#define MWV207REG_PC_PIXEL_BRANCHES_MSB                                       15
#define MWV207REG_PC_PIXEL_BRANCHES_LSB                                        0
#define MWV207REG_PC_PIXEL_BRANCHES_BLK                                        0
#define MWV207REG_PC_PIXEL_BRANCHES_Count                                      1
#define MWV207REG_PC_PIXEL_BRANCHES_FieldMask                         0xFFFFFFFF
#define MWV207REG_PC_PIXEL_BRANCHES_ReadMask                          0xFFFFFFFF
#define MWV207REG_PC_PIXEL_BRANCHES_WriteMask                         0xFFFFFFFF
#define MWV207REG_PC_PIXEL_BRANCHES_ResetValue                        0x00000000

#define MWV207REG_PC_PIXEL_BRANCHES_COUNTER                                 31:0
#define MWV207REG_PC_PIXEL_BRANCHES_COUNTER_End                               31
#define MWV207REG_PC_PIXEL_BRANCHES_COUNTER_Start                              0
#define MWV207REG_PC_PIXEL_BRANCHES_COUNTER_Type                             U32




#define mwv207regPCPixelTexturesRegAddrs                                  0x4CB2
#define MWV207REG_PC_PIXEL_TEXTURES_Address                              0x132C8
#define MWV207REG_PC_PIXEL_TEXTURES_MSB                                       15
#define MWV207REG_PC_PIXEL_TEXTURES_LSB                                        0
#define MWV207REG_PC_PIXEL_TEXTURES_BLK                                        0
#define MWV207REG_PC_PIXEL_TEXTURES_Count                                      1
#define MWV207REG_PC_PIXEL_TEXTURES_FieldMask                         0xFFFFFFFF
#define MWV207REG_PC_PIXEL_TEXTURES_ReadMask                          0xFFFFFFFF
#define MWV207REG_PC_PIXEL_TEXTURES_WriteMask                         0xFFFFFFFF
#define MWV207REG_PC_PIXEL_TEXTURES_ResetValue                        0x00000000

#define MWV207REG_PC_PIXEL_TEXTURES_COUNTER                                 31:0
#define MWV207REG_PC_PIXEL_TEXTURES_COUNTER_End                               31
#define MWV207REG_PC_PIXEL_TEXTURES_COUNTER_Start                              0
#define MWV207REG_PC_PIXEL_TEXTURES_COUNTER_Type                             U32




#define mwv207regPCPixelsRenderedRegAddrs                                 0x4CB3
#define MWV207REG_PC_PIXELS_RENDERED_Address                             0x132CC
#define MWV207REG_PC_PIXELS_RENDERED_MSB                                      15
#define MWV207REG_PC_PIXELS_RENDERED_LSB                                       0
#define MWV207REG_PC_PIXELS_RENDERED_BLK                                       0
#define MWV207REG_PC_PIXELS_RENDERED_Count                                     1
#define MWV207REG_PC_PIXELS_RENDERED_FieldMask                        0xFFFFFFFF
#define MWV207REG_PC_PIXELS_RENDERED_ReadMask                         0xFFFFFFFF
#define MWV207REG_PC_PIXELS_RENDERED_WriteMask                        0xFFFFFFFF
#define MWV207REG_PC_PIXELS_RENDERED_ResetValue                       0x00000000

#define MWV207REG_PC_PIXELS_RENDERED_COUNTER                                31:0
#define MWV207REG_PC_PIXELS_RENDERED_COUNTER_End                              31
#define MWV207REG_PC_PIXELS_RENDERED_COUNTER_Start                             0
#define MWV207REG_PC_PIXELS_RENDERED_COUNTER_Type                            U32




#define mwv207regPCLoadInstructionsRegAddrs                               0x4CB4
#define MWV207REG_PC_LOAD_INSTRUCTIONS_Address                           0x132D0
#define MWV207REG_PC_LOAD_INSTRUCTIONS_MSB                                    15
#define MWV207REG_PC_LOAD_INSTRUCTIONS_LSB                                     0
#define MWV207REG_PC_LOAD_INSTRUCTIONS_BLK                                     0
#define MWV207REG_PC_LOAD_INSTRUCTIONS_Count                                   1
#define MWV207REG_PC_LOAD_INSTRUCTIONS_FieldMask                      0xFFFFFFFF
#define MWV207REG_PC_LOAD_INSTRUCTIONS_ReadMask                       0xFFFFFFFF
#define MWV207REG_PC_LOAD_INSTRUCTIONS_WriteMask                      0xFFFFFFFF
#define MWV207REG_PC_LOAD_INSTRUCTIONS_ResetValue                     0x00000000

#define MWV207REG_PC_LOAD_INSTRUCTIONS_COUNTER                              31:0
#define MWV207REG_PC_LOAD_INSTRUCTIONS_COUNTER_End                            31
#define MWV207REG_PC_LOAD_INSTRUCTIONS_COUNTER_Start                           0
#define MWV207REG_PC_LOAD_INSTRUCTIONS_COUNTER_Type                          U32




#define mwv207regPCStoreInstructionsRegAddrs                              0x4CB5
#define MWV207REG_PC_STORE_INSTRUCTIONS_Address                          0x132D4
#define MWV207REG_PC_STORE_INSTRUCTIONS_MSB                                   15
#define MWV207REG_PC_STORE_INSTRUCTIONS_LSB                                    0
#define MWV207REG_PC_STORE_INSTRUCTIONS_BLK                                    0
#define MWV207REG_PC_STORE_INSTRUCTIONS_Count                                  1
#define MWV207REG_PC_STORE_INSTRUCTIONS_FieldMask                     0xFFFFFFFF
#define MWV207REG_PC_STORE_INSTRUCTIONS_ReadMask                      0xFFFFFFFF
#define MWV207REG_PC_STORE_INSTRUCTIONS_WriteMask                     0xFFFFFFFF
#define MWV207REG_PC_STORE_INSTRUCTIONS_ResetValue                    0x00000000

#define MWV207REG_PC_STORE_INSTRUCTIONS_COUNTER                             31:0
#define MWV207REG_PC_STORE_INSTRUCTIONS_COUNTER_End                           31
#define MWV207REG_PC_STORE_INSTRUCTIONS_COUNTER_Start                          0
#define MWV207REG_PC_STORE_INSTRUCTIONS_COUNTER_Type                         U32




#define mwv207regPCL1LoadRequestsRegAddrs                                 0x4CB6
#define MWV207REG_PCL1_LOAD_REQUESTS_Address                             0x132D8
#define MWV207REG_PCL1_LOAD_REQUESTS_MSB                                      15
#define MWV207REG_PCL1_LOAD_REQUESTS_LSB                                       0
#define MWV207REG_PCL1_LOAD_REQUESTS_BLK                                       0
#define MWV207REG_PCL1_LOAD_REQUESTS_Count                                     1
#define MWV207REG_PCL1_LOAD_REQUESTS_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCL1_LOAD_REQUESTS_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCL1_LOAD_REQUESTS_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCL1_LOAD_REQUESTS_ResetValue                       0x00000000

#define MWV207REG_PCL1_LOAD_REQUESTS_COUNTER                                31:0
#define MWV207REG_PCL1_LOAD_REQUESTS_COUNTER_End                              31
#define MWV207REG_PCL1_LOAD_REQUESTS_COUNTER_Start                             0
#define MWV207REG_PCL1_LOAD_REQUESTS_COUNTER_Type                            U32




#define mwv207regPCL1StoreRequestsRegAddrs                                0x4CB7
#define MWV207REG_PCL1_STORE_REQUESTS_Address                            0x132DC
#define MWV207REG_PCL1_STORE_REQUESTS_MSB                                     15
#define MWV207REG_PCL1_STORE_REQUESTS_LSB                                      0
#define MWV207REG_PCL1_STORE_REQUESTS_BLK                                      0
#define MWV207REG_PCL1_STORE_REQUESTS_Count                                    1
#define MWV207REG_PCL1_STORE_REQUESTS_FieldMask                       0xFFFFFFFF
#define MWV207REG_PCL1_STORE_REQUESTS_ReadMask                        0xFFFFFFFF
#define MWV207REG_PCL1_STORE_REQUESTS_WriteMask                       0xFFFFFFFF
#define MWV207REG_PCL1_STORE_REQUESTS_ResetValue                      0x00000000

#define MWV207REG_PCL1_STORE_REQUESTS_COUNTER                               31:0
#define MWV207REG_PCL1_STORE_REQUESTS_COUNTER_End                             31
#define MWV207REG_PCL1_STORE_REQUESTS_COUNTER_Start                            0
#define MWV207REG_PCL1_STORE_REQUESTS_COUNTER_Type                           U32




#define mwv207regPCL1MissesRegAddrs                                       0x4CB8
#define MWV207REG_PCL1_MISSES_Address                                    0x132E0
#define MWV207REG_PCL1_MISSES_MSB                                             15
#define MWV207REG_PCL1_MISSES_LSB                                              0
#define MWV207REG_PCL1_MISSES_BLK                                              0
#define MWV207REG_PCL1_MISSES_Count                                            1
#define MWV207REG_PCL1_MISSES_FieldMask                               0xFFFFFFFF
#define MWV207REG_PCL1_MISSES_ReadMask                                0xFFFFFFFF
#define MWV207REG_PCL1_MISSES_WriteMask                               0xFFFFFFFF
#define MWV207REG_PCL1_MISSES_ResetValue                              0x00000000

#define MWV207REG_PCL1_MISSES_COUNTER                                       31:0
#define MWV207REG_PCL1_MISSES_COUNTER_End                                     31
#define MWV207REG_PCL1_MISSES_COUNTER_Start                                    0
#define MWV207REG_PCL1_MISSES_COUNTER_Type                                   U32




#define mwv207regPCL1BytesFetchedRegAddrs                                 0x4CB9
#define MWV207REG_PCL1_BYTES_FETCHED_Address                             0x132E4
#define MWV207REG_PCL1_BYTES_FETCHED_MSB                                      15
#define MWV207REG_PCL1_BYTES_FETCHED_LSB                                       0
#define MWV207REG_PCL1_BYTES_FETCHED_BLK                                       0
#define MWV207REG_PCL1_BYTES_FETCHED_Count                                     1
#define MWV207REG_PCL1_BYTES_FETCHED_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCL1_BYTES_FETCHED_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCL1_BYTES_FETCHED_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCL1_BYTES_FETCHED_ResetValue                       0x00000000

#define MWV207REG_PCL1_BYTES_FETCHED_COUNTER                                31:0
#define MWV207REG_PCL1_BYTES_FETCHED_COUNTER_End                              31
#define MWV207REG_PCL1_BYTES_FETCHED_COUNTER_Start                             0
#define MWV207REG_PCL1_BYTES_FETCHED_COUNTER_Type                            U32




#define mwv207regPCL1BytesWrittenRegAddrs                                 0x4CBA
#define MWV207REG_PCL1_BYTES_WRITTEN_Address                             0x132E8
#define MWV207REG_PCL1_BYTES_WRITTEN_MSB                                      15
#define MWV207REG_PCL1_BYTES_WRITTEN_LSB                                       0
#define MWV207REG_PCL1_BYTES_WRITTEN_BLK                                       0
#define MWV207REG_PCL1_BYTES_WRITTEN_Count                                     1
#define MWV207REG_PCL1_BYTES_WRITTEN_FieldMask                        0xFFFFFFFF
#define MWV207REG_PCL1_BYTES_WRITTEN_ReadMask                         0xFFFFFFFF
#define MWV207REG_PCL1_BYTES_WRITTEN_WriteMask                        0xFFFFFFFF
#define MWV207REG_PCL1_BYTES_WRITTEN_ResetValue                       0x00000000

#define MWV207REG_PCL1_BYTES_WRITTEN_COUNTER                                31:0
#define MWV207REG_PCL1_BYTES_WRITTEN_COUNTER_End                              31
#define MWV207REG_PCL1_BYTES_WRITTEN_COUNTER_Start                             0
#define MWV207REG_PCL1_BYTES_WRITTEN_COUNTER_Type                            U32


#endif


