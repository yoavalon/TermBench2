#include <iostream>
#include <vector>
#include <cmath>

double decay_function(double value, double rate, int precision) {
    return std::round(value * (1 - rate) * std::pow(10, precision)) / std::pow(10, precision);
}

std::vector<double> simulate_decay(double initial_value, double decay_rate, int precision, int steps) {
    std::vector<double> values;
    values.push_back(initial_value);
    for (int i = 0; i < steps; ++i) {
        double current_value = values.back();
        double new_value = decay_function(current_value, decay_rate, precision);
        values.push_back(new_value);
    }
    return values;
}

void main() {
    double initial_value = 1.0;
    double decay_rate = 0.1;
    int precision = 4;
    int steps = 10;
    std::vector<double> result = simulate_decay(initial_value, decay_rate, precision, steps);
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}