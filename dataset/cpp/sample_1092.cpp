#include <cmath>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    double new_x = x * cos_a - y * sin_a;
    double new_y = x * sin_a + y * cos_a;
    double new_z = z;
    return std::make_tuple(new_x, new_y, new_z);
}

void transform_point(double x, double y, double z) {
    double angle = 0.1;
    auto [new_x, new_y, new_z] = rotate_point(x, y, z, angle);
    transform_point(new_x, new_y, new_z);
}

int main() {
    double x = 1, y = 1, z = 1;
    transform_point(x, y, z);
    return 0;
}