#!/bin/bash
# deploy_ddx_tearfree_sync.sh —— 部署/回退「DDX TearFree 同步」补丁（治三角/楔形错位）
#
# 背景（README §3.2 #10 / §6 #1）：
#   厂商 DDX 的"合成 → 扫描缓冲"拷贝路径经 drm_jmgpu_bo_xfer_to_dev() 提交 2D 作业后
#   **立即返回**，不等 2D 引擎排空 ⇒ 显示可能先扫到未写完的缓冲 ⇒ 三角/楔形错位。
#   本补丁把两处函数尾声的 `ldp x29,x30,[sp,#16]` 换成 `bl <现成但从未被调用的
#   等 2D 空闲封装 @0x10d78>`（共 8 字节），使"上传完成前不返回"。
#
# 用法：
#   sudo bash tools/deploy_ddx_tearfree_sync.sh build     # 生成"ABI25+同步"合一版（免 root）
#   sudo bash tools/deploy_ddx_tearfree_sync.sh apply     # 安装（自动备份）并重启 lightdm
#   sudo bash tools/deploy_ddx_tearfree_sync.sh apply-nox # 只安装，不重启（下次登录生效）
#   sudo bash tools/deploy_ddx_tearfree_sync.sh revert    # 回退到最近备份并重启 lightdm
#   sudo bash tools/deploy_ddx_tearfree_sync.sh status    # 查看当前是哪一版
#
# ⚠️ 风险与回退
#   * 若不慎装错导致 X 起不来：在 TTY(Ctrl+Alt+F3) 或 SSH 执行 `revert` 即可；
#   * 本补丁只改 8 字节、且 `bl` 到的函数是模块自带，不改 ABI ⇒ X 仍能加载；
#   * 副作用：每次"合成→扫描"多一次 2D 排空等待 ⇒ 呈现延迟略增（换正确性）。
set -u

REPO="$(cd "$(dirname "$0")/.." && pwd)"
DDX=/usr/lib/xorg/modules/drivers/mwv207_drv.so
OUT="$REPO/build-cli/mwv207_drv.so.abi25+tearfree-sync"
EXPECT_OUT=4c0f96b64c06f4273ef333a27d93c2e3e5a3e29a5f4655ec3ec7b44f93132201

usage() {
	echo "用法: $0 {build|apply|apply-nox|revert|status}"
	exit 1
}

# ---------------------------------------------------------------------------
# 2026-10-08：本补丁已废弃，全部动作硬拦截。
#
# 该补丁把 DDX 里 0x12CB0 / 0x131FC 的
#     ldp x29, x30, [sp, #16]      ← 该函数唯一恢复调用者 LR 的指令
# 替换成 `bl 0x10D78`，而函数尾部是 `ret`（用 x30）。
# 替换后 x30 被 bl 改成 0x12CB4/0x13200，且其后到 ret 之间没有任何指令
# 恢复 x29/x30 ⇒ 返回地址错乱（跳回 0x12CB4 形成循环）。
# 实测后果：TearFree 的「合成→扫描缓冲」上传路径每帧都走这里，
# 图形栈行为不可预测，表现为**直通与软解都出现**画面斜向错位。
#
# 2D 排空等待已由内核侧负责（DRM_JM_GEM_XFER_RECT →
# j9_handle_j9ma_arecaceous() 的 xfer_waits_2d_idle，默认 30ms），
# 因此本补丁在功能上也是多余的。
#
# 正确做法：用 build-cli/mwv207_drv.so.abi25.fixed3
#           （md5 297aee83b5db3a3bccf33ff7ac2698fc）。
# 本脚本保留仅为 revert/status 的历史记录用途。
# ---------------------------------------------------------------------------
echo "!! tools/deploy_ddx_tearfree_sync.sh 已废弃，拒绝执行（含 build/apply）。"
echo
echo "   原因：该补丁覆盖了 DDX 函数唯一的 ldp x29,x30,[sp,#16]，"
echo "         导致 2D 上传例程 ret 返回到错误地址 —— 实测造成"
echo "         硬件直通与软件解码都出现画面斜向错位。"
echo
echo "   当前应使用：build-cli/mwv207_drv.so.abi25.fixed3"
echo "               (md5 297aee83b5db3a3bccf33ff7ac2698fc)"
echo
echo "   若 DDX 当前已是打补丁版本，回退："
echo "     sudo cp -f $REPO/build-cli/mwv207_drv.so.abi25.fixed3 $DDX"
echo "     sudo systemctl restart lightdm"
exit 9

do_build() {
	cd "$REPO"
	python3 tools/patch_ddx_tearfree_sync.py "$DDX" "$OUT" || exit 1
	echo
	echo "产物: $OUT"
	sha256sum "$OUT"
	echo "（期望 sha256 = $EXPECT_OUT）"
	[ "$(sha256sum "$OUT" | cut -d' ' -f1)" = "$EXPECT_OUT" ] \
		&& echo "指纹一致 ✓" || echo "!! 指纹与预期不一致，请勿部署"
}

do_apply() {
	local restart="$1"
	[ -f "$OUT" ] || { echo "请先 build"; exit 1; }
	[ "$(sha256sum "$OUT" | cut -d' ' -f1)" = "$EXPECT_OUT" ] || {
		echo "!! 产物指纹不符，拒绝部署"; exit 1; }

	if [ "$(sha256sum "$DDX" | cut -d' ' -f1)" = "$EXPECT_OUT" ]; then
		echo "已是补丁版，无需重复部署"
	else
		local bak="/root/mwv207_drv.so.pre-sync-$(date +%Y%m%d-%H%M%S)"
		cp -a "$DDX" "$bak" && echo "已备份 → $bak"
		cp "$OUT" "$DDX" && chmod 644 "$DDX" && echo "已安装补丁版 → $DDX"
	fi
	sha256sum "$DDX"

	if [ "$restart" = yes ]; then
		echo "重启 lightdm（会注销当前会话，请重新登录）..."
		systemctl restart lightdm
	fi
}

do_revert() {
	local bak
	bak=$(ls -1t /root/mwv207_drv.so.pre-sync-* 2>/dev/null | head -1)
	[ -n "$bak" ] || { echo "找不到备份 /root/mwv207_drv.so.pre-sync-*"; exit 1; }
	cp -a "$bak" "$DDX" && echo "已从 $bak 回退"
	sha256sum "$DDX"
	systemctl restart lightdm
}

do_status() {
	echo "当前 DDX: $DDX"
	sha256sum "$DDX"
	case "$(sha256sum "$DDX" | cut -d' ' -f1)" in
		"$EXPECT_OUT") echo "  → 已打 TearFree 同步补丁（合 ABI25）";;
		70d02b433d94d15ca86fa7c06ba8a2e963fd7a52c46d4709bcf96ee61830735d)
			echo "  → 原版（仅 ABI25 修复，未打同步补丁）";;
		c58afa9ea948f2a2b0a8993f3b0b33abcc1bc1e45e0664fdd2331599826e6621)
			echo "  → 未改动的原件";;
		*) echo "  → 未知版本";;
	esac
	objdump -d --start-address=0x12cb0 --stop-address=0x12cb4 "$DDX" 2>/dev/null | sed -n '7,8p'
}

case "${1:-}" in
	build)     do_build ;;
	apply)     do_apply yes ;;
	apply-nox) do_apply no ;;
	revert)    do_revert ;;
	status)    do_status ;;
	*) usage ;;
esac
