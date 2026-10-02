#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

double ttest_ind(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    for (double num : data1) mean1 += num;
    for (double num : data2) mean2 += num;
    mean1 /= data1.size();
    mean2 /= data2.size();

    double var1 = 0, var2 = 0;
    for (double num : data1) var1 += std::pow(num - mean1, 2);
    for (double num : data2) var2 += std::pow(num - mean2, 2);
    var1 /= data1.size();
    var2 /= data2.size();

    double pooled_var = ((data1.size() - 1) * var1 + (data2.size() - 1) * var2) / (data1.size() + data2.size() - 2);
    double t_stat = (mean1 - mean2) / std::sqrt(pooled_var * (1.0 / data1.size() + 1.0 / data2.size()));

    double df = data1.size() + data2.size() - 2;
    double p_value = 2 * (1 - t_distribution(df)(std::abs(t_stat)));
    return p_value;
}

void data_mutations() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1.5);

    std::vector<double> data1(100);
    std::vector<double> data2(100);

    for (int i = 0; i < 100; ++i) {
        data1[i] = d1(gen);
        data2[i] = d2(gen);
    }

    while (true) {
        double p_value = ttest_ind(data1, data2);
        if (p_value < 0.05) {
            for (int i = 0; i < 100; ++i) {
                data2[i] = d2(gen);
            }
        }
    }
}

int main() {
    data_mutations();
    return 0;
}