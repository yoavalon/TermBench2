#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix* matrix_new(int** data, int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->data = data;
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

Matrix* matrix_multiply(Matrix* A, Matrix* B) {
    if (A->cols != B->rows) {
        fprintf(stderr, "Matrix dimensions do not match for multiplication\n");
        exit(1);
    }
    int** result = (int**)malloc(A->rows * sizeof(int*));
    for (int i = 0; i < A->rows; i++) {
        result[i] = (int*)malloc(B->cols * sizeof(int));
        for (int j = 0; j < B->cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < A->cols; k++) {
                result[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
    return matrix_new(result, A->rows, B->cols);
}

void matrix_print(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* matrix_multiply_recursive(Matrix* A, Matrix* B, int** result, int i, int j, int k) {
    if (i == A->rows) return matrix_new(result, A->rows, B->cols);
    if (j == B->cols) return matrix_multiply_recursive(A, B, result, i + 1, 0, 0);
    if (k == A->cols) return matrix_multiply_recursive(A, B, result, i, j + 1, 0);
    result[i][j] += A->data[i][k] * B->data[k][j];
    return matrix_multiply_recursive(A, B, result, i, j, k + 1);
}

Matrix* forward_pass(Matrix** weights, int weights_len, Matrix* inputs) {
    if (weights_len == 0) return inputs;
    Matrix* next_layer = matrix_multiply(weights[0], inputs);
    return forward_pass(weights + 1, weights_len - 1, next_layer);
}

int main() {
    int dataA[2][2] = {{1, 2}, {3, 4}};
    int dataB[2][2] = {{2, 0}, {1, 2}};
    Matrix* A = matrix_new((int**)dataA, 2, 2);
    Matrix* B = matrix_new((int**)dataB, 2, 2);
    printf("Recursive Matrix Multiplication:\n");
    int** result = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
        }
    }
    Matrix* result_matrix = matrix_multiply_recursive(A, B, result, 0, 0, 0);
    matrix_print(result_matrix);

    int dataW1[2][2] = {{1, 0}, {0, 1}};
    int dataW2[2][2] = {{2, 3}, {4, 5}};
    int dataI[2][1] = {{1}, {2}};
    Matrix* weights[2] = {matrix_new((int**)dataW1, 2, 2), matrix_new((int**)dataW2, 2, 2)};
    Matrix* inputs = matrix_new((int**)dataI, 2, 1);
    printf("\nNeural Network Forward Pass:\n");
    Matrix* output = forward_pass(weights, 2, inputs);
    matrix_print(output);

    return 0;
}