#include <stdio.h>
#include <math.h>

double calculate_reward_decay(double initial_reward, double decay_rate, int step) {
    return initial_reward * pow(decay_rate, step);
}

double simulate_episode(double initial_reward, double decay_rate, int max_steps) {
    double total_reward = 0;
    int step = 0;
    while (step < max_steps) {
        double reward = calculate_reward_decay(initial_reward, decay_rate, step);
        total_reward += reward;
        step += 1;
    }
    return total_reward;
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.9;
    int max_steps = 10;
    double result = simulate_episode(initial_reward, decay_rate, max_steps);
    printf("%f\n", result);
    return 0;
}