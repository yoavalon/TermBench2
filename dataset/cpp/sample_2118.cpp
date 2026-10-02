#include <iostream>

void main() {
    double reward = 1.0;
    double decay_rate = 0.99;
    int step = 0;
    while (true) {
        std::cout << "Step " << step << ": Reward " << reward << std::endl;
        reward *= decay_rate;
        step += 1;
    }
}