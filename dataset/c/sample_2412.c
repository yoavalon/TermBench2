#include <stdio.h>

#define ROWS 2
#define COLS 2

void forward_pass(double matrix[ROWS][COLS], double weights[ROWS][COLS], double bias[ROWS], double result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double sum = 0;
            for (int k = 0; k < COLS; k++) {
                sum += matrix[i][k] * weights[k][j];
            }
            result[i][j] = sum + bias[j];
            if (result[i][j] < 0) {
                result[i][j] = 0;
            }
        }
    }
}

int main() {
    double matrix[ROWS][COLS] = {{1, 2}, {3, 4}};
    double weights[ROWS][COLS] = {{0.1, 0.2}, {0.3, 0.4}};
    double bias[ROWS] = {0.1, 0.2};
    double result[ROWS][COLS];

    forward_pass(matrix, weights, bias, result);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}