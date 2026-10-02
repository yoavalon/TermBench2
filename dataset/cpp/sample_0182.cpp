#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> filter_signal(const std::vector<double>& data, double threshold) {
    std::vector<double> result;
    for (double value : data) {
        if (std::abs(value) > threshold) {
            result.push_back(value);
        } else {
            break;
        }
    }
    return result;
}

std::vector<double> process_data(const std::vector<double>& data, double threshold) {
    std::vector<double> filtered = filter_signal(data, threshold);
    std::vector<double> processed;
    for (double value : filtered) {
        processed.push_back(value * 2);
    }
    return processed;
}

int main() {
    std::vector<double> data = {0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0};
    double threshold = 0.3;
    std::vector<double> output = process_data(data, threshold);
    for (double value : output) {
        std::cout << value << " ";
    }
    return 0;
}