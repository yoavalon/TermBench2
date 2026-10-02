#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS_X 3
#define COLS_X 4
#define ROWS_W 4
#define COLS_W 5
#define COLS_B 5

void matrix_op(double x[ROWS_X][COLS_X], double w[ROWS_W][COLS_W], double b[1][COLS_B], double a[ROWS_X][COLS_W]) {
    for (int i = 0; i < ROWS_X; i++) {
        for (int j = 0; j < COLS_W; j++) {
            double z = 0;
            for (int k = 0; k < COLS_X; k++) {
                z += x[i][k] * w[k][j];
            }
            z += b[0][j];
            a[i][j] = z > 0 ? z : 0;
        }
    }
}

int main() {
    srand(time(NULL));

    double x[ROWS_X][COLS_X];
    double w[ROWS_W][COLS_W];
    double b[1][COLS_B];
    double result[ROWS_X][COLS_W];

    for (int i = 0; i < ROWS_X; i++) {
        for (int j = 0; j < COLS_X; j++) {
            x[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < ROWS_W; i++) {
        for (int j = 0; j < COLS_W; j++) {
            w[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (int j = 0; j < COLS_B; j++) {
        b[0][j] = (double)rand() / RAND_MAX;
    }

    matrix_op(x, w, b, result);

    for (int i = 0; i < ROWS_X; i++) {
        for (int j = 0; j < COLS_W; j++) {
            printf("%.6f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}