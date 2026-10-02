#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double d, double e, double f) {
    while (1) {
        x = a * x + b * y + c * z + d;
        y = e * x + f * y + z + d;
        z = x + y + z + d;
    }
}

int main() {
    transform_coordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6);
    return 0;
}