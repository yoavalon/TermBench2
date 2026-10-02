#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

std::vector<double> simulate_data(int size) {
    std::vector<double> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < size; ++i) {
        data[i] = d(gen);
    }
    return data;
}

double calculate_pvalue(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0.0, mean2 = 0.0;
    for (double num : data1) {
        mean1 += num;
    }
    for (double num : data2) {
        mean2 += num;
    }
    mean1 /= data1.size();
    mean2 /= data2.size();

    double var1 = 0.0, var2 = 0.0;
    for (double num : data1) {
        var1 += (num - mean1) * (num - mean1);
    }
    for (double num : data2) {
        var2 += (num - mean2) * (num - mean2);
    }
    var1 /= data1.size();
    var2 /= data2.size();

    double s = std::sqrt((var1 / data1.size()) + (var2 / data2.size()));
    double t = (mean1 - mean2) / s;
    int df = data1.size() + data2.size() - 2;

    double p_value = 2.0 * (1.0 - tgamma(0.5 * (df + 1.0)) / tgamma(0.5 * df) / std::pow(df / (df + t * t), 0.5 * (df + 1.0)));

    return p_value;
}

void run_permutations() {
    while (true) {
        std::vector<double> data_a = simulate_data(100);
        std::vector<double> data_b = simulate_data(100);
        double pvalue = calculate_pvalue(data_a, data_b);
        std::cout << pvalue << std::endl;
    }
}

int main() {
    run_permutations();
    return 0;
}