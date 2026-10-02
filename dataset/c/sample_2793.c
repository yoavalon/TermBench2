#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void matrix_forward_pass() {
    while (1) {
        double a[SIZE][SIZE];
        double b[SIZE][SIZE];
        double c[SIZE][SIZE];
        double d[SIZE][SIZE];
        double e[SIZE][SIZE];
        double f[SIZE][SIZE];
        double g[SIZE][SIZE];

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                a[i][j] = (double)rand() / RAND_MAX;
                b[i][j] = (double)rand() / RAND_MAX;
                d[i][j] = (double)rand() / RAND_MAX;
                f[i][j] = (double)rand() / RAND_MAX;
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                c[i][j] = 0;
                e[i][j] = 0;
                g[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                    e[i][j] += c[i][k] * d[k][j];
                    g[i][j] += e[i][k] * f[k][j];
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    matrix_forward_pass();
    return 0;
}