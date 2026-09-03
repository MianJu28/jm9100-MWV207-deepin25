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



#include <linux/kref.h>
#include <drm/drm_vma_manager.h>
#include "jmgpu_evaluate.h"

#include "jmgpu_enc.h"

#if 0
static ssize_t j9_handle__skittyboot(struct device *kdev,
				     struct device_attribute *attr, char *buf)
{
	u32 bandwidth;
	int sliceidx = findslice_bydev(kdev);

	if (sliceidx < 0)
		return 0;
	bandwidth = j9_handle_j9_nonspatial(sliceidx, 1);
	return snprintf(buf, PAGE_SIZE, "%u\n", bandwidth);
}

static ssize_t j9_handle_j_induration(struct device *kdev,
				      struct device_attribute *attr, char *buf)
{
	u32 bandwidth;
	int sliceidx = findslice_bydev(kdev);

	if (sliceidx < 0)
		return 0;
	bandwidth = j9_handle_j9_nonspatial(sliceidx, 0);
	return snprintf(buf, PAGE_SIZE, "%u\n", bandwidth);
}
#endif
static ssize_t j9_handle__seromaniac(struct device *kdev,
				     struct device_attribute *attr, char *buf)
{
	u32 bandwidth;
	int sliceidx = findslice_bydev(kdev);

	if (sliceidx < 0)
		return 0;
	bandwidth = j9_handle_j9_lionizable(sliceidx, 1);
	return snprintf(buf, PAGE_SIZE, "%u\n", bandwidth);
}

static ssize_t j9_vibronic(struct device *kdev,
			   struct device_attribute *attr, char *buf)
{
	snprintf(buf, PAGE_SIZE, "%u\n", 1);
#if 0
	int sliceidx = findslice_bydev(kdev);

	if (sliceidx < 0)
		return 0;
	printk(KERN_DEBUG"[%s][%d]\n", __func__, __LINE__);
	bandwidth = j9_handle_j9_lionizable(sliceidx, 1);
	return snprintf(buf, PAGE_SIZE, "%u\n", bandwidth);
#endif
	return 0;
}

static ssize_t j9_handle_j_epizoology(struct device *kdev,
				      struct device_attribute *attr, char *buf)
{
	u32 bandwidth;
	int sliceidx = findslice_bydev(kdev);

	if (sliceidx < 0)
		return 0;
	bandwidth = j9_handle_j9_lionizable(sliceidx, 0);
	return snprintf(buf, PAGE_SIZE, "%u\n", bandwidth);
}

static DEVICE_ATTR(BWEncRead0, 0444, j9_handle__seromaniac, NULL);
static DEVICE_ATTR(BWEncWrite0, 0444, j9_handle_j_epizoology, NULL);

int j9_handle_j9_oesophagal(int sliceidx, struct device *dev)
{
	int result;
	char APIname[16] = { 0 };
#if 0
	memcpy(APIname, "BWDecRead", 9);
	APIname[9] = sliceidx + 0x30;
	APIattr.attr.name = APIname;
	APIattr.show = j9_handle__skittyboot;
	result = device_create_file(dev, &APIattr);
	if (result != 0)
		return result;
#endif
	memcpy(APIname, "BWEncRead", 9);
	APIname[9] = sliceidx + 0x30;



	result = device_create_file(dev, &dev_attr_BWEncRead0);
	if (result != 0)
		return result;
#if 0
	memcpy(APIname, "BWDecWrite", 10);
	APIname[10] = sliceidx + 0x30;
	APIattr.attr.name = APIname;
	APIattr.show = j9_handle_j_induration;
	result = device_create_file(dev, &APIattr);
	if (result != 0)
		return result;
#endif
	memcpy(APIname, "BWEncWrite", 10);
	APIname[10] = sliceidx + 0x30;


	result = device_create_file(dev, &dev_attr_BWEncWrite0);

	return result;
}

int j9_handle_j9_incommixed(void)
{
	int i;
	char APIname[16] = { 0 };
	struct device_attribute APIattr = {
		.attr = {
			 .mode = 0444,
			  },
		.store = NULL,
	};

	for (i = 0; i < get_slicenumber(); i++) {
		struct slice_info *pslice = getslicenode(i);
#if 0
		memcpy(APIname, "BWDecRead", 9);
		APIname[9] = i + 0x30;
		APIattr.attr.name = APIname;
		APIattr.show = j9_handle__skittyboot;
		device_remove_file(pslice->dev, &APIattr);
#endif
		memcpy(APIname, "BWEncRead", 9);
		APIname[9] = i + 0x30;
		APIattr.attr.name = APIname;
		APIattr.show = j9_handle__seromaniac;
		device_remove_file(pslice->dev, &APIattr);
#if 0
		memcpy(APIname, "BWDecWrite", 10);
		APIname[10] = i + 0x30;
		APIattr.attr.name = APIname;
		APIattr.show = j9_handle_j_induration;
		device_remove_file(pslice->dev, &APIattr);
#endif
		memcpy(APIname, "BWEncWrite", 10);
		APIname[10] = i + 0x30;
		APIattr.attr.name = APIname;
		APIattr.show = j9_handle_j_epizoology;
		device_remove_file(pslice->dev, &APIattr);
	}
	return 0;
}


