#include <iostream>
#include <vector>

std::vector<std::vector<double>> transform_coordinates(const std::vector<std::vector<double>>& coords, const std::vector<std::vector<double>>& matrix) {
    std::vector<std::vector<double>> result(coords.size(), std::vector<double>(matrix[0].size(), 0));
    for (size_t i = 0; i < coords.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            for (size_t k = 0; k < matrix.size(); ++k) {
                result[i][j] += coords[i][k] * matrix[k][j];
            }
        }
    }
    return result;
}

void print_matrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<double>> coords = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<double>> matrix = {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
    std::vector<std::vector<double>> result = transform_coordinates(coords, matrix);
    print_matrix(result);
    return 0;
}