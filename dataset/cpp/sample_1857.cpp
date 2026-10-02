#include <iostream>
#include <vector>

std::vector<double> decay_reward(double reward, double decay_rate, int steps) {
    std::vector<double> rewards;
    for (int i = 0; i < steps; ++i) {
        rewards.push_back(reward);
        reward *= decay_rate;
    }
    return rewards;
}

int main() {
    decay_reward(1.0, 0.9, 10);
    return 0;
}