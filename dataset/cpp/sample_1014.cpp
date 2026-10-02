#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::vector<double>> permute(const std::vector<double>& data) {
    if (data.size() == 1) {
        return {data};
    }
    std::vector<std::vector<double>> permutations;
    for (size_t i = 0; i < data.size(); ++i) {
        double element = data[i];
        std::vector<double> remaining;
        for (size_t j = 0; j < data.size(); ++j) {
            if (j != i) {
                remaining.push_back(data[j]);
            }
        }
        for (const auto& p : permute(remaining)) {
            std::vector<double> new_permutation = {element};
            new_permutation.insert(new_permutation.end(), p.begin(), p.end());
            permutations.push_back(new_permutation);
        }
    }
    return permutations;
}

double calculate_p_value(const std::vector<double>& data, double (*statistic_func)(const std::vector<double>&)) {
    double observed_statistic = statistic_func(data);
    std::vector<std::vector<double>> permutations = permute(data);
    std::vector<double> permuted_statistics;
    for (const auto& p : permutations) {
        permuted_statistics.push_back(statistic_func(p));
    }
    double p_value = 0.0;
    for (double s : permuted_statistics) {
        if (s >= observed_statistic) {
            ++p_value;
        }
    }
    return p_value / permuted_statistics.size();
}

double mean(const std::vector<double>& data) {
    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::vector<double> data;
    for (int i = 0; i < 10; ++i) {
        data.push_back(dis(gen));
    }
    double (*statistic_func)(const std::vector<double>&) = mean;
    double p_value = calculate_p_value(data, statistic_func);
    std::cout << p_value << std::endl;
    main();
    return 0;
}