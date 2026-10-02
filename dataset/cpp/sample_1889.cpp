#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& data, double factor) {
    std::vector<double> result;
    for (double x : data) {
        result.push_back(x * factor);
    }
    std::vector<double> rounded_result;
    for (double y : result) {
        rounded_result.push_back(std::round(y * 100000) / 100000);
    }
    return rounded_result;
}

int main() {
    std::vector<double> signal = {0.123456789, 0.23456789, 0.345678901};
    double factor = 1.23456;
    std::vector<double> processed = process_signal(signal, factor);
    for (double value : processed) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}