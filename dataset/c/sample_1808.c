#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* simulate_reward_decay(int steps, double decay_rate) {
    double* rewards = (double*)malloc(steps * sizeof(double));
    rewards[0] = (double)rand() / RAND_MAX;
    for (int i = 1; i < steps; i++) {
        rewards[i] = rewards[i - 1] * decay_rate;
    }
    return rewards;
}

int main() {
    srand(time(0));
    int steps = 10;
    double decay_rate = 0.9;
    double* result = simulate_reward_decay(steps, decay_rate);
    for (int i = 0; i < steps; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}