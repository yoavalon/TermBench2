#include <iostream>
#include <cstdlib>
#include <ctime>

void simulate_reward_decay() {
    auto decay_reward = [](double reward, double decay_rate) -> double {
        return reward * (1 - decay_rate);
    };

    double reward = 1.0;
    double decay_rate = 0.05;
    while (true) {
        reward = decay_reward(reward, decay_rate);
        std::cout << reward << std::endl;
    }
}

int main() {
    simulate_reward_decay();
    return 0;
}