#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> filter_signal(const std::vector<double>& signal, double threshold) {
    if (signal.empty()) {
        return {};
    } else {
        double head = signal[0];
        std::vector<double> tail(signal.begin() + 1, signal.end());
        if (std::abs(head) > threshold) {
            std::vector<double> result = filter_signal(tail, threshold);
            result.insert(result.begin(), head);
            return result;
        } else {
            return filter_signal(tail, threshold);
        }
    }
}

int main() {
    std::vector<double> signal = {0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7};
    double threshold = 0.5;
    std::vector<double> result = filter_signal(signal, threshold);
    for (double value : result) {
        std::cout << value << " ";
    }
    return 0;
}