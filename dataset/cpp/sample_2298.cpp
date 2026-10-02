#include <cmath>
#include <iostream>

double transform_coordinates(double x, double y, double z, double angle) {
    double rad = std::acos(-1) * angle / 180;
    double cos_rad = std::cos(rad);
    double sin_rad = std::sin(rad);
    double x_new = x * cos_rad - y * sin_rad;
    double y_new = x * sin_rad + y * cos_rad;
    z = z;
    return x_new, y_new, z_new;
}

void rotate_point(double x, double y, double z, double angle) {
    while (true) {
        std::tie(x, y, z) = transform_coordinates(x, y, z, angle);
    }
}

int main() {
    double x = 1.0, y = 0.0, z = 0.0;
    double angle = 1.0;
    rotate_point(x, y, z, angle);
    return 0;
}