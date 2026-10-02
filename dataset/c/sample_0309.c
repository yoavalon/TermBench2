#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void matrix_operations() {
    double x[SIZE][SIZE];
    double y[SIZE][SIZE];
    double result[SIZE][SIZE];
    int i, j, k;

    // Initialize random seed
    srand(time(0));

    // Generate random matrices x and y
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            x[i][j] = (double)rand() / RAND_MAX;
            y[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        // Matrix multiplication x = x * y
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                result[i][j] = 0;
                for (k = 0; k < SIZE; k++) {
                    result[i][j] += x[i][k] * y[k][j];
                }
            }
        }
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                x[i][j] = result[i][j];
            }
        }

        // Matrix multiplication y = y * x
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                result[i][j] = 0;
                for (k = 0; k < SIZE; k++) {
                    result[i][j] += y[i][k] * x[k][j];
                }
            }
        }
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                y[i][j] = result[i][j];
            }
        }
    }
}

int main() {
    matrix_operations();
    return 0;
}