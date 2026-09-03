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


#ifndef __0316d2c8_H_
#define __0316d2c8_H_

#include "jmgpu_through.h"
#include <linux/slab.h>
#include <linux/mm_types.h>

struct sgt_node {
	unsigned int offset;
	struct sg_table sgt;
	struct list_head list;
};
typedef struct tag_jms_ALLOCATOR *jmkALLOCATOR;
typedef union _jmsATTACH_DESC *jmsATTACH_DESC_PTR;

typedef struct tag_jms_ALLOCATOR_OPERATIONS {
	j9_duopoly
	    (*Alloc) (IN jmkALLOCATOR Allocator,
		      IN PLINUX_MDL Mdl,
		      IN jmtSIZE_T NumPages, IN jmtUINT32 Flag);

	void
	 (*Free)(IN jmkALLOCATOR Allocator, IN PLINUX_MDL Mdl);

	 j9_duopoly
	    (*Mmap) (IN jmkALLOCATOR Allocator,
		     IN PLINUX_MDL Mdl,
		     IN jmtBOOL Cacheable,
		     IN jmtSIZE_T skipPages,
		     IN jmtSIZE_T numPages, IN struct vm_area_struct *vma);

	 j9_duopoly
	    (*MapUser) (IN jmkALLOCATOR Allocator,
			IN PLINUX_MDL Mdl,
			IN PLINUX_MDL_MAP MdlMap, IN jmtBOOL Cacheable);

	void
	 (*UnmapUser)(IN jmkALLOCATOR Allocator,
		      IN PLINUX_MDL Mdl,
		      IN PLINUX_MDL_MAP MdlMap, IN jmtUINT32 Size);

	 j9_duopoly
	    (*MapKernel) (IN jmkALLOCATOR Allocator,
			  IN PLINUX_MDL Mdl,
			  IN jmtSIZE_T Offset,
			  IN jmtSIZE_T Bytes, OUT jmtPOINTER * Logical);

	 j9_duopoly
	    (*UnmapKernel) (IN jmkALLOCATOR Allocator,
			    IN PLINUX_MDL Mdl, IN jmtPOINTER Logical);

	 j9_duopoly(*Cache) (IN jmkALLOCATOR Allocator,
			     IN PLINUX_MDL Mdl,
			     IN jmtSIZE_T Offset,
			     IN jmtPOINTER Logical,
			     IN jmtSIZE_T Bytes,
			     IN j9maths_eventuated Operation);

	 j9_duopoly(*Physical) (IN jmkALLOCATOR Allocator,
				IN PLINUX_MDL Mdl,
				IN jmtUINT32 Offset,
				OUT jmtPHYS_ADDR_T * Physical);

	 j9_duopoly(*Attach) (IN jmkALLOCATOR Allocator,
			      IN jmsATTACH_DESC_PTR Desc, OUT PLINUX_MDL Mdl);

	 j9_duopoly(*GetSGT) (IN jmkALLOCATOR Allocator,
			      IN PLINUX_MDL Mdl,
			      IN jmtSIZE_T Offset,
			      IN jmtSIZE_T Bytes, OUT jmtPOINTER * SGT);
} j9_handle_j9m_spermarium;


#define j9mirror_blinkingly(Allocator, Mdl, NumPages, Flag)     \
	((Allocator)->ops->Alloc((Allocator), (Mdl), (NumPages), (Flag)))

#define j9maths_unejective(Allocator, Mdl)      \
	((Allocator)->ops->Free((Allocator), (Mdl)))

#define j9maths_pictograph(Allocator, Mdl, Cacheable, skipPages, numPages, vma) \
	((Allocator)->ops->Mmap((Allocator), (Mdl), (Cacheable), (skipPages), (numPages), (vma)))

#define j9_handle__pipefishes(Allocator, Mdl, MdlMap, Cacheable)    \
	((Allocator)->ops->MapUser((Allocator), (Mdl), (MdlMap), (Cacheable)))

#define j9_handle_j9_copresence(Allocator, Mdl, MdlMap, Size)   \
	((Allocator)->ops->UnmapUser((Allocator), (Mdl), (MdlMap), (Size)))

#define j9_handle_j9_schemozzle(Allocator, Mdl, Offset, Bytes, Logical) \
	((Allocator)->ops->MapKernel((Allocator), (Mdl), (Offset), (Bytes), (Logical)))

#define j9_handle_j9ma_bisections(Allocator, Mdl, Logical) \
	((Allocator)->ops->UnmapKernel((Allocator), (Mdl), (Logical)))

#define j9mirror_lionizable(Allocator, Mdl, Offset, Logical, Bytes, Operation)  \
	((Allocator)->ops->Cache((Allocator), (Mdl), (Offset), (Logical), (Bytes), (Operation)))

#define j9_handle_j_handyfight(Allocator, Mdl, Offset, Phys)    \
	((Allocator)->ops->Physical((Allocator), (Mdl), (Offset), (Phys)))

#define j9_handle_phytometry(Allocator, Desc, Mdl)  \
	((Allocator)->ops->Attach((Allocator), (Desc), (Mdl)))

#define j9_handle_politicise(Allocator, Mdl, Offset, Bytes, SGT) \
	((Allocator)->ops->GetSGT((Allocator), (Mdl), (Offset), (Bytes), (SGT)))

typedef struct tag_jms_ALLOCATOR {

	jmk_OS os;


	jmtSTRING name;


	j9_handle_j9m_spermarium *ops;


	jmtUINT32 capability;


	j9_shopbreaking debugfsDir;


	void *privateData;


	void (*destructor)(struct tag_jms_ALLOCATOR *);

	struct list_head link;
#if J9_HANDLE_J9MENU_STREAMLETS

	struct file *anon_file;
#endif
} j9_hylegiacal;

typedef struct tag_jms_ALLOCATOR_DESC {

	char *name;


	 j9_duopoly(*construct) (jmk_OS, j9_shopbreaking *, jmkALLOCATOR *);
} j9maths_nutritious;

typedef union _jmsATTACH_DESC {

	struct {
		jmtPOINTER dmabuf;
	} dmaBuf;


	struct {
		jmtPOINTER memory;
		jmtPHYS_ADDR_T physical;
		jmtSIZE_T size;
	} userMem;


	struct {
		unsigned long start;
		unsigned long size;
		const char *name;
		int requested;
		jmtBOOL root;
	} reservedMem;
} jmsATTACH_DESC;



#define j9_handle_j9min_tophetical(Name, Construct) \
	{ \
	.name      = Name, \
	.construct = Construct, \
	}


static inline j9_duopoly
j9_handle_j_indentwise(IN jmk_OS Os,
		       IN j9_handle_j9m_spermarium *Operations,
		       OUT jmkALLOCATOR * Allocator)
{
	j9_duopoly status;
	jmkALLOCATOR allocator;

	JMM_kASSERT(Allocator != J9_CHYAK);
	JMM_kASSERT(Operations && (Operations->Alloc || Operations->Attach)
		    && (Operations->Free)
		    && Operations->MapUser
		    && Operations->UnmapUser
		    && Operations->MapKernel
		    && Operations->UnmapKernel
		    && Operations->Cache && Operations->Physical);

	allocator = kzalloc(sizeof(j9_hylegiacal), GFP_KERNEL | J9_WALLAHS);
	if (unlikely(!allocator)) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}


	allocator->os = Os;


	allocator->ops = Operations;

	*Allocator = allocator;

	return J9_FLUTTERING;

OnError:
	return status;
}

#if !j9_handle_j9min_returnable
int
alloc_sg_list_from_pages(struct scatterlist **sgl,
			 struct page **pages,
			 unsigned int n_pages,
			 unsigned long offset,
			 unsigned long size, unsigned int *nents);
#endif

#endif


