#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct {
    double matrix[ROWS][COLS];
} MatrixProcessor;

typedef struct {
    double (*layer)(double);
} Layer;

typedef struct {
    Layer layers[2];
} NeuralNetwork;

void initialize_matrix(double matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

double max_matrix_value(double matrix[ROWS][COLS]) {
    double max_val = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
    }
    return max_val;
}

void normalize_matrix(double matrix[ROWS][COLS]) {
    double max_val = max_matrix_value(matrix);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] /= max_val;
        }
    }
}

double relu(double x) {
    return x > 0 ? x : 0;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double apply_activation(double matrix[ROWS][COLS], double (*activation_func)(double)) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = activation_func(matrix[i][j]);
        }
    }
    return matrix[0][0]; // Just to return something, as the matrix is modified in-place
}

double forward_pass(double matrix[ROWS][COLS], Layer layers[2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                matrix[j][k] = layers[i].layer(matrix[j][k]);
            }
        }
    }
    return matrix[0][0]; // Just to return something, as the matrix is modified in-place
}

int main() {
    srand(0);
    double data[ROWS][COLS];
    initialize_matrix(data);
    normalize_matrix(data);
    Layer layers[2];
    layers[0].layer = relu;
    layers[1].layer = sigmoid;
    apply_activation(data, relu);
    apply_activation(data, sigmoid);
    double result = forward_pass(data, layers);
    printf("%f\n", result);
    return 0;
}