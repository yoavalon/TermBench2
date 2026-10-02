#include <iostream>

double decay_function(double value, double rate) {
    return value * (1 - rate);
}

double reward_decay(double initial_value, double rate, int steps) {
    double result = initial_value;
    for (int i = 0; i < steps; ++i) {
        result = decay_function(result, rate);
    }
    return result;
}

void main() {
    double initial_value = 1.0;
    double rate = 0.05;
    int steps = 100;
    double final_value = reward_decay(initial_value, rate, steps);
    std::cout << final_value << std::endl;
}