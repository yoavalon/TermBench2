#include <iostream>
#include <cmath>

double transform_coordinates(double x, double y, double z, double angle, double &new_x, double &new_y, double &new_z) {
    double rad = std::acos(-1) * angle / 180.0;
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    new_x = x * cos_a - y * sin_a;
    new_y = x * sin_a + y * cos_a;
    new_z = z;
}

double calculate_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = 30.0;
    double x_t, y_t, z_t;
    transform_coordinates(x, y, z, angle, x_t, y_t, z_t);
    double d = calculate_distance(x, y, z, x_t, y_t, z_t);
    std::cout << "Transformed Coordinates: (" << x_t << ", " << y_t << ", " << z_t << ")" << std::endl;
    std::cout << "Distance: " << d << std::endl;
    return 0;
}