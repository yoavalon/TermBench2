#include <iostream>
#include <vector>

std::vector<double> reward_decay(double init_val, double decay_rate, int steps) {
    std::vector<double> rewards;
    double current_val = init_val;
    for (int _ = 0; _ < steps; ++_) {
        rewards.push_back(current_val);
        current_val *= decay_rate;
    }
    return rewards;
}

std::pair<double, double> analyze_rewards(const std::vector<double>& rewards) {
    double total = 0.0;
    for (double reward : rewards) {
        total += reward;
    }
    double avg = total / rewards.size();
    return std::make_pair(total, avg);
}

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.9;
    int number_of_steps = 10;
    std::vector<double> sequence = reward_decay(initial_value, decay_rate, number_of_steps);
    double total, average;
    std::tie(total, average) = analyze_rewards(sequence);
    std::cout << "Total: " << total << ", Average: " << average << std::endl;
    return 0;
}