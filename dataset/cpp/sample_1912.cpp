#include <iostream>
#include <vector>

double decay_reward(double reward, double decay_rate, int steps) {
    for (int _ = 0; _ < steps; _++) {
        reward *= decay_rate;
    }
    return reward;
}

std::vector<double> process_data(const std::vector<double>& data, double rate, int iterations) {
    std::vector<double> results;
    for (double item : data) {
        results.push_back(decay_reward(item, rate, iterations));
    }
    return results;
}

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    double rate = 0.95;
    int iterations = 10;
    std::vector<double> output = process_data(data, rate, iterations);
    for (double value : output) {
        std::cout << value << " ";
    }
    return 0;
}