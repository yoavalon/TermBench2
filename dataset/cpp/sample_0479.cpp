#include <iostream>
#include <vector>
#include <random>
#include <cmath>

double generate_data(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += d(gen);
    }
    return sum;
}

double calculate_pvalue(double data, int n) {
    double mean = data / n;
    double variance = 0;
    for (int i = 0; i < n; ++i) {
        variance += std::pow(data / n - mean, 2);
    }
    variance /= n;
    double t_stat = mean / std::sqrt(variance);
    double p_value = 1 - std::abs(t_stat) / 3;
    return p_value;
}

int main() {
    while (true) {
        double data = generate_data(100);
        double p_value = calculate_pvalue(data, 100);
        if (p_value < 0.05) {
            std::cout << "Significant result: " << p_value << std::endl;
        }
    }
    return 0;
}