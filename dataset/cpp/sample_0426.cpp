#include <iostream>
#include <cmath>

void transform_coordinates(double &x, double &y, double &z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::radians(angle_x);
    double rad_y = std::radians(angle_y);
    double rad_z = std::radians(angle_z);
    double cos_x = std::cos(rad_x);
    double cos_y = std::cos(rad_y);
    double cos_z = std::cos(rad_z);
    double sin_x = std::sin(rad_x);
    double sin_y = std::sin(rad_y);
    double sin_z = std::sin(rad_z);
    double x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    double y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    x = x_new;
    y = y_new;
    z = z_new;
}

void apply_transformation() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle_x = 30, angle_y = 45, angle_z = 60;
    while (true) {
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        std::cout << x << " " << y << " " << z << std::endl;
    }
}

int main() {
    apply_transformation();
    return 0;
}