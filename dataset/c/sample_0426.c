#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *x_new, double *y_new, double *z_new) {
    double rad_x = angle_x * M_PI / 180.0;
    double rad_y = angle_y * M_PI / 180.0;
    double rad_z = angle_z * M_PI / 180.0;
    double cos_x = cos(rad_x);
    double cos_y = cos(rad_y);
    double cos_z = cos(rad_z);
    double sin_x = sin(rad_x);
    double sin_y = sin(rad_y);
    double sin_z = sin(rad_z);
    *x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    *y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    *z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
}

void apply_transformation() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle_x = 30.0, angle_y = 45.0, angle_z = 60.0;
    while (1) {
        double x_new, y_new, z_new;
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z, &x_new, &y_new, &z_new);
        printf("%f %f %f\n", x_new, y_new, z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

int main() {
    apply_transformation();
    return 0;
}