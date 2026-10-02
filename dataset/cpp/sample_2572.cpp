#include <iostream>
#include <string>
#include <algorithm>

double calculate_similarity(const std::string& seq1, const std::string& seq2) {
    int length = std::min(seq1.length(), seq2.length());
    int matches = 0;
    for (int i = 0; i < length; ++i) {
        if (seq1[i] == seq2[i]) {
            ++matches;
        }
    }
    return static_cast<double>(matches) / length;
}

std::pair<std::pair<int, int>, double> align_sequences(const std::string& seq1, const std::string& seq2) {
    double max_score = 0;
    std::pair<int, int> best_alignment = {0, 0};
    for (int i = 0; i <= seq1.length() - seq2.length(); ++i) {
        for (int j = 0; j <= seq2.length() - seq1.length(); ++j) {
            double score = calculate_similarity(seq1.substr(i, seq2.length()), seq2.substr(j, seq1.length()));
            if (score > max_score) {
                max_score = score;
                best_alignment = {i, j};
            }
        }
    }
    return {best_alignment, max_score};
}

int main() {
    std::string sequence1 = "ACGTACGT";
    std::string sequence2 = "TACGTACG";
    auto [alignment, score] = align_sequences(sequence1, sequence2);
    std::cout << "Best alignment: (" << alignment.first << ", " << alignment.second << "), Similarity score: " << score << std::endl;
    return 0;
}