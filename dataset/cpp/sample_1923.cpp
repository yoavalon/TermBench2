#include <iostream>
#include <vector>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double rad = std::radians(angle);
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

std::vector<std::tuple<double, double, double>> apply_transformation(const std::vector<std::tuple<double, double, double>>& data, double angle) {
    std::vector<std::tuple<double, double, double>> transformed_data;
    for (const auto& [x, y, z] : data) {
        transformed_data.push_back(transform_coordinates(x, y, z, angle));
    }
    return transformed_data;
}

int main() {
    std::vector<std::tuple<double, double, double>> data = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 90;
    std::vector<std::tuple<double, double, double>> result = apply_transformation(data, angle);
    for (const auto& [x, y, z] : result) {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
    return 0;
}