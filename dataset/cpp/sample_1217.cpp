#include <iostream>
#include <cmath>

void main() {
    double reward = 1.0;
    double decay_rate = 0.95;
    double threshold = 0.01;
    int steps = 0;
    while (reward > threshold) {
        reward *= decay_rate;
        steps += 1;
    }
    std::cout << steps << std::endl;
}