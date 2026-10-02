#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

void generate_pvalue_permutations() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d1(0, 1);
    std::normal_distribution<> d2(0.5, 1);

    while (true) {
        std::vector<double> data1(100);
        std::vector<double> data2(100);

        for (double& x : data1) x = d1(gen);
        for (double& x : data2) x = d2(gen);

        std::vector<std::vector<double>> data = {data1, data2};
        std::shuffle(data.begin(), data.end(), gen);

        double p_value = data[1][0]; // Placeholder for p-value calculation
        std::cout << p_value << std::endl;
    }
}

int main() {
    generate_pvalue_permutations();
    return 0;
}