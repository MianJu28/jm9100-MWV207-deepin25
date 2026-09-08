# JM9100 (MWV207) GPU 驱动移植与视频硬解探索记录

> 本仓库记录了在 **Phytium（飞腾）+ 景嘉微 JM9100 (PCI 0731:9100)** 平台上，
> 将 GPU 驱动移植到内核 **6.6.143-arm64-desktop-hwe (Deepin 25)** 并尝试打通
> **视频硬解 (H.264)** 的完整过程、代码修改与验证结论。
>
> **最终结果（2026-09）：显示点亮 + VA-API 硬解在闭源 jmgpu 栈上同时达成 ✅**
> 此前判定的"显示输出无信号（固有问题）"实为一次内核 API 迁移遗漏，
> 根因与修复见 §3 路线 A「显示无信号根因与修复」，结论更新见 §4/§6。
>
> **遗留问题（已解决 ✅ 2026-09-08）**：显示画面整体"蒙灰滤镜"已修复。
> 根因：X 专有驱动 (mwv207_drv.so) 的 gamma 下发存在**固定 1/3 线性缩放缺陷**
> （恒等请求也下发 in/3 的 ramp），原样写入 jmgpu 硬件 LUT 后造成整屏低对比度。
> 修复：内核驱动新增 `gamma_norm` 参数（默认 3 = 写 LUT 前乘 3 归一化）——
> 显示恢复正常且**系统亮度调节同步恢复可用**。诊断过程（含 initramfs 冻结
> 旧模块的教训）与使用方法见 **FIXLOG.md「问题 2」修复 5/6**。

---

## 1. 硬件与系统环境

| 项 | 值 |
|---|---|
| CPU | 飞腾 D2000 (Phytium, aarch64) |
| GPU | 景嘉微 JM9100 (PCI vendor:device = 0731:9100, 子系统 0731:9101) |
| 内核 | 6.6.143-arm64-desktop-hwe (Deepin 25 定制) |
| 系统 | Deepin 25, Xorg 1.21, lightdm |
| 会话 | x11 |
| 显示连接 | HDMI-A-1 (物理显示器, 1080p) |

### 关键系统事实
- 内核 `/dev/dri/card0` 由 **deepin 自带 mwv207.ko**（开源系）驱动，显示正常
- 系统装景嘉微**闭源用户态**：`com.jingjiamicro.mwv207` / `com.jingjiamicro.mwv207.vaapi`
  （含 `jmgpu_dri.so` GL、`jmgpu_drv_video.so` VA-API、`libdrm_jmgpu.so`、专有 Xorg `mwv207_drv.so`）
- 一个 PCI 设备 `0000:07:00.0` **只能绑定一个内核驱动**

---

## 2. 四套候选驱动/用户态 全景

景嘉微存在**两套割裂的驱动栈**，另有社区/官方开源内核：

| 内核驱动 | 来源 | 建 /dev/jmgpu | 显示 | GL | 视频硬解用户态 |
|---|---|---|---|---|---|
| **闭源 jmgpu.ko** | 景美闭源 1.7.0 | ✅ | ✅ (灰滤镜已修, 见§3/§4/FIXLOG 问题2 修复6) | ✅ | ✅ (H264/HEVC/VP9 VLD 实测) |
| **deepin mwv207.ko** | 开源系 (shanjinkui) | ❌ | ✅ | 软渲染(llvmpipe) | ❌ |
| **Icenowy mwv207-dkms** | 社区开源 | ❌ | 设计支持 | (mesa) | ❌ 无用户态 |
| **景美官方 6.6 mwv207** | openkylin 开源 | ❌ | 设计支持 | (mesa) | ❌ 无用户态 |

---

## 3. 尝试过的修改与实现方案

### 路线 A：闭源 jmgpu 内核移植到 6.6（最深入）

**目标**：让景美闭源 jmgpu.ko（原仅支持老内核）在 6.6.143 上编译并接管 GPU。

**做法**：对厂商 1.7.0 的 dkms 源码 `/usr/src/mwv207-1.7.0.uos` 做内核 API 移植
（改动约 22 个 `.c` 文件，见 git 基线 `13de34c`）。

**API 迁移点**（全部编译期验证）：
| 内核 API 变化 | 处理 |
|---|---|
| 用户态 `stdarg.h`/`stddef.h` | 改 `linux/stdarg.h`/`linux/stddef.h` |
| `dma_buf_map`→`iosys_map` (6.3+) | `jmgpu_bullets.c` 迁移 |
| `MAX` 宏冲突 | `#ifndef` 守卫 |
| `class_create()` 去 owner (6.4+) | 版本分支 |
| `vm_flags` 只读化 (6.1+) | `vm_flags_set()` |
| 枚举交叉赋值 `-Werror=enum-conversion` | 显式 cast |
| `mode_config.allow_fb_modifiers` (deepin 提前移除) | 条件移除 |
| `alloc_apertures`→`drm_aperture_remove_conflicting_pci_framebuffers` (6.0+) | 改名 |
| `PDE_DATA`→`pde_data()` | 改名 |
| `get_user_pages` 去 vmas 参数 (6.1+) | 版本适配 |
| 整个 fbdev 控制台层 (6.4+ 移除) | `jmgpu_clause.c` 降级 no-op |
| `drm_dp_helper.h`/`scdc_helper.h` 等→`drm/display/` (6.6) | include 路径版本化 |
| `DRM_COLOR_FORMAT_YCRCB*` 拼写 | 改 YCBCR |
| 厂商私有 SCDC 函数与内核同名冲突 | 改名 `jmgpu_scdc_*` |
| **`__pte_offset_map_lock` 未导出** (核心障碍) | 改用导出 `follow_pfn` 重写 3 处页表遍历 |

**移植结果**：全部 ~75 对象编译通过，DKMS build/install 成功，模块 `jmgpu.ko`
（vermagic 匹配，含 PCI 0x9100）。

**真机验证结论**（多次 SSH 可控测试）：
- ✅ probe 成功（`probe for 0x0731:9100`）
- ✅ 建 `/dev/jmgpu` + `/dev/dri/card0` + `renderD128`
- ✅ DRM 完整初始化（2 crtc / 3 encoder / 3 connector）
- ✅ VA-API **H264 硬解打通**：`LIBVA_DRIVER_NAME=jmgpu vainfo`
  → `H264ConstrainedBaseline VLD`（景美闭源用户态配 jmgpu 内核成功）
- ❌→✅ **显示输出**：初期无信号（见下节根因与修复），修复后已完全打通

### 路线 A 附：「显示无信号」根因与修复（2026-09 重大突破）

**误诊澄清**：早期判定"connector connected 但 modes 为空 → 寄存器时序/phy 固有问题"是
**sysfs 误诊**——sysfs 的 `modes`/`edid` 文件为空 ≠ 内核无模式：只有 `GETCONNECTOR`
ioctl 才触发 `fill_modes`。用 `modetest -M jmgpu -c` 枚举后发现真 EDID（DDC 正常）
与 preferred `1920x1080@60` 模式**一直都在**。

**真正根因**（`modetest -s` 强制 setcrtc 触发内核 oops，抓栈定位）：

```
drm_mode_setcrtc → drm_atomic_commit → commit_tail
  → drm_atomic_helper_commit_modeset_enables
    → j9_handle_j9m_principium → j9_troglodyte → hdmi_phy_config_para [jmgpu]
      → drm_scdc_set_scrambling [drm_display_helper]   ← 调的是内核符号!
        → i2c_transfer → el1_abort → do_page_fault      ← 内核空指针 oops
```

因果链（两个移植遗漏叠加）：
1. HDMI connector 的 `late_register` 回调里创建了自管 i2c adapter `hdmi->ddc`，
   但**从未同步到内核标准字段 `connector->ddc`**（永远为 NULL）；
   EDID 读取走自己的 `hdmi->ddc` 所以一直正常，掩盖了问题。
2. 内核 **6.5+ 把 `drm_scdc_set_scrambling/set_high_tmds_clock_ratio` 签名从
   `(struct i2c_adapter*, bool)` 改为 `(struct drm_connector*, bool)`**；
   厂商本地 adapter 版实现 `jmgpu_scdc_set_*` 被 `#if < KERNEL_VERSION(4,12,0)`
   条件块排除，6.6 下调用链接到内核 connector 版 → 内部 `connector->ddc` = NULL
   → `i2c_transfer(NULL)` → translation fault → atomic commit 未完成 → **HDMI 无信号**。
   （"厂商私有 SCDC 函数改名"只改了 read/write，set_scrambling 一族被漏掉。）

**修复**（3 处，全在 `jmgpu_nicely.c`）：
| 修复 | 位置 |
|---|---|
| `hdmi->connector.ddc = hdmi->ddc;`（late_register 内，init memset 之后） | 原约 1635 行 |
| 8 处 `drm_scdc_set_scrambling/set_high_tmds_clock_ratio(&hdmi->connector, …)` → `jmgpu_scdc_*(hdmi->ddc, …)` | `hdmi_phy_config_para`/`hdmi_set_high_tmds_clock_ratio`/SCDC work |
| `jmgpu_scdc_set_scrambling/set_high_tmds_clock_ratio` 定义移出 `#if <4.12` 条件块 | 原约 818-867 行 |

**修复后验证**：
- `modetest -M jmgpu -s 41@35:1920x1080` → rc=0，屏幕出现彩条（显示管线全通）
- 普通显示器（HDMI 1.4 无 SCDC）下 `jmgpu_scdc_*` 读 SCDC 寄存器 NACK（err=-6）
  → 返回 false 无害降级，PHY 配置继续完成——这正是内核版函数做不到的
- 开机持久化（`force_mode_test.sh boot`：blacklist mwv207 进 initramfs +
  `/etc/modules-load.d/jmgpu.conf` 强制加载）后 lightdm + 专有 X 驱动正常点亮桌面
- `vainfo` 同栈报全 profile：H264 全系 / HEVC Main+Main10 / VP9 / JPEG VLD
- **VA-API 硬解实测**（见 FIXLOG.md「修复 3」）：H264/HEVC/VP9 硬解输出与软解
  校验和完全一致（像素正确）；4K30 x264 CPU 占用 user 1.617→0.143s（省约 91%），
  但吞吐不及 D2000 软解，价值主要在 CPU 卸载

### 路线 A 附 2：「显示灰蒙蒙」—— 已解决 ✅（排查记录见 FIXLOG.md「问题 2」修复 4/5/6）

显示点亮后曾有画质问题：**整体像蒙一层灰滤镜，黑色发灰、白色不白，但色相
完全正确**（照片证据见 FIXLOG 引用的两张图）；硬件鼠标光标色彩正常。

**最终根因**（2026-09-08 定位）：X 专有驱动 `mwv207_drv.so` 的 gamma 下发存在
**固定 1/3 线性缩放缺陷**（恒等请求也下发 `in/3` 的 ramp，实测采样
`[0,21,42,64,85]`），经 atomic_flush 写入 jmgpu 硬件 LUT → 整屏低对比度。
mwv207 开源栈的 X 不写 ramp，故同显示器正常。

**最终修复**：内核驱动 `gamma_norm` 参数（默认 3）在写 LUT 前对 ramp 乘 3
归一化——灰滤镜消失，**系统亮度/gamma 调节同步恢复可用**。
排查过程、initramfs 冻结旧模块导致的多次误判教训、参数使用方法，
完整记录见 **FIXLOG.md「问题 2」修复 4/5/6**。

**早期排查记录**（供参考，部分结论后被修正）：
1. `rgb_limited_range` 条件化（full 直通 + FULL 声明）——无效
2. 清理 grub 残留 `video=`/`drm.edid_firmware=`——无效
3. `virtual_display=0`——无效
4. 数据恢复 CEA 默认 limited + 手写 AVI 量化范围声明 LIMITED——无效
   （终局认知：灰与 RGB 量化范围/AVI 声明无关，两栈 HDMI 域寄存器完全一致；
   早期"modetest 直出彩条仍灰"是被 X 已写入的暗化 LUT 遗留污染所致）

### 路线 B：Icenowy 社区开源 mwv207-dkms

**目标**：用社区适配 6.7+ 的开源驱动替代。

**做法**：`github.com/Icenowy/mwv207-dkms` 在 6.6.143 编译，仅需将 Makefile
`obj-$(CONFIG_DRM_MWV207)` 改 `obj-m` 即可，**零移植一次通过**。

**结论**：该驱动含完整 dc/ 显示控制器 + pipe_dec/enc，但**无解码用户态**，
deepin 多媒体(VA-API)接不上；且与 deepin 自带 mwv207 同源同名，替换需处理 initramfs
时序（deepin mwv207 在 initramfs 早期 3.9s 就加载占用设备）。

### 路线 C：景美官方 6.6 内核补丁（最新官方）

**目标**：用 openkylin 仓库 `jemoic/Jemoic-OpenHarmony-code-source` 提供的官方 6.6 补丁。

**做法**：`linux_6.6/mwv207_gpu.patch`（57 个新增文件）提取为独立驱动树
（脚本 `extract_patch.py`），仅修 **1 处** API（`drm_device.irq_enabled` 6.4+ 移除）
即编译通过 → `mwv207.ko` (9.1MB, 含 0x9100)。

**结论**：官方为飞腾 D2000+JM9100+6.6 设计，含完整 dc/ 显示 + pipe_dec/enc + `dc/mwv207_va.c`，
显示最可能可用。但**不建 /dev/jmgpu**，且配套解码用户态 `bellagio/`（OpenMAX）在景美
仓库中为**空目录**——**官方没有开放解码用户态**。

### 路线 D：解码用户态调查（四处寻找）

| 用户态来源 | 结果 |
|---|---|
| deepin 生态 | apt 源仅闭源包；ffmpeg 用 VA-API 对不上开源 mwv207 自定义 ioctl |
| 景美开源 mesa (jemoic / everything411) | **纯 3D**，无 `create_video_codec`/vl 视频管线 |
| bellagio (OpenMAX IL) | 标准框架无 mwv207 组件；deepin 桌面不走 OpenMAX |
| 闭源 jmgpu VA | H264/HEVC/VP9 硬解可用；闭源内核"显示坏"已修复（§3 路线 A），现为最终采用方案 |

---

## 4. 最终架构结论（矛盾已解）

~~"显示"与"H264硬解"无法同时达成~~ —— **已被推翻**。

```
                 ┌────────────────────────────────────┐
  单卡全功能     │  闭源 jmgpu 内核 (1.7.0 + 本仓库补丁) │
  (修复后)       │  显示 ✅ GL ✅ 硬解 ✅              │
                 │  /dev/jmgpu + /dev/dri/card0        │
                 └────────────────────────────────────┘
```

**历程复盘**：早期认为"闭源内核显示输出固有问题 + 开源系无解码用户态 ⇒ 无解"。
实际是**闭源内核存在一处 SCDC API 迁移遗漏**（详见 §3 路线 A 修复记录），
用 `modetest` 强制 setcrtc 抓到内核 oops 栈即定位；三行级修复后显示点亮。
遗留的画质问题（灰蒙蒙）已定位到内核输出层，尚待根因，见 FIXLOG.md「问题 2」。

**仍然成立的客观事实**：
1. 一个 PCI 设备只能绑一个内核驱动（jmgpu 与 mwv207 仍互斥，但已不需要共存）
2. 景美开源系（deepin mwv207 / 官方 6.6 / Icenowy）从内核到 mesa 仍无解码用户态
   （bellagio 空/闭源）——若要走纯开源路线，结论不变：无用户态，无解
3. deepin 官方对景美卡的支持已转向商业 UOS（社区商店驱动已下架）

**deepin 上可用方案（本仓库）**：补丁版闭源 jmgpu 栈持久化接管，显示+硬解全功能。

---

## 5. 交付物清单

| 路径/提交 | 说明 |
|---|---|
| git 基线 `13de34c` | 闭源 jmgpu 1.7.0 移植到 6.6.143 的完整源码 |
| git 提交（SCDC 修复） | `jmgpu_nicely.c` 三处修复：`connector.ddc` 同步、8 处调用换 `jmgpu_scdc_*`、函数移出 `<4.12` 条件块（见 §3 路线 A） |
| `sync_dkms.sh` | 同步源码到 DKMS 并 build+install+update-initramfs（一条龙） |
| `force_mode_test.sh` | 方案1 强制点屏验证（live 诊断/boot 持久化/boot-undo 回滚，SSH 可控自动回退） |
| `color_bisect.sh` | 灰蒙蒙二分实验（A: modetest 彩条判定内核输出层 / B: modesetting 独立 X 判定 X 层） |
| `dump_display_regs.sh` | 显示关键寄存器 dump（VA/LUT/HDMI，两栈对比定位用） |
| `dump_full_regs.sh` | 显示域全量寄存器 dump（VA 0x990000-0x9907FF + TOP + HDMI，深度排查） |
| `fix_win_contrast.sh` | WIN_CONTRAST(0x990038) 寄存器写回（诊断工具） |
| `FIXLOG.md` | **修复记录**：SCDC 无信号修复 ✅ + 灰蒙蒙问题（修复 4 双 RAM / 修复 5 应急 / 修复 6 归一化 ✅，含 initramfs 教训与 gamma_norm 使用方法） |
| `verify_jmgpu_probe*.sh` | 真机 probe 验证脚本（SSH 可控，自动回退） |
| `check_jmgpu_display.sh` | DRM connector/mode/EDID 预检 |
| `diag_jmgpu_fail.sh` | 干净 dmesg 失败诊断 |
| `switch_full_closed_stack.sh` | 运行时切全闭源栈（jmgpu+专有 X 驱动）测试 |
| `extract_patch.py` | 从景美 6.6 patch 提取独立驱动树 |
| `/tmp/mwv207-official/` | 景美官方 6.6 驱动（已编译通过 mwv207.ko） |
| `/tmp/mwv207test/mwv207.ko` | Icenowy 开源驱动（已编译通过） |
| 本 README | 完整探索记录与结论 |

> 参考仓库：
> - 闭源：景美官网 dkms 1.7.0
> - 开源内核：`github.com/Icenowy/mwv207-dkms`
> - 官方 6.6：`gitee.com/jemoic/Jemoic-OpenHarmony-code-source`
> - GL：`github.com/everything411/mesa-mwv207`、`gitee.com/jemoic/mesa`

---

## 6. 结论与后续建议

**软件层正解已达成**：本仓库补丁版闭源 jmgpu 1.7.0 在 Deepin 25 / 6.6.143 上
**显示（无灰滤镜）+ GL + VA-API 硬解全功能可用**，无需 UOS。

后续建议：
0. ~~**灰蒙蒙画质问题（当前首要）**~~ **已解决 ✅（2026-09-08）**：根因为 X 专有
   驱动 gamma 下发的固定 1/3 缩放缺陷，内核侧 `gamma_norm=3` 归一化修复，
   系统亮度调节同步恢复；完整记录与使用方法见 FIXLOG.md「问题 2」修复 5/6。
   若需向景美反馈：X 驱动 `jmgpuDrmModeSetupColorMap`/gamma 路径的 1/3 缩放
   （dmesg 采样日志 `gamma_lut updated` 可作证据）。
1. **保持本仓库栈**：DKMS 已装补丁版 `jmgpu.ko`；持久化 = `force_mode_test.sh boot`
   （blacklist mwv207 + modules-load 强制加载 jmgpu）。回滚 = `boot-undo`。
   **改驱动源码后部署：`./sync_dkms.sh build`（已含 install + update-initramfs）
   再重启**——跳过 update-initramfs 会导致重启仍加载 initramfs 冻结的旧模块。
2. **向景美/deepin/飞腾反馈**：附本 README §3 路线 A 的 SCDC 根因与三处修复——
   同源代码在 UOS 之外的所有 6.x 内核上应有同样问题，补丁可直接回给厂商
3. **播放器接入硬解**：应用层用 `LIBVA_DRIVER_NAME=jmgpu`（VA-API 已报
   H264/HEVC/VP9 全 profile VLD）；mpv/ffmpeg 用 `--hwdec=vaapi` +
   `-vaapi_device /dev/dri/renderD128`
4. （可选）若未来想走纯开源路线：Icenowy/官方 6.6 内核显示可用但解码用户态
   仍缺失，需自写 VA driver 对接 `pipe_dec`，工作量大，现阶段无必要

---

## 7. 使用方法

### 7.1 驱动部署 / 持久化 / 回滚

```bash
# 当前栈检查：应只见 jmgpu
lsmod | grep -E 'jmgpu|mwv207'

# jmgpu 接管持久化（blacklist mwv207 进 initramfs + modules-load 强制加载）
sudo ./force_mode_test.sh boot && sudo reboot

# 回滚到 deepin mwv207 开源栈
sudo ./force_mode_test.sh boot-undo && sudo reboot
```

### 7.2 修改驱动源码后的标准部署流程

```bash
./sync_dkms.sh build    # = 同步源码 + dkms build --force + install --force
                        #   + update-initramfs -u（一条龙，缺一不可）
sudo reboot
```

**红线**：`dkms install` 后**必须重建 initramfs 再重启**——开机早期
modules-load 加载的是 initramfs 冻结的模块副本，否则新代码永远不生效。
验证新模块确实在跑：

```bash
cat /sys/module/jmgpu/srcversion                                          # 运行中模块指纹
modinfo -F srcversion /lib/modules/$(uname -r)/updates/dkms/jmgpu.ko      # 磁盘模块指纹
# 两者一致 = 新模块已生效；不一致 = 加载的是 initramfs 冻结的旧模块
```

### 7.3 显示色彩：`gamma_norm` 参数（灰滤镜修复）

X 专有驱动 `mwv207_drv.so` 的 gamma 下发有固定 1/3 线性缩放缺陷
（恒等请求也下发 `in/3` ramp），内核默认乘 3 归一化补偿：

```bash
# 查看当前模式（默认 3）
cat /sys/module/jmgpu/parameters/gamma_norm

# 运行时切换（立即生效，无需重启）
echo 3 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 3 = 归一化（正常，默认）
echo 0 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 0 = 跳过用户态 gamma（应急）
echo 1 | sudo tee /sys/module/jmgpu/parameters/gamma_norm  # 1 = 原样写（复现缺陷/调试）

# 开机固定（可选）：写入 /etc/modprobe.d/jmgpu-gamma.conf
#   options jmgpu gamma_norm=3
```

| 模式 | 效果 |
|---|---|
| `gamma_norm=3`（默认） | 画面正常无灰滤镜，系统设置→显示→亮度滑条可用 |
| `gamma_norm=0` | LUT 恒为线性表（画面正常），亮度调节失效（应急用） |
| `gamma_norm=1` | 复现 X 驱动缺陷：整屏蒙灰、亮度只有应有值的 1/3 |

诊断：`sudo dmesg | grep "gamma_lut updated"` —— 打印 X 驱动每次下发的
ramp 采样值（正常应为线性 `0,63,128,192,255`；缺陷形态为 `0,21,42,64,85`）。

### 7.4 视频硬解（VA-API）

```bash
# Profile 查询
LIBVA_DRIVER_NAME=jmgpu vainfo

# mpv（x11 会话自动回落 vaapi-copy，日志可见 Trying hardware decoding）
LIBVA_DRIVER_NAME=jmgpu mpv --hwdec=auto /path/video.mp4

# ffmpeg 校验硬解输出（与软解 md5 一致 = 像素正确）
ffmpeg -hwaccel vaapi -vaapi_device /dev/dri/renderD128 -i in.mp4 -f rawvideo \
    -pix_fmt nv12 - | md5sum
```

### 7.5 显示诊断工具

```bash
# 关键寄存器 dump（VA/LUT/HDMI 域）
sudo ./dump_display_regs.sh -o /tmp/reg.txt

# 显示域全量 dump（VA 0x990000-0x9907FF + TOP + HDMI）
sudo ./dump_full_regs.sh -o /tmp/full.txt

# WIN_CONTRAST 寄存器写回（诊断）
sudo ./fix_win_contrast.sh f0

# modetest 查 connector（注意：本栈 modetest 直亮彩条点不亮，属已知问题，勿当故障）
modetest -D /dev/dri/card0 -c
```
