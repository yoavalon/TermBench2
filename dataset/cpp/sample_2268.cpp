#include <iostream>
#include <vector>

std::vector<double> transform_coordinates(const std::vector<double>& point, const std::vector<std::vector<double>>& matrix) {
    std::vector<double> result(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i] += point[j] * matrix[i][j];
        }
    }
    return result;
}

std::vector<std::vector<double>> apply_transformation(const std::vector<std::vector<double>>& points, const std::vector<std::vector<double>>& matrix) {
    std::vector<std::vector<double>> transformed_points;
    for (const auto& point : points) {
        transformed_points.push_back(transform_coordinates(point, matrix));
    }
    return transformed_points;
}

int main() {
    std::vector<std::vector<double>> points = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<std::vector<double>> matrix = {{0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}, {0.7, 0.8, 0.9}};
    while (true) {
        points = apply_transformation(points, matrix);
    }
    return 0;
}