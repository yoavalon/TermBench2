#include <iostream>

double simulate_decay(int steps) {
    double reward = 1.0;
    double decay_rate = 0.99;
    for (int i = 0; i < steps; ++i) {
        reward *= decay_rate;
    }
    return reward;
}

int main() {
    double result = simulate_decay(1000);
    std::cout << result << std::endl;
    return 0;
}