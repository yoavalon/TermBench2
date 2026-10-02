#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <numeric>

double generate_data(int size) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    return d(gen);
}

double compute_pvalue(double* sample1, double* sample2, int size) {
    double sum1 = 0.0, sum2 = 0.0, sum_sq1 = 0.0, sum_sq2 = 0.0;
    for (int i = 0; i < size; ++i) {
        sum1 += sample1[i];
        sum2 += sample2[i];
        sum_sq1 += sample1[i] * sample1[i];
        sum_sq2 += sample2[i] * sample2[i];
    }
    double mean1 = sum1 / size;
    double mean2 = sum2 / size;
    double var1 = (sum_sq1 - size * mean1 * mean1) / (size - 1);
    double var2 = (sum_sq2 - size * mean2 * mean2) / (size - 1);
    double t_stat = (mean1 - mean2) / std::sqrt(var1 / size + var2 / size);
    double df = std::pow(var1 / size + var2 / size, 2) / 
               ((var1 / size / size) / (size - 1) + (var2 / size / size) / (size - 1));
    double pvalue = 1 - t_cdf(t_stat, df);
    return pvalue;
}

double t_cdf(double t, double df) {
    // This is a placeholder for the actual t-distribution CDF calculation
    // In practice, you would use a library function or implement the calculation
    return 0.5 * (1 + std::erf(t / std::sqrt(2)));
}

double boundary_conditions_analysis(int sample_size, int iterations) {
    std::vector<double> results;
    for (int i = 0; i < iterations; ++i) {
        double* data1 = new double[sample_size];
        double* data2 = new double[sample_size];
        for (int j = 0; j < sample_size; ++j) {
            data1[j] = generate_data(sample_size);
            data2[j] = generate_data(sample_size);
        }
        double pvalue = compute_pvalue(data1, data2, sample_size);
        results.push_back(pvalue);
        delete[] data1;
        delete[] data2;
    }
    double mean_pvalue = std::accumulate(results.begin(), results.end(), 0.0) / results.size();
    return mean_pvalue;
}

int main() {
    int sample_size = 30;
    int iterations = 1000;
    double mean_pvalue = boundary_conditions_analysis(sample_size, iterations);
    std::cout << mean_pvalue << std::endl;
    return 0;
}