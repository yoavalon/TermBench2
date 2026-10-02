#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double** weights;
    double* bias;
} Layer;

typedef struct {
    Layer* layers;
    int num_layers;
} Network;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

Layer create_layer(int size) {
    Layer layer;
    layer.weights = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        layer.weights[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            layer.weights[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    layer.bias = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        layer.bias[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    return layer;
}

double* activate(Layer layer, double* inputs, int size) {
    double* output = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        output[i] = 0.0;
        for (int j = 0; j < size; j++) {
            output[i] += layer.weights[i][j] * inputs[j];
        }
        output[i] += layer.bias[i];
        output[i] = sigmoid(output[i]);
    }
    return output;
}

Network create_network(int num_layers, int layer_size) {
    Network network;
    network.layers = (Layer*)malloc(num_layers * sizeof(Layer));
    network.num_layers = num_layers;
    for (int i = 0; i < num_layers; i++) {
        network.layers[i] = create_layer(layer_size);
    }
    return network;
}

double* forward_pass(Network network, double* inputs, int size) {
    double* output = inputs;
    for (int i = 0; i < network.num_layers; i++) {
        output = activate(network.layers[i], output, size);
    }
    return output;
}

int main() {
    int num_layers = 5;
    int layer_size = 10;
    Network network = create_network(num_layers, layer_size);
    double* inputs = (double*)malloc(layer_size * sizeof(double));
    for (int i = 0; i < layer_size; i++) {
        inputs[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    while (1) {
        double* output = forward_pass(network, inputs, layer_size);
        free(inputs);
        inputs = output;
    }
    return 0;
}