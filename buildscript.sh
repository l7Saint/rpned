#!/bin/bash
[[ $1 == "--debug" ]] && FLAGS="-g3 -O0 -fsanitize=address -Wall --std=c99" || FLAGS="-g0 -O2 --std=c99"
clang $FLAGS -lm main.c stack.c -o build.o
[[ $? == 0 ]] && ./build.o || echo "Compilation error, not executing build."
