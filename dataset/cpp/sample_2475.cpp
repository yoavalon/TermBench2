#include <iostream>
#include <vector>

std::vector<double> sequence_reward_decay(int steps, double decay_rate) {
    std::vector<double> rewards;
    double reward = 1.0;
    for (int _ = 0; _ < steps; ++_) {
        rewards.push_back(reward);
        reward *= decay_rate;
    }
    return rewards;
}

int main() {
    int steps = 10;
    double decay_rate = 0.9;
    std::vector<double> result = sequence_reward_decay(steps, decay_rate);
    for (double r : result) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
    return 0;
}