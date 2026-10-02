#include <iostream>
#include <vector>

std::vector<std::vector<double>> matrix_multiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    if (A[0].size() != B.size()) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication.");
    }
    std::vector<std::vector<double>> result(A.size(), std::vector<double>(B[0].size(), 0.0));
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < B[0].size(); ++j) {
            for (size_t k = 0; k < B.size(); ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<std::vector<double>>>& weights, const std::vector<std::vector<double>>& inputs) {
    for (const auto& weight : weights) {
        inputs = matrix_multiply(weight, inputs);
    }
    return inputs;
}

int main() {
    std::vector<std::vector<std::vector<double>>> weights = {{{0.5, 0.2}, {0.1, 0.8}}, {{0.4, 0.6}, {0.7, 0.3}}};
    std::vector<std::vector<double>> inputs = {{1}, {2}};
    std::vector<std::vector<double>> output = forward_pass(weights, inputs);
    for (const auto& row : output) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}