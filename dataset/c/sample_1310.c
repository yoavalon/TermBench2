#include <stdio.h>

void calculate_reward_decay(double initial_reward, double decay_rate, int time_steps, double rewards[]) {
    rewards[0] = initial_reward;
    for (int t = 1; t < time_steps; t++) {
        rewards[t] = rewards[t - 1] * (1 - decay_rate);
    }
}

int simulate_terminal_condition(double rewards[], int time_steps, double threshold) {
    for (int i = 0; i < time_steps; i++) {
        if (rewards[i] < threshold) {
            return 1;
        }
    }
    return 0;
}

void main() {
    double initial_reward = 1.0;
    double decay_rate = 0.05;
    int time_steps = 20;
    double threshold = 0.01;
    double rewards[time_steps];
    calculate_reward_decay(initial_reward, decay_rate, time_steps, rewards);
    int terminal_condition = simulate_terminal_condition(rewards, time_steps, threshold);
    printf("Terminal Condition Met: %d\n", terminal_condition);
}