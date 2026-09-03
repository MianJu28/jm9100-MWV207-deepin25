# JM9100 修复记录

> 本文档记录对闭源 jmgpu 1.7.0 内核驱动（移植到 6.6.143）的修复过程与排查记录。
> 配套：README.md（整体探索记录）、`force_mode_test.sh`（强制点屏/持久化）、
> `color_bisect.sh`（色彩二分实验）。

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

## 问题 2：显示灰蒙蒙（低对比度）—— 未解决 ⚠️（排查记录）

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

### 复现与恢复
- 复现：jmgpu 栈下任意显示内容均灰（modetest / X / 桌面一致）
- 恢复正常：mwv207 栈（deepin 内核开源驱动）
- 回滚驱动：`git checkout` 源码后 `sync_dkms.sh` 重编译；
  回滚栈：`force_mode_test.sh boot-undo && reboot`
