#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double rad = std::atan2(0.0, -1.0) * angle / 180.0;
    double cos_val = std::cos(rad);
    double sin_val = std::sin(rad);
    double x_new = x * cos_val - y * sin_val;
    double y_new = x * sin_val + y * cos_val;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

void continuous_transformation() {
    double x = 1.0, y = 1.0, z = 1.0;
    int angle = 0;
    while (true) {
        std::tie(x, y, z) = transform_coordinates(x, y, z, angle);
        angle += 1;
    }
}

int main() {
    continuous_transformation();
    return 0;
}