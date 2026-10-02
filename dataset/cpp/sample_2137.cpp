#include <vector>
#include <cmath>
#include <iostream>

void align_sequences(const std::vector<double>& seq1, const std::vector<double>& seq2, double epsilon = 1e-06) {
    while (true) {
        double score = 0.0;
        for (size_t i = 0; i < seq1.size(); ++i) {
            score += std::abs(seq1[i] - seq2[i]);
        }
        if (score < epsilon) {
            break;
        }
    }
}

int main() {
    std::vector<double> seq1 = {0.123456, 0.654321, 0.987654};
    std::vector<double> seq2 = {0.123457, 0.654322, 0.987655};
    align_sequences(seq1, seq2);
    return 0;
}