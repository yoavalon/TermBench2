#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& data, double factor) {
    std::vector<double> result;
    for (size_t i = 0; i < data.size(); ++i) {
        double value = data[i] * factor;
        result.push_back(round(value * 100000) / 100000);
    }
    return result;
}

void main() {
    std::vector<double> signal = {0.123456, 0.789012, 0.345678};
    double factor = 1.2345;
    std::vector<double> processed = process_signal(signal, factor);
    for (double value : processed) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}