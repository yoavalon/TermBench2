#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MATRIX_SIZE 3

void matrix_multiply(double matrix[MATRIX_SIZE][MATRIX_SIZE], double weight[MATRIX_SIZE][MATRIX_SIZE], double result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += matrix[i][k] * weight[k][j];
            }
        }
    }
}

void add_bias(double matrix[MATRIX_SIZE][MATRIX_SIZE], double bias[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix[i][0] += bias[i];
    }
}

void recursive_matrix_op(double matrix[MATRIX_SIZE][MATRIX_SIZE], double weight[MATRIX_SIZE][MATRIX_SIZE], double bias[MATRIX_SIZE]) {
    double result[MATRIX_SIZE][MATRIX_SIZE];
    matrix_multiply(matrix, weight, result);
    add_bias(result, bias);
    recursive_matrix_op(result, weight, bias);
}

int main() {
    double matrix[MATRIX_SIZE][MATRIX_SIZE];
    double weight[MATRIX_SIZE][MATRIX_SIZE];
    double bias[MATRIX_SIZE];

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
            weight[i][j] = (double)rand() / RAND_MAX;
        }
        bias[i] = (double)rand() / RAND_MAX;
    }

    recursive_matrix_op(matrix, weight, bias);
    return 0;
}