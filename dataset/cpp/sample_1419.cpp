#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<double>& data) : data(data), optimized_data() {}

    void process_data() {
        for (const auto& item : data) {
            optimized_data.push_back(mutate_item(item));
        }
    }

    double mutate_item(double item) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.8, 1.2);
        double mutation_factor = dis(gen);
        return item * mutation_factor;
    }

private:
    std::vector<double> data;
    std::vector<double> optimized_data;
};

class DataProcessor {
public:
    DataProcessor(const std::vector<int>& data) : data(data) {}

    std::vector<double> normalize_data() {
        double min_val = *std::min_element(data.begin(), data.end());
        double max_val = *std::max_element(data.begin(), data.end());
        std::vector<double> normalized_data;
        for (const auto& x : data) {
            normalized_data.push_back((x - min_val) / (max_val - min_val));
        }
        return normalized_data;
    }

private:
    std::vector<int> data;
};

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<double>& data) : data(data) {}

    std::pair<double, double> calculate_statistics() {
        double mean = 0.0;
        for (const auto& x : data) {
            mean += x;
        }
        mean /= data.size();

        double variance = 0.0;
        for (const auto& x : data) {
            variance += (x - mean) * (x - mean);
        }
        variance /= data.size();

        return {mean, variance};
    }

private:
    std::vector<double> data;
};

void main() {
    std::vector<int> raw_data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 100);

    for (int i = 0; i < 100; ++i) {
        raw_data.push_back(dis(gen));
    }

    DataProcessor processor(raw_data);
    std::vector<double> normalized_data = processor.normalize_data();
    SupplyChainOptimizer optimizer(normalized_data);
    optimizer.process_data();
    std::vector<double> optimized_data = optimizer.optimized_data;
    DataAnalyzer analyzer(optimized_data);
    auto [mean, variance] = analyzer.calculate_statistics();
    std::cout << "Mean: " << mean << ", Variance: " << variance << std::endl;
}

int main() {
    main();
    return 0;
}