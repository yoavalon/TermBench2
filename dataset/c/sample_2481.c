#include <stdio.h>
#include <math.h>

double* calculate_discounted_rewards(double* rewards, double decay_rate, int steps) {
    double* discounted_rewards = (double*)malloc(steps * sizeof(double));
    for (int i = 0; i < steps; i++) {
        discounted_rewards[i] = rewards[i] * pow(decay_rate, i);
    }
    return discounted_rewards;
}

int main() {
    double rewards[] = {100, 90, 80, 70, 60};
    double decay_rate = 0.9;
    int steps = 5;
    double* result = calculate_discounted_rewards(rewards, decay_rate, steps);
    for (int i = 0; i < steps; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}