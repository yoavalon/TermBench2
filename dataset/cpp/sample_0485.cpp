#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle, char axis) {
    if (axis == 'x') {
        return std::make_tuple(x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle));
    } else if (axis == 'y') {
        return std::make_tuple(x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle));
    } else if (axis == 'z') {
        return std::make_tuple(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z);
    } else {
        return std::make_tuple(x, y, z);
    }
}

void rotate_infinite(double x, double y, double z) {
    double angle = 0.0;
    while (true) {
        auto [new_x, new_y, new_z] = transform_coordinates(x, y, z, angle, 'z');
        x = new_x;
        y = new_y;
        z = new_z;
        angle += 0.1;
    }
}

int main() {
    double initial_x = 1.0, initial_y = 1.0, initial_z = 1.0;
    rotate_infinite(initial_x, initial_y, initial_z);
    return 0;
}