#!/bin/bash

clang -g -O0 -fsanitize=address -Wall --std=c99 main.c stack.c -o build.o
[[ $? == 0 ]] && ./build.o || echo "Compilation error, not executing build."
