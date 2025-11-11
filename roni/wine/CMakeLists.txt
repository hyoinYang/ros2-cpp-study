cmake_minimum_required(VERSION 4.0)
project(wine)

set(CMAKE_CXX_STANDARD 20)

add_executable(wine main.cpp
        winec.h
        winec.cpp)
