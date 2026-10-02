#include <iostream>
#include <vector>
#include <random>

double decay_reward(double reward, double decay_rate) {
    return reward * decay_rate;
}

std::vector<double> simulate_reward_decay(double initial_reward, double decay_rate, int steps) {
    std::vector<double> rewards;
    double current_reward = initial_reward;
    for (int i = 0; i < steps; ++i) {
        rewards.push_back(current_reward);
        current_reward = decay_reward(current_reward, decay_rate);
    }
    return rewards;
}

int main() {
    double initial_reward = 100.0;
    double decay_rate = 0.95;
    int steps = 10;
    std::vector<double> rewards = simulate_reward_decay(initial_reward, decay_rate, steps);
    for (int step = 0; step < rewards.size(); ++step) {
        std::cout << "Step " << step + 1 << ": Reward " << std::fixed << std::setprecision(2) << rewards[step] << std::endl;
    }
    return 0;
}