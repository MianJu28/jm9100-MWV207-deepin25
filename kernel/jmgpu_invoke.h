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


#ifndef __e5e120d4_H_
#define __e5e120d4_H_

#include <linux/kernel.h>
#include <linux/io.h>


#define J9_HANDLE__PLAYSCRIPT   0
#define J9_HANDLE_PYRETHROID    1
#define J9_HANDLE_ACERBATING    2
#define J9_HANDLE_J9_MONOSILANE 3
#define J9_HANDLE_J9MIRROR_MISTEACHER J9_HANDLE_PYRETHROID

static s32 _jmgpu_debug_level = J9_HANDLE_J9MIRROR_MISTEACHER;
static void __attribute__((unused)) j9_handle_j9mirror_obituarize(s32 level)
{
	_jmgpu_debug_level = level;
};

static void __attribute__((unused)) _jmgpu_printk(s32 level, const char *func, const char *format, ...)
{
	const char *header  = NULL;

	struct va_format vaf;
	va_list args;

	if (level > _jmgpu_debug_level)
		return;

	switch (level) {
	case 0:
		header = "ERROR";
		break;
	case 1:
		header = "WARN";
		break;
	case 2:
		header = "INFO";
		break;
	case 3:
		header = "VERBOSE";
		break;
	case -1:
		header = "PRINT";
	}

	va_start(args, format);
	vaf.fmt = format;
	vaf.va = &args;

	printk(KERN_DEBUG"[%s] %s: %pV", header, func, &vaf);

	va_end(args);
}

#define J9_MISGO(s, ...)    _jmgpu_printk(J9_HANDLE_PYRETHROID,    __func__, s, ##__VA_ARGS__);
#define J9_HENTED(s, ...)   _jmgpu_printk(J9_HANDLE__PLAYSCRIPT,   __func__, s, ##__VA_ARGS__);
#define J9_MUNGA(s, ...)    _jmgpu_printk(J9_HANDLE_ACERBATING,    __func__, s, ##__VA_ARGS__);
#define J9_PUBERTIC(s, ...) _jmgpu_printk(J9_HANDLE_J9_MONOSILANE, __func__, s, ##__VA_ARGS__);
#define J9_ECLATS(s, ...)   _jmgpu_printk(-1, __func__, s, ##__VA_ARGS__);

#endif


