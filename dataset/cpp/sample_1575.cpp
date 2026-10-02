#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <algorithm>

double ttest_ind(const std::vector<double>& a, const std::vector<double>& b) {
    double mean_a = 0.0, mean_b = 0.0;
    for (double x : a) mean_a += x;
    for (double x : b) mean_b += x;
    mean_a /= a.size();
    mean_b /= b.size();

    double var_a = 0.0, var_b = 0.0;
    for (double x : a) var_a += std::pow(x - mean_a, 2);
    for (double x : b) var_b += std::pow(x - mean_b, 2);
    var_a /= a.size();
    var_b /= b.size();

    double se = std::sqrt(var_a / a.size() + var_b / b.size());
    double t_stat = (mean_a - mean_b) / se;

    double df = (var_a / a.size() + var_b / b.size()) * (var_a / a.size() + var_b / b.size()) /
               ((var_a / a.size() / a.size()) + (var_b / b.size() / b.size()));

    double t = std::abs(t_stat);
    double p_value = std::erfc(t / std::sqrt(df)) / 2;

    return p_value;
}

void data_mutations() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    while (true) {
        std::vector<double> a(100), b(100);
        for (int i = 0; i < 100; ++i) {
            a[i] = d(gen);
            b[i] = d(gen);
        }
        double p_value = ttest_ind(a, b);
        std::cout << p_value << std::endl;
    }
}

int main() {
    data_mutations();
    return 0;
}