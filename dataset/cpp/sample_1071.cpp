#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <utility>
#include <any>

std::vector<double>& permute(std::vector<double>& data) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(data.begin(), data.end(), g);
    return data;
}

double func(const std::vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

std::pair<bool, std::any> p_value_permutation(
    std::vector<double>& data, 
    double target, 
    double (*f)(const std::vector<double>&), 
    double threshold = 0.05
) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(data.begin(), data.end(), g);

    bool success = f(data) <= target;
    
    return {success, std::make_any<std::pair<bool, std::any>>(p_value_permutation(data, target, f, threshold))};
}

int main() {
    std::vector<double> data(100);
    std::iota(data.begin(), data.end(), 1.0); 
    
    double target = 50.0;
    
    auto [success, _] = p_value_permutation(data, target, func);
    
    std::cout << (success ? "True" : "False") << std::endl;
    
    return 0;
}