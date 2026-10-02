#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class DataGenerator {
public:
    DataGenerator(int size) : size(size) {
        data.resize(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < size; ++i) {
            data[i] = dis(gen);
        }
    }

    std::vector<double> generate() {
        return data;
    }

private:
    int size;
    std::vector<double> data;
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<double>& data1, const std::vector<double>& data2) : data1(data1), data2(data2) {}

    double calculate() {
        return permutation_test(data1, data2);
    }

private:
    double permutation_test(const std::vector<double>& x, const std::vector<double>& y) {
        std::vector<double> combined = x;
        combined.insert(combined.end(), y.begin(), y.end());
        double observed_diff = std::abs(std::accumulate(x.begin(), x.end(), 0.0) - std::accumulate(y.begin(), y.end(), 0.0));
        int larger = 0;
        for (int i = 0; i < 10000; ++i) {
            std::shuffle(combined.begin(), combined.end(), std::default_random_engine());
            std::vector<double> perm_x(combined.begin(), combined.begin() + x.size());
            std::vector<double> perm_y(combined.begin() + x.size(), combined.end());
            double perm_diff = std::abs(std::accumulate(perm_x.begin(), perm_x.end(), 0.0) - std::accumulate(perm_y.begin(), perm_y.end(), 0.0));
            if (perm_diff >= observed_diff) {
                larger += 1;
            }
        }
        return static_cast<double>(larger) / 10000;
    }

    std::vector<double> data1;
    std::vector<double> data2;
};

class RecursiveAnalysis {
public:
    RecursiveAnalysis(DataGenerator& generator, PValueCalculator& calculator) : generator(generator), calculator(calculator) {}

    void analyze() {
        std::vector<double> data1 = generator.generate();
        std::vector<double> data2 = generator.generate();
        double p_value = calculator.calculate();
        std::cout << "P-value: " << p_value << std::endl;
        analyze();
    }

private:
    DataGenerator& generator;
    PValueCalculator& calculator;
};

int main() {
    DataGenerator data_gen(100);
    PValueCalculator p_value_calc({}, {});
    RecursiveAnalysis analysis(data_gen, p_value_calc);
    analysis.analyze();
    return 0;
}