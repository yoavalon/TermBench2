#include <stdio.h>

#define ROWS 3
#define COLS 3

void transform_sequence(int points[][3], int matrix[ROWS][COLS], int result[][ROWS], int num_points) {
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < ROWS; j++) {
            int transformed = 0;
            for (int k = 0; k < COLS; k++) {
                transformed += matrix[j][k] * points[i][k];
            }
            result[i][j] = transformed;
        }
    }
}

int main() {
    int sequence[][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrix[ROWS][COLS] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    int transformed_sequence[2][ROWS];

    transform_sequence(sequence, matrix, transformed_sequence, 2);

    for (int i = 0; i < 2; i++) {
        printf("[");
        for (int j = 0; j < ROWS; j++) {
            printf("%d", transformed_sequence[i][j]);
            if (j < ROWS - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    return 0;
}