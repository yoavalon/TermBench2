cpp
#include <iostream>
#include <cmath>

double reward_decay() {
    double x = 1.0;
    double decay_rate = 0.99;
    double epsilon = 1e-06;
    while (x > epsilon) {
        x *= decay_rate;
    }
    return x;
}

int main() {
    double result = reward_decay();
    std::cout << result << std::endl;
    return 0;
}