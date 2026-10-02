#include <iostream>
#include <vector>

double reward_decay(double current, double rate, double threshold) {
    if (current <= threshold) {
        return current;
    }
    return reward_decay(current * rate, rate, threshold);
}

std::vector<double> calculate_discounted_rewards(double initial, double rate, double threshold) {
    std::vector<double> rewards;
    while (initial > threshold) {
        rewards.push_back(initial);
        initial = initial * rate;
    }
    rewards.push_back(initial);
    return rewards;
}

int main() {
    double initial = 100;
    double rate = 0.9;
    double threshold = 10;
    std::vector<double> result = calculate_discounted_rewards(initial, rate, threshold);
    for (double reward : result) {
        std::cout << reward << " ";
    }
    return 0;
}