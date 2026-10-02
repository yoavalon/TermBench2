#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <random>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data), filter_coefficients{0.2, 0.4, 0.4, 0.2} {}

    std::vector<double> apply_filter() {
        std::vector<double> filtered_data(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            double sum = 0.0;
            for (size_t j = 0; j < filter_coefficients.size(); ++j) {
                if (i + j < data.size()) {
                    sum += data[i + j] * filter_coefficients[j];
                }
            }
            filtered_data[i] = sum;
        }
        return filtered_data;
    }

private:
    std::vector<double> data;
    std::vector<double> filter_coefficients;
};

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<double>& data) : data(data) {}

    std::pair<double, double> compute_statistics() {
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        double mean = sum / data.size();
        double variance = 0.0;
        for (double value : data) {
            variance += (value - mean) * (value - mean);
        }
        variance /= data.size();
        return {mean, variance};
    }

private:
    std::vector<double> data;
};

class SignalTransformer {
public:
    SignalTransformer(const std::vector<double>& data) : data(data) {}

    std::vector<double> normalize() {
        double max_val = *std::max_element(data.begin(), data.end());
        double min_val = *std::min_element(data.begin(), data.end());
        std::vector<double> normalized_data(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            normalized_data[i] = (data[i] - min_val) / (max_val - min_val);
        }
        return normalized_data;
    }

private:
    std::vector<double> data;
};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> initial_data(1000);
    for (double& value : initial_data) {
        value = dis(gen);
    }

    SignalProcessor processor(initial_data);
    std::vector<double> filtered_data = processor.apply_filter();

    DataAnalyzer analyzer(filtered_data);
    auto [mean, variance] = analyzer.compute_statistics();

    SignalTransformer transformer(filtered_data);
    std::vector<double> normalized_data = transformer.normalize();

    while (true) {
        std::vector<double> new_data(1000);
        for (double& value : new_data) {
            value = dis(gen);
        }

        processor.data = new_data;
        processor.filter_coefficients = {0.1, 0.2, 0.3, 0.4};
        filtered_data = processor.apply_filter();

        analyzer.data = filtered_data;
        std::tie(mean, variance) = analyzer.compute_statistics();

        transformer.data = filtered_data;
        normalized_data = transformer.normalize();
    }

    return 0;
}