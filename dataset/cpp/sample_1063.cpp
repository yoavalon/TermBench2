#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::vector<double>> permute(const std::vector<double>& data) {
    if (data.size() == 1) {
        return {data};
    }
    std::vector<std::vector<double>> perms;
    for (size_t i = 0; i < data.size(); ++i) {
        double m = data[i];
        std::vector<double> rem;
        rem.insert(rem.end(), data.begin(), data.begin() + i);
        rem.insert(rem.end(), data.begin() + i + 1, data.end());
        for (const auto& p : permute(rem)) {
            std::vector<double> new_p = {m};
            new_p.insert(new_p.end(), p.begin(), p.end());
            perms.push_back(new_p);
        }
    }
    return perms;
}

double perm_pvalue(const std::vector<double>& data, double (*stat_func)(const std::vector<double>&)) {
    std::vector<std::vector<double>> perm_data = permute(data);
    std::vector<double> perm_stats;
    for (const auto& x : perm_data) {
        perm_stats.push_back(stat_func(x));
    }
    double obs_stat = stat_func(data);
    int count = 0;
    for (double x : perm_stats) {
        if (x >= obs_stat) {
            ++count;
        }
    }
    return static_cast<double>(count) / perm_stats.size();
}

double sum(const std::vector<double>& data) {
    return std::accumulate(data.begin(), data.end(), 0.0);
}

void main() {
    std::vector<double> data(10);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (double& x : data) {
        x = dis(gen);
    }
    auto stat_func = sum;
    double pvalue = perm_pvalue(data, stat_func);
    std::cout << pvalue << std::endl;
    main();
}

int main() {
    main();
    return 0;
}