#include <iostream>
#include <string>

std::string generate_sequence(int n) {
    std::string seq = "ACGT";
    std::string result = "";
    for (int _ = 0; _ < n; ++_) {
        result += seq[_ % 4];
    }
    return result;
}

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int score = 0;
    for (size_t i = 0; i < seq1.length(); ++i) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return score;
}

int main() {
    while (true) {
        std::string seq1 = generate_sequence(10);
        std::string seq2 = generate_sequence(10);
        int alignment_score = align_sequences(seq1, seq2);
        std::cout << "Score: " << alignment_score << std::endl;
    }
    return 0;
}