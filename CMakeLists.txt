cmake_minimum_required(VERSION 3.17)
project(modeling)

set(CMAKE_CXX_STANDARD 20)

add_executable(modeling
        main.cpp
        spiral/code.cpp spiral/code.h
        harmonic/code.cpp
        spiral/KahanFloat.h spiral/KahanFloat.cpp
        spiral/State.h spiral/StateNew.h
        )
