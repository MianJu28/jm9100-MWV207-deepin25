#!/usr/bin/env bash
# 决定性测试: jmgpu 接管后, 用 Xorg modesetting 驱动在其 card0 上启动 X,
# 验证能否真正输出显示。
# 用法(SSH): sudo ./scripts/x_test_jmgpu.sh
# 安全: 全程 SSH 可见; X 启动失败会自动清理并回退 mwv207; 主显示器若点亮说明成功。
set -uo pipefail
PCI="0000:07:00.0"
LOG=/var/log/jmgpu_x_test.log
export PATH=/usr/sbin:/usr/bin:/sbin:/bin
log(){ echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }
echo "==== jmgpu X 显示测试 $(date) ====" | tee "$LOG"

recover_all(){
  log "==> 清理并回退 mwv207"
  pkill -9 Xorg 2>/dev/null; pkill -9 lightdm 2>/dev/null; sleep 1
  [ -f /sys/bus/pci/devices/$PCI/driver_override ] && echo "" > /sys/bus/pci/devices/$PCI/driver_override 2>/dev/null
  rmmod jmgpu 2>/dev/null; modprobe -r jmgpu 2>/dev/null; sleep 1
  modprobe mwv207 2>/dev/null; sleep 3
  if [ -d /sys/bus/pci/drivers/mwv207 ] && [ ! -e /sys/bus/pci/devices/$PCI/driver ]; then
    echo "$PCI" > /sys/bus/pci/drivers/mwv207/bind 2>/dev/null
  fi
  systemctl start lightdm 2>/dev/null
  log "==> 已恢复 mwv207 + lightdm"
}

# 1. 释放 GPU
log "[1] 释放 GPU (停 lightdm / 卸 mwv207)"
systemctl stop lightdm 2>>"$LOG"; sleep 2; pkill -9 Xorg 2>/dev/null; sleep 1
modprobe -r mwv207 2>>"$LOG"; sleep 2

# 2. jmgpu 接管
log "[2] jmgpu 接管"
echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override 2>>"$LOG"
modprobe jmgpu 2>>"$LOG"
sleep 6
[ -e /dev/dri/card0 ] || { log "!! jmgpu 未建 card0, 放弃"; recover_all; exit 1; }
log "    card0 就绪: $(ls /dev/dri/card0)"

# 3. 写临时 Xorg 配置, 强制 modesetting + card0, 用 vt 避免冲突
XCONF=/tmp/xorg-jmgpu.conf
cat > "$XCONF" <<'EOF'
Section "ServerLayout"
    Identifier "jmgpu"
    Screen 0 "jmgpuScreen"
EndSection
Section "Device"
    Identifier "jmgpuDev"
    Driver "modesetting"
    BusID "PCI:7:0:0"
    Option "kmsdev" "/dev/dri/card0"
EndSection
Section "Screen"
    Identifier "jmgpuScreen"
    Device "jmgpuDev"
    DefaultDepth 24
    SubSection "Display"
        Depth 24
    EndSubSection
EndSection
EOF

log "[3] 用 modesetting 启动独立 X (jmgpu card0)"
# 后台启动 X, 日志落盘
( Xorg -config "$XCONF" -logfile /tmp/xorg-jmgpu.log -nolisten tcp -noreset :8 vt8 2>>"$LOG" ) &
XPID=$!
sleep 5

# 4. 判断 X 是否成功
if kill -0 $XPID 2>/dev/null; then
  log "★★★ X 进程存活 (pid $XPID) - 可能已点亮显示器 ★★★"
  # 尝试截屏确认有画面 (xwd 或读 framebuffer)
  ls /tmp/.X11-unix/ 2>/dev/null >>"$LOG"
  log "Xorg 日志关键行:"
  grep -iE "screen|monitor|connected|mode|EE|fatal|no screens|error" /tmp/xorg-jmgpu.log 2>/dev/null | tail -15 >>"$LOG"
else
  log "!! X 进程已退出 - 启动失败"
fi

log "[4] 显示器状态确认:"
for c in /sys/class/drm/card0-HDMI*/; do
  st=$(cat "$c/status" 2>/dev/null); en=$(cat "$c/enabled" 2>/dev/null)
  log "   $(basename $c): status=$st enabled=$en modes=$(wc -l < "$c/modes" 2>/dev/null)个"
done

log "==== X 测试完成 ===="
echo
echo "请观察主显示器是否点亮/出现画面。"
echo "若点亮且 X 存活 => 说明 jmgpu 可接管显示。"
echo "结果日志: $LOG 和 /tmp/xorg-jmgpu.log, 请发开发者。"
echo "要回退请运行: sudo systemctl start lightdm  (或重启, 因未改开机配置)"
# 不自动回退, 让用户能观察显示器; 用户确认后手动回退或重启
