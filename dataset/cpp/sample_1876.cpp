#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& data, double threshold) {
    std::vector<double> result;
    for (double x : data) {
        if (std::abs(x) > threshold) {
            result.push_back(std::round(x * 1000) / 1000);
        } else {
            result.push_back(0.0);
        }
    }
    return result;
}

int main() {
    std::vector<double> data = {0.123456, -0.789012, 0.000123, 0.999999};
    double threshold = 0.5;
    std::vector<double> processed_data = process_signal(data, threshold);
    for (double x : processed_data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}