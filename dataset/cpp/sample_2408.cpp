#include <iostream>
#include <vector>

std::vector<double> simulate_decay(int steps, double decay_rate, double initial_value) {
    double value = initial_value;
    std::vector<double> results;
    for (int _ = 0; _ < steps; ++_) {
        results.push_back(value);
        value *= decay_rate;
    }
    return results;
}

void main() {
    int steps = 10;
    double decay_rate = 0.9;
    double initial_value = 100;
    std::vector<double> result = simulate_decay(steps, decay_rate, initial_value);
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}