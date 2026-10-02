#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE][MAX_SIZE];
    double processed_data[MAX_SIZE][MAX_SIZE];
    int rows, cols;
} MatrixProcessor;

void MatrixProcessor_init(MatrixProcessor *self, double data[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    self->rows = rows;
    self->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            self->data[i][j] = data[i][j];
        }
    }
    self->processed_data = {0};
}

void MatrixProcessor_normalize(MatrixProcessor *self) {
    double sum = 0, mean, std;
    for (int i = 0; i < self->rows; i++) {
        for (int j = 0; j < self->cols; j++) {
            sum += self->data[i][j];
        }
    }
    mean = sum / (self->rows * self->cols);

    sum = 0;
    for (int i = 0; i < self->rows; i++) {
        for (int j = 0; j < self->cols; j++) {
            sum += pow(self->data[i][j] - mean, 2);
        }
    }
    std = sqrt(sum / (self->rows * self->cols));

    for (int i = 0; i < self->rows; i++) {
        for (int j = 0; j < self->cols; j++) {
            self->processed_data[i][j] = (self->data[i][j] - mean) / std;
        }
    }
}

void MatrixProcessor_apply_weight(MatrixProcessor *self, double weights[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    double result[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < self->rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < self->cols; k++) {
                result[i][j] += self->processed_data[i][k] * weights[k][j];
            }
        }
    }
    for (int i = 0; i < self->rows; i++) {
        for (int j = 0; j < cols; j++) {
            self->processed_data[i][j] = result[i][j];
        }
    }
}

void MatrixProcessor_activate(MatrixProcessor *self) {
    for (int i = 0; i < self->rows; i++) {
        for (int j = 0; j < self->cols; j++) {
            self->processed_data[i][j] = self->processed_data[i][j] > 0 ? self->processed_data[i][j] : 0;
        }
    }
}

typedef struct {
    int layers[MAX_SIZE];
    double weights[MAX_SIZE][MAX_SIZE][MAX_SIZE];
    int num_layers;
} NeuralNetwork;

void NeuralNetwork_init(NeuralNetwork *self, int layers[MAX_SIZE], int num_layers) {
    self->num_layers = num_layers;
    for (int i = 0; i < num_layers - 1; i++) {
        for (int j = 0; j < layers[i]; j++) {
            for (int k = 0; k < layers[i + 1]; k++) {
                self->weights[i][j][k] = (double)rand() / RAND_MAX;
            }
        }
    }
}

void NeuralNetwork_forward_pass(NeuralNetwork *self, MatrixProcessor *processor) {
    for (int i = 0; i < self->num_layers - 1; i++) {
        MatrixProcessor_normalize(processor);
        MatrixProcessor_apply_weight(processor, self->weights[i], self->layers[i + 1], self->layers[i]);
        MatrixProcessor_activate(processor);
    }
}

void main() {
    double data[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    int layers[] = {5, 10, 5};
    NeuralNetwork network;
    NeuralNetwork_init(&network, layers, 3);

    MatrixProcessor processor;
    MatrixProcessor_init(&processor, data, 10, 5);
    NeuralNetwork_forward_pass(&network, &processor);

    for (int i = 0; i < processor.rows; i++) {
        for (int j = 0; j < processor.cols; j++) {
            printf("%f ", processor.processed_data[i][j]);
        }
        printf("\n");
    }
}