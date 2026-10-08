#!/bin/bash
# fix_easytier_glxguard.sh —— 用 glxguard 修 EasyTier（厂商 EGL 遗留悬垂 libglapi TLS）
#
# 背景（完整取证见 README §8.6.1）：
#   厂商 EGL 在解绑/销毁上下文后不清其内嵌 libglapi 的 TLS current context，
#   留下悬垂指针；随后厂商 GLX 的 glXDestroyContext → dri3DestroyContext
#   → jmgpu_dri.so:jmDestroyContext 直接解引用 ⇒ WebKitGTK 应用（EasyTier）启动即崩。
#
# 为什么用包装脚本而不是写 /etc/environment 的 LD_PRELOAD：
#   EasyTier 会经 pkexec 提权再启动一次（root 实例），而 **pkexec 会清环境**，
#   且 setuid/提权进程由 ld.so 忽略 LD_PRELOAD。包装脚本自身以普通方式 exec
#   非 setuid 目标，可自行注入 LD_PRELOAD ⇒ 提权实例也能带上守卫。
#   （与 ~/fix_dock_mesa.sh 的 dde-shell 包装是同一套路）
#
# 用法：
#   sudo bash tools/fix_easytier_glxguard.sh apply     # 安装（编译守卫 + 包装）
#   sudo bash tools/fix_easytier_glxguard.sh revert    # 回退（还原原二进制）
#   sudo bash tools/fix_easytier_glxguard.sh status    # 查看状态
#
# 验证：无 WEBKIT_DISABLE_COMPOSITING_MODE 时启动 EasyTier 应不再段错误；
#       诊断：JMGLXGUARD_VERBOSE=1（journal/dmesg 可见 [glxguard] 行）
set -u

REPO="$(cd "$(dirname "$0")/.." && pwd)"
GUARD_SRC="$REPO/tools/glxguard.c"
GUARD_SO=/usr/local/lib/glxguard.so
TARGET=/usr/bin/easytier-gui
REAL=/usr/bin/easytier-gui.real

usage() {
	echo "用法: $0 {apply|revert|status}"
	exit 1
}

build_guard() {
	mkdir -p /usr/local/lib
	if [ ! -f "$GUARD_SO" ] || [ "$GUARD_SRC" -nt "$GUARD_SO" ]; then
		echo "编译守卫 → $GUARD_SO"
		gcc -shared -fPIC -O2 -o "$GUARD_SO" "$GUARD_SRC" -ldl || {
			echo "编译失败"; exit 1; }
	fi
	echo "守卫: $(ls -l "$GUARD_SO")"
}

is_wrapped() {
	[ -f "$TARGET" ] && head -1 "$TARGET" 2>/dev/null | grep -q '^#!' && \
		grep -q 'glxguard' "$TARGET" 2>/dev/null
}

do_apply() {
	build_guard

	if ! is_wrapped; then
		if [ ! -f "$REAL" ]; then
			echo "备份原二进制: $TARGET → $REAL"
			cp -a "$TARGET" "$REAL"
		else
			echo "已存在 $REAL，跳过备份"
		fi
	else
		echo "已包装，刷新包装脚本"
	fi

	cat > "$TARGET" <<'EOF'
#!/bin/sh
# glxguard 包装（README §8.6.2）：修厂商 EGL 遗留悬垂 libglapi TLS 引起的段错误
GUARD=/usr/local/lib/glxguard.so
if [ -e "$GUARD" ]; then
	case ":${LD_PRELOAD:-}:" in
		*":$GUARD:"*) ;;
		*) LD_PRELOAD="$GUARD${LD_PRELOAD:+:$LD_PRELOAD}" ;;
	esac
	export LD_PRELOAD
fi
exec /usr/bin/easytier-gui.real "$@"
EOF
	chmod 755 "$TARGET"
	echo "已写入包装: $TARGET"
	ls -la "$TARGET" "$REAL"
}

do_revert() {
	if [ -f "$REAL" ]; then
		cp -a "$REAL" "$TARGET"
		echo "已还原 $REAL → $TARGET"
		ls -la "$TARGET"
	else
		echo "找不到 $REAL（可能本来就未包装）"
	fi
}

do_status() {
	echo "守卫库: $([ -f "$GUARD_SO" ] && echo "$GUARD_SO ✓" || echo "未编译")"
	if is_wrapped; then
		echo "$TARGET: 已包装（走 glxguard）"
	else
		echo "$TARGET: 未包装（原始二进制）"
	fi
	echo "$REAL: $([ -f "$REAL" ] && echo 存在 || echo 不存在)"
	grep -q '^WEBKIT_DISABLE_COMPOSITING_MODE' /etc/environment 2>/dev/null \
		&& echo "⚠️ /etc/environment 仍含 WEBKIT_DISABLE_COMPOSITING_MODE（备用规避，可删以恢复 WebKit 加速合成）" \
		|| echo "/etc/environment 无 WEBKIT_DISABLE_COMPOSITING_MODE（WebKit 加速合成未被禁用）"
}

case "${1:-}" in
	apply)  do_apply ;;
	revert) do_revert ;;
	status) do_status ;;
	*) usage ;;
esac
