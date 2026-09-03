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




#ifndef __jmgpuregAHBTrustZone_h__
#define __jmgpuregAHBTrustZone_h__




#define mwv207regMMUAHBExceptionRegAddrs                                  0x00E0
#define MWV207REG_MMUAHB_EXCEPTION_Address                               0x00380
#define MWV207REG_MMUAHB_EXCEPTION_MSB                                        15
#define MWV207REG_MMUAHB_EXCEPTION_LSB                                         0
#define MWV207REG_MMUAHB_EXCEPTION_BLK                                         0
#define MWV207REG_MMUAHB_EXCEPTION_Count                                       1
#define MWV207REG_MMUAHB_EXCEPTION_FieldMask                          0xFFFFFFFF
#define MWV207REG_MMUAHB_EXCEPTION_ReadMask                           0xFFFFFFFF
#define MWV207REG_MMUAHB_EXCEPTION_WriteMask                          0xFFFFFFFF
#define MWV207REG_MMUAHB_EXCEPTION_ResetValue                         0x00000000


#define MWV207REG_MMUAHB_EXCEPTION_ADDRESS                                  31:0
#define MWV207REG_MMUAHB_EXCEPTION_ADDRESS_End                                31
#define MWV207REG_MMUAHB_EXCEPTION_ADDRESS_Start                               0
#define MWV207REG_MMUAHB_EXCEPTION_ADDRESS_Type                              U32



#define mwv207regMMUAHBStatusRegAddrs                                     0x00E1
#define MWV207REG_MMUAHB_STATUS_Address                                  0x00384
#define MWV207REG_MMUAHB_STATUS_MSB                                           15
#define MWV207REG_MMUAHB_STATUS_LSB                                            0
#define MWV207REG_MMUAHB_STATUS_BLK                                            0
#define MWV207REG_MMUAHB_STATUS_Count                                          1
#define MWV207REG_MMUAHB_STATUS_FieldMask                             0x77777777
#define MWV207REG_MMUAHB_STATUS_ReadMask                              0x77777777
#define MWV207REG_MMUAHB_STATUS_WriteMask                             0x00000000
#define MWV207REG_MMUAHB_STATUS_ResetValue                            0x00000000

#define MWV207REG_MMUAHB_STATUS_EXCEPTION0                                   2:0
#define MWV207REG_MMUAHB_STATUS_EXCEPTION0_End                                 2
#define MWV207REG_MMUAHB_STATUS_EXCEPTION0_Start                               0
#define MWV207REG_MMUAHB_STATUS_EXCEPTION0_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION0_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION0_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION0_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION0_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION0_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION0_WRITE_SECURITY_VIOLATION        0x6

#define MWV207REG_MMUAHB_STATUS_EXCEPTION1                                   6:4
#define MWV207REG_MMUAHB_STATUS_EXCEPTION1_End                                 6
#define MWV207REG_MMUAHB_STATUS_EXCEPTION1_Start                               4
#define MWV207REG_MMUAHB_STATUS_EXCEPTION1_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION1_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION1_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION1_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION1_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION1_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION1_WRITE_SECURITY_VIOLATION        0x6

#define MWV207REG_MMUAHB_STATUS_EXCEPTION2                                  10:8
#define MWV207REG_MMUAHB_STATUS_EXCEPTION2_End                                10
#define MWV207REG_MMUAHB_STATUS_EXCEPTION2_Start                               8
#define MWV207REG_MMUAHB_STATUS_EXCEPTION2_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION2_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION2_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION2_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION2_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION2_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION2_WRITE_SECURITY_VIOLATION        0x6

#define MWV207REG_MMUAHB_STATUS_EXCEPTION3                                 14:12
#define MWV207REG_MMUAHB_STATUS_EXCEPTION3_End                                14
#define MWV207REG_MMUAHB_STATUS_EXCEPTION3_Start                              12
#define MWV207REG_MMUAHB_STATUS_EXCEPTION3_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION3_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION3_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION3_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION3_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION3_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION3_WRITE_SECURITY_VIOLATION        0x6

#define MWV207REG_MMUAHB_STATUS_EXCEPTION4                                 18:16
#define MWV207REG_MMUAHB_STATUS_EXCEPTION4_End                                18
#define MWV207REG_MMUAHB_STATUS_EXCEPTION4_Start                              16
#define MWV207REG_MMUAHB_STATUS_EXCEPTION4_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION4_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION4_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION4_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION4_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION4_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION4_WRITE_SECURITY_VIOLATION        0x6

#define MWV207REG_MMUAHB_STATUS_EXCEPTION5                                 22:20
#define MWV207REG_MMUAHB_STATUS_EXCEPTION5_End                                22
#define MWV207REG_MMUAHB_STATUS_EXCEPTION5_Start                              20
#define MWV207REG_MMUAHB_STATUS_EXCEPTION5_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION5_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION5_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION5_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION5_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION5_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION5_WRITE_SECURITY_VIOLATION        0x6

#define MWV207REG_MMUAHB_STATUS_EXCEPTION6                                 26:24
#define MWV207REG_MMUAHB_STATUS_EXCEPTION6_End                                26
#define MWV207REG_MMUAHB_STATUS_EXCEPTION6_Start                              24
#define MWV207REG_MMUAHB_STATUS_EXCEPTION6_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION6_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION6_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION6_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION6_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION6_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION6_WRITE_SECURITY_VIOLATION        0x6

#define MWV207REG_MMUAHB_STATUS_EXCEPTION7                                 30:28
#define MWV207REG_MMUAHB_STATUS_EXCEPTION7_End                                30
#define MWV207REG_MMUAHB_STATUS_EXCEPTION7_Start                              28
#define MWV207REG_MMUAHB_STATUS_EXCEPTION7_Type                              U03
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION7_SLAVE_NOT_PRESENT               0x1
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION7_PAGE_NOT_PRESENT                0x2
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION7_WRITE_VIOLATION                 0x3
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION7_OUT_OF_BOUND                    0x4
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION7_READ_SECURITY_VIOLATION         0x5
#define   MWV207REG_MMUAHB_STATUS_EXCEPTION7_WRITE_SECURITY_VIOLATION        0x6



#define mwv207regMMUAHBControlRegAddrs                                    0x00E2
#define MWV207REG_MMUAHB_CONTROL_Address                                 0x00388
#define MWV207REG_MMUAHB_CONTROL_MSB                                          15
#define MWV207REG_MMUAHB_CONTROL_LSB                                           0
#define MWV207REG_MMUAHB_CONTROL_BLK                                           0
#define MWV207REG_MMUAHB_CONTROL_Count                                         1
#define MWV207REG_MMUAHB_CONTROL_FieldMask                            0x000003FF
#define MWV207REG_MMUAHB_CONTROL_ReadMask                             0x000003E0
#define MWV207REG_MMUAHB_CONTROL_WriteMask                            0x000003FF
#define MWV207REG_MMUAHB_CONTROL_ResetValue                           0x00000000

#define MWV207REG_MMUAHB_CONTROL_MMU                                         0:0
#define MWV207REG_MMUAHB_CONTROL_MMU_End                                       0
#define MWV207REG_MMUAHB_CONTROL_MMU_Start                                     0
#define MWV207REG_MMUAHB_CONTROL_MMU_Type                                    U01
#define   MWV207REG_MMUAHB_CONTROL_MMU_DISABLE                               0x0
#define   MWV207REG_MMUAHB_CONTROL_MMU_ENABLE                                0x1


#define MWV207REG_MMUAHB_CONTROL_STRICT_MODE                                 1:1
#define MWV207REG_MMUAHB_CONTROL_STRICT_MODE_End                               1
#define MWV207REG_MMUAHB_CONTROL_STRICT_MODE_Start                             1
#define MWV207REG_MMUAHB_CONTROL_STRICT_MODE_Type                            U01
#define   MWV207REG_MMUAHB_CONTROL_STRICT_MODE_DISABLE                       0x0
#define   MWV207REG_MMUAHB_CONTROL_STRICT_MODE_ENABLE                        0x1


#define MWV207REG_MMUAHB_CONTROL_OUT_OF_BOUND_EXCEPTION                      2:2
#define MWV207REG_MMUAHB_CONTROL_OUT_OF_BOUND_EXCEPTION_End                    2
#define MWV207REG_MMUAHB_CONTROL_OUT_OF_BOUND_EXCEPTION_Start                  2
#define MWV207REG_MMUAHB_CONTROL_OUT_OF_BOUND_EXCEPTION_Type                 U01
#define   MWV207REG_MMUAHB_CONTROL_OUT_OF_BOUND_EXCEPTION_DISABLE            0x0
#define   MWV207REG_MMUAHB_CONTROL_OUT_OF_BOUND_EXCEPTION_ENABLE             0x1


#define MWV207REG_MMUAHB_CONTROL_SECURITY_VIOL_EXCEPTION                     3:3
#define MWV207REG_MMUAHB_CONTROL_SECURITY_VIOL_EXCEPTION_End                   3
#define MWV207REG_MMUAHB_CONTROL_SECURITY_VIOL_EXCEPTION_Start                 3
#define MWV207REG_MMUAHB_CONTROL_SECURITY_VIOL_EXCEPTION_Type                U01
#define   MWV207REG_MMUAHB_CONTROL_SECURITY_VIOL_EXCEPTION_DISABLE           0x0
#define   MWV207REG_MMUAHB_CONTROL_SECURITY_VIOL_EXCEPTION_ENABLE            0x1

#define MWV207REG_MMUAHB_CONTROL_FORCE_NSBUFFER_READ_COHERENCY               4:4
#define MWV207REG_MMUAHB_CONTROL_FORCE_NSBUFFER_READ_COHERENCY_End             4
#define MWV207REG_MMUAHB_CONTROL_FORCE_NSBUFFER_READ_COHERENCY_Start           4
#define MWV207REG_MMUAHB_CONTROL_FORCE_NSBUFFER_READ_COHERENCY_Type          U01
#define   MWV207REG_MMUAHB_CONTROL_FORCE_NSBUFFER_READ_COHERENCY_DISABLE     0x0
#define   MWV207REG_MMUAHB_CONTROL_FORCE_NSBUFFER_READ_COHERENCY_ENABLE      0x1


#define MWV207REG_MMUAHB_CONTROL_SET_UP_MMU                                  5:5
#define MWV207REG_MMUAHB_CONTROL_SET_UP_MMU_End                                5
#define MWV207REG_MMUAHB_CONTROL_SET_UP_MMU_Start                              5
#define MWV207REG_MMUAHB_CONTROL_SET_UP_MMU_Type                             U01
#define   MWV207REG_MMUAHB_CONTROL_SET_UP_MMU_FROM_CMD                       0x0
#define   MWV207REG_MMUAHB_CONTROL_SET_UP_MMU_FROM_REG                       0x1


#define MWV207REG_MMUAHB_CONTROL_HI_ADDRESS_BITS                             9:6
#define MWV207REG_MMUAHB_CONTROL_HI_ADDRESS_BITS_End                           9
#define MWV207REG_MMUAHB_CONTROL_HI_ADDRESS_BITS_Start                         6
#define MWV207REG_MMUAHB_CONTROL_HI_ADDRESS_BITS_Type                        U04



#define mwv207regMMUAHBTableArrayBaseAddressLowRegAddrs                   0x00E3
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_Address            0x0038C
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_MSB                     15
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_LSB                      0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_BLK                      0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_Count                    1
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_FieldMask       0xFFFFFFFF
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_ReadMask        0xFFFFFFFF
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_WriteMask       0xFFFFFFFF
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_ResetValue      0x00000000


#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_ADDRESS               31:0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_ADDRESS_End             31
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_ADDRESS_Start            0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_LOW_ADDRESS_Type           U32



#define mwv207regMMUAHBTableArrayBaseAddressHighRegAddrs                  0x00E4
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_Address           0x00390
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MSB                    15
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_LSB                     0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_BLK                     0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_Count                   1
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_FieldMask      0x000003FF
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_ReadMask       0x000003FF
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_WriteMask      0x000003FF
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_ResetValue     0x00000000


#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB            7:0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_End          7
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_Start        0
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_Type       U08


#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SECURE     8:8
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SECURE_End   8
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SECURE_Start 8
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SECURE_Type U01


#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SHAREABLE  9:9
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SHAREABLE_End 9
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SHAREABLE_Start 9
#define MWV207REG_MMUAHB_TABLE_ARRAY_BASE_ADDRESS_HIGH_MASTER_TLB_SHAREABLE_Type U01



#define mwv207regMMUAHBTableArraySizeRegAddrs                             0x00E5
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_Address                        0x00394
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_MSB                                 15
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_LSB                                  0
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_BLK                                  0
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_Count                                1
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_FieldMask                   0x0000FFFF
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_ReadMask                    0x0000FFFF
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_WriteMask                   0x0000FFFF
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_ResetValue                  0x0000FFFF


#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_SIZE                              15:0
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_SIZE_End                            15
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_SIZE_Start                           0
#define MWV207REG_MMUAHB_TABLE_ARRAY_SIZE_SIZE_Type                          U16



#define mwv207regMMUAHBSafeNonSecureAddressRegAddrs                       0x00E6
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_Address                 0x00398
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_MSB                          15
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_LSB                           0
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_BLK                           0
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_Count                         1
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_FieldMask            0xFFFFFFFF
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_ReadMask             0xFFFFFFC0
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_WriteMask            0xFFFFFFC0
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_ResetValue           0x00000000


#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_ADDRESS                    31:0
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_ADDRESS_End                  31
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_ADDRESS_Start                 0
#define MWV207REG_MMUAHB_SAFE_NON_SECURE_ADDRESS_ADDRESS_Type                U32



#define mwv207regMMUAHBSafeSecureAddressRegAddrs                          0x00E7
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_Address                     0x0039C
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_MSB                              15
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_LSB                               0
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_BLK                               0
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_Count                             1
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_FieldMask                0xFFFFFFFF
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_ReadMask                 0xFFFFFFC0
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_WriteMask                0xFFFFFFC0
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_ResetValue               0x00000000


#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_ADDRESS                        31:0
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_ADDRESS_End                      31
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_ADDRESS_Start                     0
#define MWV207REG_MMUAHB_SAFE_SECURE_ADDRESS_ADDRESS_Type                    U32



#define mwv207regMMUAHBSafeAddressExtRegAddrs                             0x00E8
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_Address                        0x003A0
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MSB                                 15
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_LSB                                  0
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_BLK                                  0
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_Count                                1
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_FieldMask                   0xC0FFC0FF
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_ReadMask                    0xC0FFC0FF
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_WriteMask                   0xC0FFC0FF
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_ResetValue                  0x00000000

#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE            7:0
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE_End          7
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE_Start        0
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE_Type       U08


#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE_SHAREABLE 14:14
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE_SHAREABLE_End 14
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE_SHAREABLE_Start 14
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_NON_SECURE_SHAREABLE_Type U01


#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_NON_SECURE     15:15
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_NON_SECURE_End    15
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_NON_SECURE_Start  15
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_NON_SECURE_Type  U01
#define   MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_NON_SECURE_ENABLED 0x0
#define   MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_NON_SECURE_MASKED 0x1

#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE              23:16
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE_End             23
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE_Start           16
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE_Type           U08


#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE_SHAREABLE    30:30
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE_SHAREABLE_End   30
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE_SHAREABLE_Start 30
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_SAFE_ADDRESS_SECURE_SHAREABLE_Type U01


#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_SECURE         31:31
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_SECURE_End        31
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_SECURE_Start      31
#define MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_SECURE_Type      U01
#define   MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_SECURE_ENABLED 0x0
#define   MWV207REG_MMUAHB_SAFE_ADDRESS_EXT_MASK_SAFE_ADDRESS_SECURE_MASKED  0x1



#define mwv207regCmdBufferAHBCtrlRegAddrs                                 0x00E9
#define MWV207REG_CMD_BUFFER_AHB_CTRL_Address                            0x003A4
#define MWV207REG_CMD_BUFFER_AHB_CTRL_MSB                                     15
#define MWV207REG_CMD_BUFFER_AHB_CTRL_LSB                                      0
#define MWV207REG_CMD_BUFFER_AHB_CTRL_BLK                                      0
#define MWV207REG_CMD_BUFFER_AHB_CTRL_Count                                    1
#define MWV207REG_CMD_BUFFER_AHB_CTRL_FieldMask                       0x0031FFFF
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ReadMask                        0x00000000
#define MWV207REG_CMD_BUFFER_AHB_CTRL_WriteMask                       0x0031FFFF
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ResetValue                      0x00000000


#define MWV207REG_CMD_BUFFER_AHB_CTRL_PREFETCH                              15:0
#define MWV207REG_CMD_BUFFER_AHB_CTRL_PREFETCH_End                            15
#define MWV207REG_CMD_BUFFER_AHB_CTRL_PREFETCH_Start                           0
#define MWV207REG_CMD_BUFFER_AHB_CTRL_PREFETCH_Type                          U16


#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENABLE                               16:16
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENABLE_End                              16
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENABLE_Start                            16
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENABLE_Type                            U01
#define   MWV207REG_CMD_BUFFER_AHB_CTRL_ENABLE_DISABLE                       0x0
#define   MWV207REG_CMD_BUFFER_AHB_CTRL_ENABLE_ENABLE                        0x1


#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL                       21:20
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL_End                      21
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL_Start                    20
#define MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL_Type                    U02
#define   MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL_NO_SWAP               0x0
#define   MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL_SWAP_WORD             0x1
#define   MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL_SWAP_DWORD            0x2
#define   MWV207REG_CMD_BUFFER_AHB_CTRL_ENDIAN_CONTROL_SWAP_DDWORD           0x3



#define mwv207regHiAHBControlRegAddrs                                     0x00EA
#define MWV207REG_HI_AHB_CONTROL_Address                                 0x003A8
#define MWV207REG_HI_AHB_CONTROL_MSB                                          15
#define MWV207REG_HI_AHB_CONTROL_LSB                                           0
#define MWV207REG_HI_AHB_CONTROL_BLK                                           0
#define MWV207REG_HI_AHB_CONTROL_Count                                         1
#define MWV207REG_HI_AHB_CONTROL_FieldMask                            0x0000001F
#define MWV207REG_HI_AHB_CONTROL_ReadMask                             0x0000001F
#define MWV207REG_HI_AHB_CONTROL_WriteMask                            0x0000000F
#define MWV207REG_HI_AHB_CONTROL_ResetValue                           0x00000010

#define MWV207REG_HI_AHB_CONTROL_SOFT_RESET                                  0:0
#define MWV207REG_HI_AHB_CONTROL_SOFT_RESET_End                                0
#define MWV207REG_HI_AHB_CONTROL_SOFT_RESET_Start                              0
#define MWV207REG_HI_AHB_CONTROL_SOFT_RESET_Type                             U01
#define   MWV207REG_HI_AHB_CONTROL_SOFT_RESET_DISABLE                        0x0
#define   MWV207REG_HI_AHB_CONTROL_SOFT_RESET_ENABLE                         0x1

#define MWV207REG_HI_AHB_CONTROL_DEBUG_MODE                                  1:1
#define MWV207REG_HI_AHB_CONTROL_DEBUG_MODE_End                                1
#define MWV207REG_HI_AHB_CONTROL_DEBUG_MODE_Start                              1
#define MWV207REG_HI_AHB_CONTROL_DEBUG_MODE_Type                             U01
#define   MWV207REG_HI_AHB_CONTROL_DEBUG_MODE_DISABLE                        0x0
#define   MWV207REG_HI_AHB_CONTROL_DEBUG_MODE_ENABLE                         0x1


#define MWV207REG_HI_AHB_CONTROL_CLUSTER_POWER_GATING                        2:2
#define MWV207REG_HI_AHB_CONTROL_CLUSTER_POWER_GATING_End                      2
#define MWV207REG_HI_AHB_CONTROL_CLUSTER_POWER_GATING_Start                    2
#define MWV207REG_HI_AHB_CONTROL_CLUSTER_POWER_GATING_Type                   U01
#define   MWV207REG_HI_AHB_CONTROL_CLUSTER_POWER_GATING_DISABLE              0x0
#define   MWV207REG_HI_AHB_CONTROL_CLUSTER_POWER_GATING_ENABLE               0x1

#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_CANCEL                              3:3
#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_CANCEL_End                            3
#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_CANCEL_Start                          3
#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_CANCEL_Type                         U01
#define   MWV207REG_HI_AHB_CONTROL_VIP_JOB_CANCEL_DISABLE                    0x0
#define   MWV207REG_HI_AHB_CONTROL_VIP_JOB_CANCEL_ENABLE                     0x1

#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_STATUS                              4:4
#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_STATUS_End                            4
#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_STATUS_Start                          4
#define MWV207REG_HI_AHB_CONTROL_VIP_JOB_STATUS_Type                         U01
#define   MWV207REG_HI_AHB_CONTROL_VIP_JOB_STATUS_CANCELLED                  0x1



#define mwv207regAxiAHBConfigRegAddrs                                     0x00EB
#define MWV207REG_AXI_AHB_CONFIG_Address                                 0x003AC
#define MWV207REG_AXI_AHB_CONFIG_MSB                                          15
#define MWV207REG_AXI_AHB_CONFIG_LSB                                           0
#define MWV207REG_AXI_AHB_CONFIG_BLK                                           0
#define MWV207REG_AXI_AHB_CONFIG_Count                                         1
#define MWV207REG_AXI_AHB_CONFIG_FieldMask                            0x00FFFFFF
#define MWV207REG_AXI_AHB_CONFIG_ReadMask                             0x00FFFFFF
#define MWV207REG_AXI_AHB_CONFIG_WriteMask                            0x00FFFFFF
#define MWV207REG_AXI_AHB_CONFIG_ResetValue                           0x00222200


#define MWV207REG_AXI_AHB_CONFIG_AWID                                        3:0
#define MWV207REG_AXI_AHB_CONFIG_AWID_End                                      3
#define MWV207REG_AXI_AHB_CONFIG_AWID_Start                                    0
#define MWV207REG_AXI_AHB_CONFIG_AWID_Type                                   U04


#define MWV207REG_AXI_AHB_CONFIG_ARID                                        7:4
#define MWV207REG_AXI_AHB_CONFIG_ARID_End                                      7
#define MWV207REG_AXI_AHB_CONFIG_ARID_Start                                    4
#define MWV207REG_AXI_AHB_CONFIG_ARID_Type                                   U04


#define MWV207REG_AXI_AHB_CONFIG_AWCACHE                                    11:8
#define MWV207REG_AXI_AHB_CONFIG_AWCACHE_End                                  11
#define MWV207REG_AXI_AHB_CONFIG_AWCACHE_Start                                 8
#define MWV207REG_AXI_AHB_CONFIG_AWCACHE_Type                                U04


#define MWV207REG_AXI_AHB_CONFIG_ARCACHE                                   15:12
#define MWV207REG_AXI_AHB_CONFIG_ARCACHE_End                                  15
#define MWV207REG_AXI_AHB_CONFIG_ARCACHE_Start                                12
#define MWV207REG_AXI_AHB_CONFIG_ARCACHE_Type                                U04


#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_SHARED                           17:16
#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_SHARED_End                          17
#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_SHARED_Start                        16
#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_SHARED_Type                        U02


#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_NON_SHARED                       19:18
#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_NON_SHARED_End                      19
#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_NON_SHARED_Start                    18
#define MWV207REG_AXI_AHB_CONFIG_AXDOMAIN_NON_SHARED_Type                    U02


#define MWV207REG_AXI_AHB_CONFIG_AXCACHE_OVERRIDE_SHARED                   23:20
#define MWV207REG_AXI_AHB_CONFIG_AXCACHE_OVERRIDE_SHARED_End                  23
#define MWV207REG_AXI_AHB_CONFIG_AXCACHE_OVERRIDE_SHARED_Start                20
#define MWV207REG_AXI_AHB_CONFIG_AXCACHE_OVERRIDE_SHARED_Type                U04



#define mwv207regAxiAHBConfigExRegAddrs                                   0x00F0
#define MWV207REG_AXI_AHB_CONFIG_EX_Address                              0x003C0
#define MWV207REG_AXI_AHB_CONFIG_EX_MSB                                       15
#define MWV207REG_AXI_AHB_CONFIG_EX_LSB                                        4
#define MWV207REG_AXI_AHB_CONFIG_EX_BLK                                        4
#define MWV207REG_AXI_AHB_CONFIG_EX_Count                                     16
#define MWV207REG_AXI_AHB_CONFIG_EX_FieldMask                         0x0FFF0FFF
#define MWV207REG_AXI_AHB_CONFIG_EX_ReadMask                          0x0FFF0FFF
#define MWV207REG_AXI_AHB_CONFIG_EX_WriteMask                         0x0FFF0FFF
#define MWV207REG_AXI_AHB_CONFIG_EX_ResetValue                        0x00000000


#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_CACHE                             3:0
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_CACHE_End                           3
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_CACHE_Start                         0
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_CACHE_Type                        U04


#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_CACHE                             7:4
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_CACHE_End                           7
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_CACHE_Start                         4
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_CACHE_Type                        U04


#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_DOMAIN                            9:8
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_DOMAIN_End                          9
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_DOMAIN_Start                        8
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AW_DOMAIN_Type                       U02


#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_DOMAIN                          11:10
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_DOMAIN_End                         11
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_DOMAIN_Start                       10
#define MWV207REG_AXI_AHB_CONFIG_EX_LOW_AR_DOMAIN_Type                       U02


#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_CACHE                          19:16
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_CACHE_End                         19
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_CACHE_Start                       16
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_CACHE_Type                       U04


#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_CACHE                          23:20
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_CACHE_End                         23
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_CACHE_Start                       20
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_CACHE_Type                       U04


#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_DOMAIN                         25:24
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_DOMAIN_End                        25
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_DOMAIN_Start                      24
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AW_DOMAIN_Type                      U02


#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_DOMAIN                         27:26
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_DOMAIN_End                        27
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_DOMAIN_Start                      26
#define MWV207REG_AXI_AHB_CONFIG_EX_HIGH_AR_DOMAIN_Type                      U02




#define mwv207regAHBControl0RegAddrs                                      0x00EC
#define MWV207REG_AHB_CONTROL0_Address                                   0x003B0
#define MWV207REG_AHB_CONTROL0_MSB                                            15
#define MWV207REG_AHB_CONTROL0_LSB                                             0
#define MWV207REG_AHB_CONTROL0_BLK                                             0
#define MWV207REG_AHB_CONTROL0_Count                                           1
#define MWV207REG_AHB_CONTROL0_FieldMask                              0x3FFF00FF
#define MWV207REG_AHB_CONTROL0_ReadMask                               0x3FFF00FF
#define MWV207REG_AHB_CONTROL0_WriteMask                              0x3FFF00FF
#define MWV207REG_AHB_CONTROL0_ResetValue                             0x00800005

#define MWV207REG_AHB_CONTROL0_ENABLE_READ_MERGE                             0:0
#define MWV207REG_AHB_CONTROL0_ENABLE_READ_MERGE_End                           0
#define MWV207REG_AHB_CONTROL0_ENABLE_READ_MERGE_Start                         0
#define MWV207REG_AHB_CONTROL0_ENABLE_READ_MERGE_Type                        U01

#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_MERGE                        1:1
#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_MERGE_End                      1
#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_MERGE_Start                    1
#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_MERGE_Type                   U01

#define MWV207REG_AHB_CONTROL0_ENABLE_WRITE_MERGE                            2:2
#define MWV207REG_AHB_CONTROL0_ENABLE_WRITE_MERGE_End                          2
#define MWV207REG_AHB_CONTROL0_ENABLE_WRITE_MERGE_Start                        2
#define MWV207REG_AHB_CONTROL0_ENABLE_WRITE_MERGE_Type                       U01

#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE                  3:3
#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_End                3
#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_Start              3
#define MWV207REG_AHB_CONTROL0_ENABLE_UNALIGNED_WRITE_MERGE_Type             U01

#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_REORDER                           4:4
#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_REORDER_End                         4
#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_REORDER_Start                       4
#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_REORDER_Type                      U01

#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_WRITE_REORDER                     5:5
#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_WRITE_REORDER_End                   5
#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_WRITE_REORDER_Start                 5
#define MWV207REG_AHB_CONTROL0_DISABLE_AXI_WRITE_REORDER_Type                U01

#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI0                                 6:6
#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI0_End                               6
#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI0_Start                             6
#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI0_Type                            U01

#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI1                                 7:7
#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI1_End                               7
#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI1_Start                             7
#define MWV207REG_AHB_CONTROL0_FORCE_ON_AXI1_Type                            U01

#define MWV207REG_AHB_CONTROL0_OUTSTANDING_READS_PER_CHANNEL               25:16
#define MWV207REG_AHB_CONTROL0_OUTSTANDING_READS_PER_CHANNEL_End              25
#define MWV207REG_AHB_CONTROL0_OUTSTANDING_READS_PER_CHANNEL_Start            16
#define MWV207REG_AHB_CONTROL0_OUTSTANDING_READS_PER_CHANNEL_Type            U10


#define MWV207REG_AHB_CONTROL0_BY_PASS_TPC                                 26:26
#define MWV207REG_AHB_CONTROL0_BY_PASS_TPC_End                                26
#define MWV207REG_AHB_CONTROL0_BY_PASS_TPC_Start                              26
#define MWV207REG_AHB_CONTROL0_BY_PASS_TPC_Type                              U01
#define   MWV207REG_AHB_CONTROL0_BY_PASS_TPC_DISABLED                        0x0
#define   MWV207REG_AHB_CONTROL0_BY_PASS_TPC_ENABLED                         0x1


#define MWV207REG_AHB_CONTROL0_DEBUG_TPC                                   27:27
#define MWV207REG_AHB_CONTROL0_DEBUG_TPC_End                                  27
#define MWV207REG_AHB_CONTROL0_DEBUG_TPC_Start                                27
#define MWV207REG_AHB_CONTROL0_DEBUG_TPC_Type                                U01
#define   MWV207REG_AHB_CONTROL0_DEBUG_TPC_DISABLED                          0x0
#define   MWV207REG_AHB_CONTROL0_DEBUG_TPC_ENABLED                           0x1


#define MWV207REG_AHB_CONTROL0_COMPRESSION_ALIGN_64B                       28:28
#define MWV207REG_AHB_CONTROL0_COMPRESSION_ALIGN_64B_End                      28
#define MWV207REG_AHB_CONTROL0_COMPRESSION_ALIGN_64B_Start                    28
#define MWV207REG_AHB_CONTROL0_COMPRESSION_ALIGN_64B_Type                    U01
#define   MWV207REG_AHB_CONTROL0_COMPRESSION_ALIGN_64B_DISABLED              0x0
#define   MWV207REG_AHB_CONTROL0_COMPRESSION_ALIGN_64B_ENABLED               0x1


#define MWV207REG_AHB_CONTROL0_DISABLE_TIMESTAMP                           29:29
#define MWV207REG_AHB_CONTROL0_DISABLE_TIMESTAMP_End                          29
#define MWV207REG_AHB_CONTROL0_DISABLE_TIMESTAMP_Start                        29
#define MWV207REG_AHB_CONTROL0_DISABLE_TIMESTAMP_Type                        U01
#define   MWV207REG_AHB_CONTROL0_DISABLE_TIMESTAMP_DISABLED                  0x0
#define   MWV207REG_AHB_CONTROL0_DISABLE_TIMESTAMP_ENABLED                   0x1




#define mwv207regMMUAHBContextPDEntry0RegAddrs                            0x00ED
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_Address                       0x003B4
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MSB                                15
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_LSB                                 0
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_BLK                                 0
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_Count                               1
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_FieldMask                  0xFFFFFFFF
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_ReadMask                   0xFFFFFFFF
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_WriteMask                  0xFFFFFFFF
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_ResetValue                 0x00000000


#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_MODE                   1:0
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_MODE_End                 1
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_MODE_Start               0
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_MODE_Type              U02
#define   MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_MODE_FOUR_K_MODE     0x0
#define   MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_MODE_ONE_K_MODE      0x1
#define   MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_MODE_BY_PASS_MODE    0x2


#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SHARABLE               2:2
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SHARABLE_End             2
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SHARABLE_Start           2
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SHARABLE_Type          U01


#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SECURE                 3:3
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SECURE_End               3
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SECURE_Start             3
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_MASTER_TLB_SECURE_Type            U01


#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_PD_ADDRESS                       31:4
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_PD_ADDRESS_End                     31
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_PD_ADDRESS_Start                    4
#define MWV207REG_MMUAHB_CONTEXT_PD_ENTRY0_PD_ADDRESS_Type                   U28



#define mwv207regMMUAHBExceptionHighRegAddrs                              0x00EE
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_Address                          0x003B8
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_MSB                                   15
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_LSB                                    0
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_BLK                                    0
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_Count                                  1
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_FieldMask                     0x000000FF
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_ReadMask                      0x000000FF
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_WriteMask                     0x000000FF
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_ResetValue                    0x00000000


#define MWV207REG_MMUAHB_EXCEPTION_HIGH_ADDRESS                              7:0
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_ADDRESS_End                            7
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_ADDRESS_Start                          0
#define MWV207REG_MMUAHB_EXCEPTION_HIGH_ADDRESS_Type                         U08


#endif


