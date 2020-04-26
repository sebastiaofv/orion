#!/bin/bash

echo "Build cleanup... "

rm -rf ../_site/

echo "Start build process... "

gcc -std=c99 -Wall main.c -o main

./main

echo "Build complete!"

rm ./main

echo "Removed compiled main"


