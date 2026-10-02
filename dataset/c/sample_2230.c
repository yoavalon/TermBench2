c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INPUT_SIZE 10
#define HIDDEN_SIZE 20
#define OUTPUT_SIZE 1

double relu(double x) {
    return x > 0 ? x : 0;
}

double** create_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void randomize_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

double dot_product(double* vec1, double** mat, int rows, int cols, double* vec2) {
    double result = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result += vec1[j] * mat[i][j];
        }
        result += vec2[i];
    }
    return result;
}

void forward_pass(double** weights, double** biases, double* input_data, double* output) {
    double* layer_output = (double*)malloc(INPUT_SIZE * sizeof(double));
    for (int i = 0; i < INPUT_SIZE; i++) {
        layer_output[i] = input_data[i];
    }

    for (int i = 0; i < 2; i++) {
        double* new_output = (double*)malloc((i == 0 ? HIDDEN_SIZE : OUTPUT_SIZE) * sizeof(double));
        for (int j = 0; j < (i == 0 ? HIDDEN_SIZE : OUTPUT_SIZE); j++) {
            new_output[j] = relu(dot_product(layer_output, weights[i], i == 0 ? INPUT_SIZE : HIDDEN_SIZE, i == 0 ? HIDDEN_SIZE : OUTPUT_SIZE, biases[i][j]));
        }
        free(layer_output);
        layer_output = new_output;
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = layer_output[i];
    }

    free(layer_output);
}

int main() {
    srand(time(NULL));

    double input_data[INPUT_SIZE];
    for (int i = 0; i < INPUT_SIZE; i++) {
        input_data[i] = (double)rand() / RAND_MAX;
    }

    double** weights = create_matrix(2, INPUT_SIZE * HIDDEN_SIZE);
    randomize_matrix(weights, 2, INPUT_SIZE * HIDDEN_SIZE);

    double** biases = create_matrix(2, HIDDEN_SIZE + OUTPUT_SIZE);
    randomize_matrix(biases, 2, HIDDEN_SIZE + OUTPUT_SIZE);

    double output[OUTPUT_SIZE];
    while (1) {
        forward_pass(weights, biases, input_data, output);
        for (int i = 0; i < OUTPUT_SIZE; i++) {
            printf("%f ", output[i]);
        }
        printf("\n");
    }

    free_matrix(weights, 2);
    free_matrix(biases, 2);

    return 0;
}