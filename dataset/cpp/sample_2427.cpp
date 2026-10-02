#include <iostream>
#include <vector>

std::vector<std::vector<double>> transform_sequence(std::vector<std::vector<double>>& points, std::vector<std::vector<double>>& transformations) {
    for (auto& point : points) {
        for (const auto& transform : transformations) {
            double x = transform[0] * point[0] + transform[1] * point[1] + transform[2] * point[2] + transform[3];
            double y = transform[4] * point[0] + transform[5] * point[1] + transform[6] * point[2] + transform[7];
            double z = transform[8] * point[0] + transform[9] * point[1] + transform[10] * point[2] + transform[11];
            point[0] = x;
            point[1] = y;
            point[2] = z;
        }
    }
    return points;
}

int main() {
    std::vector<std::vector<double>> points = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<double>> transformations = {{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 3}};
    std::vector<std::vector<double>> result = transform_sequence(points, transformations);

    for (const auto& point : result) {
        std::cout << "[" << point[0] << ", " << point[1] << ", " << point[2] << "]" << std::endl;
    }

    return 0;
}