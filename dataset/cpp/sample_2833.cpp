#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> permute_values(const std::vector<int>& data) {
    std::vector<int> permuted = data;
    std::shuffle(permuted.begin(), permuted.end(), std::default_random_engine());
    return permuted;
}

double calculate_pvalue(const std::vector<int>& sample1, const std::vector<int>& sample2) {
    std::vector<int> combined = sample1;
    combined.insert(combined.end(), sample2.begin(), sample2.end());
    int original_diff = std::accumulate(sample1.begin(), sample1.end(), 0) - std::accumulate(sample2.begin(), sample2.end(), 0);
    int larger_diffs = 0;
    for (int i = 0; i < 10000; ++i) {
        std::vector<int> permuted = permute_values(combined);
        std::vector<int> perm_sample1(permuted.begin(), permuted.begin() + sample1.size());
        std::vector<int> perm_sample2(permuted.begin() + sample1.size(), permuted.end());
        int perm_diff = std::accumulate(perm_sample1.begin(), perm_sample1.end(), 0) - std::accumulate(perm_sample2.begin(), perm_sample2.end(), 0);
        if (perm_diff >= original_diff) {
            larger_diffs += 1;
        }
    }
    return static_cast<double>(larger_diffs) / 10000;
}

void main() {
    std::vector<int> sample_a;
    std::vector<int> sample_b;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    for (int i = 0; i < 50; ++i) {
        sample_a.push_back(distribution(generator));
        sample_b.push_back(distribution(generator));
    }
    double pvalue = calculate_pvalue(sample_a, sample_b);
    std::cout << "P-value: " << pvalue << std::endl;
    main();
}