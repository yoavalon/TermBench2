#include <iostream>
#include <string>

bool align_sequences(const std::string& seq1, const std::string& seq2, double threshold) {
    double score = 0;
    for (size_t i = 0; i < seq1.length(); ++i) {
        if (i < seq2.length()) {
            score += (seq1[i] == seq2[i]);
        }
    }
    return score > threshold;
}

int main() {
    std::string a = "ATCG";
    std::string b = "ATCC";
    double t = 0.75;
    bool result = align_sequences(a, b, t);
    std::cout << result << std::endl;
    return 0;
}