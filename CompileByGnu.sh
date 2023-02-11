#!/bin/bash

g++ main.cpp -o TestGoogleUnitTest -std=c++17 -lgtest -lpthread

# if you would like to use gcc please using
#gcc main.cpp -o TestGoogleUnitTest -std=c++14 -lstdc++ -lgtest -lpthread