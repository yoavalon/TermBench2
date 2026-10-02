#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LAYERS 3
#define INPUT_SIZE 5
#define OUTPUT_SIZE 1
#define HIDDEN_SIZE 4

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double** initialize_weights(int rows, int cols) {
    double** weights = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        weights[i] = (double*)malloc(cols * sizeof(double));
    }
    return weights;
}

double** initialize_biases(int rows, int cols) {
    double** biases = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        biases[i] = (double*)malloc(cols * sizeof(double));
    }
    return biases;
}

double** forward_pass(double*** weights, double*** biases, double** inputs, int layers) {
    double** hidden = inputs;
    for (int i = 0; i < layers; i++) {
        double** new_hidden = initialize_weights(weights[i][0], 1);
        for (int j = 0; j < weights[i][0]; j++) {
            double sum = biases[i][j][0];
            for (int k = 0; k < hidden[0]; k++) {
                sum += weights[i][j][k] * hidden[k][0];
            }
            new_hidden[j][0] = sigmoid(sum);
        }
        hidden = new_hidden;
    }
    return hidden;
}

void free_weights(double*** weights, int layers) {
    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < weights[i][0]; j++) {
            free(weights[i][j]);
        }
        free(weights[i]);
    }
    free(weights);
}

void free_biases(double*** biases, int layers) {
    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < biases[i][0]; j++) {
            free(biases[i][j]);
        }
        free(biases[i]);
    }
    free(biases);
}

void free_inputs(double** inputs) {
    for (int i = 0; i < inputs[0]; i++) {
        free(inputs[i]);
    }
    free(inputs);
}

int main() {
    srand(0);
    double*** weights = (double***)malloc(LAYERS * sizeof(double**));
    double*** biases = (double***)malloc(LAYERS * sizeof(double**));
    for (int i = 0; i < LAYERS; i++) {
        if (i == 0) {
            weights[i] = initialize_weights(HIDDEN_SIZE, INPUT_SIZE);
            biases[i] = initialize_weights(HIDDEN_SIZE, 1);
        } else {
            weights[i] = initialize_weights(OUTPUT_SIZE, HIDDEN_SIZE);
            biases[i] = initialize_weights(OUTPUT_SIZE, 1);
        }
        for (int j = 0; j < (i == 0 ? HIDDEN_SIZE : OUTPUT_SIZE); j++) {
            for (int k = 0; k < (i == 0 ? INPUT_SIZE : HIDDEN_SIZE); k++) {
                weights[i][j][k] = ((double)rand() / RAND_MAX) * 2 - 1;
            }
            biases[i][j][0] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    double** inputs = initialize_weights(INPUT_SIZE, 1);
    for (int i = 0; i < INPUT_SIZE; i++) {
        inputs[i][0] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    double** result = forward_pass(weights, biases, inputs, LAYERS);
    printf("%f\n", result[0][0]);
    free_weights(weights, LAYERS);
    free_biases(biases, LAYERS);
    free_inputs(inputs);
    free(result);
    return 0;
}