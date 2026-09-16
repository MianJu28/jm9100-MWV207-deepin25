#!/usr/bin/env bash
# JM9100 灰滤镜即时修复: 把 crtc0 的 WIN_CONTRAST(0x990038) 低 8 位写回线性值 0xF0
# 根因: X 专有驱动 mwv207_drv.so 直接写 MMIO 将其改为 0x4E(对比度 78/255)，
#       绕过内核 DRM, 造成整屏"蒙灰滤镜"。
# 用法: sudo ./scripts/fix_win_contrast.sh            # 恢复 crtc0
#       sudo ./scripts/fix_win_contrast.sh <val>      # 写自定义值(16 进制, 如 f0)
set -euo pipefail
DEV=""
for d in /sys/bus/pci/devices/*/resource1; do
  dir=$(dirname "$d")
  [ "$(cat "$dir/vendor")" = "0x0731" ] && [ "$(cat "$dir/device")" = "0x9100" ] && { DEV="$d"; break; }
done
[ -n "$DEV" ] || { echo "JM9100 not found" >&2; exit 1; }
VAL="${1:-f0}"

python3 - "$DEV" "$VAL" <<'EOF'
import sys, os, mmap
dev, val = sys.argv[1], int(sys.argv[2], 16)
f = open(dev, "r+b", buffering=0)
mm = mmap.mmap(f.fileno(), os.fstat(f.fileno()).st_size)
OFF = 0x990038
old = int.from_bytes(mm[OFF:OFF+4], "little")
new = (old & 0xFFFFFF00) | val
mm[OFF:OFF+4] = new.to_bytes(4, "little")
newrb = int.from_bytes(mm[OFF:OFF+4], "little")
print(f"WIN_CONTRAST @0x990038: {old:#010x} -> {new:#010x} (readback {newrb:#010x})")
mm.close(); f.close()
EOF
