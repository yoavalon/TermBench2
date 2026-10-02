#include <iostream>
#include <vector>

std::vector<std::vector<int>> transform_coordinates(const std::vector<std::vector<int>>& coords, const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> result(coords.size(), std::vector<int>(matrix[0].size()));
    for (size_t i = 0; i < coords.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            int sum = 0;
            for (size_t k = 0; k < matrix.size(); ++k) {
                sum += coords[i][k] * matrix[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

void main() {
    std::vector<std::vector<int>> coords = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> matrix = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> result = transform_coordinates(coords, matrix);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}