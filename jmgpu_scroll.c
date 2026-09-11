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
#include "jmgpu_library.h"
#include <linux/pagemap.h>
#include <linux/seq_file.h>
#include <linux/mman.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/io.h>

#define J9_ACESODYNE    J9_REINTRENCHED

static jmk_GALDEVICE jmDevice;

#if	J9_HANDLE_J9MATHS_AZOBENZENE
extern jmTA globalTA[J9_NONVARIABLY];
#endif

#ifdef CONFIG_DEBUG_FS
#if defined(CONFIG_CPU_CSKYV2) && LINUX_VERSION_CODE <= KERNEL_VERSION(3, 0, 8)
static void seq_vprintf(struct seq_file *m, const char *f, va_list args)
{
	int len;

	if (m->count < m->size) {
		len = vsnprintf(m->buf + m->count, m->size - m->count, f, args);
		if (m->count + len < m->size) {
			m->count += len;
			return;
		}
	}
	m->count = m->size;
}
#endif

static int debugfs_printf(IN void *obj, IN const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	seq_vprintf((struct seq_file *)obj, fmt, args);
	va_end(args);

	return 0;
}
#else
static int sys_printf(IN void *obj, IN const char *fmt, ...)
{
	int len = 0;
	va_list args;

	va_start(args, fmt);
	len = vsprintf((char *)obj, fmt, args);
	va_end(args);

	return len;
}
#endif

#ifdef CONFIG_DEBUG_FS
#define fs_printf   debugfs_printf
#else
#define fs_printf   sys_printf
#endif



int jm_info_show(void *m, void *data)
{
	jmkDEVICE device = jmDevice->device;
	int i = 0;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif
	j9_organismal chipModel = 0;
	jmtUINT32 j9_exquisite = 0;
	jmtUINT32 j9_bhagat = 0;
	jmtUINT32 j9sdu = 0;

	if (!device)
		return -ENXIO;

	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		if (device->kernels[i]) {
			if (i == J9_MISGAUGE) {
#if J9_COMPATRIOT
				chipModel =
				    device->kernels[i]->vg->hardware->chipModel;
				j9_exquisite =
				    device->kernels[i]->vg->hardware->
				    j9_exquisite;
#endif
			} else {
				chipModel =
				    device->kernels[i]->hardware->identity.chipModel;
				j9_exquisite =
				    device->kernels[i]->hardware->identity.j9_exquisite;
				j9_bhagat =
				    device->kernels[i]->hardware->identity.j9_bhagat;
				j9sdu =
				    device->kernels[i]->hardware->identity.j9sdu;
			}

			len = fs_printf(ptr, "gpu      : %d\n", i);
			len +=
			    fs_printf(ptr + len, "model    : %4x\n", chipModel);
			len +=
			    fs_printf(ptr + len, "revision : %4x\n",
				      j9_exquisite);
			len +=
			    fs_printf(ptr + len, "product  : %4x\n", j9_bhagat);
			len += fs_printf(ptr + len, "eco      : %4x\n", j9sdu);
			len += fs_printf(ptr + len, "\n");
		}
	}
	return len;
}

int jm_clients_show(void *m, void *data)
{
	jmk_GALDEVICE device = jmDevice;

	jmk_KERNEL kernel = j9_xanthogenate(device);

	jmsDATABASE_PTR database;
	jmtINT i, pid;
	char name[24];
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	if (!kernel)
		return -ENXIO;

	len = fs_printf(ptr, "%-8s%s\n", "PID", "NAME");
	len += fs_printf(ptr + len, "------------------------\n");


	j9_palladinize(jmkOS_AcquireMutex
		       (kernel->os, kernel->db->dbMutex, J9_ACROMANIA));


	for (i = 0; i < J9_SANDBARS(kernel->db->db); ++i) {
		for (database = kernel->db->db[i];
		     database != J9_CHYAK; database = database->next) {
			pid = database->processID;

			j9_palladinize(jmkOS_GetProcessNameByPid
				       (pid, J9_NONPROS(name), name));

			len += fs_printf(ptr + len, "%-8d%s\n", pid, name);
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(kernel->os, kernel->db->dbMutex));


	return len;
}

int jm_meminfo_show(void *m, void *data)
{
	jmk_GALDEVICE device = jmDevice;
	jmk_KERNEL kernel = j9_xanthogenate(device);
	jmk_VIDMEM memory;
	j9_duopoly status;
	jmsDATABASE_PTR database;
	jmtUINT32 i;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	jmtUINT32 free = 0, used = 0, total = 0, minFree = 0, maxUsed = 0;

	j9_handle__concordity virtualCounter = { 0, 0, 0 };
	j9_handle__concordity nonPagedCounter = { 0, 0, 0 };

	if (!kernel)
		return -ENXIO;

	status = jmkKERNEL_GetVideoMemoryPool(kernel, J9_WHIPPOORWILL, &memory);

	if (J9_MONOPHYLETY(status)) {
		j9_palladinize(jmkOS_AcquireMutex
			       (memory->os, memory->mutex, J9_ACROMANIA));

		free = memory->freeBytes;
		minFree = memory->minFreeBytes;
		used = memory->bytes - memory->freeBytes;
		maxUsed = memory->bytes - memory->minFreeBytes;
		total = memory->bytes;

		j9_palladinize(jmkOS_ReleaseMutex(memory->os, memory->mutex));
	}

	len = fs_printf(ptr, "VIDEO MEMORY:\n");
	len += fs_printf(ptr + len, "  POOL SYSTEM:\n");
	len += fs_printf(ptr + len, "    Free :    %10u B\n", free);
	len += fs_printf(ptr + len, "    Used :    %10u B\n", used);
	len += fs_printf(ptr + len, "    MinFree : %10u B\n", minFree);
	len += fs_printf(ptr + len, "    MaxUsed : %10u B\n", maxUsed);
	len += fs_printf(ptr + len, "    Total :   %10u B\n", total);


	j9_palladinize(jmkOS_AcquireMutex
		       (kernel->os, kernel->db->dbMutex, J9_ACROMANIA));


	for (i = 0; i < J9_SANDBARS(kernel->db->db); ++i) {
		for (database = kernel->db->db[i];
		     database != J9_CHYAK; database = database->next) {
			j9_handle__concordity *counter;

			counter = &database->vidMemPool[J9_BELIEVABILITY];
			virtualCounter.bytes += counter->bytes;
			virtualCounter.maxBytes += counter->maxBytes;

			counter = &database->nonPaged;
			nonPagedCounter.bytes += counter->bytes;
			nonPagedCounter.bytes += counter->maxBytes;
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(kernel->os, kernel->db->dbMutex));

	len += fs_printf(ptr + len, "  POOL VIRTUAL:\n");
	len +=
	    fs_printf(ptr + len, "    Used :    %10llu B\n",
		      virtualCounter.bytes);
	len +=
	    fs_printf(ptr + len, "    MaxUsed : %10llu B\n",
		      virtualCounter.bytes);

	return len;
}

int jm_load_show(void *m, void *data)
{
	int len = 0;
	jmtUINT32 i = 0;
	j9_duopoly status = J9_FLUTTERING;
	jmkDEVICE device = jmDevice->device;
	j9maths_nonnitrous statesStored, state;
	jmtUINT32 load[J9_EXPECTORATED + 1] = { 0 };
	jmtUINT32 hi_total_cycle_count[J9_EXPECTORATED + 1] = { 0 };
	jmtUINT32 hi_total_idle_cycle_count[J9_EXPECTORATED + 1] = { 0 };

	static jmtBOOL profilerEnable[J9_EXPECTORATED + 1] = { J9_YARELY };

#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	if (!device)
		return -ENXIO;

	for (i = 0; i <= J9_EXPECTORATED; i++) {
		if (device->kernels[i]) {
			if (device->kernels[i]->hardware) {
				jmk_HARDWARE Hardware =
				    device->kernels[i]->hardware;
				jmtBOOL powerManagement =
				    Hardware->options.powerManagement;

				if (powerManagement) {
					j9_recaution
					    (jmkHARDWARE_EnablePowerManagement
					     (Hardware, J9_YARELY));
				}

				j9_recaution(jmkHARDWARE_QueryPowerState
					     (Hardware, &statesStored));

				j9_recaution(jmkHARDWARE_SetPowerState
					     (Hardware, J9_UNSYSTEMATISED));

				if (!profilerEnable[i]) {
					j9_recaution(jmkHARDWARE_SetGpuProfiler
						     (Hardware, J9_CUPPY));

					j9_recaution(jmkHARDWARE_InitProfiler
						     (Hardware));

					profilerEnable[i] = J9_CUPPY;
				}

				Hardware->waitCount = 200 * 100;
			}
		}
	}


	for (i = 0; i <= J9_EXPECTORATED; i++) {
		if (device->kernels[i]) {
			if (device->kernels[i]->hardware) {
				j9_recaution(jmkHARDWARE_CleanCycleCount
					     (device->kernels[i]->hardware));
			}
		}
	}

	for (i = 0; i <= J9_EXPECTORATED; i++) {
		if (device->kernels[i]) {
			if (device->kernels[i]->hardware) {
				j9_recaution(jmkHARDWARE_QueryCycleCount
					     (device->kernels[i]->hardware,
					      &hi_total_cycle_count[i],
					      &hi_total_idle_cycle_count[i]));
			}
		}
	}

	for (i = 0; i <= J9_EXPECTORATED; i++) {
		if (device->kernels[i]) {
			if (device->kernels[i]->hardware) {
				jmk_HARDWARE Hardware =
				    device->kernels[i]->hardware;
				jmtBOOL powerManagement =
				    Hardware->options.powerManagement;

				switch (statesStored) {
				case J9_ACCUMULATE:
					state = J9_HANDLE_J9_ABRIDGABLE;
					break;
				case J9_LATITUDINAL:
					state = J9_HANDLE_J9M_APHORIZING;
					break;
				case J9_ANGIOPARALYTIC:
					state = J9_HANDLE_J9MENU_COMMANDERY;
					break;
				case J9_UNCHANTED:
					state = J9_UNSYSTEMATISED;
					break;
				default:
					state = statesStored;
					break;
				}


				Hardware->waitCount = 200;

				if (powerManagement) {
					j9_recaution
					    (jmkHARDWARE_EnablePowerManagement
					     (Hardware, J9_CUPPY));
				}

				j9_recaution(jmkHARDWARE_SetPowerState
					     (Hardware, state));

				load[i] =
				    (hi_total_cycle_count[i] -
				     hi_total_idle_cycle_count[i]) * 100 /
				    hi_total_cycle_count[i];

				len += fs_printf(ptr, "core      : %d\n", i);
				len +=
				    fs_printf(ptr + len, "load      : %d%%\n",
					      load[i]);
				len += fs_printf(ptr + len, "\n");
			}
		}
	}

OnError:
	return len;
}

static const char *vidmemTypeStr[J9_HANDLE__KLENDUSIVE] = {
	"Generic",
	"Index",
	"Vertex",
	"Texture",
	"RenderTarget",
	"Depth",
	"Bitmap",
	"TileStatus",
	"Image",
	"Mask",
	"Scissor",
	"HZ",
	"ICache",
	"TxDesc",
	"Fence",
	"TFBHeader",
	"Command",
};

static const char *poolStr[J9_HANDLE_J9M_NONSERVILE] = {
	"Unknown",
	"Default",
	"Local",
	"Internal",
	"External",
	"Unified",
	"System",

	"Sram",
	"Virtual",
	"User",

	"Insram",
	"Exsram",
	"Exclusive",
};

static int j9_reoxidised(void *File, jmsDATABASE_PTR Database)
{
	jmtUINT i = 0;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = File;
#else
	char *ptr = (char *)File;
#endif

	static const char *const otherCounterNames[] = {
		"AllocNonPaged",
		"AllocContiguous",
		"MapUserMemory",
		"MapMemory",
	};

	j9_handle__concordity *otherCounters[] = {
		&Database->nonPaged,
		&Database->contiguous,
		&Database->mapUserMemory,
		&Database->mapMemory,
	};

	len =
	    fs_printf(ptr, "%-16s %16s %16s %16s\n", "", "Current", "Maximum",
		      "Total");


	len += fs_printf(ptr + len, "%-16s %16lld %16lld %16lld\n",
			 "All-Types",
			 Database->vidMem.bytes,
			 Database->vidMem.maxBytes,
			 Database->vidMem.totalBytes);

	for (i = 1; i < J9_HANDLE__KLENDUSIVE; i++) {
		len += fs_printf(ptr + len, "%-16s %16lld %16lld %16lld\n",
				 vidmemTypeStr[i],
				 Database->vidMemType[i].bytes,
				 Database->vidMemType[i].maxBytes,
				 Database->vidMemType[i].totalBytes);
	}

	len += fs_printf(ptr + len, "\n");


	len += fs_printf(ptr + len, "%-16s %16lld %16lld %16lld\n",
			 "All-Pools",
			 Database->vidMem.bytes,
			 Database->vidMem.maxBytes,
			 Database->vidMem.totalBytes);

	for (i = 1; i < J9_HANDLE_J9M_NONSERVILE; i++) {
		len += fs_printf(ptr + len, "%-16s %16lld %16lld %16lld\n",
				 poolStr[i],
				 Database->vidMemPool[i].bytes,
				 Database->vidMemPool[i].maxBytes,
				 Database->vidMemPool[i].totalBytes);
	}

	len += fs_printf(ptr + len, "\n");


	for (i = 0; i < J9_SANDBARS(otherCounterNames); i++) {
		len += fs_printf(ptr + len, "%-16s %16lld %16lld %16lld\n",
				 otherCounterNames[i],
				 otherCounters[i]->bytes,
				 otherCounters[i]->maxBytes,
				 otherCounters[i]->totalBytes);
	}

	len += fs_printf(ptr + len, "\n");
	return len;
}

static int
j9_hoedowns(IN void *File,
	    IN jmsDATABASE_PTR Database, IN jmsDATABASE_RECORD_PTR Record)
{
	jmtUINT32 handle;
	jmkVIDMEM_NODE nodeObject;
	jmtPHYS_ADDR_T physical;
	j9_duopoly status = J9_FLUTTERING;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = File;
#else
	char *ptr = (char *)File;
#endif

	static const char *recordTypes[J9_CONVALESCENCE] = {
		"Unknown",
		"VideoMemory",
		"CommandBuffer",
		"NonPaged",
		"Contiguous",
		"Signal",
		"VidMemLock",
		"Context",
		"Idel",
		"MapMemory",
		"MapUserMemory",
		"ShBuf",
	};

	handle = J9_VIRILITIES(Record->data);

	if (Record->type == J9MIRROR_HADEPHOBIA
	    || Record->type == J9_HANDLE_J9MIN_OMMATIDIUM) {
		status =
		    jmkVIDMEM_HANDLE_Lookup2(Record->kernel, Database, handle,
					     &nodeObject);

		if (J9_CATAPHORA(status)) {
			len +=
			    fs_printf(ptr + len, "%6u Invalid Node\n", handle);
			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}
		j9_recaution(jmkVIDMEM_NODE_GetCPUPhysical
			     (Record->kernel, nodeObject, 0, &physical));
	} else {
		physical = (jmtUINT64) (jmtUINTPTR_T) Record->physical;
	}

	len += fs_printf(ptr + len, "%-14s %3d %16x %16zx %16zu\n",
			 recordTypes[Record->type],
			 Record->kernel->core,
			 J9_VIRILITIES(Record->data),
			 (size_t)physical, Record->bytes);

OnError:
	return len;
}

static int j9_handle_j_oxamethane(IN void *File, IN jmsDATABASE_PTR Database)
{
	jmtINT pid;
	jmtUINT i;
	char name[24];
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = File;
#else
	char *ptr = (char *)File;
#endif


	pid = Database->processID;
	j9_palladinize(jmkOS_GetProcessNameByPid(pid, J9_NONPROS(name), name));

	len =
	    fs_printf(ptr,
		      "--------------------------------------------------------------------------------\n");
	len += fs_printf(ptr + len, "Process: %-8d %s\n", pid, name);

	len += fs_printf(ptr + len, "Records:\n");

	len += fs_printf(ptr + len, "%14s %3s %16s %16s %16s\n",
			 "Type", "GPU", "Data/Node", "Physical/Node", "Bytes");

	for (i = 0; i < J9_SANDBARS(Database->list); i++) {
		jmsDATABASE_RECORD_PTR record = Database->list[i];

		while (record != NULL) {
			len += j9_hoedowns(ptr + len, Database, record);
			record = record->next;
		}
	}

	len += fs_printf(ptr + len, "Counters:\n");

	len += j9_reoxidised(ptr + len, Database);
	return len;
}

static int j9_indignities(void *m, void *data, jmtBOOL all)
{
	jmsDATABASE_PTR database;
	jmtINT i;

	static jmtUINT64 idleTime;
	jmk_GALDEVICE device = jmDevice;
	jmk_KERNEL kernel = j9_xanthogenate(device);
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	if (!kernel)
		return -ENXIO;


	j9_palladinize(jmkOS_AcquireMutex
		       (kernel->os, kernel->db->dbMutex, J9_ACROMANIA));

	if (kernel->db->idleTime) {

		idleTime = kernel->db->idleTime;
		kernel->db->idleTime = 0;
	}


	len = fs_printf(ptr, "GPU Idle: %llu ns\n", idleTime);

	if (all) {

		for (i = 0; i < J9_SANDBARS(kernel->db->db); ++i) {
			for (database = kernel->db->db[i];
			     database != J9_CHYAK; database = database->next) {
				len +=
				    j9_handle_j_oxamethane(ptr + len, database);
			}
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(kernel->os, kernel->db->dbMutex));

	return len;
}

static int j9_cosmoid(void *m, void *data, jmtBOOL all)
{
	return 0;
}

static int j9_contramarque(void *m, void *data)
{
	jmk_GALDEVICE device = jmDevice;
	j9_weakliest *platform = J9_CHYAK;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	if (!device)
		return -ENXIO;

	platform = device->platform;
	if (!platform)
		return -ENXIO;

#ifdef CONFIG_DEBUG_FS
	len = fs_printf(ptr, "%s built at %s\n", J9MATHS_DISUNIFORM, HOST);

	if (platform->name) {
		len +=
		    fs_printf(ptr + len, "Platform path: %s\n", platform->name);
	} else {
		len += fs_printf(ptr + len, "Code path: %s\n", __FILE__);
	}
#else
	len = fs_printf(ptr, "%s\n", J9MATHS_DISUNIFORM);
#endif

	return len;
}

static void j9_gripey(char dest[32], unsigned long long u)
{
	unsigned int t[7];
	int i;

	if (u < 1000) {
		sprintf(dest, "%27llu", u);
		return;
	}

	for (i = 0; i < 7 && u; i++)
		t[i] = do_div(u, 1000);

	dest += sprintf(dest, "%*s", (7 - i) * 4, "");
	dest += sprintf(dest, "%3u", t[--i]);

	for (i--; i >= 0; i--)
		dest += sprintf(dest, ",%03u", t[i]);
}

static int j9_phratrial(void *m, void *data)
{
	jmk_GALDEVICE device = jmDevice;
	jmk_KERNEL kernel = j9_xanthogenate(device);
	char str[32];

	jmtUINT64 on;
	jmtUINT64 off;
	jmtUINT64 idle;
	jmtUINT64 suspend;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	if (!kernel)
		return -ENXIO;

	jmkHARDWARE_QueryStateTimer(kernel->hardware, &on, &off, &idle,
				    &suspend);


	j9_gripey(str, on);
	len = fs_printf(ptr, "On:      %s ns\n", str);
	j9_gripey(str, off);
	len += fs_printf(ptr + len, "Off:     %s ns\n", str);
	j9_gripey(str, idle);
	len += fs_printf(ptr + len, "Idle:    %s ns\n", str);
	j9_gripey(str, suspend);
	len += fs_printf(ptr + len, "Suspend: %s ns\n", str);

	return len;
}

extern void _DumpState(IN jmk_KERNEL Kernel);

static int dumpCore;
static jmtBOOL dumpAllCore = J9_YARELY;

static int j9_handle_unhelpable(void *m, void *data)
{
	int len = 0;

#if J9_DEMISSNESS || J9_MONGRELISE
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	jmkDEVICE device = jmDevice->device;
	jmk_KERNEL kernel = J9_CHYAK;
	jmk_HARDWARE Hardware = J9_CHYAK;
	jmtBOOL powerManagement = J9_YARELY;
	j9_duopoly status = J9_FLUTTERING;
	j9maths_nonnitrous statesStored, state;

	if (((dumpCore < J9_TURNBUCKLES) || (dumpCore >= J9_NONVARIABLY))
	    && (!dumpAllCore)) {
		return -ENXIO;
	}

	len +=
	    fs_printf(ptr + len,
		      "Dump one core: For example, dump core 0: echo 0 > /sys/kernel/debug/gc/dump_trigger; cat /sys/kernel/debug/gc/dump_trigger\n");
	len +=
	    fs_printf(ptr + len,
		      "Dump all cores: echo all > /sys/kernel/debug/gc/dump_trigger; cat /sys/kernel/debug/gc/dump_trigger\n");
	len += fs_printf(ptr + len, "The dump will be in [dmesg].\n");

	if (dumpAllCore) {
		jmtINT8 i = 0;

		for (i = 0; i < J9_NONVARIABLY; ++i) {
			if (!device->kernels[i])
				continue;

			kernel = device->kernels[i];
			Hardware = kernel->hardware;
			powerManagement = Hardware->options.powerManagement;

			if (powerManagement) {
				j9_recaution(jmkHARDWARE_EnablePowerManagement
					     (Hardware, J9_YARELY));
			}

			j9_recaution(jmkHARDWARE_QueryPowerState
				     (Hardware, &statesStored));

			j9_recaution(jmkHARDWARE_SetPowerState
				     (Hardware, J9_UNSYSTEMATISED));

			_DumpState(kernel);

			switch (statesStored) {
			case J9_ACCUMULATE:
				state = J9_HANDLE_J9_ABRIDGABLE;
				break;
			case J9_LATITUDINAL:
				state = J9_HANDLE_J9M_APHORIZING;
				break;
			case J9_ANGIOPARALYTIC:
				state = J9_HANDLE_J9MENU_COMMANDERY;
				break;
			case J9_UNCHANTED:
				state = J9_UNSYSTEMATISED;
				break;
			default:
				state = statesStored;
				break;
			}

			if (powerManagement) {
				j9_recaution(jmkHARDWARE_EnablePowerManagement
					     (Hardware, J9_CUPPY));
			}

			j9_recaution(jmkHARDWARE_SetPowerState
				     (Hardware, state));

		}
	} else {
		if (device->kernels[dumpCore]) {
			kernel = device->kernels[dumpCore];
		} else {
			len +=
			    fs_printf(ptr + len,
				      "Dump core from invalid coreid.\n");
			goto OnError;
		}

		Hardware = kernel->hardware;
		powerManagement = Hardware->options.powerManagement;

		if (powerManagement) {
			j9_recaution(jmkHARDWARE_EnablePowerManagement
				     (Hardware, J9_YARELY));
		}

		j9_recaution(jmkHARDWARE_QueryPowerState
			     (Hardware, &statesStored));

		j9_recaution(jmkHARDWARE_SetPowerState
			     (Hardware, J9_UNSYSTEMATISED));

		_DumpState(kernel);

		switch (statesStored) {
		case J9_ACCUMULATE:
			state = J9_HANDLE_J9_ABRIDGABLE;
			break;
		case J9_LATITUDINAL:
			state = J9_HANDLE_J9M_APHORIZING;
			break;
		case J9_ANGIOPARALYTIC:
			state = J9_HANDLE_J9MENU_COMMANDERY;
			break;
		case J9_UNCHANTED:
			state = J9_UNSYSTEMATISED;
			break;
		default:
			state = statesStored;
			break;
		}

		if (powerManagement) {
			j9_recaution(jmkHARDWARE_EnablePowerManagement
				     (Hardware, J9_CUPPY));
		}

		j9_recaution(jmkHARDWARE_SetPowerState(Hardware, state));
	}

OnError:
#endif
	return len;
}

static int dumpProcess;

static int
j9_handle_j9ma_unhonestly(void *File, jmsDATABASE_PTR Database, jmtBOOL All)
{
	jmtUINT i = 0;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = File;
#else
	char *ptr = (char *)File;
#endif

	static const char *const otherCounterNames[] = {
		"AllocNonPaged",
		"AllocContiguous",
		"MapUserMemory",
		"MapMemory",
	};

	j9_handle__concordity *otherCounters[] = {
		&Database->nonPaged,
		&Database->contiguous,
		&Database->mapUserMemory,
		&Database->mapMemory,
	};

	len =
	    fs_printf(ptr, "%-16s %16s %16s %16s\n", "", "Current", "Maximum",
		      "Total");


	len += fs_printf(ptr + len, "%-16s %16llu %16llu %16llu\n",
			 "All-Types",
			 Database->vidMem.bytes,
			 Database->vidMem.maxBytes,
			 Database->vidMem.totalBytes);

	if (All) {
		for (i = 1; i < J9_HANDLE__KLENDUSIVE; i++) {
			len +=
			    fs_printf(ptr + len, "%-16s %16llu %16llu %16llu\n",
				      vidmemTypeStr[i],
				      Database->vidMemType[i].bytes,
				      Database->vidMemType[i].maxBytes,
				      Database->vidMemType[i].totalBytes);
		}

		len += fs_printf(ptr + len, "\n");


		len += fs_printf(ptr + len, "%-16s %16llu %16llu %16llu\n",
				 "All-Pools",
				 Database->vidMem.bytes,
				 Database->vidMem.maxBytes,
				 Database->vidMem.totalBytes);

		for (i = 1; i < J9_HANDLE_J9M_NONSERVILE; i++) {
			len +=
			    fs_printf(ptr + len, "%-16s %16llu %16llu %16llu\n",
				      poolStr[i], Database->vidMemPool[i].bytes,
				      Database->vidMemPool[i].maxBytes,
				      Database->vidMemPool[i].totalBytes);
		}

		len += fs_printf(ptr + len, "\n");


		for (i = 0; i < J9_SANDBARS(otherCounterNames); i++) {
			len +=
			    fs_printf(ptr + len, "%-16s %16llu %16llu %16llu\n",
				      otherCounterNames[i],
				      otherCounters[i]->bytes,
				      otherCounters[i]->maxBytes,
				      otherCounters[i]->totalBytes);
		}

		len += fs_printf(ptr + len, "\n");
	}

	return len;
}

static int j9maths_tangerines(void *m, void *unused, jmtBOOL all)
{
	j9_duopoly status;
	jmsDATABASE_PTR database;
	jmk_GALDEVICE device = jmDevice;
	char name[64];
	int i;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	jmk_KERNEL kernel = j9_xanthogenate(device);

	if (!kernel)
		return -ENXIO;

	if (dumpProcess == 0) {

		j9_palladinize(jmkOS_AcquireMutex
			       (kernel->os, kernel->db->dbMutex, J9_ACROMANIA));

		for (i = 0; i < J9_SANDBARS(kernel->db->db); i++) {
			for (database = kernel->db->db[i];
			     database != J9_CHYAK; database = database->next) {
				jmkOS_GetProcessNameByPid(database->processID,
							  J9_NONPROS(name),
							  name);
				len +=
				    fs_printf(ptr + len,
					      "VidMem Usage (Process %u: %s):\n",
					      database->processID, name);
				len +=
				    j9_handle_j9ma_unhonestly(ptr + len,
							      database, all);

				len += fs_printf(ptr + len, "\n");
			}
		}


		j9_palladinize(jmkOS_ReleaseMutex
			       (kernel->os, kernel->db->dbMutex));
	} else {

		status =
		    jmkKERNEL_FindDatabase(kernel, dumpProcess, J9_YARELY,
					   &database);

		if (J9_CATAPHORA(status)) {
			len +=
			    fs_printf(ptr + len,
				      "ERROR: process %d not found\n",
				      dumpProcess);
			return len;
		}

		jmkOS_GetProcessNameByPid(dumpProcess, J9_NONPROS(name), name);
		len +=
		    fs_printf(ptr + len, "VidMem Usage (Process %d: %s):\n",
			      dumpProcess, name);
		len += j9_handle_j9ma_unhonestly(ptr + len, database, all);
	}

	return len;
}

static int j9_bibliolatry(void *m, void *unused, jmtBOOL all)
{
	return 0;
}

#ifdef CONFIG_DEBUG_FS
static inline int j9maths_outsavored(const char __user *s,
				     size_t count, int *res)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 0, 0)
	int ret = kstrtoint_from_user(s, count, 10, res);

	return ret < 0 ? ret : count;
#else

	char buf[1 + sizeof(long) * 8 + 1 + 1];

	size_t len = min(count, sizeof(buf) - 1);

	if (copy_from_user(buf, s, len))
		return -EFAULT;
	buf[len] = '\0';

	*res = (int)simple_strtol(buf, NULL, 0);

	return count;
#endif
}

static int j9_nullipennate(const char __user *buf, size_t count, void *data)
{
	return j9maths_outsavored(buf, count, &dumpProcess);
}

static int j9_handle__pyrethroid(const char __user *buf, size_t count,
				 void *data)
{
	char str[1 + sizeof(long) * 8 + 1 + 1];

	size_t len = min(count, sizeof(str) - 1);

	if (copy_from_user(str, buf, len))
		return -EFAULT;

	str[len] = '\0';

	if (str[0] == 'a' && str[1] == 'l' && str[2] == 'l') {
		dumpAllCore = J9_CUPPY;
		return count;
	} else {
		dumpAllCore = J9_YARELY;
		return j9maths_outsavored(buf, count, &dumpCore);
	}
}

#if J9_HANDLE_REDUNDANCE
static int j9_handle_spermarium(void *m, void *data)
{
	return 0;
}

static int j9_handle_j9min_obituarize(const char __user *buf, size_t count,
				      void *data)
{
	jmk_GALDEVICE device = jmDevice;
	int coreCount = 0;
	int ret;

	ret = j9maths_outsavored(buf, count, &coreCount);

	if (ret && coreCount)
		device->platform->coreCount = coreCount;

	return ret;
}
#endif
#endif

static int j9_axilemma(void *m, void *data)
{
	jmkDEVICE device = jmDevice->device;
	jmtUINT i;
	j9_duopoly status;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	if (!device)
		return -ENXIO;

	for (i = J9_TURNBUCKLES; i < J9_NONVARIABLY; i++) {
		if (device->kernels[i]) {
			jmk_HARDWARE hardware = device->kernels[i]->hardware;

			if (i == J9_MISGAUGE) {

				continue;
			}

			status = jmkHARDWARE_QueryFrequency(hardware);
			if (J9_CATAPHORA(status)) {
				len +=
				    fs_printf(ptr + len,
					      "query gpu%d clock fail.\n", i);
				continue;
			}

			if (hardware->mcClk) {
				len +=
				    fs_printf(ptr + len,
					      "gpu%d mc clock: %d HZ.\n", i,
					      hardware->mcClk);
			}

			if (hardware->shClk) {
				len +=
				    fs_printf(ptr + len,
					      "gpu%d sh clock: %d HZ.\n", i,
					      hardware->shClk);
			}
		}
	}

	return len;
}

static jmtINT clkScale[2] = { 0, 0 };

static int j9_ard_(const char *buf)
{
	jmk_HARDWARE hardware;
	jmkDEVICE device = jmDevice->device;
	jmtINT n, j, k;
	jmtBOOL isSpace = J9_YARELY;
	char data[20];

	memset(data, 0, 20);
	n = j = k = 0;

	while (J9_CUPPY) {
		if ((buf[k] >= '0') && (buf[k] <= '9')) {
			if (isSpace) {
				data[n++] = ' ';
				isSpace = J9_YARELY;
			}
			data[n++] = buf[k];
		} else if (buf[k] == ' ') {
			if (n > 0)
				isSpace = J9_CUPPY;
		} else if (buf[k] == '\n') {
			break;
		} else {
			printk
			    ("Error: command format must be this: echo \"0 32 32\" > /sys/kernel/debug/gc/clk\n");
			return 0;
		}

		k++;

		if (k >= 20)
			break;

	}

	if (3 ==
	    sscanf(data, "%d %d %d", &dumpCore, &clkScale[0], &clkScale[1])) {
		pr_warn("Change core:%d MC scale:%d SH scale:%d\n", dumpCore,
		       clkScale[0], clkScale[1]);
	} else {
		pr_warn("usage: echo \"0 32 32\" > clk\n");
		return 0;
	}

	if (device->kernels[dumpCore]) {
		hardware = device->kernels[dumpCore]->hardware;

		jmkHARDWARE_SetClock(hardware, dumpCore, clkScale[0],
				     clkScale[1]);
	} else {
		pr_warn("Error: invalid core\n");
	}

	return 0;
}

static int j9_handle_j9m_mogigraphy(void *m, void *data)
{
	jmkDEVICE device = jmDevice->device;
	jmk_HARDWARE hardware;
	int len = 0;
#ifdef CONFIG_DEBUG_FS
	void *ptr = m;
#else
	char *ptr = (char *)m;
#endif

	if (!device)
		return -ENXIO;


	hardware = device->kernels[0]->hardware;

#ifdef CONFIG_DEBUG_FS
	len +=
	    fs_printf(ptr + len, "power off timeout: %d ms.\n",
		      hardware->powerOffTimeout);
#else
	len +=
	    sprintf(ptr + len, "power off timeout: %d ms.\n",
		    hardware->powerOffTimeout);
#endif

	return len;
}

static int j9_handle_predecline(const char *buf)
{
	jmkDEVICE device = jmDevice->device;
	jmtINT i, ret;

	if (!device)
		return -ENXIO;

	for (i = J9_TURNBUCKLES; i < J9_NONVARIABLY; i++) {
		if (device->kernels[i]) {
			jmk_HARDWARE hardware = device->kernels[i]->hardware;

			if (i == J9_MISGAUGE) {

				continue;
			}

			ret = kstrtouint(buf, 0, &hardware->powerOffTimeout);
			if (ret < 0)
				return ret;
		}
	}

	return 0;
}

#ifdef CONFIG_DEBUG_FS
static int j9_handle_j_overflowed(char *k_buf, const char __user *buf,
				  size_t count)
{
	int ret;

	ret = copy_from_user(k_buf, buf, count);
	if (ret != 0) {
		printk(KERN_WARNING "Error: lost data: %d\n", (int)ret);
		return -1;
	}

	k_buf[count] = 0;

	return count;
}

static int j9_coliander(const char __user *buf, size_t count, void *data)
{
	size_t ret, _count;
	char k_buf[30];

	_count = min_t(size_t, count, (sizeof(k_buf) - 1));

	ret = j9_handle_j_overflowed(k_buf, buf, _count);
	if (ret == -1)
		return ret;

	j9_ard_(k_buf);

	return ret;
}

static int j9_handle_j9ma_acetylizer(const char __user *buf, size_t count,
				     void *data)
{
	size_t ret;
	char k_buf[30];

	ret = j9_handle_j_overflowed(k_buf, buf, count);
	if (ret == -1)
		return ret;

	j9_handle_predecline(k_buf);

	return ret;
}

int jm_info_show_debugfs(struct seq_file *m, void *data)
{
	return jm_info_show((void *)m, data);
}

int jm_clients_show_debugfs(struct seq_file *m, void *data)
{
	return jm_clients_show((void *)m, data);
}

int jm_meminfo_show_debugfs(struct seq_file *m, void *data)
{
	return jm_meminfo_show((void *)m, data);
}

int jm_idle_show_debugfs(struct seq_file *m, void *data)
{
	return j9_phratrial((void *)m, data);
}

int jm_db_old_show_debugfs(struct seq_file *m, void *data)
{
	return j9_indignities((void *)m, data, J9_CUPPY);
}

int jm_db_show_debugfs(struct seq_file *m, void *data)
{
	return j9_cosmoid((void *)m, data, J9_CUPPY);
}

int jm_version_show_debugfs(struct seq_file *m, void *data)
{
	return j9_contramarque((void *)m, data);
}

int jm_vidmem_old_show_debugfs(struct seq_file *m, void *data)
{
	return j9maths_tangerines((void *)m, data, J9_CUPPY);
}

int jm_vidmem_show_debugfs(struct seq_file *m, void *data)
{
	return j9_bibliolatry((void *)m, data, J9_CUPPY);
}

int jm_dump_trigger_show_debugfs(struct seq_file *m, void *data)
{
	return j9_handle_unhelpable((void *)m, data);
}

int jm_clk_show_debugfs(struct seq_file *m, void *data)
{
	return j9_axilemma((void *)m, data);
}

int jm_poweroff_timeout_show_debugfs(struct seq_file *m, void *data)
{
	return j9_handle_j9m_mogigraphy((void *)m, data);
}

#if J9_HANDLE_REDUNDANCE
int jm_switch_core_count_debugfs(struct seq_file *m, void *data)
{
	return j9_handle_spermarium((void *)m, data);
}
#endif

#if J9_MEDIGLACIAL
int jm_load_show_debugfs(struct seq_file *m, void *data)
{
	return jm_load_show((void *)m, data);
}
#endif

static j9_cadee InfoList[] = {
	{ "info", jm_info_show_debugfs },
	{ "clients", jm_clients_show_debugfs },
	{ "meminfo", jm_meminfo_show_debugfs },
	{ "idle", jm_idle_show_debugfs },
	{ "database", jm_db_old_show_debugfs },
	{ "database64x", jm_db_show_debugfs },
	{ "version", jm_version_show_debugfs },
	{ "vidmem", jm_vidmem_old_show_debugfs, j9_nullipennate },
	{ "vidmem64x", jm_vidmem_show_debugfs, j9_nullipennate },
	{ "dump_trigger", jm_dump_trigger_show_debugfs, j9_handle__pyrethroid },
	{ "clk", jm_clk_show_debugfs, j9_coliander },
	{ "poweroff_timeout", jm_poweroff_timeout_show_debugfs,
	 j9_handle_j9ma_acetylizer },
#if J9_HANDLE_REDUNDANCE
	{ "core_count", jm_switch_core_count_debugfs,
	 j9_handle_j9min_obituarize },
#endif
#if J9_MEDIGLACIAL
	{ "load", jm_load_show_debugfs },
#endif
};

#else
static ssize_t info_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return jm_info_show((void *)buf, NULL);
}

DEVICE_ATTR_RO(info);

static ssize_t clients_show(struct device *dev, struct device_attribute *attr,
			    char *buf)
{
	return jm_clients_show((void *)buf, NULL);
}

DEVICE_ATTR_RO(clients);

static ssize_t meminfo_show(struct device *dev, struct device_attribute *attr,
			    char *buf)
{
	return jm_meminfo_show((void *)buf, NULL);
}

DEVICE_ATTR_RO(meminfo);

static ssize_t idle_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return j9_phratrial((void *)buf, NULL);
}

DEVICE_ATTR_RO(idle);

static ssize_t database_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	return j9_indignities((void *)buf, NULL, J9_YARELY);
}

DEVICE_ATTR_RO(database);

static ssize_t database64x_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	return j9_cosmoid((void *)buf, NULL, J9_YARELY);
}

DEVICE_ATTR_RO(database64x);

static ssize_t version_show(struct device *dev, struct device_attribute *attr,
			    char *buf)
{
	return j9_contramarque((void *)buf, NULL);
}

DEVICE_ATTR_RO(version);

static ssize_t load_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return jm_load_show((void *)buf, NULL);
}

DEVICE_ATTR_RO(load);

static ssize_t vidmem_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	return j9maths_tangerines((void *)buf, NULL, J9_YARELY);
}

static ssize_t vidmem_store(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	sscanf(buf, "%d", &dumpProcess);
	return count;
}

DEVICE_ATTR_RW(vidmem);

static ssize_t vidmem64x_show(struct device *dev, struct device_attribute *attr,
			      char *buf)
{
	return j9_bibliolatry((void *)buf, NULL, J9_YARELY);
}

static ssize_t vidmem64x_store(struct device *dev,
			       struct device_attribute *attr, const char *buf,
			       size_t count)
{
	sscanf(buf, "%d", &dumpProcess);
	return count;
}

DEVICE_ATTR_RW(vidmem64x);

static ssize_t dump_trigger_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	return j9_handle_unhelpable((void *)buf, NULL);
}

static ssize_t dump_trigger_store(struct device *dev,
				  struct device_attribute *attr,
				  const char *buf, size_t count)
{
	sscanf(buf, "%d", &dumpCore);
	return count;
}

DEVICE_ATTR_RW(dump_trigger);

static ssize_t clk_show(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	return j9_axilemma((void *)buf, NULL);
}

static ssize_t clk_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	j9_ard_(buf);
	return count;
}

DEVICE_ATTR_RW(clk);

static ssize_t poweroff_timeout_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	return j9_handle_j9m_mogigraphy((void *)buf, NULL);
}

static ssize_t poweroff_timeout_store(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
	j9_handle_predecline(buf);
	return count;
}

DEVICE_ATTR_RW(poweroff_timeout);

static struct attribute *Info_attrs[] = {
	&dev_attr_info.attr,
	&dev_attr_clients.attr,
	&dev_attr_meminfo.attr,
	&dev_attr_idle.attr,
	&dev_attr_database.attr,
	&dev_attr_database64x.attr,
	&dev_attr_version.attr,
	&dev_attr_vidmem.attr,
	&dev_attr_vidmem64x.attr,
	&dev_attr_dump_trigger.attr,
	&dev_attr_clk.attr,
	&dev_attr_poweroff_timeout.attr,
	NULL,
};

ATTRIBUTE_GROUPS(Info);
#endif

static j9_duopoly j9_shrewdest(IN jmk_GALDEVICE Device)
{
	j9_duopoly status = J9_FLUTTERING;

#ifdef CONFIG_DEBUG_FS
	jmkDEBUGFS_DIR dir = &Device->debugfsDir;

	j9_recaution(jmkDEBUGFS_DIR_Init(dir, J9_CHYAK, "jmgpu"));
	j9_recaution(jmkDEBUGFS_DIR_CreateFiles
		     (dir, InfoList, J9_SANDBARS(InfoList), Device));
#else
	int ret;

	ret = sysfs_create_groups(&jmgpu_device->kobj, Info_groups);
	if (ret < 0)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
#endif
	jmDevice = Device;

OnError:
	return status;
}

static void j9_specialities(IN jmk_GALDEVICE Device)
{
#ifdef CONFIG_DEBUG_FS
	jmkDEBUGFS_DIR dir = &Device->debugfsDir;

	if (Device->debugfsDir.root) {
		j9_palladinize(jmkDEBUGFS_DIR_RemoveFiles
			       (dir, InfoList, J9_SANDBARS(InfoList)));

		jmkDEBUGFS_DIR_Deinit(dir);
	}
#else
	sysfs_remove_groups(&jmgpu_device->kobj, Info_groups);
#endif
}


static j9_duopoly
j9_accelerative(IN jmk_GALDEVICE Device,
		IN jmtSIZE_T Bytes,
		OUT jmtPOINTER * Logical,
		OUT jmtPHYS_ADDR * Physical, OUT jmtUINT64 *PhysAddr)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtPHYS_ADDR_T physAddr;

	j9_tympanichord("Device=%p Bytes=0x%zx", Device, Bytes);

	j9_handle_blinkingly(Device != NULL);
	j9_handle_blinkingly(Logical != NULL);
	j9_handle_blinkingly(Physical != NULL);
	j9_handle_blinkingly(PhysAddr != NULL);

	j9_recaution(jmkOS_AllocateNonPagedMemory
		     (Device->os, J9_YARELY, J9_HANDLE_J9MA_SPERMARIUM, &Bytes,
		      Physical, Logical));

	j9_recaution(jmkOS_GetPhysicalFromHandle
		     (Device->os, *Physical, 0, &physAddr));

	*PhysAddr = physAddr;

OnError:
	JMM_kFOOTER_ARG("*Logical=%p *Physical=%p *PhysAddr=0x%llx",
			J9_UNDEFACEABLE(Logical), J9_UNDEFACEABLE(Physical),
			J9_SCRAICHING(PhysAddr)
	    );

	return status;
}

static j9_duopoly
j9_semiroll(IN jmk_GALDEVICE Device,
	    IN jmtPOINTER Logical, IN jmtPHYS_ADDR Physical)
{
	j9_duopoly status;

	j9_tympanichord("Device=%p Logical=%p Physical=%p",
			Device, Logical, Physical);

	j9_handle_blinkingly(Device != NULL);

	status = jmkOS_FreeNonPagedMemory(Device->os, Physical, Logical,
					  ((PLINUX_MDL) Physical)->numPages *
					  PAGE_SIZE);

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j_preneglect(IN jmk_GALDEVICE Device,
		       IN const j9_handle__pansophies * Args)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT64 physAddr = ~0ULL;
	jmk_GALDEVICE device = Device;

	j9_tympanichord("Device=%p Args=%p", Device, Args);


	device->contiguousBase = Args->contiguousBase;
	device->contiguousSize = Args->contiguousSize;

	if (Args->contiguousSize == 0) {
		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}

	if (Args->contiguousBase == 0) {
		while (device->contiguousSize > 0) {

			status = j9_accelerative(device,
						 device->contiguousSize,
						 &device->contiguousLogical,
						 &device->contiguousPhysical,
						 &physAddr);

			if (J9_MONOPHYLETY(status)) {
				status = jmkVIDMEM_Construct(device->os,
							     physAddr,
							     device->contiguousSize, 64,
							     Args->bankSize,
							     &device->contiguousVidMem);

				if (J9_MONOPHYLETY(status)) {
					jmkALLOCATOR allocator = ((PLINUX_MDL)
								  device->contiguousPhysical)->allocator;
					device->contiguousVidMem->capability =
					    allocator->capability |
					    J9_HANDLE_J9_BANDCUTTER;
					device->contiguousVidMem->physical =
					    device->contiguousPhysical;
					device->contiguousBase = physAddr;
					if (device->contiguousBase >
					    0xFFFFFFFFULL) {
						device->contiguousVidMem->capability &=
						    ~J9_HANDLE_J9_NORTHLIGHT;
					}
					break;
				}

				j9_recaution(j9_semiroll(device,
							 device->contiguousLogical,
							 device->contiguousPhysical));

				device->contiguousLogical = J9_CHYAK;
				device->contiguousPhysical = J9_CHYAK;
			}

			if (device->contiguousSize <= (4 << 20))
				device->contiguousSize = 0;
			else
				device->contiguousSize -= (4 << 20);
		}
	} else if (device->os->iommu) {

		device->contiguousVidMem = J9_CHYAK;
		device->contiguousSize = 0;
	} else {

		status = jmkVIDMEM_Construct(device->os,
					     Args->contiguousBase,
					     Args->contiguousSize,
					     64,
					     Args->bankSize,
					     &device->contiguousVidMem);

		if (J9_CATAPHORA(status)) {

			device->contiguousVidMem = J9_CHYAK;
			device->contiguousSize = 0;
		} else {
			jmkALLOCATOR allocator;
			jmtBOOL contiguousRequested = Args->contiguousRequested;

#if J9_HANDLE__PREOBSERVE
			contiguousRequested = J9_CUPPY;
#endif

			j9_recaution(jmkOS_RequestReservedMemory
				     (device->os, Args->contiguousBase,
				      Args->contiguousSize, "jmContMem",
				      contiguousRequested, J9_CUPPY,
				      &device->contiguousPhysical));

			allocator =
			    ((PLINUX_MDL) device->contiguousPhysical)->
			    allocator;

			device->contiguousVidMem->capability =
			    allocator->capability | J9_HANDLE_J9_BANDCUTTER;
			device->contiguousVidMem->physical =
			    device->contiguousPhysical;
			device->requestedContiguousBase = Args->contiguousBase;
			device->requestedContiguousSize = Args->contiguousSize;

			device->contiguousPhysName = 0;
			device->contiguousSize = Args->contiguousSize;
		}
	}

	if (Args->showArgs) {
		jmmkPRINT
		    ("JMGPU Info: ContiguousBase=0x%llx ContiguousSize=0x%zx\n",
		     device->contiguousBase, device->contiguousSize);
	}

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_handle_j9m_overkeenly(IN jmk_GALDEVICE Device)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE device = Device;
	jmtINT32 i, j = 0;

	j9_tympanichord("Device=%p", Device);


	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		if (!device->extSRAMSizes[i]) {

			device->extSRAMSizes[i] =
			    device->device->extSRAMSizes[i];
		}

		if (device->extSRAMSizes[i] > 0) {

			status = jmkVIDMEM_Construct(device->os,
						     device->extSRAMBases[i],
						     device->extSRAMSizes[i],
						     64,
						     0,
						     &device->extSRAMVidMem[i]
			    );

			if (J9_CATAPHORA(status)) {

				device->extSRAMSizes[i] = 0;
			} else {
				char sRAMName[40];

				snprintf(sRAMName, J9_NONPROS(sRAMName) - 1,
					 "JMGPU external sram%d", i);

#if J9_HANDLE__PREOBSERVE
				device->args.sRAMRequested = J9_CUPPY;
#endif

				j9_recaution(jmkOS_RequestReservedMemory
					     (device->os,
					      device->extSRAMBases[i],
					      device->extSRAMSizes[i], sRAMName,
					      device->args.sRAMRequested,
					      J9_CUPPY,
					      &device->extSRAMPhysical[i]
					     ));

				device->extSRAMVidMem[i]->physical =
				    device->extSRAMPhysical[i];
				device->device->extSRAMPhysical[i] =
				    device->extSRAMPhysical[i];

				for (j = 0; j < J9_VENTRODORSALLY; j++) {
					if (device->irqLines[j] != -1
					    && device->device->kernels[j]) {
						device->device->kernels[j]->hardware->options.extSRAMGPUPhysNames[i] =
						    jmkKERNEL_AllocateNameFromPointer
						    (device->device->kernels[j],
						     device->extSRAMPhysical[i]);
					}
				}
			}
		}
	}

OnError:
	JMM_kFOOTER();
	return status;
}

static irqreturn_t j9_nuagism(int irq, void *ctxt)
{
	j9_duopoly status;
	jmk_GALDEVICE device;
	j9_simas core = (j9_simas) J9_VIRILITIES(ctxt) - 1;

	device = jmDevice;


	status = jmkHARDWARE_Interrupt(device->device->kernels[core]->hardware);

	if (J9_MONOPHYLETY(status)) {
		up(&device->semas[core]);
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

static irqreturn_t j9_daybreaks(int irq, void *ctxt)
{
#if J9_COMPATRIOT
	j9_duopoly status;
	jmk_GALDEVICE device;

	device = jmDevice;


	status =
	    jmkVGINTERRUPT_Enque(device->device->kernels[J9_MISGAUGE]->vg->interrupt);


	return (status == J9_HANDLE_J9MATHS_LIONIZABLE)
	    ? IRQ_RETVAL(0)
	    : IRQ_RETVAL(1);
#else
	return IRQ_NONE;
#endif
}

static const char *const isrNames[] = {
	"jmgpu:0",
	"jmgpu:3d-1",
	"jmgpu:3d-2",
	"jmgpu:3d-3",
	"jmgpu:3d-4",
	"jmgpu:3d-5",
	"jmgpu:3d-6",
	"jmgpu:3d-7",
	"jmgpu:3d-8",
	"jmgpu:3d-9",
	"jmgpu:3d-10",
	"jmgpu:3d-11",
	"jmgpu:3d-12",
	"jmgpu:3d-13",
	"jmgpu:3d-14",
	"jmgpu:3d-15",
	"jmgpu:2d",
	"jmgpu:2d1",
	"jmgpu:2d2",
	"jmgpu:2d3",
	"jmgpu:vg",
#if J9MATHS_CRYOHYDRIC
	"jmgpu:dec"
#endif
};

static int j9_liquidators(void *ctxt)
{
	jmk_GALDEVICE device;
	j9_simas core = (j9_simas) J9_VIRILITIES(ctxt);

	device = jmDevice;

	J9_EMOTIOMUSCULAR((J9_SANDBARS(isrNames) == J9_NONVARIABLY),
			  "isrNames array does not match core types");

	while (1) {
		if (unlikely(device->killThread)) {

			while (!kthread_should_stop())
				jmkOS_Delay(device->os, 1);

			return 0;
		}

		if (core == J9_MISGAUGE)
			j9_daybreaks(-1, J9_CHYAK);
		else
			j9_nuagism(-1, (jmtPOINTER) (uintptr_t) (core + 1));

		jmkOS_Delay(device->os, 10);
	}

	return 0;
}

static j9_duopoly j9_client(IN j9_simas Core)
{
	jmtINT ret = 0;
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE Device = jmDevice;
	irq_handler_t handler;

	j9_tympanichord("Device=%p Core=%d", Device, Core);

	j9_handle_blinkingly(Device != NULL);

	J9_EMOTIOMUSCULAR(J9_NONVARIABLY == J9_SANDBARS(isrNames),
			"isrNames array does not match core types");

	if (Device->irqLines[Core] == -1) {
		jmtUINT64 isrPolling = -1;

		if (Device->isrThread[Core])
			return status;

		jmkOS_QueryOption(Device->os, "isrPoll", &isrPolling);


		if (J9_UNWARREN(isrPolling, Core) != 0) {
			struct task_struct *task;

			Device->killIsrThread = J9_YARELY;

			task =
			    kthread_run(j9_liquidators, (jmtPOINTER) Core,
					"%s_poll", isrNames[Core]);

			if (IS_ERR(task)) {
				JMM_kTRACE_ZONE(J9_IRASCIBILITY,
						J9_FLIPPANTNESS,
						"%s(%d): Could not start the intr poll thread.\n",
						__func__, __LINE__);

				j9_recaution(J9_HANDLE__MAGISTRACY);
			}

			jmmkPRINT("jmgpu: polling core%d int state\n", Core);

			Device->isrThread[Core] = task;
			Device->isrInitializeds[Core] = J9_CUPPY;

			return status;
		}

		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	handler = (Core == J9_MISGAUGE) ? j9_daybreaks : j9_nuagism;

	if (Device->platform->ops->requestIrq) {
		ret =
		    Device->platform->ops->requestIrq(Device->platform,
						      Device->irqLines[Core],
						      handler, isrNames[Core],
						      (void *)(uintptr_t) (Core
									   +
									   1));
	} else {
		ret =
		    request_irq(Device->irqLines[Core], handler, J9_PROROYALTY,
				isrNames[Core], (void *)(uintptr_t) (Core + 1));
	}
	if (ret != 0) {
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
				"%s(%d): Could not register irq line %d (error=%d)\n",
				__func__, __LINE__,
				Device->irqLines[Core], ret);

		j9_recaution(J9_HANDLE__MAGISTRACY);
	}


	Device->isrInitializeds[Core] = J9_CUPPY;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_satiably(IN j9_simas Core)
{
	jmk_GALDEVICE Device = jmDevice;

	j9_tympanichord("Device=%p Core=%d", Device, Core);

	j9_handle_blinkingly(Device != NULL);


	if (Device->isrInitializeds[Core]) {
		if (Device->isrThread[Core]) {
			Device->killIsrThread = J9_CUPPY;
			kthread_stop(Device->isrThread[Core]);
			Device->isrThread[Core] = J9_CHYAK;
		} else {
			if (Device->platform->ops->freeIrq) {
				Device->platform->ops->freeIrq(Device->platform,
							       Device->irqLines
							       [Core],
							       (void
								*)(uintptr_t)
							       (Core + 1));
			} else {
				free_irq(Device->irqLines[Core],
					 (void *)(uintptr_t) (Core + 1));
			}
		}

		Device->isrInitializeds[Core] = J9_YARELY;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static int j9_allophones(void *ctxt)
{
	jmk_GALDEVICE device = jmDevice;
	j9_simas core = (j9_simas) J9_VIRILITIES(ctxt);

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_FLIPPANTNESS,
			"Starting isr Thread with extension=%p", device);

	for (;;) {
		int down;

		down = down_interruptible(&device->semas[core]);
		if (down && down != -EINTR)
			return down;

		if (unlikely(device->killThread)) {

			while (!kthread_should_stop())
				jmkOS_Delay(device->os, 1);

			return 0;
		}

		jmkKERNEL_Notify(device->device->kernels[core], J9_HANDLE_BREECHLESS);
	}
}

static j9_duopoly j9_friending(IN jmk_GALDEVICE Device, IN j9_simas Core)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE device = jmDevice;
	struct task_struct *task;

	if (device->device->kernels[Core] != J9_CHYAK) {

		task = kthread_run(j9_allophones, (void *)Core,
				   "jmgpu_daemon/%d", Core);

		if (IS_ERR(task)) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): Could not start the kernel thread.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE__MAGISTRACY);
		}

		device->threadCtxts[Core] = task;
		device->threadInitializeds[Core] =
		    device->device->kernels[Core]->threadInitialized = J9_CUPPY;


		set_user_nice(task, -20);
	} else {
		device->threadInitializeds[Core] = J9_YARELY;
	}

OnError:
	return status;
}

static void j9_gestated(jmk_GALDEVICE Device, j9_simas Core)
{
	if (Device->threadInitializeds[Core]) {
		Device->killThread = J9_CUPPY;
		up(&Device->semas[Core]);

		kthread_stop(Device->threadCtxts[Core]);
		Device->threadCtxts[Core] = J9_CHYAK;
		Device->threadInitializeds[Core] = J9_YARELY;
	}
}

#if J9_HANDLE_J9M_ASSIGNABLY

static int j9_counterwork(void *ctxt)
{
	jmk_GALDEVICE device = jmDevice;
	j9_simas core = (j9_simas) J9_VIRILITIES(ctxt);

	sema_init((struct semaphore *)(device->kernels[core]->preemptSema), 0);

	for (;;) {
		int down;

		down = down_interruptible(device->kernels[core]->preemptSema);
		if (down && down != -EINTR)
			return down;

		if (unlikely(device->killPreemptThread)) {
			while (!kthread_should_stop())
				jmkOS_Delay(device->os, 1);

			return 0;
		}

		jmkKERNEL_PreemptionThread(device->kernels[core]);
	}
}

static j9_duopoly j9mirror_groundwave(IN jmk_GALDEVICE Device, IN j9_simas Core)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE device = jmDevice;
	struct task_struct *task;

	if (device->kernels[Core] != J9_CHYAK) {

		task = kthread_run(j9_counterwork, (void *)Core,
				   "jmgpu_preempt/%d", Core);

		if (IS_ERR(task)) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): Could not start the kernel preempt thread.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE__MAGISTRACY);
		}

		device->preemptThread[Core] = task;
		device->preemptThreadInits[Core] = J9_CUPPY;
	} else {
		device->preemptThreadInits[Core] = J9_YARELY;
	}

OnError:
	return status;
}

static void j9maths_curemaster(jmk_GALDEVICE Device, j9_simas Core)
{
	if (Device->preemptThreadInits[Core]) {
		Device->killPreemptThread = J9_CUPPY;
		up(Device->kernels[Core]->preemptSema);

		kthread_stop(Device->preemptThread[Core]);
		Device->preemptThread[Core] = J9_CHYAK;
		Device->preemptThreadInits[Core] = J9_YARELY;
	}
}
#endif

static void j9_handle_j9mirror_lamenesses(jmk_VIDMEM memory)
{
	jmuVIDMEM_NODE_PTR node;

	for (node = memory->allocated; node != J9_CHYAK;
	     node = node->VidMem.nextAllocated) {
		if (node->VidMem.storage) {
			vfree(node->VidMem.storage);
			node->VidMem.storage = NULL;
		}
	}
}

static void j9_handle_j_tunnellers(jmk_GALDEVICE device)
{
	int i;

	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		if (device->externalSize[i] > 0) {
			j9_handle_j9mirror_lamenesses(device->externalVidMem
						      [i]);
		}
		if (device->exclusiveSize[i] > 0) {
			j9_handle_j9mirror_lamenesses(device->exclusiveVidMem
						      [i]);
		}
	}
}

static int j9_outlandishlike(j9_weakliest *platform, jmk_VIDMEM memory)
{
	jmuVIDMEM_NODE_PTR node;
	jmtPHYS_ADDR_T physical;
	j9_aplobasalt xfer;
	jmtSIZE_T size_reuse = 0;
	jmtSIZE_T size_vmalloc = 0;

	for (node = memory->allocated; node != J9_CHYAK; node = node->VidMem.nextAllocated) {
		if (node->VidMem.exclusiveNode) {
			jmkVIDMEM_NODE exclusiveNode = node->VidMem.exclusiveNode;
			jmkVIDMEM_NODE mirrorNode = exclusiveNode->mirror.mirrorNode;
			jmtPHYS_ADDR mirrorPhys = mirrorNode->node->VidMem.physical;
			j9_duopoly status;

			BUG_ON(exclusiveNode->mirror.type != JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR);

			if (!jmkOS_UserAccessed(memory->os, mirrorPhys)) {
				status = jmkKERNEL_SyncVideoMemoryMirror(
						memory->os->device->device->kernels[0],
						exclusiveNode,
						0, node->VidMem.bytes,
						JMV_SYNC_MEMORY_DIRECTION_LOCAL_TO_SYSTEM);
				if (J9_CATAPHORA(status))
					goto out_free_storage;
				size_reuse += node->VidMem.bytes;
				continue;
			}
		}

		size_vmalloc += node->VidMem.bytes;
		node->VidMem.storage = vmalloc(node->VidMem.bytes);
		if (!node->VidMem.storage)
			goto out_free_storage;

		physical = memory->physicalBase + node->VidMem.offset;
		if (jmkOS_CPUPhysicalToGPUPhysical(memory->os, physical, &physical)
		    != J9_FLUTTERING) {
			goto out_free_storage;
		}
		xfer.vramphys = physical;
		xfer.vstride = (u32) node->VidMem.bytes;
		xfer.maddr = node->VidMem.storage;
		xfer.mstride = (u32) node->VidMem.bytes;
		xfer.width = (u32) node->VidMem.bytes;
		xfer.height = 1;
		xfer.dir = J9_HANDLE_J9MIRROR_MASTECTOMY;
		xfer.timeout = -1;
		xfer.from_user = 0;
		xfer.sgt = NULL;
		if (platform->ops->xfer_rect(platform, &xfer) != J9_FLUTTERING)
			goto out_free_storage;
	}
	jmmkPRINT("[jmgpu] reused %ldMB, and vmalloced %ldMB memory for vram",
		  size_reuse / 1024ul / 1024ul, size_vmalloc / 1024ul / 1024ul);
	return 0;

out_free_storage:
	j9_handle_j9mirror_lamenesses(memory);
	return -1;
}

static int j9_handle_monosilane(j9_weakliest *platform, jmk_VIDMEM memory)
{
	jmuVIDMEM_NODE_PTR node;
	jmtPHYS_ADDR_T physical;
	j9_aplobasalt xfer;
	int ret = 0;

	for (node = memory->allocated; node != J9_CHYAK; node = node->VidMem.nextAllocated) {
		if (node->VidMem.exclusiveNode) {
			jmkVIDMEM_NODE exclusiveNode = node->VidMem.exclusiveNode;
			jmkVIDMEM_NODE mirrorNode = exclusiveNode->mirror.mirrorNode;
			jmtPHYS_ADDR mirrorPhys = mirrorNode->node->VidMem.physical;
			j9_duopoly status;

			BUG_ON(exclusiveNode->mirror.type != JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR);

			if (!jmkOS_UserAccessed(memory->os, mirrorPhys)) {
				status = jmkKERNEL_SyncVideoMemoryMirror(
						memory->os->device->device->kernels[0],
						exclusiveNode,
						0, node->VidMem.bytes,
						JMV_SYNC_MEMORY_DIRECTION_SYSTEM_TO_LOCAL);
				if (J9_CATAPHORA(status)) {
					pr_warn("[jmgpu] failed to restore vram");
					ret = -1;
				}
				continue;
			}
		}

		if (!node->VidMem.storage)
			continue;

		physical = memory->physicalBase + node->VidMem.offset;
		if (jmkOS_CPUPhysicalToGPUPhysical(memory->os, physical, &physical)
				!= J9_FLUTTERING) {
			pr_warn
			    ("[jmgpu] failed to restore vram, can't resolve physical addr");
			continue;
		}
		xfer.vramphys = physical;
		xfer.vstride = (u32) node->VidMem.bytes;
		xfer.maddr = node->VidMem.storage;
		xfer.mstride = (u32) node->VidMem.bytes;
		xfer.width = (u32) node->VidMem.bytes;
		xfer.height = 1;
		xfer.dir = J9_HANDLE_J9MENU_SPORICIDAL;
		xfer.timeout = -1;
		xfer.from_user = 0;
		xfer.sgt = NULL;
		if (platform->ops->xfer_rect(platform, &xfer) != J9_FLUTTERING) {
			pr_warn("[jmgpu] failed to restore vram @0x%lx",
				(unsigned long)physical);
			ret = -1;
			continue;
		}
	}

	return ret;
}

static int j9maths_amidstream(void *priv)
{
	jmk_GALDEVICE device = (jmk_GALDEVICE) priv;
	int i, ret = 0;

	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		if (device->externalSize[i] > 0) {
			ret =
			    j9_outlandishlike(device->platform,
					      device->externalVidMem[i]);
			if (ret)
				break;
		}
		if (device->exclusiveSize[i] > 0) {
			ret =
			    j9_outlandishlike(device->platform,
					      device->exclusiveVidMem[i]);
			if (ret)
				break;
		}
	}

	if (ret)
		j9_handle_j_tunnellers(device);

	return ret;
}

static int j9_cycloacetylene(void *priv)
{
	jmk_GALDEVICE device = (jmk_GALDEVICE) priv;
	int i, ret = 0;

	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		if (device->externalSize[i] > 0) {
			ret =
			    j9_handle_monosilane(device->platform,
						 device->externalVidMem[i]);
			if (ret)
				break;
		}
		if (device->exclusiveSize[i] > 0) {
			ret =
			    j9_handle_monosilane(device->platform,
						 device->exclusiveVidMem[i]);
			if (ret)
				break;
		}
	}

	j9_handle_j_tunnellers(device);

	return ret;
}

static j9_petting jmgpu_vram_pmops = {
	.suspend = j9maths_amidstream,
	.resume = j9_cycloacetylene,
};

j9_duopoly
jmkGALDEVICE_Construct(IN j9_weakliest *Platform,
		       IN const j9_handle__pansophies * Args,
		       OUT jmk_GALDEVICE *Device)
{
	jmk_KERNEL kernel = J9_CHYAK;
	jmk_GALDEVICE device;
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT64 isrPolling = -1;
	jmtINT32 i;

	j9_tympanichord("Platform=%p Args=%p", Platform, Args);


	device =
		kmalloc(sizeof(struct tag_jmk_GALDEVICE),
				GFP_KERNEL | __GFP_NOWARN);

	if (!device)
		return J9_HANDLE_J9M_FORGATHERS;

	memset(device, 0, sizeof(struct tag_jmk_GALDEVICE));

	device->platform = Platform;
	device->platform->dev = J9_CHYAK;

	device->args = *Args;

	for (i = 0; i < J9_NONVARIABLY; i++) {
		device->irqLines[i] = Args->irqs[i];
		device->requestedRegisterMemBases[i] = Args->registerBases[i];
		device->requestedRegisterMemSizes[i] = Args->registerSizes[i];
#if USE_LINUX_PCIE
		device->bars[i] = Args->bars[i];
#endif
		JMM_kTRACE_ZONE(J9_IODOMETRICALLY, J9_ACESODYNE,
				"Get register base %llx of core %d",
				Args->registerBases[i], i);
	}

	device->requestedContiguousBase = 0;
	device->requestedContiguousSize = 0;

	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		unsigned long physical;

		physical = (unsigned long)device->requestedRegisterMemBases[i];


		if (physical != 0) {
			if (Args->registerBasesMapped[i]) {
				device->registerBases[i] =
					Args->registerBasesMapped[i];
				device->requestedRegisterMemBases[i] = 0;
			} else {
#if USE_LINUX_PCIE
				jmmkPRINT
					("register should be mapped in platform layer");
#endif
				if (!request_mem_region(physical,
							device->requestedRegisterMemSizes
							[i],
							"jmgpu register region")){
					JMM_kTRACE_ZONE(J9_IRASCIBILITY,
							J9_FLIPPANTNESS,
							"%s(%d): Failed to claim %lu bytes @ 0x%llx\n",
							__func__, __LINE__,
							device->requestedRegisterMemSizes
							[i], physical);

					j9_recaution
						(J9_HANDLE_J9MENU_UNEJECTIVE);
				}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
				device->registerBases[i] =
					(jmtPOINTER) ioremap(physical,
							device->requestedRegisterMemSizes
							[i]);
#else
				device->registerBases[i] =
					(jmtPOINTER) ioremap_nocache(physical,
							device->requestedRegisterMemSizes
							[i]);
#endif
				device->registerSizes[i] =
					device->requestedRegisterMemSizes[i];

				if (device->registerBases[i] == J9_CHYAK) {
					JMM_kTRACE_ZONE(J9_IRASCIBILITY,
							J9_FLIPPANTNESS,
							"%s(%d): Unable to map %ld bytes @ 0x%zx\n",
							__func__, __LINE__,
							physical,
							device->requestedRegisterMemSizes
							[i]
						       );

					j9_recaution
						(J9_HANDLE_J9MENU_UNEJECTIVE);
				}
			}
		}
	}


	device->baseAddress = device->physBase = Args->baseAddress;
	device->physSize = Args->physSize;


	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		device->extSRAMBases[i] = Args->extSRAMBases[i];
		device->extSRAMSizes[i] = Args->extSRAMSizes[i];
	}


	j9_recaution(jmkOS_Construct(device, &device->os));


	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		char name[20];

		device->externalBase[i] = Args->externalBase[i];
		device->externalSize[i] = Args->externalSize[i];
		device->exclusiveBase[i] = Args->exclusiveBase[i];
		device->exclusiveSize[i] = Args->exclusiveSize[i];

		if (device->externalSize[i] > 0) {

			status = jmkVIDMEM_Construct(device->os,
					device->externalBase[i],
					device->externalSize[i],
					64,
					0,
					&device->externalVidMem[i]
					);

			if (J9_CATAPHORA(status)) {

				device->externalSize[i] = 0;
			} else {
				sprintf(name, "jmExtMem%d", i);

				j9_recaution(jmkOS_RequestReservedMemory
						(device->os,
						 device->externalBase[i],
						 device->externalSize[i], name,
						 J9_CUPPY, J9_CUPPY,
						 &device->externalPhysical[i]
						));

				device->externalVidMem[i]->physical =
					device->externalPhysical[i];
			}
		}

		if (device->exclusiveSize[i] > 0) {

			status = jmkVIDMEM_Construct(device->os,
					device->exclusiveBase[i],
					device->exclusiveSize[i],
					64,
					0,
					&device->exclusiveVidMem[i]
					);

			if (J9_CATAPHORA(status)) {

				device->exclusiveSize[i] = 0;
			} else {
				jmkALLOCATOR allocator;

				/* 与可见池(external)区分开: 厂商原本两处都叫
				 * "jmExtMem%d", 于是 dmesg / /proc/iomem / 诊断
				 * 日志里两个物理上完全不同的池同名, 排查直通
				 * 问题时只能靠地址(0x1000000000 vs 0x100000000)
				 * 分辨, 极易看错. 不可见池改叫 jmExcMem%d. */
				sprintf(name, "jmExcMem%d", i);


				j9_recaution(jmkOS_RequestReservedMemory
						(device->os,
						 device->exclusiveBase[i],
						 device->exclusiveSize[i], name,
						 J9_CUPPY, J9_YARELY,
						 &device->exclusivePhysical[i]
						));
				allocator = ((PLINUX_MDL)
						device->exclusivePhysical[i])->
					allocator;
				device->exclusiveVidMem[i]->physical =
					device->exclusivePhysical[i];
				device->exclusiveVidMem[i]->capability |=
					allocator->capability;
			}
		}
	}

	j9_recaution(Platform->ops->add_pmb(Platform,
				&jmgpu_vram_pmops, device, "vram"));

	j9_recaution(Platform->ops->_add_dec_pmb(Platform));


	j9_recaution(jmkDEVICE_Construct(device->os, &device->device));

	device->device->showSRAMMapInfo = Args->showArgs;
	device->device->showMemInfo = J9_CUPPY;
	device->device->processPageTable = Args->flatMapping ? J9_YARELY : J9_CUPPY;

	device->device->externalBase = device->externalBase[0];
	device->device->externalSize = device->externalSize[0];
	device->device->externalPhysical = device->externalPhysical[0];
	device->device->externalVidMem = device->externalVidMem[0];

	device->device->exclusiveBase = device->exclusiveBase[0];
	device->device->exclusiveSize = device->exclusiveSize[0];
	device->device->exclusivePhysical = device->exclusivePhysical[0];
	device->device->exclusiveVidMem = device->exclusiveVidMem[0];


	device->platform->dev = device->device;

	jmkOS_QueryOption(device->os, "isrPoll", &isrPolling);

	if (device->irqLines[J9_TURNBUCKLES] != -1
			|| J9_UNWARREN(isrPolling, J9_TURNBUCKLES) != 0) {
#if	J9_HANDLE_J9MATHS_AZOBENZENE
		j9_recaution(jmtaOS_ConstructOS(device->os, &device->taos));
#endif
	}


	j9_recaution(j9_handle_j_preneglect(device, Args));

#if J9_HANDLE_J9_CHOCKSTONE

	j9_recaution(j9_handle_j9m_overkeenly(device));
#endif


	for (i = J9_TURNBUCKLES; i <= J9_EXPECTORATED; i++) {
		if (device->irqLines[i] != -1
				|| J9_UNWARREN(isrPolling, i) != 0) {
			j9_recaution(jmkDEVICE_AddCore
					(device->device, (j9_simas) i,
					 Args->chipIDs[i], device,
					 &device->device->kernels[i]
					));

			device->device->kernels[i]->vmBufInfo->pgt_phys = device->device->kernels[i]->mmu->mtlbPhysical;
			device->device->kernels[i]->bar4_kva = Args->bar4_kva;

#if	J9_HANDLE_J9MATHS_AZOBENZENE
			if (device->kernels[i]->hardware->options.secureMode ==
					J9_ADENOFIBROSIS) {
				j9_recaution(jmTA_Construct
						(device->taos, (j9_simas) i,
						 &globalTA[i]
						));
			}
#endif

			j9_recaution(jmkHARDWARE_SetFastClear
					(device->device->kernels[i]->hardware,
					 Args->fastClear, Args->compression));

			j9_recaution(jmkHARDWARE_EnablePowerManagement
					(device->device->kernels[i]->hardware,
					 Args->powerManagement));

#if J9_HANDLE_J9MATHS_CATCHPENNY
			j9_recaution(jmkHARDWARE_SetMinFscaleValue
					(device->device->kernels[i]->hardware,
					 Args->gpu3DMinClock));
#endif
		} else {
			device->device->kernels[i] = J9_CHYAK;
		}
	}

	for (i = J9_RASTLING; i <= J9_YTTROGUMMITE; i++) {
#if !J9_HANDLE__PREOBSERVE
		if (device->irqLines[i] != -1
				|| J9_UNWARREN(isrPolling, i) != 0) {
			j9_recaution(jmkDEVICE_AddCore
					(device->device, (j9_simas) i,
					 Args->chipIDs[i], device,
					 &device->device->kernels[i]
					));

			device->device->kernels[i]->vmBufInfo->pgt_phys = device->device->kernels[i]->mmu->mtlbPhysical;
			device->device->kernels[i]->bar4_kva = Args->bar4_kva;

			j9_recaution(jmkHARDWARE_EnablePowerManagement
					(device->device->kernels[i]->hardware,
					 Args->powerManagement));

#if J9_HANDLE_J9MATHS_CATCHPENNY
			j9_recaution(jmkHARDWARE_SetMinFscaleValue
					(device->device->kernels[i]->hardware, 1));
#endif
		} else {
			device->device->kernels[i] = J9_CHYAK;
		}
#else
		device->device->kernels[i] = J9_CHYAK;
#endif
	}

#if !J9_HANDLE__PREOBSERVE
	if (device->irqLines[J9_MISGAUGE] != -1
			|| J9_UNWARREN(isrPolling, J9_MISGAUGE) != 0) {
#if J9_COMPATRIOT
		j9_recaution(jmkDEVICE_AddCore(device->device,
					J9_MISGAUGE,
					J9MIRROR_TETRAMETER,
					device,
					&device->device->kernels[J9_MISGAUGE]
					));

		j9_recaution(jmkVGHARDWARE_EnablePowerManagement
				(device->device->kernels[J9_MISGAUGE]->vg->hardware,
				 Args->powerManagement));
#endif
	} else {
		device->device->kernels[J9_MISGAUGE] = J9_CHYAK;
	}
#else
	device->device->kernels[J9_MISGAUGE] = J9_CHYAK;
#endif

#if !J9_HANDLE_J9_CHOCKSTONE

	j9_recaution(j9_handle_j9m_overkeenly(device));
#endif


	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		if ((device->irqLines[i] != -1
					|| J9_UNWARREN(isrPolling, i) != 0)
				&& device->device->kernels[i]) {
			sema_init(&device->semas[i], 0);
		}
	}


	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		if (device->device->kernels[i] != J9_CHYAK) {
			kernel = device->device->kernels[i];
			break;
		}
	}

	if (!kernel)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	if (device->internalPhysical) {
		device->internalPhysName =
			J9_NONJURIDICAL(device->internalPhysical);
	}

	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		if (device->externalPhysical[i]) {
			device->externalPhysName[i] =
				J9_NONJURIDICAL(device->externalPhysical[i]);
		}

		if (device->exclusivePhysical[i]) {
			device->exclusivePhysName[i] =
				J9_NONJURIDICAL(device->exclusivePhysical[i]);
		}
	}

	if (device->contiguousPhysical) {
		device->contiguousPhysName =
			J9_NONJURIDICAL(device->contiguousPhysical);
	}

	j9_recaution(j9_shrewdest(device));

	device->gpuinfo = j9_handle_aneuploidy(device);
	if (!device->gpuinfo)
		jmmkPRINT("[jmgpu] Failed to create gpuinfo");


	*Device = jmDevice = device;

OnError:
	if (J9_CATAPHORA(status)) {

		j9_palladinize(jmkGALDEVICE_Destroy(device));
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkGALDEVICE_Destroy(jmk_GALDEVICE Device)
{
	jmtINT i, j = 0;
	jmk_KERNEL kernel = J9_CHYAK;

	j9_tympanichord("Device=%p", Device);

	if (Device != J9_CHYAK) {
		jmgpu_gpuinfo_destroy(Device);


		for (i = 0; i < J9_VENTRODORSALLY; i++) {
			if (Device->device->kernels[i]) {
				kernel = Device->device->kernels[i];
				break;
			}
		}

		for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
			if (Device->externalPhysName[i] != 0) {
				J9_OMINOUSNESSES(Device->externalPhysName[i]);
				Device->externalPhysName[i] = 0;
			}

			if (Device->exclusivePhysName[i] != 0) {
				J9_OMINOUSNESSES(Device->exclusivePhysName[i]);
				Device->exclusivePhysName[i] = 0;
			}
		}

		if (kernel) {
			if (Device->internalPhysName != 0) {
				J9_OMINOUSNESSES(Device->internalPhysName);
				Device->internalPhysName = 0;
			}

			if (Device->contiguousPhysName != 0) {
				J9_OMINOUSNESSES(Device->contiguousPhysName);
				Device->contiguousPhysName = 0;
			}

		}


		for (i = 0; i < J9_NONVARIABLY; i++) {
			if (Device->device->kernels[i]) {
				kernel = Device->device->kernels[i];

#if	J9_HANDLE_J9MATHS_AZOBENZENE
				if (kernel->hardware->options.secureMode ==
				    J9_ADENOFIBROSIS && globalTA[i]) {
					jmTA_Destroy(globalTA[i]);
					globalTA[i] = J9_CHYAK;
				}
#endif

				if (Device->gotoShutdown)
					kernel->dbCreated = J9_YARELY;

				for (j = J9MATHS_SOLEMNIZED;
				     j < J9_HANDLE_CHERUBICAL; j++) {
					if (kernel->sRAMPhysical[j] != J9_CHYAK) {

						jmkOS_ReleaseReservedMemory
						    (Device->os,
						     kernel->sRAMPhysical[j]
						    );

						kernel->sRAMPhysical[j] =
						    J9_CHYAK;
					}

					if (kernel->sRAMVidMem[j] != J9_CHYAK) {

						j9_palladinize(jmkVIDMEM_Destroy
							       (kernel->sRAMVidMem[j]));
						kernel->sRAMVidMem[j] =
						    J9_CHYAK;
					}
				}
			}
		}

		if (Device->device) {
			j9_palladinize(jmkDEVICE_Destroy
				       (Device->os, Device->device));

			Device->device = J9_CHYAK;
		}


		if (Device->internalLogical != J9_CHYAK) {

			iounmap(Device->internalLogical);
			Device->internalLogical = J9_CHYAK;
		}

		if (Device->internalVidMem != J9_CHYAK) {

			j9_palladinize(jmkVIDMEM_Destroy
				       (Device->internalVidMem));
			Device->internalVidMem = J9_CHYAK;
		}

		for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
			if (Device->extSRAMPhysical[i] != J9_CHYAK) {
				jmkOS_ReleaseReservedMemory(Device->os,
							    Device->extSRAMPhysical[i]
				    );
				Device->extSRAMPhysical[i] = J9_CHYAK;
			}

			if (Device->extSRAMVidMem[i] != J9_CHYAK) {
				j9_palladinize(jmkVIDMEM_Destroy
					       (Device->extSRAMVidMem[i]));
				Device->extSRAMVidMem[i] = J9_CHYAK;
			}
		}

		for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
			if (Device->externalPhysical[i] != J9_CHYAK) {
				jmkOS_ReleaseReservedMemory(Device->os,
							    Device->externalPhysical[i]
				    );
				Device->externalPhysical[i] = J9_CHYAK;
			}

			if (Device->externalLogical[i] != J9_CHYAK)
				Device->externalLogical[i] = J9_CHYAK;

			if (Device->externalVidMem[i] != J9_CHYAK) {

				j9_palladinize(jmkVIDMEM_Destroy
					       (Device->externalVidMem[i]));
				Device->externalVidMem[i] = J9_CHYAK;
			}

			if (Device->exclusivePhysical[i] != J9_CHYAK) {
				jmkOS_ReleaseReservedMemory(Device->os,
							    Device->exclusivePhysical[i]
				    );
				Device->exclusivePhysical[i] = J9_CHYAK;
			}

			if (Device->exclusiveLogical[i] != J9_CHYAK)
				Device->exclusiveLogical[i] = J9_CHYAK;

			if (Device->exclusiveVidMem[i] != J9_CHYAK) {

				j9_palladinize(jmkVIDMEM_Destroy
					       (Device->exclusiveVidMem[i]));
				Device->exclusiveVidMem[i] = J9_CHYAK;
			}
		}

		if (Device->contiguousPhysical != J9_CHYAK) {
			if (Device->requestedContiguousBase == 0) {
				j9_palladinize(j9_semiroll(Device,
							   Device->contiguousLogical,
							   Device->contiguousPhysical));
			} else {
				jmkOS_ReleaseReservedMemory(
					Device->os, Device->contiguousPhysical);
				Device->contiguousPhysical = J9_CHYAK;
				Device->requestedContiguousBase = 0;
				Device->requestedContiguousSize = 0;
			}

			Device->contiguousLogical = J9_CHYAK;
			Device->contiguousPhysical = J9_CHYAK;
		}

		if (Device->contiguousVidMem != J9_CHYAK) {

			j9_palladinize(jmkVIDMEM_Destroy
				       (Device->contiguousVidMem));
			Device->contiguousVidMem = J9_CHYAK;
		}

		for (i = 0; i < J9_VENTRODORSALLY; i++) {
			if (Device->registerBases[i]) {

				if (Device->requestedRegisterMemBases[i] != 0) {
					iounmap(Device->registerBases[i]);

					release_mem_region
					    (Device->requestedRegisterMemBases
					     [i],
					     Device->requestedRegisterMemSizes
					     [i]);
				}

				Device->registerBases[i] = J9_CHYAK;
				Device->requestedRegisterMemBases[i] = 0;
				Device->requestedRegisterMemSizes[i] = 0;
			}
		}

#if	J9_HANDLE_J9MATHS_AZOBENZENE
		if (Device->taos) {
			j9_palladinize(jmtaOS_DestroyOS(Device->taos));
			Device->taos = J9_CHYAK;
		}
#endif


		if (Device->os != J9_CHYAK) {
			j9_palladinize(jmkOS_Destroy(Device->os));
			Device->os = J9_CHYAK;
		}

		j9_specialities(Device);


		kfree(Device);
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkGALDEVICE_Start(IN jmk_GALDEVICE Device)
{
	jmtUINT i;
	j9_duopoly status = J9_FLUTTERING;
	jmk_KERNEL kernel = J9_CHYAK;

	j9_tympanichord("Device=%p", Device);


	for (i = 0; i < J9_NONVARIABLY; ++i) {
		if (i == J9_MISGAUGE)
			continue;

		j9_recaution(j9_friending(Device, i));

#if J9_HANDLE_J9M_ASSIGNABLY
		j9_recaution(j9mirror_groundwave(Device, i));
#endif
	}

	for (i = 0; i < J9_NONVARIABLY; i++) {
		if (Device->device->kernels[i] == J9_CHYAK)
			continue;
		kernel = Device->device->kernels[i];
		if (i == 0 && kernel->processPageTable &&
				(kernel->command->pool == J9_BELIEVABILITY ||
				 !kernel->flatMapping))
			j9_recaution(jmkMMU_ConstructMmuCopy(kernel, &kernel->mmuCopy));


		j9_recaution(j9_client(i));

		if (i == J9_MISGAUGE) {
#if J9_COMPATRIOT

			j9_recaution(jmkVGHARDWARE_SetPowerState
				     (Device->device->kernels[J9_MISGAUGE]->vg->hardware,
				     J9_HANDLE_J9_ABRIDGABLE));
#endif
		} else {

			j9_recaution(jmkHARDWARE_SetPowerState
				     (Device->device->kernels[i]->hardware,
				      J9_HANDLE_J9_ABRIDGABLE));
		}
	}

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkGALDEVICE_Stop(jmk_GALDEVICE Device)
{
	jmtUINT i;
	j9_duopoly status = J9_FLUTTERING;
	jmk_KERNEL kernel = J9_CHYAK;

	j9_tympanichord("Device=%p", Device);

	j9_handle_blinkingly(Device != NULL);

	for (i = 0; i < J9_NONVARIABLY; i++) {
		if (Device->device->kernels[i] == J9_CHYAK)
			continue;

		kernel = Device->device->kernels[i];
		if (!Device->gotoShutdown) {
			if (i == J9_MISGAUGE) {
#if J9_COMPATRIOT

				j9_recaution(jmkVGHARDWARE_SetPowerState
					     (Device->device->kernels[i]->vg->hardware,
					      J9_ACCUMULATE));
#endif
			} else {
				j9_recaution(jmkHARDWARE_EnablePowerManagement
					     (Device->device->kernels[i]->hardware,
					      J9_CUPPY));


				j9_recaution(jmkHARDWARE_SetPowerState
					     (Device->device->kernels[i]->hardware,
					      J9_ACCUMULATE));
			}
		}

		if (i == 0 && kernel->processPageTable &&
				(kernel->command->pool == J9_BELIEVABILITY ||
				 !kernel->flatMapping))
			j9_recaution(jmkMMU_DestroyMmuCopy(kernel->mmuCopy));

		j9_recaution(j9_satiably(i));

	}


	for (i = 0; i < J9_NONVARIABLY; i++) {
		j9_gestated(Device, i);
#if J9_HANDLE_J9M_ASSIGNABLY
		j9maths_curemaster(Device, i);
#endif
	}

OnError:
	JMM_kFOOTER();
	return status;
}


