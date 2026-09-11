#!/usr/bin/env bash
#
# jmgpu_reload_test.sh -- 模块卸载/重载（.remove / probe 路径）验证，可选 S3 挂起恢复
#
# 为什么必须在 SSH（或 TTY）会话里跑：
#   jmgpu 被 Xorg / kwin / 桌面组件与 IDE 持有（本机实测 121 个引用），
#   不释放无法 rmmod；而停 lightdm 会连带杀掉图形会话里的终端。
#   所以本脚本沿用仓库既有做法（verify_jmgpu_probe_ssh.sh）：在独立于
#   图形会话的通道里执行，并且【无论如何都恢复桌面】。
#
# 两个必须绕过的坑（均为本机实测踩过）：
#   1) pkill -9 Xorg 后，X 来不及清理 /tmp/.X0-lock 与 /tmp/.X11-unix/X0，
#      残留会让 lightdm 再次启 X 时报
#        (EE) Cannot establish any listening sockets - Make sure an X server isn't already running
#      于是 lightdm 永远停在 activating、桌面起不来（2026-09-11 16:10 实测，
#      那次只能靠重启恢复）。因此：先 TERM 等它自清，必要时才 KILL，
#      KILL 之后必须手动清理锁/socket。
#   2) 桌面起得慢，restore 不能 4 秒就判死并 restart（反复打断反而更慢），
#      要轮询等待并收集 lightdm/Xorg 现场。
#
# 用法：
#   sudo ./jmgpu_reload_test.sh              # 只做卸载/重载
#   sudo ./jmgpu_reload_test.sh --suspend    # 重载并恢复桌面后，再做一次 S3 挂起/恢复
#       （S3 请在物理机前运行：恢复失败只能硬断电）
#
# 结果：/var/log/jmgpu_reload.log
#
set -uo pipefail

LOG=/var/log/jmgpu_reload.log
PCI="0000:07:00.0"
WANT_SUSPEND=0
[ "${1:-}" = "--suspend" ] && WANT_SUSPEND=1

export PATH=/usr/sbin:/usr/bin:/sbin:/bin

log() { echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }
drv_state() { lsmod | awk '/^jmgpu|^mwv207/{printf "%s(used=%s) ", $1, $3}'; }
refcnt() { lsmod | awk '/^jmgpu/{print $3}'; }
nodes() { echo "/dev/jmgpu=[$(ls /dev/jmgpu* 2>/dev/null | tr '\n' ' ')] /dev/dri=[$(ls /dev/dri 2>/dev/null | tr '\n' ' ')]"; }
kwarn() { dmesg -T 2>/dev/null | grep -iE "warning|bug|oops|refcount|use-after|slab|jmgpu.*(fail|error)" | tail -20 | sed 's/^/      /'; }

# X 被强杀后留下的锁/socket 会让后续 X 启动失败，务必清掉
x_clean_stale() {
	local f
	f=$(ls /tmp/.X*-lock /tmp/.X11-unix/X* 2>/dev/null | tr '\n' ' ')
	[ -n "$f" ] && log "    清理陈旧 X 锁/socket: $f"
	rm -f /tmp/.X*-lock /tmp/.X11-unix/X* 2>/dev/null
	return 0
}

wait_lightdm() { # $1=秒数
	local i
	for i in $(seq 1 "$1"); do
		systemctl is-active --quiet lightdm && return 0
		sleep 1
	done
	return 1
}

dump_display_failure() {
	log "     现场: systemctl status lightdm"
	systemctl status lightdm --no-pager -l 2>&1 | head -12 | sed 's/^/      /' >>"$LOG"
	log "     现场: journalctl -u lightdm -n 20"
	journalctl -u lightdm -n 20 --no-pager 2>&1 | sed 's/^/      /' >>"$LOG"
	log "     现场: Xorg 日志尾部"
	tail -15 /var/log/Xorg.*.log 2>/dev/null | sed 's/^/      /' >>"$LOG"
}

restore() {
	log "==> [restore] 恢复驱动与桌面"
	if ! lsmod | grep -q '^jmgpu'; then
		modprobe jmgpu 2>>"$LOG"
		if ! lsmod | grep -q '^jmgpu'; then
			log "!! jmgpu 重新加载失败，回退 mwv207"
			modprobe mwv207 2>>"$LOG"
		fi
	fi
	udevadm settle 2>/dev/null || sleep 1
	pgrep -x Xorg >/dev/null || x_clean_stale
	systemctl reset-failed lightdm 2>/dev/null
	systemctl start lightdm 2>>"$LOG"
	if ! wait_lightdm 30; then
		log "!! lightdm 30s 内未就绪，收集现场后重试一次"
		dump_display_failure
		x_clean_stale
		systemctl reset-failed lightdm 2>/dev/null
		systemctl restart lightdm 2>>"$LOG"
		wait_lightdm 30 || true
	fi
	log "[restore] lightdm=$(systemctl is-active lightdm) 驱动: $(drv_state) $(nodes)"
	readlink /sys/bus/pci/devices/$PCI/driver >>"$LOG" 2>&1
}
trap restore EXIT

log "==== jmgpu 卸载/重载验证 $(date) ===="
log "[0] 停机前: srcversion=$(cat /sys/module/jmgpu/srcversion 2>/dev/null) 驱动: $(drv_state) 引用计数=$(refcnt)"

# 清空环形缓冲，使卸载/重载阶段的 dmesg 归属无歧义（历史在 journalctl -k 中仍可查）
dmesg -C 2>>"$LOG" && log "    已清空 dmesg 环形缓冲，便于归属本阶段日志"

# ---------------------------------------------------------------- 释放 GPU
log "[1] 停 lightdm 并结束 Xorg（释放 DRM）"
systemctl stop lightdm 2>>"$LOG"
sleep 2
pkill -TERM Xorg 2>/dev/null
for i in $(seq 1 10); do pgrep -x Xorg >/dev/null || break; sleep 0.5; done
if pgrep -x Xorg >/dev/null; then
	log "    Xorg 未在 5s 内退出，改用 SIGKILL（随后清锁）"
	pkill -9 Xorg 2>/dev/null
	sleep 1
	x_clean_stale
fi
pkill -9 kwin_x11 2>/dev/null
sleep 1
udevadm settle 2>/dev/null || sleep 1
if command -v fuser >/dev/null 2>&1; then
	log "    仍占用 /dev/dri/card0 的进程:"
	fuser -v /dev/dri/card0 2>&1 | sed 's/^/      /' >>"$LOG"
fi

# ---------------------------------------------------------------- 卸载
log "[2] rmmod jmgpu（引用计数=$(refcnt)）"
rmmod jmgpu 2>>"$LOG"
rc=$?
log "    rmmod 返回码: $rc"
if lsmod | grep -q '^jmgpu'; then
	log "!! 卸载失败：模块仍驻留，引用计数=$(refcnt)（说明有驱动内引用未释放）"
else
	log "    jmgpu 已卸载 $(nodes)"
fi
log "[3] 卸载阶段 dmesg（尾 25 行）"
dmesg -T 2>/dev/null | tail -25 | sed 's/^/      /' >>"$LOG"
kwarn >>"$LOG"

# ---------------------------------------------------------------- 重载
log "[4] modprobe jmgpu"
modprobe jmgpu 2>>"$LOG"
udevadm settle 2>/dev/null || sleep 1
sleep 3
log "    srcversion=$(cat /sys/module/jmgpu/srcversion 2>/dev/null)  $(nodes)"
log "[5] 重载阶段 dmesg（尾 30 行）"
dmesg -T 2>/dev/null | tail -30 | sed 's/^/      /' >>"$LOG"
log "[6] 内核告警/错误汇总（重载后）"
kwarn >>"$LOG"

log "[7] 参数与显存"
log "    gamma_norm=$(cat /sys/module/jmgpu/parameters/gamma_norm 2>/dev/null) allow_invisible_mmap=$(cat /sys/module/jmgpu/parameters/allow_invisible_mmap 2>/dev/null) prefer_visible_pool=$(cat /sys/module/jmgpu/parameters/prefer_visible_pool 2>/dev/null)"
head -14 /sys/kernel/debug/jmgpu/meminfo 2>/dev/null | sed 's/^/      /' >>"$LOG"
dmesg | grep -E "pool CPU physical" | sed 's/^/      /' >>"$LOG"

log "==== 卸载/重载流程结束，开始恢复桌面 ===="
restore

# ---------------------------------------------------------------- 可选: S3
if [ "$WANT_SUSPEND" = "1" ]; then
	log "==== [S3] 挂起前状态: lightdm=$(systemctl is-active lightdm) 驱动 $(drv_state) $(nodes) ===="
	if ! systemctl is-active --quiet lightdm; then
		log "!! 桌面未就绪，跳过 S3（这样测不出「带活动桌面的恢复」）"
		exit 0
	fi
	log "     3 秒后执行 systemctl suspend（请按电源键/键盘唤醒）"
	sleep 3
	systemctl suspend 2>>"$LOG"
	# 机器在此冻结，唤醒后本脚本从这里继续
	sleep 5
	log "==== [S3] 唤醒后状态: srcversion=$(cat /sys/module/jmgpu/srcversion 2>/dev/null) $(nodes) ===="
	log "     唤醒后 dmesg（尾 30 行）:"
	dmesg -T 2>/dev/null | tail -30 | sed 's/^/      /' >>"$LOG"
	log "     内核告警/错误汇总（唤醒后）:"
	kwarn >>"$LOG"
	wait_lightdm 30 || log "!! 唤醒后 lightdm 未就绪，见下方现场"
	systemctl is-active --quiet lightdm || dump_display_failure
	log "     [S3] lightdm=$(systemctl is-active lightdm)"
fi

log "==== 全部结束。日志: $LOG ===="
