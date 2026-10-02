#include <stdio.h>

double* simulate_decay_reward(double initial_reward, double decay_rate, int steps) {
    double *rewards = (double *)malloc((steps + 1) * sizeof(double));
    rewards[0] = initial_reward;
    for (int i = 1; i <= steps; i++) {
        rewards[i] = rewards[i - 1] * (1 - decay_rate);
    }
    return rewards;
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.1;
    int steps = 10;
    double *result = simulate_decay_reward(initial_reward, decay_rate, steps);
    for (int i = 0; i <= steps; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}