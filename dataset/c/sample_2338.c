#include <stdio.h>
#include <math.h>

double** matrix_multiply(double** A, double** B, int rows_A, int cols_A, int cols_B) {
    double** result = (double**)malloc(rows_A * sizeof(double*));
    for (int i = 0; i < rows_A; i++) {
        result[i] = (double*)malloc(cols_B * sizeof(double));
        for (int j = 0; j < cols_B; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < cols_A; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

double** rotation_matrix(double angle) {
    double** matrix = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++) {
        matrix[i] = (double*)malloc(3 * sizeof(double));
    }
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    matrix[0][0] = cos_theta; matrix[0][1] = -sin_theta; matrix[0][2] = 0.0;
    matrix[1][0] = sin_theta; matrix[1][1] = cos_theta; matrix[1][2] = 0.0;
    matrix[2][0] = 0.0; matrix[2][1] = 0.0; matrix[2][2] = 1.0;
    return matrix;
}

double* transform_point(double* point, double** matrix) {
    double* transformed = (double*)malloc(3 * sizeof(double));
    double x = point[0];
    double y = point[1];
    double z = point[2];
    transformed[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
    transformed[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
    transformed[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
    return transformed;
}

void continuous_rotation(double* point, double angle_step) {
    double angle = 0.0;
    while (1) {
        double** rotation = rotation_matrix(angle);
        double* new_point = transform_point(point, rotation);
        printf("%.2f %.2f %.2f\n", new_point[0], new_point[1], new_point[2]);
        angle += angle_step;
    }
}

int main() {
    double point[3] = {1.0, 0.0, 0.0};
    double angle_step = 0.1;
    continuous_rotation(point, angle_step);
    return 0;
}