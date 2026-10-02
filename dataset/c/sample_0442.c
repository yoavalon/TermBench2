#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

double activation(double x) {
    return fmax(0, x);
}

void forward_pass(double *weights, double *biases, double *inputs, double *outputs) {
    for (int i = 0; i < SIZE; i++) {
        double z = 0;
        for (int j = 0; j < SIZE; j++) {
            z += weights[i * SIZE + j] * inputs[j];
        }
        z += biases[i];
        outputs[i] = activation(z);
    }
}

int main() {
    srand(0);
    double weights[SIZE * SIZE];
    double biases[SIZE];
    double inputs[SIZE];
    double outputs[SIZE];

    for (int i = 0; i < SIZE * SIZE; i++) {
        weights[i] = (double)rand() / RAND_MAX;
    }
    for (int i = 0; i < SIZE; i++) {
        biases[i] = (double)rand() / RAND_MAX;
        inputs[i] = (double)rand() / RAND_MAX;
    }

    while (1) {
        forward_pass(weights, biases, inputs, outputs);
        for (int i = 0; i < SIZE; i++) {
            inputs[i] = outputs[i];
        }
    }

    return 0;
}