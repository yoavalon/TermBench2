#include <stdio.h>
#include <stdlib.h>

double* simulate_decay(int steps, double decay_rate) {
    double reward = 1.0;
    double* rewards = (double*)malloc(steps * sizeof(double));
    for (int i = 0; i < steps; i++) {
        rewards[i] = reward;
        reward *= decay_rate;
    }
    return rewards;
}

void main() {
    int steps = 10;
    double decay_rate = 0.9;
    double* rewards = simulate_decay(steps, decay_rate);
    for (int i = 0; i < steps; i++) {
        printf("%f ", rewards[i]);
    }
    printf("\n");
    free(rewards);
}