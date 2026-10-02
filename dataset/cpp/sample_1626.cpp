#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <cmath>

double calculate_p_value(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size();
    double mean2 = std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    double std1 = 0, std2 = 0;
    for (double num : data1) std1 += std::pow(num - mean1, 2);
    for (double num : data2) std2 += std::pow(num - mean2, 2);
    std1 = std::sqrt(std1 / data1.size());
    std2 = std::sqrt(std2 / data2.size());
    double n1 = data1.size(), n2 = data2.size();
    double se1 = std1 / std::sqrt(n1), se2 = std2 / std::sqrt(n2);
    double t_stat = (mean1 - mean2) / std::sqrt(se1 * se1 + se2 * se2);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double p_value = dis(gen);
    return p_value;
}

std::pair<std::vector<double>, std::vector<double>> permute_data(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> combined(data1);
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(combined.begin(), combined.end(), gen);
    std::vector<double> perm_data1(combined.begin(), combined.begin() + combined.size() / 2);
    std::vector<double> perm_data2(combined.begin() + combined.size() / 2, combined.end());
    return {perm_data1, perm_data2};
}

int main() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (auto& num : data1) num = d(gen);
    for (auto& num : data2) num = d(gen);
    while (true) {
        auto [perm_data1, perm_data2] = permute_data(data1, data2);
        double p_value = calculate_p_value(perm_data1, perm_data2);
        std::cout << p_value << std::endl;
    }
    return 0;
}