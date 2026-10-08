#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
!!! 已废弃（2026-10-08）—— 本补丁是**错的**，会破坏 DDX 函数返回地址，切勿再打 !!!

原始意图
    给景嘉微专有 X 驱动 mwv207_drv.so 的"2D 上传（合成 -> 扫描缓冲）"路径
    补上缺失的 2D 引擎排空等待，用于消除视频窗口的三角/楔形错位。

为什么错（实测 + 反汇编证据）
    补丁把 0x12CB0 / 0x131FC 处的
        ldp x29, x30, [sp, #16]          ← 该函数**唯一**恢复调用者 LR 的指令
    替换成
        bl  0x10D78                      ← 写 x30 = 返回地址(0x12CB4/0x13200)

    函数尾部是 `ret`，用的是 x30。替换后 x30 已被 bl 改成 0x12CB4，
    而 0x12CB0 之后到 0x12CCC 之间**没有任何**恢复 x29/x30 的指令
    ⇒ ret 跳回 0x12CB4 ⇒ 该函数被调用即陷入循环/返回地址错乱。

    原脚本注释里"随后紧跟的原指令 ldp x29,x30,[sp,#16] 会恢复真正的 LR"
    是**错误**的：bl 就写在那条 ldp 的**位置**上，把它覆盖掉了，
    那条 ldp 已不存在（另一处 0x12CD8 的 ldp 属于 cbnz 跳转的**错误分支**）。

    后果：DDX 的 TearFree「合成→扫描缓冲」上传路径每帧都会走这段代码，
    返回地址错乱导致图形栈行为不可预测 —— 实测表现为**直通与软解都出现**
    画面斜向错位（三角形/平行四边形）。

功能上也是多余的
    内核侧 DRM_JM_GEM_XFER_RECT → j9_handle_j9ma_arecaceous() 已有
    `xfer_waits_2d_idle`（默认 30ms，见 kernel/jmgpu_garbage.c）在搬运前
    等 2D 引擎排空 ⇒ DDX 侧无需重复同步。

正确做法
    使用未打本补丁的 ABI25 修复版：
        build-cli/mwv207_drv.so.abi25.fixed3   (md5 297aee83b5db3a3bccf33ff7ac2698fc)
    部署/回退见 tools/deploy_ddx_tearfree_sync.sh（已加拦截）。

若要真正实现"上传后等 2D 空闲"，必须保留 ldp 并另找空间：
    * 不能占用 ldp 所在指令；
    * 需要 3 条以上指令（保存 x0/x1 传参、bl、恢复）或跳到函数外的
      空闲代码洞（cave）里做，且要覆盖**所有**返回路径；
    * 或直接改内核侧（已实现，推荐）。

本文件保留仅为记录与防止再被打上；脚本主体已加硬拦截。
"""


import argparse
import hashlib
import struct
import sys

# ---- 原件指纹（防止打错文件）----
EXPECT_SHA256 = "c58afa9ea948f2a2b0a8993f3b0b33abcc1bc1e45e0664fdd2331599826e6621"
EXPECT_SIZE = 140464

# ---- 允许的基线白名单 ----
# 说明：现装机上**已装**的 DDX 是"ABI25 修复版"（不是未改动的原件），
# 两个补丁点（0x12cb0 / 0x131fc）与等待函数（0x10d78）在 ABI 修复后**完全未变**，
# 因此可安全地在该版本上继续打本补丁 ⇒ 得到"ABI25 + TearFree 同步"合一版。
ABI25_SHA256 = "70d02b433d94d15ca86fa7c06ba8a2e963fd7a52c46d4709bcf96ee61830735d"

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


DISABLED_REASON = (
    "本补丁已废弃：它会覆盖函数唯一的 `ldp x29,x30,[sp,#16]`，"
    "导致 DDX 2D 上传例程 ret 返回到错误地址（实测造成直通/软解都错位）。"
    "请改用 build-cli/mwv207_drv.so.abi25.fixed3；2D 排空等待由内核 "
    "xfer_waits_2d_idle 负责。"
)


def main():
    # 硬拦截：即使有人照旧调用，也绝不写出被破坏的模块。
    print("!! 本脚本已废弃，拒绝执行。")
    print("   原因：%s" % DISABLED_REASON)
    print()
    print("   正确做法：使用 build-cli/mwv207_drv.so.abi25.fixed3")
    print("   （md5 297aee83b5db3a3bccf33ff7ac2698fc，未打本补丁的 ABI25 修复版）")
    print("   2D 排空等待由内核 xfer_waits_2d_idle 负责，无需 DDX 侧重复同步。")
    return 9

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
    known_bases = {
        EXPECT_SHA256: "未改动的原件",
        ABI25_SHA256: "ABI25 修复版（本机已装）",
    }
    if sha not in known_bases:
        print("!! SHA-256 不在已知基线内：%s" % sha)
        print("   已知基线：")
        for h, n in known_bases.items():
            print("     %s  (%s)" % (h, n))
        print("!! 已终止，避免在错误文件上打补丁。")
        return 2
    print("校验     : 基线 = %s OK" % known_bases[sha])
    if sha == ABI25_SHA256:
        print("           （在 ABI25 修复版上打本补丁 ⇒ 产出\"ABI25 + TearFree 同步\"合一版）")

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
