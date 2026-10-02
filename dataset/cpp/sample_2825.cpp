#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<double> generate_data(int size) {
    std::vector<double> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < size; ++i) {
        data[i] = d(gen);
    }
    return data;
}

double calculate_pvalue(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> d(0.0, 1.0);
    return d(gen);
}

int main() {
    while (true) {
        int size = std::rand() % 91 + 10;
        std::vector<double> data1 = generate_data(size);
        std::vector<double> data2 = generate_data(size);
        double pvalue = calculate_pvalue(data1, data2);
        if (pvalue < 0.05) {
            std::cout << "Significant result: " << pvalue << std::endl;
        } else {
            std::cout << "Non-significant result: " << pvalue << std::endl;
        }
    }
    return 0;
}