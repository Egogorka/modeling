cmake_minimum_required(VERSION 3.17)
project(modeling)

set(CMAKE_CXX_STANDARD 20)

add_executable(modeling
        main.cpp
        spiral/code.cpp spiral/code.h
        harmonic/code.cpp
        code/KahanFloat.h code/KahanFloat.cpp
        spiral/State.h
        code/Vector.h code/ODE.h code/Writer.cpp code/Writer.h code/typedefs.h code/odes/MathPendulum.h)

include_directories(code)