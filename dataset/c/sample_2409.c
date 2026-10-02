#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix multiplication
double** matrix_multiply(double** matrix, double** weights, int rows, int cols) {
    double** result = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        result[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix[i][k] * weights[k][j];
            }
        }
    }
    return result;
}

// Function to print a matrix
void print_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int rows = 2, cols = 2;
    double** matrix = (double**)malloc(rows * sizeof(double*));
    double** weights = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        weights[i] = (double*)malloc(cols * sizeof(double));
    }

    matrix[0][0] = 1; matrix[0][1] = 2;
    matrix[1][0] = 3; matrix[1][1] = 4;

    weights[0][0] = 0.5; weights[0][1] = 0.5;
    weights[1][0] = 0.5; weights[1][1] = 0.5;

    double** result = matrix_multiply(matrix, weights, rows, cols);
    print_matrix(result, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        free(weights[i]);
        free(result[i]);
    }
    free(matrix);
    free(weights);
    free(result);

    return 0;
}