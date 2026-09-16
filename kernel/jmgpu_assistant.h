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





#if J9_OSTEODERMIS

#if J9_CHITTERLINGS

#include "jmgpu_marshal.h"
#include "jmgpu_relational.h"

#define J9_FUTTAH 0

typedef enum _USC_NN_TYPE {
	USC_NN_TYPE_V6,
	USC_NN_TYPE_V7,
	USC_NN_TYPE_V8,
} USC_NN_TYPE;
j9_duopoly
_InitializeUSC_NNCommands(IN jmk_HARDWARE Hardware,
			  IN USC_NN_TYPE hw_type,
			  IN jmtUINT32 kernelAddress,
			  IN jmtUINT32 inImageAddress,
			  IN jmtUINT32 outImageAddress,
			  IN OUT jmtUINT8_PTR data_type,
			  IN OUT jmtUINT32_PTR item_size,
			  IN OUT jmtUINT32_PTR core_count,
			  IN OUT jmtSIZE_T_PTR patchBufferSizes,
			  IN OUT jmtUINT32_PTR * nnCommands)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_OS os = Hardware->os;

	jmtUINT32_PTR command = *nnCommands;

	jmtUINT8 kernelDataType = *data_type;
	jmtUINT8 inImageDataType = *data_type;
	jmtUINT8 outImageDataType = *data_type;

	jmtUINT32 kernelsPerCore = 1;

	jmtUINT32 inImageXSize = 3;
	jmtUINT32 inImageYSize = 2;

	jmtUINT32 outImageXSize = 2;
	jmtUINT32 outImageYSize = 1;
	jmtUINT32 outImageZSize = 1;

	jmtUINT32 kernelXYSize = 2;
	jmtUINT32 kernelZSize = 1;

	jmtUINT32 nn_layer_flush = 1, noZOffset = 0, size =
	    J9_NONPROS(jmtUINT32) * ((hw_type == USC_NN_TYPE_V6) ? 16 : 32);
	jmtUINT32 imageEndAddress = 2048, post_shift = 0, post_shift_bit56 = 0;
	jmtUINT8 coefZP = 0, outputZP = 0;
	jmsFEATURE_DATABASE *db =
	    (jmsFEATURE_DATABASE *) Hardware->featureDatabase;
	jmtUINT32 config = 0, index = 0;
	jmtUINT32 configuration[][3] = {

		{ 1, MWV207REG_NN_DATA_TYPE_INT8, db->j9_unpersuasible },
		{ 2, MWV207REG_NN_DATA_TYPE_INT16, db->j9_discrimination },
		{ 2, MWV207REG_NN_DATA_TYPE_FP16, db->j9mirror_transmutes },
		{ 2, MWV207REG_NN_DATA_TYPE_BFP16, db->j9maths_aurivorous },
	};

	*patchBufferSizes = size;

	if (command == NULL) {
		j9_recaution(jmkOS_Allocate
			     (os, size, (jmtPOINTER *) (&command)));
		j9_recaution(jmkOS_ZeroMemory(command, size));

		*nnCommands = command;
	}

	JMM_kASSERT(command != NULL);
	j9_bronchotyphus(0, 0, 0, 0, 0);

	for (index = 0; index < J9_SANDBARS(configuration); index++) {
		if (configuration[index][2] > 0)
			break;
	}

	if (index == J9_SANDBARS(configuration))
		JMM_kASSERT("Hardware not support NN!");

#if J9_FUTTAH
	jmmkPRINT("The hardware(0x%0x) support %d\n", db->j9_nascent, index);
	jmmkPRINT
	    ("\tcore int8  %d\n\tcore int16 %d\n\tcore fp16  %d\n\tcore bfp16 %d\n",
	     db->j9_unpersuasible, db->j9_discrimination,
	     db->j9mirror_transmutes, db->j9maths_aurivorous);

#endif
	*item_size = configuration[index][0];
	*data_type = (jmtUINT8) configuration[index][1];
	*core_count = configuration[index][2];

	kernelDataType = *data_type;
	inImageDataType = *data_type;
	outImageDataType = *data_type;

	switch (hw_type) {
	case USC_NN_TYPE_V8:
		noZOffset = 1;

		outputZP = 0;
		post_shift =
		    (jmkHARDWARE_IsFeatureAvailable
		     (Hardware, J9_HANDLE_ATTRIBUTE_LITTERMATE)) ? 0x1f : 0;
		post_shift_bit56 =
		    (jmkHARDWARE_IsFeatureAvailable
		     (Hardware, J9_HANDLE_ATTRIBUTE_LITTERMATE)) ? 3 : 0;

		break;
	case USC_NN_TYPE_V7:
	case USC_NN_TYPE_V6:
		post_shift =
		    (*data_type == MWV207REG_NN_DATA_TYPE_INT8) ? 15 : 0;
		break;
	default:
		break;
	}


	j9_uncoherentness(command, J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0, LAYER_TYPE, 0)
			  |J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0,
					NO_ZLOCATION_OFFSET, noZOffset)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0,
					 KERNEL_XYSIZE, kernelXYSize)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0,
					 KERNEL_ZSIZE, (kernelZSize & 0x3FFF))
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0,
					 KERNELS_PER_CORE, kernelsPerCore)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0, POOLING, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0,
					 POOLING_XYSIZE, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0, PRELU, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD0, LAST_LAYER,
					 nn_layer_flush));

	config =
	    J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1, INIMAGE_XSIZE,
			 inImageXSize)
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1, INIMAGE_YSIZE,
			   inImageYSize)
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1, KERNEL_DATA_TYPE,
			   kernelDataType >> 1)
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1, INIMAGE_DATA_TYPE,
			   inImageDataType >> 1)
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1, OUTIMAGE_DATA_TYPE,
			   outImageDataType >> 1)
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1, KERNEL_DATA_SIZE_MINUS1,
			   kernelDataType & 0x1)
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1, INIMAGE_DATA_SIZE_MINUS1,
			   inImageDataType & 0x1)
	    | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD1,
			   OUTIMAGE_DATA_SIZE_MINUS1, outImageDataType & 0x1);


	j9_uncoherentness(command, config);


	j9_uncoherentness(command,
			  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2, RELU, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2,
					 ACTIVATION_FUNCTION, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2,
					 INIMAGE_XOFFSET, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2,
					 INIMAGE_YOFFSET, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2,
					 POST_MULTIPLIER, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2, BRICK_MODE,
					 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2,
					 BRICK_DISTANCE, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD2, POST_SHIFT,
					 post_shift));


	j9_uncoherentness(command,
			  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD3,
				       OUTIMAGE_XSIZE, outImageXSize)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD3,
					 OUTIMAGE_YSIZE, outImageYSize)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD3, NO_BIAS, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD3, NO_FLUSH,
					 0));


	j9_uncoherentness(command,
			  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD4,
				       OUTIMAGE_ZSIZE, outImageZSize)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD4,
					 ROUNDING_MODE,
					 MWV207REG_NN_INST_WORD4_ROUNDING_MODE_SIMPLE_ROUNDING)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD4,
					 OUTIMAGE_TILE_XSIZE,
					 1)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD4,
					 OUTIMAGE_TILE_YSIZE,
					 1)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD4,
					 INIMAGE_XOFFSET_BIT3, (0 >> 3) & 0x1)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD4,
					 INIMAGE_YOFFSET_BIT3, (0 >> 3) & 0x1));


	j9_uncoherentness(command,
			  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD5,
				       KERNEL_ZSIZE1,
				       ((kernelZSize >> 14) & 0x3F))
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD5,
					 KERNEL_BASE_ADDRESS,
					 (kernelAddress >> 6)));


	j9_uncoherentness(command, inImageAddress);

	j9_uncoherentness(command, outImageAddress);

	j9_uncoherentness(command,
			     J9_CRACKROPE(0, MWV207REG_NN_INST_WORD8,
					       KERNEL_YSIZE, kernelXYSize)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD8,
					 OUT_IMAGE_YSTRIDE, outImageYSize));


	j9_uncoherentness(command, 0);


	j9_uncoherentness(command, 0);


	j9_uncoherentness(command, 0);


	j9_uncoherentness(command, 0);


	j9_uncoherentness(command, 0);


	j9_uncoherentness(command, imageEndAddress);


	j9_uncoherentness(command,
			  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD15,
				       IN_IMAGE_BORDER_MODE, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD15,
					 IN_IMAGE_BORDER_CONSTANT, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD15,
					 KERNEL_DATA_TYPE_MSB,
					 kernelDataType >> 2)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD15,
					 INIMAGE_DATA_TYPE_MSB,
					 inImageDataType >> 2)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD15,
					 OUTIMAGE_DATA_TYPE_MSB,
					 outImageDataType >> 2)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD15,
					 POST_MULTIPLIER_BIT6TO1, 0)
			  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD15,
					 POST_SHIFT_BIT6TO5, post_shift_bit56));


	if (hw_type == USC_NN_TYPE_V7 || hw_type == USC_NN_TYPE_V8) {

		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD16,
					       IN_IMAGE_XSTRIDE,
					       inImageXSize * (*item_size))
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD16,
						 IN_IMAGE_YSTRIDE,
						 inImageYSize));


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD17,
					       OUT_IMAGE_XSTRIDE,
					       outImageXSize * (*item_size))
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD17,
						 POST_MULTIPLIER_BIT14TO7, 0));


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD18,
					       OUT_IMAGE_CIRCULAR_BUF_SIZE,
					       0 >> 6)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD18,
						 PER_CH_POST_MULT, 0)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD18,
						 IN_IMAGE_XOFFSET_BIT4,
						 (0 >> 4) & 0x1)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD18,
						 IN_IMAGE_YOFFSET_BIT4,
						 (0 >> 4) & 0x1)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD18,
						 SLOW_OUTPUT, 0)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD18,
						 KERNEL_DATA_TYPE_BIT3,
						 kernelDataType >> 3));


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD19,
					       OUT_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1,
					       0xFFFFFFFF >> 6)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD19,
						 B_FLOAT16_MODE, 0)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD19,
						 IN_IMAGE_DATA_TYPE_BIT3,
						 inImageDataType >> 3));


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD20,
					       IN_IMAGE_CIRCULAR_BUF_SIZE,
					       0 >> 6)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD20,
						 OUT_IMAGE_DATA_TYPE_BIT3,
						 outImageDataType >> 3));


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD21,
					       IN_IMAGE_CIRCULAR_BUF_END_ADDR_PLUS1,
					       0xFFFFFFFF >> 6));


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD22,
					       COEF_ZERO_POINT, coefZP)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD22,
						 OUT_IMAGE_ZERO_POINT, outputZP)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD22,
						 KERNEL_DIRECT_STREAM_FROM_VIP_SRAM,
						 0)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD22,
						 DEPTH_WISE, 0)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD22,
						 POST_MULTIPLIER_BIT22TO15, 0));


		j9_uncoherentness(command, 0);


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD24,
					       IN_IMAGE_TRANSPOSE_CH_MINUS_ONE,
					       0)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD24,
						 OUT_IMAGE_TRANSPOSE_BUF_START_ADDR,
						 0 >> 4));


		j9_uncoherentness(command,
				  J9_CRACKROPE(0, MWV207REG_NN_INST_WORD25,
					       OUT_IMAGE_TRANSPOSE_CH_MINUS_ONE,
					       0)
				  | J9_CRACKROPE(0, MWV207REG_NN_INST_WORD25,
						 OUT_IMAGE_TRANSPOSE_BUF_END_ADDR_PLUS_ONE,
						 0 >> 4));
	}

OnError:
	return status;
}

j9_duopoly
j9_staxis(IN jmtUINT8_PTR * base,
	  IN jmtUINT32 value, IN jmtUINT32_PTR offset, IN jmtUINT length)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32_PTR msb = (jmtUINT32_PTR) (*base) + 1, lsb =
	    (jmtUINT32_PTR) (*base);

	JMM_kASSERT(*offset <= 32 && length <= 32);

	if ((*offset) < 32) {
		jmtUINT32 end = (*offset) + length, data = *lsb;

		if (end < 32) {
			data = (*lsb & ((1 << *offset) - 1));
			data |= (*lsb & ~((1 << end) - 1));
			data |= (value << *offset);

			*lsb = data;
			*offset = end;
		} else if (end < 64) {
			jmtUINT32 length_m = end - 32;
			jmtUINT32 data_l = (*lsb & ((1 << *offset) - 1));
			jmtUINT32 data_m = (*msb & ~((1 << length_m) - 1));

			data_l |= (value << *offset);
			data_m |= (value >> length_m);

			*lsb = data_l;

			if (end > 32)
				*msb = data_m;

			*offset = length_m;

			*base = (jmtUINT8_PTR) msb;
		}

	}

	return status;
}

j9_duopoly
_InitializeUSC_NNKernel(IN jmk_HARDWARE Hardware,
			IN USC_NN_TYPE hw_type,
			IN jmtUINT8 data_type,
			IN jmtUINT32 item_size,
			IN jmtUINT32 core_count, IN OUT jmtUINT32_PTR nnKernels)
{
	j9_duopoly status = J9_FLUTTERING;

	jmtUINT8_PTR kernels = (jmtUINT8_PTR) nnKernels;
	jmtUINT8_PTR kernel_stream_size_ptr = 0;
	jmtUINT32 filterTotalCount = 1, filterSize =
	    2 * 2 * 1 * item_size, biasSize = 4;


	if (hw_type == USC_NN_TYPE_V8) {
		jmtUINT32 i = 0, offset = 0;

		jmtUINT8 rlt[][18] = {
		{ 0 }, { 1, 1, 0, 1 }, { 7, 1 }, { 0 }, { 3, 1, 0, 1 },
		{ 0 }, { 0 }, { 1, 1, 0, 1 }
		};
		jmtUINT8 map[][9] = {
			{ 1, 8, 7, 0, 4, 5, 6, 2, 3 },
			{ 1, 5, 0, 7, 8, 2, 6, 3, 4 },
			{ 1, 0, 7, 8, 4, 5, 6, 2, 3 },
		};
		jmtBOOL bit16 = (data_type == MWV207REG_NN_DATA_TYPE_INT16)
		    || data_type == (MWV207REG_NN_DATA_TYPE_FP16)
		    || data_type == (MWV207REG_NN_DATA_TYPE_BFP16);
		jmtBOOL fp16 = (data_type == MWV207REG_NN_DATA_TYPE_FP16);
		jmtUINT32 index =
		    (data_type ==
		     MWV207REG_NN_DATA_TYPE_FP16) ? 1 : ((data_type ==
							  MWV207REG_NN_DATA_TYPE_BFP16)
							 ? 2 : 0);

		j9_recaution(j9_staxis(&kernels, 0, &offset, 1));
		j9_recaution(j9_staxis(&kernels, bit16, &offset, 1));
		j9_recaution(j9_staxis(&kernels, fp16, &offset, 1));
		j9_recaution(j9_staxis(&kernels, 0, &offset, 1));
		j9_recaution(j9_staxis(&kernels, 1, &offset, 4));
		j9_recaution(j9_staxis(&kernels, 4, &offset, 8));

		for (i = 0; i < 18; i++)
			j9_recaution(j9_staxis(&kernels, rlt[data_type][i], &offset, 8));

		for (i = 0; i < 4; i++)
			j9_recaution(j9_staxis(&kernels, (map[index][2 * i + 1] << 4) + map[index][2 * i], &offset, 8));

		j9_recaution(j9_staxis(&kernels, 0, &offset, 16));

		j9_recaution(j9_staxis(&kernels, 0, &offset, 16));

		kernel_stream_size_ptr = kernels;
		for (i = 0; i < core_count; i++)
			j9_recaution(j9_staxis(&kernels, 0, &offset, 32));

		kernels = (jmtUINT8_PTR) nnKernels + J9_UNFLEETING((jmtUINT32)
								   ((jmtUINT32_PTR) kernels - nnKernels), 64);

		switch (data_type) {
		case MWV207REG_NN_DATA_TYPE_INT16:
			j9_recaution(j9_staxis(&kernels, 0x04058000, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x640101fc, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x00001200, &offset, 32));

			j9_recaution(j9_staxis(&kernel_stream_size_ptr, 0x0000006d, &offset, 32));

			break;
		case MWV207REG_NN_DATA_TYPE_UINT8:
		case MWV207REG_NN_DATA_TYPE_INT8:
			j9_recaution(j9_staxis(&kernels, 0xec000038, &offset, 32));

			j9_recaution(j9_staxis(&kernel_stream_size_ptr, 0x35, &offset, 32));

			break;
		case MWV207REG_NN_DATA_TYPE_FP16:
			j9_recaution(j9_staxis(&kernels, 0x0009db68, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x000006c0, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x000001f0, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x00000900, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x00024000, &offset, 32));

			j9_recaution(j9_staxis(&kernel_stream_size_ptr, 0x000000a3, &offset, 32));

			break;
		case MWV207REG_NN_DATA_TYPE_BFP16:
			j9_recaution(j9_staxis(&kernels, 0x0007fff8, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x7f00fdfc, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0xc0397f00, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x0900001f, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x40000000, &offset, 32));
			j9_recaution(j9_staxis(&kernels, 0x00000002, &offset, 32));

			j9_recaution(j9_staxis(&kernel_stream_size_ptr, 0x000000b2, &offset, 32));

			break;
		default:
			JMM_kASSERT
			    ("Huffman encode not support this format! Please check!");
			break;
		}

	} else {
		jmtBOOL zero_all = J9_YARELY;
		jmtUINT8 zrl = 0;
		jmtUINT16 vznum = 1;
		jmtUINT32 bias = 0;
		jmtUINT32 total_size = J9_UNFLEETING((filterTotalCount * (filterSize + biasSize + 3) + 3), 64);

		jmkOS_ZeroMemory(kernels, total_size + 64);

		*((jmtUINT32_PTR) kernels) = total_size;
		kernels += total_size;
		if (zero_all)
			*((jmtUINT32_PTR) kernels) = (vznum << (8 * item_size));
		else {
			jmtINT16 value =
			    (data_type ==
			     MWV207REG_NN_DATA_TYPE_FP16) ? 0x3c00 :
			    1;
			jmtUINT32 i = 0, offset = 0;

			j9_staxis(&kernels, zrl, &offset, 8);
			j9_staxis(&kernels, vznum, &offset, 16);
			j9_staxis(&kernels, value, &offset, 8 * item_size);
			j9_staxis(&kernels, bias, &offset, 32);
			if (data_type == MWV207REG_NN_DATA_TYPE_UINT16
			    || data_type == MWV207REG_NN_DATA_TYPE_INT16)
				j9_staxis(&kernels, 0, &offset, 16);

			for (i = 1; i < filterSize / item_size; i++)
				j9_staxis(&kernels, value, &offset,
					  8 * item_size);
		}

	}
OnError:
	return status;
}

static j9_duopoly j9_handle_j9min_activation(IN jmk_HARDWARE Hardware,
					     IN USC_NN_TYPE hw_type,
					     IN jmtUINT32_PTR flushCommands,
					     IN jmtUINT32 CmdAddress,
					     IN jmtUINT32 SramRemapAddress,
					     OUT jmtUINT32_PTR Bytes)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsFEATURE_DATABASE *db =
	    (jmsFEATURE_DATABASE *) (Hardware->featureDatabase);
	jmtUINT32 idx = 0, kernel_brust_size = db->J9_HANDLE__APHIDICIDE;
	jmtINT32 disableZDPN = 1, disableSWTiling = 1, smallBatch =
	    1, ddrBurstSize = 0;
	jmtBOOL enableNNStride = J9_YARELY;

	disableZDPN = (db->J9_MOOP || db->J9_DEXY) ? 0 : 1;

	enableNNStride = db->J9_SUSPENDIBILITY;
	disableSWTiling = enableNNStride ? 0 : 1;

	switch (kernel_brust_size) {
	case 256:
		ddrBurstSize = MWV207REG_CONFIG_NN_DDR_BURST_SIZE_SIZE256_B;
		break;
	case 64:
		ddrBurstSize = MWV207REG_CONFIG_NN_DDR_BURST_SIZE_SIZE64_B;
		break;
	default:
		break;
	}

	if (Hardware->identity.chipModel == 0x8000
	    && Hardware->identity.j9_exquisite == 0x7120
	    && (Hardware->identity.j9_nascent == 0x80
		|| Hardware->identity.j9_nascent == 0x92))
		smallBatch = MWV207REG_CONFIG_NN_SMALL_BATCH_ENABLE;
	else
		smallBatch = (db->J9_HANDLE_INCULPATED
			      && db->J9_HANDLE_J9MENU_ATTRIBUTE_DEMOLISHED)
		    ? MWV207REG_CONFIG_NN_SMALL_BATCH_ENABLE :
		    MWV207REG_CONFIG_NN_SMALL_BATCH_DISABLE;

	if (hw_type == USC_NN_TYPE_V6) {
		flushCommands[idx++] =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
				      LOAD_STATE)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
				   mwv207regMMUConfigRegAddrs)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
		flushCommands[idx++] = 0;

		flushCommands[idx++] =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
				      LOAD_STATE)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
				   AQFlushRegAddrs)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
		flushCommands[idx++] =
		    J9_MEGAPHONICALLY(0, AQ_FLUSH, L2_CACHE, ENABLE);
	}

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regSramRemapStartAddressRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	flushCommands[idx++] = SramRemapAddress;

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regOnChipBufferRemapStartAddressRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	flushCommands[idx++] = 0x00000000;

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regOnChipBufferRemapEndAddressRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	flushCommands[idx++] = 0x00000000;

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);
	flushCommands[idx++] = J9_MEGAPHONICALLY(0, AQ_FLUSH, L2_CACHE, ENABLE);

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regConfigNNRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

	flushCommands[idx++] =
	    J9_CRACKROPE(0, MWV207REG_CONFIG_NN, ZDPN, disableZDPN)
	    | J9_CRACKROPE(0, MWV207REG_CONFIG_NN, SW_TILING, disableSWTiling)
	    | J9_CRACKROPE(0, MWV207REG_CONFIG_NN, SMALL_BATCH, smallBatch)
	    | J9_CRACKROPE(0, MWV207REG_CONFIG_NN, DDR_BURST_SIZE, ddrBurstSize)
	    | J9_CRACKROPE(0, MWV207REG_CONFIG_NN, COMMAND_SIZE,
			   MWV207REG_CONFIG_NN_COMMAND_SIZE_SIZE128_B);

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regVipFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

	flushCommands[idx++] =
	    J9_CRACKROPE(0, MWV207REG_VIP_FLUSH, NN_FLUSH_CLIENT_ID, 0)
	    | J9_CRACKROPE(0, MWV207REG_VIP_FLUSH, NN_NO_FLUSH, 0);

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSTriggerNNRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

	flushCommands[idx++] =
	    J9_CRACKROPE(0, MWV207REG_PS_TRIGGER_NN, COMMAND_BUFFER_ADDR,
			 (CmdAddress >> 6))
	    | J9_CRACKROPE(0, MWV207REG_PS_TRIGGER_NN, COMMAND_EVENT_ID, 0);

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   mwv207regPSWaitForEventRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

	flushCommands[idx++] = 0;

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
			      LOAD_STATE)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
			   AQFlushRegAddrs)
	    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

	flushCommands[idx++] =
	    J9_MEGAPHONICALLY(0, AQ_FLUSH, SHL1_CACHE, ENABLE);

	*Bytes = idx * 4;


	return status;
}

#endif

#endif


