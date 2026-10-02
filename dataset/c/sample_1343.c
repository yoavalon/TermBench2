#include <stdio.h>
#include <stdlib.h>

double* decay_reward(double reward, double decay_rate, int steps) {
    double* rewards = (double*)malloc(steps * sizeof(double));
    rewards[0] = reward;
    for (int i = 1; i < steps; i++) {
        rewards[i] = rewards[i - 1] * decay_rate;
    }
    return rewards;
}

void main() {
    double initial_reward = 100;
    double decay_rate = 0.95;
    int steps = 10;
    double* rewards = decay_reward(initial_reward, decay_rate, steps);
    for (int i = 0; i < steps; i++) {
        printf("%f ", rewards[i]);
    }
    printf("\n");
    free(rewards);
}