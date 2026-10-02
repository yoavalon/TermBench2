#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> transform_point(const std::vector<std::vector<double>>& matrix, const std::vector<double>& point) {
    std::vector<double> result(3, 0.0);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            result[i] += matrix[i][j] * point[j];
        }
    }
    return result;
}

std::vector<std::vector<double>> generate_rotation_matrix(double angle, char axis) {
    double c = std::cos(angle);
    double s = std::sin(angle);
    std::vector<std::vector<double>> matrix(3, std::vector<double>(3, 0.0));
    if (axis == 'x') {
        matrix[0][0] = 1;
        matrix[1][1] = c;
        matrix[1][2] = -s;
        matrix[2][1] = s;
        matrix[2][2] = c;
    } else if (axis == 'y') {
        matrix[0][0] = c;
        matrix[0][2] = s;
        matrix[1][1] = 1;
        matrix[2][0] = -s;
        matrix[2][2] = c;
    } else if (axis == 'z') {
        matrix[0][0] = c;
        matrix[0][1] = -s;
        matrix[1][0] = s;
        matrix[1][1] = c;
        matrix[2][2] = 1;
    }
    return matrix;
}

int main() {
    std::vector<double> point = {1, 2, 3};
    double angle = M_PI / 4;
    std::vector<std::vector<double>> matrix = generate_rotation_matrix(angle, 'z');
    std::vector<double> transformed_point = transform_point(matrix, point);
    for (double val : transformed_point) {
        std::cout << val << " ";
    }
    return 0;
}