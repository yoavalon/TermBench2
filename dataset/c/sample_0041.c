#include <stdio.h>
#include <stdlib.h>

void transform_coordinates(int coords[2][3], int matrix[3][3], int result[2][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += coords[i][k] * matrix[k][j];
            }
        }
    }
}

int main() {
    int coords[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrix[3][3] = {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
    int result[2][3];
    
    transform_coordinates(coords, matrix, result);
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}