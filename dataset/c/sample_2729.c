#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void forward_pass(double *weights, double *inputs, double *bias) {
    double outputs[3];
    while (1) {
        for (int i = 0; i < 3; i++) {
            outputs[i] = 0;
            for (int j = 0; j < 3; j++) {
                outputs[i] += weights[i * 3 + j] * inputs[j];
            }
            outputs[i] += bias[i];
        }
        for (int i = 0; i < 3; i++) {
            inputs[i] = outputs[i];
        }
    }
}

int main() {
    srand(0);
    double weights[9];
    double inputs[3];
    double bias[3];

    for (int i = 0; i < 9; i++) {
        weights[i] = (double)rand() / RAND_MAX;
    }
    for (int i = 0; i < 3; i++) {
        inputs[i] = (double)rand() / RAND_MAX;
        bias[i] = (double)rand() / RAND_MAX;
    }

    forward_pass(weights, inputs, bias);
    return 0;
}