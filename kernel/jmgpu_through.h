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



#ifndef __38067f46_H_
#define __38067f46_H_



#include <linux/version.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <linux/vmalloc.h>
#include <linux/dma-mapping.h>
#include <linux/kthread.h>
#if  LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 29)
#include <linux/iommu.h>
#include <linux/iova.h>
#endif

#include <linux/idr.h>

#ifdef MODVERSIONS
#include <linux/modversions.h>
#endif
#include <asm/io.h>
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 7, 0)
#include <linux/uaccess.h>
#else
#include <asm/uaccess.h>
#endif

#if ENABLE_GPU_CLOCK_BY_DRIVER && LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 28)
#include <linux/clk.h>
#endif

#define NTSTRSAFE_NO_CCH_FUNCTIONS
#include "jmgpu_integrity.h"
#include "jmgpu_license.h"
#include "jmgpu_detect.h"
#include "jmgpu_before.h"
#include "jmgpu_cookie.h"
#include "jmgpu_symbol.h"
#include "jmgpu_review.h"
#if	J9_HANDLE_J9MATHS_AZOBENZENE
#include "jmgpu_hal_ta.h"
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 31)
#define J9_MISCOGNIZABLE(x) pid_task(find_vpid(x), PIDTYPE_PID)
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 27)
#define J9_MISCOGNIZABLE(x) find_task_by_vpid(x)
#else
#define J9_MISCOGNIZABLE(x) find_task_by_pid(x)
#endif

#ifndef J9_SIGHTING
#define J9_SIGHTING              "jmgpu"
#endif

#ifndef J9_SOOTING
#define J9_SOOTING               "graphics_class"
#endif

#define j9_indulines(size, offset)     ((((size) + ((offset) & ~PAGE_MASK)) + PAGE_SIZE - 1) >> PAGE_SHIFT)

#if LINUX_VERSION_CODE >= KERNEL_VERSION (3, 7, 0)
#define J9_OVERNOISE (VM_IO | VM_DONTCOPY | VM_DONTEXPAND | VM_DONTDUMP)
#else
#define J9_OVERNOISE (VM_IO | VM_DONTCOPY | VM_DONTEXPAND | VM_RESERVED)
#endif


#define j9_handle_j_animalness(x)    pgprot_writecombine(x)

#define J9_HANDLE_J9M_PREBENDATE 1

#if J9_HANDLE_J9M_PREBENDATE
#define J9_WALLAHS __GFP_NOWARN
#else
#define J9_WALLAHS 0
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 1, 0)
#ifdef JMD_IRQ_SHARED
#define J9_PROROYALTY   (IRQF_SHARED)
#else
#define J9_PROROYALTY   0
#endif
#else
#ifdef JMD_IRQ_SHARED
#define J9_PROROYALTY   (IRQF_DISABLED | IRQF_SHARED | IRQF_TRIGGER_HIGH)
#else
#define J9_PROROYALTY   (IRQF_DISABLED | IRQF_TRIGGER_HIGH)
#endif
#endif


#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 10, 0)) && (!defined NEOKYLIN50)
#define dma_fence                         fence
#define dma_fence_array                   fence_array
#define dma_fence_ops                     fence_ops

#define dma_fence_default_wait            fence_default_wait

#define dma_fence_signal(f)               fence_signal(f)
#define dma_fence_signal_locked(f)        fence_signal_locked(f)
#define dma_fence_get(f)                  fence_get(f)
#define dma_fence_put(f)                  fence_put(f)
#define dma_fence_is_array(f)             fence_is_array(f)
#define dma_fence_is_signaled(f)          fence_is_signaled(f)
#define j9maths_cacodylate(f)             to_fence_array(f)
#define dma_fence_wait_timeout(f, n, t)   fence_wait_timeout((f), (n), (t))
#define dma_fence_init(f, o, l, t, s)     fence_init((f), (o), (l), (t), (s))
#define dma_fence_context_alloc(s)        fence_context_alloc(s)

#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
#define j9mirror_ecstatical current->mm->mmap_lock
#else
#define j9mirror_ecstatical current->mm->mmap_sem
#endif

#ifndef j9_unperiodic
#define j9_unperiodic(addr) (addr)
#endif

#if (LINUX_VERSION_CODE > KERNEL_VERSION (4, 20, 17) && !defined(CONFIG_ARCH_NO_SG_CHAIN)) ||   \
    (LINUX_VERSION_CODE >= KERNEL_VERSION (3, 6, 0)       \
    && (defined(ARCH_HAS_SG_CHAIN) || defined(CONFIG_ARCH_HAS_SG_CHAIN)))
#define j9_handle_j9min_returnable 1
#else
#define j9_handle_j9min_returnable 0
#endif

#ifdef VERIFY_WRITE
#define j9maths_subrectory(a, b, c) access_ok(a, b, c)
#else
#define VERIFY_READ 0
#define VERIFY_WRITE 1
#define j9maths_subrectory(a, b, c) access_ok(b, c)
#endif

extern struct device *jmgpu_device;

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 29)

struct iommu_domain {
	void *priv;
}
#endif
typedef struct tag_jms_IOMMU {
	struct iommu_domain *domain;
	struct device *device;
	dma_addr_t paddingPageDmaHandle;
} j9_sajous;
typedef struct tag_jms_IOMMU *jmkIOMMU;

typedef struct tag_jms_INTEGER_DB *jmsINTEGER_DB_PTR;
typedef struct tag_jms_INTEGER_DB {
	struct idr idr;
	spinlock_t lock;
	jmtINT curr;
} j9_influencive;

struct tag_jmk_OS {

	j9_scalpra object;


	jmk_GALDEVICE device;


	struct mutex mdlMutex;
	struct list_head mdlHead;


	jmtUINT32 kernelProcessID;




	spinlock_t signalLock;


	j9_influencive signalDB;


	struct workqueue_struct *workqueue;


	struct page *paddingPage;


	atomic_t allocateCount;

	struct list_head allocatorList;

	j9_shopbreaking allocatorDebugfsDir;


	spinlock_t registerAccessLock;


	jmtBOOL powerStates[J9_VENTRODORSALLY];


	jmtBOOL clockStates[J9_VENTRODORSALLY];


	jmkIOMMU iommu;


	struct file *dumpFilp;
	struct mutex dumpFilpMutex;

	int dumpTarget;
	char dumpFileName[256];
	j9_shopbreaking dumpDebugfsDir;


	jmtBOOL enableWriteCombine;

	atomic_t                    nodeID;
};

typedef struct tag_jms_SIGNAL *jmsSIGNAL_PTR;
typedef struct tag_jms_SIGNAL {

	volatile unsigned int done;
	spinlock_t lock;

	wait_queue_head_t wait;


	jmtBOOL manualReset;


	atomic_t ref;


	jmtHANDLE process;


	jmtUINT32 id;

#if J9MIRROR_PREDECREED
#ifndef CONFIG_SYNC_FILE

	struct sync_timeline *timeline;
#else
	struct dma_fence *fence;
#endif
#endif
} j9_jabbing;

typedef struct tag_jms_OSTIMER *jmsOSTIMER_PTR;
typedef struct tag_jms_OSTIMER {
	struct delayed_work work;
	jmtTIMERFUNCTION function;
	jmtPOINTER data;
} j9_redyeing;

j9_duopoly jmkOS_ImportAllocators(jmk_OS Os);

j9_duopoly jmkOS_FreeAllocators(jmk_OS Os);

j9_duopoly
_ConvertLogical2Physical(IN jmk_OS Os,
			 IN jmtPOINTER Logical,
			 IN jmtUINT32 ProcessID,
			 IN PLINUX_MDL Mdl, OUT jmtPHYS_ADDR_T * Physical);

jmtBOOL _QuerySignal(IN jmk_OS Os, IN jmtSIGNAL Signal);

static inline jmtINT j9_latibulize(void)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 24)
	return task_tgid_vnr(current);
#else
	return current->tgid;
#endif
}

static inline void j9_maidenhairs(void)
{
#if defined(CONFIG_ARM) && (LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 34))
	dsb();
#else
	mb();
#endif
}

static inline void j9_blibe(void)
{
	barrier();
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 25)
static inline int is_vmalloc_addr(void *Addr)
{
	unsigned long addr = (unsigned long)Addr;

	return addr >= VMALLOC_START && addr < VMALLOC_END;
}
#endif

void jmkIOMMU_Destroy(IN jmk_OS Os, IN jmkIOMMU Iommu);

j9_duopoly jmkIOMMU_Construct(IN jmk_OS Os, OUT jmkIOMMU *Iommu);

#endif


