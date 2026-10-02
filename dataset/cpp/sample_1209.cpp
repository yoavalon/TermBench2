#include <iostream>
#include <vector>

std::vector<double> simulate_decay_reward(double initial_reward, double decay_rate, int steps) {
    std::vector<double> rewards;
    rewards.push_back(initial_reward);
    for (int i = 0; i < steps; ++i) {
        double current_reward = rewards.back() * (1 - decay_rate);
        rewards.push_back(current_reward);
    }
    return rewards;
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.1;
    int steps = 10;
    std::vector<double> result = simulate_decay_reward(initial_reward, decay_rate, steps);
    for (double reward : result) {
        std::cout << reward << " ";
    }
    std::cout << std::endl;
    return 0;
}