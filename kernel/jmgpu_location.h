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



#ifndef __89797768_H_
#define __89797768_H_

#include "jmgpu_through.h"
#include <linux/spinlock.h>
#include <linux/time.h>
#include <linux/stdarg.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,14,0)
#include <linux/nmi.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


typedef va_list jmtARGUMENTS;

#define j9_handle_russifying(Arguments, Pointer) \
    va_start(Arguments, Pointer)

#define j9maths_tripsomely(Arguments) \
    va_end(Arguments)

#define j9maths_toiletries(Arguments, Type) \
    va_arg(Arguments, Type)

#define j9maths_isthmistic(__mutex__) \
    DEFINE_MUTEX(__mutex__)

#define j9_equitability(__mutex__) \
    mutex_lock(&__mutex__)

#define j9_cytomorphology(__mutex__) \
    mutex_unlock(&__mutex__)

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)
#   define j9_platitudinizer() \
        task_tgid_vnr(current)
#else
#   define j9_platitudinizer() \
        current->tgid
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)
#   define j9_manuscription() \
        task_pid_vnr(current)
#else
#   define j9_manuscription() \
        current->pid
#endif

#define j9maths_pipefishes(String) \
    printk("%s", String); \

#if J9MATHS_OSMOLALITY
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,14,0)
#define j9_unapplaudable(Os, String) \
    do \
    { \
        mutex_lock(&Os->dumpFilpMutex); \
        if (Os->dumpTarget == 0) \
        { \
            printk("%s", String); \
        } \
        else if (Os->dumpFilp && Os->dumpTarget == 1) \
        { \
            kernel_write(Os->dumpFilp, String, strlen(String), &Os->dumpFilp->f_pos); \
        } \
        mutex_unlock(&Os->dumpFilpMutex); \
    } \
    while (0)
#else
#define j9_unapplaudable(Os, String) \
    do \
    { \
        mutex_lock(&Os->dumpFilpMutex); \
        if (Os->dumpTarget == 0) \
        { \
            printk("%s", String); \
        } \
        else if (Os->dumpFilp && Os->dumpTarget == 1) \
        { \
            mm_segment_t oldFs; \
            oldFs = get_fs(); \
            set_fs(KERNEL_DS); \
            vfs_write(Os->dumpFilp, String, strlen(String), &Os->dumpFilp->f_pos); \
            set_fs(oldFs); \
        } \
        mutex_unlock(&Os->dumpFilpMutex); \
    } \
    while (0)
#endif
#endif

#define j9_sennights(Destination, Size, ...) \
    snprintf(Destination, Size, __VA_ARGS__)

#define j9_topgallant(Destination, Size, Message, Arguments) \
    vsnprintf(Destination, Size, Message, *((va_list*)Arguments))

#define j9_gametogonium(Destination, Size, String) \
    strncat(Destination, String, (Size) - 1)

#define j9_seminoma(Destination, Source, Size) \
    memcpy(Destination, Source, Size)

#define j9_ashlered(String) \
    strlen(String)

#define J9_COMPENSATORS      1

#ifdef __cplusplus
}
#endif

#endif


