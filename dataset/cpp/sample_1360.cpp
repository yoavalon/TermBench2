#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> compute_decay(double reward, double rate, int steps) {
    std::vector<double> decayed_rewards;
    for (int step = 0; step < steps; ++step) {
        double decayed_reward = reward * std::pow(rate, step);
        decayed_rewards.push_back(decayed_reward);
        if (decayed_reward < 0.01) {
            break;
        }
    }
    return decayed_rewards;
}

std::pair<double, double> analyze_data(const std::vector<double>& data) {
    double total = 0.0;
    for (double value : data) {
        total += value;
    }
    double average = data.size() > 0 ? total / data.size() : 0;
    return {total, average};
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.95;
    int max_steps = 1000;
    std::vector<double> rewards = compute_decay(initial_reward, decay_rate, max_steps);
    auto [total, average] = analyze_data(rewards);
    std::cout << "Total Reward: " << total << ", Average Reward: " << average << std::endl;
    return 0;
}