c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INPUT_SIZE 5
#define HIDDEN_SIZE 10
#define OUTPUT_SIZE 1

double** initialize_weights(int input_size, int hidden_size, int output_size) {
    double** W1 = (double**)malloc(input_size * sizeof(double*));
    double** W2 = (double**)malloc(hidden_size * sizeof(double*));
    for (int i = 0; i < input_size; i++) {
        W1[i] = (double*)malloc(hidden_size * sizeof(double));
        for (int j = 0; j < hidden_size; j++) {
            W1[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    for (int i = 0; i < hidden_size; i++) {
        W2[i] = (double*)malloc(output_size * sizeof(double));
        for (int j = 0; j < output_size; j++) {
            W2[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    double** weights = (double**)malloc(2 * sizeof(double*));
    weights[0] = (double*)W1;
    weights[1] = (double*)W2;
    return weights;
}

double* forward_pass(double** X, double** W1, double** W2, int input_size, int hidden_size, int output_size) {
    double* Z1 = (double*)malloc(hidden_size * sizeof(double));
    double* A1 = (double*)malloc(hidden_size * sizeof(double));
    double* Z2 = (double*)malloc(output_size * sizeof(double));
    double* A2 = (double*)malloc(output_size * sizeof(double));

    for (int j = 0; j < hidden_size; j++) {
        Z1[j] = 0;
        for (int i = 0; i < input_size; i++) {
            Z1[j] += X[i][0] * W1[i][j];
        }
        A1[j] = tanh(Z1[j]);
    }

    for (int j = 0; j < output_size; j++) {
        Z2[j] = 0;
        for (int i = 0; i < hidden_size; i++) {
            Z2[j] += A1[i] * W2[i][j];
        }
        A2[j] = 1 / (1 + exp(-Z2[j]));
    }

    free(Z1);
    free(A1);
    free(Z2);

    return A2;
}

int main() {
    srand(time(NULL));

    double** X = (double**)malloc(10 * sizeof(double*));
    for (int i = 0; i < 10; i++) {
        X[i] = (double*)malloc(1 * sizeof(double));
        X[i][0] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    double** weights = initialize_weights(INPUT_SIZE, HIDDEN_SIZE, OUTPUT_SIZE);
    double** W1 = (double**)weights[0];
    double** W2 = (double**)weights[1];

    double* output = forward_pass(X, W1, W2, INPUT_SIZE, HIDDEN_SIZE, OUTPUT_SIZE);

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("%f\n", output[i]);
    }

    for (int i = 0; i < 10; i++) {
        free(X[i]);
    }
    free(X);

    for (int i = 0; i < INPUT_SIZE; i++) {
        free(W1[i]);
    }
    free(W1);

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        free(W2[i]);
    }
    free(W2);

    free(weights);
    free(output);

    return 0;
}