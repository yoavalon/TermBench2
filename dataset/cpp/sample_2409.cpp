#include <iostream>
#include <vector>

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& matrix, const std::vector<std::vector<double>>& weights) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int weightCols = weights[0].size();
    std::vector<std::vector<double>> result(rows, std::vector<double>(weightCols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < weightCols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result[i][j] += matrix[i][k] * weights[k][j];
            }
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<double>> matrix = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<std::vector<double>> weights = {{0.5, 0.5}, {0.5, 0.5}};
    std::vector<std::vector<double>> result = forward_pass(matrix, weights);

    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}