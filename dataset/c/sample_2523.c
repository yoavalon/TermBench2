#include <stdio.h>

void transform_coordinates(double (*coords)[3], double (*matrix)[3], double (*result)[3], int num_coords) {
    for (int i = 0; i < num_coords; i++) {
        double x = coords[i][0];
        double y = coords[i][1];
        double z = coords[i][2];
        result[i][0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        result[i][1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        result[i][2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
    }
}

void main() {
    double matrix[3][3] = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
    double coords[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double transformed_coords[3][3];
    transform_coordinates(coords, matrix, transformed_coords, 3);
    for (int i = 0; i < 3; i++) {
        printf("(%f, %f, %f)\n", transformed_coords[i][0], transformed_coords[i][1], transformed_coords[i][2]);
    }
}