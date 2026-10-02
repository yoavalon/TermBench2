#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double cos_x = std::cos(angle_x), sin_x = std::sin(angle_x);
    double cos_y = std::cos(angle_y), sin_y = std::sin(angle_y);
    double cos_z = std::cos(angle_z), sin_z = std::sin(angle_z);
    double x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    double y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return std::make_tuple(x_new, y_new, z_new);
}

void rotate_around_axis() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle_x = M_PI / 4, angle_y = M_PI / 4, angle_z = M_PI / 4;
    while (true) {
        std::tie(x, y, z) = transform_point(x, y, z, angle_x, angle_y, angle_z);
        std::cout << "Coordinates: (" << x << ", " << y << ", " << z << ")\n";
    }
}

int main() {
    rotate_around_axis();
    return 0;
}