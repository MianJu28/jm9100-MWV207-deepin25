# JM9100 修复记录

> 本文档记录对闭源 jmgpu 1.7.0 内核驱动（移植到 6.6.143）的修复过程与排查记录。
> 配套：README.md（整体探索记录）、`force_mode_test.sh`（强制点屏/持久化）、
> `color_bisect.sh`（色彩二分实验）、`dump_display_regs.sh`/`dump_full_regs.sh`
> （寄存器 dump 对比）、`fix_win_contrast.sh`（LUT 相关键写回，诊断用）。
>
> **2026-09-10 状态**：
> - 问题 2（灰蒙蒙）已解决——X 专有驱动 gamma 下发的 1/3 缩放缺陷，
>   内核 `gamma_norm=3` 归一化修复（见修复 5/6）。
> - **VA-API 直通（mpv `--hwdec=vaapi`）已打通**——根因是闭源 VA 驱动把解码
>   surface 放进 CPU 不可见显存池，叠加 mpv 走了 JM9100 未实现的
>   `glEGLImageTargetTexStorageEXT` 导入入口；修复为 mpv 侧补丁 + 内核
>   dmabuf 链修正（见修复 7/8）。**使用方法见下方「VA-API 直通使用方法」**。
> - 改驱动后的部署必须 `./sync_dkms.sh build`（含 update-initramfs，
>   否则 initramfs 冻结旧模块）。

---

## VA-API 直通使用方法（2026-09-10 实测可用 ✅）

### 前置（已完成，重装系统后需重做）

1. 内核模块：本仓库源码 `./sync_dkms.sh build`（安装 jmgpu.ko + 重建 initramfs）。
   `prefer_visible_pool` / `no_exclusive_pool` 保持默认 0 即可，**无需**特殊参数。
2. mpv：应用本仓库 `mpv_dmabuf_oes_image.patch` 后重编安装（见「修复 8」）。

### 播放（直通，VA surface 经 dmabuf 零拷贝交给 GL）

```bash
LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=vaapi 视频.mp4
```

- 若走 Mesa 软栈：`LIBGL_ALWAYS_SOFTWARE=1 LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=vaapi 视频.mp4`
- 应用内（purelive 等）配置 `hwdec=vaapi` 即可，无需再强制 `vaapi-copy`。

### 其它工具

```bash
# ffmpeg 硬解（VA-API 设备）
LIBVA_DRIVER_NAME=jmgpu ffmpeg -hwaccel vaapi -vaapi_device /dev/dri/renderD128 \
    -i in.mp4 -c:v libx264 out.mp4

# 硬解能力检查
LIBVA_DRIVER_NAME=jmgpu vainfo
```

### 自检与验证

```bash
cd ~/Desktop/Git/jm9100
./test_passthrough.sh              # 纯色片源自动判定直通是否正常（推荐）
./test_passthrough.sh -s 720p      # 换分辨率
./test_passthrough.sh -x           # 附加导出诊断（缓冲内容 / vaGetImage 对比）
./test_passthrough.sh -n           # 只做环境体检（模块版本、显存池占用）
```

判定：`直通(vaapi)` 的 `avg` 应等于片源原色（脚本用的纯红片 → `(255,0,0)`）；
若为 `(0,77,0)` 之类的深绿即仍是全零导出。

### 可选内核参数（一般不需要）

| 参数 | 作用 |
|---|---|
| `prefer_visible_pool=0` | 默认，厂商原行为（**当前使用**） |
| `prefer_visible_pool=1` | 解码 surface 优先申请可见池（可见池空闲充足时） |
| `prefer_visible_pool=2` | 交换两池角色，可见窗口整块留给解码（可见池碎片化严重时用；会让桌面部分缓冲进不可见池） |
| `no_exclusive_pool=1` | 关闭不可见池（可用显存降到 255MB，仅在极端场景用） |

运行时切换：`echo N | sudo tee /sys/module/jmgpu/parameters/prefer_visible_pool`

---

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

### 性能复测（2026-09-09，修复 6/7 部署后）

运行态模块：`srcversion F39A3DBCC1D5A13C802F3BA`（与磁盘模块一致，新代码已生效），
`gamma_norm=3`，`renderD128` 可用，8 核。片源：合成片 x264 ultrafast
（1080p30 20s/600 帧、4K30 5s/150 帧）。每项跑 3 轮取典型值（波动 <5%）。

| 场景 | speed | user(s) | sys(s) | CPU 合计 |
|---|---|---|---|---|
| 1080p30 软解 | 28.4–29.6x | 3.96 | 0.12 | **4.08** |
| 1080p30 硬解，帧留 GPU | 12.6x | 0.15 | 0.43 | **0.58（省 86%）** |
| 1080p30 硬解，帧下载 CPU | 6.1x | 0.59 | 3.86 | 4.45 |
| 4K30 软解 | 9.8–10.6x | 2.57 | 0.18 | **2.75** |
| 4K30 硬解，帧留 GPU | 3.65x | 0.13 | 0.25 | **0.38（省 86%）** |
| 4K30 硬解，帧下载 CPU | 1.5x | 0.51 | 3.73 | 4.24 |

- 与首次测试一致：**吞吐软解胜、CPU 占用硬解胜**（两档分辨率下 CPU 均省 ~86%，
  1080p 4.08→0.58s，4K 2.75→0.38s）。硬解 CPU 开销几乎不随分辨率增长（软解 4K
  user 是 1080p 的 0.65 倍但绝对值仍在 2.5s 量级，硬解恒 0.13s）。
- **下载路径是性能杀手**：`-hwaccel_output_format vaapi`（帧留 GPU）比默认下载快
  2 倍（1080p 12.6x vs 6.1x），且 sys 时间从 3.9s 降到 0.43s —— 开销几乎全在
  VA→CPU 回读（vaGetImage/内核拷贝），而非解码本身。
- 像素正确性复验：1080p 全片软解/硬解 nv12 md5 一致（`5812f952…`）。

**mpv 实时播放复测**（Jingjia GL `GL_RENDERER='Jingjia JM9100'`，x11egl，
600 帧 1080p30，wall≈20.4s，跑 3 轮稳定）：

| hwdec | user(s) | sys(s) | CPU 合计 | 单核当量 |
|---|---|---|---|---|
| `vaapi-copy`（硬解+回读） | 3.8 | 12.9 | 16.7 | **82%** |
| `no`（纯软解） | 6.7 | 7.4 | 14.1 | **69%** |

- 与修复 7 记录的 copy 70.2% 相比本次为 82%，差异主要在 **sys 时间**（12.9s）：
  复测时系统有后台负载（load 1.7–2.2），且回读的 sys 开销对系统状态敏感；
  绝对值仅供参考，需同环境 A/B 才有意义。
- 结论不变：copy 模式下 **user 时间硬解更低（3.8 vs 6.7s），但 sys 回读开销
  吞掉收益（+5.5s）**，总 CPU 反而略高于纯软解。播放场景若不能走 direct
  （直通导出全零，见修复 7 终局结论），硬解在播放端并无 CPU 优势，收益只在
  转码/多路并发（帧留 GPU）场景。

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

## 修复 7：VA 直通 dmabuf 导出链（mmap / map_dma_buf / 导出尺寸）—— 已部署验证 ✅（直通数据缺失见终局结论）

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
- 2026-09-09 已重启加载，验证通过（见下）；此后多次重编部署（诊断插桩/加固）
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

---

## 修复 8（2026-09-10）：直通根因与最终修复 ✅（已实测）

> 结论先行（最终版）：
> 1. FIXLOG 修复 7 的「厂商级缺陷、内核侧无法修复」结论**不成立**——导出链路
>    本身正确（可见池缓冲导出字节精确）；
> 2. 直通全绿有**两个叠加原因**：
>    - 解码 surface 落在 **CPU 不可见显存池**（VA 驱动把整池作为一块连续显存申请，
>      可见窗口被桌面打碎后申请失败而回退）；
>    - **mpv 的导入入口选错**：desktop GL 下走
>      `glEGLImageTargetTexStorageEXT`，而 JM9100 该入口存在但不真正挂接 dmabuf，
>      纹理恒为全零。
> 3. **最终修复 = mpv 侧改用 `EGLImageTargetTexture2DOES`**（`mpv_dmabuf_oes_image.patch`）。
>    该路径下 Jingjia EGL/GL 经 GEM 句柄在 GPU 侧导入，**与缓冲落在哪个池无关**，
>    因此内核侧保持厂商默认 `prefer_visible_pool=0` 即可（实测已通过）。
> 4. 内核侧修复 1-4（mmap 放行/尺寸对齐/NULL-SGT 防护/越界防御）与同驱动
>    dmabuf 导入快捷路径 `jmgpu_dmabuf_peek_node()` 保留——是 GPU 侧导入能成功的基础。

### 排查方法（不依赖文档，重新实测）

新增两个探针（均绕开闭源驱动，直接打到内核/VA 边界）：
- `jm_gem_probe.c`：jmgpu 私有 GEM ioctl 分配显存 → `GEM_LOCK` 取 CPU 地址 →
  `PRIME_HANDLE_TO_FD` 导出 → `mmap` 回读，双向交叉验证两个映射是否同一块物理内存；
- `va_export_probe.c`：`vaPutImage` 写入已知图案 → `vaGetImage` 回读校验 →
  `vaExportSurfaceHandle(DRM_PRIME_2)` 导出 → `mmap` 逐字节比对图案。

同时在 `jmkVIDMEM_NODE_Export` / `j9_forefence` / `j9_pathopsychosis` 增加
`jmgpu-exp` / `jmgpu-mmap` / `jmgpu-diag` 内核日志，打印导出节点所在的
**池编号、池内偏移、池页数、cpuAccessible** 与最终 `remap_pfn_range` 的 pfn。

### 关键实测结果

| 观察 | 数据 |
|---|---|
| 描述符其实是**正确**的 | `objects=1 layers=2`：layer0=`R8`(Y, off=0)、layer1=`GR88`(UV, off=2088960)，pitch 1920。此前「UV offset=0」是诊断脚本读 `layers[0].offset[1]` 的误读（每层只有 1 个 plane） |
| `vaPutImage` 写入的 1920x1088 surface 导出**完全正确** | `pattern match=8160 mismatch=0`，`vaGetImage` 回读 `ok=6120 bad=0` |
| 同一尺寸**解码帧**导出**全零** | `nz=0/6121`（mpv `--hwdec=vaapi`，16 帧全部 nz=0） |
| 差异在**显存池** | 成功者：`pool=4 off=0x76cc000 ... cpuAcc=1 nPages=65280`（可见池 255MB）<br>失败者：`pool=12 off=0xdc35000 ... cpuAcc=0 nPages=454656`（不可见池 1776MB） |
| GEM 探针复现同一现象 | 3MB `CONTIGUOUS` 分配也落到 `pool=12`：cpu→dmabuf `ok=3 bad=765`，dmabuf→cpu `ok=0 bad=768`，`dma[0]=00` 且写入被丢弃 |

### 根因

```
[jmgpu] VRAM size: 2048MB, visible size: 255MB, invisible size: 1776MB
[jmgpu]: external  pool CPU physical=0x1000000000 GPU physical=0x0        size=0xff00000
[jmgpu]: exclusive pool CPU physical=0x100000000  GPU physical=0x10000000 size=0x6f000000
```

- **external（可见）池** = PCIe BAR2（`/proc/iomem` `1000000000-100fffffff : 0000:07:00.0`），
  CPU 可映射。
- **exclusive（不可见）池** 的「CPU physical」是 `0x100000000`，但 `/proc/iomem` 里
  `100000000-16effffff : jmgpu_vram` 这条只是驱动自己 `request_mem_region` 的占位：
  系统 RAM 只有 `84030000-fbffffff` 与 `2000000000-237fffffff` 两段，PCI 桥窗口也只到
  `58000000-7fffffff` 和 `1000000000-1fffffffff`。**0x100000000 没有任何宿主桥解码。**

`j9_pathopsychosis()` 对导出做 `pfn = (res->start >> PAGE_SHIFT) + skipPages`，
对不可见池就是把这个无解码的总线地址装进 PTE：读恒为 `0x00`、写被静默丢弃，
且 `mmap()` 本身**成功返回**——于是 importer 拿到一块「看起来正常、内容全零」的内存，
直通画面全绿，而 `vaGetImage`（走 GPU 拷贝）不受影响，与历史现象完全吻合。

解码器（JMDEC）的 render target 由闭源 VA 驱动指定分配在 exclusive 池；
`vaPutImage`/桌面 pixmap 走 external 池，所以同为 1920x1088 也会一成一败。

### 修复尝试 A（`jmgpu_insert.c`）：关闭不可见池 —— 验证了根因，但不可用

新增模块参数 **`no_exclusive_pool`**（int，0644，默认 0）：置 1 时走驱动原本就有的
「exclusive pool disabled」分支（`exclusiveBase/Size = 0`），把全部显存分配压到
CPU 可见的 BAR 窗口内。

实测结果（`options jmgpu no_exclusive_pool=1`）：
- ✅ 探针全绿：`jm_gem_probe 3145728 1` → `A[ok=768 bad=0] B[ok=768 bad=0]`；
  `va_export_probe` → `pattern match=8160 mismatch=0`。
- ✅ `invisible size: 0MB`，`jmgpu-exp/mmap` 全部落在 `pool=4 cpuAcc=1`。
- ❌ **不可用**：BAR2 只有 256MB，本机桌面（Xorg 85MB + buddycn 122MB + …）已占
  约 220MB；mpv 再分配 1080p surface 即 `jmgpu_hbo_create failed … ret:-3`
  与 GL `OUT_OF_MEMORY`，整机显存耗尽导致 IDE 显示异常。

**结论**：不可见池不能砍——它承担了 1776MB 的 GPU 侧容量；而可见池（255MB）
是硬上限，装不下"桌面 + 解码"。

### 修复尝试 B（最终采用）：同驱动 dmabuf 导入快捷路径

既然可见池容量无法满足，就让**解码 surface 继续留在不可见池**（保住 2048MB），
但让 **GPU 侧 importer 不必碰 CPU 地址**。

- `jmgpu_bullets.c` 新增 `jmgpu_dmabuf_peek_node(struct dma_buf *)`：
  若 `dmabuf->ops == &_dmabuf_ops`（即本驱动导出），返回 `dmabuf->priv`
  （导出时 `exp_info.priv = NodeObject`，就是原始 VIDMEM 节点）。
- `jmgpu_garbage.c` `j9_handle_j9_dumbbeller()`（本驱动的 `gem_prime_import`）
  增加快捷分支：命中时 `jmkVIDMEM_NODE_Reference()` + `j9_handle_j9ma_smellproof()`
  直接把**同一个 VIDMEM 节点**包装成 GEM 对象返回，完全绕开
  `map_dma_buf → GetSGT`（reserved-mem 该回调是空桩）与 CPU mmap。

适用场景：VA-API 直通里 importer 与 exporter 是同一个驱动（景嘉微 GL/EGL
导入 VA 刚导出的 surface），因此节点地址天然正确，**与缓冲区在哪个池无关**，
不可见池也能零拷贝直通。

局限：纯 CPU importer（Mesa/llvmpipe 的 `mmap` 路径）仍读不到不可见池内容，
需显式 `no_exclusive_pool=1`（代价见上）或厂商补齐 `GetSGT`。

### 关键补充：importer 走的是 mmap，且可见池有 25% 阈值

后续实测推翻了「同驱动导入即可直通」的乐观假设：

1. **Jingjia EGL/GL 的 dmabuf 导入会 mmap**。播放期间内核 `jmgpu-mmap` 日志
   显示 importer 对导出缓冲反复调用 `.mmap`（`j9_forefence`），因此即使
   `PRIME_FD_TO_HANDLE` 已 `rc=0`，只要缓冲区在不可见池，importer 拿到的仍是全零。
2. **`GetSGT`/`map_dma_buf` 路径实际未被使用**（dmesg 无 `map_dma_buf failed` 告警），
   所以「补齐 GetSGT」并非当前瓶颈。
3. **池选择有 25% 空闲阈值**（`jmgpu_detect.c:1447-1474`）：

```c
} else if (pool == J9_HANDLE_J9_PROSNEUSIS) {
        status = jmkKERNEL_GetVideoMemoryPool(Kernel, J9_HANDLE_J9M_ANTHRAMINE, &videoMemory);
        if (失败) pool = J9_HANDLE_J9_UNCONTRITE;
        else {
                status = jmkKERNEL_GetVideoMemoryPool(Kernel, J9_HANDLE_J9_UNCONTRITE, &videoMemory);
                if (J9_MONOPHYLETY(status) && (videoMemory->freeBytes < videoMemory->bytes / 4)
                    && Type != ...) pool = J9_HANDLE_J9M_ANTHRAMINE;   /* 改用不可见池 */
                else            pool = J9_HANDLE_J9_UNCONTRITE;
        }
}
```

即 **可见池空闲不足 1/4 时，新分配改投不可见池（ANTHRAMINE，pool=12）**。
实测吻合：本机桌面占用可见池约 206MB/255MB（buddycn 107MB + Xorg 58MB +
mihomo-party 33.5MB + …），空闲仅 ~49MB < 63.75MB → 解码 surface 全部落
`pool=12` → 直通全绿；而**刚开机桌面尚未吃满时**（空闲 > 25%），
`va_export_probe` 的 surface 落在 `pool=4` 且导出字节精确。

进一步实测（`va_export_diag.c` 同时比对导出内容与 `vaGetImage`）：

```
[vad]#7 NV12 1920x1088 sz=3133440 mmap_nz=0
[vad]   vaGetImage(1920x1088) nz=6120/6121 head=49 4a 4a 4a
```

**surface 里有正确解码数据，只是导出映射读不到** —— 与 360p 片源同样复现
（360p 仅需约 7MB，仍全绿，因为阈值判定与分辨率无关，只看池空闲比例），
确认瓶颈是「可见池空闲比例」而不是「本次请求大小」。

### 结论与可行路径

- 直通要求解码 surface 落在 **CPU 可见的 255MB 池**，而该池空闲比例被
  桌面的显存占用压到 25% 阈值以下 → 厂商策略把解码缓冲改投不可见池。
- 因此**可行修复 = 释放可见池空间**（把桌面占用压到 ~190MB 以下），
  使解码 surface 重新落到可见池；或内核侧放宽/关闭该 25% 阈值
  （`jmgpu_detect.c` 上述分支加参数，让「装得下就用可见池」）。
- 若两者都不做，直通在本机不可行；copy 模式（`vaapi-copy`）不受影响。

### 内核侧加固与重定向实验（`prefer_visible_pool`）

新增模块参数 **`prefer_visible_pool`**（int，0644，默认 0，定义在
`jmgpu_insert.c`，`jmgpu_detect.c` 使用）：

1. `jmkKERNEL_AllocateVideoMemory()` 入口：`*Pool == ANTHRAMINE(12, 不可见池)`
   时改请求 `UNCONTRITE(4, 可见池)`；
2. PROSNEUSIS 分支的「可见池空闲 < 1/4 就改投不可见池」判定加 `!prefer_visible_pool`。

两者都保留了池回退链（可见池装不下 → 仍回退 ANTHRAMINE），**不会造成 OOM**。

**实测结果（本机，`prefer_visible_pool=1`）**：解码 surface 仍为
`jmgpu-exp: pool=12 … cpuAcc=0`，直通画面仍 `avg=(0,77,0)`（全零深绿）。
说明**可见池当时确实无法满足该请求**（VA surface 的连续/对齐要求 + 桌面占用），
重定向只是把失败提前，最终仍回退不可见池。

对照：同一时刻 `jm_gem_probe 3145728 1` 却能落在 `pool=4` 且导出字节精确
——VA surface 的分配条件（type/flag/alignment）比普通 GEM 更苛刻。

### 可见池能否调大？—— 不能（硬件 BAR 上限）

```
ppcie_info->mem0bar.no   = 2;                          /* PCI BAR2 */
ppcie_info->mem0bar.size = pci_resource_len(pdev, 2);  /* 256MB，硬件固定 */
pargs->slide_window_base = MIN(mem0bar.base + vram_usable_size,
                               mem0bar.base + mem0bar.size) - HADEPHOBIA(1MB);
pargs->externalSize[0]   = slide_window_base - mem0bar.base;   /* = 255MB */
```

- `vram_space_limit` 只参与**不可见池**尺寸计算，调它不会把空间转给可见池；
- 设备**不支持 Resizable BAR**（`lspci -vvv` capability 里没有该能力），BAR2 固定 256MB；
- 其它 BAR 也不行：`bar_probe.c` 实测把特征串写进显存后，**BAR0(128MB) 搜不到**
  （不是显存窗口），**BAR1(32MB) 顺序读取触发总线错误**（稀疏 MMIO）；
- 滑窗 `HADEPHOBIA` 只有 1MB，且是驱动切页访问用的。

结论：**没有第二条 CPU 可见通道**，255MB 是硬上限，只能靠减少占用。

### 根因收敛：解码 surface 池是"一整块连续显存"

导出日志里 4 个解码 surface 的池内偏移严格等间隔：

```
pool=12 off=0x5dd6000 bytes=0x2fd000
pool=12 off=0x5ad9000 bytes=0x2fd000   (差 = 0x2fd000)
pool=12 off=0x57dc000 bytes=0x2fd000
pool=12 off=0x54df000 bytes=0x2fd000
```

即 VA 驱动把**整个解码 surface 池作为一块连续显存申请**，再切成单个 surface。
因此只要可见窗口里没有足够大的连续空闲块，**整组**都会回退到不可见池。

实测可见池的碎片化程度（`jm_gem_probe` + `gpu_addr` 判池）：

| 请求大小 | 落池 |
|---|---|
| 1/2/4/6/8 MB | 可见（最大块 8~11MB） |
| 12/16 MB | 不可见 |

而 4 个 1080p surface 就需 12.5MB 连续，典型 1080p 流（~20 帧）需 ~63MB 连续
—— 可见池总空闲虽有 ~65MB，但**最大连续块只有 8~11MB**，必然失败。

**结论**：直通成立的前提是可见窗口里存在足够大的连续空闲区，实质要求
"解码时可见池基本是空的"。桌面应用（本机 buddycn ~145MB + Xorg ~47MB +
dde-shell ~17MB）把可见池打得七零八落，因此默认状态下不可行。

### 对策实验：`prefer_visible_pool=2`（交换两池角色）

在 `jmgpu_detect.c` 增加模式 2：把"通用/内部池"路径一律压到不可见池
（`pool = J9_HANDLE_J9M_ANTHRAMINE`），把显式请求不可见池的（VA 解码）请求
改到可见池，从而让可见窗口尽量保持整块空闲给解码 surface 池。

- 默认仍是模式 1（安全）；模式 0 = 厂商原行为；
- 模式 2 属风险实验：桌面的部分缓冲也会进 CPU 不可见池，可能出现显示异常；
- 运行时可即时回退：`echo 1 > /sys/module/jmgpu/parameters/prefer_visible_pool`。

### 分水岭：内核侧已通，故障转移到 importer（GL/EGL）

开启 `prefer_visible_pool=2` 后（buddycn 130MB 转到不可见池，可见池占用
190MB→65MB），`./test_passthrough.sh -x` 的实测：

```
[vad]#7 NV12 1920x1088 sz=3133440 mmap_nz=6120        ← 导出缓冲内容正确
[vad]   vaGetImage(1920x1088) nz=6120/6121 head=51 51 51 51
...
直通(vaapi): 1920x1080 avg=(0,77,0) 绿色占比 100.0%     ← 画面仍是全零
```

**缓冲里已有正确数据，但 GL 采样到全零** → 内核导出链路（修复 1-4 + 本次
参数）已经没问题了，最后一环在 importer：

mpv 0.40 的 `vaapi_gl_mapper_init()` 是**二选一**（`video/out/hwdec/dmabuf_interop_gl.c`）：

```c
    if (ra_gl_get(mapper->ra)->es) {      /* GLES */
        p->EGLImageTargetTexture2DOES = eglGetProcAddress("glEGLImageTargetTexture2DOES");
    } else {                              /* desktop GL ← 我们走这里 */
        p->EGLImageTargetTexStorageEXT = eglGetProcAddress("glEGLImageTargetTexStorageEXT");
    }
```

`--gpu-context=x11egl` 下 Jingjia 给的是 **desktop GL**，mpv 于是调用
`glEGLImageTargetTexStorageEXT`（日志确认：`Using EGL dmabuf interop via
GL_EXT_EGL_image_storage`）。JM9100 该入口**存在但不真正挂接 dmabuf**，
纹理保持全零 → 采样全零 → 深绿；而 `glEGLImageTargetTexture2DOES`
（GL_OES_EGL_image）是 FIXLOG P6 里最小验证程序实测可用的那个入口。

**修复**：`mpv_dmabuf_oes_image.patch` 已更新——desktop 分支解析出 OES 入口后
**优先使用并置空 storage 指针**（这样 init/map/unmap 三处的生命周期判断自然
走 OES 路径）。重编 mpv 即可。

### 最终修复与验证（2026-09-10 实测通过 ✅）

**改动清单**

| 位置 | 改动 |
|---|---|
| `video/out/hwdec/dmabuf_interop_gl.c`（mpv，见 `mpv_dmabuf_oes_image.patch`） | desktop GL 分支解析出 `glEGLImageTargetTexture2DOES` 后**优先使用并置空 storage 指针**；扩展检查放宽为 OES/storage 任一 |
| `jmgpu_bullets.c` | `jmgpu_dmabuf_peek_node()`：同驱动 dmabuf 导入快捷路径（`j9_handle_j9_dumbbeller` 直接复用原 VIDMEM 节点，绕开 reserved-mem 缺失的 `GetSGT`） |
| `jmgpu_bullets.c` / `jmgpu_setlayout.c` | 修复 1-4（mmap 放行、导出尺寸页对齐、NULL-SGT 防护、越界防御）+ 诊断日志（`jmgpu-exp`/`jmgpu-mmap`/`jmgpu-diag`） |
| `jmgpu_insert.c` | 参数 `no_exclusive_pool`、`prefer_visible_pool`（默认 0，均非必需） |
| `jmgpu_detect.c` | `prefer_visible_pool` 的两级重定向钩子 |

**验证结果**（`./test_passthrough.sh -s 1080p`，`prefer_visible_pool=0`）：

```
直通(vaapi): 1920x1080 avg=(255,0,64) 绿色占比 0.0%
软解(no)   : 1920x1080 avg=(255,0,64) 绿色占比 0.0%
==> 直通【正常】：画面是片源原色(红)
```

另：同一状态下 `prefer_visible_pool=1/2` 也正常，但**不再需要**；
`prefer_visible_pool=2` 会把桌面缓冲推到不可见池，仅建议在可见池碎片化
导致导出异常时才临时启用。

**部署状态（本机）**

- jmgpu 模块 `srcversion 217561F3771EF4276FFB6A0`，已 dkms 安装且写入 initramfs；
- `/etc/modprobe.d/` 下**不再有**池策略配置（恢复厂商默认）；
- mpv 已按补丁重编安装（`mpv v0.40.0`）。

**厂商侧建议（可反馈）**

1. `glEGLImageTargetTexStorageEXT` 入口未真正挂接 dmabuf（建议实现或不要声明
   `GL_EXT_EGL_image_storage`）；
2. reserved-mem（VRAM）分配器的 `GetSGT` 为空桩，导致标准 `map_dma_buf` 导入
   失败（本次已用同驱动快捷路径绕过）；
3. 解码 surface 池整体按“一块连续显存”申请，在可见窗口碎片化时必然整组回退
   到 CPU 不可见池，建议改为按需分块或非连续分配。

**回归测试工具（仓库内）**

`test_passthrough.sh`（一键判定）、`va_export_probe.c` / `va_export_diag.c`
（VA 导出与 importer 诊断）、`jm_gem_probe.c`（内核 GEM 导出双向校验）、
`bar_probe.c`（BAR 是否为显存窗口）、`ppm_stats.py` / `passthrough_verify.py`。
