#include <iostream>
#include <vector>

std::vector<double> reward_decay(int epochs, double decay_rate) {
    std::vector<double> rewards;
    double current_reward = 1.0;
    for (int i = 0; i < epochs; ++i) {
        rewards.push_back(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

int main() {
    std::vector<double> result = reward_decay(10, 0.9);
    for (double reward : result) {
        std::cout << reward << " ";
    }
    std::cout << std::endl;
    return 0;
}