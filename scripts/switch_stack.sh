#!/bin/bash
#
# switch_stack.sh —— 在「厂商栈(jmgpu)」与「系统自带驱动(mwv207)」之间切换
#
# 背景：本机 JM9100 (0731:9100) 有两套可用驱动栈：
#   A) 厂商栈：本仓库构建的 jmgpu 内核模块 + 厂商闭源用户态（DDX/GL/EGL/VAAPI）
#      —— GL 硬件加速、VA-API 硬解可用（README §8/§14）
#   B) 系统自带：发行版 in-tree mwv207（带 ttm/gpu_sched）+ Mesa
#      —— 系统升级、日常稳妥使用
#
# 两者对以下**共享资源**的期望相反，所以切换时必须成套修改，否则会出问题：
#   /etc/environment            GLX vendor 变量、vblank_mode
#   /usr/share/X11/xorg.conf.d/10-mwv207.conf   X 是否用厂商 DDX
#   DKMS mwv207 注册            升级内核时是否触发重编（未移除会中断系统更新）
#
# 用法：
#   sudo ./scripts/switch_stack.sh status        # 查看当前状态与差异（只读）
#   sudo ./scripts/switch_stack.sh vendor        # 切到厂商栈（需重启）
#   sudo ./scripts/switch_stack.sh system        # 切回系统驱动（更新系统前用；需重启）
#   sudo ./scripts/switch_stack.sh backup        # 仅备份现有配置
#   sudo ./scripts/switch_stack.sh restore       # 从最近一次备份恢复
#
# 安全约定（见 README §13.4）：
#   * 本脚本**不自动重启**，改完会提示你手动执行；
#   * 所有被修改的文件**先备份**到 $BAK（默认 /persistent/home/admin/jm9100-xdrv-backup）；
#   * 每次只改一个方向；失败会明确报出哪一步出错；
#   * `system` 模式会移除 DKMS 注册（避免内核升级被中断），但**保留**厂商用户态库。
#
set -u

REPO="$(cd "$(dirname "$0")/.." && pwd)"
BAK="${JM9100_BAK:-/persistent/home/admin/jm9100-xdrv-backup}"
STAMP="$(date +%F-%H%M%S)"

XCONF=/usr/share/X11/xorg.conf.d/10-mwv207.conf
ENVF=/etc/environment
VBLANK_SVC=/etc/systemd/system/drm-vblank-fix.service
VBLANK_TMP=/etc/tmpfiles.d/drm-vblank.conf
PROF_GLX=/etc/profile.d/mwv207_glvnd.sh

DRM_LINK_SYS=/usr/lib/aarch64-linux-gnu/libdrm.so.2.4.0
DRM_LINK_MWV=/usr/lib/aarch64-linux-gnu/mwv207/libdrm.so.2.4.0
DDX=/usr/lib/xorg/modules/drivers/mwv207_drv.so

die() { echo "!! $*" >&2; exit 1; }
say() { echo "==> $*"; }

need_root() {
	[ "$(id -u)" = 0 ] || die "请用 sudo 运行：sudo $0 $*"
}

ensure_bak() { mkdir -p "$BAK" || die "无法创建备份目录 $BAK"; }

backup_file() {   # backup_file <路径> —— 存在才备份
	local f="$1"
	[ -e "$f" ] || return 0
	cp -a "$f" "$BAK/$(basename "$f").$STAMP.bak" && echo "    备份 $f -> $BAK/$(basename "$f").$STAMP.bak"
}

# ---------------------------------------------------------------- status
cmd_status() {
	echo "=== 1) 内核驱动 ==="
	if lsmod | grep -q '^jmgpu'; then
		echo "  运行中: jmgpu（厂商栈）"
	elif lsmod | grep -q '^mwv207'; then
		echo "  运行中: mwv207（系统自带）"
	else
		echo "  运行中: (无显卡驱动)"
	fi
	printf "  PCI 绑定: "; readlink -f /sys/bus/pci/devices/0000:07:00.0/driver 2>/dev/null | xargs -r basename || echo "(无)"
	echo "  /dev/jmgpu: $([ -e /dev/jmgpu ] && echo 存在 || echo 不存在)"
	echo "  /dev/dri : $(ls /dev/dri 2>/dev/null | tr '\n' ' ')"

	echo
	echo "=== 2) 关键配置 ==="
	printf "  X 配置(%s): " "$XCONF"
	[ -f "$XCONF" ] && echo "存在（厂商 DDX）" || echo "不存在（走系统默认）"

	printf "  /etc/environment:\n"
	sed 's/^/    /' "$ENVF" 2>/dev/null || echo "    (空)"
	grep -q '__GLX_VENDOR_LIBRARY_NAME' "$ENVF" 2>/dev/null \
		&& echo "    → 含 GLX vendor 变量（厂商栈期望）" \
		|| echo "    → 无 GLX vendor 变量（系统栈期望）"

	printf "  DKMS mwv207: "
	dkms status 2>/dev/null | grep -q '^mwv207/' && echo "已注册（内核升级会触发重编）" || echo "未注册 ✓"
	printf "  jmgpu.ko   : "
	ls /lib/modules/*/updates/dkms/jmgpu.ko >/dev/null 2>&1 && echo "存在" || echo "已清理 ✓"

	echo
	echo "=== 3) vblank 辅助（厂商栈专用，系统栈可留可删） ==="
	[ -f "$VBLANK_SVC" ] && echo "  $VBLANK_SVC 存在" || echo "  未安装"
	[ -f "$VBLANK_TMP" ] && echo "  $VBLANK_TMP 存在" || echo "  未安装"
	sudo -n cat /sys/module/drm/parameters/vblankoffdelay 2>/dev/null \
		| sed 's/^/  vblankoffdelay = /' || true

	echo
	echo "=== 4) 厂商用户态 ==="
	dpkg -l 2>/dev/null | grep -q 'com.jingjiamicro.mwv207 ' \
		&& echo "  包 com.jingjiamicro.mwv207: 已安装" || echo "  包 com.jingjiamicro.mwv207: 未安装"
	printf "  DDX: %s\n" "$(md5sum $DDX 2>/dev/null | awk '{print $1}')"
	[ -e "$DRM_LINK_SYS" ] && echo "  libdrm.so.2.4.0 系统目录链接: 有" || echo "  libdrm.so.2.4.0 系统目录链接: 无"
	[ -e "$DRM_LINK_MWV" ] && echo "  libdrm.so.2.4.0 mwv207 目录链接: 有" || echo "  libdrm.so.2.4.0 mwv207 目录链接: 无"

	echo
	echo "=== 5) 当前 GL（会话 DISPLAY 自动探测） ==="
	local D
	D=$(tr '\0' '\n' < "/proc/$(pgrep -x kwin_x11 | head -1)/environ" 2>/dev/null | sed -n 's/^DISPLAY=//p')
	echo "  DISPLAY=${D:-未探测到}"
	[ -n "${D:-}" ] && DISPLAY="$D" XAUTHORITY="$HOME/.Xauthority" \
		glxinfo -B 2>/dev/null | grep -iE 'OpenGL renderer' | sed 's/^/  /'
}

# ---------------------------------------------------------------- backup
cmd_backup() {
	need_root backup
	ensure_bak
	say "备份到 $BAK（后缀 .$STAMP.bak）"
	for f in "$XCONF" "$ENVF" "$VBLANK_SVC" "$VBLANK_TMP" "$PROF_GLX" "$DDX"; do
		backup_file "$f"
	done
	echo "$STAMP" > "$BAK/.last-stamp"
	say "备份完成（时间戳 $STAMP）"
}

cmd_restore() {
	need_root restore
	ensure_bak
	local s
	s=$(cat "$BAK/.last-stamp" 2>/dev/null) || die "找不到备份时间戳（$BAK/.last-stamp），请先 backup"
	say "从备份 $s 恢复"
	local n=0
	for b in "$BAK"/*."$s".bak; do
		[ -e "$b" ] || continue
		local orig="${b%.$s.bak}"
		# 还原到原路径（去掉 .bak 后缀）
		case "$(basename "$orig")" in
			10-mwv207.conf)  cp -a "$b" "$XCONF" ;;
			environment)     cp -a "$b" "$ENVF" ;;
			drm-vblank-fix.service) cp -a "$b" "$VBLANK_SVC" ;;
			drm-vblank.conf) cp -a "$b" "$VBLANK_TMP" ;;
			mwv207_glvnd.sh) cp -a "$b" "$PROF_GLX" ;;
			mwv207_drv.so)   cp -a "$b" "$DDX" ;;
			*) echo "    跳过 $b（未知目标）"; continue ;;
		esac
		echo "    恢复 $orig"
		n=$((n + 1))
	done
	say "恢复 $n 个文件；请重启 X：sudo systemctl restart lightdm"
}

# ---------------------------------------------------------------- vendor
cmd_vendor() {
	need_root vendor
	ensure_bak
	say "切到【厂商栈 jmgpu】"
	cmd_backup

	echo
	echo "[1/5] X 配置：用厂商 DDX（MatchDriver \"jmgpu\"）"
	cat > "$XCONF" <<'EOF'
Section "OutputClass"
        Identifier "JMgpu"
        MatchDriver "jmgpu"
        Driver "mwv207"
EndSection
EOF
	echo "    已写入 $XCONF"

	echo "[2/5] /etc/environment：加 GLX vendor 变量"
	# 注意：__GLX_VENDOR_LIBRARY_NAME 必须靠 pam_env 交付（pkexec 会清环境，见 README §3.5/§15）
	grep -q '__GLX_VENDOR_LIBRARY_NAME' "$ENVF" 2>/dev/null || \
		echo '__GLX_VENDOR_LIBRARY_NAME=mwv207' >> "$ENVF"
	grep -q '^vblank_mode' "$ENVF" 2>/dev/null || echo 'vblank_mode=0' >> "$ENVF"
	sed 's/^/    /' "$ENVF"

	echo "[3/5] libdrm.so.2.4.0 兼容链接（两处都要，见 docs/系统还原后重建步骤.md §3）"
	ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 "$DRM_LINK_SYS"
	ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 "$DRM_LINK_MWV"
	ls -la "$DRM_LINK_SYS" "$DRM_LINK_MWV" | sed 's/^/    /'

	echo "[4/5] vblank 辅助服务（厂商驱动需要 drm.vblankoffdelay=0，见 README §8.9）"
	cat > "$VBLANK_TMP" <<'EOF'
w /sys/module/drm/parameters/vblankoffdelay - - - - 0
EOF
	cat > "$VBLANK_SVC" <<'EOF'
[Unit]
Description=Set drm.vblankoffdelay=0
After=systemd-modules-load.service
[Service]
Type=oneshot
ExecStart=/bin/sh -c 'echo 0 > /sys/module/drm/parameters/vblankoffdelay'
[Install]
WantedBy=multi-user.target
EOF
	systemctl daemon-reload
	systemctl enable drm-vblank-fix.service >/dev/null 2>&1
	echo "    已安装并 enable"

	echo "[5/5] DKMS：重建 mwv207 注册与模块"
	if [ -d /usr/src/mwv207-1.7.0.uos ]; then
		dkms status 2>/dev/null | grep -q '^mwv207/' || dkms add mwv207/1.7.0.uos >/dev/null 2>&1
		"$REPO/scripts/sync_dkms.sh" build || die "DKMS 构建失败，请查看输出"
	else
		echo "    !! /usr/src/mwv207-1.7.0.uos 不存在"
		echo "    !! 请先：cd $REPO/kernel && sudo cp -f *.c *.h Makefile* dkms.conf Kconfig* /usr/src/mwv207-1.7.0.uos/"
		echo "    !! 然后重跑：sudo $0 vendor"
		exit 1
	fi

	cat <<EOF

==> 厂商栈配置完成。**请手动重启**（不要在本脚本里自动重启）：
      sudo reboot            # 建议整机重启（模块+initramfs 变更）
    重启后自检：
      sudo $0 status
      glxinfo -B | grep renderer        # 期望 Jingjia JM9100
      glxgears                          # 期望上万 FPS
EOF
}

# ---------------------------------------------------------------- system
cmd_system() {
	need_root system
	ensure_bak
	say "切到【系统自带 mwv207】"
	cmd_backup

	echo
	echo "[1/5] 删除 X 配置（MatchDriver \"jmgpu\" 与系统驱动名不符，留着会导致 X 起不来）"
	rm -f "$XCONF" && echo "    已删除 $XCONF"

	echo "[2/5] /etc/environment 去掉厂商栈变量"
	sed -i '/__GLX_VENDOR_LIBRARY_NAME/d; /vblank_mode/d' "$ENVF"
	echo "    现在内容：$(cat "$ENVF" 2>/dev/null | tr '\n' ' ')(空即为正常)"

	echo "[3/5] 移除 DKMS 注册（避免系统升级内核时触发重编并中断更新）"
	dkms remove mwv207/1.7.0.uos --all 2>&1 | sed 's/^/    /' || echo "    (原本未注册)"
	ls /lib/modules/*/updates/dkms/jmgpu.ko 2>/dev/null | sed 's/^/    残留模块: /' || echo "    模块文件已清理 ✓"

	echo "[4/5] 保留项（方案 B：将来可切回，不影响系统更新）"
	echo "    - 厂商用户态库 / DDX / vblank 服务 / profile.d"
	echo "    - libdrm.so.2.4.0 两处链接"

	echo "[5/5] 完成"
	cat <<EOF

==> 系统栈配置完成。**请手动重启**（X 与内核模块都需要重新初始化）：
      sudo reboot
    重启后自检：
      sudo $0 status
      lsmod | grep -E '^jmgpu|^mwv207'   # 期望 mwv207
      glxinfo -B | grep renderer         # 期望 Mesa/llvmpipe（系统栈）

    提示：若将来要切回厂商栈，先确认 /usr/src/mwv207-1.7.0.uos 存在，再执行：
      sudo $0 vendor
EOF
}

# ---------------------------------------------------------------- main
case "${1:-status}" in
	status)  cmd_status ;;
	vendor)  cmd_vendor ;;
	system)  cmd_system ;;
	backup)  cmd_backup ;;
	restore) cmd_restore ;;
	-h|--help|help)
		sed -n '2,40p' "$0" | sed 's/^# \{0,1\}//'
		;;
	*) die "未知参数：$1（可用：status|vendor|system|backup|restore）" ;;
esac
