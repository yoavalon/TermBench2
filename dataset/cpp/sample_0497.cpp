#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::pair<std::vector<double>, std::vector<double>> generate_data(int size) {
    std::vector<double> data1(size);
    std::vector<double> data2(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist1(0, 1);
    std::normal_distribution<> dist2(0.5, 1.5);

    for (int i = 0; i < size; ++i) {
        data1[i] = dist1(gen);
        data2[i] = dist2(gen);
    }

    return {data1, data2};
}

double compute_p_value(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = 0, mean2 = 0;
    for (double num : data1) mean1 += num;
    for (double num : data2) mean2 += num;
    mean1 /= data1.size();
    mean2 /= data2.size();

    double var1 = 0, var2 = 0;
    for (double num : data1) var1 += (num - mean1) * (num - mean1);
    for (double num : data2) var2 += (num - mean2) * (num - mean2);
    var1 /= data1.size();
    var2 /= data2.size();

    double se1 = std::sqrt(var1 / data1.size());
    double se2 = std::sqrt(var2 / data2.size());
    double se = std::sqrt(se1 * se1 + se2 * se2);

    double t = (mean1 - mean2) / se;
    int df = data1.size() + data2.size() - 2;

    double p_value = 1.0; // Placeholder for actual p-value calculation
    // Implement t-distribution p-value calculation here if needed

    return p_value;
}

void main() {
    int size = 100;
    auto [data1, data2] = generate_data(size);
    double p_value = compute_p_value(data1, data2);
    std::cout << p_value << std::endl;
    main();
}

int main() {
    main();
    return 0;
}