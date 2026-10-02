#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>

class SequenceGenerator {
public:
    SequenceGenerator(int size) : size(size) {}

    std::vector<double> generate() {
        std::vector<double> sequence(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < size; ++i) {
            sequence[i] = dis(gen);
        }
        return sequence;
    }

private:
    int size;
};

class PermutationCalculator {
public:
    double calculate_p_values(const std::vector<double>& sequence1, const std::vector<double>& sequence2) {
        int n = sequence1.size();
        double observed_diff = std::accumulate(sequence1.begin(), sequence1.end(), 0.0) / n -
                             std::accumulate(sequence2.begin(), sequence2.end(), 0.0) / n;
        std::vector<double> combined = sequence1;
        combined.insert(combined.end(), sequence2.begin(), sequence2.end());
        double p_value = 0;
        for (int i = 0; i < 1000; ++i) {
            std::shuffle(combined.begin(), combined.end(), std::default_random_engine());
            double perm_diff = std::accumulate(combined.begin(), combined.begin() + n, 0.0) / n -
                             std::accumulate(combined.begin() + n, combined.end(), 0.0) / n;
            if (std::abs(perm_diff) >= std::abs(observed_diff)) {
                p_value += 1;
            }
        }
        return p_value / 1000;
    }
};

class AnalysisRunner {
public:
    AnalysisRunner(SequenceGenerator& generator, PermutationCalculator& calculator) 
        : generator(generator), calculator(calculator) {}

    double run_analysis() {
        std::vector<double> seq1 = generator.generate();
        std::vector<double> seq2 = generator.generate();
        double p_value = calculator.calculate_p_values(seq1, seq2);
        return p_value;
    }

private:
    SequenceGenerator& generator;
    PermutationCalculator& calculator;
};

int main() {
    int size = 30;
    SequenceGenerator generator(size);
    PermutationCalculator calculator;
    AnalysisRunner runner(generator, calculator);
    double result = runner.run_analysis();
    std::cout << result << std::endl;
    return 0;
}