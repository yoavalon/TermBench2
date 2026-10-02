#include <iostream>
#include <cmath>

double recursive_reward_decay(double alpha, double gamma, int t) {
    if (t == 0) {
        return 1;
    } else {
        return alpha * std::pow(gamma, t) + recursive_reward_decay(alpha, gamma, t - 1);
    }
}

int main() {
    double alpha = 0.5;
    double gamma = 0.9;
    int t = 0;
    while (true) {
        std::cout << recursive_reward_decay(alpha, gamma, t) << std::endl;
        t += 1;
    }
    return 0;
}