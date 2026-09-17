#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
patch_ddx_tearfree_sync.py
    给景嘉微专有 X 驱动 mwv207_drv.so 的 "2D 上传（合成 -> 扫描缓冲）" 路径
    补上缺失的 **2D 引擎排空等待**，用于消除视频窗口的三角/楔形错位。

背景
    README.md §12/§13：视频窗口内出现"三角/楔形错位 + 重复之前片段"。
    A/B 已定位（§12.7）：`Option "TearFree" "off"` 后三角错位明显减少 ⇒
    主因在 DDX 的"合成 -> 扫描缓冲"拷贝路径：该拷贝经
    `drm_jmgpu_bo_xfer_to_dev()`（内核 DRM_JM_GEM_XFER_RECT，2D 引擎作业）
    提交后**立即返回**，没有任何"等作业完成"的动作 ⇒ 显示控制器可能在
    2D 引擎写完之前就扫到该缓冲 ⇒ 按行错切（三角）。

反编译证据（BuildID 912c7bd4bf721ea7c5b6ca44690b0c596500e6bf，sha256 c58afa9e…）
    上传例程 1（成功路径）：
        0x12ca4:  bl drm_jmgpu_bo_xfer_to_dev@plt
        0x12ca8:  mov w5, w0
        0x12cac:  cbnz w0, 0x12d54
        0x12cb0:  ldp x29, x30, [sp, #16]   <-- 直接恢复栈返回，无同步
        ...
        0x12ccc:  ret
    上传例程 2：同样结构（0x131f0 bl xfer → 0x131f8 cbnz → 0x131fc ldp → 0x13214 ret）

    驱动里**已存在**"等 2D 空闲"的封装函数，却**从未被调用**（全库 0 处引用）：
        0x10d78:  stp x29,x30,[sp,#-16]! ; mov x29,sp
                  bl  xf86ScreenToScrn@plt
                  ldr x0,[x0,#280] ; ldr x0,[x0,#176] ; ldr w0,[x0,#4]
                  b   drm_jmgpu_j2d_wait_idle@plt      <-- 尾调用，无返回值依赖

补丁（2 处、各 1 条指令，**无需跳板**）
    0x12cb0:  ldp x29, x30, [sp, #16]   ->   bl 0x10d78
    0x131fc:  ldp x29, x30, [sp, #16]   ->   bl 0x10d78

    为什么正确：
      * `bl` 把返回地址写入 x30(=LR)，随后紧跟的原指令
        `ldp x29,x30,[sp,#16]` 会从栈中恢复**真正的** LR ⇒ 返回地址不受影响；
      * `0x10d78` 内部若保存/恢复 x29,x30，返回时二者不变 ⇒ 原逻辑不变；
      * `0x12cb0` 有 3 处跳转指向它（0x12c10 b.eq / 0x12d7c b.le / 0x12db4 b），
        `0x131fc` 有 1 处（0x132a4 b.le）⇒ **所有返回路径都会经过等待**，无遗漏。

风险与回滚
    * 只对**副本**操作（脚本不修改输入文件）；
    * `drm_jmgpu_j2d_wait_idle` 内核侧有超时参数（此封装取自 device 内的值），
      **不会永久阻塞**；
    * 副作用：每次"合成->扫描"多一次 2D 排空等待 ⇒ 呈现延迟略增（换取正确性）；
    * 回滚：用原件覆盖回去 + 重启 lightdm。

用法
    python3 tools/patch_ddx_tearfree_sync.py <原件> <输出> [--check]

    python3 tools/patch_ddx_tearfree_sync.py \\
        /persistent/home/admin/jm9100-xdrv-backup/mwv207_drv.so.orig \\
        build-cli/mwv207_drv.so.tearfree-sync
"""

import argparse
import hashlib
import struct
import sys

# ---- 原件指纹（防止打错文件）----
EXPECT_SHA256 = "c58afa9ea948f2a2b0a8993f3b0b33abcc1bc1e45e0664fdd2331599826e6621"
EXPECT_SIZE = 140464

# ---- 地址（本 ELF 首个 PT_LOAD 的 p_offset == p_vaddr ⇒ 文件偏移 == vaddr）----
WAIT_IDLE_FN = 0x10D78          # 现成的"等 2D 空闲"封装（0 引用）
PATCH_SITES = (0x12CB0, 0x131FC)  # ldp x29,x30,[sp,#16] -> bl WAIT_IDLE_FN

EXP_LDP_X29X30 = 0xA9417BFD     # ldp x29, x30, [sp, #16]
# 仅忽略 Rt2（bit 14:10）后逐位比较；Rt（bit 4:0）固定为 x29
LDP_RT2_MASK = 0xFFFFFFFF & ~(0x1F << 10)


def asm_bl(from_addr, to_addr):
    """AArch64 `bl`：opcode 100101 | imm26"""
    imm = (to_addr - from_addr) >> 2
    if not (-(1 << 25) <= imm < (1 << 25)):
        raise ValueError("bl 超出 ±128MB: 0x%x -> 0x%x" % (from_addr, to_addr))
    return 0x94000000 | (imm & 0x03FFFFFF)


def rd32(buf, addr):
    return struct.unpack_from("<I", buf, addr)[0]


def wr32(buf, addr, val):
    struct.pack_into("<I", buf, addr, val)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src", help="输入的 mwv207_drv.so（原件）")
    ap.add_argument("dst", nargs="?", help="输出模块（副本）")
    ap.add_argument("--check", action="store_true", help="只校验，不写出")
    args = ap.parse_args()

    data = bytearray(open(args.src, "rb").read())
    sha = hashlib.sha256(data).hexdigest()

    print("输入文件 : %s" % args.src)
    print("大小     : %d 字节" % len(data))
    print("SHA-256  : %s" % sha)
    if sha != EXPECT_SHA256:
        print("!! 警告：SHA-256 与预期原件不符（预期 %s）" % EXPECT_SHA256)
        if not args.check:
            print("!! 已终止，避免在错误文件上打补丁。")
            return 2
    else:
        print("校验     : 与原件 SHA-256 一致 OK")

    # 校验两个插入点都是期望的 ldp
    ok = True
    for a in PATCH_SITES:
        w = rd32(data, a)
        good = (w & LDP_RT2_MASK) == (EXP_LDP_X29X30 & LDP_RT2_MASK)
        if not good:
            ok = False
        print("  [%s] 0x%x 原指令 0x%08x  %s"
              % ("OK " if good else "!! 不是期望的 ldp", a, w, "ldp x29, x30, [sp, #16]"))
    if not ok:
        print("!! 校验失败：插入点与预期不符，已终止。")
        return 3

    # 确认目标函数地址处的指令形态（stp x29,x30,[sp,#-16]!）
    w = rd32(data, WAIT_IDLE_FN)
    if (w & LDP_RT2_MASK) != (0xA9BF7BFD & LDP_RT2_MASK):
        print("!! 警告：0x%x 处不是 stp x29,x30,[sp,#-16]!（实际 0x%08x）" % (WAIT_IDLE_FN, w))
    else:
        print("  0x%x 处为 stp x29,x30,[sp,#-16]! ✓（等 2D 空闲封装）" % WAIT_IDLE_FN)

    if args.check:
        print("\n--check：仅校验，未写出任何文件。")
        return 0

    if not args.dst:
        print("!! 未指定输出文件。")
        return 1

    for a in PATCH_SITES:
        wr32(data, a, asm_bl(a, WAIT_IDLE_FN))

    open(args.dst, "wb").write(data)
    print("\n已写出 : %s" % args.dst)
    for a in PATCH_SITES:
        print("  - 0x%x: ldp x29,x30,[sp,#16] -> bl 0x%x" % (a, WAIT_IDLE_FN))
    print("共 2 处、8 字节改动。回滚：用原件覆盖 + 重启 lightdm。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
