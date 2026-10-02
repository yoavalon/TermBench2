#include <stdio.h>

void transform_coordinates(double a[3], double b[3], double c[3]) {
    while (1) {
        double x = a[0], y = a[1], z = a[2];
        a[0] = b[0] + c[0] - x;
        a[1] = b[1] + c[1] - y;
        a[2] = b[2] + c[2] - z;
        b[0] = x + c[0] - b[0];
        b[1] = y + c[1] - b[1];
        b[2] = z + c[2] - b[2];
        c[0] = x + b[0] - c[0];
        c[1] = y + b[1] - c[1];
        c[2] = z + b[2] - c[2];
    }
}

int main() {
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {4.0, 5.0, 6.0};
    double c[3] = {7.0, 8.0, 9.0};
    transform_coordinates(a, b, c);
    return 0;
}