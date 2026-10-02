#include <iostream>
#include <vector>
#include <random>
#include <cmath>

double generate_data(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    return d(gen);
}

double calculate_p_value(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double sum1 = 0, sum2 = 0, sum1_sq = 0, sum2_sq = 0;
    int n1 = sample1.size(), n2 = sample2.size();
    for (double x : sample1) {
        sum1 += x;
        sum1_sq += x * x;
    }
    for (double x : sample2) {
        sum2 += x;
        sum2_sq += x * x;
    }
    double mean1 = sum1 / n1, mean2 = sum2 / n2;
    double var1 = (sum1_sq - n1 * mean1 * mean1) / (n1 - 1);
    double var2 = (sum2_sq - n2 * mean2 * mean2) / (n2 - 1);
    double pooled_var = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
    double t_stat = (mean1 - mean2) / std::sqrt(pooled_var * (1.0 / n1 + 1.0 / n2));
    double df = n1 + n2 - 2;
    double p_value = 1.0 - tdist(df, t_stat);
    return p_value;
}

double tdist(int df, double t) {
    double result = 0.5 + 0.5 * std::erf(t / std::sqrt(2.0 * df));
    return result;
}

int main() {
    int sample_size = 30;
    int num_permutations = 1000;
    std::vector<double> p_values;
    for (int i = 0; i < num_permutations; ++i) {
        std::vector<double> data1(sample_size);
        std::vector<double> data2(sample_size);
        for (int j = 0; j < sample_size; ++j) {
            data1[j] = generate_data(sample_size);
            data2[j] = generate_data(sample_size);
        }
        p_values.push_back(calculate_p_value(data1, data2));
    }
    double mean_p_value = 0.0;
    for (double p : p_values) {
        mean_p_value += p;
    }
    mean_p_value /= p_values.size();
    std::cout << mean_p_value << std::endl;
    return 0;
}