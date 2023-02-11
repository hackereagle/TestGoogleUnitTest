#!/bin/bash

rm -r build
mkdir build
time cmake -E chdir build/ cmake -DCMAKE_BUILD_TYPE=Debug ..
time cmake --build build/