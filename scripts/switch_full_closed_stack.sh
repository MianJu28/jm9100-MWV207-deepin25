#!/usr/bin/env bash
# 决定性测试: 运行时把 07:00.0 切换到闭源 jmgpu 内核, 并启动 lightdm,
# 让 10-mwv207.conf 触发景嘉微专有 mwv207_drv.so X 驱动, 验证显示+VA。
# 在 SSH 会话里运行(本地断显不影响). 失败自动回退 mwv207.
# 用法: sudo ./scripts/switch_full_closed_stack.sh
set -uo pipefail
PCI="0000:07:00.0"
LOG=/var/log/jmgpu_full_stack.log
export PATH=/usr/sbin:/usr/bin:/sbin:/bin
log(){ echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }
echo "==== 全闭源栈切换测试 $(date) ====" | tee "$LOG"

recover(){
  log "==> 回退 mwv207"
  systemctl stop lightdm 2>/dev/null; sleep 1
  pkill -9 Xorg 2>/dev/null
  [ -f /sys/bus/pci/devices/$PCI/driver_override ] && echo "" > /sys/bus/pci/devices/$PCI/driver_override 2>/dev/null
  rmmod jmgpu 2>/dev/null; modprobe -r jmgpu 2>/dev/null; sleep 1
  modprobe mwv207 2>/dev/null; sleep 3
  if [ -d /sys/bus/pci/drivers/mwv207 ] && [ ! -e /sys/bus/pci/devices/$PCI/driver ]; then
    echo "$PCI" > /sys/bus/pci/drivers/mwv207/bind 2>/dev/null
  fi
  systemctl start lightdm 2>/dev/null
  log "==> 已回退 mwv207 + lightdm"
}

# 1. 停图形, 卸 mwv207
log "[1] 停 lightdm + 卸 mwv207"
systemctl stop lightdm 2>>"$LOG"; sleep 2; pkill -9 Xorg 2>/dev/null; sleep 1
modprobe -r mwv207 2>>"$LOG"; sleep 2
if lsmod | grep -q mwv207; then log "!! mwv207 无法卸载(仍被占)"; recover; exit 1; fi
log "    mwv207 已卸, 设备空闲"

# 2. jmgpu 接管 (driver_override 避免自动绑定问题)
log "[2] jmgpu 接管 $PCI"
echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override 2>>"$LOG"
modprobe jmgpu 2>>"$LOG"; sleep 5
if [ ! -e /dev/jmgpu ]; then log "!! jmgpu probe 失败(无 /dev/jmgpu)"; recover; exit 1; fi
log "    /dev/jmgpu OK, DRM:"; ls /dev/dri/ >>"$LOG" 2>&1

# 3. 关键: 启动 lightdm, 让 10-mwv207.conf 触发专有 mwv207_drv.so
log "[3] 启动 lightdm (应触发专有 mwv207_drv.so X 驱动)"
systemctl start lightdm 2>>"$LOG"; sleep 8

# 4. 检查 X 是否起来 + 用哪个驱动
log "[4] X 状态:"
ps aux | grep "[X]org" | awk '{print "   pid",$2,$11,$12,$13}' >>"$LOG" 2>&1 || log "   X 未运行"
grep -iE "Loading .*_drv|mwv207_drv|modeset|EE |fatal|no screens" /var/log/Xorg.0.log 2>/dev/null | tail -8 >>"$LOG"

# 5. VA 硬解测试
log "[5] VA-API 测试:"
log "   /dev/jmgpu: $(ls /dev/jmgpu 2>/dev/null || echo 无)"
LIBVA_DRIVER_NAME=jmgpu vainfo 2>&1 | head -12 >>"$LOG"

log "==== 测试完成 ===="
echo
echo "请观察主显示器是否点亮 (此时是 jmgpu+专有驱动)."
echo "日志: $LOG"
echo "若点亮且 vainfo 有 profile => 打通."
echo "验证完要回 deepin mwv207: 再跑本脚本或手动恢复, 或重启(blacklist 未进 initramfs,重启自动回 mwv207)"
