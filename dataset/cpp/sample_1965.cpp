#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

std::pair<std::vector<double>, std::vector<double>> permute_data(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(combined.begin(), combined.end(), g);
    size_t mid = combined.size() / 2;
    return {std::vector<double>(combined.begin(), combined.begin() + mid), std::vector<double>(combined.begin() + mid, combined.end())};
}

double calculate_p_value(const std::vector<double>& data1, const std::vector<double>& data2, int iterations = 1000) {
    double original_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    int larger_diff_count = 0;
    for (int i = 0; i < iterations; ++i) {
        auto [permuted_data1, permuted_data2] = permute_data(data1, data2);
        double permuted_diff = std::accumulate(permuted_data1.begin(), permuted_data1.end(), 0.0) / permuted_data1.size() - std::accumulate(permuted_data2.begin(), permuted_data2.end(), 0.0) / permuted_data2.size();
        if (permuted_diff >= original_diff) {
            ++larger_diff_count;
        }
    }
    return static_cast<double>(larger_diff_count) / iterations;
}

int main() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);
    std::vector<double> data1, data2;
    for (int i = 0; i < 100; ++i) {
        data1.push_back(d1(g));
        data2.push_back(d2(g));
    }
    double p_value = calculate_p_value(data1, data2);
    std::cout << p_value << std::endl;
    return 0;
}