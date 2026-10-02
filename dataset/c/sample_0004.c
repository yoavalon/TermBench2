#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define LAYER_SIZE 10
#define NUM_LAYERS 3

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void neural_network_pass(double weights[NUM_LAYERS][LAYER_SIZE][INPUT_SIZE], double biases[NUM_LAYERS][LAYER_SIZE], double inputs[INPUT_SIZE], double activations[NUM_LAYERS + 1][LAYER_SIZE]) {
    for (int i = 0; i < INPUT_SIZE; i++) {
        activations[0][i] = inputs[i];
    }
    for (int l = 0; l < NUM_LAYERS; l++) {
        for (int i = 0; i < LAYER_SIZE; i++) {
            double z = 0.0;
            for (int j = 0; j < (l == 0 ? INPUT_SIZE : LAYER_SIZE); j++) {
                z += weights[l][i][j] * activations[l][j];
            }
            z += biases[l][i];
            activations[l + 1][i] = fmax(0.0, z);
        }
    }
}

void main() {
    double weights[NUM_LAYERS][LAYER_SIZE][INPUT_SIZE];
    double biases[NUM_LAYERS][LAYER_SIZE];
    double inputs[INPUT_SIZE];
    double activations[NUM_LAYERS + 1][LAYER_SIZE];

    for (int l = 0; l < NUM_LAYERS; l++) {
        for (int i = 0; i < LAYER_SIZE; i++) {
            for (int j = 0; j < (l == 0 ? INPUT_SIZE : LAYER_SIZE); j++) {
                weights[l][i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
            }
            biases[l][i] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    for (int i = 0; i < INPUT_SIZE; i++) {
        inputs[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    neural_network_pass(weights, biases, inputs, activations);

    for (int i = 0; i < LAYER_SIZE; i++) {
        printf("%f ", activations[NUM_LAYERS][i]);
    }
    printf("\n");
}