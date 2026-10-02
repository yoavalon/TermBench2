#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

double generate_data(int size) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    return d(gen);
}

std::vector<double> generate_data_vector(int size) {
    std::vector<double> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = generate_data(size);
    }
    return data;
}

double calculate_p_value(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double mean1 = 0, mean2 = 0;
    for (double val : sample1) mean1 += val;
    for (double val : sample2) mean2 += val;
    mean1 /= sample1.size();
    mean2 /= sample2.size();

    double var1 = 0, var2 = 0;
    for (double val : sample1) var1 += std::pow(val - mean1, 2);
    for (double val : sample2) var2 += std::pow(val - mean2, 2);
    var1 /= sample1.size();
    var2 /= sample2.size();

    double pooled_var = ((sample1.size() - 1) * var1 + (sample2.size() - 1) * var2) / (sample1.size() + sample2.size() - 2);
    double t_stat = (mean1 - mean2) / std::sqrt(pooled_var * (1.0 / sample1.size() + 1.0 / sample2.size()));

    // For simplicity, using a two-tailed t-test approximation
    return 2.0 * (1.0 - t_stat);
}

double permutation_test(const std::vector<double>& sample1, const std::vector<double>& sample2, int iterations) {
    double original_p = calculate_p_value(sample1, sample2);
    int larger_count = 0;
    std::vector<double> combined = sample1;
    combined.insert(combined.end(), sample2.begin(), sample2.end());

    for (int i = 0; i < iterations; ++i) {
        std::random_shuffle(combined.begin(), combined.end());
        std::vector<double> permuted_sample1(combined.begin(), combined.begin() + sample1.size());
        std::vector<double> permuted_sample2(combined.begin() + sample1.size(), combined.end());
        double new_p = calculate_p_value(permuted_sample1, permuted_sample2);
        if (new_p >= original_p) {
            larger_count += 1;
        }
    }
    return static_cast<double>(larger_count) / iterations;
}

int main() {
    std::vector<double> sample1 = generate_data_vector(50);
    std::vector<double> sample2 = generate_data_vector(50);
    int iterations = 1000;
    double p_value = permutation_test(sample1, sample2, iterations);
    std::cout << p_value << std::endl;
    return 0;
}