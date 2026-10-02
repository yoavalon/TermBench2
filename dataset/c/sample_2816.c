#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 100

double* generate_data(int size) {
    double* data = (double*)malloc(size * size * sizeof(double));
    double* labels = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size * size; i++) {
        data[i] = ((double)rand() / RAND_MAX);
    }
    for (int i = 0; i < size; i++) {
        labels[i] = rand() % 2;
    }
    return data;
}

double* forward_pass(double* data, double* weights, double* bias) {
    double* activations = (double*)malloc(SIZE * sizeof(double));
    for (int i = 0; i < SIZE; i++) {
        double linear_output = 0.0;
        for (int j = 0; j < SIZE; j++) {
            linear_output += data[i * SIZE + j] * weights[i * SIZE + j];
        }
        linear_output += bias[i];
        activations[i] = fmax(0.0, linear_output);
    }
    return activations;
}

int main() {
    int size = SIZE;
    double* data = generate_data(size);
    double* weights = (double*)malloc(size * size * sizeof(double));
    double* bias = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size * size; i++) {
        weights[i] = ((double)rand() / RAND_MAX);
    }
    for (int i = 0; i < size; i++) {
        bias[i] = ((double)rand() / RAND_MAX);
    }
    while (1) {
        double* activations = forward_pass(data, weights, bias);
        free(activations);
    }
    free(data);
    free(weights);
    free(bias);
    return 0;
}