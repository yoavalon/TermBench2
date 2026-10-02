#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS_A 3
#define COLS_A 4
#define ROWS_B 4
#define COLS_B 5
#define ROWS_C 3
#define COLS_C 5

double** create_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void randomize_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = ((double)rand() / RAND_MAX) * 1.0;
        }
    }
}

void matrix_multiply(double** a, double** b, double** c, int rows_a, int cols_a, int cols_b) {
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            c[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_add(double** a, double** b, double** c, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void apply_tanh(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = tanh(matrix[i][j]);
        }
    }
}

double** func(double** a, double** b, double** c, int rows_a, int cols_a, int cols_b, int rows_c, int cols_c) {
    double** x = create_matrix(rows_a, cols_b);
    double** y = create_matrix(rows_a, cols_c);
    double** z = create_matrix(rows_a, cols_c);

    matrix_multiply(a, b, x, rows_a, cols_a, cols_b);
    matrix_add(x, c, y, rows_a, cols_c);
    apply_tanh(y, rows_a, cols_c);

    free_matrix(x, rows_a);
    free_matrix(y, rows_a);

    return z;
}

int main() {
    double** a = create_matrix(ROWS_A, COLS_A);
    double** b = create_matrix(ROWS_B, COLS_B);
    double** c = create_matrix(ROWS_C, COLS_C);

    randomize_matrix(a, ROWS_A, COLS_A);
    randomize_matrix(b, ROWS_B, COLS_B);
    randomize_matrix(c, ROWS_C, COLS_C);

    double** result = func(a, b, c, ROWS_A, COLS_A, COLS_B, ROWS_C, COLS_C);

    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_C; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }

    free_matrix(a, ROWS_A);
    free_matrix(b, ROWS_B);
    free_matrix(c, ROWS_C);
    free_matrix(result, ROWS_A);

    return 0;
}