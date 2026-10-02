#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

class PValuePermutations {
public:
    PValuePermutations(const std::vector<double>& data, int iterations)
        : data(data), iterations(iterations) {}

    void generate_permutations() {
        for (int i = 0; i < iterations; ++i) {
            std::vector<double> permuted_data = data;
            std::shuffle(permuted_data.begin(), permuted_data.end(), std::default_random_engine());
            permutations.push_back(permuted_data);
        }
    }

    std::vector<double> calculate_p_values() {
        std::vector<double> p_values;
        double original_mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
        for (const auto& permuted_data : permutations) {
            double permuted_mean = std::accumulate(permuted_data.begin(), permuted_data.end(), 0.0) / permuted_data.size();
            double p_value = calculate_one_tailed_p_value(original_mean, permuted_mean);
            p_values.push_back(p_value);
        }
        return p_values;
    }

private:
    double calculate_one_tailed_p_value(double original_mean, double permuted_mean) {
        if (original_mean > permuted_mean) {
            return 1;
        } else {
            return 0;
        }
    }

    std::vector<double> data;
    int iterations;
    std::vector<std::vector<double>> permutations;
};

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<double>& data, int iterations)
        : data(data), iterations(iterations), p_value_calculator(data, iterations) {}

    double analyze() {
        p_value_calculator.generate_permutations();
        std::vector<double> p_values = p_value_calculator.calculate_p_values();
        return std::accumulate(p_values.begin(), p_values.end(), 0.0) / p_values.size();
    }

private:
    std::vector<double> data;
    int iterations;
    PValuePermutations p_value_calculator;
};

int main() {
    std::vector<double> data;
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, 1);
    for (int i = 0; i < 100; ++i) {
        data.push_back(distribution(generator));
    }
    int iterations = 1000;
    DataAnalyzer analyzer(data, iterations);
    double result = analyzer.analyze();
    std::cout << "Mean p-value: " << result << std::endl;
    return 0;
}