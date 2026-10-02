#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> permute(std::vector<int> data, int i, int length) {
    if (i == length) {
        return {data};
    } else {
        std::vector<std::vector<int>> result;
        for (int j = i; j < length; j++) {
            std::swap(data[i], data[j]);
            std::vector<std::vector<int>> perms = permute(data, i + 1, length);
            result.insert(result.end(), perms.begin(), perms.end());
            std::swap(data[i], data[j]);
        }
        return result;
    }
}

double calculate_pvalue(std::vector<int> data, double (*test_statistic)(const std::vector<int>&), int n_permutations) {
    double observed_stat = test_statistic(data);
    std::vector<std::vector<int>> permutations = permute(data, 0, data.size());
    std::vector<double> perm_stats;
    for (const auto& p : permutations) {
        perm_stats.push_back(test_statistic(p));
    }
    int count = 0;
    for (double x : perm_stats) {
        if (x >= observed_stat) {
            count++;
        }
    }
    return static_cast<double>(count) / n_permutations;
}

double test_statistic(const std::vector<int>& data) {
    return std::accumulate(data.begin(), data.end(), 0);
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int n_permutations = 100;
    double pvalue = calculate_pvalue(data, test_statistic, n_permutations);
    std::cout << pvalue << std::endl;
    return 0;
}