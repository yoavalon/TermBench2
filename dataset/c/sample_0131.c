#include <stdio.h>

void transform_coordinates(int coords[3][3], int matrix[3][3], int result[3][3]) {
    for (int k = 0; k < 3; k++) {
        int new_coord[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                new_coord[i] += coords[k][j] * matrix[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            result[k][i] = new_coord[i];
        }
    }
}

void main() {
    int coords[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    int transformed[3][3];
    transform_coordinates(coords, matrix, transformed);
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d", transformed[i][j]);
            if (j < 2) printf(", ");
        }
        printf("]");
        if (i < 2) printf(", ");
    }
    printf("\n");
}