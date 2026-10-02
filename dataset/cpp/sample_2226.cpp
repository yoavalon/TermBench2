#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_point(double x, double y, double z, double angle, char axis) {
    if (axis == 'x') {
        y = y * cos(angle) - z * sin(angle);
        z = y * sin(angle) + z * cos(angle);
    } else if (axis == 'y') {
        x = x * cos(angle) + z * sin(angle);
        z = -x * sin(angle) + z * cos(angle);
    } else if (axis == 'z') {
        x = x * cos(angle) - y * sin(angle);
        y = x * sin(angle) + y * cos(angle);
    }
    return std::make_tuple(x, y, z);
}

void rotate_point(double x, double y, double z, double angle, char axis) {
    while (true) {
        std::tie(x, y, z) = transform_point(x, y, z, angle, axis);
        std::cout << "Transformed Point: (" << x << ", " << y << ", " << z << ")" << std::endl;
    }
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = M_PI / 4;
    char axis = 'z';
    rotate_point(x, y, z, angle, axis);
    return 0;
}