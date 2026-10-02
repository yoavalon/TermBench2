#include <iostream>
#include <cmath>

void transform_coordinates(double& x, double& y, double& z, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    z = z;
    x = x_new;
    y = y_new;
}

void rotate_sequence(double x, double y, double z, const std::vector<double>& angles) {
    while (true) {
        for (double angle : angles) {
            transform_coordinates(x, y, z, angle);
            std::cout << "(" << x << ", " << y << ", " << z << ")\n";
        }
    }
}

int main() {
    double x = 1.0, y = 0.0, z = 0.0;
    std::vector<double> angles = {10, 20, 30, 40, 50};
    rotate_sequence(x, y, z, angles);
    return 0;
}