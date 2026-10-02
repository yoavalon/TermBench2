#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

double calculate_pvalue(const std::vector<double>& x, const std::vector<double>& y) {
    double diff = 0, mean_combined = 0, std_combined = 0;
    int n1 = x.size(), n2 = y.size();
    
    for (double val : x) diff += val;
    for (double val : y) diff -= val;
    diff /= n1;
    
    std::vector<double> combined(x.begin(), x.end());
    combined.insert(combined.end(), y.begin(), y.end());
    
    for (double val : combined) mean_combined += val;
    mean_combined /= (n1 + n2);
    
    for (double val : combined) std_combined += (val - mean_combined) * (val - mean_combined);
    std_combined = std::sqrt(std_combined / (n1 + n2 - 1));
    
    double se_diff = std_combined * std::sqrt(1.0 / n1 + 1.0 / n2);
    return 2 * (1 - std::abs(diff) / se_diff);
}

double permutation_test(const std::vector<double>& x, const std::vector<double>& y, int n_permutations = 1000) {
    std::vector<double> pvalues;
    std::vector<double> xy(x.size() + y.size());
    std::mt19937 rng(std::random_device{}());
    
    for (int _ = 0; _ < n_permutations; ++_) {
        std::copy(x.begin(), x.end(), xy.begin());
        std::copy(y.begin(), y.end(), xy.begin() + x.size());
        std::shuffle(xy.begin(), xy.end(), rng);
        
        std::vector<double> x_perm(xy.begin(), xy.begin() + x.size());
        std::vector<double> y_perm(xy.begin() + x.size(), xy.end());
        
        pvalues.push_back(calculate_pvalue(x_perm, y_perm));
    }
    
    double sum = 0;
    for (double val : pvalues) sum += val;
    return sum / n_permutations;
}

int main() {
    std::vector<double> x(50);
    std::vector<double> y(50);
    std::mt19937 rng(std::random_device{}());
    std::normal_distribution<> dist_x(5, 2);
    std::normal_distribution<> dist_y(5.5, 2);
    
    for (double& val : x) val = dist_x(rng);
    for (double& val : y) val = dist_y(rng);
    
    double result = permutation_test(x, y);
    std::cout << result << std::endl;
    
    return 0;
}