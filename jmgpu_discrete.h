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




#ifndef __AQHostInterface_h__
#define __AQHostInterface_h__




#define AQHiClockControlRegAddrs                                          0x0000
#define AQ_HI_CLOCK_CONTROL_Address                                      0x00000
#define AQ_HI_CLOCK_CONTROL_MSB                                               15
#define AQ_HI_CLOCK_CONTROL_LSB                                                0
#define AQ_HI_CLOCK_CONTROL_BLK                                                0
#define AQ_HI_CLOCK_CONTROL_Count                                              1
#define AQ_HI_CLOCK_CONTROL_FieldMask                                 0x1FFF7FFF
#define AQ_HI_CLOCK_CONTROL_ReadMask                                  0x1FFF7FFF
#define AQ_HI_CLOCK_CONTROL_WriteMask                                 0x1FF87FFF
#define AQ_HI_CLOCK_CONTROL_ResetValue                                0x00070900

#define AQ_HI_CLOCK_CONTROL_CLK3D_DIS                                        0:0
#define AQ_HI_CLOCK_CONTROL_CLK3D_DIS_End                                      0
#define AQ_HI_CLOCK_CONTROL_CLK3D_DIS_Start                                    0
#define AQ_HI_CLOCK_CONTROL_CLK3D_DIS_Type                                   U01

#define AQ_HI_CLOCK_CONTROL_CLK2D_DIS                                        1:1
#define AQ_HI_CLOCK_CONTROL_CLK2D_DIS_End                                      1
#define AQ_HI_CLOCK_CONTROL_CLK2D_DIS_Start                                    1
#define AQ_HI_CLOCK_CONTROL_CLK2D_DIS_Type                                   U01


#define AQ_HI_CLOCK_CONTROL_FSCALE_VAL                                       8:2
#define AQ_HI_CLOCK_CONTROL_FSCALE_VAL_End                                     8
#define AQ_HI_CLOCK_CONTROL_FSCALE_VAL_Start                                   2
#define AQ_HI_CLOCK_CONTROL_FSCALE_VAL_Type                                  U07

#define AQ_HI_CLOCK_CONTROL_FSCALE_CMD_LOAD                                  9:9
#define AQ_HI_CLOCK_CONTROL_FSCALE_CMD_LOAD_End                                9
#define AQ_HI_CLOCK_CONTROL_FSCALE_CMD_LOAD_Start                              9
#define AQ_HI_CLOCK_CONTROL_FSCALE_CMD_LOAD_Type                             U01


#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_CLOCK_GATING                       10:10
#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_CLOCK_GATING_End                      10
#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_CLOCK_GATING_Start                    10
#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_CLOCK_GATING_Type                    U01

#define AQ_HI_CLOCK_CONTROL_DISABLE_DEBUG_REGISTERS                        11:11
#define AQ_HI_CLOCK_CONTROL_DISABLE_DEBUG_REGISTERS_End                       11
#define AQ_HI_CLOCK_CONTROL_DISABLE_DEBUG_REGISTERS_Start                     11
#define AQ_HI_CLOCK_CONTROL_DISABLE_DEBUG_REGISTERS_Type                     U01

#define AQ_HI_CLOCK_CONTROL_SOFT_RESET                                     12:12
#define AQ_HI_CLOCK_CONTROL_SOFT_RESET_End                                    12
#define AQ_HI_CLOCK_CONTROL_SOFT_RESET_Start                                  12
#define AQ_HI_CLOCK_CONTROL_SOFT_RESET_Type                                  U01


#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION                 13:13
#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_End                13
#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Start              13
#define AQ_HI_CLOCK_CONTROL_DISABLE_RAM_POWER_OPTIMIZATION_Type              U01


#define AQ_HI_CLOCK_CONTROL_DISABLE_CORE_SPEED_UP                          14:14
#define AQ_HI_CLOCK_CONTROL_DISABLE_CORE_SPEED_UP_End                         14
#define AQ_HI_CLOCK_CONTROL_DISABLE_CORE_SPEED_UP_Start                       14
#define AQ_HI_CLOCK_CONTROL_DISABLE_CORE_SPEED_UP_Type                       U01


#define AQ_HI_CLOCK_CONTROL_IDLE3_D                                        16:16
#define AQ_HI_CLOCK_CONTROL_IDLE3_D_End                                       16
#define AQ_HI_CLOCK_CONTROL_IDLE3_D_Start                                     16
#define AQ_HI_CLOCK_CONTROL_IDLE3_D_Type                                     U01


#define AQ_HI_CLOCK_CONTROL_IDLE2_D                                        17:17
#define AQ_HI_CLOCK_CONTROL_IDLE2_D_End                                       17
#define AQ_HI_CLOCK_CONTROL_IDLE2_D_Start                                     17
#define AQ_HI_CLOCK_CONTROL_IDLE2_D_Type                                     U01


#define AQ_HI_CLOCK_CONTROL_IDLE_VG                                        18:18
#define AQ_HI_CLOCK_CONTROL_IDLE_VG_End                                       18
#define AQ_HI_CLOCK_CONTROL_IDLE_VG_Start                                     18
#define AQ_HI_CLOCK_CONTROL_IDLE_VG_Type                                     U01

#define AQ_HI_CLOCK_CONTROL_ISOLATE_GPU                                    19:19
#define AQ_HI_CLOCK_CONTROL_ISOLATE_GPU_End                                   19
#define AQ_HI_CLOCK_CONTROL_ISOLATE_GPU_Start                                 19
#define AQ_HI_CLOCK_CONTROL_ISOLATE_GPU_Type                                 U01


#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_REG_SELECT                          23:20
#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_REG_SELECT_End                         23
#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_REG_SELECT_Start                       20
#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_REG_SELECT_Type                       U04


#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_USE_SINGLE_AXI                      27:24
#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_USE_SINGLE_AXI_End                     27
#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_USE_SINGLE_AXI_Start                   24
#define AQ_HI_CLOCK_CONTROL_MULTI_PIPE_USE_SINGLE_AXI_Type                   U04


#define AQ_HI_CLOCK_CONTROL_SOFT_RESET_L2                                  28:28
#define AQ_HI_CLOCK_CONTROL_SOFT_RESET_L2_End                                 28
#define AQ_HI_CLOCK_CONTROL_SOFT_RESET_L2_Start                               28
#define AQ_HI_CLOCK_CONTROL_SOFT_RESET_L2_Type                               U01




#define AQHiIdleRegAddrs                                                  0x0001
#define AQ_HI_IDLE_Address                                               0x00004
#define AQ_HI_IDLE_MSB                                                        15
#define AQ_HI_IDLE_LSB                                                         0
#define AQ_HI_IDLE_BLK                                                         0
#define AQ_HI_IDLE_Count                                                       1
#define AQ_HI_IDLE_FieldMask                                          0xFFFFFFFF
#define AQ_HI_IDLE_ReadMask                                           0xFFFFFFFF
#define AQ_HI_IDLE_WriteMask                                          0x00000000
#define AQ_HI_IDLE_ResetValue                                         0x7FFFFFFF


#define AQ_HI_IDLE_IDLE_FE                                                   0:0
#define AQ_HI_IDLE_IDLE_FE_End                                                 0
#define AQ_HI_IDLE_IDLE_FE_Start                                               0
#define AQ_HI_IDLE_IDLE_FE_Type                                              U01


#define AQ_HI_IDLE_IDLE_DE                                                   1:1
#define AQ_HI_IDLE_IDLE_DE_End                                                 1
#define AQ_HI_IDLE_IDLE_DE_Start                                               1
#define AQ_HI_IDLE_IDLE_DE_Type                                              U01


#define AQ_HI_IDLE_IDLE_PE                                                   2:2
#define AQ_HI_IDLE_IDLE_PE_End                                                 2
#define AQ_HI_IDLE_IDLE_PE_Start                                               2
#define AQ_HI_IDLE_IDLE_PE_Type                                              U01


#define AQ_HI_IDLE_IDLE_SH                                                   3:3
#define AQ_HI_IDLE_IDLE_SH_End                                                 3
#define AQ_HI_IDLE_IDLE_SH_Start                                               3
#define AQ_HI_IDLE_IDLE_SH_Type                                              U01


#define AQ_HI_IDLE_IDLE_PA                                                   4:4
#define AQ_HI_IDLE_IDLE_PA_End                                                 4
#define AQ_HI_IDLE_IDLE_PA_Start                                               4
#define AQ_HI_IDLE_IDLE_PA_Type                                              U01


#define AQ_HI_IDLE_IDLE_SE                                                   5:5
#define AQ_HI_IDLE_IDLE_SE_End                                                 5
#define AQ_HI_IDLE_IDLE_SE_Start                                               5
#define AQ_HI_IDLE_IDLE_SE_Type                                              U01


#define AQ_HI_IDLE_IDLE_RA                                                   6:6
#define AQ_HI_IDLE_IDLE_RA_End                                                 6
#define AQ_HI_IDLE_IDLE_RA_Start                                               6
#define AQ_HI_IDLE_IDLE_RA_Type                                              U01


#define AQ_HI_IDLE_IDLE_TX                                                   7:7
#define AQ_HI_IDLE_IDLE_TX_End                                                 7
#define AQ_HI_IDLE_IDLE_TX_Start                                               7
#define AQ_HI_IDLE_IDLE_TX_Type                                              U01


#define AQ_HI_IDLE_IDLE_VG                                                   8:8
#define AQ_HI_IDLE_IDLE_VG_End                                                 8
#define AQ_HI_IDLE_IDLE_VG_Start                                               8
#define AQ_HI_IDLE_IDLE_VG_Type                                              U01


#define AQ_HI_IDLE_IDLE_IM                                                   9:9
#define AQ_HI_IDLE_IDLE_IM_End                                                 9
#define AQ_HI_IDLE_IDLE_IM_Start                                               9
#define AQ_HI_IDLE_IDLE_IM_Type                                              U01


#define AQ_HI_IDLE_IDLE_FP                                                 10:10
#define AQ_HI_IDLE_IDLE_FP_End                                                10
#define AQ_HI_IDLE_IDLE_FP_Start                                              10
#define AQ_HI_IDLE_IDLE_FP_Type                                              U01


#define AQ_HI_IDLE_IDLE_TS                                                 11:11
#define AQ_HI_IDLE_IDLE_TS_End                                                11
#define AQ_HI_IDLE_IDLE_TS_Start                                              11
#define AQ_HI_IDLE_IDLE_TS_Type                                              U01


#define AQ_HI_IDLE_IDLE_BLT                                                12:12
#define AQ_HI_IDLE_IDLE_BLT_End                                               12
#define AQ_HI_IDLE_IDLE_BLT_Start                                             12
#define AQ_HI_IDLE_IDLE_BLT_Type                                             U01


#define AQ_HI_IDLE_IDLE_FE_BLT                                             13:13
#define AQ_HI_IDLE_IDLE_FE_BLT_End                                            13
#define AQ_HI_IDLE_IDLE_FE_BLT_Start                                          13
#define AQ_HI_IDLE_IDLE_FE_BLT_Type                                          U01


#define AQ_HI_IDLE_IDLE_MC                                                 14:14
#define AQ_HI_IDLE_IDLE_MC_End                                                14
#define AQ_HI_IDLE_IDLE_MC_Start                                              14
#define AQ_HI_IDLE_IDLE_MC_Type                                              U01


#define AQ_HI_IDLE_IDLE_PPA                                                15:15
#define AQ_HI_IDLE_IDLE_PPA_End                                               15
#define AQ_HI_IDLE_IDLE_PPA_Start                                             15
#define AQ_HI_IDLE_IDLE_PPA_Type                                             U01


#define AQ_HI_IDLE_IDLE_DC                                                 16:16
#define AQ_HI_IDLE_IDLE_DC_End                                                16
#define AQ_HI_IDLE_IDLE_DC_Start                                              16
#define AQ_HI_IDLE_IDLE_DC_Type                                              U01


#define AQ_HI_IDLE_IDLE_WD                                                 17:17
#define AQ_HI_IDLE_IDLE_WD_End                                                17
#define AQ_HI_IDLE_IDLE_WD_Start                                              17
#define AQ_HI_IDLE_IDLE_WD_Type                                              U01


#define AQ_HI_IDLE_IDLE_NN                                                 18:18
#define AQ_HI_IDLE_IDLE_NN_End                                                18
#define AQ_HI_IDLE_IDLE_NN_Start                                              18
#define AQ_HI_IDLE_IDLE_NN_Type                                              U01


#define AQ_HI_IDLE_IDLE_TP                                                 19:19
#define AQ_HI_IDLE_IDLE_TP_End                                                19
#define AQ_HI_IDLE_IDLE_TP_Start                                              19
#define AQ_HI_IDLE_IDLE_TP_Type                                              U01


#define AQ_HI_IDLE_IDLE_JMC                                                20:20
#define AQ_HI_IDLE_IDLE_JMC_End                                               20
#define AQ_HI_IDLE_IDLE_JMC_Start                                             20
#define AQ_HI_IDLE_IDLE_JMC_Type                                             U01


#define AQ_HI_IDLE_IDLE_MMU                                                21:21
#define AQ_HI_IDLE_IDLE_MMU_End                                               21
#define AQ_HI_IDLE_IDLE_MMU_Start                                             21
#define AQ_HI_IDLE_IDLE_MMU_Type                                             U01


#define AQ_HI_IDLE_UNUSED                                                  30:22
#define AQ_HI_IDLE_UNUSED_End                                                 30
#define AQ_HI_IDLE_UNUSED_Start                                               22
#define AQ_HI_IDLE_UNUSED_Type                                               U09


#define AQ_HI_IDLE_AXI_LP                                                  31:31
#define AQ_HI_IDLE_AXI_LP_End                                                 31
#define AQ_HI_IDLE_AXI_LP_Start                                               31
#define AQ_HI_IDLE_AXI_LP_Type                                               U01



#define AQAxiConfigRegAddrs                                               0x0002
#define AQ_AXI_CONFIG_Address                                            0x00008
#define AQ_AXI_CONFIG_MSB                                                     15
#define AQ_AXI_CONFIG_LSB                                                      0
#define AQ_AXI_CONFIG_BLK                                                      0
#define AQ_AXI_CONFIG_Count                                                    1
#define AQ_AXI_CONFIG_FieldMask                                       0x00FFFFFF
#define AQ_AXI_CONFIG_ReadMask                                        0x00FFFFFF
#define AQ_AXI_CONFIG_WriteMask                                       0x00FFFFFF
#define AQ_AXI_CONFIG_ResetValue                                      0x00222200


#define AQ_AXI_CONFIG_AWID                                                   3:0
#define AQ_AXI_CONFIG_AWID_End                                                 3
#define AQ_AXI_CONFIG_AWID_Start                                               0
#define AQ_AXI_CONFIG_AWID_Type                                              U04


#define AQ_AXI_CONFIG_ARID                                                   7:4
#define AQ_AXI_CONFIG_ARID_End                                                 7
#define AQ_AXI_CONFIG_ARID_Start                                               4
#define AQ_AXI_CONFIG_ARID_Type                                              U04


#define AQ_AXI_CONFIG_AWCACHE                                               11:8
#define AQ_AXI_CONFIG_AWCACHE_End                                             11
#define AQ_AXI_CONFIG_AWCACHE_Start                                            8
#define AQ_AXI_CONFIG_AWCACHE_Type                                           U04


#define AQ_AXI_CONFIG_ARCACHE                                              15:12
#define AQ_AXI_CONFIG_ARCACHE_End                                             15
#define AQ_AXI_CONFIG_ARCACHE_Start                                           12
#define AQ_AXI_CONFIG_ARCACHE_Type                                           U04


#define AQ_AXI_CONFIG_AXDOMAIN_SHARED                                      17:16
#define AQ_AXI_CONFIG_AXDOMAIN_SHARED_End                                     17
#define AQ_AXI_CONFIG_AXDOMAIN_SHARED_Start                                   16
#define AQ_AXI_CONFIG_AXDOMAIN_SHARED_Type                                   U02


#define AQ_AXI_CONFIG_AXDOMAIN_NON_SHARED                                  19:18
#define AQ_AXI_CONFIG_AXDOMAIN_NON_SHARED_End                                 19
#define AQ_AXI_CONFIG_AXDOMAIN_NON_SHARED_Start                               18
#define AQ_AXI_CONFIG_AXDOMAIN_NON_SHARED_Type                               U02


#define AQ_AXI_CONFIG_AXCACHE_OVERRIDE_SHARED                              23:20
#define AQ_AXI_CONFIG_AXCACHE_OVERRIDE_SHARED_End                             23
#define AQ_AXI_CONFIG_AXCACHE_OVERRIDE_SHARED_Start                           20
#define AQ_AXI_CONFIG_AXCACHE_OVERRIDE_SHARED_Type                           U04



#define AQAxiStatusRegAddrs                                               0x0003
#define AQ_AXI_STATUS_Address                                            0x0000C
#define AQ_AXI_STATUS_MSB                                                     15
#define AQ_AXI_STATUS_LSB                                                      0
#define AQ_AXI_STATUS_BLK                                                      0
#define AQ_AXI_STATUS_Count                                                    1
#define AQ_AXI_STATUS_FieldMask                                       0x000003FF
#define AQ_AXI_STATUS_ReadMask                                        0x000003FF
#define AQ_AXI_STATUS_WriteMask                                       0x00000000
#define AQ_AXI_STATUS_ResetValue                                      0x00000000


#define AQ_AXI_STATUS_WR_ERR_ID                                              3:0
#define AQ_AXI_STATUS_WR_ERR_ID_End                                            3
#define AQ_AXI_STATUS_WR_ERR_ID_Start                                          0
#define AQ_AXI_STATUS_WR_ERR_ID_Type                                         U04


#define AQ_AXI_STATUS_RD_ERR_ID                                              7:4
#define AQ_AXI_STATUS_RD_ERR_ID_End                                            7
#define AQ_AXI_STATUS_RD_ERR_ID_Start                                          4
#define AQ_AXI_STATUS_RD_ERR_ID_Type                                         U04


#define AQ_AXI_STATUS_DET_WR_ERR                                             8:8
#define AQ_AXI_STATUS_DET_WR_ERR_End                                           8
#define AQ_AXI_STATUS_DET_WR_ERR_Start                                         8
#define AQ_AXI_STATUS_DET_WR_ERR_Type                                        U01


#define AQ_AXI_STATUS_DET_RD_ERR                                             9:9
#define AQ_AXI_STATUS_DET_RD_ERR_End                                           9
#define AQ_AXI_STATUS_DET_RD_ERR_Start                                         9
#define AQ_AXI_STATUS_DET_RD_ERR_Type                                        U01



#define AQIntrAcknowledgeRegAddrs                                         0x0004
#define AQ_INTR_ACKNOWLEDGE_Address                                      0x00010
#define AQ_INTR_ACKNOWLEDGE_MSB                                               15
#define AQ_INTR_ACKNOWLEDGE_LSB                                                0
#define AQ_INTR_ACKNOWLEDGE_BLK                                                0
#define AQ_INTR_ACKNOWLEDGE_Count                                              1
#define AQ_INTR_ACKNOWLEDGE_FieldMask                                 0xFFFFFFFF
#define AQ_INTR_ACKNOWLEDGE_ReadMask                                  0xFFFFFFFF
#define AQ_INTR_ACKNOWLEDGE_WriteMask                                 0x00000000
#define AQ_INTR_ACKNOWLEDGE_ResetValue                                0x00000000

#define AQ_INTR_ACKNOWLEDGE_INTR_VEC                                        31:0
#define AQ_INTR_ACKNOWLEDGE_INTR_VEC_End                                      31
#define AQ_INTR_ACKNOWLEDGE_INTR_VEC_Start                                     0
#define AQ_INTR_ACKNOWLEDGE_INTR_VEC_Type                                    U32




#define AQIntrEnblRegAddrs                                                0x0005
#define AQ_INTR_ENBL_Address                                             0x00014
#define AQ_INTR_ENBL_MSB                                                      15
#define AQ_INTR_ENBL_LSB                                                       0
#define AQ_INTR_ENBL_BLK                                                       0
#define AQ_INTR_ENBL_Count                                                     1
#define AQ_INTR_ENBL_FieldMask                                        0xFFFFFFFF
#define AQ_INTR_ENBL_ReadMask                                         0xFFFFFFFF
#define AQ_INTR_ENBL_WriteMask                                        0xFFFFFFFF
#define AQ_INTR_ENBL_ResetValue                                       0x00000000

#define AQ_INTR_ENBL_INTR_ENBL_VEC                                          31:0
#define AQ_INTR_ENBL_INTR_ENBL_VEC_End                                        31
#define AQ_INTR_ENBL_INTR_ENBL_VEC_Start                                       0
#define AQ_INTR_ENBL_INTR_ENBL_VEC_Type                                      U32



#define AQIdentRegAddrs                                                   0x0006
#define AQ_IDENT_Address                                                 0x00018
#define AQ_IDENT_MSB                                                          15
#define AQ_IDENT_LSB                                                           0
#define AQ_IDENT_BLK                                                           0
#define AQ_IDENT_Count                                                         1
#define AQ_IDENT_FieldMask                                            0xFFFFFFFF
#define AQ_IDENT_ReadMask                                             0xFFFFFFFF
#define AQ_IDENT_WriteMask                                            0x00000000
#define AQ_IDENT_ResetValue                                           0x00000000

#define AQ_IDENT_FAMILY                                                    31:24
#define AQ_IDENT_FAMILY_End                                                   31
#define AQ_IDENT_FAMILY_Start                                                 24
#define AQ_IDENT_FAMILY_Type                                                 U08
#define   AQ_IDENT_FAMILY_JM500                                             0x01
#define   AQ_IDENT_FAMILY_JM520                                             0x02
#define   AQ_IDENT_FAMILY_JM530                                             0x03
#define   AQ_IDENT_FAMILY_JM400                                             0x04
#define   AQ_IDENT_FAMILY_JM450                                             0x05
#define   AQ_IDENT_FAMILY_JM600                                             0x08
#define   AQ_IDENT_FAMILY_JM700                                             0x09
#define   AQ_IDENT_FAMILY_JM350                                             0x0A
#define   AQ_IDENT_FAMILY_JM380                                             0x0B
#define   AQ_IDENT_FAMILY_JM800                                             0x0C
#define   AQ_IDENT_FAMILY_JM1000                                            0x10
#define   AQ_IDENT_FAMILY_JM2000                                            0x14


#define AQ_IDENT_PRODUCT                                                   23:16
#define AQ_IDENT_PRODUCT_End                                                  23
#define AQ_IDENT_PRODUCT_Start                                                16
#define AQ_IDENT_PRODUCT_Type                                                U08


#define AQ_IDENT_REVISION                                                  15:12
#define AQ_IDENT_REVISION_End                                                 15
#define AQ_IDENT_REVISION_Start                                               12
#define AQ_IDENT_REVISION_Type                                               U04


#define AQ_IDENT_TECHNOLOGY                                                 11:8
#define AQ_IDENT_TECHNOLOGY_End                                               11
#define AQ_IDENT_TECHNOLOGY_Start                                              8
#define AQ_IDENT_TECHNOLOGY_Type                                             U04


#define AQ_IDENT_CUSTOMER                                                    7:0
#define AQ_IDENT_CUSTOMER_End                                                  7
#define AQ_IDENT_CUSTOMER_Start                                                0
#define AQ_IDENT_CUSTOMER_Type                                               U08



#define JMFeaturesRegAddrs                                                0x0007
#define JM_FEATURES_Address                                              0x0001C
#define JM_FEATURES_MSB                                                       15
#define JM_FEATURES_LSB                                                        0
#define JM_FEATURES_BLK                                                        0
#define JM_FEATURES_Count                                                      1
#define JM_FEATURES_FieldMask                                         0xFFFFFFFF
#define JM_FEATURES_ReadMask                                          0xFFFFFFFF
#define JM_FEATURES_WriteMask                                         0x00000000
#define JM_FEATURES_ResetValue                                        0x00000000


#define JM_FEATURES_FAST_CLEAR                                               0:0
#define JM_FEATURES_FAST_CLEAR_End                                             0
#define JM_FEATURES_FAST_CLEAR_Start                                           0
#define JM_FEATURES_FAST_CLEAR_Type                                          U01
#define   JM_FEATURES_FAST_CLEAR_NONE                                        0x0
#define   JM_FEATURES_FAST_CLEAR_AVAILABLE                                   0x1


#define JM_FEATURES_SPECIAL_ANTI_ALIASING                                    1:1
#define JM_FEATURES_SPECIAL_ANTI_ALIASING_End                                  1
#define JM_FEATURES_SPECIAL_ANTI_ALIASING_Start                                1
#define JM_FEATURES_SPECIAL_ANTI_ALIASING_Type                               U01
#define   JM_FEATURES_SPECIAL_ANTI_ALIASING_NONE                             0x0
#define   JM_FEATURES_SPECIAL_ANTI_ALIASING_AVAILABLE                        0x1


#define JM_FEATURES_PIPE_3D                                                  2:2
#define JM_FEATURES_PIPE_3D_End                                                2
#define JM_FEATURES_PIPE_3D_Start                                              2
#define JM_FEATURES_PIPE_3D_Type                                             U01
#define   JM_FEATURES_PIPE_3D_NONE                                           0x0
#define   JM_FEATURES_PIPE_3D_AVAILABLE                                      0x1


#define JM_FEATURES_DXT_TEXTURE_COMPRESSION                                  3:3
#define JM_FEATURES_DXT_TEXTURE_COMPRESSION_End                                3
#define JM_FEATURES_DXT_TEXTURE_COMPRESSION_Start                              3
#define JM_FEATURES_DXT_TEXTURE_COMPRESSION_Type                             U01
#define   JM_FEATURES_DXT_TEXTURE_COMPRESSION_NONE                           0x0
#define   JM_FEATURES_DXT_TEXTURE_COMPRESSION_AVAILABLE                      0x1


#define JM_FEATURES_DEBUG_MODE                                               4:4
#define JM_FEATURES_DEBUG_MODE_End                                             4
#define JM_FEATURES_DEBUG_MODE_Start                                           4
#define JM_FEATURES_DEBUG_MODE_Type                                          U01
#define   JM_FEATURES_DEBUG_MODE_NONE                                        0x0
#define   JM_FEATURES_DEBUG_MODE_AVAILABLE                                   0x1


#define JM_FEATURES_ZCOMPRESSION                                             5:5
#define JM_FEATURES_ZCOMPRESSION_End                                           5
#define JM_FEATURES_ZCOMPRESSION_Start                                         5
#define JM_FEATURES_ZCOMPRESSION_Type                                        U01
#define   JM_FEATURES_ZCOMPRESSION_NONE                                      0x0
#define   JM_FEATURES_ZCOMPRESSION_AVAILABLE                                 0x1


#define JM_FEATURES_YUV420_FILTER                                            6:6
#define JM_FEATURES_YUV420_FILTER_End                                          6
#define JM_FEATURES_YUV420_FILTER_Start                                        6
#define JM_FEATURES_YUV420_FILTER_Type                                       U01
#define   JM_FEATURES_YUV420_FILTER_NONE                                     0x0
#define   JM_FEATURES_YUV420_FILTER_AVAILABLE                                0x1


#define JM_FEATURES_MSAA                                                     7:7
#define JM_FEATURES_MSAA_End                                                   7
#define JM_FEATURES_MSAA_Start                                                 7
#define JM_FEATURES_MSAA_Type                                                U01
#define   JM_FEATURES_MSAA_NONE                                              0x0
#define   JM_FEATURES_MSAA_AVAILABLE                                         0x1


#define JM_FEATURES_DC                                                       8:8
#define JM_FEATURES_DC_End                                                     8
#define JM_FEATURES_DC_Start                                                   8
#define JM_FEATURES_DC_Type                                                  U01
#define   JM_FEATURES_DC_NONE                                                0x0
#define   JM_FEATURES_DC_AVAILABLE                                           0x1


#define JM_FEATURES_PIPE_2D                                                  9:9
#define JM_FEATURES_PIPE_2D_End                                                9
#define JM_FEATURES_PIPE_2D_Start                                              9
#define JM_FEATURES_PIPE_2D_Type                                             U01
#define   JM_FEATURES_PIPE_2D_NONE                                           0x0
#define   JM_FEATURES_PIPE_2D_AVAILABLE                                      0x1


#define JM_FEATURES_ETC1_TEXTURE_COMPRESSION                               10:10
#define JM_FEATURES_ETC1_TEXTURE_COMPRESSION_End                              10
#define JM_FEATURES_ETC1_TEXTURE_COMPRESSION_Start                            10
#define JM_FEATURES_ETC1_TEXTURE_COMPRESSION_Type                            U01
#define   JM_FEATURES_ETC1_TEXTURE_COMPRESSION_NONE                          0x0
#define   JM_FEATURES_ETC1_TEXTURE_COMPRESSION_AVAILABLE                     0x1


#define JM_FEATURES_FAST_SCALER                                            11:11
#define JM_FEATURES_FAST_SCALER_End                                           11
#define JM_FEATURES_FAST_SCALER_Start                                         11
#define JM_FEATURES_FAST_SCALER_Type                                         U01
#define   JM_FEATURES_FAST_SCALER_NONE                                       0x0
#define   JM_FEATURES_FAST_SCALER_AVAILABLE                                  0x1


#define JM_FEATURES_HIGH_DYNAMIC_RANGE                                     12:12
#define JM_FEATURES_HIGH_DYNAMIC_RANGE_End                                    12
#define JM_FEATURES_HIGH_DYNAMIC_RANGE_Start                                  12
#define JM_FEATURES_HIGH_DYNAMIC_RANGE_Type                                  U01
#define   JM_FEATURES_HIGH_DYNAMIC_RANGE_NONE                                0x0
#define   JM_FEATURES_HIGH_DYNAMIC_RANGE_AVAILABLE                           0x1


#define JM_FEATURES_YUV420_TILER                                           13:13
#define JM_FEATURES_YUV420_TILER_End                                          13
#define JM_FEATURES_YUV420_TILER_Start                                        13
#define JM_FEATURES_YUV420_TILER_Type                                        U01
#define   JM_FEATURES_YUV420_TILER_NONE                                      0x0
#define   JM_FEATURES_YUV420_TILER_AVAILABLE                                 0x1


#define JM_FEATURES_MODULE_CG                                              14:14
#define JM_FEATURES_MODULE_CG_End                                             14
#define JM_FEATURES_MODULE_CG_Start                                           14
#define JM_FEATURES_MODULE_CG_Type                                           U01
#define   JM_FEATURES_MODULE_CG_NONE                                         0x0
#define   JM_FEATURES_MODULE_CG_AVAILABLE                                    0x1


#define JM_FEATURES_MIN_AREA                                               15:15
#define JM_FEATURES_MIN_AREA_End                                              15
#define JM_FEATURES_MIN_AREA_Start                                            15
#define JM_FEATURES_MIN_AREA_Type                                            U01
#define   JM_FEATURES_MIN_AREA_NONE                                          0x0
#define   JM_FEATURES_MIN_AREA_AVAILABLE                                     0x1


#define JM_FEATURES_NO_EZ                                                  16:16
#define JM_FEATURES_NO_EZ_End                                                 16
#define JM_FEATURES_NO_EZ_Start                                               16
#define JM_FEATURES_NO_EZ_Type                                               U01
#define   JM_FEATURES_NO_EZ_NONE                                             0x0
#define   JM_FEATURES_NO_EZ_AVAILABLE                                        0x1


#define JM_FEATURES_NO422_TEXTURE                                          17:17
#define JM_FEATURES_NO422_TEXTURE_End                                         17
#define JM_FEATURES_NO422_TEXTURE_Start                                       17
#define JM_FEATURES_NO422_TEXTURE_Type                                       U01
#define   JM_FEATURES_NO422_TEXTURE_NONE                                     0x0
#define   JM_FEATURES_NO422_TEXTURE_AVAILABLE                                0x1


#define JM_FEATURES_BUFFER_INTERLEAVING                                    18:18
#define JM_FEATURES_BUFFER_INTERLEAVING_End                                   18
#define JM_FEATURES_BUFFER_INTERLEAVING_Start                                 18
#define JM_FEATURES_BUFFER_INTERLEAVING_Type                                 U01
#define   JM_FEATURES_BUFFER_INTERLEAVING_NONE                               0x0
#define   JM_FEATURES_BUFFER_INTERLEAVING_AVAILABLE                          0x1


#define JM_FEATURES_BYTE_WRITE_2D                                          19:19
#define JM_FEATURES_BYTE_WRITE_2D_End                                         19
#define JM_FEATURES_BYTE_WRITE_2D_Start                                       19
#define JM_FEATURES_BYTE_WRITE_2D_Type                                       U01
#define   JM_FEATURES_BYTE_WRITE_2D_NONE                                     0x0
#define   JM_FEATURES_BYTE_WRITE_2D_AVAILABLE                                0x1


#define JM_FEATURES_NO_SCALER                                              20:20
#define JM_FEATURES_NO_SCALER_End                                             20
#define JM_FEATURES_NO_SCALER_Start                                           20
#define JM_FEATURES_NO_SCALER_Type                                           U01
#define   JM_FEATURES_NO_SCALER_NONE                                         0x0
#define   JM_FEATURES_NO_SCALER_AVAILABLE                                    0x1


#define JM_FEATURES_YUY2_AVERAGING                                         21:21
#define JM_FEATURES_YUY2_AVERAGING_End                                        21
#define JM_FEATURES_YUY2_AVERAGING_Start                                      21
#define JM_FEATURES_YUY2_AVERAGING_Type                                      U01
#define   JM_FEATURES_YUY2_AVERAGING_NONE                                    0x0
#define   JM_FEATURES_YUY2_AVERAGING_AVAILABLE                               0x1


#define JM_FEATURES_HALF_PE_CACHE                                          22:22
#define JM_FEATURES_HALF_PE_CACHE_End                                         22
#define JM_FEATURES_HALF_PE_CACHE_Start                                       22
#define JM_FEATURES_HALF_PE_CACHE_Type                                       U01
#define   JM_FEATURES_HALF_PE_CACHE_NONE                                     0x0
#define   JM_FEATURES_HALF_PE_CACHE_AVAILABLE                                0x1


#define JM_FEATURES_HALF_TX_CACHE                                          23:23
#define JM_FEATURES_HALF_TX_CACHE_End                                         23
#define JM_FEATURES_HALF_TX_CACHE_Start                                       23
#define JM_FEATURES_HALF_TX_CACHE_Type                                       U01
#define   JM_FEATURES_HALF_TX_CACHE_NONE                                     0x0
#define   JM_FEATURES_HALF_TX_CACHE_AVAILABLE                                0x1


#define JM_FEATURES_YUY2_RENDER_TARGET                                     24:24
#define JM_FEATURES_YUY2_RENDER_TARGET_End                                    24
#define JM_FEATURES_YUY2_RENDER_TARGET_Start                                  24
#define JM_FEATURES_YUY2_RENDER_TARGET_Type                                  U01
#define   JM_FEATURES_YUY2_RENDER_TARGET_NONE                                0x0
#define   JM_FEATURES_YUY2_RENDER_TARGET_AVAILABLE                           0x1


#define JM_FEATURES_MEM32_BIT_SUPPORT                                      25:25
#define JM_FEATURES_MEM32_BIT_SUPPORT_End                                     25
#define JM_FEATURES_MEM32_BIT_SUPPORT_Start                                   25
#define JM_FEATURES_MEM32_BIT_SUPPORT_Type                                   U01
#define   JM_FEATURES_MEM32_BIT_SUPPORT_NONE                                 0x0
#define   JM_FEATURES_MEM32_BIT_SUPPORT_AVAILABLE                            0x1


#define JM_FEATURES_PIPE_VG                                                26:26
#define JM_FEATURES_PIPE_VG_End                                               26
#define JM_FEATURES_PIPE_VG_Start                                             26
#define JM_FEATURES_PIPE_VG_Type                                             U01
#define   JM_FEATURES_PIPE_VG_NONE                                           0x0
#define   JM_FEATURES_PIPE_VG_AVAILABLE                                      0x1


#define JM_FEATURES_VGTS                                                   27:27
#define JM_FEATURES_VGTS_End                                                  27
#define JM_FEATURES_VGTS_Start                                                27
#define JM_FEATURES_VGTS_Type                                                U01
#define   JM_FEATURES_VGTS_NONE                                              0x0
#define   JM_FEATURES_VGTS_AVAILABLE                                         0x1


#define JM_FEATURES_FE20                                                   28:28
#define JM_FEATURES_FE20_End                                                  28
#define JM_FEATURES_FE20_Start                                                28
#define JM_FEATURES_FE20_Type                                                U01
#define   JM_FEATURES_FE20_NONE                                              0x0
#define   JM_FEATURES_FE20_AVAILABLE                                         0x1


#define JM_FEATURES_BYTE_WRITE_3D                                          29:29
#define JM_FEATURES_BYTE_WRITE_3D_End                                         29
#define JM_FEATURES_BYTE_WRITE_3D_Start                                       29
#define JM_FEATURES_BYTE_WRITE_3D_Type                                       U01
#define   JM_FEATURES_BYTE_WRITE_3D_NONE                                     0x0
#define   JM_FEATURES_BYTE_WRITE_3D_AVAILABLE                                0x1


#define JM_FEATURES_RS_YUV_TARGET                                          30:30
#define JM_FEATURES_RS_YUV_TARGET_End                                         30
#define JM_FEATURES_RS_YUV_TARGET_Start                                       30
#define JM_FEATURES_RS_YUV_TARGET_Type                                       U01
#define   JM_FEATURES_RS_YUV_TARGET_NONE                                     0x0
#define   JM_FEATURES_RS_YUV_TARGET_AVAILABLE                                0x1


#define JM_FEATURES_FE20_BIT_INDEX                                         31:31
#define JM_FEATURES_FE20_BIT_INDEX_End                                        31
#define JM_FEATURES_FE20_BIT_INDEX_Start                                      31
#define JM_FEATURES_FE20_BIT_INDEX_Type                                      U01
#define   JM_FEATURES_FE20_BIT_INDEX_NONE                                    0x0
#define   JM_FEATURES_FE20_BIT_INDEX_AVAILABLE                               0x1



#define JMChipIdRegAddrs                                                  0x0008
#define JM_CHIP_ID_Address                                               0x00020
#define JM_CHIP_ID_MSB                                                        15
#define JM_CHIP_ID_LSB                                                         0
#define JM_CHIP_ID_BLK                                                         0
#define JM_CHIP_ID_Count                                                       1
#define JM_CHIP_ID_FieldMask                                          0xFFFFFFFF
#define JM_CHIP_ID_ReadMask                                           0xFFFFFFFF
#define JM_CHIP_ID_WriteMask                                          0x00000000
#define JM_CHIP_ID_ResetValue                                         0x00000000


#define JM_CHIP_ID_ID                                                       31:0
#define JM_CHIP_ID_ID_End                                                     31
#define JM_CHIP_ID_ID_Start                                                    0
#define JM_CHIP_ID_ID_Type                                                   U32



#define JMChipRevRegAddrs                                                 0x0009
#define JM_CHIP_REV_Address                                              0x00024
#define JM_CHIP_REV_MSB                                                       15
#define JM_CHIP_REV_LSB                                                        0
#define JM_CHIP_REV_BLK                                                        0
#define JM_CHIP_REV_Count                                                      1
#define JM_CHIP_REV_FieldMask                                         0xFFFFFFFF
#define JM_CHIP_REV_ReadMask                                          0xFFFFFFFF
#define JM_CHIP_REV_WriteMask                                         0x00000000
#define JM_CHIP_REV_ResetValue                                        0x00000000

#define JM_CHIP_REV_REV                                                     31:0
#define JM_CHIP_REV_REV_End                                                   31
#define JM_CHIP_REV_REV_Start                                                  0
#define JM_CHIP_REV_REV_Type                                                 U32



#define JMChipDateRegAddrs                                                0x000A
#define JM_CHIP_DATE_Address                                             0x00028
#define JM_CHIP_DATE_MSB                                                      15
#define JM_CHIP_DATE_LSB                                                       0
#define JM_CHIP_DATE_BLK                                                       0
#define JM_CHIP_DATE_Count                                                     1
#define JM_CHIP_DATE_FieldMask                                        0xFFFFFFFF
#define JM_CHIP_DATE_ReadMask                                         0xFFFFFFFF
#define JM_CHIP_DATE_WriteMask                                        0x00000000
#define JM_CHIP_DATE_ResetValue                                       0x00000000


#define JM_CHIP_DATE_DATE                                                   31:0
#define JM_CHIP_DATE_DATE_End                                                 31
#define JM_CHIP_DATE_DATE_Start                                                0
#define JM_CHIP_DATE_DATE_Type                                               U32



#define JMChipTimeRegAddrs                                                0x000B
#define JM_CHIP_TIME_Address                                             0x0002C
#define JM_CHIP_TIME_MSB                                                      15
#define JM_CHIP_TIME_LSB                                                       0
#define JM_CHIP_TIME_BLK                                                       0
#define JM_CHIP_TIME_Count                                                     1
#define JM_CHIP_TIME_FieldMask                                        0xFFFFFFFF
#define JM_CHIP_TIME_ReadMask                                         0xFFFFFFFF
#define JM_CHIP_TIME_WriteMask                                        0x00000000
#define JM_CHIP_TIME_ResetValue                                       0x00000000


#define JM_CHIP_TIME_TIME                                                   31:0
#define JM_CHIP_TIME_TIME_End                                                 31
#define JM_CHIP_TIME_TIME_Start                                                0
#define JM_CHIP_TIME_TIME_Type                                               U32



#define JMChipCustomerRegAddrs                                            0x000C
#define JM_CHIP_CUSTOMER_Address                                         0x00030
#define JM_CHIP_CUSTOMER_MSB                                                  15
#define JM_CHIP_CUSTOMER_LSB                                                   0
#define JM_CHIP_CUSTOMER_BLK                                                   0
#define JM_CHIP_CUSTOMER_Count                                                 1
#define JM_CHIP_CUSTOMER_FieldMask                                    0xFFFFFFFF
#define JM_CHIP_CUSTOMER_ReadMask                                     0xFFFFFFFF
#define JM_CHIP_CUSTOMER_WriteMask                                    0x00000000
#define JM_CHIP_CUSTOMER_ResetValue                                   0x00000000


#define JM_CHIP_CUSTOMER_COMPANY                                           31:16
#define JM_CHIP_CUSTOMER_COMPANY_End                                          31
#define JM_CHIP_CUSTOMER_COMPANY_Start                                        16
#define JM_CHIP_CUSTOMER_COMPANY_Type                                        U16


#define JM_CHIP_CUSTOMER_GROUP                                              15:0
#define JM_CHIP_CUSTOMER_GROUP_End                                            15
#define JM_CHIP_CUSTOMER_GROUP_Start                                           0
#define JM_CHIP_CUSTOMER_GROUP_Type                                          U16



#define JMMinorFeatures0RegAddrs                                          0x000D
#define JM_MINOR_FEATURES0_Address                                       0x00034
#define JM_MINOR_FEATURES0_MSB                                                15
#define JM_MINOR_FEATURES0_LSB                                                 0
#define JM_MINOR_FEATURES0_BLK                                                 0
#define JM_MINOR_FEATURES0_Count                                               1
#define JM_MINOR_FEATURES0_FieldMask                                  0xFFFFFFFF
#define JM_MINOR_FEATURES0_ReadMask                                   0xFFFFFFFF
#define JM_MINOR_FEATURES0_WriteMask                                  0x00000000
#define JM_MINOR_FEATURES0_ResetValue                                 0x00000000


#define JM_MINOR_FEATURES0_FLIP_Y                                            0:0
#define JM_MINOR_FEATURES0_FLIP_Y_End                                          0
#define JM_MINOR_FEATURES0_FLIP_Y_Start                                        0
#define JM_MINOR_FEATURES0_FLIP_Y_Type                                       U01
#define   JM_MINOR_FEATURES0_FLIP_Y_NONE                                     0x0
#define   JM_MINOR_FEATURES0_FLIP_Y_AVAILABLE                                0x1


#define JM_MINOR_FEATURES0_DUAL_RETURN_BUS                                   1:1
#define JM_MINOR_FEATURES0_DUAL_RETURN_BUS_End                                 1
#define JM_MINOR_FEATURES0_DUAL_RETURN_BUS_Start                               1
#define JM_MINOR_FEATURES0_DUAL_RETURN_BUS_Type                              U01
#define   JM_MINOR_FEATURES0_DUAL_RETURN_BUS_NONE                            0x0
#define   JM_MINOR_FEATURES0_DUAL_RETURN_BUS_AVAILABLE                       0x1


#define JM_MINOR_FEATURES0_ENDIANNESS_CONFIG                                 2:2
#define JM_MINOR_FEATURES0_ENDIANNESS_CONFIG_End                               2
#define JM_MINOR_FEATURES0_ENDIANNESS_CONFIG_Start                             2
#define JM_MINOR_FEATURES0_ENDIANNESS_CONFIG_Type                            U01
#define   JM_MINOR_FEATURES0_ENDIANNESS_CONFIG_NONE                          0x0
#define   JM_MINOR_FEATURES0_ENDIANNESS_CONFIG_AVAILABLE                     0x1


#define JM_MINOR_FEATURES0_TEXTURE8_K                                        3:3
#define JM_MINOR_FEATURES0_TEXTURE8_K_End                                      3
#define JM_MINOR_FEATURES0_TEXTURE8_K_Start                                    3
#define JM_MINOR_FEATURES0_TEXTURE8_K_Type                                   U01
#define   JM_MINOR_FEATURES0_TEXTURE8_K_NONE                                 0x0
#define   JM_MINOR_FEATURES0_TEXTURE8_K_AVAILABLE                            0x1


#define JM_MINOR_FEATURES0_CORRECT_TEXTURE_CONVERTER                         4:4
#define JM_MINOR_FEATURES0_CORRECT_TEXTURE_CONVERTER_End                       4
#define JM_MINOR_FEATURES0_CORRECT_TEXTURE_CONVERTER_Start                     4
#define JM_MINOR_FEATURES0_CORRECT_TEXTURE_CONVERTER_Type                    U01
#define   JM_MINOR_FEATURES0_CORRECT_TEXTURE_CONVERTER_NONE                  0x0
#define   JM_MINOR_FEATURES0_CORRECT_TEXTURE_CONVERTER_AVAILABLE             0x1


#define JM_MINOR_FEATURES0_SPECIAL_MSAA_LOD                                  5:5
#define JM_MINOR_FEATURES0_SPECIAL_MSAA_LOD_End                                5
#define JM_MINOR_FEATURES0_SPECIAL_MSAA_LOD_Start                              5
#define JM_MINOR_FEATURES0_SPECIAL_MSAA_LOD_Type                             U01
#define   JM_MINOR_FEATURES0_SPECIAL_MSAA_LOD_NONE                           0x0
#define   JM_MINOR_FEATURES0_SPECIAL_MSAA_LOD_AVAILABLE                      0x1


#define JM_MINOR_FEATURES0_FAST_CLEAR_FLUSH                                  6:6
#define JM_MINOR_FEATURES0_FAST_CLEAR_FLUSH_End                                6
#define JM_MINOR_FEATURES0_FAST_CLEAR_FLUSH_Start                              6
#define JM_MINOR_FEATURES0_FAST_CLEAR_FLUSH_Type                             U01
#define   JM_MINOR_FEATURES0_FAST_CLEAR_FLUSH_NONE                           0x0
#define   JM_MINOR_FEATURES0_FAST_CLEAR_FLUSH_AVAILABLE                      0x1


#define JM_MINOR_FEATURES0_2DPE20                                            7:7
#define JM_MINOR_FEATURES0_2DPE20_End                                          7
#define JM_MINOR_FEATURES0_2DPE20_Start                                        7
#define JM_MINOR_FEATURES0_2DPE20_Type                                       U01
#define   JM_MINOR_FEATURES0_2DPE20_NONE                                     0x0
#define   JM_MINOR_FEATURES0_2DPE20_AVAILABLE                                0x1


#define JM_MINOR_FEATURES0_CORRECT_AUTO_DISABLE                              8:8
#define JM_MINOR_FEATURES0_CORRECT_AUTO_DISABLE_End                            8
#define JM_MINOR_FEATURES0_CORRECT_AUTO_DISABLE_Start                          8
#define JM_MINOR_FEATURES0_CORRECT_AUTO_DISABLE_Type                         U01
#define   JM_MINOR_FEATURES0_CORRECT_AUTO_DISABLE_NONE                       0x0
#define   JM_MINOR_FEATURES0_CORRECT_AUTO_DISABLE_AVAILABLE                  0x1


#define JM_MINOR_FEATURES0_RENDER_8K                                         9:9
#define JM_MINOR_FEATURES0_RENDER_8K_End                                       9
#define JM_MINOR_FEATURES0_RENDER_8K_Start                                     9
#define JM_MINOR_FEATURES0_RENDER_8K_Type                                    U01
#define   JM_MINOR_FEATURES0_RENDER_8K_NONE                                  0x0
#define   JM_MINOR_FEATURES0_RENDER_8K_AVAILABLE                             0x1


#define JM_MINOR_FEATURES0_TILE_STATUS_2BITS                               10:10
#define JM_MINOR_FEATURES0_TILE_STATUS_2BITS_End                              10
#define JM_MINOR_FEATURES0_TILE_STATUS_2BITS_Start                            10
#define JM_MINOR_FEATURES0_TILE_STATUS_2BITS_Type                            U01
#define   JM_MINOR_FEATURES0_TILE_STATUS_2BITS_NONE                          0x0
#define   JM_MINOR_FEATURES0_TILE_STATUS_2BITS_AVAILABLE                     0x1


#define JM_MINOR_FEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED           11:11
#define JM_MINOR_FEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_End          11
#define JM_MINOR_FEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_Start        11
#define JM_MINOR_FEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_Type        U01
#define   JM_MINOR_FEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_NONE      0x0
#define   JM_MINOR_FEATURES0_SEPARATE_TILE_STATUS_WHEN_INTERLEAVED_AVAILABLE 0x1


#define JM_MINOR_FEATURES0_SUPER_TILED_32X32                               12:12
#define JM_MINOR_FEATURES0_SUPER_TILED_32X32_End                              12
#define JM_MINOR_FEATURES0_SUPER_TILED_32X32_Start                            12
#define JM_MINOR_FEATURES0_SUPER_TILED_32X32_Type                            U01
#define   JM_MINOR_FEATURES0_SUPER_TILED_32X32_NONE                          0x0
#define   JM_MINOR_FEATURES0_SUPER_TILED_32X32_AVAILABLE                     0x1


#define JM_MINOR_FEATURES0_VG_20                                           13:13
#define JM_MINOR_FEATURES0_VG_20_End                                          13
#define JM_MINOR_FEATURES0_VG_20_Start                                        13
#define JM_MINOR_FEATURES0_VG_20_Type                                        U01
#define   JM_MINOR_FEATURES0_VG_20_NONE                                      0x0
#define   JM_MINOR_FEATURES0_VG_20_AVAILABLE                                 0x1


#define JM_MINOR_FEATURES0_TS_EXTENDED_COMMANDS                            14:14
#define JM_MINOR_FEATURES0_TS_EXTENDED_COMMANDS_End                           14
#define JM_MINOR_FEATURES0_TS_EXTENDED_COMMANDS_Start                         14
#define JM_MINOR_FEATURES0_TS_EXTENDED_COMMANDS_Type                         U01
#define   JM_MINOR_FEATURES0_TS_EXTENDED_COMMANDS_NONE                       0x0
#define   JM_MINOR_FEATURES0_TS_EXTENDED_COMMANDS_AVAILABLE                  0x1

#define JM_MINOR_FEATURES0_COMPRESSION_FIFO_FIXED                          15:15
#define JM_MINOR_FEATURES0_COMPRESSION_FIFO_FIXED_End                         15
#define JM_MINOR_FEATURES0_COMPRESSION_FIFO_FIXED_Start                       15
#define JM_MINOR_FEATURES0_COMPRESSION_FIFO_FIXED_Type                       U01
#define   JM_MINOR_FEATURES0_COMPRESSION_FIFO_FIXED_NONE                     0x0
#define   JM_MINOR_FEATURES0_COMPRESSION_FIFO_FIXED_AVAILABLE                0x1


#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS0                      16:16
#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS0_End                     16
#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS0_Start                   16
#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS0_Type                   U01
#define   JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS0_NONE                 0x0
#define   JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS0_AVAILABLE            0x1


#define JM_MINOR_FEATURES0_VG_FILTER                                       17:17
#define JM_MINOR_FEATURES0_VG_FILTER_End                                      17
#define JM_MINOR_FEATURES0_VG_FILTER_Start                                    17
#define JM_MINOR_FEATURES0_VG_FILTER_Type                                    U01
#define   JM_MINOR_FEATURES0_VG_FILTER_NONE                                  0x0
#define   JM_MINOR_FEATURES0_VG_FILTER_AVAILABLE                             0x1

#define JM_MINOR_FEATURES0_VG_21                                           18:18
#define JM_MINOR_FEATURES0_VG_21_End                                          18
#define JM_MINOR_FEATURES0_VG_21_Start                                        18
#define JM_MINOR_FEATURES0_VG_21_Type                                        U01
#define   JM_MINOR_FEATURES0_VG_21_NONE                                      0x0
#define   JM_MINOR_FEATURES0_VG_21_AVAILABLE                                 0x1


#define JM_MINOR_FEATURES0_SHADER_GETS_W                                   19:19
#define JM_MINOR_FEATURES0_SHADER_GETS_W_End                                  19
#define JM_MINOR_FEATURES0_SHADER_GETS_W_Start                                19
#define JM_MINOR_FEATURES0_SHADER_GETS_W_Type                                U01
#define   JM_MINOR_FEATURES0_SHADER_GETS_W_NONE                              0x0
#define   JM_MINOR_FEATURES0_SHADER_GETS_W_AVAILABLE                         0x1


#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS1                      20:20
#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS1_End                     20
#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS1_Start                   20
#define JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS1_Type                   U01
#define   JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS1_NONE                 0x0
#define   JM_MINOR_FEATURES0_EXTRA_SHADER_INSTRUCTIONS1_AVAILABLE            0x1


#define JM_MINOR_FEATURES0_DEFAULT_REG0                                    21:21
#define JM_MINOR_FEATURES0_DEFAULT_REG0_End                                   21
#define JM_MINOR_FEATURES0_DEFAULT_REG0_Start                                 21
#define JM_MINOR_FEATURES0_DEFAULT_REG0_Type                                 U01
#define   JM_MINOR_FEATURES0_DEFAULT_REG0_NONE                               0x0
#define   JM_MINOR_FEATURES0_DEFAULT_REG0_AVAILABLE                          0x1


#define JM_MINOR_FEATURES0_MC_20                                           22:22
#define JM_MINOR_FEATURES0_MC_20_End                                          22
#define JM_MINOR_FEATURES0_MC_20_Start                                        22
#define JM_MINOR_FEATURES0_MC_20_Type                                        U01
#define   JM_MINOR_FEATURES0_MC_20_NONE                                      0x0
#define   JM_MINOR_FEATURES0_MC_20_AVAILABLE                                 0x1


#define JM_MINOR_FEATURES0_SHADER_MSAA_SIDEBAND                            23:23
#define JM_MINOR_FEATURES0_SHADER_MSAA_SIDEBAND_End                           23
#define JM_MINOR_FEATURES0_SHADER_MSAA_SIDEBAND_Start                         23
#define JM_MINOR_FEATURES0_SHADER_MSAA_SIDEBAND_Type                         U01
#define   JM_MINOR_FEATURES0_SHADER_MSAA_SIDEBAND_NONE                       0x0
#define   JM_MINOR_FEATURES0_SHADER_MSAA_SIDEBAND_AVAILABLE                  0x1

#define JM_MINOR_FEATURES0_BUG_FIXES0                                      24:24
#define JM_MINOR_FEATURES0_BUG_FIXES0_End                                     24
#define JM_MINOR_FEATURES0_BUG_FIXES0_Start                                   24
#define JM_MINOR_FEATURES0_BUG_FIXES0_Type                                   U01
#define   JM_MINOR_FEATURES0_BUG_FIXES0_NONE                                 0x0
#define   JM_MINOR_FEATURES0_BUG_FIXES0_AVAILABLE                            0x1


#define JM_MINOR_FEATURES0_VAA                                             25:25
#define JM_MINOR_FEATURES0_VAA_End                                            25
#define JM_MINOR_FEATURES0_VAA_Start                                          25
#define JM_MINOR_FEATURES0_VAA_Type                                          U01
#define   JM_MINOR_FEATURES0_VAA_NONE                                        0x0
#define   JM_MINOR_FEATURES0_VAA_AVAILABLE                                   0x1


#define JM_MINOR_FEATURES0_BYPASS_IN_MSAA                                  26:26
#define JM_MINOR_FEATURES0_BYPASS_IN_MSAA_End                                 26
#define JM_MINOR_FEATURES0_BYPASS_IN_MSAA_Start                               26
#define JM_MINOR_FEATURES0_BYPASS_IN_MSAA_Type                               U01
#define   JM_MINOR_FEATURES0_BYPASS_IN_MSAA_NONE                             0x0
#define   JM_MINOR_FEATURES0_BYPASS_IN_MSAA_AVAILABLE                        0x1


#define JM_MINOR_FEATURES0_HIERARCHICAL_Z                                  27:27
#define JM_MINOR_FEATURES0_HIERARCHICAL_Z_End                                 27
#define JM_MINOR_FEATURES0_HIERARCHICAL_Z_Start                               27
#define JM_MINOR_FEATURES0_HIERARCHICAL_Z_Type                               U01
#define   JM_MINOR_FEATURES0_HIERARCHICAL_Z_NONE                             0x0
#define   JM_MINOR_FEATURES0_HIERARCHICAL_Z_AVAILABLE                        0x1


#define JM_MINOR_FEATURES0_NEW_TEXTURE                                     28:28
#define JM_MINOR_FEATURES0_NEW_TEXTURE_End                                    28
#define JM_MINOR_FEATURES0_NEW_TEXTURE_Start                                  28
#define JM_MINOR_FEATURES0_NEW_TEXTURE_Type                                  U01
#define   JM_MINOR_FEATURES0_NEW_TEXTURE_NONE                                0x0
#define   JM_MINOR_FEATURES0_NEW_TEXTURE_AVAILABLE                           0x1


#define JM_MINOR_FEATURES0_A8_TARGET_SUPPORT                               29:29
#define JM_MINOR_FEATURES0_A8_TARGET_SUPPORT_End                              29
#define JM_MINOR_FEATURES0_A8_TARGET_SUPPORT_Start                            29
#define JM_MINOR_FEATURES0_A8_TARGET_SUPPORT_Type                            U01
#define   JM_MINOR_FEATURES0_A8_TARGET_SUPPORT_NONE                          0x0
#define   JM_MINOR_FEATURES0_A8_TARGET_SUPPORT_AVAILABLE                     0x1


#define JM_MINOR_FEATURES0_CORRECT_STENCIL                                 30:30
#define JM_MINOR_FEATURES0_CORRECT_STENCIL_End                                30
#define JM_MINOR_FEATURES0_CORRECT_STENCIL_Start                              30
#define JM_MINOR_FEATURES0_CORRECT_STENCIL_Type                              U01
#define   JM_MINOR_FEATURES0_CORRECT_STENCIL_NONE                            0x0
#define   JM_MINOR_FEATURES0_CORRECT_STENCIL_AVAILABLE                       0x1

#define JM_MINOR_FEATURES0_ENHANCE_VR                                      31:31
#define JM_MINOR_FEATURES0_ENHANCE_VR_End                                     31
#define JM_MINOR_FEATURES0_ENHANCE_VR_Start                                   31
#define JM_MINOR_FEATURES0_ENHANCE_VR_Type                                   U01
#define   JM_MINOR_FEATURES0_ENHANCE_VR_NONE                                 0x0
#define   JM_MINOR_FEATURES0_ENHANCE_VR_AVAILABLE                            0x1




#define JMCacheControlRegAddrs                                            0x000E
#define JM_CACHE_CONTROL_Address                                         0x00038
#define JM_CACHE_CONTROL_MSB                                                  15
#define JM_CACHE_CONTROL_LSB                                                   0
#define JM_CACHE_CONTROL_BLK                                                   0
#define JM_CACHE_CONTROL_Count                                                 1
#define JM_CACHE_CONTROL_FieldMask                                    0xFFFFFFFF
#define JM_CACHE_CONTROL_ReadMask                                     0xFFFFFFFF
#define JM_CACHE_CONTROL_WriteMask                                    0xFFFFFFFF
#define JM_CACHE_CONTROL_ResetValue                                   0x00000000

#define JM_CACHE_CONTROL_NOT_USED                                           31:0
#define JM_CACHE_CONTROL_NOT_USED_End                                         31
#define JM_CACHE_CONTROL_NOT_USED_Start                                        0
#define JM_CACHE_CONTROL_NOT_USED_Type                                       U32



#define JMResetMemCountersRegAddrs                                        0x000F
#define JM_RESET_MEM_COUNTERS_Address                                    0x0003C
#define JM_RESET_MEM_COUNTERS_MSB                                             15
#define JM_RESET_MEM_COUNTERS_LSB                                              0
#define JM_RESET_MEM_COUNTERS_BLK                                              0
#define JM_RESET_MEM_COUNTERS_Count                                            1
#define JM_RESET_MEM_COUNTERS_FieldMask                               0x00000001
#define JM_RESET_MEM_COUNTERS_ReadMask                                0x00000000
#define JM_RESET_MEM_COUNTERS_WriteMask                               0x00000001
#define JM_RESET_MEM_COUNTERS_ResetValue                              0x00000000


#define JM_RESET_MEM_COUNTERS_RESET                                          0:0
#define JM_RESET_MEM_COUNTERS_RESET_End                                        0
#define JM_RESET_MEM_COUNTERS_RESET_Start                                      0
#define JM_RESET_MEM_COUNTERS_RESET_Type                                     U01




#define jmTotalReadsRegAddrs                                              0x0010
#define JM_TOTAL_READS_Address                                           0x00040
#define JM_TOTAL_READS_MSB                                                    15
#define JM_TOTAL_READS_LSB                                                     0
#define JM_TOTAL_READS_BLK                                                     0
#define JM_TOTAL_READS_Count                                                   1
#define JM_TOTAL_READS_FieldMask                                      0xFFFFFFFF
#define JM_TOTAL_READS_ReadMask                                       0xFFFFFFFF
#define JM_TOTAL_READS_WriteMask                                      0x00000000
#define JM_TOTAL_READS_ResetValue                                     0x00000000


#define JM_TOTAL_READS_COUNT                                                31:0
#define JM_TOTAL_READS_COUNT_End                                              31
#define JM_TOTAL_READS_COUNT_Start                                             0
#define JM_TOTAL_READS_COUNT_Type                                            U32




#define jmTotalWritesRegAddrs                                             0x0011
#define JM_TOTAL_WRITES_Address                                          0x00044
#define JM_TOTAL_WRITES_MSB                                                   15
#define JM_TOTAL_WRITES_LSB                                                    0
#define JM_TOTAL_WRITES_BLK                                                    0
#define JM_TOTAL_WRITES_Count                                                  1
#define JM_TOTAL_WRITES_FieldMask                                     0xFFFFFFFF
#define JM_TOTAL_WRITES_ReadMask                                      0xFFFFFFFF
#define JM_TOTAL_WRITES_WriteMask                                     0x00000000
#define JM_TOTAL_WRITES_ResetValue                                    0x00000000


#define JM_TOTAL_WRITES_COUNT                                               31:0
#define JM_TOTAL_WRITES_COUNT_End                                             31
#define JM_TOTAL_WRITES_COUNT_Start                                            0
#define JM_TOTAL_WRITES_COUNT_Type                                           U32



#define jmChipSpecsRegAddrs                                               0x0012
#define JM_CHIP_SPECS_Address                                            0x00048
#define JM_CHIP_SPECS_MSB                                                     15
#define JM_CHIP_SPECS_LSB                                                      0
#define JM_CHIP_SPECS_BLK                                                      0
#define JM_CHIP_SPECS_Count                                                    1
#define JM_CHIP_SPECS_FieldMask                                       0xFFF1FFFF
#define JM_CHIP_SPECS_ReadMask                                        0xFFF1FFFF
#define JM_CHIP_SPECS_WriteMask                                       0x00000000
#define JM_CHIP_SPECS_ResetValue                                      0x00000000

#define JM_CHIP_SPECS_STREAMS                                                3:0
#define JM_CHIP_SPECS_STREAMS_End                                              3
#define JM_CHIP_SPECS_STREAMS_Start                                            0
#define JM_CHIP_SPECS_STREAMS_Type                                           U04


#define JM_CHIP_SPECS_TEMP_REGISTERS                                         7:4
#define JM_CHIP_SPECS_TEMP_REGISTERS_End                                       7
#define JM_CHIP_SPECS_TEMP_REGISTERS_Start                                     4
#define JM_CHIP_SPECS_TEMP_REGISTERS_Type                                    U04


#define JM_CHIP_SPECS_THREAD_COUNT                                          11:8
#define JM_CHIP_SPECS_THREAD_COUNT_End                                        11
#define JM_CHIP_SPECS_THREAD_COUNT_Start                                       8
#define JM_CHIP_SPECS_THREAD_COUNT_Type                                      U04


#define JM_CHIP_SPECS_VERTEX_CACHE_SIZE                                    16:12
#define JM_CHIP_SPECS_VERTEX_CACHE_SIZE_End                                   16
#define JM_CHIP_SPECS_VERTEX_CACHE_SIZE_Start                                 12
#define JM_CHIP_SPECS_VERTEX_CACHE_SIZE_Type                                 U05


#define JM_CHIP_SPECS_NUM_SHADER_CORES                                     24:20
#define JM_CHIP_SPECS_NUM_SHADER_CORES_End                                    24
#define JM_CHIP_SPECS_NUM_SHADER_CORES_Start                                  20
#define JM_CHIP_SPECS_NUM_SHADER_CORES_Type                                  U05

#define JM_CHIP_SPECS_NUM_PIXEL_PIPES                                      27:25
#define JM_CHIP_SPECS_NUM_PIXEL_PIPES_End                                     27
#define JM_CHIP_SPECS_NUM_PIXEL_PIPES_Start                                   25
#define JM_CHIP_SPECS_NUM_PIXEL_PIPES_Type                                   U03


#define JM_CHIP_SPECS_VERTEX_OUTPUT_BUFFER_SIZE                            31:28
#define JM_CHIP_SPECS_VERTEX_OUTPUT_BUFFER_SIZE_End                           31
#define JM_CHIP_SPECS_VERTEX_OUTPUT_BUFFER_SIZE_Start                         28
#define JM_CHIP_SPECS_VERTEX_OUTPUT_BUFFER_SIZE_Type                         U04



#define jmTotalWriteBurstsRegAddrs                                        0x0013
#define JM_TOTAL_WRITE_BURSTS_Address                                    0x0004C
#define JM_TOTAL_WRITE_BURSTS_MSB                                             15
#define JM_TOTAL_WRITE_BURSTS_LSB                                              0
#define JM_TOTAL_WRITE_BURSTS_BLK                                              0
#define JM_TOTAL_WRITE_BURSTS_Count                                            1
#define JM_TOTAL_WRITE_BURSTS_FieldMask                               0xFFFFFFFF
#define JM_TOTAL_WRITE_BURSTS_ReadMask                                0xFFFFFFFF
#define JM_TOTAL_WRITE_BURSTS_WriteMask                               0x00000000
#define JM_TOTAL_WRITE_BURSTS_ResetValue                              0x00000000


#define JM_TOTAL_WRITE_BURSTS_COUNT                                         31:0
#define JM_TOTAL_WRITE_BURSTS_COUNT_End                                       31
#define JM_TOTAL_WRITE_BURSTS_COUNT_Start                                      0
#define JM_TOTAL_WRITE_BURSTS_COUNT_Type                                     U32




#define jmTotalWriteReqsRegAddrs                                          0x0014
#define JM_TOTAL_WRITE_REQS_Address                                      0x00050
#define JM_TOTAL_WRITE_REQS_MSB                                               15
#define JM_TOTAL_WRITE_REQS_LSB                                                0
#define JM_TOTAL_WRITE_REQS_BLK                                                0
#define JM_TOTAL_WRITE_REQS_Count                                              1
#define JM_TOTAL_WRITE_REQS_FieldMask                                 0xFFFFFFFF
#define JM_TOTAL_WRITE_REQS_ReadMask                                  0xFFFFFFFF
#define JM_TOTAL_WRITE_REQS_WriteMask                                 0x00000000
#define JM_TOTAL_WRITE_REQS_ResetValue                                0x00000000


#define JM_TOTAL_WRITE_REQS_COUNT                                           31:0
#define JM_TOTAL_WRITE_REQS_COUNT_End                                         31
#define JM_TOTAL_WRITE_REQS_COUNT_Start                                        0
#define JM_TOTAL_WRITE_REQS_COUNT_Type                                       U32



#define jmTotalWriteLastsRegAddrs                                         0x0015
#define JM_TOTAL_WRITE_LASTS_Address                                     0x00054
#define JM_TOTAL_WRITE_LASTS_MSB                                              15
#define JM_TOTAL_WRITE_LASTS_LSB                                               0
#define JM_TOTAL_WRITE_LASTS_BLK                                               0
#define JM_TOTAL_WRITE_LASTS_Count                                             1
#define JM_TOTAL_WRITE_LASTS_FieldMask                                0xFFFFFFFF
#define JM_TOTAL_WRITE_LASTS_ReadMask                                 0xFFFFFFFF
#define JM_TOTAL_WRITE_LASTS_WriteMask                                0x00000000
#define JM_TOTAL_WRITE_LASTS_ResetValue                               0x00000000


#define JM_TOTAL_WRITE_LASTS_COUNT                                          31:0
#define JM_TOTAL_WRITE_LASTS_COUNT_End                                        31
#define JM_TOTAL_WRITE_LASTS_COUNT_Start                                       0
#define JM_TOTAL_WRITE_LASTS_COUNT_Type                                      U32



#define jmTotalReadBurstsRegAddrs                                         0x0016
#define JM_TOTAL_READ_BURSTS_Address                                     0x00058
#define JM_TOTAL_READ_BURSTS_MSB                                              15
#define JM_TOTAL_READ_BURSTS_LSB                                               0
#define JM_TOTAL_READ_BURSTS_BLK                                               0
#define JM_TOTAL_READ_BURSTS_Count                                             1
#define JM_TOTAL_READ_BURSTS_FieldMask                                0xFFFFFFFF
#define JM_TOTAL_READ_BURSTS_ReadMask                                 0xFFFFFFFF
#define JM_TOTAL_READ_BURSTS_WriteMask                                0x00000000
#define JM_TOTAL_READ_BURSTS_ResetValue                               0x00000000


#define JM_TOTAL_READ_BURSTS_COUNT                                          31:0
#define JM_TOTAL_READ_BURSTS_COUNT_End                                        31
#define JM_TOTAL_READ_BURSTS_COUNT_Start                                       0
#define JM_TOTAL_READ_BURSTS_COUNT_Type                                      U32




#define jmTotalReadReqsRegAddrs                                           0x0017
#define JM_TOTAL_READ_REQS_Address                                       0x0005C
#define JM_TOTAL_READ_REQS_MSB                                                15
#define JM_TOTAL_READ_REQS_LSB                                                 0
#define JM_TOTAL_READ_REQS_BLK                                                 0
#define JM_TOTAL_READ_REQS_Count                                               1
#define JM_TOTAL_READ_REQS_FieldMask                                  0xFFFFFFFF
#define JM_TOTAL_READ_REQS_ReadMask                                   0xFFFFFFFF
#define JM_TOTAL_READ_REQS_WriteMask                                  0x00000000
#define JM_TOTAL_READ_REQS_ResetValue                                 0x00000000


#define JM_TOTAL_READ_REQS_COUNT                                            31:0
#define JM_TOTAL_READ_REQS_COUNT_End                                          31
#define JM_TOTAL_READ_REQS_COUNT_Start                                         0
#define JM_TOTAL_READ_REQS_COUNT_Type                                        U32



#define jmTotalReadLastsRegAddrs                                          0x0018
#define JM_TOTAL_READ_LASTS_Address                                      0x00060
#define JM_TOTAL_READ_LASTS_MSB                                               15
#define JM_TOTAL_READ_LASTS_LSB                                                0
#define JM_TOTAL_READ_LASTS_BLK                                                0
#define JM_TOTAL_READ_LASTS_Count                                              1
#define JM_TOTAL_READ_LASTS_FieldMask                                 0xFFFFFFFF
#define JM_TOTAL_READ_LASTS_ReadMask                                  0xFFFFFFFF
#define JM_TOTAL_READ_LASTS_WriteMask                                 0x00000000
#define JM_TOTAL_READ_LASTS_ResetValue                                0x00000000


#define JM_TOTAL_READ_LASTS_COUNT                                           31:0
#define JM_TOTAL_READ_LASTS_COUNT_End                                         31
#define JM_TOTAL_READ_LASTS_COUNT_Start                                        0
#define JM_TOTAL_READ_LASTS_COUNT_Type                                       U32




#define jmGpOut0RegAddrs                                                  0x0019
#define JM_GP_OUT0_Address                                               0x00064
#define JM_GP_OUT0_MSB                                                        15
#define JM_GP_OUT0_LSB                                                         0
#define JM_GP_OUT0_BLK                                                         0
#define JM_GP_OUT0_Count                                                       1
#define JM_GP_OUT0_FieldMask                                          0xFFFFFFFF
#define JM_GP_OUT0_ReadMask                                           0xFFFFFFFF
#define JM_GP_OUT0_WriteMask                                          0xFFFFFFFF
#define JM_GP_OUT0_ResetValue                                         0x00000000

#define JM_GP_OUT0_COUNT                                                    31:0
#define JM_GP_OUT0_COUNT_End                                                  31
#define JM_GP_OUT0_COUNT_Start                                                 0
#define JM_GP_OUT0_COUNT_Type                                                U32




#define jmGpOut1RegAddrs                                                  0x001A
#define JM_GP_OUT1_Address                                               0x00068
#define JM_GP_OUT1_MSB                                                        15
#define JM_GP_OUT1_LSB                                                         0
#define JM_GP_OUT1_BLK                                                         0
#define JM_GP_OUT1_Count                                                       1
#define JM_GP_OUT1_FieldMask                                          0xFFFFFFFF
#define JM_GP_OUT1_ReadMask                                           0xFFFFFFFF
#define JM_GP_OUT1_WriteMask                                          0xFFFFFFFF
#define JM_GP_OUT1_ResetValue                                         0x00000000

#define JM_GP_OUT1_COUNT                                                    31:0
#define JM_GP_OUT1_COUNT_End                                                  31
#define JM_GP_OUT1_COUNT_Start                                                 0
#define JM_GP_OUT1_COUNT_Type                                                U32




#define jmGpOut2RegAddrs                                                  0x001B
#define JM_GP_OUT2_Address                                               0x0006C
#define JM_GP_OUT2_MSB                                                        15
#define JM_GP_OUT2_LSB                                                         0
#define JM_GP_OUT2_BLK                                                         0
#define JM_GP_OUT2_Count                                                       1
#define JM_GP_OUT2_FieldMask                                          0xFFFFFFFF
#define JM_GP_OUT2_ReadMask                                           0xFFFFFFFF
#define JM_GP_OUT2_WriteMask                                          0xFFFFFFFF
#define JM_GP_OUT2_ResetValue                                         0x00000000

#define JM_GP_OUT2_COUNT                                                    31:0
#define JM_GP_OUT2_COUNT_End                                                  31
#define JM_GP_OUT2_COUNT_Start                                                 0
#define JM_GP_OUT2_COUNT_Type                                                U32




#define jmAxiControlRegAddrs                                              0x001C
#define JM_AXI_CONTROL_Address                                           0x00070
#define JM_AXI_CONTROL_MSB                                                    15
#define JM_AXI_CONTROL_LSB                                                     0
#define JM_AXI_CONTROL_BLK                                                     0
#define JM_AXI_CONTROL_Count                                                   1
#define JM_AXI_CONTROL_FieldMask                                      0x0000001F
#define JM_AXI_CONTROL_ReadMask                                       0x0000001F
#define JM_AXI_CONTROL_WriteMask                                      0x0000001F
#define JM_AXI_CONTROL_ResetValue                                     0x00000000


#define JM_AXI_CONTROL_WR_FULL_BURST_MODE                                    0:0
#define JM_AXI_CONTROL_WR_FULL_BURST_MODE_End                                  0
#define JM_AXI_CONTROL_WR_FULL_BURST_MODE_Start                                0
#define JM_AXI_CONTROL_WR_FULL_BURST_MODE_Type                               U01
#define   JM_AXI_CONTROL_WR_FULL_BURST_MODE_NO_BURST_RESET_VALUE             0x0
#define   JM_AXI_CONTROL_WR_FULL_BURST_MODE_BURST_RESET_VALUE                0x1

#define JM_AXI_CONTROL_SPLIT_SIZE                                            3:1
#define JM_AXI_CONTROL_SPLIT_SIZE_End                                          3
#define JM_AXI_CONTROL_SPLIT_SIZE_Start                                        1
#define JM_AXI_CONTROL_SPLIT_SIZE_Type                                       U03
#define   JM_AXI_CONTROL_SPLIT_SIZE_DISABLED                                 0x0
#define   JM_AXI_CONTROL_SPLIT_SIZE_BYTE64                                   0x1
#define   JM_AXI_CONTROL_SPLIT_SIZE_BYTE128                                  0x2
#define   JM_AXI_CONTROL_SPLIT_SIZE_BYTE256                                  0x3
#define   JM_AXI_CONTROL_SPLIT_SIZE_BYTE512                                  0x4
#define   JM_AXI_CONTROL_SPLIT_SIZE_BYTE1024                                 0x5
#define   JM_AXI_CONTROL_SPLIT_SIZE_BUS0                                     0x6
#define   JM_AXI_CONTROL_SPLIT_SIZE_BUS1                                     0x7


#define JM_AXI_CONTROL_DISABLE_FE_SPLIT_REQUESTS                             4:4
#define JM_AXI_CONTROL_DISABLE_FE_SPLIT_REQUESTS_End                           4
#define JM_AXI_CONTROL_DISABLE_FE_SPLIT_REQUESTS_Start                         4
#define JM_AXI_CONTROL_DISABLE_FE_SPLIT_REQUESTS_Type                        U01



#define JMMinorFeatures1RegAddrs                                          0x001D
#define JM_MINOR_FEATURES1_Address                                       0x00074
#define JM_MINOR_FEATURES1_MSB                                                15
#define JM_MINOR_FEATURES1_LSB                                                 0
#define JM_MINOR_FEATURES1_BLK                                                 0
#define JM_MINOR_FEATURES1_Count                                               1
#define JM_MINOR_FEATURES1_FieldMask                                  0xFFFFFFFF
#define JM_MINOR_FEATURES1_ReadMask                                   0xFFFFFFFF
#define JM_MINOR_FEATURES1_WriteMask                                  0x00000000
#define JM_MINOR_FEATURES1_ResetValue                                 0x00000000


#define JM_MINOR_FEATURES1_RSUV_SWIZZLE                                      0:0
#define JM_MINOR_FEATURES1_RSUV_SWIZZLE_End                                    0
#define JM_MINOR_FEATURES1_RSUV_SWIZZLE_Start                                  0
#define JM_MINOR_FEATURES1_RSUV_SWIZZLE_Type                                 U01
#define   JM_MINOR_FEATURES1_RSUV_SWIZZLE_NONE                               0x0
#define   JM_MINOR_FEATURES1_RSUV_SWIZZLE_AVAILABLE                          0x1


#define JM_MINOR_FEATURES1_V2_COMPRESSION                                    1:1
#define JM_MINOR_FEATURES1_V2_COMPRESSION_End                                  1
#define JM_MINOR_FEATURES1_V2_COMPRESSION_Start                                1
#define JM_MINOR_FEATURES1_V2_COMPRESSION_Type                               U01
#define   JM_MINOR_FEATURES1_V2_COMPRESSION_NONE                             0x0
#define   JM_MINOR_FEATURES1_V2_COMPRESSION_AVAILABLE                        0x1


#define JM_MINOR_FEATURES1_VG_DOUBLE_BUFFER                                  2:2
#define JM_MINOR_FEATURES1_VG_DOUBLE_BUFFER_End                                2
#define JM_MINOR_FEATURES1_VG_DOUBLE_BUFFER_Start                              2
#define JM_MINOR_FEATURES1_VG_DOUBLE_BUFFER_Type                             U01
#define   JM_MINOR_FEATURES1_VG_DOUBLE_BUFFER_NONE                           0x0
#define   JM_MINOR_FEATURES1_VG_DOUBLE_BUFFER_AVAILABLE                      0x1

#define JM_MINOR_FEATURES1_BUG_FIXES1                                        3:3
#define JM_MINOR_FEATURES1_BUG_FIXES1_End                                      3
#define JM_MINOR_FEATURES1_BUG_FIXES1_Start                                    3
#define JM_MINOR_FEATURES1_BUG_FIXES1_Type                                   U01
#define   JM_MINOR_FEATURES1_BUG_FIXES1_NONE                                 0x0
#define   JM_MINOR_FEATURES1_BUG_FIXES1_AVAILABLE                            0x1

#define JM_MINOR_FEATURES1_BUG_FIXES2                                        4:4
#define JM_MINOR_FEATURES1_BUG_FIXES2_End                                      4
#define JM_MINOR_FEATURES1_BUG_FIXES2_Start                                    4
#define JM_MINOR_FEATURES1_BUG_FIXES2_Type                                   U01
#define   JM_MINOR_FEATURES1_BUG_FIXES2_NONE                                 0x0
#define   JM_MINOR_FEATURES1_BUG_FIXES2_AVAILABLE                            0x1


#define JM_MINOR_FEATURES1_TEXTURE_STRIDE                                    5:5
#define JM_MINOR_FEATURES1_TEXTURE_STRIDE_End                                  5
#define JM_MINOR_FEATURES1_TEXTURE_STRIDE_Start                                5
#define JM_MINOR_FEATURES1_TEXTURE_STRIDE_Type                               U01
#define   JM_MINOR_FEATURES1_TEXTURE_STRIDE_NONE                             0x0
#define   JM_MINOR_FEATURES1_TEXTURE_STRIDE_AVAILABLE                        0x1

#define JM_MINOR_FEATURES1_BUG_FIXES3                                        6:6
#define JM_MINOR_FEATURES1_BUG_FIXES3_End                                      6
#define JM_MINOR_FEATURES1_BUG_FIXES3_Start                                    6
#define JM_MINOR_FEATURES1_BUG_FIXES3_Type                                   U01
#define   JM_MINOR_FEATURES1_BUG_FIXES3_NONE                                 0x0
#define   JM_MINOR_FEATURES1_BUG_FIXES3_AVAILABLE                            0x1

#define JM_MINOR_FEATURES1_CORRECT_AUTO_DISABLE                              7:7
#define JM_MINOR_FEATURES1_CORRECT_AUTO_DISABLE_End                            7
#define JM_MINOR_FEATURES1_CORRECT_AUTO_DISABLE_Start                          7
#define JM_MINOR_FEATURES1_CORRECT_AUTO_DISABLE_Type                         U01
#define   JM_MINOR_FEATURES1_CORRECT_AUTO_DISABLE_NONE                       0x0
#define   JM_MINOR_FEATURES1_CORRECT_AUTO_DISABLE_AVAILABLE                  0x1

#define JM_MINOR_FEATURES1_AUTO_RESTART_TS                                   8:8
#define JM_MINOR_FEATURES1_AUTO_RESTART_TS_End                                 8
#define JM_MINOR_FEATURES1_AUTO_RESTART_TS_Start                               8
#define JM_MINOR_FEATURES1_AUTO_RESTART_TS_Type                              U01
#define   JM_MINOR_FEATURES1_AUTO_RESTART_TS_NONE                            0x0
#define   JM_MINOR_FEATURES1_AUTO_RESTART_TS_AVAILABLE                       0x1

#define JM_MINOR_FEATURES1_BUG_FIXES4                                        9:9
#define JM_MINOR_FEATURES1_BUG_FIXES4_End                                      9
#define JM_MINOR_FEATURES1_BUG_FIXES4_Start                                    9
#define JM_MINOR_FEATURES1_BUG_FIXES4_Type                                   U01
#define   JM_MINOR_FEATURES1_BUG_FIXES4_NONE                                 0x0
#define   JM_MINOR_FEATURES1_BUG_FIXES4_AVAILABLE                            0x1

#define JM_MINOR_FEATURES1_L2_WINDOWING                                    10:10
#define JM_MINOR_FEATURES1_L2_WINDOWING_End                                   10
#define JM_MINOR_FEATURES1_L2_WINDOWING_Start                                 10
#define JM_MINOR_FEATURES1_L2_WINDOWING_Type                                 U01
#define   JM_MINOR_FEATURES1_L2_WINDOWING_NONE                               0x0
#define   JM_MINOR_FEATURES1_L2_WINDOWING_AVAILABLE                          0x1

#define JM_MINOR_FEATURES1_HALF_FLOAT_PIPE                                 11:11
#define JM_MINOR_FEATURES1_HALF_FLOAT_PIPE_End                                11
#define JM_MINOR_FEATURES1_HALF_FLOAT_PIPE_Start                              11
#define JM_MINOR_FEATURES1_HALF_FLOAT_PIPE_Type                              U01
#define   JM_MINOR_FEATURES1_HALF_FLOAT_PIPE_NONE                            0x0
#define   JM_MINOR_FEATURES1_HALF_FLOAT_PIPE_AVAILABLE                       0x1

#define JM_MINOR_FEATURES1_PIXEL_DITHER                                    12:12
#define JM_MINOR_FEATURES1_PIXEL_DITHER_End                                   12
#define JM_MINOR_FEATURES1_PIXEL_DITHER_Start                                 12
#define JM_MINOR_FEATURES1_PIXEL_DITHER_Type                                 U01
#define   JM_MINOR_FEATURES1_PIXEL_DITHER_NONE                               0x0
#define   JM_MINOR_FEATURES1_PIXEL_DITHER_AVAILABLE                          0x1

#define JM_MINOR_FEATURES1_TWO_STENCIL_REFERENCE                           13:13
#define JM_MINOR_FEATURES1_TWO_STENCIL_REFERENCE_End                          13
#define JM_MINOR_FEATURES1_TWO_STENCIL_REFERENCE_Start                        13
#define JM_MINOR_FEATURES1_TWO_STENCIL_REFERENCE_Type                        U01
#define   JM_MINOR_FEATURES1_TWO_STENCIL_REFERENCE_NONE                      0x0
#define   JM_MINOR_FEATURES1_TWO_STENCIL_REFERENCE_AVAILABLE                 0x1

#define JM_MINOR_FEATURES1_EXTENDED_PIXEL_FORMAT                           14:14
#define JM_MINOR_FEATURES1_EXTENDED_PIXEL_FORMAT_End                          14
#define JM_MINOR_FEATURES1_EXTENDED_PIXEL_FORMAT_Start                        14
#define JM_MINOR_FEATURES1_EXTENDED_PIXEL_FORMAT_Type                        U01
#define   JM_MINOR_FEATURES1_EXTENDED_PIXEL_FORMAT_NONE                      0x0
#define   JM_MINOR_FEATURES1_EXTENDED_PIXEL_FORMAT_AVAILABLE                 0x1


#define JM_MINOR_FEATURES1_CORRECT_MIN_MAX_DEPTH                           15:15
#define JM_MINOR_FEATURES1_CORRECT_MIN_MAX_DEPTH_End                          15
#define JM_MINOR_FEATURES1_CORRECT_MIN_MAX_DEPTH_Start                        15
#define JM_MINOR_FEATURES1_CORRECT_MIN_MAX_DEPTH_Type                        U01
#define   JM_MINOR_FEATURES1_CORRECT_MIN_MAX_DEPTH_NONE                      0x0
#define   JM_MINOR_FEATURES1_CORRECT_MIN_MAX_DEPTH_AVAILABLE                 0x1


#define JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D                 16:16
#define JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_End                16
#define JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_Start              16
#define JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_Type              U01
#define   JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_NONE            0x0
#define   JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D_AVAILABLE       0x1

#define JM_MINOR_FEATURES1_BUG_FIXES5                                      17:17
#define JM_MINOR_FEATURES1_BUG_FIXES5_End                                     17
#define JM_MINOR_FEATURES1_BUG_FIXES5_Start                                   17
#define JM_MINOR_FEATURES1_BUG_FIXES5_Type                                   U01
#define   JM_MINOR_FEATURES1_BUG_FIXES5_NONE                                 0x0
#define   JM_MINOR_FEATURES1_BUG_FIXES5_AVAILABLE                            0x1

#define JM_MINOR_FEATURES1_NEW_2D                                          18:18
#define JM_MINOR_FEATURES1_NEW_2D_End                                         18
#define JM_MINOR_FEATURES1_NEW_2D_Start                                       18
#define JM_MINOR_FEATURES1_NEW_2D_Type                                       U01
#define   JM_MINOR_FEATURES1_NEW_2D_NONE                                     0x0
#define   JM_MINOR_FEATURES1_NEW_2D_AVAILABLE                                0x1

#define JM_MINOR_FEATURES1_NEW_FLOATING_POINT_ARITHMETIC                   19:19
#define JM_MINOR_FEATURES1_NEW_FLOATING_POINT_ARITHMETIC_End                  19
#define JM_MINOR_FEATURES1_NEW_FLOATING_POINT_ARITHMETIC_Start                19
#define JM_MINOR_FEATURES1_NEW_FLOATING_POINT_ARITHMETIC_Type                U01
#define   JM_MINOR_FEATURES1_NEW_FLOATING_POINT_ARITHMETIC_NONE              0x0
#define   JM_MINOR_FEATURES1_NEW_FLOATING_POINT_ARITHMETIC_AVAILABLE         0x1

#define JM_MINOR_FEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT             20:20
#define JM_MINOR_FEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_End            20
#define JM_MINOR_FEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_Start          20
#define JM_MINOR_FEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_Type          U01
#define   JM_MINOR_FEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_NONE        0x0
#define   JM_MINOR_FEATURES1_TEXTURE_HORIZONTAL_ALIGNMENT_SELECT_AVAILABLE   0x1

#define JM_MINOR_FEATURES1_NON_POWER_OF_TWO                                21:21
#define JM_MINOR_FEATURES1_NON_POWER_OF_TWO_End                               21
#define JM_MINOR_FEATURES1_NON_POWER_OF_TWO_Start                             21
#define JM_MINOR_FEATURES1_NON_POWER_OF_TWO_Type                             U01
#define   JM_MINOR_FEATURES1_NON_POWER_OF_TWO_NONE                           0x0
#define   JM_MINOR_FEATURES1_NON_POWER_OF_TWO_AVAILABLE                      0x1


#define JM_MINOR_FEATURES1_LINEAR_TEXTURE_SUPPORT                          22:22
#define JM_MINOR_FEATURES1_LINEAR_TEXTURE_SUPPORT_End                         22
#define JM_MINOR_FEATURES1_LINEAR_TEXTURE_SUPPORT_Start                       22
#define JM_MINOR_FEATURES1_LINEAR_TEXTURE_SUPPORT_Type                       U01
#define   JM_MINOR_FEATURES1_LINEAR_TEXTURE_SUPPORT_NONE                     0x0
#define   JM_MINOR_FEATURES1_LINEAR_TEXTURE_SUPPORT_AVAILABLE                0x1

#define JM_MINOR_FEATURES1_HALTI0                                          23:23
#define JM_MINOR_FEATURES1_HALTI0_End                                         23
#define JM_MINOR_FEATURES1_HALTI0_Start                                       23
#define JM_MINOR_FEATURES1_HALTI0_Type                                       U01
#define   JM_MINOR_FEATURES1_HALTI0_NONE                                     0x0
#define   JM_MINOR_FEATURES1_HALTI0_AVAILABLE                                0x1

#define JM_MINOR_FEATURES1_CORRECT_OVERFLOW_VG                             24:24
#define JM_MINOR_FEATURES1_CORRECT_OVERFLOW_VG_End                            24
#define JM_MINOR_FEATURES1_CORRECT_OVERFLOW_VG_Start                          24
#define JM_MINOR_FEATURES1_CORRECT_OVERFLOW_VG_Type                          U01
#define   JM_MINOR_FEATURES1_CORRECT_OVERFLOW_VG_NONE                        0x0
#define   JM_MINOR_FEATURES1_CORRECT_OVERFLOW_VG_AVAILABLE                   0x1

#define JM_MINOR_FEATURES1_NEGATIVE_LOG_FIX                                25:25
#define JM_MINOR_FEATURES1_NEGATIVE_LOG_FIX_End                               25
#define JM_MINOR_FEATURES1_NEGATIVE_LOG_FIX_Start                             25
#define JM_MINOR_FEATURES1_NEGATIVE_LOG_FIX_Type                             U01
#define   JM_MINOR_FEATURES1_NEGATIVE_LOG_FIX_NONE                           0x0
#define   JM_MINOR_FEATURES1_NEGATIVE_LOG_FIX_AVAILABLE                      0x1

#define JM_MINOR_FEATURES1_RESOLVE_OFFSET                                  26:26
#define JM_MINOR_FEATURES1_RESOLVE_OFFSET_End                                 26
#define JM_MINOR_FEATURES1_RESOLVE_OFFSET_Start                               26
#define JM_MINOR_FEATURES1_RESOLVE_OFFSET_Type                               U01
#define   JM_MINOR_FEATURES1_RESOLVE_OFFSET_NONE                             0x0
#define   JM_MINOR_FEATURES1_RESOLVE_OFFSET_AVAILABLE                        0x1

#define JM_MINOR_FEATURES1_OK_TO_GATE_AXI_CLOCK                            27:27
#define JM_MINOR_FEATURES1_OK_TO_GATE_AXI_CLOCK_End                           27
#define JM_MINOR_FEATURES1_OK_TO_GATE_AXI_CLOCK_Start                         27
#define JM_MINOR_FEATURES1_OK_TO_GATE_AXI_CLOCK_Type                         U01
#define   JM_MINOR_FEATURES1_OK_TO_GATE_AXI_CLOCK_NONE                       0x0
#define   JM_MINOR_FEATURES1_OK_TO_GATE_AXI_CLOCK_AVAILABLE                  0x1


#define JM_MINOR_FEATURES1_MMU                                             28:28
#define JM_MINOR_FEATURES1_MMU_End                                            28
#define JM_MINOR_FEATURES1_MMU_Start                                          28
#define JM_MINOR_FEATURES1_MMU_Type                                          U01
#define   JM_MINOR_FEATURES1_MMU_NONE                                        0x0
#define   JM_MINOR_FEATURES1_MMU_AVAILABLE                                   0x1

#define JM_MINOR_FEATURES1_WIDE_LINE                                       29:29
#define JM_MINOR_FEATURES1_WIDE_LINE_End                                      29
#define JM_MINOR_FEATURES1_WIDE_LINE_Start                                    29
#define JM_MINOR_FEATURES1_WIDE_LINE_Type                                    U01
#define   JM_MINOR_FEATURES1_WIDE_LINE_NONE                                  0x0
#define   JM_MINOR_FEATURES1_WIDE_LINE_AVAILABLE                             0x1

#define JM_MINOR_FEATURES1_BUG_FIXES6                                      30:30
#define JM_MINOR_FEATURES1_BUG_FIXES6_End                                     30
#define JM_MINOR_FEATURES1_BUG_FIXES6_Start                                   30
#define JM_MINOR_FEATURES1_BUG_FIXES6_Type                                   U01
#define   JM_MINOR_FEATURES1_BUG_FIXES6_NONE                                 0x0
#define   JM_MINOR_FEATURES1_BUG_FIXES6_AVAILABLE                            0x1

#define JM_MINOR_FEATURES1_FC_FLUSH_STALL                                  31:31
#define JM_MINOR_FEATURES1_FC_FLUSH_STALL_End                                 31
#define JM_MINOR_FEATURES1_FC_FLUSH_STALL_Start                               31
#define JM_MINOR_FEATURES1_FC_FLUSH_STALL_Type                               U01
#define   JM_MINOR_FEATURES1_FC_FLUSH_STALL_NONE                             0x0
#define   JM_MINOR_FEATURES1_FC_FLUSH_STALL_AVAILABLE                        0x1



#define jmTotalCyclesRegAddrs                                             0x001E
#define JM_TOTAL_CYCLES_Address                                          0x00078
#define JM_TOTAL_CYCLES_MSB                                                   15
#define JM_TOTAL_CYCLES_LSB                                                    0
#define JM_TOTAL_CYCLES_BLK                                                    0
#define JM_TOTAL_CYCLES_Count                                                  1
#define JM_TOTAL_CYCLES_FieldMask                                     0xFFFFFFFF
#define JM_TOTAL_CYCLES_ReadMask                                      0xFFFFFFFF
#define JM_TOTAL_CYCLES_WriteMask                                     0xFFFFFFFF
#define JM_TOTAL_CYCLES_ResetValue                                    0x00000000


#define JM_TOTAL_CYCLES_CYCLES                                              31:0
#define JM_TOTAL_CYCLES_CYCLES_End                                            31
#define JM_TOTAL_CYCLES_CYCLES_Start                                           0
#define JM_TOTAL_CYCLES_CYCLES_Type                                          U32



#define jmTotalIdleCyclesRegAddrs                                         0x001F
#define JM_TOTAL_IDLE_CYCLES_Address                                     0x0007C
#define JM_TOTAL_IDLE_CYCLES_MSB                                              15
#define JM_TOTAL_IDLE_CYCLES_LSB                                               0
#define JM_TOTAL_IDLE_CYCLES_BLK                                               0
#define JM_TOTAL_IDLE_CYCLES_Count                                             1
#define JM_TOTAL_IDLE_CYCLES_FieldMask                                0xFFFFFFFF
#define JM_TOTAL_IDLE_CYCLES_ReadMask                                 0xFFFFFFFF
#define JM_TOTAL_IDLE_CYCLES_WriteMask                                0xFFFFFFFF
#define JM_TOTAL_IDLE_CYCLES_ResetValue                               0x00000000


#define JM_TOTAL_IDLE_CYCLES_CYCLES                                         31:0
#define JM_TOTAL_IDLE_CYCLES_CYCLES_End                                       31
#define JM_TOTAL_IDLE_CYCLES_CYCLES_Start                                      0
#define JM_TOTAL_IDLE_CYCLES_CYCLES_Type                                     U32



#define jmChipSpecs2RegAddrs                                              0x0020
#define JM_CHIP_SPECS2_Address                                           0x00080
#define JM_CHIP_SPECS2_MSB                                                    15
#define JM_CHIP_SPECS2_LSB                                                     0
#define JM_CHIP_SPECS2_BLK                                                     0
#define JM_CHIP_SPECS2_Count                                                   1
#define JM_CHIP_SPECS2_FieldMask                                      0xFFFFFFFF
#define JM_CHIP_SPECS2_ReadMask                                       0xFFFFFFFF
#define JM_CHIP_SPECS2_WriteMask                                      0x00000000
#define JM_CHIP_SPECS2_ResetValue                                     0x00000000

#define JM_CHIP_SPECS2_BUFFER_SIZE                                           7:0
#define JM_CHIP_SPECS2_BUFFER_SIZE_End                                         7
#define JM_CHIP_SPECS2_BUFFER_SIZE_Start                                       0
#define JM_CHIP_SPECS2_BUFFER_SIZE_Type                                      U08

#define JM_CHIP_SPECS2_INSTRUCTION_COUNT                                    15:8
#define JM_CHIP_SPECS2_INSTRUCTION_COUNT_End                                  15
#define JM_CHIP_SPECS2_INSTRUCTION_COUNT_Start                                 8
#define JM_CHIP_SPECS2_INSTRUCTION_COUNT_Type                                U08

#define JM_CHIP_SPECS2_NUMBER_OF_CONSTANTS                                 31:16
#define JM_CHIP_SPECS2_NUMBER_OF_CONSTANTS_End                                31
#define JM_CHIP_SPECS2_NUMBER_OF_CONSTANTS_Start                              16
#define JM_CHIP_SPECS2_NUMBER_OF_CONSTANTS_Type                              U16



#define JMMinorFeatures2RegAddrs                                          0x0021
#define JM_MINOR_FEATURES2_Address                                       0x00084
#define JM_MINOR_FEATURES2_MSB                                                15
#define JM_MINOR_FEATURES2_LSB                                                 0
#define JM_MINOR_FEATURES2_BLK                                                 0
#define JM_MINOR_FEATURES2_Count                                               1
#define JM_MINOR_FEATURES2_FieldMask                                  0xFFFFFFFF
#define JM_MINOR_FEATURES2_ReadMask                                   0xFFFFFFFF
#define JM_MINOR_FEATURES2_WriteMask                                  0x00000000
#define JM_MINOR_FEATURES2_ResetValue                                 0x00000000

#define JM_MINOR_FEATURES2_LINE_LOOP                                         0:0
#define JM_MINOR_FEATURES2_LINE_LOOP_End                                       0
#define JM_MINOR_FEATURES2_LINE_LOOP_Start                                     0
#define JM_MINOR_FEATURES2_LINE_LOOP_Type                                    U01
#define   JM_MINOR_FEATURES2_LINE_LOOP_NONE                                  0x0
#define   JM_MINOR_FEATURES2_LINE_LOOP_AVAILABLE                             0x1

#define JM_MINOR_FEATURES2_LOGIC_OP                                          1:1
#define JM_MINOR_FEATURES2_LOGIC_OP_End                                        1
#define JM_MINOR_FEATURES2_LOGIC_OP_Start                                      1
#define JM_MINOR_FEATURES2_LOGIC_OP_Type                                     U01
#define   JM_MINOR_FEATURES2_LOGIC_OP_NONE                                   0x0
#define   JM_MINOR_FEATURES2_LOGIC_OP_AVAILABLE                              0x1

#define JM_MINOR_FEATURES2_SEAMLESS_CUBE_MAP                                 2:2
#define JM_MINOR_FEATURES2_SEAMLESS_CUBE_MAP_End                               2
#define JM_MINOR_FEATURES2_SEAMLESS_CUBE_MAP_Start                             2
#define JM_MINOR_FEATURES2_SEAMLESS_CUBE_MAP_Type                            U01
#define   JM_MINOR_FEATURES2_SEAMLESS_CUBE_MAP_NONE                          0x0
#define   JM_MINOR_FEATURES2_SEAMLESS_CUBE_MAP_AVAILABLE                     0x1


#define JM_MINOR_FEATURES2_SUPER_TILED_TEXTURE                               3:3
#define JM_MINOR_FEATURES2_SUPER_TILED_TEXTURE_End                             3
#define JM_MINOR_FEATURES2_SUPER_TILED_TEXTURE_Start                           3
#define JM_MINOR_FEATURES2_SUPER_TILED_TEXTURE_Type                          U01
#define   JM_MINOR_FEATURES2_SUPER_TILED_TEXTURE_NONE                        0x0
#define   JM_MINOR_FEATURES2_SUPER_TILED_TEXTURE_AVAILABLE                   0x1


#define JM_MINOR_FEATURES2_LINEAR_PE                                         4:4
#define JM_MINOR_FEATURES2_LINEAR_PE_End                                       4
#define JM_MINOR_FEATURES2_LINEAR_PE_Start                                     4
#define JM_MINOR_FEATURES2_LINEAR_PE_Type                                    U01
#define   JM_MINOR_FEATURES2_LINEAR_PE_NONE                                  0x0
#define   JM_MINOR_FEATURES2_LINEAR_PE_AVAILABLE                             0x1

#define JM_MINOR_FEATURES2_RECT_PRIMITIVE                                    5:5
#define JM_MINOR_FEATURES2_RECT_PRIMITIVE_End                                  5
#define JM_MINOR_FEATURES2_RECT_PRIMITIVE_Start                                5
#define JM_MINOR_FEATURES2_RECT_PRIMITIVE_Type                               U01
#define   JM_MINOR_FEATURES2_RECT_PRIMITIVE_NONE                             0x0
#define   JM_MINOR_FEATURES2_RECT_PRIMITIVE_AVAILABLE                        0x1

#define JM_MINOR_FEATURES2_COMPOSITION                                       6:6
#define JM_MINOR_FEATURES2_COMPOSITION_End                                     6
#define JM_MINOR_FEATURES2_COMPOSITION_Start                                   6
#define JM_MINOR_FEATURES2_COMPOSITION_Type                                  U01
#define   JM_MINOR_FEATURES2_COMPOSITION_NONE                                0x0
#define   JM_MINOR_FEATURES2_COMPOSITION_AVAILABLE                           0x1

#define JM_MINOR_FEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH                  7:7
#define JM_MINOR_FEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_End                7
#define JM_MINOR_FEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_Start              7
#define JM_MINOR_FEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_Type             U01
#define   JM_MINOR_FEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_NONE           0x0
#define   JM_MINOR_FEATURES2_CORRECT_AUTO_DISABLE_COUNT_WIDTH_AVAILABLE      0x1

#define JM_MINOR_FEATURES2_PE_SWIZZLE                                        8:8
#define JM_MINOR_FEATURES2_PE_SWIZZLE_End                                      8
#define JM_MINOR_FEATURES2_PE_SWIZZLE_Start                                    8
#define JM_MINOR_FEATURES2_PE_SWIZZLE_Type                                   U01
#define   JM_MINOR_FEATURES2_PE_SWIZZLE_NONE                                 0x0
#define   JM_MINOR_FEATURES2_PE_SWIZZLE_AVAILABLE                            0x1

#define JM_MINOR_FEATURES2_END_EVENT                                         9:9
#define JM_MINOR_FEATURES2_END_EVENT_End                                       9
#define JM_MINOR_FEATURES2_END_EVENT_Start                                     9
#define JM_MINOR_FEATURES2_END_EVENT_Type                                    U01
#define   JM_MINOR_FEATURES2_END_EVENT_NONE                                  0x0
#define   JM_MINOR_FEATURES2_END_EVENT_AVAILABLE                             0x1

#define JM_MINOR_FEATURES2_S1S8                                            10:10
#define JM_MINOR_FEATURES2_S1S8_End                                           10
#define JM_MINOR_FEATURES2_S1S8_Start                                         10
#define JM_MINOR_FEATURES2_S1S8_Type                                         U01
#define   JM_MINOR_FEATURES2_S1S8_NONE                                       0x0
#define   JM_MINOR_FEATURES2_S1S8_AVAILABLE                                  0x1

#define JM_MINOR_FEATURES2_HALTI1                                          11:11
#define JM_MINOR_FEATURES2_HALTI1_End                                         11
#define JM_MINOR_FEATURES2_HALTI1_Start                                       11
#define JM_MINOR_FEATURES2_HALTI1_Type                                       U01
#define   JM_MINOR_FEATURES2_HALTI1_NONE                                     0x0
#define   JM_MINOR_FEATURES2_HALTI1_AVAILABLE                                0x1

#define JM_MINOR_FEATURES2_RGB888                                          12:12
#define JM_MINOR_FEATURES2_RGB888_End                                         12
#define JM_MINOR_FEATURES2_RGB888_Start                                       12
#define JM_MINOR_FEATURES2_RGB888_Type                                       U01
#define   JM_MINOR_FEATURES2_RGB888_NONE                                     0x0
#define   JM_MINOR_FEATURES2_RGB888_AVAILABLE                                0x1

#define JM_MINOR_FEATURES2_TX__YUV_ASSEMBLER                               13:13
#define JM_MINOR_FEATURES2_TX__YUV_ASSEMBLER_End                              13
#define JM_MINOR_FEATURES2_TX__YUV_ASSEMBLER_Start                            13
#define JM_MINOR_FEATURES2_TX__YUV_ASSEMBLER_Type                            U01
#define   JM_MINOR_FEATURES2_TX__YUV_ASSEMBLER_NONE                          0x0
#define   JM_MINOR_FEATURES2_TX__YUV_ASSEMBLER_AVAILABLE                     0x1

#define JM_MINOR_FEATURES2_DYNAMIC_FREQUENCY_SCALING                       14:14
#define JM_MINOR_FEATURES2_DYNAMIC_FREQUENCY_SCALING_End                      14
#define JM_MINOR_FEATURES2_DYNAMIC_FREQUENCY_SCALING_Start                    14
#define JM_MINOR_FEATURES2_DYNAMIC_FREQUENCY_SCALING_Type                    U01
#define   JM_MINOR_FEATURES2_DYNAMIC_FREQUENCY_SCALING_NONE                  0x0
#define   JM_MINOR_FEATURES2_DYNAMIC_FREQUENCY_SCALING_AVAILABLE             0x1

#define JM_MINOR_FEATURES2_TX_FILTER                                       15:15
#define JM_MINOR_FEATURES2_TX_FILTER_End                                      15
#define JM_MINOR_FEATURES2_TX_FILTER_Start                                    15
#define JM_MINOR_FEATURES2_TX_FILTER_Type                                    U01
#define   JM_MINOR_FEATURES2_TX_FILTER_NONE                                  0x0
#define   JM_MINOR_FEATURES2_TX_FILTER_AVAILABLE                             0x1

#define JM_MINOR_FEATURES2_FULL_DIRECT_FB                                  16:16
#define JM_MINOR_FEATURES2_FULL_DIRECT_FB_End                                 16
#define JM_MINOR_FEATURES2_FULL_DIRECT_FB_Start                               16
#define JM_MINOR_FEATURES2_FULL_DIRECT_FB_Type                               U01
#define   JM_MINOR_FEATURES2_FULL_DIRECT_FB_NONE                             0x0
#define   JM_MINOR_FEATURES2_FULL_DIRECT_FB_AVAILABLE                        0x1

#define JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER                              17:17
#define JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER_End                             17
#define JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER_Start                           17
#define JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER_Type                           U01
#define   JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER_NONE                         0x0
#define   JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER_AVAILABLE                    0x1

#define JM_MINOR_FEATURES2_THREAD_WALKER_IN_PS                             18:18
#define JM_MINOR_FEATURES2_THREAD_WALKER_IN_PS_End                            18
#define JM_MINOR_FEATURES2_THREAD_WALKER_IN_PS_Start                          18
#define JM_MINOR_FEATURES2_THREAD_WALKER_IN_PS_Type                          U01
#define   JM_MINOR_FEATURES2_THREAD_WALKER_IN_PS_NONE                        0x0
#define   JM_MINOR_FEATURES2_THREAD_WALKER_IN_PS_AVAILABLE                   0x1

#define JM_MINOR_FEATURES2_TILE_FILLER                                     19:19
#define JM_MINOR_FEATURES2_TILE_FILLER_End                                    19
#define JM_MINOR_FEATURES2_TILE_FILLER_Start                                  19
#define JM_MINOR_FEATURES2_TILE_FILLER_Type                                  U01
#define   JM_MINOR_FEATURES2_TILE_FILLER_NONE                                0x0
#define   JM_MINOR_FEATURES2_TILE_FILLER_AVAILABLE                           0x1

#define JM_MINOR_FEATURES2_YUV_STANDARD                                    20:20
#define JM_MINOR_FEATURES2_YUV_STANDARD_End                                   20
#define JM_MINOR_FEATURES2_YUV_STANDARD_Start                                 20
#define JM_MINOR_FEATURES2_YUV_STANDARD_Type                                 U01
#define   JM_MINOR_FEATURES2_YUV_STANDARD_NONE                               0x0
#define   JM_MINOR_FEATURES2_YUV_STANDARD_AVAILABLE                          0x1

#define JM_MINOR_FEATURES2_MULTI_SOURCE_BLT                                21:21
#define JM_MINOR_FEATURES2_MULTI_SOURCE_BLT_End                               21
#define JM_MINOR_FEATURES2_MULTI_SOURCE_BLT_Start                             21
#define JM_MINOR_FEATURES2_MULTI_SOURCE_BLT_Type                             U01
#define   JM_MINOR_FEATURES2_MULTI_SOURCE_BLT_NONE                           0x0
#define   JM_MINOR_FEATURES2_MULTI_SOURCE_BLT_AVAILABLE                      0x1

#define JM_MINOR_FEATURES2_YUV_CONVERSION                                  22:22
#define JM_MINOR_FEATURES2_YUV_CONVERSION_End                                 22
#define JM_MINOR_FEATURES2_YUV_CONVERSION_Start                               22
#define JM_MINOR_FEATURES2_YUV_CONVERSION_Type                               U01
#define   JM_MINOR_FEATURES2_YUV_CONVERSION_NONE                             0x0
#define   JM_MINOR_FEATURES2_YUV_CONVERSION_AVAILABLE                        0x1

#define JM_MINOR_FEATURES2_FLUSH_FIXED_2D                                  23:23
#define JM_MINOR_FEATURES2_FLUSH_FIXED_2D_End                                 23
#define JM_MINOR_FEATURES2_FLUSH_FIXED_2D_Start                               23
#define JM_MINOR_FEATURES2_FLUSH_FIXED_2D_Type                               U01
#define   JM_MINOR_FEATURES2_FLUSH_FIXED_2D_NONE                             0x0
#define   JM_MINOR_FEATURES2_FLUSH_FIXED_2D_AVAILABLE                        0x1

#define JM_MINOR_FEATURES2_INTERLEAVER                                     24:24
#define JM_MINOR_FEATURES2_INTERLEAVER_End                                    24
#define JM_MINOR_FEATURES2_INTERLEAVER_Start                                  24
#define JM_MINOR_FEATURES2_INTERLEAVER_Type                                  U01
#define   JM_MINOR_FEATURES2_INTERLEAVER_NONE                                0x0
#define   JM_MINOR_FEATURES2_INTERLEAVER_AVAILABLE                           0x1

#define JM_MINOR_FEATURES2_MIXED_STREAMS                                   25:25
#define JM_MINOR_FEATURES2_MIXED_STREAMS_End                                  25
#define JM_MINOR_FEATURES2_MIXED_STREAMS_Start                                25
#define JM_MINOR_FEATURES2_MIXED_STREAMS_Type                                U01
#define   JM_MINOR_FEATURES2_MIXED_STREAMS_NONE                              0x0
#define   JM_MINOR_FEATURES2_MIXED_STREAMS_AVAILABLE                         0x1

#define JM_MINOR_FEATURES2_L2_CACHE_FOR_2D_420                             26:26
#define JM_MINOR_FEATURES2_L2_CACHE_FOR_2D_420_End                            26
#define JM_MINOR_FEATURES2_L2_CACHE_FOR_2D_420_Start                          26
#define JM_MINOR_FEATURES2_L2_CACHE_FOR_2D_420_Type                          U01
#define   JM_MINOR_FEATURES2_L2_CACHE_FOR_2D_420_NONE                        0x0
#define   JM_MINOR_FEATURES2_L2_CACHE_FOR_2D_420_AVAILABLE                   0x1

#define JM_MINOR_FEATURES2_BUG_FIXES7                                      27:27
#define JM_MINOR_FEATURES2_BUG_FIXES7_End                                     27
#define JM_MINOR_FEATURES2_BUG_FIXES7_Start                                   27
#define JM_MINOR_FEATURES2_BUG_FIXES7_Type                                   U01
#define   JM_MINOR_FEATURES2_BUG_FIXES7_NONE                                 0x0
#define   JM_MINOR_FEATURES2_BUG_FIXES7_AVAILABLE                            0x1

#define JM_MINOR_FEATURES2_NO_INDEX_PATTERN                                28:28
#define JM_MINOR_FEATURES2_NO_INDEX_PATTERN_End                               28
#define JM_MINOR_FEATURES2_NO_INDEX_PATTERN_Start                             28
#define JM_MINOR_FEATURES2_NO_INDEX_PATTERN_Type                             U01
#define   JM_MINOR_FEATURES2_NO_INDEX_PATTERN_NONE                           0x0
#define   JM_MINOR_FEATURES2_NO_INDEX_PATTERN_AVAILABLE                      0x1

#define JM_MINOR_FEATURES2_TEXTURE_TILE_STATUS                             29:29
#define JM_MINOR_FEATURES2_TEXTURE_TILE_STATUS_End                            29
#define JM_MINOR_FEATURES2_TEXTURE_TILE_STATUS_Start                          29
#define JM_MINOR_FEATURES2_TEXTURE_TILE_STATUS_Type                          U01
#define   JM_MINOR_FEATURES2_TEXTURE_TILE_STATUS_NONE                        0x0
#define   JM_MINOR_FEATURES2_TEXTURE_TILE_STATUS_AVAILABLE                   0x1

#define JM_MINOR_FEATURES2_DECOMPRESS_Z16                                  30:30
#define JM_MINOR_FEATURES2_DECOMPRESS_Z16_End                                 30
#define JM_MINOR_FEATURES2_DECOMPRESS_Z16_Start                               30
#define JM_MINOR_FEATURES2_DECOMPRESS_Z16_Type                               U01
#define   JM_MINOR_FEATURES2_DECOMPRESS_Z16_NONE                             0x0
#define   JM_MINOR_FEATURES2_DECOMPRESS_Z16_AVAILABLE                        0x1

#define JM_MINOR_FEATURES2_BUG_FIXES8                                      31:31
#define JM_MINOR_FEATURES2_BUG_FIXES8_End                                     31
#define JM_MINOR_FEATURES2_BUG_FIXES8_Start                                   31
#define JM_MINOR_FEATURES2_BUG_FIXES8_Type                                   U01
#define   JM_MINOR_FEATURES2_BUG_FIXES8_NONE                                 0x0
#define   JM_MINOR_FEATURES2_BUG_FIXES8_AVAILABLE                            0x1



#define JMMinorFeatures3RegAddrs                                          0x0022
#define JM_MINOR_FEATURES3_Address                                       0x00088
#define JM_MINOR_FEATURES3_MSB                                                15
#define JM_MINOR_FEATURES3_LSB                                                 0
#define JM_MINOR_FEATURES3_BLK                                                 0
#define JM_MINOR_FEATURES3_Count                                               1
#define JM_MINOR_FEATURES3_FieldMask                                  0xFFFFFFFF
#define JM_MINOR_FEATURES3_ReadMask                                   0xFFFFFFFF
#define JM_MINOR_FEATURES3_WriteMask                                  0x00000000
#define JM_MINOR_FEATURES3_ResetValue                                 0x00000000

#define JM_MINOR_FEATURES3_DE_ROTATION_STALL_FIX                             0:0
#define JM_MINOR_FEATURES3_DE_ROTATION_STALL_FIX_End                           0
#define JM_MINOR_FEATURES3_DE_ROTATION_STALL_FIX_Start                         0
#define JM_MINOR_FEATURES3_DE_ROTATION_STALL_FIX_Type                        U01
#define   JM_MINOR_FEATURES3_DE_ROTATION_STALL_FIX_NONE                      0x0
#define   JM_MINOR_FEATURES3_DE_ROTATION_STALL_FIX_AVAILABLE                 0x1

#define JM_MINOR_FEATURES3_OCL_ONLY                                          1:1
#define JM_MINOR_FEATURES3_OCL_ONLY_End                                        1
#define JM_MINOR_FEATURES3_OCL_ONLY_Start                                      1
#define JM_MINOR_FEATURES3_OCL_ONLY_Type                                     U01
#define   JM_MINOR_FEATURES3_OCL_ONLY_NONE                                   0x0
#define   JM_MINOR_FEATURES3_OCL_ONLY_AVAILABLE                              0x1

#define JM_MINOR_FEATURES3_NEW_FEATURES0                                     2:2
#define JM_MINOR_FEATURES3_NEW_FEATURES0_End                                   2
#define JM_MINOR_FEATURES3_NEW_FEATURES0_Start                                 2
#define JM_MINOR_FEATURES3_NEW_FEATURES0_Type                                U01
#define   JM_MINOR_FEATURES3_NEW_FEATURES0_NONE                              0x0
#define   JM_MINOR_FEATURES3_NEW_FEATURES0_AVAILABLE                         0x1


#define JM_MINOR_FEATURES3_INSTRUCTION_CACHE                                 3:3
#define JM_MINOR_FEATURES3_INSTRUCTION_CACHE_End                               3
#define JM_MINOR_FEATURES3_INSTRUCTION_CACHE_Start                             3
#define JM_MINOR_FEATURES3_INSTRUCTION_CACHE_Type                            U01
#define   JM_MINOR_FEATURES3_INSTRUCTION_CACHE_NONE                          0x0
#define   JM_MINOR_FEATURES3_INSTRUCTION_CACHE_AVAILABLE                     0x1


#define JM_MINOR_FEATURES3_GEOMETRY_SHADER                                   4:4
#define JM_MINOR_FEATURES3_GEOMETRY_SHADER_End                                 4
#define JM_MINOR_FEATURES3_GEOMETRY_SHADER_Start                               4
#define JM_MINOR_FEATURES3_GEOMETRY_SHADER_Type                              U01
#define   JM_MINOR_FEATURES3_GEOMETRY_SHADER_NONE                            0x0
#define   JM_MINOR_FEATURES3_GEOMETRY_SHADER_AVAILABLE                       0x1


#define JM_MINOR_FEATURES3_TEX_COMPRESSION_SUPERTILED                        5:5
#define JM_MINOR_FEATURES3_TEX_COMPRESSION_SUPERTILED_End                      5
#define JM_MINOR_FEATURES3_TEX_COMPRESSION_SUPERTILED_Start                    5
#define JM_MINOR_FEATURES3_TEX_COMPRESSION_SUPERTILED_Type                   U01
#define   JM_MINOR_FEATURES3_TEX_COMPRESSION_SUPERTILED_NONE                 0x0
#define   JM_MINOR_FEATURES3_TEX_COMPRESSION_SUPERTILED_AVAILABLE            0x1

#define JM_MINOR_FEATURES3_GENERICS                                          6:6
#define JM_MINOR_FEATURES3_GENERICS_End                                        6
#define JM_MINOR_FEATURES3_GENERICS_Start                                      6
#define JM_MINOR_FEATURES3_GENERICS_Type                                     U01
#define   JM_MINOR_FEATURES3_GENERICS_NONE                                   0x0
#define   JM_MINOR_FEATURES3_GENERICS_AVAILABLE                              0x1

#define JM_MINOR_FEATURES3_BUG_FIXES9                                        7:7
#define JM_MINOR_FEATURES3_BUG_FIXES9_End                                      7
#define JM_MINOR_FEATURES3_BUG_FIXES9_Start                                    7
#define JM_MINOR_FEATURES3_BUG_FIXES9_Type                                   U01
#define   JM_MINOR_FEATURES3_BUG_FIXES9_NONE                                 0x0
#define   JM_MINOR_FEATURES3_BUG_FIXES9_AVAILABLE                            0x1


#define JM_MINOR_FEATURES3_FAST_MSAA                                         8:8
#define JM_MINOR_FEATURES3_FAST_MSAA_End                                       8
#define JM_MINOR_FEATURES3_FAST_MSAA_Start                                     8
#define JM_MINOR_FEATURES3_FAST_MSAA_Type                                    U01
#define   JM_MINOR_FEATURES3_FAST_MSAA_NONE                                  0x0
#define   JM_MINOR_FEATURES3_FAST_MSAA_AVAILABLE                             0x1

#define JM_MINOR_FEATURES3_WCLIP                                             9:9
#define JM_MINOR_FEATURES3_WCLIP_End                                           9
#define JM_MINOR_FEATURES3_WCLIP_Start                                         9
#define JM_MINOR_FEATURES3_WCLIP_Type                                        U01
#define   JM_MINOR_FEATURES3_WCLIP_NONE                                      0x0
#define   JM_MINOR_FEATURES3_WCLIP_AVAILABLE                                 0x1

#define JM_MINOR_FEATURES3_BUG_FIXES10                                     10:10
#define JM_MINOR_FEATURES3_BUG_FIXES10_End                                    10
#define JM_MINOR_FEATURES3_BUG_FIXES10_Start                                  10
#define JM_MINOR_FEATURES3_BUG_FIXES10_Type                                  U01
#define   JM_MINOR_FEATURES3_BUG_FIXES10_NONE                                0x0
#define   JM_MINOR_FEATURES3_BUG_FIXES10_AVAILABLE                           0x1

#define JM_MINOR_FEATURES3_UNIFIED_SAMPLERS                                11:11
#define JM_MINOR_FEATURES3_UNIFIED_SAMPLERS_End                               11
#define JM_MINOR_FEATURES3_UNIFIED_SAMPLERS_Start                             11
#define JM_MINOR_FEATURES3_UNIFIED_SAMPLERS_Type                             U01
#define   JM_MINOR_FEATURES3_UNIFIED_SAMPLERS_NONE                           0x0
#define   JM_MINOR_FEATURES3_UNIFIED_SAMPLERS_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_BUG_FIXES11                                     12:12
#define JM_MINOR_FEATURES3_BUG_FIXES11_End                                    12
#define JM_MINOR_FEATURES3_BUG_FIXES11_Start                                  12
#define JM_MINOR_FEATURES3_BUG_FIXES11_Type                                  U01
#define   JM_MINOR_FEATURES3_BUG_FIXES11_NONE                                0x0
#define   JM_MINOR_FEATURES3_BUG_FIXES11_AVAILABLE                           0x1


#define JM_MINOR_FEATURES3_PERFORMANCE_COUNTERS                            13:13
#define JM_MINOR_FEATURES3_PERFORMANCE_COUNTERS_End                           13
#define JM_MINOR_FEATURES3_PERFORMANCE_COUNTERS_Start                         13
#define JM_MINOR_FEATURES3_PERFORMANCE_COUNTERS_Type                         U01
#define   JM_MINOR_FEATURES3_PERFORMANCE_COUNTERS_NONE                       0x0
#define   JM_MINOR_FEATURES3_PERFORMANCE_COUNTERS_AVAILABLE                  0x1

#define JM_MINOR_FEATURES3_EXTRA_SHADER_INSTRUCTIONS2                      14:14
#define JM_MINOR_FEATURES3_EXTRA_SHADER_INSTRUCTIONS2_End                     14
#define JM_MINOR_FEATURES3_EXTRA_SHADER_INSTRUCTIONS2_Start                   14
#define JM_MINOR_FEATURES3_EXTRA_SHADER_INSTRUCTIONS2_Type                   U01
#define   JM_MINOR_FEATURES3_EXTRA_SHADER_INSTRUCTIONS2_NONE                 0x0
#define   JM_MINOR_FEATURES3_EXTRA_SHADER_INSTRUCTIONS2_AVAILABLE            0x1

#define JM_MINOR_FEATURES3_BUG_FIXES12                                     15:15
#define JM_MINOR_FEATURES3_BUG_FIXES12_End                                    15
#define JM_MINOR_FEATURES3_BUG_FIXES12_Start                                  15
#define JM_MINOR_FEATURES3_BUG_FIXES12_Type                                  U01
#define   JM_MINOR_FEATURES3_BUG_FIXES12_NONE                                0x0
#define   JM_MINOR_FEATURES3_BUG_FIXES12_AVAILABLE                           0x1

#define JM_MINOR_FEATURES3_BUG_FIXES13                                     16:16
#define JM_MINOR_FEATURES3_BUG_FIXES13_End                                    16
#define JM_MINOR_FEATURES3_BUG_FIXES13_Start                                  16
#define JM_MINOR_FEATURES3_BUG_FIXES13_Type                                  U01
#define   JM_MINOR_FEATURES3_BUG_FIXES13_NONE                                0x0
#define   JM_MINOR_FEATURES3_BUG_FIXES13_AVAILABLE                           0x1

#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS1                                17:17
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS1_End                               17
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS1_Start                             17
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES3_DE_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES3_DE_ENHANCEMENTS1_AVAILABLE                      0x1


#define JM_MINOR_FEATURES3_ACE                                             18:18
#define JM_MINOR_FEATURES3_ACE_End                                            18
#define JM_MINOR_FEATURES3_ACE_Start                                          18
#define JM_MINOR_FEATURES3_ACE_Type                                          U01
#define   JM_MINOR_FEATURES3_ACE_NONE                                        0x0
#define   JM_MINOR_FEATURES3_ACE_AVAILABLE                                   0x1

#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS1                                19:19
#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS1_End                               19
#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS1_Start                             19
#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES3_TX_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES3_TX_ENHANCEMENTS1_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS1                                20:20
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS1_End                               20
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS1_Start                             20
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS1_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS2                                21:21
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS2_End                               21
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS2_Start                             21
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS2_Type                             U01
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS2_NONE                           0x0
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS2_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_PE_ENHANCEMENTS1                                22:22
#define JM_MINOR_FEATURES3_PE_ENHANCEMENTS1_End                               22
#define JM_MINOR_FEATURES3_PE_ENHANCEMENTS1_Start                             22
#define JM_MINOR_FEATURES3_PE_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES3_PE_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES3_PE_ENHANCEMENTS1_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS2                                23:23
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS2_End                               23
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS2_Start                             23
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS2_Type                             U01
#define   JM_MINOR_FEATURES3_DE_ENHANCEMENTS2_NONE                           0x0
#define   JM_MINOR_FEATURES3_DE_ENHANCEMENTS2_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_BUG_FIXES14                                     24:24
#define JM_MINOR_FEATURES3_BUG_FIXES14_End                                    24
#define JM_MINOR_FEATURES3_BUG_FIXES14_Start                                  24
#define JM_MINOR_FEATURES3_BUG_FIXES14_Type                                  U01
#define   JM_MINOR_FEATURES3_BUG_FIXES14_NONE                                0x0
#define   JM_MINOR_FEATURES3_BUG_FIXES14_AVAILABLE                           0x1

#define JM_MINOR_FEATURES3_POWER_OPTIMIZATIONS0                            25:25
#define JM_MINOR_FEATURES3_POWER_OPTIMIZATIONS0_End                           25
#define JM_MINOR_FEATURES3_POWER_OPTIMIZATIONS0_Start                         25
#define JM_MINOR_FEATURES3_POWER_OPTIMIZATIONS0_Type                         U01
#define   JM_MINOR_FEATURES3_POWER_OPTIMIZATIONS0_NONE                       0x0
#define   JM_MINOR_FEATURES3_POWER_OPTIMIZATIONS0_AVAILABLE                  0x1

#define JM_MINOR_FEATURES3_NEW_HZ                                          26:26
#define JM_MINOR_FEATURES3_NEW_HZ_End                                         26
#define JM_MINOR_FEATURES3_NEW_HZ_Start                                       26
#define JM_MINOR_FEATURES3_NEW_HZ_Type                                       U01
#define   JM_MINOR_FEATURES3_NEW_HZ_NONE                                     0x0
#define   JM_MINOR_FEATURES3_NEW_HZ_AVAILABLE                                0x1

#define JM_MINOR_FEATURES3_BUG_FIXES15                                     27:27
#define JM_MINOR_FEATURES3_BUG_FIXES15_End                                    27
#define JM_MINOR_FEATURES3_BUG_FIXES15_Start                                  27
#define JM_MINOR_FEATURES3_BUG_FIXES15_Type                                  U01
#define   JM_MINOR_FEATURES3_BUG_FIXES15_NONE                                0x0
#define   JM_MINOR_FEATURES3_BUG_FIXES15_AVAILABLE                           0x1

#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS3                                28:28
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS3_End                               28
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS3_Start                             28
#define JM_MINOR_FEATURES3_DE_ENHANCEMENTS3_Type                             U01
#define   JM_MINOR_FEATURES3_DE_ENHANCEMENTS3_NONE                           0x0
#define   JM_MINOR_FEATURES3_DE_ENHANCEMENTS3_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS3                                29:29
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS3_End                               29
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS3_Start                             29
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS3_Type                             U01
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS3_NONE                           0x0
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS3_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS4                                30:30
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS4_End                               30
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS4_Start                             30
#define JM_MINOR_FEATURES3_SH_ENHANCEMENTS4_Type                             U01
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS4_NONE                           0x0
#define   JM_MINOR_FEATURES3_SH_ENHANCEMENTS4_AVAILABLE                      0x1

#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS2                                31:31
#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS2_End                               31
#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS2_Start                             31
#define JM_MINOR_FEATURES3_TX_ENHANCEMENTS2_Type                             U01
#define   JM_MINOR_FEATURES3_TX_ENHANCEMENTS2_NONE                           0x0
#define   JM_MINOR_FEATURES3_TX_ENHANCEMENTS2_AVAILABLE                      0x1



#define jmChipSpecs3RegAddrs                                              0x0023
#define JM_CHIP_SPECS3_Address                                           0x0008C
#define JM_CHIP_SPECS3_MSB                                                    15
#define JM_CHIP_SPECS3_LSB                                                     0
#define JM_CHIP_SPECS3_BLK                                                     0
#define JM_CHIP_SPECS3_Count                                                   1
#define JM_CHIP_SPECS3_FieldMask                                      0xFFFF01F7
#define JM_CHIP_SPECS3_ReadMask                                       0xFFFF01F7
#define JM_CHIP_SPECS3_WriteMask                                      0x00000000
#define JM_CHIP_SPECS3_ResetValue                                     0x00000000

#define JM_CHIP_SPECS3_CORE_COUNT                                            2:0
#define JM_CHIP_SPECS3_CORE_COUNT_End                                          2
#define JM_CHIP_SPECS3_CORE_COUNT_Start                                        0
#define JM_CHIP_SPECS3_CORE_COUNT_Type                                       U03

#define JM_CHIP_SPECS3_VARYING_COUNT                                         8:4
#define JM_CHIP_SPECS3_VARYING_COUNT_End                                       8
#define JM_CHIP_SPECS3_VARYING_COUNT_Start                                     4
#define JM_CHIP_SPECS3_VARYING_COUNT_Type                                    U05

#define JM_CHIP_SPECS3_LOCAL_STORAGE_SIZE                                  23:16
#define JM_CHIP_SPECS3_LOCAL_STORAGE_SIZE_End                                 23
#define JM_CHIP_SPECS3_LOCAL_STORAGE_SIZE_Start                               16
#define JM_CHIP_SPECS3_LOCAL_STORAGE_SIZE_Type                               U08

#define JM_CHIP_SPECS3_L1_CACHE_SIZE                                       31:24
#define JM_CHIP_SPECS3_L1_CACHE_SIZE_End                                      31
#define JM_CHIP_SPECS3_L1_CACHE_SIZE_Start                                    24
#define JM_CHIP_SPECS3_L1_CACHE_SIZE_Type                                    U08




#define mwv207regControl2RegAddrs                                         0x0024
#define MWV207REG_CONTROL2_Address                                       0x00090
#define MWV207REG_CONTROL2_MSB                                                15
#define MWV207REG_CONTROL2_LSB                                                 0
#define MWV207REG_CONTROL2_BLK                                                 0
#define MWV207REG_CONTROL2_Count                                               1
#define MWV207REG_CONTROL2_FieldMask                                  0x00000FF3
#define MWV207REG_CONTROL2_ReadMask                                   0x00000FF3
#define MWV207REG_CONTROL2_WriteMask                                  0x00000FF3
#define MWV207REG_CONTROL2_ResetValue                                 0x00000381


#define MWV207REG_CONTROL2_SPLIT_CONTROL                                     1:0
#define MWV207REG_CONTROL2_SPLIT_CONTROL_End                                   1
#define MWV207REG_CONTROL2_SPLIT_CONTROL_Start                                 0
#define MWV207REG_CONTROL2_SPLIT_CONTROL_Type                                U02
#define   MWV207REG_CONTROL2_SPLIT_CONTROL_NO_SPLIT                          0x0
#define   MWV207REG_CONTROL2_SPLIT_CONTROL_SPLIT_TO128                       0x1
#define   MWV207REG_CONTROL2_SPLIT_CONTROL_SPLIT_TO64                        0x2


#define MWV207REG_CONTROL2_DISABLE_AXI_WRITE_REORDER                         4:4
#define MWV207REG_CONTROL2_DISABLE_AXI_WRITE_REORDER_End                       4
#define MWV207REG_CONTROL2_DISABLE_AXI_WRITE_REORDER_Start                     4
#define MWV207REG_CONTROL2_DISABLE_AXI_WRITE_REORDER_Type                    U01


#define MWV207REG_CONTROL2_DISABLE_ADDRESS_SHUFFLING                         5:5
#define MWV207REG_CONTROL2_DISABLE_ADDRESS_SHUFFLING_End                       5
#define MWV207REG_CONTROL2_DISABLE_ADDRESS_SHUFFLING_Start                     5
#define MWV207REG_CONTROL2_DISABLE_ADDRESS_SHUFFLING_Type                    U01


#define MWV207REG_CONTROL2_DISABLE_AXI_READ_REORDER                          6:6
#define MWV207REG_CONTROL2_DISABLE_AXI_READ_REORDER_End                        6
#define MWV207REG_CONTROL2_DISABLE_AXI_READ_REORDER_Start                      6
#define MWV207REG_CONTROL2_DISABLE_AXI_READ_REORDER_Type                     U01


#define MWV207REG_CONTROL2_DISABLE_TX_AXI_READ_REORDER                       7:7
#define MWV207REG_CONTROL2_DISABLE_TX_AXI_READ_REORDER_End                     7
#define MWV207REG_CONTROL2_DISABLE_TX_AXI_READ_REORDER_Start                   7
#define MWV207REG_CONTROL2_DISABLE_TX_AXI_READ_REORDER_Type                  U01


#define MWV207REG_CONTROL2_DISABLE_FE_AXI_READ_REORDER                       8:8
#define MWV207REG_CONTROL2_DISABLE_FE_AXI_READ_REORDER_End                     8
#define MWV207REG_CONTROL2_DISABLE_FE_AXI_READ_REORDER_Start                   8
#define MWV207REG_CONTROL2_DISABLE_FE_AXI_READ_REORDER_Type                  U01


#define MWV207REG_CONTROL2_UNIQUE_AXI_ID                                     9:9
#define MWV207REG_CONTROL2_UNIQUE_AXI_ID_End                                   9
#define MWV207REG_CONTROL2_UNIQUE_AXI_ID_Start                                 9
#define MWV207REG_CONTROL2_UNIQUE_AXI_ID_Type                                U01


#define MWV207REG_CONTROL2_REDUCED_ID_COUNT                                10:10
#define MWV207REG_CONTROL2_REDUCED_ID_COUNT_End                               10
#define MWV207REG_CONTROL2_REDUCED_ID_COUNT_Start                             10
#define MWV207REG_CONTROL2_REDUCED_ID_COUNT_Type                             U01


#define MWV207REG_CONTROL2_ENABLE_WATA_AHEAD                               11:11
#define MWV207REG_CONTROL2_ENABLE_WATA_AHEAD_End                              11
#define MWV207REG_CONTROL2_ENABLE_WATA_AHEAD_Start                            11
#define MWV207REG_CONTROL2_ENABLE_WATA_AHEAD_Type                            U01



#define JMMinorFeatures4RegAddrs                                          0x0025
#define JM_MINOR_FEATURES4_Address                                       0x00094
#define JM_MINOR_FEATURES4_MSB                                                15
#define JM_MINOR_FEATURES4_LSB                                                 0
#define JM_MINOR_FEATURES4_BLK                                                 0
#define JM_MINOR_FEATURES4_Count                                               1
#define JM_MINOR_FEATURES4_FieldMask                                  0xFFFFFFFF
#define JM_MINOR_FEATURES4_ReadMask                                   0xFFFFFFFF
#define JM_MINOR_FEATURES4_WriteMask                                  0x00000000
#define JM_MINOR_FEATURES4_ResetValue                                 0x00000000

#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS1                                  0:0
#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS1_End                                0
#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS1_Start                              0
#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES4_FE_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES4_FE_ENHANCEMENTS1_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS2                                  1:1
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS2_End                                1
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS2_Start                              1
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS2_Type                             U01
#define   JM_MINOR_FEATURES4_PE_ENHANCEMENTS2_NONE                           0x0
#define   JM_MINOR_FEATURES4_PE_ENHANCEMENTS2_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS1                                  2:2
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS1_End                                2
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS1_Start                              2
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES4_PA_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES4_PA_ENHANCEMENTS1_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_DE_NO_GAMMA                                       3:3
#define JM_MINOR_FEATURES4_DE_NO_GAMMA_End                                     3
#define JM_MINOR_FEATURES4_DE_NO_GAMMA_Start                                   3
#define JM_MINOR_FEATURES4_DE_NO_GAMMA_Type                                  U01
#define   JM_MINOR_FEATURES4_DE_NO_GAMMA_NONE                                0x0
#define   JM_MINOR_FEATURES4_DE_NO_GAMMA_AVAILABLE                           0x1

#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS2                                  4:4
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS2_End                                4
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS2_Start                              4
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS2_Type                             U01
#define   JM_MINOR_FEATURES4_PA_ENHANCEMENTS2_NONE                           0x0
#define   JM_MINOR_FEATURES4_PA_ENHANCEMENTS2_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS4                                  5:5
#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS4_End                                5
#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS4_Start                              5
#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS4_Type                             U01
#define   JM_MINOR_FEATURES4_DE_ENHANCEMENTS4_NONE                           0x0
#define   JM_MINOR_FEATURES4_DE_ENHANCEMENTS4_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS3                                  6:6
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS3_End                                6
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS3_Start                              6
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS3_Type                             U01
#define   JM_MINOR_FEATURES4_PE_ENHANCEMENTS3_NONE                           0x0
#define   JM_MINOR_FEATURES4_PE_ENHANCEMENTS3_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_HI_ENHANCEMENTS1                                  7:7
#define JM_MINOR_FEATURES4_HI_ENHANCEMENTS1_End                                7
#define JM_MINOR_FEATURES4_HI_ENHANCEMENTS1_Start                              7
#define JM_MINOR_FEATURES4_HI_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES4_HI_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES4_HI_ENHANCEMENTS1_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS3                                  8:8
#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS3_End                                8
#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS3_Start                              8
#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS3_Type                             U01
#define   JM_MINOR_FEATURES4_TX_ENHANCEMENTS3_NONE                           0x0
#define   JM_MINOR_FEATURES4_TX_ENHANCEMENTS3_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS5                                  9:9
#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS5_End                                9
#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS5_Start                              9
#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS5_Type                             U01
#define   JM_MINOR_FEATURES4_SH_ENHANCEMENTS5_NONE                           0x0
#define   JM_MINOR_FEATURES4_SH_ENHANCEMENTS5_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS2                                10:10
#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS2_End                               10
#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS2_Start                             10
#define JM_MINOR_FEATURES4_FE_ENHANCEMENTS2_Type                             U01
#define   JM_MINOR_FEATURES4_FE_ENHANCEMENTS2_NONE                           0x0
#define   JM_MINOR_FEATURES4_FE_ENHANCEMENTS2_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_BUG_FIXES16                                     11:11
#define JM_MINOR_FEATURES4_BUG_FIXES16_End                                    11
#define JM_MINOR_FEATURES4_BUG_FIXES16_Start                                  11
#define JM_MINOR_FEATURES4_BUG_FIXES16_Type                                  U01
#define   JM_MINOR_FEATURES4_BUG_FIXES16_NONE                                0x0
#define   JM_MINOR_FEATURES4_BUG_FIXES16_AVAILABLE                           0x1

#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS5                                12:12
#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS5_End                               12
#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS5_Start                             12
#define JM_MINOR_FEATURES4_DE_ENHANCEMENTS5_Type                             U01
#define   JM_MINOR_FEATURES4_DE_ENHANCEMENTS5_NONE                           0x0
#define   JM_MINOR_FEATURES4_DE_ENHANCEMENTS5_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS4                                13:13
#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS4_End                               13
#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS4_Start                             13
#define JM_MINOR_FEATURES4_TX_ENHANCEMENTS4_Type                             U01
#define   JM_MINOR_FEATURES4_TX_ENHANCEMENTS4_NONE                           0x0
#define   JM_MINOR_FEATURES4_TX_ENHANCEMENTS4_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS4                                14:14
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS4_End                               14
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS4_Start                             14
#define JM_MINOR_FEATURES4_PE_ENHANCEMENTS4_Type                             U01
#define   JM_MINOR_FEATURES4_PE_ENHANCEMENTS4_NONE                           0x0
#define   JM_MINOR_FEATURES4_PE_ENHANCEMENTS4_AVAILABLE                      0x1


#define JM_MINOR_FEATURES4_MC_ENHANCEMENTS1                                15:15
#define JM_MINOR_FEATURES4_MC_ENHANCEMENTS1_End                               15
#define JM_MINOR_FEATURES4_MC_ENHANCEMENTS1_Start                             15
#define JM_MINOR_FEATURES4_MC_ENHANCEMENTS1_Type                             U01
#define   JM_MINOR_FEATURES4_MC_ENHANCEMENTS1_NONE                           0x0
#define   JM_MINOR_FEATURES4_MC_ENHANCEMENTS1_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_HALTI2                                          16:16
#define JM_MINOR_FEATURES4_HALTI2_End                                         16
#define JM_MINOR_FEATURES4_HALTI2_Start                                       16
#define JM_MINOR_FEATURES4_HALTI2_Type                                       U01
#define   JM_MINOR_FEATURES4_HALTI2_NONE                                     0x0
#define   JM_MINOR_FEATURES4_HALTI2_AVAILABLE                                0x1

#define JM_MINOR_FEATURES4_DE_MIRROR_ROTATE                                17:17
#define JM_MINOR_FEATURES4_DE_MIRROR_ROTATE_End                               17
#define JM_MINOR_FEATURES4_DE_MIRROR_ROTATE_Start                             17
#define JM_MINOR_FEATURES4_DE_MIRROR_ROTATE_Type                             U01
#define   JM_MINOR_FEATURES4_DE_MIRROR_ROTATE_NONE                           0x0
#define   JM_MINOR_FEATURES4_DE_MIRROR_ROTATE_AVAILABLE                      0x1


#define JM_MINOR_FEATURES4_SMALL_MSAA                                      18:18
#define JM_MINOR_FEATURES4_SMALL_MSAA_End                                     18
#define JM_MINOR_FEATURES4_SMALL_MSAA_Start                                   18
#define JM_MINOR_FEATURES4_SMALL_MSAA_Type                                   U01
#define   JM_MINOR_FEATURES4_SMALL_MSAA_NONE                                 0x0
#define   JM_MINOR_FEATURES4_SMALL_MSAA_AVAILABLE                            0x1

#define JM_MINOR_FEATURES4_BUG_FIXES17                                     19:19
#define JM_MINOR_FEATURES4_BUG_FIXES17_End                                    19
#define JM_MINOR_FEATURES4_BUG_FIXES17_Start                                  19
#define JM_MINOR_FEATURES4_BUG_FIXES17_Type                                  U01
#define   JM_MINOR_FEATURES4_BUG_FIXES17_NONE                                0x0
#define   JM_MINOR_FEATURES4_BUG_FIXES17_AVAILABLE                           0x1

#define JM_MINOR_FEATURES4_RASTERIZER2                                     20:20
#define JM_MINOR_FEATURES4_RASTERIZER2_End                                    20
#define JM_MINOR_FEATURES4_RASTERIZER2_Start                                  20
#define JM_MINOR_FEATURES4_RASTERIZER2_Type                                  U01
#define   JM_MINOR_FEATURES4_RASTERIZER2_NONE                                0x0
#define   JM_MINOR_FEATURES4_RASTERIZER2_AVAILABLE                           0x1

#define JM_MINOR_FEATURES4_DUAL_PIPE_OPF                                   21:21
#define JM_MINOR_FEATURES4_DUAL_PIPE_OPF_End                                  21
#define JM_MINOR_FEATURES4_DUAL_PIPE_OPF_Start                                21
#define JM_MINOR_FEATURES4_DUAL_PIPE_OPF_Type                                U01
#define   JM_MINOR_FEATURES4_DUAL_PIPE_OPF_NONE                              0x0
#define   JM_MINOR_FEATURES4_DUAL_PIPE_OPF_AVAILABLE                         0x1

#define JM_MINOR_FEATURES4_MULTI_SRC_V2                                    22:22
#define JM_MINOR_FEATURES4_MULTI_SRC_V2_End                                   22
#define JM_MINOR_FEATURES4_MULTI_SRC_V2_Start                                 22
#define JM_MINOR_FEATURES4_MULTI_SRC_V2_Type                                 U01
#define   JM_MINOR_FEATURES4_MULTI_SRC_V2_NONE                               0x0
#define   JM_MINOR_FEATURES4_MULTI_SRC_V2_AVAILABLE                          0x1

#define JM_MINOR_FEATURES4_CSCV2                                           23:23
#define JM_MINOR_FEATURES4_CSCV2_End                                          23
#define JM_MINOR_FEATURES4_CSCV2_Start                                        23
#define JM_MINOR_FEATURES4_CSCV2_Type                                        U01
#define   JM_MINOR_FEATURES4_CSCV2_NONE                                      0x0
#define   JM_MINOR_FEATURES4_CSCV2_AVAILABLE                                 0x1

#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS3                                24:24
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS3_End                               24
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS3_Start                             24
#define JM_MINOR_FEATURES4_PA_ENHANCEMENTS3_Type                             U01
#define   JM_MINOR_FEATURES4_PA_ENHANCEMENTS3_NONE                           0x0
#define   JM_MINOR_FEATURES4_PA_ENHANCEMENTS3_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_BUG_FIXES18                                     25:25
#define JM_MINOR_FEATURES4_BUG_FIXES18_End                                    25
#define JM_MINOR_FEATURES4_BUG_FIXES18_Start                                  25
#define JM_MINOR_FEATURES4_BUG_FIXES18_Type                                  U01
#define   JM_MINOR_FEATURES4_BUG_FIXES18_NONE                                0x0
#define   JM_MINOR_FEATURES4_BUG_FIXES18_AVAILABLE                           0x1

#define JM_MINOR_FEATURES4_COMPRESSION2_D                                  26:26
#define JM_MINOR_FEATURES4_COMPRESSION2_D_End                                 26
#define JM_MINOR_FEATURES4_COMPRESSION2_D_Start                               26
#define JM_MINOR_FEATURES4_COMPRESSION2_D_Type                               U01
#define   JM_MINOR_FEATURES4_COMPRESSION2_D_NONE                             0x0
#define   JM_MINOR_FEATURES4_COMPRESSION2_D_AVAILABLE                        0x1

#define JM_MINOR_FEATURES4_PROBE                                           27:27
#define JM_MINOR_FEATURES4_PROBE_End                                          27
#define JM_MINOR_FEATURES4_PROBE_Start                                        27
#define JM_MINOR_FEATURES4_PROBE_Type                                        U01
#define   JM_MINOR_FEATURES4_PROBE_NONE                                      0x0
#define   JM_MINOR_FEATURES4_PROBE_AVAILABLE                                 0x1

#define JM_MINOR_FEATURES4_MEDIUM_PRECISION                                28:28
#define JM_MINOR_FEATURES4_MEDIUM_PRECISION_End                               28
#define JM_MINOR_FEATURES4_MEDIUM_PRECISION_Start                             28
#define JM_MINOR_FEATURES4_MEDIUM_PRECISION_Type                             U01
#define   JM_MINOR_FEATURES4_MEDIUM_PRECISION_NONE                           0x0
#define   JM_MINOR_FEATURES4_MEDIUM_PRECISION_AVAILABLE                      0x1

#define JM_MINOR_FEATURES4_DE_SUPERTILE                                    29:29
#define JM_MINOR_FEATURES4_DE_SUPERTILE_End                                   29
#define JM_MINOR_FEATURES4_DE_SUPERTILE_Start                                 29
#define JM_MINOR_FEATURES4_DE_SUPERTILE_Type                                 U01
#define   JM_MINOR_FEATURES4_DE_SUPERTILE_NONE                               0x0
#define   JM_MINOR_FEATURES4_DE_SUPERTILE_AVAILABLE                          0x1

#define JM_MINOR_FEATURES4_BUG_FIXES19                                     30:30
#define JM_MINOR_FEATURES4_BUG_FIXES19_End                                    30
#define JM_MINOR_FEATURES4_BUG_FIXES19_Start                                  30
#define JM_MINOR_FEATURES4_BUG_FIXES19_Type                                  U01
#define   JM_MINOR_FEATURES4_BUG_FIXES19_NONE                                0x0
#define   JM_MINOR_FEATURES4_BUG_FIXES19_AVAILABLE                           0x1

#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS6                                31:31
#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS6_End                               31
#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS6_Start                             31
#define JM_MINOR_FEATURES4_SH_ENHANCEMENTS6_Type                             U01
#define   JM_MINOR_FEATURES4_SH_ENHANCEMENTS6_NONE                           0x0
#define   JM_MINOR_FEATURES4_SH_ENHANCEMENTS6_AVAILABLE                      0x1



#define mwv207regHIChipPatchRevRegAddrs                                   0x0026
#define MWV207REG_HI_CHIP_PATCH_REV_Address                              0x00098
#define MWV207REG_HI_CHIP_PATCH_REV_MSB                                       15
#define MWV207REG_HI_CHIP_PATCH_REV_LSB                                        0
#define MWV207REG_HI_CHIP_PATCH_REV_BLK                                        0
#define MWV207REG_HI_CHIP_PATCH_REV_Count                                      1
#define MWV207REG_HI_CHIP_PATCH_REV_FieldMask                         0x000000FF
#define MWV207REG_HI_CHIP_PATCH_REV_ReadMask                          0x000000FF
#define MWV207REG_HI_CHIP_PATCH_REV_WriteMask                         0x00000000
#define MWV207REG_HI_CHIP_PATCH_REV_ResetValue                        0x00000000


#define MWV207REG_HI_CHIP_PATCH_REV_PATCH_REV                                7:0
#define MWV207REG_HI_CHIP_PATCH_REV_PATCH_REV_End                              7
#define MWV207REG_HI_CHIP_PATCH_REV_PATCH_REV_Start                            0
#define MWV207REG_HI_CHIP_PATCH_REV_PATCH_REV_Type                           U08



#define mwv207regHIChipSpecs4RegAddrs                                     0x0027
#define MWV207REG_HI_CHIP_SPECS4_Address                                 0x0009C
#define MWV207REG_HI_CHIP_SPECS4_MSB                                          15
#define MWV207REG_HI_CHIP_SPECS4_LSB                                           0
#define MWV207REG_HI_CHIP_SPECS4_BLK                                           0
#define MWV207REG_HI_CHIP_SPECS4_Count                                         1
#define MWV207REG_HI_CHIP_SPECS4_FieldMask                            0x007FF3FF
#define MWV207REG_HI_CHIP_SPECS4_ReadMask                             0x007FF3FF
#define MWV207REG_HI_CHIP_SPECS4_WriteMask                            0x00000000
#define MWV207REG_HI_CHIP_SPECS4_ResetValue                           0x00000000


#define MWV207REG_HI_CHIP_SPECS4_INSTRUCTION_MEMORY                          3:0
#define MWV207REG_HI_CHIP_SPECS4_INSTRUCTION_MEMORY_End                        3
#define MWV207REG_HI_CHIP_SPECS4_INSTRUCTION_MEMORY_Start                      0
#define MWV207REG_HI_CHIP_SPECS4_INSTRUCTION_MEMORY_Type                     U04


#define MWV207REG_HI_CHIP_SPECS4_SHADER_PC_LENGTH                            9:4
#define MWV207REG_HI_CHIP_SPECS4_SHADER_PC_LENGTH_End                          9
#define MWV207REG_HI_CHIP_SPECS4_SHADER_PC_LENGTH_Start                        4
#define MWV207REG_HI_CHIP_SPECS4_SHADER_PC_LENGTH_Type                       U06


#define MWV207REG_HI_CHIP_SPECS4_STREAM_COUNT                              16:12
#define MWV207REG_HI_CHIP_SPECS4_STREAM_COUNT_End                             16
#define MWV207REG_HI_CHIP_SPECS4_STREAM_COUNT_Start                           12
#define MWV207REG_HI_CHIP_SPECS4_STREAM_COUNT_Type                           U05


#define MWV207REG_HI_CHIP_SPECS4_NN_CONV_CORE_COUNT                        22:17
#define MWV207REG_HI_CHIP_SPECS4_NN_CONV_CORE_COUNT_End                       22
#define MWV207REG_HI_CHIP_SPECS4_NN_CONV_CORE_COUNT_Start                     17
#define MWV207REG_HI_CHIP_SPECS4_NN_CONV_CORE_COUNT_Type                     U06



#define JMMinorFeatures5RegAddrs                                          0x0028
#define JM_MINOR_FEATURES5_Address                                       0x000A0
#define JM_MINOR_FEATURES5_MSB                                                15
#define JM_MINOR_FEATURES5_LSB                                                 0
#define JM_MINOR_FEATURES5_BLK                                                 0
#define JM_MINOR_FEATURES5_Count                                               1
#define JM_MINOR_FEATURES5_FieldMask                                  0xFFFFFFFF
#define JM_MINOR_FEATURES5_ReadMask                                   0xFFFFFFFF
#define JM_MINOR_FEATURES5_WriteMask                                  0x00000000
#define JM_MINOR_FEATURES5_ResetValue                                 0x00000000

#define JM_MINOR_FEATURES5_SH_ENHANCEMENTS7                                  0:0
#define JM_MINOR_FEATURES5_SH_ENHANCEMENTS7_End                                0
#define JM_MINOR_FEATURES5_SH_ENHANCEMENTS7_Start                              0
#define JM_MINOR_FEATURES5_SH_ENHANCEMENTS7_Type                             U01
#define   JM_MINOR_FEATURES5_SH_ENHANCEMENTS7_NONE                           0x0
#define   JM_MINOR_FEATURES5_SH_ENHANCEMENTS7_AVAILABLE                      0x1

#define JM_MINOR_FEATURES5_BUG_FIXES20                                       1:1
#define JM_MINOR_FEATURES5_BUG_FIXES20_End                                     1
#define JM_MINOR_FEATURES5_BUG_FIXES20_Start                                   1
#define JM_MINOR_FEATURES5_BUG_FIXES20_Type                                  U01
#define   JM_MINOR_FEATURES5_BUG_FIXES20_NONE                                0x0
#define   JM_MINOR_FEATURES5_BUG_FIXES20_AVAILABLE                           0x1


#define JM_MINOR_FEATURES5_DE_ADDRESS40                                      2:2
#define JM_MINOR_FEATURES5_DE_ADDRESS40_End                                    2
#define JM_MINOR_FEATURES5_DE_ADDRESS40_Start                                  2
#define JM_MINOR_FEATURES5_DE_ADDRESS40_Type                                 U01
#define   JM_MINOR_FEATURES5_DE_ADDRESS40_NONE                               0x0
#define   JM_MINOR_FEATURES5_DE_ADDRESS40_AVAILABLE                          0x1

#define JM_MINOR_FEATURES5_MINI_MMU_FIX                                      3:3
#define JM_MINOR_FEATURES5_MINI_MMU_FIX_End                                    3
#define JM_MINOR_FEATURES5_MINI_MMU_FIX_Start                                  3
#define JM_MINOR_FEATURES5_MINI_MMU_FIX_Type                                 U01
#define   JM_MINOR_FEATURES5_MINI_MMU_FIX_NONE                               0x0
#define   JM_MINOR_FEATURES5_MINI_MMU_FIX_AVAILABLE                          0x1

#define JM_MINOR_FEATURES5_EEZ                                               4:4
#define JM_MINOR_FEATURES5_EEZ_End                                             4
#define JM_MINOR_FEATURES5_EEZ_Start                                           4
#define JM_MINOR_FEATURES5_EEZ_Type                                          U01
#define   JM_MINOR_FEATURES5_EEZ_NONE                                        0x0
#define   JM_MINOR_FEATURES5_EEZ_AVAILABLE                                   0x1

#define JM_MINOR_FEATURES5_BUG_FIXES21                                       5:5
#define JM_MINOR_FEATURES5_BUG_FIXES21_End                                     5
#define JM_MINOR_FEATURES5_BUG_FIXES21_Start                                   5
#define JM_MINOR_FEATURES5_BUG_FIXES21_Type                                  U01
#define   JM_MINOR_FEATURES5_BUG_FIXES21_NONE                                0x0
#define   JM_MINOR_FEATURES5_BUG_FIXES21_AVAILABLE                           0x1

#define JM_MINOR_FEATURES5_EXTRA_VG_CAPS                                     6:6
#define JM_MINOR_FEATURES5_EXTRA_VG_CAPS_End                                   6
#define JM_MINOR_FEATURES5_EXTRA_VG_CAPS_Start                                 6
#define JM_MINOR_FEATURES5_EXTRA_VG_CAPS_Type                                U01
#define   JM_MINOR_FEATURES5_EXTRA_VG_CAPS_NONE                              0x0
#define   JM_MINOR_FEATURES5_EXTRA_VG_CAPS_AVAILABLE                         0x1

#define JM_MINOR_FEATURES5_MULTI_SRC_V15                                     7:7
#define JM_MINOR_FEATURES5_MULTI_SRC_V15_End                                   7
#define JM_MINOR_FEATURES5_MULTI_SRC_V15_Start                                 7
#define JM_MINOR_FEATURES5_MULTI_SRC_V15_Type                                U01
#define   JM_MINOR_FEATURES5_MULTI_SRC_V15_NONE                              0x0
#define   JM_MINOR_FEATURES5_MULTI_SRC_V15_AVAILABLE                         0x1

#define JM_MINOR_FEATURES5_BUG_FIXES22                                       8:8
#define JM_MINOR_FEATURES5_BUG_FIXES22_End                                     8
#define JM_MINOR_FEATURES5_BUG_FIXES22_Start                                   8
#define JM_MINOR_FEATURES5_BUG_FIXES22_Type                                  U01
#define   JM_MINOR_FEATURES5_BUG_FIXES22_NONE                                0x0
#define   JM_MINOR_FEATURES5_BUG_FIXES22_AVAILABLE                           0x1

#define JM_MINOR_FEATURES5_HALTI3                                            9:9
#define JM_MINOR_FEATURES5_HALTI3_End                                          9
#define JM_MINOR_FEATURES5_HALTI3_Start                                        9
#define JM_MINOR_FEATURES5_HALTI3_Type                                       U01
#define   JM_MINOR_FEATURES5_HALTI3_NONE                                     0x0
#define   JM_MINOR_FEATURES5_HALTI3_AVAILABLE                                0x1


#define JM_MINOR_FEATURES5_TESSELLATION_SHADERS                            10:10
#define JM_MINOR_FEATURES5_TESSELLATION_SHADERS_End                           10
#define JM_MINOR_FEATURES5_TESSELLATION_SHADERS_Start                         10
#define JM_MINOR_FEATURES5_TESSELLATION_SHADERS_Type                         U01
#define   JM_MINOR_FEATURES5_TESSELLATION_SHADERS_NONE                       0x0
#define   JM_MINOR_FEATURES5_TESSELLATION_SHADERS_AVAILABLE                  0x1

#define JM_MINOR_FEATURES5_OPF9_TAP                                        11:11
#define JM_MINOR_FEATURES5_OPF9_TAP_End                                       11
#define JM_MINOR_FEATURES5_OPF9_TAP_Start                                     11
#define JM_MINOR_FEATURES5_OPF9_TAP_Type                                     U01
#define   JM_MINOR_FEATURES5_OPF9_TAP_NONE                                   0x0
#define   JM_MINOR_FEATURES5_OPF9_TAP_AVAILABLE                              0x1

#define JM_MINOR_FEATURES5_MULTI_SRC_V2_STR_QUAD                           12:12
#define JM_MINOR_FEATURES5_MULTI_SRC_V2_STR_QUAD_End                          12
#define JM_MINOR_FEATURES5_MULTI_SRC_V2_STR_QUAD_Start                        12
#define JM_MINOR_FEATURES5_MULTI_SRC_V2_STR_QUAD_Type                        U01
#define   JM_MINOR_FEATURES5_MULTI_SRC_V2_STR_QUAD_NONE                      0x0
#define   JM_MINOR_FEATURES5_MULTI_SRC_V2_STR_QUAD_AVAILABLE                 0x1

#define JM_MINOR_FEATURES5_SEPERATE_SRC_AND_DST_CACHE                      13:13
#define JM_MINOR_FEATURES5_SEPERATE_SRC_AND_DST_CACHE_End                     13
#define JM_MINOR_FEATURES5_SEPERATE_SRC_AND_DST_CACHE_Start                   13
#define JM_MINOR_FEATURES5_SEPERATE_SRC_AND_DST_CACHE_Type                   U01
#define   JM_MINOR_FEATURES5_SEPERATE_SRC_AND_DST_CACHE_NONE                 0x0
#define   JM_MINOR_FEATURES5_SEPERATE_SRC_AND_DST_CACHE_AVAILABLE            0x1

#define JM_MINOR_FEATURES5_HALTI4                                          14:14
#define JM_MINOR_FEATURES5_HALTI4_End                                         14
#define JM_MINOR_FEATURES5_HALTI4_Start                                       14
#define JM_MINOR_FEATURES5_HALTI4_Type                                       U01
#define   JM_MINOR_FEATURES5_HALTI4_NONE                                     0x0
#define   JM_MINOR_FEATURES5_HALTI4_AVAILABLE                                0x1

#define JM_MINOR_FEATURES5_RA_WRITE_DEPTH                                  15:15
#define JM_MINOR_FEATURES5_RA_WRITE_DEPTH_End                                 15
#define JM_MINOR_FEATURES5_RA_WRITE_DEPTH_Start                               15
#define JM_MINOR_FEATURES5_RA_WRITE_DEPTH_Type                               U01
#define   JM_MINOR_FEATURES5_RA_WRITE_DEPTH_NONE                             0x0
#define   JM_MINOR_FEATURES5_RA_WRITE_DEPTH_AVAILABLE                        0x1

#define JM_MINOR_FEATURES5_ANDROID_ONLY                                    16:16
#define JM_MINOR_FEATURES5_ANDROID_ONLY_End                                   16
#define JM_MINOR_FEATURES5_ANDROID_ONLY_Start                                 16
#define JM_MINOR_FEATURES5_ANDROID_ONLY_Type                                 U01
#define   JM_MINOR_FEATURES5_ANDROID_ONLY_NONE                               0x0
#define   JM_MINOR_FEATURES5_ANDROID_ONLY_AVAILABLE                          0x1

#define JM_MINOR_FEATURES5_HAS_CHIP_PRODUCT_REG                            17:17
#define JM_MINOR_FEATURES5_HAS_CHIP_PRODUCT_REG_End                           17
#define JM_MINOR_FEATURES5_HAS_CHIP_PRODUCT_REG_Start                         17
#define JM_MINOR_FEATURES5_HAS_CHIP_PRODUCT_REG_Type                         U01
#define   JM_MINOR_FEATURES5_HAS_CHIP_PRODUCT_REG_NONE                       0x0
#define   JM_MINOR_FEATURES5_HAS_CHIP_PRODUCT_REG_AVAILABLE                  0x1

#define JM_MINOR_FEATURES5_TX_SUPPORT_DEC                                  18:18
#define JM_MINOR_FEATURES5_TX_SUPPORT_DEC_End                                 18
#define JM_MINOR_FEATURES5_TX_SUPPORT_DEC_Start                               18
#define JM_MINOR_FEATURES5_TX_SUPPORT_DEC_Type                               U01
#define   JM_MINOR_FEATURES5_TX_SUPPORT_DEC_NONE                             0x0
#define   JM_MINOR_FEATURES5_TX_SUPPORT_DEC_AVAILABLE                        0x1

#define JM_MINOR_FEATURES5_S8_MSAA_COMPRESSION                             19:19
#define JM_MINOR_FEATURES5_S8_MSAA_COMPRESSION_End                            19
#define JM_MINOR_FEATURES5_S8_MSAA_COMPRESSION_Start                          19
#define JM_MINOR_FEATURES5_S8_MSAA_COMPRESSION_Type                          U01
#define   JM_MINOR_FEATURES5_S8_MSAA_COMPRESSION_NONE                        0x0
#define   JM_MINOR_FEATURES5_S8_MSAA_COMPRESSION_AVAILABLE                   0x1

#define JM_MINOR_FEATURES5_BUG_FIXES_IN544                                 20:20
#define JM_MINOR_FEATURES5_BUG_FIXES_IN544_End                                20
#define JM_MINOR_FEATURES5_BUG_FIXES_IN544_Start                              20
#define JM_MINOR_FEATURES5_BUG_FIXES_IN544_Type                              U01
#define   JM_MINOR_FEATURES5_BUG_FIXES_IN544_NONE                            0x0
#define   JM_MINOR_FEATURES5_BUG_FIXES_IN544_AVAILABLE                       0x1

#define JM_MINOR_FEATURES5_L2_CACHE_REMOVE                                 21:21
#define JM_MINOR_FEATURES5_L2_CACHE_REMOVE_End                                21
#define JM_MINOR_FEATURES5_L2_CACHE_REMOVE_Start                              21
#define JM_MINOR_FEATURES5_L2_CACHE_REMOVE_Type                              U01
#define   JM_MINOR_FEATURES5_L2_CACHE_REMOVE_NONE                            0x0
#define   JM_MINOR_FEATURES5_L2_CACHE_REMOVE_AVAILABLE                       0x1

#define JM_MINOR_FEATURES5_FE_ALLOW_RND_VTX_CNT                            22:22
#define JM_MINOR_FEATURES5_FE_ALLOW_RND_VTX_CNT_End                           22
#define JM_MINOR_FEATURES5_FE_ALLOW_RND_VTX_CNT_Start                         22
#define JM_MINOR_FEATURES5_FE_ALLOW_RND_VTX_CNT_Type                         U01
#define   JM_MINOR_FEATURES5_FE_ALLOW_RND_VTX_CNT_NONE                       0x0
#define   JM_MINOR_FEATURES5_FE_ALLOW_RND_VTX_CNT_AVAILABLE                  0x1

#define JM_MINOR_FEATURES5_CUBE_MAP_FL28                                   23:23
#define JM_MINOR_FEATURES5_CUBE_MAP_FL28_End                                  23
#define JM_MINOR_FEATURES5_CUBE_MAP_FL28_Start                                23
#define JM_MINOR_FEATURES5_CUBE_MAP_FL28_Type                                U01
#define   JM_MINOR_FEATURES5_CUBE_MAP_FL28_NONE                              0x0
#define   JM_MINOR_FEATURES5_CUBE_MAP_FL28_AVAILABLE                         0x1

#define JM_MINOR_FEATURES5_TX6BIT_FRAC                                     24:24
#define JM_MINOR_FEATURES5_TX6BIT_FRAC_End                                    24
#define JM_MINOR_FEATURES5_TX6BIT_FRAC_Start                                  24
#define JM_MINOR_FEATURES5_TX6BIT_FRAC_Type                                  U01
#define   JM_MINOR_FEATURES5_TX6BIT_FRAC_NONE                                0x0
#define   JM_MINOR_FEATURES5_TX6BIT_FRAC_AVAILABLE                           0x1

#define JM_MINOR_FEATURES5_FE_ALLOW_STALL_PREFETCH_ENG                     25:25
#define JM_MINOR_FEATURES5_FE_ALLOW_STALL_PREFETCH_ENG_End                    25
#define JM_MINOR_FEATURES5_FE_ALLOW_STALL_PREFETCH_ENG_Start                  25
#define JM_MINOR_FEATURES5_FE_ALLOW_STALL_PREFETCH_ENG_Type                  U01
#define   JM_MINOR_FEATURES5_FE_ALLOW_STALL_PREFETCH_ENG_NONE                0x0
#define   JM_MINOR_FEATURES5_FE_ALLOW_STALL_PREFETCH_ENG_AVAILABLE           0x1

#define JM_MINOR_FEATURES5_THIRD_PARTY_COMPRESSION                         26:26
#define JM_MINOR_FEATURES5_THIRD_PARTY_COMPRESSION_End                        26
#define JM_MINOR_FEATURES5_THIRD_PARTY_COMPRESSION_Start                      26
#define JM_MINOR_FEATURES5_THIRD_PARTY_COMPRESSION_Type                      U01
#define   JM_MINOR_FEATURES5_THIRD_PARTY_COMPRESSION_NONE                    0x0
#define   JM_MINOR_FEATURES5_THIRD_PARTY_COMPRESSION_AVAILABLE               0x1

#define JM_MINOR_FEATURES5_RSS8                                            27:27
#define JM_MINOR_FEATURES5_RSS8_End                                           27
#define JM_MINOR_FEATURES5_RSS8_Start                                         27
#define JM_MINOR_FEATURES5_RSS8_Type                                         U01
#define   JM_MINOR_FEATURES5_RSS8_NONE                                       0x0
#define   JM_MINOR_FEATURES5_RSS8_AVAILABLE                                  0x1

#define JM_MINOR_FEATURES5_MSAA_COHERENCY_CHECK                            28:28
#define JM_MINOR_FEATURES5_MSAA_COHERENCY_CHECK_End                           28
#define JM_MINOR_FEATURES5_MSAA_COHERENCY_CHECK_Start                         28
#define JM_MINOR_FEATURES5_MSAA_COHERENCY_CHECK_Type                         U01
#define   JM_MINOR_FEATURES5_MSAA_COHERENCY_CHECK_NONE                       0x0
#define   JM_MINOR_FEATURES5_MSAA_COHERENCY_CHECK_AVAILABLE                  0x1

#define JM_MINOR_FEATURES5_HALTI5                                          29:29
#define JM_MINOR_FEATURES5_HALTI5_End                                         29
#define JM_MINOR_FEATURES5_HALTI5_Start                                       29
#define JM_MINOR_FEATURES5_HALTI5_Type                                       U01
#define   JM_MINOR_FEATURES5_HALTI5_NONE                                     0x0
#define   JM_MINOR_FEATURES5_HALTI5_AVAILABLE                                0x1

#define JM_MINOR_FEATURES5_EVIS                                            30:30
#define JM_MINOR_FEATURES5_EVIS_End                                           30
#define JM_MINOR_FEATURES5_EVIS_Start                                         30
#define JM_MINOR_FEATURES5_EVIS_Type                                         U01
#define   JM_MINOR_FEATURES5_EVIS_NONE                                       0x0
#define   JM_MINOR_FEATURES5_EVIS_AVAILABLE                                  0x1

#define JM_MINOR_FEATURES5_BLT_ENGINE                                      31:31
#define JM_MINOR_FEATURES5_BLT_ENGINE_End                                     31
#define JM_MINOR_FEATURES5_BLT_ENGINE_Start                                   31
#define JM_MINOR_FEATURES5_BLT_ENGINE_Type                                   U01
#define   JM_MINOR_FEATURES5_BLT_ENGINE_NONE                                 0x0
#define   JM_MINOR_FEATURES5_BLT_ENGINE_AVAILABLE                            0x1



#define jmChipInfoRegAddrs                                                0x0029
#define JM_CHIP_INFO_Address                                             0x000A4
#define JM_CHIP_INFO_MSB                                                      15
#define JM_CHIP_INFO_LSB                                                       0
#define JM_CHIP_INFO_BLK                                                       0
#define JM_CHIP_INFO_Count                                                     1
#define JM_CHIP_INFO_FieldMask                                        0x7F33333F
#define JM_CHIP_INFO_ReadMask                                         0x7F33333F
#define JM_CHIP_INFO_WriteMask                                        0x00000000
#define JM_CHIP_INFO_ResetValue                                       0x00000000


#define JM_CHIP_INFO_ENGINE2_D                                               0:0
#define JM_CHIP_INFO_ENGINE2_D_End                                             0
#define JM_CHIP_INFO_ENGINE2_D_Start                                           0
#define JM_CHIP_INFO_ENGINE2_D_Type                                          U01
#define   JM_CHIP_INFO_ENGINE2_D_NONE                                        0x0
#define   JM_CHIP_INFO_ENGINE2_D_AVAILABLE                                   0x1


#define JM_CHIP_INFO_ENGINE3_D                                               1:1
#define JM_CHIP_INFO_ENGINE3_D_End                                             1
#define JM_CHIP_INFO_ENGINE3_D_Start                                           1
#define JM_CHIP_INFO_ENGINE3_D_Type                                          U01
#define   JM_CHIP_INFO_ENGINE3_D_NONE                                        0x0
#define   JM_CHIP_INFO_ENGINE3_D_AVAILABLE                                   0x1


#define JM_CHIP_INFO_ENGINE_VG                                               2:2
#define JM_CHIP_INFO_ENGINE_VG_End                                             2
#define JM_CHIP_INFO_ENGINE_VG_Start                                           2
#define JM_CHIP_INFO_ENGINE_VG_Type                                          U01
#define   JM_CHIP_INFO_ENGINE_VG_NONE                                        0x0
#define   JM_CHIP_INFO_ENGINE_VG_AVAILABLE                                   0x1


#define JM_CHIP_INFO_ENGINE_DEC                                              3:3
#define JM_CHIP_INFO_ENGINE_DEC_End                                            3
#define JM_CHIP_INFO_ENGINE_DEC_Start                                          3
#define JM_CHIP_INFO_ENGINE_DEC_Type                                         U01
#define   JM_CHIP_INFO_ENGINE_DEC_NONE                                       0x0
#define   JM_CHIP_INFO_ENGINE_DEC_AVAILABLE                                  0x1


#define JM_CHIP_INFO_ENGINE_DC                                               4:4
#define JM_CHIP_INFO_ENGINE_DC_End                                             4
#define JM_CHIP_INFO_ENGINE_DC_Start                                           4
#define JM_CHIP_INFO_ENGINE_DC_Type                                          U01
#define   JM_CHIP_INFO_ENGINE_DC_NONE                                        0x0
#define   JM_CHIP_INFO_ENGINE_DC_AVAILABLE                                   0x1


#define JM_CHIP_INFO_ENGINE_SC                                               5:5
#define JM_CHIP_INFO_ENGINE_SC_End                                             5
#define JM_CHIP_INFO_ENGINE_SC_Start                                           5
#define JM_CHIP_INFO_ENGINE_SC_Type                                          U01
#define   JM_CHIP_INFO_ENGINE_SC_NONE                                        0x0
#define   JM_CHIP_INFO_ENGINE_SC_AVAILABLE                                   0x1


#define JM_CHIP_INFO_ONE_SET_BUS                                             8:8
#define JM_CHIP_INFO_ONE_SET_BUS_End                                           8
#define JM_CHIP_INFO_ONE_SET_BUS_Start                                         8
#define JM_CHIP_INFO_ONE_SET_BUS_Type                                        U01
#define   JM_CHIP_INFO_ONE_SET_BUS_NONE                                      0x0
#define   JM_CHIP_INFO_ONE_SET_BUS_AVAILABLE                                 0x1


#define JM_CHIP_INFO_TWO_SET_BUS                                             9:9
#define JM_CHIP_INFO_TWO_SET_BUS_End                                           9
#define JM_CHIP_INFO_TWO_SET_BUS_Start                                         9
#define JM_CHIP_INFO_TWO_SET_BUS_Type                                        U01
#define   JM_CHIP_INFO_TWO_SET_BUS_NONE                                      0x0
#define   JM_CHIP_INFO_TWO_SET_BUS_AVAILABLE                                 0x1


#define JM_CHIP_INFO_INTERFACE_AHB                                         12:12
#define JM_CHIP_INFO_INTERFACE_AHB_End                                        12
#define JM_CHIP_INFO_INTERFACE_AHB_Start                                      12
#define JM_CHIP_INFO_INTERFACE_AHB_Type                                      U01
#define   JM_CHIP_INFO_INTERFACE_AHB_NONE                                    0x0
#define   JM_CHIP_INFO_INTERFACE_AHB_AVAILABLE                               0x1


#define JM_CHIP_INFO_INTERFACE_APB                                         13:13
#define JM_CHIP_INFO_INTERFACE_APB_End                                        13
#define JM_CHIP_INFO_INTERFACE_APB_Start                                      13
#define JM_CHIP_INFO_INTERFACE_APB_Type                                      U01
#define   JM_CHIP_INFO_INTERFACE_APB_NONE                                    0x0
#define   JM_CHIP_INFO_INTERFACE_APB_AVAILABLE                               0x1


#define JM_CHIP_INFO_ONE_GPU                                               16:16
#define JM_CHIP_INFO_ONE_GPU_End                                              16
#define JM_CHIP_INFO_ONE_GPU_Start                                            16
#define JM_CHIP_INFO_ONE_GPU_Type                                            U01
#define   JM_CHIP_INFO_ONE_GPU_NONE                                          0x0
#define   JM_CHIP_INFO_ONE_GPU_AVAILABLE                                     0x1


#define JM_CHIP_INFO_DUAL_GPU                                              17:17
#define JM_CHIP_INFO_DUAL_GPU_End                                             17
#define JM_CHIP_INFO_DUAL_GPU_Start                                           17
#define JM_CHIP_INFO_DUAL_GPU_Type                                           U01
#define   JM_CHIP_INFO_DUAL_GPU_NONE                                         0x0
#define   JM_CHIP_INFO_DUAL_GPU_AVAILABLE                                    0x1


#define JM_CHIP_INFO_BUS64_BITS                                            20:20
#define JM_CHIP_INFO_BUS64_BITS_End                                           20
#define JM_CHIP_INFO_BUS64_BITS_Start                                         20
#define JM_CHIP_INFO_BUS64_BITS_Type                                         U01
#define   JM_CHIP_INFO_BUS64_BITS_NONE                                       0x0
#define   JM_CHIP_INFO_BUS64_BITS_AVAILABLE                                  0x1


#define JM_CHIP_INFO_BUS128_BITS                                           21:21
#define JM_CHIP_INFO_BUS128_BITS_End                                          21
#define JM_CHIP_INFO_BUS128_BITS_Start                                        21
#define JM_CHIP_INFO_BUS128_BITS_Type                                        U01
#define   JM_CHIP_INFO_BUS128_BITS_NONE                                      0x0
#define   JM_CHIP_INFO_BUS128_BITS_AVAILABLE                                 0x1


#define JM_CHIP_INFO_DEC200                                                24:24
#define JM_CHIP_INFO_DEC200_End                                               24
#define JM_CHIP_INFO_DEC200_Start                                             24
#define JM_CHIP_INFO_DEC200_Type                                             U01
#define   JM_CHIP_INFO_DEC200_NONE                                           0x0
#define   JM_CHIP_INFO_DEC200_AVAILABLE                                      0x1


#define JM_CHIP_INFO_DEC200D                                               25:25
#define JM_CHIP_INFO_DEC200D_End                                              25
#define JM_CHIP_INFO_DEC200D_Start                                            25
#define JM_CHIP_INFO_DEC200D_Type                                            U01
#define   JM_CHIP_INFO_DEC200D_NONE                                          0x0
#define   JM_CHIP_INFO_DEC200D_AVAILABLE                                     0x1


#define JM_CHIP_INFO_DEC200E                                               26:26
#define JM_CHIP_INFO_DEC200E_End                                              26
#define JM_CHIP_INFO_DEC200E_Start                                            26
#define JM_CHIP_INFO_DEC200E_Type                                            U01
#define   JM_CHIP_INFO_DEC200E_NONE                                          0x0
#define   JM_CHIP_INFO_DEC200E_AVAILABLE                                     0x1


#define JM_CHIP_INFO_DEC200DO                                              27:27
#define JM_CHIP_INFO_DEC200DO_End                                             27
#define JM_CHIP_INFO_DEC200DO_Start                                           27
#define JM_CHIP_INFO_DEC200DO_Type                                           U01
#define   JM_CHIP_INFO_DEC200DO_NONE                                         0x0
#define   JM_CHIP_INFO_DEC200DO_AVAILABLE                                    0x1


#define JM_CHIP_INFO_COMPRESSION                                           28:28
#define JM_CHIP_INFO_COMPRESSION_End                                          28
#define JM_CHIP_INFO_COMPRESSION_Start                                        28
#define JM_CHIP_INFO_COMPRESSION_Type                                        U01
#define   JM_CHIP_INFO_COMPRESSION_NONE                                      0x0
#define   JM_CHIP_INFO_COMPRESSION_AVAILABLE                                 0x1


#define JM_CHIP_INFO_FOUR_PORT_RAM                                         29:29
#define JM_CHIP_INFO_FOUR_PORT_RAM_End                                        29
#define JM_CHIP_INFO_FOUR_PORT_RAM_Start                                      29
#define JM_CHIP_INFO_FOUR_PORT_RAM_Type                                      U01
#define   JM_CHIP_INFO_FOUR_PORT_RAM_NONE                                    0x0
#define   JM_CHIP_INFO_FOUR_PORT_RAM_AVAILABLE                               0x1


#define JM_CHIP_INFO_EXTRA_CLOCK_FOR_SH                                    30:30
#define JM_CHIP_INFO_EXTRA_CLOCK_FOR_SH_End                                   30
#define JM_CHIP_INFO_EXTRA_CLOCK_FOR_SH_Start                                 30
#define JM_CHIP_INFO_EXTRA_CLOCK_FOR_SH_Type                                 U01
#define   JM_CHIP_INFO_EXTRA_CLOCK_FOR_SH_NONE                               0x0
#define   JM_CHIP_INFO_EXTRA_CLOCK_FOR_SH_AVAILABLE                          0x1




#define jmProductIdRegAddrs                                               0x002A
#define JM_PRODUCT_ID_Address                                            0x000A8
#define JM_PRODUCT_ID_MSB                                                     15
#define JM_PRODUCT_ID_LSB                                                      0
#define JM_PRODUCT_ID_BLK                                                      0
#define JM_PRODUCT_ID_Count                                                    1
#define JM_PRODUCT_ID_FieldMask                                       0xFFFFFFFF
#define JM_PRODUCT_ID_ReadMask                                        0xFFFFFFFF
#define JM_PRODUCT_ID_WriteMask                                       0x00000000
#define JM_PRODUCT_ID_ResetValue                                      0x00000000

#define JM_PRODUCT_ID_GRADE_LEVEL                                            3:0
#define JM_PRODUCT_ID_GRADE_LEVEL_End                                          3
#define JM_PRODUCT_ID_GRADE_LEVEL_Start                                        0
#define JM_PRODUCT_ID_GRADE_LEVEL_Type                                       U04

#define JM_PRODUCT_ID_NUM                                                   23:4
#define JM_PRODUCT_ID_NUM_End                                                 23
#define JM_PRODUCT_ID_NUM_Start                                                4
#define JM_PRODUCT_ID_NUM_Type                                               U20

#define JM_PRODUCT_ID_TYPE                                                 27:24
#define JM_PRODUCT_ID_TYPE_End                                                27
#define JM_PRODUCT_ID_TYPE_Start                                              24
#define JM_PRODUCT_ID_TYPE_Type                                              U04


#define JM_PRODUCT_ID_AUX                                                  31:28
#define JM_PRODUCT_ID_AUX_End                                                 31
#define JM_PRODUCT_ID_AUX_Start                                               28
#define JM_PRODUCT_ID_AUX_Type                                               U04




#define jmCustomize0RegAddrs                                              0x002B
#define JM_CUSTOMIZE0_Address                                            0x000AC
#define JM_CUSTOMIZE0_MSB                                                     15
#define JM_CUSTOMIZE0_LSB                                                      0
#define JM_CUSTOMIZE0_BLK                                                      0
#define JM_CUSTOMIZE0_Count                                                    1
#define JM_CUSTOMIZE0_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE0_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE0_WriteMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE0_ResetValue                                      0x00000000


#define JM_CUSTOMIZE0_CONTROL                                               31:0
#define JM_CUSTOMIZE0_CONTROL_End                                             31
#define JM_CUSTOMIZE0_CONTROL_Start                                            0
#define JM_CUSTOMIZE0_CONTROL_Type                                           U32




#define jmCustomize1RegAddrs                                              0x002C
#define JM_CUSTOMIZE1_Address                                            0x000B0
#define JM_CUSTOMIZE1_MSB                                                     15
#define JM_CUSTOMIZE1_LSB                                                      0
#define JM_CUSTOMIZE1_BLK                                                      0
#define JM_CUSTOMIZE1_Count                                                    1
#define JM_CUSTOMIZE1_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE1_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE1_WriteMask                                       0x00000000
#define JM_CUSTOMIZE1_ResetValue                                      0x00000000


#define JM_CUSTOMIZE1_STATUS                                                31:0
#define JM_CUSTOMIZE1_STATUS_End                                              31
#define JM_CUSTOMIZE1_STATUS_Start                                             0
#define JM_CUSTOMIZE1_STATUS_Type                                            U32




#define jmCustomize2RegAddrs                                              0x002D
#define JM_CUSTOMIZE2_Address                                            0x000B4
#define JM_CUSTOMIZE2_MSB                                                     15
#define JM_CUSTOMIZE2_LSB                                                      0
#define JM_CUSTOMIZE2_BLK                                                      0
#define JM_CUSTOMIZE2_Count                                                    1
#define JM_CUSTOMIZE2_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE2_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE2_WriteMask                                       0x00000000
#define JM_CUSTOMIZE2_ResetValue                                      0x00000000


#define JM_CUSTOMIZE2_STATUS                                                31:0
#define JM_CUSTOMIZE2_STATUS_End                                              31
#define JM_CUSTOMIZE2_STATUS_Start                                             0
#define JM_CUSTOMIZE2_STATUS_Type                                            U32




#define jmCustomize3RegAddrs                                              0x002E
#define JM_CUSTOMIZE3_Address                                            0x000B8
#define JM_CUSTOMIZE3_MSB                                                     15
#define JM_CUSTOMIZE3_LSB                                                      0
#define JM_CUSTOMIZE3_BLK                                                      0
#define JM_CUSTOMIZE3_Count                                                    1
#define JM_CUSTOMIZE3_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE3_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE3_WriteMask                                       0x00000000
#define JM_CUSTOMIZE3_ResetValue                                      0x00000000


#define JM_CUSTOMIZE3_STATUS                                                31:0
#define JM_CUSTOMIZE3_STATUS_End                                              31
#define JM_CUSTOMIZE3_STATUS_Start                                             0
#define JM_CUSTOMIZE3_STATUS_Type                                            U32




#define jmCustomize4RegAddrs                                              0x002F
#define JM_CUSTOMIZE4_Address                                            0x000BC
#define JM_CUSTOMIZE4_MSB                                                     15
#define JM_CUSTOMIZE4_LSB                                                      0
#define JM_CUSTOMIZE4_BLK                                                      0
#define JM_CUSTOMIZE4_Count                                                    1
#define JM_CUSTOMIZE4_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE4_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE4_WriteMask                                       0x00000000
#define JM_CUSTOMIZE4_ResetValue                                      0x00000000


#define JM_CUSTOMIZE4_STATUS                                                31:0
#define JM_CUSTOMIZE4_STATUS_End                                              31
#define JM_CUSTOMIZE4_STATUS_Start                                             0
#define JM_CUSTOMIZE4_STATUS_Type                                            U32




#define jmCustomize5RegAddrs                                              0x0030
#define JM_CUSTOMIZE5_Address                                            0x000C0
#define JM_CUSTOMIZE5_MSB                                                     15
#define JM_CUSTOMIZE5_LSB                                                      0
#define JM_CUSTOMIZE5_BLK                                                      0
#define JM_CUSTOMIZE5_Count                                                    1
#define JM_CUSTOMIZE5_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE5_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE5_WriteMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE5_ResetValue                                      0x00000000


#define JM_CUSTOMIZE5_CONTROL                                               31:0
#define JM_CUSTOMIZE5_CONTROL_End                                             31
#define JM_CUSTOMIZE5_CONTROL_Start                                            0
#define JM_CUSTOMIZE5_CONTROL_Type                                           U32




#define jmCustomize6RegAddrs                                              0x0031
#define JM_CUSTOMIZE6_Address                                            0x000C4
#define JM_CUSTOMIZE6_MSB                                                     15
#define JM_CUSTOMIZE6_LSB                                                      0
#define JM_CUSTOMIZE6_BLK                                                      0
#define JM_CUSTOMIZE6_Count                                                    1
#define JM_CUSTOMIZE6_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE6_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE6_WriteMask                                       0x00000000
#define JM_CUSTOMIZE6_ResetValue                                      0x00000000


#define JM_CUSTOMIZE6_STATUS                                                31:0
#define JM_CUSTOMIZE6_STATUS_End                                              31
#define JM_CUSTOMIZE6_STATUS_Start                                             0
#define JM_CUSTOMIZE6_STATUS_Type                                            U32




#define jmCustomize7RegAddrs                                              0x0032
#define JM_CUSTOMIZE7_Address                                            0x000C8
#define JM_CUSTOMIZE7_MSB                                                     15
#define JM_CUSTOMIZE7_LSB                                                      0
#define JM_CUSTOMIZE7_BLK                                                      0
#define JM_CUSTOMIZE7_Count                                                    1
#define JM_CUSTOMIZE7_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE7_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE7_WriteMask                                       0x00000000
#define JM_CUSTOMIZE7_ResetValue                                      0x00000000


#define JM_CUSTOMIZE7_STATUS                                                31:0
#define JM_CUSTOMIZE7_STATUS_End                                              31
#define JM_CUSTOMIZE7_STATUS_Start                                             0
#define JM_CUSTOMIZE7_STATUS_Type                                            U32




#define jmCustomize8RegAddrs                                              0x0033
#define JM_CUSTOMIZE8_Address                                            0x000CC
#define JM_CUSTOMIZE8_MSB                                                     15
#define JM_CUSTOMIZE8_LSB                                                      0
#define JM_CUSTOMIZE8_BLK                                                      0
#define JM_CUSTOMIZE8_Count                                                    1
#define JM_CUSTOMIZE8_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE8_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE8_WriteMask                                       0x00000000
#define JM_CUSTOMIZE8_ResetValue                                      0x00000000


#define JM_CUSTOMIZE8_STATUS                                                31:0
#define JM_CUSTOMIZE8_STATUS_End                                              31
#define JM_CUSTOMIZE8_STATUS_Start                                             0
#define JM_CUSTOMIZE8_STATUS_Type                                            U32




#define jmCustomize9RegAddrs                                              0x0034
#define JM_CUSTOMIZE9_Address                                            0x000D0
#define JM_CUSTOMIZE9_MSB                                                     15
#define JM_CUSTOMIZE9_LSB                                                      0
#define JM_CUSTOMIZE9_BLK                                                      0
#define JM_CUSTOMIZE9_Count                                                    1
#define JM_CUSTOMIZE9_FieldMask                                       0xFFFFFFFF
#define JM_CUSTOMIZE9_ReadMask                                        0xFFFFFFFF
#define JM_CUSTOMIZE9_WriteMask                                       0x00000000
#define JM_CUSTOMIZE9_ResetValue                                      0x00000000


#define JM_CUSTOMIZE9_STATUS                                                31:0
#define JM_CUSTOMIZE9_STATUS_End                                              31
#define JM_CUSTOMIZE9_STATUS_Start                                             0
#define JM_CUSTOMIZE9_STATUS_Type                                            U32



#define AQIntrAcknowledgeExRegAddrs                                       0x0035
#define AQ_INTR_ACKNOWLEDGE_EX_Address                                   0x000D4
#define AQ_INTR_ACKNOWLEDGE_EX_MSB                                            15
#define AQ_INTR_ACKNOWLEDGE_EX_LSB                                             0
#define AQ_INTR_ACKNOWLEDGE_EX_BLK                                             0
#define AQ_INTR_ACKNOWLEDGE_EX_Count                                           1
#define AQ_INTR_ACKNOWLEDGE_EX_FieldMask                              0xFFFFFFFF
#define AQ_INTR_ACKNOWLEDGE_EX_ReadMask                               0xFFFFFFFF
#define AQ_INTR_ACKNOWLEDGE_EX_WriteMask                              0x00000000
#define AQ_INTR_ACKNOWLEDGE_EX_ResetValue                             0x00000000

#define AQ_INTR_ACKNOWLEDGE_EX_INTR_VEC                                     31:0
#define AQ_INTR_ACKNOWLEDGE_EX_INTR_VEC_End                                   31
#define AQ_INTR_ACKNOWLEDGE_EX_INTR_VEC_Start                                  0
#define AQ_INTR_ACKNOWLEDGE_EX_INTR_VEC_Type                                 U32



#define AQIntrEnblExRegAddrs                                              0x0036
#define AQ_INTR_ENBL_EX_Address                                          0x000D8
#define AQ_INTR_ENBL_EX_MSB                                                   15
#define AQ_INTR_ENBL_EX_LSB                                                    0
#define AQ_INTR_ENBL_EX_BLK                                                    0
#define AQ_INTR_ENBL_EX_Count                                                  1
#define AQ_INTR_ENBL_EX_FieldMask                                     0xFFFFFFFF
#define AQ_INTR_ENBL_EX_ReadMask                                      0xFFFFFFFF
#define AQ_INTR_ENBL_EX_WriteMask                                     0xFFFFFFFF
#define AQ_INTR_ENBL_EX_ResetValue                                    0x00000000

#define AQ_INTR_ENBL_EX_INTR_ENBL_VEC                                       31:0
#define AQ_INTR_ENBL_EX_INTR_ENBL_VEC_End                                     31
#define AQ_INTR_ENBL_EX_INTR_ENBL_VEC_Start                                    0
#define AQ_INTR_ENBL_EX_INTR_ENBL_VEC_Type                                   U32



#define JMMinorFeatures6RegAddrs                                          0x0037
#define JM_MINOR_FEATURES6_Address                                       0x000DC
#define JM_MINOR_FEATURES6_MSB                                                15
#define JM_MINOR_FEATURES6_LSB                                                 0
#define JM_MINOR_FEATURES6_BLK                                                 0
#define JM_MINOR_FEATURES6_Count                                               1
#define JM_MINOR_FEATURES6_FieldMask                                  0x0000003F
#define JM_MINOR_FEATURES6_ReadMask                                   0x0000003F
#define JM_MINOR_FEATURES6_WriteMask                                  0x00000000
#define JM_MINOR_FEATURES6_ResetValue                                 0x00000000

#define JM_MINOR_FEATURES6_BUG_FIXES23                                       0:0
#define JM_MINOR_FEATURES6_BUG_FIXES23_End                                     0
#define JM_MINOR_FEATURES6_BUG_FIXES23_Start                                   0
#define JM_MINOR_FEATURES6_BUG_FIXES23_Type                                  U01
#define   JM_MINOR_FEATURES6_BUG_FIXES23_NONE                                0x0
#define   JM_MINOR_FEATURES6_BUG_FIXES23_AVAILABLE                           0x1

#define JM_MINOR_FEATURES6_BUG_FIXES24                                       1:1
#define JM_MINOR_FEATURES6_BUG_FIXES24_End                                     1
#define JM_MINOR_FEATURES6_BUG_FIXES24_Start                                   1
#define JM_MINOR_FEATURES6_BUG_FIXES24_Type                                  U01
#define   JM_MINOR_FEATURES6_BUG_FIXES24_NONE                                0x0
#define   JM_MINOR_FEATURES6_BUG_FIXES24_AVAILABLE                           0x1


#define JM_MINOR_FEATURES6_DEC                                               2:2
#define JM_MINOR_FEATURES6_DEC_End                                             2
#define JM_MINOR_FEATURES6_DEC_Start                                           2
#define JM_MINOR_FEATURES6_DEC_Type                                          U01
#define   JM_MINOR_FEATURES6_DEC_NONE                                        0x0
#define   JM_MINOR_FEATURES6_DEC_AVAILABLE                                   0x1


#define JM_MINOR_FEATURES6_VS_TILE_NV12                                      3:3
#define JM_MINOR_FEATURES6_VS_TILE_NV12_End                                    3
#define JM_MINOR_FEATURES6_VS_TILE_NV12_Start                                  3
#define JM_MINOR_FEATURES6_VS_TILE_NV12_Type                                 U01
#define   JM_MINOR_FEATURES6_VS_TILE_NV12_NONE                               0x0
#define   JM_MINOR_FEATURES6_VS_TILE_NV12_AVAILABLE                          0x1


#define JM_MINOR_FEATURES6_VS_TILE_NV12_10BIT                                4:4
#define JM_MINOR_FEATURES6_VS_TILE_NV12_10BIT_End                              4
#define JM_MINOR_FEATURES6_VS_TILE_NV12_10BIT_Start                            4
#define JM_MINOR_FEATURES6_VS_TILE_NV12_10BIT_Type                           U01
#define   JM_MINOR_FEATURES6_VS_TILE_NV12_10BIT_NONE                         0x0
#define   JM_MINOR_FEATURES6_VS_TILE_NV12_10BIT_AVAILABLE                    0x1


#define JM_MINOR_FEATURES6_DISABLE_VIP                                       5:5
#define JM_MINOR_FEATURES6_DISABLE_VIP_End                                     5
#define JM_MINOR_FEATURES6_DISABLE_VIP_Start                                   5
#define JM_MINOR_FEATURES6_DISABLE_VIP_Type                                  U01
#define   JM_MINOR_FEATURES6_DISABLE_VIP_NONE                                0x0
#define   JM_MINOR_FEATURES6_DISABLE_VIP_AVAILABLE                           0x1




#define jmRecoverControlRegAddrs                                          0x0038
#define JM_RECOVER_CONTROL_Address                                       0x000E0
#define JM_RECOVER_CONTROL_MSB                                                15
#define JM_RECOVER_CONTROL_LSB                                                 0
#define JM_RECOVER_CONTROL_BLK                                                 0
#define JM_RECOVER_CONTROL_Count                                               1
#define JM_RECOVER_CONTROL_FieldMask                                  0x00000003
#define JM_RECOVER_CONTROL_ReadMask                                   0x00000003
#define JM_RECOVER_CONTROL_WriteMask                                  0x00000003
#define JM_RECOVER_CONTROL_ResetValue                                 0x00000000


#define JM_RECOVER_CONTROL_ENABLE_RECOVER                                    0:0
#define JM_RECOVER_CONTROL_ENABLE_RECOVER_End                                  0
#define JM_RECOVER_CONTROL_ENABLE_RECOVER_Start                                0
#define JM_RECOVER_CONTROL_ENABLE_RECOVER_Type                               U01
#define   JM_RECOVER_CONTROL_ENABLE_RECOVER_DISABLED                         0x0
#define   JM_RECOVER_CONTROL_ENABLE_RECOVER_ENABLED                          0x1

#define JM_RECOVER_CONTROL_ENABLE_DROP_DATA                                  1:1
#define JM_RECOVER_CONTROL_ENABLE_DROP_DATA_End                                1
#define JM_RECOVER_CONTROL_ENABLE_DROP_DATA_Start                              1
#define JM_RECOVER_CONTROL_ENABLE_DROP_DATA_Type                             U01
#define   JM_RECOVER_CONTROL_ENABLE_DROP_DATA_DISABLED                       0x0
#define   JM_RECOVER_CONTROL_ENABLE_DROP_DATA_ENABLED                        0x1



#define jmRecoverCounterRegAddrs                                          0x0039
#define JM_RECOVER_COUNTER_Address                                       0x000E4
#define JM_RECOVER_COUNTER_MSB                                                15
#define JM_RECOVER_COUNTER_LSB                                                 0
#define JM_RECOVER_COUNTER_BLK                                                 0
#define JM_RECOVER_COUNTER_Count                                               1
#define JM_RECOVER_COUNTER_FieldMask                                  0xFFFFFFFF
#define JM_RECOVER_COUNTER_ReadMask                                   0xFFFFFFFF
#define JM_RECOVER_COUNTER_WriteMask                                  0xFFFFFFFF
#define JM_RECOVER_COUNTER_ResetValue                                 0x00000000

#define JM_RECOVER_COUNTER_COUNTER                                          31:0
#define JM_RECOVER_COUNTER_COUNTER_End                                        31
#define JM_RECOVER_COUNTER_COUNTER_Start                                       0
#define JM_RECOVER_COUNTER_COUNTER_Type                                      U32



#define jmEcoIdRegAddrs                                                   0x003A
#define JM_ECO_ID_Address                                                0x000E8
#define JM_ECO_ID_MSB                                                         15
#define JM_ECO_ID_LSB                                                          0
#define JM_ECO_ID_BLK                                                          0
#define JM_ECO_ID_Count                                                        1
#define JM_ECO_ID_FieldMask                                           0xFF0000FF
#define JM_ECO_ID_ReadMask                                            0xFF0000FF
#define JM_ECO_ID_WriteMask                                           0x00000000
#define JM_ECO_ID_ResetValue                                          0x00000000


#define JM_ECO_ID_ID                                                         7:0
#define JM_ECO_ID_ID_End                                                       7
#define JM_ECO_ID_ID_Start                                                     0
#define JM_ECO_ID_ID_Type                                                    U08

#define JM_ECO_ID_CONV_COUNT                                               31:24
#define JM_ECO_ID_CONV_COUNT_End                                              31
#define JM_ECO_ID_CONV_COUNT_Start                                            24
#define JM_ECO_ID_CONV_COUNT_Type                                            U08



#define jmUserModeConfigRegAddrs                                          0x003B
#define JM_USER_MODE_CONFIG_Address                                      0x000EC
#define JM_USER_MODE_CONFIG_MSB                                               15
#define JM_USER_MODE_CONFIG_LSB                                                0
#define JM_USER_MODE_CONFIG_BLK                                                0
#define JM_USER_MODE_CONFIG_Count                                              1
#define JM_USER_MODE_CONFIG_FieldMask                                 0x000001FF
#define JM_USER_MODE_CONFIG_ReadMask                                  0x000001FF
#define JM_USER_MODE_CONFIG_WriteMask                                 0x000001FF
#define JM_USER_MODE_CONFIG_ResetValue                                0x00000000


#define JM_USER_MODE_CONFIG_USER_MODE                                        7:0
#define JM_USER_MODE_CONFIG_USER_MODE_End                                      7
#define JM_USER_MODE_CONFIG_USER_MODE_Start                                    0
#define JM_USER_MODE_CONFIG_USER_MODE_Type                                   U08
#define   JM_USER_MODE_CONFIG_USER_MODE_BY_PASS_MODE                        0x00
#define   JM_USER_MODE_CONFIG_USER_MODE_POLICY_ID_MODE                      0x01


#define JM_USER_MODE_CONFIG_POLICY_ID_MODE_SW_AUX_BIT                        8:8
#define JM_USER_MODE_CONFIG_POLICY_ID_MODE_SW_AUX_BIT_End                      8
#define JM_USER_MODE_CONFIG_POLICY_ID_MODE_SW_AUX_BIT_Start                    8
#define JM_USER_MODE_CONFIG_POLICY_ID_MODE_SW_AUX_BIT_Type                   U01

#define jmDebugControl4RegAddrs                                           0x003C
#define JM_DEBUG_CONTROL4_Address                                        0x000F0
#define JM_DEBUG_CONTROL4_MSB                                                 15
#define JM_DEBUG_CONTROL4_LSB                                                  0
#define JM_DEBUG_CONTROL4_BLK                                                  0
#define JM_DEBUG_CONTROL4_Count                                                1
#define JM_DEBUG_CONTROL4_FieldMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL4_ReadMask                                    0xFFFFFFFF
#define JM_DEBUG_CONTROL4_WriteMask                                   0xFFFFFFFF
#define JM_DEBUG_CONTROL4_ResetValue                                  0x00000000

#define JM_DEBUG_CONTROL4_FE                                                 7:0
#define JM_DEBUG_CONTROL4_FE_End                                               7
#define JM_DEBUG_CONTROL4_FE_Start                                             0
#define JM_DEBUG_CONTROL4_FE_Type                                            U08

#define JM_DEBUG_CONTROL4_HI                                                15:8
#define JM_DEBUG_CONTROL4_HI_End                                              15
#define JM_DEBUG_CONTROL4_HI_Start                                             8
#define JM_DEBUG_CONTROL4_HI_Type                                            U08

#define JM_DEBUG_CONTROL4_WD                                               23:16
#define JM_DEBUG_CONTROL4_WD_End                                              23
#define JM_DEBUG_CONTROL4_WD_Start                                            16
#define JM_DEBUG_CONTROL4_WD_Type                                            U08

#define JM_DEBUG_CONTROL4_DIR                                              31:24
#define JM_DEBUG_CONTROL4_DIR_End                                             31
#define JM_DEBUG_CONTROL4_DIR_Start                                           24
#define JM_DEBUG_CONTROL4_DIR_Type                                           U08




#define jmDebugSignalsWdRegAddrs                                          0x003D
#define JM_DEBUG_SIGNALS_WD_Address                                      0x000F4
#define JM_DEBUG_SIGNALS_WD_MSB                                               15
#define JM_DEBUG_SIGNALS_WD_LSB                                                0
#define JM_DEBUG_SIGNALS_WD_BLK                                                0
#define JM_DEBUG_SIGNALS_WD_Count                                              1
#define JM_DEBUG_SIGNALS_WD_FieldMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_WD_ReadMask                                  0xFFFFFFFF
#define JM_DEBUG_SIGNALS_WD_WriteMask                                 0x00000000
#define JM_DEBUG_SIGNALS_WD_ResetValue                                0x00000000


#define JM_DEBUG_SIGNALS_WD_SIGNAL                                          31:0
#define JM_DEBUG_SIGNALS_WD_SIGNAL_End                                        31
#define JM_DEBUG_SIGNALS_WD_SIGNAL_Start                                       0
#define JM_DEBUG_SIGNALS_WD_SIGNAL_Type                                      U32




#define jmDebugSignalsDirRegAddrs                                         0x003E
#define JM_DEBUG_SIGNALS_DIR_Address                                     0x000F8
#define JM_DEBUG_SIGNALS_DIR_MSB                                              15
#define JM_DEBUG_SIGNALS_DIR_LSB                                               0
#define JM_DEBUG_SIGNALS_DIR_BLK                                               0
#define JM_DEBUG_SIGNALS_DIR_Count                                             1
#define JM_DEBUG_SIGNALS_DIR_FieldMask                                0xFFFFFFFF
#define JM_DEBUG_SIGNALS_DIR_ReadMask                                 0xFFFFFFFF
#define JM_DEBUG_SIGNALS_DIR_WriteMask                                0x00000000
#define JM_DEBUG_SIGNALS_DIR_ResetValue                               0x00000000


#define JM_DEBUG_SIGNALS_DIR_SIGNAL                                         31:0
#define JM_DEBUG_SIGNALS_DIR_SIGNAL_End                                       31
#define JM_DEBUG_SIGNALS_DIR_SIGNAL_Start                                      0
#define JM_DEBUG_SIGNALS_DIR_SIGNAL_Type                                     U32



#define AQWriteAddrHighRegAddrs                                           0x003F
#define AQ_WRITE_ADDR_HIGH_Address                                       0x000FC
#define AQ_WRITE_ADDR_HIGH_MSB                                                15
#define AQ_WRITE_ADDR_HIGH_LSB                                                 0
#define AQ_WRITE_ADDR_HIGH_BLK                                                 0
#define AQ_WRITE_ADDR_HIGH_Count                                               1
#define AQ_WRITE_ADDR_HIGH_FieldMask                                  0x0000FFFF
#define AQ_WRITE_ADDR_HIGH_ReadMask                                   0x0000FFFF
#define AQ_WRITE_ADDR_HIGH_WriteMask                                  0x0000FFFF
#define AQ_WRITE_ADDR_HIGH_ResetValue                                 0x00000000


#define AQ_WRITE_ADDR_HIGH_ADDRESS                                          15:0
#define AQ_WRITE_ADDR_HIGH_ADDRESS_End                                        15
#define AQ_WRITE_ADDR_HIGH_ADDRESS_Start                                       0
#define AQ_WRITE_ADDR_HIGH_ADDRESS_Type                                      U16




#define AQReadAddrHighRegAddrs                                            0x006D
#define AQ_READ_ADDR_HIGH_Address                                        0x001B4
#define AQ_READ_ADDR_HIGH_MSB                                                 15
#define AQ_READ_ADDR_HIGH_LSB                                                  0
#define AQ_READ_ADDR_HIGH_BLK                                                  0
#define AQ_READ_ADDR_HIGH_Count                                                1
#define AQ_READ_ADDR_HIGH_FieldMask                                   0x0000FFFF
#define AQ_READ_ADDR_HIGH_ReadMask                                    0x0000FFFF
#define AQ_READ_ADDR_HIGH_WriteMask                                   0x0000FFFF
#define AQ_READ_ADDR_HIGH_ResetValue                                  0x00000000


#define AQ_READ_ADDR_HIGH_ADDRESS                                           15:0
#define AQ_READ_ADDR_HIGH_ADDRESS_End                                         15
#define AQ_READ_ADDR_HIGH_ADDRESS_Start                                        0
#define AQ_READ_ADDR_HIGH_ADDRESS_Type                                       U16




#define jmAxiConfigRegAddrs                                               0x0070
#define JM_AXI_CONFIG_Address                                            0x001C0
#define JM_AXI_CONFIG_MSB                                                     15
#define JM_AXI_CONFIG_LSB                                                      4
#define JM_AXI_CONFIG_BLK                                                      4
#define JM_AXI_CONFIG_Count                                                   16
#define JM_AXI_CONFIG_FieldMask                                       0x0FFF0FFF
#define JM_AXI_CONFIG_ReadMask                                        0x0FFF0FFF
#define JM_AXI_CONFIG_WriteMask                                       0x0FFF0FFF
#define JM_AXI_CONFIG_ResetValue                                      0x00000000

#define JM_AXI_CONFIG_LOW_AW_CACHE                                           3:0
#define JM_AXI_CONFIG_LOW_AW_CACHE_End                                         3
#define JM_AXI_CONFIG_LOW_AW_CACHE_Start                                       0
#define JM_AXI_CONFIG_LOW_AW_CACHE_Type                                      U04

#define JM_AXI_CONFIG_LOW_AR_CACHE                                           7:4
#define JM_AXI_CONFIG_LOW_AR_CACHE_End                                         7
#define JM_AXI_CONFIG_LOW_AR_CACHE_Start                                       4
#define JM_AXI_CONFIG_LOW_AR_CACHE_Type                                      U04

#define JM_AXI_CONFIG_LOW_AW_DOMAIN                                          9:8
#define JM_AXI_CONFIG_LOW_AW_DOMAIN_End                                        9
#define JM_AXI_CONFIG_LOW_AW_DOMAIN_Start                                      8
#define JM_AXI_CONFIG_LOW_AW_DOMAIN_Type                                     U02

#define JM_AXI_CONFIG_LOW_AR_DOMAIN                                        11:10
#define JM_AXI_CONFIG_LOW_AR_DOMAIN_End                                       11
#define JM_AXI_CONFIG_LOW_AR_DOMAIN_Start                                     10
#define JM_AXI_CONFIG_LOW_AR_DOMAIN_Type                                     U02

#define JM_AXI_CONFIG_HIGH_AW_CACHE                                        19:16
#define JM_AXI_CONFIG_HIGH_AW_CACHE_End                                       19
#define JM_AXI_CONFIG_HIGH_AW_CACHE_Start                                     16
#define JM_AXI_CONFIG_HIGH_AW_CACHE_Type                                     U04

#define JM_AXI_CONFIG_HIGH_AR_CACHE                                        23:20
#define JM_AXI_CONFIG_HIGH_AR_CACHE_End                                       23
#define JM_AXI_CONFIG_HIGH_AR_CACHE_Start                                     20
#define JM_AXI_CONFIG_HIGH_AR_CACHE_Type                                     U04

#define JM_AXI_CONFIG_HIGH_AW_DOMAIN                                       25:24
#define JM_AXI_CONFIG_HIGH_AW_DOMAIN_End                                      25
#define JM_AXI_CONFIG_HIGH_AW_DOMAIN_Start                                    24
#define JM_AXI_CONFIG_HIGH_AW_DOMAIN_Type                                    U02

#define JM_AXI_CONFIG_HIGH_AR_DOMAIN                                       27:26
#define JM_AXI_CONFIG_HIGH_AR_DOMAIN_End                                      27
#define JM_AXI_CONFIG_HIGH_AR_DOMAIN_Start                                    26
#define JM_AXI_CONFIG_HIGH_AR_DOMAIN_Type                                    U02




#define jmTotalReadsOCBRegAddrs                                           0x5F80
#define JM_TOTAL_READS_OCB_Address                                       0x17E00
#define JM_TOTAL_READS_OCB_MSB                                                15
#define JM_TOTAL_READS_OCB_LSB                                                 0
#define JM_TOTAL_READS_OCB_BLK                                                 0
#define JM_TOTAL_READS_OCB_Count                                               1
#define JM_TOTAL_READS_OCB_FieldMask                                  0xFFFFFFFF
#define JM_TOTAL_READS_OCB_ReadMask                                   0xFFFFFFFF
#define JM_TOTAL_READS_OCB_WriteMask                                  0x00000000
#define JM_TOTAL_READS_OCB_ResetValue                                 0x00000000

#define JM_TOTAL_READS_OCB_COUNT                                            31:0
#define JM_TOTAL_READS_OCB_COUNT_End                                          31
#define JM_TOTAL_READS_OCB_COUNT_Start                                         0
#define JM_TOTAL_READS_OCB_COUNT_Type                                        U32



#define jmTotalReadBurstsOCBRegAddrs                                      0x5F81
#define JM_TOTAL_READ_BURSTS_OCB_Address                                 0x17E04
#define JM_TOTAL_READ_BURSTS_OCB_MSB                                          15
#define JM_TOTAL_READ_BURSTS_OCB_LSB                                           0
#define JM_TOTAL_READ_BURSTS_OCB_BLK                                           0
#define JM_TOTAL_READ_BURSTS_OCB_Count                                         1
#define JM_TOTAL_READ_BURSTS_OCB_FieldMask                            0xFFFFFFFF
#define JM_TOTAL_READ_BURSTS_OCB_ReadMask                             0xFFFFFFFF
#define JM_TOTAL_READ_BURSTS_OCB_WriteMask                            0x00000000
#define JM_TOTAL_READ_BURSTS_OCB_ResetValue                           0x00000000

#define JM_TOTAL_READ_BURSTS_OCB_COUNT                                      31:0
#define JM_TOTAL_READ_BURSTS_OCB_COUNT_End                                    31
#define JM_TOTAL_READ_BURSTS_OCB_COUNT_Start                                   0
#define JM_TOTAL_READ_BURSTS_OCB_COUNT_Type                                  U32



#define jmTotalReadReqsOCBRegAddrs                                        0x5F82
#define JM_TOTAL_READ_REQS_OCB_Address                                   0x17E08
#define JM_TOTAL_READ_REQS_OCB_MSB                                            15
#define JM_TOTAL_READ_REQS_OCB_LSB                                             0
#define JM_TOTAL_READ_REQS_OCB_BLK                                             0
#define JM_TOTAL_READ_REQS_OCB_Count                                           1
#define JM_TOTAL_READ_REQS_OCB_FieldMask                              0xFFFFFFFF
#define JM_TOTAL_READ_REQS_OCB_ReadMask                               0xFFFFFFFF
#define JM_TOTAL_READ_REQS_OCB_WriteMask                              0x00000000
#define JM_TOTAL_READ_REQS_OCB_ResetValue                             0x00000000

#define JM_TOTAL_READ_REQS_OCB_COUNT                                        31:0
#define JM_TOTAL_READ_REQS_OCB_COUNT_End                                      31
#define JM_TOTAL_READ_REQS_OCB_COUNT_Start                                     0
#define JM_TOTAL_READ_REQS_OCB_COUNT_Type                                    U32



#define jmTotalReadLastsOCBRegAddrs                                       0x5F83
#define JM_TOTAL_READ_LASTS_OCB_Address                                  0x17E0C
#define JM_TOTAL_READ_LASTS_OCB_MSB                                           15
#define JM_TOTAL_READ_LASTS_OCB_LSB                                            0
#define JM_TOTAL_READ_LASTS_OCB_BLK                                            0
#define JM_TOTAL_READ_LASTS_OCB_Count                                          1
#define JM_TOTAL_READ_LASTS_OCB_FieldMask                             0xFFFFFFFF
#define JM_TOTAL_READ_LASTS_OCB_ReadMask                              0xFFFFFFFF
#define JM_TOTAL_READ_LASTS_OCB_WriteMask                             0x00000000
#define JM_TOTAL_READ_LASTS_OCB_ResetValue                            0x00000000

#define JM_TOTAL_READ_LASTS_OCB_COUNT                                       31:0
#define JM_TOTAL_READ_LASTS_OCB_COUNT_End                                     31
#define JM_TOTAL_READ_LASTS_OCB_COUNT_Start                                    0
#define JM_TOTAL_READ_LASTS_OCB_COUNT_Type                                   U32



#define jmTotalWritesOCBRegAddrs                                          0x5F84
#define JM_TOTAL_WRITES_OCB_Address                                      0x17E10
#define JM_TOTAL_WRITES_OCB_MSB                                               15
#define JM_TOTAL_WRITES_OCB_LSB                                                0
#define JM_TOTAL_WRITES_OCB_BLK                                                0
#define JM_TOTAL_WRITES_OCB_Count                                              1
#define JM_TOTAL_WRITES_OCB_FieldMask                                 0xFFFFFFFF
#define JM_TOTAL_WRITES_OCB_ReadMask                                  0xFFFFFFFF
#define JM_TOTAL_WRITES_OCB_WriteMask                                 0x00000000
#define JM_TOTAL_WRITES_OCB_ResetValue                                0x00000000

#define JM_TOTAL_WRITES_OCB_COUNT                                           31:0
#define JM_TOTAL_WRITES_OCB_COUNT_End                                         31
#define JM_TOTAL_WRITES_OCB_COUNT_Start                                        0
#define JM_TOTAL_WRITES_OCB_COUNT_Type                                       U32



#define jmTotalWriteBurstsOCBRegAddrs                                     0x5F85
#define JM_TOTAL_WRITE_BURSTS_OCB_Address                                0x17E14
#define JM_TOTAL_WRITE_BURSTS_OCB_MSB                                         15
#define JM_TOTAL_WRITE_BURSTS_OCB_LSB                                          0
#define JM_TOTAL_WRITE_BURSTS_OCB_BLK                                          0
#define JM_TOTAL_WRITE_BURSTS_OCB_Count                                        1
#define JM_TOTAL_WRITE_BURSTS_OCB_FieldMask                           0xFFFFFFFF
#define JM_TOTAL_WRITE_BURSTS_OCB_ReadMask                            0xFFFFFFFF
#define JM_TOTAL_WRITE_BURSTS_OCB_WriteMask                           0x00000000
#define JM_TOTAL_WRITE_BURSTS_OCB_ResetValue                          0x00000000

#define JM_TOTAL_WRITE_BURSTS_OCB_COUNT                                     31:0
#define JM_TOTAL_WRITE_BURSTS_OCB_COUNT_End                                   31
#define JM_TOTAL_WRITE_BURSTS_OCB_COUNT_Start                                  0
#define JM_TOTAL_WRITE_BURSTS_OCB_COUNT_Type                                 U32



#define jmTotalWriteReqsOCBRegAddrs                                       0x5F86
#define JM_TOTAL_WRITE_REQS_OCB_Address                                  0x17E18
#define JM_TOTAL_WRITE_REQS_OCB_MSB                                           15
#define JM_TOTAL_WRITE_REQS_OCB_LSB                                            0
#define JM_TOTAL_WRITE_REQS_OCB_BLK                                            0
#define JM_TOTAL_WRITE_REQS_OCB_Count                                          1
#define JM_TOTAL_WRITE_REQS_OCB_FieldMask                             0xFFFFFFFF
#define JM_TOTAL_WRITE_REQS_OCB_ReadMask                              0xFFFFFFFF
#define JM_TOTAL_WRITE_REQS_OCB_WriteMask                             0x00000000
#define JM_TOTAL_WRITE_REQS_OCB_ResetValue                            0x00000000

#define JM_TOTAL_WRITE_REQS_OCB_COUNT                                       31:0
#define JM_TOTAL_WRITE_REQS_OCB_COUNT_End                                     31
#define JM_TOTAL_WRITE_REQS_OCB_COUNT_Start                                    0
#define JM_TOTAL_WRITE_REQS_OCB_COUNT_Type                                   U32



#define jmTotalWriteLastsOCBRegAddrs                                      0x5F87
#define JM_TOTAL_WRITE_LASTS_OCB_Address                                 0x17E1C
#define JM_TOTAL_WRITE_LASTS_OCB_MSB                                          15
#define JM_TOTAL_WRITE_LASTS_OCB_LSB                                           0
#define JM_TOTAL_WRITE_LASTS_OCB_BLK                                           0
#define JM_TOTAL_WRITE_LASTS_OCB_Count                                         1
#define JM_TOTAL_WRITE_LASTS_OCB_FieldMask                            0xFFFFFFFF
#define JM_TOTAL_WRITE_LASTS_OCB_ReadMask                             0xFFFFFFFF
#define JM_TOTAL_WRITE_LASTS_OCB_WriteMask                            0x00000000
#define JM_TOTAL_WRITE_LASTS_OCB_ResetValue                           0x00000000

#define JM_TOTAL_WRITE_LASTS_OCB_COUNT                                      31:0
#define JM_TOTAL_WRITE_LASTS_OCB_COUNT_End                                    31
#define JM_TOTAL_WRITE_LASTS_OCB_COUNT_Start                                   0
#define JM_TOTAL_WRITE_LASTS_OCB_COUNT_Type                                  U32





#define AQSecurityNSAIDRegAddrs                                           0x00A0
#define AQ_SECURITY_NSAID_Address                                        0x00280
#define AQ_SECURITY_NSAID_MSB                                                 15
#define AQ_SECURITY_NSAID_LSB                                                  0
#define AQ_SECURITY_NSAID_BLK                                                  0
#define AQ_SECURITY_NSAID_Count                                                1
#define AQ_SECURITY_NSAID_FieldMask                                   0x00000FFF
#define AQ_SECURITY_NSAID_ReadMask                                    0x00000FFF
#define AQ_SECURITY_NSAID_WriteMask                                   0x00000FFF
#define AQ_SECURITY_NSAID_ResetValue                                  0x00000000


#define AQ_SECURITY_NSAID_FE                                                 3:0
#define AQ_SECURITY_NSAID_FE_End                                               3
#define AQ_SECURITY_NSAID_FE_Start                                             0
#define AQ_SECURITY_NSAID_FE_Type                                            U04


#define AQ_SECURITY_NSAID_TS                                                 7:4
#define AQ_SECURITY_NSAID_TS_End                                               7
#define AQ_SECURITY_NSAID_TS_Start                                             4
#define AQ_SECURITY_NSAID_TS_Type                                            U04


#define AQ_SECURITY_NSAID_OTHER                                             11:8
#define AQ_SECURITY_NSAID_OTHER_End                                           11
#define AQ_SECURITY_NSAID_OTHER_Start                                          8
#define AQ_SECURITY_NSAID_OTHER_Type                                         U04




#define AQNoSecurityNSAIDRegAddrs                                         0x00A1
#define AQ_NO_SECURITY_NSAID_Address                                     0x00284
#define AQ_NO_SECURITY_NSAID_MSB                                              15
#define AQ_NO_SECURITY_NSAID_LSB                                               0
#define AQ_NO_SECURITY_NSAID_BLK                                               0
#define AQ_NO_SECURITY_NSAID_Count                                             1
#define AQ_NO_SECURITY_NSAID_FieldMask                                0x00000FFF
#define AQ_NO_SECURITY_NSAID_ReadMask                                 0x00000FFF
#define AQ_NO_SECURITY_NSAID_WriteMask                                0x00000FFF
#define AQ_NO_SECURITY_NSAID_ResetValue                               0x00000000


#define AQ_NO_SECURITY_NSAID_FE                                              3:0
#define AQ_NO_SECURITY_NSAID_FE_End                                            3
#define AQ_NO_SECURITY_NSAID_FE_Start                                          0
#define AQ_NO_SECURITY_NSAID_FE_Type                                         U04


#define AQ_NO_SECURITY_NSAID_TS                                              7:4
#define AQ_NO_SECURITY_NSAID_TS_End                                            7
#define AQ_NO_SECURITY_NSAID_TS_Start                                          4
#define AQ_NO_SECURITY_NSAID_TS_Type                                         U04


#define AQ_NO_SECURITY_NSAID_OTHER                                          11:8
#define AQ_NO_SECURITY_NSAID_OTHER_End                                        11
#define AQ_NO_SECURITY_NSAID_OTHER_Start                                       8
#define AQ_NO_SECURITY_NSAID_OTHER_Type                                      U04




#define jmFrameTotalBusyCntRegAddrs                                       0x00A2
#define JM_FRAME_TOTAL_BUSY_CNT_Address                                  0x00288
#define JM_FRAME_TOTAL_BUSY_CNT_MSB                                           15
#define JM_FRAME_TOTAL_BUSY_CNT_LSB                                            0
#define JM_FRAME_TOTAL_BUSY_CNT_BLK                                            0
#define JM_FRAME_TOTAL_BUSY_CNT_Count                                          1
#define JM_FRAME_TOTAL_BUSY_CNT_FieldMask                             0xFFFFFFFF
#define JM_FRAME_TOTAL_BUSY_CNT_ReadMask                              0xFFFFFFFF
#define JM_FRAME_TOTAL_BUSY_CNT_WriteMask                             0xFFFFFFFF
#define JM_FRAME_TOTAL_BUSY_CNT_ResetValue                            0x00000000

#define JM_FRAME_TOTAL_BUSY_CNT_VALUE                                       31:0
#define JM_FRAME_TOTAL_BUSY_CNT_VALUE_End                                     31
#define JM_FRAME_TOTAL_BUSY_CNT_VALUE_Start                                    0
#define JM_FRAME_TOTAL_BUSY_CNT_VALUE_Type                                   U32




#define jmFrameBackpressReadCntRegAddrs                                   0x00A3
#define JM_FRAME_BACKPRESS_READ_CNT_Address                              0x0028C
#define JM_FRAME_BACKPRESS_READ_CNT_MSB                                       15
#define JM_FRAME_BACKPRESS_READ_CNT_LSB                                        0
#define JM_FRAME_BACKPRESS_READ_CNT_BLK                                        0
#define JM_FRAME_BACKPRESS_READ_CNT_Count                                      1
#define JM_FRAME_BACKPRESS_READ_CNT_FieldMask                         0xFFFFFFFF
#define JM_FRAME_BACKPRESS_READ_CNT_ReadMask                          0xFFFFFFFF
#define JM_FRAME_BACKPRESS_READ_CNT_WriteMask                         0xFFFFFFFF
#define JM_FRAME_BACKPRESS_READ_CNT_ResetValue                        0x00000000

#define JM_FRAME_BACKPRESS_READ_CNT_VALUE                                   31:0
#define JM_FRAME_BACKPRESS_READ_CNT_VALUE_End                                 31
#define JM_FRAME_BACKPRESS_READ_CNT_VALUE_Start                                0
#define JM_FRAME_BACKPRESS_READ_CNT_VALUE_Type                               U32




#define jmFrameBackpressWriteCntRegAddrs                                  0x00A4
#define JM_FRAME_BACKPRESS_WRITE_CNT_Address                             0x00290
#define JM_FRAME_BACKPRESS_WRITE_CNT_MSB                                      15
#define JM_FRAME_BACKPRESS_WRITE_CNT_LSB                                       0
#define JM_FRAME_BACKPRESS_WRITE_CNT_BLK                                       0
#define JM_FRAME_BACKPRESS_WRITE_CNT_Count                                     1
#define JM_FRAME_BACKPRESS_WRITE_CNT_FieldMask                        0xFFFFFFFF
#define JM_FRAME_BACKPRESS_WRITE_CNT_ReadMask                         0xFFFFFFFF
#define JM_FRAME_BACKPRESS_WRITE_CNT_WriteMask                        0xFFFFFFFF
#define JM_FRAME_BACKPRESS_WRITE_CNT_ResetValue                       0x00000000

#define JM_FRAME_BACKPRESS_WRITE_CNT_VALUE                                  31:0
#define JM_FRAME_BACKPRESS_WRITE_CNT_VALUE_End                                31
#define JM_FRAME_BACKPRESS_WRITE_CNT_VALUE_Start                               0
#define JM_FRAME_BACKPRESS_WRITE_CNT_VALUE_Type                              U32




#define jmFrameBackpressWriteDataCntRegAddrs                              0x00A5
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_Address                        0x00294
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_MSB                                 15
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_LSB                                  0
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_BLK                                  0
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_Count                                1
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_FieldMask                   0xFFFFFFFF
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_ReadMask                    0xFFFFFFFF
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_WriteMask                   0xFFFFFFFF
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_ResetValue                  0x00000000

#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_VALUE                             31:0
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_VALUE_End                           31
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_VALUE_Start                          0
#define JM_FRAME_BACKPRESS_WRITE_DATA_CNT_VALUE_Type                         U32




#define jmFrameTotalLatencyCntRegAddrs                                    0x00A6
#define JM_FRAME_TOTAL_LATENCY_CNT_Address                               0x00298
#define JM_FRAME_TOTAL_LATENCY_CNT_MSB                                        15
#define JM_FRAME_TOTAL_LATENCY_CNT_LSB                                         0
#define JM_FRAME_TOTAL_LATENCY_CNT_BLK                                         0
#define JM_FRAME_TOTAL_LATENCY_CNT_Count                                       1
#define JM_FRAME_TOTAL_LATENCY_CNT_FieldMask                          0xFFFFFFFF
#define JM_FRAME_TOTAL_LATENCY_CNT_ReadMask                           0xFFFFFFFF
#define JM_FRAME_TOTAL_LATENCY_CNT_WriteMask                          0xFFFFFFFF
#define JM_FRAME_TOTAL_LATENCY_CNT_ResetValue                         0x00000000

#define JM_FRAME_TOTAL_LATENCY_CNT_VALUE                                    31:0
#define JM_FRAME_TOTAL_LATENCY_CNT_VALUE_End                                  31
#define JM_FRAME_TOTAL_LATENCY_CNT_VALUE_Start                                 0
#define JM_FRAME_TOTAL_LATENCY_CNT_VALUE_Type                                U32




#define jmFrameTotalRdReqCntRegAddrs                                      0x00A7
#define JM_FRAME_TOTAL_RD_REQ_CNT_Address                                0x0029C
#define JM_FRAME_TOTAL_RD_REQ_CNT_MSB                                         15
#define JM_FRAME_TOTAL_RD_REQ_CNT_LSB                                          0
#define JM_FRAME_TOTAL_RD_REQ_CNT_BLK                                          0
#define JM_FRAME_TOTAL_RD_REQ_CNT_Count                                        1
#define JM_FRAME_TOTAL_RD_REQ_CNT_FieldMask                           0xFFFFFFFF
#define JM_FRAME_TOTAL_RD_REQ_CNT_ReadMask                            0xFFFFFFFF
#define JM_FRAME_TOTAL_RD_REQ_CNT_WriteMask                           0xFFFFFFFF
#define JM_FRAME_TOTAL_RD_REQ_CNT_ResetValue                          0x00000000

#define JM_FRAME_TOTAL_RD_REQ_CNT_VALUE                                     31:0
#define JM_FRAME_TOTAL_RD_REQ_CNT_VALUE_End                                   31
#define JM_FRAME_TOTAL_RD_REQ_CNT_VALUE_Start                                  0
#define JM_FRAME_TOTAL_RD_REQ_CNT_VALUE_Type                                 U32




#define jmLatencyMap0CntRegAddrs                                          0x00A8
#define JM_LATENCY_MAP0_CNT_Address                                      0x002A0
#define JM_LATENCY_MAP0_CNT_MSB                                               15
#define JM_LATENCY_MAP0_CNT_LSB                                                0
#define JM_LATENCY_MAP0_CNT_BLK                                                0
#define JM_LATENCY_MAP0_CNT_Count                                              1
#define JM_LATENCY_MAP0_CNT_FieldMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP0_CNT_ReadMask                                  0xFFFFFFFF
#define JM_LATENCY_MAP0_CNT_WriteMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP0_CNT_ResetValue                                0x00000000

#define JM_LATENCY_MAP0_CNT_VALUE                                           31:0
#define JM_LATENCY_MAP0_CNT_VALUE_End                                         31
#define JM_LATENCY_MAP0_CNT_VALUE_Start                                        0
#define JM_LATENCY_MAP0_CNT_VALUE_Type                                       U32




#define jmLatencyMap1CntRegAddrs                                          0x00A9
#define JM_LATENCY_MAP1_CNT_Address                                      0x002A4
#define JM_LATENCY_MAP1_CNT_MSB                                               15
#define JM_LATENCY_MAP1_CNT_LSB                                                0
#define JM_LATENCY_MAP1_CNT_BLK                                                0
#define JM_LATENCY_MAP1_CNT_Count                                              1
#define JM_LATENCY_MAP1_CNT_FieldMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP1_CNT_ReadMask                                  0xFFFFFFFF
#define JM_LATENCY_MAP1_CNT_WriteMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP1_CNT_ResetValue                                0x00000000

#define JM_LATENCY_MAP1_CNT_VALUE                                           31:0
#define JM_LATENCY_MAP1_CNT_VALUE_End                                         31
#define JM_LATENCY_MAP1_CNT_VALUE_Start                                        0
#define JM_LATENCY_MAP1_CNT_VALUE_Type                                       U32




#define jmLatencyMap2CntRegAddrs                                          0x00AA
#define JM_LATENCY_MAP2_CNT_Address                                      0x002A8
#define JM_LATENCY_MAP2_CNT_MSB                                               15
#define JM_LATENCY_MAP2_CNT_LSB                                                0
#define JM_LATENCY_MAP2_CNT_BLK                                                0
#define JM_LATENCY_MAP2_CNT_Count                                              1
#define JM_LATENCY_MAP2_CNT_FieldMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP2_CNT_ReadMask                                  0xFFFFFFFF
#define JM_LATENCY_MAP2_CNT_WriteMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP2_CNT_ResetValue                                0x00000000

#define JM_LATENCY_MAP2_CNT_VALUE                                           31:0
#define JM_LATENCY_MAP2_CNT_VALUE_End                                         31
#define JM_LATENCY_MAP2_CNT_VALUE_Start                                        0
#define JM_LATENCY_MAP2_CNT_VALUE_Type                                       U32




#define jmLatencyMap3CntRegAddrs                                          0x00AB
#define JM_LATENCY_MAP3_CNT_Address                                      0x002AC
#define JM_LATENCY_MAP3_CNT_MSB                                               15
#define JM_LATENCY_MAP3_CNT_LSB                                                0
#define JM_LATENCY_MAP3_CNT_BLK                                                0
#define JM_LATENCY_MAP3_CNT_Count                                              1
#define JM_LATENCY_MAP3_CNT_FieldMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP3_CNT_ReadMask                                  0xFFFFFFFF
#define JM_LATENCY_MAP3_CNT_WriteMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP3_CNT_ResetValue                                0x00000000

#define JM_LATENCY_MAP3_CNT_VALUE                                           31:0
#define JM_LATENCY_MAP3_CNT_VALUE_End                                         31
#define JM_LATENCY_MAP3_CNT_VALUE_Start                                        0
#define JM_LATENCY_MAP3_CNT_VALUE_Type                                       U32




#define jmLatencyMap4CntRegAddrs                                          0x00AC
#define JM_LATENCY_MAP4_CNT_Address                                      0x002B0
#define JM_LATENCY_MAP4_CNT_MSB                                               15
#define JM_LATENCY_MAP4_CNT_LSB                                                0
#define JM_LATENCY_MAP4_CNT_BLK                                                0
#define JM_LATENCY_MAP4_CNT_Count                                              1
#define JM_LATENCY_MAP4_CNT_FieldMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP4_CNT_ReadMask                                  0xFFFFFFFF
#define JM_LATENCY_MAP4_CNT_WriteMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP4_CNT_ResetValue                                0x00000000

#define JM_LATENCY_MAP4_CNT_VALUE                                           31:0
#define JM_LATENCY_MAP4_CNT_VALUE_End                                         31
#define JM_LATENCY_MAP4_CNT_VALUE_Start                                        0
#define JM_LATENCY_MAP4_CNT_VALUE_Type                                       U32




#define jmLatencyMap5CntRegAddrs                                          0x00AD
#define JM_LATENCY_MAP5_CNT_Address                                      0x002B4
#define JM_LATENCY_MAP5_CNT_MSB                                               15
#define JM_LATENCY_MAP5_CNT_LSB                                                0
#define JM_LATENCY_MAP5_CNT_BLK                                                0
#define JM_LATENCY_MAP5_CNT_Count                                              1
#define JM_LATENCY_MAP5_CNT_FieldMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP5_CNT_ReadMask                                  0xFFFFFFFF
#define JM_LATENCY_MAP5_CNT_WriteMask                                 0xFFFFFFFF
#define JM_LATENCY_MAP5_CNT_ResetValue                                0x00000000

#define JM_LATENCY_MAP5_CNT_VALUE                                           31:0
#define JM_LATENCY_MAP5_CNT_VALUE_End                                         31
#define JM_LATENCY_MAP5_CNT_VALUE_Start                                        0
#define JM_LATENCY_MAP5_CNT_VALUE_Type                                       U32





#define jmAHBTotalReadsOCBRegAddrs                                        0x0170
#define JM_AHB_TOTAL_READS_OCB_Address                                   0x005C0
#define JM_AHB_TOTAL_READS_OCB_MSB                                            15
#define JM_AHB_TOTAL_READS_OCB_LSB                                             0
#define JM_AHB_TOTAL_READS_OCB_BLK                                             0
#define JM_AHB_TOTAL_READS_OCB_Count                                           1
#define JM_AHB_TOTAL_READS_OCB_FieldMask                              0xFFFFFFFF
#define JM_AHB_TOTAL_READS_OCB_ReadMask                               0xFFFFFFFF
#define JM_AHB_TOTAL_READS_OCB_WriteMask                              0x00000000
#define JM_AHB_TOTAL_READS_OCB_ResetValue                             0x00000000

#define JM_AHB_TOTAL_READS_OCB_COUNT                                        31:0
#define JM_AHB_TOTAL_READS_OCB_COUNT_End                                      31
#define JM_AHB_TOTAL_READS_OCB_COUNT_Start                                     0
#define JM_AHB_TOTAL_READS_OCB_COUNT_Type                                    U32



#define jmAHBTotalReadBurstsOCBRegAddrs                                   0x0171
#define JM_AHB_TOTAL_READ_BURSTS_OCB_Address                             0x005C4
#define JM_AHB_TOTAL_READ_BURSTS_OCB_MSB                                      15
#define JM_AHB_TOTAL_READ_BURSTS_OCB_LSB                                       0
#define JM_AHB_TOTAL_READ_BURSTS_OCB_BLK                                       0
#define JM_AHB_TOTAL_READ_BURSTS_OCB_Count                                     1
#define JM_AHB_TOTAL_READ_BURSTS_OCB_FieldMask                        0xFFFFFFFF
#define JM_AHB_TOTAL_READ_BURSTS_OCB_ReadMask                         0xFFFFFFFF
#define JM_AHB_TOTAL_READ_BURSTS_OCB_WriteMask                        0x00000000
#define JM_AHB_TOTAL_READ_BURSTS_OCB_ResetValue                       0x00000000

#define JM_AHB_TOTAL_READ_BURSTS_OCB_COUNT                                  31:0
#define JM_AHB_TOTAL_READ_BURSTS_OCB_COUNT_End                                31
#define JM_AHB_TOTAL_READ_BURSTS_OCB_COUNT_Start                               0
#define JM_AHB_TOTAL_READ_BURSTS_OCB_COUNT_Type                              U32



#define jmAHBTotalReadReqsOCBRegAddrs                                     0x0172
#define JM_AHB_TOTAL_READ_REQS_OCB_Address                               0x005C8
#define JM_AHB_TOTAL_READ_REQS_OCB_MSB                                        15
#define JM_AHB_TOTAL_READ_REQS_OCB_LSB                                         0
#define JM_AHB_TOTAL_READ_REQS_OCB_BLK                                         0
#define JM_AHB_TOTAL_READ_REQS_OCB_Count                                       1
#define JM_AHB_TOTAL_READ_REQS_OCB_FieldMask                          0xFFFFFFFF
#define JM_AHB_TOTAL_READ_REQS_OCB_ReadMask                           0xFFFFFFFF
#define JM_AHB_TOTAL_READ_REQS_OCB_WriteMask                          0x00000000
#define JM_AHB_TOTAL_READ_REQS_OCB_ResetValue                         0x00000000

#define JM_AHB_TOTAL_READ_REQS_OCB_COUNT                                    31:0
#define JM_AHB_TOTAL_READ_REQS_OCB_COUNT_End                                  31
#define JM_AHB_TOTAL_READ_REQS_OCB_COUNT_Start                                 0
#define JM_AHB_TOTAL_READ_REQS_OCB_COUNT_Type                                U32



#define jmAHBTotalReadLastsOCBRegAddrs                                    0x0173
#define JM_AHB_TOTAL_READ_LASTS_OCB_Address                              0x005CC
#define JM_AHB_TOTAL_READ_LASTS_OCB_MSB                                       15
#define JM_AHB_TOTAL_READ_LASTS_OCB_LSB                                        0
#define JM_AHB_TOTAL_READ_LASTS_OCB_BLK                                        0
#define JM_AHB_TOTAL_READ_LASTS_OCB_Count                                      1
#define JM_AHB_TOTAL_READ_LASTS_OCB_FieldMask                         0xFFFFFFFF
#define JM_AHB_TOTAL_READ_LASTS_OCB_ReadMask                          0xFFFFFFFF
#define JM_AHB_TOTAL_READ_LASTS_OCB_WriteMask                         0x00000000
#define JM_AHB_TOTAL_READ_LASTS_OCB_ResetValue                        0x00000000

#define JM_AHB_TOTAL_READ_LASTS_OCB_COUNT                                   31:0
#define JM_AHB_TOTAL_READ_LASTS_OCB_COUNT_End                                 31
#define JM_AHB_TOTAL_READ_LASTS_OCB_COUNT_Start                                0
#define JM_AHB_TOTAL_READ_LASTS_OCB_COUNT_Type                               U32




#define jmAHBTotalWritesOCBRegAddrs                                       0x0174
#define JM_AHB_TOTAL_WRITES_OCB_Address                                  0x005D0
#define JM_AHB_TOTAL_WRITES_OCB_MSB                                           15
#define JM_AHB_TOTAL_WRITES_OCB_LSB                                            0
#define JM_AHB_TOTAL_WRITES_OCB_BLK                                            0
#define JM_AHB_TOTAL_WRITES_OCB_Count                                          1
#define JM_AHB_TOTAL_WRITES_OCB_FieldMask                             0xFFFFFFFF
#define JM_AHB_TOTAL_WRITES_OCB_ReadMask                              0xFFFFFFFF
#define JM_AHB_TOTAL_WRITES_OCB_WriteMask                             0x00000000
#define JM_AHB_TOTAL_WRITES_OCB_ResetValue                            0x00000000

#define JM_AHB_TOTAL_WRITES_OCB_COUNT                                       31:0
#define JM_AHB_TOTAL_WRITES_OCB_COUNT_End                                     31
#define JM_AHB_TOTAL_WRITES_OCB_COUNT_Start                                    0
#define JM_AHB_TOTAL_WRITES_OCB_COUNT_Type                                   U32



#define jmAHBTotalWriteBurstsOCBRegAddrs                                  0x0175
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_Address                            0x005D4
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_MSB                                     15
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_LSB                                      0
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_BLK                                      0
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_Count                                    1
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_FieldMask                       0xFFFFFFFF
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_ReadMask                        0xFFFFFFFF
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_WriteMask                       0x00000000
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_ResetValue                      0x00000000

#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_COUNT                                 31:0
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_COUNT_End                               31
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_COUNT_Start                              0
#define JM_AHB_TOTAL_WRITE_BURSTS_OCB_COUNT_Type                             U32



#define jmAHBTotalWriteReqsOCBRegAddrs                                    0x0176
#define JM_AHB_TOTAL_WRITE_REQS_OCB_Address                              0x005D8
#define JM_AHB_TOTAL_WRITE_REQS_OCB_MSB                                       15
#define JM_AHB_TOTAL_WRITE_REQS_OCB_LSB                                        0
#define JM_AHB_TOTAL_WRITE_REQS_OCB_BLK                                        0
#define JM_AHB_TOTAL_WRITE_REQS_OCB_Count                                      1
#define JM_AHB_TOTAL_WRITE_REQS_OCB_FieldMask                         0xFFFFFFFF
#define JM_AHB_TOTAL_WRITE_REQS_OCB_ReadMask                          0xFFFFFFFF
#define JM_AHB_TOTAL_WRITE_REQS_OCB_WriteMask                         0x00000000
#define JM_AHB_TOTAL_WRITE_REQS_OCB_ResetValue                        0x00000000

#define JM_AHB_TOTAL_WRITE_REQS_OCB_COUNT                                   31:0
#define JM_AHB_TOTAL_WRITE_REQS_OCB_COUNT_End                                 31
#define JM_AHB_TOTAL_WRITE_REQS_OCB_COUNT_Start                                0
#define JM_AHB_TOTAL_WRITE_REQS_OCB_COUNT_Type                               U32



#define jmAHBTotalWriteLastsOCBRegAddrs                                   0x0177
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_Address                             0x005DC
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_MSB                                      15
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_LSB                                       0
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_BLK                                       0
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_Count                                     1
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_FieldMask                        0xFFFFFFFF
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_ReadMask                         0xFFFFFFFF
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_WriteMask                        0x00000000
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_ResetValue                       0x00000000

#define JM_AHB_TOTAL_WRITE_LASTS_OCB_COUNT                                  31:0
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_COUNT_End                                31
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_COUNT_Start                               0
#define JM_AHB_TOTAL_WRITE_LASTS_OCB_COUNT_Type                              U32




#define jmAHBTotalNNIdleCycleCore0RegAddrs                                0x0178
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_Address                         0x005E0
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_MSB                                  15
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_LSB                                   0
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_BLK                                   0
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_Count                                 1
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_FieldMask                    0xFFFFFFFF
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_ReadMask                     0xFFFFFFFF
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_WriteMask                    0x00000000
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_ResetValue                   0x00000000

#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_COUNT                              31:0
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_COUNT_End                            31
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_COUNT_Start                           0
#define JM_AHB_TOTAL_NN_IDLE_CYCLE_CORE0_COUNT_Type                          U32




#define AQQchannelPowerStatusRegAddrs                                     0x0179
#define AQ_QCHANNEL_POWER_STATUS_Address                                 0x005E4
#define AQ_QCHANNEL_POWER_STATUS_MSB                                          15
#define AQ_QCHANNEL_POWER_STATUS_LSB                                           0
#define AQ_QCHANNEL_POWER_STATUS_BLK                                           0
#define AQ_QCHANNEL_POWER_STATUS_Count                                         1
#define AQ_QCHANNEL_POWER_STATUS_FieldMask                            0x00000003
#define AQ_QCHANNEL_POWER_STATUS_ReadMask                             0x00000003
#define AQ_QCHANNEL_POWER_STATUS_WriteMask                            0x00000000
#define AQ_QCHANNEL_POWER_STATUS_ResetValue                           0x00000000


#define AQ_QCHANNEL_POWER_STATUS_POWER_STATUS                                0:0
#define AQ_QCHANNEL_POWER_STATUS_POWER_STATUS_End                              0
#define AQ_QCHANNEL_POWER_STATUS_POWER_STATUS_Start                            0
#define AQ_QCHANNEL_POWER_STATUS_POWER_STATUS_Type                           U01
#define   AQ_QCHANNEL_POWER_STATUS_POWER_STATUS_POWER_OFF                    0x0
#define   AQ_QCHANNEL_POWER_STATUS_POWER_STATUS_POWER_ON                     0x1


#define AQ_QCHANNEL_POWER_STATUS_IDLE                                        1:1
#define AQ_QCHANNEL_POWER_STATUS_IDLE_End                                      1
#define AQ_QCHANNEL_POWER_STATUS_IDLE_Start                                    1
#define AQ_QCHANNEL_POWER_STATUS_IDLE_Type                                   U01




#define AQQchannelPowerControlRegAddrs                                    0x017A
#define AQ_QCHANNEL_POWER_CONTROL_Address                                0x005E8
#define AQ_QCHANNEL_POWER_CONTROL_MSB                                         15
#define AQ_QCHANNEL_POWER_CONTROL_LSB                                          0
#define AQ_QCHANNEL_POWER_CONTROL_BLK                                          0
#define AQ_QCHANNEL_POWER_CONTROL_Count                                        1
#define AQ_QCHANNEL_POWER_CONTROL_FieldMask                           0x00001FFF
#define AQ_QCHANNEL_POWER_CONTROL_ReadMask                            0x00001FFF
#define AQ_QCHANNEL_POWER_CONTROL_WriteMask                           0x00001FFF
#define AQ_QCHANNEL_POWER_CONTROL_ResetValue                          0x00000000


#define AQ_QCHANNEL_POWER_CONTROL_START_UP_QCHANNEL                          0:0
#define AQ_QCHANNEL_POWER_CONTROL_START_UP_QCHANNEL_End                        0
#define AQ_QCHANNEL_POWER_CONTROL_START_UP_QCHANNEL_Start                      0
#define AQ_QCHANNEL_POWER_CONTROL_START_UP_QCHANNEL_Type                     U01


#define AQ_QCHANNEL_POWER_CONTROL_DISABLE_QCHANNEL                           1:1
#define AQ_QCHANNEL_POWER_CONTROL_DISABLE_QCHANNEL_End                         1
#define AQ_QCHANNEL_POWER_CONTROL_DISABLE_QCHANNEL_Start                       1
#define AQ_QCHANNEL_POWER_CONTROL_DISABLE_QCHANNEL_Type                      U01


#define AQ_QCHANNEL_POWER_CONTROL_SOFT_RESET_QCHANNEL                        2:2
#define AQ_QCHANNEL_POWER_CONTROL_SOFT_RESET_QCHANNEL_End                      2
#define AQ_QCHANNEL_POWER_CONTROL_SOFT_RESET_QCHANNEL_Start                    2
#define AQ_QCHANNEL_POWER_CONTROL_SOFT_RESET_QCHANNEL_Type                   U01


#define AQ_QCHANNEL_POWER_CONTROL_POWER_OFF_QCHANNEL                         3:3
#define AQ_QCHANNEL_POWER_CONTROL_POWER_OFF_QCHANNEL_End                       3
#define AQ_QCHANNEL_POWER_CONTROL_POWER_OFF_QCHANNEL_Start                     3
#define AQ_QCHANNEL_POWER_CONTROL_POWER_OFF_QCHANNEL_Type                    U01


#define AQ_QCHANNEL_POWER_CONTROL_DEBUG_SELECT_QCHANNEL                     11:4
#define AQ_QCHANNEL_POWER_CONTROL_DEBUG_SELECT_QCHANNEL_End                   11
#define AQ_QCHANNEL_POWER_CONTROL_DEBUG_SELECT_QCHANNEL_Start                  4
#define AQ_QCHANNEL_POWER_CONTROL_DEBUG_SELECT_QCHANNEL_Type                 U08


#define AQ_QCHANNEL_POWER_CONTROL_MASK_DEBUG_SELECT_QCHANNEL               12:12
#define AQ_QCHANNEL_POWER_CONTROL_MASK_DEBUG_SELECT_QCHANNEL_End              12
#define AQ_QCHANNEL_POWER_CONTROL_MASK_DEBUG_SELECT_QCHANNEL_Start            12
#define AQ_QCHANNEL_POWER_CONTROL_MASK_DEBUG_SELECT_QCHANNEL_Type            U01
#define   AQ_QCHANNEL_POWER_CONTROL_MASK_DEBUG_SELECT_QCHANNEL_ENABLED       0x0
#define   AQ_QCHANNEL_POWER_CONTROL_MASK_DEBUG_SELECT_QCHANNEL_MASKED        0x1



#define mwv207regProbeAxiProbeCtrlRegAddrs                                0x017B
#define MWV207REG_PROBE_AXI_PROBE_CTRL_Address                           0x005EC
#define MWV207REG_PROBE_AXI_PROBE_CTRL_MSB                                    15
#define MWV207REG_PROBE_AXI_PROBE_CTRL_LSB                                     0
#define MWV207REG_PROBE_AXI_PROBE_CTRL_BLK                                     0
#define MWV207REG_PROBE_AXI_PROBE_CTRL_Count                                   1
#define MWV207REG_PROBE_AXI_PROBE_CTRL_FieldMask                      0x00001FFF
#define MWV207REG_PROBE_AXI_PROBE_CTRL_ReadMask                       0x00001FFF
#define MWV207REG_PROBE_AXI_PROBE_CTRL_WriteMask                      0x00001FFF
#define MWV207REG_PROBE_AXI_PROBE_CTRL_ResetValue                     0x00000000


#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_ID_SEL_EN                         0:0
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_ID_SEL_EN_End                       0
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_ID_SEL_EN_Start                     0
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_ID_SEL_EN_Type                    U01

#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_ID_SEL_EN_DISABLE               0x0
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_ID_SEL_EN_ENABLE                0x1


#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL                         6:1
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_End                       6
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_Start                     1
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_Type                    U06
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_PE_RD       0x00
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_SC_RD       0x01
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_PE_Z_RD     0x02
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_FE1_RD      0x03
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_SH_RD       0x04
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_FE_RD       0x05
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_RA_RD       0x06
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_MMU_RD      0x07
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_FCZ_RD      0x08
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_BLT_RD      0x09
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_TX_RD       0x0A
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_FCC_RD      0x0B
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_TX1_RD      0x0C
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_HZ_RD       0x0D
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_SH1_RD      0x0E
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_ID_TXFC_RD     0x0F
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_SAMPLER_NOFC_TX 0x18
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_SAMPLER_NOFC_VTX_DATA 0x19
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_SAMPLER_NOFC_SH 0x1A
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_RD_ID_SEL_AQ_MC_SAMPLER_NOFC_ICACHE 0x1B


#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL                        12:7
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_End                      12
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_Start                     7
#define MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_Type                    U06
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_PE_WR       0x01
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_PE_Z_WR     0x03
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_SH_WR       0x04
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_PA_WR       0x05
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_FCZ_WR      0x08
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_BLT_WR      0x09
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_FCC_WR      0x0B
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_HZ_WR       0x0D
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_SH1_WR      0x0E
#define   MWV207REG_PROBE_AXI_PROBE_CTRL_AXI_WR_ID_SEL_AQ_MC_ID_TXFC_WR     0x0F



#define mwv207regProbeAxiProbeModuleEnableRegAddrs                        0x017C
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_Address                  0x005F0
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MSB                           15
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_LSB                            0
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_BLK                            0
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_Count                          1
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FieldMask             0x007FFFFF
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_ReadMask              0x007FFFFF
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_WriteMask             0x00000000
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_ResetValue            0x00000000


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FRONT_END                    0:0
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FRONT_END_End                  0
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FRONT_END_Start                0
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FRONT_END_Type               U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FRONT_END_DISABLED         0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FRONT_END_ENABLED          0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_VERTEX_SHADER                1:1
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_VERTEX_SHADER_End              1
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_VERTEX_SHADER_Start            1
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_VERTEX_SHADER_Type           U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_VERTEX_SHADER_DISABLED     0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_VERTEX_SHADER_ENABLED      0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PRIMITIVE_ASSEMBLY           2:2
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PRIMITIVE_ASSEMBLY_End         2
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PRIMITIVE_ASSEMBLY_Start       2
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PRIMITIVE_ASSEMBLY_Type      U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PRIMITIVE_ASSEMBLY_DISABLED 0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PRIMITIVE_ASSEMBLY_ENABLED 0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_SETUP                        3:3
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_SETUP_End                      3
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_SETUP_Start                    3
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_SETUP_Type                   U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_SETUP_DISABLED             0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_SETUP_ENABLED              0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_RASTERIZER                   4:4
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_RASTERIZER_End                 4
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_RASTERIZER_Start               4
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_RASTERIZER_Type              U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_RASTERIZER_DISABLED        0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_RASTERIZER_ENABLED         0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_SHADER                 5:5
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_SHADER_End               5
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_SHADER_Start             5
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_SHADER_Type            U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_SHADER_DISABLED      0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_SHADER_ENABLED       0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TEXTURE                      6:6
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TEXTURE_End                    6
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TEXTURE_Start                  6
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TEXTURE_Type                 U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TEXTURE_DISABLED           0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TEXTURE_ENABLED            0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_ENGINE                 7:7
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_ENGINE_End               7
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_ENGINE_Start             7
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_ENGINE_Type            U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_ENGINE_DISABLED      0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_PIXEL_ENGINE_ENABLED       0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_COLOR      8:8
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_COLOR_End    8
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_COLOR_Start  8
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_COLOR_Type U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_COLOR_DISABLED 0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_COLOR_ENABLED 0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_DEPTH      9:9
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_DEPTH_End    9
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_DEPTH_Start  9
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_DEPTH_Type U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_DEPTH_DISABLED 0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_MEMORY_CONTROLLER_DEPTH_ENABLED 0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE0            10:10
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE0_End           10
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE0_Start         10
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE0_Type         U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE0_DISABLED   0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE0_ENABLED    0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE1            11:11
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE1_End           11
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE1_Start         11
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE1_Type         U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE1_DISABLED   0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_HOST_INTERFACE1_ENABLED    0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GPUL2_CACHE                12:12
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GPUL2_CACHE_End               12
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GPUL2_CACHE_Start             12
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GPUL2_CACHE_Type             U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GPUL2_CACHE_DISABLED       0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GPUL2_CACHE_ENABLED        0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_WORK_DISTRIBUTOR           13:13
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_WORK_DISTRIBUTOR_End          13
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_WORK_DISTRIBUTOR_Start        13
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_WORK_DISTRIBUTOR_Type        U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_WORK_DISTRIBUTOR_DISABLED  0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_WORK_DISTRIBUTOR_ENABLED   0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_POSITION_PA                14:14
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_POSITION_PA_End               14
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_POSITION_PA_Start             14
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_POSITION_PA_Type             U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_POSITION_PA_DISABLED       0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_POSITION_PA_ENABLED        0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FINAL_PA                   15:15
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FINAL_PA_End                  15
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FINAL_PA_Start                15
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FINAL_PA_Type                U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FINAL_PA_DISABLED          0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_FINAL_PA_ENABLED           0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_CTRL_SHADER           16:16
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_CTRL_SHADER_End          16
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_CTRL_SHADER_Start        16
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_CTRL_SHADER_Type        U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_CTRL_SHADER_DISABLED  0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_CTRL_SHADER_ENABLED   0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_EVAL_SHADER           17:17
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_EVAL_SHADER_End          17
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_EVAL_SHADER_Start        17
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_EVAL_SHADER_Type        U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_EVAL_SHADER_DISABLED  0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TESS_EVAL_SHADER_ENABLED   0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GEOMETRY_SHADER            18:18
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GEOMETRY_SHADER_End           18
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GEOMETRY_SHADER_Start         18
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GEOMETRY_SHADER_Type         U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GEOMETRY_SHADER_DISABLED   0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_GEOMETRY_SHADER_ENABLED    0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TRANSFORM_FEEDBACK         19:19
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TRANSFORM_FEEDBACK_End        19
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TRANSFORM_FEEDBACK_Start      19
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TRANSFORM_FEEDBACK_Type      U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TRANSFORM_FEEDBACK_DISABLED 0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_TRANSFORM_FEEDBACK_ENABLED 0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_UNIVERSAL_STORAGE          20:20
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_UNIVERSAL_STORAGE_End         20
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_UNIVERSAL_STORAGE_Start       20
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_UNIVERSAL_STORAGE_Type       U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_UNIVERSAL_STORAGE_DISABLED 0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_UNIVERSAL_STORAGE_ENABLED  0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_DIRECTORY                  21:21
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_DIRECTORY_End                 21
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_DIRECTORY_Start               21
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_DIRECTORY_Type               U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_DIRECTORY_DISABLED         0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_DIRECTORY_ENABLED          0x1


#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_BLIT                       22:22
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_BLIT_End                      22
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_BLIT_Start                    22
#define MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_BLIT_Type                    U01
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_BLIT_DISABLED              0x0
#define   MWV207REG_PROBE_AXI_PROBE_MODULE_ENABLE_BLIT_ENABLED               0x1




#define mwv207regAHBFullPipelineConfigRegAddrs                            0x017D
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_Address                       0x005F4
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_MSB                                15
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_LSB                                 0
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_BLK                                 0
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_Count                               1
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_FieldMask                  0x000001FF
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_ReadMask                   0x000001FF
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_WriteMask                  0x000001FF
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_ResetValue                 0x00000000


#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_OS_LIMIT                          8:0
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_OS_LIMIT_End                        8
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_OS_LIMIT_Start                      0
#define MWV207REG_AHB_FULL_PIPELINE_CONFIG_OS_LIMIT_Type                     U09


#endif


