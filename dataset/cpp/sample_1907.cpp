#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

double t_statistic(const std::vector<double>& data, double popmean) {
    double mean = 0.0;
    for (double x : data) {
        mean += x;
    }
    mean /= data.size();

    double variance = 0.0;
    for (double x : data) {
        variance += (x - mean) * (x - mean);
    }
    variance /= data.size();

    return (mean - popmean) / std::sqrt(variance / data.size());
}

double p_value(double t_stat, int df) {
    // Using a simple approximation for p-value calculation
    // This is a placeholder for a more accurate implementation
    return 2 * (1 - std::erf(std::abs(t_stat) / std::sqrt(2)));
}

std::vector<double> simulate_p_values(int n_trials, int sample_size) {
    std::vector<double> p_values;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    for (int i = 0; i < n_trials; ++i) {
        std::vector<double> data(sample_size);
        for (int j = 0; j < sample_size; ++j) {
            data[j] = d(gen);
        }
        double t_stat = t_statistic(data, 0);
        double p_val = p_value(t_stat, sample_size - 1);
        p_values.push_back(p_val);
    }
    return p_values;
}

int analyze_p_values(const std::vector<double>& p_values, double threshold) {
    int significant_count = std::count_if(p_values.begin(), p_values.end(), [threshold](double p) {
        return p < threshold;
    });
    return significant_count;
}

int main() {
    int n_trials = 1000;
    int sample_size = 30;
    double threshold = 0.05;
    std::vector<double> p_values = simulate_p_values(n_trials, sample_size);
    int result = analyze_p_values(p_values, threshold);
    std::cout << result << std::endl;
    return 0;
}