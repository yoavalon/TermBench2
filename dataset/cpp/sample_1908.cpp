#include <iostream>
#include <vector>

std::vector<double> process_signal(const std::vector<double>& data) {
    std::vector<double> processed_data;
    for (double sample : data) {
        double processed_sample = sample * 0.5 + 0.3;
        processed_data.push_back(processed_sample);
    }
    return processed_data;
}

std::vector<double> filter_signal(const std::vector<double>& data, double threshold) {
    std::vector<double> filtered_data;
    for (double sample : data) {
        if (sample > threshold) {
            filtered_data.push_back(sample);
        }
    }
    return filtered_data;
}

int main() {
    std::vector<double> data = {1.2, 2.3, 3.4, 4.5, 5.6};
    std::vector<double> processed = process_signal(data);
    std::vector<double> result = filter_signal(processed, 2.0);
    for (double value : result) {
        std::cout << value << " ";
    }
    return 0;
}