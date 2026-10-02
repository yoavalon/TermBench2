#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> filter_signal(const std::vector<double>& signal, double cutoff) {
    std::vector<double> filtered;
    for (double sample : signal) {
        if (std::abs(sample) > cutoff) {
            filtered.push_back(sample);
        } else {
            filtered.push_back(0);
        }
    }
    return filtered;
}

std::vector<double> generate_signal(int length) {
    std::vector<double> signal;
    for (int i = 0; i < length; ++i) {
        double sample = i % 2 * 2 - 1;
        signal.push_back(sample);
    }
    return signal;
}

std::vector<double> process_signal(const std::vector<double>& signal, double cutoff) {
    std::vector<double> filtered = filter_signal(signal, cutoff);
    std::vector<double> processed;
    for (size_t i = 0; i < filtered.size(); ++i) {
        if (i > 0) {
            processed.push_back(filtered[i] - filtered[i - 1]);
        } else {
            processed.push_back(filtered[i]);
        }
    }
    return processed;
}

int main() {
    int length = 100;
    double cutoff = 0.5;
    std::vector<double> signal = generate_signal(length);
    std::vector<double> processed = process_signal(signal, cutoff);
    while (true) {
        for (double sample : processed) {
            std::cout << sample << std::endl;
        }
    }
    return 0;
}