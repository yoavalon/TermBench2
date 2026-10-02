#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *a;
    float *b;
    int rows;
    int cols;
} MatrixOperations;

MatrixOperations* MatrixOperations_init(float *a, float *b, int rows, int cols) {
    MatrixOperations *self = malloc(sizeof(MatrixOperations));
    self->a = a;
    self->b = b;
    self->rows = rows;
    self->cols = cols;
    return self;
}

float** multiply(MatrixOperations *self) {
    float **result = (float**)malloc(self->rows * sizeof(float*));
    for (int i = 0; i < self->rows; i++) {
        result[i] = (float*)malloc(self->cols * sizeof(float));
        for (int j = 0; j < self->cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < self->cols; k++) {
                result[i][j] += self->a[i * self->cols + k] * self->b[k * self->cols + j];
            }
        }
    }
    return result;
}

float** add(MatrixOperations *self) {
    float **result = (float**)malloc(self->rows * sizeof(float*));
    for (int i = 0; i < self->rows; i++) {
        result[i] = (float*)malloc(self->cols * sizeof(float));
        for (int j = 0; j < self->cols; j++) {
            result[i][j] = self->a[i * self->cols + j] + self->b[i * self->cols + j];
        }
    }
    return result;
}

float** subtract(MatrixOperations *self) {
    float **result = (float**)malloc(self->rows * sizeof(float*));
    for (int i = 0; i < self->rows; i++) {
        result[i] = (float*)malloc(self->cols * sizeof(float));
        for (int j = 0; j < self->cols; j++) {
            result[i][j] = self->a[i * self->cols + j] - self->b[i * self->cols + j];
        }
    }
    return result;
}

typedef struct {
    MatrixOperations **layers;
    int num_layers;
} NeuralNetwork;

NeuralNetwork* NeuralNetwork_init(MatrixOperations **layers, int num_layers) {
    NeuralNetwork *self = malloc(sizeof(NeuralNetwork));
    self->layers = layers;
    self->num_layers = num_layers;
    return self;
}

float** forward_pass(NeuralNetwork *self, float **input_data) {
    float **result = input_data;
    for (int i = 0; i < self->num_layers; i++) {
        result = multiply(self->layers[i]);
    }
    return result;
}

int main() {
    float a[] = {1.0, 2.0, 3.0, 4.0};
    float b[] = {2.0, 0.0, 1.0, 2.0};
    float c[] = {0.5, 1.5, 2.5, 3.5};
    MatrixOperations *op1 = MatrixOperations_init(a, b, 2, 2);
    float **result1 = multiply(op1);
    MatrixOperations *op2 = MatrixOperations_init((float*)result1, c, 2, 2);
    MatrixOperations *layers[] = {op1, op2};
    NeuralNetwork *nn = NeuralNetwork_init(layers, 2);
    float input_data[] = {1.0, 1.0, 1.0, 1.0};
    float **output = forward_pass(nn, (float**)input_data);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}