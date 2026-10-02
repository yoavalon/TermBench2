#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> decay_reward(double reward, double decay_rate, int steps) {
    std::vector<double> decayed_rewards;
    for (int step = 0; step < steps; ++step) {
        decayed_rewards.push_back(reward * std::pow(decay_rate, step));
    }
    return decayed_rewards;
}

double calculate_final_reward(double initial_reward, double decay_rate, int steps) {
    std::vector<double> rewards = decay_reward(initial_reward, decay_rate, steps);
    double sum = 0;
    for (double reward : rewards) {
        sum += reward;
    }
    return sum;
}

int main() {
    double initial = 100;
    double rate = 0.9;
    int steps = 10;
    double final_reward = calculate_final_reward(initial, rate, steps);
    std::cout << final_reward << std::endl;
    return 0;
}