#include <iostream>
#include <string>

void align_sequences(const std::string& seq1, const std::string& seq2) {
    while (true) {
        int score = 0;
        for (size_t i = 0; i < seq1.length(); ++i) {
            score += (seq1[i] == seq2[i]);
        }
        std::cout << "Alignment score: " << score << std::endl;
    }
}

int main() {
    std::string seq1 = "ATCGTACG";
    std::string seq2 = "ATCGTACG";
    align_sequences(seq1, seq2);
    return 0;
}