#include <iostream>
#include <vector>
#include <cmath>

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

std::vector<double> forward_pass(const std::vector<std::vector<double>>& weights, 
                                 const std::vector<double>& biases, 
                                 const std::vector<double>& input_data) {
    std::vector<double> x(weights.size());
    for (size_t i = 0; i < weights.size(); ++i) {
        x[i] = 0;
        for (size_t j = 0; j < input_data.size(); ++j) {
            x[i] += weights[i][j] * input_data[j];
        }
        x[i] += biases[i];
    }
    for (size_t i = 0; i < x.size(); ++i) {
        x[i] = sigmoid(x[i]);
    }
    return x;
}

void recursive_forward(const std::vector<std::vector<double>>& weights, 
                       const std::vector<double>& biases, 
                       const std::vector<double>& input_data) {
    std::vector<double> output = forward_pass(weights, biases, input_data);
    recursive_forward(weights, biases, output);
}

int main() {
    std::vector<std::vector<double>> weights(10, std::vector<double>(10));
    std::vector<double> biases(10);
    std::vector<double> input_data(10);

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            weights[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
        biases[i] = static_cast<double>(rand()) / RAND_MAX;
        input_data[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    recursive_forward(weights, biases, input_data);
    return 0;
}