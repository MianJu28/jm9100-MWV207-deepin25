# JM9100 (MWV207) GPU 驱动移植与视频硬解记录

> 平台：**飞腾 D3000 + 景嘉微 JM9100**，内核 **6.6.143-arm64-desktop-hwe (Deepin 25)**。
> 目标：把闭源 **jmgpu 1.7.0** 内核驱动移植到 6.6 并**同时**点亮显示与打通 VA-API 硬解。
>
> **最终结果：1–5、7 已解决，6 已定位根因 ✅；8、9 于 2026-09-16 反编译修复 ✅**
> （1–3 于 2026-09-10；4–7 于 2026-09-14；7 的收尾与显示/GL 性能调优于 2026-09-15，详见 §3.5 / §3.6 / §3.7 / §3.9 / **§8**；
> 8–9 为反编译厂商用户态/补全内核缺陷，见 **§9**）

| # | 问题 | 状态 | 主要修复位置 |
|---|---|---|---|
| 1 | HDMI 无信号（内核 oops） | ✅ | `jmgpu_nicely.c` |
| 2 | 显示灰蒙蒙（低对比度） | ✅ | `jmgpu_package.c`（GAMMA_LUT 契约 768 → 256） |
| 3 | VA-API 直通画面全绿 | ✅ | `mpv_dmabuf_oes_image.patch` + `jmgpu_bullets.c` / `jmgpu_setlayout.c` |
| 4 | EasyTier GUI 白屏（提权进程丢 GL vendor 变量） | ✅ | `/etc/environment`（§3.5，**非仓库代码**） |
| 5 | 未打补丁应用无法 VA-API 零拷贝直通 | ✅ | `jm_gl_compat.c`（用户态 GL 兼容层，§3.6） |
| 6 | 硬件 GL 栈黑窗 | 🔁 归因已推翻，待重查 | `jm_egl_visual_probe.c` 的「EGL 只覆盖 1 个 visual」推断被 `egl_force_visual.c` 实测推翻（**90/90 visual 都能建面渲染**，§3.7 更正） |
| 7 | X11 呈现错位（专有 X 驱动无法加载） | ✅ | `patch_xorg_abi.py` + `patch_abi_layout.py`（ABI 24→25 + `ScrnInfoRec` 布局偏移），见 **§8** |
| 8 | `glEGLImageTargetTexStorageEXT` **原生未实现**（VA-API 零拷贝必须挂 `LD_PRELOAD` 兼容层） | ✅ **已原生修复**（兼容层可退役） | `patch_gl_storage.py`：`jmgpu_dri.so` 扩展广告 + `libEGL_mwv207.so` / `libGLX_mwv207.so` 入口别名，见 **§9** |
| 9 | 内核 Dmabuf（外部 dmabuf 导入）分配器 `.GetSGT` **空桩** → 导入缓冲永远取不到 sg_table | ✅ | `jmgpu_crosstab.c` `_DmabufGetSGT()`，见 **§9.3** |

- 部署流程见 **§4**，日常使用见 **§5**。
- 历史排查全过程（含大量已排除方案、实验数据）见 `backup/FIXLOG.2026-09-10.md`
  与 `backup/README.2026-09-10.md`。

---

## 1. 硬件与系统环境

| 项 | 值 |
|---|---|
| CPU | 飞腾 D3000 (Phytium, aarch64) |
| GPU | 景嘉微 JM9100 (PCI vendor:device = 0731:9100，子系统 0731:9101) |
| 内核 | 6.6.143-arm64-desktop-hwe (Deepin 25 定制) |
| 系统 / 会话 | Deepin 25, Xorg 1.21, lightdm, x11 |
| 显示 | HDMI-A-1（物理显示器 1080p） |

**关键系统事实**

- 闭源用户态由 `com.jingjiamicro.mwv207` / `com.jingjiamicro.mwv207.vaapi` 提供：
  `jmgpu_dri.so`(GL)、`jmgpu_drv_video.so`(VA-API)、`libdrm_jmgpu.so`、专有 Xorg `mwv207_drv.so`。
- 一个 PCI 设备 `0000:07:00.0` **只能绑定一个内核驱动**（jmgpu 与 mwv207 互斥）。
- GPU 显存 2048MB = **CPU 可见窗口 255MB**（PCI BAR2，`0x1000000000`）+
  **不可见 1776MB**（驱动在 iomem 中占位 `0x100000000`，无宿主桥解码）。

---

## 2. 最终架构

```
                 ┌────────────────────────────────────────┐
  单卡全功能     │  闭源 jmgpu 内核 (1.7.0 + 本仓库补丁)    │
  (修复后)       │  显示 ✅   GL ✅   硬解(直通) ✅         │
                 │  /dev/jmgpu + /dev/dri/card0            │
                 └────────────────────────────────────────┘
```

**仍然成立的客观事实**

1. 一个 PCI 设备只能绑一个内核驱动（已不需要共存）。
2. 景美开源系（deepin `mwv207` / Icenowy `mwv207-dkms` / 官方 6.6）显示可用，
   但**从内核到 mesa 都无解码用户态**，纯开源路线无法做硬解。
3. deepin 官方对景美卡的支持已转向商业 UOS（社区商店驱动已下架）。

---

## 3. 关键修复

### 3.1 HDMI 无信号（内核 oops）✅

**症状**：jmgpu 接管后 connector 报 `connected`，但桌面/彩条均无信号输出。

**根因**（两处内核 API 迁移遗漏叠加，由 oops 栈定位）

1. HDMI connector `late_register` 里创建了自管 i2c adapter `hdmi->ddc`，
   却从未同步到内核标准字段 `connector->ddc`（恒 `NULL`）。EDID 读取走自管
   adapter 一直正常，掩盖了该缺陷。
2. 内核 6.5+ 把 `drm_scdc_set_scrambling/set_high_tmds_clock_ratio` 的签名由
   `(struct i2c_adapter*, bool)` 改成 `(struct drm_connector*, bool)`；厂商本地
   adapter 版实现被 `#if < KERNEL_VERSION(4,12,0)` 条件块排除，6.6 下链接到内核
   connector 版 → 内部取 `connector->ddc` = NULL → `i2c_transfer(NULL)` →
   translation fault → atomic commit 中断 → 无信号。

```
drm_mode_setcrtc → drm_atomic_commit → commit_tail
  → drm_atomic_helper_commit_modeset_enables
    → j9_handle_j9m_principium → j9_troglodyte → hdmi_phy_config_para [jmgpu]
      → drm_scdc_set_scrambling [drm_display_helper]   ← 内核符号(签名已变)
        → i2c_transfer → el1_abort → do_page_fault      ← 空指针 oops
```

**修复**（全在 `jmgpu_nicely.c`）

| # | 修复 |
|---|---|
| 1 | `late_register` 中补 `hdmi->connector.ddc = hdmi->ddc;` |
| 2 | 8 处 `drm_scdc_*(&hdmi->connector, …)` → `jmgpu_scdc_*(hdmi->ddc, …)` |
| 3 | `jmgpu_scdc_set_scrambling/set_high_tmds_clock_ratio` 定义移出 `#if <4.12` 条件块 |

**验证**：`modetest -M jmgpu -s 41@35:1920x1080` → rc=0 出现彩条；
持久化后 lightdm + 专有 X 点亮桌面；`vainfo` 报全 profile
（H264 全系 / HEVC Main+Main10 / VP9 / JPEG VLD）。

---

### 3.2 显示灰蒙蒙（低对比度）✅

**症状**：jmgpu 栈下任意内容整体低对比度——**黑发灰、白不白、色相完全正确**；
硬件光标正常（cursor plane 不走主 surface 的 LUT）。mwv207 栈显示正常。

**根因（2026-09-11 更正）**：不是 X 驱动的问题，是**本仓库内核驱动的
color-mgmt 契约与自身消费端不一致**：

```c
jmgpu_package.c:1270  drm_crtc_enable_color_mgmt(&jcrtc->base, 768, true, 768);
                      /* 宣称 gamma_lut_size = 768 —— 厂商把「3 通道 × 256」
                         误当成了一个 LUT 的项数 */
jmgpu_package.c:587   for (i = 0; i < 256; i++)    /* 却只读前 256 项 */
```

DRM 的契约是「`gamma_lut_size` 个表项，每项自带 r/g/b」，不是三通道首尾相接。
于是客户端下发的 **768 项 identity ramp 只有前 1/3 进硬件**，采样值恰好是
`0,21,42,64,85` = `in/3` —— 整屏被压到 1/3 动态范围，表现为"黑发灰、白不白、
色相正确"，且亮度值只剩应有的 1/3。

**证据**（本轮新增探针 `drm_gamma_probe.c`，读 CRTC 的真实属性）：

```
$ ./drm_gamma_probe /dev/dri/card0
crtc 35: legacy gamma_size=256
  GAMMA_LUT_SIZE     value: 768          <-- 对外宣称 768 项
  GAMMA_LUT          blob: 6144 字节 = 768 项   <-- 客户端确实下发了 768 项
  DEGAMMA_LUT_SIZE   value: 768          <-- 驱动并未实现 degamma
```

而驱动内部 `lutdata[3*256]`、`pWriteData = data + rgb*256` 与读取循环
都只按 **256 项/通道** 工作。

> 历史结论「X 专有驱动 `mwv207_drv.so` 的 gamma 下发有固定 1/3 缩放缺陷」
> **不成立**：X 下发的是完全正确的 768 项 identity ramp（其项数正是照内核宣称的
> `GAMMA_LUT_SIZE` 来的）。当时的 `gamma_norm=3` 补偿是在补我们自己的 bug，
> 且补偿会带来精度损失（X 侧 ramp 先被截断到 1/3 分辨率，再乘 3 放大，
> 灰阶只能落在 3 的倍数上）。

**修复**（`jmgpu_package.c`）

1. 新增常量 **`JMGPU_LUT_ENTRIES_PER_CHANNEL = 256`**，同时用于：
   对外宣称的 `gamma_lut_size`、`lutdata[3*N]` 布局、`pWriteData = data + rgb*N`、
   `atomic_flush` 的读取项数 —— 三者不可能再各自漂移；
2. `drm_crtc_enable_color_mgmt(crtc, 256)`：degamma/CTM 本驱动未实现，
   一并关闭（改前客户端设置它们会被静默忽略）；契约与
   `drm_mode_crtc_set_gamma_size(256)` 统一；
3. `atomic_flush` 增加 `BUILD_BUG_ON` 与 blob 长度校验告警；
4. `gamma_norm` 默认值由 3 改回 **1（原样写）**——契约修正后这就是正确行为。

**验证（2026-09-11 实测通过 ✅，模块 `3D636A0CE8AA8C215CACE52`，`gamma_norm=1`）**

```
$ ./drm_gamma_probe /dev/dri/card0
crtc 35: legacy gamma_size=256
  GAMMA_LUT          blob: 2048 字节 = 256 项      <-- 契约与消费项数一致
    ramp 采样(8位) R: 0 64 128 192 255  G: 0 64 128 192 255  B: 0 64 128 192 255
    判定: 线性(正确)
  GAMMA_LUT_SIZE     value: 256
（DEGAMMA_LUT / CTM 属性已不再提供）

$ sudo grep -i CONTRAST /tmp/reg.txt          # 显示域寄存器 dump
WIN+0x38 WIN_CONTRAST        @0x990038 = 0x800000f0   <-- 128*15/8：LUT 装的是线性表
                                                      （修复前为 0x8000004e ≈ 42 = 128/3）
```

即：X 下发的 256 项 ramp 被**完整**消费，硬件 LUT 为精确线性表，且**无需任何
内核侧补偿**（`gamma_norm=1`）。这一结果同时反证了历史结论——X 下发的本来就是
线性 ramp（`0,64,128,192,255`），并不存在"1/3 缩放缺陷"。

**回退**：若客户端仍按旧契约提交 768 项 blob（未重启 X 时），`drm_atomic` 会以
`-EINVAL` 拒绝，此时改回 `echo 3 | sudo tee /sys/module/jmgpu/parameters/gamma_norm`
即可临时回到旧行为；`gamma_norm` 参数保留正是为了这种兼容场景。

---

### 3.3 VA-API 直通画面全绿 ✅

**症状**：`mpv --hwdec=vaapi`（VA surface 经 dmabuf 零拷贝交给 GL）画面全绿
（YUV 全零）；`vaapi-copy`（解码后回读到 CPU）像素完全正确。

**根因：两处缺陷叠加**

1. **解码 surface 落在 CPU 不可见显存池。**
   VA 驱动把**整个解码 surface 池作为一整块连续显存**申请（导出的各 surface
   池内偏移严格等间隔 `0x2FD000`），再切成单个 surface。而 CPU 可见窗口只有
   255MB（BAR2），被桌面应用打碎后最大连续空闲块只剩 8~11MB，装不下该申请
   （4 个 1080p surface 需 12.5MB 连续，典型流需 ~63MB 连续）→ **整组回退**到
   1776MB 不可见池。不可见池在 BAR2 之外，驱动只给了它一个 `request_mem_region`
   的**占位 CPU 地址**、没有宿主桥解码：直接对它 `remap_pfn_range()` 会成功返回，
   但读恒为 `0x00`、写被静默丢弃。（仅指 `dma_buf_mmap()` 这条路——不可见池
   并非 CPU 完全够不到，驱动另有滑动窗口，见下方「补」中的两条路径对比。）
2. **mpv 的导入入口选错。**
   mpv（0.40/0.41）的 `vaapi_gl_mapper_init()` 在 desktop GL 下只解析并调用
   `glEGLImageTargetTexStorageEXT`；JM9100 的该入口**存在但不真正把 dmabuf
   挂接到纹理**，纹理恒为全零（JM9100 只声明 `GL_OES_EGL_image`，不声明
   `GL_EXT_EGL_image_storage`）。
   > §3.8 反编译更正：驱动里**根本没有**该符号，入口是 glvnd 生成的 no-op stub 顶替的，
   > 即"未实现"而非"实现错误"；客户端侧由 §3.6 的 `jm_gl_compat.c` 兜底。

**修复**

| 侧 | 改动 |
|---|---|
| mpv（`mpv_dmabuf_oes_image.patch`） | `video/out/hwdec/dmabuf_interop_gl.c`：desktop GL 分支在未声明 `GL_EXT_EGL_image_storage` 时改用 `glEGLImageTargetTexture2DOES`(GL_OES_EGL_image)（init/map/unmap 三处生命周期判断随之自动走 OES 路径）；扩展检查放宽为 OES / storage 任一。补丁同时适配 mpv 0.40 与 0.41 |
| 内核（dmabuf 导出链） | ① 导出尺寸改 `PAGE_ALIGN()` 向上对齐；② `.map_dma_buf` 失败改返回 `ERR_PTR`（原返回 NULL 会被解引用）；③ `mmap`/导出补越界防御（clamp 到池尾）与限流诊断日志；④ reserved-mem `.Mmap` 对**非宿主可寻址**池（`cpuAccessible=FALSE` 的不可见池）直接拒绝——见下方「补」 |
| 内核（同驱动导入） | 新增 `jmgpu_dmabuf_peek_node()`：dmabuf 由本驱动导出时（`dmabuf->ops == &_dmabuf_ops`），`j9_handle_j9_dumbbeller()` 直接复用原 VIDMEM 节点包装成 GEM 对象，绕开 reserved-mem 缺失的 `.GetSGT`（该空桩会让标准 `map_dma_buf` 导入永远失败） |

**关键认识**：改用 OES 入口后，Jingjia EGL/GL 是经 **GEM 句柄在 GPU 侧**导入
dmabuf 的，**与缓冲落在哪个池无关**。因此内核侧保持**厂商默认池策略**即可，
不需要 `prefer_visible_pool` / `no_exclusive_pool` 等参数。

**补（2026-09-11，据应用侧实测）：CPU 侧 importer 必须被显式拒绝**

上述「与池无关」只对 **GPU 侧导入**成立。应用侧审计
（purelive `docs/LINUX_JM9100_HWDECODE_AUDIT.md` §10.1）实测到另一条路径：

| 实测 | 结果 |
|---|---|
| 纯 EGL/ES 进程 + Jingjia EGL，`hwdec=vaapi` | ✅ `Using EGL dmabuf interop via GL_OES_EGL_image`，回读帧为源色红 `(254,24,0)` |
| 同一路径改用 **Mesa/llvmpipe**（应用 §9.2 的 UI 形态） | ⚠️ 仍报 `hwdec-current=vaapi`，但回读帧是**全零 NV12 深绿** `(26,130,73)` |

原因：Mesa/llvmpipe 的 dmabuf 导入**要走 CPU mmap**（`dma_buf_mmap()`）。旧代码在
不可见池上把 `remap_pfn_range()` 装进 PTE 并成功返回，映射却恒读 `0` ——
**全链路无一处报错，画面静默变绿**。

因此 `j9_pathopsychosis` 现在对 `cpuAccessible=FALSE` 的池**拒绝 CPU mmap**
（`-ENODEV`/`EINVAL`，限流日志打印池名、总线地址与进程名），
新参数 **`allow_invisible_mmap=0`（默认）** 即为该行为。效果：

- llvmpipe 这类 CPU importer 的导入**立即失败**（mpv 日志出现 mmap 失败并回落
  `vaapi-copy`/软解，画面正确但非零拷贝）——把静默错误变成可见、可回退的失败；
- Jingjia EGL/GL 的 GPU 侧导入不受影响（不经 `dma_buf_mmap`），零拷贝直通照旧；
- `allow_invisible_mmap=1` 可复现历史（静默全零）行为，仅用于排查。

**为什么是"拒绝"而不是"改走滑动窗口"**（2026-09-11 实测澄清）

不可见池并非 CPU 完全够不到：驱动在 **BAR2 末尾**开了一块 128KB 一档的
**滑动窗口**（`slide_window_base/top`，`jmgpu_insert.c`），GEM/dumb 的 `mmap()`
缺页时（`jmgpu_garbage.c: j9_handle_j9_sitatungas`）把窗口页重指向设备显存页，
并 `unmap_mapping_range()` 失效旧映射。但 `dma_buf_mmap()` 这条路径**不经过**
窗口，只有占位地址上的 `remap_pfn_range()` 一条路，于是"映射成功、读全零"：

| CPU 访问路径 | 走的代码 | 不可见池结果 |
|---|---|---|
| `dma_buf_mmap()`（Mesa/llvmpipe 导入 dmabuf） | reserved-mem `.Mmap` | 静默读全零 → **故显式拒绝** |
| GEM/dumb `mmap()`（`j9_diluvianism` + 缺页） | `j9_handle_j9_sitatungas` | **可用**（滑动窗口） |

不改走窗口的理由是性能与资源，而非"不可能"：窗口一次仅映射 128KB、每次滑动
都要失效旧映射，整帧采样（1080p NV12 = 3MB/帧）会严重抖动；且窗口是全局共享
资源，与厂商用户态自身的用法有冲突风险。实测 GEM/dumb 通路完好：

```
$ ./jm_dumb_probe /dev/dri/card0
[1] CREATE_DUMB      : ok (handle=1 pitch=1024 size=262144)
[2] MAP_DUMB(取偏移) : ok (offset=0x1007f1000)
[3] mmap             : ok (0xffff811d0000)
[4] 读写回环         : map[0]=0xa5 map[63]=0xa5 (正常)
```

内核级复现（`./jm_gem_probe <bytes> 1`；尺寸要大到可见池装不下才会落到
不可见池，本机实测 **64MB 起**如此，32MB 仍落可见池）：

```
# 32MB → 可见池：两端映射内容一致（无回归）
sz=33554432 flags=0x1 gpu_addr=0xcc26000 ... A[ok=8192 bad=0] B[ok=8192 bad=0] cpu[0]=5a dma[0]=5a

# 64MB → 不可见池，allow_invisible_mmap=0（默认）：直接显式失败
sz=67108864 flags=0x1 mmap dmabuf FAILED

# 64MB → 不可见池，allow_invisible_mmap=1（旧行为）：成功但读全零
sz=67108864 flags=0x1 gpu_addr=0x123cf000 ... A[ok=64 bad=16320] B[ok=0 bad=16384] cpu[0]=a5 dma[0]=00
#                                        ↑ CPU 映射写入生效      ↑ dmabuf 映射读全零
```

对应的内核日志：

```
jmgpu: refusing CPU mmap of 16384 pages in pool 'jmExtMem0' @0x100000000
  (pid 17236 'jm_gem_probe'): pool is not host-addressable, so the mapping
  would read zeros; use allow_invisible_mmap=1 to override
```

> 注：`jmExtMem0` 是厂商给 external/exclusive 两个池起的同一个名字（`jmgpu_scroll.c`
> 里两处 `sprintf(name, "jmExtMem%d")`），因此以地址区分——`@0x100000000` 才是
> 不可见池，可见池是 BAR2 的 `0x1000000000`。

**验证**（2026-09-11 复测：内核 `718BB943…` + 打过补丁的 mpv 0.41 CLI，
`./test_passthrough.sh -s 1080p`，纯红片源）：

```
本次播放新增的导出池归属：
  -> 可见池(pool=4): 0 个；不可见池(pool=12): 7 个
直通(vaapi): 1920x1080 avg=(255,0,64) 绿色占比 0.0%
软解(no)   : 1920x1080 avg=(255,0,64) 绿色占比 0.0%
==> 直通【正常】：画面是片源原色(红)
  mpv 实际使用: Using hardware decoding (vaapi)
```

解码 surface **全部来自不可见池（pool=12）**，direct 仍渲染正确——这就是
「GPU 侧导入与池无关」的端到端证明，同时也说明新增的 mmap 拒绝**没有**影响该路径
（本次播放无任何 `refusing CPU mmap` 记录）。

复现用的带补丁 CLI 可以不动系统 mpv，直接在 `/tmp` 构建：

```bash
curl -sL -o /tmp/mpv-0.41.0.tar.gz \
  https://codeload.github.com/mpv-player/mpv/tar.gz/refs/tags/v0.41.0
tar xf /tmp/mpv-0.41.0.tar.gz -C /tmp && cd /tmp/mpv-0.41.0
patch -p1 < ~/Desktop/Git/jm9100/mpv_dmabuf_oes_image.patch
meson setup build -Dlibmpv=true -Dcplayer=true -Dvulkan=disabled -Dgpl=true \
      -Dlua=disabled -Djavascript=disabled && ninja -C build
LD_LIBRARY_PATH=$PWD/build PATH=$PWD/build:$PATH \
  ~/Desktop/Git/jm9100/test_passthrough.sh -s 1080p
```

> **前提**：被测 mpv 必须是**打过本仓库补丁**的重编版本。系统原版 mpv 在
> desktop GL 下会直接拒绝 VA-API interop（verbose 日志：
> `VAAPI hwdec only works with OpenGL or Vulkan backends`），此时 mpv **静默回落
> 软解**，脚本仍会输出「直通【正常】」——那是在测软解，不能作为直通可用的证据。
> 自检脚本现在会显式报出 mpv 实际是否启用硬解（见 §5.3）；2026-09-11 复查发现
> 本机 `/usr/bin/mpv` 是 `0.40.0-3+deb13u1deepin1` 原版包（未重编），
> 因此当时那次「正常」判定无效，需按 §4.3 重编 mpv 后重测。

---

### 3.4 卸载/重载 与 S3 挂起恢复（2026-09-11 实测 ✅）

用 `jmgpu_reload_test.sh` 在 **SSH 会话**里执行（图形会话会被停掉，所以发起
通道必须独立于桌面）：

| 检查项 | 结果 |
|---|---|
| 停机前引用计数 | 121 / 93（两次独立运行） |
| 停 lightdm + 结束 X 后 | 引用计数 **0**，`fuser /dev/dri/card0` 无占用 → 客户端都正常释放 |
| `rmmod jmgpu` | rc=0，`/dev/jmgpu`、`/dev/dri` 全部消失，dmesg 仅 `jmgpu_dec: module removed` |
| `modprobe jmgpu` | 重建 `/dev/jmgpu`+`card0`+`renderD128`，初始化链完整、无告警 |
| 重复性 | 连续两次结果一致 |
| **S3（带活动桌面）** | 挂起前 `lightdm=active`；唤醒后 vram / decoder / cores / j2d / dvfs / jaudio / **kms** 全部 `resume done`，**桌面存活**，无 BUG/WARNING |

过程中修掉两处问题：

1. **测试脚本自身（非驱动问题）**：`pkill -9 Xorg` 不会清理 `/tmp/.X0-lock` 与
   `/tmp/.X11-unix/X0`，残留使 lightdm 之后启 X 报
   `Cannot establish any listening sockets - Make sure an X server isn't already running`
   → 桌面再也起不来，只能重启。现改为：先 `TERM` 等 X 自清（5s），必要时才 `-9`，
   **`-9` 后强制清锁/socket**；restore 改为**轮询等待 30s**（原先 4s 就判死并
   restart，越帮越忙），失败时自动把 `systemctl status lightdm` /
   `journalctl -u lightdm` / Xorg 日志收进测试日志。
   同样的陷阱在既有 `verify_jmgpu_probe_ssh.sh` 里也有，已一并修正。
   修复后同一脚本能自动把桌面带回来（`lightdm=active`）。

2. **SCDC 日志级别**（`jmgpu_nicely.c`）：普通 1080p sink 不支持 SCDC，
   `drm_scdc_readb` 返回 `-ENXIO(-6)` 属**正常降级**（Scrambling/TMDS 比率是
   HDMI 2.0 高时钟才需要），原实现却按 `DRM_ERROR` 打印，于是每次建链、每次
   S3 恢复都刷 4 行 `*ERROR*`，既误导又把真正的错误淹没。现改为：无 SCDC 的
   sink 只 `DRM_INFO` 提示一次，其余失败降为 `DRM_DEBUG_KMS`。

   验证（2026-09-11 重启后，模块 `F55C8DA4…`）：

   ```
   $ sudo dmesg | grep -i scdc
   [   27.854490] [drm] HDMI sink does not support SCDC (err=-6);
                  scrambling / TMDS clock-ratio setup skipped
   ```

   只有一行一次性 INFO、**零 `*ERROR*`**；随后用 `xrandr` 反复切换刷新率
   （等价于重新建链）也不再产生任何输出。

> **环境事实（排查须知）**：本机 `journalctl -k` **不收录内核消息**（只有 1 行），
> 且 `kernel.dmesg_restrict=1` —— 内核日志只能靠 `sudo dmesg` 取得，
> 排查时不要用 journal。

> 已知但未改动：`jmgpu_dec: IRQ irq[0] not in use!`（每次加载都出现）——
> 解码器未注册独立 IRQ（走轮询/共享机制）。硬解实测正常（600 帧 1080p30 仅
> 0.70s CPU），按信息性提示处理，待有 IRQ 负载疑虑时再深查。

---

### 3.5 EasyTier GUI 白屏（提权进程丢失 GL vendor 变量，2026-09-14）✅

**症状**：EasyTier GUI v2.6.4（**Tauri + WebKitGTK 4.1**，libwebkit2gtk 2.50.4）在 jmgpu
栈下窗口**纯白**，只剩标题栏。量化：窗口像素 `mean=1.0 / std=0`（完全均匀白）。

**第一手结论：白屏不是"驱动画不出来"，而是 WebKit 的 web 内容进程已死**

```
$ pgrep -af "webkit2gtk-4.1/WebKit"      # 白屏实例
26282 …/WebKitNetworkProcess 1 16 18     # 网络进程在，WebKitWebProcess 不存在
```

内核侧**无 GPU 复位/hang/fault、无 OOM**；`jmgpu-exp` 导出记录全部**早于**应用启动
（应用启动 ≈ t1620s，最后一条导出 t1442s）——即 **EasyTier 根本没走 GPU/dmabuf**，
与 §3.3 的 dmabuf 改动无关。

**根因：环境变量断链，被驱动栈切换放大**

1. EasyTier GUI 需要 root（建 TUN），会**通过 `pkexec` 把自己重新拉起**：

```
easytier-gui(admin) → pkexec /usr/bin/env DISPLAY=:0 XAUTHORITY=… HOME=… /usr/bin/easytier-gui (root)
```

2. 景美 GL 依赖 `__GLX_VENDOR_LIBRARY_NAME=mwv207`
   （来源 `/etc/profile.d/mwv207_glvnd.sh`；配套 `/usr/share/glvnd/{glx,egl}_vendor.d/10_mwv207.json`）。
   **`pkexec` 会清空并重建环境**，该变量不在白名单 → 提权后的 GUI 丢失它。
   （逐项对比两个进程环境：除该变量外其余差异 `PKEXEC_UID`/`PATH`/`TERM`/`XDG_CURRENT_DESKTOP`
   均不影响结果。）
3. 变量丢失后 glvnd 取 **X server 通告的 vendor 名**（Xorg 21.1.16 默认 `mesa`），
   去加载 `libGLX_mesa.so.0`：`libGLX.so.0` 的内部常量是 `libGLX_%s.so.0`，
   **Vendor 名由 server 决定，JSON 的 `library_path` 不参与**。于是 Mesa 顶上来，
   而 Mesa 对 `0731:9100` 无驱动：

```
glx: failed to create dri3 screen
failed to load driver: jmgpu
KMS: DRM_IOCTL_MODE_CREATE_DUMB failed: 权限不够
Failed to create GBM buffer of size 800x600: 权限不够
```

4. WebKit WebProcess 渲染 / GBM 初始化失败 → **进程死亡** → 白页。

**为什么"改完驱动"才暴露**：开源 mwv207 栈下 Mesa 有配套 `mwv207_dri.so`，回落路径
可用，问题被掩盖；换成闭源 jmgpu 内核驱动后 Mesa 无驱动，回落必然失败。
**驱动修复本身没错，只是把"GL vendor 选择依赖"从被掩盖变成致命。**

**修复**：在这套 Xorg + 专有 DDX 组合下，**变量只能靠环境变量交付**（glvnd 级配置
消除不掉，见下方"已排除"），因此只需补齐 PAM 这条链路 —— `/usr/lib/pam.d/polkit-1`
本就调用 `pam_env.so readenv=1`（会读 `/etc/environment`），而驱动安装脚本只写了
`/etc/profile.d/`（仅登录 shell 生效）：

```bash
# 追加一行（覆盖 pkexec / su / login / sshd / lightdm / cron 等所有 PAM 会话）
__GLX_VENDOR_LIBRARY_NAME=mwv207      # 写入 /etc/environment
```

> `sudo` 的 PAM 栈**不含** `pam_env`，所以**不能**用 `sudo easytier-gui` 来复现/验证本问题
> ——那种方式自带变量，画面正常，会得出"没问题"的错误结论。

**验证（2026-09-14，重启后从桌面图标启动，即走 pkexec 提权路径）**

| 检查项 | 修复前 | 修复后 |
|---|---|---|
| 提权进程环境（`PKEXEC_UID=1000` 的 root 实例） | 无 `__GLX_VENDOR_LIBRARY_NAME` | **有** `__GLX_VENDOR_LIBRARY_NAME=mwv207` |
| `WebKitWebProcess` | 不存在（仅 NetworkProcess） | 存活 |
| 窗口像素 | `mean=1.0  std=0`（纯白） | `mean=0.975  std=0.104`（正常渲染） |

**对照实验（同一二进制、同为 root，只改环境）**

| 启动方式 | WebProcess | 画面 |
|---|---|---|
| `sudo` + 环境含 `__GLX_VENDOR_LIBRARY_NAME=mwv207` | 存活 | 正常 |
| `env -i …`（精确复刻 pkexec 环境，无该变量） | 起来后**立即死** | 白屏 |
| `MiniBrowser`（`/usr/lib/aarch64-linux-gnu/webkit2gtk-4.1/MiniBrowser`）免 root 复现 | 同上结论一致 | 同上 |

**已排除的"glvnd 级"方案（勿再尝试）**

1. 在 `glx_vendor.d` 增加 `{"name":"mesa", "library_path":"…/libGLX_mwv207.so.1.2.0"}` →
   **无效**：glvnd 按 `libGLX_<name>.so.0` 拼 soname，不看 JSON 的 `library_path`。
2. 指望 glvnd/景美 X 驱动"默认认领 vendor" → server 侧报的就是 Xorg 默认的 `mesa`，
   客户端改不动；除非顶掉 `libGLX_mesa.so.0` 本体，代价过大（会打掉 Mesa 软栈）。
3. 顺带排除：系统范围内 `Disabled hardware acceleration because GTK failed to initialize GL:
   指定的 RGBA 像素格式没有可用的设置` 在**修复前后都会出现**（WebKit 因此走软件回退），
   **不是**白屏的判据，不要拿它当根因。

---

### 3.6 用户态 GL 兼容层：补齐 `GL_EXT_EGL_image_storage`（2026-09-14）✅

**问题**（purelive 审计 §10.1/§10.2）：景美桌面 GL 的用户态实现存在不对称：

- ✅ 声明 `GL_OES_EGL_image`，`glEGLImageTargetTexture2DOES()` **能真正**把 dmabuf 挂到纹理；
- ❌ **未声明** `GL_EXT_EGL_image_storage`，而 `glEGLImageTargetTexStorageEXT()` 这个入口
  「存在却不真正挂接 dmabuf」（纹理恒为全零）。

后果：走 storage 路径的客户端（mpv 的 `vaapi_gl_mapper`、Chromium 等）在桌面 GL 下**主动拒绝**
VA-API dmabuf 零拷贝 —— 回落 `vaapi-copy`（收益被搬运吃光）或软解；在 Mesa/llvmpipe 上更会
**静默产出全零帧**（深绿绿屏）。此前只能给 mpv 打补丁（§3.3 的
`mpv_dmabuf_oes_image.patch`），属于**逐应用修**。

**方案：一次性覆盖所有应用的 LD_PRELOAD 兼容层**（`jm_gl_compat.c`）

| 动作 | 说明 |
|---|---|
| 广告 `GL_EXT_EGL_image_storage` | `glGetString(GL_EXTENSIONS)`、`glGetStringi()`、`glGetIntegerv(GL_NUM_EXTENSIONS)` **三条路径都覆盖** |
| storage → OES 重定向 | `glEGLImageTargetTexStorageEXT()` / `glEGLImageTargetTextureStorageEXT()` → `glEGLImageTargetTexture2DOES()`（语义等价，都作用于当前绑定纹理） |
| `getProcAddress` 拦截 | `glXGetProcAddress(ARB)` / `eglGetProcAddress` 也返回上述重定向 —— **epoxy / glad / GLEW 绕过动态链接器符号表**，只做符号插入抓不到它们 |
| 防御式生效 | 仅当 `GL_VENDOR` 含 `Jingjia` **且** `glEGLImageTargetTexture2DOES` 真实存在（能力判据）时介入；其它栈原样透传 |
| 开关 | `JMGPU_GL_COMPAT=0` 关闭；`JMGPU_GL_COMPAT_DEBUG=1` 打印日志 |

```bash
./build_gl_compat.sh              # 编译到 build-cli/libjm_gl_compat.so
./build_gl_compat.sh install      # 安装到 /usr/lib/aarch64-linux-gnu/
./test_gl_compat.sh               # 一键验证（三步）
LD_PRELOAD=.../libjm_gl_compat.so LIBVA_DRIVER_NAME=jmgpu mpv --vo=gpu --hwdec=vaapi 视频.mp4
```

**验证（2026-09-14，系统 `mpv v0.40.0`，**未打任何补丁**，720p 纯红片源）**

| 检查项 | 无兼容层 | 有兼容层 |
|---|---|---|
| `GL_EXT_EGL_image_storage` | 不在扩展列表 | **在** |
| mpv `vo/gpu/vaapi` 判定 | `VAAPI hwdec only works with OpenGL or Vulkan backends.`（拒绝 direct） | **`Using EGL dmabuf interop via GL_EXT_EGL_image_storage`**（进入 direct） |
| 直通画面像素 | — | `avg=(255,0,64)`，绿色占比 0.0%（非全零绿屏） |
| 重定向日志 | — | `redirect glEGLImageTargetTexStorageEXT(target=0xde1) -> glEGLImageTargetTexture2DOES` |

即：**未打补丁的应用也能零拷贝直通**。兼容层不替换任何厂商库，可随时用 `JMGPU_GL_COMPAT=0` 或
不设 `LD_PRELOAD` 停用。

---

### 3.7 硬件 GL 栈黑窗根因：景美 EGL 的 config 只覆盖一个 visual（2026-09-14）❌ 结论已更正（见本章文末 2026-09-15）

**症状**：purelive 在 `PURELIVE_JM9100_GL=hardware` 下窗口**纯黑**（`mean=0 std=0`），
引擎持续刷：

```
[ERROR:flutter/.../embedder.cc(939)]  Could not wrap embedder supplied frame-buffer.
[ERROR:flutter/.../embedder.cc(1538)] Could not create a surface from an embedder provided render target.
```

**排查（按证据逐项排除）**

| 实验 | 结果 | 排除的假设 |
|---|---|---|
| `glxgears`（厂商 GLX）640x480 | 正常 | 厂商 GLX 窗口化呈现本身 |
| `glxgears` **1920x1030**（与应用同尺寸） | 正常 100 FPS | **窗口尺寸/显存不足** |
| Xorg 日志 glamor 记录 | `Failed to allocate 1920x1030 FBO due to GL_OUT_OF_MEMORY` **全局仅 1 次**，复跑不再出现 | **不是稳定阻塞点**（该次瞬时 OOM 会引发 `GLXBadPixmap` 崩溃，属一次性资源事件） |
| `jm_egl_visual_probe`（本仓库新增） | 景美 EGL 的 **40 个 config 只覆盖 `0x21` 一个 visual**；其余 **89 个** visual（含应用选的 `0x7c`、全部 32 位 ARGB）**无 config** → `eglCreateWindowSurface` 必然失败 | **根因** |

```
$ ./jm_egl_visual_probe
EGL_VENDOR  = Jingjia Micro
EGL 共 40 个 config，覆盖 1 个 X visual
  visual   depth  class      EGL config   window surface
  0x21     24     TrueColor  40个         OK
  0x7c     32     TrueColor  -            （无匹配 config，引擎必然失败）
  ...（其余 88 个同理）...
屏幕默认 visual = 0x21
```

**根因**：Flutter(GTK embedder) 最终用 **EGL** 给窗口建 surface；而窗口 visual 是应用按
「**32 位 ARGB 优先**」挑的（本机 `0x7c`），该 visual 不在景美 EGL 的 config 覆盖范围内
→ 引擎建不出 surface → 黑窗。**唯一可用的 `0x21` 恰好就是屏幕默认 visual。**

**修复方向（应用侧，一处）**：visual 选择必须以「**EGL 能否建出 window surface**」为准，
而不是「`gdk_window_create_gl_context` 成功」（后者只验 GLX 路径，会误选 `0x7c`）。
在景美栈上等价于：**硬件模式下不要覆盖窗口 visual**，沿用默认 `0x21`，
只保留会话 GL 环境（`__GLX_VENDOR_LIBRARY_NAME=mwv207`）。

> **对 purelive 审计 §10.1 的更正**：其中「屏幕默认 visual `0x21` 能建上下文但呈现阶段崩溃、
> 只有 32 位 ARGB `0x7c` 能出图」的规则来自 GLX 路径观测，且被首次 glamor OOM 污染。
> 以本节的 EGL 实测为准：`0x21` 是**唯一**能让景美 EGL 建出 window surface 的 visual。

---

### 3.8 用户态库反编译结论：两处缺陷属「未实现」，无法小补丁修复（2026-09-14）🔍

> 结论先行：**§3.6 的扩展/入口缺失与 §3.7 的 EGL visual 缺失，都不是"实现错了"，而是
> "没有实现"或"结构性缺失"**。在闭源二进制上做等价补丁需要**新增可执行段 + 运行时表项**，
> 风险大于收益。因此修复落点保持在**客户端侧**（§3.6 的 `jm_gl_compat.c` + §3.7 的
> visual 选择），反编译结果转为**给厂商的精确缺陷报告**（含地址与结构）。

**方法与可分析性**：三个厂商用户态库**均未 strip**（符号表完整），用 `objdump` / `nm` /
`readelf` / `radare2` 可直接得到函数名与数据结构。

| 库 | BuildID | 大小 |
|---|---|---|
| `dri/jmgpu_dri.so`（GL 实现） | `367ef146…` | 4.0 MB |
| `mwv207/libEGL_mwv207.so.1.5.0` | `e418a068…` | 426 KB |
| `mwv207/libGLX_mwv207.so.1.2.0` | `cce3049e…` | 789 KB |

**发现 1：`glEGLImageTargetTexStorageEXT` 在驱动里根本不存在**

```
$ nm -D --defined-only jmgpu_dri.so | grep -i glEGLImage
glEGLImageTargetRenderbufferStorageOES   0x81e20
glEGLImageTargetTexture2DOES             0x81dc0     ← 只有 OES 版
（无任何 TexStorage 符号；GL_EXT_EGL_image_storage 字符串也不存在）
```

所以 §3.3 里「入口存在但不真正挂接 dmabuf」的**真正机制**是：该入口由 **glvnd 生成的
no-op stub** 顶替（驱动未实现），而不是厂商实现写错了。**§3.3 的措辞据此更正。**

扩展表结构（可用于未来补丁）：

| 结构 | 地址/说明 |
|---|---|
| `__glExtension` | `.data` @`0x37be70`，**206 条 × 24 B** = `{u64 index; u64 name_ptr; u64 profile_flags}`，index 0…205，**无空槽**（符号大小 4944 = 206×24） |
| 扩展名字符串 | 32 B 步长表，`0x293fb8`…`0x2956a8`；**有空槽**（首个空槽 `0x294a18`，可容纳 25 B 的名字） |
| `glGetString` / `glGetStringi` | `0x6c800` / `0x70650` |
| `__glGetProcAddr` | `0xe4348`：两张 name→func 表（表 A 记录 24 B，头 `0x379c50`、首条 `0x379c68`；表 B 记录 16 B，count/基址由 GOT `0x36a830` / `0x36b358` 取） |

**为什么不能只改表**：表 A 记录里的 `func` 字段在**文件里恒为 0**（运行时才填充），
因此无法静态插入一条可用入口；而 `__glExtension` 已满，只能"顶掉"某个现成扩展 —— 那会
反而破坏一个真实能力。要正确实现需要**新增代码**（至少一条 trampoline）与新表项。

**发现 2：EGL 的 `EGL_NATIVE_VISUAL_ID` 是「显示级」调用，与 config 无关**

```
libEGL_mwv207: eglGetConfigAttrib @0x19d70
  EGL_NATIVE_VISUAL_ID (0x302E) 分支 @0x1a0a8:
    1a0a8  ldr  x2, [x20, #8]     ; display->vtable
    1a0ac  mov  x0, x20           ; 只传 display，x1(=config 记录) 未参与
    1a0b0  ldr  x2, [x2, #48]     ; 平台级 _GetNativeVisualId
    1a0b4  blr  x2
    1a0b8  str  w0, [x24]
```

→ **40 个 config 必然报同一个 visual**（实测 `0x21`），这正是 §3.7 的根因。
对照 `EGL_NATIVE_VISUAL_TYPE`(0x302F) 分支 @`0x19e70` 读的是 `config+48`，其存的是
**位深/格式代码**（`0x10`=16bpp、`0x20`=32bpp、`0x3038`=EGL_NONE），**不是 visual id**，
因此也不能把它当作 visual 来用。

其余结构：config 记录步长 **220 B**；`eglGetConfigs` @`0x18e70`；`eglChooseConfig`
@`0x19038`；`eglCreateWindowSurface` @`0x20570` → `veglCreatePlatformWindowSurface`
@`0x1fac8`（attrib 解析在 @`0x1fb88`）。
`libGLX_mwv207` 侧 FBConfig visual 覆盖 `0x21/0x22/0x113…0x14c`（审计 §10.1）。

**为什么也不能小补丁修**：让 EGL 支持 ARGB 等窗口需要为每个 config 建立**真实的
config↔visual 映射**（现在 40 个 config 只有一个 visual），属重建数据表，不是改一个字段。

**因此**：两处都转为厂商侧需求（见 §7 反馈清单），客户端侧继续用 §3.6/§3.7 的方案兜底。

> #### ❌ 更正（2026-09-15）：上面「EGL config 覆盖率是黑窗根因」结论**被实验推翻**
>
> **实验**（`egl_force_visual.c`，本仓库新增）：无视 config 报告的 visual，直接拿
> `config[0]` 到**屏幕全部 90 个 visual** 上建 EGL window surface，并真正执行
> `eglMakeCurrent` + `glClear` + `eglSwapBuffers`：
>
> ```
> 厂商 EGL：共 40 个 config，统一使用 config[0]（其 EGL_NATIVE_VISUAL_ID=0x21）
> visual   depth class       surface  eglGetError  渲染(glClear+swap)
>   0x21     24    TrueColor   OK       -            OK
>   0x22     24    DirectColor OK       -            OK
>   0x6c     32    TrueColor   OK       -            OK     ← Flutter/GTK 偏好的 32 位 ARGB
>   ...（其余 87 个同样 OK）...
> 小结: visual 总数 90，surface 建立失败 0，可完整渲染 90
> ```
>
> **结论**：`eglCreateWindowSurface` **不做 config↔visual 匹配校验**，任何 visual 都能建成
> surface 并正常渲染/交换。`EGL_NATIVE_VISUAL_ID` 的「显示级返回 0x21」只是**查询语义的
> 简化**，并非能力限制。由此：
>
> 1. `jm_egl_visual_probe` 输出里的「无匹配 config，引擎必然失败」是**探针自身的推断**
>    （它按 `EGL_NATIVE_VISUAL_ID` 匹配后就跳过，从未真正尝试建面）——该推断不成立，
>    探针输出需按此理解（建议后续版本改为「强制用 config[0] 试建面」）。
> 2. **§3.7 的黑窗根因需重新排查** ✗：不是 EGL visual 覆盖问题；`0x7c`/`0x6c` 这类
>    ARGB visual 上的 EGL 表面实测完全可用。
> 3. 附带更正：探针报「含 `EGL_EXT_platform_x11`: no」也是**查询方式错误** ——
>    `EGL_KHR_platform_x11` / `EGL_EXT_platform_x11` 实际**存在**，但位于**客户端扩展**
>    串（`EGL_EXT_client_extensions … EGL_KHR_platform_x11 EGL_EXT_platform_x11`），
>    必须用 `eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS)` 查询。
> 4. 因此**不需要**为 EGL 侧做「重建 config↔visual 映射表」的补丁（原本的厂商需求项作废）。
>
> 复现：`gcc -O2 -o /tmp/egl_force_visual egl_force_visual.c -lEGL -lX11 -lGLESv2 && /tmp/egl_force_visual`

---

### 3.9 X11 呈现错位（带状/三角状斑块）：专有 X 驱动 ABI 补丁——已过门禁，PreInit 仍崩（2026-09-14）🚧

> 对应 `VENDOR_FEEDBACK_PRESENTATION.md`（Pure Live 侧反馈）。根因链：专有 X 驱动
> `mwv207_drv.so` 按 **DDx ABI 24** 编译，Xorg 1.21.1.16 要求 **25** → 加载失败 →
> 服务器回落 `modeset(0)` + 软件路径，DRI3 共享 pixmap 拷到显示缓冲与扫描输出之间
> **无 vblank 同步** → 30 fps 源错位斑块严重、60 fps 偶发。

**阶段 1：解析模块版本结构（4 字节补丁过 ABI 门禁）**

`mwv207_drv.so`（140 KB，**stripped**）的加载入口 `mwv207ModuleData` 在
`.data 0x317b8`，指向 `XF86ModuleVersionInfo`@`0x317d0`：

| 偏移 | 值 | 字段 |
|---|---|---|
| +0 | →`"mwv207"` | modname |
| +8 | →`"X.Org Foundation"` | vendor |
| +16/+20/+24/+28 | 4×u32 | `_modinfo` / major / minor / patch（驱动自身版本） |
| +32 | →`"X.Org Video Driver"` | **abiclass**（ABI_CLASS_VIDEODRV）|
| **+40** | **`0x00180000`** | **abiversion = (24<<16)\|0 = 24.0** ← 病灶 |
| +44 | 0 | 对齐 |
| +48 | →`"X.Org Video Driver"` | moduleclass |
| +56 | 0 | checksum |

ABI 编码是 `major<<16 | minor`（加载器按 `值>>16` 打印 "major version"）。
所以修复只需把文件偏移 **`0x217f8`** 处的 u32 从 `0x00180000` 改为 `0x00190000`。

```bash
python3 patch_xorg_abi.py /usr/lib/xorg/modules/drivers/mwv207_drv.so \
                          build-cli/mwv207_drv.so.abi25
```

**阶段 2：隔离验证（不污染当前会话）**

用 `ModulePath` 指向补丁副本、`Xorg :99 -config …` 起独立实例（当前 X 占着 DRM master，
测试实例必然失败退出，因此**对现网会话零影响**）：

| | 现象 |
|---|---|
| 原版模块（对照） | `ABI class: X.Org Video Driver, version 24.0` → `(EE) module ABI major version (24) doesn't match the server's version (25)` → `Failed to load module` → `No drivers available` |
| **补丁模块** | `ABI class: X.Org Video Driver, version **25.0**` → **ABI 门禁通过**，进入 Probe，且被识别为 `MWV207: Driver for jmgpu chipsets: JMGPU JM9200 8018` |
| 但随后 | `(EE) Backtrace: …` **`Segmentation fault at address 0x48`**（Probe/PreInit 阶段；backtrace 因无 unwind 信息无法展开） |

**结论**：**4 字节补丁已让驱动通过 ABI 门禁并被识别**；但 ABI 24→25 之间 DDX 结构
（`ScrnInfoRec`/`EntityInfoRec` 等）确有变化，PreInit 里出现 `NULL+0x48` 解引用崩溃。
（`NULL + 0x48` 这种形态更像「某接口返回 NULL 后按偏移取字段」，而非单纯字段偏移错位。）

**下一步（按风险/收益排序）**

1. ~~先上合成器缓解错位~~ **实测走不通（2026-09-14）**：合成器其实**一直在开**
   （KWin `active=true`，后端为 **XRender** 软件合成——反馈文档"无合成器"的说法需更正）。
   三种强制 OpenGL 合成的手段**全部回落 XRender**：kwinrc `[Compositing] Backend=OpenGL`
   + `reconfigure`、`Compositing.suspend/resume` 完整重建、`KWIN_COMPOSE=O2` 重启；
   且 Deepin 的 `kwin_x11` 完全抑制自身日志（`QT_LOGGING_RULES="*.debug=true"` 也只吐
   Qt 内部噪音），拿不到失败原因。GLX 侧实测**存在** visual `0x7c`（depth32 / RGBA8888 /
   depth24+stencil8）的 FBConfig——**更正审计 §10.1**（其称 GLX 只覆盖
   `0x21/0x22/0x113…0x14c`）。→ **错位的止血在合成器层面走不通**；根治仍指向专有 X
   驱动（本节 ABI 补丁路线）或厂商。注：kwinrc 已还原；开关合成的 A/B 对照可用
   `qdbus org.kde.KWin /Compositor org.kde.kwin.Compositing.suspend` / `resume`。
2. 继续逆向 ABI 24→25 的结构差异，逐个修 PreInit 崩溃点（工作量大、且修完后
   仍可能有更多不兼容点，需要可回滚环境反复重启 X 验证）。
3. 等厂商出 ABI 25 的 `mwv207_drv.so`（反馈文档 §6.1 的根治路径）。

**复现命令**（隔离环境，安全）

```bash
mkdir -p /tmp/xabi_modules/drivers
cp build-cli/mwv207_drv.so.abi25 /tmp/xabi_modules/drivers/mwv207_drv.so
# /tmp/x99.conf 里用 ModulePath "/tmp/xabi_modules" + Driver "mwv207" + BusID "PCI:7:0:0"
Xorg :99 -config /tmp/x99.conf -logfile /tmp/x99.log -novtswitch -sharevts
grep -aiE "mwv207|ABI|Backtrace|Segmentation" /tmp/x99.log
```

---

## 4. 部署

### 4.1 首次部署 / 持久化 / 回滚

```bash
cd ~/Desktop/Git/jm9100

# 当前栈检查：应只见 jmgpu
lsmod | grep -E 'jmgpu|mwv207'

# jmgpu 接管持久化（blacklist mwv207 进 initramfs + modules-load 强制加载）
sudo ./force_mode_test.sh boot && sudo reboot

# 回滚到 deepin mwv207 开源栈
sudo ./force_mode_test.sh boot-undo && sudo reboot
```

### 4.2 修改驱动源码后的标准部署流程

```bash
./sync_dkms.sh build    # = 同步源码 + dkms build --force + install --force
                        #   + update-initramfs -u（一条龙，缺一不可）
sudo reboot
```

> **红线**：`dkms install` 后**必须重建 initramfs 再重启**——开机早期
> `modules-load` 加载的是 initramfs 冻结的模块副本，否则新代码永远不生效
> （历史上多次"修复无效"的误判均由此而来）。
> 2026-09-11 又实测到一次：新模块已装到磁盘，但重启后运行的仍是 initramfs 里
> 上一版（`srcversion` 不一致），直到重建 initramfs 才恢复一致。
> 修复后的正向验证：重建 initramfs 后重启（16:40:49），运行态 `srcversion`
> 与磁盘/initramfs 完全一致（`F55C8DA4…`），即开机早期加载的确实是最新模块。
>
> initramfs 重建时 dracut 会偶发 `failed with 139` / `Segmentation fault`
> （`dracut-install` 调用的 `cp` 段错误，本机常见于 `pata_opti`、`hid-ezkey`、
> `ti-am65-cpsw-nuss`、`xhci-mtk-hcd` 等**与显存无关**的模块）——
> 它**不一定导致命令失败**，却可能静默漏拷。因此 `sync_dkms.sh build`
> 现在会自动重试一次，并**校验 initramfs 里的 `jmgpu.ko` 与磁盘模块同指纹**，
> 不一致时以非零码退出并给出处理建议。

验证运行中模块确实是新模块：

```bash
cat /sys/module/jmgpu/srcversion                                      # 运行中指纹
modinfo -F srcversion /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko  # 磁盘指纹
# 两者一致 = 新模块已生效；不一致 = 加载的是 initramfs 冻结的旧模块

# 直接校验 initramfs 内容（sync_dkms.sh build 已内置同样的检查）
sudo rm -rf /tmp/ir && mkdir -p /tmp/ir
sudo unmkinitramfs /boot/initrd.img-$(uname -r) /tmp/ir
find /tmp/ir -name 'jmgpu.ko' -exec modinfo -F srcversion {} \;
```

### 4.3 重装系统后需重做的两件事

1. 内核模块：`./sync_dkms.sh build`（+ `force_mode_test.sh boot` 持久化接管）。
2. **mpv**：应用 `mpv_dmabuf_oes_image.patch` 后重编安装（§3.3，直通必需）。
   补丁同时适用于 mpv 0.40（系统包）与 0.41：

```bash
sudo apt-get install -y build-essential devscripts dpkg-dev
cd /tmp && apt-get source mpv && cd mpv-0.40.0
patch -p1 --fuzz=3 < ~/Desktop/Git/jm9100/mpv_dmabuf_oes_image.patch
dpkg-buildpackage -b -uc -us -j$(nproc)
sudo dpkg -i ../mpv_*.deb
```

重编后必须确认 mpv 真的启用硬解（否则一切"正常"都是软解）：

```bash
libva 需要: export LIBVA_DRIVER_NAME=jmgpu
DISPLAY=:0 mpv --no-config --vo=gpu --hwdec=vaapi --frames=5 --msg-level=vo=v video.mp4 2>&1 \
  | grep -E "hardware decoding|EGL dmabuf interop|GL_RENDERER|hwdec only works"
# 期望: Using hardware decoding (vaapi)  +  Using EGL dmabuf interop via GL_OES_EGL_image
# 若出现 "VAAPI hwdec only works with OpenGL or Vulkan backends" → 补丁没生效，
# 检查 /usr/bin/mpv 的构建日期，或改用自检脚本（会显式报出是否启用硬解）
```

---

## 5. 使用方法

### 5.1 视频硬解播放（VA-API 直通）

```bash
# 直通：VA surface 经 dmabuf 零拷贝交给 GL
LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=vaapi 视频.mp4

# 走 Mesa 软栈 GL 时
LIBGL_ALWAYS_SOFTWARE=1 LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=vaapi 视频.mp4

# 兼容/排障：解码后回读到 CPU（像素同样正确，多一次回读）
LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=vaapi-copy 视频.mp4
```

应用内（purelive 等）直接配置 `hwdec=vaapi` 即可，无需再强制 `vaapi-copy`。

### 5.2 其它硬解工具

```bash
# 能力/Profile 检查
LIBVA_DRIVER_NAME=jmgpu vainfo

# ffmpeg 硬解转码
LIBVA_DRIVER_NAME=jmgpu ffmpeg -hwaccel vaapi -vaapi_device /dev/dri/renderD128 \
    -i in.mp4 -c:v libx264 out.mp4

# 校验硬解输出与软解一致（像素正确性）
ffmpeg -hwaccel vaapi -vaapi_device /dev/dri/renderD128 -i in.mp4 -f rawvideo \
    -pix_fmt nv12 - | md5sum
```

### 5.3 直通自检脚本（推荐）

```bash
cd ~/Desktop/Git/jm9100
./test_passthrough.sh            # 纯红片源自动判定直通是否正常
./test_passthrough.sh -s 720p    # 换片源分辨率（720p/360p/WxH）
./test_passthrough.sh -x         # 附加导出诊断（mmap 内容 / vaGetImage 对比）
./test_passthrough.sh -n         # 只做环境体检（模块版本、显存池占用）
./test_passthrough.sh -e '--hwdec-extra-frames=0'   # 追加任意 mpv 参数
```

判定规则：

1. **先看前提**——脚本会打印 `mpv 实际使用: Using hardware decoding (…)`。
   若提示「没有启用硬解」，说明 mpv 没走硬解（多半是未打补丁的原版 mpv），
   后面的画面判定无意义，先按 §4.3 重编 mpv；
2. `直通(vaapi)` 一行的 `avg` 应等于片源原色（脚本用纯红片 → `(255,0,0)`）；
   若为 `(0,77,0)` 之类的深绿，即仍是全零导出（回看 `-x` 的 `mmap_nz` 与
   「导出池归属」定位是缓冲问题还是 importer 问题）；
3. 若出现「不可见池缓冲的 CPU mmap 被拒」提示，说明该 importer 走的是 CPU
   采样路径（Mesa/llvmpipe）——它本来也拿不到数据（过去是全零绿屏），
   现在会被内核显式拒绝并回落 copy/软解（§3.3 补）。

> 脚本自身会设定 `LIBVA_DRIVER_NAME=jmgpu`；不设时 libva 找不到
> `jmgpu_drv_video.so`，mpv 同样会静默软解。

### 5.4 显示色彩：`gamma_norm`

灰蒙蒙的根因已按 §3.2 更正为内核 color-mgmt 契约不一致（GAMMA_LUT_SIZE
宣称 768 而驱动只消费 256）。契约修正后**默认不需要任何参数**：

```bash
# 查看当前值（契约修正后默认 1 = 原样写）
cat /sys/module/jmgpu/parameters/gamma_norm

# 运行时切换（立即生效，无需重启）
echo 1 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 1 = 原样写（默认，正确）
echo 0 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 0 = 跳过用户态 gamma（应急，亮度调节失效）
echo 3 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 3 = ×3 补偿，仅用于旧 768 契约/复现

# 诊断：ramp 契约与采样
./drm_gamma_probe /dev/dri/card0        # 期望 GAMMA_LUT_SIZE=256、GAMMA_LUT=2048 字节
sudo dmesg | grep "gamma_lut updated"   # 期望线性 0,64,128,192,255
#   若仍是 0,21,42,64,85 → 契约又被改成 768（或 gamma_norm 被设成 3）
```

### 5.5 可选内核参数（一般无需设置）

| 参数 | 说明 |
|---|---|
| `gamma_norm=1` | 默认。原样写用户态 gamma ramp（契约修正后即正确，§3.2） |
| `allow_invisible_mmap=0` | 默认。拒绝 CPU mmap 不可见池缓冲——**直通正确性依赖此默认值**（§3.3 补）；设 1 会退回"mmap 成功但读到全零"的静默错误行为，仅供复现 |
| `prefer_visible_pool=0` | 默认。厂商显存池策略（**直通已不需要改动**） |
| `prefer_visible_pool=1` | 解码 surface 优先申请 CPU 可见池（可见池空闲充足时） |
| `prefer_visible_pool=2` | 交换两池角色，可见窗口整块留给解码（可见池严重碎片化时临时用；会让桌面部分缓冲进不可见池） |
| `no_exclusive_pool=1` | 关闭不可见池（可用显存降到 255MB，极端场景排查用） |

运行时切换：`echo N | sudo tee /sys/module/jmgpu/parameters/<参数>`
（开机固定写 `/etc/modprobe.d/jmgpu-*.conf` 后 `sudo update-initramfs -u`）

### 5.6 显示诊断工具

```bash
sudo ./dump_display_regs.sh -o /tmp/reg.txt    # 关键寄存器（VA/LUT/HDMI）
sudo ./dump_full_regs.sh -o /tmp/full.txt      # 显示域全量寄存器
sudo ./fix_win_contrast.sh f0                  # WIN_CONTRAST 写回（诊断）
modetest -D /dev/dri/card0 -c                  # 查 connector
                                               # （本栈 modetest 直亮彩条点不亮属已知问题，非故障）
```

---

## 6. 交付物清单

| 路径 | 说明 |
|---|---|
| git 基线 `13de34c` | 闭源 jmgpu 1.7.0 移植到 6.6.143 的完整源码 |
| `jmgpu_nicely.c` | HDMI 无信号修复（3 处） |
| `jmgpu_package.c` | 灰蒙蒙修复：`JMGPU_LUT_ENTRIES_PER_CHANNEL` 统一 gamma LUT 契约（768→256）+ blob 长度校验 + `gamma_norm` 采样日志 |
| `jmgpu_setlayout.c` / `jmgpu_bullets.c` | dmabuf 导出链修复（尺寸对齐/NULL-SGT/越界）+ **拒绝不可见池的 CPU mmap** + 同驱动导入快捷路径 `jmgpu_dmabuf_peek_node()` + 诊断日志（`jmgpu-exp` / `jmgpu-mmap` / `jmgpu-diag` / `refusing CPU mmap`） |
| `jmgpu_insert.c` / `jmgpu_detect.c` | 可选参数 `allow_invisible_mmap` / `no_exclusive_pool` / `prefer_visible_pool` |
| `mpv_dmabuf_oes_image.patch` | **mpv 直通必需补丁**（desktop GL 改走 `glEGLImageTargetTexture2DOES`；适配 0.40 / 0.41） |
| `sync_dkms.sh` | 同步源码到 DKMS + build + install + update-initramfs（一条龙） |
| `force_mode_test.sh` | 强制点屏验证与持久化接管 / 回滚（`boot` / `boot-undo`） |
| `test_passthrough.sh` | **直通一键自检**（纯色片源判定 + 导出诊断 + 环境体检） |
| `/etc/environment`（**系统配置，非本仓库文件**） | 追加 `__GLX_VENDOR_LIBRARY_NAME=mwv207`：修复 pkexec 提权应用（EasyTier GUI 等）白屏（§3.5） |
| `jm_gl_compat.c` | **用户态 GL 兼容层**（LD_PRELOAD）：补齐 `GL_EXT_EGL_image_storage` 并把 storage 入口重定向到可用的 OES 入口，使**未打补丁**的应用也能 VA-API 零拷贝直通（§3.6） |
| `build_gl_compat.sh` | 编译/安装/卸载上述兼容层（含导出符号自检） |
| `test_gl_compat.sh` | **兼容层一键验证**：扩展广告 → 未打补丁 mpv 的 direct 判定 → 直通画面像素（区分全零绿屏） |
| `jm_egl_visual_probe.c` | **EGL visual 能力探针**：枚举 X visual 并 dump config 属性（`-a`）。⚠️ 其输出中的「无匹配 config，引擎必然失败」是**探针自身推断**，已于 2026-09-15 被实测推翻（§3.7 文末更正），勿再作为结论使用 |
| `egl_force_visual.c` | **EGL visual 强制建面探针（2026-09-15 新增）**：无视 config 报告的 visual，用 `config[0]` 在屏幕**全部 visual** 上建 window surface 并真正 `glClear`+`eglSwapBuffers`。实测 **90/90 全通过** —— 据此推翻 §3.7 原结论 |
| `patch_gl_storage.py` | **原生 `GL_EXT_EGL_image_storage` 补丁（2026-09-16 新增，§9）**：给 `jmgpu_dri.so`（扩展广告）+ `libGLX_mwv207.so` / `libEGL_mwv207.so`（入口别名）做纯字节补丁，把 `glEGLImageTargetTexStorageEXT` 接回可用的 OES 实现。内置空区/唯一重定位/文件尺寸三类断言 |
| `install_gl_storage.sh` | 上述补丁的**安装 / 回退 / 状态**脚本（`install` / `revert` / `status`），始终从原件生成补丁（幂等），备份于 `/var/backups/jm9100-glstorage/` |
| `jm_gl_storage_test.c` | **A/B 端到端探针**：EGL+pbuffer + jmgpu dumb buffer→dmabuf→EGLImage，对照 `glEGLImageTargetTexture2DOES` 与 `glEGLImageTargetTexStorageEXT` 的纹理绑定结果（补丁后两者均 `256x128`） |
| `jm_gl_ext_dump.c` | 扩展广告探针：打印 `GL_EXTENSIONS` 串与 `GL_NUM_EXTENSIONS`，用于确认补丁只等价替换了 1 个重复扩展、总数与串长不变 |
| `jmgpu_crosstab.c`（`_DmabufGetSGT`） | **内核第二处 `.GetSGT` 空桩修复（2026-09-16，§9.2）**：Dmabuf（外部 dmabuf 导入）分配器按 `j9_lactant()` 约定派生子区间 sg_table，缓存于 `j9_camaron->sub_sgt` 并在 Free 时释放 |
| `docs/应用侧交付与测试清单.md` | **交付给应用侧的说明与测试清单**：测试环境基线、系统层改动清单（含回退）、应用侧三项注意（GL vendor 变量 / vsync 语义 / VA-API 零拷贝接入）、逐项测试项与判据、黑窗问题采集模板、已知限制与问题回报模板 |
| `patch_xorg_abi.py` | **X 驱动 ABI 补丁**：把 `mwv207_drv.so` 的 `XF86ModuleVersionInfo.abiversion` 从 24.0 补到 25.0（对副本操作，4 字节），使其能被 Xorg 1.21 加载（§3.9） |
| `drm_gamma_probe.c` | **gamma 契约探针**：读 CRTC 的 `GAMMA_LUT_SIZE` 以及当前 `GAMMA_LUT` blob 的项数与内容（定位灰蒙蒙根因用，§3.2） |
| `jmgpu_reload_test.sh` | **卸载/重载 + S3 验证脚本**（须在 SSH/TTY 中跑，自带恢复桌面与回滚，§3.4） |
| `jm_dmabuf_cycle.c` | dmabuf 导出→同驱动导入→释放 循环压测与泄漏检查（无需 root，§3.3 相关） |
| `va_export_probe.c` | VA 导出保真度探针（`vaPutImage`→导出→逐字节比对） |
| `va_export_diag.c` | LD_PRELOAD 导出诊断（mmap 内容 vs `vaGetImage`） |
| `jm_gem_probe.c` | 内核 GEM 导出双向校验（CPU↔dmabuf 交叉比对、pagemap） |
| `jm_dumb_probe.c` | dumb/GEM `mmap()` 通路探针（`CREATE_DUMB`/`MAP_DUMB`/`mmap` 三态 + 读写回环），用于区分「滑动窗口可用」与「dmabuf 路径静默全零」（§3.3 补） |
| `bar_probe.c` | 验证其它 PCI BAR 是否也是显存窗口 |
| `ppm_stats.py` / `passthrough_verify.py` | 截图取色判定直通画面 |
| `dump_display_regs.sh` / `dump_full_regs.sh` / `fix_win_contrast.sh` | 显示域寄存器 dump 与写回（诊断） |
| `color_bisect.sh` / `check_jmgpu_display.sh` / `diag_jmgpu_fail.sh` | 色彩/显示排查辅助脚本 |
| `backup/README.2026-09-10.md`、`backup/FIXLOG.2026-09-10.md` | **合并前的原始文档备份**（完整排查过程与已排除方案） |

> 参考仓库：
> - 闭源：景美官网 dkms 1.7.0
> - 开源内核：`github.com/Icenowy/mwv207-dkms`
> - 官方 6.6：`gitee.com/jemoic/Jemoic-OpenHarmony-code-source`
> - GL：`github.com/everything411/mesa-mwv207`、`gitee.com/jemoic/mesa`

---

## 7. 结论与后续建议

**软件层正解已达成**：本仓库补丁版闭源 jmgpu 1.7.0 在 Deepin 25 / 6.6.143 上
**显示（无灰滤镜）+ GL + VA-API 硬解直通全功能可用**，无需 UOS。

后续建议：

1. **保持本仓库栈**：DKMS 已装补丁版 `jmgpu.ko`；持久化 = `force_mode_test.sh boot`
   （blacklist mwv207 + modules-load 强制加载 jmgpu），回滚 = `boot-undo`。
   改驱动源码后务必 `./sync_dkms.sh build` 再重启（含 initramfs 重建）。
2. **直通的两条路（二选一即可）**：
   - **系统级（推荐）**：`./build_gl_compat.sh install`，再用
     `LD_PRELOAD=/usr/lib/aarch64-linux-gnu/libjm_gl_compat.so` 启动播放器 ——
     未打补丁的应用也能进入 direct（§3.6）；
   - **应用级**：给 mpv 打 `mpv_dmabuf_oes_image.patch` 后重编（§4.3），
     升级 mpv 后需重新应用。
3. **`/etc/environment` 不可丢**（§3.5）：`__GLX_VENDOR_LIBRARY_NAME=mwv207`
   必须**同时**存在于
   - `/etc/profile.d/mwv207_glvnd.sh`（登录 shell / 桌面会话应用），与
   - `/etc/environment`（PAM 会话，含 `pkexec` 提权的应用）。

   驱动的安装脚本目前**只写了前者**，凡"自我提权"的应用（EasyTier GUI 等）
   都会白屏。重装系统或重装驱动包后需重新确认这两处都在。
4. **向景美反馈的五点**（附本 README §3.3 / §3.5 / §3.7 数据即可复现）：
   - ~~`glEGLImageTargetTexStorageEXT` 入口存在但未真正挂接 dmabuf，建议实现或
     不要声明 `GL_EXT_EGL_image_storage`~~ → **本仓库已原生补齐（§9，2026-09-16），
     该项仍建议厂商在源码层实现（当前是二进制补丁，驱动升级后需重打）**；
   - reserved-mem（VRAM）分配器的 `.GetSGT` 为空桩，导致标准 `map_dma_buf`
     导入必然失败；
   - 解码 surface 池整体按"一块连续显存"申请，在可见窗口碎片化时整组回退到
     CPU 不可见池，建议改为按需分块或非连续分配；
   - **X 驱动应通过 `GLX_EXT_libglvnd` 通告 libglvnd vendor 名 `mwv207`**（当前
     报的是 Xorg 默认的 `mesa`）。否则凡经 `pkexec`/纯净环境启动的 WebKit、
     Chromium、GTK 程序都会让 glvnd 回落到 Mesa 而崩溃（§3.5 有完整复现与对照）；
     另外驱动安装脚本应把 `__GLX_VENDOR_LIBRARY_NAME` 同时写入 `/etc/environment`；
   - ~~**EGL 的 config 集合只覆盖屏幕的 1 个 visual（实测 `0x21`，其余 89 个 visual
     全部无 config）**，建议覆盖屏幕的全部 visual……~~ → **该项已作废（2026-09-15）**：
     实测 `eglCreateWindowSurface` **不做** config↔visual 匹配校验，屏幕 **90/90 个 visual**
     都能建面并完成 `glClear`+`eglSwapBuffers`（见 §3.7 文末更正）。
     即**不需要**厂商为 EGL 重建 config↔visual 映射表。
5. **向景美/deepin/飞腾反馈 SCDC 修复**：同源代码在所有 6.x 内核上都有该问题，
   §3.1 的补丁可直接回给厂商。
6. （可选）纯开源路线：Icenowy / 官方 6.6 内核显示可用但解码用户态仍缺失，
   需自写 VA driver 对接 `pipe_dec`，工作量大，现阶段无必要。

---

## 8. 2026-09-15 续：专有 X 驱动打通、GL 可用性与显示性能调优

> 承接 **§3.9**（ABI 24→25 已过门禁，但清理路径仍崩）。
> 本节记录当日完成的修复、**系统改动清单**、实测数据与已排除方案；所有改动均给出回退方式。

### 8.1 结果概览

| # | 问题 | 状态 | 关键动作 |
|---|---|---|---|
| 7 | 专有 X 驱动无法加载（崩溃） | ✅ 已解决 | `mwv207_drv.so.abi25.fixed3`（ABI + `ScrnInfoRec` 布局双补丁） |
| 8 | 桌面/应用卡顿：GL 垂直同步等待每帧超时 ~1s | ✅ **已修复（内核参数）** | `drm.vblankoffdelay=0`：vblank 中断不再被内核自动关闭 → 1.000 FPS → ~14,000 FPS（详见 §8.9） |
| 9 | KWin GL(`gl2`) 合成送显仅 ≈8fps | ✅ 已规避 | dconfig `user_type=4`（XRender 合成，实测 60fps；vblank 修复后仍如此，详见 §8.9） |
| 10 | 任务栏（dde-shell）掉帧 | ✅ 已规避 | `/usr/bin/dde-shell` 包装：GLX/EGL 改走 Mesa(CPU) |

**结论**：专有 DDX 正常工作、GL 应用硬件加速可用（1.3–1.8 万 FPS）；仍有两类厂商驱动缺陷只能绕过（§8.5）。

### 8.2 系统改动清单（当前生效）

| 位置 | 改动 | 原因 | 回退 |
|---|---|---|---|
| `/usr/lib/xorg/modules/drivers/mwv207_drv.so` | 替换为 `build-cli/mwv207_drv.so.abi25.fixed3`（md5 `297aee83…`） | ① ABI 版本 24→25（`patch_xorg_abi.py`）；② Xorg 1.21 删除 `xf86str.h` 的 `Bool flipPixels` → 其后字段整体 **−8 字节**，回调槽错位使 `xf86DeleteScreen` 误调 LeaveVT，读未初始化的 `pScrn->pScreen` → `NULL+0x48` 段错误（`build-cli/patch_abi_layout.py`） | 从驱动包恢复原始 `mwv207_drv.so` |
| `/etc/tmpfiles.d/drm-vblank.conf` + `/etc/systemd/system/drm-vblank-fix.service` | 每次开机把 `drm` 模块参数 `vblankoffdelay` 写为 **0** | **缺陷#1 的根治**：内核默认在最后一个 vblank 使用者释放后 5000ms 关闭 vblank 中断，厂商驱动无法重新使能 → 客户端等待永远超时（1s）。写 0 = 永不自动关闭（见 §8.9） | `sudo systemctl disable --now drm-vblank-fix.service`；`rm /etc/systemd/system/drm-vblank-fix.service /etc/tmpfiles.d/drm-vblank.conf`；`echo 5000 > /sys/module/drm/parameters/vblankoffdelay` |
| `/etc/environment` | 追加 `vblank_mode=0` | **缺陷#1 的旧规避**（已被 §8.9 的内核修复取代，可保留作双保险） | 删除该行（备份：`/etc/environment.bak-20260915-113720`） |
| `/etc/profile.d/zz-vblank.sh` | 新增 `export vblank_mode=0` | 同上，覆盖终端/命令行启动的 GL 程序 | `sudo rm /etc/profile.d/zz-vblank.sh` |
| dconfig `org.kde.kwin.compositing:user_type` | `1`(OpenGL) → **`4`**(XRender) | 同款应用 1920×1080 录屏逐帧去重实测：`gl2` 合成 **40/301 帧（≈8fps）** vs `XRender` **237/301（≈47fps）** | `dde-dconfig set -a org.kde.kwin -r org.kde.kwin.compositing -k user_type -v 1` |
| `/usr/bin/dde-shell` | 改为包装脚本（原厂二进制备份为 `dde-shell.real`，md5 `03e036d3…`） | 任务栏是 Qt Quick 高频重绘，走厂商 GL 明显掉帧（§8.10：`gl2` 仅 1–11 fps）。~~且厂商 EGL 建窗口 surface 必然失败（§3.7）~~ → 该 EGL 归因已于 2026-09-15 实测**推翻**（§3.7 文末更正）。包装内设 `__GLX_VENDOR_LIBRARY_NAME=mesa`、`__EGL_VENDOR_LIBRARY_FILENAMES=…/50_mesa.json`、`QT_XCB_GL_INTEGRATION=xcb_glx` → GLX/EGL 全部改走 Mesa(CPU) | `sudo bash ~/fix_dock_mesa.sh revert` 后注销重登 |

> 说明：以上改动**均在系统层，不涉及本仓库源码**；`/usr/share/X11/xorg.conf.d/10-mwv207.conf`
> 保持原厂默认（实验用的 `Option "TearFree" "off"` 已还原）。
> 另：X11 会话的 `DISPLAY` 会随会话重启递增（曾出现 `:2` / `:4`），脚本请勿硬编码，
> 应从 `kwin_x11` 进程的 `/proc/<pid>/environ` 读取。

### 8.3 实测数据（关键对照）

| 场景 | 结果 |
|---|---|
| `glxgears`（`vblank_mode=0`） | **13,800–18,000 FPS** ✓ |
| `glxgears`（默认开启垂直同步） | **1.000 FPS** ✗（每帧超时 1s） |
| 自写 GLX 交换测试（默认，20s） | 1758 次交换，19 次 ≈1005ms 卡死 ✗ |
| 同上 + `vblank_mode=0`（20s） | 1,292,401 次交换，**0 次卡死**，最差帧间隔 7.8ms ✓ |
| KWin 合成对照（同款应用、逐帧去重） | `gl2` **40/301** vs `XRender` **237/301** ✓ |
| 屏幕可见帧率（XRender 合成） | ≥60 fps ✓ |
| `vainfo` | jmgpu 驱动正常（H264 等 VLD）✓ |
| `jmgpu_int_ctlr` 中断（2s 采样） | 532 次 ≈266Hz —— GPU 中断本身正常 ✓ |

### 8.4 尝试过但无效 / 已回退（避免重复踩坑）

| 尝试 | 结果 |
|---|---|
| 模块参数 `fake_vblank=1`（`modinfo`：0x1=软件定时器产生 vblank） | 显式重载后确实为 1，但**驱动运行中自动改回 0** ✗（GL 仍 1 FPS） |
| DDX `Option "TearFree" "off"` | 对客户端垂直同步超时无改善 ✗（已还原） |
| `/usr/bin/kwin_x11` 包装（只让合成器 `vblank_mode=1`） | `gl2` 送显仍 0.5fps ✗（包装已卸载） |
| 单独 `__EGL_VENDOR_LIBRARY_FILENAMES=…50_mesa.json` | EGL 报错依旧 ✗（需与 `__GLX_VENDOR_LIBRARY_NAME=mesa` 同时生效才见改善） |
| `__GL_SYNC_TO_VBLANK=0` / `GL_SYNC_TO_VBLANK=0` | 厂商 GL **不识别** ✗（只有 `vblank_mode` 有效） |
| DDX `EnablePageFlip` / `VSync` 选项 | **已测 `EnablePageFlip off`**：gl2 合成 1.2 → **11.2 fps**（9 倍提升但仍远低于 XRender 的 60）；再叠加 `TearFree off` 反而降到 1.4 fps。`VSync` 未单独测。结论：**DDX 选项无法把 gl2 修到可用**（详见 §8.10） |
| 抓崩溃 shim（`/usr/local/lib/libsegv_real.so`）、登录自检、lightdm 包装 | 仅诊断用，**均已清理** ✓ |
| 怀疑"DDX 只注册了 `Solid`，2D 全走软件回退" | **误判，已排除** —— 日志完整读取后实际注册 5 项：`Solid` / `Copy` / `Composite (RENDER)` / `UploadToScreen` / `DownloadFromScreen`，2D 加速是齐的。（早先误判原因：日志每行都以 `[时间]` 开头，用 `sed '/Driver registered support/,/^\[/p'` 会在下一行就截断） |
| 怀疑 EXA 结构体在两版 Xorg 间位移导致部分注册失败 | **已排除** —— `exa.h` 的 `ExaDriverRec` 在 1.20.4 与 21.1.16 间布局完全一致（仅注释错别字与 `slave`→`secondary` 改名） |

> ⚠️ 教训：**不要用 `sed`/文本编辑工具处理 ELF 二进制**。曾误将一行 `export` 插入
> `/usr/bin/dde-shell` 开头（81 字节），内核无法执行该文件，导致桌面壳与任务栏消失；
> 恢复方式：按 ELF 魔数偏移截断（`tail -c +82`），再用 `dpkg` 记录的 md5 校验
> （`/var/lib/dpkg/info/dde-shell.md5sums`）。要改环境变量，一律改**包装脚本**。

### 8.5 向景美反馈的驱动缺陷（新增/印证，建议随 §7.4 一并提交）

1. **GL 客户端垂直同步等待超时**：vblank 事件流约 1Hz（而非 60Hz）。GPU 中断本身正常
   （2s 内 532 次 ≈266Hz）。表现：任何开启垂直同步的 GL 应用恒定 1.000 FPS。
2. **GL 合成路径性能异常**：同场景 `gl2` 合成 8fps vs `XRender` 47fps，约为 1/6。
3. ~~**印证 §3.7**：厂商 EGL 的 config 集合只覆盖 1 个 visual（实测 `0x21`），任何用
   EGL 给窗口建 surface 的客户端都会报 `Failed to initialize EglDisplay`……~~
   → **本条已撤回（2026-09-15）**：`egl_force_visual.c` 实测 **90/90 个 visual 均可建面 +
   渲染 + 交换**（§3.7 文末更正），EGL 表面本身不是瓶颈。`dde-shell` 历史上的
   `Failed to initialize EglDisplay` **真因待重查**（现已由 Mesa 包装规避）。

### 8.6 保留脚本（家目录）

| 脚本 | 用途 |
|---|---|
| `~/feel.sh`（依赖 `~/anim3`） | 屏幕真实可见帧率自测：`bash ~/feel.sh 6` |
| `~/fix_dock_mesa.sh` | dde-shell 的 Mesa 渲染包装：安装 / `revert` 还原 |
| `~/fix_dock_egl.sh`、`~/fix_dock_glx.sh` | 前两版包装（已被 mesa 版取代，可删） |
| `~/fix_kwin_vsync.sh` | kwin 包装的安装/回退（当前未使用） |
| `~/apply_restore.sh` | 按 dpkg md5 还原被文本损坏的 `dde-shell` |

### 8.7 日常自检

```bash
# 1) GL 应用是否正常（应上万 FPS）
vblank_mode=0 glxgears
# 2) 桌面合成是否满帧（≈18–20 为采样上限，实际 60）
bash ~/feel.sh 6
# 3) 合成器是否处于可用模式（期望 xrender）
qdbus org.kde.KWin /Compositor org.kde.kwin.Compositing.compositingType
# 4) VA-API 是否正常
vainfo | head -8
```

### 8.8 遗留事项

- 若将来厂商更新驱动（内核 `jmgpu.ko` / 用户态 `libGLX_mwv207.so`），可按下表复测并**回退规避项**：

  | 复测项 | 期望 | 通过后回退 |
  |---|---|---|
  | `glxgears`（开垂直同步） | ≈60 FPS | 删除 `/etc/environment` 的 `vblank_mode=0` 与 `zz-vblank.sh` |
  | `user_type=1`（gl2 合成） | ≥47 fps | 保持 `user_type=1`，删除 kwin 相关规避 |
  | `~/feel.sh` 下任务栏/启动器动画 | 明显顺滑 | `sudo bash ~/fix_dock_mesa.sh revert` |

- DDX 的 `EnablePageFlip` / `VSync` 两个选项尚未验证，可作为下一步实验方向。

### 8.9 缺陷#1 的根治：内核 `drm.vblankoffdelay=0`（2026-09-15 晚）

#### 现象指纹

| 观察 | 数值 |
|---|---|
| `glxgears`（开启垂直同步） | **前 5 秒 278 FPS → 之后恒定 1.000 FPS** |
| 自写 GLX 交换测试（20s） | 1758 次交换，其中 **19 次 ≈1005ms** 卡死 |
| GPU 中断 `jmgpu_int_ctlr` | 2s 内 532 次 ≈266Hz —— **硬件中断本身正常** |
| 加载了模块参数 `fake_vblank=1` 后 | 驱动运行中自动改回 0，无改善 |

"**恰好 5 秒后崩坏**"是关键指纹：Linux DRM 内核在最后一个 vblank 使用者释放后，
会等 `drm_vblank_offdelay`（**默认 5000ms**）然后**关闭 vblank 中断**；
内核文档明确：**该参数设为 0 = 禁用这个延迟关闭（中断长期保持使能）**。
厂商驱动显然缺少"vblank 中断重新使能"的路径，于是中断一旦被内核关掉就再也回不来，
后续所有 vblank 等待只能走满超时（1s）——与实测完全吻合。

#### 修复

```bash
# 查看（root 可读，普通用户不可读）
sudo cat /sys/module/drm/parameters/vblankoffdelay      # 默认 5000
# 修复：0 = 永不自动关闭
sudo sh -c 'echo 0 > /sys/module/drm/parameters/vblankoffdelay'
```

**持久化（本机采用双保险，见 §8.2）**：

```bash
# ① tmpfiles（开机早期写入）
echo 'w /sys/module/drm/parameters/vblankoffdelay - - - - 0' | sudo tee /etc/tmpfiles.d/drm-vblank.conf
# ② systemd oneshot（等 drm 模块加载后再写一次，防止①时机过早失效）
sudo bash ~/make_vblank_persistent.sh
```

#### 修复前后实测对照

| 场景 | 修复前 | 修复后 |
|---|---|---|
| `glxgears`（开启垂直同步） | **1.000 FPS** ✗ | **13,667 / 14,872 / 14,876 FPS**，二次复测 14,899 / 15,357 FPS ✓ |
| `glxgears`（`vblank_mode=0`） | 13,800–18,000 FPS | 14,760 FPS（不变）✓ |
| KWin **XRender** 合成（同款应用 5s 录屏逐帧去重） | 237 / 301（≈47fps） | **301 / 301（60fps 满帧）** ✓ |
| KWin **gl2** 合成（同款应用） | 40 / 301（≈8fps） | **6 / 301（≈1.2fps）** ✗ 仍不可用 |

#### 结论与边界

- ✅ **缺陷#1 属内核层可控项**，一行参数即根治；`vblank_mode=0` 全局变量从此非必需（本机暂留作双保险）。
- ⚠️ 修复后 vblank 等待**不再超时，但也不做真正节流**（同步开启仍是上万 FPS）→ 即厂商 GL 的 vsync 仍未真正实现同步语义，仅不再卡死。
- ❌ **缺陷#2（GL 合成路径）不受此修复影响**：`gl2` 合成仍只有 ≈1.2fps，继续使用 `XRender` 合成（60fps）。两者成因不同，需分别反馈厂商。

#### 复测三连（验证修复是否生效/是否在重启后保持）

```bash
# ① 应上万 FPS（若为 1.000 FPS 说明参数失效）
glxgears
# ② 应 60fps 满帧
bash ~/feel.sh 6
# ③ 合成器类型应为 xrender
qdbus org.kde.KWin /Compositor org.kde.kwin.Compositing.compositingType
```

### 8.10 缺陷#2（GL/`gl2` 合成送显）专项结论：**DDX 选项无法修复，属厂商侧**

测量方法：KWin 切到 `gl2` 后，用同一段 1920×1080 高速重绘动画录屏 5 秒，逐帧校验和去重
（每个校验和不同 = 该帧真的被送显）。

| 配置 | 不同画面 / 总帧 | 有效帧率 |
|---|---|---|
| 原厂默认（TearFree 默认 on、页翻转 on） | 40 / 301 | ≈8 fps |
| 内核 vblank 修复后（原厂 DDX） | **6 / 301** | **≈1.2 fps** |
| `Option "EnablePageFlip" "off"` | **56 / 301** | **≈11.2 fps**（最佳，仍不可用） |
| `EnablePageFlip off` + `TearFree off` | 7 / 301 | ≈1.4 fps（反而更差） |
| `/usr/bin/kwin_x11` 包装（合成器单独 `vblank_mode=1`） | — | ≈0.5 fps |
| 对照：**XRender（CPU）合成** | **301 / 301** | **60 fps** ✓ |

**结论**：

1. 送显路径存在结构性瓶颈：改用"拷贝送显"（关页翻转）能带来 **9 倍** 提升，但仍被卡在 ≈11 fps，
   而同一台机器上 XRender 的拷贝路径可达 **60 fps 满帧** → 说明瓶颈在**厂商 GL 合成实现本身**
   （纹理上传/TFP/同步），不是 DDX 的页面翻转策略。
2. 该现象与缺陷#1（vblank 超时）**相互独立**：内核修复后客户端 GL 从 1.000 → 14,000 FPS，
   但 `gl2` 合成几乎无变化（8 → 1.2 fps）。
3. **工程选择**：本机固定使用 `XRender` 合成（60 fps），代价是 KWin 的 **窗口模糊（blur）特效不可用**
   （blur 需要 GL 合成），其余桌面特效（透明度、缩放、动画）不受影响。
4. 已排除项见 §8.4：EXA 注册齐全、EXA/`exa.h` 结构体两版一致 → **不是 2D 加速缺失所致**。

**待厂商确认的提问**：`gl2` 合成路径中，窗口纹理的获取（TFP / `glXBindTexImageEXT`）与
present 是否走了未优化路径？为何同一硬件上"XRender 拷贝"能到 60fps 而"GL 合成"只有 1–11fps。

### 8.11 用户态库反编译专项：推翻 §3.7 归因（2026-09-15）

> 目标：在厂商闭源用户态库上寻找可修的缺陷。结论之一是**此前认定的一个"厂商缺陷"并不存在**。
> 交付给应用侧的文档见 **`docs/应用侧交付与测试清单.md`**。

#### 可分析性（起点）

| 库 | 大小 | strip | 符号数 |
|---|---|---|---|
| `jmgpu_dri.so`（GL 实现） | 4.0 MB | **未 strip** | 完整 |
| `mwv207/libGLX_mwv207.so.1.2.0` | 789 KB | **未 strip** | 完整 |
| `mwv207/libEGL_mwv207.so.1.5.0` | 421 KB | **未 strip** | 动态 402 / 全部 1073 |

工具链：`objdump` / `readelf` / `nm` / `objcopy` / `patchelf` / `radare2` 均可用（本机）。
厂商 EGL **不是** `mesa-mwv207` 构建的（那个 Mesa 22.3.7 分支自带独立 `mwv207` gallium 驱动）；
厂商库是自研实现，UOS GCC 8.3.0 编译，走 DRI3/Present + Wayland，`NEEDED: libdrm_jmgpu.so.1.0.0`。

#### 决定性实验：`egl_force_visual.c`（本轮新增）

**方法**：无视 config 报告的 visual，直接拿 `config[0]` 到屏幕**全部 90 个 visual** 上
`eglCreateWindowSurface`，并真正执行 `eglMakeCurrent` + `glClear` + `eglSwapBuffers`。

```
厂商 EGL：共 40 个 config，统一使用 config[0]（其 EGL_NATIVE_VISUAL_ID=0x21）
visual   depth class       surface  eglGetError  渲染(glClear+swap)
  0x21     24    TrueColor   OK       -            OK
  0x22     24    DirectColor OK       -            OK
  0x6c     32    TrueColor   OK       -            OK     ← Flutter/GTK 偏好的 32 位 ARGB
  ...（其余 87 个同样 OK）...
小结: visual 总数 90，surface 建立失败 0，可完整渲染 90
```

（复现：`gcc -O2 -o /tmp/egl_force_visual egl_force_visual.c -lEGL -lX11 -lGLESv2 && /tmp/egl_force_visual`）

**结论**：`eglCreateWindowSurface` **不做 config↔visual 匹配校验**，任何 visual 都能建面并正常
渲染/交换。`EGL_NATIVE_VISUAL_ID` 的"显示级返回 `0x21`"只是**查询语义的简化**，不是能力限制。

**§3.7 的「EGL config 只覆盖 1 个 visual → 黑窗」归因据此作废**（详见 §3.7 文末更正块）；
`jm_egl_visual_probe` 的"必然失败"是其**自身推断**（匹配失败即跳过，从未真正试建面）。
**黑窗问题回到未定位状态**，需重新排查。

#### 附带更正：`EGL_EXT_platform_x11` 其实存在

`eglQueryString(display, EGL_EXTENSIONS)` 查不到它 → 它是**客户端扩展**，必须用
`eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS)` 查询，实测该串含
`EGL_KHR_platform_x11` / `EGL_EXT_platform_x11`。即应用侧用
`eglGetPlatformDisplayEXT(EGL_PLATFORM_X11_KHR, …)` 是可行的。

#### 已摸清的关键地址（`libEGL_mwv207.so.1.5.0`，供后续补丁使用）

| 项 | 地址/值 |
|---|---|
| `eglGetConfigs` / `eglChooseConfig` / `eglGetConfigAttrib` | `0x18e70` / `0x19038` / `0x19d70` |
| `eglCreateWindowSurface` → `veglCreatePlatformWindowSurface` | `0x20570` → `0x1fac8`（attrib 解析 @`0x1fb88`） |
| config 记录步长 / 基址 | **220 B** / `display+96`（索引 1-based） |
| `EGL_NATIVE_VISUAL_ID`(0x302E) 分支 | @`0x1a0a8`（**只传 display**，与 config 无关） |
| `EGL_NATIVE_VISUAL_TYPE`(0x302F) 分支 | @`0x19e70`（读 `config+48`，是位深/格式代码，非 visual id） |
| EGL 错误码 `0x3009`(BAD_MATCH) 等 | 见 `re` 记录；全库 `cmp #0x21`/`#0x22` 仅 3 处，均与 visual 白名单无关 |

> 教训（与 §8.4 同源）：**探针/脚本自身的推断必须用"真正执行目标操作"的对照实验验证**。
> 本轮两条错误结论（EGL visual、`EGL_EXT_platform_x11`）都源于"用查询结果推断能力，而没有真做一次"。

### 8.12 应用侧反馈闭环与 `glEGLImageTargetTexStorageEXT` 架构结论（2026-09-15 晚）

应用侧反馈（见 `docs/应用侧测试反馈_20260915.md`）确认：

1. **黑窗根因闭环**：purelive 历史黑窗**不是** EGL/visual 问题（与 §8.11 一致），而是**窗口未被 KWin
   接管（`managed=0`，不受合成、不可见）**——窗口管理/合成层问题，应用侧以「WM 接管自愈」修复后消除。
   `Could not wrap embedder supplied frame-buffer` 从「待定位」改标「**已解决**」。应用侧清单 §6 已同步。
2. **storage 函数：原生驱动未实现，glvnd 空桩**（反编译 + 运行时 `dladdr` 实测）：
   - `glXGetProcAddress("glEGLImageTargetTexStorageEXT")` 返回**非 NULL**，但落点是 glvnd
     `libGLdispatch.so.0` 的分发桩，**不在** `libGLX_mwv207.so` / `jmgpu_dri.so`；
   - `jmgpu_dri.so` 内**无** `glEGLImageTargetTexStorageEXT` 符号**也无**其函数名字符串；
     其 `GL_DISPATCH_TABLE` 仅 152 字节（19 槽），非全量分发表；
   - 原生栈 `glGetString(GL_EXTENSIONS)` **不广告** `GL_EXT_EGL_image_storage`（实测 `advertised = NO`）。
   → 证实 §3.8「两处缺陷属未实现，无法小补丁修复」：要修得往 `jmgpu_dri.so` getproc 注入名字+重定向，
   比 glvnd 拦截层（兼容层）更侵入。
3. **系统兼容层已安装**（2026-09-15）：`/usr/lib/aarch64-linux-gnu/libjm_gl_compat.so` 就位；
   装后 `glxinfo | grep GL_EXT_EGL_image_storage` 可见该扩展。standalone mpv/Chromium 用
   `LD_PRELOAD=.../libjm_gl_compat.so LIBVA_DRIVER_NAME=jmgpu` 即零拷贝直通。
4. **对厂商真正诉求**：实现 `glEGLImageTargetTexStorageEXT`（复用 OES 的 dmabuf 绑定即可），实现后
  兼容层可退役；GL vsync 不真正节流、gl2 合成 1–11fps 仍属厂商合成缺陷（§7.2 / §8.10）。

> **2026-09-16 更新**：上面第 4 条的 `glEGLImageTargetTexStorageEXT` **已在本轮原生补齐**（§9），
> 兼容层可退役。以下 §9 记录全部过程、代价与回退方式。

---

## 9. 2026-09-16 续：反编译补齐两处「厂商需修」缺陷（原生 `GL_EXT_EGL_image_storage` + 内核第二处 `.GetSGT` 空桩）

> 承接 **§3.6 / §3.8 / §4.4**（`glEGLImageTargetTexStorageEXT` 属"未实现，只能客户端兜底"）与
> **§7.4 厂商缺陷清单**。本轮把两处缺陷**直接在二进制/内核源码层补齐**，兼容层（`jm_gl_compat.c`）因此可退役。

### 9.1 结果概览

| # | 缺陷 | 位置 | 状态 |
|---|---|---|---|
| A | Dmabuf（外部 dmabuf **导入**）分配器 `.GetSGT` 是无条件错误返回 | 内核 `jmgpu_crosstab.c` | ✅ **已实现**（源码，`dkms build` 通过） |
| B | `glEGLImageTargetTexStorageEXT` 原生未实现（glvnd 空桩 → 纹理恒全零） | 厂商 `jmgpu_dri.so` + `libEGL_mwv207.so` + `libGLX_mwv207.so` | ✅ **已原生修复**（三库字节补丁，实测通过） |

**端到端证明**（**无 `LD_PRELOAD`、系统原版未打补丁 `mpv` 0.40**）：

```
[vo/gpu/opengl] Initializing GPU context 'x11egl'          ← mpv 默认走的是 EGL，不是 GLX
[vo/gpu/vaapi]  Using EGL dmabuf interop via GL_EXT_EGL_image_storage
$ ./test_passthrough.sh -s 720p
  直通(vaapi): 1280x720 avg=(255,0,64) 绿色占比 0.0%
  ==> 直通【正常】：画面是片源原色(红)
  mpv 实际使用: Using hardware decoding (vaapi)
```

### 9.2 缺陷 A（内核）：Dmabuf 分配器的 `.GetSGT` 空桩

§3.3 / §7.4 只记录了 **reserved-mem**（VRAM）分配器的 `.GetSGT` 空桩。反编译时发现**还有第二处**：
`jmgpu_crosstab.c` 的 Dmabuf 分配器（`dma_buf_attach()` / `dma_buf_map_attachment()` 导入外部 dmabuf）
其分配器表里 `_DmabufGetSGT` 也是**无条件错误返回**，而 `Mdl->priv`（`j9_camaron`）**本来就持有**
`j9_prismatoid()` 从 `dma_buf_map_attachment()` 得到的真实 `sgt`：

```440:447:jmgpu_crosstab.c
static j9_duopoly
_DmabufGetSGT(IN jmkALLOCATOR Allocator,
	      IN PLINUX_MDL Mdl,
	      IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes, OUT jmtPOINTER *SGT)
{

	return J9_HANDLE_J9MENU_HOMOGONIES;
}
```

> `dma_map_sgtable()` 只改 `sg_dma_address()`，`sg_page()/offset/length` 仍是导出方的真实页，
> 所以子区间可以安全地重新切片。

**修复**（`jmgpu_crosstab.c`）：按 GFP 分配器 `j9_lactant()` 的同款约定派生 `[Offset, Offset+Bytes)`
子区间 sg_table ——

1. 单个源 scatterlist 条目所描述的区域物理连续，因此每个源条目最多对应**一个**派生条目
   （`sg_set_page(d, sg_page(s), take, s->offset + in_off)`），`nents` 上界即 `orig->orig_nents`；
2. 结果缓存在 `j9_camaron->sub_sgt`（同区间可复用），在 `j9_coryphee`（Free）里 `sg_free_table()`，不泄漏；
3. 越界/空页/无条目一律 `goto fail` 释放后返回错误，绝不返回半个表。

**影响面**：修复前 `jmkOS_MemoryGetSGT()` 对导入缓冲必然失败，任何需要 sg_table 的消费方
（`DRM_JM_GEM_XFER_RECT` ioctl 喂 2D/解码引擎、dma-buf core 经 `j9_cibarious()`）都用不了导入缓冲。
修复后语义与系统内存分配器（`j9_lactant`）一致。

> 部署状态：**已 `dkms build --force` 编译通过（含 `-Werror`），未 `install`、未重启**，运行态模块未变。

### 9.3 缺陷 B（用户态）：把 `glEGLImageTargetTexStorageEXT` 接回可用的 OES 实现

#### 9.3.1 两条**互不相通**的入口解析链（本轮关键发现）

§3.8 只看了 `jmgpu_dri.so` 的 getproc 表，因此得出"必须新增代码段 + trampoline"的结论。
本轮把**实际解析链**钉死为两条（`jm_gl_storage_test.c` 实测 mpv 走的是 ②EGL 链）：

**① GLX 链**（`libGLX_mwv207.so.1.2.0`）

```
glvnd(libGL.so.1) → libGLX.so.0 → 厂商 __glvndGetProcAddress(0x6ee68)
  → glXGetProcAddress(0x28360) → glXGetProcAddressARB(0x278d8)
     第一优先：glExtApiAliasTbl @0xaaa08
               65 条 **16 B `{char *name; void *func}`**，NULL 名结尾
               （name / func 各 1 条 R_AARCH64_RELATIVE 重定位）
     回退：    由 GOT 提供表基址/count 的 16 B `{name, func}` 表（表内名字已剥掉 "gl"）
```

**② EGL 链**（`libEGL_mwv207.so.1.5.0`；**mpv / Chromium / GTK 实际走这条**）

```
libEGL.so.1 → 厂商 eglGetProcAddress(0x17700)
  名字以 "egl" 开头 → _LookupProc(表, name, skew=0)
  否则以 "gl"  开头 →
      桌面 GL(EGL_OPENGL_API) 分支：
        1) 先查 "forward_" + name  → _LookupProc(forward 表 @0x67668, skew=10)
        2) 失败 → LookupGLExtAliasApiProc(name)     ← 名字**原地改写**
        3) 再用（改写后的）name 查 _LookupProc 表 @0x63450 → @0x65838（skew=2）
      ── 第 2 步的 glExtApiAliasTbl @0x67d10：214 条 **24 B `{pattern; u64 pad; replacement}`**
         命中则把 name 改写为 replacement；`replacement == 0` 表示"砍掉末尾 3 字符"
         （`glTexImage3DOES` → `glTexImage3D`）
      ── `_LookupProc` 表是 24 B `{char *name; void *func; u64 pad}`（**func 在 +8**，
         文件内为 0、由运行时填充），按 `name + skew` 比较（skew=2 ⇒ 表内名字已去掉 "gl"）
```

**由此得到可行补丁思路**：不动函数入口、不加代码段，只做两件"数据"事 ——
**扩展广告**（`__glExtension` name_ptr 指向的字符串）与**名字改写**（别名表 pattern/replacement）。

#### 9.3.2 补丁设计（`patch_gl_storage.py`）

| # | 库 | 改动 | 为什么可行 |
|---|---|---|---|
| 1 | `jmgpu_dri.so` | 把已广告、且与 `GL_ARB_texture_rectangle` 重复的 `GL_EXT_texture_rectangle`（24 B）**等长**替换为 `GL_EXT_EGL_image_storage`（24 B） | 等长 ⇒ 扩展串总长不变、无溢出；`__glExtension[66]` 的 flags 原样保留 ⇒ **必然被广告**（该串仅被 1 条重定位引用：`r_offset=0x37c4a8`） |
| 2 | `libGLX_mwv207.so` | 牺牲早已废弃的 SGIX 视频通道别名 `glXQueryChannelDeltasSGIX`（记录 @0xaad98）：名字串（@0x6ffe0，槽位 32 B）原地改写为 `glEGLImageTargetTexStorageEXT`；其 func 相对重定位 addend 由 `0x24098` 改为本库自带 `glEGLImageTargetTexture2DOES`（`0x59970`，glapi 分发桩，与 OES 路径同一实现） | 别名表是**唯一可扩展**的 name→func 表，且表项 func 是 RELATIVE 重定位 ⇒ 只需改 addend |
| 3 | `libEGL_mwv207.so` | 牺牲 `glGetObjectParameterfvARB`（记录 @0x688c8）——该记录的 **replacement 与 pattern 是同一个字符串 ⇒ 改写恒等（空操作）⇒ 牺牲零功能损失**；把它的 pattern / replacement 两条重定位 addend 分别改指新串 `glEGLImageTargetTexStorageEXT` / `glEGLImageTargetTexture2DOES`；两条新串写入 `.rodata` 里 1030 B 零填充区（`0x3f9a0` / `0x3f9c0`） | 改写后名字变成 `glEGLImageTargetTexture2DOES`，而 `_LookupProc` 表 @0x63450（记录 @0x655e0）**已存在**该条目（func 运行时填充）⇒ 直接命中真实 OES 实现 |

三处改动**全部是"改字节 / 改既有重定位 addend"**：不新增或移动任何节、不增删重定位、文件长度不变
（脚本内置两项断言：文件尺寸不变 + 每次写入前校验目标是空区/唯一重定位）。

> ⚠️ 本轮踩坑（已修）：Python `bytearray` 的**切片赋值长度不等会改变文件长度**，从而位移其后所有
> 偏移 → 生成的 `.so` 直接损坏（`readelf` 报 `no .dynamic section`、加载即段错误）。
> 脚本现已统一"等长覆盖 + 文件尺寸断言"。

#### 9.3.3 验证

**A/B 对照探针 `jm_gl_storage_test.c`**（EGL + pbuffer + jmgpu dumb buffer 导出 dmabuf → EGLImage）：

```
GL_EXT_EGL_image_storage advertised = YES
GL_OES_EGL_image advertised         = YES
[eglimg] EGLImage ok (256x128)
  A) glEGLImageTargetTexture2DOES    level0=256x128  err=0    ← OES 路径（基准）
  B) glEGLImageTargetTexStorageEXT   level0=256x128  err=0    ← 补丁前为 0x0（空桩）
```

即 **B 与 A 行为完全一致**；补丁前后唯一差别就是"纹理被真正挂上了 dmabuf"。

**mpv 端到端（无 `LD_PRELOAD`、系统原版）**：见 §9.1 的 `x11egl` +
`Using EGL dmabuf interop via GL_EXT_EGL_image_storage`，且 `test_passthrough.sh` 判定直通正常、画面为片源原色。

**回归检查**：`glxinfo -B` → `direct rendering: Yes` / `Jingjia JM9100` / `GL 4.0 V1.7.0`；
扩展总数仍 **142**、扩展串仍 **3535 B**（等长替换的直接结果）。

### 9.4 代价清单（精确到"牺牲了什么"）

| 牺牲项 | 影响评估 |
|---|---|
| `GL_EXT_texture_rectangle` 不再广告 | 与 `GL_ARB_texture_rectangle` **功能重复**，ARB 版仍在广告；现代应用查 ARB 名 |
| `glXQueryChannelDeltasSGIX` 不再能由 getproc 解析 | SGIX **视频通道**（录像/缩放）遗留扩展，1998 年后无使用者；同组其它 SGIX 名仍在 |
| `glGetObjectParameterfvARB` 别名改写消失 | 该改写**本来就是空操作**（replacement == pattern），**零功能变化** |

### 9.5 部署与回退

```bash
cd ~/Desktop/Git/jm9100
sudo ./install_gl_storage.sh            # 生成补丁 + 备份原件 + 安装三库
sudo ./install_gl_storage.sh status     # 查看三库是否已打补丁（含 md5 对照）
sudo ./install_gl_storage.sh revert     # 从 /var/backups/jm9100-glstorage/ 还原原件
```

脚本**始终从原件（备份）生成补丁**（幂等），并自动同步硬链接副本 `/usr/lib/dri/jmgpu_dri.so`。

> 生效范围：替换后**新启动**的进程才加载补丁版（已运行进程仍持有旧 inode）；建议注销重登
> （`Xorg` / 合成器亦会重新加载）。

### 9.6 对既有文档的更正

1. **§3.8 / §4.4 的「两处缺陷属未实现，无法小补丁修复」需收敛为**：*在 `jmgpu_dri.so` 的 getproc
   表上*确实无法小补丁（表已满、func 运行时填充、需新增重定位）；但把修复落在
   **`libEGL` / `libGLX` 的别名表（名字改写）** 上就只需改数据与既有 addend —— 本轮已完成。
2. **§7.4 第 3 条可关闭**（`glEGLImageTargetTexStorageEXT` 未实现 → 兼容层兜底）：原生已可用，
   `jm_gl_compat.c`（`LD_PRELOAD`）降级为**可选冗余**，可整体退役。
3. §3.6 兼容层的保留价值：仅剩"更老/特殊应用直连 `glXGetProcAddress` 且自行判缓存"的边角场景；
   日常播放（mpv / Chromium / GTK）已不再需要。
4. 新增交付物见 §6 清单（`patch_gl_storage.py` / `install_gl_storage.sh` /
   `jm_gl_storage_test.c` / `jm_gl_ext_dump.c`）。
