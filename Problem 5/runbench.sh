#!/bin/bash

sizes=(128 256 512 1024 2048)

echo "Compiling..."
gcc -O2 loopsstaticshell.c -o loopsstatic
gcc -O2 loopsdynamicshell.c -o loopsdynamic

echo "Starting benchmark..."

for n in "${sizes[@]}"
do
    echo "=============================="
    echo "Matrix size: $n"
    echo "---- Static ----"
    ./loopsstatic $n
    echo "---- Dynamic ----"
    ./loopsdynamic $n
done
