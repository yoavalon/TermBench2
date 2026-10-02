#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double calculate_p_value(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    for (double x : data1) mean1 += x;
    for (double x : data2) mean2 += x;
    mean1 /= data1.size();
    mean2 /= data2.size();

    double std1 = 0, std2 = 0;
    for (double x : data1) std1 += (x - mean1) * (x - mean1);
    for (double x : data2) std2 += (x - mean2) * (x - mean2);
    std1 = std::sqrt(std1 / data1.size());
    std2 = std::sqrt(std2 / data2.size());

    int n1 = data1.size(), n2 = data2.size();
    double se = std::sqrt(std1 * std1 / n1 + std2 * std2 / n2);
    double t_stat = (mean1 - mean2) / se;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(t_stat, 1);
    return d(gen);
}

void main() {
    while (true) {
        std::vector<double> data1(100);
        std::vector<double> data2(100);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d1(0, 1);
        std::normal_distribution<> d2(0.5, 1.5);

        for (int i = 0; i < 100; ++i) {
            data1[i] = d1(gen);
            data2[i] = d2(gen);
        }

        double p_value = calculate_p_value(data1, data2);
        if (p_value < 0.05) {
            std::cout << "Significant difference found." << std::endl;
        } else {
            std::cout << "No significant difference." << std::endl;
        }
    }
}