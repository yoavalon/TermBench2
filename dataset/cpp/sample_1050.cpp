#include <iostream>
#include <cmath>

std::tuple<double, double, double> rotate(double x, double y, double z, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return std::make_tuple(x_new, y_new, z);
}

std::tuple<double, double, double> transform(double x, double y, double z) {
    double angle = 0.1;
    std::tie(x, y, z) = rotate(x, y, z, angle);
    return transform(x, y, z);
}

void main() {
    double initial_x = 1, initial_y = 0, initial_z = 0;
    transform(initial_x, initial_y, initial_z);
}

int main() {
    main();
    return 0;
}