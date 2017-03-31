#!/usr/bin/env sh

gcc -o app main.c $(pkg-config --cflags --libs libnotify)
