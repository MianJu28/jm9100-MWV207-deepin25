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




#ifndef __jmgpuregTensorTransfDMA_h__
#define __jmgpuregTensorTransfDMA_h__


#define mwv207regTTDMiscRegAddrs                                          0x5FB0
#define MWV207REG_TTD_MISC_Address                                       0x17EC0
#define MWV207REG_TTD_MISC_MSB                                                15
#define MWV207REG_TTD_MISC_LSB                                                 0
#define MWV207REG_TTD_MISC_BLK                                                 0
#define MWV207REG_TTD_MISC_Count                                               1
#define MWV207REG_TTD_MISC_FieldMask                                  0x0007FFFF
#define MWV207REG_TTD_MISC_ReadMask                                   0x0007FFFF
#define MWV207REG_TTD_MISC_WriteMask                                  0x0007FFFF
#define MWV207REG_TTD_MISC_ResetValue                                 0x00000000

#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED                           0:0
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_End                         0
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_Start                       0
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_Type                      U01

#define MWV207REG_TTD_MISC_VIP_SOFTWARE_FRAME_START                          1:1
#define MWV207REG_TTD_MISC_VIP_SOFTWARE_FRAME_START_End                        1
#define MWV207REG_TTD_MISC_VIP_SOFTWARE_FRAME_START_Start                      1
#define MWV207REG_TTD_MISC_VIP_SOFTWARE_FRAME_START_Type                     U01


#define MWV207REG_TTD_MISC_DENOISE_POST_PROCESS_BYPASS                       2:2
#define MWV207REG_TTD_MISC_DENOISE_POST_PROCESS_BYPASS_End                     2
#define MWV207REG_TTD_MISC_DENOISE_POST_PROCESS_BYPASS_Start                   2
#define MWV207REG_TTD_MISC_DENOISE_POST_PROCESS_BYPASS_Type                  U01

#define MWV207REG_TTD_MISC_OCM_BYPASS                                        3:3
#define MWV207REG_TTD_MISC_OCM_BYPASS_End                                      3
#define MWV207REG_TTD_MISC_OCM_BYPASS_Start                                    3
#define MWV207REG_TTD_MISC_OCM_BYPASS_Type                                   U01

#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED                              4:4
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_End                            4
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_Start                          4
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_Type                         U01

#define MWV207REG_TTD_MISC_XSOFTWARE_FRAME_START                             5:5
#define MWV207REG_TTD_MISC_XSOFTWARE_FRAME_START_End                           5
#define MWV207REG_TTD_MISC_XSOFTWARE_FRAME_START_Start                         5
#define MWV207REG_TTD_MISC_XSOFTWARE_FRAME_START_Type                        U01

#define MWV207REG_TTD_MISC_ISP_SHADOW_REG_PREPARED                           6:6
#define MWV207REG_TTD_MISC_ISP_SHADOW_REG_PREPARED_End                         6
#define MWV207REG_TTD_MISC_ISP_SHADOW_REG_PREPARED_Start                       6
#define MWV207REG_TTD_MISC_ISP_SHADOW_REG_PREPARED_Type                      U01

#define MWV207REG_TTD_MISC_ISP_SOFTWARE_FRAME_START                          7:7
#define MWV207REG_TTD_MISC_ISP_SOFTWARE_FRAME_START_End                        7
#define MWV207REG_TTD_MISC_ISP_SOFTWARE_FRAME_START_Start                      7
#define MWV207REG_TTD_MISC_ISP_SOFTWARE_FRAME_START_Type                     U01

#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0                      8:8
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0_End                    8
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0_Start                  8
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA0_Type                 U01

#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1                      9:9
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1_End                    9
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1_Start                  9
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA1_Type                 U01

#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2                    10:10
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2_End                   10
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2_Start                 10
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA2_Type                 U01

#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3                    11:11
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3_End                   11
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3_Start                 11
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA3_Type                 U01

#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4                    12:12
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4_End                   12
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4_Start                 12
#define MWV207REG_TTD_MISC_VIP_SHADOW_REG_PREPARED_DMA4_Type                 U01

#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA5                       13:13
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA5_End                      13
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA5_Start                    13
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA5_Type                    U01

#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA6                       14:14
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA6_End                      14
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA6_Start                    14
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA6_Type                    U01

#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA7                       15:15
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA7_End                      15
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA7_Start                    15
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA7_Type                    U01

#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA8                       16:16
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA8_End                      16
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA8_Start                    16
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA8_Type                    U01

#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA9                       17:17
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA9_End                      17
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA9_Start                    17
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA9_Type                    U01

#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA10                      18:18
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA10_End                     18
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA10_Start                   18
#define MWV207REG_TTD_MISC_XSHADOW_REG_PREPARED_DMA10_Type                   U01




#define mwv207regCompressorRegAddrs                                       0x5FB1
#define MWV207REG_COMPRESSOR_Address                                     0x17EC4
#define MWV207REG_COMPRESSOR_MSB                                              15
#define MWV207REG_COMPRESSOR_LSB                                               0
#define MWV207REG_COMPRESSOR_BLK                                               0
#define MWV207REG_COMPRESSOR_Count                                             1
#define MWV207REG_COMPRESSOR_FieldMask                                0x0FFFFFFF
#define MWV207REG_COMPRESSOR_ReadMask                                 0x0FFFFFFF
#define MWV207REG_COMPRESSOR_WriteMask                                0x0FFFFFFF
#define MWV207REG_COMPRESSOR_ResetValue                               0x04000000


#define MWV207REG_COMPRESSOR_UNCOMPRESSED_MODE                               0:0
#define MWV207REG_COMPRESSOR_UNCOMPRESSED_MODE_End                             0
#define MWV207REG_COMPRESSOR_UNCOMPRESSED_MODE_Start                           0
#define MWV207REG_COMPRESSOR_UNCOMPRESSED_MODE_Type                          U01
#define   MWV207REG_COMPRESSOR_UNCOMPRESSED_MODE_COMPRESSED                  0x0
#define   MWV207REG_COMPRESSOR_UNCOMPRESSED_MODE_UNCOMPRESSED                0x1


#define MWV207REG_COMPRESSOR_SOFT_CLEAR                                      1:1
#define MWV207REG_COMPRESSOR_SOFT_CLEAR_End                                    1
#define MWV207REG_COMPRESSOR_SOFT_CLEAR_Start                                  1
#define MWV207REG_COMPRESSOR_SOFT_CLEAR_Type                                 U01

#define MWV207REG_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS                          9:2
#define MWV207REG_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS_End                        9
#define MWV207REG_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Start                      2
#define MWV207REG_COMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Type                     U08


#define MWV207REG_COMPRESSOR_FRAME_HEIGHT                                  23:10
#define MWV207REG_COMPRESSOR_FRAME_HEIGHT_End                                 23
#define MWV207REG_COMPRESSOR_FRAME_HEIGHT_Start                               10
#define MWV207REG_COMPRESSOR_FRAME_HEIGHT_Type                               U14


#define MWV207REG_COMPRESSOR_CFG_BAYER_MODE                                25:24
#define MWV207REG_COMPRESSOR_CFG_BAYER_MODE_End                               25
#define MWV207REG_COMPRESSOR_CFG_BAYER_MODE_Start                             24
#define MWV207REG_COMPRESSOR_CFG_BAYER_MODE_Type                             U02
#define   MWV207REG_COMPRESSOR_CFG_BAYER_MODE_RGGB                           0x0
#define   MWV207REG_COMPRESSOR_CFG_BAYER_MODE_GRBG                           0x1
#define   MWV207REG_COMPRESSOR_CFG_BAYER_MODE_GBRG                           0x2
#define   MWV207REG_COMPRESSOR_CFG_BAYER_MODE_BGGR                           0x3


#define MWV207REG_COMPRESSOR_CFG_RATIO                                     27:26
#define MWV207REG_COMPRESSOR_CFG_RATIO_End                                    27
#define MWV207REG_COMPRESSOR_CFG_RATIO_Start                                  26
#define MWV207REG_COMPRESSOR_CFG_RATIO_Type                                  U02
#define   MWV207REG_COMPRESSOR_CFG_RATIO_SIXTEEN_DIV_EIGHT                   0x0
#define   MWV207REG_COMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TEN                     0x1
#define   MWV207REG_COMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TWELVE                  0x2




#define mwv207regDecompressorRegAddrs                                     0x5FB2
#define MWV207REG_DECOMPRESSOR_Address                                   0x17EC8
#define MWV207REG_DECOMPRESSOR_MSB                                            15
#define MWV207REG_DECOMPRESSOR_LSB                                             0
#define MWV207REG_DECOMPRESSOR_BLK                                             0
#define MWV207REG_DECOMPRESSOR_Count                                           1
#define MWV207REG_DECOMPRESSOR_FieldMask                              0x0FFFFFFF
#define MWV207REG_DECOMPRESSOR_ReadMask                               0x0FFFFFFF
#define MWV207REG_DECOMPRESSOR_WriteMask                              0x0FFFFFFF
#define MWV207REG_DECOMPRESSOR_ResetValue                             0x04000000


#define MWV207REG_DECOMPRESSOR_UNCOMPRESSED_MODE                             0:0
#define MWV207REG_DECOMPRESSOR_UNCOMPRESSED_MODE_End                           0
#define MWV207REG_DECOMPRESSOR_UNCOMPRESSED_MODE_Start                         0
#define MWV207REG_DECOMPRESSOR_UNCOMPRESSED_MODE_Type                        U01
#define   MWV207REG_DECOMPRESSOR_UNCOMPRESSED_MODE_COMPRESSED                0x0
#define   MWV207REG_DECOMPRESSOR_UNCOMPRESSED_MODE_UNCOMPRESSED              0x1


#define MWV207REG_DECOMPRESSOR_SOFT_CLEAR                                    1:1
#define MWV207REG_DECOMPRESSOR_SOFT_CLEAR_End                                  1
#define MWV207REG_DECOMPRESSOR_SOFT_CLEAR_Start                                1
#define MWV207REG_DECOMPRESSOR_SOFT_CLEAR_Type                               U01

#define MWV207REG_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS                        9:2
#define MWV207REG_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS_End                      9
#define MWV207REG_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Start                    2
#define MWV207REG_DECOMPRESSOR_FRAME_WIDTH_HIGH8_BITS_Type                   U08


#define MWV207REG_DECOMPRESSOR_FRAME_HEIGHT                                23:10
#define MWV207REG_DECOMPRESSOR_FRAME_HEIGHT_End                               23
#define MWV207REG_DECOMPRESSOR_FRAME_HEIGHT_Start                             10
#define MWV207REG_DECOMPRESSOR_FRAME_HEIGHT_Type                             U14


#define MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE                              25:24
#define MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE_End                             25
#define MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE_Start                           24
#define MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE_Type                           U02
#define   MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE_RGGB                         0x0
#define   MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE_GRBG                         0x1
#define   MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE_GBRG                         0x2
#define   MWV207REG_DECOMPRESSOR_CFG_BAYER_MODE_BGGR                         0x3


#define MWV207REG_DECOMPRESSOR_CFG_RATIO                                   27:26
#define MWV207REG_DECOMPRESSOR_CFG_RATIO_End                                  27
#define MWV207REG_DECOMPRESSOR_CFG_RATIO_Start                                26
#define MWV207REG_DECOMPRESSOR_CFG_RATIO_Type                                U02
#define   MWV207REG_DECOMPRESSOR_CFG_RATIO_SIXTEEN_DIV_EIGHT                 0x0
#define   MWV207REG_DECOMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TEN                   0x1
#define   MWV207REG_DECOMPRESSOR_CFG_RATIO_SIXTEEN_DIV_TWELVE                0x2



#define mwv207regVIPTensorIoRegAddrs                                      0x5FB3
#define MWV207REG_VIP_TENSOR_IO_Address                                  0x17ECC
#define MWV207REG_VIP_TENSOR_IO_MSB                                           15
#define MWV207REG_VIP_TENSOR_IO_LSB                                            0
#define MWV207REG_VIP_TENSOR_IO_BLK                                            0
#define MWV207REG_VIP_TENSOR_IO_Count                                          1
#define MWV207REG_VIP_TENSOR_IO_FieldMask                             0x0000FFFF
#define MWV207REG_VIP_TENSOR_IO_ReadMask                              0x0000FFFF
#define MWV207REG_VIP_TENSOR_IO_WriteMask                             0x0000FFFF
#define MWV207REG_VIP_TENSOR_IO_ResetValue                            0x00000000

#define MWV207REG_VIP_TENSOR_IO_ADDRESS                                     15:0
#define MWV207REG_VIP_TENSOR_IO_ADDRESS_End                                   15
#define MWV207REG_VIP_TENSOR_IO_ADDRESS_Start                                  0
#define MWV207REG_VIP_TENSOR_IO_ADDRESS_Type                                 U16



#define mwv207regVIPTensorIoWrRegAddrs                                    0x5FB4
#define MWV207REG_VIP_TENSOR_IO_WR_Address                               0x17ED0
#define MWV207REG_VIP_TENSOR_IO_WR_MSB                                        15
#define MWV207REG_VIP_TENSOR_IO_WR_LSB                                         0
#define MWV207REG_VIP_TENSOR_IO_WR_BLK                                         0
#define MWV207REG_VIP_TENSOR_IO_WR_Count                                       1
#define MWV207REG_VIP_TENSOR_IO_WR_FieldMask                          0xFFFFFFFF
#define MWV207REG_VIP_TENSOR_IO_WR_ReadMask                           0xFFFFFFFF
#define MWV207REG_VIP_TENSOR_IO_WR_WriteMask                          0xFFFFFFFF
#define MWV207REG_VIP_TENSOR_IO_WR_ResetValue                         0x00000000

#define MWV207REG_VIP_TENSOR_IO_WR_DATA                                     31:0
#define MWV207REG_VIP_TENSOR_IO_WR_DATA_End                                   31
#define MWV207REG_VIP_TENSOR_IO_WR_DATA_Start                                  0
#define MWV207REG_VIP_TENSOR_IO_WR_DATA_Type                                 U32




#define mwv207regPtnGenBayerImageRegAddrs                                 0x5FB5
#define MWV207REG_PTN_GEN_BAYER_IMAGE_Address                            0x17ED4
#define MWV207REG_PTN_GEN_BAYER_IMAGE_MSB                                     15
#define MWV207REG_PTN_GEN_BAYER_IMAGE_LSB                                      0
#define MWV207REG_PTN_GEN_BAYER_IMAGE_BLK                                      0
#define MWV207REG_PTN_GEN_BAYER_IMAGE_Count                                    1
#define MWV207REG_PTN_GEN_BAYER_IMAGE_FieldMask                       0xFFFFFFFF
#define MWV207REG_PTN_GEN_BAYER_IMAGE_ReadMask                        0xFFFFFFFF
#define MWV207REG_PTN_GEN_BAYER_IMAGE_WriteMask                       0xFFFFFFFF
#define MWV207REG_PTN_GEN_BAYER_IMAGE_ResetValue                      0x0C001100


#define MWV207REG_PTN_GEN_BAYER_IMAGE_WIDTH                                 15:0
#define MWV207REG_PTN_GEN_BAYER_IMAGE_WIDTH_End                               15
#define MWV207REG_PTN_GEN_BAYER_IMAGE_WIDTH_Start                              0
#define MWV207REG_PTN_GEN_BAYER_IMAGE_WIDTH_Type                             U16


#define MWV207REG_PTN_GEN_BAYER_IMAGE_HEIGHT                               31:16
#define MWV207REG_PTN_GEN_BAYER_IMAGE_HEIGHT_End                              31
#define MWV207REG_PTN_GEN_BAYER_IMAGE_HEIGHT_Start                            16
#define MWV207REG_PTN_GEN_BAYER_IMAGE_HEIGHT_Type                            U16

#define mwv207regPtnGenRedRegAddrs                                        0x5FB6
#define MWV207REG_PTN_GEN_RED_Address                                    0x17ED8
#define MWV207REG_PTN_GEN_RED_MSB                                             15
#define MWV207REG_PTN_GEN_RED_LSB                                              0
#define MWV207REG_PTN_GEN_RED_BLK                                              0
#define MWV207REG_PTN_GEN_RED_Count                                            1
#define MWV207REG_PTN_GEN_RED_FieldMask                               0xFFFFFFFF
#define MWV207REG_PTN_GEN_RED_ReadMask                                0xFFFFFFFF
#define MWV207REG_PTN_GEN_RED_WriteMask                               0xFFFFFFFF
#define MWV207REG_PTN_GEN_RED_ResetValue                              0x00000000


#define MWV207REG_PTN_GEN_RED_INIT                                          15:0
#define MWV207REG_PTN_GEN_RED_INIT_End                                        15
#define MWV207REG_PTN_GEN_RED_INIT_Start                                       0
#define MWV207REG_PTN_GEN_RED_INIT_Type                                      U16


#define MWV207REG_PTN_GEN_RED_INC_X                                        31:16
#define MWV207REG_PTN_GEN_RED_INC_X_End                                       31
#define MWV207REG_PTN_GEN_RED_INC_X_Start                                     16
#define MWV207REG_PTN_GEN_RED_INC_X_Type                                     U16

#define mwv207regPtnGenGreensRegAddrs                                     0x5FB7
#define MWV207REG_PTN_GEN_GREENS_Address                                 0x17EDC
#define MWV207REG_PTN_GEN_GREENS_MSB                                          15
#define MWV207REG_PTN_GEN_GREENS_LSB                                           0
#define MWV207REG_PTN_GEN_GREENS_BLK                                           0
#define MWV207REG_PTN_GEN_GREENS_Count                                         1
#define MWV207REG_PTN_GEN_GREENS_FieldMask                            0xFFFFFFFF
#define MWV207REG_PTN_GEN_GREENS_ReadMask                             0xFFFFFFFF
#define MWV207REG_PTN_GEN_GREENS_WriteMask                            0xFFFFFFFF
#define MWV207REG_PTN_GEN_GREENS_ResetValue                           0x00000000


#define MWV207REG_PTN_GEN_GREENS_INIT                                       15:0
#define MWV207REG_PTN_GEN_GREENS_INIT_End                                     15
#define MWV207REG_PTN_GEN_GREENS_INIT_Start                                    0
#define MWV207REG_PTN_GEN_GREENS_INIT_Type                                   U16


#define MWV207REG_PTN_GEN_GREENS_INC_X                                     31:16
#define MWV207REG_PTN_GEN_GREENS_INC_X_End                                    31
#define MWV207REG_PTN_GEN_GREENS_INC_X_Start                                  16
#define MWV207REG_PTN_GEN_GREENS_INC_X_Type                                  U16

#define mwv207regPtnGenBlueRegAddrs                                       0x5FB8
#define MWV207REG_PTN_GEN_BLUE_Address                                   0x17EE0
#define MWV207REG_PTN_GEN_BLUE_MSB                                            15
#define MWV207REG_PTN_GEN_BLUE_LSB                                             0
#define MWV207REG_PTN_GEN_BLUE_BLK                                             0
#define MWV207REG_PTN_GEN_BLUE_Count                                           1
#define MWV207REG_PTN_GEN_BLUE_FieldMask                              0xFFFFFFFF
#define MWV207REG_PTN_GEN_BLUE_ReadMask                               0xFFFFFFFF
#define MWV207REG_PTN_GEN_BLUE_WriteMask                              0xFFFFFFFF
#define MWV207REG_PTN_GEN_BLUE_ResetValue                             0x00000000


#define MWV207REG_PTN_GEN_BLUE_INIT                                         15:0
#define MWV207REG_PTN_GEN_BLUE_INIT_End                                       15
#define MWV207REG_PTN_GEN_BLUE_INIT_Start                                      0
#define MWV207REG_PTN_GEN_BLUE_INIT_Type                                     U16


#define MWV207REG_PTN_GEN_BLUE_INC_X                                       31:16
#define MWV207REG_PTN_GEN_BLUE_INC_X_End                                      31
#define MWV207REG_PTN_GEN_BLUE_INC_X_Start                                    16
#define MWV207REG_PTN_GEN_BLUE_INC_X_Type                                    U16




#define mwv207regPtnGenIncY0RegAddrs                                      0x5FB9
#define MWV207REG_PTN_GEN_INC_Y0_Address                                 0x17EE4
#define MWV207REG_PTN_GEN_INC_Y0_MSB                                          15
#define MWV207REG_PTN_GEN_INC_Y0_LSB                                           0
#define MWV207REG_PTN_GEN_INC_Y0_BLK                                           0
#define MWV207REG_PTN_GEN_INC_Y0_Count                                         1
#define MWV207REG_PTN_GEN_INC_Y0_FieldMask                            0xFFFFFFFF
#define MWV207REG_PTN_GEN_INC_Y0_ReadMask                             0xFFFFFFFF
#define MWV207REG_PTN_GEN_INC_Y0_WriteMask                            0xFFFFFFFF
#define MWV207REG_PTN_GEN_INC_Y0_ResetValue                           0x00000000

#define MWV207REG_PTN_GEN_INC_Y0_RED                                        15:0
#define MWV207REG_PTN_GEN_INC_Y0_RED_End                                      15
#define MWV207REG_PTN_GEN_INC_Y0_RED_Start                                     0
#define MWV207REG_PTN_GEN_INC_Y0_RED_Type                                    U16


#define MWV207REG_PTN_GEN_INC_Y0_GREENS                                    31:16
#define MWV207REG_PTN_GEN_INC_Y0_GREENS_End                                   31
#define MWV207REG_PTN_GEN_INC_Y0_GREENS_Start                                 16
#define MWV207REG_PTN_GEN_INC_Y0_GREENS_Type                                 U16

#define mwv207regPtnGenIncY1RegAddrs                                      0x5FBA
#define MWV207REG_PTN_GEN_INC_Y1_Address                                 0x17EE8
#define MWV207REG_PTN_GEN_INC_Y1_MSB                                          15
#define MWV207REG_PTN_GEN_INC_Y1_LSB                                           0
#define MWV207REG_PTN_GEN_INC_Y1_BLK                                           0
#define MWV207REG_PTN_GEN_INC_Y1_Count                                         1
#define MWV207REG_PTN_GEN_INC_Y1_FieldMask                            0x0000FFFF
#define MWV207REG_PTN_GEN_INC_Y1_ReadMask                             0x0000FFFF
#define MWV207REG_PTN_GEN_INC_Y1_WriteMask                            0x0000FFFF
#define MWV207REG_PTN_GEN_INC_Y1_ResetValue                           0x00000000


#define MWV207REG_PTN_GEN_INC_Y1_BLUE                                       15:0
#define MWV207REG_PTN_GEN_INC_Y1_BLUE_End                                     15
#define MWV207REG_PTN_GEN_INC_Y1_BLUE_Start                                    0
#define MWV207REG_PTN_GEN_INC_Y1_BLUE_Type                                   U16




#define mwv207regChecksumExpectedChecksumRedRegAddrs                      0x5FBB
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_Address                 0x17EEC
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_MSB                          15
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_LSB                           0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_BLK                           0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_Count                         1
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_FieldMask            0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_ReadMask             0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_WriteMask            0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_ResetValue           0x00000000

#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE                      31:0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE_End                    31
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE_Start                   0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_RED_VALUE_Type                  U32




#define mwv207regChecksumExpectedChecksumGreenRegAddrs                    0x5FBC
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_Address               0x17EF0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_MSB                        15
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_LSB                         0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_BLK                         0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_Count                       1
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_FieldMask          0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_ReadMask           0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_WriteMask          0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_ResetValue         0x00000000

#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE                    31:0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE_End                  31
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE_Start                 0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_GREEN_VALUE_Type                U32




#define mwv207regChecksumExpectedChecksumBlueRegAddrs                     0x5FBD
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_Address                0x17EF4
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_MSB                         15
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_LSB                          0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_BLK                          0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_Count                        1
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_FieldMask           0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_ReadMask            0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_WriteMask           0xFFFFFFFF
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_ResetValue          0x00000000

#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE                     31:0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE_End                   31
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE_Start                  0
#define MWV207REG_CHECKSUM_EXPECTED_CHECKSUM_BLUE_VALUE_Type                 U32




#define mwv207regPatternsRegAddrs                                         0x5FBE
#define MWV207REG_PATTERNS_Address                                       0x17EF8
#define MWV207REG_PATTERNS_MSB                                                15
#define MWV207REG_PATTERNS_LSB                                                 0
#define MWV207REG_PATTERNS_BLK                                                 0
#define MWV207REG_PATTERNS_Count                                               1
#define MWV207REG_PATTERNS_FieldMask                                  0x0000003F
#define MWV207REG_PATTERNS_ReadMask                                   0x0000003F
#define MWV207REG_PATTERNS_WriteMask                                  0x0000003F
#define MWV207REG_PATTERNS_ResetValue                                 0x00000000

#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_RED                              0:0
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_RED_End                            0
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_RED_Start                          0
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_RED_Type                         U01
#define   MWV207REG_PATTERNS_COMPARE_CHECKSUM_RED_DISABLE                    0x0
#define   MWV207REG_PATTERNS_COMPARE_CHECKSUM_RED_ENABLE                     0x1

#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_GREEN                            1:1
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_GREEN_End                          1
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_GREEN_Start                        1
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_GREEN_Type                       U01
#define   MWV207REG_PATTERNS_COMPARE_CHECKSUM_GREEN_DISABLE                  0x0
#define   MWV207REG_PATTERNS_COMPARE_CHECKSUM_GREEN_ENABLE                   0x1

#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_BLUE                             2:2
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_BLUE_End                           2
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_BLUE_Start                         2
#define MWV207REG_PATTERNS_COMPARE_CHECKSUM_BLUE_Type                        U01
#define   MWV207REG_PATTERNS_COMPARE_CHECKSUM_BLUE_DISABLE                   0x0
#define   MWV207REG_PATTERNS_COMPARE_CHECKSUM_BLUE_ENABLE                    0x1

#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_RED                             3:3
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_RED_End                           3
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_RED_Start                         3
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_RED_Type                        U01

#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_GREEN                           4:4
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_GREEN_End                         4
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_GREEN_Start                       4
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_GREEN_Type                      U01

#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_BLUE                            5:5
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_BLUE_End                          5
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_BLUE_Start                        5
#define MWV207REG_PATTERNS_MISMATCH_CHECKSUM_BLUE_Type                       U01




#define mwv207regSWControlVXSBI0RegAddrs                                  0x5FBF
#define MWV207REG_SW_CONTROL_VXSBI0_Address                              0x17EFC
#define MWV207REG_SW_CONTROL_VXSBI0_MSB                                       15
#define MWV207REG_SW_CONTROL_VXSBI0_LSB                                        0
#define MWV207REG_SW_CONTROL_VXSBI0_BLK                                        0
#define MWV207REG_SW_CONTROL_VXSBI0_Count                                      1
#define MWV207REG_SW_CONTROL_VXSBI0_FieldMask                         0x0000001B
#define MWV207REG_SW_CONTROL_VXSBI0_ReadMask                          0x0000001B
#define MWV207REG_SW_CONTROL_VXSBI0_WriteMask                         0x0000001B
#define MWV207REG_SW_CONTROL_VXSBI0_ResetValue                        0x00000000

#define MWV207REG_SW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT                      1:0
#define MWV207REG_SW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_End                    1
#define MWV207REG_SW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_Start                  0
#define MWV207REG_SW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_Type                 U02
#define   MWV207REG_SW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_ISP                0x0
#define   MWV207REG_SW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_SOFT_CONTROL       0x1
#define   MWV207REG_SW_CONTROL_VXSBI0_ISP2_NPU_DISCONNECT_PATTERN_GEN        0x2

#define MWV207REG_SW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT                      4:3
#define MWV207REG_SW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_End                    4
#define MWV207REG_SW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_Start                  3
#define MWV207REG_SW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_Type                 U02
#define   MWV207REG_SW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_ISP                0x0
#define   MWV207REG_SW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_SOFT_CONTROL       0x1
#define   MWV207REG_SW_CONTROL_VXSBI0_NPU2_ISP_DISCONNECT_CHECK_SUM_GEN      0x2




#define mwv207regDenoisePostProcessC0RegAddrs                             0x5FC0
#define MWV207REG_DENOISE_POST_PROCESS_C0_Address                        0x17F00
#define MWV207REG_DENOISE_POST_PROCESS_C0_MSB                                 15
#define MWV207REG_DENOISE_POST_PROCESS_C0_LSB                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C0_BLK                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C0_Count                                1
#define MWV207REG_DENOISE_POST_PROCESS_C0_FieldMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C0_ReadMask                    0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C0_WriteMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C0_ResetValue                  0x00000000

#define MWV207REG_DENOISE_POST_PROCESS_C0_VALUE                             31:0
#define MWV207REG_DENOISE_POST_PROCESS_C0_VALUE_End                           31
#define MWV207REG_DENOISE_POST_PROCESS_C0_VALUE_Start                          0
#define MWV207REG_DENOISE_POST_PROCESS_C0_VALUE_Type                         U32




#define mwv207regDenoisePostProcessC1RegAddrs                             0x5FC1
#define MWV207REG_DENOISE_POST_PROCESS_C1_Address                        0x17F04
#define MWV207REG_DENOISE_POST_PROCESS_C1_MSB                                 15
#define MWV207REG_DENOISE_POST_PROCESS_C1_LSB                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C1_BLK                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C1_Count                                1
#define MWV207REG_DENOISE_POST_PROCESS_C1_FieldMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C1_ReadMask                    0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C1_WriteMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C1_ResetValue                  0x00000000

#define MWV207REG_DENOISE_POST_PROCESS_C1_VALUE                             31:0
#define MWV207REG_DENOISE_POST_PROCESS_C1_VALUE_End                           31
#define MWV207REG_DENOISE_POST_PROCESS_C1_VALUE_Start                          0
#define MWV207REG_DENOISE_POST_PROCESS_C1_VALUE_Type                         U32




#define mwv207regDenoisePostProcessC2RegAddrs                             0x5FC2
#define MWV207REG_DENOISE_POST_PROCESS_C2_Address                        0x17F08
#define MWV207REG_DENOISE_POST_PROCESS_C2_MSB                                 15
#define MWV207REG_DENOISE_POST_PROCESS_C2_LSB                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C2_BLK                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C2_Count                                1
#define MWV207REG_DENOISE_POST_PROCESS_C2_FieldMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C2_ReadMask                    0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C2_WriteMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C2_ResetValue                  0x00000000

#define MWV207REG_DENOISE_POST_PROCESS_C2_VALUE                             31:0
#define MWV207REG_DENOISE_POST_PROCESS_C2_VALUE_End                           31
#define MWV207REG_DENOISE_POST_PROCESS_C2_VALUE_Start                          0
#define MWV207REG_DENOISE_POST_PROCESS_C2_VALUE_Type                         U32




#define mwv207regDenoisePostProcessC3RegAddrs                             0x5FC3
#define MWV207REG_DENOISE_POST_PROCESS_C3_Address                        0x17F0C
#define MWV207REG_DENOISE_POST_PROCESS_C3_MSB                                 15
#define MWV207REG_DENOISE_POST_PROCESS_C3_LSB                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C3_BLK                                  0
#define MWV207REG_DENOISE_POST_PROCESS_C3_Count                                1
#define MWV207REG_DENOISE_POST_PROCESS_C3_FieldMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C3_ReadMask                    0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C3_WriteMask                   0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_C3_ResetValue                  0x00000000

#define MWV207REG_DENOISE_POST_PROCESS_C3_VALUE                             31:0
#define MWV207REG_DENOISE_POST_PROCESS_C3_VALUE_End                           31
#define MWV207REG_DENOISE_POST_PROCESS_C3_VALUE_Start                          0
#define MWV207REG_DENOISE_POST_PROCESS_C3_VALUE_Type                         U32



#define mwv207regDenoisePostProcessNnOutScaleRegAddrs                     0x5FC4
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_Address              0x17F10
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_MSB                       15
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_LSB                        0
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_BLK                        0
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_Count                      1
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_FieldMask         0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_ReadMask          0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_WriteMask         0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_ResetValue        0x00000000

#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE                   31:0
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE_End                 31
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE_Start                0
#define MWV207REG_DENOISE_POST_PROCESS_NN_OUT_SCALE_VALUE_Type               U32



#define mwv207regDenoisePostProcessClampMinMaxRegAddrs                    0x5FC5
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_Address             0x17F14
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_MSB                      15
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_LSB                       0
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_BLK                       0
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_Count                     1
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_FieldMask        0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_ReadMask         0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_WriteMask        0xFFFFFFFF
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_ResetValue       0x00000000

#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX              15:0
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX_End            15
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX_Start           0
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MAX_Type          U16

#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN             31:16
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN_End            31
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN_Start          16
#define MWV207REG_DENOISE_POST_PROCESS_CLAMP_MIN_MAX_CLAMP_MIN_Type          U16

#define mwv207regXDeepSleep0RegAddrs                                      0x5FC6
#define MWV207REG_XDEEP_SLEEP0_Address                                   0x17F18
#define MWV207REG_XDEEP_SLEEP0_MSB                                            15
#define MWV207REG_XDEEP_SLEEP0_LSB                                             0
#define MWV207REG_XDEEP_SLEEP0_BLK                                             0
#define MWV207REG_XDEEP_SLEEP0_Count                                           1
#define MWV207REG_XDEEP_SLEEP0_FieldMask                              0x01FE01FF
#define MWV207REG_XDEEP_SLEEP0_ReadMask                               0x01FE01FF
#define MWV207REG_XDEEP_SLEEP0_WriteMask                              0x01FE01FF
#define MWV207REG_XDEEP_SLEEP0_ResetValue                             0x00000000


#define MWV207REG_XDEEP_SLEEP0_EN_VIP0                                       1:0
#define MWV207REG_XDEEP_SLEEP0_EN_VIP0_End                                     1
#define MWV207REG_XDEEP_SLEEP0_EN_VIP0_Start                                   0
#define MWV207REG_XDEEP_SLEEP0_EN_VIP0_Type                                  U02
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP0_NOSLEEP                             0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP0_IMMEDIATE                           0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP0_VBLANK                              0x2


#define MWV207REG_XDEEP_SLEEP0_EN_VIP1                                       3:2
#define MWV207REG_XDEEP_SLEEP0_EN_VIP1_End                                     3
#define MWV207REG_XDEEP_SLEEP0_EN_VIP1_Start                                   2
#define MWV207REG_XDEEP_SLEEP0_EN_VIP1_Type                                  U02
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP1_NOSLEEP                             0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP1_IMMEDIATE                           0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP1_VBLANK                              0x2


#define MWV207REG_XDEEP_SLEEP0_EN_VIP2                                       5:4
#define MWV207REG_XDEEP_SLEEP0_EN_VIP2_End                                     5
#define MWV207REG_XDEEP_SLEEP0_EN_VIP2_Start                                   4
#define MWV207REG_XDEEP_SLEEP0_EN_VIP2_Type                                  U02
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP2_NOSLEEP                             0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP2_IMMEDIATE                           0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP2_VBLANK                              0x2


#define MWV207REG_XDEEP_SLEEP0_EN_VIP3                                       7:6
#define MWV207REG_XDEEP_SLEEP0_EN_VIP3_End                                     7
#define MWV207REG_XDEEP_SLEEP0_EN_VIP3_Start                                   6
#define MWV207REG_XDEEP_SLEEP0_EN_VIP3_Type                                  U02
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP3_NOSLEEP                             0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP3_IMMEDIATE                           0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_VIP3_VBLANK                              0x2

#define MWV207REG_XDEEP_SLEEP0_WAKEUP_METHOD                                 8:8
#define MWV207REG_XDEEP_SLEEP0_WAKEUP_METHOD_End                               8
#define MWV207REG_XDEEP_SLEEP0_WAKEUP_METHOD_Start                             8
#define MWV207REG_XDEEP_SLEEP0_WAKEUP_METHOD_Type                            U01
#define   MWV207REG_XDEEP_SLEEP0_WAKEUP_METHOD_HW_AUTO_DETECK                0x0
#define   MWV207REG_XDEEP_SLEEP0_WAKEUP_METHOD_SOFT_TIMER                    0x1


#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART0                         18:17
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART0_End                        18
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART0_Start                      17
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART0_Type                      U02
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART0_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART0_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART0_VBLANK                  0x2


#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART1                         20:19
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART1_End                        20
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART1_Start                      19
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART1_Type                      U02
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART1_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART1_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART1_VBLANK                  0x2


#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART2                         22:21
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART2_End                        22
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART2_Start                      21
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART2_Type                      U02
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART2_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART2_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART2_VBLANK                  0x2


#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART3                         24:23
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART3_End                        24
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART3_Start                      23
#define MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART3_Type                      U02
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART3_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART3_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP0_EN_SHARED_OCM_PART3_VBLANK                  0x2

#define mwv207regXDeepSleep1RegAddrs                                      0x5FC7
#define MWV207REG_XDEEP_SLEEP1_Address                                   0x17F1C
#define MWV207REG_XDEEP_SLEEP1_MSB                                            15
#define MWV207REG_XDEEP_SLEEP1_LSB                                             0
#define MWV207REG_XDEEP_SLEEP1_BLK                                             0
#define MWV207REG_XDEEP_SLEEP1_Count                                           1
#define MWV207REG_XDEEP_SLEEP1_FieldMask                              0x000000FF
#define MWV207REG_XDEEP_SLEEP1_ReadMask                               0x000000FF
#define MWV207REG_XDEEP_SLEEP1_WriteMask                              0x000000FF
#define MWV207REG_XDEEP_SLEEP1_ResetValue                             0x00000000


#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART4                           1:0
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART4_End                         1
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART4_Start                       0
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART4_Type                      U02
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART4_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART4_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART4_VBLANK                  0x2


#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART5                           3:2
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART5_End                         3
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART5_Start                       2
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART5_Type                      U02
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART5_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART5_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART5_VBLANK                  0x2


#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART6                           5:4
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART6_End                         5
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART6_Start                       4
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART6_Type                      U02
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART6_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART6_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART6_VBLANK                  0x2


#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART7                           7:6
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART7_End                         7
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART7_Start                       6
#define MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART7_Type                      U02
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART7_NOSLEEP                 0x0
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART7_IMMEDIATE               0x1
#define   MWV207REG_XDEEP_SLEEP1_EN_SHARED_OCM_PART7_VBLANK                  0x2

#define mwv207regXDeepSleep2RegAddrs                                      0x5FC8
#define MWV207REG_XDEEP_SLEEP2_Address                                   0x17F20
#define MWV207REG_XDEEP_SLEEP2_MSB                                            15
#define MWV207REG_XDEEP_SLEEP2_LSB                                             0
#define MWV207REG_XDEEP_SLEEP2_BLK                                             0
#define MWV207REG_XDEEP_SLEEP2_Count                                           1
#define MWV207REG_XDEEP_SLEEP2_FieldMask                              0x0000FFFF
#define MWV207REG_XDEEP_SLEEP2_ReadMask                               0x0000FFFF
#define MWV207REG_XDEEP_SLEEP2_WriteMask                              0x0000FFFF
#define MWV207REG_XDEEP_SLEEP2_ResetValue                             0x00000000


#define MWV207REG_XDEEP_SLEEP2_WAKE_UP_COUNT                                15:0
#define MWV207REG_XDEEP_SLEEP2_WAKE_UP_COUNT_End                              15
#define MWV207REG_XDEEP_SLEEP2_WAKE_UP_COUNT_Start                             0
#define MWV207REG_XDEEP_SLEEP2_WAKE_UP_COUNT_Type                            U16

#define mwv207regXCacheRegAddrs                                           0x5FC9
#define MWV207REG_XCACHE_Address                                         0x17F24
#define MWV207REG_XCACHE_MSB                                                  15
#define MWV207REG_XCACHE_LSB                                                   0
#define MWV207REG_XCACHE_BLK                                                   0
#define MWV207REG_XCACHE_Count                                                 1
#define MWV207REG_XCACHE_FieldMask                                    0x000000FF
#define MWV207REG_XCACHE_ReadMask                                     0x000000FF
#define MWV207REG_XCACHE_WriteMask                                    0x000000FF
#define MWV207REG_XCACHE_ResetValue                                   0x00000000


#define MWV207REG_XCACHE_AR_VALUE                                            3:0
#define MWV207REG_XCACHE_AR_VALUE_End                                          3
#define MWV207REG_XCACHE_AR_VALUE_Start                                        0
#define MWV207REG_XCACHE_AR_VALUE_Type                                       U04


#define MWV207REG_XCACHE_WR_VALUE                                            7:4
#define MWV207REG_XCACHE_WR_VALUE_End                                          7
#define MWV207REG_XCACHE_WR_VALUE_Start                                        4
#define MWV207REG_XCACHE_WR_VALUE_Type                                       U04




#define mwv207regVIPDebugRegAddrs                                         0x5FCA
#define MWV207REG_VIP_DEBUG_Address                                      0x17F28
#define MWV207REG_VIP_DEBUG_MSB                                               15
#define MWV207REG_VIP_DEBUG_LSB                                                0
#define MWV207REG_VIP_DEBUG_BLK                                                0
#define MWV207REG_VIP_DEBUG_Count                                              1
#define MWV207REG_VIP_DEBUG_FieldMask                                 0xFFFFFFFF
#define MWV207REG_VIP_DEBUG_ReadMask                                  0xFFFFFFFF
#define MWV207REG_VIP_DEBUG_WriteMask                                 0xFFFFFFFF
#define MWV207REG_VIP_DEBUG_ResetValue                                0x00000000

#define MWV207REG_VIP_DEBUG_OCLA                                            31:0
#define MWV207REG_VIP_DEBUG_OCLA_End                                          31
#define MWV207REG_VIP_DEBUG_OCLA_Start                                         0
#define MWV207REG_VIP_DEBUG_OCLA_Type                                        U32




#define mwv207regXVIPDebugRegAddrs                                        0x5FCB
#define MWV207REG_XVIP_DEBUG_Address                                     0x17F2C
#define MWV207REG_XVIP_DEBUG_MSB                                              15
#define MWV207REG_XVIP_DEBUG_LSB                                               0
#define MWV207REG_XVIP_DEBUG_BLK                                               0
#define MWV207REG_XVIP_DEBUG_Count                                             1
#define MWV207REG_XVIP_DEBUG_FieldMask                                0xFFFFFFFF
#define MWV207REG_XVIP_DEBUG_ReadMask                                 0xFFFFFFFF
#define MWV207REG_XVIP_DEBUG_WriteMask                                0xFFFFFFFF
#define MWV207REG_XVIP_DEBUG_ResetValue                               0x00000000

#define MWV207REG_XVIP_DEBUG_OCLA                                           31:0
#define MWV207REG_XVIP_DEBUG_OCLA_End                                         31
#define MWV207REG_XVIP_DEBUG_OCLA_Start                                        0
#define MWV207REG_XVIP_DEBUG_OCLA_Type                                       U32




#define mwv207regCompDecompRegAddrs                                       0x5FCC
#define MWV207REG_COMP_DECOMP_Address                                    0x17F30
#define MWV207REG_COMP_DECOMP_MSB                                             15
#define MWV207REG_COMP_DECOMP_LSB                                              0
#define MWV207REG_COMP_DECOMP_BLK                                              0
#define MWV207REG_COMP_DECOMP_Count                                            1
#define MWV207REG_COMP_DECOMP_FieldMask                               0x00000FFF
#define MWV207REG_COMP_DECOMP_ReadMask                                0x00000FFF
#define MWV207REG_COMP_DECOMP_WriteMask                               0x00000FFF
#define MWV207REG_COMP_DECOMP_ResetValue                              0x00000000

#define MWV207REG_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS                     5:0
#define MWV207REG_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS_End                   5
#define MWV207REG_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS_Start                 0
#define MWV207REG_COMP_DECOMP_COMP_FRAME_WIDTH_LOW6_BITS_Type                U06

#define MWV207REG_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS                 11:6
#define MWV207REG_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS_End               11
#define MWV207REG_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS_Start              6
#define MWV207REG_COMP_DECOMP_DE_COMP_FRAME_WIDTH_LOW6_BITS_Type             U06


#endif


