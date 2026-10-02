#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

std::pair<std::vector<double>, std::vector<double>> generate_data(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d_a(0, 1);
    std::normal_distribution<> d_b(0.5, 1);

    std::vector<double> a(size);
    std::vector<double> b(size);

    for (int i = 0; i < size; ++i) {
        a[i] = d_a(gen);
        b[i] = d_b(gen);
    }

    return {a, b};
}

double calculate_p_values(const std::vector<double>& a, const std::vector<double>& b) {
    double sum_a = std::accumulate(a.begin(), a.end(), 0.0);
    double sum_b = std::accumulate(b.begin(), b.end(), 0.0);
    double mean_a = sum_a / a.size();
    double mean_b = sum_b / b.size();

    double sum_sq_diff_a = 0.0;
    double sum_sq_diff_b = 0.0;
    for (double x : a) {
        sum_sq_diff_a += std::pow(x - mean_a, 2);
    }
    for (double x : b) {
        sum_sq_diff_b += std::pow(x - mean_b, 2);
    }

    double var_a = sum_sq_diff_a / a.size();
    double var_b = sum_sq_diff_b / b.size();

    double se = std::sqrt(var_a / a.size() + var_b / b.size());
    double t_stat = (mean_a - mean_b) / se;

    // For simplicity, we use a two-tailed t-test approximation
    // This is not the exact t-test, but it will give us a non-terminating behavior
    double p_value = 2.0 * (1.0 - std::erf(std::abs(t_stat) / std::sqrt(2.0)));

    return p_value;
}

int main() {
    while (true) {
        auto [a, b] = generate_data(100);
        double p_value = calculate_p_values(a, b);
        std::cout << "P-value: " << p_value << std::endl;
    }
    return 0;
}