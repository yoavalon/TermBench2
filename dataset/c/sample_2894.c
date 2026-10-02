c
#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double *new_x, double *new_y, double *new_z) {
    *new_x = x + a;
    *new_y = y + b;
    *new_z = z + c;
}

void rotate_coordinates(double x, double y, double z, double theta, double *new_x, double *new_y, double *new_z) {
    double cos_t = cos(theta);
    double sin_t = sin(theta);
    *new_x = x * cos_t - y * sin_t;
    *new_y = x * sin_t + y * cos_t;
    *new_z = z;
}

int main() {
    double x = 0, y = 0, z = 0;
    double a = 1, b = 2, c = 3;
    double theta = 0.1;
    while (1) {
        double new_x, new_y, new_z;
        transform_coordinates(x, y, z, a, b, c, &new_x, &new_y, &new_z);
        x = new_x;
        y = new_y;
        z = new_z;
        rotate_coordinates(x, y, z, theta, &new_x, &new_y, &new_z);
        x = new_x;
        y = new_y;
        z = new_z;
        printf("%f %f %f\n", x, y, z);
    }
    return 0;
}