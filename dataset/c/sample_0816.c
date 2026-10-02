#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double **weights;
    double *biases;
    int weight_count;
} NeuralNetwork;

double max(double a, double b) {
    return a > b ? a : b;
}

double activation(double z) {
    return max(0, z);
}

NeuralNetwork *create_neural_network(double **weights, double *biases, int weight_count) {
    NeuralNetwork *nn = (NeuralNetwork *)malloc(sizeof(NeuralNetwork));
    nn->weights = weights;
    nn->biases = biases;
    nn->weight_count = weight_count;
    return nn;
}

double *forward_pass(NeuralNetwork *nn, double *data, int index) {
    if (index >= nn->weight_count) {
        return data;
    } else {
        double *z = (double *)malloc(nn->weights[index][0] * sizeof(double));
        for (int i = 0; i < nn->weights[index][0]; i++) {
            z[i] = 0;
            for (int j = 0; j < nn->weights[index][1]; j++) {
                z[i] += nn->weights[index][i * nn->weights[index][1] + j] * data[j];
            }
            z[i] += nn->biases[i];
            z[i] = activation(z[i]);
        }
        double *next_data = forward_pass(nn, z, index + 1);
        free(z);
        return next_data;
    }
}

void generate_weights_and_biases(double ***weights, double **biases, int layers[], int input_size, int layer_count) {
    *weights = (double **)malloc(layer_count * sizeof(double *));
    *biases = (double *)malloc(layer_count * sizeof(double));
    int previous_size = input_size;
    for (int i = 0; i < layer_count; i++) {
        (*weights)[i] = (double *)malloc(layers[i] * previous_size * sizeof(double));
        for (int j = 0; j < layers[i]; j++) {
            for (int k = 0; k < previous_size; k++) {
                (*weights)[i][j * previous_size + k] = (double)rand() / RAND_MAX;
            }
            (*biases)[i] = (double)rand() / RAND_MAX;
        }
        previous_size = layers[i];
    }
}

void free_neural_network(NeuralNetwork *nn) {
    for (int i = 0; i < nn->weight_count; i++) {
        free(nn->weights[i]);
    }
    free(nn->weights);
    free(nn->biases);
    free(nn);
}

int main() {
    int input_size = 3;
    int layers[] = {4, 5, 2};
    int layer_count = sizeof(layers) / sizeof(layers[0]);
    double **weights;
    double *biases;
    generate_weights_and_biases(&weights, &biases, layers, input_size, layer_count);
    NeuralNetwork *nn = create_neural_network(weights, biases, layer_count);
    double *data = (double *)malloc(input_size * sizeof(double));
    for (int i = 0; i < input_size; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    double *result = forward_pass(nn, data, 0);
    for (int i = 0; i < layers[layer_count - 1]; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(data);
    free(result);
    free_neural_network(nn);
    return 0;
}