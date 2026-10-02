#include <iostream>
#include <vector>

std::vector<std::vector<double>> neural_net_forward_pass(const std::vector<std::vector<double>>& matrix, const std::vector<std::vector<double>>& weights, const std::vector<double>& bias) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int weight_rows = weights.size();
    int weight_cols = weights[0].size();
    std::vector<std::vector<double>> x(rows, std::vector<double>(weight_cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < weight_cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                x[i][j] += matrix[i][k] * weights[k][j];
            }
            x[i][j] += bias[j];
            if (x[i][j] < 0) {
                x[i][j] = 0;
            }
        }
    }
    return x;
}

void main() {
    std::vector<std::vector<double>> mat = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> w = {{0.5, -0.5}, {-0.5, 0.5}};
    std::vector<double> b = {0.1, -0.1};
    std::vector<std::vector<double>> result = neural_net_forward_pass(mat, w, b);

    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}