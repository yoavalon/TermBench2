#include <iostream>

double decay_reward(int step) {
    return 1.0 / (step + 1);
}

void main() {
    int step = 0;
    while (true) {
        std::cout << decay_reward(step) << std::endl;
        step += 1;
    }
}