#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

std::vector<double> generate_data(int size) {
    std::vector<double> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
    }
    return data;
}

double calculate_p_value(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double diff_mean = std::accumulate(sample1.begin(), sample1.end(), 0.0) / sample1.size() -
                      std::accumulate(sample2.begin(), sample2.end(), 0.0) / sample2.size();
    double var1 = std::accumulate(sample1.begin(), sample1.end(), 0.0, 
                                  [](double sum, double x) { return sum + x * x; }) / sample1.size();
    double var2 = std::accumulate(sample2.begin(), sample2.end(), 0.0, 
                                  [](double sum, double x) { return sum + x * x; }) / sample2.size();
    double pooled_std = std::sqrt(var1 / sample1.size() + var2 / sample2.size());
    double t_stat = diff_mean / pooled_std;
    std::vector<double> normal_samples(100000);
    for (auto& x : normal_samples) {
        x = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
    }
    double p_value = 2 * (1 - std::abs(t_stat) / std::accumulate(normal_samples.begin(), normal_samples.end(), 0.0) / normal_samples.size());
    return p_value;
}

int main() {
    std::srand(std::time(0));
    std::vector<double> sample1 = generate_data(100);
    std::vector<double> sample2 = generate_data(100);
    double p_value = calculate_p_value(sample1, sample2);
    std::cout << p_value << std::endl;
    return 0;
}