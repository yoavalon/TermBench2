#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 10
#define LAYERS 5

void matrix_multiply(double a[MATRIX_SIZE][MATRIX_SIZE], double b[MATRIX_SIZE][1], double result[MATRIX_SIZE][1]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        result[i][0] = 0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i][0] += a[i][j] * b[j][0];
        }
    }
}

void forward_pass(double weights[LAYERS][MATRIX_SIZE][MATRIX_SIZE], double inputs[MATRIX_SIZE][1], int layers, double output[MATRIX_SIZE][1]) {
    for (int i = 0; i < layers; i++) {
        matrix_multiply(weights[i], inputs, output);
        for (int j = 0; j < MATRIX_SIZE; j++) {
            inputs[j][0] = output[j][0];
        }
    }
}

int main() {
    srand(time(NULL));
    double weights[LAYERS][MATRIX_SIZE][MATRIX_SIZE];
    double inputs[MATRIX_SIZE][1];
    double output[MATRIX_SIZE][1];

    for (int i = 0; i < LAYERS; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            for (int k = 0; k < MATRIX_SIZE; k++) {
                weights[i][j][k] = (double)rand() / RAND_MAX;
            }
        }
    }

    for (int i = 0; i < MATRIX_SIZE; i++) {
        inputs[i][0] = (double)rand() / RAND_MAX;
    }

    forward_pass(weights, inputs, LAYERS, output);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        printf("%f\n", output[i][0]);
    }

    return 0;
}