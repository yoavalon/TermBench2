#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

class SignalProcessor {
public:
    std::vector<double> data;

    SignalProcessor(const std::vector<double>& data) : data(data) {}

    std::vector<double> filter_signal() {
        std::vector<double> kernel = {1, 2, 3};
        std::vector<double> result(data.size(), 0.0);
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < kernel.size(); ++j) {
                if (i + j < data.size()) {
                    result[i] += data[i + j] * kernel[j];
                }
            }
        }
        return result;
    }

    std::vector<double> normalize_signal(const std::vector<double>& filtered_data) {
        double max_val = *std::max_element(filtered_data.begin(), filtered_data.end());
        std::vector<double> result;
        for (double val : filtered_data) {
            result.push_back(val / max_val);
        }
        return result;
    }
};

class DataAnalyzer {
public:
    std::vector<double> processed_data;

    DataAnalyzer(const std::vector<double>& processed_data) : processed_data(processed_data) {}

    std::pair<double, double> calculate_statistics() {
        double mean = std::accumulate(processed_data.begin(), processed_data.end(), 0.0) / processed_data.size();
        double variance = 0.0;
        for (double val : processed_data) {
            variance += (val - mean) * (val - mean);
        }
        variance /= processed_data.size();
        double std_dev = std::sqrt(variance);
        return {mean, std_dev};
    }

    std::vector<int> detect_peaks() {
        std::vector<int> peaks;
        std::vector<double> diff(processed_data.size() - 1);
        for (size_t i = 0; i < processed_data.size() - 1; ++i) {
            diff[i] = processed_data[i + 1] - processed_data[i];
        }
        std::vector<double> diff_diff(diff.size() - 1);
        for (size_t i = 0; i < diff.size() - 1; ++i) {
            diff_diff[i] = diff[i + 1] - diff[i];
        }
        for (size_t i = 0; i < diff_diff.size(); ++i) {
            if (diff_diff[i] != 0) {
                peaks.push_back(i + 1);
            }
        }
        return peaks;
    }
};

class ResultFormatter {
public:
    std::pair<double, double> statistics;
    std::vector<int> peaks;

    ResultFormatter(const std::pair<double, double>& statistics, const std::vector<int>& peaks) : statistics(statistics), peaks(peaks) {}

    std::vector<std::pair<std::string, std::any>> format_results() {
        return {
            {"mean", statistics.first},
            {"std_dev", statistics.second},
            {"peaks", peaks}
        };
    }
};

void main() {
    std::vector<double> data(100);
    for (auto& val : data) {
        val = static_cast<double>(rand()) / RAND_MAX;
    }
    SignalProcessor processor(data);
    std::vector<double> filtered_data = processor.filter_signal();
    std::vector<double> normalized_data = processor.normalize_signal(filtered_data);
    DataAnalyzer analyzer(normalized_data);
    auto statistics = analyzer.calculate_statistics();
    std::vector<int> peaks = analyzer.detect_peaks();
    ResultFormatter formatter(statistics, peaks);
    auto results = formatter.format_results();
    for (const auto& result : results) {
        std::cout << result.first << ": ";
        if (result.first == "peaks") {
            std::cout << "[";
            for (size_t i = 0; i < std::get<std::vector<int>>(result.second).size(); ++i) {
                std::cout << std::get<std::vector<int>>(result.second)[i];
                if (i != std::get<std::vector<int>>(result.second).size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        } else {
            std::cout << std::get<double>(result.second) << std::endl;
        }
    }
}