#include <stdio.h>
#include <math.h>

#define MATRIX_ROWS 2
#define MATRIX_COLS 2
#define WEIGHTS_ROWS 2
#define WEIGHTS_COLS 2

void forward_pass(double matrix[MATRIX_ROWS][MATRIX_COLS], double weights[WEIGHTS_ROWS][WEIGHTS_COLS], double result[MATRIX_ROWS][MATRIX_COLS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_COLS; k++) {
                result[i][j] += matrix[i][k] * weights[k][j];
            }
            result[i][j] = tanh(result[i][j]);
        }
    }
}

int main() {
    double weights[WEIGHTS_ROWS][WEIGHTS_COLS] = {{0.2, 0.5}, {0.4, 0.3}};
    double matrix[MATRIX_ROWS][MATRIX_COLS] = {{0.1, 0.2}, {0.3, 0.4}};
    double result[MATRIX_ROWS][MATRIX_COLS];

    forward_pass(matrix, weights, result);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}