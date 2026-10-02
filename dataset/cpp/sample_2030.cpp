#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class MatrixProcessor {
public:
    MatrixProcessor(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    std::vector<std::vector<double>> normalize() {
        double max_val = 0;
        for (const auto& row : matrix) {
            for (double val : row) {
                if (val > max_val) {
                    max_val = val;
                }
            }
        }
        for (auto& row : matrix) {
            for (double& val : row) {
                val /= max_val;
            }
        }
        return matrix;
    }

    std::vector<std::vector<double>> apply_activation(const std::function<std::vector<std::vector<double>>(const std::vector<std::vector<double>>&)> activation_func) {
        matrix = activation_func(matrix);
        return matrix;
    }

private:
    std::vector<std::vector<double>> matrix;
};

class NeuralNetwork {
public:
    NeuralNetwork(const std::vector<std::function<std::vector<std::vector<double>>(const std::vector<std::vector<double>>&)>>& layers) : layers(layers) {}

    std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& input_data) {
        std::vector<std::vector<double>> output = input_data;
        for (const auto& layer : layers) {
            output = layer(output);
        }
        return output;
    }

private:
    std::vector<std::function<std::vector<std::vector<double>>(const std::vector<std::vector<double>>&)>> layers;
};

class ActivationFunctions {
public:
    static std::vector<std::vector<double>> sigmoid(const std::vector<std::vector<double>>& x) {
        std::vector<std::vector<double>> result(x.size(), std::vector<double>(x[0].size()));
        for (size_t i = 0; i < x.size(); ++i) {
            for (size_t j = 0; j < x[i].size(); ++j) {
                result[i][j] = 1 / (1 + std::exp(-x[i][j]));
            }
        }
        return result;
    }

    static std::vector<std::vector<double>> relu(const std::vector<std::vector<double>>& x) {
        std::vector<std::vector<double>> result(x.size(), std::vector<double>(x[0].size()));
        for (size_t i = 0; i < x.size(); ++i) {
            for (size_t j = 0; j < x[i].size(); ++j) {
                result[i][j] = std::max(0.0, x[i][j]);
            }
        }
        return result;
    }
};

void main() {
    srand(0);
    std::vector<std::vector<double>> data(10, std::vector<double>(10));
    for (auto& row : data) {
        for (double& val : row) {
            val = static_cast<double>(rand()) / RAND_MAX;
        }
    }
    MatrixProcessor processor(data);
    auto normalized_data = processor.normalize();
    auto relu_output = processor.apply_activation(ActivationFunctions::relu);
    auto sigmoid_output = processor.apply_activation(ActivationFunctions::sigmoid);
    std::vector<std::function<std::vector<std::vector<double>>(const std::vector<std::vector<double>>&)>> layers = {
        [&relu_output](const std::vector<std::vector<double>>& x) { return relu_output; },
        [&sigmoid_output](const std::vector<std::vector<double>>& x) { return sigmoid_output; }
    };
    NeuralNetwork network(layers);
    auto result = network.forward_pass(normalized_data);
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}