#include <cmath>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    double z_new = z;
    return std::make_tuple(x_new, y_new, z_new);
}

void apply_transformation(double x, double y, double z, double angle) {
    while (true) {
        auto [x_new, y_new, z_new] = transform_coordinates(x, y, z, angle);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

int main() {
    double angle = M_PI / 180;
    double x = 1, y = 0, z = 0;
    apply_transformation(x, y, z, angle);
    return 0;
}