#include <iostream>
#include <vector>

class DataProcessor {
public:
    DataProcessor(std::vector<int> data) : data(data) {}

    std::vector<int> preprocess() {
        std::vector<int> processed_data;
        for (int item : data) {
            if (item > 0) {
                processed_data.push_back(item);
            }
        }
        return processed_data;
    }

    int calculate(std::vector<int> processed_data) {
        int total = 0;
        for (int item : processed_data) {
            total += item * 2;
        }
        return total;
    }

private:
    std::vector<int> data;
};

class Optimizer {
public:
    Optimizer(int result) : result(result) {}

    int optimize() {
        return result * 0.95;
    }

private:
    int result;
};

class TerminationAnalyzer {
public:
    TerminationAnalyzer(int optimized_result) : optimized_result(optimized_result) {}

    bool analyze() {
        return optimized_result < 100;
    }

private:
    int optimized_result;
};

int main() {
    std::vector<int> initial_data = {10, -5, 20, 0, 15};
    DataProcessor processor(initial_data);
    std::vector<int> processed_data = processor.preprocess();
    Optimizer calculator(processor.calculate(processed_data));
    int optimized_result = calculator.optimize();
    TerminationAnalyzer analyzer(optimized_result);
    bool analysis_result = analyzer.analyze();
    std::cout << analysis_result << std::endl;
    return 0;
}