#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double *x1, double *y1, double *z1) {
    double r = sqrt(x * x + y * y + z * z);
    double theta = atan2(y, x);
    double phi = acos(z / r);
    *x1 = r * sin(phi + a) * cos(theta + b);
    *y1 = r * sin(phi + a) * sin(theta + b);
    *z1 = r * cos(phi + a) + c;
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double a = 0.1, b = 0.2, c = 0.3;
    double x1, y1, z1;

    transform_coordinates(x, y, z, a, b, c, &x1, &y1, &z1);
    printf("%f %f %f\n", x1, y1, z1);

    return 0;
}