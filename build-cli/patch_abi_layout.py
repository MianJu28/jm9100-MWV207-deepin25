#!/usr/bin/env python3
"""mwv207_drv.so ABI24(deepin-1.20.4)→21.1 布局适配补丁  v2
规则：仅 **ScrnInfoRec**(pScrn) 的 post-fbOffset 访问偏移 −8。
      ScrnInfoRec 差异：21.1 删除 Bool flipPixels(xf86str.h 643d644) → 其后字段整体 −8。
      ScreenRec(scrnintstr.h) 两版仅注释/改名，布局完全相同 ⇒ **pScreen 访问不得改动**。
      例: 0x6ab0/0x6adc 的 [x19,#984] 中 x19=arg0 且经 xf86ScreenToScrn 转换 ⇒ pScreen, 必须保持 984。
"""
import struct, shutil, sys

SRC = "/home/admin/Desktop/Git/jm9100/build-cli/mwv207_drv.so.abi25"
DST = "/home/admin/Desktop/Git/jm9100/build-cli/mwv207_drv.so.abi25.fixed2"
TEXT_VMA, TEXT_OFF = 25488, 25488

# (vaddr, 类型, 期望旧立即数[字节]，一律 −8)
SITES = [
    # 回调安装块（x2/x3 = pScrn+512）
    (0x6470, "stp64", 440), (0x6478, "stp64", 456),
    (0x6480, "stp64", 472), (0x648c, "stp64", 488),
    (0x6494, "str64", 1016),           # ValidMode
    # 注意: 0x6ab0 / 0x6adc ([x19,#984]) 与 0x6810/0x6824 ([x20,#960]) 均为 pScreen,
    #       偏移正确, 不补丁（v1 曾误改 0x6ab0/0x6adc 导致 libexa 崩溃）
    # vtSema（32位）
    (0x6834, "ldr32", 904), (0x7110, "ldr32", 904),
    (0x6f48, "str32", 904), (0x7fa0, "str32", 904), (0x8360, "str32", 904),
    (0x185ac, "ldr32", 904), (0x186f8, "ldr32", 904),
    # options / is_gpu / capabilities（32位）
    (0x7558, "ldr64", 896),            # options → xf86ProcessOptions
    (0x7be4, "ldr32", 928),            # is_gpu
    (0x76e8, "str32", 932), (0x7708, "ldr32", 932), (0x7714, "str32", 932),
    (0x771c, "ldr32", 932), (0x7728, "str32", 932), (0x773c, "str32", 932),
    # deepin 扩展钩子
    (0x7c48, "str64", 880), (0x16d08, "ldr64", 888), (0x16d14, "str64", 888),
]

data = bytearray(open(SRC, "rb").read())

for vaddr, kind, old_bytes in SITES:
    fo = TEXT_OFF + (vaddr - TEXT_VMA)
    w = struct.unpack_from("<I", data, fo)[0]
    if kind in ("str64", "ldr64"):
        assert (w >> 30) == 3 and ((w >> 10) & 0xFFF) * 8 == old_bytes, \
            f"0x{vaddr:x}: 期望64位偏移{old_bytes}, 实际{w:08x}"
        new = w - (1 << 10)          # imm12 −1 (×8)
    elif kind in ("str32", "ldr32"):
        assert (w >> 30) == 2 and ((w >> 10) & 0xFFF) * 4 == old_bytes, \
            f"0x{vaddr:x}: 期望32位偏移{old_bytes}, 实际{w:08x}"
        new = w - (2 << 10)          # imm12 −2 (×4)
    elif kind == "stp64":
        assert ((w >> 27) & 7) == 5 and ((w >> 30) & 3) == 2, f"0x{vaddr:x} 非STP64"
        imm7 = (w >> 15) & 0x7F
        if imm7 & 0x40: imm7 -= 128
        assert imm7 * 8 == old_bytes, f"0x{vaddr:x}: 期望STP偏移{old_bytes}, 实际{imm7*8}"
        new = w - (1 << 15)          # imm7 −1 (×8)
    struct.pack_into("<I", data, fo, new)
    print(f"0x{vaddr:x}: {w:08x} -> {new:08x}  ({kind} {old_bytes} -> {old_bytes-8})")

open(DST, "wb").write(bytes(data))
print(f"\n已写入 {DST}")

# ---------- fixed3: 额外禁用 deepin 钩子安装 ----------
# 0x16d14 原为 "str x2, [x19, #888]"（安装窗口包装器到 deepin 钩子槽）。
# 该槽在 deepin-21.1 的语义是 "屏幕钩子"(以 pScreen 为第一参数), 与厂商的
# 窗口/绘图包装器签名不符, 会导致 xf86ScreenToScrn(NULL) 崩溃。
# 该钩子为可选特性(server 遇 NULL 跳过, modesetting 亦不安装), 故直接 NOP 该安装。
DST3 = "/home/admin/Desktop/Git/jm9100/build-cli/mwv207_drv.so.abi25.fixed3"
NOP = 0xD503201F
TARGETS = [(0x16d14, "禁用 deepin 钩子安装(str x2,[x19,#888]→NOP)")]
for vaddr, desc in TARGETS:
	fo = TEXT_OFF + (vaddr - TEXT_VMA)
	w = struct.unpack_from("<I", data, fo)[0]
	assert (w >> 30) == 3 and (((w >> 10) & 0xFFF) * 8) in (880, 888), \
		f"0x{vaddr:x}: 非预期指令 {w:08x}"
	struct.pack_into("<I", data, fo, NOP)
	print(f"0x{vaddr:x}: {w:08x} -> {NOP:08x}  ({desc})")
open(DST3, "wb").write(bytes(data))
print(f"已写入 {DST3}")
