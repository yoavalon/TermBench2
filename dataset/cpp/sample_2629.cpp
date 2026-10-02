#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class SequenceGenerator {
public:
    SequenceGenerator(int size) : size(size), sequence(size) {}

    void generate_fibonacci() {
        int a = 0, b = 1;
        for (int i = 0; i < size; ++i) {
            sequence[i] = a;
            int next = a + b;
            a = b;
            b = next;
        }
    }

    void generate_arithmetic(int diff) {
        for (int i = 0; i < size; ++i) {
            sequence[i] = diff * i;
        }
    }

    void generate_geometric(int ratio) {
        for (int i = 0; i < size; ++i) {
            sequence[i] = std::pow(ratio, i);
        }
    }

private:
    int size;
    std::vector<double> sequence;
};

class DataProcessor {
public:
    DataProcessor(const std::vector<double>& sequence) : sequence(sequence) {}

    double calculate_mean() {
        double sum = 0;
        for (double x : sequence) {
            sum += x;
        }
        return sum / sequence.size();
    }

    double calculate_median() {
        std::vector<double> sorted_seq = sequence;
        std::sort(sorted_seq.begin(), sorted_seq.end());
        int mid = sorted_seq.size() / 2;
        return (sorted_seq[mid - 1] + sorted_seq[mid]) / 2.0;
    }

    double calculate_variance() {
        double mean = calculate_mean();
        double sum_sq_diff = 0;
        for (double x : sequence) {
            sum_sq_diff += (x - mean) * (x - mean);
        }
        return sum_sq_diff / sequence.size();
    }

private:
    std::vector<double> sequence;
};

class Optimizer {
public:
    Optimizer(const DataProcessor& processor) : processor(processor) {}

    std::vector<double> optimize_supply_chain() {
        double mean = processor.calculate_mean();
        double median = processor.calculate_median();
        double variance = processor.calculate_variance();
        return {mean, median, variance};
    }

private:
    const DataProcessor& processor;
};

int main() {
    int size = 10;
    int diff = 2;
    int ratio = 3;
    SequenceGenerator generator(size);
    generator.generate_fibonacci();
    DataProcessor processor(generator.sequence);
    Optimizer optimizer(processor);
    std::vector<double> result = optimizer.optimize_supply_chain();
    std::cout << "Mean: " << result[0] << ", Median: " << result[1] << ", Variance: " << result[2] << std::endl;
    return 0;
}