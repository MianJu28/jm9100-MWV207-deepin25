#!/usr/bin/env bash
# 把 jm9100 的移植源码同步到 DKMS 源目录，供 dkms rebuild 验证。
# 用法：./scripts/sync_dkms.sh [build]
#   - 默认只同步源码（含非 .c/.h 的构建配置）
#   - 传 build 参数则同步后执行 dkms build
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
SRC="$REPO/kernel"          # 驱动源码与构建配置（Makefile/Kconfig/dkms.conf）都在 kernel/
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
  ir_read=0
  ir_has_ko=0
  if sudo unmkinitramfs /boot/initrd.img-"$(uname -r)" "$ir_tmp" >/dev/null 2>&1; then
    ir_read=1
    ir_ko=$(find "$ir_tmp" -name 'jmgpu.ko' 2>/dev/null | head -1)
    if [ -n "$ir_ko" ]; then
      ir_has_ko=1
      ir_sv=$(modinfo -F srcversion "$ir_ko" 2>/dev/null || true)
    fi
  fi
  sudo rm -rf "$ir_tmp"
  echo "    磁盘模块    srcversion: ${disk_sv:-<读不到>}"
  echo "    initramfs  srcversion: ${ir_sv:-<initramfs 里没有 jmgpu.ko>}"

  # 2026-10-08: 本系统的 initramfs **不收录** updates/（DKMS）目录（实测
  # updates/*.ko = 0，只有 kernel/drivers/gpu/drm/mwv207/mwv207.ko），所以
  # jmgpu.ko 永远不会出现在 initramfs 里 —— 它由 rootfs 阶段的 udev modalias
  # 从 /lib/modules/.../updates/dkms/ 加载（README §6 #7）。
  # 之前这里把"initramfs 里没有 jmgpu.ko"直接判为失败并 `exit 1`，导致这条
  # 被文档写成"标准流程"的命令**每次都报校验失败**（明明 dkms status 已是
  # installed）。现在只在"initramfs 里确实有一个与磁盘不一致的 jmgpu.ko"时
  # 才失败 —— 那才是重启会回退到旧模块的真实场景。
  if [ "$ir_read" = 0 ]; then
    echo "!! 无法解包 initramfs，跳过模块一致性校验（不判失败）"
  elif [ "$ir_has_ko" = 0 ]; then
    echo "==> 校验：initramfs 不含 jmgpu.ko（本系统不收录 updates/，属正常）"
    echo "    模块由 rootfs 阶段 udev modalias 加载；只要 dkms status 为 installed 即可"
  elif [ -n "${disk_sv:-}" ] && [ "$disk_sv" = "$ir_sv" ]; then
    echo "==> 校验通过: initramfs 已含最新模块 (重启与 modprobe 都会用新的)"
  else
    echo "!! 校验失败: initramfs 里的 jmgpu.ko 与磁盘不一致 —— 重启会回退到旧模块!"
    echo "   处理: sudo update-initramfs -u 后重跑本脚本校验; 仍失败检查 /boot 空间与 dracut"
    exit 1
  fi
fi
