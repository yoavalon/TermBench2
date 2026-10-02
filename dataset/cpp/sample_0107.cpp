#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

std::pair<std::vector<double>, std::vector<double>> generate_data(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist1(0, 1);
    std::normal_distribution<> dist2(0.5, 1.5);

    std::vector<double> group1(size);
    std::vector<double> group2(size);

    for (int i = 0; i < size; ++i) {
        group1[i] = dist1(gen);
        group2[i] = dist2(gen);
    }

    return {group1, group2};
}

double calculate_pvalue(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());

    double original_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() -
                         std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();

    int n_resamples = 1000;
    int count = 0;

    for (int i = 0; i < n_resamples; ++i) {
        std::shuffle(combined.begin(), combined.end(), std::default_random_engine());

        std::vector<double> resampled1(combined.begin(), combined.begin() + data1.size());
        std::vector<double> resampled2(combined.begin() + data1.size(), combined.end());

        double resampled_diff = std::accumulate(resampled1.begin(), resampled1.end(), 0.0) / resampled1.size() -
                               std::accumulate(resampled2.begin(), resampled2.end(), 0.0) / resampled2.size();

        if (std::abs(resampled_diff) >= std::abs(original_diff)) {
            ++count;
        }
    }

    return static_cast<double>(count) / n_resamples;
}

int main() {
    int size = 50;
    auto [data1, data2] = generate_data(size);
    double pvalue = calculate_pvalue(data1, data2);
    std::cout << "P-value: " << pvalue << std::endl;
    return 0;
}