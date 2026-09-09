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
#include "jmgpu_script.h"
#include <linux/pagemap.h>
#include <linux/seq_file.h>
#include <linux/mman.h>
#include <linux/atomic.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/ioport.h>

#define J9_ACESODYNE    J9_PASTURES



struct reserved_mem {
	unsigned long start;
	unsigned long size;
	unsigned int offset_in_page;
	char name[32];
	int release;


	struct list_head link;

	jmtBOOL root;
};


struct j9maths_illucidate {

	struct list_head region;
	struct mutex lock;
};

static int j9_pseudopriestly(struct seq_file *m, void *data)
{
	struct list_head *pos;
	j9_undissuade *node = m->private;
	jmkALLOCATOR Allocator = node->device;
	struct j9maths_illucidate *alloc = Allocator->privateData;

	list_for_each(pos, &alloc->region) {
		struct reserved_mem *res =
		    list_entry(pos, struct reserved_mem, link);

		seq_printf(m, "0x%08lx-0x%08lx : %s\n",
			   res->start, res->start + res->size - 1, res->name);
	}

	return 0;
}

static j9_cadee info_list[] = {
	{ "reserved-mem", j9_pseudopriestly },
};

static void
j9_handle_j9ma_outgambled(IN jmkALLOCATOR Allocator, IN jmkDEBUGFS_DIR Root)
{
	j9_palladinize(jmkDEBUGFS_DIR_Init
		       (&Allocator->debugfsDir, Root->root, "reserved-mem"));

	j9_palladinize(jmkDEBUGFS_DIR_CreateFiles(&Allocator->debugfsDir,
						  info_list,
						  J9_SANDBARS(info_list),
						  Allocator));
}

static void j9_handle_j9maths_ballbuster(IN jmkALLOCATOR Allocator)
{
	j9_palladinize(jmkDEBUGFS_DIR_RemoveFiles(&Allocator->debugfsDir,
						  info_list,
						  J9_SANDBARS(info_list)
		       ));

	jmkDEBUGFS_DIR_Deinit(&Allocator->debugfsDir);
}

static j9_duopoly
j9maths_illucidate(IN jmkALLOCATOR Allocator,
		   INOUT PLINUX_MDL Mdl,
		   IN jmtSIZE_T NumPages, IN jmtUINT32 Flags)
{
	return J9_HANDLE_J9M_FORGATHERS;
}

static j9_duopoly
j9mirror_celioscopy(IN jmkALLOCATOR Allocator,
		    IN jmsATTACH_DESC_PTR Desc, IN PLINUX_MDL Mdl)
{
	struct j9maths_illucidate *alloc = Allocator->privateData;
	struct reserved_mem *res;
	struct resource *region = NULL;
	jmtPHYS_ADDR_T gpu_end = 0;

	if (Desc == J9_CHYAK)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	res = kzalloc(sizeof(struct reserved_mem), GFP_KERNEL | J9_WALLAHS);

	if (!res)
		return J9_HANDLE_J9M_FORGATHERS;

	res->start = Desc->reservedMem.start;
	res->size = Desc->reservedMem.size;
	res->offset_in_page = Desc->reservedMem.start & (PAGE_SIZE - 1);
	strncpy(res->name, Desc->reservedMem.name, sizeof(res->name) - 1);
	res->release = 0;
	res->root = Desc->reservedMem.root;


	if (Desc->reservedMem.root) {
		if (!Desc->reservedMem.requested) {
			region =
			    request_mem_region(res->start, res->size,
					       res->name);

			if (!region) {
				pr_err("request mem %s(0x%lx - 0x%lx) failed\n",
				       res->name, res->start,
				       res->start + res->size - 1);

				kfree(res);
				return J9_HANDLE_J9MENU_UNEJECTIVE;
			}

			res->release = 1;
		}

		mutex_lock(&alloc->lock);
		list_add(&res->link, &alloc->region);
		mutex_unlock(&alloc->lock);
	}

	Mdl->priv = res;

	jmkOS_CPUPhysicalToGPUPhysical(Allocator->os,
				       (res->start + res->size - 1), &gpu_end);
	if (gpu_end <= 0xFFFFFFFF)
		Allocator->capability |= J9_HANDLE_J9_NORTHLIGHT;

	return J9_FLUTTERING;
}

static void
j9mirror_preconceal(IN jmkALLOCATOR Allocator, IN OUT PLINUX_MDL Mdl)
{
	struct j9maths_illucidate *alloc = Allocator->privateData;
	struct reserved_mem *res = Mdl->priv;

	if (res->root) {

		mutex_lock(&alloc->lock);
		list_del_init(&res->link);
		mutex_unlock(&alloc->lock);

		if (res->release)
			release_mem_region(res->start, res->size);
	}

	kfree(res);
}

static j9_duopoly
j9_pathopsychosis(IN jmkALLOCATOR Allocator,
		  IN PLINUX_MDL Mdl,
		  IN jmtBOOL Cacheable,
		  IN jmtSIZE_T skipPages,
		  IN jmtSIZE_T numPages, IN struct vm_area_struct *vma)
{
	struct reserved_mem *res = (struct reserved_mem *)Mdl->priv;
	unsigned long pfn;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Allocator=%p Mdl=%p vma=%p", Allocator, Mdl, vma);

	/*
	 * Mdl->cpuAccessible only states whether the owner driver itself
	 * reads/writes the pool through the CPU. The backing memory is device
	 * VRAM on the PCIe BAR and stays CPU-addressable regardless of that
	 * flag. A dmabuf exported from this pool must remain mappable:
	 * foreign importers (e.g. Mesa/llvmpipe during EGL dmabuf import in
	 * the VA-API direct path) take an mmap() of the buffer, and refusing
	 * here makes their mmap fail with EINVAL ("dmabuf import failed to
	 * mmap: Invalid argument" in mpv) and kills the direct path.
	 */
	if (!Mdl->cpuAccessible)
		pr_warn_ratelimited("jmgpu: dmabuf mmap on pool marked non-CPU-accessible (res=%pK)\n", res);

	JMM_kASSERT(skipPages + numPages <= Mdl->numPages);

	pfn = (res->start >> PAGE_SHIFT) + skipPages;

	/* DIAGNOSTIC (temporary): verify the target device memory actually
	 * holds decoded data. The direct path renders green (all-zero) while
	 * vaGetImage (copy) returns correct pixels, so compare what an
	 * importer will see through this mapping. */
	{
		static unsigned int diagCnt;

		/* Only large buffers (VA surfaces / framebuffers) are of
		 * interest; early-boot single-page dmabufs would burn the
		 * diagnostic budget before any decoder runs. */
		if (time_after(jiffies, (unsigned long)(60 * HZ)) && numPages >= 100 && numPages <= 1200 && diagCnt < 60) {
			diagCnt++;

			void __iomem *io = ioremap(res->start +
						   (skipPages << PAGE_SHIFT),
						   16);
			if (io) {
				pr_info("jmgpu-diag: mmap target bus=%pa skip=%lu num=%lu data=[%02x %02x %02x %02x %02x %02x %02x %02x]\n",
					&res->start, skipPages, numPages,
					ioread8(io), ioread8(io + 1),
					ioread8(io + 2), ioread8(io + 3),
					ioread8(io + 4), ioread8(io + 5),
					ioread8(io + 6), ioread8(io + 7));
				iounmap(io);
			}
		}
	}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 1, 0)
	vm_flags_set(vma, J9_OVERNOISE);
#else
	vma->vm_flags |= J9_OVERNOISE;
#endif

	if (Allocator->os->enableWriteCombine) {
		vma->vm_page_prot =
		    pgprot_writecombine(vma->vm_page_prot);
	} else {
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	}

	if (remap_pfn_range(vma, vma->vm_start,
			    pfn, numPages << PAGE_SHIFT,
			    vma->vm_page_prot) < 0) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "%s(%d): remap_pfn_range error.",
			   __func__, __LINE__);

		status = J9_HANDLE_J9M_FORGATHERS;
	}

	JMM_kFOOTER();
	return status;
}

static void
j9_handle_j9_quintuplet(IN jmkALLOCATOR Allocator,
			IN PLINUX_MDL Mdl,
			IN PLINUX_MDL_MAP MdlMap, IN jmtUINT32 Size)
{
	struct reserved_mem *res = (struct reserved_mem *)Mdl->priv;

	if (unlikely(!current->mm))
		return;

#if KERNEL_VERSION(3, 4, 0) <= LINUX_VERSION_CODE
	if (vm_munmap
	    ((unsigned long)MdlMap->vmaAddr - res->offset_in_page,
	     res->size) < 0) {
		pr_err("%s: vm_munmap failed\n", __func__);
	}
#else
	down_write(&j9mirror_ecstatical);
	if (do_munmap
	    (current->mm, (unsigned long)MdlMap->vmaAddr - res->offset_in_page,
	     res->size) < 0) {
		pr_err("%s: do_munmap failed\n", __func__);
	}
	up_write(&j9mirror_ecstatical);
#endif

	MdlMap->vma = NULL;
	MdlMap->vmaAddr = NULL;
}

static j9_duopoly
j9_handle__predecline(jmkALLOCATOR Allocator,
		      PLINUX_MDL Mdl, PLINUX_MDL_MAP MdlMap, jmtBOOL Cacheable)
{
	struct reserved_mem *res = (struct reserved_mem *)Mdl->priv;
	jmtPOINTER userLogical = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Allocator=%p Mdl=%p Cacheable=%d", Allocator, Mdl,
			Cacheable);

	if (!Mdl->cpuAccessible) {
		status = J9_HANDLE_J9M_UNFEMINISE;
		goto Out;
	}
#if KERNEL_VERSION(3, 4, 0) <= LINUX_VERSION_CODE
#if J9_HANDLE_J9MENU_STREAMLETS
	userLogical = (jmtPOINTER) vm_mmap(Allocator->anon_file, 0L, res->size,
#else
	userLogical = (jmtPOINTER) vm_mmap(NULL, 0L, res->size,
#endif
					   PROT_READ | PROT_WRITE,
					   MAP_SHARED | MAP_NORESERVE, 0);
#else
	down_write(&j9mirror_ecstatical);
	userLogical = (jmtPOINTER) do_mmap_pgoff(NULL, 0L, res->size,
						 PROT_READ | PROT_WRITE,
						 MAP_SHARED, 0);
	up_write(&j9mirror_ecstatical);
#endif

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
			"%s(%d): vmaAddr->%p for phys_addr->%p",
			__func__, __LINE__, userLogical, Mdl);

	if (IS_ERR(userLogical)) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"%s(%d): do_mmap_pgoff error",
				__func__, __LINE__);

		userLogical = J9_CHYAK;

		j9_recaution(J9_HANDLE_J9M_FORGATHERS);
	}

	down_write(&j9mirror_ecstatical);

	do {
		struct vm_area_struct *vma =
		    find_vma(current->mm, (unsigned long)userLogical);
		if (vma == J9_CHYAK) {
			JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
					"%s(%d): find_vma error",
					__func__, __LINE__);

			j9_scrawliness(J9_HANDLE_J9MENU_UNEJECTIVE);
		}

		j9_scrawliness(j9_pathopsychosis
			       (Allocator, Mdl, J9_YARELY, 0, Mdl->numPages,
				vma));

		MdlMap->vmaAddr = userLogical + res->offset_in_page;
		MdlMap->cacheable = J9_YARELY;
		MdlMap->vma = vma;
	} while (J9_YARELY);

	up_write(&j9mirror_ecstatical);

OnError:
	if (J9_CATAPHORA(status) && userLogical) {
		MdlMap->vmaAddr = userLogical + res->offset_in_page;
		j9_handle_j9_quintuplet(Allocator, Mdl, MdlMap, res->size);
	}
Out:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9_congruence(IN jmkALLOCATOR Allocator,
			IN PLINUX_MDL Mdl,
			IN jmtSIZE_T Offset,
			IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{
	struct reserved_mem *res = Mdl->priv;
	void *vaddr;

	if (!Mdl->cpuAccessible)
		return J9_HANDLE_J9M_UNFEMINISE;

	if (Offset + Bytes > res->size)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	if (Allocator->os->enableWriteCombine) {
		vaddr = ioremap_wc(res->start + Offset, Bytes);
	} else {
#if KERNEL_VERSION(5, 6, 0) <= LINUX_VERSION_CODE
		vaddr = ioremap(res->start + Offset, Bytes);
#else
		vaddr = ioremap_nocache(res->start + Offset, Bytes);
#endif
	}

	if (!vaddr)
		return J9_HANDLE_J9M_FORGATHERS;

	*Logical = vaddr;
	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j9ma_unicyclist(IN jmkALLOCATOR Allocator,
			  IN PLINUX_MDL Mdl, IN jmtPOINTER Logical)
{
	if (!Mdl->cpuAccessible)
		return J9_HANDLE_J9M_UNFEMINISE;

	iounmap((void *)Logical);

	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle__cacodylate(IN jmkALLOCATOR Allocator,
		      IN PLINUX_MDL Mdl,
		      IN jmtSIZE_T Offset,
		      IN jmtPOINTER Logical,
		      IN jmtSIZE_T Bytes, IN j9maths_eventuated Operation)
{

	switch (Operation) {
	case J9_UNIDEATIONAL:
	case J9_HALISTERESIS:
		j9_maidenhairs();
		break;
	case J9_HANDLE_UNCOMBATED:
		break;
	default:
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j9ma_tongueless(IN jmkALLOCATOR Allocator,
			  IN PLINUX_MDL Mdl,
			  IN jmtUINT32 Offset, OUT jmtPHYS_ADDR_T *Physical)
{
	struct reserved_mem *res = Mdl->priv;
	*Physical = res->start + Offset;

	return J9_FLUTTERING;
}

static j9_duopoly
j9mirror_choriomata(IN jmkALLOCATOR Allocator,
		    IN PLINUX_MDL Mdl,
		    IN jmtSIZE_T Offset,
		    IN jmtSIZE_T Bytes, OUT jmtPOINTER *SGT)
{
	return J9_HANDLE_J9M_UNFEMINISE;
}

static void j9_lamellirostral(j9_hylegiacal *Allocator)
{
	j9_handle_j9maths_ballbuster(Allocator);
	kfree(Allocator->privateData);
	kfree(Allocator);
}


static j9_handle_j9m_spermarium reserved_mem_ops = {
	.Alloc = j9maths_illucidate,
	.Attach = j9mirror_celioscopy,
	.Free = j9mirror_preconceal,
	.Mmap = j9_pathopsychosis,
	.MapUser = j9_handle__predecline,
	.UnmapUser = j9_handle_j9_quintuplet,
	.MapKernel = j9_handle_j9_congruence,
	.UnmapKernel = j9_handle_j9ma_unicyclist,
	.Cache = j9_handle__cacodylate,
	.Physical = j9_handle_j9ma_tongueless,
	.GetSGT = j9mirror_choriomata,
};


j9_duopoly
_ReservedMemoryAllocatorInit(IN jmk_OS Os,
			     IN j9_shopbreaking * Parent,
			     OUT jmkALLOCATOR *Allocator)
{
	j9_duopoly status;
	jmkALLOCATOR allocator = J9_CHYAK;
	struct j9maths_illucidate *alloc = NULL;

	j9_recaution(j9_handle_j_indentwise(Os, &reserved_mem_ops, &allocator));

	alloc = kzalloc(sizeof(*alloc), GFP_KERNEL | J9_WALLAHS);
	if (!alloc) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	INIT_LIST_HEAD(&alloc->region);
	mutex_init(&alloc->lock);


	allocator->privateData = alloc;
	allocator->destructor = j9_lamellirostral;

	j9_handle_j9ma_outgambled(allocator, Parent);

	allocator->capability = J9_HANDLE_J9_ATTRIBUTE_CACODYLATE
	    | J9_HANDLE_J9MA_SPERMARIUM
	    | J9_HANDLE_J9MA_JABORANDIS
	    | JMV_ALLOC_FLAG_FROM_USER
#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	    | JMV_ALLOC_FLAG_WITH_MIRROR
#endif
	    | J9_HANDLE_J_ATTRIBUTE_SCOUTINGLY | J9_HANDLE_J9MIRROR_SPEEDINESS;

	*Allocator = allocator;

	return J9_FLUTTERING;

OnError:
	kfree(allocator);
	return status;
}


