#include <stdio.h>

void transform(double x, double y, double z, double a, double b, double c) {
    double new_x = a * x + b * y + c * z;
    double new_y = b * x + a * y;
    double new_z = c * x + y;
    transform(new_x, new_y, new_z, a, b, c);
}

int main() {
    transform(1, 1, 1, 1.5, -0.5, 0);
    return 0;
}