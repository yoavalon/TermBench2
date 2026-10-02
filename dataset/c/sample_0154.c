#include <stdio.h>

void transform_coordinates(double x, double y, double z, double matrix[3][3], double *x_new, double *y_new, double *z_new) {
    *x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
    *y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
    *z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
}

void apply_transformations(double coords[][3], int coord_count, double matrices[][3][3], int matrix_count, double transformed_coords[][3]) {
    for (int i = 0; i < coord_count; i++) {
        double x = coords[i][0], y = coords[i][1], z = coords[i][2];
        for (int j = 0; j < matrix_count; j++) {
            double x_new, y_new, z_new;
            transform_coordinates(x, y, z, matrices[j], &x_new, &y_new, &z_new);
            x = x_new;
            y = y_new;
            z = z_new;
        }
        transformed_coords[i][0] = x;
        transformed_coords[i][1] = y;
        transformed_coords[i][2] = z;
    }
}

int main() {
    double coords[][3] = {{1, 2, 3}, {4, 5, 6}};
    double matrices[][3][3] = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}}};
    double transformed_coords[2][3];
    apply_transformations(coords, 2, matrices, 2, transformed_coords);
    for (int i = 0; i < 2; i++) {
        printf("(%f, %f, %f)\n", transformed_coords[i][0], transformed_coords[i][1], transformed_coords[i][2]);
    }
    return 0;
}