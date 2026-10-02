#include <stdio.h>
#include <math.h>

void transform_point(double matrix[3][3], double point[3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += matrix[i][j] * point[j];
        }
    }
}

void generate_rotation_matrix(double angle, char axis, double matrix[3][3]) {
    double c = cos(angle);
    double s = sin(angle);
    if (axis == 'x') {
        matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0;
        matrix[1][0] = 0; matrix[1][1] = c; matrix[1][2] = -s;
        matrix[2][0] = 0; matrix[2][1] = s; matrix[2][2] = c;
    } else if (axis == 'y') {
        matrix[0][0] = c; matrix[0][1] = 0; matrix[0][2] = s;
        matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0;
        matrix[2][0] = -s; matrix[2][1] = 0; matrix[2][2] = c;
    } else if (axis == 'z') {
        matrix[0][0] = c; matrix[0][1] = -s; matrix[0][2] = 0;
        matrix[1][0] = s; matrix[1][1] = c; matrix[1][2] = 0;
        matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
    }
}

void main() {
    double point[3] = {1, 2, 3};
    double angle = M_PI / 4;
    double matrix[3][3];
    double transformed_point[3];

    generate_rotation_matrix(angle, 'z', matrix);
    transform_point(matrix, point, transformed_point);

    printf("%f %f %f\n", transformed_point[0], transformed_point[1], transformed_point[2]);
}