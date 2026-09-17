# JM9100 X11 呈现错位（带状/三角状斑块）反馈文档

> 反馈日期：2026-09-14
> 反馈方：Pure Live（纯粹直播）Linux arm64 维护分支
> 关联驱动仓库文档：本仓库 README §3.6 / §3.7 / §3.8、§7
> 附件：`/home/admin/Downloads/image.png`、`/home/admin/Downloads/image(1).png`、
> `/home/admin/Downloads/image(2).png`（红色线条为人工标注的错位区域，呈带状与三角状）

---

## 1. 现象

X11 会话下，视频播放窗口内出现**局部错位斑块**：

- 形态：带状（横条）与三角状（楔形）混杂交错，边界不规则；
- 内容：斑块内是**前一帧/写入中的画面内容**，与周围画面不连续（截图中红框标注）；
- 频率：**30 fps 源错位严重，60 fps 源偶发**（面板 60 Hz 时）；
- 窗口模式即出现，与全屏与否无关；直播正常播放、无崩溃。

## 2. 结论速览

- 应用侧已排除：解码/渲染节拍恒定（视频恰 30.0 fps、最大帧间隔 34 ms）、
  纹理三缓冲 + EGL fence 设计正确且 fence 实测非空壳、CPU 未饱和（单核 31%）、
  无几何/尺寸抖动、无崩溃。
- 错位发生在**呈现阶段**：GL 客户端把窗口内容经 DRI3 共享 pixmap 交给 X 服务器，
  服务器用 **glamor 软件路径**把窗口内容拷贝到显示缓冲；该拷贝与扫描输出之间
  **没有 vblank 同步**，扫描读到"写入中"的缓冲即为错位斑块。
- 关键诱因：专有 X 驱动 `mwv207_drv.so`（ABI 24）无法被 Xorg 1.21.1.16（ABI 25）
  加载，服务器回落 `modeset(0)` + 软件 glamor，**X 侧没有硬件 GLX**（DRISWRAST）；
  同时会话无合成器（`_NET_WM_CM_S0` 无人持有）。
- 客户端同步开关只能缓解：`vblank_mode=1` 减轻错位（伴随重复/回退帧），
  `vblank_mode=3` 反而更严重——说明竞争点在**服务器侧拷贝**，客户端同步无法根治。

## 3. 环境与版本

| 项 | 值 |
| --- | --- |
| 硬件 | 景嘉微 JM9100（MWV207），PCI 0731:9100 |
| 系统 | Deepin 25，Xorg 1.21.1.16（server ABI 25），lightdm，X11 |
| 内核模块 | `jmgpu`（含 `drm_kms_helper`/`drm_display_helper`） |
| 厂商用户态库 | `libGLX_mwv207.so.1.2.0`、`libEGL_mwv207.so.1.5.0`、`libgbm_jm.so`、`libGLESv1_CM_mwv207.so`（2025-10-30 构建）；`libdrm_jmgpu.so` 缺失 |
| GL / EGL | OpenGL ES 3.2 V1.7.0（`Jingjia JM9100`）；EGL 1.5 |
| 显示模式 | 1920x1080 @ 60 Hz（可选 50 / 59.94 / 74.97 / 100） |
| 合成器 | 无（KWin 进程在但 `_NET_WM_CM_S0` 无人持有） |
| 桌面 | deepin 25（dde-shell + kwin_x11） |
| 应用 | pure_live Linux arm64（commit `8ea4e28e`），media_kit 视频管线（mpv 直通硬解 + 三缓冲纹理） |

Xorg 日志关键行（`/var/log/Xorg.0.log`）：

```
(EE) mwv207: module ABI major version (24) doesn't match the server's version (25)
(EE) Failed to load module "mwv207" (module requirement mismatch, 0)
```

## 4. 复现步骤与实测

1. 构建 `pure_live`（Linux arm64）并启动，打开 30 fps 直播间
   （例：bilibili 房间 6，实测源流 `1280x720@30`）；
2. 观察 1080p 窗口：画面出现带状/三角状"上一帧内容"斑块，位置随时间变化
   （30 fps 源严重）；60 fps 源仅偶发；
3. 30 fps 屏幕录制对照：相邻帧每 5 帧出现 1 帧完全重复（4:5 节拍）；
4. 应用内部打点（`PURELIVE_MPV_STATS=1`）：视频渲染节拍恒定
   `fps=30.0, max_gap=34 ms`——**应用侧不丢帧、不限速**；
5. 纹理同步实测：向 2048x2048 FBO 提交耗时 GL 工作后立即创建
   `EGL_KHR_fence_sync` fence 并 0 超时等待，20/20 次均为"未满足"——
   **厂商 fence 语义正常**，排除 fence 空壳导致的读写竞争；
6. 同步开关 A/B（客户端侧，Mesa 派生 GLX/EGL 均识别）：

| 配置 | 结果 |
| --- | --- |
| 无同步变量（基线） | 错位明显 |
| `vblank_mode=1`（+ `__GL_SYNC_TO_VBLANK=1`） | 错位减轻；出现重复/回退帧 |
| `vblank_mode=3`（+ `__GL_SYNC_TO_VBLANK=1`） | 错位更严重 |

A/B 说明：客户端同步只作用于 **GLX 交换**；错位依旧说明竞争点在**服务器把窗口
内容拷贝到显示缓冲**的环节（软件 glamor 拷贝 vs 扫描输出），客户端等待 vblank
无法阻止服务器侧拷贝与扫描竞争；`vblank_mode=3` 的阻塞式等待反而使拷贝更频繁地
落在扫描区间内。

## 5. 一并反馈的其它驱动问题

| 问题 | 证据 |
| --- | --- |
| `glEGLImageTargetTexStorageEXT` 为空壳（glvnd 桩），mpv 的 VA-API dmabuf 互操作取 storage 分支即拒绝 | README §3.6；应用以"广告扩展 + 把 storage 入口重定向到 `glEGLImageTargetTexture2DOES`"绕过 |
| EGL config 仅覆盖单一 visual（屏幕默认 0x100 无对应 FBConfig） | README §3.7；应用需子进程探测并强制窗口 visual（本机 0x7c） |
| `gbm_jm_surface_get_free_buffer+0x48` 空指针崩溃（mpv 自建窗口 surface 时） | 调用栈：`libmpv.so.2 → libEGL_mwv207.so(+0x32a68/+0x32af4/+0x23390/+0x23bc4) → libgbm_jm.so(gbm_jm_surface_get_free_buffer)`，`si_addr=0x839` |
| `libdrm_jmgpu.so` 缺失（`/usr/lib`、`/lib` 均无），libva/GBM 探测逐次 ENOENT | strace 记录 |
| 进程内先有桌面 GL 上下文后建 EGL 上下文时，桌面 GL 未声明 `GL_EXT_EGL_image_storage` | README §3.6 |

## 6. 请厂商提供的支持（按优先级）

1. **适配当前 Xorg（1.21.1.16 / server ABI 25）的 `mwv207_drv.so`**，恢复服务器侧
   硬件加速与硬件 GLX，使窗口呈现可 vblank 同步——这是消除呈现错位的根治路径；
2. 或在 `libGLX_mwv207` 中实现 **DRI3 共享 pixmap 路径上真实生效的 swap-interval /
   vblank 等待**（`glXSwapIntervalEXT/MESA/SGI` 目前对错位无效），使客户端应用能
   自行消除撕裂；
3. 给出该环境（Deepin 25 + kwin_x11 + lightdm）下**推荐的合成器配置**
   （KWin 合成是否支持、`_NET_WM_CM_S0` 的预期行为、是否建议 picom 等）；
4. 确认 `gbm_jm_surface_get_free_buffer` 空指针崩溃与 `glEGLImageTargetTexStorageEXT`
   空壳的修复计划（见 §5）。

## 7. 数据采集命令（便于复现）

```bash
# 版本与日志
Xorg -version
grep -aiE 'mwv207|ABI|modeset|glamor|DRISWRAST' /var/log/Xorg.0.log
lsmod | grep -i jmgpu
ls -l /usr/lib/aarch64-linux-gnu/mwv207/

# GL/EGL 信息（Jingjia 栈）
DISPLAY=:0 __EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/10_mwv207.json es2_info | grep -iE 'EGL_VERSION|GL_VERSION|GL_RENDERER'

# 显示模式
DISPLAY=:0 xrandr

# 应用侧呈现节拍（pure_live 构建产物）
DISPLAY=:0 PURELIVE_MPV_STATS=1 <bundle>/pure_live   # 每 2s 打印 mpvstats: frames/fps/max_gap
```

---

备注：应用侧为绕开驱动缺口已实现三项兼容（广告 `GL_EXT_EGL_image_storage`、
`eglGetProcAddress` 重定向 storage→OES、子进程探测窗口 visual）。这些兼容只影响
mpv 的 GL 入口解析与窗口 visual 选择，不改变 X 呈现路径，与本文所述错位无因果。

---

## 8. 复测与结论更正（2026-09-16，本机当前状态）

反馈提交后，本仓库对驱动与系统栈做了多项修复，本文 §2 的**前提已不再成立**，
§6 的第 1、2、4 条诉求也已部分落地。为保证结论可用，先给复测数据，再重述嫌疑链。

### 8.1 前提已变（与 §2 的差异）

| 反馈时的前提 | 当前实测 |
|---|---|
| 专有 X 驱动 `mwv207_drv.so`（ABI 24）无法加载 → 服务器回落 `modeset(0)` + 软件 glamor | **已解决**：ABI 24→25 + `ScrnInfoRec` 布局双补丁后 **正常加载**（`Xorg.0.log`: `ABI class: X.Org Video Driver, version 25.0`），EXA 硬件加速可用 |
| X 侧无硬件 GLX（DRISWRAST） | 已恢复（DDX 加载成功） |
| 会话**无合成器**（`_NET_WM_CM_S0` 无人持有） | **有**：kwin XRender 合成，实测 60fps 满帧 |
| — | `TearFree property default: **on**`、`Present extension enabled`、`KMS Pageflipping for Present extension: **enabled**` |

### 8.2 vblank 同步能力：**实测健康**（推翻"驱动缺 vblank 重新使能"的推断）

用裸 `ioctl(DRM_IOCTL_WAIT_VBLANK)` 在多档 sequence 上测量（工具：`tools/jm_vblank_probe.c`）：

| 请求 | 实测耗时 | 60Hz 期望 |
|---|---|---|
| 相对 +1 | 16.6 ~ 17.2 ms | 16.7 ms ✅ |
| 相对 +2 | 32.7 ~ 33.3 ms | 33.3 ms ✅ |
| 相对 +5 | 82.8 ~ 83.3 ms | 83.3 ms ✅ |
| 相对 +10 | 166.7 ms | 166.7 ms ✅ |
| **绝对 +60** | **1.000 s** | 1.000 s ✅ |

即：**vblank 计数器与等待语义均正确**，`TearFree` / `Present` 翻页所需的同步原语**可用**。

> ⚠️ **测量陷阱（务必避免）**：libdrm 的 `drmVBlank` 是 **union**，
> `drmWaitVBlank()` 回填 `reply` 时会覆盖同一个 `request.type` 字段；
> 若在循环中复用同一结构体且只重设 `sequence`，第二次起 `type` 已被计数污染，
> 表现为"等待不阻塞"的**假象**。本仓库探针因此改用裸 ioctl。
> 早前据此推出的「厂商驱动缺少 vblank 中断重新使能」结论**作废**。

### 8.3 因此，错位斑块的首要嫌疑改为"内容一致性"而非"扫描撕裂"

在 vblank 可靠、TearFree 开启、且有合成器的当前状态下，"拷贝与扫描竞争"已不易成立；
与现象描述（**斑块内是前一帧/写入中的画面内容**、边界呈带状与楔形）更吻合的是
**内容一致性**问题，按优先级：

1. **主平面寄存器更新缺少 vblank 同步（最具体、可直接验证）**：`atomic_update` 路径
   （`jmgpu_console.c` 的 `j9_handle__attribute_chalkstone()`，经 `j9_handle_j9min_dichlorvos()`
   调用）把**步长 → 尺寸 → 基址**直接写进显示寄存器，不区分是否处于扫描期间。
   若提交恰落在扫描中，本帧后半段就会用新步长（→ 横向错切，成**楔形/三角**）与新基址
   （→ 读到缓冲别处的**更早画面**）。这与"**三角状错位 + 有时重复之前片段**"的实测描述完全吻合，
   也解释了其**间歇性**。本仓库已给出可选修复开关 `update_at_vblank`（默认关，置 1 把该次
   编程推迟到下一次 vblank 落地），可直接做 A/B 判定。
   **请厂商确认：该芯片组的图形窗口寄存器是否具备"影子寄存器/下一场生效"位，
   以及基址+步长是否应作为一组原子地在该时机生效。**
2. **栅栏未挂到缓冲、且无 fence fd 导出（导致"渲染完成 ↔ 扫描输出"无法同步）**：
   驱动内部**有**栅栏/时间线实现（`jm_fence_create()` / `dma_fence_init()` /
   `dma_fence_signal_locked()`）与 `JM_J2D_WAIT_IDLE` 等待原语，但：
   - **从不把作业栅栏挂到缓冲的 `dma_resv`**（全库无 `dma_resv_add_fence/_excl_fence`）；
   - **无 fence fd 导出**（构建定义了 `-DJMD_LINUX_SYNC_FILE=1`，却无任何源码使用；
     亦未使用 `sync_file` / `drm_syncobj`）；
   - 平面未实现 `.prepare_fb` / `.cleanup_fb`。

   后果：DRM 核心在翻页前的 `drm_atomic_helper_wait_for_fences()` **无栅栏可等**，
   于是「2D 合成/GL 写完 → 翻页扫出」只能靠时序碰运气，**负载越高越易撞上** ——
   这正是"楔形块 + 重复上一帧内容"且**间歇出现**的成因。
   **请厂商**：(i) 作业提交时把完成栅栏挂到目标 `dma_buf`/GEM 的 `dma_resv`；
   (ii) 提供 fence fd（`sync_file`/`drm_syncobj`）导入导出，打通 DRI3/Present 与
   EGL/dmabuf 互操作；(iii) 由于 `DRM_JM_J2D_SEND_CMD` 只传不透明命令流，
   内核无法得知目标缓冲，建议在提交接口上显式带上目标 handle。
3. **帧缓冲压缩 / TS（Tile Status）状态维护不完整**：驱动的 `compression` 参数注释即
   *"Disable compression if set it to 0, enabled by default"*，本机该值当前为 **15（开启）**。
   瓦片状态记录"该瓦片是否压缩/清空"；若 2D 引擎或 CPU 写入某缓冲后**未正确失效/刷新
   瓦片状态**，显示侧会读到**上一帧的旧瓦片内容**。由于瓦片在内存中**不按光栅顺序**排布，
   未更新瓦片在屏幕上呈**不规则块 / 阶梯 / 楔形**，且**仅在状态不一致时出现** ——
   与"三角状错位 + 有时重复之前片段"高度吻合，且与 ① 的寄存器时机是**两个独立成因**
   （故仅修 ① 只能减轻）。**请厂商确认**：在扫描缓冲的写入路径（2D/EXA 合成、CPU 上传）
   上是否完整执行了 Tile Status 的失效/刷新；并确认 `compression=0` 下是否**完全**禁用
   该路径（供我们作为规避手段）。
4. 扫描撕裂（TearFree 失效）—— 已不是首选：vblank 语义实测正确（§8.2），TearFree 亦为开启状态。

### 8.4 复现与取证命令（当前栈）

```bash
# 一、vblank 同步能力（应全部与 60Hz 期望一致）
gcc -O2 -I/usr/include/libdrm -o /tmp/jm_vblank_probe tools/jm_vblank_probe.c
/tmp/jm_vblank_probe 30

# 二、X 侧呈现路径是否仍是预期（TearFree / Present / pageflip）
grep -aiE 'TearFree|PageFlip|Present|EXA|DRI3' /var/log/Xorg.0.log | grep -av Modeline

# 三、合成器类型（应为 xrender）
qdbus org.kde.KWin /Compositor org.kde.kwin.Compositing.compositingType

# 四、VA-API 零拷贝直通仍正常（排除解码链路回归）
./scripts/test_passthrough.sh -s 360p
```

### 8.5 对 §6 诉求的更新

- 第 1 条（适配 ABI 25 的 `mwv207_drv.so`）：**已由本仓库补丁打通**；仍建议厂商发布官方 ABI 25 版本。
- 第 2 条（DRI3 共享 pixmap 上真实生效的 swap-interval/vblank 等待）：vblank 原语本身健康，
  但**客户端 GL 的 vsync 仍未真正节流**（同步开启实测上万 FPS），该条**继续有效**。
- 第 3 条（推荐合成器配置）：当前 kwin **XRender** 合成为满帧方案；`gl2` 合成仍不可用（§8.10）。
- 第 4 条（`gbm_jm_surface_get_free_buffer` 崩溃 / `glEGLImageTargetTexStorageEXT` 空壳）：
  后者**已由本仓库原生补丁解决**并实测通过（`glEGLImageTargetTexStorageEXT` 绑定 dma-buf
  纹理 `err=0`、尺寸正确）；前者**仍请厂商确认**。

---

## 9. 2026-09-16 下午：两条**相互独立**的新缺陷（含可复现矩阵）

### 9.1 【新】`compression` 与 `fastClear` **同时为默认(开)** ⇒ 卡顿 + **内核任务态被破坏**

在本机（JM9100 / aarch64 / 内核 6.6.143）以 boot 期 `modprobe.d` 只改这两个参数做 A/B，
同一模块、同一环境：

| `compression` | `fastClear` | 桌面表现 | 内核日志 |
|---|---|---|---|
| 15（默认=开） | -1（默认=开） | **卡顿** | **`note: cp[..] exited with irqs disabled` / `exited with preempt_count 1`**；`cp` 以 139(SIGSEGV) 退出（`update-initramfs` 的 plymouth hook 因此失败） |
| 0（关） | 默认(开) | 正常 | 无异常 |
| 15（开） | 0（关） | 正常 | 无异常 |

- 同一条 `cp` 命令手工复跑（目标 `/tmp`）返回 0 ⇒ 与 coreutils 无关；
- 判定：**Z-compression 与 fastClear 同时启用**时，驱动/硬件路径会破坏内核任务状态
  （抢占计数/中断状态泄漏），并伴随整机卡顿；任一关闭即恢复。
- 相关寄存器：`AQ_MEMORY_DEBUG.DISABLE_FAST_CLEAR` / `DISABLE_ZCOMPRESSION`
  （`jmkHARDWARE_SetFastClear()`，由上述两个参数驱动）；`AHBDEC_CONTROL` /
  `AHBDEC_CONTROL_EX2.TILE_STATUS_READ_ID=4 / WRITE_ID=2`（硬编码常量，
  `jmgpu_calendar.c:2806-2827`）。
- **请厂商确认**：为何该组合会破坏任务态；`TILE_STATUS_READ_ID/WRITE_ID` 的硬编码常量
  与用户态 `DRM_JM_GEM_ATTACH_AUX` 各自挂载的 `ts_handle` 之间应有何契约。

### 9.2 画面分块/三角错位：**写扫描缓冲的路径与扫描输出之间没有栅栏**

X 侧逐项 A/B（各改 `/usr/share/X11/xorg.conf.d/10-mwv207.conf` 后注销重登；同时打开
本仓库两个时序缓解参数 `update_at_vblank=1` + `flip_waits_2d_idle=1`）：

| 选项 | 观测 | 指向 |
|---|---|---|
| `EnablePageFlip off` | 三角错位不变 | 与翻页机制本身无关 |
| `TearFree off` | 三角错位**明显减少**，出现撕裂 | 三角错位主要来自 DDX「合成→扫描缓冲」拷贝与扫描竞争（2D XFER_RECT） |
| `Present off` | 撕裂减少，出现**画面回退**（闪回旧帧） | 缺栅栏：换提交路径只是换症状 |
| `DRI3 off` | 三角错位不变 | 与 DRI3 直翻无关 |
| 再换一个视频源 | 两组都仍有三角错位，`TearFree off` + 两缓解那组**最轻** | ⇒ 写入方**不限于** TearFree 拷贝，而是**任何**写扫描缓冲的路径 |

**诉求（对应 §6 第 2 条，本次给出更明确的落点）**：
1. 平面补 `.prepare_fb` / `.cleanup_fb`，并把 2D / GL / 解码作业的栅栏挂到缓冲的
   `dma_resv`，同时提供 fence fd（`sync_file` / `drm_syncobj`）导出 —— 让 DRM 核心的
   `drm_atomic_helper_wait_for_fences()` 在翻页前真正等到"渲染完成"；
2. 或提供"按目标缓冲等待 2D 完成"的接口（本仓库只能做到"等引擎全局空闲"）。

### 9.3 已**证伪**的假设（请勿再按此方向排查）

- **"非线性(瓦片/TS)缓冲被直线扫描"**：本仓库新增的核内诊断（`fb_create` 与主平面
  `update` 处检查 `tilingMode / tsMode / tsNode`）在 `compression=15`（压缩开启）下
  **零命中** ⇒ 用户态并未给扫描缓冲挂 TS，扫描缓冲始终线性无 TS；
- **"翻页机制本身"**、**"DRI3 直翻"**：见 9.2 的 A/B。

### 9.4 本机当前可用规避（已验证，非根治）

```bash
# 1) 避开 9.1 的坏组合（二选一）
echo 'options jmgpu compression=0' | sudo tee /etc/modprobe.d/jmgpu-nocompress.conf
#   或： echo 'options jmgpu compression=15 fastClear=0' | sudo tee /etc/modprobe.d/jmgpu-comp-fc.conf
sudo update-initramfs -u && sudo reboot

# 2) 把 9.2 的错位压到最轻（本仓库两个时序缓解，运行时可切）
echo 1 | sudo tee /sys/module/jmgpu/parameters/update_at_vblank
echo 1 | sudo tee /sys/module/jmgpu/parameters/flip_waits_2d_idle
# 3) X 侧：Option "TearFree" "off"（代价：出现普通撕裂）
```
