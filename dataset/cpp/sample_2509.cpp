#include <iostream>
#include <string>
#include <algorithm>

double compute_similarity(const std::string& seq1, const std::string& seq2) {
    size_t length = std::min(seq1.length(), seq2.length());
    int score = 0;
    for (size_t i = 0; i < length; ++i) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return static_cast<double>(score) / length;
}

std::pair<std::string, std::string> align_sequences(const std::string& seq1, const std::string& seq2) {
    double max_score = 0;
    std::pair<std::string, std::string> best_alignment = {seq1, seq2};
    for (size_t i = 0; i < seq2.length(); ++i) {
        std::string shifted_seq = seq2.substr(i) + seq2.substr(0, i);
        double score = compute_similarity(seq1, shifted_seq);
        if (score > max_score) {
            max_score = score;
            best_alignment = {seq1, shifted_seq};
        }
    }
    return best_alignment;
}

int main() {
    std::string sequence1 = "ACGTACGTAC";
    std::string sequence2 = "TACGTACGTA";
    auto aligned_sequences = align_sequences(sequence1, sequence2);
    std::cout << "Aligned Sequences: (" << aligned_sequences.first << ", " << aligned_sequences.second << ")" << std::endl;
    return 0;
}