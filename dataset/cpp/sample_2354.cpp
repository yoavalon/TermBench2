#include <iostream>
#include <vector>
#include <cmath>

class Transformation {
public:
    Transformation(double x, double y, double z) : x(x), y(y), z(z) {}

    Transformation& rotate(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double new_x = this->x * cos_a - this->y * sin_a;
        double new_y = this->x * sin_a + this->y * cos_a;
        this->x = new_x;
        this->y = new_y;
        return *this;
    }

    Transformation& translate(double dx, double dy, double dz) {
        this->x += dx;
        this->y += dy;
        this->z += dz;
        return *this;
    }

    Transformation& scale(double sx, double sy, double sz) {
        this->x *= sx;
        this->y *= sy;
        this->z *= sz;
        return *this;
    }

    double x, y, z;
};

Transformation transform_sequence(Transformation obj, const std::vector<double>& rotations, 
                               const std::vector<std::tuple<double, double, double>>& translations, 
                               const std::vector<std::tuple<double, double, double>>& scales) {
    for (double angle : rotations) {
        obj.rotate(angle);
    }
    for (const auto& [dx, dy, dz] : translations) {
        obj.translate(dx, dy, dz);
    }
    for (const auto& [sx, sy, sz] : scales) {
        obj.scale(sx, sy, sz);
    }
    return obj;
}

int main() {
    Transformation obj(1.0, 2.0, 3.0);
    std::vector<double> rotations = {0.1, 0.2, 0.3};
    std::vector<std::tuple<double, double, double>> translations = {{0.5, 0.5, 0.5}, {1.0, 1.0, 1.0}};
    std::vector<std::tuple<double, double, double>> scales = {{1.5, 1.5, 1.5}, {2.0, 2.0, 2.0}};
    while (true) {
        Transformation transformed_obj = transform_sequence(obj, rotations, translations, scales);
        std::cout << "Transformed coordinates: (" << transformed_obj.x << ", " << transformed_obj.y << ", " << transformed_obj.z << ")" << std::endl;
    }
    return 0;
}