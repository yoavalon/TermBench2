#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LAYERS 10

typedef struct {
    double *data;
    int rows, cols;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (double *)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++) {
        mat.data[i] = 0.0;
    }
    return mat;
}

void free_matrix(Matrix mat) {
    free(mat.data);
}

Matrix matrix_multiply(Matrix a, Matrix b) {
    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i * result.cols + j] += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
        }
    }
    return result;
}

Matrix activate(Matrix x) {
    Matrix result = create_matrix(x.rows, x.cols);
    for (int i = 0; i < x.rows * x.cols; i++) {
        result.data[i] = fmax(0.0, x.data[i]);
    }
    return result;
}

Matrix forward_pass(Matrix *weights, Matrix *biases, Matrix input_data, int depth) {
    if (depth == 0) {
        return input_data;
    }
    Matrix layer_output = matrix_multiply(input_data, weights[depth - 1]);
    for (int i = 0; i < layer_output.rows * layer_output.cols; i++) {
        layer_output.data[i] += biases[depth - 1].data[i];
    }
    layer_output = activate(layer_output);
    return forward_pass(weights, biases, layer_output, depth - 1);
}

typedef struct {
    Matrix *weights;
    Matrix *biases;
    int num_layers;
} NeuralNetwork;

NeuralNetwork create_neural_network(int *layers, int input_size) {
    NeuralNetwork network;
    network.num_layers = 0;
    network.weights = (Matrix *)malloc(MAX_LAYERS * sizeof(Matrix));
    network.biases = (Matrix *)malloc(MAX_LAYERS * sizeof(Matrix));
    network.weights[network.num_layers] = create_matrix(input_size, layers[0]);
    network.biases[network.num_layers] = create_matrix(1, layers[0]);
    network.num_layers++;
    for (int i = 1; i < layers[0]; i++) {
        network.biases[network.num_layers - 1].data[i] = (double)rand() / RAND_MAX;
    }
    for (int i = 1; i < layers[0]; i++) {
        for (int j = 0; j < input_size; j++) {
            network.weights[network.num_layers - 1].data[i * input_size + j] = (double)rand() / RAND_MAX;
        }
    }
    for (int i = 1; i < layers[0]; i++) {
        network.biases[network.num_layers - 1].data[i] = (double)rand() / RAND_MAX;
    }
    for (int i = 1; i < layers[0]; i++) {
        for (int j = 0; j < input_size; j++) {
            network.weights[network.num_layers - 1].data[i * input_size + j] = (double)rand() / RAND_MAX;
        }
    }
    return network;
}

Matrix predict(NeuralNetwork network, Matrix input_data, int depth) {
    return forward_pass(network.weights, network.biases, input_data, depth);
}

void main() {
    srand(time(NULL));
    Matrix input_data = create_matrix(1, 10);
    for (int i = 0; i < 10; i++) {
        input_data.data[i] = (double)rand() / RAND_MAX;
    }
    int layers[] = {20, 15, 5};
    NeuralNetwork network = create_neural_network(layers, 10);
    Matrix output = predict(network, input_data, 3);
    for (int i = 0; i < output.rows * output.cols; i++) {
        printf("%f ", output.data[i]);
    }
    printf("\n");
    free_matrix(input_data);
    free_matrix(output);
    for (int i = 0; i < network.num_layers; i++) {
        free_matrix(network.weights[i]);
        free_matrix(network.biases[i]);
    }
    free(network.weights);
    free(network.biases);
}