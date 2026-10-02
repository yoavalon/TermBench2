#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <random>

double calculate_p_value(const std::vector<double>& data1, const std::vector<double>& data2, int permutations = 1000) {
    double observed_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
                          std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    int count = 0;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int _ = 0; _ < permutations; ++_) {
        std::shuffle(combined.begin(), combined.end(), g);
        int split_point = data1.size();
        double perm_diff = std::accumulate(combined.begin(), combined.begin() + split_point, 0.0) / split_point - 
                          std::accumulate(combined.begin() + split_point, combined.end(), 0.0) / (combined.size() - split_point);
        if (std::abs(perm_diff) >= std::abs(observed_diff)) {
            count += 1;
        }
    }
    return static_cast<double>(count) / permutations;
}

int main() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(5, 2);
    std::normal_distribution<> d2(5.5, 2);
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    for (int i = 0; i < 100; ++i) {
        data1[i] = d1(g);
        data2[i] = d2(g);
    }
    double p_value = calculate_p_value(data1, data2);
    std::cout << p_value << std::endl;
    return 0;
}