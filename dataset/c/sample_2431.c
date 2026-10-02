#include <stdio.h>

#define ROWS 2
#define COLS 2

void neural_net_forward_pass(double matrix[ROWS][COLS], double weights[ROWS][COLS], double bias[COLS], double result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double x = 0.0;
            for (int k = 0; k < COLS; k++) {
                x += matrix[i][k] * weights[k][j];
            }
            x += bias[j];
            result[i][j] = x > 0.0 ? x : 0.0;
        }
    }
}

int main() {
    double mat[ROWS][COLS] = {{1, 2}, {3, 4}};
    double w[ROWS][COLS] = {{0.5, -0.5}, {-0.5, 0.5}};
    double b[COLS] = {0.1, -0.1};
    double result[ROWS][COLS];

    neural_net_forward_pass(mat, w, b, result);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}