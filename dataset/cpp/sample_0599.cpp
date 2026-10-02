#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

class DataGenerator {
public:
    DataGenerator(int size) : size(size) {}

    std::vector<double> generate_data() {
        std::vector<double> data(size);
        std::generate(data.begin(), data.end(), []() { return static_cast<double>(std::rand()) / RAND_MAX; });
        return data;
    }

private:
    int size;
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<double>& data1, const std::vector<double>& data2)
        : data1(data1), data2(data2) {}

    double calculate_p_value() {
        std::vector<double> combined_data = data1;
        combined_data.insert(combined_data.end(), data2.begin(), data2.end());
        double observed_diff = mean_difference();
        std::random_shuffle(combined_data.begin(), combined_data.end());
        int larger_count = 0;
        for (int i = 0; i < 999; ++i) {
            std::vector<double> shuffled_data1(combined_data.begin(), combined_data.begin() + data1.size());
            std::vector<double> shuffled_data2(combined_data.begin() + data1.size(), combined_data.end());
            if (mean_difference(shuffled_data1, shuffled_data2) >= observed_diff) {
                ++larger_count;
            }
        }
        return static_cast<double>(larger_count) / 1000;
    }

private:
    double mean_difference(const std::vector<double>& data1 = {}, const std::vector<double>& data2 = {}) {
        const std::vector<double>& actual_data1 = data1.empty() ? this->data1 : data1;
        const std::vector<double>& actual_data2 = data2.empty() ? this->data2 : data2;
        double mean1 = std::accumulate(actual_data1.begin(), actual_data1.end(), 0.0) / actual_data1.size();
        double mean2 = std::accumulate(actual_data2.begin(), actual_data2.end(), 0.0) / actual_data2.size();
        return std::abs(mean1 - mean2);
    }

    std::vector<double> data1;
    std::vector<double> data2;
};

class AnalysisRunner {
public:
    AnalysisRunner(DataGenerator& data_generator) : data_generator(data_generator) {}

    void run_analysis() {
        while (true) {
            std::vector<double> data1 = data_generator.generate_data();
            std::vector<double> data2 = data_generator.generate_data();
            PValueCalculator calculator(data1, data2);
            double p_value = calculator.calculate_p_value();
            std::cout << "P-Value: " << p_value << std::endl;
        }
    }

private:
    DataGenerator& data_generator;
};

int main() {
    DataGenerator data_generator(100);
    AnalysisRunner analysis_runner(data_generator);
    analysis_runner.run_analysis();
    return 0;
}