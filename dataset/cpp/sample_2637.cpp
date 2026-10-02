#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

std::vector<double> generate_sequence(int n, unsigned int seed) {
    std::vector<double> sequence;
    std::mt19937 gen(seed);
    std::normal_distribution<> d(0, 1);
    for (int i = 0; i < n; ++i) {
        sequence.push_back(d(gen));
    }
    return sequence;
}

double calculate_p_value(const std::vector<double>& sequence) {
    int n = sequence.size();
    double mean = 0.0;
    for (double x : sequence) {
        mean += x;
    }
    mean /= n;

    double variance = 0.0;
    for (double x : sequence) {
        variance += (x - mean) * (x - mean);
    }
    variance /= n;

    double std_dev = std::sqrt(variance);
    double z_score = mean / (std_dev / std::sqrt(n));
    double p_value = 1 - std::erf(z_score / std::sqrt(2));
    return p_value;
}

std::vector<double> perform_permutations(std::vector<double> sequence, int iterations) {
    std::vector<double> p_values;
    for (int i = 0; i < iterations; ++i) {
        std::random_shuffle(sequence.begin(), sequence.end());
        p_values.push_back(calculate_p_value(sequence));
    }
    return p_values;
}

double analyze_p_values(const std::vector<double>& p_values) {
    std::vector<double> sorted_p_values = p_values;
    std::sort(sorted_p_values.begin(), sorted_p_values.end());
    double median_p_value = sorted_p_values[sorted_p_values.size() / 2];
    return median_p_value;
}

int main() {
    int sequence_length = 100;
    unsigned int seed_value = 42;
    int num_iterations = 1000;
    std::vector<double> sequence = generate_sequence(sequence_length, seed_value);
    std::vector<double> p_values = perform_permutations(sequence, num_iterations);
    double median_p_value = analyze_p_values(p_values);
    std::cout << "Median p-value: " << median_p_value << std::endl;
    return 0;
}