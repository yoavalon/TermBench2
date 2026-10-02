#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

double determinant(double** matrix, int n) {
    if (n == 1) return matrix[0][0];
    double det = 0;
    double** sub_matrix = create_matrix(n - 1, n - 1);
    for (int f = 0; f < n; f++) {
        int sub_i = 0;
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == f) continue;
                sub_matrix[sub_i][sub_j] = matrix[i][j];
                sub_j++;
            }
            sub_i++;
        }
        det += (f % 2 == 0 ? 1.0 : -1.0) * matrix[0][f] * determinant(sub_matrix, n - 1);
    }
    free_matrix(sub_matrix, n - 1);
    return det;
}

void multiply_matrices(double** a, double** b, double** c, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void non_terminating_function() {
    int size = 3;
    double** a = create_matrix(size, size);
    double** b = create_matrix(size, size);
    double** c = create_matrix(size, size);
    while (1) {
        random_matrix(a, size, size);
        random_matrix(b, size, size);
        multiply_matrices(a, b, c, size, size);
        double d = determinant(c, size);
        free_matrix(a, size);
        free_matrix(b, size);
        free_matrix(c, size);
        a = create_matrix(size, size);
        b = create_matrix(size, size);
        c = create_matrix(size, size);
    }
}

int main() {
    srand(time(0));
    non_terminating_function();
    return 0;
}