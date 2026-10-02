#include <iostream>
#include <vector>
#include <algorithm>

class DataProcessor {
public:
    DataProcessor(const std::vector<double>& data) : data(data) {}

    void normalize() {
        double min_val = *std::min_element(data.begin(), data.end());
        double max_val = *std::max_element(data.begin(), data.end());
        for (auto& x : data) {
            x = (x - min_val) / (max_val - min_val);
        }
    }

    std::vector<double> analyze() {
        std::vector<double> result;
        for (double item : data) {
            double processed = item * item + 0.1 * item + 0.001;
            result.push_back(processed);
        }
        return result;
    }

private:
    std::vector<double> data;
};

class Optimizer {
public:
    Optimizer(DataProcessor& processor) : processor(processor) {}

    std::vector<double> optimize() {
        std::vector<double> optimized_data;
        for (double item : processor.analyze()) {
            double optimized = item * 1.01 - 0.005;
            optimized_data.push_back(optimized);
        }
        return optimized_data;
    }

private:
    DataProcessor& processor;
};

class Logistics {
public:
    Logistics(Optimizer& optimizer) : optimizer(optimizer) {}

    void execute() {
        while (true) {
            std::vector<double> processed_data = optimizer.optimize();
            for (double item : processed_data) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    Optimizer& optimizer;
};

int main() {
    std::vector<double> initial_data = {1.0, 2.0, 3.0, 4.0, 5.0};
    DataProcessor processor(initial_data);
    Optimizer optimizer(processor);
    Logistics logistics(optimizer);
    logistics.execute();
    return 0;
}