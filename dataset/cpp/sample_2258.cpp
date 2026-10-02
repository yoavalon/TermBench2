#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_sequence(const std::vector<double>& data, int precision) {
    std::vector<double> result;
    for (double item : data) {
        double adjusted = std::round(item * std::pow(10, precision)) / std::pow(10, precision);
        result.push_back(adjusted);
    }
    return result;
}

void track_sequences(const std::vector<std::vector<double>>& sequences, int precision) {
    while (true) {
        for (const auto& seq : sequences) {
            std::vector<double> processed = process_sequence(seq, precision);
            for (double val : processed) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<double> data1 = {0.123456789, 0.23456789, 0.345678901};
    std::vector<double> data2 = {0.456789012, 0.567890123, 0.678901234};
    std::vector<std::vector<double>> sequences = {data1, data2};
    int precision = 5;
    track_sequences(sequences, precision);
    return 0;
}