#include <iostream>
#include <vector>
#include <cmath>

class Simulation {
public:
    Simulation(double a, double b, double c) : a(a), b(b), c(c) {}

    double calculate(double x) {
        return a * x * x + b * x + c;
    }

private:
    double a;
    double b;
    double c;
};

class PrecisionAnalyzer {
public:
    PrecisionAnalyzer(Simulation* simulation) : simulation(simulation) {}

    std::vector<double> analyze(const std::vector<double>& x_values) {
        std::vector<double> results;
        for (double x : x_values) {
            double result = simulation->calculate(x);
            results.push_back(result);
        }
        return results;
    }

private:
    Simulation* simulation;
};

class DataProcessor {
public:
    DataProcessor(PrecisionAnalyzer* analyzer) : analyzer(analyzer) {}

    std::vector<double> process(const std::vector<double>& x_values) {
        std::vector<double> raw_data = analyzer->analyze(x_values);
        std::vector<double> processed_data = format_data(raw_data);
        return processed_data;
    }

private:
    std::vector<double> format_data(const std::vector<double>& data) {
        std::vector<double> formatted;
        for (double value : data) {
            formatted.push_back(round(value * 100000) / 100000);
        }
        return formatted;
    }

    PrecisionAnalyzer* analyzer;
};

int main() {
    Simulation sim(2.0, 3.0, 1.0);
    PrecisionAnalyzer analyzer(&sim);
    DataProcessor processor(&analyzer);
    std::vector<double> x_values = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    std::vector<double> processed_results = processor.process(x_values);
    for (size_t i = 0; i < processed_results.size(); ++i) {
        std::cout << "X: " << x_values[i] << ", Result: " << processed_results[i] << std::endl;
    }
    return 0;
}