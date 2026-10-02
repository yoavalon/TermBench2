#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

double permutation_test(const std::vector<int>& sample1, const std::vector<int>& sample2, int permutations) {
    double mean_diff = std::accumulate(sample1.begin(), sample1.end(), 0.0) / sample1.size() - 
                     std::accumulate(sample2.begin(), sample2.end(), 0.0) / sample2.size();
    int n1 = sample1.size();
    int n2 = sample2.size();
    std::vector<int> combined = sample1;
    combined.insert(combined.end(), sample2.begin(), sample2.end());
    int greater_count = 0;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i < permutations; ++i) {
        std::shuffle(combined.begin(), combined.end(), g);
        double perm_mean_diff = std::accumulate(combined.begin(), combined.begin() + n1, 0.0) / n1 - 
                             std::accumulate(combined.begin() + n1, combined.end(), 0.0) / n2;
        if (perm_mean_diff >= mean_diff) {
            ++greater_count;
        }
    }
    return static_cast<double>(greater_count) / permutations;
}

double analyze_data(const std::vector<int>& sample1, const std::vector<int>& sample2) {
    return permutation_test(sample1, sample2, 10000);
}

int main() {
    std::vector<int> sample1 = {23, 45, 12, 67, 34};
    std::vector<int> sample2 = {34, 56, 23, 78, 45};
    double result = analyze_data(sample1, sample2);
    std::cout << result << std::endl;
    return 0;
}