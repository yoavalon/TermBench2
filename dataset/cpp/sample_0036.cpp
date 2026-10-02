#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

double permutation_test(const std::vector<double>& x, const std::vector<double>& y, int n_resamples) {
    double original_diff = std::accumulate(x.begin(), x.end(), 0.0) / x.size() - std::accumulate(y.begin(), y.end(), 0.0) / y.size();
    std::vector<double> combined(x.size() + y.size());
    std::copy(x.begin(), x.end(), combined.begin());
    std::copy(y.begin(), y.end(), combined.begin() + x.size());

    int larger_count = 0;
    for (int i = 0; i < n_resamples; ++i) {
        std::shuffle(combined.begin(), combined.end(), std::default_random_engine());
        std::vector<double> permuted_x(combined.begin(), combined.begin() + x.size());
        std::vector<double> permuted_y(combined.begin() + x.size(), combined.end());
        double permuted_diff = std::accumulate(permuted_x.begin(), permuted_x.end(), 0.0) / permuted_x.size() - std::accumulate(permuted_y.begin(), permuted_y.end(), 0.0) / permuted_y.size();
        if (permuted_diff >= original_diff) {
            larger_count++;
        }
    }
    return static_cast<double>(larger_count) / n_resamples;
}

int main() {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, 1);
    std::vector<double> x(100);
    std::vector<double> y(100);

    for (int i = 0; i < 100; ++i) {
        x[i] = distribution(generator);
        y[i] = distribution(generator) + 0.5;
    }

    double pvalue = permutation_test(x, y, 1000);
    std::cout << pvalue << std::endl;

    return 0;
}