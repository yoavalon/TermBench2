#include <stdio.h>
#include <stdlib.h>

double* transform_coordinates(double* point, double** matrix) {
    double* result = (double*)malloc(3 * sizeof(double));
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += point[j] * matrix[i][j];
        }
    }
    return result;
}

double** apply_transformation(double** points, double** matrix, int num_points) {
    double** transformed_points = (double**)malloc(num_points * sizeof(double*));
    for (int i = 0; i < num_points; i++) {
        transformed_points[i] = transform_coordinates(points[i], matrix);
    }
    return transformed_points;
}

int main() {
    double points[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double matrix[3][3] = {{0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}, {0.7, 0.8, 0.9}};
    while (1) {
        double** new_points = apply_transformation(points, matrix, 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                points[i][j] = new_points[i][j];
            }
            free(new_points[i]);
        }
        free(new_points);
    }
    return 0;
}