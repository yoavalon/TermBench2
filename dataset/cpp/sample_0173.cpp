#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double angle_x_rad = std::atan2(std::sin(angle_x), std::cos(angle_x));
    double angle_y_rad = std::atan2(std::sin(angle_y), std::cos(angle_y));
    double angle_z_rad = std::atan2(std::sin(angle_z), std::cos(angle_z));
    double cos_x = std::cos(angle_x_rad);
    double sin_x = std::sin(angle_x_rad);
    double cos_y = std::cos(angle_y_rad);
    double sin_y = std::sin(angle_y_rad);
    double cos_z = std::cos(angle_z_rad);
    double sin_z = std::sin(angle_z_rad);
    double x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    double y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return std::make_tuple(x_new, y_new, z_new);
}

std::tuple<double, double, double> apply_boundary_conditions(double x, double y, double z, double min_x, double max_x, double min_y, double max_y, double min_z, double max_z) {
    x = std::max(min_x, std::min(x, max_x));
    y = std::max(min_y, std::min(y, max_y));
    z = std::max(min_z, std::min(z, max_z));
    return std::make_tuple(x, y, z);
}

int main() {
    double x = 5, y = 10, z = 15;
    double angle_x = 30, angle_y = 45, angle_z = 60;
    double min_x = -100, max_x = 100, min_y = -100, max_y = 100, min_z = -100, max_z = 100;
    std::tie(x, y, z) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    std::tie(x, y, z) = apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z);
    std::cout << "Transformed and bounded coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;
    return 0;
}