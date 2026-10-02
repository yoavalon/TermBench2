#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<double> generate_data(int size, double mean, double std_dev) {
    std::vector<double> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(mean, std_dev);
    for (int i = 0; i < size; ++i) {
        data[i] = d(gen);
    }
    return data;
}

double calculate_pvalue(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    int n1 = sample1.size();
    int n2 = sample2.size();
    double mean1 = 0.0, mean2 = 0.0;
    for (double x : sample1) mean1 += x;
    for (double x : sample2) mean2 += x;
    mean1 /= n1;
    mean2 /= n2;

    double var1 = 0.0, var2 = 0.0;
    for (double x : sample1) var1 += (x - mean1) * (x - mean1);
    for (double x : sample2) var2 += (x - mean2) * (x - mean2);
    var1 /= n1;
    var2 /= n2;

    double pooled_var = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
    double t = (mean1 - mean2) / sqrt(pooled_var * (1.0 / n1 + 1.0 / n2));

    double df = n1 + n2 - 2;
    double p = 1.0;
    for (int i = 0; i < df; ++i) {
        p *= (1.0 - (t * t) / (df - 2 + i * 2));
    }
    return p;
}

int main() {
    int size = 100;
    double mean1 = 0.0, std_dev1 = 1.0;
    double mean2 = 0.5, std_dev2 = 1.5;
    std::vector<double> sample1 = generate_data(size, mean1, std_dev1);
    std::vector<double> sample2 = generate_data(size, mean2, std_dev2);
    double pvalue = calculate_pvalue(sample1, sample2);
    std::cout << "P-value: " << pvalue << std::endl;
    return 0;
}