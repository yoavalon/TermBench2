#include <iostream>
#include <vector>

std::vector<double> calculate_reward_decay(double initial_reward, double decay_rate, int time_steps) {
    std::vector<double> rewards(time_steps);
    rewards[0] = initial_reward;
    for (int t = 1; t < time_steps; ++t) {
        rewards[t] = rewards[t - 1] * (1 - decay_rate);
    }
    return rewards;
}

bool simulate_terminal_condition(const std::vector<double>& rewards, double threshold) {
    for (double reward : rewards) {
        if (reward < threshold) {
            return true;
        }
    }
    return false;
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.05;
    int time_steps = 20;
    double threshold = 0.01;
    std::vector<double> rewards = calculate_reward_decay(initial_reward, decay_rate, time_steps);
    bool terminal_condition = simulate_terminal_condition(rewards, threshold);
    std::cout << "Terminal Condition Met: " << (terminal_condition ? "true" : "false") << std::endl;
    return 0;
}