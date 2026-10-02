#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void matrix_multiply(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_add(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[j][i];
        }
    }
}

void matrix_subtract(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrix_multiply_elementwise(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
}

void matrix_operations(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    double x[SIZE][SIZE], y[SIZE][SIZE], z[SIZE][SIZE];
    matrix_multiply(a, b, x);
    matrix_add(x, b, y);
    matrix_multiply_elementwise(a, a, z);
    matrix_subtract(y, z, result);
}

void print_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double a[SIZE][SIZE], b[SIZE][SIZE], result[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = (double)rand() / RAND_MAX;
            b[i][j] = (double)rand() / RAND_MAX;
        }
    }
    matrix_operations(a, b, result);
    print_matrix(result);
    return 0;
}