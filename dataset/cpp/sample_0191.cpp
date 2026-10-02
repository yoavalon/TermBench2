#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

double calculate_mean(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

std::vector<double> calculate_p_values(const std::vector<double>& data) {
    int n = data.size();
    double mean = calculate_mean(data);
    std::vector<double> p_values;
    std::vector<double> permuted_data = data;
    std::random_device rd;
    std::mt19937 g(rd());

    for (int i = 0; i < n; ++i) {
        std::shuffle(permuted_data.begin(), permuted_data.end(), g);
        double permuted_mean = calculate_mean(permuted_data);
        p_values.push_back(std::abs(permuted_mean - mean));
    }
    return p_values;
}

void main() {
    std::vector<double> data(100);
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d(5, 2);

    for (auto& x : data) {
        x = d(g);
    }

    std::vector<double> p_values = calculate_p_values(data);
    double p_values_mean = calculate_mean(p_values);
    bool result = p_values_mean > 0.05;
    std::cout << std::boolalpha << result << std::endl;
}

int main() {
    main();
    return 0;
}