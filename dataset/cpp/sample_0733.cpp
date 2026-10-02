#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

std::vector<double> forward_pass(const std::vector<std::vector<double>>& weights, const std::vector<double>& inputs, const std::vector<double>& bias, int layers) {
    if (layers == 0) {
        return inputs;
    }
    std::vector<double> weighted_sum(inputs.size(), 0.0);
    for (size_t i = 0; i < inputs.size(); ++i) {
        for (size_t j = 0; j < inputs.size(); ++j) {
            weighted_sum[i] += weights[i][j] * inputs[j];
        }
        weighted_sum[i] += bias[i];
        weighted_sum[i] = sigmoid(weighted_sum[i]);
    }
    return forward_pass(weights, weighted_sum, bias, layers - 1);
}

int main() {
    std::srand(0);
    std::vector<std::vector<double>> weights(4, std::vector<double>(4));
    std::vector<double> inputs(4);
    std::vector<double> bias(4);
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            weights[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
        inputs[i] = static_cast<double>(std::rand()) / RAND_MAX;
        bias[i] = static_cast<double>(std::rand()) / RAND_MAX;
    }
    int layers = 3;
    std::vector<double> result = forward_pass(weights, inputs, bias, layers);
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}