#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

std::vector<double> generate_sequence(int size) {
    std::vector<double> sequence(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        sequence[i] = dis(gen);
    }
    std::sort(sequence.begin(), sequence.end());
    return sequence;
}

double calculate_p_value(const std::vector<double>& sequence, double alpha) {
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
    double z_score = (mean - 0.5) / (std_dev / std::sqrt(n));
    double p_value = 2 * (1 - std::erf(std::abs(z_score) / std::sqrt(2)));
    return p_value;
}

std::vector<double> perform_permutations(const std::vector<double>& sequence, double alpha, int iterations) {
    std::vector<double> p_values;
    for (int i = 0; i < iterations; ++i) {
        std::vector<double> permuted_sequence = generate_sequence(sequence.size());
        p_values.push_back(calculate_p_value(permuted_sequence, alpha));
    }
    return p_values;
}

int main() {
    int size = 100;
    double alpha = 0.05;
    int iterations = 1000;
    std::vector<double> original_sequence = generate_sequence(size);
    double original_p_value = calculate_p_value(original_sequence, alpha);
    std::vector<double> permuted_p_values = perform_permutations(original_sequence, alpha, iterations);
    int observed_count = 0;
    for (double p : permuted_p_values) {
        if (p <= original_p_value) {
            ++observed_count;
        }
    }
    double p_value_of_p_value = static_cast<double>(observed_count) / iterations;
    std::cout << p_value_of_p_value << std::endl;
    return 0;
}