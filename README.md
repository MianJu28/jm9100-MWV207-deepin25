# JM9100 (MWV207) GPU 驱动移植与视频硬解记录

> 平台：**飞腾 D3000 + 景嘉微 JM9100**，内核 **6.6.143-arm64-desktop-hwe (Deepin 25)**。
> 目标：把闭源 **jmgpu 1.7.0** 内核驱动移植到 6.6 并**同时**点亮显示与打通 VA-API 硬解。
>
> **最终结果：1–5 已解决，6 已定位根因，7 阶段成果 ✅**
> （1–3 于 2026-09-10；4–7 于 2026-09-14，详见 §3.5 / §3.6 / §3.7 / §3.9）

| # | 问题 | 状态 | 主要修复位置 |
|---|---|---|---|
| 1 | HDMI 无信号（内核 oops） | ✅ | `jmgpu_nicely.c` |
| 2 | 显示灰蒙蒙（低对比度） | ✅ | `jmgpu_package.c`（GAMMA_LUT 契约 768 → 256） |
| 3 | VA-API 直通画面全绿 | ✅ | `mpv_dmabuf_oes_image.patch` + `jmgpu_bullets.c` / `jmgpu_setlayout.c` |
| 4 | EasyTier GUI 白屏（提权进程丢 GL vendor 变量） | ✅ | `/etc/environment`（§3.5，**非仓库代码**） |
| 5 | 未打补丁应用无法 VA-API 零拷贝直通 | ✅ | `jm_gl_compat.c`（用户态 GL 兼容层，§3.6） |
| 6 | 硬件 GL 栈黑窗 | 🔍 已定位 | `jm_egl_visual_probe.c` 定位根因，修复在应用侧（§3.7） |
| 7 | X11 呈现错位（专有 X 驱动无法加载） | 🚧 阶段成果 | `patch_xorg_abi.py` 补 ABI 24→25，已过门禁；PreInit 仍崩（§3.9） |

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

### 3.7 硬件 GL 栈黑窗根因：景美 EGL 的 config 只覆盖一个 visual（2026-09-14）✅ 已定位

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
| `jm_egl_visual_probe.c` | **EGL visual 能力探针**：枚举 X visual 并实测景美 EGL 能否为其建出 window surface（定位硬件栈黑窗根因用，§3.7）；`-a` 额外 dump 全部 config 属性 |
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
   - `glEGLImageTargetTexStorageEXT` 入口存在但未真正挂接 dmabuf，建议实现或
     不要声明 `GL_EXT_EGL_image_storage`（本仓库已用 `jm_gl_compat.c` 从
     客户端侧兜底，§3.6）；
   - reserved-mem（VRAM）分配器的 `.GetSGT` 为空桩，导致标准 `map_dma_buf`
     导入必然失败；
   - 解码 surface 池整体按"一块连续显存"申请，在可见窗口碎片化时整组回退到
     CPU 不可见池，建议改为按需分块或非连续分配；
   - **X 驱动应通过 `GLX_EXT_libglvnd` 通告 libglvnd vendor 名 `mwv207`**（当前
     报的是 Xorg 默认的 `mesa`）。否则凡经 `pkexec`/纯净环境启动的 WebKit、
     Chromium、GTK 程序都会让 glvnd 回落到 Mesa 而崩溃（§3.5 有完整复现与对照）；
     另外驱动安装脚本应把 `__GLX_VENDOR_LIBRARY_NAME` 同时写入 `/etc/environment`；
   - **EGL 的 config 集合只覆盖屏幕的 1 个 visual（实测 `0x21`，其余 89 个 visual
     全部无 config）**，建议覆盖屏幕的全部 visual（至少 24/32 位 TrueColor 全部）。
     这是「任何用 EGL 给窗口建 surface 的客户端」（Flutter/GTK/Chromium…）在
     景美栈上黑窗的直接原因，且 `0x21` 恰好是屏幕默认 visual —— 用别的 visual
     必挂（§3.7）。
5. **向景美/deepin/飞腾反馈 SCDC 修复**：同源代码在所有 6.x 内核上都有该问题，
   §3.1 的补丁可直接回给厂商。
6. （可选）纯开源路线：Icenowy / 官方 6.6 内核显示可用但解码用户态仍缺失，
   需自写 VA driver 对接 `pipe_dec`，工作量大，现阶段无必要。
