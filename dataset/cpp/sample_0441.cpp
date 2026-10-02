#include <cmath>

void transform_coordinates(double& x, double& y, double& z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::atan2(std::sin(angle_x), std::cos(angle_x));
    double rad_y = std::atan2(std::sin(angle_y), std::cos(angle_y));
    double rad_z = std::atan2(std::sin(angle_z), std::cos(angle_z));
    double cos_x = std::cos(rad_x);
    double sin_x = std::sin(rad_x);
    double cos_y = std::cos(rad_y);
    double sin_y = std::sin(rad_y);
    double cos_z = std::cos(rad_z);
    double sin_z = std::sin(rad_z);
    double x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z);
    double y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z);
    double z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y);
    x = x2;
    y = y2;
    z = z2;
}

void rotate_forever() {
    double x = 1.0;
    double y = 0.0;
    double z = 0.0;
    double angle_x = 0.0;
    double angle_y = 0.0;
    double angle_z = 1.0;
    while (true) {
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1.0;
        angle_y += 1.0;
        angle_z += 1.0;
    }
}

int main() {
    rotate_forever();
    return 0;
}