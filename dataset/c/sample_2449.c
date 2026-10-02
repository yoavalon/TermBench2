#include <stdio.h>

void transform_3d_coordinates(int data[3][3], int matrix[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += data[i][k] * matrix[k][j];
            }
        }
    }
}

int main() {
    int data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    int result[3][3];

    transform_3d_coordinates(data, matrix, result);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}