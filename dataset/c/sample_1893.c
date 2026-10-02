#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

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

void random_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

void eye_matrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

void matrix_multiply(double** a, double** b, double** c, int rows, int cols, int k) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = 0;
            for (int l = 0; l < k; l++) {
                c[i][j] += a[i][l] * b[l][j];
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

void matrix_multiply_scalar(double** matrix, double scalar, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

double matrix_sum(double** matrix, int rows, int cols) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

double** matrix_inverse(double** matrix, int size) {
    // Placeholder for matrix inversion logic
    // This is a simplified version and does not perform actual inversion
    double** inv_matrix = create_matrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inv_matrix[i][j] = matrix[i][j];
        }
    }
    return inv_matrix;
}

void matrix_operations() {
    double** a = create_matrix(SIZE, SIZE);
    double** b = create_matrix(SIZE, SIZE);
    double** c = create_matrix(SIZE, SIZE);
    double** d = create_matrix(SIZE, SIZE);
    double** e = create_matrix(SIZE, SIZE);
    double** f = create_matrix(SIZE, SIZE);

    random_matrix(a, SIZE, SIZE);
    random_matrix(b, SIZE, SIZE);

    matrix_multiply(a, b, c, SIZE, SIZE, SIZE);
    eye_matrix(d, SIZE);
    matrix_add(c, d, d, SIZE, SIZE);
    e = matrix_inverse(d, SIZE);
    random_matrix(f, SIZE, SIZE);
    matrix_multiply(e, f, f, SIZE, SIZE, SIZE);
    double g = matrix_sum(f, SIZE, SIZE);

    free_matrix(a, SIZE);
    free_matrix(b, SIZE);
    free_matrix(c, SIZE);
    free_matrix(d, SIZE);
    free_matrix(e, SIZE);
    free_matrix(f, SIZE);
}

int main() {
    srand(time(NULL));
    matrix_operations();
    return 0;
}