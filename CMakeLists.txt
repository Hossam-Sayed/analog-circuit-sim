cmake_minimum_required(VERSION 3.10)
project(AnalogCircuitSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include public headers
include_directories(include)

# Find Eigen3
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# List source files
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

# Build executable
add_executable(simulator ${SRC_FILES})
