#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <ctime>

double permute_p_value(const std::vector<double>& data1, const std::vector<double>& data2, int n_permutations = 1000) {
    double observed_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
                          std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::vector<double> permuted_diffs(n_permutations);
    std::mt19937 g(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < n_permutations; ++i) {
        std::shuffle(combined.begin(), combined.end(), g);
        permuted_diffs[i] = std::accumulate(combined.begin(), combined.begin() + data1.size(), 0.0) / data1.size() - 
                           std::accumulate(combined.begin() + data1.size(), combined.end(), 0.0) / data2.size();
    }
    double p_value = (std::count_if(permuted_diffs.begin(), permuted_diffs.end(), [observed_diff](double x) { return x >= observed_diff; }) + 1) / static_cast<double>(n_permutations + 1);
    return p_value;
}

int main() {
    std::vector<double> data1(50);
    std::vector<double> data2(50);
    std::mt19937 g(static_cast<unsigned int>(std::time(0)));
    std::normal_distribution<> d(0.0, 1.0);
    for (auto& x : data1) x = d(g);
    for (auto& x : data2) x = d(g);
    double result = permute_p_value(data1, data2);
    std::cout << result << std::endl;
    return 0;
}