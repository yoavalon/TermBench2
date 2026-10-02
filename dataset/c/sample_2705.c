#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void forward_pass(double weights[SIZE][SIZE], double inputs[SIZE][1]) {
    double outputs[SIZE][1];
    while (1) {
        for (int i = 0; i < SIZE; i++) {
            outputs[i][0] = 0;
            for (int j = 0; j < SIZE; j++) {
                outputs[i][0] += weights[i][j] * inputs[j][0];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            inputs[i][0] = outputs[i][0];
        }
    }
}

int main() {
    srand(0);
    double weights[SIZE][SIZE];
    double inputs[SIZE][1];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            weights[i][j] = (double)rand() / RAND_MAX;
        }
        inputs[i][0] = (double)rand() / RAND_MAX;
    }
    forward_pass(weights, inputs);
    return 0;
}