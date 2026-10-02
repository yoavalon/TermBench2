#include <iostream>
#include <cmath>

double recursive_reward_decay(double alpha, double gamma, int t) {
    return alpha * std::pow(gamma, t) + recursive_reward_decay(alpha, gamma, t + 1);
}

int main() {
    recursive_reward_decay(1, 0.9, 0);
    return 0;
}