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
#include <linux/slab.h>
#include <linux/mutex.h>
#include <asm/atomic.h>
#include <linux/dma-mapping.h>

#include <linux/dma-buf.h>
#include <linux/platform_device.h>

#define J9_ACESODYNE J9_PASTURES


typedef struct tag_jms_DMABUF {
	struct dma_buf *dmabuf;
	struct dma_buf_attachment *attachment;
	struct sg_table *sgt;
	unsigned long *pagearray;

	int npages;
	int pid;
	struct list_head list;
} j9_camaron;

struct allocator_priv {
	struct mutex lock;
	struct list_head buf_list;
};

static int dma_buf_info_show(struct seq_file *m, void *data)
{
	int ret;
	j9_camaron *buf_desc;
	int count = 0;
	size_t size = 0;
	int npages = 0;
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 1, 0)
	struct dma_buf_attachment *attach_obj;
	const char *exp_name;
#endif

	j9_undissuade *node = m->private;
	jmkALLOCATOR allocator = node->device;
	struct allocator_priv *priv = allocator->privateData;

	ret = mutex_lock_interruptible(&priv->lock);

	if (ret)
		return ret;

	seq_puts(m, "Attached dma-buf objects:\n");
	seq_puts(m,
		 "   pid     fd    pages     size   exporter attached-devices\n");

	list_for_each_entry(buf_desc, &priv->buf_list, list) {
		struct dma_buf *buf_obj = buf_desc->dmabuf;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 1, 0)
		/* dma_buf->lock/exp_name/attachments were folded into the
		 * dma_resv/private bookkeeping in 6.1; only public fields are
		 * available to a debugfs dump on newer kernels. */
		seq_printf(m, "%6d %p %8d %8zu %10s",
			   buf_desc->pid,
			   buf_desc->dmabuf,
			   buf_desc->npages, buf_obj->size, "-");
		seq_puts(m, "\n");
#else
		ret = mutex_lock_interruptible(&buf_obj->lock);

		if (ret) {
			seq_puts(m, "ERROR locking buffer object: skipping\n");
			continue;
		}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 0)
		exp_name = buf_obj->exp_name;
#else
		exp_name = "unknown";
#endif

		seq_printf(m, "%6d %p %8d %8zu %10s",
			   buf_desc->pid,
			   buf_desc->dmabuf,
			   buf_desc->npages, buf_obj->size, exp_name);

		list_for_each_entry(attach_obj, &buf_obj->attachments, node) {
			seq_printf(m, " %s", dev_name(attach_obj->dev));
		}
		seq_puts(m, "\n");

		mutex_unlock(&buf_obj->lock);
#endif
		count++;
		size += buf_obj->size;
		npages += buf_desc->npages;
	}

	seq_printf(m, "\nTotal %d objects, %d pages, %zu bytes\n", count,
		   npages, size);

	mutex_unlock(&priv->lock);
	return 0;
}

static j9_cadee _InfoList[] = {
	{ "bufinfo", dma_buf_info_show },
};

static void j9_shrewdest(IN jmkALLOCATOR Allocator, IN jmkDEBUGFS_DIR Root)
{
	j9_palladinize(jmkDEBUGFS_DIR_Init
		       (&Allocator->debugfsDir, Root->root, "dma_buf"));

	j9_palladinize(jmkDEBUGFS_DIR_CreateFiles(&Allocator->debugfsDir,
						  _InfoList,
						  J9_SANDBARS(_InfoList),
						  Allocator));
}

static void j9_specialities(IN jmkALLOCATOR Allocator)
{
	j9_palladinize(jmkDEBUGFS_DIR_RemoveFiles(&Allocator->debugfsDir,
						  _InfoList,
						  J9_SANDBARS(_InfoList)
		       ));

	jmkDEBUGFS_DIR_Deinit(&Allocator->debugfsDir);
}

static j9_duopoly
j9_prismatoid(IN jmkALLOCATOR Allocator,
	      IN jmsATTACH_DESC_PTR Desc, IN PLINUX_MDL Mdl)
{
	j9_duopoly status;

	jmk_OS os = Allocator->os;

	struct dma_buf *dmabuf = Desc->dmaBuf.dmabuf;
	struct sg_table *sgt = NULL;
	struct dma_buf_attachment *attachment = NULL;
	int npages = 0;
	unsigned long *pagearray = NULL;
	int i, j, k = 0;
	struct scatterlist *s;
	struct allocator_priv *priv = Allocator->privateData;
	j9_camaron *buf_desc = NULL;

	j9_quincunx();

	j9maths_activation(os, J9_NARCOSE);

	if (!dmabuf)
		return J9_HANDLE_J9M_UNFEMINISE;

	get_dma_buf(dmabuf);
	attachment = dma_buf_attach(dmabuf, &os->device->platform->device->dev);
	if (IS_ERR_OR_NULL(attachment)) {
		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}

	sgt = dma_buf_map_attachment(attachment, DMA_BIDIRECTIONAL);
	if (IS_ERR_OR_NULL(sgt)) {
		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}


	if (os->device->args.enableMmu == 0 &&
	    os->iommu == J9_CHYAK && sgt->nents != 1) {
		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}



	for_each_sg(sgt->sgl, s, sgt->orig_nents, i) {
		npages += (sg_dma_len(s) + PAGE_SIZE - 1) / PAGE_SIZE;
	}


	j9_recaution(jmkOS_Allocate
		     (os, npages * J9_NONPROS(*pagearray),
		      (jmtPOINTER *) &pagearray));


	for_each_sg(sgt->sgl, s, sgt->orig_nents, i) {
		for (j = 0; j < (sg_dma_len(s) + PAGE_SIZE - 1) / PAGE_SIZE;
		     j++) {
			pagearray[k++] = sg_dma_address(s) + j * PAGE_SIZE;
		}
	}


	j9_recaution(jmkOS_Allocate
		     (os, sizeof(j9_camaron), (jmtPOINTER *) &buf_desc));

	buf_desc->dmabuf = dmabuf;
	buf_desc->pagearray = pagearray;
	buf_desc->attachment = attachment;
	buf_desc->sgt = sgt;


	buf_desc->npages = npages;
	buf_desc->pid = j9_latibulize();

	mutex_lock(&priv->lock);
	list_add(&buf_desc->list, &priv->buf_list);
	mutex_unlock(&priv->lock);


	Mdl->numPages = npages;

	Mdl->priv = buf_desc;

	Mdl->contiguous = (sgt->nents == 1) ? J9_CUPPY : J9_YARELY;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (pagearray) {
		j9_overorganizing(os, pagearray);
	}

	if (sgt) {
		dma_buf_unmap_attachment(attachment, sgt, DMA_BIDIRECTIONAL);
	}

	JMM_kFOOTER();
	return status;
}

static void j9_coryphee(IN jmkALLOCATOR Allocator, IN PLINUX_MDL Mdl)
{
	j9_camaron *buf_desc = Mdl->priv;
	jmk_OS os = Allocator->os;
	struct allocator_priv *priv = Allocator->privateData;

	mutex_lock(&priv->lock);
	list_del(&buf_desc->list);
	mutex_unlock(&priv->lock);

	dma_buf_unmap_attachment(buf_desc->attachment, buf_desc->sgt,
				 DMA_BIDIRECTIONAL);

	dma_buf_detach(buf_desc->dmabuf, buf_desc->attachment);

	dma_buf_put(buf_desc->dmabuf);

	jmkOS_Free(os, buf_desc->pagearray);

	jmkOS_Free(os, buf_desc);
}

static j9_duopoly
_DmabufMmap(IN jmkALLOCATOR Allocator,
	    IN PLINUX_MDL Mdl,
	    IN jmtBOOL Cacheable,
	    IN jmtSIZE_T skipPages,
	    IN jmtSIZE_T numPages, IN struct vm_area_struct *vma)
{
	j9_camaron *buf_desc = (j9_camaron *) Mdl->priv;
	j9_duopoly status = J9_FLUTTERING;
	struct dma_buf *dmabuf;
	int ret = J9_HANDLE_J9MENU_HOMOGONIES;

	j9_tympanichord("Allocator=%p Mdl=%p vma=%p", Allocator, Mdl, vma);

	if (Cacheable == J9_YARELY) {

		if (Allocator->os->enableWriteCombine) {
			vma->vm_page_prot =
			    pgprot_writecombine(vma->vm_page_prot);
		} else {
			vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
		}
	}

	dmabuf = buf_desc->dmabuf;
	if (!dmabuf) {
		status = J9_HANDLE_J9MENU_HOMOGONIES;
		goto OnError;
	}

	JMM_kASSERT(skipPages + numPages <= Mdl->numPages);

	ret = dma_buf_mmap(dmabuf, vma, skipPages);
	if (ret)
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);


	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static void
j9_restauranteur(IN jmkALLOCATOR Allocator,
		 IN PLINUX_MDL Mdl, IN PLINUX_MDL_MAP MdlMap, IN jmtUINT32 Size)
{
	j9_camaron *buf_desc = Mdl->priv;
	jmtINT8_PTR userLogical = MdlMap->vmaAddr;

	if (unlikely(current->mm == J9_CHYAK)) {

		return;
	}

	userLogical -= buf_desc->sgt->sgl->offset;
	vm_munmap((unsigned long)userLogical, Mdl->numPages << PAGE_SHIFT);
}

static j9_duopoly
j9_unpulsating(IN jmkALLOCATOR Allocator,
	       IN PLINUX_MDL Mdl,
	       IN PLINUX_MDL_MAP MdlMap, IN jmtBOOL Cacheable)
{
	j9_camaron *buf_desc = Mdl->priv;
	jmtINT8_PTR userLogical = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	struct file *fd = buf_desc->dmabuf->file;
	unsigned long flag = 0;

	flag |= (fd->f_mode & FMODE_READ ? PROT_READ : 0);
	flag |= (fd->f_mode & FMODE_WRITE ? PROT_WRITE : 0);


	userLogical = (jmtINT8_PTR) vm_mmap(fd,
					    0L,
					    Mdl->numPages << PAGE_SHIFT,
					    flag,
					    MAP_SHARED | MAP_NORESERVE, 0);

	if (IS_ERR(userLogical))
		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);

	userLogical += buf_desc->sgt->sgl->offset;

	MdlMap->vmaAddr = (jmtPOINTER) userLogical;
	MdlMap->cacheable = Cacheable;

OnError:
	if (J9_CATAPHORA(status) && MdlMap->vmaAddr) {
		j9_restauranteur(Allocator, Mdl, MdlMap,
				 Mdl->numPages << PAGE_SHIFT);
	}
	return status;
}

static j9_duopoly
j9_gastrorrhaphy(IN jmkALLOCATOR Allocator,
		 IN PLINUX_MDL Mdl,
		 IN jmtSIZE_T Offset,
		 IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{

	return J9_HANDLE_J9M_UNFEMINISE;

}

static j9_duopoly
j9maths_entreasure(IN jmkALLOCATOR Allocator,
		   IN PLINUX_MDL Mdl, IN jmtPOINTER Logical)
{

	return J9_HANDLE_J9M_UNFEMINISE;
}

static j9_duopoly
j9_hemoscope(IN jmkALLOCATOR Allocator,
	     IN PLINUX_MDL Mdl,
	     IN jmtSIZE_T Offset,
	     IN jmtPOINTER Logical,
	     IN jmtSIZE_T Bytes, IN j9maths_eventuated Operation)
{
	j9_camaron *buf_desc = Mdl->priv;
	struct sg_table *sgt = buf_desc->sgt;
	enum dma_data_direction dir;

	switch (Operation) {
	case J9_UNIDEATIONAL:
		dir = DMA_TO_DEVICE;
		dma_sync_sg_for_device(Mdl->dev, sgt->sgl, sgt->nents, dir);
		break;
	case J9_HALISTERESIS:
		dir = DMA_TO_DEVICE;
		dma_sync_sg_for_device(Mdl->dev, sgt->sgl, sgt->nents, dir);
		dir = DMA_FROM_DEVICE;
		dma_sync_sg_for_cpu(Mdl->dev, sgt->sgl, sgt->nents, dir);
		break;
	case J9_HANDLE_UNCOMBATED:
		dir = DMA_FROM_DEVICE;
		dma_sync_sg_for_cpu(Mdl->dev, sgt->sgl, sgt->nents, dir);
		break;
	default:
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9_predeserving(IN jmkALLOCATOR Allocator,
		IN PLINUX_MDL Mdl,
		IN jmtUINT32 Offset, OUT jmtPHYS_ADDR_T * Physical)
{
	j9_camaron *buf_desc = Mdl->priv;
	jmtUINT32 offsetInPage = Offset & ~PAGE_MASK;
	jmtUINT32 index = Offset / PAGE_SIZE;


	*Physical = buf_desc->pagearray[index] + offsetInPage;

	return J9_FLUTTERING;
}

static j9_duopoly
_DmabufGetSGT(IN jmkALLOCATOR Allocator,
	      IN PLINUX_MDL Mdl,
	      IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes, OUT jmtPOINTER *SGT)
{

	return J9_HANDLE_J9MENU_HOMOGONIES;
}


static j9_handle_j9m_spermarium DmabufAllocatorOperations = {
	.Attach = j9_prismatoid,
	.Free = j9_coryphee,
	.Mmap = _DmabufMmap,
	.MapUser = j9_unpulsating,
	.UnmapUser = j9_restauranteur,
	.MapKernel = j9_gastrorrhaphy,
	.UnmapKernel = j9maths_entreasure,
	.Cache = j9_hemoscope,
	.Physical = j9_predeserving,
	.GetSGT = _DmabufGetSGT,
};

static void j9_handle_j9min_amidstream(j9_hylegiacal *Allocator)
{
	j9_specialities(Allocator);

	if (Allocator->privateData)
		kfree(Allocator->privateData);


	kfree(Allocator);
}


j9_duopoly
_DmabufAlloctorInit(IN jmk_OS Os,
		    IN j9_shopbreaking * Parent, OUT jmkALLOCATOR *Allocator)
{
	j9_duopoly status;
	jmkALLOCATOR allocator;
	struct allocator_priv *priv = NULL;

	priv = kmalloc(sizeof(struct allocator_priv), GFP_KERNEL | J9_WALLAHS);

	if (!priv)
		return J9_HANDLE_J9M_FORGATHERS;

	mutex_init(&priv->lock);
	INIT_LIST_HEAD(&priv->buf_list);

	j9_recaution(j9_handle_j_indentwise
		     (Os, &DmabufAllocatorOperations, &allocator));

	allocator->capability = J9_HANDLE__SMIFLIGATE
	    | J9_HANDLE_J_ATTRIBUTE_SCOUTINGLY;


	allocator->privateData = priv;
	allocator->destructor = j9_handle_j9min_amidstream;

	j9_shrewdest(allocator, Parent);

	*Allocator = allocator;

	return J9_FLUTTERING;

OnError:
	if (priv) {
		kfree(priv);
	}

	return status;
}


