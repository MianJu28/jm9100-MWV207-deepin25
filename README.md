# JM9100 (MWV207) GPU 驱动移植与视频硬解

> 平台：**飞腾 D3000 + 景嘉微 JM9100**（PCI `0731:9100`），内核 **6.6-arm64-desktop-hwe (Deepin 25)**。
> 目标：把闭源 **jmgpu 1.7.0** 内核驱动移植到 6.6，**同时**点亮显示与打通 VA-API 硬解。
>
> **当前状态：显示 ✅ · GL 硬件加速 ✅ · VA-API 零拷贝直通 ✅**
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

> ⚠️ `sync_dkms.sh` 报"**initramfs 校验失败**"通常是**误报**（本系统 initramfs 不收录
> `updates/` 目录），只要 `dkms status` 是 `installed` 即算成功（见 §6 遗留问题 7）。

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

### 2.9 最后：持久化（可选，**确认上面全绿后再做**）

```bash
cd ~/Desktop/Git/jm9100
sudo ./scripts/force_mode_test.sh boot      # blacklist mwv207 + modules-load jmgpu + 进 initramfs
sudo reboot
# 回滚：
sudo ./scripts/force_mode_test.sh boot-undo && sudo reboot
```

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

**同族但有意未改**：`jmgpu_program.c`（MMU/STLB）、`jmgpu_refactor.c`（堆空闲链表）等处的 `JMM_kASSERT`
属**内部不变量**，值不受用户控制，改运行时检查收益低而回归面大。

### 3.2 用户态（厂商闭源库的字节补丁）

| # | 目标 | 做法 | 脚本 / 产物 |
|---|---|---|---|
| 8 | **专有 X 驱动无法加载**（ABI 24→25 + 清理路径 `NULL+0x48` 段错误） | ① `XF86ModuleVersionInfo.abiversion` 24.0→25.0；② Xorg 1.21 删除了 `xf86str.h` 的 `Bool flipPixels` ⇒ `ScrnInfoRec` 其后字段整体 **−8 字节**，回调槽错位 | `tools/patch_xorg_abi.py` + `build-cli/patch_abi_layout.py` ⇒ 产物 **`build-cli/mwv207_drv.so.abi25.fixed3`**（md5 `297aee83…`） |
| 9 | **`glEGLImageTargetTexStorageEXT` 未实现**（VA-API 零拷贝必须挂 `LD_PRELOAD`） | 给 `jmgpu_dri.so` 补扩展广告 + `libEGL_mwv207.so`/`libGLX_mwv207.so` 加入口别名（纯字节补丁） | `tools/patch_gl_storage.py` ⇒ 产物 `build-cli/*.glstorage` |
| 10 | **TearFree 的 2D 上传后不等引擎完成**（画面三角/楔形错位） | 把上传例程返回前的 `ldp x29,x30,[sp,#16]` 改成 `bl 等2D空闲封装`（该封装驱动里本就存在、却 0 引用） | `tools/patch_ddx_tearfree_sync.py`（**未验证效果**，见 §6） |

### 3.3 系统配置（非仓库代码）

| # | 项 | 内容 | 原因 |
|---|---|---|---|
| 11 | `/etc/environment` | `__GLX_VENDOR_LIBRARY_NAME=mwv207` | glvnd 需要它才用厂商 GLX；**`pkexec` 会清空环境**，只有 `pam_env`（读 `/etc/environment`）这条链路能覆盖提权应用（否则 EasyTier 等 **白屏**） |
| 12 | `/etc/tmpfiles.d/drm-vblank.conf` + `drm-vblank-fix.service` | 开机把 `drm.vblankoffdelay` 写为 **0** | 内核默认在最后一个 vblank 使用者释放后 5s 关闭 vblank 中断，厂商驱动无法重新使能 ⇒ 客户端每帧等 1s（**1 FPS → 1.4 万 FPS**） |
| 13 | `dconfig org.kde.kwin.compositing:user_type=4` | kwin 用 **XRender** 合成 | 厂商 GL 合成实测仅 8 fps，XRender 47 fps |
| 14 | `/usr/bin/dde-shell` 包装 | 改走 Mesa（原二进制备份为 `dde-shell.real`） | 任务栏高频重绘，厂商 GL 只有 1–11 fps；`~/fix_dock_mesa.sh` 应用/回退 |
| 15 | `10-mwv207.conf` | `MatchDriver "jmgpu"` + `Driver "mwv207"` | 让 X 使用厂商 DDX（**切回系统驱动时必须删除**，否则 X 起不来） |

### 3.4 已排除（勿再尝试）

| 方案 | 结论 |
|---|---|
| 改 `libglx.so`（Xorg 模块）的默认 GLX vendor | ❌ **无效且有害** —— 客户端走的是 glvnd（`libGLX.so.0`，内部无默认 vendor 字符串），改 Xorg 模块不起作用；反而打乱 DDX↔内核协作，**触发 vblank 超时 + 内核 `BUG()`**（详见 §8.3） |
| 让 EGL 覆盖全部 visual | ❌ 不需要 —— 实测 `eglCreateWindowSurface` 不做 config↔visual 匹配校验，90/90 visual 都能建面渲染 |
| 全局关压缩 `compression=0` | ⚠️ 可缓解卡顿，但**不是错位主因**（详见 §6） |

---

## 4. 部署与切换

### 4.1 首次部署 / 持久化 / 回滚

```bash
cd ~/Desktop/Git/jm9100

# 厂商栈接管持久化（blacklist mwv207 + modules-load 强制加载 jmgpu + 进 initramfs）
sudo ./scripts/force_mode_test.sh boot && sudo reboot

# 回滚到系统自带 mwv207
sudo ./scripts/force_mode_test.sh boot-undo && sudo reboot
```

> ⚠️ **持久化会改写开机路径**：一旦新驱动在该内核上跑不起来，开机既加载不到新驱动、
> 又因 blacklist 回不到原驱动 ⇒ **黑屏只能还原系统**。
> **务必先用运行时手段验证**（`driver_override`），确认可用后再持久化，且**回退命令先在手**。

### 4.2 改驱动源码后的标准流程

```bash
cd ~/Desktop/Git/jm9100
./scripts/sync_dkms.sh build      # 同步 + dkms build/install + update-initramfs -u
sudo reboot
```

> **红线**：`dkms install` 后**必须重建 initramfs 再重启**——开机早期 `modules-load`
> 加载的是 **initramfs 里冻结的模块副本**，否则新代码永远不生效（历史上多次"修复无效"的误判均源于此）。
>
> 验证：
> ```bash
> cat /sys/module/jmgpu/srcversion                                      # 运行中
> modinfo -F srcversion /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko  # 磁盘
> # 两者一致 = 新模块已生效
> ```

### 4.3 两套栈切换（`scripts/switch_stack.sh`）

```bash
sudo ./scripts/switch_stack.sh status     # 只读：查看当前栈与配置差异
sudo ./scripts/switch_stack.sh vendor     # 切到厂商栈（需手动重启）
sudo ./scripts/switch_stack.sh system     # 切回系统驱动（**升级系统前**必做；需手动重启）
sudo ./scripts/switch_stack.sh backup     # 备份现有配置
sudo ./scripts/switch_stack.sh restore    # 回到上次备份
```

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
   若 DKMS 注册丢失，先建源码目录：
   ```bash
   sudo mkdir -p /usr/src/mwv207-1.7.0.uos
   cd ~/Desktop/Git/jm9100/kernel && sudo cp -f *.c *.h Makefile* dkms.conf Kconfig* /usr/src/mwv207-1.7.0.uos/
   sudo dkms add mwv207/1.7.0.uos
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
7. **系统配置**：§3.3 的 11~15 项

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

---

## 6. 遗留问题

| # | 问题 | 状态 | 说明 |
|---|---|---|---|
| 1 | **画面三角/楔形错位**（视频窗口内，偶发） | ⚠️ **未根治** | 已定位为"**写入扫描缓冲 ↔ 扫描输出 之间缺同步/一致性**"，且写入方**覆盖 2D 引擎与 CPU 两条路径**（`TearFree off` 能显著减少；`Accel off` 后仍复现）。**核内无法根治**，需厂商补 `.prepare_fb` + fence 导出（见 §7）。已写补丁 `tools/patch_ddx_tearfree_sync.py` 但**效果未验证** |
| 2 | `compression=15`（默认）下**卡顿 + 内核任务态破坏** | ⚠️ 规避可用 | 与 `fastClear` 组合有关；`compression=0` 或 `fastClear=0` 可规避。**但该现象在系统自带驱动下也偶现** ⇒ 不能完全归因于本驱动 |
| 3 | **CPU 写合并（`enable_wc`）一致性** | ⚠️ **未验证** | `Accel off` 仍错位 ⇒ 怀疑 `pgprot_writecombine` 的 posted 写未被显示读到。验证方案（`enable_wc=0`）**曾导致无法启动**，未得结论。后续验证**必须用可回退方式** |
| 4 | kwin GL(`gl2`) 合成只有 ~8 fps | ✅ 已规避 | 用 `user_type=4`（XRender）绕过；属厂商侧 |
| 5 | 任务栏（`dde-shell`）走厂商 GL 掉帧 | ✅ 已规避 | 包装改走 Mesa（§3.3 #14） |
| 6 | `cp` / `update-initramfs` **随机 139** | ✅ 已定位（**非本驱动**） | 根因是 `deepin-anything` 的 **`vfs_monitor.ko`** 在内核 6.6 上触发 `BUG()`（ARM64 `brk #6`，`Tainted: G D OE`）。`sudo rmmod vfs_monitor` 后 100 次复制 **0 失败**、`update-initramfs` **rc=0**。持久规避：`blacklist vfs_monitor`（代价：deepin 文件索引失效） |
| 7 | `sync_dkms.sh` 报"initramfs 校验失败" | ✅ 属**误报** | 本系统 initramfs **不收录 `updates/`（DKMS）目录**（实测 `updates/*.ko`=0、`kernel/drivers/*.ko`=1636）。DKMS 模块由 rootfs 阶段 udev modalias 加载 ⇒ **校验失败 ≠ 安装失败**，只需确认 `dkms status` 为 `installed` |
| 8 | GL 兼容层 `libjm_gl_compat.so` | ✅ **已退役** | glstorage 补丁已原生支持，系统级兼容层已卸载（无需 `LD_PRELOAD`） |
| 9 | 零拷贝依赖 mpv 补丁 | ⚠️ 已知 | 升级 mpv 后需重新应用 `patches/mpv_dmabuf_oes_image.patch`（系统级 `LD_PRELOAD` 兼容层亦可，但已退役） |

---

## 7. 给厂商的反馈

> 详细材料见 `docs/VENDOR_FEEDBACK_PRESENTATION.md`。

| # | 项 | 诉求 |
|---|---|---|
| 1 | **SCDC 签名迁移** | `jmgpu_nicely.c` 的 `drm_scdc_*` 需按 6.5+ 签名适配（`drm_connector*`）；同源代码在所有 6.x 内核上都有该问题，§3.1 的补丁可直接回给厂商 |
| 2 | **平面缺 `.prepare_fb` / fence 导出** | 需把 2D / GL / 解码作业的栅栏挂到缓冲的 `dma_resv`，并提供 fence fd 导出 ⇒ 让 `drm_atomic_helper_wait_for_fences()` 在翻页前真正等到"渲染完成"。**这是三角错位的根治方向** |
| 3 | **`GLX_EXT_libglvnd` vendor 名** | X 驱动应通告 libglvnd vendor 名 `mwv207`（当前报 Xorg 默认的 `mesa`），否则凡经 `pkexec`/纯净环境启动的 WebKit/Chromium/GTK 程序都会让 glvnd 回落 Mesa 而崩溃；安装脚本也应把 `__GLX_VENDOR_LIBRARY_NAME` 写入 `/etc/environment` |
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
| **initramfs 不收录 `updates/`** | `sync_dkms.sh` 的"initramfs 校验失败"是**误报** |
| **`Xorg` 的 `DISPLAY` 每次重启都变** | 所有 X 侧测试前先取当前会话的 `DISPLAY` |
