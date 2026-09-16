#!/usr/bin/env bash
# JM9100 显示域全量寄存器 dump (v2) —— 定位 X 专有驱动直接写 MMIO 的痕迹
# 范围:
#   VA/WIN  0x990000-0x9907FF (u32, crtc0+c1 全区: 后处理/窗口/时序/LUT)
#   TOP     0x9B0000-0x9B00FF (u32, VA/VO 单元全局配置)
#   HDMI TX 0x1200000-0x12011FF + 0x1204000-0x12041FF + 0x1205000-0x12050FF (u8)
# 用法: sudo ./scripts/dump_full_regs.sh -o /tmp/full_<stack>.txt
# 注意: 在显示管线 active(X 运行或 modetest 点亮)时执行.
set -euo pipefail
set -u

OUT=/dev/null
if [ "${1:-}" = "-o" ] && [ -n "${2:-}" ]; then OUT="$2"; fi

DEV=""
for d in /sys/bus/pci/devices/*/resource1; do
  [ -e "$d" ] || continue
  dir=$(dirname "$d")
  ven=$(cat "$dir/vendor"); dev=$(cat "$dir/device")
  if [ "$ven" = "0x0731" ] && [ "$dev" = "0x9100" ]; then DEV="$dir"; break; fi
done
[ -n "$DEV" ] || { echo "ERROR: JM9100 (0731:9100) not found" >&2; exit 1; }
[ "$(id -u)" = 0 ] || { echo "ERROR: run as root" >&2; exit 1; }

cat > /tmp/fullregdump.py <<'EOF'
import sys, os, mmap

res = open(sys.argv[1], "rb", buffering=0)
BAR_LEN = os.fstat(res.fileno()).st_size
mm = mmap.mmap(res.fileno(), BAR_LEN, mmap.MAP_SHARED, mmap.PROT_READ)

def r32(off):
    if off + 4 > BAR_LEN: return None
    mm.seek(off)
    return int.from_bytes(mm.read(4), "little")

def r8(off):
    if off >= BAR_LEN: return None
    mm.seek(off)
    return mm.read(1)[0]

def dump_u32(base, size, label):
    print(f"== {label} (u32) ==")
    for off in range(0, size, 4):
        v = r32(base + off)
        if v is None: continue
        if off % 0x40 == 0:
            print(f"-- {label} +{off:#06x} --")
        print(f"{base+off:#08x} = {v:#010x}")

def dump_u8(base, size, label):
    print(f"== {label} (u8) ==")
    for off in range(0, size, 16):
        row = [r8(base + off + i) for i in range(16)]
        if all(v == 0xFF for v in row) or all(v == 0x00 for v in row):
            continue  # 折叠全 FF/全 00 行, 缩短输出
        vals = " ".join(f"{v:02x}" if v is not None else "??" for v in row)
        print(f"{base+off:#08x}: {vals}")

dump_u32(0x990000, 0x800, "VA/WIN crtc0+c1 (0x990000-0x9907FF)")
dump_u32(0x9B0000, 0x100, "TOP (0x9B0000)")
dump_u8(0x1200000, 0x1200, "HDMI TX 0x0000-0x11FF")
dump_u8(0x1204000, 0x200, "HDMI TX 0x4000-0x41FF")
dump_u8(0x1205000, 0x100, "HDMI TX 0x5000-0x50FF")
EOF

echo "==> full dump $DEV at $(date)" | tee -a "$OUT"
python3 /tmp/fullregdump.py "$DEV/resource1" | tee -a "$OUT"
rm -f /tmp/fullregdump.py
echo "==> done" | tee -a "$OUT"
