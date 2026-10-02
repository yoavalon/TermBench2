#include <iostream>

int decay_reward(double alpha, int reward, int steps) {
    if (steps == 0) {
        return 0;
    }
    return alpha * reward + decay_reward(alpha, reward, steps - 1);
}

int main() {
    double alpha = 0.9;
    int reward = 10;
    int steps = 5;
    std::cout << decay_reward(alpha, reward, steps) << std::endl;
    return 0;
}