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


#ifndef EMULATOR
#include <linux/hash.h>
#include <linux/list.h>
#include <linux/hashtable.h>
#endif

#include "jmgpu_dependent.h"
#ifdef CONFIG_DMA_SHARED_BUFFER
#include "jmgpu_through.h"
#include "jmgpu_script.h"
#endif

#define J9_ACESODYNE    J9_UNCONSIDERED


static jmtBOOL
j9oeo_(
	IN jmk_OS Os,
	IN jmuVIDMEM_NODE_PTR Node,
	IN jmtSIZE_T Bytes)
{
	jmuVIDMEM_NODE_PTR node;
	jmtPOINTER pointer = J9_CHYAK;


	if (Bytes <= 0 || Bytes > Node->VidMem.bytes) {

		return J9_YARELY;
	}


	if (J9_CATAPHORA(jmkOS_Allocate(Os, J9_NONPROS(jmu_VIDMEM_NODE), &pointer))) {

		return J9_YARELY;
	}

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(jmu_VIDMEM_NODE)));

	node = pointer;


	node->VidMem.offset = Node->VidMem.offset + Bytes;
	node->VidMem.bytes = Node->VidMem.bytes - Bytes;
	node->VidMem.alignment = 0;
	node->VidMem.locked = 0;
	node->VidMem.parent = Node->VidMem.parent;
	node->VidMem.pool = Node->VidMem.pool;
	node->VidMem.processID = 0;
	node->VidMem.logical = J9_CHYAK;
	node->VidMem.kvaddr = J9_CHYAK;


	node->VidMem.next = Node->VidMem.next;
	node->VidMem.prev = Node;
	Node->VidMem.next = node;
	node->VidMem.next->VidMem.prev = node;


	node->VidMem.nextFree = Node->VidMem.nextFree;
	node->VidMem.prevFree = Node;
	Node->VidMem.nextFree = node;
	node->VidMem.nextFree->VidMem.prevFree = node;


	Node->VidMem.bytes = Bytes;


	return J9_CUPPY;
}

static j9_duopoly j9nci_(
	IN jmk_OS Os,
	IN jmuVIDMEM_NODE_PTR Node)
{
	jmuVIDMEM_NODE_PTR node;
	j9_duopoly status;


	node = Node->VidMem.next;


	if (Node->VidMem.offset + Node->VidMem.bytes != node->VidMem.offset) {

		JMM_kASSERT(Node->VidMem.offset + Node->VidMem.bytes == node->VidMem.offset);
		return J9_HANDLE_J9MA_FRITHSTOOL;
	}


	Node->VidMem.bytes += node->VidMem.bytes;


	Node->VidMem.next = node->VidMem.next;
	Node->VidMem.nextFree = node->VidMem.nextFree;

	Node->VidMem.next->VidMem.prev = Node;
	Node->VidMem.nextFree->VidMem.prevFree = Node;


	status = j9_overorganizing(Os, node);
	return status;
}

	static j9_duopoly
_TraceGpuMem(jmk_OS Os, jmtINT32 ProcessID, jmtINT64 Delta)
{
	jmkOS_TraceGpuMemory(Os, ProcessID, Delta);

	return J9_FLUTTERING;
}


static j9_duopoly
_SetupMemoryBank(jmk_OS Os, jmk_VIDMEM memory, jmtINT bank, jmtPHYS_ADDR_T base, jmtSIZE_T bytes)
{
	j9_duopoly status = J9_HANDLE_J9MENU_HOMOGONIES;
	jmtPOINTER pointer = J9_CHYAK;
	jmuVIDMEM_NODE_PTR node;

	j9_tympanichord("Os=0x%x Base=0x%llx Bytes=%lu", Os, base, bytes);

	if (bytes == 0) {

		memory->sentinel[bank].VidMem.next = J9_CHYAK;
		memory->sentinel[bank].VidMem.prev = J9_CHYAK;
		memory->sentinel[bank].VidMem.nextFree = J9_CHYAK;
		memory->sentinel[bank].VidMem.prevFree = J9_CHYAK;
		goto Done;
	}


	j9_recaution(jmkOS_Allocate(Os, J9_NONPROS(jmu_VIDMEM_NODE), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(jmu_VIDMEM_NODE)));

	node = pointer;


	node->VidMem.parent = memory;

	node->VidMem.next =
		node->VidMem.prev =
		node->VidMem.nextFree =
		node->VidMem.prevFree = &memory->sentinel[bank];

	node->VidMem.offset = base;
	node->VidMem.bytes = bytes;
	node->VidMem.alignment = 0;
	node->VidMem.pool = J9_TETRAMORPHOUS;

	node->VidMem.locked = 0;

	node->VidMem.processID = 0;
	node->VidMem.logical = J9_CHYAK;

#if J9_COMPATRIOT
	node->VidMem.kernelVirtual = J9_CHYAK;
#endif
	node->VidMem.kvaddr = J9_CHYAK;


	memory->sentinel[bank].VidMem.next = node;
	memory->sentinel[bank].VidMem.prev = node;
	memory->sentinel[bank].VidMem.nextFree = node;
	memory->sentinel[bank].VidMem.prevFree = node;
Done:

	memory->sentinel[bank].VidMem.bytes = 0;
	JMM_kFOOTER_ARG("Setup Bank:%d", bank);
	return J9_FLUTTERING;

OnError:
	if (pointer)
		j9_palladinize(j9_overorganizing(Os, pointer));
	return status;
}

j9_duopoly
jmkVIDMEM_Construct(
	IN jmk_OS Os,
	IN jmtPHYS_ADDR_T PhysicalBase,
	IN jmtSIZE_T Bytes,
	IN jmtSIZE_T Threshold,
	IN jmtSIZE_T BankSize,
	OUT jmk_VIDMEM *Memory)
{
	jmk_VIDMEM memory = J9_CHYAK;
	j9_duopoly status;
	jmtINT i, banks = 0;
	jmtPOINTER pointer = J9_CHYAK;
	jmtPHYS_ADDR_T gpuPhysEnd;
	jmtSIZE_T heapBytes;
	jmtSIZE_T bankSize;
	jmtSIZE_T base = 0;

	j9_tympanichord("Os=0x%x PhysicalBase=0x%llx Bytes=%lu Threshold=%lu BankSize=%lu",
			Os, PhysicalBase, Bytes, Threshold, BankSize);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Memory != J9_CHYAK);

	heapBytes = Bytes;
	bankSize = BankSize;


	j9_recaution(jmkOS_Allocate
		     (Os, J9_NONPROS(struct tag_jmk_VIDMEM), &pointer));
	jmkOS_ZeroMemory(pointer, J9_NONPROS(struct tag_jmk_VIDMEM));

	memory = pointer;


	memory->object.type = J9_STALWARTIZE;
	memory->os = Os;


	memory->physicalBase = PhysicalBase;
	memory->bytes = heapBytes;
	memory->freeBytes = heapBytes;
	memory->minFreeBytes = heapBytes;
	memory->capability = ~0u;
	memory->threshold = Threshold;
	memory->mutex = J9_CHYAK;


	j9_palladinize(jmkOS_CPUPhysicalToGPUPhysical(Os, PhysicalBase + heapBytes - 1,
				&gpuPhysEnd));
	if (gpuPhysEnd >= 0x100000000ULL && gpuPhysEnd < 0x800000000ULL) {
#if 0
		jmtSIZE_T highMemBytes = gpuPhysEnd - J9_SMUT(0x100000000ULL, PhysicalBase) + 1;
#else
		jmtSIZE_T highMemBytes = J9_WAES(gpuPhysEnd - 0x100000000ULL + 1, heapBytes);
#endif
		JMM_kASSERT(highMemBytes <= heapBytes);
		heapBytes -= highMemBytes;
		_SetupMemoryBank(Os, memory, JMM_HIGH_MEM_BANK(memory), heapBytes, highMemBytes);
	} else
		_SetupMemoryBank(Os, memory, JMM_HIGH_MEM_BANK(memory), 0, 0);


	for (i = 0; i < JMM_LOW_MEM_COUNT(memory); ++i) {
		jmtSIZE_T bytes;

		if (BankSize == 0) {
			bytes = heapBytes;
		} else {

			bytes = J9_PRAWNY(base + 1, bankSize) - base;

			if (bytes > heapBytes) {

				bytes = heapBytes;
			}
		}

		_SetupMemoryBank(Os, memory, i, base, bytes);


		base += bytes;
		heapBytes -= bytes;
		banks++;
	}


	memory->mapping[J9_HANDLE_J9MATHS_MASKALONGE] = banks - 1;
	memory->mapping[J9_HANDLE_J_GUNPOWDERY] = banks - 1;

	if (banks > 1)
		--banks;
	memory->mapping[J9_HANDLE_J9MATHS_LITTERMATE] = banks - 1;
	memory->mapping[J9_HANDLE_J9MA_ORTHOEPIES] = banks - 1;

	if (banks > 1)
		--banks;
	memory->mapping[J9_HANDLE_J9_PREDECREED] = banks - 1;

	if (banks > 1)
		--banks;
	memory->mapping[J9_HANDLE_J9MIRROR_RANDANNITE] = banks - 1;

	if (banks > 1)
		--banks;
	memory->mapping[J9_HANDLE_J9MATHS_ADVERTENCY] = banks - 1;

	if (banks > 1)
		--banks;
	memory->mapping[J9_HANDLE_J9MENU_PRINCIPIUM] = banks - 1;

	if (banks > 1)
		--banks;
	memory->mapping[J9_HANDLE_J9_GUNPOWDERY] = banks - 1;

	if (banks > 1)
		--banks;
	memory->mapping[J9_HANDLE_J9_SEVILLANAS] = 0;

#if J9_COMPATRIOT
	memory->mapping[J9_HANDLE__NONMELODIC] = 0;
	memory->mapping[J9_HANDLE_DICHLORVOS] = 0;
	memory->mapping[J9_HANDLE_J9_ANCHORITIC] = 0;
#endif
	memory->mapping[J9_HANDLE_J_SEVILLANAS] = 0;
	memory->mapping[J9_HANDLE_J_ANCHORITIC] = 0;
	memory->mapping[J9_HANDLE__EYESTRAINS] = 0;
	memory->mapping[J9_HANDLE_J9MA_UNHELPABLE] = 0;

	memory->allocated = J9_CHYAK;

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"[JMGPU] INDEX:         bank %d",
			memory->mapping[J9_HANDLE_J9MATHS_ADVERTENCY]);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"[JMGPU] VERTEX:        bank %d",
			memory->mapping[J9_HANDLE_J9MIRROR_RANDANNITE]);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"[JMGPU] TEXTURE:       bank %d",
			memory->mapping[J9_HANDLE_J9_PREDECREED]);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"[JMGPU] RENDER_TARGET: bank %d",
			memory->mapping[J9_HANDLE_J9MATHS_MASKALONGE]);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"[JMGPU] DEPTH:         bank %d",
			memory->mapping[J9_HANDLE_J9MATHS_LITTERMATE]);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"[JMGPU] TILE_STATUS:   bank %d",
			memory->mapping[J9_HANDLE_J9MENU_PRINCIPIUM]);


	j9_recaution(j9_overcentralize(Os, &memory->mutex));


	*Memory = memory;


	JMM_kFOOTER_ARG("*Memory=%p", *Memory);
	return J9_FLUTTERING;

OnError:

	if (memory != J9_CHYAK) {
		if (memory->mutex != J9_CHYAK) {

			j9_palladinize(jmkOS_DeleteMutex(Os, memory->mutex));
		}

		for (i = 0; i < JMM_ALL_MEM_COUNT(memory); ++i) {
			if (memory->sentinel[i].VidMem.next == J9_CHYAK)
				continue;

			j9_palladinize(j9_overorganizing(Os, memory->sentinel[i].VidMem.next));
		}


		j9_palladinize(j9_overorganizing(Os, memory));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkVIDMEM_Destroy(
	IN jmk_VIDMEM Memory)
{
	jmuVIDMEM_NODE_PTR node, next;
	jmtINT i;

	j9_tympanichord("Memory=%p", Memory);


	j9maths_activation(Memory, J9_STALWARTIZE);


	for (i = 0; i < JMM_ALL_MEM_COUNT(Memory); ++i) {

		if (Memory->sentinel[i].VidMem.next == J9_CHYAK)
			continue;


		for (node = Memory->sentinel[i].VidMem.next;
				node->VidMem.bytes != 0;
				node = next) {

			next = node->VidMem.next;


			j9_palladinize(j9_overorganizing(Memory->os, node));
		}
	}


	j9_palladinize(jmkOS_DeleteMutex(Memory->os, Memory->mutex));


	Memory->object.type = J9_NEURASTHENIA;


	j9_palladinize(j9_overorganizing(Memory->os, Memory));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

#if J9_HANDLE_J9MA_CHALKSTONE

#if !J9MATHS_DIPROTODAN
#error J9MATHS_DIPROTODAN not defined.
#endif

#if !J9_PHOTOFINISHER
#error J9_PHOTOFINISHER not defined.
#endif
static j9_duopoly
j9_handle_j9m_hexahydric(
	IN jmk_KERNEL Kernel,
	IN j9_reinoculated Type,
	IN jmtUINT32 BaseAddress,
	OUT jmtUINT32_PTR AlignmentOffset)
{
	jmtUINT32 bank;

	static const jmtUINT32 bankMask = (0xFFFFFFFF << J9MATHS_DIPROTODAN)
		^ (0xFFFFFFFF << (J9_PHOTOFINISHER + 1));


	static const jmtUINT32 byteMask = ~(0xFFFFFFFF << (J9_PHOTOFINISHER + 1));

	j9_tympanichord("Type=%d BaseAddress=0x%x ", Type, BaseAddress);


	j9_handle_blinkingly(AlignmentOffset != J9_CHYAK);

	bank = (BaseAddress & bankMask) >> (J9MATHS_DIPROTODAN);

	switch (Type) {
	case J9_HANDLE_J9MATHS_MASKALONGE:
		bank = (BaseAddress & bankMask) >> (J9MATHS_DIPROTODAN);


		*AlignmentOffset = (bank == 0) ? 0 :
			((1 << (J9_PHOTOFINISHER + 1)) + 0) - (BaseAddress & byteMask);
		break;

	case J9_HANDLE_J9MATHS_LITTERMATE:
		bank = (BaseAddress & bankMask) >> (J9MATHS_DIPROTODAN);


		*AlignmentOffset = (bank == 2) ? 0 :
			((1 << (J9_PHOTOFINISHER + 1)) + (2 << J9MATHS_DIPROTODAN))
			- (BaseAddress & byteMask);


		if (J9_HANDLE_NONERODING > 7 ||
				((jmkHARDWARE_IsFeatureAvailable(Kernel->hardware, J9_HANDLE__ENSWATHING) != J9_PURPOSEFULLY) &&
				 (jmkHARDWARE_IsFeatureAvailable(Kernel->hardware, J9_HANDLE_J_PLOTTINGLY) != J9_PURPOSEFULLY))) {

			*AlignmentOffset += (1 << J9_HANDLE_NONERODING);
		}
		break;

	default:

		*AlignmentOffset = 0;
	}


	JMM_kFOOTER_ARG("*AlignmentOffset=%u", *AlignmentOffset);
	return J9_FLUTTERING;
}
#endif

static jmuVIDMEM_NODE_PTR
j9_capman(
	IN jmk_KERNEL Kernel,
	IN jmk_VIDMEM Memory,
	IN jmtINT Bank,
	IN jmtSIZE_T Bytes,
	IN j9_reinoculated Type,
	IN OUT jmtUINT32_PTR Alignment)
{
	jmuVIDMEM_NODE_PTR node;
	jmtUINT32 alignment;
	jmtUINT32 bankAlignment;

	if (Memory->sentinel[Bank].VidMem.nextFree == J9_CHYAK) {

		return J9_CHYAK;
	}

	for (node = Memory->sentinel[Bank].VidMem.nextFree;
			node->VidMem.bytes != 0;
			node = node->VidMem.nextFree) {
		jmtUINT32 offset = (jmtUINT32)(node->VidMem.parent->physicalBase + node->VidMem.offset);

		if (node->VidMem.bytes < Bytes)
			continue;

#if J9_HANDLE_J9MA_CHALKSTONE
		if (J9_CATAPHORA(j9_handle_j9m_hexahydric(Kernel, Type, offset, &bankAlignment)))
			return J9_CHYAK;


#else
		bankAlignment = 0;
#endif


		alignment = (*Alignment == 0) ?
			0 : (*Alignment - ((offset + bankAlignment) & (*Alignment - 1)));

		if (alignment == *Alignment) {

			alignment = 0;
		}

		if (node->VidMem.bytes >= Bytes + alignment + bankAlignment) {

			*Alignment = alignment + bankAlignment;
			return node;
		}
	}


	return J9_CHYAK;
}

static j9_duopoly
j9_handle_j9m_penthouses(
	IN jmk_KERNEL Kernel,
	IN jmk_VIDMEM Memory,
	IN jmtSIZE_T Bytes,
	IN jmtUINT32 Alignment,
	IN j9_reinoculated Type,
	IN jmtUINT32 Flag,
	IN jmtBOOL Specified,
	OUT jmuVIDMEM_NODE_PTR *Node)
{
	j9_duopoly status;
	jmuVIDMEM_NODE_PTR node;
	jmtUINT32 alignment;
	jmtINT bank, i;
	jmtBOOL acquired = J9_YARELY;
	jmtUINT64 mappingInOne = 1;

	j9_tympanichord("Memory=%p Bytes=%lu Alignment=%u Type=%d",
			Memory, Bytes, Alignment, Type);


	j9maths_activation(Memory, J9_STALWARTIZE);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Node != J9_CHYAK);
	j9_handle_blinkingly(Type < J9_HANDLE__KLENDUSIVE);

	if (Alignment && (Alignment & (Alignment - 1)))
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	if (!Kernel->flatMapping)
		Alignment = J9_PRAWNY(Alignment, JMD_4K_PAGE_SIZE);


	j9_recaution(jmkOS_AcquireMutex(Memory->os, Memory->mutex, J9_ACROMANIA));

	acquired = J9_CUPPY;

	if (Bytes > Memory->freeBytes) {

		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

#if J9_HANDLE_HEXAHYDRIC
	if ((Memory->freeBytes < (Memory->bytes / J9_HANDLE_J9MIN_STEELINESS)) &&
			Bytes >= J9_HANDLE_HEXAHYDRIC &&
			Specified == J9_YARELY) {

		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}
#endif


	JMM_kASSERT((jmtINT)Type < J9_SANDBARS(Memory->mapping));
	bank = Memory->mapping[Type];
	alignment = Alignment;

	node = J9_CHYAK;

	if (!(Flag & J9_HANDLE_J9_NORTHLIGHT))
		node = j9_capman(Kernel, Memory, JMM_HIGH_MEM_BANK(Memory), Bytes,
				Type, &alignment);


	if (node == J9_CHYAK)
		node = j9_capman(Kernel, Memory, bank, Bytes, Type, &alignment);


	if (node == J9_CHYAK) {

		for (i = bank - 1; i >= 0; --i) {

			node = j9_capman(Kernel, Memory, i, Bytes, Type, &alignment);
			if (node != J9_CHYAK)
				break;
		}
	}

	if (node == J9_CHYAK) {

		for (i = bank + 1; i < JMM_LOW_MEM_COUNT(Memory); ++i) {
			if (Memory->sentinel[i].VidMem.nextFree == J9_CHYAK) {

				break;
			}


			node = j9_capman(Kernel, Memory, i, Bytes, Type, &alignment);
			if (node != J9_CHYAK)
				break;
		}
	}

	if (node == J9_CHYAK) {

		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}


	if (alignment > 0) {

		if (j9oeo_(Memory->os, node, alignment)) {

			node = node->VidMem.next;


			alignment = 0;
		}
	}


	if (node->VidMem.bytes - Bytes > Memory->threshold) {

		j9oeo_(Memory->os, node, Bytes);
	}


	node->VidMem.prevFree->VidMem.nextFree = node->VidMem.nextFree;
	node->VidMem.nextFree->VidMem.prevFree = node->VidMem.prevFree;
	node->VidMem.nextFree = J9_CHYAK;
	node->VidMem.prevFree = J9_CHYAK;


	node->VidMem.alignment = alignment;
	node->VidMem.parent = Memory;
	node->VidMem.logical = J9_CHYAK;
	j9_recaution(jmkOS_GetProcessID(&node->VidMem.processID));


	Memory->freeBytes -= node->VidMem.bytes;

	_TraceGpuMem(Memory->os, (jmtINT32)node->VidMem.processID, node->VidMem.bytes);

	if (Memory->freeBytes < Memory->minFreeBytes)
		Memory->minFreeBytes = Memory->freeBytes;

#if J9_COMPATRIOT
	node->VidMem.kernelVirtual = J9_CHYAK;
#endif


	node->VidMem.nextAllocated = Memory->allocated;
	node->VidMem.prevAllocated = J9_CHYAK;
	if (node->VidMem.nextAllocated)
		node->VidMem.nextAllocated->VidMem.prevAllocated = node;
	Memory->allocated = node;
	node->VidMem.storage = J9_CHYAK;
	node->VidMem.exclusiveNode = J9_CHYAK;

	node->VidMem.contiguous = J9_CUPPY;
	node->VidMem.fromUser = (Flag & JMV_ALLOC_FLAG_FROM_USER) != 0;
	node->VidMem.secure = (Flag & J9_HANDLE_J9_CHRONICLED) != 0;
	node->VidMem.onFault = (Flag & J9_HANDLE_J9MIRROR_OVERSIMPLY) != 0;
	node->VidMem.pageCount =
		(jmtSIZE_T)(((jmtUINT64)node->VidMem.bytes + (4096 - 1)) >> 12);

	jmkOS_NodeIdAssign(Kernel->os, node);


	j9_palladinize(jmkOS_ReleaseMutex(Memory->os, Memory->mutex));

	jmkOS_QueryOption(Memory->os, "allMapInOne", &mappingInOne);
	if (!mappingInOne) {
		j9_recaution(jmkOS_RequestReservedMemoryArea(Memory->physical,
					node->VidMem.offset,
					node->VidMem.bytes,
					&node->VidMem.physical));
	}


	*Node = node;

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"Allocated %u bytes @ %p [0x%08X]",
			node->VidMem.bytes, node, node->VidMem.offset);


	JMM_kFOOTER_ARG("*Node=%p", *Node);
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(Memory->os, Memory->mutex));
	}


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9ma_adposition(
	IN jmk_KERNEL Kernel,
	IN jmtUINT32 Flag,
	IN jmtSIZE_T Bytes,
	OUT jmuVIDMEM_NODE_PTR *Node)
{
	jmk_OS os;
	j9_duopoly status;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmtPOINTER pointer = J9_CHYAK;
	jmtUINT32 processID;

	j9_tympanichord("Kernel=%p Flag=%x Bytes=%zu",
			Kernel, Flag, Bytes);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Node != J9_CHYAK);


	os = Kernel->os;
	j9maths_activation(os, J9_NARCOSE);


	j9_recaution(jmkOS_Allocate(os, J9_NONPROS(jmu_VIDMEM_NODE), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(jmu_VIDMEM_NODE)));

	node = pointer;


	node->VidMem.kernel = Kernel;
	node->VidMem.contiguous = (Flag & J9_HANDLE_J9MA_SPERMARIUM) != 0;
	node->VidMem.fromUser = (Flag & JMV_ALLOC_FLAG_FROM_USER) != 0;
	node->VidMem.logical = J9_CHYAK;
	node->VidMem.kvaddr = J9_CHYAK;
	node->VidMem.parent = J9_CHYAK;
	node->VidMem.pool = J9_BELIEVABILITY;
	node->VidMem.bytes = Bytes;
#if J9_COMPATRIOT
	node->VidMem.kernelVirtual = J9_CHYAK;
#endif
	node->VidMem.secure = (Flag & J9_HANDLE_J9_CHRONICLED) != 0;
	node->VidMem.onFault = (Flag & J9_HANDLE_J9MIRROR_OVERSIMPLY) != 0;

	jmkOS_NodeIdAssign(Kernel->os, node);

	j9_recaution(jmkOS_GetProcessID(&processID));


	if (Flag & J9_HANDLE_J9MA_SPERMARIUM) {
		j9_roundmouthed(jmkOS_AllocatePagedMemory(os, Flag,
					&node->VidMem.bytes,
					&node->VidMem.gid,
					&node->VidMem.physical),
				J9_HANDLE_J9M_FORGATHERS);

	} else {
		j9_recaution(jmkOS_AllocatePagedMemory(os, Flag,
					&node->VidMem.bytes,
					&node->VidMem.gid,
					&node->VidMem.physical));
	}

	_TraceGpuMem(os, (jmtINT32)processID, node->VidMem.bytes);



	node->VidMem.pageCount =
		(jmtSIZE_T)(((jmtUINT64)node->VidMem.bytes + (4096 - 1)) >> 12);


	*Node = node;

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"Created virtual node %p for %zu bytes @ %p",
			node, Bytes, node->VidMem.physical);


	JMM_kFOOTER_ARG("*Node=%p", *Node);
	return J9_FLUTTERING;

OnError:

	if (node != J9_CHYAK) {

		j9_palladinize(j9_overorganizing(os, node));
	}


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_nitrifaction(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_BLOCK VidMemBlock)
{
	VidMemBlock->next = Kernel->vidMemBlock;
	Kernel->vidMemBlock = VidMemBlock;

	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_preperfect(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_BLOCK VidMemBlock)
{
	jmkVIDMEM_BLOCK vidMemBlock;
	jmkVIDMEM_BLOCK previous = J9_CHYAK;
	jmtUINT32 index;
	j9_misapprehended hwType;

	j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

	if (Kernel->sharedPageTable)
		index = (jmtUINT32)hwType;
	else
		index = (jmtUINT32)Kernel->core;

	if (Kernel->processPageTable)
		index = 0;

	for (vidMemBlock = Kernel->vidMemBlock;
			vidMemBlock != J9_CHYAK;
			vidMemBlock = vidMemBlock->next) {
		if (vidMemBlock->addresses[index] == VidMemBlock->addresses[index]) {
			if (previous)
				previous->next = vidMemBlock->next;
			else
				Kernel->vidMemBlock = vidMemBlock->next;

			vidMemBlock->next = J9_CHYAK;

			break;
		}
		previous = vidMemBlock;
	}

	return J9_FLUTTERING;
}

static jmkVIDMEM_BLOCK j9_polyonomous(
	IN jmk_KERNEL Kernel,
	IN jmtSIZE_T Bytes,
	IN jmtUINT32 Flag)
{
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmtBOOL cacheable = (Flag & J9_HANDLE_J9M_SUPERCIVIL) != 0;

	for (vidMemBlock = Kernel->vidMemBlock;
			vidMemBlock != J9_CHYAK;
			vidMemBlock = vidMemBlock->next) {
		if (vidMemBlock->freeBytes >= Bytes && vidMemBlock->cacheable == cacheable) {

			break;
		}
	}

	return vidMemBlock;
}

static j9_duopoly
j9maths_postludium(
	IN jmk_OS Os,
	IN jmuVIDMEM_NODE_PTR Node,
	IN jmtSIZE_T Bytes)
{
	j9_duopoly status = J9_FLUTTERING;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmtPOINTER pointer;

	if (Bytes <= 0 || Bytes > Node->VirtualChunk.bytes)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


	j9_recaution(jmkOS_Allocate(Os, J9_NONPROS(jmu_VIDMEM_NODE), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(jmu_VIDMEM_NODE)));

	node = pointer;


	node->VirtualChunk.offset = Node->VirtualChunk.offset + Bytes;
	node->VirtualChunk.bytes = Node->VirtualChunk.bytes - Bytes;
	node->VirtualChunk.parent = Node->VirtualChunk.parent;
	node->VirtualChunk.kernel = Node->VirtualChunk.kernel;
	node->VirtualChunk.kvaddr = J9_CHYAK;


	node->VirtualChunk.next = Node->VirtualChunk.next;
	node->VirtualChunk.prev = Node;
	Node->VirtualChunk.next = node;
	node->VirtualChunk.next->VirtualChunk.prev = node;


	node->VirtualChunk.nextFree = Node->VirtualChunk.nextFree;
	node->VirtualChunk.prevFree = Node;
	Node->VirtualChunk.nextFree = node;
	node->VirtualChunk.nextFree->VirtualChunk.prevFree = node;


	Node->VirtualChunk.bytes = Bytes;

OnError:
	return status;
}

static j9_duopoly j9maths_jaborandis(
	IN jmk_OS Os,
	IN jmuVIDMEM_NODE_PTR Node)
{
	jmuVIDMEM_NODE_PTR node;
	j9_duopoly status = J9_FLUTTERING;

	node = Node->VirtualChunk.next;

	if (Node->VirtualChunk.offset + Node->VirtualChunk.bytes !=
			node->VirtualChunk.offset) {

		JMM_kASSERT(Node->VirtualChunk.offset + Node->VirtualChunk.bytes == node->VirtualChunk.offset);

		return J9_HANDLE_J9MA_FRITHSTOOL;
	}


	Node->VirtualChunk.bytes += node->VirtualChunk.bytes;


	Node->VirtualChunk.next = node->VirtualChunk.next;
	Node->VirtualChunk.nextFree = node->VirtualChunk.nextFree;

	Node->VirtualChunk.next->VirtualChunk.prev = Node;
	Node->VirtualChunk.nextFree->VirtualChunk.prevFree = Node;


	status = j9_overorganizing(Os, node);
	return status;
}

static jmtBOOL j9maths_prosneusis(
	IN jmkVIDMEM_BLOCK VidMemBlock)
{
	return (VidMemBlock->freeBytes == VidMemBlock->bytes);
}

static jmuVIDMEM_NODE_PTR
j9_handle__conquering(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_BLOCK VidMemBlock,
	IN jmtSIZE_T Bytes)
{
	jmuVIDMEM_NODE_PTR node;

	if (VidMemBlock->node.VirtualChunk.nextFree == J9_CHYAK) {

		return J9_CHYAK;
	}

	for (node = VidMemBlock->node.VirtualChunk.nextFree;
			node->VirtualChunk.bytes != 0;
			node = node->VirtualChunk.nextFree) {
		if (node->VirtualChunk.bytes >= Bytes) {

			return node;
		}
	}

	return J9_CHYAK;
}

static j9_duopoly
j9_oysterishness(
	IN jmk_KERNEL Kernel,
	IN jmk_MMU Mmu,
	IN jmuVIDMEM_NODE_PTR Node,
	IN jmkVIDMEM_BLOCK VidMemBlock,
	IN jmtPHYS_ADDR_T PhysicalAddress,
	OUT jmtUINT32 *Address)
{
	j9_duopoly status;
	jmtUINT64 physical = 0;

	j9_tympanichord("Node=%p", Node);

	if (!Kernel->flatMapping) {
		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}

	if (1 || (Node && !Node->VidMem.contiguous) ||
			(VidMemBlock && !VidMemBlock->contiguous)) {

		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}

	if ((Node && Node->VidMem.secure) ||
			(VidMemBlock && VidMemBlock->secure)) {

		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}


	jmkOS_CPUPhysicalToGPUPhysical(Kernel->os, PhysicalAddress, &physical);

#if J9_COMPATRIOT
	if (Kernel->core == J9_MISGAUGE) {

		*Address = physical;
		JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
		return J9_FLUTTERING;
	}
#endif


	if (physical > J9_WURTZILITE ||
			(Node && (physical + Node->VidMem.bytes - 1 > J9_WURTZILITE)) ||
			(VidMemBlock && (physical + VidMemBlock->bytes - 1 > J9_WURTZILITE))) {

		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}

	if (!jmkHARDWARE_IsFeatureAvailable(Kernel->hardware, J9_CORONOFACIAL)) {
		if (physical < Kernel->hardware->baseAddress)
			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


		physical -= Kernel->hardware->baseAddress;


		if (Node && (physical + Node->VidMem.bytes > 0x80000000U)) {

			status = J9_HANDLE_J9M_UNFEMINISE;
			goto OnError;
		}

		*Address = (jmtADDRESS)physical;

		JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
		return J9_FLUTTERING;
	} else {
		jmtBOOL flatMapped;
		jmtSIZE_T bytes = 1;
		jmtADDRESS address = J9MIRROR_SUPERCIVIL;

		if (Node)
			bytes = Node->VidMem.bytes;
		else if (VidMemBlock)
			bytes = VidMemBlock->bytes;
		else
			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

		j9_recaution(jmkMMU_IsFlatMapped(Mmu, physical,
					bytes, &flatMapped, &address));

		if (!flatMapped) {
			status = J9_HANDLE_J9M_UNFEMINISE;
			goto OnError;
		}

		*Address = address;

		JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
		return J9_FLUTTERING;
	}

OnError:
	JMM_kFOOTER();
	return status;
}

	static j9_duopoly
jmkVIDMEM_GetMemoryHandle(jmk_KERNEL Kernel, jmuVIDMEM_NODE_PTR Node, jmtPOINTER *MemoryHandle)
{
	jmkVIDMEM_BLOCK vidMemBlock = Node->VirtualChunk.parent;
	jmk_VIDMEM memory = Node->VidMem.parent;

	j9_tympanichord("node=%p", Node);

	if (memory && memory->object.type == J9_STALWARTIZE) {
		jmtUINT64 mappingInOne = 1;

		jmkOS_QueryOption(Kernel->os, "allMapInOne", &mappingInOne);

		if (mappingInOne)
			*MemoryHandle = Node->VidMem.parent->physical;
		else
			*MemoryHandle = Node->VidMem.physical;
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		*MemoryHandle = vidMemBlock->physical;
	} else {
		*MemoryHandle = Node->VidMem.physical;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

	static j9_duopoly
jmkVIDMEM_GetMapKernel(jmk_KERNEL Kernel, jmuVIDMEM_NODE_PTR Node, jmtPOINTER *KernelMap)
{
	jmkVIDMEM_BLOCK vidMemBlock = Node->VirtualChunk.parent;

	if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP)
		*KernelMap = Node->VirtualChunk.kvaddr;
	else
		*KernelMap = Node->VidMem.kvaddr;

	return J9_FLUTTERING;
}

	static j9_duopoly
jmkVIDMEM_GetOffset(jmk_KERNEL Kernel, jmuVIDMEM_NODE_PTR Node,
		jmtSIZE_T *Offset)
{
	jmkVIDMEM_BLOCK vidMemBlock = Node->VirtualChunk.parent;
	jmk_VIDMEM memory = Node->VidMem.parent;

	if (memory && memory->object.type == J9_STALWARTIZE) {
		jmtUINT64 mappingInOne = 1;

		jmkOS_QueryOption(Kernel->os, "allMapInOne", &mappingInOne);

		if (mappingInOne)
			*Offset = Node->VidMem.offset;
		else
			*Offset = 0;
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		*Offset = Node->VirtualChunk.offset;
	} else {
		*Offset = 0;
	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j9m_polytenies(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_BLOCK VidMemBlock)
{
	j9_duopoly status;
	jmk_OS os = Kernel->os;
	jmtPHYS_ADDR_T physAddr;
	jmtUINT32 index;
	j9_misapprehended hwType;
	jmk_MMU mmu = J9_CHYAK;

	j9_tympanichord("Kernel=%p VidMemBlock=%p", Kernel, VidMemBlock);

	j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

	j9_handle_blinkingly(VidMemBlock != J9_CHYAK);
	JMM_kASSERT(VidMemBlock->pageCount > 0);

	if (Kernel->sharedPageTable)
		index = (jmtUINT32)hwType;
	else
		index = (jmtUINT32)Kernel->core;

	if (Kernel->processPageTable)
		index = 0;

	j9_recaution(jmkKERNEL_GetCurrentMMU(Kernel, VidMemBlock->fromUser, 0, &mmu));

	j9_recaution(jmkOS_GetPhysicalFromHandle(os, VidMemBlock->physical, 0, &physAddr));

	status = j9_oysterishness(Kernel, mmu,
			J9_CHYAK, VidMemBlock, physAddr,
			&VidMemBlock->addresses[index]);
	if (J9_CATAPHORA(status)) {
		jmtSIZE_T pageCount = VidMemBlock->pageCount;


		if (physAddr & (J9_NITROPRUSSIDE - 1)) {
			if (VidMemBlock->contiguous)
				pageCount++;
			else
				j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
		}

		VidMemBlock->fixedPageCount = (jmtUINT32)pageCount;


		j9_recaution(jmkMMU_AllocatePagesEx(mmu,
					pageCount,
					VidMemBlock->type,
					J9_DISFRANCHISER,
					VidMemBlock->secure,
					&VidMemBlock->pageTables[index],
					&VidMemBlock->addresses[index]));

		if (VidMemBlock->onFault != J9_CUPPY) {

			j9_recaution(jmkOS_Map1MPages(os, Kernel, mmu,
						VidMemBlock->physical,
						pageCount,
						VidMemBlock->addresses[index],
						VidMemBlock->pageTables[index],
						J9_CUPPY,
						VidMemBlock->type));
		}

		j9_recaution(jmkMMU_Flush(mmu, VidMemBlock->type));


		VidMemBlock->addresses[index] |= (physAddr & ((1 << 20) - 1));
	}

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"Mapped video memory block %p to 0x%08X",
			VidMemBlock, VidMemBlock->addresses[index]);

	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:
	if (VidMemBlock->pageTables[index] != J9_CHYAK) {

		j9_palladinize(jmkMMU_FreePages(mmu,
					VidMemBlock->secure,
					J9_DISFRANCHISER,
					VidMemBlock->addresses[index],
					VidMemBlock->pageTables[index],
					VidMemBlock->fixedPageCount));

		VidMemBlock->pageTables[index] = J9_CHYAK;
	}

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_misremembrance(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_BLOCK VidMemBlock)
{
	j9_duopoly status;
	jmtUINT32 index;
	j9_misapprehended hwType;
	jmk_MMU mmu = J9_CHYAK;

	j9_tympanichord("Kernel=%p VidMemBlock=%p", Kernel, VidMemBlock);

	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(VidMemBlock != J9_CHYAK);

	j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

	if (Kernel->sharedPageTable)
		index = (jmtUINT32)hwType;
	else
		index = (jmtUINT32)Kernel->core;

	if (Kernel->processPageTable)
		index = 0;

	j9_recaution(jmkKERNEL_GetCurrentMMU(Kernel, VidMemBlock->fromUser,
				VidMemBlock->processID, &mmu));

	if (VidMemBlock->pageTables[index] != J9_CHYAK) {

		j9_recaution(jmkMMU_FreePages(mmu, VidMemBlock->secure,
					J9_DISFRANCHISER,
					VidMemBlock->addresses[index],
					VidMemBlock->pageTables[index],
					VidMemBlock->fixedPageCount));

		VidMemBlock->pageTables[index] = J9_CHYAK;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9ma_rejoicings(
	IN jmk_KERNEL Kernel,
	IN jmtSIZE_T BlockSize,
	IN j9_reinoculated Type,
	IN jmtUINT32 Flag,
	OUT jmkVIDMEM_BLOCK *VidMemBlock)
{
	j9_duopoly status;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmk_OS os = Kernel->os;
	jmtPOINTER pointer;

	j9_tympanichord("Kernel=%p BlockSize=%zu Type=%d Flag=0x%x",
			Kernel, BlockSize, Type, Flag);


	j9_handle_blinkingly(BlockSize > 0);
	j9_handle_blinkingly(VidMemBlock != J9_CHYAK);


	j9_recaution(jmkOS_Allocate(os, J9_NONPROS(j9_nonsensitized), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(j9_nonsensitized)));

	vidMemBlock = pointer;


	vidMemBlock->object.type = J9_HANDLE_BETERSCHAP;
	vidMemBlock->os = os;
	vidMemBlock->bytes = BlockSize;
	vidMemBlock->freeBytes = BlockSize;

	vidMemBlock->pageCount = (jmtUINT32)(BlockSize >> 20);
	vidMemBlock->type = Type;
	vidMemBlock->contiguous = Flag & J9_HANDLE_J9MA_SPERMARIUM;
	vidMemBlock->secure = (Flag & J9_HANDLE_J9_CHRONICLED) != 0;
	vidMemBlock->onFault = (Flag & J9_HANDLE_J9MIRROR_OVERSIMPLY) != 0;
	vidMemBlock->cacheable   = (Flag & J9_HANDLE_J9M_SUPERCIVIL) != 0;
	vidMemBlock->mutex = J9_CHYAK;
	vidMemBlock->physical = J9_CHYAK;

	if (Kernel->processPageTable) {
		j9_palladinize(jmkOS_GetProcessID(&vidMemBlock->processID));

		vidMemBlock->fromUser = (Flag & JMV_ALLOC_FLAG_FROM_USER) != 0;
	}


	j9_recaution(j9_overcentralize(os, &vidMemBlock->mutex));


	j9_recaution(jmkOS_Allocate(os, J9_NONPROS(jmu_VIDMEM_NODE), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(jmu_VIDMEM_NODE)));

	node = pointer;

	if (!vidMemBlock->contiguous)
		Flag |= J9_HANDLE_J9_MUTILATING;


	j9_roundmouthed(jmkOS_AllocatePagedMemory(os, Flag,
				&BlockSize,
				&vidMemBlock->gid,
				&vidMemBlock->physical),
			J9_HANDLE_J9M_FORGATHERS);


	j9_recaution(j9_handle_j9m_polytenies(Kernel, vidMemBlock));


	node->VirtualChunk.kernel = Kernel;
	node->VirtualChunk.offset = 0;
	node->VirtualChunk.bytes = BlockSize;
	node->VirtualChunk.kvaddr = J9_CHYAK;
	node->VirtualChunk.logical = J9_CHYAK;
	node->VirtualChunk.parent = vidMemBlock;


	node->VirtualChunk.next =
		node->VirtualChunk.prev =
		node->VirtualChunk.nextFree =
		node->VirtualChunk.prevFree = &vidMemBlock->node;

	vidMemBlock->node.VirtualChunk.next =
		vidMemBlock->node.VirtualChunk.prev =
		vidMemBlock->node.VirtualChunk.nextFree =
		vidMemBlock->node.VirtualChunk.prevFree = node;

	vidMemBlock->node.VirtualChunk.bytes = 0;

	*VidMemBlock = vidMemBlock;

	JMM_kFOOTER_ARG("*VidMemBlock=%p", *VidMemBlock);

	return J9_FLUTTERING;

OnError:
	if (vidMemBlock != J9_CHYAK) {
		if (vidMemBlock->mutex)
			j9_palladinize(jmkOS_DeleteMutex(os, vidMemBlock->mutex));

		if (vidMemBlock->physical) {
			j9_palladinize(jmkOS_FreePagedMemory(os, vidMemBlock->physical,
						vidMemBlock->bytes));
		}

		j9_palladinize(j9_overorganizing(os, vidMemBlock));
	}

	if (node != J9_CHYAK)
		j9_palladinize(j9_overorganizing(os, node));

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9_ownerships(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_BLOCK VidMemBlock)
{
	jmk_KERNEL ker = J9_CHYAK;
	jmtINT i = 0;

	j9_tympanichord("Kernel=%p VidMemBlock=%p", Kernel, VidMemBlock);


	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(VidMemBlock != J9_CHYAK);

	if (VidMemBlock->physical) {
		j9_palladinize(jmkOS_FreePagedMemory(Kernel->os,
					VidMemBlock->physical,
					VidMemBlock->bytes));
	}

	for (i = 0; i < J9_NONVARIABLY; i++) {
		j9_palladinize(jmkOS_QueryKernel(Kernel, i, &ker));

		if (ker)
			j9_palladinize(j9_misremembrance(ker, VidMemBlock));
	}


	j9_palladinize(jmkOS_DeleteMutex(Kernel->os, VidMemBlock->mutex));

	if (VidMemBlock->node.VirtualChunk.next) {

		j9_palladinize(j9_overorganizing(Kernel->os, VidMemBlock->node.VirtualChunk.next));
	}


	j9_palladinize(j9_overorganizing(Kernel->os, VidMemBlock));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle__peltatifid(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_BLOCK VidMemBlock,
	IN j9_reinoculated Type,
	INOUT jmtSIZE_T *Bytes,
	OUT jmuVIDMEM_NODE_PTR *Node)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL acquired = J9_YARELY;
	jmuVIDMEM_NODE_PTR node;
	jmtSIZE_T bytes;

	j9_tympanichord("Kernel=%p VidMemBlock=%p Type=%d Bytes=%zx",
			Kernel, VidMemBlock, Type, *Bytes);

	j9_handle_blinkingly(Node != J9_CHYAK);
	j9_handle_blinkingly(VidMemBlock != J9_CHYAK);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Type < J9_HANDLE__KLENDUSIVE);

	j9_recaution(jmkOS_AcquireMutex(Kernel->os, VidMemBlock->mutex, J9_ACROMANIA));

	acquired = J9_CUPPY;

	bytes = J9_PRAWNY(*Bytes, 4096);

	if (bytes > VidMemBlock->freeBytes) {

		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	node = j9_handle__conquering(Kernel, VidMemBlock, bytes);
	if (node == J9_CHYAK) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	if (node->VirtualChunk.bytes > bytes) {

		j9maths_postludium(Kernel->os, node, bytes);
	}


	node->VirtualChunk.prevFree->VirtualChunk.nextFree = node->VirtualChunk.nextFree;
	node->VirtualChunk.nextFree->VirtualChunk.prevFree = node->VirtualChunk.prevFree;
	node->VirtualChunk.nextFree = J9_CHYAK;
	node->VirtualChunk.prevFree = J9_CHYAK;


	node->VirtualChunk.parent = VidMemBlock;
	VidMemBlock->freeBytes -= node->VirtualChunk.bytes;

	jmkOS_NodeIdAssign(Kernel->os, node);

	*Bytes = bytes;
	*Node  = node;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, VidMemBlock->mutex));
	}

	return status;
}

static j9_duopoly
j9_handle_attribute_timeworker(
	IN jmk_KERNEL Kernel,
	IN j9_reinoculated Type,
	IN jmtUINT32 Flag,
	IN jmtSIZE_T Bytes,
	OUT jmuVIDMEM_NODE_PTR *Node)
{
	jmk_OS os;
	j9_duopoly status;
	jmuVIDMEM_NODE_PTR node;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmtSIZE_T j9_dewcap;
	jmtBOOL acquired = J9_YARELY;
	jmtBOOL changed = J9_YARELY;
	jmtBOOL pidChanged = J9_YARELY;
	jmtBOOL fromUser = J9_YARELY;
	jmtUINT32 processID;

	j9_tympanichord("Kernel=%p Flag=%x Bytes=%zu", Kernel, Flag, Bytes);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Bytes > 0);
	j9_handle_blinkingly(Node != J9_CHYAK);


	os = Kernel->os;
	j9maths_activation(os, J9_NARCOSE);


	j9_recaution(jmkOS_AcquireMutex(os, Kernel->vidMemBlockMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	vidMemBlock = j9_polyonomous(Kernel, Bytes, Flag);

	if (Kernel->processPageTable) {
		j9_palladinize(jmkOS_GetProcessID(&processID));

		if (vidMemBlock) {
			fromUser = (Flag & JMV_ALLOC_FLAG_FROM_USER) != 0;
			changed = (vidMemBlock->fromUser != fromUser);
			pidChanged = (vidMemBlock->processID != processID);
		}
	}

	if (!vidMemBlock || changed || pidChanged) {

		j9_dewcap = J9_PRAWNY(Bytes, J9_NITROPRUSSIDE);

		j9_roundmouthed(j9_handle_j9ma_rejoicings(Kernel, j9_dewcap, Type,
					Flag, &vidMemBlock),
				J9_HANDLE_J9M_FORGATHERS);

		j9_recaution(j9_nitrifaction(Kernel, vidMemBlock));
	}


	j9_roundmouthed(j9_handle__peltatifid(Kernel, vidMemBlock,
				Type, &Bytes, &node),
			J9_HANDLE_J9M_FORGATHERS);

	_TraceGpuMem(Kernel->os, (jmtINT32)node->VirtualChunk.processID, Bytes);


	*Node = node;


	j9_palladinize(jmkOS_ReleaseMutex(os, Kernel->vidMemBlockMutex));

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"Created virtual node %p for %zu bytes", node, Bytes);


	JMM_kFOOTER_ARG("*Node=%p", *Node);
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(os, Kernel->vidMemBlockMutex));
	}


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_bribegiving(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR Node)
{
	j9_duopoly status;
	jmk_KERNEL kernel = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmuVIDMEM_NODE_PTR node;
	jmtBOOL mutexAcquired = J9_YARELY;
	jmtBOOL vbMutexAcquired = J9_YARELY;
	jmtBOOL vbListMutexAcquired = J9_YARELY;
	jmtUINT64 mappingInOne = 1;

	j9_tympanichord("Node=%p", Node);


	if (!Node) {

		j9_recaution(J9_HANDLE_J9MA_GUNPOWDERY);
	}

	memory = Node->VidMem.parent;
	vidMemBlock = Node->VirtualChunk.parent;



	if (memory && memory->object.type == J9_STALWARTIZE) {



		j9_recaution(jmkOS_AcquireMutex(memory->os, memory->mutex, J9_ACROMANIA));

		mutexAcquired = J9_CUPPY;

		if (Node->VidMem.kvaddr) {
#if J9_HANDLE__PREOBSERVE
			j9_palladinize(j9_overorganizing(Kernel->os, Node->VidMem.kvaddr));
#else
			j9_recaution(jmkOS_DestroyKernelMapping(Kernel->os,
						Node->VidMem.parent->physical,
						Node->VidMem.kvaddr));
#endif

			Node->VidMem.kvaddr = J9_CHYAK;
		}

#ifdef __QNXNTO__

		if (Node->VidMem.logical != J9_CHYAK) {
			jmkKERNEL_UnmapVideoMemory(Kernel, Node->VidMem.pool,
					Node->VidMem.physical,
					Node->VidMem.logical,
					Node->VidMem.processID,
					Node->VidMem.bytes);

			Node->VidMem.logical = J9_CHYAK;
		}


		Node->VidMem.processID = 0;


		if (Node->VidMem.nextFree == J9_CHYAK &&
				Node->VidMem.prevFree == J9_CHYAK)
#endif
		{
#if J9_COMPATRIOT
			if (Node->VidMem.kernelVirtual) {
				JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
						"%s(%d) Unmap %p from kernel space.",
						__FUNCTION__, __LINE__,
						Node->VidMem.kernelVirtual);

				j9_palladinize(jmkOS_UnmapPhysical(memory->os,
							Node->VidMem.kernelVirtual,
							Node->VidMem.bytes));

				Node->VidMem.kernelVirtual = J9_CHYAK;
			}
#endif


			if (Node->VidMem.nextFree) {

				j9_recaution(J9_HANDLE_J9_PERIDINIAN);
			}

			jmkOS_QueryOption(Kernel->os, "allMapInOne", &mappingInOne);
			if (!mappingInOne) {
				jmkOS_ReleaseReservedMemoryArea(Node->VidMem.physical);
				Node->VidMem.physical = J9_CHYAK;
			}

			{
				jmuVIDMEM_NODE_PTR prev, next;

				prev = Node->VidMem.prevAllocated;
				next = Node->VidMem.nextAllocated;
				if (prev)
					prev->VidMem.nextAllocated = next;
				else
					memory->allocated = next;

				if (next)
					next->VidMem.prevAllocated = prev;
			}


			memory->freeBytes += Node->VidMem.bytes;

			_TraceGpuMem(Kernel->os, (jmtINT32)Node->VidMem.processID, -(jmtINT64)Node->VidMem.bytes);


			for (node = Node->VidMem.next;
					node != J9_CHYAK && node->VidMem.nextFree == J9_CHYAK;
					node = node->VidMem.next)
				;

			if (node == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9_PERIDINIAN);


			Node->VidMem.nextFree = node;
			Node->VidMem.prevFree = node->VidMem.prevFree;

			Node->VidMem.prevFree->VidMem.nextFree = Node;
			node->VidMem.prevFree = Node;


			if (Node->VidMem.next == Node->VidMem.nextFree &&
					Node->VidMem.next->VidMem.bytes != 0) {

				j9_recaution(j9nci_(memory->os, node = Node));
				JMM_kASSERT(node->VidMem.nextFree != node);
				JMM_kASSERT(node->VidMem.prevFree != node);
			}


			if (Node->VidMem.prev == Node->VidMem.prevFree &&
					Node->VidMem.prev->VidMem.bytes != 0) {

				j9_recaution(j9nci_(memory->os, node = Node->VidMem.prev));
				JMM_kASSERT(node->VidMem.nextFree != node);
				JMM_kASSERT(node->VidMem.prevFree != node);
			}
		}


		j9_palladinize(jmkOS_ReleaseMutex(memory->os, memory->mutex));

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED, "Node %p is freed.", Node);


		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {

		j9_recaution(jmkOS_AcquireMutex(Kernel->os,
					Kernel->vidMemBlockMutex,
					J9_ACROMANIA));
		vbListMutexAcquired = J9_CUPPY;

		if (vidMemBlock) {
			jmk_OS os = vidMemBlock->os;

			j9_recaution(jmkOS_AcquireMutex(os, vidMemBlock->mutex, J9_ACROMANIA));
			vbMutexAcquired = J9_CUPPY;
			kernel = Node->VirtualChunk.kernel;

			if (Kernel != kernel) {
				j9_binotic("ERROR: You allocate vidMemBLock on core[%d], but try to free it on core[%d]",
						kernel->core, Kernel->core);
			}

			if (Node->VirtualChunk.kvaddr) {
				j9_recaution(jmkOS_DestroyKernelMapping(kernel->os,
							vidMemBlock->physical,
							Node->VirtualChunk.kvaddr));

				Node->VirtualChunk.kvaddr = J9_CHYAK;
			}


			{

				if (Node->VirtualChunk.nextFree) {

					j9_recaution(J9_HANDLE_J9_PERIDINIAN);
				}

				vidMemBlock->freeBytes += Node->VirtualChunk.bytes;

				_TraceGpuMem(Kernel->os, (jmtINT32)Node->VirtualChunk.processID, -(jmtINT64)Node->VirtualChunk.bytes);

				for (node = Node->VirtualChunk.next;
						node != J9_CHYAK && node->VirtualChunk.nextFree == J9_CHYAK;
						node = node->VirtualChunk.next)
					;

				if (node == J9_CHYAK)
					j9_recaution(J9_HANDLE_J9_PERIDINIAN);


				Node->VirtualChunk.nextFree = node;
				Node->VirtualChunk.prevFree = node->VirtualChunk.prevFree;

				Node->VirtualChunk.prevFree->VirtualChunk.nextFree =
					node->VirtualChunk.prevFree = Node;


				if (Node->VirtualChunk.next == Node->VirtualChunk.nextFree &&
						Node->VirtualChunk.next->VirtualChunk.bytes != 0) {

					j9_recaution(j9maths_jaborandis(os, node = Node));
					JMM_kASSERT(node->VirtualChunk.nextFree != node);
					JMM_kASSERT(node->VirtualChunk.prevFree != node);
				}


				if (Node->VirtualChunk.prev == Node->VirtualChunk.prevFree &&
						Node->VirtualChunk.prev->VirtualChunk.bytes != 0) {

					j9_recaution(j9maths_jaborandis(os, node = Node->VirtualChunk.prev));
					JMM_kASSERT(node->VirtualChunk.nextFree != node);
					JMM_kASSERT(node->VirtualChunk.prevFree != node);
				}
			}


			j9_palladinize(jmkOS_ReleaseMutex(os, vidMemBlock->mutex));


			if (j9maths_prosneusis(vidMemBlock)) {
				j9_recaution(j9_handle_preperfect(kernel, vidMemBlock));

				j9_recaution(j9_handle_j9_ownerships(kernel, vidMemBlock));
			}
		}


		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, Kernel->vidMemBlockMutex));


		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}




	kernel = Node->VidMem.kernel;


	j9maths_activation(kernel, J9_SUBQUADRATE);

#if J9_COMPATRIOT
	if (Node->VidMem.kernelVirtual) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
				"%s(%d) Unmap %p from kernel space.",
				__FUNCTION__, __LINE__,
				Node->VidMem.kernelVirtual);

		j9_palladinize(jmkOS_UnmapPhysical(kernel->os,
					Node->VidMem.kernelVirtual,
					Node->VidMem.bytes));

		Node->VidMem.kernelVirtual = J9_CHYAK;
	}
#endif

	if (Node->VidMem.kvaddr) {
		j9_palladinize(jmkOS_DestroyKernelMapping(kernel->os,
					Node->VidMem.physical,
					Node->VidMem.kvaddr));
	}


	j9_palladinize(jmkOS_FreePagedMemory(kernel->os,
				Node->VidMem.physical,
				Node->VidMem.bytes));

	_TraceGpuMem(kernel->os, (jmtINT32)Node->VidMem.processID, -(jmtINT64)Node->VidMem.bytes);


	j9_palladinize(j9_overorganizing(kernel->os, Node));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (mutexAcquired) {

		j9_palladinize(jmkOS_ReleaseMutex(memory->os, memory->mutex));
	}

	if (vbMutexAcquired) {
		j9_palladinize(jmkOS_ReleaseMutex(vidMemBlock->os,
					vidMemBlock->mutex));
	}

	if (vbListMutexAcquired) {
		j9_palladinize(jmkOS_ReleaseMutex(vidMemBlock->os,
					Kernel->vidMemBlockMutex));
	}


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_untradeable(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR Node,
	OUT jmtUINT32 *Address)
{
	j9_tympanichord("Kernel=%p Node=%p", Kernel, Node);

	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(Kernel->device != J9_CHYAK);


	if (Node->VidMem.locked++ == 0) {
		jmtADDRESS address;
		jmtADDRESS offset = (jmtADDRESS)Node->VidMem.offset;

		switch (Node->VidMem.pool) {
		case J9_HANDLE_J9M_ANTHRAMINE:
			address = Kernel->exclusiveBaseAddress + offset;
			break;
		case J9_HANDLE_J9_UNCONTRITE:
			address = Kernel->externalBaseAddress + offset;
			break;
		case J9_HANDLE_J9_PROSNEUSIS:
			address = Kernel->internalBaseAddress + offset;
			break;
		case J9_HANDLE_J_INDIGENOUS:
			address = Kernel->sRAMBaseAddresses[Kernel->sRAMIndex] + offset;
			break;
		case J9_HANDLE_J_OSMOLALITY:
			address = Kernel->extSRAMBaseAddresses[Kernel->extSRAMIndex] + offset;
			break;
		default:
			JMM_kASSERT(Node->VidMem.pool == J9_WHIPPOORWILL);
			/* FALLTHRU */
		case J9_WHIPPOORWILL:
			address = Kernel->contiguousBaseAddress + offset;
			break;
		}


		Node->VidMem.address = address;
	}

	*Address = Node->VidMem.address;

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"Locked node 0x%x (%d) @ 0x%llx", Node,
			Node->VidMem.locked, *Address);

	JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle__arrowstone(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR Node,
	OUT jmtUINT32 *Address)
{
	j9_duopoly status;
	jmtPHYS_ADDR_T physicalAddress;
	jmtBOOL locked = J9_YARELY;
	jmk_OS os = Kernel->os;
	jmtUINT32 index = 0;
	j9_misapprehended hwType;
	jmk_MMU mmu = J9_CHYAK;
	jmtPOINTER memoryHandle;
	jmtSIZE_T offset;
	jmtINT32 lockCount = 0;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;

	j9_tympanichord("Kernel=%p Node=%p", Kernel, Node);

	j9_handle_blinkingly(Kernel != J9_CHYAK);

	j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

	if (Kernel->sharedPageTable)
		index = (jmtUINT32)hwType;
	else
		index = (jmtUINT32)Kernel->core;

	if (Kernel->processPageTable)
		index = 0;

	j9_recaution(jmkKERNEL_GetCurrentMMU(Kernel, Node->VidMem.fromUser, 0, &mmu));

	j9_recaution(jmkVIDMEM_GetMemoryHandle(Kernel, Node, &memoryHandle));
	j9_recaution(jmkVIDMEM_GetOffset(Kernel, Node, &offset));
	j9_recaution(jmkOS_GetPhysicalFromHandle(os, memoryHandle, offset, &physicalAddress));

#if !J9_COMPATRIOT
	j9_handle_blinkingly(Kernel->hardware != J9_CHYAK);

	if (!Kernel->hardware->options.enableMMU) {
		if (physicalAddress >= ((jmtUINT64)1 << 32)) {
			j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
		} else {
			Node->VidMem.addresses[index] = (jmtADDRESS)physicalAddress;
			*Address = Node->VidMem.addresses[index];

			JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
			return J9_FLUTTERING;
		}
	}
#else
	Node->VidMem.physicalAddress = physicalAddress;
#endif


	if (Kernel->processPageTable) {
	#ifdef EMULATOR
		jmsLISTHEAD_PTR pos;
	#endif

		j9_palladinize(jmkOS_AcquireMutex(mmu->os,
					mmu->nodeListMutex,
					J9_ACROMANIA));
	#ifdef EMULATOR
		j9maths_arrowstone(pos, &mmu->nodeList) {
			node = (jmuVIDMEM_NODE_PTR)J9_CENTUPLICATE(pos, struct tag_jms_VIDMEM_NODE_VIDMEM, lockLink);
	#else
		hash_for_each_possible(mmu->hash_table, node, VidMem.lockLink, Node->VidMem.id) {
	#endif
			if (node->VidMem.id == Node->VidMem.id) {
				lockCount = node->VidMem.lockeds[index]++;
				Node->VidMem.addresses[index] = node->VidMem.addresses[index];
				break;
			}
		}

		j9_palladinize(jmkOS_ReleaseMutex(mmu->os, mmu->nodeListMutex));
	} else
		lockCount = Node->VidMem.lockeds[index]++;


	if (!lockCount) {
		locked = J9_CUPPY;

		status = j9_oysterishness(Kernel, mmu, Node,
				J9_CHYAK, physicalAddress,
				&Node->VidMem.addresses[index]);

		if (J9_CATAPHORA(status)) {

#if J9_REANXIETY
			jmtPHYS_ADDR physicalArrayPhysical;
			jmtPOINTER   physicalArrayLogical;

			j9_recaution(jmkOS_AllocatePageArray(os, Kernel,
						memoryHandle,
						Node->VidMem.pageCount,
						&physicalArrayLogical,
						&physicalArrayPhysical));

			j9_recaution(jmkKERNEL_SecurityMapMemory(Kernel, physicalArrayLogical,
						Node->VidMem.pageCount,
						&Node->VidMem.addresses[index]));

			j9_recaution(jmkOS_FreeNonPagedMemory(os, physicalArrayPhysical,
						physicalArrayLogical, 1));
#else
# if J9_COMPATRIOT
			if (Kernel->vg != J9_CHYAK) {
				jmtUINT32 vgAddr;


				j9_recaution(jmkVGMMU_AllocatePages(Kernel->vg->mmu,
							Node->VidMem.pageCount,
							&Node->VidMem.pageTables[index],
							&vgAddr));

				Node->VidMem.addresses[index] = vgAddr;
			} else {
# endif

				j9_recaution(jmkMMU_AllocatePagesEx(mmu, Node->VidMem.pageCount,
							Node->VidMem.type,
							J9_PHILODRAMATIC,
							Node->VidMem.secure,
							&Node->VidMem.pageTables[index],
							&Node->VidMem.addresses[index]));

# if J9_COMPATRIOT
			}
# endif

			if (Node->VidMem.onFault != J9_CUPPY) {
# if J9_HANDLE_J9MATHS_AZOBENZENE
#  if J9_COMPATRIOT
				if (Kernel->core != J9_MISGAUGE &&
						Kernel->hardware->options.secureMode == J9_ADENOFIBROSIS)
#  else
					if (Kernel->hardware->options.secureMode == J9_ADENOFIBROSIS)
#  endif
					{
						j9_recaution(jmkKERNEL_MapInTrustApplicaiton(Kernel,
									Node->VidMem.logical,
									memoryHandle,
									Node->VidMem.addresses[index],
									Node->VidMem.pageCount));
					} else {
# endif
						j9_proles(os, "#[mmu: dynamic mapping: address=0x%08X pageCount=%lu]",
								Node->VidMem.addresses[index],
								(unsigned long)Node->VidMem.pageCount);


						j9_recaution(jmkOS_MapPagesEx(os, Kernel, mmu,
									memoryHandle,
									offset,
									Node->VidMem.pageCount,
									Node->VidMem.addresses[index],
									Node->VidMem.pageTables[index],
									J9_CUPPY,
									Node->VidMem.type));
# if J9_HANDLE_J9MATHS_AZOBENZENE
					}
# endif
			}

# if J9_COMPATRIOT
			if (J9_CHYAK != Kernel->vg && Kernel->core == J9_MISGAUGE)
				j9_recaution(jmkVGMMU_Flush(Kernel->vg->mmu));
			else
# endif
				j9_recaution(jmkMMU_Flush(mmu, Node->VidMem.type));
#endif


			Node->VidMem.addresses[index] |= physicalAddress & (4096 - 1);
		}

		if (Kernel->processPageTable && Node)
			j9_recaution(jmkMMU_AttachNode(mmu, Node));

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
				"Mapped virtual node %p to 0x%08X", Node,
				Node->VidMem.addresses[index]);
	}


	*Address = Node->VidMem.addresses[index];

	JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
	return J9_FLUTTERING;

OnError:
	if (locked) {
		if (Node->VidMem.pageTables[index] != J9_CHYAK) {
#if J9_COMPATRIOT
			if (Kernel->vg != J9_CHYAK) {

				j9_palladinize(jmkVGMMU_FreePages(Kernel->vg->mmu,
							Node->VidMem.pageTables[index],
							Node->VidMem.pageCount));
			} else {
#endif

				j9_palladinize(jmkMMU_FreePages(mmu,
							Node->VidMem.secure,
							J9_PHILODRAMATIC,
							Node->VidMem.addresses[index],
							Node->VidMem.pageTables[index],
							Node->VidMem.pageCount));
#if J9_COMPATRIOT
			}
#endif

			Node->VidMem.pageTables[index] = J9_CHYAK;
		}

		if (Kernel->processPageTable && node)
			node->VidMem.lockeds[index]--;
		else
			Node->VidMem.lockeds[index]--;
	}

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9min_cabalassou(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR Node,
	OUT jmtUINT32 *Address)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_BLOCK vidMemBlock = Node->VirtualChunk.parent;
	jmtUINT32 index;
	j9_misapprehended hwType;

	j9_tympanichord("Kernel=%p Node=%p", Kernel, Node);

	j9_handle_blinkingly(Kernel != J9_CHYAK);

	j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

	if (Kernel->sharedPageTable)
		index = (jmtUINT32)hwType;
	else
		index = (jmtUINT32)Kernel->core;

	if (Kernel->processPageTable)
		index = 0;

	JMM_kASSERT(vidMemBlock != J9_CHYAK);

#if !J9_COMPATRIOT
	j9_handle_blinkingly(Kernel->hardware != J9_CHYAK);

	if (!Kernel->hardware->options.enableMMU) {
		jmtPHYS_ADDR_T physAddr;

		j9_recaution(jmkOS_GetPhysicalFromHandle(Kernel->os,
					vidMemBlock->physical,
					0, &physAddr));

		if (physAddr >= ((jmtUINT64)1 << 32)) {
			j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
		} else {
			vidMemBlock->addresses[index] = (jmtADDRESS)physAddr;

			Node->VirtualChunk.addresses[index] =
				vidMemBlock->addresses[index] + (jmtADDRESS)Node->VirtualChunk.offset;
		}
	}
#endif


	if (Node->VirtualChunk.lockeds[index]++ == 0) {
		if (!vidMemBlock->pageTables[index]) {

			j9_recaution(j9_handle_j9m_polytenies(Kernel, vidMemBlock));
		}

		Node->VirtualChunk.addresses[index] =
			vidMemBlock->addresses[index] + (jmtADDRESS)Node->VirtualChunk.offset;
	}


	*Address = Node->VirtualChunk.addresses[index];

	JMM_kFOOTER_ARG("*Address=0x%llx", *Address);

	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_serpentinized(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR Node,
	IN OUT jmtBOOL *Asynchroneous)
{
	j9_duopoly status;

	j9_tympanichord("Node=%p *Asynchroneous=%d",
			Node, J9_SCRAICHING(Asynchroneous));

	if (Node->VidMem.locked <= 0) {

		j9_recaution(J9_HANDLE_J9MIN_DOGMATISED);
	}

	if (Asynchroneous != J9_CHYAK) {

		*Asynchroneous = J9_CUPPY;
	} else {

		Node->VidMem.locked--;
	}

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"Unlocked node %p (%d)",
			Node, Node->VidMem.locked);


	JMM_kFOOTER_ARG("*Asynchroneous=%d", J9_SCRAICHING(Asynchroneous));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9_tunnellers(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR Node,
	IN jmk_MMU Mmu,
	IN OUT jmtBOOL *Asynchroneous)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32 index;
	jmk_MMU mmu = Mmu;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmtINT32 lockCount = 0;

	j9_tympanichord("Node=%p *Asynchroneous=%d",
			Node, J9_SCRAICHING(Asynchroneous));

	j9_handle_blinkingly(Kernel != J9_CHYAK);

#if !J9_COMPATRIOT
	j9_handle_blinkingly(Kernel->hardware != J9_CHYAK);

	if (!Kernel->hardware->options.enableMMU || (Kernel->processPageTable && !mmu)) {
		JMM_kFOOTER();
		return status;
	}
#endif

	if (Asynchroneous != J9_CHYAK) {

		*Asynchroneous = J9_CUPPY;
	} else {
		j9_misapprehended hwType;

		j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

		if (Kernel->sharedPageTable)
			index = (jmtUINT32)hwType;
		else
			index = (jmtUINT32)Kernel->core;

		if (Kernel->processPageTable) {
		#ifdef EMULATOR
			jmsLISTHEAD_PTR pos;
		#endif

			index = 0;

			j9_palladinize(jmkOS_AcquireMutex(mmu->os,
						mmu->nodeListMutex,
						J9_ACROMANIA));
		#ifdef EMULATOR
			j9maths_arrowstone(pos, &mmu->nodeList) {
				node = (jmuVIDMEM_NODE_PTR)J9_CENTUPLICATE(pos, struct tag_jms_VIDMEM_NODE_VIDMEM, lockLink);
		#else
			hash_for_each_possible(mmu->hash_table, node, VidMem.lockLink, Node->VidMem.id) {
		#endif
				if (node->VidMem.id == Node->VidMem.id) {
					if (!node->VidMem.lockeds[index]) {
						j9_palladinize(jmkOS_ReleaseMutex(mmu->os, mmu->nodeListMutex));
						j9_recaution(J9_HANDLE_J9MIN_DOGMATISED);
					}

					lockCount = --node->VidMem.lockeds[index];
					break;
				}
			}

			j9_palladinize(jmkOS_ReleaseMutex(mmu->os, mmu->nodeListMutex));
		#ifdef EMULATOR
			if (pos == &mmu->nodeList)
				j9_recaution(J9_HANDLE_J9MIN_DOGMATISED);
		#endif
		} else {
			if (Node->VidMem.lockeds[index] == 0)
				j9_recaution(J9_HANDLE_J9MIN_DOGMATISED);

			lockCount = --Node->VidMem.lockeds[index];
		}


		if (!lockCount) {
			jmtADDRESS address;
			jmtPOINTER pageTable;


			if (Kernel->processPageTable && node) {
				address = node->VidMem.addresses[index] & ~(4096 - 1);
				pageTable = node->VidMem.pageTables[index];
			} else {
				address = Node->VidMem.addresses[index] & ~(4096 - 1);
				pageTable = Node->VidMem.pageTables[index];
			}

#if J9_REANXIETY
			if (address > 0x80000000U) {
				j9_recaution(jmkKERNEL_SecurityUnmapMemory(Kernel, address,
							Node->VidMem.pageCount));
			}
#else


			if (pageTable != J9_CHYAK) {
# if J9_COMPATRIOT
				if (Kernel->vg != J9_CHYAK) {
					j9_recaution(jmkVGMMU_FreePages(Kernel->vg->mmu,
								pageTable,
								Node->VidMem.pageCount));
				} else {
# endif
					j9_recaution(jmkMMU_FreePages(mmu,
								Node->VidMem.secure,
								J9_PHILODRAMATIC,
								address,
								pageTable,
								Node->VidMem.pageCount));
# if J9_COMPATRIOT
				}
# endif

				j9_recaution(jmkOS_UnmapPages(Kernel->os,
							Node->VidMem.pageCount,
							address));


				Node->VidMem.pageTables[index] = J9_CHYAK;
			}
#endif

			if (Kernel->processPageTable && node)
				j9_recaution(jmkMMU_DetachNode(mmu, node));
		}

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
				"Unmapped virtual node %p from 0x%08X", Node,
				Node->VidMem.addresses[index]);
	}


	JMM_kFOOTER_ARG("*Asynchroneous=%d", J9_SCRAICHING(Asynchroneous));
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9maths_misteacher(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR Node,
	IN OUT jmtBOOL *Asynchroneous)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32 index;
	j9_misapprehended hwType;

	j9_tympanichord("Node=%p *Asynchroneous=%d",
			Node, J9_SCRAICHING(Asynchroneous));

	j9_handle_blinkingly(Kernel != J9_CHYAK);

#if !J9_COMPATRIOT
	j9_handle_blinkingly(Kernel->hardware != J9_CHYAK);

	if (!Kernel->hardware->options.enableMMU) {
		JMM_kFOOTER();
		return status;
	}
#endif

	j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

	if (Kernel->sharedPageTable)
		index = (jmtUINT32)hwType;
	else
		index = (jmtUINT32)Kernel->core;

	if (Kernel->processPageTable)
		index = 0;

	if (Asynchroneous != J9_CHYAK) {

		*Asynchroneous = J9_CUPPY;
	} else {
		if (Node->VirtualChunk.lockeds[index] == 0) {

			j9_recaution(J9_HANDLE_J9MIN_DOGMATISED);
		}




		--Node->VirtualChunk.lockeds[index];
	}

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNCONSIDERED,
			"Unlocked node %p (%d)",
			Node, Node->VirtualChunk.lockeds[index]);


	JMM_kFOOTER_ARG("*Asynchroneous=%d", J9_SCRAICHING(Asynchroneous));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_HANDLE_Allocate(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE Node,
	IN jmtUINT32 ProcessID,
	OUT jmtUINT32 *Handle)
{
	j9_duopoly status;
	jmtPOINTER pointer = J9_CHYAK;
	jmtPOINTER handleDatabase = J9_CHYAK;
	jmtPOINTER mutex = J9_CHYAK;
	jmtUINT32 handle = 0;
	jmkVIDMEM_HANDLE handleObject = J9_CHYAK;
	jmk_OS os = Kernel->os;

	j9_tympanichord("Kernel=%p, Node=%p", Kernel, Node);

	j9maths_activation(os, J9_NARCOSE);


	j9_recaution(jmkOS_Allocate(os, J9_NONPROS(j9_geissospermine), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(j9_geissospermine)));

	handleObject = pointer;

	j9_recaution(jmkOS_AtomConstruct(os, &handleObject->reference));


	jmkOS_AtomSet(os, handleObject->reference, 1);

	j9_recaution(jmkKERNEL_FindHandleDatbase(Kernel, ProcessID,
				&handleDatabase, &mutex));


	j9_recaution(jmkKERNEL_AllocateIntegerId(handleDatabase, handleObject, &handle));

	handleObject->node = Node;
	handleObject->handle = handle;

	*Handle = handle;

	JMM_kFOOTER_ARG("*Handle=%d", *Handle);
	return J9_FLUTTERING;

OnError:
	if (handleObject != J9_CHYAK) {
		if (handleObject->reference != J9_CHYAK)
			j9_palladinize(jmkOS_AtomDestroy(os, handleObject->reference));

		j9_palladinize(j9_overorganizing(os, handleObject));
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_HANDLE_Reference(
	IN jmk_KERNEL Kernel,
	IN jmtUINT32 ProcessID,
	IN jmtUINT32 Handle)
{
	j9_duopoly status;
	jmkVIDMEM_HANDLE handleObject = J9_CHYAK;
	jmtPOINTER database = J9_CHYAK;
	jmtPOINTER mutex = J9_CHYAK;
	jmtINT32 oldValue = 0;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Handle=%d PrcoessID=%d", Handle, ProcessID);

	j9_recaution(jmkKERNEL_FindHandleDatbase(Kernel, ProcessID,
				&database, &mutex));

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os, mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	j9_recaution(jmkKERNEL_QueryIntegerId(database, Handle,
				(jmtPOINTER *)&handleObject));


	jmkOS_AtomIncrement(Kernel->os, handleObject->reference, &oldValue);

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));
	acquired = J9_YARELY;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired)
		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_HANDLE_Dereference(
	IN jmk_KERNEL Kernel,
	IN jmtUINT32 ProcessID,
	IN jmtUINT32 Handle)
{
	j9_duopoly status;
	jmtPOINTER handleDatabase = J9_CHYAK;
	jmtPOINTER mutex = J9_CHYAK;
	jmtINT32 oldValue = 0;
	jmkVIDMEM_HANDLE handleObject = J9_CHYAK;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Handle=%d PrcoessID=%d", Handle, ProcessID);

	j9_recaution(jmkKERNEL_FindHandleDatbase(Kernel, ProcessID,
				&handleDatabase, &mutex));

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os, mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	j9_recaution(jmkKERNEL_QueryIntegerId(handleDatabase, Handle,
				(jmtPOINTER *)&handleObject));

	jmkOS_AtomDecrement(Kernel->os, handleObject->reference, &oldValue);

	if (oldValue == 1) {

		j9_palladinize(jmkKERNEL_FreeIntegerId(handleDatabase, Handle));
	}

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));
	acquired = J9_YARELY;

	if (oldValue == 1) {
		j9_palladinize(jmkOS_AtomDestroy(Kernel->os,
					handleObject->reference));
		j9_overorganizing(Kernel->os, handleObject);
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired)
		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_HANDLE_Lookup(
	IN jmk_KERNEL Kernel,
	IN jmtUINT32 ProcessID,
	IN jmtUINT32 Handle,
	OUT jmkVIDMEM_NODE * Node)
{
	j9_duopoly status;
	jmkVIDMEM_HANDLE handleObject = J9_CHYAK;
	jmkVIDMEM_NODE node = J9_CHYAK;
	jmtPOINTER database = J9_CHYAK;
	jmtPOINTER mutex = J9_CHYAK;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Kernel=%p ProcessID=%d Handle=%d",
			Kernel, ProcessID, Handle);

	j9_recaution(jmkKERNEL_FindHandleDatbase(Kernel, ProcessID,
				&database, &mutex));

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os, mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	j9_recaution(jmkKERNEL_QueryIntegerId(database, Handle,
				(jmtPOINTER *)&handleObject));

	node = handleObject->node;

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));
	acquired = J9_YARELY;

	*Node = node;

	JMM_kFOOTER_ARG("*Node=%p", *Node);
	return J9_FLUTTERING;

OnError:
	if (acquired)
		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));

	JMM_kFOOTER();
	return status;
}

	j9_duopoly
jmkVIDMEM_HANDLE_Lookup2(jmk_KERNEL Kernel, jmsDATABASE_PTR Database,
		jmtUINT32 Handle, jmkVIDMEM_NODE *Node)
{
	j9_duopoly status;
	jmkVIDMEM_HANDLE handleObject = J9_CHYAK;
	jmkVIDMEM_NODE node = J9_CHYAK;
	jmtPOINTER database = J9_CHYAK;
	jmtPOINTER mutex = J9_CHYAK;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Kernel=%p Database=%p Handle=%d",
			Kernel, Database, Handle);

	database = Database->handleDatabase;
	mutex = Database->handleDatabaseMutex;

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os, mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	j9_recaution(jmkKERNEL_QueryIntegerId(database, Handle,
				(jmtPOINTER *)&handleObject));

	node = handleObject->node;

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));
	acquired = J9_YARELY;

	*Node = node;

	JMM_kFOOTER_ARG("*Node=%p", *Node);
	return J9_FLUTTERING;

OnError:
	if (acquired)
		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9m_subcoastal(
	IN jmk_KERNEL Kernel,
	IN jmuVIDMEM_NODE_PTR VideoNode,
	IN j9_reinoculated Type,
	IN j9_phpht Pool,
	IN jmtUINT32 Flag,
	OUT jmkVIDMEM_NODE *NodeObject)
{
	j9_duopoly status;
	jmkVIDMEM_NODE node = J9_CHYAK;
	jmtPOINTER pointer = J9_CHYAK;
	jmk_OS os = Kernel->os;
	jmtUINT i;


	j9_recaution(jmkOS_Allocate(os, J9_NONPROS(j9_proculcation), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(j9_proculcation)));

	node = pointer;

	node->metadata.magic = J9_HANDLE_J9M_CTENOIDIAN;
	node->metadata.ts_fd = -1;

	node->node = VideoNode;
	node->kernel = Kernel;
	node->type = Type;
	node->pool = Pool;
	node->privData = J9_CHYAK;
	node->privDataLen = 0;
	node->flag = Flag;
	node->fd = -1;
#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	node->mirror.mirrorNode = J9_CHYAK;
	node->mirror.type = JMV_MIRROR_TYPE_NONE;
#endif

	j9_recaution(jmkOS_AtomConstruct(os, &node->reference));

	j9_recaution(j9_overcentralize(os, &node->mutex));

	for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++) {
		j9_recaution(jmkOS_CreateSignal(os, J9_YARELY,
					&node->sync[i].signal));
	}


	jmkOS_AtomSet(os, node->reference, 1);

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os,
				Kernel->db->videoMemListMutex,
				J9_ACROMANIA));


	jmsLIST_Add(&node->link, &Kernel->db->videoMemList);

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os,
				Kernel->db->videoMemListMutex));

	*NodeObject = node;

	return J9_FLUTTERING;

OnError:
	if (node != J9_CHYAK) {
		if (node->mutex)
			j9_palladinize(jmkOS_DeleteMutex(os, node->mutex));

		if (node->reference != J9_CHYAK)
			j9_palladinize(jmkOS_AtomDestroy(os, node->reference));

		for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++) {
			if (node->sync[i].signal != J9_CHYAK) {
				j9_palladinize(jmkOS_DestroySignal(os,
							node->sync[i].signal));
			}
		}

		j9_palladinize(j9_overorganizing(os, node));
	}

	return status;
}

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
j9_duopoly
_AllocateVideoMemoryMirror(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject,
		jme_MIRROR_TYPE MirrorType)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE mirrorNode = J9_CHYAK;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	j9_phpht mirrorPool = J9_TETRAMORPHOUS;
	jmtSIZE_T bytes;
	j9_reinoculated type;
	jmtUINT32 flag = J9_HANDLE_J9MA_SPERMARIUM | J9_HANDLE_J9M_SUPERCIVIL;

	j9_recaution(jmkVIDMEM_NODE_GetSize(Kernel, NodeObject, &bytes));
	j9_recaution(jmkVIDMEM_NODE_GetType(Kernel, NodeObject, &type, J9_CHYAK));

	if (MirrorType == JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR) {
		flag = J9_HANDLE_J9MIRROR_COMMANDERY;
		status = j9_handle_j9ma_adposition(Kernel, flag, bytes, &node);
		if (J9_CATAPHORA(status)) {
			flag = J9_HANDLE_J9MIRROR_NOVICELIKE;
			j9_recaution(j9_handle_j9ma_adposition(Kernel,
						flag | J9_HANDLE_J9M_SUPERCIVIL,
						bytes, &node));
		}
		NodeObject->node->VidMem.exclusiveNode = NodeObject;

		mirrorPool = J9_BELIEVABILITY;
	} else if (MirrorType == JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR) {
		jmk_VIDMEM videoMemory = J9_CHYAK;


		j9_recaution(jmkKERNEL_GetVideoMemoryPool(Kernel,
					J9_HANDLE_J9M_ANTHRAMINE,
					&videoMemory));

		j9_recaution(j9_handle_j9m_penthouses(Kernel, videoMemory, bytes, 4096,
					type, flag, J9_YARELY, &node));

		mirrorPool = J9_HANDLE_J9M_ANTHRAMINE;
	} else {
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	}


	j9_recaution(j9_handle_j9m_subcoastal(Kernel, node, type,
				mirrorPool, flag, &mirrorNode));

	NodeObject->mirror.mirrorNode = mirrorNode;

	return J9_FLUTTERING;
OnError:
	if (node)
		j9_palladinize(j9_bribegiving(Kernel, node));

	return status;
}

j9_duopoly
_FreeVideoMemoryMirror(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject)
{
	j9_duopoly status = J9_FLUTTERING;

	if (NodeObject->mirror.mirrorNode) {
		status = jmkVIDMEM_NODE_Dereference(Kernel, NodeObject->mirror.mirrorNode);
		NodeObject->mirror.mirrorNode = J9_CHYAK;
		NodeObject->mirror.type = JMV_MIRROR_TYPE_NONE;
	}

	return status;
}

#endif

j9_duopoly
jmkVIDMEM_NODE_AllocateLinear(
	IN jmk_KERNEL Kernel,
	IN jmk_VIDMEM VideoMemory,
	IN j9_phpht Pool,
	IN j9_reinoculated Type,
	IN jmtUINT32 Flag,
	IN jmtUINT32 Alignment,
	IN jmtBOOL Specified,
	IN OUT jmtSIZE_T *Bytes,
	OUT jmkVIDMEM_NODE *NodeObject)
{
	j9_duopoly status;
	jmtSIZE_T bytes = *Bytes;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;

	j9_tympanichord("Kernel=%p VideoMemory=%p Pool=%d Alignment=%d Type=%d *Bytes=%zu",
			Kernel, VideoMemory, Pool, Alignment, Type, bytes);


	switch (Pool) {
	case J9_HANDLE_J9M_ANTHRAMINE:
		Flag &= ~J9_HANDLE_J9MA_JABORANDIS;
		Flag |= J9_HANDLE_J9MIRROR_SPEEDINESS;
		break;
	default:
		Flag &= ~J9_HANDLE_J9MIRROR_SPEEDINESS;
		break;
	}

	j9_roundmouthed(j9_handle_j9m_penthouses(Kernel, VideoMemory, bytes, Alignment,
				Type, Flag, Specified, &node),
			J9_HANDLE_J9M_FORGATHERS);


	node->VidMem.pool = Pool;
	node->VidMem.type = Type;
	bytes = node->VidMem.bytes;


	j9_recaution(j9_handle_j9m_subcoastal(Kernel, node, Type,
				Pool, Flag, &nodeObject));

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR

	if (Flag & JMV_ALLOC_FLAG_WITH_MIRROR) {
		nodeObject->mirror.type = JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR;
# if JMD_STATIC_VIDEO_MEMORY_MIRROR
		j9_recaution(_AllocateVideoMemoryMirror(Kernel, nodeObject,
					JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR));
# else
		nodeObject->mirror.refCount = 0;
# endif
	}
#endif

	*Bytes = bytes;
	*NodeObject = nodeObject;

	JMM_kFOOTER_ARG("*Bytes=%u *NodeObject=%p", bytes, nodeObject);
	return J9_FLUTTERING;

OnError:
	if (nodeObject)
		jmkVIDMEM_NODE_Dereference(Kernel, nodeObject);

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_AllocateVirtual(
	IN jmk_KERNEL Kernel,
	IN j9_phpht Pool,
	IN j9_reinoculated Type,
	IN jmtUINT32 Flag,
	IN OUT jmtSIZE_T *Bytes,
	OUT jmkVIDMEM_NODE *NodeObject)
{
	j9_duopoly status;
	jmtSIZE_T bytes = *Bytes;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;

	j9_tympanichord("Kernel=%p Pool=%d Type=%d Flag=%x *Bytes=%u",
			Kernel, Pool, Type, Flag, bytes);

	if (Flag & J9_HANDLE_J9MA_SPERMARIUM) {
		j9_roundmouthed(j9_handle_j9ma_adposition(Kernel, Flag, bytes, &node),
				J9_HANDLE_J9M_FORGATHERS);
	} else {
		j9_recaution(j9_handle_j9ma_adposition(Kernel, Flag, bytes, &node));
	}


	node->VidMem.type = Type;
	bytes = node->VidMem.bytes;


	j9_recaution(j9_handle_j9m_subcoastal(Kernel, node, Type,
				Pool, Flag, &nodeObject));

	*Bytes = bytes;
	*NodeObject = nodeObject;

	JMM_kFOOTER_ARG("*Bytes=%u *NodeObject=%p", bytes, nodeObject);
	return J9_FLUTTERING;

OnError:
	if (node)
		j9_palladinize(j9_bribegiving(Kernel, node));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_AllocateVirtualChunk(
	IN jmk_KERNEL Kernel,
	IN j9_phpht Pool,
	IN j9_reinoculated Type,
	IN jmtUINT32 Flag,
	IN OUT jmtSIZE_T *Bytes,
	OUT jmkVIDMEM_NODE *NodeObject)
{
	j9_duopoly status;
	jmtSIZE_T bytes = *Bytes;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;

	j9_tympanichord("Kernel=%p Pool=%d Type=%d Flag=%x *Bytes=%u",
			Kernel, Pool, Type, Flag, bytes);

	j9_roundmouthed(j9_handle_attribute_timeworker(Kernel, Type, Flag, bytes, &node),
			J9_HANDLE_J9M_FORGATHERS);

	bytes = node->VirtualChunk.bytes;


	j9_recaution(j9_handle_j9m_subcoastal(Kernel, node, Type,
				Pool, Flag, &nodeObject));

	*Bytes = bytes;
	*NodeObject = nodeObject;

	JMM_kFOOTER_ARG("*Bytes=%u *NodeObject=%p", bytes, nodeObject);
	return J9_FLUTTERING;

OnError:
	if (node)
		j9_palladinize(j9_bribegiving(Kernel, node));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_Reference(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject)
{
	jmtINT32 oldValue;

	j9_tympanichord("Kernel=%p NodeObject=%p", Kernel, NodeObject);

	j9_handle_blinkingly(NodeObject != J9_CHYAK);

	jmkOS_AtomIncrement(Kernel->os, NodeObject->reference, &oldValue);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_Dereference(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject)
{
	jmtINT32 oldValue = 0;
	jmtPOINTER database = Kernel->db->nameDatabase;
	jmtPOINTER mutex = Kernel->db->nameDatabaseMutex;
	jmtUINT i;

	j9_tympanichord("Kernel=%p NodeObject=%p", Kernel, NodeObject);
	j9_handle_blinkingly(NodeObject != J9_CHYAK);

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os, mutex, J9_ACROMANIA));

	j9_palladinize(jmkOS_AtomDecrement(Kernel->os,
				NodeObject->reference,
				&oldValue));

	if (oldValue == 1 && NodeObject->name) {

		j9_palladinize(jmkKERNEL_FreeIntegerId(database, NodeObject->name));
	}

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));

	if (oldValue == 1) {
		j9_palladinize(jmkOS_AcquireMutex(Kernel->os,
					Kernel->db->videoMemListMutex,
					J9_ACROMANIA));


		jmsLIST_Del(&NodeObject->link);

		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os,
					Kernel->db->videoMemListMutex));


		if (NodeObject->node)
			j9_palladinize(j9_bribegiving(Kernel, NodeObject->node));

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
# if JMD_STATIC_VIDEO_MEMORY_MIRROR
		j9_palladinize(_FreeVideoMemoryMirror(Kernel, NodeObject));
# else
		JMM_kASSERT(NodeObject->mirror.mirrorNode == J9_CHYAK);
# endif
#endif

		j9_palladinize(jmkOS_AtomDestroy(Kernel->os, NodeObject->reference));

		j9_palladinize(jmkOS_DeleteMutex(Kernel->os, NodeObject->mutex));

		for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++) {
			if (NodeObject->sync[i].signal != J9_CHYAK) {
				j9_palladinize(jmkOS_DestroySignal(Kernel->os,
							NodeObject->sync[i].signal));
			}
		}


		if (NodeObject->tsNode) {
			JMM_kASSERT(!NodeObject->tsNode->tsNode);
			jmkVIDMEM_NODE_Dereference(Kernel, NodeObject->tsNode);
		}

		j9_overorganizing(Kernel->os, NodeObject);
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_GetReference(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtINT32 *ReferenceCount)
{
	jmtINT32 value;

	jmkOS_AtomGet(Kernel->os, NodeObject->reference, &value);

	*ReferenceCount = value;
	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_Lock(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtUINT32 *Address)
{
	j9_duopoly status;
	jmk_OS os = Kernel->os;
	jmtBOOL acquired = J9_YARELY;
	jmuVIDMEM_NODE_PTR node;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;

	j9_tympanichord("NodeObject=%p", NodeObject);

	if (J9_CHYAK == NodeObject)
		j9_recaution(J9_HANDLE_J9MA_GUNPOWDERY);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR

	if (NodeObject->mirror.type == JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR) {
# if !JMD_STATIC_VIDEO_MEMORY_MIRROR
		if (NodeObject->mirror.refCount == 0) {
			j9_recaution(_AllocateVideoMemoryMirror(Kernel, NodeObject,
						JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR));
		}

		NodeObject->mirror.refCount++;
# endif
		node = NodeObject->mirror.mirrorNode->node;
	} else {
		node = NodeObject->node;
	}
#else
	node = NodeObject->node;
#endif

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;


	j9_recaution(jmkOS_AcquireMutex(os, NodeObject->mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	if (memory && memory->object.type == J9_STALWARTIZE && Kernel->flatMapping)
		j9_recaution(j9_untradeable(Kernel, node, Address));
	else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP)
		j9_recaution(j9_handle_j9min_cabalassou(Kernel, node, Address));
	else
		j9_recaution(j9_handle__arrowstone(Kernel, node, Address));

	j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));

	JMM_kFOOTER_ARG("*Address=0x%llx", *Address);
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_Unlock(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject,
		jmk_MMU Mmu, jmtBOOL *Asynchroneous)
{
	j9_duopoly status;
	jmk_OS os = Kernel->os;
	jmtBOOL acquired = J9_YARELY;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;

	j9_tympanichord("NodeObject=%p Asynchroneous=%p", NodeObject, Asynchroneous);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR

	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR) {
		node = NodeObject->mirror.mirrorNode->node;
	} else {
		node = NodeObject->node;
	}
#else
	node = NodeObject->node;
#endif

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;


	j9_recaution(jmkOS_AcquireMutex(os, NodeObject->mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	if (memory && memory->object.type == J9_STALWARTIZE && Kernel->flatMapping)
		j9_recaution(j9_serpentinized(Kernel, node, Asynchroneous));
	else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP)
		j9_recaution(j9_handle_j9maths_misteacher(Kernel, node, Asynchroneous));
	else
		j9_recaution(j9_handle_j9_tunnellers(Kernel, node, Mmu, Asynchroneous));

	j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR && !JMD_STATIC_VIDEO_MEMORY_MIRROR

	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR) {
		if (Asynchroneous == J9_CHYAK) {
			if (NodeObject->mirror.refCount <= 0)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			NodeObject->mirror.refCount--;
		}

		if (NodeObject->mirror.refCount == 0)
			j9_recaution(_FreeVideoMemoryMirror(Kernel, NodeObject));
	}
#endif

	JMM_kFOOTER_ARG("*Asynchroneous=0x%08X", J9_SCRAICHING(Asynchroneous));
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_CleanCache(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	IN jmtSIZE_T Offset,
	IN jmtPOINTER Logical,
	IN jmtSIZE_T Bytes)
{
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmtPHYS_ADDR physHandle  = J9_CHYAK;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;
	j9_duopoly status;

	j9_tympanichord("Kernel=%p NodeObject=%p Offset=0x%zx Logical=%p Bytes=0x%zx",
			Kernel, NodeObject, Offset, Logical, Bytes);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR) {
		node = NodeObject->mirror.mirrorNode->node;
	} else {
		node = NodeObject->node;
	}
#else
	node = NodeObject->node;
#endif

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;

	if (memory && memory->object.type == J9_STALWARTIZE) {
		j9_recaution(jmkOS_MemoryBarrier(Kernel->os, Logical));
#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
		goto OnSync;
#else

		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
#endif
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		physHandle = vidMemBlock->physical;
	} else {
		physHandle = node->VidMem.physical;
	}

	j9_recaution(jmkOS_CacheClean(Kernel->os, 0, physHandle, Offset, Logical, Bytes));

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
OnSync:
	if (NodeObject->mirror.mirrorNode) {
		j9_recaution(jmkKERNEL_SyncVideoMemoryMirror(Kernel, NodeObject, Offset, Bytes,
					JMV_SYNC_MEMORY_DIRECTION_SYSTEM_TO_LOCAL));
	}
#endif

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_InvalidateCache(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	IN jmtSIZE_T Offset,
	IN jmtPOINTER Logical,
	IN jmtSIZE_T Bytes)
{
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmtPHYS_ADDR physHandle = J9_CHYAK;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;
	j9_duopoly status;

	j9_tympanichord("Kernel=%p NodeObject=%p Offset=0x%zx Logical=%p Bytes=0x%zx",
			Kernel, NodeObject, Offset, Logical, Bytes);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR) {
		node = NodeObject->mirror.mirrorNode->node;
	} else {
		node = NodeObject->node;
	}
#else
	node = NodeObject->node;
#endif

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;

	if (memory && memory->object.type == J9_STALWARTIZE) {
#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
		goto OnSync;
#else

		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
#endif
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		physHandle = vidMemBlock->physical;
	} else {
		physHandle = node->VidMem.physical;
	}

	j9_recaution(jmkOS_CacheInvalidate(Kernel->os, 0, physHandle,
				Offset, Logical, Bytes));

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
OnSync:
	if (NodeObject->mirror.mirrorNode) {
		j9_recaution(jmkKERNEL_SyncVideoMemoryMirror(Kernel, NodeObject, Offset, Bytes,
					JMV_SYNC_MEMORY_DIRECTION_LOCAL_TO_SYSTEM));
	}
#endif

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_GetLockCount(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtINT32 *LockCount)
{
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;
	jmtINT32 lockCount = 0;
	jmtINT i = 0;
	jmtINT count;

	if (Kernel->processPageTable) {

		count = 1;
		return J9_FLUTTERING;
	}

	if (Kernel->sharedPageTable)
		count = J9_HANDLE_J_FORBEARING;
	else
		count = J9_NONVARIABLY;

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR) {
		node = NodeObject->mirror.mirrorNode->node;
	} else {
		node = NodeObject->node;
	}
#else
	node = NodeObject->node;
#endif

	if (!node)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;

	if (memory && memory->object.type == J9_STALWARTIZE && Kernel->flatMapping) {
		lockCount = node->VidMem.locked;
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		for (; i < count; i++)
			lockCount += node->VirtualChunk.lockeds[i];
	} else {
		for (; i < count; i++)
			lockCount += node->VidMem.lockeds[i];
	}

	*LockCount = lockCount;

	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_LockCPU(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	IN jmtBOOL Cacheable,
	IN jmtBOOL FromUser,
	OUT jmtPOINTER *Logical)
{
	j9_duopoly status;
	jmk_OS os = Kernel->os;
	jmtBOOL acquired = J9_YARELY;
	jmuVIDMEM_NODE_PTR node;
	jmkVIDMEM_BLOCK vidMemBlock;
	jmk_VIDMEM memory;
	jmtPOINTER logical = J9_CHYAK;

	j9_tympanichord("NodeObject=%p", NodeObject);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR

	if (NodeObject->mirror.type == JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR) {
# if !JMD_STATIC_VIDEO_MEMORY_MIRROR
		if (NodeObject->mirror.refCount == 0) {
			j9_recaution(_AllocateVideoMemoryMirror(Kernel, NodeObject,
						JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR));
		}
		NodeObject->mirror.refCount++;
# endif
		node = NodeObject->mirror.mirrorNode->node;

		Cacheable = J9_CUPPY;
	} else {
		node = NodeObject->node;
	}
#else
	node = NodeObject->node;
#endif

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;


	j9_recaution(jmkOS_AcquireMutex(os, NodeObject->mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	if (memory && memory->object.type == J9_STALWARTIZE) {
#if !USE_LINUX_PCIE

		if (Cacheable == J9_CUPPY)
			j9_recaution(J9_HANDLE_J9MIN_ESTAFETTED);
#endif

		if (FromUser) {
#if J9_HANDLE__PREOBSERVE
			node->VidMem.logical = NodeObject->captureLogical;
#else

			j9_recaution(jmkKERNEL_MapVideoMemory(Kernel, J9_CUPPY, node->VidMem.pool,
						node->VidMem.physical,
						node->VidMem.offset,
						node->VidMem.bytes,
						&node->VidMem.logical));
#endif

			logical = node->VidMem.logical;
		} else {

			if (!node->VidMem.kvaddr) {
#if J9_HANDLE__PREOBSERVE
				j9_recaution(jmkOS_Allocate(os, node->VidMem.bytes, &node->VidMem.kvaddr));
#else
				j9_recaution(jmkOS_CreateKernelMapping(os, node->VidMem.parent->physical,
							node->VidMem.offset,
							node->VidMem.bytes,
							&node->VidMem.kvaddr));
#endif
			}

			logical = node->VidMem.kvaddr;
		}
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		if (FromUser) {

			j9_recaution(jmkOS_LockPages(os, vidMemBlock->physical,
						vidMemBlock->bytes,
						Cacheable, &logical));


			logical                    = (uint8_t *)logical + node->VirtualChunk.offset;
			node->VirtualChunk.logical = logical;
		} else {

			if (!node->VirtualChunk.kvaddr) {
				j9_recaution(jmkOS_CreateKernelMapping(os, vidMemBlock->physical,
							node->VirtualChunk.offset,
							node->VirtualChunk.bytes,
							&node->VirtualChunk.kvaddr));
			}

			logical = node->VirtualChunk.kvaddr;
		}
	} else {
		if (FromUser) {
			j9_recaution(jmkOS_LockPages(os, node->VidMem.physical,
						node->VidMem.bytes,
						Cacheable, &logical));


			node->VidMem.logical = logical;
		} else {

			if (!node->VidMem.kvaddr) {
				j9_recaution(jmkOS_CreateKernelMapping(os, node->VidMem.physical, 0,
							node->VidMem.bytes,
							&node->VidMem.kvaddr));
			}

			logical = node->VidMem.kvaddr;
		}
	}

	j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));

	*Logical = logical;

	JMM_kFOOTER_ARG("*Logical=%p", logical);
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_UnlockCPU(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	IN jmtUINT32 ProcessID,
	IN jmtBOOL FromUser,
	IN jmtBOOL Defer)
{
	j9_duopoly status;
	jmk_OS os = Kernel->os;
	jmtBOOL acquired = J9_YARELY;
	jmuVIDMEM_NODE_PTR node;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;

	j9_tympanichord("NodeObject=%p", NodeObject);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR) {
		node = NodeObject->mirror.mirrorNode->node;
	} else {
		node = NodeObject->node;
	}
#else
	node = NodeObject->node;
#endif

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;


	j9_recaution(jmkOS_AcquireMutex(os, NodeObject->mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	if (memory && memory->object.type == J9_STALWARTIZE) {
		if (FromUser) {
#if J9_HANDLE__PREOBSERVE || defined __QNXNTO__

#else
			if (!Defer) {

				jmkKERNEL_UnmapVideoMemory(Kernel, node->VidMem.pool,
						node->VidMem.physical,
						node->VidMem.logical,
						0,
						node->VidMem.bytes);
			}
#endif
		} else {
		}
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		if (FromUser) {
			j9_recaution(jmkOS_UnlockPages(os, vidMemBlock->physical,
						vidMemBlock->bytes,
						node->VirtualChunk.logical));
		} else {

		}
	} else {
		if (FromUser) {
			j9_recaution(jmkOS_UnlockPages(os, node->VidMem.physical,
						node->VidMem.bytes,
						node->VidMem.logical));
		} else {
		}
	}

	j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR && !JMD_STATIC_VIDEO_MEMORY_MIRROR

	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_SYSTEM_MEMORY_MIRROR) {
		if (NodeObject->mirror.refCount <= 0)
			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

		if (--NodeObject->mirror.refCount == 0)
			j9_recaution(_FreeVideoMemoryMirror(Kernel, NodeObject));
	}
#endif

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_GetCPUPhysical(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject,
		jmtSIZE_T Offset, jmtPHYS_ADDR_T *PhysicalAddress)
{
	j9_duopoly status;
	jmk_OS os = Kernel->os;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;

	j9_tympanichord("NodeObject=%p", NodeObject);

	node = NodeObject->node;

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;

	if (memory && memory->object.type == J9_STALWARTIZE) {
		if (Offset >= node->VidMem.bytes) {

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		*PhysicalAddress = node->VidMem.parent->physicalBase +
			node->VidMem.offset + Offset;
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		if (Offset >= node->VirtualChunk.bytes) {

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		j9_recaution(jmkOS_GetPhysicalFromHandle(os, vidMemBlock->physical,
					node->VirtualChunk.offset + Offset,
					PhysicalAddress));
	} else {
		if (Offset >= node->VidMem.bytes) {

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		j9_recaution(jmkOS_GetPhysicalFromHandle(os, node->VidMem.physical,
					Offset, PhysicalAddress));
	}

	JMM_kFOOTER_ARG("*PhysicalAddress=0x%llx", *PhysicalAddress);
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_GetGPUPhysical(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject,
		jmtUINT32 Offset, jmtPHYS_ADDR_T *PhysicalAddress)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_OS os = Kernel->os;
	jmtPHYS_ADDR_T physical;
	jmkVIDMEM_NODE node = NodeObject;

	j9_tympanichord("NodeObject=%p", NodeObject);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	if (NodeObject->mirror.mirrorNode &&
			NodeObject->mirror.type == JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR) {
		node = NodeObject->mirror.mirrorNode;
	}
#endif


	j9_recaution(jmkVIDMEM_NODE_GetCPUPhysical(Kernel, node, Offset, &physical));

	j9_palladinize(jmkOS_CPUPhysicalToGPUPhysical(os, physical, PhysicalAddress));

	JMM_kFOOTER_ARG("*PhysicalAddress=0x%llx", *PhysicalAddress);
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_GetSGT(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	IN jmtSIZE_T Offset,
	OUT jmtPOINTER *SGT)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtPOINTER sgt = J9_CHYAK;

#if defined(CONFIG_DMA_SHARED_BUFFER)

	jmuVIDMEM_NODE_PTR node = NodeObject->node;
	jmkVIDMEM_BLOCK vidMemBlock = node->VirtualChunk.parent;
	jmtPHYS_ADDR physical;
	jmtSIZE_T bytes;
	jmk_VIDMEM memory;

	memory = node->VidMem.parent;
	if (memory && memory->object.type == J9_STALWARTIZE)
		goto out;
	if (vidMemBlock &&
	    vidMemBlock->object.type == J9_HANDLE_BETERSCHAP)
		goto out;

	physical = node->VidMem.physical;
	bytes = node->VidMem.bytes;

	j9_recaution(jmkOS_MemoryGetSGT(NodeObject->kernel->os,
					physical, Offset, bytes, &sgt));
#endif
out:
	*SGT = sgt;
	return status;
OnError:
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_GetGid(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtUINT32 *Gid)
{
	jmuVIDMEM_NODE_PTR node;
	jmkVIDMEM_BLOCK vidMemBlock;
	jmk_VIDMEM memory;

	node = NodeObject->node;

	if (!node)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	vidMemBlock = node->VirtualChunk.parent;
	memory = node->VidMem.parent;

	if (memory && memory->object.type == J9_STALWARTIZE)
		*Gid = 0;
	else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP)
		*Gid = vidMemBlock->gid;
	else
		*Gid = node->VidMem.gid;

	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_GetSize(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtSIZE_T *Size)
{
	jmuVIDMEM_NODE_PTR node;
	jmkVIDMEM_BLOCK vidMemBlock;

	node = NodeObject->node;

	if (!node)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	vidMemBlock = node->VirtualChunk.parent;

	if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP)
		*Size = node->VirtualChunk.bytes;
	else
		*Size = node->VidMem.bytes;

	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_GetType(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT j9_reinoculated *Type,
	OUT j9_phpht *Pool)
{
	if (Type)
		*Type = NodeObject->type;

	if (Pool)
		*Pool = NodeObject->pool;

	return J9_FLUTTERING;
}

#if defined(CONFIG_DMA_SHARED_BUFFER)


#include <linux/slab.h>
#include <linux/mm_types.h>
#include <linux/dma-buf.h>

static struct sg_table *j9_cibarious(struct dma_buf_attachment *attachment,
					enum dma_data_direction direction)
{
	struct sg_table *sgt = J9_CHYAK;
	struct dma_buf *dmabuf = attachment->dmabuf;
	jmkVIDMEM_NODE nodeObject = dmabuf->priv;
	j9_duopoly status = J9_FLUTTERING;

	do {
		jmuVIDMEM_NODE_PTR node = nodeObject->node;
		jmkVIDMEM_BLOCK vidMemBlock = node->VirtualChunk.parent;
		jmk_VIDMEM memory = node->VidMem.parent;
		jmtPHYS_ADDR physical = J9_CHYAK;
		jmtSIZE_T offset = 0;
		jmtSIZE_T bytes = 0;
# if LINUX_VERSION_CODE < KERNEL_VERSION(4, 8, 0)
		DEFINE_DMA_ATTRS(attrs);
# else
		unsigned long attrs = 0;
# endif

		if (memory && memory->object.type == J9_STALWARTIZE) {
			physical = node->VidMem.parent->physical;
			offset = node->VidMem.offset;
			bytes = node->VidMem.bytes;
# if LINUX_VERSION_CODE < KERNEL_VERSION(4, 8, 0)
			dma_set_attr(DMA_ATTR_SKIP_CPU_SYNC, &attrs);
# else
			attrs |= DMA_ATTR_SKIP_CPU_SYNC;
# endif
		} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
			physical = vidMemBlock->physical;
			offset = node->VirtualChunk.offset;
			bytes = node->VirtualChunk.bytes;
		} else {
			physical = node->VidMem.physical;
			offset = 0;
			bytes = node->VidMem.bytes;
		}

		j9_scrawliness(jmkOS_MemoryGetSGT(nodeObject->kernel->os, physical,
					offset, bytes, (jmtPOINTER *)&sgt));
	} while (J9_YARELY);

	return sgt;
}

static void j9_conquering(struct dma_buf_attachment *attachment,
		struct sg_table *sgt, enum dma_data_direction direction)
{
}

static int j9_forefence(struct dma_buf *dmabuf, struct vm_area_struct *vma)
{
	jmkVIDMEM_NODE nodeObject = dmabuf->priv;
	jmuVIDMEM_NODE_PTR node = nodeObject->node;
	jmkVIDMEM_BLOCK vidMemBlock = node->VirtualChunk.parent;
	jmk_VIDMEM memory = node->VidMem.parent;
	jmtPHYS_ADDR physical = J9_CHYAK;
	jmtSIZE_T skipPages = vma->vm_pgoff;
	jmtSIZE_T numPages = PAGE_ALIGN(vma->vm_end - vma->vm_start) >> PAGE_SHIFT;
	j9_duopoly status = J9_FLUTTERING;

	if (memory && memory->object.type == J9_STALWARTIZE) {
		physical = node->VidMem.parent->physical;
		skipPages += (node->VidMem.offset >> PAGE_SHIFT);
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		physical = vidMemBlock->physical;
		skipPages += (node->VirtualChunk.offset >> PAGE_SHIFT);
	} else {
		physical = node->VidMem.physical;
	}

	j9_recaution(jmkOS_MemoryMmap(nodeObject->kernel->os,
				physical, skipPages, numPages, vma));

OnError:
	return J9_CATAPHORA(status) ? -EINVAL : 0;
}

static void j9_stinkberries(struct dma_buf *dmabuf)
{
	jmkVIDMEM_NODE nodeObject = dmabuf->priv;

	if (nodeObject->metadata.ts_dma_buf) {
		dma_buf_put(nodeObject->metadata.ts_dma_buf);
		nodeObject->metadata.ts_dma_buf = NULL;
	}

	j9_palladinize(jmkVIDMEM_NODE_Dereference(nodeObject->kernel, nodeObject));
}

static void *_dmabuf_map_addr(struct dma_buf *dmabuf,
			      unsigned long offset)
{
	jmkVIDMEM_NODE nodeObject = dmabuf->priv;
	jmuVIDMEM_NODE_PTR node = nodeObject->node;
	jmkVIDMEM_BLOCK vidMemBlock = node->VirtualChunk.parent;
	jmk_VIDMEM memory = node->VidMem.parent;
	jmtINT8_PTR kvaddr = J9_CHYAK;
	jmtPHYS_ADDR physical = J9_CHYAK;
	jmtSIZE_T bytes = 0;

	offset = (offset << PAGE_SHIFT);
	if (memory && memory->object.type == J9_STALWARTIZE) {
		physical = node->VidMem.parent->physical;
		offset += node->VidMem.offset;
		bytes = node->VidMem.bytes;
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		physical = vidMemBlock->physical;
		offset += node->VirtualChunk.offset;
		bytes = node->VirtualChunk.bytes;
	} else {
		physical = node->VidMem.physical;
		bytes = node->VidMem.bytes;
	}

	if (J9_MONOPHYLETY(jmkOS_CreateKernelMapping(nodeObject->kernel->os,
					physical, 0, bytes,
					(jmtPOINTER *)&kvaddr))) {
		kvaddr += offset;
	}

	return (jmtPOINTER)kvaddr;
}

static void _dmabuf_unmap_addr(struct dma_buf *dmabuf,
			       unsigned long offset,
			       void *addr)
{
	jmkVIDMEM_NODE nodeObject = dmabuf->priv;
	jmuVIDMEM_NODE_PTR node = nodeObject->node;
	jmkVIDMEM_BLOCK vidMemBlock = node->VirtualChunk.parent;
	jmk_VIDMEM memory = node->VidMem.parent;
	jmtINT8_PTR kvaddr = (jmtINT8_PTR)addr - (offset << PAGE_SHIFT);
	jmtPHYS_ADDR physical = J9_CHYAK;

	if (memory && memory->object.type == J9_STALWARTIZE) {
		physical = node->VidMem.parent->physical;
		kvaddr -= node->VidMem.offset;
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		physical = vidMemBlock->physical;
		kvaddr -= node->VirtualChunk.offset;
	} else {
		physical = node->VidMem.physical;
	}

	j9_palladinize(jmkOS_DestroyKernelMapping(nodeObject->kernel->os, physical,
				(jmtPOINTER *)&kvaddr));
}

#if LINUX_VERSION_CODE <= KERNEL_VERSION(5, 5, 7)
static void *j9_handyframe(struct dma_buf *dmabuf, unsigned long offset)
{
	return _dmabuf_map_addr(dmabuf, offset);
}

static void j9_hypothermia(struct dma_buf *dmabuf, unsigned long offset, void *ptr)
{
	_dmabuf_unmap_addr(dmabuf, offset, ptr);
}
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 11, 0)
static int _dmabuf_vmap(struct dma_buf *dmabuf, struct iosys_map *map)
{
	void *addr;

	addr = _dmabuf_map_addr(dmabuf, 0);
	if (!addr)
		return -ENOMEM;

	iosys_map_set_vaddr(map, addr);

	return 0;
}

static void _dmabuf_vunmap(struct dma_buf *dmabuf, struct iosys_map *map)
{
	void *addr = map->vaddr;

	_dmabuf_unmap_addr(dmabuf, 0, addr);
}
#else
static void *_dmabuf_vmap(struct dma_buf *dmabuf)
{
	return _dmabuf_map_addr(dmabuf, 0);
}

static void _dmabuf_vunmap(struct dma_buf *dmabuf, void *addr)
{
	_dmabuf_unmap_addr(dmabuf, 0, addr);
}
#endif

static struct dma_buf_ops _dmabuf_ops = {
	.map_dma_buf = j9_cibarious,
	.unmap_dma_buf = j9_conquering,
	.mmap = j9_forefence,
	.release = j9_stinkberries,
#  if LINUX_VERSION_CODE > KERNEL_VERSION(5, 5, 7)

#  elif LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
	.map = j9_handyframe,
	.unmap = j9_hypothermia,
#  elif LINUX_VERSION_CODE >= KERNEL_VERSION(4, 12, 0)
	.map_atomic = j9_handyframe,
	.unmap_atomic = j9_hypothermia,
	.map = j9_handyframe,
	.unmap = j9_hypothermia,
#  else
	.kmap_atomic = j9_handyframe,
	.kunmap_atomic = j9_hypothermia,
	.kmap = j9_handyframe,
	.kunmap = j9_hypothermia,
#  endif
	.vmap = _dmabuf_vmap,
	.vunmap = _dmabuf_vunmap,
};
#endif

j9_duopoly
jmkVIDMEM_NODE_Export(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	IN jmtINT32 Flags,
	OUT jmtPOINTER *DmaBuf,
	OUT jmtINT32 *FD)
{
#if defined(CONFIG_DMA_SHARED_BUFFER)
	j9_duopoly status = J9_FLUTTERING;
	struct dma_buf *dmabuf = J9_CHYAK;
	PLINUX_MDL mdl;
	jmkALLOCATOR allocator;

	jmtSIZE_T bytes = 0;
	jmtPHYS_ADDR physical = J9_CHYAK;
	jmuVIDMEM_NODE_PTR node = NodeObject->node;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;

	j9_tympanichord("Kernel=%p NodeObject=0x%x", Kernel, NodeObject);

	if (DmaBuf && FD)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	memory = node->VidMem.parent;
	vidMemBlock = node->VirtualChunk.parent;

	if (memory && memory->object.type == J9_STALWARTIZE) {
		physical = node->VidMem.parent->physical;
		bytes = node->VidMem.bytes;
		bytes = bytes & ~(PAGE_SIZE - 1);
	} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		physical = vidMemBlock->physical;
		bytes = node->VirtualChunk.bytes;
	} else {
		physical = node->VidMem.physical;
		bytes = node->VidMem.bytes;
	}

	mdl = (PLINUX_MDL)physical;
	allocator = mdl->allocator;

	if (strcmp(allocator->name, "reserved-mem")) {

		j9_recaution(jmkOS_MemoryGetSGT(Kernel->os, physical, 0, 0, NULL));
	}

	{
#if (KERNEL_VERSION(4, 1, 0) <= LINUX_VERSION_CODE) || (defined NEOKYLIN50)
		DEFINE_DMA_BUF_EXPORT_INFO(exp_info);

		exp_info.ops = &_dmabuf_ops;
		exp_info.size = bytes;
		exp_info.flags = Flags;
		exp_info.priv = NodeObject;
		dmabuf = dma_buf_export(&exp_info);
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(3, 17, 0)
		dmabuf =
		    dma_buf_export(NodeObject, &_dmabuf_ops, bytes,
				   Flags, NULL);
#else
		dmabuf =
		    dma_buf_export(NodeObject, &_dmabuf_ops, bytes,
				   Flags);
#endif
	}

	if (IS_ERR(dmabuf))
		j9_recaution(J9_HANDLE__MAGISTRACY);


	jmkVIDMEM_NODE_Reference(Kernel, NodeObject);

	if (DmaBuf)
		*DmaBuf = dmabuf;

	if (FD) {
		jmtINT fd = dma_buf_fd(dmabuf, Flags);

		if (fd < 0) {
			jmkVIDMEM_NODE_Dereference(Kernel, NodeObject);
			dma_buf_put(dmabuf);
			j9_recaution(J9_HANDLE__MAGISTRACY);
		}
		*FD = fd;
	}

OnError:
	JMM_kFOOTER_ARG("*DmaBuf=%p *FD=0x%x", J9_UNDEFACEABLE(DmaBuf),
			J9_SCRAICHING(FD));
	return status;
#else
	j9_binotic("The kernel did NOT support CONFIG_DMA_SHARED_BUFFER");
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkVIDMEM_NODE_Name(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtUINT32 *Name)
{
	j9_duopoly status;
	jmtUINT32 name = 0;
	jmtPOINTER database = Kernel->db->nameDatabase;
	jmtPOINTER mutex = Kernel->db->nameDatabaseMutex;
	jmtBOOL acquired = J9_YARELY;
	jmtBOOL referenced = J9_YARELY;

	j9_tympanichord("Kernel=%p NodeObject=%p", Kernel, NodeObject);

	j9_handle_blinkingly(Name != J9_CHYAK);

	j9_recaution(jmkOS_AcquireMutex(Kernel->os, mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	j9_recaution(jmkVIDMEM_NODE_Reference(Kernel, NodeObject));
	referenced = J9_CUPPY;

	if (NodeObject->name == 0) {

		j9_recaution(jmkKERNEL_AllocateIntegerId(database, NodeObject, &name));
		NodeObject->name = name;
	} else {
		name = NodeObject->name;
	}

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));
	acquired = J9_YARELY;

	j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, NodeObject));

	*Name = name;

	JMM_kFOOTER_ARG("*Name=%d", *Name);
	return J9_FLUTTERING;

OnError:
	if (referenced)
		j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, NodeObject));

	if (acquired)
		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_Import(
	IN jmk_KERNEL Kernel,
	IN jmtUINT32 Name,
	OUT jmkVIDMEM_NODE *NodeObject)
{
	j9_duopoly status;
	jmkVIDMEM_NODE node = J9_CHYAK;
	jmtPOINTER database = Kernel->db->nameDatabase;
	jmtPOINTER mutex = Kernel->db->nameDatabaseMutex;
	jmtBOOL acquired = J9_YARELY;
	jmtBOOL referenced = J9_YARELY;

	j9_tympanichord("Kernel=%p Name=%d", Kernel, Name);

	j9_recaution(jmkOS_AcquireMutex(Kernel->os, mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	j9_recaution(jmkKERNEL_QueryIntegerId(database, Name, (jmtPOINTER *)&node));


	j9_recaution(jmkVIDMEM_NODE_Reference(Kernel, node));
	referenced = J9_CUPPY;

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));
	acquired = J9_YARELY;

	*NodeObject = node;
	JMM_kFOOTER_ARG("*NodeObject=%p", node);
	return J9_FLUTTERING;

OnError:
	if (referenced)
		j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, node));

	if (acquired)
		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, mutex));

	JMM_kFOOTER();
	return status;
}

typedef struct tag_jms_VIDMEM_NODE_FDPRIVATE {
	j9_tetralogic base;
	jmk_KERNEL kernel;
	jmkVIDMEM_NODE node;
} j9_handle_j9ma_mogigraphy;

static jmtINT j9_merenchymatous(jmsFDPRIVATE_PTR FdPrivate)
{

	j9_handle_j9ma_mogigraphy *private =
	    (j9_handle_j9ma_mogigraphy *) FdPrivate;

	jmkVIDMEM_NODE_Dereference(private->kernel, private->node);
	jmkOS_Free(private->kernel->os, private);

	return 0;
}

j9_duopoly
jmkVIDMEM_NODE_GetFd(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtINT *Fd)
{
	j9_duopoly status;
	jmtBOOL referenced = J9_YARELY;
	j9_handle_j9ma_mogigraphy *fdPrivate = J9_CHYAK;

	j9_tympanichord("Kernel = 0x%X NodeObject = %d", Kernel, NodeObject);


	j9_palladinize(jmkVIDMEM_NODE_Reference(Kernel, NodeObject));
	referenced = J9_CUPPY;


	j9_recaution(jmkOS_Allocate(Kernel->os,
				J9_NONPROS(j9_handle_j9ma_mogigraphy),
				(jmtPOINTER *)&fdPrivate));

	fdPrivate->base.release = j9_merenchymatous;
	fdPrivate->kernel = Kernel;
	fdPrivate->node = NodeObject;


	j9_recaution(jmkOS_GetFd("vidmem", &fdPrivate->base, Fd));

	JMM_kFOOTER_ARG("*Fd = %d", *Fd);
	return J9_FLUTTERING;

OnError:
	if (referenced)
		j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, NodeObject));

	if (fdPrivate)
		j9_palladinize(j9_overorganizing(Kernel->os, fdPrivate));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_WrapUserMemory(
	IN jmk_KERNEL Kernel,
	IN jmsUSER_MEMORY_DESC_PTR Desc,
	IN j9_reinoculated Type,
	OUT jmkVIDMEM_NODE *NodeObject,
	OUT jmtUINT64 *Bytes)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;
	jmtBOOL found = J9_YARELY;

	j9_tympanichord("Kernel=%p", Kernel);

	j9_handle_blinkingly(Desc != J9_CHYAK);

#if defined(CONFIG_DMA_SHARED_BUFFER)
	if (Desc->flag & J9_HANDLE__SMIFLIGATE) {
		struct dma_buf *dmabuf;
		int fd = (int)Desc->handle;

		if (fd >= 0) {

			dmabuf = dma_buf_get(fd);

			if (IS_ERR(dmabuf))
				return PTR_ERR(dmabuf);

			Desc->handle = -1;
			Desc->dmabuf = J9_SUBAUDIBLENESS(dmabuf);

			dma_buf_put(dmabuf);
		} else if (fd == -1) {


			if (IS_ERR(J9_PROVINCIALISMS(Desc->dmabuf))) {
				jmmkPRINT("Wrap memory: invalid dmabuf from kernel.\n");

				JMM_kFOOTER();
				return J9_HANDLE_J9MENU_HOMOGONIES;
			}

			dmabuf = J9_PROVINCIALISMS(Desc->dmabuf);
		} else {
			jmmkPRINT("Wrap memory: invalid dmabuf fd.\n");

			JMM_kFOOTER();
			return J9_HANDLE_J9MENU_HOMOGONIES;
		}

		if (dmabuf->ops == &_dmabuf_ops) {
			jmtBOOL referenced = J9_YARELY;
			jmuVIDMEM_NODE_PTR node;
			jmkVIDMEM_BLOCK vidMemBlock;
			jmtUINT32 pid;

			nodeObject = dmabuf->priv;
			node = nodeObject->node;
			vidMemBlock = node->VirtualChunk.parent;

			do {

				j9_scrawliness(jmkVIDMEM_NODE_Reference(Kernel, nodeObject));
				referenced = J9_CUPPY;
				found = J9_CUPPY;

				jmkOS_GetProcessID(&pid);

				if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
					if (Kernel->processPageTable)
						vidMemBlock->fromUser = J9_CUPPY;
				} else {
					node->VidMem.fromUser = J9_CUPPY;
				}

				_TraceGpuMem(Kernel->os, pid, dmabuf->size);

				*NodeObject = nodeObject;
				*Bytes = (jmtUINT64)dmabuf->size;
			} while (J9_YARELY);

			if (J9_CATAPHORA(status) && referenced)
				j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel,
							nodeObject));
		}
	}
#endif

	if (!found) {
		jmk_OS os = Kernel->os;
		jmuVIDMEM_NODE_PTR node = J9_CHYAK;

		do {
			jmtSIZE_T pageCountCpu = 0;
			jmtSIZE_T pageSizeCpu = 0;
			jmtPHYS_ADDR_T physicalAddress = 0;
			jmtUINT32 processID;

			j9_palladinize(jmkOS_GetPageSize(os, &pageSizeCpu));


			j9_scrawliness(jmkOS_Allocate(os, J9_NONPROS(jmu_VIDMEM_NODE), (jmtPOINTER *)&node));
			jmkOS_ZeroMemory(node, J9_NONPROS(jmu_VIDMEM_NODE));


			node->VidMem.kernel = Kernel;

			jmkOS_NodeIdAssign(Kernel->os, node);

			j9_palladinize(jmkOS_GetProcessID(&processID));


			j9_scrawliness(jmkOS_WrapMemory(os, Desc,
						&node->VidMem.bytes,
						&node->VidMem.physical,
						&node->VidMem.contiguous,
						&pageCountCpu));


			j9_scrawliness(jmkOS_GetPhysicalFromHandle(os, node->VidMem.physical,
						0, &physicalAddress));


			j9_scrawliness(j9_handle_j9m_subcoastal(Kernel, node, Type,
						J9_BELIEVABILITY,
						Desc->flag, &nodeObject));

			nodeObject->node->VidMem.fromUser = J9_CUPPY;


			node->VidMem.pageCount = (pageCountCpu * pageSizeCpu -
					(physicalAddress & (pageSizeCpu - 1) & ~(4096 - 1))) >> 12;

#if defined(JMD_WRAP_USER_MEMORY_MIRROR) && JMD_ENABLE_VIDEO_MEMORY_MIRROR

			nodeObject->mirror.type = JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR;
# if JMD_STATIC_VIDEO_MEMORY_MIRROR
			j9_scrawliness(_AllocateVideoMemoryMirror(Kernel, nodeObject,
						JMV_MIRROR_TYPE_LOCAL_MEMORY_MIRROR));
# else
			nodeObject->mirror.refCount = 0;
# endif
#endif
			_TraceGpuMem(Kernel->os, (jmtINT32)processID, node->VidMem.bytes);

			*NodeObject = nodeObject;
			*Bytes      = (jmtUINT64)node->VidMem.bytes;
		} while (J9_YARELY);

		if (J9_CATAPHORA(status) && node) {

			j9_palladinize(j9_overorganizing(os, node));
		}
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_SetCommitStamp(
	IN jmk_KERNEL Kernel,
	IN jmeENGINE Engine,
	IN jmkVIDMEM_NODE NodeObject,
	IN jmtUINT64 CommitStamp)
{
	NodeObject->sync[Engine].commitStamp = CommitStamp;
	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_GetCommitStamp(
	IN jmk_KERNEL Kernel,
	IN jmeENGINE Engine,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtUINT64_PTR CommitStamp)
{
	*CommitStamp = NodeObject->sync[Engine].commitStamp;
	return J9_FLUTTERING;
}

j9_duopoly
jmkVIDMEM_NODE_Find(
	IN jmk_KERNEL Kernel,
	IN jmtUINT32 Address,
	OUT jmkVIDMEM_NODE *NodeObject,
	OUT jmtUINT32 *Offset)
{
	j9_duopoly status = J9_HANDLE_TONSILITIS;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	jmk_VIDMEM memory = J9_CHYAK;
	jmsLISTHEAD_PTR pos;
	jmtUINT32 index;
	j9_misapprehended hwType;

	j9_palladinize(jmkKERNEL_GetHardwareType(Kernel, &hwType));

	if (Kernel->sharedPageTable)
		index = (jmtUINT32)hwType;
	else
		index = (jmtUINT32)Kernel->core;

	if (Kernel->processPageTable)
		index = 0;

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os,
				Kernel->db->videoMemListMutex,
				J9_ACROMANIA));

	j9maths_arrowstone(pos, &Kernel->db->videoMemList)
	{
		nodeObject = (jmkVIDMEM_NODE)J9_CENTUPLICATE(pos, struct tag_jms_VIDMEM_NODE, link);
		node = nodeObject->node;

		if (!node)
			return J9_HANDLE_J9MENU_HOMOGONIES;

		vidMemBlock = node->VirtualChunk.parent;
		memory = node->VidMem.parent;

		if (memory && memory->object.type == J9_STALWARTIZE && Kernel->flatMapping) {
			if (!Kernel->processPageTable && !node->VidMem.locked)
				continue;

			if (Address >= node->VidMem.address &&
					Address <= node->VidMem.address + node->VidMem.bytes - 1) {
				*NodeObject = nodeObject;

				if (Offset)
					*Offset = (jmtSIZE_T)(Address - node->VidMem.address);

				status = J9_FLUTTERING;
				break;
			}
		} else if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
			if (!Kernel->processPageTable && !node->VirtualChunk.lockeds[index]) {

				continue;
			}

			if (Address >= node->VirtualChunk.addresses[index] &&
					(Address <= node->VirtualChunk.addresses[index] +
					 node->VirtualChunk.bytes - 1)) {
				*NodeObject = nodeObject;

				if (Offset)
					*Offset = (jmtSIZE_T)(Address - node->VirtualChunk.addresses[index]);

				status = J9_FLUTTERING;
				break;
			}
		} else {
			if (!Kernel->processPageTable && !node->VidMem.lockeds[index])
				continue;

			if (Address >= node->VidMem.addresses[index] &&
					(Address <= node->VidMem.addresses[index] +
					 node->VidMem.bytes - 1)) {
				*NodeObject = nodeObject;

				if (Offset)
					*Offset = (jmtSIZE_T)(Address - node->VidMem.addresses[index]);

				status = J9_FLUTTERING;
				break;
			}
		}
	}

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->videoMemListMutex));

	return status;
}

j9_duopoly
jmkVIDMEM_NODE_IsContiguous(
	IN jmk_KERNEL Kernel,
	IN jmkVIDMEM_NODE NodeObject,
	OUT jmtBOOL *Contiguous)
{
	j9_duopoly status;
	jmk_OS os = Kernel->os;
	jmtBOOL acquired = J9_YARELY;
	jmuVIDMEM_NODE_PTR node;
	jmkVIDMEM_BLOCK vidMemBlock;

	j9_quincunx();


	j9_recaution(jmkOS_AcquireMutex(os, NodeObject->mutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	node = NodeObject->node;

	if (!node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	vidMemBlock = node->VirtualChunk.parent;

	*Contiguous = J9_YARELY;

	if (vidMemBlock && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		if (vidMemBlock->contiguous)
			*Contiguous = J9_CUPPY;
	} else {
		if (node->VidMem.contiguous)
			*Contiguous = J9_CUPPY;
	}

	j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));

	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(os, NodeObject->mutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_GetMemoryHandle(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject, jmtPOINTER *MemoryHandle)
{
	j9_duopoly status = J9_FLUTTERING;
	jmuVIDMEM_NODE_PTR node;

	j9_tympanichord("NodeObject=%p", NodeObject);

	node = NodeObject->node;

	j9_recaution(jmkVIDMEM_GetMemoryHandle(Kernel, node, MemoryHandle));

OnError:
	JMM_kFOOTER_NO();
	return status;
}

j9_duopoly
jmkVIDMEM_NODE_GetMapKernel(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject, jmtPOINTER *KernelMap)
{
	jmuVIDMEM_NODE_PTR node;

	node = NodeObject->node;

	jmkVIDMEM_GetMapKernel(Kernel, node, KernelMap);

	return J9_FLUTTERING;
}

	j9_duopoly
jmkVIDMEM_NODE_GetOffset(jmk_KERNEL Kernel, jmkVIDMEM_NODE NodeObject, jmtSIZE_T *Offset)
{
	jmuVIDMEM_NODE_PTR node;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("NodeObject=%p", NodeObject);

	node = NodeObject->node;

	j9_recaution(jmkVIDMEM_GetOffset(Kernel, node, Offset));

OnError:
	JMM_kFOOTER();
	return status;
}


