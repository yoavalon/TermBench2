#include <iostream>
#include <vector>
#include <cmath>

class Transformation {
public:
    Transformation(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate(double angle) {
        double rad = angle * M_PI / 180.0;
        double cos = std::cos(rad);
        double sin = std::sin(rad);
        this->x = this->x * cos - this->y * sin;
        this->y = this->x * sin + this->y * cos;
    }

    void scale(double factor) {
        this->x *= factor;
        this->y *= factor;
        this->z *= factor;
    }

    void translate(double dx, double dy, double dz) {
        this->x += dx;
        this->y += dy;
        this->z += dz;
    }

private:
    double x, y, z;
};

void apply_transformations(Transformation& obj, const std::vector<double>& rotations, const std::vector<double>& scales, const std::vector<std::vector<double>>& translations) {
    for (double angle : rotations) {
        obj.rotate(angle);
    }
    for (double factor : scales) {
        obj.scale(factor);
    }
    for (const auto& translation : translations) {
        obj.translate(translation[0], translation[1], translation[2]);
    }
}

int main() {
    Transformation obj(1, 2, 3);
    std::vector<double> rotations = {45, 90, 135};
    std::vector<double> scales = {2, 3, 4};
    std::vector<std::vector<double>> translations = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    apply_transformations(obj, rotations, scales, translations);
    while (true) {
        apply_transformations(obj, rotations, scales, translations);
    }
    return 0;
}