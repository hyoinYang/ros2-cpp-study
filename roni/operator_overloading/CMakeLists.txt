cmake_minimum_required(VERSION 4.0)
project(operator_overloading)

set(CMAKE_CXX_STANDARD 20)

add_executable(operator_overloading main.cpp
        cmake-build-debug/vect.h
        cmake-build-debug/vect.cpp
        cmake-build-debug/randwalk.cpp
        src/randwalk1.cpp)
