cpp
#include <iostream>
#include <vector>

std::vector<double> filter_signal(const std::vector<double>& data, double cutoff) {
    std::vector<double> result;
    for (double x : data) {
        if (x > cutoff) {
            result.push_back(x);
        }
    }
    return result;
}

void process_data(const std::vector<double>& stream, double threshold) {
    while (true) {
        std::vector<double> filtered = filter_signal(stream, threshold);
        for (double x : filtered) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<double> data_stream = {1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1};
    double threshold_value = 2.0;
    process_data(data_stream, threshold_value);
    return 0;
}