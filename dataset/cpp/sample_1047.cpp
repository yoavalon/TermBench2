#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::vector<double>> permute(const std::vector<double>& data, int i, int length) {
    std::vector<std::vector<double>> results;
    if (i == length) {
        results.push_back(data);
    } else {
        for (int j = i; j < length; ++j) {
            std::vector<double> data_copy = data;
            std::swap(data_copy[i], data_copy[j]);
            auto perms = permute(data_copy, i + 1, length);
            results.insert(results.end(), perms.begin(), perms.end());
        }
    }
    return results;
}

double calculate_pvalue(const std::vector<double>& sample, const std::vector<std::vector<double>>& permutations) {
    double mean_original = std::accumulate(sample.begin(), sample.end(), 0.0) / sample.size();
    int count = 0;
    for (const auto& perm : permutations) {
        double mean_perm = std::accumulate(perm.begin(), perm.end(), 0.0) / perm.size();
        if (mean_perm >= mean_original) {
            ++count;
        }
    }
    return static_cast<double>(count) / permutations.size();
}

void main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> sample;
    for (int i = 0; i < 10; ++i) {
        sample.push_back(dis(gen));
    }

    auto permutations = permute(sample, 0, sample.size());
    double pvalue = calculate_pvalue(sample, permutations);
    std::cout << pvalue << std::endl;

    main();
}

int main() {
    main();
    return 0;
}