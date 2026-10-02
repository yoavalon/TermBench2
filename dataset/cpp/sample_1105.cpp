#include <cmath>
#include <tuple>

std::tuple<double, double, double> transform_point(double x, double y, double z, double a, double b, double c) {
    double x_new = x + a;
    double y_new = y + b;
    double z_new = z + c;
    return std::make_tuple(x_new, y_new, z_new);
}

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle) {
    double rad = std::radians(angle);
    double cos_rad = std::cos(rad);
    double sin_rad = std::sin(rad);
    double x_new = x * cos_rad - y * sin_rad;
    double y_new = x * sin_rad + y * cos_rad;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

std::tuple<double, double, double> scale_point(double x, double y, double z, double s) {
    double x_new = x * s;
    double y_new = y * s;
    double z_new = z * s;
    return std::make_tuple(x_new, y_new, z_new);
}

std::tuple<double, double, double> recursive_transform(double x, double y, double z, double a, double b, double c, double angle, double s) {
    std::tie(x, y, z) = transform_point(x, y, z, a, b, c);
    std::tie(x, y, z) = rotate_point(x, y, z, angle);
    std::tie(x, y, z) = scale_point(x, y, z, s);
    return recursive_transform(x, y, z, a, b, c, angle, s);
}

int main() {
    double x = 0, y = 0, z = 0;
    double a = 1, b = 1, c = 1;
    double angle = 1;
    double s = 1.01;
    recursive_transform(x, y, z, a, b, c, angle, s);
    return 0;
}