#!/bin/sh

touch massif.txt
rm massif*
gcc main.c -o main -L`jemalloc-config --libdir` -Wl,-rpath,`jemalloc-config --libdir` -ljemalloc `jemalloc-config --libs`
valgrind --tool=massif main $1
ms_print massif*
