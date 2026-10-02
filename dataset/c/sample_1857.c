#include <stdio.h>
#include <stdlib.h>

void decay_reward(double reward, double decay_rate, int steps) {
    double *rewards = (double *)malloc(steps * sizeof(double));
    for (int i = 0; i < steps; i++) {
        rewards[i] = reward;
        reward *= decay_rate;
    }
    free(rewards);
}

int main() {
    decay_reward(1.0, 0.9, 10);
    return 0;
}