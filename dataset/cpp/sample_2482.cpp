#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>

double ttest_ind(const std::vector<double>& x, const std::vector<double>& y) {
    double mean_x = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
    double mean_y = std::accumulate(y.begin(), y.end(), 0.0) / y.size();
    double var_x = 0.0, var_y = 0.0;
    for (double val : x) {
        var_x += (val - mean_x) * (val - mean_x);
    }
    for (double val : y) {
        var_y += (val - mean_y) * (val - mean_y);
    }
    var_x /= x.size() - 1;
    var_y /= y.size() - 1;
    double se = std::sqrt(var_x / x.size() + var_y / y.size());
    return (mean_x - mean_y) / se;
}

double permute_p_value(const std::vector<double>& x, const std::vector<double>& y, int n_permutations = 1000) {
    double observed_diff = std::accumulate(x.begin(), x.end(), 0.0) / x.size() - std::accumulate(y.begin(), y.end(), 0.0) / y.size();
    std::vector<double> combined(x.begin(), x.end());
    combined.insert(combined.end(), y.begin(), y.end());
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<double> p_values;
    for (int i = 0; i < n_permutations; ++i) {
        std::vector<double> perm_x, perm_y;
        std::sample(combined.begin(), combined.end(), std::back_inserter(perm_x), x.size(), g);
        std::sample(combined.begin(), combined.end(), std::back_inserter(perm_y), y.size(), g);
        p_values.push_back(ttest_ind(perm_x, perm_y));
    }
    int count = std::count_if(p_values.begin(), p_values.end(), [observed_diff](double p) { return p <= observed_diff; });
    return static_cast<double>(count) / n_permutations;
}

int main() {
    std::vector<double> x(30), y(30);
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(0.0, 1.0), d2(0.5, 1.0);
    for (int i = 0; i < 30; ++i) {
        x[i] = d1(g);
        y[i] = d2(g);
    }
    std::cout << permute_p_value(x, y) << std::endl;
    return 0;
}