/*
 * wkmin —— 最小 WebKitGTK 复现器：强制走"加速合成"路径，并用可判读的纯色页面
 * 便于用 ffmpeg 抓屏 + 像素统计客观判定成败（无需人眼）。
 */
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <stdio.h>
#include <stdlib.h>

static const char *HTML =
	"<html><head><meta charset=utf-8><style>"
	"html,body{margin:0;padding:0;background:#ff0000;height:100%;}"
	"#l{width:380px;height:280px;background:#ff0000;"
	"   transform:translateZ(0); will-change:transform;}"   /* 强制成层 ⇒ 需要加速合成 */
	"#t{position:absolute;left:20px;top:100px;color:#ffffff;"
	"   font:bold 44px sans-serif;}"
	"</style></head><body><div id=l></div>"
	"<div id=t>WEBKIT-OK-12345</div>"
	"</body></html>";

static gboolean tick(gpointer data)
{
	(void)data;
	printf("[wkmin] 页面已加载，窗口应可见\n");
	fflush(stdout);
	return G_SOURCE_REMOVE;
}

int main(int argc, char **argv)
{
	GtkWidget *win, *view;
	WebKitSettings *st;

	gtk_init(&argc, &argv);

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(win), 400, 300);
	gtk_window_move(GTK_WINDOW(win), 60, 60);
	gtk_window_set_title(GTK_WINDOW(win), "wkmin");

	view = webkit_web_view_new();
	st = webkit_settings_new();
	/* 强制启用加速合成（硬件加速 always） */
	webkit_settings_set_hardware_acceleration_policy(
		st, WEBKIT_HARDWARE_ACCELERATION_POLICY_ALWAYS);
	webkit_web_view_set_settings(WEBKIT_WEB_VIEW(view), st);

	gtk_container_add(GTK_CONTAINER(win), view);
	g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(win);

	webkit_web_view_load_html(WEBKIT_WEB_VIEW(view), HTML, NULL);
	g_timeout_add_seconds(4, tick, NULL);

	printf("[wkmin] 环境: GLX=%s WEBKIT_DISABLE_COMPOSITING_MODE=%s LD_PRELOAD=%s\n",
	       getenv("__GLX_VENDOR_LIBRARY_NAME") ? : "(无)",
	       getenv("WEBKIT_DISABLE_COMPOSITING_MODE") ? : "(无)",
	       getenv("LD_PRELOAD") ? : "(无)");
	fflush(stdout);

	gtk_main();
	printf("[wkmin] 主循环结束（正常退出）\n");
	return 0;
}
