#include <stdlib.h>
#include <stdio.h>
#include <libnotify/notify.h>


int main (int argc, char *argv[])
{
	printf("demo libnotify\n");

	notify_init("Hello world!");

	NotifyNotification * Hello = notify_notification_new(
		"哈囉！",
		"This is an example notification.",
		"dialog-information"
	);

	notify_notification_show (Hello, NULL);
	g_object_unref(G_OBJECT(Hello));

	notify_uninit();

	return EXIT_SUCCESS;
}
