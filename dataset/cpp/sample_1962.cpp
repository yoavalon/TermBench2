#include <iostream>
#include <string>
#include <cmath>

double align_sequences(const std::string& seq1, const std::string& seq2) {
    int len1 = seq1.length();
    int len2 = seq2.length();
    if (!len1 || !len2) {
        return 0;
    }
    int score = 0;
    for (int i = 0; i < std::min(len1, len2); ++i) {
        if (seq1[i] == seq2[i]) {
            ++score;
        }
    }
    return static_cast<double>(score) / std::max(len1, len2);
}

double normalize_score(double score) {
    return std::floor(score * 100) / 100;
}

int main() {
    std::string seq1 = "ATCGTACG";
    std::string seq2 = "ATCGTACC";
    double score = align_sequences(seq1, seq2);
    double normalized_score = normalize_score(score);
    std::cout << normalized_score << std::endl;
    return 0;
}