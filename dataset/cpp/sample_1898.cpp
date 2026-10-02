#include <iostream>
#include <vector>

std::vector<double> transform_3d(const std::vector<double>& point, const std::vector<std::vector<double>>& matrix) {
    std::vector<double> result(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i] += point[j] * matrix[i][j];
        }
    }
    return result;
}

void main() {
    std::vector<double> point = {1.0, 2.0, 3.0};
    std::vector<std::vector<double>> matrix = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    std::vector<double> transformed = transform_3d(point, matrix);
    for (double value : transformed) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}