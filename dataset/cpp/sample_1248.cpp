#include <iostream>
#include <vector>

void main() {
    double gamma = 0.99;
    std::vector<int> rewards = {100, 50, 25, 10, 5};
    double state_value = 0;
    for (int r : rewards) {
        state_value = gamma * state_value + r;
    }
    std::cout << state_value << std::endl;
}