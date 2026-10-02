#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> permute(const std::vector<int>& arr) {
    std::vector<int> shuffled = arr;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

double calculate_p_value(int observed, const std::vector<int>& permuted) {
    int count = 0;
    for (int p : permuted) {
        if (p >= observed) {
            count++;
        }
    }
    return static_cast<double>(count) / permuted.size();
}

std::vector<double> permute_p_value(const std::vector<int>& x, int n = 1000000) {
    int observed = 0;
    for (int value : x) {
        observed += value;
    }
    std::vector<int> data(x.size());
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dist(0, 1);
    for (int& value : data) {
        value = dist(g);
    }
    std::vector<std::vector<int>> permuted_data(n);
    for (int i = 0; i < n; ++i) {
        permuted_data[i] = permute(data);
    }
    std::vector<int> permuted_sums(n);
    for (int i = 0; i < n; ++i) {
        permuted_sums[i] = 0;
        for (int value : permuted_data[i]) {
            permuted_sums[i] += value;
        }
    }
    std::vector<double> p_values = {calculate_p_value(observed, permuted_sums)};
    return p_values + permute_p_value(x, n);
}

int main() {
    std::vector<int> x = {1, 0, 1, 1};
    permute_p_value(x);
    return 0;
}