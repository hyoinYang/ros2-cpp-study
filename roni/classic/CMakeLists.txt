cmake_minimum_required(VERSION 4.0)
project(classic)

set(CMAKE_CXX_STANDARD 20)

add_executable(classic main.cpp
        classic.h
        classic.cpp)
