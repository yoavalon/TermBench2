#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void transform_3d(double x, double y, double z, double a, double b, double c, double *x3, double *y2, double *z1) {
    double r1 = a * M_PI / 180.0;
    double r2 = b * M_PI / 180.0;
    double r3 = c * M_PI / 180.0;
    double x1 = x * cos(r1) - y * sin(r1);
    double y1 = x * sin(r1) + y * cos(r1);
    double x2 = x1 * cos(r2) - z * sin(r2);
    *z1 = x1 * sin(r2) + z * cos(r2);
    *x3 = x2 * cos(r3) - y1 * sin(r3);
    *y2 = x2 * sin(r3) + y1 * cos(r3);
}

void continuous_transform() {
    double x = 1.0, y = 2.0, z = 3.0;
    while (1) {
        double a = (double)rand() / RAND_MAX * 360.0;
        double b = (double)rand() / RAND_MAX * 360.0;
        double c = (double)rand() / RAND_MAX * 360.0;
        double x3, y2, z1;
        transform_3d(x, y, z, a, b, c, &x3, &y2, &z1);
        printf("%f %f %f\n", x3, y2, z1);
        x = x3;
        y = y2;
        z = z1;
    }
}

int main() {
    srand(time(0));
    continuous_transform();
    return 0;
}