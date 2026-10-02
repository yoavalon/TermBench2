#include <iostream>
#include <vector>

std::vector<std::vector<double>> transform_coordinates(const std::vector<std::vector<double>>& points, const std::vector<std::vector<double>>& matrix) {
    std::vector<std::vector<double>> transformed;
    for (const auto& point : points) {
        double x = point[0];
        double y = point[1];
        double z = point[2];
        double tx = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        double ty = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        double tz = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push_back({tx, ty, tz});
    }
    return transformed;
}

int main() {
    std::vector<std::vector<double>> transformation_matrix = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    std::vector<std::vector<double>> points_list = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> result = transform_coordinates(points_list, transformation_matrix);

    for (const auto& point : result) {
        std::cout << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")\n";
    }

    return 0;
}