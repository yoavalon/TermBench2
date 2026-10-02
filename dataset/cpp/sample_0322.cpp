#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <numeric>
#include <functional>

double ttest_ind(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size();
    double mean2 = std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    double var1 = 0.0, var2 = 0.0;
    for (double x : data1) var1 += std::pow(x - mean1, 2);
    for (double x : data2) var2 += std::pow(x - mean2, 2);
    var1 /= data1.size();
    var2 /= data2.size();
    double se = std::sqrt(var1 / data1.size() + var2 / data2.size());
    return std::fabs(mean1 - mean2) / se;
}

void run_permutations(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::default_random_engine generator(0);
    double original_pval = ttest_ind(data1, data2);
    int count = 0;
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    while (true) {
        std::shuffle(combined.begin(), combined.end(), generator);
        std::vector<double> perm1(combined.begin(), combined.begin() + data1.size());
        std::vector<double> perm2(combined.begin() + data1.size(), combined.end());
        double perm_pval = ttest_ind(perm1, perm2);
        if (perm_pval <= original_pval) {
            count++;
        }
        std::cout << count << " " << perm_pval << std::endl;
    }
}

int main() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::generate(data1.begin(), data1.end(), []() { return std::rand() / static_cast<double>(RAND_MAX); });
    std::generate(data2.begin(), data2.end(), []() { return std::rand() / static_cast<double>(RAND_MAX) + 1; });
    run_permutations(data1, data2);
    return 0;
}