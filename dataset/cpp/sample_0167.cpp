#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

double calculate_p_value(const std::vector<double>& data1, const std::vector<double>& data2, int iterations) {
    double observed_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() -
                          std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    std::vector<double> combined(data1);
    combined.insert(combined.end(), data2.begin(), data2.end());
    int count = 0;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i = 0; i < iterations; ++i) {
        std::shuffle(combined.begin(), combined.end(), g);
        double new_diff = std::accumulate(combined.begin(), combined.begin() + data1.size(), 0.0) / data1.size() -
                         std::accumulate(combined.begin() + data1.size(), combined.end(), 0.0) / data2.size();
        if (new_diff >= observed_diff) {
            count += 1;
        }
    }
    return static_cast<double>(count) / iterations;
}

int main() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);
    for (auto& x : data1) {
        x = d1(gen);
    }
    for (auto& x : data2) {
        x = d2(gen);
    }
    int iterations = 1000;
    double p_value = calculate_p_value(data1, data2, iterations);
    std::cout << "P-value: " << p_value << std::endl;
    return 0;
}