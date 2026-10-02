#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

void apply_transformation(double data[3][3], double angle, double result[3][3]) {
    for (int i = 0; i < 3; i++) {
        transform_coordinates(data[i][0], data[i][1], data[i][2], angle, &result[i][0], &result[i][1], &result[i][2]);
    }
}

int main() {
    double data[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 90;
    double result[3][3];
    apply_transformation(data, angle, result);
    for (int i = 0; i < 3; i++) {
        printf("(%.1f, %.1f, %.1f)\n", result[i][0], result[i][1], result[i][2]);
    }
    return 0;
}