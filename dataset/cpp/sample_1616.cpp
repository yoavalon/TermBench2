#include <vector>
#include <array>

std::array<double, 3> transform_coordinates(double x, double y, double z, const std::vector<std::vector<double>>& matrix) {
    return {
        matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3],
        matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3],
        matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
    };
}

std::vector<std::array<double, 3>> apply_transformation(const std::vector<std::array<double, 3>>& data, const std::vector<std::vector<double>>& transformation_matrix) {
    std::vector<std::array<double, 3>> result;
    for (const auto& point : data) {
        auto transformed_point = transform_coordinates(point[0], point[1], point[2], transformation_matrix);
        result.push_back(transformed_point);
    }
    return result;
}

void main() {
    std::vector<std::array<double, 3>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> matrix = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    while (true) {
        auto transformed_data = apply_transformation(data, matrix);
        data = transformed_data;
    }
}