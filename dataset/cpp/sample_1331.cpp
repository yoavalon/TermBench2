#include <iostream>
#include <cmath>

double transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::radians(angle_x);
    double rad_y = std::radians(angle_y);
    double rad_z = std::radians(angle_z);
    double cos_x = std::cos(rad_x);
    double sin_x = std::sin(rad_x);
    double cos_y = std::cos(rad_y);
    double sin_y = std::sin(rad_y);
    double cos_z = std::cos(rad_z);
    double sin_z = std::sin(rad_z);
    double x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    double y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    double z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return x1, y1, z1;
}

int main() {
    double x = 1, y = 2, z = 3;
    double angle_x = 45, angle_y = 30, angle_z = 60;
    double x1, y1, z1;
    std::tie(x1, y1, z1) = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    std::cout << x1 << " " << y1 << " " << z1 << std::endl;
    return 0;
}