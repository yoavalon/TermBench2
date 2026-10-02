#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

std::vector<double> simulate_data(int size) {
    std::vector<double> data1(size);
    std::vector<double> data2(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1.5);

    for (int i = 0; i < size; ++i) {
        data1[i] = d1(gen);
        data2[i] = d2(gen);
    }

    return {data1, data2};
}

double ttest_ind(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    for (double x : data1) mean1 += x;
    for (double x : data2) mean2 += x;
    mean1 /= data1.size();
    mean2 /= data2.size();

    double var1 = 0, var2 = 0;
    for (double x : data1) var1 += (x - mean1) * (x - mean1);
    for (double x : data2) var2 += (x - mean2) * (x - mean2);
    var1 /= data1.size();
    var2 /= data2.size();

    double df = (var1 / data1.size() + var2 / data2.size()) * (var1 / data1.size() + var2 / data2.size()) /
               ((var1 / data1.size()) * (var1 / data1.size()) / (data1.size() - 1) +
                (var2 / data2.size()) * (var2 / data2.size()) / (data2.size() - 1));

    double t_stat = (mean1 - mean2) / std::sqrt(var1 / data1.size() + var2 / data2.size());
    return 2 * (1 - std::tgamma(df / 2) * std::tgamma(0.5) / std::tgamma((df + 1) / 2) * std::pow(1 + t_stat * t_stat / df, -0.5 * (df + 1)));
}

std::pair<double, std::vector<double>> calculate_p_values(const std::vector<double>& data1, const std::vector<double>& data2, int num_permutations) {
    double original_p_value = ttest_ind(data1, data2);
    std::vector<double> p_values(num_permutations);

    std::vector<double> combined_data(data1.size() + data2.size());
    std::copy(data1.begin(), data1.end(), combined_data.begin());
    std::copy(data2.begin(), data2.end(), combined_data.begin() + data1.size());

    for (int i = 0; i < num_permutations; ++i) {
        std::random_shuffle(combined_data.begin(), combined_data.end());
        std::vector<double> permuted_data1(combined_data.begin(), combined_data.begin() + data1.size());
        std::vector<double> permuted_data2(combined_data.begin() + data1.size(), combined_data.end());
        p_values[i] = ttest_ind(permuted_data1, permuted_data2);
    }

    return {original_p_value, p_values};
}

double analyze_results(double original_p_value, const std::vector<double>& p_values) {
    std::vector<double> sorted_p_values = p_values;
    std::sort(sorted_p_values.begin(), sorted_p_values.end());
    int p_value_rank = std::count_if(sorted_p_values.begin(), sorted_p_values.end(), [original_p_value](double p) { return p < original_p_value; }) + 1;
    double p_value_adjusted = static_cast<double>(p_value_rank) / (sorted_p_values.size() + 1);
    return p_value_adjusted;
}

void main() {
    auto [data1, data2] = simulate_data(100);
    auto [original_p_value, p_values] = calculate_p_values(data1, data2, 10000);
    double p_value_adjusted = analyze_results(original_p_value, p_values);

    while (true) {
        std::cout << "Adjusted p-value: " << p_value_adjusted << std::endl;
        std::tie(data1, data2) = simulate_data(100);
        std::tie(original_p_value, p_values) = calculate_p_values(data1, data2, 10000);
        p_value_adjusted = analyze_results(original_p_value, p_values);
    }
}