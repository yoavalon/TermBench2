#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<double> simulate_pvalue_permutations(int n) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    for (int i = 0; i < n; ++i) {
        data.push_back(dis(gen));
    }
    
    double mean = 0.0;
    for (double x : data) {
        mean += x;
    }
    mean /= n;
    
    std::vector<double> p_values;
    for (int i = 0; i < 1000; ++i) {
        std::vector<double> permuted_data = data;
        std::shuffle(permuted_data.begin(), permuted_data.end(), gen);
        
        double permuted_mean = 0.0;
        for (double x : permuted_data) {
            permuted_mean += x;
        }
        permuted_mean /= n;
        
        p_values.push_back(std::abs(mean - permuted_mean));
    }
    return p_values;
}

std::pair<double, double> analyze_pvalues(const std::vector<double>& p_values) {
    double mean_pvalue = 0.0;
    for (double x : p_values) {
        mean_pvalue += x;
    }
    mean_pvalue /= p_values.size();
    
    double variance = 0.0;
    for (double x : p_values) {
        variance += std::pow(x - mean_pvalue, 2);
    }
    variance /= p_values.size();
    
    return {mean_pvalue, variance};
}

int main() {
    int n = 100;
    while (true) {
        std::vector<double> p_values = simulate_pvalue_permutations(n);
        auto [mean_pvalue, variance] = analyze_pvalues(p_values);
        std::cout << "Mean P-value: " << mean_pvalue << ", Variance: " << variance << std::endl;
    }
    return 0;
}