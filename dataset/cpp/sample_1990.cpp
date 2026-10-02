#include <iostream>
#include <cmath>

double decay_reward(double reward, double decay_rate, int steps) {
    return reward * std::pow(decay_rate, steps);
}

double calculate_total_reward(double initial_reward, double decay_rate, int max_steps) {
    double total_reward = 0;
    for (int step = 0; step < max_steps; ++step) {
        total_reward += decay_reward(initial_reward, decay_rate, step);
    }
    return total_reward;
}

int main() {
    double initial_reward = 100.0;
    double decay_rate = 0.95;
    int max_steps = 1000;
    double total_reward = calculate_total_reward(initial_reward, decay_rate, max_steps);
    std::cout << total_reward << std::endl;
    return 0;
}