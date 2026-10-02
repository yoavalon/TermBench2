#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double* forward_pass(double* weights, double* biases, double* inputs, int rows, int cols) {
    static double output[10];
    for (int i = 0; i < rows; i++) {
        double z = biases[i];
        for (int j = 0; j < cols; j++) {
            z += weights[i * cols + j] * inputs[j];
        }
        output[i] = sigmoid(z);
    }
    return output;
}

int main() {
    srand(0);
    double weights[10 * 5];
    double biases[10];
    double inputs[5];

    for (int i = 0; i < 10 * 5; i++) {
        weights[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    for (int i = 0; i < 10; i++) {
        biases[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    for (int i = 0; i < 5; i++) {
        inputs[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    double* output = forward_pass(weights, biases, inputs, 10, 5);
    for (int i = 0; i < 10; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    return 0;
}