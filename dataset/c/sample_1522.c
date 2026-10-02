#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void matrix_ops() {
    while (1) {
        double x[SIZE][SIZE], y[SIZE][SIZE], z[SIZE][SIZE], w[SIZE][SIZE], v[SIZE][SIZE];
        int i, j, k;

        // Generate random matrices x and y
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                x[i][j] = (double)rand() / RAND_MAX;
                y[i][j] = (double)rand() / RAND_MAX;
            }
        }

        // Compute z = x * y
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                z[i][j] = 0;
                for (k = 0; k < SIZE; k++) {
                    z[i][j] += x[i][k] * y[k][j];
                }
            }
        }

        // Compute w = z + y^T
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                w[i][j] = z[i][j] + y[j][i];
            }
        }

        // Compute v = w - I
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                v[i][j] = w[i][j] - (i == j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    matrix_ops();
    return 0;
}