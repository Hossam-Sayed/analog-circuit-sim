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

## Simulator Test

This simulator is tested againest NGSpice. The results were minimal (on the order of `1e-5` or better). To test the simulator, run the simulator using the following command on the `large_example.net` netlist file

```shell
sh run.sh
```

Then, install `ngspice` library using the following command:

```shell
sudo apt install ngspice
```

Then run ngspice simulator on the same file, then compare the outputs.

Note that: For NGSpice, you need to add the following commands to the end of the file:

```shell
.control
op
print all
.endc
.end
```