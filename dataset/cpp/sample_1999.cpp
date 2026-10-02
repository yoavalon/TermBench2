#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

std::vector<double> forward_pass(const std::vector<std::vector<double>>& weights, 
                                const std::vector<double>& biases, 
                                const std::vector<double>& inputs) {
    std::vector<double> z(weights.size(), 0.0);
    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < inputs.size(); ++j) {
            z[i] += weights[i][j] * inputs[j];
        }
        z[i] += biases[i];
        z[i] = sigmoid(z[i]);
    }
    return z;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    std::vector<std::vector<double>> weights(10, std::vector<double>(5));
    for (auto& row : weights) {
        for (auto& elem : row) {
            elem = d(gen);
        }
    }

    std::vector<double> biases(10);
    for (auto& elem : biases) {
        elem = d(gen);
    }

    std::vector<double> inputs(5);
    for (auto& elem : inputs) {
        elem = d(gen);
    }

    std::vector<double> output = forward_pass(weights, biases, inputs);
    for (double o : output) {
        std::cout << o << " ";
    }
    std::cout << std::endl;
    return 0;
}