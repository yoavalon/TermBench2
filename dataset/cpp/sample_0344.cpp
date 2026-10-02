#include <iostream>
#include <cmath>

void simulate_reward_decay() {
    int state = 0;
    double reward = 1.0;
    double discount = 0.99;
    while (true) {
        state += 1;
        reward *= discount;
        std::cout << "State: " << state << ", Reward: " << reward << std::endl;
    }
}

int main() {
    simulate_reward_decay();
    return 0;
}