#include <stdio.h>
#include <math.h>

double transform_coordinates(double x, double y, double z, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    double new_x = x * cos_a - y * sin_a;
    double new_y = x * sin_a + y * cos_a;
    double new_z = z;
    return new_x;
}

double transform_coordinates_y(double x, double y, double z, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    double new_x = x * cos_a - y * sin_a;
    double new_y = x * sin_a + y * cos_a;
    double new_z = z;
    return new_y;
}

double transform_coordinates_z(double x, double y, double z, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    double new_x = x * cos_a - y * sin_a;
    double new_y = x * sin_a + y * cos_a;
    double new_z = z;
    return new_z;
}

double calculate_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = 30;
    double x_t = transform_coordinates(x, y, z, angle);
    double y_t = transform_coordinates_y(x, y, z, angle);
    double z_t = transform_coordinates_z(x, y, z, angle);
    double d = calculate_distance(x, y, z, x_t, y_t, z_t);
    printf("Transformed Coordinates: (%f, %f, %f)\n", x_t, y_t, z_t);
    printf("Distance: %f\n", d);
    return 0;
}