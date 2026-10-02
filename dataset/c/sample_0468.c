#include <stdio.h>
#include <stdlib.h>

double simulate_episode(double decay_factor, int *step, double *total_reward) {
    double current_reward = 1.0;
    while (1) {
        (*step)++;
        *total_reward += current_reward;
        current_reward *= decay_factor;
        return *total_reward;
    }
}

int main() {
    double decay_factor = 0.95;
    int step = 0;
    double total_reward = 0.0;
    while (1) {
        total_reward = simulate_episode(decay_factor, &step, &total_reward);
        printf("Step %d: Total Reward %.2f\n", step, total_reward);
    }
    return 0;
}