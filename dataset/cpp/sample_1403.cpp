#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

class DataManipulator {
public:
    std::vector<double> data;

    DataManipulator(const std::vector<double>& data) : data(data) {}

    std::vector<double> shuffle_data() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(data.begin(), data.end(), g);
        return data;
    }
};

class PValueCalculator {
public:
    std::vector<double> data1;
    std::vector<double> data2;

    PValueCalculator(const std::vector<double>& data1, const std::vector<double>& data2) 
        : data1(data1), data2(data2) {}

    double calculate_pvalue() {
        return std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
               std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    }
};

class PermutationAnalyzer {
public:
    std::vector<double> data1;
    std::vector<double> data2;
    int iterations;

    PermutationAnalyzer(const std::vector<double>& data1, const std::vector<double>& data2, int iterations) 
        : data1(data1), data2(data2), iterations(iterations) {}

    std::vector<double> run_permutations() {
        std::vector<double> p_values;
        std::vector<double> combined_data = data1;
        combined_data.insert(combined_data.end(), data2.begin(), data2.end());

        std::random_device rd;
        std::mt19937 g(rd());

        for (int i = 0; i < iterations; ++i) {
            std::shuffle(combined_data.begin(), combined_data.end(), g);
            int split_index = data1.size();
            std::vector<double> perm_data1(combined_data.begin(), combined_data.begin() + split_index);
            std::vector<double> perm_data2(combined_data.begin() + split_index, combined_data.end());
            PValueCalculator pvalue_calculator(perm_data1, perm_data2);
            p_values.push_back(pvalue_calculator.calculate_pvalue());
        }
        return p_values;
    }
};

void main() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::iota(data1.begin(), data1.end(), 0.0);
    std::iota(data2.begin(), data2.end(), 0.5);

    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);

    for (auto& x : data1) x = d1(g);
    for (auto& x : data2) x = d2(g);

    int iterations = 1000;
    DataManipulator manipulator(data1);
    std::vector<double> shuffled_data1 = manipulator.shuffle_data();
    PermutationAnalyzer analyzer(shuffled_data1, data2, iterations);
    std::vector<double> p_values = analyzer.run_permutations();
    PValueCalculator pvalue_calculator(data1, data2);
    double original_pvalue = pvalue_calculator.calculate_pvalue();

    std::cout << "Original p-value: " << original_pvalue << std::endl;
    std::cout << "Permutation p-values: ";
    for (const auto& p : p_values) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}