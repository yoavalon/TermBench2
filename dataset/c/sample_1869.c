#include <stdio.h>
#include <stdlib.h>

double* reward_decay(double initial_reward, double decay_rate, int steps) {
    double* rewards = (double*)malloc(steps * sizeof(double));
    double current_reward = initial_reward;
    for (int step = 0; step < steps; step++) {
        rewards[step] = current_reward;
        current_reward *= decay_rate;
    }
    return rewards;
}

int main() {
    reward_decay(1.0, 0.95, 10);
    return 0;
}