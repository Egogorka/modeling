cmake_minimum_required(VERSION 3.17)
project(modeling)

set(CMAKE_CXX_STANDARD 20)

add_executable(modeling
        main.cpp
        code/KahanFloat.h code/KahanFloat.cpp
        code/Vector.h
        code/ODE.h
        code/Writer.h
        code/typedefs.h
        code/odes/MathPendulum.h
        code/odes/PhysPendulum.h
        records/spiral/spiral.cpp
        records/spiral/spiral.h
        code/utilities.cpp
        code/utilities.h
        records/phys_pendulum/pendulum.cpp
        records/phys_pendulum/pendulum.h
        code/odes/PhysPendulumFriction.h records/phys_pendulum_friction/pendulum.cpp records/phys_pendulum_friction/pendulum.h code/odes/WaveTracing.h records/wave_tracing/tracing.cpp records/wave_tracing/tracing.h)

include_directories(code)