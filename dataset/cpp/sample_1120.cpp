#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

class DataGenerator {
public:
    std::vector<double> data;

    DataGenerator(int size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < size; ++i) {
            data.push_back(dis(gen));
        }
    }

    std::vector<double> generate() {
        return data;
    }
};

class PValueCalculator {
public:
    std::vector<double> data1;
    std::vector<double> data2;

    PValueCalculator(std::vector<double> data1, std::vector<double> data2) : data1(data1), data2(data2) {}

    double calculate_p_value() {
        int n1 = data1.size();
        int n2 = data2.size();
        double mean1 = 0, mean2 = 0;
        for (double x : data1) mean1 += x;
        for (double x : data2) mean2 += x;
        mean1 /= n1;
        mean2 /= n2;

        double se1 = 0, se2 = 0;
        for (double x : data1) se1 += (x - mean1) * (x - mean1);
        for (double x : data2) se2 += (x - mean2) * (x - mean2);
        se1 = std::sqrt(se1 / (n1 - 1)) / std::sqrt(n1);
        se2 = std::sqrt(se2 / (n2 - 1)) / std::sqrt(n2);

        double se_diff = std::sqrt(se1 * se1 + se2 * se2);
        double t_stat = (mean1 - mean2) / se_diff;
        double df = (se1 * se1 + se2 * se2) * (se1 * se1 + se2 * se2) / (se1 * se1 * se1 * se1 / (n1 - 1) + se2 * se2 * se2 * se2 / (n2 - 1));
        double p_value = 2 * (1 - std::tanh(t_stat * std::sqrt(df / (df + 1))));
        return p_value;
    }
};

class PermutationTester {
public:
    std::vector<double> data1;
    std::vector<double> data2;

    PermutationTester(std::vector<double> data1, std::vector<double> data2) : data1(data1), data2(data2) {}

    double permute_and_test() {
        std::vector<double> combined_data = data1;
        combined_data.insert(combined_data.end(), data2.begin(), data2.end());
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(combined_data.begin(), combined_data.end(), g);
        std::vector<double> new_data1(combined_data.begin(), combined_data.begin() + data1.size());
        std::vector<double> new_data2(combined_data.begin() + data1.size(), combined_data.end());
        PValueCalculator p_calculator(new_data1, new_data2);
        return p_calculator.calculate_p_value();
    }
};

void main() {
    DataGenerator data_gen1(100);
    DataGenerator data_gen2(100);
    std::vector<double> data1 = data_gen1.generate();
    std::vector<double> data2 = data_gen2.generate();
    PermutationTester perm_tester(data1, data2);
    double p_value = perm_tester.permute_and_test();
    std::cout << p_value << std::endl;
    main();
}

int main() {
    main();
    return 0;
}