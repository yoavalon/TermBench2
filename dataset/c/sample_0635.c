#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 3
#define DEPTH 3

void forward_pass(double weights[INPUT_SIZE][INPUT_SIZE], double biases[INPUT_SIZE], double inputs[INPUT_SIZE], int depth, double outputs[INPUT_SIZE]) {
    if (depth == 0) {
        for (int i = 0; i < INPUT_SIZE; i++) {
            outputs[i] = inputs[i];
        }
        return;
    }

    double next_inputs[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        next_inputs[i] = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            next_inputs[i] += weights[i][j] * inputs[j];
        }
        next_inputs[i] += biases[i];
    }

    forward_pass(weights, biases, next_inputs, depth - 1, outputs);
}

int main() {
    srand(0);
    double weights[INPUT_SIZE][INPUT_SIZE];
    double biases[INPUT_SIZE];
    double inputs[INPUT_SIZE];
    double result[INPUT_SIZE];

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            weights[i][j] = (double)rand() / RAND_MAX;
        }
        biases[i] = (double)rand() / RAND_MAX;
        inputs[i] = (double)rand() / RAND_MAX;
    }

    forward_pass(weights, biases, inputs, DEPTH, result);

    for (int i = 0; i < INPUT_SIZE; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}