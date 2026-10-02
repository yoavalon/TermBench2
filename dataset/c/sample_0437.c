#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT_SIZE 10
#define OUTPUT_SIZE 5
#define DATA_SIZE 100

double** initialize_weights(int input_size, int output_size) {
    double** weights = (double**)malloc(input_size * sizeof(double*));
    for (int i = 0; i < input_size; i++) {
        weights[i] = (double*)malloc(output_size * sizeof(double));
        for (int j = 0; j < output_size; j++) {
            weights[i][j] = (double)rand() / RAND_MAX * 2 - 1;
        }
    }
    return weights;
}

double* forward_pass(double* inputs, double** weights, int input_size, int output_size) {
    double* result = (double*)malloc(output_size * sizeof(double));
    for (int i = 0; i < output_size; i++) {
        result[i] = 0;
        for (int j = 0; j < input_size; j++) {
            result[i] += inputs[j] * weights[j][i];
        }
    }
    return result;
}

double** process_data(double** data, double** weights, int data_size, int input_size, int output_size) {
    double** results = (double**)malloc(data_size * sizeof(double*));
    for (int i = 0; i < data_size; i++) {
        results[i] = forward_pass(data[i], weights, input_size, output_size);
    }
    return results;
}

void free_memory(double** array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    srand(time(NULL));
    double** data = (double**)malloc(DATA_SIZE * sizeof(double*));
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = (double*)malloc(INPUT_SIZE * sizeof(double));
        for (int j = 0; j < INPUT_SIZE; j++) {
            data[i][j] = (double)rand() / RAND_MAX * 2 - 1;
        }
    }

    double** weights = initialize_weights(INPUT_SIZE, OUTPUT_SIZE);

    while (1) {
        double** outputs = process_data(data, weights, DATA_SIZE, INPUT_SIZE, OUTPUT_SIZE);
        free_memory(weights, INPUT_SIZE);
        weights = initialize_weights(INPUT_SIZE, OUTPUT_SIZE);
        free_memory(outputs, DATA_SIZE);
    }

    free_memory(data, DATA_SIZE);
    return 0;
}