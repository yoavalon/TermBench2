#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

std::vector<double> process_signal(const std::vector<double>& signal) {
    std::vector<double> filtered_signal(signal.size());
    std::vector<double> kernel = {0.25, 0.5, 0.25};
    for (size_t i = 0; i < signal.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < kernel.size(); ++j) {
            if (i + j < signal.size()) {
                sum += signal[i + j] * kernel[j];
            }
        }
        filtered_signal[i] = sum;
    }
    return filtered_signal;
}

std::vector<bool> analyze_data(const std::vector<double>& data) {
    std::vector<double> processed_data = process_signal(data);
    double mean = std::accumulate(processed_data.begin(), processed_data.end(), 0.0) / processed_data.size();
    double variance = 0.0;
    for (double value : processed_data) {
        variance += (value - mean) * (value - mean);
    }
    double std_dev = std::sqrt(variance / processed_data.size());
    double threshold = mean + 2 * std_dev;
    std::vector<bool> anomalies(processed_data.size());
    for (size_t i = 0; i < processed_data.size(); ++i) {
        anomalies[i] = processed_data[i] > threshold;
    }
    return anomalies;
}

int main() {
    std::vector<double> data(100);
    for (auto& value : data) {
        value = static_cast<double>(rand()) / RAND_MAX;
    }
    std::vector<bool> result = analyze_data(data);
    for (bool anomaly : result) {
        std::cout << anomaly << " ";
    }
    std::cout << std::endl;
    return 0;
}