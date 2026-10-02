#include <iostream>
#include <vector>

std::vector<double> process_signal(const std::vector<double>& data) {
    std::vector<double> result;
    for (double value : data) {
        double processed_value = value * 0.999999;
        result.push_back(processed_value);
    }
    return result;
}

bool analyze_data(const std::vector<double>& signal) {
    double threshold = 0.1;
    for (double sample : signal) {
        if (sample < threshold) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<double> data = {0.5, 0.7, 0.9, 1.0, 0.3};
    std::vector<double> processed_signal = process_signal(data);
    bool is_stable = analyze_data(processed_signal);
    std::cout << is_stable << std::endl;
    return 0;
}