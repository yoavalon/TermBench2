#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 4
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 4

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void forward_pass(double weights[HIDDEN_SIZE][INPUT_SIZE], double bias[HIDDEN_SIZE], double input_data[INPUT_SIZE][HIDDEN_SIZE], double output[OUTPUT_SIZE]) {
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double sum = bias[i];
        for (int j = 0; j < INPUT_SIZE; j++) {
            sum += input_data[j][i] * weights[i][j];
        }
        output[i] = sigmoid(sum);
    }
}

int main() {
    srand(0);
    double weights[HIDDEN_SIZE][INPUT_SIZE];
    double bias[HIDDEN_SIZE];
    double input_data[INPUT_SIZE][HIDDEN_SIZE];
    double result[OUTPUT_SIZE];

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        bias[i] = ((double)rand() / (double)RAND_MAX);
        for (int j = 0; j < INPUT_SIZE; j++) {
            weights[i][j] = ((double)rand() / (double)RAND_MAX);
            input_data[j][i] = ((double)rand() / (double)RAND_MAX);
        }
    }

    forward_pass(weights, bias, input_data, result);

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}