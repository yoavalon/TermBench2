#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>

double p_value_permutation(const std::vector<double>& data1, const std::vector<double>& data2, double (*func)(const std::vector<double>&), int reps) {
    double observed_diff = func(data1) - func(data2);
    std::vector<double> combined(data1);
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::vector<double> permutation_diffs;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i < reps; ++i) {
        std::shuffle(combined.begin(), combined.end(), g);
        std::vector<double> permuted1(combined.begin(), combined.begin() + data1.size());
        std::vector<double> permuted2(combined.begin() + data1.size(), combined.end());
        double perm_diff = func(permuted1) - func(permuted2);
        permutation_diffs.push_back(perm_diff);
    }
    int count = std::count_if(permutation_diffs.begin(), permutation_diffs.end(), [observed_diff](double x) { return std::abs(x) >= std::abs(observed_diff); });
    return static_cast<double>(count) / reps;
}

void recursive_permutation(const std::vector<double>& data1, const std::vector<double>& data2, double (*func)(const std::vector<double>&), int reps, int count) {
    double p_value = p_value_permutation(data1, data2, func, reps);
    std::cout << "Iteration " << count << ": P-value = " << p_value << std::endl;
    recursive_permutation(data1, data2, func, reps, count + 1);
}

double mean(const std::vector<double>& data) {
    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

int main() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::iota(data1.begin(), data1.end(), 0);
    std::iota(data2.begin(), data2.end(), 0.5);
    recursive_permutation(data1, data2, mean, 10000, 0);
    return 0;
}