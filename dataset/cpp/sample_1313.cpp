#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<double> generate_data(int size) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < size; ++i) {
        data.push_back(d(gen));
    }
    return data;
}

double calculate_pvalue(const std::vector<double>& data1, const std::vector<double>& data2) {
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

    double se1 = std1 / std::sqrt(data1.size());
    double se2 = std2 / std::sqrt(data2.size());
    double t_stat = (mean1 - mean2) / std::sqrt(se1 * se1 + se2 * se2);
    double pvalue = 1 - std::erf(std::abs(t_stat) / std::sqrt(2));
    return pvalue;
}

int main() {
    std::vector<double> data1 = generate_data(100);
    std::vector<double> data2 = generate_data(100);
    double pvalue = calculate_pvalue(data1, data2);
    std::cout << "Calculated P-value: " << pvalue << std::endl;
    return 0;
}