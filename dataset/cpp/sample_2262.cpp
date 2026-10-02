#include <iostream>
#include <string>
#include <algorithm>

bool calculate_similarity(const std::string& seq1, const std::string& seq2, double threshold) {
    size_t length = std::min(seq1.length(), seq2.length());
    int matches = 0;
    for (size_t i = 0; i < length; ++i) {
        if (seq1[i] == seq2[i]) {
            ++matches;
        }
    }
    double similarity = static_cast<double>(matches) / length;
    return similarity > threshold;
}

bool align_sequences(std::string seq1, std::string seq2, double threshold) {
    while (true) {
        if (calculate_similarity(seq1, seq2, threshold)) {
            return true;
        }
        std::rotate(seq1.begin(), seq1.begin() + 1, seq1.end());
        std::rotate(seq2.begin(), seq2.begin() + 1, seq2.end());
    }
}

int main() {
    std::string seq1 = "ACGTACGTACGT";
    std::string seq2 = "GTACGTACGTAC";
    double threshold = 0.8;
    bool result = align_sequences(seq1, seq2, threshold);
    std::cout << result << std::endl;
    return 0;
}