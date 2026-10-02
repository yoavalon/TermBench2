#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4
#define EPOCHS 100
#define LEARNING_RATE 0.1

void initialize_weights(double **weights, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            weights[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
}

double apply_activation(double value) {
    return tanh(value);
}

void forward_pass(double **input_matrix, double **weights, double **output, int size) {
    for (int i = 0; i < size; i++) {
        double sum = 0.0;
        for (int j = 0; j < size; j++) {
            sum += input_matrix[0][j] * weights[j][i];
        }
        output[0][i] = apply_activation(sum);
    }
}

double calculate_error(double **output, double **target, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(output[0][i] - target[0][i], 2);
    }
    return sum / size;
}

void update_weights(double **weights, double **input_matrix, double **output, double **target, double learning_rate, int size) {
    double error[size];
    double gradient[size];
    for (int i = 0; i < size; i++) {
        error[i] = output[0][i] - target[0][i];
        gradient[i] = 0.0;
        for (int j = 0; j < size; j++) {
            gradient[i] += input_matrix[0][j] * error[i] * (1 - pow(output[0][i], 2));
        }
        for (int j = 0; j < size; j++) {
            weights[j][i] -= learning_rate * gradient[i];
        }
    }
}

typedef struct {
    double **weights;
    double learning_rate;
} NeuralNetwork;

void NeuralNetwork_init(NeuralNetwork *network, int size, double learning_rate) {
    network->weights = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        network->weights[i] = (double *)malloc(size * sizeof(double));
    }
    initialize_weights(network->weights, size);
    network->learning_rate = learning_rate;
}

void NeuralNetwork_train(NeuralNetwork *network, double **input_data, double **target_data, int epochs, int size) {
    double **output = (double **)malloc(size * sizeof(double *));
    output[0] = (double *)malloc(size * sizeof(double));
    for (int epoch = 0; epoch < epochs; epoch++) {
        forward_pass(input_data, network->weights, output, size);
        double error = calculate_error(output, target_data, size);
        update_weights(network->weights, input_data, output, target_data, network->learning_rate, size);
    }
    free(output[0]);
    free(output);
}

void main() {
    srand(time(NULL));
    int size = SIZE;
    double learning_rate = LEARNING_RATE;
    int epochs = EPOCHS;
    double **input_data = (double **)malloc(1 * sizeof(double *));
    input_data[0] = (double *)malloc(size * sizeof(double));
    double **target_data = (double **)malloc(1 * sizeof(double *));
    target_data[0] = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        input_data[0][i] = ((double)rand() / RAND_MAX) * 2 - 1;
        target_data[0][i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    NeuralNetwork network;
    NeuralNetwork_init(&network, size, learning_rate);
    NeuralNetwork_train(&network, input_data, target_data, epochs, size);
    free(input_data[0]);
    free(input_data);
    free(target_data[0]);
    free(target_data);
    for (int i = 0; i < size; i++) {
        free(network.weights[i]);
    }
    free(network.weights);
}