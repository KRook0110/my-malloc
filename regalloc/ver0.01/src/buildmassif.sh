#!/bin/sh

touch massif.txt
rm massif*
gcc -o regalloc ./regalloc.c
valgrind --tool=massif regalloc $1
ms_print massif*

