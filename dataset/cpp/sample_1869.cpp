#include <iostream>
#include <vector>

std::vector<double> reward_decay(double initial_reward, double decay_rate, int steps) {
    std::vector<double> rewards;
    double current_reward = initial_reward;
    for (int step = 0; step < steps; ++step) {
        rewards.push_back(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

int main() {
    reward_decay(1.0, 0.95, 10);
    return 0;
}