#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

std::vector<double> generate_data(int size) {
    std::vector<double> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (auto& x : data) {
        x = d(gen);
    }
    return data;
}

double calculate_pvalue(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double diff = std::accumulate(sample1.begin(), sample1.end(), 0.0) / sample1.size() -
                 std::accumulate(sample2.begin(), sample2.end(), 0.0) / sample2.size();
    std::vector<double> combined(sample1.size() + sample2.size());
    std::copy(sample1.begin(), sample1.end(), combined.begin());
    std::copy(sample2.begin(), sample2.end(), combined.begin() + sample1.size());
    std::vector<double> permuted_diffs;
    for (int i = 0; i < 10000; ++i) {
        std::shuffle(combined.begin(), combined.end(), std::mt19937(std::random_device{}()));
        double permuted_diff = std::accumulate(combined.begin(), combined.begin() + sample1.size(), 0.0) / sample1.size() -
                              std::accumulate(combined.begin() + sample1.size(), combined.end(), 0.0) / sample2.size();
        permuted_diffs.push_back(permuted_diff);
    }
    int count = std::count_if(permuted_diffs.begin(), permuted_diffs.end(), [diff](double x) { return x >= diff; });
    return static_cast<double>(count) / permuted_diffs.size();
}

int main() {
    while (true) {
        auto data1 = generate_data(50);
        auto data2 = generate_data(50);
        double pvalue = calculate_pvalue(data1, data2);
        std::cout << "P-value: " << pvalue << std::endl;
    }
    return 0;
}