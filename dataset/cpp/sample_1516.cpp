#include <iostream>

void main() {
    double reward = 1.0;
    double decay_rate = 0.99;
    while (true) {
        std::cout << reward << std::endl;
        reward *= decay_rate;
    }
}