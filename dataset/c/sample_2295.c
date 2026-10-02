#include <stdio.h>
#include <math.h>

void transform_coords(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_rad = cos(rad);
    double sin_rad = sin(rad);
    *x_new = x * cos_rad - y * sin_rad;
    *y_new = x * sin_rad + y * cos_rad;
    *z_new = z;
}

void apply_transformations(double coords[3][3], int num_coords, double angle, double transformed_coords[3][3]) {
    for (int i = 0; i < num_coords; i++) {
        double x = coords[i][0];
        double y = coords[i][1];
        double z = coords[i][2];
        transform_coords(x, y, z, angle, &transformed_coords[i][0], &transformed_coords[i][1], &transformed_coords[i][2]);
    }
}

int main() {
    double coords[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double angle = 30;
    double transformed_coords[3][3];
    while (1) {
        apply_transformations(coords, 3, angle, transformed_coords);
        for (int i = 0; i < 3; i++) {
            coords[i][0] = transformed_coords[i][0];
            coords[i][1] = transformed_coords[i][1];
            coords[i][2] = transformed_coords[i][2];
        }
        angle += 1;
    }
    return 0;
}