#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define RAND_MAX 32767

typedef struct {
    int** weights;
    int** biases;
    int* layers;
    int num_layers;
} Network;

typedef struct {
    double** data;
    int size;
    int features;
} DataGenerator;

typedef struct {
    Network* network;
    DataGenerator* data_generator;
} Trainer;

double random_double() {
    return (double)rand() / RAND_MAX;
}

double tanh_double(double x) {
    return (exp(2 * x) - 1) / (exp(2 * x) + 1);
}

Network* Network_init(int* layers, int num_layers) {
    Network* network = (Network*)malloc(sizeof(Network));
    network->layers = layers;
    network->num_layers = num_layers;
    network->weights = (int**)malloc((num_layers - 1) * sizeof(int*));
    network->biases = (int**)malloc((num_layers - 1) * sizeof(int*));

    for (int i = 0; i < num_layers - 1; i++) {
        network->weights[i] = (int*)malloc(layers[i] * layers[i + 1] * sizeof(int));
        network->biases[i] = (int*)malloc(layers[i + 1] * sizeof(int));
        for (int j = 0; j < layers[i] * layers[i + 1]; j++) {
            network->weights[i][j] = (int)(random_double() * RAND_MAX);
        }
        for (int j = 0; j < layers[i + 1]; j++) {
            network->biases[i][j] = (int)(random_double() * RAND_MAX);
        }
    }
    return network;
}

double* Network_forward(Network* network, double* input_data) {
    double* activations = (double*)malloc(network->layers[network->num_layers - 1] * sizeof(double));
    double* temp_activations = (double*)malloc(network->layers[network->num_layers - 1] * sizeof(double));

    for (int i = 0; i < network->num_layers - 1; i++) {
        for (int j = 0; j < network->layers[i + 1]; j++) {
            double activation = 0;
            for (int k = 0; k < network->layers[i]; k++) {
                activation += input_data[k] * network->weights[i][j * network->layers[i] + k];
            }
            activation += network->biases[i][j];
            temp_activations[j] = tanh_double(activation);
        }
        input_data = temp_activations;
    }

    for (int i = 0; i < network->layers[network->num_layers - 1]; i++) {
        activations[i] = input_data[i];
    }

    free(temp_activations);
    return activations;
}

DataGenerator* DataGenerator_init(int size, int features) {
    DataGenerator* data_generator = (DataGenerator*)malloc(sizeof(DataGenerator));
    data_generator->size = size;
    data_generator->features = features;
    data_generator->data = (double**)malloc(size * sizeof(double*));

    for (int i = 0; i < size; i++) {
        data_generator->data[i] = (double*)malloc(features * sizeof(double));
        for (int j = 0; j < features; j++) {
            data_generator->data[i][j] = random_double();
        }
    }
    return data_generator;
}

double** DataGenerator_generate(DataGenerator* data_generator) {
    return data_generator->data;
}

Trainer* Trainer_init(Network* network, DataGenerator* data_generator) {
    Trainer* trainer = (Trainer*)malloc(sizeof(Trainer));
    trainer->network = network;
    trainer->data_generator = data_generator;
    return trainer;
}

void Trainer_train(Trainer* trainer) {
    while (1) {
        double** data = DataGenerator_generate(trainer->data_generator);
        for (int i = 0; i < trainer->data_generator->size; i++) {
            double* activations = Network_forward(trainer->network, data[i]);
            free(activations);
        }
    }
}

void main() {
    int layers[] = {784, 128, 64, 10};
    Network* network = Network_init(layers, 4);
    DataGenerator* data_generator = DataGenerator_init(1000, 784);
    Trainer* trainer = Trainer_init(network, data_generator);
    Trainer_train(trainer);
}