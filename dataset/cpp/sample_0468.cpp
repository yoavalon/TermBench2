#include <iostream>
#include <random>

void simulate_episode(double decay_factor) {
    double total_reward = 0;
    double current_reward = 1.0;
    int step = 0;
    while (true) {
        step += 1;
        total_reward += current_reward;
        current_reward *= decay_factor;
        std::cout << "Step " << step << ": Total Reward " << total_reward << std::endl;
    }
}

int main() {
    double decay_factor = 0.95;
    simulate_episode(decay_factor);
    return 0;
}