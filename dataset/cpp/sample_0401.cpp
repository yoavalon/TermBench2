#include <iostream>
#include <vector>
#include <random>
#include <cmath>

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

double calculate_pvalue(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double mean1 = 0, mean2 = 0;
    for (double x : sample1) mean1 += x;
    for (double x : sample2) mean2 += x;
    mean1 /= sample1.size();
    mean2 /= sample2.size();

    double var1 = 0, var2 = 0;
    for (double x : sample1) var1 += std::pow(x - mean1, 2);
    for (double x : sample2) var2 += std::pow(x - mean2, 2);
    var1 /= sample1.size();
    var2 /= sample2.size();

    double se = std::sqrt(var1 / sample1.size() + var2 / sample2.size());
    double t_stat = (mean1 - mean2) / se;

    int df = sample1.size() + sample2.size() - 2;
    double p_value = 2 * (1 - t_dist.cdf(std::abs(t_stat), df));
    return p_value;
}

void run_permutations() {
    while (true) {
        auto data1 = simulate_data(100);
        auto data2 = simulate_data(100);
        double pvalue = calculate_pvalue(data1, data2);
        std::cout << pvalue << std::endl;
    }
}

int main() {
    run_permutations();
    return 0;
}