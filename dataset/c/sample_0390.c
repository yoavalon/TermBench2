#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

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

void fill_random_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

void process_matrices() {
    double a[SIZE][SIZE];
    double b[SIZE][SIZE];
    double temp[SIZE][SIZE];

    srand(time(NULL));
    fill_random_matrix(a);
    fill_random_matrix(b);

    while (1) {
        multiply_matrices(a, b, temp);
        multiply_matrices(b, a, a);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                b[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    process_matrices();
    return 0;
}