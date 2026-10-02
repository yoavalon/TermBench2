#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double forward_pass(double weights[1][3], double bias, double input_data[3]) {
    double z = weights[0][0] * input_data[0] + weights[0][1] * input_data[1] + weights[0][2] * input_data[2] + bias;
    return sigmoid(z);
}

int main() {
    srand(0);
    double weights[1][3];
    for (int i = 0; i < 3; i++) {
        weights[0][i] = (double)rand() / RAND_MAX;
    }
    double bias = (double)rand() / RAND_MAX;
    double input_data[3] = {1.0, 2.0, 3.0};
    double output = forward_pass(weights, bias, input_data);
    printf("%f\n", output);
    return 0;
}