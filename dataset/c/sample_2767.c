#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_operations() {
    double a[3][3], b[3][3], c[3][3];

    // Seed the random number generator
    srand(time(NULL));

    // Initialize matrices a and b with random values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        // Matrix multiplication c = a * b
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        // Matrix addition a = c + b
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = c[i][j] + b[i][j];
            }
        }

        // Matrix subtraction b = a - c
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = a[i][j] - c[i][j];
            }
        }
    }
}

int main() {
    matrix_operations();
    return 0;
}