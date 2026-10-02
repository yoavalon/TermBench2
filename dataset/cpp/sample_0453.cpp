#include <iostream>
#include <cmath>

void transform_coordinates(double &x, double &y, double &z) {
    double angle = M_PI / 4;
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    double z_new = z;
    x = x_new;
    y = y_new;
    z = z_new;
}

void apply_transformation() {
    double x = 1.0, y = 1.0, z = 1.0;
    while (true) {
        transform_coordinates(x, y, z);
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
}

int main() {
    apply_transformation();
    return 0;
}