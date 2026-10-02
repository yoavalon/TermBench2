#include <iostream>
#include <vector>

std::vector<double> simulate_decay(int steps, double decay_rate) {
    double reward = 1.0;
    std::vector<double> rewards;
    for (int i = 0; i < steps; ++i) {
        rewards.push_back(reward);
        reward *= decay_rate;
    }
    return rewards;
}

int main() {
    std::vector<double> result = simulate_decay(10, 0.9);
    for (double r : result) {
        std::cout << r << " ";
    }
    return 0;
}