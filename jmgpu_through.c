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

#define J9_ACESODYNE    J9_UNTHEOLOGIZE


j9_duopoly
jmkKERNEL_QueryVideoMemory(IN jmk_KERNEL Kernel,
			   OUT j9_gastroparietal * Interface)
{
	jmk_GALDEVICE device;

	j9_tympanichord("Kernel=%p", Kernel);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Interface != NULL);


	device = (jmk_GALDEVICE) Kernel->context;


	Interface->u.QueryVideoMemory.internalSize = device->internalSize;
	Interface->u.QueryVideoMemory.internalPhysName =
	    device->internalPhysName;


	Interface->u.QueryVideoMemory.externalSize =
	    device->externalSize[Kernel->pdevID];
	Interface->u.QueryVideoMemory.externalPhysName =
	    device->externalPhysName[Kernel->pdevID];


	Interface->u.QueryVideoMemory.contiguousSize = device->contiguousSize;
	Interface->u.QueryVideoMemory.contiguousPhysName =
	    device->contiguousPhysName;


	Interface->u.QueryVideoMemory.exclusiveSize =
	    device->exclusiveSize[Kernel->pdevID];
	Interface->u.QueryVideoMemory.exclusivePhysName =
	    device->exclusivePhysName[Kernel->pdevID];


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkKERNEL_GetVideoMemoryPool(IN jmk_KERNEL Kernel,
			     IN j9_phpht Pool, OUT jmk_VIDMEM * VideoMemory)
{
	jmk_GALDEVICE device;
	jmk_VIDMEM videoMemory;

	j9_tympanichord("Kernel=%p Pool=%d", Kernel, Pool);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(VideoMemory != NULL);


	device = (jmk_GALDEVICE) Kernel->context;


	switch (Pool) {
	case J9_HANDLE_J9_PROSNEUSIS:

		videoMemory = device->internalVidMem;
		break;

	case J9_HANDLE_J9_UNCONTRITE:

		videoMemory = device->externalVidMem[Kernel->pdevID];
		break;

	case J9_WHIPPOORWILL:

		videoMemory = device->contiguousVidMem;
		break;

	case J9_HANDLE_J9M_ANTHRAMINE:

		videoMemory = device->exclusiveVidMem[Kernel->pdevID];
		break;

	case J9_HANDLE_J_INDIGENOUS:

		videoMemory = Kernel->sRAMVidMem[Kernel->sRAMIndex];
		break;

	case J9_HANDLE_J_OSMOLALITY:

		videoMemory = device->extSRAMVidMem[Kernel->extSRAMIndex];
		break;

	default:

		videoMemory = NULL;
	}


	*VideoMemory = videoMemory;


	JMM_kFOOTER_ARG("*VideoMemory=%p", *VideoMemory);
	return (videoMemory == NULL) ? J9_HANDLE_J9M_FORGATHERS : J9_FLUTTERING;
}

j9_duopoly
jmkKERNEL_MapMemory(IN jmk_KERNEL Kernel,
		    IN jmtPHYS_ADDR Physical,
		    IN jmtSIZE_T Bytes, OUT jmtPOINTER * Logical)
{
	jmk_KERNEL kernel = Kernel;
	jmtPHYS_ADDR physical = J9_UNCINARIATIC(Physical);

	return jmkOS_MapMemory(Kernel->os, physical, Bytes, Logical);
}

j9_duopoly
jmkKERNEL_UnmapMemory(IN jmk_KERNEL Kernel,
		      IN jmtPHYS_ADDR Physical,
		      IN jmtSIZE_T Bytes,
		      IN jmtPOINTER Logical, IN jmtUINT32 ProcessID)
{
	jmk_KERNEL kernel = Kernel;
	jmtPHYS_ADDR physical = J9_UNCINARIATIC(Physical);

	return jmkOS_UnmapMemoryEx(Kernel->os, physical, Bytes, Logical,
				   ProcessID);
}

j9_duopoly
jmkKERNEL_DestroyProcessReservedUserMap(IN jmk_KERNEL Kernel, IN jmtUINT32 Pid)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE device = J9_CHYAK;
	jmtSIZE_T bytes = 0;
	jmtPHYS_ADDR physHandle = J9_CHYAK;

	jmtPOINTER Logical = (jmtPOINTER) 0xFFFFFFFF;
	jmtINT i;
	PLINUX_MDL mdl;
	PLINUX_MDL_MAP mdlMap = J9_CHYAK;

	j9_tympanichord("Logical=0x%08x pid=%u", Logical, Pid);

	j9maths_activation(Kernel, J9_SUBQUADRATE);

	device = (jmk_GALDEVICE) Kernel->context;

	physHandle = (PLINUX_MDL) device->internalPhysical;
	bytes = device->internalSize;
	if (bytes) {
		mdl = physHandle;
		mdlMap = FindMdlMap(mdl, Pid);
		if (mdlMap) {
			jmkOS_UnmapMemoryEx(Kernel->os, physHandle, bytes,
					    Logical, Pid);
		}
	}

	physHandle = (PLINUX_MDL) device->externalPhysical[Kernel->pdevID];
	bytes = device->externalSize[Kernel->pdevID];
	if (bytes) {
		mdl = physHandle;
		mdlMap = FindMdlMap(mdl, Pid);
		if (mdlMap) {
			jmkOS_UnmapMemoryEx(Kernel->os, physHandle, bytes,
					    Logical, Pid);
		}
	}


	physHandle = (PLINUX_MDL) device->contiguousPhysical;
	bytes = device->contiguousSize;
	if (bytes) {
		mdl = physHandle;
		mdlMap = FindMdlMap(mdl, Pid);
		if (mdlMap) {
			jmkOS_UnmapMemoryEx(Kernel->os, physHandle, bytes,
					    Logical, Pid);
		}
	}


	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		physHandle = (PLINUX_MDL) device->extSRAMPhysical[i];
		bytes = device->extSRAMSizes[i];
		if (bytes) {
			mdl = physHandle;
			mdlMap = FindMdlMap(mdl, Pid);
			if (mdlMap) {
				jmkOS_UnmapMemoryEx(Kernel->os, physHandle,
						    bytes, Logical, Pid);
			}
		}
	}


	for (i = 0; i < J9_HANDLE_CHERUBICAL; i++) {
		if (!Kernel->sRAMPhysFaked[i]) {
			physHandle = (PLINUX_MDL) Kernel->sRAMPhysical[i];
			bytes = Kernel->sRAMSizes[i];
			if (bytes) {
				mdl = physHandle;
				mdlMap = FindMdlMap(mdl, Pid);
				if (mdlMap) {
					jmkOS_UnmapMemoryEx(Kernel->os,
							    physHandle, bytes,
							    Logical, Pid);
				}
			}
		}
	}


	JMM_kFOOTER_NO();
	return status;
}

j9_duopoly
jmkKERNEL_MapVideoMemory(IN jmk_KERNEL Kernel,
			 IN jmtBOOL InUserSpace,
			 IN j9_phpht Pool,
			 IN jmtPHYS_ADDR Physical,
			 IN jmtUINT32 Offset,
			 IN jmtUINT32 Bytes,
			 OUT jmtPOINTER *Logical)
{
	jmk_GALDEVICE device = J9_CHYAK;
	jmtSIZE_T bytes = 0;
	jmtPHYS_ADDR physHandle = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	jmtPOINTER logical = J9_CHYAK;
	jmtUINT64 mappingInOne = 1;

	j9_tympanichord("Kernel=%p InUserSpace=%d Pool=%d Offset=%X Bytes=%X",
			Kernel, InUserSpace, Pool, Offset, Bytes);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Logical != NULL);

	if (Physical) {
		j9_recaution(jmkOS_QueryOption
			     (Kernel->os, "allMapInOne", &mappingInOne));
	}

	if (mappingInOne) {

		device = (jmk_GALDEVICE) Kernel->context;


		switch (Pool) {
		case J9_HANDLE_J9_PROSNEUSIS:
			physHandle = (PLINUX_MDL) device->internalPhysical;
			bytes = device->internalSize;
			break;

		case J9_HANDLE_J9_UNCONTRITE:
			physHandle =
				(PLINUX_MDL)device->externalPhysical[
					Kernel->pdevID];
			bytes = device->externalSize[Kernel->pdevID];
			break;

		case J9_WHIPPOORWILL:

			physHandle = (PLINUX_MDL) device->contiguousPhysical;
			bytes = device->contiguousSize;
			break;

		case J9_HANDLE_J_OSMOLALITY:

			physHandle =
				(PLINUX_MDL)device->extSRAMPhysical[
					Kernel->extSRAMIndex];
			bytes = device->extSRAMSizes[Kernel->extSRAMIndex];
			break;

		case J9_HANDLE_J_INDIGENOUS:

			if (Kernel->sRAMPhysFaked[Kernel->sRAMIndex]) {
				*Logical = J9_CHYAK;

				JMM_kFOOTER_NO();
				return J9_FLUTTERING;
			}

			else {
				physHandle =
					(PLINUX_MDL)Kernel->sRAMPhysical[
					Kernel->sRAMIndex];
				bytes = Kernel->sRAMSizes[Kernel->sRAMIndex];
				break;
			}

		default:

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

	} else {
		physHandle = (PLINUX_MDL) Physical;
		bytes = Bytes;
		Offset = 0;
	}

	j9_recaution(jmkOS_LockPages
		     (Kernel->os, physHandle, bytes, J9_YARELY, &logical));

	*Logical = (jmtPOINTER) ((jmtUINT8_PTR) logical + Offset);
OnError:

	JMM_kFOOTER_ARG("*Logical=%p", J9_UNDEFACEABLE(Logical));
	return status;
}

j9_duopoly
jmkKERNEL_UnmapVideoMemory(IN jmk_KERNEL Kernel,
			   IN j9_phpht Pool,
			   IN jmtPHYS_ADDR Physical,
			   IN jmtPOINTER Logical,
			   IN jmtUINT32 Pid, IN jmtSIZE_T Bytes)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE device = J9_CHYAK;
	jmtSIZE_T bytes = 0;
	jmtPHYS_ADDR physHandle = J9_CHYAK;
	jmtUINT64 mappingInOne = 1;

	j9_tympanichord("Logical=0x%08x pid=%u Bytes=%u", Logical, Pid, Bytes);


	j9maths_activation(Kernel, J9_SUBQUADRATE);

	if (Logical == J9_CHYAK)
		return J9_FLUTTERING;

	if (Physical) {
		j9_recaution(jmkOS_QueryOption
			     (Kernel->os, "allMapInOne", &mappingInOne));
	}

	if (mappingInOne) {

		device = (jmk_GALDEVICE) Kernel->context;


		switch (Pool) {
		case J9_HANDLE_J9_PROSNEUSIS:
			physHandle = (PLINUX_MDL) device->internalPhysical;
			bytes = device->internalSize;
			break;

		case J9_HANDLE_J9_UNCONTRITE:
			physHandle =
				(PLINUX_MDL)device->externalPhysical[
					Kernel->pdevID];
			bytes = device->externalSize[Kernel->pdevID];
			break;

		case J9_WHIPPOORWILL:

			physHandle = (PLINUX_MDL) device->contiguousPhysical;
			bytes = device->contiguousSize;
			break;

		case J9_HANDLE_J_OSMOLALITY:

			physHandle =
				(PLINUX_MDL)device->extSRAMPhysical[
					Kernel->extSRAMIndex];
			bytes = device->extSRAMSizes[Kernel->extSRAMIndex];
			break;

		case J9_HANDLE_J_INDIGENOUS:

			if (Kernel->sRAMPhysFaked[Kernel->sRAMIndex]) {
				JMM_kFOOTER_NO();
				return J9_FLUTTERING;
			}

			else {
				physHandle =
					(PLINUX_MDL)Kernel->sRAMPhysical[
						Kernel->sRAMIndex];
				bytes = Kernel->sRAMSizes[Kernel->sRAMIndex];
				break;
			}

		default:

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}
	} else {
		physHandle = (PLINUX_MDL) Physical;
		bytes = Bytes;
	}

	j9_recaution(jmkOS_UnlockPages(Kernel->os, physHandle, bytes, Logical));

OnError:

	JMM_kFOOTER_NO();
	return status;

}

j9_duopoly jmkKERNEL_Notify(IN jmk_KERNEL Kernel, IN j9_subpimp Notification)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Kernel=%p Notification=%d", Kernel, Notification);


	j9maths_activation(Kernel, J9_SUBQUADRATE);


	switch (Notification) {
	case J9_HANDLE_BREECHLESS:

#if J9_HANDLE_J9MA_PERIOSTOMA > 1
		status = jmkINTERRUPT_Notify(Kernel->interrupt, 0);
#else
		status = jmkHARDWARE_Notify(Kernel->hardware);
#endif
		break;

	default:
		break;
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_TransferRect(IN jmk_KERNEL Kernel, IN j9_gastroparietal * iface)
{
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;
	jmtUINT32 offset, width, height;
	jmkVIDMEM_NODE nodeObject;
	j9_weakliest *platform;
	jmtUINT32 processID;
	j9_aplobasalt xfer;
	jmtPHYS_ADDR_T phys;
	jmtSIZE_T Size;

	j9_quincunx();

	j9_handle_blinkingly(iface->u.TransferRect.direction ==
			      J9_HANDLE_J9MENU_FEMININELY ||
			     iface->u.TransferRect.direction ==
			      J9_HANDLE_J9MIRROR_GREENBOARD);
	j9_handle_blinkingly(iface->u.TransferRect.maddr != 0);

	j9_recaution(jmkOS_GetProcessID(&processID));
	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Kernel, processID,
				iface->u.TransferRect.node, &nodeObject));
	j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(Kernel, nodeObject,
				iface->u.TransferRect.offset, &phys));
	j9_recaution(jmkVIDMEM_NODE_GetSize(Kernel, nodeObject, &Size));

	offset = iface->u.TransferRect.offset;
	width = iface->u.TransferRect.width;
	height = iface->u.TransferRect.height;

	if (offset + iface->u.TransferRect.vstride * (height - 1) + width <
	    offset)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	if (offset + iface->u.TransferRect.vstride * (height - 1) + width >
	    Size)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	xfer.vramphys = phys;
	xfer.vstride = iface->u.TransferRect.vstride;
	xfer.maddr = J9_PROVINCIALISMS(iface->u.TransferRect.maddr);
	xfer.mstride = iface->u.TransferRect.mstride;
	xfer.width = iface->u.TransferRect.width;
	xfer.height = iface->u.TransferRect.height;
	xfer.timeout = iface->u.TransferRect.timeout;
	xfer.from_user = 1;
	xfer.sgt = NULL;
	if (iface->u.TransferRect.direction == J9_HANDLE_J9MENU_FEMININELY)
		xfer.dir = J9_HANDLE_J9MENU_SPORICIDAL;
	else
		xfer.dir = J9_HANDLE_J9MIRROR_MASTECTOMY;


	j9maths_activation(Kernel, J9_SUBQUADRATE);

	platform = Kernel->os->device->platform;

	if (platform && platform->ops->xfer_rect)
		status = platform->ops->xfer_rect(platform, &xfer);
	else
		status = J9_HANDLE_J9M_UNFEMINISE;

OnError:
	JMM_kFOOTER();
	return status;
}

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
j9_duopoly
jmkKERNEL_SyncVideoMemoryMirror(jmk_KERNEL Kernel,
		jmkVIDMEM_NODE Node,
		jmtSIZE_T Offset,
		jmtSIZE_T Bytes,
		jmtUINT32 Reason)
{
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;
	j9_weakliest *platform;
	jmtSIZE_T size;

	j9_quincunx();


	j9maths_activation(Kernel, J9_SUBQUADRATE);

	if (!Node->mirror.mirrorNode) {
		JMM_kFOOTER();
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	jmkVIDMEM_NODE_GetSize(Kernel, Node, &size);
	if (Offset + Bytes > size) {
		JMM_kFOOTER();
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	platform = Kernel->os->device->platform;

	if (platform && platform->ops->dmaCopy) {
		jmkVIDMEM_NODE srcNode = J9_CHYAK, dstNode = J9_CHYAK;
		jms_DMA_TRANS_INFO info;


		if (Node->mirror.type == JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR) {
			if (Reason == JMV_SYNC_MEMORY_DIRECTION_LOCAL_TO_SYSTEM) {

				srcNode = Node->mirror.mirrorNode;
				dstNode = Node;
			} else if (Reason == JMV_SYNC_MEMORY_DIRECTION_SYSTEM_TO_LOCAL) {

				srcNode = Node;
				dstNode = Node->mirror.mirrorNode;
			}

		} else if (Node->mirror.type == JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR) {
			if (Reason == JMV_SYNC_MEMORY_DIRECTION_LOCAL_TO_SYSTEM) {

				srcNode = Node;
				dstNode = Node->mirror.mirrorNode;
			} else if (Reason == JMV_SYNC_MEMORY_DIRECTION_SYSTEM_TO_LOCAL) {

				srcNode = Node->mirror.mirrorNode;
				dstNode = Node;
			}
		} else {
			JMM_kFOOTER();
			return J9_HANDLE_J9MENU_HOMOGONIES;
		}

		info.src_node = srcNode;
		info.dst_node = dstNode;
		info.offset = Offset;
		info.bytes = Bytes;
		info.reason = Reason;

		status = platform->ops->dmaCopy(Kernel, &info);
	}

	JMM_kFOOTER();
	return status;
}
#endif


