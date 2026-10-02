#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& data, double threshold) {
    std::vector<double> result;
    for (size_t i = 0; i < data.size() - 1; ++i) {
        if (std::abs(data[i] - data[i + 1]) > threshold) {
            result.push_back(data[i]);
        }
    }
    return result;
}

int main() {
    std::vector<double> data = {0.1, 0.2, 0.3, 2.0, 2.1, 2.2};
    double threshold = 1.5;
    std::vector<double> output = process_signal(data, threshold);
    
    for (double value : output) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}