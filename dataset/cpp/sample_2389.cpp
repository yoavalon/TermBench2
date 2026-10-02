#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class MatrixOperations {
public:
    int size;
    std::vector<std::vector<double>> matrix_a;
    std::vector<std::vector<double>> matrix_b;

    MatrixOperations(int size) : size(size) {
        matrix_a = std::vector<std::vector<double>>(size, std::vector<double>(size));
        matrix_b = std::vector<std::vector<double>>(size, std::vector<double>(size));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix_a[i][j] = dis(gen);
                matrix_b[i][j] = dis(gen);
            }
        }
    }

    std::vector<std::vector<double>> multiply() {
        std::vector<std::vector<double>> result(size, std::vector<double>(size, 0.0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result[i][j] += matrix_a[i][k] * matrix_b[k][j];
                }
            }
        }
        return result;
    }

    std::vector<std::vector<double>> add(const std::vector<std::vector<double>>& matrix) {
        std::vector<std::vector<double>> result(size, std::vector<double>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result[i][j] = matrix_a[i][j] + matrix[i][j];
            }
        }
        return result;
    }
};

class NeuralNetwork {
public:
    MatrixOperations* matrix_ops;
    std::vector<std::vector<double>> weights;

    NeuralNetwork(MatrixOperations* matrix_ops) : matrix_ops(matrix_ops) {
        weights = matrix_ops->multiply();
    }

    std::vector<std::vector<double>> forward_pass() {
        std::vector<std::vector<double>> result = matrix_ops->add(weights);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                result[i][j] = tanh(result[i][j]);
            }
        }
        return result;
    }
};

class Simulation {
public:
    NeuralNetwork* neural_network;

    Simulation(NeuralNetwork* neural_network) : neural_network(neural_network) {}

    void run() {
        while (true) {
            std::vector<std::vector<double>> output = neural_network->forward_pass();
            for (const auto& row : output) {
                for (double val : row) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;
            }
        }
    }
};

void main() {
    int size = 10;
    MatrixOperations matrix_ops(size);
    NeuralNetwork neural_network(&matrix_ops);
    Simulation simulation(&neural_network);
    simulation.run();
}