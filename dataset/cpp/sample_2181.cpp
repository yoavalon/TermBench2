#include <iostream>
#include <random>

void simulate_reward_decay() {
    double state = 1.0;
    double gamma = 0.99;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    while (true) {
        double reward = dis(gen) * state;
        state *= gamma;
        std::cout << "Reward: " << reward << ", State: " << state << std::endl;
    }
}

int main() {
    simulate_reward_decay();
    return 0;
}