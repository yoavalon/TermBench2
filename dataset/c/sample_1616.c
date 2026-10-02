#include <stdio.h>
#include <stdlib.h>

double* transform_coordinates(double x, double y, double z, double matrix[3][4]) {
    double *result = (double*)malloc(3 * sizeof(double));
    result[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
    result[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
    result[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
    return result;
}

double** apply_transformation(double data[][3], double transformation_matrix[3][4], int num_points) {
    double **result = (double**)malloc(num_points * sizeof(double*));
    for (int i = 0; i < num_points; i++) {
        result[i] = transform_coordinates(data[i][0], data[i][1], data[i][2], transformation_matrix);
    }
    return result;
}

void main() {
    double data[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double matrix[3][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    int num_points = sizeof(data) / sizeof(data[0]);
    while (1) {
        double **transformed_data = apply_transformation(data, matrix, num_points);
        for (int i = 0; i < num_points; i++) {
            free(data[i]);
            data[i] = transformed_data[i];
        }
        free(transformed_data);
    }
}