#include <stdio.h>
#include <math.h>

#define NUM_INPUTS 2
#define NUM_OUTPUTS 2

void forward_pass(double weights[NUM_OUTPUTS][NUM_INPUTS], double biases[NUM_OUTPUTS], double inputs[NUM_INPUTS], double outputs[NUM_OUTPUTS]) {
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        outputs[i] = 0;
        for (int j = 0; j < NUM_INPUTS; j++) {
            outputs[i] += inputs[j] * weights[i][j];
        }
        outputs[i] += biases[i];
        if (outputs[i] < 0) {
            outputs[i] = 0;
        }
    }
}

int main() {
    double weights[NUM_OUTPUTS][NUM_INPUTS] = {{0.2, 0.3}, {0.4, 0.5}};
    double biases[NUM_OUTPUTS] = {0.1, 0.2};
    double inputs[NUM_INPUTS] = {1, 2};
    double outputs[NUM_OUTPUTS];

    forward_pass(weights, biases, inputs, outputs);

    for (int i = 0; i < NUM_OUTPUTS; i++) {
        printf("%f ", outputs[i]);
    }
    printf("\n");

    return 0;
}