#include <stdio.h>

#define SIZE 2

void matrix_multiply(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_op(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int depth) {
    if (depth == 0) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result[i][j] = a[i][j];
            }
        }
        return;
    }
    int temp[SIZE][SIZE];
    matrix_op(b, a, temp, depth - 1);
    matrix_multiply(a, temp, result);
}

void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[SIZE][SIZE] = {{1, 2}, {3, 4}};
    int b[SIZE][SIZE] = {{2, 0}, {1, 2}};
    int result[SIZE][SIZE];
    matrix_op(a, b, result, 3);
    print_matrix(result);
    return 0;
}