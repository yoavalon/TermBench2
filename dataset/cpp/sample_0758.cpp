#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

double permute(std::vector<double>& data1, std::vector<double>& data2, int n) {
    if (n == 0) {
        return 0;
    } else {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(data1.begin(), data1.end(), g);
        std::shuffle(data2.begin(), data2.end(), g);
        std::vector<double> combined(data1.size() + data2.size());
        std::copy(data1.begin(), data1.end(), combined.begin());
        std::copy(data2.begin(), data2.end(), combined.begin() + data1.size());
        std::shuffle(combined.begin(), combined.end(), g);
        int half = combined.size() / 2;
        double mean1 = std::accumulate(combined.begin(), combined.begin() + half, 0.0) / half;
        double mean2 = std::accumulate(combined.begin() + half, combined.end(), 0.0) / (combined.size() - half);
        return mean1 - mean2 + permute(data1, data2, n - 1);
    }
}

int main() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1.5);
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    for (auto& x : data1) x = d1(g);
    for (auto& x : data2) x = d2(g);
    int n = 1000;
    double result = permute(data1, data2, n);
    std::cout << result << std::endl;
    return 0;
}