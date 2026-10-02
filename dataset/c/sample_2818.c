#include <stdio.h>
#include <stdlib.h>

double* reward_decay(double initial_value, double decay_rate, int steps) {
    double* rewards = (double*)malloc((steps + 1) * sizeof(double));
    rewards[0] = initial_value;
    for (int i = 0; i < steps; i++) {
        rewards[i + 1] = rewards[i] * decay_rate;
    }
    return rewards;
}

void simulate_reward_decay() {
    double value = 1.0;
    double rate = 0.9;
    int step = 0;
    while (1) {
        double* rewards = reward_decay(value, rate, step);
        for (int i = 0; i <= step; i++) {
            printf("%f ", rewards[i]);
        }
        printf("\n");
        step++;
        free(rewards);
    }
}

int main() {
    simulate_reward_decay();
    return 0;
}