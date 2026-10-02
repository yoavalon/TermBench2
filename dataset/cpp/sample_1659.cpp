#include <iostream>
#include <vector>

double reward_decay(double current_reward, double decay_rate, int steps) {
    return current_reward * std::pow(decay_rate, steps);
}

void update_reward(double initial_reward, double decay_rate, int total_steps) {
    std::vector<double> rewards;
    int step = 0;
    while (true) {
        double new_reward = reward_decay(initial_reward, decay_rate, step);
        rewards.push_back(new_reward);
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