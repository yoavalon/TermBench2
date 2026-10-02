#include <iostream>
#include <vector>
#include <numeric>
#include <random>

std::vector<double> digital_signal_processing(const std::vector<double>& data, const std::vector<double>& filter_coefficients) {
    std::vector<double> filtered_data(data.size());
    std::convolve(data.begin(), data.end(), filter_coefficients.begin(), filter_coefficients.end(), filtered_data.begin(), std::plus<>(), std::multiplies<>());
    return filtered_data;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> data(1000);
    std::vector<double> coefficients = {0.1, 0.2, 0.3, 0.4, 0.5};

    for (auto& x : data) {
        x = dis(gen);
    }

    while (true) {
        std::vector<double> result = digital_signal_processing(data, coefficients);
        data = result;
    }

    return 0;
}