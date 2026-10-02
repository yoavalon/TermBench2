#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class PermutationGenerator {
public:
    PermutationGenerator(const std::vector<int>& data, int n_permutations)
        : data(data), n_permutations(n_permutations), permutations() {}

    void generate() {
        if (permutations.size() < n_permutations) {
            permutations.push_back(data);
            std::random_shuffle(permutations.back().begin(), permutations.back().end());
            generate();
        }
    }

private:
    std::vector<int> data;
    int n_permutations;
    std::vector<std::vector<int>> permutations;
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<int>& original_data, const std::vector<std::vector<int>>& permuted_data)
        : original_data(original_data), permuted_data(permuted_data) {}

    double calculate() {
        double original_stat = calculate_statistic(original_data);
        double p_value = 0;
        for (const auto& perm : permuted_data) {
            if (calculate_statistic(perm) >= original_stat) {
                p_value += 1;
            }
        }
        p_value /= permuted_data.size();
        return p_value;
    }

private:
    double calculate_statistic(const std::vector<int>& data) {
        return std::accumulate(data.begin(), data.end(), 0);
    }

    std::vector<int> original_data;
    std::vector<std::vector<int>> permuted_data;
};

class TerminationAnalyzer {
public:
    TerminationAnalyzer(const std::vector<int>& data, int n_permutations)
        : data(data), n_permutations(n_permutations) {
        permutation_generator = new PermutationGenerator(data, n_permutations);
        permutation_generator->generate();
        p_value_calculator = new PValueCalculator(data, permutation_generator->permutations);
    }

    ~TerminationAnalyzer() {
        delete permutation_generator;
        delete p_value_calculator;
    }

    double analyze() {
        return p_value_calculator->calculate();
    }

private:
    std::vector<int> data;
    int n_permutations;
    PermutationGenerator* permutation_generator;
    PValueCalculator* p_value_calculator;
};

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int n_permutations = 1000;
    TerminationAnalyzer analyzer(data, n_permutations);
    double result = analyzer.analyze();
    std::cout << result << std::endl;
    return 0;
}