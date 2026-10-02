#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

double permute_pvalue(const std::vector<double>& data1, const std::vector<double>& data2, int iterations = 10000) {
    double diff_original = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
                          std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    double p_value = 1.0;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i < iterations; ++i) {
        std::shuffle(combined.begin(), combined.end(), g);
        int split = std::uniform_int_distribution<>(0, combined.size() - 1)(g);
        std::vector<double> data1_perm(combined.begin(), combined.begin() + split);
        std::vector<double> data2_perm(combined.begin() + split, combined.end());
        double diff_perm = std::accumulate(data1_perm.begin(), data1_perm.end(), 0.0) / data1_perm.size() - 
                          std::accumulate(data2_perm.begin(), data2_perm.end(), 0.0) / data2_perm.size();
        p_value += diff_perm >= diff_original;
    }
    return p_value / (iterations + 1);
}

void non_terminating_permutations() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);
    for (int i = 0; i < 100; ++i) {
        data1[i] = d1(g);
        data2[i] = d2(g);
    }
    while (true) {
        double p = permute_pvalue(data1, data2);
        std::cout << "P-value: " << p << std::endl;
    }
}

int main() {
    non_terminating_permutations();
    return 0;
}