#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

std::vector<double> generate_data(int size) {
    std::vector<double> data1(size);
    std::vector<double> data2(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1.5);

    for (int i = 0; i < size; ++i) {
        data1[i] = d1(gen);
        data2[i] = d2(gen);
    }
    return {data1, data2};
}

double t_test(const std::vector<double>& data1, const std::vector<double>& data2) {
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

    double s pooled = std::sqrt((var1 + var2) / 2);
    double t = (mean1 - mean2) / (s_pooled * std::sqrt(1.0 / data1.size() + 1.0 / data2.size()));
    return t;
}

std::vector<double> calculate_p_values(const std::vector<double>& data1, const std::vector<double>& data2, int iterations) {
    std::vector<double> p_values;
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < iterations; ++i) {
        std::vector<double> shuffled_data1 = data1;
        std::vector<double> shuffled_data2 = data2;
        std::shuffle(shuffled_data1.begin(), shuffled_data1.end(), gen);
        std::shuffle(shuffled_data2.begin(), shuffled_data2.end(), gen);

        double t = t_test(shuffled_data1, shuffled_data2);
        double p_value = 2 * (1 - tdist(t, data1.size() + data2.size() - 2));
        p_values.push_back(p_value);
    }
    return p_values;
}

double tdist(double t, int df) {
    // Approximation of the Student's t-distribution CDF
    return 0.5 * (1 + std::erf(t / std::sqrt(2 * (1 + df / (2 * df * df * df)))));
}

void main() {
    auto [data1, data2] = generate_data(100);
    std::vector<double> p_values = calculate_p_values(data1, data2, 1000);
    double mean_p_value = 0;
    for (double p : p_values) mean_p_value += p;
    mean_p_value /= p_values.size();
    std::cout << mean_p_value << std::endl;
}

int main() {
    main();
    return 0;
}