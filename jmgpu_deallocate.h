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




#ifndef __jmgpuregAHBMCFE_h__
#define __jmgpuregAHBMCFE_h__




#define mwv207regMCFEStdDescRingBufStartAddrRegAddrs                      0x0900
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address              0x02400
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_MSB                       15
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_LSB                        6
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_BLK                        0
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Count                     64
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_FieldMask         0xFFFFFFFF
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_ReadMask          0xFFFFFFFF
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_WriteMask         0xFFFFFFFF
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_ResetValue        0x00000000

#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_ADDRESS                 31:0
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_ADDRESS_End               31
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_ADDRESS_Start              0
#define MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_ADDRESS_Type             U32



#define mwv207regMCFEStdDescFifoDepthExpRegAddrs                          0x0940
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_Address                   0x02500
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_MSB                            15
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_LSB                             6
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_BLK                             0
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_Count                          64
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_FieldMask              0x0000001F
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_ReadMask               0x0000001F
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_WriteMask              0x0000001F
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_ResetValue             0x00000000


#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_VALUE                         4:0
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_VALUE_End                       4
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_VALUE_Start                     0
#define MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_VALUE_Type                    U05



#define mwv207regMCFEStdDescFifoWrPtrRegAddrs                             0x0980
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_Address                      0x02600
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_MSB                               15
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_LSB                                6
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_BLK                                0
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_Count                             64
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_FieldMask                 0x0000FFFF
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_ReadMask                  0x00000000
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_WriteMask                 0x0000FFFF
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_ResetValue                0x00000000

#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_VALUE                           15:0
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_VALUE_End                         15
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_VALUE_Start                        0
#define MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_VALUE_Type                       U16



#define mwv207regMCFEStdDescFifoRdPtrRegAddrs                             0x09C0
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_Address                      0x02700
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_MSB                               15
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_LSB                                6
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_BLK                                0
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_Count                             64
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_FieldMask                 0x0000FFFF
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_ReadMask                  0x0000FFFF
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_WriteMask                 0x00000000
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_ResetValue                0x00000000

#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_VALUE                           15:0
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_VALUE_End                         15
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_VALUE_Start                        0
#define MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_VALUE_Type                       U16



#define mwv207regMCFEPriDescRingBufStartAddrRegAddrs                      0x0A00
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_Address              0x02800
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_MSB                       15
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_LSB                        6
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_BLK                        0
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_Count                     64
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_FieldMask         0xFFFFFFFF
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_ReadMask          0xFFFFFFFF
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_WriteMask         0xFFFFFFFF
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_ResetValue        0x00000000

#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_ADDRESS                 31:0
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_ADDRESS_End               31
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_ADDRESS_Start              0
#define MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_ADDRESS_Type             U32



#define mwv207regMCFEPriDescFifoDepthExpRegAddrs                          0x0A40
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_Address                   0x02900
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_MSB                            15
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_LSB                             6
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_BLK                             0
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_Count                          64
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_FieldMask              0x0000001F
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_ReadMask               0x0000001F
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_WriteMask              0x0000001F
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_ResetValue             0x00000000


#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_VALUE                         4:0
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_VALUE_End                       4
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_VALUE_Start                     0
#define MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_VALUE_Type                    U05



#define mwv207regMCFEPriDescFifoWrPtrRegAddrs                             0x0A80
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_Address                      0x02A00
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_MSB                               15
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_LSB                                6
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_BLK                                0
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_Count                             64
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_FieldMask                 0x0000FFFF
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_ReadMask                  0x00000000
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_WriteMask                 0x0000FFFF
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_ResetValue                0x00000000

#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_VALUE                           15:0
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_VALUE_End                         15
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_VALUE_Start                        0
#define MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_VALUE_Type                       U16



#define mwv207regMCFEPriDescFifoRdPtrRegAddrs                             0x0AC0
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_Address                      0x02B00
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_MSB                               15
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_LSB                                6
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_BLK                                0
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_Count                             64
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_FieldMask                 0x0000FFFF
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_ReadMask                  0x0000FFFF
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_WriteMask                 0x00000000
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_ResetValue                0x00000000

#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_VALUE                           15:0
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_VALUE_End                         15
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_VALUE_Start                        0
#define MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_VALUE_Type                       U16



#define MCFE_COMMAND_OPCODE                                                31:27
#define MCFE_COMMAND_OPCODE_End                                               31
#define MCFE_COMMAND_OPCODE_Start                                             27
#define MCFE_COMMAND_OPCODE_Type                                             U05
#define   MCFE_COMMAND_OPCODE_LOAD_STATE                                    0x01
#define   MCFE_COMMAND_OPCODE_NOP                                           0x03
#define   MCFE_COMMAND_OPCODE_SUB_COMMAND                                   0x16


#define MCFE_COMMAND_SUB_OPCODE                                            25:16
#define MCFE_COMMAND_SUB_OPCODE_End                                           25
#define MCFE_COMMAND_SUB_OPCODE_Start                                         16
#define MCFE_COMMAND_SUB_OPCODE_Type                                         U10
#define   MCFE_COMMAND_SUB_OPCODE_SUBMIT_JOB                               0x001
#define   MCFE_COMMAND_SUB_OPCODE_SEND_SEMAPHORE                           0x002
#define   MCFE_COMMAND_SUB_OPCODE_WAIT_SEMAPHORE                           0x003
#define   MCFE_COMMAND_SUB_OPCODE_LOCK                                     0x004
#define   MCFE_COMMAND_SUB_OPCODE_UNLOCK                                   0x005
#define   MCFE_COMMAND_SUB_OPCODE_INTERRUPT_EVENT                          0x006



#define MCFE_COMMAND_LOADSTATE_OPCODE                                      31:27
#define MCFE_COMMAND_LOADSTATE_OPCODE_End                                     31
#define MCFE_COMMAND_LOADSTATE_OPCODE_Start                                   27
#define MCFE_COMMAND_LOADSTATE_OPCODE_Type                                   U05
#define   MCFE_COMMAND_LOADSTATE_OPCODE_LOAD_STATE                          0x01
#define   MCFE_COMMAND_LOADSTATE_OPCODE_NOP                                 0x03
#define   MCFE_COMMAND_LOADSTATE_OPCODE_SUB_COMMAND                         0x16


#define MCFE_COMMAND_LOADSTATE_COUNT                                       25:16
#define MCFE_COMMAND_LOADSTATE_COUNT_End                                      25
#define MCFE_COMMAND_LOADSTATE_COUNT_Start                                    16
#define MCFE_COMMAND_LOADSTATE_COUNT_Type                                    U10


#define MCFE_COMMAND_LOADSTATE_ADDRESS                                      15:0
#define MCFE_COMMAND_LOADSTATE_ADDRESS_End                                    15
#define MCFE_COMMAND_LOADSTATE_ADDRESS_Start                                   0
#define MCFE_COMMAND_LOADSTATE_ADDRESS_Type                                  U16



#define MCFE_COMMAND_SUBMITJOB_OPCODE                                      31:27
#define MCFE_COMMAND_SUBMITJOB_OPCODE_End                                     31
#define MCFE_COMMAND_SUBMITJOB_OPCODE_Start                                   27
#define MCFE_COMMAND_SUBMITJOB_OPCODE_Type                                   U05
#define   MCFE_COMMAND_SUBMITJOB_OPCODE_LOAD_STATE                          0x01
#define   MCFE_COMMAND_SUBMITJOB_OPCODE_NOP                                 0x03
#define   MCFE_COMMAND_SUBMITJOB_OPCODE_SUB_COMMAND                         0x16


#define MCFE_COMMAND_SUBMITJOB_SUB_OPCODE                                  25:16
#define MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_End                                 25
#define MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_Start                               16
#define MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_Type                               U10
#define   MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_SUBMIT_JOB                     0x001
#define   MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_SEND_SEMAPHORE                 0x002
#define   MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_WAIT_SEMAPHORE                 0x003
#define   MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_LOCK                           0x004
#define   MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_UNLOCK                         0x005
#define   MCFE_COMMAND_SUBMITJOB_SUB_OPCODE_INTERRUPT_EVENT                0x006



#define MCFE_COMMAND_SENDSEMAPHORE_OPCODE                                  31:27
#define MCFE_COMMAND_SENDSEMAPHORE_OPCODE_End                                 31
#define MCFE_COMMAND_SENDSEMAPHORE_OPCODE_Start                               27
#define MCFE_COMMAND_SENDSEMAPHORE_OPCODE_Type                               U05
#define   MCFE_COMMAND_SENDSEMAPHORE_OPCODE_LOAD_STATE                      0x01
#define   MCFE_COMMAND_SENDSEMAPHORE_OPCODE_NOP                             0x03
#define   MCFE_COMMAND_SENDSEMAPHORE_OPCODE_SUB_COMMAND                     0x16


#define MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE                              25:16
#define MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_End                             25
#define MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_Start                           16
#define MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_Type                           U10
#define   MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_SUBMIT_JOB                 0x001
#define   MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_SEND_SEMAPHORE             0x002
#define   MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_WAIT_SEMAPHORE             0x003
#define   MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_LOCK                       0x004
#define   MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_UNLOCK                     0x005
#define   MCFE_COMMAND_SENDSEMAPHORE_SUB_OPCODE_INTERRUPT_EVENT            0x006


#define MCFE_COMMAND_SENDSEMAPHORE_SEMAPHORE_ID                             15:0
#define MCFE_COMMAND_SENDSEMAPHORE_SEMAPHORE_ID_End                           15
#define MCFE_COMMAND_SENDSEMAPHORE_SEMAPHORE_ID_Start                          0
#define MCFE_COMMAND_SENDSEMAPHORE_SEMAPHORE_ID_Type                         U16



#define MCFE_COMMAND_WAITSEMAPHORE_OPCODE                                  31:27
#define MCFE_COMMAND_WAITSEMAPHORE_OPCODE_End                                 31
#define MCFE_COMMAND_WAITSEMAPHORE_OPCODE_Start                               27
#define MCFE_COMMAND_WAITSEMAPHORE_OPCODE_Type                               U05
#define   MCFE_COMMAND_WAITSEMAPHORE_OPCODE_LOAD_STATE                      0x01
#define   MCFE_COMMAND_WAITSEMAPHORE_OPCODE_NOP                             0x03
#define   MCFE_COMMAND_WAITSEMAPHORE_OPCODE_SUB_COMMAND                     0x16


#define MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE                              25:16
#define MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_End                             25
#define MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_Start                           16
#define MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_Type                           U10
#define   MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_SUBMIT_JOB                 0x001
#define   MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_SEND_SEMAPHORE             0x002
#define   MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_WAIT_SEMAPHORE             0x003
#define   MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_LOCK                       0x004
#define   MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_UNLOCK                     0x005
#define   MCFE_COMMAND_WAITSEMAPHORE_SUB_OPCODE_INTERRUPT_EVENT            0x006


#define MCFE_COMMAND_WAITSEMAPHORE_SEMAPHORE_ID                             15:0
#define MCFE_COMMAND_WAITSEMAPHORE_SEMAPHORE_ID_End                           15
#define MCFE_COMMAND_WAITSEMAPHORE_SEMAPHORE_ID_Start                          0
#define MCFE_COMMAND_WAITSEMAPHORE_SEMAPHORE_ID_Type                         U16



#define MCFE_COMMAND_LOCK_OPCODE                                           31:27
#define MCFE_COMMAND_LOCK_OPCODE_End                                          31
#define MCFE_COMMAND_LOCK_OPCODE_Start                                        27
#define MCFE_COMMAND_LOCK_OPCODE_Type                                        U05
#define   MCFE_COMMAND_LOCK_OPCODE_LOAD_STATE                               0x01
#define   MCFE_COMMAND_LOCK_OPCODE_NOP                                      0x03
#define   MCFE_COMMAND_LOCK_OPCODE_SUB_COMMAND                              0x16


#define MCFE_COMMAND_LOCK_SUB_OPCODE                                       25:16
#define MCFE_COMMAND_LOCK_SUB_OPCODE_End                                      25
#define MCFE_COMMAND_LOCK_SUB_OPCODE_Start                                    16
#define MCFE_COMMAND_LOCK_SUB_OPCODE_Type                                    U10
#define   MCFE_COMMAND_LOCK_SUB_OPCODE_SUBMIT_JOB                          0x001
#define   MCFE_COMMAND_LOCK_SUB_OPCODE_SEND_SEMAPHORE                      0x002
#define   MCFE_COMMAND_LOCK_SUB_OPCODE_WAIT_SEMAPHORE                      0x003
#define   MCFE_COMMAND_LOCK_SUB_OPCODE_LOCK                                0x004
#define   MCFE_COMMAND_LOCK_SUB_OPCODE_UNLOCK                              0x005
#define   MCFE_COMMAND_LOCK_SUB_OPCODE_INTERRUPT_EVENT                     0x006



#define MCFE_COMMAND_UNLOCK_OPCODE                                         31:27
#define MCFE_COMMAND_UNLOCK_OPCODE_End                                        31
#define MCFE_COMMAND_UNLOCK_OPCODE_Start                                      27
#define MCFE_COMMAND_UNLOCK_OPCODE_Type                                      U05
#define   MCFE_COMMAND_UNLOCK_OPCODE_LOAD_STATE                             0x01
#define   MCFE_COMMAND_UNLOCK_OPCODE_NOP                                    0x03
#define   MCFE_COMMAND_UNLOCK_OPCODE_SUB_COMMAND                            0x16


#define MCFE_COMMAND_UNLOCK_SUB_OPCODE                                     25:16
#define MCFE_COMMAND_UNLOCK_SUB_OPCODE_End                                    25
#define MCFE_COMMAND_UNLOCK_SUB_OPCODE_Start                                  16
#define MCFE_COMMAND_UNLOCK_SUB_OPCODE_Type                                  U10
#define   MCFE_COMMAND_UNLOCK_SUB_OPCODE_SUBMIT_JOB                        0x001
#define   MCFE_COMMAND_UNLOCK_SUB_OPCODE_SEND_SEMAPHORE                    0x002
#define   MCFE_COMMAND_UNLOCK_SUB_OPCODE_WAIT_SEMAPHORE                    0x003
#define   MCFE_COMMAND_UNLOCK_SUB_OPCODE_LOCK                              0x004
#define   MCFE_COMMAND_UNLOCK_SUB_OPCODE_UNLOCK                            0x005
#define   MCFE_COMMAND_UNLOCK_SUB_OPCODE_INTERRUPT_EVENT                   0x006



#define MCFE_COMMAND_EVENT_OPCODE                                          31:27
#define MCFE_COMMAND_EVENT_OPCODE_End                                         31
#define MCFE_COMMAND_EVENT_OPCODE_Start                                       27
#define MCFE_COMMAND_EVENT_OPCODE_Type                                       U05
#define   MCFE_COMMAND_EVENT_OPCODE_LOAD_STATE                              0x01
#define   MCFE_COMMAND_EVENT_OPCODE_NOP                                     0x03
#define   MCFE_COMMAND_EVENT_OPCODE_SUB_COMMAND                             0x16


#define MCFE_COMMAND_EVENT_SUB_OPCODE                                      25:16
#define MCFE_COMMAND_EVENT_SUB_OPCODE_End                                     25
#define MCFE_COMMAND_EVENT_SUB_OPCODE_Start                                   16
#define MCFE_COMMAND_EVENT_SUB_OPCODE_Type                                   U10
#define   MCFE_COMMAND_EVENT_SUB_OPCODE_SUBMIT_JOB                         0x001
#define   MCFE_COMMAND_EVENT_SUB_OPCODE_SEND_SEMAPHORE                     0x002
#define   MCFE_COMMAND_EVENT_SUB_OPCODE_WAIT_SEMAPHORE                     0x003
#define   MCFE_COMMAND_EVENT_SUB_OPCODE_LOCK                               0x004
#define   MCFE_COMMAND_EVENT_SUB_OPCODE_UNLOCK                             0x005
#define   MCFE_COMMAND_EVENT_SUB_OPCODE_INTERRUPT_EVENT                    0x006


#define MCFE_COMMAND_EVENT_EVENT_ID                                          5:0
#define MCFE_COMMAND_EVENT_EVENT_ID_End                                        5
#define MCFE_COMMAND_EVENT_EVENT_ID_Start                                      0
#define MCFE_COMMAND_EVENT_EVENT_ID_Type                                     U06


#endif


