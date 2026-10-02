#include <iostream>

double decay_reward(double reward, double factor, double threshold) {
    if (reward < threshold) {
        return 0;
    }
    return reward * factor;
}

double compute_reward(double initial, double factor, int steps, double threshold) {
    double reward = initial;
    for (int _ = 0; _ < steps; ++_) {
        reward = decay_reward(reward, factor, threshold);
    }
    return reward;
}

int main() {
    double initial_reward = 100;
    double decay_factor = 0.9;
    int steps = 10;
    double threshold = 10;
    double final_reward = compute_reward(initial_reward, decay_factor, steps, threshold);
    std::cout << final_reward << std::endl;
    return 0;
}