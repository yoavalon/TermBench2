#include <stdio.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double *x_prime, double *y_prime, double *z_prime) {
    *x_prime = a * x + b * y + c * z;
    *y_prime = b * x + a * y + c * z;
    *z_prime = c * x + c * y + a * z;
}

void main() {
    double x = 1, y = 2, z = 3;
    double a = 0.5, b = 0.5, c = 0.707;
    double x_prime, y_prime, z_prime;
    transform_coordinates(x, y, z, a, b, c, &x_prime, &y_prime, &z_prime);
    printf("%f %f %f\n", x_prime, y_prime, z_prime);
}