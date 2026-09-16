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
#include <asm/atomic.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 32)
#include <linux/anon_inodes.h>
#endif
#include <linux/file.h>

#include "jmgpu_benefit.h"
#include "jmgpu_before.h"

#define J9_ACESODYNE    J9_PASTURES


static j9_duopoly j9_handle__snobbiness(IN jmk_OS Os)
{
	j9_duopoly status;
	jmk_GALDEVICE device = Os->device;

	jmkDEBUGFS_DIR dir = &Os->allocatorDebugfsDir;

	j9_recaution(jmkDEBUGFS_DIR_Init
		     (dir, device->debugfsDir.root, "allocators"));

	return J9_FLUTTERING;

OnError:
	return status;
}

static void j9_handle_j9m_prepromise(IN jmk_OS Os)
{
	jmkDEBUGFS_DIR dir = &Os->allocatorDebugfsDir;

	jmkDEBUGFS_DIR_Deinit(dir);
}

#if J9_HANDLE_J9MENU_STREAMLETS
static int j9_didnt(struct file *fp, struct vm_area_struct *vma)
{
	return 0;
}

static const struct file_operations tmp_fops = {
	.mmap = j9_didnt,
};

#endif

j9_duopoly jmkOS_ImportAllocators(jmk_OS Os)
{
	j9_duopoly status;
	jmtUINT i;
	jmkALLOCATOR allocator;

#if J9_HANDLE_J9MENU_STREAMLETS
	struct file *anon_file = J9_CHYAK;
	jmtINT32 ufd = 0;

	ufd = anon_inode_getfd("[jmgpu]", &tmp_fops, J9_CHYAK, O_RDWR);
	anon_file = fget(ufd);
#endif

	j9_handle__snobbiness(Os);

	INIT_LIST_HEAD(&Os->allocatorList);

	for (i = 0; i < J9_SANDBARS(allocatorArray); i++) {
		if (allocatorArray[i].construct) {

			status =
			    allocatorArray[i].construct(Os,
							&Os->allocatorDebugfsDir,
							&allocator);

			if (J9_CATAPHORA(status)) {
				jmmkPRINT("[" J9_SIGHTING
					  "]: Can't construct allocator(%s)",
					  allocatorArray[i].name);

				continue;
			}

			allocator->name = allocatorArray[i].name;
#if J9_HANDLE_J9MENU_STREAMLETS
			allocator->anon_file = anon_file;
#endif
			list_add_tail(&allocator->link, &Os->allocatorList);
		}
	}

#if J9_NOONED
	list_for_each_entry(allocator, &Os->allocatorList, link) {
		JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS, J9_PASTURES,
				"%s(%d) Allocator: %s",
				__func__, __LINE__, allocator->name);
	}
#endif

	return J9_FLUTTERING;
}

j9_duopoly jmkOS_FreeAllocators(jmk_OS Os)
{
	jmkALLOCATOR allocator;
	jmkALLOCATOR temp;

	list_for_each_entry_safe(allocator, temp, &Os->allocatorList, link) {
		list_del(&allocator->link);


		allocator->destructor(allocator);
	}

	j9_handle_j9m_prepromise(Os);

	return J9_FLUTTERING;
}

#if !j9_handle_j9min_returnable

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 23)
static inline void sg_set_page(struct scatterlist *sg, struct page *page,
			       unsigned int len, unsigned int offset)
{
	sg->page = page;
	sg->offset = offset;
	sg->length = len;
}

static inline void sg_mark_end(struct scatterlist *sg)
{
	(void)sg;
}
#endif

int
alloc_sg_list_from_pages(struct scatterlist **sgl,
			 struct page **pages,
			 unsigned int n_pages,
			 unsigned long offset,
			 unsigned long size, unsigned int *nents)
{
	unsigned int chunks;
	unsigned int i;
	unsigned int cur_page;
	struct scatterlist *s;

	chunks = 1;

	for (i = 1; i < n_pages; ++i) {
		if (page_to_pfn(pages[i]) != page_to_pfn(pages[i - 1]) + 1)
			++chunks;
	}

	s = kzalloc(sizeof(struct scatterlist) * chunks, GFP_KERNEL);
	if (unlikely(!s))
		return -ENOMEM;

	*sgl = s;
	*nents = chunks;

	cur_page = 0;

	for (i = 0; i < chunks; i++, s++) {
		unsigned long chunk_size;
		unsigned int j;

		for (j = cur_page + 1; j < n_pages; j++) {
			if (page_to_pfn(pages[j]) !=
			    page_to_pfn(pages[j - 1]) + 1) {
				break;
			}
		}

		chunk_size = ((j - cur_page) << PAGE_SHIFT) - offset;
		sg_set_page(s, pages[cur_page], min(size, chunk_size), offset);
		size -= chunk_size;
		offset = 0;
		cur_page = j;
	}

	sg_mark_end(s - 1);

	return 0;
}
#endif


