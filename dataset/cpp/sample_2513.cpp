#include <iostream>
#include <vector>

std::vector<std::vector<double>> transform_point(double x, double y, double z, const std::vector<std::vector<double>>& matrix) {
    return {x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2],
            x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2],
            x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]};
}

std::vector<std::vector<double>> apply_sequence_transformations(const std::vector<std::vector<double>>& points, const std::vector<std::vector<std::vector<double>>>& sequence) {
    std::vector<std::vector<double>> result = points;
    for (const auto& matrix : sequence) {
        std::vector<std::vector<double>> new_points;
        for (const auto& point : result) {
            new_points.push_back(transform_point(point[0], point[1], point[2], matrix));
        }
        result = new_points;
    }
    return result;
}

int main() {
    std::vector<std::vector<double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<std::vector<double>>> sequence = {
        {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
        {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}},
        {{1, 0, 0}, {0, 1, 0}, {0, 0, -1}}
    };
    std::vector<std::vector<double>> transformed_points = apply_sequence_transformations(points, sequence);
    for (const auto& point : transformed_points) {
        std::cout << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")" << std::endl;
    }
    return 0;
}