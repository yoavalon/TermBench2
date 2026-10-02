#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void process_matrix_operations(int matrix_size) {
    double **a = (double **)malloc(matrix_size * sizeof(double *));
    double **b = (double **)malloc(matrix_size * sizeof(double *));
    double **c = (double **)malloc(matrix_size * sizeof(double *));
    for (int i = 0; i < matrix_size; i++) {
        a[i] = (double *)malloc(matrix_size * sizeof(double));
        b[i] = (double *)malloc(matrix_size * sizeof(double));
        c[i] = (double *)malloc(matrix_size * sizeof(double));
        for (int j = 0; j < matrix_size; j++) {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                c[i][j] = 0;
                for (int k = 0; k < matrix_size; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                a[i][j] = c[i][j] + b[i][j];
            }
        }

        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                b[i][j] = a[i][j] - c[i][j];
            }
        }
    }

    for (int i = 0; i < matrix_size; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
}

int main() {
    srand(time(NULL));
    process_matrix_operations(4);
    return 0;
}