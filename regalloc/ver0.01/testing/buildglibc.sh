#!/bin/sh

touch massif.txt
rm massif*
gcc main.c -o main
valgrind --tool=massif main $1
ms_print massif*
