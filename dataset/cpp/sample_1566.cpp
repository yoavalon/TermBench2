#include <iostream>

void transform_coordinates(double x, double y, double z, double a, double b, double c) {
    while (true) {
        x = a * x + b * y + c * z;
        y = b * x + a * y;
        z = c * x + c * y + a * z;
    }
}

int main() {
    transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5);
    return 0;
}