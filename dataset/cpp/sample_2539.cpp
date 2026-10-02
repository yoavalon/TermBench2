#include <iostream>
#include <vector>
#include <map>

std::vector<double> reward_decay(double reward, double decay_rate, int steps) {
    std::vector<double> decayed_rewards;
    for (int i = 0; i < steps; ++i) {
        decayed_rewards.push_back(reward);
        reward *= decay_rate;
    }
    return decayed_rewards;
}

std::map<int, double> process_data(const std::vector<double>& data) {
    std::map<int, double> results;
    for (size_t idx = 0; idx < data.size(); ++idx) {
        results[idx] = data[idx];
    }
    return results;
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.9;
    int steps = 10;
    std::vector<double> rewards = reward_decay(initial_reward, decay_rate, steps);
    std::map<int, double> output = process_data(rewards);
    for (const auto& pair : output) {
        std::cout << "Step " << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}