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






#include "jmgpu_integrity.h"
#include "jmgpu_relational.h"
#include "jmgpu_static.h"
#include "jmgpu_policy.h"



static j9_duopoly
j9_handle_extradoses(IN jmk_KERNEL Kernel,
		     IN j9_reinoculated Type,
		     IN jmtUINT32 AllocFlag,
		     IN OUT j9_phpht * Pool,
		     IN OUT jmtSIZE_T * Bytes,
		     OUT jmkVIDMEM_NODE * Node,
		     OUT jmtPOINTER * Logical, OUT jmtUINT32 * Address)
{
	j9_duopoly status = J9_FLUTTERING;

	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes = 0;
	j9_phpht pool = J9_MULTIGRANULAR;

	if (!Bytes || *Bytes == 0)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	if (Pool)
		pool = *Pool;

	bufferBytes = *Bytes;

	j9_recaution(jmkKERNEL_AllocateVideoMemory(Kernel,
						   64,
						   Type,
						   AllocFlag,
						   &bufferBytes,
						   &pool, &bufferNode));

	j9_recaution(jmkVIDMEM_NODE_LockCPU(Kernel,
					    bufferNode,
					    J9_YARELY,
					    J9_YARELY, &bufferLogical));

	j9_recaution(jmkVIDMEM_NODE_Lock(Kernel, bufferNode, &bufferAddress));

	j9_recaution(jmkOS_ZeroMemory(bufferLogical, bufferBytes));

	*Bytes = bufferBytes;

	if (Pool)
		*Pool = pool;
	if (Node)
		*Node = bufferNode;
	if (Logical)
		*Logical = bufferLogical;
	if (Address)
		*Address = bufferAddress;

	return J9_FLUTTERING;

OnError:
	if (bufferNode) {
		if (bufferAddress) {
			j9_palladinize(jmkVIDMEM_NODE_Unlock(Kernel,
							     bufferNode,
							     Kernel->mmu, J9_CHYAK));
		}

		if (bufferLogical) {
			j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Kernel,
								bufferNode,
								0,
								J9_YARELY,
								J9_YARELY));
		}

		j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, bufferNode));
	}

	return status;
}

static j9_duopoly j9_surveillances(IN jmk_KERNEL Kernel, IN jmkVIDMEM_NODE Node)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Node)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_palladinize(jmkVIDMEM_NODE_Unlock(Kernel, Node, Kernel->mmu, J9_CHYAK));

	j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Kernel,
						Node, 0, J9_YARELY, J9_YARELY));

	j9_palladinize(jmkVIDMEM_NODE_Dereference(Kernel, Node));

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_staxis(IN jmtUINT8_PTR * Base,
	  IN jmtUINT32 Value, IN jmtUINT32_PTR Offset, IN jmtUINT Length)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32_PTR msb = (jmtUINT32_PTR) (*Base) + 1, lsb =
	    (jmtUINT32_PTR) (*Base);

	JMM_kASSERT(*Offset <= 32 && Length <= 32);

	if ((*Offset) < 32) {
		jmtUINT32 end = (*Offset) + Length, data = *lsb;

		if (end < 32) {
			data = (*lsb & ((1 << *Offset) - 1));
			data |= (*lsb & ~((1 << end) - 1));
			data |= (Value << *Offset);

			*lsb = data;
			*Offset = end;
		} else if (end < 64) {
			jmtUINT32 length_m = end - 32;
			jmtUINT32 data_l = (*lsb & ((1 << *Offset) - 1));
			jmtUINT32 data_m = (*msb & ~((1 << length_m) - 1));

			data_l |= (Value << *Offset);
			data_m |= (Value >> (32 - *Offset));

			*lsb = data_l;

			if (end > 32)
				*msb = data_m;

			*Offset = length_m;

			*Base = (jmtUINT8_PTR) msb;
		}

	}

	return status;
}

static j9_duopoly
j9_anocathartic(IN jmk_HARDWARE Hardware,
		OUT j9_nonflatulently * ArchType,
		OUT jmtUINT8 * DataType,
		OUT jmtUINT32 *j9_norgen,
		OUT jmtUINT32 *Zdp,
		OUT jmtUINT32 *KernelBurstSize)
{
	j9_duopoly status = J9_FLUTTERING;

	jmsFEATURE_DATABASE *database =
	    (jmsFEATURE_DATABASE *) (Hardware->featureDatabase);
	j9_nonflatulently archType;
	jmtUINT8 dataType = MWV207REG_NN_DATA_TYPE_UINT8;
	jmtUINT32 coreCount = 0;
	jmtUINT32 zdp = 1;
	jmtUINT32 kernelBurstSize;

	JMM_kASSERT(database);


	j9_bronchotyphus(0, 0, 0, 0, 0);


	if (database->j9_unpersuasible > 0) {
		dataType = MWV207REG_NN_DATA_TYPE_UINT8;
		coreCount = database->j9_unpersuasible;
	} else if (database->j9_discrimination > 0) {
		dataType = MWV207REG_NN_DATA_TYPE_INT16;
		coreCount = database->j9_discrimination;
	} else if (database->j9mirror_transmutes > 0) {
		dataType = MWV207REG_NN_DATA_TYPE_FP16;
		coreCount = database->j9mirror_transmutes;
	} else if (database->j9maths_aurivorous > 0) {
		dataType = MWV207REG_NN_DATA_TYPE_BFP16;
		coreCount = database->j9maths_aurivorous;
	} else {
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
	}

	if (database->J9_SYLPH)
		archType = J9_HANDLE_PROVITAMIN;
	else if (database->J9SUB_)
		archType = J9_HANDLE_REINSERTED;
	else
		archType = J9_HANDLE_PHYSICKING;

	zdp = database->J9_MOOP ? 3 : 1;

	kernelBurstSize = database->J9_HANDLE__APHIDICIDE;

	if (ArchType)
		*ArchType = archType;

	if (Hardware->identity.j9_nascent == 0x23
	    || Hardware->identity.j9_nascent == 0x83) {
		dataType = MWV207REG_NN_DATA_TYPE_FP16;
	} else if (Hardware->identity.j9_nascent == 0x96) {
		dataType = MWV207REG_NN_DATA_TYPE_INT8;
	}

	if (DataType)
		*DataType = dataType;
	if (j9_norgen)
		*j9_norgen = coreCount;
	if (Zdp)
		*Zdp = zdp;

	if (KernelBurstSize)
		*KernelBurstSize = kernelBurstSize;

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_inactionist(IN jmtUINT8 DataType, OUT jmtUINT32_PTR DataSize)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!DataSize)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	switch (DataType) {
	case MWV207REG_NN_DATA_TYPE_INT8:
	case MWV207REG_NN_DATA_TYPE_UINT8:
		*DataSize = 1;
		break;

	case MWV207REG_NN_DATA_TYPE_INT16:
	case MWV207REG_NN_DATA_TYPE_FP16:
	case MWV207REG_NN_DATA_TYPE_BFP16:
		*DataSize = 2;
		break;

	default:
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		break;
	}

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_checkerboards(IN jmk_HARDWARE Hardware,
		 IN jmtUINT32 InImageXSize,
		 IN jmtUINT32 InImageYSize,
		 IN jmtUINT32 AllocFlag,
		 IN OUT j9_phpht *Pool,
		 OUT jmsFUNCTION_EXECUTION_DATA * Data)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 itemBytes = 1;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;
	jmtUINT32 *buffer = J9_CHYAK;
	jmtUINT32 i;

	bufferBytes = bytes =
	    (jmtSIZE_T) (InImageXSize * InImageYSize * itemBytes);

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	buffer = (jmtUINT32_PTR) bufferLogical;


	for (i = 0; i < bytes / 4; i++)
		buffer[i] = J9_PROCEREBRUM;

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: ppu input]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

static j9_duopoly
j9_suprastapedial(IN jmk_HARDWARE Hardware,
		  IN jmtUINT32 Width,
		  IN jmtUINT32 Height,
		  IN jmtUINT32 AllocFlag,
		  IN OUT j9_phpht *Pool,
		  OUT jmsFUNCTION_EXECUTION_DATA * Data)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 itemBytes = 1;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;

	bufferBytes = bytes = (jmtSIZE_T) (Width * Height * itemBytes);

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bufferBytes));

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

static jmtUINT32
J9_AVIAN(IN jmtUINT32 Data,
	 IN jmtUINT32 Start, IN jmtUINT32 End, IN jmtUINT32 Value)
{
	jmtUINT32 data = Data;
	jmtUINT32 mask;

	if (End >= Start) {
		mask = ((~0ULL >> (63 - End + Start)) << Start);
		data &= ~mask;
		data |= ((Value) << Start) & mask;
		return data;
	}

	mask = ((~0ULL >> (63 - Start + End)) << End);
	data &= ~mask;
	data |= ((Value) << End) & mask;

	return data;
}

static jmtUINT32
J9_RACK(IN jmtUINT32 Data, IN jmtUINT32 Position, IN jmtUINT32 Value)
{
	jmtUINT32 data;

	data = J9_AVIAN(Data, Position, Position, Value);

	return data;
}

static jmtUINT32
J9_MACBS(IN jmtUINT32 Data, IN jmtUINT32 Start, IN jmtUINT32 End)
{
	jmtUINT32 data = Data;
	jmtUINT32 mask;

	if (End >= Start) {
		mask = (~0ULL >> (63 - (End - Start)));
		return (data >> Start) & mask;
	}

	mask = (~0ULL >> (63 - (Start - End)));

	return (data >> End) & mask;
}

static jmtUINT32 J9_LGBO(IN jmtUINT32 Data, IN jmtUINT32 Position)
{
	jmtUINT32 data;

	data = J9_MACBS(Data, Position, Position);

	return data;
}

static j9_duopoly
j9mirror_politicise(IN jmtUINT32 Where,
		    IN jmtUINT32 Value,
		    IN jmtUINT32 Type, IN OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	switch (Where) {
	case 0:
		Inst[1] =
		    J9_CRACKROPE(Inst[1], AQ_INST, SRC0_ADR,
				 J9_MACBS(Value, 8, 0));
		Inst[1] =
		    J9_CRACKROPE(Inst[1], AQ_INST, SRC0_SWIZZLE,
				 J9_MACBS(Value, 16, 9));
		Inst[1] =
		    J9_CRACKROPE(Inst[1], AQ_INST, SRC0_MODIFIER_NEG,
				 J9_LGBO(Value, 17));
		Inst[1] =
		    J9_CRACKROPE(Inst[1], AQ_INST, SRC0_MODIFIER_ABS,
				 J9_LGBO(Value, 18));
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC0_REL_ADR,
				 J9_LGBO(Value, 19) | (Type << 1));
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC0_TYPE,
				 AQ_SHADER_SRC_REG_TYPE_IMMEDIATE);
		break;

	case 1:
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_ADR,
				 J9_MACBS(Value, 8, 0));
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_SWIZZLE,
				 J9_MACBS(Value, 16, 9));
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_MODIFIER_NEG,
				 J9_LGBO(Value, 17));
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_MODIFIER_ABS,
				 J9_LGBO(Value, 18));
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_REL_ADR,
				 J9_LGBO(Value, 19) | (Type << 1));
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC1_TYPE,
				 AQ_SHADER_SRC_REG_TYPE_IMMEDIATE);
		break;

	case 2:
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_ADR,
				 J9_MACBS(Value, 8, 0));
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_SWIZZLE,
				 J9_MACBS(Value, 16, 9));
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_MODIFIER_NEG,
				 J9_LGBO(Value, 17));
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_MODIFIER_ABS,
				 J9_LGBO(Value, 18));
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_REL_ADR,
				 J9_LGBO(Value, 19) | (Type << 1));
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_TYPE,
				 AQ_SHADER_SRC_REG_TYPE_IMMEDIATE);
		break;
	}

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_handle_j9ma_returnable(IN jmtUINT32 Type, OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	Inst[1] = J9_CRACKROPE(Inst[1], AQ_INST, INST_TYPE_0, J9_LGBO(Type, 0));
	Inst[2] =
	    J9_CRACKROPE(Inst[2], AQ_INST, INST_TYPE_1, J9_MACBS(Type, 2, 1));

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_platformistic(IN jmk_HARDWARE Hardware,
		 IN jmtUINT32 OpCode, OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	jmsFEATURE_DATABASE *database =
	    (jmsFEATURE_DATABASE *) Hardware->featureDatabase;
	jmtUINT32 bits = 0;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	if (!database->J9_LIPPITUDO)
		return J9_FLUTTERING;

	switch (OpCode) {
	case AQ_INST_OP_CODE_MOV:
	case AQ_INST_OP_CODE_MOVAI:
	case AQ_INST_OP_CODE_MOVAR:
	case AQ_INST_OP_CODE_MOVAF:
	case AQ_INST_OP_CODE_SELECT:
	case AQ_INST_OP_CODE_CMP:
	case AQ_INST_OP_CODE_SET:
		bits =
		    J9_AVIAN(Inst[1],
			     MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER_Start,
			     MWV207REG_SH_END_OF_BASIC_BLOCK_CC_VER_End, 1);
		Inst[1] = J9_CRACKROPE(Inst[1], AQ_INST, SAMPLER_SWIZZLE, bits);
		break;

	case AQ_INST_OP_CODE_ATOM_ADD:
	case AQ_INST_OP_CODE_ATOM_XCHG:
	case AQ_INST_OP_CODE_ATOM_CMP_XCHG:
	case AQ_INST_OP_CODE_ATOM_MIN:
	case AQ_INST_OP_CODE_ATOM_MAX:
	case AQ_INST_OP_CODE_ATOM_OR:
	case AQ_INST_OP_CODE_ATOM_AND:
	case AQ_INST_OP_CODE_ATOM_XOR:
	case AQ_INST_OP_CODE_IMG_ATOM:
		bits =
		    J9_AVIAN(Inst[0],
			     MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_Start,
			     MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_End, 1);
		Inst[0] = J9_CRACKROPE(Inst[0], AQ_INST, CONDITION_CODE, bits);
		break;

	case AQ_INST_OP_CODE_LOAD:
	case AQ_INST_OP_CODE_LOADP:
	case AQ_INST_OP_CODE_STORE:
	case AQ_INST_OP_CODE_STOREP:
	case AQ_INST_OP_CODE_IMG_LOAD:
	case AQ_INST_OP_CODE_IMG_LOAD_3D:
	case AQ_INST_OP_CODE_IMG_STORE:
	case AQ_INST_OP_CODE_IMG_STORE_3D:
		bits =
		    J9_AVIAN(Inst[0],
			     MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_Start,
			     MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_End, 1);
		Inst[0] = J9_CRACKROPE(Inst[0], AQ_INST, CONDITION_CODE, bits);
		break;

	default:
		if (OpCode != AQ_INST_OP_CODE_BRANCH &&
		    OpCode != AQ_INST_OP_CODE_BRANCH_ANY &&
		    OpCode != AQ_INST_OP_CODE_CALL &&
		    OpCode != AQ_INST_OP_CODE_RET &&
		    OpCode != AQ_INST_OP_CODE_TEXKILL) {
			bits =
			J9_AVIAN(Inst[0],
				MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_Start,
				MWV207REG_SH_END_OF_BASIC_BLOCK_NO_CC_VER_End,
				1);
			Inst[0] = J9_CRACKROPE(Inst[0], AQ_INST, CONDITION_CODE,
					bits);
		}
		break;
	}

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_gynecologists(IN jmk_HARDWARE Hardware,
		 IN jmtUINT32 OpCode,
		 IN jmtUINT32 Extended,
		 IN jmtUINT32 Type, IN OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	Inst[0] =
	    J9_CRACKROPE(Inst[0], AQ_INST, OP_CODE, J9_MACBS(OpCode, 5, 0));
	Inst[2] =
	    J9_CRACKROPE(Inst[2], AQ_INST, OP_CODE_MSB6, J9_LGBO(OpCode, 6));

	switch (OpCode) {
	case AQ_INST_OP_CODE_EXTENDED:
		j9_recaution(j9mirror_politicise
			     (2, Extended, MWV207REG_SH_IMMEDIATE_TYPE_U20,
			      Inst));
		break;

	case AQ_INST_OP_CODE_EVIS:
		Inst[0] =
		    J9_CRACKROPE(Inst[0], AQ_INST, DEST_REL_ADR,
				 J9_MACBS(Extended, 2, 0));
		Inst[0] = J9_RACK(Inst[0], 31, J9_LGBO(Extended, 3));
		Inst[1] = J9_AVIAN(Inst[1], 1, 0, J9_MACBS(Extended, 5, 4));
		break;

	case AQ_INST_OP_CODE_CMP:
	case AQ_INST_OP_CODE_MOV:
	case AQ_INST_OP_CODE_SELECT:
		Inst[0] =
		    J9_CRACKROPE(Inst[0], AQ_INST, CONDITION_CODE,
				 J9_MACBS(Extended, 4, 0));
		break;

	default:
		break;
	}

	if (Type != J9_HANDLE_J9MENU_ATTRIBUTE_COENOTYPIC)
		j9_recaution(j9_handle_j9ma_returnable(Type, Inst));

	j9_recaution(j9_platformistic(Hardware, OpCode, Inst));

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_handle__isthmistic(IN jmtUINT32 Address,
		      IN jmtUINT32 WriteEnable,
		      IN jmtUINT32 Saturate, IN OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	Inst[0] = J9_CRACKROPE(Inst[0], AQ_INST, DEST_VALID, 1);
	Inst[0] = J9_CRACKROPE(Inst[0], AQ_INST, DEST_ADR, Address);
	Inst[0] =
	    J9_CRACKROPE(Inst[0], AQ_INST, DEST_WRITE_ENABLE, WriteEnable);
	Inst[0] = J9_CRACKROPE(Inst[0], AQ_INST, SATURATE, Saturate);

	return J9_FLUTTERING;

OnError:
	return status;
}

#define J9_HANDSMOOTH \
	((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3))
#define J9_NONRESIDENT(X, Y, Z, W) \
	((1 << (X)) | (1 << (Y)) | (1 << (Z)) | (1 << (W)))
#define J9_CRYSTALITIC(X) \
	(1 << (X))
#define J9_PRESURROUND(X, Y) \
	((1 << (X)) | (1 << (Y)))
#define J9_COPPERSMITH(X, Y, Z) \
	((1 << (X)) | (1 << (Y)) | (1 << (Z)))
#define J9_EMPIRICALLY \
	(0 | (1 << 2) | (2 << 4) | (3 << 6))
#define J9_RESTRINGENCY(X) \
	((X) | ((X) << 2) | ((X) << 4) | ((X) << 6))
#define J9_ANTIFEMINIST(X, Y) \
	((X) | ((Y) << 2) | ((Y) << 4) | ((Y) << 6))
#define J9_RIDICULOUSLY(X, Y, Z, W) \
	((X) | ((Y) << 2) | ((Z) << 4) | ((W) << 6))

static jmtUINT32 j9_proamusement(IN jmtUINT32 Format)
{
	jmtUINT32 pixel = 0;

	switch (Format) {
	case MWV207REG_SH_INSTRUCTION_TYPE_UNSIGNED8:
		pixel = 15;
		break;

	case MWV207REG_SH_INSTRUCTION_TYPE_SIGNED16:
	case MWV207REG_SH_INSTRUCTION_TYPE_UNSIGNED16:
		pixel = 7;
		break;

	default:
		pixel = 15;
		break;
	}

	return pixel;
}

j9_duopoly
jmkPPU_SetEVIS(IN jmtUINT32 Start,
	       IN jmtUINT32 End, IN jmtUINT32 Evis, IN OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	Inst[0] = J9_CRACKROPE(Inst[0], AQ_INST, DEST_WRITE_ENABLE, Start);
	Inst[0] = J9_AVIAN(Inst[0], 30, 27, End);
	Inst[1] = J9_AVIAN(Inst[1], 10, 2, Evis);

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_purpuriferous(IN jmtUINT32 Where,
		 IN jmtUINT32 Address,
		 IN jmtUINT32 Swizzle,
		 IN jmtUINT32 Type,
		 IN jmtBOOL Negate,
		 IN jmtBOOL Absolute,
		 IN jmtUINT32 Relative, IN OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	switch (Where) {
	case 0:
		Inst[1] = J9_CRACKROPE(Inst[1], AQ_INST, SRC0_VALID, 1);
		Inst[1] = J9_CRACKROPE(Inst[1], AQ_INST, SRC0_ADR, Address);
		Inst[1] = J9_CRACKROPE(Inst[1], AQ_INST, SRC0_SWIZZLE, Swizzle);
		Inst[1] =
		    J9_CRACKROPE(Inst[1], AQ_INST, SRC0_MODIFIER_NEG, Negate);
		Inst[1] =
		    J9_CRACKROPE(Inst[1], AQ_INST, SRC0_MODIFIER_ABS, Absolute);
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC0_REL_ADR, Relative);
		Inst[2] = J9_CRACKROPE(Inst[2], AQ_INST, SRC0_TYPE, Type);
		break;

	case 1:
		Inst[2] = J9_CRACKROPE(Inst[2], AQ_INST, SRC1_VALID, 1);
		Inst[2] = J9_CRACKROPE(Inst[2], AQ_INST, SRC1_ADR, Address);
		Inst[2] = J9_CRACKROPE(Inst[2], AQ_INST, SRC1_SWIZZLE, Swizzle);
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_MODIFIER_NEG, Negate);
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_MODIFIER_ABS, Absolute);
		Inst[2] =
		    J9_CRACKROPE(Inst[2], AQ_INST, SRC1_REL_ADR, Relative);
		Inst[3] = J9_CRACKROPE(Inst[3], AQ_INST, SRC1_TYPE, Type);
		break;

	case 2:
		Inst[3] = J9_CRACKROPE(Inst[3], AQ_INST, SRC2_VALID, 1);
		Inst[3] = J9_CRACKROPE(Inst[3], AQ_INST, SRC2_ADR, Address);
		Inst[3] = J9_CRACKROPE(Inst[3], AQ_INST, SRC2_SWIZZLE, Swizzle);
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_MODIFIER_NEG, Negate);
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_MODIFIER_ABS, Absolute);
		Inst[3] =
		    J9_CRACKROPE(Inst[3], AQ_INST, SRC2_REL_ADR, Relative);
		Inst[3] = J9_CRACKROPE(Inst[3], AQ_INST, SRC2_TYPE, Type);
		break;

	default:
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		break;
	}

	return J9_FLUTTERING;

OnError:
	return status;
}

static const jmtUINT32 NEGATE_FLAG = 1 << 0;
static const jmtUINT32 ABSOLUTE_FLAG = 1 << 1;

static j9_duopoly
j9_megalomaniacal(IN jmtUINT32 Where,
		  IN jmtUINT32 Address,
		  IN jmtUINT32 Swizzle,
		  IN jmtUINT32 Modifiers, OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtBOOL negate = (Modifiers & NEGATE_FLAG) ? J9_CUPPY : J9_YARELY;
	jmtBOOL absolute = (Modifiers & ABSOLUTE_FLAG) ? J9_CUPPY : J9_YARELY;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(j9_purpuriferous(Where,
				      Address,
				      Swizzle,
				      AQ_SHADER_SRC_REG_TYPE_UNBOUNDED_CONST,
				      negate, absolute, 0, Inst));

	return J9_FLUTTERING;

OnError:
	return status;
}

j9_duopoly
jmkPPU_SetTempReg(IN jmtUINT32 Where,
		  IN jmtUINT32 Address,
		  IN jmtUINT32 Swizzle,
		  IN jmtUINT32 Modifiers, OUT jmtUINT32_PTR Inst)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtBOOL negate = (Modifiers & NEGATE_FLAG) ? J9_CUPPY : J9_YARELY;
	jmtBOOL absolute = (Modifiers & ABSOLUTE_FLAG) ? J9_CUPPY : J9_YARELY;

	if (!Inst)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(j9_purpuriferous(Where,
				      Address,
				      Swizzle,
				      AQ_SHADER_SRC_REG_TYPE_TEMP,
				      negate, absolute, 0, Inst));

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_handle_j_etherolate(IN jmk_HARDWARE Hardware,
		       IN jmtUINT32 DataType,
		       IN jmtUINT32 numShaderCores,
		       IN jmtUINT32 AllocFlag,
		       IN OUT j9_phpht *Pool,
		       OUT jmtUINT32 *InstCount,
		       OUT jmtUINT32 *RegCount,
		       OUT jmsFUNCTION_EXECUTION_DATA * Data)
{
	j9_duopoly status = J9_FLUTTERING;

	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;

	jmtUINT32 instCount = 0;
	jmtUINT32_PTR inst = J9_CHYAK;

	jmtUINT32 inImage1DataType = DataType;
	jmtUINT32 inImage2DataType = DataType;
	jmtUINT32 outImageDataType = DataType;

	if (!Data || !InstCount || !RegCount)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	bufferBytes = bytes = J9_NONPROS(jmtUINT32) * J9_HANDLE_J9MA_OUTWRIGGLE;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J9_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	inst = (jmtUINT32_PTR) bufferLogical;


	j9_recaution(j9_gynecologists
		     (Hardware, AQ_INST_OP_CODE_IMG_LOAD, 0, inImage1DataType,
		      &inst[instCount]));
	j9_recaution(j9_handle__isthmistic
		     (1, J9_HANDSMOOTH, J9_YARELY, &inst[instCount]));
	j9_recaution(jmkPPU_SetEVIS
		     (0, j9_proamusement(inImage1DataType), 1,
		      &inst[instCount]));
	j9_recaution(j9_megalomaniacal
		     (0, 0, J9_EMPIRICALLY, 0, &inst[instCount]));
	j9_recaution(jmkPPU_SetTempReg
		     (1, 0, J9_ANTIFEMINIST(0, 1), 0, &inst[instCount]));
	instCount += 4;


	j9_recaution(j9_gynecologists
		     (Hardware, AQ_INST_OP_CODE_IMG_LOAD, 0, inImage2DataType,
		      &inst[instCount]));
	j9_recaution(j9_handle__isthmistic
		     (2, J9_HANDSMOOTH, J9_YARELY, &inst[instCount]));
	j9_recaution(jmkPPU_SetEVIS
		     (0, j9_proamusement(inImage2DataType), 1,
		      &inst[instCount]));
	j9_recaution(j9_megalomaniacal
		     (0, 0, J9_EMPIRICALLY, 0, &inst[instCount]));
	j9_recaution(jmkPPU_SetTempReg
		     (1, 0, J9_ANTIFEMINIST(0, 1), 0, &inst[instCount]));
	instCount += 4;


	j9_recaution(j9_gynecologists
		     (Hardware, AQ_INST_OP_CODE_EVIS,
		      MWV207REG_SH_VISION_OPCODE_DP2X8, outImageDataType,
		      &inst[instCount]));
	j9_recaution(j9_handle__isthmistic
		     (1, J9_HANDSMOOTH, J9_YARELY, &inst[instCount]));
	j9_recaution(jmkPPU_SetEVIS
		     (0, 7, (inImage1DataType | (inImage2DataType << 3)),
		      &inst[instCount]));
	j9_recaution(jmkPPU_SetTempReg
		     (0, 1, J9_EMPIRICALLY, 0, &inst[instCount]));
	j9_recaution(jmkPPU_SetTempReg
		     (1, 2, J9_EMPIRICALLY, 0, &inst[instCount]));
	j9_recaution(j9_purpuriferous
		     (2, 2, J9_EMPIRICALLY, AQ_SHADER_SRC_REG_TYPE_UNIFORM512,
		      J9_YARELY, J9_YARELY, 0, &inst[instCount]));
	instCount += 4;


	j9_recaution(j9_gynecologists
		     (Hardware, AQ_INST_OP_CODE_IMG_STORE, 0, outImageDataType,
		      &inst[instCount]));
	j9_recaution(jmkPPU_SetEVIS
		     (0,
		      (j9_proamusement(outImageDataType) + 1) / numShaderCores -
		      1, 1, &inst[instCount]));
	j9_recaution(j9_megalomaniacal
		     (0, 1, J9_EMPIRICALLY, 0, &inst[instCount]));
	j9_recaution(jmkPPU_SetTempReg
		     (1, 0, J9_ANTIFEMINIST(0, 1), 0, &inst[instCount]));
	j9_recaution(jmkPPU_SetTempReg
		     (2, 1, J9_EMPIRICALLY, 0, &inst[instCount]));
	instCount += 4;

	bytes = J9_NONPROS(jmtUINT32) * instCount;

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: ppu instruction]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	*InstCount = instCount;
	*RegCount = 0x3;

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));
	return status;
}

static j9_duopoly
j9maths_novicelike(IN jmk_HARDWARE Hardware,
		   IN jmtUINT32 Stride,
		   IN jmtUINT32 Width,
		   IN jmtUINT32 Height,
		   IN jmtUINT32 WorkDim,
		   IN jmtUINT32 ValueOrder,
		   IN jmtUINT32 GroupSizeX,
		   IN jmtUINT32 GroupSizeY,
		   IN jmtUINT32 GroupSizeZ,
		   IN jmtUINT32 GlobalScaleX,
		   IN jmtUINT32 GlobalScaleY,
		   IN jmtUINT32 GlobalScaleZ,
		   IN jmtUINT32 GlobalOffsetX,
		   IN jmtUINT32 GlobalOffsetY,
		   IN jmtUINT32 GlobalOffsetZ,
		   IN jmtUINT32 ThreadAllocation,
		   IN jmtUINT32 InImageAddress,
		   IN jmtUINT32 OutImageAddress,
		   IN jmtUINT32 InstAddress,
		   IN jmtUINT32 InstCount,
		   IN jmtUINT32 RegCount,
		   IN jmtUINT32 AllocFlag,
		   IN OUT j9_phpht *Pool,
		   OUT jmsFUNCTION_COMMAND_PTR Command)
{
	j9_duopoly status = J9_FLUTTERING;

	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes = 0;
	jmtUINT32 bytes = 0;
	jmtUINT8_PTR endLogical;
	jmtUINT32 endAddress;
	jmtUINT32 endBytes = 0;
	jmtUINT32_PTR commands = J9_CHYAK;
	jmtUINT32 index = 0;
	jmtUINT32 groupCountX = (Width + GlobalScaleX - 1) / GlobalScaleX;
	jmtUINT32 groupCountY = (Height + GlobalScaleY - 1) / GlobalScaleY;
	jmtUINT32 groupCountZ = 0;

	if (!Command)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	bufferBytes = J9_NONPROS(jmtUINT32) * J9MIRROR_ADHESIVELY;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J9_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	commands = (jmtUINT32_PTR) bufferLogical;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQModeRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = J9_MEGAPHONICALLY(0, AQ_MODE, API_MODE, OpenCL);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQSemaphoreRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, SOURCE, FRONT_END)
	    | J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, DESTINATION, PIXEL_ENGINE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE, STALL);
	commands[index++] = J9_MEGAPHONICALLY(0, STALL_STALL, SOURCE, FRONT_END)
	    | J9_MEGAPHONICALLY(0, STALL_STALL, DESTINATION, PIXEL_ENGINE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPixelUniformsRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 4);
	commands[index++] = InImageAddress;
	commands[index++] = Stride;
	commands[index++] = Height << 16 | Width;
	commands[index++] = J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SHIFT, 0)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, MULTIPLY,
			   MWV207REG_SH_IMAGE_MULTIPLY_ONE)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, ADDRESSING,
			   MWV207REG_SH_IMAGE_ADDRESSING_CLAMP)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, CONVERSION,
			   MWV207REG_SH_IMAGE_CONVERSION_U8)
	    | J9_MEGAPHONICALLY(0, MWV207REG_SH_IMAGE, TILING, LINEAR)
	    | J9_MEGAPHONICALLY(0, MWV207REG_SH_IMAGE, TYPE, 2D)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, COMPONENT_COUNT,
			   MWV207REG_SH_IMAGE_COMPONENT_COUNT_ONE_COMPONENT)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_R,
			   MWV207REG_SH_IMAGE_SWIZZLE_R_X)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_G,
			   MWV207REG_SH_IMAGE_SWIZZLE_G_ZERO)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_B,
			   MWV207REG_SH_IMAGE_SWIZZLE_B_ZERO)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_A,
			   MWV207REG_SH_IMAGE_SWIZZLE_A_ZERO);

	commands[index++] = 0xFFFFFFFF;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPixelUniformsRegAddrs + 0x04)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 4);
	commands[index++] = OutImageAddress;
	commands[index++] = Stride;
	commands[index++] = Height << 16 | Width;
	commands[index++] = J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SHIFT, 0)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, MULTIPLY,
			   MWV207REG_SH_IMAGE_MULTIPLY_ONE)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, ADDRESSING,
			   MWV207REG_SH_IMAGE_ADDRESSING_CLAMP)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, CONVERSION,
			   MWV207REG_SH_IMAGE_CONVERSION_U8)
	    | J9_MEGAPHONICALLY(0, MWV207REG_SH_IMAGE, TILING, LINEAR)
	    | J9_MEGAPHONICALLY(0, MWV207REG_SH_IMAGE, TYPE, 2D)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, COMPONENT_COUNT,
			   MWV207REG_SH_IMAGE_COMPONENT_COUNT_ONE_COMPONENT)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_R,
			   MWV207REG_SH_IMAGE_SWIZZLE_R_X)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_G,
			   MWV207REG_SH_IMAGE_SWIZZLE_G_ZERO)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_B,
			   MWV207REG_SH_IMAGE_SWIZZLE_B_ZERO)
	    | J9_CRACKROPE(0, MWV207REG_SH_IMAGE, SWIZZLE_A,
			   MWV207REG_SH_IMAGE_SWIZZLE_A_ZERO);

	commands[index++] = 0xFFFFFFFF;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPixelUniformsRegAddrs + 0x08)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 16);
	commands[index++] = 0x55555555;
	commands[index++] = 0x00000000;
	commands[index++] = 0x01234567;
	commands[index++] = 0x89abcdef;
	commands[index++] = 0x55555555;
	commands[index++] = 0x01234567;
	commands[index++] = 0x89abcdef;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;
	commands[index++] = 0x00000000;

	commands[index++] = 0xFFFFFFFF;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWConfigRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_CRACKROPE(0, MWV207REG_TW_CONFIG, WORK_DIM,
			 MWV207REG_TW_CONFIG_WORK_DIM_TWO)
	    | J9_MEGAPHONICALLY(0, MWV207REG_TW_CONFIG, TRAVERSE_ORDER, XYZ)
	    | J9_CRACKROPE(0, MWV207REG_TW_CONFIG, VALUE_ORDER,
			   MWV207REG_TW_CONFIG_VALUE_ORDER_LGW);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regSHIcacheInvalidateRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_CRACKROPE(0, MWV207REG_SH_ICACHE_INVALIDATE, VS, 1)
	    | J9_CRACKROPE(0, MWV207REG_SH_ICACHE_INVALIDATE, TCS, 1)
	    | J9_CRACKROPE(0, MWV207REG_SH_ICACHE_INVALIDATE, TES, 1)
	    | J9_CRACKROPE(0, MWV207REG_SH_ICACHE_INVALIDATE, GS, 1)
	    | J9_CRACKROPE(0, MWV207REG_SH_ICACHE_INVALIDATE, PS, 1);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSUnpackRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = J9_CRACKROPE(0, MWV207REG_PS_UNPACK, VARYING0, 0);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQPixelShaderTemporaryRegisterControlRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = RegCount;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSSamplerBaseRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPixelShaderConstRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSStartPCRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSRelativeEndRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = InstCount / 4;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSInstructionRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = InstAddress;

	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9MATHS_CORPORALCY)) {
		commands[index++] =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
				      LOAD_STATE)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
				   mwv207regShaderMiscConfigRegAddrs)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
		commands[index++] =
		    J9_MEGAPHONICALLY(0, MWV207REG_SHADER_MISC_CONFIG,
				      RTNE_ROUNDING, ENABLE);
	} else {
		commands[index++] =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
				      LOAD_STATE)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
				   mwv207regShaderConfigRegAddrs)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
		commands[index++] =
		    J9_MEGAPHONICALLY(0, MWV207REG_SHADER_CONFIG, RTNE_ROUNDING,
				      ENABLE);
	}

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regSHCacheControlRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_MEGAPHONICALLY(0, MWV207REG_SH_CACHE_CONTROL, MODE, MEMORY);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSInstructionPrefetchRelativeEndRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = InstCount / 4 - 1;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQPixelShaderInputControlRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_CRACKROPE(0, AQ_PIXEL_SHADER_INPUT_CONTROL, COUNT, 1)
	    | J9_CRACKROPE(0, AQ_PIXEL_SHADER_INPUT_CONTROL, TIMEOUT, ~0);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regVSThrottleRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPAControlRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regVaryingsRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSOutputModeRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQVertexShaderOutputControlRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_CRACKROPE(0, AQ_VERTEX_SHADER_OUTPUT_CONTROL, COUNT, 1);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regSemanticLocationRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSInstructionPrefetchRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWConfigRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_CRACKROPE(0, MWV207REG_TW_CONFIG, WORK_DIM,
			 MWV207REG_TW_CONFIG_WORK_DIM_TWO)
	    | J9_MEGAPHONICALLY(0, MWV207REG_TW_CONFIG, TRAVERSE_ORDER, XYZ)
	    | J9_CRACKROPE(0, MWV207REG_TW_CONFIG, VALUE_ORDER,
			   MWV207REG_TW_CONFIG_VALUE_ORDER_WGL);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWShaderInfo2RegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWShaderInfoRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = ThreadAllocation;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWInfoGlobalOffsetXRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = GlobalOffsetX;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWInfoGlobalOffsetYRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = GlobalOffsetY;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWInfoGlobalOffsetZRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = GlobalOffsetZ;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWInfoGlobalScaleXRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = GlobalScaleX;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWInfoGlobalScaleYRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = GlobalScaleY;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWInfoGlobalScaleZRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = GlobalScaleZ;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWWorkGroupCountXRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 6);
	commands[index++] = groupCountX - 1;
	commands[index++] = groupCountY - 1;
	commands[index++] = groupCountZ - 1;
	commands[index++] =
	    J9_CRACKROPE(0, MWV207REG_TW_WORKGROUP_SIZE_X, SIZE,
			 GroupSizeX - 1);
	commands[index++] =
	    J9_CRACKROPE(0, MWV207REG_TW_WORKGROUP_SIZE_Y, SIZE,
			 GroupSizeY - 1);
	commands[index++] =
	    J9_CRACKROPE(0, MWV207REG_TW_WORKGROUP_SIZE_Z, SIZE,
			 GroupSizeZ - 1);
	commands[index++] = 0x00000000;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regTWTriggerRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = 0xBADABEEB;

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = J9_MEGAPHONICALLY(0, AQ_FLUSH, SHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, VSSHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, PSSHL1_CACHE, ENABLE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQSemaphoreRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, SOURCE, FRONT_END)
	    | J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, DESTINATION, PIXEL_ENGINE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE, STALL);

	commands[index++] = J9_MEGAPHONICALLY(0, STALL_STALL, SOURCE, FRONT_END)
	    | J9_MEGAPHONICALLY(0, STALL_STALL, DESTINATION, PIXEL_ENGINE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = J9_MEGAPHONICALLY(0, AQ_FLUSH, ZCACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, CCACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, SHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, VSSHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, PSSHL1_CACHE, ENABLE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = J9_MEGAPHONICALLY(0, AQ_FLUSH, ZCACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, CCACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, SHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, VSSHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, PSSHL1_CACHE, ENABLE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   jmTileCacheFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] =
	    J9_MEGAPHONICALLY(0, JM_TILE, CACHE_FLUSH_FLUSH, ENABLE);

	commands[index++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	commands[index++] = J9_MEGAPHONICALLY(0, AQ_FLUSH, ZCACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, CCACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, SHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, VSSHL1_CACHE, ENABLE)
	    | J9_MEGAPHONICALLY(0, AQ_FLUSH, PSSHL1_CACHE, ENABLE);

	bytes = J9_NONPROS(jmtUINT32) * index;

	endLogical = (jmtUINT8_PTR) bufferLogical + bytes;
	endAddress = bufferAddress + bytes;

	if (Hardware->wlFE) {
		j9_recaution(jmkWLFE_End(Hardware, J9_CHYAK, ~0U, &endBytes));
		j9_recaution(jmkWLFE_End
			     (Hardware, endLogical, endAddress, &endBytes));
	}

	bytes += endBytes;

	JMM_kASSERT(bytes <= bufferBytes);

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

	Command->funcVidMem = bufferNode;
	Command->funcVidMemBytes = bufferBytes;
	Command->logical = bufferLogical;
	Command->address = bufferAddress;
	Command->bytes = bytes;
	Command->endAddress = endAddress;
	Command->endLogical = endLogical;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));
	return status;
}

j9_duopoly
jmkHARDWARE_ResetFlopWithPPU(IN jmk_HARDWARE Hardware,
			     IN jmtUINT32 AllocFlag,
			     IN OUT j9_phpht *Pool,
			     OUT j9_handle_acetylizer * Command)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 dataType = MWV207REG_SH_INSTRUCTION_TYPE_UNSIGNED8;
	jmsFEATURE_DATABASE *database = J9_CHYAK;
	jmtUINT32 numShaderCores;
	jmtUINT32 stride, width, height;
	jmtUINT32 workDim;
	jmtUINT32 valueOrder;
	jmtUINT32 groupSizeX, groupSizeY, groupSizeZ;
	jmtUINT32 globalScaleX, globalScaleY, globalScaleZ;
	jmtUINT32 globalOffsetX, globalOffsetY, globalOffsetZ;
	jmtUINT32 threadAllocation;
	jmtUINT32 inImageAddress = 0, outImageAddress = 0, instAddress = 0;
	jmtUINT32 instCount = 0, regCount = 0;
	jmtUINT32 dataCount;
	jmtPOINTER pointer = J9_CHYAK;
	jmsFUNCTION_EXECUTION_DATA *data = J9_CHYAK;
	jmtUINT32 i;


	dataCount = J9_HANDLE_J9MENU_PARANOIACS;
	JMM_kASSERT(dataCount > 0);

	j9_recaution(jmkOS_Allocate(Hardware->os,
				    J9_NONPROS(jmsFUNCTION_EXECUTION_DATA) *
				    dataCount, &pointer));
	jmkOS_ZeroMemory(pointer,
			 J9_NONPROS(jmsFUNCTION_EXECUTION_DATA) * dataCount);
	data = (jmsFUNCTION_EXECUTION_DATA_PTR) pointer;

	database = (jmsFEATURE_DATABASE *) Hardware->featureDatabase;

	numShaderCores = database->j9_subclassify;

	stride = J9_UNSCULPTURED * 1;
	width = J9_UNSCULPTURED;
	height = J9_POSTSEASONAL;

	j9_recaution(j9_checkerboards(Hardware,
				      width,
				      height,
				      AllocFlag,
				      Pool, &data[J9_HANDLE_J9M_POSTMEATAL]
		     ));

	j9_recaution(j9_suprastapedial(Hardware,
				       width,
				       height,
				       AllocFlag,
				       Pool, &data[J9_HANDLE_J9MA_OMMATIDIUM]
		     ));

	j9_recaution(j9_handle_j_etherolate(Hardware,
					    dataType,
					    numShaderCores,
					    AllocFlag,
					    Pool,
					    &instCount,
					    &regCount,
					    &data
					    [J9_HANDLE_ATTRIBUTE_PREINSURED]
		     ));

	workDim = MWV207REG_TW_CONFIG_WORK_DIM_TWO;
	valueOrder = MWV207REG_TW_CONFIG_VALUE_ORDER_LGW;
	groupSizeX = 1;
	groupSizeY = 1;
	groupSizeZ = 0;
	globalScaleX = 4;
	globalScaleY = 1;
	globalScaleZ = 0;
	globalOffsetX = 0;
	globalOffsetY = 0;
	globalOffsetZ = 0;
	threadAllocation =
	    (groupSizeX * groupSizeY + numShaderCores * 4 -
	     1) / (numShaderCores * 4);
	inImageAddress = data[J9_HANDLE_J9M_POSTMEATAL].address;
	outImageAddress = data[J9_HANDLE_J9MA_OMMATIDIUM].address;
	instAddress = data[J9_HANDLE_ATTRIBUTE_PREINSURED].address;

	j9_recaution(j9maths_novicelike(Hardware,
					stride,
					width,
					height,
					workDim,
					valueOrder,
					groupSizeX,
					groupSizeY,
					groupSizeZ,
					globalScaleX,
					globalScaleY,
					globalScaleZ,
					globalOffsetX,
					globalOffsetY,
					globalOffsetZ,
					threadAllocation,
					inImageAddress,
					outImageAddress,
					instAddress,
					instCount,
					regCount, AllocFlag, Pool, Command));

	Command->data = data;
	Command->dataCount = dataCount;
	if (Hardware->identity.j9_nascent == 0x85)
		Command->channelId = 1;
	return J9_FLUTTERING;

OnError:
	if (Command->funcVidMem) {
		j9_palladinize(j9_surveillances(Hardware->kernel,
						Command->funcVidMem));
		Command->funcVidMem = J9_CHYAK;
	}

	if (data) {
		for (i = 0; i < dataCount; i++) {
			if (data[i].bufVidMem) {
				j9_palladinize(j9_surveillances
					       (Hardware->kernel,
						data[i].bufVidMem));
			}
		}

		j9_palladinize(jmkOS_Free(Hardware->os, data));
	}

	return status;
}

static j9_duopoly
j9_coconspirator(IN jmk_HARDWARE Hardware,
		 IN jmtUINT8 DataType,
		 IN jmtUINT32 KernelXSize,
		 IN jmtUINT32 KernelYSize,
		 IN jmtUINT32 KernelZSize,
		 IN chipCmdData * cd,
		 IN jmtUINT32 AllocFlag,
		 IN OUT j9_phpht *Pool,
		 OUT jmsFUNCTION_EXECUTION_DATA *Data)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes;
	jmtSIZE_T bytes = 0;
	jmtUINT32 *buffer = J9_CHYAK;
	jmtBOOL need_refine = (Hardware->identity.j9_nascent == 0x85
			       && Hardware->options.configNNPowerControl != 0);


	bytes = bufferBytes = cd->NNkerLen;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	buffer = (jmtUINT32_PTR) bufferLogical;


	jmkOS_MemCopy(bufferLogical, cd->NNKer, bytes);

	if (need_refine) {
		buffer[16] = buffer[32];
		buffer[17] = buffer[33];
		buffer[18] = buffer[34];
		buffer[32] = 0x0;
		buffer[33] = 0x0;
		buffer[34] = 0x0;
	}

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bufferBytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: nn kernel]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical,
			 bufferAddress, need_refine ? (bytes - 0x40) : bytes);
#endif

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = need_refine ? (bufferBytes - 0x40) : bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = need_refine ? (bytes - 0x40) : bytes;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));
	return status;
}

static j9_duopoly
j9_purpurescent(IN jmk_HARDWARE Hardware,
		IN jmtUINT8 DataType,
		IN jmtUINT32 InImageXSize,
		IN jmtUINT32 InImageYSize,
		IN jmtUINT32 InImageZSize,
		IN jmtUINT32 AllocFlag,
		IN OUT j9_phpht *Pool,
		OUT jmsFUNCTION_EXECUTION_DATA_PTR Data)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 inputSize = InImageXSize * InImageYSize * InImageZSize;
	jmtUINT32 itemBytes = 0;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;
	jmtUINT8_PTR buffer = J9_CHYAK;

	jmtUINT32 i = 0;
	jmtUINT32 offset = 0;

	j9_recaution(j9_inactionist(DataType, &itemBytes));

	bufferBytes = inputSize * itemBytes;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	buffer = (jmtUINT8_PTR) bufferLogical;

	for (i = 0; i < inputSize; i++) {
		j9_staxis(&buffer, flopResetInputs[DataType], &offset,
			  itemBytes * 8);
	}

	bytes = buffer + (offset + 7) / 8 - (jmtUINT8_PTR) bufferLogical;

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: nn input]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

static j9_duopoly
j9_infeasibility(IN jmk_HARDWARE Hardware,
		 IN jmtUINT8 DataType,
		 IN jmtUINT32 OutputXSize,
		 IN jmtUINT32 OutputYSize,
		 IN jmtUINT32 OutputZSize,
		 IN jmtUINT32 AllocFlag,
		 IN OUT j9_phpht *Pool,
		 OUT jmsFUNCTION_EXECUTION_DATA *Data)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 itemBytes = 0;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;

	if (!Data)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(j9_inactionist(DataType, &itemBytes));

	bufferBytes = bytes =
	    (jmtSIZE_T) (OutputXSize * OutputYSize * OutputZSize * itemBytes);

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

static j9_duopoly
j9_handle__bursectomy(IN jmk_HARDWARE Hardware,
		      IN jmtUINT8 DataType,
		      IN jmtUINT32 InImageXSize,
		      IN jmtUINT32 InImageYSize,
		      IN jmtUINT32 OutImageXSize,
		      IN jmtUINT32 OutImageYSize,
		      IN jmtUINT32 OutImageZSize,
		      IN jmtUINT32 KernelXSize,
		      IN jmtUINT32 KernelYSize,
		      IN jmtUINT32 KernelZSize,
		      IN jmtUINT32 InImageAddress,
		      IN jmtUINT32 OutImageAddress,
		      IN jmtUINT32 KernelAddress,
		      IN chipCmdData * cd,
		      IN jmtUINT32 AllocFlag,
		      IN j9_phpht *Pool,
		      OUT jmsFUNCTION_EXECUTION_DATA_PTR Data)
{
	jmtUINT32 itemBytes = 0;
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;
	jmtUINT32 *command = J9_CHYAK;
	jmtSIZE_T outbufferBytes = 0;

	bufferBytes = bytes =
	    jmkHARDWARE_IsFeatureAvailable(
			Hardware,
			JMV_FEATURE_BIT_NN_TENSOR_ADD_FIELD_MOVE_TO_EXT_CMD) ?
			J9_HANDLE_J_OVERKEENLY : J9MATHS_DISTORTION;


	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J9_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	j9_recaution(j9_inactionist(DataType, &itemBytes));
	outbufferBytes =
	    (jmtSIZE_T) (OutImageXSize * OutImageYSize * OutImageZSize *
			 itemBytes);
	command = (jmtUINT32_PTR) bufferLogical;
	jmkOS_MemCopy(command, cd->NNIns, bytes);


	command[5] =
	    J9_CRACKROPE(0, MWV207REG_NN_INST_WORD5, KERNEL_ZSIZE1,
			 ((KernelZSize >> 14) & 0x3F))
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD5, KERNEL_BASE_ADDRESS,
			   (KernelAddress >> 6));
	command[6] = InImageAddress;
	command[7] = OutImageAddress;

	if (Hardware->identity.j9_nascent == 0x85) {
		if (Hardware->options.configNNPowerControl == 3)
			command[12] = 0x00000900;
		else if (Hardware->options.configNNPowerControl == 4)
			command[12] = 0x00000A00;
		else if (Hardware->options.configNNPowerControl == 0)
			command[12] = 0x00000B00;
	}

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bufferBytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: nn instruction]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));
	return status;
}

static j9_duopoly
j9_tracheofissure(IN jmk_HARDWARE Hardware,
		  IN jmtUINT32 InstAddress,
		  IN chipCmdData * cd,
		  IN jmtUINT32 AllocFlag,
		  IN j9_phpht *Pool,
		  OUT jmsFUNCTION_COMMAND_PTR Command)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes = 0;
	jmtUINT32 bytes;
	jmtUINT8_PTR endLogical;
	jmtUINT32 endAddress;
	jmtUINT32 endBytes = 0;
	jmtUINT32 *commands = J9_CHYAK;

	bufferBytes = J9_NONPROS(jmtUINT32) * J9MATHS_PRESTORING;
	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J9_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	commands = (jmtUINT32_PTR) bufferLogical;
	jmkOS_MemCopy(commands, cd->NNCmd, cd->NNCmdLen);
	if (Hardware->identity.j9_nascent == 0x85) {
		commands[cd->NNCmdOffset - 4] = commands[cd->NNCmdOffset - 4]
		    | J9_CRACKROPE(0, MWV207REG_CONFIG_NN, POWER_CONTROL,
				   Hardware->options.configNNPowerControl);
		commands[cd->NNCmdOffset] =
		    J9_CRACKROPE(0, MWV207REG_TRIGGER_NN, COMMAND_BUFFER_ADDR,
				 (InstAddress >> 6));
	} else {
		commands[cd->NNCmdOffset] =
		    J9_CRACKROPE(0, MWV207REG_PS_TRIGGER_NN,
				 COMMAND_BUFFER_ADDR, (InstAddress >> 6))
		    | J9_CRACKROPE(0, MWV207REG_PS_TRIGGER_NN, COMMAND_EVENT_ID,
				   0);
	}

	bytes = cd->NNCmdLen;

	endLogical = (jmtUINT8_PTR) bufferLogical + bytes;
	endAddress = bufferAddress + bytes;

	if (Hardware->wlFE) {
		j9_recaution(jmkWLFE_End(Hardware, J9_CHYAK, ~0U, &endBytes));
		j9_recaution(jmkWLFE_End
			     (Hardware, endLogical, endAddress, &endBytes));
	}

	bytes += endBytes;

	JMM_kASSERT(bytes <= bufferBytes);

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

	Command->funcVidMem = bufferNode;
	Command->funcVidMemBytes = bufferBytes;
	Command->logical = bufferLogical;
	Command->address = bufferAddress;
	Command->bytes = bytes;
	Command->endAddress = endAddress;
	Command->endLogical = endLogical;
#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: nn commands]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif
	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_recaution(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

j9_duopoly
jmkHARDWARE_ResetFlopWithNN(IN jmk_HARDWARE Hardware,
			    IN jmtUINT32 AllocFlag,
			    IN OUT j9_phpht *Pool,
			    OUT j9_handle_acetylizer * Command)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 kernelXSize = J9_ENTOCONDYLAR;
	jmtUINT32 kernelYSize = J9_SPHACELATING;
	jmtUINT32 kernelZSize = J9_REDEMPTIONAL;

	jmtUINT32 inImageXSize = J9_RECOMPENSED;
	jmtUINT32 inImageYSize = J9_NONRECOURSE;
	jmtUINT32 inImageZSize = J9_UNBUCKRAMED;

	jmtUINT32 outImageXSize = J9_SUBREFERENCE;
	jmtUINT32 outImageYSize = J9_ARGILLACEOUS;
	jmtUINT32 outImageZSize = J9_UNSUSPECTFUL;

	jmtUINT32 i;
	jmtPOINTER pointer = J9_CHYAK;

	jmtUINT8 dataType;
	jmtUINT32 itemBytes = 0;
	jmsFUNCTION_EXECUTION_DATA_PTR data = J9_CHYAK;
	jmtUINT32 dataCount = 0;
	chipCmdData *cd = J9_CHYAK;

#if J9_HANDLE_J9MENU_GYNIATRICS
	jmtUINT8_PTR golden;
	jmtSIZE_T outBufBytes;

#endif

	if (!Command)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(j9_anocathartic(Hardware,
				     J9_CHYAK,
				     &dataType, J9_CHYAK, J9_CHYAK, J9_CHYAK));

	cd = j9_hologoninidia(Hardware->identity.j9_nascent,
			      Hardware->identity.chipModel,
			      Hardware->identity.j9_exquisite,
			      Hardware->identity.j9_bhagat,
			      Hardware->identity.j9sdu);
	if (cd == J9_CHYAK)
		return status;
	JMM_kASSERT(dataType == cd->InputDataType);

	j9_recaution(j9_inactionist(dataType, &itemBytes));


	dataCount = J9_HANDLE_J9MIN_EPIZOOLOGY;
	JMM_kASSERT(dataCount > 0);

	j9_recaution(jmkOS_Allocate(Hardware->os,
				    J9_NONPROS(jmsFUNCTION_EXECUTION_DATA) *
				    dataCount, &pointer));
	jmkOS_ZeroMemory(pointer,
			 J9_NONPROS(jmsFUNCTION_EXECUTION_DATA) * dataCount);
	data = (jmsFUNCTION_EXECUTION_DATA *) pointer;


	j9_recaution(j9_coconspirator(Hardware,
				      dataType,
				      kernelXSize,
				      kernelYSize,
				      kernelZSize,
				      cd,
				      AllocFlag,
				      Pool, &data[J9_HANDLE_J9M_FORBEARING]
		     ));


	j9_recaution(j9_purpurescent(Hardware,
				     dataType,
				     inImageXSize,
				     inImageYSize,
				     inImageZSize,
				     AllocFlag,
				     Pool, &data[J9_HANDLE_J9_ECSTATICAL]
		     ));


	j9_recaution(j9_infeasibility(Hardware,
				      dataType,
				      outImageXSize,
				      outImageYSize,
				      outImageZSize,
				      AllocFlag,
				      Pool, &data[J9_HANDLE_J9M_CORROSIVES]));


	j9_recaution(j9_handle__bursectomy(
				Hardware, dataType, inImageXSize, inImageYSize,
				outImageXSize, outImageYSize, outImageZSize,
				kernelXSize, kernelYSize, kernelZSize,
				data[J9_HANDLE_J9_ECSTATICAL].address,
				data[J9_HANDLE_J9M_CORROSIVES].address,
				data[J9_HANDLE_J9M_FORBEARING].address,
				cd, AllocFlag, Pool,
				&data[J9_HANDLE_J9MIRROR_INDENTWISE]));

	j9_recaution(j9_tracheofissure(
				Hardware,
				data[J9_HANDLE_J9MIRROR_INDENTWISE].address,
				cd, AllocFlag, Pool, Command));

#if J9_HANDLE_J9MENU_GYNIATRICS
	outBufBytes = outImageXSize * outImageYSize * outImageZSize * itemBytes;

	j9_recaution(jmkOS_Allocate
		     (Hardware->os, outBufBytes, &Command->golden));
	jmkOS_ZeroMemory(Command->golden, outBufBytes);
	golden = (jmtUINT8_PTR) Command->golden;
	if (Hardware->identity.j9_nascent == 0x23
	    || Hardware->identity.j9_nascent == 0x83) {
		golden[0] = 0xe3;
		golden[1] = 0x34;
		golden[2] = 0xe3;
		golden[3] = 0x34;
	} else if (Hardware->identity.j9_nascent == 0x96) {
		golden[0] = 0x50;
		golden[1] = 0x50;
	} else {
		for (i = 0; i < outBufBytes; ++i)
			golden[i] = '3';
	}
	Command->outlogical = data[J9_HANDLE_J9M_CORROSIVES].logical;
	Command->outSize = outBufBytes;
#endif

	if (Hardware->identity.j9_nascent == 0x85)
		Command->channelId = 2;
	Command->data = data;
	Command->dataCount = dataCount;

	return J9_FLUTTERING;

OnError:
	if (Command && Command->funcVidMem) {
		j9_palladinize(j9_surveillances(Hardware->kernel,
						Command->funcVidMem));
		Command->funcVidMem = J9_CHYAK;
	}
#if J9_HANDLE_J9MENU_GYNIATRICS
	if (Command->golden) {
		j9_palladinize(jmkOS_Free(Hardware->os, Command->golden));
		Command->golden = J9_CHYAK;
	}
#endif

	if (data) {
		for (i = 0; i < dataCount; i++) {
			if (data[i].bufVidMem) {
				j9_palladinize(j9_surveillances
					       (Hardware->kernel,
						data[i].bufVidMem));
			}
		}

		j9_palladinize(jmkOS_Free(Hardware->os, data));
	}

	return status;
}

static j9_duopoly
j9_colloquialist(IN jmk_HARDWARE Hardware,
		 IN jmtUINT8 DataType,
		 IN jmtUINT32 KernelXSize,
		 IN jmtUINT32 KernelYSize,
		 IN jmtUINT32 KernelZSize,
		 IN chipCmdData *cd,
		 IN jmtUINT32 AllocFlag,
		 IN OUT j9_phpht *Pool,
		 OUT jmsFUNCTION_EXECUTION_DATA *Data)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes = 0;
	jmtSIZE_T bytes;
	jmtUINT32 *buffer = J9_CHYAK;

	bytes = bufferBytes = cd->TPkerLen;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	buffer = (jmtUINT32_PTR) bufferLogical;


	jmkOS_MemCopy(bufferLogical, cd->TPKer, bytes);

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bufferBytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: TP kernel]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));
	return status;
}

static j9_duopoly
j9_preinterpret(IN jmk_HARDWARE Hardware,
		IN jmtUINT8 DataType,
		IN jmtUINT32 InImageXSize,
		IN jmtUINT32 InImageYSize,
		IN jmtUINT32 InImageZSize,
		IN jmtUINT32 AllocFlag,
		IN OUT j9_phpht *Pool,
		OUT jmsFUNCTION_EXECUTION_DATA_PTR Data)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 inputSize = InImageXSize * InImageYSize * InImageZSize;
	jmtUINT32 itemBytes = 0;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;
	jmtUINT8_PTR buffer = J9_CHYAK;
	jmtUINT32 i = 0;
	jmtUINT32 offset = 0;

	j9_recaution(j9_inactionist(DataType, &itemBytes));

	bufferBytes = inputSize * itemBytes;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	buffer = (jmtUINT8_PTR) bufferLogical;

	for (i = 0; i < inputSize; i++) {
		j9_staxis(&buffer, flopResetInputs[DataType], &offset,
			  itemBytes * 8);
	}

	bytes = buffer + (offset + 7) / 8 - (jmtUINT8_PTR) bufferLogical;

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: TP input]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

static j9_duopoly
j9_tibioscaphoid(IN jmk_HARDWARE Hardware,
		 IN jmtUINT8 DataType,
		 IN jmtUINT32 OutputXSize,
		 IN jmtUINT32 OutputYSize,
		 IN jmtUINT32 OutputZSize,
		 IN jmtUINT32 AllocFlag,
		 IN OUT j9_phpht *Pool,
		 OUT jmsFUNCTION_EXECUTION_DATA *Data)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 itemBytes = 0;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes, bytes;

	if (!Data)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(j9_inactionist(DataType, &itemBytes));

	bufferBytes = bytes =
	    (jmtSIZE_T) (OutputXSize * OutputYSize * OutputZSize * itemBytes);

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bytes));

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

static j9_duopoly
j9_handle__inimitably(IN jmk_HARDWARE Hardware,
		      IN jmtUINT8 DataType,
		      IN jmtUINT32 InImageXSize,
		      IN jmtUINT32 InImageYSize,
		      IN jmtUINT32 OutImageXSize,
		      IN jmtUINT32 OutImageYSize,
		      IN jmtUINT32 OutImageZSize,
		      IN jmtUINT32 KernelXSize,
		      IN jmtUINT32 KernelYSize,
		      IN jmtUINT32 KernelZSize,
		      IN jmtUINT32 InImageAddress,
		      IN jmtUINT32 OutImageAddress,
		      IN jmtUINT32 KernelAddress,
		      IN chipCmdData *cd,
		      IN jmtUINT32 AllocFlag,
		      IN j9_phpht *Pool,
		      OUT jmsFUNCTION_EXECUTION_DATA_PTR Data)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes;
	jmtSIZE_T bytes;
	jmtUINT32 *command = J9_CHYAK;
	jmtUINT32 i;
	jmtSIZE_T steps = 1;
	jmtUINT32 KernelAnchor = 0, OutImageAnchor = 0;

	bytes = bufferBytes = cd->TPCoreCount * J9MATHS_RHODIZONIC;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J9_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));
	jmkOS_MemCopy(bufferLogical, cd->TPIns, bytes);
	command = (jmtUINT32_PTR) bufferLogical;
	steps = bytes / J9MATHS_RHODIZONIC;
	KernelAnchor = command[11];
	OutImageAnchor = command[13];
	for (i = 0; i < steps; ++i) {
		command[i * 32 + 10] = InImageAddress;
		command[i * 32 + 11] =
		    KernelAddress + command[i * 32 + 11] - KernelAnchor;
		command[i * 32 + 13] =
		    OutImageAddress + command[i * 32 + 13] - OutImageAnchor;
	}

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bufferBytes));

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: TP instruction]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	Data->bufVidMem = bufferNode;
	Data->bufVidMemBytes = bufferBytes;
	Data->address = bufferAddress;
	Data->logical = bufferLogical;
	Data->bytes = bytes;

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_palladinize(j9_surveillances(Hardware->kernel, bufferNode));

	return status;
}

static j9_duopoly
j9_hydromechanics(IN jmk_HARDWARE Hardware,
		  IN jmtUINT32 InstAddress,
		  IN chipCmdData *cd,
		  IN jmtUINT32 AllocFlag,
		  IN j9_phpht *Pool,
		  OUT jmsFUNCTION_COMMAND_PTR Command)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkVIDMEM_NODE bufferNode = J9_CHYAK;
	jmtPOINTER bufferLogical = J9_CHYAK;
	jmtUINT32 bufferAddress = 0;
	jmtSIZE_T bufferBytes;
	jmtUINT32 bytes;
	jmtUINT32 *commands;
	jmtUINT32 startAnchor = 0;

	jmtUINT8_PTR endLogical;
	jmtUINT32 endAddress;
	jmtUINT32 endBytes = 0;
	jmtUINT32 i = 0;
	jmtUINT32 k = 1;

	bufferBytes = J9_NONPROS(jmtUINT32) * 280;
	bytes = cd->TPCmdLen;

	j9_recaution(j9_handle_extradoses(Hardware->kernel,
					  J9_HANDLE_J9_GUNPOWDERY,
					  AllocFlag,
					  Pool,
					  &bufferBytes,
					  &bufferNode,
					  &bufferLogical, &bufferAddress));

	commands = (jmtUINT32_PTR) bufferLogical;
	jmkOS_MemCopy(commands, cd->TPCmd, bytes);

	i = cd->TPCoreCount;
	startAnchor = commands[cd->TPCmdOffset[0]];
	commands[cd->TPCmdOffset[0]] =
	    (cd->TPCoreCount ==
	     1) ? (InstAddress & 0xffffffC0) : ((InstAddress & 0xffffffC0) |
						(0x1));
	if (Hardware->identity.j9_nascent == 0x85) {
		commands[cd->TPCmdOffset[0]] =
		    J9_CRACKROPE(0, MWV207REG_TRIGGER_NN, COMMAND_BUFFER_ADDR,
				 (InstAddress >> 6));
	}
	for (k = 1; k < i; k++) {
		commands[cd->TPCmdOffset[k]] =
		    commands[cd->TPCmdOffset[0]] +
		    commands[cd->TPCmdOffset[k]] - startAnchor;
	}

	endLogical = (jmtUINT8_PTR) bufferLogical + bytes;
	endAddress = bufferAddress + bytes;

	if (Hardware->wlFE) {
		j9_recaution(jmkWLFE_End(Hardware, J9_CHYAK, ~0U, &endBytes));
		j9_recaution(jmkWLFE_End
			     (Hardware, endLogical, endAddress, &endBytes));
	}

	bytes += endBytes;

	JMM_kASSERT(bytes <= bufferBytes);

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       bufferNode,
					       0, bufferLogical, bufferBytes));

	Command->funcVidMem = bufferNode;
	Command->funcVidMemBytes = bufferBytes;
	Command->logical = bufferLogical;
	Command->address = bufferAddress;
	Command->bytes = bytes;
	Command->endAddress = endAddress;
	Command->endLogical = endLogical;

#if J9MATHS_OSMOLALITY
	j9_proles(Hardware->os, "#[flop reset: TP Command]");
	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 bufferLogical, bufferAddress, bytes);
#endif

	return J9_FLUTTERING;

OnError:
	if (bufferNode)
		j9_recaution(j9_surveillances(Hardware->kernel, bufferNode));
	return status;
}

j9_duopoly
jmkHARDWARE_ResetFlopWithTP(IN jmk_HARDWARE Hardware,
			    IN jmtUINT32 AllocFlag,
			    IN j9_phpht *Pool,
			    OUT jmsFUNCTION_COMMAND_PTR Command)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT32 kernelXSize = J9_ADJUTANTSHIP;
	jmtUINT32 kernelYSize = J9_PULVERESCENT;
	jmtUINT32 kernelZSize = J9_FORTIFYINGLY;

	jmtUINT32 inImageXSize = J9_TERSULPHATE;
	jmtUINT32 inImageYSize = J9_SPERMOPHILE;
	jmtUINT32 inImageZSize = J9_MALEVOLENCE;

	jmtUINT32 outImageXSize = J9_CLETHRACEOUS;
	jmtUINT32 outImageYSize = J9_THAUMATOGENY;
	jmtUINT32 outImageZSize = J9_PHYLLOCYSTIC;

	jmtUINT32 i;
	jmtPOINTER pointer = J9_CHYAK;

	jmtUINT8 dataType;
	jmtUINT32 itemBytes = 0;
	jmsFUNCTION_EXECUTION_DATA_PTR data = J9_CHYAK;
	jmtUINT32 dataCount = 0;
	chipCmdData *cd;

#if J9_HANDLE_J9MENU_GYNIATRICS
	jmtUINT8_PTR golden;
	jmtSIZE_T outBufBytes;

#endif

	if (!Command)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	cd = j9_hologoninidia(Hardware->identity.j9_nascent,
			      Hardware->identity.chipModel,
			      Hardware->identity.j9_exquisite,
			      Hardware->identity.j9_bhagat,
			      Hardware->identity.j9sdu);
	if (cd == J9_CHYAK)
		return status;
	dataType = cd->InputDataType;
	j9_recaution(j9_inactionist(dataType, &itemBytes));


	dataCount = J9_HANDLE_J9MIN_PREPROMISE;
	JMM_kASSERT(dataCount > 0);

	j9_recaution(jmkOS_Allocate(Hardware->os,
				    J9_NONPROS(jmsFUNCTION_EXECUTION_DATA) *
				    dataCount, &pointer));
	jmkOS_ZeroMemory(pointer,
			 J9_NONPROS(jmsFUNCTION_EXECUTION_DATA) * dataCount);
	data = (jmsFUNCTION_EXECUTION_DATA *) pointer;


	j9_recaution(j9_colloquialist(Hardware,
				      dataType,
				      kernelXSize,
				      kernelYSize,
				      kernelZSize,
				      cd,
				      AllocFlag,
				      Pool, &data[J9_HANDLE_J9M_UNCIFEROUS]
		     ));


	j9_recaution(j9_preinterpret(
				Hardware, dataType, inImageXSize, inImageYSize,
				inImageZSize, AllocFlag, Pool,
				&data[J9_HANDLE_J9_PLOTTINGLY]));


	j9_recaution(j9_tibioscaphoid(
				Hardware, dataType, outImageXSize,
				outImageYSize, outImageZSize, AllocFlag,
				Pool, &data[J9_HANDLE_J9M_PERIDINIAN]));


	j9_recaution(j9_handle__inimitably(
				Hardware, dataType, inImageXSize, inImageYSize,
				outImageXSize, outImageYSize, outImageZSize,
				kernelXSize, kernelYSize, kernelZSize,
				data[J9_HANDLE_J9_PLOTTINGLY].address,
				data[J9_HANDLE_J9M_PERIDINIAN].address,
				data[J9_HANDLE_J9M_UNCIFEROUS].address,
				cd, AllocFlag, Pool,
				&data[J9_HANDLE_J9MIRROR_OUTWEIGHED]));

	j9_recaution(j9_hydromechanics(
				Hardware,
				data[J9_HANDLE_J9MIRROR_OUTWEIGHED].address,
				cd, AllocFlag, Pool, Command));

#if J9_HANDLE_J9MENU_GYNIATRICS
	outBufBytes = outImageXSize * outImageYSize * outImageZSize * itemBytes;
	j9_recaution(jmkOS_Allocate
		     (Hardware->os, outBufBytes, &Command->golden));
	jmkOS_ZeroMemory(Command->golden, outBufBytes);
	golden = (jmtUINT8_PTR) Command->golden;
	if (Hardware->identity.j9_nascent == 0x23
	    || Hardware->identity.j9_nascent == 0x83) {
		golden[0] = 0x19;
		golden[1] = 0xa9;
		golden[2] = 0x31;
		golden[3] = 0x31;
		golden[4] = 0xf9;
		golden[5] = 0x35;
		golden[6] = 0x53;
		golden[7] = 0x30;
		golden[8] = 0x3c;
		golden[9] = 0x29;
		golden[10] = 0x3b;
		golden[11] = 0x37;
		golden[12] = 0x24;
		golden[13] = 0x38;
		golden[14] = 0x33;
		golden[15] = 0x37;
		golden[16] = 0xd;
		golden[17] = 0x39;
		golden[18] = 0x6e;
		golden[19] = 0x32;
		golden[20] = 0x68;
		golden[21] = 0xba;
		golden[22] = 0x40;
		golden[23] = 0x2a;
		golden[24] = 0xab;
		golden[25] = 0xa9;
		golden[26] = 0xb;
		golden[27] = 0xb4;
		golden[28] = 0xe8;
		golden[29] = 0xab;
		golden[30] = 0x9e;
		golden[31] = 0x30;
		golden[32] = 0xf0;
		golden[33] = 0x20;
		golden[34] = 0x98;
		golden[35] = 0xb6;
		golden[36] = 0x5a;
		golden[37] = 0xb1;
		golden[38] = 0x90;
		golden[39] = 0xb4;
		golden[40] = 0xff;
		golden[41] = 0x38;
		golden[42] = 0x7c;
		golden[43] = 0xb4;
		golden[44] = 0xb6;
		golden[45] = 0x31;
		golden[46] = 0x34;
		golden[47] = 0xae;
		golden[48] = 0xa3;
		golden[49] = 0x38;
		golden[50] = 0xb4;
		golden[51] = 0x32;
		golden[52] = 0x5f;
		golden[53] = 0x31;
		golden[54] = 0x12;
		golden[55] = 0x34;
		golden[56] = 0xc0;
		golden[57] = 0x34;
		golden[58] = 0xac;
		golden[59] = 0xa6;
		golden[60] = 0x6f;
		golden[61] = 0x38;
		golden[62] = 0xfd;
		golden[63] = 0x34;
		golden[64] = 0xa7;
		golden[65] = 0xb7;
		golden[66] = 0xa0;
		golden[67] = 0x33;
		golden[68] = 0x89;
		golden[69] = 0x34;
		golden[70] = 0xb6;
		golden[71] = 0x33;
		golden[72] = 0x80;
		golden[73] = 0x94;
		golden[74] = 0x5d;
		golden[75] = 0xb2;
		golden[76] = 0x68;
		golden[77] = 0x37;
		golden[78] = 0xbb;
		golden[79] = 0xb1;
		golden[80] = 0x23;
		golden[81] = 0xb5;
		golden[82] = 0xc3;
		golden[83] = 0x28;
		golden[84] = 0xac;
		golden[85] = 0x35;
		golden[86] = 0x8a;
		golden[87] = 0xb3;
		golden[88] = 0x12;
		golden[89] = 0x34;
		golden[90] = 0x47;
		golden[91] = 0xb4;
		golden[92] = 0xa6;
		golden[93] = 0x32;
		golden[94] = 0x86;
		golden[95] = 0xb1;
		golden[96] = 0x83;
		golden[97] = 0xae;
		golden[98] = 0x6a;
		golden[99] = 0x32;
		golden[100] = 0x1a;
		golden[101] = 0xb1;
		golden[102] = 0x99;
		golden[103] = 0xb4;
		golden[104] = 0xcd;
		golden[105] = 0x32;
		golden[106] = 0x78;
		golden[107] = 0xb4;
		golden[108] = 0x66;
		golden[109] = 0x8a;
		golden[110] = 0xa6;
		golden[111] = 0xad;
		golden[112] = 0xf3;
		golden[113] = 0x2f;
		golden[114] = 0x79;
		golden[115] = 0xa0;
		golden[116] = 0x15;
		golden[117] = 0xb5;
		golden[118] = 0x1a;
		golden[119] = 0xb5;
		golden[120] = 0x4a;
		golden[121] = 0xb5;
		golden[122] = 0x4;
		golden[123] = 0xb8;
		golden[124] = 0xdc;
		golden[125] = 0x2f;
		golden[126] = 0x8e;
		golden[127] = 0x31;
	} else if (Hardware->identity.j9_nascent == 0x96) {
		golden[0] = 0x32;
		golden[1] = 0x0;
		golden[2] = 0xfe;
		golden[3] = 0xfa;
		golden[4] = 0x16;
		golden[5] = 0xfe;
		golden[6] = 0xfc;
		golden[7] = 0xf7;
		golden[8] = 0x2;
		golden[9] = 0xf;
		golden[10] = 0x3;
		golden[11] = 0xf;
		golden[12] = 0x18;
		golden[13] = 0xec;
		golden[14] = 0x6;
		golden[15] = 0xf6;
		golden[16] = 0xf7;
		golden[17] = 0xc;
		golden[18] = 0xf8;
		golden[19] = 0x4;
		golden[20] = 0xef;
		golden[21] = 0x4;
		golden[22] = 0xea;
		golden[23] = 0xfa;
		golden[24] = 0xf4;
		golden[25] = 0xd;
		golden[26] = 0xe;
		golden[27] = 0xfd;
		golden[28] = 0xee;
		golden[29] = 0xff;
		golden[30] = 0xe6;
		golden[31] = 0xfc;
		golden[32] = 0x13;
		golden[33] = 0x1;
		golden[34] = 0xf7;
		golden[35] = 0xdf;
		golden[36] = 0xe9;
		golden[37] = 0xec;
		golden[38] = 0xf;
		golden[39] = 0xf0;
		golden[40] = 0xf0;
		golden[41] = 0xb;
		golden[42] = 0xa;
		golden[43] = 0xe7;
		golden[44] = 0x0;
		golden[45] = 0xec;
		golden[46] = 0x1b;
		golden[47] = 0xf4;
		golden[48] = 0xee;
		golden[49] = 0x1b;
		golden[50] = 0xe2;
		golden[51] = 0x20;
		golden[52] = 0xe9;
		golden[53] = 0x1;
		golden[54] = 0xfe;
		golden[55] = 0x1;
		golden[56] = 0x17;
		golden[57] = 0xf7;
		golden[58] = 0x26;
		golden[59] = 0x8;
		golden[60] = 0xd8;
		golden[61] = 0xf3;
		golden[62] = 0x5;
		golden[63] = 0x1c;
	} else {
		for (i = 0; i < outBufBytes; ++i)
			golden[i] = '3';
	}

	Command->outlogical = data[J9_HANDLE_J9M_PERIDINIAN].logical;
	Command->outSize = outBufBytes;
#endif

	if (Hardware->identity.j9_nascent == 0x85)
		Command->channelId = 3;
	Command->data = data;
	Command->dataCount = dataCount;

	return J9_FLUTTERING;

OnError:
	if (Command && Command->funcVidMem) {
		j9_palladinize(j9_surveillances(Hardware->kernel,
						Command->funcVidMem));
		Command->funcVidMem = J9_CHYAK;
	}
#if J9_HANDLE_J9MENU_GYNIATRICS
	if (Command->golden) {
		j9_palladinize(jmkOS_Free(Hardware->os, Command->golden));
		Command->golden = J9_CHYAK;
	}
#endif

	if (data) {
		for (i = 0; i < dataCount; i++) {
			if (data[i].bufVidMem) {
				j9_palladinize(j9_surveillances
					       (Hardware->kernel,
						data[i].bufVidMem));
			}
		}

		j9_palladinize(jmkOS_Free(Hardware->os, data));
	}

	return status;
}


