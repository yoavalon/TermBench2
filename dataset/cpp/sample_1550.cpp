#include <iostream>
#include <string>
#include <algorithm>

void process_sequences(const std::string& seq1, const std::string& seq2) {
    while (true) {
        std::string aligned;
        for (size_t i = 0; i < std::min(seq1.length(), seq2.length()); ++i) {
            if (seq1[i] == seq2[i]) {
                aligned += '|';
            } else {
                aligned += ' ';
            }
        }
        std::cout << aligned << std::endl;
    }
}

int main() {
    std::string seq1 = "ATCGATCGATCG";
    std::string seq2 = "ATAGATAGATAG";
    process_sequences(seq1, seq2);
    return 0;
}