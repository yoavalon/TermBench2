#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::pair<std::vector<double>, std::vector<double>> generate_data(int n) {
    std::vector<double> x, y;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        x.push_back(dis(gen));
        y.push_back(dis(gen));
    }
    return {x, y};
}

double calculate_pvalue(const std::vector<double>& x, const std::vector<double>& y) {
    std::vector<double> combined = x;
    combined.insert(combined.end(), y.begin(), y.end());
    std::sort(combined.begin(), combined.end());

    int ranksum = 0;
    for (double xi : x) {
        ranksum += std::distance(combined.begin(), std::find(combined.begin(), combined.end(), xi)) + 1;
    }

    double meanrank = x.size() * (combined.size() + 1) / 2.0;
    double varrank = x.size() * y.size() * (combined.size() + 1) * (combined.size() + 2) / 12.0;
    double z = (ranksum - meanrank) / std::sqrt(varrank);
    return 2 * (1 - std::abs(z) / 2);
}

void non_terminating_permutations() {
    while (true) {
        auto [x, y] = generate_data(100);
        double pvalue = calculate_pvalue(x, y);
        std::cout << pvalue << std::endl;
    }
}

int main() {
    non_terminating_permutations();
    return 0;
}