#!/usr/bin/env sh

gcc -c -fPIC hello.c hi.c

gcc -shared -Wl,-soname,libdemo.so.1 -o libdemo.so.1.0.0 hello.o hi.o

ln -sf libdemo.so.1.0.0 libdemo.so.1
