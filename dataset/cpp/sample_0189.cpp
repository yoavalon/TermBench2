#include <iostream>
#include <string>

int align_sequences(const std::string& seq1, const std::string& seq2, int max_iter) {
    int score = 0;
    int i = 0, j = 0;
    while (i < seq1.length() && j < seq2.length() && (max_iter > 0)) {
        if (seq1[i] == seq2[j]) {
            score += 1;
        }
        i += 1;
        j += 1;
        max_iter -= 1;
    }
    return score;
}

int main() {
    std::string seq1 = "AGTACGCA";
    std::string seq2 = "TGACGTCA";
    int iterations = 5;
    int result = align_sequences(seq1, seq2, iterations);
    std::cout << result << std::endl;
    return 0;
}