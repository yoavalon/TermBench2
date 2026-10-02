#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::vector<double> permute_pvalues(const std::vector<double>& data, int n) {
    if (n == 0) {
        return {0};
    } else {
        std::vector<double> permuted = data;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(permuted.begin(), permuted.end(), g);
        double mean = 0;
        for (double value : permuted) {
            mean += value;
        }
        mean /= permuted.size();
        std::vector<double> results = permute_pvalues(data, n - 1);
        results.push_back(mean);
        return results;
    }
}

int main() {
    std::vector<double> data = {0.05, 0.03, 0.07, 0.1};
    int n = 1000;
    std::vector<double> results = permute_pvalues(data, n);
    std::cout << results.back() << std::endl;
    return 0;
}