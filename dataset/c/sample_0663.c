#include <stdio.h>
#include <stdlib.h>

#define ROWS_A 10
#define COLS_A 5
#define COLS_W 5

void matrix_multiply(float* A, float* B, float* C, int rows, int cols_A, int cols_B) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols_B; j++) {
            C[i * cols_B + j] = 0;
            for (int k = 0; k < cols_A; k++) {
                C[i * cols_B + j] += A[i * cols_A + k] * B[k * cols_B + j];
            }
        }
    }
}

void matrix_add(float* A, float* B, float* C, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i * cols + j] = A[i * cols + j] + B[j];
        }
    }
}

void matrix_forward_pass(float* matrix, float* weights, float* bias, int depth, int rows, int cols) {
    if (depth == 0) {
        return;
    }
    float* temp = (float*)malloc(rows * cols * sizeof(float));
    matrix_multiply(matrix, weights, temp, rows, cols, cols);
    matrix_add(temp, bias, matrix, rows, cols);
    free(temp);
    matrix_forward_pass(matrix, weights, bias, depth - 1, rows, cols);
}

int main() {
    float* A = (float*)malloc(ROWS_A * COLS_A * sizeof(float));
    float* W = (float*)malloc(COLS_A * COLS_W * sizeof(float));
    float* B = (float*)malloc(COLS_W * sizeof(float));

    for (int i = 0; i < ROWS_A * COLS_A; i++) {
        A[i] = (float)rand() / RAND_MAX;
    }
    for (int i = 0; i < COLS_A * COLS_W; i++) {
        W[i] = (float)rand() / RAND_MAX;
    }
    for (int i = 0; i < COLS_W; i++) {
        B[i] = (float)rand() / RAND_MAX;
    }

    int depth = 3;
    matrix_forward_pass(A, W, B, depth, ROWS_A, COLS_W);

    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_W; j++) {
            printf("%.2f ", A[i * COLS_W + j]);
        }
        printf("\n");
    }

    free(A);
    free(W);
    free(B);

    return 0;
}