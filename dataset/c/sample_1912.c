#include <stdio.h>
#include <stdlib.h>

double decay_reward(double reward, double decay_rate, int steps) {
    for (int _ = 0; _ < steps; _++) {
        reward *= decay_rate;
    }
    return reward;
}

double* process_data(double* data, int data_size, double rate, int iterations) {
    double* results = (double*)malloc(data_size * sizeof(double));
    for (int i = 0; i < data_size; i++) {
        results[i] = decay_reward(data[i], rate, iterations);
    }
    return results;
}

int main() {
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int data_size = sizeof(data) / sizeof(data[0]);
    double rate = 0.95;
    int iterations = 10;
    double* output = process_data(data, data_size, rate, iterations);
    for (int i = 0; i < data_size; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");
    free(output);
    return 0;
}