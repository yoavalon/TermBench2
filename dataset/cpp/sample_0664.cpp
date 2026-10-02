#include <iostream>

double reward_decay(double reward, double discount, double threshold) {
    if (reward < threshold) {
        return reward;
    } else {
        return reward_decay(reward * discount, discount, threshold);
    }
}

int main() {
    double result = reward_decay(100, 0.9, 10);
    std::cout << result << std::endl;
    return 0;
}