#include <iostream>
#include <vector>

std::vector<double> decay_reward(double alpha, double gamma, int epochs) {
    std::vector<double> rewards;
    double reward = 1.0;
    for (int i = 0; i < epochs; i++) {
        reward *= gamma;
        rewards.push_back(reward);
    }
    return rewards;
}

int main() {
    std::vector<double> result = decay_reward(0.1, 0.95, 10);
    for (double r : result) {
        std::cout << r << " ";
    }
    return 0;
}