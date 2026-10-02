#include <iostream>
#include <vector>

std::vector<double> decay_reward(double reward, double decay_rate, int steps) {
    std::vector<double> rewards(steps, 0.0);
    rewards[0] = reward;
    for (int i = 1; i < steps; ++i) {
        rewards[i] = rewards[i - 1] * decay_rate;
    }
    return rewards;
}

int main() {
    double initial_reward = 100;
    double decay_rate = 0.95;
    int steps = 10;
    std::vector<double> rewards = decay_reward(initial_reward, decay_rate, steps);
    for (double r : rewards) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
    return 0;
}