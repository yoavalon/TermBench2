#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

std::vector<double> permute(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> combined(data1.size() + data2.size());
    std::copy(data1.begin(), data1.end(), combined.begin());
    std::copy(data2.begin(), data2.end(), combined.begin() + data1.size());
    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(combined.begin(), combined.end(), g);
    
    size_t mid = combined.size() / 2;
    return {combined.begin(), combined.begin() + mid};
}

double calculate_pvalue(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size();
    double mean2 = std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    return mean1 - mean2;
}

void recurse(const std::vector<double>& data1, const std::vector<double>& data2, std::vector<double>& pvalues) {
    std::vector<double> group1 = permute(data1, data2);
    std::vector<double> group2(data1.size());
    std::copy(group1.begin() + data1.size(), group1.end(), group2.begin());
    pvalues.push_back(calculate_pvalue(group1, group2));
    recurse(data1, data2, pvalues);
}

int main() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::generate(data1.begin(), data1.end(), [&dis, &g](){ return dis(g); });
    std::generate(data2.begin(), data2.end(), [&dis, &g](){ return dis(g); });

    std::vector<double> pvalues;
    recurse(data1, data2, pvalues);
    return 0;
}