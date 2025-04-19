# Analog Circuit Simulator

A simple Analog Circuit Simulator using C++.

## Setup

Install C++ and CMake

```shell
sudo apt update
sudo apt install build-essential cmake
```

Install `gdb` for debugging

```shell
sudo apt update
sudo apt install gdb
```

Verify installation

```shell
g++ --version
cmake --version
gdb --version
```

Install Eigen for solving matrices

```shell
sudo apt install libeigen3-dev
```

Build and Run the Project

```shell
cmake -S . -B build
cmake --build build
./build/simulator
```