#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x_new, double *y_new, double *z_new) {
    double angle_x_rad = angle_x * M_PI / 180.0;
    double angle_y_rad = angle_y * M_PI / 180.0;
    double angle_z_rad = angle_z * M_PI / 180.0;
    double cos_x = cos(angle_x_rad);
    double sin_x = sin(angle_x_rad);
    double cos_y = cos(angle_y_rad);
    double sin_y = sin(angle_y_rad);
    double cos_z = cos(angle_z_rad);
    double sin_z = sin(angle_z_rad);
    *x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    *y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    *z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
}

void apply_boundary_conditions(double *x, double *y, double *z, double min_x, double max_x, double min_y, double max_y, double min_z, double max_z) {
    *x = fmax(min_x, fmin(*x, max_x));
    *y = fmax(min_y, fmin(*y, max_y));
    *z = fmax(min_z, fmin(*z, max_z));
}

int main() {
    double x = 5, y = 10, z = 15;
    double angle_x = 30, angle_y = 45, angle_z = 60;
    double min_x = -100, max_x = 100, min_y = -100, max_y = 100, min_z = -100, max_z = 100;
    double x_new, y_new, z_new;
    transform_coordinates(x, y, z, angle_x, angle_y, angle_z, &x_new, &y_new, &z_new);
    apply_boundary_conditions(&x_new, &y_new, &z_new, min_x, max_x, min_y, max_y, min_z, max_z);
    printf("Transformed and bounded coordinates: (%f, %f, %f)\n", x_new, y_new, z_new);
    return 0;
}