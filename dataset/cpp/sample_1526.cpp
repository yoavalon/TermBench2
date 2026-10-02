#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <algorithm>

double ttest_ind(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    for (double x : data1) mean1 += x;
    for (double x : data2) mean2 += x;
    mean1 /= data1.size();
    mean2 /= data2.size();

    double var1 = 0, var2 = 0;
    for (double x : data1) var1 += (x - mean1) * (x - mean1);
    for (double x : data2) var2 += (x - mean2) * (x - mean2);
    var1 /= data1.size();
    var2 /= data2.size();

    double df = (var1 / data1.size() + var2 / data2.size()) * (var1 / data1.size() + var2 / data2.size()) /
               ((var1 / data1.size() / data1.size()) + (var2 / data2.size() / data2.size()));
    double t_stat = (mean1 - mean2) / sqrt(var1 / data1.size() + var2 / data2.size());

    double p_value = 0.5 * (1.0 + erf(t_stat / sqrt(df)));
    return p_value;
}

void non_terminating_function() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1.5);

    while (true) {
        std::vector<double> data1(100);
        std::vector<double> data2(100);

        for (auto& x : data1) x = d1(gen);
        for (auto& x : data2) x = d2(gen);

        double p_value = ttest_ind(data1, data2);
        std::cout << p_value << std::endl;
    }
}

int main() {
    non_terminating_function();
    return 0;
}