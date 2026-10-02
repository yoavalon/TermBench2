#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INPUT_SIZE 10
#define LAYER_SIZE 10
#define NUM_LAYERS 2

double relu(double x) {
    return fmax(0, x);
}

void forward_pass(double weights[NUM_LAYERS][LAYER_SIZE][LAYER_SIZE], double biases[NUM_LAYERS][LAYER_SIZE], double inputs[LAYER_SIZE], double outputs[LAYER_SIZE]) {
    for (int i = 0; i < NUM_LAYERS; i++) {
        for (int j = 0; j < LAYER_SIZE; j++) {
            double sum = biases[i][j];
            for (int k = 0; k < LAYER_SIZE; k++) {
                sum += weights[i][j][k] * inputs[k];
            }
            inputs[j] = relu(sum);
        }
    }
    for (int i = 0; i < LAYER_SIZE; i++) {
        outputs[i] = inputs[i];
    }
}

void main() {
    srand(time(NULL));
    double weights[NUM_LAYERS][LAYER_SIZE][LAYER_SIZE];
    double biases[NUM_LAYERS][LAYER_SIZE];
    double inputs[LAYER_SIZE];
    double outputs[LAYER_SIZE];

    for (int i = 0; i < NUM_LAYERS; i++) {
        for (int j = 0; j < LAYER_SIZE; j++) {
            biases[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
            for (int k = 0; k < LAYER_SIZE; k++) {
                weights[i][j][k] = ((double)rand() / RAND_MAX) * 2 - 1;
            }
        }
    }

    for (int i = 0; i < LAYER_SIZE; i++) {
        inputs[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    while (1) {
        forward_pass(weights, biases, inputs, outputs);
    }
}