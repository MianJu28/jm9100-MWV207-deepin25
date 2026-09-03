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


#ifdef MODULE
#include <linux/module.h>
#endif
#include <linux/init.h>
#include <linux/debugfs.h>
#include <linux/slab.h>
#ifdef MODVERSIONS
#include <linux/modversions.h>
#endif
#include <linux/stddef.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/vmalloc.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <asm/uaccess.h>
#include <linux/completion.h>
#include <linux/seq_file.h>
#include "jmgpu_through.h"
#include "jmgpu_detect.h"
#include "jmgpu_location.h"

#define J9_ACESODYNE    J9_UNTHEOLOGIZE

static int j9_organography(struct inode *inode, struct file *file)
{
	j9_undissuade *node = inode->i_private;

	return single_open(file, node->info->show, node);
}

static ssize_t
j9_overweeningly(struct file *file,
		 const char __user *buf, size_t count, loff_t *pos)
{
	struct seq_file *s = file->private_data;
	j9_undissuade *node = s->private;
	j9_cadee *info = node->info;

	if (info->write) {
		info->write(buf, count, node);
	}

	return count;
}

static const struct file_operations jm_debugfs_operations = {
	.owner = THIS_MODULE,
	.open = j9_organography,
	.write = j9_overweeningly,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

j9_duopoly
jmkDEBUGFS_DIR_Init(IN jmkDEBUGFS_DIR Dir,
		    IN struct dentry *root, IN jmtCONST_STRING Name)
{
	Dir->root = debugfs_create_dir(Name, root);

	if (!Dir->root) {
		return J9_HANDLE_J9M_UNFEMINISE;
	}

	INIT_LIST_HEAD(&Dir->nodeList);

	return J9_FLUTTERING;
}

j9_duopoly
jmkDEBUGFS_DIR_CreateFiles(IN jmkDEBUGFS_DIR Dir,
			   IN j9_cadee *List, IN int count, IN jmtPOINTER Data)
{
	int i;
	j9_undissuade *node;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Dir=%p List=%p count=%d Data=%p", Dir, List, count,
			Data);

	for (i = 0; i < count; i++) {
		umode_t mode = 0;


		node =
		    (j9_undissuade *) kzalloc(sizeof(j9_undissuade),
					      GFP_KERNEL);

		node->info = &List[i];
		node->device = Data;

		mode |= List[i].show ? S_IRUGO : 0;
		mode |= List[i].write ? S_IWUSR : 0;


		node->entry =
		    debugfs_create_file(List[i].name, mode, Dir->root, node,
					&jm_debugfs_operations);

		if (!node->entry) {
			j9_recaution(J9_HANDLE_J9M_FORGATHERS);
		}

		list_add(&(node->head), &(Dir->nodeList));
	}

OnError:
	if (J9_CATAPHORA(status)) {
		j9_palladinize(jmkDEBUGFS_DIR_RemoveFiles(Dir, List, count));
	}
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkDEBUGFS_DIR_RemoveFiles(IN jmkDEBUGFS_DIR Dir,
			   IN j9_cadee *List, IN int count)
{
	int i;
	j9_undissuade *node;
	j9_undissuade *temp;

	j9_tympanichord("Dir=%p List=%p count=%d", Dir, List, count);

	for (i = 0; i < count; i++) {
		list_for_each_entry_safe(node, temp, &Dir->nodeList, head) {
			if (node->info == &List[i]) {
				debugfs_remove(node->entry);
				list_del(&node->head);
				kfree(node);
			}
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

void jmkDEBUGFS_DIR_Deinit(IN jmkDEBUGFS_DIR Dir)
{
	if (Dir->root != NULL) {
		debugfs_remove(Dir->root);
		Dir->root = NULL;
	}
}


