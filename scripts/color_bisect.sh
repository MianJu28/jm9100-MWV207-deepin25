#!/usr/bin/env bash
# 灰蒙蒙二分定位: A(modetest 彩条=内核输出层) / B(modesetting 独立X=X专有驱动层)
# 前提: jmgpu 栈已接管(开机持久化生效)。全程 SSH 可控, 结束自动恢复 lightdm。
# 用法: sudo ./scripts/color_bisect.sh
# 观察结果按脚本结尾判读表回报。
set -uo pipefail

LOG=/var/log/jmgpu_color_bisect.log
export PATH=/usr/sbin:/usr/bin:/sbin:/bin

log(){ echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }

RECOVERED=0
recover(){
  [ "$RECOVERED" = 1 ] && return; RECOVERED=1
  log "==> 清理恢复"
  pkill -9 modetest 2>/dev/null
  pkill -9 Xorg 2>/dev/null
  sleep 1
  systemctl start lightdm 2>/dev/null
  log "==> lightdm 已恢复"
}
trap 'recover' EXIT INT TERM

echo "==== 灰蒙蒙二分实验 $(date) ====" | tee "$LOG"

log "[0] 当前驱动状态:"
lsmod | grep -E "jmgpu|mwv207" | head -3 >> "$LOG" 2>&1
if ! lsmod | grep -q jmgpu; then
  log "!! jmgpu 未加载(当前是 mwv207 栈), 本脚本只测 jmgpu 栈"
  exit 1
fi
command -v modetest >/dev/null 2>&1 || { apt-get install -y libdrm-tests >>"$LOG" 2>&1 && log "libdrm-tests 已装" || log "!! libdrm-tests 安装失败"; }

# ============ 实验 A: modetest 彩条 (内核输出层, 不经 X) ============
log "==== 实验 A: modetest 彩条 (判定: 内核->HDMI 输出层) ===="
systemctl stop lightdm 2>>"$LOG"; sleep 2; pkill -9 Xorg 2>/dev/null; sleep 1

if modetest -M jmgpu -c >/dev/null 2>&1; then MT="modetest -M jmgpu"
else MT="modetest -D /dev/dri/card0"; fi
CONN=$($MT -c 2>/dev/null | grep -v disconnected | awk '/connected/{print $1; exit}')
CRTC=$($MT -p 2>/dev/null | awk '/^[0-9]+\t/{print $1; exit}')
log "    connector_id=$CONN crtc_id=$CRTC"
if [ -z "$CONN" ] || [ -z "$CRTC" ]; then
  log "!! connector/crtc 枚举失败"
  recover; exit 1
fi

log "    >>> 彩条将显示 40 秒 <<<"
log "    ★★ 记录三项: 1)黑色块是否纯黑  2)白色块是否纯白  3)灰阶渐变是否平滑 ★★"
log "    $ $MT -s $CONN@$CRTC:1920x1080"
sleep 40 | $MT -s "$CONN@$CRTC:1920x1080" >/dev/null 2>&1
log "    实验 A 结束 (屏幕复黑属正常)"

# ============ 实验 B: modesetting 独立 X (X 专有驱动对照层) ============
log "==== 实验 B: modesetting 独立 X (判定: X 渲染/专有驱动层) ===="
cat > /tmp/xorg-color-bisect.conf <<'EOF'
Section "Device"
    Identifier "jmgpuDev"
    Driver "modesetting"
    BusID "PCI:7:0:0"
    Option "kmsdev" "/dev/dri/card0"
EndSection
Section "Screen"
    Identifier "jmgpuScreen"
    Device "jmgpuDev"
EndSection
EOF

log "    >>> 独立 X 将显示 40 秒 <<<"
log "    ★★ 记录: X 的灰色格子背景(root window)是否黑白分明, 与桌面灰蒙蒙对比 ★★"
( Xorg -config /tmp/xorg-color-bisect.conf -logfile /tmp/xorg-color-bisect.log -nolisten tcp :8 vt8 >/dev/null 2>&1 ) &
XPID=$!
sleep 6
if kill -0 $XPID 2>/dev/null; then
  log "    X 存活 (pid $XPID), 保持显示..."
  sleep 34
  log "    X 关键日志:"
  grep -iE "modesetting|screen|EE|error" /tmp/xorg-color-bisect.log 2>/dev/null | tail -6 >> "$LOG"
else
  log "    !! X 已退出, 日志尾部:"
  tail -15 /tmp/xorg-color-bisect.log >> "$LOG" 2>&1
fi
pkill -9 Xorg 2>/dev/null
log "    实验 B 结束"

recover
trap - EXIT INT TERM

log "==== 二分结束, 请按判读表回报 A/B 观察结果 ===="
cat <<'TBL'

================ 判读表 ================
A 彩条正常 + B 灰格正常  => 内核输出层OK, 灰在专有X驱动(mwv207_drv.so)
                            => 方案: 日常改用 modesetting X 驱动
A 彩条灰                 => 灰在内核输出层 => 需要 LUT 写入调试补丁
A 彩条正常 + B 灰格异常  => 请描述异常细节
========================================
TBL
