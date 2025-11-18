cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름과 C++ 표준 지정
project(RandWalkProject)
set(CMAKE_CXX_STANDARD 17)

# 실행 파일과 소스 파일 지정
add_executable(hangman
    hangman.cpp
)
