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


#include "jmgpu_problem.h"
#include "jmgpu_library.h"
#include <linux/file.h>
#include "jmgpu_printer.h"
#include <linux/pagemap.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/jiffies.h>
#include <linux/mman.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/io.h>
#include "jmgpu_livelock.h"

#define J9_HATEFULLNESSES      0x900004
#define J9MIRROR_PREPROMISE    0x9B0150

#define J9_HANDLE__GUNPOWDERY  20
#define J9_FIDEICOMMISSOR      1000

#define J9_INTERLINEATION      32
#define J9_HANDLE__COHABITING  32

typedef struct tag_jms_gpuinfo {
	jmtBOOL created;
	char name[J9_HANDLE__COHABITING];
} j9_carpalia;

static ssize_t gpuinfo_show(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	j9_gearshifts *ppcie_info;
	j9_atlantomastoid *pdate = (j9_atlantomastoid *)dev_get_drvdata(dev);

	ppcie_info = &pdate->pcie_info;

	return snprintf(buf, PAGE_SIZE, "VRAM total size:0x%llx\n", ppcie_info->vram_size);
}

static DEVICE_ATTR(gpu_info, S_IRUGO, gpuinfo_show, NULL);

static void jmgpu_gpuinfo_fs_create(jmk_GALDEVICE gdev)
{
	int ret;
	j9_weakliest *platform;
	struct device *ddev;
	struct pci_dev *pdev;

	platform = gdev->platform;
	if (!platform)
		return;

	ddev = platform->ops->getSubDevice(platform);
	if (!ddev)
		return;

	pdev = to_pci_dev(ddev);
	if (!pdev)
		return;

	dev_attr_gpu_info.attr.name = "gpu-info";
	ret = device_create_file(&pdev->dev, &dev_attr_gpu_info);
	if (ret)
		dev_err(&pdev->dev, "Failed to create gpuinfo sysfs!");
}

static void jmgpu_gpuinfo_fs_remove(jmk_GALDEVICE gdev)
{
	j9_weakliest *platform;
	struct device *ddev;
	struct pci_dev *pdev;

	platform = gdev->platform;
	if (!platform)
		return;

	ddev = platform->ops->getSubDevice(platform);
	if (!ddev)
		return;

	pdev = to_pci_dev(ddev);
	if (!pdev)
		return;

	device_remove_file(&pdev->dev, &dev_attr_gpu_info);
}

static s16 j9mirror_peridinian(j9_weakliest *platform)
{
	u32 ret = 0;

	if (!platform)
		return 0;


	ret = platform->ops->readRegisterRaw(platform, J9MIRROR_PREPROMISE);

	return (s16)(ret & 0xffff);
}

static u32 j9_handle_menarcheal(j9_weakliest *platform, j9mirror_outleaping pll_idx)
{
	s32 ret = -1;
	u32 freq_khz;

	if (!platform || !platform->ops->get_pll)
		return 0;


	ret = platform->ops->get_pll(platform, pll_idx, &freq_khz);
	if (ret != 0)
		return 0;


	return (freq_khz / 1000);
}

static u32 j9_inochondritis(j9_weakliest *platform, int id)
{
	switch (id) {
	case J9_PHYLLOPYRROLE:
		return j9_handle_menarcheal(platform, J9MIRROR_DUMBBELLER);
	case J9_HOMOGENIZATION:
		return j9_handle_menarcheal(platform, J9_HANDLE_CRAWLERIZE);
	case J9_COMPREHENSIBLY:
		return j9_handle_menarcheal(platform, J9_HANDLE_PARALLELER);
	case J9_PREOPPRESSION:
		if (platform->params.family == J9_UNGLADSOME) {
			return J9_SMUT(j9_handle_menarcheal(platform, J9_HANDLE_CRAWLERIZE),
				j9_handle_menarcheal(platform, J9_HANDLE_PARALLELER));
		} else {
			return j9_handle_menarcheal(platform, J9_HANDLE_CRAWLERIZE);
		}
	default:
		return 0;
	}
}

static u32 j9_handle__menarcheal(j9_weakliest *platform)
{
	s32 ret = -1;
	u32 volt_mv;

	if (!platform || !platform->ops->get_pll)
		return 0;


	ret = platform->ops->get_core_volt(platform, &volt_mv);
	if (ret != 0)
		return 0;


	return volt_mv;
}

static u32 j9_handle_j_acerbating(j9_weakliest *platform)
{
	u32 val;
	u32 idle;
	u32 i;
	u32 period = J9_FIDEICOMMISSOR;
	u32 vm_id = JM_VGPU_GET_ID(platform->params.vinfo);

	if (!platform)
		return 0;


	idle = 0;
	for (i = 0; i < period; i++) {
		if (vm_id == 2) {
			val = platform->ops->readRegisterRaw(platform, J9_HATEFULLNESSES + 0x10000);
		} else {
			val = platform->ops->readRegisterRaw(platform, J9_HATEFULLNESSES);
		}
		if (val == 0x7fffffff || val == 0x7ffffffe)
			idle++;

	}
	val = idle >= period ? 0 : period - idle;

	return val * 10000 / period;
}

static u32 j9_handle_j9m_unhelpable(jmk_GALDEVICE dev)
{
	u64 remain_bytes = 0;
	u64 jmir_bytes;
	u32 i;
	u32 ret;

	if (!dev)
		return 0;


	jmir_bytes = dev->args.vram_size;

	if (dev->internalVidMem != NULL)
		remain_bytes += dev->internalVidMem->freeBytes;

	if (dev->externalVidMem[0] != NULL) {
		remain_bytes += dev->externalVidMem[0]->freeBytes;
		jmir_bytes -= dev->externalVidMem[0]->bytes;
	}
	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		if (dev->extSRAMVidMem[i] != NULL)
			remain_bytes += dev->extSRAMVidMem[i]->freeBytes;

	}
	if (dev->contiguousVidMem != NULL)
		remain_bytes += dev->contiguousVidMem->freeBytes;

	if (dev->exclusiveVidMem[0] != NULL) {
		remain_bytes += dev->exclusiveVidMem[0]->freeBytes;
		jmir_bytes -= dev->exclusiveVidMem[0]->bytes;
	}

	ret = (u32)((remain_bytes + jmir_bytes) / 1024 / 1024);

	return ret;
}

static char *j9_hymenopterist(j9_weakliest *platform)
{
	struct device *dev;
	struct pci_dev *pdev;
	enum pci_bus_speed speed;
	enum pcie_link_width width;
	u32 id0, id1;
	static const char link_info[20][12] = {
		"PCIE1.0 x1", "PCIE1.0 x2", "PCIE1.0 x4", "PCIE1.0 x8", "PCIE1.0 x16",
		"PCIE2.0 x1", "PCIE2.0 x2", "PCIE2.0 x4", "PCIE2.0 x8", "PCIE2.0 x16",
		"PCIE3.0 x1", "PCIE3.0 x2", "PCIE3.0 x4", "PCIE3.0 x8", "PCIE3.0 x16",
		"PCIE4.0 x1", "PCIE4.0 x2", "PCIE4.0 x4", "PCIE4.0 x8", "PCIE4.0 x16"
	};

	if (!platform)
		return NULL;

	if (platform->params.virt_type == JMV_VIRT_TYPE_MDEV)
		return "PCIE MDEV";

	dev = platform->ops->getSubDevice(platform);
	if (!dev)
		return NULL;


	pdev = to_pci_dev(dev);
	if (!pdev)
		return NULL;


#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 17, 0)
	pcie_get_minimum_link(pdev, &speed, &width);
#else
	pcie_bandwidth_available(pdev, NULL, &speed, &width);
#endif

	if (speed == PCIE_SPEED_2_5GT)
		id0 = 0;
	else if (speed == PCIE_SPEED_5_0GT)
		id0 = 1;
	else if (speed == PCIE_SPEED_8_0GT)
		id0 = 2;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 17, 0)
	else if (speed == PCIE_SPEED_16_0GT)
		id0 = 3;

#endif
	else
		return NULL;


	if (width == 1)
		id1 = 0;
	else if (width == 2)
		id1 = 1;
	else if (width == 4)
		id1 = 2;
	else if (width == 8)
		id1 = 3;
	else if (width == 16)
		id1 = 4;
	else
		return NULL;


	return (char *)(&link_info[id0 * 5 + id1]);
}

static void j9_handle__unfeelable(j9_weakliest *platform, u32 *freq, u32 *rate)
{
	u32 val, i;
	u32 ddr4_rate[8][2] = {
		{400, 1600}, {465, 1866}, {532, 2133}, {600, 2400},
		{665, 2666}, {732, 2933}, {800, 3200}, {931, 3733}
	};

	val = j9_handle_menarcheal(platform, J9MATHS_DERMATAGRA);
	for (i = 0; i < 8; i++) {
		if ((val >= ddr4_rate[i][0] - 5) && (val <= ddr4_rate[i][0] + 5)) {
			*freq = ddr4_rate[i][1] / 2;
			*rate = ddr4_rate[i][1];
			return;
		}
	}

	*freq = *rate = 0;
}

#define JMD_GPU_NAME_DATA(gpu_vendor_id, gpu_device_id, gpu_subsys_id, gpu_main_name, gpu_sub_name) \
	.vendor_id = gpu_vendor_id, \
	.device_id = gpu_device_id, \
	.subsys_id = gpu_subsys_id, \
	.main_name = gpu_main_name, \
	.sub_name  = gpu_sub_name

struct gpu_name_info {
	const char *main_name;
	const char *sub_name;
	unsigned short vendor_id;
	unsigned short device_id;
	unsigned short subsys_id;
};

static const char *gpuinfo_get_gpu_name(
		unsigned short vendor_id,
		unsigned short device_id,
		unsigned short subsys_id
		)
{
	unsigned short idx;
	const char *best_match = NULL;

	static struct gpu_name_info name_info[] = {
		{JMD_GPU_NAME_DATA(0x0731, 0x9100, 0x9101, "JM9100", "JM9100")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9100, 0x9102, "JM9100", "JM9100-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9100, 0x9103, "JM9100", "JM9100M")},
		{JMD_GPU_NAME_DATA(0x0731, 0x910a, 0x910a, "JH910",  "JH910")},
		{JMD_GPU_NAME_DATA(0x0731, 0x910a, 0x910b, "JH910",  "JH910-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x910a, 0x910c, "JH910",  "JH910-M")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9200, 0x0000, "JM9200", "JM9200")},
		{JMD_GPU_NAME_DATA(0x0731, 0x920a, 0x920a, "JH920",  "JH920")},
		{JMD_GPU_NAME_DATA(0x0731, 0x920a, 0x920b, "JH920",  "JH920-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x920a, 0x920c, "JH920",  "JH920-M")},
		{JMD_GPU_NAME_DATA(0x0731, 0x920a, 0x920d, "JH920",  "JH920-II")},
		{JMD_GPU_NAME_DATA(0x0731, 0x920b, 0x0000, "JH920-I", "JH920-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x920c, 0x0000, "JH920-M", "JH920-M")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9210, 0x9210, "JM9210", "JM9210")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9210, 0x9211, "JM9210", "JM9210-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9211, 0x0000, "JM9210-I", "JM9210-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9230, 0x9230, "JM9230", "JM9230")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9230, 0x9231, "JM9230", "JM9230-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9231, 0x0000, "JM9231-I", "JM9231-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x9250, 0x9250, "JM9250", "JM9250")},
		{JMD_GPU_NAME_DATA(0x0731, 0x930a, 0x930a, "JH930-I",  "JH930-I")},
		{JMD_GPU_NAME_DATA(0x0731, 0x930a, 0x930b, "JH930-I",  "JH930-M")},
		{JMD_GPU_NAME_DATA(0x0731, 0x930a, 0x930c, "JH930-I",  "JH930")},
		{JMD_GPU_NAME_DATA(0x0731, 0x930a, 0x930d, "JH930-I",  "JH930-II")},
		{JMD_GPU_NAME_DATA(0x0731, 0x930b, 0x0000, "JH930-M", "JH930-M")}
	};

	for (idx = 0; idx < ARRAY_SIZE(name_info); idx++) {
		if (name_info[idx].vendor_id == vendor_id && name_info[idx].device_id == device_id) {
			best_match = name_info[idx].main_name;
			if (name_info[idx].subsys_id == subsys_id) {
				best_match = name_info[idx].sub_name;
				break;
			}
		}
	}

	return best_match;
}

static int j9_osteometrical(struct seq_file *seq, void *offset)
{
	u32 vram_rate;
	j9_weakliest *platform;
	jmk_GALDEVICE dev;
	u32 max2dfreq, rate3d, ddr4_freq = 0, ddr4_rate = 0;
	u64 vram_size;
	s16 temp;
	char *fver, *fodm, *link_info;
	const char *gpu_name;
	struct device *ddev;
	struct pci_dev *pdev;
	u32 vm_id;

	dev = seq->private;
	if (!dev)
		return 0;


	platform = dev->platform;
	if (!platform)
		return 0;


	ddev = platform->ops->getSubDevice(platform);
	if (!ddev)
		return 0;


	pdev = to_pci_dev(ddev);
	if (!pdev)
		return 0;


	vram_size = platform->params.vram_size;
	fver      = platform->params.firmware_version;
	fodm      = platform->params.odm_manufacture;
	vram_rate = platform->params.vram_rate;
	link_info = j9_hymenopterist(platform);
	gpu_name  = gpuinfo_get_gpu_name(pdev->vendor, pdev->device, pdev->subsystem_device);
	temp      = j9mirror_peridinian(platform);
	max2dfreq    = j9mirror_annuisance(dev->dvfs, J9_PHYLLOPYRROLE);

	vm_id     = JM_VGPU_GET_ID(platform->params.vinfo);
	if (vm_id == 2)
		rate3d = j9mirror_annuisance(dev->dvfs, J9_COMPREHENSIBLY);
	else if (vm_id == 1)
		rate3d = j9mirror_annuisance(dev->dvfs, J9_HOMOGENIZATION);
	else
		rate3d = j9mirror_annuisance(dev->dvfs, J9_PREOPPRESSION);

    if (platform->params.family == J9_BREASTLESS) {
		j9_handle__unfeelable(platform, &ddr4_freq, &ddr4_rate);
	}


	seq_printf(seq, "Vendor                      : %s\n", "Changsha JingJia Microelectronics Co.");
	seq_printf(seq, "Vendor ID                   : %s\n", "0731");
	seq_printf(seq, "Device ID                   : %x\n", pdev->device);
	if (gpu_name)
	seq_printf(seq, "GPU                         : %s\n", gpu_name);

	seq_printf(seq, "Bus Type                    : %s\n", link_info ? link_info : "Unknown");
	seq_printf(seq, "Number of Stream Processors : %s\n", (platform->params.family == J9_BREASTLESS) ? "256" : "512");
	if (pdev->device != 0x930a)
	seq_printf(seq, "Memory Type                 : %s\n", platform->params.mem_type);

	seq_printf(seq, "Memory Size                 : %lld MB\n", vram_size / 1024 / 1024);
	seq_printf(seq, "Memory Remain Size          : %u MB\n", j9_handle_j9m_unhelpable(dev));
	seq_printf(seq, "Memory Bit Wide             : %s\n", "64");
	if (platform->params.family == J9_UNGLADSOME)
	seq_printf(seq, "Memory Transfer Rate        : %u.%u GB/s\n", vram_rate / 10, vram_rate % 10);

	if ((platform->params.family == J9_BREASTLESS) && (ddr4_freq != 0)) {
		seq_printf(seq, "Memory Frequency            : %u MHz\n", ddr4_freq);
		seq_printf(seq, "Memory Transfer Rate        : %u Mbps\n", ddr4_rate);
	}

	seq_printf(seq, "GPU Frequency               : %u MHz\n", max2dfreq);

	if (platform->params.pmbus_present) {
		seq_printf(seq, "Core Voltage                : %u mV\n", j9_handle__menarcheal(platform));
	}

	seq_printf(seq, "Kernel Version              : %s\n", J9MATHS_DISUNIFORM);
	seq_printf(seq, "Firmware Version            : %s\n", fver ? fver : "Unknown");
	if (fodm)
	seq_printf(seq, "ODM Manufacture             : %s\n", fodm);

	seq_printf(seq, "Realtime Temperature        : %d.%02u Degree Centigrade\n", (s32)temp / 100, (u32)temp % 100);
	seq_printf(seq, "GPU Utilize Rate            : %d.%02d%%\n", rate3d / 100, rate3d % 100);

	return 0;
}

static s32 j9_horsetree(struct inode *inode, struct file *file)
{
	/* PDE_DATA() was renamed to the pde_data() helper in newer kernels. */
	jmk_GALDEVICE dev = pde_data(inode);
	return single_open(file, j9_osteometrical, dev);
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
static const struct proc_ops gpuinfo_file_ops = {
	.proc_open    = j9_horsetree,
	.proc_read    = seq_read,
	.proc_lseek   = seq_lseek,
	.proc_release = single_release
};
#else
static const struct file_operations gpuinfo_file_ops = {
	.owner   = THIS_MODULE,
	.open    = j9_horsetree,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = single_release
};
#endif

j9_carpalia *j9_handle_aneuploidy(jmk_GALDEVICE dev)
{
	j9_carpalia *gpuinfo;
	struct proc_dir_entry *ent;
	struct file *filp = J9_CHYAK;
	char proc_name[J9_HANDLE__COHABITING];
	int num;

	if (dev == J9_CHYAK)
		return J9_CHYAK;


	gpuinfo = (j9_carpalia *)kzalloc(sizeof(j9_carpalia), GFP_KERNEL);
	if (!gpuinfo)
		return J9_CHYAK;

	jmgpu_gpuinfo_fs_create(dev);

	gpuinfo->created = J9_YARELY;
	for (num = 0; num < J9_INTERLINEATION; num++) {
		snprintf(gpuinfo->name, J9_HANDLE__COHABITING, "gpuinfo_%d", num);
		snprintf(proc_name, J9_HANDLE__COHABITING, "/proc/%s", gpuinfo->name);
		filp = filp_open(proc_name, O_RDONLY, 0);
		if (!IS_ERR(filp)) {
			fput(filp);
			continue;
		}

		ent = proc_create_data(gpuinfo->name, S_IRUGO, NULL, &gpuinfo_file_ops, dev);
		if (ent) {
			gpuinfo->created = J9_CUPPY;
			return gpuinfo;
		}
	}

	kfree(gpuinfo);
	return J9_CHYAK;
}

void jmgpu_gpuinfo_destroy(jmk_GALDEVICE dev)
{
	j9_carpalia *gpuinfo = dev->gpuinfo;

	if (!gpuinfo)
		return;

	jmgpu_gpuinfo_fs_remove(dev);

	if (gpuinfo->created)
		remove_proc_entry(gpuinfo->name, NULL);

	kfree(gpuinfo);
}



