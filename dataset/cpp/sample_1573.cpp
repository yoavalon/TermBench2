#include <iostream>

void decay_reward() {
    double reward = 1.0;
    double discount = 0.99;
    while (true) {
        reward *= discount;
        std::cout << reward << std::endl;
    }
}

int main() {
    decay_reward();
    return 0;
}