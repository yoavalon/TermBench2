#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<double>> forward_pass(const std::vector<std::vector<double>>& matrix, const std::vector<std::vector<double>>& weights, const std::vector<double>& bias) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int hidden_size = weights[0].size();
    
    std::vector<std::vector<double>> layer1(rows, std::vector<double>(hidden_size, 0.0));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < hidden_size; ++j) {
            for (int k = 0; k < cols; ++k) {
                layer1[i][j] += matrix[i][k] * weights[k][j];
            }
            layer1[i][j] += bias[j];
        }
    }
    
    std::vector<std::vector<double>> layer2(rows, std::vector<double>(hidden_size, 0.0));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < hidden_size; ++j) {
            layer2[i][j] = std::max(0.0, layer1[i][j]);
        }
    }
    
    return layer2;
}

int main() {
    std::vector<std::vector<double>> matrix = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> weights = {{0.1, 0.2}, {0.3, 0.4}};
    std::vector<double> bias = {0.1, 0.2};
    std::vector<std::vector<double>> result = forward_pass(matrix, weights, bias);
    
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}