#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double rad = std::acos(-1) * angle / 180.0;
    double cos_rad = std::cos(rad);
    double sin_rad = std::sin(rad);
    double x_new = x * cos_rad - y * sin_rad;
    double y_new = x * sin_rad + y * cos_rad;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

void apply_transformation() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = 0.0;
    while (true) {
        std::tie(x, y, z) = transform_coordinates(x, y, z, angle);
        angle += 1;
    }
}

int main() {
    apply_transformation();
    return 0;
}