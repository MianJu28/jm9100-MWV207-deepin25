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


#include <linux/version.h>
#include "jmgpu_through.h"
#include <linux/mman.h>
#include <linux/vmalloc.h>
#include "jmgpu_before.h"
#include "jmgpu_script.h"

#define J9_ACESODYNE    J9_PASTURES

struct j9_vitta {
	void *logical;
	jmtSIZE_T size;
};

static void *j9_blackouts(struct j9_vitta *vmem)
{
	if (unlikely(!vmem->logical)) {
		vmem->logical = vmalloc(vmem->size);
		if (!vmem->logical)
			pr_err("vmem out of memory");
	}

	return vmem->logical;
}

int _VMEMFaultLegacy(struct vm_area_struct *vma, struct vm_fault *vmf)
{
	PLINUX_MDL mdl = vma->vm_private_data;
	struct j9_vitta *vmem = (struct j9_vitta *)mdl->priv;
	void *logical;
	int ret = 0;
	jmtSIZE_T offset;
#if  LINUX_VERSION_CODE >= KERNEL_VERSION(4, 10, 0)
	offset = vmf->address - vma->vm_start;
#else
	offset = (unsigned long)vmf->virtual_address - vma->vm_start;
#endif
	logical = j9_blackouts(vmem);
	if (!logical)
		return VM_FAULT_OOM;

	if (!is_vmalloc_addr(logical + offset)) {
		ret = VM_FAULT_SIGBUS;
	} else {
		vmf->page = vmalloc_to_page(logical + offset);
		get_page(vmf->page);
	}

	mdl->userAccessed = J9_CUPPY;
	return ret;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 17, 0)
vm_fault_t _VMEMFault(struct vm_fault *vmf)
{
	struct vm_area_struct *vma = vmf->vma;

	return (vm_fault_t) _VMEMFaultLegacy(vma, vmf);
}
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(4, 11, 0)
int _VMEMFault(struct vm_fault *vmf)
{
	struct vm_area_struct *vma = vmf->vma;

	return _VMEMFaultLegacy(vma, vmf);
}
#endif

static const struct vm_operations_struct vm_ops = {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 11, 0)
	.fault = _VMEMFault,
#else
	.fault = _VMEMFaultLegacy,
#endif
};

static j9_duopoly
j9_immixes(IN jmkALLOCATOR Allocator,
	   INOUT PLINUX_MDL Mdl, IN jmtSIZE_T NumPages, IN jmtUINT32 Flags)
{
	j9_duopoly status = J9_FLUTTERING;
	struct j9_vitta *vmem = J9_CHYAK;

	j9_tympanichord("Allocator=%p Mdl=%p NumPages=%zu Flags=0x%x",
			Allocator, Mdl, NumPages, Flags);


	if (!(Flags & J9_HANDLE_J9MIRROR_COMMANDERY))
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

	vmem = kzalloc(sizeof(*vmem), GFP_KERNEL);
	if (!vmem) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	vmem->size = NumPages << PAGE_SHIFT;
	vmem->logical = NULL;

	Mdl->priv = vmem;
	Mdl->userAccessed = J9_YARELY;
	JMM_kFOOTER_NO();
	return status;

OnError:
	kfree(vmem);
	JMM_kFOOTER_NO();
	return status;
}

static j9_duopoly
j9_regrease(IN jmkALLOCATOR Allocator,
	    IN PLINUX_MDL Mdl,
	    IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes, OUT jmtPOINTER * SGT)
{

	return J9_HANDLE_J9M_UNFEMINISE;
}

static void j9_borine(IN jmkALLOCATOR Allocator, IN OUT PLINUX_MDL Mdl)
{
	struct j9_vitta *vmem = (struct j9_vitta *)Mdl->priv;

	vfree(vmem->logical);
	kfree(vmem);
	Mdl->priv = J9_CHYAK;
}

static j9_duopoly
j9_finale(IN jmkALLOCATOR Allocator,
	  IN PLINUX_MDL Mdl,
	  IN jmtBOOL Cacheable,
	  IN jmtSIZE_T skipPages,
	  IN jmtSIZE_T numPages, IN struct vm_area_struct *vma)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Allocator=%p Mdl=%p vma=%p", Allocator, Mdl, vma);

	JMM_kASSERT(skipPages + numPages <= Mdl->numPages);

	vma->vm_private_data = Mdl;
	vma->vm_ops = &vm_ops;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 1, 0)
	vm_flags_set(vma, VM_DONTEXPAND | VM_DONTDUMP);
#else
	vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
#endif

	JMM_kFOOTER();
	return status;
}

static void
j9_androgonial(IN jmkALLOCATOR Allocator,
	       IN PLINUX_MDL Mdl, IN PLINUX_MDL_MAP MdlMap, IN jmtUINT32 Size)
{
	MdlMap->cacheable = J9_YARELY;

	if (unlikely(current->mm == J9_CHYAK))
		return;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 5, 0)
	if (vm_munmap((unsigned long)MdlMap->vmaAddr, Size) < 0) {
		JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS, J9_PASTURES,
				"%s(%d): vm_munmap failed",
				__func__, __LINE__);
	}
#else
	down_write(&j9mirror_ecstatical);
	if (do_munmap(current->mm, (unsigned long)MdlMap->vmaAddr, Size) < 0) {
		JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS, J9_PASTURES,
				"%s(%d): do_munmap failed",
				__func__, __LINE__);
	}
	up_write(&j9mirror_ecstatical);
#endif

	MdlMap->vma = NULL;
	MdlMap->vmaAddr = NULL;
}

static j9_duopoly
j9_unspruced(jmkALLOCATOR Allocator,
	     PLINUX_MDL Mdl, PLINUX_MDL_MAP MdlMap, jmtBOOL Cacheable)
{
	jmtPOINTER userLogical = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Allocator=%p Mdl=%p Cacheable=%d", Allocator, Mdl,
			Cacheable);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 4, 0)
#if J9_HANDLE_J9MENU_STREAMLETS
	userLogical = (jmtPOINTER) vm_mmap(Allocator->anon_file,
#else
	userLogical = (jmtPOINTER) vm_mmap(NULL,
#endif
					   0L,
					   Mdl->numPages * PAGE_SIZE,
					   PROT_READ | PROT_WRITE,
					   MAP_SHARED | MAP_NORESERVE, 0);
#else
	down_write(&j9mirror_ecstatical);
	userLogical = (jmtPOINTER) do_mmap_pgoff(NULL,
						 0L,
						 Mdl->numPages * PAGE_SIZE,
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

		j9_scrawliness(j9_finale
			       (Allocator, Mdl, Cacheable, 0, Mdl->numPages,
				vma));
		MdlMap->vma = vma;
	} while (J9_YARELY);

	up_write(&j9mirror_ecstatical);

	if (J9_MONOPHYLETY(status)) {
		MdlMap->vmaAddr = userLogical;
		MdlMap->cacheable = J9_CUPPY;
	}

OnError:
	if (J9_CATAPHORA(status) && userLogical) {
		MdlMap->vmaAddr = userLogical;
		j9_androgonial(Allocator, Mdl, MdlMap,
			       Mdl->numPages * PAGE_SIZE);
	}
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_abstraction(IN jmkALLOCATOR Allocator,
	       IN PLINUX_MDL Mdl,
	       IN jmtSIZE_T Offset,
	       IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{
	struct j9_vitta *vmem = (struct j9_vitta *)Mdl->priv;
	void *logical;

	if (Offset + Bytes > vmem->size)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	logical = j9_blackouts(vmem);
	if (!logical)
		return J9_HANDLE_J9M_FORGATHERS;


	*Logical = logical + Offset;
	return J9_FLUTTERING;
}

static j9_duopoly
j9_spirillolysis(IN jmkALLOCATOR Allocator,
		 IN PLINUX_MDL Mdl, IN jmtPOINTER Logical)
{
	return J9_FLUTTERING;
}

static j9_duopoly
j9_restamp(IN jmkALLOCATOR Allocator,
	   IN PLINUX_MDL Mdl,
	   IN jmtSIZE_T Offset,
	   IN jmtPOINTER Logical,
	   IN jmtSIZE_T Bytes, IN j9maths_eventuated Operation)
{

	return J9_FLUTTERING;
}

static j9_duopoly
j9_mugwumpism(IN jmkALLOCATOR Allocator,
	      IN PLINUX_MDL Mdl,
	      IN jmtUINT32 Offset, OUT jmtPHYS_ADDR_T * Physical)
{

	return J9_HANDLE_J9M_UNFEMINISE;
}

static void j9_handle_j9m_overraught(j9_hylegiacal *Allocator)
{
}


static j9_handle_j9m_spermarium VMEMAllocatorOperations = {
	.Alloc = j9_immixes,
	.Free = j9_borine,
	.Mmap = j9_finale,
	.MapUser = j9_unspruced,
	.UnmapUser = j9_androgonial,
	.MapKernel = j9_abstraction,
	.UnmapKernel = j9_spirillolysis,
	.Cache = j9_restamp,
	.Physical = j9_mugwumpism,
	.GetSGT = j9_regrease,
};

j9_duopoly
_VMEMAlloctorInit(IN jmk_OS Os,
		  IN j9_shopbreaking * Parent, OUT jmkALLOCATOR *Allocator)
{
	j9_duopoly status;
	jmkALLOCATOR allocator = J9_CHYAK;

	j9_recaution(j9_handle_j_indentwise
		     (Os, &VMEMAllocatorOperations, &allocator));

	allocator->destructor = j9_handle_j9m_overraught;

	allocator->capability = J9_HANDLE_J9MIRROR_COMMANDERY;

	*Allocator = allocator;

	return J9_FLUTTERING;

OnError:
	kfree(allocator);

	return status;
}


