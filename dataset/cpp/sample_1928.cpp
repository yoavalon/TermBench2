#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

std::pair<std::pair<std::vector<double>, std::vector<double>>, int> align_sequences(const std::vector<double>& seq1, const std::vector<double>& seq2, double precision) {

    auto calculate_score = [](const std::vector<double>& a, const std::vector<double>& b) {
        int score = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (std::fabs(a[i] - b[i]) < precision) {
                score += 1;
            } else {
                score -= 1;
            }
        }
        return score;
    };

    int max_score = std::numeric_limits<int>::min();
    std::pair<std::vector<double>, std::vector<double>> best_alignment;

    for (int i = 0; i <= static_cast<int>(seq1.size() - seq2.size()); ++i) {
        for (int j = 0; j <= static_cast<int>(seq2.size() - seq1.size()); ++j) {
            std::vector<double> subseq1(seq2.size());
            std::vector<double> subseq2(seq1.size());
            for (size_t k = 0; k < seq2.size(); ++k) {
                subseq1[k] = seq1[i + k];
            }
            for (size_t k = 0; k < seq1.size(); ++k) {
                subseq2[k] = seq2[j + k];
            }
            int score = calculate_score(subseq1, subseq2);
            if (score > max_score) {
                max_score = score;
                best_alignment = {subseq1, subseq2};
            }
        }
    }
    return {best_alignment, max_score};
}

int main() {
    std::vector<double> seq1 = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::vector<double> seq2 = {0.1, 0.2, 0.3, 0.4, 0.5};
    double precision = 1e-09;
    auto [alignment, score] = align_sequences(seq1, seq2, precision);
    std::cout << "Alignment: (" << alignment.first[0];
    for (size_t i = 1; i < alignment.first.size(); ++i) {
        std::cout << ", " << alignment.first[i];
    }
    std::cout << "), (" << alignment.second[0];
    for (size_t i = 1; i < alignment.second.size(); ++i) {
        std::cout << ", " << alignment.second[i];
    }
    std::cout << ") Score: " << score << std::endl;
    return 0;
}