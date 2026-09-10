#!/usr/bin/env bash
#
# test_passthrough.sh -- VA-API 直通（mpv --hwdec=vaapi）一键验证
#
# 原理：用纯红静态片源播放，直通正常则画面为红 (255,0,0)；
#       若缓存在 CPU 不可见显存池，dmabuf 导入方 mmap 读到全零 NV12，
#       画面会变成深绿 (约 0,77,0 ~ 0,135,0)。两者可明确区分。
#
# 用法：
#   ./test_passthrough.sh                 # 默认 1080p
#   ./test_passthrough.sh -s 720p         # 用 720p 片源（占用更小）
#   ./test_passthrough.sh -e '--hwdec-extra-frames=0'   # 额外 mpv 参数
#   ./test_passthrough.sh -n              # 只做环境体检，不播放
#
# 依赖：ffmpeg、mpv、python3（用于 mpv IPC 截图与像素统计）
# 注意：需要图形会话（默认 DISPLAY=:0）；播放会短暂弹出一个小窗口。
#
set -uo pipefail

SIZE=1080p
EXTRA=""
CHECK_ONLY=0
KEEP=0
DIAG=0
SHIM=/tmp/pt_va_diag.so

usage() {
	cat <<'EOF'
用法: ./test_passthrough.sh [-s 尺寸] [-e 'mpv 额外参数'] [-x] [-n] [-k]
  -s 1080p|720p|360p|WxH   片源尺寸（默认 1080p）
  -e '...'                 追加 mpv 参数，如 -e '--hwdec-extra-frames=0'
  -x                       加载导出诊断 shim，打印每个导出 buffer 的
                           mmap 非零字节数与 vaGetImage 回读结果，
                           用于区分「缓冲内容是零」还是「缓冲正常但 GL 绑不上」
  -n                       仅环境体检
  -k                       保留中间文件
EOF
	exit 1
}

while getopts "s:e:nhkx" o; do
	case "$o" in
	s) SIZE=$OPTARG ;;
	e) EXTRA=$OPTARG ;;
	n) CHECK_ONLY=1 ;;
	k) KEEP=1 ;;
	x) DIAG=1 ;;
	h) usage ;;
	*) usage ;;
	esac
done

DISPLAY="${DISPLAY:-:0}"
export DISPLAY
RENDER=/dev/dri/renderD128
VID="/tmp/pt_red_${SIZE}.mp4"
# 读 dmesg / debugfs 需要 root；非 root 时用 sudo（可能会提示一次密码）
sudo=()
[ "$(id -u)" = "0" ] || sudo=(sudo)

hr() { printf '%s\n' "------------------------------------------------------------"; }
say() { printf '%s\n' "$*"; }
warn() { printf '[!] %s\n' "$*"; }

# ---------------------------------------------------------------- 环境体检
say "===== 1/4 环境体检 ====="
hr

say "内核模块: $(uname -r)"
if [ -r /sys/module/jmgpu/srcversion ]; then
	run_sv=$(cat /sys/module/jmgpu/srcversion)
	disk_sv=$(modinfo -F srcversion jmgpu 2>/dev/null)
	say "  jmgpu 运行态 srcversion: $run_sv"
	say "  磁盘模块   srcversion: $disk_sv"
	[ "$run_sv" = "$disk_sv" ] || warn "运行的不是磁盘上的模块（initramfs 冻结旧模块？）"
else
	warn "jmgpu 未加载"
fi

pvp=$(cat /sys/module/jmgpu/parameters/prefer_visible_pool 2>/dev/null)
nep=$(cat /sys/module/jmgpu/parameters/no_exclusive_pool 2>/dev/null)
say "  prefer_visible_pool = ${pvp:-<无此参数>}   （直通需要 =1）"
say "  no_exclusive_pool   = ${nep:-<无此参数>}   （=1 会禁用不可见池，代价是显存只剩 255MB）"
if [ "${pvp:-0}" != "1" ]; then
	warn "prefer_visible_pool 不为 1：解码 surface 会优先落不可见池，直通基本不可能成功"
	say "      可即时开启: echo 1 | sudo tee /sys/module/jmgpu/parameters/prefer_visible_pool"
fi

say ""
say "显存池划分（dmesg）："
"${sudo[@]}" dmesg 2>/dev/null | grep -E "VRAM size|pool CPU physical" | tail -3 | sed 's/^/  /' || \
	warn "读 dmesg 需要 sudo，已跳过"

say ""
say "各进程 CPU 可见池占用（debugfs vidmem）："
VM=$("${sudo[@]}" cat /sys/kernel/debug/jmgpu/vidmem 2>/dev/null)
if [ -n "$VM" ]; then
	printf '%s\n' "$VM" | awk '
		/^VidMem Usage/{p=$0; sub(/^VidMem Usage \(Process /,"",p); sub(/\).*/,"",p)}
		/^External /{ if ($2+0 > 0 && $2+0 < 1e11) printf "  %-28s %8.1f MB\n", p, $2/1048576 }
	' | sort -k2 -rn | head -8
	say "  （可见池总容量 255MB；解码 1080p 约需 60MB）"
else
	warn "读不到 vidmem（需要 sudo）"
fi

say ""
say "最近一次导出的 buffer 落在哪个池（pool=4 可见 / pool=12 不可见）："
"${sudo[@]}" dmesg 2>/dev/null | grep "jmgpu-exp" | tail -6 | sed 's/^/  /' || true

[ "$CHECK_ONLY" = "1" ] && { hr; say "(-n) 仅体检完成"; exit 0; }

# ---------------------------------------------------------------- 片源
say ""
say "===== 2/4 准备片源 ====="
hr
case "$SIZE" in
1080p) WH="1920x1080" ;;
720p) WH="1280x720" ;;
360p) WH="640x360" ;;
*) WH="$SIZE" ;;
esac
if [ ! -f "$VID" ]; then
	say "生成纯红片源 $WH -> $VID"
	ffmpeg -y -hide_banner -loglevel error -f lavfi \
		-i "color=c=red:s=${WH}:r=30" -t 3 -c:v libx264 -preset ultrafast \
		-pix_fmt yuv420p "$VID" || { warn "ffmpeg 生成片源失败"; exit 1; }
fi
say "片源: $VID ($WH)，期望画面 RGB=(255,0,0)"

if [ "$DIAG" = "1" ]; then
	if [ ! -f "$SHIM" ] || [ "$(dirname "$0")/va_export_diag.c" -nt "$SHIM" ]; then
		say "编译导出诊断 shim -> $SHIM"
		gcc -O2 -fPIC -shared -o "$SHIM" \
			"$(dirname "$0")/va_export_diag.c" -ldl || \
			{ warn "shim 编译失败，忽略 -x"; DIAG=0; }
	fi
	[ "$DIAG" = "1" ] && say "已启用 -x：将打印每个导出 buffer 的 mmap_nz / vaGetImage"
fi

# ---------------------------------------------------------------- 播放 + 截图
say ""
say "===== 3/4 播放并抓帧 ====="
hr

BEFORE=$("${sudo[@]}" dmesg 2>/dev/null | grep -c "jmgpu-exp")

run_one() { # $1=hwdec 标签  $2=输出 ppm
	local tag=$1 ppm=$2 dir="/tmp/pt_shots_$1"
	killall -q mpv 2>/dev/null
	sleep 1
	rm -rf "$dir"; mkdir -p "$dir"
	say "  [$tag] 启动 mpv --hwdec=$tag ..."
	# shellcheck disable=SC2086
	if [ "$DIAG" = "1" ]; then
		LD_PRELOAD="$SHIM" mpv --no-config --loop --no-audio --vo=gpu \
			"--hwdec=$tag" --geometry=320x180+100+100 --no-border \
			--input-ipc-server="/tmp/pt_sock_$tag" \
			--screenshot-format=png --screenshot-directory="$dir" \
			$EXTRA "$VID" >"/tmp/pt_mpv_$tag.log" 2>&1 &
	else
		mpv --no-config --loop --no-audio --vo=gpu "--hwdec=$tag" \
			--geometry=320x180+100+100 --no-border \
			--input-ipc-server="/tmp/pt_sock_$tag" \
			--screenshot-format=png --screenshot-directory="$dir" \
			$EXTRA "$VID" >"/tmp/pt_mpv_$tag.log" 2>&1 &
	fi
	sleep 1
	python3 - "$tag" <<-'PYEOF'
		import os, socket, sys, time
		tag = sys.argv[1]
		sock = "/tmp/pt_sock_%s" % tag
		for _ in range(50):
		    if os.path.exists(sock):
		        break
		    time.sleep(0.2)
		time.sleep(4)
		try:
		    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
		    s.connect(sock)
		    s.sendall(b'{ "command": ["screenshot", "video"] }\n')
		    time.sleep(1.5)
		    s.recv(4096)
		    s.close()
		    print("    [%s] 已发送截图命令" % tag)
		except Exception as e:
		    print("    [%s] 截图命令失败: %s" % (tag, e))
	PYEOF
	sleep 1
	killall -q mpv 2>/dev/null
	sleep 1
	local png
	png=$(ls "$dir"/*.png 2>/dev/null | tail -1)
	if [ -z "$png" ]; then
		warn "[$tag] 没拿到截图"
		return 1
	fi
	ffmpeg -y -hide_banner -loglevel error -i "$png" "$ppm" || return 1
	say "    [$tag] 截图: $png"
	return 0
}

run_one vaapi /tmp/pt_direct.ppm
run_one no    /tmp/pt_soft.ppm

# 收集本次新产生的导出日志
say ""
say "本次播放新增的导出池归属："
NEW=$("${sudo[@]}" dmesg 2>/dev/null | grep "jmgpu-exp" | tail -n +"$((BEFORE + 1))")
if [ -n "$NEW" ]; then
	printf '%s\n' "$NEW" | sed 's/^/  /' | tail -8
	c4=$(printf '%s\n' "$NEW" | grep -c "pool=4")
	c12=$(printf '%s\n' "$NEW" | grep -c "pool=12")
	say "  -> 可见池(pool=4): $c4 个；不可见池(pool=12): $c12 个"
else
	say "  （无新增日志：说明 surface 小于 400KB 未打点，或未被导出）"
fi

if [ "$DIAG" = "1" ]; then
	say ""
	say "导出内容诊断（mmap_nz=0 表示缓冲里是零；vaGetImage 非零表示 surface 里确有数据）："
	grep -a "\[vad\]" /tmp/pt_mpv_vaapi.log 2>/dev/null | tail -14 | sed 's/^/  /'
fi

# ---------------------------------------------------------------- 判定
say ""
say "===== 4/4 判定 ====="
hr
python3 - /tmp/pt_direct.ppm /tmp/pt_soft.ppm <<-'PYEOF'
	import sys

	def load(p):
	    d = open(p, "rb").read()
	    f, i = [], 0
	    while len(f) < 4 and i < len(d):
	        if d[i:i+1] == b'#':
	            while i < len(d) and not d[i:i+1].isspace():
	                i += 1
	        elif d[i:i+1].isspace():
	            i += 1
	        else:
	            j = i
	            while j < len(d) and not d[j:j+1].isspace():
	                j += 1
	            f.append(d[i:j]); i = j
	    w, h = int(f[1]), int(f[2])
	    i += 1
	    return w, h, d[i:i + w * h * 3]

	def stats(p):
	    w, h, px = load(p)
	    n = w * h
	    sr = sg = sb = 0
	    green = 0
	    for k in range(n):
	        r, g, b = px[3 * k], px[3 * k + 1], px[3 * k + 2]
	        sr += r; sg += g; sb += b
	        if g > 40 and r * 3 < g and b * 3 < g:
	            green += 1
	    return w, h, sr // n, sg // n, sb // n, 100.0 * green / n

	d = stats(sys.argv[1]); s = stats(sys.argv[2])
	print("  直通(vaapi): %dx%d avg=(%d,%d,%d) 绿色占比 %.1f%%" % (d[0], d[1], d[2], d[3], d[4], d[5]))
	print("  软解(no)   : %dx%d avg=(%d,%d,%d) 绿色占比 %.1f%%" % (s[0], s[1], s[2], s[3], s[4], s[5]))
	r, g, b = d[2], d[3], d[4]
	v = "unknown"
	if r > 180 and g < 90 and b < 90:
	    print("  ==> 直通【正常】：画面是片源原色(红)")
	    v = "ok"
	elif g > 40 and r < g and b < g:
	    print("  ==> 直通【失败】：画面是全零 NV12 的深绿")
	    v = "green"
	else:
	    print("  ==> 结果不确定，请人眼确认截图 %s" % sys.argv[1])
	open("/tmp/pt_verdict.txt", "w").write(v)
PYEOF

# 归因提示：缓冲有数据但画面仍绿 => importer（GL/EGL）侧问题
if [ "$DIAG" = "1" ]; then
	NZD=$(grep -a -o "mmap_nz=[1-9][0-9]*" /tmp/pt_mpv_vaapi.log 2>/dev/null | head -1)
	INTEROP=$(grep -a "Using EGL dmabuf interop via" /tmp/pt_mpv_vaapi.log 2>/dev/null | tail -1 | sed 's/.*via //')
	VERD=$(cat /tmp/pt_verdict.txt 2>/dev/null)
	if [ -n "$NZD" ]; then
		say ""
		say "  导出缓冲内容非零（$NZD）—— 内核导出/mmapp 链路正常。"
		say "  当前 interop：${INTEROP:-未知}"
		if [ "$VERD" = "green" ]; then
			say "  ==> 故障定位在 importer（GL/EGL）侧：desktop GL 走了"
			say "      glEGLImageTargetTexStorageEXT，而 JM9100 该入口不生效，"
			say "      纹理保持全零。应用 mpv_dmabuf_oes_image.patch 重编 mpv 后重测。"
		fi
	fi
fi

say ""
say "详细日志：/tmp/pt_mpv_vaapi.log  /tmp/pt_mpv_no.log"
say "截图：     /tmp/pt_shots_vaapi/*.png  /tmp/pt_shots_no/*.png"
[ "$KEEP" = "0" ] || say "（-k 已保留中间文件）"
exit 0
