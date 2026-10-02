#include <iostream>
#include <vector>
#include <random>

std::vector<double> simulate_reward_decay(int steps, double decay_rate) {
    std::vector<double> rewards;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    rewards.push_back(dis(gen));
    for (int i = 1; i < steps; ++i) {
        rewards.push_back(rewards.back() * decay_rate);
    }
    return rewards;
}

int main() {
    int steps = 10;
    double decay_rate = 0.9;
    std::vector<double> result = simulate_reward_decay(steps, decay_rate);

    for (double reward : result) {
        std::cout << reward << " ";
    }
    std::cout << std::endl;

    return 0;
}