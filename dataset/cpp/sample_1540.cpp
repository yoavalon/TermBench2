#include <iostream>

void non_terminating_function() {
    double reward = 1.0;
    double decay_rate = 0.99;
    int step = 0;
    while (true) {
        step += 1;
        reward *= decay_rate;
        std::cout << "Step: " << step << ", Reward: " << reward << std::endl;
    }
}

int main() {
    non_terminating_function();
    return 0;
}