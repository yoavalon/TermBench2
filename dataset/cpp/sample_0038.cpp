#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& data, double threshold) {
    std::vector<double> processed;
    for (double x : data) {
        if (std::abs(x) > threshold) {
            processed.push_back(x);
        } else {
            break;
        }
    }
    return processed;
}

int main() {
    std::vector<double> data = {0.1, 0.5, 1.5, 2.5, 0.3, 0.4};
    double threshold = 1.0;
    std::vector<double> result = process_signal(data, threshold);
    for (double x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}