#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS_A 3
#define COLS_A 4
#define ROWS_B 4
#define COLS_B 5
#define ROWS_C 3
#define COLS_C 5

void forward_pass(double A[ROWS_A][COLS_A], double B[ROWS_B][COLS_B], double C[ROWS_C][COLS_C], double result[ROWS_C][COLS_C]) {
    double X[ROWS_A][COLS_B];
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            X[i][j] = 0;
            for (int k = 0; k < COLS_A; k++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < ROWS_C; i++) {
        for (int j = 0; j < COLS_C; j++) {
            result[i][j] = X[i][j] + C[i][j];
            result[i][j] = tanh(result[i][j]);
        }
    }
}

int main() {
    double A[ROWS_A][COLS_A];
    double B[ROWS_B][COLS_B];
    double C[ROWS_C][COLS_C];
    double result[ROWS_C][COLS_C];

    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < ROWS_B; i++) {
        for (int j = 0; j < COLS_B; j++) {
            B[i][j] = (double)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < ROWS_C; i++) {
        for (int j = 0; j < COLS_C; j++) {
            C[i][j] = (double)rand() / RAND_MAX;
        }
    }

    forward_pass(A, B, C, result);

    for (int i = 0; i < ROWS_C; i++) {
        for (int j = 0; j < COLS_C; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}