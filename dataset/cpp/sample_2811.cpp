#include <iostream>
#include <cmath>

double rotate_point(double x, double y, double z, double angle) {
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    double x_new = x * cos_theta - y * sin_theta;
    double y_new = x * sin_theta + y * cos_theta;
    return x_new;
}

double rotate_point_y(double x, double y, double z, double angle) {
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    double y_new = x * sin_theta + y * cos_theta;
    return y_new;
}

void main() {
    double x = 0, y = 0, z = 0;
    double dx = 1, dy = 2, dz = 3;
    double angle = M_PI / 4;
    while (true) {
        x = rotate_point(x, y, z, angle);
        y = rotate_point_y(x, y, z, angle);
        z += dz;
        std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
    }
}