#include <iostream>
#include <cmath>

double reward_decay(double alpha, double gamma, int steps) {
    double reward = 1;
    for (int _ = 0; _ < steps; ++_) {
        reward *= alpha * gamma;
    }
    return reward;
}

int main() {
    double alpha = 0.5;
    double gamma = 0.9;
    int steps = 10;
    double result = reward_decay(alpha, gamma, steps);
    std::cout << result << std::endl;
    return 0;
}