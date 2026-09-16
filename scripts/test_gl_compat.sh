#!/usr/bin/env bash
#
# test_gl_compat.sh -- 验证 JM9100 用户态 GL 兼容层（build-cli/libjm_gl_compat.so）
#
#   1/4 编译兼容层
#   2/4 扩展广告：GL_EXT_EGL_image_storage 是否出现在 GL 扩展列表
#   3/4 direct 判定：**系统未打补丁的 mpv** 是否从
#       "VAAPI hwdec only works with OpenGL or Vulkan backends"（拒绝）
#       变成 "Using EGL dmabuf interop via GL_EXT_EGL_image_storage"（进入直通）
#   4/4 像素校验：直通画面必须是片源原色（纯红 255,0,0），
#       而不是 Mesa/llvmpipe 直通时的「全零 NV12 深绿」（README §3.3 补）
#
# 用法：./scripts/test_gl_compat.sh [-s 1080p|720p|360p|WxH] [-k]
# 依赖：gcc ffmpeg mpv glxinfo nm python3；需要图形会话（默认 DISPLAY=:0）
#
set -uo pipefail

SIZE=1080p
KEEP=0
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
SHIM="$REPO/build-cli/libjm_gl_compat.so"
PASS=0
FAIL=0

while getopts "s:kh" o; do
	case "$o" in
	s) SIZE=$OPTARG ;;
	k) KEEP=1 ;;
	*) printf '用法: %s [-s 尺寸] [-k]\n' "$0"; exit 1 ;;
	esac
done

export DISPLAY="${DISPLAY:-:0}"
# 不设 LIBVA_DRIVER_NAME 时 libva 找不到 jmgpu_drv_video.so，mpv 会静默软解
export LIBVA_DRIVER_NAME="${LIBVA_DRIVER_NAME:-jmgpu}"
# 厂商 GLX vendor（会话通常已由 /etc/profile.d/mwv207_glvnd.sh 导出，这里兜底）
export __GLX_VENDOR_LIBRARY_NAME="${__GLX_VENDOR_LIBRARY_NAME:-mwv207}"

case "$SIZE" in
720p) WH=1280x720 ;;
360p) WH=640x360 ;;
*) WH=$SIZE ;;
esac
VID="/tmp/glc_red_$SIZE.mp4"

hr() { printf '%s\n' "------------------------------------------------------------"; }
say() { printf '%s\n' "$*"; }
warn() { printf '\033[33m%s\033[0m\n' "$*" >&2; }
ok() { PASS=$((PASS + 1)); printf '\033[32m  [OK] %s\033[0m\n' "$*"; }
bad() { FAIL=$((FAIL + 1)); printf '\033[31m  [NG] %s\033[0m\n' "$*"; }

for t in gcc ffmpeg mpv glxinfo nm python3; do
	command -v "$t" >/dev/null || { warn "缺少依赖: $t"; exit 1; }
done

cleanup() {
	killall -q mpv 2>/dev/null
	[ "$KEEP" = 1 ] || rm -rf /tmp/glc_shots /tmp/glc_*.log /tmp/glc_*.ppm
}
trap cleanup EXIT

# ------------------------------------------------------------ 1/4 编译
say "===== 1/4 编译兼容层 ====="; hr
"$HERE/build_gl_compat.sh" >/tmp/glc_build.log 2>&1 || {
	warn "编译失败："; tail -20 /tmp/glc_build.log >&2; exit 1; }
grep -E "产物|符号自检|缺少" /tmp/glc_build.log | sed 's/^/  /'
[ -f "$SHIM" ] || { warn "没生成 $SHIM"; exit 1; }

# ------------------------------------------------------------ 2/4 扩展广告
say ""; say "===== 2/4 扩展广告 ====="; hr
ext_of() { # $1 = LD_PRELOAD 值（空表示不加载）
	if [ -n "$1" ]; then LD_PRELOAD="$1" glxinfo 2>/dev/null; else glxinfo 2>/dev/null; fi |
		grep -o "GL_EXT_EGL_image_storage" | head -1
}
A=$(ext_of ""); B=$(ext_of "$SHIM")
say "  无兼容层: ${A:-（未出现）}"
say "  有兼容层: ${B:-（未出现）}"
[ -z "$A" ] && [ -n "$B" ] && ok "扩展广告生效" || bad "扩展广告未生效"

# ------------------------------------------------------------ 3/4 direct 判定
say ""; say "===== 3/4 系统 mpv（未打补丁）direct 判定 ====="; hr
[ -f "$VID" ] || {
	say "  生成纯红片源 $WH -> $VID"
	ffmpeg -y -hide_banner -loglevel error -f lavfi \
		-i "color=c=red:s=${WH}:r=30" -t 3 -c:v libx264 -preset ultrafast \
		-pix_fmt yuv420p "$VID" || { warn "生成片源失败"; exit 1; }
}
say "  mpv: $(mpv --version 2>/dev/null | head -1)"
say "  片源: $VID（期望 RGB=(255,0,0)）"

mpv_log() { # $1=日志  $2=LD_PRELOAD（空=不加载）
	if [ -n "$2" ]; then
		LD_PRELOAD="$2" timeout 40 mpv --no-config --no-audio --frames=40 \
			--vo=gpu --hwdec=vaapi --msg-level=vo=v,vd=v "$VID" >"$1" 2>&1
	else
		timeout 40 mpv --no-config --no-audio --frames=40 \
			--vo=gpu --hwdec=vaapi --msg-level=vo=v,vd=v "$VID" >"$1" 2>&1
	fi
}
verdict() { grep -a -m1 -oE "Using EGL dmabuf interop via [^ ]+|VAAPI hwdec only works with OpenGL or Vulkan backends" "$1" | head -1; }

mpv_log /tmp/glc_no.log ""
mpv_log /tmp/glc_yes.log "$SHIM"
V_NO=$(verdict /tmp/glc_no.log); V_YES=$(verdict /tmp/glc_yes.log)
say "  无兼容层: ${V_NO:-（无明确判定）}"
say "  有兼容层: ${V_YES:-（无明确判定）}"
case "$V_YES" in
"Using EGL dmabuf interop via"*) ok "兼容层让未打补丁的 mpv 进入 direct 硬解" ;;
*) bad "兼容层下 mpv 仍未进入 direct" ;;
esac

# ------------------------------------------------------------ 4/4 像素校验
say ""; say "===== 4/4 直通画面像素 ====="; hr
rm -rf /tmp/glc_shots; mkdir -p /tmp/glc_shots
killall -q mpv 2>/dev/null; sleep 1
LD_PRELOAD="$SHIM" JMGPU_GL_COMPAT_DEBUG=1 timeout 40 mpv --no-config \
	--loop --no-audio --vo=gpu --hwdec=vaapi \
	--geometry=320x180+100+100 --no-border \
	--input-ipc-server=/tmp/glc_sock --screenshot-format=png \
	--screenshot-directory=/tmp/glc_shots "$VID" >/tmp/glc_pix.log 2>&1 &
python3 - <<'PY'
import os, socket, time
for _ in range(60):
    if os.path.exists("/tmp/glc_sock"):
        break
    time.sleep(0.2)
time.sleep(4)
try:
    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM); s.connect("/tmp/glc_sock")
    s.sendall(b'{ "command": ["screenshot", "video"] }\n'); time.sleep(1.5)
    s.recv(4096); s.close(); print("  已发送截图命令")
except Exception as e:
    print("  截图命令失败: %s" % e)
PY
sleep 1; killall -q mpv 2>/dev/null; sleep 1
PNG=$(ls /tmp/glc_shots/*.png 2>/dev/null | tail -1)
if [ -z "$PNG" ]; then
	bad "没拿到截图（见 /tmp/glc_pix.log）"
else
	ffmpeg -y -hide_banner -loglevel error -i "$PNG" /tmp/glc_direct.ppm 2>/dev/null
	say "  截图: $PNG"
	OUT=$(python3 - /tmp/glc_direct.ppm <<'PY'
import sys
data = open(sys.argv[1], 'rb').read()
f, i = [], 0
while len(f) < 4 and i < len(data):
    if data[i:i+1] == b'#':
        while data[i:i+1] != b'\n': i += 1
    elif data[i:i+1].isspace(): i += 1
    else:
        j = i
        while not data[j:j+1].isspace(): j += 1
        f.append(data[i:j]); i = j
w, h = int(f[1]), int(f[2]); i += 1
px = data[i:i + w * h * 3]; n = w * h
sr = sg = sb = green = 0
for k in range(n):
    r, g, b = px[3*k], px[3*k+1], px[3*k+2]
    sr += r; sg += g; sb += b
    if g > 40 and r * 3 < g and b * 3 < g: green += 1
r, g, b = sr // n, sg // n, sb // n
print("  %dx%d avg=(%d,%d,%d) 绿色占比=%.1f%%" % (w, h, r, g, b, 100.0 * green / n))
# 判定阈值与 test_passthrough.sh 一致（纯红片源经 NV12→RGB 后为 (255,0,64)）
if r > 180 and g < 90 and b < 90:
    print("VERDICT=ok")
elif g > 40 and r < g and b < g:
    print("VERDICT=green")
else:
    print("VERDICT=unknown")
PY
)
	printf '%s\n' "$OUT" | grep -v VERDICT | sed 's/^/  /'
	case "$OUT" in
	*VERDICT=ok*) ok "画面为片源原色（红），零拷贝直通像素正确" ;;
	*VERDICT=green*) bad "画面全零深绿 —— storage/OES 挂接未真正生效" ;;
	*) bad "颜色非预期，请人工确认（见 /tmp/glc_pix.log）" ;;
	esac
	grep -a "jm-gl-compat: redirect" /tmp/glc_pix.log | head -2 | sed 's/^/  /'
fi

# ------------------------------------------------------------ 汇总
say ""; hr
say "结果: $PASS 项通过, $FAIL 项失败"
[ "$FAIL" = 0 ] || exit 1
