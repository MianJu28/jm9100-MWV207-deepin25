#!/usr/bin/env bash
# SSH 会话版 jmgpu probe 验证。
# 目的: 只确认 jmgpu 独占 JM9100(07:00.0) 时能否完整 probe(生成 /dev/jmgpu 与 DRM 节点)，
#       验证完【自动回退】到 mwv207，不破坏桌面。
# 用法(在 SSH 会话里执行):  sudo ./verify_jmgpu_probe_ssh.sh
#
# 与上次黑屏版的差异:
#   - 先停 lightdm 释放 GPU(否则 mwv207 卸载被拒)
#   - probe 完成后【不接管桌面】, 明确回退, 结果落盘 /var/log/jmgpu_probe.log
set -uo pipefail

PCI="0000:07:00.0"
LOG=/var/log/jmgpu_probe.log
export PATH=/usr/sbin:/usr/bin:/sbin:/bin

log() { echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }

echo "==== jmgpu probe 验证(SSH版) $(date) ====" | tee "$LOG"

recover() {
  log "==> 回退: 卸载 jmgpu, 恢复 mwv207"
  # 清 driver_override
  [ -f /sys/bus/pci/devices/$PCI/driver_override ] && \
    echo "" > /sys/bus/pci/devices/$PCI/driver_override 2>/dev/null
  rmmod jmgpu 2>/dev/null
  modprobe -r jmgpu 2>/dev/null
  sleep 1
  modprobe mwv207 2>/dev/null
  sleep 3
  # 若未自动绑定则手动 bind
  if [ -d /sys/bus/pci/drivers/mwv207 ] && [ ! -e /sys/bus/pci/devices/$PCI/driver ]; then
    echo "$PCI" > /sys/bus/pci/drivers/mwv207/bind 2>/dev/null && log "mwv207 已手动重新绑定"
  fi
  systemctl start lightdm 2>/dev/null
  log "==> 回退完成。当前驱动:"
  lsmod | grep -E "mwv207|jmgpu" >> "$LOG"
  readlink /sys/bus/pci/devices/$PCI/driver >> "$LOG" 2>/dev/null
}

# ---------- 停图形会话释放 GPU ----------
log "[1] 停止 lightdm 释放 GPU"
systemctl stop lightdm 2>>"$LOG"
sleep 2
pkill -9 Xorg 2>/dev/null
sleep 1

# ---------- 卸载 mwv207 ----------
log "[2] 卸载 mwv207"
modprobe -r mwv207 2>>"$LOG"
sleep 2
if lsmod | grep -q mwv207; then
  log "!! mwv207 仍被占用无法卸载(可能有进程持 drm)。中止并回退。"
  recover
  exit 1
fi
log "    mwv207 已卸载, 设备空闲"

# ---------- driver_override 强制 jmgpu ----------
log "[3] 强制 jmgpu 接管 $PCI"
echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override 2>>"$LOG"
modprobe jmgpu 2>>"$LOG"
sleep 4
log "    modprobe 后 lsmod:"
lsmod | grep -E "jmgpu|mwv207" >> "$LOG" 2>&1

# ---------- 判断结果 ----------
log "[4] probe 结果:"
if [ -e /dev/jmgpu ]; then
  log "★★★★ PROBE 成功: /dev/jmgpu 已创建 ★★★★"
  ls -l /dev/jmgpu* >> "$LOG" 2>&1
  ls -l /sys/bus/pci/devices/$PCI/drm 2>>"$LOG" || true
  # 记录 dmesg 中 probe 关键行
  dmesg | tail -40 | grep -iE "jmgpu|probe for|jm9100" >> "$LOG" 2>&1
else
  log "!! PROBE 失败: 无 /dev/jmgpu"
  log "    最近 dmesg (jmgpu 相关):"
  dmesg | tail -60 | grep -iE "jmgpu|j9|platform|failed|error|probe" >> "$LOG" 2>&1 || true
fi

# ---------- 自动回退到 mwv207, 恢复桌面 ----------
recover
log "==== 验证结束。完整日志: $LOG ===="
echo
echo "结果已写入 $LOG 。请把该文件内容发给开发者。"
