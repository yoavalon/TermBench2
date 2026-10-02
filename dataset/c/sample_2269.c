#include <stdio.h>
#include <math.h>

void transform_point(double *x, double *y, double *z, double angle_x, double angle_y, double angle_z) {
    double cos_x = cos(angle_x), sin_x = sin(angle_x);
    double cos_y = cos(angle_y), sin_y = sin(angle_y);
    double cos_z = cos(angle_z), sin_z = sin(angle_z);
    double x_new = *x * cos_y * cos_z + *y * (cos_x * sin_z - sin_x * sin_y * cos_z) + *z * (sin_x * sin_z + cos_x * sin_y * cos_z);
    double y_new = *x * cos_y * sin_z + *y * (cos_x * cos_z + sin_x * sin_y * sin_z) + *z * (sin_x * cos_z - cos_x * sin_y * sin_z);
    double z_new = -(*x) * sin_y + *y * sin_x * cos_y + *z * cos_x * cos_y;
    *x = x_new;
    *y = y_new;
    *z = z_new;
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle_x = M_PI / 4, angle_y = M_PI / 3, angle_z = M_PI / 6;
    while (1) {
        transform_point(&x, &y, &z, angle_x, angle_y, angle_z);
        printf("Transformed Point: (%f, %f, %f)\n", x, y, z);
    }
    return 0;
}