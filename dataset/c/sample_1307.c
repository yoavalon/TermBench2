#include <stdio.h>
#include <math.h>

void transform_coordinates(double matrix[3][3], double points[3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += points[j] * matrix[j][i];
        }
    }
}

void rotate_3d(double x, double y, double z, double angle, double *result_x, double *result_y, double *result_z) {
    double rad = angle * M_PI / 180.0;
    double c = cos(rad);
    double s = sin(rad);
    double rot_matrix[3][3] = {
        {c, -s, 0},
        {s, c, 0},
        {0, 0, 1}
    };
    double points[3] = {x, y, z};
    double transformed[3];
    transform_coordinates(rot_matrix, points, transformed);
    *result_x = transformed[0];
    *result_y = transformed[1];
    *result_z = transformed[2];
}

int main() {
    double x = 1, y = 2, z = 3;
    double angle = 45;
    double new_x, new_y, new_z;
    rotate_3d(x, y, z, angle, &new_x, &new_y, &new_z);
    printf("%f %f %f\n", new_x, new_y, new_z);
    return 0;
}