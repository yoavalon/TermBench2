#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void transform_matrix(double rotation[3][3], double translation[3], double result[4][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = rotation[i][j];
        }
    }
    result[0][3] = translation[0];
    result[1][3] = translation[1];
    result[2][3] = translation[2];
    result[3][0] = 0;
    result[3][1] = 0;
    result[3][2] = 0;
    result[3][3] = 1;
}

void apply_transformation(double points[3], double matrix[4][4], double transformed_points[3]) {
    double homogeneous_points[4] = {points[0], points[1], points[2], 1};
    for (int i = 0; i < 3; i++) {
        transformed_points[i] = 0;
        for (int j = 0; j < 4; j++) {
            transformed_points[i] += homogeneous_points[j] * matrix[i][j];
        }
    }
}

void generate_sequence(int n, double initial_point[3], double angle, double axis[3], double sequence[11][3]) {
    sequence[0][0] = initial_point[0];
    sequence[0][1] = initial_point[1];
    sequence[0][2] = initial_point[2];
    double rotation_matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    for (int i = 0; i < n; i++) {
        rotate_around_axis(rotation_matrix, angle, axis, rotation_matrix);
        apply_transformation(sequence[i], rotation_matrix, sequence[i + 1]);
    }
}

void rotate_around_axis(double matrix[3][3], double angle, double axis[3], double result[3][3]) {
    double cos_val = cos(angle);
    double sin_val = sin(angle);
    double norm = sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
    double ux = axis[0] / norm;
    double uy = axis[1] / norm;
    double uz = axis[2] / norm;
    result[0][0] = cos_val + ux * ux * (1 - cos_val);
    result[0][1] = ux * uy * (1 - cos_val) - uz * sin_val;
    result[0][2] = ux * uz * (1 - cos_val) + uy * sin_val;
    result[1][0] = uy * ux * (1 - cos_val) + uz * sin_val;
    result[1][1] = cos_val + uy * uy * (1 - cos_val);
    result[1][2] = uy * uz * (1 - cos_val) - ux * sin_val;
    result[2][0] = uz * ux * (1 - cos_val) - uy * sin_val;
    result[2][1] = uz * uy * (1 - cos_val) + ux * sin_val;
    result[2][2] = cos_val + uz * uz * (1 - cos_val);
}

int main() {
    double initial_point[3] = {1, 0, 0};
    double angle = PI / 4;
    double axis[3] = {0, 0, 1};
    int n = 10;
    double sequence[11][3];
    generate_sequence(n, initial_point, angle, axis, sequence);
    for (int i = 0; i < n + 1; i++) {
        printf("%f %f %f\n", sequence[i][0], sequence[i][1], sequence[i][2]);
    }
    return 0;
}