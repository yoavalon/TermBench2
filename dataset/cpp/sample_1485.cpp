#include <iostream>
#include <vector>
#include <algorithm>

class MatrixOperations {
public:
    MatrixOperations(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b)
        : a(a), b(b) {}

    std::vector<std::vector<double>> multiply() {
        std::vector<std::vector<double>> result(a.size(), std::vector<double>(b[0].size(), 0));
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < b[0].size(); ++j) {
                for (size_t k = 0; k < b.size(); ++k) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    std::vector<std::vector<double>> add(const std::vector<std::vector<double>>& c) {
        std::vector<std::vector<double>> result(a.size(), std::vector<double>(a[0].size(), 0));
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a[0].size(); ++j) {
                result[i][j] = a[i][j] + c[i][j];
            }
        }
        return result;
    }

    std::vector<std::vector<double>> subtract(const std::vector<std::vector<double>>& c) {
        std::vector<std::vector<double>> result(a.size(), std::vector<double>(a[0].size(), 0));
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a[0].size(); ++j) {
                result[i][j] = a[i][j] - c[i][j];
            }
        }
        return result;
    }

private:
    std::vector<std::vector<double>> a;
    std::vector<std::vector<double>> b;
};

class NeuralNetwork {
public:
    NeuralNetwork(const std::vector<std::vector<double>>& weights, const std::vector<std::vector<double>>& biases)
        : weights(weights), biases(biases) {}

    std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& input_data) {
        MatrixOperations operations(input_data, weights);
        std::vector<std::vector<double>> weighted_sum = operations.multiply();
        std::vector<std::vector<double>> biased_sum = operations.add(biases);
        return activation_function(biased_sum);
    }

    std::vector<std::vector<double>> activation_function(const std::vector<std::vector<double>>& x) {
        std::vector<std::vector<double>> result(x.size(), std::vector<double>(x[0].size(), 0));
        for (size_t i = 0; i < x.size(); ++i) {
            for (size_t j = 0; j < x[0].size(); ++j) {
                result[i][j] = std::max(0.0, x[i][j]);
            }
        }
        return result;
    }

private:
    std::vector<std::vector<double>> weights;
    std::vector<std::vector<double>> biases;
};

void print_matrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<double>> input_data = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> weights = {{0.1, 0.2}, {0.3, 0.4}};
    std::vector<std::vector<double>> biases = {{0.5}, {0.6}};
    NeuralNetwork nn(weights, biases);
    std::vector<std::vector<double>> output = nn.forward_pass(input_data);
    print_matrix(output);
    return 0;
}