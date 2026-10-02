#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void forward_pass(double weights[SIZE][SIZE], double inputs[SIZE], double outputs[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        outputs[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            outputs[i] += weights[i][j] * inputs[j];
        }
    }
}

void update_weights(double weights[SIZE][SIZE], double learning_rate, double error[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            weights[i][j] -= learning_rate * error[i];
        }
    }
}

void simulate_nn(double weights[SIZE][SIZE], double inputs[SIZE], double learning_rate) {
    double outputs[SIZE];
    forward_pass(weights, inputs, outputs);
    double error[SIZE];
    for (int i = 0; i < SIZE; i++) {
        error[i] = outputs[i] - 1.0;
    }
    update_weights(weights, learning_rate, error);
}

int main() {
    srand(time(NULL));
    double weights[SIZE][SIZE];
    double inputs[SIZE];
    double learning_rate = 0.01;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            weights[i][j] = (double)rand() / RAND_MAX;
        }
        inputs[i] = (double)rand() / RAND_MAX;
    }

    while (1) {
        simulate_nn(weights, inputs, learning_rate);
    }

    return 0;
}