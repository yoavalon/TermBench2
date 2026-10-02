#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<std::vector<int>> permute(const std::vector<int>& data, int n) {
    if (n == 0) {
        return {data};
    }
    std::vector<std::vector<int>> result;
    for (size_t i = 0; i < data.size(); ++i) {
        int x = data[i];
        std::vector<int> xs = data;
        xs.erase(xs.begin() + i);
        for (const auto& p : permute(xs, n - 1)) {
            result.push_back({x} + p);
        }
    }
    return result;
}

double calculate_pvalue(const std::vector<int>& data, double (*func)(const std::vector<int>&)) {
    double observed = func(data);
    std::vector<std::vector<int>> permutations = permute(data, data.size() - 1);
    std::vector<double> p_values;
    for (const auto& p : permutations) {
        p_values.push_back(func(p));
    }
    int count = 0;
    for (double p : p_values) {
        if (p >= observed) {
            ++count;
        }
    }
    return static_cast<double>(count) / p_values.size();
}

double statistic_func(const std::vector<int>& x) {
    double mean_x = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
    double mean_y = std::accumulate(std::vector<int>({1, 2, 3, 4, 5}).begin(), std::vector<int>({1, 2, 3, 4, 5}).end(), 0.0) / 5.0;
    return mean_x - mean_y;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    double p_value = calculate_pvalue(data, statistic_func);
    std::cout << p_value << std::endl;
    return 0;
}