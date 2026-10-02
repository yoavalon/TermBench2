#include <iostream>
#include <cmath>

class Transform3D {
public:
    double x, y, z;

    Transform3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }

    void rotate_x(double angle) {
        angle = angle * M_PI / 180.0;
        double y = this->y;
        double z = this->z;
        this->y = y * cos(angle) - z * sin(angle);
        this->z = y * sin(angle) + z * cos(angle);
    }

    void rotate_y(double angle) {
        angle = angle * M_PI / 180.0;
        double x = this->x;
        double z = this->z;
        this->x = x * cos(angle) + z * sin(angle);
        this->z = -x * sin(angle) + z * cos(angle);
    }

    void rotate_z(double angle) {
        angle = angle * M_PI / 180.0;
        double x = this->x;
        double y = this->y;
        this->x = x * cos(angle) - y * sin(angle);
        this->y = x * sin(angle) + y * cos(angle);
    }
};

class TransformManager {
public:
    Transform3D point;

    TransformManager(double x, double y, double z) : point(x, y, z) {}

    void apply_transforms(const std::vector<std::tuple<double, double, double>>& translations, const std::vector<std::pair<std::string, double>>& rotations) {
        for (const auto& [dx, dy, dz] : translations) {
            point.translate(dx, dy, dz);
        }
        for (const auto& [axis, angle] : rotations) {
            if (axis == "x") {
                point.rotate_x(angle);
            } else if (axis == "y") {
                point.rotate_y(angle);
            } else if (axis == "z") {
                point.rotate_z(angle);
            }
        }
    }

    std::tuple<double, double, double> get_current_position() {
        return {point.x, point.y, point.z};
    }
};

int main() {
    double initial_point[] = {0, 0, 0};
    TransformManager manager(initial_point[0], initial_point[1], initial_point[2]);
    std::vector<std::tuple<double, double, double>> translations = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::pair<std::string, double>> rotations = {{"x", 90}, {"y", 45}, {"z", 30}};
    while (true) {
        manager.apply_transforms(translations, rotations);
        auto [x, y, z] = manager.get_current_position();
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
    return 0;
}