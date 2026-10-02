cpp
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <numeric>

double ttest_ind(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size();
    double mean2 = std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    double var1 = 0.0, var2 = 0.0;
    for (double num : data1) var1 += std::pow(num - mean1, 2);
    for (double num : data2) var2 += std::pow(num - mean2, 2);
    var1 /= data1.size();
    var2 /= data2.size();
    double se = std::sqrt(var1 / data1.size() + var2 / data2.size());
    return std::abs(mean1 - mean2) / se;
}

std::vector<double> generate_data(int size) {
    std::vector<double> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < size; ++i) {
        data[i] = d(gen);
    }
    return data;
}

std::pair<double, std::vector<double>> perform_permutation_test(const std::vector<double>& data1, const std::vector<double>& data2, int iterations) {
    double original_p_value = ttest_ind(data1, data2);
    std::vector<double> p_values;
    std::vector<double> combined_data = data1;
    combined_data.insert(combined_data.end(), data2.begin(), data2.end());
    for (int i = 0; i < iterations; ++i) {
        std::random_shuffle(combined_data.begin(), combined_data.end());
        double new_p_value = ttest_ind(std::vector<double>(combined_data.begin(), combined_data.begin() + data1.size()), std::vector<double>(combined_data.begin() + data1.size(), combined_data.end()));
        p_values.push_back(new_p_value);
    }
    return {original_p_value, p_values};
}

int main() {
    std::vector<double> data1 = generate_data(50);
    std::vector<double> data2 = generate_data(50);
    int iterations = 1000;
    auto [original_p_value, p_values] = perform_permutation_test(data1, data2, iterations);
    std::cout << original_p_value << std::endl;
    int count = 0;
    for (double p : p_values) {
        if (p < original_p_value) count++;
    }
    std::cout << static_cast<double>(count) / p_values.size() << std::endl;
    return 0;
}