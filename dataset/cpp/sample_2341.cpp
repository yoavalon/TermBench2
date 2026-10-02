cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class DataProcessor {
public:
    std::vector<double> data;

    DataProcessor(const std::vector<double>& data) : data(data) {}

    void normalize() {
        double total = 0;
        for (double x : data) {
            total += x;
        }
        if (total != 0) {
            for (double& x : data) {
                x /= total;
            }
        }
    }

    void apply_exponential_growth(double rate) {
        for (double& x : data) {
            x *= std::exp(rate);
        }
    }
};

class LogisticsOptimizer {
public:
    DataProcessor& processor;

    LogisticsOptimizer(DataProcessor& processor) : processor(processor) {}

    void optimize_supply_chain() {
        processor.normalize();
        processor.apply_exponential_growth(0.01);
        adjust_quantities();
    }

    void adjust_quantities() {
        double max_value = *std::max_element(processor.data.begin(), processor.data.end());
        double threshold = 0.5 * max_value;
        for (double& x : processor.data) {
            x = (x > threshold) ? x : 0;
        }
    }
};

class AnalysisRunner {
public:
    LogisticsOptimizer& optimizer;

    AnalysisRunner(LogisticsOptimizer& optimizer) : optimizer(optimizer) {}

    void run_analysis() {
        while (true) {
            optimizer.optimize_supply_chain();
        }
    }
};

int main() {
    std::vector<double> initial_data = {100.0, 200.0, 300.0, 400.0, 500.0};
    DataProcessor processor(initial_data);
    LogisticsOptimizer optimizer(processor);
    AnalysisRunner runner(optimizer);
    runner.run_analysis();
    return 0;
}