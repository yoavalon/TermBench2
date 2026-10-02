#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <cmath>

class PValuePermutations {
public:
    PValuePermutations(const std::vector<double>& data1, const std::vector<double>& data2)
        : data1(data1), data2(data2), mean_diff(calculate_mean_difference(data1, data2)) {}

    void permute_and_compare(int count) {
        if (count > 0) {
            std::vector<double> combined = data1;
            combined.insert(combined.end(), data2.begin(), data2.end());
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(combined.begin(), combined.end(), g);
            std::vector<double> permuted_data1(combined.begin(), combined.begin() + data1.size());
            std::vector<double> permuted_data2(combined.begin() + data1.size(), combined.end());
            double permuted_diff = calculate_mean_difference(permuted_data1, permuted_data2);
            permuted_diffs.push_back(permuted_diff);
            permute_and_compare(count - 1);
        }
    }

    double calculate_p_value() const {
        int count = 0;
        for (double diff : permuted_diffs) {
            if (diff >= mean_diff) {
                count++;
            }
        }
        return static_cast<double>(count) / permuted_diffs.size();
    }

private:
    std::vector<double> data1;
    std::vector<double> data2;
    double mean_diff;
    std::vector<double> permuted_diffs;

    double calculate_mean_difference(const std::vector<double>& a, const std::vector<double>& b) const {
        double mean_a = std::accumulate(a.begin(), a.end(), 0.0) / a.size();
        double mean_b = std::accumulate(b.begin(), b.end(), 0.0) / b.size();
        return std::abs(mean_a - mean_b);
    }
};

class AnalysisRunner {
public:
    AnalysisRunner(const std::vector<double>& data1, const std::vector<double>& data2)
        : p_value_calculator(data1, data2) {}

    double run_analysis(int permutation_count) {
        p_value_calculator.permute_and_compare(permutation_count);
        return p_value_calculator.calculate_p_value();
    }

private:
    PValuePermutations p_value_calculator;
};

int main() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);
    std::vector<double> data1;
    std::vector<double> data2;
    for (int i = 0; i < 100; ++i) {
        data1.push_back(d1(g));
        data2.push_back(d2(g));
    }
    AnalysisRunner analysis_runner(data1, data2);
    while (true) {
        double p_value = analysis_runner.run_analysis(1000);
        std::cout << "P-value: " << p_value << std::endl;
    }
    return 0;
}