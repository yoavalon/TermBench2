#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class CoordinateTransformer {
public:
    std::vector<std::tuple<double, double, double>> points;
    std::vector<std::tuple<double, double, double>> transformations;

    void add_point(double x, double y, double z) {
        points.push_back(std::make_tuple(x, y, z));
    }

    void apply_rotation(double angle_x, double angle_y, double angle_z) {
        double cos_x = std::cos(angle_x);
        double sin_x = std::sin(angle_x);
        double cos_y = std::cos(angle_y);
        double sin_y = std::sin(angle_y);
        double cos_z = std::cos(angle_z);
        double sin_z = std::sin(angle_z);
        std::vector<std::vector<double>> rotation_matrix = {
            {cos_y * cos_z, cos_y * sin_z, -sin_y},
            {sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y},
            {cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y}
        };
        std::vector<std::tuple<double, double, double>> new_points;
        for (const auto& point : points) {
            double x, y, z;
            std::tie(x, y, z) = point;
            double new_x = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
            double new_y = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
            double new_z = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
            new_points.push_back(std::make_tuple(new_x, new_y, new_z));
        }
        points = new_points;
    }

    void apply_translation(double dx, double dy, double dz) {
        std::vector<std::tuple<double, double, double>> new_points;
        for (const auto& point : points) {
            double x, y, z;
            std::tie(x, y, z) = point;
            new_points.push_back(std::make_tuple(x + dx, y + dy, z + dz));
        }
        points = new_points;
    }
};

std::vector<std::tuple<double, double, double>> generate_points() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);
    std::vector<std::tuple<double, double, double>> points;
    for (int i = 0; i < 100; ++i) {
        points.push_back(std::make_tuple(dis(gen), dis(gen), dis(gen)));
    }
    return points;
}

void main() {
    CoordinateTransformer transformer;
    auto points = generate_points();
    for (const auto& point : points) {
        double x, y, z;
        std::tie(x, y, z) = point;
        transformer.add_point(x, y, z);
    }
    transformer.apply_rotation(0.5, 0.3, 0.2);
    transformer.apply_translation(5, 5, 5);
    while (true) {
        transformer.apply_rotation(0.01, 0.02, 0.03);
        transformer.apply_translation(0.1, 0.1, 0.1);
    }
}