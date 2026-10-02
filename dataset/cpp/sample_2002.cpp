#include <iostream>
#include <vector>
#include <cmath>

class Transform3D {
public:
    double x, y, z;

    Transform3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Transform3D rotate_x(double angle) const {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double new_y = y * cos_a - z * sin_a;
        double new_z = y * sin_a + z * cos_a;
        return Transform3D(x, new_y, new_z);
    }

    Transform3D rotate_y(double angle) const {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double new_x = x * cos_a + z * sin_a;
        double new_z = -x * sin_a + z * cos_a;
        return Transform3D(new_x, y, new_z);
    }

    Transform3D rotate_z(double angle) const {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double new_x = x * cos_a - y * sin_a;
        double new_y = x * sin_a + y * cos_a;
        return Transform3D(new_x, new_y, z);
    }
};

class TransformHandler {
public:
    std::vector<Transform3D> points;

    TransformHandler(const std::vector<std::vector<double>>& points) {
        for (const auto& point : points) {
            this->points.emplace_back(point[0], point[1], point[2]);
        }
    }

    std::vector<std::vector<double>> apply_rotation(double angle_x, double angle_y, double angle_z) const {
        std::vector<std::vector<double>> rotated_points;
        for (const auto& point : points) {
            Transform3D rotated = point.rotate_x(angle_x).rotate_y(angle_y).rotate_z(angle_z);
            rotated_points.push_back({rotated.x, rotated.y, rotated.z});
        }
        return rotated_points;
    }
};

int main() {
    std::vector<std::vector<double>> initial_points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    TransformHandler handler(initial_points);
    double angles[] = {M_PI / 4, M_PI / 4, M_PI / 4};
    std::vector<std::vector<double>> result = handler.apply_rotation(angles[0], angles[1], angles[2]);
    for (const auto& point : result) {
        std::cout << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")" << std::endl;
    }
    return 0;
}