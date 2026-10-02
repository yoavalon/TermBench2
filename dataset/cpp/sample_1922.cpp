#include <iostream>
#include <vector>

std::vector<double> simulate_temperature_change(double initial_temp, double rate, int steps) {
    std::vector<double> data(steps);
    for (int i = 0; i < steps; ++i) {
        data[i] = initial_temp + i * rate;
    }
    return data;
}

std::vector<int> analyze_data(const std::vector<double>& data, double threshold) {
    std::vector<int> indices;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] > threshold) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    double initial_temp = 300.0;
    double rate = 0.1;
    int steps = 1000;
    double threshold = 350.0;
    std::vector<double> data = simulate_temperature_change(initial_temp, rate, steps);
    std::vector<int> indices = analyze_data(data, threshold);
    for (int index : indices) {
        std::cout << index << " ";
    }
    return 0;
}