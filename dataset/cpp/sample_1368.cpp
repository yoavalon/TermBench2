#include <iostream>
#include <vector>

double compute_reward_decay(double initial_reward, double decay_rate, int time_steps) {
    double reward = initial_reward;
    for (int i = 0; i < time_steps; i++) {
        reward *= decay_rate;
    }
    return reward;
}

std::vector<double> simulate_data_mutation(const std::vector<double>& initial_data, double decay_rate, int steps) {
    std::vector<double> mutated_data;
    for (double data_point : initial_data) {
        double reward = compute_reward_decay(data_point, decay_rate, steps);
        mutated_data.push_back(reward);
    }
    return mutated_data;
}

int main() {
    std::vector<double> data = {100, 200, 300, 400, 500};
    double rate = 0.95;
    int steps = 10;
    std::vector<double> result = simulate_data_mutation(data, rate, steps);
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}