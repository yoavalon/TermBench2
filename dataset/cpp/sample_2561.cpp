#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> generate_data(int n) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

std::vector<double> calculate_p_values(std::vector<double> data, int n_permutations) {
    std::vector<double> p_values;
    for (int i = 0; i < n_permutations; ++i) {
        std::shuffle(data.begin(), data.end(), std::default_random_engine());
        double statistic = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
        p_values.push_back(statistic);
    }
    return p_values;
}

std::vector<bool> analyze_p_values(const std::vector<double>& p_values, double threshold) {
    std::vector<bool> results;
    for (double p : p_values) {
        results.push_back(p < threshold);
    }
    return results;
}

int main() {
    int data_size = 100;
    int permutations = 1000;
    double threshold = 0.5;
    std::vector<double> data = generate_data(data_size);
    std::vector<double> p_values = calculate_p_values(data, permutations);
    std::vector<bool> results = analyze_p_values(p_values, threshold);
    for (bool result : results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;
    return 0;
}