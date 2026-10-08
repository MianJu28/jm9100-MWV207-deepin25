# JM9100 (MWV207) GPU 驱动移植与视频硬解

> 平台：**飞腾 D3000 + 景嘉微 JM9100**（PCI `0731:9100`），内核 **6.6-arm64-desktop-hwe (Deepin 25)**。
> 目标：把闭源 **jmgpu 1.7.0** 内核驱动移植到 6.6，**同时**点亮显示与打通 VA-API 硬解。
>
> **当前状态：显示 ✅ · GL 硬件加速 ✅ · VA-API 零拷贝直通 ✅**
> 已在 **内核 6.6.155** 上完整验证（jmgpu 接管 PCI、`Jingjia JM9100` 约 1.7 万 FPS、直通判定"正常"）。
>
> 本文档只保留**结论、操作方法、已采用的修复与遗留问题**。
> 历史排查过程（大量已排除方案与实验数据）见 `backup/README.2026-09-17.md`（本文件重写前的完整版）
> 与 `backup/FIXLOG.2026-09-10.md`。

---

## 目录

- [0. 快速开始](#0-快速开始)
- [1. 环境与架构](#1-环境与架构)
- [2. 部署方法](#2-部署方法)
- [3. 已采用的修复](#3-已采用的修复)
- [4. 部署与切换](#4-部署与切换)
- [5. 仓库结构](#5-仓库结构)
- [6. 遗留问题](#6-遗留问题)
- [7. 给厂商的反馈](#7-给厂商的反馈)
- [8. 附录：排查经验](#8-附录排查经验)

---

## 0. 快速开始

### 从零/还原后的系统部署（详见 §2）

```bash
cd ~/Desktop/Git/jm9100

sudo ./scripts/sync_dkms.sh build          # ① 内核模块（DKMS）
sudo dpkg -i vendor/*.deb                  # ② 厂商用户态
sudo ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 \
            /usr/lib/aarch64-linux-gnu/libdrm.so.2.4.0          # ③ libdrm 链接（两处！见 §2.4）
# ④~⑥ 见 §2.5~§2.7，或直接用切换脚本：
sudo ./scripts/switch_stack.sh vendor && sudo reboot             # 一步到位（需手动重启）
```

### 日常使用

```bash
# 视频硬解直通播放（零拷贝）
LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=vaapi 视频.mp4

# 状态总览 + 一键自检
sudo ./scripts/switch_stack.sh status
DISPLAY=$(tr '\0' '\n' < /proc/$(pgrep -x kwin_x11 | head -1)/environ | sed -n 's/^DISPLAY=//p')
DISPLAY=$DISPLAY ./scripts/test_passthrough.sh -s 360p
```

### 驱动栈切换（两套栈互斥，见 §4）

```bash
cd ~/Desktop/Git/jm9100
sudo ./scripts/switch_stack.sh status    # 只读：当前跑哪套栈
sudo ./scripts/switch_stack.sh system    # 切回系统自带驱动（**系统升级前**必做）
sudo ./scripts/switch_stack.sh vendor    # 切到厂商栈（jmgpu，GL 硬件加速）
```

### 修改驱动源码后

```bash
cd ~/Desktop/Git/jm9100
sudo ./scripts/sync_dkms.sh build        # 同步源码 + dkms build/install + 重建 initramfs
sudo reboot                              # **必须重启**（见 §4.2 红线）
```

---

## 1. 环境与架构

### 1.1 环境

| 项 | 值 |
|---|---|
| CPU | 飞腾 D3000 (Phytium, aarch64) |
| GPU | 景嘉微 JM9100（`0731:9100`，子系统 `0731:9101`） |
| 内核 | 6.6-arm64-desktop-hwe（Deepin 25 定制） |
| 系统 | Deepin 25，Xorg 1.21，lightdm，X11 会话 |
| 显示 | HDMI-A-1（1080p） |

**关键事实**：

- 厂商用户态由 `com.jingjiamicro.mwv207` / `.vaapi` 两个 deb 提供：
  `jmgpu_dri.so`(GL)、`jmgpu_drv_video.so`(VA-API)、`libdrm_jmgpu.so`、专有 Xorg `mwv207_drv.so`。
- 一个 PCI 设备**只能绑定一个内核驱动**（`jmgpu` 与发行版自带 `mwv207` 互斥）。
- 显存 2048MB = **CPU 可见窗口 255MB**（BAR2）+ 不可见 1776MB。

### 1.2 两套驱动栈

| | **厂商栈（A）** | **系统栈（B）** |
|---|---|---|
| 内核模块 | 本仓库构建的 `jmgpu.ko`（DKMS） | 发行版 in-tree `mwv207`（带 `ttm`/`gpu_sched`） |
| 用户态 | 厂商闭源（DDX/GL/EGL/VAAPI） | Mesa |
| 能力 | **GL 硬件加速 + VA-API 硬解** | 显示可用，**无硬解** |
| 用途 | 日常使用、硬解播放 | 系统升级、稳妥兜底 |

切换脚本自动处理两者**期望相反**的配置（详见 §4.3）。

---

## 2. 部署方法

> 从**零/还原后的系统**开始，把整条栈装起来。完整版与回退见 `docs/系统还原后重建步骤.md`；
> 此处给出**按顺序可直接执行**的主干，以及每步的**验证判据**。

### 2.1 部署顺序总览

```
① 内核模块(DKMS)  → ② 厂商用户态(deb) → ③ libdrm 兼容链接 → ④ X 配置
                                                        ↓
                  ⑦ 重启并验收  ← ⑥ 系统配置(变量/vblank/kwin/dde-shell)
                                                        ↑
                                   ⑤ 用户态字节补丁(DDX + glstorage)
```

> ⚠️ **先做完 ①~⑥，最后才做「持久化」**（`force_mode_test.sh boot`）。
> 持久化会改写开机路径，一旦驱动跑不起来就**只能还原系统**（本机已两次，见 §8.1 坑 3）。

### 2.2 ① 内核模块（DKMS）

```bash
cd ~/Desktop/Git/jm9100

# 若 DKMS 源码目录不存在（还原后会丢），先补建
sudo mkdir -p /usr/src/mwv207-1.7.0.uos
cd kernel && sudo cp -f *.c *.h Makefile* dkms.conf Kconfig* /usr/src/mwv207-1.7.0.uos/
sudo dkms add mwv207/1.7.0.uos
cd ..

# 构建 + 安装 + 重建 initramfs（脚本自带 139 重试与 srcversion 校验）
sudo ./scripts/sync_dkms.sh build
```

**验证**（三条都要过）：

```bash
dkms status | grep mwv207        # 必须是 "installed"，不是 "added"
ls /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko
modinfo -F srcversion /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko
```

> ℹ️ 本系统 initramfs **不收录** `updates/` 目录，所以 `jmgpu.ko` 不会出现在 initramfs 里
> （由 rootfs 阶段 udev modalias 加载）。`sync_dkms.sh` 自 **2026-10-08** 起会识别这一情况并
> 判为正常；只有"initramfs 里确实存在一个与磁盘**不一致**的 `jmgpu.ko`"时才报失败
> （见 §6 遗留问题 7）。判成功仍以 `dkms status` 为 `installed` 为准。

### 2.3 ② 厂商用户态（deb）

```bash
cd ~/Desktop/Git/jm9100/vendor
sudo dpkg -i com.jingjiamicro.mwv207_1.7.0.uos_arm64.deb
sudo dpkg -i com.jingjiamicro.mwv207.vaapi_1.6.2.uos_arm64.deb
sudo apt-get -f install -y          # 依赖缺失时补齐
```

**验证**：`mwv207_drv.so` / `jmgpu_dri.so` / `libdrm_jmgpu.so.1.0.0` / glvnd json 都存在
（清单见 `vendor/README.md`）。

### 2.4 ③ libdrm 兼容链接（**两处都要，最易漏**）

DDX 的 `NEEDED` 写的是旧式 soname `libdrm.so.2.4.0`，而现代 `libdrm2` 只提供 `libdrm.so.2`：

```bash
sudo ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 /usr/lib/aarch64-linux-gnu/libdrm.so.2.4.0
sudo ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 /usr/lib/aarch64-linux-gnu/mwv207/libdrm.so.2.4.0
```

**验证**（四个厂商库都不应有 `not found`）：

```bash
for f in /usr/lib/aarch64-linux-gnu/mwv207/libGLX_mwv207.so.1.2.0 \
         /usr/lib/aarch64-linux-gnu/mwv207/libEGL_mwv207.so.1.5.0 \
         /usr/lib/aarch64-linux-gnu/dri/jmgpu_dri.so \
         /usr/lib/xorg/modules/drivers/mwv207_drv.so; do
  printf "%-56s " "$(basename $f)"
  ldd "$f" 2>&1 | grep -q 'not found' && ldd "$f" | grep 'not found' || echo OK
done
```

> **为什么必须两处**：只有 `mwv207_drv.so` 带 RUNPATH（`.../mwv207`）；另外三个库**没有 RUNPATH**，
> 只能按系统默认路径找。只建一处 ⇒ 厂商 GLX 加载失败 ⇒ **GL 静默回落 llvmpipe**（478 vs 17000 FPS）。

### 2.5 ④ X 配置

```bash
sudo tee /usr/share/X11/xorg.conf.d/10-mwv207.conf >/dev/null <<'EOF'
Section "OutputClass"
        Identifier "JMgpu"
        MatchDriver "jmgpu"
        Driver "mwv207"
EndSection
EOF
```

> `MatchDriver "jmgpu"` 对应**内核驱动名**（`/sys/bus/pci/devices/0000:07:00.0/driver`），
> `Driver "mwv207"` 对应 **X 驱动**（`mwv207_drv.so`）。
> **切回系统驱动时必须删除此文件**，否则 X 起不来（见 §4.3）。

### 2.6 ⑤ 用户态字节补丁

```bash
cd ~/Desktop/Git/jm9100

# 5a) DDX：ABI 24→25 + ScrnInfoRec 布局（用现成产物，md5 应为 297aee83…）
sudo cp -a /usr/lib/xorg/modules/drivers/mwv207_drv.so \
   /persistent/home/admin/jm9100-xdrv-backup/mwv207_drv.so.from-deb
sudo cp build-cli/mwv207_drv.so.abi25.fixed3 /usr/lib/xorg/modules/drivers/mwv207_drv.so
md5sum /usr/lib/xorg/modules/drivers/mwv207_drv.so     # 期望 297aee83b5db3a3bccf33ff7ac2698fc

# 5b) glstorage 三库（VA-API 零拷贝免 LD_PRELOAD）
sudo ./scripts/install_gl_storage.sh
sudo ./scripts/install_gl_storage.sh status            # 确认已打补丁
```

> 若原件丢失，可用 `tools/patch_xorg_abi.py` + `build-cli/patch_abi_layout.py` 重新生成
> `abi25.fixed3`；glstorage 用 `tools/patch_gl_storage.py`。

### 2.7 ⑥ 系统配置

```bash
# 6a) glvnd：让厂商 GLX 被选中（pkexec 会清环境，只有 pam_env 这条链路能覆盖提权应用）
sudo cp -a /etc/environment /etc/environment.bak
grep -q '__GLX_VENDOR_LIBRARY_NAME' /etc/environment || \
  echo '__GLX_VENDOR_LIBRARY_NAME=mwv207' | sudo tee -a /etc/environment

# 6a-2) ★ 必做：否则 EasyTier 等 WebKitGTK 应用会 SIGSEGV（图标一闪而过、无窗口）
#       厂商 GL 与 WebKitGTK 不兼容，关掉 WebKit 的加速合成即可（详见 §8.6）
grep -q '^WEBKIT_DISABLE_COMPOSITING_MODE' /etc/environment || \
  echo 'WEBKIT_DISABLE_COMPOSITING_MODE=1' | sudo tee -a /etc/environment

# 6b) vblank：内核默认 5s 后关闭 vblank 中断，厂商驱动无法重新使能（否则每帧等 1s）
sudo tee /etc/tmpfiles.d/drm-vblank.conf >/dev/null <<'EOF'
w /sys/module/drm/parameters/vblankoffdelay - - - - 0
EOF
sudo tee /etc/systemd/system/drm-vblank-fix.service >/dev/null <<'EOF'
[Unit]
Description=Set drm.vblankoffdelay=0
After=systemd-modules-load.service
[Service]
Type=oneshot
ExecStart=/bin/sh -c 'echo 0 > /sys/module/drm/parameters/vblankoffdelay'
[Install]
WantedBy=multi-user.target
EOF
sudo systemctl daemon-reload && sudo systemctl enable drm-vblank-fix.service

# 6c) kwin 用 XRender 合成（厂商 GL 合成实测仅 8 fps）
dde-dconfig set -a org.kde.kwin -r org.kde.kwin.compositing -k user_type -v 4

# 6d) 任务栏走 Mesa（厂商 GL 在其上仅 1–11 fps）
bash ~/fix_dock_mesa.sh
```

### 2.8 ⑦ 重启并验收

> **重启 X 会结束当前图形会话**，请在 **tty（Ctrl+Alt+F3）或 SSH** 里执行。

```bash
sudo reboot
```

重启后逐项验收（**关键是先取对 `DISPLAY`**）：

```bash
cd ~/Desktop/Git/jm9100
sudo ./scripts/switch_stack.sh status          # 总览：驱动/配置/GL 一眼看清

# 会话 DISPLAY 自动探测（本机在 :0/:1/:3/:4 之间变化）
D=$(tr '\0' '\n' < /proc/$(pgrep -x kwin_x11 | head -1)/environ | sed -n 's/^DISPLAY=//p')

DISPLAY=$D glxinfo -B | grep -i renderer       # 期望 Jingjia JM9100（不是 llvmpipe）
DISPLAY=$D vblank_mode=0 glxgears              # 期望上万 FPS（软件栈仅 ~500）
DISPLAY=$D ./scripts/test_passthrough.sh -s 360p   # VA-API 直通端到端

sudo dmesg | grep -cE 'vblank wait timed out|commit wait timed out|BUG:'   # 期望 0
```

### 2.9 最后：持久化（**确认上面全绿后再做**）

**为什么需要**：默认发行版 in-tree `mwv207` 会由 modalias 抢先绑定设备，
而 `10-mwv207.conf` 的 `MatchDriver "jmgpu"` 匹配不上内核驱动 ⇒ 厂商 DDX 不会被使用。
持久化 = 「禁掉 `mwv207` + 强制加载 `jmgpu` + 冻结进 initramfs」。

```bash
cd ~/Desktop/Git/jm9100

# 方式一（推荐，等价且更易回退）
sudo ./scripts/switch_stack.sh persist      # 或 sudo ./scripts/switch_stack.sh vendor --persist
sudo reboot

# 方式二
sudo ./scripts/force_mode_test.sh boot      # 与上面等价（blacklist + modules-load + initramfs）
sudo reboot
```

**回退**（三选一，后两者更彻底）：

```bash
sudo ./scripts/switch_stack.sh system && sudo reboot        # 回系统栈：撤配置+撤持久化+移 DKMS
sudo ./scripts/force_mode_test.sh boot-undo && sudo reboot   # 仅撤持久化
sudo ~/rollback-to-system.sh && sudo reboot                  # **紧急**（黑屏时在 TTY/SSH 里用）
```

> `update-initramfs` 期间若报 **dracut `cp` 139**，先 `sudo rmmod vfs_monitor`
> （deepin 文件监控在内核 6.6 上触发内核 `BUG()`，与本驱动无关，见 §8.5）。
> `switch_stack.sh` 的持久化动作已内置这一步。

**验证运行中的模块 = 磁盘模块**（历史上多次"修复无效"的误判都源于此）：

```bash
cat /sys/module/jmgpu/srcversion                                       # 运行中
modinfo -F srcversion /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko   # 磁盘
```

### 2.10 部署后日常使用

```bash
# 视频硬解播放（零拷贝直通）
LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=vaapi 视频.mp4

# 确认真的走了硬解（否则一切"正常"都是软解）
LIBVA_DRIVER_NAME=jmgpu mpv --no-config --vo=gpu --hwdec=vaapi --frames=5 video.mp4 2>&1 \
  | grep -E "hardware decoding|EGL dmabuf interop|GL_RENDERER"
# 期望：Using hardware decoding (vaapi) + Using EGL dmabuf interop via GL_OES_EGL_image

# 色彩诊断
./scripts/color_bisect.sh
```

> ⚠️ **`DISPLAY` 每次重启 X 都会变**（`:0`/`:1`/`:3`/`:4` 都出现过）——
> 所有 X 侧测试前**必须先取当前会话的 `DISPLAY`**，否则会看到"命令无输出"的假象（见 §8.1 坑 2）。

---

## 3. 已采用的修复

> 只列**当前生效**的修复。每项给出：症状 → 根因 → 落地位置。

### 3.1 内核驱动（本仓库 `kernel/`）

| # | 问题 | 根因 | 修复位置 |
|---|---|---|---|
| 1 | **HDMI 无信号**（内核 oops） | ① `late_register` 未把自管 i2c adapter 同步到 `connector->ddc`；② 6.5+ 内核 `drm_scdc_*` 签名由 `(i2c_adapter*,bool)` 改为 `(drm_connector*,bool)`，厂商实现被 `#if <4.12` 排除 ⇒ 走内核版 ⇒ `i2c_transfer(NULL)` | `jmgpu_nicely.c`（补 `connector.ddc` + 8 处改调本地 `jmgpu_scdc_*` + 定义移出条件块） |
| 2 | **显示灰蒙蒙**（低对比度） | `drm_crtc_enable_color_mgmt(..., 768, ...)` 宣称 768 项，但驱动只读前 256 项 ⇒ 客户端下发的 768 项 identity ramp 只进 1/3，整屏压到 1/3 动态范围 | `jmgpu_package.c`：契约改为 **256**（与消费端一致） |
| 3 | **VA-API 直通画面全绿** | dmabuf 导入路径的 sg_table / 地址翻译缺陷 | `jmgpu_bullets.c`、`jmgpu_setlayout.c` + `patches/mpv_dmabuf_oes_image.patch` |
| 4 | **Dmabuf 分配器 `.GetSGT` 空桩** ⇒ 外部 dmabuf 导入永远取不到 sg_table | 未实现 | `jmgpu_crosstab.c` `_DmabufGetSGT()` |
| 5 | **`DRM_JM_GEM_XFER_RECT` 整数溢出** + 第二缓冲未校验 | 用户可控 `offset/size` 未做范围检查 | `jmgpu_garbage.c` |
| 6 | **三处分配器 `.Physical` 缺 `Offset` 越界检查** | 同上 | `jmgpu_crosstab.c` / `jmgpu_setlayout.c` / `jmgpu_background.c` |
| 7 | **把 `JMM_kASSERT` 当边界检查的 8 处缺陷**（含**用户可控 `ChannelId` 越界写**） | `JMM_kASSERT` 在发行构建（`-DDBG=0`）下**展开为空** ⇒ 检查与 `return` 全部消失 | `jmgpu_register.c`（`channels[ChannelId]`）、`jmgpu_marketing.c`/`jmgpu_crosstab.c`/`jmgpu_background.c`（`.Mmap`/`.GetSGT` 的 `skipPages/numPages/Offset`）、`jmgpu_middleware.c`（`1ull << channelId`） |
| 8 | **三角/楔形错位**：GEM 搬运行前不等 2D 排空 | DDX 的「2D 合成 → 影子缓冲 → `DRM_JM_GEM_XFER_RECT` 上传 → 翻页」链条里，**上传与之前的 2D 合成无同步** ⇒ 上传可能读到只写了一半的源缓冲 | `jmgpu_garbage.c` `j9_handle_j9ma_arecaceous()`：开始搬运前 `j9mirror_monosilane(p2d, ms)`（有界等待，失败只告警）。开关：`xfer_waits_2d_idle`（毫秒，0=关闭，默认 **30**） |
| 9 | **`jmkOS_WaitNativeFence` 等待预算算错**（栅栏提前超时） | `dma_fence_wait_timeout()` 返回**剩余**预算，原码写作 `timeout -= ret` ⇒ 多元素 fence array 后续预算越缩越小、提前超时 | `jmgpu_symbol.c`（6.6 分支改为 `timeout = ret` + 逐元素判断；旧内核分支同类写法一并修） |
| 10 | **GL/EGL 应用送显只有 1~2.5 次/秒**（mpv `vo=gpu`/`vo=gpu-next`、EasyTier 等） | ⚠️ **原判定的根因是错的（2026-10-08 更正）** | **原前提「本板硬件 vblank 事件不产生」已被证伪**：kprobe 直接量到显示 IRQ 处理函数 `j9_handle_j9m_luciferase()` 4 秒内被调用 **802 次、全部返回 `IRQ_HANDLED`**，随后调用 `drm_crtc_handle_vblank()`；以厂商原始行为运行时 `DRM_IOCTL_WAIT_VBLANK` 实测 **99.2Hz**（面板 100Hz）。当初"看不到 vblank"的真因是内核 `drm.vblankoffdelay` 空闲 5s 后关掉 vblank 中断、而厂商驱动无法重新使能（§3.3 #12 已用 `drm.vblankoffdelay=0` 规避）。**开着 `flip_event_immediate=1` 的代价（实测）**：vblank 计数被推到 **193Hz**（真 100Hz）；且 `drm_crtc_handle_vblank()` 被从**原子提交路径**调用，会**提前唤醒**所有等在该 vblank 队列上的线程（含厂商 DDX 的 TearFree —— 它用 `drmWaitVBlank` 定位"该做 shadow→扫描缓冲拷贝"的时刻）⇒ 拷贝落到**显示正在扫描的过程中** ⇒ 撕裂/错位。**故默认已改回 0（=厂商原始行为）**。 | `kernel/jmgpu_package.c`：`flip_event_immediate` 默认 **1 → 0**；`sw_vblank_counter` 默认 0 并标注作废；`jmgpu_commit_wait_flip()` 在默认配置下直接走 `drm_atomic_helper_wait_for_vblanks()`。本机 `/etc/modprobe.d/jmgpu-vblank.conf` 同步改为 `flip_event_immediate=0`。**仍成立的结论**：GL 路径送显慢是**用户态**问题（X Present / EGL / 无合成器），与内核 vblank 机制无关；日常播放用 `vo=x11`（30 次/秒、颜色正确）。<br>**历史**：`fake_vblank`/`vblank_refresh` 的软件 vblank 会打坏光标平面行 vblank（鼠标不动）⇒ 保持 0；`flip_wait_ms>0` 会拖慢每次原子提交 ⇒ 鼠标不跟手 ⇒ 保持 0。 |
| 11 | **#7 同类残留（2026-10-08 补齐）**：① 两个分配器 `.Mmap` 仍只用"发行构建下被编译掉"的 `JMM_kASSERT`；② 4 处 extent 检查求和可溢出 | ① `jmgpu_setlayout.c`（reserved-mem）与 `jmgpu_formula.c`（VMEM）的 `.Mmap` 里 `JMM_kASSERT(skipPages + numPages <= Mdl->numPages)` 在 `-DDBG=0` 下展开为空，其后 `remap_pfn_range()` / fault handler 按**用户给定的 mmap 长度**映射；VMEM 的 fault handler 只判 `is_vmalloc_addr()` ⇒ 越界 offset 仍落在 vmalloc 区、会拿到**别的分配**的页并 `get_page()` 交给用户态。② `setlayout`/`formula`/`marketing` 的 `.MapKernel` 与 `jmgpu_through.c` 镜像同步写的是 `Offset + Bytes > size` —— 用户可控 `Offset` 很大时求和回绕 ⇒ 检查被绕过 | `jmgpu_setlayout.c` `j9_pathopsychosis()`（+`res` 空判）、`jmgpu_formula.c` `j9_finale()` 与 `_VMEMFaultLegacy()`（offset 越界 + `vmalloc_to_page()` 空返回）；4 处 extent 一律改为 `Offset > size \|\| Bytes > size - Offset`。**至此 5 个 `.Mmap` 实现、全部 `.Physical`/`.GetSGT` 均已有真实边界检查 —— 该类审计收口** |


**同族但有意未改**：`jmgpu_program.c`（MMU/STLB）、`jmgpu_refactor.c`（堆空闲链表）等处的 `JMM_kASSERT`
属**内部不变量**，值不受用户控制，改运行时检查收益低而回归面大。

**2026-10-08 复核（该类收口）**：5 个 `.Mmap`（`jmgpu_marketing.c`/`jmgpu_background.c`/`jmgpu_crosstab.c`/
`jmgpu_setlayout.c`/`jmgpu_formula.c`）、全部 `.Physical`、全部 `.GetSGT` 现已都有真实边界检查；
`jmgpu_middleware.c`/`jmgpu_destroy.c` 里用户可控的 patch `type` 虽只用 `JMM_kASSERT` 断言，但
两个下游派发器（`j9_handle_j_tactometer()`、`j9mirror_unciferous()`）内已有真实数组边界检查，
故未重复加。所有改动**已编译通过**，但**尚未在硬件上部署验证**（见 §4.2 标准流程）。

### 3.2 用户态（厂商闭源库的字节补丁）

| # | 目标 | 做法 | 脚本 / 产物 |
|---|---|---|---|
| 8 | **专有 X 驱动无法加载**（ABI 24→25 + 清理路径 `NULL+0x48` 段错误） | ① `XF86ModuleVersionInfo.abiversion` 24.0→25.0；② Xorg 1.21 删除了 `xf86str.h` 的 `Bool flipPixels` ⇒ `ScrnInfoRec` 其后字段整体 **−8 字节**，回调槽错位 | `tools/patch_xorg_abi.py` + `build-cli/patch_abi_layout.py` ⇒ 产物 **`build-cli/mwv207_drv.so.abi25.fixed3`**（md5 `297aee83…`） |
| 9 | **`glEGLImageTargetTexStorageEXT` 未实现**（VA-API 零拷贝必须挂 `LD_PRELOAD`） | 给 `jmgpu_dri.so` 补扩展广告 + `libEGL_mwv207.so`/`libGLX_mwv207.so` 加入口别名（纯字节补丁） | `tools/patch_gl_storage.py` ⇒ 产物 `build-cli/*.glstorage` |
| 10 | **TearFree 的 2D 上传后不等引擎完成**（画面三角/楔形错位） | 把上传例程返回前的 `ldp x29,x30,[sp,#16]` 改成 `bl 等2D空闲封装`（该封装驱动里本就存在、却 0 引用） | `tools/patch_ddx_tearfree_sync.py` ⇒ 产物 **`build-cli/mwv207_drv.so.abi25+tearfree-sync`**（sha256 `4c0f96b6…`，仅 8 字节改动）<br>部署/回退：`tools/deploy_ddx_tearfree_sync.sh build\|apply\|revert\|status`<br>**注**：2026-09-18 才把该补丁打到"ABI25 修复版"上（此前只打在未修复的原件上 ⇒ 无法加载 ⇒ 一直没验证） |

### 3.3 系统配置（非仓库代码）

| # | 项 | 内容 | 原因 |
|---|---|---|---|
| 11 | `/etc/environment` | `__GLX_VENDOR_LIBRARY_NAME=mwv207` | glvnd 需要它才用厂商 GLX；**`pkexec` 会清空环境**，只有 `pam_env`（读 `/etc/environment`）这条链路能覆盖提权应用（否则 EasyTier 等 **白屏**） |
| 12 | `/etc/tmpfiles.d/drm-vblank.conf` + `drm-vblank-fix.service` | 开机把 `drm.vblankoffdelay` 写为 **0** | 内核默认在最后一个 vblank 使用者释放后 5s 关闭 vblank 中断，厂商驱动无法重新使能 ⇒ 客户端每帧等 1s（**1 FPS → 1.4 万 FPS**） |
| 13 | `dconfig org.kde.kwin.compositing:user_type=4` | kwin 用 **XRender** 合成 | 厂商 GL 合成实测仅 8 fps，XRender 47 fps |
| 14 | `/usr/bin/dde-shell` 包装 | 改走 Mesa（原二进制备份为 `dde-shell.real`） | 任务栏高频重绘，厂商 GL 只有 1–11 fps；`~/fix_dock_mesa.sh` 应用/回退 |
| 15 | `10-mwv207.conf` | `MatchDriver "jmgpu"` + `Driver "mwv207"` | 让 X 使用厂商 DDX（**切回系统驱动时必须删除**，否则 X 起不来） |
| 16 | `/etc/environment` | **`WEBKIT_DISABLE_COMPOSITING_MODE=1`** | **当前唯一可靠规避**（WebKit 不建 GL 上下文 ⇒ 不触发厂商栈的悬垂 TLS 解引用）。实测：加 `glxguard` 守卫也救不了 WebKit 实际形态（§8.6.3）⇒ 保留本行；厂商修好 EGL 侧（§7 第 9～11 条）后方可移除 |
| 17 | `/etc/initramfs-tools/modules` | **`jmgpu`** | **让 initramfs 自带并在开机早期加载厂商模块**。不加这一行时：`MODULES=most` 只扫 `kernel/`（不含 `updates/dkms/`），`modules-load.d` 又只对切根后的 systemd 生效 ⇒ 整个 initramfs 阶段**没有任何 DRM 设备**，deepin `/init` 的 `wait_for_gpu_device()` 会白等满 2000×5ms 才超时（实测 **13.67s**，见 §6 #12）。2026-10-08 起由 `switch_stack.sh persist` 自动写入、`system` 自动移除 |

### 3.4 已排除（勿再尝试）

| 方案 | 结论 |
|---|---|
| 改 `libglx.so`（Xorg 模块）的默认 GLX vendor | ❌ **无效且有害** —— 客户端走的是 glvnd（`libGLX.so.0`，内部无默认 vendor 字符串），改 Xorg 模块不起作用；反而打乱 DDX↔内核协作，**触发 vblank 超时 + 内核 `BUG()`**（详见 §8.3） |
| 让 EGL 覆盖全部 visual | ❌ 不需要 —— 实测 `eglCreateWindowSurface` 不做 config↔visual 匹配校验，90/90 visual 都能建面渲染 |
| 全局关压缩 `compression=0` | ⚠️ 可缓解卡顿，但**不是错位主因**（详见 §6） |
| 给 WebKit 应用加 `__EGL_VENDOR_LIBRARY_FILENAMES=…10_mwv207.json` | ❌ **反而必崩** —— 强制只用厂商 EGL 时 EasyTier SIGSEGV（与只给 GLX 变量同样结果，§8.6） |

---

## 4. 部署与切换

### 4.1 首次部署 / 持久化 / 回滚

```bash
cd ~/Desktop/Git/jm9100

# 厂商栈接管持久化（blacklist mwv207 + modules-load 强制加载 jmgpu + 进 initramfs）
sudo ./scripts/switch_stack.sh persist   # 或 ./scripts/force_mode_test.sh boot（等价）
sudo reboot

# 回滚到系统自带 mwv207
sudo ./scripts/switch_stack.sh system && sudo reboot
# 紧急回滚（黑屏时在 TTY/SSH 里执行；只做最小必要动作，不依赖仓库脚本）
sudo ~/rollback-to-system.sh && sudo reboot
```

> ⚠️ **持久化会改写开机路径**：一旦新驱动在该内核上跑不起来，开机既加载不到新驱动、
> 又因 blacklist 回不到原驱动 ⇒ **黑屏只能还原系统**。
> **务必先用运行时手段验证**（`driver_override`），确认可用后再持久化，且**回退命令先在手**。
> 紧急回退脚本 `~/rollback-to-system.sh` 就是为此准备的 —— 建议在持久化**之前**确认它存在。

### 4.2 改驱动源码后的标准流程

```bash
cd ~/Desktop/Git/jm9100
./scripts/sync_dkms.sh build      # 同步 + dkms build/install + update-initramfs -u
sudo reboot
```

> **红线（2026-10-08 重新表述）**：`dkms install` 后**必须重建 initramfs 再重启**，原因有两层：
> - **厂商栈已把 `jmgpu` 写进 `/etc/initramfs-tools/modules`**（§3.3 #17，`persist` 自动做）
>   ⇒ `jmgpu.ko` 现在**就在 initramfs 里**，并由 `/init` 的 `load_modules()` 于开机早期加载。
>   不重建 initramfs，重启后早期阶段仍旧镜像（旧模块 / 无模块）⇒ 新代码不生效、且白等 GPU
>   （§6 #12）。**这也意味着 `sync_dkms.sh` 的 initramfs `srcversion` 校验现在是有效判据**。
> - **开机路径配置**：`blacklist mwv207` / `modules-load jmgpu` 同样是写进 initramfs 的；
>   改了持久化就必须 `update-initramfs -u`（历史上"修复无效"的误判多源于此）。
>
> 注：**未持久化**（`vendor` 不带 `--persist`）时 initramfs 不收录 `updates/dkms/`，
> `jmgpu.ko` 只能由切根后的 systemd 加载 —— 那时"initramfs 里没有 jmgpu.ko"是正常态（§6 #7）。
>
> 验证（模块本体是否为新代码）：
> ```bash
> cat /sys/module/jmgpu/srcversion                                      # 运行中
> modinfo -F srcversion /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko  # 磁盘
> # 两者一致 = 新模块已生效
> ```

### 4.3 两套栈切换（`scripts/switch_stack.sh`）

```bash
sudo ./scripts/switch_stack.sh status                # 只读：当前栈 + 配置差异 + 一致性检查
sudo ./scripts/switch_stack.sh vendor                # 切到厂商栈：配置 + 装模块（**不动开机路径**）
sudo ./scripts/switch_stack.sh vendor --persist      # 上一步 + 持久化（**改开机路径**）
sudo ./scripts/switch_stack.sh persist               # 只做持久化（禁 mwv207 + 强制 jmgpu + initramfs）
sudo ./scripts/switch_stack.sh system                # 切回系统驱动（撤配置+撤持久化+移 DKMS）
sudo ./scripts/switch_stack.sh backup                # 备份现有配置
sudo ./scripts/switch_stack.sh restore               # 回到上次备份
```

**设计要点**：

- `vendor` **默认不做持久化** —— 只配置 X/环境/链接/vblank + 装模块，避免"改开机路径"的意外；
  此时 `status` 会报**不一致**并提示下一步（`persist` 或 `system`）。
- `system` **同时**撤销持久化与 DKMS 注册。若只撤 DKMS 而不撤黑名单，会出现
  「jmgpu 未安装 + mwv207 被禁」⇒ **开机无驱动**（这是曾经的隐患）。
- 持久化前会**先卸 `vfs_monitor`**，避免 dracut `cp` 139 导致 initramfs 生成失败。

**为什么需要它**（两套栈期望**相反**的三处配置，散着改必然漏）：

| 配置 | 厂商栈 | 系统栈 |
|---|---|---|
| `10-mwv207.conf` | 需要（`MatchDriver "jmgpu"`） | **必须删除**（驱动名不符 ⇒ **X 起不来**） |
| `/etc/environment` 的 `__GLX_VENDOR_LIBRARY_NAME` | 需要 | **删除**（否则 GL 走错库） |
| DKMS `mwv207` 注册 | 需要 | **必须移除**（否则内核升级触发重编 ⇒ **中断更新**） |

> 脚本**不自动重启**，改前**先备份**（默认 `$BAK=/persistent/home/admin/jm9100-xdrv-backup`，
> 可用 `JM9100_BAK=` 覆盖）。

### 4.4 重装系统后需重做

1. **内核模块**：`./scripts/sync_dkms.sh build`（+ `force_mode_test.sh boot` 持久化）；
   **DKMS 注册丢失时脚本会自己 `dkms add`**（2026-10-08 起）。只有**源码目录本身**也没了
   （重装系统后 `/usr/src/mwv207-1.7.0.uos` 不存在）时才需要手工：
   ```bash
   sudo mkdir -p /usr/src/mwv207-1.7.0.uos
   cd ~/Desktop/Git/jm9100/kernel && sudo cp -f *.c *.h Makefile* dkms.conf Kconfig* /usr/src/mwv207-1.7.0.uos/
   sudo dkms add mwv207/1.7.0.uos     # sync_dkms.sh build 也会自动补
   ```
2. **厂商 deb**：`vendor/` 下三个包（详见 `vendor/README.md`）。
3. **libdrm 兼容链接**（**两处都要**，易漏）：
   ```bash
   sudo ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 /usr/lib/aarch64-linux-gnu/libdrm.so.2.4.0
   sudo ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 /usr/lib/aarch64-linux-gnu/mwv207/libdrm.so.2.4.0
   ```
4. **DDX**：`build-cli/mwv207_drv.so.abi25.fixed3`（md5 `297aee83…`）
5. **glstorage 三库**：`build-cli/*.glstorage`
6. **mpv**：打 `patches/mpv_dmabuf_oes_image.patch` 后重编（见下）
7. **系统配置**：§3.3 的 11~17 项（其中 11/12/15/17 与开机路径相关，`switch_stack.sh vendor --persist` 会一并写好；16 也会被 `vendor` 写入）

完整步骤与回退见 **`docs/系统还原后重建步骤.md`**。

**mpv 重编**：

```bash
sudo apt-get install -y build-essential devscripts dpkg-dev
cd /tmp && apt-get source mpv && cd mpv-0.40.0
patch -p1 --fuzz=3 < ~/Desktop/Git/jm9100/patches/mpv_dmabuf_oes_image.patch
dpkg-buildpackage -b -uc -us -j$(nproc)
sudo dpkg -i ../mpv_*.deb
```

---

## 5. 仓库结构

```
jm9100/
├── kernel/     内核驱动源码与构建配置（DKMS 只从这里取源码）
│               jmgpu_*.c/.h、mwv207_*.c/.h、Makefile*、Kconfig*、dkms.conf
├── scripts/    部署 / 切换 / 测试 / 诊断脚本
├── tools/      探针（*.c）与补丁/统计脚本（*.py）
├── patches/    对外补丁（mpv 直通补丁）
├── docs/       重建手册、交付清单、厂商反馈材料
├── vendor/     厂商安装包副本（deb，含 sha256 清单）
├── build-cli/  生成物（补丁产物 .so）
├── backup/     历史文档与基线备份
└── README.md
```

**约定**：

- 正文中的 `jmgpu_*.c` / `Makefile` / `dkms.conf` 等**一律位于 `kernel/`**。
- `sync_dkms.sh` 把 `kernel/` 内容**平铺**拷到 DKMS 源目录（DKMS 侧仍是"所有文件同目录"，
  故 `Makefile` 的裸对象名与 `-I.` 不受仓库目录结构影响）。
- 所有脚本用 `HERE`/`REPO` 自定位，**可在任意 cwd 调用**，生成物落在仓库根 `build-cli/`。

### 5.1 脚本清单（`scripts/`）

| 脚本 | 用途 |
|---|---|
| **`switch_stack.sh`** | **两套栈切换**（status / vendor / system / backup / restore） |
| **`sync_dkms.sh`** | 同步源码 + DKMS build/install + 重建 initramfs（+ 指纹校验） |
| `force_mode_test.sh` | 持久化接管（`boot` / `boot-undo`） |
| `test_passthrough.sh` | **VA-API 直通端到端自检**（推荐） |
| `install_gl_storage.sh` | 安装 glstorage 三库补丁（status/install/revert） |
| `build_gl_compat.sh` / `test_gl_compat.sh` | GL 兼容层构建/测试（**已退役**，见 §6） |
| `check_jmgpu_display.sh` / `diag_jmgpu_fail.sh` | 显示状态检查与失败诊断 |
| `color_bisect.sh` / `fix_win_contrast.sh` | 色彩/对比度诊断 |
| `jmgpu_reload_test.sh` | 卸载/重载与 S3 恢复测试 |
| `verify_jmgpu_probe.sh` / `verify_jmgpu_probe_ssh.sh` | 综合探针验证 |
| `dump_display_regs.sh` / `dump_full_regs.sh` | 寄存器转储 |
| `x_test_jmgpu.sh` | X 侧测试 |

**`$HOME` 下的配套脚本（不在仓库内，随环境部署）**：

| 脚本 | 用途 |
|---|---|
| `~/fix_dock_mesa.sh` | 任务栏走 Mesa 的包装（apply / revert，§3.3 #14） |
| **`~/rollback-to-system.sh`** | **紧急回退**到系统自带 mwv207：黑屏时在 **TTY（`Ctrl+Alt+F3`）或 SSH** 执行 `sudo ~/rollback-to-system.sh && sudo reboot`。动作 = 删黑名单 → 删 `jmgpu.conf` → 删 `10-mwv207.conf` → 清 `/etc/environment` 变量 → 重建 initramfs（自动先卸 `vfs_monitor` 避免 139） |

### 5.2 工具清单（`tools/`）

| 工具 | 用途 |
|---|---|
| `patch_xorg_abi.py` | DDX 的 ABI 24→25 补丁 |
| `patch_ddx_tearfree_sync.py` | DDX 的 TearFree 2D 同步补丁（§3.2 #10） |
| `patch_gl_storage.py` | glstorage 三库补丁（§3.2 #9） |
| `test_passthrough.sh` 配套：`passthrough_verify.py` / `ppm_stats.py` | 直通结果与像素统计 |
| `jm_gl_storage_test.c` / `jm_gl_glx_path_test.c` | GL storage 双路径端到端探针 |
| `egl_force_visual.c` / `jm_egl_visual_probe.c` | EGL visual/config 探针 |
| `va_export_probe.c` / `va_export_diag.c` | VA-API 导出与诊断 |
| `jm_gem_probe.c` / `jm_dumb_probe.c` / `jm_dmabuf_cycle.c` | DRM GEM / dmabuf 探针 |
| `drm_gamma_probe.c` / `bar_probe.c` | 色彩管理 / BAR 探针 |
| `jm_gl_compat.c` | GL 兼容层源码（**已退役**） |
| `extract_patch.py` | 补丁提取辅助 |
| **`glx_egl_tls_uaf_repro.c`** | **崩溃复现/取证程序**（§8.6.1）：厂商 EGL 留下悬垂 libglapi TLS ⇒ GLX 销毁时 `jmDestroyContext` SIGSEGV。`--no-egl` 为对照组 |
| **`glxguard.c`** | 该崩溃的**守卫库**（§8.6.2）：用 `mincore()` 只清"真悬垂"的 libglapi TLS，合法当前上下文不动 |
| **`fix_easytier_glxguard.sh`** | 部署守卫（`apply` / `revert` / `status`）：编译到 `/usr/local/lib/` + 包装 `/usr/bin/easytier-gui`（含 pkexec 提权实例） |
| **`wkmin.c`** | **最小 WebKit 复现器**（§8.6.3）：强制加速合成 + 纯色页面，配 `ffmpeg x11grab` 抓屏可**客观判定**（像素统计）WebKit 在厂商栈上是否崩溃/是否画出内容 |
| **`deploy_ddx_tearfree_sync.sh`** | 部署/回退"DDX TearFree 同步"补丁（治三角/楔形错位）：`build` / `apply` / `apply-nox` / `revert` / `status`。补丁 = 把 DDX 里"合成→扫描缓冲"上传路径的两处函数尾声换成 `bl <等 2D 空闲封装>`（共 8 字节），使**上传完成前不返回** |

---

## 6. 遗留问题

| # | 问题 | 状态 | 说明 |
|---|---|---|---|
| 1 | **画面三角/楔形错位**（视频窗口内，偶发） | ✅ **已定位（2026-10-08 彻底重新分析）** —— 根因在**用户态呈现链**，非内核搬运 | **旧结论作废**：先前归因于"硬件 vblank 事件不产生 / 内核搬运与 2D 不同步"，均被实测推翻（更正见 §3.1 #10）。<br>**新根因（三层叠加，逐层取证）**：<br>① **X 侧没有硬件 GLX**：Xorg 日志 `(EE) AIGLX error: jmgpu exports no extensions (jmgpu_dri.so: undefined symbol: __driDriverExtensions)` ⇒ 服务器回落 `DRISWRAST`（软件）。`jmgpu_dri.so` 只导出 `__driCreateNewScreen`，且系统里**没有任何** Mesa DRI 提供该符号可借用 ⇒ 此补丁**不可行**。<br>② **会话没有合成器**：`_NET_WM_CM_S0` 无人持有；kwin `/Compositor` `active=false` 且 `reinitialize` 拉不起来；`kwinrc` 无 `[Compositing]` 启用项；dconfig `user_type=5`（§3.3 #13 要求的 XRender 合成 `4` 未生效）⇒ 窗口直接写扫描缓冲，**无合成/重定向兜底**。<br>③ **GLX 交换与 vblank 完全无同步**（决定性实测，探针 `glxswap`）：厂商 GLX 交换 **~63000 Hz**（0.016ms/次）而面板 100Hz；Mesa 软件栈 **515 Hz** 也不同步 ⇒ 与厂商无关，是 **X 服务器未建立交换↔vblank 关系**。同步手段全失效：`vblank_mode=1/3` 无效（`3` 让交换**永久挂死**）、`glXSwapIntervalEXT(1)` **挂死**、`GLX_MESA/SGI_swap_control` 不存在、`LIBGL_DRI3_DISABLE=1` 与 `__GL_SYNC_TO_VBLANK=1` 均无效。<br>⇒ **扫描输出读到正在被写入的缓冲** ⇒ 带状/三角状"上一帧残留"，位置随时间漂移（与"截图里能看到"一致）。<br>**我方引入的加重因素（已修）**：`/etc/environment` 中我们写的 `vblank_mode=0` 经 pam_env 注入整个会话，把应用用 `setenv(overwrite=0)` 想开的同步**挡掉了**（应用实测打印 `__GL_SYNC_TO_VBLANK=1 vblank_mode=0`）。已从脚本与系统删除（该变量对厂商 GLX 本就无效，只会阻碍他人）。<br>**应用侧独立同结论**：`purelive_linux_arm64/docs/LINUX_JM9100_HWDECODE_AUDIT.md §10.9`（"GLX 交换未与 vblank 同步"）。<br>**可行修复方向（按性价比）**：<br>a. **让合成器接管呈现**（最干净，须先解决 kwin 合成为何不可用）——窗口先进合成器、由合成器按 vblank 节拍上屏；<br>b. 补 `__driDriverExtensions` 让 X 侧有硬件 GLX（需厂商/自研 DRI，工作量最大）；<br>c. 应用侧规避：`PURELIVE_JM9100_GL=software`（llvmpipe + X 拷贝路径，不再与 GL 扫描缓冲竞争；代价是 CPU/软解）——**待维护者实测确认**。<br>**本轮已排除**：内核 vblank 机制（kprobe 实测硬件 vblank 100Hz、IRQ 全 `IRQ_HANDLED`）、`xfer_waits_2d_idle`（本次启动 0 次超时告警）、`jmkOS_WaitNativeFence`（已修且与现象无关）。 |
| 2 | `compression=15`（默认）下**卡顿 + 内核任务态破坏** | ⚠️ 规避可用 | 与 `fastClear` 组合有关；`compression=0` 或 `fastClear=0` 可规避。**但该现象在系统自带驱动下也偶现** ⇒ 不能完全归因于本驱动 |
| 3 | **CPU 写合并（`enable_wc`）一致性** | ⚠️ **未验证** | `Accel off` 仍错位 ⇒ 怀疑 `pgprot_writecombine` 的 posted 写未被显示读到。验证方案（`enable_wc=0`）**曾导致无法启动**，未得结论。后续验证**必须用可回退方式** |
| 4 | kwin GL(`gl2`) 合成只有 ~8 fps | ✅ 已规避 | 用 `user_type=4`（XRender）绕过；属厂商侧 |
| 5 | 任务栏（`dde-shell`）走厂商 GL 掉帧 | ✅ 已规避 | 包装改走 Mesa（§3.3 #14） |
| 6 | `cp` / `update-initramfs` **随机 139** | ✅ 已定位（**非本驱动**） | 根因是 `deepin-anything` 的 **`vfs_monitor.ko`** 在内核 6.6 上触发 `BUG()`（ARM64 `brk #6`，`Tainted: G D OE`）。`sudo rmmod vfs_monitor` 后 100 次复制 **0 失败**、`update-initramfs` **rc=0**。持久规避：`blacklist vfs_monitor`（代价：deepin 文件索引失效） |
| 7 | `sync_dkms.sh` 报"initramfs 校验失败" | ✅ **已修（2026-10-08）** | 原脚本把"initramfs 里找不到 `jmgpu.ko`"直接判失败并 `exit 1` —— 而本系统 initramfs **不收录 `updates/`（DKMS）目录**（实测 `updates/*.ko`=0，只有 `kernel/drivers/gpu/drm/mwv207/mwv207.ko`），DKMS 模块由 rootfs 阶段 udev modalias 加载 ⇒ **"找不到"是正常态**，导致这条被文档写成"标准流程"的命令每次都报失败。现改为：解包失败→跳过校验不判失败；initramfs 无 `jmgpu.ko`→判定正常；**只有** initramfs 里确有 `jmgpu.ko` 且与磁盘 `srcversion` 不一致时才 `exit 1` |
| 8 | GL 兼容层 `libjm_gl_compat.so` | ✅ **已退役** | glstorage 补丁已原生支持，系统级兼容层已卸载（无需 `LD_PRELOAD`） |
| 9 | 零拷贝依赖 mpv 补丁 | ⚠️ 已知 | 升级 mpv 后需重新应用 `patches/mpv_dmabuf_oes_image.patch`（系统级 `LD_PRELOAD` 兼容层亦可，但已退役） |
| 10 | **厂商 EGL 留下悬垂 libglapi TLS ⇒ GLX 销毁段错误**（WebKitGTK 应用打不开） | ⚠️ **部分缓解**，厂商侧根因未修 | 根因链：EGL 解绑/销毁不清 TLS → `jmDestroyContext` 解引用未校验（UAF）。我方 `glxguard` 守卫能修**独立复现器**，但**修不了 WebKit 实际形态**（悬垂指针可能落在**仍映射**的池里 ⇒ 地址类判据不可靠，§8.6.3）。当前仍以 `WEBKIT_DISABLE_COMPOSITING_MODE=1` 为准（§3.3 #16）；确定性复现程序 `tools/glx_egl_tls_uaf_repro.c`、客观判定工具 `tools/wkmin.c` |
| 11 | **内核 `jmkOS_WaitNativeFence` 等待预算算错**（栅栏提前超时） | ✅ **已修（本仓库 `kernel/jmgpu_symbol.c`）** | `dma_fence_wait_timeout()` 返回的是**剩余**预算，原代码写 `timeout -= ret`（把剩余换成"已用时间"）⇒ 多元素 fence array 必然提前超时，调用方（`jmo_SURF_WaitFence` 等）会拿着**尚未完成**的缓冲继续用 ⇒ 内容不一致（三角/楔形错位一类）。已改为 `timeout = ret`，并逐元素判断 `f` 而非外层 `fence`。**需重建+重启生效**（`sudo ./scripts/sync_dkms.sh build`） |
| 12 | **开机"桌面卡住一段时间"（厂商栈下 initramfs 白等 GPU 13.7s）** | ✅ **已定位并修（2026-10-08）** | 用**单调时间轴**定位 boot 0 的 initramfs 卡点：`2.0s` 起跑 → `24.696s` `begin wait gpu device` → `38.363s` `No drm device,timeout` = **白等 13.67s**（2000 次 × `sleep 0.005`）。原因：deepin 的 `/init` 里 `wait_for_gpu_device()` 轮询 `/dev/dri/card*`，而**厂商栈下整个 initramfs 阶段没有任何 DRM 设备** —— `MODULES=most` 只扫 `kernel/`、不收 `updates/dkms/*.ko`，`modules-load.d/jmgpu.conf` 又只对切根后的 systemd 生效，同时 `mwv207` 已被 blacklist。系统栈的 `mwv207` 恰好**在 initramfs 里**（`kernel/drivers/gpu/drm/mwv207/mwv207.ko` + udev coldplug）所以从不触发。**修复**：`persist` 往 `/etc/initramfs-tools/modules` 写 `jmgpu` ⇒ initramfs 收进 `updates/dkms/jmgpu.ko`+依赖，并由 `/conf/modules` 在 `~2.4s` 提前 modprobe（早于该等待）。附带发现：`cryptroot`/`crng` 段另有约 10s 发行版侧等待，与驱动无关 |

---

## 7. 给厂商的反馈

> 详细材料见 `docs/VENDOR_FEEDBACK_PRESENTATION.md`。

| # | 项 | 诉求 |
|---|---|---|
| 1 | **SCDC 签名迁移** | `jmgpu_nicely.c` 的 `drm_scdc_*` 需按 6.5+ 签名适配（`drm_connector*`）；同源代码在所有 6.x 内核上都有该问题，§3.1 的补丁可直接回给厂商 |
| 2 | **平面缺 `.prepare_fb` / fence 导出** | 需把 2D / GL / 解码作业的栅栏挂到缓冲的 `dma_resv`，并提供 fence fd 导出 ⇒ 让 `drm_atomic_helper_wait_for_fences()` 在翻页前真正等到"渲染完成"。**这是三角错位的根治方向** |
| 3 | **`GLX_EXT_libglvnd` vendor 名** | X 驱动应通告 libglvnd vendor 名 `mwv207`（当前报 Xorg 默认的 `mesa`）⇒ 这样**无需环境变量**客户端就能选到厂商 GL；同时安装脚本应把 `__GLX_VENDOR_LIBRARY_NAME` 写入 `/etc/environment`（`pkexec` 会清环境，只有 `pam_env` 能覆盖提权应用） |
| 9 | **EGL 销毁上下文未清 libglapi TLS（use-after-free 之源）** | `eglMakeCurrent(EGL_NO_CONTEXT)` 与 `eglDestroyContext()` 之后，厂商自带 libglapi 的 current context TLS **仍指向已释放的内存**（实测值如 `0xffff8ae01010`，不在进程任何映射内）。反编译证据：`libEGL_mwv207.so` **完全没有** `_glapi_set/get_context` 引用。**诉求**：EGL 解绑与销毁路径必须 `_glapi_set_context(NULL)`。复现：`tools/glx_egl_tls_uaf_repro.c`（§8.6.1） |
| 10 | **`jmDestroyContext` 解引用未校验（可被 UAF 触发段错误）** | `jmgpu_dri.so: jmDestroyContext+56` （文件偏移 `0x69638`）执行 `ldr x0,[x0,#376]`，其中 `x0 = _glapi_get_context()` **只做了 `!= NULL` 判断**；当该指针悬垂/非法时直接 SIGSEGV（`#1 dri3DestroyContext` ← `libGLX_mwv207`）。**诉求**：解引用前做有效性防护（与同函数内 `[ctx,#376]/[ctx,#368]` 的 `cbz` 检查保持一致）。触发场景：任何 GTK3/WebKit2GTK 应用（EasyTier、MiniBrowser）析构窗口 |
| 11 | **两套 libglapi / TLS 归属无契约** | 系统 `libglapi.so.0` 与厂商 `libGLX_mwv207` 各带一份 `_glapi_get/set_context`（后者带 `@@VERSION`），`jmgpu_dri.so` 经 `LD_DEBUG=bindings` 绑定到**厂商那份**。请明确 EGL/GLX/DRI 三方共用时 TLS 生命周期的唯一归属，或改为只依赖系统 libglapi |
| 12 | **内核 `jmkOS_WaitNativeFence` 等待预算算错** | `dma_fence_wait_timeout()` 返回**剩余**预算，原代码 `timeout -= ret`（应为 `timeout = ret`）⇒ 多元素 fence array 后续元素预算越缩越小、**提前超时**，调用方带着未完成的缓冲继续用（内容不一致）。我方已修 6.6 分支，**同一函数的旧内核分支有同样写法，建议一并修**（详见本文档 §10.5.2） |
| 4 | **vblank 中断** | 内核默认 5s 后关闭 vblank 中断，驱动无法重新使能 ⇒ 客户端每帧等 1s（已用 `drm.vblankoffdelay=0` 规避，建议驱动侧修复） |
| 5 | reserved-mem 分配器 `.GetSGT` 空桩 | 已由本仓库补齐，**建议在源码层实现**（当前是仓库补丁） |
| 6 | 解码 surface 池整块连续申请 | 可见窗口碎片化时整组回退到 CPU 不可见池，建议按需分块或非连续分配 |
| 7 | `glEGLImageTargetTexStorageEXT` | 已由二进制补丁接回 OES 实现，**建议源码层实现**（驱动升级后需重打补丁） |
| 8 | **压缩 / fastClear** | `compression` 与 `fastClear` 同开时出现卡顿与内核任务态破坏；请确认 `AHBDEC_CONTROL_EX2.TILE_STATUS_READ_ID=4/WRITE_ID=2` 硬编码常量与用户态 `ATTACH_AUX` 各自挂载的 `ts_handle` 之间应有的契约 |

---

## 8. 附录：排查经验

> 这些都是**实际踩过**的坑，按代价从大到小。

### 8.1 三个最贵的坑

| # | 坑 | 症状 | 根因 | 修正 |
|---|---|---|---|---|
| 1 | **`libdrm.so.2.4.0` 只建一处** | `glxinfo` 显示 `llvmpipe`、`glxgears` 仅 **478 FPS**；日志只有模糊的 `glx: failed to create dri3 screen` / `failed to load driver: jmgpu` | 只有 `mwv207_drv.so` 带 RUNPATH；**`libGLX_mwv207`/`libEGL_mwv207`/`jmgpu_dri.so` 三个库没有 RUNPATH**，按系统默认路径查 `libdrm.so.2.4.0` ⇒ `not found` ⇒ 厂商 GLX 加载失败 ⇒ 回落 Mesa | **两处都建**：系统目录 + `mwv207/` 目录 ⇒ **478 → 17,000 FPS** |
| 2 | **`DISPLAY` 拿错** | `DISPLAY=:0 glxinfo \| grep renderer` **无输出**（错误被 grep 吞掉），像"命令跑了没结果" | 本机 X 常起在 `:1`/`:3`/`:4` | 先取 `tr '\0' '\n' < /proc/$(pgrep -x kwin_x11\|head -1)/environ \| grep DISPLAY`，再测试 |
| 3 | **过早持久化 ⇒ 黑屏** | 重启后黑屏，只能还原系统（本机**两次**） | 在驱动尚未验证可用时执行 `update-initramfs`，把「blacklist 原驱动 + 强制加载新驱动」冻结进 initramfs | **正确顺序**：装模块 → **运行时 `driver_override` 验证** → 确认 `glxinfo` 走硬件 → **最后**才持久化，且回退命令先在手 |

### 8.2 判据速查

```bash
# 厂商库依赖是否完整（第一判据，比看日志快）
for f in /usr/lib/aarch64-linux-gnu/mwv207/libGLX_mwv207.so.1.2.0 \
         /usr/lib/aarch64-linux-gnu/mwv207/libEGL_mwv207.so.1.5.0 \
         /usr/lib/aarch64-linux-gnu/dri/jmgpu_dri.so \
         /usr/lib/xorg/modules/drivers/mwv207_drv.so; do
  printf "%-56s " "$(basename $f)"; ldd "$f" 2>&1 | grep -q 'not found' && ldd "$f" | grep 'not found' || echo OK
done

# DKMS 必须是 installed（不是 added）
dkms status | grep mwv207

# 内核是否健康（"多个不相关程序同时异常"时必查）
sudo dmesg | grep -E 'vblank wait timed out|commit wait timed out|BUG:|recursive fault'
```

### 8.3 一次失败的自作聪明：改 `libglx.so`

**动机**：让 glvnd 不依赖环境变量也能选到厂商 GL。

**做了什么**：把 `/usr/lib/xorg/modules/extensions/libglx.so` 的 `"mesa"`（`0x35348`）等长改成 `"mwv207"`。

**结果**：打补丁后 **6 秒**出现

```
[CRTC:35:crtc_0] vblank wait timed out
drm_atomic_helper_wait_for_vblanks … j9_handle_j9m_principium+0x9c/0xc0 [jmgpu]
jmgpu: *ERROR* flip_done timed out / commit wait timed out
Code: d42000c0 (d42000c0)                      ← ARM64 brk #6 = BUG()
Fixing recursive fault but reboot is needed!   ← 内核状态损坏
```

**症状**：EasyTier 图标一闪而过无窗口、`MiniBrowser` 段错误、`cp` 随机 139
（**多个不相关程序同时异常** ⇒ 一定是内核/驱动层）。**回退后 vblank 超时 3 → 0，全部恢复。**

**两个错误**：

1. **改错了库** —— `libglx.so` 是 **Xorg 模块**（server 侧）；客户端走 **glvnd**（`libGLX.so.0`），
   而后者**内部没有默认 vendor 字符串**（实测 `mesa@[]`，vendor 名运行时从 X server 取）
   ⇒ **改 Xorg 模块对客户端毫无作用**。
2. **"更彻底"≠更好** —— 改 server 侧 vendor 会打乱 DDX ↔ 内核驱动的既有协作，触发 vblank 路径失效。

**结论**：保持 `libglx.so` **原版**，变量只写 `/etc/environment`。

### 8.4 操作规范（本机教训，必须遵守）

> **第 0 条（最高优先级）**：**任何会改变"开机行为"的命令，先列命令 + 回退步骤，确认后再执行。**

属"改变开机行为"的操作：

| 类别 | 具体 |
|---|---|
| 写持久配置 | `/etc/modprobe.d/`、`/etc/modules-load.d/`、`/etc/initramfs-tools/`、GRUB |
| 重建 initramfs | `update-initramfs` / `mkinitramfs` / `dracut` / `grub-*` |
| 重启 | `reboot` / 重启 `lightdm` 等显示管理器（**在图形会话里执行会断会话**） |

**为什么**：这些操作会把改动**冻结进 initramfs 或开机路径**。一旦新驱动跑不起来，
开机既加载不到新驱动、又因 blacklist 回不到原驱动 ⇒ **黑屏，只能还原系统**（本机已两次）。

**其余规范**：

1. 一次只改一个变量（否则无法归因）；
2. **能用 sysfs 运行时参数验证的，绝不写加载期参数**；
3. 优先用"不写持久配置"的运行时手段（如 `driver_override`）；
4. 内核改动顺序：**先只加诊断（零行为改变）→ 再上策略（参数开关、默认关）**；
5. 持久化只在"驱动已实测可用 + 回退路径在手"后才做；
6. 改动前先备份（`git diff > /tmp/.../work.patch`）。

### 8.5 已知的系统级坑（与本仓库驱动无关）

| 项 | 说明 |
|---|---|
| **`vfs_monitor`（deepin-anything）** | 在内核 6.6 上触发内核 `BUG()` ⇒ `cp`/`update-initramfs` 随机 139。`sudo rmmod vfs_monitor` 即恢复 |
| **initramfs 不收录 `updates/`** | 默认如此（`MODULES=most` 只扫 `kernel/`）。厂商栈 `persist` 会往 `/etc/initramfs-tools/modules` 写 `jmgpu` 把它收进去（§3.3 #17 / §6 #12）；`sync_dkms.sh` 的"initramfs 校验失败"曾是**误报**，脚本已于 2026-10-08 修正（§6 #7） |
| **initramfs 里 `wait_for_gpu_device()` 白等 13.7s** | deepin 的 `/init` 会轮询 `/dev/dri/card*` 最多 2000×5ms。只要该阶段没有 DRM 设备（厂商栈的默认形态），每次开机都白等 ~13.7s ⇒ 表现为"卡住一段时间"。修法见 §3.3 #17（把 `jmgpu` 放进 initramfs） |
| **`Xorg` 的 `DISPLAY` 每次重启都变** | 所有 X 侧测试前先取当前会话的 `DISPLAY` |
| **journal 里早启动阶段的 wall 时间不可信** | journald 导入 kmsg 积压时会把整个 initramfs 的 kernel 消息压到几毫秒内（实测 39s 压成 160ms），**只有单调时间（`-o short-monotonic`）可用于分析开机耗时** |

### 8.6 厂商栈下 **WebKitGTK 应用必崩**（EasyTier 打不开的真正原因）

**症状**：切到厂商栈后，EasyTier（Tauri + WebKitGTK）**任务栏图标一闪而过、无窗口**；
journal 只见 `pkexec[...]: pam_unix(polkit-1:session): session opened for user root` 之后**再无下文**。
`MiniBrowser` 同样崩溃。

**实测矩阵**（都以 pkexec 等价的纯净环境运行 12 秒，`124`＝存活、`139`＝SIGSEGV）：

| 环境 | 结果 |
|---|---|
| 只给 `DISPLAY/XAUTHORITY/HOME`（无 GL 变量） | **124 存活** ✓ |
| `+ __GLX_VENDOR_LIBRARY_NAME=mwv207` | **139 崩溃**（重复 2/2）✗ |
| `+ __EGL_VENDOR_LIBRARY_FILENAMES=…10_mwv207.json` | **139 崩溃** ✗ |
| 只有 `vblank_mode=0` | 124 存活 ✓ |
| `__GLX_VENDOR_LIBRARY_NAME=mwv207` **+ `WEBKIT_DISABLE_COMPOSITING_MODE=1`** | **124 存活** ✓（连跑两次） |
| `__GLX_VENDOR_LIBRARY_NAME=mwv207` + `LIBGL_ALWAYS_SOFTWARE=1` | 124 存活 ✓ |

⇒ 初步结论（已被下面的深挖推翻并细化）：**厂商 GL 会让 WebKitGTK 段错误**。
而 `__GLX_VENDOR_LIBRARY_NAME=mwv207` 是厂商栈的**必需**变量（第 11 项，否则 GL 走 Mesa/llvmpipe），
它经 `pam_env` 注入到 **pkexec 提权实例** ⇒ **必崩**。

#### 8.6.1 真根因：**厂商 EGL 留下悬垂的 libglapi TLS current ⇒ GLX 销毁时解引用**（2026-09-18）

用 core + gdb + 反编译把它钉到了指令级：

```
GTK3/WebKit2GTK 析构窗口
 → gdk_window_destroy → g_object_run_dispose   (libgdk-3.so)
 → glXDestroyContext                            (libGLX_mwv207.so)
 → dri3DestroyContext                           (libGLX_mwv207.so)
 → jmDestroyContext                             (jmgpu_dri.so)  ← SIGSEGV
   崩溃指令： jmDestroyContext+56  ldr x0,[x0,#376]
   x0 = _glapi_get_context() = 0xffffc0481010（**不在进程任何映射内** ⇒ 悬垂/UAF）
```

**逐阶段 TLS 值**（`tools/glx_egl_tls_uaf_repro.c` 输出，厂商栈）：

| 阶段 | TLS `current` | 判读 |
|---|---|---|
| 加载厂商 `libGLX_mwv207` 后 | `(nil)` | 起点正常 |
| `eglCreateContext` 后 | `(nil)` | — |
| `eglMakeCurrent` 后 | `0xffff8ae01010` | EGL 绑定时写入（正常） |
| **`eglMakeCurrent(EGL_NO_CONTEXT)` 后** | `0xffff8ae01010` | ★ **解绑未清** |
| **`eglDestroyContext` 后** | `0xffff8ae01010` | ★★ **销毁后仍留着悬垂值** |
| `glXDestroyContext` | — | **SIGSEGV** |

**反编译佐证（三条独立证据）**：

| 证据 | 出处 |
|---|---|
| `libEGL_mwv207.so` 中**完全没有** `_glapi_set_context` / `_glapi_get_context` 引用 ⇒ EGL 侧从不清理 TLS | `objdump -d` 全库扫描 |
| `_glapi_get/set_context` 有**两个提供者**（系统 `libglapi.so.0` 与厂商自带的 `libGLX_mwv207`），且 `jmgpu_dri.so` 经 `LD_DEBUG=bindings` 绑定到**厂商那份**（`@@VERSION`） | `LD_DEBUG=bindings` |
| 同函数内 `[ctx,#376]` / `[ctx,#368]` 访问**都有 `cbz` 空指针检查**，唯独 `[current,#376]`（`current=_glapi_get_context()`）**只判 `!= NULL`** | `jmDestroyContext` 反汇编 |

⇒ 三个缺陷串成一条链，任一处修好都能消除崩溃：
1. **EGL 解绑/销毁不清 TLS**（`libEGL_mwv207` / DRI 的 EGL 路径）——**主缺陷**；
2. **`jmDestroyContext` 解引用前不校验指针有效性**——纵深防御缺失；
3. 两套 `libglapi`（系统 + 厂商自带）共存，TLS 归属无契约——架构隐患。

**确定性复现（厂商 5 秒可跑）**：`tools/glx_egl_tls_uaf_repro.c`

```bash
gcc -O2 -o glx_egl_tls_uaf_repro tools/glx_egl_tls_uaf_repro.c -lEGL -lGL -lX11 -ldl

# ① 复现（预期 SIGSEGV）
__GLX_VENDOR_LIBRARY_NAME=mwv207 DISPLAY=:0 ./glx_egl_tls_uaf_repro
# ② 对照：跳过 EGL ⇒ 不崩（证明 EGL 阶段是前置条件）
__GLX_VENDOR_LIBRARY_NAME=mwv207 DISPLAY=:0 ./glx_egl_tls_uaf_repro --no-egl
# ③ 对照：EGL 走 Mesa（GLX 仍厂商）⇒ 不崩
__GLX_VENDOR_LIBRARY_NAME=mwv207 \
__EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/50_mesa.json \
DISPLAY=:0 ./glx_egl_tls_uaf_repro
```

> 注：单纯 GLX `create+destroy` **不崩**（对照组 ② 的 TLS 是**有效**上下文，走正常分支）；
> 必须"EGL 先用过"才崩 —— 这正是 WebKitGTK 类应用的形态（EGL 与 GLX 并存）。

**三种可用规避（均已实测）**：

| 方案 | 命令/位置 | 代价 | 适用 |
|---|---|---|---|
| **A（已采用）** | `/etc/environment`：`WEBKIT_DISABLE_COMPOSITING_MODE=1` | WebKit 不做加速合成 | **最稳**：`pam_env` 交付，**对 pkexec 提权进程同样生效** |
| B | `/etc/environment`：`__EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/50_mesa.json` | EGL 硬件路径全失效（**含 VA-API 零拷贝**） | 不推荐全局 |
| C | `LD_PRELOAD=tools/glxguard.c` 编译出的 `glxguard.so` | 需逐进程注入 | **对提权进程无效**（loader 忽略 setuid 程序 `LD_PRELOAD`） |

**临时守卫** `tools/glxguard.c`（C 方案）：在 `glXDestroyContext` 前把厂商那份 TLS 清空，
使 `jmDestroyContext` 走其已有安全分支：

```
无守卫： glXDestroyContext → 段错误
有守卫： [glxguard] 清除悬垂 current=0xffff80991010 后再销毁 ⇒ 完成 ✓
```

> **为何 9/17 能用、现在不能**：系统升级（内核 6.6.155 + glvnd/WebKitGTK/Mesa 更新）后，
> 该应用路径上出现了"EGL 先建/销毁上下文、随后 GLX 销毁"的组合。
>
> 这属于**厂商用户态栈的 use-after-free**（且是安全相关问题），已列入 §7 给厂商的反馈（第 9～11 条）。

#### 8.6.3 守卫的能力边界（**诚实修正**，2026-09-18）

用 `tools/wkmin.c`（最小 WebKit 复现器 + `ffmpeg` 抓屏 + 像素统计）做客观判定：

| 配置 | 是否崩 | 画面（红=页面内容） |
|---|---|---|
| 厂商栈 + 加速合成（无规避） | **段错误** | 无内容（93.9% 白） |
| **+ `glxguard` 守卫** | **仍段错误** ✗ | 无内容 |
| + `WEBKIT_DISABLE_COMPOSITING_MODE=1` | 不崩 ✓ | **400×966 红块** ⇒ 窗口正常 ✓ |

⇒ **守卫拦不住 WebKit 的真实形态**，原因（已用 gdb 核实）：这次悬垂指针是
`0xffffd8391010`，落在**仍然映射着的内存池**里（对象已释放、整块 mmap 还在）
⇒ `mincore()` 判定"已映射" ⇒ v1 的"未映射才清"判据失效；v2 改为"按语义在解绑/销毁当前上下文时清"
也无效，因为 WebKit 的这条路径**既没走 EGL 解绑、也没走 GLX 解绑**（用户态无从观测到那一跳）。

**结论**：`glxguard` 只对"独立复现器那类 munmap 型悬垂"有效，**对 WebKit 实际形态无效**。
⇒ 该缺陷仍必须由厂商在 EGL 侧根治（§7 第 9～11 条）；本机继续用
`WEBKIT_DISABLE_COMPOSITING_MODE=1`（§3.3 #16）。

### 8.6.2 我方修复尝试与最终方案（2026-09-18）

**先试原生补丁（3 处，全部用 gdb/coredump 逐条验证）**：

| # | 补丁点 | 结果 |
|---|---|---|
| 1 | `jmgpu_dri.so: veglMakeCurrent_es3+0x6c`：`cbz x19, <早返回>` → `b <调用 _glapi_set_context>` | ❌ **不生效**（已回退）：实测 EGL 解绑/销毁**根本不进 DRI**，此函数全程只被调用 1 次（绑定那次） |
| 2 | `jmgpu_dri.so: jmDestroyContext` 跳过对 current 的解引用 | ❌ 不安全：会在另一处（`[current+384]`）再次解引用悬垂指针；且会破坏"销毁非当前上下文"时的状态保存 |
| 3 | `libGLX_mwv207: dri3DestroyContext` 入口插"悬垂即清"桩 | ❌ 不可行：GLX 侧**无法区分**"已释放的悬垂指针"与"仍然存活的当前上下文"，清错会破坏多上下文应用 |

> 结论：**根治必须在厂商 EGL 侧**（我们无法在消费者侧安全地判断指针死活）。
> 但已定位到三个精确的厂商缺陷点（见 §7 第 9～11 条与本文档 §10.6）：
> `veglMakeCurrent_es3` 的 NULL 分支不设 TLS、`veglDestroyContext_es3` 不清 TLS、
> 以及 EGL 上下文从未维护 DRI 的"current 标志"（`[ctx->[16] + 0xac000 + 11272]`）
> ⇒ 所有"lose/destroy current"清理逻辑（`jmLoseCurrent` @693c4、`jmDestroyContext` @696c0）
> 全部被跳过。

**最终采用：用户态守卫 `glxguard.so`**（`tools/glxguard.c`，本仓库已实现并验证）

判据用 `mincore()`：**只清"已不在任何映射中"的真悬垂指针**；合法的当前上下文绝不触碰
（这解决了上面第 3 条"无法区分"的矛盾——在用户态可以用 syscall 判定）。

```
悬垂场景  ： [glxguard] 检出悬垂 current=0xffffa20d1010（未映射）→ 清空后再销毁 ⇒ 未崩溃 ✓
多上下文  ： [glxguard] current=0xffff881d0010 仍在映射内，保持不动 ⇒ 当前上下文不受影响 ✓
对照组(无守卫)： glXDestroyContext ⇒ 段错误 139（证明守卫就是修复）
```

**部署**（对 EasyTier 生效，且**保留 WebKit 加速合成**）：

```bash
sudo bash tools/fix_easytier_glxguard.sh apply     # 编译守卫到 /usr/local/lib/ + 包装 /usr/bin/easytier-gui
sudo bash tools/fix_easytier_glxguard.sh status
sudo bash tools/fix_easytier_glxguard.sh revert    # 回退（还原原始二进制）
```

- 为什么用**包装脚本**而不是 `/etc/environment` 里的 `LD_PRELOAD`：EasyTier 会经 **pkexec 提权**
  再启动一次，pkexec 会清环境且提权进程由 ld.so 忽略 `LD_PRELOAD`；包装脚本自身以普通方式
  exec 非 setuid 目标，可自行注入 ⇒ **提权实例同样带上守卫**（与 `~/fix_dock_mesa.sh` 的 dde-shell 包装同一套路）。
- 采用守卫后，`/etc/environment` 里的 `WEBKIT_DISABLE_COMPOSITING_MODE=1`（第 16 项）**已移除**，
  WebKit 恢复加速合成；若某应用仍表现异常，可把该行加回作为备用规避。
