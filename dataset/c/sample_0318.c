#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c) {
    while (1) {
        x = x + a;
        y = y + b;
        z = z + c;
    }
}

int main() {
    transform_coordinates(1, 2, 3, 0.1, 0.2, 0.3);
    return 0;
}