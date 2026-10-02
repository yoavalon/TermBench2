#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> permute_data(const std::vector<int>& data) {
    std::vector<int> shuffled_data = data;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled_data.begin(), shuffled_data.end(), g);
    return shuffled_data;
}

double calculate_pvalue(const std::vector<int>& sample1, const std::vector<int>& sample2, int iterations = 10000) {
    int observed_diff = std::abs(std::accumulate(sample1.begin(), sample1.end(), 0) - std::accumulate(sample2.begin(), sample2.end(), 0));
    int larger_diff_count = 0;
    for (int _ = 0; _ < iterations; ++_) {
        std::vector<int> combined = sample1;
        combined.insert(combined.end(), sample2.begin(), sample2.end());
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(combined.begin(), combined.end(), g);
        std::vector<int> permuted_sample1(combined.begin(), combined.begin() + sample1.size());
        std::vector<int> permuted_sample2(combined.begin() + sample1.size(), combined.end());
        int permuted_diff = std::abs(std::accumulate(permuted_sample1.begin(), permuted_sample1.end(), 0) - std::accumulate(permuted_sample2.begin(), permuted_sample2.end(), 0));
        if (permuted_diff >= observed_diff) {
            ++larger_diff_count;
        }
    }
    return static_cast<double>(larger_diff_count) / iterations;
}

void non_terminating_simulation() {
    std::vector<int> data1;
    std::vector<int> data2;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int _ = 0; _ < 50; ++_) {
        data1.push_back(rd() % 100 + 1);
        data2.push_back(rd() % 100 + 1);
    }
    while (true) {
        std::vector<int> permuted_data1 = permute_data(data1);
        std::vector<int> permuted_data2 = permute_data(data2);
        double pvalue = calculate_pvalue(permuted_data1, permuted_data2);
        std::cout << "P-value: " << pvalue << std::endl;
    }
}

int main() {
    non_terminating_simulation();
    return 0;
}