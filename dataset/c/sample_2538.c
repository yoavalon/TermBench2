#include <stdio.h>
#include <math.h>

double compute_reward_decay(double reward, double decay_rate, int steps) {
    return reward * pow(decay_rate, steps);
}

void simulate_sequence(double initial_reward, double decay_rate, int max_steps, double sequence[]) {
    double current_reward = initial_reward;
    for (int step = 0; step < max_steps; step++) {
        current_reward = compute_reward_decay(current_reward, decay_rate, 1);
        sequence[step] = current_reward;
    }
}

void main() {
    double initial_value = 100;
    double decay_factor = 0.95;
    int total_iterations = 10;
    double result[total_iterations];
    simulate_sequence(initial_value, decay_factor, total_iterations, result);
    for (int i = 0; i < total_iterations; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
}