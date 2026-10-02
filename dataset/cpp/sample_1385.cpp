#include <iostream>
#include <vector>
#include <algorithm>

std::vector<double> simulate_temperature_change(double initial_temp, double rate, int steps) {
    std::vector<double> temperatures;
    temperatures.push_back(initial_temp);
    for (int i = 0; i < steps; ++i) {
        double new_temp = temperatures.back() + rate;
        temperatures.push_back(new_temp);
    }
    return temperatures;
}

std::pair<double, double> analyze_data(const std::vector<double>& data) {
    double max_temp = *std::max_element(data.begin(), data.end());
    double min_temp = *std::min_element(data.begin(), data.end());
    return std::make_pair(max_temp, min_temp);
}

int main() {
    std::vector<double> data = simulate_temperature_change(20, 2, 10);
    std::pair<double, double> result = analyze_data(data);
    std::cout << result.first << " " << result.second << std::endl;
    return 0;
}