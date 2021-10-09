cmake_minimum_required(VERSION 3.17)
project(modeling)

set(CMAKE_CXX_STANDARD 20)

add_executable(modeling main.cpp spiral/state_.cpp spiral/state_.h spiral/code.cpp harmonic/code.cpp spiral/code.h spiral/KahanFloat.h spiral/KahanFloat.cpp spiral/State.h)
