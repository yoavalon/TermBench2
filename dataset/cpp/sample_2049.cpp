#include <iostream>
#include <vector>
#include <map>
#include <cmath>

class DataProcessor {
public:
    DataProcessor(std::vector<double> data) : data(data) {}

    std::vector<double> process_data() {
        std::vector<double> processed;
        for (double item : data) {
            processed.push_back(adjust_precision(item));
        }
        return processed;
    }

private:
    std::vector<double> data;

    double adjust_precision(double value) {
        return std::round(value * 100000) / 100000;
    }
};

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(std::vector<double> processed_data) : processed_data(processed_data) {}

    std::vector<double> optimize() {
        std::vector<double> optimized_data;
        for (double item : processed_data) {
            optimized_data.push_back(calculate_cost(item));
        }
        return optimized_data;
    }

private:
    std::vector<double> processed_data;

    double calculate_cost(double item) {
        return item * 1.05;
    }
};

class ResultCompiler {
public:
    ResultCompiler(std::vector<double> optimized_data) : optimized_data(optimized_data) {}

    std::map<int, double> compile_results() {
        std::map<int, double> result;
        for (size_t index = 0; index < optimized_data.size(); ++index) {
            result[index] = optimized_data[index];
        }
        return result;
    }

private:
    std::vector<double> optimized_data;
};

int main() {
    std::vector<double> raw_data = {100.123456, 200.654321, 300.987654, 400.135792, 500.24681};
    DataProcessor processor(raw_data);
    std::vector<double> processed_data = processor.process_data();
    SupplyChainOptimizer optimizer(processed_data);
    std::vector<double> optimized_data = optimizer.optimize();
    ResultCompiler compiler(optimized_data);
    std::map<int, double> results = compiler.compile_results();

    for (const auto& pair : results) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}