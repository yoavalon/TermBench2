#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<double> generate_data(int size) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < size; ++i) {
        data.push_back(d(gen));
    }
    return data;
}

double calculate_p_value(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    for (double x : data1) mean1 += x;
    for (double x : data2) mean2 += x;
    mean1 /= data1.size();
    mean2 /= data2.size();
    double variance1 = 0, variance2 = 0;
    for (double x : data1) variance1 += (x - mean1) * (x - mean1);
    for (double x : data2) variance2 += (x - mean2) * (x - mean2);
    variance1 /= data1.size();
    variance2 /= data2.size();
    double pooled_variance = ((data1.size() - 1) * variance1 + (data2.size() - 1) * variance2) / (data1.size() + data2.size() - 2);
    double t_statistic = (mean1 - mean2) / std::sqrt(pooled_variance * (1.0 / data1.size() + 1.0 / data2.size()));
    int df = data1.size() + data2.size() - 2;
    double p_value = 2 * (1 - std::tanh(t_statistic * std::sqrt(df / (df + t_statistic * t_statistic))));
    return p_value;
}

std::vector<double> simulate_p_values(int num_simulations, int sample_size) {
    std::vector<double> p_values;
    for (int i = 0; i < num_simulations; ++i) {
        auto data1 = generate_data(sample_size);
        auto data2 = generate_data(sample_size);
        p_values.push_back(calculate_p_value(data1, data2));
    }
    return p_values;
}

void main() {
    int num_simulations = 1000;
    int sample_size = 30;
    auto p_values = simulate_p_values(num_simulations, sample_size);
    std::sort(p_values.begin(), p_values.end());
    double median_p_value = p_values[p_values.size() / 2];
    std::cout << "Median P-value: " << median_p_value << std::endl;
}