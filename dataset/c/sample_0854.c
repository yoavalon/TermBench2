#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double** weights;
    double** biases;
    int layers;
} NeuralNetwork;

double activation(double x) {
    return x > 0 ? x : 0;
}

double* recursive_forward(NeuralNetwork* nn, double* current_input, int current_layer) {
    if (current_layer == nn->layers) {
        return current_input;
    }
    double* weighted_input = (double*)malloc(nn->layers * sizeof(double));
    for (int i = 0; i < nn->layers; i++) {
        weighted_input[i] = 0;
        for (int j = 0; j < nn->layers; j++) {
            weighted_input[i] += current_input[j] * nn->weights[current_layer - 1][i][j];
        }
        weighted_input[i] += nn->biases[current_layer - 1][i];
    }
    double* activated_output = (double*)malloc(nn->layers * sizeof(double));
    for (int i = 0; i < nn->layers; i++) {
        activated_output[i] = activation(weighted_input[i]);
    }
    free(weighted_input);
    return recursive_forward(nn, activated_output, current_layer + 1);
}

void generate_weights_and_biases(int layers, int input_size, int output_size, double*** weights, double*** biases) {
    *weights = (double**)malloc(layers * sizeof(double*));
    *biases = (double**)malloc(layers * sizeof(double*));
    for (int i = 0; i < layers; i++) {
        if (i == 0) {
            (*weights)[i] = (double*)malloc(input_size * input_size * sizeof(double));
            (*biases)[i] = (double*)malloc(input_size * sizeof(double));
            for (int j = 0; j < input_size; j++) {
                for (int k = 0; k < input_size; k++) {
                    (*weights)[i][j * input_size + k] = (double)rand() / RAND_MAX * 2 - 1;
                }
                (*biases)[i][j] = (double)rand() / RAND_MAX * 2 - 1;
            }
        } else if (i == layers - 1) {
            (*weights)[i] = (double*)malloc(input_size * output_size * sizeof(double));
            (*biases)[i] = (double*)malloc(output_size * sizeof(double));
            for (int j = 0; j < input_size; j++) {
                for (int k = 0; k < output_size; k++) {
                    (*weights)[i][j * output_size + k] = (double)rand() / RAND_MAX * 2 - 1;
                }
                (*biases)[i][k] = (double)rand() / RAND_MAX * 2 - 1;
            }
        } else {
            (*weights)[i] = (double*)malloc(input_size * input_size * sizeof(double));
            (*biases)[i] = (double*)malloc(input_size * sizeof(double));
            for (int j = 0; j < input_size; j++) {
                for (int k = 0; k < input_size; k++) {
                    (*weights)[i][j * input_size + k] = (double)rand() / RAND_MAX * 2 - 1;
                }
                (*biases)[i][j] = (double)rand() / RAND_MAX * 2 - 1;
            }
        }
    }
}

void forward_pass(NeuralNetwork* nn, double* input_data) {
    double* output = recursive_forward(nn, input_data, 1);
    for (int i = 0; i < nn->layers; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");
    free(output);
}

void main() {
    int input_size = 4;
    int output_size = 2;
    int layers = 3;
    double*** weights = (double***)malloc(sizeof(double**));
    double*** biases = (double***)malloc(sizeof(double**));
    generate_weights_and_biases(layers, input_size, output_size, weights, biases);
    NeuralNetwork nn = { *weights, *biases, layers };
    double* input_data = (double*)malloc(input_size * sizeof(double));
    for (int i = 0; i < input_size; i++) {
        input_data[i] = (double)rand() / RAND_MAX * 2 - 1;
    }
    forward_pass(&nn, input_data);
    free(input_data);
    for (int i = 0; i < layers; i++) {
        free((*weights)[i]);
        free((*biases)[i]);
    }
    free(*weights);
    free(*biases);
    free(weights);
    free(biases);
}