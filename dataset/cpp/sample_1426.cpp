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
        std::normal_distribution<> dis(0, 1);
        for (int i = 0; i < size; ++i) {
            data.push_back(dis(gen));
        }
    }
};

class PValueCalculator {
public:
    std::vector<double> data1;
    std::vector<double> data2;

    PValueCalculator(const std::vector<double>& data1, const std::vector<double>& data2)
        : data1(data1), data2(data2) {}

    double calculate_p_value() {
        double mean1 = 0, mean2 = 0;
        for (double x : data1) mean1 += x;
        for (double x : data2) mean2 += x;
        mean1 /= data1.size();
        mean2 /= data2.size();
        double diff = mean1 - mean2;
        double var1 = 0, var2 = 0;
        for (double x : data1) var1 += (x - mean1) * (x - mean1);
        for (double x : data2) var2 += (x - mean2) * (x - mean2);
        var1 /= data1.size();
        var2 /= data2.size();
        return diff / std::sqrt(var1 + var2);
    }
};

class PermutationTester {
public:
    std::vector<double> data1;
    std::vector<double> data2;
    int iterations;

    PermutationTester(const std::vector<double>& data1, const std::vector<double>& data2, int iterations)
        : data1(data1), data2(data2), iterations(iterations) {}

    double permute_and_test() {
        PValueCalculator pval_calculator(data1, data2);
        double original_p_value = pval_calculator.calculate_p_value();
        int larger = 0;
        std::vector<double> combined_data = data1;
        combined_data.insert(combined_data.end(), data2.begin(), data2.end());
        for (int i = 0; i < iterations; ++i) {
            std::random_shuffle(combined_data.begin(), combined_data.end());
            std::vector<double> new_data1(combined_data.begin(), combined_data.begin() + data1.size());
            std::vector<double> new_data2(combined_data.begin() + data1.size(), combined_data.end());
            PValueCalculator new_pval_calculator(new_data1, new_data2);
            double new_p_value = new_pval_calculator.calculate_p_value();
            if (std::abs(new_p_value) >= std::abs(original_p_value)) {
                larger++;
            }
        }
        return static_cast<double>(larger) / iterations;
    }
};

int main() {
    int size = 100;
    int iterations = 1000;
    DataGenerator generator1(size);
    DataGenerator generator2(size);
    PermutationTester tester(generator1.data, generator2.data, iterations);
    double result = tester.permute_and_test();
    std::cout << result << std::endl;
    return 0;
}