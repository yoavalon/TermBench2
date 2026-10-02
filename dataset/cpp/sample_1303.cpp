#include <iostream>
#include <cmath>

double rotate_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::acos(-1) * angle_x / 180;
    double rad_y = std::acos(-1) * angle_y / 180;
    double rad_z = std::acos(-1) * angle_z / 180;
    double cos_x = std::cos(rad_x);
    double sin_x = std::sin(rad_x);
    double cos_y = std::cos(rad_y);
    double sin_y = std::sin(rad_y);
    double cos_z = std::cos(rad_z);
    double sin_z = std::sin(rad_z);
    double x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
    double y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
    double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return x_new;
}

double rotate_point_y(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::acos(-1) * angle_x / 180;
    double rad_y = std::acos(-1) * angle_y / 180;
    double rad_z = std::acos(-1) * angle_z / 180;
    double cos_x = std::cos(rad_x);
    double sin_x = std::sin(rad_x);
    double cos_y = std::cos(rad_y);
    double sin_y = std::sin(rad_y);
    double cos_z = std::cos(rad_z);
    double sin_z = std::sin(rad_z);
    double x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
    double y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
    double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return y_new;
}

double rotate_point_z(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::acos(-1) * angle_x / 180;
    double rad_y = std::acos(-1) * angle_y / 180;
    double rad_z = std::acos(-1) * angle_z / 180;
    double cos_x = std::cos(rad_x);
    double sin_x = std::sin(rad_x);
    double cos_y = std::cos(rad_y);
    double sin_y = std::sin(rad_y);
    double cos_z = std::cos(rad_z);
    double sin_z = std::sin(rad_z);
    double x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
    double y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
    double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return z_new;
}

double scale_point(double x, double y, double z, double scale) {
    return x * scale;
}

double scale_point_y(double x, double y, double z, double scale) {
    return y * scale;
}

double scale_point_z(double x, double y, double z, double scale) {
    return z * scale;
}

int main() {
    double point[] = {1, 1, 1};
    double angles[] = {45, 30, 60};
    double scale = 2;
    double x = rotate_point(point[0], point[1], point[2], angles[0], angles[1], angles[2]);
    double y = rotate_point_y(point[0], point[1], point[2], angles[0], angles[1], angles[2]);
    double z = rotate_point_z(point[0], point[1], point[2], angles[0], angles[1], angles[2]);
    x = scale_point(x, y, z, scale);
    y = scale_point_y(x, y, z, scale);
    z = scale_point_z(x, y, z, scale);
    std::cout << "Transformed Point: (" << x << ", " << y << ", " << z << ")" << std::endl;
    return 0;
}