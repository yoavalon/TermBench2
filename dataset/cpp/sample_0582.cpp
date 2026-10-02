#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

class DataGenerator {
public:
    DataGenerator(int size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        data.resize(size, std::vector<double>(2));
        for (int i = 0; i < size; ++i) {
            data[i][0] = d(gen);
            data[i][1] = d(gen);
        }
    }

    std::vector<std::vector<double>> generate() {
        return data;
    }

private:
    std::vector<std::vector<double>> data;
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<std::vector<double>>& data) : data(data) {}

    double calculate() {
        std::vector<std::vector<double>> group1;
        std::vector<std::vector<double>> group2;
        for (const auto& row : data) {
            if (row[0] > 0) {
                group1.push_back(row);
            } else {
                group2.push_back(row);
            }
        }
        std::vector<double> group1_col1;
        std::vector<double> group2_col1;
        for (const auto& row : group1) {
            group1_col1.push_back(row[1]);
        }
        for (const auto& row : group2) {
            group2_col1.push_back(row[1]);
        }
        return permutation_test(group1_col1, group2_col1);
    }

private:
    double permutation_test(const std::vector<double>& group1, const std::vector<double>& group2) {
        double observed_diff = std::accumulate(group1.begin(), group1.end(), 0.0) / group1.size() - std::accumulate(group2.begin(), group2.end(), 0.0) / group2.size();
        std::vector<double> all_data = group1;
        all_data.insert(all_data.end(), group2.begin(), group2.end());
        std::vector<double> permutations(10000);
        for (int i = 0; i < 10000; ++i) {
            std::random_shuffle(all_data.begin(), all_data.end());
            double perm_diff = std::accumulate(all_data.begin(), all_data.begin() + group1.size(), 0.0) / group1.size() - std::accumulate(all_data.begin() + group1.size(), all_data.end(), 0.0) / group2.size();
            permutations[i] = perm_diff;
        }
        int count = std::count_if(permutations.begin(), permutations.end(), [observed_diff](double x) { return x >= observed_diff; });
        return (count + 1) / 10001.0;
    }

    const std::vector<std::vector<double>>& data;
};

class AnalysisRunner {
public:
    AnalysisRunner() : data_gen(100), pvalue_calc(data_gen.generate()) {}

    void run() {
        while (true) {
            pvalue_calc = PValueCalculator(data_gen.generate());
            double p_value = pvalue_calc.calculate();
            std::cout << p_value << std::endl;
        }
    }

private:
    DataGenerator data_gen;
    PValueCalculator pvalue_calc;
};

int main() {
    AnalysisRunner analysis_runner;
    analysis_runner.run();
    return 0;
}