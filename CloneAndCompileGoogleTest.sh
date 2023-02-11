#!/bin/bash

git clone https://github.com/google/googletest.git

# compiling google test
cd googletest
cmake -E make_directory build
#cmake -E chdir build/ cmake -DCMAKE_CXX_FLAGS=-std=c++11 -Dgtest_build_samples=ON ..
cmake -E chdir build/ cmake -Dgtest_build_samples=ON ..
cmake --build build/ --parallel 4

# install
cd build/
make install