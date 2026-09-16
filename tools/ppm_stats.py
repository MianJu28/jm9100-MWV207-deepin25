#!/usr/bin/env python3
# 统计 PPM(P6) 截图的颜色分布，用于判断 mpv 直通画面是否为"全零深绿"。
import sys

def load_ppm(path):
    with open(path, 'rb') as f:
        data = f.read()
    # 解析 P6 头（容忍注释）
    fields = []
    i = 0
    while len(fields) < 4 and i < len(data):
        if data[i:i+1] == b'#':
            while i < len(data) and data[i:i+1] != b'\n':
                i += 1
        elif data[i:i+1].isspace():
            i += 1
        else:
            j = i
            while j < len(data) and not data[j:j+1].isspace():
                j += 1
            fields.append(data[i:j])
            i = j
    w, h = int(fields[1]), int(fields[2])
    i += 1
    px = data[i:i + w * h * 3]
    return w, h, px

def main():
    path = sys.argv[1]
    w, h, px = load_ppm(path)
    n = w * h
    if len(px) < n * 3:
        print("truncated data")
        return
    colors = set()
    green = 0
    dark = 0
    sr = sg = sb = 0
    for k in range(n):
        r, g, b = px[3*k], px[3*k+1], px[3*k+2]
        sr += r; sg += g; sb += b
        colors.add((r >> 4, g >> 4, b >> 4))
        if g > 40 and r * 3 < g and b * 3 < g:
            green += 1
        if r < 16 and g < 16 and b < 16:
            dark += 1
    print("%s: %dx%d avg=(%d,%d,%d) unique16=%d green=%.1f%% black=%.1f%%"
          % (path, w, h, sr // n, sg // n, sb // n, len(colors),
             100.0 * green / n, 100.0 * dark / n))

main()
