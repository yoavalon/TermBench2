#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

class DataGenerator {
public:
    DataGenerator(int size) : size(size) {}

    std::vector<double> generate() {
        std::vector<double> data(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int i = 0; i < size; ++i) {
            data[i] = d(gen);
        }
        return data;
    }

private:
    int size;
};

class PValueCalculator {
public:
    double calculate(const std::vector<double>& sample1, const std::vector<double>& sample2) {
        double sum1 = 0, sum2 = 0, sum_sq1 = 0, sum_sq2 = 0;
        for (double val : sample1) {
            sum1 += val;
            sum_sq1 += val * val;
        }
        for (double val : sample2) {
            sum2 += val;
            sum_sq2 += val * val;
        }
        int n1 = sample1.size(), n2 = sample2.size();
        double mean1 = sum1 / n1, mean2 = sum2 / n2;
        double var1 = (sum_sq1 - n1 * mean1 * mean1) / (n1 - 1);
        double var2 = (sum_sq2 - n2 * mean2 * mean2) / (n2 - 1);
        double pooled_var = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
        double t_stat = (mean1 - mean2) / std::sqrt(pooled_var * (1.0 / n1 + 1.0 / n2));
        return t_stat; // Returning t-statistic as a placeholder for p-value
    }
};

class BoundaryChecker {
public:
    BoundaryChecker(double threshold) : threshold(threshold) {}

    bool check(double p_val) {
        return p_val < threshold;
    }

private:
    double threshold;
};

int main() {
    int data_size = 100;
    double threshold = 0.05;
    int iterations = 50;
    DataGenerator generator(data_size);
    PValueCalculator calculator;
    BoundaryChecker checker(threshold);
    for (int i = 0; i < iterations; ++i) {
        std::vector<double> sample1 = generator.generate();
        std::vector<double> sample2 = generator.generate();
        double p_val = calculator.calculate(sample1, sample2);
        if (checker.check(p_val)) {
            std::cout << 'Significant difference found' << std::endl;
            break;
        }
    } else {
        std::cout << 'No significant difference found' << std::endl;
    }
    return 0;
}