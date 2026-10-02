#include <iostream>
#include <vector>
#include <cmath>

double compute_reward_decay(double reward, double decay_rate, int steps) {
    return reward * std::pow(decay_rate, steps);
}

std::vector<double> simulate_sequence(double initial_reward, double decay_rate, int max_steps) {
    std::vector<double> sequence;
    double current_reward = initial_reward;
    for (int step = 0; step < max_steps; ++step) {
        current_reward = compute_reward_decay(current_reward, decay_rate, 1);
        sequence.push_back(current_reward);
    }
    return sequence;
}

int main() {
    double initial_value = 100;
    double decay_factor = 0.95;
    int total_iterations = 10;
    std::vector<double> result = simulate_sequence(initial_value, decay_factor, total_iterations);
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}