cmake_minimum_required(VERSION 3.10)
project(AnalogCircuitSim)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(simulator
    main.cpp
    src/NetlistParser.cpp
    src/CircuitSimulator.cpp
)
