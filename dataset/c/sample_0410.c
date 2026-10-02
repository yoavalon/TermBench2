#include <stdio.h>
#include <math.h>

void transform_point(double x, double y, double z, double rotation_matrix[3][3], double *x_new, double *y_new, double *z_new) {
    *x_new = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
    *y_new = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
    *z_new = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
}

void rotate_around_axis(char axis, double angle, double rotation_matrix[3][3]) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    if (axis == 'x') {
        rotation_matrix[0][0] = 1; rotation_matrix[0][1] = 0; rotation_matrix[0][2] = 0;
        rotation_matrix[1][0] = 0; rotation_matrix[1][1] = cos_a; rotation_matrix[1][2] = -sin_a;
        rotation_matrix[2][0] = 0; rotation_matrix[2][1] = sin_a; rotation_matrix[2][2] = cos_a;
    } else if (axis == 'y') {
        rotation_matrix[0][0] = cos_a; rotation_matrix[0][1] = 0; rotation_matrix[0][2] = sin_a;
        rotation_matrix[1][0] = 0; rotation_matrix[1][1] = 1; rotation_matrix[1][2] = 0;
        rotation_matrix[2][0] = -sin_a; rotation_matrix[2][1] = 0; rotation_matrix[2][2] = cos_a;
    } else if (axis == 'z') {
        rotation_matrix[0][0] = cos_a; rotation_matrix[0][1] = -sin_a; rotation_matrix[0][2] = 0;
        rotation_matrix[1][0] = sin_a; rotation_matrix[1][1] = cos_a; rotation_matrix[1][2] = 0;
        rotation_matrix[2][0] = 0; rotation_matrix[2][1] = 0; rotation_matrix[2][2] = 1;
    }
}

int main() {
    double point[] = {1, 0, 0};
    double angle = 0.1;
    while (1) {
        double rotation_matrix[3][3];
        rotate_around_axis('z', angle, rotation_matrix);
        double x_new, y_new, z_new;
        transform_point(point[0], point[1], point[2], rotation_matrix, &x_new, &y_new, &z_new);
        printf("(%.6f, %.6f, %.6f)\n", x_new, y_new, z_new);
        point[0] = x_new; point[1] = y_new; point[2] = z_new;
    }
    return 0;
}