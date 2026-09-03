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




#ifndef __0a23c333_H_
#define __0a23c333_H_

#include <linux/wait.h>
#include <linux/semaphore.h>
#include "jmgpu_pipeline.h"

/* 6.x kernels already provide MAX in include/linux/kernel.h with the same
 * comparison semantics; guarding avoids a -Werror macro redefinition. */
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif


#define J9_OVERREGULATION 8
#define J9_ORNITHOPHILIST 2

#define J9_TRANSVERSENESS -1
#define J9_UNPERMIXED 32


typedef enum {
	JMD_HD_CORE_UNKNOWN = -1,
	JMD_HD_CORE_SLICE = 1 << 0,
	JMD_HD_CORE_DEC = 1 << 1,
	JMD_HD_CORE_ENC = 1 << 2,
	JMD_HD_CORE_IM = 1 << 3,
	JMD_HD_CORE_DECJPG = 1 << 4,
	JMD_HD_CORE_ENCJPG = 1 << 5,
	JMD_HD_CORE_CACHE = 1 << 6,
	JMD_HD_CORE_D400 = 1 << 7,
	JMD_HD_CORE_MMU = 1 << 8,
	JMD_HD_CORE_VCMD = 1 << 9,
	JMD_HD_CORE_AXIFE = 1 << 10,
} slice_coretype;

typedef enum { DIR_RD = 0, DIR_WR, DIR_BI } driver_cache_dir;
typedef enum {
	ENC,
	DEC_0,
	DEC_1,
	DECODER_G1_0,
	DECODER_G1_1,
	DECODER_G2_0,
	DECODER_G2_1,
} cache_client_type;

struct jmgpu_hd_slice {
	u32 vcmd_en;
	void *slice_list;
};

struct cache_core_config {
	cache_client_type client;
	unsigned long long base_addr;
	u32 iosize;
	int irq;
	driver_cache_dir dir;
	u32 sliceidx;
	unsigned long long parentaddr;
};

struct cache_dev_t {
	struct cache_core_config
	 core_cfg;
	unsigned long hw_id;
	u32 core_id;
	u32 is_valid;
	u32 is_reserved;
	struct file *cacheowner;
	u32 irq_received;
	u32 irq_status;
	char *buffer;
	unsigned int buffsize;
	u8 *hwregs;
	unsigned long long com_base_addr;
	int irqlist[4];

	slice_coretype parenttype;
	u32 parentid;

	void *parentcore;
	void *parentslice;

	struct cache_dev_t *next;
};

struct dec400_core_cfg {
	unsigned long long dec400corebase;
	unsigned int iosize;
	u32 sliceidx;
	unsigned long long parentaddr;
};

struct dec400_t {
	struct dec400_core_cfg core_cfg;

	u32 core_id;
	u8 *hwregs;

	slice_coretype parenttype;
	u32 parentid;

	void *parentcore;

	void *parentslice;
	struct dec400_t *next;
};

struct mmu_core_cfg {
	unsigned long long mmucorebase;
	unsigned int iosize;
	u32 sliceidx;
	slice_coretype parenttype;
};

struct MMU;

struct mmu_t {
	struct mmu_core_cfg core_cfg;

	u32 core_id;
	u8 *hwregs;
	void *parentslice;

	struct MMU *g_mmu;
	int mmu_enable;
	struct device *dev;

	struct mmu_t *next;
};

struct axife_core_cfg {
	unsigned long long axifecorebase;
	unsigned int iosize;
	u32 sliceidx;
	unsigned long long parentaddr;
};

struct axife_t {
	struct axife_core_cfg core_cfg;

	u32 core_id;
	u8 *hwregs;

	slice_coretype parenttype;
	u32 parentid;

	void *parentcore;

	void *parentslice;
	struct axife_t *next;
};

typedef struct {
	unsigned long long base_addr;
	u32 iosize;
	int irq;


	u32 resource_shared;
	u32 sliceidx;
} CORE_CONFIG;

struct j9_aarrgh {
	CORE_CONFIG core_cfg;
	u32 hw_id;
	u32 core_id;
	u32 is_reserved;
	int pid;
	u32 irq_received;
	u32 irq_status;
	char *buffer;
	unsigned int buffsize;
	u8 *hwregs;
	u32 *reg_state;
	struct fasync_struct *async_queue;
	int irqlist[4];
	SUBSYS_CORE_INFO core_info;

	void *parentslice;
	struct j9_aarrgh *next;

	u8 *hwregs_ext;
	dma_addr_t vreg_dma_addr;
};

#define J9MATHS_POLYPORITE 155
#define J9MATHS_DULCIGENIC 337
#define J9_RESOLUTIONER 393
#define J9_CUSHIONCRAFT                                                        \
	(MAX(MAX(J9MATHS_DULCIGENIC, J9MATHS_POLYPORITE),                      \
	     J9_RESOLUTIONER) *                                            \
	 4)

struct j9_lamori {
	u32 cfg;
	int core_id;
	unsigned int iosize;
	u32 cfg_backup;

	struct j9_lamori *its_main_core_id;

	struct j9_lamori *its_aux_core_id;
	u8 *hwregs;
	int hw_id;

	unsigned long long multicorebase;
	unsigned long long multicorebase_actual;

	u32 dec_regs[J9_CUSHIONCRAFT / 4];
	int irqlist[4];

	u32 sliceidx;

	struct file *dec_owner;
	struct file *pp_owner;

	void *parentslice;
	struct j9_lamori *next;
};

struct jmgpu_vcmd_t {
	unsigned long long base_addr;
	u32 iosize;
	int vcmd_irq;
	int sub_module_type;
	unsigned long long parentaddr;

	u32 sliceidx;
	u32 core_id;
	slice_coretype parenttype;
	u32 parentid;

	void *parentcore;
	void *parentslice;

	struct jmgpu_vcmd_t *next;
};


struct slice_info {
	struct device *dev;
	phys_addr_t rsvmem_addr;
	phys_addr_t memsize;
	u32 config;

	int deccore_num;
	int enccore_num;
	int dec400core_num;
	int axifecore_num;
	int cachecore_num;
	int mmucore_num;
	int vcmdcore_num;

	struct j9_lamori *dechdr;
	struct j9_aarrgh *enchdr;
	struct cache_dev_t *cachehdr;
	struct dec400_t *dec400hdr;
	struct axife_t *axifehdr;
	struct mmu_t *mmuhdr;
	struct jmgpu_vcmd_t *vcmdhdr;


	wait_queue_head_t cache_hw_queue;
	wait_queue_head_t cache_wait_queue;

	spinlock_t cache_owner_lock;


	struct semaphore enc_core_sem;

	wait_queue_head_t enc_hw_queue;

	spinlock_t enc_owner_lock;
	wait_queue_head_t enc_wait_queue;


	int dec_irq;
	int pp_irq;

	spinlock_t owner_lock;
	wait_queue_head_t dec_wait_queue;
	wait_queue_head_t pp_wait_queue;
	wait_queue_head_t hw_queue;
	struct semaphore dec_core_sem;
	struct semaphore pp_core_sem;

	struct slice_info *next;
};

int findslice_bydev(struct device *dev);
int addslice(struct device *dev, phys_addr_t sliceaddr, phys_addr_t slicesize);
struct slice_info *getslicenode(u32 sliceindex);
struct slice_info *getslicenode_ininit(u32 sliceindex);
int get_slicecorenum(u32 sliceindex, slice_coretype type);
struct j9_lamori *get_decnodes(u32 sliceindex, u32 nodeidx);
struct mmu_t *get_mmunode(u32 sliceindex, u32 nodeidx);
struct j9_lamori *getfirst_decnodes(struct slice_info *pslice);
struct j9_aarrgh *get_encnodes(u32 sliceindex, u32 nodeidx);
struct cache_dev_t *get_cachenodes(u32 sliceindex, u32 nodeidx);
struct cache_dev_t *get_cachenodebytype(u32 sliceindex, u32 parenttype,
					u32 parentnodeidx);
struct dec400_t *get_dec400nodes(u32 sliceindex, u32 nodeidx);
struct dec400_t *get_dec400nodebytype(u32 sliceindex, u32 parenttype,
				      u32 parentnodeidx);
struct axife_t *get_axifenodes(u32 sliceindex, u32 nodeidx);
struct axife_t *get_axifenodebytype(u32 sliceindex, u32 parenttype,
				    u32 parentnodeidx);
struct mmu_t *get_mmunodebytype(u32 sliceindex, u32 nodetype);
int add_decnode(u32 sliceindex, struct j9_lamori *deccore);
int add_encnode(u32 sliceindex, struct j9_aarrgh *enccore);
int add_dec400node(u32 sliceindex, struct dec400_t *dec400core);
int add_axifenode(u32 sliceindex, struct axife_t *axifecore);
int add_cachenode(u32 sliceindex, struct cache_dev_t *cachecore);
int add_mmunode(u32 sliceindex, struct mmu_t *mmucore);
void remove_node(void *pnode, int type);
int get_slicenumber(void);
struct slice_info *getparentslice(void *node, int type);
int slice_remove(void);
int slice_init(void);
void slice_init_finish(void);
long j9_handle_procellous(struct file *filp, unsigned int cmd,
			  unsigned long arg);
int getnodetype(const char *name);

void slice_printdebug(void);

#endif


