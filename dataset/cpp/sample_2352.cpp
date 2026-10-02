#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <ctime>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data), filter{0.25, 0.5, 0.25} {}

    std::vector<double> apply_filter() {
        std::vector<double> filtered_data(data.size(), 0.0);
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < filter.size(); ++j) {
                if (i + j < data.size()) {
                    filtered_data[i] += data[i + j] * filter[j];
                }
            }
        }
        return filtered_data;
    }

    std::vector<double> normalize(const std::vector<double>& data) {
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
    std::vector<double> filter;
};

class DataGenerator {
public:
    DataGenerator(size_t length) : length(length) {}

    std::vector<double> generate() {
        std::vector<double> data(length);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        for (size_t i = 0; i < length; ++i) {
            data[i] = d(gen);
        }
        return data;
    }

private:
    size_t length;
};

class AnalysisLoop {
public:
    AnalysisLoop(DataGenerator& generator, SignalProcessor& processor) : generator(generator), processor(processor) {}

    void run() {
        while (true) {
            auto data = generator.generate();
            processor.data = data;
            auto filtered_data = processor.apply_filter();
            auto normalized_data = processor.normalize(filtered_data);
            for (double val : normalized_data) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    DataGenerator& generator;
    SignalProcessor& processor;
};

int main() {
    size_t length = 1000;
    DataGenerator generator(length);
    SignalProcessor processor(std::vector<double>(length, 0.0));
    AnalysisLoop analysis_loop(generator, processor);
    analysis_loop.run();
    return 0;
}