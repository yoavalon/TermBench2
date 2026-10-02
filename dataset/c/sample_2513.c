#include <stdio.h>

void transform_point(double x, double y, double z, double matrix[3][3], double result[3]) {
    result[0] = x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2];
    result[1] = x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2];
    result[2] = x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2];
}

void apply_sequence_transformations(double points[3][3], double sequence[3][3][3], double transformed_points[3][3]) {
    for (int i = 0; i < 3; i++) {
        double new_points[3][3];
        for (int j = 0; j < 3; j++) {
            transform_point(points[j][0], points[j][1], points[j][2], sequence[i], new_points[j]);
        }
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                points[k][l] = new_points[k][l];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transformed_points[i][j] = points[i][j];
        }
    }
}

int main() {
    double points[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double sequence[3][3][3] = {
        {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
        {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}},
        {{1, 0, 0}, {0, 1, 0}, {0, 0, -1}}
    };
    double transformed_points[3][3];
    apply_sequence_transformations(points, sequence, transformed_points);
    for (int i = 0; i < 3; i++) {
        printf("(%f, %f, %f)\n", transformed_points[i][0], transformed_points[i][1], transformed_points[i][2]);
    }
    return 0;
}