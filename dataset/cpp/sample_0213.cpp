#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data) {}

    std::vector<double> apply_filter(const std::vector<double>& kernel) {
        std::vector<double> filtered_data(data.size(), 0.0);
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < kernel.size(); ++j) {
                if (i + j < data.size()) {
                    filtered_data[i] += data[i + j] * kernel[j];
                }
            }
        }
        return filtered_data;
    }

    std::vector<double> normalize(const std::vector<double>& data) {
        double min_val = *std::min_element(data.begin(), data.end());
        double max_val = *std::max_element(data.begin(), data.end());
        if (max_val == min_val) {
            return data;
        }
        std::vector<double> normalized_data(data.size());
        std::transform(data.begin(), data.end(), normalized_data.begin(), [min_val, max_val](double val) {
            return (val - min_val) / (max_val - min_val);
        });
        return normalized_data;
    }

private:
    std::vector<double> data;
};

class BoundaryHandler {
public:
    BoundaryHandler(SignalProcessor& processor) : processor(processor) {}

    std::vector<double> handle_edges(const std::vector<double>& data, const std::string& mode = "reflect") {
        std::vector<double> padded_data(data.size() + 2);
        padded_data[0] = data.front();
        padded_data.back() = data.back();
        std::copy(data.begin(), data.end(), padded_data.begin() + 1);
        return padded_data;
    }

    bool terminate_condition(const std::vector<double>& data, double threshold = 0.5) {
        return std::all_of(data.begin(), data.end(), [threshold](double val) { return val < threshold; });
    }

private:
    SignalProcessor& processor;
};

class MainController {
public:
    MainController(const std::vector<double>& signal_data) : signal_processor(signal_data), boundary_handler(signal_processor) {}

    std::vector<double> process_signal() {
        std::vector<double> kernel = {1, 2, 1};
        std::vector<double> data = signal_processor.apply_filter(kernel);
        data = boundary_handler.handle_edges(data);
        std::vector<double> normalized_data = signal_processor.normalize(data);
        while (!boundary_handler.terminate_condition(normalized_data)) {
            data = signal_processor.apply_filter(kernel);
            data = boundary_handler.handle_edges(data);
            normalized_data = signal_processor.normalize(data);
        }
        return normalized_data;
    }

private:
    SignalProcessor signal_processor;
    BoundaryHandler boundary_handler;
};

int main() {
    std::vector<double> signal_data = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    MainController controller(signal_data);
    std::vector<double> result = controller.process_signal();
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}