#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> track_sequence(int precision, int steps) {
    std::vector<double> data = {0.0};
    for (int i = 0; i < steps; ++i) {
        double next_value = data.back() + 1.0 / (i + 1);
        data.push_back(std::round(next_value * std::pow(10, precision)) / std::pow(10, precision));
    }
    return data;
}

int main() {
    std::vector<double> result = track_sequence(5, 100);
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}