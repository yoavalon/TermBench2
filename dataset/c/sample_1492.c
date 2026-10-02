#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 10

typedef struct {
    double **weights;
    double *bias;
} MatrixLayer;

typedef struct {
    MatrixLayer *layers;
    int num_layers;
} NeuralNetwork;

double random_double() {
    return (double)rand() / RAND_MAX;
}

void initialize_matrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = random_double();
        }
    }
}

void initialize_vector(double *vector, int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = random_double();
    }
}

void matrix_multiply(double *result, double *matrix, double *vector, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        result[i] = 0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i * cols + j] * vector[j];
        }
    }
}

double *MatrixLayer_forward(MatrixLayer *layer, double *x) {
    double *result = (double *)malloc(layer->weights[0][0] * sizeof(double));
    matrix_multiply(result, layer->weights[0], x, layer->bias[0], layer->weights[0][0]);
    for (int i = 0; i < layer->bias[0]; i++) {
        result[i] += layer->bias[i];
    }
    return result;
}

NeuralNetwork *NeuralNetwork_init(MatrixLayer *layer1, MatrixLayer *layer2) {
    NeuralNetwork *model = (NeuralNetwork *)malloc(sizeof(NeuralNetwork));
    model->layers = (MatrixLayer *)malloc(2 * sizeof(MatrixLayer));
    model->layers[0] = *layer1;
    model->layers[1] = *layer2;
    model->num_layers = 2;
    return model;
}

double *NeuralNetwork_predict(NeuralNetwork *model, double *x) {
    for (int i = 0; i < model->num_layers; i++) {
        x = MatrixLayer_forward(&model->layers[i], x);
    }
    return x;
}

MatrixLayer *initialize_weights(int input_size, int hidden_size, int output_size) {
    MatrixLayer *layer1 = (MatrixLayer *)malloc(sizeof(MatrixLayer));
    layer1->weights = (double **)malloc(input_size * sizeof(double *));
    for (int i = 0; i < input_size; i++) {
        layer1->weights[i] = (double *)malloc(hidden_size * sizeof(double));
    }
    layer1->bias = (double *)malloc(hidden_size * sizeof(double));
    initialize_matrix(layer1->weights, input_size, hidden_size);
    initialize_vector(layer1->bias, hidden_size);

    MatrixLayer *layer2 = (MatrixLayer *)malloc(sizeof(MatrixLayer));
    layer2->weights = (double **)malloc(hidden_size * sizeof(double *));
    for (int i = 0; i < hidden_size; i++) {
        layer2->weights[i] = (double *)malloc(output_size * sizeof(double));
    }
    layer2->bias = (double *)malloc(output_size * sizeof(double));
    initialize_matrix(layer2->weights, hidden_size, output_size);
    initialize_vector(layer2->bias, output_size);

    return layer1;
}

void main() {
    srand(time(NULL));
    MatrixLayer *layer1, *layer2;
    layer1 = initialize_weights(INPUT_SIZE, HIDDEN_SIZE, OUTPUT_SIZE);
    layer2 = initialize_weights(HIDDEN_SIZE, OUTPUT_SIZE, OUTPUT_SIZE);

    NeuralNetwork *model = NeuralNetwork_init(layer1, layer2);

    double *input_data = (double *)malloc(INPUT_SIZE * sizeof(double));
    initialize_vector(input_data, INPUT_SIZE);

    double *output = NeuralNetwork_predict(model, input_data);

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free(input_data);
    free(output);
    free(layer1->weights);
    free(layer1->bias);
    free(layer2->weights);
    free(layer2->bias);
    free(layer1);
    free(layer2);
    free(model->layers);
    free(model);
}