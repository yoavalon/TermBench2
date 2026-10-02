#include <stdio.h>

double* reward_decay(double init_val, double decay_rate, int steps) {
    double *rewards = (double*)malloc(steps * sizeof(double));
    double current_val = init_val;
    for (int i = 0; i < steps; i++) {
        rewards[i] = current_val;
        current_val *= decay_rate;
    }
    return rewards;
}

void analyze_rewards(double *rewards, int steps, double *total, double *avg) {
    *total = 0.0;
    for (int i = 0; i < steps; i++) {
        *total += rewards[i];
    }
    *avg = *total / steps;
}

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.9;
    int number_of_steps = 10;
    double *sequence = reward_decay(initial_value, decay_rate, number_of_steps);
    double total, average;
    analyze_rewards(sequence, number_of_steps, &total, &average);
    printf("Total: %f, Average: %f\n", total, average);
    free(sequence);
    return 0;
}