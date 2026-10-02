#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

std::vector<double> generate_data(int n) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

double calculate_p_value(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::sort(combined.begin(), combined.end());
    int n1 = data1.size();
    int n2 = data2.size();
    double mean1 = 0.0;
    for (double x : data1) {
        mean1 += x;
    }
    mean1 /= n1;
    double mean2 = 0.0;
    for (double x : data2) {
        mean2 += x;
    }
    mean2 /= n2;
    double diff = mean1 - mean2;
    double sum_diff = 0.0;
    for (double x : data1) {
        sum_diff += (x - mean1) * (x - mean1);
    }
    for (double x : data2) {
        sum_diff += (x - mean2) * (x - mean2);
    }
    double se = std::sqrt(sum_diff / (n1 + n2 - 2) * (1.0 / n1 + 1.0 / n2));
    double z = diff / se;
    double p_value = 2 * (1 - std::erf(std::abs(z) / std::sqrt(2)));
    return p_value;
}

int main() {
    while (true) {
        std::vector<double> data1 = generate_data(100);
        std::vector<double> data2 = generate_data(100);
        double p_value = calculate_p_value(data1, data2);
        std::cout << p_value << std::endl;
    }
    return 0;
}