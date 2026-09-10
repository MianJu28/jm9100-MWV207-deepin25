#!/usr/bin/env bash
# JM9100 显示输出域寄存器 dump —— 用于 jmgpu 栈与 mwv207(开源)栈的逐寄存器对比
# （详见 README.md §3.2 显示灰蒙蒙）
#
# 用法：
#   sudo ./dump_display_regs.sh            # 输出到 stdout
#   sudo ./dump_display_regs.sh -o jmgpu.txt
#
# 在两套栈下各跑一次（jmgpu 栈 / mwv207 栈 + modetest 点亮），diff 两份输出。
# 依赖 root（mmap PCI BAR0 via /sys/.../resource0）与 bc-less 纯 bash。
set -euo pipefail
set -u

OUT=/dev/null
if [ "${1:-}" = "-o" ] && [ -n "${2:-}" ]; then OUT="$2"; fi

DEV=""
for d in /sys/bus/pci/devices/*/resource1; do
  [ -e "$d" ] || continue
  # JM9100: vendor 0x0731 device 0x9100
  # 寄存器域(VA 0x990000 / HDMI 0x1200000)在 BAR1: 两栈驱动均
  # ioremap(pci_resource_start(pdev,1)) 作为 mmio 基址
  dir=$(dirname "$d")
  ven=$(cat "$dir/vendor"); dev=$(cat "$dir/device")
  if [ "$ven" = "0x0731" ] && [ "$dev" = "0x9100" ]; then DEV="$dir"; break; fi
done
[ -n "$DEV" ] || { echo "ERROR: JM9100 (0731:9100) not found" >&2; exit 1; }
[ "$(id -u)" = 0 ] || { echo "ERROR: 请用 sudo 运行 (需要 mmap $DEV/resource1)" >&2; exit 1; }

cat > /tmp/regdump.py <<'EOF'
import sys, os, mmap

res = open(sys.argv[1], "rb", buffering=0)
BAR_LEN = os.fstat(res.fileno()).st_size
mm = mmap.mmap(res.fileno(), BAR_LEN, mmap.MAP_SHARED, mmap.PROT_READ)
print(f"# BAR1 len = {BAR_LEN:#x}")

def r32(off):
    if off + 4 > BAR_LEN: return None
    mm.seek(off)
    return int.from_bytes(mm.read(4), "little")

def r8(off):
    if off >= BAR_LEN: return None
    mm.seek(off)
    return mm.read(1)[0]

VA   = 0x990000   # crtc0 VA/后处理单元 (crtc1 = +0x100)
WIN  = 0x990000   # crtc0 窗口单元 (WIN_CONTRAST@0x38)
HDMI = 0x1200000  # HDMI TX0 (DW HDMI, 8bit 寄存器)

# HDMI TX 存在性校验: 开源驱动以 read(0x1200000)==0x21 探测
hid = r32(HDMI)
print(f"# HDMI TX ID @0x1200000 = {hid:#x}" if hid is not None else "# HDMI TX ID: N/A (BAR1 太小?)")
if hid is not None and (hid & 0xff) != 0x21:
    print("# WARNING: HDMI ID != 0x21, 基址可能不正确!")

print("== VA / back-process unit (crtc0) ==")
va_regs = [
    ("0x2A0 BACK_PROCESS_MODE", VA + 0x2A0),
    ("0x2C0 ZOOM_FIX",          VA + 0x2C0),
    ("0x2C4 BACK_PROCESS_MOD",  VA + 0x2C4),
    ("0x430 plane fmt",         VA + 0x430),
    ("0x434 stride",            VA + 0x434),
    ("0x438 fb addr",           VA + 0x438),
    ("0x43C size|en",           VA + 0x43C),
    ("0x440 palette RAM sel",   VA + 0x440),
    ("0x444 LUT fifo data",     VA + 0x444),
    ("0x448 LUT fifo activate", VA + 0x448),
    ("0x44C LUT channel sel",   VA + 0x44C),
    ("0x450 LUT fifo count",    VA + 0x450),
    ("0x454 cursor hot",        VA + 0x454),
    ("0x460 LUT ctrl",          VA + 0x460),
    ("0x464 interlace cfg",     VA + 0x464),
    ("0x478 cursor ctrl",       VA + 0x478),
    ("0x4F8 plane w",           VA + 0x4F8),
]
for name, off in va_regs:
    v = r32(off)
    print(f"{name:28s} @{off:#08x} = {v:#010x}" if v is not None else f"{name:28s} @{off:#08x} = N/A")
print(f"{'WIN+0x2c WIN_SEL':28s} @{WIN+0x2c:#08x} = {r32(WIN+0x2c):#010x}")
print(f"{'WIN+0x38 WIN_CONTRAST':28s} @{WIN+0x38:#08x} = {r32(WIN+0x38):#010x}")

print("== VA timing (crtc0) ==")
for off in (0x400, 0x404, 0x408, 0x40C, 0x410, 0x414, 0x418, 0x41C, 0x420, 0x458, 0x45C):
    print(f"VA+{off:#04x} = {r32(VA+off):#010x}")

print("== HDMI TX0 (DW HDMI, 8bit) ==")
hdmi_regs = [
    ("0x0801 VP_CONF (coldepth)", 0x0801),
    ("0x0802 VP_STUFF",           0x0802),
    ("0x0803 VP_REMAP",           0x0803),
    ("0x0804 VP_CONF",            0x0804),
    ("0x1000 FC_INVIDCONF",       0x1000),
    ("0x1011 FC_CTRLDUR",         0x1011),
    ("0x1014-16 CH0-2 PREAM",     0x1014),
    ("0x1015 CH1 PREAM",          0x1015),
    ("0x1016 CH2 PREAM",          0x1016),
    ("0x1017 FC_AVICONF3",        0x1017),
    ("0x1019 FC_AVICONF0",        0x1019),
    ("0x101A FC_AVICONF1",        0x101A),
    ("0x101B FC_AVICONF2",        0x101B),
    ("0x101C AVI VIC",            0x101C),
    ("0x101E FC_PRCONF",          0x101E),
    ("0x4001 MC_CLKDIS",          0x4001),
    ("0x4004 MC_FLOWCTRL",        0x4004),
]
for name, off in hdmi_regs:
    v = r8(HDMI + off)
    print(f"{name:28s} @{HDMI+off:#08x} = {v:#04x}" if v is not None else f"{name:28s} = N/A")

print("== HDMI CSC coeffs (0x4100-0x411B, 8bit) ==")
row = []
for off in range(0x4100, 0x411C):
    row.append(f"{r8(HDMI+off):#04x}")
    if len(row) == 8:
        print(f"  {off-7:#06x}: " + " ".join(row)); row = []

print("== TX 0x10E0..0x10E3 ==")
for off in (0x10E0, 0x10E1, 0x10E2, 0x10E3):
    print(f"  {off:#06x} = {r8(HDMI+off):#04x}")
EOF

echo "==> dumping $DEV (BAR1 @0x60000000, 32M) at $(date)" | tee -a "$OUT"
python3 /tmp/regdump.py "$DEV/resource1" | tee -a "$OUT"
rm -f /tmp/regdump.py
echo "==> 完成。切栈后再跑一次，diff 两份输出。" | tee -a "$OUT"
