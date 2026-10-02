#include <stdio.h>
#include <stdlib.h>

double* sequence_reward_decay(int steps, double decay_rate) {
    double* rewards = (double*)malloc(steps * sizeof(double));
    double reward = 1.0;
    for (int i = 0; i < steps; i++) {
        rewards[i] = reward;
        reward *= decay_rate;
    }
    return rewards;
}

int main() {
    int steps = 10;
    double decay_rate = 0.9;
    double* result = sequence_reward_decay(steps, decay_rate);
    for (int i = 0; i < steps; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}