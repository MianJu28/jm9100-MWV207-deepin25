# JM9100 (MWV207) GPU 驱动移植与视频硬解记录

> 平台：**飞腾 D3000 + 景嘉微 JM9100**，内核 **6.6.143-arm64-desktop-hwe (Deepin 25)**。
> 目标：把闭源 **jmgpu 1.7.0** 内核驱动移植到 6.6 并**同时**点亮显示与打通 VA-API 硬解。
>
> **最终结果（2026-09-10）：三项关键问题全部解决 ✅**

| # | 问题 | 状态 | 主要修复位置 |
|---|---|---|---|
| 1 | HDMI 无信号（内核 oops） | ✅ | `jmgpu_nicely.c` |
| 2 | 显示灰蒙蒙（低对比度） | ✅ | `jmgpu_package.c`（GAMMA_LUT 契约 768 → 256） |
| 3 | VA-API 直通画面全绿 | ✅ | `mpv_dmabuf_oes_image.patch` + `jmgpu_bullets.c` / `jmgpu_setlayout.c` |

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
   1776MB 不可见池。不可见池的"CPU 物理地址"只是驱动 `request_mem_region`
   的占位地址，**没有任何宿主桥解码**：`mmap()` 会成功返回，但读恒为 `0x00`、
   写被静默丢弃。
2. **mpv 的导入入口选错。**
   mpv（0.40/0.41）的 `vaapi_gl_mapper_init()` 在 desktop GL 下只解析并调用
   `glEGLImageTargetTexStorageEXT`；JM9100 的该入口**存在但不真正把 dmabuf
   挂接到纹理**，纹理恒为全零（JM9100 只声明 `GL_OES_EGL_image`，不声明
   `GL_EXT_EGL_image_storage`）。

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
>
> initramfs 重建若报 dracut `138/139` 段错误属**偶发**，重试一次即可。

验证运行中模块确实是新模块：

```bash
cat /sys/module/jmgpu/srcversion                                      # 运行中指纹
modinfo -F srcversion /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko  # 磁盘指纹
# 两者一致 = 新模块已生效；不一致 = 加载的是 initramfs 冻结的旧模块
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
| `drm_gamma_probe.c` | **gamma 契约探针**：读 CRTC 的 `GAMMA_LUT_SIZE` 与当前 `GAMMA_LUT` blob 项数（定位灰蒙蒙根因用，§3.2） |
| `va_export_probe.c` | VA 导出保真度探针（`vaPutImage`→导出→逐字节比对） |
| `va_export_diag.c` | LD_PRELOAD 导出诊断（mmap 内容 vs `vaGetImage`） |
| `jm_gem_probe.c` | 内核 GEM 导出双向校验（CPU↔dmabuf 交叉比对、pagemap） |
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
2. **mpv 补丁不可丢**：直通依赖 `mpv_dmabuf_oes_image.patch`，升级 mpv 后需重新应用。
3. **向景美反馈的三点**（附本 README §3.3 数据即可复现）：
   - `glEGLImageTargetTexStorageEXT` 入口存在但未真正挂接 dmabuf，建议实现或
     不要声明 `GL_EXT_EGL_image_storage`；
   - reserved-mem（VRAM）分配器的 `.GetSGT` 为空桩，导致标准 `map_dma_buf`
     导入必然失败；
   - 解码 surface 池整体按"一块连续显存"申请，在可见窗口碎片化时整组回退到
     CPU 不可见池，建议改为按需分块或非连续分配。
4. **向景美/deepin/飞腾反馈 SCDC 修复**：同源代码在所有 6.x 内核上都有该问题，
   §3.1 的补丁可直接回给厂商。
5. （可选）纯开源路线：Icenowy / 官方 6.6 内核显示可用但解码用户态仍缺失，
   需自写 VA driver 对接 `pipe_dec`，工作量大，现阶段无必要。
