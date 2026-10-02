#include <iostream>
#include <vector>
#include <random>
#include <numeric>

std::vector<double> forward_pass(const std::vector<std::vector<double>>& weights, 
                                  const std::vector<double>& biases, 
                                  const std::vector<double>& inputs, 
                                  int depth) {
    if (depth == 0) {
        return inputs;
    }
    std::vector<double> next_inputs(weights.size(), 0.0);
    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < inputs.size(); ++j) {
            next_inputs[i] += inputs[j] * weights[j][i];
        }
        next_inputs[i] += biases[i];
    }
    return forward_pass(weights, biases, next_inputs, depth - 1);
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> weights(3, std::vector<double>(3));
    std::vector<double> biases(3);
    std::vector<double> inputs(3);

    for (auto& w : weights) {
        std::generate(w.begin(), w.end(), [&dis, &gen]() { return dis(gen); });
    }
    std::generate(biases.begin(), biases.end(), [&dis, &gen]() { return dis(gen); });
    std::generate(inputs.begin(), inputs.end(), [&dis, &gen]() { return dis(gen); });

    std::vector<double> result = forward_pass(weights, biases, inputs, 3);

    for (double res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}