#include <iostream>
#include <vector>
#include <numeric>

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& matrix, const std::vector<std::vector<double>>& weights) {
    std::vector<std::vector<double>> result(matrix.size(), std::vector<double>(weights[0].size(), 0.0));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < weights[0].size(); ++j) {
            for (size_t k = 0; k < weights.size(); ++k) {
                result[i][j] += matrix[i][k] * weights[k][j];
            }
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<double>> data = {{1, 2}, {3, 4}, {5, 6}};
    std::vector<std::vector<double>> w = {{0.5, 0.5}, {0.5, 0.5}};
    std::vector<std::vector<double>> result = forward_pass(data, w);

    for (const auto& row : result) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}