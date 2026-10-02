#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> track_sequence(const std::vector<double>& seq, double precision) {
    std::vector<double> result;
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        double diff = std::abs(seq[i] - seq[i + 1]);
        if (diff < precision) {
            result.push_back(diff);
        }
    }
    return result;
}

std::vector<double> analyze_data(const std::vector<double>& data) {
    double precision = 1e-09;
    std::vector<double> processed_data = track_sequence(data, precision);
    return processed_data;
}

int main() {
    std::vector<double> data = {0.1, 0.2, 0.300000001, 0.4, 0.5};
    std::vector<double> output = analyze_data(data);
    for (double value : output) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}