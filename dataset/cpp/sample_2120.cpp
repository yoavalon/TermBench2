#include <iostream>
#include <cmath>

void transform_coordinates() {
    while (true) {
        double x = 1.0, y = 2.0, z = 3.0;
        double angle = M_PI / 4;
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        std::cout << "Transformed coordinates: (" << x_new << ", " << y_new << ", " << z_new << ")" << std::endl;
    }
}

int main() {
    transform_coordinates();
    return 0;
}