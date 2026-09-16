#!/usr/bin/env bash
# 安装 / 回退「原生 GL_EXT_EGL_image_storage 支持」补丁（见 README §9）。
#
#   ./scripts/install_gl_storage.sh          生成补丁并安装（首次自动备份原件）
#   ./scripts/install_gl_storage.sh revert   从备份还原厂商原件
#   ./scripts/install_gl_storage.sh status   查看当前三库是否已打补丁
#
# 涉及厂商文件：
#   /usr/lib/aarch64-linux-gnu/dri/jmgpu_dri.so               扩展广告
#   /usr/lib/aarch64-linux-gnu/mwv207/libGLX_mwv207.so.1.2.0  GLX 入口别名
#   /usr/lib/aarch64-linux-gnu/mwv207/libEGL_mwv207.so.1.5.0  EGL 入口别名
#
# 备份目录：/var/backups/jm9100-glstorage/
# 注意：替换后**已运行**的进程仍用旧 inode，需重启应用（Xorg/合成器建议注销重登）。
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
OUT="$REPO/build-cli"       # 生成物目录在仓库根
BAK=/var/backups/jm9100-glstorage

DRI_ORIG=/usr/lib/aarch64-linux-gnu/dri/jmgpu_dri.so
DRI_ALT=/usr/lib/dri/jmgpu_dri.so
GLX=/usr/lib/aarch64-linux-gnu/mwv207/libGLX_mwv207.so.1.2.0
EGL=/usr/lib/aarch64-linux-gnu/mwv207/libEGL_mwv207.so.1.5.0

DRI_BAK="$BAK/$(basename "$DRI_ORIG").orig"
GLX_BAK="$BAK/$(basename "$GLX").orig"
EGL_BAK="$BAK/$(basename "$EGL").orig"

DRI_OUT="$OUT/jmgpu_dri.so.glstorage"
GLX_OUT="$OUT/libGLX_mwv207.so.1.2.0.glstorage"
EGL_OUT="$OUT/libEGL_mwv207.so.1.5.0.glstorage"

md5() { md5sum "$1" 2>/dev/null | cut -d' ' -f1; }

need_root() {
  [ "$(id -u)" = 0 ] || { echo "需要 root（用 sudo 运行）" >&2; exit 1; }
}

do_status() {
  echo "备份目录: $BAK"
  for f in "$DRI_ORIG" "$GLX" "$EGL"; do
    [ -e "$f" ] || { printf '%-52s 不存在\n' "$f"; continue; }
    b="$BAK/$(basename "$f").orig"
    cur=$(md5 "$f"); org=$([ -e "$b" ] && md5 "$b" || echo "-")
    if [ "$cur" = "$org" ]; then
      printf '%-52s 原厂\n' "$(basename "$f")"
    else
      printf '%-52s 已打补丁 (md5 %s, 原件 %s)\n' "$(basename "$f")" "$cur" "$org"
    fi
  done
}

do_revert() {
  need_root
  for pair in "$DRI_BAK:$DRI_ORIG" "$GLX_BAK:$GLX" "$EGL_BAK:$EGL"; do
    b="${pair%%:*}"; d="${pair##*:}"
    [ -e "$b" ] || { echo "跳过（无备份）: $b"; continue; }
    cp -f "$b" "$d"
    echo "已还原 $(basename "$d")"
  done
  # /usr/lib/dri 若是独立副本也一并还原
  if [ -e "$DRI_ALT" ] && [ "$(stat -c %i "$DRI_ALT")" != "$(stat -c %i "$DRI_ORIG")" ]; then
    cp -f "$DRI_BAK" "$DRI_ALT"
    echo "已还原 $(basename "$DRI_ALT")"
  fi
  echo "== 回退完成，重启应用/会话后生效 =="
  do_status
}

do_install() {
  need_root
  mkdir -p "$BAK"

  # 首次安装：备份原件
  [ -e "$DRI_BAK" ] || cp -a "$DRI_ORIG" "$DRI_BAK"
  [ -e "$GLX_BAK" ] || cp -a "$GLX" "$GLX_BAK"
  [ -e "$EGL_BAK" ] || cp -a "$EGL" "$EGL_BAK"
  echo "原件备份于 $BAK"

  # 始终**从原件**生成补丁（保证可重复、幂等）
  echo "==> 生成补丁"
  python3 "$REPO/tools/patch_gl_storage.py" \
      --dri "$DRI_BAK" --glx "$GLX_BAK" --egl "$EGL_BAK" --outdir "$OUT"

  echo "==> 安装"
  cp -f "$DRI_OUT" "$DRI_ORIG"
  cp -f "$GLX_OUT" "$GLX"
  cp -f "$EGL_OUT" "$EGL"
  if [ -e "$DRI_ALT" ] && [ "$(stat -c %i "$DRI_ALT")" != "$(stat -c %i "$DRI_ORIG")" ]; then
    cp -f "$DRI_OUT" "$DRI_ALT"
    echo "    同步 $DRI_ALT"
  fi

  echo "== 安装完成，重启应用（建议注销重登）后生效 =="
  do_status
}

case "${1:-install}" in
  install) do_install ;;
  revert)  do_revert ;;
  status)  do_status ;;
  *) echo "用法: $0 [install|revert|status]" >&2; exit 2 ;;
esac
