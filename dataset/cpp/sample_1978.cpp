#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& data, double threshold) {
    std::vector<double> filtered(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        filtered[i] = (data[i] > threshold) ? data[i] : 0;
    }
    return filtered;
}

std::vector<double> analyze_data(const std::vector<double>& signal, double precision) {
    std::vector<double> quantized(signal.size());
    for (size_t i = 0; i < signal.size(); ++i) {
        quantized[i] = std::round(signal[i] / precision) * precision;
    }
    return quantized;
}

int main() {
    std::vector<double> data(1000);
    for (auto& d : data) {
        d = std::rand() / (double)RAND_MAX * 2 - 1;
    }
    double threshold = 0.5;
    double precision = 0.01;
    std::vector<double> processed = process_signal(data, threshold);
    std::vector<double> analyzed = analyze_data(processed, precision);
    for (double a : analyzed) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}