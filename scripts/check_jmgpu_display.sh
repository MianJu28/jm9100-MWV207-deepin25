#!/usr/bin/env bash
# jmgpu 显示输出能力预检。
# 目的: 确认 jmgpu 接管后其 DRM 是否注册了可用的 connector/modes，
#       判断能否真正驱动显示(避免 blacklist mwv207 重启后黑屏)。
# 用法(SSH 会话):  sudo ./scripts/check_jmgpu_display.sh
#
# 流程: 停 lightdm -> 卸 mwv207 -> jmgpu 接管并停留 -> 采集 DRM/connector/modes
#       -> 回退 mwv207 -> 恢复 lightdm。全程 SSH 可见。
set -uo pipefail
PCI="0000:07:00.0"
LOG=/var/log/jmgpu_display_check.log
export PATH=/usr/sbin:/usr/bin:/sbin:/bin
log(){ echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }

echo "==== jmgpu 显示能力预检 $(date) ====" | tee "$LOG"

recover(){
  log "==> 回退 mwv207 + 恢复 lightdm"
  [ -f /sys/bus/pci/devices/$PCI/driver_override ] && echo "" > /sys/bus/pci/devices/$PCI/driver_override 2>/dev/null
  rmmod jmgpu 2>/dev/null; modprobe -r jmgpu 2>/dev/null; sleep 1
  modprobe mwv207 2>/dev/null; sleep 3
  if [ -d /sys/bus/pci/drivers/mwv207 ] && [ ! -e /sys/bus/pci/devices/$PCI/driver ]; then
    echo "$PCI" > /sys/bus/pci/drivers/mwv207/bind 2>/dev/null && log "mwv207 手动重绑"
  fi
  systemctl start lightdm 2>/dev/null
  log "==> 已恢复 mwv207"; readlink /sys/bus/pci/devices/$PCI/driver >>"$LOG" 2>/dev/null
}

log "[1] 停 lightdm, 释放 GPU"
systemctl stop lightdm 2>>"$LOG"; sleep 2; pkill -9 Xorg 2>/dev/null; sleep 1

log "[2] 卸载 mwv207"
modprobe -r mwv207 2>>"$LOG"; sleep 2
if lsmod | grep -q mwv207; then log "!! mwv207 卸载失败"; recover; exit 1; fi

log "[3] jmgpu 接管 $PCI"
echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override 2>>"$LOG"
modprobe jmgpu 2>>"$LOG"
sleep 5

log "[4] jmgpu DRM 设备节点:"
ls -l /dev/dri/* 2>/dev/null >>"$LOG" || log "   (无 /dev/dri/*)"
ls -l /sys/class/drm/ 2>>"$LOG" | grep -iE "card|render|connector" >>"$LOG" 2>&1

log "[5] connector 状态:"
for c in /sys/class/drm/card*-*/; do
  name=$(basename "$c")
  status=$(cat "$c/status" 2>/dev/null)
  log "   connector $name: status=$status"
done

log "[6] connected connector 的 mode 与 EDID 诊断:"
for c in /sys/class/drm/card*-*/; do
  name=$(basename "$c")
  st=$(cat "$c/status" 2>/dev/null)
  if [ "$st" = "connected" ]; then
    log "   --- $name (connected):"
    log "      modes 文件内容:"
    if [ -s "$c/modes" ]; then
      cat "$c/modes" 2>/dev/null >> "$LOG"
    else
      log "      (modes 文件为空!)"
    fi
    log "      edid 是否可读:"
    if [ -f "$c/edid" ] && [ -s "$c/edid" ]; then
      sz=$(stat -c%s "$c/edid" 2>/dev/null)
      log "      edid 大小=$sz 字节 (非空=读到 EDID)"
    else
      log "      edid 空或不存在 (未读到 EDID!)"
    fi
    log "      dpms 状态: $(cat "$c/dpms" 2>/dev/null)"
    log "      enabled: $(cat "$c/enabled" 2>/dev/null)"
  fi
done
log "      --- dmesg EDID/HDMI 相关:"
dmesg | tail -120 | grep -iE "edid|hdmi|hdcp|scdc|mode|connector|link" >> "$LOG" 2>&1 || true

log "[7] 回退前完整 DRM 环境:"
ls -l /sys/bus/pci/devices/$PCI/ 2>/dev/null | grep -iE "drm|driver" >>"$LOG"

recover
log "==== 预检结束。完整日志: $LOG ===="
echo; echo "结果已写入 $LOG。请把内容发开发者。"
