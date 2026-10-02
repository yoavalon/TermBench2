#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>

double simulate_p_value(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> merged = a;
    merged.insert(merged.end(), b.begin(), b.end());
    std::random_shuffle(merged.begin(), merged.end());
    int observed_diff = std::abs(std::accumulate(a.begin(), a.end(), 0) - std::accumulate(b.begin(), b.end(), 0));
    int count = 0;
    for (int i = 0; i < 10000; ++i) {
        std::random_shuffle(merged.begin(), merged.end());
        if (std::abs(std::accumulate(merged.begin(), merged.begin() + a.size(), 0) - std::accumulate(merged.begin() + a.size(), merged.end(), 0)) >= observed_diff) {
            count += 1;
        }
    }
    return static_cast<double>(count) / 10000;
}

double recursive_permutation_test(std::vector<int> data, std::vector<int> a, std::vector<int> b) {
    if (data.size() == 0) {
        return simulate_p_value(a, b);
    } else {
        int element = data.back();
        data.pop_back();
        a.push_back(element);
        double p_value_a = recursive_permutation_test(data, a, b);
        a.pop_back();
        b.push_back(element);
        double p_value_b = recursive_permutation_test(data, a, b);
        b.pop_back();
        return std::max(p_value_a, p_value_b);
    }
}

int main() {
    std::vector<int> data;
    for (int i = 0; i < 20; ++i) {
        data.push_back(std::rand() % 100 + 1);
    }
    std::vector<int> a;
    std::vector<int> b;
    while (true) {
        double p_value = recursive_permutation_test(data, a, b);
        std::cout << p_value << std::endl;
    }
    return 0;
}