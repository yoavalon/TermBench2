#include <iostream>
#include <cmath>
#include <vector>

class CoordinateTransformer {
public:
    double a, b, c;

    CoordinateTransformer(double x, double y, double z) : a(x), b(y), c(z) {}

    void rotate(double theta) {
        double cos_theta = cos(theta);
        double sin_theta = sin(theta);
        a = a * cos_theta - b * sin_theta;
        b = a * sin_theta + b * cos_theta;
    }

    void scale(double factor) {
        a *= factor;
        b *= factor;
        c *= factor;
    }

    void translate(double dx, double dy, double dz) {
        a += dx;
        b += dy;
        c += dz;
    }
};

void apply_transformations(CoordinateTransformer& obj, const std::vector<double>& rotations, const std::vector<double>& scales, const std::vector<std::vector<double>>& translations) {
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
    CoordinateTransformer obj(1, 2, 3);
    std::vector<double> rotations = {0.1, 0.2, 0.3};
    std::vector<double> scales = {1.5, 2.0, 2.5};
    std::vector<std::vector<double>> translations = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    apply_transformations(obj, rotations, scales, translations);
    std::cout << obj.a << " " << obj.b << " " << obj.c << std::endl;
    return 0;
}