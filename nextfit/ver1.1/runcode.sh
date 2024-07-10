#!/bin/bash

echo "Compiling Code"
gcc -o main ./main.c ./shamalloc_ver1.1.c ./memorypage.c ./utils.c
echo "Compiling Completed"
./main
