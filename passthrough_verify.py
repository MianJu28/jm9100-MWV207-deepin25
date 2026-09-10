#!/usr/bin/env python3
"""VA-API 直通像素验证。

用纯色片源，分别以 --hwdec=vaapi（直通，VA surface 经 dmabuf 交给 GL）
和 --hwdec=no（软解）播放，并用 mpv 自身的 screenshot 命令从 GL 输出抓帧。
直通若把 dmabuf 导成"全零 NV12"，画面会变成深绿/黑；正常应为片源原色。

用法：python3 passthrough_verify.py [片源] [期望RGB，如 255,0,0]
"""
import os
import socket
import subprocess
import sys
import time
import shutil

VID = sys.argv[1] if len(sys.argv) > 1 else "/tmp/red1080p.mp4"
WANT = sys.argv[2] if len(sys.argv) > 2 else "255,0,0"


def mpv_screenshot(mode, outdir):
    shutil.rmtree(outdir, ignore_errors=True)
    os.makedirs(outdir, exist_ok=True)
    sock = "/tmp/mpvsock_%s" % mode
    for p in (sock,):
        if os.path.exists(p):
            os.unlink(p)
    log = open("/tmp/mpv_%s.log" % mode, "wb")
    env = dict(os.environ, DISPLAY=":0")
    extra = os.environ.get("MPV_EXTRA", "").split()
    proc = subprocess.Popen([
        "mpv", "--no-config", "--loop", "--no-audio", "--vo=gpu",
        "--hwdec=%s" % mode, "--geometry=320x180+100+100",
        "--input-ipc-server=%s" % sock,
        "--screenshot-format=png", "--screenshot-directory=%s" % outdir,
    ] + extra + [VID], stdout=log, stderr=log, env=env)
    try:
        for _ in range(50):
            if os.path.exists(sock):
                break
            time.sleep(0.2)
        time.sleep(4)
        s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        s.connect(sock)
        s.sendall(b'{ "command": ["screenshot", "video"] }\n')
        time.sleep(1.5)
        s.recv(4096)
        s.close()
    finally:
        proc.terminate()
        try:
            proc.wait(timeout=5)
        except Exception:
            proc.kill()
        log.close()
    shots = sorted(f for f in os.listdir(outdir) if f.endswith(".png"))
    return os.path.join(outdir, shots[-1]) if shots else None


def ppm_from_png(png):
    ppm = png.rsplit(".", 1)[0] + ".ppm"
    subprocess.run(["ffmpeg", "-y", "-hide_banner", "-loglevel", "error",
                    "-i", png, ppm], check=True)
    return ppm


def main():
    want = tuple(int(x) for x in WANT.split(","))
    ok = True
    for mode in ("vaapi", "no"):
        png = mpv_screenshot(mode, "/tmp/shots_%s" % mode)
        if not png:
            print("[%s] 未拿到截图" % mode)
            ok = False
            continue
        ppm = ppm_from_png(png)
        out = subprocess.run([sys.executable,
                              os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                           "ppm_stats.py"), ppm],
                             capture_output=True, text=True).stdout.strip()
        print("[%s] %s" % (mode, out))
    print("期望颜色 RGB=%s" % (want,))
    print("提示：直通=vaapi 一行的 avg 应接近期望色；若为深绿(约 0,135,0)则仍是全零导出")


main()
