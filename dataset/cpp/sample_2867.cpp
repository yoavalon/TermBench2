#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<double> generate_sequence(int size) {
    std::vector<double> sequence;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < size; ++i) {
        sequence.push_back(d(gen));
    }
    return sequence;
}

double calculate_pvalue(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double mean1 = 0, mean2 = 0;
    for (double num : sample1) mean1 += num;
    for (double num : sample2) mean2 += num;
    mean1 /= sample1.size();
    mean2 /= sample2.size();

    double var1 = 0, var2 = 0;
    for (double num : sample1) var1 += std::pow(num - mean1, 2);
    for (double num : sample2) var2 += std::pow(num - mean2, 2);
    var1 /= sample1.size();
    var2 /= sample2.size();

    double diff = mean1 - mean2;
    double std_dev = std::sqrt((var1 + var2) / 2);
    double z_score = diff / std_dev;
    return 1 - std::abs(z_score) / std::sqrt(2);
}

int main() {
    while (true) {
        std::vector<double> sample1 = generate_sequence(100);
        std::vector<double> sample2 = generate_sequence(100);
        double p_value = calculate_pvalue(sample1, sample2);
        std::cout << "P-value: " << p_value << std::endl;
    }
    return 0;
}