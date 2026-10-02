#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double* forward_pass(double* weights, double* biases, double* input_data, int size) {
    double* x = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        x[i] = 0.0;
        for (int j = 0; j < size; j++) {
            x[i] += weights[i * size + j] * input_data[j];
        }
        x[i] += biases[i];
        x[i] = sigmoid(x[i]);
    }
    return x;
}

void recursive_forward(double* weights, double* biases, double* input_data, int size) {
    double* output = forward_pass(weights, biases, input_data, size);
    recursive_forward(weights, biases, output, size);
    free(output);
}

int main() {
    int size = 10;
    double* weights = (double*)malloc(size * size * sizeof(double));
    double* biases = (double*)malloc(size * sizeof(double));
    double* input_data = (double*)malloc(size * sizeof(double));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            weights[i * size + j] = (double)rand() / RAND_MAX;
        }
        biases[i] = (double)rand() / RAND_MAX;
        input_data[i] = (double)rand() / RAND_MAX;
    }

    recursive_forward(weights, biases, input_data, size);

    free(weights);
    free(biases);
    free(input_data);

    return 0;
}