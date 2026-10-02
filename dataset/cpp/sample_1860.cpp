#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_sequence(std::vector<double> data, int precision) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] = std::round(data[i] * std::pow(10, precision)) / std::pow(10, precision);
    }
    return data;
}

void main() {
    std::vector<double> sequence = {1.123456789, 2.987654321, 3.456789123};
    std::vector<double> result = process_sequence(sequence, 5);
    for (double num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}