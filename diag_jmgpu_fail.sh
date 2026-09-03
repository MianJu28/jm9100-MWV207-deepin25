#!/usr/bin/env bash
# 最小化诊断 jmgpu 不稳定 probe：抓从 modprobe 起的完整 dmesg + 关键节点。
# 用法(SSH): sudo ./diag_jmgpu_fail.sh
set -uo pipefail
PCI="0000:07:00.0"
LOG=/var/log/jmgpu_diag.log
export PATH=/usr/sbin:/usr/bin:/sbin:/bin
log(){ echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }

echo "==== jmgpu 失败诊断 $(date) ====" | tee "$LOG"
MARK=$(date +%s)
recover(){
  [ -f /sys/bus/pci/devices/$PCI/driver_override ] && echo "" > /sys/bus/pci/devices/$PCI/driver_override 2>/dev/null
  rmmod jmgpu 2>/dev/null; modprobe -r jmgpu 2>/dev/null; sleep 1
  modprobe mwv207 2>/dev/null; sleep 3
  if [ -d /sys/bus/pci/drivers/mwv207 ] && [ ! -e /sys/bus/pci/devices/$PCI/driver ]; then
    echo "$PCI" > /sys/bus/pci/drivers/mwv207/bind 2>/dev/null
  fi
  systemctl start lightdm 2>/dev/null
}

# 释放 GPU
log "[1] 停 lightdm / 卸 mwv207"
systemctl stop lightdm 2>>"$LOG"; sleep 2; pkill -9 Xorg 2>/dev/null; sleep 1
modprobe -r mwv207 2>>"$LOG"; sleep 2

# 清空 dmesg 环形缓冲，确保从零开始抓 jmgpu 本次日志
log "[2] 清空 dmesg 后加载 jmgpu"
sudo dmesg -c >/dev/null 2>&1 || true
echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override 2>>"$LOG"
modprobe jmgpu 2>>"$LOG"
sleep 6

log "[3] 关键节点检查:"
log "   /dev/jmgpu: $(ls /dev/jmgpu 2>/dev/null || echo 无)"
log "   /dev/dri/card0: $(ls /dev/dri/card0 2>/dev/null || echo 无)"
log "   /dev/dri/renderD128: $(ls /dev/dri/renderD128 2>/dev/null || echo 无)"

log "[4] 本次 jmgpu 完整 dmesg (从头, 未过滤):"
dmesg >> "$LOG" 2>&1
log "   (上面为完整 dmesg 原始输出)"

recover
log "==== 诊断结束。完整日志: $LOG ===="
echo; echo "结果写入 $LOG，请全文发开发者(尤其 [4] 段)。"
