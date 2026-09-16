#!/usr/bin/env python3
"""
patch_gl_storage.py - 给景美闭源用户态栈打上原生 GL_EXT_EGL_image_storage 支持

背景（见 README §3.6 / §3.8 / §4.4）：
  * `jmgpu_dri.so` 只实现并声明 `GL_OES_EGL_image`
    （`glEGLImageTargetTexture2DOES` 真能用）；
  * `GL_EXT_EGL_image_storage` 既不声明、`glEGLImageTargetTexStorageEXT`
    也不实现 —— glvnd 用一个分发桩顶上，调用后纹理恒为全零（"绿屏"）。
  * 之前只能靠 LD_PRELOAD 兼容层（`jm_gl_compat.c`）从客户端侧兜底。

本脚本在二进制层面补上这两点，等价于厂商应做的修复：

  [扩展广告] `jmgpu_dri.so`
     把已广告、且与 ARB 版重复的 `GL_EXT_texture_rectangle`（24 字符）
     原地替换为 `GL_EXT_EGL_image_storage`（24 字符，等长）。
     等长替换 ⇒ 扩展串总长不变，无缓冲区溢出风险；
     `__glExtension` 表项与其 profile flags 完全不动，因此必然被广告。

  [入口解析] `libGLX_mwv207.so.1.2.0`
     `glXGetProcAddressARB()` 会先查一张 `{name, func}` 别名表
     （`glExtApiAliasTbl`，16 字节记录，NULL 名结尾）。
     该表 65 条之后只剩 16 字节空槽（不够一条记录 + 终止符），因此
     牺牲一条早已废弃的 SGIX 视频通道别名 `glXQueryChannelDeltasSGIX`：
       - 它的名字字符串槽位有 31 字节容量 ⇒ 原地改写成新名字；
       - 它的 func 相对重定位 addend 改指本库自带的
         `glEGLImageTargetTexture2DOES`（glapi 分发桩，与 OES 路径同一实现）。
     这样 `glXGetProcAddress("glEGLImageTargetTexStorageEXT")` 就会拿到
     真实的 OES 实现，glvnd 会把它装进 dispatch 槽 ⇒ 原生可用。

两个替换都只改字节，不新增 / 移动任何节、不增删重定位，可完全回退。

用法：
    python3 tools/patch_gl_storage.py \
        --dri   /usr/lib/aarch64-linux-gnu/dri/jmgpu_dri.so \
        --glx   /usr/lib/aarch64-linux-gnu/mwv207/libGLX_mwv207.so.1.2.0 \
        --outdir build-cli
"""
import argparse
import os
import struct
import subprocess
import sys

# ---------------------------------------------------------------- ELF helpers


class Elf:
    def __init__(self, path):
        self.path = path
        self.d = bytearray(open(path, "rb").read())
        self.size = len(self.d)
        self.sections = {}
        self.loads = []
        out = subprocess.run(["readelf", "-SW", path], capture_output=True,
                             text=True).stdout
        for line in out.splitlines():
            p = line.split()
            if p[:1] == ["["]:
                p = p[1:]
            if len(p) > 5 and p[1].startswith("."):
                try:
                    self.sections[p[1]] = (int(p[3], 16), int(p[4], 16),
                                           int(p[5], 16))
                except ValueError:
                    pass
        out = subprocess.run(["readelf", "-lW", path], capture_output=True,
                             text=True).stdout
        for line in out.splitlines():
            p = line.split()
            if p[:1] == ["LOAD"]:
                self.loads.append((int(p[1], 16), int(p[2], 16), int(p[4], 16)))
        self.relocs = {}          # r_offset -> list[(type, sym_index, addend)]
        rva, roff, rsz = self.sections[".rela.dyn"]
        for i in range(0, rsz, 24):
            r_off, r_info, r_add = struct.unpack_from("<QQq", self.d, roff + i)
            self.relocs.setdefault(r_off, []).append(
                (r_info & 0xFFFFFFFF, r_info >> 32, r_add))
        self.reloc_addend_users = {}
        for off, lst in self.relocs.items():
            for (rt, rsym, radd) in lst:
                self.reloc_addend_users.setdefault(radd, []).append(off)

    def va2off(self, va):
        for (off, vaddr, filesz) in self.loads:
            if vaddr <= va < vaddr + filesz:
                return off + (va - vaddr)
        return None

    def u64(self, va):
        o = self.va2off(va)
        return struct.unpack_from("<Q", self.d, o)[0]

    def cstr(self, va):
        o = self.va2off(va)
        if o is None:
            return None
        e = self.d.find(b"\0", o)
        return bytes(self.d[o:e])

    def room_at(self, off):
        """在字符串起始处，其后（含 NUL 终止符）到下一处非零字节的字节数"""
        j = off
        e = j
        while self.d[e] != 0:
            e += 1
        e += 1                                   # 跨过 NUL
        j = e
        while self.d[j] == 0:
            j += 1
        return j - off

    def dynsym(self):
        dv, do_, ds = self.sections[".dynsym"]
        sv, so, ss = self.sections[".dynstr"]
        out = []
        for i in range(ds // 24):
            st_name, st_info, st_other, st_shndx, st_value, st_size = \
                struct.unpack_from("<IBBHQQ", self.d, do_ + i * 24)
            e = self.d.find(b"\0", so + st_name)
            out.append((bytes(self.d[so + st_name:e]).decode("latin1"),
                        st_value, st_shndx, st_size))
        return out


def fail(msg):
    print(f"!! 校验失败: {msg}", file=sys.stderr)
    sys.exit(1)


# ------------------------------------------------------------- patch: jmgpu_dri

DRI_OLD = b"GL_EXT_texture_rectangle"      # 24 字符，已被 ARB 版覆盖
DRI_NEW = b"GL_EXT_EGL_image_storage"      # 24 字符（本补丁要补的扩展）
assert len(DRI_OLD) == len(DRI_NEW) == 24


def patch_dri(src, dst):
    e = Elf(src)
    ro_v, ro_o, ro_s = e.sections[".rodata"]
    pat = DRI_OLD + b"\0"
    hits = []
    s = ro_o
    while True:
        o = e.d.find(pat, s, ro_o + ro_s)
        if o < 0:
            break
        hits.append(o)
        s = o + 1
    if len(hits) != 1:
        fail(f".rodata 中 {DRI_OLD.decode()} 出现 {len(hits)} 次（期望 1）")
    off = hits[0]
    va = ro_v + (off - ro_o)
    room = e.room_at(off)
    print(f"[dri ] {DRI_OLD.decode()} @ off={off:#x} va={va:#x} room={room}")
    if room < len(DRI_NEW) + 1:
        fail(f"槽位只有 {room} 字节，放不下 {len(DRI_NEW)+1} 字节")
    users = e.reloc_addend_users.get(va, [])
    if len(users) != 1:
        fail(f"引用该字符串的重定位有 {len(users)} 处（期望 1，扩展表 name_ptr）")
    print(f"[dri ] 被 1 处重定位引用（r_offset={users[0]:#x}，即 __glExtension "
          f"name_ptr）")

    span = max(len(DRI_OLD), len(DRI_NEW))
    e.d[off:off + span] = DRI_NEW + b"\0" * (span - len(DRI_NEW))
    if len(e.d) != e.size:
        fail(f"文件长度被改变: {e.size} -> {len(e.d)}")
    open(dst, "wb").write(e.d)
    print(f"[dri ] 写出 {dst}")
    return True


# --------------------------------------------------------------- patch: libGLX

GLX_ALIAS_TBL = 0xAAA08                    # glExtApiAliasTbl
GLX_SACRIFICE = b"glXQueryChannelDeltasSGIX"
GLX_NEW = b"glEGLImageTargetTexStorageEXT"
GLX_OES_IMPL = 0x59970                     # glEGLImageTargetTexture2DOES


def patch_glx(src, dst):
    e = Elf(src)
    syms = e.dynsym()
    oes = [s for s in syms if s[0] == "glEGLImageTargetTexture2DOES"]
    if not oes:
        fail("libGLX 中找不到 glEGLImageTargetTexture2DOES 符号")
    if GLX_OES_IMPL not in [s[1] for s in oes]:
        fail(f"glEGLImageTargetTexture2DOES 不在 {GLX_OES_IMPL:#x}"
             f"（实际 {[hex(s[1]) for s in oes]}）")
    print(f"[glx ] glEGLImageTargetTexture2DOES -> {GLX_OES_IMPL:#x} "
          f"(size={[s[3] for s in oes][0]})")

    # 走一遍别名表，找到被牺牲的记录
    va = GLX_ALIAS_TBL
    rec = None
    i = 0
    while True:
        nm = e.u64(va)
        if nm == 0:
            print(f"[glx ] 别名表 {i} 条，终止符 @ {va:#x}")
            break
        s = e.cstr(nm)
        if s == GLX_SACRIFICE:
            rec = (va, nm)
        va += 16
        i += 1
        if i > 300:
            fail("别名表没有终止符")
    if rec is None:
        fail(f"别名表里找不到 {GLX_SACRIFICE.decode()}")

    rec_va, name_va = rec
    print(f"[glx ] 牺牲记录 @ {rec_va:#x}（{GLX_SACRIFICE.decode()}），"
          f"名字串 va={name_va:#x}")

    name_rl = e.relocs.get(rec_va, [])
    func_rl = e.relocs.get(rec_va + 8, [])
    if len(name_rl) != 1 or name_rl[0][2] != name_va:
        fail(f"name 重定位异常: {name_rl}")
    if len(func_rl) != 1:
        fail(f"func 重定位异常: {func_rl}")
    print(f"[glx ] name reloc addend={name_va:#x}; "
          f"func reloc addend={func_rl[0][2]:#x}")

    off = e.va2off(name_va)
    room = e.room_at(off)
    print(f"[glx ] 名字串 off={off:#x} room={room} "
          f"old={len(GLX_SACRIFICE)} new={len(GLX_NEW)}")
    if room < len(GLX_NEW) + 1:
        fail(f"名字槽位只有 {room} 字节，放不下 {len(GLX_NEW)+1} 字节")

    # 1) 原地改写名字串。必须让切片赋值前后的长度完全一致，否则 bytearray 会
    #    改变文件长度、位移其后所有偏移 → ELF 损坏。新名可能更长，故 span 取
    #    两者较大值（已由上面的 room 检查保证不会踩到下一个字符串）。
    span = max(len(GLX_SACRIFICE) + 1, len(GLX_NEW) + 1)
    e.d[off:off + span] = GLX_NEW + b"\0" * (span - len(GLX_NEW))
    # 2) func 重定位 addend 指向 OES 实现
    rva, roff, rsz = e.sections[".rela.dyn"]
    cnt = 0
    for j in range(0, rsz, 24):
        r_off, r_info, r_add = struct.unpack_from("<QQq", e.d, roff + j)
        if r_off == rec_va + 8:
            struct.pack_into("<q", e.d, roff + j + 16, GLX_OES_IMPL)
            cnt += 1
    if cnt != 1:
        fail(f"改写 func addend 命中 {cnt} 条重定位")

    if len(e.d) != e.size:
        fail(f"文件长度被改变: {e.size} -> {len(e.d)}")
    open(dst, "wb").write(e.d)
    print(f"[glx ] 写出 {dst}")
    return True


# --------------------------------------------------------------- patch: libEGL

#
# EGL 上下文的 GL 入口不走 libGLX，而是 libEGL 自己的
#   eglGetProcAddress -> "forward_"+name 查表 -> LookupGLExtAliasApiProc(name)
#                   -> _LookupProc(name, skew=2) -> _LookupProc(name, skew=2)
# 其中 LookupGLExtAliasApiProc 用同一张 24B `glExtApiAliasTbl`（214 条）
# 对名字做**原地改写**：pattern 命中就把 name 换成 +16 处的替代串
# （+16 为 0 时表示"砍掉末尾 3 字符"，如 glTexImage3DOES -> glTexImage3D）。
#
# 该表里有 9 条带非零替代串（`*ObjectARB` -> core），其中 5 条的替代串
# **与自身完全相同**（改写是空操作）——牺牲它们零功能损失。
#
# 改写目标选 `glEGLImageTargetTexture2DOES`：三张 _LookupProc 表
# (0x67668 / 0x63450 / 0x65838) 里**都已存在**该条目，写回后直接命中。
EGL_ALIAS_TPL = 0x688C8          # glGetObjectParameterfvARB（替代串=自身，空操作）
EGL_STR_PATTERN_VA = 0x3F9A0     # .rodata 里 1030B 零填充区
EGL_STR_REPL_VA = 0x3F9C0
EGL_NEW_PATTERN = b"glEGLImageTargetTexStorageEXT"
EGL_NEW_REPL = b"glEGLImageTargetTexture2DOES"


def _patch_reloc_addend(e, target_va, new_addend):
    rva, roff, rsz = e.sections[".rela.dyn"]
    cnt = 0
    for j in range(0, rsz, 24):
        r_off, r_info, r_add = struct.unpack_from("<QQq", e.d, roff + j)
        if r_off == target_va:
            if (r_info & 0xFFFFFFFF) != 1027:
                fail(f"{target_va:#x} 处重定位类型不是 RELATIVE")
            struct.pack_into("<q", e.d, roff + j + 16, new_addend)
            cnt += 1
    if cnt != 1:
        fail(f"{target_va:#x} 处改写 addend 命中 {cnt} 条重定位")
    return cnt


def _write_str(e, va, s):
    o = e.va2off(va)
    blob = s + b"\0"
    cur = bytes(e.d[o:o + len(blob)])
    if cur.strip(b"\0"):
        fail(f"{va:#x} 处不是空区（已有数据 {cur!r}）")
    e.d[o:o + len(blob)] = blob


def patch_egl(src, dst):
    e = Elf(src)
    tpl = EGL_ALIAS_TPL
    pat_rl = e.relocs.get(tpl)
    repl_rl = e.relocs.get(tpl + 16)
    if not pat_rl or not repl_rl:
        fail(f"{tpl:#x} 模板记录的 pattern/replacement 重定位缺失: "
             f"{pat_rl} / {repl_rl}")
    pat_va = pat_rl[0][2]
    repl_va = repl_rl[0][2]
    pat_str = e.cstr(pat_va)
    repl_str = e.cstr(repl_va)
    print(f"[egl ] 模板记录 {tpl:#x}: pattern={pat_str!r} repl={repl_str!r}")
    if pat_str != repl_str:
        fail("模板记录的替代串不是自身（改写非空操作），换一条模板")
    print("[egl ] 该记录改写为恒等（空操作）→ 牺牲零功能损失")

    # 目标条目确认存在（改写后能命中）。
    # 注意：_LookupProc 用 skew=2 比较（跳过 "gl"），所以表内名字是去掉前缀的形式。
    stripped = EGL_NEW_REPL[2:]
    found = _find_proc_entry(e, 0x63450, stripped)
    print(f"[egl ] 改写目标 {EGL_NEW_REPL.decode()} 在 _LookupProc 表"
          f"(0x63450) 中: {'已存在 @ %#x' % found if found else '缺失'}")
    if not found:
        fail("改写目标不在 _LookupProc 表中，改写后仍无法命中")

    for va in (EGL_STR_PATTERN_VA, EGL_STR_REPL_VA):
        if e.va2off(va) is None:
            fail(f"{va:#x} 不在任何 PT_LOAD 中")

    _write_str(e, EGL_STR_PATTERN_VA, EGL_NEW_PATTERN)
    _write_str(e, EGL_STR_REPL_VA, EGL_NEW_REPL)
    _patch_reloc_addend(e, tpl, EGL_STR_PATTERN_VA)
    _patch_reloc_addend(e, tpl + 16, EGL_STR_REPL_VA)

    if len(e.d) != e.size:
        fail(f"文件长度被改变: {e.size} -> {len(e.d)}")
    open(dst, "wb").write(e.d)
    print(f"[egl ] 写出 {dst}")
    return True


def _find_proc_entry(e, table_va, stripped_name):
    """在 _LookupProc 风格表（24B: {name, func, pad}）里找去掉 "gl" 的名字"""
    va = table_va
    for _ in range(4000):
        nm = e.u64(va)
        if not nm:
            return 0
        if e.cstr(nm) == stripped_name:
            return va
        va += 24
    return 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dri", required=True)
    ap.add_argument("--glx", required=True)
    ap.add_argument("--egl", required=True)
    ap.add_argument("--outdir", default="build-cli")
    a = ap.parse_args()

    os.makedirs(a.outdir, exist_ok=True)
    dri_out = os.path.join(a.outdir, "jmgpu_dri.so.glstorage")
    glx_out = os.path.join(a.outdir, "libGLX_mwv207.so.1.2.0.glstorage")
    egl_out = os.path.join(a.outdir, "libEGL_mwv207.so.1.5.0.glstorage")

    patch_dri(a.dri, dri_out)
    patch_glx(a.glx, glx_out)
    patch_egl(a.egl, egl_out)
    print("\n== 完成 ==")
    print(f"  {dri_out}")
    print(f"  {glx_out}")
    print(f"  {egl_out}")


if __name__ == "__main__":
    main()
