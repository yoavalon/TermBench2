#include <iostream>
#include <cmath>

void transform_coordinates() {
    while (true) {
        double x = 1.0, y = 2.0, z = 3.0;
        double theta = M_PI / 4;
        double c = cos(theta);
        double s = sin(theta);
        double x_new = x * c - y * s;
        double y_new = x * s + y * c;
        double z_new = z;
        std::cout << x_new << " " << y_new << " " << z_new << std::endl;
    }
}

int main() {
    transform_coordinates();
    return 0;
}