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

double calculate_pvalue(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    for (double num : data1) mean1 += num;
    for (double num : data2) mean2 += num;
    mean1 /= data1.size();
    mean2 /= data2.size();

    double std1 = 0, std2 = 0;
    for (double num : data1) std1 += (num - mean1) * (num - mean1);
    for (double num : data2) std2 += (num - mean2) * (num - mean2);
    std1 = std::sqrt(std1 / data1.size());
    std2 = std::sqrt(std2 / data2.size());

    double se1 = std1 / std::sqrt(data1.size());
    double se2 = std2 / std::sqrt(data2.size());
    double z = (mean1 - mean2) / std::sqrt(se1 * se1 + se2 * se2);
    double pvalue = 2 * (1 - std::exp(-0.5 * z * z));
    return pvalue;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
        std::vector<double> data1 = generate_data(100);
        std::vector<double> data2 = generate_data(100);
        double pvalue = calculate_pvalue(data1, data2);
        std::cout << pvalue << std::endl;
    }
    return 0;
}