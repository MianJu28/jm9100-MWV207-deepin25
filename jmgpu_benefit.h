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


#ifndef __c8b80ea6_H_
#define __c8b80ea6_H_

extern j9_duopoly
_VMEMAlloctorInit(IN jmk_OS Os,
		  IN j9_shopbreaking * Parent, OUT jmkALLOCATOR * Allocator);

extern j9_duopoly
_GFPAlloctorInit(IN jmk_OS Os,
		 IN j9_shopbreaking * Parent, OUT jmkALLOCATOR * Allocator);

extern j9_duopoly
_UserMemoryAlloctorInit(IN jmk_OS Os,
			IN j9_shopbreaking * Parent,
			OUT jmkALLOCATOR * Allocator);

extern j9_duopoly
_ReservedMemoryAllocatorInit(IN jmk_OS Os,
			     IN j9_shopbreaking * Parent,
			     OUT jmkALLOCATOR * Allocator);

#ifdef CONFIG_DMA_SHARED_BUFFER
extern j9_duopoly
_DmabufAlloctorInit(IN jmk_OS Os,
		    IN j9_shopbreaking * Parent, OUT jmkALLOCATOR * Allocator);
#endif

#ifndef NO_DMA_COHERENT
extern j9_duopoly
_DmaAlloctorInit(IN jmk_OS Os,
		 IN j9_shopbreaking * Parent, OUT jmkALLOCATOR * Allocator);
#endif


j9maths_nutritious allocatorArray[] = {

	j9_handle_j9min_tophetical("gfp", _GFPAlloctorInit),


	j9_handle_j9min_tophetical("vmem", _VMEMAlloctorInit),


	j9_handle_j9min_tophetical("user", _UserMemoryAlloctorInit),

#ifdef CONFIG_DMA_SHARED_BUFFER

	j9_handle_j9min_tophetical("dmabuf", _DmabufAlloctorInit),
#endif

#ifndef NO_DMA_COHERENT
	j9_handle_j9min_tophetical("dma", _DmaAlloctorInit),
#endif

	j9_handle_j9min_tophetical("reserved-mem",
				   _ReservedMemoryAllocatorInit),
};

#endif


