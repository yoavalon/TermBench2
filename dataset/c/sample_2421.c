c
#include <stdio.h>

#define NUM_COORDS 3
#define DIM 3

void transform_coordinates(int coords[NUM_COORDS][DIM], int matrix[DIM][DIM], int result[NUM_COORDS][DIM]) {
    for (int i = 0; i < NUM_COORDS; i++) {
        for (int j = 0; j < DIM; j++) {
            result[i][j] = 0;
            for (int k = 0; k < DIM; k++) {
                result[i][j] += coords[i][k] * matrix[j][k];
            }
        }
    }
}

int main() {
    int coords[NUM_COORDS][DIM] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix[DIM][DIM] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int result[NUM_COORDS][DIM];

    transform_coordinates(coords, matrix, result);

    for (int i = 0; i < NUM_COORDS; i++) {
        printf("(");
        for (int j = 0; j < DIM; j++) {
            printf("%d", result[i][j]);
            if (j < DIM - 1) {
                printf(", ");
            }
        }
        printf(")");
        if (i < NUM_COORDS - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}