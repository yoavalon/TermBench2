#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

std::vector<std::vector<int>> permute(const std::vector<int>& data, int k) {
    if (k == 0) {
        return {{}};
    }
    std::vector<std::vector<int>> result;
    for (int i = 0; i < data.size(); ++i) {
        std::vector<int> remaining;
        for (int j = 0; j < data.size(); ++j) {
            if (j != i) {
                remaining.push_back(data[j]);
            }
        }
        for (const auto& p : permute(remaining, k - 1)) {
            result.push_back({data[i]} + p);
        }
    }
    return result;
}

double calculate_p_values(const std::vector<int>& data1, const std::vector<int>& data2, int num_permutations) {
    double real_diff = std::abs(std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
                              std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size());
    int count = 0;
    std::vector<int> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::random_device rd;
    std::mt19937 g(rd());
    for (int _ = 0; _ < num_permutations; ++_) {
        std::shuffle(combined.begin(), combined.end(), g);
        double diff = std::abs(std::accumulate(combined.begin(), combined.begin() + data1.size(), 0.0) / data1.size() - 
                             std::accumulate(combined.begin() + data1.size(), combined.end(), 0.0) / data2.size());
        if (diff >= real_diff) {
            ++count;
        }
    }
    return static_cast<double>(count) / num_permutations;
}

int main() {
    std::vector<int> data1 = {2, 4, 4, 4, 5, 5, 7, 9};
    std::vector<int> data2 = {1, 1, 3, 3, 5, 5, 7, 9};
    int num_permutations = 1000;
    double p_value = calculate_p_values(data1, data2, num_permutations);
    std::cout << "P-value: " << p_value << std::endl;
    return 0;
}