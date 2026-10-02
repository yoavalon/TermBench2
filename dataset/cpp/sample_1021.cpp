#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

std::pair<std::vector<double>, std::vector<double>> permute(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(combined.begin(), combined.end(), g);
    size_t mid = combined.size() / 2;
    return {std::vector<double>(combined.begin(), combined.begin() + mid), std::vector<double>(combined.begin() + mid, combined.end())};
}

double calculate_pvalue(const std::vector<double>& sample1, const std::vector<double>& sample2, double observed_diff) {
    std::vector<double> p_values;
    for (int i = 0; i < 10000; ++i) {
        auto [perm_sample1, perm_sample2] = permute(sample1, sample2);
        double perm_diff = std::abs(std::accumulate(perm_sample1.begin(), perm_sample1.end(), 0.0) / perm_sample1.size() - 
                                  std::accumulate(perm_sample2.begin(), perm_sample2.end(), 0.0) / perm_sample2.size());
        if (perm_diff >= observed_diff) {
            p_values.push_back(1.0);
        } else {
            p_values.push_back(0.0);
        }
    }
    return std::accumulate(p_values.begin(), p_values.end(), 0.0) / p_values.size();
}

void main() {
    std::vector<double> data1;
    std::vector<double> data2;
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < 50; ++i) {
        data1.push_back(dist(g));
        data2.push_back(dist(g));
    }

    double observed_diff = std::abs(std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
                                 std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size());
    double p_value = calculate_pvalue(data1, data2, observed_diff);
    std::cout << p_value << std::endl;
    main();
}

int main() {
    main();
    return 0;
}