cmake_minimum_required(VERSION 4.0)
project(randwalk2)

set(CMAKE_CXX_STANDARD 20)

add_executable(randwalk2 randwalk2.cpp
        vect1.h
        vect1.cpp)
