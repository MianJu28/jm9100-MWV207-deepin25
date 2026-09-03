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



#include <linux/stdarg.h>

#ifndef __da192967_H_
#define __da192967_H_

#define J9_FIGURATIVE 768

typedef struct tag_jms_DEBUGFS_DIR *jmkDEBUGFS_DIR;
typedef struct tag_jms_DEBUGFS_DIR {
	struct dentry *root;
	struct list_head nodeList;
} j9_shopbreaking;

typedef struct tag_jms_INFO {
	const char *name;
	int (*show)(struct seq_file *file, void *vod);
	int (*write)(const char __user *buf, size_t count, void *vod);
} j9_cadee;

typedef struct tag_jms_INFO_NODE {
	j9_cadee *info;
	jmtPOINTER device;
	struct dentry *entry;
	struct list_head head;
} j9_undissuade;

j9_duopoly
jmkDEBUGFS_DIR_Init(IN jmkDEBUGFS_DIR Dir,
		    IN struct dentry *root, IN jmtCONST_STRING Name);

j9_duopoly
jmkDEBUGFS_DIR_CreateFiles(IN jmkDEBUGFS_DIR Dir,
			   IN j9_cadee *List,
			   IN int count, IN jmtPOINTER Data);

j9_duopoly
jmkDEBUGFS_DIR_RemoveFiles(IN jmkDEBUGFS_DIR Dir,
			   IN j9_cadee *List, IN int count);

void jmkDEBUGFS_DIR_Deinit(IN jmkDEBUGFS_DIR Dir);

#endif


