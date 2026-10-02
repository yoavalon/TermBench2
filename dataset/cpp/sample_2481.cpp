#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> calculate_discounted_rewards(const std::vector<int>& rewards, double decay_rate, int steps) {
    std::vector<double> discounted_rewards;
    for (int i = 0; i < steps; ++i) {
        discounted_rewards.push_back(rewards[i] * std::pow(decay_rate, i));
    }
    return discounted_rewards;
}

int main() {
    std::vector<int> rewards = {100, 90, 80, 70, 60};
    double decay_rate = 0.9;
    int steps = 5;
    std::vector<double> result = calculate_discounted_rewards(rewards, decay_rate, steps);
    for (double reward : result) {
        std::cout << reward << " ";
    }
    return 0;
}