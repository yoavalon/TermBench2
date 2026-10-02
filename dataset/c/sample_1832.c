#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void matrix_transpose(double a[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[j][i];
        }
    }
}

void matrix_inverse(double a[SIZE][SIZE], double result[SIZE][SIZE]) {
    double det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
                a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
                a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    if (det == 0) {
        printf("Matrix is singular and cannot be inverted.\n");
        exit(1);
    }

    result[0][0] = (a[1][1] * a[2][2] - a[1][2] * a[2][1]) / det;
    result[0][1] = (a[0][2] * a[2][1] - a[0][1] * a[2][2]) / det;
    result[0][2] = (a[0][1] * a[1][2] - a[0][2] * a[1][1]) / det;
    result[1][0] = (a[1][2] * a[2][0] - a[1][0] * a[2][2]) / det;
    result[1][1] = (a[0][0] * a[2][2] - a[0][2] * a[2][0]) / det;
    result[1][2] = (a[0][2] * a[1][0] - a[0][0] * a[1][2]) / det;
    result[2][0] = (a[1][0] * a[2][1] - a[1][1] * a[2][0]) / det;
    result[2][1] = (a[0][1] * a[2][0] - a[0][0] * a[2][1]) / det;
    result[2][2] = (a[0][0] * a[1][1] - a[0][1] * a[1][0]) / det;
}

double matrix_sum(double a[SIZE][SIZE]) {
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

double matrix_ops(double a[SIZE][SIZE], double b[SIZE][SIZE]) {
    double x[SIZE][SIZE];
    double y[SIZE][SIZE];
    double z[SIZE][SIZE];

    matrix_multiply(a, b, x);
    matrix_transpose(x, y);
    matrix_add(x, y, y);
    matrix_inverse(y, z);

    return matrix_sum(z);
}

void generate_random_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = ((double)rand() / (double)RAND_MAX);
        }
    }
}

int main() {
    double a[SIZE][SIZE];
    double b[SIZE][SIZE];
    double result;

    srand(time(NULL));
    generate_random_matrix(a);
    generate_random_matrix(b);

    result = matrix_ops(a, b);
    printf("%f\n", result);

    return 0;
}