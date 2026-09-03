#!/usr/bin/env python3
"""从景美 mwv207_gpu.patch 提取 drivers/gpu/drm/mwv207/ 新增文件为独立驱动树。
补丁是 git 格式: 每个新文件 diff 为 /dev/null -> +内容(b/xxx)。
用法: python3 extract_patch.py <patch> <outdir>
"""
import os, sys, re

patch, outdir = sys.argv[1], sys.argv[2]
os.makedirs(outdir, exist_ok=True)

cur_path = None
cur_lines = []
in_block = False

def flush():
    global cur_lines, cur_path
    if cur_path and cur_lines:
        # cur_lines 含 '+' 或上下文; 新增文件全是 '+'
        content = []
        for ln in cur_lines:
            if ln.startswith('+'):
                content.append(ln[1:])
            elif ln.startswith(' '):  # 不应出现(新增文件), 保守保留
                content.append(ln[1:])
        full = os.path.join(outdir, cur_path)
        os.makedirs(os.path.dirname(full), exist_ok=True)
        with open(full, 'w') as f:
            f.write(''.join(content))
        print(f"  {cur_path} ({len(content)} lines)")
    cur_path, cur_lines = None, []

with open(patch, encoding='utf-8', errors='replace') as f:
    for line in f:
        m = re.match(r'diff --git a/(\S+) b/(\S+)', line)
        if m:
            flush()
            # 只提取 mwv207 驱动目录, 跳过 drm/Kconfig 等框架修改
            apath = m.group(1)
            if apath.startswith('drivers/gpu/drm/mwv207/') and not apath.endswith(('.bak.c',)):
                cur_path = apath.replace('drivers/gpu/drm/mwv207/', '', 1)
                # 跳过二进制
            else:
                cur_path = None
            in_block = True
            continue
        if cur_path is None:
            continue
        # 判断是否为新增文件 diff (/dev/null 源)
        if line.startswith('--- /dev/null'):
            pass
        if line.startswith('+++ b/'):
            continue
        if re.match(r'^@@ ', line):
            cur_lines = []
            continue
        if cur_path:
            cur_lines.append(line)
flush()
print("提取完成")
