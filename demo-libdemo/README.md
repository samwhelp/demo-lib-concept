
## 原始討論

* [#13 回覆: 如何安裝 StarUML-v2.8.0-64-bit.deb ？](https://www.ubuntu-tw.org/modules/newbb/viewtopic.php?post_id=356984#forumpost356984)


## 參考連結

* [[心得] 用gcc 自製 Library](https://www.ptt.cc/bbs/LinuxDev/M.1162669989.A.2E6.html)


## 操作步驟

### lib-build.sh

執行

``` sh
$ ./lib-build.sh
```

執行

``` sh
$ ./app
```

顯示

```
./app: error while loading shared libraries: libdemo.so.1: cannot open shared object file: No such file or directory
```

執行

``` sh
LD_LIBRARY_PATH=. ./app
```

上面指令，編寫到「[run.sh](run.sh)」

所以也可以執行

```
$ ./run.sh
```

顯示

```
hello
hi
```

執行

``` sh
$ file libdemo.so.1
```

顯示

```
libdemo.so.1: symbolic link to libdemo.so.1.0.0
```

執行

``` sh
$ file libdemo.so.1.0.0
```

顯示

```
libdemo.so.1.0.0: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, BuildID[sha1]=686d1ff51b06b1aa8d9a46c5675d6189728153cc, not stripped
```

執行

``` sh
$ ldd libdemo.so.1.0.0
```

或是執行

``` sh
$ ldd libdemo.so.1
```

顯示

```
linux-vdso.so.1 =>  (0x00007ffcb3bd7000)
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f66f9434000)
/lib64/ld-linux-x86-64.so.2 (0x000055bb9a972000)
```

執行

``` sh
$ objdump -p libdemo.so.1 | grep SONAME
```

或是執行

``` sh
$ objdump -p libdemo.so.1.0.0 | grep SONAME
```

顯示

```
SONAME               libdemo.so.1
```

### main-build.sh

執行

``` sh
$ ./main-build.sh
```

執行

``` sh
$ file app
```

顯示

```
app: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=dbdd369cbe33194ac5131581980bbb6465326be7, not stripped
```

執行

``` sh
$ ldd app
```

顯示

```
linux-vdso.so.1 =>  (0x00007ffc670b4000)
libdemo.so.1 => not found
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f89d11bb000)
/lib64/ld-linux-x86-64.so.2 (0x00005646e9ea8000)
```

執行

``` sh
$ objdump -p app | grep NEEDED
```

顯示

```
NEEDED               libdemo.so.1
NEEDED               libc.so.6
```


## manpage

* $ man [ldd](http://manpages.ubuntu.com/manpages/xenial/en/man1/ldd.1.html)
* $ man [ldconfig](http://manpages.ubuntu.com/manpages/xenial/en/man8/ldconfig.8.html)
* $ man [ld.so](http://manpages.ubuntu.com/manpages/xenial/en/man8/ld.so.8.html)
* $ man [objdump](http://manpages.ubuntu.com/manpages/xenial/en/man1/objdump.1.html)
