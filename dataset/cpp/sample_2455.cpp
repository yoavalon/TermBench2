#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<double>> dot(const std::vector<std::vector<double>>& matrix, const std::vector<double>& weights) {
    std::vector<std::vector<double>> result(matrix.size(), std::vector<double>(1));
    for (size_t i = 0; i < matrix.size(); ++i) {
        result[i][0] = 0.0;
        for (size_t j = 0; j < weights.size(); ++j) {
            result[i][0] += matrix[i][j] * weights[j];
        }
    }
    return result;
}

std::vector<std::vector<double>> addBias(const std::vector<std::vector<double>>& matrix, double bias) {
    std::vector<std::vector<double>> result = matrix;
    for (size_t i = 0; i < result.size(); ++i) {
        result[i][0] += bias;
    }
    return result;
}

std::vector<std::vector<double>> relu(const std::vector<std::vector<double>>& matrix) {
    std::vector<std::vector<double>> result = matrix;
    for (size_t i = 0; i < result.size(); ++i) {
        result[i][0] = std::max(0.0, result[i][0]);
    }
    return result;
}

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& matrix, const std::vector<double>& weights, double bias) {
    auto x = dot(matrix, weights);
    x = addBias(x, bias);
    return relu(x);
}

int main() {
    std::vector<std::vector<double>> a = {{1, 2}, {3, 4}};
    std::vector<double> b = {0.5, -0.5};
    double c = 1.0;
    auto result = forward_pass(a, b, c);
    for (const auto& row : result) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}