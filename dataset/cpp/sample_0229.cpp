#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> matrix_multiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    std::vector<std::vector<double>> result(A.size(), std::vector<double>(B[0].size(), 0));
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < B[0].size(); ++j) {
            for (size_t k = 0; k < B.size(); ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

std::vector<double> translate_point(const std::vector<double>& point, const std::vector<double>& translation) {
    std::vector<std::vector<double>> translation_matrix = {
        {1, 0, 0, translation[0]},
        {0, 1, 0, translation[1]},
        {0, 0, 1, translation[2]},
        {0, 0, 0, 1}
    };
    std::vector<std::vector<double>> point_matrix = {
        {point[0]},
        {point[1]},
        {point[2]},
        {1}
    };
    std::vector<std::vector<double>> transformed_point = matrix_multiply(translation_matrix, point_matrix);
    return {transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]};
}

std::vector<double> rotate_point(const std::vector<double>& point, double angle, char axis) {
    double cos_angle = std::cos(angle);
    double sin_angle = std::sin(angle);
    std::vector<std::vector<double>> rotation_matrix;
    if (axis == 'x') {
        rotation_matrix = {
            {1, 0, 0, 0},
            {0, cos_angle, -sin_angle, 0},
            {0, sin_angle, cos_angle, 0},
            {0, 0, 0, 1}
        };
    } else if (axis == 'y') {
        rotation_matrix = {
            {cos_angle, 0, sin_angle, 0},
            {0, 1, 0, 0},
            {-sin_angle, 0, cos_angle, 0},
            {0, 0, 0, 1}
        };
    } else if (axis == 'z') {
        rotation_matrix = {
            {cos_angle, -sin_angle, 0, 0},
            {sin_angle, cos_angle, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };
    }
    std::vector<std::vector<double>> point_matrix = {
        {point[0]},
        {point[1]},
        {point[2]},
        {1}
    };
    std::vector<std::vector<double>> transformed_point = matrix_multiply(rotation_matrix, point_matrix);
    return {transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]};
}

std::vector<double> scale_point(const std::vector<double>& point, double scale) {
    std::vector<std::vector<double>> scaling_matrix = {
        {scale, 0, 0, 0},
        {0, scale, 0, 0},
        {0, 0, scale, 0},
        {0, 0, 0, 1}
    };
    std::vector<std::vector<double>> point_matrix = {
        {point[0]},
        {point[1]},
        {point[2]},
        {1}
    };
    std::vector<std::vector<double>> transformed_point = matrix_multiply(scaling_matrix, point_matrix);
    return {transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]};
}

int main() {
    std::vector<double> point = {1, 2, 3};
    std::vector<double> translation = {1, 1, 1};
    double angle = 30 * (3.14159 / 180);
    double scale_factor = 2;
    point = translate_point(point, translation);
    point = rotate_point(point, angle, 'z');
    point = scale_point(point, scale_factor);
    std::cout << point[0] << " " << point[1] << " " << point[2] << std::endl;
    return 0;
}