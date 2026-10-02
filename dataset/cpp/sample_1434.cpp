#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

std::vector<double> generate_data(int size) {
    std::vector<double> data1(size);
    std::vector<double> data2(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);

    for (int i = 0; i < size; ++i) {
        data1[i] = d1(gen);
        data2[i] = d2(gen);
    }
    return {data1, data2};
}

std::pair<double, double> perform_ttest(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    double var1 = 0, var2 = 0;
    int n1 = data1.size(), n2 = data2.size();

    for (double x : data1) mean1 += x;
    for (double x : data2) mean2 += x;
    mean1 /= n1;
    mean2 /= n2;

    for (double x : data1) var1 += (x - mean1) * (x - mean1);
    for (double x : data2) var2 += (x - mean2) * (x - mean2);
    var1 /= n1 - 1;
    var2 /= n2 - 1;

    double t_stat = (mean1 - mean2) / std::sqrt(var1 / n1 + var2 / n2);
    double p_value = 2 * (1 - std::erf(std::abs(t_stat) / std::sqrt(2)));
    return {t_stat, p_value};
}

std::vector<double> permute_data(const std::vector<double>& data1, const std::vector<double>& data2, int iterations) {
    std::vector<double> p_values;
    std::vector<double> combined(data1.size() + data2.size());
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < iterations; ++i) {
        std::copy(data1.begin(), data1.end(), combined.begin());
        std::copy(data2.begin(), data2.end(), combined.begin() + data1.size());
        std::shuffle(combined.begin(), combined.end(), gen);

        std::vector<double> permuted_data1(combined.begin(), combined.begin() + data1.size());
        std::vector<double> permuted_data2(combined.begin() + data1.size(), combined.end());
        auto [_, permuted_p_value] = perform_ttest(permuted_data1, permuted_data2);
        p_values.push_back(permuted_p_value);
    }
    return p_values;
}

bool analyze_p_values(const std::vector<double>& p_values, double original_p_value, double alpha = 0.05) {
    int count = 0;
    for (double p : p_values) {
        if (p <= original_p_value) count++;
    }
    double p_value_permutation = static_cast<double>(count) / p_values.size();
    return p_value_permutation < alpha;
}

int main() {
    auto [data1, data2] = generate_data(30);
    auto [t_stat, original_p_value] = perform_ttest(data1, data2);
    std::vector<double> p_values = permute_data(data1, data2, 1000);
    bool result = analyze_p_values(p_values, original_p_value);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}