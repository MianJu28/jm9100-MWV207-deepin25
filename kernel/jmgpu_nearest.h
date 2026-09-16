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




#ifndef __AQPrimitiveAssembly_h__
#define __AQPrimitiveAssembly_h__


#define AQViewportXScaleRegAddrs                                          0x0280
#define AQ_VIEWPORT_XSCALE_Address                                       0x00A00
#define AQ_VIEWPORT_XSCALE_MSB                                                15
#define AQ_VIEWPORT_XSCALE_LSB                                                 0
#define AQ_VIEWPORT_XSCALE_BLK                                                 0
#define AQ_VIEWPORT_XSCALE_Count                                               1
#define AQ_VIEWPORT_XSCALE_FieldMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_XSCALE_ReadMask                                   0xFFFFFFFF
#define AQ_VIEWPORT_XSCALE_WriteMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_XSCALE_ResetValue                                 0x00000000


#define AQ_VIEWPORT_XSCALE_SCALE                                            31:0
#define AQ_VIEWPORT_XSCALE_SCALE_End                                          31
#define AQ_VIEWPORT_XSCALE_SCALE_Start                                         0
#define AQ_VIEWPORT_XSCALE_SCALE_Type                                        U32

#define AQViewportYScaleRegAddrs                                          0x0281
#define AQ_VIEWPORT_YSCALE_Address                                       0x00A04
#define AQ_VIEWPORT_YSCALE_MSB                                                15
#define AQ_VIEWPORT_YSCALE_LSB                                                 0
#define AQ_VIEWPORT_YSCALE_BLK                                                 0
#define AQ_VIEWPORT_YSCALE_Count                                               1
#define AQ_VIEWPORT_YSCALE_FieldMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_YSCALE_ReadMask                                   0xFFFFFFFF
#define AQ_VIEWPORT_YSCALE_WriteMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_YSCALE_ResetValue                                 0x00000000


#define AQ_VIEWPORT_YSCALE_SCALE                                            31:0
#define AQ_VIEWPORT_YSCALE_SCALE_End                                          31
#define AQ_VIEWPORT_YSCALE_SCALE_Start                                         0
#define AQ_VIEWPORT_YSCALE_SCALE_Type                                        U32

#define AQViewportZScaleRegAddrs                                          0x0282
#define AQ_VIEWPORT_ZSCALE_Address                                       0x00A08
#define AQ_VIEWPORT_ZSCALE_MSB                                                15
#define AQ_VIEWPORT_ZSCALE_LSB                                                 0
#define AQ_VIEWPORT_ZSCALE_BLK                                                 0
#define AQ_VIEWPORT_ZSCALE_Count                                               1
#define AQ_VIEWPORT_ZSCALE_FieldMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_ZSCALE_ReadMask                                   0xFFFFFFFF
#define AQ_VIEWPORT_ZSCALE_WriteMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_ZSCALE_ResetValue                                 0x00000000


#define AQ_VIEWPORT_ZSCALE_SCALE                                            31:0
#define AQ_VIEWPORT_ZSCALE_SCALE_End                                          31
#define AQ_VIEWPORT_ZSCALE_SCALE_Start                                         0
#define AQ_VIEWPORT_ZSCALE_SCALE_Type                                        U32

#define AQViewportXOffsetRegAddrs                                         0x0283
#define AQ_VIEWPORT_XOFFSET_Address                                      0x00A0C
#define AQ_VIEWPORT_XOFFSET_MSB                                               15
#define AQ_VIEWPORT_XOFFSET_LSB                                                0
#define AQ_VIEWPORT_XOFFSET_BLK                                                0
#define AQ_VIEWPORT_XOFFSET_Count                                              1
#define AQ_VIEWPORT_XOFFSET_FieldMask                                 0xFFFFFFFF
#define AQ_VIEWPORT_XOFFSET_ReadMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_XOFFSET_WriteMask                                 0xFFFFFFFF
#define AQ_VIEWPORT_XOFFSET_ResetValue                                0x00000000


#define AQ_VIEWPORT_XOFFSET_OFFSET                                          31:0
#define AQ_VIEWPORT_XOFFSET_OFFSET_End                                        31
#define AQ_VIEWPORT_XOFFSET_OFFSET_Start                                       0
#define AQ_VIEWPORT_XOFFSET_OFFSET_Type                                      U32

#define AQViewportYOffsetRegAddrs                                         0x0284
#define AQ_VIEWPORT_YOFFSET_Address                                      0x00A10
#define AQ_VIEWPORT_YOFFSET_MSB                                               15
#define AQ_VIEWPORT_YOFFSET_LSB                                                0
#define AQ_VIEWPORT_YOFFSET_BLK                                                0
#define AQ_VIEWPORT_YOFFSET_Count                                              1
#define AQ_VIEWPORT_YOFFSET_FieldMask                                 0xFFFFFFFF
#define AQ_VIEWPORT_YOFFSET_ReadMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_YOFFSET_WriteMask                                 0xFFFFFFFF
#define AQ_VIEWPORT_YOFFSET_ResetValue                                0x00000000


#define AQ_VIEWPORT_YOFFSET_OFFSET                                          31:0
#define AQ_VIEWPORT_YOFFSET_OFFSET_End                                        31
#define AQ_VIEWPORT_YOFFSET_OFFSET_Start                                       0
#define AQ_VIEWPORT_YOFFSET_OFFSET_Type                                      U32

#define AQViewportZOffsetRegAddrs                                         0x0285
#define AQ_VIEWPORT_ZOFFSET_Address                                      0x00A14
#define AQ_VIEWPORT_ZOFFSET_MSB                                               15
#define AQ_VIEWPORT_ZOFFSET_LSB                                                0
#define AQ_VIEWPORT_ZOFFSET_BLK                                                0
#define AQ_VIEWPORT_ZOFFSET_Count                                              1
#define AQ_VIEWPORT_ZOFFSET_FieldMask                                 0xFFFFFFFF
#define AQ_VIEWPORT_ZOFFSET_ReadMask                                  0xFFFFFFFF
#define AQ_VIEWPORT_ZOFFSET_WriteMask                                 0xFFFFFFFF
#define AQ_VIEWPORT_ZOFFSET_ResetValue                                0x00000000


#define AQ_VIEWPORT_ZOFFSET_OFFSET                                          31:0
#define AQ_VIEWPORT_ZOFFSET_OFFSET_End                                        31
#define AQ_VIEWPORT_ZOFFSET_OFFSET_Start                                       0
#define AQ_VIEWPORT_ZOFFSET_OFFSET_Type                                      U32

#define AQPAClipAALineScaleRegAddrs                                       0x0286
#define AQPA_CLIP_AA_LINE_SCALE_Address                                  0x00A18
#define AQPA_CLIP_AA_LINE_SCALE_MSB                                           15
#define AQPA_CLIP_AA_LINE_SCALE_LSB                                            0
#define AQPA_CLIP_AA_LINE_SCALE_BLK                                            0
#define AQPA_CLIP_AA_LINE_SCALE_Count                                          1
#define AQPA_CLIP_AA_LINE_SCALE_FieldMask                             0xFFFFFFFF
#define AQPA_CLIP_AA_LINE_SCALE_ReadMask                              0xFFFFFFFF
#define AQPA_CLIP_AA_LINE_SCALE_WriteMask                             0xFFFFFFFF
#define AQPA_CLIP_AA_LINE_SCALE_ResetValue                            0x00000000


#define AQPA_CLIP_AA_LINE_SCALE_SCALE                                       31:0
#define AQPA_CLIP_AA_LINE_SCALE_SCALE_End                                     31
#define AQPA_CLIP_AA_LINE_SCALE_SCALE_Start                                    0
#define AQPA_CLIP_AA_LINE_SCALE_SCALE_Type                                   U32

#define AQPAClipPointSizeDivBy2RegAddrs                                   0x0287
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_Address                             0x00A1C
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_MSB                                      15
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_LSB                                       0
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_BLK                                       0
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_Count                                     1
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_FieldMask                        0xFFFFFFFF
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_ReadMask                         0xFFFFFFFF
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_WriteMask                        0xFFFFFFFF
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_ResetValue                       0x00000000


#define AQPA_CLIP_POINT_SIZE_DIV_BY2_SCALE                                  31:0
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_SCALE_End                                31
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_SCALE_Start                               0
#define AQPA_CLIP_POINT_SIZE_DIV_BY2_SCALE_Type                              U32




#define AQPAClipVTRegAddrs                                                0x0288
#define AQ_PACLIPVT_Address                                              0x00A20
#define AQ_PACLIPVT_MSB                                                       15
#define AQ_PACLIPVT_LSB                                                        0
#define AQ_PACLIPVT_BLK                                                        0
#define AQ_PACLIPVT_Count                                                      1
#define AQ_PACLIPVT_FieldMask                                         0x7FFFFFFF
#define AQ_PACLIPVT_ReadMask                                          0x7FFFFFFF
#define AQ_PACLIPVT_WriteMask                                         0x7FFFFFFF
#define AQ_PACLIPVT_ResetValue                                        0x00000000


#define AQ_PACLIPVT_ENPOS                                                    0:0
#define AQ_PACLIPVT_ENPOS_End                                                  0
#define AQ_PACLIPVT_ENPOS_Start                                                0
#define AQ_PACLIPVT_ENPOS_Type                                               U01
#define   AQ_PACLIPVT_ENPOS_DISABLE                                          0x0
#define   AQ_PACLIPVT_ENPOS_ENABLE                                           0x1


#define AQ_PACLIPVT_ENFOG                                                    1:1
#define AQ_PACLIPVT_ENFOG_End                                                  1
#define AQ_PACLIPVT_ENFOG_Start                                                1
#define AQ_PACLIPVT_ENFOG_Type                                               U01
#define   AQ_PACLIPVT_ENFOG_DISABLE                                          0x0
#define   AQ_PACLIPVT_ENFOG_ENABLE                                           0x1

#define AQ_PACLIPVT_ENPTSIZE                                                 2:2
#define AQ_PACLIPVT_ENPTSIZE_End                                               2
#define AQ_PACLIPVT_ENPTSIZE_Start                                             2
#define AQ_PACLIPVT_ENPTSIZE_Type                                            U01
#define   AQ_PACLIPVT_ENPTSIZE_DISABLE                                       0x0
#define   AQ_PACLIPVT_ENPTSIZE_ENABLE                                        0x1


#define AQ_PACLIPVT_COLOR0                                                   3:3
#define AQ_PACLIPVT_COLOR0_End                                                 3
#define AQ_PACLIPVT_COLOR0_Start                                               3
#define AQ_PACLIPVT_COLOR0_Type                                              U01
#define   AQ_PACLIPVT_COLOR0_DISABLE                                         0x0
#define   AQ_PACLIPVT_COLOR0_ENABLE                                          0x1


#define AQ_PACLIPVT_COLOR1                                                   4:4
#define AQ_PACLIPVT_COLOR1_End                                                 4
#define AQ_PACLIPVT_COLOR1_Start                                               4
#define AQ_PACLIPVT_COLOR1_Type                                              U01
#define   AQ_PACLIPVT_COLOR1_DISABLE                                         0x0
#define   AQ_PACLIPVT_COLOR1_ENABLE                                          0x1


#define AQ_PACLIPVT_TEXTURE0                                                 5:5
#define AQ_PACLIPVT_TEXTURE0_End                                               5
#define AQ_PACLIPVT_TEXTURE0_Start                                             5
#define AQ_PACLIPVT_TEXTURE0_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE0_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE0_ENABLE                                        0x1


#define AQ_PACLIPVT_TEXTURE1                                                 6:6
#define AQ_PACLIPVT_TEXTURE1_End                                               6
#define AQ_PACLIPVT_TEXTURE1_Start                                             6
#define AQ_PACLIPVT_TEXTURE1_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE1_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE1_ENABLE                                        0x1


#define AQ_PACLIPVT_TEXTURE2                                                 7:7
#define AQ_PACLIPVT_TEXTURE2_End                                               7
#define AQ_PACLIPVT_TEXTURE2_Start                                             7
#define AQ_PACLIPVT_TEXTURE2_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE2_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE2_ENABLE                                        0x1


#define AQ_PACLIPVT_TEXTURE3                                                 8:8
#define AQ_PACLIPVT_TEXTURE3_End                                               8
#define AQ_PACLIPVT_TEXTURE3_Start                                             8
#define AQ_PACLIPVT_TEXTURE3_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE3_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE3_ENABLE                                        0x1


#define AQ_PACLIPVT_TEXTURE4                                                 9:9
#define AQ_PACLIPVT_TEXTURE4_End                                               9
#define AQ_PACLIPVT_TEXTURE4_Start                                             9
#define AQ_PACLIPVT_TEXTURE4_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE4_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE4_ENABLE                                        0x1


#define AQ_PACLIPVT_TEXTURE5                                               10:10
#define AQ_PACLIPVT_TEXTURE5_End                                              10
#define AQ_PACLIPVT_TEXTURE5_Start                                            10
#define AQ_PACLIPVT_TEXTURE5_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE5_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE5_ENABLE                                        0x1


#define AQ_PACLIPVT_TEXTURE6                                               11:11
#define AQ_PACLIPVT_TEXTURE6_End                                              11
#define AQ_PACLIPVT_TEXTURE6_Start                                            11
#define AQ_PACLIPVT_TEXTURE6_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE6_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE6_ENABLE                                        0x1


#define AQ_PACLIPVT_TEXTURE7                                               12:12
#define AQ_PACLIPVT_TEXTURE7_End                                              12
#define AQ_PACLIPVT_TEXTURE7_Start                                            12
#define AQ_PACLIPVT_TEXTURE7_Type                                            U01
#define   AQ_PACLIPVT_TEXTURE7_DISABLE                                       0x0
#define   AQ_PACLIPVT_TEXTURE7_ENABLE                                        0x1


#define AQ_PACLIPVT_CULLMODE                                               14:13
#define AQ_PACLIPVT_CULLMODE_End                                              14
#define AQ_PACLIPVT_CULLMODE_Start                                            13
#define AQ_PACLIPVT_CULLMODE_Type                                            U02
#define   AQ_PACLIPVT_CULLMODE_NONE                                          0x0
#define   AQ_PACLIPVT_CULLMODE_CW                                            0x1
#define   AQ_PACLIPVT_CULLMODE_CCW                                           0x2


#define AQ_PACLIPVT_FILLMODE                                               16:15
#define AQ_PACLIPVT_FILLMODE_End                                              16
#define AQ_PACLIPVT_FILLMODE_Start                                            15
#define AQ_PACLIPVT_FILLMODE_Type                                            U02
#define   AQ_PACLIPVT_FILLMODE_POINT                                         0x0
#define   AQ_PACLIPVT_FILLMODE_WIREFRAME                                     0x1
#define   AQ_PACLIPVT_FILLMODE_SOLID                                         0x2


#define AQ_PACLIPVT_SHADEMODE                                              18:17
#define AQ_PACLIPVT_SHADEMODE_End                                             18
#define AQ_PACLIPVT_SHADEMODE_Start                                           17
#define AQ_PACLIPVT_SHADEMODE_Type                                           U02
#define   AQ_PACLIPVT_SHADEMODE_FLAT                                         0x0
#define   AQ_PACLIPVT_SHADEMODE_GOURAUD                                      0x1


#define AQ_PACLIPVT_TEXTUREWRAP                                            19:19
#define AQ_PACLIPVT_TEXTUREWRAP_End                                           19
#define AQ_PACLIPVT_TEXTUREWRAP_Start                                         19
#define AQ_PACLIPVT_TEXTUREWRAP_Type                                         U01
#define   AQ_PACLIPVT_TEXTUREWRAP_DISABLE                                    0x0
#define   AQ_PACLIPVT_TEXTUREWRAP_ENABLE                                     0x1


#define AQ_PACLIPVT_ENPTSPRITE                                             20:20
#define AQ_PACLIPVT_ENPTSPRITE_End                                            20
#define AQ_PACLIPVT_ENPTSPRITE_Start                                          20
#define AQ_PACLIPVT_ENPTSPRITE_Type                                          U01
#define   AQ_PACLIPVT_ENPTSPRITE_DISABLE                                     0x0
#define   AQ_PACLIPVT_ENPTSPRITE_ENABLE                                      0x1


#define AQ_PACLIPVT_FOG_TYPE                                               22:21
#define AQ_PACLIPVT_FOG_TYPE_End                                              22
#define AQ_PACLIPVT_FOG_TYPE_Start                                            21
#define AQ_PACLIPVT_FOG_TYPE_Type                                            U02


#define AQ_PACLIPVT_ISTRANSFORM                                            23:23
#define AQ_PACLIPVT_ISTRANSFORM_End                                           23
#define AQ_PACLIPVT_ISTRANSFORM_Start                                         23
#define AQ_PACLIPVT_ISTRANSFORM_Type                                         U01
#define   AQ_PACLIPVT_ISTRANSFORM_DISABLE                                    0x0
#define   AQ_PACLIPVT_ISTRANSFORM_ENABLE                                     0x1


#define AQ_PACLIPVT_ANTIALIASLINE                                          24:24
#define AQ_PACLIPVT_ANTIALIASLINE_End                                         24
#define AQ_PACLIPVT_ANTIALIASLINE_Start                                       24
#define AQ_PACLIPVT_ANTIALIASLINE_Type                                       U01
#define   AQ_PACLIPVT_ANTIALIASLINE_DISABLE                                  0x0
#define   AQ_PACLIPVT_ANTIALIASLINE_ENABLE                                   0x1


#define AQ_PACLIPVT_CLIP_LINE_PER_PIXEL                                    25:25
#define AQ_PACLIPVT_CLIP_LINE_PER_PIXEL_End                                   25
#define AQ_PACLIPVT_CLIP_LINE_PER_PIXEL_Start                                 25
#define AQ_PACLIPVT_CLIP_LINE_PER_PIXEL_Type                                 U01
#define   AQ_PACLIPVT_CLIP_LINE_PER_PIXEL_DISABLE                            0x0
#define   AQ_PACLIPVT_CLIP_LINE_PER_PIXEL_ENABLE                             0x1


#define AQ_PACLIPVT_TEXFORAALINE                                           29:26
#define AQ_PACLIPVT_TEXFORAALINE_End                                          29
#define AQ_PACLIPVT_TEXFORAALINE_Start                                        26
#define AQ_PACLIPVT_TEXFORAALINE_Type                                        U04
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE0                                  0x0
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE1                                  0x1
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE2                                  0x2
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE3                                  0x3
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE4                                  0x4
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE5                                  0x5
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE6                                  0x6
#define   AQ_PACLIPVT_TEXFORAALINE_TEXTURE7                                  0x7


#define AQ_PACLIPVT_CLIP_USE_W                                             30:30
#define AQ_PACLIPVT_CLIP_USE_W_End                                            30
#define AQ_PACLIPVT_CLIP_USE_W_Start                                          30
#define AQ_PACLIPVT_CLIP_USE_W_Type                                          U01
#define   AQ_PACLIPVT_CLIP_USE_W_DISABLE                                     0x0
#define   AQ_PACLIPVT_CLIP_USE_W_AUTOMATIC                                   0x1

#define AQPrimTypeRegAddrs                                                0x0289
#define AQ_PRIM_TYPE_Address                                             0x00A24
#define AQ_PRIM_TYPE_MSB                                                      15
#define AQ_PRIM_TYPE_LSB                                                       0
#define AQ_PRIM_TYPE_BLK                                                       0
#define AQ_PRIM_TYPE_Count                                                     1
#define AQ_PRIM_TYPE_FieldMask                                        0x0000003F
#define AQ_PRIM_TYPE_ReadMask                                         0x0000003F
#define AQ_PRIM_TYPE_WriteMask                                        0x0000003F
#define AQ_PRIM_TYPE_ResetValue                                       0x00000000


#define AQ_PRIM_TYPE_PRIMTYPE                                                3:0
#define AQ_PRIM_TYPE_PRIMTYPE_End                                              3
#define AQ_PRIM_TYPE_PRIMTYPE_Start                                            0
#define AQ_PRIM_TYPE_PRIMTYPE_Type                                           U04
#define   AQ_PRIM_TYPE_PRIMTYPE_POINT_LIST                                   0x1
#define   AQ_PRIM_TYPE_PRIMTYPE_LINE_LIST                                    0x2
#define   AQ_PRIM_TYPE_PRIMTYPE_LINE_STRIP                                   0x3
#define   AQ_PRIM_TYPE_PRIMTYPE_TRIANGLE_LIST                                0x4
#define   AQ_PRIM_TYPE_PRIMTYPE_TRIANGLE_STRIP                               0x5
#define   AQ_PRIM_TYPE_PRIMTYPE_TRIANGLE_FAN                                 0x6
#define   AQ_PRIM_TYPE_PRIMTYPE_LINE_LOOP                                    0x7
#define   AQ_PRIM_TYPE_PRIMTYPE_RECTANGLE                                    0x8
#define   AQ_PRIM_TYPE_PRIMTYPE_LINES_ADJACENCY                              0x9
#define   AQ_PRIM_TYPE_PRIMTYPE_LINE_STRIP_ADJACENCY                         0xA
#define   AQ_PRIM_TYPE_PRIMTYPE_TRIANGLES_ADJACENCY                          0xB
#define   AQ_PRIM_TYPE_PRIMTYPE_TRIANGLE_STRIP_ADJACENCY                     0xC
#define   AQ_PRIM_TYPE_PRIMTYPE_PATCH_LIST                                   0xD


#define AQ_PRIM_TYPE_INSTANCE_MODE                                           4:4
#define AQ_PRIM_TYPE_INSTANCE_MODE_End                                         4
#define AQ_PRIM_TYPE_INSTANCE_MODE_Start                                       4
#define AQ_PRIM_TYPE_INSTANCE_MODE_Type                                      U01
#define   AQ_PRIM_TYPE_INSTANCE_MODE_DISABLE                                 0x0
#define   AQ_PRIM_TYPE_INSTANCE_MODE_ENABLE                                  0x1


#define AQ_PRIM_TYPE_DRAW_MODE                                               5:5
#define AQ_PRIM_TYPE_DRAW_MODE_End                                             5
#define AQ_PRIM_TYPE_DRAW_MODE_Start                                           5
#define AQ_PRIM_TYPE_DRAW_MODE_Type                                          U01
#define   AQ_PRIM_TYPE_DRAW_MODE_ARRAY                                       0x0
#define   AQ_PRIM_TYPE_DRAW_MODE_ELEMENT                                     0x1

#define AQSystemRegAddrs                                                  0x028A
#define AQ_SYSTEM_Address                                                0x00A28
#define AQ_SYSTEM_MSB                                                         15
#define AQ_SYSTEM_LSB                                                          0
#define AQ_SYSTEM_BLK                                                          0
#define AQ_SYSTEM_Count                                                        1
#define AQ_SYSTEM_FieldMask                                           0x00000013
#define AQ_SYSTEM_ReadMask                                            0x00000013
#define AQ_SYSTEM_WriteMask                                           0x00000013
#define AQ_SYSTEM_ResetValue                                          0x00000000


#define AQ_SYSTEM_MODE                                                       1:0
#define AQ_SYSTEM_MODE_End                                                     1
#define AQ_SYSTEM_MODE_Start                                                   0
#define AQ_SYSTEM_MODE_Type                                                  U02
#define   AQ_SYSTEM_MODE_D3D                                                 0x0
#define   AQ_SYSTEM_MODE_GL                                                  0x1


#define AQ_SYSTEM_ADD_DOT5                                                   4:4
#define AQ_SYSTEM_ADD_DOT5_End                                                 4
#define AQ_SYSTEM_ADD_DOT5_Start                                               4
#define AQ_SYSTEM_ADD_DOT5_Type                                              U01
#define   AQ_SYSTEM_ADD_DOT5_OFF                                             0x0
#define   AQ_SYSTEM_ADD_DOT5_ON                                              0x1

#define AQPAClipWplaneLimitRegAddrs                                       0x028B
#define AQPA_CLIP_WPLANE_LIMIT_Address                                   0x00A2C
#define AQPA_CLIP_WPLANE_LIMIT_MSB                                            15
#define AQPA_CLIP_WPLANE_LIMIT_LSB                                             0
#define AQPA_CLIP_WPLANE_LIMIT_BLK                                             0
#define AQPA_CLIP_WPLANE_LIMIT_Count                                           1
#define AQPA_CLIP_WPLANE_LIMIT_FieldMask                              0xFFFFFFFF
#define AQPA_CLIP_WPLANE_LIMIT_ReadMask                               0xFFFFFFFF
#define AQPA_CLIP_WPLANE_LIMIT_WriteMask                              0xFFFFFFFF
#define AQPA_CLIP_WPLANE_LIMIT_ResetValue                             0x00000000


#define AQPA_CLIP_WPLANE_LIMIT_VALUE                                        31:0
#define AQPA_CLIP_WPLANE_LIMIT_VALUE_End                                      31
#define AQPA_CLIP_WPLANE_LIMIT_VALUE_Start                                     0
#define AQPA_CLIP_WPLANE_LIMIT_VALUE_Type                                    U32

#define AQPAClipVT30RegAddrs                                              0x028C
#define AQ_PACLIPVT30_Address                                            0x00A30
#define AQ_PACLIPVT30_MSB                                                     15
#define AQ_PACLIPVT30_LSB                                                      0
#define AQ_PACLIPVT30_BLK                                                      0
#define AQ_PACLIPVT30_Count                                                    1
#define AQ_PACLIPVT30_FieldMask                                       0x00000FFF
#define AQ_PACLIPVT30_ReadMask                                        0x00000FFF
#define AQ_PACLIPVT30_WriteMask                                       0x00000FFF
#define AQ_PACLIPVT30_ResetValue                                      0x00000000


#define AQ_PACLIPVT30_RESV_BITS                                              7:0
#define AQ_PACLIPVT30_RESV_BITS_End                                            7
#define AQ_PACLIPVT30_RESV_BITS_Start                                          0
#define AQ_PACLIPVT30_RESV_BITS_Type                                         U08


#define AQ_PACLIPVT30_ELEMENT_COUNT                                         11:8
#define AQ_PACLIPVT30_ELEMENT_COUNT_End                                       11
#define AQ_PACLIPVT30_ELEMENT_COUNT_Start                                      8
#define AQ_PACLIPVT30_ELEMENT_COUNT_Type                                     U04




#define AQPAClipFlatColorTexRegAddrs                                      0x0290
#define AQPA_CLIP_FLAT_COLOR_TEX_Address                                 0x00A40
#define AQPA_CLIP_FLAT_COLOR_TEX_MSB                                          15
#define AQPA_CLIP_FLAT_COLOR_TEX_LSB                                           4
#define AQPA_CLIP_FLAT_COLOR_TEX_BLK                                           4
#define AQPA_CLIP_FLAT_COLOR_TEX_Count                                        16
#define AQPA_CLIP_FLAT_COLOR_TEX_FieldMask                            0x00000FF1
#define AQPA_CLIP_FLAT_COLOR_TEX_ReadMask                             0x00000FF1
#define AQPA_CLIP_FLAT_COLOR_TEX_WriteMask                            0x00000FF1
#define AQPA_CLIP_FLAT_COLOR_TEX_ResetValue                           0x00000000

#define AQPA_CLIP_FLAT_COLOR_TEX_TYPE                                        0:0
#define AQPA_CLIP_FLAT_COLOR_TEX_TYPE_End                                      0
#define AQPA_CLIP_FLAT_COLOR_TEX_TYPE_Start                                    0
#define AQPA_CLIP_FLAT_COLOR_TEX_TYPE_Type                                   U01
#define   AQPA_CLIP_FLAT_COLOR_TEX_TYPE_COLOR                                0x0

#define   AQPA_CLIP_FLAT_COLOR_TEX_TYPE_NOTCOLOR                             0x1

#define AQPA_CLIP_FLAT_COLOR_TEX_COMPONENT                                   7:4
#define AQPA_CLIP_FLAT_COLOR_TEX_COMPONENT_End                                 7
#define AQPA_CLIP_FLAT_COLOR_TEX_COMPONENT_Start                               4
#define AQPA_CLIP_FLAT_COLOR_TEX_COMPONENT_Type                              U04
#define   AQPA_CLIP_FLAT_COLOR_TEX_COMPONENT_DISABLE                         0x0
#define   AQPA_CLIP_FLAT_COLOR_TEX_COMPONENT_ENABLE                          0x1

#define AQPA_CLIP_FLAT_COLOR_TEX_COORD                                      11:8
#define AQPA_CLIP_FLAT_COLOR_TEX_COORD_End                                    11
#define AQPA_CLIP_FLAT_COLOR_TEX_COORD_Start                                   8
#define AQPA_CLIP_FLAT_COLOR_TEX_COORD_Type                                  U04
#define   AQPA_CLIP_FLAT_COLOR_TEX_COORD_U                                   0x0
#define   AQPA_CLIP_FLAT_COLOR_TEX_COORD_V                                   0x1

#define AQPAMaskedRegAddrs                                                0x028D
#define AQPA_MASKED_Address                                              0x00A34
#define AQPA_MASKED_MSB                                                       15
#define AQPA_MASKED_LSB                                                        0
#define AQPA_MASKED_BLK                                                        0
#define AQPA_MASKED_Count                                                      1
#define AQPA_MASKED_FieldMask                                         0x7FF777FF
#define AQPA_MASKED_ReadMask                                          0x7FF777FF
#define AQPA_MASKED_WriteMask                                         0x7FF777FF
#define AQPA_MASKED_ResetValue                                        0x00000000


#define AQPA_MASKED_RESV_BITS                                                1:0
#define AQPA_MASKED_RESV_BITS_End                                              1
#define AQPA_MASKED_RESV_BITS_Start                                            0
#define AQPA_MASKED_RESV_BITS_Type                                           U02

#define AQPA_MASKED_ENABLE_POINT_SIZE                                        2:2
#define AQPA_MASKED_ENABLE_POINT_SIZE_End                                      2
#define AQPA_MASKED_ENABLE_POINT_SIZE_Start                                    2
#define AQPA_MASKED_ENABLE_POINT_SIZE_Type                                   U01
#define   AQPA_MASKED_ENABLE_POINT_SIZE_DISABLE                              0x0
#define   AQPA_MASKED_ENABLE_POINT_SIZE_ENABLE                               0x1


#define AQPA_MASKED_MASK_ENABLE_POINT_SIZE                                   3:3
#define AQPA_MASKED_MASK_ENABLE_POINT_SIZE_End                                 3
#define AQPA_MASKED_MASK_ENABLE_POINT_SIZE_Start                               3
#define AQPA_MASKED_MASK_ENABLE_POINT_SIZE_Type                              U01
#define   AQPA_MASKED_MASK_ENABLE_POINT_SIZE_ENABLED                         0x0
#define   AQPA_MASKED_MASK_ENABLE_POINT_SIZE_MASKED                          0x1


#define AQPA_MASKED_ENABLE_POINT_SPRITE                                      4:4
#define AQPA_MASKED_ENABLE_POINT_SPRITE_End                                    4
#define AQPA_MASKED_ENABLE_POINT_SPRITE_Start                                  4
#define AQPA_MASKED_ENABLE_POINT_SPRITE_Type                                 U01
#define   AQPA_MASKED_ENABLE_POINT_SPRITE_DISABLED                           0x0
#define   AQPA_MASKED_ENABLE_POINT_SPRITE_ENABLED                            0x1


#define AQPA_MASKED_MASK_ENABLE_POINT_SPRITE                                 5:5
#define AQPA_MASKED_MASK_ENABLE_POINT_SPRITE_End                               5
#define AQPA_MASKED_MASK_ENABLE_POINT_SPRITE_Start                             5
#define AQPA_MASKED_MASK_ENABLE_POINT_SPRITE_Type                            U01
#define   AQPA_MASKED_MASK_ENABLE_POINT_SPRITE_ENABLED                       0x0
#define   AQPA_MASKED_MASK_ENABLE_POINT_SPRITE_MASKED                        0x1


#define AQPA_MASKED_ENABLE_PRIMITIVE_ID                                      6:6
#define AQPA_MASKED_ENABLE_PRIMITIVE_ID_End                                    6
#define AQPA_MASKED_ENABLE_PRIMITIVE_ID_Start                                  6
#define AQPA_MASKED_ENABLE_PRIMITIVE_ID_Type                                 U01
#define   AQPA_MASKED_ENABLE_PRIMITIVE_ID_DISABLED                           0x0
#define   AQPA_MASKED_ENABLE_PRIMITIVE_ID_ENABLED                            0x1


#define AQPA_MASKED_MASK_ENABLE_PRIMITIVE_ID                                 7:7
#define AQPA_MASKED_MASK_ENABLE_PRIMITIVE_ID_End                               7
#define AQPA_MASKED_MASK_ENABLE_PRIMITIVE_ID_Start                             7
#define AQPA_MASKED_MASK_ENABLE_PRIMITIVE_ID_Type                            U01
#define   AQPA_MASKED_MASK_ENABLE_PRIMITIVE_ID_ENABLED                       0x0
#define   AQPA_MASKED_MASK_ENABLE_PRIMITIVE_ID_MASKED                        0x1


#define AQPA_MASKED_CULL_MODE                                                9:8
#define AQPA_MASKED_CULL_MODE_End                                              9
#define AQPA_MASKED_CULL_MODE_Start                                            8
#define AQPA_MASKED_CULL_MODE_Type                                           U02
#define   AQPA_MASKED_CULL_MODE_NONE                                         0x0
#define   AQPA_MASKED_CULL_MODE_CW                                           0x1
#define   AQPA_MASKED_CULL_MODE_CCW                                          0x2


#define AQPA_MASKED_MASK_CULL_MODE                                         10:10
#define AQPA_MASKED_MASK_CULL_MODE_End                                        10
#define AQPA_MASKED_MASK_CULL_MODE_Start                                      10
#define AQPA_MASKED_MASK_CULL_MODE_Type                                      U01
#define   AQPA_MASKED_MASK_CULL_MODE_ENABLED                                 0x0
#define   AQPA_MASKED_MASK_CULL_MODE_MASKED                                  0x1


#define AQPA_MASKED_FILL_MODE                                              13:12
#define AQPA_MASKED_FILL_MODE_End                                             13
#define AQPA_MASKED_FILL_MODE_Start                                           12
#define AQPA_MASKED_FILL_MODE_Type                                           U02
#define   AQPA_MASKED_FILL_MODE_POINT                                        0x0
#define   AQPA_MASKED_FILL_MODE_WIREFRAME                                    0x1
#define   AQPA_MASKED_FILL_MODE_SOLID                                        0x2


#define AQPA_MASKED_MASK_FILL_MODE                                         14:14
#define AQPA_MASKED_MASK_FILL_MODE_End                                        14
#define AQPA_MASKED_MASK_FILL_MODE_Start                                      14
#define AQPA_MASKED_MASK_FILL_MODE_Type                                      U01
#define   AQPA_MASKED_MASK_FILL_MODE_ENABLED                                 0x0
#define   AQPA_MASKED_MASK_FILL_MODE_MASKED                                  0x1


#define AQPA_MASKED_SHADE_MODE                                             17:16
#define AQPA_MASKED_SHADE_MODE_End                                            17
#define AQPA_MASKED_SHADE_MODE_Start                                          16
#define AQPA_MASKED_SHADE_MODE_Type                                          U02
#define   AQPA_MASKED_SHADE_MODE_FLAT                                        0x0
#define   AQPA_MASKED_SHADE_MODE_GOURAUD                                     0x1


#define AQPA_MASKED_MASK_SHADE_MODE                                        18:18
#define AQPA_MASKED_MASK_SHADE_MODE_End                                       18
#define AQPA_MASKED_MASK_SHADE_MODE_Start                                     18
#define AQPA_MASKED_MASK_SHADE_MODE_Type                                     U01
#define   AQPA_MASKED_MASK_SHADE_MODE_ENABLED                                0x0
#define   AQPA_MASKED_MASK_SHADE_MODE_MASKED                                 0x1


#define AQPA_MASKED_IS_TRANSFORMED                                         20:20
#define AQPA_MASKED_IS_TRANSFORMED_End                                        20
#define AQPA_MASKED_IS_TRANSFORMED_Start                                      20
#define AQPA_MASKED_IS_TRANSFORMED_Type                                      U01
#define   AQPA_MASKED_IS_TRANSFORMED_DISABLE                                 0x0
#define   AQPA_MASKED_IS_TRANSFORMED_ENABLE                                  0x1


#define AQPA_MASKED_MASK_IS_TRANSFORMED                                    21:21
#define AQPA_MASKED_MASK_IS_TRANSFORMED_End                                   21
#define AQPA_MASKED_MASK_IS_TRANSFORMED_Start                                 21
#define AQPA_MASKED_MASK_IS_TRANSFORMED_Type                                 U01
#define   AQPA_MASKED_MASK_IS_TRANSFORMED_ENABLED                            0x0
#define   AQPA_MASKED_MASK_IS_TRANSFORMED_MASKED                             0x1


#define AQPA_MASKED_ANTI_ALIAS_LINE                                        22:22
#define AQPA_MASKED_ANTI_ALIAS_LINE_End                                       22
#define AQPA_MASKED_ANTI_ALIAS_LINE_Start                                     22
#define AQPA_MASKED_ANTI_ALIAS_LINE_Type                                     U01
#define   AQPA_MASKED_ANTI_ALIAS_LINE_DISABLE                                0x0
#define   AQPA_MASKED_ANTI_ALIAS_LINE_ENABLE                                 0x1


#define AQPA_MASKED_MASK_ANTI_ALIAS_LINE                                   23:23
#define AQPA_MASKED_MASK_ANTI_ALIAS_LINE_End                                  23
#define AQPA_MASKED_MASK_ANTI_ALIAS_LINE_Start                                23
#define AQPA_MASKED_MASK_ANTI_ALIAS_LINE_Type                                U01
#define   AQPA_MASKED_MASK_ANTI_ALIAS_LINE_ENABLED                           0x0
#define   AQPA_MASKED_MASK_ANTI_ALIAS_LINE_MASKED                            0x1


#define AQPA_MASKED_TEXTURE_FOR_ANTI_ALIAS_LINE                            27:24
#define AQPA_MASKED_TEXTURE_FOR_ANTI_ALIAS_LINE_End                           27
#define AQPA_MASKED_TEXTURE_FOR_ANTI_ALIAS_LINE_Start                         24
#define AQPA_MASKED_TEXTURE_FOR_ANTI_ALIAS_LINE_Type                         U04


#define AQPA_MASKED_MASK_TEXTURE_FOR_ANTI_ALIAS_LINE                       28:28
#define AQPA_MASKED_MASK_TEXTURE_FOR_ANTI_ALIAS_LINE_End                      28
#define AQPA_MASKED_MASK_TEXTURE_FOR_ANTI_ALIAS_LINE_Start                    28
#define AQPA_MASKED_MASK_TEXTURE_FOR_ANTI_ALIAS_LINE_Type                    U01
#define   AQPA_MASKED_MASK_TEXTURE_FOR_ANTI_ALIAS_LINE_ENABLED               0x0
#define   AQPA_MASKED_MASK_TEXTURE_FOR_ANTI_ALIAS_LINE_MASKED                0x1


#define AQPA_MASKED_CLIP_USE_W                                             29:29
#define AQPA_MASKED_CLIP_USE_W_End                                            29
#define AQPA_MASKED_CLIP_USE_W_Start                                          29
#define AQPA_MASKED_CLIP_USE_W_Type                                          U01
#define   AQPA_MASKED_CLIP_USE_W_DISABLE                                     0x0
#define   AQPA_MASKED_CLIP_USE_W_AUTOMATIC                                   0x1


#define AQPA_MASKED_MASK_CLIP_USE_W                                        30:30
#define AQPA_MASKED_MASK_CLIP_USE_W_End                                       30
#define AQPA_MASKED_MASK_CLIP_USE_W_Start                                     30
#define AQPA_MASKED_MASK_CLIP_USE_W_Type                                     U01
#define   AQPA_MASKED_MASK_CLIP_USE_W_ENABLED                                0x0
#define   AQPA_MASKED_MASK_CLIP_USE_W_MASKED                                 0x1




#define mwv207regPALineAdjustSubRegAddrs                                  0x028E
#define MWV207REG_PA_LINE_ADJUST_SUB_Address                             0x00A38
#define MWV207REG_PA_LINE_ADJUST_SUB_MSB                                      15
#define MWV207REG_PA_LINE_ADJUST_SUB_LSB                                       0
#define MWV207REG_PA_LINE_ADJUST_SUB_BLK                                       0
#define MWV207REG_PA_LINE_ADJUST_SUB_Count                                     1
#define MWV207REG_PA_LINE_ADJUST_SUB_FieldMask                        0xFFFFFFFF
#define MWV207REG_PA_LINE_ADJUST_SUB_ReadMask                         0xFFFFFFFF
#define MWV207REG_PA_LINE_ADJUST_SUB_WriteMask                        0xFFFFFFFF
#define MWV207REG_PA_LINE_ADJUST_SUB_ResetValue                       0x00000000

#define MWV207REG_PA_LINE_ADJUST_SUB_FL32_VALUE                             31:0
#define MWV207REG_PA_LINE_ADJUST_SUB_FL32_VALUE_End                           31
#define MWV207REG_PA_LINE_ADJUST_SUB_FL32_VALUE_Start                          0
#define MWV207REG_PA_LINE_ADJUST_SUB_FL32_VALUE_Type                         U32



#define mwv207regPALineAdjustAddRegAddrs                                  0x028F
#define MWV207REG_PA_LINE_ADJUST_ADD_Address                             0x00A3C
#define MWV207REG_PA_LINE_ADJUST_ADD_MSB                                      15
#define MWV207REG_PA_LINE_ADJUST_ADD_LSB                                       0
#define MWV207REG_PA_LINE_ADJUST_ADD_BLK                                       0
#define MWV207REG_PA_LINE_ADJUST_ADD_Count                                     1
#define MWV207REG_PA_LINE_ADJUST_ADD_FieldMask                        0xFFFFFFFF
#define MWV207REG_PA_LINE_ADJUST_ADD_ReadMask                         0xFFFFFFFF
#define MWV207REG_PA_LINE_ADJUST_ADD_WriteMask                        0xFFFFFFFF
#define MWV207REG_PA_LINE_ADJUST_ADD_ResetValue                       0x00000000

#define MWV207REG_PA_LINE_ADJUST_ADD_FL32_VALUE                             31:0
#define MWV207REG_PA_LINE_ADJUST_ADD_FL32_VALUE_End                           31
#define MWV207REG_PA_LINE_ADJUST_ADD_FL32_VALUE_Start                          0
#define MWV207REG_PA_LINE_ADJUST_ADD_FL32_VALUE_Type                         U32




#define mwv207regPAClipWRegAddrs                                          0x02A0
#define MWV207REG_PA_CLIP_W_Address                                      0x00A80
#define MWV207REG_PA_CLIP_W_MSB                                               15
#define MWV207REG_PA_CLIP_W_LSB                                                0
#define MWV207REG_PA_CLIP_W_BLK                                                0
#define MWV207REG_PA_CLIP_W_Count                                              1
#define MWV207REG_PA_CLIP_W_FieldMask                                 0xFFFFFFFF
#define MWV207REG_PA_CLIP_W_ReadMask                                  0xFFFFFFFF
#define MWV207REG_PA_CLIP_W_WriteMask                                 0xFFFFFFFF
#define MWV207REG_PA_CLIP_W_ResetValue                                0x00000000

#define MWV207REG_PA_CLIP_W_FL32                                            31:0
#define MWV207REG_PA_CLIP_W_FL32_End                                          31
#define MWV207REG_PA_CLIP_W_FL32_Start                                         0
#define MWV207REG_PA_CLIP_W_FL32_Type                                        U32




#define mwv207regPAMaxPointSizeRegAddrs                                   0x02A1
#define MWV207REG_PA_MAX_POINT_SIZE_Address                              0x00A84
#define MWV207REG_PA_MAX_POINT_SIZE_MSB                                       15
#define MWV207REG_PA_MAX_POINT_SIZE_LSB                                        0
#define MWV207REG_PA_MAX_POINT_SIZE_BLK                                        0
#define MWV207REG_PA_MAX_POINT_SIZE_Count                                      1
#define MWV207REG_PA_MAX_POINT_SIZE_FieldMask                         0xFFFFFFFF
#define MWV207REG_PA_MAX_POINT_SIZE_ReadMask                          0xFFFFFFFF
#define MWV207REG_PA_MAX_POINT_SIZE_WriteMask                         0xFFFFFFFF
#define MWV207REG_PA_MAX_POINT_SIZE_ResetValue                        0x00000000

#define MWV207REG_PA_MAX_POINT_SIZE_FL32                                    31:0
#define MWV207REG_PA_MAX_POINT_SIZE_FL32_End                                  31
#define MWV207REG_PA_MAX_POINT_SIZE_FL32_Start                                 0
#define MWV207REG_PA_MAX_POINT_SIZE_FL32_Type                                U32




#define mwv207regPAClipControlRegAddrs                                    0x02A2
#define MWV207REG_PA_CLIP_CONTROL_Address                                0x00A88
#define MWV207REG_PA_CLIP_CONTROL_MSB                                         15
#define MWV207REG_PA_CLIP_CONTROL_LSB                                          0
#define MWV207REG_PA_CLIP_CONTROL_BLK                                          0
#define MWV207REG_PA_CLIP_CONTROL_Count                                        1
#define MWV207REG_PA_CLIP_CONTROL_FieldMask                           0x53111111
#define MWV207REG_PA_CLIP_CONTROL_ReadMask                            0x53111111
#define MWV207REG_PA_CLIP_CONTROL_WriteMask                           0x53111111
#define MWV207REG_PA_CLIP_CONTROL_ResetValue                          0x00000000

#define MWV207REG_PA_CLIP_CONTROL_CLIP_DISABLE                               0:0
#define MWV207REG_PA_CLIP_CONTROL_CLIP_DISABLE_End                             0
#define MWV207REG_PA_CLIP_CONTROL_CLIP_DISABLE_Start                           0
#define MWV207REG_PA_CLIP_CONTROL_CLIP_DISABLE_Type                          U01
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_DISABLE_ENABLED                     0x0
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_DISABLE_DISABLED                    0x1

#define MWV207REG_PA_CLIP_CONTROL_CLIP_WPLANE_DISABLE                        4:4
#define MWV207REG_PA_CLIP_CONTROL_CLIP_WPLANE_DISABLE_End                      4
#define MWV207REG_PA_CLIP_CONTROL_CLIP_WPLANE_DISABLE_Start                    4
#define MWV207REG_PA_CLIP_CONTROL_CLIP_WPLANE_DISABLE_Type                   U01
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_WPLANE_DISABLE_ENABLED              0x0
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_WPLANE_DISABLE_DISABLED             0x1

#define MWV207REG_PA_CLIP_CONTROL_CLIP_LINE_DISABLE                          8:8
#define MWV207REG_PA_CLIP_CONTROL_CLIP_LINE_DISABLE_End                        8
#define MWV207REG_PA_CLIP_CONTROL_CLIP_LINE_DISABLE_Start                      8
#define MWV207REG_PA_CLIP_CONTROL_CLIP_LINE_DISABLE_Type                     U01
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_LINE_DISABLE_ENABLED                0x0
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_LINE_DISABLE_DISABLED               0x1

#define MWV207REG_PA_CLIP_CONTROL_CLIP_TRIANGLE_DISABLE                    12:12
#define MWV207REG_PA_CLIP_CONTROL_CLIP_TRIANGLE_DISABLE_End                   12
#define MWV207REG_PA_CLIP_CONTROL_CLIP_TRIANGLE_DISABLE_Start                 12
#define MWV207REG_PA_CLIP_CONTROL_CLIP_TRIANGLE_DISABLE_Type                 U01
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_TRIANGLE_DISABLE_ENABLED            0x0
#define   MWV207REG_PA_CLIP_CONTROL_CLIP_TRIANGLE_DISABLE_DISABLED           0x1

#define MWV207REG_PA_CLIP_CONTROL_CLAMP_COORDINATES_DISABLE                16:16
#define MWV207REG_PA_CLIP_CONTROL_CLAMP_COORDINATES_DISABLE_End               16
#define MWV207REG_PA_CLIP_CONTROL_CLAMP_COORDINATES_DISABLE_Start             16
#define MWV207REG_PA_CLIP_CONTROL_CLAMP_COORDINATES_DISABLE_Type             U01
#define   MWV207REG_PA_CLIP_CONTROL_CLAMP_COORDINATES_DISABLE_ENABLED        0x0
#define   MWV207REG_PA_CLIP_CONTROL_CLAMP_COORDINATES_DISABLE_DISABLED       0x1


#define MWV207REG_PA_CLIP_CONTROL_CLIP_NEGATIVE_W                          20:20
#define MWV207REG_PA_CLIP_CONTROL_CLIP_NEGATIVE_W_End                         20
#define MWV207REG_PA_CLIP_CONTROL_CLIP_NEGATIVE_W_Start                       20
#define MWV207REG_PA_CLIP_CONTROL_CLIP_NEGATIVE_W_Type                       U01

#define   MWV207REG_PA_CLIP_CONTROL_CLIP_NEGATIVE_W_CLAMP                    0x0

#define   MWV207REG_PA_CLIP_CONTROL_CLIP_NEGATIVE_W_DROP                     0x1


#define MWV207REG_PA_CLIP_CONTROL_CLIP_FAR_Z                               24:24
#define MWV207REG_PA_CLIP_CONTROL_CLIP_FAR_Z_End                              24
#define MWV207REG_PA_CLIP_CONTROL_CLIP_FAR_Z_Start                            24
#define MWV207REG_PA_CLIP_CONTROL_CLIP_FAR_Z_Type                            U01

#define   MWV207REG_PA_CLIP_CONTROL_CLIP_FAR_Z_ENABLED                       0x0

#define   MWV207REG_PA_CLIP_CONTROL_CLIP_FAR_Z_DISABLED                      0x1


#define MWV207REG_PA_CLIP_CONTROL_ADJUST_FAR_Z                             25:25
#define MWV207REG_PA_CLIP_CONTROL_ADJUST_FAR_Z_End                            25
#define MWV207REG_PA_CLIP_CONTROL_ADJUST_FAR_Z_Start                          25
#define MWV207REG_PA_CLIP_CONTROL_ADJUST_FAR_Z_Type                          U01

#define   MWV207REG_PA_CLIP_CONTROL_ADJUST_FAR_Z_ENABLED                     0x0

#define   MWV207REG_PA_CLIP_CONTROL_ADJUST_FAR_Z_DISABLED                    0x1


#define MWV207REG_PA_CLIP_CONTROL_DENORM                                   28:28
#define MWV207REG_PA_CLIP_CONTROL_DENORM_End                                  28
#define MWV207REG_PA_CLIP_CONTROL_DENORM_Start                                28
#define MWV207REG_PA_CLIP_CONTROL_DENORM_Type                                U01

#define   MWV207REG_PA_CLIP_CONTROL_DENORM_CLAMP_TO_ZERO                     0x0

#define   MWV207REG_PA_CLIP_CONTROL_DENORM_PASS_THROUGH                      0x1


#define MWV207REG_PA_CLIP_CONTROL_ZSCALE                                   30:30
#define MWV207REG_PA_CLIP_CONTROL_ZSCALE_End                                  30
#define MWV207REG_PA_CLIP_CONTROL_ZSCALE_Start                                30
#define MWV207REG_PA_CLIP_CONTROL_ZSCALE_Type                                U01

#define   MWV207REG_PA_CLIP_CONTROL_ZSCALE_SCALE                             0x0

#define   MWV207REG_PA_CLIP_CONTROL_ZSCALE_BYPASS                            0x1




#define mwv207regPASmallWRegAddrs                                         0x02A3
#define MWV207REG_PA_SMALL_W_Address                                     0x00A8C
#define MWV207REG_PA_SMALL_W_MSB                                              15
#define MWV207REG_PA_SMALL_W_LSB                                               0
#define MWV207REG_PA_SMALL_W_BLK                                               0
#define MWV207REG_PA_SMALL_W_Count                                             1
#define MWV207REG_PA_SMALL_W_FieldMask                                0xFFFFFFFF
#define MWV207REG_PA_SMALL_W_ReadMask                                 0xFFFFFFFF
#define MWV207REG_PA_SMALL_W_WriteMask                                0xFFFFFFFF
#define MWV207REG_PA_SMALL_W_ResetValue                               0x00000000

#define MWV207REG_PA_SMALL_W_FP32                                           31:0
#define MWV207REG_PA_SMALL_W_FP32_End                                         31
#define MWV207REG_PA_SMALL_W_FP32_Start                                        0
#define MWV207REG_PA_SMALL_W_FP32_Type                                       U32




#define mwv207regPAPackRegAddrs                                           0x02A4
#define MWV207REG_PA_PACK_Address                                        0x00A90
#define MWV207REG_PA_PACK_MSB                                                 15
#define MWV207REG_PA_PACK_LSB                                                  2
#define MWV207REG_PA_PACK_BLK                                                  2
#define MWV207REG_PA_PACK_Count                                                4
#define MWV207REG_PA_PACK_FieldMask                                   0x77777777
#define MWV207REG_PA_PACK_ReadMask                                    0x77777777
#define MWV207REG_PA_PACK_WriteMask                                   0x77777777
#define MWV207REG_PA_PACK_ResetValue                                  0x00000000

#define MWV207REG_PA_PACK_VARYING0                                           2:0
#define MWV207REG_PA_PACK_VARYING0_End                                         2
#define MWV207REG_PA_PACK_VARYING0_Start                                       0
#define MWV207REG_PA_PACK_VARYING0_Type                                      U03

#define MWV207REG_PA_PACK_VARYING1                                           6:4
#define MWV207REG_PA_PACK_VARYING1_End                                         6
#define MWV207REG_PA_PACK_VARYING1_Start                                       4
#define MWV207REG_PA_PACK_VARYING1_Type                                      U03

#define MWV207REG_PA_PACK_VARYING2                                          10:8
#define MWV207REG_PA_PACK_VARYING2_End                                        10
#define MWV207REG_PA_PACK_VARYING2_Start                                       8
#define MWV207REG_PA_PACK_VARYING2_Type                                      U03

#define MWV207REG_PA_PACK_VARYING3                                         14:12
#define MWV207REG_PA_PACK_VARYING3_End                                        14
#define MWV207REG_PA_PACK_VARYING3_Start                                      12
#define MWV207REG_PA_PACK_VARYING3_Type                                      U03

#define MWV207REG_PA_PACK_VARYING4                                         18:16
#define MWV207REG_PA_PACK_VARYING4_End                                        18
#define MWV207REG_PA_PACK_VARYING4_Start                                      16
#define MWV207REG_PA_PACK_VARYING4_Type                                      U03

#define MWV207REG_PA_PACK_VARYING5                                         22:20
#define MWV207REG_PA_PACK_VARYING5_End                                        22
#define MWV207REG_PA_PACK_VARYING5_Start                                      20
#define MWV207REG_PA_PACK_VARYING5_Type                                      U03

#define MWV207REG_PA_PACK_VARYING6                                         26:24
#define MWV207REG_PA_PACK_VARYING6_End                                        26
#define MWV207REG_PA_PACK_VARYING6_Start                                      24
#define MWV207REG_PA_PACK_VARYING6_Type                                      U03

#define MWV207REG_PA_PACK_VARYING7                                         30:28
#define MWV207REG_PA_PACK_VARYING7_End                                        30
#define MWV207REG_PA_PACK_VARYING7_Start                                      28
#define MWV207REG_PA_PACK_VARYING7_Type                                      U03

#define AQPaWrapRegAddrs                                                  0x02A8
#define AQ_PA_WRAP_Address                                               0x00AA0
#define AQ_PA_WRAP_MSB                                                        15
#define AQ_PA_WRAP_LSB                                                         1
#define AQ_PA_WRAP_BLK                                                         1
#define AQ_PA_WRAP_Count                                                       2
#define AQ_PA_WRAP_FieldMask                                          0xFFFFFFFF
#define AQ_PA_WRAP_ReadMask                                           0xFFFFFFFF
#define AQ_PA_WRAP_WriteMask                                          0xFFFFFFFF
#define AQ_PA_WRAP_ResetValue                                         0x00000000

#define AQ_PA_WRAP_WRAP0                                                     3:0
#define AQ_PA_WRAP_WRAP0_End                                                   3
#define AQ_PA_WRAP_WRAP0_Start                                                 0
#define AQ_PA_WRAP_WRAP0_Type                                                U04
#define   AQ_PA_WRAP_WRAP0_X                                                 0x1
#define   AQ_PA_WRAP_WRAP0_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP0_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP0_W                                                 0x8

#define AQ_PA_WRAP_WRAP1                                                     7:4
#define AQ_PA_WRAP_WRAP1_End                                                   7
#define AQ_PA_WRAP_WRAP1_Start                                                 4
#define AQ_PA_WRAP_WRAP1_Type                                                U04
#define   AQ_PA_WRAP_WRAP1_X                                                 0x1
#define   AQ_PA_WRAP_WRAP1_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP1_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP1_W                                                 0x8

#define AQ_PA_WRAP_WRAP2                                                    11:8
#define AQ_PA_WRAP_WRAP2_End                                                  11
#define AQ_PA_WRAP_WRAP2_Start                                                 8
#define AQ_PA_WRAP_WRAP2_Type                                                U04
#define   AQ_PA_WRAP_WRAP2_X                                                 0x1
#define   AQ_PA_WRAP_WRAP2_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP2_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP2_W                                                 0x8

#define AQ_PA_WRAP_WRAP3                                                   15:12
#define AQ_PA_WRAP_WRAP3_End                                                  15
#define AQ_PA_WRAP_WRAP3_Start                                                12
#define AQ_PA_WRAP_WRAP3_Type                                                U04
#define   AQ_PA_WRAP_WRAP3_X                                                 0x1
#define   AQ_PA_WRAP_WRAP3_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP3_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP3_W                                                 0x8

#define AQ_PA_WRAP_WRAP4                                                   19:16
#define AQ_PA_WRAP_WRAP4_End                                                  19
#define AQ_PA_WRAP_WRAP4_Start                                                16
#define AQ_PA_WRAP_WRAP4_Type                                                U04
#define   AQ_PA_WRAP_WRAP4_X                                                 0x1
#define   AQ_PA_WRAP_WRAP4_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP4_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP4_W                                                 0x8

#define AQ_PA_WRAP_WRAP5                                                   23:20
#define AQ_PA_WRAP_WRAP5_End                                                  23
#define AQ_PA_WRAP_WRAP5_Start                                                20
#define AQ_PA_WRAP_WRAP5_Type                                                U04
#define   AQ_PA_WRAP_WRAP5_X                                                 0x1
#define   AQ_PA_WRAP_WRAP5_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP5_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP5_W                                                 0x8

#define AQ_PA_WRAP_WRAP6                                                   27:24
#define AQ_PA_WRAP_WRAP6_End                                                  27
#define AQ_PA_WRAP_WRAP6_Start                                                24
#define AQ_PA_WRAP_WRAP6_Type                                                U04
#define   AQ_PA_WRAP_WRAP6_X                                                 0x1
#define   AQ_PA_WRAP_WRAP6_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP6_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP6_W                                                 0x8

#define AQ_PA_WRAP_WRAP7                                                   31:28
#define AQ_PA_WRAP_WRAP7_End                                                  31
#define AQ_PA_WRAP_WRAP7_Start                                                28
#define AQ_PA_WRAP_WRAP7_Type                                                U04
#define   AQ_PA_WRAP_WRAP7_X                                                 0x1
#define   AQ_PA_WRAP_WRAP7_Y                                                 0x2
#define   AQ_PA_WRAP_WRAP7_Z                                                 0x4
#define   AQ_PA_WRAP_WRAP7_W                                                 0x8




#define mwv207regPAControlRegAddrs                                        0x02AA
#define MWV207REG_PA_CONTROL_Address                                     0x00AA8
#define MWV207REG_PA_CONTROL_MSB                                              15
#define MWV207REG_PA_CONTROL_LSB                                               0
#define MWV207REG_PA_CONTROL_BLK                                               0
#define MWV207REG_PA_CONTROL_Count                                             1
#define MWV207REG_PA_CONTROL_FieldMask                                0x0000033F
#define MWV207REG_PA_CONTROL_ReadMask                                 0x0000033F
#define MWV207REG_PA_CONTROL_WriteMask                                0x0000033F
#define MWV207REG_PA_CONTROL_ResetValue                               0x00000000


#define MWV207REG_PA_CONTROL_OUTPUT_COUNT                                    5:0
#define MWV207REG_PA_CONTROL_OUTPUT_COUNT_End                                  5
#define MWV207REG_PA_CONTROL_OUTPUT_COUNT_Start                                0
#define MWV207REG_PA_CONTROL_OUTPUT_COUNT_Type                               U06


#define MWV207REG_PA_CONTROL_SKIP_LAST_ATTRIBUTE                             8:8
#define MWV207REG_PA_CONTROL_SKIP_LAST_ATTRIBUTE_End                           8
#define MWV207REG_PA_CONTROL_SKIP_LAST_ATTRIBUTE_Start                         8
#define MWV207REG_PA_CONTROL_SKIP_LAST_ATTRIBUTE_Type                        U01


#define MWV207REG_PA_CONTROL_BYPASS_AA_LINE_FIX                              9:9
#define MWV207REG_PA_CONTROL_BYPASS_AA_LINE_FIX_End                            9
#define MWV207REG_PA_CONTROL_BYPASS_AA_LINE_FIX_Start                          9
#define MWV207REG_PA_CONTROL_BYPASS_AA_LINE_FIX_Type                         U01
#define   MWV207REG_PA_CONTROL_BYPASS_AA_LINE_FIX_DISABLE                    0x0
#define   MWV207REG_PA_CONTROL_BYPASS_AA_LINE_FIX_ENABLE                     0x1




#define mwv207regFinalPAControlRegAddrs                                   0x02AB
#define MWV207REG_FINAL_PA_CONTROL_Address                               0x00AAC
#define MWV207REG_FINAL_PA_CONTROL_MSB                                        15
#define MWV207REG_FINAL_PA_CONTROL_LSB                                         0
#define MWV207REG_FINAL_PA_CONTROL_BLK                                         0
#define MWV207REG_FINAL_PA_CONTROL_Count                                       1
#define MWV207REG_FINAL_PA_CONTROL_FieldMask                          0x000001FF
#define MWV207REG_FINAL_PA_CONTROL_ReadMask                           0x000001FF
#define MWV207REG_FINAL_PA_CONTROL_WriteMask                          0x000001FF
#define MWV207REG_FINAL_PA_CONTROL_ResetValue                         0x00000000


#define MWV207REG_FINAL_PA_CONTROL_INPUT_FIFO_DEPTH                          8:0
#define MWV207REG_FINAL_PA_CONTROL_INPUT_FIFO_DEPTH_End                        8
#define MWV207REG_FINAL_PA_CONTROL_INPUT_FIFO_DEPTH_Start                      0
#define MWV207REG_FINAL_PA_CONTROL_INPUT_FIFO_DEPTH_Type                     U09

#define mwv207regPAControlExRegAddrs                                      0x02AC
#define MWV207REG_PA_CONTROL_EX_Address                                  0x00AB0
#define MWV207REG_PA_CONTROL_EX_MSB                                           15
#define MWV207REG_PA_CONTROL_EX_LSB                                            0
#define MWV207REG_PA_CONTROL_EX_BLK                                            0
#define MWV207REG_PA_CONTROL_EX_Count                                          1
#define MWV207REG_PA_CONTROL_EX_FieldMask                             0x0000007F
#define MWV207REG_PA_CONTROL_EX_ReadMask                              0x0000007F
#define MWV207REG_PA_CONTROL_EX_WriteMask                             0x0000007F
#define MWV207REG_PA_CONTROL_EX_ResetValue                            0x00000000


#define MWV207REG_PA_CONTROL_EX_FRONT_FACE                                   0:0
#define MWV207REG_PA_CONTROL_EX_FRONT_FACE_End                                 0
#define MWV207REG_PA_CONTROL_EX_FRONT_FACE_Start                               0
#define MWV207REG_PA_CONTROL_EX_FRONT_FACE_Type                              U01
#define   MWV207REG_PA_CONTROL_EX_FRONT_FACE_CW                              0x0
#define   MWV207REG_PA_CONTROL_EX_FRONT_FACE_CCW                             0x1


#define MWV207REG_PA_CONTROL_EX_MASK_FRONT_FACE                              1:1
#define MWV207REG_PA_CONTROL_EX_MASK_FRONT_FACE_End                            1
#define MWV207REG_PA_CONTROL_EX_MASK_FRONT_FACE_Start                          1
#define MWV207REG_PA_CONTROL_EX_MASK_FRONT_FACE_Type                         U01
#define   MWV207REG_PA_CONTROL_EX_MASK_FRONT_FACE_ENABLED                    0x0
#define   MWV207REG_PA_CONTROL_EX_MASK_FRONT_FACE_MASKED                     0x1


#define MWV207REG_PA_CONTROL_EX_PPA2_LINE_CACHE                              2:2
#define MWV207REG_PA_CONTROL_EX_PPA2_LINE_CACHE_End                            2
#define MWV207REG_PA_CONTROL_EX_PPA2_LINE_CACHE_Start                          2
#define MWV207REG_PA_CONTROL_EX_PPA2_LINE_CACHE_Type                         U01
#define   MWV207REG_PA_CONTROL_EX_PPA2_LINE_CACHE_ENABLED                    0x0
#define   MWV207REG_PA_CONTROL_EX_PPA2_LINE_CACHE_DISABLED                   0x1


#define MWV207REG_PA_CONTROL_EX_MASK_PPA2_LINE_CACHE                         3:3
#define MWV207REG_PA_CONTROL_EX_MASK_PPA2_LINE_CACHE_End                       3
#define MWV207REG_PA_CONTROL_EX_MASK_PPA2_LINE_CACHE_Start                     3
#define MWV207REG_PA_CONTROL_EX_MASK_PPA2_LINE_CACHE_Type                    U01
#define   MWV207REG_PA_CONTROL_EX_MASK_PPA2_LINE_CACHE_ENABLED               0x0
#define   MWV207REG_PA_CONTROL_EX_MASK_PPA2_LINE_CACHE_MASKED                0x1


#define MWV207REG_PA_CONTROL_EX_SEPARATE_FILL_MODE                           4:4
#define MWV207REG_PA_CONTROL_EX_SEPARATE_FILL_MODE_End                         4
#define MWV207REG_PA_CONTROL_EX_SEPARATE_FILL_MODE_Start                       4
#define MWV207REG_PA_CONTROL_EX_SEPARATE_FILL_MODE_Type                      U01
#define   MWV207REG_PA_CONTROL_EX_SEPARATE_FILL_MODE_ENABLED                 0x0
#define   MWV207REG_PA_CONTROL_EX_SEPARATE_FILL_MODE_DISABLED                0x1


#define MWV207REG_PA_CONTROL_EX_BACK_FACE_FILL_MODE                          6:5
#define MWV207REG_PA_CONTROL_EX_BACK_FACE_FILL_MODE_End                        6
#define MWV207REG_PA_CONTROL_EX_BACK_FACE_FILL_MODE_Start                      5
#define MWV207REG_PA_CONTROL_EX_BACK_FACE_FILL_MODE_Type                     U02
#define   MWV207REG_PA_CONTROL_EX_BACK_FACE_FILL_MODE_POINT                  0x0
#define   MWV207REG_PA_CONTROL_EX_BACK_FACE_FILL_MODE_WIREFRAME              0x1
#define   MWV207REG_PA_CONTROL_EX_BACK_FACE_FILL_MODE_SOLID                  0x2

#define mwv207regPosPAClusterCtrlRegAddrs                                 0x02AD
#define MWV207REG_POS_PA_CLUSTER_CTRL_Address                            0x00AB4
#define MWV207REG_POS_PA_CLUSTER_CTRL_MSB                                     15
#define MWV207REG_POS_PA_CLUSTER_CTRL_LSB                                      0
#define MWV207REG_POS_PA_CLUSTER_CTRL_BLK                                      0
#define MWV207REG_POS_PA_CLUSTER_CTRL_Count                                    1
#define MWV207REG_POS_PA_CLUSTER_CTRL_FieldMask                       0x000000FF
#define MWV207REG_POS_PA_CLUSTER_CTRL_ReadMask                        0x000000FF
#define MWV207REG_POS_PA_CLUSTER_CTRL_WriteMask                       0x000000FF
#define MWV207REG_POS_PA_CLUSTER_CTRL_ResetValue                      0x000000FF


#define MWV207REG_POS_PA_CLUSTER_CTRL_CLUSTER_ALIVE                          7:0
#define MWV207REG_POS_PA_CLUSTER_CTRL_CLUSTER_ALIVE_End                        7
#define MWV207REG_POS_PA_CLUSTER_CTRL_CLUSTER_ALIVE_Start                      0
#define MWV207REG_POS_PA_CLUSTER_CTRL_CLUSTER_ALIVE_Type                     U08



#define mwv207regPADebugModeRegAddrs                                      0x02AE
#define MWV207REG_PA_DEBUG_MODE_Address                                  0x00AB8
#define MWV207REG_PA_DEBUG_MODE_MSB                                           15
#define MWV207REG_PA_DEBUG_MODE_LSB                                            0
#define MWV207REG_PA_DEBUG_MODE_BLK                                            0
#define MWV207REG_PA_DEBUG_MODE_Count                                          1
#define MWV207REG_PA_DEBUG_MODE_FieldMask                             0x0000FFFF
#define MWV207REG_PA_DEBUG_MODE_ReadMask                              0x0000FFFF
#define MWV207REG_PA_DEBUG_MODE_WriteMask                             0x0000FFFF
#define MWV207REG_PA_DEBUG_MODE_ResetValue                            0x00000000


#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_ENABLE                         0:0
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_ENABLE_End                       0
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_ENABLE_Start                     0
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_ENABLE_Type                    U01
#define   MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_ENABLE_MASKED                0x0
#define   MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_ENABLE_ENABLED               0x1


#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_GPUID                          3:1
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_GPUID_End                        3
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_GPUID_Start                      1
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_GPUID_Type                     U03

#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_TOTAL_CLUSTER_ALIVE            9:4
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_TOTAL_CLUSTER_ALIVE_End          9
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_TOTAL_CLUSTER_ALIVE_Start        4
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_TOTAL_CLUSTER_ALIVE_Type       U06


#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_PREVIOUS_CLUSTER_ALIVE       15:10
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_PREVIOUS_CLUSTER_ALIVE_End      15
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_PREVIOUS_CLUSTER_ALIVE_Start    10
#define MWV207REG_PA_DEBUG_MODE_PA_DEBUG_MODE_PREVIOUS_CLUSTER_ALIVE_Type    U06


#define mwv207regViewportXScaleExRegAddrs                                 0x7A00
#define MWV207REG_VIEWPORT_XSCALE_EX_Address                             0x1E800
#define MWV207REG_VIEWPORT_XSCALE_EX_MSB                                      15
#define MWV207REG_VIEWPORT_XSCALE_EX_LSB                                       4
#define MWV207REG_VIEWPORT_XSCALE_EX_BLK                                       4
#define MWV207REG_VIEWPORT_XSCALE_EX_Count                                    16
#define MWV207REG_VIEWPORT_XSCALE_EX_FieldMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_XSCALE_EX_ReadMask                         0xFFFFFFFF
#define MWV207REG_VIEWPORT_XSCALE_EX_WriteMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_XSCALE_EX_ResetValue                       0x00000000


#define MWV207REG_VIEWPORT_XSCALE_EX_SCALE                                  31:0
#define MWV207REG_VIEWPORT_XSCALE_EX_SCALE_End                                31
#define MWV207REG_VIEWPORT_XSCALE_EX_SCALE_Start                               0
#define MWV207REG_VIEWPORT_XSCALE_EX_SCALE_Type                              U32

#define mwv207regViewportYScaleExRegAddrs                                 0x7A10
#define MWV207REG_VIEWPORT_YSCALE_EX_Address                             0x1E840
#define MWV207REG_VIEWPORT_YSCALE_EX_MSB                                      15
#define MWV207REG_VIEWPORT_YSCALE_EX_LSB                                       4
#define MWV207REG_VIEWPORT_YSCALE_EX_BLK                                       4
#define MWV207REG_VIEWPORT_YSCALE_EX_Count                                    16
#define MWV207REG_VIEWPORT_YSCALE_EX_FieldMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_YSCALE_EX_ReadMask                         0xFFFFFFFF
#define MWV207REG_VIEWPORT_YSCALE_EX_WriteMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_YSCALE_EX_ResetValue                       0x00000000


#define MWV207REG_VIEWPORT_YSCALE_EX_SCALE                                  31:0
#define MWV207REG_VIEWPORT_YSCALE_EX_SCALE_End                                31
#define MWV207REG_VIEWPORT_YSCALE_EX_SCALE_Start                               0
#define MWV207REG_VIEWPORT_YSCALE_EX_SCALE_Type                              U32

#define mwv207regViewportZScaleExRegAddrs                                 0x7A20
#define MWV207REG_VIEWPORT_ZSCALE_EX_Address                             0x1E880
#define MWV207REG_VIEWPORT_ZSCALE_EX_MSB                                      15
#define MWV207REG_VIEWPORT_ZSCALE_EX_LSB                                       4
#define MWV207REG_VIEWPORT_ZSCALE_EX_BLK                                       4
#define MWV207REG_VIEWPORT_ZSCALE_EX_Count                                    16
#define MWV207REG_VIEWPORT_ZSCALE_EX_FieldMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_ZSCALE_EX_ReadMask                         0xFFFFFFFF
#define MWV207REG_VIEWPORT_ZSCALE_EX_WriteMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_ZSCALE_EX_ResetValue                       0x00000000


#define MWV207REG_VIEWPORT_ZSCALE_EX_SCALE                                  31:0
#define MWV207REG_VIEWPORT_ZSCALE_EX_SCALE_End                                31
#define MWV207REG_VIEWPORT_ZSCALE_EX_SCALE_Start                               0
#define MWV207REG_VIEWPORT_ZSCALE_EX_SCALE_Type                              U32

#define mwv207regViewportXOffsetExRegAddrs                                0x7A30
#define MWV207REG_VIEWPORT_XOFFSET_EX_Address                            0x1E8C0
#define MWV207REG_VIEWPORT_XOFFSET_EX_MSB                                     15
#define MWV207REG_VIEWPORT_XOFFSET_EX_LSB                                      4
#define MWV207REG_VIEWPORT_XOFFSET_EX_BLK                                      4
#define MWV207REG_VIEWPORT_XOFFSET_EX_Count                                   16
#define MWV207REG_VIEWPORT_XOFFSET_EX_FieldMask                       0xFFFFFFFF
#define MWV207REG_VIEWPORT_XOFFSET_EX_ReadMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_XOFFSET_EX_WriteMask                       0xFFFFFFFF
#define MWV207REG_VIEWPORT_XOFFSET_EX_ResetValue                      0x00000000


#define MWV207REG_VIEWPORT_XOFFSET_EX_OFFSET                                31:0
#define MWV207REG_VIEWPORT_XOFFSET_EX_OFFSET_End                              31
#define MWV207REG_VIEWPORT_XOFFSET_EX_OFFSET_Start                             0
#define MWV207REG_VIEWPORT_XOFFSET_EX_OFFSET_Type                            U32

#define mwv207regViewportYOffsetExRegAddrs                                0x7A40
#define MWV207REG_VIEWPORT_YOFFSET_EX_Address                            0x1E900
#define MWV207REG_VIEWPORT_YOFFSET_EX_MSB                                     15
#define MWV207REG_VIEWPORT_YOFFSET_EX_LSB                                      4
#define MWV207REG_VIEWPORT_YOFFSET_EX_BLK                                      4
#define MWV207REG_VIEWPORT_YOFFSET_EX_Count                                   16
#define MWV207REG_VIEWPORT_YOFFSET_EX_FieldMask                       0xFFFFFFFF
#define MWV207REG_VIEWPORT_YOFFSET_EX_ReadMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_YOFFSET_EX_WriteMask                       0xFFFFFFFF
#define MWV207REG_VIEWPORT_YOFFSET_EX_ResetValue                      0x00000000


#define MWV207REG_VIEWPORT_YOFFSET_EX_OFFSET                                31:0
#define MWV207REG_VIEWPORT_YOFFSET_EX_OFFSET_End                              31
#define MWV207REG_VIEWPORT_YOFFSET_EX_OFFSET_Start                             0
#define MWV207REG_VIEWPORT_YOFFSET_EX_OFFSET_Type                            U32

#define mwv207regViewportZOffsetExRegAddrs                                0x7A50
#define MWV207REG_VIEWPORT_ZOFFSET_EX_Address                            0x1E940
#define MWV207REG_VIEWPORT_ZOFFSET_EX_MSB                                     15
#define MWV207REG_VIEWPORT_ZOFFSET_EX_LSB                                      4
#define MWV207REG_VIEWPORT_ZOFFSET_EX_BLK                                      4
#define MWV207REG_VIEWPORT_ZOFFSET_EX_Count                                   16
#define MWV207REG_VIEWPORT_ZOFFSET_EX_FieldMask                       0xFFFFFFFF
#define MWV207REG_VIEWPORT_ZOFFSET_EX_ReadMask                        0xFFFFFFFF
#define MWV207REG_VIEWPORT_ZOFFSET_EX_WriteMask                       0xFFFFFFFF
#define MWV207REG_VIEWPORT_ZOFFSET_EX_ResetValue                      0x00000000


#define MWV207REG_VIEWPORT_ZOFFSET_EX_OFFSET                                31:0
#define MWV207REG_VIEWPORT_ZOFFSET_EX_OFFSET_End                              31
#define MWV207REG_VIEWPORT_ZOFFSET_EX_OFFSET_Start                             0
#define MWV207REG_VIEWPORT_ZOFFSET_EX_OFFSET_Type                            U32




#define mwv207regPAClipWExRegAddrs                                        0x7A60
#define MWV207REG_PA_CLIP_WEX_Address                                    0x1E980
#define MWV207REG_PA_CLIP_WEX_MSB                                             15
#define MWV207REG_PA_CLIP_WEX_LSB                                              4
#define MWV207REG_PA_CLIP_WEX_BLK                                              4
#define MWV207REG_PA_CLIP_WEX_Count                                           16
#define MWV207REG_PA_CLIP_WEX_FieldMask                               0xFFFFFFFF
#define MWV207REG_PA_CLIP_WEX_ReadMask                                0xFFFFFFFF
#define MWV207REG_PA_CLIP_WEX_WriteMask                               0xFFFFFFFF
#define MWV207REG_PA_CLIP_WEX_ResetValue                              0x00000000

#define MWV207REG_PA_CLIP_WEX_FL32                                          31:0
#define MWV207REG_PA_CLIP_WEX_FL32_End                                        31
#define MWV207REG_PA_CLIP_WEX_FL32_Start                                       0
#define MWV207REG_PA_CLIP_WEX_FL32_Type                                      U32


#define   AQPA_XY_CLAMP_MIN                                           0xCAFFFFFE
#define   AQPA_XY_CLAMP_MAX                                           0x4AFFFFFE

#define   AQPA_DEFAULT_STATE_LINE_WIDTH_SCALE                         0x3F400000
#define   AQPA_DEFAULT_STATE_XSCALE                                   0x43200000
#define   AQPA_DEFAULT_STATE_YSCALE                                   0xC2F00000
#define   AQPA_DEFAULT_STATE_ZSCALE                                   0x3F800000
#define   AQPA_DEFAULT_STATE_XOFFSET                                  0x43200000
#define   AQPA_DEFAULT_STATE_YOFFSET                                  0x42F00000
#define   AQPA_DEFAULT_STATE_ZOFFSET                                  0x00000000
#define   AQPA_DEFAULT_STATE_PNT_SIZE_DIV_BY2                         0x3F000000
#define   AQPA_DEFAULT_STATE_FILLMODE                                 0x00000002
#define   AQPA_DEFAULT_STATE_ELEMENT_NUM                              0x00000001
#define   AQPA_DEFAULT_STATE_W_LIMIT                                  0x3E000000


#endif


