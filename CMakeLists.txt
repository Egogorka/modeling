cmake_minimum_required(VERSION 3.20)
project(modeling)

set(CMAKE_CXX_STANDARD 20)

add_executable(modeling main.cpp spiral/state.cpp spiral/state.h spiral/code.cpp harmonic/code.cpp spiral/code.h spiral/KahanFloat.h spiral/KahanFloat.cpp)
