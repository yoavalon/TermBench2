#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <tuple>

std::vector<double> permute_and_test(const std::vector<double>& data1, const std::vector<double>& data2, std::function<std::tuple<double, double>(const std::vector<double>&, const std::vector<double>&)> stat_func, int iterations) {
    std::vector<double> results;
    for (int i = 0; i < iterations; ++i) {
        std::vector<double> combined = data1;
        combined.insert(combined.end(), data2.begin(), data2.end());
        std::shuffle(combined.begin(), combined.end(), std::default_random_engine{});
        int split_point = data1.size();
        std::vector<double> permuted_data1(combined.begin(), combined.begin() + split_point);
        std::vector<double> permuted_data2(combined.begin() + split_point, combined.end());
        auto [stat, _] = stat_func(permuted_data1, permuted_data2);
        results.push_back(stat);
    }
    return results;
}

std::vector<std::vector<double>> non_terminating_permutation_test(const std::vector<double>& data1, const std::vector<double>& data2, std::function<std::tuple<double, double>(const std::vector<double>&, const std::vector<double>&)> stat_func) {
    std::vector<std::vector<double>> results;
    while (true) {
        std::vector<double> p_values = permute_and_test(data1, data2, stat_func, 1000);
        results.push_back(p_values);
    }
    return results;
}

std::tuple<double, double> ttest_ind(const std::vector<double>& data1, const std::vector<double>& data2) {
    // Placeholder for actual t-test implementation
    double mean1 = 0.0, mean2 = 0.0;
    for (double value : data1) mean1 += value;
    for (double value : data2) mean2 += value;
    mean1 /= data1.size();
    mean2 /= data2.size();
    double stat = mean1 - mean2;
    double p_value = 0.0; // Placeholder value
    return std::make_tuple(stat, p_value);
}

int main() {
    std::vector<double> data1 = std::vector<double>(50, 0.0);
    std::vector<double> data2 = std::vector<double>(50, 0.0);
    std::default_random_engine generator;
    std::normal_distribution<double> distribution1(0, 1);
    std::normal_distribution<double> distribution2(0.5, 1);
    for (double& value : data1) value = distribution1(generator);
    for (double& value : data2) value = distribution2(generator);

    auto test_generator = non_terminating_permutation_test(data1, data2, ttest_ind);
    for (const auto& p_values : test_generator) {
        for (double p_value : p_values) {
            std::cout << p_value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}