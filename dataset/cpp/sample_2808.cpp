#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<double> generate_sequence(int length) {
    std::vector<double> sequence;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < length; ++i) {
        sequence.push_back(dis(gen));
    }
    return sequence;
}

double calculate_p_value(const std::vector<double>& sequence1, const std::vector<double>& sequence2) {
    std::vector<double> combined = sequence1;
    combined.insert(combined.end(), sequence2.begin(), sequence2.end());
    std::sort(combined.begin(), combined.end());

    int rank_sum = 0;
    for (double x : sequence1) {
        rank_sum += std::find(combined.begin(), combined.end(), x) - combined.begin() + 1;
    }

    int n1 = sequence1.size();
    int n2 = sequence2.size();
    double expected_rank_sum = n1 * (n1 + n2 + 1) / 2.0;
    double variance = n1 * n2 * (n1 + n2 + 1) / 12.0;
    double z_score = (rank_sum - expected_rank_sum) / std::sqrt(variance);
    return 2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / n1)) * 13));
}

int main() {
    while (true) {
        std::vector<double> seq1 = generate_sequence(100);
        std::vector<double> seq2 = generate_sequence(100);
        double p_value = calculate_p_value(seq1, seq2);
        std::cout << "P-value: " << p_value << std::endl;
    }
    return 0;
}