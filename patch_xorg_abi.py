#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
patch_xorg_abi.py -- 把景嘉微专有 X 驱动 mwv207_drv.so 的 DDx ABI 版本
                     从 24.0 补到 25.0，使其能被 Xorg 1.21.1.16 加载。

背景（VENDOR_FEEDBACK_PRESENTATION.md §2/§6.1、README §3.7/§3.8）
    专有 X 驱动按 ABI_VIDEODRV_VERSION 24 编译，而 Deepin 25 的
    Xorg 1.21.1.16 要求 25，于是加载失败、服务器回落 modeset(0)+软件 GLX，
    DRI3 呈现路径与扫描输出之间无 vblank 同步 → 视频窗口出现带状/三角状错位斑块。
    本脚本只改 `XF86ModuleVersionInfo.abiversion` 这一个字段（24.0 -> 25.0）。

模块结构（实测，未 strip 的符号地址 + .data 映射 vaddr-0x10000）
    mwv207ModuleData      @ .data 0x317b8   { VersionInfo*, SetupProc, TearDown }
    XF86ModuleVersionInfo @ .data 0x317d0
        +0   modname       -> "mwv207"
        +8   vendor        -> "X.Org Foundation"
        +16  _modinfo/major/minor/patch（4×u32）
        +32  abiclass      -> "X.Org Video Driver"
        +40  abiversion    = 0x00180000  (24<<16)
        +44  pad
        +48  moduleclass   -> "X.Org Video Driver"
        +56  checksum      = 0
    ABI 编码：major<<16 | minor（加载器按 (值>>16) 打印"major version"）。

用法
    python3 patch_xorg_abi.py <输入模块> <输出模块> [--abi 25]
    python3 patch_xorg_abi.py /usr/lib/xorg/modules/drivers/mwv207_drv.so \
                             build-cli/mwv207_drv.so.abi25

注意
    * 只改 4 字节；原始模块保持不动（务必对副本操作）。
    * ABI 24 -> 25 之间 DDX 有真实变化，补丁只解决"加载"，运行期是否稳定
      必须以实际 X 会话验证为准（先在可回滚环境试）。
    * 回滚：还原原模块，删除对应的 xorg.conf.d 片段，重启 lightdm。
"""
import struct
import sys

MODULE_DATA_VA = 0x317B8          # mwv207ModuleData（.data）
DATA_VA_BASE = 0x30A98            # 从该虚地址起，file offset = vaddr - 0x10000
DELTA = 0x10000

ABI_CLASSES = (b"ABI_CLASS_VIDEODRV",)  # 仅用于人工核对


def off(va):
    """虚地址 -> 文件偏移。"""
    if va >= DATA_VA_BASE:
        return va - DELTA
    return va


def cstr(d, va):
    o = off(va)
    if o < 0 or o >= len(d):
        return None
    e = d.find(b"\x00", o)
    if e < 0:
        return None
    return d[o:e].decode("utf-8", "replace")


def encode_abi(major, minor=0):
    return (major << 16) | (minor & 0xFFFF)


def main(argv):
    if len(argv) < 3:
        print(__doc__)
        return 2
    src, dst = argv[1], argv[2]
    major = 25
    if "--abi" in argv:
        major = int(argv[argv.index("--abi") + 1])

    d = bytearray(open(src, "rb").read())

    md_off = off(MODULE_DATA_VA)
    verinfo, setup, teardown = struct.unpack_from("<QQQ", d, md_off)
    vi_off = off(verinfo)
    if vi_off < 0 or vi_off + 64 > len(d):
        print("错误: VersionInfo 指针异常 0x%x（文件偏移 0x%x 越界）"
              % (verinfo, vi_off))
        return 1
    modname_ptr = struct.unpack_from("<Q", d, vi_off)[0]
    if cstr(d, modname_ptr) != "mwv207":
        print("错误: VersionInfo->modname 不是 'mwv207'（结构偏移可能变了），中止")
        return 1
    print("XF86ModuleData  @0x%x  SetupProc=0x%x TearDown=0x%x"
          % (MODULE_DATA_VA, setup, teardown))

    vo = vi_off
    name = cstr(d, modname_ptr)
    vendor = cstr(d, struct.unpack_from("<Q", d, vo + 8)[0])
    abiclass = cstr(d, struct.unpack_from("<Q", d, vo + 32)[0])
    moduleclass = cstr(d, struct.unpack_from("<Q", d, vo + 48)[0])
    print("VersionInfo     @0x%x" % verinfo)
    print("  modname     = %s" % name)
    print("  vendor      = %s" % vendor)
    print("  abiclass    = %s" % abiclass)
    print("  moduleclass = %s" % moduleclass)
    if abiclass != "X.Org Video Driver":
        print("错误: abiclass 不是 Video Driver，字段偏移可能变了，中止")
        return 1

    abi_off = vo + 40
    old = struct.unpack_from("<I", d, abi_off)[0]
    print("  abiversion  @+40 = 0x%08x  (ABI %d.%d)"
          % (old, old >> 16, old & 0xFFFF))

    new = encode_abi(major, 0)
    if old == new:
        print("无需修改：模块已是 ABI %d.0" % major)
        return 0

    struct.pack_into("<I", d, abi_off, new)
    open(dst, "wb").write(bytes(d))
    print("\n补丁: %d.%d -> %d.0  （文件偏移 0x%x: 0x%08x -> 0x%08x）"
          % (old >> 16, old & 0xFFFF, major, abi_off, old, new))
    print("已写出: %s" % dst)

    # 自检：重读确认
    d2 = open(dst, "rb").read()
    got = struct.unpack_from("<I", d2, abi_off)[0]
    if got != new:
        print("错误: 自检失败")
        return 1
    print("自检通过: 0x%08x (ABI %d.%d)" % (got, got >> 16, got & 0xFFFF))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
