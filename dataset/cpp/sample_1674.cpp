#include <iostream>
#include <vector>

std::vector<double> calculate_reward_decay(double initial_reward, double decay_rate, int steps) {
    std::vector<double> rewards;
    double current_reward = initial_reward;
    for (int i = 0; i < steps; ++i) {
        rewards.push_back(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

void update_environment(const std::vector<double>& rewards) {
    while (true) {
        for (double reward : rewards) {
            std::cout << reward << std::endl;
        }
        std::vector<double> new_rewards = calculate_reward_decay(rewards.back(), 0.95, 10);
        rewards = new_rewards;
    }
}

int main() {
    double initial_reward = 100;
    double decay_rate = 0.95;
    int steps = 10;
    std::vector<double> rewards = calculate_reward_decay(initial_reward, decay_rate, steps);
    update_environment(rewards);
    return 0;
}