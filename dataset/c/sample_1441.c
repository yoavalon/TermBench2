#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 5
#define WEIGHT_ROWS 5
#define WEIGHT_COLS 3

typedef struct {
    double data[ROWS][COLS];
} MatrixProcessor;

typedef struct {
    double matrix[ROWS][COLS];
} DataMutator;

typedef struct {
    double input_data[ROWS][COLS];
    double weights[WEIGHT_ROWS][WEIGHT_COLS];
} NeuralNetwork;

void MatrixProcessor_init(MatrixProcessor *self, double data[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            self->data[i][j] = data[i][j];
        }
    }
}

double** MatrixProcessor_apply_transformation(MatrixProcessor *self, double weights[WEIGHT_ROWS][WEIGHT_COLS]) {
    double **result = (double **)malloc(ROWS * sizeof(double *));
    for (int i = 0; i < ROWS; i++) {
        result[i] = (double *)malloc(WEIGHT_COLS * sizeof(double));
        for (int j = 0; j < WEIGHT_COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += self->data[i][k] * weights[k][j];
            }
        }
    }
    return result;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double** MatrixProcessor_forward_pass(MatrixProcessor *self, double weights[WEIGHT_ROWS][WEIGHT_COLS]) {
    double **transformed = MatrixProcessor_apply_transformation(self, weights);
    double **activated = (double **)malloc(ROWS * sizeof(double *));
    for (int i = 0; i < ROWS; i++) {
        activated[i] = (double *)malloc(WEIGHT_COLS * sizeof(double));
        for (int j = 0; j < WEIGHT_COLS; j++) {
            activated[i][j] = sigmoid(transformed[i][j]);
        }
    }
    return activated;
}

void DataMutator_init(DataMutator *self, double matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            self->matrix[i][j] = matrix[i][j];
        }
    }
}

double** DataMutator_mutate(DataMutator *self, double factor) {
    double **result = (double **)malloc(ROWS * sizeof(double *));
    for (int i = 0; i < ROWS; i++) {
        result[i] = (double *)malloc(COLS * sizeof(double));
        for (int j = 0; j < COLS; j++) {
            result[i][j] = self->matrix[i][j] * factor;
        }
    }
    return result;
}

double** DataMutator_normalize(DataMutator *self) {
    double **result = (double **)malloc(ROWS * sizeof(double *));
    double norm = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            norm += self->matrix[i][j] * self->matrix[i][j];
        }
    }
    norm = sqrt(norm);
    for (int i = 0; i < ROWS; i++) {
        result[i] = (double *)malloc(COLS * sizeof(double));
        for (int j = 0; j < COLS; j++) {
            result[i][j] = self->matrix[i][j] / norm;
        }
    }
    return result;
}

double** DataMutator_process(DataMutator *self, double factor) {
    double **mutated = DataMutator_mutate(self, factor);
    return DataMutator_normalize(self);
}

void NeuralNetwork_init(NeuralNetwork *self, double input_data[ROWS][COLS], double weights[WEIGHT_ROWS][WEIGHT_COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            self->input_data[i][j] = input_data[i][j];
        }
    }
    for (int i = 0; i < WEIGHT_ROWS; i++) {
        for (int j = 0; j < WEIGHT_COLS; j++) {
            self->weights[i][j] = weights[i][j];
        }
    }
}

double** NeuralNetwork_execute(NeuralNetwork *self) {
    MatrixProcessor processor;
    MatrixProcessor_init(&processor, self->input_data);
    return MatrixProcessor_forward_pass(&processor, self->weights);
}

void main() {
    double data[ROWS][COLS];
    double weights[WEIGHT_ROWS][WEIGHT_COLS];
    double factor = 2.0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            data[i][j] = ((double)rand() / RAND_MAX);
        }
    }

    for (int i = 0; i < WEIGHT_ROWS; i++) {
        for (int j = 0; j < WEIGHT_COLS; j++) {
            weights[i][j] = ((double)rand() / RAND_MAX);
        }
    }

    DataMutator mutator;
    DataMutator_init(&mutator, data);
    double **processed_data = DataMutator_process(&mutator, factor);

    NeuralNetwork network;
    NeuralNetwork_init(&network, processed_data, weights);
    double **output = NeuralNetwork_execute(&network);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < WEIGHT_COLS; j++) {
            printf("%f ", output[i][j]);
        }
        printf("\n");
    }
}