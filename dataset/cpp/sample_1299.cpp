#include <iostream>

double decay_reward(double initial_value, double decay_rate, int steps) {
    double current_value = initial_value;
    for (int i = 0; i < steps; ++i) {
        current_value *= decay_rate;
    }
    return current_value;
}

int main() {
    decay_reward(100, 0.9, 10);
    return 0;
}