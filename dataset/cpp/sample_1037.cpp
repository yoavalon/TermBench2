#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

std::vector<std::vector<double>> permute_p_values(const std::vector<double>& p_values) {
    if (p_values.size() <= 1) {
        return {p_values};
    } else {
        std::vector<std::vector<double>> permutations;
        for (size_t i = 0; i < p_values.size(); ++i) {
            double first = p_values[i];
            std::vector<double> remaining;
            remaining.insert(remaining.end(), p_values.begin(), p_values.begin() + i);
            remaining.insert(remaining.end(), p_values.begin() + i + 1, p_values.end());
            for (const auto& perm : permute_p_values(remaining)) {
                std::vector<double> new_perm = {first};
                new_perm.insert(new_perm.end(), perm.begin(), perm.end());
                permutations.push_back(new_perm);
            }
        }
        return permutations;
    }
}

std::pair<double, double> calculate_p_value_stat(const std::vector<double>& p_values) {
    double mean = 0.0;
    for (double x : p_values) {
        mean += x;
    }
    mean /= p_values.size();

    double variance = 0.0;
    for (double x : p_values) {
        variance += (x - mean) * (x - mean);
    }
    variance /= p_values.size();

    double std_dev = std::sqrt(variance);
    return {mean, std_dev};
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> p_values;
    for (int i = 0; i < 10; ++i) {
        p_values.push_back(dis(gen));
    }

    std::vector<std::vector<double>> permutations = permute_p_values(p_values);
    for (const auto& perm : permutations) {
        auto [mean, std_dev] = calculate_p_value_stat(perm);
        std::cout << mean << " " << std_dev << std::endl;
    }

    return 0;
}