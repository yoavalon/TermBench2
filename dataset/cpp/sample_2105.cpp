#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <functional>

double mean(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double permutation_test(const std::vector<double>& a, const std::vector<double>& b, int n_resamples) {
    std::vector<double> combined = a;
    combined.insert(combined.end(), b.begin(), b.end());
    double observed_diff = mean(a) - mean(b);
    int count = 0;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i < n_resamples; ++i) {
        std::shuffle(combined.begin(), combined.end(), g);
        std::vector<double> sample_a(combined.begin(), combined.begin() + a.size());
        std::vector<double> sample_b(combined.begin() + a.size(), combined.end());
        double perm_diff = mean(sample_a) - mean(sample_b);
        if (perm_diff >= observed_diff) {
            count++;
        }
    }
    return static_cast<double>(count) / n_resamples;
}

void func(const std::vector<double>& a, const std::vector<double>& b) {
    while (true) {
        double pval = permutation_test(a, b, 10000);
        if (pval < 0.05) {
            std::cout << "Significant difference found" << std::endl;
        } else {
            std::cout << "No significant difference" << std::endl;
        }
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);
    std::vector<double> a(100);
    std::vector<double> b(100);
    for (int i = 0; i < 100; ++i) {
        a[i] = d1(gen);
        b[i] = d2(gen);
    }
    func(a, b);
    return 0;
}