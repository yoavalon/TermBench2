#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BATCH_SIZE 10
#define MAX_LAYERS 4
#define INPUT_SIZE 784
#define OUTPUT_SIZE 10

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

typedef struct {
    double** weights[MAX_LAYERS - 1];
    double** biases[MAX_LAYERS - 1];
    int layer_sizes[MAX_LAYERS];
} NeuralNetwork;

void init_neural_network(NeuralNetwork* nn, int layers[], int num_layers) {
    for (int i = 0; i < num_layers - 1; i++) {
        nn->weights[i] = (double**)malloc(layers[i] * sizeof(double*));
        for (int j = 0; j < layers[i]; j++) {
            nn->weights[i][j] = (double*)malloc(layers[i + 1] * sizeof(double));
            for (int k = 0; k < layers[i + 1]; k++) {
                nn->weights[i][j][k] = (double)rand() / RAND_MAX;
            }
        }
        nn->biases[i] = (double**)malloc(1 * sizeof(double*));
        nn->biases[i][0] = (double*)malloc(layers[i + 1] * sizeof(double));
        for (int j = 0; j < layers[i + 1]; j++) {
            nn->biases[i][0][j] = (double)rand() / RAND_MAX;
        }
    }
}

double** forward_pass(NeuralNetwork* nn, double** input_data, int input_size) {
    double** activations = (double**)malloc(MAX_LAYERS * sizeof(double*));
    activations[0] = input_data;
    for (int i = 0; i < MAX_LAYERS - 1; i++) {
        double** z = (double**)malloc(1 * sizeof(double*));
        z[0] = (double*)malloc(nn->layer_sizes[i + 1] * sizeof(double));
        for (int j = 0; j < nn->layer_sizes[i + 1]; j++) {
            z[0][j] = 0.0;
            for (int k = 0; k < nn->layer_sizes[i]; k++) {
                z[0][j] += activations[i][k] * nn->weights[i][k][j];
            }
            z[0][j] += nn->biases[i][0][j];
        }
        activations[i + 1] = (double**)malloc(1 * sizeof(double*));
        activations[i + 1][0] = (double*)malloc(nn->layer_sizes[i + 1] * sizeof(double));
        for (int j = 0; j < nn->layer_sizes[i + 1]; j++) {
            activations[i + 1][0][j] = sigmoid(z[0][j]);
        }
        free(z[0]);
        free(z);
    }
    return activations[MAX_LAYERS - 1];
}

typedef struct {
    double** data;
    int size;
} DataProcessor;

void init_data_processor(DataProcessor* dp, int size) {
    dp->data = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        dp->data[i] = (double*)malloc(INPUT_SIZE * sizeof(double));
        for (int j = 0; j < INPUT_SIZE; j++) {
            dp->data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    dp->size = size;
}

double** normalize(DataProcessor* dp) {
    double min_val = dp->data[0][0];
    double max_val = dp->data[0][0];
    for (int i = 0; i < dp->size; i++) {
        for (int j = 0; j < INPUT_SIZE; j++) {
            if (dp->data[i][j] < min_val) min_val = dp->data[i][j];
            if (dp->data[i][j] > max_val) max_val = dp->data[i][j];
        }
    }
    double** normalized_data = (double**)malloc(dp->size * sizeof(double*));
    for (int i = 0; i < dp->size; i++) {
        normalized_data[i] = (double*)malloc(INPUT_SIZE * sizeof(double));
        for (int j = 0; j < INPUT_SIZE; j++) {
            normalized_data[i][j] = (dp->data[i][j] - min_val) / (max_val - min_val);
        }
    }
    return normalized_data;
}

double*** prepare_batches(DataProcessor* dp, int batch_size) {
    int num_batches = (dp->size + batch_size - 1) / batch_size;
    double*** batches = (double***)malloc(num_batches * sizeof(double**));
    for (int i = 0; i < num_batches; i++) {
        batches[i] = (double**)malloc(batch_size * sizeof(double*));
        for (int j = 0; j < batch_size; j++) {
            if (i * batch_size + j < dp->size) {
                batches[i][j] = dp->data[i * batch_size + j];
            } else {
                batches[i][j] = NULL;
            }
        }
    }
    return batches;
}

typedef struct {
    NeuralNetwork nn;
    DataProcessor dp;
} Controller;

void process_data(Controller* controller) {
    double** normalized_data = normalize(&controller->dp);
    double*** batches = prepare_batches(&controller->dp, MAX_BATCH_SIZE);
    for (int i = 0; i < (controller->dp.size + MAX_BATCH_SIZE - 1) / MAX_BATCH_SIZE; i++) {
        for (int j = 0; j < MAX_BATCH_SIZE; j++) {
            if (batches[i][j] != NULL) {
                forward_pass(&controller->nn, batches[i][j], INPUT_SIZE);
            }
        }
    }
}

int main() {
    int layers[] = {784, 128, 64, 10};
    NeuralNetwork nn;
    init_neural_network(&nn, layers, 4);
    DataProcessor dp;
    init_data_processor(&dp, 1000);
    Controller controller = {nn, dp};
    while (1) {
        process_data(&controller);
    }
    return 0;
}