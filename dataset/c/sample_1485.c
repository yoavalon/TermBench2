#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double** a;
    double** b;
    int rows;
    int cols;
} MatrixOperations;

typedef struct {
    double** weights;
    double** biases;
    int rows;
    int cols;
} NeuralNetwork;

MatrixOperations* MatrixOperations_init(double** a, double** b, int rows, int cols) {
    MatrixOperations* self = (MatrixOperations*)malloc(sizeof(MatrixOperations));
    self->a = a;
    self->b = b;
    self->rows = rows;
    self->cols = cols;
    return self;
}

double** multiply(MatrixOperations* self) {
    double** result = (double**)malloc(self->rows * sizeof(double*));
    for (int i = 0; i < self->rows; i++) {
        result[i] = (double*)malloc(self->cols * sizeof(double));
        for (int j = 0; j < self->cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < self->cols; k++) {
                result[i][j] += self->a[i][k] * self->b[k][j];
            }
        }
    }
    return result;
}

double** add(MatrixOperations* self, double** biases) {
    double** result = (double**)malloc(self->rows * sizeof(double*));
    for (int i = 0; i < self->rows; i++) {
        result[i] = (double*)malloc(self->cols * sizeof(double));
        for (int j = 0; j < self->cols; j++) {
            result[i][j] = self->a[i][j] + biases[i][j];
        }
    }
    return result;
}

double** subtract(MatrixOperations* self, double** biases) {
    double** result = (double**)malloc(self->rows * sizeof(double*));
    for (int i = 0; i < self->rows; i++) {
        result[i] = (double*)malloc(self->cols * sizeof(double));
        for (int j = 0; j < self->cols; j++) {
            result[i][j] = self->a[i][j] - biases[i][j];
        }
    }
    return result;
}

NeuralNetwork* NeuralNetwork_init(double** weights, double** biases, int rows, int cols) {
    NeuralNetwork* self = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    self->weights = weights;
    self->biases = biases;
    self->rows = rows;
    self->cols = cols;
    return self;
}

double** forward_pass(NeuralNetwork* self, double** input_data) {
    MatrixOperations* operations = MatrixOperations_init(input_data, self->weights, self->rows, self->cols);
    double** weighted_sum = multiply(operations);
    double** biased_sum = add(operations, self->biases);
    free(operations);
    return biased_sum;
}

double** activation_function(double** x, int rows, int cols) {
    double** result = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        result[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            result[i][j] = x[i][j] > 0 ? x[i][j] : 0;
        }
    }
    return result;
}

void main() {
    double input_data[2][2] = {{1, 2}, {3, 4}};
    double weights[2][2] = {{0.1, 0.2}, {0.3, 0.4}};
    double biases[2] = {0.5, 0.6};
    NeuralNetwork* nn = NeuralNetwork_init((double**)weights, (double**)biases, 2, 2);
    double** output = forward_pass(nn, (double**)input_data);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", output[i][j]);
        }
        printf("\n");
    }
    free(nn);
}