
## 原始討論

* [#13 回覆: 如何安裝 StarUML-v2.8.0-64-bit.deb ？](https://www.ubuntu-tw.org/modules/newbb/viewtopic.php?post_id=356984#forumpost356984)


## 參考連結

* Arch Wiki / [Desktop notifications](https://wiki.archlinux.org/index.php/Desktop_notifications)


## 相關套件

* [libnotify4](http://packages.ubuntu.com/xenial/libnotify4)
* [libnotify-dev](http://packages.ubuntu.com/xenial/libnotify-dev)
* [libnotify-doc](http://packages.ubuntu.com/xenial/libnotify-doc)

執行下面指令安裝

``` sh
$ sudo apt-get install libnotify-dev libnotify-doc
```

執行

``` sh
$ dpkg -L libnotify4
```

顯示

```
/.
/usr
/usr/share
/usr/share/doc
/usr/share/doc/libnotify4
/usr/share/doc/libnotify4/AUTHORS
/usr/share/doc/libnotify4/changelog.Debian.gz
/usr/share/doc/libnotify4/copyright
/usr/share/doc/libnotify4/NEWS.gz
/usr/lib
/usr/lib/x86_64-linux-gnu
/usr/lib/x86_64-linux-gnu/libnotify.so.4.0.0
/usr/lib/x86_64-linux-gnu/libnotify.so.4
```

執行

``` sh
$ ls /usr/lib/x86_64-linux-gnu/libnotify.so.4 -l
```

顯示

```
lrwxrwxrwx 1 root root 18 Apr 24  2016 /usr/lib/x86_64-linux-gnu/libnotify.so.4 -> libnotify.so.4.0.0
```

執行

``` sh
$ file /usr/lib/x86_64-linux-gnu/libnotify.so.4
```

顯示

```
/usr/lib/x86_64-linux-gnu/libnotify.so.4: symbolic link to libnotify.so.4.0.0
```

執行

``` sh
$ dpkg -L libnotify-dev
```

顯示

```
/.
/usr
/usr/share
/usr/share/gir-1.0
/usr/share/gir-1.0/Notify-0.7.gir
/usr/share/doc
/usr/share/doc/libnotify-dev
/usr/share/doc/libnotify-dev/copyright
/usr/include
/usr/include/libnotify
/usr/include/libnotify/notify-enum-types.h
/usr/include/libnotify/notification.h
/usr/include/libnotify/notify.h
/usr/include/libnotify/notify-features.h
/usr/lib
/usr/lib/x86_64-linux-gnu
/usr/lib/x86_64-linux-gnu/pkgconfig
/usr/lib/x86_64-linux-gnu/pkgconfig/libnotify.pc
/usr/lib/x86_64-linux-gnu/libnotify.a
/usr/share/doc/libnotify-dev/AUTHORS
/usr/share/doc/libnotify-dev/changelog.Debian.gz
/usr/share/doc/libnotify-dev/NEWS.gz
/usr/lib/x86_64-linux-gnu/libnotify.so
```

執行

``` sh
$ dpkg -L libnotify-doc
```

顯示

```
/.
/usr
/usr/share
/usr/share/gtk-doc
/usr/share/gtk-doc/html
/usr/share/gtk-doc/html/libnotify
/usr/share/gtk-doc/html/libnotify/right.png
/usr/share/gtk-doc/html/libnotify/ch01.html
/usr/share/gtk-doc/html/libnotify/left.png
/usr/share/gtk-doc/html/libnotify/index.html
/usr/share/gtk-doc/html/libnotify/libnotify-notify.html
/usr/share/gtk-doc/html/libnotify/NotifyNotification.html
/usr/share/gtk-doc/html/libnotify/api-index-full.html
/usr/share/gtk-doc/html/libnotify/index.sgml
/usr/share/gtk-doc/html/libnotify/libnotify.devhelp2
/usr/share/gtk-doc/html/libnotify/style.css
/usr/share/gtk-doc/html/libnotify/home.png
/usr/share/gtk-doc/html/libnotify/annotation-glossary.html
/usr/share/gtk-doc/html/libnotify/up.png
/usr/share/gtk-doc/html/libnotify/api-index-deprecated.html
/usr/share/doc
/usr/share/doc/libnotify-doc
/usr/share/doc/libnotify-doc/AUTHORS
/usr/share/doc/libnotify-doc/changelog.Debian.gz
/usr/share/doc/libnotify-doc/copyright
/usr/share/doc/libnotify-doc/NEWS.gz
```

執行下面指令

``` sh
$ firefox /usr/share/gtk-doc/html/libnotify/index.html
```

關於「firefox」可以改為「lynx」或「w3m」，或是參考這篇「[回覆 #3](https://www.ubuntu-tw.org/modules/newbb/viewtopic.php?post_id=355920#forumpost355920)」列的[參考連結](https://wiki.archlinux.org/index.php?title=List_of_applications/Internet&redirect=no#Web_browsers)，裡面列的瀏覽器。

## 編譯參數

可以參考「/usr/lib/x86_64-linux-gnu/pkgconfig/libnotify.pc」這個檔

執行

``` sh
$ pkg-config --cflags --libs libnotify
```

顯示

``` sh
-pthread -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng12 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lnotify -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0
```


執行下面指令，編譯「main.c」，寫成「[build.sh](build.sh)」。

``` sh
$ gcc -o app main.c $(pkg-config --cflags --libs libnotify)
```

編譯可以參考「[這篇](https://www.ubuntu-tw.org/modules/newbb/viewtopic.php?post_id=356758#forumpost356758)」裡面列的連結。


* [https://developer.gnome.org/glib/stable/](https://developer.gnome.org/glib/stable/)
* [https://developer.gnome.org/glib/stable/glib-compiling.html](https://developer.gnome.org/glib/stable/glib-compiling.html)
* [https://developer.gnome.org/gtk3/stable/](https://developer.gnome.org/gtk3/stable/)
* [https://developer.gnome.org/gtk3/stable/gtk-compiling.html](https://developer.gnome.org/gtk3/stable/gtk-compiling.html)
* [GNOME Developer Platform Demos](https://developer.gnome.org/gnome-devel-demos/stable/index.html.en) / [Platform Demos in C](https://developer.gnome.org/gnome-devel-demos/stable/c.html.en)


執行

``` sh
$ file app
```

顯示

```
app: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=3f9d12e9850b819b961d1237c46701d8c74dfe09, not stripped
```

執行

``` sh
$ ldd app
```

顯示

```
linux-vdso.so.1 =>  (0x00007ffdfaf16000)
libnotify.so.4 => /usr/lib/x86_64-linux-gnu/libnotify.so.4 (0x00007fccb7a7c000)
libgobject-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0 (0x00007fccb7829000)
libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007fccb760b000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fccb7242000)
libgdk_pixbuf-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libgdk_pixbuf-2.0.so.0 (0x00007fccb7020000)
libgio-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libgio-2.0.so.0 (0x00007fccb6c97000)
libglib-2.0.so.0 => /lib/x86_64-linux-gnu/libglib-2.0.so.0 (0x00007fccb6986000)
libffi.so.6 => /usr/lib/x86_64-linux-gnu/libffi.so.6 (0x00007fccb677e000)
/lib64/ld-linux-x86-64.so.2 (0x000055b505ff6000)
libgmodule-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libgmodule-2.0.so.0 (0x00007fccb6579000)
libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fccb6270000)
libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007fccb6056000)
libselinux.so.1 => /lib/x86_64-linux-gnu/libselinux.so.1 (0x00007fccb5e33000)
libresolv.so.2 => /lib/x86_64-linux-gnu/libresolv.so.2 (0x00007fccb5c18000)
libpcre.so.3 => /lib/x86_64-linux-gnu/libpcre.so.3 (0x00007fccb59a8000)
libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007fccb57a3000)
```

執行

``` sh
$ objdump -p app | grep NEEDED
```

顯示

```
NEEDED               libnotify.so.4
NEEDED               libgobject-2.0.so.0
NEEDED               libpthread.so.0
NEEDED               libc.so.6
```


## manpage

* $ man [gcc](http://manpages.ubuntu.com/manpages/xenial/en/man1/gcc.1.html)
* $ man [pkg-config](http://manpages.ubuntu.com/manpages/xenial/en/man1/pkg-config.1.html)
