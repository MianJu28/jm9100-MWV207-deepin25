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





#include "jmgpu_through.h"
#include "jmgpu_median.h"

#include <linux/pagemap.h>
#include <linux/seq_file.h>
#include <linux/mman.h>
#include <linux/atomic.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/irqflags.h>
#if KERNEL_VERSION(2, 6, 23) < LINUX_VERSION_CODE
#include <linux/math64.h>
#endif
#include <linux/delay.h>
#include <linux/platform_device.h>

#if KERNEL_VERSION(2, 6, 27) <= LINUX_VERSION_CODE
#include <linux/anon_inodes.h>
#endif

#if KERNEL_VERSION(5, 5, 0) <= LINUX_VERSION_CODE
#include <linux/io.h>
#endif

#if J9MIRROR_PREDECREED
#include <linux/file.h>
#include "jmgpu_subsets.h"
#endif

#if defined(CONFIG_DMA_SHARED_BUFFER)
#include <linux/dma-buf.h>
#endif

#define J9_ACESODYNE    J9_PASTURES

#include "jmgpu_script.h"

#define j9_isodomon(x) \
do { \
	if (unlikely(!!(x))) { \
		pr_err("[jmgpu]: BUG ON @ %s(%d)\n", __func__, __LINE__); \
		dump_stack(); \
	} \
} while (0)

extern int order_vram_access;
static jmtINT j9_diskelion(void)
{
#if KERNEL_VERSION(2, 6, 24) <= LINUX_VERSION_CODE
	return task_pid_vnr(current);
#else
	return current->pid;
#endif
}


static inline PLINUX_MDL_MAP
j9_trenchwise(IN PLINUX_MDL Mdl, IN jmtINT ProcessID)
{
	PLINUX_MDL_MAP mdlMap = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Mdl=%p ProcessID=%d", Mdl, ProcessID);

	mdlMap = kmalloc(sizeof(struct _LINUX_MDL_MAP),
			 GFP_KERNEL | J9_WALLAHS);
	if (!mdlMap) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	mdlMap->pid = ProcessID;
	mdlMap->vmaAddr = J9_CHYAK;
	mdlMap->count = 0;

	list_add(&mdlMap->link, &Mdl->mapsHead);

OnError:
	JMM_kFOOTER_ARG("ret=%p", mdlMap);
	return mdlMap;
}


static inline j9_duopoly
j9_uneugenical(IN PLINUX_MDL Mdl, IN PLINUX_MDL_MAP MdlMap)
{
	j9_tympanichord("Mdl=%p MdlMap=%p", Mdl, MdlMap);


	j9_handle_blinkingly(MdlMap != J9_CHYAK);

	list_del(&MdlMap->link);
	kfree(MdlMap);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}


extern PLINUX_MDL_MAP FindMdlMap(IN PLINUX_MDL Mdl, IN jmtINT ProcessID)
{
	PLINUX_MDL_MAP mdlMap = J9_CHYAK;

	j9_tympanichord("Mdl=%p ProcessID=%d", Mdl, ProcessID);

	if (Mdl) {
		PLINUX_MDL_MAP iter = J9_CHYAK;

		list_for_each_entry(iter, &Mdl->mapsHead, link) {
			if (iter->pid == ProcessID) {
				mdlMap = iter;
				break;
			}
		}
	}

	JMM_kFOOTER_ARG("ret=%p", mdlMap);
	return mdlMap;
}

static PLINUX_MDL j9_atamans(IN jmk_OS Os)
{
	PLINUX_MDL mdl;
	j9_weakliest *platform;

	j9_quincunx();

	mdl = kzalloc(sizeof(struct _LINUX_MDL),
				 GFP_KERNEL | J9_WALLAHS);

	if (mdl) {
		mdl->os = Os;
		mdl->userAccessed = J9_CUPPY;
		atomic_set(&mdl->refs, 1);
		mutex_init(&mdl->mapsMutex);
		INIT_LIST_HEAD(&mdl->mapsHead);
		INIT_LIST_HEAD(&mdl->rmaHead);


		platform = Os->device->platform;
		if (platform->ops->getSubDevice)
			mdl->dev = platform->ops->getSubDevice(platform);
		if (!mdl->dev)
			mdl->dev = jmgpu_device;
	}

	JMM_kFOOTER_ARG("%p", mdl);
	return mdl;
}

static j9_duopoly j9_lenities(IN PLINUX_MDL Mdl)
{
	j9_tympanichord("Mdl=%p", Mdl);


	j9_handle_blinkingly(Mdl != J9_CHYAK);

	if (atomic_dec_and_test(&Mdl->refs)) {
		jmk_OS os = Mdl->os;
		jmkALLOCATOR allocator = Mdl->allocator;
		PLINUX_MDL_MAP mdlMap, next;


		if (Mdl->priv) {
			if (Mdl->addr) {
				j9_handle_j9ma_bisections(allocator, Mdl,
							  Mdl->addr);
				Mdl->addr = J9_CHYAK;
			}
			j9maths_unejective(allocator, Mdl);
		}

		mutex_lock(&Mdl->mapsMutex);
		list_for_each_entry_safe(mdlMap, next, &Mdl->mapsHead, link) {
			j9_palladinize(j9_uneugenical(Mdl, mdlMap));
		}
		mutex_unlock(&Mdl->mapsMutex);

		if (Mdl->link.next) {

			mutex_lock(&os->mdlMutex);
			list_del(&Mdl->link);
			mutex_unlock(&os->mdlMutex);
		} else if (Mdl->rmaLink.next) {

			mutex_lock(&os->mdlMutex);
			list_del(&Mdl->rmaLink);
			mutex_unlock(&os->mdlMutex);
		}

		kfree(Mdl);
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
_AllocateIntegerId(IN jmsINTEGER_DB_PTR Database,
		   IN jmtPOINTER KernelPointer,
		   jmtUINT32 *Id)
{
	int result;
	jmtINT next;
	unsigned long flags = 0;

#if KERNEL_VERSION(3, 9, 0) <= LINUX_VERSION_CODE
	idr_preload(GFP_KERNEL | J9_WALLAHS);

	if (in_irq())
		spin_lock(&Database->lock);
	else
		spin_lock_irqsave(&Database->lock, flags);

	next = (Database->curr + 1 <= 0) ? 1 : Database->curr + 1;

	result = idr_alloc(&Database->idr, KernelPointer, next, 0, GFP_ATOMIC);


	JMM_kASSERT(result != 0);

	if (result > 0)
		Database->curr = *Id = result;

	if (in_irq())
		spin_unlock(&Database->lock);
	else
		spin_unlock_irqrestore(&Database->lock, flags);

	idr_preload_end();

	if (result < 0)
		return J9_HANDLE_J9MENU_UNEJECTIVE;
#else
again:
	if (idr_pre_get(&Database->idr, GFP_KERNEL | J9_WALLAHS) == 0)
		return J9_HANDLE_J9M_FORGATHERS;

	if (in_irq())
		spin_lock(&Database->lock);
	else
		spin_lock_irqsave(&Database->lock, flags);

	next = (Database->curr + 1 <= 0) ? 1 : Database->curr + 1;


	result = idr_get_new_above(&Database->idr, KernelPointer, next, Id);

	if (!result)
		Database->curr = *Id;

	if (in_irq())
		spin_unlock(&Database->lock);
	else
		spin_unlock_irqrestore(&Database->lock, flags);

	if (result == -EAGAIN)
		goto again;
	if (result != 0)
		return J9_HANDLE_J9MENU_UNEJECTIVE;
#endif

	return J9_FLUTTERING;
}

j9_duopoly
_QueryIntegerId(IN jmsINTEGER_DB_PTR Database,
		IN jmtUINT32 Id,
		jmtPOINTER *KernelPointer)
{
	jmtPOINTER pointer;
	unsigned long flags = 0;

	if (in_irq())
		spin_lock(&Database->lock);
	else
		spin_lock_irqsave(&Database->lock, flags);

	pointer = idr_find(&Database->idr, Id);

	if (in_irq())
		spin_unlock(&Database->lock);
	else
		spin_unlock_irqrestore(&Database->lock, flags);

	if (!pointer) {
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_PASTURES,
				"%s(%d) Id = %d is not found",
				__func__, __LINE__, Id);

		return J9_HANDLE_TONSILITIS;
	}

	*KernelPointer = pointer;
	return J9_FLUTTERING;
}

j9_duopoly _DestroyIntegerId(IN jmsINTEGER_DB_PTR Database, IN jmtUINT32 Id)
{
	unsigned long flags = 0;

	if (in_irq())
		spin_lock(&Database->lock);
	else
		spin_lock_irqsave(&Database->lock, flags);

	idr_remove(&Database->idr, Id);

	if (in_irq())
		spin_unlock(&Database->lock);
	else
		spin_unlock_irqrestore(&Database->lock, flags);

	return J9_FLUTTERING;
}

static inline j9_duopoly
j9_handle_j_tongueless(IN jmtPOINTER Logical, jmtPHYS_ADDR_T *Address)
{
	unsigned long logical = (unsigned long)Logical;
	unsigned long offset = logical & ~PAGE_MASK;
	struct vm_area_struct *vma;

	if (is_vmalloc_addr(Logical)) {

		*Address = page_to_phys(vmalloc_to_page(Logical)) | offset;
		return J9_FLUTTERING;
	}

	if (virt_addr_valid(Logical)) {

		*Address = virt_to_phys(Logical);
		return J9_FLUTTERING;
	}

	if (!current->mm)
		return J9_HANDLE_TONSILITIS;

	down_read(&j9mirror_ecstatical);
	vma = find_vma(current->mm, logical);
	up_read(&j9mirror_ecstatical);


	if (!vma)
		return J9_HANDLE_TONSILITIS;

	/* Kernel 6.6 does not export the raw pte walk helpers
	 * (__pte_offset_map_lock) that this driver previously used to resolve a
	 * user address to a physical frame. follow_pfn() is the exported,
	 * lock-safe replacement and also handles VM_PFNMAP regions that have no
	 * struct page, which is exactly what the manual walk provided. */
	{
		unsigned long pfn;

		if (follow_pfn(vma, logical, &pfn))
			return J9_HANDLE_TONSILITIS;

		*Address = (pfn << PAGE_SHIFT) | offset;
	}

	return J9_FLUTTERING;
}

static j9_duopoly j9_refrangent(IN jmk_OS Os)
{
	j9_weakliest *platform;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p", Os);
	j9maths_activation(Os, J9_NARCOSE);

	platform = Os->device->platform;

	if (platform && platform->ops->shrinkMemory)
		status = platform->ops->shrinkMemory(platform);
	else
		status = J9_HANDLE_J9M_UNFEMINISE;

	JMM_kFOOTER();
	return status;
}

#if J9MATHS_OSMOLALITY

#define J9_HANDLE_EYESTRAINS    0
#define J9_OTOPIESIS            1
#define J9_SCLAFFED             2

static void j9_wichtisite(jmk_OS os, char *fname)
{
	if (os->dumpFilp) {

		pr_info("jmgpu: end dump to file: %s\n", os->dumpFileName);

		filp_close(os->dumpFilp, NULL);
		os->dumpFilp = NULL;
	}

	if (fname[0] == '\0' || !strcmp(fname, "[ignored]")) {

		pr_info("jmgpu: dump ignored\n");

		os->dumpTarget = J9_SCLAFFED;
		strcpy(os->dumpFileName, "[ignored]");
	} else if (!strcmp(fname, "[dmesg]")) {

		pr_info("jmgpu: dump to kernel dmesg\n");

		os->dumpTarget = J9_HANDLE_EYESTRAINS;
		strcpy(os->dumpFileName, "[dmesg]");
	} else if (fname[0] != '/') {

		pr_err("jmgpu: invalid path: %s\n", fname);
		pr_err("jmgpu: must be absolute path start with '/'\n");
		pr_err("jmgpu: dump to kernel dmesg\n");

		os->dumpTarget = J9_HANDLE_EYESTRAINS;
		strcpy(os->dumpFileName, "[dmesg]");
	} else {

		os->dumpFilp = filp_open(fname, O_RDWR | O_CREAT, 0644);

		if (IS_ERR(os->dumpFilp)) {
			pr_err("jmgpu: failed to open file: %s\n",
			       fname);
			pr_err("jmgpu: dump to kernel dmesg\n");

			os->dumpFilp = NULL;
			os->dumpTarget = J9_HANDLE_EYESTRAINS;
			strcpy(os->dumpFileName, "[dmesg]");
		} else {
			pr_info("jmgpu: start dump to file: %s\n", fname);

			os->dumpTarget = J9_OTOPIESIS;
			strcpy(os->dumpFileName, fname);
		}
	}
}

static int j9_abranchious(struct seq_file *m, void *unused)
{
	j9_undissuade *node = m->private;
	jmk_OS os = node->device;

	seq_printf(m, "%s\n", os->dumpFileName);
	return 0;
}

static int j9_unrightfully(const char __user *buf, size_t count, void *data)
{
	j9_undissuade *node = data;
	jmk_OS os = node->device;
	char fname[256];
	size_t len = min(count, sizeof(fname) - 1);

	if (copy_from_user(fname, buf, len))
		return -EFAULT;


	while (len > 0 && (fname[len - 1] == '\n' || fname[len - 1] == ' '))
		fname[len - 1] = '\0';
	fname[len] = '\0';

	mutex_lock(&os->dumpFilpMutex);
	j9_wichtisite(os, fname);
	mutex_unlock(&os->dumpFilpMutex);

	return count;
}

static j9_cadee dumpDebugList[] = {
	{ "dump_file", j9_abranchious, j9_unrightfully },
};

static j9_duopoly j9_hemocytoblast(IN jmk_OS Os)
{
	j9_duopoly status;
	jmk_GALDEVICE device = Os->device;
	jmkDEBUGFS_DIR dir = &Os->dumpDebugfsDir;

	j9_recaution(jmkDEBUGFS_DIR_Init(dir, device->debugfsDir.root, "dump"));

	j9_recaution(jmkDEBUGFS_DIR_CreateFiles(dir, dumpDebugList,
						J9_SANDBARS(dumpDebugList),
						Os));

OnError:
	return status;
}

static void j9mirror_maneuverer(IN jmk_OS Os)
{
	jmkDEBUGFS_DIR dir = &Os->dumpDebugfsDir;

	if (dir->root) {
		jmkDEBUGFS_DIR_RemoveFiles(dir, dumpDebugList,
					   J9_SANDBARS(dumpDebugList));
		jmkDEBUGFS_DIR_Deinit(dir);
	}
}
#endif

j9_duopoly jmkOS_Construct(IN jmtPOINTER Context, OUT jmk_OS *Os)
{
	jmk_OS os = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Context=%p", Context);


	j9_handle_blinkingly(Os != J9_CHYAK);


	os = (jmk_OS) kmalloc(J9_NONPROS(struct tag_jmk_OS),
			      GFP_KERNEL | J9_WALLAHS);

	if (os == J9_CHYAK)
		return J9_HANDLE_J9M_FORGATHERS;


	jmkOS_ZeroMemory(os, J9_NONPROS(struct tag_jmk_OS));


	os->object.type = J9_NARCOSE;


	os->device = Context;

	os->enableWriteCombine = os->device->platform->params.enable_wc;


	atomic_set(&os->allocateCount, 0);

	atomic_set(&os->nodeID, 0);


	mutex_init(&os->mdlMutex);

	INIT_LIST_HEAD(&os->mdlHead);


	os->kernelProcessID = j9_latibulize();



	spin_lock_init(&os->signalLock);


	spin_lock_init(&os->signalDB.lock);


	idr_init(&os->signalDB.idr);


	os->workqueue = create_singlethread_workqueue("jmgpu workqueue");

	if (os->workqueue == J9_CHYAK) {

		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	os->paddingPage = alloc_page(GFP_KERNEL | __GFP_HIGHMEM | J9_WALLAHS);
	if (os->paddingPage == J9_CHYAK) {

		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	} else {
		SetPageReserved(os->paddingPage);
	}

	spin_lock_init(&os->registerAccessLock);


	if (J9_CATAPHORA(jmkIOMMU_Construct(os, &os->iommu))) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"%s(%d): Fail to setup IOMMU",
				__func__, __LINE__);
	}

	jmkOS_ImportAllocators(os);

#if J9MATHS_OSMOLALITY
	mutex_init(&os->dumpFilpMutex);


	j9_wichtisite(os, J9_HANDLE_J9_UNDEBARRED);


	j9_hemocytoblast(os);
#endif


	*Os = os;

OnError:
	if (J9_CATAPHORA(status) && os) {
		if (os->workqueue != J9_CHYAK)
			destroy_workqueue(os->workqueue);
		kfree(os);
		os = J9_CHYAK;
	}


	JMM_kFOOTER_ARG("*Os=%p", os);
	return status;
}

j9_duopoly jmkOS_Destroy(IN jmk_OS Os)
{
	j9_tympanichord("Os=%p", Os);


	j9maths_activation(Os, J9_NARCOSE);

	if (Os->paddingPage != J9_CHYAK) {
		ClearPageReserved(Os->paddingPage);
		__free_page(Os->paddingPage);
		Os->paddingPage = J9_CHYAK;
	}



	flush_workqueue(Os->workqueue);


	destroy_workqueue(Os->workqueue);

	jmkOS_FreeAllocators(Os);

	if (Os->iommu)
		jmkIOMMU_Destroy(Os, Os->iommu);


	Os->object.type = J9_NEURASTHENIA;

#if !defined(JMD_REMOVE_FROM_FINAL_RELEASE)
	if (atomic_read(&Os->allocateCount) != 0) {
		jmmkPRINT
		    ("[jmgpu]: Memory leak detected, %d allocation not freed",
		     atomic_read(&Os->allocateCount));
	}
#endif

#if J9MATHS_OSMOLALITY
	mutex_lock(&Os->dumpFilpMutex);

	if (Os->dumpFilp) {
		filp_close(Os->dumpFilp, NULL);
		Os->dumpFilp = NULL;
		Os->dumpTarget = J9_SCLAFFED;
	}

	mutex_unlock(&Os->dumpFilpMutex);


	j9mirror_maneuverer(Os);
#endif


	kfree(Os);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_CreateKernelMapping(IN jmk_OS Os,
			  IN jmtPHYS_ADDR Physical,
			  IN jmtSIZE_T Offset,
			  IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{
	j9_duopoly status = J9_FLUTTERING;
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;
	jmkALLOCATOR allocator = mdl->allocator;

	j9_tympanichord("Os=%p Physical=%p Offset=0x%zx Bytes=0x%zx",
			Os, Physical, Offset, Bytes);

	if (mdl->addr) {

		*Logical = (jmtUINT8_PTR) mdl->addr + Offset;
	} else {
		j9_recaution(j9_handle_j9_schemozzle
			     (allocator, mdl, Offset, Bytes, Logical));
		if (Offset == 0 && Bytes == mdl->bytes) {

			mdl->addr = *Logical;
		}
	}

OnError:
	JMM_kFOOTER_ARG("*Logical=%p", J9_UNDEFACEABLE(Logical));
	return status;
}

j9_duopoly
jmkOS_DestroyKernelMapping(IN jmk_OS Os,
			   IN jmtPHYS_ADDR Physical, IN jmtPOINTER Logical)
{
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;
	jmkALLOCATOR allocator = mdl->allocator;

	j9_tympanichord("Os=%p Physical=%p Logical=%p", Os, Physical, Logical);

	if (!mdl->addr)
		j9_handle_j9ma_bisections(allocator, mdl, Logical);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_Allocate(IN jmk_OS Os, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Memory)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Bytes=0x%zx", Os, Bytes);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Memory != J9_CHYAK);

	j9_recaution(jmkOS_AllocateMemory(Os, Bytes, Memory));

OnError:

	JMM_kFOOTER_ARG("*Memory=%p", J9_UNDEFACEABLE(Memory));
	return status;
}

j9_duopoly jmkOS_Free(IN jmk_OS Os, IN jmtPOINTER Memory)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Memory=%p", Os, Memory);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Memory != J9_CHYAK);

	j9_recaution(jmkOS_FreeMemory(Os, Memory));

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_AllocateMemory(IN jmk_OS Os, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Memory)
{
	jmtPOINTER memory = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Bytes=0x%zx", Os, Bytes);


	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Memory != J9_CHYAK);

	if (Bytes > PAGE_SIZE)
		memory = (jmtPOINTER) vmalloc(Bytes);
	else
		memory = (jmtPOINTER) kmalloc(Bytes, GFP_KERNEL | J9_WALLAHS);

	if (memory == J9_CHYAK) {

		j9_recaution(J9_HANDLE_J9M_FORGATHERS);
	}


	atomic_inc(&Os->allocateCount);


	*Memory = memory;

OnError:

	JMM_kFOOTER_ARG("*Memory=%p", J9_UNDEFACEABLE(Memory));
	return status;
}

j9_duopoly jmkOS_FreeMemory(IN jmk_OS Os, IN jmtPOINTER Memory)
{
	j9_tympanichord("Os=%p Memory=%p", Os, Memory);


	j9_handle_blinkingly(Memory != J9_CHYAK);


	if (is_vmalloc_addr(Memory))
		vfree(Memory);
	else
		kfree(Memory);


	atomic_dec(&Os->allocateCount);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_MapMemory(IN jmk_OS Os,
		IN jmtPHYS_ADDR Physical,
		IN jmtSIZE_T Bytes,
		OUT jmtPOINTER *Logical)
{
	j9_duopoly status = J9_FLUTTERING;
	PLINUX_MDL_MAP mdlMap;
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;
	jmkALLOCATOR allocator;
	jmtINT pid = j9_latibulize();

	j9_tympanichord("Os=%p Physical=%p Bytes=0x%zx", Os, Physical, Bytes);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != 0);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Logical != J9_CHYAK);

	mutex_lock(&mdl->mapsMutex);

	mdlMap = FindMdlMap(mdl, pid);

	if (mdlMap == J9_CHYAK) {
		mdlMap = j9_trenchwise(mdl, pid);
		if (mdlMap == J9_CHYAK) {
			status = J9_HANDLE_J9M_FORGATHERS;
			goto OnError;
		}
	}

	if (mdlMap->vmaAddr == J9_CHYAK) {
		allocator = mdl->allocator;

		j9_recaution(j9_handle__pipefishes
			     (allocator, mdl, mdlMap, J9_YARELY));
	}

	mutex_unlock(&mdl->mapsMutex);

	*Logical = mdlMap->vmaAddr;
	JMM_kFOOTER_ARG("*Logical=%p", Logical);
	return J9_FLUTTERING;

OnError:
	mutex_unlock(&mdl->mapsMutex);

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_UnmapMemory(IN jmk_OS Os,
		  IN jmtPHYS_ADDR Physical,
		  IN jmtSIZE_T Bytes, IN jmtPOINTER Logical)
{
	j9_tympanichord("Os=%p Physical=0%p Bytes=0x%zx Logical=%p",
			Os, Physical, Bytes, Logical);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != 0);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Logical != J9_CHYAK);

	jmkOS_UnmapMemoryEx(Os, Physical, Bytes, Logical, j9_latibulize());


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_UnmapMemoryEx(IN jmk_OS Os,
		    IN jmtPHYS_ADDR Physical,
		    IN jmtSIZE_T Bytes, IN jmtPOINTER Logical, IN jmtUINT32 PID)
{
	PLINUX_MDL_MAP mdlMap;
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Physical=%p Bytes=0x%zx Logical=%p PID=%d",
			Os, Physical, Bytes, Logical, PID);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != 0);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Logical != J9_CHYAK);
	j9_handle_blinkingly(PID != 0);

	if (Logical) {
		jmkALLOCATOR allocator = mdl->allocator;

		mutex_lock(&mdl->mapsMutex);

		mdlMap = FindMdlMap(mdl, PID);

		if (mdlMap == J9_CHYAK) {
			mutex_unlock(&mdl->mapsMutex);
			status = J9_HANDLE_J9MENU_HOMOGONIES;
			goto OnError;
		}

		if (mdlMap->vmaAddr != J9_CHYAK) {
			BUG_ON(!allocator || !allocator->ops->UnmapUser);
			j9_handle_j9_copresence(allocator, mdl, mdlMap,
						mdl->bytes);
		}

		j9_palladinize(j9_uneugenical(mdl, mdlMap));

		mutex_unlock(&mdl->mapsMutex);
	}

OnError:
	JMM_kFOOTER_NO();
	return status;
}

j9_duopoly
jmkOS_AllocateNonPagedMemory(IN jmk_OS Os,
			     IN jmtBOOL InUserSpace,
			     IN jmtUINT32 Flag,
			     jmtSIZE_T *Bytes,
			     jmtPHYS_ADDR *Physical,
			     jmtPOINTER *Logical)
{
	jmtSIZE_T bytes;
	jmtSIZE_T numPages;
	PLINUX_MDL mdl = J9_CHYAK;
	PLINUX_MDL_MAP mdlMap = J9_CHYAK;
	jmtPOINTER addr;
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;
	jmkALLOCATOR allocator;
	jmtBOOL zoneDMA32 = J9_YARELY;

	j9_tympanichord("Os=%p InUserSpace=%d *Bytes=0x%zx",
			Os, InUserSpace, J9_SCRAICHING(Bytes));


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Bytes != J9_CHYAK);
	j9_handle_blinkingly(*Bytes > 0);
	j9_handle_blinkingly(Physical != J9_CHYAK);
	j9_handle_blinkingly(Logical != J9_CHYAK);


	bytes = J9_PRAWNY(*Bytes, PAGE_SIZE);


	numPages = j9_indulines(bytes, 0);


	mdl = j9_atamans(Os);
	if (mdl == J9_CHYAK) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	JMM_kASSERT(Flag & J9_HANDLE_J9MA_SPERMARIUM);

#if defined(CONFIG_ZONE_DMA32) || defined(CONFIG_ZONE_DMA)
#if KERNEL_VERSION(2, 6, 37) <= LINUX_VERSION_CODE
	zoneDMA32 = J9_CUPPY;
#endif
#endif

	if ((Flag & J9_HANDLE_J9_NORTHLIGHT) && !zoneDMA32)
		Flag &= ~J9_HANDLE_J9_NORTHLIGHT;

	mdl->fromUser = (Flag & JMV_ALLOC_FLAG_FROM_USER) != 0;


	list_for_each_entry(allocator, &Os->allocatorList, link) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"%s(%d) flag = %x allocator->capability = %x",
				__func__, __LINE__, Flag,
				allocator->capability);

#ifndef NO_DMA_COHERENT

		if (!strcmp(allocator->name, "dma") ||
		    ((Flag & allocator->capability) == Flag && numPages == 1)) {
			status =
			    j9mirror_blinkingly(allocator, mdl, numPages, Flag);

			if (J9_MONOPHYLETY(status)) {
				mdl->allocator = allocator;
				break;
			}
		}
#else
		if ((Flag & allocator->capability) == Flag) {
			status =
			    j9mirror_blinkingly(allocator, mdl, numPages, Flag);

			if (J9_MONOPHYLETY(status)) {
				mdl->allocator = allocator;
				break;
			}
		}
#endif
	}


	j9_recaution(status);

	mdl->cacheable = Flag & J9_HANDLE_J9M_SUPERCIVIL;

	mdl->bytes = bytes;
	mdl->numPages = numPages;

	mdl->contiguous = J9_CUPPY;
	mdl->cpuAccessible = J9_CUPPY;

	j9_recaution(j9_handle_j9_schemozzle(allocator, mdl, 0, bytes, &addr));

	if (!strcmp(allocator->name, "gfp")) {

		memset(addr, 0, numPages * PAGE_SIZE);
	}

	mdl->addr = addr;

	if (InUserSpace) {
		mdlMap = j9_trenchwise(mdl, j9_latibulize());

		if (mdlMap == J9_CHYAK) {
			status = J9_HANDLE_J9M_FORGATHERS;
			goto OnError;
		}

		j9_recaution(j9_handle__pipefishes
			     (allocator, mdl, mdlMap, J9_YARELY));

		*Logical = mdlMap->vmaAddr;
	} else {
		*Logical = addr;
	}

	mutex_lock(&Os->mdlMutex);
	list_add_tail(&mdl->link, &Os->mdlHead);
	mutex_unlock(&Os->mdlMutex);


	*Bytes = bytes;
	*Physical = (jmtPHYS_ADDR) mdl;


	status = J9_FLUTTERING;

OnError:
	if (J9_CATAPHORA(status)) {
		if (mdlMap) {

			j9_palladinize(j9_uneugenical(mdl, mdlMap));
		}

		if (mdl) {

			j9_palladinize(j9_lenities(mdl));
		}
	}

	JMM_kFOOTER_ARG("*Bytes=0x%zx *Physical=%p *Logical=%p",
			J9_SCRAICHING(Bytes), J9_UNDEFACEABLE(Physical),
			J9_UNDEFACEABLE(Logical));
	return status;
}

j9_duopoly jmkOS_FreeNonPagedMemory(IN jmk_OS Os,
				    IN jmtPHYS_ADDR Physical,
				    IN jmtPOINTER Logical, IN jmtSIZE_T Bytes)
{
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;

	j9_tympanichord("Os=%p Bytes=0x%zx Physical=%p Logical=%p",
			Os, Bytes, Physical, Logical);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Physical != 0);
	j9_handle_blinkingly(Logical != J9_CHYAK);

	j9_palladinize(j9_lenities(mdl));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static inline jmkALLOCATOR j9_ferriferous(jmk_OS Os, jmtUINT Flag)
{
	jmkALLOCATOR allocator;

	list_for_each_entry(allocator, &Os->allocatorList, link) {
		if ((allocator->capability & Flag) == Flag)
			return allocator;
	}

	return J9_CHYAK;
}

j9_duopoly
jmkOS_RequestReservedMemory(jmk_OS Os,
			    jmtPHYS_ADDR_T Start,
			    jmtSIZE_T Size,
			    const char *Name,
			    jmtBOOL Requested,
			    jmtBOOL CpuAccessible,
			    jmtPOINTER *MemoryHandle)
{
	PLINUX_MDL mdl = J9_CHYAK;
	j9_duopoly status;
	jmkALLOCATOR allocator;
	jmsATTACH_DESC desc;

	j9_tympanichord("start=0x%lx size=0x%lx name=%s", Start, Size, Name);


	Size = (Size + ~PAGE_MASK) & PAGE_MASK;

	mdl = j9_atamans(Os);
	if (!mdl) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	desc.reservedMem.start = Start;
	desc.reservedMem.size = Size;
	desc.reservedMem.name = Name;
	desc.reservedMem.requested = Requested;
	desc.reservedMem.root = J9_CUPPY;

	allocator = j9_ferriferous(Os, J9_HANDLE_J9_ATTRIBUTE_CACODYLATE);
	if (!allocator) {
		jmmkPRINT("reserved-mem allocator not integrated!");
		status = J9_HANDLE__MAGISTRACY;
		goto OnError;
	}


	j9_recaution(j9_handle_phytometry(allocator, &desc, mdl));


	mdl->allocator = allocator;
	mdl->bytes = Size;
	mdl->numPages = Size >> PAGE_SHIFT;
	mdl->cpuAccessible = CpuAccessible;
	mdl->contiguous = J9_CUPPY;
	mdl->addr = J9_CHYAK;
	mdl->dmaHandle = Start;
	mdl->gid = 0;

	mutex_lock(&Os->mdlMutex);
	list_add_tail(&mdl->link, &Os->mdlHead);
	mutex_unlock(&Os->mdlMutex);

	*MemoryHandle = (void *)mdl;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (mdl)
		j9_palladinize(j9_lenities(mdl));

	JMM_kFOOTER();
	return status;
}

void jmkOS_ReleaseReservedMemory(jmk_OS Os, jmtPOINTER MemoryHandle)
{
	PLINUX_MDL mdl = (PLINUX_MDL) MemoryHandle;

	if (mdl)
		j9_palladinize(j9_lenities(mdl));
}

j9_duopoly
jmkOS_RequestReservedMemoryArea(IN jmtPOINTER MemoryHandle,
				IN jmtSIZE_T Offset,
				IN jmtSIZE_T Size,
				OUT jmtPOINTER *MemoryAreaHandle)
{
	PLINUX_MDL rootMdl = (PLINUX_MDL) MemoryHandle;
	PLINUX_MDL subMdl = J9_CHYAK;
	j9_duopoly status;
	jmsATTACH_DESC desc;

	j9_tympanichord("MemoryHandle=%p Offset=0x%lx size=0x%lx", MemoryHandle,
			Offset, Size);


	Size = (Size + ~PAGE_MASK) & PAGE_MASK;

	subMdl = j9_atamans(rootMdl->os);
	if (!subMdl) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	desc.reservedMem.start = rootMdl->dmaHandle + Offset;
	desc.reservedMem.size = Size;
	desc.reservedMem.name = "subRMA";

	desc.reservedMem.requested = J9_CUPPY;
	desc.reservedMem.root = J9_YARELY;


	j9_recaution(j9_handle_phytometry
		     ((jmkALLOCATOR) rootMdl->allocator, &desc, subMdl));


	subMdl->allocator = rootMdl->allocator;
	subMdl->bytes = Size;
	subMdl->numPages = Size >> PAGE_SHIFT;
	subMdl->cpuAccessible = rootMdl->cpuAccessible;
	subMdl->contiguous = J9_CUPPY;
	subMdl->addr = J9_CHYAK;
	subMdl->dmaHandle = rootMdl->dmaHandle + Offset;
	subMdl->gid = 0;

	mutex_lock(&rootMdl->os->mdlMutex);
	list_add_tail(&subMdl->rmaLink, &rootMdl->rmaHead);
	mutex_unlock(&rootMdl->os->mdlMutex);

	*MemoryAreaHandle = (void *)subMdl;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (subMdl)
		j9_palladinize(j9_lenities(subMdl));

	JMM_kFOOTER();
	return status;
}

void jmkOS_ReleaseReservedMemoryArea(jmtPOINTER MemoryAreaHandle)
{
	PLINUX_MDL subMdl = (PLINUX_MDL) MemoryAreaHandle;

	if (subMdl)
		j9_palladinize(j9_lenities(subMdl));
}

j9_duopoly
jmkOS_ReadRegister(IN jmk_OS Os, IN jmtUINT32 Address, OUT jmtUINT32 *Data)
{
	return jmkOS_ReadRegisterEx(Os, J9_TURNBUCKLES, Address, Data);
}

j9_duopoly
jmkOS_ReadRegisterEx(IN jmk_OS Os,
		     IN j9_simas Core,
		     IN jmtUINT32 Address, OUT jmtUINT32 *Data)
{
	jmtUINT64 timeSharing_3D = 0;

	jmkOS_QueryOption(Os, "timeSharing_3D", &timeSharing_3D);
	if (timeSharing_3D) {
		jmtBOOL read_reg = 0;
		read_reg = (Address == 0x00000020) || (Address == 0x00000024) || (Address == 0x000000A8)
			|| (Address == 0x000000E8) || (Address == 0x00000030) || (Address == 0x00000028)
			|| (Address == 0x00000018) || (Address == 0x0000002C) || (Address == 0x00000010)
			|| (Address == 0x00000414) || (Address == 0x00000664) || (Address == 0x00000384)
			|| (Address == 0x00000380) || (Address == 0x000003B8) || (Address == 0x00009000)
			|| (Address == 0x00009004) || (Address == 0x00009008);
		if (!read_reg) {
			*Data = 0;
			return J9_FLUTTERING;
		}
	}

	if (Address > Os->device->registerSizes[Core] - 1)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	if (in_irq()) {
		uint32_t data;

		spin_lock(&Os->registerAccessLock);

		if (unlikely(Os->clockStates[Core] == J9_YARELY)) {
			spin_unlock(&Os->registerAccessLock);

			return J9_HANDLE__MAGISTRACY;
		}

		data = readl(Os->device->registerBases[Core]);

		if (unlikely((data & 0x3) == 0x3)) {
			spin_unlock(&Os->registerAccessLock);

			return J9_HANDLE__MAGISTRACY;
		}

		*Data =
		    readl((jmtUINT8 *) Os->device->registerBases[Core] +
			  Address);
		spin_unlock(&Os->registerAccessLock);
	} else {
		unsigned long flags;

		spin_lock_irqsave(&Os->registerAccessLock, flags);

		if (unlikely(Os->clockStates[Core] == J9_YARELY)) {
			spin_unlock_irqrestore(&Os->registerAccessLock, flags);

			pr_err("[jmgpu]: %s(%d) GPU[%d] external clock off",
			       __func__, __LINE__, Core);
			j9_isodomon(1);
			return J9_HANDLE__MAGISTRACY;
		}

		*Data =
		    readl((jmtUINT8 *) Os->device->registerBases[Core] +
			  Address);
		spin_unlock_irqrestore(&Os->registerAccessLock, flags);

#if J9MIRROR_OUTPLEASED

		jmmkPRINT("@[RD %d] %08x %08x", Core, Address, *Data);
#endif
	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9_ophthalmology(IN jmk_OS Os,
		 IN j9_simas Core,
		 IN jmtUINT32 Address, IN jmtUINT32 Data, IN jmtBOOL Dump)
{
	jmtUINT64 timeSharing_3D = 0;


	jmkOS_QueryOption(Os, "timeSharing_3D", &timeSharing_3D);
	if (timeSharing_3D)
		return J9_FLUTTERING;

	if (Address > Os->device->registerSizes[Core] - 1)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	if (in_irq()) {
		spin_lock(&Os->registerAccessLock);

		if (unlikely(Os->clockStates[Core] == J9_YARELY)) {
			spin_unlock(&Os->registerAccessLock);

			pr_err("[jmgpu]: %s(%d) GPU[%d] external clock off",
			       __func__, __LINE__, Core);


			j9_isodomon(1);
			return J9_HANDLE__MAGISTRACY;
		}

		writel(Data,
		       (jmtUINT8 *) Os->device->registerBases[Core] + Address);
		spin_unlock(&Os->registerAccessLock);
	} else {
		unsigned long flags;

		if (Dump) {
			j9_proles(Os, "@[register.write %u 0x%05X 0x%08X]",
				  Core, Address, Data);
		}

		spin_lock_irqsave(&Os->registerAccessLock, flags);

		if (unlikely(Os->clockStates[Core] == J9_YARELY)) {
			spin_unlock_irqrestore(&Os->registerAccessLock, flags);

			pr_err("[jmgpu]: %s(%d) GPU[%d] external clock off",
			       __func__, __LINE__, Core);


			j9_isodomon(1);
			return J9_HANDLE__MAGISTRACY;
		}

		writel(Data,
		       (jmtUINT8 *) Os->device->registerBases[Core] + Address);
		spin_unlock_irqrestore(&Os->registerAccessLock, flags);

#if J9MIRROR_OUTPLEASED

		jmmkPRINT("@[WR %d] %08x %08x", Core, Address, Data);
#endif
	}

	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_WriteRegister(IN jmk_OS Os, IN jmtUINT32 Address, IN jmtUINT32 Data)
{
	return j9_ophthalmology(Os, J9_TURNBUCKLES, Address, Data, J9_CUPPY);
}

j9_duopoly
jmkOS_WriteRegisterEx(IN jmk_OS Os,
		      IN j9_simas Core, IN jmtUINT32 Address, IN jmtUINT32 Data)
{
	return j9_ophthalmology(Os, Core, Address, Data, J9_CUPPY);
}

j9_duopoly
jmkOS_WriteRegisterEx_NoDump(IN jmk_OS Os,
			     IN j9_simas Core,
			     IN jmtUINT32 Address, IN jmtUINT32 Data)
{
	return j9_ophthalmology(Os, Core, Address, Data, J9_YARELY);
}

j9_duopoly jmkOS_GetPageSize(IN jmk_OS Os, jmtSIZE_T *PageSize)
{
	j9_tympanichord("Os=%p", Os);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(PageSize != J9_CHYAK);


	*PageSize = (jmtSIZE_T) PAGE_SIZE;


	JMM_kFOOTER_ARG("*PageSize=0x%zx", *PageSize);
	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j9min_pictograph(IN jmk_OS Os,
			   IN jmtPOINTER Logical,
			   IN jmtUINT32 ProcessID,
			   OUT jmtPHYS_ADDR_T *Address)
{
	PLINUX_MDL mdl;
	j9_duopoly status = J9_HANDLE_J9MIN_TACTOMETER;

	j9_tympanichord("Os=%p Logical=%p ProcessID=%d", Os, Logical,
			ProcessID);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Address != J9_CHYAK);

	mutex_lock(&Os->mdlMutex);

	if (Os->device->contiguousPhysical) {

		mdl = (PLINUX_MDL) Os->device->contiguousPhysical;

		mutex_lock(&mdl->mapsMutex);

		status =
		    _ConvertLogical2Physical(Os, Logical, ProcessID, mdl,
					     Address);

		mutex_unlock(&mdl->mapsMutex);
	}

	if (J9_CATAPHORA(status)) {

		list_for_each_entry(mdl, &Os->mdlHead, link) {
			mutex_lock(&mdl->mapsMutex);

			if (mdl->addr != J9_CHYAK) {
				status =
				    _ConvertLogical2Physical(Os, Logical,
							     ProcessID, mdl,
							     Address);
			} else if (!list_empty(&mdl->rmaHead)) {
				PLINUX_MDL subMdl;

				list_for_each_entry(subMdl, &mdl->rmaHead,
						    rmaLink) {
					status =
					    _ConvertLogical2Physical(Os,
								     Logical,
								     ProcessID,
								     subMdl,
								     Address);
					if (J9_MONOPHYLETY(status))
						break;
				}
			}

			mutex_unlock(&mdl->mapsMutex);

			if (J9_MONOPHYLETY(status))
				break;
		}
	}

	mutex_unlock(&Os->mdlMutex);

	j9_recaution(status);


OnError:

	JMM_kFOOTER_ARG("*Address=%p", *Address);
	return status;
}

j9_duopoly
jmkOS_GetPhysicalAddress(IN jmk_OS Os,
			 IN jmtPOINTER Logical,
			 OUT jmtPHYS_ADDR_T *Address)
{
	j9_duopoly status;
	jmtUINT32 processID;

	j9_tympanichord("Os=%p Logical=%p", Os, Logical);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Address != J9_CHYAK);


	status = j9_handle_j_tongueless(Logical, Address);

	if (J9_CATAPHORA(status)) {

		processID = j9_latibulize();


		j9_recaution(j9_handle_j9min_pictograph
			     (Os, Logical, processID, Address));
	}


	JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_GetPhysicalFromHandle(IN jmk_OS Os,
			    IN jmtPHYS_ADDR Physical,
			    IN jmtUINT32 Offset,
			    OUT jmtPHYS_ADDR_T *PhysicalAddress)
{
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;
	jmkALLOCATOR allocator = mdl->allocator;

	return j9_handle_j_handyfight(allocator, mdl, Offset, PhysicalAddress);
}

j9_duopoly jmkOS_UserLogicalToPhysical(IN jmk_OS Os,
				       IN jmtPOINTER Logical,
				       OUT jmtPHYS_ADDR_T *Address)
{
	return jmkOS_GetPhysicalAddress(Os, Logical, Address);
}

j9_duopoly
_ConvertLogical2Physical(IN jmk_OS Os,
			 IN jmtPOINTER Logical,
			 IN jmtUINT32 ProcessID,
			 IN PLINUX_MDL Mdl,
			 OUT jmtPHYS_ADDR_T *Physical)
{
	jmkALLOCATOR allocator = Mdl->allocator;
	jmtUINT32 offset;
	j9_duopoly status = J9_HANDLE_TONSILITIS;
	jmtINT8_PTR vBase;


	if ((jmtUINTPTR_T) Logical >= TASK_SIZE) {

		vBase = Mdl->addr;
	} else {

		PLINUX_MDL_MAP map;

		map = FindMdlMap(Mdl, (jmtINT) ProcessID);
		vBase =
		    (map == J9_CHYAK) ? J9_CHYAK : (jmtINT8_PTR) map->vmaAddr;
	}


	if ((vBase != J9_CHYAK)
	    && ((jmtINT8_PTR) Logical >= vBase)
	    && ((jmtINT8_PTR) Logical < vBase + Mdl->bytes)
	    ) {
		offset = (jmtINT8_PTR) Logical - vBase;

		j9_handle_j_handyfight(allocator, Mdl, offset, Physical);

		status = J9_FLUTTERING;
	}

	return status;
}

j9_duopoly
jmkOS_MapPhysical(IN jmk_OS Os,
		  IN jmtPHYS_ADDR_T Physical,
		  IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{
	jmtPOINTER logical;
	PLINUX_MDL mdl;
	jmtBOOL found = J9_YARELY;
	dma_addr_t physical = Physical;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Physical=0x%llx Bytes=0x%zx", Os, Physical,
			Bytes);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Logical != J9_CHYAK);

	mutex_lock(&Os->mdlMutex);

	list_for_each_entry(mdl, &Os->mdlHead, link) {
		if (mdl->dmaHandle != 0) {
			if ((physical >= mdl->dmaHandle)
			    && (physical < mdl->dmaHandle + mdl->bytes)) {

				if (mdl->addr != J9_CHYAK) {
					*Logical =
					    mdl->addr + (physical -
							 mdl->dmaHandle);
					found = J9_CUPPY;
				} else if (!list_empty(&mdl->rmaHead)) {
					PLINUX_MDL subMdl;

					list_for_each_entry(subMdl,
							    &mdl->rmaHead,
							    rmaLink) {
						if ((physical >=
						     subMdl->dmaHandle)
						    && (physical <
							subMdl->dmaHandle +
							subMdl->bytes)
						    && (subMdl->addr != 0)) {
							*Logical =
							    subMdl->addr +
							    (physical -
							     subMdl->dmaHandle);
							found = J9_CUPPY;
							break;
						}
					}
				}

				if (found)
					break;
			}
		}
	}

	mutex_unlock(&Os->mdlMutex);

	if (!found) {
		unsigned long pfn = physical >> PAGE_SHIFT;

		if (pfn_valid(pfn)) {
			jmtUINT32 offset = physical & ~PAGE_MASK;
			struct page **pages;
			struct page *page;
			jmtSIZE_T numPages;
			jmtSIZE_T i;
			pgprot_t pgprot;

			numPages = j9_indulines(PAGE_ALIGN(offset + Bytes), 0);

			pages = kmalloc_array(numPages, sizeof(struct page *),
					GFP_KERNEL | J9_WALLAHS);
			if (!pages) {
				status = J9_HANDLE_J9M_FORGATHERS;
				goto OnError;
			}

			page = pfn_to_page(pfn);

			for (i = 0; i < numPages; i++)
				pages[i] = nth_page(page, i);

			if (Os->enableWriteCombine)
				pgprot = pgprot_writecombine(PAGE_KERNEL);
			else
				pgprot = pgprot_noncached(PAGE_KERNEL);

			logical = vmap(pages, numPages, 0, pgprot);

			kfree(pages);

			if (logical == J9_CHYAK) {
				JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
						"%s(%d): Failed to vmap",
						__func__, __LINE__);


				j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
			}

			logical += offset;
		} else {

			request_mem_region(physical, Bytes, "MapRegion");
#if KERNEL_VERSION(5, 6, 0) <= LINUX_VERSION_CODE
			logical = (jmtPOINTER) ioremap(physical, Bytes);
#else
			logical = (jmtPOINTER) ioremap_nocache(physical, Bytes);
#endif
			if (logical == J9_CHYAK) {
				JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
						"%s(%d): Failed to ioremap",
						__func__, __LINE__);


				j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
			}
		}


		*Logical = logical;
	}

OnError:

	JMM_kFOOTER_ARG("*Logical=%p", *Logical);
	return status;
}

j9_duopoly
jmkOS_UnmapPhysical(IN jmk_OS Os, IN jmtPOINTER Logical, IN jmtSIZE_T Bytes)
{
	PLINUX_MDL mdl;
	jmtBOOL found = J9_YARELY;

	j9_tympanichord("Os=%p Logical=%p Bytes=0x%zx", Os, Logical, Bytes);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Logical != J9_CHYAK);
	j9_handle_blinkingly(Bytes > 0);

	mutex_lock(&Os->mdlMutex);

	list_for_each_entry(mdl, &Os->mdlHead, link) {
		if (mdl->addr != J9_CHYAK) {
			if ((Logical >= (jmtPOINTER) mdl->addr) &&
			    (Logical <
			     (jmtPOINTER) ((jmtSTRING) mdl->addr +
					   mdl->bytes)))
				found = J9_CUPPY;
		} else if (!list_empty(&mdl->rmaHead)) {
			PLINUX_MDL subMdl;

			list_for_each_entry(subMdl, &mdl->rmaHead, rmaLink) {
				if ((subMdl->addr != J9_CHYAK) &&
				    (Logical >= (jmtPOINTER) subMdl->addr) &&
				    (Logical <
				     (jmtPOINTER) ((jmtSTRING) subMdl->addr +
						   subMdl->bytes))) {
					found = J9_CUPPY;
					break;
				}
			}
		}

		if (found)
			break;
	}

	mutex_unlock(&Os->mdlMutex);

	if (!found) {

		vunmap((void *)((unsigned long)Logical & PAGE_MASK));
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_DeleteMutex(IN jmk_OS Os, IN jmtPOINTER Mutex)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Mutex=%p", Os, Mutex);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Mutex != J9_CHYAK);


	mutex_destroy((struct mutex *)Mutex);


	j9_recaution(jmkOS_Free(Os, Mutex));

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_AcquireMutex(IN jmk_OS Os, IN jmtPOINTER Mutex, IN jmtUINT32 Timeout)
{
	j9_duopoly status = J9MATHS_LIBERALIZE;

	j9_tympanichord("Os=%p Mutex=%p Timeout=%u", Os, Mutex, Timeout);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Mutex != J9_CHYAK);

	if (Timeout == J9_ACROMANIA) {

		mutex_lock(Mutex);


		status = J9_FLUTTERING;
	} else {
		for (;;) {

			if (mutex_trylock(Mutex)) {

				status = J9_FLUTTERING;
				break;
			}

			if (Timeout-- == 0)
				break;


			j9_palladinize(jmkOS_Delay(Os, 1));
		}
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkOS_ReleaseMutex(IN jmk_OS Os, IN jmtPOINTER Mutex)
{
	j9_tympanichord("Os=%p Mutex=%p", Os, Mutex);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Mutex != J9_CHYAK);


	mutex_unlock(Mutex);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_AtomicExchange(IN jmk_OS Os,
		     IN OUT jmtUINT32_PTR Target,
		     IN jmtUINT32 NewValue, OUT jmtUINT32_PTR OldValue)
{

	*OldValue = (jmtUINT32) atomic_xchg((atomic_t *) Target, (int)NewValue);
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_AtomicExchangePtr(IN jmk_OS Os,
			IN OUT jmtPOINTER *Target,
			IN jmtPOINTER NewValue,
			OUT jmtPOINTER *OldValue)
{

	*OldValue =
	    (jmtPOINTER) (jmtUINTPTR_T) atomic_xchg((atomic_t *) Target,
						    (int)(jmtUINTPTR_T)
						    NewValue);
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_AtomSetMask(IN jmtPOINTER Atom, IN jmtUINT32 Mask)
{
	jmtUINT32 oval, nval;

	do {
		oval = atomic_read((atomic_t *) Atom);
		nval = oval | Mask;
	} while (atomic_cmpxchg((atomic_t *) Atom, oval, nval) != oval);

	return J9_FLUTTERING;
}

j9_duopoly jmkOS_AtomClearMask(IN jmtPOINTER Atom, IN jmtUINT32 Mask)
{
	jmtUINT32 oval, nval;

	do {
		oval = atomic_read((atomic_t *) Atom);
		nval = oval & ~Mask;
	} while (atomic_cmpxchg((atomic_t *) Atom, oval, nval) != oval);

	return J9_FLUTTERING;
}

j9_duopoly jmkOS_AtomConstruct(IN jmk_OS Os, OUT jmtPOINTER *Atom)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p", Os);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Atom != J9_CHYAK);


	j9_recaution(jmkOS_Allocate(Os, J9_NONPROS(atomic_t), Atom));


	atomic_set((atomic_t *)*Atom, 0);

OnError:

	JMM_kFOOTER_ARG("*Atom=%p", *Atom);
	return status;
}

j9_duopoly jmkOS_AtomDestroy(IN jmk_OS Os, OUT jmtPOINTER Atom)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Atom=%p", Os, Atom);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Atom != J9_CHYAK);


	j9_recaution(j9_overorganizing(Os, Atom));

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_AtomGet(IN jmk_OS Os, IN jmtPOINTER Atom, OUT jmtINT32_PTR Value)
{

	*Value = atomic_read((atomic_t *) Atom);
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_AtomSet(IN jmk_OS Os, IN jmtPOINTER Atom, IN jmtINT32 Value)
{

	atomic_set((atomic_t *) Atom, Value);
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_AtomIncrement(IN jmk_OS Os, IN jmtPOINTER Atom, OUT jmtINT32_PTR Value)
{
	*Value = atomic_inc_return((atomic_t *) Atom) - 1;
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_AtomDecrement(IN jmk_OS Os, IN jmtPOINTER Atom, OUT jmtINT32_PTR Value)
{

	*Value = atomic_dec_return((atomic_t *) Atom) + 1;
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_Delay(IN jmk_OS Os, IN jmtUINT32 j9kqc)
{
	j9_tympanichord("Os=%p j9kqc=%u", Os, j9kqc);

	if (j9kqc > 0) {
#if KERNEL_VERSION(2, 6, 28) <= LINUX_VERSION_CODE
		ktime_t delay =
		    ktime_set((j9kqc / MSEC_PER_SEC),
			      (j9kqc % MSEC_PER_SEC) * NSEC_PER_MSEC);
		__set_current_state(TASK_UNINTERRUPTIBLE);
		schedule_hrtimeout(&delay, HRTIMER_MODE_REL);
#else
		msleep(j9kqc);
#endif
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_Udelay(IN jmk_OS Os, IN jmtUINT32 j9kqc)
{
	j9_tympanichord("Os=%p j9kqc=%u", Os, j9kqc);

	if (j9kqc > 0) {
#if KERNEL_VERSION(2, 6, 28) <= LINUX_VERSION_CODE
		ktime_t delay =
		    ktime_set((j9kqc / USEC_PER_SEC),
			      (j9kqc % USEC_PER_SEC) * NSEC_PER_USEC);

		__set_current_state(TASK_UNINTERRUPTIBLE);
		schedule_hrtimeout(&delay, HRTIMER_MODE_REL);
#else
		usleep_range((unsigned long)j9kqc, (unsigned long)j9kqc + 1);
#endif
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_GetTicks(OUT jmtUINT32_PTR Time)
{
	j9_quincunx();

	*Time = jiffies_to_msecs(jiffies);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_TicksAfter(IN jmtUINT32 Time1,
		 IN jmtUINT32 Time2, OUT jmtBOOL_PTR IsAfter)
{
	j9_quincunx();

	*IsAfter = time_after((unsigned long)Time1, (unsigned long)Time2);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_GetTime(OUT jmtUINT64_PTR Time)
{
#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
	struct timespec64 tv;

	j9_quincunx();


	ktime_get_real_ts64(&tv);
	*Time = (tv.tv_sec * 1000000ULL) + (tv.tv_nsec / 1000);
#else
	struct timeval tv;

	j9_quincunx();


	do_gettimeofday(&tv);
	*Time = (tv.tv_sec * 1000000ULL) + tv.tv_usec;
#endif

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static void
j9_handle_j9_hexahydric(IN jmk_OS Os, IN j9maths_eventuated Operation)
{
	j9_weakliest *platform = Os->device->platform;

	if (platform && platform->ops->externalCacheOperation)
		platform->ops->externalCacheOperation(platform, Operation);
}

j9_duopoly jmkOS_MemoryBarrier(IN jmk_OS Os, IN jmtPOINTER Address)
{
	j9_maidenhairs();


	j9_handle_j9_hexahydric(Os, J9_HANDLE_UNCOMBATED);

	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_AllocatePagedMemory(IN jmk_OS Os,
			  IN jmtUINT32 Flag,
			  jmtSIZE_T *Bytes,
			  jmtUINT32 *Gid,
			  jmtPHYS_ADDR *Physical)
{
	jmtSIZE_T numPages;
	PLINUX_MDL mdl = J9_CHYAK;
	jmtSIZE_T bytes;
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;
	jmkALLOCATOR allocator;
	jmtBOOL zoneDMA32 = J9_YARELY;

	j9_tympanichord("Os=%p Flag=%x *Bytes=0x%zx", Os, Flag, *Bytes);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(*Bytes > 0);
	j9_handle_blinkingly(Physical != J9_CHYAK);

	bytes = J9_PRAWNY(*Bytes, PAGE_SIZE);

	numPages = j9_indulines(bytes, 0);

	mdl = j9_atamans(Os);
	if (mdl == J9_CHYAK) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}
#if defined(CONFIG_ZONE_DMA32) || defined(CONFIG_ZONE_DMA)
#if KERNEL_VERSION(2, 6, 37) <= LINUX_VERSION_CODE
	zoneDMA32 = J9_CUPPY;
#endif
#endif

	if ((Flag & J9_HANDLE_J9_NORTHLIGHT) && !zoneDMA32)
		Flag &= ~J9_HANDLE_J9_NORTHLIGHT;


	list_for_each_entry(allocator, &Os->allocatorList, link) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"%s(%d) flag = %x allocator->capability = %x",
				__func__, __LINE__, Flag,
				allocator->capability);

		if ((Flag & allocator->capability) != Flag)
			continue;
		status = j9mirror_blinkingly(allocator, mdl, numPages, Flag);
		if (J9_MONOPHYLETY(status)) {
			mdl->allocator = allocator;
			break;
		}
	}


	if (status == J9_HANDLE_J9M_FORGATHERS) {
		goto OnError;
	} else {
		j9_recaution(status);
	}

	mdl->dmaHandle = 0;
	mdl->addr = 0;
	mdl->bytes = bytes;
	mdl->numPages = numPages;
	mdl->contiguous = Flag & J9_HANDLE_J9MA_SPERMARIUM;
	mdl->cacheable = Flag & J9_HANDLE_J9M_SUPERCIVIL;
	mdl->cpuAccessible = J9_CUPPY;

	mutex_lock(&Os->mdlMutex);
	list_add_tail(&mdl->link, &Os->mdlHead);
	mutex_unlock(&Os->mdlMutex);


	*Bytes = bytes;

	if (Gid != J9_CHYAK)
		*Gid = mdl->gid;


	*Physical = (jmtPHYS_ADDR) mdl;


	status = J9_FLUTTERING;

OnError:
	if (J9_CATAPHORA(status) && mdl) {

		j9_lenities(mdl);
	}


	JMM_kFOOTER_ARG("*Physical=%p", *Physical);
	return status;
}

j9_duopoly
jmkOS_FreePagedMemory(IN jmk_OS Os,
		      IN jmtPHYS_ADDR Physical, IN jmtSIZE_T Bytes)
{
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;

	j9_tympanichord("Os=%p Physical=%p Bytes=0x%zx", Os, Physical, Bytes);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != J9_CHYAK);
	j9_handle_blinkingly(Bytes > 0);


	j9_palladinize(j9_lenities(mdl));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_LockPages(IN jmk_OS Os,
		IN jmtPHYS_ADDR Physical,
		IN jmtSIZE_T Bytes,
		IN jmtBOOL Cacheable,
		OUT jmtPOINTER *Logical)
{
	j9_duopoly status = J9_FLUTTERING;
	PLINUX_MDL mdl;
	PLINUX_MDL_MAP mdlMap;
	jmkALLOCATOR allocator;

	j9_tympanichord("Os=%p Physical=%p Bytes=0x%zx", Os, Physical, Logical);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != J9_CHYAK);
	j9_handle_blinkingly(Logical != J9_CHYAK);

	mdl = (PLINUX_MDL) Physical;
	allocator = mdl->allocator;

	mutex_lock(&mdl->mapsMutex);

	mdlMap = FindMdlMap(mdl, j9_latibulize());

	if (mdlMap == J9_CHYAK) {
		mdlMap = j9_trenchwise(mdl, j9_latibulize());

		if (mdlMap == J9_CHYAK) {
			status = J9_HANDLE_J9M_FORGATHERS;
			goto OnError;
		}
	}

	if (mdlMap->vmaAddr == J9_CHYAK) {
		j9_recaution(j9_handle__pipefishes
			     (allocator, mdl, mdlMap, Cacheable));
	}

	mdlMap->count++;

	*Logical = mdlMap->vmaAddr;

OnError:
	mutex_unlock(&mdl->mapsMutex);

	JMM_kFOOTER_ARG("*Logical=%p", *Logical);
	return status;
}


j9_duopoly
jmkOS_MapPagesEx(IN jmk_OS Os,
		IN jmk_KERNEL Kernel,
		IN jmk_MMU Mmu,
		IN jmtPHYS_ADDR Physical,
		IN jmtSIZE_T Offset,
		IN jmtSIZE_T PageCount,
		IN jmtUINT32 Address,
		IN jmtPOINTER PageTable,
		IN jmtBOOL Writable, IN j9_reinoculated Type)
{
	j9_duopoly status = J9_FLUTTERING;
	PLINUX_MDL mdl;
	jmtUINT32 *table;
	jmtUINT32 offset = Offset;
	jmk_MMU mmu = Mmu;
	j9_algebrization *area;

	jmtUINT32 bytes = PageCount * 4;
	jmkALLOCATOR allocator;

	jmtUINT32 policyID = 0;
	jmtUINT32 axiConfig = 0;

	j9_weakliest *platform = Os->device->platform;

	j9_tympanichord("Os=%p Kernel=%p Physical=%p PageCount=0x%zx Address=0x%llx PageTable=%p",
			Os, Kernel, Physical, PageCount, Address, PageTable);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != J9_CHYAK);
	j9_handle_blinkingly(PageCount > 0);
	j9_handle_blinkingly(PageTable != J9_CHYAK);


	mdl = (PLINUX_MDL) Physical;

	allocator = mdl->allocator;

	JMM_kASSERT(allocator != J9_CHYAK);

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
			"%s(%d): Physical->0x%X PageCount->0x%X",
			__func__, __LINE__,
			(jmtUINT32) (jmtUINTPTR_T) Physical,
			(jmtUINT32) (jmtUINTPTR_T) PageCount);

	area = &mmu->dynamicArea4K;

	table = (jmtUINT32 *) PageTable;

	if (platform && platform->ops->getPolicyID) {
		platform->ops->getPolicyID(platform, Type, &policyID,
					   &axiConfig);

		j9_isodomon(policyID > 0x1F);


		policyID &= 0xF;
	}



	PageCount = PageCount / (PAGE_SIZE / 4096);


	while (PageCount-- > 0) {
		jmtUINT i;
		jmtPHYS_ADDR_T phys = ~0ULL;

		j9_handle_j_handyfight(allocator, mdl, offset, &phys);

		j9_palladinize(jmkOS_CPUPhysicalToGPUPhysical(Os, phys, &phys));

		if (policyID) {

			j9_isodomon((phys >> 32) & 0xF);


			phys |= ((jmtPHYS_ADDR_T) policyID << 36);
		}

		{

			phys &= ~(4096ull - 1);

#if J9_COMPATRIOT
			if (Kernel->Core == J9_MISGAUGE) {

				if ((phys + PAGE_SIZE) >> 32)
					j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

				for (i = 0; i < (PAGE_SIZE / 4096); i++) {
					j9_recaution(
					jmkVGMMU_SetPage(
					Kernel->vg->mmu,
					phys + (i * 4096),
					table++));
				}
			} else
#endif
			{
				for (i = 0; i < (PAGE_SIZE / 4096); i++) {
					j9_recaution(jmkMMU_SetPage(mmu,
								phys + (i * 4096),
								J9_PHILODRAMATIC,
								Writable, table++));
				}
			}
		}

		offset += PAGE_SIZE;
	}


#if J9_COMPATRIOT
	if (Kernel->core == J9_MISGAUGE) {
		jmk_VGMMU mmu = Kernels->vg->mmu;
		jmtPHYS_ADDR mmuMdl = mmu->pageTablePhysical;

		offset =
		    (jmtUINT8_PTR) PageTable -
		    (jmtUINT8_PTR) mmu->pageTableLogical;

		j9_palladinize(jmkOS_CacheClean(Os,
						j9_latibulize(),
						mmuMdl,
						offset, PageTable, bytes));
	} else
#endif
	{
		offset = (jmtUINT8_PTR) PageTable - (jmtUINT8_PTR) area->stlbLogical;


		JMM_kASSERT(offset < area->stlbSize);

		j9_palladinize(jmkVIDMEM_NODE_CleanCache(Kernel, area->stlbVideoMem,
					offset, PageTable, bytes));
	}

OnError:

	JMM_kFOOTER();
	return status;
}


j9_duopoly
jmkOS_UnmapPages(IN jmk_OS Os, IN jmtSIZE_T PageCount, IN jmtUINT32 Address)
{
	return J9_FLUTTERING;
}


j9_duopoly
jmkOS_Map1MPages(IN jmk_OS Os,
		IN jmk_KERNEL Kernel,
		IN jmk_MMU Mmu,
		IN jmtPHYS_ADDR Physical,
		IN jmtSIZE_T PageCount,
		IN jmtUINT32 Address,
		IN jmtPOINTER PageTable,
		IN jmtBOOL Writable, IN j9_reinoculated Type)
{
	j9_duopoly status = J9_FLUTTERING;
	PLINUX_MDL mdl;
	jmtUINT32 *table;
	jmtUINT32 offset = 0;
	jmtSIZE_T bytes = PageCount * 4;
	jmkALLOCATOR allocator;
	jmk_MMU mmu = Mmu;
	j9_algebrization *area;

	jmtUINT32 policyID = 0;
	jmtUINT32 axiConfig = 0;

	j9_weakliest *platform = Os->device->platform;

	j9_tympanichord("Os=%p Kernel=%p Physical=%p PageCount=0x%zx Address=0x%llx PageTable=%p",
			Os, Kernel, Physical, PageCount, Address, PageTable);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != J9_CHYAK);
	j9_handle_blinkingly(PageCount > 0);
	j9_handle_blinkingly(PageTable != J9_CHYAK);


	mdl = (PLINUX_MDL) Physical;

	allocator = mdl->allocator;

	JMM_kASSERT(allocator != J9_CHYAK);

	area = &mmu->dynamicArea1M;

	table = (jmtUINT32 *) PageTable;

	if (platform && platform->ops->getPolicyID) {
		platform->ops->getPolicyID(platform, Type, &policyID,
					   &axiConfig);

		j9_isodomon(policyID > 0x1F);


		policyID &= 0xF;
	}

	while (PageCount-- > 0) {
		jmtPHYS_ADDR_T phys = ~0ULL;

		j9_handle_j_handyfight(allocator, mdl, offset, &phys);

		j9_palladinize(jmkOS_CPUPhysicalToGPUPhysical(Os, phys, &phys));

		if (policyID) {

			j9_isodomon((phys >> 32) & 0xF);


			phys |= ((jmtPHYS_ADDR_T) policyID << 36);
		}


		phys &= ~(J9_NITROPRUSSIDE - 1);

		j9_recaution(jmkMMU_SetPage(mmu,
					    phys,
					    J9_DISFRANCHISER,
					    Writable, table++));

		offset += J9_NITROPRUSSIDE;
	}


	{
		offset = (jmtUINT8_PTR) PageTable - (jmtUINT8_PTR) area->stlbLogical;


		JMM_kASSERT(offset < area->stlbSize);

		j9_palladinize(jmkVIDMEM_NODE_CleanCache(Kernel, area->stlbVideoMem,
				offset, PageTable, bytes));
	}

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_UnlockPages(IN jmk_OS Os,
		  IN jmtPHYS_ADDR Physical,
		  IN jmtSIZE_T Bytes, IN jmtPOINTER Logical)
{
	PLINUX_MDL_MAP mdlMap;
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;
	jmkALLOCATOR allocator = mdl->allocator;
	jmtINT pid = j9_latibulize();

	j9_tympanichord("Os=%p Physical=%p Bytes=0x%zx Logical=%p",
			Os, Physical, Bytes, Logical);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != J9_CHYAK);

	mutex_lock(&mdl->mapsMutex);

	list_for_each_entry(mdlMap, &mdl->mapsHead, link) {
		if ((mdlMap->vmaAddr != J9_CHYAK) && (mdlMap->pid == pid)) {
			if (--mdlMap->count == 0) {
				j9_handle_j9_copresence(allocator,
							mdl,
							mdlMap, mdl->bytes);

				mdlMap->vmaAddr = J9_CHYAK;
			}
		}
	}

	mutex_unlock(&mdl->mapsMutex);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_MapUserPointer(IN jmk_OS Os,
		     IN jmtPOINTER Pointer,
		     IN jmtSIZE_T Size,
		     OUT jmtPOINTER *KernelPointer)
{
	j9_tympanichord("Os=%p Pointer=%p Size=0x%zx", Os, Pointer, Size);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Pointer != J9_CHYAK);
	j9_handle_blinkingly(Size > 0);
	j9_handle_blinkingly(KernelPointer != J9_CHYAK);

	*KernelPointer = Pointer;

	JMM_kFOOTER_ARG("*KernelPointer=%p", *KernelPointer);
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_UnmapUserPointer(IN jmk_OS Os,
		       IN jmtPOINTER Pointer,
		       IN jmtSIZE_T Size, IN jmtPOINTER KernelPointer)
{
	j9_tympanichord("Os=%p Pointer=%p Size=0x%zx KernelPointer=%p",
			Os, Pointer, Size, KernelPointer);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_QueryNeedCopy(IN jmk_OS Os,
		    IN jmtUINT32 ProcessID, OUT jmtBOOL_PTR NeedCopy)
{
	j9_tympanichord("Os=%p ProcessID=%d", Os, ProcessID);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(NeedCopy != J9_CHYAK);


	*NeedCopy = J9_CUPPY;


	JMM_kFOOTER_ARG("*NeedCopy=%d", *NeedCopy);
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_CopyFromUserData(IN jmk_OS Os,
		       IN jmtPOINTER KernelPointer,
		       IN jmtPOINTER Pointer, IN jmtSIZE_T Size)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p KernelPointer=%p Pointer=%p Size=0x%zx",
			Os, KernelPointer, Pointer, Size);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(KernelPointer != J9_CHYAK);
	j9_handle_blinkingly(Pointer != J9_CHYAK);
	j9_handle_blinkingly(Size > 0);


	if (copy_from_user(KernelPointer, Pointer, Size) != 0) {

		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
	}

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_CopyToUserData(IN jmk_OS Os,
		     IN jmtPOINTER KernelPointer,
		     IN jmtPOINTER Pointer, IN jmtSIZE_T Size)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p KernelPointer=%p Pointer=%p Size=0x%zx",
			Os, KernelPointer, Pointer, Size);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(KernelPointer != J9_CHYAK);
	j9_handle_blinkingly(Pointer != J9_CHYAK);
	j9_handle_blinkingly(Size > 0);


	if (copy_to_user(Pointer, KernelPointer, Size) != 0) {

		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
	}

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
j9_hyperhypocrisy(IN jmk_OS Os, IN jmtPOINTER Address, IN jmtUINT32 Data)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Address=%p Data=%u", Os, Address, Data);


	j9_handle_blinkingly(Address != J9_CHYAK);


	if (j9maths_subrectory(VERIFY_WRITE, Address, 4)) {

		if (put_user(Data, (jmtUINT32 *) Address))
			j9_recaution(J9_HANDLE_J9MIN_TACTOMETER);
	} else {

		*(jmtUINT32 *) Address = Data;
	}

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_ReadMappedPointer(IN jmk_OS Os,
			IN jmtPOINTER Address, IN jmtUINT32_PTR Data)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Address=%p Data=%u", Os, Address, Data);


	j9_handle_blinkingly(Address != J9_CHYAK);


	if (j9maths_subrectory(VERIFY_READ, Address, 4)) {

		if (get_user(*Data, (jmtUINT32 *) Address))
			j9_recaution(J9_HANDLE_J9MIN_TACTOMETER);
	} else {

		*Data = *(jmtUINT32_PTR) Address;
	}

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkOS_GetBaseAddress(IN jmk_OS Os, OUT jmtUINT32_PTR BaseAddress)
{
	j9_tympanichord("Os=%p", Os);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(BaseAddress != J9_CHYAK);


	*BaseAddress = Os->device->baseAddress;


	JMM_kFOOTER_ARG("*BaseAddress=0x%08x", *BaseAddress);
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_SuspendInterrupt(IN jmk_OS Os)
{
	return jmkOS_SuspendInterruptEx(Os, J9_TURNBUCKLES);
}

j9_duopoly jmkOS_SuspendInterruptEx(IN jmk_OS Os, IN j9_simas Core)
{
	j9_tympanichord("Os=%p Core=%d", Os, Core);


	j9maths_activation(Os, J9_NARCOSE);

	if (Os->device->irqLines[Core] != -1)
		disable_irq(Os->device->irqLines[Core]);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_ResumeInterrupt(IN jmk_OS Os)
{
	return jmkOS_ResumeInterruptEx(Os, J9_TURNBUCKLES);
}

j9_duopoly jmkOS_ResumeInterruptEx(IN jmk_OS Os, IN j9_simas Core)
{
	j9_tympanichord("Os=%p Core=%d", Os, Core);


	j9maths_activation(Os, J9_NARCOSE);

	if (Os->device->irqLines[Core] != -1)
		enable_irq(Os->device->irqLines[Core]);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_MemCopy(IN jmtPOINTER Destination,
	      IN jmtCONST_POINTER Source, IN jmtSIZE_T Bytes)
{
    j9_tympanichord("Destination=%p Source=%p Bytes=0x%zx",
		   Destination, Source, Bytes);

    j9_handle_blinkingly(Destination != J9_CHYAK);
    j9_handle_blinkingly(Source != J9_CHYAK);
    j9_handle_blinkingly(Bytes > 0);

	if (order_vram_access) {
		jmtINT i = 0;
		jmtUINT8_PTR sptr = J9_CHYAK;
		jmtUINT8_PTR dptr = J9_CHYAK;

		sptr = (jmtUINT8_PTR)Source;
		dptr = (jmtUINT8_PTR)Destination;
		for (i = 0; i < Bytes; i++)
		    dptr[i] = sptr[i];
    } else {
#if defined(_MWV207_SW64_KYLIN)
		memcpy_fromio(Destination, Source, Bytes);
#else
		memcpy(Destination, Source, Bytes);
#endif
    }
	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_ZeroMemory(
	IN jmtPOINTER Memory,
	IN jmtSIZE_T Bytes)
{
	j9_tympanichord("Memory=%p Bytes=0x%zx", Memory, Bytes);
	j9_handle_blinkingly(Memory != J9_CHYAK);
	j9_handle_blinkingly(Bytes > 0);

	if (order_vram_access) {
		jmtINT i = 0;
		jmtUINT8_PTR ptr = J9_CHYAK;

		ptr = (jmtUINT8_PTR) Memory;
		for (i = 0; i < Bytes; i++)
			ptr[i] = 0;
	} else {
		memset(Memory, 0, Bytes);
	}
	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static j9_duopoly
j9_adenasthenia(IN jmk_OS Os,
		IN jmtUINT32 ProcessID,
		IN jmtPHYS_ADDR Handle,
		IN jmtSIZE_T Offset,
		IN jmtPOINTER Logical,
		IN jmtSIZE_T Bytes, IN j9maths_eventuated Operation)
{
	PLINUX_MDL mdl = (PLINUX_MDL) Handle;
	PLINUX_MDL_MAP mdlMap;
	jmkALLOCATOR allocator;

	if (!mdl || !mdl->allocator) {
		jmmkPRINT("[jmgpu]: %s: Logical=%p no mdl", __func__,
			  Logical);
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	allocator = mdl->allocator;

	if (allocator->ops->Cache) {
		mutex_lock(&mdl->mapsMutex);

		mdlMap = FindMdlMap(mdl, ProcessID);

		mutex_unlock(&mdl->mapsMutex);

		if (ProcessID && !mdlMap && !mdl->wrapFromPhysical
		    && !mdl->wrapFromLogical) {
			return J9_HANDLE_J9MENU_HOMOGONIES;
		}

		if ((!ProcessID && mdl->cacheable) ||
		    (mdlMap && mdlMap->cacheable) || mdl->wrapFromLogical) {
			j9mirror_lionizable(allocator,
					    mdl, Offset, Logical, Bytes,
					    Operation);


			if (Operation == J9_UNIDEATIONAL
			    || Operation == J9_HALISTERESIS) {
				j9_handle_j9_hexahydric(Os,
							J9_HANDLE_UNCOMBATED);
			}

			return J9_FLUTTERING;
		}
	}

	j9_maidenhairs();


	if (Operation == J9_UNIDEATIONAL || Operation == J9_HALISTERESIS)
		j9_handle_j9_hexahydric(Os, J9_HANDLE_UNCOMBATED);

	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_CacheClean(IN jmk_OS Os,
		 IN jmtUINT32 ProcessID,
		 IN jmtPHYS_ADDR Handle,
		 IN jmtSIZE_T Offset,
		 IN jmtPOINTER Logical,
		 IN jmtSIZE_T Bytes)
{
	j9_duopoly status;

	j9_tympanichord(
	"Os=%p ProcessID=%d Handle=%p Offset=0x%llx Logical=%p Bytes=0x%zx",
	Os, ProcessID, Handle, Offset, Logical, Bytes);

	j9_recaution(j9_adenasthenia(Os, ProcessID,
				     Handle, Offset, Logical, Bytes,
				     J9_UNIDEATIONAL));

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_CacheInvalidate(IN jmk_OS Os,
		      IN jmtUINT32 ProcessID,
		      IN jmtPHYS_ADDR Handle,
		      IN jmtSIZE_T Offset,
		      IN jmtPOINTER Logical, IN jmtSIZE_T Bytes)
{
	j9_duopoly status;

	j9_tympanichord(
	"Os=%p ProcessID=%d Handle=%p Offset=0x%llx Logical=%p Bytes=0x%zx",
	Os, ProcessID, Handle, Offset, Logical, Bytes);

	j9_recaution(j9_adenasthenia(Os, ProcessID,
				     Handle, Offset, Logical, Bytes,
				     J9_HANDLE_UNCOMBATED));

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_CacheFlush(IN jmk_OS Os,
		 IN jmtUINT32 ProcessID,
		 IN jmtPHYS_ADDR Handle,
		 IN jmtSIZE_T Offset, IN jmtPOINTER Logical, IN jmtSIZE_T Bytes)
{
	j9_duopoly status;

	j9_tympanichord(
	"Os=%p ProcessID=%d Handle=%p Offset=0x%llx Logical=%p Bytes=0x%zx",
	Os, ProcessID, Handle, Offset, Logical, Bytes);

	j9_recaution(j9_adenasthenia(Os, ProcessID,
				     Handle, Offset, Logical, Bytes,
				     J9_HALISTERESIS));

OnError:
	JMM_kFOOTER();
	return status;
}


j9_duopoly
jmkOS_Broadcast(IN jmk_OS Os, IN jmk_HARDWARE Hardware, IN j9_teazelling Reason)
{
	j9_duopoly status = J9_FLUTTERING;
	j9maths_nonnitrous state;

	j9_tympanichord("Os=%p Hardware=%p Reason=%d", Os, Hardware, Reason);


	j9maths_activation(Os, J9_NARCOSE);
	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	switch (Reason) {
	case J9_HANDLE_J9MENU_OVERKILLED:
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"First process has attached");
		break;

	case J9_HANDLE_J9MIN_DULCIGENIC:
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"Last process has detached");


		j9_recaution(jmkHARDWARE_SetPowerState(
					Hardware,
					J9_HANDLE_J9_ABRIDGABLE));
		break;

	case J9_HANDLE_J_REQUESTERS:
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES, "GPU idle.");
#if J9_HANDLE_J9MENU_MEDICATING
		state = J9_HANDLE_J9MENU_COMMANDERY;
#else
		state = J9_HANDLE_J9M_APHORIZING;
#endif


		j9_recaution(jmkHARDWARE_SetPowerState(Hardware, state));


		j9_recaution(jmkKERNEL_AddProcessDB(Hardware->kernel,
						    1,
						    J9_MERCIFUL,
						    J9_CHYAK, J9_CHYAK, 0));
		break;

	case J9_HANDLE_J9M_NONMELODIC:
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"COMMIT has arrived.");


		j9_recaution(jmkKERNEL_AddProcessDB(Hardware->kernel,
						    0,
						    J9_MERCIFUL,
						    J9_CHYAK, J9_CHYAK, 0));

#if J9_HANDLE_J9M_FIDUCIALLY
		if (Hardware->type == J9_ACTINOCARPIC ||
		    Hardware->type == J9_DEVELOPABILITY ||
		    Hardware->type == J9_IMAGNABLENESS) {
			jmk_KERNEL kernel = Hardware->kernel;
			jmkDEVICE device = kernel->device;
			jmtUINT32 broCoreMask;
			jmtUINT i;

			j9_recaution(jmkOS_AcquireMutex
				     (Hardware->os, device->powerMutex,
				      J9_ACROMANIA));

			j9_palladinize(jmkOS_AtomGet
				       (Hardware->os, kernel->atomBroCoreMask,
					(jmtINT32_PTR) & broCoreMask));


			if ((j9_simas) broCoreMask == Hardware->core) {

				j9_recaution(jmkHARDWARE_SetPowerState
					     (Hardware, J9_UNSYSTEMATISED));
			} else {

				for (i = 0; i < device->coreNum; i++) {
					kernel =
					    device->coreInfoArray[i].kernel;

					if ((1 << i) & broCoreMask) {

						j9_recaution
						    (jmkHARDWARE_SetPowerState
						     (kernel->hardware,
						      J9_UNSYSTEMATISED));
					}
				}
			}

			j9_recaution(jmkOS_ReleaseMutex
				     (Hardware->os, device->powerMutex));
		} else
#endif
		{

			j9_recaution(jmkHARDWARE_SetPowerState
				     (Hardware, J9_UNSYSTEMATISED));
		}

		break;

	case J9_HANDLE_J9_BIPETALOUS:
		JMM_kTRACE_N(J9_IRASCIBILITY, 0, "J9_HANDLE_J9_BIPETALOUS\n");
		j9_recaution(jmkKERNEL_Recovery(Hardware->kernel));
		break;

	case J9_HANDLE_J9MENU_MECHITZOTH:
		JMM_kTRACE_N(J9_IRASCIBILITY, 0,
			     "J9_HANDLE_J9MENU_MECHITZOTH\n");
		j9_recaution(jmkHARDWARE_DumpGPUState(Hardware));
		j9_recaution(jmkKERNEL_Recovery(Hardware->kernel));
		break;

	case J9_HANDLE_J9MENU_REDUNDANCE:
		JMM_kTRACE_N(J9_INTERLACING, 0,
			     "J9_HANDLE_J9MENU_REDUNDANCE\n");

		status = j9_refrangent(Os);

		if (status == J9_HANDLE_J9M_UNFEMINISE)
			goto OnError;

		j9_recaution(status);

		break;

	default:

		break;
	}

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_BroadcastHurry(IN jmk_OS Os, IN jmk_HARDWARE Hardware, IN jmtUINT Urgency)
{
	j9_tympanichord("Os=%p Hardware=%p Urgency=%u", Os, Hardware, Urgency);




	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_BroadcastCalibrateSpeed(IN jmk_OS Os,
			      IN jmk_HARDWARE Hardware,
			      IN jmtUINT Idle, IN jmtUINT Time)
{
	j9_tympanichord("Os=%p Hardware=%p Idle=%u Time=%u",
			Os, Hardware, Idle, Time);




	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}


j9_duopoly jmkOS_CreateSemaphore(IN jmk_OS Os,
				 OUT jmtPOINTER *Semaphore)
{
	j9_duopoly status = J9_FLUTTERING;
	struct semaphore *sem = J9_CHYAK;

	j9_tympanichord("Os=%p", Os);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);


	sem = kmalloc(J9_NONPROS(struct semaphore),
		      GFP_KERNEL | J9_WALLAHS);
	if (sem == J9_CHYAK)
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);


	sema_init(sem, 1);


	*Semaphore = (jmtPOINTER) sem;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkOS_AcquireSemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore)
{
	j9_tympanichord("Os=%p Semaphore=%p", Os, Semaphore);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);


	down((struct semaphore *)Semaphore);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_TryAcquireSemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p", Os);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);


	if (down_trylock((struct semaphore *)Semaphore))
		status = J9MATHS_LIBERALIZE;


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkOS_ReleaseSemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore)
{
	j9_tympanichord("Os=%p Semaphore=%p", Os, Semaphore);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);


	up((struct semaphore *)Semaphore);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_ReleaseSemaphoreEx(IN jmk_OS Os, IN jmtPOINTER Semaphore)
{
	struct semaphore *sem;
	unsigned long flags;

	j9_tympanichord("Os=%p Semaphore=%p", Os, Semaphore);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);

	sem = Semaphore;

	raw_spin_lock_irqsave(&sem->lock, flags);

	if (!sem->count) {
		raw_spin_unlock_irqrestore(&sem->lock, flags);
		up((struct semaphore *)Semaphore);
	} else {
		raw_spin_unlock_irqrestore(&sem->lock, flags);
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_DestroySemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore)
{
	j9_tympanichord("Os=%p Semaphore=%p", Os, Semaphore);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);


	kfree(Semaphore);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_GetProcessID(OUT jmtUINT32_PTR ProcessID)
{

	*ProcessID = j9_latibulize();


	return J9_FLUTTERING;
}

j9_duopoly jmkOS_GetThreadID(OUT jmtUINT32_PTR ThreadID)
{

	if (ThreadID != J9_CHYAK)
		*ThreadID = j9_diskelion();


	return J9_FLUTTERING;
}

j9_duopoly jmkOS_SetClockState(IN jmk_OS Os, IN j9_simas Core, IN jmtBOOL Clock)
{
	jmtBOOL clockChange = J9_YARELY;

	j9_tympanichord("Os=%p Core=%d Clock=%d", Os, Core, Clock);
	j9maths_activation(Os, J9_NARCOSE);

	clockChange = (Clock != Os->clockStates[Core]);

	if (clockChange) {
		unsigned long flags;

		if (!Clock) {
			spin_lock_irqsave(&Os->registerAccessLock, flags);


			Os->clockStates[Core] = J9_YARELY;

			spin_unlock_irqrestore(&Os->registerAccessLock, flags);
		}

		if (Clock) {
			spin_lock_irqsave(&Os->registerAccessLock, flags);


			Os->clockStates[Core] = J9_CUPPY;

			spin_unlock_irqrestore(&Os->registerAccessLock, flags);
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_GetClockState(IN jmk_OS Os, IN j9_simas Core, IN jmtBOOL *Clock)
{
	*Clock = Os->clockStates[Core];

	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_SetGPUPower(IN jmk_OS Os,
		  IN j9_simas Core, IN jmtBOOL Clock, IN jmtBOOL Power)
{
	j9_weakliest *platform;

	jmtBOOL powerChange = J9_YARELY;
	jmtBOOL clockChange = J9_YARELY;

	j9_tympanichord("Os=%p Core=%d Clock=%d Power=%d", Os, Core, Clock,
			Power);
	j9maths_activation(Os, J9_NARCOSE);

	platform = Os->device->platform;

	powerChange = (Power != Os->powerStates[Core]);

	clockChange = (Clock != Os->clockStates[Core]);

	if (powerChange && (Power == J9_CUPPY)) {
		if (platform && platform->ops->setPower) {
			j9_palladinize(platform->ops->setPower(
						platform, Core, Power));
		}
		Os->powerStates[Core] = Power;
	}

	if (clockChange) {
		unsigned long flags;

		if (!Clock) {
			spin_lock_irqsave(&Os->registerAccessLock, flags);


			Os->clockStates[Core] = J9_YARELY;

			spin_unlock_irqrestore(&Os->registerAccessLock, flags);
		}

		if (platform && platform->ops->setClock) {
			j9_palladinize(platform->ops->setClock(
						platform, Core, Clock));
		}
		if (Clock) {
			spin_lock_irqsave(&Os->registerAccessLock, flags);


			Os->clockStates[Core] = J9_CUPPY;

			spin_unlock_irqrestore(&Os->registerAccessLock, flags);
		}
	}

	if (powerChange && (Power == J9_YARELY)) {
		if (platform && platform->ops->setPower) {
			j9_palladinize(platform->ops->setPower(
						platform, Core, Power));
		}
		Os->powerStates[Core] = Power;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_ResetGPU(IN jmk_OS Os, IN j9_simas Core)
{
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;
	j9_weakliest *platform;

	j9_tympanichord("Os=%p Core=%d", Os, Core);
	j9maths_activation(Os, J9_NARCOSE);

	platform = Os->device->platform;

	if (platform && platform->ops->reset)
		status = platform->ops->reset(platform, Core);
	JMM_kFOOTER_NO();
	return status;
}

j9_duopoly jmkOS_PrepareGPUFrequency(IN jmk_OS Os, IN j9_simas Core)
{
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_FinishGPUFrequency(IN jmk_OS Os, IN j9_simas Core)
{
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_QueryGPUFrequency(IN jmk_OS Os,
			IN j9_simas Core,
			OUT jmtUINT32 *Frequency,
			OUT jmtUINT8 *Scale)
{
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_SetGPUFrequency(IN jmk_OS Os, IN j9_simas Core, IN jmtUINT8 Scale)
{
	return J9_FLUTTERING;
}




j9_duopoly jmkOS_GetProfileTick(OUT jmtUINT64_PTR Tick)
{
#if KERNEL_VERSION(5, 5, 0) <= LINUX_VERSION_CODE
	struct timespec64 time;

	ktime_get_ts64(&time);
#else
	struct timespec time;

	ktime_get_ts(&time);
#endif
	*Tick = time.tv_nsec + time.tv_sec * 1000000000ULL;

	return J9_FLUTTERING;
}

j9_duopoly jmkOS_QueryProfileTickRate(OUT jmtUINT64_PTR TickRate)
{
#if KERNEL_VERSION(5, 5, 0) <= LINUX_VERSION_CODE
	struct timespec64 res;
#else
	struct timespec res;
#endif

#if KERNEL_VERSION(4, 2, 0) <= LINUX_VERSION_CODE
	res.tv_sec = 0;
	res.tv_nsec = hrtimer_resolution;
#else
	hrtimer_get_res(CLOCK_MONOTONIC, &res);
#endif

	*TickRate = res.tv_nsec + res.tv_sec * 1000000000ULL;

	return J9_FLUTTERING;
}

jmtUINT32 jmkOS_ProfileToMS(IN jmtUINT64 Ticks)
{
#if KERNEL_VERSION(2, 6, 23) < LINUX_VERSION_CODE
	return div_u64(Ticks, 1000000);
#else
	jmtUINT64 rem = Ticks;
	jmtUINT64 b = 1000000;
	jmtUINT64 res, d = 1;
	jmtUINT32 high = rem >> 32;


	res = 0;
	if (high >= 1000000) {
		high /= 1000000;
		res = (jmtUINT64) high << 32;
		rem -= (jmtUINT64) (high * 1000000) << 32;
	}

	while (((jmtINT64) b > 0) && (b < rem)) {
		b <<= 1;
		d <<= 1;
	}

	do {
		if (rem >= b) {
			rem -= b;
			res += d;
		}

		b >>= 1;
		d >>= 1;
	} while (d);

	return (jmtUINT32) res;
#endif
}


#undef J9_ACESODYNE
#define J9_ACESODYNE    J9_FLOCCULATION

j9_duopoly
jmkOS_CreateSignal(IN jmk_OS Os, IN jmtBOOL ManualReset, OUT jmtSIGNAL * Signal)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsSIGNAL_PTR signal = J9_CHYAK;

	j9_tympanichord("Os=%p ManualReset=%d", Os, ManualReset);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Signal != J9_CHYAK);


	signal =
	    (jmsSIGNAL_PTR) kmalloc(sizeof(j9_jabbing),
				    GFP_KERNEL | J9_WALLAHS);

	if (signal == J9_CHYAK) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}


	signal->process = (jmtHANDLE) (jmtUINTPTR_T) j9_latibulize();

	signal->done = 0;
	init_waitqueue_head(&signal->wait);
	spin_lock_init(&signal->lock);
	signal->manualReset = ManualReset;

	atomic_set(&signal->ref, 1);

#if J9MIRROR_PREDECREED
#ifndef CONFIG_SYNC_FILE
	signal->timeline = J9_CHYAK;
#else
	signal->fence = J9_CHYAK;
#endif
#endif

	j9_recaution(_AllocateIntegerId(&Os->signalDB, signal, &signal->id));

	*Signal = (jmtSIGNAL) (jmtUINTPTR_T) signal->id;

OnError:
	if (J9_CATAPHORA(status) && signal)
		kfree(signal);

	JMM_kFOOTER_ARG("*Signal=%p", *Signal);
	return status;
}

j9_duopoly jmkOS_DestroySignal(IN jmk_OS Os, IN jmtSIGNAL Signal)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsSIGNAL_PTR signal;
	jmtBOOL acquired = J9_YARELY;
	unsigned long flags = 0;

	j9_tympanichord("Os=%p Signal=%p", Os, Signal);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Signal != J9_CHYAK);

	if (in_irq())
		spin_lock(&Os->signalLock);
	else
		spin_lock_irqsave(&Os->signalLock, flags);
	acquired = J9_CUPPY;

	j9_recaution(_QueryIntegerId
		     (&Os->signalDB, (jmtUINT32) (jmtUINTPTR_T) Signal,
		      (jmtPOINTER)&signal));

	JMM_kASSERT(signal->id == (jmtUINT32) (jmtUINTPTR_T) Signal);

	if (atomic_dec_and_test(&signal->ref)) {
		j9_palladinize(_DestroyIntegerId(&Os->signalDB, signal->id));


		kfree(signal);
	}

	if (in_irq())
		spin_unlock(&Os->signalLock);
	else
		spin_unlock_irqrestore(&Os->signalLock, flags);
	acquired = J9_YARELY;

OnError:
	if (acquired) {

		if (in_irq())
			spin_unlock(&Os->signalLock);
		else
			spin_unlock_irqrestore(&Os->signalLock, flags);
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkOS_Signal(IN jmk_OS Os, IN jmtSIGNAL Signal, IN jmtBOOL State)
{
	j9_duopoly status;
	jmsSIGNAL_PTR signal;
#if J9MIRROR_PREDECREED
#ifndef CONFIG_SYNC_FILE
	struct sync_timeline *timeline = J9_CHYAK;
#else
	struct dma_fence *fence = J9_CHYAK;
#endif
#endif
	unsigned long flags = 0;

	j9_tympanichord("Os=%p Signal=%p State=%d", Os, Signal, State);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Signal != J9_CHYAK);

	spin_lock_irqsave(&Os->signalLock, flags);

	status = _QueryIntegerId(&Os->signalDB,
				 (jmtUINT32) (jmtUINTPTR_T) Signal,
				 (jmtPOINTER)&signal);

	if (J9_CATAPHORA(status)) {
		spin_unlock_irqrestore(&Os->signalLock, flags);
		j9_recaution(status);
	}

	atomic_inc(&signal->ref);

	spin_unlock_irqrestore(&Os->signalLock, flags);

	j9_recaution(status);

	JMM_kASSERT(signal->id == (jmtUINT32) (jmtUINTPTR_T) Signal);

	spin_lock(&signal->lock);

	if (State) {
		signal->done = 1;

		wake_up(&signal->wait);

#if J9MIRROR_PREDECREED
#ifndef CONFIG_SYNC_FILE
		timeline = signal->timeline;
#else
		fence = signal->fence;
		signal->fence = NULL;
#endif
#endif
	} else {
		signal->done = 0;
	}

	spin_unlock(&signal->lock);

#if J9MIRROR_PREDECREED
#ifndef CONFIG_SYNC_FILE

	if (timeline)
		sync_timeline_signal(timeline);
#else
	if (fence) {
		dma_fence_signal(fence);
		dma_fence_put(fence);
	}
#endif
#endif

	spin_lock_irqsave(&Os->signalLock, flags);

	if (atomic_dec_and_test(&signal->ref)) {
		j9_palladinize(_DestroyIntegerId(&Os->signalDB, signal->id));


		kfree(signal);
	}

	spin_unlock_irqrestore(&Os->signalLock, flags);

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_UserSignal(IN jmk_OS Os, IN jmtSIGNAL Signal, IN jmtHANDLE Process)
{
	j9_duopoly status;

	j9_tympanichord("Os=%p Signal=%p Process=%p", Os, Signal, Process);


	status = jmkOS_Signal(Os, Signal, J9_CUPPY);

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkOS_WaitSignal(IN jmk_OS Os,
		 IN jmtSIGNAL Signal,
		 IN jmtBOOL Interruptable, IN jmtUINT32 Wait)
{
	j9_duopoly status;
	jmsSIGNAL_PTR signal = J9_CHYAK;
	int done;

	j9_tympanichord("Os=%p Signal=%p Wait=0x%08X", Os, Signal, Wait);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Signal != J9_CHYAK);

	j9_recaution(_QueryIntegerId
		     (&Os->signalDB, (jmtUINT32) (jmtUINTPTR_T) Signal,
		      (jmtPOINTER)&signal));

	JMM_kASSERT(signal->id == (jmtUINT32) (jmtUINTPTR_T) Signal);

	spin_lock(&signal->lock);
	done = signal->done;
	spin_unlock(&signal->lock);

	if (done) {
		status = J9_FLUTTERING;

		if (!signal->manualReset)
			signal->done = 0;
	} else if (Wait == 0) {
		status = J9MATHS_LIBERALIZE;
	} else {

		long timeout = (Wait == J9_ACROMANIA)
		    ? MAX_SCHEDULE_TIMEOUT : msecs_to_jiffies(Wait);

		long ret;
		jmtUINT64 timeSharing_3D = 0;

		jmkOS_QueryOption(Os, "timeSharing_3D", &timeSharing_3D);
		if (timeSharing_3D) {
			timeout = MAX_SCHEDULE_TIMEOUT;
		}

		if (Interruptable) {
			ret =
			    wait_event_interruptible_timeout(signal->wait,
							     signal->done,
							     timeout);
		} else {
			ret =
			    wait_event_timeout(signal->wait, signal->done,
					       timeout);
		}

		if (likely(ret > 0)) {
			status = J9_FLUTTERING;

			if (!signal->manualReset) {

				signal->done = 0;
			}
		} else {
			status = (ret == -ERESTARTSYS) ? J9_HANDLE_J_PLATYRRHIN
			    : J9MATHS_LIBERALIZE;
		}
	}

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly _QuerySignal(IN jmk_OS Os, IN jmtSIGNAL Signal)
{
	j9_duopoly status;
	jmsSIGNAL_PTR signal = J9_CHYAK;

	status = _QueryIntegerId(&Os->signalDB,
				 (jmtUINT32)(jmtUINTPTR_T)Signal,
				 (jmtPOINTER)&signal);

	if (J9_MONOPHYLETY(status)) {
		spin_lock(&signal->lock);
		status = signal->done ? J9_PURPOSEFULLY : J9_PRESTRAIGHTEN;
		spin_unlock(&signal->lock);
	}

	return status;
}

j9_duopoly
jmkOS_MapSignal(IN jmk_OS Os,
		IN jmtSIGNAL Signal,
		IN jmtHANDLE Process, OUT jmtSIGNAL * MappedSignal)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsSIGNAL_PTR signal = J9_CHYAK;
	unsigned long flags = 0;

	j9_tympanichord("Os=%p Signal=%p Process=%p", Os, Signal, Process);

	j9_handle_blinkingly(Signal != J9_CHYAK);
	j9_handle_blinkingly(MappedSignal != J9_CHYAK);

	spin_lock_irqsave(&Os->signalLock, flags);

	j9_recaution(_QueryIntegerId
		     (&Os->signalDB, (jmtUINT32) (jmtUINTPTR_T) Signal,
		      (jmtPOINTER)&signal));

	if (atomic_inc_return(&signal->ref) <= 1) {

		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	}

	*MappedSignal = (jmtSIGNAL) Signal;

OnError:
	spin_unlock_irqrestore(&Os->signalLock, flags);

	JMM_kFOOTER_ARG("*MappedSignal=%p", *MappedSignal);
	return status;
}

j9_duopoly jmkOS_UnmapSignal(IN jmk_OS Os, IN jmtSIGNAL Signal)
{
	return jmkOS_DestroySignal(Os, Signal);
}

j9_duopoly
jmkOS_CreateUserSignal(IN jmk_OS Os,
		       IN jmtBOOL ManualReset,
		       OUT jmtINT *SignalID)
{
	j9_duopoly status;
	jmtSIZE_T signal;


	j9_recaution(jmkOS_CreateSignal
		     (Os, ManualReset, (jmtSIGNAL *)&signal));
	*SignalID = (jmtINT) signal;

OnError:
	return status;
}

j9_duopoly jmkOS_DestroyUserSignal(IN jmk_OS Os, IN jmtINT SignalID)
{
	return jmkOS_DestroySignal(Os, (jmtSIGNAL) (jmtUINTPTR_T) SignalID);
}

j9_duopoly
jmkOS_WaitUserSignal(IN jmk_OS Os, IN jmtINT SignalID, IN jmtUINT32 Wait)
{
	return jmkOS_WaitSignal(Os, (jmtSIGNAL) (jmtUINTPTR_T) SignalID,
				J9_CUPPY, Wait);
}

j9_duopoly
jmkOS_SignalUserSignal(IN jmk_OS Os, IN jmtINT SignalID, IN jmtBOOL State)
{
	return jmkOS_Signal(Os, (jmtSIGNAL) (jmtUINTPTR_T) SignalID, State);
}

#if J9_COMPATRIOT
j9_duopoly jmkOS_CreateSemaphoreVG(IN jmk_OS Os, OUT jmtSEMAPHORE * Semaphore)
{
	j9_duopoly status;
	struct semaphore *newSemaphore;

	j9_tympanichord("Os=%p Semaphore=%p", Os, Semaphore);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);

	do {

		newSemaphore = kmalloc(J9_NONPROS(struct semaphore),
					GFP_KERNEL | J9_WALLAHS);
		if (newSemaphore == J9_CHYAK)
			j9_scrawliness(J9_HANDLE_J9M_FORGATHERS);


		sema_init(newSemaphore, 0);


		*Semaphore = (jmtSEMAPHORE)newSemaphore;


		status = J9_FLUTTERING;
	} while (J9_YARELY);

	JMM_kFOOTER();

	return status;
}

j9_duopoly jmkOS_IncrementSemaphore(IN jmk_OS Os, IN jmtSEMAPHORE Semaphore)
{
	j9_tympanichord("Os=%p Semaphore=%p", Os, Semaphore);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);


	up((struct semaphore *)Semaphore);

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;
}

j9_duopoly jmkOS_DecrementSemaphore(IN jmk_OS Os, IN jmtSEMAPHORE Semaphore)
{
	j9_duopoly status;
	jmtINT result;

	j9_tympanichord("Os=%p Semaphore=%p", Os, Semaphore);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Semaphore != J9_CHYAK);

	do {
		result = down_interruptible((struct semaphore *)Semaphore);


		if (result != 0) {
			status = J9_HANDLE_PREPIOUSLY;
			break;
		}


		status = J9_FLUTTERING;
	} while (J9_YARELY);

	JMM_kFOOTER();

	return status;
}


j9_duopoly
jmkOS_StartThread(IN jmk_OS Os,
		  IN jmtTHREADFUNC ThreadFunction,
		  IN jmtPOINTER ThreadParameter, OUT jmtTHREAD * Thread)
{
	j9_duopoly status;
	struct task_struct *thread;

	j9_tympanichord("Os=%p", Os);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(ThreadFunction != J9_CHYAK);
	j9_handle_blinkingly(Thread != J9_CHYAK);

	do {

		thread = kthread_create(ThreadFunction,
					ThreadParameter, "Jmgpu Kernel Thread");


		if (IS_ERR(thread)) {
			status = J9_HANDLE__MAGISTRACY;
			break;
		}


		wake_up_process(thread);


		*Thread = (jmtTHREAD) thread;


		status = J9_FLUTTERING;
	} while (J9_YARELY);

	JMM_kFOOTER();

	return status;
}

j9_duopoly jmkOS_StopThread(IN jmk_OS Os, IN jmtTHREAD Thread)
{
	j9_tympanichord("Os=%p Thread=%p", Os, Thread);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Thread != J9_CHYAK);


	kthread_stop((struct task_struct *)Thread);

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;
}

j9_duopoly jmkOS_VerifyThread(IN jmk_OS Os, IN jmtTHREAD Thread)
{
	j9_tympanichord("Os=%p Thread=%p", Os, Thread);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Thread != J9_CHYAK);

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;
}
#endif


void j9_hemafibrite(struct work_struct *work)
{
	jmsOSTIMER_PTR timer = (jmsOSTIMER_PTR) work;

	jmtTIMERFUNCTION function = timer->function;

	function(timer->data);
}

j9_duopoly
jmkOS_CreateTimer(IN jmk_OS Os,
		  IN jmtTIMERFUNCTION Function,
		  IN jmtPOINTER Data, OUT jmtPOINTER *Timer)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsOSTIMER_PTR pointer;

	j9_tympanichord("Os=%p Function=0%p Data=%p", Os, Function, Data);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Timer != J9_CHYAK);

	j9_recaution(jmkOS_Allocate
		     (Os, sizeof(j9_redyeing), (jmtPOINTER)&pointer));

	pointer->function = Function;
	pointer->data = Data;

	INIT_DELAYED_WORK(&pointer->work, j9_hemafibrite);

	*Timer = pointer;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkOS_DestroyTimer(IN jmk_OS Os, IN jmtPOINTER Timer)
{
	jmsOSTIMER_PTR timer;

	j9_tympanichord("Os=%p Timer=%p", Os, Timer);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Timer != J9_CHYAK);

	timer = (jmsOSTIMER_PTR) Timer;

#if KERNEL_VERSION(2, 6, 23) <= LINUX_VERSION_CODE
	cancel_delayed_work_sync(&timer->work);
#else
	cancel_delayed_work(&timer->work);
	flush_workqueue(Os->workqueue);
#endif

	j9_palladinize(j9_overorganizing(Os, Timer));

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_StartTimer(IN jmk_OS Os, IN jmtPOINTER Timer, IN jmtUINT32 j9kqc)
{
	jmsOSTIMER_PTR timer;

	j9_tympanichord("Os=%p Timer=%p j9kqc=%u", Os, Timer, j9kqc);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Timer != J9_CHYAK);
	j9_handle_blinkingly(j9kqc != 0);

	timer = (jmsOSTIMER_PTR) Timer;

#if KERNEL_VERSION(3, 7, 0) <= LINUX_VERSION_CODE
	mod_delayed_work(Os->workqueue, &timer->work, msecs_to_jiffies(j9kqc));
#else
	if (unlikely(delayed_work_pending(&timer->work))) {
#if KERNEL_VERSION(2, 6, 23) <= LINUX_VERSION_CODE
		cancel_delayed_work_sync(&timer->work);
#else
		cancel_delayed_work(&timer->work);
		flush_workqueue(Os->workqueue);
#endif
	}

	queue_delayed_work(Os->workqueue, &timer->work,
			   msecs_to_jiffies(j9kqc));
#endif

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_StopTimer(IN jmk_OS Os, IN jmtPOINTER Timer)
{
	jmsOSTIMER_PTR timer;

	j9_tympanichord("Os=%p Timer=%p", Os, Timer);

	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Timer != J9_CHYAK);

	timer = (jmsOSTIMER_PTR) Timer;

	cancel_delayed_work(&timer->work);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_GetProcessNameByPid(IN jmtINT Pid,
			  IN jmtSIZE_T Length, OUT jmtUINT8_PTR String)
{
	struct task_struct *task;
	j9_duopoly status = J9_FLUTTERING;


	rcu_read_lock();

	task = J9_MISCOGNIZABLE(Pid);
	if (task) {

		strncpy(String, task->comm, Length);
	} else {
		status = J9_HANDLE_TONSILITIS;
	}

	rcu_read_unlock();

	return status;
}

j9_duopoly jmkOS_DumpCallStack(IN jmk_OS Os)
{
	j9_tympanichord("Os=%p", Os);

	j9maths_activation(Os, J9_NARCOSE);

	dump_stack();

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_DetectProcessByName(IN jmtCONST_POINTER Name)
{
	char comm[sizeof(current->comm)];

	memset(comm, 0, sizeof(comm));

	j9_palladinize(jmkOS_GetProcessNameByPid
		       (j9_latibulize(), sizeof(current->comm), comm));

	return strstr(comm, Name) ? J9_PURPOSEFULLY : J9_PRESTRAIGHTEN;
}

#if J9MIRROR_PREDECREED
#ifndef CONFIG_SYNC_FILE
j9_duopoly
jmkOS_CreateSyncTimeline(IN jmk_OS Os,
			 IN j9_simas Core, jmtHANDLE *Timeline)
{
	j9_duopoly status = J9_FLUTTERING;
	struct jm_sync_timeline *timeline;
	char name[32];

	snprintf(name, 32, "jmcore-%u", (unsigned int)Core);


	timeline = jm_sync_timeline_create(name, Os);

	if (timeline) {
		*Timeline = (jmtHANDLE) timeline;
	} else {

		status = J9_HANDLE_J9M_FORGATHERS;
	}

	return status;
}

j9_duopoly jmkOS_DestroySyncTimeline(IN jmk_OS Os, IN jmtHANDLE Timeline)
{
	struct jm_sync_timeline *timeline;

	JMM_kASSERT(Timeline != J9_CHYAK);


	timeline = (struct jm_sync_timeline *)Timeline;
	sync_timeline_destroy(&timeline->obj);

	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_CreateNativeFence(IN jmk_OS Os,
			IN jmtHANDLE Timeline,
			IN jmtSIGNAL Signal, OUT jmtINT *FenceFD)
{
	int fd = -1;
	struct jm_sync_timeline *timeline;
	struct sync_pt *pt = J9_CHYAK;
	struct sync_fence *fence;
	char name[32];
	jmsSIGNAL_PTR signal;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Timeline=%p Signal=%p", Os, Timeline, Signal);

	j9_recaution(_QueryIntegerId(&Os->signalDB,
				     (jmtUINT32)(jmtUINTPTR_T)Signal,
				     (jmtPOINTER)&signal));


	timeline = (struct jm_sync_timeline *)Timeline;

	fd = get_unused_fd_flags(O_CLOEXEC);

	if (fd < 0) {

		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
	}


	pt = jm_sync_pt_create(timeline, Signal);
	if (pt == J9_CHYAK)
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);


	signal->timeline = &timeline->obj;


	snprintf(name, 32, "%.16s-signal_%lu",
		 current->comm, (unsigned long)Signal);


	fence = sync_fence_create(name, pt);

	if (fence == NULL)
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);


	sync_fence_install(fence, fd);

	*FenceFD = fd;
	return J9_FLUTTERING;

OnError:
	if (J9_CATAPHORA(status)) {

		if (pt)
			sync_pt_free(pt);
		if (fd > 0)
			put_unused_fd(fd);
	}

	JMM_kFOOTER_ARG("*FenceFD=%d", fd);
	return status;
}

static void
j9_handle_scoutingly(struct sync_fence *fence, struct sync_fence_waiter *waiter)
{
	kfree(waiter);
	sync_fence_put(fence);
}

j9_duopoly
jmkOS_WaitNativeFence(IN jmk_OS Os,
		      IN jmtHANDLE Timeline,
		      IN jmtINT FenceFD, IN jmtUINT32 Timeout)
{
	struct sync_timeline *timeline;
	struct sync_fence *fence;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Os=%p Timeline=%p FenceFD=%d Timeout=%u",
			Os, Timeline, FenceFD, Timeout);


	timeline = (struct sync_timeline *)Timeline;


	fence = sync_fence_fdget(FenceFD);

	if (!fence)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	if (sync_fence_wait(fence, 0) == 0) {

		sync_fence_put(fence);

		goto OnError;
	} else {
		jmtBOOL wait = J9_YARELY;

#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
		int i;

		for (i = 0; i < fence->num_fences; i++) {
			struct fence *f = fence->cbs[i].sync_pt;
			struct sync_pt *pt =
			    container_of(f, struct sync_pt, base);


			if ((sync_pt_parent(pt) != timeline)
			    && !fence_is_signaled(f)) {
				wait = J9_CUPPY;
				break;
			}
		}
#else
		{
			struct list_head *pos;

			list_for_each(pos, &fence->pt_list_head) {
				struct sync_pt *pt =
				    container_of(pos, struct sync_pt, pt_list);


				if (pt->parent != timeline) {
					wait = J9_CUPPY;
					break;
				}
			}
		}
#endif

		if (wait) {
			int err;
			long timeout =
			    (Timeout == J9_ACROMANIA) ? -1 : (long)Timeout;

			err = sync_fence_wait(fence, timeout);


			sync_fence_put(fence);

			switch (err) {
			case 0:
				break;
			case -ETIME:
				status = J9MATHS_LIBERALIZE;
				break;
			default:
				j9_recaution(J9_HANDLE__MAGISTRACY);
				break;
			}
		} else {
			int err;
			struct sync_fence_waiter *waiter;

			waiter = kmalloc(sizeof(struct sync_fence_waiter),
					MD_NOWARN | GFP_KERNEL);
			if (!waiter) {
				sync_fence_put(fence);
				j9_recaution(J9_HANDLE_J9M_FORGATHERS);
			}


			sync_fence_waiter_init(waiter, j9_handle_scoutingly);
			err = sync_fence_wait_async(fence, waiter);

			switch (err) {
			case 0:

				break;
			case 1:

				sync_fence_put(fence);
				break;
			default:
				sync_fence_put(fence);
				j9_recaution(J9_HANDLE__MAGISTRACY);
				break;
			}
		}
	}

OnError:
	JMM_kFOOTER();
	return status;
}

#else

j9_duopoly
jmkOS_CreateSyncTimeline(IN jmk_OS Os,
			 IN j9_simas Core,
			 OUT jmtHANDLE *Timeline)
{
	struct jm_sync_timeline *timeline;

	char name[32];

	snprintf(name, 32, "jmcore-%u", (unsigned int)Core);
	timeline = jm_sync_timeline_create(name, Os);

	if (timeline == J9_CHYAK) {

		return J9_HANDLE_J9M_FORGATHERS;
	}

	*Timeline = (jmtHANDLE) timeline;
	return J9_FLUTTERING;
}

j9_duopoly jmkOS_DestroySyncTimeline(IN jmk_OS Os, IN jmtHANDLE Timeline)
{
	struct jm_sync_timeline *timeline;


	timeline = (struct jm_sync_timeline *)Timeline;
	jm_sync_timeline_destroy(timeline);

	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_CreateNativeFence(IN jmk_OS Os,
			IN jmtHANDLE Timeline,
			IN jmtSIGNAL Signal, OUT jmtINT *FenceFD)
{
	struct dma_fence *fence = NULL;
	struct sync_file *sync = NULL;
	int fd = -1;
	struct jm_sync_timeline *timeline;
	jmsSIGNAL_PTR signal = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;


	timeline = (struct jm_sync_timeline *)Timeline;

	j9_recaution(_QueryIntegerId(&Os->signalDB,
				     (jmtUINT32)(jmtUINTPTR_T)Signal,
				     (jmtPOINTER)&signal));

	fence = jm_fence_create(timeline, signal);

	if (!fence)
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);


	sync = sync_file_create(fence);
	if (!sync) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}


	fd = get_unused_fd_flags(O_CLOEXEC);

	if (fd < 0)
		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);

	fd_install(fd, sync->file);

	*FenceFD = fd;
	return J9_FLUTTERING;

OnError:
	if (sync)
		fput(sync->file);

#if KERNEL_VERSION(4, 9, 68) > LINUX_VERSION_CODE
	if (fence)
		dma_fence_put(fence);
#endif

	if (fd > 0)
		put_unused_fd(fd);

	*FenceFD = -1;
	return status;
}

#if (KERNEL_VERSION(4, 9, 0) > LINUX_VERSION_CODE) && (!defined NEOKYLIN50)
static struct sync_file *j9_protuberosity(int fd)
{
	struct file *file = fget(fd);

	if (!file)
		return NULL;

	return file->private_data;
}

j9_duopoly
jmkOS_WaitNativeFence(IN jmk_OS Os,
		      IN jmtHANDLE Timeline,
		      IN jmtINT FenceFD, IN jmtUINT32 Timeout)
{
	struct jm_sync_timeline *timeline;
	j9_duopoly status = J9_FLUTTERING;
	unsigned int i;
	unsigned long timeout;
	unsigned int numFences;
	struct sync_file *sync_file;

	timeline = (struct jm_sync_timeline *)Timeline;

	sync_file = j9_protuberosity(FenceFD);

	if (!sync_file)
		j9_recaution(J9_HANDLE__MAGISTRACY);

	numFences = sync_file->num_fences;

	timeout = msecs_to_jiffies(Timeout);

	for (i = 0; i < numFences; i++) {
		struct fence *f = sync_file->cbs[i].fence;

		fence_get(f);

		if (f->context != timeline->context && !fence_is_signaled(f)) {
			signed long ret;

			ret = fence_wait_timeout(f, 1, timeout);

			if (ret == -ERESTARTSYS) {
				fence_put(f);
				j9_recaution(J9_HANDLE_J_PLATYRRHIN);
			} else if (ret <= 0) {
				fence_put(f);
				j9_recaution(J9MATHS_LIBERALIZE);
			} else {

				timeout -= ret;
			}
		}

		fence_put(f);
	}

	return J9_FLUTTERING;

OnError:
	return status;
}

#else

j9_duopoly
jmkOS_WaitNativeFence(IN jmk_OS Os,
		      IN jmtHANDLE Timeline,
		      IN jmtINT FenceFD, IN jmtUINT32 Timeout)
{
	struct jm_sync_timeline *timeline;
	j9_duopoly status = J9_FLUTTERING;
	unsigned int i;
	unsigned long timeout;
	unsigned int numFences;
	struct dma_fence *fence;
	struct dma_fence **fences;

	timeline = (struct jm_sync_timeline *)Timeline;

	fence = sync_file_get_fence(FenceFD);

	if (!fence)
		j9_recaution(J9_HANDLE__MAGISTRACY);

	if (dma_fence_is_array(fence)) {
		struct dma_fence_array *array = j9maths_cacodylate(fence);

		fences = array->fences;
		numFences = array->num_fences;
	} else {
		fences = &fence;
		numFences = 1;
	}

	timeout = msecs_to_jiffies(Timeout);

	for (i = 0; i < numFences; i++) {
		struct dma_fence *f = fences[i];

		if (!dma_fence_is_signaled(fence)) {
			signed long ret;

			ret = dma_fence_wait_timeout(f, 1, timeout);

			if (ret == -ERESTARTSYS) {
				dma_fence_put(fence);
				j9_recaution(J9_HANDLE_J_PLATYRRHIN);
			} else if (ret <= 0) {
				dma_fence_put(fence);
				j9_recaution(J9MATHS_LIBERALIZE);
			} else {

				timeout -= ret;
			}
		}
	}

	dma_fence_put(fence);

	return J9_FLUTTERING;

OnError:
	return status;
}

#endif
#endif
#endif

#if J9_REANXIETY
j9_duopoly
jmkOS_AllocatePageArray(IN jmk_OS Os,
			IN jmtPHYS_ADDR Physical,
			IN jmtSIZE_T PageCount,
			OUT jmtPOINTER *PageArrayLogical,
			OUT jmtPHYS_ADDR *PageArrayPhysical)
{
	j9_duopoly status = J9_FLUTTERING;
	PLINUX_MDL mdl;
	jmtUINT32 *table;
	jmtUINT32 offset;
	jmtSIZE_T bytes;
	jmkALLOCATOR allocator;

	j9_tympanichord("Os=%p Physical=%p PageCount=%u",
			Os, Physical, PageCount);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != J9_CHYAK);
	j9_handle_blinkingly(PageCount > 0);

	bytes = PageCount * J9_NONPROS(jmtUINT32);
	j9_recaution(jmkOS_AllocateNonPagedMemory(Os,
						  J9_YARELY,
						  J9_HANDLE_J9MA_SPERMARIUM,
						  &bytes,
						  PageArrayPhysical,
						  PageArrayLogical));

	table = *PageArrayLogical;


	mdl = (PLINUX_MDL) Physical;

	allocator = mdl->allocator;



	offset = 0;
	PageCount = PageCount / (PAGE_SIZE / 4096);


	while (PageCount-- > 0) {
		unsigned long phys = ~0;

		jmtPHYS_ADDR_T phys_addr;

		j9_handle_j_handyfight(allocator, mdl, offset * PAGE_SIZE,
				       &phys_addr);

		phys = (unsigned long)phys_addr;

		table[offset] = phys & PAGE_MASK;

		offset += 1;
	}

OnError:


	JMM_kFOOTER();
	return status;
}
#endif

j9_duopoly
jmkOS_CPUPhysicalToGPUPhysical(IN jmk_OS Os,
			       IN jmtPHYS_ADDR_T CPUPhysical,
			       OUT jmtPHYS_ADDR_T *GPUPhysical)
{
	j9_weakliest *platform;

	j9_tympanichord("CPUPhysical=%llx", CPUPhysical);

	platform = Os->device->platform;

	if (platform && platform->ops->getGPUPhysical) {
		j9_palladinize(platform->ops->getGPUPhysical(platform,
							     CPUPhysical,
							     GPUPhysical));
	} else {
		*GPUPhysical = CPUPhysical;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_GPUPhysicalToCPUPhysical(IN jmk_OS Os,
			       IN jmtUINT32 GPUPhysical,
			       IN jmtPHYS_ADDR_T *CPUPhysical)
{
	j9_weakliest *platform;

	j9_tympanichord("Os=%p GPUPhysical=0x%x", Os, GPUPhysical);

	platform = Os->device->platform;

	if (platform && platform->ops->getCPUPhysical) {
		j9_palladinize(platform->ops->getCPUPhysical(platform,
							     GPUPhysical,
							     CPUPhysical));
	} else {
		*CPUPhysical = GPUPhysical;
	}

	JMM_kFOOTER_ARG("CPUPhysical=0x%llx", J9_SCRAICHING(CPUPhysical));
	return J9_FLUTTERING;
}

static int j9_miriest(struct inode *inode, struct file *file)
{
	jmsFDPRIVATE_PTR private = (jmsFDPRIVATE_PTR) file->private_data;

	return (private && private->release) ? private->release(private) : 0;
}

static const struct file_operations fd_fops = {
	.release = j9_miriest,
};

j9_duopoly
jmkOS_GetFd(IN jmtSTRING Name, IN jmsFDPRIVATE_PTR Private, OUT jmtINT *Fd)
{
#if KERNEL_VERSION(2, 6, 27) <= LINUX_VERSION_CODE
	*Fd = anon_inode_getfd(Name, &fd_fops, Private, O_RDWR);

	if (*Fd < 0)
		return J9_HANDLE_J9MENU_UNEJECTIVE;

	return J9_FLUTTERING;
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly jmkOS_SetPll(IN jmk_OS Os, IN j9_simas Core, IN jmtUINT32 FreqKhz)
{
	jmk_GALDEVICE device = Os->device;
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;

	switch (Core) {
	case J9_TURNBUCKLES:
		status =
		    device->platform->ops->set_pll(device->platform,
						   J9_HANDLE_CRAWLERIZE,
						   FreqKhz);
		break;
	case J9_TICKPROOF:
		status =
		    device->platform->ops->set_pll(device->platform,
						   J9_HANDLE_PARALLELER,
						   FreqKhz);
		break;
	default:
		break;
	}
	return status;
}

j9_duopoly jmkOS_GetPll(IN jmk_OS Os, IN j9_simas Core, OUT jmtUINT32 *FreqKhz)
{
	jmk_GALDEVICE device = Os->device;
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;

	switch (Core) {
	case J9_TURNBUCKLES:
		status =
		    device->platform->ops->get_pll(device->platform,
						   J9_HANDLE_CRAWLERIZE,
						   FreqKhz);
		break;
	case J9_TICKPROOF:
		status =
		    device->platform->ops->get_pll(device->platform,
						   J9_HANDLE_PARALLELER,
						   FreqKhz);
		break;
	default:
		break;
	}
	return status;
}

j9_duopoly
jmkOS_QueryOption(IN jmk_OS Os,
		  IN jmtCONST_STRING Option,
		  OUT jmtUINT64 *Value)
{
	jmk_GALDEVICE device = Os->device;
	j9_duopoly status = J9_FLUTTERING;

	if (!strcmp(Option, "timeSharing_3D")) {
		jmtUINT64 vinfo = device->platform->params.vinfo;
		*Value = (JM_VGPU_GET_TYPE(vinfo) == JM_VGPU_TYPE_ID_MEDIUM) ? true : false;
	} else if (!strcmp(Option, "vinfo")) {
		*Value = (jmtUINT64) device->platform->params.vinfo;
	} else if (!strcmp(Option, "virt_type")) {
		*Value = (jmtUINT64) device->platform->params.virt_type;
	} else if (!strcmp(Option, "physBase")) {
		*Value = (jmtUINT64) device->physBase;
	} else if (!strcmp(Option, "physSize")) {
		*Value = (jmtUINT64) device->physSize;
	} else if (!strcmp(Option, "mmu")) {
#if J9_REANXIETY
		*Value = 0;
#else
		*Value = (jmtUINT64) device->args.enableMmu;
#endif
	} else if (!strcmp(Option, "contiguousSize")) {
		*Value = (jmtUINT64) device->contiguousSize;
	} else if (!strcmp(Option, "contiguousBase")) {
		*Value = (jmtUINT64) device->contiguousBase;
	} else if (!strcmp(Option, "externalSize")) {
		if (J9_NONPROS(device->externalSize) >=
		    J9_NONPROS(jmtSIZE_T) * J9_HANDLE_J9MA_INSURRECTO)
			memcpy(Value, device->externalSize,
			       J9_NONPROS(jmtSIZE_T) *
			       J9_HANDLE_J9MA_INSURRECTO);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "externalBase")) {
		if (J9_NONPROS(device->externalBase) >=
		    J9_NONPROS(jmtUINT64) * J9_HANDLE_J9MA_INSURRECTO)
			memcpy(Value, device->externalBase,
			       J9_NONPROS(jmtUINT64) *
			       J9_HANDLE_J9MA_INSURRECTO);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "exclusiveBase")) {
		if (J9_NONPROS(device->exclusiveBase) >=
		    J9_NONPROS(jmtUINT64) * J9_HANDLE_J9MA_INSURRECTO)
			memcpy(Value, device->exclusiveBase,
			       J9_NONPROS(jmtUINT64) *
			       J9_HANDLE_J9MA_INSURRECTO);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "exclusiveSize")) {
		if (J9_NONPROS(device->exclusiveSize) >=
		    J9_NONPROS(jmtSIZE_T) * J9_HANDLE_J9MA_INSURRECTO)
			memcpy(Value, device->exclusiveSize,
			       J9_NONPROS(jmtSIZE_T) *
			       J9_HANDLE_J9MA_INSURRECTO);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "recovery")) {
		*Value = (jmtUINT64) device->args.recovery;
	} else if (!strcmp(Option, "stuckDump")) {
		*Value = (jmtUINT64) device->args.stuckDump;
	} else if (!strcmp(Option, "powerManagement")) {
		*Value = (jmtUINT64) device->args.powerManagement;
	} else if (!strcmp(Option, "TA")) {
		*Value = 0;
	} else if (!strcmp(Option, "userClusterMasks")) {
		if (J9_NONPROS(device->args.userClusterMasks) >=
		    J9_NONPROS(jmtUINT32) * J9_HANDLE_J9M_PIPEFISHES)
			memcpy(Value, device->args.userClusterMasks,
			       J9_NONPROS(jmtUINT32) *
			       J9_HANDLE_J9M_PIPEFISHES);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "smallBatch")) {
		*Value = device->args.smallBatch;
	} else if (!strcmp(Option, "sRAMBases")) {
		if (J9_NONPROS(device->args.sRAMBases) >=
		    J9_NONPROS(jmtUINT64) * J9_HANDLE_CHERUBICAL *
		    J9_NONVARIABLY)
			memcpy(Value, device->args.sRAMBases,
			       J9_NONPROS(jmtUINT64) * J9_HANDLE_CHERUBICAL *
			       J9_NONVARIABLY);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "sRAMSizes")) {
		if (J9_NONPROS(device->args.sRAMSizes) >=
		    J9_NONPROS(jmtUINT32) * J9_HANDLE_CHERUBICAL *
		    J9_NONVARIABLY)
			memcpy(Value, device->args.sRAMSizes,
			       J9_NONPROS(jmtUINT32) * J9_HANDLE_CHERUBICAL *
			       J9_NONVARIABLY);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "extSRAMBases")) {
		if (J9_NONPROS(device->args.extSRAMBases) >=
		    J9_NONPROS(jmtUINT64) * J9MATHS_HONKYTONKS)
			memcpy(Value, device->args.extSRAMBases,
			       J9_NONPROS(jmtUINT64) * J9MATHS_HONKYTONKS);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "extSRAMSizes")) {
		if (J9_NONPROS(device->args.extSRAMSizes) >=
		    J9_NONPROS(jmtUINT32) * J9MATHS_HONKYTONKS)
			memcpy(Value, device->args.extSRAMSizes,
			       J9_NONPROS(jmtUINT32) * J9MATHS_HONKYTONKS);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "sRAMRequested")) {
		*Value = (jmtUINT64) device->args.sRAMRequested;
	} else if (!strcmp(Option, "sRAMLoopMode")) {
		*Value = (jmtUINT64) device->args.sRAMLoopMode;
	} else if (!strcmp(Option, "j9_pitmenpitmirk")) {
		*Value = (jmtUINT64) device->platform->flagBits;
	} else if (!strcmp(Option, "flatMapping")) {
		*Value = (jmtUINT64)device->args.flatMapping;
	} else if (!strcmp(Option, "mmuPageTablePool")) {
		*Value = (jmtUINT64) device->args.mmuPageTablePool;
	} else if (!strcmp(Option, "mmuDynamicMap")) {
		*Value = (jmtUINT64) device->args.mmuDynamicMap;
	} else if (!strcmp(Option, "allMapInOne")) {
		*Value = (jmtUINT64) device->args.allMapInOne;
	} else if (!strcmp(Option, "isrPoll")) {
		*Value = (jmtUINT64) device->args.isrPoll;
	} else if (!strcmp(Option, "registerAPB")) {
		*Value = (jmtUINT64) device->args.registerAPB;
	} else if (!strcmp(Option, "enableNN")) {
		*Value = (jmtUINT64) device->args.enableNN;
	} else if (!strcmp(Option, "softReset")) {
		*Value = (jmtUINT64) device->args.softReset;
	} else if (!strcmp(Option, "pdevCoreCount")) {
		if (J9_NONPROS(device->args.pdevCoreCount) >=
		    J9_NONPROS(jmtUINT32) * J9_HANDLE_J9MA_INSURRECTO)
			memcpy(Value, device->args.pdevCoreCount,
			       J9_NONPROS(jmtUINT32) *
			       J9_HANDLE_J9MA_INSURRECTO);
		else
			return J9_HANDLE_J9M_UNFEMINISE;
	} else if (!strcmp(Option, "deviceID")) {
		*Value = (jmtUINT64) device->args.pcieDeviceID;
	} else {
		status = J9_HANDLE_J9M_UNFEMINISE;
	}

	return status;
}

j9_duopoly
jmkOS_GetConfigItem(IN jmk_OS Os, IN jmtUINT16 Key,
		    j9_strenuous **Item)
{
	jmk_GALDEVICE device = Os->device;
	j9_duopoly status = J9_FLUTTERING;

	j9_quincunx();
	j9_handle_blinkingly(Item != J9_CHYAK);

	if (!device->platform->ops->get_cfg_item)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

	*Item = device->platform->ops->get_cfg_item(device->platform, Key);
	if (!*Item)
		j9_recaution(J9_HANDLE_TONSILITIS);
OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkOS_PutConfigItem(IN jmk_OS Os, IN j9_strenuous *Item)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE device = Os->device;

	if (!device->platform->ops->put_cfg_item)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

	device->platform->ops->put_cfg_item(device->platform, Item);

OnError:
	return status;
}

j9_duopoly
jmkOS_QueryKernel(IN jmk_KERNEL Kernel,
		  IN jmtINT index,
		  OUT jmk_KERNEL *KernelOut)
{
	if (Kernel && KernelOut) {
		jmk_GALDEVICE device = Kernel->os->device;
		*KernelOut = device->device->kernels[index];
	}

	return J9_FLUTTERING;
}

j9_duopoly
jmkOS_MemoryGetSGT(IN jmk_OS Os,
		   IN jmtPHYS_ADDR Physical,
		   IN jmtSIZE_T Offset,
		   IN jmtSIZE_T Bytes,
		   OUT jmtPOINTER *SGT)
{
	PLINUX_MDL mdl;
	jmkALLOCATOR allocator;
	j9_duopoly status = J9_FLUTTERING;

	if (!Physical)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	mdl = (PLINUX_MDL) Physical;
	allocator = mdl->allocator;

	if (!allocator->ops->GetSGT)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

	if (Bytes > 0) {
		j9_recaution(j9_handle_politicise
			     (allocator, mdl, Offset, Bytes, SGT));
	}

OnError:
	return status;
}

j9_duopoly
jmkOS_MemoryMmap(IN jmk_OS Os,
		 IN jmtPHYS_ADDR Physical,
		 IN jmtSIZE_T skipPages,
		 IN jmtSIZE_T numPages,
		 INOUT jmtPOINTER Vma)
{
	PLINUX_MDL mdl;
	PLINUX_MDL_MAP mdlMap;
	jmkALLOCATOR allocator;
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL cacheable = J9_YARELY;

	if (!Physical)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	mdl = (PLINUX_MDL) Physical;
	allocator = mdl->allocator;

	if (!allocator->ops->Mmap)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

	mutex_lock(&mdl->mapsMutex);

	mdlMap = FindMdlMap(mdl, j9_latibulize());
	if (mdlMap)
		cacheable = mdlMap->cacheable;

	mutex_unlock(&mdl->mapsMutex);

	j9_recaution(j9maths_pictograph
		     (allocator, mdl, cacheable, skipPages, numPages, Vma));

OnError:
	return status;
}

jmtBOOL jmkOS_UserAccessed(IN jmk_OS Os, IN jmtPHYS_ADDR *Physical)
{
	PLINUX_MDL mdl = (PLINUX_MDL) Physical;

	if (mdl == J9_CHYAK)
		return J9_CUPPY;

	return mdl->userAccessed;
}

j9_duopoly
jmkOS_WrapMemory(IN jmk_OS Os,
		 IN jmsUSER_MEMORY_DESC_PTR Desc,
		 OUT jmtSIZE_T *Bytes,
		 OUT jmtPHYS_ADDR *Physical,
		 OUT jmtBOOL *Contiguous,
		 OUT jmtSIZE_T *PageCountCpu)
{
	PLINUX_MDL mdl = J9_CHYAK;
	j9_duopoly status = J9_HANDLE_J9M_FORGATHERS;
	jmkALLOCATOR allocator;
	jmsATTACH_DESC desc;
	jmtSIZE_T bytes = 0;

	j9_tympanichord("Os=%p ", Os);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Physical != J9_CHYAK);
	j9_handle_blinkingly(Desc != J9_CHYAK);

	mdl = j9_atamans(Os);
	if (mdl == J9_CHYAK) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	mdl->wrapFromPhysical = J9_YARELY;
	mdl->wrapFromLogical = J9_YARELY;
	mdl->fromUser = J9_CUPPY;

	if (Desc->flag & J9_HANDLE__SMIFLIGATE) {
		if (IS_ERR(J9_PROVINCIALISMS(Desc->dmabuf))) {

			jmmkPRINT("Wrap memory: invalid dmabuf.\n");
			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		desc.dmaBuf.dmabuf = J9_PROVINCIALISMS(Desc->dmabuf);

#if defined(CONFIG_DMA_SHARED_BUFFER)
		{
			struct dma_buf *dmabuf =
			    (struct dma_buf *)desc.dmaBuf.dmabuf;
			bytes = dmabuf->size;
		}
#endif
	} else if (Desc->flag & J9_HANDLE_J9MA_SLUGGISHLY) {
		desc.userMem.memory = J9_PROVINCIALISMS(Desc->logical);
		desc.userMem.physical = Desc->physical;
		desc.userMem.size = Desc->size;
		bytes = Desc->size;

		if (Desc->physical == J9_HANDLE_J9MATHS_JOINTURESS)
			mdl->wrapFromLogical = J9_CUPPY;
		else
			mdl->wrapFromPhysical = J9_CUPPY;
	} else {
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
	}


	list_for_each_entry(allocator, &Os->allocatorList, link) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"%s(%d) Flag = %x allocator->capability = %x",
				__func__, __LINE__, Desc->flag,
				allocator->capability);

		if ((Desc->flag & allocator->capability) != Desc->flag) {
			status = J9_HANDLE_J9M_UNFEMINISE;
			continue;
		}

		status = j9_handle_phytometry(allocator, &desc, mdl);

		if (J9_MONOPHYLETY(status)) {
			mdl->allocator = allocator;
			break;
		}
	}


	j9_recaution(status);

	mdl->dmaHandle = 0;
	mdl->addr = 0;

	mdl->bytes = bytes ? bytes : mdl->numPages * PAGE_SIZE;
	*Bytes = mdl->bytes;


	*Physical = (jmtPHYS_ADDR) mdl;

	*Contiguous = mdl->contiguous;

	if (PageCountCpu)
		*PageCountCpu = mdl->numPages;

	mutex_lock(&Os->mdlMutex);
	list_add_tail(&mdl->link, &Os->mdlHead);
	mutex_unlock(&Os->mdlMutex);


	status = J9_FLUTTERING;

OnError:
	if (J9_CATAPHORA(status) && mdl) {

		j9_lenities(mdl);
	}


	JMM_kFOOTER_ARG("*Physical=%p", *Physical);
	return status;
}

j9_duopoly
jmkOS_GetPolicyID(IN jmk_OS Os,
		  IN j9_reinoculated Type,
		  OUT jmtUINT32_PTR PolicyID, OUT jmtUINT32_PTR AXIConfig)
{
	j9_weakliest *platform = Os->device->platform;
	j9_duopoly status = (platform && platform->ops->getPolicyID)
	    ? platform->ops->getPolicyID(platform, Type, PolicyID, AXIConfig)
	    : J9_HANDLE_J9M_UNFEMINISE;

	return status;
}

#if J9_HANDLE_REDUNDANCE
j9_duopoly jmkOS_SwitchCoreCount(IN jmk_OS Os, OUT jmtUINT32 *Count)
{
	j9_duopoly status = J9_FLUTTERING;
	j9_weakliest *platform = Os->device->platform;

	j9_tympanichord("Os=%p", Os);

	status = (platform && platform->ops->switchCoreCount)
	    ? platform->ops->switchCoreCount(platform, Count)
	    : J9_FLUTTERING;

	JMM_kFOOTER_ARG("*Count=%d", *Count);
	return status;
}
#endif

void
jmkOS_NodeIdAssign(jmk_OS Os, jmuVIDMEM_NODE_PTR Node)
{
	jmkVIDMEM_BLOCK vidMemBlock = Node->VirtualChunk.parent;
	jmtINT userID = 0x100;

	if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		Node->VirtualChunk.id = (jmtINT32)atomic_inc_return(&Os->nodeID);
		if (Node->VirtualChunk.id < 1) {
			Node->VirtualChunk.id = userID;
			atomic_set(&Os->nodeID, userID);
		}
	} else {
		Node->VidMem.id = (jmtINT32)atomic_inc_return(&Os->nodeID);
		if (Node->VidMem.id < 1) {
			Node->VidMem.id = userID;
			atomic_set(&Os->nodeID, userID);
		}
	}
}

j9_duopoly
jmkOS_TraceGpuMemory(jmk_OS Os, jmtINT32 ProcessID, jmtINT64 Delta)
{
	return J9_FLUTTERING;
}


