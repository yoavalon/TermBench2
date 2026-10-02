#include <iostream>
#include <vector>

std::vector<double> reward_decay(double initial_value, double decay_rate, int steps) {
    std::vector<double> rewards;
    rewards.push_back(initial_value);
    for (int i = 0; i < steps; ++i) {
        rewards.push_back(rewards.back() * decay_rate);
    }
    return rewards;
}

void simulate_reward_decay() {
    double value = 1.0;
    double rate = 0.9;
    int step = 0;
    while (true) {
        std::vector<double> rewards = reward_decay(value, rate, step);
        for (double reward : rewards) {
            std::cout << reward << " ";
        }
        std::cout << std::endl;
        step += 1;
    }
}

int main() {
    simulate_reward_decay();
    return 0;
}