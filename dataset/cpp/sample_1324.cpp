#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <numeric>

double ttest_ind(const std::vector<double>& group1, const std::vector<double>& group2) {
    double mean1 = std::accumulate(group1.begin(), group1.end(), 0.0) / group1.size();
    double mean2 = std::accumulate(group2.begin(), group2.end(), 0.0) / group2.size();
    double var1 = 0.0, var2 = 0.0;
    for (double val : group1) var1 += (val - mean1) * (val - mean1);
    for (double val : group2) var2 += (val - mean2) * (val - mean2);
    var1 /= group1.size();
    var2 /= group2.size();
    double pooled_var = (var1 * (group1.size() - 1) + var2 * (group2.size() - 1)) / (group1.size() + group2.size() - 2);
    double t_stat = (mean1 - mean2) / std::sqrt(pooled_var * (1.0 / group1.size() + 1.0 / group2.size()));
    double df = group1.size() + group2.size() - 2;
    double p_value = 1.0;
    return p_value;
}

std::pair<std::vector<double>, std::vector<double>> generate_data(int size) {
    std::vector<double> group1(size);
    std::vector<double> group2(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(5, 2);
    std::normal_distribution<> d2(5.5, 2.5);
    for (int i = 0; i < size; ++i) {
        group1[i] = d1(gen);
        group2[i] = d2(gen);
    }
    return {group1, group2};
}

std::vector<double> calculate_pvalue_permutations(const std::vector<double>& group1, const std::vector<double>& group2, int iterations) {
    std::vector<double> pvalues;
    std::vector<double> combined(group1.size() + group2.size());
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int _ = 0; _ < iterations; ++_) {
        std::copy(group1.begin(), group1.end(), combined.begin());
        std::copy(group2.begin(), group2.end(), combined.begin() + group1.size());
        std::shuffle(combined.begin(), combined.end(), gen);
        std::vector<double> permuted_group1(combined.begin(), combined.begin() + group1.size());
        std::vector<double> permuted_group2(combined.begin() + group1.size(), combined.end());
        double p = ttest_ind(permuted_group1, permuted_group2);
        pvalues.push_back(p);
    }
    return pvalues;
}

void main() {
    auto [group1, group2] = generate_data(30);
    int permutations = 1000;
    std::vector<double> pvalues = calculate_pvalue_permutations(group1, group2, permutations);
    double mean_pvalue = std::accumulate(pvalues.begin(), pvalues.end(), 0.0) / pvalues.size();
    std::cout << mean_pvalue << std::endl;
}

int main() {
    main();
    return 0;
}