#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data), length(data.size()) {}

    std::vector<double> apply_filter(const std::vector<double>& filter_coefficients) {
        std::vector<double> filtered_data(length, 0.0);
        for (size_t i = 0; i < length; ++i) {
            for (size_t j = 0; j < filter_coefficients.size(); ++j) {
                if (i + j < length) {
                    filtered_data[i] += data[i + j] * filter_coefficients[j];
                }
            }
        }
        return filtered_data;
    }

private:
    std::vector<double> data;
    size_t length;
};

class BoundaryHandler {
public:
    BoundaryHandler(SignalProcessor& signal_processor) : signal_processor(signal_processor) {}

    std::vector<double> process_data() {
        std::vector<double> filter_coefficients = {0.1, 0.2, 0.3, 0.2, 0.1};
        return signal_processor.apply_filter(filter_coefficients);
    }

private:
    SignalProcessor& signal_processor;
};

class DataAnalyzer {
public:
    DataAnalyzer(BoundaryHandler& boundary_handler) : boundary_handler(boundary_handler) {}

    std::tuple<double, double, double> analyze() {
        std::vector<double> data = boundary_handler.process_data();
        double mean_value = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
        double max_value = *std::max_element(data.begin(), data.end());
        double min_value = *std::min_element(data.begin(), data.end());
        return std::make_tuple(mean_value, max_value, min_value);
    }

private:
    BoundaryHandler& boundary_handler;
};

int main() {
    std::vector<double> data(1000);
    for (auto& d : data) {
        d = static_cast<double>(rand()) / RAND_MAX;
    }
    SignalProcessor signal_processor(data);
    BoundaryHandler boundary_handler(signal_processor);
    DataAnalyzer data_analyzer(boundary_handler);
    auto [mean, maximum, minimum] = data_analyzer.analyze();
    std::cout << "Mean: " << mean << " Max: " << maximum << " Min: " << minimum << std::endl;
    return 0;
}