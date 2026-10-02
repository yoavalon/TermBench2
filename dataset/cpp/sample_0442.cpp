#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<double> activation(const std::vector<double>& x) {
    std::vector<double> result(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        result[i] = std::max(0.0, x[i]);
    }
    return result;
}

std::vector<double> forward_pass(const std::vector<std::vector<double>>& weights, 
                                 const std::vector<double>& biases, 
                                 const std::vector<double>& inputs) {
    std::vector<double> z(biases.size(), 0.0);
    for (size_t i = 0; i < biases.size(); ++i) {
        for (size_t j = 0; j < inputs.size(); ++j) {
            z[i] += weights[i][j] * inputs[j];
        }
        z[i] += biases[i];
    }
    return activation(z);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::vector<double>> weights(10, std::vector<double>(10));
    std::vector<double> biases(10);
    std::vector<double> inputs(10);

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            weights[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
        biases[i] = static_cast<double>(std::rand()) / RAND_MAX;
        inputs[i] = static_cast<double>(std::rand()) / RAND_MAX;
    }

    while (true) {
        std::vector<double> outputs = forward_pass(weights, biases, inputs);
        inputs = outputs;
    }

    return 0;
}