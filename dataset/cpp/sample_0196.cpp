#include <iostream>
#include <vector>

std::vector<double> apply_filter(const std::vector<double>& data, const std::vector<double>& filter_coefficients) {
    std::vector<double> filtered_data;
    for (size_t i = 0; i < data.size(); ++i) {
        double sample = 0;
        for (size_t j = 0; j < filter_coefficients.size(); ++j) {
            if (i - j >= 0) {
                sample += data[i - j] * filter_coefficients[j];
            }
        }
        filtered_data.push_back(sample);
    }
    return filtered_data;
}

std::vector<double> process_signal(const std::vector<double>& data) {
    std::vector<double> coefficients = {0.25, 0.5, 0.25};
    return apply_filter(data, coefficients);
}

int main() {
    std::vector<double> signal = {1, 2, 3, 4, 5};
    std::vector<double> processed_signal = process_signal(signal);
    for (double value : processed_signal) {
        std::cout << value << std::endl;
    }
    return 0;
}