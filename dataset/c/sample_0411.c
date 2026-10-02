#include <stdio.h>

void transform_coordinates(int x, int y, int z, int matrix[3][3], int result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                result[i] += x * matrix[i][j];
            } else if (j == 1) {
                result[i] += y * matrix[i][j];
            } else {
                result[i] += z * matrix[i][j];
            }
        }
    }
}

void apply_transformation(int iterations, int *x, int *y, int *z) {
    int matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int result[3];
    for (int _ = 0; _ < iterations; _++) {
        transform_coordinates(*x, *y, *z, matrix, result);
        *x = result[0];
        *y = result[1];
        *z = result[2];
        matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0;
        matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0;
        matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
    }
}

void main() {
    while (1) {
        int x = 1, y = 1, z = 1;
        apply_transformation(100, &x, &y, &z);
        printf("(%d, %d, %d)\n", x, y, z);
    }
}