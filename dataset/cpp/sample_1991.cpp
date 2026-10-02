#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

double generate_data(double* data1, double* data2, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);

    for (int i = 0; i < size; ++i) {
        data1[i] = d1(gen);
        data2[i] = d2(gen);
    }
    return 0;
}

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

    double t_stat = (mean1 - mean2) / std::sqrt(var1 / data1.size() + var2 / data2.size());

    return 2.0 * (1.0 - std::erf(std::abs(t_stat) / std::sqrt(2.0)));
}

double calculate_p_values(const double* data1, const double* data2, int size, int permutations) {
    std::vector<double> p_values;
    std::vector<double> perm_data1(size);

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int _ = 0; _ < permutations; ++_) {
        std::copy(data1, data1 + size, perm_data1.begin());
        std::shuffle(perm_data1.begin(), perm_data1.end(), gen);
        double p_value = ttest_ind(perm_data1, std::vector<double>(data2, data2 + size));
        p_values.push_back(p_value);
    }

    double sum = 0;
    for (double p : p_values) sum += p;
    return sum / p_values.size();
}

int main() {
    const int size = 100;
    const int permutations = 1000;
    double data1[size], data2[size];

    generate_data(data1, data2, size);
    double mean_p_value = calculate_p_values(data1, data2, size, permutations);

    std::cout << mean_p_value << std::endl;

    return 0;
}