#!/bin/bash

g++ main.cpp -o ArrayToBmp.out
g++ generator.cpp -o Generator.out
g++ check.cpp -o Check.out

./Generator.out
./ArrayToBmp.out

timeout 1s eog image.bmp
