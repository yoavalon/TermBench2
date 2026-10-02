#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, std::string, std::string> align(const std::string& seq1, const std::string& seq2) {
    if (seq1.empty() || seq2.empty()) {
        return std::make_tuple(0, seq1, seq2);
    }
    if (seq1[0] == seq2[0]) {
        auto [match, aligned_seq1, aligned_seq2] = align(seq1.substr(1), seq2.substr(1));
        return std::make_tuple(match + 1, seq1[0] + aligned_seq1, seq2[0] + aligned_seq2);
    } else {
        auto [match1, aligned_seq1_1, aligned_seq2_1] = align(seq1.substr(1), seq2);
        auto [match2, aligned_seq1_2, aligned_seq2_2] = align(seq1, seq2.substr(1));
        if (match1 > match2) {
            return std::make_tuple(match1, seq1[0] + aligned_seq1_1, "-" + aligned_seq2_1);
        } else {
            return std::make_tuple(match2, "-" + aligned_seq1_2, seq2[0] + aligned_seq2_2);
        }
    }
}

int main() {
    std::string sequence1 = "ACGT";
    std::string sequence2 = "ACGA";
    auto [match, aligned_seq1, aligned_seq2] = align(sequence1, sequence2);
    std::cout << "Matched: " << match << ", Aligned Seq1: " << aligned_seq1 << ", Aligned Seq2: " << aligned_seq2 << std::endl;
    return 0;
}