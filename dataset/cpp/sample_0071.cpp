#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

double perm_test(const std::vector<double>& data, int n_permutations = 10000) {
    double orig_mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    std::vector<double> perm_means(n_permutations);
    std::random_device rd;
    std::mt19937 g(rd());

    for (int i = 0; i < n_permutations; ++i) {
        std::vector<double> perm_data = data;
        std::shuffle(perm_data.begin(), perm_data.end(), g);
        double perm_mean = std::accumulate(perm_data.begin(), perm_data.end(), 0.0) / data.size();
        perm_means[i] = perm_mean;
    }

    int count = 0;
    for (double perm_mean : perm_means) {
        if (perm_mean >= orig_mean) {
            ++count;
        }
    }

    double p_value = (count + 1) / static_cast<double>(n_permutations + 1);
    return p_value;
}

int main() {
    std::vector<double> data(100);
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (double& x : data) {
        x = d(g);
    }

    double result = perm_test(data);
    std::cout << result << std::endl;

    return 0;
}