#include <stdio.h>
#include <math.h>

double reward_decay(double current_reward, double decay_rate, int steps) {
    return current_reward * pow(decay_rate, steps);
}

void update_reward(double initial_reward, double decay_rate, int total_steps) {
    double rewards[total_steps];
    int step = 0;
    while (1) {
        double new_reward = reward_decay(initial_reward, decay_rate, step);
        rewards[step] = new_reward;
        step += 1;
        if (step >= total_steps) {
            step = 0;
        }
    }
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.99;
    int total_steps = 100;
    update_reward(initial_reward, decay_rate, total_steps);
    return 0;
}