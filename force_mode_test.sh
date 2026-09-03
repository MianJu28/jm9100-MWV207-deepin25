#!/usr/bin/env bash
# 方案1: 强制点屏验证 —— 定位闭源 jmgpu "无信号"根因(EDID/缺模式表 vs 显示管线死)
#
# 核心假设: mwv207 栈下 HDMI-A-1 EDID=0字节 仍有43个mode(内置模式表)且显示正常,
#          说明 DDC/EDID 本来就不可用是常态; jmgpu "connected 但 modes=空" 大概率
#          只是缺 fallback 模式表. 用 cmdline video= / drm.edid_firmware 强造模式,
#          若 CRTC 能 modeset 出信号 => 显示+硬解同时打通(方案1成功).
#
# 子命令:
#   live       (默认) jmgpu 接管 -> 采集诊断 -> 尝试 debugfs 注入 -> modetest 强制 setcrtc
#              -> 全程自动回退 mwv207+lightdm (trap 保护, 断线/中断也回退)
#   boot       准备重启路径: blacklist mwv207 + GRUB cmdline 注入
#              video=<conn>:1920x1080@60e drm.edid_firmware=<conn>:edid/1920x1080.bin
#   boot-undo  精确回滚 boot 的全部改动
#
# 用法(SSH 会话, 必须 root):
#   sudo ./force_mode_test.sh          # 先跑 live 诊断(自动回退, 不影响后续)
#   sudo ./force_mode_test.sh boot     # live 后再跑, 准备重启验证
#   sudo reboot                        # 重启后观察屏幕 / SSH 检查
#   sudo ./force_mode_test.sh boot-undo && sudo reboot   # 结束后回滚
#
# 产物: /var/log/jmgpu_force_mode_test.log, /var/lib/jm9100-test/
set -uo pipefail

PCI="0000:07:00.0"
LOG=/var/log/jmgpu_force_mode_test.log
WORK=/var/lib/jm9100-test
BLACKLIST=/etc/modprobe.d/zz-jmgpu-test-blacklist.conf
GRUB=/etc/default/grub
export PATH=/usr/sbin:/usr/bin:/sbin:/bin

log(){ echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }
die(){ log "!! $*"; exit 1; }
need_root(){ [ "$(id -u)" = 0 ] || die "请用 sudo 运行"; }

RECOVERED=0
NEED_REBOOT=0
recover(){
  [ "$RECOVERED" = 1 ] && return; RECOVERED=1
  log "==> 回退: 卸 jmgpu -> mwv207 + lightdm"
  pkill -9 modetest 2>/dev/null; pkill -9 Xorg 2>/dev/null; pkill -9 lightdm 2>/dev/null; sleep 1
  [ -f /sys/bus/pci/devices/$PCI/driver_override ] && \
    echo "" > /sys/bus/pci/devices/$PCI/driver_override 2>/dev/null
  if [ "$NEED_REBOOT" = 1 ]; then
    log "    !! setcrtc 时内核路径挂死(D态进程 SIGKILL 也杀不掉), 软回退不可靠"
    log "    ==> 请直接: sudo reboot  (未改任何持久配置, 重启自动回到 mwv207 显示)"
    return
  fi
  rmmod jmgpu 2>/dev/null &
  RP=$!
  N=0; while [ $N -lt 8 ] && kill -0 $RP 2>/dev/null; do sleep 1; N=$((N+1)); done
  if kill -0 $RP 2>/dev/null; then
    log "    rmmod 8s 未完成 => jmgpu 无法卸载, 请直接: sudo reboot (重启自动回 mwv207)"
    return
  fi
  modprobe -r jmgpu 2>/dev/null; sleep 1
  modprobe mwv207 2>/dev/null; sleep 3
  if [ -d /sys/bus/pci/drivers/mwv207 ] && [ ! -e /sys/bus/pci/devices/$PCI/driver ]; then
    echo "$PCI" > /sys/bus/pci/drivers/mwv207/bind 2>/dev/null && log "    mwv207 手动重绑"
  fi
  systemctl start lightdm 2>/dev/null
  log "==> 回退完成: 当前驱动 $(readlink /sys/bus/pci/devices/$PCI/driver 2>/dev/null)"
}

# modetest 探测: 优先按驱动名 jmgpu, 失败退回 -D card0
# 注意: 必须用变量展开而非 shell 函数 —— timeout 调不到函数, 会误执行系统 /bin/mt(磁带工具)
set_mt(){
  if modetest -M jmgpu -c >/dev/null 2>&1; then MT="modetest -M jmgpu"
  else MT="modetest -D /dev/dri/card0"; fi
}

snap_connectors(){
  local tag="$1" c st m e
  log "   [$tag]"
  for c in /sys/class/drm/card*-*/; do
    [ -d "$c" ] || continue
    st=$(cat "$c/status" 2>/dev/null)
    m=$(wc -l < "$c/modes" 2>/dev/null)
    e=$(stat -c%s "$c/edid" 2>/dev/null || echo 0)
    log "   $(basename "$c"): status=$st modes=$m edid=${e}B dpms=$(cat "$c/dpms" 2>/dev/null) enabled=$(cat "$c/enabled" 2>/dev/null)"
  done
}

live(){
  need_root
  mkdir -p "$WORK"
  echo "==== 方案1 live 强制点屏诊断 $(date) ====" | tee "$LOG"

  log "[0] 依赖与现状"
  if ! command -v modetest >/dev/null 2>&1; then
    log "    modetest 未安装, 尝试安装 libdrm-tests..."
    apt-get install -y libdrm-tests >>"$LOG" 2>&1 \
      && log "    安装成功" \
      || log "    !! 安装失败(手动: sudo apt install libdrm-tests), 继续 sysfs 诊断"
  fi
  edidcfg=$(grep -h "^CONFIG_DRM_LOAD_EDID_FIRMWARE" "/boot/config-$(uname -r)" 2>/dev/null \
            || zcat /proc/config.gz 2>/dev/null | grep "^CONFIG_DRM_LOAD_EDID_FIRMWARE" \
            || echo "CONFIG_DRM_LOAD_EDID_FIRMWARE=unknown")
  log "    内核 EDID 固件支持: $edidcfg (y/m 时 drm.edid_firmware=edid/1920x1080.bin 走内核内置假EDID)"
  snap_connectors "mwv207 栈现状(对照, 注意 HDMI 的 modes 数与 edid=0):"

  trap 'recover' EXIT INT TERM

  log "[1] 停 lightdm 释放 GPU"
  systemctl stop lightdm 2>>"$LOG"; sleep 2; pkill -9 Xorg 2>/dev/null; sleep 1
  log "[2] 卸载 mwv207"
  modprobe -r mwv207 2>>"$LOG"; sleep 2
  if lsmod | grep -q mwv207; then log "!! mwv207 卸载失败(仍被占用)"; recover; exit 1; fi

  log "[3] jmgpu 接管 $PCI"
  dmesg -c >/dev/null 2>&1 || true
  echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override 2>>"$LOG"
  modprobe jmgpu 2>>"$LOG"; sleep 5
  if [ ! -e /dev/jmgpu ]; then log "!! jmgpu probe 失败(无 /dev/jmgpu)"; recover; exit 1; fi
  log "    /dev/jmgpu OK, /dev/dri: $(ls /dev/dri/ | tr '\n' ' ')"

  log "[4] jmgpu 栈 connector 现状:"
  snap_connectors "jmgpu 栈"
  : > "$WORK/jmgpu_connector.txt"
  for c in /sys/class/drm/card*-*/; do
    [ "$(cat "$c/status" 2>/dev/null)" = connected ] || continue
    basename "$c" | sed 's/^card[0-9]*-//' >> "$WORK/jmgpu_connector.txt"
  done
  if [ -s "$WORK/jmgpu_connector.txt" ]; then
    log "    connected connector 名: $(tr '\n' ' ' < "$WORK/jmgpu_connector.txt")(已记录, boot 子命令将使用)"
  else
    echo "HDMI-A-1" > "$WORK/jmgpu_connector.txt"
    log "    !! jmgpu 栈无 connected connector, boot 将用默认名 HDMI-A-1"
  fi

  log "[5] dmesg 显示路径诊断(ddc/i2c/edid/pll/phy/hdmi/mode):"
  dmesg | grep -iE "jmgpu|ddc|i2c|edid|hdmi|hdcp|scdc|pll|phy|link train|aux|crtc|mode set|drm" \
    | head -80 >> "$LOG" 2>&1

  log "[6] jmgpu 私有参数/调试接口枚举(如有强制显示参数可直接翻盘):"
  for p in /sys/module/jmgpu/parameters/*; do
    [ -e "$p" ] && log "    $(basename "$p") = $(cat "$p" 2>/dev/null)"
  done 2>/dev/null
  ls /proc/jmgpu* >> "$LOG" 2>/dev/null || true
  ls -la /sys/kernel/debug/dri/*/ >> "$LOG" 2>&1 || true

  log "[7] debugfs 强制注入探测(force / edid_override, 6.6 可能未实现):"
  INJ=0
  for d in /sys/kernel/debug/dri/*/card*-*/; do
    [ -d "$d" ] || continue
    name=$(basename "$d")
    if [ -w "$d/force" ]; then
      echo on > "$d/force" 2>/dev/null && { log "    $name: force=on 已写"; INJ=1; }
    fi
    if [ -e "$d/edid_override" ]; then
      echo edid/1920x1080.bin > "$d/edid_override" 2>/dev/null \
        && { log "    $name: edid_override=edid/1920x1080.bin 已写"; INJ=1; }
    fi
    log "    $name/ 内容: $(ls "$d" 2>/dev/null | tr '\n' ' ')"
  done
  [ "$INJ" = 0 ] && log "    (无注入接口 => live 阶段无法凭空造 mode, 决定性验证需走 boot 路径)"

  if command -v modetest >/dev/null 2>&1; then
    set_mt
    log "[8] modetest 枚举 (GETCONNECTOR 会触发 fill_modes 重新探测):"
    $MT -c 2>&1 | head -60 >> "$LOG" 2>&1
    CONN=$($MT -c 2>/dev/null | grep -v disconnected | awk '/connected/{print $1; exit}')
    CRTC=$($MT -p 2>/dev/null | awk '/^[0-9]+\t/{print $1; exit}')
    log "    connector_id=$CONN crtc_id=$CRTC"
    log "    connected connector 的 mode 列表(前12行):"
    $MT -c 2>&1 | grep -v disconnected | grep -A 12 "connected" | head -16 >> "$LOG" 2>&1

    if [ -n "$CONN" ] && [ -n "$CRTC" ]; then
      log "[9] 强制 setcrtc (15s 观察窗) —— >>> 请立即观察主显示器是否出现彩条测试图 <<<"
      GOT=0
      for MODE in "1920x1080" "1920x1080@60"; do
        log "    $ $MT -s $CONN@$CRTC:$MODE"
        $MT -s "$CONN@$CRTC:$MODE" >/dev/null 2>&1 &
        MPID=$!
        N=0
        while [ $N -lt 15 ] && kill -0 $MPID 2>/dev/null; do sleep 1; N=$((N+1)); done
        if ! kill -0 $MPID 2>/dev/null; then
          wait $MPID 2>/dev/null; ec=$?
          if [ "$ec" = 0 ]; then
            # rc=0 + 立即退出: setcrtc 已成功, modetest 的 getchar() 读到 stdin EOF 正常退出
            # (被内核拒绝是 rc=22/1; 上次挂死版是 D 态永驻)
            log "    ★ setcrtc $MODE -> rc=0 = 内核成功执行!"
            GOT=1
            log "    ==> 保持显示 30s —— >>> 请立即观察主显示器是否出现彩条测试图 <<<"
            sleep 30 | $MT -s "$CONN@$CRTC:$MODE" >/dev/null 2>&1
            log "    (30s 观察窗结束; modetest 退出释放 master, 屏幕复黑属正常)"
            break
          else
            log "    setcrtc $MODE -> modetest 提前退出 rc=$ec (22/1=mode/encoder 被内核拒)"
            continue
          fi
        fi
        ST=$(ps -o stat= -p $MPID 2>/dev/null | tr -d ' ')
        log "    setcrtc $MODE -> 15s 后 modetest 仍存活 (stat=$ST)"
        case "$ST" in
          *D*)
            log "    !! setcrtc ioctl 卡死内核(D态) —— 黄金现场, wchan 与内核栈:"
            log "       wchan=$(cat /proc/$MPID/wchan 2>/dev/null)"
            cat /proc/$MPID/stack >> "$LOG" 2>&1 || true
            dmesg | tail -12 >> "$LOG" 2>&1 || true
            kill -9 $MPID 2>/dev/null; sleep 2
            if kill -0 $MPID 2>/dev/null; then
              log "    pid=$MPID SIGKILL 无效 => 内核路径挂死, 只能重启清理"
              NEED_REBOOT=1
            fi
            break ;;
          *)
            # S/R 态: setcrtc 已被内核接受, modetest 驻留显示循环 => 成功
            log "    ★ setcrtc 被内核接受(CRTC 已输出) —— 屏幕是否亮过彩条?"
            GOT=1
            kill -9 $MPID 2>/dev/null
            break ;;
        esac
      done
      log "    setcrtc 结果: $([ $GOT = 1 ] && echo '★ 内核接受' || echo '未成功(拒绝或挂死)')"

      if [ "$GOT" = 0 ] && [ "$NEED_REBOOT" = 0 ]; then
        FV=$(cat /sys/module/jmgpu/parameters/fake_vblank 2>/dev/null || echo "?")
        log "[9b] 疑似卡在等 vblank => 用 fake_vblank=1 重载 jmgpu 再试 (当前 fake_vblank=$FV)"
        if [ "$FV" = "0" ] && ! pgrep -x modetest >/dev/null 2>&1; then
          rmmod jmgpu 2>>"$LOG"
          if ! lsmod | grep -q jmgpu; then
            echo "jmgpu" > /sys/bus/pci/devices/$PCI/driver_override
            modprobe jmgpu fake_vblank=1 2>>"$LOG"
            sleep 5
            if [ -e /dev/jmgpu ]; then
              set_mt
              CONN=$($MT -c 2>/dev/null | grep -v disconnected | awk '/connected/{print $1; exit}')
              CRTC=$($MT -p 2>/dev/null | awk '/^[0-9]+\t/{print $1; exit}')
              log "    重载后 connector_id=$CONN crtc_id=$CRTC"
              if [ -n "$CONN" ] && [ -n "$CRTC" ]; then
                MODE="1920x1080"
                log "    $ $MT -s $CONN@$CRTC:$MODE  (fake_vblank=1)"
                $MT -s "$CONN@$CRTC:$MODE" >/dev/null 2>&1 &
                MPID=$!
                N=0
                while [ $N -lt 15 ] && kill -0 $MPID 2>/dev/null; do sleep 1; N=$((N+1)); done
                if ! kill -0 $MPID 2>/dev/null; then
                  wait $MPID 2>/dev/null; ec=$?
                  log "    setcrtc -> rc=$ec (fake_vblank=1 仍被拒)"
                else
                  ST=$(ps -o stat= -p $MPID 2>/dev/null | tr -d ' ')
                  case "$ST" in
                    *D*) log "    fake_vblank=1 仍 D 态挂死, 内核栈:"; cat /proc/$MPID/stack >> "$LOG" 2>&1
                         kill -9 $MPID 2>/dev/null; sleep 2
                         kill -0 $MPID 2>/dev/null && NEED_REBOOT=1 ;;
                    *)   log "    ★ fake_vblank=1 后 setcrtc 被内核接受! 屏幕是否亮过彩条?"
                         GOT=1; kill -9 $MPID 2>/dev/null ;;
                  esac
                fi
              fi
            else
              log "    fake_vblank=1 重载后 probe 失败"
            fi
          else
            log "    rmmod 失败(jmgpu 仍在加载), 跳过 9b"
          fi
        fi
      fi

      log "    dmesg 增量:"
      dmesg | tail -40 | grep -iE "jmgpu|drm|hdmi|pll|phy|edid|crtc|mode|encoder" >> "$LOG" 2>&1 || true
      log "    (setcrtc 结束后 CRTC 关闭屏幕复黑属正常; 复看请手动执行上面记录的 modetest 命令)"
    fi
  else
    log "[8] 无 modetest, 跳过强制点屏(手动: sudo apt install libdrm-tests 后重跑 live)"
  fi

  log "[10] 结论判定:"
  log "    A. rc=0 且 30s 观察窗内屏幕亮彩条 => 显示管线完全打通! 转持久化+VA硬解验证"
  log "    B. rc=0 但屏幕从未亮              => 内核接受但 PHY/HDMI 无输出 => 转方案2"
  log "    C. rc=22/1 被拒                   => mode/encoder 不匹配 => 看 dmesg"
  log "    D. D 态挂死                       => 内核路径死等 => 转方案2"

  recover
  trap - EXIT INT TERM
  log "==== live 诊断结束, 已回退 mwv207+lightdm ===="
}

boot(){
  need_root
  mkdir -p "$WORK"
  CONN=$(cat "$WORK/jmgpu_connector.txt" 2>/dev/null || echo "HDMI-A-1")
  echo "==== 方案1 持久化: jmgpu 开机接管 (connector=$CONN) $(date) ====" | tee -a "$LOG"

  # SCDC bug 已修, 真 EDID 可读, 无需 cmdline 注入假 EDID/mode —— 仅需让 jmgpu 接管
  printf 'blacklist mwv207\n' > "$BLACKLIST"
  log "已写 $BLACKLIST (deepin mwv207 在 initramfs 早期加载, 必须重建 initramfs 才生效)"
  printf 'jmgpu\n' > /etc/modules-load.d/jmgpu.conf
  log "已写 /etc/modules-load.d/jmgpu.conf (systemd 早期强制加载, 不依赖 udev alias)"
  update-initramfs -u >> "$LOG" 2>&1 && log "update-initramfs OK" || log "!! update-initramfs 失败"

  log "==> 重启后: mwv207 被禁, jmgpu 接管 (显示管线已实测打通)"
  log "==> 重启后 SSH/本机检查清单:"
  log "    lsmod | grep -E 'jmgpu|mwv207'      # 应只见 jmgpu"
  log "    ls /dev/jmgpu /dev/dri/"
  log "    cat /sys/class/drm/card*-HDMI*/modes"
  log "    lightdm + 专有 X 驱动(mwv207_drv.so) 应自动点亮桌面"
  log "    硬解验证: LIBVA_DRIVER_NAME=jmgpu vainfo"
  log "==> 回滚: sudo $0 boot-undo && sudo reboot"
}

boot_undo(){
  need_root
  echo "==== 方案1 boot-undo $(date) ====" | tee -a "$LOG"
  rm -f "$BLACKLIST" /etc/modules-load.d/jmgpu.conf
  update-initramfs -u >> "$LOG" 2>&1 && log "initramfs 已重建, mwv207 blacklist 已移除"
  log "==== boot-undo 完成, 重启后回到 mwv207 显示 ===="
}

usage(){
  echo "用法: sudo $0 [live|boot|boot-undo]"
  echo "  live       jmgpu 接管诊断+强制点屏尝试, 自动回退(默认)"
  echo "  boot       准备重启验证(blacklist mwv207 + cmdline 注入 mode/假EDID)"
  echo "  boot-undo  回滚 boot 改动"
}

case "${1:-live}" in
  live) live ;;
  boot) boot ;;
  boot-undo) boot_undo ;;
  *) usage; exit 1 ;;
esac
