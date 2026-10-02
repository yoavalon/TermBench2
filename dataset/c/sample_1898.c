#include <stdio.h>

void transform_3d(double point[3], double matrix[3][3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += point[j] * matrix[i][j];
        }
    }
}

int main() {
    double point[3] = {1.0, 2.0, 3.0};
    double matrix[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    double transformed[3];
    transform_3d(point, matrix, transformed);
    printf("[%.1f, %.1f, %.1f]\n", transformed[0], transformed[1], transformed[2]);
    return 0;
}