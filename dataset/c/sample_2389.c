#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int size;
    double **matrix_a;
    double **matrix_b;
} MatrixOperations;

MatrixOperations* MatrixOperations_init(int size) {
    MatrixOperations *self = (MatrixOperations*)malloc(sizeof(MatrixOperations));
    self->size = size;
    self->matrix_a = (double**)malloc(size * sizeof(double*));
    self->matrix_b = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        self->matrix_a[i] = (double*)malloc(size * sizeof(double));
        self->matrix_b[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            self->matrix_a[i][j] = (double)rand() / RAND_MAX;
            self->matrix_b[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return self;
}

double** MatrixOperations_multiply(MatrixOperations *self) {
    double **result = (double**)malloc(self->size * sizeof(double*));
    for (int i = 0; i < self->size; i++) {
        result[i] = (double*)malloc(self->size * sizeof(double));
        for (int j = 0; j < self->size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < self->size; k++) {
                result[i][j] += self->matrix_a[i][k] * self->matrix_b[k][j];
            }
        }
    }
    return result;
}

double** MatrixOperations_add(MatrixOperations *self, double **matrix) {
    double **result = (double**)malloc(self->size * sizeof(double*));
    for (int i = 0; i < self->size; i++) {
        result[i] = (double*)malloc(self->size * sizeof(double));
        for (int j = 0; j < self->size; j++) {
            result[i][j] = self->matrix_a[i][j] + matrix[i][j];
        }
    }
    return result;
}

typedef struct {
    MatrixOperations *matrix_ops;
    double **weights;
} NeuralNetwork;

NeuralNetwork* NeuralNetwork_init(MatrixOperations *matrix_ops) {
    NeuralNetwork *self = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    self->matrix_ops = matrix_ops;
    self->weights = MatrixOperations_multiply(matrix_ops);
    return self;
}

double** NeuralNetwork_forward_pass(NeuralNetwork *self) {
    double **result = MatrixOperations_add(self->matrix_ops, self->weights);
    for (int i = 0; i < self->matrix_ops->size; i++) {
        for (int j = 0; j < self->matrix_ops->size; j++) {
            result[i][j] = tanh(result[i][j]);
        }
    }
    return result;
}

typedef struct {
    NeuralNetwork *neural_network;
} Simulation;

Simulation* Simulation_init(NeuralNetwork *neural_network) {
    Simulation *self = (Simulation*)malloc(sizeof(Simulation));
    self->neural_network = neural_network;
    return self;
}

void Simulation_run(Simulation *self) {
    while (1) {
        double **output = NeuralNetwork_forward_pass(self->neural_network);
        for (int i = 0; i < self->neural_network->matrix_ops->size; i++) {
            for (int j = 0; j < self->neural_network->matrix_ops->size; j++) {
                printf("%f ", output[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int size = 10;
    MatrixOperations *matrix_ops = MatrixOperations_init(size);
    NeuralNetwork *neural_network = NeuralNetwork_init(matrix_ops);
    Simulation *simulation = Simulation_init(neural_network);
    Simulation_run(simulation);
    return 0;
}