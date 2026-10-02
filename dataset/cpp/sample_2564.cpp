#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

std::pair<std::vector<double>, std::vector<double>> generate_data(int n) {
    std::vector<double> a(n);
    std::vector<double> b(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        a[i] = dis(gen);
        b[i] = dis(gen);
    }

    return {a, b};
}

double calculate_pvalue(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> combined = a;
    combined.insert(combined.end(), b.begin(), b.end());
    std::sort(combined.begin(), combined.end());

    int rank_sum = 0;
    for (double x : a) {
        rank_sum += std::find(combined.begin(), combined.end(), x) - combined.begin() + 1;
    }

    int n1 = a.size();
    int n2 = b.size();
    double mean_rank_sum = n1 * (n1 + n2 + 1) / 2.0;
    double var_rank_sum = n1 * n2 * (n1 + n2 + 1) / 12.0;
    double z = (rank_sum - mean_rank_sum) / std::sqrt(var_rank_sum);
    return 2 * (1 - std::erf(std::abs(z) / std::sqrt(2)));
}

int main() {
    int n = 10;
    auto [a, b] = generate_data(n);
    double p_value = calculate_pvalue(a, b);
    std::cout << p_value << std::endl;
    return 0;
}