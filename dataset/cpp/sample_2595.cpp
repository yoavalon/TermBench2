#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> rotate_point(const std::vector<double>& point, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    std::vector<std::vector<double>> rotation_matrix = {
        {cos_a, -sin_a, 0},
        {sin_a, cos_a, 0},
        {0, 0, 1}
    };
    std::vector<double> rotated_point(3, 0);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            rotated_point[i] += rotation_matrix[i][j] * point[j];
        }
    }
    return {rotated_point};
}

std::vector<double> translate_point(const std::vector<double>& point, const std::vector<double>& vector) {
    std::vector<double> translated_point(3, 0);
    for (size_t i = 0; i < 3; ++i) {
        translated_point[i] = point[i] + vector[i];
    }
    return translated_point;
}

std::vector<std::vector<double>> transform_sequence(const std::vector<std::vector<double>>& points, const std::vector<double>& angles, const std::vector<double>& vector) {
    std::vector<std::vector<double>> transformed_points;
    for (size_t i = 0; i < points.size(); ++i) {
        auto rotated_point = rotate_point(points[i], angles[i]);
        auto translated_point = translate_point(rotated_point[0], vector);
        transformed_points.push_back(translated_point);
    }
    return transformed_points;
}

int main() {
    std::vector<std::vector<double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<double> angles = {M_PI / 4, M_PI / 3, M_PI / 2};
    std::vector<double> vector = {1, 1, 1};
    auto result = transform_sequence(points, angles, vector);
    for (const auto& point : result) {
        for (double coord : point) {
            std::cout << coord << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}