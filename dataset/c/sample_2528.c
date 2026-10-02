#include <stdio.h>

void decay_reward(double reward, double decay_rate, int steps, double decayed_rewards[]) {
    for (int step = 0; step < steps; step++) {
        decayed_rewards[step] = reward * pow(decay_rate, step);
    }
}

double calculate_final_reward(double initial_reward, double decay_rate, int steps) {
    double rewards[steps];
    decay_reward(initial_reward, decay_rate, steps, rewards);
    double sum = 0;
    for (int i = 0; i < steps; i++) {
        sum += rewards[i];
    }
    return sum;
}

int main() {
    double initial = 100;
    double rate = 0.9;
    int steps = 10;
    double final_reward = calculate_final_reward(initial, rate, steps);
    printf("%f\n", final_reward);
    return 0;
}