#include <stdio.h>
#include <stdlib.h>

void transform_coordinates(int points[3][3], int matrix[3][3], int transformed[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transformed[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                transformed[i][j] += points[i][k] * matrix[k][j];
            }
        }
    }
}

int main() {
    int points[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    int transformed[3][3];

    transform_coordinates(points, matrix, transformed);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transformed[i][j]);
        }
        printf("\n");
    }

    return 0;
}