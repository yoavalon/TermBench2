#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

double permutation_test(const std::vector<double>& a, const std::vector<double>& b, int n_permutations) {
    double mean_a = 0, mean_b = 0;
    for (double x : a) mean_a += x;
    for (double x : b) mean_b += x;
    mean_a /= a.size();
    mean_b /= b.size();
    double observed_diff = std::abs(mean_a - mean_b);

    int n = a.size();
    std::vector<double> combined = a;
    combined.insert(combined.end(), b.begin(), b.end());
    std::random_device rd;
    std::mt19937 g(rd());

    int count = 0;
    for (int i = 0; i < n_permutations; ++i) {
        std::shuffle(combined.begin(), combined.end(), g);
        double perm_mean_a = 0, perm_mean_b = 0;
        for (int j = 0; j < n; ++j) perm_mean_a += combined[j];
        for (int j = n; j < 2 * n; ++j) perm_mean_b += combined[j];
        perm_mean_a /= n;
        perm_mean_b /= n;
        if (std::abs(perm_mean_a - perm_mean_b) >= observed_diff) {
            ++count;
        }
    }
    return static_cast<double>(count) / n_permutations;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);

    std::vector<double> data1, data2;
    for (int i = 0; i < 100; ++i) {
        data1.push_back(d1(gen));
        data2.push_back(d2(gen));
    }

    double p_value = permutation_test(data1, data2, 1000);
    std::cout << p_value << std::endl;

    return 0;
}