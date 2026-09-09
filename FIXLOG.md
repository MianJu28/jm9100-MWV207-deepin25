# JM9100 修复记录

> 本文档记录对闭源 jmgpu 1.7.0 内核驱动（移植到 6.6.143）的修复过程与排查记录。
> 配套：README.md（整体探索记录）、`force_mode_test.sh`（强制点屏/持久化）、
> `color_bisect.sh`（色彩二分实验）、`dump_display_regs.sh`/`dump_full_regs.sh`
> （寄存器 dump 对比）、`fix_win_contrast.sh`（LUT 相关键写回，诊断用）。
>
> **2026-09-08 状态**：问题 2（灰蒙蒙）已解决——X 专有驱动 gamma 下发的 1/3
> 缩放缺陷，内核 `gamma_norm=3` 归一化修复（见修复 5/6）。改驱动后的部署必须
> `./sync_dkms.sh build`（含 update-initramfs，否则 initramfs 冻结旧模块）。

---

## 修复 1：HDMI 无信号（内核 oops）—— 已解决 ✅

### 症状
- jmgpu 接管后 connector `connected`，桌面/彩条无任何信号输出
- 早期误判为"寄存器时序/phy 固有问题"（实为 sysfs 误诊，见 README §3）

### 根因（内核 oops 栈定位，两个移植遗漏叠加）
1. HDMI connector `late_register` 里创建了自管 i2c adapter `hdmi->ddc`，
   但从未同步到内核标准字段 `connector->ddc`（恒 NULL）。
   EDID 读取走自管 adapter，一直正常，掩盖了问题。
2. 内核 6.5+ 将 `drm_scdc_set_scrambling/set_high_tmds_clock_ratio` 签名由
   `(struct i2c_adapter*, bool)` 改为 `(struct drm_connector*, bool)`；
   厂商本地 adapter 版实现被 `#if < KERNEL_VERSION(4,12,0)` 条件块排除，
   6.6 下调用链接到内核 connector 版 → 内部取 `connector->ddc`=NULL
   → `i2c_transfer(NULL)` → translation fault → atomic commit 中断 → 无信号。

```
drm_mode_setcrtc → drm_atomic_commit → commit_tail
  → drm_atomic_helper_commit_modeset_enables
    → j9_handle_j9m_principium → j9_troglodyte → hdmi_phy_config_para [jmgpu]
      → drm_scdc_set_scrambling [drm_display_helper]   ← 内核符号(签名已变)
        → i2c_transfer → el1_abort → do_page_fault      ← 空指针 oops
```

### 修复（全在 `jmgpu_nicely.c`）
| # | 修复 |
|---|---|
| 1 | `late_register` 中补 `hdmi->connector.ddc = hdmi->ddc;`（init memset 之后） |
| 2 | 8 处 `drm_scdc_set_scrambling/set_high_tmds_clock_ratio(&hdmi->connector,…)` → `jmgpu_scdc_*(hdmi->ddc,…)` |
| 3 | `jmgpu_scdc_set_scrambling/set_high_tmds_clock_ratio` 定义移出 `#if <4.12` 条件块 |

### 验证
- `modetest -M jmgpu -s 41@35:1920x1080` → rc=0，屏幕出现彩条
- 无 SCDC 显示器下 `jmgpu_scdc_*` 读寄存器 NACK（err=-6）→ 无害降级继续
- 持久化（`force_mode_test.sh boot`）后 lightdm + 专有 X 驱动点亮桌面
- `vainfo` 同栈报全 profile：H264 全系 / HEVC Main+Main10 / VP9 / JPEG VLD

---

## 问题 2：显示灰蒙蒙（低对比度）—— 已解决 ✅（2026-09-08，修复 4/5/6）

### 症状（照片证据：IMG_20260903_155328.jpg / IMG_20260903_165113.jpg）
- jmgpu 栈下任意内容（桌面 / X / modetest 彩条）整体低对比度：
  **黑色发灰、白色不白、色相完全正确** —— 典型"数据 16-235 被按 0-255 解释"形态
- 硬件鼠标光标色彩正常（cursor plane 不经过主 surface 后处理路径）
- 同显示器在 mwv207（deepin 开源内核）栈下显示完全正常

### 已确认事实
| 事实 | 手段 |
|---|---|
| X/FB 内容色彩正常 | deepin 截屏 vs 拍屏对比 |
| 灰在内核输出层（与 X 无关） | `color_bisect.sh` 实验 A：modetest 直出彩条仍灰 |
| DDC/EDID 正常 | 真 EDID 可读（N24188，43 modes）；曾误入"Linux FHD"假 EDID 为 grub 残留所致，已清理 |
| 输出恒为 RGB888_1X24 | `j9_handle_j9min_serologist` 仅构建 DEBUG 列表未被消费，3074 行恒定设 RGB888 |
| LUT fifo 写入无超时 | `dmesg` 无 "Timeout waiting for lut fifo" |
| 闭源 LUT 写入实现与开源等价 | 与 `mwv207-dkms/dc/mwv207_va.c` 的 `mwv207_va_lut_enable` 逐寄存器对比（fifo 0x444/0x448/0x44C/0x440、数据公式 `(data[i/4]<<2)|0x03`、循环 1024） |
| `lutdata` 已初始化线性表 | CRTC init 处 256 项×3 通道 = i |
| reset 回调会写 LUT | `.reset = j9_nonvegetative` → `j9_handle__autoclasis`（`vdisplay=false` 不早退，dmesg 无 Virtualization 日志） |

### 已尝试方案（均无效，按时间序）
| # | 方案 | 结果 |
|---|---|---|
| 1 | `rgb_limited_range` 加 `display_info.rgb_quant_range_selectable` 条件（full 直通 + FULL 声明） | 无效 |
| 2 | 清理 grub 残留 `video=HDMI-A-1:…e` + `drm.edid_firmware=…`（假 EDID "Linux FHD"） | 真 EDID 恢复，仍灰 |
| 3 | `virtual_display=0`（验证 vdisplay 早退假设） | 假设不成立（dmesg 无 Virtualization 行），无效 |
| 4 | 数据恢复 limited（CEA 默认）+ 手写 AVI 量化范围声明 LIMITED（绕过内核把 LIMITED 改写 FULL 的行为） | 无效 |

### 已排除
- CSC `rgb_limited_range` 数据压缩路径（full/limited 两方向均试过）
- AVI infoframe 量化范围声明内容（内核函数改写 vs 手写，均试过）
- YCC 输出路径（输出恒 RGB888）
- X / 专有驱动 mwv207_drv.so（modetest 绕过 X 仍灰）
- palette/LUT fifo 写入超时（dmesg 无错）
- 闭源 LUT 写入寄存器序列错误（与开源等价）
- 假 EDID / cmdline 残留（已清理）

### 待验证方向（后续排查入口）
1. **显示器 OSD**：Black Level / RGB Range 选项切 High/Full —— 若恢复则证明
   AVI infoframe 未被显示器采纳（未发出或发出但显示器不解析）
2. **AVI infoframe 是否实际发出**：`FC_AVICONF0/1/2` 写入后 packet 调度与
   发送使能（对照开源栈的 packet 控制寄存器序列）
3. **GCP（General Control Packet）** 量化声明（`HDMI_FC_GCP`）
4. **LUT 硬件实际值**：寄存器级 dump 验证 `j9_handle__autoclasis` 是否静默失败
   （失败路径 `return -2` 无日志，reset 调用处亦不检查返回值）
5. **VP remap/stuffing**（`HDMI_VP_STUFF_IDEFAULT_PHASE` 已置 1，验证是否恰当）
6. **与 mwv207 开源栈逐寄存器对比**：dc（VA 单元）+ HDMI 输出域全量 dump，
   找出两栈驱动行为差异
7. **CSC 时钟/flow-control**：`j9_homography()==false` 时 `CSCCLK disable +
   FEED_THROUGH_OFF_CSC_BYPASS` 是否真正生效

### 修复 4（2026-09-07）：LUT 双 palette RAM 只写一块就切换 —— 已修复，待真机验证 🔧

**排查方法**：FIXLOG 待验证方向 6（与开源栈逐寄存器对比）。开源参考：
`mwv207-dkms/dc/`（Icenowy）与 `jm9100-oh`（官方 6.6 patch），本仓库副本
`/home/admin/Desktop/Git/`。

**对比结论**：HDMI TX 域两栈**逐寄存器等价**（CSC 系数/scale、AVICONF0-3+VIC+bar、
VSIF enable 序列 0x10B3/10B4/10B5、无 GCP、VP packetize、MC_CLKDIS/FLOWCTRL 分支、
preamble 0x0B/0x16/0x21）；DC/VA 域也等价（timing 0x400-0x420、primary plane
0x430/434/438/43C/4F8、BACK_PROCESS_MODE 0x2A0 的 enable-RMW/disable-写 2 序列、
WIN_CONTRAST 0x38 公式 `lutdata[384]*15/8|bit31`、lutdata 线性初始化、
`drm_crtc_enable_color_mgmt`）。

**唯一实质差异**（对比 `jmgpu_package.c:j9_handle__autoclasis` 与
`mwv207_va.c:mwv207_va_lut_enable`）：
palette RAM 是**双缓冲**，开源**两块都写**（`for (ram = 0; ram < 2; ram++)`，
每轮重新读 0x440 当前 active，写完切 `1-active`），两轮后 active 回到初始块且
两块内容均为线性表；闭源**只写当前 active 块，随即把 active 切到另一块
（从未写过）** —— 实际显示采样的是那块 RAM 的**上电默认内容**，而非 lutdata。

**症状吻合度**：
- LUT 只作用于 primary surface，硬件光标 plane 直通 → 光标色彩正常 ✅
- modetest/X 都不触发第二次 LUT 写入（`color_mgmt_changed && gamma_lut`）→ 恒灰 ✅
- mwv207 栈两块都写 → 与默认内容无关 → 正常 ✅
- 冷启动后稳定复现（RAM1 每次上电都是同一默认表）✅

**修复**（`jmgpu_package.c`）：`j9_handle__autoclasis` 改为与开源一致的双 RAM
循环；同时为 fifo 超时失败路径（原 `return -2` 静默，方向 4）补 `DRM_ERROR` 日志。
`sync_dkms.sh build` + `dkms install --force` 编译签名通过。

**验证步骤**：`reboot`（或卸载重载 jmgpu）后观感对比；若仍灰，用
`dump_display_regs.sh` 在两栈各 dump 一份寄存器 diff（重点 0x440/0x450/0x460、
HDMI 0x4001/0x4004/0x4100-0x411B/AVI 区）。

**若无效的后续方向**：显示器 OSD Black Level 验证（方向 1）、两栈寄存器全量
diff（方向 6，脚本已备）、AVI infoframe 抓包（HDMI 分析仪/电视串口）。

---

### 修复 5（2026-09-08）：根因确认 —— X 专有驱动的非恒等 gamma ramp 污染硬件 LUT ✅

> 注：本修复（`gamma_support=off` 应急跳过）后被修复 6 的归一化方案取代；
> 本节的价值在根因定位过程与诊断方法。

**排查方法**：`dump_display_regs.sh` 两栈寄存器对比（jmgpu vs mwv207，同机切换）。

**证据链**：
1. **HDMI TX 域两栈逐寄存器完全一致**（VP/AVI/CSC 系数/MC_CLKDIS/MC_FLOWCTRL，
   diff 为空）→ FIXLOG 方向 2/3/5/7 全部排除，TX 侧无嫌疑。
2. VA/DC 域唯一实质差异：`WIN_CONTRAST`(0x990038, 公式 `lutdata[384]*15/8|bit31`)
   —— mwv207 栈 `0x800000F1`（lutdata[384]≈128，线性恒等表）；
   jmgpu 栈 `0x8000004E`（lutdata[384]≈42，**严重暗化的非恒等表**）。
3. LUT 写入路径只有两条：crtc reset（写线性表）与 atomic_flush 的
   `gamma_lut` 提交（写用户态 ramp）→ 非恒等表必来自用户态 gamma。
4. 链路实锤：`xrandr --output HDMI-1 --gamma 0.3:0.3:0.3` 下发后 LUT 寄存器
   **立即变化**（CONTRAST 0x4E→0x01，fifo 末端 data 7）；而 identity 请求
   (`--gamma 1:1:1`) 后 CONTRAST 仍 0x4E —— **X 专有驱动 (mwv207_drv.so，
   内含 xf86SetGamma) 即使收到恒等 gamma 请求，下发给内核的 ramp 也非恒等**。

**结论**：X 专有驱动的 gamma/ramp 处理缺陷 → 每次桌面启动都把暗化曲线写进
jmgpu 硬件 LUT → 整体低对比度（黑发灰/白不白/色相正确）。mwv207 开源栈的
X 不写 ramp → 正常。历史"modetest 彩条仍灰"（实验 A）是被 X 遗留 ramp 污染
的误判（modetest 场景 gamma_lut=NULL，驱动不重写 LUT，污染持续存在）。
修复 4（LUT 双 palette RAM）虽非本症状根因，但仍是与开源栈的真实行为差异，
修复保留。

**修复**（`jmgpu_package.c`，**已被修复 6 的 `gamma_norm` 方案取代**）：
- 新增模块参数 `gamma_support`（默认 off）：跳过用户态 gamma ramp 写入硬件
  LUT，保持 crtc reset 时写入的双 RAM 线性表；副作用是亮度调节失效，
  由修复 6 的三态归一化方案替代。
- 保留 gamma_lut 采样日志（DRM_INFO，含 R/G/B 通道 5 点采样），可随时从
  dmesg 观察 X 专有驱动实际下发的 ramp 内容，供向厂商反馈——正是该日志
  在修复 6 中揭示了 1/3 缩放缺陷。

**验证步骤**（SSH）：
```
sudo reboot        # 或停 X 后 rmmod jmgpu && modprobe jmgpu
# 桌面对比度应恢复正常
sudo dmesg | grep -E "gamma_lut updated|identity LUT"   # 观察根因证据
```

**遗留观察**：modetest -D 直亮（`-s 41:1920x1080`）在 jmgpu 栈点不亮（卡屏），
mwv207 栈同样未成功（两次"无彩条"），原因待查（疑 mode 选择/时序，与色彩
问题无关，桌面显示不受影响）；两栈 modetest 自动选模式时序亦不同
（jmgpu htotal=2080/vtotal=1100 vs mwv207 2200/1125），后续如需复测寄存器
对比需改用显式 mode 参数或抓 modetest.log。

---

### 修复 6（2026-09-08）：最终修复 —— X 驱动 1/3 缩放缺陷 + `gamma_norm` 归一化 ✅（已实测）

**诊断日志立功**：修复 5 的 gamma_lut 采样日志（新模块生效后）直接揭示了
X 专有驱动 ramp 的精确形态：

| 用户请求 | X 驱动下发的 ramp（R=G=B，采样 [0,64,128,192,255]） | 实际含义 |
|---|---|---|
| 亮度 1.0（恒等） | `0,21,42,64,85` | = in × **1/3**（85=255/3） |
| 亮度 0.5 | `0,11,21,32,43` | = in × **0.5/3** |

→ **X 驱动 (`jmgpuDrmModeSetupColorMap`/gamma ioctl 路径) 对所有 ramp 统一
做了 1/3 线性缩放**：`out = in × brightness / 3`。原样写 LUT 的后果：
1. 恒等请求变暗化表 → 整屏"蒙灰滤镜"（黑发灰/白不白/色相与灰阶层次保留）；
2. 亮度/对比度调节值只剩应有的 1/3。

**最终修复**（`jmgpu_package.c`）：`gamma_support` 布尔参数改为三态
**`gamma_norm`**（int，0644，默认 **3**）：

| `gamma_norm` | 行为 | 用途 |
|---|---|---|
| **3（默认）** | 写 LUT 前 ramp **乘 3 归一化**（clamp 255） | 恒等请求恢复线性表（灰滤镜消失），亮度/gamma 滑条按真实意图生效 ✅ |
| 0 | 完全跳过用户态 gamma（LUT 恒为 reset 线性表） | 应急（亮度调节失效） |
| 1 | 原样写（厂商原始行为） | 复现缺陷/调试 |

验证：重启后系统亮度滑条平滑可用、画面无灰滤镜；WIN_CONTRAST 随归一化
自动恢复 0x800000F0（lutdata[384]=128 → 128×15/8=240）。

**过程教训（重要，供以后所有 dkms 修复参考）**：
1. **`dkms install` 后必须 `update-initramfs -u` 再重启**。`force_mode_test.sh
   boot` 时代建的 initramfs 冻结了旧版 `jmgpu.ko`，开机早期 modules-load
   直接加载冻结副本，真实根上的新模块永远轮不上——期间多次"修复无效"的
   反馈均因此误判（包括把 WIN_CONTRAST 红鲱鱼当根因、误推 X 直写 MMIO）。
2. **验证运行中模块身份用 srcversion**：
   `cat /sys/module/jmgpu/srcversion` vs `modinfo -F srcversion jmgpu`，
   不一致即加载的不是磁盘上的模块。
3. `sync_dkms.sh build` 现已自动执行 `update-initramfs -u`。

**使用方法**（`gamma_norm` 参数）：
```bash
# 查看当前值（默认 3）
cat /sys/module/jmgpu/parameters/gamma_norm
# 运行时切换（无需重启；0/1/3 见上表）
echo 0 | sudo tee /sys/module/jmgpu/parameters/gamma_norm
# 开机固定：/etc/modprobe.d/jmgpu-gamma.conf
#   options jmgpu gamma_norm=3
```
亮度调节：deepin 系统设置 → 显示 → 亮度滑条，正常可用（经 gamma_norm=3
归一化）。诊断：
```bash
sudo dmesg | grep "gamma_lut updated"    # X 驱动原始 ramp 采样
```

**附带工具**（本次排查沉淀，保留在仓库）：
- `dump_display_regs.sh` / `dump_full_regs.sh`：显示域寄存器 dump（两栈对比）
- `fix_win_contrast.sh`：WIN_CONTRAST 寄存器写回（诊断用）

---

### 复现与恢复
- 复现：jmgpu 栈下任意显示内容均灰（modetest / X / 桌面一致）
- 恢复正常：mwv207 栈（deepin 内核开源驱动）
- 回滚驱动：`git checkout` 源码后 `sync_dkms.sh` 重编译；
  回滚栈：`force_mode_test.sh boot-undo && reboot`

---

## 修复 3：VA-API 硬解实测 —— 功能 ✅ / 像素 ✅ / 性能受限 ⚠️

### 测试环境与工具
- jmgpu 栈开机持久化已生效（blacklist mwv207 + modules-load jmgpu）
- `/dev/dri/renderD128`（渲染节点，权限走 ACL `+` 即可访问）
- 环境变量 `LIBVA_DRIVER_NAME=jmgpu`（VA-API 驱动 = `jmgpu_drv_video.so`）
- 工具：ffmpeg 6.0.16 / mpv 0.40.0

### 功能与像素正确性（硬解 vs 软解输出校验和一致 = 像素级正确）
| 编码 | 测试片 | 软解 md5 | VA-API 硬解 md5 | 结果 |
|---|---|---|---|---|
| H.264 | 1920x1080 30fps 5s | `81edd071…38853e` | `81edd071…38853e` | ✅ 一致 |
| H.265/HEVC | 1920x1080 30fps 3s | `f781c5d8…07ce5` | `f781c5d8…07ce5` | ✅ 一致 |
| VP9 | 1280x720 30fps 3s | `8fd5723b…d39d` | `8fd5723b…d39d` | ✅ 一致 |

> 方法：`ffmpeg -hwaccel vaapi -vaapi_device /dev/dri/renderD128 -i xxx -f rawvideo -pix_fmt nv12 - | md5sum`
> 软解为同参数去掉 `-hwaccel` 的基准。md5 完全一致 ⇒ 硬解像素输出与软解无差。

### 性能（D2000 八核 NEON 软解本身很强）
| 场景 | 软解 | VA-API 硬解 | 说明 |
|---|---|---|---|
| 1080p30 x264，帧留 GPU（`-hwaccel_output_format vaapi`） | 28.4x | 12.4x | 硬解慢 |
| 4K30 x264，帧留 GPU | 8.16x | 3.82x | 硬解慢 |
| **CPU 占用（4K30 x264）** | user 1.617s / sys 0.151s | **user 0.143s / sys 0.192s** | **硬解 CPU 省 91%** |

> 结论：**功能正常、像素正确，但吞吐不及软解**（测试片为 x264 ultrafast 低复杂度，
> 且 VA-API→CPU 存在下载/搬运开销）。**硬解的价值在 CPU 卸载**（4K 下 user 时间
> 1.617→0.143s，约省 91%），适合 CPU 紧张或并发多路场景；追求单路最高帧率时软解
> 反而更快。真实高码率/高复杂度片源上硬解吞吐差距会缩小。

### mpv 播放器接入
- `mpv --hwdec=auto`（x11 会话下 VA 零拷贝后端不可用，自动回落 **`h264-vaapi-copy`**，
  日志确认 `Trying hardware decoding via h264-vaapi-copy`）
- 命令：`LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=auto /path/video.mp4`
- ffmpeg：`ffmpeg -hwaccel vaapi -vaapi_device /dev/dri/renderD128 -i in.mp4 -c:v ... out.mp4`

### 待补验证
- H.264 10bit / HEVC Main10（vainfo 报了 Main10 profile，未测真实 10bit 片源）
- 复杂/高码率真实片源的吞吐对比（当前仅为合成低复杂度片）
- `vaapi` 零拷贝后端（`--vo=vaapi`/`vaapi-drm`）——需在无 X 或匹配 VO 下验证

---

## 修复 7：VA 直通 dmabuf 导出链（mmap / map_dma_buf / 导出尺寸）—— 已编译部署，待重启验证 🔄

### 背景（purelive 仓库 `docs/LINUX_JM9100_HWDECODE_AUDIT.md` §10，P6）

mpv `hwdec=vaapi`（直通，VA surface 经 dmabuf 交给 GL）在应用同款环境
（`LIBGL_ALWAYS_SOFTWARE=1` + Mesa EGL + `LIBVA_DRIVER_NAME=jmgpu`）下：

```
Using hardware decoding (vaapi).
VO: [gpu] 1920x1080 vaapi[nv12]
dmabuf import failed to mmap: Invalid argument × 3 → 段错误 exit=139
```

`Using hardware decoding (vaapi)` 说明解码与 VA 互操作已建立；失败点是
**importer 对导出 dmabuf 的 mmap**。该消息位于 Mesa `libgallium`（llvmpipe 的
dmabuf import 需要线性 CPU 映射，`LIBGL_ALWAYS_SOFTWARE=1` 下 GL 端即 llvmpipe），
底层是内核 `dma_buf_mmap()` 返回 `-EINVAL`。内核侧无任何日志（失败路径无打印）。

### 根因（jmgpu dmabuf 导出链三处缺陷，均在 VIDMEM → reserved-mem 池路径）

| # | 位置 | 缺陷 |
|---|---|---|
| 1 | `jmgpu_setlayout.c` `j9_pathopsychosis`（reserved-mem `.Mmap`） | 池 mdl `cpuAccessible=FALSE`（exclusive 池注册如此，见 `jmgpu_scroll.c:2634`）时直接返回 `-13` → dmabuf mmap 一律 `-EINVAL`。但 VRAM 背后是 PCIe BAR 设备内存，物理上始终 CPU 可映射；该标志只表达"驱动自己不经 CPU 访问" |
| 2 | `jmgpu_bullets.c` `jmkVIDMEM_NODE_Export` | 导出 dmabuf 尺寸 `bytes & ~(PAGE_SIZE-1)` **向下**页对齐；VIDMEM 节点按 64 字节粒度分配（非页对齐），导致 dmabuf 尺寸小于 VA 驱动声明的 surface 尺寸 → importer mmap 触发 `dma_buf_mmap()` 的范围检查 `-EINVAL` |
| 3 | `jmgpu_setlayout.c:420` `j9mirror_choriomata`（reserved-mem `.GetSGT`） | 空桩，永远返回 `-13` → `j9_cibarious`（`.map_dma_buf`）失败后**返回 NULL sg_table**；dma-buf 框架/importer 约定失败必须返回 `ERR_PTR`，NULL 会被解引用（潜在内核 oops） |

### 修复

1. `j9_pathopsychosis`：删除 `!cpuAccessible` 拒绝分支，统一 `remap_pfn_range`
   （BAR 显存始终 CPU 可映射），非 CPU 可访问池打限流警告；
2. `jmkVIDMEM_NODE_Export`：导出尺寸改 `PAGE_ALIGN()`（向上对齐），尾部仍在
   VRAM 池内，映射安全；
3. `j9_cibarious`：SGT 缺失时返回 `ERR_PTR(-EINVAL)` 并限流告警（不再返回 NULL）；
4. `j9_forefence`：mmap 失败时限流输出内核诊断日志（status/dmabuf_size/pgoff/pages），
   便于后续定位。

> 说明：reserved-mem 的 `GetSGT` 空桩**未**实现（PCIe BAR 区域无 `struct page`，
> 正确实现需厂商按设备内存语义提供）——llvmpipe 纯 mmap import 不依赖它，故不阻断
> 本修复；真实 DMA 设备 importer 仍需厂商补齐。

### 部署与验证状态
- `./sync_dkms.sh build` 编译安装成功，`update-initramfs -u` 已重跑（首次 plymouth
  hook 段错误为偶发，重试通过）
- 2026-09-09 已重启加载，验证通过（见下）
- 重启后验证：
  1. `LIBGL_ALWAYS_SOFTWARE=1 __EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/50_mesa.json LIBVA_DRIVER_NAME=jmgpu mpv --vo=gpu --gpu-context=x11egl --hwdec=vaapi --frames=200 /tmp/hwtest_1080p.mp4` → 期望 exit=0、`hwdec-current=vaapi`、无 `dmabuf import failed to mmap`
  2. `dmesg | grep jmgpu` 观察残留限流告警（`map_dma_buf failed` 出现即 GetSGT 仍为阻断点）
  3. 应用内 `hwdec=auto` 复测（直通恢复后按 §7.2 复测整机 CPU）

### 运行态验证（2026-09-09 重启后）

- `dmesg` 命中修复 1 的限流日志 `dmabuf mmap on pool marked non-CPU-accessible`：
  VA surface 确实分配在 exclusive 池（cpuAccessible=FALSE），修复 1 精确命中根因；
  无 `dmabuf mmap failed`、无 `map_dma_buf failed` 日志。
- 行为变化（详见 purelive 仓库审计文档 §10.5/10.6）：Mesa(llvmpipe) EGL + `auto`
  时 direct 被选中，跨驱动（Jingjia VA 到 llvmpipe mmap 采样）整机 CPU 672%，
  性能灾难不可用；Jingjia EGL + `auto` 时 direct 仍被 mpv 拒绝（P6）回落 copy 66.7%。


### 加固（同日追加）

导出尺寸向上页对齐后，池尾节点的对齐尾部可能越过池末尾，补充两处防御：
1. `jmkVIDMEM_NODE_Export`：导出尺寸 clamp 到「池大小 - 节点偏移」（页对齐）；
2. `j9_forefence`：`skipPages + numPages` 超过池页数时拒绝并限流告警，避免
   `remap_pfn_range` 映射到无效 bus 地址（访问即总线错误）。

已重编部署（模块 12:10、initramfs 12:16），再次重启后生效。

### P6 收尾：mpv 组件补丁（本仓库留档 `mpv_dmabuf_oes_image.patch`）

Jingjia desktop GL 只声明 `GL_OES_EGL_image` 且忽略 GLES context 请求，mpv
desktop 分支要求的 `GL_EXT_EGL_image_storage` 缺失，direct 被拒（P6）。
OES_EGL_image 在 desktop context 上的 dmabuf import 经最小验证程序实测可用。
mpv 补丁（`video/out/hwdec/dmabuf_interop_gl.c`）：
1. 扩展检查接受 `GL_OES_EGL_image` / `GL_EXT_EGL_image_storage` 任一；
2. desktop 无 storage 入口时回退解析 `glEGLImageTargetTexture2DOES`。

已按 deepin 源码包（0.40.0-3+deb13u1deepin1）重编 deb 并安装。Jingjia EGL
下最终实测（600 帧 1080p30，单核当量）：direct + 轻量渲染参数（dither=no +
bilinear）约 21%（垫片原型 17.2%，波动内一致）；direct + 默认渲染参数约 56%；
copy + 默认渲染参数（补丁前最优）70.2%。

注意：应用（purelive）UI 仍被强制在 Mesa EGL，应用内 `hwdec=auto` 会选中
跨驱动 direct（672%），必须维持 vaapi-copy 设置（审计文档 §10.3/10.4，
应用侧映射待另行实现）；待 Jingjia GLES + Flutter Skia 黑屏解决、UI 切回
Jingjia 后，direct（约 21%）即可在应用内兑现。

### 直通终局结论（2026-09-09，诊断 shim 实测）

`vaExportSurfaceHandle(DRM_PRIME_2)` 实测（LD_PRELOAD 拦截 va_export_diag.c）：
- 格式探测 surface（128x128，有数据写入）：nz=48/48、96/96 —— 导出链路本身通；
- **正式解码帧（NV12 1920x1088, 3133440B）：每帧 nz=0 —— 导出内存全零**；
- desc 异常：NV12 的 UV plane offset[1]=0（应为 pitch*height 约等于 2088960）；
- 同一 surface vaGetImage（copy 路径）数据正确；
- Jingjia GL 与 Mesa llvmpipe 两个独立 importer 采样结果一致（全零深绿），
  且内核 jmgpu-diag（ioremap 直读 bus 地址）同为全零——排除 importer 侧。

结论：Jingjia 闭源 VA 驱动的 PRIME_2 导出实现不返回解码数据（疑似解码输出
经 GPU MMU 写入与 VIDMEM node 分离的页面，或导出路径未实现数据别名），UV
offset 描述符亦损坏。此为厂商级缺陷，内核（jmgpu DRM 驱动）侧无法修复。

处置：
- 直通暂不可行，应用维持 vaapi-copy（JMDEC 解码收益保留在 copy 模式）；
- va_export_diag.c（LD_PRELOAD 诊断）与内核 jmgpu-diag 插桩保留，供厂商
  复现与定位，向景嘉微反馈时附本节数据即可复现；
- 修复 1-4（mmap 放行/尺寸对齐/NULL-SGT 防护/越界防御）保留——把直通从
  「进程崩溃」降级为「可安全探测」，也是未来厂商修复后的必要基础。
