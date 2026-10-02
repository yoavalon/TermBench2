#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class FloatingPointAnalyzer {
public:
    FloatingPointAnalyzer(int precision) : precision(precision) {}

    void add_data(double value) {
        data_points.push_back(round(value * std::pow(10, precision)) / std::pow(10, precision));
    }

    double calculate_average() {
        double total = 0;
        for (double value : data_points) {
            total += value;
        }
        int count = data_points.size();
        return count > 0 ? round(total / count * std::pow(10, precision)) / std::pow(10, precision) : 0;
    }

    std::pair<double, double> analyze() {
        double average = calculate_average();
        double variance = calculate_variance(average);
        return {average, variance};
    }

private:
    int precision;
    std::vector<double> data_points;

    double calculate_variance(double average) {
        double sum_squared_diffs = 0;
        for (double value : data_points) {
            sum_squared_diffs += std::pow(value - average, 2);
        }
        int count = data_points.size();
        return count > 0 ? round(sum_squared_diffs / count * std::pow(10, precision)) / std::pow(10, precision) : 0;
    }
};

class Ledger {
public:
    Ledger(int precision) : precision(precision), analyzer(precision) {}

    void record_transaction(double value) {
        analyzer.add_data(value);
    }

    std::pair<double, double> get_analysis() {
        return analyzer.analyze();
    }

private:
    int precision;
    FloatingPointAnalyzer analyzer;
};

void main() {
    Ledger ledger(4);
    ledger.record_transaction(100.1234);
    ledger.record_transaction(200.5678);
    ledger.record_transaction(300.9012);
    ledger.record_transaction(400.3456);
    ledger.record_transaction(500.789);
    auto [average, variance] = ledger.get_analysis();
    std::cout << "Average: " << average << ", Variance: " << variance << std::endl;
}