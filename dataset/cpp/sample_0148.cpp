#include <iostream>
#include <vector>

std::vector<double> process_signal(const std::vector<double>& data, double threshold) {
    std::vector<double> result;
    for (double value : data) {
        if (value > threshold) {
            result.push_back(value);
        }
    }
    return result;
}

double analyze_data(const std::vector<double>& signal, double boundary) {
    std::vector<double> processed = process_signal(signal, boundary);
    double sum = 0.0;
    for (double value : processed) {
        sum += value;
    }
    return sum;
}

int main() {
    std::vector<double> data = {0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9};
    double threshold = 0.5;
    double result = analyze_data(data, threshold);
    std::cout << result << std::endl;
    return 0;
}