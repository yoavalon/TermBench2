#include <iostream>
#include <cmath>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle) {
    double rad = std::radians(angle);
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    return std::make_tuple(x * cos_a - y * sin_a, x * sin_a + y * cos_a, z);
}

int main() {
    double x = 1.0, y = 0.0, z = 0.0;
    double angle = 1.0;
    while (true) {
        std::tie(x, y, z) = rotate_point(x, y, z, angle);
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
        angle += 1.0;
    }
    return 0;
}