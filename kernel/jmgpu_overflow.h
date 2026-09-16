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




#ifndef __jmgpuregWorkDistributor_h__
#define __jmgpuregWorkDistributor_h__





#define mwv207regWDConfigRegAddrs                                         0x6100
#define MWV207REG_WD_CONFIG_Address                                      0x18400
#define MWV207REG_WD_CONFIG_MSB                                               15
#define MWV207REG_WD_CONFIG_LSB                                                0
#define MWV207REG_WD_CONFIG_BLK                                                0
#define MWV207REG_WD_CONFIG_Count                                              1
#define MWV207REG_WD_CONFIG_FieldMask                                 0x000313F1
#define MWV207REG_WD_CONFIG_ReadMask                                  0x000313F1
#define MWV207REG_WD_CONFIG_WriteMask                                 0x000313F1
#define MWV207REG_WD_CONFIG_ResetValue                                0x00000000

#define MWV207REG_WD_CONFIG_ARB_PRIORITY                                     0:0
#define MWV207REG_WD_CONFIG_ARB_PRIORITY_End                                   0
#define MWV207REG_WD_CONFIG_ARB_PRIORITY_Start                                 0
#define MWV207REG_WD_CONFIG_ARB_PRIORITY_Type                                U01
#define   MWV207REG_WD_CONFIG_ARB_PRIORITY_UPSTREAM                          0x0
#define   MWV207REG_WD_CONFIG_ARB_PRIORITY_DOWNSTREAM                        0x1

#define MWV207REG_WD_CONFIG_EXTRA_PAGES                                      9:4
#define MWV207REG_WD_CONFIG_EXTRA_PAGES_End                                    9
#define MWV207REG_WD_CONFIG_EXTRA_PAGES_Start                                  4
#define MWV207REG_WD_CONFIG_EXTRA_PAGES_Type                                 U06


#define MWV207REG_WD_CONFIG_GS_GROUP_DISTRIBUTION                          12:12
#define MWV207REG_WD_CONFIG_GS_GROUP_DISTRIBUTION_End                         12
#define MWV207REG_WD_CONFIG_GS_GROUP_DISTRIBUTION_Start                       12
#define MWV207REG_WD_CONFIG_GS_GROUP_DISTRIBUTION_Type                       U01
#define   MWV207REG_WD_CONFIG_GS_GROUP_DISTRIBUTION_ADJACENT_CLUSTERS        0x0
#define   MWV207REG_WD_CONFIG_GS_GROUP_DISTRIBUTION_ONE_CLUSTER              0x1


#define MWV207REG_WD_CONFIG_EXECUTE_AT_NHOPS                               17:16
#define MWV207REG_WD_CONFIG_EXECUTE_AT_NHOPS_End                              17
#define MWV207REG_WD_CONFIG_EXECUTE_AT_NHOPS_Start                            16
#define MWV207REG_WD_CONFIG_EXECUTE_AT_NHOPS_Type                            U02




#define mwv207regWDStaticConfigRegAddrs                                   0x6101
#define MWV207REG_WD_STATIC_CONFIG_Address                               0x18404
#define MWV207REG_WD_STATIC_CONFIG_MSB                                        15
#define MWV207REG_WD_STATIC_CONFIG_LSB                                         0
#define MWV207REG_WD_STATIC_CONFIG_BLK                                         0
#define MWV207REG_WD_STATIC_CONFIG_Count                                       1
#define MWV207REG_WD_STATIC_CONFIG_FieldMask                          0x00000003
#define MWV207REG_WD_STATIC_CONFIG_ReadMask                           0x00000003
#define MWV207REG_WD_STATIC_CONFIG_WriteMask                          0x00000003
#define MWV207REG_WD_STATIC_CONFIG_ResetValue                         0x00000000


#define MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE                           1:0
#define MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE_End                         1
#define MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE_Start                       0
#define MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE_Type                      U02
#define   MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE_LOAD_BALANCE            0x0
#define   MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE_ROUND_ROBIN             0x1
#define   MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE_PSEUDO_RANDOM           0x2
#define   MWV207REG_WD_STATIC_CONFIG_ASSIGNMENT_MODE_LOWEST_ACTIVE           0x3





#define mwv207regVerifPrimitiveIdRegAddrs                                 0x6170
#define MWV207REG_VERIF_PRIMITIVE_ID_Address                             0x185C0
#define MWV207REG_VERIF_PRIMITIVE_ID_MSB                                      15
#define MWV207REG_VERIF_PRIMITIVE_ID_LSB                                       0
#define MWV207REG_VERIF_PRIMITIVE_ID_BLK                                       0
#define MWV207REG_VERIF_PRIMITIVE_ID_Count                                     1
#define MWV207REG_VERIF_PRIMITIVE_ID_FieldMask                        0xFFFFFFFF
#define MWV207REG_VERIF_PRIMITIVE_ID_ReadMask                         0xFFFFFFFF
#define MWV207REG_VERIF_PRIMITIVE_ID_WriteMask                        0xFFFFFFFF
#define MWV207REG_VERIF_PRIMITIVE_ID_ResetValue                       0x00000000


#define MWV207REG_VERIF_PRIMITIVE_ID_PRIMITIVE_ID                           31:0
#define MWV207REG_VERIF_PRIMITIVE_ID_PRIMITIVE_ID_End                         31
#define MWV207REG_VERIF_PRIMITIVE_ID_PRIMITIVE_ID_Start                        0
#define MWV207REG_VERIF_PRIMITIVE_ID_PRIMITIVE_ID_Type                       U32


#endif


