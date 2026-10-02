#include <iostream>
#include <string>

int align_sequences(const std::string& seq1, const std::string& seq2, int max_len) {
    int i = 0, j = 0;
    int score = 0;
    while (i < seq1.length() && j < seq2.length() && (i + j < max_len)) {
        if (seq1[i] == seq2[j]) {
            score += 1;
        }
        i += 1;
        j += 1;
    }
    return score;
}

int main() {
    int result = align_sequences("ACGT", "ACGG", 10);
    std::cout << result << std::endl;
    return 0;
}