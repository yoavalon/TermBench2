#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& weights, const std::vector<std::vector<double>>& bias, const std::vector<std::vector<double>>& input_data) {
    std::vector<std::vector<double>> layer1(weights.size(), std::vector<double>(input_data[0].size()));
    std::vector<std::vector<double>> output(weights.size(), std::vector<double>(input_data[0].size()));

    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < input_data[0].size(); ++j) {
            layer1[i][j] = 0.0;
            for (size_t k = 0; k < input_data.size(); ++k) {
                layer1[i][j] += weights[i][k] * input_data[k][j];
            }
            layer1[i][j] += bias[i][j];
            output[i][j] = sigmoid(layer1[i][j]);
        }
    }

    return output;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<std::vector<double>> weights(3, std::vector<double>(4));
    std::vector<std::vector<double>> bias(1, std::vector<double>(4));
    std::vector<std::vector<double>> input_data(4, std::vector<double>(3));

    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < weights[i].size(); ++j) {
            weights[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }

    for (size_t i = 0; i < bias.size(); ++i) {
        for (size_t j = 0; j < bias[i].size(); ++j) {
            bias[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }

    for (size_t i = 0; i < input_data.size(); ++i) {
        for (size_t j = 0; j < input_data[i].size(); ++j) {
            input_data[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }

    std::vector<std::vector<double>> result = forward_pass(weights, bias, input_data);

    for (const auto& row : result) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}