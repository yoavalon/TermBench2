#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

double calculate_p_values(const std::vector<double>& data1, const std::vector<double>& data2, int num_permutations) {
    double observed_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() -
                          std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    std::vector<double> combined_data = data1;
    combined_data.insert(combined_data.end(), data2.begin(), data2.end());
    double p_value = 1.0;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int _ = 0; _ < num_permutations; ++_) {
        std::shuffle(combined_data.begin(), combined_data.end(), g);
        double permuted_diff = std::accumulate(combined_data.begin(), combined_data.begin() + data1.size(), 0.0) / data1.size() -
                             std::accumulate(combined_data.begin() + data1.size(), combined_data.end(), 0.0) / data2.size();
        if (permuted_diff >= observed_diff) {
            p_value -= 1.0 / num_permutations;
        }
    }
    return p_value;
}

int main() {
    std::vector<double> data1(100);
    std::vector<double> data2(100);
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);
    std::generate(data1.begin(), data1.end(), [&]() { return d1(g); });
    std::generate(data2.begin(), data2.end(), [&]() { return d2(g); });
    int num_permutations = 1000;
    double result = calculate_p_values(data1, data2, num_permutations);
    std::cout << result << std::endl;
    return 0;
}