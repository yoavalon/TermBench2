#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

std::vector<double> generate_data(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1.5);
    
    std::vector<double> data1(size);
    std::vector<double> data2(size);
    
    for (int i = 0; i < size; ++i) {
        data1[i] = d1(gen);
        data2[i] = d2(gen);
    }
    
    return {data1, data2};
}

double calculate_p_values(const std::vector<double>& data1, const std::vector<double>& data2, int permutations) {
    std::vector<double> p_values;
    std::vector<double> combined(data1.size() + data2.size());
    
    double observed_diff = std::accumulate(data1.begin(), data1.end(), 0.0) / data1.size() - 
                          std::accumulate(data2.begin(), data2.end(), 0.0) / data2.size();
    
    for (int _ = 0; _ < permutations; ++_) {
        std::copy(data1.begin(), data1.end(), combined.begin());
        std::copy(data2.begin(), data2.end(), combined.begin() + data1.size());
        std::shuffle(combined.begin(), combined.end(), std::default_random_engine());
        
        double new_data1_mean = std::accumulate(combined.begin(), combined.begin() + data1.size(), 0.0) / data1.size();
        double new_data2_mean = std::accumulate(combined.begin() + data1.size(), combined.end(), 0.0) / data2.size();
        
        p_values.push_back(new_data1_mean - new_data2_mean >= observed_diff);
    }
    
    double p_value = std::accumulate(p_values.begin(), p_values.end(), 0.0) / p_values.size();
    return p_value;
}

int main() {
    int size = 100;
    int permutations = 1000;
    auto [data1, data2] = generate_data(size);
    double p_value = calculate_p_values(data1, data2, permutations);
    std::cout << p_value << std::endl;
    return 0;
}