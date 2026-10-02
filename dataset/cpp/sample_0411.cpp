#include <iostream>
#include <vector>

std::vector<double> transform_coordinates(double x, double y, double z, const std::vector<std::vector<double>>& matrix) {
    std::vector<double> result(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == 0) {
                result[i] += x * matrix[i][j];
            } else if (j == 1) {
                result[i] += y * matrix[i][j];
            } else {
                result[i] += z * matrix[i][j];
            }
        }
    }
    return result;
}

std::vector<double> apply_transformation(int iterations) {
    std::vector<std::vector<double>> matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double x = 1, y = 1, z = 1;
    for (int _ = 0; _ < iterations; ++_) {
        std::vector<double> result = transform_coordinates(x, y, z, matrix);
        x = result[0];
        y = result[1];
        z = result[2];
        matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    }
    return {x, y, z};
}

int main() {
    while (true) {
        std::vector<double> result = apply_transformation(100);
        std::cout << "(" << result[0] << ", " << result[1] << ", " << result[2] << ")" << std::endl;
    }
    return 0;
}