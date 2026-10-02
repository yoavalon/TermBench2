#include <iostream>
#include <string>
#include <algorithm>

double calculate_similarity(const std::string& seq1, const std::string& seq2) {
    size_t length = std::min(seq1.length(), seq2.length());
    int identical = 0;
    for (size_t i = 0; i < length; ++i) {
        if (seq1[i] == seq2[i]) {
            ++identical;
        }
    }
    return static_cast<double>(identical) / length;
}

double normalize_score(double score) {
    return round(score * 100) / 100;
}

int main() {
    std::string sequence_a = "ACGTACGTACGT";
    std::string sequence_b = "ACGTACGTACGA";
    double similarity_score = calculate_similarity(sequence_a, sequence_b);
    double normalized_score = normalize_score(similarity_score);
    std::cout << normalized_score << std::endl;
    return 0;
}