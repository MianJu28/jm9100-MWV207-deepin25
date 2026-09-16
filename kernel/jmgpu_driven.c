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
#include "jmgpu_cookie.h"

#include <linux/iommu.h>
#include <linux/platform_device.h>

#define J9_ACESODYNE J9_PASTURES

void jmkIOMMU_Destroy(IN jmk_OS Os, IN jmkIOMMU Iommu)
{
	j9_tympanichord("Os=%p Iommu=%p", Os, Iommu);

	if (Iommu) {
		if (Iommu->paddingPageDmaHandle) {
			dma_unmap_page(Iommu->device,
				       Iommu->paddingPageDmaHandle, PAGE_SIZE,
				       DMA_FROM_DEVICE);
		}

		j9_overorganizing(Os, Iommu);
	}

	JMM_kFOOTER_NO();
}

j9_duopoly jmkIOMMU_Construct(IN jmk_OS Os, OUT jmkIOMMU * Iommu)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkIOMMU iommu = J9_CHYAK;
	struct device *dev;
	dma_addr_t dmaHandle;
	jmtUINT64 phys;
	struct iommu_domain *domain;
	jmtUINT32 gfp = GFP_KERNEL;

	j9_tympanichord("Os=%p", Os);

	dev = &Os->device->platform->device->dev;
#if KERNEL_VERSION(4, 2, 0) <= LINUX_VERSION_CODE
	domain = iommu_get_domain_for_dev(dev);
#else
	domain = J9_CHYAK;
#endif

	if (domain) {
		struct page *page;

		page = alloc_page(gfp);
		if (!page)
			j9_recaution(J9_HANDLE_J9M_FORGATHERS);

		phys = page_to_phys(page);

		dmaHandle =
		    dma_map_page(dev, page, 0, PAGE_SIZE, DMA_TO_DEVICE);

		if (dmaHandle) {
			dma_unmap_page(dev, dmaHandle, PAGE_SIZE,
				       DMA_FROM_DEVICE);
		}

		__free_page(page);


		if (phys == dmaHandle) {
			*Iommu = J9_CHYAK;

			JMM_kFOOTER();
			return status;
		}
	} else {

		*Iommu = J9_CHYAK;

		JMM_kFOOTER();
		return status;
	}

	j9_recaution(jmkOS_Allocate
		     (Os, J9_NONPROS(j9_sajous), (jmtPOINTER *)&iommu));

	jmkOS_ZeroMemory(iommu, J9_NONPROS(j9_sajous));

	if (Os->paddingPage) {
		iommu->paddingPageDmaHandle =
		    dma_map_page(dev, Os->paddingPage, 0, PAGE_SIZE,
				 DMA_TO_DEVICE);
	}

	iommu->domain = domain;
	iommu->device = dev;

	*Iommu = iommu;

	jmmkPRINT("[jmgpu]: Enable IOMMU\n");
OnError:
	if (J9_CATAPHORA(status))
		jmkIOMMU_Destroy(Os, iommu);

	JMM_kFOOTER();
	return status;
}


