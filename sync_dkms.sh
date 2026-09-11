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

  # 关键: 开机早期 modules-load 加载的是 initramfs 里冻结的模块副本, 不重建
  # initramfs 就会在重启后悄悄回退到旧模块 (教训见 README.md §4.2)。
  # 而 dracut 在本机会偶发 SIGSEGV(139), 漏拷文件却仍返回 0 —— 所以这里
  # 不仅要重建, 还要**校验 initramfs 里确实是刚安装的那个模块**, 不能
  # 无条件打印"完成"。
  IR_LOG=$(mktemp)
  for attempt in 1 2; do
    sudo update-initramfs -u >"$IR_LOG" 2>&1 || true
    if ! grep -qE "failed with 139|Segmentation fault" "$IR_LOG"; then
      break
    fi
    echo "==> update-initramfs 出现 dracut 139 段错误, 重试 (第 $attempt 次)"
  done
  if grep -qE "failed with 139|Segmentation fault" "$IR_LOG"; then
    echo "!! 警告: initramfs 生成仍有段错误, 可能漏拷了无关模块(本机用不到的几个),"
    echo "          jmgpu 是否成功以下方校验为准"
  fi
  rm -f "$IR_LOG"

  DISK_KO="/lib/modules/$(uname -r)/updates/dkms/jmgpu.ko"
  disk_sv=$(modinfo -F srcversion "$DISK_KO" 2>/dev/null || true)
  ir_tmp=$(mktemp -d)
  ir_sv=""
  if sudo unmkinitramfs /boot/initrd.img-"$(uname -r)" "$ir_tmp" >/dev/null 2>&1; then
    ir_sv=$(find "$ir_tmp" -name 'jmgpu.ko' -exec modinfo -F srcversion {} \; 2>/dev/null | head -1)
  fi
  sudo rm -rf "$ir_tmp"
  echo "    磁盘模块    srcversion: ${disk_sv:-<读不到>}"
  echo "    initramfs  srcversion: ${ir_sv:-<initramfs 里没有 jmgpu.ko>}"
  if [ -n "${disk_sv:-}" ] && [ "$disk_sv" = "${ir_sv:-}" ]; then
    echo "==> 校验通过: initramfs 已含最新模块 (重启与 modprobe 都会用新的)"
  else
    echo "!! 校验失败: initramfs 里的 jmgpu.ko 与磁盘不一致 —— 重启会回退到旧模块!"
    echo "   处理: sudo update-initramfs -u 后重跑本脚本校验; 仍失败检查 /boot 空间与 dracut"
    exit 1
  fi
fi
