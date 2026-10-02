#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> matrix_multiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();
    std::vector<std::vector<double>> result(rows_A, std::vector<double>(cols_B, 0.0));
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < cols_A; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<double>> rotation_matrix(double angle) {
    double cos_theta = std::cos(angle);
    double sin_theta = std::sin(angle);
    return {{cos_theta, -sin_theta, 0.0}, {sin_theta, cos_theta, 0.0}, {0.0, 0.0, 1.0}};
}

std::vector<double> transform_point(const std::vector<double>& point, const std::vector<std::vector<double>>& matrix) {
    double x = point[0];
    double y = point[1];
    double z = point[2];
    std::vector<std::vector<double>> transformed = matrix_multiply(matrix, {{x}, {y}, {z}});
    return {transformed[0][0], transformed[1][0], transformed[2][0]};
}

void continuous_rotation(const std::vector<double>& point, double angle_step) {
    double angle = 0.0;
    while (true) {
        std::vector<std::vector<double>> rotation = rotation_matrix(angle);
        std::vector<double> new_point = transform_point(point, rotation);
        std::cout << new_point[0] << " " << new_point[1] << " " << new_point[2] << std::endl;
        angle += angle_step;
    }
}

int main() {
    std::vector<double> point = {1.0, 0.0, 0.0};
    double angle_step = 0.1;
    continuous_rotation(point, angle_step);
    return 0;
}