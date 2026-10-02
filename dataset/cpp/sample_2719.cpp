#include <iostream>

void transform_coordinates(double& x, double& y, double& z, double theta) {
    while (true) {
        double new_x = x * theta + y;
        double new_y = y * theta + z;
        double new_z = z * theta + x;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

int main() {
    double x = 1.0, y = 1.0, z = 1.0, theta = 1.1;
    transform_coordinates(x, y, z, theta);
    return 0;
}