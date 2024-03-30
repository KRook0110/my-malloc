#!/bin/bash

echo "started compiling"
gcc -o main main.c my_malloc.c
echo "finished compiling"
./main

