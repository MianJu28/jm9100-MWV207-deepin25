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
#   sudo ./scripts/switch_stack.sh status           # 查看当前状态与差异（只读）
#   sudo ./scripts/switch_stack.sh vendor [--persist]
#                                                   # 切到厂商栈；--persist 一并做开机持久化
#   sudo ./scripts/switch_stack.sh system           # 切回系统驱动（更新系统前用；含移除持久化）
#   sudo ./scripts/switch_stack.sh persist          # 只做厂商栈持久化（禁 mwv207 + 强制 jmgpu）
#   sudo ./scripts/switch_stack.sh backup           # 仅备份现有配置
#   sudo ./scripts/switch_stack.sh restore          # 从最近一次备份恢复
#
# 持久化的含义（**改开机路径！**）：
#   /etc/modprobe.d/zz-jmgpu-test-blacklist.conf  = blacklist mwv207
#   /etc/modules-load.d/jmgpu.conf                = jmgpu（systemd 早期强制加载）
#   之后 update-initramfs 把上述两项冻结进开机镜像
#   ⚠️ 一旦新驱动在该内核上跑不起来，开机既加载不到新驱动、又回不到原驱动 ⇒ **黑屏**
#   ⇒ 所以 `vendor` 默认**不做**持久化，只配置 + 装模块；确认驱动可用后再 `persist`。
#
# 安全约定（见 README §8.4）：
#   * 本脚本**不自动重启**，改完会提示你手动执行；
#   * 所有被修改的文件**先备份**到 $BAK（默认 /persistent/home/admin/jm9100-xdrv-backup）；
#   * 每次只改一个方向；失败会明确报出哪一步出错；
#   * `system` 会**同时**移除持久化与 DKMS 注册（否则会出现"jmgpu 没装 + mwv207 被禁" ⇒ 无驱动）；
#   * 紧急回退：`sudo ~/rollback-to-system.sh && sudo reboot`。
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

# 持久化（决定开机时哪个驱动抢到设备；**改这三项等于改开机路径**）
BLACKLIST=/etc/modprobe.d/zz-jmgpu-test-blacklist.conf
MODLOAD=/etc/modules-load.d/jmgpu.conf
IR_LOG=/tmp/jmgpu-initramfs.log

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
	grep -q '^WEBKIT_DISABLE_COMPOSITING_MODE' "$ENVF" 2>/dev/null \
		&& echo "    → 含 WebKit 兼容参数（厂商栈必需，否则 EasyTier 等 WebKit 应用 SIGSEGV）" \
		|| echo "    → 无 WebKit 兼容参数（系统栈正常，厂商栈会让 WebKit 应用崩溃）"

	printf "  DKMS mwv207: "
	dkms status 2>/dev/null | grep -q '^mwv207/' && echo "已注册（内核升级会触发重编）" || echo "未注册 ✓"
	printf "  jmgpu.ko   : "
	ls /lib/modules/*/updates/dkms/jmgpu.ko >/dev/null 2>&1 && echo "存在" || echo "已清理 ✓"

	printf "  blacklist mwv207: "
	[ -f "$BLACKLIST" ] && echo "已设置（开机 jmgpu 抢设备）" || echo "未设置（开机 mwv207 接管）"
	printf "  modules-load jmgpu: "
	[ -f "$MODLOAD" ] && echo "已设置" || echo "未设置"

	# 一致性检查：配置与持久化是否配套（不配套时重启会落到"半切"状态）
	local want=0 have=0
	[ -f "$XCONF" ] && want=1
	[ -f "$BLACKLIST" ] && have=1
	echo
	if [ "$want" = 1 ] && [ "$have" = 0 ]; then
		echo "  ⚠️ 不一致：X 已配厂商 DDX，但**未持久化** ⇒ 重启将由 mwv207 接管，"
		echo "     而 10-mwv207.conf 的 MatchDriver \"jmgpu\" 匹配不上 ⇒ X 不用厂商 DDX，"
		echo "     且 GLX 变量会指向厂商库 ⇒ 部分 GL 程序可能异常。"
		echo "     处理：确认驱动可用后执行  sudo $0 persist  再重启；或 sudo $0 system 回退。"
	elif [ "$want" = 0 ] && [ "$have" = 1 ]; then
		echo "  ⚠️ 不一致：已持久化禁 mwv207，但未配厂商 X 配置 ⇒ 开机将只有 jmgpu + 默认 X 驱动。"
		echo "     处理：sudo $0 vendor（补配置）或 sudo $0 system（一并撤销）。"
	else
		echo "  ✓ 配置与持久化一致（$([ "$want" = 1 ] && echo "厂商栈" || echo "系统栈")）"
	fi

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

# ------------------------------------------------- persist / unpersist
# 这两个动作**改开机路径**，只在明确要求时调用（`vendor --persist` 或 `persist`）。
# 教训：若"禁掉 mwv207"而"新驱动又跑不起来"，开机将既无新驱动也回不到原驱动 ⇒ 黑屏。
_rebuild_initramfs() {
	# deepin-anything 的 vfs_monitor 在本内核上会让 dracut 的 cp 段错误(139)，
	# 先临时卸掉可稳定生成（详见 README §8.5）。
	rmmod vfs_monitor 2>/dev/null && echo "    已临时卸载 vfs_monitor（避免 dracut 139）"
	if update-initramfs -u >"$IR_LOG" 2>&1; then
		echo "    initramfs 重建成功"
	else
		echo "    !! initramfs 重建失败（日志 $IR_LOG）"
		echo "       /boot 旧镜像未被覆盖，重启仍可用；可重跑一次"
		return 1
	fi
}

cmd_persist() {
	need_root persist
	say "写入厂商栈持久化（**改开机路径**）"
	echo "[1/3] blacklist mwv207"
	printf 'blacklist mwv207\n' > "$BLACKLIST" && sed 's/^/    /' "$BLACKLIST"
	echo "[2/3] modules-load jmgpu"
	printf 'jmgpu\n' > "$MODLOAD" && sed 's/^/    /' "$MODLOAD"
	echo "[3/3] 重建 initramfs（把上面两项冻结进开机镜像）"
	_rebuild_initramfs || true
	echo
	echo "    回退： sudo $0 system   （或紧急时 sudo ~/rollback-to-system.sh）"
}

cmd_unpersist() {
	say "移除厂商栈持久化（恢复 mwv207 可加载）"
	rm -f "$BLACKLIST" && echo "    已删 $BLACKLIST"
	rm -f "$MODLOAD" && echo "    已删 $MODLOAD"
	_rebuild_initramfs || true
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

	echo "[2/5] /etc/environment：加 GLX vendor 变量 + WebKit 兼容参数"
	# 注意：__GLX_VENDOR_LIBRARY_NAME 必须靠 pam_env 交付（pkexec 会清环境，见 README §3.5/§15）
	grep -q '__GLX_VENDOR_LIBRARY_NAME' "$ENVF" 2>/dev/null || \
		echo '__GLX_VENDOR_LIBRARY_NAME=mwv207' >> "$ENVF"
	grep -q '^vblank_mode' "$ENVF" 2>/dev/null || echo 'vblank_mode=0' >> "$ENVF"
	# WebKitGTK 在厂商 GL 上会 SIGSEGV（EasyTier 图标一闪而过、无窗口）⇒ 关掉其加速合成。
	# 实测：仅加 GLX 变量必崩（2/2）；加上本行后连跑两次均存活。详见 README §8.6。
	grep -q '^WEBKIT_DISABLE_COMPOSITING_MODE' "$ENVF" 2>/dev/null || \
		echo 'WEBKIT_DISABLE_COMPOSITING_MODE=1' >> "$ENVF"
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

	echo
	if [ "${PERSIST:-0}" = 1 ]; then
		echo "[6/6] 持久化（--persist 已指定）"
		cmd_persist
	else
		echo "[6/6] 持久化：**未做**（默认不碰开机路径）"
		cat <<EOF

    ⚠️ 当前是"半切换"状态：X 已配厂商 DDX，但开机仍由 mwv207 接管。
       若现在重启，MatchDriver "jmgpu" 匹配不上内核驱动 ⇒ 厂商 DDX 不会被使用，
       而 GLX 变量已指向厂商库 ⇒ 部分 GL 程序可能异常。
       ⇒ 请先确认驱动可用，再二选一：
            sudo $0 persist      # 写入持久化（禁 mwv207 + 强制 jmgpu + 重建 initramfs）
            sudo $0 system       # 或撤销本次配置，回到系统栈
EOF
	fi

	cat <<EOF

==> 厂商栈配置完成。**请手动重启**（不要在本脚本里自动重启）：
      sudo reboot            # 建议整机重启（模块+initramfs 变更）
    重启后自检：
      sudo $0 status
      glxinfo -B | grep renderer        # 期望 Jingjia JM9100
      glxgears                          # 期望上万 FPS
    若黑屏：TTY(Ctrl+Alt+F3) 执行  sudo ~/rollback-to-system.sh && sudo reboot
EOF
}

# ---------------------------------------------------------------- system
cmd_system() {
	need_root system
	ensure_bak
	say "切到【系统自带 mwv207】"
	cmd_backup

	echo
	echo "[1/6] 删除 X 配置（MatchDriver \"jmgpu\" 与系统驱动名不符，留着会导致 X 起不来）"
	rm -f "$XCONF" && echo "    已删除 $XCONF"

	echo "[2/6] /etc/environment 去掉厂商栈变量（含 WebKit 兼容参数）"
	sed -i '/__GLX_VENDOR_LIBRARY_NAME/d; /vblank_mode/d; /WEBKIT_DISABLE_COMPOSITING_MODE/d' "$ENVF"
	echo "    现在内容：$(cat "$ENVF" 2>/dev/null | tr '\n' ' ')(空即为正常)"

	echo "[3/6] 移除持久化（否则会出现「jmgpu 没装 + mwv207 被禁」⇒ 无驱动黑屏）"
	cmd_unpersist

	echo "[4/6] 移除 DKMS 注册（避免系统升级内核时触发重编并中断更新）"
	dkms remove mwv207/1.7.0.uos --all 2>&1 | sed 's/^/    /' || echo "    (原本未注册)"
	ls /lib/modules/*/updates/dkms/jmgpu.ko 2>/dev/null | sed 's/^/    残留模块: /' || echo "    模块文件已清理 ✓"

	echo "[5/6] 保留项（将来可切回，不影响系统更新）"
	echo "    - 厂商用户态库 / DDX / vblank 服务 / profile.d"
	echo "    - libdrm.so.2.4.0 两处链接"

	echo "[6/6] 完成"
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
# vendor 支持 --persist：一并写入持久化（默认不做，见文件头说明）
if [ "${1:-}" = vendor ]; then
	case "${2:-}" in
		--persist|-p|persist) PERSIST=1 ;;
	esac
fi

case "${1:-status}" in
	status)  cmd_status ;;
	vendor)  cmd_vendor ;;
	system)  cmd_system ;;
	persist) cmd_persist ;;
	backup)  cmd_backup ;;
	restore) cmd_restore ;;
	-h|--help|help)
		sed -n '2,40p' "$0" | sed 's/^# \{0,1\}//'
		;;
	*) die "未知参数：$1（可用：status|vendor|system|backup|restore）" ;;
esac
