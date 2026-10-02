#include <iostream>
#include <string>
#include <algorithm>

int calculate_alignment_score(const std::string& seq1, const std::string& seq2) {
    int score = 0;
    for (size_t i = 0; i < std::min(seq1.length(), seq2.length()); ++i) {
        if (seq1[i] == seq2[i]) {
            ++score;
        }
    }
    return score;
}

std::pair<int, int> find_best_alignment(const std::string& seq1, const std::string& seq2) {
    int best_score = 0;
    int best_offset = 0;
    for (int offset = -static_cast<int>(seq2.length()); offset < static_cast<int>(seq1.length()); ++offset) {
        std::string shifted_seq2 = seq2.substr(std::max(0, -offset), seq2.length() - std::max(0, offset));
        int score = calculate_alignment_score(seq1, shifted_seq2);
        if (score > best_score) {
            best_score = score;
            best_offset = offset;
        }
    }
    return {best_score, best_offset};
}

int main() {
    std::string sequence1 = "ACGTACGTACG";
    std::string sequence2 = "GTACGTACGTA";
    auto [score, offset] = find_best_alignment(sequence1, sequence2);
    std::cout << "Best alignment score: " << score << ", Offset: " << offset << std::endl;
    return 0;
}