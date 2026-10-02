#include <iostream>
#include <vector>

std::vector<std::vector<int>> transform_sequence(const std::vector<std::vector<int>>& points, const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> result;
    for (const auto& point : points) {
        std::vector<int> transformed(matrix.size(), 0);
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < point.size(); ++j) {
                transformed[i] += matrix[i][j] * point[j];
            }
        }
        result.push_back(transformed);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> sequence = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> matrix = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    std::vector<std::vector<int>> transformed_sequence = transform_sequence(sequence, matrix);

    for (const auto& row : transformed_sequence) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}