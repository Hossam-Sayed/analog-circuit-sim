#include "CircuitSimulator.hpp"
#include <iostream>

CircuitSimulator::CircuitSimulator(const NetlistParser &parser)
    : netlist(parser) {}

void CircuitSimulator::constructMNASystem(Eigen::MatrixXd &A, Eigen::VectorXd &z)
{
    int n = netlist.getMaxNode(); // Nodes are numbered 1 to n
    int m = netlist.getVoltageSources().size();

    int size = n + m;
    A = Eigen::MatrixXd::Zero(size, size);
    z = Eigen::VectorXd::Zero(size);

    // Stamping Resistors
    for (const auto &r : netlist.getResistors())
    {
        int a = r.node1;
        int b = r.node2;
        double g = 1.0 / r.resistance;

        if (a != 0)
            A(a - 1, a - 1) += g;
        if (b != 0)
            A(b - 1, b - 1) += g;
        if (a != 0 && b != 0)
        {
            A(a - 1, b - 1) -= g;
            A(b - 1, a - 1) -= g;
        }
    }

    // Stamping Voltage Sources
    const auto &vsrcs = netlist.getVoltageSources();
    for (size_t k = 0; k < vsrcs.size(); ++k)
    {
        int a = vsrcs[k].node1;
        int b = vsrcs[k].node2;
        double v = vsrcs[k].voltage;

        int row = n + k;
        if (a != 0)
        {
            A(row, a - 1) = 1;
            A(a - 1, row) = 1;
        }
        if (b != 0)
        {
            A(row, b - 1) = -1;
            A(b - 1, row) = -1;
        }

        z(row) = v;
    }
}

void CircuitSimulator::solve()
{
    Eigen::MatrixXd A_dense;
    Eigen::VectorXd z;

    constructMNASystem(A_dense, z); // Use dense for easy stamping

    std::cout << "Solving A * x = z using SparseLU\n";

    // Convert dense A to sparse for SparseLU
    Eigen::SparseMatrix<double> A_sparse = A_dense.sparseView();

    // SparseLU Solver
    Eigen::SparseLU<Eigen::SparseMatrix<double>> solver;
    solver.analyzePattern(A_sparse);
    solver.factorize(A_sparse);

    Eigen::VectorXd x = solver.solve(z);

    if (solver.info() != Eigen::Success)
    {
        std::cerr << "Matrix solve failed!\n";
        return;
    }

    print(x, netlist.getMaxNode());
}

void CircuitSimulator::print(Eigen::VectorXd x, int n)
{
    std::cout << "Node Voltages:\n";
    for (int i = 0; i < n; ++i)
        std::cout << "V(" << (i + 1) << ") = " << x(i) << " V\n";

    std::cout << "Currents through Voltage Sources:\n";
    const auto &vsrcs = netlist.getVoltageSources();
    for (size_t i = 0; i < vsrcs.size(); ++i)
        std::cout << vsrcs[i].name << " current = " << x(n + i) << " A\n";
}
