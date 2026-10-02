#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 5

double** init_weights(int size) {
    double** weights = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        weights[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            weights[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    return weights;
}

double** forward_pass(double** input_data, double** weights, int size) {
    double** result = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        result[i] = (double*)malloc(sizeof(double));
        result[i][0] = 0;
        for (int j = 0; j < size; j++) {
            result[i][0] += input_data[i][j] * weights[j][0];
        }
    }
    return result;
}

int terminate_condition(double** data, int size) {
    for (int i = 0; i < size; i++) {
        if (data[i][0] >= 0.1) {
            return 0;
        }
    }
    return 1;
}

void free_memory(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    srand(time(NULL));
    int size = SIZE;
    double** weights = init_weights(size);
    double** data = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        data[i] = (double*)malloc(sizeof(double));
        data[i][0] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    while (1) {
        double** new_data = forward_pass(data, weights, size);
        free_memory(data, size);
        data = new_data;
        if (terminate_condition(data, size)) {
            break;
        }
    }

    free_memory(data, size);
    free_memory(weights, size);
    return 0;
}