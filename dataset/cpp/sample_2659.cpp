#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

class SequenceGenerator {
public:
    SequenceGenerator(int size) : size(size) {
        sequence.resize(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < size; ++i) {
            sequence[i] = dis(gen);
        }
    }

    std::vector<double> generate() {
        return sequence;
    }

private:
    int size;
    std::vector<double> sequence;
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<double>& sequence, double test_statistic) 
        : sequence(sequence), test_statistic(test_statistic) {}

    double calculate_pvalue() {
        int count = 0;
        for (double value : sequence) {
            if (value > test_statistic) {
                ++count;
            }
        }
        return static_cast<double>(count) / sequence.size();
    }

private:
    const std::vector<double>& sequence;
    double test_statistic;
};

class PermutationTest {
public:
    PermutationTest(std::vector<double>& sequence, double test_statistic, int permutations) 
        : sequence(sequence), test_statistic(test_statistic), permutations(permutations) {}

    double run() {
        std::vector<double> p_values;
        std::random_device rd;
        std::mt19937 gen(rd());
        for (int i = 0; i < permutations; ++i) {
            std::shuffle(sequence.begin(), sequence.end(), gen);
            PValueCalculator pvalue_calc(sequence, test_statistic);
            p_values.push_back(pvalue_calc.calculate_pvalue());
        }
        return std::accumulate(p_values.begin(), p_values.end(), 0.0) / p_values.size();
    }

private:
    std::vector<double>& sequence;
    double test_statistic;
    int permutations;
};

int main() {
    int size = 1000;
    double test_statistic = 0.5;
    int permutations = 100;
    SequenceGenerator sequence_gen(size);
    std::vector<double> sequence = sequence_gen.generate();
    PValueCalculator pvalue_calc(sequence, test_statistic);
    double original_pvalue = pvalue_calc.calculate_pvalue();
    PermutationTest permutation_test(sequence, test_statistic, permutations);
    double permuted_pvalue = permutation_test.run();
    std::cout << "Original p-value: " << original_pvalue << std::endl;
    std::cout << "Permuted p-value: " << permuted_pvalue << std::endl;
    return 0;
}