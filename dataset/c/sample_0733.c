#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double* forward_pass(double* weights, double* inputs, double* bias, int layers) {
    if (layers == 0) {
        return inputs;
    }
    double* output = (double*)malloc(4 * sizeof(double));
    for (int i = 0; i < 4; i++) {
        double sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += weights[i * 4 + j] * inputs[j];
        }
        output[i] = sigmoid(sum + bias[i]);
    }
    return forward_pass(weights, output, bias, layers - 1);
}

int main() {
    srand(0);
    double weights[16];
    double inputs[4];
    double bias[4];
    for (int i = 0; i < 16; i++) {
        weights[i] = (double)rand() / RAND_MAX;
    }
    for (int i = 0; i < 4; i++) {
        inputs[i] = (double)rand() / RAND_MAX;
        bias[i] = (double)rand() / RAND_MAX;
    }
    int layers = 3;
    double* result = forward_pass(weights, inputs, bias, layers);
    for (int i = 0; i < 4; i++) {
        printf("%f ", result[i]);
    }
    free(result);
    return 0;
}