# JM9100 (MWV207) GPU 驱动移植与视频硬解记录

> 平台：**飞腾 D3000 + 景嘉微 JM9100**，内核 **6.6.143-arm64-desktop-hwe (Deepin 25)**。
> 目标：把闭源 **jmgpu 1.7.0** 内核驱动移植到 6.6 并**同时**点亮显示与打通 VA-API 硬解。
>
> **最终结果（2026-09-10）：三项关键问题全部解决 ✅**

| # | 问题 | 状态 | 主要修复位置 |
|---|---|---|---|
| 1 | HDMI 无信号（内核 oops） | ✅ | `jmgpu_nicely.c` |
| 2 | 显示灰蒙蒙（低对比度） | ✅ | `jmgpu_package.c`（`gamma_norm`） |
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

**根因**：X 专有驱动 `mwv207_drv.so` 的 gamma 下发存在**固定 1/3 线性缩放缺陷**：

| 用户请求 | X 驱动下发的 ramp（采样 `[0,64,128,192,255]`） | 含义 |
|---|---|---|
| 亮度 1.0（恒等） | `0,21,42,64,85` | = in × **1/3**（85 = 255/3） |
| 亮度 0.5 | `0,11,21,32,43` | = in × 0.5/3 |

即 `out = in × brightness / 3`。原样写入硬件 LUT 后：恒等请求变成暗化表
→ 整屏"蒙灰滤镜"；亮度滑条只剩应有值的 1/3。

**定位手段**：`gamma_norm` 的采样日志（`dmesg | grep "gamma_lut updated"`）
直接打印 X 驱动下发的 ramp；并与开源栈逐寄存器对比 `WIN_CONTRAST(0x990038)`
（jmgpu `0x8000004E` 暗化表 vs mwv207 `0x800000F1` 恒等表）。

**修复**（`jmgpu_package.c`）：新增三态参数 **`gamma_norm`**（int，0644，默认 **3**）

| 值 | 行为 |
|---|---|
| **3（默认）** | 写 LUT 前 ramp **×3 归一化**（clamp 255）→ 恒等请求恢复线性表，亮度/gamma 按真实意图生效 ✅ |
| 0 | 完全跳过用户态 gamma（LUT 恒为 reset 线性表）→ 画面正常但亮度调节失效（应急） |
| 1 | 原样写（厂商原始行为）→ 复现灰滤镜缺陷 |

**验证**：灰滤镜消失，系统设置→显示→亮度滑条平滑可用；
`WIN_CONTRAST` 自动恢复 `0x800000F0`。

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
   mpv 0.40 的 `vaapi_gl_mapper_init()` 在 desktop GL 下只解析并调用
   `glEGLImageTargetTexStorageEXT`；JM9100 的该入口**存在但不真正把 dmabuf
   挂接到纹理**，纹理恒为全零。

**修复**

| 侧 | 改动 |
|---|---|
| mpv（`mpv_dmabuf_oes_image.patch`） | `video/out/hwdec/dmabuf_interop_gl.c`：desktop 分支解析出 `glEGLImageTargetTexture2DOES`(GL_OES_EGL_image) 后**优先使用并把 storage 指针置空**（init/map/unmap 三处生命周期判断随之自动走 OES 路径）；扩展检查放宽为 OES / storage 任一 |
| 内核（dmabuf 导出链） | ① reserved-mem `.Mmap` 删除 `!cpuAccessible` 拒绝分支（BAR 显存物理上始终可映射）；② 导出尺寸改 `PAGE_ALIGN()` 向上对齐；③ `.map_dma_buf` 失败改返回 `ERR_PTR`（原返回 NULL 会被解引用）；④ `mmap`/导出补越界防御（clamp 到池尾）与限流诊断日志 |
| 内核（同驱动导入） | 新增 `jmgpu_dmabuf_peek_node()`：dmabuf 由本驱动导出时（`dmabuf->ops == &_dmabuf_ops`），`j9_handle_j9_dumbbeller()` 直接复用原 VIDMEM 节点包装成 GEM 对象，绕开 reserved-mem 缺失的 `.GetSGT`（该空桩会让标准 `map_dma_buf` 导入永远失败） |

**关键认识**：改用 OES 入口后，Jingjia EGL/GL 是经 **GEM 句柄在 GPU 侧**导入
dmabuf 的，**与缓冲落在哪个池无关**。因此内核侧保持**厂商默认池策略**即可，
不需要 `prefer_visible_pool` / `no_exclusive_pool` 等参数。

**验证**（`./test_passthrough.sh -s 1080p`，纯红片源）：

```
直通(vaapi): 1920x1080 avg=(255,0,64) 绿色占比 0.0%
软解(no)   : 1920x1080 avg=(255,0,64) 绿色占比 0.0%
==> 直通【正常】：画面是片源原色(红)
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
2. **mpv**：应用 `mpv_dmabuf_oes_image.patch` 后重编安装（§3.3，直通必需）：

```bash
sudo apt-get install -y build-essential devscripts dpkg-dev
cd /tmp && apt-get source mpv && cd mpv-0.40.0
patch -p1 --fuzz=3 < ~/Desktop/Git/jm9100/mpv_dmabuf_oes_image.patch
dpkg-buildpackage -b -uc -us -j$(nproc)
sudo dpkg -i ../mpv_*.deb
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

判定规则：`直通(vaapi)` 一行的 `avg` 应等于片源原色（脚本用纯红片 → `(255,0,0)`）；
若为 `(0,77,0)` 之类的深绿，即仍是全零导出（回看 `-x` 的 `mmap_nz` 与
「导出池归属」定位是缓冲问题还是 importer 问题）。

### 5.4 显示色彩：`gamma_norm`（灰滤镜修复）

```bash
# 查看当前模式（默认 3）
cat /sys/module/jmgpu/parameters/gamma_norm

# 运行时切换（立即生效，无需重启）
echo 3 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 3 = 归一化（正常，默认）
echo 0 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 0 = 跳过用户态 gamma（应急）
echo 1 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 1 = 原样写（复现缺陷）

# 开机固定（可选）：/etc/modprobe.d/jmgpu-gamma.conf
#   options jmgpu gamma_norm=3

# 诊断：打印 X 驱动每次下发的 ramp 采样
sudo dmesg | grep "gamma_lut updated"
#   正常应为线性 0,63,128,192,255；缺陷形态为 0,21,42,64,85
```

### 5.5 可选内核参数（一般无需设置）

| 参数 | 说明 |
|---|---|
| `gamma_norm=3` | 默认。灰滤镜修复（§3.2） |
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
| `jmgpu_package.c` | 灰滤镜修复：`gamma_norm` 三态归一化 + gamma ramp 采样日志 |
| `jmgpu_setlayout.c` / `jmgpu_bullets.c` | dmabuf 导出链修复（mmap/尺寸/NULL-SGT/越界）+ 同驱动导入快捷路径 `jmgpu_dmabuf_peek_node()` + 诊断日志（`jmgpu-exp` / `jmgpu-mmap` / `jmgpu-diag`） |
| `jmgpu_insert.c` / `jmgpu_detect.c` | 可选参数 `no_exclusive_pool` / `prefer_visible_pool` |
| `mpv_dmabuf_oes_image.patch` | **mpv 直通必需补丁**（改走 `glEGLImageTargetTexture2DOES`） |
| `sync_dkms.sh` | 同步源码到 DKMS + build + install + update-initramfs（一条龙） |
| `force_mode_test.sh` | 强制点屏验证与持久化接管 / 回滚（`boot` / `boot-undo`） |
| `test_passthrough.sh` | **直通一键自检**（纯色片源判定 + 导出诊断 + 环境体检） |
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
