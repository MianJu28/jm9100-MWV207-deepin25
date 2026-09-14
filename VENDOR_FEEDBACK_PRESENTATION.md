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
