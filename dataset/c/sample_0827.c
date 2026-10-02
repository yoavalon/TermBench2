#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double (*sigmoid)(double);
    double (*relu)(double);
} Activation;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double relu(double x) {
    return x > 0 ? x : 0;
}

typedef struct {
    double** weights;
    double* bias;
    double (*activation)(double);
} Layer;

Layer* create_layer(int input_size, int output_size, Activation* activation, const char* activation_type) {
    Layer* layer = (Layer*)malloc(sizeof(Layer));
    layer->weights = (double**)malloc(input_size * sizeof(double*));
    for (int i = 0; i < input_size; i++) {
        layer->weights[i] = (double*)malloc(output_size * sizeof(double));
        for (int j = 0; j < output_size; j++) {
            layer->weights[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    layer->bias = (double*)malloc(output_size * sizeof(double));
    for (int i = 0; i < output_size; i++) {
        layer->bias[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    if (strcmp(activation_type, "sigmoid") == 0) {
        layer->activation = activation->sigmoid;
    } else if (strcmp(activation_type, "relu") == 0) {
        layer->activation = activation->relu;
    }
    return layer;
}

double* forward(Layer* layer, double* input_data, int input_size) {
    double* z = (double*)malloc(layer->bias[0] * sizeof(double));
    for (int i = 0; i < input_size; i++) {
        for (int j = 0; j < layer->bias[0]; j++) {
            z[j] += input_data[i] * layer->weights[i][j];
        }
    }
    for (int i = 0; i < layer->bias[0]; i++) {
        z[i] += layer->bias[i];
        z[i] = layer->activation(z[i]);
    }
    return z;
}

typedef struct {
    Layer** layers;
    int layer_count;
} NeuralNetwork;

NeuralNetwork* create_network(int* layer_sizes, int layer_count, Activation* activation, const char* activation_type) {
    NeuralNetwork* network = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    network->layers = (Layer**)malloc((layer_count - 1) * sizeof(Layer*));
    network->layer_count = layer_count - 1;
    for (int i = 0; i < layer_count - 1; i++) {
        network->layers[i] = create_layer(layer_sizes[i], layer_sizes[i + 1], activation, activation_type);
    }
    return network;
}

double* predict(NeuralNetwork* network, double* input_data, int input_size) {
    for (int i = 0; i < network->layer_count; i++) {
        input_data = forward(network->layers[i], input_data, input_size);
        input_size = network->layers[i]->bias[0];
    }
    return input_data;
}

void free_layer(Layer* layer) {
    for (int i = 0; i < layer->weights[0]; i++) {
        free(layer->weights[i]);
    }
    free(layer->weights);
    free(layer->bias);
    free(layer);
}

void free_network(NeuralNetwork* network) {
    for (int i = 0; i < network->layer_count; i++) {
        free_layer(network->layers[i]);
    }
    free(network->layers);
    free(network);
}

int main() {
    double input_data[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    double expected_output[4][1] = {{0}, {1}, {1}, {0}};
    Activation activation = {sigmoid, relu};
    int layer_sizes[3] = {2, 4, 1};
    NeuralNetwork* network = create_network(layer_sizes, 3, &activation, "sigmoid");
    for (int i = 0; i < 4; i++) {
        double* output = predict(network, input_data[i], 2);
        printf("%f\n", output[0]);
        free(output);
    }
    free_network(network);
    return 0;
}