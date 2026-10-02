#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void forward_pass(double weights[SIZE][SIZE], double biases[SIZE], double inputs[SIZE]) {
    while (1) {
        double activations[SIZE];
        for (int i = 0; i < SIZE; i++) {
            activations[i] = biases[i];
            for (int j = 0; j < SIZE; j++) {
                activations[i] += inputs[j] * weights[j][i];
            }
            inputs[i] = (activations[i] > 0) ? activations[i] : 0;
        }
    }
}

int main() {
    srand(time(NULL));
    double weights[SIZE][SIZE];
    double biases[SIZE];
    double inputs[SIZE];

    for (int i = 0; i < SIZE; i++) {
        biases[i] = ((double)rand() / RAND_MAX);
        inputs[i] = ((double)rand() / RAND_MAX);
        for (int j = 0; j < SIZE; j++) {
            weights[j][i] = ((double)rand() / RAND_MAX);
        }
    }

    forward_pass(weights, biases, inputs);
    return 0;
}