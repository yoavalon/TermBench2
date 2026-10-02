#include <iostream>
#include <cmath>

double update_reward(double reward, double decay_rate, int steps) {
    return reward * std::pow(decay_rate, steps);
}

void process_data() {
    double reward = 1.0;
    double decay_rate = 0.9;
    int steps = 10;
    for (int _ = 0; _ < steps; _++) {
        reward = update_reward(reward, decay_rate, 1);
    }
    std::cout << reward << std::endl;
}

int main() {
    process_data();
    return 0;
}