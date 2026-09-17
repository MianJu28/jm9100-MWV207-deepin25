# 厂商安装包（vendor）

本目录保存 **景嘉微 JM9100 (mwv207)** 的官方安装包副本，供系统还原后离线重建使用。
配套操作步骤见 **`docs/系统还原后重建步骤.md`**。

## 包清单

| 文件 | 包名 | 版本 | 架构 | 大小 | 用途 |
|---|---|---|---|---|---|
| `com.jingjiamicro.mwv207_1.7.0.uos_arm64.deb` | `com.jingjiamicro.mwv207` | 1.7.0.uos | arm64 | 5.4 MB | **用户态主包**：`jmgpu_dri.so`(GL)、`libdrm_jmgpu.so`、`jmgpu_drv_video.so`(VA-API)、专有 X 驱动 `mwv207_drv.so`、`libGLX_mwv207`、`libEGL_mwv207`、`libgbm_jm.so` |
| `com.jingjiamicro.mwv207.vaapi_1.6.2.uos_arm64.deb` | `com.jingjiamicro.mwv207.vaapi` | 1.6.2.uos | arm64 | 364 KB | **VA-API 硬解**（`vainfo` / `mpv --hwdec=vaapi` 需要） |
| `mwv207-dkms_1.7.0.uos_all.deb` | `mwv207-dkms` | 1.7.0.uos | all | 714 KB | **内核模块 DKMS 包**（官方版；本机实际用的是 **本仓库 `kernel/` 源码**构建的版本，见重建文档 §1） |

## SHA-256 校验值

```
a0e6b4ed497da7b67cc96625ca3dd54f23dadb9c8b8327d2179ab1027501f713  com.jingjiamicro.mwv207_1.7.0.uos_arm64.deb
e64fed56ec3d85e5f68ab47368af20089c962b78f7ebc52dfb4bb7ae9d05351d  com.jingjiamicro.mwv207.vaapi_1.6.2.uos_arm64.deb
14c758a612549935a0b5cd2e84b00fe9c421970147e4cc244417d41168f5f8fc  mwv207-dkms_1.7.0.uos_all.deb
```

校验：
```bash
cd vendor && sha256sum -c <<'EOF'
a0e6b4ed497da7b67cc96625ca3dd54f23dadb9c8b8327d2179ab1027501f713  com.jingjiamicro.mwv207_1.7.0.uos_arm64.deb
e64fed56ec3d85e5f68ab47368af20089c962b78f7ebc52dfb4bb7ae9d05351d  com.jingjiamicro.mwv207.vaapi_1.6.2.uos_arm64.deb
14c758a612549935a0b5cd2e84b00fe9c421970147e4cc244417d41168f5f8fc  mwv207-dkms_1.7.0.uos_all.deb
EOF
```

## 安装

```bash
cd vendor
sudo dpkg -i com.jingjiamicro.mwv207_1.7.0.uos_arm64.deb
sudo dpkg -i com.jingjiamicro.mwv207.vaapi_1.6.2.uos_arm64.deb
sudo apt-get -f install -y          # 依赖缺失时补齐
```

> **`Depends: libpciaccess0, libudev1, xserver-xorg-core, libdrm2, libglvnd0`**
>
> ⚠️ 装完**还必须**补一个 soname 兼容链接，否则 DDX 加载失败
> （`libdrm.so.2.4.0: cannot open shared object file`）：
> ```bash
> sudo ln -sf /usr/lib/aarch64-linux-gnu/libdrm.so.2 \
>             /usr/lib/aarch64-linux-gnu/mwv207/libdrm.so.2.4.0
> ```
> 然后还需打 **ABI 24→25 补丁**（`tools/patch_xorg_abi.py`），详见重建文档 §3 / §5。

## 卸载

```bash
sudo dpkg -r com.jingjiamicro.mwv207 com.jingjiamicro.mwv207.vaapi
```

## 备注

- 这些包是**厂商闭源二进制**，仅作本机重建用途；本仓库对它们的**字节级补丁脚本**见 `tools/`
  （`patch_xorg_abi.py`、`patch_ddx_tearfree_sync.py`、`patch_gl_storage.py`）。
- `mwv207-dkms_1.7.0.uos_all.deb` 提供的是**官方内核模块**；本机实际部署的是
  **本仓库 `kernel/`（提交 `27537d0`）** 构建的模块，二者不要混用。
- 另有官方移植素材（未纳入本目录）：`mwv207_6.6_dkms_source.tar.gz`、
  `mwv207_6.6_ported_source.tar.gz`、`mwv207_6.6_port.patch`。
