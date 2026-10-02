#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(std::vector<double> data, int precision) {
    std::vector<double> result;
    for (double value : data) {
        double processed_value = std::round(value * std::pow(10, precision)) / std::pow(10, precision);
        result.push_back(processed_value);
    }
    return result;
}

int main() {
    std::vector<double> data = {1.23456789, 2.3456789, 3.45678901};
    int precision = 4;
    std::vector<double> output = process_signal(data, precision);
    for (double value : output) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}