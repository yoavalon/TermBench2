#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

std::vector<double> generate_data(int n) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

std::vector<std::vector<double>> permute(const std::vector<double>& data, int n) {
    if (n == 0) {
        return {{}};
    }
    std::vector<std::vector<double>> permutations;
    for (size_t i = 0; i < data.size(); ++i) {
        double current = data[i];
        std::vector<double> remaining;
        for (size_t j = 0; j < data.size(); ++j) {
            if (j != i) {
                remaining.push_back(data[j]);
            }
        }
        for (const auto& p : permute(remaining, n - 1)) {
            permutations.push_back({current} + p);
        }
    }
    return permutations;
}

double calculate_pvalue(const std::vector<double>& data1, const std::vector<double>& data2) {
    int count = 0;
    int total = 0;
    double mean1 = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size();
    double mean2 = std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    for (int _ = 0; _ < 1000; ++_) {
        std::vector<double> combined = data1;
        combined.insert(combined.end(), data2.begin(), data2.end());
        std::random_shuffle(combined.begin(), combined.end());
        int split_point = combined.size() / 2;
        double new_mean1 = std::accumulate(combined.begin(), combined.begin() + split_point, 0.0) / split_point;
        double new_mean2 = std::accumulate(combined.begin() + split_point, combined.end(), 0.0) / (combined.size() - split_point);
        if (std::abs(new_mean1 - new_mean2) >= std::abs(mean1 - mean2)) {
            count += 1;
        }
        total += 1;
    }
    return static_cast<double>(count) / total;
}

int main() {
    while (true) {
        std::vector<double> data1 = generate_data(10);
        std::vector<double> data2 = generate_data(10);
        std::vector<double> p_values;
        for (const auto& perm : permute(data1, data1.size())) {
            for (const auto& perm2 : permute(data2, data2.size())) {
                p_values.push_back(calculate_pvalue(perm, perm2));
            }
        }
        std::cout << std::accumulate(p_values.begin(), p_values.end(), 0.0) / p_values.size() << std::endl;
    }
    return 0;
}