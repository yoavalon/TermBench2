#include <iostream>
#include <cmath>

void main() {
    double reward_decay(int step) {
        return pow(0.99, step);
    }
    int step = 0;
    while (true) {
        std::cout << "Step " << step << ": Reward " << reward_decay(step) << std::endl;
        step += 1;
    }
}