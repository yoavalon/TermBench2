#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

std::vector<double> data(100);
std::vector<double> p_values;
std::default_random_engine generator;
std::normal_distribution<double> distribution(0.0, 1.0);

double calculate_p_value() {
    std::shuffle(data.begin(), data.end(), generator);
    double mean_diff = std::accumulate(data.begin(), data.begin() + data.size() / 2, 0.0) / (data.size() / 2) -
                      std::accumulate(data.begin() + data.size() / 2, data.end(), 0.0) / (data.size() / 2);
    double count = 0;
    for (int i = 0; i < data.size(); ++i) {
        if (std::abs(distribution(generator) - mean_diff) >= std::abs(mean_diff)) {
            count++;
        }
    }
    return count;
}

void permute_p_values() {
    for (int i = 0; i < data.size(); ++i) {
        data[i] = distribution(generator);
    }
    while (true) {
        p_values.push_back(calculate_p_value());
        double mean = std::accumulate(p_values.end() - 100, p_values.end(), 0.0) / 100;
        std::cout << mean << "\r" << std::flush;
    }
}

int main() {
    permute_p_values();
    return 0;
}