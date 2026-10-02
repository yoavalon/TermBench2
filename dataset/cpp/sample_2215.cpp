#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& data, double precision) {
    std::vector<double> result;
    for (double x : data) {
        double processed_value = std::round(x / precision * 100000) / 100000;
        result.push_back(processed_value);
    }
    return result;
}

void analyze_data(const std::vector<double>& data) {
    double precision = 1e-05;
    while (true) {
        std::vector<double> processed = process_signal(data, precision);
        for (double value : processed) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    analyze_data(data);
    return 0;
}