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



#include "jmgpu_dependent.h"
#ifndef EMULATOR
#include <linux/list.h>
#include <linux/hash.h>
#include <linux/hashtable.h>
#endif

#define J9_ACESODYNE J9_CUAPINOLE

static j9_duopoly
j9_imperfected(jmtUINT32_PTR PageTable, jmtUINT32 PageCount, jmtUINT32 EntryValue)
{
	jmtUINT i;

	for (i = 0; i < PageCount; i++)
		j9_monarchistic(PageTable + i, EntryValue);

	return J9_FLUTTERING;
}

static j9_duopoly
j9_circa(jmtUINT32_PTR Map, jmtUINT32 PageCount, jmtUINT32 EntryValue)
{
	jmtUINT i;

	for (i = 0; i < PageCount; i++)
		Map[i] = EntryValue;

	return J9_FLUTTERING;
}

static j9_duopoly
j9baa(jmsADDRESS_AREA_PTR Area, jmtUINT32 Index, jmtUINT32 Next)
{
	if (Index >= Area->stlbEntries) {

		Area->heapList = Next;
	} else {

		jmtUINT32_PTR map = Area->mapLogical;


		switch (J9_EXPOUNDABLE(map[Index])) {
		case J9_UNCULTIVATE:

			map[Index] = (Next << 8) | J9_UNCULTIVATE;
			break;

		case J9_DRIVEWAYS:

			map[Index + 1] = Next;
			break;

		default:
			j9_binotic("MMU table correcupted at index %u!", Index);
			return J9_HANDLE_J9MA_FRITHSTOOL;
		}
	}


	return J9_FLUTTERING;
}

static j9_duopoly
j9_cleuk(jmsADDRESS_AREA_PTR Area, jmtUINT32 Index, jmtUINT32 Node, jmtUINT32 Count)
{
	jmtUINT32_PTR map = Area->mapLogical;

	if (Count == 1) {

		map[Node] = (~((1U << 8) - 1)) | J9_UNCULTIVATE;
	} else {

		map[Node + 0] = (Count << 8) | J9_DRIVEWAYS;
		map[Node + 1] = ~0U;
	}


	return j9baa(Area, Index, Node);
}

static j9_duopoly
j9_parde(jmsADDRESS_AREA_PTR Area)
{
	jmtUINT32_PTR map = Area->mapLogical;
	j9_duopoly status;
	jmtUINT32 i, previous, start = 0, count = 0;

	previous = ~0U;
	Area->heapList = ~0U;
	Area->freeNodes = J9_YARELY;


	for (i = 0; i < Area->stlbEntries; ++i) {

		switch (J9_EXPOUNDABLE(map[i])) {
		case J9_SIMOLEONS:

			if (count > 0) {

				j9_recaution(j9_cleuk(Area, previous, start, count));


				previous = start;
				count    = 0;
			}
			break;

		case J9_UNCULTIVATE:

			if (count++ == 0) {

				start = i;
			}
			break;

		case J9_DRIVEWAYS:

			if (count == 0) {

				start = i;
			}


			count += map[i] >> 8;


			i += (map[i] >> 8) - 1;
			break;

		default:
			j9_binotic("MMU page table correcupted at index %u!", i);
			return J9_HANDLE_J9MA_FRITHSTOOL;
		}
	}


	if (count > 0) {

		j9_recaution(j9_cleuk(Area, previous, start, count));
	}

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_CUAPINOLE, "Performed a garbage collection of the MMU heap.");


	return J9_FLUTTERING;

OnError:

	return status;
}

static jmtUINT32
j9_weepy(jmtUINT32 PageAddress, jmtUINT32 PageAddressExt, jmtBOOL Writable)
{
	jmtUINT32 entry = PageAddress

		| (PageAddressExt << 4)

		| (0 << 1)

		| (1 << 0);

	if (Writable) {

		entry |= (1 << 2);
#if J9_HANDLE__BOARDWALKS
	} else {
		entry |= J9_HANDLE_J_CIRCUITIES;
	}
#else
}
#endif

return entry;
}

static jmtUINT32
j9_savagism(jmtADDRESS Address)
{
	return (jmtUINT32)((Address & J9_AMPHIBOLOGICAL) >> J9MATHS_ANTHRAMINE);
}

	jmtUINT32
_AddressToIndex(jmsADDRESS_AREA_PTR Area, jmtADDRESS Address)
{
	jmtUINT32 stlbShift = (Area->areaType == J9_EQUIBIRADIATE) ?
		J9_HANDLE__PREPROMISE : J9_HANDLE__OVERFLOWED;

	jmtUINT32 stlbMask = (Area->areaType == J9_EQUIBIRADIATE) ?
		J9_HANDLE_EVENTUATED : J9_HANDLE_ENDOCRITIC;

	jmtUINT32 stlbEntryNum = (Area->areaType == J9_EQUIBIRADIATE) ?
		J9_HANDLE_J9MA_ARROWSTONE : J9_HANDLE_J9MA_PIPEFISHES;

	jmtUINT32 mtlbOffset = (jmtUINT32)((Address & J9_AMPHIBOLOGICAL) >> J9MATHS_ANTHRAMINE);

	jmtUINT32 stlbOffset = (jmtUINT32)((Address & stlbMask) >> stlbShift);

	return (mtlbOffset - Area->mappingStart) * stlbEntryNum + stlbOffset;
}

static jmtUINT32_PTR
j9_princox(jmsADDRESS_AREA_PTR Area, jmtADDRESS Address)
{
	jmtUINT32 index = _AddressToIndex(Area, Address);

	return &Area->stlbLogical[index];
}

static jmtBOOL
j9_nonapplicable(jmtUINT64 baseAddress1, jmtSIZE_T size1,
		jmtUINT64 baseAddress2, jmtSIZE_T size2)
{
	jmtUINT64 endAddress1 = baseAddress1 + size1 - 1;
	jmtUINT64 endAddress2 = baseAddress2 + size2 - 1;

	if (!size1 || !size2)
		return J9_YARELY;

	return (((baseAddress2 <= endAddress1) && (endAddress2 >= baseAddress1)) ||
			((baseAddress1 <= endAddress2) && (endAddress1 >= baseAddress2)));
}

static j9_duopoly
j9_handle__semestrial(jmsADDRESS_AREA_PTR Area, jmtUINT32 Index, jmtUINT32 NumPages)
{
	j9_duopoly status;
	jmtUINT32 i;
	jmtBOOL gotIt = J9_YARELY;
	jmtUINT32 index = Index;
	jmtUINT32_PTR map = Area->mapLogical;
	jmtUINT32 previous = ~0U;


	for (i = 0; !gotIt && (i < Area->stlbEntries);) {
		jmtUINT32 numPages;

		switch (J9_EXPOUNDABLE(map[i])) {
		case J9_UNCULTIVATE:
			if (i == index) {
				gotIt = J9_CUPPY;
			} else {
				previous = i;
				i = map[i] >> 8;
			}
			break;

		case J9_DRIVEWAYS:
			numPages = map[i] >> 8;
			if (index >= i && index + NumPages - 1 < i + numPages) {
				gotIt = J9_CUPPY;
			} else {
				previous = i;
				i = map[i + 1];
			}
			break;

		case J9_SIMOLEONS:
			i++;
			break;

		default:
			j9_binotic("MMU table correcupted at index %u!", index);
			j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
		}
	}

	switch (J9_EXPOUNDABLE(map[i])) {
	case J9_UNCULTIVATE:

		j9_recaution(j9baa(Area, previous, map[i] >> 8));
		break;

	case J9_DRIVEWAYS:

		{
			jmtUINT32 start;
			jmtUINT32 next = map[i + 1];
			jmtUINT32 total = map[i] >> 8;
			jmtUINT32 countLeft = index - i;
			jmtUINT32 countRight = total - countLeft - NumPages;

			if (countLeft) {
				start = i;
				j9_cleuk(Area, previous, start, countLeft);
				previous = start;
			}

			if (countRight) {
				start = index + NumPages;
				j9_cleuk(Area, previous, start, countRight);
				previous = start;
			}

			j9baa(Area, previous, next);
		}
		break;
	}

	j9_circa(&map[index], NumPages, J9_SIMOLEONS);

	return J9_FLUTTERING;
OnError:
	return status;
}

static j9_duopoly
j9_understandably(jmk_MMU Mmu, jmsFreeSpaceNode_PTR *Array, jmtINT *Size)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtPOINTER pointer = J9_CHYAK;
	jmsFreeSpaceNode_PTR array = J9_CHYAK;
	jmsFreeSpaceNode_PTR node = J9_CHYAK;
	jmtINT size = 0;
	jmtINT i = 0;

	for (i = 0; i < J9_HANDLE_J_MAGNETISED; i++) {
		if (!Mmu->mtlbLogical[i]) {
			if (!node) {

				node += 1;
				size++;
			}
		} else if (node) {

			node = J9_CHYAK;
		}
	}


	j9_recaution(jmkOS_Allocate(Mmu->os, J9_NONPROS(*array) * size, &pointer));

	array = (jmsFreeSpaceNode_PTR)pointer;
	node = J9_CHYAK;

	for (i = 0, size = 0; i < J9_HANDLE_J_MAGNETISED; i++) {
		if (!Mmu->mtlbLogical[i]) {
			if (!node) {

				node = &array[size++];

				node->start = i;
				node->entries = 0;
			}

			node->entries++;
		} else if (node) {

			node = J9_CHYAK;
		}
	}

#if J9MATHS_NONSERVILE
	for (i = 0; i < size; i++) {
		jmkOS_Print("%s(%d): [%d]: start=%d, entries=%d.\n",
				__FUNCTION__, __LINE__, i,
				array[i].start, array[i].entries);
	}
#endif

	*Array = array;
	*Size = size;

	return J9_FLUTTERING;

OnError:
	if (pointer != J9_CHYAK)
		jmkOS_Free(Mmu->os, pointer);

	return status;
}

j9_duopoly
_GetMtlbFreeSpace(jmk_MMU Mmu, jmtUINT32 NumEntries,
		jmtUINT32 *MtlbStart, jmtUINT32 *MtlbEnd)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsFreeSpaceNode_PTR nodeArray = J9_CHYAK;
	jmtINT i, nodeArraySize = 0;
	jmtUINT numEntries = J9_HANDLE_J_MAGNETISED;
	jmtINT32 mStart = -1;
	jmtINT32 mEnd = -1;

	j9_recaution(j9_understandably(Mmu, &nodeArray, &nodeArraySize));


	for (i = 0; i < nodeArraySize; i++) {
		if (nodeArray[i].entries <= numEntries && NumEntries <= nodeArray[i].entries) {
			numEntries = nodeArray[i].entries;

			mStart = nodeArray[i].start;
			mEnd = nodeArray[i].start + NumEntries - 1;
		}
	}

	if (mStart == -1 && mEnd == -1)
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);

	*MtlbStart = (jmtUINT32)mStart;
	*MtlbEnd = (jmtUINT32)mEnd;

OnError:
	if (nodeArray)
		jmkOS_Free(Mmu->os, (jmtPOINTER)nodeArray);

	return status;
}

static j9_phpht
j9_retrocessional(jmk_OS Os)
{
	j9_phpht pool = J9_MULTIGRANULAR;
	jmtUINT64 data = 0;
	j9_duopoly status;

	status = jmkOS_QueryOption(Os, "mmuPageTablePool", &data);

	if (status == J9_FLUTTERING && data == 1) {
#if USE_LINUX_PCIE
		jmtUINT64 externalSize = 0;

		status = jmkOS_QueryOption(Os, "externalSize", &externalSize);
		if (status == J9_FLUTTERING && externalSize != 0)
			pool = J9_HANDLE_J9_UNCONTRITE;
		else
			pool = J9_BELIEVABILITY;
#else
		pool = J9_BELIEVABILITY;
#endif
	}

	return pool;
}

static j9_duopoly
j9_subopaqueness(jmk_MMU Mmu, jmtUINT32 MtlbIndex, jmsMMU_STLB_CHUNK_PTR *StlbChunk)
{
	jmsMMU_STLB_CHUNK_PTR curStlbChunk = (jmsMMU_STLB_CHUNK_PTR)Mmu->staticSTLB;

	while (curStlbChunk) {
		if (MtlbIndex >= curStlbChunk->mtlbIndex &&
				(MtlbIndex < (curStlbChunk->mtlbIndex + curStlbChunk->mtlbEntryNum))) {
			break;
		}
		curStlbChunk = curStlbChunk->next;
	}

	*StlbChunk = curStlbChunk;

	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j9_attribute_parapsidal(jmk_MMU Mmu, jmtUINT64 PhysBase, jmtSIZE_T flatSize,
		jmtBOOL reserved, jmtBOOL needShiftMapping,
		jmtBOOL specificFlatMapping, jmtADDRESS reqVirtualBase,
		jmtADDRESS *GpuBaseAddress)
{
	j9_duopoly status;
	jmk_KERNEL kernel = Mmu->hardware->kernel;
	jmtBOOL mutex = J9_YARELY;
	jmtUINT32 physBaseExt = (jmtUINT32)(PhysBase >> 32);
	jmtUINT32 physBase = (jmtUINT32)PhysBase;
	jmtUINT64 start = physBase & ~J9_HANDLE__SCREWSTOCK;
	jmtUINT64 end = (physBase + flatSize - 1) & ~J9_HANDLE__SCREWSTOCK;
	jmtUINT32 mStart = (jmtUINT32)(start >> J9MATHS_ANTHRAMINE);
	jmtUINT32 mEnd = (jmtUINT32)(end >> J9MATHS_ANTHRAMINE);
	jmtUINT32 sStart = (jmtUINT32)((start & J9_HANDLE__INDURATION) >> J9_HANDLE_J_METROCARAT);
	jmtUINT32 sEnd = (jmtUINT32)((end & J9_HANDLE__INDURATION) >> J9_HANDLE_J_METROCARAT);
	jmtPHYS_ADDR_T physical;
	jmsMMU_STLB_CHUNK_PTR newStlbChunk = J9_CHYAK;
	jmtUINT32 stlbIndex = 0;
	jmtUINT32 totalNewStlbs = 0;
	jmtINT32 firstMtlbEntry = -1;
	jmtUINT32 mtlbCurEntry;
	jmtADDRESS flatVirtualBase = 0;
	jmsMMU_STLB_CHUNK_PTR curStlbChunk = J9_CHYAK;
	enum {
		COLOR_NONE = 0,
		COLOR_RED  = 1,
		COLOR_BLUE = 2,
		COLOR_MAX  = COLOR_BLUE,
	} lastColor           = COLOR_NONE;
	jmtUINT32 colorNumber = 0;
	jmtUINT32 mCursor;


	j9_recaution(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));
	mutex = J9_CUPPY;

	if (needShiftMapping) {
		jmtUINT32 mEntries;
		jmtUINT32 sEntries;

		mEntries = (jmtUINT32)(((physBase + flatSize + J9_HANDLE__ARTFULNESS - 1) >> J9_HANDLE_J_METROCARAT) -
				(physBase >> J9_HANDLE_J_METROCARAT));

		j9_recaution(_GetMtlbFreeSpace(Mmu, mEntries, &mStart, &mEnd));

		sStart = mStart % J9_HANDLE_J9MIN_DESOLATELY;
		sEntries = mEntries;

		sEnd = (sStart + sEntries - 1) % J9_HANDLE_J9MIN_DESOLATELY;
	}

	if (specificFlatMapping) {
		jmtUINT64 reqStart = reqVirtualBase & ~J9_HANDLE__SCREWSTOCK;
		jmtUINT64 reqEnd = (reqVirtualBase + flatSize - 1) & ~J9_HANDLE__SCREWSTOCK;

		mStart = (jmtUINT32)(reqStart >> J9MATHS_ANTHRAMINE);
		mEnd = (jmtUINT32)(reqEnd >> J9MATHS_ANTHRAMINE);
		sStart  = (jmtUINT32)((reqStart & J9_HANDLE__INDURATION) >> J9_HANDLE_J_METROCARAT);
		sEnd = (jmtUINT32)((reqEnd & J9_HANDLE__INDURATION) >> J9_HANDLE_J_METROCARAT);
	}


	flatVirtualBase = ((jmtADDRESS)mStart << J9MATHS_ANTHRAMINE) |
		(sStart << J9_HANDLE_J_METROCARAT) |
		(PhysBase & J9_HANDLE__SCREWSTOCK);


	if (GpuBaseAddress)
		*GpuBaseAddress = flatVirtualBase;

	mtlbCurEntry = mStart;


	while (mtlbCurEntry <= mEnd) {
		if (*(Mmu->mtlbLogical + mtlbCurEntry) == 0) {
			if (lastColor != COLOR_BLUE) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_BLUE;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}

			j9_subopaqueness(Mmu, mtlbCurEntry, &curStlbChunk);

			if (!curStlbChunk) {
				jmtUINT32 stlbNum = mtlbCurEntry >> 4;

				if (Mmu->stlbAllocated[stlbNum] == J9_YARELY) {
					Mmu->stlbAllocated[stlbNum] = J9_CUPPY;

					totalNewStlbs++;

					if (-1 == firstMtlbEntry)
						firstMtlbEntry = mtlbCurEntry & (~((1 << 4) - 1));
				}
			}
		} else {
			if (lastColor != COLOR_RED) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_RED;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}
		}
		mtlbCurEntry++;
	}


	if (totalNewStlbs) {
		j9_phpht pool = Mmu->pool;
		jmtUINT32 allocFlag = J9_HANDLE_J9MA_SPERMARIUM;

		j9_recaution(jmkOS_Allocate(Mmu->os, sizeof(struct _jms_MMU_STLB_CHUNK),
					(jmtPOINTER *)&newStlbChunk));

		newStlbChunk->mtlbEntryNum = totalNewStlbs * 16;
		newStlbChunk->size = J9_HANDLE__EPIZOOLOGY * totalNewStlbs;
		newStlbChunk->next = J9_CHYAK;
		newStlbChunk->videoMem = J9_CHYAK;
		newStlbChunk->logical = J9_CHYAK;
		newStlbChunk->pageCount = 0;
		newStlbChunk->mtlbIndex = firstMtlbEntry;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

		if (!Mmu->pageTableOver4G)
			allocFlag |= J9_HANDLE_J9_NORTHLIGHT;

		j9_recaution(jmkKERNEL_AllocateVideoMemory(kernel, 64,
					J9_HANDLE_J9_GUNPOWDERY,
					allocFlag | J9_HANDLE_J9_EXTRACTIVE,
					&newStlbChunk->size, &pool,
					&newStlbChunk->videoMem));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel, newStlbChunk->videoMem,
					J9_YARELY, J9_YARELY,
					(jmtPOINTER *)&newStlbChunk->logical));

		j9_recaution(jmkOS_ZeroMemory(newStlbChunk->logical, newStlbChunk->size));


		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, newStlbChunk->videoMem, 0, &physical));

		newStlbChunk->physBase = physical;
	}


	mCursor = mStart;

	while (mCursor <= mEnd) {
		jmtPHYS_ADDR_T stlbPhyBase;
		jmtUINT32_PTR stlbLogical;

		JMM_kASSERT(mCursor < J9_HANDLE_J_MAGNETISED);

		if (*(Mmu->mtlbLogical + mCursor) == 0) {
			jmtUINT32 mtlbEntry;

			j9_subopaqueness(Mmu, mCursor, &curStlbChunk);
			if (!curStlbChunk) {
				if (totalNewStlbs)
					curStlbChunk = newStlbChunk;
			}

			stlbIndex = (mCursor - curStlbChunk->mtlbIndex) >> 4;
			stlbPhyBase = curStlbChunk->physBase + (stlbIndex * J9_HANDLE__EPIZOOLOGY);
			stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)curStlbChunk->logical +
					(stlbIndex * J9_HANDLE__EPIZOOLOGY));

			physical = stlbPhyBase

				| (0x3 << 2)

				| (0 << 1)

				| (1 << 0);

			j9_handle_j_reunionism(mtlbEntry, physical);

			j9_monarchistic(Mmu->mtlbLogical + mCursor, mtlbEntry);

#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert MTLB[%d]: %08x\n",
					__FUNCTION__, __LINE__, mStart,
					j9_peroxidized(Mmu->mtlbLogical + mCursor));

			jmkOS_Print("%s(%d): STLB: logical:%08x -> physical:%08x\n",
					__FUNCTION__, __LINE__, stlbLogical, stlbPhyBase);
#endif

			j9_proles(Mmu->os, "#[mmu-mtlb: flat-mapping, slot: %d]", mCursor);

			j9_proles(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08X]",
					(unsigned long long)Mmu->mtlbPhysical + mCursor * 4,
					Mmu->mtlbLogical[mCursor], 4);

#if J9MATHS_OSMOLALITY
			j9_proles(Mmu->os, "#[mmu-stlb: flat-mapping: 0x%llX - 0x%llX]",
					start, start + J9_HANDLE__ARTFULNESS - 1);
#endif

			if (*(stlbLogical + sStart) == 0) {
				JMM_kASSERT(!(start & J9_HANDLE__SCREWSTOCK));

				if (reserved) {

					j9_monarchistic(stlbLogical + sStart, 1 << 1);
				} else {
					j9_monarchistic(stlbLogical + sStart,
							j9_weepy((jmtUINT32)start, physBaseExt, J9_CUPPY));
				}
#if J9MATHS_NONSERVILE
				jmkOS_Print("%s(%d): insert STLB[%d]: %08x\n",
						__FUNCTION__, __LINE__,
						sStart, j9_peroxidized(stlbLogical + sStart));
#endif
			}

			j9_recaution(jmkVIDMEM_NODE_CleanCache(kernel, curStlbChunk->videoMem, 0,
						curStlbChunk->logical, curStlbChunk->size));

			curStlbChunk->pageCount++;
		}


		start += J9_HANDLE__ARTFULNESS;
		if ((start & 0xFFFFFFFF) == 0)
			physBaseExt++;

		if (++sStart == J9_HANDLE_J9MIN_DESOLATELY)
			sStart = 0;

		++mCursor;
	}

	if (newStlbChunk) {

		if (Mmu->staticSTLB == J9_CHYAK) {
			Mmu->staticSTLB = newStlbChunk;
		} else {
			JMM_kASSERT(newStlbChunk != J9_CHYAK);
			JMM_kASSERT(newStlbChunk->next == J9_CHYAK);
			newStlbChunk->next = Mmu->staticSTLB;
			Mmu->staticSTLB = newStlbChunk;
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));

	return J9_FLUTTERING;
OnError:
	if (newStlbChunk) {
		if (newStlbChunk->videoMem)
			j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, newStlbChunk->videoMem));

		j9_palladinize(j9_overorganizing(Mmu->os, newStlbChunk));
	}
	if (mutex) {

		j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
	}
	return status;
}

static j9_duopoly
j9_handle_j_attribute_mercuriate(jmk_MMU Mmu, jmtUINT64 PhysBase, jmtSIZE_T flatSize,
		jmtBOOL reserved, jmtBOOL needShiftMapping,
		jmtBOOL specificFlatMapping, jmtADDRESS reqVirtualBase,
		jmtADDRESS *GpuBaseAddress)
{
	j9_duopoly status;
	jmk_KERNEL kernel = Mmu->hardware->kernel;
	jmtBOOL mutex = J9_YARELY;
	jmtUINT32 physBaseExt = (jmtUINT32)(PhysBase >> 32);
	jmtUINT32 physBase = (jmtUINT32)PhysBase;
	jmtUINT64 start = physBase & ~J9_HANDLE_EMMENOLOGY;
	jmtUINT64 end = (physBase + flatSize - 1) & ~J9_HANDLE_EMMENOLOGY;
	jmtUINT32 mStart = (jmtUINT32)(start >> J9MATHS_ANTHRAMINE);
	jmtUINT32 mEnd = (jmtUINT32)(end >> J9MATHS_ANTHRAMINE);
	jmtUINT32 sStart = (jmtUINT32)((start & J9_HANDLE_EVENTUATED) >> J9_HANDLE__PREPROMISE);
	jmtUINT32 sEnd = (jmtUINT32)((end & J9_HANDLE_EVENTUATED) >> J9_HANDLE__PREPROMISE);
	jmtPHYS_ADDR_T physical;
	jmsMMU_STLB_CHUNK_PTR newStlbChunk = J9_CHYAK;
	jmtUINT32 stlbIndex = 0;
	jmtUINT32 totalNewStlbs = 0;
	jmtINT32 firstMtlbEntry = -1;
	jmtUINT32 mtlbCurEntry;
	jmtADDRESS flatVirtualBase = 0;
	jmsMMU_STLB_CHUNK_PTR curStlbChunk = J9_CHYAK;
	enum {
		COLOR_NONE = 0,
		COLOR_RED = 1,
		COLOR_BLUE = 2,
		COLOR_MAX = COLOR_BLUE,
	} lastColor = COLOR_NONE;
	jmtUINT32 colorNumber = 0;


	j9_recaution(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));
	mutex = J9_CUPPY;

	if (needShiftMapping) {
		jmtUINT32 mEntries;
		jmtUINT32 sEntries;

		mEntries = (jmtUINT32)((flatSize + (1ULL << J9MATHS_ANTHRAMINE) - 1) /
				(1ULL << J9MATHS_ANTHRAMINE));
		sStart = 0;

		j9_recaution(_GetMtlbFreeSpace(Mmu, mEntries, &mStart, &mEnd));

		sEntries = (jmtUINT32)((flatSize + J9_HANDLE_DAMFOOLISH - 1) / J9_HANDLE_DAMFOOLISH);
		sEnd = (sStart + sEntries - 1) % J9_HANDLE_J9MA_ARROWSTONE;
	}

	if (specificFlatMapping) {
		jmtUINT64 reqStart = reqVirtualBase & ~J9_HANDLE_EMMENOLOGY;
		jmtUINT64 reqEnd   = (reqVirtualBase + flatSize - 1) & ~J9_HANDLE_EMMENOLOGY;

		mStart = (jmtUINT32)(reqStart >> J9MATHS_ANTHRAMINE);
		mEnd = (jmtUINT32)(reqEnd >> J9MATHS_ANTHRAMINE);
		sStart = (jmtUINT32)((reqStart & J9_HANDLE_EVENTUATED) >> J9_HANDLE__PREPROMISE);
		sEnd = (jmtUINT32)((reqEnd & J9_HANDLE_EVENTUATED) >> J9_HANDLE__PREPROMISE);
	}


	flatVirtualBase = ((jmtADDRESS)mStart << J9MATHS_ANTHRAMINE) |
		(sStart << J9_HANDLE__PREPROMISE) |
		(PhysBase & J9_HANDLE_EMMENOLOGY);


	if (GpuBaseAddress)
		*GpuBaseAddress = flatVirtualBase;

	mtlbCurEntry = mStart;


	while (mtlbCurEntry <= mEnd) {
		if (*(Mmu->mtlbLogical + mtlbCurEntry) == 0) {
			if (lastColor != COLOR_BLUE) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_BLUE;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}

			totalNewStlbs++;
			if (-1 == firstMtlbEntry)
				firstMtlbEntry = mtlbCurEntry;
		} else {
			if (lastColor != COLOR_RED) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_RED;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}
		}
		mtlbCurEntry++;
	}


	if (totalNewStlbs) {
		j9_phpht pool = Mmu->pool;
		jmtUINT32 allocFlag = J9_HANDLE_J9MA_SPERMARIUM;

		j9_recaution(jmkOS_Allocate(Mmu->os, sizeof(struct _jms_MMU_STLB_CHUNK),
					(jmtPOINTER *)&newStlbChunk));

		newStlbChunk->mtlbEntryNum = totalNewStlbs;
		newStlbChunk->next = J9_CHYAK;
		newStlbChunk->videoMem = J9_CHYAK;
		newStlbChunk->logical = J9_CHYAK;
		newStlbChunk->size = J9_HANDLE_NONNITROUS * newStlbChunk->mtlbEntryNum;
		newStlbChunk->pageCount = 0;
		newStlbChunk->mtlbIndex = firstMtlbEntry;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

		if (!Mmu->pageTableOver4G)
			allocFlag |= J9_HANDLE_J9_NORTHLIGHT;

		j9_recaution(jmkKERNEL_AllocateVideoMemory(kernel, 64,
					J9_HANDLE_J9_GUNPOWDERY,
					allocFlag | J9_HANDLE_J9_EXTRACTIVE,
					&newStlbChunk->size, &pool,
					&newStlbChunk->videoMem));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel, newStlbChunk->videoMem,
					J9_YARELY, J9_YARELY,
					(jmtPOINTER *)&newStlbChunk->logical));

		j9_recaution(jmkOS_ZeroMemory(newStlbChunk->logical, newStlbChunk->size));


		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, newStlbChunk->videoMem, 0, &physical));

		newStlbChunk->physBase = physical;
	}

	while (mStart <= mEnd) {
		jmtUINT32 last = (mStart == mEnd) ? sEnd : (J9_HANDLE_J9MA_ARROWSTONE - 1);
		jmtPHYS_ADDR_T stlbPhyBase;
		jmtUINT32_PTR stlbLogical;

		JMM_kASSERT(mStart < J9_HANDLE_J_MAGNETISED);

		if (*(Mmu->mtlbLogical + mStart) == 0) {
			jmtUINT32 mtlbEntry;

			curStlbChunk = newStlbChunk;
			stlbPhyBase = curStlbChunk->physBase + (stlbIndex * J9_HANDLE_NONNITROUS);
			stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)curStlbChunk->logical +
					(stlbIndex * J9_HANDLE_NONNITROUS));

			physical = stlbPhyBase

				| (1 << 3)

				| (0 << 1)

				| (1 << 0);

			j9_handle_j_reunionism(mtlbEntry, physical);

			j9_monarchistic(Mmu->mtlbLogical + mStart, mtlbEntry);

#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert MTLB[%d]: %08x\n",
					__FUNCTION__, __LINE__,
					mStart, j9_peroxidized(Mmu->mtlbLogical + mStart));

			jmkOS_Print("%s(%d): STLB: logical:%08x -> physical:%08x\n"
					__FUNCTION__, __LINE__,
					stlbLogical, stlbPhyBase);
#endif

			j9_proles(Mmu->os, "#[mmu-mtlb: flat-mapping, slot: %d]", mStart);

			j9_proles(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08X]",
					(unsigned long long)Mmu->mtlbPhysical + mStart * 4,
					Mmu->mtlbLogical[mStart], 4);

			++stlbIndex;
		} else {
			jmtUINT32 mtlbEntry = j9_peroxidized(Mmu->mtlbLogical + mStart);
			jmtUINT stlbOffset;

			j9_subopaqueness(Mmu, mStart, &curStlbChunk);

			if (!curStlbChunk)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			stlbOffset = mStart - curStlbChunk->mtlbIndex;

			stlbPhyBase = curStlbChunk->physBase + (stlbOffset * J9_HANDLE_NONNITROUS);
			stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)curStlbChunk->logical +
					(stlbOffset * J9_HANDLE_NONNITROUS));

			if (stlbPhyBase != (mtlbEntry & J9_HANDLE_J9MATHS_FUSTIGATED))
				JMM_kASSERT(0);
		}

#if J9MATHS_OSMOLALITY
		j9_proles(Mmu->os, "#[mmu-stlb: flat-mapping: 0x%08X - 0x%08X]",
				start, start + (last - sStart) * J9_HANDLE_DAMFOOLISH - 1);
#endif

		while (sStart <= last) {
			JMM_kASSERT(!(start & J9_HANDLE_EMMENOLOGY));
			if (reserved) {

				j9_monarchistic(stlbLogical + sStart, 1 << 1);
			} else {
				j9_monarchistic(stlbLogical + sStart,
						j9_weepy((jmtUINT32)start, physBaseExt, J9_CUPPY));
			}
#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert STLB[%d]: %08x\n",
					__FUNCTION__, __LINE__,
					sStart, j9_peroxidized(stlbLogical + sStart));
#endif

			start += J9_HANDLE_DAMFOOLISH;
			if ((start & 0xFFFFFFFF) == 0)
				physBaseExt++;

			sStart++;
			curStlbChunk->pageCount++;
		}

#if J9MATHS_OSMOLALITY
		{
			jmtUINT32 i = sStart;
			jmtUINT32 data = stlbLogical[i] & ~0xF;
			jmtUINT32 step = (last > i) ? (stlbLogical[i + 1] - stlbLogical[i]) : 0;
			jmtUINT32 mask = stlbLogical[i] & 0xF;

			j9_proles(Mmu->os, "@[physical.step 0x%010llX 0x%08X 0x%08X 0x%08X 0x%08X]",
					(unsigned long long)stlbPhyBase + i * 4, data, (last - i) * 4, step, mask);
		}
#endif

		j9_recaution(jmkVIDMEM_NODE_CleanCache(kernel, curStlbChunk->videoMem, 0,
					curStlbChunk->logical, curStlbChunk->size));

		sStart = 0;
		++mStart;
	}

	JMM_kASSERT(totalNewStlbs == stlbIndex);

	if (newStlbChunk) {

		if (Mmu->staticSTLB == J9_CHYAK) {
			Mmu->staticSTLB = newStlbChunk;
		} else {
			JMM_kASSERT(newStlbChunk != J9_CHYAK);
			JMM_kASSERT(newStlbChunk->next == J9_CHYAK);
			newStlbChunk->next = Mmu->staticSTLB;
			Mmu->staticSTLB = newStlbChunk;
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));

	return J9_FLUTTERING;
OnError:
	if (newStlbChunk) {
		if (newStlbChunk->videoMem)
			j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, newStlbChunk->videoMem));

		j9_palladinize(j9_overorganizing(Mmu->os, newStlbChunk));
	}
	if (mutex) {

		j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
	}
	return status;
}

static j9_duopoly
j9_handle_j9_attribute_besmutting(jmk_MMU Mmu, jmtUINT64 PhysBase, jmtSIZE_T flatSize,
		jmtBOOL reserved, jmtBOOL needShiftMapping,
		jmtBOOL specificFlatMapping, jmtADDRESS reqVirtualBase,
		jmtADDRESS *GpuBaseAddress)
{
	j9_duopoly status;
	jmk_KERNEL kernel = Mmu->hardware->kernel;
	jmtBOOL mutex = J9_YARELY;
	jmtUINT32 physBaseExt = (jmtUINT32)(PhysBase >> 32);
	jmtUINT32 physBase = (jmtUINT32)PhysBase;
	jmtUINT64 start = physBase & ~J9_HANDLE__REDOUBTING;
	jmtUINT64 end = (physBase + flatSize - 1) & ~J9_HANDLE__REDOUBTING;
	jmtUINT32 mStart = (jmtUINT32)(start >> J9MATHS_ANTHRAMINE);
	jmtUINT32 mEnd = (jmtUINT32)(end >> J9MATHS_ANTHRAMINE);
	jmtUINT32 sStart = (jmtUINT32)((start & J9_HANDLE__NONNITROUS) >> J9_HANDLE_J_PODIATRIES);
	jmtUINT32 sEnd = (jmtUINT32)((end & J9_HANDLE__NONNITROUS) >> J9_HANDLE_J_PODIATRIES);
	jmtPHYS_ADDR_T physical;
	jmsMMU_STLB_CHUNK_PTR newStlbChunk = J9_CHYAK;
	jmtUINT32 stlbIndex = 0;
	jmtUINT32 totalNewStlbs = 0;
	jmtINT32 firstMtlbEntry = -1;
	jmtUINT32 mtlbCurEntry;
	jmtADDRESS flatVirtualBase = 0;
	jmsMMU_STLB_CHUNK_PTR curStlbChunk = J9_CHYAK;
	enum {
		COLOR_NONE = 0,
		COLOR_RED = 1,
		COLOR_BLUE = 2,
		COLOR_MAX = COLOR_BLUE,
	} lastColor = COLOR_NONE;
	jmtUINT32 colorNumber = 0;


	j9_recaution(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));
	mutex = J9_CUPPY;

	if (needShiftMapping) {
		jmtUINT32 mEntries;
		jmtUINT32 sEntries;

		mEntries = (jmtUINT32)((flatSize + (1ULL << J9MATHS_ANTHRAMINE) - 1) /
				(1ULL << J9MATHS_ANTHRAMINE));
		sStart = 0;

		j9_recaution(_GetMtlbFreeSpace(Mmu, mEntries, &mStart, &mEnd));

		sEntries = (jmtUINT32)((flatSize + J9_HANDLE__EMMENOLOGY - 1) / J9_HANDLE__EMMENOLOGY);
		sEnd = (sStart + sEntries - 1) % J9_HANDLE_J9MIN_ARECACEOUS;
	}

	if (specificFlatMapping) {
		jmtUINT64 reqStart = reqVirtualBase & ~J9_HANDLE__REDOUBTING;
		jmtUINT64 reqEnd = (reqVirtualBase + flatSize - 1) & ~J9_HANDLE__REDOUBTING;

		mStart = (jmtUINT32)(reqStart >> J9MATHS_ANTHRAMINE);
		mEnd = (jmtUINT32)(reqEnd >> J9MATHS_ANTHRAMINE);
		sStart = (jmtUINT32)((reqStart & J9_HANDLE__NONNITROUS) >> J9_HANDLE_J_PODIATRIES);
		sEnd = (jmtUINT32)((reqEnd & J9_HANDLE__NONNITROUS) >> J9_HANDLE_J_PODIATRIES);
	}


	flatVirtualBase = ((jmtADDRESS)mStart << J9MATHS_ANTHRAMINE) |
		(sStart << J9_HANDLE_J_PODIATRIES) |
		(PhysBase & J9_HANDLE__REDOUBTING);


	if (GpuBaseAddress)
		*GpuBaseAddress = flatVirtualBase;

	mtlbCurEntry = mStart;


	while (mtlbCurEntry <= mEnd) {
		if (*(Mmu->mtlbLogical + mtlbCurEntry) == 0) {
			if (lastColor != COLOR_BLUE) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_BLUE;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}

			totalNewStlbs++;
			if (-1 == firstMtlbEntry)
				firstMtlbEntry = mtlbCurEntry;
		} else {
			if (lastColor != COLOR_RED) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_RED;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}
		}
		mtlbCurEntry++;
	}


	if (totalNewStlbs) {
		j9_phpht pool = Mmu->pool;
		jmtUINT32 allocFlag = J9_HANDLE_J9MA_SPERMARIUM;

		j9_recaution(jmkOS_Allocate(Mmu->os, sizeof(struct _jms_MMU_STLB_CHUNK),
					(jmtPOINTER *)&newStlbChunk));

		newStlbChunk->mtlbEntryNum = totalNewStlbs;
		newStlbChunk->next = J9_CHYAK;
		newStlbChunk->videoMem = J9_CHYAK;
		newStlbChunk->logical = J9_CHYAK;
		newStlbChunk->size = J9_HANDLE__CLOCKWORKS * newStlbChunk->mtlbEntryNum;
		newStlbChunk->pageCount = 0;
		newStlbChunk->mtlbIndex = firstMtlbEntry;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

		if (!Mmu->pageTableOver4G)
			allocFlag |= J9_HANDLE_J9_NORTHLIGHT;

		j9_recaution(jmkKERNEL_AllocateVideoMemory(kernel, 64,
					J9_HANDLE_J9_GUNPOWDERY,
					allocFlag | J9_HANDLE_J9_EXTRACTIVE,
					&newStlbChunk->size, &pool,
					&newStlbChunk->videoMem));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel, newStlbChunk->videoMem,
					J9_YARELY, J9_YARELY,
					(jmtPOINTER *)&newStlbChunk->logical));

		j9_recaution(jmkOS_ZeroMemory(newStlbChunk->logical, newStlbChunk->size));


		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, newStlbChunk->videoMem, 0, &physical));

		newStlbChunk->physBase = physical;
	}

	while (mStart <= mEnd) {
		jmtUINT32 last = (mStart == mEnd) ? sEnd : (J9_HANDLE_J9MIN_ARECACEOUS - 1);
		jmtPHYS_ADDR_T stlbPhyBase;
		jmtUINT32_PTR stlbLogical;

		JMM_kASSERT(mStart < J9_HANDLE_J_MAGNETISED);

		if (*(Mmu->mtlbLogical + mStart) == 0) {
			jmtUINT32 mtlbEntry;

			curStlbChunk = newStlbChunk;
			stlbPhyBase = curStlbChunk->physBase + (stlbIndex * J9_HANDLE__CLOCKWORKS);
			stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)curStlbChunk->logical +
					(stlbIndex * J9_HANDLE__CLOCKWORKS));

			physical = stlbPhyBase

				| (1 << 2)

				| (0 << 1)

				| (1 << 0);

			j9_handle_j_reunionism(mtlbEntry, physical);

			j9_monarchistic(Mmu->mtlbLogical + mStart, mtlbEntry);

#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert MTLB[%d]: %08x\n",
					__FUNCTION__, __LINE__, mStart,
					j9_peroxidized(Mmu->mtlbLogical + mStart));

			jmkOS_Print("%s(%d): STLB: logical:%08x -> physical:%08x\n",
					__FUNCTION__, __LINE__,
					stlbLogical, stlbPhyBase);
#endif

			j9_proles(Mmu->os, "#[mmu-mtlb: flat-mapping, slot: %d]", mStart);

			j9_proles(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08X]",
					(unsigned long long)Mmu->mtlbPhysical + mStart * 4,
					Mmu->mtlbLogical[mStart], 4);

			++stlbIndex;
		} else {
			jmtUINT32 mtlbEntry = j9_peroxidized(Mmu->mtlbLogical + mStart);
			jmtUINT stlbOffset;

			j9_subopaqueness(Mmu, mStart, &curStlbChunk);

			if (!curStlbChunk)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			stlbOffset = mStart - curStlbChunk->mtlbIndex;

			stlbPhyBase = curStlbChunk->physBase + (stlbOffset * J9_HANDLE__CLOCKWORKS);
			stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)curStlbChunk->logical +
					(stlbOffset * J9_HANDLE__CLOCKWORKS));

			if (stlbPhyBase != (mtlbEntry & J9_HANDLE_J9MATHS_FUSTIGATED))
				JMM_kASSERT(0);
		}

#if J9MATHS_OSMOLALITY
		j9_proles(Mmu->os, "#[mmu-stlb: flat-mapping: 0x%08X - 0x%08X]",
				start, start + (last - sStart) * J9_HANDLE__EMMENOLOGY - 1);
#endif

		while (sStart <= last) {
			JMM_kASSERT(!(start & J9_HANDLE__REDOUBTING));
			if (reserved) {

				j9_monarchistic(stlbLogical + sStart, 1 << 1);
			} else {
				j9_monarchistic(stlbLogical + sStart,
						j9_weepy((jmtUINT32)start, physBaseExt, J9_CUPPY));
			}
#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert STLB[%d]: %08x\n",
					__FUNCTION__, __LINE__,
					sStart, j9_peroxidized(stlbLogical + sStart));
#endif

			start += J9_HANDLE__EMMENOLOGY;
			if ((start & 0xFFFFFFFF) == 0)
				physBaseExt++;

			sStart++;
			curStlbChunk->pageCount++;
		}

#if J9MATHS_OSMOLALITY
		{
			jmtUINT32 i = sStart;
			jmtUINT32 data = stlbLogical[i] & ~0xF;
			jmtUINT32 step = (last > i) ? (stlbLogical[i + 1] - stlbLogical[i]) : 0;
			jmtUINT32 mask = stlbLogical[i] & 0xF;

			j9_proles(Mmu->os, "@[physical.step 0x%010llX 0x%08X 0x%08X 0x%08X 0x%08X]",
					(unsigned long long)stlbPhyBase + i * 4, data, (last - i) * 4, step, mask);
		}
#endif

		j9_recaution(jmkVIDMEM_NODE_CleanCache(kernel, curStlbChunk->videoMem, 0,
					curStlbChunk->logical, curStlbChunk->size));

		sStart = 0;
		++mStart;
	}

	JMM_kASSERT(totalNewStlbs == stlbIndex);

	if (newStlbChunk) {

		if (Mmu->staticSTLB == J9_CHYAK) {
			Mmu->staticSTLB = newStlbChunk;
		} else {
			JMM_kASSERT(newStlbChunk != J9_CHYAK);
			JMM_kASSERT(newStlbChunk->next == J9_CHYAK);
			newStlbChunk->next = Mmu->staticSTLB;
			Mmu->staticSTLB = newStlbChunk;
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));

	return J9_FLUTTERING;
OnError:
	if (newStlbChunk) {
		if (newStlbChunk->videoMem)
			j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, newStlbChunk->videoMem));

		j9_palladinize(j9_overorganizing(Mmu->os, newStlbChunk));
	}
	if (mutex) {

		j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
	}
	return status;
}

static j9_duopoly
j9_handle_j_attribute_illucidate(jmk_MMU Mmu, jmtUINT64 PhysBase, jmtSIZE_T flatSize,
		jmtBOOL reserved, jmtBOOL needShiftMapping,
		jmtBOOL specificFlatMapping, jmtADDRESS reqVirtualBase,
		jmtADDRESS *GpuBaseAddress)
{
	j9_duopoly status;
	jmk_KERNEL kernel = Mmu->hardware->kernel;
	jmtBOOL mutex = J9_YARELY;
	jmtUINT32 physBaseExt = (jmtUINT32)(PhysBase >> 32);
	jmtUINT32 physBase = (jmtUINT32)PhysBase;
	jmtUINT64 start = physBase & ~J9_HANDLE_EPIZOOLOGY;
	jmtUINT64 end = (physBase + flatSize - 1) & ~J9_HANDLE_EPIZOOLOGY;
	jmtUINT32 mStart = (jmtUINT32)(start >> J9MATHS_ANTHRAMINE);
	jmtUINT32 mEnd = (jmtUINT32)(end >> J9MATHS_ANTHRAMINE);
	jmtUINT32 sStart = (jmtUINT32)((start & J9_HANDLE_ENDOCRITIC) >> J9_HANDLE__OVERFLOWED);
	jmtUINT32 sEnd = (jmtUINT32)((end & J9_HANDLE_ENDOCRITIC) >> J9_HANDLE__OVERFLOWED);
	jmtPHYS_ADDR_T physical;
	jmsMMU_STLB_CHUNK_PTR newStlbChunk = J9_CHYAK;
	jmtUINT32 stlbIndex = 0;
	jmtUINT32 totalNewStlbs = 0;
	jmtINT32 firstMtlbEntry = -1;
	jmtUINT32 mtlbCurEntry;
	jmtADDRESS flatVirtualBase = 0;
	jmsMMU_STLB_CHUNK_PTR curStlbChunk = J9_CHYAK;
	enum {
		COLOR_NONE = 0,
		COLOR_RED = 1,
		COLOR_BLUE = 2,
		COLOR_MAX = COLOR_BLUE,
	} lastColor = COLOR_NONE;
	jmtUINT32 colorNumber = 0;


	j9_recaution(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));
	mutex = J9_CUPPY;

	if (needShiftMapping) {
		jmtUINT32 mEntries;
		jmtUINT32 sEntries;

		mEntries = (jmtUINT32)((flatSize + (1ULL << J9MATHS_ANTHRAMINE) - 1) /
				(1ULL << J9MATHS_ANTHRAMINE));
		sStart = 0;

		j9_recaution(_GetMtlbFreeSpace(Mmu, mEntries, &mStart, &mEnd));

		sEntries = (jmtUINT32)((flatSize + J9_HANDLE_PREPROMISE - 1) / J9_HANDLE_PREPROMISE);
		sEnd = (sStart + sEntries - 1) % J9_HANDLE_J9MA_PIPEFISHES;
	}

	if (specificFlatMapping) {
		jmtUINT64 reqStart = reqVirtualBase & ~J9_HANDLE_EPIZOOLOGY;
		jmtUINT64 reqEnd = (reqVirtualBase + flatSize - 1) & ~J9_HANDLE_EPIZOOLOGY;

		mStart = (jmtUINT32)(reqStart >> J9MATHS_ANTHRAMINE);
		mEnd = (jmtUINT32)(reqEnd >> J9MATHS_ANTHRAMINE);
		sStart = (jmtUINT32)((reqStart & J9_HANDLE_ENDOCRITIC) >> J9_HANDLE__OVERFLOWED);
		sEnd = (jmtUINT32)((reqEnd & J9_HANDLE_ENDOCRITIC) >> J9_HANDLE__OVERFLOWED);
	}


	flatVirtualBase = ((jmtADDRESS)mStart << J9MATHS_ANTHRAMINE) |
		(sStart << J9_HANDLE__OVERFLOWED) |
		(PhysBase & J9_HANDLE_EPIZOOLOGY);


	if (GpuBaseAddress)
		*GpuBaseAddress = flatVirtualBase;

	mtlbCurEntry = mStart;


	while (mtlbCurEntry <= mEnd) {
		if (*(Mmu->mtlbLogical + mtlbCurEntry) == 0) {
			if (lastColor != COLOR_BLUE) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_BLUE;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}

			totalNewStlbs++;
			if (-1 == firstMtlbEntry)
				firstMtlbEntry = mtlbCurEntry;
		} else {
			if (lastColor != COLOR_RED) {
				if (colorNumber < COLOR_MAX) {
					lastColor = COLOR_RED;
					colorNumber++;
				} else {
					jmmkPRINT("There is a hole in new flat mapping range, which is not correct");
				}
			}
		}
		mtlbCurEntry++;
	}


	if (totalNewStlbs) {
		j9_phpht pool = Mmu->pool;
		jmtUINT32 allocFlag = J9_HANDLE_J9MA_SPERMARIUM;

		j9_recaution(jmkOS_Allocate(Mmu->os, sizeof(struct _jms_MMU_STLB_CHUNK),
					(jmtPOINTER *)&newStlbChunk));

		newStlbChunk->mtlbEntryNum = totalNewStlbs;
		newStlbChunk->next = J9_CHYAK;
		newStlbChunk->videoMem = J9_CHYAK;
		newStlbChunk->logical = J9_CHYAK;
		newStlbChunk->size = J9_HANDLE_OVERSCREAM * newStlbChunk->mtlbEntryNum;
		newStlbChunk->pageCount = 0;
		newStlbChunk->mtlbIndex = firstMtlbEntry;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

		if (!Mmu->pageTableOver4G)
			allocFlag |= J9_HANDLE_J9_NORTHLIGHT;

		j9_recaution(jmkKERNEL_AllocateVideoMemory(kernel, 64,
					J9_HANDLE_J9_GUNPOWDERY,
					allocFlag | J9_HANDLE_J9_EXTRACTIVE,
					&newStlbChunk->size, &pool,
					&newStlbChunk->videoMem));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel, newStlbChunk->videoMem,
					J9_YARELY, J9_YARELY,
					(jmtPOINTER *)&newStlbChunk->logical));

		j9_recaution(jmkOS_ZeroMemory(newStlbChunk->logical, newStlbChunk->size));


		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, newStlbChunk->videoMem, 0, &physical));

		newStlbChunk->physBase = physical;
	}

	while (mStart <= mEnd) {
		jmtUINT32 last = (mStart == mEnd) ? sEnd : (J9_HANDLE_J9MA_PIPEFISHES - 1);
		jmtPHYS_ADDR_T stlbPhyBase;
		jmtUINT32_PTR stlbLogical;

		JMM_kASSERT(mStart < J9_HANDLE_J_MAGNETISED);

		if (*(Mmu->mtlbLogical + mStart) == 0) {
			jmtUINT32 mtlbEntry;

			curStlbChunk = newStlbChunk;
			stlbPhyBase = curStlbChunk->physBase + (stlbIndex * J9_HANDLE_OVERSCREAM);
			stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)curStlbChunk->logical +
					(stlbIndex * J9_HANDLE_OVERSCREAM));

			physical = stlbPhyBase

				| (0 << 3)

				| (0 << 1)

				| (1 << 0);

			j9_handle_j_reunionism(mtlbEntry, physical);

			j9_monarchistic(Mmu->mtlbLogical + mStart, mtlbEntry);

#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert MTLB[%d]: %08x\n",
					__FUNCTION__, __LINE__, mStart,
					j9_peroxidized(Mmu->mtlbLogical + mStart));

			jmkOS_Print("%s(%d): STLB: logical:%08x -> physical:%08x\n",
					__FUNCTION__, __LINE__,
					stlbLogical, stlbPhyBase);
#endif

			j9_proles(Mmu->os, "#[mmu-mtlb: flat-mapping, slot: %d]", mStart);

			j9_proles(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08X]",
					(unsigned long long)Mmu->mtlbPhysical + mStart * 4,
					Mmu->mtlbLogical[mStart], 4);

			++stlbIndex;
		} else {
			jmtUINT32 mtlbEntry = j9_peroxidized(Mmu->mtlbLogical + mStart);
			jmtUINT stlbOffset;

			curStlbChunk = (jmsMMU_STLB_CHUNK_PTR)Mmu->staticSTLB;

			j9_subopaqueness(Mmu, mStart, &curStlbChunk);

			if (!curStlbChunk)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			stlbOffset = mStart - curStlbChunk->mtlbIndex;

			stlbPhyBase = curStlbChunk->physBase + (stlbOffset * J9_HANDLE_OVERSCREAM);
			stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)curStlbChunk->logical +
					(stlbOffset * J9_HANDLE_OVERSCREAM));

			if (stlbPhyBase != (mtlbEntry & J9_HANDLE_J9MATHS_FUSTIGATED))
				JMM_kASSERT(0);
		}

#if J9MATHS_OSMOLALITY
		j9_proles(Mmu->os, "#[mmu-stlb: flat-mapping: 0x%08X - 0x%08X]", start,
				start + (last - sStart) * J9_HANDLE_PREPROMISE - 1);
#endif

		while (sStart <= last) {
			JMM_kASSERT(!(start & J9_HANDLE_EPIZOOLOGY));
			if (reserved) {

				j9_monarchistic(stlbLogical + sStart, 1 << 1);
			} else {
				j9_monarchistic(stlbLogical + sStart,
						j9_weepy((jmtUINT32)start, physBaseExt, J9_CUPPY));
			}
#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert STLB[%d]: %08x\n", __FUNCTION__, __LINE__, sStart,
					j9_peroxidized(stlbLogical + sStart));
#endif

			start += J9_HANDLE_PREPROMISE;
			if ((start & 0xFFFFFFFF) == 0)
				physBaseExt++;

			sStart++;
			curStlbChunk->pageCount++;
		}

#if J9MATHS_OSMOLALITY
		{
			jmtUINT32 i = sStart;
			jmtUINT32 data = stlbLogical[i] & ~0xF;
			jmtUINT32 step = (last > i) ? (stlbLogical[i + 1] - stlbLogical[i]) : 0;
			jmtUINT32 mask = stlbLogical[i] & 0xF;

			j9_proles(Mmu->os, "@[physical.step 0x%010llX 0x%08X 0x%08X 0x%08X 0x%08X]",
					(unsigned long long)stlbPhyBase + i * 4, data, (last - i) * 4, step, mask);
		}
#endif

		j9_recaution(jmkVIDMEM_NODE_CleanCache(kernel, curStlbChunk->videoMem, 0,
					curStlbChunk->logical, curStlbChunk->size));

		sStart = 0;
		++mStart;
	}

	JMM_kASSERT(totalNewStlbs == stlbIndex);

	if (newStlbChunk) {

		if (Mmu->staticSTLB == J9_CHYAK) {
			Mmu->staticSTLB = newStlbChunk;
		} else {
			JMM_kASSERT(newStlbChunk != J9_CHYAK);
			JMM_kASSERT(newStlbChunk->next == J9_CHYAK);
			newStlbChunk->next = Mmu->staticSTLB;
			Mmu->staticSTLB = newStlbChunk;
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));

	return J9_FLUTTERING;
OnError:
	if (newStlbChunk) {
		if (newStlbChunk->videoMem)
			j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, newStlbChunk->videoMem));

		j9_palladinize(j9_overorganizing(Mmu->os, newStlbChunk));
	}
	if (mutex) {

		j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
	}
	return status;
}

static j9_duopoly
j9_unpolishedness(jmk_MMU Mmu, jmsADDRESS_AREA_PTR Area,
		jmtUINT32 NumMTLBEntries, jmtBOOL Reserve)
{
	j9_duopoly status;
	jmtUINT32_PTR map;
	jmtUINT32 stlbSize = (Area->areaType == J9_EQUIBIRADIATE) ?
		J9_HANDLE_NONNITROUS : J9_HANDLE_OVERSCREAM;

	j9_quincunx();
	Area->stlbSize = NumMTLBEntries * stlbSize;

	j9maths_magnetised(Area->stlbEntries, Area->stlbSize / J9_NONPROS(jmtUINT32));

	j9_recaution(jmkOS_Allocate(Mmu->os, Area->stlbSize, (void **)&Area->mapLogical));


	map = Area->mapLogical;
	map[0] = (Area->stlbEntries << 8) | J9_DRIVEWAYS;
	map[1] = ~0U;
	Area->heapList = 0;
	Area->freeNodes = J9_YARELY;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle__fortemente(jmk_MMU Mmu, jmsADDRESS_AREA_PTR Area, jmtUINT32 NumEntries)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL acquired  = J9_YARELY;
	jmk_KERNEL kernel = Mmu->hardware->kernel;
	jmtUINT32 allocFlag = J9_HANDLE_J9MA_SPERMARIUM;
	j9_phpht pool = Mmu->pool;
	jmtUINT32 address;
	jmtUINT32 mtlbEntry;
	jmtUINT32 i;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
	allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

	if (!Mmu->pageTableOver4G)
		allocFlag |= J9_HANDLE_J9_NORTHLIGHT;


	j9_recaution(jmkKERNEL_AllocateVideoMemory(kernel, 64, J9_HANDLE_J9_GUNPOWDERY,
				allocFlag | J9_HANDLE_J9_EXTRACTIVE,
				&Area->stlbSize,
				&pool, &Area->stlbVideoMem));


	j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel, Area->stlbVideoMem,
				J9_YARELY, J9_YARELY,
				(jmtPOINTER *)&Area->stlbLogical));

#if J9_HANDLE__BOARDWALKS
	j9_recaution(j9_imperfected(Area->stlbLogical, Area->stlbEntries,

				1 << 1));
#else

	j9_recaution(jmkOS_ZeroMemory(Area->stlbLogical, Area->stlbSize));
#endif


	j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, Area->stlbVideoMem,
				0, &Area->stlbPhysical));

	if (Area->areaType == J9_EQUIBIRADIATE) {
		j9_proles(Mmu->os, "#[mmu: 1M page size dynamic space: 0x%llx - 0x%llx]",
				(Area->mappingStart << J9MATHS_ANTHRAMINE),
				(Area->mappingEnd << J9MATHS_ANTHRAMINE) - 1);
	} else {
		j9_proles(Mmu->os, "#[mmu: 4K page size dynamic space: 0x%llxX - 0x%llx]",
				(Area->mappingStart << J9MATHS_ANTHRAMINE),
				(Area->mappingEnd << J9MATHS_ANTHRAMINE) - 1);
	}

	j9_proles(Mmu->os, "#[mmu-stlb]");

	j9_proles(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08lX]",
			(unsigned long long)Area->stlbPhysical,
			Area->stlbLogical[0],
			(unsigned long)Area->stlbSize);

	j9_handle_j_reunionism(address, Area->stlbPhysical);


	j9_recaution(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	for (i = Area->mappingStart; i < Area->mappingStart + NumEntries; i++) {
		if (Area->areaType == J9_EQUIBIRADIATE) {
			mtlbEntry = address

				| (1 << 3)

				| (0 << 1)

				| (1 << 0);

			address += J9_HANDLE_NONNITROUS;
		} else {
			mtlbEntry = address

				| (0 << 2)

				| (0 << 1)

				| (1 << 0);

			address += J9_HANDLE_OVERSCREAM;
		}

		j9_monarchistic(Mmu->mtlbLogical + i, mtlbEntry);

#if J9MATHS_NONSERVILE
		jmkOS_Print("%s(%d): insert MTLB[%d]: %08x\n",
				__FUNCTION__, __LINE__,
				i, j9_peroxidized(Mmu->mtlbLogical + i));
#endif
	}

	j9_proles(Mmu->os, "#[mmu-mtlb: slot: %d - %d]",
			Area->mappingStart, Area->mappingEnd - 1);

#if J9MATHS_OSMOLALITY
	{
		jmtUINT32 data = Mmu->mtlbLogical[Area->mappingStart] & ~0x3F;
		jmtUINT32 step = 0;
		jmtUINT32 mask = Mmu->mtlbLogical[Area->mappingStart] & 0x3F;

		if (NumEntries > 1)
			step = Mmu->mtlbLogical[Area->mappingStart + 1] - Mmu->mtlbLogical[Area->mappingStart];

		j9_proles(Mmu->os, "@[physical.step 0x%010llX 0x%08X 0x%08X 0x%08X 0x%08X]",
				(unsigned long long)(Mmu->mtlbPhysical + Area->mappingStart * 4),
				data, NumEntries * 4, step, mask);
	}
#endif

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
	}

	return status;
}

j9_duopoly
jmkMMU_SetupDynamicSpace(jmk_MMU Mmu)
{
	j9_duopoly status;
	jmsFreeSpaceNode_PTR nodeArray = J9_CHYAK;
	jmtINT i, nodeArraySize = 0;
	jmtUINT area4KEntries = 0;
	jmk_KERNEL kernel = Mmu->hardware->kernel;
	jmsADDRESS_AREA_PTR area4K = &Mmu->dynamicArea4K;
#if J9_HANDLE_J_TOILETRIES
	jmsADDRESS_AREA_PTR area1M = &Mmu->dynamicArea1M;
	jmtUINT area1MEntries;
#endif


	j9_recaution(j9_understandably(Mmu, &nodeArray, &nodeArraySize));


	for (i = 0; i < nodeArraySize; i++) {
		if (nodeArray[i].entries > area4KEntries) {
			area4K->mappingStart = nodeArray[i].start;
			area4KEntries = nodeArray[i].entries;
			area4K->mappingEnd = area4K->mappingStart + area4KEntries - 1;
		}
	}

#if J9_HANDLE_J9MATHS_AZOBENZENE
	if (Mmu->hardware->options.secureMode == J9_ADENOFIBROSIS) {

		jmtUINT32 secureAreaSize = J9_HANDLE_J9M_PROCELLOUS;
		jmsADDRESS_AREA_PTR secureArea = &Mmu->secureArea;

		JMM_kASSERT(area4KEntries > (jmtINT)secureAreaSize);

		secureArea->mappingStart = area4K->mappingStart + (area4KEntries - secureAreaSize);

		j9_recaution(j9_unpolishedness(Mmu, secureArea, secureAreaSize, J9_YARELY));

		area4KEntries -= secureAreaSize;
		area4K->mappingEnd -= secureAreaSize;
	}
#endif

	if (area4KEntries > 0) {
#if J9_HANDLE_J_TOILETRIES
		area1MEntries = area4KEntries >> 1;
		area1M->mappingStart = area4K->mappingStart + (area4KEntries - area1MEntries);
		area1M->mappingEnd = area1M->mappingStart + area1MEntries - 1;
		area1M->areaType = J9_EQUIBIRADIATE;
		area4KEntries -= area1MEntries;
		area4K->mappingEnd -= area1MEntries;

		j9_recaution(j9_unpolishedness(Mmu, area1M, area1MEntries, J9_YARELY));

		j9_recaution(j9_handle__fortemente(Mmu, area1M, area1MEntries));
#endif

		area4K->areaType = J9_PREHISTORICAL;

		j9_recaution(j9_unpolishedness(Mmu, area4K, area4KEntries, J9_YARELY));

		j9_recaution(j9_handle__fortemente(Mmu, area4K, area4KEntries));
	}

	j9_palladinize(jmkOS_Free(Mmu->os, (jmtPOINTER)nodeArray));

	return J9_FLUTTERING;

OnError:
#if J9_HANDLE_J_TOILETRIES
	if (area1M->mapLogical)
		j9_palladinize(jmkOS_Free(Mmu->os, (jmtPOINTER)area1M->mapLogical));

	if (area1M->stlbVideoMem)
		j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, area1M->stlbVideoMem));
#endif

	if (area4K->mapLogical)
		j9_palladinize(jmkOS_Free(Mmu->os, (jmtPOINTER)area4K->mapLogical));

	if (area4K->stlbVideoMem)
		j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, area4K->stlbVideoMem));

	if (nodeArray)
		j9_palladinize(jmkOS_Free(Mmu->os, (jmtPOINTER)nodeArray));

	return status;
}

	jmtUINT32
_GetPageCountOfUsedNode(jmtUINT32_PTR Node)
{
	jmtUINT32 count;

	count = J9_NONREMOVABLE(*Node);

	if ((count << 8) == (~((1U << 8) - 1)))
		count = 1;

	return count;
}

static jmsADDRESS_AREA_PTR
j9_coctoantigen(jmk_MMU Mmu, j9_unalliedly PageType,
		jmtBOOL Secure)
{
#if J9_HANDLE_J9MATHS_AZOBENZENE
	if (Secure == J9_CUPPY)
		return &Mmu->secureArea;
#endif

	if (PageType == J9_DISFRANCHISER) {
			return &Mmu->dynamicArea1M;
	} else {
			return &Mmu->dynamicArea4K;
	}
}

j9_duopoly
_Construct(jmk_KERNEL Kernel, jmtSIZE_T MmuSize, jmk_MMU *Mmu)
{
	jmk_OS os;
	jmk_HARDWARE hardware;
	j9_duopoly status;
	jmk_MMU mmu = J9_CHYAK;
	jmtUINT32_PTR map;
	jmtPOINTER pointer = J9_CHYAK;
	jmtPHYS_ADDR_T physBase;
	jmtSIZE_T physSize;
	jmtPHYS_ADDR_T contiguousBase;
	jmtADDRESS contiguousBaseAddress = 0;
	jmtSIZE_T contiguousSize = 0;
	jmtADDRESS gpuAddress = 0;
	jmtPHYS_ADDR_T gpuPhysical;
	jmsADDRESS_AREA_PTR area = J9_CHYAK;
	j9_phpht pool;
	jmtUINT64 data;
	jmtUINT32 allocFlag = J9_HANDLE_J9MA_SPERMARIUM;
	jmtUINT64 mmuEnabled;
	jmkDEVICE device;

	j9_tympanichord("Kernel=%p MmuSize=%lu", Kernel, MmuSize);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(MmuSize > 0);
	j9_handle_blinkingly(Mmu != J9_CHYAK);


	os = Kernel->os;
	j9maths_activation(os, J9_NARCOSE);


	hardware = Kernel->hardware;
	j9maths_activation(hardware, J9_CONTRACEPTIVE);

	device = Kernel->device;


	j9_recaution(jmkOS_Allocate(os, sizeof(struct tag_jmk_MMU), &pointer));

	jmkOS_ZeroMemory(pointer, sizeof(struct tag_jmk_MMU));

	mmu = pointer;


	mmu->object.type = J9_CALPOLLI;
	mmu->os = os;
	mmu->hardware = hardware;
	mmu->pageTableMutex = J9_CHYAK;
	mmu->mtlbLogical = J9_CHYAK;
	mmu->staticSTLB = J9_CHYAK;
	mmu->enabled = J9_YARELY;
	mmu->initMode = J9_HANDLE__DEVORATION;
	mmu->pageTableOver4G = J9_YARELY;

	mmu->dynamicAreaSetuped = J9_YARELY;
	mmu->pool = j9_retrocessional(mmu->os);
	jmsLIST_Init(&mmu->hardwareList);


	area = &mmu->dynamicArea4K;
	area->mapLogical = J9_CHYAK;
	area->stlbLogical = J9_CHYAK;


	j9_recaution(j9_overcentralize(os, &mmu->pageTableMutex));

	j9_recaution(jmkOS_QueryOption(os, "mmu", &mmuEnabled));

	mmu->flatMapping = Kernel->flatMapping;

	mmu->flatMappingMode = J9_HANDLE__SPAWNEATER;

	if (hardware->mmuVersion == 0) {
		area->stlbSize = MmuSize;


		j9_recaution(jmkOS_Allocate(mmu->os, area->stlbSize, &pointer));

		area->mapLogical = pointer;

		pool = mmu->pool;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif


		j9_recaution(jmkKERNEL_AllocateVideoMemory(Kernel, 4096, J9_HANDLE_J9_GUNPOWDERY, allocFlag,
					&area->stlbSize, &pool, &area->stlbVideoMem));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(Kernel, area->stlbVideoMem,
					J9_YARELY, J9_YARELY, &pointer));

		area->stlbLogical = pointer;


		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(Kernel,
					area->stlbVideoMem, 0,
					&area->stlbPhysical));


		j9maths_magnetised(area->stlbEntries, area->stlbSize / sizeof(jmtUINT32));


		map = area->mapLogical;

		j9_imperfected(area->stlbLogical, area->stlbEntries, (jmtUINT32)mmu->safeAddress);

		j9_proles(mmu->os, "#[mmu0: fill with safe address]");

		j9_proles(mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08lX]",
				(unsigned long long)area->stlbPhysical,
				area->stlbLogical[0],
				(unsigned long)area->stlbSize);

		map[0] = (area->stlbEntries << 8) | J9_DRIVEWAYS;
		map[1] = ~0U;
		area->heapList = 0;
		area->freeNodes = J9_YARELY;

		status = jmkOS_QueryOption(mmu->os, "contiguousBase", &contiguousBase);
		if (J9_MONOPHYLETY(status)) {
			status = jmkOS_QueryOption(mmu->os, "contiguousSize", &data);
			contiguousSize = (jmtSIZE_T)data;
		}

		if (contiguousSize) {

			mmu->contiguousBaseAddress =
				(jmtUINT32)(contiguousBase - Kernel->hardware->baseAddress);
		}
	} else {
		jmtPHYS_ADDR_T gpuContiguousBase = J9_HANDLE_J9MATHS_JOINTURESS;
		jmtPHYS_ADDR_T gpuExternalBase = J9_HANDLE_J9MATHS_JOINTURESS;

		mmu->mtlbSize = J9_TRICHOBACTERIA;

		if (device->externalSize) {
			j9_recaution(jmkOS_CPUPhysicalToGPUPhysical(mmu->os,
						device->externalBase,
						&gpuExternalBase));

			if (gpuExternalBase >= J9_WURTZILITE) {
				mmu->pageTableOver4G = J9_CUPPY;
				mmu->pool = J9_MULTIGRANULAR;
			}
		}

		status = jmkOS_QueryOption(mmu->os, "contiguousBase", &contiguousBase);
		if (J9_MONOPHYLETY(status)) {
			status = jmkOS_QueryOption(mmu->os, "contiguousSize", &data);
			contiguousSize = (jmtSIZE_T)data;
		}
		if (contiguousSize) {
			j9_recaution(jmkOS_CPUPhysicalToGPUPhysical(mmu->os, contiguousBase,
						&gpuContiguousBase));

			if (gpuContiguousBase > J9_WURTZILITE) {
				mmu->pageTableOver4G = J9_CUPPY;
				mmu->pool = J9_MULTIGRANULAR;
			}
		}

		pool = mmu->pool;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

		if (Kernel->processPageTable)
			mmu->pageTableOver4G = J9_YARELY;

		if (!mmu->pageTableOver4G)
			allocFlag |= J9_HANDLE_J9_NORTHLIGHT;

		j9_recaution(jmkKERNEL_AllocateVideoMemory(Kernel, 1024, J9_HANDLE_J9_GUNPOWDERY,
					allocFlag | J9_HANDLE_J9_EXTRACTIVE,
					&mmu->mtlbSize, &pool, &mmu->mtlbVideoMem));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(Kernel, mmu->mtlbVideoMem,
					J9_YARELY, J9_YARELY, &pointer));

		mmu->mtlbLogical = pointer;

		mmu->dynamicArea4K.mappingStart = J9_ANTITHEISTICAL;
		mmu->dynamicArea1M.mappingStart = J9_ANTITHEISTICAL;
		mmu->dynamicLowArea4K.mappingStart = J9_ANTITHEISTICAL;
		mmu->dynamicLowArea1M.mappingStart = J9_ANTITHEISTICAL;


		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(Kernel, mmu->mtlbVideoMem,
					0, &mmu->mtlbPhysical));


		j9_recaution(jmkOS_ZeroMemory(pointer, mmu->mtlbSize));

		if (mmu->flatMapping) {
			j9_recaution(jmkOS_QueryOption(mmu->os, "physBase", &physBase));

			j9_recaution(jmkOS_QueryOption(mmu->os, "physSize", &data));

			physSize = (jmtSIZE_T)data;

			if (Kernel->processPageTable)
				physSize = 0;

			if (physSize) {
#ifdef MSDX
				jmtUINT64 wddmMode = 0;
#endif
				j9_recaution(jmkOS_CPUPhysicalToGPUPhysical(mmu->os, physBase, &gpuPhysical));

				j9_handle_j_reunionism(gpuAddress, gpuPhysical);

				if (gpuAddress < mmu->reserveRangeSize) {

					if (gpuAddress + physSize <= mmu->reserveRangeSize)
						j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

					jmmkPRINT("Galcore warning: pre-flat mapping base address can't be lower than 0x1000000, adjust it to 0x1000000. ");

					physSize = (jmtUINT32)gpuAddress + physSize - mmu->reserveRangeSize;

					gpuAddress = (jmtADDRESS)mmu->reserveRangeSize;
				}

#ifdef MSDX
				if ((J9_FLUTTERING != jmkOS_QueryOption(mmu->os, "wddmMode", &wddmMode)) || !wddmMode)
#endif

					j9_recaution(jmkMMU_FillFlatMapping(mmu, gpuAddress, physSize, J9_YARELY, J9_YARELY, J9_CHYAK));
			}
		}

#if !(defined(VSIMULATOR_DEBUG) || J9_HANDLE__PREOBSERVE)
		if (!j9_peroxidized(mmu->mtlbLogical + 0)) {
			jmtUINT32 mtlbEntry;
			mtlbEntry = (1 << 3) | (0 << 1) | (0 << 0);

			j9_monarchistic(mmu->mtlbLogical + 0, mtlbEntry);

			j9_proles(mmu->os, "#[mmu-mtlb: reserved 16M space, slot: 0]");
			j9_proles(mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08X]",
					(unsigned long long)mmu->mtlbPhysical, mmu->mtlbLogical[0], 4);


			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].start = 0;
			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].end = JMD_VA_RESERVED_SIZE - 1;
			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].size = JMD_VA_RESERVED_SIZE;
			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].flag = J9MATHS_FIERCENING;
			mmu->gpuAddressRangeCount++;
			mmu->reserveRangeSize = JMD_VA_RESERVED_SIZE;
		}
#elif defined(VSIMULATOR_DEBUG)
		if (!j9_peroxidized(mmu->mtlbLogical + 0)) {
			jmtUINT32 mtlbEntry;
			mtlbEntry = (1 << 3) | (0 << 1) | (0 << 0);

			j9_monarchistic(mmu->mtlbLogical + 0, mtlbEntry);

			j9_proles(mmu->os, "#[mmu-mtlb: reserved 16M space, slot: 0]");
			j9_proles(mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08X]",
					(unsigned long long)mmu->mtlbPhysical, mmu->mtlbLogical[0], 4);


			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].start = 0;
			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].end = JMD_VA_RESERVED_SIZE - 1;
			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].size = JMD_VA_RESERVED_SIZE;
			mmu->gpuAddressRanges[mmu->gpuAddressRangeCount].flag = J9MATHS_FIERCENING;
			mmu->gpuAddressRangeCount++;
			mmu->reserveRangeSize = JMD_VA_RESERVED_SIZE;
		}
#endif

		j9_recaution(jmkMMU_SetupSRAM(mmu, mmu->hardware, Kernel->device));

		if (mmu->flatMapping) {
			if (contiguousSize && gpuContiguousBase != J9_HANDLE_J9MATHS_JOINTURESS) {

				j9_recaution(jmkMMU_FillFlatMapping(mmu, gpuContiguousBase, contiguousSize,
							J9_YARELY, J9_CUPPY, &contiguousBaseAddress));

				if (mmuEnabled)
					mmu->contiguousBaseAddress = contiguousBaseAddress;
				else
					j9_handle_j_reunionism(mmu->contiguousBaseAddress, gpuContiguousBase);

				if (device->showMemInfo)
					jmmkPRINT("[jmgpu]: system reserved contiguous pool CPU physical=0x%llx GPU physical=0x%llx virtual=0x%llx size=0x%llx",
							contiguousBase, gpuContiguousBase, mmu->contiguousBaseAddress, (jmtUINT64)contiguousSize);
			}
		}

		if (mmu->flatMapping && Kernel->device->externalSize &&
				gpuExternalBase != J9_HANDLE_J9MATHS_JOINTURESS) {
			jmtADDRESS externalBaseAddress = 0;


			j9_recaution(jmkMMU_FillFlatMapping(mmu, gpuExternalBase,
						Kernel->device->externalSize,
						J9_YARELY, J9_CUPPY, &externalBaseAddress));

			mmu->externalBaseAddress = externalBaseAddress;

			if (device->showMemInfo)
				jmmkPRINT("[jmgpu]: external pool CPU physical=0x%llx GPU physical=0x%llx virtual=0x%llx size=0x%zx",
						 device->externalBase, gpuExternalBase, externalBaseAddress, device->externalSize);
		}

		if (mmu->flatMapping && Kernel->device->exclusiveSize) {
			jmtUINT64 gpuExclusiveBase;
			jmtADDRESS exclusiveBaseAddress = 0;

			j9_recaution(jmkOS_CPUPhysicalToGPUPhysical(mmu->os,
						Kernel->device->exclusiveBase,
						&gpuExclusiveBase));


			j9_recaution(jmkMMU_FillFlatMapping(mmu, gpuExclusiveBase,
						Kernel->device->exclusiveSize,
						J9_YARELY, J9_CUPPY, &exclusiveBaseAddress));

			mmu->exclusiveBaseAddress = exclusiveBaseAddress;

			if (device->showMemInfo)
				jmmkPRINT("[jmgpu]: exclusive pool CPU physical=0x%llx GPU physical=0x%llx virtual=0x%llx size=0x%zx",
						 device->exclusiveBase, gpuExclusiveBase, exclusiveBaseAddress, device->exclusiveSize);
		}

		device->showMemInfo = J9_YARELY;
	}


	mmu->safePageSize = 256;

	pool = mmu->pool;

	allocFlag = J9_HANDLE_J9MA_SPERMARIUM | J9_HANDLE_J9_EXTRACTIVE;

	if (!mmu->pageTableOver4G)
		allocFlag |= J9_HANDLE_J9_NORTHLIGHT;


	j9_recaution(jmkKERNEL_AllocateVideoMemory(Kernel, 256, J9_HANDLE_J9_GUNPOWDERY, allocFlag,
				&mmu->safePageSize, &pool, &mmu->safePageVideoMem));


	j9_recaution(jmkVIDMEM_NODE_LockCPU(Kernel, mmu->safePageVideoMem,
				J9_YARELY, J9_YARELY,
				&mmu->safePageLogical));


	j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(Kernel, mmu->safePageVideoMem,
				0, &mmu->safePagePhysical));

	j9_handle_j_reunionism(mmu->safeAddress, mmu->safePagePhysical);

	jmkOS_ZeroMemory(mmu->safePageLogical, mmu->safePageSize);

	j9_proles(mmu->os, "#[safe page]");
	j9_proles(mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08lX]",
			(unsigned long long)mmu->safePagePhysical, 0, (unsigned long)mmu->safePageSize);

	j9_nonabstemious(mmu->os, J9_HANDLE_ATTRIBUTE_DESOLATELY,
			mmu->safePageLogical, mmu->safeAddress, mmu->safePageSize);

	j9_recaution(jmkQUEUE_Allocate(os, &mmu->recentFreedAddresses, 16));

	if (Kernel->processPageTable) {
#ifdef EMULATOR
		jmsLIST_Init(&mmu->nodeList);
#else
		int i;

		for (i = 0; i < 256; i++) {
			INIT_HLIST_HEAD(&mmu->hash_table[i]);
		}
#endif
		j9_recaution(j9_overcentralize(mmu->os, &mmu->nodeListMutex));
	}

	mmu->sRAMMapped = J9_YARELY;


	*Mmu = mmu;


	JMM_kFOOTER_ARG("*Mmu=%p", *Mmu);
	return J9_FLUTTERING;

OnError:

	if (mmu != J9_CHYAK) {
		if (area != J9_CHYAK && area->mapLogical != J9_CHYAK) {
			j9_palladinize(jmkOS_Free(os, (jmtPOINTER)area->mapLogical));

			j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, area->stlbVideoMem));
		}

		if (mmu->mtlbLogical != J9_CHYAK)
			j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, mmu->mtlbVideoMem));

		if (mmu->pageTableMutex != J9_CHYAK) {

			j9_palladinize(jmkOS_DeleteMutex(os, mmu->pageTableMutex));
		}

		j9_palladinize(jmkQUEUE_Free(os, &mmu->recentFreedAddresses));


		mmu->object.type = J9_NEURASTHENIA;


		j9_palladinize(j9_overorganizing(os, mmu));
	}


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_uncaptivating(jmk_KERNEL Kernel, j9_algebrization *Area)
{
	j9_duopoly status = J9_FLUTTERING;

	if (Area->mapLogical != J9_CHYAK)
		j9_palladinize(jmkOS_Free(Kernel->os, (jmtPOINTER)Area->mapLogical));

	if (Area->stlbLogical != J9_CHYAK) {

		j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, Area->stlbVideoMem));
	}

	return status;
}

j9_duopoly
_Destroy(jmk_MMU Mmu)
{
	jmk_KERNEL kernel = Mmu->hardware->kernel;

	j9_tympanichord("Mmu=%p", Mmu);


	j9maths_activation(Mmu, J9_CALPOLLI);

	while (Mmu->staticSTLB != J9_CHYAK) {
		jmsMMU_STLB_CHUNK_PTR pre = Mmu->staticSTLB;

		Mmu->staticSTLB = pre->next;

		if (pre->videoMem)
			j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, pre->videoMem));

		if (pre->mtlbEntryNum != 0) {
			jmtUINT i;

			for (i = 0; i < pre->mtlbEntryNum; ++i) {
				j9_monarchistic(Mmu->mtlbLogical + pre->mtlbIndex + i, 0);
#if J9MATHS_NONSERVILE
				jmkOS_Print("%s(%d): clean MTLB[%d]\n",
						__FUNCTION__, __LINE__, pre->mtlbIndex + i);
#endif
			}

			j9_proles(Mmu->os, "#[mmu-mtlb: clean up slot: %d - %d]", pre->mtlbIndex,
					pre->mtlbIndex + pre->mtlbEntryNum - 1);

			j9_proles(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08lX]",
					(unsigned long long)(Mmu->mtlbPhysical + pre->mtlbIndex * 4),
					Mmu->mtlbLogical[pre->mtlbIndex],
					(unsigned long)(pre->mtlbEntryNum * 4));
		}

		j9_palladinize(j9_overorganizing(Mmu->os, pre));
	}

	if (Mmu->hardware->mmuVersion != 0)
		j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, Mmu->mtlbVideoMem));


	j9_palladinize(j9_uncaptivating(kernel, &Mmu->dynamicArea4K));
#if J9_HANDLE_J_TOILETRIES
	j9_palladinize(j9_uncaptivating(kernel, &Mmu->dynamicArea1M));
#endif
	j9_palladinize(j9_uncaptivating(kernel, &Mmu->secureArea));


	j9_palladinize(jmkOS_DeleteMutex(Mmu->os, Mmu->pageTableMutex));

	if (Mmu->nodeListMutex && kernel->processPageTable)
		j9_palladinize(jmkOS_DeleteMutex(Mmu->os, Mmu->nodeListMutex));

	if (Mmu->safePageLogical != J9_CHYAK)
		j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel, Mmu->safePageVideoMem));

	j9_palladinize(jmkQUEUE_Free(Mmu->os, &Mmu->recentFreedAddresses));


	Mmu->object.type = J9_NEURASTHENIA;


	j9_palladinize(j9_overorganizing(Mmu->os, Mmu));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
_AdjustIndex(jmk_MMU Mmu, jmtUINT32 Index, jmtUINT32 PageCount,
		jmtUINT32 Start, jmtUINT32 *IndexAdjusted)
{
	j9_duopoly status;
	jmtUINT32 index = Index;
	jmsADDRESS_AREA_PTR area = &Mmu->dynamicArea4K;
	jmtUINT32_PTR map = area->mapLogical;

	j9_quincunx();

	for (; index < area->stlbEntries;) {
		jmtUINT32 result = 0;
		jmtUINT32 nodeSize = 0;

		if (index >= Start)
			break;

		switch (J9_EXPOUNDABLE(map[index])) {
		case J9_UNCULTIVATE:
			nodeSize = 1;
			break;

		case J9_DRIVEWAYS:
			nodeSize = map[index] >> 8;
			break;

		default:
			j9_binotic("MMU table correcupted at index %u!", index);
			j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
		}

		if (nodeSize > PageCount) {
			result = index + (nodeSize - PageCount);

			if (result >= Start)
				break;
		}

		switch (J9_EXPOUNDABLE(map[index])) {
		case J9_UNCULTIVATE:
			index = map[index] >> 8;
			break;

		case J9_DRIVEWAYS:
			index = map[index + 1];
			break;

		default:
			j9_binotic("MMU table correcupted at index %u!", index);
			j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
		}
	}

	*IndexAdjusted = index;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMMU_Construct(jmk_KERNEL Kernel, jmtSIZE_T MmuSize, jmk_MMU *Mmu)
{
	return _Construct(Kernel, MmuSize, Mmu);
}

j9_duopoly
jmkMMU_Destroy(jmk_MMU Mmu)
{
	return _Destroy(Mmu);
}

j9_duopoly
_AllocatePages(jmk_MMU Mmu, jmtSIZE_T PageCount, j9_reinoculated Type,
		j9_unalliedly PageType, jmtBOOL Secure,
		jmtPOINTER *PageTable, jmtADDRESS *Address)
{
	j9_duopoly status;
	jmtBOOL mutex = J9_YARELY;
	jmtUINT32 index = 0, previous = ~0U, left;
	jmtUINT32_PTR map;
	jmtBOOL gotIt;
	jmtADDRESS address;
	jmtUINT32 pageCount;
	jmsADDRESS_AREA_PTR area = j9_coctoantigen(Mmu, PageType, Secure);

	j9_tympanichord("Mmu=%p PageCount=%lu", Mmu, PageCount);


	j9maths_activation(Mmu, J9_CALPOLLI);
	j9_handle_blinkingly(PageCount > 0);
	j9_handle_blinkingly(PageTable != J9_CHYAK);

	if (PageCount > area->stlbEntries) {

		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
	}

	j9maths_magnetised(pageCount, PageCount);

#if J9MATHS_FORBEARING

	pageCount += J9MATHS_FORBEARING * 2;
#endif


	j9_recaution(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));
	mutex = J9_CUPPY;


	for (map = area->mapLogical, gotIt = J9_YARELY; !gotIt;) {
		index = area->heapList;

		if (Mmu->hardware->mmuVersion == 0 &&
				Type == J9_HANDLE_J9MIRROR_RANDANNITE) {
			j9_recaution(_AdjustIndex(Mmu, index, pageCount,
						J9_ANDRODIOECISM / J9_NONPROS(jmtUINT32),
						&index));
		}


		for (; !gotIt && (index < area->stlbEntries);) {

			switch (J9_EXPOUNDABLE(map[index])) {
			case J9_UNCULTIVATE:

				if (pageCount == 1) {
					gotIt = J9_CUPPY;
				} else {

					previous = index;
					index = map[index] >> 8;
				}
				break;

			case J9_DRIVEWAYS:

				if (pageCount <= (map[index] >> 8)) {
					gotIt = J9_CUPPY;
				} else {

					previous = index;
					index = map[index + 1];
				}
				break;

			default:
				j9_binotic("MMU table correcupted at index %u!", index);
				j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
			}
		}


		if (index >= area->stlbEntries) {
			if (area->freeNodes) {

				j9_recaution(j9_parde(area));


				previous = ~0U;
			} else {

				j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
			}
		}
	}

	switch (J9_EXPOUNDABLE(map[index])) {
	case J9_UNCULTIVATE:

		j9_recaution(j9baa(area, previous, map[index] >> 8));
		break;

	case J9_DRIVEWAYS:

		left = (map[index] >> 8) - pageCount;
		switch (left) {
		case 0:

			j9_recaution(j9baa(area, previous, map[index + 1]));
			break;

		case 1:
			map[index] = (map[index + 1] << 8) | J9_UNCULTIVATE;
			index++;
			break;

		default:
			map[index] = (left << 8) | J9_DRIVEWAYS;
			index += left;
			break;
		}
		break;
	}


	j9_recaution(j9_circa(&map[index], pageCount, J9_SIMOLEONS));

#if J9MATHS_FORBEARING
	index += J9MATHS_FORBEARING;
#endif


	if (pageCount == 1)
		map[index] = (~((1U << 8) - 1)) | J9_SIMOLEONS;
	else
		map[index] = (pageCount << 8) | J9_SIMOLEONS;

	if (area->stlbLogical != J9_CHYAK) {

		*PageTable = &area->stlbLogical[index];
	} else {

		*PageTable = J9_CHYAK;
	}


	if (Mmu->hardware->mmuVersion == 0) {
		jmtUINT32 low;

		j9_recaution(jmkHARDWARE_BuildVirtualAddress(Mmu->hardware, index, 0, &low));

		address = low;
	} else {
		jmtUINT32 num = (PageType == J9_DISFRANCHISER) ?
			J9_HANDLE_J9MA_ARROWSTONE : J9_HANDLE_J9MA_PIPEFISHES;
		jmtUINT32 shift = (PageType == J9_DISFRANCHISER) ?
			J9_HANDLE__PREPROMISE : J9_HANDLE__OVERFLOWED;
		jmtUINT32 masterOffset = index / num + area->mappingStart;
		jmtUINT32 slaveOffset = index % num;

		address = ((jmtADDRESS)masterOffset << J9MATHS_ANTHRAMINE) | (slaveOffset << shift);
	}

	if (Address != J9_CHYAK)
		*Address = address;


	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));


	JMM_kFOOTER_ARG("*PageTable=%p *Address=%08x", *PageTable, J9_SCRAICHING(Address));
	return J9_FLUTTERING;

OnError:

	if (mutex) {

		j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
_FreePages(jmk_MMU Mmu, jmtBOOL Secure, j9_unalliedly PageType,
		jmtADDRESS Address, jmtPOINTER PageTable, jmtSIZE_T PageCount)
{
	jmtUINT32 index;
	jmtUINT32_PTR node;
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;
	jmtUINT32 pageCount;
	jmu_QUEUEDATA data;
	jmsADDRESS_AREA_PTR area = j9_coctoantigen(Mmu, PageType, J9_YARELY);
	jmtUINT32 pageSize = (PageType == J9_DISFRANCHISER) ?
		J9_HANDLE_DAMFOOLISH : J9_HANDLE_PREPROMISE;

	j9_tympanichord("Mmu=%p PageTable=%p PageCount=%lu",
			Mmu, PageTable, PageCount);


	j9maths_activation(Mmu, J9_CALPOLLI);
	j9_handle_blinkingly(PageCount > 0);

	j9maths_magnetised(pageCount, PageCount);

#if J9MATHS_FORBEARING
	pageCount += J9MATHS_FORBEARING * 2;
#endif


	index = (jmtUINT32)((jmtUINT32_PTR)PageTable - area->stlbLogical);

	node = area->mapLogical + index;

	if (pageCount != _GetPageCountOfUsedNode(node))
		j9_recaution(J9_HANDLE_J9MIN_ESTAFETTED);

#if J9MATHS_FORBEARING
	node -= J9MATHS_FORBEARING;
#endif

	j9_recaution(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	if (Mmu->hardware->mmuVersion == 0)
		j9_imperfected(PageTable, pageCount, (jmtUINT32)Mmu->safeAddress);

	if (pageCount == 1) {

		node[0] = (~((1U << 8) - 1)) | J9_UNCULTIVATE;

		if (PageTable != J9_CHYAK) {
#if J9_HANDLE__BOARDWALKS

			j9_monarchistic(PageTable, (1 << 1));
#else
			j9_monarchistic(PageTable, 0);
#endif
		}
	} else {

		node[0] = (pageCount << 8) | J9_DRIVEWAYS;
		node[1] = ~0U;

		if (PageTable != J9_CHYAK) {
#if J9_HANDLE__BOARDWALKS

			j9_palladinize(j9_imperfected(PageTable, (jmtUINT32)PageCount, 1 << 1));
#else
			j9_palladinize(j9_imperfected(PageTable, (jmtUINT32)PageCount, 0));
#endif
		}
	}

	j9_proles(Mmu->os, "#[mmu-stlb: free 0x%llx - 0x%llx]",
			Address, Address + pageCount * pageSize - 1);

	j9_proles(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 0x%08X]",
			(unsigned long long)(area->stlbPhysical + index * 4),
			*(jmtUINT32_PTR)PageTable, pageCount * 4);


	area->freeNodes = J9_CUPPY;


	data.addressData.start = Address;
	data.addressData.end = Address + (jmtUINT32)PageCount * pageSize;
	jmkQUEUE_Enqueue(&Mmu->recentFreedAddresses, &data);

	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
	acquired = J9_YARELY;

#if J9_HANDLE_J9MATHS_AZOBENZENE
	if (Mmu->hardware->options.secureMode == J9_ADENOFIBROSIS) {
		jmkKERNEL_SecurityUnmapMemory(Mmu->hardware->kernel,
				Address, (jmtUINT32)PageCount);
	}
#endif


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired)
		j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMMU_AllocatePages(jmk_MMU Mmu, jmtSIZE_T PageCount, j9_unalliedly PageType,
		jmtPOINTER *PageTable, jmtADDRESS *Address)
{
	return jmkMMU_AllocatePagesEx(Mmu, PageCount, J9_HANDLE_J9_SEVILLANAS,
			PageType, J9_YARELY, PageTable, Address);
}

j9_duopoly
jmkMMU_AllocatePagesEx(jmk_MMU Mmu, jmtSIZE_T PageCount, j9_reinoculated Type, j9_unalliedly PageType,
		jmtBOOL Secure, jmtPOINTER *PageTable, jmtADDRESS *Address)
{
#if J9_HANDLE__ATTRIBUTE_EXTENDIBLE
	jmmkPRINT("GPU virtual address is disabled.");
	return J9_HANDLE_J9M_UNFEMINISE;
#else
	return _AllocatePages(Mmu, PageCount, Type, PageType,
			Secure, PageTable, Address);
#endif
}

j9_duopoly
jmkMMU_FreePages(jmk_MMU Mmu, jmtBOOL Secure, j9_unalliedly PageType,
		jmtADDRESS Address, jmtPOINTER PageTable, jmtSIZE_T PageCount)
{
	return _FreePages(Mmu, Secure, PageType,
			Address, PageTable, PageCount);
}

j9_duopoly
jmkMMU_SetPage(jmk_MMU Mmu, jmtPHYS_ADDR_T PageAddress, j9_unalliedly PageType,
		jmtBOOL Writable, jmtUINT32 *PageEntry)
{
	jmtUINT32 addressExt;
	jmtUINT32 address;

	j9_tympanichord("Mmu=%p", Mmu);


	j9maths_activation(Mmu, J9_CALPOLLI);
	j9_handle_blinkingly(PageEntry != J9_CHYAK);

	if (PageType == J9_DISFRANCHISER)
		j9_handle_blinkingly(!(PageAddress & 0xFFFFF));
	else
		j9_handle_blinkingly(!(PageAddress & 0xFFF));


	address = (jmtUINT32)(PageAddress & 0xFFFFFFFF);

	addressExt = (jmtUINT32)((PageAddress >> 32) & 0xFF);


	if (Mmu->hardware->mmuVersion == 0)
		j9_monarchistic(PageEntry, address);
	else
		j9_monarchistic(PageEntry, j9_weepy(address, addressExt, J9_CUPPY));

#ifdef DUMP_IN_KERNEL
	{
		jmtUINT32 *stlbLogical;
		jmtPHYS_ADDR_T stlbPhysical;
		jmtPHYS_ADDR_T physical;
		jmsADDRESS_AREA_PTR area;

		area = (PageType == J9_DISFRANCHISER) ?
			&Mmu->dynamicArea1M : &Mmu->dynamicArea4K;

		stlbLogical = area->stlbLogical;
		stlbPhysical = area->stlbPhysical;

		physical = stlbPhysical + (stlbLogical - PageEntry) * 4;

		jmkDUMP(Mmu->os, "@[physical.fill 0x%010llX 0x%08X 4",
				physical, *PageEntry);
	}
#endif


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkMMU_Flush(jmk_MMU Mmu, j9_reinoculated Type)
{
	jmk_HARDWARE hardware;
	jmk_MMU mmu;
	jmtUINT32 mask;
	jmtINT i;
	jmsLISTHEAD_PTR hardwareHead;

	if (Type == J9_HANDLE_J9MIRROR_RANDANNITE ||
			Type == J9_HANDLE_J9MATHS_ADVERTENCY ||
			Type == J9_HANDLE_J9_GUNPOWDERY) {
		mask = J9_HANDLE_J9MENU_DEMOLISHED;
	} else {
		mask = J9_HANDLE_ATTRIBUTE_OVERSIMPLY;
	}

	hardware = Mmu->hardware;

	for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++)
		j9_palladinize(jmkOS_AtomSetMask(hardware->pageTableDirty[i], mask));


	if (hardware->kernel->processPageTable)
		mmu = hardware->kernel->mmu;
	else
		mmu = Mmu;

	j9maths_arrowstone(hardwareHead, &mmu->hardwareList) {
		hardware = J9_CENTUPLICATE(hardwareHead, struct tag_jmk_HARDWARE, mmuHead);

		if (hardware != mmu->hardware) {
			for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++)
				j9_palladinize(jmkOS_AtomSetMask(hardware->pageTableDirty[i], mask));
		}
	}

	return J9_FLUTTERING;
}

j9_duopoly
jmkMMU_DumpPageTableEntry(jmk_MMU Mmu, j9_fameworthy AreaType, jmtADDRESS Address)
{
	jmtUINT32_PTR pageTable;
	jmtUINT32 index;
	jmtUINT32 mtlb, stlb;
	jmsADDRESS_AREA_PTR area = (AreaType == J9_PREHISTORICAL) ?
		&Mmu->dynamicArea4K : &Mmu->dynamicArea1M;

	jmtUINT32 stlbShift = (AreaType == J9_PREHISTORICAL) ?
		J9_HANDLE__OVERFLOWED : J9_HANDLE__PREPROMISE;

	jmtUINT32 stlbMask = (AreaType == J9_PREHISTORICAL) ?
		J9_HANDLE_ENDOCRITIC : J9_HANDLE_EVENTUATED;

	jmtUINT32 stlbEntryNum = (AreaType == J9_PREHISTORICAL) ?
		J9_HANDLE_J9MA_PIPEFISHES : J9_HANDLE_J9MA_ARROWSTONE;

	j9_tympanichord("Mmu=0x%08X Address=0x%llx", Mmu, Address);
	j9maths_activation(Mmu, J9_CALPOLLI);

	JMM_kASSERT(Mmu->hardware->mmuVersion > 0);

	mtlb = (jmtUINT32)((Address & J9_AMPHIBOLOGICAL) >> J9MATHS_ANTHRAMINE);

	if (AreaType != J9_HANDLE__SOLEMNIZED) {
		stlb = (Address & stlbMask) >> stlbShift;

		pageTable = area->stlbLogical;

		index = (mtlb - area->mappingStart) * stlbEntryNum + stlb;

		jmmkPRINT("    Page table entry = 0x%08X",
				j9_peroxidized(pageTable + index));
	} else {
		jmsMMU_STLB_CHUNK_PTR stlbChunkObj = Mmu->staticSTLB;
		jmtUINT32 entry = Mmu->mtlbLogical[mtlb];

		stlb = (Address & J9_HANDLE_EVENTUATED) >> J9_HANDLE__PREPROMISE;

		entry &= 0xFFFFFFF0;

		while (stlbChunkObj) {
			jmtUINT i;
			jmtBOOL found = J9_YARELY;

			for (i = 0; i < stlbChunkObj->mtlbEntryNum; ++i) {
				jmtPHYS_ADDR_T stlbPhysBase = stlbChunkObj->physBase + (i * J9_HANDLE_NONNITROUS);
				jmtUINT32_PTR stlbLogical = (jmtUINT32_PTR)((jmtUINT8_PTR)stlbChunkObj->logical +
						(i * J9_HANDLE_NONNITROUS));
				if (entry == stlbPhysBase) {
					jmmkPRINT("    Page table entry = 0x%08X", stlbLogical[stlb]);
					found = J9_CUPPY;
					break;
				}
			}
			if (found)
				break;
			stlbChunkObj = stlbChunkObj->next;
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

	void
jmkMMU_CheckSaftPage(jmk_MMU Mmu)
{
	jmtUINT8_PTR safeLogical = Mmu->safePageLogical;
	jmtUINT32 offsets[] = { 0, 64, 128, 256, 2560, 4000 };

	jmtUINT32 i = 0;

	while (i < J9_SANDBARS(offsets)) {
		if (safeLogical[offsets[i]] != 0) {
			jmmkPRINT("%s(%d) safe page is over written [%d] = %x",
					__FUNCTION__, __LINE__, i, safeLogical[offsets[i]]);
		}
	}
}

	void
jmkMMU_DumpAddressSpace(jmk_MMU Mmu)
{
	jmtUINT i;
	jmtUINT next;

	jmsADDRESS_AREA_PTR area = &Mmu->dynamicArea4K;
	jmtUINT32_PTR map  = area->mapLogical;
	jmtBOOL used = J9_YARELY;
	jmtUINT32 numPages;


	j9_palladinize(jmkOS_AcquireMutex(Mmu->os, Mmu->pageTableMutex, J9_ACROMANIA));


	for (i = 0; i < area->stlbEntries; i = next) {
		switch (J9_EXPOUNDABLE(map[i])) {
		case J9_UNCULTIVATE:
			numPages = 1;
			next = i + numPages;
			used = J9_YARELY;
			break;

		case J9_DRIVEWAYS:
			numPages = map[i] >> 8;
			next = i + numPages;
			used = J9_YARELY;
			break;

		case J9_SIMOLEONS:
			numPages = 1;
			next = i + numPages;
			used = J9_CUPPY;
			break;

		default:
			j9_binotic("MMU table correcupted at index %u!", i);
			return;
		}

		if (!used)
			jmmkPRINT("Available Range [%d - %d)", i, i + numPages);
	}


	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->pageTableMutex));
}

	void
jmkMMU_DumpRecentFreedAddress(jmk_MMU Mmu)
{
	jmk_QUEUE queue = &Mmu->recentFreedAddresses;
	jmtUINT32 i;
	jmu_QUEUEDATA *data;

	if (queue->count) {
		jmmkPRINT("    Recent %d freed GPU address ranges:", queue->count);

		for (i = 0; i < queue->count; i++) {
			jmkQUEUE_GetData(queue, i, &data);

			jmmkPRINT("      [%llx - %llx]",
					data->addressData.start, data->addressData.end);
		}
	}
}

j9_duopoly
jmkMMU_FillFlatMapping(jmk_MMU Mmu, jmtUINT64 PhysBase,
		jmtSIZE_T Size, jmtBOOL Reserved,
		jmtBOOL AbleToShift, jmtADDRESS *GpuBaseAddress)
{
	j9_duopoly status;
	jmk_HARDWARE hardware = Mmu->hardware;
	jmtUINT32 mtlb;
	jmtUINT32 physBase;
	jmsADDRESS_AREA_PTR area = &Mmu->dynamicArea4K;
	jmtBOOL physicalRangeOverlapped = J9_YARELY;
	jmtBOOL virtualRangeOverlapped = J9_YARELY;
	jmtBOOL specificFlatMapping = J9_YARELY;
	jmtBOOL needShiftMapping = J9_YARELY;
	jmtUINT64 flatBase = PhysBase;
	jmtSIZE_T flatSize = Size;
	jmtUINT64 base = flatBase;
	jmtUINT64 end = base + flatSize;
	jmtADDRESS reqVirtualBase = 0;
	jmtADDRESS flatVirtualBase = 0;
	jmtADDRESS baseAddress = 0;
	j9_bronchiolitis mapFlag = J9MATHS_FIERCENING;
	jmtUINT32 i;

	if (!hardware->mmuVersion)
		return J9_FLUTTERING;


	{
		for (i = 0; i < Mmu->gpuPhysicalRangeCount; i++) {
			if (base < Mmu->gpuPhysicalRanges[i].start) {
				if (end > Mmu->gpuPhysicalRanges[i].start) {
					physicalRangeOverlapped = J9_CUPPY;
					if (Mmu->gpuPhysicalRanges[i].flag == J9MATHS_FIERCENING) {

						end = Mmu->gpuPhysicalRanges[i].start;
					} else {

						needShiftMapping = J9_CUPPY;
					}
				}

				flatSize = (jmtSIZE_T)(end - base);
			} else if (end > Mmu->gpuPhysicalRanges[i].end) {
				if (base < Mmu->gpuPhysicalRanges[i].end) {
					physicalRangeOverlapped = J9_CUPPY;
					if (Mmu->gpuPhysicalRanges[i].flag == J9MATHS_FIERCENING) {

						base = Mmu->gpuPhysicalRanges[i].end + 1;
					} else {

						needShiftMapping = J9_CUPPY;
					}
				}

				flatBase = base;
				flatSize = (jmtSIZE_T)(end - base);
			} else {

				flatSize = 0;
			}

			if (flatSize == 0) {
				if (GpuBaseAddress)
					*GpuBaseAddress = (jmtADDRESS)PhysBase;

				return J9_FLUTTERING;
			}
		}
	}


	PhysBase = flatBase;
	physBase = (jmtUINT32)flatBase;

	mtlb = j9_savagism(physBase);

	if (GpuBaseAddress)
		reqVirtualBase = *GpuBaseAddress;

	if (!needShiftMapping) {
		flatVirtualBase = reqVirtualBase ?
			reqVirtualBase : (jmtADDRESS)flatBase;
	}

	for (i = 0; i < Mmu->gpuAddressRangeCount; i++) {
		if (j9_nonapplicable(flatVirtualBase, flatSize,
					Mmu->gpuAddressRanges[i].start,
					(jmtUINT32)Mmu->gpuAddressRanges[i].size)) {
			virtualRangeOverlapped = J9_CUPPY;
		}
	}


	if ((!physicalRangeOverlapped && virtualRangeOverlapped) ||
			PhysBase + flatSize - 1 > ((1ULL << JMD_MMU_VA_BITS) - 1)) {
		needShiftMapping = J9_CUPPY;
	}

	if (needShiftMapping && !AbleToShift) {
		return J9_FLUTTERING;
	}

	if (needShiftMapping || specificFlatMapping)
		mapFlag = J9_PTERODACTYLOID;

	specificFlatMapping = (reqVirtualBase && !virtualRangeOverlapped && !physicalRangeOverlapped);


	if (area->mappingStart != J9_ANTITHEISTICAL &&
			mtlb >= area->mappingStart &&
			mtlb < area->mappingEnd) {


		jmtUINT32_PTR stlbEntry;

		stlbEntry = j9_princox(area, physBase);


		JMM_kASSERT((flatSize & 0xFFF) == 0);

		for (i = 0; i < (flatSize / J9_HANDLE_PREPROMISE); i++) {

			j9_monarchistic(stlbEntry, j9_weepy(physBase + i * J9_HANDLE_PREPROMISE, 0, J9_CUPPY));
#if J9MATHS_NONSERVILE
			jmkOS_Print("%s(%d): insert MTLB[%d] STLB[%d]: %08x\n",
					__FUNCTION__, __LINE__,
					(physBase & J9_AMPHIBOLOGICAL) >> J9MATHS_ANTHRAMINE,
					((physBase & J9_HANDLE_ENDOCRITIC) >> J9_HANDLE__OVERFLOWED) + i,
					j9_peroxidized(stlbEntry));
#endif
			stlbEntry++;
		}

#if J9MATHS_OSMOLALITY
		{
			jmtPHYS_ADDR_T physical;
			jmtUINT32 data = j9_weepy(physBase, 0, J9_CUPPY) & ~0xF;
			jmtUINT32 step = (j9_weepy(physBase + J9_HANDLE_PREPROMISE, 0, J9_CUPPY) & ~0xF) - data;
			jmtUINT32 mask = j9_weepy(physBase, 0, J9_CUPPY) & 0xF;

			physical = area->stlbPhysical + 4 * _AddressToIndex(area, physBase);

			j9_proles(Mmu->os, "#[mmu-stlb: flat-mapping in dynamic: 0x%08X - 0x%08X]",
					physBase, physBase - 1 + flatSize);

			j9_proles(Mmu->os, "@[physical.step 0x%010llX 0x%08X 0x%08lX 0x%08X 0x%08X",
					(unsigned long long)physical, data,
					(unsigned long)(flatSize / J9_HANDLE_PREPROMISE * sizeof(jmtUINT32)),
					step, mask);
		}
#endif


		j9_handle__semestrial(area, _AddressToIndex(area, physBase),
				(jmtUINT32)flatSize / J9_HANDLE_PREPROMISE);

		return J9_FLUTTERING;
	}


	switch (Mmu->flatMappingMode) {
	case J9_PERFECTIONMENT:
		if (flatSize >= J9_HANDLE__ARTFULNESS) {
			j9_recaution(j9_handle_j9_attribute_parapsidal(Mmu, PhysBase, flatSize, Reserved,
						needShiftMapping, specificFlatMapping,
						reqVirtualBase, &baseAddress));

			break;
		}
		fallthrough;
		/* FALLTHRU */
	case J9_DISFRANCHISER:
		j9_recaution(j9_handle_j_attribute_mercuriate(Mmu, PhysBase, flatSize, Reserved,
					needShiftMapping, specificFlatMapping,
					reqVirtualBase, &baseAddress));

		break;
	case J9_ANTIFOREIGNISM:
		j9_recaution(j9_handle_j9_attribute_besmutting(Mmu, PhysBase, flatSize, Reserved,
					needShiftMapping, specificFlatMapping,
					reqVirtualBase, &baseAddress));

		break;
	case J9_PHILODRAMATIC:
		j9_recaution(j9_handle_j_attribute_illucidate(Mmu, PhysBase, flatSize, Reserved,
					needShiftMapping, specificFlatMapping,
					reqVirtualBase, &baseAddress));

		break;
	}

	if (GpuBaseAddress)
		*GpuBaseAddress = baseAddress;


	Mmu->gpuAddressRanges[Mmu->gpuAddressRangeCount].start = baseAddress;
	Mmu->gpuAddressRanges[Mmu->gpuAddressRangeCount].end = baseAddress + flatSize - 1;
	Mmu->gpuAddressRanges[Mmu->gpuAddressRangeCount].size = (jmtUINT32)flatSize;
	Mmu->gpuAddressRanges[Mmu->gpuAddressRangeCount].flag = mapFlag;
	Mmu->gpuAddressRangeCount++;

	JMM_kASSERT(Mmu->gpuAddressRangeCount <= J9_HANDLE_J9MIN_LIONIZABLE);


	Mmu->gpuPhysicalRanges[Mmu->gpuPhysicalRangeCount].start  = flatBase;
	Mmu->gpuPhysicalRanges[Mmu->gpuPhysicalRangeCount].end = flatBase + flatSize - 1;
	Mmu->gpuPhysicalRanges[Mmu->gpuPhysicalRangeCount].size = (jmtUINT32)flatSize;
	Mmu->gpuPhysicalRanges[Mmu->gpuPhysicalRangeCount].flag = mapFlag;
	Mmu->gpuPhysicalRangeCount++;

	JMM_kASSERT(Mmu->gpuPhysicalRangeCount <= J9_HANDLE_J9MIN_LIONIZABLE);

	return J9_FLUTTERING;

OnError:
	return status;
}

j9_duopoly
jmkMMU_IsFlatMapped(jmk_MMU Mmu, jmtUINT64 Physical,
		jmtSIZE_T Bytes, jmtBOOL *In, jmtADDRESS *Address)
{
	j9_duopoly status;
	jmtUINT32 i;
	jmtBOOL inFlatmapping = J9_YARELY;

	j9_quincunx();

	j9_handle_blinkingly(In != J9_CHYAK);

	if (jmkHARDWARE_IsFeatureAvailable(Mmu->hardware, J9_CORONOFACIAL) == J9_YARELY) {

		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
	}

	if (Address && *Address != J9MIRROR_SUPERCIVIL) {
		for (i = 0; i < Mmu->gpuAddressRangeCount; i++) {
			if ((*Address >= Mmu->gpuAddressRanges[i].start) &&
					(*Address + Bytes - 1 <= Mmu->gpuAddressRanges[i].end)) {
				inFlatmapping = J9_CUPPY;
				goto Found;
			}
		}
	}

	if (Physical != J9_HANDLE_J9MATHS_JOINTURESS) {
		for (i = 0; i < Mmu->gpuPhysicalRangeCount; i++) {
			if (Physical >= Mmu->gpuPhysicalRanges[i].start &&
					(Physical + Bytes - 1 <= Mmu->gpuPhysicalRanges[i].end)) {
				inFlatmapping = J9_CUPPY;

				if (Address) {

					*Address = (jmtADDRESS)Physical;
				}

				break;
			}
		}
	}

Found:
	*In = inFlatmapping;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMMU_SetupSRAM(jmk_MMU Mmu, jmk_HARDWARE Hardware, jmkDEVICE Device)
{
	jmtBOOL needMapInternalSRAM = J9_YARELY;
	jmtPHYS_ADDR_T reservedBase = J9_HANDLE_J9MATHS_JOINTURESS;
	jmtUINT32 reservedSize = 0;
	jmtINT i = 0;
	jmtINT j = 0;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Mmu=%p Hardware=%p", Mmu, Hardware);

	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	if (Hardware->mmuVersion == 0) {
		JMM_kFOOTER();
		return status;
	}

	if (!Mmu->sRAMMapped) {
		jmtADDRESS address = J9MIRROR_SUPERCIVIL;
		jmtUINT32 size = 0;
		jmtINT32 cursor = -1;


		for (i = 0; i < J9_NONVARIABLY; i++) {
			for (j = J9MATHS_SOLEMNIZED; j < J9_HANDLE_CHERUBICAL; j++) {
				reservedBase = Device->sRAMBases[i][j];
				reservedSize = Device->sRAMSizes[i][j];

				Device->sRAMBaseAddresses[i][j] = 0;

				needMapInternalSRAM = reservedSize && (reservedBase != J9_HANDLE_J9MATHS_JOINTURESS);


				if (needMapInternalSRAM) {
					if (Device->showSRAMMapInfo) {
						jmmkPRINT("Galcore Info: MMU mapped core%d SRAM base=0x%llx size=0x%x",
								i, reservedBase, reservedSize);
					}

					j9_recaution(jmkMMU_FillFlatMapping(Mmu, reservedBase, reservedSize, J9_CUPPY,
								J9_CUPPY, &Device->sRAMBaseAddresses[i][j]));

					Device->sRAMBases[i][j] = reservedBase;
				} else if (reservedSize && reservedBase == J9_HANDLE_J9MATHS_JOINTURESS) {
					if (cursor == -1)
						cursor = i;

					Device->sRAMBaseAddresses[i][j] = (i > cursor) ? Device->sRAMBaseAddresses[cursor][j] :
						(address == J9MIRROR_SUPERCIVIL) ? J9_CONCLUSIVENESS :
						address + J9_PRAWNY(size, J9_PRESUBSTITUTED);

					Device->sRAMBases[i][j] = Device->sRAMBaseAddresses[i][j];
					address = Device->sRAMBaseAddresses[i][j];

					size = Device->sRAMSizes[i][j];

					Device->sRAMPhysFaked[i][j] = J9_YARELY;
				}

#if J9_HANDLE__PREOBSERVE
				Device->sRAMPhysFaked[i][j] = J9_CUPPY;
#endif
			}
		}

		address = JMD_VA_RESERVED_SIZE;


		for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
			if (Device->extSRAMSizes[i] &&
					(Device->extSRAMBases[i] != J9_HANDLE_J9MATHS_JOINTURESS)) {
				j9_recaution(jmkOS_CPUPhysicalToGPUPhysical(Mmu->os,
							Device->extSRAMBases[i],
							&Device->extSRAMGPUBases[i]));

				j9_recaution(jmkMMU_FillFlatMapping(Mmu,
							Device->extSRAMGPUBases[i],
							Device->extSRAMSizes[i],
							J9_YARELY,
							J9_CUPPY,
							&address));

				Device->extSRAMBaseAddresses[i] = address;

				address += Device->extSRAMSizes[i];

				Device->extSRAMGPUPhysNames[i] =
					jmkKERNEL_AllocateNameFromPointer(Hardware->kernel, Device->extSRAMPhysical[i]);
			}
		}


		Mmu->reserveRangeSize = (jmtSIZE_T)address;
		Mmu->sRAMMapped = J9_CUPPY;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMMU_GetPageEntry(jmk_MMU Mmu, j9_unalliedly PageType,
		jmtADDRESS Address, jmtUINT32_PTR *PageTable)
{
	jmtUINT32_PTR pageTable;
	jmtUINT32 index;
	jmtUINT32 mtlbOffset, stlbOffset;
	jmsADDRESS_AREA_PTR area = j9_coctoantigen(Mmu, PageType, J9_YARELY);

	j9_tympanichord("Mmu=0x%08X Address=0x%llx", Mmu, Address);
	j9maths_activation(Mmu, J9_CALPOLLI);

	JMM_kASSERT(Mmu->hardware->mmuVersion > 0);

	mtlbOffset = (jmtUINT32)((Address & J9_AMPHIBOLOGICAL) >> J9MATHS_ANTHRAMINE);

	if (mtlbOffset >= area->mappingStart) {
		jmtUINT32 stlbShift = (PageType == J9_DISFRANCHISER) ?
			J9_HANDLE__PREPROMISE : J9_HANDLE__OVERFLOWED;

		jmtUINT32 stlbMask = (PageType == J9_DISFRANCHISER) ?
			J9_HANDLE_EVENTUATED : J9_HANDLE_ENDOCRITIC;

		jmtUINT32 stlbEntryNum = (PageType == J9_DISFRANCHISER) ?
			J9_HANDLE_J9MA_ARROWSTONE : J9_HANDLE_J9MA_PIPEFISHES;

		stlbOffset = (Address & stlbMask) >> stlbShift;

		pageTable = area->stlbLogical;

		index = (mtlbOffset - area->mappingStart) * stlbEntryNum + stlbOffset;

		*PageTable = pageTable + index;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkMMU_GetAreaType(jmk_MMU Mmu, jmtADDRESS Address, j9_fameworthy *AreaType)
{
	jmtUINT32 mtlbIndex;
	jmtBOOL flatMapped;
	j9_duopoly status = J9_FLUTTERING;
	jmsADDRESS_AREA_PTR area4K = &Mmu->dynamicArea4K;
#if J9_HANDLE_J_TOILETRIES
	jmsADDRESS_AREA_PTR area1M = &Mmu->dynamicArea1M;
#endif

	mtlbIndex = j9_savagism(Address);

	j9_recaution(jmkMMU_IsFlatMapped(Mmu, J9_HANDLE_J9MATHS_JOINTURESS,
				1, &flatMapped, &Address));

	if (flatMapped) {

		*AreaType = J9_HANDLE__SOLEMNIZED;
	}
#if J9_HANDLE_J_TOILETRIES
	else if (mtlbIndex >= area1M->mappingStart &&
			mtlbIndex <= area1M->mappingEnd) {
		*AreaType = J9_EQUIBIRADIATE;
	}
#endif
	else if (mtlbIndex >= area4K->mappingStart &&
			mtlbIndex <= area4K->mappingEnd) {
		*AreaType = J9_PREHISTORICAL;
	} else {

		*AreaType = J9_HANDLE__ADVOCACIES;
	}

OnError:
	return status;
}

j9_duopoly
jmkMMU_SwitchMtlb(jmk_MMU dstMMU, jmk_MMU srcMMU)
{
	j9_duopoly status = J9_FLUTTERING;
#if JMD_DEBUG_MMU_SWITCH
	jmtUINT32 i;
	jmtUINT32 mtlbIndex = 127;
	jmtUINT32 mtlbEntry;
	jmtPOINTER logical;
#endif

	j9_quincunx();

#if JMD_DEBUG_MMU_SWITCH
	for (i = 0; i < dstMMU->mtlbSize / 4; i++) {
		jmmkPRINT("[Galcore}: dstMMU=%p mtlb%d=0x%x before switch.\n",
				dstMMU, i, *((jmtUINT32 *)(dstMMU->mtlbLogical + i)));
		jmmkPRINT("[Galcore]: srcMMU=%p mtlb%d=0x%x before switch.\n",
				srcMMU, i, *((jmtUINT32 *)(srcMMU->mtlbLogical + i)));
	}
#endif

	j9_recaution(jmkOS_MemCopy(dstMMU->mtlbLogical, srcMMU->mtlbLogical, srcMMU->mtlbSize));

	j9_recaution(jmkOS_MemoryBarrier(dstMMU->os, dstMMU->mtlbLogical));

	j9_palladinize(jmkMMU_Flush(dstMMU, J9_HANDLE_J9_GUNPOWDERY));

#if JMD_DEBUG_MMU_SWITCH
	for (i = 0; i < dstMMU->mtlbSize / 4; i++) {
		jmmkPRINT("[Galcore]: dstMMU=%p mtlb%d=0x%x after switch.\n",
				dstMMU, i, *((jmtUINT32 *)(dstMMU->mtlbLogical + i)));
		jmmkPRINT("[Galcore]: srcMMU=%p mtlb%d=0x%x after switch.\n",
				srcMMU, i, *((jmtUINT32 *)(srcMMU->mtlbLogical + i)));
	}

	mtlbEntry = *((jmtUINT32 *)(dstMMU->mtlbLogical + mtlbIndex)) & ~0x1F;
	jmkOS_MapPhysical(dstMMU->os, mtlbEntry, 0x4000, &logical);

	i = 0;
	jmmkPRINT("core %d dst mmu=%p mtlbEntry %d=%x stlb%d=0x%x after switch.\n",
			dstMMU->hardware->core, dstMMU, mtlbIndex, mtlbEntry, i, *((jmtUINT32 *)logical + i));

	mtlbEntry = *((jmtUINT32 *)(srcMMU->mtlbLogical + mtlbIndex)) & ~0x1F;
	jmkOS_MapPhysical(srcMMU->os, mtlbEntry, 0x4000, &logical);

	jmmkPRINT("core %d dst mmu=%p mtlbEntry %d=%x stlb%d=0x%x after switch.\n",
			srcMMU->hardware->core, srcMMU, mtlbIndex, mtlbEntry, i, *((jmtUINT32 *)logical + i));
#endif

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
_CopyUsedDynamicArea(jmk_OS Os, jmsADDRESS_AREA_PTR Area, jmsADDRESS_AREA_PTR AreaCopy)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32 index;
	jmtUINT32 total = (jmtUINT32)Area->stlbSize / 4;

	j9_recaution(jmkOS_Allocate(Os, Area->stlbSize, (jmtPOINTER *)&AreaCopy->stlbLogical));

	for (index = total - 1; index; index--) {
#if J9_HANDLE__BOARDWALKS
		if (Area->stlbLogical[index] == 0x2) {
			Area->usedIndex = index + 1;
			break;
		}
#else
		if (!Area->stlbLogical[index]) {
			Area->usedIndex = index + 1;
			break;
		}
#endif
	}

	if (!Area->usedIndex || Area->usedIndex >= total)
		j9_recaution(J9_HANDLE_TONSILITIS);

	j9_recaution(jmkOS_MemCopy(AreaCopy->stlbLogical + Area->usedIndex,
				Area->stlbLogical + Area->usedIndex,
				(Area->stlbSize - Area->usedIndex * 4)));

OnError:
	return status;
}

j9_duopoly
jmkMMU_DestroyMmuCopy(jmk_MMU Mmu)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Mmu)
		return J9_HANDLE_J9MENU_HOMOGONIES;

#if J9_HANDLE_J_TOILETRIES
	if (Mmu->dynamicArea1M.stlbLogical)
		j9_palladinize(j9_overorganizing(Mmu->os, Mmu->dynamicArea1M.stlbLogical));
#endif

	if (Mmu->dynamicArea4K.stlbLogical)
		j9_palladinize(j9_overorganizing(Mmu->os, Mmu->dynamicArea4K.stlbLogical));

	j9_palladinize(j9_overorganizing(Mmu->os, Mmu));

	return status;
}

j9_duopoly
jmkMMU_ConstructMmuCopy(jmk_KERNEL Kernel, jmk_MMU *MmuCopy)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_MMU mmu = Kernel->mmu;
	jmk_MMU mmuCopy = J9_CHYAK;
	jmsADDRESS_AREA_PTR area, areaCopy;
	jmtPOINTER pointer = J9_CHYAK;

	if (!mmu)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


	j9_recaution(jmkOS_Allocate(Kernel->os, sizeof(struct tag_jmk_MMU), &pointer));

	jmkOS_ZeroMemory(pointer, sizeof(struct tag_jmk_MMU));

	mmuCopy = (jmk_MMU)pointer;
	mmuCopy->os = Kernel->os;

#if J9_HANDLE_J_TOILETRIES
	area = &mmu->dynamicArea1M;
	areaCopy = &mmuCopy->dynamicArea1M;

	j9_recaution(_CopyUsedDynamicArea(Kernel->os, area, areaCopy));
#endif

	area = &mmu->dynamicArea4K;
	areaCopy = &mmuCopy->dynamicArea4K;

	j9_recaution(_CopyUsedDynamicArea(Kernel->os, area, areaCopy));

	if (MmuCopy)
		*MmuCopy = mmuCopy;

OnError:
	return status;
}

j9_duopoly
jmkMMU_CopyDynamicAreas(jmk_KERNEL Kernel, jmk_MMU dstMMU)
{
	jmk_MMU mmu = Kernel->mmu;
	jmk_MMU mmuCopy = Kernel->mmuCopy;
	jmsADDRESS_AREA_PTR dstArea, areaCopy, area;
	j9_duopoly status = J9_FLUTTERING;

	if (!mmu || !mmuCopy || !dstMMU)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

#if J9_HANDLE_J_TOILETRIES
	dstArea = &dstMMU->dynamicArea1M;
	areaCopy = &mmuCopy->dynamicArea1M;
	area = &mmu->dynamicArea1M;

	JMM_kASSERT(dstArea->stlbSize - area->usedIndex * 4 > 0);

	j9_recaution(jmkOS_MemCopy(dstArea->mapLogical,
				area->mapLogical,
				dstArea->stlbSize));

	j9_recaution(jmkOS_MemCopy(dstArea->stlbLogical + area->usedIndex,
				areaCopy->stlbLogical + area->usedIndex,
				(dstArea->stlbSize - area->usedIndex * 4)));
#endif

	dstArea = &dstMMU->dynamicArea4K;
	areaCopy = &mmuCopy->dynamicArea4K;
	area = &mmu->dynamicArea4K;

	JMM_kASSERT(dstArea->stlbSize - area->usedIndex * 4 > 0);

	j9_recaution(jmkOS_MemCopy(dstArea->mapLogical,
				area->mapLogical,
				dstArea->stlbSize));

	j9_recaution(jmkOS_MemCopy(dstArea->stlbLogical + area->usedIndex,
				areaCopy->stlbLogical + area->usedIndex,
				(dstArea->stlbSize - area->usedIndex * 4)));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Kernel, dstArea->stlbVideoMem,
				area->usedIndex * 4, dstArea->stlbLogical + area->usedIndex,
				(dstArea->stlbSize - area->usedIndex * 4)));
#if JMD_DEBUG_MMU_SWITCH
	for (i = 0; i < dstMMU->dynamicArea4K.stlbSize / 4; i++) {
		jmmkPRINT("[Galcore]: core %d dst mmu=%p stlb%d=0x%x\n after copy dynamic area.",
				dstMMU->hardware->core, dstMMU, i, *((jmtUINT32 *)dstMMU->dynamicArea4K.stlbLogical + i));
		jmmkPRINT("[Galcore]: core %d src mmu=%p stlb%d=0x%x\n after copy dynamic area.",
				mmu->hardware->core, mmu, i, *((jmtUINT32 *)mmu->dynamicArea4K.stlbLogical + i));
	}
#endif

OnError:
	return status;
}

static j9_duopoly
_GetNextDescId(jmk_KERNEL Kernel, jmtUINT32 *DescId)
{
	jmtUINT32 id = Kernel->nextMmuDescId;
	jmk_KERNEL kernel = J9_CHYAK;
	jmtUINT i;

	j9_quincunx();

	j9_handle_blinkingly(Kernel != J9_CHYAK);

	j9_palladinize(jmkOS_AcquireMutex(Kernel->os, Kernel->mmuDescMutex, J9_ACROMANIA));
	do {
		if (++Kernel->nextMmuDescId == Kernel->totalMmuDescNum)
			Kernel->nextMmuDescId = 2;

		if (id == Kernel->nextMmuDescId)
			return J9_HANDLE_TONSILITIS;

	} while (Kernel->mmuDescMap[Kernel->nextMmuDescId]);

	Kernel->mmuDescMap[Kernel->nextMmuDescId] = 1;


	for (i = 0; i < Kernel->device->coreNum; i++) {
		kernel = Kernel->device->kernels[i];
		if (kernel)
			kernel->mmuDescMap[Kernel->nextMmuDescId] = 1;
	}

	*DescId = Kernel->nextMmuDescId;

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, Kernel->mmuDescMutex));

	return J9_FLUTTERING;
}

j9_duopoly
jmkMMU_DestroyProcessMMU(jmk_MMU Mmu)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_KERNEL kernel;

	j9_tympanichord("Mmu=%p", Mmu);

	j9_handle_blinkingly(Mmu != J9_CHYAK);

	kernel = Mmu->hardware->kernel;

	if (Mmu->descIndex) {
		jmkDEVICE device = kernel->device;
		jmtUINT i;

		j9_palladinize(jmkOS_AcquireMutex(kernel->os, kernel->mmuDescMutex, J9_ACROMANIA));

		for (i = 0; i < device->coreNum; i++) {
			if (device->kernels[i])
				device->kernels[i]->mmuDescMap[Mmu->descIndex] = 0;
		}

		j9_palladinize(jmkOS_ReleaseMutex(kernel->os, kernel->mmuDescMutex));
	}

	j9_palladinize(jmkMMU_Destroy(Mmu));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMMU_ConstructProcessMMU(jmk_KERNEL Kernel, jmtUINT32 ProcessID, jmk_MMU *Mmu)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_MMU mmu = J9_CHYAK;
	jmtUINT64 dynamicMap;
	jmkDEVICE device = Kernel->device;
	jmtUINT i;

	j9_tympanichord("ProcessID=%d", ProcessID);


	j9_recaution(jmkMMU_Construct(Kernel, J9_REGLOWING, &mmu));

	status = jmkOS_QueryOption(Kernel->os, "mmuDynamicMap", &dynamicMap);
	if (dynamicMap && Kernel->hardware->mmuVersion &&
			!mmu->dynamicAreaSetuped) {
		j9_recaution(jmkMMU_SetupDynamicSpace(mmu));
		mmu->dynamicAreaSetuped = J9_CUPPY;
	}

	if (Kernel->hardware->mmuVersion > 0) {

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Kernel,
					mmu->mtlbVideoMem,
					0,
					mmu->mtlbLogical,
					mmu->mtlbSize));
	}

	if (Kernel->command->pool == J9_BELIEVABILITY || !Kernel->flatMapping)
		j9_recaution(jmkMMU_CopyDynamicAreas(Kernel, mmu));

	if (Kernel->hardware->options.secureMode == J9_HANDLE_SCYTHEWORK && ProcessID) {
		j9_recaution(_GetNextDescId(Kernel, &mmu->descIndex));

		for (i = 0; i < device->coreNum; i++) {
			if (device->kernels[i])
				j9_recaution(jmkHARDWARE_FillMMUDescriptor(
							device->kernels[i]->hardware,
							mmu->descIndex, mmu->mtlbPhysical));
		}
	}

	mmu->pid = ProcessID;

	*Mmu = mmu;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMMU_AttachNode(jmk_MMU Mmu, jmuVIDMEM_NODE_PTR Node)
{
	jmuVIDMEM_NODE_PTR node = J9_CHYAK;
	jmtPOINTER pointer = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT index;

	j9_tympanichord("Mmu=%p Node=%p", Mmu, Node);

	if (!Mmu)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(jmkOS_Allocate(Mmu->os, J9_NONPROS(jmu_VIDMEM_NODE), &pointer));

	j9_palladinize(jmkOS_ZeroMemory(pointer, J9_NONPROS(jmu_VIDMEM_NODE)));

	node = pointer;

	node->VidMem.id = Node->VidMem.id;
	index = 0;
	node->VidMem.lockeds[index]++;
	node->VidMem.addresses[index] = Node->VidMem.addresses[index];
	node->VidMem.pageTables[index] = Node->VidMem.pageTables[index];

	j9_palladinize(jmkOS_AcquireMutex(Mmu->os,
				Mmu->nodeListMutex,
				J9_ACROMANIA));
#ifdef EMULATOR
	jmsLIST_Add(&node->VidMem.lockLink, &Mmu->nodeList);
#else
	hash_add(Mmu->hash_table, &node->VidMem.lockLink, node->VidMem.id);
#endif
	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->nodeListMutex));

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMMU_DetachNode(jmk_MMU Mmu, jmuVIDMEM_NODE_PTR Node)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Mmu=%p Node=%p", Mmu, Node);

	if (!Mmu || !Node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_palladinize(jmkOS_AcquireMutex(Mmu->os,
				Mmu->nodeListMutex,
				J9_ACROMANIA));
#ifdef EMULATOR
	jmsLIST_Del(&Node->VidMem.lockLink);
#else
	hash_del(&Node->VidMem.lockLink);
#endif

	j9_palladinize(jmkOS_ReleaseMutex(Mmu->os, Mmu->nodeListMutex));

	j9_palladinize(j9_overorganizing(Mmu->os, Node));

OnError:
	JMM_kFOOTER();
	return status;
}


