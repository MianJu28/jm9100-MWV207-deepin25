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
#include "jmgpu_detect.h"
#include "jmgpu_protect.h"
#include "jmgpu_marshal.h"



#define J9_ACESODYNE    J9_UNDERSIGNALMEN


#define J9CGM_(reg)                                                            \
	j9pdn_(                                                                \
	    Context, index,                                                    \
	    reg##_Address >> 2,                                                \
	    reg##_ResetValue,                                                  \
	    reg##_Count,                                                       \
	    J9_YARELY, J9_YARELY                                               \
	    )

#define J9_LUMINANCE(reg, count)                                               \
	j9pdn_(                                                                \
	    Context, index,                                                    \
	    reg##_Address >> 2,                                                \
	    reg##_ResetValue,                                                  \
	    count,                                                             \
	    J9_YARELY, J9_YARELY                                               \
	    )

#define J9MIRROR_CONGRUENCE(reg, offset, count)                                \
	j9pdn_(                                                                \
	Context, index,                                                        \
	(reg##_Address >> 2) + offset,                                         \
	reg##_ResetValue,                                                      \
	count,                                                                 \
	J9_YARELY, J9_YARELY                                                   \
	)

#define J9MIRROR_QUINTUPLET(reg, mirror, count)                                \
	j9_packboard(                                                          \
	Context,                                                               \
	reg##_Address >> 2,                                                    \
	count,                                                                 \
	mirror##_Address >> 2                                                  \
	)

#define J9_SAWBUCKS(reg)                                                       \
	j9pdn_(                                                                \
	Context, index,                                                        \
	reg##_Address >> 2,                                                    \
	reg##_ResetValue,                                                      \
	reg##_Count,                                                           \
	J9_YARELY, J9_CUPPY                                                    \
	)

#define J9_SEMIRETICULATE(reg, block, count)                                   \
	j9pdn_(                                                                \
	Context, index,                                                        \
	(reg##_Address >> 2) + (block << reg##_BLK),                           \
	reg##_ResetValue,                                                      \
	count,                                                                 \
	J9_YARELY, J9_CUPPY                                                    \
	)

#define J9_HANDLE_J9M_CELIOSCOPY(reg, offset, count)                           \
	j9pdn_(                                                                \
	Context, index,                                                        \
	(reg##_Address >> 2) + offset,                                         \
	reg##_ResetValue,                                                      \
	count,                                                                 \
	J9_YARELY, J9_CUPPY                                                    \
	)

#define J9_OASAL(reg)                                                          \
	j9pdn_(                                                                \
	Context, index,                                                        \
	reg##_Address >> 2,                                                    \
	reg##_ResetValue,                                                      \
	reg##_Count,                                                           \
	J9_CUPPY, J9_YARELY                                                    \
	)

#define J9_UNCHANGINGNESS(reg, value)                                          \
	j9pdn_(                                                                \
	Context, index,                                                        \
	reg##_Address >> 2,                                                    \
	value,                                                                 \
	reg##_Count,                                                           \
	J9_YARELY, J9_YARELY                                                   \
	)

#define J9_HANDLE_J9M_PRECONCEAL(reg, offset, value)                           \
	j9pdn_(                                                                \
	Context, index,                                                        \
	(reg##_Address >> 2) + offset,                                         \
	value,                                                                 \
	1,                                                                     \
	J9_YARELY, J9_YARELY                                                   \
	)

#define J9_HANDLE_J9_ANTIRACISM(reg, value, block, count)                      \
	j9pdn_(                                                                \
	Context, index,                                                        \
	(reg##_Address >> 2) + (block << reg##_BLK),                           \
	value,                                                                 \
	count,                                                                 \
	J9_YARELY, J9_YARELY                                                   \
	)

#define J9_ARDENNITE()                                                         \
	j9_handle_congruence(Context, index)

#define J9_ICSH(reg, field)                                                    \
do {                                                                           \
	if (J9_HANDLE_STEELINESS(data, reg, MASK_##field, ENABLED))            \
		enable |= J9_DOWNSTREET(reg, field);                           \
} while (J9_YARELY)

#define J9_MAHARANEE(reg)                                                      \
	((reg##_Count) >> (reg##_BLK))


#define J9_PRECONCEALS \
	(J9_MEGAPHONICALLY(0, AQ_COMMAND_NOP_COMMAND, OPCODE, NOP) | 0xC0FFEE)

#if !J9_HANDLE__UNFEMINISE || J9_DEMISSNESS
static jmtUINT32
j9_handle_congruence(IN jmk_CONTEXT Context, IN jmtUINT32 Index)
{
	jmtUINT32_PTR buffer;
	jmtUINT32 align;


	align = (Index & 1) ? 1 : 0;


	buffer = (Context->buffer == J9_CHYAK)
	    ? J9_CHYAK : Context->buffer->logical;

	if (align && (buffer != J9_CHYAK))
		buffer[Index] = 0xDEADDEAD;


	Context->lastAddress = ~0U;


	return align;
}
#endif

#if !J9_HANDLE__UNFEMINISE
static jmtUINT32 j9_maad(IN jmk_CONTEXT Context, IN jmtUINT32 Index)
{
	if (Context->buffer != J9_CHYAK) {
		jmtUINT32_PTR buffer;


		buffer = Context->buffer->logical + Index;


		*buffer++ =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_NOP_COMMAND, OPCODE, NOP);
		*buffer++ = 0;
	}


	return 2;
}
#endif

#if J9_DEMISSNESS
static jmtUINT32
j9_voltize(IN jmk_CONTEXT Context, IN jmtUINT32 Index, IN j9_rittingerite Pipe)
{
	jmtUINT32 flushSlots;
	jmtBOOL txCacheFix;
	jmtBOOL fcFlushStall;
	jmtBOOL iCacheInvalidate;
	jmtBOOL halti5;
	jmtBOOL snapPages;
	jmtBOOL hwTFB;
	jmtBOOL blt;
	jmtBOOL peTSFlush;
	jmtBOOL multiCluster;
	jmtBOOL computeOnly;

	txCacheFix = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE__ATTRIBUTE_EQUIPOISED);

	fcFlushStall = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_J9MIN_PUZZLEHEAD);

	iCacheInvalidate = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_ATTRIBUTE_BEHAVIOUR_REMODIFIED);

	halti5 = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9MATHS_CORPORALCY);

	snapPages = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_J9MATHS_ASSIGNABLY) &&
		    jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_J9M_SEMESTRIAL);

	hwTFB = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9MATHS_TRANSMUTES);

	blt = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_J_SNOBBINESS);
	multiCluster = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_J9MA_CORROSIVES);

	peTSFlush = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_J9MA_ATTRIBUTE_DISTORTION);

	computeOnly = jmkHARDWARE_IsFeatureAvailable(Context->hardware,
				J9_HANDLE_J9M_DELIQUESCE);

	flushSlots = blt ? 10 : 6;

	if (Pipe == J9_SYNAPTAI) {
		if (!txCacheFix) {

			flushSlots += blt ? 8 : 4;
		}


		flushSlots += 2;
	}


	if (fcFlushStall && !computeOnly)
		flushSlots += blt ? ((!peTSFlush) ? 14 : 10) : 6;

	if (iCacheInvalidate && !halti5)
		flushSlots += blt ? 16 : 12;


	if (hwTFB)
		flushSlots += 2;


	if (snapPages)
		flushSlots += 2;

	if (Context->buffer != J9_CHYAK) {
		jmtUINT32_PTR buffer;


		buffer = Context->buffer->logical + Index;

		if (Pipe == J9_SYNAPTAI && !txCacheFix) {
			if (blt) {

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, LOCK);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						AQSemaphoreRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE, SOURCE,
						FRONT_END) |
					    J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE,
						DESTINATION,
						BLT_ENGINE);


				*buffer++ = J9_MEGAPHONICALLY(0,
						STALL_COMMAND, OPCODE, STALL);

				*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, STALL_STALL,
						DESTINATION, BLT_ENGINE);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, UNLOCK);
			} else {

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						AQSemaphoreRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE, SOURCE,
						FRONT_END) |
					    J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE,
						DESTINATION,
						PIXEL_ENGINE);


				*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
						OPCODE, STALL);

				*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, STALL_STALL,
						DESTINATION, PIXEL_ENGINE);
			}
		}


		*buffer++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE) |
			    J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1) |
			    J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, AQFlushRegAddrs);

		*buffer++ = (Pipe == J9_GUNSMITH) ?
			J9_MEGAPHONICALLY(0, AQ_FLUSH, PE2D_CACHE, ENABLE) :
			(J9_MEGAPHONICALLY(0, AQ_FLUSH, ZCACHE, ENABLE) |
			 J9_MEGAPHONICALLY(0, AQ_FLUSH, CCACHE, ENABLE) |
			 (multiCluster ? 0 :
			  J9_MEGAPHONICALLY(0, AQ_FLUSH, TCACHE, ENABLE)) |
			 J9_MEGAPHONICALLY(0, AQ_FLUSH, SHL1_CACHE, ENABLE) |
			 J9_MEGAPHONICALLY(0, AQ_FLUSH, VSSHL1_CACHE, ENABLE) |
			 J9_MEGAPHONICALLY(0, AQ_FLUSH, PSSHL1_CACHE, ENABLE));

		if (hwTFB) {
			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regTFBInvalidateRegAddrs) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1);

			*buffer++ = MWV207REG_TFB_INVALIDATE_INVALIDATE_TRUE;
		}


		if (Pipe == J9_SYNAPTAI) {
			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, AQFlushRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_FLUSH, VST_CACHE, ENABLE);
		}


		if (blt) {

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL, LOCK);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, AQSemaphoreRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_SEMAPHORE, SOURCE,
					FRONT_END) |
				    J9_MEGAPHONICALLY(0,
					AQ_SEMAPHORE, DESTINATION,
					BLT_ENGINE);


			*buffer++ = J9_MEGAPHONICALLY(0,
					STALL_COMMAND, OPCODE, STALL);

			*buffer++ = J9_MEGAPHONICALLY(0,
					STALL_STALL, SOURCE, FRONT_END) |
				    J9_MEGAPHONICALLY(0,
					STALL_STALL, DESTINATION,
					BLT_ENGINE);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL, UNLOCK);
		} else {
			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, AQSemaphoreRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
					SOURCE, FRONT_END) |
				    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
					DESTINATION, PIXEL_ENGINE);


			*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
					OPCODE, STALL);

			*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
					SOURCE, FRONT_END) |
				    J9_MEGAPHONICALLY(0, STALL_STALL,
					DESTINATION, PIXEL_ENGINE);
		}

		if (fcFlushStall && !computeOnly) {
			if (!peTSFlush && blt) {
				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, LOCK);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltCacheFlushRegAddrs) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_CACHE_FLUSH,
						TILE_CACHE, ENABLE);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, UNLOCK);
			} else {
				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						jmTileCacheFlushRegAddrs) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1);

				*buffer++ = J9_MEGAPHONICALLY(0,
						JM_TILE_CACHE_FLUSH,
						FLUSH, ENABLE);
			}


			if (blt) {

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, LOCK);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS, AQSemaphoreRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE, SOURCE,
						FRONT_END) |
					    J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE, DESTINATION,
						BLT_ENGINE);


				*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
						OPCODE, STALL);

				*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, STALL_STALL,
						DESTINATION, BLT_ENGINE);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, UNLOCK);
			} else {
				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS, AQSemaphoreRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
						DESTINATION, PIXEL_ENGINE);


				*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
						OPCODE, STALL);

				*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, STALL_STALL,
						DESTINATION, PIXEL_ENGINE);
			}
		}

		if (iCacheInvalidate && !halti5) {

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regShaderConfigRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_SHADER_CONFIG,
					INST_DECODE_SELECT, VS);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regSHCacheControlRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_SH_CACHE_CONTROL,
					MODE, MEMORY) |
				    J9_CRACKROPE(0, MWV207REG_SH_CACHE_CONTROL,
					INVALIDATE_VS, 1);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regShaderConfigRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_SHADER_CONFIG,
					INST_DECODE_SELECT, PS);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regSHCacheControlRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_SH_CACHE_CONTROL,
					MODE, MEMORY) |
				    J9_CRACKROPE(0,
					MWV207REG_SH_CACHE_CONTROL,
					INVALIDATE_PS, 1);


			if (blt) {

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, LOCK);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						AQSemaphoreRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
						DESTINATION, BLT_ENGINE);


				*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
						OPCODE, STALL);

				*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, STALL_STALL,
						DESTINATION, BLT_ENGINE);

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL, UNLOCK);
			} else {
				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					    J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS, AQSemaphoreRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
						DESTINATION, PIXEL_ENGINE);


				*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
						OPCODE, STALL);

				*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
						SOURCE, FRONT_END) |
					    J9_MEGAPHONICALLY(0, STALL_STALL,
						DESTINATION, PIXEL_ENGINE);
			}
		}

		if (snapPages) {
			*buffer++ = J9_MEGAPHONICALLY(0,
					JMCMD_SNAP_TO_PAGE_COMMAND,
					OPCODE, SNAP_TO_PAGE) |
				    J9_MEGAPHONICALLY(0,
					JMCMD_SNAP_TO_PAGE_COMMAND,
					CLIENT, VS) |
				    J9_MEGAPHONICALLY(0,
					JMCMD_SNAP_TO_PAGE_COMMAND,
					CLIENT, TCS) |
				    J9_MEGAPHONICALLY(0,
					JMCMD_SNAP_TO_PAGE_COMMAND,
					CLIENT, TES) |
				    J9_MEGAPHONICALLY(0,
					JMCMD_SNAP_TO_PAGE_COMMAND,
					CLIENT, GS) |
				    J9_MEGAPHONICALLY(0,
					JMCMD_SNAP_TO_PAGE_COMMAND,
					CLIENT, PS);

			*buffer++ = 0;
		}
	}


	return flushSlots;
}
#endif

#if J9_DEMISSNESS
static jmtUINT32 j9_ungroundable(IN jmk_CONTEXT Context, IN jmtUINT32 Index)
{
	jmtBOOL blt =
	    jmkHARDWARE_IsFeatureAvailable(Context->hardware,
					   J9_HANDLE_J_SNOBBINESS);
	if (Context->buffer != J9_CHYAK) {
		jmtUINT32_PTR buffer;


		buffer = Context->buffer->logical + Index;

		if (blt) {

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL, LOCK);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, AQSemaphoreRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
					SOURCE, FRONT_END) |
				    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
					DESTINATION, BLT_ENGINE);


			*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
					OPCODE, STALL);

			*buffer++ = J9_MEGAPHONICALLY(0, STALL_STALL,
					SOURCE, FRONT_END) |
				    J9_MEGAPHONICALLY(0, STALL_STALL,
					DESTINATION, BLT_ENGINE);

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
				mwv207regBltGeneralControlRegAddrs);

			*buffer = J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL, UNLOCK);
		} else {

			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, AQSemaphoreRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
					SOURCE, FRONT_END) |
				    J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
					DESTINATION, PIXEL_ENGINE);


			*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND,
					OPCODE, STALL);
			*buffer = J9_MEGAPHONICALLY(0, STALL_STALL,
					SOURCE, FRONT_END) |
				  J9_MEGAPHONICALLY(0, STALL_STALL,
					DESTINATION, PIXEL_ENGINE);
		}
	}


	return (blt ? 8 : 4);
}
#endif

#if (J9_DEMISSNESS || J9_MONGRELISE)

#if J9_HANDLE_J9M_ASSIGNABLY
typedef struct {
	jmtUINT inputBase;
	jmtUINT count;
	jmtUINT outputBase;
} jmsSTATEMIRROR;

const jmsSTATEMIRROR mirroredStates[] = {
	{ mwv207regTXGpipeSamplerCtrl0RegAddrs, 0x300,
	 mwv207regTXPixelSamplerCtrl0RegAddrs },
	{ mwv207regTXGpipeTextureDescriptorAddrRegAddrs, 0x100,
	 mwv207regTXPixelTextureDescriptorAddrRegAddrs },
	{ mwv207regPixelUniformsRegAddrs, 0x140,
	 mwv207regGpipeUniformsRegAddrs },
};

jmtUINT mirroredStatesCount;

static j9_duopoly j9_juberous(IN jmsSTATE_DELTA_PTR StateDelta)
{

	StateDelta->id += 1;


	if (StateDelta->id == 0) {

		jmkOS_ZeroMemory(J9_PROVINCIALISMS(StateDelta->mapEntryID),
				 StateDelta->mapEntryIDSize);


		StateDelta->id += 1;
	}


	StateDelta->elementCount = 0;


	StateDelta->recordCount = 0;


	return J9_FLUTTERING;
}

static j9_duopoly
j9_subcordate(IN jmk_CONTEXT Context, IN jmsSTATE_DELTA_PTR delta)
{
	jmtUINT_PTR mapEntryIndex = J9_PROVINCIALISMS(delta->mapEntryIndex);
	jmtUINT_PTR mapEntryID = J9_PROVINCIALISMS(delta->mapEntryID);
	jmsSTATE_DELTA_RECORD_PTR recordArray =
	    J9_PROVINCIALISMS(delta->recordArray);
	j9_duopoly status = J9_FLUTTERING;

	j9_quincunx();


	if (mapEntryIndex != J9_CHYAK)
		j9_recaution(j9_overorganizing(Context->os, mapEntryIndex));


	if (mapEntryID != J9_CHYAK)
		j9_recaution(j9_overorganizing(Context->os, mapEntryID));


	if (recordArray != J9_CHYAK)
		j9_recaution(j9_overorganizing(Context->os, recordArray));

	j9_recaution(j9_overorganizing(Context->os, delta));

OnError:


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static j9_duopoly
j9_phoniatrics(IN jmk_CONTEXT Context, OUT jmsSTATE_DELTA_PTR * Delta)
{
	jmk_CONTEXT context = Context;
	jmk_OS os = context->os;
	j9_duopoly status;
	jmsSTATE_DELTA_PTR delta = J9_CHYAK;
	jmtPOINTER pointer = J9_CHYAK;

	j9_quincunx();

	if (context->maxState == 0) {
		*Delta = NULL;
		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}


	j9_recaution(jmkOS_Allocate
		     (os, J9_NONPROS(j9_revalidating), (jmtPOINTER *)&delta));


	jmkOS_ZeroMemory(delta, J9_NONPROS(j9_revalidating));

	if (context->maxState > 0) {

		jmtSIZE_T bytes = J9_NONPROS(jmtUINT) * context->maxState;


		j9_recaution(jmkOS_Allocate(os, bytes, &pointer));

		delta->mapEntryID = J9_SUBAUDIBLENESS(pointer);


		delta->mapEntryIDSize = (jmtUINT32) bytes;


		jmkOS_ZeroMemory(J9_PROVINCIALISMS(delta->mapEntryID), bytes);


		j9_recaution(jmkOS_Allocate(os, bytes, &pointer));

		delta->mapEntryIndex = J9_SUBAUDIBLENESS(pointer);

	}

	if (context->numStates > 0) {

		j9_recaution(jmkOS_Allocate(os,
					    J9_NONPROS(j9_handle_j_coruscated) *
					    context->numStates, &pointer));

		delta->recordArray = J9_SUBAUDIBLENESS(pointer);
	}


	j9_juberous(delta);

	*Delta = delta;

	JMM_kFOOTER();
	return status;

OnError:
	if (delta)
		j9_subcordate(Context, delta);

	JMM_kFOOTER_NO();
	return status;
}
#endif

static jmtUINT32
j9_ginglymi(IN jmk_CONTEXT Context, IN jmtUINT32 Index, IN j9_rittingerite Pipe)
{
	jmtUINT32 slots = 2;

	if (Context->buffer != J9_CHYAK) {
		jmtUINT32_PTR buffer;


		buffer = Context->buffer->logical + Index;


		*buffer++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE) |
			    J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, AQPipeSelectRegAddrs) |
			    J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1);

		*buffer = (Pipe == J9_GUNSMITH)  ?
			AQ_PIPE_SELECT_PIPE_PIPE2D :
			AQ_PIPE_SELECT_PIPE_PIPE3D;
	}

	Context->pipeSelectBytes = slots * J9_NONPROS(jmtUINT32);

	return slots;
}
#endif

#if !J9_HANDLE__UNFEMINISE || J9_DEMISSNESS
static jmtUINT32
j9pdn_(IN jmk_CONTEXT Context,
	IN jmtUINT32 Index,
	IN jmtUINT32 Address,
	IN jmtUINT32 Value,
	IN jmtUINT32 Size, IN jmtBOOL FixedPoint, IN jmtBOOL Hinted)
{
	jmtUINT32_PTR buffer;
	jmtUINT32 align;
	jmtUINT32 i;


	align = (Index & 1) ? 1 : 0;


	buffer = (Context->buffer == J9_CHYAK)
	    ? J9_CHYAK : Context->buffer->logical;

	if ((buffer == J9_CHYAK) && (Address + Size > Context->maxState)) {

		Context->maxState = Address + Size;
	}

	if (buffer == J9_CHYAK) {

		Context->numStates += Size;
	}


	if ((Address != Context->lastAddress)
	    || (FixedPoint != Context->lastFixed)) {
		if (buffer != J9_CHYAK) {
			if (align) {

				buffer[Index++] = 0xDEADDEAD;
			}


			JMM_kASSERT((Index & 1) == 0);

			if (FixedPoint) {
				buffer[Index] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, FIXED16_DOT16) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, Size) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS, Address);
			} else {
				buffer[Index] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, NORMAL) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, Size) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS, Address);
			}


			for (i = 0; i < (jmtUINT32) Size; i += 1) {

				buffer[Index + 1 + i] = Value;


				Context->map[Address + i].index =
				    (jmtUINT) Index + 1 + i;
			}
		}


		Context->lastIndex = (jmtUINT) Index;
		Context->lastAddress = Address + (jmtUINT32) Size;
		Context->lastSize = Size;
		Context->lastFixed = FixedPoint;


		return align + 1 + Size;
	}


	if (buffer != J9_CHYAK) {

		buffer[Context->lastIndex] =
		    J9_CRACKROPE(buffer[Context->lastIndex],
				 AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,
				 Context->lastSize + Size);


		for (i = 0; i < (jmtUINT32) Size; i += 1) {

			buffer[Index + i] = Value;


			Context->map[Address + i].index = (jmtUINT) Index + i;
		}
	}


	Context->lastAddress += (jmtUINT32) Size;
	Context->lastSize += Size;


	return Size;
}

static jmtUINT32
j9_packboard(IN jmk_CONTEXT Context,
	     IN jmtUINT32 Address,
	     IN jmtUINT32 Size, IN jmtUINT32 AddressMirror)
{
	jmtUINT32 i;


	if (Context->buffer != J9_CHYAK) {

		for (i = 0; i < Size; i++) {

			Context->map[Address + i].index =
			    Context->map[AddressMirror + i].index;
		}
	}


	return Size;
}

static void
j9_lonesomenesses(IN jmk_CONTEXT Context,
		  IN jmtUINT32 Address, IN jmtUINT32 Size, IN jmtUINT32 Count)
{
	jmtUINT base;
	jmtUINT nopCount;
	jmtUINT32_PTR nop;
	jmsCONTEXT_PTR buffer;
	jmsSTATE_MAP_PTR map;
	jmtUINT i;


	buffer = Context->buffer;


	map = Context->map;

	base = map[Address].index;

	if (Count > 1024) {
		buffer->logical[base - 1] =
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					FLOAT, NORMAL) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1024) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, Address);

		buffer->logical[base + 1024 + 1] =
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					FLOAT, NORMAL) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, Count - 1024) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, Address + 1024);


		nopCount = (Size / 2) - (Count / 2);

		nop = &buffer->logical[base + (Count | 1) + 2];


		for (i = 0; i < nopCount; i += 1) {
			if (nop >= buffer->logical + Context->totalSize)
				break;


			*nop = J9_MEGAPHONICALLY(0, AQ_COMMAND_NOP_COMMAND,
					OPCODE, NOP);


			nop += 2;
		}
	} else {
		buffer->logical[base - 1] =
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					FLOAT, NORMAL) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, Count) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, Address);


		nopCount = (Size / 2) - (Count / 2) + Size / 1024;


		nop = &buffer->logical[base + (Count | 1)];


		for (i = 0; i < nopCount; i += 1) {
			if (nop >= buffer->logical + Context->totalSize)
				break;


			*nop = J9_MEGAPHONICALLY(0, AQ_COMMAND_NOP_COMMAND,
					OPCODE, NOP);


			nop += 2;
		}
	}
}
#endif

#if (J9_DEMISSNESS || J9_MONGRELISE)

static j9_duopoly j9_handle_j9_attribute_interester(IN jmk_CONTEXT Context)
{
	jmtUINT32_PTR buffer;
	jmtUINT32 index;

#if J9_DEMISSNESS
	jmtBOOL halti5;
	jmtBOOL hasSecurity;
	jmtBOOL hasRobustness;
	jmtBOOL multiCluster;
	jmtUINT clusterAliveMask;
#endif

	jmk_HARDWARE hardware;

	j9_quincunx();

	hardware = Context->hardware;

	j9maths_activation(hardware, J9_CONTRACEPTIVE);


	index = 0;


	Context->lastAddress = ~0U;


	buffer = (Context->buffer == J9_CHYAK)
	    ? J9_CHYAK : Context->buffer->logical;




#if !J9_HANDLE__UNFEMINISE
	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9MIRROR_RHYMESTERS)) {

		index += j9_voltize(Context, index, J9_SYNAPTAI);


		index += j9_ginglymi(Context, index, J9_GUNSMITH);

		index += J9CGM_(MWV207REG_FEDE_TIMEOUT);


		index += J9_SAWBUCKS(AQDE_SRC_ADDRESS);
		index += J9CGM_(AQDE_SRC_STRIDE);
		index += J9CGM_(AQDE_SRC_ROTATION_CONFIG);
		index += J9CGM_(AQDE_SRC_CONFIG);
		index += J9CGM_(AQDE_SRC_ORIGIN);
		index += J9CGM_(AQDE_SRC_SIZE);
		index += J9CGM_(AQDE_SRC_COLOR_BG);
		index += J9CGM_(AQDE_SRC_COLOR_FG);


		index += J9CGM_(AQDE_STRETCH_FACTOR_LOW);
		index += J9CGM_(AQDE_STRETCH_FACTOR_HIGH);


		index += J9_SAWBUCKS(AQDE_DEST_ADDRESS);
		index += J9CGM_(AQDE_DEST_STRIDE);
		index += J9CGM_(AQDE_DEST_ROTATION_CONFIG);
		index += J9CGM_(AQDE_DEST_CONFIG);


		index += J9_SAWBUCKS(AQDE_PATTERN_ADDRESS);
		index += J9CGM_(AQDE_PATTERN_LOW);
		index += J9CGM_(AQDE_PATTERN_HIGH);
		index += J9CGM_(AQDE_PATTERN_MASK_LOW);
		index += J9CGM_(AQDE_PATTERN_MASK_HIGH);
		index += J9CGM_(AQDE_PATTERN_BG_COLOR);
		index += J9CGM_(AQDE_PATTERN_FG_COLOR);
		index += J9CGM_(AQDE_PATTERN_CONFIG);


		index += J9CGM_(AQDE_FILTER_BLIT);
		index += J9CGM_(AQDE_FILTER_KERNEL);


		index += J9CGM_(AQDE_INDEX_COLOR_TABLE);


		index += J9CGM_(AQDE_ROP);
		index += J9CGM_(AQDE_CLIP_TOP_LEFT);
		index += J9CGM_(AQDE_CLIP_BOTTOM_RIGHT);
		index += J9CGM_(AQDE_CLEAR_BYTE_MASK);
		index += J9CGM_(AQDE_CLEAR_PIXEL_VALUE_LOW);
		index += J9CGM_(AQDE_CLEAR_PIXEL_VALUE_HIGH);
		index += J9CGM_(AQDE_CONFIG);
		index += J9CGM_(AQDE_SRC_ORIGIN_FRACTION);


		index += J9CGM_(AQDE_ALPHA_CONTROL);
		index += J9CGM_(AQDE_ALPHA_MODES);


		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J9M_ABRIDGABLE)) {
			index += J9_SAWBUCKS(UPLANE_ADDRESS);
			index += J9CGM_(UPLANE_STRIDE);
			index += J9_SAWBUCKS(VPLANE_ADDRESS);
			index += J9CGM_(VPLANE_STRIDE);
			index += J9CGM_(AQVR_SOURCE_IMAGE_LOW);
			index += J9CGM_(AQVR_SOURCE_IMAGE_HIGH);
			index += J9CGM_(AQVR_SOURCE_ORIGIN_LOW);
			index += J9CGM_(AQVR_SOURCE_ORIGIN_HIGH);
			index += J9CGM_(AQVR_TARGET_WINDOW_LOW);
			index += J9CGM_(AQVR_TARGET_WINDOW_HIGH);
			index += J9CGM_(AQVR_CONFIG_EX);
		}


		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9MATHS_ACETARSONE)) {
			index += J9CGM_(AQPE_CONFIG);
			index += J9CGM_(AQDE_DST_ROTATION_HEIGHT);
			index += J9CGM_(AQDE_SRC_ROTATION_HEIGHT);
			index += J9CGM_(AQDE_ROT_ANGLE);
			index += J9CGM_(AQDE_CLEAR_PIXEL_VALUE32);
			index += J9CGM_(AQDE_DEST_COLOR_KEY);
			index += J9CGM_(AQDE_GLOBAL_SRC_COLOR);
			index += J9CGM_(AQDE_GLOBAL_DEST_COLOR);
			index += J9CGM_(AQDE_COLOR_MULTIPLY_MODES);
			index += J9CGM_(AQPE_TRANSPARENCY);
			index += J9CGM_(AQPE_CONTROL);
			index += J9CGM_(AQDE_SRC_COLOR_KEY_HIGH);
			index += J9CGM_(AQDE_DEST_COLOR_KEY_HIGH);
			index += J9CGM_(AQDE_INDEX_COLOR_TABLE32);
		}


#ifdef JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D
		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J9_ATTRIBUTE_BEHAVIOUR_BALLBUSTER)) {
			index += J9CGM_(AQPE_DITHER_LOW);
			index += J9CGM_(AQPE_DITHER_HIGH);
		}
#endif


#ifdef JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER
		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_ATTRIBUTE_POLYGAMIAN)) {
			index += J9CGM_(AQDE_HORI_FILTER_KERNEL);
			index += J9CGM_(AQDE_VERTI_FILTER_KERNEL);
			index += J9CGM_(AQBW_CONFIG);
			index += J9CGM_(AQBW_BLOCK_SIZE);
			index += J9CGM_(AQBW_TILE_SIZE);
			index += J9CGM_(AQBW_BLOCK_MASK);
			index += J9CGM_(AQDE_SRC_EX_CONFIG);
			index += J9CGM_(AQDE_SRC_EX_ADDRESS);
		}
#endif

		index += J9_ARDENNITE();

		Context->linkIndex2D = index;
		index += j9_maad(Context, index);
	}
#endif

#if J9_DEMISSNESS



	halti5 = jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_CORPORALCY);
	hasSecurity =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_PREREJOICE);
	hasRobustness =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J_ECSTATICAL);
	multiCluster =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9MA_CORROSIVES);
	clusterAliveMask = hardware->identity.clusterAvailMask &
			   hardware->options.userClusterMask;


	Context->entryOffset3D = (jmtUINT) index * J9_NONPROS(jmtUINT32);


	index += j9_ginglymi(Context, index, J9_SYNAPTAI);

	if (multiCluster) {
		index += J9_HANDLE_J9_ANTIRACISM(
				MWV207REG_CLUSTER_CONTROL,
				J9_CRACKROPE(0, MWV207REG_CLUSTER_CONTROL,
					CLUSTER_ALIVE_ENABLE,
					clusterAliveMask),
				0, 4);
		index += J9_UNCHANGINGNESS(
				MWV207REG_CLUSTER_CHECKER_BOARD,
				J9_MEGAPHONICALLY(0,
					MWV207REG_CLUSTER_CHECKER_BOARD,
					SIZE, BLOCK32X32));
	}


#if J9_NOONED && defined(mwv207regContextRegAddrs)
	index += J9CGM_(MWV207REG_CONTEXT);
#endif

	index += j9_voltize(Context, index, J9_SYNAPTAI);


	if (hasSecurity) {
		index += J9CGM_(MWV207REG_APP_CONTEXT_ID_LOW);
		index += J9_ARDENNITE();
		index += J9CGM_(MWV207REG_APP_CONTEXT_ID_HIGH);
	}

	if (halti5) {
		jmtUINT32 uscControl =
			J9_CRACKROPE(0, MWV207REG_USC_CONTROL,
				 MEMORY_CONTROLLER_SELECT, 2);
		index += J9CGM_(MWV207REG_SEMANTIC_LOCATION);
		index += J9CGM_(MWV207REG_SEMANTICS);

		uscControl |=
		    J9_CRACKROPE(0, MWV207REG_USC_CONTROL, CACHE_PAGES,
				 hardware->options.uscL1CacheRatio);
		if (multiCluster) {
			uscControl |=
				J9_CRACKROPE(0, MWV207REG_USC_CONTROL,
					ATTRIB_CACHE_PAGES,
					hardware->options.uscAttribCacheRatio);
		}
		index += J9_UNCHANGINGNESS(MWV207REG_USC_CONTROL, uscControl);
	} else {
		index += J9CGM_(MWV207REG_VARYING_PACKING);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_LOW);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_HIGH);
		index += J9CGM_(MWV207REG_VARYING_PACKING_EX);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_EX);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_EX2);
	}

	index += J9_ARDENNITE();


	index += J9CGM_(JM_MEMORY_CONFIG);

	if (hasSecurity || hasRobustness) {
		index += J9_UNCHANGINGNESS(
				MWV207REG_MMU_CONFIG,
				J9_MEGAPHONICALLY(0,
					MWV207REG_MMU_CONFIG,
					MASK_PAGE_TABLE_ID,
					MASKED));
	}


	index += j9_ungroundable(Context, index);
#endif




	Context->linkIndex3D = (jmtUINT) index;

	if (buffer != J9_CHYAK) {
		buffer[index + 0] = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LINK_COMMAND, OPCODE,
					LINK) |
				    J9_CRACKROPE(0, AQ_COMMAND_LINK_COMMAND,
					PREFETCH, 0);

		buffer[index + 1] = 0;
	}

	index += 2;


	Context->bufferSize = index * J9_NONPROS(jmtUINT32);





	Context->entryOffsetXDFrom2D = (jmtUINT) index * J9_NONPROS(jmtUINT32);


	index += j9_ginglymi(Context, index, J9_SYNAPTAI);


	Context->linkIndexXD = (jmtUINT) index;

	if (buffer != J9_CHYAK) {
		buffer[index + 0] = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LINK_COMMAND,
					OPCODE, LINK) |
				    J9_CRACKROPE(0, AQ_COMMAND_LINK_COMMAND,
					PREFETCH, 0);

		buffer[index + 1] = 0;
	}

	index += 2;




	Context->totalSize = index * J9_NONPROS(jmtUINT32);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

}

static j9_duopoly j9_handle_j9m_centermost(IN jmk_CONTEXT Context)
{
	jmtUINT32_PTR buffer = J9_CHYAK;
	jmtUINT32 index;

#if J9_DEMISSNESS
	jmtBOOL halti0, halti1, halti2, halti3, halti4, halti5;
	jmtUINT i;
	jmtUINT vertexUniforms, fragmentUniforms;
	jmtBOOL unifiedUniform;
	jmtBOOL hasGS, hasTS;
	jmtBOOL genericAttrib;
	jmtBOOL hasICache;
	jmtBOOL hasICachePrefetch;
	jmtUINT numRT = 0;
	jmtUINT numSamplers = 32;
	jmtBOOL hasTXdesc;
	jmtBOOL hasSecurity;
	jmtBOOL hasRobustness;
	jmtBOOL multiCluster;
	jmtBOOL smallBatch;
	jmtBOOL multiCoreBlockSetCfg2;
	jmtUINT clusterAliveMask[J9_HANDLE_J9M_PIPEFISHES];
	jmtBOOL hasPSCSThrottle;
	jmtBOOL hasMsaaFragOperation;
	jmtBOOL newGPipe;
	jmtBOOL computeOnly;
#if J9_PRISM && J9_ERRONEOUSLY
	jmtUINT PEFenceEndianControl;
#endif
#endif

	jmk_HARDWARE hardware;

	j9_quincunx();

	hardware = Context->hardware;

	j9maths_activation(hardware, J9_CONTRACEPTIVE);

	if (!hardware->options.hasShader)
		return j9_handle_j9_attribute_interester(Context);


	index = 0;


	Context->lastAddress = ~0U;


	buffer = (Context->buffer == J9_CHYAK)
	    ? J9_CHYAK : Context->buffer->logical;




#if !J9_HANDLE__UNFEMINISE
	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9MIRROR_RHYMESTERS)) {

		index += j9_voltize(Context, index, J9_SYNAPTAI);


		index += j9_ginglymi(Context, index, J9_GUNSMITH);

		index += J9CGM_(MWV207REG_FEDE_TIMEOUT);


		index += J9_SAWBUCKS(AQDE_SRC_ADDRESS);
		index += J9CGM_(AQDE_SRC_STRIDE);
		index += J9CGM_(AQDE_SRC_ROTATION_CONFIG);
		index += J9CGM_(AQDE_SRC_CONFIG);
		index += J9CGM_(AQDE_SRC_ORIGIN);
		index += J9CGM_(AQDE_SRC_SIZE);
		index += J9CGM_(AQDE_SRC_COLOR_BG);
		index += J9CGM_(AQDE_SRC_COLOR_FG);


		index += J9CGM_(AQDE_STRETCH_FACTOR_LOW);
		index += J9CGM_(AQDE_STRETCH_FACTOR_HIGH);


		index += J9_SAWBUCKS(AQDE_DEST_ADDRESS);
		index += J9CGM_(AQDE_DEST_STRIDE);
		index += J9CGM_(AQDE_DEST_ROTATION_CONFIG);
		index += J9CGM_(AQDE_DEST_CONFIG);


		index += J9_SAWBUCKS(AQDE_PATTERN_ADDRESS);
		index += J9CGM_(AQDE_PATTERN_LOW);
		index += J9CGM_(AQDE_PATTERN_HIGH);
		index += J9CGM_(AQDE_PATTERN_MASK_LOW);
		index += J9CGM_(AQDE_PATTERN_MASK_HIGH);
		index += J9CGM_(AQDE_PATTERN_BG_COLOR);
		index += J9CGM_(AQDE_PATTERN_FG_COLOR);
		index += J9CGM_(AQDE_PATTERN_CONFIG);


		index += J9CGM_(AQDE_FILTER_BLIT);
		index += J9CGM_(AQDE_FILTER_KERNEL);


		index += J9CGM_(AQDE_INDEX_COLOR_TABLE);


		index += J9CGM_(AQDE_ROP);
		index += J9CGM_(AQDE_CLIP_TOP_LEFT);
		index += J9CGM_(AQDE_CLIP_BOTTOM_RIGHT);
		index += J9CGM_(AQDE_CLEAR_BYTE_MASK);
		index += J9CGM_(AQDE_CLEAR_PIXEL_VALUE_LOW);
		index += J9CGM_(AQDE_CLEAR_PIXEL_VALUE_HIGH);
		index += J9CGM_(AQDE_CONFIG);
		index += J9CGM_(AQDE_SRC_ORIGIN_FRACTION);


		index += J9CGM_(AQDE_ALPHA_CONTROL);
		index += J9CGM_(AQDE_ALPHA_MODES);


		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J9M_ABRIDGABLE)) {
			index += J9_SAWBUCKS(UPLANE_ADDRESS);
			index += J9CGM_(UPLANE_STRIDE);
			index += J9_SAWBUCKS(VPLANE_ADDRESS);
			index += J9CGM_(VPLANE_STRIDE);
			index += J9CGM_(AQVR_SOURCE_IMAGE_LOW);
			index += J9CGM_(AQVR_SOURCE_IMAGE_HIGH);
			index += J9CGM_(AQVR_SOURCE_ORIGIN_LOW);
			index += J9CGM_(AQVR_SOURCE_ORIGIN_HIGH);
			index += J9CGM_(AQVR_TARGET_WINDOW_LOW);
			index += J9CGM_(AQVR_TARGET_WINDOW_HIGH);
			index += J9CGM_(AQVR_CONFIG_EX);
		}


		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9MATHS_ACETARSONE)) {
			index += J9CGM_(AQPE_CONFIG);
			index += J9CGM_(AQDE_DST_ROTATION_HEIGHT);
			index += J9CGM_(AQDE_SRC_ROTATION_HEIGHT);
			index += J9CGM_(AQDE_ROT_ANGLE);
			index += J9CGM_(AQDE_CLEAR_PIXEL_VALUE32);
			index += J9CGM_(AQDE_DEST_COLOR_KEY);
			index += J9CGM_(AQDE_GLOBAL_SRC_COLOR);
			index += J9CGM_(AQDE_GLOBAL_DEST_COLOR);
			index += J9CGM_(AQDE_COLOR_MULTIPLY_MODES);
			index += J9CGM_(AQPE_TRANSPARENCY);
			index += J9CGM_(AQPE_CONTROL);
			index += J9CGM_(AQDE_SRC_COLOR_KEY_HIGH);
			index += J9CGM_(AQDE_DEST_COLOR_KEY_HIGH);
			index += J9CGM_(AQDE_INDEX_COLOR_TABLE32);
		}


#ifdef JM_MINOR_FEATURES1_DITHER_AND_FILTER_PLUS_ALPHA_2D
		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J9_ATTRIBUTE_BEHAVIOUR_BALLBUSTER)) {
			index += J9CGM_(AQPE_DITHER_LOW);
			index += J9CGM_(AQPE_DITHER_HIGH);
		}
#endif


#ifdef JM_MINOR_FEATURES2_ONE_PASS_2D_FILTER
		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_ATTRIBUTE_POLYGAMIAN)) {
			index += J9CGM_(AQDE_HORI_FILTER_KERNEL);
			index += J9CGM_(AQDE_VERTI_FILTER_KERNEL);
			index += J9CGM_(AQBW_CONFIG);
			index += J9CGM_(AQBW_BLOCK_SIZE);
			index += J9CGM_(AQBW_TILE_SIZE);
			index += J9CGM_(AQBW_BLOCK_MASK);
			index += J9CGM_(AQDE_SRC_EX_CONFIG);
			index += J9CGM_(AQDE_SRC_EX_ADDRESS);
		}
#endif

		index += J9_ARDENNITE();

		Context->linkIndex2D = index;
		index += j9_maad(Context, index);
	}
#endif

#if J9_DEMISSNESS



	halti0 = jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_POLYGRAPHY);
	halti1 = jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_ENTONEMENT);
	halti2 = jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_ROSANILINE);
	halti3 = jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_TERNARIANT);
	halti4 = jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_ABSTINENCE);
	halti5 = jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_CORPORALCY);
	hasGS =
	    jmkHARDWARE_IsFeatureAvailable(hardware,
					   J9_HANDLE_J9MENU_PREPROMISE);
	hasTS =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9M_CONQUERING);
	genericAttrib =
	    jmkHARDWARE_IsFeatureAvailable(hardware,
					   J9_HANDLE_J9MIN_FORGATHERS);
	hasICache =
	    jmkHARDWARE_IsFeatureAvailable(hardware,
			    J9_HANDLE_ATTRIBUTE_BEHAVIOUR_REMODIFIED);
	hasTXdesc =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9MA_DULCIGENIC);
	hasSecurity =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_PREREJOICE);
	hasRobustness =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J_ECSTATICAL);
	hasICachePrefetch =
	    jmkHARDWARE_IsFeatureAvailable(hardware,
					   J9_HANDLE_J9MA_ATTRIBUTE_COMMENCING);
	multiCluster =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9MA_CORROSIVES);
	smallBatch =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_NONJURIDIC)
	    && hardware->options.smallBatch;
	multiCoreBlockSetCfg2 =
	    jmkHARDWARE_IsFeatureAvailable(hardware,
			    J9_HANDLE_ATTRIBUTE_BEHAVIOUR_OXAMETHANE);
	hasPSCSThrottle =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9MA_HISTOLOGIC);
	hasMsaaFragOperation =
	    jmkHARDWARE_IsFeatureAvailable(hardware,
					   J9_HANDLE_J9MA_ATTRIBUTE_BANDCUTTER);
	newGPipe =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE__THERMOGENY);
	computeOnly =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9M_DELIQUESCE);
#if J9_PRISM && J9_ERRONEOUSLY
	PEFenceEndianControl =
	    jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_NONMELODIC)
	    ? MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_SWAP_DDWORD :
	    MWV207REG_PE_CONFIG_EX_FENCE_ENDIAN_CONTROL_SWAP_DWORD;
#endif

	for (i = 0; i < J9_HANDLE_J9M_PIPEFISHES; i++) {
		clusterAliveMask[i] = hardware->identity.clusterAvailMask &
				      hardware->options.userClusterMasks[i];
	}


	if (Context->hardware->identity.chipModel == J9_AJOG &&
	    Context->hardware->identity.j9_exquisite == 0x5124 &&
	    Context->hardware->identity.j9_nascent == 0x103) {
		numRT = 16;
	} else if (halti2 ||
		   ((Context->hardware->identity.chipModel == J9_BOSK) &&
		    (Context->hardware->identity.j9_exquisite == 0x5250))) {
		numRT = 8;
	} else if (halti0) {
		numRT = 4;
	} else {
		numRT = 1;
	}

	if (hasGS && hasTS)
		numSamplers = 80;


	J9_HANDLE_J_DEEDHOLDER(Context->hardware->identity.chipModel,
			       Context->hardware->identity.j9_exquisite,
			       halti5,
			       smallBatch,
			       computeOnly,
			       Context->hardware->identity.numConstants,
			       unifiedUniform,
			       vertexUniforms, fragmentUniforms);

#if !J9_HANDLE_J9MENU_MUSCOLOGIC
	if (Context->hardware->identity.numConstants > 256)
		unifiedUniform = J9_CUPPY;
	else
		unifiedUniform = J9_YARELY;
#endif


	Context->entryOffset3D = (jmtUINT) index * J9_NONPROS(jmtUINT32);


	index += j9_ginglymi(Context, index, J9_SYNAPTAI);

	if (multiCluster) {
		for (i = 0; i < hardware->kernel->device->coreNum; i++) {
			index += J9_HANDLE_J9M_PRECONCEAL(
					MWV207REG_CLUSTER_CONTROL,
					i, J9_CRACKROPE(0,
						MWV207REG_CLUSTER_CONTROL,
						CLUSTER_ALIVE_ENABLE,
						clusterAliveMask[i]));
		}

		index += J9_UNCHANGINGNESS(
				MWV207REG_CLUSTER_CHECKER_BOARD,
				J9_MEGAPHONICALLY(0,
					MWV207REG_CLUSTER_CHECKER_BOARD,
					SIZE, BLOCK32X32));
	}


#if J9_NOONED && defined(mwv207regContextRegAddrs)
	index += J9CGM_(MWV207REG_CONTEXT);
#endif

	index += j9_voltize(Context, index, J9_SYNAPTAI);


	if (hasSecurity) {
		index += J9CGM_(MWV207REG_APP_CONTEXT_ID_LOW);
		index += J9_ARDENNITE();
		index += J9CGM_(MWV207REG_APP_CONTEXT_ID_HIGH);
	}

	index += J9CGM_(AQ_VERTEX_ELEMENT_CONFIG);
	index += J9_ARDENNITE();
	index += J9CGM_(MWV207REG_MULTI_SAMPLE_CONFIG);
	index += J9CGM_(MWV207REG_VARYINGS);

	if (halti5) {
		jmtUINT32 uscControl = J9_CRACKROPE(0, MWV207REG_USC_CONTROL,
					MEMORY_CONTROLLER_SELECT, 2);
		index += J9CGM_(MWV207REG_SEMANTIC_LOCATION);
		index += J9CGM_(MWV207REG_SEMANTICS);

		uscControl |= J9_CRACKROPE(0, MWV207REG_USC_CONTROL,
				CACHE_PAGES,
				hardware->options.uscL1CacheRatio);
		if (multiCluster) {
			uscControl |= J9_CRACKROPE(0, MWV207REG_USC_CONTROL,
					 ATTRIB_CACHE_PAGES,
					 hardware->options.uscAttribCacheRatio);
		}
		index += J9_UNCHANGINGNESS(MWV207REG_USC_CONTROL, uscControl);
	} else {
		index += J9CGM_(MWV207REG_VARYING_PACKING);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_LOW);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_HIGH);
		index += J9CGM_(MWV207REG_VARYING_PACKING_EX);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_EX);
		index += J9CGM_(MWV207REG_COMPONENT_TYPE_EX2);
	}

	if (hasGS)
		index += J9CGM_(MWV207REG_DEPTH_SLICE);

	index += J9CGM_(AQ_MODE);


	if (halti5) {
		index += J9CGM_(MWV207REG_FE_ATTRIBUTE);
		index += J9_ARDENNITE();
		index += J9CGM_(MWV207REG_FE_ID);
		index += J9CGM_(MWV207REG_FE_PACKING);
		index += J9CGM_(MWV207REG_FE_CONTROL);
		index += J9CGM_(MWV207REG_FE_FETCH);
		if (genericAttrib || newGPipe) {
			index += J9CGM_(MWV207REG_FE_GENERIC_X);
			index += J9CGM_(MWV207REG_FE_GENERIC_Y);
			index += J9CGM_(MWV207REG_FE_GENERIC_Z);
			index += J9CGM_(MWV207REG_FE_GENERIC_W);
		}
	} else {
		index +=
		    J9_LUMINANCE(AQ_VERTEX_ELEMENT_CTRL, (halti0 ? 16 : 12));
		index += J9_ARDENNITE();
		if (genericAttrib) {
			index += J9CGM_(MWV207REG_FE_GENERICS_X);
			index += J9CGM_(MWV207REG_FE_GENERICS_Y);
			index += J9CGM_(MWV207REG_FE_GENERICS_Z);
			index += J9CGM_(MWV207REG_FE_GENERICS_W);
		}
	}

	if (halti2 || (Context->hardware->identity.streamCount > 8)) {
		index += J9CGM_(MWV207REG_FE_STREAM_ADDRESS);
		index += J9CGM_(MWV207REG_FE_STREAM_STRIDE);
		index += J9CGM_(MWV207REG_FE_STREAM_DIVISOR);
	} else if (Context->hardware->identity.streamCount > 1) {
		index += J9_SAWBUCKS(MWV207REG_FE_VERTEX_ADDRESS);
		index += J9CGM_(MWV207REG_FE_VERTEX_STRIDE);
	} else {
		index += J9_SAWBUCKS(AQ_VERTEX_STREAM_BASE_ADDR);
		index += J9CGM_(AQ_VERTEX_STREAM_CTRL);

	}
	index += J9_SAWBUCKS(AQ_INDEX_STREAM_BASE_ADDR);
	index += J9CGM_(AQ_INDEX_STREAM_CTRL);
	index += J9CGM_(MWV207REG_FE_PRIMITIVE_RESTART);

	if (halti1) {
		index += J9CGM_(MWV207REG_FE_INDEX_MIN);
		index += J9CGM_(MWV207REG_FE_INDEX_MAX);
	}

	index += J9_ARDENNITE();

	if (hasRobustness) {
		index += J9_SAWBUCKS(MWV207REG_FE_STREAM_END_ADDRESS);
		index += J9_ARDENNITE();
		index += J9_SAWBUCKS(MWV207REG_FE_INDEX_END_ADDRESS);
		index += J9_ARDENNITE();
	}


	if (multiCluster) {

		index += J9_UNCHANGINGNESS(
				MWV207REG_WD_STATIC_CONFIG,
				J9_MEGAPHONICALLY(0,
					MWV207REG_WD_STATIC_CONFIG,
					ASSIGNMENT_MODE,
					ROUND_ROBIN));
	}

	if (halti5) {
		index += J9_UNCHANGINGNESS(MWV207REG_SHADER_STATIC,
								J9_CRACKROPE(0,
												MWV207REG_SHADER_STATIC,
												GPIPE_SMALL_BATCH,
												smallBatch ?
												MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH_ENABLE
												: MWV207REG_SHADER_STATIC_GPIPE_SMALL_BATCH_DISABLE)
									| J9_CRACKROPE(0,
												MWV207REG_SHADER_STATIC,
												PIXEL_SMALL_BATCH,
												smallBatch ?
												MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH_ENABLE
												: MWV207REG_SHADER_STATIC_PIXEL_SMALL_BATCH_DISABLE)
									| J9_MEGAPHONICALLY(0,
												MWV207REG_SHADER_STATIC,
												DUAL_ISSUE,
												ENABLE)
									| J9_MEGAPHONICALLY(0,
												MWV207REG_SHADER_STATIC,
												TWO_GROUP_FAST_REISSUE,
												ENABLE));

		index += J9CGM_(MWV207REG_SHADER_MISC_CONFIG);
	} else {
		index += J9CGM_(MWV207REG_SHADER_CONFIG);
	}

	if (hasICache) {

		index += J9CGM_(MWV207REG_SH_CACHE_CONTROL);
		index += J9CGM_(MWV207REG_VS_INSTRUCTION);
		index += J9CGM_(MWV207REG_CE_INSTRUCTION);
		index += J9CGM_(MWV207REG_PS_INSTRUCTION);
		index += J9_ARDENNITE();

		if (hasICachePrefetch) {
			if (halti5) {
				index += J9_SAWBUCKS(MWV207REG_VS_INSTRUCTION_PREFETCH_RELATIVE_END);
				index += J9_SAWBUCKS(MWV207REG_PS_INSTRUCTION_PREFETCH_RELATIVE_END);
			} else {
				index += J9_SAWBUCKS(MWV207REG_VS_INSTRUCTION_PREFETCH_END);
				index += J9_SAWBUCKS(MWV207REG_PS_INSTRUCTION_PREFETCH_END);
			}
			index += J9_ARDENNITE();
		}
	}

	if (multiCluster) {

		index += J9CGM_(MWV207REG_GPIPE_LOAD_BALANCING);
	}


	index += J9CGM_(AQ_VERTEX_SHADER_OUTPUT_CONTROL);
	index += J9_UNCHANGINGNESS(AQ_VERTEX_SHADER_INPUT_CONTROL,
				   J9_CRACKROPE(0,
						AQ_VERTEX_SHADER_INPUT_CONTROL,
						COUNT, 1));
	index += J9CGM_(AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL);
	index += J9CGM_(AQ_VERTEX_SHADER_LOAD_BALANCING);

	if (halti5) {
		index += J9CGM_(MWV207REG_VS_UNPACK);
		index += J9CGM_(MWV207REG_VS_THROTTLE);
		index += J9CGM_(MWV207REG_VS_ATTRIBUTE);
		index += J9CGM_(MWV207REG_VS_SAMPLER_BASE);
		index += J9CGM_(MWV207REG_VS_INPUT);
		index += J9CGM_(MWV207REG_VS_OUTPUT);
	} else {
		index += J9CGM_(AQ_VERTEX_SHADER_OUTPUT);
		index += J9CGM_(AQ_VERTEX_SHADER_INPUT);
	}

	if (multiCluster) {
		index += J9CGM_(MWV207REG_FA_CONTROL);
		index += J9CGM_(MWV207REG_VS_THROTTLE_EX);
	}

	index += J9_ARDENNITE();


	if (hasGS) {
		index += J9CGM_(MWV207REG_GS_CONTROL);
		index += J9CGM_(MWV207REG_GS_TYPE);
		index += J9CGM_(MWV207REG_GS_COUNTERS);
		index += J9CGM_(MWV207REG_GS_START);
		index += J9CGM_(MWV207REG_GS_RELATIVE_END);
		index += J9_SAWBUCKS(MWV207REG_GS_INSTRUCTION);
		index += J9CGM_(MWV207REG_GS_INSTRUCTION_PREFETCH_RELATIVE_END);
		index += J9CGM_(MWV207REG_GS_THROTTLE);
		index += J9CGM_(MWV207REG_GS_THROTTLE_EX);
		index += J9CGM_(MWV207REG_GS_ATTRIBUTE);
		index += J9CGM_(MWV207REG_GS_ATTRIBUTE_EX);
		index += J9CGM_(MWV207REG_GS_UNIFORM_BASE);
		index += J9CGM_(MWV207REG_GS_SAMPLER_BASE);
		index += J9CGM_(MWV207REG_GS_OUTPUT);
		index += J9_ARDENNITE();
	}


	if (hasTS) {
		index += J9CGM_(MWV207REG_FE_PATCH_CONTROL);

		index += J9CGM_(MWV207REG_TCS_CONTROL);
		index += J9CGM_(MWV207REG_TCS_THROTTLE);
		index += J9CGM_(MWV207REG_TCS_ATTRIBUTE);
		index += J9CGM_(MWV207REG_TCS_ATTRIBUTE_EX);
		index += J9CGM_(MWV207REG_TCS_START);
		index += J9CGM_(MWV207REG_TCS_RELATIVE_END);
		index += J9_SAWBUCKS(MWV207REG_TCS_INSTRUCTION);
		index +=
		    J9CGM_(MWV207REG_TCS_INSTRUCTION_PREFETCH_RELATIVE_END);
		index += J9CGM_(MWV207REG_TCS_OUTPUT);
		index += J9CGM_(MWV207REG_TCS_UNIFORM_BASE);
		index += J9CGM_(MWV207REG_TCS_SAMPLER_BASE);

		index += J9_ARDENNITE();

		index += J9CGM_(MWV207REG_TES_CONTROL);
		index += J9CGM_(MWV207REG_TES_THROTTLE);
		index += J9CGM_(MWV207REG_TES_ATTRIBUTE);
		index += J9CGM_(MWV207REG_TES_START);
		index += J9CGM_(MWV207REG_TES_RELATIVE_END);
		index += J9_SAWBUCKS(MWV207REG_TES_INSTRUCTION);
		index +=
		    J9CGM_(MWV207REG_TES_INSTRUCTION_PREFETCH_RELATIVE_END);
		index += J9CGM_(MWV207REG_TES_OUTPUT);
		index += J9CGM_(MWV207REG_TES_UNIFORM_BASE);
		index += J9CGM_(MWV207REG_TES_SAMPLER_BASE);
		index += J9CGM_(MWV207REG_TES_THROTTLE_EX);

		index += J9CGM_(MWV207REG_TPG_CONTROL);

	}

	index += J9_ARDENNITE();


	if (jmkHARDWARE_IsFeatureAvailable
	    (Context->hardware, J9MATHS_TRANSMUTES)) {
		index += J9CGM_(MWV207REG_TFB_CONTROL);
		index += J9_SAWBUCKS(MWV207REG_TFB_HEADER);
		index += J9_SEMIRETICULATE(MWV207REG_TFB_BUFFER_ADDRESS, 0, 4);
		index += J9_LUMINANCE(MWV207REG_TFB_BUFFER_SIZE, 4);
		index += J9_LUMINANCE(MWV207REG_TFB_BUFFER_STRIDE, 4);
		index += J9_LUMINANCE(MWV207REG_TFB_DESCRIPTOR_COUNT, 4);
		index += J9_LUMINANCE(MWV207REG_TFB_DESCRIPTOR, 128 * 4);

		index += J9_SAWBUCKS(MWV207REG_TFB_QUERY_HEADER);
		index += J9_ARDENNITE();

	}


	index += J9_OASAL(AQ_VIEWPORT_XSCALE);
	index += J9_OASAL(AQ_VIEWPORT_YSCALE);
	index += J9CGM_(AQ_VIEWPORT_ZSCALE);
	index += J9_OASAL(AQ_VIEWPORT_XOFFSET);
	index += J9_OASAL(AQ_VIEWPORT_YOFFSET);
	index += J9CGM_(AQ_VIEWPORT_ZOFFSET);
	index += J9CGM_(AQPA_CLIP_AA_LINE_SCALE);
	index += J9_UNCHANGINGNESS(AQPA_CLIP_POINT_SIZE_DIV_BY2, 0x3F000000);
	index += J9CGM_(AQ_SYSTEM);
	index += J9CGM_(AQPA_CLIP_WPLANE_LIMIT);
	index += J9CGM_(AQ_PACLIPVT30);
	index += J9CGM_(AQPA_MASKED);
	index += J9CGM_(MWV207REG_PA_LINE_ADJUST_SUB);
	index += J9CGM_(MWV207REG_PA_LINE_ADJUST_ADD);
	index += J9CGM_(MWV207REG_PA_CLIP_W);
	index += J9_OASAL(MWV207REG_PA_MAX_POINT_SIZE);
	index += J9CGM_(MWV207REG_PA_SMALL_W);
	index += J9CGM_(MWV207REG_PA_CLIP_CONTROL);

	if (halti5) {
		index += J9CGM_(MWV207REG_PA_CONTROL);
		index += J9CGM_(MWV207REG_PA_PACK);
	} else {
		index += J9_LUMINANCE(AQPA_CLIP_FLAT_COLOR_TEX,
				Context->hardware->identity.varyingsCount);
	}

	if (multiCluster) {

		index += J9CGM_(MWV207REG_FINAL_PA_CONTROL);
		index += J9_UNCHANGINGNESS(
				MWV207REG_MULTI_CHIP_CONTROL,
				J9_MEGAPHONICALLY(0,
					MWV207REG_MULTI_CHIP_CONTROL,
					MODE,
					INTERLEAVED) |
				J9_CRACKROPE(0,
					MWV207REG_MULTI_CHIP_CONTROL,
					ENABLE_GPU_ENABLE, 0xf));
	} else {
		index += J9CGM_(MWV207REG_MULTI_CHIP_CONTROL);
	}

	index += J9CGM_(MWV207REG_MULTI_CHIP_TOP_LEFT);
	index += J9CGM_(MWV207REG_MULTI_CHIP_BOTTOM_RIGHT);

	if (multiCoreBlockSetCfg2) {
		index += J9CGM_(MWV207REG_MULTI_CHIP_SET_MAPPING);
		index += J9CGM_(MWV207REG_MULTI_CHIP_SET_MAPPING_EX);
	}


	index += J9_OASAL(AQ_SETUP_CLIP_LEFT);
	index += J9_OASAL(AQ_SETUP_CLIP_TOP);
	index += J9_OASAL(AQ_SETUP_CLIP_RIGHT);
	index += J9_OASAL(AQ_SETUP_CLIP_BOTTOM);
	index += J9CGM_(AQ_SETUP_SLOPE_SCALED_DEPTH_BIAS);
	index += J9CGM_(AQ_SETUP_DEPTH_BIAS);
	index += J9CGM_(AQ_SETUP_CONFIG);
	index += J9CGM_(MWV207REG_SE_AREA_THRESHOLD);
	index += J9_OASAL(MWV207REG_SE_CLIP_COMPARE_RIGHT);
	index += J9_OASAL(MWV207REG_SE_CLIP_COMPARE_BOTTOM);


	index += J9CGM_(AQ_RASTER_CONTROL);
	index += J9CGM_(MWV207REG_MULTI_SAMPLE_COORDS);
	index += J9CGM_(MWV207REG_MULTI_SAMPLE_JITTER);
	index += J9CGM_(MWV207REG_CENTROIDS);
	index += J9_UNCHANGINGNESS(
			MWV207REG_RA_CONTROL,
			J9_CRACKROPE(MWV207REG_RA_CONTROL_ResetValue,
				MWV207REG_RA_CONTROL, SMALL_BATCH,
				smallBatch ?
				MWV207REG_RA_CONTROL_SMALL_BATCH_ENABLED :
				MWV207REG_RA_CONTROL_SMALL_BATCH_DISABLED));
	index += J9CGM_(MWV207REG_HZ_BASE_ADDRESS1);
	index += J9CGM_(MWV207REG_RA_CONTROL_HZ);

	if (halti2)
		index += J9CGM_(MWV207REG_RA_MEDIUMP_MASK);
	if (halti5)
		index += J9CGM_(MWV207REG_RA_CONTROL_EX);


	index += J9CGM_(AQ_PIXEL_SHADER_COLOR_OUT);
	index += J9CGM_(AQ_PIXEL_SHADER_INPUT_CONTROL);
	index += J9CGM_(AQ_PIXEL_SHADER_TEMPORARY_REGISTER_CONTROL);
	index += J9CGM_(AQ_PIXEL_SHADER_CONTROL);
	index += J9CGM_(MWV207REG_PS_OUTPUT_MODE);
	index += J9CGM_(MWV207REG_PS_OUTPUT_PRECISION);

	if (halti2)
		index += J9CGM_(MWV207REG_PS_INPUT_TYPE);

	if (numRT == 16) {
		index += J9CGM_(MWV207REG_PS_OUTPUT_CONTROL);
		index += J9CGM_(MWV207REG_PS_OUTPUT_CONTROL1);
		index += J9CGM_(MWV207REG_PS_OUTPUT_CONTROL2);
	} else if (numRT == 8) {
		index += J9CGM_(MWV207REG_PS_OUTPUT_CONTROL);
		index += J9CGM_(MWV207REG_PS_OUTPUT_PRECISION_EX);
	}

	if (hasMsaaFragOperation) {
		index += J9CGM_(MWV207REG_PS_SAMPLE_COVERAGE_CTRL);
		index += J9_LUMINANCE(MWV207REG_PS_SAMPLE_DITHER_TABLE, 8);
	}

	if (halti5) {
		index += J9CGM_(MWV207REG_PS_UNPACK);
		index += J9CGM_(MWV207REG_PS_SAMPLER_BASE);
		index += J9CGM_(MWV207REG_PS_MAX);
	}

	if (hasPSCSThrottle)
		index += J9CGM_(MWV207REG_PSCS_THROTTLE);

	index += J9_ARDENNITE();


	if (hasTXdesc) {

		index += J9CGM_(MWV207REG_TX_GLOBAL_CONFIG);

		if (smallBatch) {
			index +=
			    J9_UNCHANGINGNESS(MWV207REG_SH_ALLOC_SAMPLERS,
					      numSamplers);
			index +=
			    J9_UNCHANGINGNESS(MWV207REG_SH_ALLOC_TEXTURES,
					      numSamplers);

			index +=
			    J9_LUMINANCE(MWV207REG_TX_GPIPE_SAMPLER_CTRL0,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_GPIPE_SAMPLER_CTRL1,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL,
					 numSamplers);

			index +=
			    J9_SEMIRETICULATE(MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR, 0,
			     numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_GPIPE_TEXTURE_CTRL,
					 numSamplers);

			index += J9_ARDENNITE();
		} else {
			index +=
			    J9_LUMINANCE(MWV207REG_TX_PIXEL_SAMPLER_CTRL0,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_PIXEL_SAMPLER_CTRL1,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS,
					 numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL,
					 numSamplers);

			index +=
			    J9_SEMIRETICULATE(MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR, 0,
			     numSamplers);
			index +=
			    J9_LUMINANCE(MWV207REG_TX_PIXEL_TEXTURE_CTRL,
					 numSamplers);

			index += J9_ARDENNITE();

			J9MIRROR_QUINTUPLET(MWV207REG_TX_GPIPE_SAMPLER_CTRL0, MWV207REG_TX_PIXEL_SAMPLER_CTRL0, numSamplers);
			J9MIRROR_QUINTUPLET(MWV207REG_TX_GPIPE_SAMPLER_CTRL1, MWV207REG_TX_PIXEL_SAMPLER_CTRL1, numSamplers);
			J9MIRROR_QUINTUPLET(MWV207REG_TX_GPIPE_SAMPLER_LOD_MAX_MIN, MWV207REG_TX_PIXEL_SAMPLER_LOD_MAX_MIN, numSamplers);
			J9MIRROR_QUINTUPLET(MWV207REG_TX_GPIPE_SAMPLER_LOD_BIAS, MWV207REG_TX_PIXEL_SAMPLER_LOD_BIAS, numSamplers);
			J9MIRROR_QUINTUPLET(MWV207REG_TX_GPIPE_SAMPLER_ANISO_CTRL, MWV207REG_TX_PIXEL_SAMPLER_ANISO_CTRL, numSamplers);
			J9MIRROR_QUINTUPLET(MWV207REG_TX_GPIPE_TEXTURE_DESCRIPTOR_ADDR, MWV207REG_TX_PIXEL_TEXTURE_DESCRIPTOR_ADDR, numSamplers);
			J9MIRROR_QUINTUPLET(MWV207REG_TX_GPIPE_TEXTURE_CTRL, MWV207REG_TX_PIXEL_TEXTURE_CTRL, numSamplers);
		}
	} else {
		index += J9_LUMINANCE(AQ_TEXTURE_SAMPLE_MODE, 12);
		index += J9_LUMINANCE(AQ_TEXTURE_SAMPLE_WH, 12);
		index += J9_LUMINANCE(AQ_TEXTURE_SAMPLE_LOG_WH, 12);
		index += J9_LUMINANCE(AQ_TEXTURE_SAMPLE_LOD, 12);
		index += J9_LUMINANCE(AQ_TEXTURE_SAMPLE_BORDER_COLOR, 12);
		index += J9_LUMINANCE(MWV207REG_TX_STRIDE, 12);
		index += J9_LUMINANCE(MWV207REG_TX_VOLUME, 12);
		index += J9_LUMINANCE(MWV207REG_TX_MODE, 12);
		index += J9_LUMINANCE(MWV207REG_TX_CONTROL_YUV, 12);
		index += J9_LUMINANCE(MWV207REG_TX_STRIDE_YUV, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD00_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD01_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD02_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD03_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD04_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD05_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD06_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD07_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD08_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD09_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD10_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD11_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD12_ADDRESS, 0, 12);
		index +=
		    J9_SEMIRETICULATE(AQ_TEXTURE_SAMPLE_LOD13_ADDRESS, 0, 12);
		index += J9_ARDENNITE();

		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J9MIN_ANCHORITIC)) {
			jmtUINT count = halti1 ? 14 : 1;

			for (i = 0; i < 12; i += 1) {
				index +=
				    J9MIRROR_CONGRUENCE(MWV207REG_TX_SAMPLER_STRIDE, i * 16,
				     count);
			}
		}

		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE__ATTRIBUTE_DOWAGERISM)) {
			jmtUINT texBlockCount;
			jmtUINT mwv207regTXLogSizeResetValue;

			mwv207regTXLogSizeResetValue =
			    J9_MEGAPHONICALLY(MWV207REG_TX_LOG_SIZE_ResetValue, MWV207REG_TX_LOG_SIZE, INTEGER_FILTER_CONTROL, INTEGER);


			index += J9CGM_(MWV207REG_TX_CONFIG);
			index += J9CGM_(MWV207REG_TX_SIZE);
			index +=
			    J9_UNCHANGINGNESS(MWV207REG_TX_LOG_SIZE,
					      mwv207regTXLogSizeResetValue);
			index += J9CGM_(MWV207REG_TX_LOD);
			index += J9CGM_(MWV207REG_TX_BORDER_COLOR);
			index += J9CGM_(MWV207REG_TX_LINEAR_STRIDE);
			index += J9CGM_(MWV207REG_TX3_D);
			index += J9CGM_(MWV207REG_TX_EXT_CONFIG);
			index += J9CGM_(MWV207REG_TX_CONTROL_YUV_EX);
			index += J9CGM_(MWV207REG_TX_STRIDE_YUV_EX);

			if (jmkHARDWARE_IsFeatureAvailable
			    (hardware, J9_HANDLE__GLOSSINESS)) {
				index += J9CGM_(MWV207REG_TX_HORIZONTAL_KERNEL);
				index += J9CGM_(MWV207REG_TX_VERTICAL_KERNEL);
			}

			texBlockCount = J9_MAHARANEE(MWV207REG_TX_ADDRESS);

			for (i = 0; i < texBlockCount; i += 1) {
				index +=
				    J9_SEMIRETICULATE(MWV207REG_TX_ADDRESS, i, 14);
			}
		}

		if (jmkHARDWARE_IsFeatureAvailable
		    (Context->hardware, J9_HANDLE_J9_SKITTYBOOT)) {
			index += J9CGM_(MWV207REG_TX_BASE_LOD);
		}

		if (halti3 ||
		    jmkHARDWARE_IsFeatureAvailable(
			    hardware, J9_HANDLE_J9MIN_REDOUBTING)) {
			index += J9CGM_(MWV207REG_TX_CONFIG2);
		}

		if (halti4) {
			index += J9_LUMINANCE(MWV207REG_TX_SLICE, 32);
			index += J9_LUMINANCE(MWV207REG_TX_CONFIG3, 32);
		}

		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J9M_ATTRIBUTE_LAMENESSES)) {
			index += J9_LUMINANCE(MWV207REG_TX_SIZE_EXT, 32);
			index += J9_LUMINANCE(MWV207REG_TX_VOLUME_EXT, 32);
			index += J9_LUMINANCE(MWV207REG_TX_LOD_EXT, 32);
			index += J9_LUMINANCE(MWV207REG_TX_LOD_BIAS_EXT, 32);
			index += J9_LUMINANCE(MWV207REG_TX_ANISO_CTRL, 32);
		}


		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J9M_SORDIDNESS)) {
			index += J9CGM_(MWV207REG_TX_ASTC0_EX);
			index += J9CGM_(MWV207REG_TX_ASTC1_EX);
			index += J9CGM_(MWV207REG_TX_ASTC2_EX);
			index += J9CGM_(MWV207REG_TX_ASTC3_EX);
		}
	}

	if (halti3)
		index += J9CGM_(MWV207REG_TX_GUARDBAND);


	index += J9CGM_(MWV207REG_TW_CONFIG);
	index += J9CGM_(MWV207REG_TW_INFO_X);
	index += J9CGM_(MWV207REG_TW_INFO_Y);
	index += J9CGM_(MWV207REG_TW_INFO_Z);
	index += J9CGM_(MWV207REG_TW_WORK_GROUP_X);
	index += J9CGM_(MWV207REG_TW_WORK_GROUP_Y);
	index += J9CGM_(MWV207REG_TW_WORK_GROUP_Z);

	index += J9CGM_(MWV207REG_TW_SHADER_INFO2);
	index += J9CGM_(MWV207REG_TW_SHADER_INFO);

	if (jmkHARDWARE_IsFeatureAvailable
	    (hardware, J9_HANDLE_J_ATTRIBUTE_PANSOPHIES)) {
		index += J9CGM_(MWV207REG_TW_WORK_GROUP_COUNT_X);
		index += J9CGM_(MWV207REG_TW_WORK_GROUP_COUNT_Y);
		index += J9CGM_(MWV207REG_TW_WORK_GROUP_COUNT_Z);
		index += J9CGM_(MWV207REG_TW_WORKGROUP_SIZE_X);
		index += J9CGM_(MWV207REG_TW_WORKGROUP_SIZE_Y);
		index += J9CGM_(MWV207REG_TW_WORKGROUP_SIZE_Z);
	}

	if (halti5) {
		index += J9CGM_(MWV207REG_TW_INFO_GLOBAL_SCALE_X);
		index += J9CGM_(MWV207REG_TW_INFO_GLOBAL_SCALE_Y);
		index += J9CGM_(MWV207REG_TW_INFO_GLOBAL_SCALE_Z);
	}

	index += J9_ARDENNITE();


	if (halti5) {
		index += J9CGM_(MWV207REG_VS_START_PC);
		index += J9CGM_(MWV207REG_VS_RELATIVE_END);
		index += J9CGM_(MWV207REG_PS_START_PC);
		index += J9CGM_(MWV207REG_PS_RELATIVE_END);
		index += J9_ARDENNITE();
	} else if (hasICache) {

		index += J9CGM_(MWV207REG_VS_START_PC);
		index += J9CGM_(MWV207REG_VS_END_PC);
		index += J9CGM_(MWV207REG_PS_START_PC);
		index += J9CGM_(MWV207REG_PS_END_PC);
		index += J9_ARDENNITE();
	} else {
		if (Context->hardware->identity.instructionCount <= 256) {

			index += J9CGM_(AQ_VERTEX_SHADER_END_PC);
			index += J9CGM_(AQ_VERTEX_SHADER_START_PC);
			index += J9_ARDENNITE();

			index += J9CGM_(AQ_PIXEL_SHADER_END_PC);
			index += J9CGM_(AQ_PIXEL_SHADER_START_PC);
			index += J9_ARDENNITE();
		} else {

			index += J9CGM_(MWV207REG_VS_PROGRAM);
			index += J9CGM_(MWV207REG_PS_PROGRAM);
			index += J9_ARDENNITE();
		}
	}

	if (!hasICachePrefetch) {

		if (Context->hardware->identity.instructionCount > 1024) {
			for (i = 0; i < Context->hardware->identity.instructionCount << 2; i += 256 << 2) {
				index += J9MIRROR_CONGRUENCE(MWV207REG_SH_INSTRUCTIONS, i, 256 << 2);
				index += J9_ARDENNITE();
			}
		}

		else if (Context->hardware->identity.instructionCount > 256) {

			for (i = 0; i < Context->hardware->identity.instructionCount << 2; i += 256 << 2) {
				index += J9MIRROR_CONGRUENCE(MWV207REG_VS_SHADER_CODE, i, 256 << 2);
				index += J9_ARDENNITE();
			}

			J9MIRROR_QUINTUPLET(MWV207REG_PS_SHADER_CODE,
								MWV207REG_VS_SHADER_CODE,
								Context->hardware->identity.instructionCount << 2);
		}

		else {
			if (Context->hardware->identity.PSInstructionCount > Context->hardware->identity.instructionCount) {
				JMM_kASSERT(Context->hardware->identity.PSInstructionCount % 256 == 0);


				for (i = 0; i < Context->hardware->identity.PSInstructionCount << 2; i += 256 << 2) {
					index += J9MIRROR_CONGRUENCE(MWV207REG_PS_SHADER_CODE, i, 256 << 2);
					index += J9_ARDENNITE();
				}
			} else {
				index += J9CGM_(AQ_PIXEL_SHADER_INST);
				index += J9_ARDENNITE();
			}

			index += J9CGM_(AQ_VERTEX_SHADER_INST);
			index += J9_ARDENNITE();
		}
	}

	if (unifiedUniform) {
		jmtINT numConstants = Context->hardware->identity.numConstants;


		index += J9CGM_(MWV207REG_PIXEL_SHADER_CONST);
		index += J9CGM_(MWV207REG_VERTEX_SHADER_CONST);
		index += J9_ARDENNITE();

		if (smallBatch) {
			index +=
			    J9_UNCHANGINGNESS(MWV207REG_SH_ALLOC_UNIFORMS,
					      numConstants);
		}

		for (i = 0;
		     numConstants > 0; i += 256 << 2, numConstants -= 256) {
			if (halti5) {
				if (numConstants >= 256) {
					if (smallBatch) {
						index +=
						    J9MIRROR_CONGRUENCE(MWV207REG_GPIPE_UNIFORMS, i, 256 << 2);
					} else {
						index +=
						    J9MIRROR_CONGRUENCE(MWV207REG_PIXEL_UNIFORMS, i, 256 << 2);
					}
				} else {
					if (smallBatch) {
						index +=
						    J9MIRROR_CONGRUENCE(MWV207REG_GPIPE_UNIFORMS, i, numConstants << 2);
					} else {
						index +=
						    J9MIRROR_CONGRUENCE (MWV207REG_PIXEL_UNIFORMS, i, numConstants << 2);
					}
				}
				index += J9_ARDENNITE();
			} else {
				if (numConstants >= 256) {
					index +=
					    J9MIRROR_CONGRUENCE(MWV207REG_SH_UNIFORMS, i, 256 << 2);
				} else {
					index +=
					    J9MIRROR_CONGRUENCE(MWV207REG_SH_UNIFORMS, i, numConstants << 2);
				}

				index += J9_ARDENNITE();
			}
		}

		if (halti5 && !smallBatch) {
			J9MIRROR_QUINTUPLET(MWV207REG_GPIPE_UNIFORMS,
					MWV207REG_PIXEL_UNIFORMS,
					Context->hardware->identity.numConstants
					<< 2);
		}
	}
#if J9_HANDLE_J9MENU_MUSCOLOGIC
	else
#endif
	{
		index +=
		    J9_LUMINANCE(AQ_VERTEX_SHADER_CONST, vertexUniforms * 4);
		index +=
		    J9_LUMINANCE(AQ_PIXEL_SHADER_CONST, fragmentUniforms * 4);
	}

	if (halti1)
		index += J9CGM_(MWV207REG_SH_SAMPLER_ARBITRATION);

	if (halti5) {

		index += J9CGM_(MWV207REG_SH_ICACHE_INVALIDATE);
	}


	Context->entryOffsetXDFrom3D = (jmtUINT) index * J9_NONPROS(jmtUINT32);


	index += J9CGM_(AQ_DEPTH_CONFIG);
	index += J9CGM_(AQ_DEPTH_NEAR);
	index += J9CGM_(AQ_DEPTH_FAR);
	index += J9CGM_(AQ_DEPTH_NORMALIZE);
	index += J9CGM_(AQ_DEPTH_STRIDE);
	index += J9CGM_(AQ_STENCIL_OPERATION);
	index += J9CGM_(AQ_STENCIL_CONFIG);
	index += J9CGM_(AQ_ALPHA_TEST);
	index += J9CGM_(AQ_ALPHA_BLEND_FACTOR);
	index += J9CGM_(AQ_ALPHA_BLEND);
	index += J9CGM_(AQ_PIXEL_CONFIG);
	index += J9CGM_(AQ_PIXEL_STRIDE);
	index += J9CGM_(MWV207REG_PE_HIERARCHICAL_CONTROL);
	index += J9_SAWBUCKS(MWV207REG_PE_HIERARCHICAL_ADDRESS);
	index += J9CGM_(MWV207REG_PE_EXTRA_REFERENCE);
	index += J9CGM_(MWV207REG_PE_DITHER_LOW);
	index += J9CGM_(MWV207REG_PE_DITHER_HIGH);

	if (jmkHARDWARE_IsFeatureAvailable
	    (hardware, J9_HANDLE_J9MENU_EVENTUATED)) {
		index += J9CGM_(MWV207REG_PE_BLEND_FACTOR_LOW);
		index += J9CGM_(MWV207REG_PE_BLEND_FACTOR_HIGH);
	}
	index += J9CGM_(MWV207REG_PE_CONFIG);
	index += J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_CONFIG, 3);
	index += J9CGM_(MWV207REG_PE_BACKFACE_STENCIL);

	if (halti3)
		index += J9CGM_(MWV207REG_PS_OUTPUT_MAP);

	index += J9_SEMIRETICULATE(MWV207REG_PE_COLOR_BASE_ADDRESS, 0,
				   Context->hardware->identity.pixelPipes);

	if (Context->hardware->identity.pixelPipes == 1) {
		index += J9_SAWBUCKS(AQ_PIXEL_ADDRESS);
		index += J9_SAWBUCKS(AQ_DEPTH_ADDRESS);
	}

	if (Context->hardware->identity.pixelPipes > 1 || halti0) {
		index += J9_SEMIRETICULATE(MWV207REG_PE_DEPTH_BASE_ADDRESS, 0,
				Context->hardware->identity.pixelPipes);
	}

	for (i = 0; i < 3; i++) {
		index += J9_SEMIRETICULATE(MWV207REG_PE_RENDER_TARGET_ADDRESS, i,
				Context->hardware->identity.pixelPipes);
	}

	if (numRT == 16) {
		for (i = 0; i < 15; i++) {
			index += J9_SEMIRETICULATE(MWV207REG_PE_RENDER_TARGET_ADDRESS_EX2, i,
					Context->hardware->identity.pixelPipes);
		}
		index += J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_CONFIG_EX2, 15);
		index += J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX2, 15);
	} else if (numRT == 8) {
		for (i = 0; i < 7; i++) {
			index += J9_SEMIRETICULATE(MWV207REG_PE_RENDER_TARGET_ADDRESS_EX, i,
					Context->hardware->identity.pixelPipes);
		}
		index += J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_CONFIG_EX, 7);
	}

	if (halti3) {
#if J9_PRISM && J9_ERRONEOUSLY
		index += J9_UNCHANGINGNESS(MWV207REG_PE_CONFIG_EX,
					   J9_CRACKROPE(0,
							MWV207REG_PE_CONFIG_EX,
							FENCE_ENDIAN_CONTROL,
							PEFenceEndianControl));
#else
		index += J9CGM_(MWV207REG_PE_CONFIG_EX);
#endif
	}

	if (halti4)
		index += J9CGM_(MWV207REG_PE_ALPHA_CONFIG);
	if (hasGS)
		index += J9CGM_(MWV207REG_COLOR_SLICE);

	if (halti5) {
		index +=
		    J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_EXTRA_CONFIG_EX, 7);
		index += J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_ALPHA_TEST, 7);
		index +=
		    J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_ALPHA_CONTROL, 7);
		index +=
		    J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_LOW, 7);
		index +=
		    J9_LUMINANCE(MWV207REG_PE_RENDER_TARGET_BLEND_COLOR_HIGH,
				 7);
	}

	if (hasRobustness) {
		index += J9_SAWBUCKS(MWV207REG_PE_RENDER_TARGET_END_ADDRES_EX);
		index += J9_SAWBUCKS(MWV207REG_DEPTH_BUFFER_END_ADDRESS);
	}


	index += J9CGM_(JM_MEMORY_CONFIG);

	index += J9_ARDENNITE();
	index += J9_SAWBUCKS(JM_COLOR_CACHE);
	index += J9_SAWBUCKS(JM_COLOR_BASE);
	index += J9CGM_(JM_COLOR_CLEAR_VALUE);
	index += J9_SAWBUCKS(JM_DEPTH_CACHE);
	index += J9_SAWBUCKS(JM_DEPTH_BASE);
	index += J9CGM_(JM_DEPTH_CLEAR_VALUE);
	index += J9CGM_(JM_TILE_STATUS_COUNTER_Z);
	index += J9CGM_(JM_TILE_STATUS_COUNTER_C);
	index += J9_SAWBUCKS(MWV207REG_MC_CACHE_HZ);
	index += J9CGM_(MWV207REG_MC_COUNTER_HZ);
	index += J9CGM_(MWV207REG_MC_CLEAR_VALUE_HZ);
	index += J9CGM_(MWV207REG_MC_TEXTURE_CONFIG);
	index += J9_SAWBUCKS(MWV207REG_MC_TEXTURE_BUFFER);
	index += J9CGM_(MWV207REG_MC_TEXTURE_CLEAR);

	if (halti2) {
		index += J9CGM_(MWV207REG_MC_TEXTURE_CLEAR64);
		index += J9CGM_(MWV207REG_MC_COLOR_CLEAR64);

		if (jmkHARDWARE_IsFeatureAvailable
		    (hardware, J9_HANDLE_J_ATTRIBUTE_OUTPURSUED)) {
			index += J9CGM_(MWV207REG_MRT_MEMORY_CONFIG);
		} else {
			index +=
			    J9MIRROR_CONGRUENCE(MWV207REG_MRT_MEMORY_CONFIG, 1,
						7);
		}

		index +=
		    J9_HANDLE_J9M_CELIOSCOPY(MWV207REG_MRT_COLOR_CACHE, 1, 7);
		index +=
		    J9_HANDLE_J9M_CELIOSCOPY(MWV207REG_MRT_COLOR_BASE, 1, 7);
		index +=
		    J9MIRROR_CONGRUENCE(MWV207REG_MRT_COLOR_CLEAR_VALUE, 1, 7);
		index +=
		    J9MIRROR_CONGRUENCE(MWV207REG_MRTMC_COLOR_CLEAR64, 1, 7);
		index +=
		    J9MIRROR_CONGRUENCE(MWV207REG_MRT_TILE_STATUS_COUNTER_C, 1,
					7);
	}

	index += J9_ARDENNITE();

	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_INTRATOMIC)) {
		index += J9_UNCHANGINGNESS(MWV207REG_OCCLUSION_CONTROL, MWV207REG_OCCLUSION_CONTROL_MODE_RENDER);
		index += J9_ARDENNITE();
	}

	if (halti3) {
		index += J9_SAWBUCKS(MWV207REG_MC_TEXTURE_BASE_BUFFER);
		index += J9_ARDENNITE();
	}

	if (hasSecurity || hasRobustness) {
		index += J9_UNCHANGINGNESS(MWV207REG_MMU_CONFIG,
			    J9_MEGAPHONICALLY(0, MWV207REG_MMU_CONFIG, MASK_PAGE_TABLE_ID, MASKED));
	}


	index += j9_ungroundable(Context, index);
#endif


	Context->linkIndex3D = (jmtUINT) index;

	if (buffer != J9_CHYAK) {
		buffer[index + 0] = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LINK_COMMAND,
					OPCODE,	LINK) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LINK_COMMAND,
					PREFETCH, 0);

		buffer[index + 1] = 0;
	}

	index += 2;


	Context->bufferSize = index * J9_NONPROS(jmtUINT32);




	Context->entryOffsetXDFrom2D = (jmtUINT) index * J9_NONPROS(jmtUINT32);


	index += j9_ginglymi(Context, index, J9_SYNAPTAI);


	Context->linkIndexXD = (jmtUINT) index;

	if (buffer != J9_CHYAK) {
		buffer[index + 0]
		    = J9_MEGAPHONICALLY(0, AQ_COMMAND_LINK_COMMAND, OPCODE,
					LINK)
		    | J9_CRACKROPE(0, AQ_COMMAND_LINK_COMMAND, PREFETCH, 0);

		buffer[index + 1]
		    = 0;
	}

	index += 2;



	Context->totalSize = index * J9_NONPROS(jmtUINT32);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}
#endif

static j9_duopoly j9_regressively(IN jmk_CONTEXT Context)
{
	j9_duopoly status = J9_FLUTTERING;

	if (Context != J9_CHYAK) {
		jmsCONTEXT_PTR bufferHead;

#if J9_HANDLE_J9M_ASSIGNABLY
		jmsSTATE_DELTA_PTR delta, next;


		for (Context->delta = Context->deltaHead;
		     Context->delta != J9_CHYAK;) {
			delta = Context->delta;


			next = J9_PROVINCIALISMS(delta->next);


			if (next == Context->deltaHead)
				next = J9_CHYAK;

			j9_subcordate(Context, delta);


			Context->delta = next;
		}

		j9_palladinize(jmkCONTEXT_DestroyPrevDelta(Context));
#endif


		for (bufferHead = Context->buffer;
		     Context->buffer != J9_CHYAK;) {

			jmsCONTEXT_PTR buffer = Context->buffer;


			jmsCONTEXT_PTR next = buffer->next;


			if (next == bufferHead)
				next = J9_CHYAK;


			if (buffer->signal != J9_CHYAK) {
				j9_recaution(jmkOS_DestroySignal
					     (Context->os, buffer->signal));

				buffer->signal = J9_CHYAK;
			}


			if (buffer->logical != J9_CHYAK) {
				jmk_KERNEL kernel = Context->hardware->kernel;
				jmtBOOL asynchronous = J9_YARELY;
				jmk_MMU mmu = J9_CHYAK;

#if J9_HANDLE__PREOBSERVE
				j9_choreographies dbType;
				jmtUINT32 processID;
#endif


				j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(
						kernel, buffer->videoMem,
						0, J9_YARELY, J9_YARELY));

				j9_recaution(jmkKERNEL_GetCurrentMMU(kernel, J9_CUPPY, 0, &mmu));


				j9_palladinize(jmkVIDMEM_NODE_Unlock(
						kernel, buffer->videoMem,
						mmu,
						kernel->eventObj ?
						&asynchronous : J9_CHYAK));

#if J9_HANDLE__PREOBSERVE
				dbType = J9MIRROR_HADEPHOBIA |
					(J9_HANDLE_J9_SEVILLANAS <<
					 J9_HANDLE_ATTRIBUTE_SMIFLIGATE) |
					(buffer->videoMem->pool <<
					 J9_HANDLE_ATTRIBUTE_ACETYLIZER);

				j9_recaution(jmkOS_GetProcessID(&processID));

				j9_recaution(jmkKERNEL_RemoveProcessDB(
							kernel, processID,
							dbType,
							buffer->videoMem));
#endif

				if (kernel->eventObj && asynchronous) {
					j9_palladinize(jmkEVENT_Unlock(kernel->eventObj,
							J9_UNPANTHEISTIC, mmu,
							buffer->videoMem));
				} else
					j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel,
								buffer->videoMem));
				buffer->logical = J9_CHYAK;
			}


			j9_recaution(j9_overorganizing(Context->os, buffer));


			Context->buffer = next;
		}


		Context->object.type = J9_NEURASTHENIA;


		j9_recaution(j9_overorganizing(Context->os, Context));
	}

OnError:
	return status;
}

#if (J9_DEMISSNESS || J9_MONGRELISE)
static j9_duopoly
j9_handle_j_predecreed(IN jmk_CONTEXT Context, IN jmsCONTEXT_PTR Buffer)
{
	j9_duopoly status;
	jmk_KERNEL kernel = Context->hardware->kernel;
	j9_phpht pool = J9_BELIEVABILITY;
	jmtSIZE_T totalSize = Context->totalSize;
	jmtUINT32 allocFlag = JMV_ALLOC_FLAG_FROM_USER;

#if J9_HANDLE__PREOBSERVE
	j9_choreographies dbType;
	jmtUINT32 processID;
#endif

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
	allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

#if !J9_HANDLE__PREOBSERVE
	allocFlag |= J9_HANDLE_J9_PREADAPTED;
#endif


	j9_recaution(jmkKERNEL_AllocateVideoMemory(kernel,
						   64,
						   J9_HANDLE_J9_GUNPOWDERY,
						   allocFlag,
						   &totalSize,
						   &pool, &Buffer->videoMem));

#if J9_HANDLE__PREOBSERVE
	j9_recaution(jmkOS_GetProcessID(&processID));


	j9_recaution(jmkVIDMEM_HANDLE_Allocate(kernel, Buffer->videoMem,
					       processID,
					       &Context->buffer->handle));


	dbType = J9MIRROR_HADEPHOBIA
	    | (J9_HANDLE_J9_SEVILLANAS << J9_HANDLE_ATTRIBUTE_SMIFLIGATE)
	    | (pool << J9_HANDLE_ATTRIBUTE_ACETYLIZER);


	j9_recaution(jmkKERNEL_AddProcessDB(kernel,
					    processID,
					    dbType,
					    Buffer->videoMem,
					    J9_CHYAK, totalSize));
#endif


	j9_recaution(jmkVIDMEM_NODE_Lock(kernel,
					 Buffer->videoMem, &Buffer->address));


	j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel,
					    Buffer->videoMem,
					    J9_YARELY,
					    J9_YARELY,
					    (jmtPOINTER *)&Buffer->logical));

	return J9_FLUTTERING;

OnError:
	return status;
}
#endif


#if (J9_DEMISSNESS || J9_MONGRELISE)
j9_duopoly
jmkCONTEXT_Construct(IN jmk_OS Os,
		     IN jmk_HARDWARE Hardware,
		     IN jmtUINT32 ProcessID, OUT jmk_CONTEXT *Context)
{
	j9_duopoly status;
	jmk_CONTEXT context = J9_CHYAK;
	jmtUINT32 allocationSize;
	jmtUINT i;
	jmtPOINTER pointer = J9_CHYAK;

	j9_tympanichord("Os=%p Hardware=%p", Os, Hardware);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Context != J9_CHYAK);





	allocationSize = J9_NONPROS(struct tag_jmk_CONTEXT);


	j9_recaution(jmkOS_Allocate(Os, allocationSize, &pointer));

	context = pointer;


	j9_recaution(jmkOS_ZeroMemory(context, allocationSize));


	context->object.type = J9_UNSUPPLENESS;
	context->os = Os;
	context->hardware = Hardware;

#if !J9_DEMISSNESS
	context->entryPipe = J9_GUNSMITH;
	context->exitPipe = J9_GUNSMITH;
#elif J9_HANDLE__UNFEMINISE
	context->entryPipe = J9_SYNAPTAI;
	context->exitPipe = J9_SYNAPTAI;
#else
	context->entryPipe
	    =
	    J9_GLUTINANT(context->hardware->identity.chipFeatures, JM_FEATURES,
			 PIPE_2D)
	    ? J9_GUNSMITH : J9_SYNAPTAI;
	context->exitPipe = J9_SYNAPTAI;
#endif


	j9_recaution(jmkHARDWARE_QueryCommandBuffer(Hardware,
						    J9_SULPHOCHLORIDE,
						    &context->alignment,
						    &context->reservedHead,
						    J9_CHYAK));




	j9_recaution(j9_handle_j9m_centermost(context));

	if (context->maxState > 0) {


		if (context->hardware->kernel->command->stateMap == J9_CHYAK) {

			j9_recaution(jmkOS_Allocate(Os,
						    J9_NONPROS(j9_synclastic) *
						    context->maxState,
						    &pointer));

			context->map = pointer;


			j9_recaution(jmkOS_ZeroMemory
				     (context->map,
				      J9_NONPROS(j9_synclastic) *
				      context->maxState));

			context->hardware->kernel->command->stateMap = pointer;
		} else {
			context->map =
			    context->hardware->kernel->command->stateMap;
		}
	}




	for (i = 0; i < J9_HANDLE_J9M_AMIDSTREAM; i += 1) {

		jmsCONTEXT_PTR buffer;


		j9_recaution(jmkOS_Allocate(Os,
					    J9_NONPROS(j9_reembark), &pointer));

		buffer = pointer;


		j9_palladinize(jmkOS_ZeroMemory(buffer, J9_NONPROS(j9_reembark)
			       ));


		if (context->buffer == J9_CHYAK) {
			buffer->next = buffer;
			context->buffer = buffer;
		} else {
			buffer->next = context->buffer->next;
			context->buffer->next = buffer;
		}


#if J9_MISDATING(J9_SYLLABICITY)
		buffer->num = i;
#endif


		j9_recaution(jmkOS_CreateSignal
			     (Os, J9_YARELY, &buffer->signal));


		j9_recaution(jmkOS_Signal(Os, buffer->signal, J9_CUPPY));


		j9_recaution(j9_handle_j_predecreed(context, buffer));


		buffer->eventObj = Hardware->kernel->eventObj;


		if (context->linkIndex2D != 0)
			buffer->link2D = &buffer->logical[context->linkIndex2D];

		if (context->linkIndex3D != 0)
			buffer->link3D = &buffer->logical[context->linkIndex3D];

		if (context->linkIndexXD != 0) {
			jmtPOINTER xdLink;
			jmtUINT32 xdEntryAddress;
			jmtUINT32 xdEntrySize;
			jmtUINT32 linkBytes;


			xdLink = &buffer->logical[context->linkIndexXD];

			xdEntryAddress
			    = buffer->address + context->entryOffsetXDFrom3D;

			xdEntrySize
			    = context->bufferSize
			    - context->entryOffsetXDFrom3D;


			j9_recaution(jmkWLFE_Link
				     (Hardware, J9_CHYAK, 0, 0, &linkBytes,
				      J9_CHYAK, J9_CHYAK));


			j9_recaution(jmkWLFE_Link(Hardware,
						  xdLink,
						  xdEntryAddress,
						  xdEntrySize,
						  &linkBytes,
						  J9_CHYAK, J9_CHYAK));
		}
	}





	j9_recaution(j9_handle_j9m_centermost(context));

#if J9_HANDLE_J9M_ASSIGNABLY
	if (context->maxState > 0 && context->numStates > 0) {
		for (i = 0; i < J9_HANDLE_J9M_AMIDSTREAM + 1; i += 1) {

			jmsSTATE_DELTA_PTR delta = J9_CHYAK;
			jmsSTATE_DELTA_PTR prev;


			j9_phoniatrics(context, &delta);


			if (context->delta == J9_CHYAK) {
				delta->prev = J9_SUBAUDIBLENESS(delta);
				delta->next = J9_SUBAUDIBLENESS(delta);
				context->deltaHead = context->delta = delta;
			} else {
				delta->next = J9_SUBAUDIBLENESS(context->delta);
				delta->prev = context->delta->prev;

				prev = J9_PROVINCIALISMS(context->delta->prev);
				prev->next = J9_SUBAUDIBLENESS(delta);
				context->delta->prev = J9_SUBAUDIBLENESS(delta);
			}
		}
	}

	if (jmkHARDWARE_IsFeatureAvailable
	    (context->hardware, J9MATHS_CORPORALCY)
	    &&
	    !(jmkHARDWARE_IsFeatureAvailable
	      (context->hardware, J9_HANDLE_J9_NONJURIDIC)
	      && context->hardware->options.smallBatch)) {
		mirroredStatesCount = ARRAY_SIZE(mirroredStates);
	}

	context->prevRecordArray = J9_CHYAK;
	context->prevMapEntryID = J9_CHYAK;
	context->prevMapEntryIndex = J9_CHYAK;
	context->prevDeltaPtr = J9_CHYAK;
#endif


	{
		jmsCONTEXT_PTR currContext, tempContext;


		currContext = context->buffer;


		tempContext = currContext->next;


		while (tempContext != currContext) {
			if (tempContext == J9_CHYAK)
				j9_recaution(J9_HANDLE_TONSILITIS);


			jmkOS_MemCopy(tempContext->logical,
				      currContext->logical,
				      context->totalSize);


			tempContext = tempContext->next;
		}
	}


	*Context = context;


	JMM_kFOOTER_ARG("*Context=0x%08X", *Context);
	return J9_FLUTTERING;

OnError:

	j9_palladinize(j9_regressively(context));


	JMM_kFOOTER();
	return status;
}
#endif

j9_duopoly jmkCONTEXT_Destroy(IN jmk_CONTEXT Context)
{
	j9_duopoly status;

	j9_tympanichord("Context=%p", Context);


	j9maths_activation(Context, J9_UNSUPPLENESS);


	status = j9_regressively(Context);


	JMM_kFOOTER_NO();
	return status;
}

j9_duopoly
jmkCONTEXT_Update(IN jmk_CONTEXT Context,
		  IN jmtUINT32 ProcessID, IN jmsSTATE_DELTA_PTR StateDelta)
{
#if J9_DEMISSNESS
	j9_duopoly status = J9_FLUTTERING;
	j9_revalidating _stateDelta;
	jmk_KERNEL kernel;
	jmsCONTEXT_PTR buffer;
	jmsSTATE_MAP_PTR map;
	jmtBOOL needCopy = J9_YARELY;
	jmsSTATE_DELTA_PTR nDelta;
	jmsSTATE_DELTA_PTR uDelta = J9_CHYAK;
	jmsSTATE_DELTA_PTR kDelta = J9_CHYAK;
	jmsSTATE_DELTA_RECORD_PTR record;
	jmsSTATE_DELTA_RECORD_PTR recordArray = J9_CHYAK;
	jmtUINT elementCount;
	jmtUINT address;
	jmtUINT32 mask;
	jmtUINT32 data;
	jmtUINT index;
	jmtUINT i, j;
	jmtUINT32 dirtyRecordArraySize = 0;

	j9_tympanichord("Context=%p ProcessID=%d StateDelta=%p",
			Context, ProcessID, StateDelta);


	j9maths_activation(Context, J9_UNSUPPLENESS);


	kernel = Context->hardware->kernel;


	j9_recaution(jmkOS_QueryNeedCopy(Context->os, ProcessID, &needCopy));


	buffer = Context->buffer;

	j9_recaution(jmkOS_WaitSignal(Context->os, buffer->signal, J9_YARELY, J9_ACROMANIA));

#if J9_MISDATING(J9_SYLLABICITY) && defined(mwv207regContextRegAddrs) && J9_DEMISSNESS

	buffer->logical[Context->map[mwv207regContextRegAddrs].index] = (jmtUINT32) J9_VIRILITIES(Context);
#endif


	if (buffer->deltaCount != 0) {

		map = Context->map;


		uDelta = buffer->delta;


		elementCount = 0;


		for (i = 0; i < buffer->deltaCount; i += 1) {

			j9_recaution(
				jmkKERNEL_OpenUserData(
					kernel, needCopy,
					&_stateDelta,
					uDelta,
					J9_NONPROS(j9_revalidating),
					(jmtPOINTER *)&kDelta));

			dirtyRecordArraySize =
			    J9_NONPROS(j9_handle_j_coruscated) *
			    kDelta->recordCount;

			if (dirtyRecordArraySize) {

				j9_recaution(
					jmkOS_MapUserPointer(
						kernel->os,
						J9_PROVINCIALISMS
						(kDelta->recordArray),
						dirtyRecordArraySize,
						(jmtPOINTER *)&recordArray));

				if (recordArray == J9_CHYAK) {
					j9_recaution
					    (J9_HANDLE_J9MENU_HOMOGONIES);
				}


				for (j = 0; j < kDelta->recordCount; j += 1) {
					if (j >= Context->numStates)
						break;


					record = &recordArray[j];


					j9_recaution(jmkOS_ReadMappedPointer
						     (kernel->os,
						      &record->address,
						      &address));

					if (address >= Context->maxState) {
						JMM_kTRACE(J9_IRASCIBILITY,
							   "%s(%d): State 0x%04X (0x%04X) is not mapped.\n",
							   __func__,
							   __LINE__, address,
							   address << 2);

						continue;
					}


					index = map[address].index;


					if (index == 0) {
#if !defined(JMD_REMOVE_FROM_FINAL_RELEASE)

						for (;;) {
							jmmkPRINT
							    ("[jmgpu]: %s(%d): State 0x%04X (0x%04X) is not mapped.\n",
							     __func__,
							     __LINE__, address,
							     address << 2);

							jmkOS_Delay(Context->os,
								    10 * 1000);
						}
#else
						continue;
#endif
					}


					j9_recaution(jmkOS_ReadMappedPointer
						     (kernel->os, &record->mask,
						      &mask));


					j9_recaution(jmkOS_ReadMappedPointer
						     (kernel->os, &record->data,
						      &data));

					if ((mask == 0) || (mask == ~0U)) {

						if (address == jmMemoryConfigRegAddrs) {
							data = J9_MEGAPHONICALLY(data, JM_MEMORY_CONFIG, AUTO_DISABLE_C, DISABLE);
							data = J9_MEGAPHONICALLY(data, JM_MEMORY_CONFIG, AUTO_DISABLE_Z, DISABLE);
							data = J9_MEGAPHONICALLY(data, JM_MEMORY_CONFIG, AUTO_DISABLE_HZ_FAST_CLEAR, DISABLE);
						}


						buffer->logical[index] = data;
					} else {
						buffer->logical[index] = (~mask & buffer->logical[index]) | (mask & data);
					}
				}
			}


			if (kDelta->elementCount != 0)
				elementCount = kDelta->elementCount;


			kDelta->refCount -= 1;

			JMM_kASSERT(kDelta->refCount >= 0);


			nDelta = J9_PROVINCIALISMS(kDelta->next);

			if (dirtyRecordArraySize) {

				j9_recaution(
					jmkOS_UnmapUserPointer(
						kernel->os,
						J9_PROVINCIALISMS(
							kDelta->recordArray),
						dirtyRecordArraySize,
						recordArray));

				recordArray = J9_CHYAK;
			}


			j9_recaution(jmkKERNEL_CloseUserData(kernel, needCopy,
							     J9_CUPPY,
							     uDelta,
							     J9_NONPROS
							     (j9_revalidating),
							     (jmtPOINTER *) &
							     kDelta));


			uDelta = nDelta;
		}

		if (elementCount != 0) {
			jmtUINT base;
			jmtUINT nopCount;
			jmtUINT32_PTR nop;
			jmtUINT fe2vsCount;
			jmtUINT attribCount = elementCount - 1;
			jmtUINT32 feAttributeStatgeAddr =
			    AQVertexElementCtrlRegAddrs;
			if (jmkHARDWARE_IsFeatureAvailable
			    (Context->hardware, J9MATHS_CORPORALCY)) {
				fe2vsCount = 32;
				base = map[mwv207regFEAttributeRegAddrs].index;
				feAttributeStatgeAddr =
				    mwv207regFEAttributeRegAddrs;
			} else if (jmkHARDWARE_IsFeatureAvailable(
					Context->hardware,
					J9MATHS_POLYGRAPHY)) {
				fe2vsCount = 16;
				base = map[AQVertexElementCtrlRegAddrs].index;
			} else {
				fe2vsCount = 12;
				base = map[AQVertexElementCtrlRegAddrs].index;
			}


			if (attribCount == 0) {
				JMM_kASSERT(jmkHARDWARE_IsFeatureAvailable
					    (Context->hardware,
					     J9_HANDLE__ATTRIBUTE_GYNIATRICS));

				buffer->logical[base - 1] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, NORMAL) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						feAttributeStatgeAddr);


				buffer->logical[base + 1] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, NORMAL) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regFEResetAttributesRegAddrs);
				buffer->logical[base + 2] = 0x1;
				attribCount = 3;
			} else {
				buffer->logical[base - 1] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, NORMAL) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, attribCount) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						feAttributeStatgeAddr);
			}


			nopCount = (fe2vsCount / 2) - (attribCount / 2);

			nop = &buffer->logical[base + (attribCount | 1)];


			for (i = 0; i < nopCount; i += 1) {
				if (nop >= buffer->logical + Context->totalSize)
					break;

				*nop =
				    J9_MEGAPHONICALLY(0, AQ_COMMAND_NOP_COMMAND,
						      OPCODE, NOP);


				nop += 2;
			}
		}

		if (jmkHARDWARE_IsFeatureAvailable
		    (Context->hardware, J9_HANDLE_J9_NONJURIDIC)
		    && Context->hardware->options.smallBatch) {
			jmtUINT numConstant =
			    (jmtUINT) Context->hardware->identity.numConstants;
			jmtUINT32 constCount = 0;


			index = map[mwv207regSHAllocUniformsRegAddrs].index;
			data = buffer->logical[index];
			constCount =
			    J9_GLUTINANT(data, MWV207REG_SH_ALLOC_UNIFORMS,
					 SIZE);

			j9_lonesomenesses(Context,
					  mwv207regGpipeUniformsRegAddrs,
					  numConstant << 2, constCount << 2);
		}

		if (jmkHARDWARE_IsFeatureAvailable
		    (Context->hardware, J9_HANDLE_J9_NONJURIDIC)
		    && Context->hardware->options.smallBatch) {
			jmtUINT numSamplers = 80;
			jmtUINT32 samplerCount = 0;


			index = map[mwv207regSHAllocSamplersRegAddrs].index;
			data = buffer->logical[index];
			samplerCount =
			    J9_GLUTINANT(data, MWV207REG_SH_ALLOC_SAMPLERS,
					 SIZE);

			j9_lonesomenesses(Context,
					  mwv207regTXGpipeSamplerCtrl0RegAddrs,
					  numSamplers, samplerCount);
			j9_lonesomenesses(Context,
					  mwv207regTXGpipeSamplerCtrl1RegAddrs,
					  numSamplers, samplerCount);
			j9_lonesomenesses(
				Context,
				mwv207regTXGpipeSamplerLodMaxMinRegAddrs,
				numSamplers, samplerCount);
			j9_lonesomenesses(
				Context,
				mwv207regTXGpipeSamplerLodBiasRegAddrs,
				numSamplers, samplerCount);
			j9_lonesomenesses(
				Context,
				mwv207regTXGpipeSamplerAnisoCtrlRegAddrs,
				numSamplers, samplerCount);
			j9_lonesomenesses(
				Context,
				mwv207regTXGpipeTextureDescriptorAddrRegAddrs,
				numSamplers, samplerCount);
			j9_lonesomenesses(Context,
					  mwv207regTXGpipeTextureCtrlRegAddrs,
					  numSamplers, samplerCount);
		}

		buffer->deltaCount = 0;
		buffer->delta = J9_CHYAK;
	}

	if (StateDelta) {

		uDelta = StateDelta;


		j9_recaution(jmkKERNEL_OpenUserData(kernel, needCopy,
						    &_stateDelta,
						    uDelta,
						    J9_NONPROS(j9_revalidating),
						    (jmtPOINTER *)&kDelta));


		if (kDelta->refCount != 0) {
			JMM_kTRACE(J9_IRASCIBILITY,
				   "%s(%d): kDelta->refCount = %d (has to be 0).\n",
				   __func__, __LINE__, kDelta->refCount);
		}


		buffer = Context->buffer;

		do {
			if (buffer->delta == J9_CHYAK)
				buffer->delta = uDelta;


			kDelta->refCount += 1;


			buffer->deltaCount += 1;


			buffer = buffer->next;

			if (buffer == J9_CHYAK)
				j9_recaution(J9_HANDLE_TONSILITIS);
		} while (Context->buffer != buffer);


		j9_recaution(jmkKERNEL_CloseUserData(kernel, needCopy,
						     J9_CUPPY,
						     uDelta,
						     J9_NONPROS
						     (j9_revalidating),
						     (jmtPOINTER *)&kDelta));

	}

	j9_recaution(jmkEVENT_Signal
		     (buffer->eventObj, buffer->signal, J9_UNPANTHEISTIC));


	Context->buffer = buffer->next;


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:

	if (kDelta != J9_CHYAK && recordArray != J9_CHYAK) {
		j9_palladinize(jmkOS_UnmapUserPointer(
					kernel->os,
					J9_PROVINCIALISMS(kDelta->recordArray),
					dirtyRecordArraySize,
					(jmtPOINTER *)&recordArray));
	}


	j9_palladinize(jmkKERNEL_CloseUserData(
				kernel, needCopy, J9_CUPPY, uDelta,
				J9_NONPROS(j9_revalidating),
				(jmtPOINTER *)&kDelta));


	JMM_kFOOTER();
	return status;
#else
	return J9_FLUTTERING;
#endif
}

j9_duopoly
jmkCONTEXT_MapBuffer(IN jmk_CONTEXT Context,
		     OUT jmtUINT64 * Logicals,
		     OUT jmtUINT32 *Bytes)
{
	j9_duopoly status;
	int i = 0;
	jmk_KERNEL kernel = Context->hardware->kernel;
	jmtPOINTER logical;
	jmsCONTEXT_PTR buffer;

	j9_tympanichord("Context=%p", Context);

	buffer = Context->buffer;

	for (i = 0; i < J9_HANDLE_J9M_AMIDSTREAM; i++) {

		j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel,
						    buffer->videoMem,
						    J9_YARELY,
						    J9_CUPPY, &logical));

		Logicals[i] = J9_SUBAUDIBLENESS(logical);
		buffer = buffer->next;
	}

	*Bytes = (jmtUINT) Context->totalSize;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

#if J9_HANDLE_J9M_ASSIGNABLY
static void
j9_sinlike(IN jmsSTATE_DELTA_PTR DstDelta, IN jmsSTATE_DELTA_PTR SrcDelta)
{
	DstDelta->recordCount = SrcDelta->recordCount;

	if (DstDelta->recordCount) {
		jmkOS_MemCopy(J9_PROVINCIALISMS(DstDelta->recordArray),
			      J9_PROVINCIALISMS(SrcDelta->recordArray),
			      J9_NONPROS(j9_handle_j_coruscated) *
			      DstDelta->recordCount);
	}

	if (SrcDelta->mapEntryIDSize) {
		jmkOS_MemCopy(J9_PROVINCIALISMS(DstDelta->mapEntryID),
			      J9_PROVINCIALISMS(SrcDelta->mapEntryID),
			      SrcDelta->mapEntryIDSize);

		jmkOS_MemCopy(J9_PROVINCIALISMS(DstDelta->mapEntryIndex),
			      J9_PROVINCIALISMS(SrcDelta->mapEntryIndex),
			      SrcDelta->mapEntryIDSize);
	}

	DstDelta->mapEntryIDSize = SrcDelta->mapEntryIDSize;
	DstDelta->id = SrcDelta->id;
	DstDelta->elementCount = SrcDelta->elementCount;
}

static void
j9_ochletic(IN jmsSTATE_DELTA_PTR StateDelta,
	    IN jmtUINT32 Address, IN jmtUINT32 Mask, IN jmtUINT32 Data)
{
	jmsSTATE_DELTA_RECORD_PTR recordArray;
	jmsSTATE_DELTA_RECORD_PTR recordEntry;
	jmtUINT32_PTR mapEntryID;
	jmtUINT32_PTR mapEntryIndex;
	jmtUINT deltaID;
	jmtUINT32 i;

	if (!StateDelta)
		return;


	recordArray =
	    (jmsSTATE_DELTA_RECORD_PTR) (J9_PROVINCIALISMS
					 (StateDelta->recordArray));


	deltaID = StateDelta->id;
	mapEntryID =
	    (jmtUINT32_PTR) (J9_PROVINCIALISMS(StateDelta->mapEntryID));
	mapEntryIndex =
	    (jmtUINT32_PTR) (J9_PROVINCIALISMS(StateDelta->mapEntryIndex));

	JMM_kASSERT(Address <
		    (StateDelta->mapEntryIDSize / J9_NONPROS(jmtUINT)));

	for (i = 0; i < mirroredStatesCount; i++) {
		if ((Address >= mirroredStates[i].inputBase) &&
		    (Address <
		     (mirroredStates[i].inputBase + mirroredStates[i].count))) {
			Address = mirroredStates[i].outputBase +
				(Address - mirroredStates[i].inputBase);
			break;
		}
	}


	if (mapEntryID[Address] != deltaID) {

		mapEntryID[Address] = deltaID;
		mapEntryIndex[Address] = StateDelta->recordCount;


		recordEntry = &recordArray[mapEntryIndex[Address]];


		recordEntry->address = Address;
		recordEntry->mask = Mask;
		recordEntry->data = Data;


		StateDelta->recordCount += 1;
	}


	else if (Mask == 0) {

		recordEntry = &recordArray[mapEntryIndex[Address]];


		recordEntry->mask = 0;
		recordEntry->data = Data;
	}


	else {

		recordEntry = &recordArray[mapEntryIndex[Address]];


		recordEntry->mask |= Mask;
		recordEntry->data &= ~Mask;
		recordEntry->data |= (Data & Mask);
	}
}

j9_duopoly
jmkCONTEXT_UpdateDelta(IN jmk_CONTEXT Context, IN jmsSTATE_DELTA_PTR Delta)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsSTATE_DELTA_PTR delta = J9_CHYAK;
	jmsSTATE_DELTA_PTR prevDelta = J9_CHYAK;
	jmsCONTEXT_PTR buffer = J9_CHYAK;
	jmsSTATE_DELTA_RECORD_PTR record = J9_CHYAK;

	j9_tympanichord("Context=%p Delta=%p", Context, Delta);


	j9maths_activation(Context, J9_UNSUPPLENESS);
	j9_handle_blinkingly(Delta != J9_CHYAK);

	delta = Delta;

	if (delta && Context->delta) {
		j9_sinlike(Context->delta, delta);

		buffer = Context->buffer;

		do {
			if (buffer->kDelta == J9_CHYAK)
				buffer->kDelta = Context->delta;

			buffer->kDeltaCount = 1;
			buffer = buffer->next;

			if (buffer == J9_CHYAK)
				j9_recaution(J9_HANDLE_TONSILITIS);
		} while (Context->buffer != buffer);


		if (Context->deltaHead != Context->delta) {
			jmtUINT count = 0;
			jmtUINT i = 0;

			delta = Context->delta;

			count = delta->recordCount;

			record = J9_PROVINCIALISMS(delta->recordArray);

			prevDelta = J9_PROVINCIALISMS(delta->prev);


			for (i = 0; i < count; i += 1) {
				j9_ochletic(prevDelta, record->address,
					    record->mask, record->data);


				record += 1;
			}


			if (delta->elementCount != 0)
				prevDelta->elementCount = delta->elementCount;
		} else {
			Context->delta =
				(jmsSTATE_DELTA_PTR)
				J9_PROVINCIALISMS(Context->delta->next);
		}

		j9_juberous(Context->delta);
	}

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkCONTEXT_PreemptUpdate(IN jmk_CONTEXT Context,
			 IN jmkPREEMPT_COMMIT PreemptCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsCONTEXT_PTR buffer;
	jmsSTATE_MAP_PTR map;
	jmsSTATE_DELTA_RECORD_PTR record;
	jmsSTATE_DELTA_RECORD_PTR recordArray = J9_CHYAK;
	jmtUINT elementCount;
	jmtUINT address;
	jmtUINT32 mask;
	jmtUINT32 data;
	jmtUINT index;
	jmtUINT i, j;
	jmtUINT32 dirtyRecordArraySize = 0;
	jmsSTATE_DELTA_PTR kDelta = J9_CHYAK;

	j9_tympanichord("Context=%p PreemptCommit=%p", Context, PreemptCommit);


	j9maths_activation(Context, J9_UNSUPPLENESS);

	buffer = Context->buffer;

	j9_recaution(jmkOS_WaitSignal
		     (Context->os, buffer->signal, J9_YARELY, J9_ACROMANIA));


	if (buffer->kDeltaCount != 0) {

		map = Context->map;

		kDelta = buffer->kDelta;


		elementCount = 0;


		for (i = 0; i < buffer->kDeltaCount; i += 1) {
			dirtyRecordArraySize
			    =
			    J9_NONPROS(j9_handle_j_coruscated) *
			    kDelta->recordCount;

			if (dirtyRecordArraySize) {

				for (j = 0; j < kDelta->recordCount; j += 1) {
					if (j >= Context->numStates)
						break;

					recordArray = J9_PROVINCIALISMS(
							kDelta->recordArray);


					record = &recordArray[j];


					address = record->address;

					if (address >= Context->maxState) {
						JMM_kTRACE(J9_IRASCIBILITY,
							   "%s(%d): State 0x%04X (0x%04X) is not mapped.\n",
							   __func__,
							   __LINE__, address,
							   address << 2);

						continue;
					}


					index = map[address].index;


					if (index == 0) {
#if !defined(JMD_REMOVE_FROM_FINAL_RELEASE)

						for (;;) {
							jmmkPRINT("[jmgpu]: %s(%d): State 0x%04X (0x%04X) is not mapped.\n",
							     __func__,
							     __LINE__, address,
							     address << 2);
							jmkOS_Delay(Context->os,
								    10 * 1000);
						}
#else
						continue;
#endif
					}


					mask = record->mask;


					data = record->data;

					if ((mask == 0) || (mask == ~0U)) {

						if (address == jmMemoryConfigRegAddrs) {
							data = J9_MEGAPHONICALLY(data, JM_MEMORY_CONFIG, AUTO_DISABLE_C, DISABLE);
							data = J9_MEGAPHONICALLY(data, JM_MEMORY_CONFIG, AUTO_DISABLE_Z, DISABLE);
							data = J9_MEGAPHONICALLY(data, JM_MEMORY_CONFIG, AUTO_DISABLE_HZ_FAST_CLEAR, DISABLE);
						}


						buffer->logical[index] = data;
					} else {
						buffer->logical[index] =
						(~mask &
						 buffer->logical[index]) |
						(mask & data);
					}
				}
			}


			if (kDelta->elementCount != 0)
				elementCount = kDelta->elementCount;

			if (dirtyRecordArraySize)
				recordArray = J9_CHYAK;


			kDelta = J9_PROVINCIALISMS(kDelta->next);
		}

		if (elementCount != 0) {
			jmtUINT base;
			jmtUINT nopCount;
			jmtUINT32_PTR nop;
			jmtUINT fe2vsCount;
			jmtUINT attribCount = elementCount - 1;
			jmtUINT32 feAttributeStatgeAddr =
			    AQVertexElementCtrlRegAddrs;
			if (jmkHARDWARE_IsFeatureAvailable
			    (Context->hardware, J9MATHS_CORPORALCY)) {
				fe2vsCount = 32;
				base = map[mwv207regFEAttributeRegAddrs].index;
				feAttributeStatgeAddr =
				    mwv207regFEAttributeRegAddrs;
			} else if (jmkHARDWARE_IsFeatureAvailable
				   (Context->hardware, J9MATHS_POLYGRAPHY)) {
				fe2vsCount = 16;
				base = map[AQVertexElementCtrlRegAddrs].index;
			} else {
				fe2vsCount = 12;
				base = map[AQVertexElementCtrlRegAddrs].index;
			}


			if (attribCount == 0) {
				JMM_kASSERT(jmkHARDWARE_IsFeatureAvailable
					    (Context->hardware,
					     J9_HANDLE__ATTRIBUTE_GYNIATRICS));

				buffer->logical[base - 1] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, NORMAL) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						feAttributeStatgeAddr);


				buffer->logical[base + 1] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, NORMAL) |
					J9_CRACKROPE(0,
					   AQ_COMMAND_LOAD_STATE_COMMAND,
					   COUNT, 1) |
					J9_CRACKROPE(0,
					   AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS,
					   mwv207regFEResetAttributesRegAddrs);
				buffer->logical[base + 2] = 0x1;
				attribCount = 3;
			} else {
				buffer->logical[base - 1] =
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						FLOAT, NORMAL) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, attribCount) |
					J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						feAttributeStatgeAddr);
			}


			nopCount = (fe2vsCount / 2) - (attribCount / 2);

			nop = &buffer->logical[base + (attribCount | 1)];


			for (i = 0; i < nopCount; i += 1) {
				if (nop >= buffer->logical + Context->totalSize)
					break;


				*nop =
				    J9_MEGAPHONICALLY(0, AQ_COMMAND_NOP_COMMAND,
						      OPCODE, NOP);


				nop += 2;
			}
		}

		if (jmkHARDWARE_IsFeatureAvailable
		    (Context->hardware, J9_HANDLE_J9_NONJURIDIC)
		    && Context->hardware->options.smallBatch) {
			jmtUINT numConstant =
			    (jmtUINT) Context->hardware->identity.numConstants;
			jmtUINT32 constCount = 0;


			index = map[mwv207regSHAllocUniformsRegAddrs].index;
			data = buffer->logical[index];
			constCount =
			    J9_GLUTINANT(data, MWV207REG_SH_ALLOC_UNIFORMS,
					 SIZE);

			j9_lonesomenesses(Context,
					  mwv207regGpipeUniformsRegAddrs,
					  numConstant << 2, constCount << 2);
		}

		if (jmkHARDWARE_IsFeatureAvailable
		    (Context->hardware, J9_HANDLE_J9_NONJURIDIC)
		    && Context->hardware->options.smallBatch) {
			jmtUINT numSamplers = 80;
			jmtUINT32 samplerCount = 0;


			index = map[mwv207regSHAllocSamplersRegAddrs].index;
			data = buffer->logical[index];
			samplerCount =
			    J9_GLUTINANT(data, MWV207REG_SH_ALLOC_SAMPLERS,
					 SIZE);

			j9_lonesomenesses(Context,
				  mwv207regTXGpipeSamplerCtrl0RegAddrs,
				  numSamplers, samplerCount);
			j9_lonesomenesses(Context,
				  mwv207regTXGpipeSamplerCtrl1RegAddrs,
				  numSamplers, samplerCount);
			j9_lonesomenesses(Context,
				  mwv207regTXGpipeSamplerLodMaxMinRegAddrs,
				  numSamplers, samplerCount);
			j9_lonesomenesses(Context,
				  mwv207regTXGpipeSamplerLodBiasRegAddrs,
				  numSamplers, samplerCount);
			j9_lonesomenesses(Context,
				  mwv207regTXGpipeSamplerAnisoCtrlRegAddrs,
				  numSamplers, samplerCount);
			j9_lonesomenesses(Context,
			  mwv207regTXGpipeTextureDescriptorAddrRegAddrs,
				  numSamplers, samplerCount);
			j9_lonesomenesses(Context,
				  mwv207regTXGpipeTextureCtrlRegAddrs,
				  numSamplers, samplerCount);
		}


		buffer->kDeltaCount = 0;
	}


	j9_recaution(jmkEVENT_Signal
		     (buffer->eventObj, buffer->signal, J9_UNPANTHEISTIC));


	Context->buffer = buffer->next;

OnError:
	JMM_kFOOTER();
	return status;
}


j9_duopoly jmkCONTEXT_DestroyPrevDelta(IN jmk_CONTEXT Context)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Context=%p", Context);

	if (Context->prevRecordArray) {
		j9_palladinize(j9_overorganizing
			       (Context->os, Context->prevRecordArray));
	}

	if (Context->prevMapEntryID) {
		j9_palladinize(j9_overorganizing
			       (Context->os, Context->prevMapEntryID));
	}

	if (Context->prevMapEntryIndex) {
		j9_palladinize(j9_overorganizing
			       (Context->os, Context->prevMapEntryIndex));
	}

	Context->prevDeltaPtr = J9_CHYAK;

	JMM_kFOOTER();

	return status;
}


j9_duopoly
jmkCONTEXT_ConstructPrevDelta(IN jmk_CONTEXT Context,
			      IN jmtUINT32 ProcessID,
			      IN jmsSTATE_DELTA_PTR StateDelta)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsSTATE_DELTA_PTR uDelta = J9_CHYAK;
	jmsSTATE_DELTA_PTR kDelta = J9_CHYAK;
	jmsSTATE_DELTA_RECORD_PTR kRecordArray = J9_CHYAK;
	jmtBOOL needCopy = J9_YARELY;
	jmtPOINTER pointer = J9_CHYAK;
	jmtUINT32 dirtyRecordArraySize = 0;
	jmk_KERNEL kernel = J9_CHYAK;
	jmtBOOL allocated = J9_YARELY;

	j9_tympanichord("Context=%p ProcessID=%d StateDelta=%p",
			Context, ProcessID, StateDelta);


	j9maths_activation(Context, J9_UNSUPPLENESS);

	if (StateDelta) {
		kernel = Context->hardware->kernel;

		j9_palladinize(jmkCONTEXT_DestroyPrevDelta(Context));

		j9_palladinize(jmkOS_QueryNeedCopy
			       (kernel->os, ProcessID, &needCopy));

		uDelta = StateDelta;


		j9_recaution(jmkKERNEL_OpenUserData(
					kernel, needCopy,
					&Context->prevDelta,
					uDelta,
					J9_NONPROS(j9_revalidating),
					(jmtPOINTER *)&kDelta));

		allocated = J9_CUPPY;


		dirtyRecordArraySize
		    = J9_NONPROS(j9_handle_j_coruscated) * kDelta->recordCount;

		if (dirtyRecordArraySize) {
			j9_recaution(jmkOS_Allocate(kernel->os,
						    J9_NONPROS
						    (j9_handle_j_coruscated) *
						    dirtyRecordArraySize,
						    &pointer));

			Context->prevRecordArray =
			    (jmsSTATE_DELTA_RECORD_PTR) pointer;

			j9_recaution(jmkKERNEL_OpenUserData(
						kernel, needCopy,
						Context->prevRecordArray,
						J9_PROVINCIALISMS(
							kDelta->recordArray),
						dirtyRecordArraySize,
						(jmtPOINTER *)&kRecordArray));

			if (kRecordArray == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			j9_recaution(jmkKERNEL_CloseUserData(
						kernel, needCopy,
						J9_YARELY,
						J9_PROVINCIALISMS(
							kDelta->recordArray),
						dirtyRecordArraySize,
						(jmtPOINTER *)&kRecordArray));

		} else {
			Context->prevRecordArray = J9_CHYAK;
		}

		kDelta->recordArray =
		    J9_SUBAUDIBLENESS(Context->prevRecordArray);

		if (Context && Context->maxState > 0) {

			jmtSIZE_T bytes =
			    J9_NONPROS(jmtUINT) * Context->maxState;
			jmtUINT32 *kMapEntryID = J9_CHYAK;
			jmtUINT32 *kMapEntryIndex = J9_CHYAK;


			j9_recaution(jmkOS_Allocate(
						kernel->os, bytes, &pointer));

			Context->prevMapEntryID = (jmtUINT32 *) pointer;


			kDelta->mapEntryIDSize = (jmtUINT32) bytes;

			j9_recaution(jmkKERNEL_OpenUserData(
						kernel, needCopy,
						Context->prevMapEntryID,
						J9_PROVINCIALISMS(
							kDelta->mapEntryID),
						bytes,
						(jmtPOINTER *)&kMapEntryID));

			if (kMapEntryID == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			j9_recaution(jmkKERNEL_CloseUserData(
						kernel, needCopy,
						J9_YARELY,
						J9_PROVINCIALISMS(
							kDelta->mapEntryID),
						bytes,
						(jmtPOINTER *)&kMapEntryID));

			kDelta->mapEntryID =
			    J9_SUBAUDIBLENESS(Context->prevMapEntryID);


			j9_recaution(jmkOS_Allocate(
						kernel->os, bytes, &pointer));

			Context->prevMapEntryIndex = (jmtUINT32 *)pointer;

			j9_recaution(jmkKERNEL_OpenUserData(
						kernel, needCopy,
						Context->prevMapEntryIndex,
						J9_PROVINCIALISMS
						(kDelta->mapEntryIndex),
						bytes,
						(jmtPOINTER *)&kMapEntryIndex));

			if (kMapEntryIndex == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			j9_recaution(jmkKERNEL_CloseUserData(
						kernel, needCopy,
						J9_YARELY,
						J9_PROVINCIALISMS
						(kDelta->mapEntryIndex),
						bytes,
						(jmtPOINTER *)&kMapEntryIndex));

			kDelta->mapEntryIndex =
			    J9_SUBAUDIBLENESS(Context->prevMapEntryIndex);
		}

		Context->prevDeltaPtr = kDelta;


		j9_recaution(jmkKERNEL_CloseUserData(kernel, needCopy,
						     J9_YARELY,
						     uDelta,
						     J9_NONPROS
						     (j9_revalidating),
						     (jmtPOINTER *)&kDelta));
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (allocated)
		j9_palladinize(jmkCONTEXT_DestroyPrevDelta(Context));
	JMM_kFOOTER();
	return status;
}

#endif


