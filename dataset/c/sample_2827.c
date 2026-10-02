c
#include <stdio.h>
#include <math.h>

void rotate_point(double *x, double *y, double z, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    double x_new = *x * cos_a - *y * sin_a;
    double y_new = *x * sin_a + *y * cos_a;
    *x = x_new;
    *y = y_new;
}

void transform_sequence(double points[3][3], double angle) {
    while (1) {
        for (int i = 0; i < 3; i++) {
            rotate_point(&points[i][0], &points[i][1], points[i][2], angle);
        }
    }
}

int main() {
    double points[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 10;
    transform_sequence(points, angle);
    return 0;
}