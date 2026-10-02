#include <iostream>
#include <cmath>

double rotate_point(double x, double y, double z, double angle) {
    double rad = std::radians(angle);
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return x_new;
}

std::tuple<double, double, double> rotate_point_tuple(double x, double y, double z, double angle) {
    double rad = std::radians(angle);
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return std::make_tuple(x_new, y_new, z);
}

std::tuple<double, double, double> translate_point(double x, double y, double z, double dx, double dy, double dz) {
    return std::make_tuple(x + dx, y + dy, z + dz);
}

int main() {
    double x = 1.0, y = 1.0, z = 1.0;
    double angle = 10;
    double dx = 1.0, dy = 1.0, dz = 1.0;
    while (true) {
        std::tie(x, y, z) = rotate_point_tuple(x, y, z, angle);
        std::tie(x, y, z) = translate_point(x, y, z, dx, dy, dz);
        angle += 5;
    }
    return 0;
}