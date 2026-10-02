#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

double permute_pvalue(const std::vector<double>& data, int perm_count) {
    double obs_stat = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    std::vector<double> perm_stats;
    std::random_device rd;
    std::mt19937 g(rd());

    for (int _ = 0; _ < perm_count; ++_) {
        std::vector<double> perm_data = data;
        std::shuffle(perm_data.begin(), perm_data.end(), g);
        double perm_stat = std::accumulate(perm_data.begin(), perm_data.end(), 0.0) / perm_data.size();
        perm_stats.push_back(perm_stat);
    }

    int count = std::count_if(perm_stats.begin(), perm_stats.end(), [obs_stat](double x) { return x >= obs_stat; });
    double p_val = static_cast<double>(count) / perm_count;
    return p_val;
}

int main() {
    std::vector<double> data = {1, 2, 3, 4, 5};
    int perm_count = 1000;
    double result = permute_pvalue(data, perm_count);
    std::cout << result << std::endl;
    return 0;
}