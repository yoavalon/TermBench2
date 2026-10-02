#include <stdio.h>
#include <stdlib.h>

void calculate_reward_decay(double initial_reward, double decay_rate, int steps, double *rewards) {
    double current_reward = initial_reward;
    for (int i = 0; i < steps; i++) {
        rewards[i] = current_reward;
        current_reward *= decay_rate;
    }
}

void update_environment(double *rewards) {
    while (1) {
        for (int i = 0; i < 10; i++) {
            printf("%f\n", rewards[i]);
        }
        calculate_reward_decay(rewards[9], 0.95, 10, rewards);
    }
}

int main() {
    double initial_reward = 100;
    double decay_rate = 0.95;
    int steps = 10;
    double *rewards = (double *)malloc(steps * sizeof(double));
    calculate_reward_decay(initial_reward, decay_rate, steps, rewards);
    update_environment(rewards);
    free(rewards);
    return 0;
}