#include <stdio.h>
#include <stdlib.h>

double decay_reward(double reward, double decay_rate) {
    return reward * decay_rate;
}

double* simulate_reward_decay(double initial_reward, double decay_rate, int steps) {
    double *rewards = (double *)malloc(steps * sizeof(double));
    double current_reward = initial_reward;
    for (int i = 0; i < steps; i++) {
        rewards[i] = current_reward;
        current_reward = decay_reward(current_reward, decay_rate);
    }
    return rewards;
}

void main() {
    double initial_reward = 100.0;
    double decay_rate = 0.95;
    int steps = 10;
    double *rewards = simulate_reward_decay(initial_reward, decay_rate, steps);
    for (int step = 0; step < steps; step++) {
        printf("Step %d: Reward %.2f\n", step + 1, rewards[step]);
    }
    free(rewards);
}