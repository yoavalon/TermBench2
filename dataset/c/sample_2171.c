#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void multiply_matrices(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void process_matrices(double a[SIZE][SIZE], double b[SIZE][SIZE], double c[SIZE][SIZE]) {
    double x[SIZE][SIZE], y[SIZE][SIZE], z[SIZE][SIZE], w[SIZE][SIZE], v[SIZE][SIZE];
    while (1) {
        multiply_matrices(a, b, x);
        multiply_matrices(x, c, y);
        multiply_matrices(y, a, z);
        multiply_matrices(z, b, w);
        multiply_matrices(w, c, v);
    }
}

void initialize_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

int main() {
    double a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
    srand(time(0));
    initialize_matrix(a);
    initialize_matrix(b);
    initialize_matrix(c);
    process_matrices(a, b, c);
    return 0;
}