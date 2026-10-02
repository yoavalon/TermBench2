#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& weights, const std::vector<std::vector<double>>& inputs, const std::vector<std::vector<double>>& bias) {
    while (true) {
        std::vector<std::vector<double>> outputs(weights.size(), std::vector<double>(inputs[0].size()));
        for (size_t i = 0; i < weights.size(); ++i) {
            for (size_t j = 0; j < inputs[0].size(); ++j) {
                outputs[i][j] = bias[i][j];
                for (size_t k = 0; k < inputs.size(); ++k) {
                    outputs[i][j] += weights[i][k] * inputs[k][j];
                }
            }
        }
        inputs = outputs;
    }
    return inputs; // This return is just to make the function compilable, it won't be reached due to the infinite loop.
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> weights(3, std::vector<double>(3));
    std::vector<std::vector<double>> inputs(3, std::vector<double>(1));
    std::vector<std::vector<double>> bias(3, std::vector<double>(1));

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            weights[i][j] = dis(gen);
        }
        inputs[i][0] = dis(gen);
        bias[i][0] = dis(gen);
    }

    forward_pass(weights, inputs, bias);
    return 0;
}