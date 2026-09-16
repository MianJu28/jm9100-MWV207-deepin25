#!/usr/bin/env bash
# 真机验证 jmgpu 在独占 JM9100(07:00.0) 时 probe 能否完整成功。
#
# 必须在【纯文本控制台】运行（Ctrl+Alt+F2 ~ F6），不要在有 X11 桌面的终端里跑，
# 因为脚本会卸载 mwv207 并断开当前显示。
#
# 用法:  sudo ./scripts/verify_jmgpu_probe.sh
#
# 脚本逻辑:
#   1. 备份当前 mwv207 绑定，卸载 mwv207（会断开显示）
#   2. 用 driver_override 强制 07:00.0 绑到 jmgpu，加载 jmgpu
#   3. 抓取完整 probe 日志，判断成功/失败
#   4. 任何失败都自动回退：卸载 jmgpu -> 恢复 mwv207
set -uo pipefail

PCI="0000:07:00.0"
DRV=/sys/bus/pci/drivers
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

echo "======================================================"
echo " JM9100 jmgpu probe 验证（文本控制台专用）"
echo "======================================================"

# 记录开始时间戳用于过滤 dmesg
DMESG_MARK=$(date +%s)

cleanup() {
  echo
  echo "==> 回退中..."
  # 移除 jmgpu 的 override，卸载 jmgpu
  echo "--- unbind jmgpu (若已绑定)"
  [ -L "$DRV/jmgpu/$PCI" ] && echo "$PCI" > "$DRV/jmgpu/unbind" 2>/dev/null
  # 清空 override 恢复 mwv207 自动绑定
  [ -f "$DRV/jmgpu/remove_id" ] && true
  echo "--- 卸载 jmgpu"
  rmmod jmgpu 2>/dev/null
  modprobe -r jmgpu 2>/dev/null
  # 恢复 mwv207
  echo "--- 重新加载并绑定 mwv207"
  modprobe mwv207 2>/dev/null
  sleep 2
  echo "--- 尝试重新绑定 mwv207 到 $PCI"
  if [ -d "$DRV/mwv207" ] && [ ! -L "$DRV/mwv207/$PCI" ]; then
    echo "$PCI" > "$DRV/mwv207/bind" 2>/dev/null || echo "(自动绑定通常已生效)"
  fi
  lsmod | grep -E "mwv207|jmgpu"
  echo "==> 回退完成。若显示未恢复，请重启。"
}

# ---------- 1. 确认当前绑定 ----------
echo "[1] 当前 $PCI 驱动绑定:"
readlink "$DRV/mwv207/$PCI" 2>/dev/null || ls -l /sys/bus/pci/devices/$PCI/driver 2>/dev/null || echo "(未绑定)"

# ---------- 2. 卸载 mwv207 释放设备 ----------
echo
echo "[2] 卸载 mwv207 (显示将断开,属正常)"
echo "    (5 秒倒计时, Ctrl-C 可取消)"
sleep 5
modprobe -r mwv207 2>&1 | head -3
if lsmod | grep -q mwv207; then
  echo "!! mwv207 卸载失败(仍被占用),可能是有进程持有显示。"
  echo "   请先停止图形会话(systemctl stop lightdm)或改用单用户模式。"
  cleanup
  exit 1
fi
echo "    mwv207 已卸载, $PCI 现应空闲"

# ---------- 3. 强制 jmgpu 绑定并加载 ----------
echo
echo "[3] driver_override 强制 jmgpu 接管 $PCI"
echo "$PCI" > "$DRV/mwv207/unbind" 2>/dev/null || true
echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override
echo "    加载 jmgpu (probe 将在此触发)..."
modprobe jmgpu 2>&1 | head -3
sleep 3

# ---------- 4. 检查 probe 结果 ----------
echo
echo "[4] probe 日志:"
dmesg --since="$DMESG_MARK" 2>/dev/null | grep -iE "jmgpu|j9|jm9100|failed|error" | tail -30 || tail -30 /var/log/kern.log 2>/dev/null | grep -iE "jmgpu|j9" | tail -20

echo
echo "==> 绑定状态:"
ls -l /sys/bus/pci/devices/$PCI/driver 2>/dev/null || echo "  (无驱动绑定 - probe 失败)"
echo "==> 设备节点:"
ls -l /dev/jmgpu* 2>/dev/null || echo "  (无 /dev/jmgpu)"
ls -l /sys/bus/pci/devices/$PCI/ 2>/dev/null | grep -iE "drm|render" | head

if lsmod | grep -q jmgpu && [ -e /dev/jmgpu ]; then
  echo
  echo "★★★★★★ PROBE 成功 ★★★★★★"
  echo "  jmgpu 已接管 JM9100。若显示正常,可将 mwv207 加入 blacklist 使其持久。"
  echo "  当前为验证态;要回退到 mwv207,按 Ctrl-C 中断后运行 cleanup 或重启。"
else
  echo
  echo "!! PROBE 失败或未完成。正在自动回退到 mwv207..."
  cleanup
fi
