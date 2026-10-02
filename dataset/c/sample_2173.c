#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

double dot_product(double* row, double** matrix, int cols) {
    double sum = 0.0;
    for (int j = 0; j < cols; j++) {
        sum += row[j] * matrix[j][0];
    }
    return sum;
}

void matrix_multiply(double** a, double** b, double** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        result[i][0] = dot_product(a[i], b, cols);
    }
}

double tanh_function(double x) {
    return tanh(x);
}

void apply_tanh(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        matrix[i][0] = tanh_function(matrix[i][0]);
    }
}

void neural_network_pass(double** a, double** b, int rows, int cols) {
    double** result = create_matrix(rows, 1);
    while (1) {
        matrix_multiply(a, b, result, rows, cols);
        for (int i = 0; i < rows; i++) {
            a[i][0] = result[i][0];
        }
        apply_tanh(a, rows);
    }
    free_matrix(result, rows);
}

int main() {
    int rows = 10, cols = 10;
    double** a = create_matrix(rows, cols);
    double** b = create_matrix(rows, cols);
    randomize_matrix(a, rows, cols);
    randomize_matrix(b, rows, cols);
    neural_network_pass(a, b, rows, cols);
    free_matrix(a, rows);
    free_matrix(b, rows);
    return 0;
}