#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

std::vector<double> generate_data(int size) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

std::vector<double> compute_p_values(const std::vector<double>& data1, const std::vector<double>& data2) {
    std::vector<double> combined = data1;
    combined.insert(combined.end(), data2.begin(), data2.end());
    std::vector<double> p_values;
    for (int i = 0; i < 1000; ++i) {
        std::shuffle(combined.begin(), combined.end(), std::default_random_engine());
        int split = data1.size();
        double sum1 = std::accumulate(combined.begin(), combined.begin() + split, 0.0);
        double sum2 = std::accumulate(combined.begin() + split, combined.end(), 0.0);
        p_values.push_back(sum1 / (sum1 + sum2));
    }
    return p_values;
}

int main() {
    std::vector<double> data_a = generate_data(50);
    std::vector<double> data_b = generate_data(50);
    while (true) {
        std::vector<double> p_values = compute_p_values(data_a, data_b);
        for (double p : p_values) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}