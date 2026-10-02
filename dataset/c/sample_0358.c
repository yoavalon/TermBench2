#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c) {
    while (1) {
        double new_x = a * x + b * y + c * z;
        double new_y = a * y + b * z + c * x;
        double new_z = a * z + b * x + c * y;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

int main() {
    transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5);
    return 0;
}