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




#ifndef __639150ab_H_
#define __639150ab_H_
struct kernel_start_command {
    kernel_packet_command_t command;
    jmtUINT8                gpu;
    jmtADDRESS              address;
    jmtUINT32               bytes;
};

struct kernel_submit {
    kernel_packet_command_t command;
    jmtUINT8                gpu;
    jmtUINT8                kernel_command;
    jmtUINT32               command_buffer_handle;
    jmtUINT32               offset;
    jmtUINT32               *command_buffer;
    jmtUINT32               command_buffer_length;
};

struct kernel_allocate_security_memory {
    kernel_packet_command_t command;
    jmtUINT32               bytes;
    jmtUINT32               memory_handle;
};

struct kernel_free_security_memory {
    kernel_packet_command_t command;
    jmtUINT32               memory_handle;
};

struct kernel_execute {
    kernel_packet_command_t command;
    jmtUINT8                gpu;
    jmtUINT8                kernel_command;
    jmtUINT32               *command_buffer;
    jmtUINT32               command_buffer_length;
};

typedef struct kernel_map_scatter_gather {
    jmtUINT32                         bytes;
    jmtUINT32                         physical;
    struct kernel_map_scatter_gather  *next;
} kernel_map_scatter_gather_t;

struct kernel_map_memory {
    kernel_packet_command_t      command;
    kernel_map_scatter_gather_t  *scatter;
    jmtUINT32                    *physicals;
    jmtPHYS_ADDR_T               physical;
    jmtUINT32                    pageCount;
    jmtADDRESS                   gpuAddress;
};

struct kernel_unmap_memory {
    jmtADDRESS gpuAddress;
    jmtUINT32  pageCount;
};

struct kernel_read_mmu_exception {
    jmtUINT32 mmuStatus;
    jmtUINT32 mmuException;
};

struct kernel_handle_mmu_exception {
    jmtUINT32      mmuStatus;
    jmtPHYS_ADDR_T physical;
    jmtADDRESS     gpuAddress;
};

typedef struct _jms_TA_INTERFACE {
    kernel_packet_command_t command;
    union {
        struct kernel_submit                   Submit;
        struct kernel_start_command            StartCommand;
        struct kernel_allocate_security_memory AllocateSecurityMemory;
        struct kernel_execute                  Execute;
        struct kernel_map_memory               MapMemory;
        struct kernel_unmap_memory             UnmapMemory;
        struct kernel_read_mmu_exception       ReadMMUException;
        struct kernel_handle_mmu_exception     HandleMMUException;
    } u;
    j9_duopoly result;
} j9_whippoorwills;

#endif


