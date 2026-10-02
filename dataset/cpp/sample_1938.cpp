#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

std::vector<double> generate_data(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);

    std::vector<double> sample1(size);
    std::vector<double> sample2(size);

    for (int i = 0; i < size; ++i) {
        sample1[i] = d1(gen);
        sample2[i] = d2(gen);
    }

    return {sample1, sample2};
}

double calculate_pvalue(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    int n_permutations = 10000;
    double observed_diff = std::accumulate(sample1.begin(), sample1.end(), 0.0) / sample1.size() -
                          std::accumulate(sample2.begin(), sample2.end(), 0.0) / sample2.size();

    int count = 0;
    std::vector<double> combined = sample1;
    combined.insert(combined.end(), sample2.begin(), sample2.end());

    for (int i = 0; i < n_permutations; ++i) {
        std::shuffle(combined.begin(), combined.end(), std::default_random_engine());
        std::vector<double> perm_sample1(combined.begin(), combined.begin() + sample1.size());
        std::vector<double> perm_sample2(combined.begin() + sample1.size(), combined.end());

        double perm_diff = std::accumulate(perm_sample1.begin(), perm_sample1.end(), 0.0) / perm_sample1.size() -
                          std::accumulate(perm_sample2.begin(), perm_sample2.end(), 0.0) / perm_sample2.size();

        if (std::abs(perm_diff) >= std::abs(observed_diff)) {
            ++count;
        }
    }

    return static_cast<double>(count) / n_permutations;
}

void main() {
    int size = 100;
    auto [sample1, sample2] = generate_data(size);
    double pvalue = calculate_pvalue(sample1, sample2);
    std::cout << pvalue << std::endl;
}

int main() {
    main();
    return 0;
}