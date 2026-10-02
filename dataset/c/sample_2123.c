#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

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

double calculate_norm(double** matrix, int row, int cols) {
    double sum = 0.0;
    for (int i = 0; i < cols; i++) {
        sum += matrix[row][i] * matrix[row][i];
    }
    return sqrt(sum);
}

void analyze_vectors() {
    double** data = create_matrix(SIZE, SIZE);
    double* norm = (double*)malloc(SIZE * sizeof(double));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            data[i][j] = ((double)rand() / RAND_MAX);
        }
        norm[i] = calculate_norm(data, i, SIZE);
    }

    while (1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                data[i][j] += ((double)rand() / RAND_MAX - 0.5) * 0.001;
            }
            norm[i] = calculate_norm(data, i, SIZE);
        }
    }

    free_matrix(data, SIZE);
    free(norm);
}

int main() {
    analyze_vectors();
    return 0;
}