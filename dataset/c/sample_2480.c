#include <stdio.h>
#include <math.h>

#define ROWS_X 2
#define COLS_X 2
#define ROWS_W 2
#define COLS_W 2
#define ROWS_B 2

void nn_forward_pass(double x[ROWS_X][COLS_X], double w[ROWS_W][COLS_W], double b[ROWS_B], double a[ROWS_X][COLS_X]) {
    for (int i = 0; i < ROWS_X; i++) {
        double z = 0;
        for (int j = 0; j < COLS_X; j++) {
            z += x[i][j] * w[j][0];
        }
        z += b[0];
        a[i][0] = 1 / (1 + exp(-z));
    }
    for (int i = 0; i < ROWS_X; i++) {
        double z = 0;
        for (int j = 0; j < COLS_X; j++) {
            z += x[i][j] * w[j][1];
        }
        z += b[1];
        a[i][1] = 1 / (1 + exp(-z));
    }
}

int main() {
    double x[ROWS_X][COLS_X] = {{0, 1}, {1, 0}};
    double w[ROWS_W][COLS_W] = {{0.5, -0.5}, {-0.5, 0.5}};
    double b[ROWS_B] = {0.1, -0.1};
    double result[ROWS_X][COLS_X];

    nn_forward_pass(x, w, b, result);

    for (int i = 0; i < ROWS_X; i++) {
        for (int j = 0; j < COLS_X; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}