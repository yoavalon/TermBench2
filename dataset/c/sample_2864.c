#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    *x_new = x * cos_a - y * sin_a;
    *y_new = x * sin_a + y * cos_a;
    *z_new = z;
}

void rotate_sequence(double x, double y, double z, double angles[], int num_angles) {
    while (1) {
        for (int i = 0; i < num_angles; i++) {
            double x_new, y_new, z_new;
            transform_coordinates(x, y, z, angles[i], &x_new, &y_new, &z_new);
            printf("(%.2f, %.2f, %.2f)\n", x_new, y_new, z_new);
            x = x_new;
            y = y_new;
            z = z_new;
        }
    }
}

int main() {
    double x = 1.0, y = 0.0, z = 0.0;
    double angles[] = {10, 20, 30, 40, 50};
    int num_angles = sizeof(angles) / sizeof(angles[0]);
    rotate_sequence(x, y, z, angles, num_angles);
    return 0;
}