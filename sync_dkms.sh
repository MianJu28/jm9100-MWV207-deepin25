#!/usr/bin/env bash
# 把 jm9100 的移植源码同步到 DKMS 源目录，供 dkms rebuild 验证。
# 用法：./sync_dkms.sh [build]
#   - 默认只同步源码（含非 .c/.h 的构建配置）
#   - 传 build 参数则同步后执行 dkms build
set -euo pipefail

SRC="$(cd "$(dirname "$0")" && pwd)"
DST="/usr/src/mwv207-1.7.0.uos"

if [ ! -d "$DST" ]; then
  echo "错误：DKMS 源目录不存在：$DST" >&2
  exit 1
fi

echo "==> 同步 $SRC -> $DST"
# 只覆盖源文件与构建配置，避免误删 DKMS 侧无关文件；产物清理由 dkms 处理
cp -f "$SRC"/*.c "$SRC"/*.h "$SRC"/Makefile* "$SRC"/dkms.conf "$SRC"/Kconfig* 2>/dev/null "$DST"/

# 删除目标里可能残留的旧编译产物，确保 dkms 干净重建
find "$DST" -maxdepth 1 -name '*.o' -delete 2>/dev/null || true
find "$DST" -maxdepth 1 -name '*.ko' -delete 2>/dev/null || true

echo "==> 已同步 $(ls "$SRC"/*.c 2>/dev/null | wc -l) 个 .c / $(ls "$SRC"/*.h 2>/dev/null | wc -l) 个 .h"

if [ "${1:-}" = "build" ]; then
  echo "==> dkms build mwv207/1.7.0.uos"
  sudo dkms build mwv207/1.7.0.uos --force
  echo "==> dkms build 完成"
  sudo dkms install mwv207/1.7.0.uos --force
  echo "==> dkms install 完成"
  # 关键: modules-load 早期加载走 initramfs 冻结副本, 不重建 initramfs
  # 的话新模块在重启后不会生效 (教训见 FIXLOG.md 修复 6)
  sudo update-initramfs -u
  echo "==> update-initramfs 完成 (新模块重启后生效)"
fi
