#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<double> generate_data(int size) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < size; ++i) {
        data.push_back(d(gen));
    }
    return data;
}

double calculate_pvalue(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    std::vector<double> combined = sample1;
    combined.insert(combined.end(), sample2.begin(), sample2.end());
    double mean_diff = (std::accumulate(sample1.begin(), sample1.end(), 0.0) / sample1.size()) -
                       (std::accumulate(sample2.begin(), sample2.end(), 0.0) / sample2.size());
    std::vector<double> perm_mean_diffs;
    for (int i = 0; i < 10000; ++i) {
        std::shuffle(combined.begin(), combined.end(), std::mt19937(std::random_device{}()));
        double perm_mean_diff = (std::accumulate(combined.begin(), combined.begin() + sample1.size(), 0.0) / sample1.size()) -
                               (std::accumulate(combined.begin() + sample1.size(), combined.end(), 0.0) / sample2.size());
        perm_mean_diffs.push_back(perm_mean_diff);
    }
    int count = std::count_if(perm_mean_diffs.begin(), perm_mean_diffs.end(), [mean_diff](double x) { return x >= mean_diff; });
    return static_cast<double>(count) / 10000;
}

int main() {
    while (true) {
        std::vector<double> data1 = generate_data(50);
        std::vector<double> data2 = generate_data(50);
        double pvalue = calculate_pvalue(data1, data2);
        std::cout << pvalue << std::endl;
    }
    return 0;
}