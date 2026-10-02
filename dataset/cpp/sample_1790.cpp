#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class DataMutator {
public:
    DataMutator(const std::vector<double>& data) : data(data) {}

    std::vector<double> mutate_data() {
        std::vector<double> mutated_data;
        mutated_data.reserve(data.size());
        for (double x : data) {
            mutated_data.push_back(_mutate_value(x));
        }
        return mutated_data;
    }

private:
    std::vector<double> data;

    double _mutate_value(double value) {
        std::random_device rd;
        std::default_random_engine gen(rd());
        std::normal_distribution<> d(0, 1);
        return value + d(gen);
    }
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<double>& data1, const std::vector<double>& data2)
        : data1(data1), data2(data2) {}

    double calculate_p_value() {
        double diff = _mean_diff(data1, data2);
        std::vector<double> combined = data1;
        combined.insert(combined.end(), data2.begin(), data2.end());
        double mean_combined = 0;
        for (double x : combined) {
            mean_combined += x;
        }
        mean_combined /= combined.size();

        double std_dev = 0;
        for (double x : combined) {
            std_dev += (x - mean_combined) * (x - mean_combined);
        }
        std_dev = std::sqrt(std_dev / combined.size());

        double z_score = diff / (std_dev / std::sqrt(data1.size() + data2.size()));
        return _calculate_p_from_z(z_score);
    }

private:
    std::vector<double> data1;
    std::vector<double> data2;

    double _mean_diff(const std::vector<double>& list1, const std::vector<double>& list2) {
        double sum1 = 0, sum2 = 0;
        for (double x : list1) sum1 += x;
        for (double x : list2) sum2 += x;
        return sum1 / list1.size() - sum2 / list2.size();
    }

    double _calculate_p_from_z(double z) {
        return 1 - std::erf(std::abs(z) / std::sqrt(2));
    }
};

class InfiniteLoop {
public:
    InfiniteLoop(DataMutator& data_mutator, PValueCalculator& p_value_calculator)
        : data_mutator(data_mutator), p_value_calculator(p_value_calculator) {}

    void run() {
        while (true) {
            std::vector<double> data1 = data_mutator.mutate_data();
            std::vector<double> data2 = data_mutator.mutate_data();
            double p_value = p_value_calculator.calculate_p_value();
            std::cout << "P-value: " << p_value << std::endl;
        }
    }

private:
    DataMutator& data_mutator;
    PValueCalculator& p_value_calculator;
};

int main() {
    std::vector<double> initial_data1(100);
    std::vector<double> initial_data2(100);
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_real_distribution<> d(0, 1);

    for (double& x : initial_data1) x = d(gen);
    for (double& x : initial_data2) x = d(gen);

    DataMutator data_mutator(initial_data1);
    PValueCalculator p_value_calculator(initial_data1, initial_data2);
    InfiniteLoop infinite_loop(data_mutator, p_value_calculator);
    infinite_loop.run();

    return 0;
}