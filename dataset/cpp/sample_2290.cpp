#include <vector>
#include <numeric>

std::vector<double> filter_signal(const std::vector<double>& signal, const std::vector<double>& coefficients) {
    std::vector<double> filtered;
    for (size_t i = 0; i <= signal.size() - coefficients.size(); ++i) {
        double value = 0.0;
        for (size_t j = 0; j < coefficients.size(); ++j) {
            value += signal[i + j] * coefficients[j];
        }
        filtered.push_back(value);
    }
    return filtered;
}

void process_data(std::vector<double>& data, const std::vector<double>& filter_coefficients) {
    std::vector<double> processed;
    while (true) {
        std::vector<double> filtered = filter_signal(data, filter_coefficients);
        processed.insert(processed.end(), filtered.begin(), filtered.end());
        if (data.size() > 1) {
            data.erase(data.begin());
        }
    }
}

int main() {
    std::vector<double> initial_data = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::vector<double> coefficients = {0.5, 0.3, 0.2};
    process_data(initial_data, coefficients);
    return 0;
}