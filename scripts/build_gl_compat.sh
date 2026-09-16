#!/usr/bin/env bash
#
# build_gl_compat.sh -- 编译/安装 JM9100 用户态 GL 兼容层（tools/jm_gl_compat.c）
#
# 兼容层做两件事（详见 tools/jm_gl_compat.c 头部注释与 README §3.6）：
#   1. 把 GL_EXT_EGL_image_storage 加入扩展列表；
#   2. 把驱动“存在但不真正挂接 dmabuf”的 glEGLImageTargetTexStorageEXT（以及
#      glEGLImageTargetTextureStorageEXT）转发到驱动真正可用的
#      glEGLImageTargetTexture2DOES（GL_OES_EGL_image）。
#
# 结果：不必再给每个应用打补丁（如 patches/mpv_dmabuf_oes_image.patch），系统原版
#       mpv / 其它走 storage 路径的客户端即可进入 VA-API dmabuf 零拷贝直通。
#
# 生效方式：LD_PRELOAD。**不替换、不覆盖任何厂商库**，因此可随时停用。
#
# 用法：
#   ./scripts/build_gl_compat.sh               # 只编译到 build-cli/libjm_gl_compat.so
#   ./scripts/build_gl_compat.sh install       # 编译 + 安装到 /usr/lib/aarch64-linux-gnu/
#   ./scripts/build_gl_compat.sh uninstall     # 卸载系统副本
#
# 安装后按需使用（任选其一）：
#   a) 单应用：LD_PRELOAD=/usr/lib/aarch64-linux-gnu/libjm_gl_compat.so mpv ...
#   b) 全局：  echo /usr/lib/aarch64-linux-gnu/libjm_gl_compat.so | sudo tee -a /etc/ld.so.preload
#      （**高风险**：会作用于所有进程，包括 Xorg/合成器；除非明确知道后果，否则用 a）
#
# 紧急关闭（无需卸载）：环境变量 JMGPU_GL_COMPAT=0
#
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
cd "$REPO"
SRC="$REPO/tools/jm_gl_compat.c"
OUT_DIR="$REPO/build-cli"
SO_NAME=libjm_gl_compat.so
SYS_DIR=/usr/lib/aarch64-linux-gnu

say() { printf '%s\n' "$*"; }
warn() { printf '\033[33m%s\033[0m\n' "$*" >&2; }
die() { printf '\033[31m%s\033[0m\n' "$*" >&2; exit 1; }

build() {
	[ -f "$SRC" ] || die "找不到 $SRC（仓库应含 tools/jm_gl_compat.c）"
	mkdir -p "$OUT_DIR"
	say "编译 $SO_NAME ..."
	# -D_GNU_SOURCE 已在源码内定义；-ldl/-lpthread 视 glibc 版本可能冗余，无害
	gcc -O2 -Wall -Wextra -fPIC -shared \
		-o "$OUT_DIR/$SO_NAME" "$SRC" -ldl -lpthread
	say "产物: $OUT_DIR/$SO_NAME"
	# 快速自检：确认符号真的齐（LD_PRELOAD 靠符号插入，缺一个就白搭）
	local missing=0
	for sym in glGetString glGetStringi glGetIntegerv \
		glEGLImageTargetTexStorageEXT glEGLImageTargetTextureStorageEXT \
		glXGetProcAddressARB glXGetProcAddress eglGetProcAddress; do
		if ! nm -D --defined-only "$OUT_DIR/$SO_NAME" | grep -q " T $sym$"; then
			warn "  缺少导出符号: $sym"
			missing=1
		fi
	done
	[ "$missing" = 0 ] && say "符号自检通过（8/8）"
}

install_shim() {
	build
	say "安装到 $SYS_DIR/$SO_NAME ..."
	sudo install -m 644 "$OUT_DIR/$SO_NAME" "$SYS_DIR/$SO_NAME"
	say "完成。示例："
	say "  LD_PRELOAD=$SYS_DIR/$SO_NAME LIBVA_DRIVER_NAME=jmgpu mpv --vo=gpu --hwdec=vaapi 视频.mp4"
}

uninstall_shim() {
	if [ -e "$SYS_DIR/$SO_NAME" ]; then
		sudo rm -f "$SYS_DIR/$SO_NAME"
		say "已卸载 $SYS_DIR/$SO_NAME"
	else
		say "$SYS_DIR/$SO_NAME 不存在，无需卸载"
	fi
	warn "如曾写入 /etc/ld.so.preload，请手动删除对应行并执行: sudo ldconfig"
}

case "${1:-build}" in
build) build ;;
install) install_shim ;;
uninstall) uninstall_shim ;;
*) die "用法: $0 [build|install|uninstall]" ;;
esac
