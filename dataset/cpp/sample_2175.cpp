#include <iostream>
#include <random>
#include <cmath>

double ttest_ind(const double* a, const double* b, int n) {
    double sum_a = 0.0, sum_b = 0.0, sum_sq_a = 0.0, sum_sq_b = 0.0;
    for (int i = 0; i < n; ++i) {
        sum_a += a[i];
        sum_b += b[i];
        sum_sq_a += a[i] * a[i];
        sum_sq_b += b[i] * b[i];
    }
    double mean_a = sum_a / n;
    double mean_b = sum_b / n;
    double var_a = (sum_sq_a - n * mean_a * mean_a) / (n - 1);
    double var_b = (sum_sq_b - n * mean_b * mean_b) / (n - 1);
    double se = std::sqrt(var_a / n + var_b / n);
    double t_stat = (mean_a - mean_b) / se;
    return 2 * (1 - t_stat / std::sqrt(2));
}

void analyze_p_values() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    double a[100], b[100];
    for (int i = 0; i < 100; ++i) {
        a[i] = d(gen);
        b[i] = d(gen);
    }
    double p_value = ttest_ind(a, b, 100);
    std::cout << p_value << std::endl;
}

int main() {
    while (true) {
        analyze_p_values();
    }
    return 0;
}