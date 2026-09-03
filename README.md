# JM9100 (MWV207) GPU 驱动移植与视频硬解探索记录

> 本仓库记录了在 **Phytium（飞腾）+ 景嘉微 JM9100 (PCI 0731:9100)** 平台上，
> 将 GPU 驱动移植到内核 **6.6.143-arm64-desktop-hwe (Deepin 25)** 并尝试打通
> **视频硬解 (H.264)** 的完整过程、代码修改与验证结论。

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
| **闭源 jmgpu.ko** | 景美闭源 1.7.0 | ✅ | ❌ 无信号 | ✅ | ✅ (H264 VLD 实测) |
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
- ❌ **显示输出无信号**：连 HDMI-A-1 `connected` 但 `modes` 为空，CRTC 无法 modeset
  - modesetting Xorg：进程存活但无画面
  - 景美专有 `mwv207_drv.so` Xorg 驱动（`10-mwv207.conf` MatchDriver jmgpu 触发）：仍无信号
  - 判定为**景美闭源驱动显示输出固有问题**（寄存器时序/phy 未正确初始化）

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
| 闭源 jmgpu VA | 唯一能 H264 硬解的，但绑死"显示坏"的闭源内核 |

---

## 4. 最终架构结论（不可调和的矛盾）

```
                    ┌─────────────────────────────┐
  video H264 hard   │  需要 VA 用户态 (VA-API)     │
  decode            │  = 闭源 jmgpu_drv_video.so   │
                    └──────────────┬──────────────┘
                                   │ 只认 /dev/jmgpu
                                   ▼
                       闭源 jmgpu 内核驱动
                     ┌──────────────┴─────────────┐
                     │ 硬解 ✅  但 显示 ❌ 无信号   │
                     └────────────────────────────┘

  desktop display    │ 开源 mwv207 内核 (deepin/景美官方/Icenowy)
                     │ 显示 ✅  但无 VA 解码用户态 (bellagio 未开源)
                     └────────────────────────────┘

  ※ 一个 PCI 设备只能绑一个内核驱动 ⇒ "显示"与"H264硬解"无法同时达成
```

**三层原因**：
1. **单卡单驱动**物理限制：jmgpu 与 mwv207 不能同时用
2. **景美闭源用户态绑死闭源内核**（VA 要 /dev/jmgpu），而闭源内核显示输出固有问题
3. **景美开源系从内核到 mesa 都没给解码用户态**（bellagio 空/闭源）

**deepin 官方对景美卡支持现状**：已转向商业 UOS（deepin 社区商店驱动已下架，
论坛确认景美卡在 deepin"无法使用"是普遍已知问题，非个例）。

---

## 5. 交付物清单

| 路径/提交 | 说明 |
|---|---|
| git 基线 `13de34c` | 闭源 jmgpu 1.7.0 移植到 6.6.143 的完整源码 |
| `sync_dkms.sh` | 同步源码到 DKMS 并 rebuild |
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

**软件层无正解**。JM9100 视频硬解需景美提供"显示正常 + 硬解可用"的完整驱动栈。

可行的后续（非本仓库代码可解决）：
1. **安装 UOS**：景美卡官方完整支持（显示+硬解），社区公认最省心方案
2. **反馈景美/deepin/飞腾整机厂**：附本 README 作为"闭源驱动显示坏" + "开源无解码用户态"的证据
3. **维持现状**：deepin mwv207 显示 + 应用层软解优化（如 pure_live 的 720p+纹理上限方案）
